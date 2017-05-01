/*
 * Copyright (c) 2011, Atheros Communications Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * Host WMI unified implementation
 */
#include "athdefs.h"
#include "a_types.h"
#include "a_osapi.h"
#include "a_debug.h"
#include "ol_defines.h"
#include "ol_if_ath_api.h"
#include "ol_helper.h"
#include "htc_api.h"
#include "dbglog_host.h"
#include "wmi.h"
#include "wmi_unified_priv.h"
#include "htt.h"

#define WMI_BUFFER_LEN 50

static wmi_debug_t wmi_debug_buf_g[WMI_BUFFER_LEN];
static char wmi_count_g = 0;
static adf_os_spinlock_t wmi_debug_lock;

#ifdef ATHR_WIN_NWF
#define ATH_MODULE_NAME wmi
#ifdef DEBUG
#define ATH_DEBUG_WMI  ATH_DEBUG_MAKE_MODULE_MASK(0)
static ATH_DEBUG_MASK_DESCRIPTION wmi_debug_desc[] = {
    { ATH_DEBUG_WMI , "WMI Tracing"},
};

ATH_DEBUG_INSTANTIATE_MODULE_VAR(wmi,
                                 "wmi",
                                 "Wireless Module Interface",
                                 ATH_DEBUG_MASK_DEFAULTS,
                                 ATH_DEBUG_DESCRIPTION_COUNT(wmi_debug_desc),
                                 wmi_debug_desc);

#endif
#endif

#if ATH_PERF_PWR_OFFLOAD


/* WMI buffer APIs */

wmi_buf_t
wmi_buf_alloc(wmi_unified_t wmi_handle, int len)
{
    wmi_buf_t wmi_buf;
    /* NOTE: For now the wbuf type is used as WBUF_TX_CTL
     * But this need to be changed appropriately to reserve
     * proper headroom for wmi_buffers
     */
    wmi_buf = wbuf_alloc(wmi_handle->osdev, WBUF_TX_CTL, len);
    if( NULL == wmi_buf )
    {
        /* wbuf_alloc returns NULL if the internel pool in wmi_handle->osdev
         * is empty
         */
        return NULL;
    }


    /* Clear the wmi buffer */
    OS_MEMZERO(wbuf_header(wmi_buf), len);

    /*
     * Set the length of the buffer to match the allocation size.
     */
    wbuf_set_pktlen(wmi_buf, len);
    return wmi_buf;
}

#define htt_host_data_dl_len(_osbuf)  (HTC_HDR_ALIGNMENT_PADDING + HTT_SW_MSDU_DESC_LEN + HTT_SDU_HDR_LEN)

/*
 * Flush the HTC endpoint associated with WMI
 */
void
wmi_flush_endpoint(wmi_unified_t wmi_handle){

    HTCFlushEndpoint(wmi_handle->htc_handle, wmi_handle->wmi_endpoint_id, 0);

}

/* WMI API to block the WMI command  */
int
wmi_stop(wmi_unified_t wmi_handle) {
    printk("WMI Stop \n");
    wmi_handle->wmi_stopinprogress = 1;
    return 0;
}

#define RETURN_STRING(str) case (str) : return (#str)

