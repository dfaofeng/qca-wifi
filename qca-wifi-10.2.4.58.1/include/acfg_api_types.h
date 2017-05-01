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

#ifndef __ACFG_TYPES_H
#define __ACFG_TYPES_H

#include <a_base_types.h>

/**
 * @Types of data
 */
enum {
    ACFG_TYPE_STR = 1,
    ACFG_TYPE_INT,
    ACFG_TYPE_INT16,
    ACFG_TYPE_CHAR,
    ACFG_TYPE_MACADDR,
    ACFG_TYPE_ACL,
};

/** 
 * @brief constants
 */
enum {
    ACFG_MAX_BB_PANICS      = 3,    /**< Number of BB Panics to get logged */ 
    ACFG_LATENCY_CATS       = 5,    /**< Number of categories to log latency */
    ACFG_LATENCY_BINS       = 45,   /**< Number of 1024us bins to log latency */
    ACFG_MACADDR_LEN        = 6,    /**< Mac Address len */
    ACFG_MAX_IFNAME         = 16,   /**< Max interface name string */
    ACFG_MAX_SSID_LEN       = 32,   /**< Max SSID length */
    ACFG_MAX_SCANLIST       = 16,   /**< Max number scanned entries per call */
    ACFG_MAX_IELEN          = 256,  /**< Max IE length */
    ACFG_MAX_RATE_SIZE      = 30,   /**< Max MCS rate element size */
    ACFG_MAX_HT_MCSSET      = 16,   /**< Represents 128-bit rates */
    ACFG_MAX_IEEE_CHAN      = 255,  /**< Max number of IEEE 
                                      Channels supported */
    ACFG_MAX_CHMODE_LEN     = 16,   /**< Max Channel Mode String length */
    ACFG_ENCODING_TOKEN_MAX = 64, /**< max size of encoding token */ 
    ACFG_MAX_MODE_LEN       = 16,   /**< Max length of phymode string */
    ACFG_MAX_ACPARAMS       = 4,   /**< Max number of AC params */
    ACFG_WSUPP_UNIQUE_LEN = 8,      /**< Unique id len for security */

    ACFG_WSUPP_PARAM_LEN = 64,      /**< Supplicant param length */
    ACFG_WPS_CONFIG_METHODS_LEN = 256, /**< wps config methods length */
    ACFG_WPS_RF_BANDS_LEN   = 3,    /**< wps rf bands length */
    ACFG_WSUPP_REPLY_LEN = 256,     /**< Supplicant reply length */
    ACFG_DL_MAX_CMDSZ   = 1024,
    ACFG_MAX_VIDNAME    = 6 ,       /** Max VLAN ID = "4096" */
    ACFG_SZ_REPLAYCMD   = 128,
    ACFG_MACSTR_LEN        = 18,    /**< Mac Address len */
    ACFG_VENDOR_PARAM_LEN = 100,    /**< Vendor param len */
    ACFG_MAX_VENDOR_PARAMS = 20,    /**< Max Vendor params */
    ACFG_KEYDATA_LEN    = 32,       /**< Key Data len */
    ACFG_MAX_BITRATE    = 32,       /**< Max bitrates */
    ACFG_MAX_FREQ       = 32,       /**< Max frequencies */
    ACFG_MAX_ENCODING   = 8,        /**< Max encoding tokens */
    ACFG_MAX_TXPOWER    = 8,        /**< Max tx powers */
    ACFG_MAX_INTR_BKT   = 512,      /**< Counter buckets, for packets handled in a single iteration */
    ACFG_VI_LOG_LEN     = 10,       /**< Max number of VI logs */
    ACFG_MCS_RATES      = 31,       /**< MCS rates */
    ACFG_MAX_DFS_FILTER = 32,       /**< Max number of DFS filters */
    ACFG_MAX_ATF_STALIST_SIZE = 1024, /**< Max size of ATF sta list */
    ACFG_MAX_PERCENT_SIZE = 4,      /**< Max size of percent str */
};

/**
 * @brief Information Element
 */
typedef struct acfg_ie {
    a_uint32_t  len;
    a_uint8_t   data[ACFG_MAX_IELEN];
} acfg_ie_t ;

/** 
 * @brief Generic SSID Types
 */
typedef struct acfg_ssid {
    a_uint32_t  len;
    a_char_t  name[ACFG_MAX_SSID_LEN + 1];
} acfg_ssid_t;

#define ACFG_MAX_VAPS          16

#define ACFG_TESTMODE_CHAN     0x1    
#define ACFG_TESTMODE_BSSID    0x2    
#define ACFG_TESTMODE_RX       0x3    
#define ACFG_TESTMODE_RESULT   0x4    
#define ACFG_TESTMODE_ANT      0x5  

#define ACFG_MAC_STR_LEN         17

#define ACFG_MAX_ACL_NODE       64
#define ACFG_CTRL_IFACE_LEN     30

/**
 * @brief  set/get testmode-info
 */
typedef struct  acfg_testmode {
    a_uint8_t     bssid[ACFG_MACADDR_LEN];
    a_int32_t     chan;         /* ChanID */  
    a_uint16_t    operation;    /* Operation */
    a_uint8_t     antenna;      /* RX-ANT */
    a_uint8_t     rx;           /* RX START/STOP */
    a_int32_t     rssi_combined;/* RSSI */
    a_int32_t     rssi0;        /* RSSI */
    a_int32_t     rssi1;        /* RSSI */
    a_int32_t     rssi2;        /* RSSI */
} acfg_testmode_t;

#define ACFG_MAX_ANTENNA       3                /* Keep the same as ATH_MAX_ANTENNA */

#define ACFG_DEFAULT_RETRIES 4
/** 
 * @brief Generic RSSI Types
 */
typedef struct acfg_rssi {
    a_uint8_t      bc_avg_rssi;     /* average rssi */
    a_uint8_t      bc_valid_mask;   /* bitmap of valid elements in rssi_ctrl/ext array */
    a_uint8_t      bc_rssi_ctrl[ACFG_MAX_ANTENNA];
    a_uint8_t      bc_rssi_ext[ACFG_MAX_ANTENNA];
    a_uint8_t      data_avg_rssi;     /* average rssi */
    a_uint8_t      data_valid_mask;   /* bitmap of valid elements in rssi_ctrl/ext array */
    a_uint8_t      data_rssi_ctrl[ACFG_MAX_ANTENNA];
    a_uint8_t      data_rssi_ext[ACFG_MAX_ANTENNA];
} acfg_rssi_t;

#define ACFG_CUSTDATA_LENGTH       20

/**
 * @brief get custdata
 */
typedef struct acfg_custdata{   
    a_uint8_t      custdata[ACFG_CUSTDATA_LENGTH]; 
}acfg_custdata_t;

/** 
 * @brief Generic channel mode
 */
typedef struct acfg_chmode {
    a_uint32_t  len;
    a_uint8_t   mode[ACFG_MAX_CHMODE_LEN];
} acfg_chmode_t;

typedef struct acfg_key {
    a_uint8_t        type;
    a_uint8_t        pad;
    a_uint16_t       keyix;
    a_uint8_t        keylen;
    a_uint8_t        flags;
    a_uint8_t        macaddr[ACFG_MACADDR_LEN];
    a_uint64_t       keyrsc;
    a_uint64_t       keytsc;
    a_uint8_t        keydata[ACFG_KEYDATA_LEN];
} acfg_key_t;

typedef struct acfg_mlme {
    a_uint8_t        op;
    a_uint8_t        ssid_len;
    a_uint16_t       reason;
    a_uint16_t       seq;
    a_uint8_t        macaddr[ACFG_MACADDR_LEN];
    a_uint8_t        ssid[ACFG_MAX_SSID_LEN];
    a_uint8_t        optie[ACFG_MAX_IELEN * 2];
    a_uint16_t       optie_len;
} acfg_mlme_t;

typedef struct acfg_filter_frame {
    a_uint32_t       filter;
} acfg_filter_t;

#define ACFG_MAX_APPIE_BUF 2048
typedef struct acfg_appie {
    a_uint32_t       frmtype;
    a_uint32_t       buflen;
    a_uint8_t        buf[0];
} acfg_appie_t;

typedef struct acfg_mmt {
    a_uint8_t        macaddr[ACFG_MACADDR_LEN];
    a_uint32_t       buflen;
    a_uint8_t        buf[0];
} acfg_mgmt_t;

/** 
 * @brief DELKEY
 */
typedef struct acfg_delkey {
    a_uint8_t idx;                     /**< Key index */
    a_uint8_t addr[ACFG_MACADDR_LEN];  /**< Mac Address */
} acfg_delkey_t;

/*
 * Station information block; the mac address is used
 * to retrieve other data like stats, unicast key, etc.
 */
typedef struct acfg_stainfo {
    a_uint16_t   isi_len;        /* length (mult of 4) */
    a_uint16_t   isi_freq;       /* MHz */
    a_uint32_t   isi_flags;      /* channel flags */
    a_uint16_t   isi_state;      /* state flags */
    a_uint8_t    isi_authmode;       /* authentication algorithm */
    a_int8_t     isi_rssi;
    a_uint16_t   isi_capinfo;        /* capabilities */
    a_uint8_t    isi_athflags;       /* Atheros capabilities */
    a_uint8_t    isi_erp;        /* ERP element */
    a_int8_t     isi_ps;            /* psmode */
    a_uint8_t    isi_macaddr[ACFG_MACADDR_LEN];
    a_uint8_t    isi_nrates;
    /* negotiated rates */
    a_uint8_t    isi_rates[36];
    a_uint8_t    isi_txrate;     /* index to isi_rates[] */
    a_uint32_t   isi_txratekbps; /* rate in Kbps, for 11n */
    a_uint16_t   isi_ie_len;     /* IE length */
    a_uint16_t   isi_associd;        /* assoc response */
    a_uint16_t   isi_txpower;        /* current tx power */
    a_uint16_t   isi_vlan;       /* vlan tag */
    a_uint16_t   isi_txseqs[17];     /* seq to be transmitted */
    a_uint16_t   isi_rxseqs[17];     /* seq previous for qos frames*/
    a_uint16_t   isi_inact;      /* inactivity timer */
    a_uint8_t    isi_uapsd;      /* UAPSD queues */
    a_uint8_t    isi_opmode;     /* sta operating mode */
    a_uint8_t    isi_cipher;
    a_uint32_t   isi_assoc_time;         /* sta association time */
    a_uint32_t   isi_tr069_assoc_time_sec;
    a_uint32_t   isi_tr069_assoc_time_nsec;
    a_uint16_t   isi_htcap;      /* HT capabilities */
    a_uint32_t   isi_rxratekbps; /* rx rate in Kbps */
    /* We use this as a common variable for legacy rates
       and lln. We do not attempt to make it symmetrical
       to isi_txratekbps and isi_txrate, which seem to be
       separate due to legacy code. */
    a_uint8_t    isi_maxrate_per_client; /* Max rate per client */
    a_uint16_t   isi_stamode;        /* Wireless mode for connected sta */
    /* XXX frag state? */
    /* variable length IE data */
} acfg_stainfo_t;

typedef struct acfg_set_scan {
    a_uint8_t            scan_type; /* IW_SCAN_TYPE_{ACTIVE,PASSIVE} */
    a_uint8_t            essid_len;
    a_uint8_t            num_channels; /* num entries in channel_list; */
    a_uint8_t            flags;
    struct {
        a_uint16_t sa_family;    /* Common data: address family and length.  */
        char sa_data[14];        /* Address data.  */
    } bssid;
    a_uint8_t            essid[ACFG_MAX_SSID_LEN];
    a_uint32_t           min_channel_time; /* in TU */
    a_uint32_t           max_channel_time; /* in TU */
    struct {
        a_int32_t        m;
        a_int16_t        e;
        a_uint8_t        i;
        a_uint8_t        flags;
    } channel_list[ACFG_MAX_FREQ];
    a_uint16_t           len;
    a_uint16_t           point_flags;
} acfg_set_scan_t;

typedef struct acfg_scanresult {
    a_uint16_t    isr_len;        /* length (mult of 4) */
    a_uint16_t    isr_freq;        /* MHz */
    a_uint32_t    isr_flags;        /* channel flags */
    a_uint8_t     isr_noise;
    a_uint8_t     isr_rssi;
    a_uint8_t     isr_intval;        /* beacon interval */
    a_uint16_t    isr_capinfo;        /* capabilities */
    a_uint8_t     isr_erp;        /* ERP element */
    a_uint8_t     isr_bssid[ACFG_MACADDR_LEN];
    a_uint8_t     isr_nrates;
    a_uint8_t     isr_rates[36];
    a_uint8_t     isr_ssid_len;        /* SSID length */
    a_uint16_t    isr_ie_len;        /* IE length */
    a_uint8_t     isr_pad[4];
    /* variable length SSID followed by IE data */
} acfg_scanresult_t;

/***************************************************************/
/******************** ACFG Data types **************************/
/***************************************************************/

/* Needs to be an explicit type */
enum acfg_opmode {
    ACFG_OPMODE_IBSS,       /**< IBSS (adhoc) station */
    ACFG_OPMODE_STA,        /**< Infrastructure station */
    ACFG_OPMODE_WDS,        /**< WDS link */
    ACFG_OPMODE_AHDEMO,     /**< Old lucent compatible adhoc demo */
    ACFG_OPMODE_RESERVE0,   /**<XXX: future use*/
    ACFG_OPMODE_RESERVE1,   /**<XXX: future use*/
    ACFG_OPMODE_HOSTAP,     /**< Software Access Point*/
    ACFG_OPMODE_RESERVE2,   /**<XXX: future use*/
    ACFG_OPMODE_MONITOR,     /**< Monitor mode*/

    /* keep this last */
    ACFG_OPMODE_INVALID,     /**< Invalid mode*/
};
typedef a_uint32_t  acfg_opmode_t; 

/**
 * brief PHY modes for VAP
 */
