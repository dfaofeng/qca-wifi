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
//  Filename:  wlan_drv_intf.c
//
//  Author:    Dham Viswanadham
//
//  Created:   5/11/2008
//
//  Descriptions:
//
//           AMP Controller Wlan Driver Interface
//
//---------------------------------------------------------------------------

#include "osdep.h"
#include "pal_osapi.h"
#include "ieee80211_defs.h"
#define WLAN_DRV_INTF
#include "amp_db.h"
#undef  WLAN_DRV_INTF
#include "wlan_drv_intf.h"
#include "bt_pal_evt.h"
#include "paldebug.h"
#include "pal_state.h"
#include "poshApi.h"
#include "bt_pal_txq.h"

//--------------------------------------------------------------------------
// Definition
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Local Variables
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Global Functions
//--------------------------------------------------------------------------


void
pal_data_set_dispatcher(acl_data_dispatcher fn)
{
    data_dispatcher = fn;
}


//--------------------------------------------------------------------------------------------------
// Shall move these in a permanent location after completion
//--------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// This function create 802.11 frame based on input ACL data frame after stripping out the
// the logic link handler from PAL_SendAclData()
//
// It is also responsible for sending out security data frames (m1, m2, m3 and m4)
// As well link_supervision_timeout and activity_report
//
// IN - r_amp:    Remote device handler for the device data base
//      acl_data: ACL_data pointer passed from stack
//      len:      ACL_data len passed from stack
//-------------------------------------------------------------------------------------------------
/*
 * BTAMP Header length calculated as follows:
 *     30 bytes: 4-address frame
 *      3 bytes: LLC header
 *      3 bytes: Snap header
 *      2 bytes: Protocol ID
 *
 * IV information will be prepended later and is not included in this calculation.
 * The NetBufferList must contain enough backfill space to hold IV plus any other
 * additional information.
 */

void create_80211_fr_and_send(
     AMP_ASSOC_INFO* r_amp, A_UINT8 *acl_data,   A_UINT16 len,  
     A_UINT8 type,          A_UINT8 serviceType, A_UINT32 LogicID)
{

    A_UINT8                     fc_dur[]  = {0x08, 0x03, 00, 00};
    A_UINT8                     llc_hdr[] = {0xAA, 0xAA, 0x03, 0x00, 0x19, 0x58, 0x00, 0x01};
    A_UINT8                     *pBuf, *pStartBuf;
    A_UINT16                    sz = 0;
    A_UINT8                     *dest = r_amp->hwaddr;
    A_UINT8                     *src  = &r_amp->amp_dev->hwaddr[0];
    AMP_DEV                     *Dev = r_amp->amp_dev;
    PACKET_HANDLE               pBufHdl;
    POSH_SEND_PACKET_CONTEXT    SendPktCtxt;

    OS_AcquireLock(&r_amp->amp_dev->PalDataQLock);

    SendPktCtxt.len             = len + SNAP_TYPE_OFFSET;
    if (PAL_POSH_API->AllocatePacket(Dev, &SendPktCtxt) != 0) {
        OS_ReleaseLock(&r_amp->amp_dev->PalDataQLock);
        return;
    }
    pStartBuf = SendPktCtxt.buf;
    pBufHdl = SendPktCtxt.poshHdl;
    pBuf = pStartBuf;
    sz = 0;

    llc_hdr[7] = type; /* This is the protocol type in LLC-SNAP hdr */

    OS_assert(pBuf != NULL);

    if (pBuf == NULL) {
        PAL_PRINT(("PAL: Invalid pBuf in creating 802.11 header, return \n"));
        OS_ReleaseLock(&r_amp->amp_dev->PalDataQLock);
        return;
    }

    //Header Size = 4
    os_memcpy(pBuf, fc_dur, sizeof(fc_dur));
    sz += sizeof(fc_dur);
    pBuf += sizeof(fc_dur);

    //Header Size = 10
    os_memcpy(pBuf, dest, 6);
    sz += 6;
    pBuf += 6;

    //Header Size = 16
    os_memcpy(pBuf, src, 6);
    sz += 6;
    pBuf += 6;

    //Header Size = 22
    os_memcpy(pBuf, dest, 6);
    sz += 6;
    pBuf += 6;

    //Header Size = 24
    *((A_UINT16 *)pBuf) = Dev->g_seq_num++ << IEEE80211_SEQ_SEQ_SHIFT;
    sz += 2;
    pBuf += 2;

    //Header Size = 30
    os_memcpy(pBuf, src, 6);
    sz += 6;
    pBuf += 6;

    //Header Size = 38 
    os_memcpy(pBuf, llc_hdr, sizeof(llc_hdr));
    sz += sizeof(llc_hdr);
    pBuf += sizeof(llc_hdr);
    
    os_memcpy(pBuf, acl_data, len); //append the ACL data here
    pBuf += len;
    sz += len;
  
    SendPktCtxt.Dev             = r_amp->amp_dev;
    SendPktCtxt.r_amp           = r_amp;
    //SendPktCtxt.buf             = pStartBuf;
    SendPktCtxt.len             = sz;
    SendPktCtxt.logical_link_id = LogicID;
    SendPktCtxt.user_priority   = serviceType; 
    //SendPktCtxt.poshHdl         = pBufHdl;

    PAL_POSH_API->PopulatePacketContext(r_amp->amp_dev, &SendPktCtxt);

#if ATH_AMP_ISOLATE_TX_PATH
    pal_tx_queue_add_packet(&(r_amp->amp_dev->pal_tx_queue),
                            &SendPktCtxt);
#else                            
    PAL_POSH_API->SendPacket(r_amp->amp_dev, &SendPktCtxt);
#endif                            
    OS_ReleaseLock(&r_amp->amp_dev->PalDataQLock);

}

