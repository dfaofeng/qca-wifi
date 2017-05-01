/*
 * Copyright (c) 2010, Qualcomm Atheros Communications Inc.
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

#include <linux/version.h>
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,19)
#include <linux/config.h>
#endif
#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/utsname.h>
#include <linux/if_arp.h>       /* XXX for ARPHRD_ETHER */

#include <asm/uaccess.h>

#include <osif_private.h>
#include <wlan_opts.h>

#include "ol_if_athvar.h"
#include "if_athioctl.h"
#include "ol_params.h"
#include "asf_amem.h"
#include "dbglog_host.h"
#include "ol_regdomain.h"
#include "ol_txrx_dbg.h"

#define __ACFG_PHYMODE_STRINGS__
#include <adf_os_types_pvt.h>
#include <acfg_drv_if.h>
#include <acfg_api_types.h>
#include <acfg_drv_dev.h>
#include <acfg_drv_cfg.h>
#include <acfg_drv_cmd.h>
#include <acfg_drv_event.h>

/*
** "split" of config param values, since they are all combined
** into the same table.  This value is a "shift" value for ATH parameters
*/
#define OL_ATH_PARAM_SHIFT     0x1000
#define OL_SPECIAL_PARAM_SHIFT 0x2000

enum {
    OL_SPECIAL_PARAM_COUNTRY_ID,
    OL_SPECIAL_PARAM_ASF_AMEM_PRINT,
    OL_SPECIAL_DBGLOG_REPORT_SIZE,
    OL_SPECIAL_DBGLOG_TSTAMP_RESOLUTION,
    OL_SPECIAL_DBGLOG_REPORTING_ENABLED,
    OL_SPECIAL_DBGLOG_LOG_LEVEL,
    OL_SPECIAL_DBGLOG_VAP_ENABLE,
    OL_SPECIAL_DBGLOG_VAP_DISABLE,
    OL_SPECIAL_DBGLOG_MODULE_ENABLE,
    OL_SPECIAL_DBGLOG_MODULE_DISABLE,
    OL_SPECIAL_PARAM_DISP_TPC,
    OL_SPECIAL_PARAM_ENABLE_CH_144,
    OL_SPECIAL_PARAM_ENABLE_OL_STATS,
    OL_SPECIAL_PARAM_REGDOMAIN,
    OL_SPECIAL_PARAM_ENABLE_MAC_REQ,
};

