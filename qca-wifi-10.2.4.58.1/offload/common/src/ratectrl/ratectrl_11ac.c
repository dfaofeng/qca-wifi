/*
 * Copyright (c) 2011-2013 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */

#if defined(ATH_TARGET)
#include <osapi.h>
#include <athdefs.h>
#include <wmi.h>
#include <wmi_api.h>
#include <wmi_svc_api.h>
#include <wlan_common.h>
#include <wlan_bss.h>
#include <wlan_dev.h>
#include <wmi_api.h>
#include "whal_api.h"
#include "if_athvar.h"
#include "wlan_buf.h"
#include "wlan_peer.h"
#include "meta.h"
#include "umac_api.h"
#include "ieee80211_proto.h"
#include "wlan_framegen.h"
#include <wal.h>
#include <ar_wal.h>  /* TODO remove this */
#else
#include "ieee80211.h"
#include "ol_ratetable.h"
#include "ol_txrx_types.h"
#include "ol_txrx_internal.h" //for debug prints. TODO: remove

#endif


#include "wlan_defs.h"
#include "pool_mgr_api.h"

#include "ratectrl_11ac.h"
#include "ratectrl_11ac_api.h"
#include "ratectrl_11ac_internal.h"
#include "ratectrl_11ac_common.h"

#define RC_WAR_INCORRECT_PEER_PHYMODE 1

/* Default rate table defining candidate MCS set to be used */

/* 2x2 11n rate table does not include MCS 4, 5, 6, 7, 8, 9, 10 */ 
#define DEFAULT_HT_RATE_TABLE_2SS_1D  ((A_RATEMASK)0xf80f)

/* 3x3 11n rate table does not include MCS 3, 4, 5, 6, 7, 8, 9, 13, 14, 15,
   16, 17, 18, 19 
*/ 
#define DEFAULT_HT_RATE_TABLE_3SS_1D  ((A_RATEMASK)0xf01c07)
/* 2x2 11ac rate table does not include MCS 1x1: 4, 5, 6, 7, 8, 9
       2x2: 0, 1, 2 
*/ 
#define DEFAULT_VHT_RATE_TABLE_2SS_1D ((A_RATEMASK)0xfe00f)

/* 3x3 11ac rate table does not include MCSs 1x1: 3,4,5,6,7,8,9
       2x2: 0, 1, 5, 6, 7,8,9
       3x3: 0, 1, 2, 3  
*/ 
#define DEFAULT_VHT_RATE_TABLE_3SS_1D ((A_RATEMASK)0x3f007007)

/* 2D rates */
#define DEFAULT_HT_RATE_TABLE_2SS_2D  ((A_RATEMASK)0xffff)
#define DEFAULT_HT_RATE_TABLE_3SS_2D  ((A_RATEMASK)0xffffff)
#define DEFAULT_VHT_RATE_TABLE_2SS_2D ((A_RATEMASK)0xfffff)
#define DEFAULT_VHT_RATE_TABLE_3SS_2D ((A_RATEMASK)0x3fffffff)

#if RC_SUPPORT_1D_RATECTRL
A_UINT32 g_use_2d_ratectrl = 1;
#endif

/* PER threshold less than this SGI is used */
A_UINT8 g_default_sgi_per_thresh = 10;

/* Excess retry persistent threshold for wifi */
A_UINT32 g_default_no_ack_wifi_thr = 3;
/* Excess retry persistent threshold for wifi and BT */
A_UINT32 g_default_no_ack_coex_thr = 3;

/* skip per update when no actual data is transmitted by only RTS */
A_UINT32 g_rc_skip_rts_failure = 1;

/* 11ac Signalling RTS/CTS bandwidth probe enable */
A_UINT32 g_rc_rts_bw_probe = 0;

/* Allow CCK rate fall back when HT MCS0 fails to perform */
A_UINT32 g_rc_cck_rate_allowed = 1;

/* vendor specific chainmask */
A_UINT32 g_rc_vendor_chainmask = 1;

#define PERE_HW_WAR_NO_MLME_SUPPORT 0

typedef enum {
    RC_BW_20 = 0,
    RC_BW_40 = 1,
    RC_BW_80 = 2
} RC_BW_TYPE_e;


typedef A_UINT16 RC_PHYMASK;

#define RC_PHYMASK_CCK (1<<WHAL_MOD_IEEE80211_T_CCK)
#define RC_PHYMASK_OFDM (1<<WHAL_MOD_IEEE80211_T_OFDM)
#define RC_PHYMASK_CCK_OFDM  (RC_PHYMASK_CCK | RC_PHYMASK_OFDM) 

#define RC_PHYMASK_HT20 (1<<WHAL_MOD_IEEE80211_T_HT_20)
#define RC_PHYMASK_HT40 (1<<WHAL_MOD_IEEE80211_T_HT_40)
#define RC_PHYMASK_HT  (RC_PHYMASK_HT20 | RC_PHYMASK_HT40) 


#define RC_PHYMASK_VHT20 (1<<WHAL_MOD_IEEE80211_T_VHT_20)
#define RC_PHYMASK_VHT40 (1<<WHAL_MOD_IEEE80211_T_VHT_40)
#define RC_PHYMASK_VHT80 (1<<WHAL_MOD_IEEE80211_T_VHT_80)
#define RC_PHYMASK_VHT160 (1<<WHAL_MOD_IEEE80211_T_VHT_160)

#define RC_PHYMASK_VHT (RC_PHYMASK_VHT20 | RC_PHYMASK_VHT40 | \
        RC_PHYMASK_VHT80 | RC_PHYMASK_VHT160)

#define RC_PHYMASK_ALL (RC_PHYMASK_CCK | RC_PHYMASK_OFDM | RC_PHYMASK_HT20 |\
    RC_PHYMASK_HT40 | RC_PHYMASK_VHT)

#define IS_PHYMODE_11N2G(mode) ((mode) == MODE_11NG_HT20 ||\
                                (mode) == MODE_11NG_HT40)

#define IS_RIX_VALID(rix) ((rix) != RT_INVALID_INDEX)

/* default rate table for different nss configurations */

#if RC_SUPPORT_1D_RATECTRL

const A_RATEMASK default_ht_rt_masks_1d[] = {
      0xff ,                    /* 1x1 11n MCS 0..7 */
      DEFAULT_HT_RATE_TABLE_2SS_1D,/* 2x2 11n  */
      DEFAULT_HT_RATE_TABLE_3SS_1D /* 3x3 11n */
};

const A_RATEMASK default_vht_rt_masks_1d[] = {
      0x3ff ,                    /* 1x1 11ac MCS 0..9 */
      DEFAULT_VHT_RATE_TABLE_2SS_1D,/* 2x2 11ac  */
      DEFAULT_VHT_RATE_TABLE_3SS_1D /* 3x3 11ac */
};

#endif

const A_RATEMASK default_ht_rt_masks_2d[] = {
      0xff ,                    /* 1x1 11n MCS 0..7 */
      DEFAULT_HT_RATE_TABLE_2SS_2D,/* 2x2 11n  */
      DEFAULT_HT_RATE_TABLE_3SS_2D /* 3x3 11n */
};

const A_RATEMASK default_vht_rt_masks_2d[] = {
      0x3ff ,                    /* 1x1 11ac MCS 0..9 */
      DEFAULT_VHT_RATE_TABLE_2SS_2D,/* 2x2 11ac  */
      DEFAULT_VHT_RATE_TABLE_3SS_2D /* 3x3 11ac */
};

/* Certain devices do not like Cyclic Delay Diversity */
static A_UINT32 g_rc_no_cdd = 0;
#define RATECTRL_DO_NOT_USE_CDD() (g_rc_no_cdd)
#if ATH_TARGET
/* 1x1 devices do not like Cyclic Delay Diversity for 64-QAM MCSs */
static A_UINT32 g_rc_1x1_mcs_no_cdd = 0x5;
#define RATECTRL_NO_CDD_1x1_STA(vdev) (wal_rc_is_dyntxchain(vdev))
#define RATECTRL_CDD_NOT_ALLOWED_FOR_MCS(m) ((m) >= g_rc_1x1_mcs_no_cdd)
#define RATECTRL_PEER_1x1(an) ((an)->peer_params.valid_tx_chainmask == 0x1)
#endif /* ATH_TARGET */
/* g_rc_bw_probe_shift_factor controls how often should we probe for
   higher bw, when dynamic bw results too much of per on higher bw
   as of now it uses rate specific 50ms << g_rc_bw_probe_shift_factor
   ms of time before it gives  a next try
*/
static A_UINT32 g_rc_bw_probe_shift_factor =1;

#if ATH_TARGET
void rc_set_vendor_chainmask(wlan_vdev_t *vdev)
{
    /* currently this function only modifies chainmask for 2 SS rates */
    wlan_pdev_t *wlan_pdev = vdev->wlan_pdev;
    wal_pdev_t  *wal_pdev = DEV_GET_WAL_PDEV(wlan_pdev);
    A_UINT8 chain_masks[MAX_SPATIAL_STREAM];
    A_UINT8 nss_bitmap = 0x2; /* 2 SS rates */

    if (g_rc_vendor_chainmask && !wal_rc_is_bt_active()) {
        A_UINT16 tx_chain_mask, rx_chain_mask;
        wal_rc_get_hw_chainmasks(wal_pdev, &tx_chain_mask, &rx_chain_mask);
        if (tx_chain_mask < 7)
           return;

        chain_masks[nss_bitmap/2] = 0x3 ; /* only use 2 chains */
        /* update 2SS chainmask */
        wal_rc_set_pdev_tx_chainmasks(wal_pdev, nss_bitmap, chain_masks);
    }
    /* register WAL_PDEV_EVENT_HW_CHAINMASK_UPDATE callback to get notification
       if chainmask changes in future
       TODO:
    */
}
#endif
/*
 * Get number of supported spatial stream based on chainmask
*/
inline A_UINT8 rc_get_nss_from_chainmask(A_UINT8 chain_mask)
{
    A_UINT8 nss = 0;

    switch (chain_mask) {

       case 7:
       {
          nss = 3;
          break;
       }
       case 3:
       case 5:
       case 6:
       {
          nss = 2;
          break;
       }
       case 1:
       case 2:
       case 4:
       {
           nss = 1;
           break;
       }
        default:
            A_ASSERT(0);
            break;
    }

    return nss;
}

inline A_UINT8 rc_get_nss_idx_from_rix(const WHAL_RATE_TABLE *pRateTable, A_UINT8 rix)
{
#if NUM_SPATIAL_STREAM > 2
    if (RT_IS_3SS(pRateTable, rix)) {
        return 2;
    }
#endif
#if NUM_SPATIAL_STREAM > 1
    if (RT_IS_2SS(pRateTable, rix)) {
        return 1;
    }
#endif
    if (RT_IS_1SS(pRateTable, rix) || RT_IS_OFDM_CCK_INDEX(rix)) {
        return 0;
    }            

    A_ASSERT(0);
}

static inline A_UINT8 *rc_get_valid_rates_2d(struct TxRateCtrl_s *pRc,
    A_UINT8 m_idx, A_UINT8 nss)
{
    if (m_idx >= WHAL_RC_MASK_IDX_VHT_20) {
        return pRc->u.tD.validRateIndexVHT[m_idx - WHAL_RC_MASK_IDX_VHT_20][nss];
    } 

    if (m_idx >= WHAL_RC_MASK_IDX_HT_20) {
        return pRc->u.tD.validRateIndexHT[m_idx - WHAL_RC_MASK_IDX_HT_20][nss];
    }

    return pRc->u.tD.validRateIndexLegacy;
}

static inline A_UINT8 rc_get_num_mcs_from_idx(A_UINT8 m_idx)
{
    if (m_idx >= WHAL_RC_MASK_IDX_VHT_20) {
        return 10;
    } 

    if (m_idx >= WHAL_RC_MASK_IDX_HT_20) {
        return 8;
    }

    /* legacy rates */
    return 12;
}

static inline A_UINT8 rc_get_mcs_from_rix(const WHAL_RATE_TABLE *pRateTable, A_UINT8 rix)
{
    A_UINT32 bit_pos, m_idx;
    A_UINT8 nss_idx = rc_get_nss_idx_from_rix(pRateTable, rix);
    A_UINT8 num_mcs;

    RT_GET_RC_MASK_4_RIX((void *)pRateTable, rix, &m_idx, &bit_pos);

    num_mcs = rc_get_num_mcs_from_idx(m_idx);

    return bit_pos - nss_idx * num_mcs;
}

void
_rcUpdatePer_2D(const WHAL_RATE_TABLE *pRateTable, struct TxRateCtrl_s *pRc,
    A_UINT8 txRate, A_UINT8 m_idx, A_UINT8 newPer)
{
    A_UINT8 rate;

    if (RT_IS_HT_INDEX(txRate)) { /* HT/VHT rates */
        A_INT8 nss;
        A_INT8 mcs;
        A_UINT8 upper, lower;
        A_UINT8 txRateMcs = rc_get_mcs_from_rix(pRateTable, txRate);
        A_UINT8 txRateNssIdx = rc_get_nss_idx_from_rix(pRateTable, txRate);
        A_UINT8 num_mcs;

        RT_GET_RIX_LIMITS_4_MASK(&upper, &lower, m_idx);

        num_mcs = rc_get_num_mcs_from_idx(m_idx);

        if (newPer > pRc->state[txRate].per) {
            /* per increased, check higher nss and mcs */
            rate = txRate;
            for (nss = txRateNssIdx; nss < NUM_SPATIAL_STREAM; ++nss) {
                for (mcs = txRateMcs; mcs < num_mcs; ++mcs) {
                    if (pRc->state[rate].per < newPer) {
                            pRc->state[rate].per = newPer;
                            ++rate;
                    } else {
                        /* the rest of this NSS is correct */
                        rate += num_mcs - mcs;
                        break;
                    }
                }
                rate += txRateMcs;
            }
        } else if (newPer < pRc->state[txRate].per) {
            rate = txRate;
            for (nss = txRateNssIdx; nss >= 0; --nss) {
                for (mcs = txRateMcs; mcs >= 0; --mcs) {
                    if (pRc->state[rate].per > newPer) {
                        pRc->state[rate].per = newPer;
                        --rate;
                    } else {
                        /* the rest of this NSS is correct */
                        rate -= mcs + 1;
                        break;
                    }
                }
                rate -= num_mcs - txRateMcs - 1;
            }
        }
    }
    else { /* Legacy CCK/OFDM rates */
        pRc->state[txRate].per = newPer;

        for (rate = 0; RT_IS_OFDM_CCK_INDEX(rate); rate++) {
            if (rate == txRate) {
                continue;
            }

            if (RT_GET_RAW_KBPS(pRateTable, txRate) < 
                RT_GET_RAW_KBPS(pRateTable, rate))
            {
                if (pRc->state[rate].per < pRc->state[txRate].per) {
                    pRc->state[rate].per = pRc->state[txRate].per;
                }
            } else {
                if (pRc->state[rate].per > pRc->state[txRate].per) {
                    pRc->state[rate].per = pRc->state[txRate].per;
                }
            }
        }
    }
}

static A_UINT32 _RATE_GetXRetryThr(A_UINT32 tries)
{
    A_UINT32 no_ack_thr ;
#if ATH_TARGET
    if (wal_rc_is_bt_active()) {
        no_ack_thr = g_default_no_ack_coex_thr >> tries;
    }
    else 
#endif
        {
        no_ack_thr = g_default_no_ack_wifi_thr >> tries;
    }
 
    return no_ack_thr;
}

static inline A_UINT8 rc_get_rate_bw_idx(A_UINT32 pos)
{
    static const A_UINT8 _rate_bw_idx[WHAL_RC_MASK_MAX_IDX + 1] =
        {   /*[WHAL_RC_MASK_IDX_NON_HT]  */ 0,
            /*[WHAL_RC_MASK_IDX_HT_20]   */ 0,
            /*[WHAL_RC_MASK_IDX_HT_40]   */ 1,
            /*[WHAL_RC_MASK_IDX_VHT_20]  */ 0,
            /*[WHAL_RC_MASK_IDX_VHT_40]  */ 1,
            /*[WHAL_RC_MASK_IDX_VHT_80]  */ 2,
        };

    return _rate_bw_idx[pos];

}

#ifdef RC_WAR_INCORRECT_PEER_PHYMODE
/*
 * The idea of having separate phy_mode and ni_flag bw indication was
 * to maintain max capability receied in Assoc Req and rather dynamic
 * VHT Operating Mode field changing ni_flags bw dynamically to avoid
 * overhead of doing rcSibUpdate again.
 * However, in past, umac and firmware went out of sync while handling
 * VHT Operating Mode element and for the sake of quick fix this 
 * workaround was proposed, which:
 *     - overwrites phy_mode to allow run-time changes into ni_flags bw
         by using WMI_PEER_CHWIDTH.
 */
static void rc_war_correct_phymode(struct rate_node *pSib)
{
     if (pSib->peer_params.ni_flags & RC_PEER_VHT) {
         pSib->peer_params.phymode = MODE_11AC_VHT80;

#if 0
        if (pSib->peer_params.ni_flags & RC_PEER_80MHZ)
            pSib->peer_params.phymode = MODE_11AC_VHT80;
        else if (pSib->peer_params.ni_flags & RC_PEER_40MHZ)
            pSib->peer_params.phymode = MODE_11AC_VHT40;
        else
            pSib->peer_params.phymode = MODE_11AC_VHT20;
#endif
    }

}
#endif

A_UINT32 defaultSpatialMuxMCSMask[] =
{
    /*[MODE_STBC]    */ 0x0000f07f, // Enable MCS 0-6, 12-15 when STBC/TXBF is supported.
    /*[MODE_NO_STBC] */ 0x0000f81f, // Enable MCS 0-4, 11-15 when STBC/TXBF is not supported.
};

/* ieee80211_basic_rateset a set of basic rates for each mode. these
 * values represent the dot11 protocol representation for each rate
 * (eg 2 = 1mbps).  */
static struct ieee80211_rateset ieee80211_basic_rateset[] = {
        { 3, { 12, 24, 48 } },      /* MODE_11A */
        { 4, { 2, 4, 11, 22 } },    /* MODE_11G (mixed b/g) */
        { 4, { 2, 4, 11, 22 } },    /* MODE_11B */
        { 3, { 12, 24, 48 } },      /* MODE_11GONLY */
        { 3, { 12, 24, 48 } },      /* MODE_11NA_HT20 */
        { 4, { 2, 4, 11, 22 } },    /* MODE_11NG_HT20 (mixed b/g) */
        { 3, { 12, 24, 48 } },      /* MODE_11NA_HT40 */
        { 4, { 2, 4, 11, 22 } },    /* MODE_11NG_HT40 (mixed b/g) */
        { 3, { 12, 24, 48 } },      /* MODE_11AC_VHT20 */
        { 3, { 12, 24, 48 } },      /* MODE_11AC_VHT40 */
        { 3, { 12, 24, 48 } },      /* MODE_11AC_VHT80 */
};

/* FIXME */
struct ieee80211_rateset *pBasicRateSet = ieee80211_basic_rateset;

#ifdef ENABLE_RSSI_BASED_RATECTRL
static A_UINT32 ratectrl_mode = 0;
/* Based on passed mode determine if RSSI should be taken into account as well.
    REVISIT
 */
#define not_per_only()    ((ratectrl_mode) != 0)
#endif /* ENABLE_RSSI_BASED_RATECTRL */

/*
 * INTERNAL FUNCTIONS START
 */

/*
    Returns 0: if peer STA is legacy, 1 if peer STA is HT and not VHT, 2 if peer STA is VHT
*/
A_UINT32 _RATE_GetPeerPhy(struct rate_node *an)
{
    /* Get rate control mask that is used to derive best rate based on whether
            peer STA is legacy (0), HT (1) or VHT (3) capable.
     */
    if (IS_CONN_ACTIVE((an->peer))) {
        if (an->peer_params.ni_flags & RC_PEER_VHT)
            return 2;
        if (an->peer_params.ni_flags & RC_PEER_HT)
            return 1;
    }

    return 0;
}

A_UINT32 _RATE_GetTxChainMask(
        struct rate_node *an,
        const WHAL_RATE_TABLE *pRateTable,
        A_UINT8 rix)
{
    A_UINT32 tx_chain_mask;

    if (IS_CONN_ACTIVE((an->peer))) {
        if (RATECTRL_DO_NOT_USE_CDD()) {
            tx_chain_mask = an->peer_params.valid_tx_chainmask;
        }
        else {
#if ATH_TARGET
            wlan_vdev_t *dev =
                    (wlan_vdev_t *)(((wlan_peer_t *)(an->peer))->pDev);
            A_UINT8 rc = RT_GET_HW_RATECODE(pRateTable,  rix);
            A_UINT8 mcs = RT_GET_DOT11RATE(pRateTable,  rix);

            tx_chain_mask =
                wal_rc_get_vdev_tx_chainmask_4_rc(DEV_GET_WAL_VDEV(dev), rc);

            /* Check if CDD disabled for selected rates if so modify tx chain
               mask accordingly */
            if (RATECTRL_PEER_1x1(an) && 
                RATECTRL_NO_CDD_1x1_STA(DEV_GET_WAL_VDEV(dev)) && 
                RT_IS_HT_INDEX(rix) &&
                RATECTRL_CDD_NOT_ALLOWED_FOR_MCS(mcs)) {
                /* Get chaninmask where only lowest chain is enabled */
                tx_chain_mask = tx_chain_mask & ~(tx_chain_mask - 1);
            }
#else
            tx_chain_mask = an->peer_params.valid_tx_chainmask;
#endif
        }
    }
    else {
        /* Why are we here? */
        A_ASSERT(0);
    }

    A_ASSERT(tx_chain_mask && (tx_chain_mask < (1 << MAX_SPATIAL_STREAM)));

    return tx_chain_mask;
}

/*
 * Returns HW rate flags when rate supports STBC, LDPC
*/
A_UINT32 _RATE_GetRCFlags(struct rate_node *an,
        RATE_CONTEXT * g_pRATE,
        const WHAL_RATE_TABLE *pRateTable,
        A_UINT8 rix)
{
    A_UINT32 flags = 0;

    if (RT_IS_HT_INDEX(rix) && IS_CONN_ACTIVE((an->peer))) {

        if(an->peer_params.ni_flags & RC_PEER_VHT) { /* VHT mode */
            if (RT_IS_STBC(pRateTable, rix) &&
                (an->peer_params.vht_caps & IEEE80211_VHTCAP_RX_STBC)) {
                flags |= WHAL_RC_FLAG_STBC;
            }

            if (RT_IS_LDPC(pRateTable, rix) &&
                (an->peer_params.vht_caps & IEEE80211_VHTCAP_RX_LDPC)) {
                flags |= WHAL_RC_FLAG_LDPC;
            }
        } else { /* HT mode */
            if (RT_IS_STBC(pRateTable, rix) &&
                (an->peer_params.ht_caps & IEEE80211_HTCAP_C_RXSTBC)) {
                flags |= WHAL_RC_FLAG_STBC;
            }

            if (RT_IS_LDPC(pRateTable, rix) &&
                (an->peer_params.ht_caps & IEEE80211_HTCAP_C_ADVCODING)) {
                flags |= WHAL_RC_FLAG_LDPC;
            }
        }
    }
    
    return flags;
}

void _RATE_SetSGIMasks(RATE_CONTEXT * g_pRATE)
{
    g_pRATE->sgiPERThreshold = g_default_sgi_per_thresh;
    g_pRATE->userSgiMask = INVALID_SGI_MASK;

    /* HT SGI mask is only enabled for highest rate */
    g_pRATE->sgiMask[0] = (0x80);

    /* VHT SGI mask is only enabled for highwe stream MCS 7, 8, 9 */
    g_pRATE->sgiMask[1] = (0x380);

}

