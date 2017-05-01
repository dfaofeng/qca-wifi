/*
 * Copyright (c) 2011-2014, Atheros Communications Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * Radio interface configuration routines for perf_pwr_offload 
 */
#include <osdep.h>
#include "ol_if_athvar.h"
#include "ol_if_athpriv.h"
#include "ath_ald.h"
#include <osif_private.h>
#define IF_ID_OFFLOAD (1)
#if ATH_PERF_PWR_OFFLOAD

#if ATH_SUPPORT_HYFI_ENHANCEMENTS
/* Do we need to move these to some appropriate header */
void ol_ath_set_hmmc_tid(struct ieee80211com *ic , u_int32_t tid);
void ol_ath_set_dscp_override(struct ieee80211com *ic , u_int32_t val);
void ol_ath_set_hmmc_dscp_override(struct ieee80211com *ic , u_int32_t val);

u_int32_t ol_ath_get_dscp_tid_map(struct ieee80211com *ic, u_int8_t tos);
u_int32_t ol_ath_get_hmmc_tid(struct ieee80211com *ic);
u_int32_t ol_ath_get_dscp_override(struct ieee80211com *ic);
u_int32_t ol_ath_get_hmmc_dscp_override(struct ieee80211com *ic);
#endif
void ol_ath_reset_vap_stat(struct ieee80211com *ic);

#if UMAC_SUPPORT_PERIODIC_PERFSTATS

static void ol_ath_net80211_set_prdperfstat_thrput_enab(struct ieee80211com *ic, u_int32_t enab)
{
    int ret = -1;

    IEEE80211_PRDPERFSTATS_THRPUT_LOCK(ic);

    if (enab != ic->ic_thrput.is_enab) {
        if (enab) {
            ret = ieee80211_prdperfstat_thrput_enable(ic);

            if (ret < 0) {
                IEEE80211_PRDPERFSTATS_THRPUT_UNLOCK(ic);
                return;
            }
        } else {
                ieee80211_prdperfstat_thrput_disable(ic);
        }
    }
            
    IEEE80211_PRDPERFSTATS_THRPUT_UNLOCK(ic);

    /* Signal Periodic Stats framework that there has been a status change */
    IEEE80211_PRDPERFSTATS_LOCK(ic);
    ieee80211_prdperfstats_signal(ic);
    IEEE80211_PRDPERFSTATS_UNLOCK(ic);
}

static u_int32_t ol_ath_net80211_get_prdperfstats_thrput_enab(struct ieee80211com *ic)
{
    return ic->ic_thrput.is_enab;
}

static void ol_ath_net80211_set_prdperfstat_thrput_win(struct ieee80211com *ic, u_int32_t window)
{
    IEEE80211_PRDPERFSTATS_THRPUT_LOCK(ic);
    if (ic->ic_thrput.is_enab) {
        IEEE80211_PRDPERFSTATS_DPRINTF("Cannot set Throughput Measurement Window "
                                           "when measurement is already enabled.\n"
                                          "Please disable measurement first.\n");
        IEEE80211_PRDPERFSTATS_THRPUT_UNLOCK(ic);
        return;
    }

    if (window < PRDPERFSTAT_THRPUT_MIN_WINDOW_MS ||
                                  window > PRDPERFSTAT_THRPUT_MAX_WINDOW_MS) {
        IEEE80211_PRDPERFSTATS_DPRINTF("Invalid value %u for Throughput Measurement Window. "
                                                    "Min:%u Max:%u\n",
                                                    window,
                                                    PRDPERFSTAT_THRPUT_MIN_WINDOW_MS,
                                                    PRDPERFSTAT_THRPUT_MAX_WINDOW_MS);
        IEEE80211_PRDPERFSTATS_THRPUT_UNLOCK(ic);
        return;
    }

    if (window % PRDPERFSTAT_THRPUT_INTERVAL_MS) {
          IEEE80211_PRDPERFSTATS_DPRINTF("Invalid value %u for Throughput Measurement Window. "
                                                         "Must be a multiple of %u ms. \n",
                                                            window,
                                                   PRDPERFSTAT_THRPUT_INTERVAL_MS);
        IEEE80211_PRDPERFSTATS_THRPUT_UNLOCK(ic);
        return;
   }

    ic->ic_thrput.histogram_size = window / PRDPERFSTAT_THRPUT_INTERVAL_MS;

    IEEE80211_PRDPERFSTATS_THRPUT_UNLOCK(ic);
}

static u_int32_t ol_ath_net80211_get_prdperfstat_thrput_win(struct ieee80211com *ic)
{
    return ic->ic_thrput.histogram_size * PRDPERFSTAT_THRPUT_INTERVAL_MS;
}
static u_int32_t ol_ath_net80211_get_prdperfstat_thrput(struct ieee80211com *ic)
{
    u_int32_t   val = 0;
    IEEE80211_PRDPERFSTATS_THRPUT_LOCK(ic);
    val = ieee80211_prdperfstat_thrput_get(ic);
    IEEE80211_PRDPERFSTATS_THRPUT_UNLOCK(ic);

    return val;
}

static void ol_ath_net80211_set_prdperfstat_per_enab(struct ieee80211com *ic, u_int32_t enab)
{
    int ret = -1;

    IEEE80211_PRDPERFSTATS_PER_LOCK(ic);

    if (enab != ic->ic_per.is_enab) {
        if (enab) {
            ret = ieee80211_prdperfstat_per_enable(ic);

            if (ret < 0) {
                IEEE80211_PRDPERFSTATS_PER_UNLOCK(ic);
                return;
            }
        } else {
            ieee80211_prdperfstat_per_disable(ic);
        }
    }
    IEEE80211_PRDPERFSTATS_PER_UNLOCK(ic);

    /* Signal Periodic Stats framework that there has been a status change */
    IEEE80211_PRDPERFSTATS_LOCK(ic);
    ieee80211_prdperfstats_signal(ic);
    IEEE80211_PRDPERFSTATS_UNLOCK(ic);
}

