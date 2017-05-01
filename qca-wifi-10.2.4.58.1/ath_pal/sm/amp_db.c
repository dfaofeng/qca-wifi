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
//  Filename:  AMP_db.c
//
//  Author:    Dham Viswanadham
//
//  Created:   5/11/2008
//
//  Descriptions:
//
//    AMP Controller Database Management
//
//----------------------------------------------------------------------------

#include "osdep.h"
#include "pal_osapi.h"
#include "amp_db.h"
#include "paldebug.h"
#include "time.h"
#include "stdlib.h"
#include "poshApi.h"
#include "bt_pal_evt.h"

static void
generate_chan_list_from_reg_triplet(A_UINT8 *reg, A_UINT16 sz, AMP_CH *chan_11g, A_UINT8 *len_11g, AMP_CH *chan_11a, A_UINT8 *len_11a, A_UINT8 CTL);

static 
A_UINT8 pal_del_all_llc(AMP_ASSOC_INFO *r_amp);

static A_UINT8
GenerateRandomChannel(A_UINT32 range);

//====================================================================================
//Good for 802-11G and 802-11A, later for 802-11N
// If we found matched channel equal registry ampSelChannel, then use registry channel
// else if we found matched channel equal default channel, use default channel
// else if we found any matched channel, use first channel inside the list
// else return 0
//=====================================================================================
static inline void AMP_GET_PREF_CHANNEL(
 A_UINT8 l_len, A_UINT8 r_len, AMP_CH *l_chan, AMP_CH *r_chan, 
 AMP_CH *SelChannel, A_UINT8 RegChannel)
{
    A_UINT8 i, j = 0;
    A_UINT8 totalChan = 0;
    AMP_CH matchedChan[MAX_CHANNEL_COUNT];
    os_memset(matchedChan, 0, MAX_CHANNEL_COUNT*sizeof(AMP_CH));

    if (l_len > MAX_CHANNEL_COUNT) {
        PAL_PRINT(("AMP_GET_PREF_CHANNEL local length reachs the MAX\n"));
        l_len = MAX_CHANNEL_COUNT;
    }

    if (r_len > MAX_CHANNEL_COUNT) {
        PAL_PRINT(("AMP_GET_PREF_CHANNEL remote length reachs the MAX\n"));
        r_len = MAX_CHANNEL_COUNT;
    }

    for (i=0; i<l_len; i++) {
        for (j=0; j<r_len; j++) {
            if (l_chan[i].ieee == r_chan[j].ieee) { //found matched channel
                //----------------------------------------------------------
                if (totalChan < MAX_CHANNEL_COUNT) {
                    matchedChan[totalChan] = l_chan[i];
                    totalChan++;
                } else {
                    PAL_PRINT(("length reachs the MAX, stop comparing\n"));
                    break;                    
                }
                    
                //If we found our preferred channel from registry, return
                if (RegChannel == l_chan[i].ieee) {
                    *SelChannel = l_chan[i];
                    return;
                }
               //-----------------------------------------------------------
            }
        }
    }

    if (totalChan != 0) {
        // pick up the first matched channel
        i = 0;
        
        ASSERT(matchedChan[i].ieee);

        PAL_PRINT(("select matchedChan[%d]=%d\n", i, matchedChan[i].ieee));
        *SelChannel = matchedChan[i];
        return;
    }

    SelChannel->ieee = INVALID_AMP_CHANNEL_NUM;
    SelChannel->regClassId = INVALID_AMP_CHANNEL_REGID;
}

void
amp_db_init(AMP_DEV *Dev)
{
    os_memset(Dev->rem_assoc_amp, 0, ((sizeof(AMP_ASSOC_INFO))*NUM_OF_AMP_ASSOC_INFO));
    PAL_PRINT(("AMP DB init - Done\n"));
}

void
alloc_rem_assoc_amp(AMP_DEV* dev, A_UINT8 phy_link_hdl, AMP_ASSOC_INFO **amp)
{
    A_UINT8 i;
    AMP_ASSOC_INFO *node;

    /* Allocate the first available node*/
    for (i = 0; i < NUM_OF_AMP_ASSOC_INFO; i++) {
        node = &(dev->rem_assoc_amp[i]);
        if (!PHY_HDL_VALID(node)) {
            PHY_HDL_VALID(node) = TRUE;
            node->phy_link_hdl = phy_link_hdl;
            node->last_assigned_llid = PAL_CREATE_LLID_FROM_PHYHDL(phy_link_hdl, 0);
            node->link_supervision_timeout = DEFAULT_LSTO;
            node->qos_support = 1;
            node->amp_dev = dev;
            node->CTL2G = NOCTL;
            node->CTL5G = NOCTL;
            node->ping_cnt = 0;
            *amp = node;
            return; //Get our node here
        }
    }

    *amp = NULL; //No more links available
}

