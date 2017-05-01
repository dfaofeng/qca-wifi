/*
 * Copyright (c) 2011-2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#include <adf_nbuf.h>         /* adf_nbuf_t, etc. */


#if QCA_OL_11AC_FAST_PATH
#include <hif.h>              /* HIF_DEVICE */
#endif
#include <htt.h>              /* HTT_TX_EXT_TID_MGMT */
#if QCA_OL_11AC_FAST_PATH
#include <htt_internal.h>     /* */
#include <htt_types.h>        /* htc_endpoint */
#endif
#include <ol_htt_tx_api.h>    /* htt_tx_desc_tid */
#include <ol_txrx_api.h>      /* ol_txrx_vdev_handle */
#include <ol_txrx_ctrl_api.h> /* ol_txrx_sync */

#include <ol_txrx_internal.h> /* TXRX_ASSERT1 */
#include <ol_txrx_types.h>    /* pdev stats */
#include <ol_tx_desc.h>       /* ol_tx_desc */
#include <ol_tx_send.h>       /* ol_tx_send */

#if ATH_DEBUG
#include "osif_private.h"
extern void set_rtscts_enable(void * vosdev);
#define ATH_DEBUG_SET_RTSCTS_ENABLE(_osdev) set_rtscts_enable(_osdev)
#else
#define ATH_DEBUG_SET_RTSCTS_ENABLE(_osdev)
#endif

#if QCA_OL_11AC_FAST_PATH
#include <htc_api.h>         /* Layering violation, but required for fast path */
#include <copy_engine_api.h>
#endif  /* QCA_OL_11AC_FAST_PATH */

#define ol_tx_prepare_ll(tx_desc, vdev, msdu) \
    do {                                                                      \
        /*
         * The TXRX module doesn't accept tx frames unless the target has
         * enough descriptors for them.
         */                                                                   \
        if (adf_os_atomic_read(&vdev->pdev->target_tx_credit) <= 0) {         \
            TXRX_STATS_MSDU_LIST_INCR(                                        \
                vdev->pdev, tx.dropped.host_reject, msdu);                    \
            return msdu;                                                      \
        }                                                                     \
                                                                              \
        tx_desc = ol_tx_desc_ll(vdev->pdev, vdev, msdu);                      \
        if (! tx_desc) {                                                      \
            TXRX_STATS_MSDU_LIST_INCR(                                        \
                vdev->pdev, tx.dropped.host_reject, msdu);                    \
            return msdu; /* the list of unaccepted MSDUs */                   \
        }                                                                     \
        OL_TXRX_PROT_AN_LOG(vdev->pdev->prot_an_tx_sent, msdu);               \
    } while (0)

/* wrapper func for the inline function in ol_tx_desc.h */
u_int16_t
ol_tx_desc_alloc_and_mark_for_mcast_clone(struct ol_txrx_pdev_t *pdev, u_int16_t buf_count)
{
    return (ol_tx_desc_alloc_for_mcast_clone(pdev, buf_count));
}

/* wrappers func for the inline function in ol_tx_desc.h */
u_int16_t
ol_tx_desc_free_and_unmark_for_mcast_clone(struct ol_txrx_pdev_t *pdev, u_int16_t buf_count)
{
    return (ol_tx_desc_free_for_mcast_clone(pdev, buf_count));
}

/* function to get the value from txrx structure, instead of accessing directly */
u_int16_t
ol_tx_get_mcast_buf_allocated_marked(struct ol_txrx_pdev_t *pdev)
{
    return(pdev->allocated_marked);
}

adf_nbuf_t
ol_tx_ll(ol_txrx_vdev_handle vdev, adf_nbuf_t msdu_list)
{
    adf_nbuf_t msdu = msdu_list;
    /*
     * The msdu_list variable could be used instead of the msdu var,
     * but just to clarify which operations are done on a single MSDU
     * vs. a list of MSDUs, use a distinct variable for single MSDUs
     * within the list.
     */
    while (msdu) {
        adf_nbuf_t next;
        struct ol_tx_desc_t *tx_desc;

        ol_tx_prepare_ll(tx_desc, vdev, msdu);
        /*
         * If debug display is enabled, show the meta-data being
         * downloaded to the target via the HTT tx descriptor.
         */
        htt_tx_desc_display(tx_desc->htt_tx_desc);
        /*
         * The netbuf may get linked into a different list inside the
         * ol_tx_send function, so store the next pointer before the
         * tx_send call.
         */
        next = adf_nbuf_next(msdu);
        ol_tx_send(vdev, tx_desc, msdu);
        msdu = next;
    }
    return NULL; /* all MSDUs were accepted */
}

#if QCA_OL_11AC_FAST_PATH

#define OL_HTT_TX_DESC_FILL(_htt_pdev, _htt_tx_desc, _tx_desc_id,           \
            _vdev_id, _msdu_paddr, _msdu_len, _pkt_cksum)                   \