static u_int32_t ol_ath_net80211_get_prdperfstat_per_enab(struct ieee80211com *ic)
{
    return ic->ic_per.is_enab;
}

static void ol_ath_net80211_set_prdperfstat_per_win(struct ieee80211com *ic, u_int32_t window)
{

    IEEE80211_PRDPERFSTATS_PER_LOCK(ic);
    
    if (ic->ic_per.is_enab) {
            IEEE80211_PRDPERFSTATS_DPRINTF("Cannot set PER Measurement Window "
                                   "when measurement is already enabled.\n"
                                  "Please disable measurement first.\n");
        IEEE80211_PRDPERFSTATS_PER_UNLOCK(ic);
        return;
    }

    if (window < PRDPERFSTAT_PER_MIN_WINDOW_MS ||
          window > PRDPERFSTAT_PER_MAX_WINDOW_MS) {
        IEEE80211_PRDPERFSTATS_DPRINTF("Invalid value %u for PER Measurement Window. "
                                                  "Min:%u Max:%u\n",
                                                          window,
                                        PRDPERFSTAT_PER_MIN_WINDOW_MS,
                                        PRDPERFSTAT_PER_MAX_WINDOW_MS);
        IEEE80211_PRDPERFSTATS_PER_UNLOCK(ic);
        return;
    }

    if (window % PRDPERFSTAT_PER_INTERVAL_MS) {
        IEEE80211_PRDPERFSTATS_DPRINTF("Invalid value %u for PER Measurement Window. "
                                        "Must be a multiple of %u ms. \n",
                                                                window,
                                        PRDPERFSTAT_PER_INTERVAL_MS);
        IEEE80211_PRDPERFSTATS_PER_UNLOCK(ic);
        return;
    }

    ic->ic_per.histogram_size = window / PRDPERFSTAT_PER_INTERVAL_MS;

    IEEE80211_PRDPERFSTATS_PER_UNLOCK(ic);

}

static u_int32_t ol_ath_net80211_get_prdperfstat_per_win(struct ieee80211com *ic)
{
    return ic->ic_per.histogram_size * PRDPERFSTAT_PER_INTERVAL_MS;
}

static u_int32_t ol_ath_net80211_get_prdperfstat_per(struct ieee80211com *ic)
{
    u_int32_t   val = 0;
    
    IEEE80211_PRDPERFSTATS_PER_LOCK(ic);
    val = ieee80211_prdperfstat_per_get(ic);
    IEEE80211_PRDPERFSTATS_PER_UNLOCK(ic);

    return val;
}

#endif /* UMAC_SUPPORT_PERIODIC_PERFSTATS */

static u_int32_t ol_ath_net80211_get_total_per(struct ieee80211com *ic)
{
    /* TODO: Receive values as u_int64_t and handle the division */
    u_int32_t failures = ic->ic_get_tx_hw_retries(ic);
    u_int32_t success  = ic->ic_get_tx_hw_success(ic);

    if ((success + failures) == 0) {
    return 0;
    }   

    return ((failures * 100) / (success + failures));
}

static int
ol_ath_validate_rx_decap_mode(u_int32_t val)
{
#if !QCA_OL_SUPPORT_RAWMODE_TXRX
    if (val == 0) {
        printk("Valid values: 1 - Native Wi-Fi, 2 - Ethernet\n"
               "0 - RAW is unavailable\n");
        return 0;
    }
#endif

    if (val <= 2) {
        return 1;
    } else {
        printk("Valid values: 0 - RAW, 1 - Native WiFi, 2 - Ethernet, "
               "%d is invalid\n", val);
        return 0;
    }
}

int
ol_ath_set_config_param(struct ol_ath_softc_net80211 *scn, ol_ath_param_t param, void *buff)
{
    int retval = 0;
    u_int32_t value = *(u_int32_t *)buff, param_id;
    struct ieee80211com *ic = &scn->sc_ic;
#if ATH_SUPPORT_HYFI_ENHANCEMENTS
	int thresh = 0;
#endif

    switch(param)
    {
        case OL_ATH_PARAM_TXCHAINMASK:
        {
            u_int8_t cur_mask = ieee80211com_get_tx_chainmask(ic);
            if (!value) {
                /* value is 0 - set the chainmask to be the default 
                 * supported tx_chain_mask value 
                 */
                retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                             WMI_PDEV_PARAM_TX_CHAIN_MASK, 
                             scn->wlan_resource_config.tx_chain_mask);
                if (retval == EOK) {
                    /* Update the ic_chainmask */
                    ieee80211com_set_tx_chainmask(ic, 
                        (u_int8_t) (scn->wlan_resource_config.tx_chain_mask));
                }
            }
            else if (cur_mask != value) {
                /* Update chainmask only if the current chainmask is different */
                if (value > scn->wlan_resource_config.tx_chain_mask) {
                    printk("ERROR - value is greater than supported chainmask 0x%x \n",
                            scn->wlan_resource_config.tx_chain_mask);
                    return -1;
                }
                retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                             WMI_PDEV_PARAM_TX_CHAIN_MASK, value);
                if (retval == EOK) {
                    /* Update the ic_chainmask */
                    ieee80211com_set_tx_chainmask(ic, (u_int8_t) (value));
                }
                /* FIXME - Currently the assumption is no active vaps 
                 * when executing this command 
                 * Need to restart all the active VAPs
                 */
            }
        }
        break;
