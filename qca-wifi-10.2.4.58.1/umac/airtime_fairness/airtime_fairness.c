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
 Air Time Fairness module
*/
#if QCA_AIRTIME_FAIRNESS

#include <ieee80211_var.h>
#include "airtime_fairness_priv.h"
#include <ieee80211_ioctl.h>  /* for ieee80211req_athdbg */
#include "ieee80211_airtime_fairness.h"

/* Definition */
#define IEEE80211_INVALID_MAC(addr) \
    ((!addr[0]) && (!addr[1]) && (!addr[2]) && \
     (!addr[3]) && (!addr[4]) && (!addr[5]))

/* forward declaration */
static OS_TIMER_FUNC(wlan_atf_token_allocate_timeout_handler);

/* extern declaration */
extern unsigned int atf_mode; /* module param to umac lkm */

/**
 * @brief For every entry in the atf structure, find the corresponding node & update the
    per node atf_unit.
 *
 * @param [in] ic  the handle to the radio
 *
 * @return true if handle is valid; otherwise false
 */
int
update_atf_nodetable(struct ieee80211com *ic)
{
    struct     ieee80211_node *ni = NULL;
    int i;

    /* For each entry in atfcfg structure, find corresponding entry in the node table */
    if(ic->atfcfg_set.peer_num_cal != 0)
    {
        for (i = 0; i < ic->atfcfg_set.peer_num_cal; i++)
        {
            ni = ieee80211_find_node(&ic->ic_sta, ic->atfcfg_set.peer_id[i].sta_mac);
            if(ni == NULL) {
                continue;
            } else {
                /* Update atf_units in the node table entry */
                ni->atf_units =  ic->atfcfg_set.peer_id[i].sta_cal_value;
                ieee80211_free_node(ni);
            }
        }
    }
    return EOK;
}

/**
 * @brief Derive txtokens based on the airtime assigned for the node.
 *
 * @param [in] node table, airtime, token distribution timer interval.
 *
 * @return None
 */
static u_int32_t ieee80211_atf_compute_txtokens(u_int32_t atf_units, u_int32_t token_interval_ms)
{
    u_int32_t tx_tokens;

    if (!atf_units) {
        return 0;
    }

    /* if token interval is 1 sec & atf_units assigned is 100 %,
       tx_tokens = 1000000
     */
    tx_tokens = token_interval_ms * 1000; /* Convert total token time to uses. */
    /* Derive tx_tokens for this peer, w.r.t. ATF denomination and scheduler token_units */
    tx_tokens = (atf_units * tx_tokens) / WMI_ATF_DENOMINATION;
    return tx_tokens;
}

/**
 * @brief Check if the peer if valid
 *
 * @param [in] node table
 *
 * @return node table entry
 */
struct ieee80211_node *ieee80211_atf_valid_peer(struct ieee80211_node *ni)
{
    /* uninitialized peer */
    if( IEEE80211_INVALID_MAC(ni->ni_macaddr) ) {
        goto peer_invalid;
    }

    /* skip peers that aren't attached to a VDEV */
    if( ni->ni_vap == NULL ) {
        goto peer_invalid;
    }

    /* skip non-AP vdevs */
    if( ni->ni_vap->iv_opmode != IEEE80211_M_HOSTAP ) {
        goto peer_invalid;
    }

    /* skip NAWDS-AP vdevs */

    /* skip AP BSS peer */
    if( ni == ni->ni_bss_node ) {
        goto peer_invalid;
    }

    return ni;

peer_invalid:
    return NULL;
}

/**
 * @brief If the peer is valid, update txtokens to the lmac layer
 * Txtokens will be used for Tx scheduling
 *
 * @param [in] ic  the handle to the radio
 *
 * @return true if handle is valid; otherwise false
 */
static void ieee80211_node_iter_dist_txtokens_strictq(void *arg, struct ieee80211_node *ni)
{
    u_int32_t atf_units = 0;
    struct ieee80211com *ic = (struct ieee80211com *) arg;

    if (!ni->ni_associd)
        return;

    /* Check for Valid peer*/
    if(ieee80211_atf_valid_peer(ni) == NULL) {
        IEEE80211_DPRINTF_IC(ic,
		IEEE80211_VERBOSE_NORMAL,
		IEEE80211_MSG_ATF,
		"%s invalid peer \n\r",__func__);
        /* Assign max atf units if node is AP Self node (ni->ni_bss_node)
           or if the opmode is STA
         */
        if ( (ni == ni->ni_bss_node) ||
             (ni->ni_vap->iv_opmode == IEEE80211_M_STA) )
        {
             atf_units = WMI_ATF_DENOMINATION;
        }
    }

    atf_units = ni->atf_units;
    ni->tx_tokens = ieee80211_atf_compute_txtokens(atf_units,ATF_TOKEN_INTVL_MS);
    ic->ic_atf_update_node_txtoken(ic, ni);
}

/**
 * @brief Iterates through the node table.
 *        Nodes with the borrow flag set will get be alloted its share
 *        from the contributable token pool
 *
 * @param [in] arg  the handle to the radio
               ni   pointer to the node table
 *
 * @return none
 */