char *
wmi_get_event_str(WMI_EVT_ID event_id)
{
   switch(event_id) {
      /** WMI service is ready; after this event WMI messages can be sent/received  */
      RETURN_STRING(WMI_SERVICE_READY_EVENTID);
      /** WMI is ready; after this event the wlan subsystem is initialized and can process commands. */
      RETURN_STRING(WMI_READY_EVENTID);
      /** event carries buffered debug messages  */
      RETURN_STRING(WMI_DEBUG_MESG_EVENTID);

      /** Scan specific events */
      RETURN_STRING(WMI_SCAN_EVENTID);

      /** echo event in response to echo command */
      RETURN_STRING(WMI_ECHO_EVENTID);

      /** FW stats(periodic or on shot)  */
      RETURN_STRING(WMI_UPDATE_STATS_EVENTID);

      /* Instantaneous RSSI event */
      RETURN_STRING(WMI_INST_RSSI_STATS_EVENTID);
      /* VDEV specific events */
      /** VDEV started event in response to VDEV_START request */
      RETURN_STRING(WMI_VDEV_START_RESP_EVENTID);

      /** vdev stanby request.this is
       *  used part of message exchange with FW to move AP vdev to a new channel
       *  along with STA vdev when the STA vdev moves to a new channel */
      RETURN_STRING(WMI_VDEV_STANDBY_REQ_EVENTID);
      /** vdev resume request.this is
       *  used part of message exchange with FW to move AP vdev to a new channel
       *  along with STA vdev when the STA vdev moves to a new channel */
      RETURN_STRING(WMI_VDEV_RESUME_REQ_EVENTID);
      /** vdev stopped event , generated in response to VDEV_STOP request */
      RETURN_STRING(WMI_VDEV_STOPPED_EVENTID);

      /* peer  specific events */
      /** FW reauet to kick out the station for reasons like inactivity,lack of response ..etc */
      RETURN_STRING(WMI_PEER_STA_KICKOUT_EVENTID);

      /* beacon/mgmt specific events */
      /** software beacon alert event to Host requesting host to Queue a beacon for transmission
        use only in host beacon mode */
      RETURN_STRING(WMI_HOST_SWBA_EVENTID);
      /** beacon tbtt offset event indicating the tsf offset of the tbtt from the theritical value.
        tbtt offset is normally 0 and will be non zero if there are multiple VDEVs operating in
        staggered beacon transmission mode */
      RETURN_STRING(WMI_TBTTOFFSET_UPDATE_EVENTID);
      /** RX management frame. the entire frame is carried along with the event.  */
      RETURN_STRING(WMI_MGMT_RX_EVENTID);

      /** Channel stats event    */
      RETURN_STRING(WMI_CHAN_INFO_EVENTID);

      /** PHY Error specific WMI event */
      RETURN_STRING(WMI_PHYERR_EVENTID);

      /** Roam event to trigger roaming on host */
      RETURN_STRING(WMI_ROAM_EVENTID);

      /** matching AP found from list of profiles */
      RETURN_STRING(WMI_PROFILE_MATCH);

      /** debug print message used for tracing FW code while debugging  */
      RETURN_STRING(WMI_DEBUG_PRINT_EVENTID);
      /** VI spoecific event  */
      RETURN_STRING(WMI_PDEV_QVIT_EVENTID);
      /** FW code profile data in response to profile request  */
      RETURN_STRING(WMI_WLAN_PROFILE_DATA_EVENTID);

      /*RTT related event ID*/
      /** RTT measurement report */
      RETURN_STRING(WMI_RTT_MEASUREMENT_REPORT_EVENTID);
      /** TSF measurement report */
      RETURN_STRING(WMI_TSF_MEASUREMENT_REPORT_EVENTID);
      /** RTT error report */
      RETURN_STRING(WMI_RTT_ERROR_REPORT_EVENTID);
      /** RTT keep-alive report */
      RETURN_STRING(WMI_RTT_KEEPALIVE_EVENTID);

      /** WOW wake up host event.generated in response to RETURN_STRING(WMI_WOW_HOSTWAKEUP_FROM_SLEEP_CMDID.
        will cary wake reason */
      RETURN_STRING(WMI_WOW_WAKEUP_HOST_EVENTID);
      /** DCS wlan or non-wlan interference event
      */
      RETURN_STRING(WMI_DCS_INTERFERENCE_EVENTID);

      /** TPC config for the current operating channel */
      RETURN_STRING(WMI_PDEV_TPC_CONFIG_EVENTID);

      RETURN_STRING(WMI_GPIO_INPUT_EVENTID);
      /* add new event IDs here */

      /** Valid rate code list for peer  */
      RETURN_STRING(WMI_PEER_RATECODE_LIST_EVENTID);

      /** Send general buffer content with variable size */
      RETURN_STRING(WMI_GENERIC_BUFFER_EVENTID);

      /* Mcast buffer release event ID */
      RETURN_STRING(WMI_MCAST_BUF_RELEASE_EVENTID);

      /* List of mcast entry aged-out */
      RETURN_STRING(WMI_MCAST_LIST_AGEOUT_EVENTID);
      /** UTF specific WMI event
       * set fixed value for UTF WMI EVT ID so
       * further addition of other WMI EVT IDs
       * does not affect the communication between
       * ART2 and UTF
       */

      RETURN_STRING(WMI_WDS_PEER_EVENTID);

      RETURN_STRING(WMI_PEER_STA_PS_STATECHG_EVENTID);

      RETURN_STRING(WMI_PDEV_UTF_EVENTID);

      default:
        return NULL;
   }
}

