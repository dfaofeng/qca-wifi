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
 * LMAC offload interface functions for UMAC - for power and performance offload model
 */
#if ATH_SUPPORT_SPECTRAL
#include "spectral.h"
#endif
#include "ol_if_athvar.h"
#include "ol_if_athpriv.h"
#include "ol_if_athutf.h"
#include "ol_txrx_ctrl_api.h"
#include "ol_ath.h"
#include "adf_os_mem.h"   /* adf_os_mem_alloc,free */
#include "adf_os_lock.h"  /* adf_os_spinlock_* */
#include "adf_os_types.h" /* adf_os_vprint */
#include "dbglog_host.h"
#include "a_debug.h"
#include <wdi_event_api.h>
#include <ol_txrx_api.h>
#include <ol_ctrl_api.h>
#include <ol_txrx_types.h>
#include <htt_internal.h>
#include <net.h>
#include <pktlog_ac_api.h>
#include <pktlog_ac_fmt.h>
#include <pktlog_ac_i.h>
#include "ol_tx_desc.h"
#include "ol_if_stats.h"
#include "osif_private.h"

#define TX_DESC_ID_LOW_MASK 0xffff
#define TX_DESC_ID_LOW_SHIFT 0
#define TX_DESC_ID_HIGH_MASK 0xffff0000
#define TX_DESC_ID_HIGH_SHIFT 16

#define TX_FRAME_OFFSET 13
#define TX_TYPE_OFFSET 14
#define TX_PEER_ID_MASK
#define TX_PEER_ID_OFFSET 1
#define TX_FRAME_TYPE_MASK 0x3c00000
#define TX_FRAME_TYPE_SHIFT 22
#define TX_FRAME_TYPE_NOACK_MASK 0x00010000
#define TX_FRAME_TYPE_NOACK_SHIFT 16
#define TX_TYPE_MASK 0xc0000
#define TX_TYPE_SHIFT 18
#define TX_AMPDU_SHIFT 15
#define TX_AMPDU_MASK 0x8000
#define PPDU_END_OFFSET 16
#define TX_OK_OFFSET (PPDU_END_OFFSET + 0)
#define TX_OK_MASK (0x80000000)
#define TX_RSSI_OFFSET (PPDU_END_OFFSET + 11)
#define TX_RSSI_MASK 0xff
#define RX_RSSI_COMB_MASK 0x000000ff
#define RX_RSSI_COMB_OFFSET 4
#define RX_RSSI_CHAIN_PRI20_MASK 0x000000ff
#define RX_RSSI_CHAIN_PRI20_SHIFT 0
#define RX_RSSI_CHAIN_SEC20_MASK 0x0000ff00
#define RX_RSSI_CHAIN_SEC20_SHIFT 8
#define RX_RSSI_CHAIN_SEC40_MASK 0x00ff0000
#define RX_RSSI_CHAIN_SEC40_SHIFT 16
#define RX_RSSI_CHAIN_SEC80_MASK 0xff000000
#define RX_RSSI_CHAIN_SEC80_SHIFT 24
#define RX_RSSI_CHAIN0_OFFSET 0
#define RX_RSSI_CHAIN1_OFFSET 1
#define RX_RSSI_CHAIN2_OFFSET 2
#define RX_RSSI_CHAIN3_OFFSET 3
#define RX_OVERFLOW_MASK 0x0d
#define SEQ_NUM_OFFSET 2
#define SEQ_NUM_MASK 0xfff
int whal_kbps_to_mcs(int, int, int, int);
wdi_event_subscribe STATS_RX_SUBSCRIBER;
wdi_event_subscribe STATS_TX_SUBSCRIBER;
#if ATH_PERF_PWR_OFFLOAD
#define RXDESC_GET_DATA_LEN(msdu_start) ((msdu_start)->msdu_length)
int
wmi_unified_wlan_profile_data_event_handler (ol_scn_t scn, u_int8_t *data, u_int16_t datalen, void *context)
{
    u_int32_t i;
    wmi_profile_stats_event *prof_data = (wmi_profile_stats_event *)data;

    printk("\n\t PROFILE DATA\n");
    printk("Profile duration : %d\n", prof_data->profile_ctx.tot);
    printk("Tx Msdu Count    : %d\n", prof_data->profile_ctx.tx_msdu_cnt);
    printk("Tx Mpdu Count    : %d\n", prof_data->profile_ctx.tx_mpdu_cnt);
    printk("Tx Ppdu Count    : %d\n", prof_data->profile_ctx.tx_ppdu_cnt);
    printk("Rx Msdu Count    : %d\n", prof_data->profile_ctx.rx_msdu_cnt);
    printk("Rx Mpdu Count    : %d\n", prof_data->profile_ctx.rx_mpdu_cnt);

    printk("Profile ID   Count   Total      Min      Max   hist_intvl  hist[0]   hist[1]   hist[2]\n");

    for(i=0; i<prof_data->profile_ctx.bin_count; i++) {
          printk("%8d   %8d %8d %8d %8d     %8d %8d %8d %8d\n", prof_data->profile_data[i].id,
                prof_data->profile_data[i].cnt, prof_data->profile_data[i].tot,
                prof_data->profile_data[i].min, prof_data->profile_data[i].max,
                prof_data->profile_data[i].hist_intvl, prof_data->profile_data[i].hist[0],
                prof_data->profile_data[i].hist[1], prof_data->profile_data[i].hist[2]);
    }

    printk("\n");
    return 0;
}
/*
 * WMI event handler for Channel info WMI event
 */