static void ieee80211_node_iter_dist_txtokens_fairq(void *arg, struct ieee80211_node *ni)
{
    u_int32_t contributabletokens_perclient = 0;
    struct ieee80211com *ic = (struct ieee80211com *) arg;

    /* For nodes with 'borrow' enabled, allocate additional tokens from contributable token pool */
    if(ni->ni_atfborrow)
    {
        contributabletokens_perclient = ic->atf_contributabletokens/ic->atf_num_clients_borrow;

        //Update borrowed tokens for this node.
        ni->ni_borrowedtokens = contributabletokens_perclient;

        IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_NORMAL, IEEE80211_MSG_ATF,
		    "%s() Node : %s atf_num_clients_borrow : %d tot atf_contributabletokens %d cont per client : %d  tokens : %d --> %d  \n\r",
            __func__, ether_sprintf(ni->ni_macaddr), ic->atf_num_clients_borrow,
            ic->atf_contributabletokens, contributabletokens_perclient,
            ni->tx_tokens, (ni->tx_tokens + contributabletokens_perclient));

        ni->tx_tokens += contributabletokens_perclient;
    }
    ic->ic_atf_update_node_txtoken(ic, ni);
}

/**
 * @brief Iterates through the node table.
 *        Identifies clients looking to borrow & contribute tokens
 *        Computes total tokens available for contribution
 *
 * @param [in] arg  the handle to the radio
               ni   pointer to the node table
 *
 * @return none
 */
static void ieee80211_node_iter_fairq_algo(void *arg, struct ieee80211_node *ni)
{
    u_int32_t atf_units = 0, avg_unusedtokens_percent = 0, node_unusedtokens = 0;
    int i = 0, node_index = 0;
    struct ieee80211com *ic = (struct ieee80211com *)arg;

    if (!ni->ni_associd)
    {
        IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_NORMAL, IEEE80211_MSG_ATF,
		                     "Node(%s) not associated. Returning \n\r", ether_sprintf(ni->ni_macaddr));
        return;
    }

    /* Check for Valid peer*/
    if(ieee80211_atf_valid_peer(ni) == NULL) {

        IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_NORMAL, IEEE80211_MSG_ATF,
		                    "%s invalid peer %s \n\r",__func__, ether_sprintf(ni->ni_macaddr));

        /* Assign max atf units if node is AP Self node (ni->ni_bss_node)
           or if the opmode is STA
         */
        if ( (ni == ni->ni_bss_node) ||
             (ni->ni_vap->iv_opmode == IEEE80211_M_STA) )
        {
            atf_units = WMI_ATF_DENOMINATION;
        }
    }

    /* convert user %(atf_units) to txtokens (ni->txtokens) */
    atf_units = ni->atf_units;
    ni->tx_tokens = ieee80211_atf_compute_txtokens(atf_units, ATF_TOKEN_INTVL_MS);

    /* Get unused tokens from the previous iteration */
    ic->ic_atf_get_unused_txtoken(ic, ni, &node_unusedtokens);
    IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_NORMAL, IEEE80211_MSG_ATF,
		                "%s() - Node MAC:%s, atf_units: %d ni->tx_tokens: %d unused tokens: %d INTVL: %d\n\r",
                          __func__,ether_sprintf(ni->ni_macaddr),atf_units, ni->tx_tokens,
                            node_unusedtokens,ATF_TOKEN_INTVL_MS);

    /* If atfdata history not available for the node */
    if(ni->ni_atfdata_logged < ATF_DATA_LOG_SIZE)
    {
        IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_NORMAL, IEEE80211_MSG_ATF,
		    "%s - Node History not available \n\r", ether_sprintf(ni->ni_macaddr));
        if(ni->ni_atfindex)
        {
            ni->ni_unusedtokenpercent[ni->ni_atfindex -1 ] =
                    (node_unusedtokens <= ni->tx_tokens)? ((node_unusedtokens/ni->tx_tokens) * 100): 0;
        }

        IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_NORMAL, IEEE80211_MSG_ATF,
		    "(node %s) atfdata_logged : %d ni_atfindex : %d \n\r",
                ether_sprintf(ni->ni_macaddr), ni->ni_atfdata_logged, ni->ni_atfindex);
        ni->ni_atfdata_logged++;
        ni->ni_atfindex++;

        if (ni->ni_atfindex >= ATF_DATA_LOG_SIZE)
        {
            IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_NORMAL, IEEE80211_MSG_ATF,
		        "%s ni_atfindex > %d . reset to 0 \n\r",ether_sprintf(ni->ni_macaddr), ATF_DATA_LOG_SIZE);
            ni->ni_atfindex = 0;
        }
        return;
    }

    /*  Compute unused tokens.
        If this node had borrowed tokens in the previous iteration,
        do not account borrowed tokens in unusedtoken compuation.
     */
    if(ni->ni_atfborrow)
    {
        IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_NORMAL, IEEE80211_MSG_ATF,
		                    "%s -  Borrow set  : unused : %d borrowed : %d\n\r",
                            ether_sprintf(ni->ni_macaddr), node_unusedtokens,
                            ni->ni_borrowedtokens);
        node_unusedtokens = (node_unusedtokens > ni->ni_borrowedtokens) ? (node_unusedtokens - ni->ni_borrowedtokens): 0;
    }

    switch(ni->ni_atfindex)
    {
        case 0:
            node_index = (ATF_DATA_LOG_SIZE - 1);
            break;
        case ATF_DATA_LOG_SIZE:
            node_index = 0;
            break;
        default:
            node_index = (ni->ni_atfindex - 1);
    }

    /* Update unused token percentage */
    ni->ni_unusedtokenpercent[ node_index ] = (node_unusedtokens <= (ni->tx_tokens - ni->ni_contributedtokens))?
                                                ((node_unusedtokens * 100)/ (ni->tx_tokens - ni->ni_contributedtokens)): 0;
    IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_NORMAL, IEEE80211_MSG_ATF,
	                    "%s - unusedtoken percent[%d]: %d \n\r",
                        ether_sprintf(ni->ni_macaddr), (node_index),
                        ni->ni_unusedtokenpercent[node_index]);

    /* Calculate avg unused tokens */
    IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_NORMAL, IEEE80211_MSG_ATF,
		" (Node : %s) avg of : ", ether_sprintf(ni->ni_macaddr));
    for(i = 0; i < ATF_DATA_LOG_SIZE ; i++)
    {
        IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_NORMAL, IEEE80211_MSG_ATF,
		    "%d, ",ni->ni_unusedtokenpercent[i]);
        avg_unusedtokens_percent += ni->ni_unusedtokenpercent[i];
    }
    avg_unusedtokens_percent = avg_unusedtokens_percent/ATF_DATA_LOG_SIZE;
    IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_NORMAL, IEEE80211_MSG_ATF, " : %d \n\r", avg_unusedtokens_percent);

    ni->ni_contributedtokens = 0;
    if(avg_unusedtokens_percent <= ATF_UNUSEDTOKENS_BORROW_THRESHOLD)
    {
        /* If average unused tokens percentage is less than a min threshold, set borrow flag */
        ni->ni_atfborrow = 1;
        ic->atf_num_clients_borrow++;
        IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_NORMAL, IEEE80211_MSG_ATF,
		                    "Node MAC:%s, borrow enabled! atf_num_clients_borrow : %d tx_tokens : %d \n\r",
                            ether_sprintf(ni->ni_macaddr), ic->atf_num_clients_borrow, ni->tx_tokens);
    }
    else
    {
        /* Compute the node tokens that can be contributed and deduct it from node tokens */
        ni->ni_atfborrow = 0;
        ni->ni_contributedtokens = ( ((avg_unusedtokens_percent - ATF_RESERVERD_TOKEN_PERCENT) * ni->tx_tokens) / 100 );
        ni->tx_tokens -= ni->ni_contributedtokens;
        ic->atf_contributabletokens += ni->ni_contributedtokens;
        IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_NORMAL, IEEE80211_MSG_ATF,
                            "%s, Tokens to contribute : %d total_contributable tokens : %d tx_tokens : %d\n\r",
                            ether_sprintf(ni->ni_macaddr), ni->ni_contributedtokens,
                            ic->atf_contributabletokens, ni->tx_tokens);
    }

    /* Increment node index */
    ni->ni_atfindex++;
    if (ni->ni_atfindex >= ATF_DATA_LOG_SIZE)
        ni->ni_atfindex = 0;
}

