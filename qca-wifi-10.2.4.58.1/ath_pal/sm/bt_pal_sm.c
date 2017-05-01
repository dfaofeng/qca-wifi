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
//  Filename:  bt_pal_sm.c
//
//  Author:    Mike Tsai
//
//  Created:   2/24/2009
//
//  Descriptions:
//
//     AMP Controller Main State Machine
//
//----------------------------------------------------------------------------
#include "osdep.h"
#include "pal_osapi.h"
#include "amp_db.h"
#include "bt_pal_evt.h"
#include "wlan_drv_intf.h"
#include "paldebug.h"
#include "pal_state.h"
#include "mywpa.h"
#include "bt_pal_security.h"
#include "bt_inp.h"
#include "poshApi.h"
#include "bt_pal_txq.h"

static A_UINT8 PAL_Disconnected_State(AMP_ASSOC_INFO *r_amp, A_UINT16 Event, A_UINT8 *Data, A_UINT16 Len);
static A_UINT8 PAL_Starting_State(AMP_ASSOC_INFO *r_amp, A_UINT16 Event, A_UINT8 *Data, A_UINT16 Len);
static A_UINT8 PAL_Connecting_State(AMP_ASSOC_INFO *r_amp, A_UINT16 Event, A_UINT8 *Data,  A_UINT16 Len);
static A_UINT8 PAL_Authenticating_State(AMP_ASSOC_INFO *r_amp, A_UINT16 Event, A_UINT8 *Data,  A_UINT16 Len);
static A_UINT8 PAL_Connected_State(AMP_ASSOC_INFO *r_amp, A_UINT16 Event, A_UINT8 *Data,  A_UINT16 Len);
static A_UINT8 PAL_Disconnecting_State(AMP_ASSOC_INFO *r_amp, A_UINT16 Event, A_UINT8 *Data, A_UINT16 Len);

/* API used by physical link statemachine  some function can be moved from original implementation */
static A_UINT8 pal_build_local_amp_assoc(AMP_ASSOC_INFO *r_amp);
static AMP_CH pal_get_selected_channel(AMP_ASSOC_INFO *l_amp, AMP_ASSOC_INFO *r_amp);
static A_UINT8 pal_stop_beacon(AMP_ASSOC_INFO *r_amp);
static A_UINT8 pal_start_phylink_timer(A_UINT32 timeout,AMP_ASSOC_INFO *r_amp);
static A_UINT8 pal_send_m1_frame(AMP_ASSOC_INFO *r_amp, A_UINT8* data, A_UINT16 len);
static A_UINT8 pal_send_m2_frame(AMP_ASSOC_INFO *r_amp, A_UINT8* data, A_UINT16 len);
static A_UINT8 pal_send_m3_frame(AMP_ASSOC_INFO *r_amp, A_UINT8* data, A_UINT16 len);
static A_UINT8 pal_send_m4_frame(AMP_ASSOC_INFO *r_amp, A_UINT8* data, A_UINT16 len);
static A_UINT8 pal_verify_key(AMP_ASSOC_INFO *r_amp, A_UINT8* data, A_UINT16 len);
static A_UINT8 pal_set_supervision_timer(AMP_ASSOC_INFO *r_amp);
static A_UINT8 pal_set_ptk_retry_timer(AMP_ASSOC_INFO *r_amp, A_UINT32 Timeout);
static A_UINT8 pal_del_all_llc(AMP_ASSOC_INFO *r_amp);
static void    PAL_resend_m3(AMP_ASSOC_INFO *r_amp);
static void    pal_statemachine_decode(A_UINT8 phy_state, A_UINT8 phy_action_state, A_UINT16 event);
static void    pal_secuity_rx(AMP_ASSOC_INFO *r_amp, HCI_ACL_DATA_PKT* acl);

static inline void PAL_BACK_TO_DISCONNECTED_STATE(AMP_ASSOC_INFO *r_amp, A_UINT8 status) 
{
    A_UINT8 Status = HCI_SUCCESS;

    r_amp->phylink_status = status;
     
    PAL_PRINT(("PAL_DISCONNECTED, State(%d), Action(%d), Status(%d)\n", 
                r_amp->phy_link_state, 
                r_amp->phy_link_action_state,
                r_amp->phylink_status));

    r_amp->phy_link_state = DISCONNECTED_STATE; 
    r_amp->phy_link_action_state = PAL_WAIT_DISCONNECT;
 
    if (r_amp->amp_dev->ResetInProcess == false) //Only send this event out if we are not going through RESET
    {
        if (r_amp->flag & FLAG_LINK_SVTO_Event)
            pal_disconnect_phy_link_compl_evt(r_amp->amp_dev, HCI_SUCCESS, r_amp->phy_link_hdl, HCI_ERR_CON_TIMEOUT);
        else if (r_amp->flag & FLAG_DisconCompleteEvent)
            pal_disconnect_phy_link_compl_evt(r_amp->amp_dev, HCI_SUCCESS, r_amp->phy_link_hdl, HCI_ERR_CON_TERM_BY_HOST);
 
        if (r_amp->flag & FLAG_CompleteEvent)
            pal_phy_link_compl_evt(r_amp->amp_dev, r_amp->phylink_status, r_amp->phy_link_hdl);
    }
 
    if (r_amp->amp_dev->ampBeaconStarted == false) //Beacon stopped, last link
    {
        if (r_amp->amp_dev->ResetInProcess == true) //Beacon stopped and we are in the middle of reset
        {
            PAL_PRINT(("Send deferred HCI Reset Complete Event to Host now!\n"));
            Status = HCI_SUCCESS; 
            pal_cmd_compl_evt(r_amp->amp_dev, HCI_Reset_Pal, &Status, sizeof(Status));
            r_amp->amp_dev->ResetInProcess = false;
        }
    }
    //Remove all timers from timer engine. If there have been removed, then do nothing
    pal_cleartimer(r_amp->amp_dev, &r_amp->phylinktimer);
    pal_cleartimer(r_amp->amp_dev, &r_amp->retry_timer);
    pal_cleartimer(r_amp->amp_dev, &r_amp->lstotimer); //clear link supervision timer here
    pal_cleartimer(r_amp->amp_dev, &r_amp->amp_dev->FlushCmpTimer);

    free_rem_assoc_amp(r_amp); 
}

static inline PAL_STOP_BEACON(AMP_ASSOC_INFO *r_amp, A_UINT8 status, AMP_DEV *Dev)
{
    //We will stop the beacon when there is no more remaining physical link(s)
    r_amp->phy_link_state = DISCONNECTING_STATE;
    r_amp->phylink_status = status;

    PAL_PRINT(("PAL Stopping Beacon, status (%d)\n", status));

    if (get_total_remote_links(Dev, r_amp->phy_link_hdl) == 0) {
        r_amp->phy_link_action_state = PAL_WAIT_BEACON_STOP;
        status = pal_stop_beacon(r_amp);
        PAL_POSH_API->SetRTS(Dev, 0);

        if (status != POSH_OK) //no need to wait for Beacon Stop, back to IDLE now
        {
            PAL_PRINT(("PAL_FATAL: Stop beacon Sync failed \n"));
            ASSERT(0);
            PAL_BACK_TO_DISCONNECTED_STATE(r_amp, status);
        }
        else
        {
            //Use the same connection timeout timer for this
            pal_cleartimer(r_amp->amp_dev, &r_amp->phylinktimer);
            pal_start_phylink_timer(DEFAULT_STOP_BEACON_TO, r_amp);
        }
    }
    else //Back to IDLE right now
        PAL_BACK_TO_DISCONNECTED_STATE(r_amp, status);
}

static inline PAL_ENTER_DISCONNECTING_STATE(AMP_ASSOC_INFO *r_amp, A_UINT8 status, AMP_DEV *Dev)
{
    PAL_PRINT(("PAL Enter Disconnecting State, Status (%d)\n", status));
   
    r_amp->phy_link_state = DISCONNECTING_STATE;
    r_amp->phy_link_action_state = PAL_WAIT_DISCONNECT;
    r_amp->phylink_status = status;
    pal_cleartimer(r_amp->amp_dev, &r_amp->phylinktimer);
    pal_start_phylink_timer(DEFAULT_DISCONN_TO, r_amp);
    pal_cleartimer(r_amp->amp_dev, &r_amp->lstotimer); //clear link supervision timer here
    pal_cleartimer(r_amp->amp_dev, &r_amp->amp_dev->FlushCmpTimer);
  
    //If Failed disconnect, then we go to stop beacon, but staying at disconnecting state
    //If we also failed stop beacon, then we back to disconnected state
    if (PAL_POSH_API->AmpDisconnect(Dev, r_amp) != POSH_OK) 
        PAL_STOP_BEACON(r_amp, status, Dev);     
}