#if ATH_SUPPORT_HYFI_ENHANCEMENTS

		case OL_ATH_PARAM_HMMC_DSCP_TID_MAP:
			ol_ath_set_hmmc_tid(ic,value);
		break;
	
		case OL_ATH_PARAM_DSCP_OVERRIDE:
			ol_ath_set_dscp_override(ic,value);
		break;

		case OL_ATH_PARAM_HMMC_DSCP_OVERRIDE:
			ol_ath_set_hmmc_dscp_override(ic,value);
        break;
#endif
        case OL_ATH_PARAM_RXCHAINMASK:
        {
            u_int8_t cur_mask = ieee80211com_get_rx_chainmask(ic);
            if (!value) {
                /* value is 0 - set the chainmask to be the default 
                 * supported rx_chain_mask value 
                 */
                retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                             WMI_PDEV_PARAM_RX_CHAIN_MASK, 
                             scn->wlan_resource_config.rx_chain_mask);
                if (retval == EOK) {
                    /* Update the ic_chainmask */
                    ieee80211com_set_rx_chainmask(ic, 
                        (u_int8_t) (scn->wlan_resource_config.rx_chain_mask));
                }
            }
            else if (cur_mask != value) {
                /* Update chainmask only if the current chainmask is different */
                if (value > scn->wlan_resource_config.rx_chain_mask) {
                    printk("ERROR - value is greater than supported chainmask 0x%x \n",
                            scn->wlan_resource_config.rx_chain_mask);
                    return -1;
                }
                retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                             WMI_PDEV_PARAM_RX_CHAIN_MASK, value);
                if (retval == EOK) {
                    /* Update the ic_chainmask */
                    ieee80211com_set_rx_chainmask(ic, (u_int8_t) (value));
                }
                /* FIXME - Currently the assumption is no active vaps 
                 * when executing this command 
                 * Need to restart all the active VAPs
                 */
            }
        }
        break;
#if QCA_AIRTIME_FAIRNESS
        case  OL_ATH_PARAM_ATF_STRICT_SCHED:
        {
#define OL_ATH_ATF_SCHED_ENABLE 1
#define OL_ATH_ATF_SCHED_DISABLE 0            
            if ((value != 0) && (value != 1))
            {
                printk("\n ATF Strict Sched value only accept 1 (Enable) or 0 (Disable)!! \n");
                return -1;
            }

            retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                    WMI_PDEV_PARAM_ATF_STRICT_SCH,
                    value);
#undef OL_ATH_ATF_SCHED_ENABLE
#undef OL_ATH_ATF_SCHED_DISABLE
        }
        break;