/**
 * @brief Iterate atf peer table, get the total atf_units alloted.
 *        convert unalloted atf_units to tokens and add to the
 *        contributable token pool
 * @param [in] ic  the handle to the radio
 *
 * @return unalloted tokens
 */
uint32_t ieee80211_atf_compute_unalloted_txtokens(struct ieee80211com *ic)
{
    uint32_t i = 0, airtime_alloted = 0, txtokens_unalloted;
    for(i = 0; i < ACTIVED_MAX_CLIENTS; i++)
    {
        if (ic->atfcfg_set.peer_id[i].sta_assoc_status == 1 ) {
            airtime_alloted += ic->atfcfg_set.peer_id[i].sta_cal_value;
        }
    }

    txtokens_unalloted = ieee80211_atf_compute_txtokens((WMI_ATF_DENOMINATION - airtime_alloted),ATF_TOKEN_INTVL_MS);
    if(txtokens_unalloted)
    {
        IEEE80211_DPRINTF_IC(ic, IEEE80211_VERBOSE_NORMAL, IEEE80211_MSG_ATF,
                             "tokens unalloted : %d  to contribute : %d \n\r", txtokens_unalloted,
                            (txtokens_unalloted - ((ATF_RESERVED_UNALLOTED_TOKEN_PERCENT * txtokens_unalloted)/100)) );
    }
    txtokens_unalloted -= ((ATF_RESERVED_UNALLOTED_TOKEN_PERCENT * txtokens_unalloted)/100);
    return txtokens_unalloted;
}


/**
 * @brief Timer that Iterates the node table & distribute tokens
 *  atf_units is updated in node table by update_atf_nodetable routine
 *
 * @param [in] ic  the handle to the radio
 *
 * @return true if handle is valid; otherwise false
 */