static inline PAL_LINK_UP(AMP_ASSOC_INFO *r_amp, A_UINT8 status, AMP_DEV *Dev)
{
    UNUSED(Dev);
    pal_cleartimer(r_amp->amp_dev, &r_amp->phylinktimer);
    pal_cleartimer(r_amp->amp_dev, &r_amp->retry_timer);
    pal_cleartimer(r_amp->amp_dev, &r_amp->amp_dev->FlushCmpTimer);

    status = PAL_POSH_API->SetEncryptionKey(r_amp->amp_dev, r_amp);
    if (status != POSH_OK)
    {
        PAL_PRINT(("PAL Set Link Key Failed \n"));
        PAL_ENTER_DISCONNECTING_STATE(r_amp, HCI_ERR_HW_FAILURE, Dev);
    }
    else
    {
        r_amp->phy_link_action_state = PAL_PHYSICAL_LINK_ON; 
        r_amp->phy_link_state =  CONNECTED_STATE; 
        r_amp->flag = 0;
        pal_phy_link_compl_evt(r_amp->amp_dev, HCI_SUCCESS, r_amp->phy_link_hdl); 
        status = pal_set_supervision_timer(r_amp);
        PAL_POSH_API->SetRTS(Dev, 1); //turn ON RTS As default
    }
}

// DECLARATION:
//   1. hci command parameter verify handled in each hci command dispatch entry
//   2. only those command which affect physical link state should call Pal_Physical_Link_Thread
//   3. responding actions should handled in state machine
//   4. timer/mac event should handled in state machine


//  qos information is contianed in amp assoc
A_UINT8 Pal_Physical_Link_Thread(AMP_ASSOC_INFO  *amp, A_UINT16 Event, A_UINT8 *Data, A_UINT16 Len)
{
    OS_assert(amp != NULL);

    if (amp == NULL)
    {
        PAL_PRINT(("PAL_FATAL_ERROR, Invalid Event Received (%d) @ state (%d) with no AMP associated", Event));
        return(HCI_ERR_UNKNOWN_CONN_ID);
    }

    pal_statemachine_decode(amp->phy_link_state, amp->phy_link_action_state, Event);//print debug state

    switch (amp->phy_link_state)
    {
    case DISCONNECTED_STATE:   // initial state
        return(PAL_Disconnected_State(amp, Event, Data, Len));

    case STARTING_STATE:       // start beaconing state
        return(PAL_Starting_State(amp, Event, Data, Len));

    case CONNECTING_STATE:     // exchange frame state
        return(PAL_Connecting_State(amp, Event, Data, Len));

    case AUTHENTICATING_STATE: // get result of four way handshake
        return(PAL_Authenticating_State(amp, Event, Data, Len));

    case CONNECTED_STATE:      // connected 
        return(PAL_Connected_State(amp, Event, Data, Len));

    case DISCONNECTING_STATE:  // stop beaconing
        return(PAL_Disconnecting_State(amp, Event, Data, Len));

    default:
        break;
    }
    return (HCI_SUCCESS);
}

static void pal_statemachine_decode(A_UINT8 phy_state, A_UINT8 phy_action_state, A_UINT16 event)
{
    switch (phy_state) {
    case DISCONNECTED_STATE:   PAL_PRINT(("DISCONNECTED_STATE:")); break;
    case STARTING_STATE:       PAL_PRINT(("STARTING_STATE:")); break;
    case CONNECTING_STATE:     PAL_PRINT(("CONNECTING_STATE:")); break;
    case AUTHENTICATING_STATE: PAL_PRINT(("AUTHENTICATING_STATE:")); break;
    case CONNECTED_STATE:      PAL_PRINT(("CONNECTED_STATE:")); break;
    case DISCONNECTING_STATE:  PAL_PRINT(("DISCONNECTING_STATE:")); break;
    }

    switch (phy_action_state) {
    case PAL_WAIT_WRITE_RMT_AMP_ASSOC:     PAL_PRINT(("PAL_WAIT_WRITE_RMT_AMP_ASSOC:")); break;
    case PAL_WAIT_BEACON_START:            PAL_PRINT(("PAL_WAIT_BEACON_START:")); break;
    case PAL_WAIT_READ_LOCAL_AMP_ASSOC:    PAL_PRINT(("PAL_WAIT_READ_LOCAL_AMP_ASSOC:")); break;
    case PAL_WAIT_M1:                      PAL_PRINT(("PAL_WAIT_M1:")); break;
    case PAL_WAIT_M2:                      PAL_PRINT(("PAL_WAIT_M2:")); break;
    case PAL_WAIT_M3:                      PAL_PRINT(("PAL_WAIT_M3:")); break;                 
    case PAL_WAIT_M4_ONAIR:                PAL_PRINT(("PAL_WAIT_M4_ONAIR:")); break;
    case PAL_WAIT_M4:                      PAL_PRINT(("PAL_WAIT_M4:")); break;
    case PAL_PHYSICAL_LINK_ON:             PAL_PRINT(("PAL_PHYSICAL_LINK_ON:")); break;
    }

    switch (event) {
    case EVENT_CREATE_PHYSICAL_LINK:               PAL_PRINT(("EVENT_CREATE_PHYSICAL_LINK")); break;
    case EVENT_ACCEPT_PHYSICAL_LINK:               PAL_PRINT(("EVENT_ACCEPT_PHYSICAL_LINK")); break;
    case EVENT_WRITE_REMOTE_AMP_ASSOC:             PAL_PRINT(("EVENT_WRITE_REMOTE_AMP_ASSOC")); break;
    case EVENT_READ_LOCAL_AMP_ASSOC:               PAL_PRINT(("EVENT_READ_LOCAL_AMP_ASSOC")); break;
    case EVENT_CONNECT_ACCEPT_TIMEOUT:             PAL_PRINT(("EVENT_CONNECT_ACCEPT_TIMEOUT")); break;
    case EVENT_RECV_M1_FRAME:                      PAL_PRINT(("EVENT_RECV_M1_FRAME")); break;
    case EVENT_RECV_M2_FRAME:                      PAL_PRINT(("EVENT_RECV_M2_FRAME")); break;
    case EVENT_RECV_M3_FRAME:                      PAL_PRINT(("EVENT_RECV_M3_FRAME")); break;
    case EVENT_RECV_M4_ACK:                        PAL_PRINT(("EVENT_RECV_M4_ACK")); break;
    case EVENT_RECV_M4_FRAME:                      PAL_PRINT(("EVENT_RECV_M4_FRAME")); break;
    case EVENT_BEACON_START_SUCCESS:               PAL_PRINT(("EVENT_BEACON_START_SUCCESS")); break;
    case EVENT_BEACON_START_FAILED:                PAL_PRINT(("EVENT_BEACON_START_FAILED")); break;
    case EVENT_DISCONECT_PHYSICAL_LINK:            PAL_PRINT(("EVENT_DISCONECT_PHYSICAL_LINK")); break;
    case EVENT_MAC_MEDIA_LOSS_INDICATION:          PAL_PRINT(("EVENT_MAC_MEDIA_LOSS_INDICATION")); break;
    case EVENT_MAC_CONNECTION_CANCEL_INDICATION:   PAL_PRINT(("EVENT_MAC_CONNECTION_CANCEL_INDICATION")); break;
    }

    PAL_PRINT(("\n"));
}

static A_UINT8 PAL_Disconnected_State(AMP_ASSOC_INFO *r_amp, A_UINT16 Event, A_UINT8 *Data, A_UINT16 Len)
{
    AMP_DEV* Dev = r_amp->amp_dev;
    PAL_CFG* cfg = &Dev->pal_cfg;
    A_UINT8  EventProcessed = false;

    UNUSED(Len);
    UNUSED(Data);

    switch (Event) {
    case EVENT_DISCONECT_PHYSICAL_LINK: //We could have received this before going out of state
         r_amp->flag |= FLAG_DisconCompleteEvent;
         //most likely we have already start the connection
         PAL_BACK_TO_DISCONNECTED_STATE(r_amp, HCI_ERR_CON_TERM_BY_HOST);
         EventProcessed = true;
         break;

    case EVENT_CREATE_PHYSICAL_LINK: /* Receive HCI_Create_Physical_Link cmd */
        EventProcessed = true;
        r_amp->flag |= FLAG_CompleteEvent; 
        r_amp->phy_link_action_state = PAL_WAIT_WRITE_RMT_AMP_ASSOC;
        //EV#63334, Query local AMP (Channel Info) as initiator so we will not select wrong channel
        PAL_POSH_API->QueryChannelInfo(Dev, NULL);
        break;

    case EVENT_READ_LOCAL_AMP_ASSOC: //A legal state and actually shall
                                      //involve getting preferred channel list
                                      //An asynchronous event
        EventProcessed = true;
        break;

    case EVENT_ACCEPT_PHYSICAL_LINK: /* Receive HCI_Accept_Physical_Link_cmd */
        
        EventProcessed = true;
        r_amp->flag |= FLAG_CompleteEvent; 
        r_amp->phy_link_action_state = PAL_WAIT_WRITE_RMT_AMP_ASSOC;
        break;

    case EVENT_WRITE_REMOTE_AMP_ASSOC: /* Receive HCI_Write_Remote_Amp_Assoc cmd */

        EventProcessed = true; 
        pal_get_selected_channel(cfg->local_ampassoc, r_amp);
        if (r_amp->channel_selected.ieee == 0) {
            PAL_BACK_TO_DISCONNECTED_STATE(r_amp, HCI_ERR_CONN_REJ_NO_SUITABLE_CHAN);
            break;
        }
      
        //Should be *0.625 (1 slot = .625 mS)
        pal_start_phylink_timer(((cfg->conn_accept_timeout/10)*6), r_amp);

        if (get_total_remote_links(Dev, r_amp->phy_link_hdl) == 0) {
            /* set channel */
            r_amp->phy_link_state = STARTING_STATE;
            r_amp->phy_link_action_state = PAL_WAIT_BEACON_START;

            //Set Channel is not really needed until we have channel switching capability
            if (PAL_POSH_API->SetChannel(r_amp->amp_dev, r_amp) != POSH_OK) //failed, back to disconnected state
            {
                PAL_BACK_TO_DISCONNECTED_STATE(r_amp, HCI_ERR_CONN_REJ_NO_SUITABLE_CHAN);
            }
 
            if (PAL_POSH_API->StartBeacon(r_amp->amp_dev, r_amp) != POSH_OK) //failed, back to disconnected state
            {
                PAL_PRINT(("PAL_FATAL, Start Beacon Failed \n"));
                PAL_BACK_TO_DISCONNECTED_STATE(r_amp, HCI_ERR_UNSPECIFIED_ERROR);
            }
        } 
        else //Got beacon already, no need to start it again
        {
           PAL_Starting_State(r_amp, EVENT_BEACON_START_SUCCESS, NULL, 0);
        }
        break;
    
    default: 
        PAL_PRINT(("PAL_FATAL, Received Unexpected Even (%d) at Pal Disconnected State \n", Event));
        break;
    }
    
    OS_assert(EventProcessed == true);

    if (EventProcessed == false)
        PAL_PRINT(("PAL_FATAL, Received Unexpected Even (%d) at Pal Disconnected State \n", Event));


    return (HCI_SUCCESS);
}