enum acfg_phymode {
    ACFG_PHYMODE_AUTO             = 0,  /**< autoselect */
    ACFG_PHYMODE_11A              = 1,  /**< 5GHz, OFDM */
    ACFG_PHYMODE_11B              = 2,  /**< 2GHz, CCK */
    ACFG_PHYMODE_11G              = 3,  /**< 2GHz, OFDM */
    ACFG_PHYMODE_FH               = 4,  /**< 2GHz, GFSK */
    ACFG_PHYMODE_TURBO_A          = 5,  /**< 5GHz dyn turbo*/	
    ACFG_PHYMODE_TURBO_G          = 6,	/**< 2GHz dyn turbo*/
    ACFG_PHYMODE_11NA_HT20        = 7,  /**< 5Ghz, HT20 */
    ACFG_PHYMODE_11NG_HT20        = 8,  /**< 2Ghz, HT20 */
    ACFG_PHYMODE_11NA_HT40PLUS    = 9,  /**< 5Ghz, HT40 (ext ch +1) */
    ACFG_PHYMODE_11NA_HT40MINUS   = 10,  /**< 5Ghz, HT40 (ext ch -1) */
    ACFG_PHYMODE_11NG_HT40PLUS    = 11,  /**< 2Ghz, HT40 (ext ch +1) */
    ACFG_PHYMODE_11NG_HT40MINUS   = 12, /**< 2Ghz, HT40 (ext ch -1) */
    ACFG_PHYMODE_11NG_HT40        = 13, /**< 2Ghz, HT40 auto */
    ACFG_PHYMODE_11NA_HT40        = 14, /**< 5Ghz, HT40 auto */
    ACFG_PHYMODE_11AC_VHT20       = 15, /* 5Ghz, VHT20 */
    ACFG_PHYMODE_11AC_VHT40PLUS   = 16, /* 5Ghz, VHT40 (Ext ch +1) */
    ACFG_PHYMODE_11AC_VHT40MINUS  = 17, /* 5Ghz  VHT40 (Ext ch -1) */
    ACFG_PHYMODE_11AC_VHT40       = 18, /* 5Ghz, VHT40 */
    ACFG_PHYMODE_11AC_VHT80       = 19, /* 5Ghz, VHT80 */

    /* keep it last */
    ACFG_PHYMODE_INVALID                /**< Invalid Phymode */
};
typedef a_uint32_t  acfg_phymode_t;

/**
 * brief AMPDU Settings
 */
enum acfg_ampdu {
    ACFG_CLEAR_AMPDU = 0,
    ACFG_SET_AMPDU = 1,
} ;
typedef a_uint32_t  acfg_ampdu_t;

typedef a_uint32_t  acfg_ampdu_frames_t;
typedef a_uint32_t  acfg_ampdu_limit_t;

/** 
 * @brief Mac address
 */
typedef struct acfg_macaddr {
    a_uint8_t addr[ACFG_MACADDR_LEN] ;
} acfg_macaddr_t; 


/** 
 * @brief Buffer descriptor that
 *        holds iw_range data
 */
typedef struct acfg_range {
    a_uint8_t *buff ;
    a_uint32_t len ;
} acfg_range_t ;

typedef struct acfg_range_buf {
    a_uint32_t           throughput;
    a_uint32_t           min_nwid;
    a_uint32_t           max_nwid;
    a_uint16_t           old_num_channels;
    a_uint8_t            old_num_frequency;
#if WIRELESS_EXT >= 17
    a_uint32_t           event_capa[6];
#endif
    a_int32_t            sensitivity;
    struct {
        a_uint8_t        qual;
        a_uint8_t        level;
        a_uint8_t        noise;
        a_uint8_t        updated;
    } max_qual, avg_qual;
    a_uint8_t            num_bitrates;
    a_int32_t            bitrate[ACFG_MAX_BITRATE];
    a_int32_t            min_rts;
    a_int32_t            max_rts;
    a_int32_t            min_frag;
    a_int32_t            max_frag;
    a_int32_t            min_pmp;
    a_int32_t            max_pmp;
    a_int32_t            min_pmt;
    a_int32_t            max_pmt;
    a_uint16_t           pmp_flags;
    a_uint16_t           pmt_flags;
    a_uint16_t           pm_capa;
    a_uint16_t           encoding_size[ACFG_MAX_ENCODING];
    a_uint8_t            num_encoding_sizes;
    a_uint8_t            max_encoding_tokens;
    a_uint8_t            encoding_login_index;
    a_uint16_t           txpower_capa;
    a_uint8_t            num_txpower;
#if WIRELESS_EXT >= 10
    a_int32_t            txpower[ACFG_MAX_TXPOWER];
#endif
    a_uint8_t            we_version_compiled;
    a_uint8_t            we_version_source;
    a_uint16_t           retry_capa;
    a_uint16_t           retry_flags;
    a_uint16_t           r_time_flags;
    a_int32_t            min_retry;
    a_int32_t            max_retry;
    a_int32_t            min_r_time;
    a_int32_t            max_r_time;
    a_uint16_t           num_channels;
    a_uint8_t            num_frequency;
    struct {
        a_int32_t        m;
        a_int16_t        e;
        a_uint8_t        i;
        a_uint8_t        flags;
    } freq[ACFG_MAX_FREQ];
#if WIRELESS_EXT >= 18
    a_uint32_t           enc_capa;
#endif
} acfg_range_buf_t;

/** 
 * @brief Fragmentation Threshold Flags
 */
enum acfg_frag_flags {
    ACFG_FRAG_DISABLED = 0x1,
    ACFG_FRAG_FIXED = 0x2,
    ACFG_FRAG_MAX = 2346,

    /* keep this last */
    ACFG_FRAG_INVALID = -1
};
typedef a_uint32_t acfg_frag_flags_t ;

/** 
 * @brief Fragmentation information
 */
typedef struct acfg_frag {
    a_uint32_t val ;    
    acfg_frag_flags_t flags ;
} acfg_frag_t ;


/** 
 * @brief RTS Threshold Flags
 */
enum acfg_rts_flags {
    ACFG_RTS_DISABLED = 0x1,
    ACFG_RTS_FIXED = 0x2,
    ACFG_RTS_MAX = 2347,

    /* keep this last */
    ACFG_RTS_INVALID = -1
};

typedef a_uint32_t acfg_rts_flags_t ;

/** 
 * @brief RTS information
 */
typedef struct acfg_rts {
    a_uint32_t val ;    
    acfg_rts_flags_t flags ;
} acfg_rts_t ;


/** 
 * @brief TxPower Flags
 */
enum acfg_txpow_flags {
    ACFG_TXPOW_DISABLED = 0x1,
    ACFG_TXPOW_FIXED = 0x2,
};
typedef a_uint32_t acfg_txpow_flags_t ;

/** 
 * @brief TxPower information
 */
typedef struct acfg_txpow {
    a_uint32_t val ;    
    acfg_txpow_flags_t flags ;
} acfg_txpow_t ;

/** 
 * @brief Power management
 */
typedef struct acfg_powmgmt {
    a_uint32_t val ;    
    a_uint16_t flags ;
    a_uint8_t disabled ;
} acfg_powmgmt_t ;

/** 
 * @brief Encoding Flags
 */
enum acfg_encode_flags {
    ACFG_ENCODE_ENABLED    = 0x0000,
    ACFG_ENCODE_TEMP       = 0x0400,
    ACFG_ENCODE_NOKEY      = 0x0800,
    ACFG_ENCODE_OPEN       = 0x2000,
    ACFG_ENCODE_RESTRICTED = 0x4000,
    ACFG_ENCODE_DISABLED   = 0x8000,
    ACFG_ENCODE_MODE       = 0xF000,
    ACFG_ENCODE_INDEX      = 0x00FF,
    ACFG_ENCODE_FLAGS      = 0xFF00
};

typedef a_uint32_t acfg_encode_flags_t ;

/** 
 * @brief Encoding information
 */
typedef struct acfg_encode {
    a_uint8_t *buff ;
    a_uint32_t len ;
    acfg_encode_flags_t flags ;
} acfg_encode_t ;


/** 
 * @brief Generic iw_param
 */
typedef struct acfg_iw_param {
    a_int32_t value;
    a_uint8_t fixed;
} acfg_iw_param_t ;

typedef acfg_iw_param_t acfg_rate_t;

typedef struct acfg_rateset_t {
    a_uint8_t rs_rates[ACFG_MAX_RATE_SIZE];
    a_uint8_t rs_nrates;
} acfg_rateset_t;

/**
 * brief Shortgi Settings
 */
enum acfg_shortgi {
    ACFG_CLEAR_SHORTGI = 0,
    ACFG_SET_SHOTRGI = 1,
} ;
typedef a_uint32_t  acfg_shortgi_t;


/** 
 * @brief vap create flag info 
 */ 
enum acfg_vapinfo_flags {
    ACFG_VAPINFO_CLONE_BSSID=0x1,   /**< allocate unique mac/bssid */
    ACFG_VAPINFO_NO_STABEACONS      /**< Do not setup the sta beacon timers*/ 
};
typedef a_uint32_t  acfg_vapinfo_flags_t;


/**
 * @brief Scan result data returned, All new entries 
 *        should aligned to 4-byte boundary
 * 
 */
typedef struct acfg_scan_list {
    a_uint32_t      isr_flags;      /**< channel flags */
    a_uint16_t      isr_len;        /**< length (mult of 4) */
    a_uint16_t      isr_freq;       /**< MHz */
    a_uint16_t      isr_capinfo;    /**< capabilities */
    a_uint16_t      isr_ie_len;     /**< IE length */

    acfg_ie_t       isr_rsn_ie;     /**< RSN */
    acfg_ie_t       isr_wme_ie;     /**< WME */
    acfg_ie_t       isr_wpa_ie;     /**< WPA */ 
    acfg_ie_t       isr_wps_ie;     /**< WPS */
    acfg_ie_t       isr_htcap_ie;   /**< HTCAP */
    acfg_ie_t       isr_htinfo_ie;  /**< HTINFO */
    acfg_ie_t       isr_ath_ie;     /**< ATH */

    acfg_ssid_t     isr_ssid;       /**< SSID */

    a_uint8_t       isr_noise;      /**< Noise */ 
    a_uint8_t       isr_rssi;       /**< Average RSSI */
    a_uint8_t       isr_intval;     /**< beacon interval */
    a_uint8_t       isr_erp;        /**< ERP element */

    a_uint8_t       isr_rates[ACFG_MAX_RATE_SIZE];      /**< Basic rates */
    a_uint16_t      isr_nrates;                         /**< number of rates */

    a_uint8_t       isr_htmcs_set[ACFG_MAX_RATE_SIZE];  /**< HT Rates */
    a_uint8_t       isr_bssid[ACFG_MACADDR_LEN];        /**< Mac Address */
} acfg_scan_list_t;


/** 
 * @brief Wireless statistics
 */
typedef struct acfg_stats {
    a_uint32_t status ;             /*< Device status */
    a_uint32_t link_quality;        /*< link quality */
    a_uint32_t signal_level;        /*< signal level dBm */
    a_uint32_t noise_level;         /*< noise level dBm*/
    a_uint32_t updated;
    a_uint32_t discard_nwid;        /*< packet discarded due to 
                                      wrong nwid/essid */
    a_uint32_t discard_code;        /*< packet discarded when 
                                      unable to code/decode */
    a_uint32_t missed_beacon ;      /*< missed beacon/superframe */
} acfg_stats_t ;

typedef struct acfg_ath_diag {
    a_uint8_t  ad_name[ACFG_MAX_IFNAME]; /* if name, e.g. "ath0" */
    a_uint16_t ad_id;
    a_uint16_t ad_in_size;
    a_uint8_t  *ad_in_data;
    a_uint8_t  *ad_out_data;
    a_uint32_t ad_out_size;
} acfg_ath_diag_t;

/**
 * @brief ath stats info
 */
typedef struct acfg_ath_stats {
    a_uint32_t          size;        /**< size of ath_stats */
    a_uint8_t           *address;   /**< location of ath_stats data */
    a_uint32_t          offload_if;  /**< flag to indicate 11ac offload interface */
} acfg_ath_stats_t;

#define _packed_ __attribute__((__packed__))

/* 
 * athdbg request
 */
enum {
    ACFG_DBGREQ_SENDADDBA     =    0,
    ACFG_DBGREQ_SENDDELBA     =    1,
    ACFG_DBGREQ_SETADDBARESP  =    2,
    ACFG_DBGREQ_GETADDBASTATS =    3,
    ACFG_DBGREQ_SENDBCNRPT    =    4, /* beacon report request */
    ACFG_DBGREQ_SENDTSMRPT    =    5, /* traffic stream measurement report */
    ACFG_DBGREQ_SENDNEIGRPT   =    6, /* neigbor report */
    ACFG_DBGREQ_SENDLMREQ     =    7, /* link measurement request */
    ACFG_DBGREQ_SENDBSTMREQ   =    8, /* bss transition management request */
    ACFG_DBGREQ_SENDCHLOADREQ =    9, /* bss channel load  request */
    ACFG_DBGREQ_SENDSTASTATSREQ =  10, /* sta stats request */
    ACFG_DBGREQ_SENDNHIST     =    11, /* Noise histogram request */
    ACFG_DBGREQ_SENDDELTS     =    12, /* delete TSPEC */
    ACFG_DBGREQ_SENDADDTSREQ  =    13, /* add TSPEC */
    ACFG_DBGREQ_SENDLCIREQ    =    14, /* Location config info request */
    ACFG_DBGREQ_GETRRMSTATS   =    15, /* RRM stats */
    ACFG_DBGREQ_SENDFRMREQ    =    16, /* RRM Frame request */
    ACFG_DBGREQ_GETBCNRPT     =    17, /* GET BCN RPT */
    ACFG_DBGREQ_SENDSINGLEAMSDU=   18, /* Sends single VHT MPDU AMSDUs */
    ACFG_DBGREQ_GETRRSSI      =    19, /* GET the Inst RSSI */
    ACFG_DBGREQ_GETACSREPORT  =    20, /* GET the ACS report */
};