static int
wmi_unified_chan_info_event_handler(ol_scn_t scn, u_int8_t *data, u_int16_t datalen, void *context)
{
    struct ieee80211com *ic = &scn->sc_ic;
    u_int8_t flags;
    u_int ieee_chan;
    int16_t chan_nf;
    struct ieee80211_chan_stats chan_stats;
    wmi_chan_info_event *event = (wmi_chan_info_event *)data;

    if(event->err_code == 0) {
#if 0
       printk("WMI event chan freq:%d, flags %d, nf %d, clr_cnt %d, cycle_cnt is %d \n",
                   event->freq,event->cmd_flags,event->noise_floor,event->rx_clear_count,
                   event->cycle_count);
#endif
       ieee_chan = ol_ath_mhz2ieee(ic, event->freq, 0);
       flags = (u_int8_t)event->cmd_flags;
       chan_nf = (int16_t)event->noise_floor;
       chan_stats.chan_clr_cnt = event->rx_clear_count;
       chan_stats.cycle_cnt = event->cycle_count;
       ieee80211_acs_stats_update(ic->ic_acs, flags, ieee_chan, chan_nf, &chan_stats);
#if ATH_SUPPORT_SPECTRAL
       if (scn->scn_icm_active) {
           if (flags == WMI_CHAN_INFO_FLAG_START_RESP) {
               ic->chan_clr_cnt = chan_stats.chan_clr_cnt;
               ic->cycle_cnt = chan_stats.cycle_cnt;
               ic->chan_num = ieee_chan;
           } else if (flags == WMI_CHAN_INFO_FLAG_END_RESP) {
               struct ath_spectral* spectral =
                   (struct ath_spectral*)ic->ic_spectral;
               SPECTRAL_LOCK(spectral);
               spectral_record_chan_info(spectral,
                                         ieee_chan,
                                         true,
                                         chan_stats.chan_clr_cnt,
                                         ic->chan_clr_cnt,
                                         chan_stats.cycle_cnt,
                                         ic->cycle_cnt,
                                         true,        /* Whether NF is valid */
                                         chan_nf,
                                         false,       /* Whether PER is valid */
                                         0);          /* PER */
               SPECTRAL_UNLOCK(spectral);
           }
       }
#endif
    }
    else {
          /** FIXME Handle it, whenever channel freq mismatch occurs in target */
       printk("Err code is non zero, Failed to read stats from target \n");
    }
    return 0;
}
/*
 * Registers WMI event handler for Channel info event
 */
void
ol_ath_chan_info_attach(struct ieee80211com *ic)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    /* Register WMI event handlers */
    wmi_unified_register_event_handler(scn->wmi_handle, WMI_CHAN_INFO_EVENTID,
                                            wmi_unified_chan_info_event_handler, NULL);
    return;
}

/*
 * Unregisters WMI event handler for Channel info event
 */
void
ol_ath_chan_info_detach(struct ieee80211com *ic)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    /* Unregister ACS event handler */
    wmi_unified_unregister_event_handler(scn->wmi_handle, WMI_CHAN_INFO_EVENTID);
    return;
}

/*
 * Prepares and Sends the WMI cmd to retrieve channel info from Target
 */
static void
ol_ath_get_chan_info(struct ieee80211com *ic, u_int8_t flags)
{
    /* In offload architecture this is stub function
       because target chan information is indicated as events timely
       (No need to poll for the chan info
     */
}

static void ol_ath_vap_iter_update_txpow(void *arg, wlan_if_t vap)
{
    struct ieee80211_node *ni;
    u_int16_t txpowlevel = *((u_int32_t *) arg);
    ni = ieee80211vap_get_bssnode(vap);
    ASSERT(ni);
    ieee80211node_set_txpower(ni, txpowlevel);
}

#define RSSI_INV     0x80 /*invalid RSSI */

#define RSSI_DROP_INV(_curr_val, _new_val) (_new_val == RSSI_INV ? _curr_val: _new_val)

#define RSSI_CHAIN_STATS(ppdu, rx_chain)        do {        \
        (rx_chain).rx_rssi_pri20 = RSSI_DROP_INV((rx_chain).rx_rssi_pri20, ((ppdu) & RX_RSSI_CHAIN_PRI20_MASK)); \
        (rx_chain).rx_rssi_sec20 = RSSI_DROP_INV((rx_chain).rx_rssi_sec20, ((ppdu) & RX_RSSI_CHAIN_SEC20_MASK) >> RX_RSSI_CHAIN_SEC20_SHIFT) ; \
        (rx_chain).rx_rssi_sec40 = RSSI_DROP_INV((rx_chain).rx_rssi_sec40, ((ppdu) & RX_RSSI_CHAIN_SEC40_MASK) >> RX_RSSI_CHAIN_SEC40_SHIFT); \
        (rx_chain).rx_rssi_sec80 = RSSI_DROP_INV((rx_chain).rx_rssi_sec80, ((ppdu) & RX_RSSI_CHAIN_SEC80_MASK) >> RX_RSSI_CHAIN_SEC80_SHIFT); \
    } while ( 0 )


/*
 * WMI event handler for periodic target stats event
 */
