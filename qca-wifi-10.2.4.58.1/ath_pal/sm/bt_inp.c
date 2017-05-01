/*
 * Copyright (c) 2008-2010, Atheros Communications Inc. 
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
//  Filename:  bt_inp.c
//
//  Author:    Dham Viswanadham
//
//  Created:   5/11/2008
//
//  Descriptions:
//
//    AMP Controller Thread Initialization
//    This module handles all the PAL data Tx/Rx process
//
//----------------------------------------------------------------------------

#include "osdep.h"
#include "pal_osapi.h"
#include "paldebug.h"
#include "wlan_drv_intf.h"
#include "amp_db.h"
#include "bt_inp.h"
#include "bt_pal_evt.h"
#include "poshApi.h"
#include "pal_hci.h"

static A_UINT32
PAL_SendAclData(AMP_DEV *dev, HCI_ACL_DATA_PKT *pkt);

int
hci_data_tx_enque(AMP_DEV *dev, A_UINT8 *buf, A_UINT16 sz)
{
    UNUSED(sz);
 
    PAL_PRINT_DATA(("Rcv ACL Data -len(%d) \n", ((HCI_ACL_DATA_PKT *)buf)->data_len));
    dump_frame(buf, sz);

    dev->PalDataInQueue = true;
    PAL_SendAclData(dev, (HCI_ACL_DATA_PKT *)buf);

    return(0);
}


static A_UINT32
PAL_SendAclData(AMP_DEV *dev, HCI_ACL_DATA_PKT *pkt)
{
    A_UINT16  id = GET_LLID_FROM_PKT_HDL(pkt->hdl_and_flags);
    A_UINT8 phy_hdl;
    AMP_ASSOC_INFO *amp;
    LLID_INFO *llid;
    A_INT8 serviceType;

    phy_hdl = PAL_GET_PHY_HDL_FROM_LLID(id);

    get_remote_assoc_amp(dev, PAL_GET_PHY_HDL_FROM_LLID(id), &amp);

    if (amp == NULL) {
        PAL_PRINT(("AMP not present for this phy hdl = 0x%x, llid = 0x%x\n",
                    phy_hdl, id));
        return(HCI_ERR_UNKNOWN_CONN_ID);   /* Return some non-zero code indicating error */
    }

    find_logical_link_info(amp, id, &llid);

    if(llid == NULL) {
        PAL_PRINT(("LLID not present for llid = %d\n", id));
        return (HCI_ERR_UNKNOWN_CONN_ID);
    }

    if (dev->flush_llc == id) {
        if (pkt->hdl_and_flags & AMP_ACL_PACKET_FLAG ) {
            pal_flush_occured_evt(dev, llid->logical_link_id);
            return HCI_SUCCESS;
        } else {
            OS_assert(0);
        }    
    }


//    PAL_PRINT(("Send out ACL data frame, Len(%d), FCS(%0X) \n", pkt->data_len,  *(A_UINT16 *)(&pkt->data[pkt->data_len-2])));  
    PAL_PRINT_DATA(("PAL_Send out ACL data frame, Len(%d), logical link ID(%04X), DA(%02X:%02X:%02X:%02X:%02X:%02X) \n", 
               pkt->data_len, llid->logical_link_id, 
               *amp->hwaddr, 
               *(amp->hwaddr+1),
               *(amp->hwaddr+2),
               *(amp->hwaddr+3),
               *(amp->hwaddr+4),
               *(amp->hwaddr+5)
               ));  
    serviceType = mapEFS2UserPriority(llid->tx_spec);
    if(serviceType == -1)
    {
        return HCI_ERR_QOS_UNACCEPTABLE_PARM;
    }
    create_80211_fr_and_send(amp, pkt->data, pkt->data_len, ACL_DATA, serviceType, (A_UINT32)llid->logical_link_id);
    return 0;
}


