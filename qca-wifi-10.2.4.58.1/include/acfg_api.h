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

#ifndef __ACFG_API_H
#define __ACFG_API_H

#include <acfg_api_types.h>

char ctrl_hapd[ACFG_CTRL_IFACE_LEN];
char ctrl_wpasupp[ACFG_CTRL_IFACE_LEN];

/**
 * @brief  Initialize interface for device-less configurations
 *
 * @return
 */
a_status_t 
acfg_dl_init(void);

/** 
 * @brief Create a VAP on the specified WIFI
 * 
 * @param wifi_name (Upto ACFG_MAX_IFNAME)
 * @param vap_name  (Upto ACFG_MAX_IFNAME)
 * @param mode
 * @param vapid
 * @param flags 
 * @return 
 */
a_status_t   
acfg_create_vap(a_uint8_t            *wifi_name, 
        a_uint8_t            *vap_name, 
        acfg_opmode_t         mode, 
        a_int32_t             vapid, 
        acfg_vapinfo_flags_t  flags);

/** 
 * @brief Delete a VAP on the specified WIFI
 * 
 * @param wifi_name (Upto ACFG_MAX_IFNAME)
 * @param vap_name  (Upto ACFG_MAX_IFNAME)
 * 
 * @return 
 */
a_status_t   
acfg_delete_vap(a_uint8_t *wifi_name, a_uint8_t *vap_name);



/** 
 * @brief Determine whether a VAP is local or remote
 * 
 * @param vap_name  (Upto ACFG_MAX_IFNAME)
 * 
 * @return On Success
 *             If vap is offload (remote): A_STATUS_OK
 *             Else: A_STATUS_FAILED
 *         On Error: A_STATUS_EFAULT
 */
a_status_t
acfg_is_offload_vap(a_uint8_t *vap_name);

/** 
 * @brief Add client with overriding params
 * 
 * @param vap_name  (Upto ACFG_MAX_IFNAME)
 *        mac
 *        aid
 *        qos
 *        lrates
 *        htrates
 *        vhtrates
 * 
 * @return On Success
 *             If : A_STATUS_OK
 *             Else: A_STATUS_FAILED
 *         On Error: A_STATUS_EFAULT
 */
a_status_t   
acfg_add_client(a_uint8_t *vap_name, a_uint8_t *mac, a_uint32_t aid, a_uint32_t qos, 
                acfg_rateset_t lrates, acfg_rateset_t htrates, acfg_rateset_t vhtrates);

/** 
 * @brief Authorize client
 * 
 * @param vap_name  (Upto ACFG_MAX_IFNAME)
 *        mac
 * 
 * @return On Success
 *             If : A_STATUS_OK
 *             Else: A_STATUS_FAILED
 *         On Error: A_STATUS_EFAULT
 */
a_status_t   
acfg_forward_client(a_uint8_t *vap_name, a_uint8_t *mac);

/** 
 * @brief Delete a client
 * 
 * @param vap_name  (Upto ACFG_MAX_IFNAME)
 *        mac
 * 
 * @return On Success
 *             If : A_STATUS_OK
 *             Else: A_STATUS_FAILED
 *         On Error: A_STATUS_EFAULT
 */
a_status_t   
acfg_delete_client(a_uint8_t *vap_name, a_uint8_t *mac);

/** 
 * @brief Delete the encryption key
 * 
 * @param vap_name  (Upto ACFG_MAX_IFNAME)
 *        mac
 *        key index
 * 
 * @return On Success
 *             If : A_STATUS_OK
 *             Else: A_STATUS_FAILED
 *         On Error: A_STATUS_EFAULT
 */
a_status_t   
acfg_del_key(a_uint8_t *vap_name, a_uint8_t *mac, a_uint16_t keyidx);

/** 
 * @brief Set the encryption key
 * 
 * @param vap_name  (Upto ACFG_MAX_IFNAME)
 *        mac
 *        cipher
 *        key index
 *        key length
 *        keydata - 64 bytes
 * 
 * @return On Success
 *             If : A_STATUS_OK
 *             Else: A_STATUS_FAILED
 *         On Error: A_STATUS_EFAULT
 */