static int
wmi_unified_update_stats_event_handler(ol_scn_t scn, u_int8_t *data,
                                    u_int16_t datalen, void *context)
{
    struct ieee80211com *ic;
    struct ieee80211_node *ni;
    struct ieee80211vap *vap;
    struct ieee80211_mac_stats *mac_stats;
    wmi_stats_event *ev = (wmi_stats_event *)data;
    A_UINT8 *temp;
    A_UINT8 i;
    u_int8_t c_macaddr[ATH_MAC_LEN];
    temp = (A_UINT8 *)ev->data;

    ic = &scn->sc_ic;

    if (ev->num_pdev_stats > 0)
    {
        for (i = 0; i < ev->num_pdev_stats; i++)
        {
            wmi_pdev_stats *pdev_stats = (wmi_pdev_stats *)temp;
            scn->mib_cycle_cnts.tx_frame_count = pdev_stats->tx_frame_count;
            scn->mib_cycle_cnts.rx_frame_count = pdev_stats->rx_frame_count;
            scn->mib_cycle_cnts.rx_clear_count = pdev_stats->rx_clear_count;
            scn->mib_cycle_cnts.cycle_count = pdev_stats->cycle_count;
            scn->chan_stats.chan_clr_cnt = pdev_stats->rx_clear_count;
            scn->chan_stats.cycle_cnt = pdev_stats->cycle_count;
            scn->chan_stats.phy_err_cnt = pdev_stats->phy_err_count;
            scn->chan_nf = pdev_stats->chan_nf;
            scn->chan_tx_pwr = pdev_stats->chan_tx_pwr;
            wlan_iterate_vap_list(ic, ol_ath_vap_iter_update_txpow,(void *) &scn->chan_tx_pwr);
            scn->scn_stats.ackRcvBad = pdev_stats->ackRcvBad;
            scn->scn_stats.rtsBad = pdev_stats->rtsBad;
            scn->scn_stats.rtsGood = pdev_stats->rtsGood;
            scn->scn_stats.fcsBad = pdev_stats->fcsBad;
            scn->scn_stats.noBeacons = pdev_stats->noBeacons;
            scn->scn_stats.mib_int_count = pdev_stats->mib_int_count;
            OS_MEMCPY(&scn->ath_stats,
                       &pdev_stats->pdev_stats,
                       sizeof(pdev_stats->pdev_stats));
            scn->scn_stats.rx_phyerr = scn->ath_stats.rx.phy_errs;
            scn->scn_stats.rx_mgmt = scn->ath_stats.rx.loc_msdus;
            scn->scn_stats.tx_mgmt = scn->ath_stats.tx.local_enqued;
            temp += sizeof(wmi_pdev_stats);
        }
    }

    if (ev->num_pdev_ext_stats > 0) {
            wmi_pdev_ext_stats *pdev_ext_stats = (wmi_pdev_ext_stats *)temp;
            OS_MEMCPY(scn->scn_stats.rx_mcs,  pdev_ext_stats->rx_mcs, sizeof(scn->scn_stats.rx_mcs));
            scn->scn_stats.rx_rssi_comb = (pdev_ext_stats->rx_rssi_comb & RX_RSSI_COMB_MASK);
            /* rssi of separate chains */
            RSSI_CHAIN_STATS(pdev_ext_stats->rx_rssi_chain0, scn->scn_stats.rx_rssi_chain0);
            RSSI_CHAIN_STATS(pdev_ext_stats->rx_rssi_chain1, scn->scn_stats.rx_rssi_chain1);
            RSSI_CHAIN_STATS(pdev_ext_stats->rx_rssi_chain2, scn->scn_stats.rx_rssi_chain2);
            RSSI_CHAIN_STATS(pdev_ext_stats->rx_rssi_chain3, scn->scn_stats.rx_rssi_chain3);
            OS_MEMCPY(scn->scn_stats.tx_mcs,  pdev_ext_stats->tx_mcs, sizeof(scn->scn_stats.tx_mcs));
            scn->scn_stats.tx_rssi= pdev_ext_stats->ack_rssi;
            temp += sizeof(wmi_pdev_ext_stats);
    }

    if (ev->num_vdev_stats > 0) {
        /*
         * No vdev stats- not required currently.
         *
         *for (i = 0; i < ev->num_vdev_stats; i++) {
         *    wmi_vdev_stats *vdev_stats = (wmi_vdev_stats *)temp;
         *    temp += sizeof(wmi_vdev_stats);
         *}
         */
    }
    if (ev->num_peer_stats > 0)
    {
        ic = &scn->sc_ic;
        for (i = 0; i < ev->num_peer_stats; i++)
        {
            wmi_peer_stats *peer_stats = (wmi_peer_stats *)temp;
            WMI_MAC_ADDR_TO_CHAR_ARRAY(&peer_stats->peer_macaddr, c_macaddr);
            ni = ieee80211_find_node(&ic->ic_sta, c_macaddr);
            if (ni) {
                vap = ni->ni_vap;
                mac_stats =  ( ni == vap->iv_bss ) ? &vap->iv_multicast_stats : &vap->iv_unicast_stats;
                ni->ni_rssi = peer_stats->peer_rssi;
#if ATH_BAND_STEERING
                if (peer_stats->peer_rssi_changed) {
                    // New RSSI measurement
                    ieee80211_bsteering_record_rssi(ni, peer_stats->peer_rssi);
                }
#endif
                (OL_ATH_NODE_NET80211(ni))->an_ni_rx_rate = peer_stats->peer_rx_rate;
                (OL_ATH_NODE_NET80211(ni))->an_ni_tx_rate = peer_stats->peer_tx_rate;
                ni->ni_stats.ns_last_rx_rate = peer_stats->peer_rx_rate;
                ni->ni_stats.ns_last_tx_rate = peer_stats->peer_tx_rate;
                mac_stats->ims_last_tx_rate  = peer_stats->peer_tx_rate;
                mac_stats->ims_last_tx_rate_mcs = whal_kbps_to_mcs( mac_stats->ims_last_tx_rate,vap->iv_data_sgi,0,0
);
#if ATH_SUPPORT_HYFI_ENHANCEMENTS

                (OL_ATH_NODE_NET80211(ni))->an_tx_cnt++;
                (OL_ATH_NODE_NET80211(ni))->an_tx_rates_used += peer_stats->peer_tx_rate/1000;
                (OL_ATH_NODE_NET80211(ni))->an_tx_bytes += peer_stats->txbytes;
                 ni->ni_ald.ald_txcount +=  peer_stats->totalsubframes;
                (OL_ATH_NODE_NET80211(ni))->an_phy_err_cnt = scn->chan_stats.phy_err_cnt;

                 ni->ni_ald.ald_max4msframelen += peer_stats->max4msframelen;
                (OL_ATH_NODE_NET80211(ni))->an_tx_ratecount += peer_stats->txratecount;



				ni->ni_ald.ald_lastper += peer_stats->currentper;
				ni->ni_ald.ald_retries += peer_stats->retries;

				ni->ni_ald.ald_ac_nobufs[0] += peer_stats->nobuffs[0];
				ni->ni_ald.ald_ac_nobufs[1] += peer_stats->nobuffs[1];
				ni->ni_ald.ald_ac_nobufs[2] += peer_stats->nobuffs[2];
				ni->ni_ald.ald_ac_nobufs[3] += peer_stats->nobuffs[3];
				ni->ni_ald.ald_ac_excretries[0] += peer_stats->excretries[0];
				ni->ni_ald.ald_ac_excretries[1] += peer_stats->excretries[1];
				ni->ni_ald.ald_ac_excretries[2] += peer_stats->excretries[2];
				ni->ni_ald.ald_ac_excretries[3] = peer_stats->excretries[3];
#endif
                ieee80211_free_node(ni);
            }
            temp += sizeof(wmi_peer_stats);
        }
    }
    return 0;
}

