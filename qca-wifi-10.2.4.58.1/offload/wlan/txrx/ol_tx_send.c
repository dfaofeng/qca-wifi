/*
 * Copyright (c) 2011-2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#include <adf_os_atomic.h>   /* adf_os_atomic_inc, etc. */
#include <adf_os_lock.h>     /* adf_os_spinlock */
#include <adf_nbuf.h>        /* adf_nbuf_t */
#include <net.h>
#include <queue.h>           /* TAILQ */

#include <ol_txrx_api.h>     /* ol_txrx_vdev_handle, etc. */
#include <ol_htt_tx_api.h>   /* htt_tx_compl_desc_id */
#include <ol_txrx_htt_api.h> /* htt_tx_status */

#include <ol_txrx_types.h>   /* ol_txrx_vdev_t, etc */
#include <ol_tx_desc.h>      /* ol_tx_desc_find, ol_tx_desc_frame_free */
#include <ol_txrx_internal.h>
#include <ol_if_athvar.h>

#include <ol_cfg.h>          /* ol_cfg_is_high_latency */
#if QCA_OL_TX_CACHEDHDR
#include "htt_internal.h"
#endif
void
ol_tx_send(
    struct ol_txrx_vdev_t *vdev,
    struct ol_tx_desc_t *tx_desc,
    adf_nbuf_t msdu)
{
    struct ol_txrx_pdev_t *pdev = vdev->pdev;
    u_int16_t id;

    adf_os_atomic_dec(&pdev->target_tx_credit);

    /*
     * When the tx frame is downloaded to the target, there are two
     * outstanding references:
     * 1.  The host download SW (HTT, HTC, HIF)
     *     This reference is cleared by the ol_tx_send_done callback
     *     functions.
     * 2.  The target FW
     *     This reference is cleared by the ol_tx_completion_handler
     *     function.
     * It is extremely probable that the download completion is processed
     * before the tx completion message.  However, under exceptional
     * conditions the tx completion may be processed first.  Thus, rather
     * that assuming that reference (1) is done before reference (2),
     * explicit reference tracking is needed.
     * Double-increment the ref count to account for both references
     * described above.
     */

#if !ATH_11AC_TXCOMPACT
    adf_os_atomic_init(&tx_desc->ref_cnt);
    adf_os_atomic_inc(&tx_desc->ref_cnt);
    adf_os_atomic_inc(&tx_desc->ref_cnt); 
#endif

    id = ol_tx_desc_id(pdev, tx_desc);
    if (htt_tx_send_std(pdev->htt_pdev, tx_desc->htt_tx_desc, msdu, id)) {
/* TBD:
 * Would it be better to just free the descriptor, and return the netbuf
 * to the OS shim, rather than freeing both the descriptor and the
 * netbuf here?
 */
        adf_os_atomic_inc(&pdev->target_tx_credit);
        ol_tx_desc_frame_free_nonstd(pdev, tx_desc, 1 /* had error */);
    }
}

static inline void
ol_tx_download_done_base(
    struct ol_txrx_pdev_t *pdev,
    A_STATUS status,
    adf_nbuf_t msdu,
    u_int16_t msdu_id)
{
    struct ol_tx_desc_t *tx_desc;

    tx_desc = ol_tx_desc_find(pdev, msdu_id);
    adf_os_assert(tx_desc);
    if (status != A_OK) {
        ol_tx_desc_frame_free_nonstd(pdev, tx_desc, 1 /* download err */);
    } else {
#if !ATH_11AC_TXCOMPACT        
        if (adf_os_atomic_dec_and_test(&tx_desc->ref_cnt)) 
#endif            
        {
            /*
             * The decremented value was zero - free the frame.
             * Use the tx status recorded previously during
             * tx completion handling.
             */
            ol_tx_desc_frame_free_nonstd(
                pdev, tx_desc, tx_desc->status != htt_tx_status_ok);
        }
    }
}

void
ol_tx_download_done_ll(
    void *pdev,
    A_STATUS status,
    adf_nbuf_t msdu,
    u_int16_t msdu_id)
{
    ol_tx_download_done_base(
        (struct ol_txrx_pdev_t *) pdev, status, msdu, msdu_id);
}