static A_UINT8 PAL_Starting_State(AMP_ASSOC_INFO *r_amp, A_UINT16 Event, A_UINT8 *Data, A_UINT16 Len)
{
    AMP_DEV *Dev = r_amp->amp_dev;

    UNUSED(Len);
    UNUSED(Data);

    switch (Event) {
    case EVENT_CONNECT_ACCEPT_TIMEOUT:  //Beacon start timeout
         PAL_STOP_BEACON(r_amp, HCI_ERR_CON_TIMEOUT, Dev);        
         break;

    case EVENT_DISCONECT_PHYSICAL_LINK:
         r_amp->flag |= FLAG_DisconCompleteEvent;
         PAL_STOP_BEACON(r_amp, HCI_ERR_CON_TERM_BY_HOST, Dev);        
         break;

    case EVENT_BEACON_START_SUCCESS:
         
        r_amp->phy_link_state = CONNECTING_STATE;
        r_amp->amp_dev->ampBeaconStarted = true;

        PAL_PRINT(("PAL: Get to Beacon start success, Role(%d)\n",
                   r_amp->connection_side));
  
        //Only the initiator shall send out channel selected event to host
        if ( r_amp->connection_side == AMP_CONNECTION_ORIGINATOR )
        {
             pal_chan_sel_evt(r_amp->amp_dev, r_amp->phy_link_hdl);
        }
        
        //Both initiator and responder shall send start MP connection process
        r_amp->phy_link_action_state = PAL_WAIT_CONNECT;

        PAL_PRINT(("PAL: Posh connect now !\n"));
        if (PAL_POSH_API->AmpConnect(Dev, r_amp) != POSH_OK) //could failed just fine
        {
            PAL_PRINT(("PAL_FATAL, Start Connection Failed \n"));
            PAL_STOP_BEACON(r_amp, HCI_ERR_CONN_REJ_BY_LIMIT_RES, Dev);        
        } 
        break;

    case EVENT_BEACON_START_FAILED:
        PAL_BACK_TO_DISCONNECTED_STATE(r_amp, HCI_ERR_CON_LIMIT_EXECED);
        break;

    case EVENT_MAC_MEDIA_LOSS_INDICATION: 
        r_amp->flag |= FLAG_DisconCompleteEvent;
        PAL_STOP_BEACON(r_amp, HCI_ERR_CON_TIMEOUT, Dev);
        break;

    default: 
        PAL_PRINT(("Received Unexpected Even (%d) at Pal Starting State \n", Event));
        break;
    }
    return(HCI_SUCCESS);
}


static A_UINT8 PAL_Connecting_State(AMP_ASSOC_INFO *r_amp, A_UINT16 Event, A_UINT8 *Data, A_UINT16 Len)
{
    AMP_DEV *dev = r_amp->amp_dev;
    A_UINT8 status = HCI_SUCCESS;

    UNUSED(Len);
    UNUSED(Data);

    switch (Event) {
    case EVENT_CONNECT_ACCEPT_TIMEOUT:
         PAL_ENTER_DISCONNECTING_STATE(r_amp, HCI_ERR_CONN_ACCPT_TIMEOUT, dev);
         break;

    case EVENT_DISCONECT_PHYSICAL_LINK:
         r_amp->flag |= FLAG_DisconCompleteEvent;
         PAL_ENTER_DISCONNECTING_STATE(r_amp, HCI_ERR_CON_TERM_BY_HOST, dev);
         break;

    case EVENT_READ_LOCAL_AMP_ASSOC:
         r_amp->phy_link_action_state = PAL_WAIT_CONNECT;
         break;

    case EVENT_CONNECT_ASSOC_FAILED:
         PAL_ENTER_DISCONNECTING_STATE(r_amp, HCI_ERR_CON_TIMEOUT, dev);
         break;

    case EVENT_CONNECT_SUCCESS:
        r_amp->sec_record.replay_counter = 0; //initialize it to 0 but start sending from 1
        //Entering Authenticating State
        r_amp->phy_link_state = AUTHENTICATING_STATE;
        if (r_amp->connection_side == AMP_CONNECTION_ORIGINATOR)
        {
            r_amp->phy_link_action_state = PAL_WAIT_M2;
            r_amp->sec_record.replay_init_count = r_amp->sec_record.replay_counter;
            status = pal_send_m1_frame(r_amp, Data, Len);
            pal_set_ptk_retry_timer(r_amp, IEEE80211_RETRY_AUTH_INTERVAL);
        }
        else //terminator
        {
            r_amp->phy_link_action_state = PAL_WAIT_M1;
        }
        break;

    //Link lost because of MP connection lost
    case EVENT_MAC_MEDIA_LOSS_INDICATION: 
        r_amp->flag |= FLAG_DisconCompleteEvent;
        PAL_STOP_BEACON(r_amp, HCI_ERR_CON_TERM_BY_HOST, dev);
        break;

    default:
        PAL_PRINT(("Received Unexpected Even (%d) at Pal Connecting State \n", Event));
        break;
    }
    return (HCI_SUCCESS);
}   

static A_UINT8 PAL_Authenticating_State(AMP_ASSOC_INFO *r_amp, A_UINT16 Event, A_UINT8 *Data, A_UINT16 Len)
{
    AMP_DEV *dev = r_amp->amp_dev;
    A_UINT8 status = HCI_SUCCESS;
    
    switch (Event) {
    case EVENT_CONNECT_ACCEPT_TIMEOUT:
         PAL_ENTER_DISCONNECTING_STATE(r_amp, HCI_ERR_CONN_ACCPT_TIMEOUT, dev);
         break;

    case EVENT_DISCONECT_PHYSICAL_LINK:
         r_amp->flag |= FLAG_DisconCompleteEvent;
         PAL_ENTER_DISCONNECTING_STATE(r_amp, HCI_ERR_CON_TERM_BY_HOST, dev);
         break;

   case  EVENT_SEC_RETRY_MAX:
         PAL_ENTER_DISCONNECTING_STATE(r_amp, HCI_ERR_AUTH_FAILURE, dev);
         break;

   case EVENT_SEC_RETRY_TIMEOUT:
        pal_set_ptk_retry_timer(r_amp, IEEE80211_RETRY_AUTH_INTERVAL); //set retry timer
        break;

   case EVENT_RECV_M1_FRAME:
        //Retry M1 frame can be received while we are expecting M3 frame
        if ((r_amp->phy_link_action_state == PAL_WAIT_M1) ||
            (r_amp->phy_link_action_state == PAL_WAIT_M3))
        {
          r_amp->phy_link_action_state = PAL_WAIT_M3;
          status = pal_send_m2_frame(r_amp, Data, Len);
        }
        else
            PAL_PRINT(("PAL_ERROR: Received M1 while not expected \n"));
        break;

    case EVENT_RECV_M2_FRAME:
        if (r_amp->phy_link_action_state != PAL_WAIT_M2) {
            break;
        }

        pal_cleartimer(r_amp->amp_dev, &r_amp->retry_timer);
        r_amp->phy_link_action_state = PAL_WAIT_M4;
        r_amp->sec_record.replay_init_count = r_amp->sec_record.replay_counter;
    
        if ((status = pal_send_m3_frame(r_amp, Data, Len)) != HCI_SUCCESS) {
            PAL_ENTER_DISCONNECTING_STATE(r_amp, HCI_ERR_AUTH_FAILURE, dev);
            break;
        }

        pal_set_ptk_retry_timer(r_amp, IEEE80211_RETRY_AUTH_INTERVAL); //set retry timer
        break;

    case EVENT_RECV_M3_FRAME:
        if (r_amp->phy_link_action_state != PAL_WAIT_M3) {
            break;
        }
        r_amp->phy_link_action_state = PAL_WAIT_M4_ONAIR;
        /* sync with M4 frame, make sure set key happened after M4 on air */
        status = pal_send_m4_frame(r_amp, Data, Len);

        if (status != HCI_SUCCESS) //disconnect
        {
            PAL_ENTER_DISCONNECTING_STATE(r_amp, HCI_ERR_AUTH_FAILURE, dev);;
        }
        break;

    case EVENT_RECV_M4_ACK: //Supplicant, received AIR ack of M4 frame
        PAL_LINK_UP(r_amp, status, dev);
        break;
    
    case EVENT_RECV_M4_FRAME:
        //We are not exactly waiting for M4, so ignore it
        if (r_amp->phy_link_action_state != PAL_WAIT_M4) {
            DEBUGP(DBG_PAL, DL_ERROR, ("Received unexpected M4 Frame PhyId %d \n", r_amp->phy_link_hdl));
            break;
        }
    
        PAL_LINK_UP(r_amp, status, dev);
        break;

    //Link lost because of MP connection lost
    case EVENT_MAC_MEDIA_LOSS_INDICATION: 
        r_amp->flag |= FLAG_DisconCompleteEvent;
        PAL_STOP_BEACON(r_amp, HCI_ERR_CON_TERM_BY_HOST, dev);
        break;

    default:
        PAL_PRINT(("Received Unexpected Even (%d) at Pal Authing State \n", Event));
        break;   
    }

    return (HCI_SUCCESS);
}

