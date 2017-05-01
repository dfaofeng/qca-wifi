/*
 * Copyright (c) 2010, Atheros Communications Inc.
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
 * Copyright (c) 2013-2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#include <osdep.h>
#include <wbuf.h>
#include <linux/firmware.h>
#include <linux/pci.h>
#include "sw_version.h"
#include "ieee80211_var.h"
#include "ieee80211_ioctl.h"
#include "ol_if_athvar.h"
#include "if_athioctl.h"
#include "osif_private.h"
#include "osapi_linux.h"
#include "if_media.h"
#include "bmi_msg.h" /* TARGET_TYPE_ */
#include "bmi.h"
#include "target_reg_table.h"
#include "ol_ath.h"
#include "epping_test.h"
#include "common_drv.h"
#include "ol_helper.h"
#include "a_debug.h"
#include "pktlog_ac_api.h"
#include "ol_txrx_dbg.h"
#include "ol_regdomain.h"
#include "ol_params.h"
#include "ieee80211_ioctl_acfg.h"
#include "ald_netlink.h"
#include "ath_pci.h"

#if ATH_BAND_STEERING
#include "ath_band_steering.h"
#endif
#include "ath_netlink.h"

#ifdef A_SIMOS_DEVHOST
#include "sim_io.h"
#endif
#ifdef LOAD_ARRAY_FW
#include "fakeBoardData_AR6004.h"
#include "otp_AR9888v2.h"
#include "otp_AR9887v1.h"
#include "athwlan_AR9888v2.h"
#include "athwlan_AR9887v1.h"
#include "utf_AR9887v1.h"
#include "utf_AR9888v2.h"
#include "athwlan_AR9888v2_max_clients.h"
#ifndef HOST_OFFLOAD
#include "athwlan_AR9888v2_lteu.h"
#endif