void
ol_tx_download_done_hl_retain(
    void *txrx_pdev,
    A_STATUS status,
    adf_nbuf_t msdu,
    u_int16_t msdu_id)
{
    struct ol_txrx_pdev_t *pdev = txrx_pdev;
    ol_tx_download_done_base(pdev, status, msdu, msdu_id);
#if 0 /* TODO: Advanced feature */
    //ol_tx_dwl_sched(pdev, OL_TX_HL_SCHED_DOWNLOAD_DONE);
adf_os_assert(0);
#endif
}

void
ol_tx_download_done_hl_free(
    void *txrx_pdev,
    A_STATUS status,
    adf_nbuf_t msdu,
    u_int16_t msdu_id)
{
    struct ol_txrx_pdev_t *pdev = txrx_pdev;
    struct ol_tx_desc_t *tx_desc;

    tx_desc = ol_tx_desc_find(pdev, msdu_id);
    adf_os_assert(tx_desc);
    ol_tx_desc_frame_free_nonstd(pdev, tx_desc, status != A_OK);
#if 0 /* TODO: Advanced feature */
    //ol_tx_dwl_sched(pdev, OL_TX_HL_SCHED_DOWNLOAD_DONE);
adf_os_assert(0);
#endif
}

/*
 * The following macros could have been inline functions too.
 * The only rationale for choosing macros, is to force the compiler to inline
 * the implementation, which cannot be controlled for actual "inline" functions,
 * since "inline" is only a hint to the compiler.
 * In the performance path, we choose to force the inlining, in preference to
 * type-checking offered by the actual inlined functions.
 */
#define ol_tx_msdu_complete_batch(_pdev, _tx_desc, _tx_descs, _status)                          \
        do {                                                                                    \
                TAILQ_INSERT_TAIL(&(_tx_descs), (_tx_desc), tx_desc_list_elem);                 \
        } while (0)
#if !ATH_11AC_TXCOMPACT
#define ol_tx_msdu_complete_single(_pdev, _tx_desc, _netbuf, _lcl_freelist, _tx_desc_last)      \
        do {                                                                                    \
                adf_os_atomic_init(&(_tx_desc)->ref_cnt); /* clear the ref cnt */               \
                adf_nbuf_unmap((_pdev)->osdev, (_netbuf), ADF_OS_DMA_TO_DEVICE);                \
                adf_nbuf_free((_netbuf));                                                       \
                _tx_desc->allocated = 0;                                                        \
                ((union ol_tx_desc_list_elem_t *)(_tx_desc))->next = (_lcl_freelist);           \
                if (adf_os_unlikely(!lcl_freelist)) {                                           \
                    (_tx_desc_last) = (union ol_tx_desc_list_elem_t *)(_tx_desc);               \
                }                                                                               \
                (_lcl_freelist) = (union ol_tx_desc_list_elem_t *)(_tx_desc);                   \
        } while (0)
#else  /*!ATH_11AC_TXCOMPACT*/

#define ol_tx_msdu_complete_single(_pdev, _tx_desc, _netbuf, _lcl_freelist, _tx_desc_last)      \
        do {                                                                                    \
                adf_nbuf_unmap((_pdev)->osdev, (_netbuf), ADF_OS_DMA_TO_DEVICE);                \
                adf_nbuf_free((_netbuf));                                                       \
                _tx_desc->allocated = 0;                                                        \
                ((union ol_tx_desc_list_elem_t *)(_tx_desc))->next = (_lcl_freelist);           \
                if (adf_os_unlikely(!lcl_freelist)) {                                           \
                    (_tx_desc_last) = (union ol_tx_desc_list_elem_t *)(_tx_desc);               \
                }                                                                               \
                (_lcl_freelist) = (union ol_tx_desc_list_elem_t *)(_tx_desc);                   \
        } while (0)


#endif /*!ATH_11AC_TXCOMPACT*/

