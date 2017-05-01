/*
 * @@-COPYRIGHT-START-@@
 *
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 *
 * @@-COPYRIGHT-END-@@
 */

#ifndef _UMAC_IEEE80211_BAND_STEERING__
#define _UMAC_IEEE80211_BAND_STEERING__

/*opaque handle in ic structure */
typedef struct ieee80211_bsteering    *ieee80211_bsteering_t;

// forward decls
struct ieee80211vap;
struct ieee80211com;
struct ieee80211req_athdbg;

#if ATH_BAND_STEERING

/**
 * @brief Initialize the band steering infrastructure.
 *
 * @param [in] ic  the radio on which to initialize
 *
 * @return EOK on success; EINPROGRESS if band steering is already initialized
 *         or ENOMEM on a memory allocation failure
 */
int ieee80211_bsteering_attach(struct ieee80211com *ic);

/**
 * @brief Destroy the band steering infrastructure.
 *
 * @param [in] ic  the radio for which to destroy
 *
 * @return EOK on success; any other value for an error
 */

int ieee80211_bsteering_detach(struct ieee80211com *ic);

/**
 * @brief Set the band steering parameters.
 *
 * This can only be done when band steering is disabled. The parameters
 * include timer values and thresholds for RSSI reporting.
 *
 * @param [in] vap  the VAP on which the set operation was done
 * @param [in] req  the parameters to be set
 * @return EOK for success and EINVAL for error cases
 */
int wlan_bsteering_set_params(struct ieee80211vap *vap,
                              struct ieee80211req_athdbg *req);

/**
 * @brief Get the band steering parameters.
 *
 * The parameters include timer values and thresholds for RSSI reporting.
 *
 * @param [in] vap  the VAP on which the get operation was done
 * @param [in] req  the parameters to be retrieved
 */
int wlan_bsteering_get_params(const struct ieee80211vap *vap,
                              struct ieee80211req_athdbg *req);

/**
 * @brief Set the parameters that control whether debugging events are
 *        generated or not.
 *
 * @param [in] vap  the VAP on which the request came in
 * @param [in] req  the actual request parameters containing the new values
 */
int wlan_bsteering_set_dbg_params(struct ieee80211vap *vap,
                                  const struct ieee80211req_athdbg *req);

/**
 * @brief Get the parameters that control whether debugging events are
 *        generated or not.
 *
 * @param [in] vap  the VAP on which the request came in
 * @param [out] req  the object to update with the current debugging parameters
 */
int wlan_bsteering_get_dbg_params(const struct ieee80211vap *vap,
                                  struct ieee80211req_athdbg *req);

/**
 * @brief Generate an event indicating that a probe request was received.
 *
 * @param [in] vap  the VAP on which the probe was received
 * @param [in] mac_addr  the MAC address of the client that sent the probe
 *                       request
 * @param [in] rssi  the RSSI of the received probe request
 */
void ieee80211_bsteering_send_probereq_event(
                                             struct ieee80211vap *vap, const u_int8_t *mac_addr, u_int8_t rssi);

/**
 * @brief Query the band steering module for whether it is withholding
 *        probe responses for the given MAC address on this VAP.
 *
 * @param [in] vap  the VAP on which the probe request was received
 * @param [in] mac_addr  the MAC address of the client that sent the probe
 *                       request
 *
 * @return true if the response should be withheld; otherwise false
 */
bool ieee80211_bsteering_is_probe_resp_wh(struct ieee80211vap *vap,
                                          const u_int8_t *mac_addr);

/**
 * @brief Generate an event indicating that an authentication message
 *        was sent with a failure code.
 *
 * @param [in] vap  the VAP on which the message was sent
 * @param [in] mac_addr  the MAC address of the client to which the
 *                       message was sent
 * @param [in] rssi  the RSSI of the received authentication message which
 *                   caused the rejection
 */
void ieee80211_bsteering_send_auth_fail_event(
                                              struct ieee80211vap *vap, const u_int8_t *mac_addr, u_int8_t rssi);

/**
 * @brief Inform the band steering module that a node is now authorized.
 *
 * @param [in] vap  the VAP on which the change occurred
 * @param [in] mac_addr  the MAC address of the client who had its
 *                       authorization status change
 */
