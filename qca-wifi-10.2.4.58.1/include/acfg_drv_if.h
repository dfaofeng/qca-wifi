/*
 * Copyright (c) 2008-2010, Atheros Communications Inc.
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

#ifndef __ACFG_DRV_INTERFACE_H
#define __ACFG_DRV_INTERFACE_H

#include <acfg_api_types.h>
#include <acfg_event_types.h>

#define acfg_min(x, y)   (x < y ? x : y)
#define acfg_max(x, y)   (x > y ? x : y)

#define ADDR_LEN 6
#define RATE_MAXSIZE 36

#define IEEE80211_CLONE_BSSID 0x0001
#define IEEE80211_CLONE_NOBEACONS 0x0002


#define ACFG_MAX_BEST_CHANS     3
#define ACFG_MAX_NOA_REQ        2
#define ACFG_MAX_NOA_DESCS      4
#define ACFG_MAX_SCAN_SSID      4
#define ACFG_MAX_SCAN_FREQ      16
#define ACFG_MAX_CHANS          255

#define VAP_ID_AUTO (-1)

/** 
 * Command request
 */


/**
 * @brief VAP info structure used during VAPCREATE
 */
typedef struct acfg_vapinfo {
    acfg_opmode_t           icp_opmode; /**< operating mode */
    acfg_vapinfo_flags_t    icp_flags;
    a_uint8_t               icp_name[ACFG_MAX_IFNAME + 1];
    a_int32_t               icp_vapid;
} acfg_vapinfo_t;

/** 
 * @brief Structure representing frequency.
 *        For numbers lower than 10^9, 
 *        we encode the number in 'm' and set 'e' to 0.
 *        For number greater than 10^9, we divide it by the lowest power
 *        of 10 to get 'm' lower than 10^9, with 'm'= f / (10^'e')...
 *        The power of 10 is in 'e', the result of the division is in 'm'.
 */
typedef struct acfg_freq {
    a_uint32_t m ;          /**< Mantissa */
    a_uint16_t e ;          /**< Exponent */
} acfg_freq_t ;


/** 
 * @brief IEEE Channel number
 */
typedef a_uint8_t   acfg_chan_t;


/**
 * @brief wsupp init flags
 */
#define ACFG_WSUPP_INIT_RESTART     0x1     /* start/restart target security service */
#define ACFG_WSUPP_INIT_CLEANUP     0x2     /* remove all config on the given iface */
typedef a_uint32_t  acfg_wsupp_init_flags_t;

typedef struct acfg_wsupp_nw_cfg {
    a_uint32_t networkid;
    a_uint32_t item;
    a_uint8_t  param_str[ACFG_WSUPP_PARAM_LEN];
    a_uint32_t param_val;
    a_uint8_t  *reply;
    a_uint32_t reply_len;
} acfg_wsupp_nw_cfg_t;

typedef struct acfg_wsupp_wps_cfg {
    a_uint32_t type;
    a_uint8_t  param_str[ACFG_WSUPP_PARAM_LEN];
    a_uint32_t param_val;
    a_uint8_t  *reply;
    a_uint32_t reply_len;
} acfg_wsupp_wps_cfg_t;

typedef struct acfg_wsupp_rt_cfg {
    a_uint32_t type;
    a_uint8_t  param_str[ACFG_WSUPP_PARAM_LEN];
    a_uint32_t param_val;
} acfg_wsupp_rt_cfg_t;

typedef struct acfg_wsupp_get_reply {
    a_uint32_t len;
    a_uint8_t  reply[ACFG_WSUPP_REPLY_LEN];
}acfg_wsupp_get_reply_t;
/** 
 * @brief Security feature initialization data
 */
typedef struct acfg_wsupp_info {
    /* common part of wsupp wmi command */
    a_uint8_t unique[ACFG_WSUPP_UNIQUE_LEN];
    a_uint8_t ifname[ACFG_MAX_IFNAME];
    union {
        /* structures for various WMI command */
        acfg_wsupp_init_flags_t init_flags;
        acfg_wsupp_nw_cfg_t nw_cfg;
        acfg_wsupp_wps_cfg_t wps_cfg;
        acfg_wsupp_rt_cfg_t rt_cfg;
    } u;
} acfg_wsupp_info_t ;