#if QCA_TX_SINGLE_COMPLETIONS 
    #if QCA_TX_STD_PATH_ONLY
        #define ol_tx_msdu_complete(_pdev, _tx_desc, _tx_descs, _netbuf, _lcl_freelist,         \
                                        _tx_desc_last, _status)                                 \
            ol_tx_msdu_complete_single((_pdev), (_tx_desc), (_netbuf), (_lcl_freelist),         \
                                             _tx_desc_last)
    #else   /* !QCA_TX_STD_PATH_ONLY */
        #define ol_tx_msdu_complete(_pdev, _tx_desc, _tx_descs, _netbuf, _lcl_freelist,         \
                                        _tx_desc_last, _status)                                 \
        do {                                                                                    \
            if (adf_os_likely((_tx_desc)->pkt_type == ol_tx_frm_std)) {                         \
                ol_tx_msdu_complete_single((_pdev), (_tx_desc), (_netbuf), (_lcl_freelist),     \
                                             (_tx_desc_last));                                  \
            } else {                                                                            \
                ol_tx_desc_frame_free_nonstd(                                                   \
                    (_pdev), (_tx_desc), (_status) != htt_tx_status_ok);                        \
            }                                                                                   \
        } while (0)
    #endif  /* !QCA_TX_STD_PATH_ONLY */
#else  /* !QCA_TX_SINGLE_COMPLETIONS */
    #if (QCA_TX_STD_PATH_ONLY)
        #define ol_tx_msdu_complete(_pdev, _tx_desc, _tx_descs, _netbuf, _lcl_freelist,         \
                                        _tx_desc_last, _status)                                 \
            ol_tx_msdus_complete_batch((_pdev), (_tx_desc), (_tx_descs), (_status))
    #else   /* !QCA_TX_STD_PATH_ONLY */
        #define ol_tx_msdu_complete(_pdev, _tx_desc, _tx_descs, _netbuf, _lcl_freelist,         \
                                        _tx_desc_last, _status)                                 \
        do {                                                                                    \
            if (adf_os_likely((_tx_desc)->pkt_type == ol_tx_frm_std)) {                         \
                ol_tx_msdu_complete_batch((_pdev), (_tx_desc), (_tx_descs), (_status));         \
            } else {                                                                            \
                ol_tx_desc_frame_free_nonstd(                                                   \
                    (_pdev), (_tx_desc), (_status) != htt_tx_status_ok);                        \
            }                                                                                   \
        } while (0)
    #endif  /* !QCA_TX_STD_PATH_ONLY */
#endif /* QCA_TX_SINGLE_COMPLETIONS */


#if QCA_OL_SUPPORT_RAWMODE_TXRX

void qca_raw_tx_chained_nbuf_unmap(ol_txrx_pdev_handle pdev, adf_nbuf_t netbuf)
{

    /* It is the responsibility of the caller to ensure that
     * adf_nbuf_next(netbuf) is non-NULL. This is for overall efficiency.
     */

    adf_nbuf_t chnbuf = adf_nbuf_next(netbuf);

    do {
        struct sk_buff *next = adf_nbuf_next(chnbuf);
        adf_nbuf_unmap_single(
                pdev->osdev, (adf_nbuf_t) chnbuf, ADF_OS_DMA_TO_DEVICE);
        adf_nbuf_free(chnbuf);
        chnbuf = next;
    } while (chnbuf);

    adf_nbuf_set_next(netbuf, NULL);
}

#define QCA_RAW_TX_CHAINED_NBUF_UNMAP(_pdev, _netbuf) \
            qca_raw_tx_chained_nbuf_unmap((_pdev), (_netbuf))
#else
#define QCA_RAW_TX_CHAINED_NBUF_UNMAP(_pdev, _netbuf) do {} while (0)
#endif /* QCA_OL_SUPPORT_RAWMODE_TXRX */


/* WARNING: ol_tx_inspect_handler()'s bahavior is similar to that of ol_tx_completion_handler().
 * any change in ol_tx_completion_handler() must be mirrored in ol_tx_inspect_handler().
 */
