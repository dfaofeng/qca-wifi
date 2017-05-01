/*
 * Copyright (c) 2011, Atheros Communications Inc.
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

#include "ol_if_athvar.h"
#include <ieee80211_defines.h>
#include <ieee80211_scan.h>



//tone number of each bw
//bw = 0, Legacy 20MHz, 53 tones
//bw = 1, HT 20MHz, 57 tones
//bw = 2, HT 40MHz, 117 tones
//bw = 3, VHT 80MHz, 242 tones

#define TONE_LEGACY_20M 53
#define TONE_VHT_20M 56
#define TONE_VHT_40M 117
#define TONE_VHT_80M 242

int tone_number[4] = {TONE_LEGACY_20M, TONE_VHT_20M, TONE_VHT_40M, TONE_VHT_80M};
#define MEM_ALIGN(x) (((x)<<1)+3) & 0xFFFC

// the buffer size of 1 chain for each BW 0-3 
u_int16_t bw_size [4] = 
{
    MEM_ALIGN(TONE_LEGACY_20M),
    MEM_ALIGN(TONE_VHT_20M),
    MEM_ALIGN(TONE_VHT_40M),
    MEM_ALIGN(TONE_VHT_80M)
};

char* measurement_type[] = {
    "NULL Frame",
    "QoS_NULL Frame",
    "TMR/TM Frame"    
};

/*
 * Define the sting for each RTT request type
 * for debug print purpose only  
 */
char* error_indicator[] = {
    "RTT_COMMAND_HEADER_ERROR",
    "RTT_COMMAND_ERROR",
    "RTT_MODULE_BUSY",
    "RTT_TOO_MANY_STA",
    "RTT_NO_RESOURCE",
    "RTT_VDEV_ERROR",
    "RTT_TRANSIMISSION_ERROR",
    "RTT_TM_TIMER_EXPIRE",
    "RTT_FRAME_TYPE_NOSUPPORT",
    "RTT_TIMER_EXPIRE",
    "RTT_CHAN_SWITCH_ERROR"
};





/* 

 * Calculate how many chains in a mask

 * mask -- chain mask  return: Number of chains

 */

static u_int8_t rtt_get_chain_no(u_int16_t mask)
{
    u_int8_t counter = 0;
    while (mask > 0) {
        if(mask & 1) counter++;
        mask = mask >> 1;
    }

    return counter;
}

/*
 * print out the rtt measurement response on host
 * for debug purpose
 */
void rtt_print_resp_header(wmi_rtt_event_hdr *header,
                           u_int8_t* frame_type,
                           u_int8_t* report_type) 
{   //print event header
    u_int8_t dest_mac[6];
    //adf_os_print("%s:", __func__);
    adf_os_print("\n\n==================Measurement Report====================\n");
    adf_os_print("Request ID is:0x%x\n", header->req_id  & 0x0000ffff);
    adf_os_print("Request result is:0x%x\n", (header->req_id & 0xffff0000) >>16);

    WMI_MAC_ADDR_TO_CHAR_ARRAY(&header->dest_mac, dest_mac);
    *frame_type = WMI_RTT_REPORT_MEAS_TYPE_GET(header->req_id);
    *report_type = WMI_RTT_REPORT_REPORT_TYPE_GET(header->req_id);
    /* Only 3 type of frames are used for Measurement type , 
       even though  RTT measurement type is 3 bit header */
    adf_os_print("Measuremnet Type is %s \n", *frame_type < 3? measurement_type[*frame_type]:"Invalid frame type");
    adf_os_print("Report type is %d \n", *report_type);
    adf_os_print("Request dest_mac is:%.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n", dest_mac[0],dest_mac[1],
                 dest_mac[2],dest_mac[3],dest_mac[4],dest_mac[5]);
}