char *
wmi_get_cmd_str(WMI_CMD_ID cmd_id)
{
   switch(cmd_id) {
      RETURN_STRING(WMI_END_CMDID);

      RETURN_STRING(WMI_INIT_CMDID);    /**< initialize the wlan sub system */

      /* Scan specific commands */

      /** start scan request to FW  */
      RETURN_STRING(WMI_START_SCAN_CMDID);
      /** stop scan request to FW  */
      RETURN_STRING(WMI_STOP_SCAN_CMDID);
      /** full list of channels as defined by the regulatory that will be used by scanner   */
      RETURN_STRING(WMI_SCAN_CHAN_LIST_CMDID);
      /** echo command mainly used for testing */
      RETURN_STRING(WMI_ECHO_CMDID);

      /* PDEV(physical device) specific commands */
      /** set regulatorty ctl id used by FW to determine the exact ctl power limits */
      RETURN_STRING(WMI_PDEV_SET_REGDOMAIN_CMDID);
      /** set channel. mainly used for supporting monitor mode */
      RETURN_STRING(WMI_PDEV_SET_CHANNEL_CMDID);
      /** set pdev specific parameters */
      RETURN_STRING(WMI_PDEV_SET_PARAM_CMDID);
      /** enable packet log */
      RETURN_STRING(WMI_PDEV_PKTLOG_ENABLE_CMDID);
      /** disable packet log*/
      RETURN_STRING(WMI_PDEV_PKTLOG_DISABLE_CMDID);
      /** set wmm parameters */
      RETURN_STRING(WMI_PDEV_SET_WMM_PARAMS_CMDID);
      /** set HT cap ie that needs to be carried probe requests HT/VHT channels */
      RETURN_STRING(WMI_PDEV_SET_HT_CAP_IE_CMDID);
      /** set VHT cap ie that needs to be carried on probe requests on VHT channels */
      RETURN_STRING(WMI_PDEV_SET_VHT_CAP_IE_CMDID);
      /** set the base MAC address for the physical device */
      RETURN_STRING(WMI_PDEV_SET_BASE_MACADDR_CMDID);

      /** set quiet ie parameters. primarily used in AP mode */
      RETURN_STRING(WMI_PDEV_SET_QUIET_MODE_CMDID);
      /** Enable/Disable Green AP Power Save  */
      RETURN_STRING(WMI_PDEV_GREEN_AP_PS_ENABLE_CMDID);
      /** get TPC config for the current operating channel */
      RETURN_STRING(WMI_PDEV_GET_TPC_CONFIG_CMDID);
      /* VDEV(virtual device) specific commands */
      /** vdev create */
      RETURN_STRING(WMI_VDEV_CREATE_CMDID);
      /** vdev delete */
      RETURN_STRING(WMI_VDEV_DELETE_CMDID);
      /** vdev start request */
      RETURN_STRING(WMI_VDEV_START_REQUEST_CMDID);
      /** vdev restart request (RX only, NO TX, used for CAC period)*/
      RETURN_STRING(WMI_VDEV_RESTART_REQUEST_CMDID);
      /** vdev up request */
      RETURN_STRING(WMI_VDEV_UP_CMDID);
      /** vdev stop request */
      RETURN_STRING(WMI_VDEV_STOP_CMDID);
      /** vdev down request */
      RETURN_STRING(WMI_VDEV_DOWN_CMDID);
      /** vdev stanby response. sent by host in respose to standby request from FW
       *  used part of message exchange with FW to move AP vdev to a new channel
       *  along with STA vdev when the STA vdev moves to a new channel */
      RETURN_STRING(WMI_VDEV_STANDBY_RESPONSE_CMDID);
      /** vdev resume response. sent by host in respose to resume request from FW
       *  used part of message exchange with FW to move AP vdev to a new channel
       *  along with STA vdev when the STA vdev moves to a new channel */
      RETURN_STRING(WMI_VDEV_RESUME_RESPONSE_CMDID);
      /* set a vdev param */
      RETURN_STRING(WMI_VDEV_SET_PARAM_CMDID);
      /* set a key (used for setting per peer unicast and per vdev multicast) */
      RETURN_STRING(WMI_VDEV_INSTALL_KEY_CMDID);

      /** Command to send the DSCP-to-TID map to the target for VAP */
      RETURN_STRING(WMI_VDEV_SET_DSCP_TID_MAP_CMDID);

      /* peer specific commands */

      /** create a peer */
      RETURN_STRING(WMI_PEER_CREATE_CMDID);
      /** delete a peer */
      RETURN_STRING(WMI_PEER_DELETE_CMDID);
      /** flush specific  tid queues of a peer */
      RETURN_STRING(WMI_PEER_FLUSH_TIDS_CMDID);
      /** set a parameter of a peer */
      RETURN_STRING(WMI_PEER_SET_PARAM_CMDID);
      /** set peer to associated state. will cary all parameters determined during assocication time */
      RETURN_STRING(WMI_PEER_ASSOC_CMDID);
      /**add a wds  (4 address ) entry. */
      RETURN_STRING(WMI_PEER_ADD_WDS_ENTRY_CMDID);
      /**update a wds  (4 address ) entry. */
      RETURN_STRING(WMI_PEER_UPDATE_WDS_ENTRY_CMDID);
      /**remove wds  (4 address ) entry. */
      RETURN_STRING(WMI_PEER_REMOVE_WDS_ENTRY_CMDID);
      /** set up mcast group infor for multicast to unicast conversion */
      RETURN_STRING(WMI_PEER_MCAST_GROUP_CMDID);

      /* beacon/management specific commands */

      /** transmit beacon by reference . used for transmitting beacon on low latency interface like pcie */
      RETURN_STRING(WMI_BCN_TX_CMDID);
      /** set the beacon/probe response template. used in beacon offload mode to setup the
       *  the common beacon/probe response template with the FW to be used by FW to generate
       *  beacons/probe responses */
      RETURN_STRING(WMI_BCN_PRB_TMPL_CMDID);
      /** set beacon filter with FW */
      RETURN_STRING(WMI_BCN_FILTER_RX_CMDID);
      /* enable/disable filtering of probe requests in the firmware */
      RETURN_STRING(WMI_PRB_REQ_FILTER_RX_CMDID);
      /** transmit management frame by value. will be deprecated */
      RETURN_STRING(WMI_MGMT_TX_CMDID);

      /** commands to directly control ba negotiation directly from host. only used in test mode */
      RETURN_STRING(WMI_ADDBA_CLEAR_RESP_CMDID);
      /** send add ba request */
      RETURN_STRING(WMI_ADDBA_SEND_CMDID);
      RETURN_STRING(WMI_ADDBA_STATUS_CMDID);
      /** send del ba */
      RETURN_STRING(WMI_DELBA_SEND_CMDID);
      RETURN_STRING(WMI_ADDBA_SET_RESP_CMDID);
      /** send single VHT MPDU with AMSDU */
      RETURN_STRING(WMI_SEND_SINGLEAMSDU_CMDID);

      /** Station power save specific config */
      /** enable/disable station powersave */
      RETURN_STRING(WMI_STA_POWERSAVE_MODE_CMDID);
      /** set station power save specific parameter */
      RETURN_STRING(WMI_STA_POWERSAVE_PARAM_CMDID);
      /** set station mimo powersave mode */
      RETURN_STRING(WMI_STA_MIMO_PS_MODE_CMDID);

      /** set debug log config */
      RETURN_STRING(WMI_DBGLOG_CFG_CMDID);

      /** DFS-specific commands */
      /** enable DFS (radar detection)*/
      RETURN_STRING(WMI_PDEV_DFS_ENABLE_CMDID);
      /** disable DFS (radar detection)*/
      RETURN_STRING(WMI_PDEV_DFS_DISABLE_CMDID);

      /* QVIT specific command id */
      RETURN_STRING(WMI_PDEV_QVIT_CMDID);

      /* Offload Scan and Roaming related  commands */
      /** set roam scan mode */
      RETURN_STRING(WMI_ROAM_SCAN_MODE);
      /** set roam scan rssi threshold below which roam scan is enabled  */
      RETURN_STRING(WMI_ROAM_SCAN_RSSI_THRESHOLD);
      /** set roam scan period for periodic roam scan mode  */
      RETURN_STRING(WMI_ROAM_SCAN_PERIOD);
      /** set roam scan trigger rssi change threshold   */
      RETURN_STRING(WMI_ROAM_SCAN_RSSI_CHANGE_THRESHOLD);
      /** set roam AP profile   */
      RETURN_STRING(WMI_ROAM_AP_PROFILE);
      /** set offload scan AP profile   */
      RETURN_STRING(WMI_OFL_SCAN_ADD_AP_PROFILE);
      /** remove offload scan AP profile   */
      RETURN_STRING(WMI_OFL_SCAN_REMOVE_AP_PROFILE);
      /** set offload scan period   */
      RETURN_STRING(WMI_OFL_SCAN_PERIOD);

      /* P2P specific commands */
      /**set P2P device info. FW will used by FW to create P2P IE to be carried in probe response
       * generated during p2p listen and for p2p discoverability  */
      RETURN_STRING(WMI_P2P_DEV_SET_DEVICE_INFO);
      /** enable/disable p2p discoverability on STA/AP VDEVs  */
      RETURN_STRING(WMI_P2P_DEV_SET_DISCOVERABILITY);
      /** set p2p ie to be carried in beacons generated by FW for GO  */
      RETURN_STRING(WMI_P2P_GO_SET_BEACON_IE);
      /** set p2p ie to be carried in probe response frames generated by FW for GO  */
      RETURN_STRING(WMI_P2P_GO_SET_PROBE_RESP_IE);


      /** AP power save specific config */
      /** set AP power save specific param */
      RETURN_STRING(WMI_AP_PS_PEER_PARAM_CMDID);
      /** set AP UAPSD coex pecific param */
      RETURN_STRING(WMI_AP_PS_PEER_UAPSD_COEX_CMDID);


      /** Rate-control specific commands */
      RETURN_STRING(WMI_PEER_RATE_RETRY_SCHED_CMDID);

      /** WLAN Profiling commands. */
      RETURN_STRING(WMI_WLAN_PROFILE_TRIGGER_CMDID);
      RETURN_STRING(WMI_WLAN_PROFILE_SET_HIST_INTVL_CMDID);
      RETURN_STRING(WMI_WLAN_PROFILE_GET_PROFILE_DATA_CMDID);
      RETURN_STRING(WMI_WLAN_PROFILE_ENABLE_PROFILE_ID_CMDID);
      RETURN_STRING(WMI_WLAN_PROFILE_LIST_PROFILE_ID_CMDID);

      /** Suspend resume command Ids */
      RETURN_STRING(WMI_PDEV_SUSPEND_CMDID);
      RETURN_STRING(WMI_PDEV_RESUME_CMDID);

      /* Beacon filter commands */
      /** add a beacon filter */
      RETURN_STRING(WMI_ADD_BCN_FILTER_CMDID);
      /** remove a  beacon filter */
      RETURN_STRING(WMI_RMV_BCN_FILTER_CMDID);

      /* WOW Specific WMI commands*/
      /** add pattern for awake */
      RETURN_STRING(WMI_WOW_ADD_WAKE_PATTERN_CMDID);
      /** deleta a wake pattern */
      RETURN_STRING(WMI_WOW_DEL_WAKE_PATTERN_CMDID);
      /** enable/deisable wake event  */
      RETURN_STRING(WMI_WOW_ENABLE_DISABLE_WAKE_EVENT_CMDID);
      /** enable WOW  */
      RETURN_STRING(WMI_WOW_ENABLE_CMDID);
      /** host woke up from sleep event to FW. Generated in response to WOW Hardware event */
      RETURN_STRING(WMI_WOW_HOSTWAKEUP_FROM_SLEEP_CMDID);

      /* RTT measurement related cmd */
      /** reques to make an RTT measurement */
      RETURN_STRING(WMI_RTT_MEASREQ_CMDID);
      /** reques to report a tsf measurement */
      RETURN_STRING(WMI_RTT_TSF_CMDID);
      /** request to start/stop keep-alive frame */
      RETURN_STRING(WMI_RTT_KEEPALIVE_CMDID);

      /** transmit beacon by value . used for transmitting beacon both by value */
      RETURN_STRING(WMI_PDEV_SEND_BCN_CMDID);

      /* F/W stats */
      /** configure spectral scan */
      RETURN_STRING(WMI_VDEV_SPECTRAL_SCAN_CONFIGURE_CMDID);
      /** enable/disable spectral scan and trigger */
      RETURN_STRING(WMI_VDEV_SPECTRAL_SCAN_ENABLE_CMDID);
      /** one time request for stats */
      RETURN_STRING(WMI_REQUEST_STATS_CMDID);

      /* GPIO Configuration */
      RETURN_STRING(WMI_GPIO_CONFIG_CMDID);
      RETURN_STRING(WMI_GPIO_OUTPUT_CMDID);
      RETURN_STRING(WMI_VDEV_RATEMASK_CMDID);

      /** Enable/Disable Smart Antenna */
      RETURN_STRING(WMI_PDEV_SMART_ANT_ENABLE_CMDID);
      /** Set Smart Antenna RX antenna*/
      RETURN_STRING(WMI_PDEV_SMART_ANT_SET_RX_ANTENNA_CMDID);
      /** Set Smart Antenna TX antenna*/
      RETURN_STRING(WMI_PEER_SMART_ANT_SET_TX_ANTENNA_CMDID);
      /** Set Smart Antenna TX train info */
      RETURN_STRING(WMI_PEER_SMART_ANT_SET_TRAIN_INFO_CMDID);
      /** Set SA node config options */
      RETURN_STRING(WMI_PEER_SMART_ANT_SET_NODE_CONFIG_OPS_CMDID);
      /* For fw recovery test command */
      RETURN_STRING(WMI_FORCE_FW_HANG_CMDID);

      /** Override the antenna switch table */
      RETURN_STRING(WMI_PDEV_SET_ANTENNA_SWITCH_TABLE_CMDID);
      /** Override the CTL table */
      RETURN_STRING(WMI_PDEV_SET_CTL_TABLE_CMDID);
      /** Override the array gain table */
      RETURN_STRING(WMI_PDEV_SET_MIMOGAIN_TABLE_CMDID);
      /** Set/Get the rate power table in OTP */
      RETURN_STRING(WMI_PDEV_RATEPWR_TABLE_CMDID);
      /** En/disable the rate power and chain mask table in FW*/
      RETURN_STRING(WMI_PDEV_RATEPWR_CHAINMSK_TABLE_CMDID);

      /* add new CMDIDs here */

      /** UTF specific WMI commands
       * set fixed value for UTF WMI command so
       * further addition of other WMI commands
       * does not affect the communication between
       * ART2 and UTF
       */
      RETURN_STRING(WMI_PDEV_UTF_CMDID);

      default:
        return NULL;
   }
}