static OS_TIMER_FUNC(wlan_atf_token_allocate_timeout_handler)
{
    struct ieee80211com *ic;

    OS_GET_TIMER_ARG(ic, struct ieee80211com *);

    if (ic->ic_atf_strictsched)
    {
        /* ATF - strictq algorithm
           Parse Node table , Derive txtokens & update node structure
         */
        ieee80211_iterate_node(ic,ieee80211_node_iter_dist_txtokens_strictq,ic);
    } else {
        /* ATF - fairq alogrithm */

        /* Reset the atf_ic variables at the start*/
        ic->atf_num_clients_borrow = 0;
        ic->atf_contributabletokens = 0;

        /* Loop1 : Iterates through node table,
                   Identifies clients looking to borrow & Contribute tokens
                   Computes total tokens available for contribution
         */
        ieee80211_iterate_node(ic,ieee80211_node_iter_fairq_algo,ic);

        /* compute the unalloted txtokens and add to the contributable token pool*/
        ic->atf_contributabletokens += ieee80211_atf_compute_unalloted_txtokens(ic);

        /* Loop2 :  Distributes tokens
                    Nodes looking to borrow tokens will get its share
                    from the contributable token pool*/
        ieee80211_iterate_node(ic,ieee80211_node_iter_dist_txtokens_fairq,ic);
    }
    update_atf_nodetable(ic);

    if(ic->atf_commit)
        OS_SET_TIMER(&ic->atf_tokenalloc_timer, ATF_TOKEN_INTVL_MS);
}

void ieee80211_atf_node_join_leave(struct ieee80211_node *ni,const u_int8_t type)
{
    struct ieee80211com *ic = ni->ni_ic;
    u_int8_t  i, j;
    u_int16_t calbitmap;

    if(type)
    { /* Add join node */
       for (i = 0, calbitmap = 1; i < ACTIVED_MAX_CLIENTS; i++)
       {
           if (ic->atfcfg_set.peer_id[i].index_vap == 0)
           {
               /* printk("\n Join sta MAC addr:%02x:%02x:%02x:%02x:%02x:%02x \n",
                        ni->ni_macaddr[0],ni->ni_macaddr[1],ni->ni_macaddr[2],
                        ni->ni_macaddr[3],ni->ni_macaddr[4],ni->ni_macaddr[5]); */

               OS_MEMCPY((char *)(ic->atfcfg_set.peer_id[i].sta_mac),(char *)(ni->ni_macaddr),IEEE80211_ADDR_LEN);
               ic->atfcfg_set.peer_id[i].index_vap = 0xff;
               ic->atfcfg_set.peer_id[i].sta_assoc_status = 1;
               ic->atfcfg_set.peer_cal_bitmap |= (calbitmap<<i);
               break;
           } else {
               if (IEEE80211_ADDR_EQ((char *)(ic->atfcfg_set.peer_id[i].sta_mac), (char *)(ni->ni_macaddr)))
               {

                   if (ic->atfcfg_set.peer_id[i].cfg_flag)
                   {
                       ic->atfcfg_set.peer_id[i].sta_assoc_status = 1;
                       break;
                   }else
                       return;

               }
           }
       }
    } else {
        /* Remove leave node */
        for (i = 0, j = 0; i < ACTIVED_MAX_CLIENTS; i++)
        {
            if (ic->atfcfg_set.peer_id[i].index_vap != 0)
                j = i;
        }
        for (i = 0, calbitmap = 1; i < ACTIVED_MAX_CLIENTS; i++)
       {
           if ((ic->atfcfg_set.peer_id[i].index_vap != 0)&&
               (IEEE80211_ADDR_EQ((char *)(ic->atfcfg_set.peer_id[i].sta_mac), (char *)(ni->ni_macaddr))))
           {
              /* printk("Leave sta MAC addr:%02x:%02x:%02x:%02x:%02x:%02x \n",
                        ni->ni_macaddr[0],ni->ni_macaddr[1],ni->ni_macaddr[2],
                        ni->ni_macaddr[3],ni->ni_macaddr[4],ni->ni_macaddr[5]);*/

               if(j != i)
               {
                   if (ic->atfcfg_set.peer_id[i].cfg_flag)
                   {
                       /*ic->atfcfg_set.peer_num_cfg--;*/
                       ic->atfcfg_set.peer_id[i].index_vap = 0xff;
                       ic->atfcfg_set.peer_id[i].sta_cal_value = 0;
                       ic->atfcfg_set.peer_id[i].sta_assoc_status = 0;
                   }else{
                       ic->atfcfg_set.peer_id[i].cfg_flag = ic->atfcfg_set.peer_id[j].cfg_flag;
                       ic->atfcfg_set.peer_id[i].sta_cfg_mark = ic->atfcfg_set.peer_id[j].sta_cfg_mark;
                       ic->atfcfg_set.peer_id[i].sta_cfg_value = ic->atfcfg_set.peer_id[j].sta_cfg_value;
                       ic->atfcfg_set.peer_id[i].index_vap = ic->atfcfg_set.peer_id[j].index_vap;
                       ic->atfcfg_set.peer_id[i].sta_cal_value = ic->atfcfg_set.peer_id[j].sta_cal_value;
                       ic->atfcfg_set.peer_id[i].sta_assoc_status = ic->atfcfg_set.peer_id[j].sta_assoc_status;
                       OS_MEMCPY((char *)(ic->atfcfg_set.peer_id[i].sta_mac),(char *)(ic->atfcfg_set.peer_id[j].sta_mac),IEEE80211_ADDR_LEN);

                       ic->atfcfg_set.peer_id[j].cfg_flag = 0;
                       ic->atfcfg_set.peer_id[j].sta_cfg_mark = 0;
                       ic->atfcfg_set.peer_id[j].sta_cfg_value = 0;
                       memset(&(ic->atfcfg_set.peer_id[j].sta_mac[0]),0,IEEE80211_ADDR_LEN);
                       ic->atfcfg_set.peer_id[j].index_vap = 0;
                       ic->atfcfg_set.peer_id[j].sta_cal_value = 0;
                       ic->atfcfg_set.peer_id[j].sta_assoc_status = 0;
                       ic->atfcfg_set.peer_cal_bitmap &= ~(calbitmap<<j);
                   }
                   break;
               }else{
                   if (ic->atfcfg_set.peer_id[i].cfg_flag)
                   {
                       ic->atfcfg_set.peer_id[i].index_vap = 0xff;
                   }else{
                       memset(&(ic->atfcfg_set.peer_id[i].sta_mac[0]),0,IEEE80211_ADDR_LEN);
                       ic->atfcfg_set.peer_id[i].index_vap = 0;
                       ic->atfcfg_set.peer_cal_bitmap &= ~(calbitmap<<i);
                   }
                   ic->atfcfg_set.peer_id[i].sta_cal_value = 0;
                   ic->atfcfg_set.peer_id[i].sta_assoc_status = 0;
                   break;
               }
           }
       }
    }
    if ( i == ACTIVED_MAX_CLIENTS)
    {
        /*    printk("ieee80211_atf_node_join_leave-- Either join or leave failed!! \n");*/
        return;
    }
    /* Wake up timer to update alloc table*/
    spin_lock(&ic->atf_lock);
    if((ic->atf_fmcap)&&(ic->atf_mode))
    {
        if (ic->atf_tasksched == 0)
        {
            ic->atf_tasksched = 1;
            ic->atf_vap_handler = ni->ni_vap;
            OS_SET_TIMER(&ic->atfcfg_timer, IEEE80211_ATF_WAIT*1000);
        } else {
            /*printk("\n delay some secs, come back again??\n");*/
        }
    }
    spin_unlock(&ic->atf_lock);

}

