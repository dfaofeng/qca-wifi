/*
 * Copyright (c) 2010, Atheros Communications Inc. 
 * All Rights Reserved.
 * 
 * Copyright (c) 2011 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * 
 */

//----------------------------------------------------------------------------
//
//  Project:   BT3_0 CORE
//
//  Filename:  bt_pal_Security.c
//
//  Author:   Mike Tsai
//
//  Created:   5/22/2009
//
//  Descriptions:
//
//     4-Way Handshaking functions
//
//----------------------------------------------------------------------------
#include "osdep.h"
#include "pal_osapi.h"
#include "amp_db.h"
#include "bt_pal_evt.h"
#include "wlan_drv_intf.h"
#include "paldebug.h"
#include "poshApi.h"
#include "pal_state.h"
#include "ieee80211_defs.h"
#include "mywpa.h"
#include "aes_wrap.h"
#include "bt_pal_security.h"

//===============================================================================
// Implementation theory
//
// Initiator                                 Responder
//
//	          AMP_Create_Physical_Link_Req --------->
//                                              Start Beaconing
//            <---------- AMP_Create_Physical_Link_Rsp
//--------------------------------------------------------------------------------
//                        <------ Probe Request        Miniport internal
//                        Probe Response ----->
//                        <------ 802.11 AUTH REQ      (Retry / timing)
//                        802.11 AUTH RSP ----->
//                        <------ 802.11 ASSOC REQ
//                        802.11 ASSOC RSP ----->
//-------------------------------------------------------- (Event to PAL, connected)
//---------------------------------------------------------------------------------                                                        
//                                                   4-Way handshaking state machine
// Note, for 4-way handshaking, only the authenticator shall retransmit the M1 or 
// M3 frames based on time out policy (1 second) and max retry (3). The supplicant is 
// only waiting passively.
//-----------------------------------------------------------------------------------
// The authenticator, upon reception of M2 or M4 frames, shall verify the RN that 
// matches what was sent before. The frames that do not match with the RN sent shall
// be ignored.
//
// There is one race condition at the end of 4-way handshaking. After PTK and MIC are
// verified based on M2 and M3 frame, the Supplicant enables the link's encryption as 
// soon as M4 is sent. This, could cause issue if the authenticator does not receive this
// M4. The authenticator will continuously retry the M3 unencrypted while the supplicant
// has already set the link encrypted. To recover from this particular situation, the 
// Authentication shall put the link into encrypted mode after 3 tries and let the upper 
// layer stacks handle it.
//
// 4 - Way handshaking is running inside PAL context and works as one of the physical 
// connection thread.
//
// Following MSC only shows when everything works (no packets lost)
//
//          M1  (RN=0) --------------------------------->
//              <---------------------------------------  M2 (RN=0) (PTK Chk)
// (PTK Chk)M3  (RN=0) --------------------------------->
//              <---------------------------------------  M4 (RN=0)
//
// In the situation where one of the M1 to M3 packet frames are lost and duplicated
// packet frames are received, we shall ignore the previous one and only accept the one
// with correct RN.
//======================================================================================
//  definitions for security timeout/retry
//======================================================================================

/* ------------------Security Related Function Calls --------------------------------------*/

/* --------------- Create EOP M1 frame -----------------------------------------------------
 * Replay counter shall start from 0 for each reassociation . It is an 8-byte octet and works
 * as a BIG unsigned number.
 *
 * ---------------------------------------------------------------------------------------*/
