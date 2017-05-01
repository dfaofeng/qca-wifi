/*
 * @@-COPYRIGHT-START-@@
 *
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 *
 * @@-COPYRIGHT-END-@@
 */

/*
 LMAC - Air Time Fairness module
*/
#if QCA_AIRTIME_FAIRNESS

#include <osdep.h>
#include "ath_internal.h"
#include "ath_dev.h"
#include "ieee80211_var.h"
#include "ath_airtime_fairness.h"

/* definitions */
#define OFDM_SIFS_TIME  16
#define OFDM_SLOT_TIME  9
#define OFDM_DIFS_TIME  34 /*(16+2*9)*/
#define ACK_LENGTH  14

#define BACKOFF_SLOT_MAX 1024
#define BACKOFF_SLOT_MIN_OFFSET 5

/* extern declaration */
extern u_int32_t
ath_buf_get_ba_period(struct ath_softc *sc, struct ath_buf *bf);

/*
 * Function     : ath_atf_sc_set
 * Description  : enable ATF
 * Input        : Pointer to sc, enable/disable
 * Output       : Void
 *
 */
void ath_atf_sc_set(struct ath_softc *sc, u_int32_t enable )
{
    sc->sc_atf_enable = 1;
}

/*
 * Function     : ath_atf_sc_clear
 * Description  : disable ATF
 * Input        : Pointer to sc, disable/enable
 * Output       : Void
 *
 */
void ath_atf_sc_clear(struct ath_softc *sc, u_int32_t disable )
{
    sc->sc_atf_enable = 0;
}

void ath_atf_sc_get_unused_txtoken(struct ath_node *an, u_int32_t *unused_token )
{
    *unused_token = an->an_atf_txtoken;
}

/*
 * Function     : ath_atf_sc_update_node
 * Description  : Update atf_units in the node structure
                  Any excess air time consumed (actual tx time > estimated tx duration),
                  will be deducted during the update
 * Input        : Pointer to node, atf_unit
 * Output       : Void
 *
 */
void ath_atf_sc_update_node_txtoken(struct ath_node *an, u_int32_t txtoken )
{
    if(an == NULL)
    {
        return;
    }

    ATH_NODE_ATF_TOKEN_LOCK(an);

    if ( an->an_atf_less_consumed )
    {
        /* TO DO - limit the number of such consecutive attempts.
           If not, the other nodes might not get its due airtime */
        txtoken += an->an_atf_less_consumed;
        an->an_atf_less_consumed = 0;
    }

    if ( an->an_atf_excess_consumed )
    {
        if(an->an_atf_excess_consumed  <= txtoken)
        {
            txtoken = txtoken - an->an_atf_excess_consumed;
            an->an_atf_excess_consumed = 0;
        }
        else
        {
            an->an_atf_excess_consumed -= txtoken;
            txtoken = 0;
        }

    }
    an->an_atf_txtoken = txtoken;
    ATH_NODE_ATF_TOKEN_UNLOCK(an);

    /* Resume the node, if paused */
    if (an->an_atf_nodepaused && an->an_atf_txtoken)
    {
        ath_tx_node_resume(an->an_sc, an);
        ATH_NODE_ATF_TOKEN_LOCK(an);
        an->an_atf_nodepaused = 0;
        ATH_NODE_ATF_TOKEN_UNLOCK(an);
    }
}

/*
 * Function     : ath_atf_check_txtokens
 * Description  : Estimate the tx packet duration.
                  Transmit the packet if the estimated duration < txtokens
                  Queue the packet back to tidq otherwise
 * Input        : Pointer to node, ath_buf, tid
 * Output       : 0 or 1
 */