/**
  * @brief function to send the atf table which has to be sent down to the Firmware
  *
  * @param ic the handle to the radio
  *
  * @return true if handle is valid; otherwise false
  */
    int
build_atf_for_fm(struct ieee80211com *ic)
{
    struct     wmi_pdev_atf_req  *wmi_req = &(ic->wmi_atfreq);
    int        retv = 0;
    u_int8_t   i, j;

    /*printk("build_atf_for_fm: ic->atfcfg_set.peer_num_cal=%d\n",ic->atfcfg_set.peer_num_cal);*/
    if(ic->atfcfg_set.peer_num_cal != 0)
    {
        wmi_req->percentage_uint = ic->atfcfg_set.percentage_unit;
        wmi_req->num_peers = ic->atfcfg_set.peer_num_cal;
        for (i = 0, j = 0; (i < ACTIVED_MAX_CLIENTS)&&(j < ic->atfcfg_set.peer_num_cal); i++)
        {
            if(ic->atfcfg_set.peer_id[i].sta_assoc_status == 1)
            {
                wmi_req->atf_peer_info[j].percentage_peer = ic->atfcfg_set.peer_id[i].sta_cal_value;
                wmi_req->atf_peer_info[j].peer_macaddr.mac_addr31to0 = 0;
                wmi_req->atf_peer_info[j].peer_macaddr.mac_addr47to32 = 0;
                wmi_req->atf_peer_info[j].peer_macaddr.mac_addr31to0 |= ic->atfcfg_set.peer_id[i].sta_mac[0];
                wmi_req->atf_peer_info[j].peer_macaddr.mac_addr31to0 |= ic->atfcfg_set.peer_id[i].sta_mac[1]<<8;
                wmi_req->atf_peer_info[j].peer_macaddr.mac_addr31to0 |= ic->atfcfg_set.peer_id[i].sta_mac[2]<<16;
                wmi_req->atf_peer_info[j].peer_macaddr.mac_addr31to0 |= ic->atfcfg_set.peer_id[i].sta_mac[3]<<24;
                wmi_req->atf_peer_info[j].peer_macaddr.mac_addr47to32 |= ic->atfcfg_set.peer_id[i].sta_mac[4];
                wmi_req->atf_peer_info[j].peer_macaddr.mac_addr47to32 |= ic->atfcfg_set.peer_id[i].sta_mac[5]<<8;
                j++;
            }
        }
    }
    else {
        printk(" No peer in allocation table, no action to firmware!\n");
    }
    return retv;
}

/**
 * @brief allocate memory for the atf table
 *
 * @param ic the handle to the radio
 *
 * @return true if handle is valid; otherwise false
 */