/* WMI command API */
int
wmi_unified_cmd_send(wmi_unified_t wmi_handle, wmi_buf_t buf, int len, WMI_CMD_ID cmd_id)
{
    A_STATUS status;
    struct cookie *cookie;
    char *cmd_str;

    if (wbuf_push(buf, sizeof(WMI_CMD_HDR)) == NULL) {
        wbuf_free(buf);
        return -ENOMEM;
    }

    if (wmi_handle->wmi_stopinprogress) {
        printk("WMI  stop in progress \n");
        wbuf_free(buf);
        return -ENOMEM;
    }

    WMI_SET_FIELD(wbuf_header(buf), WMI_CMD_HDR, COMMANDID, cmd_id);
    //WMI_CMD_HDR_SET_DEVID(cmd_hdr, 0); // unused

    cookie = ol_alloc_cookie(wmi_handle->scn_handle);
    if (!cookie) {
        printk("%s : Cookie alloc Failed for cmd_id : %0x \n",__func__,cmd_id);
        wbuf_free(buf);
        return -ENOMEM;
    }

    cookie->PacketContext = buf;
    SET_HTC_PACKET_INFO_TX(&cookie->HtcPkt,
                           cookie,
                           wbuf_header(buf),
                           len+sizeof(WMI_CMD_HDR),
                           /* htt_host_data_dl_len(buf)+20 */
                           wmi_handle->wmi_endpoint_id,
                           0/*htc_tag*/);

    SET_HTC_PACKET_NET_BUF_CONTEXT(&cookie->HtcPkt, buf);

    cmd_str = wmi_get_cmd_str(cmd_id);
    if (cmd_str != NULL && cmd_id != WMI_PDEV_SEND_BCN_CMDID &&
          cmd_id != WMI_MGMT_TX_CMDID) {
       adf_os_spin_lock_bh(&wmi_debug_lock);
       wmi_debug_buf_g[wmi_count_g].data = cmd_id;
       wmi_debug_buf_g[wmi_count_g].flag |= WMI_FLAG_COMMAND;
       wmi_count_g++;
       if (wmi_count_g == WMI_BUFFER_LEN)
          wmi_count_g = 0;
       adf_os_spin_unlock_bh(&wmi_debug_lock);
    }

    status = HTCSendPkt(wmi_handle->htc_handle, &cookie->HtcPkt);

    if (status != A_OK) {
        ol_free_cookie(wmi_handle->scn_handle, cookie);
        wbuf_free(buf);
    }

    return ((status == A_OK) ? EOK : -1);
}