a_status_t   
acfg_set_key(a_uint8_t *vap_name, a_uint8_t *mac, CIPHER_METH cipher, a_uint16_t keyidx,
             a_uint32_t keylen, a_uint8_t *keydata);

/** 
 * @brief Set the SSID for the given VAP
 * 
 * @param vap_name (Upto ACFG_MAX_IFNAME)
 * @param ssid
 * 
 * @return 
 */
a_status_t
acfg_set_ssid(a_uint8_t *vap_name, acfg_ssid_t *ssid);

/** 
 * @brief Get the ssid for the given vap
 * 
 * @param vap_name (Upto ACFG_MAX_IFNAME)
 * @param ssid
 */
a_status_t
acfg_get_ssid(a_uint8_t *vap_name, acfg_ssid_t *ssid);

/** 
 * @brief Get the rssi for the given vap
 * 
 * @param vap_name (Upto ACFG_MAX_IFNAME)
 * @param rssi
 */
a_status_t
acfg_get_rssi(a_uint8_t *vap_name, acfg_rssi_t *rssi);

/** 
 * @brief Get the custdata for the given vap
 * 
 * @param vap_name (Upto ACFG_MAX_IFNAME)
 * @param custdata
 */
a_status_t
acfg_get_custdata(a_uint8_t *vap_name, acfg_custdata_t *custdata);

/** 
 * @brief Set the testmode for the given VAP
 * 
 * @param vap_name (Upto ACFG_MAX_IFNAME)
 * @param testmode
 * 
 * @return 
 */
a_status_t
acfg_set_testmode(a_uint8_t *vap_name, acfg_testmode_t *testmode);

/** 
 * @brief Get the testmode for the given vap
 * 
 * @param vap_name (Upto ACFG_MAX_IFNAME)
 * @param testmode
 */
a_status_t
acfg_get_testmode(a_uint8_t *vap_name, acfg_testmode_t *testmode);

/** 
 * @brief Set the Channel (IEEE) number
 * 
 * @param wifi_name (Radio)
 * @param chan_num (Upto ACFG_MAX_IEEE_CHAN)
 */
a_status_t
acfg_set_channel(a_uint8_t *wifi_name, a_uint8_t chan_num);

/** 
 * @brief Get the Channel (IEEE) number
 * 
 * @param wifi_name (Radio)
 * @param chan_num 
 */
a_status_t
acfg_get_channel(a_uint8_t *wifi_name, a_uint8_t *chan_num);

/** 
 * @brief Get scan results
 * 
 * @param vap_name (Upto ACFG_MAX_IFNAME)
 * @param list (Pointer to the list of scanned results)
 * @param len (Pointer to store the number of scan entries)
 * @param offset (If there are more results, this should be
 *                used to retrive the next block)
 * 
 * @return (A_STATUS_OK if no more scan results or else
 *          A_STATUS_EINPROGRESS for more results pending)
 */
a_status_t
acfg_get_scan_list(a_uint8_t         *vap_name, 
        acfg_scan_list_t  *list, 
        a_uint32_t        *len,
        a_uint8_t          offset);

/** 
 * @brief Set the opmode
 * 
 * @param wifi_name (Radio)
 * @param opmode
 */
a_status_t
acfg_set_opmode(a_uint8_t *wifi_name, acfg_opmode_t opmode);

/** 
 * @brief Get the opmode
 * 
 * @param wifi_name (Radio)
 * @param opmode
 */
a_status_t
acfg_get_opmode(a_uint8_t *wifi_name, acfg_opmode_t *opmode);

/** 
 * @brief Set the frequency
 * 
 * @param wifi_name
 * @param freq - Frequency in MHz
 * 
 * @return 
 */
a_status_t
acfg_set_freq(a_uint8_t *wifi_name, a_uint32_t freq);