static A_UINT8 PAL_Connected_State(AMP_ASSOC_INFO *r_amp, A_UINT16 Event, A_UINT8 *Data, A_UINT16 Len)
{
    AMP_DEV *dev = r_amp->amp_dev;
    
    UNUSED(Len);
    UNUSED(Data);

    switch (Event) {
    case EVENT_DISCONECT_PHYSICAL_LINK:
         r_amp->flag |= FLAG_DisconCompleteEvent;
         PAL_ENTER_DISCONNECTING_STATE(r_amp, HCI_ERR_CON_TERM_BY_HOST, dev);
         break;

    case EVENT_LINK_SVTO:
         r_amp->flag |= FLAG_LINK_SVTO_Event;
         PAL_ENTER_DISCONNECTING_STATE(r_amp, HCI_ERR_CON_TIMEOUT, dev);
         break;

    case EVENT_READ_LOCAL_AMP_ASSOC:
         break;

    //Link lost because of MP connection lost
    case EVENT_MAC_MEDIA_LOSS_INDICATION: 
         r_amp->flag |= FLAG_DisconCompleteEvent;
         PAL_STOP_BEACON(r_amp, HCI_ERR_CON_TERM_BY_HOST, dev);
         break;
 
    case EVENT_LINK_SV_REQ:
         pal_set_supervision_timer(r_amp); //time to fire supervision req
         break;

    default:
        PAL_PRINT(("Received Unexpected Even (%d) at Pal Connected State \n", Event));
        break;
    }
    return (HCI_SUCCESS);
}


static A_UINT8 PAL_Disconnecting_State(AMP_ASSOC_INFO * r_amp, A_UINT16 Event, A_UINT8 * Data, A_UINT16 Len)
{
    AMP_DEV *Dev = r_amp->amp_dev;

    UNUSED(Len);
    UNUSED(Data);

    switch (Event) {
    case EVENT_CONNECT_ACCEPT_TIMEOUT: //disconnet timeout
         if (r_amp->phy_link_action_state == PAL_WAIT_DISCONNECT)
             PAL_STOP_BEACON(r_amp, r_amp->phylink_status, Dev);     
         else
             PAL_BACK_TO_DISCONNECTED_STATE(r_amp, r_amp->phylink_status);
         break;

    case EVENT_DISCONECT_PHYSICAL_LINK: //just registers disconnect
         r_amp->flag |= FLAG_DisconCompleteEvent;
         r_amp->phylink_status = HCI_ERR_UNKNOWN_CONN_ID;
         break;

    case EVENT_BEACON_STOP_SUCCESS:
         r_amp->amp_dev->ampBeaconStarted = false;
         PAL_BACK_TO_DISCONNECTED_STATE(r_amp, r_amp->phylink_status);
         break;

    case EVENT_MAC_MEDIA_LOSS_INDICATION: //MP has completed disconnect
         PAL_STOP_BEACON(r_amp, r_amp->phylink_status, Dev);     
         break;

    default:
        PAL_PRINT(("Received Unexpected Even (%d) at Pal Disconnecting State \n", Event));
        break;
    }
    return (HCI_SUCCESS);
}


/*--------------------- State Machine used API functions  --------------------*/
static void process_activity_rpt(AMP_DEV *Dev, A_UINT8 *buf, A_UINT16 sz)
{
    ACTIVITY_RPT_HDR *hdr = (ACTIVITY_RPT_HDR *)buf;
    A_UINT8 eventBuf[MAX_EVT_PKT_SZ+1];
    HCI_DEBUG_EVENT *evt = (HCI_DEBUG_EVENT *)eventBuf;

    PAL_PRINT(("quiet period..schedule known %d\n", hdr->schedule_known));

    if (hdr->schedule_known == 1 && hdr->num_rpts == 0)
        PAL_POSH_API->SetRTS(Dev, 0);
    else if (hdr->schedule_known == 0)
        PAL_POSH_API->SetRTS(Dev, 1);

    if ((Dev->ampDbgWdmEnable & PAL_ACT_RPT_TEST) != 0) {
        evt->event_type = GET_ACT_RPT;
        evt->event_code = PAL_DEBUG_EVENT;
        evt->param_len = 2; 
        evt->params[0] = hdr->schedule_known;
        pal_send_event(Dev, eventBuf, evt->param_len + HCI_EVENT_HDR_SIZE);
    }
}

void pal_link_supervision_rx(AMP_ASSOC_INFO *amp, A_UINT8 type)
{
    if (type == LINK_SUPERVISION_REQ) {
        PAL_PRINT(("Rec link supervision req  (%02x:%02x:%02x:%02x:%02x:%02x)\n", 
                   amp->hwaddr[0],amp->hwaddr[1],amp->hwaddr[2],
                   amp->hwaddr[3],amp->hwaddr[4],amp->hwaddr[5]));
        send_pal_link_supervision_tx(amp, LINK_SUPERVISION_RESP);
    } else if (type == LINK_SUPERVISION_RESP) {
        PAL_PRINT(("Rec link supervision resp (%02x:%02x:%02x:%02x:%02x:%02x)\n", 
                   amp->hwaddr[0],amp->hwaddr[1],amp->hwaddr[2],
                   amp->hwaddr[3],amp->hwaddr[4],amp->hwaddr[5]));
        amp->ping_cnt = 0;
    }
   
}

/* used for support AP-Link and AMP-Link Coexist */
static A_UINT8 pal_build_local_amp_assoc(AMP_ASSOC_INFO *r_amp)
{
    // TODO add code
    UNUSED(r_amp);
    return HCI_SUCCESS;
}

/* used for select channel */
static AMP_CH pal_get_selected_channel(AMP_ASSOC_INFO *l_amp, AMP_ASSOC_INFO *r_amp)
{
    perform_chan_select(l_amp, r_amp, &r_amp->channel_selected);
    PAL_PRINT(("PAL Selected Channel = %d\n", r_amp->channel_selected.ieee));   
    return r_amp->channel_selected;
}


/* used for stop beacon */
static A_UINT8 pal_stop_beacon(AMP_ASSOC_INFO *r_amp)
{
    AMP_DEV *Dev = r_amp->amp_dev;
    
    if (r_amp->phy_link_hdl == PAL_INVALID_PHYSICAL_LINK_ID)
        return(HCI_ERR_UNKNOWN_CONN_ID);

    return(PAL_POSH_API->StopBeacon(r_amp->amp_dev, NULL));
}


static A_UINT8 pal_send_m1_frame(AMP_ASSOC_INFO *r_amp, A_UINT8* data, A_UINT16 len)
{
    A_UINT8    buf[256];
    A_UINT8    sz;
    TX_CB      cb;

    UNUSED(len);
    UNUSED(data);

    os_memset(&cb, 0, sizeof(TX_CB));
    create_eop_m1(r_amp, buf, &sz);
    PAL_PRINT(("sending M1...\n"));
    //NO logic link, so no NoCB events to host
    create_80211_fr_and_send(r_amp, buf, sz, SECURED_FRAMES, EFS2UPtable[MIN_LATENCY], (MASK_FOR_M1+r_amp->phy_link_hdl));
    return HCI_SUCCESS;
}