do  {                                                                       \
    uint32_t *word;                                                         \
    htt_tx_desc_init((_htt_pdev), (_htt_tx_desc), (_tx_desc_id),            \
         (_msdu_len), (_vdev_id), htt_pkt_type_ethernet, (_pkt_cksum),      \
         ADF_NBUF_TX_EXT_TID_INVALID);                                      \
                                                                            \
    word = (u_int32_t *) (((char *)(_htt_tx_desc)) + HTT_TX_DESC_LEN);      \
    *word = (_msdu_paddr);                                                  \
    word++;                                                                 \
    *word = (_msdu_len);                                                    \
    word++;                                                                 \
    *word = 0;                                                              \
} while (0)


#if QCA_OL_SUPPORT_RAWMODE_TXRX

#define OL_HTT_RAW_TX_DESC_FILL(_htt_pdev, _htt_tx_desc, _tx_desc_id,       \
            _vdev_id, _first_frag_paddr, _total_len, _pkt_cksum,            \
            _first_frag_len)                                                \
do  {                                                                       \
    uint32_t *word;                                                         \
    htt_tx_desc_init((_htt_pdev), (_htt_tx_desc), (_tx_desc_id),            \
         (_total_len), (_vdev_id), htt_pkt_type_raw, (_pkt_cksum),          \
         ADF_NBUF_TX_EXT_TID_INVALID);                                      \
                                                                            \
    word = (u_int32_t *) (((char *)(_htt_tx_desc)) + HTT_TX_DESC_LEN);      \
    *word = (_first_frag_paddr);                                            \
    word++;                                                                 \
    *word = (_first_frag_len);                                              \
    word++;                                                                 \
    *word = 0;                                                              \
} while (0)

void
ol_tx_prepare_raw_desc(struct ol_txrx_pdev_t *pdev,
        ol_txrx_vdev_handle vdev,
        adf_nbuf_t nbuf,
        struct ol_tx_desc_t *tx_desc)
{
    u_int32_t tot_len = 0;
    /* Number of non-master nbufs */ 
    uint32_t num_frags = 0;
    adf_nbuf_t tempnbuf = NULL, next = NULL;
    uint32_t *htt_tx_desc = tx_desc->htt_tx_desc;
    u_int8_t sub_type = 0;

    adf_nbuf_frags_num_init(nbuf);
    tot_len = adf_nbuf_len(nbuf);
    tempnbuf = adf_nbuf_next(nbuf);

    while(tempnbuf) {
        next = adf_nbuf_next(tempnbuf);
        num_frags++;
        adf_nbuf_frags_num_init(tempnbuf);
        tot_len += adf_nbuf_len(tempnbuf);
        htt_tx_desc_frag(pdev->htt_pdev,
                tx_desc->htt_tx_desc,
                num_frags,
                adf_nbuf_get_frag_paddr_lo(tempnbuf, 1),
                adf_nbuf_len(tempnbuf));

        tempnbuf = next;
    }
    
    if (num_frags) {
        htt_tx_desc_num_frags(pdev->htt_pdev,
                tx_desc->htt_tx_desc,
                num_frags + 1);
    }
    
    /* HTT Header */
    OL_HTT_RAW_TX_DESC_FILL(pdev->htt_pdev, htt_tx_desc, tx_desc->id,
        vdev->vdev_id, adf_nbuf_get_frag_paddr_lo(nbuf, 1), tot_len,
        adf_nbuf_get_tx_cksum(nbuf), adf_nbuf_len(nbuf));
    
    /*Detailed specification of the tx frame contents*/

    /* 802.11 MAC Header present. */
    sub_type = 0x1;
    
    /* Don't allow aggregation. */ 
    sub_type |= 0x1 << HTT_TX_MSDU_DESC_RAW_SUBTYPE_NO_AGGR_S;
    
    /* Important note for end system integrators:
     * The following flag needs to be set, or kept clear, according to the
     * desired VAP configuration.
     *
     * The flag is being kept clear in this code base since the reference
     * code does not interact with any external entity that would carry
     * out the requisite encryption.
     */
#if 0
     /* Illustration only. */
     if (condition) {
         /*  Don't perform encryption */
         sub_type |= 0x1 << HTT_TX_MSDU_DESC_RAW_SUBTYPE_NO_ENCRYPT_S;
     }
#endif
        
     OL_HTT_TX_DESC_SUBTYPE(htt_tx_desc, sub_type);
}

#define OL_TX_PREPARE_RAW_DESC(_pdev, _vdev, _nbuf, _tx_desc) \
            ol_tx_prepare_raw_desc((_pdev), (_vdev), (_nbuf), (_tx_desc))
#else
#define OL_TX_PREPARE_RAW_DESC(_pdev, _vdev, _nbuf, _tx_desc) \
            do {} while (0)
#endif /* QCA_OL_SUPPORT_RAWMODE_TXRX */