static const A_UINT8 eop_m1_fr[] = 
           {0x01,       //protocol version
		    0x03,       //packet type 
			0x00, 0x5f, //packet body length
			0x02,		//descriptor type 
			0x00, 0x8a, //Key info 
			0x00, 0x10, //Key Length  (CCMP)
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, //Key replay Counter, it's legal to start from 1
			0xf9, 0x32, 0xe8, 0x43, 0x2f, 0x6f, 0xb3, 0x2e, //Key Nonce, 32 bytes, (replace later)
			0xb6, 0xc2, 0xcb, 0x69, 0x8b, 0x23, 0xeb, 0xad, 
			0x69, 0x16, 0x8c, 0x06, 0x41, 0x4b, 0x9b, 0xba, 
			0x06, 0x8d, 0x27, 0x1c, 0xc4, 0x26, 0x44, 0x20, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Eapol Key IV - 16 bytes
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Key RSC - 0, shall be adjusted
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Reserved
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Key MIC - 16 bytes
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00,                                     //Key Data Length = 0
			0x47, 0x05, 0x1d, 0xb7};                        //

void
create_eop_m1(AMP_ASSOC_INFO *r_amp, A_UINT8 *data, A_UINT8 *sz)
{
    os_memcpy(data, eop_m1_fr, sizeof(eop_m1_fr));
    /* Modify the nonce - ANonce */
	OS_GET_RANDOM_BYTES((u_int32_t *)r_amp->sec_record.a_nonce, sizeof(r_amp->sec_record.a_nonce));
    os_memcpy(&data[NONCE_OFFSET], r_amp->sec_record.a_nonce, sizeof(r_amp->sec_record.a_nonce));

    *sz = sizeof(eop_m1_fr);
    data[KEY_REPLAY_COUNTER_OFFSET] = ++r_amp->sec_record.replay_counter;
    PAL_PRINT(("Authenticator A_NONCE :\n"));
    dump_frame(r_amp->sec_record.a_nonce, sizeof(r_amp->sec_record.a_nonce));
}


static void
parse_and_decode_m1(AMP_ASSOC_INFO *r_amp, A_UINT8 *buf, A_UINT16 len, A_UINT8 *key_replay_counter)
{
#if DBG
    PAL_PRINT(("PAL-Parse M1 frame, len (%d) \n", len));
    dump_frame(buf, len);  
#else
    UNUSED(len);
#endif

    /* Copy the A-Nonce from Authenticator */
    os_memcpy(r_amp->sec_record.a_nonce, &buf[NONCE_OFFSET], sizeof(r_amp->sec_record.a_nonce));
    PAL_PRINT(("PAL- Supplicant, A_NONCE \n"));
    dump_frame(r_amp->sec_record.a_nonce, sizeof(r_amp->sec_record.a_nonce));  

	//Key replay counter does not go through state transition, it shall be fine as static global
    os_memcpy(key_replay_counter, &buf[KEY_REPLAY_COUNTER_START], KEY_REPLAY_COUNTER_STR_LEN);
    PAL_PRINT(("PAL- Rcv M1 Replay counter \n"));
    dump_frame(key_replay_counter, KEY_REPLAY_COUNTER_STR_LEN);  

}

static const  A_UINT8 eop_m2_fr[] = 
			{
			 0x01,		  //protocol version
			 0x03,		  //packet type 	
			 0x00, 0x75,  //packet body length, 117 bytes
			 0x02,        //descriptor type  
			 0x01, 0x0a,  //Key info
			 0x00, 0x00,  //Key Length  = 0
			 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, //Key replay counter
			 0xbe, 0x1d, 0xbe, 0x6c, 0x8f, 0x4c, 0x9b, 0x80, //S-Nonce, 32 bytes, (replaced later)
			 0x12, 0x64, 0x46, 0xab, 0x35, 0x96, 0xdf, 0xd6, 
			 0x7f, 0xe5, 0x59, 0xee, 0x85, 0x76, 0x0d, 0x17, 
			 0x49, 0x60, 0xbd, 0x2a, 0x10, 0x4a, 0xa2, 0x9d, 
			 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Eapol Key IV - 16 bytes
			 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Key RSC - 0
			 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Reserved
			 0x38, 0x97, 0x6b, 0x02, 0x40, 0xdd, 0x6c, 0x4f, //Key MIC - 16 bytes
			 0x61, 0x9c, 0x45, 0xf6, 0xe9, 0xbf, 0xc0, 0xa9, 
			 0x00, 0x16,                                     //Key Data Length: 22
			 0x30, 0x14, 0x01, 0x00, 0x00, 0x0f, 0xac, 0x04, //Key Data
			 0x01, 0x00, 0x00, 0x0f, 0xac, 0x04, 0x01, 0x00, 
			 0x00, 0x0f, 0xac, 0x02, 0x00, 0x00
};