static void
ol_ath_net80211_get_cur_chan_stats(struct ieee80211com *ic, struct ieee80211_chan_stats *chan_stats)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    chan_stats->chan_clr_cnt = scn->chan_stats.chan_clr_cnt;
    chan_stats->cycle_cnt = scn->chan_stats.cycle_cnt;
    chan_stats->phy_err_cnt = scn->chan_stats.phy_err_cnt;
}

/*
 * stats_id is a bitmap of wmi_stats_id- pdev/vdev/peer
 */

static int
ol_ath_rssi_cb(struct ol_ath_softc_net80211 *scn,
                u_int8_t *data,
                u_int16_t datalen, void *cookie)
{
    struct ieee80211com *ic;
    struct ieee80211_node *ni;
    u_int8_t i;

    wmi_inst_stats_resp *ev = (wmi_inst_stats_resp *)data;
    u_int8_t c_macaddr[ATH_MAC_LEN];

    ic = &scn->sc_ic;
    WMI_MAC_ADDR_TO_CHAR_ARRAY(&ev->peer_macaddr, c_macaddr);
    ni = ieee80211_find_node(&ic->ic_sta, c_macaddr);
    if (ni) {
#if ATH_BAND_STEERING
        if (ev->iRSSI != WMI_INST_STATS_INVALID_RSSI) {
            ieee80211_bsteering_record_inst_rssi(ni, ev->iRSSI);
        } else {
            ieee80211_bsteering_record_inst_rssi_err(ni);
        }
#endif
        ni->ni_inst_rssi = ev->iRSSI;
        adf_os_print("Inst RSSI value of node-");
        for (i = 0; i < ATH_MAC_LEN; i++) {
            adf_os_print("%02x:", c_macaddr[i]);
        }
        adf_os_print(" %d\n", ev->iRSSI);
        ieee80211_free_node(ni);
    }
    return 0;
}


static int32_t
ol_ath_request_stats(struct ieee80211com *ic,
                               void *cmd_param)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_buf_t buf;
    wmi_request_stats_cmd *cmd_buf, *cmd;
    u_int8_t len = sizeof(wmi_request_stats_cmd);
    cmd = (wmi_request_stats_cmd *)cmd_param;
    buf = wmi_buf_alloc(scn->wmi_handle, len);
    if (!buf) {
        adf_os_print("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return EINVAL;
    }
    cmd_buf = (wmi_request_stats_cmd *)wmi_buf_data(buf);
    adf_os_mem_copy(cmd_buf, cmd, sizeof(wmi_request_stats_cmd));

    if (wmi_unified_cmd_send(scn->wmi_handle, buf, len,
        WMI_REQUEST_STATS_CMDID)) {
        return EINVAL;
    }

    return 0;


}

static int32_t
ol_ath_send_rssi(struct ieee80211com *ic,
                u_int8_t *macaddr, struct ieee80211vap *vap)
{
    wmi_request_stats_cmd cmd;
    cmd.vdev_id = (OL_ATH_VAP_NET80211(vap))->av_if_id;
    cmd.stats_id = WMI_REQUEST_INST_STAT;
    WMI_CHAR_ARRAY_TO_MAC_ADDR(macaddr, &cmd.peer_macaddr);
    ol_ath_request_stats(ic, &cmd);

    return 0;
}

void
reset_node_stat(void *arg, wlan_node_t node)
{
    struct ieee80211_node *ni = node;
    OS_MEMZERO(&(ni->ni_stats), sizeof(struct ieee80211_nodestats ));
}

void
reset_vap_stat(void *arg , struct ieee80211vap *vap)
{
    wlan_iterate_station_list(vap, reset_node_stat, NULL);
    OS_MEMZERO(&(vap->iv_stats), sizeof(struct ieee80211_stats ));
    OS_MEMZERO(&(vap->iv_unicast_stats), sizeof(struct ieee80211_mac_stats ));
    OS_MEMZERO(&(vap->iv_multicast_stats), sizeof(struct ieee80211_mac_stats ));
    return;
}

void
ol_ath_reset_vap_stat(struct ieee80211com *ic)
{
     wlan_iterate_vap_list(ic, reset_vap_stat, NULL);
}

A_STATUS
process_rx_stats(void *pdev, adf_nbuf_t amsdu,
                uint16_t peer_id,
                enum htt_rx_status status)
{

    int is_mcast;
    struct htt_host_rx_desc_base *rx_desc;
    adf_nbuf_t msdu;
    struct ol_txrx_pdev_t *txrx_pdev =  (struct ol_txrx_pdev_t *)pdev;
    struct ieee80211vap *vap;
    struct ieee80211_mac_stats *mac_stats;
    struct ieee80211_node *ni;
    struct ol_ath_softc_net80211 *scn = (struct ol_ath_softc_net80211 *)txrx_pdev->ctrl_pdev;
    struct ol_txrx_vdev_t *vdev = NULL;
    struct ol_txrx_peer_t *peer;
    uint32_t data_length = 0;
    char *hdr_des;
    uint32_t *attn;
    struct ieee80211_frame *wh;

    if (!amsdu) {
        adf_os_print("Invalid data in %s\n", __func__);
        return A_ERROR;
    }