A_UINT32 _RATE_GetSGIFlag(struct rate_node *an,
        RATE_CONTEXT * g_pRATE,
        const WHAL_RATE_TABLE *pRateTable,
        A_UINT8 rix)
{
#ifdef SMART_ANTENNA
    /* FIXME In case of training packets, some times this rouitne is 
       causing Assert. Adding this check temporarily. */
    if(an->txRateCtrl == NULL)
        return 0;
#endif

    if (an && an->txRateCtrl->htSgiValid) {
        A_RATEMASK sgi_mask;
        A_UINT32 m_idx, bit_pos;
        A_UINT8 nss_idx = 
            rc_get_nss_from_chainmask(an->peer_params.valid_tx_chainmask);

        if (nss_idx > g_pRATE->curr_nss)
           nss_idx = g_pRATE->curr_nss;
        nss_idx--; /* Actual NSS index starts from 0 */

        RT_GET_RC_MASK_4_RIX((void *)pRateTable, rix, &m_idx,&bit_pos);

        if (m_idx && RT_IS_VHT_INDEX(rix)) { /* VHT */
#if RC_SUPPORT_1D_RATECTRL
            if (g_use_2d_ratectrl) {
#endif
                int i;
                sgi_mask = 0;
                for (i = 0; i <= nss_idx; ++i) {
                    sgi_mask |= g_pRATE->sgiMask[1] <<((i << 3) + (i <<1));
                }
#if RC_SUPPORT_1D_RATECTRL
            } else {
                sgi_mask = g_pRATE->sgiMask[1] <<((nss_idx << 3) + (nss_idx <<1));
            }
#endif

            if (RATEMASK_IS_VALID(sgi_mask, bit_pos) &&
                (an->txRateCtrl->state[rix].per <=
                g_pRATE->sgiPERThreshold)) {
                if ((m_idx == WHAL_RC_MASK_IDX_VHT_80 && 
                    (an->txRateCtrl->htSgiValid & TX_RATE_SGI_80)) ||
                    (m_idx == WHAL_RC_MASK_IDX_VHT_40 && 
                    (an->txRateCtrl->htSgiValid & TX_RATE_SGI_40)) ||
                    (m_idx == WHAL_RC_MASK_IDX_VHT_20 && 
                    (an->txRateCtrl->htSgiValid & TX_RATE_SGI_20))) {

                    return WHAL_RC_FLAG_SGI;                    
                }
            }
            
        }
        else if (m_idx) { /* HT case */
#if RC_SUPPORT_1D_RATECTRL
            if (g_use_2d_ratectrl) {
#endif
                int i;
                sgi_mask = 0;
                for (i = 0; i <= nss_idx; ++i) {
                    sgi_mask |= g_pRATE->sgiMask[0] << (i << 3);
                }
#if RC_SUPPORT_1D_RATECTRL
            } else {
                sgi_mask = g_pRATE->sgiMask[0] <<(nss_idx << 3);
            }
#endif
            if (RATEMASK_IS_VALID(sgi_mask, bit_pos) && 
                (an->txRateCtrl->state[rix].per <=
                g_pRATE->sgiPERThreshold)) {
                if ((m_idx == WHAL_RC_MASK_IDX_HT_40 && 
                    (an->txRateCtrl->htSgiValid & TX_RATE_SGI_40)) ||
                    (m_idx == WHAL_RC_MASK_IDX_HT_20 && 
                    (an->txRateCtrl->htSgiValid & TX_RATE_SGI_20))) {

                    return WHAL_RC_FLAG_SGI;                    
                }
            }
            
        }

    }
    return 0;
}

/* Return value
    0: NO RTS/CTS
    1: RTS-CTS
    2: CTS2Self
*/

WAL_RC_RTS_CTS _RATE_IsRTS_CTS_Enabled(struct rate_node *an)
{
#if ATH_TARGET
    wlan_peer_t *peer = (wlan_peer_t *)(an->peer);
    wlan_vdev_t *dev  = (wlan_vdev_t *)(peer->pDev);
    wal_vdev_t *wal_vdev = DEV_GET_WAL_VDEV(dev);
    /* Enable only for OFDM, HT and VHT association */
    if (an->peer_params.phymode != MODE_11B)  {
        return wal_rc_get_vdev_rts_cts(wal_vdev);
    }
#endif
    return 0;
}

WAL_RC_RTSCTS_PROFILE _RATE_GetRTS_CTS_Profile(struct rate_node *an)
{
#if ATH_TARGET
    wlan_peer_t *peer = (wlan_peer_t *)(an->peer);
    wlan_vdev_t *dev  = (wlan_vdev_t *)(peer->pDev);
    wal_vdev_t *wal_vdev = DEV_GET_WAL_VDEV(dev);
    return wal_rc_get_vdev_rts_cts_profile(wal_vdev);
#else
    /* WAR for host-based. Needs to be removed. */
    return 0;
#endif
}

/* returns index of least sig bit */
A_UINT8 _GetLSB(A_RATEMASK mask)
{
    A_UINT8 res = 0/*?*/;
    
    if(!mask) {
        return 0xff;
    }
    
    do {
        if(mask & 0x000000ff) {
            res = 0;
        } else if(mask & 0x0000ff00) {
            res = 8;
        } else if(mask & 0x00ff0000) {
            res = 16;
        } else if(mask & 0xff000000) {
            res = 24;
        } else if(mask & 0x000000ff00000000ULL) {
            res = 32;
        } else if(mask & 0x00000f0000000000ULL) {
            res = 40;
        }
        
        
        mask >>= res;
        
        if((mask & 0x0f) == 0) {
            mask >>= 4;
            res += 4;
        }
        
        if(mask & 0x01) {
            break;
        }
        
        switch (mask & 0x0f) {
        case 2:
        case 6:
        case 10:
        case 14:
            res += 1;
            break;
        case 4:
        case 12:
            res += 2;
            break;
        case 8:
            res += 3;
            break;        
        }
    }while(0);
    
    return res;
}

/* returns index of most sig bit */
A_UINT8 _GetMSB(A_RATEMASK mask)
{
    A_UINT8 res;
    
    if(!mask) {
        return 0xff;
    }
    
    do {
        if(mask & 0x00000f0000000000ULL) {
            res = 40;
        } else if(mask & 0x000000ff00000000ULL) {
            res = 32;
        }
        if (0) {
        }
        else if(mask & 0xff000000) {
            res = 24;
        } else if(mask & 0x00ff0000) {
            res = 16;
        } else if(mask & 0x0000ff00) {
            res = 8;
        } else {
            res = 0;
        }
        
        mask >>= res;
    
        if(mask & 0xf0) {
            mask >>= 4;
            res += 4;
        }                
        
        switch (mask & 0x0f) {
        case 1:
            break;
        case 2:
        case 3:
            res += 1;
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            res += 2;
            break;
        default:
            res += 3;
            break;            
        }
    }while(0);
    
    return res;
}
 
void _rate_setup(RATE_CONTEXT *g_pRATE, WLAN_PHY_MODE mode)
{
#if 0
    const WHAL_RATE_TABLE *rt;
    struct ieee80211_rateset *rs;
    A_UINT32 i;
    A_UINT8 count;
    
    rt = whalGetRateTable(mode);

#ifdef WLAN_DEBUG
    if (rt == NULL) {
        A_PRINTF("%s:No Rate Table Setup for mode %d\n", __func__, mode);
        return ;
    }
#endif    
    
//    rs = &dev->ic_sup_rates[mode];
//    rs = &g_pRATE->vdev_params.ic_sup_rates[mode];

    count = 0;

/*
     REVISIT
     This function can be simplified a lot based on mandatory rates
     also RT_GET_RATE_COUNT should be removed with only OFDM/CCK? but there 
     a break below.
*/
    for (i = 0; i < RT_GET_RATE_COUNT(rt) ; i++)
    {
        if( RT_IS_VALID_RATE(rt, i, mode) && 
            !RT_IS_HT(rt,i) && !RT_IS_VHT(rt,i))
        {
#ifdef P2P
            /*Disable CCK rates for P2P device rate set*/
            if((g_pRATE->vdev_params.ic_subopmode !=SUB_OPMODE_NONE) &&(mode == MODE_11G ||
                mode == MODE_11NG_HT20 || mode == MODE_11NG_HT40)) {
                if(RT_GET_PHY(rt, i) == WHAL_MOD_IEEE80211_T_CCK)
                  continue;
            }
#endif
            rs->rs_rates[count++] = RT_GET_DOT11RATE(rt, i);

            if(count >= IEEE80211_RATE_MAXSIZE)
                break;
        }
    }
    rs->rs_nrates = count;
#endif
}

A_BOOL _rcGetValidTxRateMaxMcs(const WHAL_RATE_TABLE *pRateTable,
        struct TxRateCtrl_s *pRc, RC_MASK_INFO_t *rc_mask_info,
        A_UINT8 nss_idx, A_UINT8 maxMcs, A_UINT8 *pFoundIndex)
{
    A_UINT8     i,j;
    A_UINT8 num_rix;
    A_UINT8 *pValidRate;
    A_UINT8 upper, lower;
    A_BOOL result = FALSE;

    RT_GET_RIX_LIMITS_4_MASK(&upper, &lower, rc_mask_info->idx);

    num_rix = pRc->u.tD.maxValidRate[rc_mask_info->idx][nss_idx];
    pValidRate = rc_get_valid_rates_2d(pRc, rc_mask_info->idx, nss_idx);

    for (i = 0; i < num_rix; i++) {
        j = pValidRate[i];

        if (RATEMASK_IS_VALID(rc_mask_info->rc_mask, (j - lower))){
            A_UINT8 mcs = rc_get_mcs_from_rix(pRateTable, j);
            if (mcs <= maxMcs) { 
                *pFoundIndex = j;
                result = TRUE;
            } else {
                break;
            }
        }
    }

    return result;
}
/* Iterators for validTxRateMask */
/* rcGetNextValidTxRate - used when probing for next higher rate */
/* Iterators for validTxRateMask */
A_BOOL _rcGetNextValidTxRate(const WHAL_RATE_TABLE *pRateTable,
        struct TxRateCtrl_s *pRc, RC_MASK_INFO_t *rc_mask_info, 
        A_UINT8 curValidTxRate, A_UINT8 *pNextIndex)
{
    A_UINT8     i,j;
    A_BOOL      found = FALSE; 
    A_UINT8 num_rix;
    A_UINT8 nss_idx;
    A_UINT8 max_rix;
    A_UINT8 *pValidRate;

#if RC_SUPPORT_1D_RATECTRL
    if (g_use_2d_ratectrl) {
#endif
        nss_idx = rc_get_nss_idx_from_rix(pRateTable, curValidTxRate);
        num_rix = pRc->u.tD.maxValidRate[rc_mask_info->idx][nss_idx];
        A_ASSERT(num_rix);
        pValidRate = rc_get_valid_rates_2d(pRc, rc_mask_info->idx, nss_idx);
        max_rix = pValidRate[num_rix - 1];
#if RC_SUPPORT_1D_RATECTRL
    } else {
        num_rix = pRc->u.oD.maxValidRate[rc_mask_info->idx];
        A_ASSERT(num_rix);
        max_rix = pRc->u.oD.validRateIndex[rc_mask_info->idx][num_rix - 1];
        pValidRate = pRc->u.oD.validRateIndex[rc_mask_info->idx];
    }
#endif

    /* Don't do anything if already at highest rate */
    if (max_rix == curValidTxRate) {
        goto done;
    }

    for (i = 0; i < num_rix; i++) {
        if (found == TRUE) {
            A_UINT8 upper, lower;

            RT_GET_RIX_LIMITS_4_MASK(&upper, &lower, rc_mask_info->idx);

            j = pValidRate[i];

            if (RATEMASK_IS_VALID(rc_mask_info->rc_mask, (j - lower))){
                *pNextIndex = j;
                return TRUE;
            }
        }
        else {
            if (pValidRate[i] == curValidTxRate) {
                found = TRUE;
            }
        }
    }

done:
    /* No more valid rates */
    *pNextIndex = 0;
    return FALSE;
}

A_BOOL _rcGetLowerValid(const WHAL_RATE_TABLE *pRateTable, A_UINT8 index,
    struct TxRateCtrl_s  *pRc, RC_MASK_INFO_t *rc_mask_info,
    A_UINT8 *pNextIndex, A_UINT8 nss_idx)
{
    A_UINT8 j;
    A_RATEMASK currMask = rc_mask_info->rc_mask;
    A_UINT8 upper, lower;
    A_UINT8 *pValidRate;

#if RC_SUPPORT_1D_RATECTRL
    if (g_use_2d_ratectrl) {
#endif
        pValidRate = rc_get_valid_rates_2d(pRc, rc_mask_info->idx, nss_idx);
#if RC_SUPPORT_1D_RATECTRL
    } else {
        pValidRate = pRc->u.oD.validRateIndex[rc_mask_info->idx];
    }
#endif

    RT_GET_RIX_LIMITS_4_MASK(&upper, &lower, rc_mask_info->idx);
    
    while(index) {
        /* Move to the next valid rate   */
        index--;

        j = pValidRate[index];
        
        if (RATEMASK_IS_VALID(currMask, (j - lower))) {
            *pNextIndex = index;
            return TRUE;
        }
    }

    *pNextIndex = index;
    return FALSE;
}

A_UINT8 _rcGetNextLowerValidTxRate(const WHAL_RATE_TABLE *pRateTable,
        RC_MASK_INFO_t *rc_mask_info, struct TxRateCtrl_s  *pRc,
        A_UINT8 curValidTxRate, A_UINT8 *pNextRateIndex)
{
    A_UINT8 i;
    A_UINT8 nss_idx;
    A_UINT8 num_rix;
    A_UINT8 *pValidRate;

    nss_idx = rc_get_nss_idx_from_rix(pRateTable, curValidTxRate);

#if RC_SUPPORT_1D_RATECTRL
    if (g_use_2d_ratectrl) {
#endif
        pValidRate = rc_get_valid_rates_2d(pRc, rc_mask_info->idx, nss_idx);
        num_rix = pRc->u.tD.maxValidRate[rc_mask_info->idx][nss_idx];
#if RC_SUPPORT_1D_RATECTRL
    } else {
        pValidRate = pRc->u.oD.validRateIndex[rc_mask_info->idx];
        num_rix = pRc->u.oD.maxValidRate[rc_mask_info->idx];
    }
#endif

    for (i = 0; i < num_rix; i++) {
        if (pValidRate[i] == curValidTxRate) {
            break;
        }
    }
    if (i == num_rix) {
        *pNextRateIndex = curValidTxRate;
        return RT_INVAL_IDX;
    }

    /* Ratemask will have the latest valid rates so double check with the rate mask.
     * to see if the next lower index is indeed valid.
     */
    if (rcGetLowerValid(pRateTable, i, pRc, rc_mask_info, &i, nss_idx)) {
        *pNextRateIndex = pValidRate[i];
    } else {
        *pNextRateIndex = curValidTxRate;
        return RT_INVAL_IDX;
    }

    return i;
}


/*
 * This API returns rate tbl, txrate and rate Index based on
 * pkt type(MGMT, CTRL, DATA or NULL DATA) for non-VHT mode
 * for VHT it has different meaning and is only used for data frames
 
 */
void
_GetRateTblAndIndex(RATE_CONTEXT *g_pRATE, A_UINT8 *probe_rix,
                        A_BOOL shortPreamble, struct rate_node *an,
                        A_UINT8 * txrate, const WHAL_RATE_TABLE ** rt,
                        A_UINT8 * rix, A_BOOL isLowest, 
                        RC_MASK_INFO_t *rc_mask_info, A_UINT32 nowMsec)
{
    const WHAL_RATE_TABLE * pRateTable = NULL;

    pRateTable = g_pRATE->sc_currates;
    
    /* a non-zero ratemask passed in trumps all other rules. It
     * implies that the host has specified through a rate policy
     * what rates should be considered for this frame. */
    if(rc_mask_info->rc_mask) {    
    
        *rix = (A_UINT8)rcRateFind(g_pRATE, an, 1500, FALSE, rc_mask_info,
                                   probe_rix, nowMsec);
        *txrate = RT_GET_HW_RATECODE(pRateTable, (*rix)) |
                 (shortPreamble ? RT_GET_SHORTPREAM_CODE(pRateTable, (*rix)) :0);
    
    } else {
        /* Execution path if a rateMask has not been specified by the caller */

            // If a valid fixed rate is specified, use it
            if (g_pRATE->sc_fixedrix != -1){
                A_UINT32 m_idx, b_idx;
                
                RT_GET_RC_MASK_4_RIX((void *)pRateTable,g_pRATE->sc_fixedrix, 
                    &m_idx,&b_idx);

                if (RATEMASK_IS_VALID(an->txRateCtrl->validTxRateMask[m_idx],
                        b_idx)) {
                    *rix = (A_UINT8)g_pRATE->sc_fixedrix;
                    *txrate = RT_GET_HW_RATECODE(pRateTable, (*rix));
                    RATEMASK_SET_IDX(rc_mask_info->rc_mask, b_idx);
                }
                else {
                    A_ASSERT(0);
                }
            } 
            else { /* Actual rate control find, no Fix rate */
                *rix = (A_UINT8)rcRateFind(g_pRATE, an, 1500, isLowest,
                    rc_mask_info, probe_rix, nowMsec);
                
                *txrate = RT_GET_HW_RATECODE(pRateTable, (*rix)) |
                           (shortPreamble ? RT_GET_SHORTPREAM_CODE(pRateTable, (*rix)) :0);
                #if 0
                rc_mask_info->rc_mask = 
                          g_pRATE->sc_fixRateSet[rc_mask_info->idx] & 
                          an->txRateCtrl.validTxRateMask[rc_mask_info->idx];

                if(g_pRATE->sc_bFramematch){
                    rc_mask_info->rc_mask &= 
                            g_pRATE->sc_frameRateMask[rc_mask_info->idx];
                }
                #endif
                
            }
    }

    *rt = pRateTable;
    g_pRATE->sc_bFramematch = 0;
    return ;
}

A_BOOL _RateCheckDefaultMCSMask(struct rate_node *rc_node, A_UINT8 mcs_idx)
{
    /* TODO 
            add VHT specific STBC/TxBF testing here
       */
            
    if (rc_node->peer_params.ni_flags & RC_PEER_VHT) {
        //need to fix this
        return TRUE;
    }


    /* N.B. STBC capabilities are derived from the ht_caps/vht_caps now. Not
     * updated here since this function is not being used anymore. */
    if (rc_node->peer_params.ni_flags & RC_PEER_SPATIAL_MUX) {
        if (rc_node->peer_params.ni_flags &
                (RC_PEER_STBC|RC_PEER_TXBF)) {
            if (defaultSpatialMuxMCSMask[MODE_STBC] & (1<<mcs_idx)) {
                return TRUE;
            }
        } else {
            if (defaultSpatialMuxMCSMask[MODE_NO_STBC] & (1<<mcs_idx)) {
                return TRUE;
            }
        }

        return FALSE;
   }

   return TRUE;
}
/* Check the rate index is valid for the current node flags.
 * This routine can be extended to support other features that needs to enable or disable
 * rates per node basis.
 *  - Check if HT40 is enabled in the ni_flags before enabling HT40 rates.
 *  - Check if spatial multiplexing can be enabled.
 */
A_BOOL _RateValidCheckNodeFlags(struct rate_node *rc_node,
        const WHAL_RATE_TABLE *pRateTable, A_UINT16 rix)
{
    if (rc_node->peer_params.ni_flags & RC_PEER_VHT) {
        
        if (RT_IS_VHT_80MHZ(pRateTable, rix) && 
            (rc_node->peer_params.ni_flags & RC_PEER_80MHZ))
            goto check_nss;

        else if (RT_IS_VHT_40MHZ(pRateTable, rix) && 
            (rc_node->peer_params.ni_flags & RC_PEER_40MHZ))
            goto check_nss;

        else if (RT_IS_VHT_20MHZ(pRateTable, rix))
            goto check_nss;
        
    }

    if (!RT_IS_40MHZ(pRateTable, rix) || 
        (rc_node->peer_params.ni_flags & RC_PEER_40MHZ)) {
        goto check_nss;
    }

check_nss:
    if (RT_IS_1SS(pRateTable, rix) || 
        (rc_node->peer_params.ni_flags & RC_PEER_SPATIAL_MUX))
        return TRUE;

    return FALSE;
}

#define VHT_INVALID_BCC_RATE  0
A_BOOL _RateValidCheck(const WHAL_RATE_TABLE *pRateTable,
        A_UINT16 rix, struct rate_node *rc_node)
{
    WLAN_PHY_MODE mode = rc_node->peer_params.phymode;
       /* Allow invalid BCC rates whenever LDPC is enabled (for 2G 256QAM only) */
    if((!RT_IS_VALID_RATE(pRateTable, rix, mode)) && 
          (!((rc_node->peer_params.ni_flags & RC_PEER_VHT_2G) &&
               (RT_IS_VHT_20MHZ(pRateTable, rix)) && 
               (RT_GET_INFO(pRateTable, rix).validModeMask == VHT_INVALID_BCC_RATE) && 
               (rc_node->peer_params.ni_flags & RC_PEER_LDPC))))
        return FALSE;
    
    /* HT 2G Association, skip certain CCK, OFDM rates */
    if (IS_PHYMODE_11N2G(mode) &&  RT_IS_OFDM_CCK_INDEX(rix) && 
        ((RT_GET_DOT11RATE(pRateTable, rix) == 22) ||  // CCK 11mbps rate  */
         (RT_GET_DOT11RATE(pRateTable, rix) == 11) ||  // CCK 5.5mbps rate */
         /* 11Mbps/5.5mbps CCK rates/OFDM rates are not used for HT */
        (RT_GET_PHY(pRateTable, rix) == WHAL_MOD_IEEE80211_T_OFDM))) {
        return FALSE;
    }    /* non-HT 2G Association, skip certain CCK, OFDM rates */
    else if ((mode == MODE_11G) && RT_IS_OFDM_CCK_INDEX(rix) &&
        ((RT_GET_DOT11RATE(pRateTable, rix) == 22) ||  // CCK 11mbps  */
         (RT_GET_DOT11RATE(pRateTable, rix) == 11) ||  // CCK 5.5mbps */
         (RT_GET_DOT11RATE(pRateTable, rix) == 18))) {  // OFDM 9mbps  */
        return FALSE;
    }
#if (NUM_SPATIAL_STREAM == 1)
   if(!(RT_IS_1SS(pRateTable, rix) || RT_IS_OFDM_CCK_INDEX(rix))){
      return FALSE;
   }
#endif    
    return TRUE;
}

void _rcSortValidRates(const WHAL_RATE_TABLE *pRateTable, A_UINT8 *pArray,
        int array_len)
{
    A_UINT8 i,j;

    if (array_len == 0) {
        return;
    }

    for (i = array_len - 1; i > 0; i--) {
        for (j = 0; j <= i - 1; j++) {
            if (RT_GET_RAW_KBPS(pRateTable, pArray[j]) > RT_GET_RAW_KBPS(pRateTable,
                pArray[j+1])) {
                A_UINT8 tmp=0;
                tmp = pArray[j];
                pArray[j] = 
                    pArray[j+1];
                pArray[j+1] = tmp;
            }
        }
    }

    return;
}

/*
 *  Check whether the MCS 8 and 9 are supported by the peer.
 *  This check is done based on the VHT Supported MCS Set
 *  information as per 11n and 11ac specs.
 */