/** 
 * @brief Channel switch information
 */
typedef struct acfg_doth_chsw {
    a_uint32_t channel ;                    /**< Channel to switch to*/
    a_uint32_t time ;                       /**< Number of beacons to wait*/
} acfg_doth_chsw_t ;


typedef struct acfg_opaque{
    a_uint32_t len;
    void      *pointer;
}acfg_opaque_t;


/** 
 * @brief Opaque Structure for passing P2P Params
 */
typedef struct acfg_p2p_param {
    a_uint32_t length;                      /**< Size of data passed */
    void      *pointer;                     /**< Pointer to the data */
    a_uint32_t param;                       /**< Sub-Ioctl number */
} acfg_p2p_param_t;

/** 
 * @brief Best Channels
 */
typedef struct acfg_best_freq {
    int        freq[ACFG_MAX_BEST_CHANS];  /**< Best freq in 2.4G/5G/Overall */
} acfg_best_freq_t;

/** 
 * @brief Get Frame, driver indicates supplicant through P2P_SEND_ACTION_CB
 * and RX_MGMT events.
 */
typedef struct acfg_rx_frame {
    a_uint32_t freq;                       /**< Freq at which frame was recvd */
    a_uint32_t type;                       /**< RX_MGMT or P2P_SEND_ACTION_CB */
    int        data[1];                    /**< Placeholder for frame data */
} acfg_rx_frame_t;

/** 
 * @brief NOA descriptor
 */
typedef struct acfg_noa_desc {
    a_uint32_t type_count;           /**< 255:continuous schedule 0:reserved */
    a_uint32_t duration;             /**< Absent period duration */
    a_uint32_t interval;             /**< Absent period interval */
    a_uint32_t start_time;           /**< Absent period start time TSF */
} acfg_noa_desc_t;

/** 
 * @brief NOA information
 */
typedef struct acfg_noa_info {
    a_uint32_t      tsf;                     /**< Current TSF */
    a_uint8_t       idx;                     /**< Identifies an instance */
    a_uint8_t       opp_ps;                  /**< oppPS state of the AP */
    a_uint8_t       ct_win;                  /**< ctwindow in TUs */
    a_uint8_t       num_desc;                /**< Number of NOA descriptors */
    acfg_noa_desc_t desc[ACFG_MAX_NOA_DESCS];/**< The NOA descriptors */
} acfg_noa_info_t;

/** 
 * @brief Channel Set Request Structure
 */
typedef struct acfg_set_chan {
    a_uint32_t freq;                      /**< Freq of the channel */
    a_uint32_t req_id;                    /**< Identifies instance of request */
    a_uint32_t time;                      /**< Time duration */
} acfg_set_chan_t;

/** 
 * @brief Send an action frame
 */
typedef struct acfg_send_act {
    a_uint32_t freq;                   /**< Freq on which frame is to be sent */
    a_uint8_t  dst[ACFG_MACADDR_LEN];  /**< Frame header - destination MAC */
    a_uint8_t  src[ACFG_MACADDR_LEN];  /**< Frame header - source MAC */
    a_uint8_t  bssid[ACFG_MACADDR_LEN];/**< Frame header - BSSID, data */
} acfg_send_act_t;

/** 
 * @brief NOA request
 */
typedef struct acfg_noa_req {
    a_uint8_t  num_iter;           /**< 255:continuous, 1-254:number of times */
    a_uint8_t  offset_next_tbtt[2];/**< Offset from the next TBTT */
    a_uint8_t  duration[2];        /**< Time duration */
} acfg_noa_req_t;

/** 
 * @brief SCAN request
 */
typedef struct acfg_scan_req {
    a_uint32_t freq[ACFG_MAX_SCAN_FREQ]; /**< Frequencies to scan */
    a_uint8_t  num_freq;                 /**< Number of frequencies to scan */
    a_uint8_t  num_ssid;                 /**< Number os SSIDs to scan */
    a_uint16_t len;                      /**< Size of IEs to add to probe Req */
    a_uint8_t  ssid[ACFG_MAX_SCAN_SSID][ACFG_MAX_SSID_LEN + 1]; /**< SSIDs */
    a_uint8_t  ssid_len[ACFG_MAX_SCAN_SSID];                /**< SSID Length */
} acfg_scan_req_t;

