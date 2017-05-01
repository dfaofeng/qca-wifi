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
//  Filename:  bt_pal_init.c
//
//  Author:    Mike Tsai
//
//  Created:   8/14/2009
//
//  Descriptions:
//
//    AMP Controller Initialization State Machine
//
//----------------------------------------------------------------------------
#include "osdep.h"
#include "pal_osapi.h"
#include "paldebug.h"
#include "amp_db.h"
#include "bt_pal_evt.h"
#include "pal_state.h"
#include "poshApi.h"
#include "bt_inp.h"
#include "bt_pal_txq.h"

// typedef enum {
//  PAL_IDLE_STATE = 0,
//  PAL_CREATE_AMP_MAC_STATE,
//  PAL_QUERY_INITIAL_CHANNEL_INFO,
//  PAL_READY_STATE
//}E_PAL_DEVICE_STATE;

//static POSH_OPS LclPoshApi;
static void     init_local_amp_cfg(AMP_DEV *dev, PAL_CFG* cfg);

static void Pal_fill_amp_assoc(AMP_DEV *Dev, AMP_ASSOC_INFO *Local_Amp, A_UINT16 sz, A_UINT8 *reg)
{
    A_UINT8    *cur = NULL;
    A_UINT8    ver[7];
    A_UINT32   palCap;
    A_UINT16   len = sz;

    /* handle empty preferred channel list first */
    if (len == 0) {
        PAL_PRINT(("AMP_ASSOC_PREF_CHAN_LIST is empty\n"));
    } else if (len <= AMP_COUNTRY_LENGTH) {
        setup_local_amp_assco_by_country(Local_Amp, reg, &len);
        //first 3 bytes are always country code
        os_memcpy(&Dev->CountryCode[0], reg, sizeof(Dev->CountryCode));
    } else {
        //first 3 bytes are always country code
        os_memcpy(&Dev->CountryCode[0], reg, sizeof(Dev->CountryCode));
    }

    //Filled in the version information

    os_memcpy(ver, &Dev->pal_cfg.local_ampinfo.pal_ver, sizeof(UINT8));
    os_memcpy(ver+1,&Dev->pal_cfg.local_ampinfo.pal_sig_name, sizeof(UINT16));
    os_memcpy(ver+3,&Dev->pal_cfg.local_ampinfo.pal_sub_ver, sizeof(UINT16));

    cur = Local_Amp->amp_assoc;
    cur = append_tlv(cur, AMP_ASSOC_MAC_ADDRESS_INFO_TYPE, MAC_ADDR_LEN, Dev->hwaddr);
    cur = append_tlv(cur, AMP_ASSOC_PREF_CHAN_LIST, len, reg);

    cur = append_tlv(cur, AMP_ASSOC_PAL_VERSION, 5, ver);
    palCap = Dev->pal_cfg.local_ampinfo.pal_capabilities;
    cur = append_tlv(cur, AMP_ASSOC_PAL_CAPABILITIES, 4 , (A_UINT8 *)&palCap);
    Local_Amp->assoc_len = (A_UINT16)(cur - Local_Amp->amp_assoc);

    parse_amp_assoc(Local_Amp->amp_assoc, AMP_ASSOC_MAC_ADDRESS_INFO_TYPE, &cur, Local_Amp->assoc_len);
    if(!cur){
        PAL_PRINT(("Failed to get AMP_ASSOC_MAC_ADDRESS_INFO_TYPE\n"));
        return;
    }
    Local_Amp->hwaddr = cur+3;
}


