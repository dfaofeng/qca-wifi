/*
* Copyright (c) 2013 Qualcomm Atheros, Inc..
* All Rights Reserved.
* Qualcomm Atheros Confidential and Proprietary.
*/

#ifndef __IF_SMARTANETNNA_H__
#define __IF_SMARTANETNNA_H__

#if UNIFIED_SMARTANTENNA

#define SMART_ANT_STATE_INIT_DONE 0x01
#define SMART_ANT_STATE_DEINIT_DONE 0x20
#define SMART_ANT_STATE_DEFAULT 0x00

#define SMART_ANT_RECONFIGURE 0
#define SMART_ANT_NEW_CONFIGURATION 1

/* SMART_ANT_STA_NOT_CONNECTED when set in new_init
 * argument of ieee80211_smart_ant_init(), channel 0
 * needs to be configured to help scanning.
 */
#define SMART_ANT_STA_NOT_CONNECTED 2
#define SMART_ANT_INTERFACE_ID_SHIFT 4

#define SMART_ANT_MODE_SERIAL   0
#define SMART_ANT_MODE_PARALLEL 1 

#define AR600P_ASSEMBLE_HW_RATECODE(_rate, _nss, _pream) \
    (((_pream) << 6) | ((_nss) << 4) | (_rate))
#define MAX_OFDM_CCK_RATES 12

#define HT_RATE_FLAG 0x80
#define HT_RATE_MASK 0x7f
#define HT_NSS_MASK 070
#define HT_NSS_SHIFT 3
#define HT_MCS_MASK 0x7
#define AR600P_PREAMBLE_HT 2

#define VHT_PREAMBLE_MASK 0xc0
#define VHT_NSS_MASK      0x30
#define VHT_NSS_SHIFT     4
#define VHT_MCS_MASK      0x0f
#define VHT_MCS_SHIFT     6

#define OPMODE_VHT 2
#define OPMODE_HT 1
#define OPMODE_CCK_OFDM 0

#define RATE_INDEX_CCK_OFDM 0
#define RATE_INDEX_BW20 1
#define RATE_INDEX_BW40 2

#define RADIO_ID_DIRECT_ATTACH  0
#define RADIO_ID_OFF_LOAD  1

#define FALL_BACK_RATES_DIRECT_ATTACH 3
#define FALL_BACK_RATES_OFF_LOAD 1

#define SA_PARM_TYPE_MASK 0xffff0000
#define SA_PARM_TYPE_SHIFT 24

inline int ieee80211_smart_ant_init( struct ieee80211com *ic, struct ieee80211vap *vap, int new_init);
inline int ieee80211_smart_ant_deinit( struct ieee80211com *ic, struct ieee80211vap *vap, int notify);
inline void ieee80211_smart_ant_node_connect(struct ieee80211_node *ni, struct sa_rate_cap *rate_cap);
inline void ieee80211_smart_ant_node_disconnect(struct ieee80211_node *ni);
inline int ieee80211_smart_ant_update_txfeedback(struct ieee80211_node *ni, void *tx_feedback);
inline int ieee80211_smart_ant_update_rxfeedback(struct ieee80211_node *ni, void *rx_feedback);
inline int ieee80211_smart_ant_get_bcn_txantenna(struct ieee80211com *ic, u_int32_t *bcn_txant);
inline int ieee80211_smart_ant_channel_change(struct ieee80211com *ic);
inline int ieee80211_smart_ant_set_param( struct ieee80211com *ic, char *params);
inline int ieee80211_smart_ant_get_param( struct ieee80211com *ic, char *params);

void __ieee80211_smart_ant_node_disconnect(struct ieee80211_node *ni);
void __ieee80211_smart_ant_node_connect(struct ieee80211_node *ni, struct sa_rate_cap *rate_cap);
int __ieee80211_smart_ant_init( struct ieee80211com *ic, struct ieee80211vap *vap, int new_init);
int __ieee80211_smart_ant_deinit( struct ieee80211com *ic, struct ieee80211vap *vap, int notify);
int __ieee80211_smart_ant_update_txfeedback(struct ieee80211_node *ni, void *tx_feedback);
int __ieee80211_smart_ant_update_rxfeedback(struct ieee80211_node *ni, void *rx_feedback);
int __ieee80211_smart_ant_get_bcn_txantenna(struct ieee80211com *ic, u_int32_t *bcn_txant);
int __ieee80211_smart_ant_get_rxantenna(struct ieee80211com *ic, uint32_t *rx_ant);
inline uint32_t ieee80211_smart_ant_convert_rate_5g(uint32_t rate_code);
inline uint32_t ieee80211_smart_ant_convert_rate_2g(uint32_t rate_code);
int __ieee80211_smart_ant_channel_change(struct ieee80211com *ic);
int ieee80211_smart_ant_cwm_action(struct ieee80211com *ic);
int __ieee80211_smart_ant_set_param( struct ieee80211com *ic, char *params);
int __ieee80211_smart_ant_get_param( struct ieee80211com *ic, char *params);

#else
static inline int ieee80211_smart_ant_get_bcn_txantenna(struct ieee80211com *ic, u_int32_t *bcn_txant)
{
    *bcn_txant = 0xffffffff;
    return 0;
}
static inline int ieee80211_smart_ant_cwm_action(struct ieee80211com *ic)
{
    return 0;
}

#endif

#endif