#endif
#ifdef QVIT
#include <qvit/qvit_defs.h>
#endif
#if PERF_FIND_WDS_NODE
#include "wds_addr.h"
#endif
#if PERE_IP_HDR_ALIGNMENT_WAR
unsigned int host_80211_enable = 1;
module_param(host_80211_enable, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(host_80211_enable,
        "Enable reception of Native Wi-Fi frames & conversion to 802.3 frames on host");
EXPORT_SYMBOL(host_80211_enable);
#endif

unsigned int enableuartprint = 0;
module_param(enableuartprint, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(enableuartprint,
        "Enable uart/serial prints from target");
EXPORT_SYMBOL(enableuartprint);

unsigned int enable_tx_tcp_cksum = 0;
module_param(enable_tx_tcp_cksum, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(enable_tx_tcp_cksum,
        "Enable TX TCP checksum");
EXPORT_SYMBOL(enable_tx_tcp_cksum);

unsigned int vow_config = 0;
module_param(vow_config, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(vow_config,
        "Do VoW Configuration");
EXPORT_SYMBOL(vow_config);

#if QCA_AIRTIME_FAIRNESS
unsigned int atf_mode = 0;
module_param(atf_mode, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(atf_mode,
        "Do ATF Mode Configuration");
EXPORT_SYMBOL(atf_mode);
#endif


unsigned int max_peers = 0;
module_param(max_peers, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(max_peers,
        "Override Default Peers");
EXPORT_SYMBOL(max_peers);

unsigned int max_vdevs = 0;
module_param(max_vdevs, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(max_vdevs,
        "Override Default VDEVs");
EXPORT_SYMBOL(max_vdevs);

unsigned int sa_validate_sw = 0;
module_param(sa_validate_sw, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(sa_validate_sw,
        "Validate Smart Antenna Software");
EXPORT_SYMBOL(sa_validate_sw);

unsigned int enable_max_clients = 0;
module_param(enable_max_clients, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(enable_max_clients,
        "Enable support for 200 stations");


/* User can configure the buffers for each AC, via UCI commands during init time only */
unsigned int OL_ACBKMinfree = 0;
module_param(OL_ACBKMinfree, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(OL_ACBKMinfree,
        "offload : Min Free buffers reserved for AC-BK");
EXPORT_SYMBOL(OL_ACBKMinfree);

unsigned int OL_ACBEMinfree = 0;
module_param(OL_ACBEMinfree, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(OL_ACBEMinfree,
        "offload : Min Free buffers reserved for AC-BE");
EXPORT_SYMBOL(OL_ACBEMinfree);

unsigned int OL_ACVIMinfree = 0;
module_param(OL_ACVIMinfree, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(OL_ACVIMinfree,
        "offload : Min Free buffers reserved for AC-VI");
EXPORT_SYMBOL(OL_ACVIMinfree);

unsigned int OL_ACVOMinfree = 0;
module_param(OL_ACVOMinfree, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(OL_ACVOMinfree,
        "offload : Min Free buffers reserved for AC-VO");
EXPORT_SYMBOL(OL_ACVOMinfree);

#ifdef AH_CAL_IN_FLASH_PCI
extern u_int32_t CalAddr[];
extern int pci_dev_cnt;
#endif

#if PCI_INTERRUPT_WAR_ENABLE
/* intr_timeout_ms need more than 600 ms at least */
unsigned int intr_timeout_ms = 600;
module_param(intr_timeout_ms, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(intr_timeout_ms,
        "intr_timeout_ms");
EXPORT_SYMBOL(intr_timeout_ms);
#endif
/*
 * Maximum acceptable MTU
 * MAXFRAMEBODY - WEP - QOS - RSN/WPA:
 * 2312 - 8 - 2 - 12 = 2290
 */
#define ATH_MAX_MTU     2290
#define ATH_MIN_MTU     32
#define MAX_UTF_LENGTH 2048

#define QC98XX_EEPROM_SIZE_LARGEST 2116
#define FLASH_CAL_START_OFFSET     0x1000
/*
** Prototype for iw attach
*/

#ifdef ATH_SUPPORT_LINUX_STA
#ifdef CONFIG_SYSCTL
void ath_dynamic_sysctl_register(struct ol_ath_softc_net80211 *sc);
void ath_dynamic_sysctl_unregister(struct ol_ath_softc_net80211 *sc);
#endif
#endif
#if OS_SUPPORT_ASYNC_Q
static void os_async_mesg_handler( void  *ctx, u_int16_t  mesg_type, u_int16_t  mesg_len, void  *mesg );
#endif

void ol_ath_iw_attach(struct net_device *dev);
#if !NO_SIMPLE_CONFIG
extern int32_t unregister_simple_config_callback(char *name);
extern int32_t register_simple_config_callback (char *name, void *callback, void *arg1, void *arg2);
static irqreturn_t jumpstart_intr(int cpl, void *dev_id, struct pt_regs *regs, void *push_dur);
#endif

#if defined(ATH_TX99_DIAG) && (!defined(ATH_PERF_PWR_OFFLOAD))
extern u_int8_t tx99_ioctl(struct net_device *dev, struct ol_ath_softc_net80211 *sc, int cmd, void *addr);
#endif

#ifdef HIF_SDIO
#define NOHIFSCATTERSUPPORT_DEFAULT    1
unsigned int nohifscattersupport = NOHIFSCATTERSUPPORT_DEFAULT;
#endif

extern void target_register_tbl_attach(u_int32_t target_type);
extern int ol_ath_utf_cmd(ol_scn_t scn, u_int8_t *data, u_int16_t len);
extern int ol_ath_utf_rsp(ol_scn_t scn, u_int8_t *payload);

#ifdef QCA_PARTNER_PLATFORM
extern void WAR_PLTFRM_PCI_WRITE32(char *addr, u32 offset, u32 value, unsigned int war1);
extern void ath_pltfrm_init( struct net_device *dev );
#endif

#define	WMI_TIMEOUT_UNINTERRUPT	2

unsigned int testmode = 0;
module_param(testmode, int, 0644);

unsigned int lteu_support = 0;
module_param(lteu_support, int, 0644);

/*
 * Signal how to handle BMI:
 *  0 --> driver handles BMI
 *  1 --> user agent handles BMI
 */
unsigned int bmi = 0;
module_param(bmi, int, 0644);


/* The code below is used to register a hw_caps file in sysfs */
static ssize_t wifi_hwcaps_show(struct device *dev,
                               struct device_attribute *attr, char *buf)
{
    struct net_device *net = to_net_dev(dev);
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(net);
    struct ieee80211com *ic = &scn->sc_ic;

    u_int32_t hw_caps = ic->ic_modecaps;

    strcpy(buf, "802.11");
    if(hw_caps &
        1 << IEEE80211_MODE_11A)
        strcat(buf, "a");
    if(hw_caps &
        1 << IEEE80211_MODE_11B)
        strcat(buf, "b");
    if(hw_caps &
        1 << IEEE80211_MODE_11G)
        strcat(buf, "g");
    if(hw_caps &
        (1 << IEEE80211_MODE_11NA_HT20 |
         1 << IEEE80211_MODE_11NG_HT20 |
         1 << IEEE80211_MODE_11NA_HT40PLUS |
         1 << IEEE80211_MODE_11NA_HT40MINUS |
         1 << IEEE80211_MODE_11NG_HT40PLUS |
         1 << IEEE80211_MODE_11NG_HT40MINUS |
         1 << IEEE80211_MODE_11NG_HT40 |
         1 << IEEE80211_MODE_11NA_HT40))
        strcat(buf, "n");
    if(hw_caps &
        (1 << IEEE80211_MODE_11AC_VHT20 |
         1 << IEEE80211_MODE_11AC_VHT40PLUS |
         1 << IEEE80211_MODE_11AC_VHT40MINUS |
         1 << IEEE80211_MODE_11AC_VHT40 |
         1 << IEEE80211_MODE_11AC_VHT80))
        strcat(buf, "/ac");
    return strlen(buf);
}
static DEVICE_ATTR(hwcaps, S_IRUGO, wifi_hwcaps_show, NULL);
static struct attribute *wifi_device_attrs[] = {
    &dev_attr_hwcaps.attr,
    NULL
};

static struct attribute_group wifi_attr_group = {
       .attrs  = wifi_device_attrs,
};


#ifndef ADF_SUPPORT
void *
OS_ALLOC_VAP(osdev_t osdev, u_int32_t len)
{
    void *netif;

    netif = OS_MALLOC(osdev, len, GFP_KERNEL);
    if (netif != NULL)
        OS_MEMZERO(netif, len);

    return netif;
}

void
OS_FREE_VAP(void *netif)
{
    OS_FREE(netif);
}

#endif

#if 0
/*
 * Merge multicast addresses from all vap's to form the
 * hardware filter.  Ideally we should only inspect our
 * own list and the 802.11 layer would merge for us but
 * that's a bit difficult so for now we put the onus on
 * the driver.
 */
void
ath_mcast_merge(ieee80211_handle_t ieee, u_int32_t mfilt[2])
{
    struct ieee80211com *ic = NET80211_HANDLE(ieee);
    struct ieee80211vap *vap;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 34)
    struct netdev_hw_addr *ha;
#else
    struct dev_mc_list *mc;
#endif
    u_int32_t val;
    u_int8_t pos;

    mfilt[0] = mfilt[1] = 0;
    /* XXX locking */
    TAILQ_FOREACH(vap, &ic->ic_vaps, iv_next) {
        struct net_device *dev = ((osif_dev *)vap->iv_ifp)->netdev;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 34)
        netdev_for_each_mc_addr(ha, dev) {
            /* calculate XOR of eight 6-bit values */
            val = LE_READ_4(ha->addr + 0);
            pos = (val >> 18) ^ (val >> 12) ^ (val >> 6) ^ val;
            val = LE_READ_4(ha->addr + 3);
            pos ^= (val >> 18) ^ (val >> 12) ^ (val >> 6) ^ val;
            pos &= 0x3f;
            mfilt[pos / 32] |= (1 << (pos % 32));
        }
#else
        for (mc = dev->mc_list; mc; mc = mc->next) {
            /* calculate XOR of eight 6bit values */
            val = LE_READ_4(mc->dmi_addr + 0);
            pos = (val >> 18) ^ (val >> 12) ^ (val >> 6) ^ val;
            val = LE_READ_4(mc->dmi_addr + 3);
            pos ^= (val >> 18) ^ (val >> 12) ^ (val >> 6) ^ val;
            pos &= 0x3f;
            mfilt[pos / 32] |= (1 << (pos % 32));
        }
#endif
    }
}
#endif
static int
ath_netdev_open(struct net_device *dev)
{
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);

    int ol_ath_ret;
    struct ieee80211com *ic = &scn->sc_ic;
    struct ieee80211vap *vap;
    osif_dev  *osifp;
    struct net_device *netdev;
    u_int8_t myaddr[IEEE80211_ADDR_LEN];
    u_int8_t id = 0;

#ifdef ATH_BUS_PM
    if (scn->sc_osdev->isDeviceAsleep)
        return -EPERM;
#endif /* ATH_BUS_PM */
    ol_ath_ret = ol_ath_resume(scn);
    if(ol_ath_ret == 0){
        dev->flags |= IFF_UP | IFF_RUNNING;      /* we are ready to go */
        /*  If physical radio interface radioX is shutdown,all virtual interfaces(athX) should gets shutdown and
            all these downed virtual interfaces should gets up when physical radio interface(radioX) is up.Refer EV 116786.
         */
        vap = TAILQ_FIRST(&ic->ic_vaps);
        while (vap != NULL) {
            osifp = (osif_dev *)vap->iv_ifp;
            netdev = osifp->netdev;
            ieee80211vap_get_macaddr(vap, myaddr);
            ATH_GET_VAP_ID(myaddr, wlan_vap_get_hw_macaddr(vap), id);
            if( ic->id_mask_vap_downed & ( 1 << id ) ){
                dev_change_flags(netdev,netdev->flags | ( IFF_UP ));
                ic->id_mask_vap_downed &= (~( 1 << id ));
            }
            vap = TAILQ_NEXT(vap, iv_next);
        }
    }
    return ol_ath_ret;
}

static int
ath_netdev_stop(struct net_device *dev)
{
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);

    struct ieee80211com *ic = &scn->sc_ic;
    struct ieee80211vap *vap;
    osif_dev  *osifp;
    struct net_device *netdev;
    u_int8_t myaddr[IEEE80211_ADDR_LEN];
    u_int8_t id = 0;

    /*  If physical radio interface radioX is shutdown,all virtual interfaces(athX) should gets shutdown and
        all these downed virtual interfaces should gets up when physical radio interface(radioX) is up.Refer EV 116786.
     */

    vap = TAILQ_FIRST(&ic->ic_vaps);
    while (vap != NULL) {
        osifp = (osif_dev *)vap->iv_ifp;
        netdev = osifp->netdev;
        if (IS_IFUP(netdev)) {
            dev_change_flags(netdev,netdev->flags & ( ~IFF_UP ));
            ieee80211vap_get_macaddr(vap, myaddr);
            ATH_GET_VAP_ID(myaddr, wlan_vap_get_hw_macaddr(vap), id);
            ic->id_mask_vap_downed |= ( 1 << id);
        }
        vap = TAILQ_NEXT(vap, iv_next);
    }

    dev->flags &= ~IFF_RUNNING;
    return ol_ath_suspend(scn);
}

#ifdef EPPING_TEST
//#define EPPING_DEBUG 1
#ifdef EPPING_DEBUG
#define EPPING_PRINTF(...) printk(__VA_ARGS__)
#else
#define EPPING_PRINTF(...)
#endif
static inline int
__ath_epping_data_tx(struct sk_buff *skb, struct net_device *dev)
{
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);
    EPPING_HEADER *eppingHdr = A_NETBUF_DATA(skb);
    HTC_ENDPOINT_ID eid = ENDPOINT_UNUSED;
    struct cookie * cookie = NULL;
    A_UINT8 ac = 0;

    /* allocate resource for this packet */
    adf_os_spin_lock_bh(&scn->data_lock);
    cookie = ol_alloc_cookie(scn);
    adf_os_spin_unlock_bh(&scn->data_lock);

    /* no resource */
    if (cookie == NULL)
        return -1;

    /*
     * a quirk of linux, the payload of the frame is 32-bit aligned and thus
     * the addition of the HTC header will mis-align the start of the HTC
     * frame, so we add some padding which will be stripped off in the target
     */
    if (EPPING_ALIGNMENT_PAD > 0) {
        A_NETBUF_PUSH(skb, EPPING_ALIGNMENT_PAD);
    }

    /* prepare ep/HTC information */
    ac = eppingHdr->StreamNo_h;
    eid = scn->EppingEndpoint[ac];
    SET_HTC_PACKET_INFO_TX(&cookie->HtcPkt,
         cookie, A_NETBUF_DATA(skb), A_NETBUF_LEN(skb), eid, 0);
    SET_HTC_PACKET_NET_BUF_CONTEXT(&cookie->HtcPkt, skb);
    /* send the packet */
    HTCSendPkt(scn->htc_handle, &cookie->HtcPkt);

    return 0;
}

static void
epping_timer_expire(unsigned long data)
{
    struct net_device *dev = (struct net_device *) data;
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);
    struct sk_buff *nodrop_skb;

    EPPING_PRINTF("%s: queue len: %d\n", __func__,
            skb_queue_len(&scn->epping_nodrop_queue));

    if (!skb_queue_len(&scn->epping_nodrop_queue)) {
        /* nodrop queue is empty so no need to arm timer */
        scn->epping_timer_running = 0;
        return;
    }

    /* try to flush nodrop queue */
    while ((nodrop_skb = skb_dequeue(&scn->epping_nodrop_queue))) {
        if (__ath_epping_data_tx(nodrop_skb, dev)) {
            EPPING_PRINTF("nodrop: %p xmit fail in timer\n", nodrop_skb);
            /* fail to xmit so put the nodrop packet to the nodrop queue */
            skb_queue_head(&scn->epping_nodrop_queue, nodrop_skb);
            break;
        } else {
            EPPING_PRINTF("nodrop: %p xmit ok in timer\n", nodrop_skb);
        }
    }

    /* if nodrop queue is not empty, continue to arm timer */
    if (nodrop_skb) {
        scn->epping_timer_running = 1;
        mod_timer(&scn->epping_timer, jiffies + HZ / 10);
    } else {
        scn->epping_timer_running = 0;
    }
}

static int
ath_epping_data_tx(struct sk_buff *skb, struct net_device *dev)
{
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);
    struct sk_buff *nodrop_skb;
    EPPING_HEADER *eppingHdr;
    A_UINT8 ac = 0;

    if (!eppingtest) {
        goto pkt_invalid;
    }

    eppingHdr = A_NETBUF_DATA(skb);

    if (!IS_EPPING_PACKET(eppingHdr)) {
         AR_DEBUG_PRINTF(ATH_DEBUG, ("not endpoint ping packets in %s\n",
                 __FUNCTION__));
        goto pkt_invalid;
    }

    /* the stream ID is mapped to an access class */
    ac = eppingHdr->StreamNo_h;
    if (ac != 0 && ac != 1) {
        printk("ac %d is not mapped to mboxping service id = %d\n",
             ac, eppingtest);
        goto pkt_invalid;
    }

    /*
     * some EPPING packets cannot be dropped no matter what access class
     * it was sent on. A special care has been taken:
     * 1. when there is no TX resource, queue the control packets to
     *    a special queue
     * 2. when there is TX resource, send the queued control packets first
     *    and then other packets
     * 3. a timer launches to check if there is queued control packets and
     *    flush them
     */

    /* check the nodrop queue first */
    while ((nodrop_skb = skb_dequeue(&scn->epping_nodrop_queue))) {
        if (__ath_epping_data_tx(nodrop_skb, dev)) {
            EPPING_PRINTF("nodrop: %p xmit fail\n", nodrop_skb);
            /* fail to xmit so put the nodrop packet to the nodrop queue */
            skb_queue_head(&scn->epping_nodrop_queue, nodrop_skb);
            /* no cookie so free the current skb */
            goto tx_fail;
        } else {
            EPPING_PRINTF("nodrop: %p xmit ok\n", nodrop_skb);
        }
    }

    /* send the original packet */
    if (__ath_epping_data_tx(skb, dev))
        goto tx_fail;

    return 0;

tx_fail:
    if (!IS_EPING_PACKET_NO_DROP(eppingHdr)) {
pkt_invalid:
        /* no packet to send, cleanup */
        A_NETBUF_FREE(skb);
        return -ENOMEM;
    } else {
        EPPING_PRINTF("nodrop: %p queued\n", skb);
        skb_queue_tail(&scn->epping_nodrop_queue, skb);
        if (!scn->epping_timer_running) {
            scn->epping_timer_running = 1;
            mod_timer(&scn->epping_timer, jiffies + HZ / 10);
        }
    }

    return 0;
}
#endif

static int
ath_netdev_hardstart(struct sk_buff *skb, struct net_device *dev)
{
#ifdef EPPING_TEST
    return ath_epping_data_tx(skb, dev);
#else
    return 0;
#endif
}

static void
ath_netdev_tx_timeout(struct net_device *dev)
{
#if 0
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);

    DPRINTF(scn, ATH_DEBUG_WATCHDOG, "%s: %sRUNNING\n",
            __func__, (dev->flags & IFF_RUNNING) ? "" : "!");

	if (dev->flags & IFF_RUNNING) {
        scn->sc_ops->reset_start(scn->sc_dev, 0, 0, 0);
        scn->sc_ops->reset(scn->sc_dev);
        scn->sc_ops->reset_end(scn->sc_dev, 0);
	}
#endif
}

static int
ath_netdev_set_macaddr(struct net_device *dev, void *addr)
{
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);
    struct ieee80211com *ic = &scn->sc_ic;
    struct sockaddr *mac = addr;

    if (netif_running(dev)) {
#if 0
        DPRINTF(scn, ATH_DEBUG_ANY,
            "%s: cannot set address; device running\n", __func__);
#endif
        return -EBUSY;
    }
#if 0
    DPRINTF(scn, ATH_DEBUG_ANY, "%s: %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n",
        __func__,
        mac->sa_data[0], mac->sa_data[1], mac->sa_data[2],
        mac->sa_data[3], mac->sa_data[4], mac->sa_data[5]);
#endif

    /* XXX not right for multiple vap's */
    IEEE80211_ADDR_COPY(ic->ic_myaddr, mac->sa_data);
    IEEE80211_ADDR_COPY(ic->ic_my_hwaddr, mac->sa_data);
    IEEE80211_ADDR_COPY(dev->dev_addr, mac->sa_data);
    scn->sc_ic.ic_set_macaddr(&scn->sc_ic, dev->dev_addr);
    return 0;
}

static void
ath_netdev_set_mcast_list(struct net_device *dev)
{
#if 0
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);
    scn->sc_ops->mc_upload(scn->sc_dev);
#endif
}

static int
ath_change_mtu(struct net_device *dev, int mtu)
{
    if (!(ATH_MIN_MTU < mtu && mtu <= ATH_MAX_MTU)) {
#if 0
        DPRINTF((struct ol_ath_softc_net80211 *) ath_netdev_priv(dev),
            ATH_DEBUG_ANY, "%s: invalid %d, min %u, max %u\n",
            __func__, mtu, ATH_MIN_MTU, ATH_MAX_MTU);
#endif
        return -EINVAL;
    }
#if 0
    DPRINTF((struct ol_ath_softc_net80211 *) ath_netdev_priv(dev), ATH_DEBUG_ANY,
        "%s: %d\n", __func__, mtu);
#endif

    dev->mtu = mtu;
    return 0;
}

int ath_hal_getdiagstate(struct ieee80211com* ic, u_int id, void* indata, u_int32_t insize, void* outdata, u_int32_t* outsize)
{
    printk("SPECTRAL : NOT IMPLEMENTED YET %s : %d\n", __func__, __LINE__);
    return 0;
}

static int
ath_ioctl_diag(struct ol_ath_softc_net80211 *scn, struct ath_diag *ad)
{

    struct ieee80211com* ic = &scn->sc_ic;
    void *indata    = NULL;
    void *outdata   = NULL;

    int error = 0;

    u_int id= ad->ad_id & ATH_DIAG_ID;
    u_int32_t insize    = ad->ad_in_size;
    u_int32_t outsize   = ad->ad_out_size;

    if (ad->ad_id & ATH_DIAG_IN) {
        /*
         * Copy in data.
         */
        indata = OS_MALLOC(scn->sc_osdev, insize, GFP_KERNEL);
        if (indata == NULL) {
            error = -ENOMEM;
            goto bad;
        }
        if (__xcopy_from_user(indata, ad->ad_in_data, insize)) {
            error = -EFAULT;
            goto bad;
        }
    }
    if (ad->ad_id & ATH_DIAG_DYN) {
        /*
         * Allocate a buffer for the results (otherwise the HAL
         * returns a pointer to a buffer where we can read the
         * results).  Note that we depend on the HAL leaving this
         * pointer for us to use below in reclaiming the buffer;
         * may want to be more defensive.
         */
        outdata = OS_MALLOC(scn->sc_osdev, outsize, GFP_KERNEL);
        if (outdata == NULL) {
            error = -ENOMEM;
            goto bad;
        }

        id = id & ~ATH_DIAG_DYN;
    }

    if (ath_hal_getdiagstate(ic, id, indata, insize, &outdata, &outsize)) {
        if (outsize < ad->ad_out_size)
            ad->ad_out_size = outsize;
        if (outdata && _copy_to_user(ad->ad_out_data, outdata, ad->ad_out_size))
            error = -EFAULT;
    } else {
        printk("SIOCATHDIAG : Error\n");
        error = -EINVAL;
    }
bad:
    if ((ad->ad_id & ATH_DIAG_IN) && indata != NULL)
        kfree(indata);
    if ((ad->ad_id & ATH_DIAG_DYN) && outdata != NULL)
        kfree(outdata);
    return error;


}

#ifdef ATH_USB
#include "usb_eth.h"
#else
extern int ol_ath_ioctl_ethtool(struct ol_ath_softc_net80211 *scn, int cmd, void *addr);
#endif

#if defined(ATH_SUPPORT_DFS) || defined(ATH_SUPPORT_SPECTRAL)
int
ath_ioctl_phyerr(struct ol_ath_softc_net80211 *scn, struct ath_diag *ad)
{
     struct ieee80211com *ic = &scn->sc_ic;
     void *indata=NULL;
     void *outdata=NULL;
     int error = -EINVAL;
     u_int32_t insize = ad->ad_in_size;
     u_int32_t outsize = ad->ad_out_size;
     u_int id= ad->ad_id & ATH_DIAG_ID;


    if (ad->ad_id & ATH_DIAG_IN) {
                /*
                 * Copy in data.
                 */
                indata = OS_MALLOC(scn->sc_osdev,insize, GFP_KERNEL);
                if (indata == NULL) {
                        error = -ENOMEM;
                        goto bad;
                }
                if (__xcopy_from_user(indata, ad->ad_in_data, insize)) {
                        error = -EFAULT;
                        goto bad;
                }
                id = id & ~ATH_DIAG_IN;
        }
        if (ad->ad_id & ATH_DIAG_DYN) {
                /*
                 * Allocate a buffer for the results (otherwise the HAL
                 * returns a pointer to a buffer where we can read the
                 * results).  Note that we depend on the HAL leaving this
                 * pointer for us to use below in reclaiming the buffer;
                 * may want to be more defensive.
                 */
                outdata = OS_MALLOC(scn->sc_osdev, outsize, GFP_KERNEL);
                if (outdata == NULL) {
                        error = -ENOMEM;
                        goto bad;
                }
                id = id & ~ATH_DIAG_DYN;
        }

#if ATH_SUPPORT_DFS
        error = ic->ic_dfs_control(ic, id, indata, insize, outdata, &outsize);
#endif

#if ATH_SUPPORT_SPECTRAL
    if (error ==  -EINVAL ) {
        error = ic->ic_spectral_control(ic, id, indata, insize, outdata, &outsize);
    }
#endif

         if (outsize < ad->ad_out_size)
                ad->ad_out_size = outsize;

        if (outdata &&
            _copy_to_user(ad->ad_out_data, outdata, ad->ad_out_size))
                error = -EFAULT;
bad:
        if ((ad->ad_id & ATH_DIAG_IN) && indata != NULL)
                OS_FREE(indata);
        if ((ad->ad_id & ATH_DIAG_DYN) && outdata != NULL)
                OS_FREE(outdata);

        return error;
}
#endif

#define ATH_XIOCTL_UNIFIED_UTF_CMD 	0x1000
#define ATH_XIOCTL_UNIFIED_UTF_RSP  0x1001

///TODO: Should this be defined here..
//#if ATH_PERF_PWR_OFFLOAD
int
utf_unified_ioctl (struct ol_ath_softc_net80211 *scn, struct ifreq *ifr)
{
    int error = 0;
    unsigned int cmd = 0;
    unsigned int length = 0;
    char *userdata;
    unsigned char *buffer;

    get_user(cmd, (int *)ifr->ifr_data);
    userdata = (char *)(((unsigned int *)ifr->ifr_data)+1);

    switch (cmd)
    {
        case ATH_XIOCTL_UNIFIED_UTF_CMD:
        {
            get_user(length, (unsigned int *)userdata);

            if ( length > MAX_UTF_LENGTH )
                return -EFAULT;

            buffer = (unsigned char*)OS_MALLOC((void*)scn->sc_osdev, length, GFP_KERNEL);
            if (buffer != NULL)
            {
                OS_MEMZERO(buffer, length);

                if (copy_from_user(buffer, &userdata[sizeof(length)], length))
                {
                    error = -EFAULT;
                }
                else
                {
                    error = ol_ath_utf_cmd(scn,(u_int8_t*)buffer,(u_int16_t)length);
                }

                OS_FREE(buffer);
             }
             else
                error = -ENOMEM;
         }
         break;
         case ATH_XIOCTL_UNIFIED_UTF_RSP:
         {
            A_UINT8 buf[MAX_UTF_LENGTH + sizeof(u_int32_t)];

            error = ol_ath_utf_rsp(scn,(u_int8_t*)buf);

            if ( !error )
            {
                error = copy_to_user(ifr->ifr_data, buf, (MAX_UTF_LENGTH + sizeof(u_int32_t)));
            }
            else
                error = -EAGAIN;
         }
         break;
    }

    return error;
}

int ol_acfg_handle_ioctl(struct net_device *dev, void *data);

static int
ath_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);
    //struct ath_phy_stats *ps;
    int error=0;
    char *userdata = NULL;
    if (cmd == ATH_IOCTL_EXTENDED) {
        /*
         * This allows for many more wireless ioctls than would otherwise
         * be available.  Applications embed the actual ioctl command in
         * the first word of the parameter block, and use the command
         * ATH_IOCTL_EXTENDED_CMD on the ioctl call.
         */
        get_user(cmd, (int *)ifr->ifr_data);
        userdata = (char *)(((unsigned int *)ifr->ifr_data)+1);
    }

    switch (cmd) {

#ifdef QVIT
    case SIOCIOCTLQVIT:
            error = qvit_unified_ioctl(scn,ifr);
            break;
#endif
    case SIOCGATHEACS:
#if 0
#if ATH_SUPPORT_SPECTRAL
        error = osif_ioctl_eacs(dev, ifr, scn->sc_osdev);
#endif
#endif
        break;
    case SIOCGATHSTATS:
        {
            struct ol_stats stats;
            struct ath_stats_container asc;

            if(((dev->flags & IFF_UP) == 0)){
            return -ENXIO;
            }
            error = __xcopy_from_user(&asc, ifr->ifr_data, sizeof(asc) );

            if(error || asc.size == 0 || asc.address == NULL) {
                error = -EFAULT;
            }else {
                stats.txrx_stats_level =
                    ol_txrx_stats_publish(scn->pdev_txrx_handle,
                            &stats.txrx_stats);
                    ol_get_wal_dbg_stats(scn,&stats.stats);
                    ol_get_radio_stats(scn,&stats.interface_stats);
                    if (_copy_to_user(asc.address, &stats,
                            sizeof(struct ol_stats)))
                    error = -EFAULT;
                else
                    error = 0;
            }
            ((struct ath_stats_container *)ifr->ifr_data)->offload_if = 1;
            ((struct ath_stats_container *)ifr->ifr_data)->size = sizeof(struct ol_stats);
        }
        break;
    case SIOCGATHSTATSCLR:
#if 0
        as = scn->sc_ops->get_ath_stats(scn->sc_dev);
        error = 0;
#endif
        break;
    case SIOCGATHPHYSTATS:
         if(((dev->flags & IFF_UP) == 0)){
         return -ENXIO;
         }
        if (_copy_to_user(ifr->ifr_data, &scn->scn_stats,
                    sizeof(scn->scn_stats))) {
            error = -EFAULT;
        } else {
            error = 0;
        }
        break;
    case SIOCGATHDIAG:
#if 1
        if (!capable(CAP_NET_ADMIN))
            error = -EPERM;
        else
            error = ath_ioctl_diag(scn, (struct ath_diag *) ifr);
#endif
        break;
#if defined(ATH_SUPPORT_DFS) || defined(ATH_SUPPORT_SPECTRAL)
    case SIOCGATHPHYERR:
        if (!capable(CAP_NET_ADMIN)) {
            error = -EPERM;
        } else {
            error = ath_ioctl_phyerr(scn, ifr->ifr_data);
        }
        break;
#endif
    case SIOCETHTOOL:
#if 0
        if (__xcopy_from_user(&cmd, ifr->ifr_data, sizeof(cmd)))
            error = -EFAULT;
        else
            error = ol_ath_ioctl_ethtool(scn, cmd, ifr->ifr_data);
#endif
        break;
    case SIOC80211IFCREATE:
	{
            struct ieee80211_clone_params cp;
            printk("%s: SIOC80211IFCREATE CALLED\n", __func__);
            if (scn->sc_in_delete) {
                printk("%s: Can't create VAP, in ol detach\n", __func__);
                return -ENODEV;
            }
            if (__xcopy_from_user(&cp, ifr->ifr_data, sizeof(cp))) {
                return -EFAULT;
            }
            error = osif_ioctl_create_vap(dev, ifr, cp, scn->sc_osdev);
	}
        break;
#if defined(ATH_TX99_DIAG) && (!defined(ATH_PERF_PWR_OFFLOAD))
    case SIOCIOCTLTX99:
        printk("Call Tx99 ioctl %d \n",cmd);
        error = tx99_ioctl(dev, ATH_DEV_TO_SC(scn->sc_dev), cmd, ifr->ifr_data);
        break;
#else
    case SIOCIOCTLTX99:
        error = utf_unified_ioctl(scn,ifr);
        break;
#endif
#ifdef ATH_SUPPORT_LINUX_VENDOR
    case SIOCDEVVENDOR:
        printk("%s: SIOCDEVVENDOR TODO\n", __func__);
        //error = osif_ioctl_vendor(dev, ifr, 0);
        break;
#endif
#ifdef ATH_BUS_PM
    case SIOCSATHSUSPEND:
      {
        printk("%s: SIOCSATHSUSPEND TODO\n", __func__);
#if 0
        struct ieee80211com *ic = &scn->sc_ic;
        struct ieee80211vap *tmpvap;
        int val = 0;
        if (__xcopy_from_user(&val, ifr->ifr_data, sizeof(int)))
          return -EFAULT;

        if(val) {
          /* suspend only if all vaps are down */
          TAILQ_FOREACH(tmpvap, &ic->ic_vaps, iv_next) {
            struct net_device *tmpdev = ((osif_dev *)tmpvap->iv_ifp)->netdev;
            if (tmpdev->flags & IFF_RUNNING)
              return -EBUSY;
          }
          error = bus_device_suspend(scn->sc_osdev);
        }
        else
          error = bus_device_resume(scn->sc_osdev);

        if (!error)
            scn->sc_osdev->isDeviceAsleep = val;
#endif
      }
      break;
#endif /* ATH_BUS_PM */
#if UMAC_SUPPORT_ACFG
    case ACFG_PVT_IOCTL:
        error = ol_acfg_handle_ioctl(dev, ifr->ifr_data);
        break;
#endif
    default:
        error = -EINVAL;
        break;
    }

    return error;
}

/*
 * Return netdevice statistics.
 */
static struct net_device_stats *
ath_getstats(struct net_device *dev)
{
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);
    struct net_device_stats *stats = NULL;
    stats = &scn->sc_osdev->devstats;
#if 0
    struct ath_stats *as;
    struct ath_phy_stats *ps;
    struct ath_11n_stats *ans;
    WIRELESS_MODE wmode;

    stats = &scn->sc_osdev->devstats;

    as = scn->sc_ops->get_ath_stats(scn->sc_dev);
    ans = scn->sc_ops->get_11n_stats(scn->sc_dev);
    /* update according to private statistics */
    stats->tx_errors = as->ast_tx_xretries
             + as->ast_tx_fifoerr
             + as->ast_tx_filtered
             ;
    stats->tx_dropped = as->ast_tx_nobuf
            + as->ast_tx_encap
            + as->ast_tx_nonode
            + as->ast_tx_nobufmgt;
    /* Add tx beacons, tx mgmt, tx, 11n tx */
    stats->tx_packets = as->ast_be_xmit
            + as->ast_tx_mgmt
            + as->ast_tx_packets
            + ans->tx_pkts;
    /* Add rx, 11n rx (rx mgmt is included) */
    stats->rx_packets = as->ast_rx_packets
            + ans->rx_pkts;

    for (wmode = 0; wmode < WIRELESS_MODE_MAX; wmode++) {
        ps = scn->sc_ops->get_phy_stats(scn->sc_dev, wmode);
        stats->rx_errors = ps->ast_rx_fifoerr;
        stats->rx_dropped = ps->ast_rx_tooshort;
        stats->rx_crc_errors = ps->ast_rx_crcerr;
    }

#endif
    return stats;
}

#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,30)
static const struct net_device_ops athdev_net_ops = {
    .ndo_open    = ath_netdev_open,
    .ndo_stop    = ath_netdev_stop,
    .ndo_start_xmit = ath_netdev_hardstart,
    .ndo_set_mac_address = ath_netdev_set_macaddr,
    .ndo_tx_timeout = ath_netdev_tx_timeout,
    .ndo_get_stats = ath_getstats,
    .ndo_change_mtu = ath_change_mtu,
#if LINUX_VERSION_CODE < KERNEL_VERSION(3,2,0)
    .ndo_set_multicast_list = ath_netdev_set_mcast_list,
#else
    .ndo_set_rx_mode = ath_netdev_set_mcast_list,
#endif
    .ndo_do_ioctl = ath_ioctl,
};
#endif

static struct ieee80211_reg_parameters ol_wlan_reg_params = {
    .sleepTimePwrSave = 100,         /* wake up every beacon */
    .sleepTimePwrSaveMax = 1000,     /* wake up every 10 th beacon */
    .sleepTimePerf=100,              /* station wakes after this many mS in max performance mode */
    .inactivityTimePwrSaveMax=400,   /* in max PS mode, how long (in mS) w/o Tx/Rx before going back to sleep */
    .inactivityTimePwrSave=200,      /* in normal PS mode, how long (in mS) w/o Tx/Rx before going back to sleep */
    .inactivityTimePerf=400,         /* in max perf mode, how long (in mS) w/o Tx/Rx before going back to sleep */
    .psPollEnabled=0,                /* Use PS-POLL to retrieve data frames after TIM is received */
    .wmeEnabled    = 1,
    .enable2GHzHt40Cap = 1,
    .cwmEnable = 1,
    .cwmExtBusyThreshold = IEEE80211_CWM_EXTCH_BUSY_THRESHOLD,
    .ignore11dBeacon = 1,
    .p2pGoUapsdEnable = 1,
    .extapUapsdEnable = 1,
#ifdef ATH_SUPPORT_TxBF
    .autocvupdate = 0,
#define DEFAULT_PER_FOR_CVUPDATE 30
    .cvupdateper = DEFAULT_PER_FOR_CVUPDATE,
#endif
    .regdmn = 0,
    .wModeSelect = REGDMN_MODE_ALL,
    .netBand = REGDMN_MODE_ALL,
    .extendedChanMode = 0,
};

void   ol_ath_linux_update_fw_config_cb( struct ol_ath_softc_net80211 *scn,
                          struct ol_ath_target_cap *tgt_cap)
{

    /*
     * tgt_cap contains default target resource configuration
     * which can be modified here, if required
     */
#if ATH_OL_11AC_DMA_BURST
    /* 0: 128B - default, 1: 256B, 2: 64B */
	tgt_cap->wlan_resource_config.dma_burst_size = ATH_OL_11AC_DMA_BURST;
#endif

#if ATH_OL_11AC_MAC_AGGR_DELIM
	tgt_cap->wlan_resource_config.mac_aggr_delim = ATH_OL_11AC_MAC_AGGR_DELIM;
#endif

    /* Override the no. of max fragments as per platform configuration */
	tgt_cap->wlan_resource_config.max_frag_entries =
                MIN(QCA_OL_11AC_TX_MAX_FRAGS, scn->max_frag_entry);
    scn->max_frag_entry = tgt_cap->wlan_resource_config.max_frag_entries;
}

int ol_ath_verify_vow_config(struct ol_ath_softc_net80211 *scn)
{
    unsigned short vow_max_sta = ((scn->vow_config) & 0xffff0000) >> 16;
    unsigned short vow_max_desc_persta = ((scn->vow_config) & 0x0000ffff);

    if( (vow_max_sta * vow_max_desc_persta) > TOTAL_VOW_ALLOCABLE ) {
        unsigned short vow_unrsvd_sta_num, vow_rsvd_num;

        vow_rsvd_num = TOTAL_VOW_ALLOCABLE/vow_max_desc_persta;

        vow_unrsvd_sta_num = vow_max_sta - vow_rsvd_num;

        if( (vow_unrsvd_sta_num * vow_max_desc_persta) > VOW_DESC_GRAB_MAX ) {
            /*cannot support the request*/
            vow_unrsvd_sta_num = VOW_DESC_GRAB_MAX / vow_max_desc_persta;
            printk("%s: ERROR: Invalid vow_config\n",__func__);
            printk("%s: Can support only %d clients for %d desc\n", __func__,
                    vow_rsvd_num + vow_unrsvd_sta_num,
                    vow_max_desc_persta);

            return -1;
        }
    }
    return 0;
}

int
__ol_ath_attach(hif_softc_t hif_sc, struct ol_attach_t *ol_cfg, osdev_t osdev, struct net_device **pdev)
{
    struct ol_ath_softc_net80211 *scn;
    struct ieee80211com *ic;
    int error = 0;
    struct net_device *dev;

    dev = alloc_netdev(sizeof(struct ol_ath_softc_net80211), ol_cfg->bus_type == BUS_TYPE_SIM ? "wifi-sim%d" : "radio%d", NET_NAME_UNKNOWN, ether_setup);
    if (dev == NULL) {
        printk(KERN_ERR "ath: Cannot allocate softc\n");
        error = -ENOMEM;
        goto bad0;
    }

    scn = ath_netdev_priv(dev);
    OS_MEMZERO(scn, sizeof(*scn));
#ifdef EPPING_TEST
    adf_os_spinlock_init(&scn->data_lock);
    skb_queue_head_init(&scn->epping_nodrop_queue);
    setup_timer(&scn->epping_timer, epping_timer_expire, (unsigned long) dev);
    scn->epping_timer_running = 0;
#endif
    scn->sc_osdev = osdev;
    scn->hif_sc = hif_sc;
    if (ol_cfg->bus_type == BUS_TYPE_SIM) {
        /* Temp WAR for simulator - since for simulator
         * __ol_ath_attach is passed with hif_handle
         * instead of hif_sc
         */
        scn->hif_hdl = hif_sc;
    }

    /*
     * Don't leave arp type as ARPHRD_ETHER as this is no eth device
     */
    dev->type = ARPHRD_IEEE80211;

    /* show that no dedicated amem instance has been created yet */
    scn->amem.handle = NULL;
    ic = &scn->sc_ic;

    /* Create amem instance, we can use OS_MALLOC beyond this point */
    error = ol_asf_adf_attach(scn);
    if (error)
        goto bad1;

    /* TBDXXX: TARGET_TYPE should be based on PCI ID */
#if defined(CONFIG_AR6320_SUPPORT)
    scn->target_type = TARGET_TYPE_AR6320;
#else
#if defined(HIF_PCI)
    scn->target_type = TARGET_TYPE_AR9888;
#elif defined(HIF_SDIO)
    scn->target_type = TARGET_TYPE_AR6004;
#endif
#endif

#if defined(HIF_PCI)
    if (ol_ath_pci_configure(hif_sc, dev, &scn->hif_hdl)) {
        error = -EIO;
        goto bad2;
    }
#elif defined(HIF_SDIO)
    ol_ath_sdio_configure(hif_sc, dev, &scn->hif_hdl);
#endif
    /* NB: irqs are allocated */

    /* initialize the adf_dev handle */
    scn->adf_dev = OS_MALLOC((void *)scn->sc_osdev,
                             sizeof(*(scn->adf_dev)),
                             GFP_KERNEL);
    if (scn->adf_dev == NULL) {
        goto bad3;
    }
    OS_MEMSET(scn->adf_dev, 0, sizeof(*(scn->adf_dev)));
    scn->adf_dev->drv = osdev;
    scn->adf_dev->drv_hdl = osdev->bdev; /* bus handle */
    scn->adf_dev->dev = osdev->device; /* device */

    /*
     * create and initialize ath layer
     */
    printk("%s: ath_attach TODO\n", __func__);
    if (ol_cfg->bus_type == BUS_TYPE_SIM ) {
        scn->is_sim=true;
    }

    /* Init timeout */
    scn->sc_osdev->wmi_timeout = 2;

#if PERE_IP_HDR_ALIGNMENT_WAR
    /*
     * NOTE: it is required to set this variable before
     * calling ol_ath_attach(), which in turn calls ol_ath_set_default_tgt_config()
     * to setup the target properly.
     */
    scn->host_80211_enable = host_80211_enable;
    printk("%s %d host_enable %d\n", __func__, __LINE__,
            scn->host_80211_enable);
#endif
#if PERF_FIND_WDS_NODE
    wds_table_init(&scn->scn_wds_table);
#endif
    scn->enableuartprint = enableuartprint;
    scn->vow_config = vow_config;
    scn->max_peers = max_peers;
    scn->max_vdevs = max_vdevs;
    scn->sa_validate_sw = sa_validate_sw;
    scn->is_ani_enable = true;
    scn->enable_max_clients = enable_max_clients;

    if(scn->enable_max_clients)
        ic->ic_num_clients = IEEE80211_MAX_AID_DEF;
    else
        ic->ic_num_clients = IEEE80211_AID_DEF;
#if QCA_AIRTIME_FAIRNESS
    ic->atf_mode = atf_mode;
#endif

    if(ol_ath_verify_vow_config(scn)) {
        /*cannot accomadate vow config requested*/
        error = -EINVAL;
        goto bad4;
    }

    init_waitqueue_head(&scn->sc_osdev->event_queue);

    /*
     * Resolving name to avoid a crash in request_irq() on new kernels
     */
    dev_alloc_name(dev, dev->name);
    printk("%s: dev name %s\n", __func__,dev->name);

#ifndef HOST_OFFLOAD
#define LTEU_SUPPORT0    0x1
#define LTEU_SUPPORT1    0x2
    if (!strcmp("radio0", dev->name))
        scn->lteu_support = (lteu_support & LTEU_SUPPORT0) ? 1 : 0;
    else if (!strcmp("radio1", dev->name))
        scn->lteu_support = (lteu_support & LTEU_SUPPORT1) ? 1 : 0;
#endif

    /*
     * pktlog scn initialization
     */
#ifndef REMOVE_PKT_LOG
    ol_pl_sethandle(&(scn->pl_dev), scn);
    ol_pl_set_name(scn, dev);
#endif

#ifdef QCA_PARTNER_PLATFORM
    ath_pltfrm_init( dev );
#endif

    error = ol_ath_attach(ol_cfg->devid, scn, &ol_wlan_reg_params, ol_ath_linux_update_fw_config_cb);
    if (error)
        goto bad4;

#if ATH_BAND_STEERING
    if ( EOK != ath_band_steering_netlink_init()) {
        printk("Band steering socket init failed __investigate__ \n");
    }
#endif

    ath_adhoc_netlink_init();

#if ATH_RXBUF_RECYCLE
    ath_rxbuf_recycle_init(osdev);
#endif

    ald_init_netlink();

    osif_attach(dev);
#if 0
    /* For STA Mode default CWM mode is Auto */
    if ( ic->ic_opmode == IEEE80211_M_STA)
        ic->ic_cwm_set_mode(ic, IEEE80211_CWM_MODE2040);
#endif

    /*
     * initialize tx/rx engine
     */

    printk("%s: init tx/rx TODO\n", __func__);
#if 0
    error = scn->sc_ops->tx_init(scn->sc_dev, ATH_TXBUF);
    if (error != 0)
        goto badTBD;

    error = scn->sc_ops->rx_init(scn->sc_dev, ATH_RXBUF);
    if (error != 0)
        goto badTBD;
#endif

    /*
     * setup net device
     */
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,30)
    dev->netdev_ops = &athdev_net_ops;
#else
    dev->open = ath_netdev_open;
    dev->stop = ath_netdev_stop;
    dev->hard_start_xmit = ath_netdev_hardstart;
    dev->set_mac_address = ath_netdev_set_macaddr;
    dev->tx_timeout = ath_netdev_tx_timeout;
    dev->set_multicast_list = ath_netdev_set_mcast_list;
    dev->do_ioctl = ath_ioctl;
    dev->get_stats = ath_getstats;
    dev->change_mtu = ath_change_mtu;
#endif
    dev->watchdog_timeo = 5 * HZ;           /* XXX */
    dev->tx_queue_len = ATH_TXBUF-1;        /* 1 for mgmt frame */

    dev->hard_header_len += sizeof (struct ieee80211_qosframe) +
                            sizeof(struct llc) + IEEE80211_ADDR_LEN +
                            IEEE80211_WEP_IVLEN + IEEE80211_WEP_KIDLEN;

    if (enable_tx_tcp_cksum) {
        dev->features |= NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM;
    }

    printk("%s: hard_header_len reservation %d\n", __func__,
                    dev->hard_header_len);
#ifdef QVIT
// Enable ethtool support
#ifdef QVIT_DEBUG
    printk("QVIT: %s: calling ethtool_ops\n", __func__);
#endif
    qvit_set_ethtool(dev);
#endif

    /*
    ** Attach the iwpriv handlers for perf_pwr_offload device
    */

    ol_ath_iw_attach(dev);

#if OS_SUPPORT_ASYNC_Q
   OS_MESGQ_INIT(osdev, &osdev->async_q, sizeof(os_async_q_mesg),
        OS_ASYNC_Q_MAX_MESGS,os_async_mesg_handler, osdev,MESGQ_PRIORITY_NORMAL,MESGQ_ASYNCHRONOUS_EVENT_DELIVERY);
#endif

    /* Kernel 2.6.25 needs valid dev_addr before  register_netdev */
    IEEE80211_ADDR_COPY(dev->dev_addr,ic->ic_myaddr);

    /*
     * finally register netdev and ready to go
     */
    if ((error = register_netdev(dev)) != 0) {
        printk(KERN_ERR "%s: unable to register device\n", dev->name);
        goto bad5;
    }
#if !NO_SIMPLE_CONFIG
    /* Request Simple Config intr handler */
    register_simple_config_callback (dev->name, (void *) jumpstart_intr, (void *) dev,
                                     (void *)&osdev->sc_push_button_dur);
#endif
    sysfs_create_group(&dev->dev.kobj, &wifi_attr_group);

#ifdef ATH_SUPPORT_LINUX_STA
#ifdef CONFIG_SYSCTL
    ath_dynamic_sysctl_register(ATH_DEV_TO_SC(scn->sc_dev));
#endif
#endif
    if (pdev) {
       *pdev=dev;
    }

#if ATH_RX_LOOPLIMIT_TIMER
    scn->rx_looplimit_timeout = 1;           /* 1 ms by default */
    scn->rx_looplimit_valid = true;          /* set to valid after initilization */
    scn->rx_looplimit = false;
#endif

    return 0;


bad5:
    /* TODO - ol_ath_detach */

bad4:
#if PERF_FIND_WDS_NODE
    wds_table_uninit(&scn->scn_wds_table);
#endif
    if (scn->adf_dev) {
        OS_FREE(scn->adf_dev);
    }
bad3:
#if defined(HIF_PCI)
    ol_ath_diag_user_agent_fini(scn);
    ol_ath_pci_nointrs(dev);
#else
#ifndef HIF_SDIO
    free_irq(dev->irq, dev);
#endif
#endif

#if defined(HIF_PCI)
bad2:
    /* TODO - free scn->amem -- reverse ol_asf_adf_attach */
#endif
bad1:
    /* TODO - free dev -- reverse alloc_netdev */
    free_netdev(dev);

bad0:
    return error;
}

