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
#include "wlan_drv_intf.h"
#include "poshApi.h"

#define BT_PAL_TX_QUEUE_DEPTH                   70

enum pal_event_type {
    PAL_EVENT_NONE,
    PAL_EVENT_PROCESS_PACKET
};

typedef struct pal_event {
    POSH_SEND_PACKET_CONTEXT    SendPktCtxt;
} pal_event_t, *ppal_event_t;

static void pal_tx_queue_handle_event(void      *context,
                                      u_int16_t event, 
                                      u_int16_t event_data_len, 
                                      void      *event_data)
{
    pal_tx_queue_data_t    *pal_tx_queue_data = context;
    pal_event_t            *pal_event         = event_data;
    AMP_DEV                *Dev               = pal_tx_queue_data->amp_dev;   
    
    ASSERT(event == PAL_EVENT_PROCESS_PACKET);
    ASSERT(event_data_len == sizeof(pal_event_t));
    ASSERT(pal_tx_queue_data->initialized);

    PAL_PRINT_DATA(("%s: Queue TX frame pStartBuf=%08p len=%d LinkId=%d\n",
                    __func__, 
                    pal_event->SendPktCtxt.buf, 
                    pal_event->SendPktCtxt.len,
                    pal_event->SendPktCtxt.logical_link_id));

    if (pal_tx_queue_data->active) {
        PAL_POSH_API->SendPacket(pal_tx_queue_data->amp_dev, &(pal_event->SendPktCtxt));
    }
    else {
        PAL_POSH_API->FreePacket(pal_tx_queue_data->amp_dev, &(pal_event->SendPktCtxt));
    }
}

// called from create_80211_fr_and_send.
int pal_tx_queue_add_packet(pal_tx_queue_data_t      *pal_tx_queue_data, 
                            POSH_SEND_PACKET_CONTEXT *SendPktCtxt)
{
    pal_event_t    pal_event;
    int            rc;
    
    ASSERT(pal_tx_queue_data->initialized);
    
    if (! pal_tx_queue_data->active) {
        PAL_PRINT(("%s: Tx queue not active\n",
                    __func__));
    }

    /* Copy event data */
    pal_event.SendPktCtxt = *SendPktCtxt;
    rc = OS_MESGQ_SEND(&(pal_tx_queue_data->queue),
                       PAL_EVENT_PROCESS_PACKET,
                       sizeof(pal_event_t),
                       &pal_event);
             
    if (rc != EOK) {
        PAL_PRINT(("%s: Failed to queue message rc=%d\n",
                    __func__, rc));
        ASSERT(0);
    }
                  
    return rc;              
}

int pal_tx_queue_start(pal_tx_queue_data_t *pal_tx_queue_data)
{
    ASSERT(pal_tx_queue_data->initialized);
    
    pal_tx_queue_data->active = true;
    
    return EOK;
}

int pal_tx_queue_stop(pal_tx_queue_data_t *pal_tx_queue_data)
{
    ASSERT(pal_tx_queue_data->initialized);
    ASSERT(pal_tx_queue_data->active);
    
    pal_tx_queue_data->active = false;
    OS_MESGQ_DRAIN(&(pal_tx_queue_data->queue), pal_tx_queue_handle_event);

    return EOK;
}

int pal_tx_queue_attach(AMP_DEV *amp_dev, osdev_t oshandle, pal_tx_queue_data_t *pal_tx_queue_data)
{
    int    rc;
    
    OS_MEMZERO(pal_tx_queue_data, sizeof(*pal_tx_queue_data));
    
    pal_tx_queue_data->amp_dev = amp_dev;
    pal_tx_queue_data->active  = false;

    rc = OS_MESGQ_INIT(oshandle, 
                       &(pal_tx_queue_data->queue), 
                       sizeof(pal_event_t), 
                       BT_PAL_TX_QUEUE_DEPTH,
                       pal_tx_queue_handle_event, 
                       pal_tx_queue_data,   
                       MESGQ_PRIORITY_NORMAL, 
                       MESGQ_ASYNCHRONOUS_EVENT_DELIVERY);
                       
    if (rc != EOK) {
        PAL_PRINT(("%s: Cannot queue message rc=%d\n",
                    __func__, rc));
    }

    pal_tx_queue_data->initialized = true;
    
    return EOK;
}

int pal_tx_queue_detach(pal_tx_queue_data_t *pal_tx_queue_data)
{
    ASSERT(! pal_tx_queue_data->active);
    ASSERT(pal_tx_queue_data->initialized);
    
    OS_MESGQ_DESTROY(&(pal_tx_queue_data->queue));

    return EOK;
}

int pal_tx_queue_enhanced_flush(pal_tx_queue_data_t *pal_tx_queue_data)
{
    ASSERT(pal_tx_queue_data->initialized);
    ASSERT(pal_tx_queue_data->active);
    
    OS_MESGQ_DRAIN(&(pal_tx_queue_data->queue),pal_tx_queue_handle_event);

    return EOK;
}

