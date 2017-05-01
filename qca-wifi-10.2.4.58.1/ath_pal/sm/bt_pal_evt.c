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
//  Filename:  bt_pal_evt.c
//
//  Author:    Dham Viswanadham
//
//  Created:   5/11/2008
//
//  Descriptions:
//
//    AMP Controller Main HCI Event Decoding
//
//----------------------------------------------------------------------------
#include "osdep.h"
#include "pal_osapi.h"
#include "paldebug.h"
#include "amp_db.h"
#include "bt_pal_evt.h"
#include "bt_inp.h"
#include "wlan_drv_intf.h"

static pal_evt_dispatcher evt_dispatcher = NULL;


void
pal_evt_set_dispatcher(pal_evt_dispatcher fn)
{
    evt_dispatcher = fn;
}

void
pal_evt_set_evt_mask(AMP_DEV *Dev, A_UINT8 index, A_UINT64 mask)
{
    Dev->pal_cfg.hci_event_mask[index] = mask;
}


void
pal_cmd_compl_evt(AMP_DEV *Dev, A_UINT16 cmd_opcode, A_UINT8 *params, A_UINT8 param_len)
{
	A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1+sizeof(ULONG_PTR)];

	HCI_EVENT_CMD_COMPLETE *evt = (HCI_EVENT_CMD_COMPLETE *)(eventBuf+sizeof(ULONG_PTR));

    evt->event_code = PAL_COMMAND_COMPLETE_EVENT;
    evt->param_len = (A_UINT8)(param_len + 3); /* Two fixed value params adds 3 bytes*/
    evt->num_hci_cmd_pkts = NUM_HCI_COMMAND_PKTS;
    evt->opcode = cmd_opcode;
    os_memcpy(evt->params, params, param_len);
   
    pal_send_event(Dev, (A_UINT8*)evt, evt->param_len + HCI_EVENT_HDR_SIZE);
}


void
pal_cmd_status_evt(AMP_DEV *Dev, A_UINT16 cmd_opcode, A_UINT8 status)
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];

    HCI_EVENT_CMD_STATUS *evt = (HCI_EVENT_CMD_STATUS *)eventBuf;

    evt->event_code = PAL_COMMAND_STATUS_EVENT;
    evt->param_len = 4; /* fixed size*/
    evt->status = status;
    evt->num_hci_cmd_pkts = NUM_HCI_COMMAND_PKTS;
    evt->opcode = cmd_opcode;

    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
}


void 
pal_hw_err_evt(AMP_DEV *Dev, A_UINT8 err_code)
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    HCI_EVENT_HW_ERR *evt = (HCI_EVENT_HW_ERR *)eventBuf;

    evt->event_code = PAL_HARDWARE_ERROR_EVENT;
    evt->param_len = 1; /* fixed size*/
    evt->hw_err_code = err_code;

    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
}


void
pal_flush_occured_evt(AMP_DEV *Dev, A_UINT16 handle)
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    HCI_EVENT_FLUSH_OCCRD *evt = (HCI_EVENT_FLUSH_OCCRD *)eventBuf;

    evt->event_code = PAL_FLUSH_OCCURRED_EVENT;
    evt->param_len = 2; /* fixed size*/
    evt->handle = handle;

    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
}


void 
pal_enhanced_flush_complete_event(AMP_DEV *Dev, A_UINT16 handle)
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    HCI_EVENT_ENHANCED_FLUSH_COMPLT *evt = (HCI_EVENT_ENHANCED_FLUSH_COMPLT *)eventBuf;

    evt->event_code = PAL_ENHANCED_FLUSH_COMPLT_EVENT;
    evt->param_len = 2; /* fixed size*/
    evt->hdl = handle;
    /*Clear the flush id*/
    Dev->flush_llc = 0;
    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
}

void
pal_loopback_cmd_evt(AMP_DEV *Dev, A_UINT8 *params, A_UINT16 param_len)
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    HCI_EVENT_LOOPBACK_CMD *evt = (HCI_EVENT_LOOPBACK_CMD *)eventBuf;
    A_UINT16 len;

    evt->event_code = PAL_LOOPBACK_EVENT;
    evt->param_len = (A_UINT8)param_len;

    /* A max of 252 bytes can be copied in to parameters 
     */
    len = (param_len > MAX_EVT_PKT_SZ - HCI_CMD_HDR_SZ) ? 
                    (MAX_EVT_PKT_SZ - HCI_CMD_HDR_SZ): param_len;
    os_memcpy(evt->params, params, len);

    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
}