/** 
 * @brief Structure containing information about each channel
 */
typedef struct acfg_channel {
    a_uint16_t   freq;               /**< Frequency in MHz */
    a_uint32_t   flags;              /**< Cahnnel attributes */
    a_uint8_t    flag_ext;           /**< Extended channel attributes */
    a_uint8_t    ieee_num;           /**< Channel number */
    a_int8_t     max_reg_pwr;        /**< Maximum regulatory tx power in dBm */
    a_int8_t     max_pwr;            /**< Maximum tx power in dBm */
    a_int8_t     min_pwr;            /**< Minimum tx power in dBm */
    a_uint8_t    reg_class;          /**< Regulatory class id of this channel */
    a_uint8_t    antenna_max;        /**< Max antenna gain from regulatory */
    a_uint8_t    vht_ch_freq_seg1;   /**< Center freqyency of channel */
    a_uint8_t    vht_ch_freq_seg2;   /**< Center freqyency of channel for 
                                       80+80MHz mode of operation */
} acfg_channel_t;

/** 
 * @brief Channel Information Structure
 */
typedef struct acfg_chan_info {
    unsigned int   num_channels;              /**< Number of channels */ 
    acfg_channel_t channel[ACFG_MAX_CHANS];   /**< Induvidual channel info */
} acfg_chan_info_t;

typedef struct {
    a_uint8_t num_node;
    a_uint8_t acl_node[ACFG_MAX_ACL_NODE][6];
} acfg_vap_acl_info_t;

typedef struct {
    a_uint32_t    setchnwidth[3];
} acfg_set_chn_width_t;

typedef struct {
    a_uint8_t   setcountry[3];
} acfg_set_country_t;

typedef struct {
    a_uint8_t stamac[ACFG_MACADDR_LEN];
    a_uint16_t aid;
    a_uint8_t qos;
    acfg_rateset_t lrates;
    acfg_rateset_t htrates;
    acfg_rateset_t vhtrates;
} acfg_add_client_t;

typedef struct {
    a_uint8_t stamac[ACFG_MACADDR_LEN];
} acfg_del_client_t;

typedef struct {
    a_uint32_t authorize;
    a_uint8_t  mac[ACFG_MACADDR_LEN];
} acfg_authorize_client_t ;

#define ACFG_KEYBUF_SIZE   16
#define ACFG_MICBUF_SIZE   (8+8)   /* space for both tx+rx keys */

typedef struct {
	a_uint8_t	cipher;
	a_uint16_t	keyix;
	a_uint8_t	keylen;	/* key length in bytes */
	a_uint8_t	macaddr[ACFG_MACADDR_LEN];
	a_uint8_t	keydata[ACFG_KEYBUF_SIZE+ACFG_MICBUF_SIZE];
} acfg_set_key_t;

typedef struct {
	a_uint16_t	keyix;
	a_uint8_t	macaddr[ACFG_MACADDR_LEN];
} acfg_del_key_t;

typedef struct {
	a_uint8_t	*buf;
	a_uint32_t	total_buf_len;
} acfg_set_beacon_buf_t;

/** 
 * @brief The Data to transport to the ADF, Instances should be on the top
 *        part & pointers should be on the lower parts
 */