#define VHT_MCS_SET_FOR_NSS(x, ss)   ( ((x) & (3 << ((ss)<<1))) >> ((ss)<<1) )
#define NUM_VHT_MCS_PER_NSS          10
#define NUM_HT_MCS_PER_NSS            8

void
_RateValidateRateSet(struct rate_node *pSib)
{
    struct TxRateCtrl_s *pRc = pSib->txRateCtrl;

    A_UINT8 num_rates = pSib->peer_params.ni_vht_max_rate;

    A_UINT32 vhtMaxMask = 0xffffffff;

    A_UINT8 nss_idx = rc_get_nss_from_chainmask(pSib->peer_params.valid_tx_chainmask);
    A_UINT8 i = 0, idx = 0;
    A_UINT8 mcs_set = 0;
    A_UINT32 mcsMask = (A_UINT32)0xffffffff, mcsSubMask = 0;

    pRc->validTxRateMask[WHAL_RC_MASK_IDX_NON_HT] &= pSib->peer_params.ni_legacy_rate_set;

    if(0 == pRc->validTxRateMask[WHAL_RC_MASK_IDX_NON_HT])
    {
        /* 
         * When the intersection turns out to be NULL, manually set atleast the 
         * basic rate set (1, 6, 12, 24). Any better way of doing this?
         */
        pRc->validTxRateMask[WHAL_RC_MASK_IDX_NON_HT] = ((1 << 3) | (1 << 5) | (1 << 6) | (1 << 7)); /* 0x00e8 */
    }

    if( pSib->peer_params.ni_flags & RC_PEER_HT ) {
        for( i=nss_idx; i>0; i-- ) {
            mcsMask = mcsMask << NUM_HT_MCS_PER_NSS;
            mcsMask = mcsMask | (pSib->peer_params.ni_ht_mcs_set[i-1]);
        }

        pRc->validTxRateMask[WHAL_RC_MASK_IDX_HT_20] &= mcsMask;
        pRc->validTxRateMask[WHAL_RC_MASK_IDX_HT_40] &= mcsMask;
    }

    mcsMask = (A_UINT32)0xffffffff;

    if( pSib->peer_params.ni_flags & RC_PEER_VHT ) {

        if (num_rates > 0) {
            /* enable MCS0.. MCS (num_rates-1) */
            vhtMaxMask = (1 << num_rates) - 1;
        }

        for( i=nss_idx; i > 0; i-- ) {
            mcs_set = VHT_MCS_SET_FOR_NSS(pSib->peer_params.ni_vht_mcs_set, (i-1));
            mcsMask = mcsMask << NUM_VHT_MCS_PER_NSS;

            switch(mcs_set) {
            case 0:
                mcsSubMask = 0xff; /* mask MCS 8 and 9 */
                break;
            case 1:
                mcsSubMask = 0x1ff; /* mask MCS 9 */
                break;
            case 2:
                mcsSubMask = 0x3ff; /* mask nothing */
                break;
            case 3:
                mcsSubMask = 0x00; /* mask all MCS */
                break;
            default:
                A_ASSERT(0);
                break;
            }

            mcsSubMask &= vhtMaxMask;

            mcsMask = mcsMask | mcsSubMask;
        }

        for( idx = WHAL_RC_MASK_IDX_VHT_20; idx <= WHAL_RC_MASK_IDX_VHT_80; idx++ ) {
            pRc->validTxRateMask[idx] &= mcsMask;
        }
    }

    return;
}

/* Get Valid Rate Mask depending on vdev, peer, and hw rate table */

static void _rc_get_peer_valid_rc_mask(RATE_CONTEXT *g_pRATE,
     struct rate_node *pSib,
     RC_MASK_INFO_t *rc_mask_info)
{
   struct TxRateCtrl_s  *pRc;
   pRc = pSib->txRateCtrl;

   /* Update the rate mask when it's not specified */
   rc_mask_info->rc_mask = g_pRATE->sc_fixRateSet[rc_mask_info->idx] &
                pRc->validTxRateMask[rc_mask_info->idx];

   if(g_pRATE->sc_bFramematch)
       rc_mask_info->rc_mask &= g_pRATE->sc_frameRateMask;
   if (rc_mask_info->idx) { /* HT/VHT rate apply MCS mask */
        /* The HW rate table MCS mask is based on minimum of
           wlan vdev current supported nss and peer's supported
           NSS.
        */
       A_UINT8 mcs_mask_idx;
       A_UINT8 nss_idx =
           rc_get_nss_from_chainmask(pSib->peer_params.valid_tx_chainmask);
       if (nss_idx > g_pRATE->curr_nss)
           nss_idx = g_pRATE->curr_nss;
       nss_idx--; /* Actual NSS index starts from 0 */

       mcs_mask_idx = (rc_mask_info->idx >= WHAL_RC_MASK_IDX_VHT_20)?
                      (NUM_SPATIAL_STREAM + nss_idx) : nss_idx;

       A_ASSERT(mcs_mask_idx < (2*NUM_SPATIAL_STREAM));

#if RC_SUPPORT_1D_RATECTRL
       if (g_use_2d_ratectrl) {
#endif
           rc_mask_info->rc_mask &= g_pRATE->mcs_mask_4_nss_2d[mcs_mask_idx];
#if RC_SUPPORT_1D_RATECTRL
       } else {
           rc_mask_info->rc_mask &= g_pRATE->mcs_mask_4_nss_1d[mcs_mask_idx];
       }
#endif
   }
}

/* Max PER after which we would lower current rateMax for given bw */
A_UINT32 g_rc_rate_max_per_thr = 50;

void _rc_validate_rateMax(const WHAL_RATE_TABLE *pRateTable, 
        RATE_CONTEXT * g_pRATE, struct rate_node *pSib)
{
    struct TxRateCtrl_s *pRc        = pSib->txRateCtrl;
    int i;
    A_UINT32 mask_idx, rix_bit;
    RC_MASK_INFO_t tmp;

#if RC_SUPPORT_1D_RATECTRL
    if (g_use_2d_ratectrl) {
#endif
        for (i=0; i < NUM_DYN_BW; i++) {
            int j;
            for (j = 0; j < NUM_SPATIAL_STREAM; ++j) {
                RT_GET_RC_MASK_4_RIX((void *)pRateTable, pRc->u.tD.rateMax[i][j], 
                     &mask_idx, &rix_bit);

                tmp.rc_mask = pRc->validTxRateMask[mask_idx] & 
                    g_pRATE->sc_fixRateSet[mask_idx];

                tmp.idx = mask_idx;

                _rc_get_peer_valid_rc_mask(g_pRATE, pSib, &tmp);

                if (!RATEMASK_IS_VALID(tmp.rc_mask, rix_bit)) {
                    /*
                     * Adjust rateMax to the lowest valid rate.
                     *
                     * This may temporarily cause the monotonicity of
                     * rateMax to be violated.
                     */
                    if (pRc->u.tD.maxValidRate[tmp.idx][j]) {
                        A_UINT8 *pValidRate = rc_get_valid_rates_2d(pRc, tmp.idx, j);
                        pRc->u.tD.rateMax[i][j] = pValidRate[0];
                    }
                }
            }
        }
#if RC_SUPPORT_1D_RATECTRL
    } else {
        for (i=0; i < NUM_DYN_BW; i++) {

            RT_GET_RC_MASK_4_RIX((void *)pRateTable, pRc->u.oD.rateMax[i], 
                 &mask_idx, &rix_bit);

            tmp.rc_mask = pRc->validTxRateMask[mask_idx] & 
                g_pRATE->sc_fixRateSet[mask_idx];

            tmp.idx = mask_idx;

            _rc_get_peer_valid_rc_mask(g_pRATE, pSib, &tmp);

            if (!RATEMASK_IS_VALID(tmp.rc_mask, rix_bit)) {
                /*
                 * Adjust rateMax to the lowest valid rate.
                 */
                pRc->u.oD.rateMax[i] = pRc->u.oD.validRateIndex[tmp.idx][0];
            }
        }
    }
#endif

}

#define INITIAL_HT_MCS  4
#define INITIAL_VHT_MCS 5

/*
 *  Update the SIB's rate control information
 *
 *  This should be called when the supported rates change
 *  (e.g. SME operation, wireless mode change)
 *
 *  It will determine which rates are valid for use.
 */

/* Used to change the PER-threshold at debug-time.
 * Will still need to re-assoc though, for this to take effect.
 */

/*TODO: hbrc- change rcSibUpdate's signature to include only peer rate-ctxt*/

void _rcSibUpdate(RATE_CONTEXT * g_pRATE, struct rate_node *pSib, void *peer)
{
    const WHAL_RATE_TABLE    *pRateTable = g_pRATE->sc_currates;
    struct TxRateCtrl_s *pRc        = pSib->txRateCtrl;
    A_UINT8             i, j, hi = 0, count, nss_idx;
    A_UINT8 *pValidRate;
    int                 rateCount;
    A_RATEMASK mask;
    A_UINT32 mask_idx, rc_bit;
#if RC_SUPPORT_1D_RATECTRL
    A_UINT8 rc_mask_cnt_1d[NUM_VALID_RC_MASK] = {0};
#endif
    A_UINT8 rc_mask_cnt_2d[NUM_VALID_RC_MASK][NUM_SPATIAL_STREAM] = { {0} };
    /* Initial rate table size. Will change depending on the working rate set */
    pRc->rateTableSize = MAX_TX_RATE_TBL;
    rateCount = RT_GET_RATE_COUNT(pRateTable);
    /* Pointer to the peer structure */
    pSib->peer = peer;

    /* Initialize thresholds according to the global rate table */
    for (i = 0 ; i < pRc->rateTableSize; i++) {
#ifdef ENABLE_RSSI_BASED_RATECTRL
        pRc->state[i].rssiThres = (i<rateCount)? RT_GET_RSSI_MIN(pRateTable, i) : 0;
#endif /* ENABLE_RSSI_BASED_RATECTRL */
        pRc->state[i].per       = 0;
    }
    
#ifdef ENABLE_RSSI_BASED_RATECTRL
    pRc->rssiDownTime = A_MILLISECONDS();
#endif /* ENABLE_RSSI_BASED_RATECTRL */

    if (g_pRATE->vdev_params.ic_opmode != RC_VDEV_M_AP) {
        A_MEMSET(&g_pRATE->sc_fixRateSet, 0, sizeof(g_pRATE->sc_fixRateSet));
    }

    /* Determine the valid rates */
    memset(&pRc->validTxRateMask, 0, sizeof(pRc->validTxRateMask));

    count = 0;

    if (1) {
        A_UINT32 ht_mcs_set = 0;
        ht_mcs_set = pSib->peer_params.ni_ht_mcs_set[0];
        if (MAX_SPATIAL_STREAM > 1) {
            ht_mcs_set |= (pSib->peer_params.ni_ht_mcs_set[1] << 8);
            if (MAX_SPATIAL_STREAM > 2) {
                ht_mcs_set |= (pSib->peer_params.ni_ht_mcs_set[2] << 16);
            }
        }

#if ATH_TARGET
        DBGLOG_RECORD_LOG(WLAN_MODULE_RATECTRL, -1,
            RATECTRL_DBGID_ASSOC, DBGLOG_ERR, 6,
            pSib->peer_params.valid_tx_chainmask, pSib->peer_params.phymode, pSib->peer_params.ni_flags,
            pSib->peer_params.ni_vht_mcs_set, ht_mcs_set, pSib->peer_params.ni_legacy_rate_set);
#endif
    }
    A_ASSERT(pSib->peer_params.phymode <= MODE_11AC_VHT80);

#ifdef RC_WAR_INCORRECT_PEER_PHYMODE
   rc_war_correct_phymode(pSib);
#endif

    if (1) {
        /* No working rate, use valid rates */
        for (i = 0; i < rateCount; i++) {

            if (RateValidCheck(pRateTable, i, pSib))
            {
                RT_GET_RC_MASK_4_RIX((void *)pRateTable, i, &mask_idx,&rc_bit);
#if RC_SUPPORT_1D_RATECTRL
                if (g_use_2d_ratectrl) {
#endif
                    nss_idx = rc_get_nss_idx_from_rix(pRateTable, i);
                    pValidRate = rc_get_valid_rates_2d(pRc, mask_idx, nss_idx);
                    pValidRate[rc_mask_cnt_2d[mask_idx][nss_idx]++] = i;
#if RC_SUPPORT_1D_RATECTRL
                } else {
                    pRc->u.oD.validRateIndex[mask_idx][rc_mask_cnt_1d[mask_idx]++] = i;
                }
#endif
                count ++;
                RATEMASK_ADD_IDX(pRc->validTxRateMask[mask_idx], 
                    pRc->validTxRateMask[mask_idx], rc_bit);

                hi = A_MAX(hi, i);

            }  
        }
#if RC_SUPPORT_1D_RATECTRL
        if (g_use_2d_ratectrl) {
#endif
            A_MEMCPY(&pRc->u.tD.maxValidRate,&rc_mask_cnt_2d,sizeof (rc_mask_cnt_2d));
#if RC_SUPPORT_1D_RATECTRL
        } else {
            A_MEMCPY(&pRc->u.oD.maxValidRate,&rc_mask_cnt_1d,sizeof (rc_mask_cnt_1d));
        }
#endif
        RateValidateRateSet(pSib);
    }

        /* Get actually valid rate index, previous we get it from rate table,
         * now get rate table which include all working rate, so we need make
         * sure our valid rate table align with working rate */

        for (j = WHAL_RC_MASK_IDX_NON_HT; j <= WHAL_RC_MASK_MAX_IDX; j++) {
            A_UINT8 lower_rix, upper_rix;
            A_UINT8 count_2d[NUM_SPATIAL_STREAM] = { 0 };
            count = 0;
            mask = pRc->validTxRateMask[j];
            RT_GET_RIX_LIMITS_4_MASK(&upper_rix, &lower_rix, j);
            for (i = lower_rix; i <= upper_rix; i++) {
                if (RATEMASK_IS_VALID(mask, (i-lower_rix))) {
#if RC_SUPPORT_1D_RATECTRL
                    if (g_use_2d_ratectrl) {
#endif
                        nss_idx = rc_get_nss_idx_from_rix(pRateTable, i);
                        pValidRate = rc_get_valid_rates_2d(pRc, j, nss_idx);
                        pValidRate[count_2d[nss_idx]++] = i;
#if RC_SUPPORT_1D_RATECTRL
                    } else {
                        pRc->u.oD.validRateIndex[j][count++] = i;
                    }
#endif
                }
            }
#if RC_SUPPORT_1D_RATECTRL
            if (g_use_2d_ratectrl) {
#endif
                A_MEMCPY(pRc->u.tD.maxValidRate[j], count_2d, sizeof(count_2d));
#if RC_SUPPORT_1D_RATECTRL
            } else {
                pRc->u.oD.maxValidRate[j] = count;
            }
#endif
            /* Sort the rate in the current mask */
#if RC_SUPPORT_1D_RATECTRL
            if (g_use_2d_ratectrl) {
#endif
                for (nss_idx = 0; nss_idx < NUM_SPATIAL_STREAM; ++nss_idx) {
                    if (pRc->u.tD.maxValidRate[j][nss_idx]) {
                        pValidRate = rc_get_valid_rates_2d(pRc, j, nss_idx);
                        rcSortValidRates(pRateTable, pValidRate, pRc->u.tD.maxValidRate[j][nss_idx]);
                    }
                }
#if RC_SUPPORT_1D_RATECTRL
            } else {
                rcSortValidRates(pRateTable, pRc->u.oD.validRateIndex[j], pRc->u.oD.maxValidRate[j]);
            }
#endif
        }
    
    pRc->rateTableSize = hi + 1;

    A_ASSERT(pRc->rateTableSize <= MAX_TX_RATE_TBL);

    A_MEMCPY(&g_pRATE->sc_fixRateSet, &g_pRATE->wmiFixRateSetMask,
        sizeof(g_pRATE->sc_fixRateSet));

    // If fixedRateMask and validTxRateMask for the connection doesnt have anything common
    // use all validTxRates
    /* Index 0 is for OFDM/CCK non-HT rates */
    if ((g_pRATE->sc_fixRateSet[0] & pRc->validTxRateMask[0]) == 0) {
        g_pRATE->sc_fixRateSet[0] = A_RATEMASK_OFDM_CCK;
    }

    switch (pSib->peer_params.phymode) {

        /* REVISIT 
           Make sure all the init max rates are valid given dynamic masks*/
        case MODE_11NA_HT20:
        case MODE_11NA_HT40:
#if RC_SUPPORT_1D_RATECTRL
            if (g_use_2d_ratectrl) {
#endif
                for (nss_idx = 0; nss_idx < NUM_SPATIAL_STREAM; ++nss_idx) {
                    pRc->u.tD.rateMax[0][nss_idx] = HT_20_RATE_TABLE_INDEX +
                        nss_idx * NUM_HT_MCS_PER_NSS + INITIAL_HT_MCS;

                    pRc->u.tD.rateMax[1][nss_idx] = HT_40_RATE_TABLE_INDEX +
                        nss_idx * NUM_HT_MCS_PER_NSS + INITIAL_HT_MCS;
                }
#if RC_SUPPORT_1D_RATECTRL
            } else {
                pRc->u.oD.rateMax[0] = RT_GET_INIT_MAXRATE(pRateTable, MODE_11NA_HT20);
                pRc->u.oD.rateMax[1] = RT_GET_INIT_MAXRATE(pRateTable, MODE_11NA_HT40);
            }
#endif
            break;

        case MODE_11NG_HT20:
        case MODE_11NG_HT40:
#if RC_SUPPORT_1D_RATECTRL
            if (g_use_2d_ratectrl) {
#endif
                for (nss_idx = 0; nss_idx < NUM_SPATIAL_STREAM; ++nss_idx) {
                    pRc->u.tD.rateMax[0][nss_idx] = HT_20_RATE_TABLE_INDEX +
                        nss_idx * NUM_HT_MCS_PER_NSS + INITIAL_HT_MCS;

                    pRc->u.tD.rateMax[1][nss_idx] = HT_40_RATE_TABLE_INDEX +
                        nss_idx * NUM_HT_MCS_PER_NSS + INITIAL_HT_MCS;
                }
#if RC_SUPPORT_1D_RATECTRL
            } else {
                pRc->u.oD.rateMax[0] = RT_GET_INIT_MAXRATE(pRateTable, MODE_11NG_HT20);
                pRc->u.oD.rateMax[1] = RT_GET_INIT_MAXRATE(pRateTable, MODE_11NG_HT40);
            }
#endif
            break;

        case MODE_11AC_VHT20:
        case MODE_11AC_VHT40:
        case MODE_11AC_VHT80:
#if RC_SUPPORT_1D_RATECTRL
            if (g_use_2d_ratectrl) {
#endif
                for (nss_idx = 0; nss_idx < NUM_SPATIAL_STREAM; ++nss_idx) {
                    pRc->u.tD.rateMax[0][nss_idx] = VHT_20_RATE_TABLE_INDEX +
                        nss_idx * NUM_VHT_MCS_PER_NSS + INITIAL_VHT_MCS;

                    pRc->u.tD.rateMax[1][nss_idx] = VHT_40_RATE_TABLE_INDEX +
                        nss_idx * NUM_VHT_MCS_PER_NSS + INITIAL_VHT_MCS;

                    pRc->u.tD.rateMax[2][nss_idx] = VHT_80_RATE_TABLE_INDEX +
                        nss_idx * NUM_VHT_MCS_PER_NSS + INITIAL_VHT_MCS;
                }
#if RC_SUPPORT_1D_RATECTRL
            } else {
                pRc->u.oD.rateMax[0] = RT_GET_INIT_MAXRATE(pRateTable, MODE_11AC_VHT20);
                pRc->u.oD.rateMax[1] = RT_GET_INIT_MAXRATE(pRateTable, MODE_11AC_VHT40);
                pRc->u.oD.rateMax[2] = RT_GET_INIT_MAXRATE(pRateTable, MODE_11AC_VHT80);
            }
#endif
            break;
        default:
            /* Legacy modes (11A, 11B, 11G) */
            if(pSib->peer_params.phymode < MODE_MAX) {
#if RC_SUPPORT_1D_RATECTRL
                if (g_use_2d_ratectrl) {
#endif
                    pRc->u.tD.rateMax[0][0] =
                                RT_GET_INIT_MAXRATE(pRateTable, pSib->peer_params.phymode);
#if RC_SUPPORT_1D_RATECTRL
                } else {
                    pRc->u.oD.rateMax[0] =
                            RT_GET_INIT_MAXRATE(pRateTable, pSib->peer_params.phymode);
                }
#endif
            }
            else {
               A_ASSERT(0);
            }
            break;
            
    }

    /* validate rate max which may not be valid as per current rate table */
    _rc_validate_rateMax(pRateTable, g_pRATE, pSib);

#if RC_SUPPORT_1D_RATECTRL
    if (g_use_2d_ratectrl) {
#endif
        pRc->u.tD.bestRate[0] = pRc->u.tD.rateMax[0][0];
        pRc->u.tD.bestRate[1] = pRc->u.tD.rateMax[1][0];
        pRc->u.tD.bestRate[2] = pRc->u.tD.rateMax[2][0];
#if RC_SUPPORT_1D_RATECTRL
    }
#endif

#if RC_USE_CACHED_RATES
#if RC_SUPPORT_1D_RATECTRL
    if (g_use_2d_ratectrl) {
#endif
        for (i = 0; i < NUM_DYN_BW; ++i) {
            pRc->u.tD.cachedRateInfo[i].rix = RT_INVALID_INDEX;
        }
#if RC_SUPPORT_1D_RATECTRL
    }
#endif
#endif

    /* Set htSgiValid so that ratectrl can decide whether to use SGI */
    pRc->htSgiValid = 0;

    /* Update the sgiMask. For now, SGI is enabled only for MCS (8*n - 1) in HT mode and
     * MCS (8*n - 1), (9*n - 1) and (10*n - 1) in VHT mode, where n is the nss. */

    if( pSib->peer_params.ni_flags & RC_PEER_HT ) {
        RATE_SetHTConnCap( pSib, pSib->peer_params.ht_caps );
    }

    if( pSib->peer_params.ni_flags & RC_PEER_VHT ) {
        RATE_SetVHTConnCap( pSib, pSib->peer_params.vht_caps );
    }

#if 0
    DBGLOG_RECORD_LOG(WLAN_MODULE_RATECTRL, -1,
        RATECTRL_DBGID_ASSOC, DBGLOG_ERR, 6,
        0xdecafe,  g_pRATE->sgiMask[0], g_pRATE->sgiMask[1],
        pSib->peer_params.ht_caps, pSib->peer_params.vht_caps, pSib->peer_params.phymode);
#endif

}



#ifdef ENABLE_RSSI_BASED_RATECTRL
/*
 * Return the median of three numbers
 */
static INLINE A_RSSI
median(A_RSSI a, A_RSSI b, A_RSSI c)
{
    if (a >= b) {
        if (b >= c) {
            return b;
        } else if (a > c) {
            return c;
        } else {
            return a;
        }
    } else {
        if (a >= c) {
            return a;
        } else if (b >= c) {
            return c;
        } else {
            return b;
        }
    }
}
#endif /* ENABLE_RSSI_BASED_RATECTRL */

#if 0
/* reads the ccount register (cpu ticks) and returns value */
static __inline__ int read_ccount()
{
    unsigned int ccount;
    __asm__ __volatile__ (
    "rsr %0, ccount"
    : "=a" (ccount) : : "memory"
    );
    return ccount;
}
#endif

/*
    _GetBestRate currently only works for passed vMask which would be either 
    for VHT or non-VHT (11n/erp ) rates
    make it more clean
    TODO

*/

/* finds the rate with the best thru-put given an allowed rate mask a rate table 
 * and a RateCtrl object for the receiver. */