/** 
 * @brief Get the frequency
 * 
 * @param wifi_name
 * @param freq - Frequency returned in MHz
 * 
 * @return 
 */
a_status_t
acfg_get_freq(a_uint8_t *wifi_name, a_uint32_t *freq);

/** 
 * @brief Get RTS threshold. The value returned is in iwparam->value.
 *        Other fields can be ignored.
 * 
 * @param vap_name
 * @param rts
 * 
 * @return 
 */

/**
 *   @brief Set RTS threshold. The value returned is in iwparam->value.
 *          Other fields can be ignored.
 *    
 *     @param vap_name
 *     @rts value
 *     @rts flags
 *     @return
 */
a_status_t
acfg_set_rts(a_uint8_t *vapname, acfg_rts_t *rts);



a_status_t
acfg_get_rts(a_uint8_t *vap_name, acfg_rts_t *rts);


a_status_t
acfg_set_frag(a_uint8_t *vapname, acfg_frag_t *frag);

/** 
 * @brief Get Fragmentation threshold
 * 
 * @param wifi_name
 * @param iwparam
 * 
 * @return 
 */
a_status_t
acfg_get_frag(a_uint8_t *vap_name, acfg_frag_t *frag);

a_status_t
acfg_set_txpow(a_uint8_t *vapname, acfg_txpow_t *frag);


/** 
 * @brief Get default Tx Power in dBm
 * 
 * @param wifi_name
 * @param txpow
 */
a_status_t
acfg_get_txpow(a_uint8_t *wifi_name, acfg_txpow_t *txpow);

/** 
 * @brief Get Access Point MAC Address
 * 
 * @param vap_name
 * @param mac
 */
a_status_t
acfg_get_ap(a_uint8_t *vap_name, acfg_macaddr_t* mac);

/** 
 * @brief Set Encode Information
 * 
 * @param vap_name
 * @param flag
 * @param len
 * @param enc
 */
a_status_t
acfg_set_enc(a_uint8_t *vap_name, acfg_encode_flags_t flag, a_char_t *enc);

/**
 * @brief set Vap vendor param
 *
 * @param vap_name
 * @param param
 * @param data
 * @param len
 * @param type
 * @param reinit
 * @return
 */
a_status_t
acfg_set_vap_vendor_param(a_uint8_t *vap_name, \
        acfg_vendor_param_vap_t param, a_uint8_t *data,
        a_uint32_t len, a_uint32_t type, acfg_vendor_param_init_flag_t reinit);

/**
 * @brief get Vap vendor param
 *
 * @param vap_name
 * @param param
 * @param data
 * @param type
 * @return
 */
a_status_t
acfg_get_vap_vendor_param(a_uint8_t *vap_name, \
        acfg_vendor_param_vap_t param, a_uint8_t *data,
        a_uint32_t *type);

/**
 * @brief Set Vap param 
 * 
 * @param vap_name  -   vap name
 * @param param     -   param id
 * @param val       -   value       
 * 
 * @return 
 */
a_status_t
acfg_set_vap_param(a_uint8_t *vap_name, \
        acfg_param_vap_t param, a_uint32_t val);


/** 
 * @brief Get Vap param
 * 
 * @param vap_name  -   vap name
 * @param param     -   param id
 * @param val       -   pointer to memory for return value
 * 
 * @return 
 */
a_status_t
acfg_get_vap_param(a_uint8_t *vap_name, \
        acfg_param_vap_t param, a_uint32_t *val);

/** 
 * @brief Set Radio param
 * 
 * @param radio_name    -   radio name
 * @param param         -   param id
 * @param val           -   value
 * 
 * @return 
 */
a_status_t
acfg_set_radio_param(a_uint8_t *radio_name, \
        acfg_param_radio_t param, a_uint32_t val);

/** 
 * @brief Get Radio param
 * 
 * @param radio_name    -   radio name
 * @param param         -   param id
 * @param val           -   pointer to memory for return value
 * 
 * @return 
 */