typedef union acfg_data {
    acfg_vapinfo_t          vap_info;       /**< Vap Information */
    acfg_ssid_t             ssid;           /**< SSID info */
    acfg_rssi_t             rssi;           /**< RSSI info */
    acfg_custdata_t         custdata;       /**< CUSTDATA info */
    acfg_testmode_t         testmode;       /**< TESTMODE info */
    acfg_phymode_t          phymode;        /**< PHY mode info */
    acfg_chan_t             chan;           /**< IEEE Channel number */
    acfg_opmode_t           opmode;         /**< Opmode info */
    acfg_ampdu_t            ampdu;          /**< AMPDU status */
    acfg_ampdu_frames_t     ampdu_frames;   /**< AMPDU Frames */
    acfg_ampdu_limit_t      ampdu_limit;    /**< AMPDU Limit */
    acfg_shortgi_t          shortgi;        /**< Shortgi Setting */
    acfg_freq_t             freq ;          /**< Frequency */
    acfg_macaddr_t          macaddr;        /**< Mac Address */
    acfg_range_t            range;          /**< Range of parameters */
    acfg_encode_t           encode;         /**< Encoding and token mode */
    acfg_rts_t              rts;            /**< RTS Threshold */
    acfg_frag_t             frag;           /**< Fragmentation Threshold */
    acfg_txpow_t            txpow;          /**< TxPower in dBm */
    acfg_powmgmt_t          powmgmt;        /**< Powert Management */
    acfg_param_req_t        param_req;      /**< Used with set/get param on
                                              redio and vap */
    acfg_vendor_param_req_t vendor_param_req; /**< Used to set/get vendor_param */
    acfg_doth_chsw_t        doth_chsw;      /**< Switch channel */
    acfg_wmmparams_req_t    wmmparams_req;	/**< wmm params */
    acfg_stats_t            stats;          /**< Wireless statistics */
    acfg_ath_stats_t        ath_stats;      /**< Wireless interface statistics */
    a_uint32_t              bitrate;        /**< Default bit rate */
    acfg_rate_t             rate;           /**< Default bit rate */
    acfg_sta_info_req_t     sta_info;       /**< Station info request structure */
    acfg_chmode_t           chmode;         /**< Channel Mode */
    acfg_set_scan_t         sscan;
    acfg_scan_t             *scan;          /**< Scan list pointer */
    acfg_tx99_t             tx99_wcmd;      /**< tx99tool */
    acfg_ie_t               ie;             /**< IE */
    a_uint32_t              acparams[ACFG_MAX_ACPARAMS]; /**< AC params */
    acfg_p2p_param_t        p2p_param;      /**< P2P param */
    acfg_chan_info_t        chan_info;      /**< Channel Information */
    acfg_macacl_t            maclist;
    /*vap list per radio*/
    acfg_radio_vap_info_t  radio_vap_info;
    acfg_vap_acl_info_t    vap_acl_info;

    /* security related data */
    acfg_wsupp_info_t       wsupp_info;
    acfg_nawds_cfg_t        nawds_cmd;
    acfg_ath_diag_t         ath_diag;
    acfg_key_t              key;
    acfg_mlme_t             *mlme;
    acfg_filter_t           filter;
    acfg_appie_t            appie;
    acfg_mgmt_t             mgmt;
    acfg_delkey_t           delkey;
    acfg_athdbg_req_t       dbgreq;
    acfg_opaque_t           opq;
    acfg_set_chn_width_t    chnw; 
    acfg_set_country_t      setcntry; 
    acfg_add_client_t       addclient;
    acfg_del_client_t       delclient;
    acfg_authorize_client_t authorize_client;
    acfg_set_key_t          set_key;
    acfg_del_key_t          del_key;
    acfg_set_beacon_buf_t   beacon_buf;
    acfg_ratemask_t         ratemask;
    acfg_atf_ssid_val_t     atf_ssid;
    acfg_atf_sta_val_t      atf_sta;
} acfg_data_t;


/** 
 * @brief Command Request per OS
 */
enum acfg_req_cmd {
    /*
     * ***************************** 
     * Wifi specific Request Numbers
     * *****************************
     */
    ACFG_REQ_FIRST_WIFI,        /**< First Radio request marker */

    ACFG_REQ_CREATE_VAP,        /**< Create VAP */
    ACFG_REQ_SET_RADIO_PARAM,   /**< Set Radio Parameters */
    ACFG_REQ_GET_RADIO_PARAM,   /**< Get Radio Parameters */
    ACFG_REQ_SET_REG,           /**< Set target register */
    ACFG_REQ_GET_REG,           /**< Get target register */
    ACFG_REQ_TX99TOOL,          /**< tx99tool */
    ACFG_REQ_SET_HW_ADDR,       /**< Set target wifi0 hw address */
    ACFG_REQ_GET_ATHSTATS,      /**< Get athstats */
    ACFG_REQ_CLR_ATHSTATS,      /**< Clear athstats */
    ACFG_REQ_GET_PROFILE,       /**< Get Radio info */
    ACFG_REQ_SET_COUNTRY,       /**< Set Country */