int
__ol_vap_delete_on_rmmod(struct net_device *dev)
{
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);
    struct ieee80211com *ic = &scn->sc_ic;
    struct ieee80211vap *vap;
    struct ieee80211vap *vapnext;
    osif_dev  *osifp;
    struct net_device *netdev;

    rtnl_lock();
    /*
     * Don't add any more VAPs after this.
     * Else probably the detach should be done with rtnl_lock() held.
     */
    scn->sc_in_delete = 1;
    vap = TAILQ_FIRST(&ic->ic_vaps);
    while (vap != NULL) {
        /* osif_ioctl_delete_vap() destroy vap->iv_next information,
        so need to store next VAP address in vapnext */
        vapnext = TAILQ_NEXT(vap, iv_next);
        osifp = (osif_dev *)vap->iv_ifp;
        netdev = osifp->netdev;
        printk("Remove interface on %s\n",netdev->name);
        dev_close(netdev);
        osif_ioctl_delete_vap(netdev);
        vap = vapnext;
    }
    rtnl_unlock();

    return 0;
}

int
__ol_ath_detach(struct net_device *dev)
{
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);
    int status;

    osif_detach(dev);

#ifdef ATH_SUPPORT_LINUX_STA
#ifdef CONFIG_SYSCTL
    ath_dynamic_sysctl_unregister(ATH_DEV_TO_SC(scn->sc_dev));