a_status_t
acfg_get_radio_param(a_uint8_t *radio_name, \
        acfg_param_radio_t param, a_uint32_t *val);

a_status_t
acfg_set_rate(a_uint8_t *vap_name, acfg_rate_t *rate);

/** 
 * @brief Get default bit rate
 * 
 * @param vap_name
 * @param mac
 * 
 * @return 
 */
a_status_t
acfg_get_rate(a_uint8_t *vap_name, a_uint32_t *rate);


/** 
 * @brief Get wireless statistics
 * 
 * @param vap_name
 * @param stats
 * 
 * @return 
 */
a_status_t
acfg_get_stats(a_uint8_t *vap_name, acfg_stats_t *stats);


/** 
 * @brief Set the phymode
 * 
 * @param vap_name
 * @param mode
 * 
 * @return 
 */
a_status_t
acfg_set_phymode(a_uint8_t *vap_name, acfg_phymode_t mode);

a_status_t
acfg_get_phymode(a_uint8_t *vap_name, acfg_phymode_t *mode);

a_status_t
acfg_assoc_sta_info(a_uint8_t *vap_name, acfg_sta_info_req_t *sinfo);

/** 
 * @brief Set Reg value
 * 
 * @param radio_name    -   radio name
 * @param offset        -   offset
 * @param val           -   value
 * 
 * @return 
 */
a_status_t
acfg_set_reg(a_uint8_t *radio_name, \
        a_uint32_t offset, a_uint32_t val);

/** 
 * @brief Get Reg Value
 * 
 * @param radio_name    -   radio name
 * @param offset        -   offset
 * @param val           -   pointer to memory for return value
 * 
 * @return 
 */
a_status_t
acfg_get_reg(a_uint8_t *radio_name, \
        a_uint32_t param, a_uint32_t *val);


a_status_t 
acfg_hostapd_getconfig(a_uint8_t *vap_name, a_char_t *reply_buf);

a_status_t
acfg_hostapd_set_wpa(a_uint8_t *argv[]);

/** 
 * @brief Create a VLAN Group
 * 
 * @param vlanid        -   vlan id for the group
 * 
 * @return 
 */
a_status_t
acfg_vlgrp_create(a_uint8_t *vlan_id);

/** 
 * @brief Delete a VLAN Group
 * 
 * @param vlanid        -   vlan id for the group
 * 
 * @return 
 */
a_status_t
acfg_vlgrp_delete(a_uint8_t *vlan_id);
/** 
 * @brief  Add VAP to a VLAN group
 * 
 * @param vlanid
 * 
 * @return 
 */
a_status_t
acfg_vlgrp_addvap(a_uint8_t *vlan_id, a_uint8_t *vap_name);

/** 
 * @brief Remove a VAP from a VLAN group
 * 
 * @param vlanid
 * @param vap_name
 * 
 * @return 
 */
a_status_t
acfg_vlgrp_delvap(a_uint8_t *vlan_id, a_uint8_t *vap_name);

a_status_t
acfg_acl_addmac(a_uint8_t *vap_name, a_uint8_t *addr);

a_status_t
acfg_acl_getmac(a_uint8_t *vap_name, acfg_macacl_t *maclist);

a_status_t
acfg_acl_delmac(a_uint8_t *vap_name, a_uint8_t *addr);


a_status_t
acfg_set_ap(a_uint8_t *vap_name, a_uint8_t *addr);

a_status_t
acfg_wlan_profile_get (acfg_wlan_profile_t *profile);

a_status_t
acfg_wlan_vap_profile_get (acfg_wlan_profile_vap_params_t *vap_params);


void
acfg_wlan_vap_profile_print (acfg_wlan_profile_vap_params_t *vap_params);

void
acfg_wlan_profile_print (acfg_wlan_profile_t *profile);

a_status_t
acfg_set_profile(acfg_wlan_profile_t *new_profile,
        acfg_wlan_profile_t *cur_profile);

