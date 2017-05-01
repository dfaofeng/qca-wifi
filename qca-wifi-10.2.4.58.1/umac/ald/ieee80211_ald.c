/*
 *  Copyright (c) 2008 Atheros Communications Inc.
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
#include <ieee80211_var.h>
#include "ieee80211_ioctl.h"
#include "ald_netlink.h"

#if ATH_SUPPORT_HYFI_ENHANCEMENTS
#include "ieee80211_ald_priv.h"    /* Private to ALD module */
#include "ath_dev.h"
#include "if_athvar.h"
int ieee80211_ald_vattach(wlan_if_t vap)
{
    struct ieee80211com     *ic;
    struct ath_linkdiag     *ald_priv;
    int  ret = 0;

    ic  = vap->iv_ic;

    if (vap->iv_ald) {
        ASSERT(vap->iv_ald == 0);
        return -1; /* already attached ? */
    }

    ald_priv = (struct ath_linkdiag *) OS_MALLOC(ic->ic_osdev, (sizeof(struct ath_linkdiag)), GFP_ATOMIC);
    vap->iv_ald = ald_priv;

    if (ald_priv == NULL) {
       return -ENOMEM;
    } else {
        OS_MEMZERO(ald_priv, sizeof(struct ath_linkdiag));
        spin_lock_init(&ald_priv->ald_lock);
        
        vap->iv_ald->ald_maxcu = WLAN_MAX_MEDIUM_UTILIZATION;
        
        return ret;
    }
}

int ieee80211_ald_vdetach(wlan_if_t vap)
{
    if(vap->iv_ald){
        spin_lock_destroy(&ald_priv->ald_lock);
        OS_FREE(vap->iv_ald);
    }
    return 0;
}

int wlan_ald_get_statistics(wlan_if_t vap, void *para)
{
    struct ieee80211com     *ic = vap->iv_ic;
    struct ath_softc_net80211 *scn = ATH_SOFTC_NET80211(ic);
    struct ald_stat_info *param = (struct ald_stat_info *)para;
	u_int32_t rxc_pcnt, rxf_pcnt, txf_pcnt;
	int retval = 0;
    ic  = vap->iv_ic;
    vap->iv_ald->staticp = param;
    switch (param->cmd)
    {
    case IEEE80211_ALD_MAXCU:
//      vap->iv_ald->ald_maxcu = param->maxcu;
        if (scn->sc_ops->ath_get_mib_cycle_counts_pct(scn->sc_dev, &rxc_pcnt, &rxf_pcnt, &txf_pcnt))
	        vap->iv_ald->ald_maxcu = 100 - rxc_pcnt;
		else {
			retval = -1;
		}	
        break;
    default:
        break;
    }
	ic->ic_get_ald_statistics(vap);
    return retval;
}

void ieee80211_ald_record_tx(struct ieee80211vap *vap, wbuf_t wbuf, int datalen)
{
    struct ieee80211_frame *wh;
    int type;

    wh = (struct ieee80211_frame *)wbuf_header(wbuf);
    type = wh->i_fc[0] & IEEE80211_FC0_TYPE_MASK;

    if((type == IEEE80211_FC0_TYPE_DATA) &&
          (!IEEE80211_IS_MULTICAST(wh->i_addr1)) &&
          (!IEEE80211_IS_BROADCAST(wh->i_addr1))){
        int32_t tmp;
        tmp = vap->iv_ald->ald_unicast_tx_bytes;
        spin_lock(&vap->iv_ald->ald_lock);
        vap->iv_ald->ald_unicast_tx_bytes += datalen;
        if(tmp > vap->iv_ald->ald_unicast_tx_bytes){
            vap->iv_ald->ald_unicast_tx_bytes = datalen;
            vap->iv_ald->ald_unicast_tx_packets = 0;
        }
        vap->iv_ald->ald_unicast_tx_packets++;
        spin_unlock(&vap->iv_ald->ald_lock);
    }
}

/* Enable ald statistics for a station with give MAC address */
int wlan_ald_sta_enable(wlan_if_t vaphandle, u_int8_t *macaddr, u_int32_t enable)
{
    struct ieee80211vap *vap = (struct ieee80211vap *)vaphandle;
    struct ieee80211com *ic = vap->iv_ic;
    struct ieee80211_node *ni;
    int retval = 0;
    u_int32_t ni_ext_stats_enable;

    if ((ni = ieee80211_find_node(&ic->ic_sta, macaddr))) {
        enable = !!enable;
        ni_ext_stats_enable = (ni->ni_flags & IEEE80211_NODE_EXT_STATS) ? 1 : 0;
        if ((ni_ext_stats_enable != enable) &&
            ((retval = ic->ic_node_ext_stats_enable(ni, enable)) == 0)) {
            ni->ni_flags ^= IEEE80211_NODE_EXT_STATS;
        }
    } else {
        retval = -EINVAL;
    }

    return retval;
}

#endif