#endif
#endif

#ifndef NO_SIMPLE_CONFIG
    unregister_simple_config_callback(dev->name);
#endif

#ifdef QVIT
    qvit_cleanup();
#endif
    sysfs_remove_group(&dev->dev.kobj, &wifi_attr_group);
    if (dev->reg_state == NETREG_REGISTERED)
        unregister_netdev(dev);

#if OS_SUPPORT_ASYNC_Q
   OS_MESGQ_DRAIN(&scn->sc_osdev->async_q,NULL);
   OS_MESGQ_DESTROY(&scn->sc_osdev->async_q);
#endif
    printk("%s: init tx/rx cleanup TODO\n", __func__);
#if 0
    scn->sc_ops->rx_cleanup(scn->sc_dev);
    scn->sc_ops->tx_cleanup(scn->sc_dev);
#endif
    ath_adhoc_netlink_delete();

#if ATH_BAND_STEERING
    ath_band_steering_netlink_delete();
#endif

#if ATH_RXBUF_RECYCLE
    ath_rxbuf_recycle_destroy(scn->sc_osdev);
#endif /* ATH_RXBUF_RECYCLE */

    ald_destroy_netlink();

    status = ol_ath_detach(scn, 1); /* Force Detach */
#if PERF_FIND_WDS_NODE
    wds_table_uninit(&scn->scn_wds_table);