void
pal_data_buffer_overflow_evt(AMP_DEV *Dev, A_UINT8 link_type)
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    HCI_EVENT_DATA_BUF_OVERFLOW *evt = (HCI_EVENT_DATA_BUF_OVERFLOW *)eventBuf;
    
    evt->event_code = PAL_BUFFER_OVERFLOW_EVENT;
    evt->param_len = 1;
    evt->link_type = link_type;
    
    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
}


void
pal_qos_violation_evt(AMP_DEV *Dev, A_UINT16 handle)
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    HCI_EVENT_QOS_VIOLATION *evt = (HCI_EVENT_QOS_VIOLATION *)eventBuf;

    evt->event_code = PAL_QOS_VIOLATION_EVENT;
    evt->param_len = 1; /* fixed size*/
    evt->handle = handle;

    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
}


void
pal_phy_link_compl_evt(AMP_DEV *Dev, A_UINT8 status, A_UINT8 phy_link_hdl)
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    HCI_EVENT_PHY_LINK_COMPLETE *evt = (HCI_EVENT_PHY_LINK_COMPLETE *)eventBuf;

    evt->event_code = PAL_PHYSICAL_LINK_COMPL_EVENT;
    evt->param_len = 2; /* fixed size */
    evt->status = status;
    evt->phy_link_hdl = phy_link_hdl;

    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
}


void
pal_chan_sel_evt(AMP_DEV *Dev, A_UINT8 phy_link_hdl)
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    HCI_EVENT_CHAN_SELECT *evt = (HCI_EVENT_CHAN_SELECT *)eventBuf;

    evt->event_code = PAL_CHANNEL_SELECT_EVENT;
    evt->param_len = 1; /* fixed size */
    evt->phy_link_hdl = phy_link_hdl;

    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
}


void
pal_disconnect_phy_link_compl_evt(AMP_DEV *Dev, A_UINT8 status, A_UINT8 phy_link_hdl, A_UINT8 reason)
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    HCI_EVENT_DISCONNECT_PHY_LINK_COMPLETE * evt = 
            (HCI_EVENT_DISCONNECT_PHY_LINK_COMPLETE *) eventBuf;

    evt->event_code = PAL_DISCONNECT_PHYSICAL_LINK_EVENT;
    evt->param_len = 3;
    evt->status = status;
    evt->phy_link_hdl = phy_link_hdl;
    evt->reason = reason;

    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
}

void
pal_logical_link_compl_evt(AMP_DEV *Dev, A_UINT8 status, A_UINT16 logical_link, A_UINT8 phy_hdl, A_UINT8 TxID)
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    HCI_EVENT_LOGICAL_LINK_COMPLETE_EVENT *evt = 
                (HCI_EVENT_LOGICAL_LINK_COMPLETE_EVENT *)eventBuf;

    evt->event_code = PAL_LOGICAL_LINK_COMPL_EVENT;
    evt->param_len = 5;
    evt->status = status;
    evt->logical_link_hdl = logical_link;
    evt->phy_hdl = phy_hdl;
    evt->TxFlowId = TxID;

    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);

    //-----------------------------------------------------------------------
    // MTsai, it is PAL's responsibility to create the Tx and Rx data thread
    // at the event that the logic link creation is completed.
    //-----------------------------------------------------------------------
}


void
pal_disconnect_logical_link_compl_evt(AMP_DEV *Dev, A_UINT8 status, A_UINT16 id, A_UINT8 reason)
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    HCI_EVENT_DISCONNECT_LOGICAL_LINK_EVENT *evt = 
                    (HCI_EVENT_DISCONNECT_LOGICAL_LINK_EVENT *)eventBuf;

    evt->event_code = PAL_DISCONNECT_LOGICAL_LINK_COMPL_EVENT;
    evt->param_len = 4;
    evt->status = status;
    evt->logical_link_hdl = id;
    evt->reason = reason;

    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
}