static A_UINT8 pal_send_m2_frame(AMP_ASSOC_INFO *r_amp, A_UINT8* data, A_UINT16 len)
{
    AMP_DEV *dev = r_amp->amp_dev;
    A_UINT8 buf[256];
    A_UINT8 sz;
    A_UINT8 mic[MIC_LENGTH];
    A_UINT8 *pmk = r_amp->sec_record.link_key;
    A_UINT8 *mic_in_fr;

    parse_m1_create_m2(r_amp, data, buf, len, &sz);
    PAL_PRINT(("sending M2, sz(%d)...\n", sz));

    generate_ptk(pmk, r_amp->sec_record.a_nonce, r_amp->sec_record.s_nonce, dev->hwaddr, r_amp->hwaddr, r_amp->sec_record.ptk);
    wpa_eapol_key_mic(r_amp->sec_record.ptk, 2, buf, sz, mic);

    PAL_PRINT(("PMK = \n"));
    dump_frame(pmk, LINK_KEY_LEN);
    PAL_PRINT(("PTK = \n"));
    dump_frame(r_amp->sec_record.ptk, 64);
    PAL_PRINT(("Buf acting on MIC(for generation in M2)\n"));
    dump_frame(buf, sz);
    /* Add MIC */
    mic_in_fr = &buf[MIC_OFFSET];
    os_memcpy(mic_in_fr, mic, MIC_LENGTH); /* Get MIC start */

    PAL_PRINT(("MIC added in M2\n"));
    dump_frame(mic, MIC_LENGTH);
    PAL_PRINT(("sending M2...len = %d\n", sz));
    dump_frame(buf, sz);
    create_80211_fr_and_send(r_amp, buf, sz, SECURED_FRAMES, EFS2UPtable[MIN_LATENCY], (MASK_FOR_M2+r_amp->phy_link_hdl));
    return HCI_SUCCESS;
}

static A_UINT8 pal_send_m3_frame(AMP_ASSOC_INFO *r_amp, A_UINT8* data, A_UINT16 len)
{
    AMP_DEV *dev = r_amp->amp_dev;
    A_UINT8 buf[256];
    A_UINT8 sz;
    A_UINT8 Status;
    A_UINT8 mic[MIC_LENGTH];
    A_UINT8 *pmk = r_amp->sec_record.link_key;
    A_UINT8 *mic_in_fr;

    parse_and_decode_m2(r_amp, data, (A_UINT8)len, mic); /* databuf pointing to EAPOL frame */

    /* Generate PTK and MIC it */
    generate_ptk(pmk, r_amp->sec_record.a_nonce, r_amp->sec_record.s_nonce, dev->hwaddr, r_amp->hwaddr, r_amp->sec_record.ptk);

    Status = verify_mic(data, (A_UINT8)len, mic, r_amp->sec_record.ptk);
    if (Status != HCI_SUCCESS) //fail
        return (Status);

    create_eop_m3(r_amp, buf, &sz);

    PAL_PRINT(("WPA_GEN_MIC, version 2, sz (%d), Key = \n", sz));
    dump_frame(r_amp->sec_record.ptk, LINK_KEY_LEN);

    PAL_PRINT(("Buf before micing, len(%d) ...\n", sz));
    dump_frame(buf, sz);
    wpa_eapol_key_mic(r_amp->sec_record.ptk, 2, buf, sz, mic);
    /* Add MIC in M3*/
    mic_in_fr = &buf[17+32+16+8+8];
    os_memcpy(mic_in_fr, mic, MIC_LENGTH); /* Get MIC start */
    PAL_PRINT(("sending M3...\n"));
    create_80211_fr_and_send(r_amp, buf, sz, SECURED_FRAMES, EFS2UPtable[MIN_LATENCY], (MASK_FOR_M3+r_amp->phy_link_hdl));
    return HCI_SUCCESS;
}

static void PAL_resend_m3(AMP_ASSOC_INFO *r_amp)
{
    A_UINT8 buf[256];
    A_UINT8 sz;
    A_UINT8 mic[MIC_LENGTH];
    A_UINT8 *mic_in_fr;

    create_eop_m3(r_amp, buf, &sz);
    wpa_eapol_key_mic(r_amp->sec_record.ptk, 2, buf, sz, mic);
    /* Add MIC in M3*/
    mic_in_fr = &buf[17+32+16+8+8];
    os_memcpy(mic_in_fr, mic, MIC_LENGTH); /* Get MIC start */
    PAL_PRINT(("Re-sending M3...\n"));
    create_80211_fr_and_send(r_amp, buf, sz, SECURED_FRAMES, EFS2UPtable[MIN_LATENCY], (MASK_FOR_M3+r_amp->phy_link_hdl));
}


static A_UINT8 pal_send_m4_frame(AMP_ASSOC_INFO *r_amp, A_UINT8* data, A_UINT16 len)
{
    A_UINT8 buf[256];
    A_UINT8 sz;
    A_UINT8 mic[MIC_LENGTH];
    A_UINT8 *mic_in_fr;
    A_UINT8 Status;

    Status = parse_m3_create_m4(r_amp, data, buf, len, &sz, mic);
    PAL_PRINT(("sending M4, sz(%d), Status (%d)...\n", sz, Status));
    if (Status != HCI_SUCCESS)
    {
       PAL_PRINT(("MIC verification failed, Status (%d)...\n", Status));
       return(Status);
    }

    wpa_eapol_key_mic(r_amp->sec_record.ptk, 2, buf, sz, mic);

    /* Add MIC in M4*/
    mic_in_fr = &buf[MIC_OFFSET];
    os_memcpy(mic_in_fr, mic, MIC_LENGTH); /* Get MIC start */
    create_80211_fr_and_send(r_amp, buf, sz, SECURED_FRAMES, EFS2UPtable[MIN_LATENCY], (MASK_FOR_M4+r_amp->phy_link_hdl));
    return (HCI_SUCCESS);
}

//-----------------------------------------------------------------------------------------------------------
// Timeout events setting/clearing and processing here
//-----------------------------------------------------------------------------------------------------------
static void phylink_timerfire(A_UINT32* contex )
{
    MP_EVENT_CONTEXT  EventCtxt;
    AMP_ASSOC_INFO*   amp = (AMP_ASSOC_INFO*)contex;
    OS_assert(amp != NULL);

    if (amp) {
        if (amp->phy_link_state != DISCONNECTED_STATE) //could be a left over timer?
        {
            if (amp->connection_side == AMP_CONNECTION_ORIGINATOR) 
                amp->phylink_status =  HCI_ERR_CON_TIMEOUT;
            else
                amp->phylink_status =  HCI_ERR_CONN_ACCPT_TIMEOUT;

            PAL_PRINT(("Physic Link Timeout\n"));

            EventCtxt.EventId = EVENT_POSH_CONNECTE_TIMEOUT; //set event ID as MP connect timeout
            os_memcpy(&EventCtxt.PeerMac, amp->hwaddr, sizeof(EventCtxt.PeerMac)); //Copy MAC address
            //Post the event and get out of there
            PAL_post_event_q(amp->amp_dev, PAL_TIMER_EVENT_QUEUE, EventCtxt.EventId,   
                   (A_UINT8 *)&EventCtxt, sizeof(MP_EVENT_CONTEXT));  
       }
    }

}


static A_UINT8 pal_start_phylink_timer(A_UINT32 timeout, AMP_ASSOC_INFO *r_amp)
{
    r_amp->phylinktimer.timer_type = PHYSICAL_LINK_TIMEOUT;  
    return((A_UINT8)pal_settimer(r_amp->amp_dev, timeout, phylink_timerfire, r_amp, &r_amp->phylinktimer));
}

static void ptk_retry_timerfire(A_UINT32* contex )
{
  
    MP_EVENT_CONTEXT  EventCtxt;
    AMP_ASSOC_INFO*   amp = (AMP_ASSOC_INFO*)contex;
    A_UINT8           EventExpected = true;
    A_UINT8           RetryMax = false;

    OS_assert(amp != NULL);

    if (amp) {

       switch(amp->phy_link_action_state)
       {
        case PAL_WAIT_M2:
            //retry M1
            if (amp->sec_record.replay_counter <= (amp->sec_record.replay_init_count + IEEE80211_AUTH_MAX_TRIES))
            {
                PAL_PRINT(("Resending M1 \n"));
                pal_send_m1_frame(amp, NULL, 0);
            }
            else
            {
                PAL_PRINT(("M1 Retry Max times \n"));
                RetryMax = true;
            }

            break;

        case PAL_WAIT_M4:
            //retry M3
            if (amp->sec_record.replay_counter <= IEEE80211_AUTH_MAX_TRIES)
            {
                PAL_PRINT(("Resending M3 \n"));
                PAL_resend_m3(amp);
            }
            else
            {
                PAL_PRINT(("M3 Retry Max times \n"));
                RetryMax = true;
            }
            break;

        default:
            EventExpected = false;
            PAL_PRINT(("Warning: Leak PTK retry timer \n"));
            break;
        }
    }

    if (EventExpected == true)   
    {
        if (RetryMax == false)
            EventCtxt.EventId = EVENT_POSH_SEC_RETRY_TIMEOUT; //Ask PAL sm to retry
        else
            EventCtxt.EventId = EVENT_POSH_SEC_RETRY_MAX;     //Failed, disconnect

            os_memcpy(&EventCtxt.PeerMac, amp->hwaddr, sizeof(EventCtxt.PeerMac)); //Copy MAC address
            //Post the event and get out of there
            PAL_post_event_q(amp->amp_dev, PAL_TIMER_EVENT_QUEUE, EventCtxt.EventId,   
                   (A_UINT8 *)&EventCtxt, sizeof(MP_EVENT_CONTEXT));  
    }
}