#endif
        case OL_ATH_PARAM_TXPOWER_LIMIT2G:
        {
            if (!value) {
                value = scn->max_tx_power;
            }
            ic->ic_set_txPowerLimit(ic, value, value, 1);
        }        
        break;
        
        case OL_ATH_PARAM_TXPOWER_LIMIT5G:
        {
            if (!value) {
                value = scn->max_tx_power;
                }
                ic->ic_set_txPowerLimit(ic, value, value, 0);
            }                
        break;

        case OL_ATH_PARAM_RTS_CTS_RATE:
        {
            if(value > 4) {
                printk("Invalid value for setctsrate. Disabling it in Firmware \n");
                value = WMI_FIXED_RATE_NONE;
            }
            scn->ol_rts_cts_rate = value;
            return wmi_unified_pdev_set_param(scn->wmi_handle, WMI_PDEV_PARAM_RTS_FIXED_RATE, value);
        }
        break;

        case OL_ATH_PARAM_DEAUTH_COUNT:
        if(value) {
            scn->scn_user_peer_invalid_cnt = value;
            scn->scn_peer_invalid_cnt = 0;
        }
        break;

            case OL_ATH_PARAM_TXPOWER_SCALE:
        {
            if((WMI_TP_SCALE_MAX <= value) && (value <= WMI_TP_SCALE_MIN))
            {
                scn->txpower_scale = value;
                return wmi_unified_pdev_set_param(scn->wmi_handle,
                    WMI_PDEV_PARAM_TXPOWER_SCALE, value);
            } else {
                retval = -EINVAL;
            }
        }
        break;
        case OL_ATH_PARAM_PS_STATE_CHANGE:
            {
                (void)wmi_unified_pdev_set_param(scn->wmi_handle,  
                                                 WMI_PDEV_PEER_STA_PS_STATECHG_ENABLE, value);
                scn->ps_report = value;
            }
        break;
        case OL_ATH_PARAM_NON_AGG_SW_RETRY_TH:
        {
                return wmi_unified_pdev_set_param(scn->wmi_handle,
                             WMI_PDEV_PARAM_NON_AGG_SW_RETRY_TH, value);
        }
        break;
        case OL_ATH_PARAM_AGG_SW_RETRY_TH:
        {
                return wmi_unified_pdev_set_param(scn->wmi_handle,
                             WMI_PDEV_PARAM_AGG_SW_RETRY_TH, value);
        }
        break; 
        case OL_ATH_PARAM_STA_KICKOUT_TH:
        {
                return wmi_unified_pdev_set_param(scn->wmi_handle,
                             WMI_PDEV_PARAM_STA_KICKOUT_TH, value);
        }
        break; 
        case OL_ATH_PARAM_WLAN_PROF_ENABLE:
        {
                return wmi_unified_wlan_profile_enable(scn->wmi_handle,
                             WMI_WLAN_PROFILE_TRIGGER_CMDID, value);
        }
        break; 
        case OL_ATH_PARAM_BCN_BURST:
        {
                /* value is set to either 1 (bursted) or 0 (staggered).
                 * if value passed is non-zero, convert it to 1 with
                 * double negation 
                 */
                value = !!value;
                if (scn->bcn_mode != (u_int8_t)value) {
                    retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                                 WMI_PDEV_PARAM_BEACON_TX_MODE, value);
                    if (retval == EOK) {
                        scn->bcn_mode = (u_int8_t)value;
                    }
                }
                break;
        }
        break; 
        case OL_ATH_PARAM_ARPDHCP_AC_OVERRIDE:
            if ((WME_AC_BE <= value) && (value <= WME_AC_VO)) {
                scn->arp_override = value;
                retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                    WMI_PDEV_PARAM_ARP_AC_OVERRIDE, value);
            } else {
                retval = -EINVAL;
            }
        case OL_ATH_PARAM_IGMPMLD_OVERRIDE:
            if ((0 == value) || (value == 1)) {
                scn->igmpmld_override = value;
                retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                    WMI_PDEV_PARAM_IGMPMLD_OVERRIDE, value);
            } else {
                retval = -EINVAL;
            }
        break;
        case OL_ATH_PARAM_IGMPMLD_TID:
            if ((0 <= value) && (value <= 7)) {
                scn->igmpmld_tid = value;
                retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                    WMI_PDEV_PARAM_IGMPMLD_TID, value);
            } else {
                retval = -EINVAL;
            }
        break;
        case OL_ATH_PARAM_ANI_ENABLE:
        {
                if (value <= 1) {
                    retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                             WMI_PDEV_PARAM_ANI_ENABLE, value);
                } else {
                    retval = -EINVAL;
                }
                if (retval == EOK) {
                    if (!value) {
                        scn->is_ani_enable = false;
                    } else {
                        scn->is_ani_enable = true;
                    }
                }
        }
        break;
        case OL_ATH_PARAM_ANI_POLL_PERIOD:
        {
                if (value > 0) {
                    return wmi_unified_pdev_set_param(scn->wmi_handle,
                             WMI_PDEV_PARAM_ANI_POLL_PERIOD, value);
                } else {
                    retval = -EINVAL;
                }
        }
        break;
        case OL_ATH_PARAM_ANI_LISTEN_PERIOD:
        {
                if (value > 0) {
                    return wmi_unified_pdev_set_param(scn->wmi_handle,
                             WMI_PDEV_PARAM_ANI_LISTEN_PERIOD, value);
                } else {
                    retval = -EINVAL;
                }
        }
        break;      
        case OL_ATH_PARAM_ANI_OFDM_LEVEL:
        {
                return wmi_unified_pdev_set_param(scn->wmi_handle,
                       WMI_PDEV_PARAM_ANI_OFDM_LEVEL, value);
        }
        break;
        case OL_ATH_PARAM_ANI_CCK_LEVEL:
        {  
                return wmi_unified_pdev_set_param(scn->wmi_handle,
                       WMI_PDEV_PARAM_ANI_CCK_LEVEL, value);    
        }
        break;
        case OL_ATH_PARAM_BURST_DUR:
        {
                if (value > 0 && value <= 8192) {
                    retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                             WMI_PDEV_PARAM_BURST_DUR, value);
                    if (retval == EOK) {
                        scn->burst_dur = (u_int16_t)value;
                    }
                } else {
                    retval = -EINVAL;
                }
        }
        break;

        case OL_ATH_PARAM_BURST_ENABLE:
        {
                if (value == 0 || value ==1) {
                    retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                             WMI_PDEV_PARAM_BURST_ENABLE, value);
		    
                    if (retval == EOK) {
                        scn->burst_enable = (u_int8_t)value;
                    }
		    if(!scn->burst_dur)
		    {
			retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                             WMI_PDEV_PARAM_BURST_DUR, 8160);
			if (retval == EOK) {
			    scn->burst_dur = (u_int16_t)value;
			}			
		    }
                } else {
                    retval = -EINVAL;
                }
        }
        break;

        case OL_ATH_PARAM_DCS:
            {
                value &= OL_ATH_CAP_DCS_MASK;
                if ((value & OL_ATH_CAP_DCS_WLANIM) && !(IEEE80211_IS_CHAN_5GHZ(ic->ic_curchan))) {
                    printk("Disabling DCS-WLANIM for 11G mode\n");
                    value &= (~OL_ATH_CAP_DCS_WLANIM);
                }
                /* 
                 * Host and target should always contain the same value. So
                 * avoid talking to target if the values are same.
                 */
                if (value == OL_IS_DCS_ENABLED(scn->scn_dcs.dcs_enable)) {
                    retval = EOK;
                    break;
                }
                /* if already enabled and run state is not running, more
                 * likely that channel change is in progress, do not let
                 * user modify the current status
                 */
                if ((OL_IS_DCS_ENABLED(scn->scn_dcs.dcs_enable)) &&
                        !(OL_IS_DCS_RUNNING(scn->scn_dcs.dcs_enable))) {
                    retval = EINVAL;
                    break;
                }
                retval = wmi_unified_pdev_set_param(scn->wmi_handle, 
                                WMI_PDEV_PARAM_DCS, value);

                /* 
                 * we do not expect this to fail, if failed, eventually
                 * target and host may not be at agreement. Otherway is 
                 * to keep it in same old state. 
                 */
                if (EOK == retval) {
                    scn->scn_dcs.dcs_enable = value;
                    printk("DCS: %s dcs enable value %d return value %d", __func__, value, retval );
                } else {
                    printk("DCS: %s target command fail, setting return value %d",
                            __func__, retval );
                }
                (OL_IS_DCS_ENABLED(scn->scn_dcs.dcs_enable)) ? (OL_ATH_DCS_SET_RUNSTATE(scn->scn_dcs.dcs_enable)) :
                                        (OL_ATH_DCS_CLR_RUNSTATE(scn->scn_dcs.dcs_enable)); 
            }
            break;
        case OL_ATH_PARAM_DCS_COCH_THR: 
            scn->scn_dcs.coch_intr_thresh = value;
            break;
        case OL_ATH_PARAM_DCS_PHYERR_THR: 
            scn->scn_dcs.phy_err_threshold = value;
            break;
        case OL_ATH_PARAM_DCS_PHYERR_PENALTY: 
            scn->scn_dcs.phy_err_penalty = value;         /* phy error penalty*/
            break;
        case OL_ATH_PARAM_DCS_RADAR_ERR_THR:
            scn->scn_dcs.radar_err_threshold = value;
            break;
        case OL_ATH_PARAM_DCS_USERMAX_CU_THR:
            scn->scn_dcs.user_max_cu = value;             /* tx_cu + rx_cu */
            break;
        case OL_ATH_PARAM_DCS_INTR_DETECT_THR:
            scn->scn_dcs.intr_detection_threshold = value;
            break;
        case OL_ATH_PARAM_DCS_SAMPLE_WINDOW:
            scn->scn_dcs.intr_detection_window = value;
            break;
        case OL_ATH_PARAM_DCS_DEBUG:
            if (value < 0 || value > 2) {
                printk("0-disable, 1-critical 2-all, %d-not valid option\n", value);
                return -EINVAL;
            }
            scn->scn_dcs.dcs_debug = value;
            break;

        case OL_ATH_PARAM_DYN_TX_CHAINMASK:
            /*
             * value is set to either 1 (enabled) or 0 (disabled).
             */
            value = !!value;
            if (scn->dtcs != (u_int8_t)value) {
                retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                                 WMI_PDEV_PARAM_DYNTXCHAIN, value);
                if (retval == EOK) {
                    scn->dtcs = (u_int8_t)value;
                }
            }
        break;