static void
create_eop_m2(AMP_ASSOC_INFO *r_amp, A_UINT8 *buf, A_UINT8 *sz, A_UINT8 *key_replay_counter)
{
    A_UINT8 *mic_in_fr;

	os_memcpy(buf, eop_m2_fr, sizeof(eop_m2_fr)); //Fill in buffer with pre-defined EOP_M2
	OS_GET_RANDOM_BYTES((u_int32_t *)r_amp->sec_record.s_nonce, sizeof(r_amp->sec_record.s_nonce));
    /* Modify the nonce - SNonce */
    os_memcpy(&buf[NONCE_OFFSET], r_amp->sec_record.s_nonce, sizeof(r_amp->sec_record.s_nonce));

    PAL_PRINT(("Supplicant S_Nonce:\n"));
    dump_frame(r_amp->sec_record.s_nonce, sizeof(r_amp->sec_record.s_nonce));

    os_memcpy(&buf[KEY_REPLAY_COUNTER_START], key_replay_counter, KEY_REPLAY_COUNTER_STR_LEN);
    PAL_PRINT(("PAL- Send M2 Replay counter \n"));
    dump_frame(&buf[KEY_REPLAY_COUNTER_START], KEY_REPLAY_COUNTER_STR_LEN); 

    /* Null the MIC */
    mic_in_fr = &buf[MIC_OFFSET];
    os_memset(mic_in_fr, 0, MIC_LENGTH);

    *sz = sizeof(eop_m2_fr);
}

void parse_m1_create_m2(AMP_ASSOC_INFO *r_amp, A_UINT8 *data, A_UINT8 *buf, A_UINT16 len, A_UINT8 *sz)
{
    A_UINT8 a_key_replay_counter[KEY_REPLAY_COUNTER_STR_LEN];

    parse_and_decode_m1(r_amp, data, len, a_key_replay_counter); //Get A-NOnce and Key Replay Counter
    create_eop_m2(r_amp, buf, sz, a_key_replay_counter);        //Create M2 frame with S-Nonce and Key replay counter from M1
}

A_UINT8
parse_and_decode_m2(AMP_ASSOC_INFO *r_amp, A_UINT8 *buf, A_UINT8 len, A_UINT8 *mic)
{
    A_UINT8 *mic_in_fr;

	UNUSED(len);

	//Is this ack what we just sent?
	if (buf[KEY_REPLAY_COUNTER_OFFSET] != r_amp->sec_record.replay_counter) 
    {
        PAL_PRINT(("PAL-SEC, Reply counter failed, expect[%d], recv[%d] \n", 
                   r_amp->sec_record.replay_counter, buf[KEY_REPLAY_COUNTER_OFFSET] )); 

		return(HCI_ERR_UNSPECIFIED_ERROR); //discard silently
    }
		
    /* Copy the nonce - SNonce */
    os_memcpy(r_amp->sec_record.s_nonce, &buf[NONCE_OFFSET], sizeof(r_amp->sec_record.s_nonce));

    PAL_PRINT(("Authenticator S_Nonce:\n"));
    dump_frame(r_amp->sec_record.s_nonce, sizeof(r_amp->sec_record.s_nonce));

    mic_in_fr = &buf[MIC_OFFSET];
    os_memcpy(mic, mic_in_fr, MIC_LENGTH);

    PAL_PRINT(("MIC in frame :\n"));
    dump_frame(mic, MIC_LENGTH);

	return(HCI_SUCCESS);
}


/* This must match what's there in beacon */