typedef struct acfg_bcnrpt {
    a_uint8_t bssid[6];
    a_uint8_t rsni;
    a_uint8_t rcpi;
    a_uint8_t chnum;
    a_uint8_t more;
} acfg_bcnrpt_t;

typedef struct acfg_rrmstats {
    a_uint8_t     chann_load[ACFG_MAX_IEEE_CHAN];
    struct {
        a_uint8_t        antid;
        a_int8_t         anpi;
        a_uint8_t        ipi[11]; 
    } noise_data[ACFG_MAX_IEEE_CHAN];
    struct {
        struct {
            a_uint32_t   txfragcnt;
            a_uint32_t   mcastfrmcnt;
            a_uint32_t   failcnt;
            a_uint32_t   rxfragcnt;
            a_uint32_t   mcastrxfrmcnt;
            a_uint32_t   fcserrcnt;
            a_uint32_t   txfrmcnt;
        } gid0;
        struct {
            a_uint32_t   rty;
            a_uint32_t   multirty;
            a_uint32_t   frmdup;
            a_uint32_t   rtsuccess;
            a_uint32_t   rtsfail;
            a_uint32_t   ackfail;
        } gid1;
        struct {
            a_uint32_t   qostxfragcnt;
            a_uint32_t   qosfailedcnt;
            a_uint32_t   qosrtycnt;
            a_uint32_t   multirtycnt;
            a_uint32_t   qosfrmdupcnt;
            a_uint32_t   qosrtssuccnt;
            a_uint32_t   qosrtsfailcnt;
            a_uint32_t   qosackfailcnt;
            a_uint32_t   qosrxfragcnt;
            a_uint32_t   qostxfrmcnt;
            a_uint32_t   qosdiscadrfrmcnt;
            a_uint32_t   qosmpdurxcnt;
            a_uint32_t   qosrtyrxcnt;
        } gidupx[8];
        struct {
            a_uint8_t   ap_avg_delay;
            a_uint8_t   be_avg_delay;
            a_uint8_t   bk_avg_delay;
            a_uint8_t   vi_avg_delay;
            a_uint8_t   vo_avg_delay;
            a_uint16_t  st_cnt;
            a_uint8_t   ch_util;
        } gid10;
        struct {
            a_uint8_t    tid;
            a_uint8_t    brange;
            a_uint8_t    mac[6];
            a_uint32_t   tx_cnt;
            a_uint32_t   discnt;
            a_uint32_t   multirtycnt;
            a_uint32_t   cfpoll;
            a_uint32_t   qdelay;
            a_uint32_t   txdelay;
            a_uint32_t   bin[6];
        } tsm_data;
        struct {
            a_uint8_t    phytype;
            a_uint8_t    arcpi;
            a_uint8_t    lrsni;
            a_uint8_t    lrcpi;
            a_uint8_t    antid;
            a_uint8_t    ta[6];
            a_uint8_t    bssid[6];
            a_uint16_t   frmcnt;
        } frmcnt_data[12];
        struct {
            a_uint8_t    tx_pow;
            a_uint8_t    lmargin;
            a_uint8_t    rxant;
            a_uint8_t    txant;
            a_uint8_t    rcpi;
            a_uint8_t    rsni;
        } lm_data;
        struct {
            a_uint8_t    id;
            a_uint8_t    len;
            a_uint8_t    lat_res;
            a_uint8_t    alt_type;
            a_uint8_t    long_res;
            a_uint8_t    alt_res;
            a_uint8_t    azi_res;
            a_uint8_t    alt_frac;
            a_uint8_t    datum;
            a_uint8_t    azi_type;
            a_uint16_t   lat_integ;
            a_uint16_t   long_integ;
            a_uint16_t   azimuth;
            a_uint32_t   lat_frac;
            a_uint32_t   long_frac;
            a_uint32_t   alt_integ;
        } ni_rrm_lciinfo;
        struct {
            a_uint8_t    id;
            a_uint8_t    len;
            a_uint8_t    lat_res;
            a_uint8_t    alt_type;
            a_uint8_t    long_res;
            a_uint8_t    alt_res;
            a_uint8_t    azi_res;
            a_uint8_t    alt_frac;
            a_uint8_t    datum;
            a_uint8_t    azi_type;
            a_uint16_t   lat_integ;
            a_uint16_t   long_integ;
            a_uint16_t   azimuth;
            a_uint32_t   lat_frac;
            a_uint32_t   long_frac;
            a_uint32_t   alt_integ;
        } ni_vap_lciinfo;
    } ni_rrm_stats;
} acfg_rrmstats_t;

typedef struct acfg_acs_dbg {
    a_uint8_t   nchans;
    a_uint8_t   entry_id;
    a_uint16_t  chan_freq;
    a_uint8_t   ieee_chan;
    a_uint8_t   chan_nbss;
    a_int32_t   chan_maxrssi;
    a_int32_t   chan_minrssi;
    a_int16_t   noisefloor;
    a_int16_t   channel_loading;
    a_uint32_t  chan_load;
    a_uint8_t   sec_chan;
} acfg_acs_dbg_t;

typedef struct acfg_athdbg_req {
    a_uint8_t cmd;
    a_uint8_t dstmac[ACFG_MACADDR_LEN];
    union {
        int param[4];
        struct  {
            a_uint16_t   num_rpt;
            a_uint8_t    regclass;
            a_uint8_t    channum;
            a_uint16_t   random_ivl;
            a_uint16_t   duration;
            a_uint8_t    reqmode;
            a_uint8_t    reqtype;
            a_uint8_t    bssid[6];
            a_uint8_t    mode;
            a_uint8_t    req_ssid;
            a_uint8_t    rep_cond;
            a_uint8_t    rep_thresh;
            a_uint8_t    rep_detail;
            a_uint8_t    req_ie;
            a_uint8_t    num_chanrep;
            struct {
                a_uint8_t regclass;
                a_uint8_t numchans;
                a_uint8_t channum[5];
            } apchanrep[2];
        } bcnrpt;
        struct {
            a_uint16_t   num_rpt;
            a_uint16_t   rand_ivl;
            a_uint16_t   meas_dur;
            a_uint8_t    reqmode;
            a_uint8_t    reqtype;
            a_uint8_t    tid;
            a_uint8_t    macaddr[6];
            a_uint8_t    bin0_range;
            a_uint8_t    trig_cond;
            a_uint8_t    avg_err_thresh;
            a_uint8_t    cons_err_thresh;
            a_uint8_t    delay_thresh;
            a_uint8_t    meas_count;
            a_uint8_t    trig_timeout;
        } tsmrpt;
        struct {
            a_uint8_t   dialogtoken;
            a_uint8_t   ssid[32];
            a_uint8_t   ssid_len;
        } neigrpt;
        struct {
            a_uint8_t   dialogtoken;
            a_uint8_t   candidate_list;
            a_uint8_t   disassoc;
            a_uint16_t  disassoc_timer;
            a_uint8_t   validity_itvl;
        } _packed_ bstmreq;
        struct {
            a_uint8_t    traffic_type;
            a_uint8_t    direction;
            a_uint8_t    dot1Dtag;
            a_uint8_t    tid;
            a_uint8_t    acc_policy_edca;
            a_uint8_t    acc_policy_hcca;
            a_uint8_t    aggregation;
            a_uint8_t    psb;
            a_uint8_t    ack_policy;
            a_uint16_t   norminal_msdu_size;
            a_uint16_t   max_msdu_size;
            a_uint32_t   min_srv_interval;
            a_uint32_t   max_srv_interval;
            a_uint32_t   inactivity_interval;
            a_uint32_t   suspension_interval;
            a_uint32_t   srv_start_time;
            a_uint32_t   min_data_rate;
            a_uint32_t   mean_data_rate;
            a_uint32_t   peak_data_rate;
            a_uint32_t   max_burst_size;
            a_uint32_t   delay_bound;
            a_uint32_t   min_phy_rate;
            a_uint16_t   surplus_bw;
            a_uint16_t   medium_time;
        } tsinfo;
        struct {
            a_uint8_t    dstmac[6];
            a_uint16_t   num_rpts;
            a_uint8_t    regclass;
            a_uint8_t    chnum;
            a_uint16_t   r_invl;
            a_uint16_t   m_dur;
            a_uint8_t    cond;
            a_uint8_t    c_val;
        } chloadrpt;
        struct {
            a_uint8_t    dstmac[6];
            a_uint16_t   num_rpts;
            a_uint16_t   m_dur;
            a_uint16_t   r_invl;
            a_uint8_t    gid;
        } stastats;
        struct {
            a_uint16_t   num_rpts;
            a_uint8_t    dstmac[6];
            a_uint8_t    regclass;
            a_uint8_t    chnum;
            a_uint16_t   r_invl;
            a_uint16_t   m_dur;
            a_uint8_t    cond;
            a_uint8_t    c_val;
        } nhist;
        struct {
            a_uint8_t    dstmac[6];
            a_uint8_t    peermac[6];
            a_uint16_t   num_rpts;
            a_uint8_t    regclass;
            a_uint8_t    chnum;
            a_uint16_t   r_invl;
            a_uint16_t   m_dur;
            a_uint8_t    ftype;
        } frm_req;
        struct {
            a_uint8_t    dstmac[6];
            a_uint16_t   num_rpts;
            a_uint8_t    location;
            a_uint8_t    lat_res;
            a_uint8_t    long_res;
            a_uint8_t    alt_res;
            a_uint8_t    azi_res;
            a_uint8_t    azi_type;
        } lci_req;
        struct {
            a_uint32_t   index;
            a_uint32_t   data_size;
            void         *data_addr;
        } rrmstats_req;
        struct {
            a_uint32_t   index;
            a_uint32_t   data_size;
            void         *data_addr;
        } acs_rep;
    } data;
} acfg_athdbg_req_t;


/**
 * @brief scan request info
 */
typedef struct acfg_scan {
    a_uint32_t          len;        /**< Valid entries*/
    a_uint16_t          more;       /**< if more entries left*/
    a_uint16_t          offset;     /**< how much the user has read */
    a_uint8_t           *results;
    acfg_scan_list_t    list[ACFG_MAX_SCANLIST];
} acfg_scan_t;

enum {
    RESTART_NONE = 0,
    RESTART_SECURITY = 1,
};
typedef a_uint32_t acfg_vendor_param_init_flag_t;
/** 
 * @brief Structure used in get/set of param values
 */
typedef struct acfg_param_req {
    a_uint32_t param;
    a_uint32_t val;
} acfg_param_req_t ;

/* vendors can fill this enum for commands, below cmds are only for sample, it can be removed */
enum {
    ACFG_VENDOR_PARAM_CMD_PRINT = 1,
    ACFG_VENDOR_PARAM_CMD_INT,
    ACFG_VENDOR_PARAM_CMD_MAC,
};
typedef a_uint32_t acfg_vendor_param_vap_t;

/* vendors can fill this union for typecasting later in application */
typedef union {
    a_uint8_t data[ACFG_VENDOR_PARAM_LEN];
} acfg_vendor_param_data_t;

typedef struct acfg_vendor_param_req {
    acfg_vendor_param_vap_t  param;
    a_uint32_t               type;
    acfg_vendor_param_data_t data;
} acfg_vendor_param_req_t;

/** 
 *  * @brief Structure used in get mac acl list;
 *   */
typedef struct acfg_acl_mac {
    a_uint32_t num;
    a_uint8_t  macaddr[ACFG_MAX_ACL_NODE][ACFG_MACADDR_LEN];
} acfg_macacl_t ;


/** 
 * @brief Structure used in get/set of wmm param values
 */
typedef struct acfg_wmmparams_req {
    a_uint32_t param[5];
    a_uint32_t val;
} acfg_wmmparams_req_t ;