#endif
    OS_FREE(scn->adf_dev);

    free_netdev(dev);
#ifdef EPPING_TEST
    adf_os_spinlock_destroy(&scn->data_lock);
    del_timer(&scn->epping_timer);
    scn->epping_timer_running = 0;
    skb_queue_purge(&scn->epping_nodrop_queue);
#endif
    return status;
}

void
__ol_target_paused_event(struct ol_ath_softc_net80211 *scn)
{
    wake_up(&scn->sc_osdev->event_queue);
}

void
__ol_ath_suspend_resume_attach(struct net_device *dev)
{
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);
    ol_ath_suspend_resume_attach(scn);
}

int
__ol_ath_suspend(struct net_device *dev)
{
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);
    u_int32_t  timeleft;

    ath_netdev_stop(dev);
    /* Suspend target with diable_target_intr set to 0 */
    if (!ol_ath_suspend_target(scn, 0)) {
        printk("waiting for target paused event from target\n");
        /* wait for the event from Target*/
        timeleft = wait_event_interruptible_timeout(scn->sc_osdev->event_queue,
                                                    (scn->is_target_paused == TRUE),
                                                    200);
        if(!timeleft || signal_pending(current)) {
            printk("Failed to receive target paused event \n");
            return -EIO;
        }
        /*
         * reset is_target_paused and host can check that in next time,
         * or it will always be TRUE and host just skip the waiting
         * condition, it causes target assert due to host already suspend
         */
        scn->is_target_paused = FALSE;
        return (0);
    }
    return (-1);
}

int
__ol_ath_resume(struct net_device *dev)
{
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);

    if (ol_ath_resume_target(scn)) {
        return -1;
    }
    ath_netdev_open(dev);
    return 0;
}


void __ol_ath_target_status_update(struct net_device *dev, ol_target_status status)
{
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);
    ol_ath_target_status_update(scn,status);
}

#if !NO_SIMPLE_CONFIG
/*
 * Handler for front panel SW jumpstart switch
 */
static irqreturn_t
jumpstart_intr (int cpl, void *dev_id, struct pt_regs *regs, void *push_time)
{
    struct net_device *dev = dev_id;
    struct ol_ath_softc_net80211 *scn = ath_netdev_priv(dev);
    struct ieee80211com *ic = &scn->sc_ic;
    struct ieee80211vap *vap;
    u_int32_t           push_duration;
    int is_ap_vap_notified = 0;
    /*
    ** Iterate through all VAPs, since any of them may have WPS enabled
    */

    vap = TAILQ_FIRST(&ic->ic_vaps);
    while (vap != NULL) {
        if (push_time) {
            push_duration = *(u_int32_t *)push_time;
        } else {
            push_duration = 0;
        }
#if ATH_SUPPORT_HYFI_ENHANCEMENTS
        if (!ieee80211_vap_nopbn_is_set(vap))
        {
#endif
	        /* Since we are having single physical push button on device ,
    	       and for push button + muti bss combination mode we will be have limitations,
        	   we designed that,physical push button notification will be sent to first
	           AP vap(main BSS) and all sta vaps.
    	    */
	        if (vap->iv_opmode != IEEE80211_M_HOSTAP || is_ap_vap_notified == 0 ){
    	        printk("SC Pushbutton Notify on %s for %d sec(s) and the vap %p dev %p:\n",dev->name,
        	            push_duration, vap, (struct net_device *)(((osif_dev *)vap->iv_ifp)->netdev));
	            osif_notify_push_button ((struct net_device *)(((osif_dev *)vap->iv_ifp)->netdev), push_duration);
    	        if(vap->iv_opmode == IEEE80211_M_HOSTAP)
        	        is_ap_vap_notified = 1;
	        }
#if ATH_SUPPORT_HYFI_ENHANCEMENTS
        }
#endif
        vap = TAILQ_NEXT(vap, iv_next);

    }
    return IRQ_HANDLED;
}
#endif

#if OS_SUPPORT_ASYNC_Q
static void os_async_mesg_handler( void  *ctx, u_int16_t  mesg_type, u_int16_t  mesg_len, void  *mesg )
{
    if (mesg_type == OS_SCHEDULE_ROUTING_MESG_TYPE) {
        os_schedule_routing_mesg  *s_mesg = (os_schedule_routing_mesg *) mesg;
        s_mesg->routine(s_mesg->context, NULL);
    }
}
#endif

static int qc98xx_verify_checksum(void *eeprom)
{
    uint16_t *p_half;
    uint16_t sum = 0;
    int i;

    p_half = (uint16_t *)eeprom;
    for (i = 0; i < QC98XX_EEPROM_SIZE_LARGEST / 2; i++) {
        sum ^= le16_to_cpu(*p_half++);
    }
    if (sum != 0xffff) {
        printk("%s error: flash checksum 0x%x, computed 0x%x \n", __func__,
                le16_to_cpu(*((uint16_t *)eeprom + 1)), sum ^ 0xFFFF);
        return -1;
    }
    printk("%s: flash checksum passed: 0x%4x\n", __func__, le16_to_cpu(*((uint16_t *)eeprom + 1)));
    return 0;
}

#define I2C_SDA_GPIO_PIN    5
#define I2C_SDA_PIN_CONFIG  3
#define SI_CLK_GPIO_PIN     17
#define SI_CLK_PIN_CONFIG   3
void config_target_eeprom(struct ol_ath_softc_net80211 *scn) {

    struct ath_hif_pci_softc *sc = (struct ath_hif_pci_softc *)(scn->hif_sc);

    /* Enable SI clock */
    A_PCI_WRITE32(sc->mem + (RTC_SOC_BASE_ADDRESS + CLOCK_CONTROL_OFFSET), 0x0);

    /* Configure GPIOs for I2C operation */
    A_PCI_WRITE32(sc->mem + (GPIO_BASE_ADDRESS + GPIO_PIN0_OFFSET + I2C_SDA_GPIO_PIN*4),
                     (WLAN_GPIO_PIN0_CONFIG_SET(I2C_SDA_PIN_CONFIG) |
                      WLAN_GPIO_PIN0_PAD_PULL_SET(1)));

    A_PCI_WRITE32(sc->mem + (GPIO_BASE_ADDRESS + GPIO_PIN0_OFFSET + SI_CLK_GPIO_PIN*4),
                     (WLAN_GPIO_PIN0_CONFIG_SET(SI_CLK_PIN_CONFIG) |
                      WLAN_GPIO_PIN0_PAD_PULL_SET(1)));

    A_PCI_WRITE32(sc->mem + (GPIO_BASE_ADDRESS + GPIO_ENABLE_W1TS_LOW_ADDRESS),
                      1 << SI_CLK_GPIO_PIN);

    /* In Swift ASIC - EEPROM clock will be (110MHz/512) = 214KHz */
    A_PCI_WRITE32(sc->mem + (SI_BASE_ADDRESS + SI_CONFIG_OFFSET),
                      (SI_CONFIG_ERR_INT_SET(1) |
                      SI_CONFIG_BIDIR_OD_DATA_SET(1) |
                      SI_CONFIG_I2C_SET(1) |
                      SI_CONFIG_POS_SAMPLE_SET(1) |
                      SI_CONFIG_INACTIVE_CLK_SET(1) |
                      SI_CONFIG_INACTIVE_DATA_SET(1) |
                      SI_CONFIG_DIVIDER_SET(8)));

}

#define SI_OK                               1
#define SI_ERR                              0
#define DEVICE_SELECT                       0xa0
#define DEVICE_READ                         0xa1000000
#define EEPROM_ADDR_OFFSET_LEN              16 /* in bits */
#define EEPROM_ADDR_OFFSET_LOWER_BYTE_MASK  0x00ff
#define EEPROM_ADDR_OFFSET_UPPER_BYTE_MASK  0xff00