void wmi_display_cmd_event(void )
{
   unsigned char count, end;
   char *str = NULL;

   count = wmi_count_g;
   end = WMI_BUFFER_LEN;

   printk("\n\nWMI command and events:\n");
   adf_os_spin_lock_bh(&wmi_debug_lock);
   while(end--) {
      if (wmi_debug_buf_g[count].flag & WMI_FLAG_COMMAND)
         str = wmi_get_cmd_str(wmi_debug_buf_g[count].data);
      else if (wmi_debug_buf_g[count].flag & WMI_FLAG_EVENT)
         str = wmi_get_event_str(wmi_debug_buf_g[count].data);
      if (str != NULL)
          printk("%s\n", str);
      str = NULL;
      count++;
      if (count == WMI_BUFFER_LEN)
         count = 0;
   }
   adf_os_spin_unlock_bh(&wmi_debug_lock);
}

/* WMI Event handler register API */

int wmi_unified_register_event_handler(wmi_unified_t wmi_handle,
                                       WMI_EVT_ID event_id,
                                       wmi_unified_event_handler handler_func,
                                       void* cookie)
{
    u_int16_t handler_id;
    handler_id = (event_id - WMI_START_EVENTID);
    if (handler_id >= WMI_UNIFIED_MAX_EVENT) {
        printk("%s : unkown event id : 0x%x  event handler id 0x%x \n",
                __func__, event_id, handler_id);
        return -1;
    }
    if (wmi_handle->event_handler[handler_id]) {
        printk("%s : event handler is already registered: event id 0x%x \n",
                __func__, event_id);
        return -1;
    }
    wmi_handle->event_handler[handler_id] = handler_func;
    wmi_handle->event_handler_cookie[handler_id] = cookie;
    return 0;
}