void
create_eop_m3(AMP_ASSOC_INFO *r_amp, A_UINT8* data, A_UINT8 *sz)
{
    A_UINT8 fr[] = 
           {
			0x01,			//protocol version
			0x03,           //packet type 
			0x00, 0x97,     //packet body length, 151 bytes
			0x02,           //descriptor type 
			0x13, 0xca,     //Key info
			0x00, 0x10,		//Key length, encryption key 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, //Key replay counter
			0xf9, 0x32, 0xe8, 0x43, 0x2f, 0x6f, 0xb3, 0x2e, //A-Nonce, same M1, 32 bytes
			0xb6, 0xc2, 0xcb, 0x69, 0x8b, 0x23, 0xeb, 0xad, 
			0x69, 0x16, 0x8c, 0x06, 0x41, 0x4b, 0x9b, 0xba, 
			0x06, 0x8d, 0x27, 0x1c, 0xc4, 0x26, 0x44, 0x20, 
			0x2a, 0x92, 0x9b, 0x6d, 0xda, 0x61, 0x5a, 0x25, //EAPOL-Key IV, random (Version 1)
			0x72, 0xb5, 0x02, 0xf5, 0xbf, 0x95, 0xe5, 0xe9, 
			0x59, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Key RSC
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Reserved
			0xab, 0x40, 0x8d, 0xb4, 0x3c, 0xea, 0x6b, 0x83, //MIC
			0x49, 0x7b, 0x53, 0xab, 0x0d, 0xb0, 0xee, 0x60
	}; 

    A_UINT8 key_len;
    A_UINT8 *mic_in_fr;

    fr[KEY_REPLAY_COUNTER_OFFSET] = ++r_amp->sec_record.replay_counter; //increase replay_counter

    /* Same ANonce as M1 */
    os_memcpy(&fr[NONCE_OFFSET], r_amp->sec_record.a_nonce, sizeof(r_amp->sec_record.a_nonce));

    /* Null the MIC */
    mic_in_fr = &fr[MIC_OFFSET];
    os_memset(mic_in_fr, 0, MIC_LENGTH);

    *sz = sizeof(fr);
    os_memcpy(data, fr, sizeof(fr));


    /* Add encrypted key data */
    key_len = create_encrypted_key(r_amp, sizeof(r_amp->sec_record.gtk), &data[*sz]);
    *sz += (A_UINT8)(key_len + 2);
     
   /* modify the size */
   *((A_UINT16 *)(&data[2])) = htons(*sz -4);
}

A_UINT8
create_encrypted_key(AMP_ASSOC_INFO *r_amp, A_UINT16 gtk_len, A_UINT8 *result)
{
    A_UINT8 key_data_len, pad_len;
    A_UINT8 buf[256], *pos;
    static const A_UINT8 RSN_SELECTOR_LEN = 4;
    static const A_UINT8 RSN_KEY_DATA_GROUPKEY[] = { 0x00, 0x0f, 0xac, 1 };
    A_UINT8 rsn_ie[IEEE80211_RSN_IE_LEN];
    AMP_DEV *Dev = r_amp->amp_dev;
    A_UINT8 i;

    os_memset(buf, 0, sizeof(buf));
    key_data_len = (A_UINT8)(sizeof(rsn_ie) + 2 + RSN_SELECTOR_LEN + 2 + gtk_len);
    pad_len = key_data_len % 8;
    if (pad_len)
        pad_len = 8 - pad_len;
    key_data_len += pad_len + 8;

#define WLAN_EID_GENERIC 221

    rsn_ie[0] = IEEE80211_ELEMID_RSN;
    rsn_ie[1] = IEEE80211_RSN_IE_LEN - 2;
    PAL_POSH_API->QueryIE(r_amp, rsn_ie);

    for(i=0; i< IEEE80211_RSN_IE_LEN ; i++)
        PAL_PRINT(("create_encrypted_key() query rsn_ie[%d]=0x%02x\n",i,rsn_ie[i]));

    /* Add RSN ie to buf for keydata */
    os_memcpy(buf, rsn_ie, sizeof(rsn_ie));
    pos = buf + sizeof(rsn_ie);
    *pos++ = WLAN_EID_GENERIC;
    *pos++ = (A_UINT8)(RSN_SELECTOR_LEN + 2 + gtk_len);
    os_memcpy(pos, RSN_KEY_DATA_GROUPKEY, RSN_SELECTOR_LEN);
    pos += RSN_SELECTOR_LEN;
    *pos++ = 1 & 0x03;  /* keyidx is 1 - fixed */
    *pos++ = 0;

    os_memcpy(pos, r_amp->sec_record.gtk, gtk_len);
    pos += gtk_len;
    if (pad_len)
        *pos++ = 0xdd;
 //   dump_frame(buf, pos - buf);
    aes_wrap(Dev->osdev, &r_amp->sec_record.ptk[16], (key_data_len - 8) / 8, buf, result+2);
    *((short *)result) = htons(key_data_len);

 //   dump_frame(result+2, key_data_len);
    PAL_PRINT(("key data len %d\n", key_data_len));

    decrypt_key(r_amp, result+2, key_data_len);
    return( key_data_len);
}