static inline
struct ol_tx_desc_t *ol_tx_prepare_ll_fast(struct ol_txrx_pdev_t *pdev,
                           ol_txrx_vdev_handle vdev,
                           adf_nbuf_t nbuf,
                           uint32_t pkt_download_len,
                           uint32_t ep_id)
{
    struct ol_tx_desc_t *tx_desc = NULL;
    uint32_t *htt_tx_desc;
    void *htc_hdr_vaddr;
    uint32_t htc_hdr_paddr_lo; /* LSB of physical address */

    tx_desc = ol_tx_desc_alloc(pdev);
    if (adf_os_unlikely(!tx_desc)) {
        TXRX_STATS_ADD(pdev, pub.tx.desc_alloc_fails, 1);
        return NULL;
    }

    tx_desc->netbuf = nbuf;
    tx_desc->pkt_type = ol_tx_frm_std; /* this can be prefilled? */
    tx_desc->tx_encap_type = vdev->tx_encap_type;

    htt_tx_desc = tx_desc->htt_tx_desc;

    if (OL_CFG_NONRAW_TX_LIKELINESS(vdev->tx_encap_type != htt_pkt_type_raw)) {
        /* Make sure frags num is set to 0 */
        /* 
         * Do this here rather than in hardstart, so
         * that we can hopefully take only one cache-miss while
         * accessing skb->cb.
         */ 
        adf_nbuf_frags_num_init(nbuf);

        /* HTT Header */
        /* TODO : Take care of multiple fragments */
        OL_HTT_TX_DESC_FILL(pdev->htt_pdev, htt_tx_desc, tx_desc->id, vdev->vdev_id,
            adf_nbuf_get_frag_paddr_lo(nbuf, 1), adf_nbuf_len(nbuf),
            adf_nbuf_get_tx_cksum(nbuf));
    } else {
        OL_TX_PREPARE_RAW_DESC(pdev, vdev, nbuf, tx_desc);
    }
     
    /* Virtual address of the HTT/HTC header, added by driver */
    htc_hdr_vaddr = (char *)htt_tx_desc - HTC_HEADER_LEN;

    /* TODO: Precompute and store paddr in ol_tx_desc_t */
    htc_hdr_paddr_lo = (u_int32_t)
		      HTT_TX_DESC_PADDR(pdev->htt_pdev, htc_hdr_vaddr);

    /* Add meta-data for the HTT/HTC header fragment to nbuf->cb */
    /* After this point num_extra_frags = 1 */
    /* Can this be passed as parameters to CE to program?
	 * Why should we store this at all ?
	 */
    adf_nbuf_frag_push_head(
		              nbuf,
                      HTC_HEADER_LEN + HTT_TX_DESC_LEN,
                      htc_hdr_vaddr, htc_hdr_paddr_lo /*phy addr LSB*/,
                      0 /* phy addr MSB */);

    /*
     *  Do we want to turn on word_stream bit-map here ? For linux, non-TSO this is
     *  not required.
     *  We still have to mark the swap bit correctly, when posting to the ring
     */
    /* Check to make sure, data download length is correct */

    /* TODO : Can we remove this check and always download a fixed length ? */
    if (adf_os_unlikely(adf_nbuf_len(nbuf) < pkt_download_len)) {
        pkt_download_len = adf_nbuf_len(nbuf);
    }

    /* Fill the HTC header information */
    /*
     * Passing 0 as the seq_no field, we can probably get away
     * with it for the time being, since this is not checked in f/w
     */
    /* TODO : Prefill this, look at multi-fragment case */
    HTC_TX_DESC_FILL(htc_hdr_vaddr, pkt_download_len, ep_id, 0);

    return tx_desc;
}
/*
 * ol_tx_ll_fast(): Fast path OL layer send function
 * Function:
 * 1) Get OL Tx desc
 * 2) Fill out HTT + HTC headers
 * 3) Fill out SG list
 * 4) Store meta-data (implicit, because we use pre-allocated pool)
 * 5) Call CE send function
 * Returns:
 *  No. of nbufs that could not be sent.
 */

#if ATH_SUPPORT_HYFI_ENHANCEMENTS

extern void ol_notify_if_low_on_buffers(void *scn, uint32_t free_buff);
#define ATH_HYFI_NOTIFY_LOW_ON_BUFFER( _ctrldev, _freebuff) \
    ol_notify_if_low_on_buffers(_ctrldev, (pdev->tx_desc.pool_size - pdev->stats.pub.tx.desc_in_use));
#else

#define ATH_HYFI_NOTIFY_LOW_ON_BUFFER( _scn, _freebuff)

#endif