#define MAX_WAIT_COUNTER_POLL_DONE_BIT      100000 /* 1 sec(100000 * 10 usecs) */
#define DELAY_BETWEEN_DONE_BIT_POLL         10     /* In usecs */
static int eeprom_byte_read(struct ath_hif_pci_softc *sc, u_int16_t addr_offset, u_int8_t *data)
{
    u_int32_t reg;
    int wait_limit;

    /* set device select byte and for the read operation */
    reg = DEVICE_SELECT |
          ((addr_offset & EEPROM_ADDR_OFFSET_LOWER_BYTE_MASK) << EEPROM_ADDR_OFFSET_LEN) |
          (addr_offset & EEPROM_ADDR_OFFSET_UPPER_BYTE_MASK) |
          DEVICE_READ ;
    A_PCI_WRITE32(sc->mem + SI_BASE_ADDRESS + SI_TX_DATA0_OFFSET, reg);

    /* write transmit data, transfer length, and START bit */
    A_PCI_WRITE32(sc->mem + SI_BASE_ADDRESS + SI_CS_OFFSET,
                                (SI_CS_START_SET(1) |
                                 SI_CS_RX_CNT_SET(1) |
                                 SI_CS_TX_CNT_SET(4)));

    wait_limit = MAX_WAIT_COUNTER_POLL_DONE_BIT;
    /* poll CS_DONE_INT bit */
    reg = A_PCI_READ32(sc->mem + SI_BASE_ADDRESS + SI_CS_OFFSET);
    /* Wait for maximum 1 sec */
    while((wait_limit--) && ((reg & SI_CS_DONE_INT_MASK) != SI_CS_DONE_INT_MASK)) {
            OS_DELAY(DELAY_BETWEEN_DONE_BIT_POLL);
            reg = A_PCI_READ32(sc->mem + SI_BASE_ADDRESS + SI_CS_OFFSET);
    }
    if(wait_limit == 0) {
        printk("%s: Timeout waiting for DONE_INT bit to be set in SI_CONFIG register\n", __func__);
        return SI_ERR;
    }

    /*
     * Clear DONE_INT bit
     * DONE_INT bit is cleared when 1 is written to this field (or) when the
     * START bit is set in this register
     */
    A_PCI_WRITE32(sc->mem + SI_BASE_ADDRESS + SI_CS_OFFSET, reg);

    if((reg & SI_CS_DONE_ERR_MASK) == SI_CS_DONE_ERR_MASK)
    {
        return SI_ERR;
    }

    /* extract receive data */
    reg = A_PCI_READ32(sc->mem + SI_BASE_ADDRESS + SI_RX_DATA0_OFFSET);
    *data = (reg & 0xff);

    return SI_OK;
}
int
ol_transfer_target_eeprom_caldata(struct ol_ath_softc_net80211 *scn, u_int32_t address, bool compressed)
{
    int status = EOK;
    struct firmware fwtemp;
    struct firmware *fw_entry = &fwtemp;
    u_int32_t fw_entry_size, orig_size = 0;
    int i;
    uint32_t *savedestp, *destp, *srcp = NULL;
    u_int8_t *pdst, *psrc,*ptr = NULL;

    struct ath_hif_pci_softc *sc = (struct ath_hif_pci_softc *)(scn->hif_sc);
    if(!sc) {
        printk("ERROR: sc ptr is NULL\n");
        return -EINVAL;
    }
    // Check for target/host driver mismatch
    if ( scn->target_version != AR9887_REV1_VERSION) {
        printk("ERROR: UNSUPPORTED TARGET VERSION 0x%x \n", scn->target_version);
        return EOK;
    }
    else {
        u_int8_t *tmp_ptr;
        u_int16_t addr_offset;
        ptr = vmalloc(QC98XX_EEPROM_SIZE_LARGEST);
        if ( NULL == ptr ){
        printk("%s %d: target eeprom caldata memory allocation failed\n",__func__, __LINE__);
        return -EINVAL;
        } else {
            tmp_ptr = ptr;
            /* Config for Target EEPROM access */
            config_target_eeprom(scn);
            /* For Swift 2116 bytes of caldata is stored in target */
            for(addr_offset = 0;  addr_offset < QC98XX_EEPROM_SIZE_LARGEST; addr_offset++) {
                if(eeprom_byte_read(sc, addr_offset, tmp_ptr) != SI_OK) {
                    if (ptr)
                        vfree(ptr);
                    return -EINVAL;
                }
                tmp_ptr++;
            }
            if (le16_to_cpu(*(uint16_t *)ptr) != QC98XX_EEPROM_SIZE_LARGEST) {
                printk("%s: Target EEPROM caldata len %d doesn't equal to %d\n", __func__,
                        le16_to_cpu(*(uint16_t *)ptr), QC98XX_EEPROM_SIZE_LARGEST);
                if (ptr)
                    vfree(ptr);
                return -EINVAL;
            }
#if 0            
            if (qc98xx_verify_checksum(ptr)){
                if (ptr)
                    vfree(ptr);
                return -EINVAL;
            }
#endif           
            srcp = (uint32_t *)ptr;
            orig_size = QC98XX_EEPROM_SIZE_LARGEST;
            fw_entry->data = ptr;
            fw_entry->size = (orig_size + 3) & ~3;
            printk("%s %d: Download Target EEPROM caldata len %d\n",
                    __func__, __LINE__, fw_entry->size);

            savedestp = destp = vmalloc(fw_entry->size);
            if(destp == NULL)
            {
                if (ptr)
                    vfree(ptr);
                printk("%s %d: memory allocation failed\n",__func__, __LINE__);
                return -EINVAL;
            }
            pdst = (uint8_t *)destp;
            psrc = (uint8_t *)srcp;

            /* Add pad bytes if required */
            for (i = 0; i < fw_entry->size; i++) {
                if (i < orig_size)
                    pdst[i] = psrc[i];
                else
                    pdst[i] = 0;
            }
            for(i=0; i < (fw_entry->size)/4; i++) {
                *destp = cpu_to_le32(*srcp);
                destp++; srcp++;
            }

            destp = savedestp;
            fw_entry_size = fw_entry->size;

            if (compressed) {
                status = BMIFastDownload(scn->hif_hdl, address, (u_int8_t *)destp, fw_entry_size, scn);
            } else {
                status = BMIWriteMemory(scn->hif_hdl, address, (u_int8_t *)destp, fw_entry_size, scn);
            }
        }

        if (status != EOK) {
            printk("%s :%d BMI operation failed \n",__func__, __LINE__);
        }

        if (ptr)
            vfree(ptr);

        if(destp)
            vfree(destp);

        if (status != EOK) {
            return -1;
        }
      return status;
    }
}
#ifdef LOAD_ARRAY_FW
int
ol_transfer_bin_file(struct ol_ath_softc_net80211 *scn, ATH_BIN_FILE file,
                    u_int32_t address, bool compressed)
{
    int status = EOK;
    struct firmware fwtemp;
    struct firmware *fw_entry = &fwtemp;
    u_int32_t fw_entry_size, orig_size = 0;
    u_int8_t *tempEeprom;
    u_int32_t board_data_size;
    int i;
    uint32_t *savedestp, *destp, *srcp = NULL;
    u_int8_t *pdst, *psrc,*ptr = NULL;
    int unknown_target_ver = 0;

    // Check for target/host driver mismatch
    if (   scn->target_version != AR6004_REV1_VERSION
        && scn->target_version != AR9888_REV2_VERSION
        && scn->target_version != AR9887_REV1_VERSION
        && scn->target_version != AR9888_DEV_VERSION
        && scn->target_version != SOC_SW_VERSION) {
            unknown_target_ver = 1;
            printk("ERROR: UNSUPPORTED TARGET VERSION 0x%x \n", scn->target_version);
    }

    switch (file)
    {
        default:
            printk("%s: Unknown file type\n", __func__);
            return -1;

        case ATH_OTP_FILE:
            if (unknown_target_ver) {
                printk("%s: no OTP file defined\n", __func__);
                return -ENOENT;
            }
            break;

        case ATH_FIRMWARE_FILE:
            if (unknown_target_ver) {
                printk("%s: no firmware file defined\n", __func__);
                return -ENOENT;
            }

#ifdef EPPING_TEST
            if (eppingtest) {
                bypasswmi = TRUE;
                compressed = 0;
            }
#endif
            break;

        case ATH_PATCH_FILE:
            printk("%s: no Patch file defined\n", __func__);
            return EOK;

        case ATH_BOARD_DATA_FILE:
            if (unknown_target_ver) {
                printk("%s: no Board data file defined\n", __func__);
                return EOK;
            }
            break;

        case ATH_FLASH_FILE:
            if (unknown_target_ver) {
                printk("%s: no flash data file defined\n", __func__);
                return EOK;
            }
            break;
    }

    /*
     * Logic below is added to support BIG ENDIAN Host by converting
     * all byte array for big endian. This has dependency on
     * Copy Engine configuration and should be changed in sync with
     * its configuration.
     */

    if(file == ATH_OTP_FILE) {
        if (scn->target_version == AR9888_REV2_VERSION) {
            srcp = (uint32_t *) otp_AR9888v2_bin;
            fw_entry->data = otp_AR9888v2_bin;
            orig_size = sizeof(otp_AR9888v2_bin);
        }
        else if (scn->target_version == AR9887_REV1_VERSION) {
            srcp = (uint32_t *) otp_AR9887v1_bin;
            fw_entry->data = otp_AR9887v1_bin;
            orig_size = sizeof(otp_AR9887v1_bin);
        }
        fw_entry->size = (orig_size + 3) & ~3; /* round off to 4 bytes */
	printk("%s %d: Download OTP data len %d\n",
                __func__, __LINE__, fw_entry->size);
    }
    else if(file == ATH_BOARD_DATA_FILE) {
	    srcp = (uint32_t *) raw_Data;
	    fw_entry->data = raw_Data;
	    orig_size = sizeof(raw_Data);
            fw_entry->size = (orig_size + 3) & ~3; /* round off to 4 bytes */
	    printk("%s %d: Download Board data len %d\n",
                __func__, __LINE__, fw_entry->size);
    }
    else if(file == ATH_FIRMWARE_FILE) {
         if (testmode == 1) {
             A_UINT32 param;
             if (scn->target_version == AR9888_REV2_VERSION) {
                 srcp = (uint32_t *) utf_AR9888v2_bin;
                 fw_entry->data = utf_AR9888v2_bin;
                 orig_size = sizeof(utf_AR9888v2_bin);
             }
             else if(scn->target_version == AR9887_REV1_VERSION) {
                 srcp = (uint32_t *) utf_AR9887v1_bin;
                 fw_entry->data = utf_AR9887v1_bin;
                 orig_size = sizeof(utf_AR9887v1_bin);
             }
             printk("%s[%d] LOAD UTF orig_size=%d\n", __func__, __LINE__,orig_size);
             fw_entry->size = (orig_size + 3) & ~3; /* round off to 4 bytes */
             printk("%s %d: Download Firmware data len %d\n",
                 __func__, __LINE__, fw_entry->size);

            if (BMIReadMemory(scn->hif_hdl,
                host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_fw_swap)),
                (A_UCHAR *)&param,
                4, scn)!= A_OK)
            {
                printk("BMIReadMemory for setting FW swap flags failed \n");
                return A_ERROR;
            }
            param |= HI_DESC_IN_FW_BIT;
            if (BMIWriteMemory(scn->hif_hdl,
               host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_fw_swap)),
                (A_UCHAR *)&param,
                4, scn) != A_OK)
            {
                printk("BMIWriteMemory for setting FW swap flags failed \n");
                return A_ERROR;
            }
        } else {
            if (scn->target_version == AR9888_REV2_VERSION) {
                if (scn->enable_max_clients) {
                    printk(" Download AR9888v2_max_clients_bin\n");
                    srcp = (uint32_t *) athwlan_AR9888v2_max_clients_bin;
                    fw_entry->data = athwlan_AR9888v2_max_clients_bin;
                    orig_size = sizeof(athwlan_AR9888v2_max_clients_bin);
                }
#ifndef HOST_OFFLOAD
                    /*
                     * The size of image is exceeding limit for
                     * full-offload target build, so not including this
                     * firmware (and not enabling it in the driver too)
                     * for that particular build. Anyways this is
                     * enabled with a module param, so can't be used in
                     * full-offload mode.
                     */
                else if (scn->lteu_support) {
                    printk(" Download AR9888v2_lteu_bin\n");
                    srcp = (uint32_t *) athwlan_AR9888v2_lteu_bin;
                    fw_entry->data = athwlan_AR9888v2_lteu_bin;
                    orig_size = sizeof(athwlan_AR9888v2_lteu_bin);
                }
#endif
                else {
                    printk(" Download AR9888v2_bin\n");
                    srcp = (uint32_t *) athwlan_AR9888v2_bin;
                    fw_entry->data = athwlan_AR9888v2_bin;
                    orig_size = sizeof(athwlan_AR9888v2_bin);
                }
            }
            else if(scn->target_version == AR9887_REV1_VERSION) {
                printk("Swift firmware download\n");
                srcp = (uint32_t *) athwlan_AR9887v1_bin;
                fw_entry->data = athwlan_AR9887v1_bin;
                orig_size = sizeof(athwlan_AR9887v1_bin);
            }
            fw_entry->size = (orig_size + 3) & ~3; /* round off to 4 bytes */
            printk("%s %d: Download Firmware data len %d\n",
                __func__, __LINE__, fw_entry->size);
        }
    }
    else if (file == ATH_FLASH_FILE) {
#ifdef  ATH_CAL_NAND_FLASH
        int ret_val=0,ret_len;
        u_int32_t cal_location = CalAddr[pci_dev_cnt-1];
        printk(KERN_ERR "Cal location [%d]: %08x\n", pci_dev_cnt-1, cal_location);
        ptr = vmalloc(QC98XX_EEPROM_SIZE_LARGEST);
        if ( NULL == ptr ){
            printk("%s %d: flash cal data(NAND)memory allocation failed\n",__func__, __LINE__);
            return -EINVAL;
        }
        else {
            ret_val = OS_NAND_FLASH_READ(ATH_CAL_NAND_PARTITION, cal_location + FLASH_CAL_START_OFFSET ,QC98XX_EEPROM_SIZE_LARGEST,&ret_len,ptr);
            if (ret_val){
                printk("%s %d: flash cal data(NAND) read failed\n",__func__, __LINE__ );
                if (ptr)
                    vfree(ptr);
                return -EINVAL;
            }
        }
#else
#ifdef ATH_CAL_FROM_FILE_11AC_PCIE
		const struct firmware *board;
		if (request_firmware(&board, ATH_CAL_FROM_FILE_11AC_PCIE, scn->sc_osdev->device)) {
			printk("%s: failed loading cal data from /lib/firmware/%s\n", __func__, ATH_CAL_FROM_FILE_11AC_PCIE);
			return -EINVAL;
		}
		ptr = board->data;
#else
        ptr = scn->cal_mem + FLASH_CAL_START_OFFSET;
        if (!scn->cal_mem ){
            printk("%s: flash cal data address is not mapped\n", __func__);
            return -EINVAL;
        }
#endif
#endif
        if (!scn->cal_in_flash) {
            printk("%s: flash cal data address is not mapped\n", __func__);
            return -EINVAL;
        }
        if (le16_to_cpu(*(uint16_t *)ptr) != QC98XX_EEPROM_SIZE_LARGEST) {
            printk("%s: flash cal data len %d doesn't equal to %d\n", __func__,
                    le16_to_cpu(*(uint16_t *)ptr), QC98XX_EEPROM_SIZE_LARGEST);
#ifdef ATH_CAL_NAND_FLASH
            if (ptr)
                vfree(ptr);
#endif
#ifdef ATH_CAL_FROM_FILE_11AC_PCIE
			if (ptr)
				release_firmware(board);
#endif
			printk("%s: flash cal data checksum verification failed\n", __func__);

            return -EINVAL;
        }
#if 0        
        if (qc98xx_verify_checksum(ptr)){
#ifdef ATH_CAL_NAND_FLASH
            if (ptr)
                vfree(ptr);
#endif
            return -EINVAL;
        }
#endif
        srcp = (uint32_t *)ptr;
        orig_size = QC98XX_EEPROM_SIZE_LARGEST;
        fw_entry->data = ptr;
        fw_entry->size = (orig_size + 3) & ~3;
        printk("%s %d: Download Flash data len %d\n",
                __func__, __LINE__, fw_entry->size);
    }
    savedestp = destp = vmalloc(fw_entry->size);
    if(destp == NULL)
    {
        printk("%s %d: memory allocation failed\n",__func__, __LINE__);
        return -EINVAL;
    }
    pdst = (uint8_t *)destp;
    psrc = (uint8_t *)srcp;

    /* Add pad bytes if required */
    for (i = 0; i < fw_entry->size; i++) {
        if (i < orig_size)
            pdst[i] = psrc[i];
        else
            pdst[i] = 0;
    }
    for(i=0; i < (fw_entry->size)/4; i++) {
	    *destp = cpu_to_le32(*srcp);
	    destp++; srcp++;
    }

    destp = savedestp;
    fw_entry_size = fw_entry->size;
    tempEeprom = NULL;

    if ((file == ATH_BOARD_DATA_FILE || file == ATH_FLASH_FILE) && destp)
    {
        u_int32_t board_ext_address;
        int32_t board_ext_data_size;

        tempEeprom = vmalloc(fw_entry->size);
        if (!tempEeprom) {
            printk("%s: Memory allocation failed\n", __func__);
            return A_ERROR;
        }

        switch (scn->target_type)
        {
            default:
                board_ext_data_size = 0;
                break;
            case TARGET_TYPE_AR6004:
                board_data_size =  AR6004_BOARD_DATA_SZ;
                board_ext_data_size = AR6004_BOARD_EXT_DATA_SZ;
                break;
            case TARGET_TYPE_AR9888:
                board_data_size =  AR9888_BOARD_DATA_SZ;
                board_ext_data_size = AR9888_BOARD_EXT_DATA_SZ;
                break;
        }

        OS_MEMCPY(tempEeprom, (u_int8_t *)destp, fw_entry->size);

#ifdef SOFTMAC_FILE_USED
        ar6000_softmac_update(ar, tempEeprom, board_data_size);
#endif

        /* Determine where in Target RAM to write Board Data */
        status = BMIReadMemory(scn->hif_hdl,
                    HOST_INTEREST_ITEM_ADDRESS(scn->target_type, hi_board_ext_data),
                    (u_int8_t *)&board_ext_address, 4, scn);

        if (status != EOK){
            printk("%s : %d BMIReadMemory failed\n", __func__,__LINE__);
            goto bad;
        }
        /*
         * Check whether the target has allocated memory for extended board
         * data and file contains extended board data
         */
        if ((board_ext_address) && (fw_entry->size == (board_data_size + board_ext_data_size)))
        {
            u_int32_t param;

            status = BMIWriteMemory(scn->hif_hdl, board_ext_address,
                    (u_int8_t *)(((A_UINT32)tempEeprom) + board_data_size), board_ext_data_size, scn);

            if (status != EOK) {
                printk("%s: BMI operation failed: %d\n", __func__, __LINE__);
                goto bad;
            }

            /* Record the fact that extended board Data IS initialized */
            param = (board_ext_data_size << 16) | 1;
            status = BMIWriteMemory(scn->hif_hdl,
                    HOST_INTEREST_ITEM_ADDRESS(scn->target_type, hi_board_ext_data_config),
                    (u_int8_t *)&param, 4, scn);

            if (status != EOK) {
                printk("%s : %d BMIWriteMemory failed\n", __func__,__LINE__);
                goto bad;
            }
        }
        /* below line of code is commented as the the allocated memory using
         * vmalloc is 2116 bytes but trying to access (read) beyond that in
         *  below BMIWriteMemory because board_data_size is 7168
         */
        //fw_entry_size = board_data_size;
    }

    if (compressed) {
        status = BMIFastDownload(scn->hif_hdl, address, (u_int8_t *)destp, fw_entry_size, scn);
    } else {
        if ((file == ATH_BOARD_DATA_FILE || file == ATH_FLASH_FILE) && destp) {
            status = BMIWriteMemory(scn->hif_hdl, address, (u_int8_t *)tempEeprom, fw_entry_size, scn);
        } else {
            status = BMIWriteMemory(scn->hif_hdl, address, (u_int8_t *)destp, fw_entry_size, scn);
        }
    }

    if (status != EOK) {
        printk("%s :%d BMI operation failed \n",__func__, __LINE__);
    }