void
decrypt_key(AMP_ASSOC_INFO *r_amp, A_UINT8 *encrypted_data, A_UINT8 keydatalen)
{
    A_UINT8 pBuf[512];
    AMP_DEV *Dev = r_amp->amp_dev;

    if (keydatalen % 8) {
        //PAL_PRINT(("WPA not supported. Keydatalen... %d\n", keydatalen));
    }

    keydatalen -= 8; /* AES-WRAP adds 8 bytes */

    aes_unwrap(Dev->osdev, &r_amp->sec_record.ptk[16], keydatalen / 8, encrypted_data, pBuf);
    PAL_PRINT(("Decrypted Key...\n"));
 //   dump_frame(pBuf, keydatalen);
}

A_UINT8
parse_and_decode_m3(AMP_ASSOC_INFO *r_amp, A_UINT8 *buf, A_UINT8 *mic, A_UINT8 *replay_counter)
{
    os_memcpy(replay_counter, &buf[KEY_REPLAY_COUNTER_START], KEY_REPLAY_COUNTER_STR_LEN);

    /* Compare the nonce - SNonce */
    if(os_memcmp(r_amp->sec_record.a_nonce, &buf[NONCE_OFFSET], sizeof(r_amp->sec_record.a_nonce))) {
        PAL_PRINT(("M1 and M3 Nonce's don't match..\n"));
		return(HCI_ERR_AUTH_FAILURE);
    }

    os_memcpy(mic, &buf[MIC_OFFSET], MIC_LENGTH);

    decrypt_key(r_amp, &buf[99], buf[97] << 8 | buf[98]);
	return(HCI_SUCCESS);
}

static const A_UINT8 m4_fr[] = 
                {
				 0x01,			//protocol version
				 0x03,			//packet type
				 0x00, 0x5f,	//packet body length, 95 bytes
				 0x02,			//descriptor type 
				 0x03, 0x0a,	//Key info 
				 0x00, 0x00,	//Key length, encryption key
				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, //Key replay counter, override with what inside M3
				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //S-Nonce, 0
				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //EAPOL-Key IV, 0 
				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  //Key RSC = 0
				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  //Reserved
				 0xf0, 0x7f, 0xc0, 0xa5, 0x6d, 0x1f, 0x06, 0x4f,  //Key MIC
				 0xb3, 0xc4, 0xe7, 0xd8, 0xc4, 0x80, 0xa8, 0x56,  //Key Data Length = 0 
				 0x00, 0x00};					