int build_atf_alloc_tbl(struct ieee80211com *ic)
{
    struct     ieee80211_node_table *nt = &ic->ic_sta;
    struct     ieee80211vap *vap = NULL;
    struct     ieee80211_node *ni;
    int        retv = 0;
    u_int8_t   i,vap_index = 0;

    /* Peer by Peer look up vap in alloc table, then program peer table*/
    for (i = 0, ic->atfcfg_set.peer_num_cal = 0; i < ACTIVED_MAX_CLIENTS; i++)
    {
       if((ic->atfcfg_set.peer_id[i].index_vap != 0)&&(ic->atfcfg_set.peer_id[i].sta_assoc_status == 1))
            ic->atfcfg_set.peer_num_cal++;
    }

    if (ic->atfcfg_set.percentage_unit == 0)
        ic->atfcfg_set.percentage_unit = PER_UNIT_1000;

    /* 1. Check vap is in alloc table.
       yes-->save vap (index+1) from vap table for peer table
       no--->save 0xff as vap_index for peer table.
       2. loop peer table and find match peer mac or new peer,
       put vap_index and new peer mac addr.
     */
    if(ic->atfcfg_set.peer_num_cal!= 0)
    {
        TAILQ_FOREACH(ni, &nt->nt_node, ni_list) {

            vap = ni->ni_vap;
            for (i = 0, vap_index = 0xff; i < ic->atfcfg_set.vap_num_cfg; i++)
            {
                if (adf_os_str_cmp(ic->atfcfg_set.vap[i].essid,vap->iv_bss->ni_essid) == 0)
                {
                    vap_index = i+1;
                    break;
                }
            }

            if (ni->ni_associd != 0)
            {
                /* Fill peer alloc table */
                for (i = 0; i < ACTIVED_MAX_CLIENTS; i++)
                {
                    if(ic->atfcfg_set.peer_id[i].index_vap != 0)
                    {
                        if(OS_MEMCMP(ic->atfcfg_set.peer_id[i].sta_mac,ni->ni_macaddr,IEEE80211_ADDR_LEN) == 0)
                        {
                            ic->atfcfg_set.peer_id[i].index_vap = vap_index;
                            if(ic->atfcfg_set.peer_id[i].sta_cfg_mark)
                                ic->atfcfg_set.peer_id[i].sta_cfg_mark = 0;
                            /*    printk("build_atf_alloc_tbl--found station---suceessful!!  \n");*/
                            break;
                        } else {
                        /*    printk("Continue to look up empty alloc table entry,current index entry=%d\n",i); */
                        }
                    } else {
                        if(OS_MEMCMP(vap->iv_myaddr,ni->ni_macaddr,IEEE80211_ADDR_LEN) !=0 )
                        {
                            OS_MEMCPY(&(ic->atfcfg_set.peer_id[i].sta_mac[0]),&(ni->ni_macaddr[0]),IEEE80211_ADDR_LEN);
                            ic->atfcfg_set.peer_id[i].index_vap = vap_index;
                        }
                        break;
                    }
                }
                if(i == ACTIVED_MAX_CLIENTS)
                {
                    retv = -1;
                    break;
                }
            }
        }
    } else {
        /*printk("Empty table,no para setting to pass firmware! \n");*/
        retv = -1;
    }
    return retv;
}
int
vrf_atf_cfg_value(struct ieee80211com *ic)
{
    int        retv = 0;
    u_int32_t  vap_cfg_added = 0;
    u_int32_t  peer_cfg_added = 0;
    u_int8_t   vap_num = 0;
    u_int8_t   i = 0, j =0;

    vap_num = ic->atfcfg_set.vap_num_cfg;
    for (i = 0; (i< CFG_NUM_VDEV)&&(vap_num != 0); i++)
    {
        if(ic->atfcfg_set.vap[i].cfg_flag)
        {
            vap_cfg_added += ic->atfcfg_set.vap[i].vap_cfg_value;
            vap_num--;
        }
    }

    if(vap_cfg_added > ic->atfcfg_set.percentage_unit)
    {
        retv = -1;
        printk("\n VAPs configuration value assigment wrong!!\n");
        goto end_vrf_atf_cfg;
    }

    vap_num = ic->atfcfg_set.vap_num_cfg;
    for (i = 0, peer_cfg_added = 0; (i< CFG_NUM_VDEV)&&(vap_num != 0); i++)
    {
        if(ic->atfcfg_set.vap[i].cfg_flag)
        {
            vap_num--;
            peer_cfg_added = 0;
            for ( j = 0; j<ACTIVED_MAX_CLIENTS; j++)
            {
                if(ic->atfcfg_set.peer_id[j].index_vap == (i+1))
                {
                    if(ic->atfcfg_set.peer_id[j].cfg_flag)
                    {
                        peer_cfg_added += ((ic->atfcfg_set.vap[i].vap_cfg_value * ic->atfcfg_set.peer_id[j].sta_cfg_value) / ic->atfcfg_set.percentage_unit);
                    }
                }
            }

            if ( peer_cfg_added > ic->atfcfg_set.vap[i].vap_cfg_value)
            {
                printk("\n Peers configuration value assignment wrong !!! Reassign the values\n");
                retv = -1;
                goto end_vrf_atf_cfg;
            }
        }
    }

end_vrf_atf_cfg:
    return retv;
}

int
vrf_atf_peer_value(struct ieee80211com *ic)
{
    int        retv = 0;
    u_int32_t  peer_cfg_added = 0;
    u_int8_t   i = 0;

    for (i=0; i<ACTIVED_MAX_CLIENTS; i++)
    {
        if(ic->atfcfg_set.peer_id[i].cfg_flag)
        {
            peer_cfg_added += ic->atfcfg_set.peer_id[i].sta_cfg_value;
        }
    }
    if(peer_cfg_added > ic->atfcfg_set.percentage_unit)
    {
        retv = -1;
        printk("\n Peers configuration value assignment wrong!!\n");
    }
    return retv;
}


/**
 * @brief calculate the percentage value and update the atf table
 *
 * @param ic the handle to the radio
 *
 * @return true if handle is valid; otherwise false
 */