//--------------------------------------------
// This function counts any link that is not
// in disconnected state. Whether it is in
// starting, connecting, connected 
// state.
//--------------------------------------------
A_UINT8 get_total_remote_links(AMP_DEV* dev, A_UINT16 phy_link_hdl)
{
#ifndef PAL_DO_NOT_STOP_BEACON
    A_UINT8 i, total_link = 0;
    AMP_ASSOC_INFO *node;

    /* Allocate the first available node*/
    for (i = 0; i < NUM_OF_AMP_ASSOC_INFO; i++) {
        node = &(dev->rem_assoc_amp[i]);
        if (node->phy_link_hdl != phy_link_hdl) //do not count our own link
        {
            if (node->phy_link_state != DISCONNECTED_STATE) {
                total_link++;
            }
        }
    }

    return(total_link);
#else
    UNUSED(phy_link_hdl);
    return(dev->ampBeaconStarted);
#endif
}

static A_UINT8 pal_del_all_llc(AMP_ASSOC_INFO *r_amp)
{
    A_UINT8 i;
    A_UINT16 id;
    LLID_INFO *link;
     
        /* Iterate thru all the LL's and disconnect them */
     for (i = 0; i < MAX_FLOW_SPECS_PER_PHY_LINK; i++) {
            id = PAL_CREATE_LLID_FROM_PHYHDL(r_amp->phy_link_hdl, i);
            find_logical_link_info(r_amp, id, &link);
            if (link) {
                free_logical_link(r_amp, id);
                if (r_amp->flag & FLAG_LINK_SVTO_Event) {
                    pal_disconnect_logical_link_compl_evt(r_amp->amp_dev, HCI_SUCCESS, id, HCI_ERR_CON_TIMEOUT);
                } else {
                    pal_disconnect_logical_link_compl_evt(r_amp->amp_dev, HCI_SUCCESS, id, HCI_ERR_CON_TERM_BY_HOST);
                }
            }
     }

     return HCI_SUCCESS;
}

void
free_rem_assoc_amp( AMP_ASSOC_INFO *amp)
{
    pal_del_all_llc(amp);
    os_memset(amp, 0, sizeof(*amp));
}

void
get_remote_assoc_amp(AMP_DEV *Dev, A_UINT16 phy_link_hdl, AMP_ASSOC_INFO **amp)
{
    A_UINT8 i;
    AMP_ASSOC_INFO *node;
    
    *amp = NULL;

    for (i = 0; i < NUM_OF_AMP_ASSOC_INFO; i++) {
        node = &(Dev->rem_assoc_amp[i]);
        if (PHY_HDL_VALID(node) && node->phy_link_hdl == phy_link_hdl) {
            *amp = node;
            break;
        }
    }
}

AMP_ASSOC_INFO 
*get_remote_amp_assoc_via_addr(AMP_DEV* dev, A_UINT8 *addr)
{
    A_UINT8 i;
    AMP_ASSOC_INFO *node;
    

    for (i = 0; i < NUM_OF_AMP_ASSOC_INFO; i++) {
        node = &(dev->rem_assoc_amp[i]);
        if (PHY_HDL_VALID(node) && node->hwaddr &&
           (os_memcmp(node->hwaddr, addr, IEEE80211_ADDR_LEN) == 0)) {
 			return (node);
        }
    }

    return 0;
}

AMP_ASSOC_INFO  
*get_remote_amp_assoc_via_state(AMP_DEV* dev, A_UINT32 State)
{
    A_UINT8 i;
    AMP_ASSOC_INFO *node;
    
    for (i = 0; i < NUM_OF_AMP_ASSOC_INFO; i++) {
        node = &(dev->rem_assoc_amp[i]);
        if (PHY_HDL_VALID(node) && 
           (node->phy_link_action_state == State)) {
 			return (node);
        }
    }
    
    return (NULL);

}

/* Generates logical link for a new FLOW SPEC. It copies the FLOW_SPEC 
 * in to db and returns new logical id. An error returns 0 as logical link id
 * LogicLinkId = (((internal FlowID -> different from the FlowId assigned by host) << 8) || Physical Link ID)
 */