uint32_t
ol_tx_ll_fast(ol_txrx_vdev_handle vdev,
              adf_nbuf_t *nbuf_arr,
              uint32_t num_msdus)
{
    struct ol_txrx_pdev_t *pdev = vdev->pdev;
    struct ol_tx_desc_t *tx_desc = NULL;
    adf_nbuf_t nbuf;
    uint32_t pkt_download_len, num_sent = 0;
    uint32_t ep_id;
    int i = 0;

    ATH_DEBUG_SET_RTSCTS_ENABLE(vdev->osif_vdev);
    ASSERT(num_msdus);
    pkt_download_len = ((struct htt_pdev_t *)(pdev->htt_pdev))->download_len;

    /* This can be statically inited once, during allocation */
    /* Call this HTC_HTTEPID_GET */
    ep_id = HTT_EPID_GET(pdev->htt_pdev);

    /* TODO : Can we batch alloc OL tx descriptors? */

    for (i = 0; i < num_msdus; i++) {
        nbuf = nbuf_arr[i];
        if (!(tx_desc = ol_tx_prepare_ll_fast(pdev,
                vdev, nbuf, pkt_download_len, ep_id))) {
            break;
        }
    }

    /*
     * If we could get descriptor for i packets, just send them one shot
     * to the CE ring
     * Assumption: if there is enough descriptors i should be equal to num_msdus
     */
    if (i) {
        num_sent = CE_send_fast(pdev->ce_tx_hdl, nbuf_arr, i, ep_id);
    }

    ASSERT((num_msdus - num_sent) == 0);

    /* Assume num_msdus == 1 */
    if ((num_sent == 0) && tx_desc) {
        ol_tx_desc_free(pdev, tx_desc);
    }

    ATH_HYFI_NOTIFY_LOW_ON_BUFFER(pdev->ctrl_pdev, (pdev->tx_desc.pool_size - pdev->stats.pub.tx.desc_in_use));

    /*
     * If there was only a partial send,
     * send the part of the nbuf_arr that could not be
     * sent back to the caller.
     */
    return (num_msdus - num_sent);
}

adf_nbuf_t ol_tx_reinject_fast(
        struct ol_txrx_vdev_t *vdev,
        adf_nbuf_t msdu, uint32_t peer_id)
{
    struct ol_tx_desc_t *tx_desc;
    struct ol_txrx_pdev_t *pdev = vdev->pdev;
    uint32_t pkt_download_len =
        ((struct htt_pdev_t *)(pdev->htt_pdev))->download_len;
    uint32_t ep_id = HTT_EPID_GET(pdev->htt_pdev);

    tx_desc = ol_tx_prepare_ll_fast(pdev, vdev, msdu,
            pkt_download_len, ep_id);

    if (adf_os_likely(tx_desc)) {
        /* Additional plumbing for re-injection */
        HTT_TX_DESC_POSTPONED_SET(*((u_int32_t *)(tx_desc->htt_tx_desc)), TRUE);
        htt_tx_desc_set_peer_id((u_int32_t *)(tx_desc->htt_tx_desc), peer_id);

        if ((0 == CE_send_fast(pdev->ce_tx_hdl, &msdu, 1, ep_id))) {
            /* The packet could not be sent */
            /* Free the descriptor, return the packet to the caller */
            ol_tx_desc_free(pdev, tx_desc);
            return msdu;
        }
    }

    return NULL;
}
#ifdef QCA_PARTNER_PLATFORM
void
ol_tx_stats_inc_pkt_cnt(ol_txrx_vdev_handle vdev)
#else
inline void
ol_tx_stats_inc_pkt_cnt(ol_txrx_vdev_handle vdev)
#endif
{
    struct ol_txrx_pdev_t *pdev = vdev->pdev;

    TXRX_STATS_ADD(pdev, pub.tx.from_stack.pkts, 1);
}

void
ol_tx_stats_inc_map_error(ol_txrx_vdev_handle vdev,
                             uint32_t num_map_error)
{
    struct ol_txrx_pdev_t *pdev = vdev->pdev;

    TXRX_STATS_ADD(pdev, pub.tx.dma_map_error, 1);
}

void
ol_tx_stats_inc_ring_error(ol_txrx_pdev_handle pdev,
                             uint32_t num_ring_error)
{
    TXRX_STATS_ADD(pdev, pub.tx.ce_ring_full, 1);
}

void ol_dump_txdesc(struct ol_tx_desc_t *tx_desc)
{
    adf_os_print("\nhtt_tx_desc bad for tx_desc:%p, id (%d), htt_tx_status (%d), allocated (%d)\n",tx_desc, tx_desc->id, tx_desc->status, tx_desc->allocated);
}

#if QCA_OL_TX_CACHEDHDR