int wmi_unified_unregister_event_handler(wmi_unified_t wmi_handle,
                                       WMI_EVT_ID event_id)
{
    u_int16_t handler_id;
    handler_id = (event_id - WMI_START_EVENTID);
    if (handler_id >= WMI_UNIFIED_MAX_EVENT) {
        printk("%s : unkown event id : 0x%x  event handler id 0x%x \n",
                __func__, event_id, handler_id);
        return -1;
    }
    if (wmi_handle->event_handler[handler_id] == NULL) {
        printk("%s : event handler is not registered: event id 0x%x \n",
                __func__, event_id);
        return -1;
    }
    wmi_handle->event_handler[handler_id] = NULL;
    wmi_handle->event_handler_cookie[handler_id] = NULL;
    return 0;
}


static int wmi_unified_event_rx(struct wmi_unified *wmi_handle, wmi_buf_t evt_buf)
{
    u_int16_t id;
    u_int8_t *event;
    u_int16_t len;
    int status = -1;
    u_int16_t handler_id;
    char *event_str;

    ASSERT(evt_buf != NULL);

    id = WMI_GET_FIELD(wbuf_header(evt_buf), WMI_CMD_HDR, COMMANDID);
    handler_id = (id - WMI_START_EVENTID);

    if (wbuf_pull(evt_buf, sizeof(WMI_CMD_HDR)) == NULL) {
        //A_DPRINTF(DBG_WMI, (DBGFMT "bad packet 1\n", DBGARG));
        //wmip->wmi_stats.cmd_len_err++;
        goto end;
    }
    if (handler_id >= WMI_UNIFIED_MAX_EVENT) {
        printk("%s : unkown event id : 0x%x  event handler id 0x%x \n",
                __func__, id, handler_id);
        goto end;
    }

    event = wbuf_header(evt_buf);
    len = wbuf_get_pktlen(evt_buf);


    if (!wmi_handle->event_handler[handler_id]) {
        printk("%s : no registered event handler : event id 0x%x \n",
                __func__, id);
        goto end;
    }

    event_str = wmi_get_event_str(id);
    if (event_str != NULL && id != WMI_MGMT_RX_EVENTID && id != WMI_HOST_SWBA_EVENTID &&
          id != WMI_UPDATE_STATS_EVENTID) {
       adf_os_spin_lock_bh(&wmi_debug_lock);
       wmi_debug_buf_g[wmi_count_g].data = id;
       wmi_debug_buf_g[wmi_count_g].flag |= WMI_FLAG_EVENT;
       wmi_count_g++;
       if (wmi_count_g == WMI_BUFFER_LEN)
          wmi_count_g = 0;
       adf_os_spin_unlock_bh(&wmi_debug_lock);
    }

    /* Call the WMI registered event handler */
    status = wmi_handle->event_handler[handler_id](wmi_handle->scn_handle, event, len,
                                           wmi_handle->event_handler_cookie[handler_id]);

end:
    wbuf_free(evt_buf);
    return status;
}

