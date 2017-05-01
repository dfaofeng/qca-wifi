/*
* Copyright (c) 2013 Qualcomm Atheros, Inc..
* All Rights Reserved.
* Qualcomm Atheros Confidential and Proprietary.
*/

#if UNIFIED_SMARTANTENNA

#include <ieee80211_var.h>
#include <ol_if_athvar.h>
#include <if_smart_ant.h>
#include <ieee80211_smart_ant_api.h>
#include <ol_txrx_types.h>
#include "ol_tx_desc.h"
#include "ol_if_smart_ant.h"


/* This will be registered when smart antenna is not enabled. So that WMI doesnt print
 * unhandled message.
 */
static int
wmi_unified_smart_ant_assoc_dummy_handler(ol_scn_t scn, u_int8_t *data, u_int16_t datalen, void *context)
{
    return 0;
}

static int
wmi_unified_smart_ant_assoc_handler(ol_scn_t scn, u_int8_t *data, u_int16_t datalen, void *context)
{
    struct ieee80211com *ic = &scn->sc_ic;
    A_UINT8 peer_macaddr[ATH_MAC_LEN];
    struct ieee80211_node *ni = NULL;
    struct sa_rate_cap rate_cap;
    int htindex = 0, i, j;
    uint8_t shift =0;
    wmi_peer_ratecode_list_event_t *rate_event = (wmi_peer_ratecode_list_event_t *)data;
    WMI_MAC_ADDR_TO_CHAR_ARRAY(&rate_event->peer_macaddr,peer_macaddr);

    ni = ieee80211_find_node(&ic->ic_sta, peer_macaddr);
    if (!ni) {
        return -1;
    }

    htindex = 0;
    rate_cap.ratecount[0] = ((rate_event->peer_rate_info.ratecount) & MASK_BYTE);
    rate_cap.ratecount[1] = ((rate_event->peer_rate_info.ratecount >> 8) & MASK_BYTE);
    rate_cap.ratecount[2] = ((rate_event->peer_rate_info.ratecount >> 16) & MASK_BYTE);
    rate_cap.ratecount[3] = ((rate_event->peer_rate_info.ratecount >> 24) & MASK_BYTE);

    if (rate_cap.ratecount[0]) {
        for (i = 0; i < MAX_LEGACY_RATE_DWORDS; i++) {
            for (j = 0;j < BYTES_IN_DWORD; j++) {
                rate_cap.ratecode_legacy[htindex] = ((rate_event->peer_rate_info.ratecode_legacy[i] >> (8*j)) & MASK_BYTE);
                htindex++;
            }
        }
    }

    htindex = 0;
    for (i = 0; i < MAX_HT_RATE_DWORDS; i++) {
        for (j = 0; j < BYTES_IN_DWORD; j++) {
            shift = (8*j);
            rate_cap.ratecode_20[htindex] = ((rate_event->peer_rate_info.ratecode_20[i] >> (shift)) & MASK_BYTE);
            rate_cap.ratecode_40[htindex] = ((rate_event->peer_rate_info.ratecode_40[i] >> (shift)) & MASK_BYTE);
            rate_cap.ratecode_80[htindex] = ((rate_event->peer_rate_info.ratecode_80[i] >> (shift)) & MASK_BYTE);
            htindex++;
        }
    }

    /* node connect */
    ieee80211_smart_ant_node_connect(ni, &rate_cap);
    ieee80211_free_node(ni);
    return 0;
}