void rtt_print_meas_resp_body(wmi_rtt_meas_event *body,
                              u_int8_t meas_type,
                              u_int8_t report_type)
{
    u_int8_t mask;
    u_int8_t bw;
    u_int8_t *p, *tmp;
    u_int8_t index, index1;
    u_int64_t tmp1;
    A_TIME64 *time;

    adf_os_print("%s:\n", __func__);

    if(body) {
        mask = WMI_RTT_REPORT_RX_CHAIN_GET(body->rx_chain);
        adf_os_print("Rx chain mask is:0x%x\n",mask);

       //calculate how many chains in mask
        bw = WMI_RTT_REPORT_RX_BW_GET(body->rx_chain);
        adf_os_print("Rx bw is:%d\n",bw);

        tmp1 = ((u_int64_t) body->tod.time32) <<32;
        tmp1 |= body->tod.time0;

        if( meas_type != RTT_MEAS_FRAME_TMR) {//
            adf_os_print("tod (0.1 ns) is: %llu\n", tmp1);
        } else {
            adf_os_print("t1 (0.1 ns) is: %llu\n", tmp1);     
        }

        tmp1 = ((u_int64_t) body->toa.time32) <<32;
        tmp1 |= body->toa.time0;

        if( meas_type != RTT_MEAS_FRAME_TMR) {//2 is TMR
            adf_os_print("toa (0.1 ns) is: %llu\n", tmp1);
        } else {
            adf_os_print("t2 (0.1 ns) is: %llu\n", tmp1);   
        }

        p =(u_int8_t *) (++body);

        //if the measurement is TMR, we should have T3 and T4
        if ( meas_type == RTT_MEAS_FRAME_TMR) {
            time = (A_TIME64 *) body;
            tmp1 = (u_int64_t) (time->time32) <<32;
            tmp1 |= time->time0;

            adf_os_print("t3 (0.1 ns) is: %llu\n", tmp1);
            time++;
            tmp1 = (u_int64_t) (time->time32) <<32;
            tmp1 |= time->time0;

            adf_os_print("t4 (0.1 ns) is: %llu\n", tmp1);
            p =(u_int8_t *) (++time);
        }

        for (index = 0; index <4; index++ ) {
            if(mask & (1 << index)) {
                adf_os_print("RSSI of chain index %d is:%.8x\n",index,
                             *((u_int32_t *)p));

                p += sizeof(u_int32_t);
                if(!report_type) {
                    adf_os_print("channel dump of chain index %d is here\n", index);
                    tmp = p + bw_size[bw]; //end of this chains channel dump

                    for(index1 = 0; index1 < tone_number[bw]; index1++){
                        adf_os_print("%.4x ", *((u_int16_t *)(p)));
                        p+=2;
                    }

                    p = tmp; //alignment adjustment
                }
                adf_os_print("\n\n");
            }
        }
    } else {
        adf_os_print("Error! Null Point!\n") ;  
    }

    return;
}


/*
 * event handler for  RTT measurement response
 * data  -- rtt measurement response from fw
 */

static int
wmi_rtt_meas_report_event_handler(ol_scn_t scn, u_int8_t *data,
                    u_int16_t datalen, void *context) 
{
    u_int8_t meas_type, report_type;

    adf_os_print("%s: data=%p, datalen=%d\n", __func__, data, datalen);
    if (!data) {
        adf_os_print("Get NULL point message from FW\n");
        return -1;
    }

    rtt_print_resp_header((wmi_rtt_event_hdr *)data, & meas_type, &report_type);
    rtt_print_meas_resp_body((wmi_rtt_meas_event *)data, meas_type, report_type);
    return 0;
}

/*
 * event handler for TSF measurement response
 * data  -- TSF measurement response from fw
 */
static int
wmi_tsf_meas_report_event_handle(ol_scn_t scn, u_int8_t *data,
                    u_int16_t datalen, void *context) 

{
  //ToDo
  return 0;

}

/*
 * event handler for RTT Error report
 * data  -- rtt measurement response from fw
 */