    ACFG_REQ_LAST_WIFI,         /**< Last Radio request marker */

    /*
     * ***************************** 
     * VAP specific Request Numbers
     * *****************************
     */
    ACFG_REQ_FIRST_VAP,         /**< First VAP request marker */

    ACFG_REQ_SET_SSID,          /**< Set the SSID */
    ACFG_REQ_GET_SSID,          /**< Get the SSID */
    ACFG_REQ_SET_CHANNEL,       /**< Set the channel (ieee) */
    ACFG_REQ_GET_CHANNEL,       /**< Set the channel (ieee) */
    ACFG_REQ_DELETE_VAP,        /**< Delete VAP */
    ACFG_REQ_SET_OPMODE,        /**< Set the Opmode */
    ACFG_REQ_GET_OPMODE,        /**< Get the Opmode */
    ACFG_REQ_SET_AMPDU,         /**< Set AMPDU setting */
    ACFG_REQ_GET_AMPDU,         /**< Get Current AMPDU setting */
    ACFG_REQ_SET_AMPDUFRAMES,   /**< Set AMPDU Frames */
    ACFG_REQ_GET_AMPDUFRAMES,   /**< Set AMPDU Frames */
    ACFG_REQ_SET_AMPDULIMIT,    /**< Set AMPDU Limit */
    ACFG_REQ_GET_AMPDULIMIT,    /**< Get AMPDU Limit */
    ACFG_REQ_SET_SHORTGI,       /**< Set Shortgi */
    ACFG_REQ_GET_SHORTGI,       /**< Get Shortgi setting */
    ACFG_REQ_SET_FREQUENCY,     /**< Set Frequency */
    ACFG_REQ_GET_FREQUENCY,     /**< Set Frequency */
    ACFG_REQ_GET_NAME,          /**< Get Wireless Name */
    ACFG_REQ_SET_RTS,           /**< Set RTS Threshold */
    ACFG_REQ_GET_RTS,           /**< Get RTS Threshold */
    ACFG_REQ_SET_FRAG,          /**< Set Fragmentation Threshold */
    ACFG_REQ_GET_FRAG,          /**< Get Fragmentation Threshold */
    ACFG_REQ_SET_TXPOW,         /**< Set default Tx Power */
    ACFG_REQ_GET_TXPOW,         /**< Get default Tx Power */
    ACFG_REQ_SET_AP,            /**< Set AP mac addr */
    ACFG_REQ_GET_AP,            /**< Get AP mac addr */
    ACFG_REQ_GET_RANGE,         /**< Get range of parameters */
    ACFG_REQ_GET_ENCODE,        /**< Get encoding token and mode */
    ACFG_REQ_SET_VAP_PARAM,     /**< Set Vap Parameters */
    ACFG_REQ_GET_VAP_PARAM,     /**< Get Vap Parameters */
    ACFG_REQ_GET_RATE,          /**< Get default bit rate */
    ACFG_REQ_SET_SCAN,          /**< Set Scan Request */
    ACFG_REQ_GET_SCANRESULTS,   /**< Get Scan Results */
    ACFG_REQ_GET_STATS,         /**< Get wireless statistics */
    ACFG_REQ_SET_PHYMODE,       /**< Set phymode */
    ACFG_REQ_GET_ASSOC_STA_INFO,/**< Get info on associated stations */
    ACFG_REQ_SET_ENCODE,        /**< Set encoding token and mode */
    ACFG_REQ_SET_RATE,          /**< Set default bit rate */
    ACFG_REQ_SET_POWMGMT,       /**< Set Power Management */
    ACFG_REQ_GET_POWMGMT,       /**< Get Power Management */
    ACFG_REQ_SET_CHMODE,        /**< Set Channel Mode */
    ACFG_REQ_GET_CHMODE,        /**< Get Channel Mode */
    ACFG_REQ_GET_RSSI,          /**< Get the RSSI */
    ACFG_REQ_SET_TESTMODE,      /**< Set the TESTMODE */
    ACFG_REQ_GET_TESTMODE,      /**< Get the TESTMODE */
    ACFG_REQ_GET_CUSTDATA,      /**< Get the CUSTDATA */
    ACFG_REQ_SET_VAP_WMMPARAMS, /**< Set Vap WMM Parameters */ 
    ACFG_REQ_GET_VAP_WMMPARAMS, /**< Get Vap WMM Parameters */ 
    ACFG_REQ_NAWDS_CONFIG,      /**< Get Nawds config */
    ACFG_REQ_DOTH_CHSWITCH,     /**< Channel Switch */
    ACFG_REQ_ADDMAC,            /**< Add ACL entry */
    ACFG_REQ_DELMAC,            /**< Delete ACL entry */
    ACFG_REQ_KICKMAC,           /**< Disassociate station */
    ACFG_REQ_GET_PHYMODE,       /**< Get phymode */
    ACFG_REQ_ACL_ADDMAC,        /**< MAC ACL addmac */
    ACFG_REQ_ACL_GETMAC,        /**< MAC ACL getmac */
    ACFG_REQ_ACL_DELMAC,        /**< MAC ACL delmac */
    ACFG_REQ_GET_VAP_ACL,
    ACFG_REQ_WDS_ADDR_SET,
    ACFG_REQ_IS_OFFLOAD_VAP,
    ACFG_REQ_ADD_CLIENT,
    ACFG_REQ_DEL_CLIENT,
    ACFG_REQ_AUTHORIZE_CLIENT,
    ACFG_REQ_PHYERR,

