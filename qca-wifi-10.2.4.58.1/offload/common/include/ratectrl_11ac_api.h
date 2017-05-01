/*
 * Copyright (c) 2011-2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

// This file contains the API exported by the wlan rate ctrl module.

#ifndef _RATECTRL_API_H_
#define _RATECTRL_API_H_

#ifdef __cplusplus
extern "C" {
#endif

#if defined(ATH_TARGET)
#include "wlan_common.h"
#include "wlan_dev.h"
#include "wlan_peer.h"
#endif

#include "ratectrl_11ac.h"
#include "wlan_defs.h"
#include "ratectrl_11ac_internal.h"


#ifndef DISABLE_RATE_INDIRECTION_TABLE
typedef struct {
    A_BOOL      (* GetTxRetrySchedule)(void *pdev,
                  const WHAL_RATE_TABLE ** rt,
                  void *wlan_peer,
                  void *rc_args, void *pkt_info_rcf);
    void        (* SetCurmode)(RATE_CONTEXT * g_pRATE, WLAN_PHY_MODE mode);
    A_UINT8     (* GetRtsCtsRate)(RATE_CONTEXT *g_pRATE,
            const WHAL_RATE_TABLE *pRateTable);
    void        (* SetHTConnCap)(struct rate_node *pSib, A_UINT32 htCap);
    void        (* SetVHTConnCap)(struct rate_node *pSib, A_UINT32 vhtCap);
    void        (* SetRtsCtsRate)(RATE_CONTEXT *g_pRATE, A_UINT8 rate_code);
    void        (* SetRateMask)(RATE_CONTEXT *g_pRATE, A_UINT32 type, A_UINT32 lower32, A_UINT32 higher32);
    void        (* SetPwrChainMsk)(void *pdev, A_UINT32 op, A_UINT32 pream_type,
                                   A_UINT32 rate_len, A_UINT32 *ratepwr_chaintbl);
} RATE_API_INDIRECTION_TABLE;


#else /* DISABLE_RATE_INDIRECTION_TABLE */


A_BOOL      _RATE_GetTxRetrySchedule(void *pdev,
                  const WHAL_RATE_TABLE ** rt,
                  void *wlan_peer,
                  void *rc_args,
                  void *pkt_info_rcf);
void        _RATE_SetCurmode(RATE_CONTEXT * g_pRATE, WLAN_PHY_MODE mode);
void        _RATE_SetRtsCtsRate(RATE_CONTEXT *g_pRATE, A_UINT8 rate_code);
A_UINT8     _RATE_GetRtsCtsRate(RATE_CONTEXT * g_pRATE,
        const WHAL_RATE_TABLE *pRateTable);
void        _RATE_SetHTConnCap(struct rate_node *pSib, A_UINT32 htCap);
void        _RATE_SetVHTConnCap(struct rate_node *pSib, A_UINT32 vhtCap);
void        _RATE_SetRateMask(RATE_CONTEXT *g_pRATE, A_UINT32 type, A_UINT32 lower32,
                               A_UINT32 higher32);
void        _RATE_SetPwrChainMsk(void *dev, A_UINT32 op, A_UINT32 pream_type,
                                 A_UINT32 rate_len, A_UINT32 *ratepwr_chaintbl);

#endif /* DISABLE_RATE_INDIRECTION_TABLE */

#ifndef DISABLE_RATE_INDIRECTION_TABLE
extern RATE_API_INDIRECTION_TABLE rateApiIndirectionTable;
#define RATE_API_FN(fn) rateApiIndirectionTable.fn
#else /* DISABLE_RATE_INDIRECTION_TABLE */
#define RATE_API_FN(fn) _RATE_##fn
#endif /* DISABLE_RATE_INDIRECTION_TABLE */


#define RATE_GetTxRetrySchedule(pdev, rt, wlan_peer, rc_args, pkt_info_rcf) \
    RATE_API_FN(GetTxRetrySchedule((pdev), (rt), (wlan_peer), (rc_args),    \
                                    pkt_info_rcf))

#define RATE_SetCurmode(g_pRATE, mode) \
    RATE_API_FN(SetCurmode((g_pRATE), (mode)))

#define RATE_SetRtsCtsRate(g_pRATE, rate_code) \
    RATE_API_FN(SetRtsCtsRate((g_pRATE), (rate_code)))

#define RATE_GetRtsCtsRate(g_pRATE, pRateTable) \
    RATE_API_FN(GetRtsCtsRate((g_pRATE), (pRateTable)))

#define RATE_SetHTConnCap(pSib, htCap) \
    RATE_API_FN(SetHTConnCap((pSib), (htCap)))

#define RATE_SetVHTConnCap(pSib, vhtCap) \
    RATE_API_FN(SetVHTConnCap((pSib), (vhtCap)))

#define RATE_SetRateMask(g_pRATE, type, lower32, higher32) \
    RATE_API_FN(SetRateMask((g_pRATE), (type), (lower32), (higher32)))

#define RATE_SetPwrChainMsk(pdev, op, pream_type, rate_len, ratepwr_chaintbl) \
    RATE_API_FN(SetPwrChainMsk((pdev), (op), (pream_type), (rate_len), (ratepwr_chaintbl)))

#if defined(ATH_TARGET)
void wlan_rc_set_max_nss(wlan_vdev_t *dev, A_UINT8 nss);
void wlan_rc_set_vht_sgi_mask(wlan_vdev_t *dev, A_UINT16 vht_sgi_mask);
void wlan_rc_set_vht80_rate_mask(wlan_vdev_t *dev, A_UINT32 vht80_rate_mask);

#endif

#endif /* _RATECTRL_API_H_ */