//LOCAL
A_UINT8 _GetBestRate(RATE_CONTEXT *g_pRATE, RC_MASK_INFO_t *rc_mask_info,
            const WHAL_RATE_TABLE *pRateTable, 
            struct TxRateCtrl_s  *pRc, A_RSSI rssiLast,
            A_UINT8 forced_max_rix)
{
        A_INT16 index;
        A_UINT32 bestThruput,thisThruput;
        A_UINT8 bestRate, minRate, maxRate;
        
        bestThruput = 0;
        bestRate    = 0;

        RT_GET_RIX_LIMITS_4_MASK(&maxRate,&minRate,rc_mask_info->idx);

        for (index = maxRate ; index >= minRate ; index--) {                
            
            /* Skip invalid rates */
            if (!RATEMASK_IS_VALID(rc_mask_info->rc_mask, (index - minRate))){
                continue;
            }                                        
    
            if (RT_GET_RAW_KBPS(pRateTable, index) >
                   RT_GET_RAW_KBPS(pRateTable, forced_max_rix)) {
                continue;
            }
            
#ifdef ENABLE_RSSI_BASED_RATECTRL
            if (not_per_only() &&
                rssiLast < pRc->state[index].rssiThres) {
                continue;
            }
#endif /* ENABLE_RSSI_BASED_RATECTRL */
    
            thisThruput = (100-pRc->state[index].per) * 
                    RT_GET_USER_KBPS(pRateTable, index);                
            
            if (bestThruput <= thisThruput) {
                bestThruput = thisThruput;
                bestRate    = index;            
            }
            
        }

        A_ASSERT(bestThruput != 0);
        
        return bestRate;
        
}

A_UINT32 g_nss_hysteresis = 110;
A_UINT32 g_mcs_hysteresis = 100;
A_UINT32 g_scaled_nss_hysteresis = 0;
A_UINT32 g_scaled_mcs_hysteresis = 0;

/*
    _GetBestRate_2D currently only works for passed vMask which would be either 
    for VHT or non-VHT (11n/erp ) rates
    make it more clean
    TODO

*/

/* finds the rate with the best thru-put given an allowed rate mask a rate table 
 * and a RateCtrl object for the receiver. */
//LOCAL
A_UINT8 _GetBestRate_2D(RATE_CONTEXT *g_pRATE, RC_MASK_INFO_t *rc_mask_info,
            const WHAL_RATE_TABLE *pRateTable, 
            struct TxRateCtrl_s  *pRc, A_UINT8 bw, A_UINT8 pastRate)
{
        A_INT16 index;
        A_UINT32 thisThruput;
        A_UINT8 minRate, maxRate;
        A_UINT8 bestRate[NUM_SPATIAL_STREAM] = { 0 };
        A_UINT32 bestThruput[NUM_SPATIAL_STREAM] = { 0 };
        A_UINT8 selectedRate;

#if RC_USE_CACHED_RATES
        if (pRc->u.tD.cachedRateInfo[bw].rix != RT_INVALID_INDEX &&
            pRc->u.tD.cachedRateInfo[bw].rc_mask == rc_mask_info->rc_mask)
        {
            return pRc->u.tD.cachedRateInfo[bw].rix;
        }
#endif

        RT_GET_RIX_LIMITS_4_MASK(&maxRate,&minRate,rc_mask_info->idx);

        if (RT_IS_HT_INDEX(maxRate)) {
            A_UINT8 pastNssIdx = rc_get_nss_idx_from_rix(pRateTable, pastRate);
            A_INT8 mcs, nss, max_mcs;
            A_UINT8 bestNssIdx = 0;

            max_mcs = rc_get_num_mcs_from_idx(rc_mask_info->idx) - 1;
            index = maxRate;

            for (nss = NUM_SPATIAL_STREAM - 1; nss >= 0; --nss) {
                mcs = max_mcs - (index - pRc->u.tD.rateMax[(A_INT32)bw][(A_INT32)nss]);
                index = pRc->u.tD.rateMax[(A_INT32)bw][(A_INT32)nss];

                for (; mcs >= 0; --mcs, --index) {
                    if (!RATEMASK_IS_VALID(rc_mask_info->rc_mask, (index - minRate))) {
                        continue;
                    }

                    if (100 * RT_GET_USER_KBPS(pRateTable, index) < bestThruput[(A_INT32)nss]) {
                        /*
                         * This MCS cannot match best throughput at 0% PER.
                         * Skip the rest of this NSS.
                         */
                        index -= mcs + 1;
                        break;
                    }

                    thisThruput = (100 - pRc->state[index].per) *
                            RT_GET_USER_KBPS(pRateTable, index);

                    if (bestThruput[(A_INT32)nss] <= thisThruput) {
                        bestThruput[(A_INT32)nss] = thisThruput;
                        bestRate[(A_INT32)nss]    = index;
                        if (bestThruput[(A_INT32)nss] >= bestThruput[(A_INT32)bestNssIdx]) {
                            bestNssIdx = nss;
                        }
                    }
                }
            }

            if (bestThruput[(A_INT32)bestNssIdx] == 0) {
                /*
                 * Ensure that lowest NSS, lowest MCS is selected
                 * if the best rate has a throughput of 0.
                 */
                A_UINT8 *pValidRate = rc_get_valid_rates_2d(pRc, rc_mask_info->idx, 0);
                selectedRate = pValidRate[0];
            } else if (bestRate[bestNssIdx] == pastRate) {
                /* no change, don't run hysteresis calculations */
                selectedRate = pastRate;
            } else if (bestThruput[bestNssIdx] <= (bestThruput[pastNssIdx] >> 7) * g_scaled_nss_hysteresis) {
                /* new nss not good enough, check mcs */
                A_UINT32 pastRateThruput = (100 - pRc->state[pastRate].per) * RT_GET_USER_KBPS(pRateTable, pastRate);
                if (bestThruput[pastNssIdx] > (pastRateThruput >> 7) * g_scaled_mcs_hysteresis) {
                    selectedRate = bestRate[pastNssIdx];
                } else {
                    selectedRate = pastRate;
                }
            } else {
                /* best nss, best mcs */
                selectedRate = bestRate[bestNssIdx];
            }
        } else {
            /* CCK / OFDM rate */

            for (index = maxRate ; index >= minRate ; index--) {                
                /* Skip invalid rates */
                if (!RATEMASK_IS_VALID(rc_mask_info->rc_mask, (index - minRate))) {
                    continue;
                }
    
                if (RT_GET_RAW_KBPS(pRateTable, index) >
                       RT_GET_RAW_KBPS(pRateTable, pRc->u.tD.rateMax[bw][0])) {
                    continue;
                }

                thisThruput = (100 - pRc->state[index].per) *
                    RT_GET_USER_KBPS(pRateTable, index);

                if (bestThruput[0] <= thisThruput) {
                    bestThruput[0] = thisThruput;
                    bestRate[0]    = index;
                }
            }

            selectedRate = bestRate[0];
        }

#if RC_USE_CACHED_RATES
        pRc->u.tD.cachedRateInfo[bw].rix = selectedRate;
        pRc->u.tD.cachedRateInfo[bw].rc_mask = rc_mask_info->rc_mask;
#endif

        return selectedRate;
}

/*
 * Return a rate faster than a provided minimum for a
 * particular nss.
 */
A_UINT8 _rcFindAltNssRate_2D(const WHAL_RATE_TABLE *pRateTable,
        struct TxRateCtrl_s *pRc, RC_MASK_INFO_t *rc_mask_info, 
        A_UINT8 nss_idx, A_UINT32 min_rate_kbps)
{
    A_UINT8     i,j;
    A_UINT8 num_rix;
    A_UINT8 upper, lower;
    A_UINT8 foundRate = RT_INVALID_INDEX;
    A_UINT8 *pValidRate;

    num_rix = pRc->u.tD.maxValidRate[rc_mask_info->idx][nss_idx];
    RT_GET_RIX_LIMITS_4_MASK(&upper, &lower, rc_mask_info->idx);

    pValidRate = rc_get_valid_rates_2d(pRc, rc_mask_info->idx, nss_idx);

    for (i = 0; i < num_rix; i++) {
        j = pValidRate[i];

        if (RATEMASK_IS_VALID(rc_mask_info->rc_mask, (j - lower))){
            if (100 * RT_GET_USER_KBPS(pRateTable, j) > min_rate_kbps) {
                foundRate = j;
                break;
            }
        }
    }

    return foundRate;
}

#if RC_SUPPORT_1D_RATECTRL

/*
 * Determines and returns the new Tx rate index.
 */
A_UINT16
_rcRateFind(RATE_CONTEXT * g_pRATE, struct rate_node *pSib, A_UINT32 frameLen,
           A_BOOL isLowest, RC_MASK_INFO_t *rc_mask_info, A_UINT8 *probe_rix, A_UINT32 nowMsec)
{
    if (g_use_2d_ratectrl) {
        return rcRateFind_2D(g_pRATE, pSib, frameLen, isLowest, rc_mask_info, probe_rix, nowMsec);
    } else {
        return rcRateFind_1D(g_pRATE, pSib, frameLen, isLowest, rc_mask_info, probe_rix, nowMsec);
    }
}

#endif

/*
 * Determines and returns the new Tx rate index.
 */
#if RC_SUPPORT_1D_RATECTRL
A_UINT16
_rcRateFind_2D(RATE_CONTEXT * g_pRATE, struct rate_node *pSib, A_UINT32 frameLen,
           A_BOOL isLowest, RC_MASK_INFO_t *rc_mask_info, A_UINT8 *probe_rix, A_UINT32 nowMsec)
#else
A_UINT16
_rcRateFind(RATE_CONTEXT * g_pRATE, struct rate_node *pSib, A_UINT32 frameLen,
           A_BOOL isLowest, RC_MASK_INFO_t *rc_mask_info, A_UINT8 *probe_rix, A_UINT32 nowMsec)
#endif
{
    const WHAL_RATE_TABLE     *pRateTable  = g_pRATE->sc_currates;
    struct TxRateCtrl_s  *pRc;
    A_UINT8              rate, nextRate;
    A_INT16              index;
    A_UINT8              nss_idx, old_nss_idx;
    A_UINT32             minRateKbps = (A_UINT32)0xffffffff;
    A_RATEMASK           vMask;
    A_ASSERT(pSib);    

    /* have the real rate control logic kick in */
    pRc = pSib->txRateCtrl;
    
    if (isLowest) {
        /* Find the lowest rate */
        nextRate = 0;
        vMask = g_pRATE->sc_fixRateSet[WHAL_RC_MASK_IDX_NON_HT];
        vMask &= pRc->validTxRateMask[WHAL_RC_MASK_IDX_NON_HT];            

        /* There should be no case, ofcourse except some craziness, where
                   there is no OFDM/CCK rate enabled
               */
        A_ASSERT(vMask);
        
        for (index = 0; RT_IS_OFDM_CCK_INDEX(index); index++) {

            /* skip unsupported rates */            
            if (!RATEMASK_IS_VALID(vMask, index)) {
                continue;
            }

            rate = index;
            if (minRateKbps > RT_GET_RAW_KBPS(pRateTable, rate)) {
                nextRate = rate;
                minRateKbps = RT_GET_RAW_KBPS(pRateTable, rate);
            }       
        }
        return nextRate;
    }

    if(rc_mask_info->rc_mask == (A_RATEMASK)0) {
        /* Update the rate mask when it's not specified */
        _rc_get_peer_valid_rc_mask(g_pRATE, pSib, rc_mask_info);
    }
  
    A_ASSERT(rc_mask_info->rc_mask);

    index = rc_get_rate_bw_idx(rc_mask_info->idx);

    rate = GetBestRate_2D(g_pRATE, rc_mask_info, pRateTable, pRc, index, pRc->u.tD.bestRate[index]);

    old_nss_idx = rc_get_nss_idx_from_rix(pRateTable, pRc->u.tD.bestRate[index]);
    nss_idx = rc_get_nss_idx_from_rix(pRateTable, rate);

    if (nss_idx != old_nss_idx) {
        /* nss switch, update probe periods */
        pRc->u.tD.probePeriod[index][old_nss_idx] = RC_PROBE_PERIOD_2D_ALTNSS_MIN;
        pRc->u.tD.probePeriod[index][nss_idx] = RC_PROBE_PERIOD_2D_CURNSS;
    }

    pRc->u.tD.bestRate[index] = rate;

    if (pRc->hwMaxRetryPktCnt[index] < 4) {
        /* no probing on any nss */
        return rate;
    }

    /* probe current nss? */
    if (nowMsec > pRc->u.tD.probeTime[index][nss_idx] + 
        pRc->u.tD.probePeriod[index][nss_idx]) {

        if (rcGetNextValidTxRate(pRateTable,
              pRc, rc_mask_info, rate, &nextRate)) {

            pRc->probeRate[index] = (A_UINT8)nextRate;
            pRc->u.tD.probeTime[index][nss_idx] = nowMsec;
            pRc->hwMaxRetryPktCnt[index] = 0;
    
            *probe_rix = nextRate;
        } else {
            if (IS_PHYMODE_11N2G(pSib->peer_params.phymode) && 
                    (rc_mask_info->idx == WHAL_RC_MASK_IDX_NON_HT)) {

                A_UINT8 lower_rix, upper_rix, i;
                A_UINT8 *pValidRate;

                /* we are at the highest CCK rate and HT association,
                   try switching to HT MCS */

                pValidRate = rc_get_valid_rates_2d(pRc, WHAL_RC_MASK_IDX_HT_20, 0);
                *probe_rix = pRc->probeRate[index] = pValidRate[0];

                pRc->u.tD.probeTime[index][0] = nowMsec;
                pRc->hwMaxRetryPktCnt[index] = 0;
                /* age out existing per since we have not used that a while
                   also we are going to start with anyway lowest MCS
                */
                RT_GET_RIX_LIMITS_4_MASK(&upper_rix, &lower_rix, 
                    WHAL_RC_MASK_IDX_HT_20);

                for (i = lower_rix; i <= upper_rix; i++) {
                   /* Reset PER since rate is just higher than lower bw */
                   pRc->state[i].per = 0;
                }
            } else if (nss_idx + 1 < NUM_SPATIAL_STREAM) {
                /* probe faster on higher NSS */
                pRc->u.tD.probeTime[index][nss_idx + 1] = pRc->u.tD.probeTime[index][nss_idx];
                pRc->u.tD.probePeriod[index][nss_idx + 1] = pRc->u.tD.probePeriod[index][nss_idx];
            }

            /* Couldn't probe (at highest available rate) */
            pRc->u.tD.probeTime[index][nss_idx] = nowMsec;
        }
    }

    if (*probe_rix == RT_INVALID_INDEX &&
        rc_mask_info->idx != WHAL_RC_MASK_IDX_NON_HT)
    {
        A_UINT32 minProbeTime = nowMsec;
        A_UINT8 probeNssIdx = 0;
        A_INT8 i;

        /* alternate probe if not probing on current nss */
        for (i = nss_idx - 1; i < NUM_SPATIAL_STREAM; ++i) {
            if (i < 0 || i == nss_idx) {
                continue;
            }

            if (nowMsec > pRc->u.tD.probeTime[index][(A_INT32)i] +
                pRc->u.tD.probePeriod[index][(A_INT32)i] && 
                pRc->u.tD.probeTime[index][(A_INT32)i] < minProbeTime)
            {
                A_UINT32 minimumRate = ((100 - pRc->state[rate].per) * 
                    RT_GET_USER_KBPS(pRateTable, rate) >> 7) * g_scaled_nss_hysteresis;

                nextRate = _rcFindAltNssRate_2D(pRateTable, pRc, rc_mask_info, i, minimumRate);

                if (nextRate != RT_INVALID_INDEX) {
                    minProbeTime = pRc->u.tD.probeTime[index][(A_INT32)i];
                    *probe_rix = nextRate;
                    probeNssIdx = i;
                } else {
                    /* couldn't find a good rate, delay probe */
                    pRc->u.tD.probeTime[index][(A_INT32)i] = nowMsec;
                }
            }
        }

        if (*probe_rix != RT_INVALID_INDEX) {
            pRc->probeRate[index] = *probe_rix;
            pRc->u.tD.probeTime[index][probeNssIdx] = nowMsec;
            pRc->hwMaxRetryPktCnt[index] = 0;
        }
    }

    return rate;
}

#if RC_SUPPORT_1D_RATECTRL

/*
 * Determines and returns the new Tx rate index.
 */
A_UINT16
_rcRateFind_1D(RATE_CONTEXT * g_pRATE, struct rate_node *pSib, A_UINT32 frameLen,
           A_BOOL isLowest, RC_MASK_INFO_t *rc_mask_info, A_UINT8 *probe_rix, A_UINT32 nowMsec)
{
    const WHAL_RATE_TABLE     *pRateTable  = g_pRATE->sc_currates;
    struct TxRateCtrl_s  *pRc;
#ifdef ENABLE_RSSI_BASED_RATECTRL
    A_UINT32             dt;
#endif /* ENABLE_RSSI_BASED_RATECTRL */
    A_UINT8              rate, nextRate;
    A_RSSI               rssiLast=0;
#ifdef ENABLE_RSSI_BASED_RATECTRL
    A_RSSI               rssiReduce;
#endif /* ENABLE_RSSI_BASED_RATECTRL */
    A_INT16              index;

    A_UINT32             minRateKbps = (A_UINT32)0xffffffff;
    A_RATEMASK           vMask;
    A_ASSERT(pSib);    

    /* have the real rate control logic kick in */
    pRc = pSib->txRateCtrl;
    
    if (isLowest) {
        /* Find the lowest rate */
        nextRate = 0;
        vMask = g_pRATE->sc_fixRateSet[WHAL_RC_MASK_IDX_NON_HT];
        vMask &= pRc->validTxRateMask[WHAL_RC_MASK_IDX_NON_HT];            

        /* There should be no case, ofcourse except some craziness, where
                   there is no OFDM/CCK rate enabled
               */
        A_ASSERT(vMask);
        
        for (index = 0; RT_IS_OFDM_CCK_INDEX(index); index++) {

            /* skip unsupported rates */            
            if (!RATEMASK_IS_VALID(vMask, index)) {
                continue;
            }

            rate = index;
            if (minRateKbps > RT_GET_RAW_KBPS(pRateTable, rate)) {
                nextRate = rate;
                minRateKbps = RT_GET_RAW_KBPS(pRateTable, rate);
            }       
        }
        return nextRate;
    }

#ifdef ENABLE_RSSI_BASED_RATECTRL
    if (pRc->rssiLastPrev || pRc->rssiLastPrev2) {
        /* Find the best rate */
        rssiLast   = median(pRc->rssiLast, pRc->rssiLastPrev, pRc->rssiLastPrev2);
    } else {
        rssiLast = pRc->rssiLast;
    }
    rssiReduce = 0;

    /*
     * Age (reduce) last ack rssi based on how old it is.
     * The bizarre numbers are so the delta is 160msec,
     * meaning we divide by 16.
     *   0msec   <= dt <= 25msec:   don't derate
     *   25msec  <= dt <= 185msec:  derate linearly from 0 to 10dB
     *   185msec <= dt:             derate by 10dB
     */

    /*
            These numbers and associated computations sound interesting.
            Do they need some tuning for 11ac?
            REVISIT
        */
    dt = nowMsec - pRc->rssiTime;

    if (dt >= 185) {
        rssiReduce = 10;
    } else if (dt >= 25) {
        rssiReduce = (A_UINT8)((dt - 25) >> 4);
    }
 
    /* Reduce rssi for long packets */
    if (frameLen > 800) {
        rssiReduce += 1;    /* need 1 more dB for packets > 800 bytes */
    }

    /* Now reduce rssiLast by rssiReduce */
    if (rssiLast < rssiReduce) {
        rssiLast = 0;
    } else {
        rssiLast -= rssiReduce;
    }
#endif /* ENABLE_RSSI_BASED_RATECTRL */

    /*
     * Now look up the rate in the rssi table and return it.
     * If no rates match then we return 0 (lowest rate)
     */

    if(rc_mask_info->rc_mask == (A_RATEMASK)0) {
        /* Update the rate mask when it's not specified */
        _rc_get_peer_valid_rc_mask(g_pRATE, pSib, rc_mask_info);
    }
  
    A_ASSERT(rc_mask_info->rc_mask);

    index = rc_get_rate_bw_idx(rc_mask_info->idx);

    rate = GetBestRate(g_pRATE, rc_mask_info, pRateTable, pRc, rssiLast,
              pRc->u.oD.rateMax[index]);   
 
#ifdef ENABLE_RSSI_BASED_RATECTRL
    pRc->rssiLastLkup = rssiLast;
#endif /* ENABLE_RSSI_BASED_RATECTRL */

    /*
     * Must check the actual rate (rateKbps) to account for non-monoticity of
     * 11g's rate table
     */
    {
        /*
         * Always probe the next rate in the rate Table (ignoring monotonicity).
         * Reason:  If OFDM is broken, when rateMax = 5.5, it will probe
         *          11 Mbps first.
         */
        if (((pRc->hwMaxRetryPktCnt[index] >= 4) 
            || (rate == pRc->u.oD.validRateIndex[rc_mask_info->idx][0])) &&
            (nowMsec - pRc->u.oD.probeTime[index] >
            RT_GET_PROBE_PERIOD(pRateTable, rate))) {

            if (rcGetNextValidTxRate(pRateTable,
                  pRc, rc_mask_info, rate, &nextRate)) {

                pRc->probeRate[index] = (A_UINT8)nextRate;
                pRc->u.oD.probeTime[index] = nowMsec;
                pRc->hwMaxRetryPktCnt[index] = 0;
        
                *probe_rix = nextRate;
            } 
            else if (IS_PHYMODE_11N2G(pSib->peer_params.phymode) && 
                    (rc_mask_info->idx == WHAL_RC_MASK_IDX_NON_HT)) {

                A_UINT8 lower_rix, upper_rix, i;

                /* we are at the highest CCK rate and HT association,
                   try switching to HT MCS */
                *probe_rix = pRc->probeRate[index] = 
                    pRc->u.oD.validRateIndex[WHAL_RC_MASK_IDX_HT_20][0];

                pRc->u.oD.probeTime[index] = nowMsec;
                pRc->hwMaxRetryPktCnt[index] = 0;
                /* age out existing per since we have not used that a while
                   also we are going to start with anyway lowest MCS
                */
                RT_GET_RIX_LIMITS_4_MASK(&upper_rix, &lower_rix, 
                    WHAL_RC_MASK_IDX_HT_20);

                for (i = lower_rix; i <= upper_rix; i++) {
                   /* Reset PER since rate is just higher than lower bw */
                   pRc->state[i].per = 0;
#ifdef ENABLE_RSSI_BASED_RATECTRL
                   pRc->state[i].rssiThres = 0;
#endif /* ENABLE_RSSI_BASED_RATECTRL */
                }
            }

        }
    }

    return rate;
}

#endif


/*
 * _g_dbg_rc_weight is currently used to cap the maximum weight in case of
   excessive retries. The idea is to remove this after some fine tuning further
*/

A_UINT32 _g_dbg_rc_weight = 80;

//#define RATECONTROL_DYNAMIC_BW_DEBUG 1

#ifdef RATECONTROL_DYNAMIC_BW_DEBUG
static A_UINT32 g_dbg_rc_err_inject = 0;
static void rc_dbg_dyn_bw_err_inj(A_UINT32 bw, A_UINT8 *mpdu_failed,
     A_UINT8 *mpdu_tried, A_UINT32 *flags)
{
    A_UINT32 err = (g_dbg_rc_err_inject >> (bw << 3)) & 0xff;
    if (!err)
        return;

    if (err == 100 )
       *flags |= WHAL_RC_TXDONE_X_RETRIES;
    else 
       *mpdu_failed = (*mpdu_tried * err ) >> 7; /* /128) */
}
#endif