A_UINT16
generate_logical_link(AMP_ASSOC_INFO *amp, FLOW_SPEC *tx_spec, FLOW_SPEC *rx_spec)
{
    A_UINT8     flow_id;
    A_UINT16    logical_link_id = 0;

    flow_id = PAL_GET_FLOW_ID_FROM_LLID(amp->last_assigned_llid);

    do {
        flow_id++;
        flow_id %= MAX_FLOW_SPECS_PER_PHY_LINK;
        /* Check if this node is free. If so assign it and
         * populate it
         */
        if (amp->logical_link[flow_id].logical_link_id == 0) {
            LLID_INFO *llid = &(amp->logical_link[flow_id]);
            llid->logical_link_id = 
                PAL_CREATE_LLID_FROM_PHYHDL(amp->phy_link_hdl, flow_id);
            amp->last_assigned_llid = llid->logical_link_id;
            logical_link_id = llid->logical_link_id;

            os_memcpy(&llid->tx_spec, tx_spec, sizeof(*tx_spec));
            os_memcpy(&llid->rx_spec, rx_spec, sizeof(*rx_spec));
            break;
        }
    } while(flow_id !=  PAL_GET_FLOW_ID_FROM_LLID(amp->last_assigned_llid));

    OS_assert(logical_link_id != 0);
    return  logical_link_id;
}

void
find_logical_link_info(AMP_ASSOC_INFO *amp, A_UINT16 id, LLID_INFO **info)
{
    A_UINT8     flow_id;

    *info = NULL;
    flow_id = PAL_GET_FLOW_ID_FROM_LLID(id);

    if (flow_id < MAX_FLOW_SPECS_PER_PHY_LINK) {
        LLID_INFO *llid = &(amp->logical_link[flow_id]);
        /* LLID must have been assigned. */
        if (llid->logical_link_id) {
            *info = llid;
        }
    }
}


A_BOOL
free_logical_link(AMP_ASSOC_INFO *amp, A_UINT16 id)
{
    A_UINT8 i = 0, flg=FALSE;

    for (i = 0; i < MAX_FLOW_SPECS_PER_PHY_LINK; i++) {
        LLID_INFO *llid = &(amp->logical_link[i]);

        if (llid->logical_link_id == id) {
            os_memset(llid, 0, sizeof(*llid));
            flg = TRUE;
            break;
        }
    }
    return flg;
}



A_BOOL
get_phy_hdl(AMP_DEV *Dev, A_UINT8 *addr, A_UINT8 *phy_hdl)
{
    A_UINT8 i;
    AMP_ASSOC_INFO *node;
    
    for (i = 0; i < NUM_OF_AMP_ASSOC_INFO; i++) {
        node = &(Dev->rem_assoc_amp[i]);
        if (PHY_HDL_VALID(node)) { 
            OS_assert(node->hwaddr != NULL);
          
            if (node->hwaddr == NULL) {//Protect from BSOD
                return(false);
            }

            if (os_memcmp(node->hwaddr, addr, IEEE80211_ADDR_LEN) == 0) {
                *phy_hdl = node->phy_link_hdl;
                return(true);
            }
        }
    }
    
    return(false);
}

/* creates a TLV in the format of tag(1), len(1), val(len)..
 * The buffer returned is at the end of adding the TLV
 * Buffer is owned by caller and we assume it has space
 * allocated beforehand.
 */
A_UINT8 *
append_tlv(A_UINT8 *buf, A_UINT8 tag, A_UINT16 len, A_UINT8 * val)
{
    /* caller to make sure that buf will have len+2 bytes */
    *buf = tag;
    buf++;
    *(A_UINT16*)buf = len;
    buf += 2;
    os_memcpy(buf, val, len);
    buf += len;
    return buf;
}


/* The format is assumed to be in TLV format. Tag(1), len(1) 
 * and value(len)... This API searches the tag and returns
 * that in info param to caller
 */
void
parse_amp_assoc(A_UINT8 *buf, A_UINT8 tag, A_UINT8 **info , A_UINT16 TotalLen)
{
    A_UINT8 *cur = buf;
    A_UINT8 *end = &(buf[TotalLen-1]);
    A_UINT16 len;
    while( (*cur != tag) && (cur - buf < AMP_ASSOC_LEN) ) {
        len = *(A_UINT16*)(cur+1);
        /*check invaild length*/
        if (len >= (end -(cur+2))) {
            *info = NULL;
            PAL_PRINT(("invalid length %d in the buffer \n", len));
            OS_assert(0);
            return;
        }
        cur += len + 3;
    }

    if (*cur == tag) {
        *info = cur;
    } else {
        *info = NULL;
        PAL_PRINT(("Failed to get tag %d in the buffer \n", tag));
        OS_assert(0);
    }
}

static A_UINT8
GenerateRandomChannel(A_UINT32 range)
{
    A_UINT32    SelIndex = 0;

    if (range <= 1) { //Only one channel
        return ((A_UINT8)SelIndex);
    }
    
    OS_GET_RANDOM_BYTES((u_int32_t *) &SelIndex, sizeof(A_UINT32));

    SelIndex = SelIndex % range; 
    return ((A_UINT8)SelIndex);

}