int
ath_atf_check_txtokens(struct ath_softc *sc, struct ath_buf *bf, ath_atx_tid_t *tid)
{
    struct ath_node   *node = NULL;
    u_int32_t  pkt_duration = 0, i, txtokens=0, ack_duration = 0, pkt_overhead = 0;
    u_int8_t rix = 0, cix = 0;
    struct ieee80211_node *ni;
    HAL_TXQ_INFO qi;
    const HAL_RATE_TABLE *rt;

    rt = sc->sc_currates;

    node = tid->an;
    ni = (struct ieee80211_node *)node->an_node;

    // check token availability
    if( (tid->tidno != WME_MGMT_TID)  && (ni != ni->ni_bss_node) )
    {
        ATH_NODE_ATF_TOKEN_LOCK(tid->an);
        txtokens = node->an_atf_txtoken;
        ATH_NODE_ATF_TOKEN_UNLOCK(tid->an);
        if( txtokens )
        {
            for (i = 0; i < 4; i++) {
                if (bf->bf_rcs[i].tries) {
                    rix = bf->bf_rcs[i].rix;
                    break;
                }
            }
            /* Highly unlikely case, where 'tries' for all mcs rates are set to '0'*/
            if(i == 4) {
                return 1;
            }

            pkt_duration = ath_pkt_duration( sc, rix, bf,
                                            (bf->bf_rcs[i].flags & ATH_RC_CW40_FLAG) != 0,
                                            (bf->bf_rcs[i].flags & ATH_RC_SGI_FLAG),
                                            bf->bf_shpreamble);
            cix = rt->info[rix].controlRate;
            ath_hal_gettxqueueprops(sc->sc_ah, bf->bf_qnum, &qi);
            if( bf->bf_isaggr )
            {
                ack_duration = ath_buf_get_ba_period(sc, bf);
            }
            else
            {
                ack_duration = ath_calc_ack_duration(sc, cix);
            }

            pkt_overhead = OFDM_SIFS_TIME + (qi.tqi_aifs * OFDM_SLOT_TIME) + ((qi.tqi_cwmin/2) * OFDM_SLOT_TIME) + ack_duration;
            pkt_duration += pkt_overhead;

            if(pkt_duration <= node->an_atf_txtoken)
            {

                txtokens -= pkt_duration;

                ATH_NODE_ATF_TOKEN_LOCK(tid->an);
                node->an_atf_txtoken = txtokens;
                ATH_NODE_ATF_TOKEN_UNLOCK(tid->an);

                /*  Update ath_buf with the estimated packet duration.
                    This will be compared with the actual packet duration in txcompletion path
                 */
                bf->bf_tx_airtime = pkt_duration;

                return 0;
            }
            else
            {
                /* Pause node & set atf falg */
                if (!tid->an->an_atf_nodepaused)
                {
                    ath_tx_node_pause_nolock(sc, tid->an);
                    ATH_NODE_ATF_TOKEN_LOCK(tid->an);
                    tid->an->an_atf_nodepaused = 1;
                    ATH_NODE_ATF_TOKEN_UNLOCK(tid->an);
                }
                return 1;
            }
        }
        else
        {
            /* Pause node & set atf falg */
            if (!tid->an->an_atf_nodepaused)
            {
                ath_tx_node_pause_nolock(sc, tid->an);
                ATH_NODE_ATF_TOKEN_LOCK(tid->an);
                tid->an->an_atf_nodepaused = 1;
                ATH_NODE_ATF_TOKEN_UNLOCK(tid->an);
            }
            return 1;
        }
    }
    return 0;
}

/*
 * Function     : ath_atf_node_airtime_consumed
 * Description  : Calculate actual airtime used
                  Compare with the duration estimated during transmit
                  If 'actual airtime > estimated duration', update node_deficit.
                  node_deficit will be deducted from the node tokens at the next token update cycle
 * Input        : Pointer to sc, ath_buf, tid, txstatus, status
 * Output       : 0 or 1
 */