int cal_atf_alloc_tbl(struct ieee80211com *ic)
{
    int        retv = 0;
    u_int8_t   calcnt,stacnt,j,i = 0;
    u_int32_t  calavgval = 0;
    u_int16_t  peerbitmap,calbitmap;
    u_int32_t  per_unit = 0;
    u_int8_t   vap_num = 0;
    u_int32_t  vap_per_unit = 0;
    u_int8_t   peer_total_cnt = 0;
    u_int8_t   un_assoc_cfg_peer = 0;

    if(ic->atfcfg_set.vap_num_cfg)
    {
        retv = vrf_atf_cfg_value(ic);
        if(retv != 0)
            goto end_cal_atf;

        peer_total_cnt = ic->atfcfg_set.peer_num_cal;
        vap_num = ic->atfcfg_set.vap_num_cfg;
        per_unit = ic->atfcfg_set.percentage_unit;
        for (i = 0; (i< CFG_NUM_VDEV)&&(vap_num != 0); i++)
        {
            if(ic->atfcfg_set.vap[i].cfg_flag)
            {
                vap_per_unit = ic->atfcfg_set.vap[i].vap_cfg_value;
                per_unit -= vap_per_unit;
                vap_num--;
                for ( j = 0, stacnt=0, peerbitmap = 0, calbitmap=1; j<ACTIVED_MAX_CLIENTS; j++)
                {
                    if(ic->atfcfg_set.peer_id[j].index_vap == (i+1))
                    {
                        if(ic->atfcfg_set.peer_id[j].cfg_flag)
                        {
                            ic->atfcfg_set.peer_id[j].sta_cal_value =
                                (ic->atfcfg_set.vap[i].vap_cfg_value*ic->atfcfg_set.peer_id[j].sta_cfg_value)/
                                ic->atfcfg_set.percentage_unit;
                            vap_per_unit -= ic->atfcfg_set.peer_id[j].sta_cal_value;
                            peer_total_cnt--;
                        } else {
                            peerbitmap |= (calbitmap<<j);
                            stacnt++;
                        }
                    }
                }
                if (stacnt)
                {
                    calavgval = vap_per_unit/stacnt;
                    for ( j = 0, calbitmap = 1; j<ACTIVED_MAX_CLIENTS; j++)
                    {
                        if(peerbitmap &(calbitmap<<j))
                            ic->atfcfg_set.peer_id[j].sta_cal_value = calavgval;
                    }
                    peer_total_cnt -= stacnt;
                }
            }
        } /*End of loop*/
        /*Handle left stations that do not include in config vap*/
        /*  printk("VAP host config mode--cal left sta Units stacnt=%d lefttotalcnt=%d\n",stacnt,peer_total_cnt);*/
        if(peer_total_cnt != 0)
        {
            calavgval = per_unit/peer_total_cnt;
            for ( j = 0; j<ACTIVED_MAX_CLIENTS; j++)
            {
                if (ic->atfcfg_set.peer_id[j].index_vap == 0xff)
                {
                    if (ic->atfcfg_set.peer_id[j].sta_assoc_status == 1)
                        ic->atfcfg_set.peer_id[j].sta_cal_value = calavgval;
                    else{
                        ic->atfcfg_set.peer_id[j].sta_cal_value = 0;
                        un_assoc_cfg_peer++;
                    }
                }
            }
        }
    } else {
        /* printk("cal_atf_alloc_tbl -- NO VAP host config mode\n");*/
        if(ic->atfcfg_set.peer_num_cfg)
        {
            retv = vrf_atf_peer_value(ic);
            if(retv != 0)
                goto end_cal_atf;
            per_unit = ic->atfcfg_set.percentage_unit;
            for (i=0, calcnt=ic->atfcfg_set.peer_num_cfg, calbitmap = 1; ((i<ACTIVED_MAX_CLIENTS)&& (calcnt!=0)); i++)
            {
                if(ic->atfcfg_set.peer_id[i].cfg_flag)
                {
                    if(ic->atfcfg_set.peer_id[i].sta_cfg_value <= per_unit )
                    {
                        if (ic->atfcfg_set.peer_id[i].sta_assoc_status == 1)
                        {
                            ic->atfcfg_set.peer_id[i].sta_cal_value = ic->atfcfg_set.peer_id[i].sta_cfg_value;
                            per_unit -=ic->atfcfg_set.peer_id[i].sta_cfg_value;
                        } else {
                            ic->atfcfg_set.peer_id[i].sta_cal_value = 0;
                            un_assoc_cfg_peer++;
                        }
                        calcnt--;
                    } else {
                        printk("Wrong input percentage value for peer!!\n");
                        retv = -1;
                        break;
                    }
                }
            }
            if (ic->atfcfg_set.peer_num_cal >= (ic->atfcfg_set.peer_num_cfg - un_assoc_cfg_peer))
            {
                calcnt = ic->atfcfg_set.peer_num_cal - (ic->atfcfg_set.peer_num_cfg - un_assoc_cfg_peer);
                if(calcnt)
                {
                    calavgval = per_unit/calcnt;
                    for (i=0, calbitmap = 1; i<ACTIVED_MAX_CLIENTS ; i++)
                    {
                        if(ic->atfcfg_set.peer_id[i].cfg_flag == 0)
                        {
                            if(ic->atfcfg_set.peer_cal_bitmap & (calbitmap<<i))
                            {
                                ic->atfcfg_set.peer_id[i].sta_cal_value = calavgval;
                                /*printk("calavgval=%d i=%d sta_cal_value=%d\n",calavgval,i,ic->atfcfg_set.peer_id[i].sta_cal_value);*/
                            }
                        }
                    }
                }
            } else {
                printk("Wrong input percentage value for peer!\n");
                retv = -1;
            }
        } else {
            if(ic->atfcfg_set.peer_num_cal)
            {
                calavgval = ic->atfcfg_set.percentage_unit/ic->atfcfg_set.peer_num_cal;
                for (i=0, calbitmap = 1; i<ACTIVED_MAX_CLIENTS; i++)
                {
                    if(ic->atfcfg_set.peer_cal_bitmap &(calbitmap<<i))
                    {
                        ic->atfcfg_set.peer_id[i].sta_cal_value = calavgval;
                    }
                }
            } else {
                printk("Empty table, no para setting to pass firmware!\n");
                retv = -1;
            }
        }
    }

end_cal_atf:
        return retv;
}