void
perform_chan_select(AMP_ASSOC_INFO *l_amp, AMP_ASSOC_INFO *r_amp, AMP_CH *SelChannel)
{
    A_UINT16 r_len, l_len;
    A_UINT8 *info, *l_reg, *r_reg;
    AMP_CH l_chan_g[MAX_CHANNEL_COUNT], r_chan_g[MAX_CHANNEL_COUNT], l_chan_a[MAX_CHANNEL_COUNT], r_chan_a[MAX_CHANNEL_COUNT];
    A_UINT8 l_11a_len=0, l_11g_len=0, r_11a_len=0, r_11g_len=0;
    AMP_DEV *Dev = r_amp->amp_dev;
    A_UINT8 Country[AMP_COUNTRY_LENGTH];
    os_memset(l_chan_g, 0, MAX_CHANNEL_COUNT*sizeof(AMP_CH));
    os_memset(r_chan_g, 0, MAX_CHANNEL_COUNT*sizeof(AMP_CH));
    os_memset(l_chan_a, 0, MAX_CHANNEL_COUNT*sizeof(AMP_CH));
    os_memset(r_chan_a, 0, MAX_CHANNEL_COUNT*sizeof(AMP_CH));

    /* Set a default value for selected channel*/
    SelChannel->APcount = 0;
    SelChannel->ieee = INVALID_AMP_CHANNEL_NUM;
    SelChannel->freq = INVALID_AMP_CHANNEL_FRQ;
    SelChannel->regClassId = INVALID_AMP_CHANNEL_REGID;
    /* 1. Get the local chan list 
       2. Get the first freq 

       3. Get the remote chan list 
       4. iterate to match the first chan from local chan list
       5. If success - got channel , otherwise repeat from 1) 
     */
    parse_amp_assoc(l_amp->amp_assoc, AMP_ASSOC_PREF_CHAN_LIST, &info, l_amp->assoc_len);
    if (!info){
        PAL_PRINT(("Failed to get AMP_ASSOC_PREF_CHAN_LIST in l_amp assoc buffer \n"));
        return;
    }
    l_len = *(A_UINT16*)(info + AMP_PREF_CHAN_LIST_TAG_LEN);
    if (l_len <= (AMP_PREF_CHAN_LIST_TAG_LEN + AMP_PREF_CHAN_LIST_LENGTH_LEN)) {
        PAL_PRINT(("Failed to get AMP_ASSOC_PREF_CHAN_LIST in l_amp assoc buffer len=%d\n",l_len));
        return;
    }
    //discard tag 1 byte and length 2 byte
    l_reg = info + (AMP_PREF_CHAN_LIST_TAG_LEN + AMP_PREF_CHAN_LIST_LENGTH_LEN);

    parse_amp_assoc(r_amp->amp_assoc, AMP_ASSOC_PREF_CHAN_LIST, &info, r_amp->assoc_len);
    if (!info){
        PAL_PRINT(("Failed to get AMP_ASSOC_PREF_CHAN_LIST in r_amp assoc buffer \n"));
        return;
    }
    r_len = *(A_UINT16*)(info + AMP_PREF_CHAN_LIST_TAG_LEN);
    if (r_len <= (AMP_PREF_CHAN_LIST_TAG_LEN + AMP_PREF_CHAN_LIST_LENGTH_LEN)) {
        PAL_PRINT(("Failed to get AMP_ASSOC_PREF_CHAN_LIST in r_amp assoc buffer len=%d\n",r_len));
        return;
    }
    //discard tag 1 byte and length 2 byte
    r_reg = info + (AMP_PREF_CHAN_LIST_TAG_LEN + AMP_PREF_CHAN_LIST_LENGTH_LEN);

    os_memcpy(Country, l_reg, AMP_COUNTRY_LENGTH);
    PAL_POSH_API->QueryCTL(l_amp, Country);
    if (l_amp->CTL2G != l_amp->CTL5G) {
        PAL_PRINT(("##########Local CTL2G is not equal CTL5G, which CTL should we use???#############\n"));
    }
    ASSERT(IsValidCTL(l_amp->CTL2G, Country));

    os_memcpy(Country, r_reg, AMP_COUNTRY_LENGTH);
    PAL_POSH_API->QueryCTL(r_amp, Country);
    if (r_amp->CTL2G != r_amp->CTL5G) {
        PAL_PRINT(("##########Remote CTL2G is not equal CTL5G, which CTL should we use???#############\n"));
    }
    ASSERT (IsValidCTL(r_amp->CTL2G, Country));

    /* Expand the reg triplet to chan list for matching */
    generate_chan_list_from_reg_triplet(l_reg, l_len, l_chan_g, &l_11g_len, l_chan_a, &l_11a_len, l_amp->CTL2G);
    generate_chan_list_from_reg_triplet(r_reg, r_len, r_chan_g, &r_11g_len, r_chan_a, &r_11a_len, r_amp->CTL2G);

    PAL_PRINT(("Local Channel G, Len(%d) \n", l_11g_len));
    PAL_PRINT(("Local Channel A, Len(%d) \n", l_11a_len));
    PAL_PRINT(("Remote Channel G, Len(%d) \n", r_11g_len));
    PAL_PRINT(("Remote Channel A, Len(%d) \n", r_11a_len));


    //--------------------------------------------------------------------
    // 11 A channel checking
    // Firstly check 11a channel
    AMP_GET_PREF_CHANNEL(l_11a_len, r_11a_len, l_chan_a, r_chan_a, SelChannel, (A_UINT8)Dev->ampSelChannel);
    // Then check 11g channel
    if (SelChannel->ieee == INVALID_AMP_CHANNEL_NUM) {
        AMP_GET_PREF_CHANNEL(l_11g_len, r_11g_len, l_chan_g, r_chan_g, SelChannel, (A_UINT8)Dev->ampSelChannel);
    }
}