static void
_rcDecreaseRateMax(const WHAL_RATE_TABLE *pRateTable, struct TxRateCtrl_s *pRc,
    struct rate_node *pSib, RC_MASK_INFO_t *rc_mask_info, A_UINT8 txRate,
    A_UINT8 bw, A_UINT8 nss_idx)
{
    A_UINT8 ret;

    ret = rcGetNextLowerValidTxRate(pRateTable, rc_mask_info,
        pRc, txRate, &pRc->u.tD.rateMax[bw][nss_idx]);

    if (ret == RT_INVAL_IDX) {
        /* can't decrease rateMax anymore. */
        if (nss_idx == 0) {
            /*
             * Using lowest HT/VHT rate, drop to CCK rates
             * if possible.
             */
            if (g_rc_cck_rate_allowed &&
                (IS_PHYMODE_11N2G(pSib->peer_params.phymode)) && 
                (rc_mask_info->idx == WHAL_RC_MASK_IDX_HT_20)) {
           
                /* switch to CCK mode */
                pRc->u.tD.rateMax[0][0] = CCK_RATE_TABLE_INDEX + 2; /* 2 mbps */
                pRc->u.tD.bestRate[0] = pRc->u.tD.rateMax[0][0];
            }
        }

        return;
    }

    /* Ensure ratemax monotonicity for HT/VHT */
    if (RT_IS_HT_INDEX(txRate)) {
        A_UINT8 k;
        A_UINT8 maxAllowedMcs;

        maxAllowedMcs = rc_get_mcs_from_rix(pRateTable, pRc->u.tD.rateMax[bw][nss_idx]);

        for (k = nss_idx + 1; k < NUM_SPATIAL_STREAM; ++k) {
            if (rc_get_mcs_from_rix(pRateTable, pRc->u.tD.rateMax[bw][k]) > 
                maxAllowedMcs)
            {
                A_UINT8 res;

                if (rcGetValidTxRateMaxMcs(pRateTable, pRc, rc_mask_info, k,
                    maxAllowedMcs, &res))
                {
                    pRc->u.tD.rateMax[bw][k] = res;
                }
            }
        }
    }
}

static void
_rcIncreaseRateMax(const WHAL_RATE_TABLE *pRateTable, struct TxRateCtrl_s *pRc,
    struct rate_node *pSib, RC_MASK_INFO_t *rc_mask_info, A_UINT8 txRate,
    A_UINT8 bw, A_UINT8 nss_idx)
{
    if (g_rc_cck_rate_allowed &&
        (IS_PHYMODE_11N2G(pSib->peer_params.phymode)) && 
        (rc_mask_info->idx == WHAL_RC_MASK_IDX_HT_20) &&
        (!RT_IS_HT_INDEX(pRc->u.tD.rateMax[bw][nss_idx])))
    {
        /* switch from CCK mode to HT */
        pRc->u.tD.bestRate[0] = txRate;
    }

    pRc->u.tD.rateMax[bw][nss_idx] = txRate;

    /* Ensure monotonicity of ratemax for HT/VHT */
    if (RT_IS_HT_INDEX(txRate)) {
        A_UINT8 k;
        A_UINT8 maxAllowedMcs = rc_get_mcs_from_rix(pRateTable, pRc->u.tD.rateMax[bw][nss_idx]);

        for (k = 0; k < nss_idx; ++k) {
            if (rc_get_mcs_from_rix(pRateTable, pRc->u.tD.rateMax[bw][k]) < 
                maxAllowedMcs)
            {
                A_UINT8 res;

                if (rcGetValidTxRateMaxMcs(pRateTable, pRc, rc_mask_info,
                    k, maxAllowedMcs, &res))
                {
                    pRc->u.tD.rateMax[bw][k] = res;
                }
            }
        }
    }
}

#if RC_SUPPORT_1D_RATECTRL

void _rcUpdate_HT (RATE_CONTEXT *g_pRATE, struct rate_node *pSib,
        RC_TX_RATE_SCHEDULE *rate_sched, RC_TX_DONE_PARAMS *args,
        A_UINT8 probe_aborted)
{
    if (g_use_2d_ratectrl) {
        rcUpdate_HT_2D(g_pRATE, pSib, rate_sched, args, probe_aborted);
    } else {
        rcUpdate_HT_1D(g_pRATE, pSib, rate_sched, args, probe_aborted);
    }
}

#endif

#if RC_SUPPORT_1D_RATECTRL
void _rcUpdate_HT_2D (RATE_CONTEXT *g_pRATE, struct rate_node *pSib,
        RC_TX_RATE_SCHEDULE *rate_sched, RC_TX_DONE_PARAMS *args,
        A_UINT8 probe_aborted)
#else
void _rcUpdate_HT (RATE_CONTEXT *g_pRATE, struct rate_node *pSib,
        RC_TX_RATE_SCHEDULE *rate_sched, RC_TX_DONE_PARAMS *args,
        A_UINT8 probe_aborted)
#endif
{
    const WHAL_RATE_TABLE *pRateTable;
    struct TxRateCtrl_s *pRc;
    A_UINT32            nowMsec     = 0; 
    A_UINT8             txRate;
    A_RSSI rssiAck;
    A_UINT8 nFrames, retries, nBad;
    A_RATEMASK rMask;
    A_UINT32 rMaskPos, rateBit;
    A_UINT8 idx;
    A_UINT8 sel_nss_idx;
    A_UINT8 nss_idx;
    A_UINT8 ratePer;

   pRateTable = g_pRATE->sc_currates;
   pRc        = pSib->txRateCtrl;

   if(probe_aborted == 1) { /* args passed in would be null if this is true. */
        goto done;
   }

    /*
        Don't let the function change statistics if the rate schedule
        of this ppdu was not determined through rate control 
    */
    rssiAck = args->ack_rssi;
    nFrames = args->num_enqued;
    retries = args->num_retries;
    nBad    = args->num_failed;

    nowMsec = args->time_stamp;

    /* Silently return if we reach here in case of a filtered frame. */
    if( retries == 0 ) {
        goto done;
    }

    A_ASSERT(pRateTable);
    txRate     = RT_WHALCODE_TO_INDEX(pRateTable, args->ptx_rc);

#if 0 //ATH_TARGET
    if (!(pSib->peer_params.ni_flags & RC_PEER_AUTH) ||
        (RT_IS_OFDM_CCK_INDEX(txRate) && 
        (pSib->peer_params.ni_flags & (RC_PEER_HT | RC_PEER_VHT)))) {
        /* called when association is not present or legacy frame but HT 
           /VHT association Ideally we should assert here but given too many
           aserts just send a warning message for now
        */
        DBGLOG_RECORD_LOG(WLAN_MODULE_RATECTRL, -1,
            RATECTRL_DBGID_UNEXPECTED_FRAME, DBGLOG_ERR, 2,
            txRate, pSib->peer_params.ni_flags);
        return; 
    }
#endif

    A_ASSERT(txRate < pRc->rateTableSize);
    ratePer = pRc->state[txRate].per;
    
    /*  get apropriate rate mask to validate index */
    if (IS_PHYMODE_11N2G(pSib->peer_params.phymode) &&  /* 2G HT */
         !RT_IS_HT_INDEX(pRc->u.tD.rateMax[0][0]) &&    /* CCK MODE */
          RT_IS_HT_INDEX(txRate) && /* HT PPDU Tx Completion */
          pRc->probeRate[0] != txRate) { /* Not HT Probe PPDU Tx */
        /* ignore HT 2G ppdus after switching to CCK mode */
        goto done;
    }

    RT_GET_RC_MASK_4_RIX((void *)pRateTable, txRate, &rMaskPos,&rateBit);
    rMask = pRc->validTxRateMask[rMaskPos];
  
    /* If txRate is not in valid rate range, don't let it go into our update module.
       This is becuase NUll data packet might use basic rate but its not included
       in TxRateMask. It will cause we stuck in the basic rate */
    if(!RATEMASK_IS_VALID(rMask, rateBit)) {
        goto done;
    }
  
    idx = rc_get_rate_bw_idx(rMaskPos);
    nss_idx = rc_get_nss_idx_from_rix(pRateTable, txRate);
    sel_nss_idx = rc_get_nss_idx_from_rix(pRateTable, pRc->u.tD.bestRate[idx]);

#ifdef RATECONTROL_DYNAMIC_BW_DEBUG
    rc_dbg_dyn_bw_err_inj(idx, &nBad, &nFrames, &args->flags); 
#endif

    /* 40Mhz rssi affect borrowed from Fusion code base */

/* TODO
    Don't know history --need to check-- however, this does not sound 
    practical  when ACK was received with diffferent rate/tx power 
    For now only add for 80MHz bandwidth since 160 is still not there
 */
    
    if (args->ptx_rc.flags & WHAL_RC_FLAG_80MHZ) {
        rssiAck = rssiAck < 6? 0: rssiAck - 6;
    } else if (args->ptx_rc.flags & WHAL_RC_FLAG_40MHZ) {
        rssiAck = rssiAck < 3? 0: rssiAck - 3;
    }
    
    if (args->flags & WHAL_RC_TXDONE_X_RETRIES) {
        /* Update the PER. */

        /* first check if this was bw probe which failed */
        if (idx && (pRc->bw_probe_pending & (1 << idx)) &&
                    (txRate == pRc->probeRate[idx])) {
            pRc->probeRate[idx] = RT_INVALID_INDEX;
            /* set all other too but already done at the end */
        }
        else {
            /* invalidate probeRate if it matches current as there may be 
               multiple tx requests submitted */

            if (pRc->probeRate[idx] == txRate) {
                pRc->probeRate[idx] = RT_INVALID_INDEX;

                if (nss_idx != sel_nss_idx) {
                    /* probe on alt nss */
                    pRc->u.tD.rateMax[idx][nss_idx] = A_MIN(pRc->u.tD.rateMax[idx][nss_idx], txRate);
                    pRc->u.tD.probePeriod[idx][nss_idx] =
                        A_MIN(pRc->u.tD.probePeriod[idx][nss_idx] << 1, RC_PROBE_PERIOD_2D_ALTNSS_MAX);

                    pRc->u.tD.probeTime[idx][nss_idx] = nowMsec;

#if RC_USE_CACHED_RATES
                    /* invalidate cached rate for this BW since rateMax may have changed */
                    pRc->u.tD.cachedRateInfo[idx].rix = RT_INVALID_INDEX;
#endif
                } else {
                    pRc->u.tD.probeTime[idx][nss_idx] = nowMsec +
                        pRc->u.tD.probePeriod[idx][nss_idx];
                }
            } else {
                /* The frame was not a probe-frame but since we have had a
                 * complete failure in the tx of the frame, we would want to
                 * enable RTS-CTS for both the series in the next
                 * SW-retry of this frame. */
                if(pRc->rtsForFirstSeries == 0) {
                    pRc->rtsForFirstSeries = 1;
                }
            }

            /* Do not update any PER since no ACK/BA is likely due to 
               interference.
            */
#if ATH_TARGET
            if (g_rc_skip_rts_failure && 
                   (args->flags & WHAL_RC_TXDONE_RTS_ONLY)) {
                goto skip_per_update;
            }
#endif
            /* We shouldn't penalize severely based on number of tx attempts. */
            pRc->u.tD.excessRetries[nss_idx]++;
            if(pRc->u.tD.excessRetries[nss_idx] > _RATE_GetXRetryThr(retries-1) ) {
                pRc->hwMaxRetryPktCnt[idx] = -4;
                ratePer += 30;
                ratePer = A_MIN(ratePer, 100);

                pRc->u.tD.excessRetries[nss_idx] = 0;

            }
        }
    } else {
        /* Update the PER.  Tries below is actual hw retries */
        A_UINT32 tries = (retries)? ( retries -1 ) : retries;

        /* The frame's TX didn't fail completely, so we can resort to not using
         * RTS-CTS for the first series. */
        pRc->rtsForFirstSeries = 0;

        /* ideally, we should never be receiving any update for no tx */
        if (nFrames) {
            A_UINT32 subFramePer = 100 * nBad / nFrames;

            if (IS_RIX_VALID(pRc->probeRate[idx]) && 
                pRc->probeRate[idx] == txRate)
            {
                if (subFramePer < 16) {
                    ratePer = (6 * ratePer + 2 * subFramePer) >> 3;
                } else {
                    ratePer = (6 * ratePer +
                        2 * (tries * 100 + subFramePer) / (tries + 1)) >> 3;
                }
            } else {
                if (subFramePer < 16) {
                    ratePer = (7 * ratePer + subFramePer) >> 3;
                } else {
                    ratePer = (7 * ratePer +
                        (tries * 100 + subFramePer) / (tries + 1)) >> 3;
                }
            }
        }

        pRc->u.tD.excessRetries[nss_idx] = 0;

        pRc->rssiLast      = rssiAck;

        /*
         * If we got at most one retry then increase the max rate if
         * this was a probe.  Otherwise, ignore the probe.
         */

        if (IS_RIX_VALID(pRc->probeRate[idx]) && 
            pRc->probeRate[idx] == txRate) {

#if RC_USE_CACHED_RATES
            /* invalidate cached rate for this BW since rateMax may be updated */
            pRc->u.tD.cachedRateInfo[idx].rix = RT_INVALID_INDEX;
#endif

            if ( retries > 1 || 3 * nBad >= nFrames) { 
                /*
                 * if the attempt worked, but more than half
                 * the subframes were bad then consider
                 * the probe a failure.
                 */
                pRc->probeRate[idx] = RT_INVALID_INDEX;

                if (nss_idx != sel_nss_idx) {
                    pRc->u.tD.rateMax[idx][nss_idx] = A_MIN(pRc->u.tD.rateMax[idx][nss_idx], txRate);
                    pRc->u.tD.probePeriod[idx][nss_idx] =
                        A_MIN(pRc->u.tD.probePeriod[idx][nss_idx] << 1, RC_PROBE_PERIOD_2D_ALTNSS_MAX);

                    pRc->u.tD.probeTime[idx][nss_idx] = nowMsec;
                } else {
                    pRc->u.tD.probeTime[idx][nss_idx] = nowMsec +
                        pRc->u.tD.probePeriod[idx][nss_idx];
                }
            } else {
                RC_MASK_INFO_t rc_mask_info;
                A_UINT32 rMask = pRc->validTxRateMask[rMaskPos];

                rc_mask_info.rc_mask = rMask & g_pRATE->sc_fixRateSet[rMaskPos];
                rc_mask_info.idx = rMaskPos;
                _rc_get_peer_valid_rc_mask(g_pRATE, pSib, &rc_mask_info);

                /* Increase rateMax since the probe was successful */
                _rcIncreaseRateMax(pRateTable, pRc, pSib, &rc_mask_info, txRate, idx, nss_idx);

                if (ratePer > 30) {
                    ratePer = 20;
                }

                pRc->lastRateIndex = pRc->probeRate[idx];
                pRc->probeRate[idx] = RT_INVALID_INDEX;
                /*
                 * Since this probe succeeded, we allow the next probe
                 * twice as soon.  This allows the maxRate to move up
                 * faster if the probes are succesful.
                 */
                if (sel_nss_idx != nss_idx) {
                    pRc->u.tD.probeTime[idx][nss_idx] = RC_PROBE_PERIOD_2D_ALTNSS_MIN;
                }

                pRc->u.tD.probeTime[idx][nss_idx] = nowMsec - 
                    (pRc->u.tD.probePeriod[idx][nss_idx] >> 1); 

                /* if this was bw probe it's sucessful */
//                if (idx && (pRc->bw_probe_pending == idx)) {
                /* TODO: what if regualar 40MHz probe and bw_probe_pending set to 80? */
                if (idx && (pRc->bw_probe_pending & (1 << idx))) {
                    /* wait for higher, if not already */
                    /* set to 80M if currently on 40MHz 
                      (pSib->peer_params.ni_flags & RC_PEER_80MHZ) */
//                    pRc->bw_probe_pending = (idx == 2)?0: idx +1;
                    pRc->bw_probe_pending &= ~(1 << idx);
                    /* Mark the lower bandwidth probe success */
                    if (pRc->bw_probe_pending && (idx == 2)) {
                        A_UINT8 lower_bw = pRc->bw_probe_pending >> 1;
                        pRc->u.tD.rateMax[lower_bw][nss_idx] = pRc->probeRate[lower_bw];
#if RC_USE_CACHED_RATES
                        /* invalidate cached rate for this BW since rateMax may be updated */
                        pRc->u.tD.cachedRateInfo[lower_bw].rix = RT_INVALID_INDEX;
#endif
                        pRc->probeRate[lower_bw] = RT_INVALID_INDEX;

                        if (sel_nss_idx != nss_idx) {
                            pRc->u.tD.probeTime[lower_bw][nss_idx] = 
                                nowMsec - (pRc->u.tD.probePeriod[idx][nss_idx] >> 1);
                        } else {
                            pRc->u.tD.probeTime[lower_bw][nss_idx] = 
                                nowMsec - (pRc->u.tD.probePeriod[idx][nss_idx] >> 1);
                        }

                        pRc->bw_probe_pending = 0;
                    }
                }
            }
        } else {
            /* not probing */
            if (3 * nBad >= nFrames) { 
                pRc->hwMaxRetryPktCnt[idx] = -4;
            } else {
                if (pRc->hwMaxRetryPktCnt[idx] < 8) {
                    pRc->hwMaxRetryPktCnt[idx]++;
                }
            }
        }
    }

    /* Update PER table, ensuring monotonicity */
    if (ratePer != pRc->state[txRate].per) {

#if RC_USE_CACHED_RATES
        /* invalidate cached rate for this BW since PER changed */
        pRc->u.tD.cachedRateInfo[idx].rix = RT_INVALID_INDEX;
#endif
        rcUpdatePer_2D(pRateTable, pRc, txRate, rMaskPos, ratePer);
    }

    /* For all cases */

    /*
     * If this rate looks bad (high PER, historically set to 60 but that seems
       too much now so we have 50%) then stop using it for
     * a while (except if we are probing).
     */
    if (ratePer >= g_rc_rate_max_per_thr &&
        RT_GET_RAW_KBPS(pRateTable, txRate) <= 
            RT_GET_RAW_KBPS(pRateTable, pRc->u.tD.rateMax[idx][nss_idx]))
    {
        RC_MASK_INFO_t rc_mask_info;
        A_UINT32 rMask = pRc->validTxRateMask[rMaskPos];

        rc_mask_info.rc_mask = rMask & g_pRATE->sc_fixRateSet[rMaskPos];
        rc_mask_info.idx = rMaskPos;
        _rc_get_peer_valid_rc_mask(g_pRATE, pSib, &rc_mask_info);

        _rcDecreaseRateMax(pRateTable, pRc, pSib, &rc_mask_info, txRate, idx, nss_idx);

#if RC_USE_CACHED_RATES
        /* invalidate cached rate for this BW since rateMax may have decreased */
        pRc->u.tD.cachedRateInfo[idx].rix = RT_INVALID_INDEX;
#endif
    }

done:

    if (probe_aborted || args->is_probe) {
        A_MEMSET(&pRc->probeRate, RT_INVALID_INDEX, sizeof (pRc->probeRate));
    }

    return;
}

#if RC_SUPPORT_1D_RATECTRL

