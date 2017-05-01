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
//  Filename:  bt_pal.c
//
//  Author:    Dham Viswanadham
//
//  Created:   5/11/2008
//
//  Descriptions:
//
//    AMP Controller Main HCI Command Decoding
//
//----------------------------------------------------------------------------
#include "osdep.h"
#include "pal_osapi.h"
#include "paldebug.h"
#include "amp_db.h"
#include "wlan_drv_intf.h"
#include "pal_state.h"
#include "bt_pal_evt.h"
#include "poshApi.h"
#include "bt_inp.h"
#include "bt_pal_txq.h"


static A_UINT32 hci_nop(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_reset(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_set_event_mask(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_read_xyz_timeout(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_write_xyz_timeout(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_enhanced_flush(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_read_link_supervision_timeout(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_write_link_supervision_timeout(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_read_location_data(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_write_location_data(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_read_flow_control_mode(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_write_flow_control_mode(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_write_be_flush_timeout(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_read_be_flush_timeout(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_short_range_mode(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_read_local_ver_info(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_read_local_supported_cmds(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_read_data_block_size(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_read_local_amp_info(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_read_local_amp_assoc(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_write_remote_amp_assoc(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_read_failed_contact_counter(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_reset_failed_contact_counter(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_read_link_quality(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_read_rssi(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_create_physical_link(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_create_logical_link(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_disconnect_logical_link(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_disconnect_physical_link(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_logical_link_cancel(AMP_DEV *dev, void *cmd, void *buf);
static A_UINT32 hci_flow_spec_modify(AMP_DEV *dev, void *cmd, void *buf);

OCF_CMD_TBL cmd_tbl[] = {
        {HCI_CMD_NOP,                           hci_nop,                             (A_UINT8*)"hci_nop" },
        {HCI_Create_Physical_Link,              hci_create_physical_link,            (A_UINT8*)"HCI_Create_Physical_Link"},
        {HCI_Accept_Physical_Link_Req,          hci_create_physical_link,            (A_UINT8*)"HCI_Accept_Physical_Link_Req"},                                  
        {HCI_Disconnect_Physical_Link,          hci_disconnect_physical_link,        (A_UINT8*)"HCI_Disconnect_Physical_Link"},
        {HCI_Create_Logical_Link,               hci_create_logical_link,             (A_UINT8*)"HCI_Create_Logical_Link"},
        {HCI_Accept_Logical_Link,               hci_create_logical_link,             (A_UINT8*)"HCI_Accept_Logical_Link"},
        {HCI_Disconnect_Logical_Link,           hci_disconnect_logical_link,         (A_UINT8*)"HCI_Disconnect_Logical_Link"},
        {HCI_Logical_Link_Cancel,               hci_logical_link_cancel,             (A_UINT8*)"HCI_Logical_Link_Cancel"},
        {HCI_Flow_Spec_Modify,                  hci_flow_spec_modify,                (A_UINT8*)"HCI_Flow_Spec_Modify"},
        {HCI_Set_Event_Mask,                    hci_set_event_mask,                  (A_UINT8*)"HCI_Set_Event_Mask"},
        {HCI_Reset_Pal,                         hci_reset,                           (A_UINT8*)"HCI_Reset_Pal"},
        {HCI_Read_Conn_Accept_Timeout,          hci_read_xyz_timeout,                (A_UINT8*)"HCI_Read_Conn_Accept_Timeout"},    
        {HCI_Write_Conn_Accept_Timeout,         hci_write_xyz_timeout,               (A_UINT8*)"HCI_Write_Conn_Accept_Timeout"},   
        {HCI_Read_Logical_Link_Accept_Timeout,  hci_read_xyz_timeout,                (A_UINT8*)"HCI_Read_Logical_Link_Accept_Timeout"},
        {HCI_Write_Logical_Link_Accept_Timeout, hci_write_xyz_timeout,               (A_UINT8*)"HCI_Write_Logical_Link_Accept_Timeout"},
        {HCI_Enhanced_Flush,                    hci_enhanced_flush,                  (A_UINT8*)"HCI_Enhanced_Flush"},
        {HCI_Read_Link_Supervision_Timeout,     hci_read_link_supervision_timeout,   (A_UINT8*)"HCI_Read_Link_Supervision_Timeout"},
        {HCI_Write_Link_Supervision_Timeout,    hci_write_link_supervision_timeout,  (A_UINT8*)"HCI_Write_Link_Supervision_Timeout"},
        {HCI_Read_Location_Data,                hci_read_location_data,              (A_UINT8*)"HCI_Read_Location_Data"},
        {HCI_Write_Location_Data,               hci_write_location_data,             (A_UINT8*)"HCI_Write_Location_Data"},
        {HCI_Set_Event_Mask_Page_2,             hci_set_event_mask,                  (A_UINT8*)"HCI_Set_Event_Mask_Page_2"},
        {HCI_Read_Flow_Control_Mode,            hci_read_flow_control_mode,          (A_UINT8*)"HCI_Read_Flow_Control_Mode"},
        {HCI_Write_Flow_Control_Mode,           hci_write_flow_control_mode,         (A_UINT8*)"HCI_Write_Flow_Control_Mode"},
        {HCI_Write_BE_Flush_Timeout,            hci_write_be_flush_timeout,          (A_UINT8*)"HCI_Write_BE_Flush_Timeout"},
        {HCI_Read_BE_Flush_Timeout,             hci_read_be_flush_timeout,           (A_UINT8*)"HCI_Read_BE_Flush_Timeout"},
        {HCI_Short_Range_Mode,                  hci_short_range_mode,                (A_UINT8*)"HCI_Short_Range_Mode"},            
        {HCI_Read_Local_Ver_Info,               hci_read_local_ver_info,             (A_UINT8*)"HCI_Read_Local_Ver_Info"},
        {HCI_Read_Local_Supported_Cmds,         hci_read_local_supported_cmds,       (A_UINT8*)"HCI_Read_Local_Supported_Cmds"},
        {HCI_Read_Data_Block_Size,              hci_read_data_block_size,            (A_UINT8*)"HCI_Read_Data_Block_Size"},
        {HCI_Read_Failed_Contact_Counter,       hci_read_failed_contact_counter,     (A_UINT8*)"HCI_Read_Failed_Contact_Counter"},
        {HCI_Reset_Failed_Contact_Counter,      hci_reset_failed_contact_counter,    (A_UINT8*)"HCI_Reset_Failed_Contact_Counter"},
        {HCI_Read_Link_Quality,                 hci_read_link_quality,               (A_UINT8*)"HCI_Read_Link_Quality"},
        {HCI_Read_RSSI,                         hci_read_rssi,                       (A_UINT8*)"HCI_Read_RSSI"},
        {HCI_Read_Local_AMP_Info,               hci_read_local_amp_info,             (A_UINT8*)"HCI_Read_Local_AMP_Info"},
        {HCI_Read_Local_AMP_ASSOC,              hci_read_local_amp_assoc,            (A_UINT8*)"HCI_Read_Local_AMP_ASSOC"},
        {HCI_Write_Remote_AMP_ASSOC,            hci_write_remote_amp_assoc,          (A_UINT8*)"HCI_Write_Remote_AMP_ASSOC"},
     
};

SUPPORT_CMD amp_support[] = {
    DEFINE_SUPPORT_CMD(HCI_Create_Physical_Link,                0x1501 ),
    DEFINE_SUPPORT_CMD(HCI_Accept_Physical_Link_Req,            0x1502 ),
    DEFINE_SUPPORT_CMD(HCI_Disconnect_Physical_Link,            0x1504 ),
    DEFINE_SUPPORT_CMD(HCI_Create_Logical_Link,                 0x1508 ),
    DEFINE_SUPPORT_CMD(HCI_Accept_Logical_Link,                 0x1510 ),
    DEFINE_SUPPORT_CMD(HCI_Disconnect_Logical_Link,             0x1520 ),
    DEFINE_SUPPORT_CMD(HCI_Logical_Link_Cancel,                 0x1540 ),
    DEFINE_SUPPORT_CMD(HCI_Flow_Spec_Modify,                    0x1580 ),
    DEFINE_SUPPORT_CMD(HCI_Set_Event_Mask,                      0x0520 ),
    DEFINE_SUPPORT_CMD(HCI_Reset_Pal,                           0x0580 ),
    DEFINE_SUPPORT_CMD(HCI_Read_Conn_Accept_Timeout,            0x0704 ),
    DEFINE_SUPPORT_CMD(HCI_Write_Conn_Accept_Timeout,           0x0708 ),
    DEFINE_SUPPORT_CMD(HCI_Read_Logical_Link_Accept_Timeout,    0x1601 ),
    DEFINE_SUPPORT_CMD(HCI_Write_Logical_Link_Accept_Timeout,   0x1602 ),
    DEFINE_SUPPORT_CMD(HCI_Enhanced_Flush,                      0x1340 ),
    DEFINE_SUPPORT_CMD(HCI_Read_Link_Supervision_Timeout,       0x0B01 ),
    DEFINE_SUPPORT_CMD(HCI_Write_Link_Supervision_Timeout,      0x0B02 ),
    DEFINE_SUPPORT_CMD(HCI_Read_Location_Data,                  0x1608 ),
    DEFINE_SUPPORT_CMD(HCI_Write_Location_Data,                 0x1610 ),
    DEFINE_SUPPORT_CMD(HCI_Set_Event_Mask_Page_2,               0x1604 ),
    DEFINE_SUPPORT_CMD(HCI_Read_Flow_Control_Mode,              0x1701 ),
    DEFINE_SUPPORT_CMD(HCI_Write_Flow_Control_Mode,             0x1702 ),
    DEFINE_SUPPORT_CMD(HCI_Write_BE_Flush_Timeout,              0x1808 ),
    DEFINE_SUPPORT_CMD(HCI_Read_BE_Flush_Timeout,               0x1804 ),
    DEFINE_SUPPORT_CMD(HCI_Short_Range_Mode,                    0x1810 ),
    DEFINE_SUPPORT_CMD(HCI_Read_Local_Ver_Info,                 0x0E08 ),
    //DEFINE_SUPPORT_CMD(HCI_Read_Local_Supported_Cmds,         0x     ),  // not shown in spec
    DEFINE_SUPPORT_CMD(HCI_Read_Data_Block_Size,                0x1704 ),
    DEFINE_SUPPORT_CMD(HCI_Read_Failed_Contact_Counter,         0x0F04 ),
    DEFINE_SUPPORT_CMD(HCI_Reset_Failed_Contact_Counter,        0x0F08 ),
    DEFINE_SUPPORT_CMD(HCI_Read_Link_Quality,                   0x0F10 ),
    DEFINE_SUPPORT_CMD(HCI_Read_RSSI,                           0x0F20 ),
    DEFINE_SUPPORT_CMD(HCI_Read_Local_AMP_Info,                 0x1620 ),
    DEFINE_SUPPORT_CMD(HCI_Read_Local_AMP_ASSOC,                0x1640 ),
    DEFINE_SUPPORT_CMD(HCI_Write_Remote_AMP_ASSOC,              0x1680 ), 
};

EVENT_CODE_TBL  evt_tbl[] = {
    {PAL_COMMAND_COMPLETE_EVENT,              "COMMAND_COMPLETE_EVENT"},
    {PAL_COMMAND_STATUS_EVENT,                "COMMAND_STATUS_EVENT"},
    {PAL_HARDWARE_ERROR_EVENT,                "HARDWARE_ERROR_EVENT"},
    {PAL_FLUSH_OCCURRED_EVENT,                "FLUSH_OCCURRED_EVENT"},
    {PAL_NUM_COMPL_PACKET_EVENT,              "NUM_COMPL_PACKET_EVENT"},
    {PAL_LOOPBACK_EVENT,                      "LOOPBACK_EVENT"},
    {PAL_BUFFER_OVERFLOW_EVENT,               "BUFFER_OVERFLOW_EVENT"},
    {PAL_QOS_VIOLATION_EVENT,                 "QOS_VIOLATION_EVENT"},
    {PAL_CHANNEL_SELECT_EVENT,                "CHANNEL_SELECT_EVENT"},
    {PAL_PHYSICAL_LINK_COMPL_EVENT,           "PAL_PHYSICAL_LINK_COMPL_EVENT"},
    {PAL_LOGICAL_LINK_COMPL_EVENT,            "PAL_LOGICAL_LINK_COMPL_EVENT"},
    {PAL_DISCONNECT_LOGICAL_LINK_COMPL_EVENT, "PAL_DISCONNECT_LOGICAL_LINK_COMPL_EVENT"},
    {PAL_DISCONNECT_PHYSICAL_LINK_EVENT,      "DISCONNECT_PHYSICAL_LINK_EVENT"},
    {PAL_FLOW_SPEC_MODIFY_COMPL_EVENT,        "FLOW_SPEC_MODIFY_COMPL_EVENT"},
    {PAL_NUM_COMPL_DATA_BLOCK_EVENT,          "NUM_COMPL_DATA_BLOCK_EVENT"},
    {PAL_SHORT_RANGE_MODE_CHANGE_COMPL_EVENT, "PAL_SHORT_RANGE_MODE_CHANGE_COMPL_EVENT"},
    {PAL_ENHANCED_FLUSH_COMPLT_EVENT,         "PAL_ENHANCED_FLUSH_COMPLT_EVENT"},
    {PAL_PHY_LINK_EARLY_LOSS_WARNING_EVENT,   "PHY_LINK_EARLY_LOSS_WARNING_EVENT"},
    {PAL_PHY_LINK_RECOVERY_EVENT,             "PHY_LINK_RECOVERY_EVENT"},
    {PAL_AMP_STATUS_CHANGE_EVENT,             "AMP_STATUS_CHANGE_EVENT"}
};

static A_UINT8  get_tbl_hdl(A_UINT16 opcode, OCF_CMD_TBL **hdl);
 

A_UINT8
get_tbl_hdl(A_UINT16 opcode, OCF_CMD_TBL **hdl)
{
    A_UINT16 i, entries;

    *hdl = NULL;
    entries = N(cmd_tbl);

    for (i = 0; i < entries; i++) {
        if (cmd_tbl[i].cmdid == opcode) {
            *hdl = &(cmd_tbl[i]);
            break;
        }
    }
    
    return (hdl != NULL);
}



A_UINT32
pal_process_hci_cmd(AMP_DEV *Dev, A_UINT8 *buf, A_UINT16 sz)
{
    HCI_CMD_PKT *pkt = (HCI_CMD_PKT *)buf;
    OCF_CMD_TBL *row;

    PAL_PRINT(("PAL recv HCI cmd ->\n"));

#if DBG
    dump_frame(buf, sz);
#else
    UNUSED(sz);
#endif

    /* Validate the opcode */
    get_tbl_hdl(pkt->opcode, &row);

    if (row == NULL) {
        PAL_PRINT(("PAL Gets Unrecognized HCI command, sz = %d \n", sz));
        pal_cmd_status_evt(Dev, *((A_UINT16*)buf), HCI_ERR_UNKNOW_CMD);
        return PAL_HCI_CMD_IGNORED;
    } 

    /* Dispatch the cmd */
    if ((row)->fn) {
        PAL_PRINT(("PAL Gets HCI cmd (%s)->\n", (row)->strCmd));
        (row)->fn(Dev, (void *)pkt, NULL);
    }

    return  PAL_HCI_CMD_PROCESSED;
}



//MTsai - 
//------------------------------------------------------------------------------------
//Should recalculate the bandwidth allocation here, or do it when we receive create
//logic link command
//------------------------------------------------------------------------------------
static A_UINT32 
supervision_timeout_handler(AMP_DEV *dev, AMP_ASSOC_INFO *amp)
{
    A_UINT16 id, i;
    LLID_INFO *link;

    UNUSED(dev);
      
     if (amp->phy_link_state == CONNECTED_STATE) {
    
         /* Iterate thru all the LL's and disconnect them */
          for (i = 0; i < MAX_FLOW_SPECS_PER_PHY_LINK; i++) {
                id = PAL_CREATE_LLID_FROM_PHYHDL(amp->phy_link_hdl, i);
                find_logical_link_info(amp, id, &link);
                if (link) {
                    free_logical_link(amp, id);
                    pal_disconnect_logical_link_compl_evt(dev, HCI_SUCCESS, id, REASON_CONN_TIMEOUT);
                }
          }

    }
    /* Disconnect the phy link too */
    pal_disconnect_phy_link_compl_evt(dev, HCI_SUCCESS, amp->phy_link_hdl, REASON_CONN_TIMEOUT);
    
    return HCI_SUCCESS;
}


void
pal_decode_event(A_UINT8 *buf, A_UINT16 sz)
{
#if DBG
    A_UINT8 i;

    for (i = 0; i < N(evt_tbl); i++) {
        if (evt_tbl[i].event_code == ((HCI_EVENT_PKT *)buf)->event_code) {
            if (evt_tbl[i].event_code == PAL_NUM_COMPL_DATA_BLOCK_EVENT) {
                PAL_PRINT_DATA(("PAL Send event -> %s\n", evt_tbl[i].evt_name));
            } else {
                PAL_PRINT(("PAL Send event -> %s\n", evt_tbl[i].evt_name));
            }
            dump_frame(buf, sz);
            
            break;
        }    
    }

    /* Log an error message if reached the end of the table without finding event. */
    if (i >= N(evt_tbl)) {
        PAL_PRINT(("Event %d not recognized\n", ((HCI_EVENT_PKT *)buf)->event_code));
    }
    
#else
    UNUSED(buf);
    UNUSED(sz);
#endif

}

static A_UINT32
hci_nop(AMP_DEV *dev, void *cmd, void *buf)
{
    UNUSED(dev);
    UNUSED(cmd);
    UNUSED(buf);

    PAL_PRINT(("CMD NOP\n"));
    return 0;
}


static A_UINT32
hci_reset(AMP_DEV *Dev, void *cmd, void *buf)
{
    A_UINT8 status, i;
    AMP_ASSOC_INFO *r_amp;
    HCI_CMD_HEAD *pCmd = (HCI_CMD_HEAD*)cmd;

    UNUSED(buf);
    PAL_PRINT(("CMD HCI Reset\n"));
    /*
     * Come back to init state. 
     * Drop all logical links/phy links. Reset AMP Db
     * Stop beaconing(if ssid set), re-initialise wlan, if connected
     * Init local AMP Assoc, and such things.
     */

    if (pCmd->param_length != 0) {
        pal_cmd_status_evt(Dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS;
    }

    //First remove all HCI links
    /* Look for link that is not in IDLE state and send disconnected to PAL SM*/
    for (i = 0; i < NUM_OF_AMP_ASSOC_INFO; i++) {
 
         r_amp = &(Dev->rem_assoc_amp[i]);
         if ((r_amp->phy_link_state != DISCONNECTED_STATE) ||
             (r_amp->phy_link_action_state != PAL_WAIT_PHYSICAL_CREATION))
         {
              PAL_PRINT(("Force Reset Disconnect Operation of PAL physical link, Hdl(%d)\n", r_amp->phy_link_hdl));
              /* As if host is asking for us to disconnect the link */
              Pal_Physical_Link_Thread(r_amp, EVENT_DISCONECT_PHYSICAL_LINK, NULL, 0);
              //Set DEV state as RESET in progress
              //3 things will happen with this is flag,
              //1 - Physical link Disconnect complete event shall not be sent to host
              //2 - After beacon stopped, PAL will send command completed event to host
              Dev->ResetInProcess = true;
         }
    }

   // PAL_POSH_API->Reset(Dev, NULL); //Force a MP reset
                                      //This shall cause all links lost
 
    status = HCI_SUCCESS;

    if (Dev->ResetInProcess == false) //Only send this event out if we are not going through RESET
        pal_cmd_compl_evt(Dev, ((HCI_CMD_PKT *)cmd)->opcode, &status, sizeof(status));

    return(HCI_SUCCESS);
}


static A_UINT32
hci_set_event_mask(AMP_DEV *dev, void *cmd, void *buf)
{
    A_UINT8 status;
    HCI_CMD_SET_EVT_MASK *pCmd = (HCI_CMD_SET_EVT_MASK *)cmd;
    A_UINT8 index = 0;

    UNUSED(dev);
    UNUSED(buf);

    if (pCmd->param_length != sizeof(A_UINT64)) {
        pal_cmd_status_evt(dev, pCmd->opcode,HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_SUCCESS;
    }

    if (pCmd->opcode == HCI_Set_Event_Mask) {
        PAL_PRINT(("CMD HCI Set Event Mask\n"));
        index = 0;
    } else {
        PAL_PRINT(("CMD HCI Set Event Mask Page 2\n"));
        index = 1;
    }

    pal_evt_set_evt_mask(dev, index, pCmd->mask);

    status = HCI_SUCCESS;
    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode, 
                                &status, sizeof(status));
    return HCI_SUCCESS;
}


static A_UINT32 
hci_read_xyz_timeout(AMP_DEV *dev, void *cmd, void *buf)
{
    TIMEOUT_INFO    info;
    PAL_CFG *pCfg = &dev->pal_cfg;
    HCI_CMD_HEAD *pCmd = (HCI_CMD_HEAD *)cmd;

    UNUSED(buf);

    if (pCmd->param_length != 0 ) {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS;
    }

    info.status = HCI_SUCCESS;
    if (pCmd->opcode == HCI_Read_Conn_Accept_Timeout)
        info.timeout = pCfg->conn_accept_timeout;

    if (pCmd->opcode == HCI_Read_Logical_Link_Accept_Timeout)
        info.timeout = pCfg->logical_link_accept_timeout;

    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode, 
                                (A_UINT8 *)&info, sizeof(info));
    return  HCI_SUCCESS;
}

static A_UINT32 
hci_write_xyz_timeout(AMP_DEV *dev, void *cmd, void *buf)
{
    PAL_CFG *pCfg = &dev->pal_cfg;
    HCI_CMD_WRITE_TIMEOUT *pCmd = (HCI_CMD_WRITE_TIMEOUT *)cmd;
    A_UINT8 ret;

    UNUSED(buf);
    if (pCmd->param_length != sizeof(A_UINT16)) {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS;
    }

    if (pCmd->opcode == HCI_Write_Conn_Accept_Timeout)
        pCfg->conn_accept_timeout = pCmd->timeout;

    if (pCmd->opcode == HCI_Write_Logical_Link_Accept_Timeout)
        pCfg->logical_link_accept_timeout = pCmd->timeout;

    ret = HCI_SUCCESS;

    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode, 
                                (A_UINT8 *)&ret, sizeof(ret));
    return  HCI_SUCCESS;
}

static void flush_cmp_timeout(void* contex)
{
    AMP_DEV* Dev = (AMP_DEV* )contex;
    pal_enhanced_flush_complete_event(Dev, Dev->flush_llc);
}

static A_UINT32
hci_enhanced_flush(AMP_DEV *dev, void *cmd, void *buf)
{
    HCI_CMD_ENHANCED_FLUSH *pCmd = (HCI_CMD_ENHANCED_FLUSH*)cmd;
    AMP_ASSOC_INFO *amp;
    LLID_INFO      *llid;
    A_UINT16        id;
    
   UNUSED(buf);

    if (pCmd->param_length != 3) {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS;
    }

    id = pCmd->hdl;
    get_remote_assoc_amp(dev, PAL_GET_PHY_HDL_FROM_LLID(id), &amp);

    if (amp == NULL) {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS; 
    }

    find_logical_link_info(amp, id, &llid);

    if (llid == NULL) {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS; 
    }

    if (!pCmd->type) {
        // only type = 0 valid
        dev->flush_llc = llid->logical_link_id;
        pal_tx_queue_enhanced_flush(&(dev->pal_tx_queue));
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_SUCCESS);
        dev->FlushCmpTimer.timer_type = EVENT_FLUSH_CMP_TIMEOUT;
        pal_settimer(dev, FLUSH_COM_EVENT_TIMEOUT, flush_cmp_timeout, dev, &dev->FlushCmpTimer);
    } else {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_SUCCESS);
        pal_enhanced_flush_complete_event(dev, id);
    }    
    return HCI_SUCCESS;
}


static A_UINT32 
hci_read_link_supervision_timeout(AMP_DEV *dev, void *cmd, void *buf)
{
    AMP_ASSOC_INFO  *amp;
    LINK_SUPERVISION_TIMEOUT_INFO   info;
    HCI_CMD_READ_LINK_SUPERVISION_TIMEOUT *pCmd = (HCI_CMD_READ_LINK_SUPERVISION_TIMEOUT *)cmd;

    UNUSED(buf);

    info.hdl = pCmd->hdl & 0x0f;
    get_remote_assoc_amp(dev, info.hdl, &amp);

    if (amp) {
        info.timeout = amp->link_supervision_timeout;
        info.status = HCI_SUCCESS;
    } else {
        info.status = HCI_ERR_UNKNOWN_CONN_ID;
    }

    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode, 
                                (A_UINT8 *)&info, sizeof(info));

    return 0;
}


static A_UINT32 
hci_write_link_supervision_timeout(AMP_DEV *dev, void *cmd, void *buf)
{
    AMP_ASSOC_INFO  *amp;
    INFO_STATUS_HDL info;
    HCI_CMD_WRITE_LINK_SUPERVISION_TIMEOUT *pCmd = 
                        (HCI_CMD_WRITE_LINK_SUPERVISION_TIMEOUT *)cmd;

    UNUSED(dev);
    UNUSED(buf);

    info.hdl = pCmd->hdl & 0x0f;
    get_remote_assoc_amp(dev, info.hdl, &amp);

    if (amp) {
        info.status = HCI_SUCCESS;
        amp->link_supervision_timeout = pCmd->timeout;
    } else {
        info.status = HCI_ERR_UNKNOWN_CONN_ID;
    }

    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode, 
                                (A_UINT8 *)&info, sizeof(info));

    return 0;
}


static A_UINT32 
hci_write_location_data(AMP_DEV *dev, void *cmd, void *buf)
{
    HCI_CMD_WRITE_LOCATION_DATA *pCmd = (HCI_CMD_WRITE_LOCATION_DATA *)cmd;
    PAL_CFG *pCfg = &dev->pal_cfg;
    A_UINT8 status;

    UNUSED(buf);

    if (pCmd->param_length != sizeof(LOCATION_DATA_CFG)) {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS;
    }

     os_memcpy(&(pCfg->loc), &(pCmd->cfg), sizeof(pCmd->cfg));

    /* Can the status be an error, ever?, Perhaps when the location
     * data is not supported by PAL? or it fails when validated.. For ex
     * a situation where a country is unsupported by PAL but the 
     * location is being indicated as such.
     */
    status = HCI_SUCCESS;

    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode, 
                                &status, sizeof(status));
    return  HCI_SUCCESS;
}


static A_UINT32 
hci_read_location_data(AMP_DEV *dev, void *cmd, void *buf)
{
    READ_LOC_INFO   info;
    PAL_CFG *pCfg = &dev->pal_cfg;
    HCI_CMD_HEAD  *pCmd = (HCI_CMD_HEAD*)cmd;

    UNUSED(buf);

    if (pCmd->param_length != 0) {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS;
    }
    
    info.status = HCI_SUCCESS;
    os_memcpy(&(info.loc), &(pCfg->loc), sizeof(pCfg->loc));

    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode, 
                                (A_UINT8 *)&info, sizeof(info));
    return  HCI_SUCCESS;
}

static A_UINT32 
hci_read_flow_control_mode(AMP_DEV *dev, void *cmd, void *buf)
{
    PAL_CFG *pCfg = &dev->pal_cfg;
    READ_FLWCTRL_INFO   info;

    UNUSED(buf);

    info.status = HCI_SUCCESS;
    info.mode = pCfg->flow_control_mode;

    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode, 
                                (A_UINT8 *)&info, sizeof(info));
    return 0;
}


static A_UINT32 
hci_write_flow_control_mode(AMP_DEV *dev, void *cmd, void *buf)
{
    PAL_CFG *pCfg = &dev->pal_cfg;
    HCI_CMD_WRITE_FLOW_CONTROL *pCmd = (HCI_CMD_WRITE_FLOW_CONTROL *)cmd;
    A_UINT8 status = HCI_SUCCESS;

    UNUSED(buf);
    /* Validate the mode, otherwise set status to error */
    if ((pCmd->mode == PACKET_BASED_FLOW_CONTROL_MODE) ||
        (pCmd->mode == DATA_BLK_BASED_FLOW_CONTROL_MODE)) {
        pCfg->flow_control_mode = pCmd->mode;
        status = HCI_SUCCESS;
    } else {
        status = HCI_ERR_INVALID_HCI_CMD_PARAMS; /* Error indicating wrong flow control */
    }

    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode, 
                                &status, sizeof(status));
    return 0;
}


static A_UINT32
hci_write_be_flush_timeout(AMP_DEV *dev, void *cmd, void *buf)
{
    A_UINT8 status = HCI_SUCCESS;
    HCI_CMD_WRITE_BE_FLUSH *pCmd = (HCI_CMD_WRITE_BE_FLUSH *)cmd;
    AMP_ASSOC_INFO *amp;
    LLID_INFO      *llid;    
    A_UINT16        id;

    UNUSED(buf);

    if (pCmd->param_length != 6) {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS;
    }

    id = pCmd->hdl;
    get_remote_assoc_amp(dev, PAL_GET_PHY_HDL_FROM_LLID(id), &amp);

    if (amp == NULL) {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS; 
    }

    find_logical_link_info(amp, id, &llid);

    if (llid == NULL) {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS; 
    }

    llid->be_flush_tout = pCmd->tout;
    
    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode, 
                                &status, sizeof(status));
    return HCI_SUCCESS;
}


static A_UINT32
hci_read_be_flush_timeout(AMP_DEV *dev, void *cmd, void *buf)
{
    HCI_CMD_READ_BE_FLUSH *pCmd = (HCI_CMD_READ_BE_FLUSH *)cmd;
    AMP_ASSOC_INFO  *amp;
    BE_TIMEOUT_INFO  beToutInfo;
    LLID_INFO       *llid;    
    A_UINT16         id;

    UNUSED(buf);

    id = pCmd->hdl;
    get_remote_assoc_amp(dev, PAL_GET_PHY_HDL_FROM_LLID(id), &amp);

    if (amp == NULL) {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS; 
    }

    find_logical_link_info(amp, id, &llid);

    if (llid == NULL) {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS; 
    }

    beToutInfo.status  = HCI_SUCCESS;
    beToutInfo.timeout = llid->be_flush_tout;

    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode, 
                                (A_UINT8 *)&beToutInfo, sizeof(BE_TIMEOUT_INFO));

    return HCI_SUCCESS;
 }

/* SRM is implemented as per AMP HCI CR D09r02-knh03 */
static A_UINT32 
hci_short_range_mode(AMP_DEV *Dev, void *cmd, void *buf)
{
    HCI_CMD_SHORT_RANGE_MODE *pCmd = (HCI_CMD_SHORT_RANGE_MODE *)cmd;
    AMP_ASSOC_INFO *amp = NULL;
    A_UINT8 status = 1; 

    UNUSED(buf);

    PAL_PRINT(("CMD = HCI_Short_Range_Mode\n"));

    if (pCmd->param_length != 2) {
        pal_cmd_status_evt(Dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS;
    }
    
    /* The SRM is per link based. So this param is link hdl property */
    get_remote_assoc_amp(Dev, pCmd->phy_link_hdl, &amp);

    if (!amp) {
        pal_cmd_status_evt(Dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS;
    }

    pal_cmd_status_evt(Dev, pCmd->opcode, HCI_SUCCESS);

    /* What is the expected behavior for link being absent for this cmd? */
    if (amp) {
        amp->srm = pCmd->mode;
        /* Set the SR mode in hw - modify pwr limit */
        //driver_set_power(1);
        PAL_POSH_API->SetSRM(Dev, amp);
        status = HCI_SUCCESS;
    }

    pal_srm_change_compl_evt(Dev, status, pCmd->phy_link_hdl, pCmd->mode);
    return HCI_SUCCESS;
}


static A_UINT32
hci_read_local_amp_info(AMP_DEV *dev, void *cmd, void *buf)
{
    HCI_CMD_HEAD *pCmd = (HCI_CMD_HEAD*)cmd;
    A_UINT8       ParaLen = sizeof(LOCAL_AMP_INFO)-sizeof(LOCAL_VERSION_INFO)+1;
    UNUSED(buf);

    if (pCmd->param_length != 0) {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS;
    }

    PAL_PRINT(("CMD = HCI_Read_Local_AMP_Info, Len(%d)\n", ParaLen));
    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode,
                    (A_UINT8 *)&dev->pal_cfg.local_ampinfo, 
                    ParaLen);
   
    return HCI_SUCCESS;
}


static A_UINT32 
hci_read_local_ver_info(AMP_DEV *dev, void *cmd, void *buf)
{
    HCI_CMD_HEAD *pCmd = (HCI_CMD_HEAD*)cmd;
    LOCAL_VERSION_INFO local_ver;

    UNUSED(buf);

    PAL_PRINT(("CMD = HCI_Read_Local_AMP_Version\n"));

    if (pCmd->param_length != 0) {
        pal_cmd_status_evt(dev, pCmd->opcode,HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS;
    }

    local_ver.status = HCI_SUCCESS;
    local_ver.hci_version = dev->pal_cfg.local_ampinfo.hci_version;  // TODO look up sig spec 
    local_ver.hci_revision = dev->pal_cfg.local_ampinfo.hci_revision; // TODO look up sig spec
    local_ver.pal_version = dev->pal_cfg.local_ampinfo.pal_ver;
    local_ver.sig_company_name[0] = dev->pal_cfg.local_ampinfo.pal_sig_name&0xFF;
    local_ver.sig_company_name[1] = dev->pal_cfg.local_ampinfo.pal_sig_name>>8;
    local_ver.pal_subversion = dev->pal_cfg.local_ampinfo.pal_sub_ver;
    
    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode,
                     (A_UINT8*)&local_ver,
                     sizeof(local_ver));
    return HCI_SUCCESS;
}


static A_UINT32 
hci_read_local_supported_cmds(AMP_DEV *dev, void *cmd, void *buf)
{
    HCI_CMD_HEAD *pCmd = (HCI_CMD_HEAD*)cmd;
    A_UINT8 param[65];
    A_UINT8 *support_cmd = param+1; //Leave 1 byte for status
    A_UINT8 num;
    A_UINT8 i;
    
    UNUSED(buf);
    UNUSED(dev);

    if (pCmd->param_length != 0) {
        pal_cmd_status_evt(dev, pCmd->opcode,HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS;
    }

    /* spec: The supported commands is a 64 octet bit filed.
             actually, 24 octet defined.
    */
    os_memset(param, 0, sizeof(param));

    num = N(amp_support);

    for (i=0; i<num; i++) {
        support_cmd[((amp_support[i].bit_pos>>8)&0xFF)] |= (amp_support[i].bit_pos & 0xFF);
    }

    pal_cmd_compl_evt(dev, pCmd->opcode, param, sizeof(param));
    
    return HCI_SUCCESS;
}


static A_UINT32 
hci_read_data_block_size(AMP_DEV *dev, void *cmd, void *buf)
{
    
    READ_DATA_BLK_SIZE_INFO info;
    HCI_CMD_HEAD *pCmd = (HCI_CMD_HEAD*)cmd;

    UNUSED(buf);
    UNUSED(dev);

    if (pCmd->param_length != 0) {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS;
    }

    info.status = HCI_SUCCESS;
    /* These params must be acquired from some config. From pal_cfg?
     * For now hardcode them.
     */
    info.max_acl_data_pkt_len = Max80211_PAL_PDU_Size;   
    info.data_block_len = Max80211_PAL_PDU_Size;
    info.total_num_data_blks = NUMBER_OF_PACKET_AVAILABLE; //TxWin=63

    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode,
                        (A_UINT8 *)&info, sizeof(info));

    return HCI_SUCCESS;
}



/* We don't support reading of assoc in chunks. All of it 
 * will be read and passed in one shot - for now
 */
static A_UINT32
hci_read_local_amp_assoc(AMP_DEV *Dev, void *cmd, void *buf)
{
    HCI_CMD_READ_LOCAL_AMP_ASSOC *pCmd = (HCI_CMD_READ_LOCAL_AMP_ASSOC *)cmd;
    AMP_ASSOC_INFO *amp = NULL;
    AMP_ASSOC_CMD_RESP resp;
    A_UINT8 reg[AMP_ASSOC_MAX_FRAG_SZ], sz;

    UNUSED(buf);

    PAL_PRINT(("CMD = HCI_Read_Local_AMP_ASSOC\n"));
    PAL_PRINT(("len so far = 0x%x - ignored for now\n", pCmd->len_so_far));
    PAL_PRINT(("Phy Link hdl = %d\n", pCmd->phy_link_hdl));

    ASSERT(pCmd->len_so_far == 0); //We do not have fragment assoc, actually
    resp.phy_hdl = pCmd->phy_link_hdl;

    if (pCmd->phy_link_hdl) { //We have a physical link
    
       get_remote_assoc_amp(Dev, pCmd->phy_link_hdl, &amp);

      /* If remote AMP is absent, status would be not ok. But such will
       * be the case with a tester generally, and not our stack.
       * Adding all kinds of error check is burdensome on PAL code size..
       */
       if (amp) {
          A_UINT8 *cur;
          A_UINT32 palcap = 0x1;
          A_UINT8  ver[7];

          resp.status = HCI_SUCCESS;    /* Status ok */

           /* Build the AMP_Assoc. If the phy handle is non zero, then
            * the AMP_ASSOC would be:
            * LOCAL_MAC_ADDR(TLV) and channel selected(TLV).
            * There would be only one channel - since channel select
            * would have been performed. It's not illegal to do 
            * read_local_amp_assoc before channel select with remote
            * phy link but it does not make sense.
            */

            sz = 0;
            os_memcpy(reg, Dev->CountryCode, 3);
            sz += 3;
            if (amp->channel_selected.regClassId != 0) {
                reg[sz++] = IEEE80211_REG_EXT_ID;
                reg[sz++] = amp->channel_selected.regClassId;
                reg[sz++] = 0;
            }

            if (amp->channel_selected.ieee == 0)
                PAL_PRINT(("It should not happen. The select channel is 0\n"));

            reg[sz++] = amp->channel_selected.ieee;
            reg[sz++] = 1;
            reg[sz++] = 0;

            cur = resp.amp_assoc_frag;
            cur = append_tlv(cur, AMP_ASSOC_MAC_ADDRESS_INFO_TYPE, MAC_ADDR_LEN, Dev->hwaddr);
            cur = append_tlv(cur, AMP_ASSOC_PREF_CHAN_LIST, sz, reg);
           
            os_memcpy(ver, &Dev->pal_cfg.local_ampinfo.pal_ver, sizeof(A_UINT8));
            os_memcpy(ver+1,&Dev->pal_cfg.local_ampinfo.pal_sig_name, sizeof(A_UINT16));
            os_memcpy(ver+3,&Dev->pal_cfg.local_ampinfo.pal_sub_ver, sizeof(A_UINT16));
            cur = append_tlv(cur, AMP_ASSOC_PAL_VERSION, 5, ver);
            cur = append_tlv(cur, AMP_ASSOC_PAL_CAPABILITIES, 4 , (A_UINT8 *)&palcap);
            resp.amp_assoc_len = (A_UINT16)(cur - resp.amp_assoc_frag);
         } //if amp
         else {
         PAL_PRINT(("Phy hdl 0x%x absent\n", pCmd->phy_link_hdl));
         resp.status = HCI_ERR_UNKNOWN_CONN_ID;  /* Status not ok - Didn't find AMP for phy link*/
         resp.amp_assoc_len = 0;
         }
        }//if pCmd->phy_link_hdl
    else
    {
       PAL_POSH_API->QueryChannelInfo(Dev, NULL);
       resp.status = HCI_SUCCESS;
       resp.amp_assoc_len = Dev->pal_cfg.local_ampassoc->assoc_len;
       os_memcpy(resp.amp_assoc_frag, Dev->pal_cfg.local_ampassoc->amp_assoc, resp.amp_assoc_len);
    }

     pal_cmd_compl_evt(Dev, ((HCI_CMD_PKT *)cmd)->opcode, 
                         (A_UINT8 *)&resp, 
                         (A_UINT8)(sizeof(resp.status) + sizeof(resp.phy_hdl)+sizeof(resp.amp_assoc_len) + resp.amp_assoc_len)); 

     return HCI_SUCCESS;
}

static A_UINT32
hci_read_failed_contact_counter(AMP_DEV *dev, void *cmd, void *buf)
{
HCI_CMD_READ_FAILED_CNT *pCmd = (HCI_CMD_READ_FAILED_CNT *)cmd;
AMP_ASSOC_INFO     *amp = NULL;
FAILED_COUNT_INFO  Failed_Counter_Info;
LLID_INFO          *llid = NULL;    
A_UINT16           id;

    UNUSED(buf);

    id = pCmd->hdl;
    Failed_Counter_Info.hdl = id;
    Failed_Counter_Info.status = HCI_SUCCESS;

    get_remote_assoc_amp(dev, PAL_GET_PHY_HDL_FROM_LLID(id), &amp);

    if (amp == NULL) {
        Failed_Counter_Info.status = HCI_ERR_UNKNOWN_CONN_ID;
    }

    if (amp != NULL)
    {
    find_logical_link_info(amp, id, &llid);

      if (llid == NULL) {
          Failed_Counter_Info.status = HCI_ERR_UNKNOWN_CONN_ID;
      }
    }

    if (llid)
    {
      Failed_Counter_Info.failedCnt = llid->failedContactCounter;
    }

    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode, 
                                (A_UINT8 *)&Failed_Counter_Info, sizeof(FAILED_COUNT_INFO));

    return HCI_SUCCESS;

}

static A_UINT32 
hci_reset_failed_contact_counter(AMP_DEV *dev, void *cmd, void *buf)
{
HCI_CMD_READ_FAILED_CNT *pCmd = (HCI_CMD_READ_FAILED_CNT *)cmd;
AMP_ASSOC_INFO     *amp = NULL;
FAILED_COUNT_INFO  Failed_Counter_Info;
LLID_INFO          *llid = NULL;    
A_UINT16           id;

    UNUSED(buf);

    id = pCmd->hdl;
    Failed_Counter_Info.hdl = id;
    Failed_Counter_Info.status = HCI_SUCCESS;

    get_remote_assoc_amp(dev, PAL_GET_PHY_HDL_FROM_LLID(id), &amp);

    if (amp == NULL) {
        Failed_Counter_Info.status = HCI_ERR_UNKNOWN_CONN_ID;
    }

    if (amp != NULL)
    {
    find_logical_link_info(amp, id, &llid);

      if (llid == NULL) {
          Failed_Counter_Info.status = HCI_ERR_UNKNOWN_CONN_ID;
      }
    }

    if (llid)
    {
      llid->failedContactCounter = 0;
    }

    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode, 
                                (A_UINT8 *)&Failed_Counter_Info, 3);

    return HCI_SUCCESS;
}

static A_UINT32
hci_read_rssi(AMP_DEV *dev, void *cmd, void *buf)
{
HCI_CMD_READ_FAILED_CNT *pCmd = (HCI_CMD_READ_FAILED_CNT *)cmd; //Same command parameters as read failed count
AMP_ASSOC_INFO     *amp = NULL;
LINK_RSSI_INFO     Rssi_Info;
A_UINT16           id;

    UNUSED(buf);

    id = pCmd->hdl & 0x0F; //Physical Link ID

    get_remote_assoc_amp(dev, id, &amp);

    if (amp == NULL) {
        Rssi_Info.status = HCI_ERR_UNKNOWN_CONN_ID;
    }

    if (amp != NULL)
    {
      Rssi_Info.status = HCI_SUCCESS;
      Rssi_Info.hdl = id;
      Rssi_Info.rssi = 20;
    }

    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode, 
                                (A_UINT8 *)&Rssi_Info, sizeof(LINK_RSSI_INFO));

    return HCI_SUCCESS;
}



static A_UINT32    
hci_write_remote_amp_assoc(AMP_DEV *dev, void *cmd, void *buf)
{
    HCI_CMD_WRITE_REM_AMP_ASSOC *pCmd = (HCI_CMD_WRITE_REM_AMP_ASSOC *)cmd;
    AMP_ASSOC_INFO *amp;
    A_UINT16 len;
    WRITE_REMOTE_AMP_ASSOC_INFO info;
    A_UINT8 *cur;
  
    UNUSED(buf);
    UNUSED(dev);

    info.hdl = pCmd->phy_link_hdl;  /* Phy link handle */

    PAL_PRINT(("CMD = HCI_Write_Remote_AMP_ASSOC\n"));
    PAL_PRINT(("Phy link hdl = 0x%x\n", pCmd->phy_link_hdl));
    get_remote_assoc_amp(dev, pCmd->phy_link_hdl, &amp);
    if (amp == NULL) {
        PAL_PRINT(("Err - Phy link Hdl not present \n"));
        info.status = HCI_ERR_UNKNOWN_CONN_ID;
        pal_cmd_compl_evt(dev, pCmd->opcode, (A_UINT8 *)&info, sizeof(info));
        return 1;
    }

    len = pCmd->amp_assoc_remaining_len;

    if (len > AMP_ASSOC_LEN) {
        PAL_PRINT(("Err - AMP Assoc len is larger than AMP_ASSOC_LEN \n"));
        info.status = HCI_ERR_INVALID_HCI_CMD_PARAMS;
        pal_cmd_compl_evt(dev, pCmd->opcode, (A_UINT8 *)&info, sizeof(info));
        return 1;
    }

    if (len > AMP_ASSOC_MAX_FRAG_SZ) {
        len = AMP_ASSOC_MAX_FRAG_SZ;
    }

    os_memcpy(&amp->amp_assoc[pCmd->len_so_far], pCmd->amp_assoc_frag, len);

    amp->assoc_len = pCmd->len_so_far + pCmd->amp_assoc_remaining_len;
    PAL_PRINT(("amp assoc len = %d\n", amp->assoc_len));

    info.status = HCI_SUCCESS;
    /* Only after the last segment is written to PAL */
    if (pCmd->amp_assoc_remaining_len <= AMP_ASSOC_LEN) {
        parse_amp_assoc(amp->amp_assoc, AMP_ASSOC_MAC_ADDRESS_INFO_TYPE, &cur, amp->assoc_len);
        if (cur && cur[1] != MAC_ADDR_LEN) {
            info.status = HCI_ERR_INVALID_HCI_CMD_PARAMS;
        } else if (!cur) {
            info.status = HCI_ERR_INVALID_HCI_CMD_PARAMS;
        }

        pal_cmd_compl_evt(dev, pCmd->opcode, (A_UINT8 *)&info, sizeof(info));

        if (info.status != HCI_SUCCESS) {
            PAL_PRINT(("Failed to get AMP_ASSOC_MAC_ADDRESS_INFO_TYPE\n"));
            return 0;
        }

        parse_amp_assoc(amp->amp_assoc, AMP_ASSOC_MAC_ADDRESS_INFO_TYPE, &amp->hwaddr, amp->assoc_len);
        amp->hwaddr += 3;
        Pal_Physical_Link_Thread(amp, EVENT_WRITE_REMOTE_AMP_ASSOC, NULL, 0);   
        
    } else {
        info.status = HCI_ERR_INVALID_HCI_CMD_PARAMS;
        pal_cmd_compl_evt(dev, pCmd->opcode, (A_UINT8 *)&info, sizeof(info));
    }

    return 0;
}


static A_UINT32    
hci_read_link_quality(AMP_DEV *dev, void *cmd, void *buf)
{
    HCI_CMD_READ_LINK_QUAL *pCmd = (HCI_CMD_READ_LINK_QUAL *)cmd;
    AMP_ASSOC_INFO *amp;
    READ_LINK_QUAL_INFO info;

    UNUSED(buf);
    UNUSED(dev);

    PAL_PRINT(("CMD = HCI_Read_Link_Quality\n"));
    PAL_PRINT(("Phy link hdl = 0x%x\n", pCmd->hdl));

    /* When do we fail reading link quality event? Perhaps when PAL is
     * not inited?...Later..
     */
    info.status = HCI_SUCCESS;
    info.hdl = pCmd->hdl & 0x0F;

    get_remote_assoc_amp(dev, info.hdl, &amp);
    
    /* Link quality should be acquired from driver. For now,
     * the presence of physical link means good link
     * Physical link is valid only after channel has been selected
     * and link has been established. For now, channel selected
     * is a good indication.(MAC 802.11 exchange cld be pending
     * for a brief window)
     */
    info.link_qual = (amp && amp->channel_selected.ieee) ? 0xBB : 0;

    pal_cmd_compl_evt(dev, ((HCI_CMD_PKT *)cmd)->opcode, 
                                (A_UINT8 *)&info, sizeof(info));

    return 0;
}

static A_UINT32    
hci_create_physical_link(AMP_DEV *dev, void *cmd, void *buf)
{
    HCI_CMD_PHY_LINK *pCmd = (HCI_CMD_PHY_LINK *)cmd;
    AMP_ASSOC_INFO *amp;

    UNUSED(buf);

    if (pCmd->opcode == HCI_Create_Physical_Link) {
        PAL_PRINT(("CMD = HCI_Create_Physical_Link\n"));
    } else {
        PAL_PRINT(("CMD = HCI_Accept_Physical_Link\n"));
    }

    //Refuse to create physical link if AMP radio is down
    if (dev->pal_cfg.local_ampinfo.amp_status  == AMP_RF_POWER_DOWN)
    {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_COMMAND_DISALLOWED);
        return 0;
    }

    PAL_PRINT(("Phy link hdl = %d\n", pCmd->phy_link_hdl));

    get_remote_assoc_amp(dev, pCmd->phy_link_hdl, &amp);

    if (amp == NULL) { //New MAC address, allocate one slot for it
        alloc_rem_assoc_amp(dev, pCmd->phy_link_hdl, &amp);
        if (amp == NULL) //exceed our max here
        {
        PAL_PRINT(("Max number of Link Exceeded, Reject \n"));
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_CON_LIMIT_EXECED);
        return(0);
        }
    }
    else //reject this physical link command from AMP manager
    {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_ACL_CONN_ALRDY_EXISTS);
        return(0);
    }

    if (pCmd->opcode == HCI_Create_Physical_Link) {
        amp->connection_side = AMP_CONNECTION_ORIGINATOR;   
    } else {
        amp->connection_side = AMP_CONNECTION_TERMINATOR;
    }

    OS_assert(pCmd->link_key_len == LINK_KEY_LEN);
    amp->sec_record.link_key_len = pCmd->link_key_len;
    amp->sec_record.link_key_type = pCmd->link_key_type;
    os_memcpy(amp->sec_record.link_key, pCmd->link_key, pCmd->link_key_len);

    pal_cmd_status_evt(dev, pCmd->opcode, HCI_SUCCESS);

    if (pCmd->opcode == HCI_Create_Physical_Link) {
        Pal_Physical_Link_Thread(amp, EVENT_CREATE_PHYSICAL_LINK, NULL, 0); 
    } else {
        Pal_Physical_Link_Thread(amp, EVENT_ACCEPT_PHYSICAL_LINK, NULL, 0); 
    }

    return 0;
}




static A_UINT32    
hci_create_logical_link(AMP_DEV *dev, void *cmd, void *buf)
{
    HCI_CMD_CREATE_LOGICAL_LINK *pCmd = (HCI_CMD_CREATE_LOGICAL_LINK *)cmd;
    AMP_ASSOC_INFO *amp;
    A_UINT16 id = 0;
    FLOW_SPEC *tx, *rx;
    A_UINT32 bw_req;
    PAL_CFG   *pCfg = &dev->pal_cfg;
    
    UNUSED(buf);
    UNUSED(dev);

    if (pCmd->opcode == HCI_Create_Logical_Link) {
    PAL_PRINT(("CMD = HCI_Create_Logical_Link\n"));
    } else {
        PAL_PRINT(("CMD = HCI_Accept_Logical_Link\n"));
    }

    PAL_PRINT(("Phy link hdl = 0x%02x\n", pCmd->phy_link_hdl));

    get_remote_assoc_amp(dev, pCmd->phy_link_hdl, &amp);

    if (amp == NULL) {
        PAL_PRINT(("AMP not populated for this phy hdl\n"));
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_UNKNOWN_CONN_ID);
        return HCI_ERR_UNKNOWN_CONN_ID;
    }

    if (amp->phy_link_state != CONNECTED_STATE) {
        PAL_PRINT(("Phy link %d not connected. Logic link creation failed\n", pCmd->phy_link_hdl));
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_COMMAND_DISALLOWED);
        return HCI_ERR_COMMAND_DISALLOWED;
    }

    tx = &pCmd->tx_flow_spec;
    if (tx->service_type == SERVICE_TYPE_GUARANTEED) {
        /* sdu_int_arrival is in us. Compute BW in KB(instead of MB) */
        if (tx->sdu_inter_arrival_time != 0xFFFFFFFF) {
            bw_req = (tx->max_sdu * 1000 * 8 ) /tx->sdu_inter_arrival_time;  
        } else {
            bw_req = 0;
        }
        if (bw_req > pCfg->local_ampinfo.max_guranteed_bw) {
            PAL_PRINT(("BW exceeded. Req = %dM\n", bw_req));
            pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_QOS_REJECTED);
            return HCI_ERR_QOS_REJECTED;
        }
    }

    rx = &pCmd->rx_flow_spec;

    if   ((tx->service_type == SERVICE_TYPE_BEST_EFFORT) &&
          (rx->service_type == SERVICE_TYPE_GUARANTEED))
    {
            pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_QOS_REJECTED);
            return HCI_ERR_QOS_REJECTED;
    }

    if   ((rx->service_type == SERVICE_TYPE_BEST_EFFORT) &&
          (tx->service_type == SERVICE_TYPE_GUARANTEED))
    {
            pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_QOS_REJECTED);
            return HCI_ERR_QOS_REJECTED;
    }
    
    //todo, if tx_service_type == SERVICE_TYPE_GUARANTEED or rx_service_type == SERVICE_TYPE_GUARANTEED
    //check if we have enough bandwidth for it
    
    pal_cmd_status_evt(dev, pCmd->opcode, HCI_SUCCESS);

    id = generate_logical_link(amp, tx, &pCmd->rx_flow_spec);
    PAL_PRINT(("Logical id = 0x%x, service type = 0x%x\n", id, tx->service_type));
    pal_logical_link_compl_evt(dev, HCI_SUCCESS, id, pCmd->phy_link_hdl, tx->id);

    return HCI_SUCCESS;
}


static A_UINT32 
hci_logical_link_cancel(AMP_DEV *dev, void *cmd, void *buf)
{
    HCI_CMD_LOGICAL_LINK_CANCEL *pCmd = (HCI_CMD_LOGICAL_LINK_CANCEL *)cmd;
    LL_CANCEL_RESP info;
    AMP_ASSOC_INFO *amp;
    A_UINT8 i;
    
    UNUSED(buf);
    UNUSED(dev);

    PAL_PRINT(("hci_logical_link_cancel %d\n", pCmd->phy_link_hdl));

    if (pCmd->param_length != 2) {
        pal_cmd_status_evt(dev, pCmd->opcode,HCI_ERR_INVALID_HCI_CMD_PARAMS);
        return HCI_ERR_INVALID_HCI_CMD_PARAMS;
    }

    
    info.phy_link_hdl = pCmd->phy_link_hdl;
    info.tx_flow_spec_id = pCmd->tx_flow_spec_id;
    
    get_remote_assoc_amp(dev, pCmd->phy_link_hdl, &amp);

    /* If phy link is not present then it's a different error case. 
     * This should not happen, as create would fail anyway, and hence
     * cancel has no meaning
     */
    if (amp == NULL) {
        PAL_PRINT(("AMP not populated for this phy hdl\n"));
        info.status = HCI_ERR_UNKNOWN_CONN_ID;
        pal_cmd_compl_evt(dev, pCmd->opcode, (A_UINT8 *)&info, sizeof(info));
        return  HCI_ERR_UNKNOWN_CONN_ID;
    }

    if (amp->phy_link_state != CONNECTED_STATE) {
        PAL_PRINT(("Phy link %d not connected. LL creation failed\n", pCmd->phy_link_hdl));
        info.status = HCI_ERR_UNKNOWN_CONN_ID;
        pal_cmd_compl_evt(dev, pCmd->opcode, (A_UINT8 *)&info, sizeof(info));
        return  HCI_ERR_UNKNOWN_CONN_ID;
    }

    for (i=0; i<MAX_FLOW_SPECS_PER_PHY_LINK; i++) {
        if (amp->logical_link[i].tx_spec.id == pCmd->tx_flow_spec_id) {
            break;
        }
    }

    if (i >= MAX_FLOW_SPECS_PER_PHY_LINK) {
        // not find logical id
        info.status = HCI_ERR_UNKNOWN_CONN_ID;
        pal_cmd_compl_evt(dev, pCmd->opcode,(A_UINT8*)&info, sizeof(info));
        return HCI_ERR_UNKNOWN_CONN_ID;
    }
    
    info.status = HCI_ERR_ACL_CONN_ALRDY_EXISTS;
    pal_cmd_compl_evt(dev, pCmd->opcode, (A_UINT8 *)&info, sizeof(info));
    return HCI_SUCCESS;
}


static A_UINT32 
hci_flow_spec_modify(AMP_DEV *dev, void *cmd, void *buf)
{
    HCI_CMD_FLOW_SPEC_MODIFY *pCmd = (HCI_CMD_FLOW_SPEC_MODIFY *)cmd;    

    UNUSED(buf);
    UNUSED(dev);

    PAL_PRINT(("CMD = HCI_Flow_Spec_Modify\n"));
    PAL_PRINT(("LL hdl = 0x%x\n", pCmd->hdl));
    pal_cmd_status_evt(dev, pCmd->opcode, HCI_SUCCESS);
    /* Get the LL info and modify the flow specs */

    pal_flow_spec_modify_evt(dev, HCI_SUCCESS, pCmd->hdl);
    return 0;
}


static A_UINT32    
hci_disconnect_logical_link(AMP_DEV *dev, void *cmd, void *buf)
{
    HCI_CMD_DISCONNECT_LOGICAL_LINK *pCmd = (HCI_CMD_DISCONNECT_LOGICAL_LINK *)cmd;
    AMP_ASSOC_INFO *amp;
    LLID_INFO *link;
    A_UINT16 id;

    UNUSED(buf);
    UNUSED(dev);

    PAL_PRINT(("CMD = HCI_Disconnect_Logical_Link\n"));
    PAL_PRINT(("LL hdl = 0x%x\n", pCmd->logical_link_hdl));

    id = pCmd->logical_link_hdl;

    get_remote_assoc_amp(dev, PAL_GET_PHY_HDL_FROM_LLID(id), &amp);

    if (amp == NULL) {
        PAL_PRINT(("AMP not populated for this phy hdl %d\n",
                PAL_GET_PHY_HDL_FROM_LLID(id))); 
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_UNKNOWN_CONN_ID);
        return (HCI_ERR_UNKNOWN_CONN_ID);
    }
    
    find_logical_link_info(amp, id, &link);

    if (link == NULL) {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_UNKNOWN_CONN_ID);
        return (HCI_ERR_UNKNOWN_CONN_ID);
    } else {
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_SUCCESS);
    }

    free_logical_link(amp, id);
    pal_disconnect_logical_link_compl_evt(dev, HCI_SUCCESS, id, REASON_CONN_TERM_BY_HOST);

    return 0;
}



static A_UINT32    
hci_disconnect_physical_link(AMP_DEV *dev, void *cmd, void *buf)
{
    HCI_CMD_DISCONNECT_PHY_LINK *pCmd = (HCI_CMD_DISCONNECT_PHY_LINK *)cmd;
    AMP_ASSOC_INFO *amp;

    UNUSED(buf);
    UNUSED(dev);

    PAL_PRINT(("CMD = HCI_Disconnect_Physical_Link\n"));
    PAL_PRINT(("Phy link hdl = %d\n", pCmd->phy_link_hdl));

    get_remote_assoc_amp(dev, pCmd->phy_link_hdl, &amp);

    if (amp == NULL) {
        PAL_PRINT(("AMP not populated for this phy hdl\n"));
        pal_cmd_status_evt(dev, pCmd->opcode, HCI_ERR_UNKNOWN_CONN_ID);
        return 1;
    }

    //Disconnect command from host has to be handled in any state
    pal_cmd_status_evt(dev, pCmd->opcode, HCI_SUCCESS);

    Pal_Physical_Link_Thread(amp, EVENT_DISCONECT_PHYSICAL_LINK, NULL, 0);

    return 0;
}