/**
 * @brief timer function to upate the atf table and calculate the percentage value
 *
 * @param atf timer
 *
 * @return true if handle is valid; otherwise false
 */

static OS_TIMER_FUNC(ieee80211_atfcfg_timer)
{
    struct ieee80211com *ic;
    int    retv = 0;
    OS_GET_TIMER_ARG(ic, struct ieee80211com *);

    spin_lock(&ic->atf_lock);

    /*1.build atf table ic-->vap<-->ic_sta*/
    retv = build_atf_alloc_tbl(ic);
    if(retv != 0)
        goto exit_atf_timer;

    /*2.cal vpa and sta % for whole table*/
    retv = cal_atf_alloc_tbl(ic);
    if(retv != 0)
        goto exit_atf_timer;

    if(!ic->ic_is_mode_offload(ic))
    {
        retv= update_atf_nodetable(ic);
    } else {
        /*3.copy contents from table to structure for fm*/
    	retv = build_atf_for_fm(ic);
        if(retv != 0)
            goto exit_atf_timer; 
    	ic->ic_vap_set_param(ic->atf_vap_handler,IEEE80211_ATF_OPT,1);
    }
exit_atf_timer:

    ic->atf_tasksched = 0;

    spin_unlock(&ic->atf_lock);

}

/**
 * @brief function that is called during attach time to start the timer
 *
 * @param ic the handle to the radio
 *
 */
void ieee80211_atf_attach(struct ieee80211com *ic)
{
    spin_lock_init(&ic->atf_lock);

    /*  Temporary change to get ATF enabled on Direct attach.
        TODO : move this to hal layer */
    if(!ic->ic_is_mode_offload(ic))
    {
        ic->atf_mode = atf_mode;
        ic->atf_fmcap = atf_mode;

        //Enable Strict scheduling by default
        ic->ic_atf_strictsched = 1;
    }

    OS_INIT_TIMER(ic->ic_osdev, &(ic->atfcfg_timer), ieee80211_atfcfg_timer, (void *) (ic));
    OS_INIT_TIMER(ic->ic_osdev, &ic->atf_tokenalloc_timer, wlan_atf_token_allocate_timeout_handler, (void *) ic);
}

int ieee80211_atf_detach(struct ieee80211com *ic)
{
    spin_lock(&ic->atf_lock);
    if (ic->atf_tasksched) {
        ic->atf_tasksched = 0;
    }
    spin_unlock(&ic->atf_lock);
    OS_FREE_TIMER(&ic->atfcfg_timer);

    OS_FREE_TIMER(&ic->atf_tokenalloc_timer);
    spin_lock_destroy(&ic->atf_lock);

    printk("%s: ATF terminated\n", __func__);
    return EOK;
}

int ieee80211_atf_set(struct ieee80211vap *vap, u_int8_t enable)
{

    struct ieee80211com *ic = vap->iv_ic;

    if(!ic->ic_is_mode_offload(ic))
        ic->ic_atf_set_enable(ic, enable);

    ic->atf_commit = !!enable;
    if((ic->atf_fmcap)&&(ic->atf_mode))
    {
        if (ic->atf_tasksched == 0)
        {
            spin_lock(&ic->atf_lock);
            ic->atf_tasksched = 1;
            ic->atf_vap_handler = vap;
            OS_SET_TIMER(&ic->atfcfg_timer, IEEE80211_ATF_WAIT*1000);

            if(!ic->ic_is_mode_offload(ic))
                OS_SET_TIMER(&ic->atf_tokenalloc_timer, ATF_TOKEN_INTVL_MS);

            spin_unlock(&ic->atf_lock);
            return EOK;
        }else
            return EINVAL;
    }else{
        printk("Either firmware capability or host ATF configuration not support!!\n");
        return EOK;
    }
}

int ieee80211_atf_clear(struct ieee80211vap *vap, u_int8_t val)
{
    struct ieee80211com *ic = vap->iv_ic;

    if(!ic->ic_is_mode_offload(ic))
        ic->ic_atf_set_disable(ic, val);

    ic->atf_commit = !!val;
    if (ic->atf_tasksched == 1)
    {
        spin_lock(&ic->atf_lock);
        ic->atf_tasksched = 0;
        ic->atf_vap_handler = NULL;
        spin_unlock(&ic->atf_lock);
        return EOK;
    }
    return !EOK;
}
#endif