void
acl_data_tx_complete(AMP_DEV* Dev, A_UINT32 LogicLinkId, A_BOOL status)
{
    A_UINT16 num_compl_pkts, num_compl_blks, Lid;
    AMP_ASSOC_INFO  *amp;
    LLID_INFO       *llid;  
    PAL_CFG *pCfg = &Dev->pal_cfg;

    /* Reporting NoCP for every tx data pkt is very inefficient.
     * ToDo : PAL must keep the count between two NoCP event reports,
     * and reset after reporting. In case of the event being masked,
     * count is maintained locally. Report all handles and cnts togather
     */
    num_compl_pkts = num_compl_blks = 1;

    if (pCfg->flow_control_mode == DATA_BLK_BASED_FLOW_CONTROL_MODE)
        pal_num_of_compl_data_blocks_evt(Dev, NUMBER_OF_PACKET_AVAILABLE, 1, (A_UINT16 *)&LogicLinkId, &num_compl_pkts, &num_compl_blks);
    else
        pal_num_of_compl_packet_evt(Dev, 1, (A_UINT16 *)&LogicLinkId, &num_compl_pkts);

    if (status != HCI_SUCCESS)
    {
        pal_flush_occured_evt(Dev, (A_UINT16)LogicLinkId);

        Lid = (A_UINT16)LogicLinkId;       
        get_remote_assoc_amp(Dev, PAL_GET_PHY_HDL_FROM_LLID(Lid), &amp);
        
        if (amp == NULL) 
            return;

        find_logical_link_info(amp, Lid, &llid);
        
        if (llid == NULL)
            return;
       
        llid->failedContactCounter++;
        PAL_PRINT(("Increase Failed Contact Counter (%d) \n", llid->failedContactCounter)); 
        
    }

}

//----------------------------------------------------------------------------------------------------------
// Test utility, create a fake physical link to test out Tx/Rx data path without the burden of creating
// physical link first. This also allows unit test of entire data conversion, host stacks interface, ..
// etc.
//----------------------------------------------------------------------------------------------------------
A_UINT16
PAL_SetFakePhyLink(AMP_DEV *dev, A_UINT8 PhyHdl)
{
    AMP_ASSOC_INFO *amp;
    FLOW_SPEC tx,  rx;
    A_UINT16  id = 0; //Logic Link ID we will be sending back

    PAL_PRINT(("Phy link hdl = %d\n", PhyHdl));
    OS_assert(PhyHdl != PAL_INVALID_PHYSICAL_LINK_ID);
  
    if (PhyHdl == PAL_INVALID_PHYSICAL_LINK_ID) //give it something meaningful
        PhyHdl = 1;

    get_remote_assoc_amp(dev, PhyHdl, &amp);

    if (amp == NULL) {
        alloc_rem_assoc_amp(dev, PhyHdl, &amp);
    }
    else //reject this physical link command from AMP manager
    {
        PAL_PRINT(("Phy link (%d) Exists already, LogicLinkId (%04X) \n", PhyHdl, amp->last_assigned_llid));
        return(amp->last_assigned_llid);
    }

    amp->phy_link_state = CONNECTED_STATE; //fake it
    tx.id = 1;
    tx.service_type = SERVICE_TYPE_BEST_EFFORT; 
    rx.id = 1;
    rx.service_type = SERVICE_TYPE_BEST_EFFORT; 
    id = generate_logical_link(amp, &tx, &rx);
    PAL_PRINT(("PAL: Logical id = 0x%x, service type = 0x%x\n", id, tx.service_type));
    init_local_amp_assoc(dev, amp);
    OS_assert(amp->hwaddr != NULL);

    if (amp->hwaddr == NULL)
    {
        PAL_PRINT(("PAL: Invalid AMP ASSOC filled \n"));
        return(0);
    }
    
    amp->hwaddr[5] = 0xAA; //change the last digit of MAC addr
    PAL_PRINT(("Filled in MAC addr as %02X:%02X:%02X:%02X:%02X:%02X:\n", 
                amp->hwaddr[0], amp->hwaddr[1], amp->hwaddr[2],
                amp->hwaddr[3], amp->hwaddr[4], amp->hwaddr[5]));

    return(id);
}