    /* security request */
    ACFG_REQ_WSUPP_INIT,
    ACFG_REQ_WSUPP_FINI,
    ACFG_REQ_WSUPP_IF_ADD,
    ACFG_REQ_WSUPP_IF_RMV,
    ACFG_REQ_WSUPP_NW_CRT,
    ACFG_REQ_WSUPP_NW_DEL,
    ACFG_REQ_WSUPP_NW_SET,
    ACFG_REQ_WSUPP_NW_GET,
    ACFG_REQ_WSUPP_NW_LIST,
    ACFG_REQ_WSUPP_WPS_REQ,
    ACFG_REQ_WSUPP_SET,

    ACFG_REQ_SET_MLME,
    ACFG_REQ_GET_WPA_IE,
    ACFG_REQ_SET_FILTERFRAME,
    ACFG_REQ_SET_APPIEBUF,
    ACFG_REQ_SET_KEY,
    ACFG_REQ_DEL_KEY,
    ACFG_REQ_SET_OPTIE,
    ACFG_REQ_SET_ACPARAMS,
    ACFG_REQ_GET_CHAN_INFO,
    ACFG_REQ_GET_CHAN_LIST,
    ACFG_REQ_GET_MAC_ADDR,
    ACFG_REQ_SET_VAP_P2P_PARAM,
    ACFG_REQ_GET_VAP_P2P_PARAM,
    ACFG_REQ_DBGREQ,
    ACFG_REQ_SEND_MGMT,
    ACFG_REQ_SET_VAP_VENDOR_PARAM,
    ACFG_REQ_GET_VAP_VENDOR_PARAM,
    ACFG_REQ_SET_CHNWIDTHSWITCH,
    ACFG_REQ_SET_BEACON_BUF,
    ACFG_REQ_SET_RATEMASK,
    ACFG_REQ_SET_ATF_ADDSSID,
    ACFG_REQ_SET_ATF_DELSSID,
    ACFG_REQ_SET_ATF_ADDSTA,
    ACFG_REQ_SET_ATF_DELSTA,

    ACFG_REQ_UNUSED,            /**< Unused marker */
    ACFG_REQ_LAST_VAP,          /**< Last VAP request marker */
};
typedef a_uint32_t  acfg_req_cmd_t;

/** 
 * @brief The request structure to communicate between the user(ACFG) 
 *        & kernel (ADF).  
 */