#if ATH_SUPPORT_HYFI_ENHANCEMENTS
		case OL_ATH_PARAM_BUFF_THRESH:
			thresh = value;
			if((thresh >= MIN_BUFF_LEVEL_IN_PERCENT) && (thresh<=100))
			{
				scn->buff_thresh.ald_free_buf_lvl = scn->buff_thresh.pool_size - ((scn->buff_thresh.pool_size * thresh) / 100);
				printk("Buff Warning Level=%d\n", (scn->buff_thresh.pool_size - scn->buff_thresh.ald_free_buf_lvl));                           
			} else {
                printk("ERR: Buff Thresh(in %%) should be >=%d and <=100\n", MIN_BUFF_LEVEL_IN_PERCENT);
            }
			break;
		case OL_ATH_PARAM_DROP_STA_QUERY:
			ic->ic_dropstaquery = !!value;
			break;
		case OL_ATH_PARAM_BLK_REPORT_FLOOD:
			ic->ic_blkreportflood = !!value;
			break;
#endif
        
        case OL_ATH_PARAM_VOW_EXT_STATS:
            {
                scn->vow_extstats = value;
            }
            break; 

        case OL_ATH_PARAM_LTR_ENABLE:
            param_id = WMI_PDEV_PARAM_LTR_ENABLE;
            goto low_power_config;
        case OL_ATH_PARAM_LTR_AC_LATENCY_BE:
            param_id = WMI_PDEV_PARAM_LTR_AC_LATENCY_BE;
            goto low_power_config;
        case OL_ATH_PARAM_LTR_AC_LATENCY_BK:
            param_id = WMI_PDEV_PARAM_LTR_AC_LATENCY_BK;
            goto low_power_config;
        case OL_ATH_PARAM_LTR_AC_LATENCY_VI:
            param_id = WMI_PDEV_PARAM_LTR_AC_LATENCY_VI;
            goto low_power_config;
        case OL_ATH_PARAM_LTR_AC_LATENCY_VO:
            param_id = WMI_PDEV_PARAM_LTR_AC_LATENCY_VO;
            goto low_power_config;
        case OL_ATH_PARAM_LTR_AC_LATENCY_TIMEOUT:
            param_id = WMI_PDEV_PARAM_LTR_AC_LATENCY_TIMEOUT;
            goto low_power_config;
        case OL_ATH_PARAM_LTR_TX_ACTIVITY_TIMEOUT:
            param_id = WMI_PDEV_PARAM_LTR_TX_ACTIVITY_TIMEOUT;
            goto low_power_config;
        case OL_ATH_PARAM_LTR_SLEEP_OVERRIDE:
            param_id = WMI_PDEV_PARAM_LTR_SLEEP_OVERRIDE;
            goto low_power_config;
        case OL_ATH_PARAM_LTR_RX_OVERRIDE:
            param_id = WMI_PDEV_PARAM_LTR_RX_OVERRIDE;
            goto low_power_config;
        case OL_ATH_PARAM_L1SS_ENABLE:
            param_id = WMI_PDEV_PARAM_L1SS_ENABLE;
            goto low_power_config;
        case OL_ATH_PARAM_DSLEEP_ENABLE:
            param_id = WMI_PDEV_PARAM_DSLEEP_ENABLE;
            goto low_power_config;
