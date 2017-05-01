/*
 * Copyright (c) 2011 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/**
 * @file htt_h2t.c
 * @brief Provide functions to send host->target HTT messages.
 * @details
 *  This file contains functions related to host->target HTT messages.
 *  There are a couple aspects of this host->target messaging:
 *  1.  This file contains the function that is called by HTC when
 *      a host->target send completes.
 *      This send-completion callback is primarily relevant to HL,
 *      to invoke the download scheduler to set up a new download,
 *      and optionally free the tx frame whose download is completed.
 *      For both HL and LL, this completion callback frees up the
 *      HTC_PACKET object used to specify the download.
 *  2.  This file contains functions for creating messages to send
 *      from the host to the target.
 */

#include <adf_nbuf.h>    /* adf_nbuf_map_single */
#include <htc_api.h>     /* HTC_PACKET */
#include <htt.h>         /* HTT host->target msg defs */
#include <ol_txrx_htt_api.h> /* ol_tx_completion_handler, htt_tx_status */
#include <ol_htt_tx_api.h>

#include <htt_internal.h>
#include <copy_engine_api.h>
#include <ol_txrx_types.h>
#include <htc.h>

#define HTT_MSG_BUF_SIZE(msg_bytes) \
   ((msg_bytes) + HTC_HEADER_LEN + HTC_HDR_ALIGNMENT_PADDING)

#ifndef container_of
#define container_of(ptr, type, member) ((type *)( \
                (char *)(ptr) - (char *)(&((type *)0)->member) ) )
#endif

static void
htt_h2t_send_complete_free_netbuf(
    void *pdev, A_STATUS status, adf_nbuf_t netbuf, u_int16_t msdu_id)
{
    adf_nbuf_free(netbuf);
}

void
htt_h2t_send_complete(void *context, HTC_PACKET *htc_pkt)
{
    void (*send_complete_part2)(
        void *pdev, A_STATUS status, adf_nbuf_t msdu, u_int16_t msdu_id);
    struct htt_pdev_t *pdev =  (struct htt_pdev_t *) context;
    struct htt_htc_pkt *htt_pkt;
    adf_nbuf_t netbuf;

    send_complete_part2 = htc_pkt->pPktContext;

    htt_pkt = container_of(htc_pkt, struct htt_htc_pkt, htc_pkt);

    /* process (free or keep) the netbuf that held the message */
    netbuf = (adf_nbuf_t) htc_pkt->pNetBufContext;
    send_complete_part2(
             htt_pkt->pdev_ctxt, htc_pkt->Status, netbuf, htt_pkt->msdu_id);
    /* free the htt_htc_pkt / HTC_PACKET object */
    htt_htc_pkt_free(pdev, htt_pkt);
}

HTC_SEND_FULL_ACTION
htt_h2t_full(void *context, HTC_PACKET *pkt)
{
/* FIX THIS */
    return HTC_SEND_FULL_KEEP;
}