void ieee80211_bsteering_send_node_authorized_event(struct ieee80211vap *vap,
                                                    const u_int8_t *mac_addr);

/**
 * @brief Toggle a VAP's overloaded status
 *
 * @param [inout] vap  the VAP whose overload status changes
 * @param [in] req  request from user space containing the flag indicating overload or not
 *
 * @return EOK if overload status is set, otherwise return EINVAL
 */
int wlan_bsteering_set_overload(struct ieee80211vap *vap,
                                const struct ieee80211req_athdbg *req);

/**
 * @brief Retrieve a VAP's overloaded status
 *
 * @param [in] vap  the VAP whose overload status to retrieve
 * @param [out] req  the object to update with the current overload status
 *
 * @return EOK if overload status is retrieved successfully, otherwise return EINVAL
 */
int wlan_bsteering_get_overload(const struct ieee80211vap *vap,
                                struct ieee80211req_athdbg *req);

/**
 * @brief Enable/Disable band steering on a VAP
 *
 * @pre  wlan_bsteering_set_params must be called
 *
 * @param [inout] vap  the VAP whose band steering status changes
 * @param [in] req  request from user space containing the flag indicating enable or disable
 *
 * @return EINVAL if band steering not initialized, otherwise
 *         return EOK
 */
int wlan_bsteering_enable(struct ieee80211vap *vap,
                          const struct ieee80211req_athdbg *req);

/**
 * @brief Start RSSI measurement on a specific station
 *
 * @param [in] vap  the VAP to start RSSI measurement
 * @param [in] req  request from user space containing the station MAC address and
 *                  number of measurements to average before reporting back
 *
 * @return EINVAL if band steering not initialized; EBUSY if the previous measurement is not done;
 *         otherwise return EOK
 */
int wlan_bsteering_trigger_rssi_measurement(struct ieee80211vap *vap,
                                            const struct ieee80211req_athdbg *req);

/**
 * @brief Mark a node's inactivity status in band steering context
 *
 * @param [inout] ni  The node to update
 * @param [in] inact flag indicating inactive or not
 */

void ieee80211_bsteering_mark_node_bs_inact(struct ieee80211_node *ni, bool inact);

/**
 * @brief Update whether probe responses should be withheld for a given
 *        MAC or not.
 *
 * Responses are only actually withheld if band steering is enabled.
 *
 * @pre The MAC must currently be in the ACL list for this to succeed.
 *
 * @param [in] vap  the VAP for which to change the value
 * @param [in] req  request from user space containing the station MAC
 *                  address and whether to enable or disable probe
 *                  response withholding
 *
 * @return EINVAL if the request is malformed; ENOENT if the MAC is not
 *         currently in the ACL; otherwise EOK
 */
int wlan_bsteering_set_probe_resp_wh(struct ieee80211vap *vap,
                                     const struct ieee80211req_athdbg *req);

/**
 * @brief Query whether probe responses are being withheld for a given
 *        MAC or not.
 *
 * Even if this indicates that responses are being withheld for this MAC,
 * they will only actually be withheld if band steering is enabled.
 *
 * @pre The MAC must currently be in the ACL list for this to succeed.
 *
 * @param [in] vap  the VAP for which to get the value
 * @param [inout] req  request from user space containing the station MAC
 *                     address for which to read the probe response
 *                     withholding value
 *
 * @return EINVAL if the request is malformed; otherwise EOK
 */
int wlan_bsteering_get_probe_resp_wh(struct ieee80211vap *vap,
                                     struct ieee80211req_athdbg *req);

/**
 * @brief Record a node's activity status change
 *
 * @param [in] ic  the radio on which the node is associated
 * @param [in] mac_addr  the MAC address of the node
 * @param [in] active  true if the node becomes active;
 *                     false if it becomes inactive
 */
void ieee80211_bsteering_record_act_change(struct ieee80211com *ic,
                                           const u_int8_t *mac_addr,
                                           bool active);

/**
 * @brief Inform the band steering module of a channel utilization measurement.
 *
 * If the necessary number of utilization measurements have been obtained,
 * this will result in an event being generated.
 *
 * @param [in] vap  the VAP for which the utilization report occurred
 * @param [in] ieee_chan_num  the channel on which the utilization measurement
 *                            took place
 * @param [in] chan_utilization  the actual utilization measurement
 */