static void
create_eop_m4(AMP_ASSOC_INFO *r_amp, A_UINT8 *buf, A_UINT8 *sz, A_UINT8 *replay_counter)
{
	UNUSED(r_amp);

    os_memcpy(buf, m4_fr, sizeof(m4_fr));

    os_memset(&buf[KEY_REPLAY_COUNTER_START], 0, sizeof(m4_fr) - KEY_REPLAY_COUNTER_START);
    os_memcpy(&buf[KEY_REPLAY_COUNTER_START], replay_counter, KEY_REPLAY_COUNTER_STR_LEN);

    *sz = sizeof(m4_fr);
}

A_UINT8 
parse_m3_create_m4(AMP_ASSOC_INFO *r_amp, A_UINT8 *data, A_UINT8 *buf, A_UINT16 len, A_UINT8 *sz, A_UINT8 *mic)
{
A_UINT8  Status;
A_UINT16 M3InLen;
A_UINT8 key_replay_counter[KEY_REPLAY_COUNTER_STR_LEN];

    /* In the EAPOL frame, byte3 and byte4 contain EAPOL frame
     * length, excluding header(4-bytes). This value is in 
     * network order. Use this value to perform MIC check.
     */
    M3InLen = (A_UINT16)((data[EAPOL_BODY_LEN_OFFSET]<<8) +data[EAPOL_BODY_LEN_OFFSET+1]) + EAPOL_HEADER_LEN;
    PAL_PRINT(("Get m3_len bytes as (0x%02X,0x%02X), M3InLen (%d) ) \n", 
        data[2], data[3], M3InLen));

    //Copy key_replay_counter and compare the Nonse
    parse_and_decode_m3(r_amp, data, mic, key_replay_counter);

    Status = verify_mic(data, (A_UINT8)M3InLen, mic, r_amp->sec_record.ptk);
    if (Status != HCI_SUCCESS) //fail
        return (Status);

    /* Send M4 */
    create_eop_m4(r_amp, buf, sz, key_replay_counter);

    return(HCI_SUCCESS);
}

static void
parse_and_decode_m4()
{

}


void
generate_ptk(A_UINT8 *pmk, A_UINT8 * n1, A_UINT8 *n2, A_UINT8 *addr1, A_UINT8 *addr2, A_UINT8 *ptk)
{
    wpa_pmk_to_ptk(pmk, LINK_KEY_LEN, addr1, addr2, n1, n2, ptk, 64);
    PAL_PRINT(("PMK = \n"));
    dump_frame(pmk, PMK_LEN);
    PAL_PRINT(("PTK = \n"));
    dump_frame(ptk, 64);
}

A_UINT8
verify_mic(A_UINT8 *buf, A_UINT8 len, A_UINT8 *mic, A_UINT8 *kck)
{
    A_UINT8 *mic_in_fr, key_mic[MIC_LENGTH];

    PAL_PRINT(("Key MIC from remote device ...\n"));
    dump_frame(mic, MIC_LENGTH);

    //PAL_PRINT(("Len = %d\n", len));
    mic_in_fr = &buf[MIC_OFFSET];
    /* reset mic in frame */
    os_memset(mic_in_fr, 0, MIC_LENGTH);

    PAL_PRINT(("WPA_GEN_MIC, version 2 Key = \n"));
    dump_frame(kck, LINK_KEY_LEN);

    PAL_PRINT(("Buf before micing, len(%d) ...\n", len));
    dump_frame(buf, len);

    
    wpa_eapol_key_mic(kck, 2, buf, len, key_mic);


    PAL_PRINT(("key mic in verifing...\n"));
    dump_frame(key_mic, MIC_LENGTH);

    if(os_memcmp(mic, key_mic, sizeof(key_mic)) == 0) {
        PAL_PRINT(("KEY MIC OK \n"));
        return(HCI_SUCCESS);
    } else {
        PAL_PRINT(("KEY MIC not OK \n"));
        return(HCI_ERR_AUTH_FAILURE);
    }
}
//----------------------------------------------------------------------------------------------------------------
//   Security utilities Ends
//----------------------------------------------------------------------------------------------------------------