static A_UINT8 pal_set_ptk_retry_timer(AMP_ASSOC_INFO *r_amp, A_UINT32 Timeout)
{
    r_amp->retry_timer.timer_type = SECURITY_FRAME_TIMEOUT;  
    r_amp->sec_record.ptk_retry_timer = pal_settimer(r_amp->amp_dev, Timeout, ptk_retry_timerfire, r_amp, &r_amp->retry_timer);
    return HCI_SUCCESS;  
}

void supervison_timer_fire(A_UINT32* contex)
{
    MP_EVENT_CONTEXT  EventCtxt;
    AMP_ASSOC_INFO *amp = (AMP_ASSOC_INFO*) contex;
    OS_assert(amp != NULL);

    if (amp)
    {
        if (amp->valid == 0) {
            OS_assert(0); return;
        }

        send_pal_link_supervision_tx(amp, LINK_SUPERVISION_REQ);

        if (amp->ping_cnt > LSTO_DIVIDER) {
            PAL_PRINT(("LSTO timer expeired\n"));
            EventCtxt.EventId = EVENT_POSH_SVTO;  //Link Supervision Timeout
        } else {
            EventCtxt.EventId = EVENT_POSH_SV_REQ;  //Link Supervision Request
        }

        os_memcpy(&EventCtxt.PeerMac, amp->hwaddr, sizeof(EventCtxt.PeerMac)); //Copy MAC address
        //Post the event and get out of there
        PAL_post_event_q(amp->amp_dev, PAL_TIMER_EVENT_QUEUE, EventCtxt.EventId,   
                            (A_UINT8 *)&EventCtxt, sizeof(MP_EVENT_CONTEXT));        
    
    }
}

static A_UINT8 pal_set_supervision_timer(AMP_ASSOC_INFO *r_amp)
{
    r_amp->lstotimer.timer_type = LINK_SUPERVISION_TIMEOUT;
    return((A_UINT8)pal_settimer(r_amp->amp_dev,(((r_amp->link_supervision_timeout/10)*6)/LSTO_DIVIDER), supervison_timer_fire, r_amp, &r_amp->lstotimer));
}


//------------------------------------------------------------------------------------------------
// We dispatch POSH event here. This is different from the pal_set_event_dispatcher(event_dispather)
// that was set by the UPOSH. 
// Here PAL takes LPOSH event and dispatches to PAL global state machine or physical link sm
// based on the incoming remoter device address.
//------------------------------------------------------------------------------------------------
#define  GET_AMP_FOR_EVENT_VIA_ADDR(Dev, amp, Context)\
{\
    amp = get_remote_amp_assoc_via_addr(Dev, &Context->PeerMac[0]);\
    if (amp == NULL) \
    {\
        PAL_PRINT(("PAL-FATAL Error, Recived peerMac not in the device data base (%02X:%02X:%02X:%02X:%02X:%02X)\n",\
        Context->PeerMac[0],Context->PeerMac[1],Context->PeerMac[2], \
        Context->PeerMac[3],Context->PeerMac[4],Context->PeerMac[5])); \
        return(HCI_ERR_HW_FAILURE); \
    }\
}\


#define GET_AMP_FOR_EVENT_VIA_STATE(Dev, amp, ActionState)\