void ol_ath_smart_ant_enable(struct ieee80211com *ic, int enable, int mode, uint32_t rx_antenna)
{
    /* Send WMI COMMAND to Enable */
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_pdev_smart_ant_enable_cmd *cmd;
    wmi_buf_t buf;
    int len = 0;
    int ret;
    len = sizeof(wmi_pdev_smart_ant_enable_cmd);
    buf = wmi_buf_alloc(scn->wmi_handle, len);
    if (!buf) {
        adf_os_print("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return ;
    }

    cmd = (wmi_pdev_smart_ant_enable_cmd *)wmi_buf_data(buf);
    cmd->enable = enable & SMART_ANT_ENABLE_MASK;
    cmd->mode = mode;
    cmd->rx_antenna = rx_antenna;
    cmd->tx_default_antenna = rx_antenna;
    if (mode == SMART_ANT_MODE_SERIAL) {
        cmd->gpio_pin[0] = ATH_GPIOPIN_ANT_SERIAL_STROBE_RADIO1;
        cmd->gpio_pin[1] = ATH_GPIOPIN_ANT_SERIAL_DATA_RADIO1;
        cmd->gpio_pin[2] = 0;
        cmd->gpio_pin[3] = 0;

        cmd->gpio_func[0] = ATH_GPIOFUNC_ANT_SERIAL_STROBE_RADIO1;
        cmd->gpio_func[1] = ATH_GPIOFUNC_ANT_SERIAL_DATA_RADIO1;
        cmd->gpio_func[2] = 0;
        cmd->gpio_func[3] = 0;
    } else if (mode == SMART_ANT_MODE_PARALLEL){
        cmd->gpio_pin[0] = ATH_GPIOPIN_ANTCHAIN0_RADIO1;
        cmd->gpio_pin[1] = ATH_GPIOPIN_ANTCHAIN1_RADIO1;
        cmd->gpio_pin[2] = ATH_GPIOPIN_ANTCHAIN2_RADIO1;
        cmd->gpio_pin[3] = 0;

        cmd->gpio_func[0] = ATH_GPIOFUNC_ANTCHAIN0_RADIO1;
        cmd->gpio_func[1] = ATH_GPIOFUNC_ANTCHAIN1_RADIO1;
        cmd->gpio_func[2] = ATH_GPIOFUNC_ANTCHAIN2_RADIO1;
        cmd->gpio_func[3] = 0;
    }

    ret = wmi_unified_cmd_send(scn->wmi_handle,
                               buf,
                               len,
                               WMI_PDEV_SMART_ANT_ENABLE_CMDID);


    /* Enable txfeed back to receive TX Control and Status descriptors from target */
    if( ret == 0) {
        if (enable) {
            if (enable & SMART_ANT_TX_FEEDBACK_MASK) {
                ol_ath_smart_ant_enable_txfeedback(ic, 1);
            }
        } else {
            ol_ath_smart_ant_enable_txfeedback(ic, 0);
        }
    } else {
        adf_os_print(" %s :WMI Failed \n", __func__);
        adf_os_print("%s: Sent WMI_PDEV_SMART_ANT_ENABLE_CMDID.\n"
                "enable:%d mode:%d  rx_antenna: 0x%08x PINS: [%d %d %d %d] Func[%d %d %d %d] cmdstatus=%d\n",
                __FUNCTION__,
                cmd->enable,
                cmd->mode,
                cmd->rx_antenna,
                cmd->gpio_pin[0], cmd->gpio_pin[1], cmd->gpio_pin[2], cmd->gpio_pin[3],
                cmd->gpio_func[0], cmd->gpio_func[1], cmd->gpio_func[2], cmd->gpio_func[3],
                ret);

    }
}

void ol_ath_smart_ant_set_rx_antenna(struct ieee80211com *ic, u_int32_t antenna)
{

    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_pdev_smart_ant_set_rx_antenna_cmd *cmd;
    wmi_buf_t buf;
    int len = 0;
    int ret;

    len = sizeof(wmi_pdev_smart_ant_set_rx_antenna_cmd);
    buf = wmi_buf_alloc(scn->wmi_handle, len);
    if (!buf) {
        adf_os_print("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return ;
    }

    cmd = (wmi_pdev_smart_ant_set_rx_antenna_cmd *)wmi_buf_data(buf);
    cmd->rx_antenna = antenna;
    ret = wmi_unified_cmd_send(scn->wmi_handle,
                               buf,
                               len,
                               WMI_PDEV_SMART_ANT_SET_RX_ANTENNA_CMDID);

    if (ret != 0) {
        adf_os_print(" %s :WMI Failed \n", __func__);
        adf_os_print("%s: Sent WMI_PDEV_SMART_ANT_SET_RX_ANTENNA_CMDID. \n"
                " rx_antenna: 0x%08x cmdstatus=%d\n",
                __FUNCTION__,
                cmd->rx_antenna,
                ret);
    }
}
/*
* TODO: As of now both RX antenna and TX default antenna are same.
* So call RX antena function and in future if required need to add a WMI for the same.
*/
void ol_ath_smart_ant_set_tx_default_antenna(struct ieee80211com *ic, u_int32_t antenna)
{
    ol_ath_smart_ant_set_rx_antenna(ic, antenna);
}

void ol_ath_smart_ant_set_tx_antenna(struct ieee80211_node *ni, u_int32_t *antenna_array)
{
    struct ieee80211com *ic = ni->ni_ic;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    struct ol_ath_vap_net80211 *avn = OL_ATH_VAP_NET80211(ni->ni_vap);
    wmi_peer_sant_set_tx_antenna_cmd *cmd;
    wmi_buf_t buf;
    int len = 0;
    int ret;

    len = sizeof(wmi_peer_sant_set_tx_antenna_cmd);
    buf = wmi_buf_alloc(scn->wmi_handle, len);
    if (!buf) {
        adf_os_print("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return ;
    }

    cmd = (wmi_peer_sant_set_tx_antenna_cmd *)wmi_buf_data(buf);
    cmd->vdev_id = avn->av_if_id;
    WMI_CHAR_ARRAY_TO_MAC_ADDR(ni->ni_macaddr, &cmd->peer_macaddr);

    cmd->antenna_series[0] = antenna_array[0];
    cmd->antenna_series[1] = antenna_array[1];
    ret = wmi_unified_cmd_send(scn->wmi_handle,
                               buf,
                               len,
                               WMI_PEER_SMART_ANT_SET_TX_ANTENNA_CMDID);

    if (ret != 0) {
        adf_os_print(" %s :WMI Failed \n", __func__);
        adf_os_print("%s: Sent WMI_PEER_SMART_ANT_SET_TX_ANTENNA_CMDID. \n"
                " Node: %s tx_antennas: [0x%08x 0x%08x] cmdstatus=%d\n",
                __FUNCTION__,
                ether_sprintf(ni->ni_macaddr),
                cmd->antenna_series[0],
                cmd->antenna_series[1],
                ret);
    }

}

void ol_ath_smart_ant_set_training_info(struct ieee80211_node *ni, uint32_t *rate_array, uint32_t *antenna_array, uint32_t numpkts)
{
    struct ieee80211com *ic = ni->ni_ic;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    struct ol_ath_vap_net80211 *avn = OL_ATH_VAP_NET80211(ni->ni_vap);
    wmi_peer_sant_set_train_antenna_cmd *cmd;
    wmi_buf_t buf;
    int len = 0;
    int ret;

    len = sizeof(wmi_peer_sant_set_train_antenna_cmd);
    buf = wmi_buf_alloc(scn->wmi_handle, len);
    if (!buf) {
        adf_os_print("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return ;
    }

    cmd = (wmi_peer_sant_set_train_antenna_cmd *)wmi_buf_data(buf);
    cmd->vdev_id = avn->av_if_id;
    WMI_CHAR_ARRAY_TO_MAC_ADDR(ni->ni_macaddr, &cmd->peer_macaddr);
    OS_MEMCPY(&cmd->train_rate_series[0], &rate_array[0], (sizeof(uint32_t)*SMART_ANT_MAX_RATE_SERIES));
    OS_MEMCPY(& cmd->train_antenna_series[0], &antenna_array[0], (sizeof(uint32_t)*SMART_ANT_MAX_RATE_SERIES));
    cmd->num_pkts = numpkts;
    ret = wmi_unified_cmd_send(scn->wmi_handle,
                               buf,
                               len,
                               WMI_PEER_SMART_ANT_SET_TRAIN_INFO_CMDID);

    if (ret != 0) {
        adf_os_print(" %s :WMI Failed \n", __func__);
        adf_os_print("%s: Sent WMI_PEER_SMART_ANT_SET_TRAIN_INFO_CMDID. \n"
                " Train Node: %s rate_array[0x%02x 0x%02x] tx_antennas: [0x%08x 0x%08x] cmdstatus=%d \n",
                __FUNCTION__,
                ether_sprintf(ni->ni_macaddr),
                cmd->train_rate_series[0], cmd->train_rate_series[1],
                cmd->train_antenna_series[0],cmd->train_antenna_series[1],
                ret);
    }

}


void ol_ath_smart_ant_set_node_config_ops(struct ieee80211_node *ni, uint32_t cmd_id, uint16_t args_count, u_int32_t args_arr[])
{
    struct ieee80211com *ic = ni->ni_ic;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    struct ol_ath_vap_net80211 *avn = OL_ATH_VAP_NET80211(ni->ni_vap);
    wmi_peer_sant_set_node_config_ops_cmd *cmd;
    wmi_buf_t buf;
    int len = 0;
    int ret;
    int i = 0;

    len = sizeof(wmi_peer_sant_set_node_config_ops_cmd);

    if ((args_count == 0) || (args_count > (sizeof(cmd->args) / sizeof(cmd->args[0])))) {
        adf_os_print("%s: Can't send a command with %d arguments\n", __FUNCTION__, args_count);
	return;
    }

    buf = wmi_buf_alloc(scn->wmi_handle, len);
    if (!buf) {
        adf_os_print("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return ;
    }

    cmd = (wmi_peer_sant_set_node_config_ops_cmd *)wmi_buf_data(buf);
    cmd->vdev_id = avn->av_if_id;
    WMI_CHAR_ARRAY_TO_MAC_ADDR(ni->ni_macaddr, &cmd->peer_macaddr);
    cmd->cmd_id = cmd_id;
    cmd->args_count = args_count;
    for (i = 0; i < args_count; i++) {
        cmd->args[i] = args_arr[i];
    }

    ret = wmi_unified_cmd_send(scn->wmi_handle,
                               buf,
                               len,
                               WMI_PEER_SMART_ANT_SET_NODE_CONFIG_OPS_CMDID);

    if (ret != 0) {
        adf_os_print(" %s :WMI Failed \n", __func__);
        adf_os_print("%s: Sent WMI_PEER_SMART_ANT_SET_NODE_CONFIG_OPS_CMDID, cmd_id: 0x%x \n"
            " Node: %s cmdstatus=%d\n", __FUNCTION__, cmd_id, ether_sprintf(ni->ni_macaddr), ret);
    }
}



int ol_ath_smart_ant_rxfeedback(struct ol_txrx_pdev_t *pdev, struct ol_txrx_peer_t *peer, struct  sa_rx_feedback *rx_feedback)
{
    struct ol_txrx_vdev_t *vdev = NULL;
    struct ieee80211vap *vap = NULL;
    struct ieee80211_node *ni = NULL;
    int status = -1;
    struct ol_ath_softc_net80211 *scn =
        (struct ol_ath_softc_net80211 *)pdev->ctrl_pdev;

    vdev = peer->vdev;
    vap = ol_ath_vap_get(scn, vdev->vdev_id);
    if(!vap)
        return status;
    ni = ieee80211_find_node(&vap->iv_ic->ic_sta,
            peer->mac_addr.raw);
    if (ni) {
        status = ieee80211_smart_ant_update_rxfeedback(ni, rx_feedback);
        ieee80211_free_node(ni);
    }
    return status;
}

A_STATUS
ol_ath_smart_ant_get_txfeedback (void *pdev, enum WDI_EVENT event, void *data,
                                 uint16_t peer_id, enum htt_tx_status status)
{
    struct ath_smart_ant_pktlog_hdr pl_hdr;
    uint32_t *pl_tgt_hdr;
    int txstatus = 0;
    int i = 0;
    struct sa_tx_feedback tx_feedback;
    struct ol_txrx_pdev_t *txrx_pdev = (struct ol_txrx_pdev_t *)pdev;
    struct ol_ath_softc_net80211 *scn = NULL;
    struct ieee80211com *ic = NULL;
    struct ol_txrx_peer_t *peer;
    struct ieee80211vap *vap = NULL;
    struct ieee80211_node *ni = NULL;

    if (!txrx_pdev) {
        adf_os_print("Invalid pdev in %s\n", __func__);
        return A_ERROR;
    }
    scn = (struct ol_ath_softc_net80211 *)txrx_pdev->ctrl_pdev;
    ic  = &scn->sc_ic;

    if (event != WDI_EVENT_TX_STATUS) {
        adf_os_print("%s: Un Subscribed Event: %d \n", __func__, event);
        return 0;
    }

    if (!txrx_pdev) {
        adf_os_print("Invalid pdev in %s\n", __func__);
        return A_ERROR;
    }

    pl_tgt_hdr = (uint32_t *)data;
    pl_hdr.log_type =  (*(pl_tgt_hdr + ATH_SMART_ANT_PKTLOG_HDR_LOG_TYPE_OFFSET) &
                                        ATH_SMART_ANT_PKTLOG_HDR_LOG_TYPE_MASK) >>
                                        ATH_SMART_ANT_PKTLOG_HDR_LOG_TYPE_SHIFT;

    if ((pl_hdr.log_type == SMART_ANT_PKTLOG_TYPE_TX_CTRL)) {
        int frame_type;
        int peer_id;
        void *tx_ppdu_ctrl_desc;
        u_int32_t *tx_ctrl_ppdu, try_status = 0;
        uint8_t total_tries =0, sbw_indx_succ = 0;
        tx_ppdu_ctrl_desc = (void *)data + sizeof(struct ath_smart_ant_pktlog_hdr);

        tx_ctrl_ppdu = (u_int32_t *)tx_ppdu_ctrl_desc;

        peer_id = tx_ctrl_ppdu[TX_PEER_ID_OFFSET];

        frame_type = (tx_ctrl_ppdu[TX_FRAME_OFFSET]
                          & TX_FRAME_TYPE_MASK) >> TX_FRAME_TYPE_SHIFT;

        if (frame_type == TX_FRAME_TYPE_DATA) { /* data frame */

            if (ic->tx_ppdu_end[SMART_ANT_FEEDBACK_OFFSET] == 0) {
                return A_ERROR;
            }

            peer = (peer_id == HTT_INVALID_PEER) ?
                NULL : txrx_pdev->peer_id_to_obj_map[peer_id];
            if (peer && !(peer->bss_peer)) {

                ni = ieee80211_find_node(&ic->ic_sta, peer->mac_addr.raw);
                if (!ni) {
                    return A_ERROR;
                }

                total_tries = (ic->tx_ppdu_end[TX_TOTAL_TRIES_OFFSET] & TX_TOTAL_TRIES_MASK) >> TX_TOTAL_TRIES_SHIFT;

                OS_MEMZERO(&tx_feedback, sizeof(tx_feedback));
                tx_feedback.nPackets = (ic->tx_ppdu_end[SMART_ANT_FEEDBACK_OFFSET] & 0xffff);
                tx_feedback.nBad = (ic->tx_ppdu_end[SMART_ANT_FEEDBACK_OFFSET] & 0x1fff0000) >> 16;

                /* Rate code and Antenna values */
                tx_feedback.tx_antenna[0] = (tx_ctrl_ppdu[TX_ANT_OFFSET_S0] & TX_ANT_MASK);
                tx_feedback.tx_antenna[1] = (tx_ctrl_ppdu[TX_ANT_OFFSET_S1] & TX_ANT_MASK);

                /* RateCode */
                tx_feedback.rate_mcs[0] = ((tx_ctrl_ppdu[TXCTRL_S0_RATE_BW20_OFFSET] & TXCTRL_RATE_MASK) >> 24) |
                                          ((tx_ctrl_ppdu[TXCTRL_S0_RATE_BW40_OFFSET] & TXCTRL_RATE_MASK) >> 16) |
                                          ((tx_ctrl_ppdu[TXCTRL_S0_RATE_BW80_OFFSET] & TXCTRL_RATE_MASK) >> 8) |
                                          (tx_ctrl_ppdu[TXCTRL_S0_RATE_BW160_OFFSET] & TXCTRL_RATE_MASK);

                tx_feedback.rate_mcs[1] = ((tx_ctrl_ppdu[TXCTRL_S1_RATE_BW20_OFFSET] & TXCTRL_RATE_MASK) >> 24) |
                                          ((tx_ctrl_ppdu[TXCTRL_S1_RATE_BW40_OFFSET] & TXCTRL_RATE_MASK) >> 16) |
                                          ((tx_ctrl_ppdu[TXCTRL_S1_RATE_BW80_OFFSET] & TXCTRL_RATE_MASK) >> 8) |
                                          (tx_ctrl_ppdu[TXCTRL_S1_RATE_BW160_OFFSET] & TXCTRL_RATE_MASK);


                if (ic->ic_smart_ant_mode == SMART_ANT_MODE_SERIAL) {
                /* Extract and fill */
                /* index0 - s0_bw20, index1 - s0_bw40  index4 - s1_bw20 ... index7: s1_bw160 */
                for (i = 0; i < MAX_RETRIES; i++) {
                        tx_feedback.nlong_retries[i] =  ((ic->tx_ppdu_end[LONG_RETRIES_OFFSET] >> (i*4)) & 0x0f);
                        tx_feedback.nshort_retries[i] = ((ic->tx_ppdu_end[SHORT_RETRIES_OFFSET] >> (i*4)) & 0x0f);

                    /* HW gives try counts and for SA module we need to provide failure counts
                     * So manipulate short failure count accordingly.
                     */
                    if (tx_feedback.nlong_retries[i]) {
                        if (tx_feedback.nshort_retries[i] == tx_feedback.nlong_retries[i]) {
                            tx_feedback.nshort_retries[i]--;
                        }
                    }
                }
                }
                /* ACK RSSI */
                tx_feedback.rssi[0] = ic->tx_ppdu_end[ACK_RSSI0_OFFSET];
                tx_feedback.rssi[1] = ic->tx_ppdu_end[ACK_RSSI1_OFFSET];
                tx_feedback.rssi[2] = ic->tx_ppdu_end[ACK_RSSI2_OFFSET];
                tx_feedback.rssi[3] = ic->tx_ppdu_end[ACK_RSSI3_OFFSET];

                try_status = ic->tx_ppdu_end[total_tries-1];
                sbw_indx_succ = (try_status & TX_TRY_SERIES_MASK)?NUM_DYN_BW_MAX:0;
                sbw_indx_succ += ((try_status & TX_TRY_BW_MASK) >> TX_TRY_BW_SHIFT);
                if (ic->ic_smart_ant_mode == SMART_ANT_MODE_SERIAL) {
                if (tx_feedback.nPackets != tx_feedback.nBad) {

                    if (tx_feedback.nlong_retries[sbw_indx_succ]) {
                        tx_feedback.nlong_retries[sbw_indx_succ] -= 1;
                    }

                    if (tx_feedback.nshort_retries[sbw_indx_succ]) {
                        tx_feedback.nshort_retries[sbw_indx_succ] -= 1;
                    }
                }
                }

                tx_feedback.rate_index = sbw_indx_succ;
                tx_feedback.is_trainpkt = ((ic->tx_ppdu_end[SMART_ANT_FEEDBACK_OFFSET] & SMART_ANT_FEEDBACK_TRAIN_MASK) ? 1: 0);
                tx_feedback.ratemaxphy =  (ic->tx_ppdu_end[SMART_ANT_FEEDBACK_OFFSET_2]);
                tx_feedback.goodput =  (ic->tx_ppdu_end[(SMART_ANT_FEEDBACK_OFFSET_2+1)]);

                tx_feedback.num_comb_feedback = (ic->tx_ppdu_end[SMART_ANT_FEEDBACK_OFFSET]  & 0x60000000) >> 29;
                *((uint32_t *)&tx_feedback.comb_fb[0]) = ic->tx_ppdu_end[LONG_RETRIES_OFFSET];
                *((uint32_t *)&tx_feedback.comb_fb[1]) = ic->tx_ppdu_end[SHORT_RETRIES_OFFSET];

                /* Data recevied from the associated node, Prepare TX feed back structure and send to SA module */
                txstatus = ieee80211_smart_ant_update_txfeedback(ni, &tx_feedback);
                ieee80211_free_node(ni);
            }
        }
    } else {
        /* First We will get status */
        if (pl_hdr.log_type == SMART_ANT_PKTLOG_TYPE_TX_STAT) {
            void *tx_ppdu_status_desc;
            u_int32_t *tx_status_ppdu;
            tx_ppdu_status_desc = (void *)data + sizeof(struct ath_smart_ant_pktlog_hdr);
            tx_status_ppdu = (u_int32_t *)tx_ppdu_status_desc;
            /* cache ppdu end (tx status desc) for smart antenna txfeedback */
            OS_MEMCPY(&ic->tx_ppdu_end, tx_status_ppdu, (sizeof(uint32_t)*MAX_TX_PPDU_SIZE));
        }
    }
    return A_OK;
}

int ol_ath_smart_ant_enable_txfeedback(struct ieee80211com *ic, int enable)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    uint32_t types=0;
    int len = 0;
    wmi_buf_t buf;
    wmi_pdev_pktlog_enable_cmd *cmd;

    if (enable == 1) {
        /* Call back for txfeedback */
        ((scn->sa_event_sub).callback) = ol_ath_smart_ant_get_txfeedback;
        if(wdi_event_sub(scn->pdev_txrx_handle,
                        &(scn->sa_event_sub),
                        WDI_EVENT_TX_STATUS)) {
            return A_ERROR;
        }

	    types |= WMI_PKTLOG_EVENT_SMART_ANTENNA;

        len = sizeof(wmi_pdev_pktlog_enable_cmd);
        buf = wmi_buf_alloc(scn->wmi_handle, len);
        if (!buf) {
                adf_os_print("%s:wmi_buf_alloc failed\n", __FUNCTION__);
            return A_ERROR;
        }
        cmd = (wmi_pdev_pktlog_enable_cmd *)wmi_buf_data(buf);
        cmd->evlist = types;
        /*enabling the pktlog for smart antenna tx feedback*/
        if(wmi_unified_cmd_send(scn->wmi_handle, buf, len,
                                WMI_PDEV_PKTLOG_ENABLE_CMDID)) {
            return A_ERROR;
        }
        return A_OK;
    } else if (enable == 0) {
        if(wdi_event_unsub(
                    scn->pdev_txrx_handle,
                    &(scn->sa_event_sub),
                    WDI_EVENT_TX_STATUS)) {
            return A_ERROR;
        }

        buf = wmi_buf_alloc(scn->wmi_handle, 0);
        if (!buf) {
            adf_os_print("%s:wmi_buf_alloc failed\n", __FUNCTION__);
            return A_ERROR;
        }
        if(!wmi_unified_cmd_send(scn->wmi_handle, buf, len,
                                WMI_PDEV_PKTLOG_DISABLE_CMDID)) {
            return A_ERROR;
        }
        return A_OK;
    } else {
        return A_ERROR;
    }
}

int ol_smart_ant_enabled(struct ol_ath_softc_net80211 *scn)
{
    struct ieee80211com *ic = &scn->sc_ic;
    return SMART_ANTENNA_ENABLED(ic);
}
EXPORT_SYMBOL(ol_smart_ant_enabled);

int ol_smart_ant_rx_feedback_enabled(struct ol_ath_softc_net80211 *scn)
{
    struct ieee80211com *ic = &scn->sc_ic;
    return SMART_ANTENNA_RX_FEEDBACK_ENABLED(ic);
}
EXPORT_SYMBOL(ol_smart_ant_rx_feedback_enabled);

void ol_ath_smart_ant_attach(struct ieee80211com *ic)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    uint32_t smart_ant_enable = 0;
    smart_ant_enable = ((WMI_SERVICE_IS_ENABLED(scn->wmi_service_bitmap, WMI_SERVICE_SMART_ANTENNA_SW_SUPPORT) &&
                        WMI_SERVICE_IS_ENABLED(scn->wmi_service_bitmap, WMI_SERVICE_SMART_ANTENNA_HW_SUPPORT))
                        || (WMI_SERVICE_IS_ENABLED(scn->wmi_service_bitmap, WMI_SERVICE_SMART_ANTENNA_SW_SUPPORT) && scn->sa_validate_sw));

    if (smart_ant_enable) {
        ic->ic_smart_ant_enable = ol_ath_smart_ant_enable;
        ic->ic_smart_ant_set_rx_antenna = ol_ath_smart_ant_set_rx_antenna;
        ic->ic_smart_ant_set_tx_antenna = ol_ath_smart_ant_set_tx_antenna;
        ic->ic_smart_ant_set_tx_default_antenna = ol_ath_smart_ant_set_tx_default_antenna;
        ic->ic_smart_ant_set_training_info = ol_ath_smart_ant_set_training_info;
	    ic->ic_smart_ant_set_node_config_ops = ol_ath_smart_ant_set_node_config_ops;
        ic->ic_smart_ant_prepare_rateset = NULL;
        ic->max_fallback_rates = 1; /* 1 primary and 1 fall back rate */
        ic->radio_id = 1; /* Radio Id is 1 for 5Ghz/offload */
        ic->ic_smart_ant_state = SMART_ANT_STATE_DEFAULT;
        wmi_unified_register_event_handler(scn->wmi_handle, WMI_PEER_RATECODE_LIST_EVENTID,
                wmi_unified_smart_ant_assoc_handler, NULL);

    } else {
        ic->ic_smart_ant_enable = NULL;
        ic->ic_smart_ant_set_rx_antenna = NULL;
        ic->ic_smart_ant_set_tx_antenna = NULL;
        ic->ic_smart_ant_set_tx_default_antenna = NULL;
        ic->ic_smart_ant_set_training_info = NULL;
	    ic->ic_smart_ant_set_node_config_ops = NULL;
        ic->ic_smart_ant_prepare_rateset = NULL;
        if(!(WMI_SERVICE_IS_ENABLED(scn->wmi_service_bitmap, WMI_SERVICE_SMART_ANTENNA_SW_SUPPORT)))
            printk("%s: Firmware doest not support Smart Antenna.\n", __func__);

        if(!(WMI_SERVICE_IS_ENABLED(scn->wmi_service_bitmap, WMI_SERVICE_SMART_ANTENNA_HW_SUPPORT)))
            printk("%s: Hardware doest not support Smart Antenna.\n", __func__);

        wmi_unified_register_event_handler(scn->wmi_handle, WMI_PEER_RATECODE_LIST_EVENTID,
                wmi_unified_smart_ant_assoc_dummy_handler, NULL);
    }
}

void ol_ath_smart_ant_detach(struct ieee80211com *ic)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    uint32_t smart_ant_enable = 0;
    smart_ant_enable = ((WMI_SERVICE_IS_ENABLED(scn->wmi_service_bitmap, WMI_SERVICE_SMART_ANTENNA_SW_SUPPORT) &&
                        WMI_SERVICE_IS_ENABLED(scn->wmi_service_bitmap, WMI_SERVICE_SMART_ANTENNA_HW_SUPPORT))
                        || (WMI_SERVICE_IS_ENABLED(scn->wmi_service_bitmap, WMI_SERVICE_SMART_ANTENNA_SW_SUPPORT) && scn->sa_validate_sw));

    if (smart_ant_enable) {
        wmi_unified_unregister_event_handler(scn->wmi_handle, WMI_PEER_RATECODE_LIST_EVENTID);
    }
}

#endif