static int
wmi_service_ready_event_rx(struct wmi_unified *wmi_handle, A_UINT8 *datap, int len)
{
    wmi_service_ready_event *ev = (wmi_service_ready_event *)datap;

    if (len < sizeof(wmi_service_ready_event)) {
        printk("%s:  WMI UNIFIED SERVICE READY event - invalid length \n", __func__);
        return A_EINVAL;
    }

    printk("%s:  WMI UNIFIED SERVICE READY event \n", __func__);
    ol_ath_service_ready_event(wmi_handle->scn_handle, ev);

    return A_OK;
}

static int
wmi_ready_event_rx(struct wmi_unified *wmi_handle, A_UINT8 *datap, int len)
{
    wmi_ready_event *ev = (wmi_ready_event *)datap;

    if (len < sizeof(wmi_ready_event)) {
        printk("%s:  WMI UNIFIED READY event - invalid length \n", __func__);
        return A_EINVAL;
    }

    printk("%s:  WMI UNIFIED READY event \n", __func__);
    ol_ath_ready_event(wmi_handle->scn_handle, ev);


    return A_OK;
}

/*
 * Temporarily added to support older WMI events. We should move all events to unified
 * when the target is ready to support it.
 */
void
wmi_control_rx(void *ctx, HTC_PACKET *htc_packet)
{
    u_int16_t id;
    u_int8_t *data;
    u_int32_t len;
    int status = EOK;
    wmi_buf_t evt_buf;
    struct wmi_unified *wmi_handle = (struct wmi_unified *) ctx;

    evt_buf =  (wmi_buf_t)  htc_packet->pPktContext;

    /**
     * This is  a HACK due to a Hack/WAR in HTC !!.
     * the head of the wbuf still contains the HTC header
     * but the length excludes htc header.
     */
    wbuf_set_pktlen(evt_buf, htc_packet->ActualLength +  HTC_HEADER_LEN);
    wbuf_pull(evt_buf, HTC_HEADER_LEN);

    id = WMI_GET_FIELD(wbuf_header(evt_buf), WMI_CMD_HDR, COMMANDID);

    if ((id >= WMI_START_EVENTID) && (id <= WMI_END_EVENTID)) {
        status = wmi_unified_event_rx(wmi_handle, evt_buf);
        return ;
    }

    if (wbuf_pull(evt_buf, sizeof(WMI_CMD_HDR)) == NULL) {
        status = -1;
        goto end;
    }

    data = wbuf_header(evt_buf);
    len = wbuf_get_pktlen(evt_buf);

    switch(id)
    {
        default:
            printk("%s: Unhandled WMI command %d\n", __func__, id);
            break;
        case WMI_SERVICE_READY_EVENTID:
            status = wmi_service_ready_event_rx(wmi_handle, data, len);
            break;
        case WMI_READY_EVENTID:
            status = wmi_ready_event_rx(wmi_handle, data, len);
            break;
        case WMI_WLAN_VERSION_EVENTID:
            printk("%s: Handle WMI_VERSION_EVENTID\n", __func__);
            break;
        case WMI_REGDOMAIN_EVENTID:
            printk("%s: Handle WMI_REGDOMAIN_EVENTID\n", __func__);
            break;
        case WMI_DEBUG_MESG_EVENTID:
            dbglog_message_handler(wmi_handle->scn_handle, evt_buf);
            return;
    }

end:
    wbuf_free(evt_buf);
}

