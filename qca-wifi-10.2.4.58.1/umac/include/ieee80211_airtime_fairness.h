/*
 * @@-COPYRIGHT-START-@@
 *
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 *
 * @@-COPYRIGHT-END-@@
 */
#if QCA_AIRTIME_FAIRNESS
#ifndef _UMAC_AIRTIME_FAIRNESS_PRIV__
#define _UMAC_AIRTIME_FAIRNESS_PRIV__

#define ATF_TOKEN_INTVL_MS      200 /* 200 msec */
#define WMI_ATF_DENOMINATION    1000

#define ATF_DATA_LOG_SIZE                   5  /* Minimum Data log (history) required for ATF Fairqueuing algo */
#define ATF_UNUSEDTOKENS_BORROW_THRESHOLD   20 /* Any node with ununsed token percent (avg) less than this value will have borrow enabled */
#define ATF_RESERVERD_TOKEN_PERCENT         2  /* Minimum token (percent) reserved for a node even when it is idle */
#define ATF_RESERVED_UNALLOTED_TOKEN_PERCENT    10 /* Minimum unalloted token (percent) reserved */

struct ieee80211com;
struct ieee80211vap;

void ieee80211_atf_attach(struct ieee80211com *ic);
int ieee80211_atf_detach(struct ieee80211com *ic);
void ieee80211_atf_node_join_leave(struct ieee80211_node *ni,const u_int8_t type);
int ieee80211_atf_set(struct ieee80211vap *vap, u_int8_t enable);
int ieee80211_atf_clear(struct ieee80211vap *vap, u_int8_t enable);
#endif
#endif