void _rcUpdate_HT_1D (RATE_CONTEXT *g_pRATE, struct rate_node *pSib,
        RC_TX_RATE_SCHEDULE *rate_sched, RC_TX_DONE_PARAMS *args,
        A_UINT8 probe_aborted)
{
    const WHAL_RATE_TABLE *pRateTable;
    struct TxRateCtrl_s *pRc;
    A_UINT32            nowMsec     = 0; 
#ifdef ENABLE_RSSI_BASED_RATECTRL
    A_BOOL              stateChange = FALSE;
#endif /* ENABLE_RSSI_BASED_RATECTRL */
    A_UINT8             lastPer;
    int                 rate;
    A_UINT8             txRate;
    A_RSSI rssiAck;
    A_UINT8 nFrames, retries, nBad;
    A_RATEMASK rMask;
    A_UINT32 rMaskPos, rateBit;
    A_UINT8 idx;

   pRateTable = g_pRATE->sc_currates;
   pRc        = pSib->txRateCtrl;

   if(probe_aborted == 1) { /* args passed in would be null if this is true. */
        goto done;
   }

    /*
        Don't let the function change statistics if the rate schedule
        of this ppdu was not determined through rate control 
    */
    rssiAck = args->ack_rssi;
    nFrames = args->num_enqued;
    retries = args->num_retries;
    nBad    = args->num_failed;

    nowMsec = args->time_stamp;

    /* Silently return if we reach here in case of a filtered frame. */
    if( retries == 0 ) {
        goto done;
    }

    A_ASSERT(pRateTable);
    txRate     = RT_WHALCODE_TO_INDEX(pRateTable, args->ptx_rc);

#if 0 //ATH_TARGET
    if (!(pSib->peer_params.ni_flags & RC_PEER_AUTH) ||
        (RT_IS_OFDM_CCK_INDEX(txRate) && 
        (pSib->peer_params.ni_flags & (RC_PEER_HT | RC_PEER_VHT)))) {
        /* called when association is not present or legacy frame but HT 
           /VHT association Ideally we should assert here but given too many
           aserts just send a warning message for now
        */
        DBGLOG_RECORD_LOG(WLAN_MODULE_RATECTRL, -1,
            RATECTRL_DBGID_UNEXPECTED_FRAME, DBGLOG_ERR, 2,
            txRate, pSib->peer_params.ni_flags);
        return; 
    }
#endif

    A_ASSERT(txRate < pRc->rateTableSize);
    
    lastPer = pRc->state[txRate].per;


    /*  get apropriate rate mask to validate index */
    if (IS_PHYMODE_11N2G(pSib->peer_params.phymode) &&  /* 2G HT */
         !RT_IS_HT_INDEX(pRc->u.oD.rateMax[0]) &&    /* CCK MODE */
          RT_IS_HT_INDEX(txRate) && /* HT PPDU Tx Completion */
          pRc->probeRate[0] != txRate) { /* Not HT Probe PPDU Tx */
        /* ignore HT 2G ppdus after switching to CCK mode */
        goto done;
    }

    RT_GET_RC_MASK_4_RIX((void *)pRateTable, txRate, &rMaskPos,&rateBit);
    rMask = pRc->validTxRateMask[rMaskPos];
  
    /* If txRate is not in valid rate range, don't let it go into our update module.
       This is becuase NUll data packet might use basic rate but its not included
       in TxRateMask. It will cause we stuck in the basic rate */
    if(!RATEMASK_IS_VALID(rMask, rateBit)) {
        goto done;
    }
  
    idx = rc_get_rate_bw_idx(rMaskPos);

#ifdef RATECONTROL_DYNAMIC_BW_DEBUG
    rc_dbg_dyn_bw_err_inj(idx, &nBad, &nFrames, &args->flags); 
#endif

    /* 40Mhz rssi affect borrowed from Fusion code base */

/* TODO
    Don't know history --need to check-- however, this does not sound 
    practical  when ACK was received with diffferent rate/tx power 
    For now only add for 80MHz bandwidth since 160 is still not there
 */
    
    if (args->ptx_rc.flags & WHAL_RC_FLAG_80MHZ) {
        rssiAck = rssiAck < 6? 0: rssiAck - 6;
    } else if (args->ptx_rc.flags & WHAL_RC_FLAG_40MHZ) {
        rssiAck = rssiAck < 3? 0: rssiAck - 3;
    }
    
    if (args->flags & WHAL_RC_TXDONE_X_RETRIES) {
        /* Update the PER. */

        /* first check if this was bw probe which failed */
        if (idx && (pRc->bw_probe_pending & (1 << idx)) &&
                    (txRate == pRc->probeRate[idx])) {
            pRc->probeRate[idx] = RT_INVALID_INDEX;
            /* set all other too but already done at the end */
        }
        else {
            /* invalidate probeRate if it matches current as there may be 
               multiple tx requests submitted */

            if (pRc->probeRate[idx] == txRate) {
                pRc->probeRate[idx] = RT_INVALID_INDEX;
                /* reset counter to defer probe */
                pRc->hwMaxRetryPktCnt[idx] = -4;
 
            } else {
                /* The frame was not a probe-frame but since we have had a
                 * complete failure in the tx of the frame, we would want to
                 * enable RTS-CTS for both the series in the next
                 * SW-retry of this frame. */
                if(pRc->rtsForFirstSeries == 0) {
                    pRc->rtsForFirstSeries = 1;
                }
            }

            /* Do not update any PER since no ACK/BA is likely due to 
               interference.
            */
#if ATH_TARGET
            if (g_rc_skip_rts_failure && 
                   (args->flags & WHAL_RC_TXDONE_RTS_ONLY)) {
                goto skip_per_update;
            }
#endif
            /* We shouldn't penalize severely based on number of tx attempts. */
            pRc->u.oD.excessRetries++;
            if(pRc->u.oD.excessRetries > _RATE_GetXRetryThr(retries-1) ) {
                pRc->state[txRate].per += 30;
                pRc->state[txRate].per =
                   A_MIN(pRc->state[txRate].per, _g_dbg_rc_weight);

                pRc->u.oD.excessRetries = 0;

            }

            /* Update the RSSI threshold */
            /*
             * Oops, it didn't work at all.  Set the required rssi
             * to the rssiAck we used to lookup the rate, plus 4dB.
             * The immediate effect is we won't try this rate again
             * until we get an rssi at least 4dB higher.
             */
#ifdef ENABLE_RSSI_BASED_RATECTRL
            /* It is found that increasing rssi for failed frames can, in
             *  certain scenarios, cause the rate logic to lock out higher
             *  rates.  Specifically this problem is seen to occur when
             *  the link is strong (high rssi) and aggregation is used.
             *  Collisions can occur in bursts causing the rssi threshold
             *  to be raised and forcing otherwise valid rates to be discarded
             *  in favor of lower rates.  It is noted that the Fusion
             *  code base has also removed this logic for AR5416 perhaps
             *  because of the same behavior.  */
            if (not_per_only() && (txRate > 0)) {
                A_RSSI rssi = A_MAX(pRc->rssiLastLkup, pRc->rssiLast - 2);
                A_RSSI cap = RT_GET_RSSI_MIN(pRateTable, txRate) + (RT_GET_RSSI_DELTA(pRateTable, txRate)<<1);

                    if(pRc->state[txRate].rssiThres + 2 < cap) {
                        if (pRc->state[txRate].rssiThres + 2 < rssi) {
                            pRc->state[txRate].rssiThres += 2;
                        } else {
                            pRc->state[txRate].rssiThres += 1;
                        }
                    }

                    stateChange         = TRUE;
            }

            /*
             * Also, if we are not doing a probe, we force a significant
             * backoff by reducing rssiLast.  This doesn't have a big
             * impact since we will bump the rate back up as soon as we
             * get any good ACK.  RateMax will also be set to the current
             * txRate if the failed frame is not a probe.
             */
            if (pRc->probeRate[idx] == 0 || pRc->probeRate[idx] != txRate) {

                if (retries > 1) {
                    pRc->rssiLast      = 10 * pRc->state[txRate].rssiThres / 16;
                    pRc->rssiLastPrev  = pRc->rssiLast;
                    pRc->rssiLastPrev2 = pRc->rssiLast;
                }
            }

#endif /* ENABLE_RSSI_BASED_RATECTRL */

        }
    } else {
        /* The frame's TX didn't fail completely, so we can resort to not using
         * RTS-CTS for the first series. */
        A_UINT32 tries = (retries)? ( retries -1 ) : retries;
        pRc->rtsForFirstSeries = 0;

        /* Update the PER.  Tries below is actual hw retries */
        
        /* new_PER = 7/8*old_PER + 1/8*(currentPER)  */
        /*
         * Assuming that nFrames is not 0.  The current PER
         * from the retries is 100 * retries / (retries+1),
         * since the first retries attempts failed, and the
         * next one worked.  For the one that worked, nBad
         * subframes out of nFrames wored, so the PER for
         * that part is 100 * nBad / nFrames, and it contributes
         * 100 * nBad / (nFrames * (retries+1)) to the above
         * PER.  The expression below is a simplified version
         * of the sum of these two terms.
         */

        /* ideally, we should never be receiving any update for no tx */
        if (nFrames) {
            pRc->state[txRate].per = (A_UINT8)(pRc->state[txRate].per -
                                     (pRc->state[txRate].per >> 3) +
                ((100*(tries*nFrames + nBad)/(nFrames*(tries+1))) >> 3));
        }
        pRc->u.oD.excessRetries = (pRc->u.oD.excessRetries > 0) ? (pRc->u.oD.excessRetries - 1) : 0;

#ifdef ENABLE_RSSI_BASED_RATECTRL
        pRc->rssiLastPrev2 = pRc->rssiLastPrev;
        pRc->rssiLastPrev  = pRc->rssiLast;
        pRc->rssiTime      = nowMsec;
#endif /* ENABLE_RSSI_BASED_RATECTRL */

        pRc->rssiLast      = rssiAck;

        /*
         * If we got at most one retry then increase the max rate if
         * this was a probe.  Otherwise, ignore the probe.
         */

        if (IS_RIX_VALID(pRc->probeRate[idx]) && 
            pRc->probeRate[idx] == txRate) {

            if ( retries > 1 || 3 * nBad >= nFrames) { 
                /*
                 * if the attempt worked, but more than half
                 * the subframes were bad then consider
                 * the probe a failure.
                 */
                pRc->probeRate[idx] = RT_INVALID_INDEX;
                /* reset counter to defer probe */
                pRc->hwMaxRetryPktCnt[idx] = -4;

            } else {
                pRc->u.oD.rateMax[idx] = pRc->probeRate[idx];
				pRc->lastRateIndex = pRc->probeRate[idx];
#if 0 /* Mercury logic */
                if (pRc->state[pRc->probeRate].per > 45) {
                    pRc->state[pRc->probeRate].per = 20;
                }
#else /* fusion logic */
                if (pRc->state[pRc->probeRate[idx]].per > 30) {
                    pRc->state[pRc->probeRate[idx]].per = 20;
                }
#endif

                pRc->probeRate[idx] = RT_INVALID_INDEX;
                /*
                 * Since this probe succeeded, we allow the next probe
                 * twice as soon.  This allows the maxRate to move up
                 * faster if the probes are succesful.
                 */
                pRc->u.oD.probeTime[idx] = nowMsec - 
                   (RT_GET_PROBE_PERIOD(pRateTable, pRc->u.oD.rateMax[idx])>>1);
                /* if this was bw probe it's sucessful */
//                if (idx && (pRc->bw_probe_pending == idx)) {
                /* TODO: what if regualar 40MHz probe and bw_probe_pending set to 80? */
                if (idx && (pRc->bw_probe_pending & (1 << idx))) {
                    /* wait for higher, if not already */
                    /* set to 80M if currently on 40MHz 
                      (pSib->peer_params.ni_flags & RC_PEER_80MHZ) */
//                    pRc->bw_probe_pending = (idx == 2)?0: idx +1;
                    pRc->bw_probe_pending &= ~(1 << idx);
                    /* Mark the lower bandwidth probe success */
                    if (pRc->bw_probe_pending && (idx == 2)) {
                        A_UINT8 lower_bw = pRc->bw_probe_pending >> 1;
                        pRc->u.oD.rateMax[lower_bw] = pRc->probeRate[lower_bw];
                        pRc->probeRate[lower_bw] = RT_INVALID_INDEX;
                        pRc->u.oD.probeTime[lower_bw] = 
                            nowMsec - (RT_GET_PROBE_PERIOD(pRateTable,
                                        pRc->u.oD.rateMax[lower_bw])>>1);

                        pRc->bw_probe_pending = 0;
                    }
                }
            }
        }

        if (retries > 1 || (3 * nBad >= nFrames)) {
            /*
             * Don't update anything.  We don't know if this was because
             * of collisions or poor signal.
             *
             * Later: if rssiAck is close to pRc->state[txRate].rssiThres
             * and we see lots of retries, then we could increase
             * pRc->state[txRate].rssiThres.
             */
            /* negative value to defer probe */
            pRc->hwMaxRetryPktCnt[idx] = -4;
        } else {
            /*
             * It worked with one tries.  First ignore bogus (small)
             * rssiAck values.
             */       
            /* < gives fast convergence to higher rate when PER improves*/
            if (txRate == pRc->u.oD.rateMax[idx] && 
            //if (RT_GET_RAW_KBPS(pRateTable, txRate) <= 
            //    RT_GET_RAW_KBPS(pRateTable, pRc->rateMax[idx]) && 
                pRc->hwMaxRetryPktCnt[idx] < 8) {
                pRc->hwMaxRetryPktCnt[idx]++;
            }

#ifdef ENABLE_RSSI_BASED_RATECTRL
            if (not_per_only() && 
                 (rssiAck >= RT_GET_RSSI_MIN(pRateTable, txRate))) {
                /* Average the rssi */
                if (txRate != pRc->rssiSumRate) {
                    pRc->rssiSumRate = txRate;
                    pRc->rssiSum     = pRc->rssiSumCnt = 0;
                }

                pRc->rssiSum += rssiAck;
                pRc->rssiSumCnt++;

                if (pRc->rssiSumCnt >= 4) {
                    A_RSSI32 rssiAckAvg = (pRc->rssiSum + 2) / 4;

                    pRc->rssiSum = pRc->rssiSumCnt = 0;

                    /* Now reduce the current rssi threshold. */
                    if ((rssiAckAvg < pRc->state[txRate].rssiThres + 2) &&
                        (pRc->state[txRate].rssiThres > RT_GET_RSSI_MIN(pRateTable, txRate)))
                    {
                        pRc->state[txRate].rssiThres--;
                    }

                    stateChange = TRUE;
                }
            }
#endif /* ENABLE_RSSI_BASED_RATECTRL */
        }
    }

    /* Make sure all rates above have at least the current PER */

    if (RT_IS_HT_INDEX(txRate)) { /* HT/VHT rates */
        for (rate = txRate + 1; rate < pRc->rateTableSize; rate++) {
            if (RT_GET_PHY(pRateTable, rate) != 
                RT_GET_PHY(pRateTable, txRate)) {
                break;
             }

            if (pRc->state[rate].per < pRc->state[txRate].per) {
                pRc->state[rate].per = pRc->state[txRate].per;
            }
        }
    }
    else { /* Legacy CCK/OFDM rates */
        for (rate = 0; RT_IS_OFDM_CCK_INDEX(rate); rate++) {
            if ((RT_GET_RAW_KBPS(pRateTable, txRate) < 
                RT_GET_RAW_KBPS(pRateTable, rate)) && 
               (pRc->state[rate].per < pRc->state[txRate].per)) {
                pRc->state[rate].per = pRc->state[txRate].per;

            }
        }
    }
#if ATH_TARGET   
skip_per_update:
#endif /* ATH_TARGET */    
    /* For all cases */

    /*
     * If this rate looks bad (high PER, historically set to 60 but that seems
       too much now so we have 50%) then stop using it for
     * a while (except if we are probing).
     */
    if (pRc->state[txRate].per >= g_rc_rate_max_per_thr &&
        RT_GET_RAW_KBPS(pRateTable, txRate) <= 
            RT_GET_RAW_KBPS(pRateTable, pRc->u.oD.rateMax[idx])) {

        RC_MASK_INFO_t tmp;
        A_UINT8 ret_val;

        tmp.rc_mask = rMask & g_pRATE->sc_fixRateSet[rMaskPos];
        tmp.idx = rMaskPos;
        
        /* Make sure rateMax mask is valid */
        _rc_get_peer_valid_rc_mask(g_pRATE, pSib, &tmp);

        ret_val = rcGetNextLowerValidTxRate(pRateTable, &tmp,
                        pRc, (A_UINT8) txRate, &pRc->u.oD.rateMax[idx]);

        if (ret_val != RT_INVAL_IDX) { /* keep probing if at lowest rate */
            /* Don't probe for a little while. */
            pRc->u.oD.probeTime[idx] = nowMsec;
        }
        else { /* lowest rate experienceing too much PER */
            /* if we are HT 2G association fall back to CCK rates */
            if (g_rc_cck_rate_allowed &&
                (IS_PHYMODE_11N2G(pSib->peer_params.phymode)) && 
                (rMaskPos == WHAL_RC_MASK_IDX_HT_20)) {
               
                /* switch to CCK mode */
                pRc->u.oD.rateMax[0] = CCK_RATE_TABLE_INDEX + 2; /* 2 mbps */

                goto done;
            }
                 
        }
    }

#ifdef ENABLE_RSSI_BASED_RATECTRL
    if (stateChange) {
        /*
         * Make sure the rates above this have higher rssi thresholds.
         * (Note:  Monotonicity is kept within the OFDM rates and within the CCK rates.
         *         However, no adjustment is made to keep the rssi thresholds monotonically
         *         increasing between the CCK and OFDM rates.)
         */
        for (rate = txRate; rate < pRc->rateTableSize - 1; rate++) {
            if (RT_GET_PHY(pRateTable, rate+1) != RT_GET_PHY(pRateTable, txRate)) {
                break;
            }

            if (pRc->state[rate].rssiThres + RT_GET_RSSI_DELTA(pRateTable, rate) >
                pRc->state[rate+1].rssiThres)
            {
                pRc->state[rate+1].rssiThres =
                    pRc->state[rate].rssiThres + RT_GET_RSSI_DELTA(pRateTable, rate);
            }
        }

        /* Make sure the rates below this have lower rssi thresholds. */
        for (rate = txRate - 1; rate >= 0; rate--) {
            if (RT_GET_PHY(pRateTable, rate) != RT_GET_PHY(pRateTable, txRate)) {
                break;
            }

            if (pRc->state[rate].rssiThres + RT_GET_RSSI_DELTA(pRateTable, rate) >
                pRc->state[rate+1].rssiThres)
            {
                if (pRc->state[rate+1].rssiThres < RT_GET_RSSI_DELTA(pRateTable, rate)) {
                    pRc->state[rate].rssiThres = 0;
                } else {
                    pRc->state[rate].rssiThres =
                        pRc->state[rate+1].rssiThres - RT_GET_RSSI_DELTA(pRateTable, rate);
                }

                if (pRc->state[rate].rssiThres < RT_GET_RSSI_MIN(pRateTable, rate)) {
                    pRc->state[rate].rssiThres = RT_GET_RSSI_MIN(pRateTable, rate);
                }
            }
        }
    }
#endif /* ENABLE_RSSI_BASED_RATECTRL */

    /* Make sure the rates below this have lower PER */
    /* Monotonicity is kept only for rates below the current rate. */
    if (pRc->state[txRate].per < lastPer) {
        if (RT_IS_HT_INDEX(txRate)) { /* HT/VHT rates */
            for (rate = txRate - 1; rate >= 0; rate--) {
                if (RT_GET_PHY(pRateTable, rate) != 
                    RT_GET_PHY(pRateTable, txRate)) {
                    break;
                }

                if (pRc->state[rate].per > pRc->state[rate+1].per) {
                    pRc->state[rate].per = pRc->state[rate+1].per;
                }
            }
        }
        else { /* Legacy CCK/OFDM rates */
            for (rate = 0; RT_IS_OFDM_CCK_INDEX(rate); rate++) {
                if (RT_GET_RAW_KBPS(pRateTable, txRate) <
                    RT_GET_RAW_KBPS(pRateTable, rate)) {
                    continue;
                }
                if (pRc->state[rate].per > pRc->state[txRate].per) {
                    pRc->state[rate].per = pRc->state[txRate].per;

                }
            }
        }
    }

#ifdef ENABLE_RSSI_BASED_RATECTRL
    /* Every so often, we reduce the thresholds (different for CCK and OFDM). */
    if (not_per_only() && 
        (nowMsec - pRc->rssiDownTime >=
           RT_GET_RSSI_REDUCE(pRateTable, txRate))) {

        A_UINT8 lower_rix, upper_rix;
    
        RT_GET_RIX_LIMITS_4_MASK(&upper_rix, &lower_rix, rMaskPos);

        for (rate = lower_rix; rate <= upper_rix; rate++) {
            if (pRc->state[rate].rssiThres > RT_GET_RSSI_MIN(pRateTable, rate)) {
                pRc->state[rate].rssiThres -= 1;
            }
        }

        pRc->rssiDownTime = nowMsec;
    }
#endif /* ENABLE_RSSI_BASED_RATECTRL */

    /* Every so often, we reduce PER (different for CCK and OFDM). */
    if (nowMsec - pRc->perDownTime[idx] >= 
        (RT_GET_RSSI_REDUCE(pRateTable, txRate)/2)) {
        A_UINT8 lower_rix, upper_rix;
    
        RT_GET_RIX_LIMITS_4_MASK(&upper_rix, &lower_rix, rMaskPos);

        for (rate = lower_rix; rate <= upper_rix; rate++) {
            if (pRc->state[rate].per)
                pRc->state[rate].per = 7*pRc->state[rate].per/8;
        }

        pRc->perDownTime[idx] = nowMsec;
    }

done:

    if (probe_aborted || args->is_probe) {
        A_MEMSET(&pRc->probeRate, RT_INVALID_INDEX, sizeof (pRc->probeRate));
    }

    return;
}

#endif

#ifdef SMART_ANTENNA
static void get_ratecode_bw_4_mask(wmi_peer_rate_info_t *rate_info,
                        A_UINT32 **ratecode_bw, A_UINT8 *ratecount_shift, A_UINT8 mask_idx)
{
    switch (mask_idx) {

        case 0:
            {
                *ratecode_bw = rate_info->ratecode_legacy;
                *ratecount_shift = 0;
            }
            break;

        case 1:
        case 3:
            {
                *ratecode_bw = rate_info->ratecode_20;
                *ratecount_shift = 8;
            }
            break;
        case 2:
        case 4:
            {
                *ratecode_bw = rate_info->ratecode_40;
                *ratecount_shift = 16;
            }
            break;
        case 5:
            {
                *ratecode_bw = rate_info->ratecode_80;
                *ratecount_shift = 24;
            }
            break;
        default:
            A_ASSERT(0);
            break;
    }

    return;
}


void _RateFillValidRatecodeList(struct rate_node *pSib, 
        const WHAL_RATE_TABLE *pRateTable, RATE_CONTEXT * g_pRATE, 
        wmi_peer_rate_info_t *rate_info)
{
    struct TxRateCtrl_s *pRc = pSib->txRateCtrl;
    RC_BW_TYPE_e bw, bw_idx;
    WHAL_RC_MASK_IDX m_idx, mask_idx;
    A_UINT8 rate_list_idx = 0;
    A_UINT8 rc, ratecount_shift;
    A_UINT32 *ratecode_bw;
    A_UINT16 i = 0;
    wlan_pdev_t *pdev = g_pdev_p;
    RC_MASK_INFO_t rc_mask_info;
    A_UINT8 upper, lower, tmp, rix;

    /* Initialize rate count to 0 (no rates filled yet) */
    rate_info->ratecount = 0;

    m_idx = _RATE_GetPeerPhy(pSib);

    /* Get default rate mask index based on peer capability */
    m_idx = (m_idx >=2) ? WHAL_RC_MASK_IDX_VHT_20 :
        (m_idx) ? WHAL_RC_MASK_IDX_HT_20 : 0;

    /* Get the Conn bw which is min of (vdev_bw, peer_bw) */
    RC_GET_PEER_BW(bw, ((wlan_peer_t *)pSib->peer));

    if (RC_IS_DYN_BW((DEV_GET_WAL_PDEV(pdev)))) {
        for (bw_idx = 0; bw_idx <= bw; bw_idx++) {
            mask_idx = m_idx + bw_idx;
            rc_mask_info.idx = mask_idx;

            get_ratecode_bw_4_mask(rate_info, &ratecode_bw, &ratecount_shift, mask_idx);

#if RC_SUPPORT_1D_RATECTRL
            if (g_use_2d_ratectrl) {
#endif
                int nss_idx;
                A_UINT8 *pValidRate;

                for (nss_idx = 0, tmp = 0; nss_idx < NUM_SPATIAL_STREAM; nss_idx++) {
                    pValidRate = rc_get_valid_rates_2d(pRc, mask_idx, nss_idx);

                    for(i = 0; i < pRc->u.tD.maxValidRate[mask_idx][nss_idx]; i++) {
                        _rc_get_peer_valid_rc_mask(g_pRATE, pSib, &rc_mask_info);

                        RT_GET_RIX_LIMITS_4_MASK(&upper, &lower, mask_idx);

                        rix = pValidRate[i];

                        /* Skip invalid rates */
                        if (!RATEMASK_IS_VALID(rc_mask_info.rc_mask, (rix - lower))){
                            continue;
                        }
                        rate_list_idx = tmp >> 2; /* Index into uint32 rate list */

                        /* Get Rate Code */
                        rc = RT_GET_HW_RATECODE(pRateTable, rix);
                        
                        /* Fill the Rate code */
                        ratecode_bw[rate_list_idx] |= (rc << ((tmp%4) << 3));
                        tmp++;
                    }
                }
#if RC_SUPPORT_1D_RATECTRL
            } else {
                for(i = 0, tmp = 0; i < pRc->u.oD.maxValidRate[mask_idx]; i++) {
                    _rc_get_peer_valid_rc_mask(g_pRATE, pSib, &rc_mask_info);

                    RT_GET_RIX_LIMITS_4_MASK(&upper, &lower, mask_idx);

                    rix = pRc->u.oD.validRateIndex[mask_idx][i];

                    /* Skip invalid rates */
                    if (!RATEMASK_IS_VALID(rc_mask_info.rc_mask, (rix - lower))){
                        continue;
                    }
                    rate_list_idx = tmp >> 2; /* Index into uint32 rate list */

                    /* Get Rate Code */
                    rc = RT_GET_HW_RATECODE(pRateTable, rix);
                    
                    /* Fill the Rate code */
                    ratecode_bw[rate_list_idx] |= (rc << ((tmp%4) << 3));
                    tmp++;
                }
            }
#endif

            /* Fill num of valid rates */
            rate_info->ratecount |= (tmp << ratecount_shift);
        }
    }
    else
    {
        /* Static BW case */
        /* Get Valid rate codes corresponding to that specific mask (BW) only */
        mask_idx = m_idx + bw;
        rc_mask_info.idx = mask_idx;

        get_ratecode_bw_4_mask(rate_info, &ratecode_bw, &ratecount_shift, mask_idx);

#if RC_SUPPORT_1D_RATECTRL
        if (g_use_2d_ratectrl) {
#endif
            int nss_idx;
            A_UINT8 *pValidRate;

            for (nss_idx = 0, tmp = 0; nss_idx < NUM_SPATIAL_STREAM; nss_idx++) {
                pValidRate = rc_get_valid_rates_2d(pRc, mask_idx, nss_idx);

                for(i = 0; i < pRc->u.tD.maxValidRate[mask_idx][nss_idx]; i++) {

                    _rc_get_peer_valid_rc_mask(g_pRATE, pSib, &rc_mask_info);

                    RT_GET_RIX_LIMITS_4_MASK(&upper, &lower, mask_idx);

                    rix = pValidRate[i];

                    /* Skip invalid rates */
                    if (!RATEMASK_IS_VALID(rc_mask_info.rc_mask, (rix - lower))){
                        continue;
                    }

                    rate_list_idx = tmp >> 2; /* Index into uint32 rate list */

                    /* Get Rate Code */
                    rc = RT_GET_HW_RATECODE(pRateTable, rix);

                    /* Fill the Rate code */
                    ratecode_bw[rate_list_idx] |= (rc << ((tmp%4) << 3));
                    tmp++;
                }
            }
#if RC_SUPPORT_1D_RATECTRL
        } else {
            for(i = 0, tmp = 0; i < pRc->u.oD.maxValidRate[mask_idx]; i++) {

                _rc_get_peer_valid_rc_mask(g_pRATE, pSib, &rc_mask_info);

                RT_GET_RIX_LIMITS_4_MASK(&upper, &lower, mask_idx);

                rix = pRc->u.oD.validRateIndex[mask_idx][i];

                /* Skip invalid rates */
                if (!RATEMASK_IS_VALID(rc_mask_info.rc_mask, (rix - lower))){
                    continue;
                }

                rate_list_idx = tmp >> 2; /* Index into uint32 rate list */

                /* Get Rate Code */
                rc = RT_GET_HW_RATECODE(pRateTable, rix);

                /* Fill the Rate code */
                ratecode_bw[rate_list_idx] |= (rc << ((tmp%4) << 3));
                tmp++;
            }
        }
#endif
        
        /* Fill num of valid rates */
        rate_info->ratecount |= (tmp << ratecount_shift);
    }

    return;
}