static int
wmi_error_report_event_handle(ol_scn_t scn, u_int8_t *data,
                    u_int16_t datalen, void *context) 
{
    u_int8_t report_type, frame_type;
    adf_os_print("%s: data=%p, datalen=%u\n", __func__, data, datalen);
    if (!data) {
        adf_os_print("Get NULL point message from FW\n");
        return -1;
    }

    rtt_print_resp_header((wmi_rtt_event_hdr *)data, &frame_type, &report_type);
    data += sizeof(wmi_rtt_event_hdr);

    //KW# 6147 adf_os_print("%s\n",error_indicator[*((WMI_RTT_ERROR_INDICATOR *)data)<10 ? *((WMI_RTT_ERROR_INDICATOR *)data) : 1 ] ) ;

    //If the error code < 10, we can use it, otherwise use some valid error-code between 0-9. I used 1 here to signify error.

    //The developer may change add another code or use a completely different logic to handle this

    adf_os_print("%s\n",error_indicator[*((WMI_RTT_ERROR_INDICATOR *)data)] );
    /* Only 3 type of frames are used for Measurement type , 
       even though  RTT measurement type is 3 bit header */
    adf_os_print("Measuremnet Type is %s \n", (frame_type < 3)? measurement_type[frame_type]:"Invalid frame type");
    adf_os_print("Report Type is %d", report_type);
    return 1;
}

/*
 * event handler for keepalive notification
 */
static int
wmi_rtt_keepalive_event_handle(ol_scn_t scn, u_int8_t *data,
                    u_int16_t datalen, void *context)
{
    wmi_rtt_event_hdr *header = (wmi_rtt_event_hdr *)data;
    u_int8_t dest_mac[6];

    adf_os_print("\n\n==================Keepalive Event====================\n");
    adf_os_print("Request ID is:0x%x\n", header->req_id  & 0x0000ffff);
    adf_os_print("Request result is:%d\n", (header->req_id & 0x10000) >> 16);

    WMI_MAC_ADDR_TO_CHAR_ARRAY(&header->dest_mac, dest_mac);
    adf_os_print("Request dest_mac is:%.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n", dest_mac[0],dest_mac[1],
                 dest_mac[2],dest_mac[3],dest_mac[4],dest_mac[5]);

    return 0;
}

/*
 * RTT measurement response handler attach functions for offload solutions
 */
void
ol_ath_rtt_meas_report_attach(struct ieee80211com *ic)
{

    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    adf_os_print("%s: called\n", __func__);

    /* Register WMI event handlers */
    wmi_unified_register_event_handler(scn->wmi_handle,
        WMI_RTT_MEASUREMENT_REPORT_EVENTID,
        wmi_rtt_meas_report_event_handler,
        NULL);

    wmi_unified_register_event_handler(scn->wmi_handle,
        WMI_TSF_MEASUREMENT_REPORT_EVENTID,
        wmi_tsf_meas_report_event_handle,
        NULL);

    wmi_unified_register_event_handler(scn->wmi_handle,
        WMI_RTT_ERROR_REPORT_EVENTID,
        wmi_error_report_event_handle,
        NULL);

    wmi_unified_register_event_handler(scn->wmi_handle,
        WMI_RTT_KEEPALIVE_EVENTID,
        wmi_rtt_keepalive_event_handle,
        NULL);

    return;

}

typedef struct {
    wmi_channel *channel;
    struct ieee80211com *ic;
} channel_search;





/*
 * Find the channel information according to the scan entry
 */