void ieee80211_bsteering_record_utilization(struct ieee80211vap *vap,
                                            u_int ieee_chan_num,
                                            u_int32_t chan_utilization);

/**
 * @brief Inform the band steering module of a RSSI measurement.
 *
 * If the RSSI measurement crossed the threshold, this will result in an event
 * being generated.
 *
 * @param [in] ni  the node for which the RSSI measurement occurred
 * @param [in] rssi  the measured RSSI
 */
void ieee80211_bsteering_record_rssi(struct ieee80211_node *ni,
                                     u_int8_t rssi);

/**
 * @brief Inform the band steering module of an inst RSSI measurement obtained by
 *        sending Null Data Packet
 *
 * If the necessary number of inst RSSI measurements have been obtained,
 * this will result in an event being generated.
 *
 * @param [in] ni  the node for which the RSSI measurement occurred
 * @param [in] rssi  the measured RSSI
 */
void ieee80211_bsteering_record_inst_rssi(struct ieee80211_node *ni,
                                          u_int8_t rssi);
/**
 * @brief Inform the band steering module of an invalid RSSI measurement when
 *        retrying sending Null Data Packet reaches limit
 *
 * If the error count reaches the limit, an event will be generated with
 * rssi of BSTEERING_INVALID RSSI,
 *
 * @param [in] ni  the node for which the RSSI measurement occurred
 */
void ieee80211_bsteering_record_inst_rssi_err(struct ieee80211_node *ni);

/**
 * @brief used for direct attach to inform band steering module for node rssi 
 * @param [in] mac address of reporting node
 * @param [in] status , success or failure
 * @param [in] rssi , rssi of node 
 */

void ieee80211_bsteering_direct_attach_rssi_update(struct ieee80211com *ic,
                                                   u_int8_t *macaddress,
                                                   u_int8_t status,
                                                   int8_t rssi);
#else

// Stub functions that return error codes to the band steering ioctls.

static inline int wlan_bsteering_set_params(struct ieee80211vap *vap,
                                            struct ieee80211req_athdbg *req)
{
    return -EINVAL;
}

static inline int wlan_bsteering_get_params(const struct ieee80211vap *vap,
                                            struct ieee80211req_athdbg *req)
{
    return -EINVAL;
}

static inline int wlan_bsteering_set_dbg_params(struct ieee80211vap *vap,
                                                const struct ieee80211req_athdbg *req)
{
    return -EINVAL;
}

static inline int wlan_bsteering_get_dbg_params(const struct ieee80211vap *vap,
                                                struct ieee80211req_athdbg *req)
{
    return -EINVAL;
}

static inline int wlan_bsteering_set_overload(struct ieee80211vap *vap,
                                              const struct ieee80211req_athdbg *req)
{
    return -EINVAL;
}

static inline int wlan_bsteering_get_overload(const struct ieee80211vap *vap,
                                              struct ieee80211req_athdbg *req)
{
    return -EINVAL;
}

static inline int wlan_bsteering_enable(struct ieee80211vap *vap,
                                        const struct ieee80211req_athdbg *req)
{
    return -EINVAL;
}

static inline int wlan_bsteering_trigger_rssi_measurement(struct ieee80211vap *vap,
                                                          const struct ieee80211req_athdbg *req)
{
    return -EINVAL;
}

static inline void ieee80211_bsteering_direct_attach_rssi_update(struct ieee80211com *ic,
                                                                 u_int8_t *macaddress,
                                                                 u_int8_t status,int8_t rssi)
{
    return;
}
 
static inline int wlan_bsteering_set_probe_resp_wh(const struct ieee80211vap *vap,
                                                   const struct ieee80211req_athdbg *req)
{
    return -EINVAL;
}

static inline int wlan_bsteering_get_probe_resp_wh(const struct ieee80211vap *vap,
                                                   struct ieee80211req_athdbg *req)
{
    return -EINVAL;
}


#endif /* ATH_BAND_STEERING */

#endif /* _UMAC_IEEE80211_BAND_STEERING__ */