A_UINT32 _RATEGetRateSchedFlags(struct rate_node *pSib, 
        const WHAL_RATE_TABLE *pRateTable, 
        RATE_CONTEXT *g_pRATE, A_UINT32 rix)
{
    A_UINT32 flags = 0;

    /* Set approprate BW flag */
    RT_GET_BW_FLAG(flags, pRateTable, rix);

    /* Set SGI flag */
    flags |= _RATE_GetSGIFlag(pSib, g_pRATE, pRateTable, rix);

    /* STBC, LDPC */
    flags |= _RATE_GetRCFlags(pSib, g_pRATE, pRateTable, rix);

    /* Chain masks */
    flags |= _RATE_GetTxChainMask(pSib, pRateTable, rix);

    return flags;
}
#endif

/*
  * API FUNCTIONS START
  */


void _RATE_SetCurmode(RATE_CONTEXT * g_pRATE, WLAN_PHY_MODE mode)
{
    const WHAL_RATE_TABLE *rt;

    rt = whalGetRateTable(mode);
    A_ASSERT(rt != NULL);

    g_pRATE->sc_currates = rt;

    return;
}

/* when adding 11N support it became necessary to return
 * the rate index instead of the rate code because for
 * 11N rates the ratecode is not sufficient to describe
 * the rate to the HW. */
void _RATE_SetRtsCtsRate(RATE_CONTEXT *g_pRATE, A_UINT8 rate_code)
{
    if (g_pRATE) {
        const WHAL_RATE_TABLE *pRateTable = whalGetRateTable(MODE_MAX - 1);
        g_pRATE->sc_protrix = RT_CODE_TO_INDEX(pRateTable, rate_code, 0);
    }
}

A_UINT8 _RATE_GetRtsCtsRate(RATE_CONTEXT *g_pRATE, const WHAL_RATE_TABLE *pRateTable)
{
#if ATH_TARGET
    wal_pdev_t *wal_pdev = DEV_GET_WAL_PDEV(g_pdev_p);

    if(wal_pdev->rts_rc_flag)
        return RT_CODE_TO_INDEX(pRateTable, wal_pdev->rts_rc, 0);
    else
#endif
        return g_pRATE->sc_protrix;
}

void _RATE_SetRateMask(RATE_CONTEXT *g_pRATE, A_UINT32 type, A_UINT32 lower32, 
                       A_UINT32 higher32)
{
    A_UINT32 i,mask = 0;
    A_RATEMASK *pRateMask;

#if RC_SUPPORT_1D_RATECTRL
    if (g_use_2d_ratectrl) {
#endif
        pRateMask = g_pRATE->mcs_mask_4_nss_2d;
#if RC_SUPPORT_1D_RATECTRL
    } else {
        pRateMask = g_pRATE->mcs_mask_4_nss_1d;
    }
#endif

    if (g_pRATE) {
       if(type == RC_CCK_OFDM_RATES) {
            g_pRATE->wmiFixRateSetMask[WHAL_RC_MASK_IDX_NON_HT] = lower32 & 0xfff;
            g_pRATE->sc_fixRateSet[WHAL_RC_MASK_IDX_NON_HT] = lower32 & 0xfff;
       } else if(type == RC_HT_RATES) {
            for(i=0; i<NUM_SPATIAL_STREAM; i++) {
                mask = (1 << (i+1)*8)-1; 
                pRateMask[i] = lower32 & mask;
            }
        } else if(type == RC_VHT_RATES) {
            for(i=0; i<NUM_SPATIAL_STREAM; i++) {
                mask = (1 << (i+1)*10)-1; 
                pRateMask[NUM_SPATIAL_STREAM + i] = lower32 & mask;
            }
        }
    }
}

void rate_init_peer_ratectxt(struct rate_node *pSib, void *peer)
{
    struct TxRateCtrl_s *pRc  = NULL;

    pRc  = pSib->txRateCtrl;

    pSib->peer = peer;

    pRc->rssiLast = 0;            /* last ack rssi */
#ifdef ENABLE_RSSI_BASED_RATECTRL
    pRc->rssiLastLkup = 0;        /* last ack rssi used for lookup */
    pRc->rssiLastPrev = 0;        /* previous last ack rssi */
    pRc->rssiLastPrev2 = 0;       /* 2nd previous last ack rssi */
    pRc->rssiSumCnt = 0;          /* count of rssiSum for averaging */
    pRc->rssiSumRate = 0;         /* rate that we are averaging */
    pRc->rssiSum = 0;           /* running sum of rssi for averaging */
#endif /* ENABLE_RSSI_BASED_RATECTRL */
    /* mask of valid rates */
    memset(pRc->validTxRateMask, 0, sizeof(pRc->validTxRateMask));
    pRc->rateTableSize = 0;      /* rate table size */
#if RC_SUPPORT_1D_RATECTRL
    if (g_use_2d_ratectrl) {
#endif
        int i, j;

        A_MEMSET(pRc->u.tD.rateMax, 0, sizeof(pRc->u.tD.rateMax));
        A_MEMSET(&pRc->u.tD.probeTime, 0, sizeof (pRc->u.tD.probeTime)); /* msec timestamp for last probe */

        A_MEMSET(pRc->u.tD.maxValidRate, 0, sizeof (pRc->u.tD.maxValidRate));
        A_MEMSET(pRc->u.tD.excessRetries, 0, sizeof(pRc->u.tD.excessRetries));
        for (i = 0; i < NUM_DYN_BW; ++i) {
            for (j = 0; j < NUM_SPATIAL_STREAM; ++j) {
                pRc->u.tD.probePeriod[i][j] = RC_PROBE_PERIOD_2D_ALTNSS_MIN;
            }
#if RC_USE_CACHED_RATES
            pRc->u.tD.cachedRateInfo[i].rix = RT_INVALID_INDEX;
#endif
        }
#if RC_SUPPORT_1D_RATECTRL
    } else {
        A_MEMSET(pRc->u.oD.rateMax, 0, sizeof(pRc->u.oD.rateMax));
        A_MEMSET(&pRc->u.oD.probeTime, 0, sizeof (pRc->u.oD.probeTime)); /* msec timestamp for last probe */
        A_MEMSET(pRc->u.oD.maxValidRate, 0, sizeof (pRc->u.oD.maxValidRate));
        pRc->u.oD.excessRetries = 0;
    }
#endif
    A_MEMSET(&pRc->probeRate, RT_INVALID_INDEX, sizeof (pRc->probeRate)); /* rate we are probing at */
#ifdef ENABLE_RSSI_BASED_RATECTRL
    pRc->rssiTime = 0;          /* msec timestamp for last ack rssi */
    pRc->rssiDownTime = 0;      /* msec timestamp for last down step */
#endif /* ENABLE_RSSI_BASED_RATECTRL */
    pRc->bw_probe_pending = 0; /* Waiting for higher bandwith probe */
    A_MEMSET(&pRc->hwMaxRetryPktCnt, 0 ,
         sizeof(pRc->hwMaxRetryPktCnt));  /* num packets since we got HW max retry error */
    /* maximum number of valid rate */
    A_MEMSET(&pRc->perDownTime, 0, sizeof (pRc->perDownTime)); /* msec timstamp for last PER down step */
    pRc->htSgiValid = 0;        /* Flags to allow Short Guard Interval in HT 20MHz or HT 40MHz */
    pRc->rtsForFirstSeries = 0;
	pRc->lastRateIndex = 0;



    return;
}


void rate_init_vdev_ratectxt(RATE_CONTEXT *g_pRATE, void *vdev)
{

    g_pRATE->dev_context = vdev;

    g_pRATE->sc_userRix = -1;
    g_pRATE->sc_fixedrix = -1;

    WHAL_RC_INIT_RC_MASKS(g_pRATE->wmiFixRateSetMask);

    WHAL_RC_INIT_RC_MASKS(g_pRATE->sc_fixRateSet);

    /* WAR mask out MCS 8 and 9 for VHT due to the underrun issue
     * identified with them.
     * TODO REVISIT REMOVE
     */
#if 0
    g_pRATE->wmiFixRateSetMask[3] &= 0x0ff3fcff;
    g_pRATE->sc_fixRateSet[3]     &= 0x0ff3fcff;
    g_pRATE->wmiFixRateSetMask[4] &= 0x0ff3fcff;
    g_pRATE->wmiFixRateSetMask[5] &= 0x0ff3fcff;
    g_pRATE->sc_fixRateSet[4]     &= 0x0ff3fcff;
    g_pRATE->sc_fixRateSet[5]     &= 0x0ff3fcff;
#endif

    /* Set Default HW rate table VHT MCSs Masks anc current NSS */
    g_pRATE->curr_nss = NUM_SPATIAL_STREAM;

#if RC_SUPPORT_1D_RATECTRL
    /* 1D */
    A_MEMCPY(&g_pRATE->mcs_mask_4_nss_1d[0], default_ht_rt_masks_1d,
             sizeof (A_RATEMASK) * NUM_SPATIAL_STREAM);
    A_MEMCPY(&g_pRATE->mcs_mask_4_nss_1d[NUM_SPATIAL_STREAM],
             default_vht_rt_masks_1d, sizeof (A_RATEMASK) * NUM_SPATIAL_STREAM);
#endif

    /* 2D */
    A_MEMCPY(&g_pRATE->mcs_mask_4_nss_2d[0], default_ht_rt_masks_2d,
             sizeof (A_RATEMASK) * NUM_SPATIAL_STREAM);
    A_MEMCPY(&g_pRATE->mcs_mask_4_nss_2d[NUM_SPATIAL_STREAM],
             default_vht_rt_masks_2d, sizeof (A_RATEMASK) * NUM_SPATIAL_STREAM);

    g_pRATE->sc_ifmgmtfixed = 0;
    g_pRATE->sc_defmgtrix = 0;
    g_pRATE->sc_bEnableFrameMask = 0;
    g_pRATE->sc_bFramematch = 0;
    g_pRATE->sc_frameType = 0;
    g_pRATE->sc_frameRateMask = A_RATEMASK_FULL;
    RATE_SetRtsCtsRate(g_pRATE, DEFAULT_LOWEST_RATE_IN_5GHZ); /* 6 Mbps OFDM rate */

    RATE_SetCurmode(g_pRATE, MODE_11G);

    rate_init_vdev_params(g_pRATE);

    _RATE_SetSGIMasks(g_pRATE);

    g_pRATE->ht_rate_ampdu_th1 = RT_HT_AMPDU_TH1;
    g_pRATE->ht_rate_ampdu_th2 = RT_HT_AMPDU_TH2;
    g_pRATE->ht_only_th = RT_HT_ONLY_TH;
#if ATH_TARGET
    rc_set_vendor_chainmask(vdev);
#endif

    g_scaled_nss_hysteresis = (g_nss_hysteresis << 7) / 100;
    g_scaled_mcs_hysteresis = (g_mcs_hysteresis << 7) / 100;

    return;
}


/* will be cleaned after test and before check-in*/
#if ATH_TARGET
void wlan_rc_set_max_nss(wlan_vdev_t *dev, A_UINT8 nss)
{
    RATE_CONTEXT * g_pRATE = (RATE_CONTEXT *)dev->pRateCtrl;
    if (nss && nss <= NUM_SPATIAL_STREAM) {

        DBGLOG_RECORD_LOG(WLAN_MODULE_RATECTRL, -1,
            RATECTRL_DBGID_NSS_CHANGE, DBGLOG_ERR, 1, nss);

        g_pRATE->curr_nss = nss;
           /* set corresponding wal level nss */
        wal_rc_set_vdev_max_nss(DEV_GET_WAL_VDEV(dev), nss);

        /* Should we also turn off HW rf chain? */
        /* TODO */
    }
}

void wlan_rc_set_vht_sgi_mask(wlan_vdev_t *dev, A_UINT16 vht_sgi_mask)
{
    RATE_CONTEXT * g_pRATE = (RATE_CONTEXT *)dev->pRateCtrl;

    g_pRATE->sgiMask[1] = (vht_sgi_mask & 0x3ff);
}


void wlan_rc_set_vht80_rate_mask(wlan_vdev_t *dev, A_UINT32 vht80_rate_mask)
{
    RATE_CONTEXT * g_pRATE = (RATE_CONTEXT *)dev->pRateCtrl;

    g_pRATE->wmiFixRateSetMask[5] = (vht80_rate_mask & A_RATEMASK_VHT_80);
    g_pRATE->sc_fixRateSet[5]     = (vht80_rate_mask & A_RATEMASK_VHT_80);
}
#endif



/*****************************************************************************/
/* FUNCTION: RATE_GetTxRetrySchedule
 * 
 * PARAMS:  [IN] void *pdev - pointer to wal device structure.
 *          [IN] RC_TX_RATE_SCHEDULE *rc_sched - pointer to rate schedule.
 *          [IN/OUT] WHAL_RATE_TABLE **rt - HW rate table.
 *          [IN] void *ptid - Pointer to wal tid
 *          [IN] void *arg - The list of arguments 
 *
 * RETURNS: N/A
 *
 * DESCRIPTION: Called by transmit authority to calculate the transmit 
 *      retry schedule for a frame.  The function accounts for frame
 *      attributes, network capabilities and recent tx/rx results.
 *      The returned retry schedule is intended to be used by the
 *      caller to transmit the frame to the intended target.
 */
/*****************************************************************************/

A_BOOL _RATE_GetTxRetrySchedule(void *pdev,
                  const WHAL_RATE_TABLE ** rt,
                  void *ppeer,
                  void *args,
                  void *pkt_info_rcf)