int rtt_find_channel_info (void *arg, wlan_scan_entry_t scan_entry)
{
    wmi_channel *wmi_chan;
    u_int32_t chan_mode;
    struct ieee80211com *ic;
    struct ieee80211_channel *se_chan;
    static const u_int modeflags[] = {
        0,                            /* IEEE80211_MODE_AUTO           */
        MODE_11A,         /* IEEE80211_MODE_11A            */
        MODE_11B,         /* IEEE80211_MODE_11B            */
        MODE_11G,         /* IEEE80211_MODE_11G            */
        0,                            /* IEEE80211_MODE_FH             */
        0,                            /* IEEE80211_MODE_TURBO_A        */
        0,                            /* IEEE80211_MODE_TURBO_G        */
        MODE_11NA_HT20,   /* IEEE80211_MODE_11NA_HT20      */
        MODE_11NG_HT20,   /* IEEE80211_MODE_11NG_HT20      */
        MODE_11NA_HT40,   /* IEEE80211_MODE_11NA_HT40PLUS  */
        MODE_11NA_HT40,   /* IEEE80211_MODE_11NA_HT40MINUS */
        MODE_11NG_HT40,   /* IEEE80211_MODE_11NG_HT40PLUS  */
        MODE_11NG_HT40,   /* IEEE80211_MODE_11NG_HT40MINUS */
        MODE_11NG_HT40,   /* IEEE80211_MODE_11NG_HT40      */
        MODE_11NA_HT40,   /* IEEE80211_MODE_11NA_HT40      */
        MODE_11AC_VHT20,  /* IEEE80211_MODE_11AC_VHT20     */
        MODE_11AC_VHT40,  /* IEEE80211_MODE_11AC_VHT40PLUS */
        MODE_11AC_VHT40,  /* IEEE80211_MODE_11AC_VHT40MINUS*/
        MODE_11AC_VHT40,  /* IEEE80211_MODE_11AC_VHT40     */
        MODE_11AC_VHT80,  /* IEEE80211_MODE_11AC_VHT80     */
    };

    adf_os_print("%s:\n", __func__);

    if (!(arg && scan_entry)) {
        return -1; //critical error
    }

    wmi_chan = ((channel_search *)arg)->channel;
    ic = ((channel_search *)arg)->ic;

    if(!(wmi_chan && ic)) {
        return -1; //critical error
    }

    se_chan = wlan_scan_entry_channel(scan_entry);

    if(!se_chan) {
        return -1; //critical error
    }

    wmi_chan->mhz = ieee80211_chan2freq(ic,se_chan);
    chan_mode = ieee80211_chan2mode(se_chan);
    WMI_SET_CHANNEL_MODE(wmi_chan, modeflags[chan_mode]);

    if(chan_mode == IEEE80211_MODE_11AC_VHT80) {
        if (se_chan->ic_ieee < 20) {
            wmi_chan->band_center_freq1 = ieee80211_ieee2mhz(
                                             ic,
                                             se_chan->ic_vhtop_ch_freq_seg1,
                                             IEEE80211_CHAN_2GHZ);
        } else {
            wmi_chan->band_center_freq1 = ieee80211_ieee2mhz(
                                            ic,
                                            se_chan->ic_vhtop_ch_freq_seg1,
                                            IEEE80211_CHAN_5GHZ);
        }
    } else if((chan_mode == IEEE80211_MODE_11NA_HT40PLUS) ||
              (chan_mode == IEEE80211_MODE_11NG_HT40PLUS) ||
              (chan_mode == IEEE80211_MODE_11AC_VHT40PLUS)) {
        wmi_chan->band_center_freq1 = wmi_chan->mhz + 10;
    } else if((chan_mode == IEEE80211_MODE_11NA_HT40MINUS) ||
              (chan_mode == IEEE80211_MODE_11NG_HT40MINUS) ||
              (chan_mode == IEEE80211_MODE_11AC_VHT40MINUS)) {
        wmi_chan->band_center_freq1 = wmi_chan->mhz - 10;
    } else {
        wmi_chan->band_center_freq1 = wmi_chan->mhz;
    }

    /* we do not support HT80PLUS80 yet */
    wmi_chan->band_center_freq2=0;
    WMI_SET_CHANNEL_MIN_POWER(wmi_chan, se_chan->ic_minpower);
    WMI_SET_CHANNEL_MAX_POWER(wmi_chan, se_chan->ic_maxpower);
    WMI_SET_CHANNEL_REG_POWER(wmi_chan, se_chan->ic_maxregpower);
    WMI_SET_CHANNEL_ANTENNA_MAX(wmi_chan, se_chan->ic_antennamax);
    WMI_SET_CHANNEL_REG_CLASSID(wmi_chan, se_chan->ic_regClassId);

    if (IEEE80211_IS_CHAN_DFS(se_chan))
        WMI_SET_CHANNEL_FLAG(wmi_chan, WMI_CHAN_FLAG_DFS);

    adf_os_print("WMI channel freq=%d, mode=%x band_center_freq1=%d\n", wmi_chan->mhz, 
        WMI_GET_CHANNEL_MODE(wmi_chan), wmi_chan->band_center_freq1);

    return 1; //seccessful!    
}

