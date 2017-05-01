/*
 **************************************************************************
 * Copyright (c) 2013, Qualcomm Atheros, Inc.
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 **************************************************************************
 */

/*
 * osif_nss.c
 *
 * This file used for wifi redirect for NSS
 * ------------------------REVISION HISTORY-----------------------------
 * Qualcomm Atheros         23/sep/2013              Created
 */


#if  QCA_NSS_PLATFORM

#include "osif_private.h"
#include <wlan_opts.h>
#define OSIF_TO_NETDEV(_osif) (((osif_dev *)(_osif))->netdev)
#include <nss_api_if.h>

/*
 * osif_pltfrm_create_vap
 *	Register vap with NSS
 */
void osif_pltfrm_create_vap(osif_dev *osif){

	struct net_device *dev = OSIF_TO_NETDEV(osif);
	osif_dev  *osifp = (osif_dev *) osif;
	osifp->nssctx = nss_create_virt_if(dev);
}

/*
 * osif_pltfrm_delete_vap
 *	Unregister vap with NSS
 */
void osif_pltfrm_delete_vap(osif_dev *osif){

	osif_dev  *osifp = (osif_dev *) osif;

	if(osifp->nssctx){
		nss_destroy_virt_if(osifp->nssctx);
	}
}

/*
 * osif_send_to_nss
 *	Send packets to the nss driver
 */
void transcap_nwifi_to_8023(adf_nbuf_t msdu);
void
osif_send_to_nss(os_if_t osif, struct sk_buff *skb, int nwifi)
{
	struct net_device *dev = OSIF_TO_NETDEV(osif);
	osif_dev  *osifp = (osif_dev *) osif;

	if(!osifp->nssctx){
		goto out;
	}

	skb->next =NULL;
	if (skb_shared(skb)){
		goto out;
	}

	if (nwifi) {
		if (nss_tx_virt_if_rx_nwifibuf(osifp->nssctx, skb)) {
			goto out ;
		}
	} else {
	if(nss_tx_virt_if_rxbuf(osifp->nssctx, skb)){
		goto out;
	}
	}

	return ;
out:
	if (nwifi) {
		transcap_nwifi_to_8023(skb);
		skb->protocol = eth_type_trans(skb, dev);
	}
	skb->dev = dev;
	netif_rx(skb);
	return ;
}
#endif