static void
ol_acfg_convert_to_acfgprofile (struct ieee80211_profile *profile,
                                    acfg_radio_vap_info_t *acfg_profile)
{
    a_uint8_t i, kid = 0;

	strncpy(acfg_profile->radio_name, profile->radio_name, IFNAMSIZ);
	acfg_profile->chan = profile->channel;
	acfg_profile->freq = profile->freq;
	acfg_profile->country_code = profile->cc;
	memcpy(acfg_profile->radio_mac, profile->radio_mac, ACFG_MACADDR_LEN);
    for (i = 0; i < profile->num_vaps; i++) {
        strncpy(acfg_profile->vap_info[i].vap_name,
                                    profile->vap_profile[i].name,
                                    IFNAMSIZ);
		memcpy(acfg_profile->vap_info[i].vap_mac, 
				profile->vap_profile[i].vap_mac, 
				ACFG_MACADDR_LEN);
		acfg_profile->vap_info[i].phymode = 
									profile->vap_profile[i].phymode;		
		switch (profile->vap_profile[i].sec_method) {
			case IEEE80211_AUTH_NONE:
			case IEEE80211_AUTH_OPEN:
				if(profile->vap_profile[i].cipher & (1 << IEEE80211_CIPHER_WEP))

				{
					acfg_profile->vap_info[i].cipher = 
										ACFG_WLAN_PROFILE_CIPHER_METH_WEP;
					acfg_profile->vap_info[i].sec_method = 
											ACFG_WLAN_PROFILE_SEC_METH_OPEN;
				} else {
					acfg_profile->vap_info[i].cipher = 
										ACFG_WLAN_PROFILE_CIPHER_METH_NONE;
					acfg_profile->vap_info[i].sec_method = 
											ACFG_WLAN_PROFILE_SEC_METH_OPEN;
				}
				break;
			case IEEE80211_AUTH_AUTO:
				acfg_profile->vap_info[i].sec_method = 
											ACFG_WLAN_PROFILE_SEC_METH_AUTO;
				if(profile->vap_profile[i].cipher & 
						(1 << IEEE80211_CIPHER_WEP))

				{
					acfg_profile->vap_info[i].cipher = 
										ACFG_WLAN_PROFILE_CIPHER_METH_WEP;
				}
				break;
			case IEEE80211_AUTH_SHARED:
				if(profile->vap_profile[i].cipher & 
						(1 << IEEE80211_CIPHER_WEP))
				{
					acfg_profile->vap_info[i].cipher = 
										ACFG_WLAN_PROFILE_CIPHER_METH_WEP;
				}
				acfg_profile->vap_info[i].sec_method = 
											ACFG_WLAN_PROFILE_SEC_METH_SHARED;
				break;	
			case IEEE80211_AUTH_WPA:
				acfg_profile->vap_info[i].sec_method = 
											ACFG_WLAN_PROFILE_SEC_METH_WPA;
				break;
			case IEEE80211_AUTH_RSNA:
				acfg_profile->vap_info[i].sec_method = 
											ACFG_WLAN_PROFILE_SEC_METH_WPA2;
				break;
		}
		if (profile->vap_profile[i].cipher & (1 << IEEE80211_CIPHER_TKIP)) {
			acfg_profile->vap_info[i].cipher |= 
										ACFG_WLAN_PROFILE_CIPHER_METH_TKIP;
		}
		if ((profile->vap_profile[i].cipher & (1 << IEEE80211_CIPHER_AES_OCB)) 
			 ||(profile->vap_profile[i].cipher & 
											(1 <<IEEE80211_CIPHER_AES_CCM))) 
		{
			acfg_profile->vap_info[i].cipher |= 
										ACFG_WLAN_PROFILE_CIPHER_METH_AES;
		}
		for (kid = 0; kid < 4; kid++) {
			if (profile->vap_profile[i].wep_key_len[kid]) {
        		memcpy(acfg_profile->vap_info[i].wep_key,
                	    profile->vap_profile[i].wep_key[kid], 
						profile->vap_profile[i].wep_key_len[kid]);
				acfg_profile->vap_info[i].wep_key_idx = kid;
				acfg_profile->vap_info[i].wep_key_len =
									profile->vap_profile[i].wep_key_len[kid];
			}
		}
    }
    acfg_profile->num_vaps = profile->num_vaps;
}

int
ol_acfg_vap_create(void *ctx, a_uint16_t cmdid,
               a_uint8_t *buffer, a_int32_t Length)
{
    struct net_device *dev = (struct net_device *) ctx;
    struct ieee80211_clone_params cp;
    acfg_vapinfo_t    *ptr;
    acfg_os_req_t   *req = NULL;
    struct ifreq ifr;
    int status;
	struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);


    req = (acfg_os_req_t *) buffer;
    ptr     = &req->data.vap_info;

    memset(&ifr, 0, sizeof(ifr));
    memset(&cp , 0, sizeof(cp));

    cp.icp_opmode = ptr->icp_opmode;
    cp.icp_flags  = ptr->icp_flags;
    cp.icp_vapid  = ptr->icp_vapid;

    memcpy(&cp.icp_name[0], &ptr->icp_name[0], ACFG_MAX_IFNAME);
    ifr.ifr_data = (void *) &cp;

    status  = osif_ioctl_create_vap(dev, &ifr, cp, scn->sc_osdev);

    return status;
}