/*
 * Send RTT measurement Command to FW (for test purpose only) here we encode two
 * STA request in each measurement comments If you need change the embedded
 * value, please search the corresponding macro in wmi_unified.h and choose the
 * macro you want to use.
 */
void
ol_ath_rtt_meas_req(wmi_unified_t  wmi_handle, struct ieee80211com *ic)
{
  //struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_buf_t buf;
    u_int8_t *p;
    int ret;
    u_int16_t len;
    u_int8_t peer[6];  //ap
    u_int8_t spoof[6];
    wmi_rtt_measreq_head *head;
    wmi_rtt_measreq_body *body;
    struct ieee80211vap *vap;
    static u_int8_t req_id = 1;
    channel_search channel_search_info;

    adf_os_print("%s:\n", __func__);
    if(!wmi_handle) {
        adf_os_print("WMI ERROR:Invalid wmi_handle  ");
        req_id++;
        return;
    }

    //for test purpose, assume there is only one vap
    vap = TAILQ_FIRST(&(ic)->ic_vaps) ; 

    /* Temporarily, hardcoding peer mac address for test purpose will be removed
     * once RTT host has been developed for even req_id, loke 0, 2, 4, there is
     * no channel_swicth for odd req_id, like 1, 3 ,5, there is channel switch
     * currently, for both cases, we have 3 req in each command please change
     * here if you only have one (or just let it be) 
     */
    if(!(req_id & 0x1)) {   
        len = sizeof(wmi_rtt_measreq_head) + 2 * sizeof(wmi_rtt_measreq_body);
    } else {
        len = sizeof(wmi_rtt_measreq_head) + 2 * sizeof(wmi_rtt_measreq_body);
    }

    buf = wmi_buf_alloc(wmi_handle, len);
    if(!buf){
      adf_os_print("No WMI resource!");
        return;
    }

    p = (u_int8_t *) wmi_buf_data(buf);
    memset(p,0,len);


//#define RTT_TEST
    //encode header
    head = (wmi_rtt_measreq_head *) p;
    //head->req_id = req_id;
    WMI_RTT_REQ_ID_SET(head->req_id, req_id);
    WMI_RTT_SPS_SET(head->req_id, 1);

    if(!(req_id & 0x1)) {//even req id
#ifndef RTT_TEST
        //we actually only have 3 sta to measure
        //this is used to test over limit request protection
        WMI_RTT_NUM_STA_SET(head->sta_num, 5);
#else
        WMI_RTT_NUM_STA_SET(head->sta_num, 2);
#endif
    } else { //odd req id
        WMI_RTT_NUM_STA_SET(head->sta_num, 3);

    }

    //encode common parts for each RTT measurement command body
    //The value here can be overwrite in following each req hardcoding
    body = &(head->body[0]);
    //set vdev_id 
    WMI_RTT_VDEV_ID_SET(body-> measure_info, 0);
    //set timeout = 100ms
    WMI_RTT_TIMEOUT_SET(body->measure_info, 100);
    //set report type = 0
    WMI_RTT_REPORT_TYPE_SET(body->measure_info, WMI_RTT_REPORT_CFR);
    //set QOS_NULL frame, peer surpport TM OPT, TX chain mask
    if(!(req_id & 0x1)) {//even req_id
        WMI_RTT_FRAME_TYPE_SET(body->control_flag,RTT_MEAS_FRAME_TMR);
    } else {
        WMI_RTT_FRAME_TYPE_SET(body->control_flag,RTT_MEAS_FRAME_TMR);
    }
    //set Tx chain mask
    WMI_RTT_TX_CHAIN_SET(body->control_flag, 001);
    //set peer is QCA device
    WMI_RTT_QCA_PEER_SET(body->control_flag, 1);
    //set rate MCS
    WMI_RTT_MCS_SET(body->control_flag, 1);
    //set HW retry time 
    WMI_RTT_RETRIES_SET(body->control_flag, 1);

    //start from here, embed the first req in each RTT measurement Command
#ifndef RTT_TEST
    if(!(req_id & 0x1)) { // even time
        /*peer[5] = 0xcb;
        peer[4] = 0xef;
        peer[3] = 0x04;
        peer[2] = 0x6c;
        peer[1] = 0x24;
        peer[0] = 0x00;*/
        peer[5] = 0x37;//02;
        peer[4] = 0x00;//7E;
        peer[3] = 0x04;//7D;
        peer[2] = 0x7F;//86;
        peer[1] = 0x03;//0B;
        peer[0] = 0x00;        
    } else { //odd time
        /*peer[5] = 0xc3;//02;
        peer[4] = 0xef;//7E;
        peer[3] = 0x04;//7D;
        peer[2] = 0x6c;//86;
        peer[1] = 0x24;//0B;
        peer[0] = 0x00;*/
		peer[5] = 0x37;//02;
        peer[4] = 0x00;//7E;
        peer[3] = 0x04;//7D;
        peer[2] = 0x7F;//86;
        peer[1] = 0x03;//0B;
        peer[0] = 0x00;     
    }
#else
        peer[5] = 0x10; 
        peer[4] = 0x01;
        peer[3] = 0x03;
        peer[2] = 0x7f;
        peer[1] = 0x03;
        peer[0] = 0x00;
#endif

    //find channel from the peer mac of first request 
    channel_search_info.channel = &head->channel;
    channel_search_info.ic = ic;
    ret = wlan_scan_macaddr_iterate(vap, &peer[0],
              rtt_find_channel_info, &channel_search_info);

    if (!ret) {
        wbuf_free(buf);
        adf_os_print("Can not find corresponding channel info %d of "
                     "%.2x:%.2x:%.2x:%.2x:%.2x:%.2x", ret, peer[0],peer[1], peer[2],
                     peer[3], peer[4],peer[5]);
        req_id++;
        return;
    } else if (ret == -1){
        wbuf_free(buf);
        req_id++;
        adf_os_print("critical error %d", ret);
        return;
    }


    WMI_CHAR_ARRAY_TO_MAC_ADDR(((u_int8_t *)peer),&body->dest_mac) ;
    memset(spoof, 0 , 6);
    if ((req_id & 0x1)) {
        WMI_CHAR_ARRAY_TO_MAC_ADDR(((u_int8_t *)peer),&body->spoof_bssid) ;
    }

    //embedded varing part of each request
    //set Preamble, BW, measurement times
    if(!(req_id & 0x1)) {//even req_id
        WMI_RTT_BW_SET(body->control_flag, WMI_RTT_BW_20);
        WMI_RTT_PREAMBLE_SET(body->control_flag, WMI_RTT_PREAM_LEGACY);
        WMI_RTT_MEAS_NUM_SET(body->measure_info, 9);
    } else {
        WMI_RTT_PREAMBLE_SET(body->control_flag, WMI_RTT_PREAM_HT);
        WMI_RTT_BW_SET(body->control_flag, WMI_RTT_BW_40);
        WMI_RTT_MEAS_NUM_SET(body->measure_info, 10);
    }

    /*embed #2 req in measurement command, if you do not have #2 measurement,
     *please comment this part or (left these here will not stop your RTT but
     *will get failed measurement result)
     */
    p = (u_int8_t *) body;
    body++;
    memcpy(body, p, sizeof(wmi_rtt_measreq_body));
    if(!(req_id & 0x1)) {//even req id
        /* peer[5] = 0xC8;
        peer[4] = 0xEF;
        peer[3] = 0x04;
        peer[2] = 0x6C;
        peer[1] = 0x24;
        peer[0] = 0x00;*/
		peer[5] = 0x37;//02;
        peer[4] = 0x00;//7E;
        peer[3] = 0x04;//7D;
        peer[2] = 0x7F;//86;
        peer[1] = 0x03;//0B;
        peer[0] = 0x00;     
        WMI_CHAR_ARRAY_TO_MAC_ADDR(((A_UINT8 *)peer),&body->dest_mac);
        WMI_CHAR_ARRAY_TO_MAC_ADDR(((A_UINT8 *)peer),&body->spoof_bssid); 
        body->measure_info &= ~(0x0000ff00);  //clear measurement times
        //set measurement times 
        WMI_RTT_MEAS_NUM_SET(body->measure_info, 9);
        //set Preamble Legacy
        WMI_RTT_PREAMBLE_SET(body->control_flag, WMI_RTT_PREAM_HT);
        //set report type
        WMI_RTT_REPORT_TYPE_SET(body->measure_info, WMI_RTT_REPORT_CFR);
        //set BW
        WMI_RTT_BW_SET(body->control_flag, WMI_RTT_BW_20);
    } else {//odd req id
        /* peer[5] = 0xC8;
        peer[4] = 0xEF;
        peer[3] = 0x04;
        peer[2] = 0x6C;
        peer[1] = 0x24;
        peer[0] = 0x00;*/
		peer[5] = 0x37;//02;
        peer[4] = 0x00;//7E;
        peer[3] = 0x04;//7D;
        peer[2] = 0x7F;//86;
        peer[1] = 0x03;//0B;
        peer[0] = 0x00;
		
        WMI_CHAR_ARRAY_TO_MAC_ADDR(((A_UINT8 *)peer),&body->dest_mac);
        WMI_CHAR_ARRAY_TO_MAC_ADDR(((A_UINT8 *)peer),&body->spoof_bssid); 
        body->measure_info &= ~(0x0000ff00);  //clear measurement times
        //set measurement times 
        WMI_RTT_MEAS_NUM_SET(body->measure_info, 10);
        //set Preamble Legacy
        WMI_RTT_PREAMBLE_SET(body->control_flag, WMI_RTT_PREAM_VHT);
        //set report CFR
        WMI_RTT_REPORT_TYPE_SET(body->measure_info, WMI_RTT_REPORT_CFR);
        WMI_RTT_BW_SET(body->control_flag, WMI_RTT_BW_40);
    }

    /*embed #3 req in measurement command, if you do not have #2 measurement,
     *please comment this part or (left these here will not stop your RTT but
     *will get failed measurement result)
     */
    body++;
    memcpy(body, p, sizeof(wmi_rtt_measreq_body));
    if(!(req_id & 0x1)) {//even req id
        //encode second body   unassociated case
        /* peer[5] = 0xC8;
        peer[4] = 0xEF;
        peer[3] = 0x04;
        peer[2] = 0x6C;
        peer[1] = 0x24;
        peer[0] = 0x00;*/
		peer[5] = 0x37;//02;
        peer[4] = 0x00;//7E;
        peer[3] = 0x04;//7D;
        peer[2] = 0x7F;//86;
        peer[1] = 0x03;//0B;
        peer[0] = 0x00;
		
        WMI_CHAR_ARRAY_TO_MAC_ADDR(((A_UINT8 *)peer),&body->dest_mac);
        WMI_CHAR_ARRAY_TO_MAC_ADDR(((A_UINT8 *)peer),&body->spoof_bssid); 
        body->measure_info &= ~(0x0000ff00);  //clear measurement times
        //set measurement times 
        WMI_RTT_MEAS_NUM_SET(body->measure_info, 9);
        //set Preamble Legacy
        WMI_RTT_PREAMBLE_SET(body->control_flag, WMI_RTT_PREAM_VHT);
        //set report type
        WMI_RTT_REPORT_TYPE_SET(body->measure_info, WMI_RTT_REPORT_CFR);
        //set BW
        WMI_RTT_BW_SET(body->control_flag, WMI_RTT_BW_20);
    } else {//odd req id
        /* peer[5] = 0xC8;
        peer[4] = 0xEF;
        peer[3] = 0x04;
        peer[2] = 0x6C;
        peer[1] = 0x24;
        peer[0] = 0x00;*/
		peer[5] = 0x37;//02;
        peer[4] = 0x00;//7E;
        peer[3] = 0x04;//7D;
        peer[2] = 0x7F;//86;
        peer[1] = 0x03;//0B;
        peer[0] = 0x00;
		
        WMI_CHAR_ARRAY_TO_MAC_ADDR(((A_UINT8 *)peer),&body->dest_mac);
        WMI_CHAR_ARRAY_TO_MAC_ADDR(((A_UINT8 *)peer),&body->spoof_bssid); 
        body->measure_info &= ~(0x0000ff00);  //clear measurement times
        //set measurement times 
        WMI_RTT_MEAS_NUM_SET(body->measure_info, 10);
        //set Preamble Legacy
        WMI_RTT_PREAMBLE_SET(body->control_flag, WMI_RTT_PREAM_VHT);
        //set report CFR
        WMI_RTT_REPORT_TYPE_SET(body->measure_info, WMI_RTT_REPORT_CFR);
        WMI_RTT_BW_SET(body->control_flag, WMI_RTT_BW_80);
    }
    ret = wmi_unified_cmd_send(wmi_handle, buf, len, WMI_RTT_MEASREQ_CMDID);
    adf_os_print("send rtt cmd to FW with length %d and return %d\n", len, ret);
    req_id++;
}