A_UINT32 pal_posh_event_dispatcher(AMP_DEV *Dev, POSH_PAL_EVENT EventId, MP_EVENT_CONTEXT *Context)
{
    AMP_ASSOC_INFO *amp = NULL;

    ASSERT(Context != NULL);
    if (Context == NULL)
    {
        PAL_PRINT(("Received NULL Context Pointer from POSH \n"));
        return(HCI_ERR_HW_FAILURE);
    }

    PAL_PRINT(("Received MP Event (%X), Status (%d)\n", EventId, Context->Status));

    switch (EventId) {
    case EVENT_POSH_VAP_CREATED:      // Vap created complete
        if (Context->Status == POSH_OK)
        {
            Dev->pal_dev_state = PAL_READY_STATE; //for now
            Dev->VapNumber =    Context->VapPort;
            os_memcpy(&Dev->hwaddr[0], &Context->PeerMac[0], sizeof(Context->PeerMac));

            PAL_PRINT(("AMP Controller Dev State (%d), Vap (%X), MAC(%02X:%02X:%02X:%02X:%02X:%02X) \n", 
                    Dev->pal_dev_state, Dev->VapNumber,
                    Dev->hwaddr[0],
                    Dev->hwaddr[1],
                    Dev->hwaddr[2],
                    Dev->hwaddr[3],
                    Dev->hwaddr[4],
                    Dev->hwaddr[5]));

            pal_init_ready_state(Dev);
        }
        else
            Dev->pal_dev_state = PAL_CREATE_AMP_VAC_FAILED_STATE;

        break;

    case EVENT_POSH_VAP_DELETED:      // Vap Deleted complete
        //We need to know if this is part of exiting sequence of OS
        //or unexpected event, how are we going to handle it differently?
        if (Context->Status == POSH_OK)
            Dev->pal_dev_state = PAL_IDLE_STATE; //for now
        else
            Dev->pal_dev_state = PAL_DELETE_AMP_VAC_FAILED_STATE;

        PAL_PRINT(("AMP Controller Dev State (%d) \n", Dev->pal_dev_state));
        break;

    case EVENT_POSH_BEACON_START_SUCCESS:
         amp = get_remote_amp_assoc_via_state(Dev, PAL_WAIT_BEACON_START);
         if (amp == NULL) 
         {
            PAL_PRINT(("PAL-FATAL Error, Recived Event, No Match state (%d)\n", PAL_WAIT_BEACON_START));            
            return(HCI_ERR_HW_FAILURE); 
         }

         Pal_Physical_Link_Thread(amp, EVENT_BEACON_START_SUCCESS, NULL, 0);
         break;

    case EVENT_POSH_BEACON_STOP_SUCCESS:
         amp = get_remote_amp_assoc_via_state(Dev, PAL_WAIT_BEACON_STOP);
         if (amp == NULL) 
         {
            PAL_PRINT(("PAL-FATAL Error, Recived Event, No Match state (%d)\n", PAL_WAIT_BEACON_START));            
            return(HCI_ERR_HW_FAILURE); 
         }

         Pal_Physical_Link_Thread(amp, EVENT_BEACON_STOP_SUCCESS, NULL, 0);
         break;

    case EVENT_POSH_BEACON_START_FAILED:
         amp = get_remote_amp_assoc_via_state(Dev, PAL_WAIT_BEACON_START);
         if (amp == NULL) 
         {
            PAL_PRINT(("PAL-FATAL Error, Recived Event, No Match state (%d)\n", PAL_WAIT_BEACON_START));            
            return(HCI_ERR_HW_FAILURE); 
         }
         Pal_Physical_Link_Thread(amp, EVENT_BEACON_START_FAILED, NULL, 0);
         break;
    
    case EVENT_POSH_CONNECTED:
        amp = get_remote_amp_assoc_via_addr(Dev, Context->PeerMac);
        OS_eval_assert((amp != NULL));
        amp->qos_support = Context->QosEnable;
        PAL_PRINT(("Receive Connect Complete Event, Status (%d), Qos(%d) \n", Context->Status, Context->QosEnable));
        Pal_Physical_Link_Thread(amp, (Context->Status == POSH_OK?EVENT_CONNECT_SUCCESS:EVENT_CONNECT_ASSOC_FAILED), NULL, 0);
        break;

    case EVENT_POSH_CONNECTE_TIMEOUT:
         amp = get_remote_amp_assoc_via_addr(Dev, Context->PeerMac);
         OS_eval_assert((amp != NULL));
         PAL_PRINT(("Receive Connect timeout Event \n"));
         Pal_Physical_Link_Thread(amp, EVENT_CONNECT_ACCEPT_TIMEOUT, NULL, 0);
         break;

    case EVENT_POSH_DISCONNECTED:
         PAL_PRINT(("MP Disconnect Event, reason (%d) \n", Context->Reason));
         //Report status change so host can retry when we are ready
         if (Context->Reason == WLAN_CHANNEL_CHANGE)
         {
             PAL_PRINT(("Sent status change, AMP has no capacity \n"));
             pal_amp_status_changed_evt(Dev, AMP_RF_POWER_DOWN); //Tell host we have no capacity and late
                                                           //tell host we are ready
         }

         amp = get_remote_amp_assoc_via_addr(Dev, Context->PeerMac);
         OS_eval_assert((amp != NULL));
         Pal_Physical_Link_Thread(amp, EVENT_MAC_MEDIA_LOSS_INDICATION, NULL, 0);
         break;

    case EVENT_POSH_SEC_RETRY_TIMEOUT:
         amp = get_remote_amp_assoc_via_addr(Dev, Context->PeerMac);
         OS_eval_assert((amp != NULL));
         Pal_Physical_Link_Thread(amp, EVENT_SEC_RETRY_TIMEOUT, NULL, 0);
         break;

    case EVENT_POSH_SEC_RETRY_MAX:
         amp = get_remote_amp_assoc_via_addr(Dev, Context->PeerMac);
         OS_eval_assert((amp != NULL));
         Pal_Physical_Link_Thread(amp, EVENT_SEC_RETRY_MAX, NULL, 0);
         break;

    case EVENT_POSH_SVTO:
         amp = get_remote_amp_assoc_via_addr(Dev, Context->PeerMac);
         OS_eval_assert((amp != NULL));
         Pal_Physical_Link_Thread(amp, EVENT_LINK_SVTO, NULL, 0);
         break;

    case EVENT_POSH_SV_REQ:
         amp = get_remote_amp_assoc_via_addr(Dev, Context->PeerMac);
         OS_eval_assert((amp != NULL));
         Pal_Physical_Link_Thread(amp, EVENT_LINK_SV_REQ, NULL, 0);
         break;

    case EVENT_POSH_PAUSE:
        //Send Event AMP_Status_Change_Notify_Event
        break;

    case EVENT_POSH_READY:
        PAL_PRINT(("PAL Received AMP ready indication (inside PAL) \n"));
        pal_amp_status_changed_evt(Dev, AMP_FULL_CAPACITY);
        Dev->pal_cfg.local_ampinfo.amp_status = AMP_FULL_CAPACITY;
        Dev->pal_dev_state = PAL_READY_STATE;
        break;

    case EVENT_POSH_RADIO_DISABLED:
        /* then we send AMP status changed event to host stack */
        pal_amp_status_changed_evt(Dev, AMP_RF_POWER_DOWN);
        /* then we register AMP status down */
        Dev->pal_cfg.local_ampinfo.amp_status = AMP_RF_POWER_DOWN;
        break;

    case EVENT_POSH_AMP_SUSPEND:
        pal_amp_status_changed_evt(Dev, AMP_RF_POWER_DOWN);
        Dev->pal_cfg.local_ampinfo.amp_status = AMP_RF_POWER_DOWN;
        PAL_PRINT(("Entering Suspending\n"));
        Dev->pal_dev_state = PAL_IDLE_STATE;
        if (UPOSH_Suspend(Dev))
            Dev->FailtoStopAMP = true;
#if ATH_AMP_ISOLATE_TX_PATH
        pal_tx_queue_stop(&(Dev->pal_tx_queue));
#endif
        break;
        
    case EVENT_POSH_AMP_RESUME:
#if ATH_AMP_ISOLATE_TX_PATH
        pal_tx_queue_start(&(Dev->pal_tx_queue));
#endif
        if (Dev->FailtoStopAMP) {
            if (!UPOSH_Suspend(Dev)) {
                UPOSH_Resume(Dev);
            } else {
                OS_eval_assert(0);
            }
            Dev->FailtoStopAMP = false;            
        } else {
            UPOSH_Resume(Dev);
        }
        pal_amp_status_changed_evt(Dev, AMP_FULL_CAPACITY);
        Dev->pal_cfg.local_ampinfo.amp_status = AMP_FULL_CAPACITY;
        Dev->pal_dev_state = PAL_READY_STATE;
        PAL_PRINT(("Exiting Suspending\n"));
        break;

    case EVENT_POSH_RECV_M4_ACK:
         amp = get_remote_amp_assoc_via_addr(Dev, Context->PeerMac);
         OS_eval_assert((amp != NULL));
         Pal_Physical_Link_Thread(amp, EVENT_RECV_M4_ACK, NULL, 0);
         break;

    case EVENT_POSH_RECV_M1_FRAME:
         amp = get_remote_amp_assoc_via_addr(Dev, Context->PeerMac);
         OS_eval_assert((amp != NULL));
         Pal_Physical_Link_Thread(amp, EVENT_RECV_M1_FRAME, &Context->Context[0], Context->Size);
         break;

    case EVENT_POSH_RECV_M2_FRAME:
         amp = get_remote_amp_assoc_via_addr(Dev, Context->PeerMac);
         OS_eval_assert((amp != NULL));
         Pal_Physical_Link_Thread(amp, EVENT_RECV_M2_FRAME, &Context->Context[0], Context->Size);
         break;

    case EVENT_POSH_RECV_M3_FRAME:
         amp = get_remote_amp_assoc_via_addr(Dev, Context->PeerMac);
         OS_eval_assert((amp != NULL));
         Pal_Physical_Link_Thread(amp, EVENT_RECV_M3_FRAME, &Context->Context[0], Context->Size);
         break;

    case EVENT_POSH_RECV_M4_FRAME:
         amp = get_remote_amp_assoc_via_addr(Dev, Context->PeerMac);
         OS_eval_assert((amp != NULL));
         Pal_Physical_Link_Thread(amp, EVENT_RECV_M4_FRAME, &Context->Context[0], Context->Size);
         break;

    case EVENT_POSH_FLUSH_COMPLT:
    case EVENT_POSH_BEACON_STOP_FAILED:
        break;

    default:
        PAL_PRINT(("Received UnReg MP event (%d) \n", EventId));
        break;
    }

    return (HCI_SUCCESS);
}

//-------------------------------------------------------------------------------
// This function is a registered CallBack between PAL and LPOSH
//
// When LPOSH gets the MP callback, it calls this API to process
// the data frame.
// The first 40 bytes is the 802.11 PAL data frame, which has the
// remote device source address and the frame type that we want.
//
// We basically use the same data buffer but moves the real ACL data
// to the offset 4 on the buffer and then replaces the first 4 byte
// of this buffer with physical Handle + data len.
//
// There could be following types of data frame
//
// ACL data - duh, forward to UPOSH
// Link supervision Req/Res - heart beat, reset the watch dog timeout
// Activity Report - decode and probably disable RTS/CTS
// Security Frame M1 - M4: this we must pass over to PAL state machine
//                   
//-------------------------------------------------------------------------------
A_UINT32  pal_data_dispatcher(AMP_DEV *Dev, A_UINT8* pkt, A_UINT16 sz)
{
    A_UINT8 *sa, phy_hdl, *buf, frmtype;
    A_BOOL ret;
    AMP_ASSOC_INFO* r_amp;
    HCI_ACL_DATA_PKT *acl = (HCI_ACL_DATA_PKT *)(pkt + SNAP_TYPE_OFFSET - ACL_DATA_HEADER);
    A_BOOL flg = true;
    
    buf = pkt;                           // Point buf to the beginning of pkt
    sa = buf + SRC_ADDR_OFFSET;          // Get remote device's src mac address
    
//    PAL_PRINT(("PAL_Data_Dispatcher - Received Data, len(%d) \n", sz));
    dump_frame(buf, sz);                      //Dump the first 40 bytes of data
    ret = get_phy_hdl(Dev, sa, &phy_hdl);     // Search for remote AMP device based upon SA
  
    get_remote_assoc_amp(Dev, phy_hdl, &r_amp);
    OS_assert(r_amp != NULL);
    if (r_amp == NULL) 
        return(HCI_ERR_UNKNOWN_CONN_ID);

    frmtype = buf[SNAP_TYPE_OFFSET - 1]; // Also get Frame type

    if (ret == TRUE) { //Got associated remote device and frame type
        r_amp->ping_cnt = 0; //If we received any meaningful data, reset ping count
        //We can now replace the first 4 bytes of this packet
        acl->hdl_and_flags = ((A_UINT16)phy_hdl | AMP_PACKET_BOUNDRY_FLAG);
//      PAL_PRINT(("Phy Hdl = 0x%04X, type = %d\n", phy_hdl, frmtype));
        // Take out the 802.11 hdr and SNAP-LLC 
        acl->data_len = sz - SNAP_TYPE_OFFSET;
        // Move real ACL data inside this buffer
        //os_memmove(acl->data, (buf + SNAP_TYPE_OFFSET), acl->data_len);
        switch(frmtype)
        {
        case ACL_DATA:
            if (data_dispatcher) {
                // Give it to UPOSH
//              PAL_PRINT(("PAL_Data_Dispatcher - Forward Data to UPOSH, len(%d) \n", (ACL_DATA_HEADER + acl->data_len)));
                dump_frame((A_UINT8 *)acl, (ACL_DATA_HEADER + acl->data_len));  //Dump the first 40 bytes of data
                data_dispatcher(Dev, (A_UINT8 *)acl, (ACL_DATA_HEADER + acl->data_len));
                Dev->PalDataInQueue = true;
            }
            break;

        case ACTIVITY_REPORT:
             process_activity_rpt(Dev, acl->data, acl->data_len);
             break;

        case LINK_SUPERVISION_REQ:
        case LINK_SUPERVISION_RESP:
             pal_link_supervision_rx(r_amp, frmtype);
             break;

        case SECURED_FRAMES:
             flg = false;
             pal_secuity_rx(r_amp, acl);
             break;
        default:
             flg = false;
             break;

        }

        /* Keep a count of ACL frames(other than non-secured) received on this Phy link */
        if (flg) {
            r_amp->num_of_frames++;
            /* We trigger sending AR just after we received the first PAL frame */
            if (r_amp->num_of_frames == 1) {
                send_activity_report(Dev, r_amp, 1, 0, NULL);
            }
        }
    }
    else
    {
        PAL_PRINT(("failed to get phy_hdl\n"));
        return (HCI_ERR_UNKNOWN_CONN_ID);
    }
    return (HCI_SUCCESS);
}