bad:
    if (tempEeprom) {
        vfree(tempEeprom);
    }
    if (file == ATH_FLASH_FILE){
#ifdef ATH_CAL_NAND_FLASH
        if (ptr)
            vfree(ptr);
#endif
    }

    if(destp)
	    vfree(destp);

    if (status != EOK) {
        return -1;
    }

    return status;
}
#else // LOAD_ARRAY_FW
int
ol_transfer_bin_file(struct ol_ath_softc_net80211 *scn, ATH_BIN_FILE file,
                    u_int32_t address, bool compressed)
{
    int status = EOK;
    const char *filename = NULL;
    const struct firmware *fw_entry;
    u_int32_t fw_entry_size;
    u_int8_t *tempEeprom;
    u_int32_t board_data_size;

    switch (file)
    {
        default:
            printk("%s: Unknown file type\n", __func__);
            return -1;

        case ATH_OTP_FILE:
            if (scn->target_version == AR6004_REV1_VERSION) {
                filename = AR6004_REV1_OTP_FILE;
            } else if (scn->target_version == AR9888_REV2_VERSION) {
                filename = AR9888_REV2_OTP_FILE;
            } else if (scn->target_version == AR9887_REV1_VERSION) {
                filename = AR9887_REV1_OTP_FILE;
            } else if (scn->target_version == AR9888_DEV_VERSION) {
                filename = AR9888_DEV_OTP_FILE;
            } else if (scn->target_version == SOC_SW_VERSION) {
                filename = ARXXXX_DEV_OTP_FILE;
            } else {
                printk("%s: no OTP file defined\n", __func__);
                return -ENOENT;
            }
            break;

        case ATH_FIRMWARE_FILE:
            if ( testmode ) {
                if ( testmode == 1 ) {
                    if (scn->target_version == AR6004_REV1_VERSION) {
                        filename = AR6004_REV1_UTF_FIRMWARE_FILE;
                    } else if (scn->target_version == AR9888_REV2_VERSION) {
                        filename = AR9888_REV2_UTF_FIRMWARE_FILE;
                    } else if (scn->target_version == AR9887_REV1_VERSION) {
                        filename = AR9887_REV1_UTF_FIRMWARE_FILE;
                    } else if (scn->target_version == AR9888_DEV_VERSION) {
                        filename = AR9888_DEV_UTF_FIRMWARE_FILE;
                    } else if (scn->target_version == SOC_SW_VERSION) {
                        filename = ARXXXX_DEV_UTF_FIRMWARE_FILE;
                    } else {
                        printk("%s: no firmware file defined\n", __func__);
                        return EOK;
                    }
                }
            }
            else {
                if (scn->target_version == AR6004_REV1_VERSION) {
                    filename = AR6004_REV1_FIRMWARE_FILE;
                } else if (scn->target_version == AR9888_REV2_VERSION) {
                    filename = AR9888_REV2_FIRMWARE_FILE;
                } else if (scn->target_version == AR9887_REV1_VERSION) {
                    filename = AR9887_REV1_FIRMWARE_FILE;
                } else if (scn->target_version == AR9888_DEV_VERSION) {
                    filename = AR9888_DEV_FIRMWARE_FILE;
                } else if (scn->target_version == SOC_SW_VERSION) {
                    filename = ARXXXX_DEV_FIRMWARE_FILE;
                } else {
                    printk("%s: no firmware file defined\n", __func__);
                    return EOK;
                }
            }

#ifdef EPPING_TEST
            if (eppingtest) {
                bypasswmi = TRUE;
                filename = AR6004_REV1_EPPING_FIRMWARE_FILE;
                compressed = 0;
            }
#endif
            break;

        case ATH_PATCH_FILE:
            printk("%s: no Patch file defined\n", __func__);
            return EOK;

        case ATH_BOARD_DATA_FILE:
            if (scn->target_version == AR6004_REV1_VERSION) {
                filename = AR6004_REV1_BOARD_DATA_FILE;
                printk("%s: Board data file AR6004\n", __func__);
            } else if (scn->target_version == AR9888_REV2_VERSION) {
                filename = AR9888_REV2_BOARD_DATA_FILE;
                printk("%s: Board data file AR9888v2\n", __func__);
            } else if (scn->target_version == AR9887_REV1_VERSION) {
                filename = AR9887_REV1_BOARD_DATA_FILE;
                printk("%s: Board data file AR9887v1\n", __func__);
            } else if (scn->target_version == AR9888_DEV_VERSION) {
                filename = AR9888_DEV_BOARD_DATA_FILE;
                printk("%s: Board data file AR9888\n", __func__);
            } else if (scn->target_version == SOC_SW_VERSION) {
                filename = ARXXXX_DEV_BOARD_DATA_FILE;
                printk("%s: Board data file ARXXXX v=0x%x\n", __func__, scn->target_version);
            } else {
                printk("%s: no Board data file defined\n", __func__);
                return EOK;
            }
            break;

    }

    if (request_firmware(&fw_entry, filename, scn->sc_osdev->device) != 0)
    {
        printk("%s: Failed to get %s\n", __func__, filename);

        if ( file == ATH_OTP_FILE )
        {
            return -ENOENT;
        }
        return -1;
    }

    fw_entry_size = fw_entry->size;
    tempEeprom = NULL;

    if (file == ATH_BOARD_DATA_FILE && fw_entry->data)
    {
        u_int32_t board_ext_address;
        int32_t board_ext_data_size;

        tempEeprom = OS_MALLOC(scn->sc_osdev, fw_entry_size, GFP_ATOMIC);
        if (!tempEeprom) {
            printk("%s: Memory allocation failed\n", __func__);
            release_firmware(fw_entry);
            return A_ERROR;
        }

        OS_MEMCPY(tempEeprom, (u_int8_t *)fw_entry->data, fw_entry_size);

        switch (scn->target_type)
        {
            default:
                board_ext_data_size = 0;
                break;
            case TARGET_TYPE_AR6004:
                board_data_size =  AR6004_BOARD_DATA_SZ;
                board_ext_data_size = AR6004_BOARD_EXT_DATA_SZ;
            case TARGET_TYPE_AR9888:
                board_data_size =  AR9888_BOARD_DATA_SZ;
                board_ext_data_size = AR9888_BOARD_EXT_DATA_SZ;
                break;
        }

#ifdef SOFTMAC_FILE_USED
        ar6000_softmac_update(ar, tempEeprom, board_data_size);
#endif

        /* Determine where in Target RAM to write Board Data */
        BMIReadMemory(scn->hif_hdl,
                HOST_INTEREST_ITEM_ADDRESS(scn->target_type, hi_board_ext_data),
                (u_int8_t *)&board_ext_address, 4, scn);
        printk("Board extended Data download address: 0x%x\n", board_ext_address);

        /*
         * Check whether the target has allocated memory for extended board
         * data and file contains extended board data
         */
        if ((board_ext_address) && (fw_entry_size == (board_data_size + board_ext_data_size)))
        {
            u_int32_t param;

            status = BMIWriteMemory(scn->hif_hdl, board_ext_address,
                    (u_int8_t *)(((A_UINT32)tempEeprom) + board_data_size), board_ext_data_size, scn);

            if (status != EOK) {
                printk("%s: BMI operation failed: %d\n", __func__, __LINE__);
                release_firmware(fw_entry);
                return -1;
            }

            /* Record the fact that extended board Data IS initialized */
            param = (board_ext_data_size << 16) | 1;
            BMIWriteMemory(scn->hif_hdl,
                    HOST_INTEREST_ITEM_ADDRESS(scn->target_type, hi_board_ext_data_config),
                    (u_int8_t *)&param, 4, scn);

            fw_entry_size = board_data_size;
        }
    }

    if (compressed) {
        status = BMIFastDownload(scn->hif_hdl, address, (u_int8_t *)fw_entry->data, fw_entry_size, scn);
    } else {
        if (file==ATH_BOARD_DATA_FILE && fw_entry->data) {
            status = BMIWriteMemory(scn->hif_hdl, address, (u_int8_t *)tempEeprom, fw_entry_size, scn);
        } else {
            status = BMIWriteMemory(scn->hif_hdl, address, (u_int8_t *)fw_entry->data, fw_entry_size, scn);
        }
    }

    if (tempEeprom) {
        OS_FREE(tempEeprom);
    }

    if (status != EOK) {
        printk("BMI operation failed: %d\n", __LINE__);
        release_firmware(fw_entry);
        return -1;
    }

    release_firmware(fw_entry);

    return status;
}
#endif // LOAD_ARRAY_FW

int
__ol_ath_check_wmi_ready(struct ol_ath_softc_net80211 *scn)
{
    int32_t timeleft;

    timeleft = wait_event_interruptible_timeout(scn->sc_osdev->event_queue,
                (scn->wmi_ready == TRUE), scn->sc_osdev->wmi_timeout * HZ);

    if (!timeleft)
    {
        printk("WMI is not ready\n");
        return -EIO;
    } else if (signal_pending(current)) {
        printk("Wait was interrupted by a signal. Error code = %d\n", timeleft);

        /* WAR: Wait uninterrupted for a small amount of time to give a chance
         * to pending events to come through. Else we could have issues on
         * preemptible kernels leading to crashes in the control stack since
         * communication is attempted when our caller is doing a cleanup. The
         * wait is expected to be very short if the FW is working correctly (a
         * max of ~200 ms has been seen so far).
         *
         * This is a reasonable trade-off versus having multiple lock checks
         * deep in the stack - this would touch all WMI communication and impose
         * unnecessary penalties for an init time requirement (there exist
         * scenarios requiring high WMI event traffic during regular operation
         * post init).
         */

        printk("Waiting uninterrupted for %u second(s) before returning\n",
                    WMI_TIMEOUT_UNINTERRUPT);
        timeleft = wait_event_timeout(scn->sc_osdev->event_queue,
                (scn->wmi_ready == TRUE), WMI_TIMEOUT_UNINTERRUPT * HZ);

        if (!timeleft && scn->wmi_ready != TRUE) {
            printk("**WMI ready not received from FW despite wait of %u "
                   "second(s). Investigate!! Bailing out**\n",
                   WMI_TIMEOUT_UNINTERRUPT);
        }

        /* Return irrespective of result */
        return -EIO;
    }

    if (scn->version.abi_ver != SOC_ABI_VERSION) {
        printk("ABI Version mismatch: Host(0x%x), Target(0x%x)\n",
                SOC_ABI_VERSION, scn->version.abi_ver);
    }

    return EOK;
}

void
__ol_ath_wmi_ready_event(struct ol_ath_softc_net80211 *scn)
{
    wake_up(&scn->sc_osdev->event_queue);
}

#define BMI_EXCHANGE_TIMEOUT_MS  1000

/*
 * Issue a BMI command from a user agent to a Target.
 *
 * Note: A single buffer is used for requests and responses.
 * Synchronization is not enforced by this module.
 */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,35)
static ssize_t
ath_sysfs_BMI_write(struct file *file, struct kobject *kobj,
                   struct bin_attribute *bin_attr,
                   char *buf, loff_t pos, size_t count)
#else
static ssize_t
ath_sysfs_BMI_write(struct kobject *kobj,
                   struct bin_attribute *bin_attr,
                   char *buf, loff_t pos, size_t count)