#if QCA_OL_SUPPORT_RAWMODE_TXRX
int32_t 
ol_tx_prepare_raw_desc_chdhdr(
        ol_txrx_vdev_handle vdev,
        adf_nbuf_t netbuf,
        u_int32_t *htt_tx_desc)
{
    a_uint32_t total_frag_len = 0;
    adf_nbuf_t currnbuf = NULL, nextnbuf = NULL;
    /* Index into fragment descriptor table from where we can
       begin to pre-fill non-master fragment physical addresses. Derived from
       main code where master fragment physical address is filled in. */
    int idx = 6;
        
    /* Process the non-master nbufs in the chain, if any.
     * We need to carry out this processing at this point in order to
     * determine total data length. We piggy-back other operations to avoid
     * additional loops later.
     */
    currnbuf = adf_nbuf_next(netbuf);

    while (currnbuf) {
        adf_nbuf_frags_num_init(currnbuf);

        if(A_STATUS_FAILED ==
            adf_nbuf_map_single(vdev->osdev,
                currnbuf,
                ADF_OS_DMA_TO_DEVICE)) {
            adf_os_print("DMA Mapping error \n");

            /* Free all nbufs in the chain */
            currnbuf = netbuf;
            while (currnbuf) {
                nextnbuf = adf_nbuf_next(currnbuf);
                adf_nbuf_free(currnbuf);
                currnbuf = nextnbuf;
            }
            return -1;
        }

        /* adf_nbuf_len() is a light-weight inline dereferencing operation
         * hence we do not store it into a local variable for second reuse.
         * Can revisit this if later extensions require more than two
         * accesses.
         */
         total_frag_len += adf_nbuf_len(currnbuf);

         /* Pre-fill physical addresses into fragment descriptor table. */
         htt_tx_desc[idx] = adf_nbuf_get_frag_paddr_lo(currnbuf, 0);
         htt_tx_desc[idx + 1] = adf_nbuf_len(currnbuf);
         idx += 2;

         currnbuf = adf_nbuf_next(currnbuf);
    }

    return total_frag_len;
}

#define OL_TX_PREPARE_RAW_DESC_CHDHDR(_vdev, _nbuf, _htt_tx_desc) \
            ol_tx_prepare_raw_desc_chdhdr((_vdev), (_nbuf), (_htt_tx_desc))
#else
#define OL_TX_PREPARE_RAW_DESC_CHDHDR(_vdev, _nbuf, _htt_tx_desc) (0)
#endif

struct ol_tx_desc_t *
ol_tx_ll_cachedhdr_prep(ol_txrx_vdev_handle vdev,
        adf_nbuf_t netbuf, uint32_t peerid)
{

    struct ol_txrx_pdev_t *pdev = vdev->pdev;
    struct ol_tx_desc_t *tx_desc = NULL;
    u_int8_t *data;
    a_uint8_t *netdata;
    a_uint32_t netlen;
    int ret = 0;
    adf_nbuf_t currnbuf = NULL, nextnbuf = NULL;

    u_int32_t *hdr_cache = vdev->hdrcache;
    u_int16_t msdu_len =  adf_nbuf_len(netbuf);
    u_int16_t total_len;
    u_int32_t *htt_tx_desc;
    u_int32_t frag_paddr;

    tx_desc = ol_tx_desc_alloc(pdev);
    if (adf_os_unlikely(!tx_desc)) {
        TXRX_STATS_ADD(pdev, pub.tx.desc_alloc_fails, 1);
        ol_vap_txdiscard_stats_update(vdev->osif_vdev, netbuf);
        adf_nbuf_free(netbuf);
        return NULL;
    }
    tx_desc->netbuf = netbuf;
    tx_desc->tx_encap_type = vdev->tx_encap_type;

    htt_tx_desc = (u_int32_t *) tx_desc->htt_tx_desc;
    
    total_len = msdu_len;

    if (OL_CFG_RAW_TX_LIKELINESS(vdev->tx_encap_type == htt_pkt_type_raw)) {
        ret = OL_TX_PREPARE_RAW_DESC_CHDHDR(vdev, netbuf, htt_tx_desc);
        if (ret ==  -1) {
            return NULL;
        } else {
            total_len += ret;
        }
    }

    htt_ffcache_update_vdev_id(hdr_cache, vdev->vdev_id);
    htt_ffcache_update_msdu_len_and_id(hdr_cache, total_len, tx_desc->id);
    htt_ffcache_update_descphy_addr(hdr_cache, htt_tx_desc);
    data = adf_nbuf_push_head(netbuf, HTC_HTT_TRANSFER_HDRSIZE);
    adf_os_mem_copy(data, hdr_cache, HTC_HTT_TRANSFER_HDRSIZE);

    adf_nbuf_peek_header(netbuf, &netdata, &netlen);
    /* Additional plumbing for re-injection */
    if(peerid != HTT_INVALID_PEER){
        htt_data_desc_postponed_set(netdata);
        htt_data_desc_set_peer_id(netdata, peerid);
    }

    if(A_STATUS_FAILED == adf_nbuf_map_nbytes_single(vdev->osdev, netbuf, ADF_OS_DMA_TO_DEVICE, netlen)){
        adf_os_print("Map error \n");
        if (OL_CFG_RAW_TX_LIKELINESS(vdev->tx_encap_type == htt_pkt_type_raw)) {
            /* Free all non master nbufs in the chain, if any */
            currnbuf = adf_nbuf_next(netbuf);
            while (currnbuf) {
                nextnbuf = adf_nbuf_next(currnbuf);
                adf_nbuf_free(currnbuf);
                currnbuf = nextnbuf;
            }
        }
        adf_nbuf_free(netbuf);
        return NULL;
    }

    frag_paddr = adf_nbuf_get_frag_paddr_lo(netbuf, 0);
    htt_tx_desc[4] = frag_paddr + HTC_HTT_TRANSFER_HDRSIZE;
    htt_tx_desc[5] = msdu_len;

    return tx_desc;
}