BOOLEAN
CheckSubband(A_UINT8* ptr, A_UINT16 size)
{
    if (size <= sizeof(REG_EXTN_TRIPLET)){
        /* The next is not the triplet in preferred channel list*/
        return FALSE;
    }

    if (*ptr == IEEE80211_REG_EXT_ID){
        return FALSE;
    }
    return TRUE;
}

static void
generate_chan_list_from_reg_triplet(A_UINT8 *reg, A_UINT16 sz, AMP_CH *chan_11g, A_UINT8 * len_11g, AMP_CH * chan_11a, A_UINT8 * len_11a, A_UINT8 CTL)
{
        REG_TRIPLET *triplet;
        REG_EXTN_TRIPLET *extn_triplet;
        A_UINT8 i;
        A_UINT8 **precnt = &len_11a;
        AMP_CH **prech = &chan_11a;
        A_UINT8 *temp_reg;
        A_UINT16 temp_sz;
        A_UINT8 index = 0, index_found = 0;
        A_UINT8 channels[MAX_CHANNEL_MAP_NUM];
        A_UINT8  regclassID = 0;
        A_UINT8 nums_11G_Chan =0;
        A_UINT8 nums_11A_Chan =0;

        os_memset(channels, 0, MAX_CHANNEL_MAP_NUM);

        if (sz >= 6) {
            PAL_PRINT(("Country = %02x %02x %02x\n", reg[0], reg[1], reg[2]));
            reg += 3;
            sz -= 3;
            /*check nums_11G_Chan and nums_11A_Chan first*/
            temp_reg  = reg;
            temp_sz  =  sz;

            while (temp_sz) {
                triplet = (REG_TRIPLET*)temp_reg;

                if (triplet->first_chan != IEEE80211_REG_EXT_ID) {
                    if (triplet->first_chan <= MAX_11G_CHANNEL) {
                        nums_11G_Chan += triplet->num_of_chan;
                    } else {
                        nums_11A_Chan += triplet->num_of_chan;
                    }
                } else {
                    extn_triplet = (REG_EXTN_TRIPLET*)triplet;                   
                    /*Check next triplet*/
                    triplet = (REG_TRIPLET *)(temp_reg + sizeof(REG_EXTN_TRIPLET));

                    /*Check if not includes subband triplet*/
                    if (!CheckSubband(&triplet->first_chan, temp_sz)) {
                        os_memset(channels, 0, MAX_CHANNEL_MAP_NUM);
                        regclassID = extn_triplet->reg_class;
                        Get_Channel_MAP(channels, CTL, regclassID);
                        
                        for (i = 0; i < MAX_CHANNEL_MAP_NUM ; i++) {
                            if (channels[i] == 0) {
                                break;
                            }
                        }

                        /* check if this is for 11G or 11A*/
                        if (channels[0] <= MAX_11G_CHANNEL ) {
                             nums_11G_Chan += i;
                        } else {
                             nums_11A_Chan += i;
                        }
                    }
                }
                temp_reg += sizeof(REG_EXTN_TRIPLET);
                temp_sz -= sizeof(REG_EXTN_TRIPLET);
            }

            if ((nums_11G_Chan + nums_11A_Chan) > MAX_CHANNEL_COUNT) {
                PAL_PRINT(("total channel number more than MAX\n"));
            }

            regclassID = 0;
            
            while (sz) {
                triplet = (REG_TRIPLET *)reg;

                if (triplet->first_chan != IEEE80211_REG_EXT_ID) {
                    index_found = 0;
                    for (i = 0; i < triplet->num_of_chan; i++) {
                        if (triplet->first_chan <= MAX_11G_CHANNEL) {
                            if (*len_11g < nums_11G_Chan) {
                                prech = &chan_11g;
                                precnt = &len_11g;
                            } else {
                                PAL_PRINT(("11G channel length parsing error\n"));
                                break;                                
                            }
                            (*prech)->ieee = triplet->first_chan + i;
                            (*prech)->regClassId = regclassID;
                            (*prech)++;
                        } else {//For 11A
                            /*using the record channel map to find out which channel numbers are implied*/
                            if (*len_11a < nums_11A_Chan) {
                                prech = &chan_11a;
                                precnt = &len_11a;
                            } else {
                                PAL_PRINT(("11A channel length parsing error\n"));
                                break;                                
                            }

                            if (index_found == 0) {
                                for (index = 0; (index < MAX_CHANNEL_MAP_NUM && channels[index] != 0); index++) {
                                   if (channels[index] == triplet->first_chan) {
                                        index_found = 1;
                                        break;
                                    }
                                }
                            }

                            if (index_found == 1) {
                                (*prech)->ieee = channels[(index+i)] ;
                                (*prech)->regClassId = regclassID;                                
                            } else {
                                if (triplet->num_of_chan == 1) {
                                    (*prech)->ieee = triplet->first_chan;
                                    (*prech)->regClassId = 0;                                
                                } else {
                                    PAL_PRINT(("Can't find the channel in channel map and the number of channe is not 1\n"));
                                    break;
                                }
                            }

                            (*prech)++;                                
                        }
                    }
                    *(*precnt)= *(*precnt)+triplet->num_of_chan;
                } else {//IEEE80211_REG_EXT_ID
                    extn_triplet = (REG_EXTN_TRIPLET*)triplet;
                    os_memset(channels, 0, MAX_CHANNEL_MAP_NUM);
                    regclassID = extn_triplet->reg_class;
                    Get_Channel_MAP(channels, CTL, regclassID);

                    /*Check next triplet*/
                    triplet = (REG_TRIPLET *)(reg + sizeof(REG_EXTN_TRIPLET));

                    /*Check if not includes subband triplet*/
                    if (!CheckSubband(&triplet->first_chan, sz)) {
                        /* check if this is for 11G or 11A*/
                        if (channels[0] <= MAX_11G_CHANNEL ) {
                            for (i = 0; (i < MAX_CHANNEL_MAP_NUM && channels[i] != 0); i++) {
                                chan_11g->ieee = channels[i];
                                chan_11g->regClassId = regclassID;
                                chan_11g++;
                            }
                            *(len_11g) += i;
                        } else {
                            for (i = 0; (i < MAX_CHANNEL_MAP_NUM && channels[i] != 0); i++) {
                                chan_11a->ieee = channels[i];
                                chan_11a->regClassId = regclassID;
                                chan_11a++;
                            }
                            *(len_11a) += i;
                        }
                    }
                }

                if ((*len_11g + *len_11a) >= MAX_CHANNEL_COUNT) {
                    PAL_PRINT(("length reachs the MAX , stop parsing the assco preferred channel list\n"));
                    break;
                }
                
                reg += sizeof(REG_TRIPLET);
                sz -= sizeof(REG_TRIPLET);
            }
        } else {
            PAL_PRINT(("Regulatory TLV smaller than 6 bytes!\n"));
            assert(0);
        }
}