enum acfg_param_vap {
    ACFG_PARAM_VAP_SHORT_GI         = 71,
    ACFG_PARAM_VAP_AMPDU            = 73,
    ACFG_PARAM_AUTHMODE             = 3,
    ACFG_PARAM_ROAMING              = 12,
    ACFG_PARAM_DROPUNENCRYPTED      = 15,
    ACFG_PARAM_MACCMD               = 17,
    ACFG_PARAM_HIDESSID             = 19,
    ACFG_PARAM_APBRIDGE             = 20,
    ACFG_PARAM_DTIM_PERIOD          = 28,
    ACFG_PARAM_BEACON_INTERVAL      = 29,
    ACFG_PARAM_BURST                = 36,
    ACFG_PARAM_PUREG                = 37,
    ACFG_PARAM_WDS                  = 39,
    ACFG_PARAM_UAPSD                = 53,
    ACFG_PARAM_COUNTRY_IE           = 45,
    ACFG_PARAM_CHANBW               = 60,
    ACFG_PARAM_SHORTPREAMBLE        = 62,
    ACFG_PARAM_CWM_ENABLE           = 68,
    ACFG_PARAM_AMSDU                = 77,
    ACFG_PARAM_COUNTRYCODE          = 79,
    ACFG_PARAM_SETADDBAOPER         = 85,  
    ACFG_PARAM_11N_RATE             = 87,
    ACFG_PARAM_11N_RETRIES          = 88,
    ACFG_PARAM_DBG_LVL              = 89,
    ACFG_PARAM_STA_FORWARD          = 93,
    ACFG_PARAM_ME                   = 94,
    ACFG_PARAM_MEDUMP               = 95,
    ACFG_PARAM_MEDEBUG              = 96,
    ACFG_PARAM_ME_SNOOPLEN          = 97,
    ACFG_PARAM_ME_TIMER             = 98,
    ACFG_PARAM_ME_TIMEOUT           = 99,
    ACFG_PARAM_PUREN                = 100,
    ACFG_PARAM_NO_EDGE_CH           = 102,
    ACFG_PARAM_WEP_TKIP_HT          = 103,
    ACFG_PARAM_VAP_IND              = 111,
    ACFG_PARAM_GREEN_AP_PS_ENABLE   = 113,
    ACFG_PARAM_GREEN_AP_PS_TIMEOUT  = 114,
    ACFG_PARAM_WPS                  = 116,
    ACFG_PARAM_CHWIDTH              = 122,
    ACFG_PARAM_EXTAP                = 123,
    ACFG_PARAM_DISABLECOEXT         = 124,
    ACFG_PARAM_TDLS_ENABLE          = 147,
    ACFG_PARAM_SET_TDLS_RMAC        = 148,
    ACFG_PARAM_CLR_TDLS_RMAC        = 149,
    ACFG_PARAM_TDLS_MACADDR1        = 150,
    ACFG_PARAM_TDLS_MACADDR2        = 151,
    ACFG_PARAM_PERIODIC_SCAN        = 170,
    ACFG_PARAM_SW_WOW               = 177,
    ACFG_PARAM_WMMPARAMS_CWMIN      = 178,
    ACFG_PARAM_WMMPARAMS_CWMAX      = 179,
    ACFG_PARAM_WMMPARAMS_AIFS       = 180,
    ACFG_PARAM_WMMPARAMS_TXOPLIMIT  = 181,
    ACFG_PARAM_WMMPARAMS_ACM        = 182,
    ACFG_PARAM_WMMPARAMS_NOACKPOLICY= 183,
    ACFG_PARAM_SCANVALID            = 184,
    ACFG_PARAM_AUTO_ASSOC           = 185,
    ACFG_PARAM_SCANBAND             = 186,
    ACFG_PARAM_QBSS_LOAD            = 194,
    ACFG_PARAM_RRM_CAP              = 195,
    ACFG_PARAM_TDLS_AUTO_ENABLE     = 201,
    ACFG_PARAM_TDLS_DIALOG_TOKEN    = 202,
    ACFG_PARAM_TDLS_DISCOVERY_REQ   = 203,
    ACFG_PARAM_HIDE_SSID            = 204,
    ACFG_PARAM_DOTH                 = 205,
    ACFG_PARAM_COEXT_DISABLE        = 206,
    ACFG_PARAM_AMPDU                = 207,
    ACFG_PARAM_UCASTCIPHERS         = 208,
    ACFG_PARAM_MAXSTA               = 242,
    ACFG_PARAM_RRM_STATS            = 243,
    ACFG_PARAM_RRM_SLWINDOW         = 244,
    ACFG_PARAM_PROXYARP_CAP         = 263,
    ACFG_PARAM_DGAF_DISABLE         = 264,
    ACFG_PARAM_L2TIF_CAP            = 265,
    ACFG_PARAM_WNM_ENABLE           = 266,
    ACFG_PARAM_WNM_BSSMAX           = 267,
    ACFG_PARAM_WNM_TFS              = 268,
    ACFG_PARAM_WNM_TIM              = 269,
    ACFG_PARAM_WNM_SLEEP            = 270,
    ACFG_PARAM_RRM_DEBUG            = 276,
    ACFG_PARAM_VHT_MCS              = 279,
    ACFG_PARAM_NSS                  = 282,
    ACFG_PARAM_LDPC                 = 283,
    ACFG_PARAM_TX_STBC              = 284,
    ACFG_PARAM_PURE11AC             = 285,
    ACFG_PARAM_OPMODE_NOTIFY        = 296,
    ACFG_PARAM_ENABLE_RTSCTS        = 299,
    ACFG_PARAM_MAX_AMPDU            = 300,   
    ACFG_PARAM_VHT_MAX_AMPDU        = 301,   
    ACFG_PARAM_EXT_IFACEUP_ACS      = 311,
    ACFG_PARAM_SHORT_SLOT           = 351,   /* Set short slot time */
    ACFG_PARAM_ERP                  = 352,   /* Set ERP protection */
    ACFG_PARAM_ATF_OPT              = 355,
};
typedef a_uint32_t acfg_param_vap_t ;

#define ATH_PARAM_SHIFT     0x1000
#define SPECIAL_PARAM_SHIFT     0x2000
enum acfg_param_radio {
    ACFG_PARAM_RADIO_TXCHAINMASK          = 1  | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_RXCHAINMASK          = 2  | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_TXCHAINMASK_LEGACY   = 3  | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_RXCHAINMASK_LEGACY   = 4  | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_AMPDU                = 6  | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_AMPDU_LIMIT          = 7  | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_AMPDU_SUBFRAMES      = 8  | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_TXPOWER_LIMIT2G      = 12 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_TXPOWER_LIMIT5G      = 13 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_ATH_DEBUG            = 19 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_GPIO_LED_CUSTOM      = 37 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_SWAP_DEFAULT_LED     = 38 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_VOWEXT               = 40 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_RCA                  = 41 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_VSP_ENABLE           = 42 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_VSP_THRESHOLD        = 43 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_VSP_EVALINTERVAL     = 44 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_VOWEXT_STATS         = 45 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_BRIDGE               = 48 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_PHYRESTART_WAR       = 70 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_KEYSEARCH_ALWAYS_WAR = 72 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_AMPDU_RX_BSIZE       = 74 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_SMARTANTENNA         = 76 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_AGGR_BURST 	  = 77 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_AGGR_BURST_DUR       = 78 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_DCS_ENABLE           = 82 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_DCS_COCH             = 93 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_DCS_TXERR            = 94 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_DCS_PHYERR           = 95 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_SMARTANT_TRAIN_MODE        = 96 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_SMARTANT_TRAIN_TYPE        = 97 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_SMARTANT_PKT_LEN           = 98 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_SMARTANT_NUM_PKTS          = 99 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_SMARTANT_TRAIN_START       = 100 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_SMARTANT_NUM_ITR           = 101 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_SMARTANT_CURRENT_ANT       = 102 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_SMARTANT_DEFAULT_ANT       = 103 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_SMARTANT_TRAFFIC_GEN_TIMER = 104 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_SMARTANT_RETRAIN           = 105 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_SMARTANT_RETRAIN_THRESH    = 106 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_SMARTANT_RETRAIN_INTERVAL  = 107 | ATH_PARAM_SHIFT,
    ACFG_PARAM_RADIO_SMARTANT_RETRAIN_DROP      = 108 | ATH_PARAM_SHIFT,

    /* Minimum Good put threshold to tigger performance training */
    ACFG_PARAM_RADIO_SMARTANT_MIN_GP_THRESH     = 109 | ATH_PARAM_SHIFT, 

    /* Number of intervals Good put need to be averaged 
     * to use in performance training tigger 
     */
    ACFG_PARAM_RADIO_SMARTANT_GP_AVG_INTERVAL   = 110 | ATH_PARAM_SHIFT, 

    /*
     * Enable Acs back Ground Channel selection Scan timer in AP mode
     * */
    ACFG_PARAM_RADIO_ACS_ENABLE_BK_SCANTIMER = 118 | ATH_PARAM_SHIFT,
    /* 
     * ACS scan timer value in Seconds 
     * */
    ACFG_PARAM_RADIO_ACS_SCANTIME = 119 | ATH_PARAM_SHIFT, 
    /*
     * Negligence Delta RSSI between two channel 
     * */
    ACFG_PARAM_RADIO_ACS_RSSIVAR = 120 | ATH_PARAM_SHIFT,  
    /*
     * Negligence Delta Channel load between two channel
     * */
    ACFG_PARAM_RADIO_ACS_CHLOADVAR = 121 | ATH_PARAM_SHIFT, 
    /* 
     * Enable Limited OBSS check 
     * */
    ACFG_PARAM_RADIO_ACS_LIMITEDOBSS = 122 | ATH_PARAM_SHIFT, 
    /* 
     * Acs control flag for Scan timer 
     * */
    ACFG_PARAM_RADIO_ACS_CTRLFLAG   = 123 | ATH_PARAM_SHIFT, 
    /* 
     * Acs Run time Debug level
     * */
    ACFG_PARAM_RADIO_ACS_DEBUGTRACE = 124  | ATH_PARAM_SHIFT, 
    ACFG_PARAM_RADIO_FW_HANG_ID     = 137  | ATH_PARAM_SHIFT,  
    ACFG_PARAM_RADIO_FW_RECOVERY_ID = 180  | ATH_PARAM_SHIFT, 

    ACFG_PARAM_RADIO_COUNTRYID            = 00 | SPECIAL_PARAM_SHIFT,
    ACFG_PARAM_RADIO_REGDOMAIN            = 12 | SPECIAL_PARAM_SHIFT,
    ACFG_PARAM_RADIO_ENABLE_OL_STATS      = 13 | SPECIAL_PARAM_SHIFT, 
    ACFG_PARAM_RADIO_ENABLE_MAC_REQ       = 14 | SPECIAL_PARAM_SHIFT,
    ACFG_PARAM_RADIO_ENABLE_SHPREAMBLE    = 15 | SPECIAL_PARAM_SHIFT,
    ACFG_PARAM_RADIO_ENABLE_SHSLOT        = 16 | SPECIAL_PARAM_SHIFT,

    ACFG_PARAM_RADIO_DYN_TX_CHAINMASK     = 73 | ATH_PARAM_SHIFT,
    ACFG_PARAM_HAL_CONFIG_FORCEBIASAUTO   = 6,
    ACFG_PARAM_HAL_CONFIG_DEBUG           = 32,
    ACFG_PARAM_HAL_CONFIG_CRDC_ENABLE     = 36,
    ACFG_PARAM_HAL_CONFIG_CRDC_WINDOW     = 37,
    ACFG_PARAM_HAL_CONFIG_CRDC_DIFFTHRESH = 38,
    ACFG_PARAM_HAL_CONFIG_CRDC_RSSITHRESH = 39,
    ACFG_PARAM_HAL_CONFIG_CRDC_NUMERATOR  = 40,
    ACFG_PARAM_HAL_CONFIG_CRDC_DENOMINATOR= 41,
    ACFG_PARAM_HAL_CONFIG_PRINT_BBDEBUG   = 45,
};
typedef a_uint32_t acfg_param_radio_t ;

/** 
 * @brief Station Capability Flags
 *        for acfg_sta_info_t.cap
 */
enum acfg_sta_capability {
    ACFG_CAP_ESS            = 0x0001,
    ACFG_CAP_IBSS           = 0x0002,
    ACFG_CAP_CF_POLLABLE    = 0x0004,
    ACFG_CAP_CF_POLLREQ     = 0x0008,
    ACFG_CAP_PRIVACY        = 0x0010,
    ACFG_CAP_SHORT_PREAMBLE = 0x0020,
    ACFG_CAP_PBCC           = 0x0040,
    ACFG_CAP_CHNL_AGILITY   = 0x0080,
    ACFG_CAP_SPECTRUM_MGMT  = 0x0100,
    ACFG_CAP_QOS            = 0x0200,
    ACFG_CAP_SHORT_SLOTTIME = 0x0400,
    ACFG_CAP_APSD           = 0x0800,
    /* bit 12 is reserved */
    ACFG_CAP_DSSSOFDM       = 0x2000,
    /* bits 14-15 are reserved */

};
typedef a_uint32_t acfg_sta_capability_t ;

/** 
 * @brief Station Atheros Capability Flags
 *        for acfg_sta_info_t.athcap
 */
enum acfg_sta_ath_capability {
    ACFG_ATHCAP_TURBOP  = 0x0001,   /**< Turbo prime enable */
    ACFG_ATHCAP_COMP    = 0x0002,   /**< Compresssion enable */
    ACFG_ATHCAP_FF      = 0x0004,   /**< Fast Frame capable */
    ACFG_ATHCAP_XR      = 0x0008,   /**< Atheros WME enable */
    ACFG_ATHCAP_AR      = 0x0010,   /**< AR capable */
    ACFG_ATHCAP_BOOST   = 0x0080,
};
typedef a_uint32_t acfg_sta_ath_capability_t ;

/** 
 * @brief Station HT Capability Flags
 *        for acfg_sta_info_t.htcap
 */
enum acfg_sta_ht_capability {
    ACFG_HTCAP_ADVCODING            = 0x0001,
    ACFG_HTCAP_CHWIDTH40            = 0x0002,
    ACFG_HTCAP_SMPOWERSAVE_STATIC   = 0x0000, /**< Capable of SM 
                                                Power Save (Static) */
    ACFG_HTCAP_SMPOWERSAVE_DYNAMIC  = 0x0004, /**< Capable of 
                                                SM Power Save (Dynamic) */
    ACFG_HTCAP_SM_RESERVED          = 0x0008, /**< Reserved */
    ACFG_HTCAP_SM_ENABLED           = 0x000C, /**< SM enabled, 
                                                no SM Power Save */
    ACFG_HTCAP_GREENFIELD           = 0x0010,
    ACFG_HTCAP_SHORTGI20            = 0x0020,
    ACFG_HTCAP_SHORTGI40            = 0x0040,
    ACFG_HTCAP_TXSTBC               = 0x0080,
    ACFG_HTCAP_RXSTBC               = 0x0300,  /**< 2 bits */
    ACFG_HTCAP_RXSTBC_S             = 0x8,
    ACFG_HTCAP_DELAYEDBLKACK        = 0x0400,
    ACFG_HTCAP_MAXAMSDUSIZE         = 0x0800,  /**< 1 = 8K, 0 = 3839B */
    ACFG_HTCAP_DSSSCCK40            = 0x1000,
    ACFG_HTCAP_PSMP                 = 0x2000,
    ACFG_HTCAP_INTOLERANT40         = 0x4000,
    ACFG_HTCAP_LSIGTXOPPROT         = 0x8000,
};
typedef a_uint32_t acfg_sta_ht_capability_t ;

/** 
 * @brief Station state flags.
 *        Used with acfg_sta_info_t.state
 */