    rx_desc = htt_rx_msdu_desc_retrieve(txrx_pdev->htt_pdev,
                                                        amsdu);
    switch (status) {
    case HTT_RX_IND_MPDU_STATUS_OK:
        peer = (peer_id == HTT_INVALID_PEER) ?
                           NULL : txrx_pdev->peer_id_to_obj_map[peer_id];
        if (peer) {
            vdev = peer->vdev;
            vap = ol_ath_vap_get(scn, vdev->vdev_id);
            if (!vap) {
                return A_ERROR;
            }
            ni = ieee80211_vap_find_node(vap,peer->mac_addr.raw);
            if (!ni) {
                   return A_ERROR;
                }
            /* remove extra node ref count added by find_node above */

            if (!pdev) {
                adf_os_print("Invalid pdev in %s\n",
                                __func__);
                return A_ERROR;
            }

            if (!amsdu) {
                adf_os_print("Invalid data in %s\n",
                                __func__);
                return A_ERROR;
            }

            msdu = amsdu;
            while (msdu) {
                rx_desc = htt_rx_msdu_desc_retrieve(txrx_pdev->htt_pdev,
                                                                    msdu);
                /*  Here the mcast packets are decided on the basis that
                    the target sets "only" the forward bit for mcast packets.
                    If it is a normal packet then "both" the forward bit and
                    the discard bit is set. Forward bit indicates that the
                    packet needs to be forwarded and the discard bit
                    indicates that the packet should not be delivered to
                    the OS.*/
                is_mcast =  ((htt_rx_msdu_forward(txrx_pdev->htt_pdev,
                                                                rx_desc)) &&
                                !htt_rx_msdu_discard(txrx_pdev->htt_pdev,
                                                                rx_desc));
                mac_stats = is_mcast ? &vap->iv_multicast_stats :
                                            &vap->iv_unicast_stats;
                data_length = RXDESC_GET_DATA_LEN(&rx_desc->msdu_start);
                attn = ((u_int32_t *)&rx_desc->attention);
                if (attn[0] & RX_OVERFLOW_MASK) {
                    scn->scn_stats.rx_overrun++;
                }
                /*  Updating peer stats */
                ni->ni_stats.ns_rx_data++;
                ni->ni_stats.ns_rx_bytes += data_length;
                /*  Updating vap stats  */
                mac_stats->ims_rx_data_packets++;
                mac_stats->ims_rx_data_bytes += data_length;
                mac_stats->ims_rx_datapyld_bytes += (data_length -
                                                        ETHERNET_HDR_LEN);

                IEEE80211_PRDPERFSTAT_THRPUT_ADDCURRCNT(ni->ni_ic, data_length + 24);
                mac_stats->ims_rx_packets++;

                mac_stats->ims_rx_bytes += data_length;
                msdu = adf_nbuf_next(msdu);
                scn->scn_stats.rx_packets++;
                scn->scn_stats.rx_num_data++;
                scn->scn_stats.rx_bytes += data_length;
            }
            ieee80211_free_node(ni);
            scn->scn_stats.rx_aggr = txrx_pdev->stats.priv.rx.normal.rx_aggr;

        }
        break;
    case HTT_RX_IND_MPDU_STATUS_ERR_FCS:
        rx_desc = htt_rx_msdu_desc_retrieve(txrx_pdev->htt_pdev,
                                                        amsdu);
        data_length = RXDESC_GET_DATA_LEN(&rx_desc->msdu_start);
        scn->scn_stats.rx_bytes += data_length;
        scn->scn_stats.rx_crcerr++;
        scn->scn_stats.rx_packets++;
	peer = (peer_id == HTT_INVALID_PEER) ?
		NULL : txrx_pdev->peer_id_to_obj_map[peer_id];
	if (peer ) {
		vdev = peer->vdev;
		if (vdev == NULL ) {
			return A_ERROR;
		}
		vap = ol_ath_vap_get(scn, vdev->vdev_id);
		is_mcast =  ((htt_rx_msdu_forward(txrx_pdev->htt_pdev, rx_desc))
				&&
				!htt_rx_msdu_discard(txrx_pdev->htt_pdev, rx_desc));
		if (vap !=NULL) {
			mac_stats = is_mcast ? &vap->iv_multicast_stats :
				&vap->iv_unicast_stats;
			mac_stats->ims_rx_fcserr++;
		}
	}
	break;
    case HTT_RX_IND_MPDU_STATUS_TKIP_MIC_ERR:
        peer = (peer_id == HTT_INVALID_PEER) ?
                              NULL : txrx_pdev->peer_id_to_obj_map[peer_id];
        if (peer) {
            vdev = peer->vdev;
            vap = ol_ath_vap_get(scn, vdev->vdev_id);
            if (!vap) {
                return A_ERROR;
            }
            rx_desc = htt_rx_msdu_desc_retrieve(txrx_pdev->htt_pdev, amsdu);
            data_length = RXDESC_GET_DATA_LEN(&rx_desc->msdu_start);
            scn->scn_stats.rx_bytes += data_length;

            is_mcast =  ((htt_rx_msdu_forward(txrx_pdev->htt_pdev, rx_desc))
                        &&
                        !htt_rx_msdu_discard(txrx_pdev->htt_pdev, rx_desc));
            mac_stats = is_mcast ? &vap->iv_multicast_stats :
                                    &vap->iv_unicast_stats;

            mac_stats->ims_rx_tkipmic++;
            scn->scn_stats.rx_badmic++;
            ni = ieee80211_vap_find_node(vap, peer->mac_addr.raw);
            if (!ni) {
               return A_ERROR;
            }
            ni->ni_stats.ns_rx_tkipmic++;
            /* remove extra node ref count added by find_node above */
            ieee80211_free_node(ni);

        }
        scn->scn_stats.rx_packets++;
        break;
    case HTT_RX_IND_MPDU_STATUS_DECRYPT_ERR:
        peer = (peer_id == HTT_INVALID_PEER) ?
                            NULL : txrx_pdev->peer_id_to_obj_map[peer_id];
        if (peer) {
            vdev = peer->vdev;
            vap = ol_ath_vap_get(scn, vdev->vdev_id);
            if (!vap) {
                return A_ERROR;
            }
            rx_desc = htt_rx_msdu_desc_retrieve(txrx_pdev->htt_pdev, amsdu);
            data_length = RXDESC_GET_DATA_LEN(&rx_desc->msdu_start);
            scn->scn_stats.rx_bytes += data_length;
            is_mcast =  ((htt_rx_msdu_forward(txrx_pdev->htt_pdev, rx_desc))
                        &&
                        !htt_rx_msdu_discard(txrx_pdev->htt_pdev, rx_desc));
            mac_stats = is_mcast ? &vap->iv_multicast_stats :
                                    &vap->iv_unicast_stats;

            mac_stats->ims_rx_decryptcrc++;
            scn->scn_stats.rx_badcrypt++;
            ni = ieee80211_vap_find_node(vap, peer->mac_addr.raw);
            if (!ni) {
               return A_ERROR;
            }
            ni->ni_stats.ns_rx_decryptcrc++;
            /* remove extra node ref count added by find_node above */
            ieee80211_free_node(ni);
        }
        scn->scn_stats.rx_packets++;
        break;
    default:
        rx_desc = htt_rx_msdu_desc_retrieve(txrx_pdev->htt_pdev,
                                                        amsdu);
        data_length = RXDESC_GET_DATA_LEN(&rx_desc->msdu_start);
        scn->scn_stats.rx_bytes += data_length;
        scn->scn_stats.rx_packets++;
        hdr_des = &rx_desc->rx_hdr_status[0];

        wh = (struct ieee80211_frame*)hdr_des;
        if ((wh->i_fc[0] & IEEE80211_FC0_TYPE_MASK) == IEEE80211_FC0_TYPE_CTL)
            scn->scn_stats.rx_num_ctl++;
        if ((wh->i_fc[0] & IEEE80211_FC0_TYPE_MASK) == IEEE80211_FC0_TYPE_MGT)
            scn->scn_stats.rx_num_mgmt++;

        break;
    }
    return A_OK;
}

