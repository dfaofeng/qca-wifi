/*
 * Copyright (c) 2011 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/**
 * @file ol_txrx_api.h
 * @brief Definitions used in multiple external interfaces to the txrx SW.
 */
#ifndef _OL_TXRX_API__H_
#define _OL_TXRX_API__H_

/**
 * @typedef ol_txrx_pdev_handle
 * @brief opaque handle for txrx physical device object
 */
struct ol_txrx_pdev_t;
typedef struct ol_txrx_pdev_t* ol_txrx_pdev_handle;

/**
 * @typedef ol_txrx_vdev_handle
 * @brief opaque handle for txrx virtual device object
 */
struct ol_txrx_vdev_t;
typedef struct ol_txrx_vdev_t* ol_txrx_vdev_handle;

/**
 * @typedef ol_txrx_peer_handle
 * @brief opaque handle for txrx peer object
 */
struct ol_txrx_peer_t;
typedef struct ol_txrx_peer_t* ol_txrx_peer_handle;

extern u_int16_t
ol_tx_desc_alloc_and_mark_for_mcast_clone(struct ol_txrx_pdev_t *pdev, u_int16_t buf_count);

extern u_int16_t
ol_tx_desc_free_and_unmark_for_mcast_clone(struct ol_txrx_pdev_t *pdev, u_int16_t buf_count);

extern u_int16_t
ol_tx_get_mcast_buf_allocated_marked(struct ol_txrx_pdev_t *pdev);

#define VAP_TX_SPIN_LOCK(_x) spin_lock(_x)
#define VAP_TX_SPIN_UNLOCK(_x) spin_unlock(_x)

#if QCA_OL_11AC_FAST_PATH && QCA_OL_TX_CACHEDHDR
extern uint32_t
ol_tx_ll_cachedhdr(ol_txrx_vdev_handle vdev,  adf_nbuf_t msdu);

#define OL_TX_LL_WRAPPER(_vdev, _msdu, _oshandle) ol_tx_ll_cachedhdr(_vdev, _msdu)


#elif QCA_OL_11AC_FAST_PATH

extern uint32_t
ol_tx_ll_fast(ol_txrx_vdev_handle vdev,
        adf_nbuf_t *nbuf_arr,
        uint32_t num_msdus);
extern void
ol_tx_stats_inc_map_error(ol_txrx_vdev_handle vdev,
                             uint32_t num_map_error);
#define OL_TX_LL_WRAPPER(_vdev, _msdu, _oshandle) \
{\
    if(A_STATUS_FAILED == adf_nbuf_map_single( _oshandle , _msdu, ADF_OS_DMA_TO_DEVICE)){;\
        ol_tx_stats_inc_map_error(_vdev, 1); \
        while (_msdu) { \
            adf_nbuf_t _next = adf_nbuf_next(_msdu); \
            adf_nbuf_free(_msdu); \
            _msdu = _next; \
        } \
    }else{ \
        if (adf_os_unlikely(ol_tx_ll_fast(_vdev, &_msdu, 1 ))){ \
            while (_msdu) { \
                adf_nbuf_t _next = adf_nbuf_next(_msdu); \
                adf_nbuf_unmap_single( _oshandle, _msdu, ADF_OS_DMA_TO_DEVICE); \
                adf_nbuf_free(_msdu); \
                _msdu = _next; \
            }\
        } \
    } \
}

#endif /* QCA_OL_11AC_FAST_PATH && QCA_OL_TX_CACHEDHDR*/

#endif /* _OL_TXRX_API__H_ */