typedef struct acfg_os_req {
    acfg_req_cmd_t  cmd;    /**< First element always */
    acfg_data_t     data;   /**< Data block */
} acfg_os_req_t;

/** 
 * Events
 */

/** 
 * @brief Event ID(s)
 */
enum acfg_ev_id {
    ACFG_EV_SCAN_DONE           = 0,    /**< Scan Done */
    ACFG_EV_ASSOC_AP            = 1,    /**< Associated with an AP */
    ACFG_EV_ASSOC_STA           = 2,    /**< Station joined an AP */
    ACFG_EV_DISASSOC_AP         = 3,    /**< AP recv disassoc from Station */
    ACFG_EV_DISASSOC_STA        = 4,    /**< Station recv disassoc from AP */
    ACFG_EV_DEAUTH_AP           = 5,    /**< AP recv deauth from Station */
    ACFG_EV_DEAUTH_STA          = 6,    /**< Station recv deauth from AP */
    ACFG_EV_NODE_LEAVE          = 7,    /**< Station leaves the Bss */
    ACFG_EV_AUTH_AP           = 8,
    ACFG_EV_AUTH_STA           = 9,

    ACFG_EV_CHAN_START          = 10,    /**< Radio On Channel */
    ACFG_EV_CHAN_END            = 11,    /**< Radio Off Channel */
    ACFG_EV_RX_MGMT             = 12,    /**< Received Management Frame */
    ACFG_EV_SENT_ACTION         = 13,    /**< Sent Action Frame */
    ACFG_EV_LEAVE_AP            = 14,    /**< STA left AP */
    ACFG_EV_GEN_IE              = 15,    /**< IE */
    ACFG_EV_ASSOC_REQ_IE        = 16,    /**< Assoc Req IE */
    ACFG_EV_MIC_FAIL            = 17,   /**< MIC FAIL EVENT */
    ACFG_EV_PROBE_REQ           = 18,   /**< Probe Request Frame for Overlap PBC Detection */
    ACFG_EV_DEVICE_STATE_CHANGE = 19,   /**< Offload target's State Change */

    ACFG_EV_WSUPP_RAW_MESSAGE               = 100,  /**< WSUPP event: associated */
    ACFG_EV_WSUPP_AP_STA_CONNECTED          = 101,  /**< WSUPP event: associated */
    ACFG_EV_WSUPP_AP_STA_DISCONNECTED          = 102,  /**< WSUPP event: associated */
    ACFG_EV_WSUPP_WPA_EVENT_CONNECTED       = 103,  /**< WSUPP event: WPA connected */
    ACFG_EV_WSUPP_WPA_EVENT_DISCONNECTED    = 104,  /**< WSUPP event: WPA disconnected */
    ACFG_EV_WSUPP_WPA_EVENT_TERMINATING     = 105,  /**< WSUPP event: WPA terminating */
    ACFG_EV_WSUPP_WPA_EVENT_SCAN_RESULTS    = 106,  /**< WSUPP event: WPA get scan result */
    ACFG_EV_WSUPP_WPS_EVENT_ENROLLEE_SEEN   = 107,  /**< WSUPP event: enrollee seen */
    ACFG_EV_WSUPP_ASSOC_REJECT              = 108,
    ACFG_EV_WSUPP_EAP_SUCCESS               = 109,
    ACFG_EV_WSUPP_EAP_FAILURE               = 110,
    ACFG_EV_PUSH_BUTTON                     = 111,
    ACFG_EV_WSUPP_WPS_NEW_AP_SETTINGS       = 112,
    ACFG_EV_WSUPP_WPS_SUCCESS               = 113,
    ACFG_EV_WAPI                            = 114,
    ACFG_EV_RADAR                           = 115,  /**< list of radar freqs */
    ACFG_EV_STA_SESSION                     = 116,  /**< STA Session timeout */
};
typedef a_uint32_t  acfg_ev_id_t;    

/** 
 * @brief Event Data
 */
