/*
 * @@-COPYRIGHT-START-@@
 *
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 *
 * @@-COPYRIGHT-END-@@
 */

#ifndef _IF_ATH_AIRTIME_FAIRNESS_H
#define _IF_ATH_AIRTIME_FAIRNESS_H

#include "ath_timer.h"

void ath_atf_sc_update_node_txtoken(struct ath_node *an, u_int32_t val );
void ath_atf_sc_get_unused_txtoken(struct ath_node *an, u_int32_t *unused_token);

int
ath_atf_check_txtokens(struct ath_softc *sc, struct ath_buf *bf, ath_atx_tid_t *tid);
void
ath_atf_node_airtime_consumed( struct ath_softc *sc, struct ath_buf *bf, struct ath_tx_status *ts, int txok);

void ath_atf_sc_set(struct ath_softc *sc, u_int32_t enable );
void ath_atf_sc_clear(struct ath_softc *sc, u_int32_t disable );
u_int32_t ath_calc_ack_duration(struct ath_softc *sc, u_int8_t cix);
u_int32_t ath_get_retries_num(struct ath_buf *bf, u_int32_t rateindex, u_int32_t retries);

#endif //_IF_ATH_AIRTIME_FAIRNESS_H