/* WMI Initialization functions */

void *
wmi_unified_attach(ol_scn_t scn_handle, osdev_t osdev)
{
    struct wmi_unified *wmi_handle;
    wmi_handle = (struct wmi_unified *)OS_MALLOC(osdev, sizeof(struct wmi_unified), GFP_ATOMIC);
    if (wmi_handle == NULL) {
        printk("allocation of wmi handle failed %d \n",sizeof(struct wmi_unified));
        return NULL;
    }
    OS_MEMZERO(wmi_handle, sizeof(struct wmi_unified));
    wmi_handle->scn_handle = scn_handle;
    wmi_handle->osdev = osdev;
    adf_os_spinlock_init(&wmi_debug_lock);
    OS_MEMZERO(wmi_debug_buf_g, sizeof(wmi_debug_buf_g));
    return wmi_handle;
}

void
wmi_unified_detach(struct wmi_unified* wmi_handle)
{
    if (wmi_handle != NULL) {
        OS_FREE(wmi_handle);
        wmi_handle = NULL;
    }
}

void   wmi_htc_tx_complete(void *ctx,HTC_PACKET *htc_pkt)
{

    wmi_buf_t wmi_cmd_buf=GET_HTC_PACKET_NET_BUF_CONTEXT(htc_pkt);
    struct wmi_unified *wmi_handle = (struct wmi_unified *)ctx;
    struct cookie *cookie = htc_pkt->pPktContext;

    ASSERT(wmi_cmd_buf);
    wbuf_free(wmi_cmd_buf);
    ol_free_cookie(wmi_handle->scn_handle , cookie);
    return;
}

int
wmi_unified_connect_htc_service(struct wmi_unified * wmi_handle, void *htc_handle)
{

    int status;
    HTC_SERVICE_CONNECT_RESP response;
    HTC_SERVICE_CONNECT_REQ connect;

    OS_MEMZERO(&connect, sizeof(connect));
    OS_MEMZERO(&response, sizeof(response));

    /* meta data is unused for now */
    connect.pMetaData = NULL;
    connect.MetaDataLength = 0;
    /* these fields are the same for all service endpoints */
    connect.EpCallbacks.pContext = wmi_handle;
    connect.EpCallbacks.EpTxCompleteMultiple = NULL /* Control path completion ar6000_tx_complete */;
    connect.EpCallbacks.EpRecv = wmi_control_rx /* Control path rx */;
    connect.EpCallbacks.EpRecvRefill = NULL /* ar6000_rx_refill */;
    connect.EpCallbacks.EpSendFull = NULL /* ar6000_tx_queue_full */;
    connect.EpCallbacks.EpTxComplete = wmi_htc_tx_complete /* ar6000_tx_queue_full */;

    /* connect to control service */
    connect.ServiceID = WMI_CONTROL_SVC;

    if ((status = HTCConnectService(htc_handle, &connect, &response)) != EOK)
    {
        printk(" Failed to connect to WMI CONTROL  service status:%d \n",  status);
        return -1;;
    }
    wmi_handle->wmi_endpoint_id = response.Endpoint;
    wmi_handle->htc_handle = htc_handle;

    return EOK;
}


ol_scn_t wmi_get_scn_handle(struct wmi_unified *wmi_handle)
{
    return wmi_handle->scn_handle;
}
#endif