typedef union acfg_ev_data {
    acfg_device_state_data_t device_state;
    acfg_scan_done_t    scan;
    acfg_assoc_t     assoc_ap;
    acfg_assoc_t     assoc_sta;
    acfg_dauth_t        dauth;
    acfg_auth_t        auth;
    acfg_disassoc_t     disassoc_ap;
    acfg_disassoc_t     disassoc_sta;
    acfg_wsupp_custom_message_t mic_fail;
    acfg_chan_start_t   chan_start;
    acfg_chan_end_t     chan_end;
    acfg_leave_ap_t     leave_ap;
    acfg_gen_ie_t       gen_ie;
    acfg_radar_t        radar;
    acfg_session_t      session;
    /* security events */
    acfg_wsupp_ap_sta_conn_t   wsupp_ap_sta_conn;
    acfg_wsupp_wpa_conn_t      wsupp_wpa_conn;
    acfg_wsupp_wps_enrollee_t  wsupp_wps_enrollee;
    acfg_wsupp_raw_message_t   wsupp_raw_message;
    acfg_probe_req_t           pr_req;
    acfg_wsupp_assoc_t         wsupp_assoc;
    acfg_wsupp_eap_t           wsupp_eap_status;
    acfg_pbc_ev_t              pbc;
    acfg_wsupp_wps_success_t   wsupp_wps_success;
    acfg_wsupp_wps_new_ap_settings_t wsupp_wps_new_ap_setting;
} acfg_ev_data_t;


/** 
 * @brief OS event reception structure
 */
typedef struct acfg_os_event {
    acfg_ev_id_t        id;             /**< Event ID */
    acfg_ev_data_t      data;           /**< Event Data */
} acfg_os_event_t;


#ifdef __ACFG_PHYMODE_STRINGS__

/** 
 * @brief String representations of phy modes 
 *        in capital letters.
 */
static const a_uint8_t *phymode_strings[] = {
    [ACFG_PHYMODE_AUTO]             = (a_uint8_t *)"AUTO",
    [ACFG_PHYMODE_11A]              = (a_uint8_t *)"11A",
    [ACFG_PHYMODE_11B]              = (a_uint8_t *)"11B",
    [ACFG_PHYMODE_11G]              = (a_uint8_t *)"11G" ,
    [ACFG_PHYMODE_FH]               = (a_uint8_t *)"FH" ,
    [ACFG_PHYMODE_TURBO_A]               = (a_uint8_t *)"TA" ,
    [ACFG_PHYMODE_TURBO_G]               = (a_uint8_t *)"TG" ,
    [ACFG_PHYMODE_11NA_HT20]        = (a_uint8_t *)"11NAHT20" ,
    [ACFG_PHYMODE_11NG_HT20]        = (a_uint8_t *)"11NGHT20" ,
    [ACFG_PHYMODE_11NA_HT40PLUS]    = (a_uint8_t *)"11NAHT40PLUS" ,
    [ACFG_PHYMODE_11NA_HT40MINUS]   = (a_uint8_t *)"11NAHT40MINUS" ,
    [ACFG_PHYMODE_11NG_HT40PLUS]    = (a_uint8_t *)"11NGHT40PLUS" ,
    [ACFG_PHYMODE_11NG_HT40MINUS]   = (a_uint8_t *)"11NGHT40MINUS" ,
    [ACFG_PHYMODE_11NG_HT40]   = (a_uint8_t *)"11NGHT40" ,
    [ACFG_PHYMODE_11NA_HT40]   = (a_uint8_t *)"11NAHT40" ,
    [ACFG_PHYMODE_11AC_VHT20]  = (a_uint8_t *)"11ACVHT20" ,
    [ACFG_PHYMODE_11AC_VHT40PLUS]  = (a_uint8_t *)"11ACVHT40PLUS" ,
    [ACFG_PHYMODE_11AC_VHT40MINUS]  = (a_uint8_t *)"11ACVHT40MINUS" ,
    [ACFG_PHYMODE_11AC_VHT40]  = (a_uint8_t *)"11ACVHT40" ,
    [ACFG_PHYMODE_11AC_VHT80]  = (a_uint8_t *)"11ACVHT80" ,
    [ACFG_PHYMODE_INVALID]          = NULL ,
} ;
#endif //__ACFG_PHYMODE_STRINGS__

#define NETLINK_ACFG_EVENT 20
#endif