/*
  1.Guaranteed bandwidth traffic is traffic with a minimum data rate but no particular latency requested. 
	Latency will be related to the link supervision timeout.
	For this type of traffic Access Latency is set to 0xFFFFFFFF.
  2.Guaranteed Latency traffic is traffic with only latency requirements. 
	For this type of traffic SDU Inter-arrival time is set to 0xFFFFFFFF. 
	HID interrupt channel and AVRCP are examples of this type of traffic.
  3.Both Guaranteed Latency and Bandwidth traffic has both a latency and bandwidth requirement. 
	An example is Audio/Video streaming.
*/
A_INT8
mapEFS2UserPriority(FLOW_SPEC efs)
{
    if (efs.service_type == SERVICE_TYPE_BEST_EFFORT) 
    {
        return EFS2UPtable[BE];
    } else if (efs.service_type == SERVICE_TYPE_GUARANTEED) {
        //This combination can't be happening for guaranteed flow spec.
        if ((efs.access_latency == 0xFFFFFFFF) && (efs.sdu_inter_arrival_time == 0xFFFFFFFF)) {	
            OS_assert(0);
            return -1;
        }

        if (efs.access_latency == 0xFFFFFFFF)
        {
            return EFS2UPtable[MAX_BW];//GU_BW
        } else {
            return EFS2UPtable[MIN_LATENCY];//GU_LATENCY
        }
    } else {
        return -1;
    }
}