void
pal_flow_spec_modify_evt (AMP_DEV *Dev, A_UINT8 status, A_UINT16 handle)
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    HCI_EVENT_FLOW_SPEC_MODIFY *evt = (HCI_EVENT_FLOW_SPEC_MODIFY *)eventBuf;
    
    evt->event_code = PAL_FLOW_SPEC_MODIFY_COMPL_EVENT;
    evt->param_len = 3; 
    evt->status = status;
    evt->handle = handle;

    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);

}


void
pal_num_of_compl_data_blocks_evt(AMP_DEV *Dev, 
                                 A_UINT16 num_data_blks, A_UINT8 num_handles, 
                                 A_UINT16 *handles, A_UINT16 *num_compl_pkts, 
                                 A_UINT16 *num_compl_blks)
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    A_UINT8 *cur, len;
    A_UINT8 i;
    HCI_EVENT_NUM_COMPL_DATA_BLKS *evt = (HCI_EVENT_NUM_COMPL_DATA_BLKS *)eventBuf;
    
    evt->event_code = PAL_NUM_COMPL_DATA_BLOCK_EVENT;
    evt->param_len = 3 + 6*num_handles;
    evt->num_data_blks = num_data_blks;
    evt->num_handles = num_handles;

    cur = evt->params;

    for (i=0; i<num_handles; i++) {
        len = sizeof(A_UINT16);
        os_memcpy(cur, &handles[i],len);
        cur += len;
        os_memcpy(cur, &num_compl_pkts[i], len);
        cur += len;
        os_memcpy(cur, &num_compl_blks[i], len);
        cur += len;
    }

    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
}

void
pal_num_of_compl_packet_evt(AMP_DEV *Dev, A_UINT8 num_handles, 
                            A_UINT16 *handles, A_UINT16 *num_compl_pkts) 
                            
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    A_UINT8 *cur, len;
    A_UINT8 i;
    HCI_EVENT_NUM_COMPL_PACKETS *evt = (HCI_EVENT_NUM_COMPL_PACKETS *)eventBuf;
    
    evt->event_code = PAL_NUM_COMPL_PACKET_EVENT;
    evt->param_len = 1 + 4*num_handles;
    evt->num_handles = num_handles;

    cur = evt->params;

    for (i=0; i<num_handles; i++) {
        len = sizeof(A_UINT16);
        os_memcpy(cur, &handles[i], len);
        cur += len;
        os_memcpy(cur, &num_compl_pkts[i], len);
        cur += len;
     }

    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
}

void
pal_srm_change_compl_evt(AMP_DEV *Dev, A_UINT8 status, A_UINT8 phy_link, A_UINT8 sr_state)
{
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    HCI_EVENT_SRM_COMPL *evt = (HCI_EVENT_SRM_COMPL *)eventBuf;

    evt->event_code = PAL_SHORT_RANGE_MODE_CHANGE_COMPL_EVENT;
    evt->param_len = 3;
    evt->status = status;
    evt->phy_link = phy_link;
    evt->state = sr_state;

    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
}


void
pal_send_event(AMP_DEV *Dev, A_UINT8 *buf, A_UINT16 sz)
{
    /* Check if stack has masked the event */
    if ((buf[0] >> 6) <= 1) {//vaild hci_event_mask index, check this event
        if (!((Dev->pal_cfg.hci_event_mask[buf[0] >> 6]) & (A_UINT64)(0x1 << (buf[0] & ~0xC0)))){
            PAL_PRINT(("event mask off (0x%02x)\n", buf[0]));
            return;
        }
    }

    if (evt_dispatcher) {
        evt_dispatcher(Dev, buf, sz);
    }

    pal_decode_event(buf, sz);
}

void pal_amp_status_changed_evt(AMP_DEV *Dev, A_UINT8 AmpStatus)
 {
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];

    HCI_EVENT_AMP_STATUS_CHANGE *evt = (HCI_EVENT_AMP_STATUS_CHANGE *)eventBuf;
    evt->event_code = PAL_AMP_STATUS_CHANGE_EVENT;
    evt->param_len = 2; /* fixed size */
    evt->status = 0;
    evt->amp_status = AmpStatus;

    pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
 }

