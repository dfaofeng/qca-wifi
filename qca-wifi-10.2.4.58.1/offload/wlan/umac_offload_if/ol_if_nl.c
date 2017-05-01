/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */


#include "ol_if_athvar.h"
#include "osif_private.h"
#include <ieee80211_nl.h>

static int
wmi_unified_mu_report_event_handler(ol_scn_t scn, u_int8_t *data, u_int16_t datalen, void *context)
{
    struct ieee80211com *ic = &scn->sc_ic;
    wmi_mu_report_event *event = (wmi_mu_report_event *)data;
    struct event_data_mu_rpt mu_rpt;
    struct ieee80211vap *vap = NULL;
    int i;
    struct ieee80211_nl_handle *nl_handle = ic->ic_nl_handle;
    void (*mu_cb)(wlan_if_t cb_arg, struct event_data_mu_rpt *mu_rpt) = NULL;
    wlan_if_t mu_cb_arg = NULL;

    if (!ic->ic_nl_handle) {
        printk("%s: MU report (status=%d id=%d), but on non NL radio\n",
               __func__, event->status_reason, event->mu_request_id);
        return 0;
    }

    spin_lock_bh(&nl_handle->mu_lock);
    if (atomic_read(&nl_handle->mu_in_progress) == 0) {
        spin_unlock_bh(&nl_handle->mu_lock);
        printk("%s: MU report id=%d (%d), but MU not active\n",
               __func__, event->mu_request_id, nl_handle->mu_id);
        return 0;
    }

    IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_LOUD, IEEE80211_MSG_NL,
             "%s: MU report id=%d, expected=%d, status=%d\n", __func__,
             event->mu_request_id, nl_handle->mu_id, event->status_reason);

    mu_rpt.mu_channel = nl_handle->mu_channel;
    mu_rpt.mu_actual_duration = nl_handle->mu_duration;
    atomic_set(&nl_handle->mu_in_progress, 0);
    spin_unlock_bh(&nl_handle->mu_lock);

    mu_rpt.mu_req_id = event->mu_request_id;
    mu_rpt.mu_status = event->status_reason;
    for (i = 0; i < MU_MAX_ALGO; i++) {
        mu_rpt.mu_total_val[i] = event->total_mu[i];
        IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_LOUD, IEEE80211_MSG_NL,
                 "%s: MU report val[%d]=%d\n", __func__, i, event->total_mu[i]);
    }
    mu_rpt.mu_num_bssid = event->num_active_bssid;
    IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_LOUD, IEEE80211_MSG_NL,
             "%s: MU report num_bssid=%d\n", __func__, event->num_active_bssid);

    IEEE80211_COMM_LOCK(ic);
    TAILQ_FOREACH(vap, &ic->ic_vaps, iv_next) {
        spin_lock_bh(&nl_handle->mu_lock);
        if (nl_handle->mu_cb && vap == nl_handle->mu_cb_arg) {
            mu_cb = nl_handle->mu_cb;
            mu_cb_arg = nl_handle->mu_cb_arg;
            spin_unlock_bh(&nl_handle->mu_lock);
            break;
        }
        spin_unlock_bh(&nl_handle->mu_lock);
    }
    IEEE80211_COMM_UNLOCK(ic);

    if (mu_cb && mu_cb_arg)
        mu_cb(mu_cb_arg, &mu_rpt);

    return 0;
}

static int
ol_ath_mu_scan(struct ieee80211com *ic, u_int8_t id,
               u_int32_t duration, u_int8_t type, u_int32_t lteu_tx_power)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_mu_start_cmd *cmd;
    wmi_buf_t buf;
    buf = wmi_buf_alloc(scn->wmi_handle, sizeof(wmi_mu_start_cmd));
    if (!buf) {
        printk("%s: wmi_buf_alloc failed\n", __func__);
        return -1;
    }
    cmd = (wmi_mu_start_cmd *)wmi_buf_data(buf);
    cmd->mu_request_id = id;
    cmd->mu_duration = duration;
    cmd->mu_type = type;
    cmd->lteu_tx_power = lteu_tx_power;
    return wmi_unified_cmd_send(scn->wmi_handle, buf,
                                sizeof(wmi_mu_start_cmd),
                                WMI_MU_CAL_START_CMDID);
}

static int
ol_ath_lteu_config(struct ieee80211com *ic,
                   ieee80211req_lteu_cfg_t *config, u_int32_t wifi_tx_power)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_set_lteu_config *cmd;
    wmi_buf_t buf;
    int i;
    buf = wmi_buf_alloc(scn->wmi_handle, sizeof(wmi_set_lteu_config));
    if (!buf) {
        printk("%s: wmi_buf_alloc failed\n", __func__);
        return -1;
    }
    cmd = (wmi_set_lteu_config *)wmi_buf_data(buf);
    cmd->gpio_enable = config->lteu_gpio_start;
    cmd->num_lteu_bins = config->lteu_num_bins;
    for (i = 0; i < cmd->num_lteu_bins; i++) {
        cmd->mu_rssi_threshold[i] = config->lteu_thresh[i];
        cmd->mu_weight[i] = config->lteu_weight[i];
        cmd->mu_gamma[i] = config->lteu_gamma[i];
    }
    cmd->mu_scan_timeout = config->lteu_scan_timeout;
    cmd->alpha_num_bssid = config->alpha_num_bssid;
    cmd->use_actual_nf = config->use_actual_nf;
    cmd->wifi_tx_power = wifi_tx_power;
    return wmi_unified_cmd_send(scn->wmi_handle, buf,
                                sizeof(wmi_set_lteu_config),
                                WMI_SET_LTEU_CONFIG_CMDID);
}

void
ol_ath_nl_attach(struct ieee80211com *ic)
{
    struct ieee80211_nl_handle *nl_handle = NULL;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    if (scn->lteu_support) {
        nl_handle = OS_MALLOC(ic->ic_osdev, sizeof(*nl_handle), GFP_KERNEL);
        if (nl_handle) {
            OS_MEMSET(nl_handle, sizeof(*nl_handle), 0);
            atomic_set(&nl_handle->mu_in_progress, 0);
            atomic_set(&nl_handle->scan_in_progress, 0);
            spin_lock_init(&nl_handle->mu_lock);
            nl_handle->mu_scan = ol_ath_mu_scan;
            nl_handle->lteu_config = ol_ath_lteu_config;
            nl_handle->force_vdev_restart = 0;
            nl_handle->use_gpio_start = 0;
            wmi_unified_register_event_handler(scn->wmi_handle,
                                WMI_MU_REPORT_EVENTID,
                                wmi_unified_mu_report_event_handler, NULL);
        }
    }
    ic->ic_nl_handle = nl_handle;
}

void
ol_ath_nl_detach(struct ieee80211com *ic)
{
    struct ieee80211_nl_handle *nl_handle = ic->ic_nl_handle;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    if (nl_handle) {
        wmi_unified_unregister_event_handler(scn->wmi_handle,
                              WMI_MU_REPORT_EVENTID);
        spin_lock_destroy(&nl_handle->mu_lock);
        OS_FREE(nl_handle);
    }
    ic->ic_nl_handle = NULL;
}