//-----------------------------------------------------------------------------------
// PAL initialization state
// Register LPOSH API Calls and initialize local device data structure
// Create AMP VAP
//------------------------------------------------------------------------------------
A_UINT8 pal_init_idle_state(AMP_DEV *Dev, VOID *pDriverObject)
{
    int    Status;

    if (Dev->VapNumber != 0) {
        PAL_PRINT(("AMP controller VapNumber (%d) not 0, AMP has been inited before\n", Dev->VapNumber));
        return(HCI_ERR_HW_FAILURE);
    }

    Dev->g_seq_num = 1;
    amp_db_init(Dev);

    //Move timer engine init here to avoid possible race conditions
    if (PAL_Timer_Init(Dev) != POSH_OK) {
        PAL_PRINT(("Pal Timer Initialize failed \n")); //PANIC?
        OS_assert(0);
        return(HCI_ERR_HW_FAILURE); //Do this until timer engine is done
    }

    Status = LPOSH_Init(Dev, PAL_POSH_API);

    if (Status != HCI_SUCCESS) {
        PAL_PRINT(("Posh Initialize failed \n")); //PANIC?
        return(Status);
    }  

#if ATH_AMP_ISOLATE_TX_PATH
    Status = pal_tx_queue_attach(Dev, Dev->osdev, &(Dev->pal_tx_queue));
    if (Status != EOK) {
        PAL_PRINT(("%s: Cannot attach tx queue, Status=(%08X)\n", 
            __func__, Status));
        OS_assert(0);
        return POSH_FAILED;
    }
    
    pal_tx_queue_start(&(Dev->pal_tx_queue));
#endif
    
    PAL_POSH_API->RegisterDataDispatcher(Dev, pal_data_dispatcher);
    PAL_POSH_API->RegisterTxCallBack(Dev, pal_sendpkt_complete);

    PAL_PRINT(("PAL-CreateMAC starting, we have only 1 vap for AMP MAC \n")); //PANIC?

    PAL_POSH_API->CreateMac(Dev, NULL); //Let's create our AMP VAP here
    Dev->pal_dev_state = PAL_CREATE_AMP_MAC_STATE;
    Dev->pal_cfg.local_ampinfo.amp_status = AMP_FULL_CAPACITY;

    //Do UPOSH_Init after PAL and LPOSH Init is done. this shall
    //avoid the timer race condition where PAL timer list is not initialized
    //yet but host has already sent the HCI_RESET command
    //
    Status = UPOSH_Init(Dev, pDriverObject, 0);

    if (Status != HCI_SUCCESS) {
        PAL_PRINT(("pal_init_idle_state() upper Posh Initialize failed \n"));
        Dev->HostPresent = false;
	    return(Status);
    } else {
        Dev->HostPresent = true;
    }
    return(HCI_SUCCESS);
}

A_UINT8 pal_init_ready_state(AMP_DEV *Dev)
{
    init_local_amp_cfg(Dev, &Dev->pal_cfg);
    alloc_rem_assoc_amp(Dev,  0, &Dev->pal_cfg.local_ampassoc);
    init_local_amp_assoc(Dev, Dev->pal_cfg.local_ampassoc);
    return(HCI_SUCCESS);
}

/*
typedef struct  local_amp_info_resp_t {
    A_UINT8     status;
    A_UINT8     amp_status;
    A_UINT32    total_bw;           
    A_UINT32    max_guranteed_bw;   
    A_UINT32    min_latency;
    A_UINT32    max_pdu_size;
    A_UINT8     amp_type;
    A_UINT16    pal_capabilities;
    A_UINT16    amp_assoc_len;
    A_UINT16    max_flush_timeout;  
    A_UINT16    be_flush_timeout;   
    A_UINT8     pal_ver;            
    A_UINT16    pal_sub_ver;        
    A_UINT16    pal_sig_name;       
    A_UINT8     hci_version;        
    A_UINT16    hci_revision;       
} POSTPACK  LOCAL_AMP_INFO;
*/
static void init_local_amp_cfg(AMP_DEV *Dev, PAL_CFG* cfg)
{
    LOCAL_AMP_INFO Local_AmpInfo = { 
                            HCI_SUCCESS,                        
                            PAL_ENABLE,                        
                            PAL_MAX_BANDWIDTH,
                            PAL_MAX_GUARANTEED_BANDWIDTH,
                            PAL_MINI_LATENCY,
                            Max80211_PAL_PDU_Size,
                            PAL_CONTORLLER_TYPE,
                            PAL_CAPABILITY,
                            Max80211_AMP_ASSOC_Len,
                            PAL_MAX_FLUSH_TIMEOUT,
                            PAL_BE_FLUSH_TIMEOUT,
                            HCI_VERSION,
                            HCI_REVISION,
                            PAL_VERSION,
                            PAL_SIG_NAME,
                            PAL_SUB_VERSION,
                    };

    os_memcpy(&Dev->pal_cfg.local_ampinfo, &Local_AmpInfo, sizeof(LOCAL_AMP_INFO));

    PAL_POSH_API->GetSupportedPhyType(Dev, &Dev->wifi_caps); //Fill in WiFi CAP
    PAL_PRINT(("PAL Wifi CAP = (%X) \n", Dev->wifi_caps));
 

    PAL_POSH_API->GetMaxDataRate(Dev, &Dev->pal_cfg.local_ampinfo.total_bw);
    PAL_PRINT(("PAL Max Bandwi = (%d) \n", Dev->pal_cfg.local_ampinfo.total_bw));
    if (Dev->pal_cfg.local_ampinfo.total_bw >= MAX_80211G_BW)
        Dev->pal_cfg.local_ampinfo.total_bw = MAX_80211G_BW;
    PAL_PRINT(("PAL Guarded Max Bandwi = (%d) \n", Dev->pal_cfg.local_ampinfo.total_bw));
    Dev->pal_cfg.local_ampinfo.max_guranteed_bw = Dev->pal_cfg.local_ampinfo.total_bw - 10*1000; //10 Mbps

    cfg->conn_accept_timeout = DEFAULT_CONN_ACCPT_TO;
    cfg->logical_link_accept_timeout = DEFAULT_LL_ACCPT_TO;
    cfg->flow_control_mode = DATA_BLK_BASED_FLOW_CONTROL_MODE;

    pal_evt_set_evt_mask(Dev, 0,  (A_UINT64)~0);
    pal_evt_set_evt_mask(Dev, 1,  (A_UINT64)~0);
}