a_status_t
acfg_write_file(acfg_wlan_profile_t *new_profile);

a_status_t
acfg_reset_cur_profile(a_char_t *radio_name);

a_status_t
acfg_apply_profile(acfg_wlan_profile_t *new_profile);

acfg_wlan_profile_t * acfg_get_profile(char *radio_name);

void
acfg_free_profile(acfg_wlan_profile_t *profile);

a_status_t
acfg_get_current_profile (acfg_wlan_profile_t *profile);

void
acfg_init_profile(acfg_wlan_profile_t *profile);

void
acfg_init_radio_params (acfg_wlan_profile_radio_params_t *unspec_radio_params);

void
acfg_init_vap_params (acfg_wlan_profile_vap_params_t *unspec_vap_params);

void
acfg_mac_str_to_octet(a_uint8_t *mac_str, uint8_t *mac);

a_status_t
acfg_set_wps_pbc(char *ifname);

a_status_t
acfg_set_wps_pin(char *ifname, int action, char *pin, char *pin_txt,
        char *bssid);

a_status_t
acfg_wps_config(a_uint8_t *ifname, char *ssid,
        char *auth, char *encr, char *key);

char *acfg_get_errstr(void);

a_status_t 
acfg_set_radio_enable(a_uint8_t *ifname);

a_status_t 
acfg_set_radio_disable(a_uint8_t *ifname);

a_status_t 
acfg_set_country(a_uint8_t *radio_name, a_uint16_t country_code);

a_status_t
acfg_get_country(a_uint8_t *radio_name, a_uint32_t *country_code);

a_status_t 
acfg_set_regdomain(a_uint8_t *radio_name, a_uint32_t regdomain);

a_status_t
acfg_get_regdomain(a_uint8_t *radio_name, a_uint32_t *regdomain);

a_status_t 
acfg_set_tx_antenna(a_uint8_t *radio_name, a_uint16_t mask);

a_status_t 
acfg_set_rx_antenna(a_uint8_t *radio_name, a_uint16_t mask);

a_status_t 
acfg_set_shpreamble(a_uint8_t *radio_name, a_uint16_t shpreamble);

a_status_t
acfg_get_shpreamble(a_uint8_t *radio_name, a_uint32_t *shpreamble);

a_status_t 
acfg_set_txpower_limit(a_uint8_t *radio_name, enum acfg_band_type band, a_uint32_t power);

a_status_t 
acfg_set_chainmask(a_uint8_t *radio_name, enum acfg_chainmask_type type, a_uint16_t mask);

a_status_t
acfg_config_radio(a_uint8_t *radio_name);

a_status_t
acfg_set_preamble(a_uint8_t  *vap_name, a_uint32_t preamble);

a_status_t
acfg_set_slot_time(a_uint8_t  *vap_name, a_uint32_t slot);

a_status_t
acfg_set_erp(a_uint8_t  *vap_name, a_uint32_t erp);

a_status_t
acfg_add_app_ie(a_uint8_t  *vap_name, const a_uint8_t *ie, a_uint32_t ie_len);

a_status_t
acfg_set_chanswitch(a_uint8_t  *wifi_name, a_uint8_t  chan_num);

a_status_t
acfg_set_ratemask(a_uint8_t  *vap_name, a_uint8_t preamble, a_uint32_t mask_lower32,
                  a_uint32_t mask_higher32);

a_status_t 
acfg_set_shslot(a_uint8_t *radio_name, a_uint16_t shslot);

a_status_t
acfg_get_shslot(a_uint8_t *radio_name, a_uint32_t *shslot);

a_status_t
acfg_get_rx_antenna(a_uint8_t *radio_name,  a_uint32_t *mask);

a_status_t
acfg_get_tx_antenna(a_uint8_t *radio_name,  a_uint32_t *mask);

a_status_t
acfg_tx99_tool(a_uint8_t  *wifi_name, acfg_tx99_data_t* tx99_data);

#endif