A_STATUS
process_tx_stats(struct ol_txrx_pdev_t *txrx_pdev,
                    void *data, uint16_t peer_id,
                    enum htt_tx_status status)
{
    struct ol_pktlog_dev_t *pl_dev;
    struct ath_pktlog_stats_hdr pl_hdr;
    struct ol_txrx_peer_t *peer = NULL;
    struct ieee80211vap *vap = NULL;
    struct ieee80211_node *ni = NULL;
    struct ieee80211_mac_stats *mac_stats = NULL;
    struct ol_ath_softc_net80211 *scn;
    struct ieee80211com *ic;
    uint32_t *pl_tgt_hdr;
    int32_t diff = 0;

    if (!txrx_pdev) {
        adf_os_print("Invalid pdev in %s\n", __func__);
        return A_ERROR;
    }
    scn = (struct ol_ath_softc_net80211 *)txrx_pdev->ctrl_pdev;
    ic = &scn->sc_ic;

    adf_os_assert(txrx_pdev->pl_dev);
    adf_os_assert(data);
    pl_dev = txrx_pdev->pl_dev;
    pl_tgt_hdr = (uint32_t *)data;
    /*
     * Makes the short words (16 bits) portable b/w little endian
     * and big endian
     */

    pl_hdr.log_type =  (*(pl_tgt_hdr + ATH_PKTLOG_STATS_HDR_LOG_TYPE_OFFSET) &
                                        ATH_PKTLOG_STATS_HDR_LOG_TYPE_MASK) >>
                                        ATH_PKTLOG_STATS_HDR_LOG_TYPE_SHIFT;