int
ol_acfg_set_wifi_param(void *ctx, a_uint16_t cmdid,
                   a_uint8_t *buffer, a_int32_t Length)
{
    struct net_device *dev = (struct net_device *) ctx;
    acfg_param_req_t        *ptr;
    acfg_os_req_t   *req = NULL;
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);
    int param, value, retval = 0;


    req = (acfg_os_req_t *) buffer;
    ptr  = &req->data.param_req;

    param = ptr->param;
    value = ptr->val;

    if ( param & OL_ATH_PARAM_SHIFT )
    {
        /*
        ** It's an ATH value.  Call the  ATH configuration interface
        */

        param -= OL_ATH_PARAM_SHIFT;
        retval = ol_ath_set_config_param(scn, (ol_ath_param_t)param,
                                                   &value);
    }
    else if ( param & OL_SPECIAL_PARAM_SHIFT )
    {
        param -= OL_SPECIAL_PARAM_SHIFT;

        switch (param) {
        case OL_SPECIAL_PARAM_COUNTRY_ID:
            retval = wlan_set_countrycode(&scn->sc_ic, NULL, value, CLIST_NEW_COUNTRY);
            break;
        case OL_SPECIAL_PARAM_ASF_AMEM_PRINT:
            asf_amem_status_print();
            if ( value ) {
                asf_amem_allocs_print(asf_amem_alloc_all, value == 1);
            }
            break;
        case OL_SPECIAL_DBGLOG_REPORT_SIZE:
            dbglog_set_report_size(scn->wmi_handle, value);
            break;
        case OL_SPECIAL_DBGLOG_TSTAMP_RESOLUTION:
            dbglog_set_timestamp_resolution(scn->wmi_handle, value);
            break;
        case OL_SPECIAL_DBGLOG_REPORTING_ENABLED:
            dbglog_reporting_enable(scn->wmi_handle, value);
            break;
        case OL_SPECIAL_DBGLOG_LOG_LEVEL:
            dbglog_set_log_lvl(scn->wmi_handle, value);
            break;
        case OL_SPECIAL_DBGLOG_VAP_ENABLE:
            dbglog_vap_log_enable(scn->wmi_handle, value, TRUE);
            break;
        case OL_SPECIAL_DBGLOG_VAP_DISABLE:
            dbglog_vap_log_enable(scn->wmi_handle, value, FALSE);
            break;
        case OL_SPECIAL_DBGLOG_MODULE_ENABLE:
            dbglog_module_log_enable(scn->wmi_handle, value, TRUE);
            break;
        case OL_SPECIAL_DBGLOG_MODULE_DISABLE:
            dbglog_module_log_enable(scn->wmi_handle, value, FALSE);
            break;
        case OL_SPECIAL_PARAM_DISP_TPC:
            wmi_unified_pdev_get_tpc_config(scn->wmi_handle, value);
            break;
        case OL_SPECIAL_PARAM_ENABLE_CH_144:
            ol_regdmn_set_ch144(scn->ol_regdmn_handle, value);
            retval = wlan_set_countrycode(&scn->sc_ic, NULL, scn->ol_regdmn_handle->ol_regdmn_countryCode, CLIST_NEW_COUNTRY);
            break;
        case OL_SPECIAL_PARAM_ENABLE_OL_STATS:
            if (scn->sc_ic.ic_ath_enable_ap_stats) {
                scn->sc_ic.ic_ath_enable_ap_stats(&scn->sc_ic, value);
                retval = 0;
            }
            break;
        case OL_SPECIAL_PARAM_ENABLE_MAC_REQ:
            printk("%s: mac req feature %d \n", __func__, value);
            scn->macreq_enabled = value;
            break;
        default:
            retval = -EOPNOTSUPP;
            break;
        }
    }
    else
    {
        retval = (int) ol_hal_set_config_param(scn, (ol_hal_param_t)param, &value);
    }

    return (retval);
}

int
ol_acfg_get_wifi_param(void *ctx, a_uint16_t cmdid,
                   a_uint8_t *buffer, a_int32_t Length)
{
    struct net_device *dev = (struct net_device *) ctx;
    acfg_param_req_t        *ptr;
    acfg_os_req_t   *req = NULL;
    struct ieee80211com *ic;
    struct ol_ath_softc_net80211 *scn  = ath_netdev_priv(dev);
    int param, *val, retval = 0;

    req = (acfg_os_req_t *) buffer;
    ptr  = &req->data.param_req;
    
    val = &ptr->param;	
    param = ptr->param;

/*
    ** Code Begins
    ** Since the parameter passed is the value of the parameter ID, we can call directly
    */
    ic = &scn->sc_ic;

    if ( param & OL_ATH_PARAM_SHIFT )
    {
        /*
        ** It's an ATH value.  Call the  ATH configuration interface
        */

        param -= OL_ATH_PARAM_SHIFT;
        if (ol_ath_get_config_param(scn, (ol_ath_param_t)param, (void *)&param))
        {
            retval = -EOPNOTSUPP;
        }
    }
    else if ( param & OL_SPECIAL_PARAM_SHIFT )
    {
        if ( param == (OL_SPECIAL_PARAM_SHIFT | OL_SPECIAL_PARAM_COUNTRY_ID) ) {
            IEEE80211_COUNTRY_ENTRY    cval;
    
            ic->ic_get_currentCountry(ic, &cval);
            val[0] = cval.countryCode;
        } else if ( param == (OL_SPECIAL_PARAM_SHIFT | OL_SPECIAL_PARAM_ENABLE_CH_144) ) {
            ol_regdmn_get_ch144(scn->ol_regdmn_handle, &val[0]);
        }
        else {
            retval = -EOPNOTSUPP;
        }
    }
    else
    {
        if ( ol_hal_get_config_param(scn, (ol_hal_param_t)param, (void *)&param))
        {
            retval = -EOPNOTSUPP;
        }
    }

    return (retval);
}