enum sta_flags_t {
    ACFG_NODE_AUTH          = 0x00000001,   /**< authorized for data */
    ACFG_NODE_QOS           = 0x00000002,   /**< QoS enabled */
    ACFG_NODE_ERP           = 0x00000004,   /**< ERP enabled */
    ACFG_NODE_HT            = 0x00000008,   /**< HT enabled */
    ACFG_NODE_PWR_MGT       = 0x00000010,   /**< power save mode enabled */
    ACFG_NODE_UAPSD         = 0x00000040,   /**< U-APSD power save enabled */
    ACFG_NODE_UAPSD_TRIG    = 0x00000080,   /**< U-APSD triggerable state */
    ACFG_NODE_UAPSD_SP      = 0x00000100,   /**< U-APSD SP in progress */
    ACFG_NODE_ATH           = 0x00000200,   /**< Atheros Owl or 
                                              follow-on device */
    ACFG_NODE_OWL_WDSWAR    = 0x00000400,   /**< Owl WDS workaround needed */
    ACFG_NODE_WDS           = 0x00000800,   /**< WDS link */
    ACFG_NODE_NOAMPDU       = 0x00001000,   /**< No AMPDU support */
    ACFG_NODE_WEPTKIPAGGR   = 0x00002000,   /**< Atheros proprietary 
                                              wep/tkip aggregation support */
    ACFG_NODE_WEPTKIP       = 0x00004000,
    ACFG_NODE_TEMP          = 0x00008000,   /**< temp node (not in 
                                              the node table) */
    ACFG_NODE_40_INTOLERANT = 0x00020000,   /**< HT40 Intolerant  */
    ACFG_NODE_PAUSED        = 0x00040000,   /**< node is  paused*/
    ACFG_NODE_EXTRADELIMWAR = 0x00080000,
    ACFG_NODE_NAWDS         = 0x00100000,   /**< node is an NAWDS repeater */
    ACFG_NODE_TDLS          = 0x00200000,   /**< TDLS node */
    ACFG_NODE_REQ_HT20      = 0x00400000,   /**< HT20 requesting node */
    ACFG_NODE_ATH_PAUSED    = 0x00800000,   /**< all the tid queues 
                                              in ath layer are paused */
};


/** 
 * @brief Structure to hold station information
 */
typedef struct acfg_sta_info {
    a_uint32_t associd ;    /**< Association id */
    a_uint32_t channel ;    /**< Channel */
    a_uint32_t txrate ;     /**< Tx Rate (Mbps) */
    a_int32_t rssi ;        /**< */
    a_uint32_t inact ;      /**< Inactivity timer */
    a_uint32_t rxseq ;      /**< seq previous for qos frames */
    a_uint32_t txseq ;      /**< seq to be transmitted */
    a_uint32_t cap ;        /**< Capabilities */
    a_uint32_t athcap ;     /**< Atheros Capabilities */
    a_uint32_t htcap ;      /**< HT Capabilities */
    a_uint32_t state ;      /**< state flags */
    a_uint8_t erp ;         /**< Erp element */
    a_uint8_t macaddr[ACFG_MACADDR_LEN] ;
} acfg_sta_info_t ;


/** 
 * @brief Structure used in request to get station information
 */
typedef struct acfg_sta_info_req {
    a_uint32_t len ;        /**< Length of buffer */
    acfg_sta_info_t *info ; /**< Pointer to array of acfg_sta_info_t */
} acfg_sta_info_req_t ;


typedef enum {
    ACFG_TX99_ENABLE,
    ACFG_TX99_DISABLE,
    ACFG_TX99_SET_FREQ,
    ACFG_TX99_SET_RATE,
    ACFG_TX99_SET_POWER,
    ACFG_TX99_SET_TXMODE,
    ACFG_TX99_SET_CHANMASK,
    ACFG_TX99_SET_TYPE,
    ACFG_TX99_GET
} acfg_tx99_type_t;

#define SET_TX99_TX(flags) (flags|=0x1)
#define SET_TX99_RX(flags) (flags&=~0x1)
#define ENABLE_TX99_TX(flags) (flags|=0x2)
#define DISABLE_TX99_TX(flags) (flags&=~0x2)
#define SET_TX99_RX_REPORT(flags) (flags|=0x4)
#define CLEAR_TX99_RX_REPORT(flags) (flags&=~0x4)
#define IS_TX99_TX(flags) ((flags&0x1) == 0x1)
#define IS_TX99_TX_ENABLED(flags) ((flags&0x2) == 0x2)
#define IS_TX99_RX_REPORT(flags) ((flags&0x4) == 0x4)
#define TX99_MAX_PARAM_NUM  12

typedef struct acfg_tx99_data {
    a_uint32_t freq;	/* tx frequency (MHz) */
    a_uint32_t chain;   /* tx chain */
    a_uint32_t htmode;	/* tx bandwidth (HT20/HT40) */
    a_uint32_t htext;	/* extension channel offset (0(none), 1(plus) and 2(minus)) */
    a_uint32_t rate;	/* Kbits/s */
    a_uint32_t rc;	        /* rate code */
    a_uint32_t power;  	/* (dBm) */
    a_uint32_t txmode;  /* wireless mode, 11NG(8), auto-select(0) */
    a_uint32_t chanmask; /* tx chain mask */
    a_uint32_t type;
    a_uint32_t flags;    /* flags:  enable/disable, tx/rx, rx_report */
    a_uint8_t  mode[16]; /* wireless mode string */
} acfg_tx99_data_t;

typedef struct acfg_tx99 {
    char                if_name[ACFG_MAX_IFNAME];/**< Interface name */
    acfg_tx99_type_t    type;             /**< Type of wcmd */
    acfg_tx99_data_t    data;             /**< Data */       
} acfg_tx99_t;

typedef enum {
    NAWDS_NOP,
    NAWDS_SET_MODE,
    NAWDS_SET_DEFCAPS,
    NAWDS_SET_OVERRIDE,
    NAWDS_SET_ADDR,
    NAWDS_CLR_ADDR,
    NAWDS_GET,
    WNM_SET_BSSMAX,
    WNM_GET_BSSMAX,
    WNM_TFS_ADD,
    WNM_TFS_DELETE,
    WNM_SET_TIMBCAST,
    WNM_GET_TIMBCAST,
    WDS_ADD_ADDR,
}NAWDS_CMDTYPE;

typedef enum {
    NAWDS_OK   = 0,
    NAWDS_FAIL = 1,
}NAWDS_STATUS;

#define TFS_MAX_FILTER_LEN 50
#define TFS_MAX_TCLAS_ELEMENTS 2
#define TFS_MAX_SUBELEMENTS 2
#define TFS_MAX_REQUEST 2
#define TFS_MAX_RESPONSE 600
#define ACFG_IPV4_LEN 4
#define ACFG_IPV6_LEN 16

struct acfg_clas3 {
    a_uint16_t filter_offset;
    a_uint32_t filter_len;
    a_uint8_t  filter_value[TFS_MAX_FILTER_LEN];
    a_uint8_t  filter_mask[TFS_MAX_FILTER_LEN];
} _packed_ ;

struct acfg_clas4_v4 {
    a_uint8_t     version;
    a_uint8_t     source_ip[ACFG_IPV4_LEN];
    a_uint8_t     reserved1[ACFG_IPV6_LEN - ACFG_IPV4_LEN];
    a_uint8_t     dest_ip[ACFG_IPV4_LEN];
    a_uint8_t     reserved2[ACFG_IPV6_LEN - ACFG_IPV4_LEN];
    a_uint16_t    source_port;
    a_uint16_t    dest_port;
    a_uint8_t     dscp;
    a_uint8_t     protocol;
    a_uint8_t     reserved;
    a_uint8_t     reserved3[2];
} _packed_ ;

struct acfg_clas4_v6 {
    a_uint8_t     version;
    a_uint8_t     source_ip[ACFG_IPV6_LEN];
    a_uint8_t     dest_ip[ACFG_IPV6_LEN];
    a_uint16_t    source_port;
    a_uint16_t    dest_port;
    a_uint8_t     dscp;
    a_uint8_t     next_header;
    a_uint8_t     flow_label[3];
} _packed_ ;

struct acfg_tfsreq_tclas_element {
    a_uint8_t classifier_type;
    a_uint8_t classifier_mask;
    a_uint8_t priority;
    union {
        struct acfg_clas3 clas3;
        union {
            struct acfg_clas4_v4 clas4_v4;
            struct acfg_clas4_v6 clas4_v6;
        } clas4;
    } clas;
} _packed_ ;

struct acfg_tfsreq_subelement {
    a_uint32_t num_tclas_elements;
    a_uint8_t tclas_processing;
    struct acfg_tfsreq_tclas_element tclas[TFS_MAX_TCLAS_ELEMENTS];
} _packed_ ;

struct acfg_wnm_tfs_req {
    a_uint8_t tfsid;
    a_uint8_t actioncode;
    a_uint8_t num_subelements;
    struct acfg_tfsreq_subelement subelement[TFS_MAX_SUBELEMENTS];
} _packed_ ;

struct acfg_wnm_tfs {
    a_uint8_t num_tfsreq;
    struct acfg_wnm_tfs_req  tfs_req[TFS_MAX_REQUEST];
} _packed_ ;

struct acfg_wnm_bssmax {
    a_uint16_t idleperiod;
};

struct acfg_wnm_tim {
    a_uint8_t interval;
    a_uint8_t enable_highrate;
    a_uint8_t enable_lowrate;
} _packed_ ;

struct acfg_wnm_cfg {
    union {
        struct acfg_wnm_bssmax bssmax;
        struct acfg_wnm_tfs tfs;
        struct acfg_wnm_tim tim;
    }data;
} _packed_ ;

/** 
 * @brief Structure used in wds/nawds config
 */
typedef struct acfg_nawds_cfg {
    NAWDS_CMDTYPE cmdtype;
    NAWDS_STATUS status;
    union {
        struct {
            a_uint8_t num;
            a_uint8_t mode;
            a_uint8_t defcaps;
            a_uint8_t override;
            a_uint8_t mac[ACFG_MACADDR_LEN];
            a_uint8_t caps;
        }nawds;

        struct acfg_wnm_cfg wnm;
    }data;
} acfg_nawds_cfg_t;

typedef struct acfg_ratemask {
    a_uint8_t preamble;
    a_uint32_t mask_lower32;
    a_uint32_t mask_higher32;
} acfg_ratemask_t;

typedef struct acfg_atf_ssid_val {
    a_uint16_t  id_type;
    a_uint8_t   ssid[ACFG_MAX_SSID_LEN+1];
    a_uint32_t  value;
} acfg_atf_ssid_val_t;

typedef struct acfg_atf_sta_val {
    a_uint16_t    id_type;
    a_uint8_t     sta_mac[ACFG_MACADDR_LEN];
    a_uint32_t    value;
} acfg_atf_sta_val_t;

/* 
 *  @brief
 *  Command Header for Device-less cfg interface
 *  byte 0:
 *  bits[3:0] - Reserved
 *  bits[4:4] - Node Id (0: kernel/1: peer)
 *  bits[5:5] - Command Type (Req/Resp)
 *  bits[6:6] - Acknowledgement Required (0/1)
 *  bits[7:7] - Response Required (0/1)
 *  
 *  byte 1:
 *  bits[7:0] - Command Identifier (0 - 247)
 *  
 *  byte 3:
 *  bits[7:0] - Parameters length (LSB)
 *  
 *  byte 4:
 *  bits[7:0] - Parameters length (MSB)
 */  

/* */  
typedef struct acfg_dl_cfg_hdr {
    a_uint8_t   data[4];
} acfg_dl_cfg_hdr_t;

/* Byte 0 Values */
#define ACFG_DL_NODE_ALL          0x00
#define ACFG_DL_NODE_REMOTE       0x10

#define ACFG_CMD_REQ_MASK        0x20

#define ACFG_CMD_REQ           0x20
#define ACFG_CMD_RESP          0x00
#define ACFG_RESP_REQD         0x80 

#define ACFG_RPLAYCMD_SUCCESS   1
#define ACFG_ACK_SUCCESS        1
#define ACFG_ACK_FAILURE        0
/* ACFG DL Cmd Ids */
enum {
    ACFG_DL_VLGRP_CREATE    =   0,
    ACFG_DL_VLGRP_DELETE    =   1,
    ACFG_DL_VLGRP_ADDVAP    =   2,
    ACFG_DL_VLGRP_DELVAP    =   3,
    ACFG_CMD_LAST           =   4
};


typedef struct  acfg_vlangrp_info {
    acfg_dl_cfg_hdr_t   dl_cfg_hdr;
    char                if_name[ACFG_MAX_IFNAME];
    char                vlan_id[ACFG_MAX_VIDNAME];
} acfg_vlangrp_info_t;


enum {
    ACFG_MAX_PSK_LEN = 65,
    ACFG_MAX_WEP_KEY_LEN = 256,
};

enum {
    ACFG_WPS_PIN_SET = 1,
    ACFG_WPS_PIN_RANDOM,
};

typedef enum {
    ACFG_WLAN_PROFILE_SEC_METH_OPEN,
    ACFG_WLAN_PROFILE_SEC_METH_SHARED,
    ACFG_WLAN_PROFILE_SEC_METH_AUTO,
    ACFG_WLAN_PROFILE_SEC_METH_WPA,
    ACFG_WLAN_PROFILE_SEC_METH_WPA2,
    ACFG_WLAN_PROFILE_SEC_METH_WPAWPA2,
    ACFG_WLAN_PROFILE_SEC_METH_WPA_EAP,
    ACFG_WLAN_PROFILE_SEC_METH_WPA2_EAP,
    ACFG_WLAN_PROFILE_SEC_METH_WPS,

    /* keep this last */
    ACFG_WLAN_PROFILE_SEC_METH_INVALID,
}SEC_TYPE;

typedef a_uint8_t acfg_wlan_profile_sec_meth_e ;