void
ol_tx_completion_handler(
    ol_txrx_pdev_handle pdev,
    int num_msdus,
    enum htt_tx_status status,
    void *tx_desc_id_iterator)
{
    int i;
    u_int16_t *desc_ids = (u_int16_t *)tx_desc_id_iterator;
    u_int16_t tx_desc_id;
    struct ol_tx_desc_t *tx_desc;
    struct ol_ath_softc_net80211 *scn =
                            (struct ol_ath_softc_net80211 *)pdev->ctrl_pdev;
    uint32_t   byte_cnt = 0;
    union ol_tx_desc_list_elem_t *td_array = pdev->tx_desc.array;
    adf_nbuf_t  netbuf;

    union ol_tx_desc_list_elem_t *lcl_freelist = NULL;
    union ol_tx_desc_list_elem_t *tx_desc_last = NULL;
    ol_tx_desc_list tx_descs;
    uint32_t bcastcnt=0;
    struct ieee80211_mac_stats *mac_stats;
    struct ieee80211vap *vap;
    struct ethhdr * eh;
    TAILQ_INIT(&tx_descs);
    for (i = 0; i < num_msdus; i++) {
        tx_desc_id = desc_ids[i];
        tx_desc = &td_array[tx_desc_id].tx_desc;
        tx_desc->status = status;
        netbuf = tx_desc->netbuf;

        if(!tx_desc->allocated)  {
           printk("MSDU is not allocated  MSDU ID is %d \n", tx_desc_id);
           continue;
        }
        /* Per SDU update of byte count */
        byte_cnt += adf_nbuf_len(netbuf);
        if (scn->scn_stats.ap_stats_tx_cal_enable) {
            if (tx_desc->tx_encap_type == htt_pkt_type_ethernet) {
                eh = (struct ethhdr *)adf_nbuf_data(netbuf);
                if (IEEE80211_IS_BROADCAST(eh->h_dest))
                    bcastcnt++;
            }
        }
#if !QCA_OL_11AC_FAST_PATH && !ATH_11AC_TXCOMPACT
        if (adf_os_atomic_dec_and_test(&tx_desc->ref_cnt))
#endif /* QCA_OL_11AC_FAST_PATH */
        {
            /* As an optimization, we do not check if Raw mode is enabled.
             * Currently, next pointer can be non-NULL only for Raw Mode.
             * TODO: Change this in the future if required.
             */
            if (OL_CFG_RAW_TX_LIKELINESS(adf_nbuf_next(netbuf) != NULL)) {
                QCA_RAW_TX_CHAINED_NBUF_UNMAP(pdev, netbuf);
            }

            ol_tx_msdu_complete(pdev, tx_desc, tx_descs, netbuf, lcl_freelist,
                                    tx_desc_last, status);
        }
    }
    if (scn->scn_stats.ap_stats_tx_cal_enable) {
        struct ol_txrx_peer_t *peer = NULL;
        switch (status) {
        case htt_tx_status_ok:
            peer = (pdev->tx_stats.peer_id == HTT_INVALID_PEER) ?
                        NULL : pdev->peer_id_to_obj_map[pdev->tx_stats.peer_id];
            if (peer) {
            /* TODO: Right now the data packets and bytes are not truly 
            *  the success packets and bytes the host driver assumes that
            *  the Firmware gave the successful packets count, on that assumption
            *  I am incrementing the counter. Inorder to have a correct
            *  count on the number of packets sent there has to be some
            *  code modification in the Firmware therefore,"TODO".
            */
                peer->peer_data_stats.data_packets = num_msdus;
                peer->peer_data_stats.data_bytes = byte_cnt;
                peer->peer_data_stats.thrup_bytes = byte_cnt;
                vap = ol_ath_vap_get(scn, peer->vdev->vdev_id);
                if (adf_os_likely(vap != NULL)) {
                    mac_stats =&vap->iv_multicast_stats;
                    mac_stats->ims_tx_bcast_data_packets += bcastcnt;
                }
            }
            pdev->tx_stats.peer_id = HTT_INVALID_PEER;
            break;
        case htt_tx_status_discard:
            peer = (pdev->tx_stats.peer_id == HTT_INVALID_PEER) ?
                NULL : pdev->peer_id_to_obj_map[pdev->tx_stats.peer_id];
            if (peer) {
                peer->peer_data_stats.discard_cnt = num_msdus;
            }
            break;
        default:
            break;
        }
    }
    /* One shot protected access to pdev freelist, when setup */
    if (lcl_freelist) {
        adf_os_spin_lock_bh(&pdev->tx_mutex);
        tx_desc_last->next = pdev->tx_desc.freelist;
        pdev->tx_desc.freelist = lcl_freelist; 
        adf_os_spin_unlock_bh(&pdev->tx_mutex);
        TXRX_STATS_SUB(pdev, pub.tx.desc_in_use, num_msdus);
    } else {
        ol_tx_desc_frame_list_free(pdev, &tx_descs, status != htt_tx_status_ok);
    }

    adf_os_atomic_add(num_msdus, &pdev->target_tx_credit);

#if OL_ATH_SUPPORT_LED
    {
        struct ol_ath_softc_net80211 *scn = (struct ol_ath_softc_net80211 *)pdev->ctrl_pdev;
        scn->scn_led_byte_cnt += byte_cnt;
        ol_ath_led_event(scn, OL_ATH_LED_TX);
    }
#endif

    /* Do one shot statistics */
    TXRX_STATS_UPDATE_TX_STATS(pdev, status, num_msdus, byte_cnt);
}