{
#if ATH_TARGET
    wlan_peer_t *wlan_peer = (wlan_peer_t *)ppeer;
    wlan_vdev_t *dev = (wlan_peer)? (wlan_vdev_t *)wlan_peer->pDev: NULL;
#else
    struct ol_txrx_peer_t *wlan_peer = (struct ol_txrx_peer_t *)ppeer;
    struct ol_txrx_vdev_t *dev = (wlan_peer)?wlan_peer->vdev: NULL;
#endif
    A_BOOL shortPreamble =1; 
    struct rate_node *an = RATE_NODE(wlan_peer);

    RATE_CONTEXT * g_pRATE = (dev) ? (RATE_CONTEXT *)dev->pRateCtrl: NULL;
    const WHAL_RATE_TABLE * pRateTable = NULL;
    A_UINT8 tries = 0;
    A_UINT8 txrate = 0;
    A_RATEMASK rateMask;
    A_UINT8 rix;

    RC_BW_TYPE_e bw, bw_idx;
    RC_MASK_INFO_t rc_mask_info;
    WHAL_RC_MASK_IDX m_idx;
    A_UINT32 rts_cts = _RATE_IsRTS_CTS_Enabled(an);
    A_UINT32 is_rts_cts = (rts_cts > WAL_RC_RTS_CTS_DISABLED);
    WAL_RC_RTSCTS_PROFILE rts_cts_profile = _RATE_GetRTS_CTS_Profile(an);

    RC_TX_RATE_SCHEDULE rc_sched;
    A_RATE probe_rix = RT_INVALID_INDEX;
    A_RATE prev_bw_rix = 0;
    A_UINT8 rateMax;
    struct TxRateCtrl_s *pRc        = (an) ? an->txRateCtrl: NULL;

    A_UINT32 nowMsec = (A_UINT32)(size_t)args;


    A_MEMSET(&rc_sched, 0, sizeof (RC_TX_RATE_SCHEDULE));

    if( dev == NULL || !g_pRATE || rt == NULL || an == NULL || pRc == NULL) {
        return FALSE;
    }

#if ATH_TARGET
    shortPreamble = wal_rc_is_short_preamble_enabled(DEV_GET_WAL_VDEV(dev));
#endif

    RC_GET_TX_RETRIES(tries, wlan_peer);
    /* Get initial rate mask and mask index */
    rateMask = 0;
    if(an) {
       m_idx = _RATE_GetPeerPhy(an);
    } else {
       A_ASSERT(0);
    }

#if RC_SUPPORT_1D_RATECTRL
    if (g_use_2d_ratectrl) {
#endif
        rateMax = pRc->u.tD.rateMax[0][0];
#if RC_SUPPORT_1D_RATECTRL
    } else {
        rateMax = pRc->u.oD.rateMax[0];
    }
#endif

    /* Get default rate mask index based on peer capability */
    m_idx = (m_idx >=2) ? WHAL_RC_MASK_IDX_VHT_20 :
                (m_idx && RT_IS_HT_INDEX(rateMax)) ?
                     WHAL_RC_MASK_IDX_HT_20:0;

    /*
            Populating series/bw rate retry series.
            a) determine whether static/dynamic bw configuration
            b) get apropriate rate mask indices to limit the search
            c) Optionally, when RTS/CTS2Self enabled, program two series
                c.1) both first and second series have try count set to 1
                c.2) second series has same rate setting except RTS/CTS enabled.

            When already running with lowest HT/VHT rates shall we fall down to OFDM/CCK?
            What is the advantage? in Enterprise case it would just kill everyone else.
            In fact most of the time not even lower HT/VHT rates should be used.
            REVISIT
            based on review/comments.
            Remmber going forward at one point of time we do have to leave legacy rates only
            for association to be fair with other smart devices.
        */

    /* Find out connection bw 

        */

    A_ASSERT((an->peer));

    /* Get the Conn bw which is min of (vdev_bw, peer_bw) */
    RC_GET_PEER_BW(bw, wlan_peer);

    /* Find out whether dynamic BW or static BW configuration */
    /* for legacy non-ht as well? */
    if (!RT_IS_HT_INDEX(rateMax) && 
         IS_PHYMODE_11N2G(an->peer_params.phymode)) { /* HT Association in CCK mode */
        bw = 0; /* only 20MHz */
        is_rts_cts = 0;
    }

    if (RC_IS_DYN_BW(pdev)) {
       A_UINT32 rts_bw_probe = 0;
       A_UINT32 rt_idx = 0;
        /*  Populate multiple rate series for each supported bw.
            When RTS/CTS is not enabled we only program one rate 
            series. However, when RTS/CTS is enabled we have two
            series. First, original transmission just one try, and 
            second series same original transmission however 
            preceded by RTS/CTS exchange.
            REVIST
            Due to curent nature of ppdu formation RTS/CTS 
            enablement may incur additional overhead, therefore
            verify the side effect in terms of performance.
        */
        
       
        if(is_rts_cts) {
            if(( rts_cts_profile == WAL_RC_RTSCTS_FOR_ALL_RATESERIES) || 
                ((rts_cts_profile == WAL_RC_RTSCTS_ACROSS_SW_RETRIES) &&
                (pRc->rtsForFirstSeries != 0))) {
                rc_sched.tries[0] = tries;
            } else {
                /* Control falls here only if rtscts is used in either of the
                 * series (profiles 1, and maybe 2). */
                if(tries > 1) {
                    /* todo: Ideally, we should have tries[0] set to 1 and
                     * tries[1] set ot (tries-1) */
                    rc_sched.tries[0] = tries >> 1;
                } else {
                    rc_sched.tries[0] = tries;
                }
            }
        } else { /* rtscts is disabled */
            rc_sched.tries[0] = tries;
        }

        for (bw_idx = 0; bw_idx <= bw; bw_idx++) {

            rc_mask_info.idx = m_idx + bw_idx;
            rc_mask_info.rc_mask = 0;

           /* Check if higher bandwiths are not waiting to be probed before
              getting those higher bandwith rates
           */
           if (bw_idx && (pRc->bw_probe_pending & (1 << bw_idx))) {
               /* 40/80MHz probe waiting*/

               A_RATE lower_rix, upper_rix, i;
               A_UINT32 probeTime;

#if RC_SUPPORT_1D_RATECTRL
               if (g_use_2d_ratectrl) {
#endif
                   probeTime = pRc->u.tD.probeTime[bw_idx][0]; 
#if RC_SUPPORT_1D_RATECTRL
               } else {
                   probeTime = pRc->u.oD.probeTime[bw_idx]; 
               }
#endif

               if (probeTime && (probeTime > nowMsec)) {
                  /* Probe interval not expired still waiting */
                  break;
               }
               
               /* If the previous rate (previous lower bw) is already lowest,
                  or we have not transmitted successfully enough frames on
                  that rate, don't probe higher bw yet but wait for channel
                  to improve rather
               */
#if RC_SUPPORT_1D_RATECTRL
               if (g_use_2d_ratectrl) {
#endif
                   A_UINT8 *pValidRate = rc_get_valid_rates_2d(pRc, rc_mask_info.idx - 1, 0);
                   if ((pValidRate[0] == prev_bw_rix)) {
                       break;
                   }
#if RC_SUPPORT_1D_RATECTRL
               } else {
                   if ((pRc->u.oD.validRateIndex[rc_mask_info.idx - 1][0] == 
                           prev_bw_rix)) {
                       break;
                   }
               }
#endif
               /* Time to turn on higher bandwiths again:
                      1. Get valid rate >= prev_bw_rix
                      2. Limit the aggreate, similar to probe, 
                      3. Set RateMax to valid rate
                      4. ageout per for this bw so it can rate adapt
               */

               RT_GET_RIX_LIMITS_4_MASK(&upper_rix, &lower_rix,  
                  rc_mask_info.idx); 
               
               rix = RT_INVALID_INDEX;
               /* Get valid rate mask */
               _rc_get_peer_valid_rc_mask(g_pRATE, an, &rc_mask_info);

               for (i = lower_rix; i <= upper_rix; i++) {
                   /* Reset PER since rate is just higher than lower bw */
                   pRc->state[i].per = 0;
#ifdef ENABLE_RSSI_BASED_RATECTRL
                   pRc->state[i].rssiThres = 0;
#endif /* ENABLE_RSSI_BASED_RATECTRL */

                   /* Skip invalid rates */
                   if (!RATEMASK_IS_VALID(rc_mask_info.rc_mask, 
                        (i - lower_rix))){
                       continue;
                   }

                   /* pRateTable will be populated here by 20MHz */
                   if (rix == RT_INVALID_INDEX && 
                       (RT_GET_RAW_KBPS(pRateTable, prev_bw_rix) <
                         RT_GET_RAW_KBPS(pRateTable, i))) {
                         rix = i; /* Save this rate to be used */
                   }
               }
               pRc->perDownTime[bw_idx] = nowMsec;
#ifdef ENABLE_RSSI_BASED_RATECTRL
               pRc->rssiDownTime = nowMsec;
#endif /* ENABLE_RSSI_BASED_RATECTRL */

               A_ASSERT(rix != RT_INVALID_INDEX);
 
               /* Set current rate since we have good rate */
               pRc->probeRate[bw_idx] = probe_rix = rix;
               /* It is possible to probe more than one bandwidths at the same
                  time using VHT RTS/CTS. 
                  for example, say both 40/80 MHz probes are pending we would
                  set probe rate for 40 and 80 both here with RTS/CTS, if
                  there is interference on receive side based on CTS bandiwth
                  80/40/20 probe/frame would go out. If everything is good
                  current rate table 80MHz receive sensistivey would be much
                  better than 40/20 giving higher throghput.
                  Unfortunately, on Peregrine we cannot have just 80/20 BW
                  programmed.
               */
               if (g_rc_rts_bw_probe && (bw_idx < bw)) { /* 40/80 MHz probe */
                   if (rts_bw_probe == 0) {
                       rts_bw_probe = bw_idx;  /* 1st bw >20 */
                   }
                   /* move next higher bw probe */
                   pRc->bw_probe_pending |= (1 << (bw_idx + 1));
#if RC_SUPPORT_1D_RATECTRL
                   if (g_use_2d_ratectrl) {
#endif
                       pRc->u.tD.probeTime[bw_idx +1][0] = nowMsec; /* fake probe time */
#if RC_SUPPORT_1D_RATECTRL
                   } else {
                       pRc->u.oD.probeTime[bw_idx +1] = nowMsec; /* fake probe time */
                   }
#endif
               }
               else {

               /* In case, both 40/80 MHz are disabled, keep higher bw still 
                  disabled
               */
               /* Disable all higher bw for now */
                   A_UINT32 higher_bw_idx = (rts_bw_probe)? 
                       rts_bw_probe : bw_idx;

#if RC_SUPPORT_1D_RATECTRL
                   if (g_use_2d_ratectrl) {
#endif
                       while (higher_bw_idx <= bw) {
                           /* what about time wrap */
                           pRc->u.tD.probeTime[higher_bw_idx++][0] = /* use rate probe time?*/
                               nowMsec + (RT_GET_PROBE_PERIOD(pRateTable, rix) <<
                                        g_rc_bw_probe_shift_factor);
                       }
#if RC_SUPPORT_1D_RATECTRL
                   } else {
                       while (higher_bw_idx <= bw) {
                           /* what about time wrap */
                           pRc->u.oD.probeTime[higher_bw_idx++] = /* use rate probe time?*/
                               nowMsec + (RT_GET_PROBE_PERIOD(pRateTable, rix) <<
                                        g_rc_bw_probe_shift_factor);
                       }
                   }
#endif
               }
               /* Skip getRateTbleAndIndex now */
           }
           else {
                A_UINT8 minimumBWRate;

                GetRateTblAndIndex(g_pRATE, &probe_rix, shortPreamble, an,
                    &txrate, &pRateTable, &rix, 0, &rc_mask_info, nowMsec);
             /* It may be possible that, in dynamic bw scenario, that rate
                returned for higher bw goodput is less than current rate for
                lower bw, in that case disable higher bw for a while.
                Eventually, we would probe for higher bw to see if that is
                working and if yes, enable using that bw from thereon.
              */
#if RC_SUPPORT_1D_RATECTRL
               if (g_use_2d_ratectrl) {
#endif
                   A_UINT8 *pValidRate = rc_get_valid_rates_2d(pRc, rc_mask_info.idx, 0);
                   minimumBWRate = pValidRate[0];
#if RC_SUPPORT_1D_RATECTRL
               } else {
                   minimumBWRate = pRc->u.oD.validRateIndex[rc_mask_info.idx][0];
               }
#endif

               if (bw_idx && /* Lower BW rate is better */
                  ((RT_GET_RAW_KBPS(pRateTable, prev_bw_rix) >=
                         RT_GET_RAW_KBPS(pRateTable, rix)) ||
                   /* or, running at lowest MCS and PER is high */
                  ((rix == minimumBWRate) &&
                         (pRc->state[rix].per > 30)))) {
                   /* Disable all higher bw for now */
                   pRc->bw_probe_pending = (1 << bw_idx);

#if RC_SUPPORT_1D_RATECTRL
                   if (g_use_2d_ratectrl) {
#endif
                       while (bw_idx <= bw) {
                           /* Disable all higher bw for now */
                           pRc->bw_probe_pending |= (1 << bw);
                           /* what about time wrap? */
                           pRc->u.tD.probeTime[bw--][0] = /* use rate probe time?*/
                               nowMsec + (RT_GET_PROBE_PERIOD(pRateTable, rix) <<
                                      g_rc_bw_probe_shift_factor);
                       }
#if RC_SUPPORT_1D_RATECTRL
                   } else {
                       while (bw_idx <= bw) {
                           /* Disable all higher bw for now */
                           pRc->bw_probe_pending |= (1 << bw);
                           /* what about time wrap? */
                           pRc->u.oD.probeTime[bw--] = /* use rate probe time?*/
                               nowMsec + (RT_GET_PROBE_PERIOD(pRateTable, rix) <<
                                      g_rc_bw_probe_shift_factor);
                       }
                   }
#endif
               }

           }

           if (rts_bw_probe == 0) {
               prev_bw_rix = rix;
           }
           /* Set Primary rate */
           rc_sched.rix[rt_idx] = rix;
            
           /*
             With dynamic BW we have a limitation here where we cannot
             just send a probe frame on fixed bw. Therefore, when we 
             are probing for any bw, dont program higher bw anymore
             There is still a chance that it may use lower bw, which is
             not a probe, e.g. CCA on secondary got busy, however, currently
             that is handled as skipped probe and we try again later on.
            */
            if (IS_RIX_VALID(probe_rix)) {
                /* Terminate rate schedule here */
                if (rts_bw_probe == 0) {
                    bw = bw_idx;
                }
                /* Limit the HW tries to 1 */
                rc_sched.tries[0] = 1;
                /* disable second tries if enabled by previous rates */
                rc_sched.tries[1] = 0;
                /* 
                   In general, probe and primary rate may have different
                   capability, e.g., STBC, SGI. Ideally, it would be nice
                   to store probe flags similar to rateflags, but due to 
                   memory constraint for now lets use probe rate's properties
                   for primary rate as well, since this is going to be 
                   thrown after 1/2 ppdus transmissions.
                */
                /* TODO: Add probe flag separately or change design to always
                   have probe rix == primary rix
                */
                rix = probe_rix;

            }

            /* Set appropriate BW flag */
            RT_GET_BW_FLAG(rc_sched.flags[rt_idx],pRateTable,rix);
            
            /* Set SGI flag */
            rc_sched.flags[rt_idx] |=
                _RATE_GetSGIFlag(an, g_pRATE, pRateTable, rix);
            
            /* STBC, LDPC */
            rc_sched.flags[rt_idx] |=
                _RATE_GetRCFlags(an, g_pRATE, pRateTable, rix);

            /* Chain masks */
            rc_sched.flags[rt_idx] |=
                _RATE_GetTxChainMask(an, pRateTable, rix);
                
            if (rts_bw_probe) {
                /* enable VHT RTS/CTS */
                rc_sched.flags[rt_idx] |= WHAL_RC_FLAG_RTSENA;
                rc_sched.bw_in_service = 2;
                rc_sched.rts_rix = RATE_GetRtsCtsRate(g_pRATE, pRateTable);
            }

            /* set default tpc */
            RC_GET_TPC(rc_sched.tpc[rt_idx], wlan_peer);

            if (is_rts_cts && !IS_RIX_VALID(probe_rix)) {

                if((rts_cts_profile == WAL_RC_RTSCTS_ERP) ||
                  (rts_cts_profile == WAL_RC_RTSCTS_FOR_ALL_RATESERIES) ||
		  ((rts_cts_profile == WAL_RC_RTSCTS_ACROSS_SW_RETRIES) &&
                    (pRc->rtsForFirstSeries != 0))) {

                    if (rts_cts == WAL_RC_USE_RTS_CTS) {
                        rc_sched.flags[rt_idx] |= WHAL_RC_FLAG_RTSENA;
                        rc_sched.bw_in_service = RT_IS_VHT_INDEX(rix)?2:0;
                    } else { /* WAL_RC_USE_CTS2SELF */
                        rc_sched.flags[rt_idx] |= WHAL_RC_FLAG_CTSENA;
                    }
                    rc_sched.rts_rix = RATE_GetRtsCtsRate(g_pRATE, pRateTable);
                }

                /* SECOND SERIES */
                /* Program the second series only if we are not using RTS-CTS on
                 * both the series, but only on the 2nd series. */
                if((tries > 1) && (((rts_cts_profile == WAL_RC_RTSCTS_ACROSS_SW_RETRIES) &&
                    (pRc->rtsForFirstSeries == 0)) ||
                   (rts_cts_profile == WAL_RC_RTSCTS_FOR_SECOND_RATESERIES))) {
                    /* Enter here only if the profile is 1, 2 or maybe 4. */

                    rt_idx++;
                    /* Use the same rate series as original transmission except
                                    with RTS/CTS enabled
                                */
                    rc_sched.tries[1] = tries - (tries >> 1);
                    rc_sched.rix[rt_idx] = rix;

                    /* set default tpc */
                    RC_GET_TPC(rc_sched.tpc[rt_idx], wlan_peer);

                    /* Set appropriate flags (original + RTS/CTS + series 1 flag) */
                    rc_sched.flags[rt_idx] =
                        rc_sched.flags[rt_idx-1] | WHAL_RC_FLAG_SERIES1;

                    if (rts_cts == WAL_RC_USE_RTS_CTS) {
                        rc_sched.flags[rt_idx] |= WHAL_RC_FLAG_RTSENA;
                        rc_sched.bw_in_service = RT_IS_VHT_INDEX(rix)?2:0;
                    }
                    else { /* WAL_RC_USE_CTS2SELF */
                        rc_sched.flags[rt_idx] |= WHAL_RC_FLAG_CTSENA;
                    }
                    rc_sched.rts_rix = RATE_GetRtsCtsRate(g_pRATE, pRateTable);

                }
            }
            rt_idx++;
        }
        
        rc_sched.num_valid_rates = rt_idx;

    }
    else { /* Static BW mode */
        /* only one rate series */
        rc_sched.num_valid_rates = 1;
        rc_mask_info.idx = m_idx + bw;
        rc_mask_info.rc_mask = rateMask;

        GetRateTblAndIndex(g_pRATE, &probe_rix, shortPreamble, an,
            &txrate, &pRateTable, &rix, 0, &rc_mask_info, nowMsec);

        /* Set Primary rate */
        rc_sched.rix[0] = rix;

        if (IS_RIX_VALID(probe_rix)) {
                /* Limit the HW tries to 1 */
                rc_sched.tries[0] = 1;
                /* disable second tries if enabled by previous rates */
                rc_sched.tries[1] = 0;
                /*
                   In general, probe and primary rate may have different
                   capability, e.g., STBC, SGI. Ideally, it would be nice
                   to store probe flags similar to rateflags, but due to
                   memory constraint for now lets use probe rate's properties
                   for primary rate as well, since this is going to be
                   thrown after 1/2 ppdus transmissions.
                */
                /* TODO: Add probe flag separately or change design to always
                   have probe rix == primary rix
                */
                rix = probe_rix;

        }
        else {
             if(is_rts_cts) {
                 if((rts_cts_profile == WAL_RC_RTSCTS_FOR_ALL_RATESERIES) ||
                     ((rts_cts_profile == WAL_RC_RTSCTS_ACROSS_SW_RETRIES) &&
                     (pRc->rtsForFirstSeries != 0))) {
                     rc_sched.tries[0] = tries;
                 } else {
                     /* Control falls here only if rtscts is used in either of the
                      * series (profiles 1, and maybe 2). */
                     if(tries > 1) {
                         /* todo: Ideally, we should have tries[0] set to 1 and
                          * tries[1] set ot (tries-1) */
                         rc_sched.tries[0] = tries >> 1;
                     } else {
                         rc_sched.tries[0] = tries;
                     }
                 }
             } else { /* rtscts is disabled */
                 rc_sched.tries[0] = tries;
             }
        }

        /* Set appropriate BW flag */
        RT_GET_BW_FLAG(rc_sched.flags[0],pRateTable,rix);

        /* Set SGI flag */
        rc_sched.flags[0] |=
            _RATE_GetSGIFlag(an, g_pRATE, pRateTable, rix);

        /* STBC, LDPC */
        rc_sched.flags[0] |=
            _RATE_GetRCFlags(an, g_pRATE, pRateTable, rix);

        /* Chain masks */
        rc_sched.flags[0] |=
            _RATE_GetTxChainMask(an, pRateTable, rix);

         /* set default tpc */
        RC_GET_TPC(rc_sched.tpc[0], wlan_peer);

                 
        if (is_rts_cts && !IS_RIX_VALID(probe_rix)) {

            if((rts_cts_profile == WAL_RC_RTSCTS_ERP) ||
                (rts_cts_profile == WAL_RC_RTSCTS_FOR_ALL_RATESERIES) || 
                ((rts_cts_profile == WAL_RC_RTSCTS_ACROSS_SW_RETRIES) &&
		(pRc->rtsForFirstSeries != 0))) {

                if (rts_cts == WAL_RC_USE_RTS_CTS) {
                    rc_sched.flags[0] |= WHAL_RC_FLAG_RTSENA;
                    rc_sched.bw_in_service = RT_IS_VHT_INDEX(rix)?2:0;
                } else { /* WAL_RC_USE_CTS2SELF */
                    rc_sched.flags[0] |= WHAL_RC_FLAG_CTSENA;
                }
                rc_sched.rts_rix = RATE_GetRtsCtsRate(g_pRATE, pRateTable);
            }


            /* SECOND SERIES */
            /* Program the second series only if we are not using RTS-CTS on
             * both the series, but only on the 2nd series. */
            if((tries > 1) && (((rts_cts_profile == WAL_RC_RTSCTS_ACROSS_SW_RETRIES) &&
                (pRc->rtsForFirstSeries == 0)) ||
               (rts_cts_profile == WAL_RC_RTSCTS_FOR_SECOND_RATESERIES))) {
                /* Enter here only if the profile is 1, maybe 2. */

                /* Use the same rate series as original transmission except
                            with RTS/CTS enabled
                        */
                rc_sched.num_valid_rates++;
                rc_sched.tries[1] = tries - (tries >> 1);
                rc_sched.rix[1] = rix;

                /* Set appropriate flags (original + RTS/CTS + series 1 flag) */
                rc_sched.flags[1] =
                    rc_sched.flags[0] | WHAL_RC_FLAG_SERIES1;

                if (rts_cts == WAL_RC_USE_RTS_CTS) {
                    rc_sched.flags[1] |= WHAL_RC_FLAG_RTSENA;
                    rc_sched.bw_in_service = RT_IS_VHT_INDEX(rix)?2:0;
                }
                else { /* WAL_RC_USE_CTS2SELF */
                    rc_sched.flags[1] |= WHAL_RC_FLAG_CTSENA;
                }
                rc_sched.rts_rix = RATE_GetRtsCtsRate(g_pRATE, pRateTable);
            }
        }
    }


    *rt = pRateTable;

    rc_sched.probe_rix = probe_rix;

    /* set short preamble for CCK rates if applicable. 
       TODO: add barker preamble check here 
    */
    rc_sched.sh_pream = (rc_sched.rix[0]<(OFDM_RATE_TABLE_INDEX  - 1)) ? shortPreamble:0;

    ratectrl_update_rate_sched(an, &rc_sched, pkt_info_rcf);

    return TRUE;
}

void _RATE_SetHTConnCap(struct rate_node *pSib, A_UINT32 htCap)
{
    struct TxRateCtrl_s *pRc        = pSib->txRateCtrl;

    if( htCap & IEEE80211_HTCAP_C_SHORTGI20 ) {
        pRc->htSgiValid |= TX_RATE_SGI_20;
    }

    if( htCap & IEEE80211_HTCAP_C_SHORTGI40 ) {
        pRc->htSgiValid |= TX_RATE_SGI_40;
    }

    return;
}

void _RATE_SetVHTConnCap(struct rate_node *pSib, A_UINT32 vhtCap)
{
    struct TxRateCtrl_s *pRc        = pSib->txRateCtrl;

    if( vhtCap & IEEE80211_VHTCAP_SHORTGI_80 ) {
        pRc->htSgiValid |= TX_RATE_SGI_80;
    }

    if( vhtCap & IEEE80211_VHTCAP_SHORTGI_160 ) {
        pRc->htSgiValid |= TX_RATE_SGI_160;
    }

    return;
}

void _RATE_SetPwrChainMsk(void *dev, A_UINT32 op, A_UINT32 pream_type,
                         A_UINT32 rate_len, A_UINT32 *ratepwr_chaintbl)
{
#if ATH_TARGET
    A_UINT8 base_idx;
    A_UINT32 phymask, cur_phymask;
    A_UINT16 cur_txchain_msk, cur_rxchain_msk, txchain_msk;
    wlan_pdev_t *pdev = (wlan_pdev_t *) dev;
        
    switch (pream_type) {
        
        case RC_CCK_OFDM_RATES:
             base_idx = RT_CCK_OFDM_RATE_BASE_IDX;
             phymask  = RC_PHYMASK_CCK_OFDM;
             break;

        case RC_HT_RATES:
             base_idx = RT_HT_RATE_BASE_IDX;
             phymask  = RC_PHYMASK_HT;
             break;

        case RC_VHT_RATES:
             base_idx = RT_VHT_RATE_BASE_IDX;
             phymask  = RC_PHYMASK_VHT;
             break;

        default:
             A_ASSERT(0);
             break;
    }
    
    cur_phymask = wal_pdev_get_ratepwr_chainmsk(DEV_GET_WAL_PDEV(pdev));

    if (op) {
        wal_pdev_set_ratepwr_chainmsk(DEV_GET_WAL_PDEV(pdev), (cur_phymask | phymask), 
                                      base_idx, rate_len, ratepwr_chaintbl);
        if(pream_type == RC_CCK_OFDM_RATES){
            /* set chainmsk for ack/cts in register */
           wal_rc_get_hw_chainmasks(DEV_GET_WAL_PDEV(pdev), &cur_txchain_msk, 
                                    &cur_rxchain_msk);
           txchain_msk = ratepwr_chaintbl[base_idx] & WHAL_RC_FLAG_CHAIN_MASK;
            if(txchain_msk != cur_txchain_msk){
               wal_rc_set_hw_chainmasks(DEV_GET_WAL_PDEV(pdev), txchain_msk, 
                                        cur_rxchain_msk);
               wal_dev_reset(DEV_GET_WAL_PDEV(pdev));
            }
        }
    } else {
        wal_pdev_set_ratepwr_chainmsk(DEV_GET_WAL_PDEV(pdev), (cur_phymask & ~phymask), 
                                      0, 0, NULL);
    }
#endif
}

#ifdef NUM_SYMBOLS_PER_USEC
#undef NUM_SYMBOLS_PER_USEC
#endif
#define NUM_SYMBOLS_PER_USEC(_u) (((_u)+ 3) >> 2)

#ifdef NUM_SYMBOLS_PER_USEC_HALFGI
#undef NUM_SYMBOLS_PER_USEC_HALFGI
#endif
#define NUM_SYMBOLS_PER_USEC_HALFGI(_u) (((_u)*5 + 17)/18)

#ifdef ATH_AGGR_MINPLEN
#undef ATH_AGGR_MINPLEN
#endif
#define ATH_AGGR_MINPLEN 256


#define BITS_PER_BYTE 8
#define BITS_PER_BYTE_SHIFT 3
#define ATH_AGGR_DELIM_SZ 4
#define ATH_AGGR_DELIM_SZ_SHIFT 2
#define ATH_AGGR_GET_NDELIM(_len)                                   \
    (((((_len) + ATH_AGGR_DELIM_SZ) < ATH_AGGR_MINPLEN) ?           \
      (ATH_AGGR_MINPLEN - (_len) - ATH_AGGR_DELIM_SZ) : 0) >> 2)
/* The calculation for this value assumes the following: 
 * mpdudensity = 16 usec (worst case value)
 * raw rate = MCS 7 @ 40 MHz using SGI
 * SGI has 3.6 usec per symbol which translates to 5 symbols in 16 usec
 * MCS 7 @ 40 MHz can produce 540 bits per symbol
 * round up to the nearest byte and done. */
#define MPDU_DENSITY_MAX_FRAME_LEN 338 // (5 symbols * 540 bitspersymbol + 7) / 8   

#define MPDU_DENSITY_MAX_FOR_1   (9)
#define MPDU_DENSITY_MAX_FOR_2   (9)
#define MPDU_DENSITY_MAX_FOR_4  (26)
#define MPDU_DENSITY_MAX_FOR_8  (43)
#define MPDU_DENSITY_MAX_FOR_16 (77)

static const A_UINT8 MPDUDensityMax[17] = 
{
    0,
    MPDU_DENSITY_MAX_FOR_1,
    MPDU_DENSITY_MAX_FOR_2,
    MPDU_DENSITY_MAX_FOR_4,
    MPDU_DENSITY_MAX_FOR_4,
    MPDU_DENSITY_MAX_FOR_8,
    MPDU_DENSITY_MAX_FOR_8,
    MPDU_DENSITY_MAX_FOR_8,
    MPDU_DENSITY_MAX_FOR_8,
    MPDU_DENSITY_MAX_FOR_16,
    MPDU_DENSITY_MAX_FOR_16,
    MPDU_DENSITY_MAX_FOR_16,
    MPDU_DENSITY_MAX_FOR_16,
    MPDU_DENSITY_MAX_FOR_16,
    MPDU_DENSITY_MAX_FOR_16,
    MPDU_DENSITY_MAX_FOR_16,
    MPDU_DENSITY_MAX_FOR_16,       
};


#ifndef DISABLE_RATE_INDIRECTION_TABLE
RATE_API_INDIRECTION_TABLE rateApiIndirectionTable = {
    _RATE_GetTxRetrySchedule,
    _RATE_SetCurmode,
    _RATE_GetRtsCtsRate,
    _RATE_SetHTConnCap,
    _RATE_SetVHTConnCap,
    _RATE_SetRtsCtsRate,
    _RATE_SetRateMask,
    _RATE_SetPwrChainMsk,
};

RATE_INTERNAL_INDIRECTION_TABLE rateInternalIndirectionTable = {
    _rcRateFind,
#if RC_SUPPORT_1D_RATECTRL
    _rcRateFind_1D,
    _rcRateFind_2D,
#endif
    _rcUpdate_HT,
#if RC_SUPPORT_1D_RATECTRL
    _rcUpdate_HT_1D,
    _rcUpdate_HT_2D,
#endif
    _rcSibUpdate,
    _GetRateTblAndIndex,
    _RateValidCheck,
    _rcGetNextValidTxRate,
    _rcGetNextLowerValidTxRate,
    _rcGetLowerValid,
    _RateValidCheckNodeFlags,
    _rcSortValidRates,
    _GetLSB,
    _GetMSB,
    _rate_setup,
    _GetBestRate,
    _GetBestRate_2D,
    _RateCheckDefaultMCSMask,
    _RateValidateRateSet,
#ifdef SMART_ANTENNA
    _RateFillValidRatecodeList,
    _RATEGetRateSchedFlags,
#endif
    _rcGetValidTxRateMaxMcs,
    _rcUpdatePer_2D,
};

#endif /* DISABLE_RATE_INDIRECTION_TABLE */