typedef enum {
    ACFG_WLAN_PROFILE_CIPHER_METH_INVALID = 0x00000000,
    ACFG_WLAN_PROFILE_CIPHER_METH_TKIP    = 0x00000001,
    ACFG_WLAN_PROFILE_CIPHER_METH_AES     = 0x00000002,
    ACFG_WLAN_PROFILE_CIPHER_METH_WEP     = 0x00000004,
    ACFG_WLAN_PROFILE_CIPHER_METH_NONE    = 0x00000008,
    ACFG_WLAN_PROFILE_CIPHER_METH_AES_CMAC  = 0x00000010,
} CIPHER_METH;

typedef a_uint8_t acfg_wlan_profile_cipher_meth_e ;

typedef enum {
    ACFG_EAP_TYPE_PEAP = 1,
    ACFG_EAP_TYPE_LEAP,
    ACFG_EAP_TYPE_TLS,
} EAP_TYPE;

#define ACFG_WLAN_PROFILE_VLAN_INVALID 0xFFFFFFFF

#define EAP_IDENTITY_LEN 128
#define EAP_PASSWD_LEN 128
#define EAP_FILE_NAME_LEN 512
#define EAP_PVT_KEY_PASSWD_LEN 128
#define IP_ADDR_LEN 16
#define RADIUS_SHARED_SECRET_LEN 128
#define ACCT_SHARED_SECRET_LEN 128

typedef struct {
    a_uint8_t eap_type;
    a_uint8_t identity[EAP_IDENTITY_LEN];
    a_uint8_t password[EAP_PASSWD_LEN];
    a_uint8_t ca_cert[EAP_FILE_NAME_LEN];
    a_uint8_t client_cert[EAP_FILE_NAME_LEN];
    a_uint8_t private_key[EAP_FILE_NAME_LEN];
    a_uint8_t private_key_passwd[EAP_PVT_KEY_PASSWD_LEN];
} acfg_wlan_profile_sec_eap_params_t;

typedef struct  {
    a_char_t radius_ip[IP_ADDR_LEN];
    a_uint32_t radius_port;
    a_char_t shared_secret[RADIUS_SHARED_SECRET_LEN];
} acfg_wlan_profile_sec_radius_params_t;

typedef struct  {
    a_char_t acct_ip[IP_ADDR_LEN];
    a_uint32_t acct_port;
    a_char_t shared_secret[ACCT_SHARED_SECRET_LEN];
} acfg_wlan_profile_sec_acct_server_params_t;

#define HS_MAX_ROAMING_CONSORTIUM_LEN    16
#define HS_MAX_VENUE_NAME_LEN            256
#define HS_MAX_AUTH_TYPE_LEN             1024
#define HS_MAX_IPADDR_TYPE_AVL_LEN       3
#define HS_MAX_NAI_REALM_LIST_NUM        10
#define HS_MAX_NAI_REALM_DATA_LEN        512
#define HS_MAX_3GPP_CELLULAR_NETWORK_LEN 255
#define HS_MAX_DOMAIN_NAME_LIST_LEN      (255 * 4)
#define HS_MAX_WAN_METRICS_LEN           128
#define HS_MAX_CONNECTION_CAP_LEN        255
#define HS_MAX_OPERATING_CLASS_LEN       255

typedef enum {
    PRIVATE_NETWORK,
    PRIVATE_NETWORK_WITH_GUEST_ACCESS,
    CHARGEABLE_PUBLIC_NETWORK,
    FREE_PUBLIC_NETWORK,
    PERSONAL_DEVICE_NETWORK,
    EMERGENCY_SERVICES_ONLY_NETWORK,
    RESERVED_START_NETWORK = 6,
    RESERVED_END_NETWORK = 13,
    TEST_OR_EXPERIMENTAL_NETWORK,
    WILDCARD_NETWORK,
    DEFAULT_NETWORK_TYPE = CHARGEABLE_PUBLIC_NETWORK,
} IW_NETWORK_TYPE;

typedef enum {
    INTERNET_ACCESS_UNSPECIFIED,
    INTERNET_ACCESS_AVAILABLE,
    DEFAULT_INTERNET = INTERNET_ACCESS_UNSPECIFIED,
} IW_INTERNET;

typedef enum {
    NO_ADDITIONAL_STEP_REQUIRED_RSNA_ENABLED,
    ADDITIONAL_STEP_REQUIRED,
    DEFAULT_ASRA = NO_ADDITIONAL_STEP_REQUIRED_RSNA_ENABLED,
} IW_ASRA;

typedef enum {
    EMERGENCY_SERVICES_UNSPECIFIED,
    EMERGENCY_SERVICES_REACHABLE,
    DEFAULT_ESR = EMERGENCY_SERVICES_UNSPECIFIED,
} IW_ESR;

typedef enum {
    NO_UNAUTHENTICATED_EMERGENCY_SERVICES_REACHABLE,
    UNAUTHENTICATED_EMERGENCY_SERVICES_REACHABLE,
    DEFAULT_UESA = NO_UNAUTHENTICATED_EMERGENCY_SERVICES_REACHABLE,
} IW_UESA;

typedef enum {
    VENUE_GROUP_UNSPECIFIED,
    VENUE_GROUP_ASSEMBLY,
    VENUE_GROUP_BUSINESS,
    VENUE_GROUP_EDUCATIONAL,
    VENUE_GROUP_FACTORY_INDUSTRIAL,
    VENUE_GROUP_INSTITUTIONAL,
    VENUE_GROUP_MERCANTILE,
    VENUE_GROUP_RESIDENTIAL,
    VENUE_GROUP_STORAGE,
    VENUE_GROUP_UTILITY_MISC,
    VENUE_GROUP_VEHICULAR,
    VENUE_GROUP_OUTDOOR,
    VENUE_GROUP_RESERVED_START = 12,
    VENUE_GROUP_RESERVED_END = 255,
    DEFAULT_VENUE_GROUP = VENUE_GROUP_BUSINESS,
} IW_VENUE_GROUP;

#define DEFAULT_VENUE_TYPE 8 //Research and Development facility

typedef struct {
    a_uint8_t hs_enabled;
    a_uint8_t iw_enabled;
    a_uint8_t network_type;
    a_uint8_t internet;
    a_uint8_t asra;
    a_uint8_t esr;
    a_uint8_t uesa;
    a_uint8_t venue_group;
    a_uint8_t venue_type;
    a_char_t hessid[ACFG_MACSTR_LEN];
    a_uint8_t roaming_consortium[HS_MAX_ROAMING_CONSORTIUM_LEN];
    a_uint8_t roaming_consortium2[HS_MAX_ROAMING_CONSORTIUM_LEN];
    a_char_t venue_name[HS_MAX_VENUE_NAME_LEN];
    a_uint8_t manage_p2p;
    a_uint8_t disable_dgaf;
    a_uint8_t hs20_venue_name[HS_MAX_VENUE_NAME_LEN];
    a_uint8_t hs20_network_auth_type[HS_MAX_AUTH_TYPE_LEN];
    a_uint8_t hs20_ipaddr_type_availability[HS_MAX_IPADDR_TYPE_AVL_LEN];
    a_uint8_t hs20_nai_realm_list[HS_MAX_NAI_REALM_LIST_NUM][HS_MAX_NAI_REALM_DATA_LEN];
    a_uint8_t hs20_3gpp_cellular_network[HS_MAX_3GPP_CELLULAR_NETWORK_LEN];
    a_uint8_t hs20_domain_name_list[HS_MAX_DOMAIN_NAME_LIST_LEN];
    a_uint8_t hs20_operator_friendly_name[HS_MAX_VENUE_NAME_LEN];
    a_uint8_t hs20_wan_metrics[HS_MAX_WAN_METRICS_LEN];
    a_uint8_t hs20_connection_capability[HS_MAX_CONNECTION_CAP_LEN];
    a_uint8_t hs20_operating_class[HS_MAX_OPERATING_CLASS_LEN];
}acfg_wlan_profile_sec_hs_iw_param_t;

typedef enum {
    ACFG_WLAN_PROFILE_NODE_ACL_OPEN   = 0,   /* set policy: no ACL's */
    ACFG_WLAN_PROFILE_NODE_ACL_ALLOW  = 1,
    ACFG_WLAN_PROFILE_NODE_ACL_DENY   = 2,
    ACFG_WLAN_PROFILE_NODE_ACL_FLUSH  = 3,   /* flush ACL database, policy will be active */
    ACFG_WLAN_PROFILE_NODE_ACL_DETACH = 4,   /* detach ACL policy */
    ACFG_WLAN_PROFILE_NODE_ACL_RADIUS = 5,   /* set policy: RADIUS managed ACLs */

    /* keep this last */
    ACFG_WLAN_PROFILE_NODE_ACL_INVALID
} ACL_POLICY;

typedef a_uint32_t acfg_wlan_profile_node_acl_t ;

typedef enum {
    WPS_FLAG_DISABLED           = 0,
    WPS_FLAG_UNCONFIGURED       = 1,
    WPS_FLAG_CONFIGURED         = 2,
} WPS_FLAGS;

typedef enum {
    ACFG_FLAG_INVALID = 0,
    ACFG_FLAG_VAP_IND = 1,
    ACFG_FLAG_EXTAP   = 2,
} WDS_FLAGS;

typedef struct {
    a_uint8_t enabled;
    a_uint8_t wds_addr[ACFG_MACSTR_LEN];
    a_uint32_t wds_flags;
} acfg_wds_params_t;

typedef struct {
    a_uint8_t radio_name[ACFG_MAX_IFNAME]; /* key */
    a_uint8_t chan; /* read-write, mandatory */
    a_uint32_t freq; /* in Mhz read-write, mandatory */
    a_uint16_t country_code; /*read-write, optional; 0 if unspecified */
    a_uint8_t radio_mac[ACFG_MACSTR_LEN];
    /* read-write, optional; 0 if unspecified */
    a_uint8_t macreq_enabled; /* read-write, optoinal, 0 if unspecified */
    a_uint8_t ampdu;
    a_uint32_t ampdu_limit_bytes;
    a_uint8_t ampdu_subframes;
    a_uint8_t  aggr_burst; /* 0 if unspecified */
    a_uint32_t aggr_burst_dur; /* 0 if unspecified */
    a_uint8_t  ext_icm; /* 0 if unspecified */
} acfg_wlan_profile_radio_params_t;

typedef struct {
    acfg_wlan_profile_sec_meth_e sec_method;  /* read-write, mandatory */
    acfg_wlan_profile_cipher_meth_e cipher_method; /* read-write, mandatory*/
    acfg_wlan_profile_cipher_meth_e g_cipher_method; /* read-write, mandatory*/
    a_char_t psk[ACFG_MAX_PSK_LEN];
    /* read-write, mandatory if sec_method = WPA/WPA2/WPS, 0 otherwise */
    a_char_t wep_key0[ACFG_MAX_WEP_KEY_LEN];
    /* read-write, mandatory if sec_method = WEP, 0 otherwise */
    a_char_t wep_key1[ACFG_MAX_WEP_KEY_LEN];
    /* read-write, optional, 0 if unspecified */
    a_char_t wep_key2[ACFG_MAX_WEP_KEY_LEN];
    /* read-write, optional, 0 if unspecified */
    a_char_t wep_key3[ACFG_MAX_WEP_KEY_LEN];
    /* read-write, optional, 0 if unspecified */
    a_uint8_t wep_key_defidx;
    a_uint32_t wps_pin;  /* write-only, 0 if unspecified */
    a_uint8_t  wps_flag;
    a_char_t  wps_manufacturer[ACFG_WSUPP_PARAM_LEN];
    a_char_t  wps_model_name[ACFG_WSUPP_PARAM_LEN];
    a_char_t  wps_model_number[ACFG_WSUPP_PARAM_LEN];
    a_char_t  wps_serial_number[ACFG_WSUPP_PARAM_LEN];
    a_char_t  wps_device_type[ACFG_WSUPP_PARAM_LEN];
    a_char_t  wps_config_methods[ACFG_WPS_CONFIG_METHODS_LEN];
    a_char_t  wps_upnp_iface[ACFG_MAX_IFNAME];
    a_uint8_t  wps_friendly_name[ACFG_WSUPP_PARAM_LEN];
    a_uint8_t  wps_man_url[ACFG_WSUPP_PARAM_LEN];
    a_uint8_t  wps_model_desc[ACFG_WSUPP_PARAM_LEN];
    a_uint8_t  wps_upc[ACFG_WSUPP_PARAM_LEN];
    a_uint32_t wps_pbc_in_m1;
    a_char_t wps_device_name[ACFG_WSUPP_PARAM_LEN];
    acfg_wlan_profile_sec_eap_params_t eap_param;
    a_uint32_t radius_retry_primary_interval;
    acfg_wlan_profile_sec_radius_params_t pri_radius_param;
    acfg_wlan_profile_sec_radius_params_t sec1_radius_param;
    acfg_wlan_profile_sec_radius_params_t sec2_radius_param;
    acfg_wlan_profile_sec_acct_server_params_t pri_acct_server_param;
    acfg_wlan_profile_sec_acct_server_params_t sec1_acct_server_param;
    acfg_wlan_profile_sec_acct_server_params_t sec2_acct_server_param;
    acfg_wlan_profile_sec_hs_iw_param_t hs_iw_param;
    /* Might be "a", "b", "g", or "ag" + \0 */
    a_char_t  wps_rf_bands[ACFG_WPS_RF_BANDS_LEN];
} acfg_wlan_profile_security_params_t;

typedef struct {
    a_uint8_t  acfg_acl_node_list[ACFG_MAX_ACL_NODE][ACFG_MACADDR_LEN];
    a_uint8_t  num_node;
    /*key*//* read-write, optional, 0 if unspecified */
    acfg_wlan_profile_node_acl_t node_acl;
    /* read-write, mandatory if node_mac specified */
} acfg_wlan_profile_node_params_t;

#define ACFG_VENDOR_PARAM_NAME_LEN 32

/* vendor param name/type/len are not known */
typedef struct {
    acfg_vendor_param_vap_t cmd;
    a_uint32_t type;
    a_uint32_t len;
    acfg_vendor_param_data_t data; 
} acfg_wlan_profile_vendor_param_t;