/* WARNING: ol_tx_inspect_handler()'s bahavior is similar to that of 
 * ol_tx_completion_handler(). any change in ol_tx_completion_handler() must be
 * mirrored here.
 */
void
ol_tx_inspect_handler(
    ol_txrx_pdev_handle pdev,
    int num_msdus,
    void *tx_desc_id_iterator)
{
    u_int16_t vdev_id, i;
    struct ol_txrx_vdev_t *vdev;
    u_int16_t *desc_ids = (u_int16_t *)tx_desc_id_iterator;
    u_int16_t tx_desc_id;
    struct ol_tx_desc_t *tx_desc;
    union ol_tx_desc_list_elem_t *td_array = pdev->tx_desc.array;
    union ol_tx_desc_list_elem_t *lcl_freelist = NULL;
    union ol_tx_desc_list_elem_t *tx_desc_last = NULL;
    adf_nbuf_t  netbuf;
#if OL_ATH_SUPPORT_LED
    uint32_t   byte_cnt = 0;
#endif
    ol_tx_desc_list tx_descs;
    TAILQ_INIT(&tx_descs);

    for (i = 0; i < num_msdus; i++) {
        tx_desc_id = desc_ids[i];
        tx_desc = &td_array[tx_desc_id].tx_desc;
        netbuf = tx_desc->netbuf;

#if OL_ATH_SUPPORT_LED
        byte_cnt += adf_nbuf_len(netbuf);
#endif

        /* find the "vdev" this tx_desc belongs to */
#if !QCA_OL_TX_CACHEDHDR
        vdev_id = HTT_TX_DESC_VDEV_ID_GET(*((u_int32_t *)(tx_desc->htt_tx_desc)));
#else
        adf_nbuf_unmap((pdev)->osdev, (netbuf), ADF_OS_DMA_TO_DEVICE);
        vdev_id = htt_data_get_vdev_id(netbuf->data);
        HTT_REMOVE_CACHED_HDR(netbuf);
#endif
        TAILQ_FOREACH(vdev, &pdev->vdev_list, vdev_list_elem) {
            if (vdev->vdev_id == vdev_id)
                break;
        }

        /* vdev now points to the vdev for this descriptor. */

#if UMAC_SUPPORT_PROXY_ARP || UMAC_SUPPORT_NAWDS || WDS_VENDOR_EXTENSION
        {
            struct ol_txrx_peer_t *peer;
            adf_nbuf_t  netbuf_copy;
#if WDS_VENDOR_EXTENSION
            int num_peers_3addr = 0, is_mcast = 0, is_ucast = 0;
            struct ether_header *eth_hdr = (struct ether_header *)(adf_nbuf_data(netbuf));
#define IS_MULTICAST(_a) (*(_a) & 0x01)
            is_mcast = (IS_MULTICAST(eth_hdr->ether_dhost)) ? 1 : 0;
            is_ucast = !is_mcast;
#undef IS_MULTICAST

            TAILQ_FOREACH(peer, &vdev->peer_list, peer_list_elem) {
                if (peer->bss_peer || (peer->peer_ids[0] == HTT_INVALID_PEER))
                    continue;

                /* count wds peers that use 3-addr framing for mcast.
                 * if there are any, the bss_peer is used to send the 
                 * the mcast frame using 3-addr format. all wds enabled
                 * peers that use 4-addr framing for mcast frames will
                 * be duplicated and sent as 4-addr frames below.
                 */
                if (!peer->wds_enabled || !peer->wds_tx_mcast_4addr)
                    num_peers_3addr ++;
            }
#endif
            TAILQ_FOREACH(peer, &vdev->peer_list, peer_list_elem) {
                if (peer) {
                    /* 
                     * osif_proxy_arp should always return true for NAWDS to work properly. 
                     */
                    if((peer->peer_ids[0] != HTT_INVALID_PEER) && 
#if WDS_VENDOR_EXTENSION
                            ((peer->bss_peer && num_peers_3addr) || 
                             (peer->wds_enabled && 
                              ((is_mcast && peer->wds_tx_mcast_4addr) || 
                               (is_ucast && peer->wds_tx_ucast_4addr))))
#else
                            (peer->bss_peer || peer->nawds_enabled)
#endif
#if UMAC_SUPPORT_PROXY_ARP
                            && !(vdev->osif_proxy_arp(vdev->osif_vdev, netbuf))
#endif
                            ) {
                        /* re-inject multicast packet back to target by copying.
                         * get a new descriptor and send this packet.
                         * TODO: optimize this code to not use skb_copy
                         */
                        netbuf_copy = adf_nbuf_copy(netbuf);
                        if (netbuf_copy) {
                            adf_nbuf_reset_ctxt(netbuf_copy);
			    OL_TX_REINJECT(vdev->pdev, vdev, netbuf_copy, peer->peer_ids[0]);
                        }
                    }//proxy arp or nawds_enabled if check
                }//peer NULL check
            }//TAILQ_FOREACH
        }
#endif // PROXY_ARP or NAWDS or WDS_VENDOR_EXTENSION
#if !QCA_OL_11AC_FAST_PATH && !ATH_11AC_TXCOMPACT
        /* save this multicast packet to local free list */
        if (adf_os_atomic_dec_and_test(&tx_desc->ref_cnt)) 
#endif            
        {
            /* As an optimization, we do not check if Raw mode is enabled.
             * Currently, next pointer can be non-NULL only for Raw Mode.
             * TODO: Change this in the future if required.
             */
            if (OL_CFG_RAW_TX_LIKELINESS(adf_nbuf_next(netbuf) != NULL)) {
                QCA_RAW_TX_CHAINED_NBUF_UNMAP(pdev, netbuf);
            }
 
            /* for this function only, force htt status to be "htt_tx_status_ok" 
             * for graceful freeing of this multicast frame
             */
#if !QCA_OL_TX_CACHEDHDR
            ol_tx_msdu_complete(pdev, tx_desc, tx_descs, netbuf, lcl_freelist,
                                    tx_desc_last, htt_tx_status_ok);
#else
	    adf_nbuf_free((netbuf));
	    ((union ol_tx_desc_list_elem_t *)(tx_desc))->next = (lcl_freelist);
	    if (adf_os_unlikely(!lcl_freelist)) {
		    (tx_desc_last) = (union ol_tx_desc_list_elem_t *)(tx_desc);
	    }
	    (lcl_freelist) = (union ol_tx_desc_list_elem_t *)(tx_desc);
#endif
        }
    }

    if (lcl_freelist) {
        adf_os_spin_lock_bh(&pdev->tx_mutex);
        tx_desc_last->next = pdev->tx_desc.freelist;
        pdev->tx_desc.freelist = lcl_freelist; 
        adf_os_spin_unlock_bh(&pdev->tx_mutex);
        TXRX_STATS_SUB(pdev, pub.tx.desc_in_use, num_msdus);
    } else {
        ol_tx_desc_frame_list_free(pdev, &tx_descs, htt_tx_status_discard);
    }
    adf_os_atomic_add(num_msdus, &pdev->target_tx_credit);

#if OL_ATH_SUPPORT_LED
    {
        struct ol_ath_softc_net80211 *scn = (struct ol_ath_softc_net80211 *)pdev->ctrl_pdev;
        scn->scn_led_byte_cnt += byte_cnt;
        ol_ath_led_event(scn, OL_ATH_LED_TX);
    }
#endif

    return;
}