uint32_t
ol_tx_ll_cachedhdr(ol_txrx_vdev_handle vdev,  adf_nbuf_t netbuf )
{
    struct ol_txrx_pdev_t *pdev = vdev->pdev;
    uint32_t pkt_download_len, headroom;
    struct ol_tx_desc_t *tx_desc;
    u_int16_t msdu_len ;

    ATH_DEBUG_SET_RTSCTS_ENABLE(vdev->osif_vdev);

    adf_nbuf_frags_num_init(netbuf);
    if (adf_os_unlikely((headroom = adf_nbuf_headroom(netbuf))< HTC_HTT_TRANSFER_HDRSIZE)){
        netbuf = adf_nbuf_realloc_headroom(netbuf, HTC_HTT_TRANSFER_HDRSIZE);
        if (netbuf == NULL ){
            adf_os_print("Realloc failed \n");
            goto out;
        }
    }

    if ((tx_desc = ol_tx_ll_cachedhdr_prep(vdev, netbuf, HTT_INVALID_PEER)) == NULL){
        goto out ;
    }

    msdu_len =  adf_nbuf_len(netbuf);
    pkt_download_len = vdev->downloadlen;

    if ( msdu_len + HTC_HTT_TRANSFER_HDRSIZE < pkt_download_len) {
        /*
         * This case of packet length being less than the nominal download
         * length can happen for a couple reasons:
         * In HL, the nominal download length is a large artificial value.
         * In LL, the frame may not have the optional header fields
         * accounted for in the nominal download size (LLC/SNAP header,
         * IPv4 or IPv6 header).
         */
        pkt_download_len = msdu_len + HTC_HTT_TRANSFER_HDRSIZE;
    }


    if(CE_send_single(pdev->ce_tx_hdl, netbuf, vdev->epid, pkt_download_len)){
        ol_tx_desc_free(pdev, tx_desc);
        adf_nbuf_unmap_single( vdev->osdev, (adf_nbuf_t) netbuf, ADF_OS_DMA_TO_DEVICE);
        ol_vap_txdiscard_stats_update(vdev->osif_vdev, netbuf);
        adf_nbuf_free(netbuf);
    }
out :

    ATH_HYFI_NOTIFY_LOW_ON_BUFFER(pdev->ctrl_pdev, (pdev->tx_desc.pool_size - pdev->stats.pub.tx.desc_in_use));
    return 0;

}
adf_nbuf_t ol_tx_reinject_cachedhdr(
        struct ol_txrx_vdev_t *vdev,
        adf_nbuf_t msdu, uint32_t peer_id)
{
    struct ol_txrx_pdev_t *pdev = vdev->pdev;
    struct ol_tx_desc_t *tx_desc;

    if ((tx_desc = ol_tx_ll_cachedhdr_prep(vdev, msdu, peer_id)) == NULL){
        goto out;
    }

    if(CE_send_single(pdev->ce_tx_hdl, 	msdu,	vdev->epid, vdev->downloadlen)){
        ol_tx_desc_free(pdev, tx_desc);
        adf_nbuf_unmap_single( vdev->osdev, (adf_nbuf_t)msdu, ADF_OS_DMA_TO_DEVICE);
        adf_nbuf_free(msdu);
    }

out :
    return 0;
}

#endif /* QCA_OL_TX_CACHEDHDR*/
#endif /* QCA_OL_11AC_FAST_PATH */

static inline int
OL_TXRX_TX_IS_RAW(enum ol_txrx_osif_tx_spec tx_spec)
{
    return
        tx_spec &
        (ol_txrx_osif_tx_spec_raw |
         ol_txrx_osif_tx_spec_no_aggr |
         ol_txrx_osif_tx_spec_no_encrypt);
}

static inline u_int8_t
OL_TXRX_TX_RAW_SUBTYPE(enum ol_txrx_osif_tx_spec tx_spec)
{
    u_int8_t sub_type = 0x1; /* 802.11 MAC header present */

    if (tx_spec & ol_txrx_osif_tx_spec_no_aggr) {
        sub_type |= 0x1 << HTT_TX_MSDU_DESC_RAW_SUBTYPE_NO_AGGR_S;
    }
    if (tx_spec & ol_txrx_osif_tx_spec_no_encrypt) {
        sub_type |= 0x1 << HTT_TX_MSDU_DESC_RAW_SUBTYPE_NO_ENCRYPT_S;
    }
    if (tx_spec & ol_txrx_osif_tx_spect_nwifi_no_encrypt) {
        sub_type |= 0x1 << HTT_TX_MSDU_DESC_RAW_SUBTYPE_NO_ENCRYPT_S;
    }
    return sub_type;
}