/* vendors need to create this table */
typedef struct {
    a_uint8_t name[ACFG_VENDOR_PARAM_NAME_LEN];
    acfg_vendor_param_vap_t cmd;
}acfg_vendor_param_cmd_map_t;

typedef struct {
    a_char_t atf_percent[ACFG_MAX_PERCENT_SIZE];
    a_char_t atf_stalist[ACFG_MAX_ATF_STALIST_SIZE];
} acfg_atf_params_t;

typedef struct {
    a_uint8_t vap_name[ACFG_MAX_IFNAME]; /* key */
    a_char_t radio_name[ACFG_MAX_IFNAME]; /* key */
    acfg_opmode_t opmode; /* read-write, mandatory */
    a_int32_t      vapid;  /* for MAC addr request */
    acfg_phymode_t phymode; /* read-write, mandatory */
    a_uint8_t      ampdu;
    a_char_t ssid[ACFG_MAX_SSID_LEN + 1]; /* read-write, mandatory */
    a_uint32_t bitrate; /* read-write, mandatory*/
    a_uint8_t rate[16]; /* read-write, mandatory*/
    a_uint32_t retries;
    acfg_txpow_t txpow; /* read-write mandatory */
    acfg_rssi_t rssi; /* read-only */
    a_uint32_t beacon_interval; /* read-write, optional; 0 if unspecified */
    acfg_rts_t rts_thresh; /* read-write, optional; 0 if unspecified */
    acfg_frag_t frag_thresh; /* read-write, optional; 0 if unspecified */
    a_uint8_t vap_mac[ACFG_MACSTR_LEN];
    acfg_wlan_profile_security_params_t security_params;
    acfg_wlan_profile_node_params_t node_params;
    acfg_wds_params_t wds_params;
    a_uint32_t vlanid;
    a_char_t bridge[ACFG_MAX_IFNAME];
    acfg_wlan_profile_vendor_param_t vendor_param[ACFG_MAX_VENDOR_PARAMS];
    a_uint8_t num_vendor_params;
    /* read-write, optional; 0 if unspecified */
    a_uint8_t num_nai_realm_data;
    a_uint32_t pureg;
    a_uint32_t puren;
    a_uint32_t hide_ssid;
    a_uint32_t doth;
    a_uint32_t client_isolation;
    a_uint8_t coext;
    a_uint32_t uapsd;
    a_uint8_t  shortgi;
    a_uint32_t amsdu; /* 0 if unspecified */
    a_uint32_t max_clients; /* 0 if unspecified */
    acfg_atf_params_t atf;
} acfg_wlan_profile_vap_params_t;

typedef struct {
    char ctrl_hapd[ACFG_CTRL_IFACE_LEN];
    char ctrl_wpasupp[ACFG_CTRL_IFACE_LEN];
    acfg_wlan_profile_radio_params_t radio_params;
    acfg_wlan_profile_vap_params_t vap_params[ACFG_MAX_VAPS];
    a_uint8_t num_vaps;
    void *priv; /* acfg library internal */
} acfg_wlan_profile_t;

typedef struct {
    a_uint8_t  wps_state;
} acfg_hapd_param_t;

enum acfg_event_handler_type {
    ACFG_EVENT_WPS_NEW_AP_SETTINGS = 1,
    ACFG_EVENT_WPS_SUCCESS,
};

enum acfg_band_type {
    ACFG_BAND_2GHZ = 1,
    ACFG_BAND_5GHZ,
};

enum acfg_chainmask_type {
    ACFG_TX_CHAINMASK = 1,
    ACFG_RX_CHAINMASK,
};

enum acfg_frame_type {
    ACFG_FRAME_BEACON = 1,
    ACFG_FRAME_PROBE_RESP,
    ACFG_FRAME_PROBE_REQ,
    ACFG_FRAME_ASSOC_RESP,
    ACFG_FRAME_ASSOC_REQ,
    ACFG_FRAME_WNM,
    ACFG_FRAME_AUTH,
};

typedef struct {
    a_uint8_t vap_name[ACFG_MAX_IFNAME];
    a_uint8_t vap_mac[ACFG_MACADDR_LEN];
    acfg_phymode_t phymode;
    a_uint8_t sec_method;
    a_uint8_t   cipher;
    a_uint8_t wep_key[ACFG_MAX_PSK_LEN];
    a_uint8_t wep_key_len;
    a_uint8_t wep_key_idx;
    a_uint8_t wds_enabled;
    a_uint8_t wds_addr[ACFG_MACSTR_LEN];
    a_uint32_t wds_flags;
} acfg_wlan_profile_vap_info_t;

typedef struct acfg_radio_vap_info {
    a_uint8_t radio_name[ACFG_MAX_IFNAME];
    a_uint8_t chan;
    a_uint32_t freq;
    a_uint16_t country_code;
    a_uint8_t radio_mac[ACFG_MACADDR_LEN];
    acfg_wlan_profile_vap_info_t vap_info[ACFG_MAX_VAPS];
    a_uint8_t num_vaps;
    a_uint8_t ampdu;
    a_uint32_t ampdu_limit_bytes;
    a_uint8_t ampdu_subframes;
} acfg_radio_vap_info_t;

typedef struct acfg_ath_stats_11n {
    a_uint32_t    ast_watchdog;
    a_uint32_t    ast_resetOnError;
    a_uint32_t    ast_mat_ucast_encrypted;
    a_uint32_t    ast_mat_rx_recrypt;
    a_uint32_t    ast_mat_rx_decrypt;
    a_uint32_t    ast_mat_key_switch;
    a_uint32_t    ast_hardware;
    a_uint32_t    ast_bmiss;
    a_uint32_t    ast_rxorn;
    a_uint32_t    ast_rxorn_bmiss;
    a_uint32_t    ast_rxeol;
    a_uint32_t    ast_txurn;
    a_uint32_t    ast_txto;
    a_uint32_t    ast_cst;
    a_uint32_t    ast_mib;
    a_uint32_t    ast_rx;
    a_uint32_t    ast_rxdesc;
    a_uint32_t    ast_rxerr;
    a_uint32_t    ast_rxnofrm;
    a_uint32_t    ast_tx;
    a_uint32_t    ast_txdesc;
    a_uint32_t    ast_tim_timer;
    a_uint32_t    ast_bbevent;
    a_uint32_t    ast_rxphy;
    a_uint32_t    ast_rxkcm;
    a_uint32_t    ast_swba;
    a_uint32_t    ast_brssi;
    a_uint32_t    ast_bnr;
    a_uint32_t    ast_tim;
    a_uint32_t    ast_dtim;
    a_uint32_t    ast_dtimsync;
    a_uint32_t    ast_gpio;
    a_uint32_t    ast_cabend;
    a_uint32_t    ast_tsfoor;
    a_uint32_t    ast_gentimer;
    a_uint32_t    ast_gtt;
    a_uint32_t    ast_fatal;
    a_uint32_t    ast_tx_packets;
    a_uint32_t    ast_rx_packets;
    a_uint32_t    ast_tx_mgmt;
    a_uint32_t    ast_tx_discard;
    a_uint32_t    ast_tx_invalid;
    a_uint32_t    ast_tx_qstop;
    a_uint32_t    ast_tx_encap;
    a_uint32_t    ast_tx_nonode;
    a_uint32_t    ast_tx_nobuf;
    a_uint32_t    ast_tx_stop;
    a_uint32_t    ast_tx_resume;
    a_uint32_t    ast_tx_nobufmgt;
    a_uint32_t    ast_tx_xretries;
    a_uint64_t    ast_tx_hw_retries;
    a_uint64_t    ast_tx_hw_success;
    a_uint32_t    ast_tx_fifoerr;
    a_uint32_t    ast_tx_filtered;
    a_uint32_t    ast_tx_badrate;
    a_uint32_t    ast_tx_noack;
    a_uint32_t    ast_tx_cts;
    a_uint32_t    ast_tx_shortpre;
    a_uint32_t    ast_tx_altrate;
    a_uint32_t    ast_tx_protect;
    a_uint32_t    ast_rx_orn;
    a_uint32_t    ast_rx_badcrypt;
    a_uint32_t    ast_rx_badmic;
    a_uint32_t    ast_rx_nobuf;
    a_uint32_t    ast_rx_swdecrypt;
    a_uint32_t    ast_rx_hal_in_progress;
    a_uint32_t    ast_rx_num_data;
    a_uint32_t    ast_rx_num_mgmt;
    a_uint32_t    ast_rx_num_ctl;
    a_uint32_t    ast_rx_num_unknown;
    a_uint32_t    ast_max_pkts_per_intr;
    a_uint32_t    ast_pkts_per_intr[ACFG_MAX_INTR_BKT+1];
    a_int8_t      ast_tx_rssi;
    a_int8_t      ast_tx_rssi_ctl0;
    a_int8_t      ast_tx_rssi_ctl1;
    a_int8_t      ast_tx_rssi_ctl2;
    a_int8_t      ast_tx_rssi_ext0;
    a_int8_t      ast_tx_rssi_ext1;
    a_int8_t      ast_tx_rssi_ext2;
    a_int8_t      ast_rx_rssi;
    a_int8_t      ast_rx_rssi_ctl0;
    a_int8_t      ast_rx_rssi_ctl1;
    a_int8_t      ast_rx_rssi_ctl2;
    a_int8_t      ast_rx_rssi_ext0;
    a_int8_t      ast_rx_rssi_ext1;
    a_int8_t      ast_rx_rssi_ext2;
    a_uint32_t    ast_be_xmit;
    a_uint32_t    ast_be_nobuf;
    a_uint32_t    ast_per_cal;
    a_uint32_t    ast_per_calfail;
    a_uint32_t    ast_per_rfgain;
    a_uint32_t    ast_rate_calls;
    a_uint32_t    ast_rate_raise;
    a_uint32_t    ast_rate_drop;
    a_uint32_t    ast_ant_defswitch;
    a_uint32_t    ast_ant_txswitch;
    a_uint32_t    ast_ant_rx[8];
    a_uint32_t    ast_ant_tx[8];
    a_uint64_t    ast_rx_bytes;
    a_uint64_t    ast_tx_bytes;
    a_uint32_t    ast_rx_num_qos_data[16];
    a_uint32_t    ast_rx_num_nonqos_data;
    a_uint32_t    ast_txq_packets[16];
    a_uint32_t    ast_txq_xretries[16];
    a_uint32_t    ast_txq_fifoerr[16];
    a_uint32_t    ast_txq_filtered[16];
    a_uint32_t    ast_txq_athbuf_limit[16];
    a_uint32_t    ast_txq_nobuf[16];
    a_uint8_t     ast_num_rxchain;
    a_uint8_t     ast_num_txchain;
    struct {
        a_uint32_t   tx_pkts;
        a_uint32_t   tx_checks;
        a_uint32_t   tx_drops;
        a_uint32_t   tx_minqdepth;
        a_uint32_t   tx_queue;
        a_uint32_t   tx_resetq;
        a_uint32_t   tx_comps;
        a_uint32_t   tx_comperror;
        a_uint32_t   tx_unaggr_comperror;
        a_uint32_t   tx_stopfiltered;
        a_uint32_t   tx_qnull;
        a_uint32_t   tx_noskbs;
        a_uint32_t   tx_nobufs;
        a_uint32_t   tx_badsetups;
        a_uint32_t   tx_normnobufs;
        a_uint32_t   tx_schednone;
        a_uint32_t   tx_bars;
        a_uint32_t   tx_legacy;
        a_uint32_t   txunaggr_single;
        a_uint32_t   txbar_xretry;
        a_uint32_t   txbar_compretries;
        a_uint32_t   txbar_errlast;
        a_uint32_t   tx_compunaggr;
        a_uint32_t   txunaggr_xretry;
        a_uint32_t   tx_compaggr;
        a_uint32_t   tx_bawadv;
        a_uint32_t   tx_bawretries;
        a_uint32_t   tx_bawnorm;
        a_uint32_t   tx_bawupdates;
        a_uint32_t   tx_bawupdtadv;
        a_uint32_t   tx_retries;
        a_uint32_t   tx_xretries;
        a_uint32_t   tx_aggregates;
        a_uint32_t   tx_sf_hw_xretries;
        a_uint32_t   tx_aggr_frames;
        a_uint32_t   txaggr_noskbs;
        a_uint32_t   txaggr_nobufs;
        a_uint32_t   txaggr_badkeys;
        a_uint32_t   txaggr_schedwindow;
        a_uint32_t   txaggr_single;
        a_uint32_t   txaggr_mimo;
        a_uint32_t   txaggr_compgood;
        a_uint32_t   txaggr_comperror;
        a_uint32_t   txaggr_compxretry;
        a_uint32_t   txaggr_compretries;
        a_uint32_t   txunaggr_compretries;
        a_uint32_t   txaggr_prepends;
        a_uint32_t   txaggr_filtered;
        a_uint32_t   txaggr_fifo;
        a_uint32_t   txaggr_xtxop;
        a_uint32_t   txaggr_desc_cfgerr;
        a_uint32_t   txaggr_data_urun;
        a_uint32_t   txaggr_delim_urun;
        a_uint32_t   txaggr_errlast;
        a_uint32_t   txunaggr_errlast;
        a_uint32_t   txaggr_longretries;
        a_uint32_t   txaggr_shortretries;
        a_uint32_t   txaggr_timer_exp;
        a_uint32_t   txaggr_babug;
        a_uint32_t   txrifs_single;
        a_uint32_t   txrifs_babug;
        a_uint32_t   txaggr_badtid;
        a_uint32_t   txrifs_compretries;
        a_uint32_t   txrifs_bar_alloc;
        a_uint32_t   txrifs_bar_freed;
        a_uint32_t   txrifs_compgood;
        a_uint32_t   txrifs_prepends;
        a_uint32_t   tx_comprifs;
        a_uint32_t   tx_compnorifs;
        a_uint32_t   rx_pkts;
        a_uint32_t   rx_aggr;
        a_uint32_t   rx_aggrbadver;
        a_uint32_t   rx_bars;
        a_uint32_t   rx_nonqos;
        a_uint32_t   rx_seqreset;
        a_uint32_t   rx_oldseq;
        a_uint32_t   rx_bareset;
        a_uint32_t   rx_baresetpkts;
        a_uint32_t   rx_dup;
        a_uint32_t   rx_baadvance;
        a_uint32_t   rx_recvcomp;
        a_uint32_t   rx_bardiscard;
        a_uint32_t   rx_barcomps;
        a_uint32_t   rx_barrecvs;
        a_uint32_t   rx_skipped;
        a_uint32_t   rx_comp_to;
        a_uint32_t   rx_timer_starts;
        a_uint32_t   rx_timer_stops;
        a_uint32_t   rx_timer_run;
        a_uint32_t   rx_timer_more;
        a_uint32_t   wd_tx_active;
        a_uint32_t   wd_tx_inactive;
        a_uint32_t   wd_tx_hung;
        a_uint32_t   wd_spurious;
        a_uint32_t   tx_requeue;
        a_uint32_t   tx_drain_txq;
        a_uint32_t   tx_drain_tid;
        a_uint32_t   tx_cleanup_tid;
        a_uint32_t   tx_drain_bufs;
        a_uint32_t   tx_tidpaused;
        a_uint32_t   tx_tidresumed;
        a_uint32_t   tx_unaggr_filtered;
        a_uint32_t   tx_aggr_filtered;
        a_uint32_t   tx_filtered;
        a_uint32_t   rx_rb_on;
        a_uint32_t   rx_rb_off;
        a_uint32_t   rx_dsstat_err;
#ifdef ATH_SUPPORT_TxBF
        a_uint32_t   bf_stream_miss;
        a_uint32_t   bf_bandwidth_miss;
        a_uint32_t   bf_destination_miss;
#endif
    } ast_11n_stats;
    struct {
        a_uint32_t           dfs_stats_valid;
        a_uint32_t           event_count;
        a_uint32_t           chirp_count;
        a_uint32_t           num_filter;
        struct {
            a_uint32_t       max_pri_count;
            a_uint32_t       max_used_pri;
            a_uint32_t       excess_pri;
            a_uint32_t       pri_threshold_reached;
            a_uint32_t       dur_threshold_reached;
            a_uint32_t       rssi_threshold_reached;
            a_uint32_t       filter_id;
        } fstat[ACFG_MAX_DFS_FILTER];
    } ast_dfs_stats;
    a_uint32_t   ast_bb_hang;
    a_uint32_t   ast_mac_hang;
#if ATH_WOW
    a_uint32_t   ast_wow_wakeups;
    a_uint32_t   ast_wow_wakeupsok;
    a_uint32_t   ast_wow_wakeupserror;
#if ATH_WOW_DEBUG
    a_uint32_t   ast_normal_sleeps;
    a_uint32_t   ast_normal_wakeups;
    a_uint32_t   ast_wow_sleeps;
    a_uint32_t   ast_wow_sleeps_nonet;
#endif
#endif
#ifdef ATH_SUPPORT_UAPSD
    a_uint32_t   ast_uapsdqnulbf_unavail;
    a_uint32_t   ast_uapsdqnul_pkts;
    a_uint32_t   ast_uapsdtriggers;
    a_uint32_t   ast_uapsdnodeinvalid;
    a_uint32_t   ast_uapsdeospdata;
    a_uint32_t   ast_uapsddata_pkts;
    a_uint32_t   ast_uapsddatacomp;
    a_uint32_t   ast_uapsdqnulcomp;
    a_uint32_t   ast_uapsddataqueued;
    a_uint32_t   ast_uapsdedmafifofull;
#endif
#if ATH_SUPPORT_VOWEXT
    a_uint32_t   ast_vow_ul_tx_calls[4];
    a_uint32_t   ast_vow_ath_txq_calls[4];
    a_uint32_t   ast_vow_ath_be_drop, ast_vow_ath_bk_drop;
#endif
#if ATH_SUPPORT_CFEND
    a_uint32_t   ast_cfend_sched;
    a_uint32_t   ast_cfend_sent;
#endif
#ifdef VOW_LOGLATENCY
    a_uint32_t   ast_retry_delay[ACFG_LATENCY_CATS][ACFG_LATENCY_BINS];
    a_uint32_t   ast_queue_delay[ACFG_LATENCY_CATS][ACFG_LATENCY_BINS];
#endif
#if UMAC_SUPPORT_VI_DBG
    a_uint32_t   vi_timestamp[ACFG_VI_LOG_LEN];
    a_uint8_t    vi_rssi_ctl0[ACFG_VI_LOG_LEN];
    a_uint8_t    vi_rssi_ctl1[ACFG_VI_LOG_LEN];
    a_uint8_t    vi_rssi_ctl2[ACFG_VI_LOG_LEN];
    a_uint8_t    vi_rssi_ext0[ACFG_VI_LOG_LEN];
    a_uint8_t    vi_rssi_ext1[ACFG_VI_LOG_LEN];
    a_uint8_t    vi_rssi_ext2[ACFG_VI_LOG_LEN];
    a_uint8_t    vi_rssi[ACFG_VI_LOG_LEN];
    a_uint8_t    vi_evm0[ACFG_VI_LOG_LEN];
    a_uint8_t    vi_evm1[ACFG_VI_LOG_LEN];
    a_uint8_t    vi_evm2[ACFG_VI_LOG_LEN];
    a_uint8_t    vi_rs_rate[ACFG_VI_LOG_LEN];
    a_uint32_t   vi_tx_frame_cnt[ACFG_VI_LOG_LEN];
    a_uint32_t   vi_rx_frame_cnt[ACFG_VI_LOG_LEN];
    a_uint32_t   vi_rx_clr_cnt[ACFG_VI_LOG_LEN];
    a_uint32_t   vi_rx_ext_clr_cnt[ACFG_VI_LOG_LEN];
    a_uint32_t   vi_cycle_cnt[ACFG_VI_LOG_LEN];
    a_uint8_t    vi_stats_index;
#endif
#ifdef ATH_SUPPORT_TxBF
    a_uint8_t    ast_txbf;
    a_uint8_t    ast_lastratecode;
    a_uint32_t   ast_sounding_count;
    a_uint32_t   ast_txbf_rpt_count;
    a_uint32_t   ast_mcs_count[ACFG_MCS_RATES+1];
#endif
#if ATH_RX_LOOPLIMIT_TIMER
    a_uint32_t   ast_rx_looplimit_start;
    a_uint32_t   ast_rx_looplimit_end;
#endif
    a_uint32_t   ast_chan_clr_cnt;
    a_uint32_t   ast_cycle_cnt;
    a_int16_t    ast_noise_floor;
    struct {
        a_uint32_t   ast_ackrcv_bad;
        a_uint32_t   ast_rts_bad;
        a_uint32_t   ast_rts_good;
        a_uint32_t   ast_fcs_bad;
        a_uint32_t   ast_beacons;
#ifdef ATH_SUPPORT_HTC
        struct {
            a_uint32_t   tx_shortretry;
            a_uint32_t   tx_longretry;
            a_uint32_t   tx_xretries;
            a_uint32_t   ht_tx_unaggr_xretry;
            a_uint32_t   ht_tx_xretries;
            a_uint32_t   tx_pkt;
            a_uint32_t   tx_aggr;
            a_uint32_t   tx_retry;
            a_uint32_t   txaggr_retry;
            a_uint32_t   txaggr_sub_retry;
        } ast_tgt_stats;
#endif
    } ast_mib_stats;
    struct {
        int        valid;
        a_uint32_t status;
        a_uint32_t tsf;
        a_uint32_t phy_panic_wd_ctl1;
        a_uint32_t phy_panic_wd_ctl2;
        a_uint32_t phy_gen_ctrl;
        a_uint32_t rxc_pcnt;
        a_uint32_t rxf_pcnt;
        a_uint32_t txf_pcnt;
        a_uint32_t cycles;
        a_uint32_t wd;
        a_uint32_t det;
        a_uint32_t rdar;
        a_uint32_t r_odfm;
        a_uint32_t r_cck;
        a_uint32_t t_odfm;
        a_uint32_t t_cck;
        a_uint32_t agc;
        a_uint32_t src;
    } ast_bb_panic[ACFG_MAX_BB_PANICS];
} acfg_ath_stats_11n_t;