void
ath_atf_node_airtime_consumed( struct ath_softc *sc, struct ath_buf *bf, struct ath_tx_status *ts, int txok)
{
    u_int32_t nframes=0, actual_pkt_duration=0, duration_per_try = 0, ack_duration = 0, pkt_overhead = 0;
    u_int32_t rateindex=0, tries = 0, totalretries = 0, backoff = 0, backoff_duration = 0;
    int i=0;
    u_int8_t rix = 0, cix = 0, rc;
    struct ieee80211_node *ni;
    struct ath_node *an = bf->bf_node;
    const HAL_RATE_TABLE    *rt = sc->sc_currates;
    HAL_TXQ_INFO qi;

    ni = (struct ieee80211_node *)an->an_node;
    if( (bf->bf_tidno != WME_MGMT_TID)  && (ni != ni->ni_bss_node) )// Hack to identify Data packet
    {
        nframes = bf->bf_nframes;

        /* get the actual transmission rate & retries from the descriptor
           calculate packet duration
           Compare with the estimated packet duration
        */
        rateindex = ts->ts_rateindex;
        tries = ts->ts_longretry;
        i = rateindex;
        /*Compute the actual packet duration based on the rateindex & tries */
        for( ;i>=0 && i<4; i--)
        {
            rix = bf->bf_rcs[i].rix;
            rc = rt->info[rix].rate_code;
            duration_per_try = ath_pkt_duration( sc, rix, bf,
                                        (bf->bf_rcs[i].flags & ATH_RC_CW40_FLAG) != 0,
                                        (bf->bf_rcs[i].flags & ATH_RC_SGI_FLAG),
                                        bf->bf_shpreamble);
            if(i == rateindex)
            {
                cix = rt->info[rix].controlRate;
                ath_hal_gettxqueueprops(sc->sc_ah, bf->bf_qnum, &qi);
                if( bf->bf_isaggr )
                {
                    ack_duration = ath_buf_get_ba_period(sc, bf);
                }
                else
                {
                    ack_duration = ath_calc_ack_duration(sc, cix);
                }

                pkt_overhead = OFDM_SIFS_TIME + (qi.tqi_aifs * OFDM_SLOT_TIME) + ((qi.tqi_cwmin/2) * OFDM_SLOT_TIME) + ack_duration;

                /* account for retries in the final transmission series
                   account the duration for successful transmission also */
                actual_pkt_duration += ( duration_per_try + pkt_overhead + ((duration_per_try + OFDM_SIFS_TIME ) * tries));
            }
            else
            {
                /* failed rate series */
                actual_pkt_duration += ( (duration_per_try + OFDM_SIFS_TIME) * bf->bf_rcs[i].tries) ;
            }
        }

        /* If there were retries, account backoff time for each retry */
        totalretries = ath_get_retries_num(bf, rateindex, tries);
        if(totalretries)
        {
            for(i=0; i < totalretries; i++)
            {
                backoff = ((1 << (BACKOFF_SLOT_MIN_OFFSET + i)) - 1);
                if(backoff >= (BACKOFF_SLOT_MAX - 1) )
                    backoff = (BACKOFF_SLOT_MAX - 1);

                backoff = backoff * OFDM_SLOT_TIME;
                backoff_duration += backoff;
            }
            actual_pkt_duration += backoff_duration;
        }

        ATH_NODE_ATF_TOKEN_LOCK(an);
        if ( actual_pkt_duration > bf->bf_tx_airtime )
        {
            an->an_atf_excess_consumed += (actual_pkt_duration - bf->bf_tx_airtime );
        }
        else if( actual_pkt_duration < bf->bf_tx_airtime )
        {
            an->an_atf_less_consumed += ( bf->bf_tx_airtime - actual_pkt_duration );
        }
        ATH_NODE_ATF_TOKEN_UNLOCK(an);
    }
}

/*
 * Function     : ath_atf_ath_calc_ack_duration
 * Description  : Calculate airtime for ACK
                  Note that ACKs will be sent at the legacy rate.
 * Input        : Pointer to sc, control rate index
 * Output       : duration
 */
u_int32_t ath_calc_ack_duration(struct ath_softc *sc, u_int8_t cix)
{
#define CCK_PREAMBLE_BITS   144
#define CCK_PLCP_BITS        48

    const HAL_RATE_TABLE *rt;
    u_int32_t ack_len = ACK_LENGTH;
    u_int32_t nsymbits = 0, nbits =0, nsymbols = 0, duration = 0,phyTime=0;

    rt = sc->sc_currates;

    switch (rt->info[cix].rate_code) {
    case 0x0b: /* 6 Mb OFDM */
        nsymbits = 24 ;
        break;
    case 0x0a: /* 12 Mb OFDM */
        nsymbits = 48;
        break;
    case 0x09: /* 24 Mb OFDM */
        nsymbits = 96;
        break;
    case 0x1b:
    case 0x1a:
    case 0x19:
    case 0x18:
        /* CCK */
        phyTime  = CCK_PREAMBLE_BITS + CCK_PLCP_BITS;
        nbits    = ack_len << 3;
        duration =  phyTime + (( nbits * 1000) / rt->info[cix].rateKbps);
#undef CCK_PREAMBLE_BITS
#undef CCK_PLCP_BITS
        return duration;
    default:
        printk("%s() - Invalid ratecode %d \n\r",__func__, rt->info[cix].rate_code);
        return 0;
    }

    /*
     * find number of symbols: PLCP + data
     */
    nbits = (ack_len << 3) + OFDM_PLCP_BITS;
    nsymbols = nbits / nsymbits;

    duration = SYMBOL_TIME(nsymbols);

    duration += L_STF + L_LTF + L_SIG;

    return duration;
}

u_int32_t ath_get_retries_num(struct ath_buf *bf, u_int32_t rateindex, u_int32_t retries)
{
    u_int32_t totalretries = 0;
    switch (rateindex)
    {
        case 0:
            totalretries = retries;
            break;
        case 1:
            totalretries = retries + bf->bf_rcs[0].tries;
            break;
        case 2:
            totalretries = retries + bf->bf_rcs[1].tries +
                          bf->bf_rcs[0].tries;
            break;
        case 3:
            totalretries = retries + bf->bf_rcs[2].tries +
                          bf->bf_rcs[1].tries + bf->bf_rcs[0].tries;
            break;
        default:
            printk("Invalid rateindex \n\r");
    }
    return totalretries;
}

OS_EXPORT_SYMBOL(ath_atf_node_airtime_consumed);
#endif