    if (pl_hdr.log_type == PKTLOG_STATS_TYPE_TX_CTRL) {
        int frame_type;
        u_int8_t is_aggr;
        u_int64_t num_msdus;
        u_int64_t byte_cnt = 0;
        u_int32_t start_seq_num;
        void *tx_ppdu_ctrl_desc;
        int       peer_id;

        tx_ppdu_ctrl_desc = (void *)data + sizeof(struct ath_pktlog_stats_hdr);
        /*	The peer_id is filled in the target in the ppdu_done function, the
            peer_id istaken from the tid structure
        */
        peer_id = *((u_int32_t *)tx_ppdu_ctrl_desc + TX_PEER_ID_OFFSET);
        txrx_pdev->tx_stats.peer_id = peer_id;
        peer = (peer_id == HTT_INVALID_PEER) ?
                NULL : txrx_pdev->peer_id_to_obj_map[peer_id];
        if (peer) {
            /* extract the seq_num  */
            start_seq_num = ((*((u_int32_t *)tx_ppdu_ctrl_desc + SEQ_NUM_OFFSET))
                                          & SEQ_NUM_MASK);
            /* We don't Check for the wrap around condition, we are
            *   interested only in seeing if we have advanced the
            *   block ack window.
            */
            if (txrx_pdev->tx_stats.seq_num != start_seq_num) {
                    scn->scn_stats.tx_bawadv++;
            }
            /* cache the seq_num in the structure for the next ppdu */
            txrx_pdev->tx_stats.seq_num = start_seq_num;
            /* cache the no_ack in the structure for the next ppdu */
            txrx_pdev->tx_stats.no_ack = ((*((u_int32_t *)tx_ppdu_ctrl_desc + TX_FRAME_OFFSET)) &
                                                TX_FRAME_TYPE_NOACK_MASK) >> TX_FRAME_TYPE_NOACK_SHIFT;

            vap = ol_ath_vap_get(scn,
                           peer->vdev->vdev_id);
            if (!vap) {
                adf_os_print("\n VAP is already deleted  \n");
                return -1;
            } 

            num_msdus = peer->peer_data_stats.data_packets;
            byte_cnt = peer->peer_data_stats.data_bytes;
            scn->scn_stats.tx_num_data += num_msdus;
            scn->scn_stats.tx_bytes += byte_cnt;
            mac_stats = peer->bss_peer ? &vap->iv_multicast_stats :
                                         &vap->iv_unicast_stats;
            mac_stats->ims_tx_packets += num_msdus;
            mac_stats->ims_tx_bytes += byte_cnt;
            mac_stats->ims_tx_data_packets += num_msdus;
            mac_stats->ims_tx_data_bytes += byte_cnt;
            mac_stats->ims_tx_datapyld_bytes = mac_stats->ims_tx_data_bytes -
                                             (mac_stats->ims_tx_data_packets *
                                                            ETHERNET_HDR_LEN);

            ni = ieee80211_vap_find_node(vap, peer->mac_addr.raw);
            if (!ni) {
                adf_os_print("\n Could not find the peer \n");
                return -1;
            }

            diff = peer->peer_data_stats.discard_cnt -  ni->ni_stats.ns_tx_discard ;
            vap->iv_unicast_stats.ims_tx_discard += diff;
            ni->ni_stats.ns_tx_discard = (u_int32_t)peer->peer_data_stats.discard_cnt;

            if (peer->bss_peer) {
                ni->ni_stats.ns_tx_mcast += num_msdus;
            } else {
                ni->ni_stats.ns_tx_ucast += num_msdus;
            }
            ni->ni_stats.ns_tx_data_success += num_msdus;
            ni->ni_stats.ns_tx_bytes_success += byte_cnt;
            /* Right now, I am approx. the header length to 802.11 as the host never receives
               the 80211 header and it is very difficult and will require a lot
               of host CPU cycles to compute it and further amsdu logic will
               make the header calculations even more complicated. Therefore for
               now leaving it at 24.
            */
            IEEE80211_PRDPERFSTAT_THRPUT_ADDCURRCNT(ni->ni_ic, peer->peer_data_stats.thrup_bytes + 24);
            peer->peer_data_stats.thrup_bytes = 0;
            peer->peer_data_stats.data_packets = 0;
            peer->peer_data_stats.data_bytes = 0;
            peer->peer_data_stats.discard_cnt = 0;
            ieee80211_free_node(ni);
        }
        frame_type = ((*((u_int32_t *)tx_ppdu_ctrl_desc + TX_FRAME_OFFSET))
                          & TX_FRAME_TYPE_MASK) >> TX_FRAME_TYPE_SHIFT;
        is_aggr = ((*((u_int32_t *)tx_ppdu_ctrl_desc + TX_FRAME_OFFSET))
                            & TX_AMPDU_MASK) >> TX_AMPDU_SHIFT;
        if (is_aggr) {
            scn->scn_stats.tx_compaggr++;
        }
        else {
            scn->scn_stats.tx_compunaggr++;
        }
        /*	Here the frame type is 3 for beacon frames, this is defined
            in the tx_ppdu_start.h
            Frame type indication.  Indicates what type of frame is
           	being sent.  Supported values:
            0: default
            1: Reserved (Used to be used for ATIM)
            2: PS-Poll
            3: Beacon
            4: Probe response
            5-15: Reserved
            <legal:0,2,3,4>
        */

        if (frame_type == 3) {
            scn->scn_stats.tx_beacon++;
        }
    }
    if (pl_hdr.log_type == PKTLOG_TYPE_TX_STAT) {
        void *tx_ppdu_status_desc = (void *)data + sizeof(struct ath_pktlog_stats_hdr);

        /* If no_ack, no way to know if tx has error so ignore. If !tx_ok, incr tx_error.  */
        /* TODO: Define ole_stats and ole_desc strcut and get stats from ole_stats.*/
        if ( !txrx_pdev->tx_stats.no_ack &&
            !((*((u_int32_t *)tx_ppdu_status_desc + TX_OK_OFFSET)) & TX_OK_MASK))
        {
            /* Peer_id is cached in PKTLOG_STATS_TYPE_TX_CTRL.
            It's not clean but we need to live with it for now. */
            peer = (txrx_pdev->tx_stats.peer_id == HTT_INVALID_PEER) ?
                NULL : txrx_pdev->peer_id_to_obj_map[txrx_pdev->tx_stats.peer_id];
            if (peer) {
                vap = ol_ath_vap_get(scn,
                           peer->vdev->vdev_id);
                if (vap) {
                    vap->iv_stats.is_tx_not_ok++;
                    ni = ieee80211_vap_find_node(vap, peer->mac_addr.raw);
                    if (!ni) {
                        return A_OK;
                    }
                    ni->ni_stats.ns_is_tx_not_ok++;
                    ieee80211_free_node(ni);
                }
            }
        }
    }

    return A_OK;
}


void
ol_ath_get_all_stats(void *pdev, enum WDI_EVENT event,
                        void *log_data, uint16_t peer_id,
                        enum htt_rx_status status)
{
    switch(event) {
    case WDI_EVENT_RX_DESC_REMOTE:
        /*
         * process RX message for local frames
         */
        if(process_rx_stats(pdev, log_data, peer_id, status)) {
            adf_os_print("Unable to process RX info\n");
            return;
        }
        break;
    case WDI_EVENT_TX_STATUS:
        /*
         *Process TX message
         */
        if(process_tx_stats(pdev, log_data, peer_id, status)) {
            adf_os_print("\n Unable to process RX info \n");
            return;
        }
        break;
    default:
        break;
    }
    return;
}