adf_nbuf_t
ol_tx_non_std_ll(
    ol_txrx_vdev_handle vdev,
    u_int8_t ext_tid,
    enum ol_txrx_osif_tx_spec tx_spec,
    adf_nbuf_t msdu_list)
{
    adf_nbuf_t msdu = msdu_list;
    htt_pdev_handle htt_pdev = vdev->pdev->htt_pdev;
    /*
     * The msdu_list variable could be used instead of the msdu var,
     * but just to clarify which operations are done on a single MSDU
     * vs. a list of MSDUs, use a distinct variable for single MSDUs
     * within the list.
     */
    while (msdu) {
        adf_nbuf_t next;
        struct ol_tx_desc_t *tx_desc;

        ol_tx_prepare_ll(tx_desc, vdev, msdu);

        /*
         * The netbuf may get linked into a different list inside the
         * ol_tx_send function, so store the next pointer before the
         * tx_send call.
         */
        next = adf_nbuf_next(msdu);

        if (tx_spec != ol_txrx_osif_tx_spec_std) {
            if (tx_spec & ol_txrx_osif_tx_spec_tso) {
                tx_desc->pkt_type = ol_tx_frm_tso;
            } else if (tx_spec & ol_txrx_osif_tx_spect_nwifi_no_encrypt) {
                u_int8_t sub_type = OL_TXRX_TX_RAW_SUBTYPE(tx_spec);
                htt_tx_desc_type(
                    htt_pdev, tx_desc->htt_tx_desc,
                    htt_pkt_type_native_wifi, sub_type);
            } else if (OL_TXRX_TX_IS_RAW(tx_spec)) {
                /* different types of raw frames */
                u_int8_t sub_type = OL_TXRX_TX_RAW_SUBTYPE(tx_spec);
                htt_tx_desc_type(
                    htt_pdev, tx_desc->htt_tx_desc,
                    htt_pkt_type_raw, sub_type);
            }
        }
        /* explicitly specify the TID and the limit
         * it to the 0-15 value of the QoS TID.
         */

        if (ext_tid >= HTT_TX_EXT_TID_NON_QOS_MCAST_BCAST) {
            ext_tid = HTT_TX_EXT_TID_DEFAULT;
        }
        htt_tx_desc_tid(htt_pdev, tx_desc->htt_tx_desc, ext_tid);

        /*
         * If debug display is enabled, show the meta-data being
         * downloaded to the target via the HTT tx descriptor.
         */
        htt_tx_desc_display(tx_desc->htt_tx_desc);
        ol_tx_send(vdev, tx_desc, msdu);
        msdu = next;
    }
    return NULL; /* all MSDUs were accepted */
}

adf_nbuf_t
ol_tx_hl(ol_txrx_vdev_handle vdev, adf_nbuf_t msdu_list)
{
    adf_nbuf_t msdu;

    /*
     * TBDXXX - TXRX module for now only downloads number
     * of descriptors that target could accept.
     */
    if (adf_os_atomic_read(&vdev->pdev->target_tx_credit) <= 0) {
        return msdu_list;
    }

    /*
     * The msdu_list variable could be used instead of the msdu var,
     * but just to clarify which operations are done on a single MSDU
     * vs. a list of MSDUs, use a distinct variable for single MSDUs
     * within the list.
     */
    msdu = msdu_list;
    while (msdu) {
        adf_nbuf_t next;
        struct ol_tx_desc_t *tx_desc;
        tx_desc = ol_tx_desc_hl(vdev->pdev, vdev, msdu);
        if (! tx_desc) {
            TXRX_STATS_MSDU_LIST_INCR(vdev->pdev, tx.dropped.host_reject, msdu);
            return msdu; /* the list of unaccepted MSDUs */
        }
        OL_TXRX_PROT_AN_LOG(vdev->pdev->prot_an_tx_sent, msdu);
        /*
         * If debug display is enabled, show the meta-data being
         * downloaded to the target via the HTT tx descriptor.
         */
        htt_tx_desc_display(tx_desc->htt_tx_desc);
        /*
         * The netbuf will get stored into a (peer-TID) tx queue list
         * inside the ol_tx_classify_store function, so store the next
         * pointer before the tx_classify_store call.
         */
        next = adf_nbuf_next(msdu);
/*
 * FIX THIS:
 * 2.  Call tx classify to determine peer and TID.
 * 3.  Store the frame in a peer-TID queue.
 */
//        ol_tx_classify_store(vdev, tx_desc, msdu);
        /*
         * FIX THIS
         * temp FIFO for bringup
         */
        ol_tx_send(vdev, tx_desc, msdu);
        msdu = next;
    }
/*
 * FIX THIS:
 * 4.  Invoke the download scheduler.
 */
//    ol_tx_dl_sched(vdev->pdev);

    return NULL; /* all MSDUs were accepted */
}

adf_nbuf_t
ol_tx_non_std_hl(
    ol_txrx_vdev_handle data_vdev,
    u_int8_t ext_tid,
    enum ol_txrx_osif_tx_spec tx_spec,
    adf_nbuf_t msdu_list)
{
    /* FILL IN HERE */
    adf_os_assert(0);
    return NULL;
}