low_power_config:
            retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                         param_id, value);
        case OL_ATH_PARAM_ACS_CTRLFLAG:
            if(ic->ic_acs){
                ieee80211_acs_set_param(ic->ic_acs, IEEE80211_ACS_CTRLFLAG , *(int *)buff);
            }
            break;
        case OL_ATH_PARAM_ACS_ENABLE_BK_SCANTIMEREN:
            if(ic->ic_acs){
                ieee80211_acs_set_param(ic->ic_acs, IEEE80211_ACS_ENABLE_BK_SCANTIMER , *(int *)buff);
            }
            break;
        case OL_ATH_PARAM_ACS_SCANTIME:
            if(ic->ic_acs){
                ieee80211_acs_set_param(ic->ic_acs, IEEE80211_ACS_SCANTIME , *(int *)buff);
            }
            break;
        case OL_ATH_PARAM_ACS_RSSIVAR:
            if(ic->ic_acs){
                ieee80211_acs_set_param(ic->ic_acs, IEEE80211_ACS_RSSIVAR , *(int *)buff);
            }
            break;
        case OL_ATH_PARAM_ACS_CHLOADVAR:
            if(ic->ic_acs){
                ieee80211_acs_set_param(ic->ic_acs, IEEE80211_ACS_CHLOADVAR , *(int *)buff);
            }
            break;
        case OL_ATH_PARAM_ACS_LIMITEDOBSS:
            if(ic->ic_acs){
                ieee80211_acs_set_param(ic->ic_acs, IEEE80211_ACS_LIMITEDOBSS , *(int *)buff);
            }
            break;
        case OL_ATH_PARAM_ACS_DEBUGTRACE:
            if(ic->ic_acs){
                ieee80211_acs_set_param(ic->ic_acs, IEEE80211_ACS_DEBUGTRACE , *(int *)buff);
            }
             break;
        case OL_ATH_PARAM_RESET_OL_STATS:
            ol_ath_reset_vap_stat(ic);
            break;
#if UMAC_SUPPORT_PERIODIC_PERFSTATS
        case OL_ATH_PARAM_PRDPERFSTAT_THRPUT_ENAB:
            (*(int *)buff) ? \
            ol_ath_net80211_set_prdperfstat_thrput_enab(ic, 1):  \
            ol_ath_net80211_set_prdperfstat_thrput_enab(ic, 0);
            break;
        case OL_ATH_PARAM_PRDPERFSTAT_THRPUT_WIN:
            ol_ath_net80211_set_prdperfstat_thrput_win(ic,
            (*(int *)buff));
            break;
        case OL_ATH_PARAM_PRDPERFSTAT_PER_ENAB:
            (*(int *)buff) ? \
            ol_ath_net80211_set_prdperfstat_per_enab(ic, 1):   \
            ol_ath_net80211_set_prdperfstat_per_enab(ic, 0);
            break;
        case OL_ATH_PARAM_PRDPERFSTAT_PER_WIN:
            ol_ath_net80211_set_prdperfstat_per_win(ic,
             (*(int *)buff));
            break;
#endif /* UMAC_SUPPORT_PERIODIC_PERFSTATS */
#if ATH_RX_LOOPLIMIT_TIMER
        case OL_ATH_PARAM_LOOPLIMIT_NUM:
            if (*(int *)buff > 0)
                scn->rx_looplimit_timeout = *(int *)buff;
            break;
#endif 
#define ANTENNA_GAIN_2G_MASK    0x0
#define ANTENNA_GAIN_5G_MASK    0x8000
        case OL_ATH_PARAM_ANTENNA_GAIN_2G:
            if (value >= 0 && value <= 30) {
                return wmi_unified_pdev_set_param(scn->wmi_handle,
                         WMI_PDEV_PARAM_ANTENNA_GAIN, value | ANTENNA_GAIN_2G_MASK);
            } else {
                retval = -EINVAL;
            }
            break;
        case OL_ATH_PARAM_ANTENNA_GAIN_5G:
            if (value >= 0 && value <= 30) {
                return wmi_unified_pdev_set_param(scn->wmi_handle,
                         WMI_PDEV_PARAM_ANTENNA_GAIN, value | ANTENNA_GAIN_5G_MASK);
            } else {
                retval = -EINVAL;
            }
            break;
        case OL_ATH_PARAM_RX_FILTER:
            if (ic->ic_set_rxfilter)
                ic->ic_set_rxfilter(ic, value);
            else
                retval = -EINVAL;
            break;
       case OL_ATH_PARAM_SET_FW_HANG_ID:
            wmi_unified_pdev_set_fw_hang(scn->wmi_handle, value);
            break;
       case OL_ATH_PARAM_FW_RECOVERY_ID:	
            if (value == 1) 
	        scn->recovery_enable = TRUE;
            else if (value == 0)
                scn->recovery_enable = FALSE;
            else
                printk("Please enter: 1 = Enable & 0 = Disable\n");
            break;
       case OL_ATH_PARAM_DISABLE_DFS:
            {
                if (!value)
                    scn->sc_is_blockdfs_set = false;
                else
                    scn->sc_is_blockdfs_set = true;
            }
            break;
       case OL_ATH_PARAM_RX_DECAP_MODE:
            {
                enum htt_pkt_type pkt_type;
                u_int32_t decap_param;
                bool nss_wifi = 0;

                if (!ol_ath_validate_rx_decap_mode(value)) {
                    retval = -EINVAL;
                } else {
                    decap_param = value;
#if PERE_IP_HDR_ALIGNMENT_WAR
                    if (scn->host_80211_enable && value != 0) {
                        /* Configure FW for Native Wi-Fi decap, except if Raw
                         * Mode is desired.
                         * We don't make any assumptions about host_80211_enable
                         * validity for value == 1 (Native Wi-Fi).
                         */
                        decap_param = 1;
                    }
#endif /* PERE_IP_HDR_ALIGNMENT_WAR */
                    
                    retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                                                WMI_PDEV_PARAM_RX_DECAP_MODE,
                                                decap_param);

                    if (retval == 0) {
                        if (value == 0) {
                            pkt_type = htt_pkt_type_raw;
                            printk("Setting Rx Decap mode to 0 (Raw)\n");
                        } else if (value == 1) {
                            pkt_type = htt_pkt_type_native_wifi;
                            printk("Setting Rx Decap mode to 1 (Native Wi-Fi)\n");
                            printk("Warning: This is not fully supported.\n");
                        } else {
                            pkt_type = htt_pkt_type_ethernet;
                            printk("Setting Rx Decap mode to 2 (Ethernet)\n");
                        }

                        ol_txrx_set_rx_decap_mode(scn->pdev_txrx_handle,
                                            pkt_type);
#if QCA_NSS_PLATFORM && QCA_NSS_NWIFI_MODE
                        if (pkt_type != htt_pkt_type_raw) {
                            nss_wifi = 1;
                        }
#endif /* QCA_NSS_PLATFORM && QCA_NSS_NWIFI_MODE */
                        ol_ath_set_vap_nss_wifi(ic, nss_wifi);

                    } else {
                        printk("Error %d setting param "
                                "WMI_PDEV_PARAM_RX_DECAP_MODE with val %u\n",
                                retval,
                                decap_param);
                    }
                }
            }
            break;
        default:
            return (-1);
    }
    return retval;
}