#endif
{
    struct ol_ath_softc_net80211 *scn = (struct ol_ath_softc_net80211 *)(bin_attr->private);
    A_UINT32 cmd;
    unsigned int nbytes;
    A_UINT8 *bmi_response_buf;
    u_int32_t *bmi_response_lengthp;

    nbytes = min(count, (size_t)BMI_DATASZ_MAX);
    OS_MEMCPY(scn->pBMICmdBuf, buf, nbytes); /* NB: buf is in kernel space */
    cmd = *((A_UINT32 *)scn->pBMICmdBuf); /* peek at command */

    if (cmd == BMI_DONE) {
        /*
         * Handle BMI_DONE specially -- signal
         * that the BMI user agent is done.
         */
        ol_ath_signal_bmi_user_agent_done(scn);
        return nbytes;
    }

    switch(cmd) {
    /* Commands that expect a response from the Target */
    case BMI_READ_MEMORY:
    case BMI_EXECUTE:
    case BMI_READ_SOC_WORD:
    case BMI_GET_TARGET_INFO:
    case BMI_ROMPATCH_INSTALL:
    case BMI_NVRAM_PROCESS:
        bmi_response_buf = scn->pBMIRspBuf;
        bmi_response_lengthp = &scn->last_rxlen;
        break;

    /* Commands that do NOT expect a response from the Target */
    case BMI_WRITE_MEMORY:
    case BMI_SET_APP_START:
    case BMI_WRITE_SOC_WORD:
    case BMI_ROMPATCH_UNINSTALL:
    case BMI_ROMPATCH_ACTIVATE:
    case BMI_ROMPATCH_DEACTIVATE:
    case BMI_LZ_STREAM_START:
    case BMI_LZ_DATA:
        bmi_response_buf = NULL;
        bmi_response_lengthp = NULL;
        break;

    default:
        printk(KERN_ERR "BMI sysfs command unknown (%d)\n", cmd);
        return A_ERROR;
    }

    if (A_OK != HIFExchangeBMIMsg(scn->hif_hdl,
                               scn->pBMICmdBuf,
                               (A_UINT32)nbytes,
                               bmi_response_buf,
                               bmi_response_lengthp,
                               BMI_EXCHANGE_TIMEOUT_MS))

    {
        printk(KERN_ERR "BMI sysfs command failed\n");
        return A_ERROR;
    }

    return nbytes;
}

/*
 * Pass a Target's response back to a user agent.  The response
 * is to a BMI command that was issued earlier through
 * ath_sysfs_BMI_write.
 */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,35)
static ssize_t
ath_sysfs_BMI_read(struct file *file, struct kobject *kobj,
                   struct bin_attribute *bin_attr,
                   char *buf, loff_t pos, size_t count)
#else
static ssize_t
ath_sysfs_BMI_read(struct kobject *kobj,
                   struct bin_attribute *bin_attr,
                   char *buf, loff_t pos, size_t count)
#endif
{
    struct ol_ath_softc_net80211 *scn = (struct ol_ath_softc_net80211 *)(bin_attr->private);
    unsigned int nbytes;

    nbytes = min(count, scn->last_rxlen);
    OS_MEMCPY(buf, scn->pBMIRspBuf, nbytes); /* NB: buf is in kernel space */

    return nbytes;
}

unsigned int
ol_ath_bmi_user_agent_init(struct ol_ath_softc_net80211 *scn)
{
    int ret;
    struct bin_attribute *BMI_fsattr;

    if (!bmi) {
        return 0; /* User agent not requested */
    }

    scn->bmiUADone = FALSE;

    BMI_fsattr = OS_MALLOC(scn->sc_osdev, sizeof(*BMI_fsattr), GFP_KERNEL);
    if (!BMI_fsattr) {
        printk("%s: Memory allocation failed\n", __func__);
        return 0;
    }
    OS_MEMZERO(BMI_fsattr, sizeof(*BMI_fsattr));

    BMI_fsattr->attr.name = "bmi";
    BMI_fsattr->attr.mode = 0600;
    BMI_fsattr->read = ath_sysfs_BMI_read;
    BMI_fsattr->write = ath_sysfs_BMI_write;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,34)
    sysfs_bin_attr_init(BMI_fsattr);
#endif
    ret = sysfs_create_bin_file(&scn->sc_osdev->device->kobj, BMI_fsattr);
    if (ret) {
        printk("%s: sysfs create failed\n", __func__);
        OS_FREE(BMI_fsattr);
        return 0;
    }

    BMI_fsattr->private = scn;
    scn->bmi_ol_priv = (void *)BMI_fsattr;

    return bmi;
}

int
ol_ath_wait_for_bmi_user_agent(struct ol_ath_softc_net80211 *scn)
{
    int rv;
    struct bin_attribute *BMI_fsattr = (struct bin_attribute *)scn->bmi_ol_priv;

    rv = wait_event_interruptible(scn->sc_osdev->event_queue, (scn->bmiUADone));

    sysfs_remove_bin_file(&scn->sc_osdev->device->kobj, BMI_fsattr);
    scn->bmi_ol_priv = NULL; /* sanity */

    return rv;
}

void
ol_ath_signal_bmi_user_agent_done(struct ol_ath_softc_net80211 *scn)
{
    scn->bmiUADone = TRUE;
    wake_up(&scn->sc_osdev->event_queue);
}

extern void ath_sysfs_diag_init(struct ol_ath_softc_net80211 *scn);
extern void ath_sysfs_diag_fini(struct ol_ath_softc_net80211 *scn);

void
ol_ath_diag_user_agent_init(struct ol_ath_softc_net80211 *scn)
{
#if defined(CONFIG_ATH_SYSFS_DIAG_SUPPORT)
    ath_sysfs_diag_init(scn);
#endif
}

void
ol_ath_diag_user_agent_fini(struct ol_ath_softc_net80211 *scn)
{
#if defined(CONFIG_ATH_SYSFS_DIAG_SUPPORT)
    ath_sysfs_diag_fini(scn);
#endif
}


#if defined(HIF_PCI)
/* BEGIN AR9888v1 WORKAROUND for EV#106293 { */

/*
 * This is a workaround for a HW issue in AR9888v1 in which there is
 * some chance that a write from Host to Target register at address X
 * may have a side effect of writing a value to X+4 (as well as the
 * requested write to X).  The value written to X+4 is whatever value
 * was read by the Host 3 reads prior.  The write to X+4 is just as
 * if software * had done it intentionally (so all effects that would
 * normally occur if that register were written do occur).
 *
 * Example1: Host tries to clear a few bits in a Copy Engine's HOST_IS
 * register (offset 0x30). As a side effect, the CE's MISC_IE register
 * (offset 0x34) is overwritten with a recently read value.
 *
 * Example2: A CE is used for Host to Target transfers, so the
 * Source Ring is maintained by the Host.  When the Host writes the
 * Source Ring Write Index, the Destination Ring Write Index is corrupted.
 *
 * The general workaround is to
 *  A) force the third read prior to a write(X) to be a read(X+4).
 *     That way, when X+4 is overwritten, it will be overwritten
 *     with the value that was there originally.
 *  B) Use a dedicated spin lock and block interrupts in order to
 *     guarantee that the above 3 reads + write occur atomically
 *     with respect to other writes from Host to Target.
 * In addition, special handling is needed for cases when re-writing
 * a value to the register at X+4 has side effects.  The only case
 * of this that occurs in practice is Example2, above.  If we simply
 * allow hardware to re-commit the value in DST_WR_IDX we may run
 * into problems: The Target may update DST_WR_IDX after our first
 * read but before the write. In that case, our re-commit is a
 * stale value. This has a catostophic side-effect because the CE
 * interprets this as a Destination Overflow.  The CE reacts by
 * setting the DST_OVFL bit in MISC_IS and halting the CE. It can
 * only be restarted with a very expensive operation of flushing,
 * re-queueing descriptors (and per-transfer software arguments)
 * and then re-starting the CE.  Rather than attempt this expensive
 * recovery process, we try to avoid this situation by synchronizing
 * Host writes(SR_WR_IDX) with Target writes(DST_WR_IDX).  The
 * currently implementation uses the low bit of DST_WATERMARK
 * register for this synchronization and it relies on reasonable
 * timing characteristics (rather than a stronger synchronization
 * algorithm --  Dekker's, etc.).  Because we rely on timing -- as
 * well as to minimize busy waiting on the Target side -- both
 * Host and Target disable interrupts for the duration of the
 * workaround.
 *
 * The intent is to fix this in HW so this is a temporary workaround.
 */


/*
 * Allow this workaround to be disabled when the driver is loaded
 * by adding "war1=0" to "insmod umac".  There is still a bit of
 * additional overhead.  Can be disabled on the small portion (10%?)
 * of boards that don't suffer from EV#106293.
 */
unsigned int war1 = 1;
module_param(war1, int, 0644);

/*
 * Allow to use CDC WAR which reaches less peak throughput but allow
 * SoC to go to sleep. By default it is disabled.
 */
unsigned int war1_allow_sleep = 0;
module_param(war1_allow_sleep, int, 0644);


DEFINE_SPINLOCK(pciwar_lock);

#define SR_WR_INDEX_ADDRESS                                          0x003c
#define DST_WATERMARK_ADDRESS                                        0x0050
#ifdef CE0_BASE_ADDRESS
#undef CE0_BASE_ADDRESS
#define CE0_BASE_ADDRESS                         0x00057400
#endif
#ifdef CE1_BASE_ADDRESS
#undef CE1_BASE_ADDRESS
#define CE1_BASE_ADDRESS                         0x00057800
#endif
#define CDC_WAR_MAGIC_STR   0xceef0000
#define CDC_WAR_DATA_CE     4

#define CE_BASE_ADDRESS(CE_id) \
	CE0_BASE_ADDRESS + ((CE1_BASE_ADDRESS-CE0_BASE_ADDRESS)*(CE_id))

#define CE_SRC_RING_WRITE_IDX_SET(targid, CE_ctrl_addr, n) \
        A_TARGET_WRITE((targid), (CE_ctrl_addr)+SR_WR_INDEX_ADDRESS, (n))

void CDC_WAR_DISABLE(void)
{
    war1 = 0;
}

void
WAR_CE_SRC_RING_WRITE_IDX_SET(A_target_id_t targid, u_int32_t ctrl_addr, unsigned int write_index)
{
    if (war1) {
        A_target_id_t indicator_addr;

        indicator_addr = TARGID_TO_PCI_ADDR(targid) + ctrl_addr + DST_WATERMARK_ADDRESS;
        if (!war1_allow_sleep && ctrl_addr == CE_BASE_ADDRESS(CDC_WAR_DATA_CE)) {
            A_PCI_WRITE32(indicator_addr, (CDC_WAR_MAGIC_STR | write_index));
        } else {
            unsigned long irq_flags;
            local_irq_save(irq_flags);
            A_PCI_WRITE32(indicator_addr, 1);
#ifndef __ubicom32__
            /*
             * PCIE write waits for ACK in IPQ8K, there is no need
             * to read back value.
             */
            (void)A_PCI_READ32(indicator_addr);
            (void)A_PCI_READ32(indicator_addr); /* conservative */
#endif

            CE_SRC_RING_WRITE_IDX_SET(targid, ctrl_addr, write_index);

            A_PCI_WRITE32(indicator_addr, 0);
            local_irq_restore(irq_flags);
        }
    } else {
        CE_SRC_RING_WRITE_IDX_SET(targid, ctrl_addr, write_index);
    }
}

void
WAR_PCI_WRITE32(char *addr, u32 offset, u32 value)
{
#ifdef QCA_PARTNER_PLATFORM
    WAR_PLTFRM_PCI_WRITE32(addr, offset, value, war1);
#else
    if (war1) {
        unsigned long irq_flags;

        spin_lock_irqsave(&pciwar_lock, irq_flags);

        (void)ioread32((void __iomem *)(addr+offset+4)); /* 3rd read prior to write */
        (void)ioread32((void __iomem *)(addr+offset+4)); /* 2nd read prior to write */
        (void)ioread32((void __iomem *)(addr+offset+4)); /* 1st read prior to write */
        iowrite32((u32)(value), (void __iomem *)(addr+offset));

        spin_unlock_irqrestore(&pciwar_lock, irq_flags);
    } else {
        iowrite32((u32)(value), (void __iomem *)(addr+offset));
    }
#endif
}

EXPORT_SYMBOL(WAR_PCI_WRITE32);
EXPORT_SYMBOL(WAR_CE_SRC_RING_WRITE_IDX_SET);
/* } END AR9888v1 WORKAROUND for EV#106293 */
#endif

/* Update host conig based on Target info */
void ol_ath_host_config_update(struct ol_ath_softc_net80211 *scn)
{
    if (scn->target_version == AR9888_REV2_VERSION || scn->target_version == AR9887_REV1_VERSION) {
        /* AR9888v1 CDC WORKAROUND for EV#106293 */
#if defined(HIF_PCI)
        CDC_WAR_DISABLE();
#endif
    }
}

EXPORT_SYMBOL(__ol_ath_attach);
EXPORT_SYMBOL(__ol_ath_detach);
EXPORT_SYMBOL(ol_transfer_bin_file);
EXPORT_SYMBOL(__ol_ath_target_status_update);
EXPORT_SYMBOL(__ol_ath_check_wmi_ready);
EXPORT_SYMBOL(__ol_ath_wmi_ready_event);
EXPORT_SYMBOL(ol_ath_bmi_user_agent_init);
EXPORT_SYMBOL(ol_ath_wait_for_bmi_user_agent);
EXPORT_SYMBOL(ol_ath_signal_bmi_user_agent_done);
EXPORT_SYMBOL(ol_ath_diag_user_agent_init);
EXPORT_SYMBOL(ol_ath_diag_user_agent_fini);
EXPORT_SYMBOL(ol_ath_host_config_update);

extern struct ol_pl_os_dep_funcs *g_ol_pl_os_dep_funcs;
EXPORT_SYMBOL(g_ol_pl_os_dep_funcs);