/*
 * Send Keepalive command to FW to probe a single associated station.
 * Make sure the client is awake before sending RTT measurement command.
 */
void
ol_ath_rtt_keepalive_req(wmi_unified_t wmi_handle, struct ieee80211vap *vap,
                         struct ieee80211_node *ni, bool stop)
{
    static u_int16_t req_id = 1;
    wmi_buf_t buf;
    wmi_rtt_keepalive_cmd *cmd;
    int ret;
    u_int16_t len;
    u_int8_t *ptr;
    struct ieee80211com *ic = NULL;
    struct ol_ath_softc_net80211 *scn = NULL;
    
    if (!vap || !ni) {
        adf_os_print("%s: Invalid parameter\n", __func__);
        req_id++;
        return;
    }

    ic = ni->ni_ic;
    scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_handle = scn->wmi_handle;

    if (!wmi_handle || vap!=ni->ni_vap) {
        adf_os_print("%s: Invalid parameter\n", __func__);
        req_id++;
        return;
    }

    len = sizeof(wmi_rtt_keepalive_cmd);
    buf = wmi_buf_alloc(wmi_handle, len);
    if(!buf) {
        adf_os_print("No WMI resource\n");
        return;
    }

    ptr = (u_int8_t *)wmi_buf_data(buf);
    OS_MEMSET(ptr, 0, len);

    cmd = (wmi_rtt_keepalive_cmd *)wmi_buf_data(buf);

    WMI_RTT_REQ_ID_SET(cmd->req_id, req_id);
    WMI_RTT_KEEPALIVE_ACTION_SET(cmd->req_id, stop);
    WMI_RTT_VDEV_ID_SET(cmd->probe_info, (OL_ATH_VAP_NET80211(vap))->av_if_id);
    /* 3ms probe interval by default */
    WMI_RTT_KEEPALIVE_PERIOD_SET(cmd->probe_info, 3);
    /* max retry of 50 by default */
    WMI_RTT_TIMEOUT_SET(cmd->probe_info, 20);
    /* set frame type */
    WMI_RTT_FRAME_TYPE_SET(cmd->control_flag, RTT_MEAS_FRAME_KEEPALIVE);

    WMI_CHAR_ARRAY_TO_MAC_ADDR(ni->ni_macaddr, &cmd->sta_mac);

    ret = wmi_unified_cmd_send(wmi_handle, buf, len, WMI_RTT_KEEPALIVE_CMDID);
    adf_os_print("send rtt keepalive cmd to FW with length %d and return %d\n", len, ret);
    req_id++;

    return; 
} 