void
send_pal_link_supervision_tx(AMP_ASSOC_INFO *amp, A_UINT8 type)
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    HCI_DEBUG_EVENT *evt = (HCI_DEBUG_EVENT *)eventBuf;
    if (amp)
    {
        OS_AcquireLock(&amp->amp_dev->PalDataQLock);
        if (amp->amp_dev->PalDataInQueue != false)
        {
            //we have data inque already, give it higher priority         
            amp->amp_dev->PalDataInQueue = false;
            amp->ping_cnt = 0;
            OS_ReleaseLock(&amp->amp_dev->PalDataQLock);
            return;
        }

        OS_ReleaseLock(&amp->amp_dev->PalDataQLock);
        if (amp->hwaddr) {
            if (type == LINK_SUPERVISION_REQ) {
                PAL_PRINT(("LSTO triggered, send Link_supervision_req\n"));
                amp->ping_cnt++;
            }
            if ((amp->amp_dev->ampDbgWdmEnable & PAL_LSTO_TEST) != 0) {

                if (type == LINK_SUPERVISION_REQ)
                    evt->event_type = LSTO_REQ;
                else if (type == LINK_SUPERVISION_RESP)
                    evt->event_type = LSTO_RESP;

                evt->event_code = PAL_DEBUG_EVENT;
                evt->param_len = 1;
                    
                pal_send_event(amp->amp_dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
            }
            create_80211_fr_and_send(amp, NULL, 0, type, EFS2UPtable[BE], (MASK_FOR_LINK_SUPERVSION+amp->phy_link_hdl));
        } 
    }
}

void
send_activity_report(AMP_DEV *dev, AMP_ASSOC_INFO *r_amp, A_BOOL schedule_known, A_UINT16 num_rpts, SCHEDULE *sch)
{
    A_UINT8             len, buf[256];
    ACTIVITY_RPT_HDR    *hdr;

    /* An activity report of larger than 256 is very generous, given each activity report is 12 bytes. 
     * If ever such an activity report is generated by BT acitivity, the wlan is possibly unsable
     * due to intereference! */
    hdr = (ACTIVITY_RPT_HDR *)buf;

    if ((r_amp->amp_dev->ampDbgWdmEnable & PAL_ACT_RPT_TEST) != 0) {
        hdr->num_rpts = 0;
        hdr->schedule_known = 0;
    } else {
        /* set default num_rpts to 0 */
        hdr->num_rpts = 0;
        hdr->schedule_known = schedule_known;
    }
    
    len = sizeof(ACTIVITY_RPT_HDR);

    if (schedule_known > 1) {
        hdr->num_rpts = num_rpts;
        if (num_rpts && sch) {
            /* Copy Schedule after the AR header */
            os_memcpy(buf + sizeof(ACTIVITY_RPT_HDR), sch, num_rpts*sizeof(SCHEDULE));
            len = (A_UINT8) (len + num_rpts*sizeof(SCHEDULE));
        }
    }

    create_80211_fr_and_send(r_amp, buf, len , ACTIVITY_REPORT, EFS2UPtable[BE], (MASK_FOR_ACTIVITY_REPORT+r_amp->phy_link_hdl));
}