A_STATUS
htt_h2t_ver_req_msg(struct htt_pdev_t *pdev)
{
    struct htt_htc_pkt *pkt;
    adf_nbuf_t msg;
    u_int32_t *msg_word;

    pkt = htt_htc_pkt_alloc(pdev);
    if (!pkt) {
        return A_ERROR; /* failure */
    }

    /* show that this is not a tx frame download (not required, but helpful) */
    pkt->msdu_id = HTT_TX_COMPL_INV_MSDU_ID;
    pkt->pdev_ctxt = NULL; /* not used during send-done callback */
#ifdef ATH_USE_NCNB
    msg = adf_nbuf_alloc_ncnb(
#else
    msg = adf_nbuf_alloc(
#endif
        pdev->osdev,
        HTT_MSG_BUF_SIZE(HTT_VER_REQ_BYTES),
        /* reserve room for the HTC header */
        HTC_HEADER_LEN + HTC_HDR_ALIGNMENT_PADDING, 4, TRUE);
    if (!msg) {
        htt_htc_pkt_free(pdev, pkt);
        return A_ERROR; /* failure */
    }

    /*
     * Set the length of the message.
     * The contribution from the HTC_HDR_ALIGNMENT_PADDING is added
     * separately during the below call to adf_nbuf_push_head.
     * The contribution from the HTC header is added separately inside HTC.
     */
    adf_nbuf_put_tail(msg, HTT_VER_REQ_BYTES);

    /* fill in the message contents */
    msg_word = (u_int32_t *) adf_nbuf_data(msg);

    /* rewind beyond alignment pad to get to the HTC header reserved area */
    adf_nbuf_push_head(msg, HTC_HDR_ALIGNMENT_PADDING);

    *msg_word = 0;
    HTT_H2T_MSG_TYPE_SET(*msg_word, HTT_H2T_MSG_TYPE_VERSION_REQ);

    SET_HTC_PACKET_INFO_TX(
        &pkt->htc_pkt,
        htt_h2t_send_complete_free_netbuf,
        adf_nbuf_data(msg),
        adf_nbuf_len(msg),
        pdev->htc_endpoint,
        1); /* tag - not relevant here */

    SET_HTC_PACKET_NET_BUF_CONTEXT(&pkt->htc_pkt, msg);

    HTCSendPkt(pdev->htc_pdev, &pkt->htc_pkt);

    return A_OK;
}

#ifdef MGMT_HTT_ENABLE
int
htt_h2t_mgmt_tx(struct ol_txrx_pdev_t *pdev,
        u_int32_t             paddr,
        adf_nbuf_t            mgmt_frm,
        u_int32_t             frag_len,
        u_int16_t             vdev_id,
        u_int8_t              *hdr)
{
    adf_nbuf_t msg;
    u_int32_t   desc_id;
    int subtype;
    HTC_FRAME_HDR       *pHtcHdr;
    struct htt_mgmt_tx_desc_t *tx_mgmt_desc;
    struct htt_pdev_t *hpdev = pdev->htt_pdev;
    struct ieee80211_frame *wh;


    /* If mgmt_frm is NULL, return with error */
    if(mgmt_frm == NULL) {
        return -1;
    }

    wh = (struct ieee80211_frame *)wbuf_header(mgmt_frm);
    subtype = wh->i_fc[0] & IEEE80211_FC0_SUBTYPE_MASK;
#define MAX_MGMT_BUF_PKTS 512 /*TODO: This needs fine tuning */
    msg = NULL;
    /* Queue Probe-res, if pending mgmt frames in Target are more than 75% of descriptors */
    if (!((subtype == IEEE80211_FC0_SUBTYPE_PROBE_RESP) &&
                (htt_tx_mgmt_pending_frames_cnt(pdev->htt_pdev) > (HTT_MAX_NUM_MGMT_DESCS*3)/4))) {
        msg = htt_tx_mgmt_desc_alloc(hpdev, &desc_id, mgmt_frm);
    }

    /* If msg is descriptor is NULL, queue it to SW MGMT queue */
    if (!msg) {
        adf_nbuf_unmap_single(pdev->osdev, mgmt_frm, ADF_OS_DMA_TO_DEVICE);
        adf_os_spin_lock_bh(&hpdev->mgmtbufLock);
        if(adf_nbuf_queue_len(&hpdev->mgmtbufQ) > MAX_MGMT_BUF_PKTS)
        {
            adf_os_spin_unlock_bh(&hpdev->mgmtbufLock);
            return -1; /* Do not Queue more than allowed to avoid Host Memory Hogging */
        }
        adf_nbuf_queue_add(&hpdev->mgmtbufQ, mgmt_frm);
        adf_os_spin_unlock_bh(&hpdev->mgmtbufLock);
        return 0;
    }

    /* fill in the message contents */
    tx_mgmt_desc = (struct htt_mgmt_tx_desc_t *) adf_nbuf_data(msg);

    /* rewind beyond alignment pad to get to the HTC header reserved area */
    adf_nbuf_push_head(msg, HTC_HDR_ALIGNMENT_PADDING + HTC_HEADER_LEN);


    pHtcHdr = (HTC_FRAME_HDR *) adf_nbuf_get_frag_vaddr(msg, 0);
    HTC_WRITE32(pHtcHdr, SM(adf_nbuf_len(msg), HTC_FRAME_HDR_PAYLOADLEN) |
            SM(hpdev->htc_endpoint, HTC_FRAME_HDR_ENDPOINTID));

    HTC_WRITE32(((u_int32_t *)pHtcHdr) + 1, SM(1,
                HTC_FRAME_HDR_CONTROLBYTES1));

    tx_mgmt_desc->msg_type = HTT_H2T_MSG_TYPE_MGMT_TX;
    tx_mgmt_desc->frag_paddr  = paddr;
    tx_mgmt_desc->desc_id     = desc_id;
    tx_mgmt_desc->len         = frag_len;
    tx_mgmt_desc->vdev_id     = vdev_id;

    OS_MEMCPY(tx_mgmt_desc->hdr, hdr, HTT_MGMT_FRM_HDR_DOWNLOAD_LEN);

#ifdef BIG_ENDIAN_HOST
    {
        /* Big endian host swap the HTC and HTT header */
        int i;
        u_int32_t *destp, *srcp, length;
        length = HTC_HEADER_LEN + sizeof( struct htt_mgmt_tx_desc_t)-
            HTT_MGMT_FRM_HDR_DOWNLOAD_LEN +
            HTC_HDR_ALIGNMENT_PADDING;
        length = length/4;
        destp = srcp = (u_int32_t *)pHtcHdr;
        for(i=0; i < length ; i++) {
            *destp = cpu_to_le32(*srcp);
            destp++; srcp++;
        }
    }
#endif
    adf_nbuf_map_single( pdev->osdev, (adf_nbuf_t) msg , ADF_OS_DMA_TO_DEVICE);
    if(CE_send_single(pdev->ce_tx_hdl, msg, hpdev->htc_endpoint,
                adf_nbuf_len(msg))){
        htt_tx_mgmt_desc_free(hpdev, desc_id, IEEE80211_TX_ERROR);
    }
    return 0;
}
#endif

A_STATUS
htt_h2t_rx_ring_cfg_msg_ll(struct htt_pdev_t *pdev)
{
    struct htt_htc_pkt *pkt;
    adf_nbuf_t msg;
    u_int32_t *msg_word;
    int enable_ctrl_data, enable_mgmt_data,
        enable_null_data, enable_phy_data, enable_hdr,
        enable_ppdu_start, enable_ppdu_end;

    pkt = htt_htc_pkt_alloc(pdev);
    if (!pkt) {
        return A_ERROR; /* failure */
    }

    /* show that this is not a tx frame download (not required, but helpful) */
    pkt->msdu_id = HTT_TX_COMPL_INV_MSDU_ID;
    pkt->pdev_ctxt = NULL; /* not used during send-done callback */
#ifdef ATH_USE_NCNB
    msg = adf_nbuf_alloc_ncnb(
#else
    msg = adf_nbuf_alloc(
#endif
        pdev->osdev,
        HTT_MSG_BUF_SIZE(HTT_RX_RING_CFG_BYTES(1)),
        /* reserve room for the HTC header */
        HTC_HEADER_LEN + HTC_HDR_ALIGNMENT_PADDING, 4, TRUE);
    if (!msg) {
        htt_htc_pkt_free(pdev, pkt);
        return A_ERROR; /* failure */
    }
    /*
     * Set the length of the message.
     * The contribution from the HTC_HDR_ALIGNMENT_PADDING is added
     * separately during the below call to adf_nbuf_push_head.
     * The contribution from the HTC header is added separately inside HTC.
     */
    adf_nbuf_put_tail(msg, HTT_RX_RING_CFG_BYTES(1));

    /* fill in the message contents */
    msg_word = (u_int32_t *) adf_nbuf_data(msg);

    /* rewind beyond alignment pad to get to the HTC header reserved area */
    adf_nbuf_push_head(msg, HTC_HDR_ALIGNMENT_PADDING);

    *msg_word = 0;
    HTT_H2T_MSG_TYPE_SET(*msg_word, HTT_H2T_MSG_TYPE_RX_RING_CFG);
    HTT_RX_RING_CFG_NUM_RINGS_SET(*msg_word, 1);

    msg_word++;
    *msg_word = 0;
    HTT_RX_RING_CFG_IDX_SHADOW_REG_PADDR_SET(
        *msg_word, pdev->rx_ring.alloc_idx.paddr);

    msg_word++;
    *msg_word = 0;
    HTT_RX_RING_CFG_BASE_PADDR_SET(*msg_word, pdev->rx_ring.base_paddr);

    msg_word++;
    *msg_word = 0;
    HTT_RX_RING_CFG_LEN_SET(*msg_word, pdev->rx_ring.size);
    HTT_RX_RING_CFG_BUF_SZ_SET(*msg_word, HTT_RX_BUF_SIZE);

/* FIX THIS: if the FW creates a complete translated rx descriptor, then the MAC DMA of the HW rx descriptor should be disabled. */
    msg_word++;
    *msg_word = 0;
#ifndef REMOVE_PKT_LOG
    enable_ctrl_data = 1;
    enable_mgmt_data = 1;
    enable_null_data = 1;
    enable_phy_data  = 1;
    enable_hdr       = 1;
    enable_ppdu_start= 1;
    enable_ppdu_end  = 1;
#else
    enable_ctrl_data = 0;
    enable_mgmt_data = 0;
    enable_null_data = 0;
    enable_phy_data  = 0;
    enable_hdr       = 0;
    enable_ppdu_start= 0;
    enable_ppdu_end  = 0;
#endif
    HTT_RX_RING_CFG_ENABLED_802_11_HDR_SET(*msg_word, enable_hdr);
    HTT_RX_RING_CFG_ENABLED_MSDU_PAYLD_SET(*msg_word, 1);
    HTT_RX_RING_CFG_ENABLED_PPDU_START_SET(*msg_word, enable_ppdu_start);
    HTT_RX_RING_CFG_ENABLED_PPDU_END_SET(*msg_word, enable_ppdu_end);
    HTT_RX_RING_CFG_ENABLED_MPDU_START_SET(*msg_word, 1);
    HTT_RX_RING_CFG_ENABLED_MPDU_END_SET(*msg_word,   1);
    HTT_RX_RING_CFG_ENABLED_MSDU_START_SET(*msg_word, 1);
    HTT_RX_RING_CFG_ENABLED_MSDU_END_SET(*msg_word,   1);
    HTT_RX_RING_CFG_ENABLED_RX_ATTN_SET(*msg_word,    1);
    HTT_RX_RING_CFG_ENABLED_FRAG_INFO_SET(*msg_word,  1); /* always present? */
    HTT_RX_RING_CFG_ENABLED_UCAST_SET(*msg_word, 1);
    HTT_RX_RING_CFG_ENABLED_MCAST_SET(*msg_word, 1);
    /* Must change to dynamic enable at run time 
     * rather than at compile time
     */
    HTT_RX_RING_CFG_ENABLED_CTRL_SET(*msg_word, enable_ctrl_data);
    HTT_RX_RING_CFG_ENABLED_MGMT_SET(*msg_word, enable_mgmt_data);
    HTT_RX_RING_CFG_ENABLED_NULL_SET(*msg_word, enable_null_data);
    HTT_RX_RING_CFG_ENABLED_PHY_SET(*msg_word, enable_phy_data);
    HTT_RX_RING_CFG_IDX_INIT_VAL_SET(*msg_word, 
            *pdev->rx_ring.alloc_idx.vaddr); 

    msg_word++;
    *msg_word = 0;
    HTT_RX_RING_CFG_OFFSET_802_11_HDR_SET(*msg_word, 
            RX_STD_DESC_HDR_STATUS_OFFSET_DWORD);
    HTT_RX_RING_CFG_OFFSET_MSDU_PAYLD_SET(*msg_word, 
            HTT_RX_STD_DESC_RESERVATION_DWORD);

    msg_word++;
    *msg_word = 0;
    HTT_RX_RING_CFG_OFFSET_PPDU_START_SET(*msg_word,
            RX_STD_DESC_PPDU_START_OFFSET_DWORD);
    HTT_RX_RING_CFG_OFFSET_PPDU_END_SET(*msg_word,
            RX_STD_DESC_PPDU_END_OFFSET_DWORD); 

    msg_word++;
    *msg_word = 0;
    HTT_RX_RING_CFG_OFFSET_MPDU_START_SET(*msg_word, 
            RX_STD_DESC_MPDU_START_OFFSET_DWORD);
    HTT_RX_RING_CFG_OFFSET_MPDU_END_SET(*msg_word, 
            RX_STD_DESC_MPDU_END_OFFSET_DWORD); 

    msg_word++;
    *msg_word = 0;
    HTT_RX_RING_CFG_OFFSET_MSDU_START_SET(*msg_word, 
            RX_STD_DESC_MSDU_START_OFFSET_DWORD);
    HTT_RX_RING_CFG_OFFSET_MSDU_END_SET(*msg_word, 
            RX_STD_DESC_MSDU_END_OFFSET_DWORD);

    msg_word++;
    *msg_word = 0;
    HTT_RX_RING_CFG_OFFSET_RX_ATTN_SET(*msg_word, 
            RX_STD_DESC_ATTN_OFFSET_DWORD);
    HTT_RX_RING_CFG_OFFSET_FRAG_INFO_SET(*msg_word, 
            RX_STD_DESC_FRAG_INFO_OFFSET_DWORD);

    SET_HTC_PACKET_INFO_TX(
            &pkt->htc_pkt,
            htt_h2t_send_complete_free_netbuf,
            adf_nbuf_data(msg),
            adf_nbuf_len(msg),
            pdev->htc_endpoint,
            1); /* tag - not relevant here */

    SET_HTC_PACKET_NET_BUF_CONTEXT(&pkt->htc_pkt, msg);

    HTCSendPkt(pdev->htc_pdev, &pkt->htc_pkt);

    return A_OK;
}

A_STATUS
htt_h2t_rx_ring_cfg_msg_hl(struct htt_pdev_t *pdev)
{
    struct htt_htc_pkt *pkt;
    adf_nbuf_t msg;
    u_int32_t *msg_word;

    pkt = htt_htc_pkt_alloc(pdev);
    if (!pkt) {
        return A_ERROR; /* failure */
    }

    /* show that this is not a tx frame download (not required, but helpful) */
    pkt->msdu_id = HTT_TX_COMPL_INV_MSDU_ID;
    pkt->pdev_ctxt = NULL; /* not used during send-done callback */
#ifdef ATH_USE_NCNB
    msg = adf_nbuf_alloc_ncnb(
#else
    msg = adf_nbuf_alloc(
#endif
        pdev->osdev,
        HTT_MSG_BUF_SIZE(HTT_RX_RING_CFG_BYTES(1)),
        /* reserve room for the HTC header */
        HTC_HEADER_LEN + HTC_HDR_ALIGNMENT_PADDING, 4, TRUE);
    if (!msg) {
        htt_htc_pkt_free(pdev, pkt);
        return A_ERROR; /* failure */
    }
    /*
     * Set the length of the message.
     * The contribution from the HTC_HDR_ALIGNMENT_PADDING is added
     * separately during the below call to adf_nbuf_push_head.
     * The contribution from the HTC header is added separately inside HTC.
     */
    adf_nbuf_put_tail(msg, HTT_RX_RING_CFG_BYTES(1));

    /* fill in the message contents */
    msg_word = (u_int32_t *) adf_nbuf_data(msg);

    /* rewind beyond alignment pad to get to the HTC header reserved area */
    adf_nbuf_push_head(msg, HTC_HDR_ALIGNMENT_PADDING);

    *msg_word = 0;
    HTT_H2T_MSG_TYPE_SET(*msg_word, HTT_H2T_MSG_TYPE_RX_RING_CFG);
    HTT_RX_RING_CFG_NUM_RINGS_SET(*msg_word, 1);

    msg_word++;
    *msg_word = 0;
    HTT_RX_RING_CFG_IDX_SHADOW_REG_PADDR_SET(
        *msg_word, pdev->rx_ring.alloc_idx.paddr);

    msg_word++;
    *msg_word = 0;
    HTT_RX_RING_CFG_BASE_PADDR_SET(*msg_word, pdev->rx_ring.base_paddr);

    msg_word++;
    *msg_word = 0;
    HTT_RX_RING_CFG_LEN_SET(*msg_word, pdev->rx_ring.size);
    HTT_RX_RING_CFG_BUF_SZ_SET(*msg_word, HTT_RX_BUF_SIZE);

/* FIX THIS: if the FW creates a complete translated rx descriptor, then the MAC DMA of the HW rx descriptor should be disabled. */
    msg_word++;
    *msg_word = 0;

    HTT_RX_RING_CFG_ENABLED_802_11_HDR_SET(*msg_word, 0);
    HTT_RX_RING_CFG_ENABLED_MSDU_PAYLD_SET(*msg_word, 1);
    HTT_RX_RING_CFG_ENABLED_PPDU_START_SET(*msg_word, 0);
    HTT_RX_RING_CFG_ENABLED_PPDU_END_SET(*msg_word, 0);
    HTT_RX_RING_CFG_ENABLED_MPDU_START_SET(*msg_word, 0);
    HTT_RX_RING_CFG_ENABLED_MPDU_END_SET(*msg_word,   0);
    HTT_RX_RING_CFG_ENABLED_MSDU_START_SET(*msg_word, 0);
    HTT_RX_RING_CFG_ENABLED_MSDU_END_SET(*msg_word,   0);
    HTT_RX_RING_CFG_ENABLED_RX_ATTN_SET(*msg_word,    0);
    HTT_RX_RING_CFG_ENABLED_FRAG_INFO_SET(*msg_word,  0); /* always present? */
    HTT_RX_RING_CFG_ENABLED_UCAST_SET(*msg_word, 1);
    HTT_RX_RING_CFG_ENABLED_MCAST_SET(*msg_word, 1);
    /* Must change to dynamic enable at run time 
     * rather than at compile time
     */
    HTT_RX_RING_CFG_ENABLED_CTRL_SET(*msg_word, 0);
    HTT_RX_RING_CFG_ENABLED_MGMT_SET(*msg_word, 0);
    HTT_RX_RING_CFG_ENABLED_NULL_SET(*msg_word, 0);
    HTT_RX_RING_CFG_ENABLED_PHY_SET(*msg_word, 0);

    msg_word++;
    *msg_word = 0;
    HTT_RX_RING_CFG_OFFSET_802_11_HDR_SET(*msg_word, 
            0);
    HTT_RX_RING_CFG_OFFSET_MSDU_PAYLD_SET(*msg_word, 
            0);

    msg_word++;
    *msg_word = 0;
    HTT_RX_RING_CFG_OFFSET_PPDU_START_SET(*msg_word,
            0);
    HTT_RX_RING_CFG_OFFSET_PPDU_END_SET(*msg_word,
            0); 

    msg_word++;
    *msg_word = 0;
    HTT_RX_RING_CFG_OFFSET_MPDU_START_SET(*msg_word, 
            0);
    HTT_RX_RING_CFG_OFFSET_MPDU_END_SET(*msg_word, 
            0); 

    msg_word++;
    *msg_word = 0;
    HTT_RX_RING_CFG_OFFSET_MSDU_START_SET(*msg_word, 
            0);
    HTT_RX_RING_CFG_OFFSET_MSDU_END_SET(*msg_word, 
            0);

    msg_word++;
    *msg_word = 0;
    HTT_RX_RING_CFG_OFFSET_RX_ATTN_SET(*msg_word, 
            0);
    HTT_RX_RING_CFG_OFFSET_FRAG_INFO_SET(*msg_word, 
            0);

    SET_HTC_PACKET_INFO_TX(
        &pkt->htc_pkt,
        htt_h2t_send_complete_free_netbuf,
        adf_nbuf_data(msg),
        adf_nbuf_len(msg),
        pdev->htc_endpoint,
        1); /* tag - not relevant here */

    SET_HTC_PACKET_NET_BUF_CONTEXT(&pkt->htc_pkt, msg);

    HTCSendPkt(pdev->htc_pdev, &pkt->htc_pkt);

    return A_OK;
}

int
htt_h2t_dbg_stats_get(
    struct htt_pdev_t *pdev, 
    u_int32_t stats_type_upload_mask,
    u_int32_t stats_type_reset_mask,
    u_int8_t cfg_stat_type,
    u_int32_t cfg_val,
    u_int64_t cookie)
{
    struct htt_htc_pkt *pkt;
    adf_nbuf_t msg;
    u_int32_t *msg_word;

    pkt = htt_htc_pkt_alloc(pdev);
    if (!pkt) {
        return -1; /* failure */
    }

    if (stats_type_upload_mask >= 1 << HTT_DBG_NUM_STATS ||
        stats_type_reset_mask >= 1 << HTT_DBG_NUM_STATS)
    {
        /* FIX THIS - add more details? */
        adf_os_print("%#x %#x stats not supported\n",
            stats_type_upload_mask, stats_type_reset_mask);
        htt_htc_pkt_free(pdev, pkt);
        return -1; /* failure */
    }

    /* show that this is not a tx frame download (not required, but helpful) */
    pkt->msdu_id = HTT_TX_COMPL_INV_MSDU_ID;
    pkt->pdev_ctxt = NULL; /* not used during send-done callback */
#ifdef ATH_USE_NCNB
    msg = adf_nbuf_alloc_ncnb(
#else
    msg = adf_nbuf_alloc(
#endif
        pdev->osdev,
        HTT_MSG_BUF_SIZE(HTT_H2T_STATS_REQ_MSG_SZ),
        /* reserve room for HTC header */
        HTC_HEADER_LEN + HTC_HDR_ALIGNMENT_PADDING, 4, FALSE);
    if (!msg) {
        htt_htc_pkt_free(pdev, pkt);
        return -1; /* failure */
    }
    /* set the length of the message */
    adf_nbuf_put_tail(msg, HTT_H2T_STATS_REQ_MSG_SZ);

    /* fill in the message contents */
    msg_word = (u_int32_t *) adf_nbuf_data(msg);

    /* rewind beyond alignment pad to get to the HTC header reserved area */
    adf_nbuf_push_head(msg, HTC_HDR_ALIGNMENT_PADDING);

    *msg_word = 0;
    HTT_H2T_MSG_TYPE_SET(*msg_word, HTT_H2T_MSG_TYPE_STATS_REQ);
    HTT_H2T_STATS_REQ_UPLOAD_TYPES_SET(*msg_word, stats_type_upload_mask);

    msg_word++;
    *msg_word = 0;
    HTT_H2T_STATS_REQ_RESET_TYPES_SET(*msg_word, stats_type_reset_mask);

    msg_word++;
    *msg_word = 0;
    HTT_H2T_STATS_REQ_CFG_VAL_SET(*msg_word, cfg_val);
    HTT_H2T_STATS_REQ_CFG_STAT_TYPE_SET(*msg_word, cfg_stat_type);

    /* cookie LSBs */
    msg_word++;
    *msg_word = cookie & 0xffffffff;

    /* cookie MSBs */
    msg_word++;
    *msg_word = cookie >> 32;

    SET_HTC_PACKET_INFO_TX(
        &pkt->htc_pkt,
        htt_h2t_send_complete_free_netbuf,
        adf_nbuf_data(msg),
        adf_nbuf_len(msg),
        pdev->htc_endpoint,
        1); /* tag - not relevant here */

    SET_HTC_PACKET_NET_BUF_CONTEXT(&pkt->htc_pkt, msg);
    htt_pkt_buf_list_add(pdev,(void *)msg,cookie, (void *)pkt);
    HTCSendPkt(pdev->htc_pdev, &pkt->htc_pkt);
    
    return 0;
}

A_STATUS
htt_h2t_sync_msg(struct htt_pdev_t *pdev, u_int8_t sync_cnt)
{
    struct htt_htc_pkt *pkt;
    adf_nbuf_t msg;
    u_int32_t *msg_word;

    pkt = htt_htc_pkt_alloc(pdev);
    if (!pkt) {
        return A_NO_MEMORY;
    }

    /* show that this is not a tx frame download (not required, but helpful) */
    pkt->msdu_id = HTT_TX_COMPL_INV_MSDU_ID;
    pkt->pdev_ctxt = NULL; /* not used during send-done callback */
#ifdef ATH_USE_NCNB
    msg = adf_nbuf_alloc_ncnb(
#else
    msg = adf_nbuf_alloc(
#endif
        pdev->osdev,
        HTT_MSG_BUF_SIZE(HTT_H2T_SYNC_MSG_SZ),
        /* reserve room for HTC header */
        HTC_HEADER_LEN + HTC_HDR_ALIGNMENT_PADDING, 4, FALSE);
    if (!msg) {
        htt_htc_pkt_free(pdev, pkt);
        return A_NO_MEMORY;
    }
    /* set the length of the message */
    adf_nbuf_put_tail(msg, HTT_H2T_SYNC_MSG_SZ);

    /* fill in the message contents */
    msg_word = (u_int32_t *) adf_nbuf_data(msg);

    /* rewind beyond alignment pad to get to the HTC header reserved area */
    adf_nbuf_push_head(msg, HTC_HDR_ALIGNMENT_PADDING);

    *msg_word = 0;
    HTT_H2T_MSG_TYPE_SET(*msg_word, HTT_H2T_MSG_TYPE_SYNC);
    HTT_H2T_SYNC_COUNT_SET(*msg_word, sync_cnt);

    SET_HTC_PACKET_INFO_TX(
        &pkt->htc_pkt,
        htt_h2t_send_complete_free_netbuf,
        adf_nbuf_data(msg),
        adf_nbuf_len(msg),
        pdev->htc_endpoint,
        1); /* tag - not relevant here */

    SET_HTC_PACKET_NET_BUF_CONTEXT(&pkt->htc_pkt, msg);

    HTCSendPkt(pdev->htc_pdev, &pkt->htc_pkt);

    return A_OK;
}

#if defined(TEMP_AGGR_CFG)
int
htt_h2t_aggr_cfg_msg(struct htt_pdev_t *pdev,
                     int max_subfrms_ampdu, 
                     int max_subfrms_amsdu)
{
    struct htt_htc_pkt *pkt;
    adf_nbuf_t msg;
    u_int32_t *msg_word;
    u_int32_t cookie ;

    pkt = htt_htc_pkt_alloc(pdev);
    if (!pkt) {
        return -1; /* failure */
    }

    /* show that this is not a tx frame download (not required, but helpful) */
    pkt->msdu_id = HTT_TX_COMPL_INV_MSDU_ID;
    pkt->pdev_ctxt = NULL; /* not used during send-done callback */
#ifdef ATH_USE_NCNB
    msg = adf_nbuf_alloc_ncnb(
#else
    msg = adf_nbuf_alloc(
#endif
        pdev->osdev,
        HTT_MSG_BUF_SIZE(HTT_AGGR_CFG_MSG_SZ),
        /* reserve room for HTC header */
        HTC_HEADER_LEN + HTC_HDR_ALIGNMENT_PADDING, 4, FALSE);
    if (!msg) {
        htt_htc_pkt_free(pdev, pkt);
        return -1; /* failure */
    }
    /* set the length of the message */
    adf_nbuf_put_tail(msg, HTT_AGGR_CFG_MSG_SZ);

    /* fill in the message contents */
    msg_word = (u_int32_t *) adf_nbuf_data(msg);

    /* rewind beyond alignment pad to get to the HTC header reserved area */
    adf_nbuf_push_head(msg, HTC_HDR_ALIGNMENT_PADDING);

    *msg_word = 0;
    HTT_H2T_MSG_TYPE_SET(*msg_word, HTT_H2T_MSG_TYPE_AGGR_CFG);

    if (max_subfrms_ampdu && (max_subfrms_ampdu <= 64)) {
        HTT_AGGR_CFG_MAX_NUM_AMPDU_SUBFRM_SET(*msg_word, max_subfrms_ampdu); 
    }

    if (max_subfrms_amsdu && (max_subfrms_amsdu < 32)) {
        HTT_AGGR_CFG_MAX_NUM_AMSDU_SUBFRM_SET(*msg_word, max_subfrms_amsdu); 
    }

    cookie = (u_int32_t)(msg);
    msg_word++;
    *msg_word = cookie ; 

    SET_HTC_PACKET_INFO_TX(
        &pkt->htc_pkt,
        htt_h2t_send_complete_free_netbuf,
        adf_nbuf_data(msg),
        adf_nbuf_len(msg),
        pdev->htc_endpoint,
        1); /* tag - not relevant here */

    SET_HTC_PACKET_NET_BUF_CONTEXT(&pkt->htc_pkt, msg);

    htt_pkt_buf_list_add(pdev,(void *)msg,(u_int64_t)cookie, (void *)pkt);

    HTCSendPkt(pdev->htc_pdev, &pkt->htc_pkt);
    return 0;
}
#endif