int
ol_acfg_set_reg (void *ctx, a_uint16_t cmdid,
            a_uint8_t *buffer, a_int32_t Length)
{
    return 0;
}

int
ol_acfg_get_reg (void *ctx, a_uint16_t cmdid,
            a_uint8_t *buffer, a_int32_t Length)
{
    return 0;
}

#ifdef ATH_TX99_DIAG
extern u_int8_t tx99_ioctl(struct net_device *dev, struct ol_ath_softc_net80211 *sc, int cmd, void *addr);
#endif
extern int utf_unified_ioctl (struct ol_ath_softc_net80211 *scn, struct ifreq *ifr);

int
ol_acfg_tx99tool (void *ctx, a_uint16_t cmdid,
               a_uint8_t *buffer, a_int32_t Length)
{
    struct net_device *dev = (struct net_device *) ctx;
    struct ol_ath_softc_net80211 *scn  = ath_netdev_priv(dev);
    acfg_os_req_t   *req = (acfg_os_req_t *)buffer;
    int error = 0;
    struct ifreq ifr;

    memset(&ifr, 0, sizeof(ifr));
    ifr.ifr_data = (void *)&req->data;

#if defined(ATH_TX99_DIAG) && (!defined(ATH_PERF_PWR_OFFLOAD))
    error = tx99_ioctl(dev, ATH_DEV_TO_SC(scn->sc_dev), SIOCIOCTLTX99, ifr.ifr_data);
#else
    error = utf_unified_ioctl(scn, &ifr);
#endif
    return error;
}

int
ol_acfg_set_hwaddr (void *ctx, a_uint16_t cmdid,
               a_uint8_t *buffer, a_int32_t Length)
{
    struct net_device *dev = (struct net_device *) ctx;
    acfg_macaddr_t *paddr;
    struct sockaddr mac;
    acfg_os_req_t   *req = (acfg_os_req_t *)buffer;
    int status = ENOTSUPP;
    
    paddr = &req->data.macaddr;
    memcpy(mac.sa_data, paddr, ACFG_MACADDR_LEN);
    
    rtnl_lock(); 

    if (dev->netdev_ops->ndo_set_mac_address)
        status = dev->netdev_ops->ndo_set_mac_address(dev, &mac);

    rtnl_unlock();
    
    return status;
}

int
ol_acfg_get_ath_stats (void *ctx, a_uint16_t cmdid,
               a_uint8_t *buffer, a_int32_t Length)
{
    struct net_device *dev = (struct net_device *) ctx;
    acfg_os_req_t   *req = (acfg_os_req_t *)buffer;
    struct ol_ath_softc_net80211 *scn  = ath_netdev_priv(dev);
    struct ol_stats stats;
    acfg_ath_stats_t *asc;
    int error = 0;

    asc = &req->data.ath_stats;

    if((dev->flags & IFF_UP) == 0)
    {
        return -ENXIO;
    }
    if(error || asc->size == 0 || asc->address == NULL) 
    {
        error = -EFAULT;
    }
    else 
    {
        stats.txrx_stats_level = ol_txrx_stats_publish(scn->pdev_txrx_handle, &stats.txrx_stats);
        ol_get_wal_dbg_stats(scn, &stats.stats);
        ol_get_radio_stats(scn, &stats.interface_stats);
        if (_copy_to_user(asc->address, &stats, sizeof(struct ol_stats)))
            error = -EFAULT;
        else
            error = 0;
    }
    return error;
}

int
ol_acfg_clr_ath_stats (void *ctx, a_uint16_t cmdid,
               a_uint8_t *buffer, a_int32_t Length)
{
    /* This IOCTL is currently not supported */
    return 0;
}

int
ol_acfg_get_profile (void *ctx, a_uint16_t cmdid,
               a_uint8_t *buffer, a_int32_t Length)
{
    struct net_device *dev = (struct net_device *) ctx;
    acfg_os_req_t   *req = NULL;
    acfg_radio_vap_info_t *ptr;
    struct ieee80211_profile *profile;
        int error = 0;

    req = (acfg_os_req_t *) buffer;
    ptr     = &req->data.radio_vap_info;
    memset(ptr, 0, sizeof (acfg_radio_vap_info_t));
    profile = (struct ieee80211_profile *)kmalloc(
                            sizeof (struct ieee80211_profile), GFP_KERNEL);
    if (profile == NULL) {
        return -ENOMEM;
    }
    OS_MEMSET(profile, 0, sizeof (struct ieee80211_profile));
    error = osif_ioctl_get_vap_info(dev, profile);
    ol_acfg_convert_to_acfgprofile(profile, ptr);
    if (profile != NULL) {
        kfree(profile);
        profile = NULL;
    }

    return 0;
}

