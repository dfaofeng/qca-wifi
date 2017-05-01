/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
#ifndef _OL_RAWMODE_SIM__H_
#define _OL_RAWMODE_SIM__H_

#include <adf_nbuf.h>           /* adf_nbuf_t */
#include <ieee80211_var.h>      /* Generally required constructs */
#include <ol_txrx_api.h>        /* ol_txrx_vdev_t, etc*/

/* Raw Mode simulation - conversion between Raw 802.11 format and other
 * formats.
 */

/* Max MSDU length supported in the simulation */
#define MAX_SIM_80211_MSDU_LEN                  (1508)

#define L_GET_LLC_ETHTYPE(ptr) \
    (((struct llc*)((ptr)))->llc_un.type_snap.ether_type)

#define L_LLC_ETHTYPE_OFFSET \
    ((u_int8_t*)&(((struct llc*)(0))->llc_un.type_snap.ether_type) - \
     (u_int8_t*)0)

#define L_ETH_ETHTYPE_SIZE \
    (sizeof(((struct ether_header*)(0))->ether_type))

#define GET_UNCONSUMED_CNT(is_frag, psctx, nonfragcnt)  \
    ((is_frag)? (psctx)->unconsumed_cnt_total:(nonfragcnt))


/* Fragment stream processing */

/* 
 * We keep a limit on the peek offset and number of bytes, for simplicity
 * so that we don't have to cross more than one nbuf boundary.
 */
#define OL_RX_FRAGSTREAM_PEEK_OFFSET_MAX   \
                                (sizeof(struct ieee80211_qosframe_addr4) + \
                                 sizeof(struct ether_header) + \
                                 sizeof(struct llc))

#define OL_RX_FRAGSTREAM_PEEK_NBYTES_MAX   (16)

/* 
 * Context for processing read and peek operations on an nbuf fragment stream
 * corresponding to an MPDU.
 */
typedef struct _ol_rx_fragstream_ctx
{
    /* Whether this context is valid. */
    u_int8_t is_valid;
    
    /* Head nbuf for fragment stream */
    adf_nbuf_t list_head;
    
    /* Total 802.11 header size. To be determined by user of context. */
    u_int16_t headersize;
    
    /* Total 802.11 trailer size. To be determined by user of context. */
    u_int16_t trailersize;
    
    /* Current nbuf being used */
    adf_nbuf_t currnbuf;
    
    /* 
     * Position in current nbuf from where next read consumption/peek should
     * start
     */
    u_int8_t *currnbuf_ptr;

    /* Next nbuf to be used */
    adf_nbuf_t nextnbuf;
    
    /* Count of unconsumed bytes in nbuf currently being processed */
    u_int32_t unconsumed_cnt_curr;

    /* Count of unconsumed bytes in all fragment nbufs put together */
    u_int32_t unconsumed_cnt_total;
} ol_rx_fragstream_ctx;


#define RAWSIM_PKT_HEXDUMP(_buf, _len) do {                  \
    int i, mod;                                              \
    unsigned char ascii[17];                                 \
    unsigned char *pc = (_buf);                              \
                                                             \
    for (i = 0; i < (_len); i++) {                           \
        mod = i % 16;                                        \
        if (mod == 0) {                                      \
            if (i != 0)                                      \
                adf_os_print("  %s\n", ascii);               \
        }                                                    \
        adf_os_print(" %02x", pc[i]);                        \
        if ((pc[i] < 0x20) || (pc[i] > 0x7e))                \
            ascii[mod] = '.';                                \
        else                                                 \
            ascii[mod] = pc[i];                              \
        ascii[(mod) + 1] = '\0';                             \
    }                                                        \
    while ((i % 16) != 0) {                                  \
        adf_os_print("   ");                                 \
        i++;                                                 \
    }                                                        \
    adf_os_print("  %s\n", ascii);                           \
} while (0)


#define RAWSIM_TX_FRAG_LIST_APPEND(head, tail, elem)         \
do {                                                         \
    if (!(head)) {                                           \
        (head) = (elem);                                     \
    } else {                                                 \
        adf_nbuf_set_next((tail), (elem));                   \
    }                                                        \
    (tail) = (elem);                                         \
} while (0)

#endif /* _OL_RAWMODE_SIM__H_ */