A_INT8 IsValidCTL(A_UINT8 CTL, A_UINT8* Country)
{
    A_UINT8    defCountry[4] = "XXX";
    if (CTL != NOCTL && CTL != CTL_FCC && CTL != CTL_MKK && CTL != CTL_ETSI) {
        PAL_PRINT(("Invalid CTL\n"));
        return 0;
    } else {
        if (CTL == NOCTL && os_memcmp(Country, defCountry, AMP_COUNTRY_LENGTH)) {
            PAL_PRINT(("NO_CTL but the country isoName is not XXX\n"));
            return 0;
        }
    }
    return 1;            
}

void Get_Channel_MAP(A_UINT8* des, A_UINT8 CTL, A_UINT8 checkId)
{
    if (CTL == CTL_FCC) {
        if (checkId == 1) {
            os_memcpy(des, CHANNEL_MAP(FCC,1), sizeof(CHANNEL_MAP(FCC,1)));
        } else  if (checkId == 2) {
             os_memcpy(des, CHANNEL_MAP(FCC,2), sizeof(CHANNEL_MAP(FCC,2)));
        } else  if (checkId == 3) {
             os_memcpy(des, CHANNEL_MAP(FCC,3), sizeof(CHANNEL_MAP(FCC,3)));
        } else  if (checkId == 4) {
             os_memcpy(des, CHANNEL_MAP(FCC,4), sizeof(CHANNEL_MAP(FCC,4)));
        } else  if (checkId == 5) {
             os_memcpy(des, CHANNEL_MAP(FCC,5), sizeof(CHANNEL_MAP(FCC,5)));
        } else  if (checkId == 6) {
             os_memcpy(des, CHANNEL_MAP(FCC,6), sizeof(CHANNEL_MAP(FCC,6)));
        } else  if (checkId == 7) {
             os_memcpy(des, CHANNEL_MAP(FCC,7), sizeof(CHANNEL_MAP(FCC,7)));
        } else  if (checkId == 8) {
             os_memcpy(des, CHANNEL_MAP(FCC,8), sizeof(CHANNEL_MAP(FCC,8)));
        } else  if (checkId == 9) {
             os_memcpy(des, CHANNEL_MAP(FCC,9), sizeof(CHANNEL_MAP(FCC,9)));
        } else  if (checkId == 10) {
             os_memcpy(des, CHANNEL_MAP(FCC,10), sizeof(CHANNEL_MAP(FCC,10)));
        } else  if (checkId == 11) {
             os_memcpy(des, CHANNEL_MAP(FCC,11), sizeof(CHANNEL_MAP(FCC,11)));
        } else  if (checkId == 12) {
             os_memcpy(des, CHANNEL_MAP(FCC,12), sizeof(CHANNEL_MAP(FCC,12)));
        }
    } else if (CTL == CTL_MKK) {
        if (checkId == 1) {
             os_memcpy(des, CHANNEL_MAP(MKK,1), sizeof(CHANNEL_MAP(MKK,1)));
        } else  if (checkId == 2) {
             os_memcpy(des, CHANNEL_MAP(MKK,2), sizeof(CHANNEL_MAP(MKK,2)));
        } else  if (checkId == 3) {
             os_memcpy(des, CHANNEL_MAP(MKK,3), sizeof(CHANNEL_MAP(MKK,3)));
        } else  if (checkId == 4) {
             os_memcpy(des, CHANNEL_MAP(MKK,4), sizeof(CHANNEL_MAP(MKK,4)));
        } else  if (checkId == 5) {
             os_memcpy(des, CHANNEL_MAP(MKK,5), sizeof(CHANNEL_MAP(MKK,5)));
        } else  if (checkId == 6) {
             os_memcpy(des, CHANNEL_MAP(MKK,6), sizeof(CHANNEL_MAP(MKK,6)));
        } else  if (checkId == 7) {
             os_memcpy(des, CHANNEL_MAP(MKK,7), sizeof(CHANNEL_MAP(MKK,7)));
        } else  if (checkId == 8) {
             os_memcpy(des, CHANNEL_MAP(MKK,8), sizeof(CHANNEL_MAP(MKK,8)));
        } else  if (checkId == 9) {
             os_memcpy(des, CHANNEL_MAP(MKK,9), sizeof(CHANNEL_MAP(MKK,9)));
        } else  if (checkId == 10) {
             os_memcpy(des, CHANNEL_MAP(MKK,10), sizeof(CHANNEL_MAP(MKK,10)));
        } else  if (checkId == 11) {
             os_memcpy(des, CHANNEL_MAP(MKK,11), sizeof(CHANNEL_MAP(MKK,11)));
        } else  if (checkId == 12) {
            os_memcpy( des, CHANNEL_MAP(MKK,12), sizeof(CHANNEL_MAP(MKK,12)));   
        } else  if (checkId == 13) {
             os_memcpy(des, CHANNEL_MAP(MKK,13), sizeof(CHANNEL_MAP(MKK,13)));
        } else  if (checkId == 14) {
             os_memcpy(des, CHANNEL_MAP(MKK,14), sizeof(CHANNEL_MAP(MKK,14)));
        } else  if (checkId == 15) {
             os_memcpy(des, CHANNEL_MAP(MKK,15), sizeof(CHANNEL_MAP(MKK,15)));
        } else  if (checkId == 16) {
             os_memcpy(des, CHANNEL_MAP(MKK,16), sizeof(CHANNEL_MAP(MKK,16)));
        } else  if (checkId == 17) {
             os_memcpy(des, CHANNEL_MAP(MKK,18), sizeof(CHANNEL_MAP(MKK,18)));
        } else  if (checkId == 18) {
             os_memcpy(des, CHANNEL_MAP(MKK,18), sizeof(CHANNEL_MAP(MKK,18)));
        } else  if (checkId == 19) {
             os_memcpy(des, CHANNEL_MAP(MKK,19), sizeof(CHANNEL_MAP(MKK,19)));
        } else  if (checkId == 20) {
             os_memcpy(des, CHANNEL_MAP(MKK,20), sizeof(CHANNEL_MAP(MKK,20)));
        } else  if (checkId == 21) {
             os_memcpy(des, CHANNEL_MAP(MKK,21), sizeof(CHANNEL_MAP(MKK,21)));
        } else  if (checkId == 22) {
             os_memcpy(des, CHANNEL_MAP(MKK,22), sizeof(CHANNEL_MAP(MKK,22)));   
        } else  if (checkId == 23) {
             os_memcpy(des, CHANNEL_MAP(MKK,23), sizeof(CHANNEL_MAP(MKK,23)));
        } else  if (checkId == 24) {
             os_memcpy(des, CHANNEL_MAP(MKK,24), sizeof(CHANNEL_MAP(MKK,24)));
        } else  if (checkId == 25) {
             os_memcpy(des, CHANNEL_MAP(MKK,25), sizeof(CHANNEL_MAP(MKK,25)));
        } else  if (checkId == 26) {
             os_memcpy(des, CHANNEL_MAP(MKK,26), sizeof(CHANNEL_MAP(MKK,26)));
        } else  if (checkId == 27) {
             os_memcpy(des, CHANNEL_MAP(MKK,27), sizeof(CHANNEL_MAP(MKK,27)));
        } else  if (checkId == 28) {
             os_memcpy(des, CHANNEL_MAP(MKK,28), sizeof(CHANNEL_MAP(MKK,28)));
        } else  if (checkId == 29) {
             os_memcpy(des, CHANNEL_MAP(MKK,29), sizeof(CHANNEL_MAP(MKK,29)));
        } else  if (checkId == 30) {
             os_memcpy(des, CHANNEL_MAP(MKK,30), sizeof(CHANNEL_MAP(MKK,30)));
        } else  if (checkId == 31) {
             os_memcpy(des, CHANNEL_MAP(MKK,31), sizeof(CHANNEL_MAP(MKK,31)));
        } else  if (checkId == 32) {
             os_memcpy(des, CHANNEL_MAP(MKK,32), sizeof(CHANNEL_MAP(MKK,32)));
        } else  if (checkId == 34) {
             os_memcpy(des, CHANNEL_MAP(MKK,34), sizeof(CHANNEL_MAP(MKK,34)));
        }
    } else if (CTL == CTL_ETSI) {
        if (checkId == 1) {
             os_memcpy(des, CHANNEL_MAP(ETSI,1), sizeof(CHANNEL_MAP(ETSI,1)));
        } else  if (checkId == 2) {
             os_memcpy(des, CHANNEL_MAP(ETSI,2), sizeof(CHANNEL_MAP(ETSI,2)));
        } else  if (checkId == 3) {
             os_memcpy(des, CHANNEL_MAP(ETSI,3), sizeof(CHANNEL_MAP(ETSI,3)));
        } else  if (checkId == 4) {
             os_memcpy(des, CHANNEL_MAP(ETSI,4), sizeof(CHANNEL_MAP(ETSI,4)));
        }
    } else  if (CTL == NOCTL) {
         if (checkId == 254) {
             os_memcpy(des, CHANNEL_MAP(NOCTL,254), sizeof(CHANNEL_MAP(NOCTL,254)));
         }
    }
}