extern int ath_ioctl_phyerr(struct ol_ath_softc_net80211 *scn, struct ath_diag *ad);

int
ol_acfg_phyerr (void *ctx, a_uint16_t cmdid,
               a_uint8_t *buffer, a_int32_t Length)
{
    int error = 0;
#if defined(ATH_SUPPORT_DFS) || defined(ATH_SUPPORT_SPECTRAL)
    struct net_device *dev = (struct net_device *) ctx;
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);
    acfg_os_req_t   *req = NULL;

    req = (acfg_os_req_t *) buffer;

    if (!capable(CAP_NET_ADMIN)) {
        error = -EPERM;
    } else {
        error = ath_ioctl_phyerr(scn, (struct ath_diag *)&req->data.ath_diag);
    }
#endif
    return error;
}

acfg_dispatch_entry_t ol_acfgdispatchentry[] =
{
    { 0,                         ACFG_REQ_FIRST_WIFI        , 0 }, //--> 0
    { ol_acfg_vap_create,        ACFG_REQ_CREATE_VAP        , 0 },
    { ol_acfg_set_wifi_param,    ACFG_REQ_SET_RADIO_PARAM   , 0 },
    { ol_acfg_get_wifi_param,    ACFG_REQ_GET_RADIO_PARAM   , 0 },
    { ol_acfg_set_reg,           ACFG_REQ_SET_REG           , 0 },
    { ol_acfg_get_reg,           ACFG_REQ_GET_REG           , 0 },
    { ol_acfg_tx99tool,          ACFG_REQ_TX99TOOL          , 0 },
    { ol_acfg_set_hwaddr,        ACFG_REQ_SET_HW_ADDR       , 0 },
    { ol_acfg_get_ath_stats,     ACFG_REQ_GET_ATHSTATS      , 0 },
    { ol_acfg_clr_ath_stats,     ACFG_REQ_CLR_ATHSTATS      , 0 },
    { ol_acfg_get_profile,       ACFG_REQ_GET_PROFILE       , 0 },
    { ol_acfg_phyerr,            ACFG_REQ_PHYERR            , 0 },
    { 0,                         ACFG_REQ_LAST_WIFI         , 0 }, //--> 12
};

int
ol_acfg_handle_wifi_ioctl(struct net_device *dev, void *data, int *isvap_ioctl)
{
    acfg_os_req_t   *req = NULL;
    uint32_t    req_len = sizeof(struct acfg_os_req);
    int32_t status = 0;
    uint32_t i;
    bool cmd_found = false;

    req = kzalloc(req_len, GFP_KERNEL);
    if(!req)
        return ENOMEM;
    if(copy_from_user(req, data, req_len))
        goto done;
    /* Iterate the dispatch table to find the handler
     * for the command received from the user */
    if(req->cmd > ACFG_REQ_FIRST_WIFI && req->cmd < ACFG_REQ_LAST_WIFI) 
    {
        *isvap_ioctl = 0;
        for (i = 0; i < sizeof(ol_acfgdispatchentry)/sizeof(ol_acfgdispatchentry[0]); i++)
        { 
            if (ol_acfgdispatchentry[i].cmdid == req->cmd) {
                cmd_found = true;
                break;
            }
        }
        if ((cmd_found == false) || (ol_acfgdispatchentry[i].cmd_handler == NULL)) {
            status = -1;
            printk("OL ACFG ioctl CMD %d failed\n", ol_acfgdispatchentry[i].cmdid);
            goto done;
        }
        status = ol_acfgdispatchentry[i].cmd_handler(dev,
                        req->cmd, (uint8_t *)req, req_len);
        if(copy_to_user(data, req, req_len)) {
	    printk("OL copy_to_user error\n");
            status = -1;
	}
    }
    else
    {
        *isvap_ioctl = 1;
    }
done:
    kfree(req);
    return status;
}

int
ol_acfg_handle_ioctl(struct net_device *dev, void *data)
{
    int isvap_ioctl = 0;
    int status = 0;

    status = ol_acfg_handle_wifi_ioctl(dev, data, &isvap_ioctl);
    if(isvap_ioctl)
    {
	printk("%s: setting vap param !!!\n", __func__);
    }

    return status;
}