void
init_local_amp_assoc(AMP_DEV *Dev, AMP_ASSOC_INFO *Local_Amp)
{
    A_UINT8     reg[20], sz = 0;

    //Prepare Preferred channel list here
    os_memcpy(reg, "XXX", AMP_COUNTRY_LENGTH); //unknown country code
    sz += AMP_COUNTRY_LENGTH;

    //Assuming we support all 802.11G channel
    reg[sz++] = IEEE80211_REG_EXT_ID;
    reg[sz++] = DEF_11G_REG_CLASS_ID;
    reg[sz++] = 0;
    Pal_fill_amp_assoc(Dev, Local_Amp, sz, reg);

    //Call LPOSH to fill in init assoc info
    //PAL_POSH_API->QueryChannelInfo(Dev, NULL);
}

//-----------------------------------------------------------------
// Update local AMP assoc after we get prefer channel list info
// from MP
//-----------------------------------------------------------------
void
Update_local_amp_assoc(AMP_DEV *Dev, AMP_ASSOC_INFO *Local_Amp, A_UINT8 *Chanlist, A_UINT16 Len)
{
    PAL_PRINT(("PAL Received Preferred Channel List (Len=%d), Update AMP Assoc: \n",
                Len));

    dump_frame(Chanlist, Len);
    //TO be done later, 802.11N channel
    Pal_fill_amp_assoc(Dev, Local_Amp, Len, Chanlist);
}

void
setup_local_amp_assco_by_country(AMP_ASSOC_INFO *Local_Amp, A_UINT8 *Chanlist, A_UINT16 *plen)
{
    A_UINT8 Country[AMP_COUNTRY_LENGTH];
    AMP_DEV *Dev = Local_Amp->amp_dev;
    
    *plen = 0;
    os_memcpy(Country, Chanlist, AMP_COUNTRY_LENGTH);

    PAL_POSH_API->QueryCTL(Local_Amp, Country);

    if (Local_Amp->CTL2G != Local_Amp->CTL5G) {
        PAL_PRINT(("##########CTL2G is not equal CTL5G, which CTL should we use???#############\n"));
    }
    
    if (!IsValidCTL(Local_Amp->CTL2G, Country)) {
        PAL_PRINT(("CTL2G is invalid\n"));
    }

    if (Local_Amp->CTL2G == CTL_FCC) {
        (*plen) += AMP_COUNTRY_LENGTH;//Country

        Chanlist[(*plen)++] = IEEE80211_REG_EXT_ID;
        Chanlist[(*plen)++] = DEF_FCC_11G_REG_CLASS_ID;
        Chanlist[(*plen)++] = 0;
    } else if (Local_Amp->CTL2G == CTL_ETSI) {
        (*plen) += AMP_COUNTRY_LENGTH;//Country

        Chanlist[(*plen)++] = IEEE80211_REG_EXT_ID;
        Chanlist[(*plen)++] = DEF_ETSI_11G_REG_CLASS_ID;
        Chanlist[(*plen)++] = 0;
    } else if (Local_Amp->CTL2G == CTL_MKK) {
		(*plen) += AMP_COUNTRY_LENGTH;//Country

        Chanlist[(*plen)++] = IEEE80211_REG_EXT_ID;
        Chanlist[(*plen)++] = DEF_MKK_11G_REG_CLASS_ID;
        Chanlist[(*plen)++] = 0;
    } else {
        setup_default_local_amp_assco(Chanlist, plen);
    }
}

void
setup_default_local_amp_assco(A_UINT8 *Chanlist, A_UINT16 *plen)
{
    os_memcpy(Chanlist, "XXX", AMP_COUNTRY_LENGTH); //unknown country code
    (*plen) += AMP_COUNTRY_LENGTH;

    Chanlist[(*plen)++] = IEEE80211_REG_EXT_ID;
    Chanlist[(*plen)++] = DEF_11G_REG_CLASS_ID;
    Chanlist[(*plen)++] = 0;
}