static int ol_ath_enable_ap_stats(struct ieee80211com *ic, u_int8_t stats_cmd)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    uint32_t types=0;
    int len = 0;
    wmi_buf_t buf;
    wmi_pdev_pktlog_enable_cmd *cmd;

    if (stats_cmd == 1) {
        /* Call back for stats */
	    if (scn->scn_stats.ap_stats_tx_cal_enable) {
            return A_OK;
        }
        STATS_RX_SUBSCRIBER.callback = ol_ath_get_all_stats;
        STATS_TX_SUBSCRIBER.callback = ol_ath_get_all_stats;

        if(wdi_event_sub(scn->pdev_txrx_handle,
                        &STATS_RX_SUBSCRIBER,
                        WDI_EVENT_RX_DESC_REMOTE)) {
            return A_ERROR;
        }
        if(wdi_event_sub(scn->pdev_txrx_handle,
                        &STATS_TX_SUBSCRIBER,
                        WDI_EVENT_TX_STATUS)) {
            return A_ERROR;
        }
        types |= WMI_PKTLOG_EVENT_TX;
        len = sizeof(wmi_pdev_pktlog_enable_cmd);
        buf = wmi_buf_alloc(scn->wmi_handle, len);
        if (!buf) {
                adf_os_print("%s:wmi_buf_alloc failed\n", __FUNCTION__);
            return A_ERROR;
        }
        cmd = (wmi_pdev_pktlog_enable_cmd *)wmi_buf_data(buf);
        cmd->evlist = WMI_PKTLOG_EVENT_TX;
        /*enabling the pktlog for stats*/
        if(wmi_unified_cmd_send(scn->wmi_handle, buf, len,
                                WMI_PDEV_PKTLOG_ENABLE_CMDID)) {
            return A_ERROR;
        }
        scn->scn_stats.ap_stats_tx_cal_enable = 1;
        return A_OK;
    } else if (stats_cmd == 0) {
	    if (!scn->scn_stats.ap_stats_tx_cal_enable) {
            return A_OK;
        }
        adf_os_mem_zero(&scn->scn_stats, sizeof(scn->scn_stats));
        scn->scn_stats.ap_stats_tx_cal_enable = 0;
        if(wdi_event_unsub(
                    scn->pdev_txrx_handle,
                    &STATS_TX_SUBSCRIBER,
                    WDI_EVENT_TX_STATUS)) {
            return A_ERROR;
        }
        if(wdi_event_unsub(
                    scn->pdev_txrx_handle,
                    &STATS_RX_SUBSCRIBER,
                    WDI_EVENT_RX_DESC_REMOTE)) {
            return A_ERROR;
        }
#if UNIFIED_SMARTANTENNA
        /* Smart Antenna uses packet log frame work, So when smart antenna is enabled disabling packet log
           in firmware is not allowed */
        if (ol_smart_ant_enabled(scn)) {
            adf_os_print("%s: As Smart Antenna is enabled, Packet log is only disabled in host\n", __FUNCTION__);
            return A_ERROR;
        }
#endif
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

void
ol_ath_stats_attach(struct ieee80211com *ic)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    ic->ic_get_cur_chan_stats = ol_ath_net80211_get_cur_chan_stats;
    ic->ic_ath_request_stats = ol_ath_request_stats;
    ic->ic_hal_get_chan_info = ol_ath_get_chan_info;
    ic->ic_ath_send_rssi = ol_ath_send_rssi;
    /* Enable and disable stats*/
    ic->ic_ath_enable_ap_stats = ol_ath_enable_ap_stats;
    /* register target stats event handler */
    wmi_unified_register_event_handler(scn->wmi_handle, WMI_UPDATE_STATS_EVENTID,
                                       wmi_unified_update_stats_event_handler, NULL);
    wmi_unified_register_event_handler(scn->wmi_handle,
                                        WMI_INST_RSSI_STATS_EVENTID,
                                        ol_ath_rssi_cb, NULL);
	/* enable the pdev stats event */
    wmi_unified_pdev_set_param(scn->wmi_handle,
                               WMI_PDEV_PARAM_PDEV_STATS_UPDATE_PERIOD,
                               PDEV_DEFAULT_STATS_UPDATE_PERIOD);
    /* enable the pdev stats event */
    wmi_unified_pdev_set_param(scn->wmi_handle,
                               WMI_PDEV_PARAM_VDEV_STATS_UPDATE_PERIOD,
                               VDEV_DEFAULT_STATS_UPDATE_PERIOD);
    /* enable the pdev stats event */
    wmi_unified_pdev_set_param(scn->wmi_handle,
                               WMI_PDEV_PARAM_PEER_STATS_UPDATE_PERIOD,
                               PEER_DEFAULT_STATS_UPDATE_PERIOD);
}

void
ol_ath_stats_detach(struct ieee80211com *ic)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    ic->ic_get_cur_chan_stats = NULL;
    ic->ic_ath_request_stats = NULL;
    ic->ic_hal_get_chan_info = NULL;
	ic->ic_ath_send_rssi = NULL;
    ic->ic_ath_enable_ap_stats = NULL;
    /* unregister target stats event handler */
    wmi_unified_unregister_event_handler(scn->wmi_handle, WMI_UPDATE_STATS_EVENTID);
	wmi_unified_unregister_event_handler(scn->wmi_handle, WMI_INST_RSSI_STATS_EVENTID);
    /* disable target stats event */
    wmi_unified_pdev_set_param(scn->wmi_handle, WMI_PDEV_PARAM_PDEV_STATS_UPDATE_PERIOD, 0);
    wmi_unified_pdev_set_param(scn->wmi_handle, WMI_PDEV_PARAM_VDEV_STATS_UPDATE_PERIOD, 0);
    wmi_unified_pdev_set_param(scn->wmi_handle, WMI_PDEV_PARAM_PEER_STATS_UPDATE_PERIOD, 0);
}


void
ol_get_wal_dbg_stats(struct ol_ath_softc_net80211 *scn,
                            struct wal_dbg_stats *dbg_stats)
{
    OS_MEMCPY(dbg_stats, &scn->ath_stats, sizeof(struct wal_dbg_stats));
}

int
ol_get_tx_free_desc(struct ol_ath_softc_net80211 *scn)
{
    struct ol_txrx_pdev_t *pdev = scn->pdev_txrx_handle;
    int total;
    int used = 0;

    total = ol_cfg_target_tx_credit(pdev->ctrl_pdev);
    used = ol_txrx_get_tx_pending(pdev);
    return (total - used);

}
void ol_get_radio_stats(struct ol_ath_softc_net80211 *scn,
                            struct ol_ath_radiostats *stats)
{
    scn->scn_stats.tx_buf_count = ol_get_tx_free_desc(scn);
    OS_MEMCPY(stats, &scn->scn_stats, sizeof(struct ol_ath_radiostats));
}

void ol_vap_txdiscard_stats_update(void *vosdev, adf_nbuf_t nbuf)
{   
    osif_dev  *osdev = (osif_dev  *)vosdev;
    struct ieee80211vap *vap = osdev->os_if;
    if ( vap != NULL) {
        struct ieee80211_node *ni = NULL;
        char *data = adf_nbuf_data(nbuf);
        vap->iv_stats.is_tx_nobuf++; 
        ni = ieee80211_find_node(&vap->iv_ic->ic_sta, data); 
        if (ni) {
            ni->ni_stats.ns_is_tx_nobuf++;
            ieee80211_free_node(ni);
        }
    }
}
#endif /* ATH_PERF_PWR_OFFLOAD */