//------------------------------------------------------------------------------------
// This is the TxData complete processing function
// We shall send out Number of Complete Block to BT host stack
//------------------------------------------------------------------------------------
A_UINT32 pal_sendpkt_complete(AMP_DEV *Dev, A_UINT32 LogicLinkId, A_UINT8 status)
{
    MP_EVENT_CONTEXT  EventCtxt;
    AMP_ASSOC_INFO* r_amp;
    A_UINT16        Lid;  

    if ((LogicLinkId & NON_ACL_MASK) == 0) //Only reports this with ACL Data
    {
        acl_data_tx_complete(Dev, LogicLinkId, status);
    }
    else //Is this a M4 security frame that we just sent out
    {
       PAL_PRINT_DATA(("PAL - Send Pkt complete, LogicLinkId = (%04X) \n", LogicLinkId));

        if ((LogicLinkId & ~NON_ACL_MASK) & MASK_FOR_M4)
        {
             Lid = (A_UINT16)(LogicLinkId & 0x0000FFFF);
             PAL_PRINT_DATA(("PAL - Send Pkt complete, LID = (%04X) \n", Lid));
             get_remote_assoc_amp(Dev, PAL_GET_PHY_HDL_FROM_LLID(Lid), &r_amp);
             if (r_amp) {
                 EventCtxt.EventId = EVENT_POSH_RECV_M4_ACK;
                 os_memcpy(&EventCtxt.PeerMac, r_amp->hwaddr, sizeof(EventCtxt.PeerMac)); //Copy MAC address
                 EventCtxt.Status = POSH_OK;
                 PAL_post_event_q(Dev, PAL_MP_EVENT_QUEUE, EventCtxt.EventId,   
                                 (A_UINT8 *)&EventCtxt, sizeof(MP_EVENT_CONTEXT));    
             }
             else
                 PAL_PRINT(("PAL-Can't Find r_amp for Lid(%04X), PhyId(%X) \n", Lid, PAL_GET_PHY_HDL_FROM_LLID(Lid)));
        }
    }

    return HCI_SUCCESS;
}


//---------------------------------------------------------------------------------------------------------
//
// Here we process the received M1 to M4 data frames.
// We can't call PAL state machine here directly because it is running in MP 
// thread (context).
//
// MTsai - the checking whether they are M1 to M4 frames here need to be in sync with the 802.11i
//         EAPOL security data frame
//
//         We decode the frame based on key information byte
//         Key Information. This field is 2 octets and specifies characteristics of the key. See Figure 43v.
//
//         B0 - B2     B3    B4-B5     B6        B7     B8    B9      B10     B11      B12         B13-B15
//         Key Desc    Key   Reserve   Install   Key   Key    Secure  Error   Request  Encrypted   Reserve
//         Version     Type                      Ack   MIC                             Key Data
//
//---------------------------------------------------------------------------------------------------------

//------------------------------ Local Definition Here ----------------------------------------------------
#define KEY_INFO_BYTE_OFFSET     5
#define SECURITY_PACKET_TYPE     3

#define EAPOL_KEY_DESC_VERSION   2     
#define KEY_TYPE_PAIR_WISE      (1<<3)
#define INSTALL_DERIVE_KEY      (1<<6)
#define KEY_ACK_AUTHENTICATOR   (1<<7)
#define KEY_MIC_CONTAINED       (1<<8)
#define SECURE_KEY_EXCHANGED    (1<<9)
#define EAPOL_MIC_ERROR         (1<<10)
#define EAPOL_KEY_REQ           (1<<11)
#define EAPOL_DATA_ENCRYPTED    (1<<12)

#define M1_KEY_INFO       (EAPOL_KEY_DESC_VERSION|KEY_TYPE_PAIR_WISE|KEY_ACK_AUTHENTICATOR)       //0x008A
#define M3_KEY_INFO       (M1_KEY_INFO|INSTALL_DERIVE_KEY|KEY_MIC_CONTAINED|SECURE_KEY_EXCHANGE)  //0x03CA
#define M2_KEY_INFO       (EAPOL_KEY_DESC_VERSION|KEY_TYPE_PAIR_WISE|KEY_MIC_CONTAINED)           //0x010A
#define M4_KEY_INFO       (M2_KEY_INFO|SECURE_KEY_EXCHANGED)                                      //0x030A

//------------------------------ Local Definition Here ----------------------------------------------------

static void pal_secuity_rx(AMP_ASSOC_INFO *r_amp, HCI_ACL_DATA_PKT* acl)
{
    MP_EVENT_CONTEXT  EventCtxt;
    A_UINT8 Mic[MIC_LENGTH];
    A_UINT8 KeyReplyCounter[KEY_REPLAY_COUNTER_STR_LEN];
    A_UINT16 KeyInfo;

    PAL_PRINT(("PAL-Received Security Data Frame \n"));
    dump_frame(acl->data, 50); //show first 50 bytes

    if (acl->data[1] != SECURITY_PACKET_TYPE) //simple sanity check here
    {
        PAL_PRINT(("PAL-Received invalid security data frame (0x%02X)\n, acl->data[1]"));
        OS_assert(acl->data[1] == 0x03);
        return;
    }

    //Let's see which M# frame that we have just received. MSB here
    KeyInfo = (A_UINT16)(acl->data[KEY_INFO_BYTE_OFFSET] << 8)+acl->data[KEY_INFO_BYTE_OFFSET+1];

    PAL_PRINT(("PAL-Received KeyInfo 0x%04X, M1_KEY_INFO(0x%04X) \n", KeyInfo, M1_KEY_INFO));

    //------------------ M1 or M3 ------------------------------------------------------
    //We are waiting for M1 and we are not getting M3
    if ((KeyInfo & M1_KEY_INFO) == M1_KEY_INFO) //M1 or M3
    {
        if ((KeyInfo & KEY_MIC_CONTAINED) == 0) //M1
        {
           EventCtxt.EventId = EVENT_POSH_RECV_M1_FRAME;
           PAL_PRINT(("PAL-Received M1 frame, forward to PAL state machine \n"));
        }
        else //M3
        {
           if (parse_and_decode_m3(r_amp, acl->data, Mic, KeyReplyCounter) == HCI_SUCCESS)
           {
                EventCtxt.EventId = EVENT_POSH_RECV_M3_FRAME;
                PAL_PRINT(("PAL-Received M3 frame \n"));
           }
           else
           {
                PAL_PRINT(("PAL-Received incorrect M3 frame \n"));
                return;
           }
        }
    }
    //------------------ M2 or M4 ------------------------------------------------------
    else 
      if ((KeyInfo & M2_KEY_INFO) == M2_KEY_INFO) //M2 and M4
       {
        if ((KeyInfo & SECURE_KEY_EXCHANGED) == 0) //M2
        {
           if (parse_and_decode_m2(r_amp, acl->data, (A_UINT8)acl->data_len, Mic) == HCI_SUCCESS) //right key_replay_count?
           {
             EventCtxt.EventId = EVENT_POSH_RECV_M2_FRAME;
             PAL_PRINT(("PAL-Received M2 frame \n"));
           }
           else
           {
             PAL_PRINT(("PAL-Received incorrect M2 frame \n"));
             return;
           }
       }
       else //M4
          {
              EventCtxt.EventId = EVENT_POSH_RECV_M4_FRAME;
              PAL_PRINT(("PAL-Received M4 frame \n"));
           }
      }
     else
       {
          PAL_PRINT(("PAL-Received Unreq Security Frame \n"));
          return;
       }

   //Prepare to copy security data into EventContext and pass to PAL
   EventCtxt.Size = acl->data_len;
   OS_assert(acl->data_len <= MAX_POSH_CONTEXT_SIZE);
   if (acl->data_len > MAX_POSH_CONTEXT_SIZE)
       return;
   //Copy actual data frame
   os_memcpy(&EventCtxt.Context[0], acl->data, acl->data_len);
   //PeerMac to search for Device structure 
   os_memcpy(&EventCtxt.PeerMac, r_amp->hwaddr, sizeof(EventCtxt.PeerMac)); //Copy MAC address
   EventCtxt.Status = POSH_OK;
   PAL_post_event_q(r_amp->amp_dev, PAL_MP_EVENT_QUEUE, EventCtxt.EventId,   
                   (A_UINT8 *)&EventCtxt, sizeof(MP_EVENT_CONTEXT));    


}
