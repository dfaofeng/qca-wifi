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

#ifndef _DEV_QVIT_DEFS_H
#define _DEV_QVIT_DEFS_H

#include <qvit/qvit_common_defs.h>

#ifndef     IFNAMSIZ
#define     IFNAMSIZ    16
#endif

#define ETHER_ADDR_LEN 6

#define ATH_XIOCTL_UNIFIED_QVIT_CMD 0x2000
#define ATH_XIOCTL_UNIFIED_QVIT_RSP ATH_XIOCTL_UNIFIED_QVIT_CMD+1


#define SIOCIOCTLQVIT 0x3000
#define DRV_NAME      "vi_drv"
#define QVIT_PROTO    0x5156

#define QVIT_NETLINK_PORT 28
#define MAX_QVIT_NETLINK_PAYLOAD 1024
#define QVIT_NETLINK_GROUP 2

#ifdef A_SIMOS_DEVHOST
#define DRV_VERSION             "sim-1.1"
#define FW_VERSION              "sim-1.0"
#define BUS_INFO                "sim-00:00:00"
#endif


typedef struct __vdev__
{
    char vdev_name[IFNAMSIZ];
    int  vdev_id;
} VDEV_FUNC;



struct ethernet_hdr
{
    unsigned char  ether_dhost[ETHER_ADDR_LEN];/* destination ethernet address */
    unsigned char  ether_shost[ETHER_ADDR_LEN];/* source ethernet address */
    unsigned short ether_type;                 /* protocol */
};

typedef struct DiagViPrivType_s
{
   struct net_device * dev;
   struct ol_ath_softc_net80211 *scn; 
   ol_txrx_vdev_handle txrx_vdev;
   struct net_device_stats stats;
   struct vlan_group *vlgrp;
   ol_txrx_tx_fp vdev_tx;
   spinlock_t stats_lock;
   int vdev_id;
} DiagVi_PrivType;

extern int ol_ath_qvit_cmd(ol_scn_t scn, u_int8_t *data, u_int16_t len);
extern int ol_ath_qvit_rsp(ol_scn_t scn, u_int8_t *payload);
void pal_ani_hexdump( const unsigned char *buffer, unsigned int len );
int qvit_unified_ioctl (struct ol_ath_softc_net80211 *scn, struct ifreq *ifr);
struct net_device *qvit_create_vdev(VDEV_FUNC *cp, char *mac_address, struct ol_ath_softc_net80211 *scn);
void qvit_delete_vdev(struct net_device *);
void qvit_set_ethtool(struct net_device *dev);
void qvit_cleanup(void);
void qvit_hexdump( const unsigned char *buffer, unsigned int len );
void qvit_delete_peers(int vdevId);
ol_txrx_peer_handle qvit_get_peer_handle_from_mac_addr(ol_txrx_vdev_handle txrx_vdev, u_int8_t *mac_addr);
int  qvit_netlink_init(struct sock **nl_sock, int groups);
void qvit_netlink_exit(struct sock *nl_sock);
void qvit_nlsendmsg_ucast(const char *message, int pid);
void qvit_nlsendmsg_bcast(const char *message, int group);

#endif