void
ol_txrx_mgmt_tx_cb_set(
    ol_txrx_pdev_handle pdev,
    u_int8_t type,
    ol_txrx_mgmt_tx_cb cb,
    void *ctxt)
{
    TXRX_ASSERT1(type < OL_TXRX_MGMT_NUM_TYPES);
    pdev->tx_mgmt.callbacks[type].cb = cb;
    pdev->tx_mgmt.callbacks[type].ctxt = ctxt;
}

int
ol_txrx_mgmt_send(
    ol_txrx_vdev_handle vdev,
    adf_nbuf_t tx_mgmt_frm,
    u_int8_t type)
{
    struct ol_txrx_pdev_t *pdev = vdev->pdev;
    uint32_t paddr;
    struct ieee80211_frame *wh = (struct ieee80211_frame *)wbuf_header(tx_mgmt_frm);
    u_int8_t subtype = wh->i_fc[0] & IEEE80211_FC0_SUBTYPE_MASK;
#ifndef MGMT_HTT_ENABLE
    struct ol_tx_desc_t *tx_desc;

    if (pdev->cfg.is_high_latency) {
        tx_desc = ol_tx_desc_hl(pdev, vdev, tx_mgmt_frm);
    } else {
        tx_desc = ol_tx_desc_ll(pdev, vdev, tx_mgmt_frm);
    }
    if (! tx_desc) {
        return 1; /* can't accept the tx mgmt frame */
    }
    TXRX_STATS_MSDU_INCR(vdev->pdev, tx.mgmt, tx_mgmt_frm);
    adf_nbuf_map_single(pdev->osdev, tx_mgmt_frm, ADF_OS_DMA_TO_DEVICE);

    TXRX_ASSERT1(type < OL_TXRX_MGMT_NUM_TYPES);
    tx_desc->pkt_type = type + OL_TXRX_MGMT_TYPE_BASE;
    htt_tx_desc_tid(pdev->htt_pdev, tx_desc->htt_tx_desc, HTT_TX_EXT_TID_MGMT);

    if (pdev->cfg.is_high_latency) {
/*
 * FIX THIS:
 * 1.  Look up the peer and queue the frame in the peer's mgmt queue.
 * 2.  Invoke the download scheduler.
 */
//        ol_tx_mgmt_classify_store(vdev, tx_desc, tx_mgmt_frm);
//        ol_tx_dl_sched(vdev->pdev);
    } else {
        ol_tx_send(vdev, tx_desc, tx_mgmt_frm);
    }

#else

    u_int8_t  frm_hdr[HTT_MGMT_FRM_HDR_DOWNLOAD_LEN];
    u_int8_t *frm_buf;

    frm_buf = (u_int8_t *)wbuf_header(tx_mgmt_frm);
    OS_MEMCPY(frm_hdr, frm_buf, HTT_MGMT_FRM_HDR_DOWNLOAD_LEN);

    adf_nbuf_map_single(pdev->osdev, tx_mgmt_frm, ADF_OS_DMA_TO_DEVICE);

    if (subtype == IEEE80211_FC0_SUBTYPE_ACTION) {
        struct ieee80211_action *ia;
        ia = (struct ieee80211_action *)&wh[1];

        if ((ia->ia_category == IEEE80211_ACTION_CAT_PUBLIC) ||
            (ia->ia_category == IEEE80211_ACTION_CAT_QOS) ||
            (ia->ia_category == IEEE80211_ACTION_CAT_PROT_DUAL) ||
            (ia->ia_category == IEEE80211_ACTION_CAT_WNM)) {
            paddr =  NBUF_MAPPED_PADDR_LO(tx_mgmt_frm);
        } else {
            paddr = adf_nbuf_get_frag_paddr_lo(tx_mgmt_frm, 0);
        }
    }
    else {
        if(subtype == IEEE80211_FC0_SUBTYPE_DISASSOC) {
            paddr = NBUF_MAPPED_PADDR_LO(tx_mgmt_frm);
        }
        else {
            paddr = adf_nbuf_get_frag_paddr_lo(tx_mgmt_frm, 0);
        }
    }
    return htt_h2t_mgmt_tx(pdev,
            paddr,
            tx_mgmt_frm,
            wbuf_get_pktlen(tx_mgmt_frm),
            vdev->vdev_id,
            frm_hdr);
#endif
    return 0;
}

void
ol_txrx_sync(ol_txrx_pdev_handle pdev, u_int8_t sync_cnt)
{
    htt_h2t_sync_msg(pdev->htt_pdev, sync_cnt);
}

adf_nbuf_t ol_tx_reinject(
    struct ol_txrx_vdev_t *vdev,
    adf_nbuf_t msdu, uint32_t peer_id)
{
	struct ol_tx_desc_t *tx_desc;
    ol_tx_prepare_ll(tx_desc, vdev, msdu);
    HTT_TX_DESC_POSTPONED_SET(*((u_int32_t *)(tx_desc->htt_tx_desc)), TRUE);

    htt_tx_desc_set_peer_id((u_int32_t *)(tx_desc->htt_tx_desc), peer_id);

    ol_tx_send(vdev, tx_desc, msdu);

    return NULL;
}