typedef struct acfg_txrx_elem {
#ifndef BIG_ENDIAN_HOST 
    a_uint64_t      pkts;
    a_uint64_t      bytes;
#else
    a_uint32_t      pkts;
    a_uint32_t      bytes;
#endif
} acfg_txrx_elem_t;

typedef struct acfg_txrx_stats {
    struct {
        acfg_txrx_elem_t      from_stack;
        acfg_txrx_elem_t      delivered;
        struct {
            acfg_txrx_elem_t  host_reject;
            acfg_txrx_elem_t  download_fail;
            acfg_txrx_elem_t  target_discard;
            acfg_txrx_elem_t  no_ack;
        } dropped;
        a_uint32_t            desc_in_use;
        a_uint32_t            desc_alloc_fails;
        a_uint32_t            ce_ring_full;
        a_uint32_t            dma_map_error;
        acfg_txrx_elem_t      mgmt;
    } tx;
    struct {
        acfg_txrx_elem_t      delivered;
        acfg_txrx_elem_t      forwarded;
    } rx;
} acfg_txrx_stats_t;

typedef struct acfg_ath_stats_11ac {
    int                       txrx_stats_level;
    acfg_txrx_stats_t         txrx_stats;
    struct {
        struct {
            a_int32_t         comp_queued;
            a_int32_t         comp_delivered;
            a_int32_t         msdu_enqued;
            a_int32_t         mpdu_enqued;
            a_int32_t         wmm_drop;
            a_int32_t         local_enqued;
            a_int32_t         local_freed;
            a_int32_t         hw_queued;
            a_int32_t         hw_reaped;
            a_int32_t         underrun;
            a_int32_t         tx_abort;
            a_int32_t         mpdus_requed;
            a_uint32_t        tx_xretry;
            a_uint32_t        data_rc;
            a_uint32_t        self_triggers;
            a_uint32_t        sw_retry_failure;
            a_uint32_t        illgl_rate_phy_err;
            a_uint32_t        pdev_cont_xretry;
            a_uint32_t        pdev_tx_timeout;
            a_uint32_t        pdev_resets;
            a_uint32_t        stateless_tid_alloc_failure;
            a_uint32_t        phy_underrun;
            a_uint32_t        txop_ovf;
        } tx;
        struct {
            a_int32_t         mid_ppdu_route_change;
            a_int32_t         status_rcvd;
            a_int32_t         r0_frags;
            a_int32_t         r1_frags;
            a_int32_t         r2_frags;
            a_int32_t         r3_frags;
            a_int32_t         htt_msdus;
            a_int32_t         htt_mpdus;
            a_int32_t         loc_msdus;
            a_int32_t         loc_mpdus;
            a_int32_t         oversize_amsdu;
            a_int32_t         phy_errs;
            a_int32_t         phy_err_drop;
            a_int32_t         mpdu_errs;
        } rx;
        struct {
            a_uint32_t        dram_free_size;
            a_uint32_t        iram_free_size;
        } mem;
        struct {
            a_int32_t         dummy;
        } peer;
    } stats;
    struct {
        a_uint64_t    tx_beacon;
        a_uint32_t    be_nobuf;
        a_uint32_t    tx_buf_count; 
        a_uint32_t    tx_packets;
        a_uint32_t    rx_packets;
        a_int32_t     tx_mgmt;
        a_uint32_t    tx_num_data;
        a_uint32_t    rx_num_data;
        a_int32_t     rx_mgmt;
        a_uint32_t    rx_num_mgmt;
        a_uint32_t    rx_num_ctl;
        a_uint32_t    tx_rssi;
        a_uint32_t    tx_mcs[10];
        a_uint32_t    rx_mcs[10];
        a_uint32_t    rx_rssi_comb;
        struct {
            a_uint8_t     rx_rssi_pri20;
            a_uint8_t     rx_rssi_sec20;
            a_uint8_t     rx_rssi_sec40;
            a_uint8_t     rx_rssi_sec80;
        } rx_rssi_chain0;
        struct {
            a_uint8_t     rx_rssi_pri20;
            a_uint8_t     rx_rssi_sec20;
            a_uint8_t     rx_rssi_sec40;
            a_uint8_t     rx_rssi_sec80;
        } rx_rssi_chain1;
        struct {
            a_uint8_t     rx_rssi_pri20;
            a_uint8_t     rx_rssi_sec20;
            a_uint8_t     rx_rssi_sec40;
            a_uint8_t     rx_rssi_sec80;
        } rx_rssi_chain2;
        struct {
            a_uint8_t     rx_rssi_pri20;
            a_uint8_t     rx_rssi_sec20;
            a_uint8_t     rx_rssi_sec40;
            a_uint8_t     rx_rssi_sec80;
        } rx_rssi_chain3;
        a_uint64_t    rx_bytes;
        a_uint64_t    tx_bytes;
        a_uint32_t    tx_compaggr;
        a_uint32_t    rx_aggr;
        a_uint32_t    tx_bawadv;
        a_uint32_t    tx_compunaggr;
        a_uint32_t    rx_overrun;
        a_uint32_t    rx_badcrypt;
        a_uint32_t    rx_badmic;
        a_uint32_t    rx_crcerr;
        a_uint32_t    rx_phyerr;
        a_uint32_t    ackRcvBad;
        a_uint32_t    rtsBad;
        a_uint32_t    rtsGood;
        a_uint32_t    fcsBad;
        a_uint32_t    noBeacons;
        a_uint32_t    mib_int_count;
        a_uint32_t    rx_looplimit_start;
        a_uint32_t    rx_looplimit_end;
        a_uint8_t     ap_stats_tx_cal_enable;
    } interface_stats;
} acfg_ath_stats_11ac_t;

#endif