int
ol_ath_get_config_param(struct ol_ath_softc_net80211 *scn, ol_ath_param_t param, void *buff)
{
    int retval = 0;
#if ATH_SUPPORT_HYFI_ENHANCEMENTS
	u_int32_t value = *(u_int32_t *)buff;
#endif
    struct ieee80211com *ic = &scn->sc_ic;

    switch(param)
    {
        case OL_ATH_PARAM_GET_IF_ID:
            *(int *)buff = IF_ID_OFFLOAD;
        break;

        case OL_ATH_PARAM_TXCHAINMASK:
            *(int *)buff = ieee80211com_get_tx_chainmask(ic);
        break;
#if ATH_SUPPORT_HYFI_ENHANCEMENTS
		case OL_ATH_PARAM_DSCP_TID_MAP:
			*(int *)buff = ol_ath_get_dscp_tid_map(ic,value);
		break;

		case OL_ATH_PARAM_HMMC_DSCP_TID_MAP:
			*(int *)buff = ol_ath_get_hmmc_tid(ic);
		break;

		case OL_ATH_PARAM_DSCP_OVERRIDE:
			*(int *)buff = ol_ath_get_dscp_override(ic);
		break;


        case OL_ATH_PARAM_HMMC_DSCP_OVERRIDE:
            *(int *)buff = ol_ath_get_hmmc_dscp_override(ic);
        break;
#endif
        case OL_ATH_PARAM_RXCHAINMASK:
            *(int *)buff = ieee80211com_get_rx_chainmask(ic);
        break;
        case OL_ATH_PARAM_BCN_BURST:
            *(int *)buff = scn->bcn_mode;
        break;
        case OL_ATH_PARAM_ARPDHCP_AC_OVERRIDE:
            *(int *)buff = scn->arp_override;
        break;
        case OL_ATH_PARAM_IGMPMLD_OVERRIDE:
            *(int *)buff = scn->igmpmld_override;
        break;
        case OL_ATH_PARAM_IGMPMLD_TID:
            *(int *)buff = scn->igmpmld_tid;
        break;
        
        case OL_ATH_PARAM_TXPOWER_LIMIT2G:
            *(int *)buff = scn->txpowlimit2G;
        break;
        
        case OL_ATH_PARAM_TXPOWER_LIMIT5G:
            *(int *)buff = scn->txpowlimit5G;
        break;

        case OL_ATH_PARAM_TXPOWER_SCALE:
            *(int *)buff = scn->txpower_scale;
        break;
        case OL_ATH_PARAM_RTS_CTS_RATE:
            *(int *)buff =  scn->ol_rts_cts_rate;
        break;
        case OL_ATH_PARAM_DEAUTH_COUNT:
            *(int *)buff =  scn->scn_user_peer_invalid_cnt;;
        break;
        case OL_ATH_PARAM_DYN_TX_CHAINMASK:
            *(int *)buff = scn->dtcs;
        break; 
    case OL_ATH_PARAM_VOW_EXT_STATS:
        *(int *)buff = scn->vow_extstats;
        break;
        case OL_ATH_PARAM_DCS:
        /* do not need to talk to target */
        *(int *)buff = OL_IS_DCS_ENABLED(scn->scn_dcs.dcs_enable);
            break;
        case OL_ATH_PARAM_DCS_COCH_THR: 
            *(int *)buff = scn->scn_dcs.coch_intr_thresh ;
            break;
        case OL_ATH_PARAM_DCS_PHYERR_THR: 
            *(int *)buff = scn->scn_dcs.phy_err_threshold ;
            break;
        case OL_ATH_PARAM_DCS_PHYERR_PENALTY: 
            *(int *)buff = scn->scn_dcs.phy_err_penalty ;  
            break;
        case OL_ATH_PARAM_DCS_RADAR_ERR_THR:
            *(int *)buff = scn->scn_dcs.radar_err_threshold ;
            break;
        case OL_ATH_PARAM_DCS_USERMAX_CU_THR:
            *(int *)buff = scn->scn_dcs.user_max_cu ;         
            break;
        case OL_ATH_PARAM_DCS_INTR_DETECT_THR:
            *(int *)buff = scn->scn_dcs.intr_detection_threshold ;
            break;
        case OL_ATH_PARAM_DCS_SAMPLE_WINDOW:
            *(int *)buff = scn->scn_dcs.intr_detection_window ;
            break;
        case OL_ATH_PARAM_DCS_DEBUG:
            *(int *)buff = scn->scn_dcs.dcs_debug ;
            break;
#if ATH_SUPPORT_HYFI_ENHANCEMENTS
		case OL_ATH_PARAM_BUFF_THRESH:
            *(int *)buff = scn->buff_thresh.pool_size - scn->buff_thresh.ald_free_buf_lvl;
			break;
		case OL_ATH_PARAM_BLK_REPORT_FLOOD:
			*(int *)buff = ic->ic_blkreportflood;
			break;
		case OL_ATH_PARAM_DROP_STA_QUERY: 
			*(int *)buff = ic->ic_dropstaquery;
			break;
#endif
        case OL_ATH_PARAM_BURST_ENABLE:
            *(int *)buff = scn->burst_enable;
            break;
        case OL_ATH_PARAM_BURST_DUR:
            *(int *)buff = scn->burst_dur;
            break;
        case OL_ATH_PARAM_ANI_ENABLE:
            *(int *)buff =  (scn->is_ani_enable == true);
            break;
        case OL_ATH_PARAM_ACS_CTRLFLAG:
            if(ic->ic_acs){
                *(int *)buff = ieee80211_acs_get_param(ic->ic_acs, IEEE80211_ACS_CTRLFLAG );
            }
            break;
        case OL_ATH_PARAM_ACS_ENABLE_BK_SCANTIMEREN:
            if(ic->ic_acs){
               *(int *)buff = ieee80211_acs_get_param(ic->ic_acs, IEEE80211_ACS_ENABLE_BK_SCANTIMER );
            }
            break;
        case OL_ATH_PARAM_ACS_SCANTIME:
            if(ic->ic_acs){
               *(int *)buff = ieee80211_acs_get_param(ic->ic_acs, IEEE80211_ACS_SCANTIME );
            }
            break;
        case OL_ATH_PARAM_ACS_RSSIVAR:
            if(ic->ic_acs){
               *(int *)buff = ieee80211_acs_get_param(ic->ic_acs, IEEE80211_ACS_RSSIVAR );
            }
            break;
        case OL_ATH_PARAM_ACS_CHLOADVAR:
            if(ic->ic_acs){
               *(int *)buff = ieee80211_acs_get_param(ic->ic_acs, IEEE80211_ACS_CHLOADVAR );
            }
            break;
        case OL_ATH_PARAM_ACS_LIMITEDOBSS:
            if(ic->ic_acs){
               *(int *)buff = ieee80211_acs_get_param(ic->ic_acs, IEEE80211_ACS_LIMITEDOBSS);
            }
            break;
        case OL_ATH_PARAM_ACS_DEBUGTRACE:
            if(ic->ic_acs){
                *(int *)buff = ieee80211_acs_get_param(ic->ic_acs, IEEE80211_ACS_DEBUGTRACE);
            }
            break;
        case OL_ATH_PARAM_RESET_OL_STATS:
            ol_ath_reset_vap_stat(ic);
            break;
#if UMAC_SUPPORT_PERIODIC_PERFSTATS
        case OL_ATH_PARAM_PRDPERFSTAT_THRPUT_ENAB:
            *(int *)buff =
            ol_ath_net80211_get_prdperfstats_thrput_enab(ic);
            break;
        case OL_ATH_PARAM_PRDPERFSTAT_THRPUT_WIN:
            *(int *)buff =
            ol_ath_net80211_get_prdperfstat_thrput_win(ic);
            break;
        case OL_ATH_PARAM_PRDPERFSTAT_THRPUT:
            *(int *)buff =
            ol_ath_net80211_get_prdperfstat_thrput(ic);
            break;
        case OL_ATH_PARAM_PRDPERFSTAT_PER_ENAB:
            *(int *)buff =
            ol_ath_net80211_get_prdperfstat_per_enab(ic);
            break;
        case OL_ATH_PARAM_PRDPERFSTAT_PER_WIN:
            *(int *)buff =
            ol_ath_net80211_get_prdperfstat_per_win(ic);
            break;
        case OL_ATH_PARAM_PRDPERFSTAT_PER:
            *(int *)buff =
            ol_ath_net80211_get_prdperfstat_per(ic);
            break;
#endif /* UMAC_SUPPORT_PERIODIC_PERFSTATS */
        case OL_ATH_PARAM_TOTAL_PER:
            *(int *)buff =
            ol_ath_net80211_get_total_per(ic);
            break;
#if ATH_RX_LOOPLIMIT_TIMER
        case OL_ATH_PARAM_LOOPLIMIT_NUM:
            *(int *)buff = scn->rx_looplimit_timeout;
            break;
#endif
        case OL_ATH_PARAM_RADIO_TYPE:
            *(int *)buff = ic->ic_is_mode_offload(ic);
            break;

        case OL_ATH_PARAM_FW_RECOVERY_ID:
            *(int *)buff = scn->recovery_enable;	
            break;
        case OL_ATH_PARAM_DISABLE_DFS:
            *(int *)buff =	(scn->sc_is_blockdfs_set == true);
            break;
        case OL_ATH_PARAM_PS_STATE_CHANGE:
            {
                *(int *) buff =  scn->ps_report ;
            }
            break;

        default:
            return (-1);
    }
    return retval;
}


int
ol_hal_set_config_param(struct ol_ath_softc_net80211 *scn, ol_hal_param_t param, void *buff)
{
    return -1;
}

int
ol_hal_get_config_param(struct ol_ath_softc_net80211 *scn, ol_hal_param_t param, void *address)
{
    return -1;
}

void
ol_ath_set_vap_nss_wifi_func(void *arg, struct ieee80211vap *vap)
{
    osif_dev *osif = (osif_dev *)vap->iv_ifp;
    osif->nss_nwifi = *((bool*)arg);
    return;
}

void
ol_ath_set_vap_nss_wifi(struct ieee80211com *ic, bool nss_nwifi)
{
     wlan_iterate_vap_list(ic, ol_ath_set_vap_nss_wifi_func, &nss_nwifi);
}

#endif
