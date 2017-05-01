/*-
 * Copyright (c) 2005 Sam Leffler, Errno Consulting
 * Copyright (c) 2010 Atheros Communications, Inc.
 * All rights reserved.
 */
/*
 * Copyright (c) 2013 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * Notifications and licenses are retained for attribution purposes only.
 */

/*
 * athdbg athX cmd args
 */
#include <sys/types.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/types.h>
#include <linux/if.h>
#include <linux/wireless.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <getopt.h>
#include <glob.h>           /* Including glob.h for glob() function used in find_pid() */
#include <signal.h>


/*
 * Linux uses __BIG_ENDIAN and __LITTLE_ENDIAN while BSD uses _foo
 * and an explicit _BYTE_ORDER.  Sorry, BSD got there first--define
 * things in the BSD way...
 */
#ifndef _LITTLE_ENDIAN
#define	_LITTLE_ENDIAN	1234	/* LSB first: i386, vax */
#endif
#ifndef _BIG_ENDIAN
#define	_BIG_ENDIAN	4321	/* MSB first: 68000, ibm, net */
#endif
#include <asm/byteorder.h>
#if defined(__LITTLE_ENDIAN)
#define	_BYTE_ORDER	_LITTLE_ENDIAN
#elif defined(__BIG_ENDIAN)
#define	_BYTE_ORDER	_BIG_ENDIAN
#else
#error "Please fix asm/byteorder.h"
#endif

/*
** Need to find proper references in UMAC code
*/

#include "os/linux/include/ieee80211_external.h"

#define	streq(a,b)	(strncasecmp(a,b,sizeof(b)-1) == 0)

#define TSPECTOTIME(tspec,tmval,buffer)                           \
    tzset();                                                      \
    if (localtime_r(&(tspec.tv_sec), &tmval) == NULL)             \
        return ;                                                  \
    strftime(buffer, sizeof(buffer),"%Y-%m-%d %H:%M:%S %Z", &tmval)


static void
usage(void)
{
	fprintf(stderr, "usage: wifitool athX cmd args\n");
	fprintf(stderr, "cmd: [sendaddba senddelba setaddbaresp getaddbastats  sendaddts senddelts  \n");
    fprintf(stderr, "cmd: [sendtsmrpt sendneigrpt sendlmreq sendbstmreq  sendbcnrpt ] \n");
    fprintf(stderr, "cmd: [sendstastats sendchload sendnhist sendlcireq rrmstats bcnrpt setchanlist getchanlist] \n");
    fprintf(stderr, "cmd: [block_acs_channel] \n");
    fprintf(stderr, "cmd: [rrm_sta_list] \n");
    fprintf(stderr, "cmd: [mu_scan lteu_cfg ap_scan] \n");
    fprintf(stderr, "cmd: [tr069_chanhist] \n");
    fprintf(stderr, "cmd: [tr069_chan_inuse] \n");
    fprintf(stderr, "cmd: [tr069_set_oper_rate] \n");
    fprintf(stderr, "cmd: [tr069_get_oper_rate] \n");
    fprintf(stderr, "cmd: [tr069_get_posiblrate] \n");
    fprintf(stderr, "cmd: [bsteer_getparams bsteer_setparams] \n");
    fprintf(stderr, "cmd: [bsteer_getdbgparams bsteer_setdbgparams] \n");
    fprintf(stderr, "cmd: [bsteer_enable] \n");
    fprintf(stderr, "cmd: [bsteer_getoverload bsteer_setoverload] \n");
    fprintf(stderr, "cmd: [bsteer_getrssi] \n");
    fprintf(stderr, "cmd: [bsteer_setproberespwh bsteer_getproberespwh] \n");
	exit(-1);
}

static void
usage_setchanlist(void)
{
 	fprintf(stderr, "usage: wifitool athX setchanlist ch1 ch2 .....n \n");
}

static void
usage_getchanlist(void)
{
 	fprintf(stderr, "usage: wifitool athX getchanlist \n");
}
static void
usage_getrrrmstats(void)
{
   fprintf(stderr, "usage: wifitool athX get_rrmstats  [dstmac]\n");
   fprintf(stderr, "[dstmac] - stats reported by the given station\n");
}
static void
usage_getrssi(void)
{
 	fprintf(stderr, "usage: wifitool athX get_rssi  [dstmac]\n");
	fprintf(stderr, "[dstmac] - stats reported by the given station\n");
}
static void
usage_acsreport(void)
{
 	fprintf(stderr, "usage: wifitool athX acsreport\n");
}
static void usage_sendfrmreq(void)
{
   fprintf(stderr, "usage: wifitool athX sendfrmreq  <dstmac> <n_rpts> <reg_class> <chnum> \n");
   fprintf(stderr, "<rand_invl> <mandatory_duration> <req_type> <ref mac> \n");
   exit(-1);
}

static void
usage_sendlcireq(void)
{
   fprintf(stderr, "usage: wifitool athX sendlcireq  <dstmac> <location> <latitude_res> <longitude_res> \n");
   fprintf(stderr, "<altitude_res> [azimuth_res] [azimuth_type]\n");
   fprintf(stderr, "<dstmac> - MAC address of the receiving station \n");
   fprintf(stderr, "<location> - location of requesting/reporting station \n");
   fprintf(stderr, "<latitude_res> - Number of most significant bits(max 34) for fixed-point value of latitude \n");
   fprintf(stderr, "<longitude_res> - Number of most significant bits(max 34) for fixed-point value of longitude\n");
   fprintf(stderr, "<altitude_res> - Number of most significant bits(max 30) for fixed-point value of altitude\n");
   fprintf(stderr, "<azimuth_res> -  Number of most significant bits(max 9) for fixed-point value of Azimuth\n");
   fprintf(stderr, "<azimuth_type> - specifies report of azimuth of radio reception(0) or front surface(1) of reporting station\n");
   exit(-1);
}

static void
usage_sendchloadrpt(void)
{
   fprintf(stderr, "usage: wifitool athX sendchload  <dstmac> <n_rpts> <reg_class> <chnum> \n");
   fprintf(stderr, "<rand_invl> <mandatory_duration> <optional_condtion> <condition_val>\n");
   exit(-1);
}

static void
usage_sendnhist(void)
{
   fprintf(stderr, "usage: wifitool athX sendnhist  <dstmac> <n_rpts> <reg_class> <chnum> \n");
   fprintf(stderr, "<rand_invl> <mandator_duration> <optional_condtion> <condition_val>\n");
   exit(-1);
}

static void
usage_sendstastatsrpt(void)
{
   fprintf(stderr, "usage: wifitool athX sendstastats  <dstmac> <duration> <gid>\n");
   exit(-1);
}

static void
usage_rrmstalist(void)
{
        fprintf(stderr, "usage: wifitool athX rrm_sta_list \n");
        exit(-1);
}

static void
usage_sendaddba(void)
{
   fprintf(stderr, "usage: wifitool athX sendaddba <aid> <tid> <buffersize>\n");
   exit(-1);
}


static void
usage_senddelba(void)
{
   fprintf(stderr, "usage: wifitool athX senddelba <aid> <tid> <initiator> <reasoncode> \n");
   exit(-1);
}

static void
usage_setaddbaresp(void)
{
   fprintf(stderr, "usage: wifitool athX setaddbaresp <aid> <tid> <statuscode> \n");
   exit(-1);
}

static void
usage_sendsingleamsdu(void)
{
   fprintf(stderr, "usage: wifitool athX sendsingleamsdu <aid> <tid> \n");
   exit(-1);
}


static void
usage_getaddbastats(void)
{
   fprintf(stderr, "usage: wifitool athX setaddbaresp <aid> <tid> \n");
   exit(-1);
}

static void
usage_sendbcnrpt(void)
{
   fprintf(stderr, "usage: wifitool athX sendbcnrpt <dstmac> <regclass> <channum> \n");
   fprintf(stderr, "       <rand_ivl> <duration> <mode> \n");
   fprintf(stderr, "       <req_ssid> <rep_cond> <rpt_detail>\n");
   fprintf(stderr, "       <req_ie> <chanrpt_mode> \n");
   fprintf(stderr, "       req_ssid = 1 for ssid, 2 for wildcard ssid \n");
   exit(-1);
}

static void
usage_sendtsmrpt(void)
{
   fprintf(stderr, "usage: wifitool athX sendtsmrpt <num_rpt> <rand_ivl> <meas_dur>\n");
   fprintf(stderr, "       <tid> <macaddr> <bin0-range> <trig_cond> \n");
   fprintf(stderr, "       <avg_err_thresh> <cons_err_thresh> <delay_thresh> <trig_timeout>\n");
   exit(-1);
}

static void
usage_sendneigrpt(void)
{
   fprintf(stderr, "usage: wifitool athX sendneigrpt <mac_addr> <ssid> <dialog_token> \n");
   exit(-1);
}

static void
usage_sendlmreq(void)
{
   fprintf(stderr, "usage: wifitool athX sendlmreq <mac_addr> \n");
   exit(-1);
}

static void
usage_sendbstmreq(void)
{
   fprintf(stderr, "usage: wifitool athX sendbstmreq <mac_addr> <candidate_list> <disassoc> <validityItrv>\n");
   exit(-1);
}

static void
usage_senddelts(void)
{
   fprintf(stderr, "usage: wifitool athX senddelts <mac_addr> <tid> \n");
   exit(-1);
}

static void
usage_sendaddts(void)
{
   fprintf(stderr, "usage: wifitool athX sendaddts <mac_addr> <tid> <dir> <up>\
           <nominal_msdu> <mean_data_rate> <mean_phy_rate> <surplus_bw>\
                             <uapsd-bit> <ack_policy> <max_burst_size>\n");
   exit(-1);
}

static void
usage_tr069chanhist(void)
{
    fprintf(stderr, "usage: wifitool athX tr069_chanhist\n");
}
static void
usage_tr069_txpower(void)
{
    fprintf(stderr, "usage: wifitool athX tr069_txpower Power(in percentage)\n");
}
static void
usage_tr069_gettxpower(void)
{
    fprintf(stderr, "usage: wifitool athX tr069_gettxpower \n");
}
static void
usage_tr069_guardintv(void)
{
     fprintf(stderr, "usage: wifitool athX tr069_guardintv time(in nanoseconds) (800 or 0 for auto)\n");
}
static void
usage_tr069_get_guardintv(void)
{
     fprintf(stderr, "usage: wifitool athX tr069_get_guardintv \n");
}
static void
usage_tr069_getassocsta(void)
{
      fprintf(stderr, "usage: wifitool athX tr069_getassocsta \n");
}
static void
usage_tr069_gettimestamp(void)
{
     fprintf(stderr, "usage: wifitool athX tr069_gettimestamp \n");
}
static void
usage_tr069_getacsscan(void)
{
     fprintf(stderr, "usage: wifitool athX tr069_getacsscan (1 to issue a scan and 0 to know the result of scan) \n");
}
static void
usage_tr069_perstastatscount(void)
{
     fprintf(stderr, "usage: wifitool athX tr069_persta_statscount \n");
}
static void
usage_tr069_get11hsupported(void)
{
     fprintf(stderr, "usage: wifitool athX tr069_get_11hsupported \n");
}
static void
usage_tr069_getpowerrange(void)
{
     fprintf(stderr, "usage: wifitool athX tr069_get_powerrange \n");
}

static void
usage_tr069_chan_inuse(void)
{
    fprintf(stderr, "usage: wifitool athX tr069_chan_inuse\n");
}

static void
usage_tr069_setoper_rate(void)
{
    fprintf(stderr, "usage: wifitool athX tr069_setoper_rate rate1,rate2, .....n \n");
}

static void
usage_tr069_getoper_rate(void)
{
    fprintf(stderr, "usage: wifitool athX tr069_getoper_rate \n");
}

static void
usage_tr069_getposiblrate(void)
{
    fprintf(stderr, "usage: wifitool athX tr069_getposiblrate \n");
}

static void
usage_tr069_getsupportedfrequency(void)
{
    fprintf(stderr, "usage: wifitool athX supported_freq \n");
}

static void
usage_bsteer_getparams(void)
{
    fprintf(stderr, "usage: wifitool athX bsteer_getparams \n");
}
static void
usage_bsteer_setparams(void)
{
    fprintf(stderr, "usage: wifitool athX bsteer_setparams <inact_normal> "
                    "<inact_overload> <util_sample_period> "
                    "<util_average_num_samples> "
                    "<rssi_crossing_threshold> "
                    "<inactive_rssi_crossing_threshold> "
                    "<inact_check_period>\n");
}

static void
usage_bsteer_getdbgparams(void)
{
    fprintf(stderr, "usage: wifitool athX bsteer_getdbgparams \n");
}

static void
usage_bsteer_setdbgparams(void)
{
    fprintf(stderr, "usage: wifitool athX bsteer_setdbgparams "
                    "<raw_chan_util_log_enable> "
                    "<raw_rssi_log_enable>\n");
}

static void
usage_bsteer_enable(void)
{
    fprintf(stderr, "Usage: wifitool athX bsteer_enable <enable_flag>\n");
}

static void
usage_bsteer_setoverload(void)
{
    fprintf(stderr, "Usage: wifitool athX bsteer_setoverload <overload_flag>\n");
}

static void
usage_bsteer_getoverload(void)
{
    fprintf(stderr, "Usage: wifitool athX bsteer_getoverload\n");
}

static void
usage_bsteer_getrssi(void)
{
    fprintf(stderr, "Usage: wifitool athX bsteer_getrssi <dstmac> <num_samples>\n");
}
/*
 * Parse event sent using wireless_send_event()
 */
static void
get_next_wireless_custom_event(int event)
{
    int sock;
    struct sockaddr_nl local;
    struct sockaddr_nl from;
    socklen_t fromlen;
    int len;
    char buf[8192];
    struct nlmsghdr *h;
    int done, count;

    sock = socket(PF_NETLINK, SOCK_RAW, NETLINK_ROUTE);
    if (sock < 0) {
        perror("socket:\n");
        return;
    }

    memset(&local, 0, sizeof(local));
    local.nl_family = AF_NETLINK;
    local.nl_groups = RTMGRP_LINK;
    if (bind(sock, (struct sockaddr *)&local, sizeof(local)) < 0) {
        perror("bind:\n");
        close(sock);
        return;
    }

    count = 0;

again:
    done = 0;
    memset(&from, 0, sizeof(from));
    fromlen = sizeof(from);
    len = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *)&from, &fromlen);
    if (len < 0) {
        perror("recvfrom:\n");
        close(sock);
        return;
    }

    h = (struct nlmsghdr *)buf;
    while (NLMSG_OK(h, len)) {
        struct ifinfomsg *ifi;
        if (h->nlmsg_type != RTM_NEWLINK) {
            h = NLMSG_NEXT(h, len);
            continue;
        }
        ifi = NLMSG_DATA(h);
        if (NLMSG_PAYLOAD(h, 0) >= sizeof(struct ifinfomsg)) {
            struct rtattr *attr = (struct rtattr *)((char *)NLMSG_DATA(h) + NLMSG_ALIGN(sizeof(struct ifinfomsg)));
            int attrlen = NLMSG_PAYLOAD(h, sizeof(struct ifinfomsg));
            int rlen = RTA_ALIGN(sizeof(struct rtattr));
            while (RTA_OK(attr, attrlen)) {
                struct iw_event iwe;
                char *start;
                char *end;
                if (attr->rta_type != IFLA_WIRELESS) {
                    attr = RTA_NEXT(attr, attrlen);
                    continue;
                }
                start = ((char *)attr) + rlen;
                end = start + (attr->rta_len - rlen);
                while (start + IW_EV_LCP_LEN <= end) {
                    memcpy(&iwe, start, IW_EV_LCP_LEN);
                    if (iwe.len <= IW_EV_LCP_LEN) {
                        break;
                    }
                    if (iwe.cmd == IWEVCUSTOM) {
                        char *pos = (char *)&iwe.u.data.length;
                        char *data = start + IW_EV_POINT_LEN;
                        memcpy(pos, start + IW_EV_LCP_LEN, sizeof(struct iw_event) - (pos - (char *)&iwe));
                        if (data + iwe.u.data.length <= end) {
                            if (event == IEEE80211_EV_SCAN && iwe.u.data.flags == event &&
                                iwe.u.data.length >= sizeof(struct event_data_scan)) {
                                struct event_data_scan *scan = (struct event_data_scan *)data;
                                printf("Scan completion event:\n");
                                printf("req_id=%d\n", scan->scan_req_id);
                                printf("status=%d\n", scan->scan_status);
                                done = 1;
                            } else if (event == IEEE80211_EV_MU_RPT && iwe.u.data.flags == event &&
                                       iwe.u.data.length >= sizeof(struct event_data_mu_rpt)) {
                                int i;
                                struct event_data_mu_rpt *mu_rpt = (struct event_data_mu_rpt *)data;
                                printf("MU report event:\n");
                                printf("req_id=%d\n", mu_rpt->mu_req_id);
                                printf("channel=%d\n", mu_rpt->mu_channel);
                                printf("status=%d\n", mu_rpt->mu_status);
                                for (i = 0; i < MU_MAX_ALGO; i++)
                                    printf("total_val[%d]=%d\n", i, mu_rpt->mu_total_val[i]);
                                printf("num_bssid=%d\n", mu_rpt->mu_num_bssid);
                                printf("actual_duration=%d\n", mu_rpt->mu_actual_duration);
                                done = 1;
                            }
                        }
                    }
                    start += iwe.len;
                }
                attr = RTA_NEXT(attr, attrlen);
            }
        }
        h = NLMSG_NEXT(h, len);
    }

    if (!done && ++count <= 5) {
        printf("Try to get event again\n");
        goto again;
    }

    close(sock);
}

static void
usage_bsteer_setproberespwh(void)
{
    fprintf(stderr, "Usage: wifitool athX bsteer_setproberespwh <dstmac> <enable_flag>\n");
}

static void
usage_bsteer_getproberespwh(void)
{
    fprintf(stderr, "Usage: wifitool athX bsteer_getproberespwh <dstmac>\n");
}

/*
 * Input an arbitrary length MAC address and convert to binary.
 * Return address size.
 */
int
wifitool_mac_aton(const char *  orig,
            unsigned char *     mac,
            int                 macmax)
{
  const char *  p = orig;
  int           maclen = 0;

  /* Loop on all bytes of the string */
  while(*p != '\0')
    {
      int       temph;
      int       templ;
      int       count;
      /* Extract one byte as two chars */
      count = sscanf(p, "%1X%1X", &temph, &templ);
      if(count != 2)
        break;                  /* Error -> non-hex chars */
      /* Output two chars as one byte */
      templ |= temph << 4;
      mac[maclen++] = (unsigned char) (templ & 0xFF);

      /* Check end of string */
      p += 2;
      if(*p == '\0')
        {
          return(maclen);               /* Normal exit */
        }

      /* Check overflow */
      if(maclen >= macmax)
        {
          fprintf(stderr, "maclen overflow \n");
          return(0);                    /* Error -> overflow */
        }

      /* Check separator */
      if(*p != ':')
        break;
      p++;
    }

  /* Error... */
  fprintf(stderr, "Invlaid macstring %s \n", orig);
  return(0);
}


static void
send_addba(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len;
    struct ieee80211req_athdbg req;
    if (argc < 6) {
        usage_sendaddba();
    }
    else {
        memset(&req, 0, sizeof(struct ieee80211req_athdbg));
        s = socket(AF_INET, SOCK_DGRAM, 0);
        (void) memset(&iwr, 0, sizeof(iwr));
        (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
        req.cmd = IEEE80211_DBGREQ_SENDADDBA;
        req.data.param[0] = atoi(argv[3]);
        req.data.param[1] = atoi(argv[4]);
        req.data.param[2] = atoi(argv[5]);
        iwr.u.data.pointer = (void *) &req;
        iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            errx(1, "unable to send addba");
        }
    }
    return;
}

static void
send_delba(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len;
    struct ieee80211req_athdbg req;
    if (argc < 7) {
        usage_senddelba();
    }
    else {
        memset(&req, 0, sizeof(struct ieee80211req_athdbg));
        s = socket(AF_INET, SOCK_DGRAM, 0);
        (void) memset(&iwr, 0, sizeof(iwr));
        (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
        req.cmd = IEEE80211_DBGREQ_SENDDELBA;
        req.data.param[0] = atoi(argv[3]);
        req.data.param[1] = atoi(argv[4]);
        req.data.param[2] = atoi(argv[5]);
        req.data.param[3] = atoi(argv[6]);
        iwr.u.data.pointer = (void *) &req;
        iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            errx(1, "unable to send delba");
        }
    }
    return;
}

static void
set_addbaresp(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len;
    struct ieee80211req_athdbg req;
    if (argc < 6) {
        usage_sendaddba();
    }
    else {
        memset(&req, 0, sizeof(struct ieee80211req_athdbg));
        s = socket(AF_INET, SOCK_DGRAM, 0);
        (void) memset(&iwr, 0, sizeof(iwr));
        (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
        req.cmd = IEEE80211_DBGREQ_SETADDBARESP;
        req.data.param[0] = atoi(argv[3]);
        req.data.param[1] = atoi(argv[4]);
        req.data.param[2] = atoi(argv[5]);
        iwr.u.data.pointer = (void *) &req;
        iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            errx(1, "unable to addba response");
        }
    }
    return;
}

static void
send_singleamsdu(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len;
    struct ieee80211req_athdbg req;
    if (argc < 5) {
        usage_sendsingleamsdu();
    }
    else {
        memset(&req, 0, sizeof(struct ieee80211req_athdbg));
        s = socket(AF_INET, SOCK_DGRAM, 0);
        (void) memset(&iwr, 0, sizeof(iwr));
        (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
        req.cmd = IEEE80211_DBGREQ_SENDSINGLEAMSDU;
        req.data.param[0] = atoi(argv[3]);
        req.data.param[1] = atoi(argv[4]);
        iwr.u.data.pointer = (void *) &req;
        iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            errx(1, "unable to send single AMSDU ");
        }
    }
    return;
}

static void
get_addbastats(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len;
    struct ieee80211req_athdbg req;
    if (argc < 5) {
        usage_getaddbastats();
    }
    else {
        memset(&req, 0, sizeof(struct ieee80211req_athdbg));
        s = socket(AF_INET, SOCK_DGRAM, 0);
        (void) memset(&iwr, 0, sizeof(iwr));
        (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
        req.cmd = IEEE80211_DBGREQ_GETADDBASTATS;
        req.data.param[0] = atoi(argv[3]);
        req.data.param[1] = atoi(argv[4]);
        iwr.u.data.pointer = (void *) &req;
        iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            errx(1, "unable to get addba stats");
        }
    }
    return;
}

    static void
send_bcnrpt(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len;
    struct ieee80211req_athdbg req;
    ieee80211_rrm_beaconreq_info_t* bcnrpt = &req.data.bcnrpt;
    int chan_rptmode = 0;
    if (argc < 14) {
        usage_sendbcnrpt();
    }
    else {
        memset(&req, 0, sizeof(struct ieee80211req_athdbg));
        s = socket(AF_INET, SOCK_DGRAM, 0);
        (void) memset(&iwr, 0, sizeof(iwr));
        (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
        req.cmd = IEEE80211_DBGREQ_SENDBCNRPT;
        if (!wifitool_mac_aton(argv[3], req.dstmac, 6)) {
            errx(1, "Invalid destination mac address");
            return;
        }
        bcnrpt->regclass = atoi(argv[4]);
        bcnrpt->channum = atoi(argv[5]);
        bcnrpt->random_ivl = atoi(argv[6]);
        bcnrpt->duration = atoi(argv[7]);
        bcnrpt->mode = atoi(argv[8]);
        bcnrpt->req_ssid = atoi(argv[9]);
        bcnrpt->rep_cond = atoi(argv[10]);
        bcnrpt->rep_detail = atoi(argv[11]);
        bcnrpt->req_ie = atoi(argv[12]);

        bcnrpt->bssid[0] = 0xff;
        bcnrpt->bssid[1] = 0xff;
        bcnrpt->bssid[2] = 0xff;
        bcnrpt->bssid[3] = 0xff;
        bcnrpt->bssid[4] = 0xff;
        bcnrpt->bssid[5] = 0xff;
        chan_rptmode = atoi(argv[13]);
        if (!chan_rptmode) {
            bcnrpt->num_chanrep = 0;
        }
        else {
            bcnrpt->num_chanrep = 2;
            bcnrpt->apchanrep[0].regclass = 12;
            bcnrpt->apchanrep[0].numchans = 2;
            bcnrpt->apchanrep[0].channum[0] = 1;
            bcnrpt->apchanrep[0].channum[1] = 6;
            bcnrpt->apchanrep[1].regclass = 1;
            bcnrpt->apchanrep[1].numchans = 2;
            bcnrpt->apchanrep[1].channum[0] = 36;
            bcnrpt->apchanrep[1].channum[1] = 48;
        }
        iwr.u.data.pointer = (void *) &req;
        iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            errx(1, "IEEE80211_IOCTL_DBGREQ failed");
        }
    }
    return;
}

static void
send_tsmrpt(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len;
    struct ieee80211req_athdbg req;
    ieee80211_rrm_tsmreq_info_t *tsmrpt = &req.data.tsmrpt;
    if (argc < 14) {
        usage_sendtsmrpt();
    }
    else {
        memset(&req, 0, sizeof(struct ieee80211req_athdbg));
        s = socket(AF_INET, SOCK_DGRAM, 0);
        (void) memset(&iwr, 0, sizeof(iwr));
        (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
        req.cmd = IEEE80211_DBGREQ_SENDTSMRPT;
        tsmrpt->num_rpt = atoi(argv[3]);
        tsmrpt->rand_ivl = atoi(argv[4]);
        tsmrpt->meas_dur = atoi(argv[5]);
        tsmrpt->tid = atoi(argv[6]);
        if (!wifitool_mac_aton(argv[7], tsmrpt->macaddr, 6)) {
            errx(1, "Invalid mac address");
            return;
        }
        tsmrpt->bin0_range = atoi(argv[8]);
        tsmrpt->trig_cond = atoi(argv[9]);
        tsmrpt->avg_err_thresh = atoi(argv[10]);
        tsmrpt->cons_err_thresh = atoi(argv[11]);
        tsmrpt->delay_thresh = atoi(argv[12]);
        tsmrpt->trig_timeout = atoi(argv[13]);
        memcpy(req.dstmac, tsmrpt->macaddr, 6);
        iwr.u.data.pointer = (void *) &req;
        iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            errx(1, "IEEE80211_IOCTL_DBGREQ: IEEE80211_DBGREQ_SENDTSMRPT failed");
        }
    }
    return;
}

static void
send_neigrpt(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len;
    struct ieee80211req_athdbg req;
    ieee80211_rrm_nrreq_info_t *neigrpt = &req.data.neigrpt;
    if (argc < 5) {
        usage_sendneigrpt();
    }
    else {
        memset(&req, 0, sizeof(struct ieee80211req_athdbg));
        s = socket(AF_INET, SOCK_DGRAM, 0);
        (void) memset(&iwr, 0, sizeof(iwr));
        (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
        req.cmd = IEEE80211_DBGREQ_SENDNEIGRPT;
        if (!wifitool_mac_aton(argv[3], req.dstmac, 6)) {
            errx(1, "Invalid destination mac address");
            return;
        }
        strncpy((char *)neigrpt->ssid, argv[4],sizeof(neigrpt->ssid));
        neigrpt->ssid_len = strlen((char *)neigrpt->ssid);
        neigrpt->dialogtoken = atoi(argv[5]);
        iwr.u.data.pointer = (void *) &req;
        iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            errx(1, "IEEE80211_IOCTL_DBGREQ: IEEE80211_DBGREQ_SENDNEIGRPT failed");
        }
    }
    return;
}

static void
send_lmreq(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len;
    struct ieee80211req_athdbg req;
    if (argc < 4) {
        usage_sendlmreq();
    }
    else {
        memset(&req, 0, sizeof(struct ieee80211req_athdbg));
        s = socket(AF_INET, SOCK_DGRAM, 0);
        (void) memset(&iwr, 0, sizeof(iwr));
        (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
        req.cmd = IEEE80211_DBGREQ_SENDLMREQ;
        if (!wifitool_mac_aton(argv[3], req.dstmac, 6)) {
            errx(1, "Invalid destination mac address");
            return;
        }
        iwr.u.data.pointer = (void *) &req;
        iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            errx(1, "IEEE80211_IOCTL_DBGREQ: IEEE80211_DBGREQ_SENDLMREQ failed");
        }
    }
    return;
}

static void
send_bstmreq(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len;
    struct ieee80211req_athdbg req;
    struct ieee80211_bstm_reqinfo* reqinfo = &req.data.bstmreq;
    if (argc < 7) {
        usage_sendbstmreq();
    }
    else {
        memset(&req, 0, sizeof(struct ieee80211req_athdbg));
        s = socket(AF_INET, SOCK_DGRAM, 0);
        (void) memset(&iwr, 0, sizeof(iwr));
        (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
        req.cmd = IEEE80211_DBGREQ_SENDBSTMREQ;
        if (!wifitool_mac_aton(argv[3], req.dstmac, 6)) {
            errx(1, "Invalid destination mac address");
            return;
        }
        reqinfo->dialogtoken = 1;
        reqinfo->candidate_list = atoi(argv[4]);
        reqinfo->disassoc = atoi(argv[5]);
        reqinfo->validity_itvl = atoi(argv[6]);
        iwr.u.data.pointer = (void *) &req;
        iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            errx(1, "IEEE80211_IOCTL_DBGREQ: IEEE80211_DBGREQ_SENDBSTMREQ failed");
        }
    }
    return;
}

static void
send_delts(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len;
    struct ieee80211req_athdbg req;
    if (argc < 5) {
        usage_senddelts();
    }
    else {
        memset(&req, 0, sizeof(struct ieee80211req_athdbg));
        s = socket(AF_INET, SOCK_DGRAM, 0);
        (void) memset(&iwr, 0, sizeof(iwr));
        (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
        req.cmd = IEEE80211_DBGREQ_SENDDELTS;
        if (!wifitool_mac_aton(argv[3], req.dstmac, 6)) {
            errx(1, "Invalid destination mac address");
            return;
        }
        req.data.param[0] = atoi(argv[4]);
        iwr.u.data.pointer = (void *) &req;
        iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            errx(1, "unable to delts");
        }
    }
    return;
}

static void
send_addts(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len;
    struct ieee80211req_athdbg req;
    ieee80211_tspec_info* tsinfo = &req.data.tsinfo;
    if (argc < 13) {
        usage_sendaddts();
    }
    else {
        memset(&req, 0, sizeof(struct ieee80211req_athdbg));
        s = socket(AF_INET, SOCK_DGRAM, 0);
        (void) memset(&iwr, 0, sizeof(iwr));
        (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
        req.cmd = IEEE80211_DBGREQ_SENDADDTSREQ;
        if (!wifitool_mac_aton(argv[3], req.dstmac, 6)) {
            errx(1, "Invalid destination mac address");
            return;
        }
        tsinfo->tid = atoi(argv[4]);
        tsinfo->direction = atoi(argv[5]);
        tsinfo->dot1Dtag = atoi(argv[6]);
        tsinfo->norminal_msdu_size = atoi(argv[7]);
        tsinfo->mean_data_rate = atoi(argv[8]);
        tsinfo->min_phy_rate = atoi(argv[9]);
        tsinfo->surplus_bw = atoi(argv[10]);
        tsinfo->psb = atoi(argv[11]);
        tsinfo->ack_policy = atoi(argv[12]);
        tsinfo->max_burst_size = atoi(argv[13]);
		tsinfo->acc_policy_edca = 1;
        iwr.u.data.pointer = (void *) &req;
        iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            errx(1, "unable to send ADDTS REQ");
        }
    }
    return;
}

static void
send_noisehistogram(const char *ifname, int argc, char *argv[])
{
    int s, len;
    struct iwreq iwr;
    struct ieee80211req_athdbg req;
    ieee80211_rrm_nhist_info_t *nhist = &req.data.nhist;

    if ((argc < 9) || (argc > 11)) {
        usage_sendnhist();
    }
    else {
        memset(&req, 0, sizeof(struct ieee80211req_athdbg));
        s = socket(AF_INET, SOCK_DGRAM, 0);
        (void) memset(&iwr, 0, sizeof(iwr));
        (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
        req.cmd = IEEE80211_DBGREQ_SENDNHIST;
        if (!wifitool_mac_aton(argv[3], nhist->dstmac, 6)) {
            errx(1, "Invalid mac address");
            return;
        }
        nhist->num_rpts = atoi(argv[4]);
        nhist->regclass = atoi(argv[5]);
        nhist->chnum = atoi(argv[6]);
        nhist->r_invl = atoi(argv[7]);
        nhist->m_dur  = atoi(argv[8]);
        if(argc > 9 ) { /*optional element */
            nhist->cond  = atoi(argv[9]);
            nhist->c_val  = atoi(argv[10]);
        }
        memcpy(req.dstmac, nhist->dstmac, 6);
        iwr.u.data.pointer = (void *) &req;
        iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            errx(1, "IEEE80211_IOCTL_DBGREQ: IEEE80211_DBGREQ_SENDNHISTT failed");
        }
    }
    return;
}
void print_rrmstats(FILE *fd,
                    ieee80211_rrmstats_t *rrmstats,int unicast)
{
   u_int32_t chnum=0, i;
   u_int8_t buf[80];
   ieee80211_rrm_noise_data_t  noise_invalid;
   ieee80211_rrm_noise_data_t  *noise_dptr;
   ieee80211_rrm_lci_data_t    *lci_info;
   ieee80211_rrm_statsgid0_t   *gid0;
   ieee80211_rrm_statsgid10_t  *gid10;
   ieee80211_rrm_statsgid1_t   *gid1;
   ieee80211_rrm_statsgidupx_t *gidupx;
   ieee80211_rrm_tsm_data_t    *tsmdata;
   ieee80211_rrm_lm_data_t     *lmdata;
   ieee80211_rrm_frmcnt_data_t *frmcnt;


   memset(&noise_invalid, 0x0, sizeof(ieee80211_rrm_noise_data_t));


   if(!unicast ) {
       fprintf(fd, "Channel# Chan_load \tANPI\t\tIPI[0 - 11]");
       for (chnum = 0; chnum < IEEE80211_RRM_CHAN_MAX;chnum++)
       {
           if (rrmstats->noise_data[chnum].anpi != 0 || rrmstats->chann_load[chnum] != 0)
               {
                   fprintf(fd,"\n");
                   fprintf(fd ,"%d\t ",chnum);
                   fprintf(fd ,"%d \t\t",rrmstats->chann_load[chnum]);
                   fprintf(fd, "%d\t\t ",rrmstats->noise_data[chnum].anpi);
                   noise_dptr = &rrmstats->noise_data[chnum];
                   for (i = 0; i < 11; i++)
                   {
                       fprintf(fd, "%d, ", noise_dptr->ipi[i]);
                   }
               }
       }
       fprintf(fd,"\n");
   }else {
       lci_info = &rrmstats->ni_rrm_stats.ni_vap_lciinfo;
       fprintf(fd, "\n");
       fprintf(fd, "LCI local information :\n");
       fprintf(fd, "--------------------\n");
       fprintf(fd, "\t\t latitude %d.%d longitude %d.%d Altitude %d.%d\n", lci_info->lat_integ,
               lci_info->lat_frac, lci_info->alt_integ, lci_info->alt_frac,
               lci_info->alt_integ, lci_info->alt_frac);
       lci_info = &rrmstats->ni_rrm_stats.ni_rrm_lciinfo;
       fprintf(fd, "\n");
       fprintf(fd, "LCI local information :\n");
       fprintf(fd, "--------------------\n");
       fprintf(fd, "\t\t latitude %d.%d longitude %d.%d Altitude %d.%d\n", lci_info->lat_integ,
               lci_info->lat_frac, lci_info->alt_integ, lci_info->alt_frac,
               lci_info->alt_integ, lci_info->alt_frac);
       gid0 = &rrmstats->ni_rrm_stats.gid0;
       fprintf(fd, "GID0 stats: \n");
       fprintf(fd, "\t\t txfragcnt %d mcastfrmcnt %d failcnt %d rxfragcnt %d mcastrxfrmcnt %d \n",
               gid0->txfragcnt, gid0->mcastfrmcnt, gid0->failcnt,gid0->rxfragcnt,gid0->mcastrxfrmcnt);
       fprintf(fd, "\t\t fcserrcnt %d  txfrmcnt %d\n",  gid0->fcserrcnt, gid0->txfrmcnt);
       gid1 = &rrmstats->ni_rrm_stats.gid1;
       fprintf(fd, "GID1 stats: \n");
       fprintf(fd, "\t\t rty %d multirty %d frmdup %d rtsuccess %d rtsfail %d ackfail %d\n", gid1->rty, gid1->multirty,gid1->frmdup,
               gid1->rtsuccess, gid1->rtsfail, gid1->ackfail);
       for (i = 0; i < 8; i++)
       {
           gidupx = &rrmstats->ni_rrm_stats.gidupx[i];
           fprintf(fd, "dup stats[%d]: \n", i);
           fprintf(fd, "\t\t qostxfragcnt %d qosfailedcnt %d qosrtycnt %d multirtycnt %d\n"
                   "\t\t qosfrmdupcnt %d qosrtssuccnt %d qosrtsfailcnt %d qosackfailcnt %d\n"
                   "\t\t qosrxfragcnt %d qostxfrmcnt %d qosdiscadrfrmcnt %d qosmpdurxcnt %d qosrtyrxcnt %d \n",
                   gidupx->qostxfragcnt,gidupx->qosfailedcnt,
                   gidupx->qosrtycnt,gidupx->multirtycnt,gidupx->qosfrmdupcnt,
                   gidupx->qosrtssuccnt,gidupx->qosrtsfailcnt,gidupx->qosackfailcnt,
                   gidupx->qosrxfragcnt,gidupx->qostxfrmcnt,gidupx->qosdiscadrfrmcnt,
                   gidupx->qosmpdurxcnt,gidupx->qosrtyrxcnt);
       }
       gid10 = &rrmstats->ni_rrm_stats.gid10;
       fprintf(fd, "GID10 stats: \n", i);
       fprintf(fd, "\t\tap_avg_delay %d be_avg_delay %d bk_avg_delay %d\n",
               "vi_avg_delay %d vo_avg_delay %d st_cnt %d ch_util %d\n",
               gid10->ap_avg_delay,gid10->be_avg_delay,gid10->bk_avg_delay,
               gid10->vi_avg_delay,gid10->vo_avg_delay,gid10->st_cnt,gid10->ch_util);
       tsmdata = &rrmstats->ni_rrm_stats.tsm_data;
       fprintf(fd, "TSM data : \n");
       fprintf(fd, "\t\ttid %d brange %d mac:%02x:%02x:%02x:%02x:%02x:%02x tx_cnt %d\n",tsmdata->tid,tsmdata->brange,
               tsmdata->mac[0],tsmdata->mac[1],tsmdata->mac[2],tsmdata->mac[3],tsmdata->mac[4],tsmdata->mac[5],tsmdata->tx_cnt);
       fprintf(fd,"\t\tdiscnt %d multirtycnt %d cfpoll %d qdelay %d txdelay %d bin[0-5]: %d %d %d %d %d %d\n\n",
               tsmdata->discnt,tsmdata->multirtycnt,tsmdata->cfpoll,
               tsmdata->qdelay,tsmdata->txdelay,tsmdata->bin[0],tsmdata->bin[1],tsmdata->bin[2],
               tsmdata->bin[3],tsmdata->bin[4],tsmdata->bin[5]);
       lmdata = &rrmstats->ni_rrm_stats.lm_data;
       fprintf(fd, "Link Measurement information :\n");
       fprintf(fd, "\t\ttx_pow %d lmargin %d rxant %d txant %d rcpi %d rsni %d\n\n",
               lmdata->tx_pow,lmdata->lmargin,lmdata->rxant,lmdata->txant,
               lmdata->rcpi,lmdata->rsni);
       fprintf(fd, "Frame Report Information : \n\n");
       for (i = 0; i < 12; i++)
       {
           frmcnt = &rrmstats->ni_rrm_stats.frmcnt_data[i];
           fprintf(fd,"Transmitter MAC: %02x:%02x:%02x:%02x:%02x:%02x",frmcnt->ta[0], frmcnt->ta[1],frmcnt->ta[2],frmcnt->ta[3],frmcnt->ta[4],frmcnt->ta[5]);
           fprintf(fd," BSSID: %02x:%02x:%02x:%02x:%02x:%02x",frmcnt->bssid[0], frmcnt->bssid[1], frmcnt->bssid[2],\
                   frmcnt->bssid[3], frmcnt->bssid[4],frmcnt->bssid[5]);
           fprintf(fd," phytype %d arsni %d lrsni %d lrcpi %d antid %d frame count %d\n",
                   frmcnt->phytype,frmcnt->arcpi,frmcnt->lrsni,frmcnt->lrcpi,frmcnt->antid, frmcnt->frmcnt);
       }
   }
   return;
}

static void get_bcnrpt(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s;
    struct ieee80211req_athdbg req;
    ieee80211req_rrmstats_t *rrmstats_req;
    ieee80211_bcnrpt_t *bcnrpt = NULL;

    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
    s = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    req.cmd = IEEE80211_DBGREQ_GETBCNRPT;
    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));

    bcnrpt  = (ieee80211_bcnrpt_t *) (malloc(sizeof(ieee80211_bcnrpt_t)));

    if(NULL == bcnrpt) {
        printf("insufficient memory \n");
        return;
    }

    rrmstats_req = &req.data.rrmstats_req;
    rrmstats_req->data_addr = (void *) bcnrpt;
    rrmstats_req->data_size = (sizeof(ieee80211_bcnrpt_t));
    rrmstats_req->index = 1;

    printf("\t BSSID \t\t\tCHNUM\tRCPI \n");
    while(rrmstats_req->index) {
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            errx(1, "IEEE80211_IOCTL_DBGREQ: ieee80211_dbgreq_bcnrpt failed");
        }

        if (bcnrpt->more) {
            rrmstats_req->index++;
            printf(" \t%02x %02x %02x %02x %02x %02x\t %d \t %d \n",
                    bcnrpt->bssid[0],bcnrpt->bssid[1],
                    bcnrpt->bssid[2],bcnrpt->bssid[3],
                    bcnrpt->bssid[4],bcnrpt->bssid[5],
                    bcnrpt->chnum,bcnrpt->rcpi);
        } else {
            rrmstats_req->index = 0;
        }
    }

    free(bcnrpt);
    return;
}
static void get_rssi(const char *ifname, int argc, char *argv[])
{

	struct iwreq iwr;
	int s, len;
	struct ieee80211req_athdbg req;
	if ((argc < 4) || (argc > 4))
	{
    	usage_getrssi();
    	return;
	}
  	memset(&req, 0, sizeof(struct ieee80211req_athdbg));
 	s = socket(AF_INET, SOCK_DGRAM, 0);
	(void) memset(&iwr, 0, sizeof(iwr));
  	(void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));



  	req.cmd = IEEE80211_DBGREQ_GETRRSSI;

  	req.dstmac[0] = 0x00;
  	req.dstmac[1] = 0x00;
  	req.dstmac[2] = 0x00;
  	req.dstmac[3] = 0x00;
  	req.dstmac[4] = 0x00;
  	req.dstmac[5] = 0x00;
 	if (!wifitool_mac_aton(argv[3], &req.dstmac[0], 6))
    {
       errx(1, "Invalid mac address");
       return;
    }
  	iwr.u.data.pointer = (void *) &req;
  	iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));


  	if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0)
  	{
      errx(1, "IEEE80211_IOCTL_DBGREQ: IEEE80211_DBGREQ_RRMSTATSREQ failed");
  	}
}


static void channel_loading_channel_list_set(const char *ifname, int argc, char *argv[])
{
#define MIN_PARAM  4
	struct iwreq iwr;
	int s, len,i;
	struct ieee80211req_athdbg req;
	ieee80211_user_chanlist_t chanlist;
	u_int8_t *chan  = NULL ; /*user channel list */

	if ((argc < MIN_PARAM))
	{
    	   usage_setchanlist();
    	   return;
	}
  	memset(&req, 0, sizeof(struct ieee80211req_athdbg));

 	s = socket(AF_INET, SOCK_DGRAM, 0);
	(void) memset(&iwr, 0, sizeof(iwr));
  	(void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

  	req.cmd = IEEE80211_DBGREQ_SETACSUSERCHANLIST;
	chan = (u_int8_t *) malloc(sizeof(u_int8_t) * (argc - 3));

	if(NULL == chan)
		return ;

	chanlist.chan = chan;
	chanlist.n_chan = 0;
	req.data.param[0] = (int )&chanlist; /*typecasting to avoid warning */

	for(i = 3;i < argc; i++)
		chan[i - 3] =  atoi(argv[i]);

	iwr.u.data.pointer = (void *) &req;
  	iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));

	if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0)
	{
        	errx(1, "ieee80211_ioctl_dbgreq: ieee80211_dbgreq_setchanlist failed");
	        printf("error in ioctl \n");
	}

	free(chan);
	return;
#undef MIN_PARAM
}

static void channel_loading_channel_list_get(const char *ifname, int argc, char *argv[])
{
#define MAX_PARAM  3
	struct iwreq iwr;
	int s, len,i;
	struct ieee80211req_athdbg req;
	ieee80211_user_chanlist_t chanlist;
	u_int8_t *chan  = NULL ; /*user channel list */

	if ((argc > MAX_PARAM))
	{
		usage_getchanlist();
		return;
	}
  	memset(&req, 0, sizeof(struct ieee80211req_athdbg));
 	s = socket(AF_INET, SOCK_DGRAM, 0);
	(void) memset(&iwr, 0, sizeof(iwr));
  	(void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

  	req.cmd = IEEE80211_DBGREQ_GETACSUSERCHANLIST;

  	iwr.u.data.pointer = (void *) &req;
  	iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
	chan = (u_int8_t *) malloc(sizeof(u_int8_t) * (255));
	if(chan == NULL)
		return;

	chanlist.chan = chan;
	chanlist.n_chan = 0;
	req.data.param[0] = (int )&chanlist; /*typecasting to avoid warning */

	if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0)
	{
		errx(1, "ieee80211_ioctl_dbgreq: ieee80211_dbgreq_getchanlist failed");
		printf("error in ioctl \n");
		return;
	}
	printf("Following list used in channel load report \n");

	for(i = 0;i < chanlist.n_chan;i++)
        	printf("%d    ",chanlist.chan[i]);

	printf("\n");

	free(chan);
	return;
#undef MAX_PARAM
}

/**
 * @brief to calulate power used by block channel list
 *
 * @param a
 * @param b
 *
 * @return
 */

static inline int power(int a, int b )
{
    int number = 1,i = 0;
    for (i = 0;i < b;i++)
        number *= a;
    return number;
}
/**
  * @brief To display the MAC address of the RRM capable STA
  *
  * @return
  */
static void rrm_sta_list(const char *ifname, int argc, char *argv[])
{
#define MAX_CLIENTS 256
#define MAX_PARAM 3
    struct ieee80211req_athdbg req = { 0 };
    struct iwreq iwr = { 0 };
    int s = 0,count = 0,index;
    unsigned char *addr_list = NULL;
    ieee80211_rrm_sta_info_t *rrm_stats;
    if (argc > MAX_PARAM)
    {
        usage_rrmstalist();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    rrm_stats = (void *)malloc(sizeof(ieee80211_rrm_sta_info_t));
    req.cmd = IEEE80211_DBGREQ_GET_RRM_STA_LIST;
    req.data.param[0] = (int )rrm_stats;
    memset(req.dstmac,0xff,IEEE80211_ADDR_LEN); /* Assigning broadcast address to get the STA count */

    if(rrm_stats == NULL) {
        printf("Memory allocation failed  __investigate__\n");
        close(s);
        return;
    }

    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        perror("set RRM STA list  failed \n");
        goto MEMORY_FAIL;
    }
    if(rrm_stats->count > MAX_CLIENTS) {
        perror("can not display long list __investigate__\n");
        goto MEMORY_FAIL;
    }
    addr_list = (u_int8_t *) malloc(IEEE80211_ADDR_LEN * (rrm_stats->count));
    if(addr_list == NULL) {
        perror("Memory allocation failed  __investigate__\n");
        goto MEMORY_FAIL;
    }
    count = rrm_stats->count;
    req.data.param[1] = (int) addr_list; /*typecasted to avoid warning */
    memset(req.dstmac,0x00,IEEE80211_ADDR_LEN);
    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        perror("RRM STA LIST failed \n");
        free(addr_list);
        goto MEMORY_FAIL;
    }
    printf("\t RRM Capable station's Mac address ");
    for(index = 0;index<(IEEE80211_ADDR_LEN*count);index++){
        if(!(index%6))
            printf("\n");
        printf("%02x:",addr_list[index]);
    }
    printf( "\n");
#undef MAX_PARAM
#undef MAX_CLIENTS
    free(addr_list);
MEMORY_FAIL:
    free(rrm_stats);
    close(s);
    return;
}

/*
 * wifitool athX lteu_cfg
 * [ -g 0|1 ] [ -n 1-10 ] [ -w 1-10 0-100+ ] [ -y 1-10 0-500+ ]
 * [ -t 1-10 (-110)-0+ ] [ -o 10-50 ] [ -a 0-100 ] [ -f 0|1 ] [ -h ]
 * -g : gpio start or not
 * -n : number of bins
 * -w : number of weights followed by the individual weights
 * -y : number of gammas followed by individual gammas
 * -t : number of thresholds followed by individual thresholds
 * -o : timeout
 * -a : alpha for num active bssid calc
 * -f : 1 to use actual NF, 0 to use a hardcoded one
 * -h : help
 */
static void lteu_cfg(const char *ifname, int argc, char *argv[])
{
    struct ieee80211req_athdbg req;
    struct iwreq iwr;
    int sock;
    int i, j, n, x, y;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("open:\n");
        return;
    }

    memset(&iwr, 0, sizeof(iwr));
    strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    iwr.u.data.pointer = (void *)&req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    req.cmd = IEEE80211_DBGREQ_LTEU_CFG;
    req.data.lteu_cfg.lteu_gpio_start = 0;
    req.data.lteu_cfg.lteu_num_bins = LTEU_MAX_BINS;
    for (i = 0; i < LTEU_MAX_BINS; i++) {
        req.data.lteu_cfg.lteu_weight[i] = 49;
        req.data.lteu_cfg.lteu_thresh[i] = 50;
        req.data.lteu_cfg.lteu_gamma[i] = 51;
    }
    req.data.lteu_cfg.lteu_scan_timeout = 10;
    req.data.lteu_cfg.alpha_num_bssid = 50;
    req.data.lteu_cfg.use_actual_nf = 0;

    argc -= 3;
    j = 3;
    while (argc) {
        if (!strcmp(argv[j], "-g")) {
            argc--;
            j++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[j], NULL, 10);
            if (x >= 0 && x <= 1) {
                argc--;
                j++;
                req.data.lteu_cfg.lteu_gpio_start = x;
            }
        } else if (!strcmp(argv[j], "-n")) {
            argc--;
            j++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[j], NULL, 10);
            if (x >= 1 && x <= 10) {
                argc--;
                j++;
                req.data.lteu_cfg.lteu_num_bins = x;
            }
        } else if (!strcmp(argv[j], "-w")) {
            argc--;
            j++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[j], NULL, 10);
            if (x >= 1 && x <= 10) {
                argc--;
                j++;
                n = x;
                i = 0;
                while (n-- && argc) {
                    y = strtoul(argv[j], NULL, 10);
                    if (y >= 0 && y <= 100) {
                        argc--;
                        j++;
                        req.data.lteu_cfg.lteu_weight[i++] = y;
                    } else
                        break;
                }
                if (i != x) {
                    for (i = 0; i < LTEU_MAX_BINS; i++)
                        req.data.lteu_cfg.lteu_weight[i] = 49;
                }
            }
        } else if (!strcmp(argv[j], "-y")) {
            argc--;
            j++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[j], NULL, 10);
            if (x >= 1 && x <= 10) {
                argc--;
                j++;
                n = x;
                i = 0;
                while (n-- && argc) {
                    y = strtoul(argv[j], NULL, 10);
                    if (y >= 0 && y <= 500) {
                        argc--;
                        j++;
                        req.data.lteu_cfg.lteu_gamma[i++] = y;
                    } else
                        break;
                }
                if (i != x) {
                    for (i = 0; i < LTEU_MAX_BINS; i++)
                        req.data.lteu_cfg.lteu_gamma[i] = 51;
                }
            }
        } else if (!strcmp(argv[j], "-t")) {
            argc--;
            j++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[j], NULL, 10);
            if (x >= 1 && x <= 10) {
                argc--;
                j++;
                n = x;
                i = 0;
                while (n-- && argc) {
                    y = strtoul(argv[j], NULL, 10);
                    if (y >= -110 && y <= 0) {
                        argc--;
                        j++;
                        req.data.lteu_cfg.lteu_thresh[i++] = y;
                    } else
                        break;
                }
                if (i != x) {
                    for (i = 0; i < LTEU_MAX_BINS; i++)
                        req.data.lteu_cfg.lteu_thresh[i] = 50;
                }
            }
        } else if (!strcmp(argv[j], "-o")) {
            argc--;
            j++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[j], NULL, 10);
            if (x >= 10 && x <= 50) {
                argc--;
                j++;
                req.data.lteu_cfg.lteu_scan_timeout = x;
            }
        } else if (!strcmp(argv[j], "-a")) {
            argc--;
            j++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[j], NULL, 10);
            if (x >= 0 && x <= 100) {
                argc--;
                j++;
                req.data.lteu_cfg.alpha_num_bssid = x;
            }
        } else if (!strcmp(argv[j], "-f")) {
            argc--;
            j++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[j], NULL, 10);
            if (x >= 0 && x <= 1) {
                argc--;
                j++;
                req.data.lteu_cfg.use_actual_nf = x;
            }
        } else if (!strcmp(argv[j], "-h")) {
            argc--;
            j++;
            printf("wifitool athX lteu_cfg "
                   "[ -g 0|1 ] [ -n 1-10 ] [ -w 1-10 0-100+ ] [ -y 1-10 -0-500+ ] "
                   "[ -t 1-10 (-110)-0+ ] [ -o 10-50 ] [ -a 0-100 ] [ -f 0|1 ] [ -h ]\n");
            printf("-g : gpio start or not\n");
            printf("-n : number of bins\n");
            printf("-w : number of weights followed by the individual weights\n");
            printf("-y : number of gammas followed by the individual gammas\n");
            printf("-t : number of thresholds followed by the individual thresholds\n");
            printf("-o : timeout\n");
            printf("-a : alpha for num active bssid calc\n");
            printf("-f : 1 to use actual NF, 0 to use a hardcoded one\n");
            printf("-h : help\n");
            close(sock);
            return;
        } else {
            argc--;
            j++;
        }
    }

    if (ioctl(sock, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        perror("ioctl:\n");
    }

    close(sock);
}

/*
 * wifitool athX ap_scan
 * [ -i 1-99 ] [ -c 1-32 36-165+ ] [ -p 0-100 ] [ -r 0-100 ]
 * [ -l 0-100 ] [ -t 0-100 ] [ -d 50-2000 ] [ -a 0|1 ] [ -w ] [ -h ]
 * -i : request id
 * -c : number of channels followed by IEEE number(s) of the channel(s)
 *      eg. to scan 36 and 40 #wifitool athX ap_scan -c 2 36 40
 * -t : value for extra scan params (can't be set separately now)
 * -p : scan repeat probe time
 * -r : scan rest time
 * -l : scan idle time
 * -t : scan probe delay
 * -d : channel time
 * -a : 1 for active scan, 0 for passive
 * -w : wait for wireless event
 * -h : help
 */
static void ap_scan(const char *ifname, int argc, char *argv[])
{
    struct ieee80211req_athdbg req;
    struct iwreq iwr;
    int sock;
    int i, j, x, y;
    int wait_event = 0;
    int ret;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("open:\n");
        return;
    }

    memset(&iwr, 0, sizeof(iwr));
    strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    iwr.u.data.pointer = (void *)&req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    req.cmd = IEEE80211_DBGREQ_AP_SCAN;
    req.data.ap_scan_req.scan_req_id = 1;
    req.data.ap_scan_req.scan_num_chan = 2;
    req.data.ap_scan_req.scan_channel_list[0] = 36;
    req.data.ap_scan_req.scan_channel_list[1] = 149;
    req.data.ap_scan_req.scan_type = SCAN_PASSIVE;
    req.data.ap_scan_req.scan_duration = 1000;
    req.data.ap_scan_req.scan_repeat_probe_time = (u_int32_t)-1;
    req.data.ap_scan_req.scan_rest_time = (u_int32_t)-1;
    req.data.ap_scan_req.scan_idle_time = (u_int32_t)-1;
    req.data.ap_scan_req.scan_probe_delay = (u_int32_t)-1;

    argc -= 3;
    i = 3;
    while (argc) {
        if (!strcmp(argv[i], "-i")) {
            argc--;
            i++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[i], NULL, 10);
            if (x >= 1 && x <= 99) {
                argc--;
                i++;
                req.data.ap_scan_req.scan_req_id = x;
            }
        } else if (!strcmp(argv[i], "-c")) {
            argc--;
            i++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[i], NULL, 10);
            if (x >= 1 && x <= 32) {
                argc--;
                i++;
                req.data.ap_scan_req.scan_num_chan = x;
                j = 0;
                while (x-- && argc) {
                    y = strtoul(argv[i], NULL, 10);
                    if (y >= 36 && y <= 165) {
                        argc--;
                        i++;
                        req.data.ap_scan_req.scan_channel_list[j++] = y;
                    } else
                        break;
                }
                if (j != req.data.ap_scan_req.scan_num_chan)
                    req.data.ap_scan_req.scan_num_chan = 0;
            }
        } else if (!strcmp(argv[i], "-p")) {
            argc--;
            i++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[i], NULL, 10);
            if (x >= 0 && x <= 100) {
                argc--;
                i++;
                req.data.ap_scan_req.scan_repeat_probe_time = x;
            }
        } else if (!strcmp(argv[i], "-r")) {
            argc--;
            i++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[i], NULL, 10);
            if (x >= 0 && x <= 100) {
                argc--;
                i++;
                req.data.ap_scan_req.scan_rest_time = x;
            }
        } else if (!strcmp(argv[i], "-l")) {
            argc--;
            i++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[i], NULL, 10);
            if (x >= 0 && x <= 100) {
                argc--;
                i++;
                req.data.ap_scan_req.scan_idle_time = x;
            }
        } else if (!strcmp(argv[i], "-t")) {
            argc--;
            i++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[i], NULL, 10);
            if (x >= 0 && x <= 100) {
                argc--;
                i++;
                req.data.ap_scan_req.scan_probe_delay = x;
            }
        } else if (!strcmp(argv[i], "-d")) {
            argc--;
            i++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[i], NULL, 10);
            if (x >= 50 && x <= 2000) {
                argc--;
                i++;
                req.data.ap_scan_req.scan_duration = x;
            }
        } else if (!strcmp(argv[i], "-a")) {
            argc--;
            i++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[i], NULL, 10);
            if (x >= 0 && x <= 1) {
                argc--;
                i++;
                req.data.ap_scan_req.scan_type = x;
            }
        } else if (!strcmp(argv[i], "-h")) {
            argc--;
            i++;
            printf("wifitool athX ap_scan "
                   "[ -i 1-99 ] [ -c 1-32 36-165+ ] [ -p 0-100 ] [ -r 0-100 ] "
                   "[ -l 0-100 ] [ -t 0-100 ] [ -d 50-2000 ] [ -a 0|1 ] [ -w ] [ -h ]\n");
            printf("-i : request id\n");
            printf("-c : number of channels followed by IEEE number(s) of the channel(s)\n");
            printf("     eg. to scan 36 and 40 #wifitool athX ap_scan -c 2 36 40\n");
            printf("-p : scan repeat probe time\n");
            printf("-r : scan rest time\n");
            printf("-l : scan idle time\n");
            printf("-t : scan probe delay\n");
            printf("-d : channel time\n");
            printf("-a : 1 for active scan, 0 for passive\n");
            printf("-w : wait for wireless event\n");
            printf("-h : help\n");
            close(sock);
            return;
        } else if (!strcmp(argv[i], "-w")) {
            argc--;
            i++;
            wait_event = 1;
        } else {
            argc--;
            i++;
        }
    }

    ret = ioctl(sock, IEEE80211_IOCTL_DBGREQ, &iwr);
    if (ret < 0) {
        perror("ioctl:\n");
    }

    close(sock);

    if (ret >= 0 && wait_event)
        get_next_wireless_custom_event(IEEE80211_EV_SCAN);
}

/*
 * wifitool athX mu_scan
 * [ -i 1-99 ] [ -c 36-165 ] [ -t 1-7 ] [ -d 5-5000 ] [ -p 0-100 ] [ -w ] [ -h ]
 * -i : request id
 * -c : IEEE number of the channel
 * -t : algo(s) to use
 * -d : time
 * -p : LTEu Tx power
 * -w : wait for wireless event
 * -h : help
 */
static void mu_scan(const char *ifname, int argc, char *argv[])
{
    struct ieee80211req_athdbg req;
    struct iwreq iwr;
    int sock;
    int i, x;
    int wait_event = 0;
    int ret;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("open:\n");
        return;
    }

    memset(&iwr, 0, sizeof(iwr));
    strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    iwr.u.data.pointer = (void *)&req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    req.cmd = IEEE80211_DBGREQ_MU_SCAN;
    req.data.mu_scan_req.mu_req_id = 1;
    req.data.mu_scan_req.mu_channel = 100;
    req.data.mu_scan_req.mu_type = MU_ALGO_1 | MU_ALGO_2 | MU_ALGO_3;
    req.data.mu_scan_req.mu_duration = 1000;
    req.data.mu_scan_req.lteu_tx_power = 10;

    argc -= 3;
    i = 3;
    while (argc) {
        if (!strcmp(argv[i], "-i")) {
            argc--;
            i++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[i], NULL, 10);
            if (x >= 1 && x <= 99) {
                argc--;
                i++;
                req.data.mu_scan_req.mu_req_id = x;
            }
        } else if (!strcmp(argv[i], "-c")) {
            argc--;
            i++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[i], NULL, 10);
            if (x >= 36 && x <= 165) {
                argc--;
                i++;
                req.data.mu_scan_req.mu_channel = x;
            }
        } else if (!strcmp(argv[i], "-t")) {
            argc--;
            i++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[i], NULL, 10);
            if (x >= 1 && x <= 7) {
                argc--;
                i++;
                req.data.mu_scan_req.mu_type = x;
            }
        } else if (!strcmp(argv[i], "-d")) {
            argc--;
            i++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[i], NULL, 10);
            if (x >= 5 && x <= 5000) {
                argc--;
                i++;
                req.data.mu_scan_req.mu_duration = x;
            }
        } else if (!strcmp(argv[i], "-p")) {
            argc--;
            i++;
            if (!argc) {
                break;
            }
            x = strtoul(argv[i], NULL, 10);
            if (x >= 0 && x <= 100) {
                argc--;
                i++;
                req.data.mu_scan_req.lteu_tx_power = x;
            }
        } else if (!strcmp(argv[i], "-h")) {
            argc--;
            i++;
            printf("wifitool athX mu_scan "
                   "[ -i 1-99 ] [ -c 36-165 ] [ -t 1-7 ] [ -d 5-5000 ] [ -p 0-100 ] [ -w ] [ -h ]\n");
            printf("-i : request id\n");
            printf("-c : IEEE number of the channel\n");
            printf("-t : algo(s) to use\n");
            printf("-d : time\n");
            printf("-p : LTEu Tx power\n");
            printf("-w : wait for wireless event\n");
            printf("-h : help\n");
            close(sock);
            return;
        } else if (!strcmp(argv[i], "-w")) {
            argc--;
            i++;
            wait_event = 1;
        } else {
            argc--;
            i++;
        }
    }

    ret = ioctl(sock, IEEE80211_IOCTL_DBGREQ, &iwr);
    if (ret < 0) {
        perror("ioctl:\n");
    }

    close(sock);

    if (ret >= 0 && wait_event)
        get_next_wireless_custom_event(IEEE80211_EV_MU_RPT);
}

/**
 * @brief api from user land to set block channel list to driver
 *
 * @param ifname
 * @param argc
 * @param argv[]
 */
static void block_acs_channel(const char *ifname, int argc, char *argv[])
{
#define MAX_CHANNEL 255
    int count = 0,temph = 0,cnt = 0,i = 0,j = 0,s = 0 ;
    u_int8_t channel[MAX_CHANNEL],valid[MAX_CHANNEL];
    char *p = NULL;
    struct iwreq iwr = { 0 };
    struct ieee80211req_athdbg req = { 0 };
    ieee80211_user_chanlist_t chanlist;
    u_int8_t *chan  = NULL ; /*user channel list */

    if ((argc < 4))
    {
        fprintf(stderr, "usage: wifitool athX block_acs_channel ch1.....chN\n");
        fprintf(stderr, "usage: wifitool athX block_acs_channel channels must be comma seperated \n");
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    req.cmd = IEEE80211_DBGREQ_BLOCK_ACS_CHANNEL;
    memset(channel,0,MAX_CHANNEL);
    p = argv[3];
    while(*p != '\0') {
        while( *p != ',' && (*p != '\0'))
        {
            sscanf(p, "%1d", &temph);
            valid[i] = temph;
            p++;
            i++;
        }
        if(i) {
            for( cnt = 0;cnt < i;cnt++) {
                channel[count] = channel[count] + valid[cnt]*power(10,(i-cnt-1));
            }
            count++;
            i = 0;
            if(*p == '\0')
                break;
            else
                p++; /*by pass commma */
        }
        if(count >= MAX_CHANNEL) {
            count = MAX_CHANNEL;
            break;
        }
    }
    if(count) {
        chan = (u_int8_t *) malloc(sizeof(u_int8_t) * (count));
        if(NULL == chan)
            return ;

        memcpy(chan,channel,count);
        chanlist.chan = chan;
        chanlist.n_chan = count;
        req.data.param[0] = (int )&chanlist; /*typecasting to avoid warning */

        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            perror("set block channel list  failed \n");
            return;
        }

        if(!chan[0])
            printf("List Flushed \n");
        else {
            printf("Following channels are blocked from Channel selection algorithm  \n");
            for(i = 0;i < count; i++) {
                printf("[%d] ",channel[i]);
            }
            printf("\n");
        }

    } else  {
        perror("Invalid channel list \n");
    }

    return;
}

static void acs_report(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len,i;
    struct ieee80211req_athdbg req;
    struct ieee80211_acs_dbg *acs = NULL;
    if ((argc < 3) || (argc > 3))
    {
        usage_acsreport();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

  	iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    req.cmd = IEEE80211_DBGREQ_GETACSREPORT;

    acs = (void *)malloc(sizeof(struct ieee80211_acs_dbg));

    if(NULL == acs) {
        printf("insufficient memory \n");
        return;
    }
    req.data.acs_rep.data_addr = acs;
    req.data.acs_rep.data_size = sizeof(struct ieee80211_acs_dbg);
    req.data.acs_rep.index = 0;
    acs->entry_id = 0;
    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ: IEEE80211_DBGREQ_RRMSTATSREQ failed");
        printf("error in ioctl \n");
        return;
    }
    fprintf(stdout," The number of channels scanned for acs report is:  %d \n",acs->nchans);
    fprintf(stdout," Channel | BSS  | minrssi | maxrssi | NF | Ch load | spect load | sec_chan \n");
    fprintf(stdout,"---------------------------------------------------------------------\n");
    /* output the current configuration */
    for (i = 0; i < acs->nchans; i++) {
        acs->entry_id = i;
        req.cmd = IEEE80211_DBGREQ_GETACSREPORT;
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            perror("DBG req failed");
            return;
        }
        /*To make sure we are not getting more than 100 %*/
        if(acs->chan_load  > 100)
            acs->chan_load = 100;

        fprintf(stdout," %4d(%3d) %4d     %4d      %4d   %4d    %4d        %4d       %4d   \n",
                acs->chan_freq,
                acs->ieee_chan,
                acs->chan_nbss,
                acs->chan_minrssi,
                acs->chan_maxrssi,
                acs->noisefloor,
                acs->chan_load,
                acs->channel_loading,
                acs->sec_chan);
    }

    free(acs);
    return;
}

static void get_rrmstats(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len,unicast=0;
    struct ieee80211req_athdbg req;
    ieee80211req_rrmstats_t *rrmstats_req;
    ieee80211_rrmstats_t *rrmstats = NULL;

    if ((argc < 3) || (argc > 4)) {
        usage_getrrrmstats();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    req.cmd = IEEE80211_DBGREQ_GETRRMSTATS;
    req.dstmac[0] = 0x00;
    req.dstmac[1] = 0x00;
    req.dstmac[2] = 0x00;
    req.dstmac[3] = 0x00;
    req.dstmac[4] = 0x00;
    req.dstmac[5] = 0x00;
    if (argc == 4) {
        unicast = 1;
        if (!wifitool_mac_aton(argv[3], &req.dstmac[0], 6)) {
            errx(1, "Invalid mac address");
            return;
        }
    }

    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    rrmstats = (ieee80211_rrmstats_t *)(malloc(sizeof(ieee80211_rrmstats_t)));

    if(NULL == rrmstats) {
        printf("insufficient memory \n");
        return;
    }

    rrmstats_req = &req.data.rrmstats_req;
    rrmstats_req->data_addr = (void *) rrmstats;
    rrmstats_req->data_size = (sizeof(ieee80211_rrmstats_t));
    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ: IEEE80211_DBGREQ_RRMSTATSREQ failed");
    }
    print_rrmstats(stdout, rrmstats,unicast);

    free(rrmstats);
    return ;


}

static void send_frmreq(const char *ifname, int argc, char *argv[])
{
  struct iwreq iwr;
  int s, len;
  struct ieee80211req_athdbg req;
  ieee80211_rrm_frame_req_info_t *frm_req = &req.data.frm_req;

  if (argc != 11)
  {
    usage_sendfrmreq();
    return;
  }

  memset(&req, 0, sizeof(struct ieee80211req_athdbg));
  s = socket(AF_INET, SOCK_DGRAM, 0);
  (void) memset(&iwr, 0, sizeof(iwr));
  (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

  req.cmd = IEEE80211_DBGREQ_SENDFRMREQ;

  if (!wifitool_mac_aton(argv[3], frm_req->dstmac, 6))
  {
      errx(1, "Invalid mac address");
      return;
  }

  memcpy(req.dstmac, frm_req->dstmac, 6);
  frm_req->num_rpts = atoi(argv[4]);
  frm_req->regclass = atoi(argv[5]);
  frm_req->chnum = atoi(argv[6]);
  frm_req->r_invl = atoi(argv[7]);
  frm_req->m_dur = atoi(argv[8]);
  frm_req->ftype = atoi(argv[9]);

  if (!wifitool_mac_aton(argv[10], frm_req->peermac, 6))
  {
      errx(1, "Invalid mac address");
      return;
  }

  iwr.u.data.pointer = (void *) &req;
  iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));

  if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0)
  {
      errx(1, "IEEE80211_IOCTL_DBGREQ: IEEE80211_DBGREQ_SENDSTASTATSREQ failed");
  }
  return;
}

static void send_lcireq(const char *ifname, int argc, char *argv[])
{
  struct iwreq iwr;
  int s, len;
  struct ieee80211req_athdbg req;
  ieee80211_rrm_lcireq_info_t *lci_req = &req.data.lci_req;

  if ((argc < 9) || (argc > 11) || (argc == 10))
  {
    usage_sendlcireq();
    return;
  }

  memset(&req, 0, sizeof(struct ieee80211req_athdbg));
  s = socket(AF_INET, SOCK_DGRAM, 0);
  (void) memset(&iwr, 0, sizeof(iwr));
  (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

  req.cmd = IEEE80211_DBGREQ_SENDLCIREQ;

  if (!wifitool_mac_aton(argv[3], lci_req->dstmac, 6))
  {
      errx(1, "Invalid mac address");
      return;
  }

  memcpy(req.dstmac, lci_req->dstmac, 6);
  lci_req->num_rpts = atoi(argv[4]);
  lci_req->location = atoi(argv[5]);
  lci_req->lat_res = atoi(argv[6]);
  lci_req->long_res = atoi(argv[7]);
  lci_req->alt_res = atoi(argv[8]);

  if ((lci_req->lat_res > 34) || (lci_req->long_res > 34) ||
      (lci_req->alt_res > 30))
  {
    fprintf(stderr, "Incorrect number of resolution bits !!\n");
    usage_sendlcireq();
    exit(-1);
  }

  if (argc == 11)
  {
    lci_req->azi_res = atoi(argv[9]);
    lci_req->azi_type =  atoi(argv[10]);

    if (lci_req->azi_type !=1)
    {
       fprintf(stderr, "Incorrect azimuth type !!\n");
       usage_sendlcireq();
       exit(-1);
    }

    if (lci_req->azi_res > 9)
    {
       fprintf(stderr, "Incorrect azimuth resolution value(correct range 0 - 9) !!\n");
       usage_sendlcireq();
       exit(-1);
    }
  }

  iwr.u.data.pointer = (void *) &req;
  iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));

  if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0)
  {
      errx(1, "IEEE80211_IOCTL_DBGREQ: IEEE80211_DBGREQ_SENDSTASTATSREQ failed");
  }
  return;
}

static void
send_stastats(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len;
    struct ieee80211req_athdbg req;
    ieee80211_rrm_stastats_info_t *stastats = &req.data.stastats;

    if (argc < 6) {
        usage_sendstastatsrpt();
    }
    else{
        s = socket(AF_INET, SOCK_DGRAM, 0);
        (void) memset(&iwr, 0, sizeof(iwr));
        (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
        req.cmd = IEEE80211_DBGREQ_SENDSTASTATSREQ;
        if (!wifitool_mac_aton(argv[3], stastats->dstmac, 6)) {
            errx(1, "Invalid mac address");
            return;
        }
        stastats->m_dur = atoi(argv[4]);
        stastats->gid = atoi(argv[5]);
        memcpy(req.dstmac,stastats->dstmac, 6);
        iwr.u.data.pointer = (void *) &req;
        iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0){
            errx(1, "IEEE80211_IOCTL_DBGREQ: IEEE80211_DBGREQ_SENDSTASTATSREQ failed");
        }
        return;
    }
}

static void
send_chload(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len;
    struct ieee80211req_athdbg req;
    ieee80211_rrm_chloadreq_info_t * chloadrpt = &req.data.chloadrpt;

    if ((argc < 9) || (argc > 11)) {
        usage_sendchloadrpt();
    }
    else {
        memset(&req, 0, sizeof(struct ieee80211req_athdbg));
        s = socket(AF_INET, SOCK_DGRAM, 0);
        (void) memset(&iwr, 0, sizeof(iwr));
        (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
        req.cmd = IEEE80211_DBGREQ_SENDCHLOADREQ;
        if (!wifitool_mac_aton(argv[3], chloadrpt->dstmac, 6)) {
            errx(1, "Invalid mac address");
            return;
        }
        chloadrpt->num_rpts = atoi(argv[4]);
        chloadrpt->regclass = atoi(argv[5]);
        chloadrpt->chnum = atoi(argv[6]);
        chloadrpt->r_invl = atoi(argv[7]);
        chloadrpt->m_dur  = atoi(argv[8]);
        if(argc > 9 ) { /*optional element */
            chloadrpt->cond  = atoi(argv[9]);
            chloadrpt->c_val  = atoi(argv[10]);
        }
        memcpy(req.dstmac, chloadrpt->dstmac, 6);
        iwr.u.data.pointer = (void *) &req;
        iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            errx(1, "IEEE80211_IOCTL_DBGREQ: IEEE80211_DBGREQ_SENDCHLOADREQ failed");
        }
    }
    return;
}

static void tr069_chan_history(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, i = 0;
    struct ieee80211req_athdbg req;
    ieee80211_channelhist_t* chandata = NULL;
    char chanSelTime[40] = "\0";
    u_int8_t act_idx=0;
    struct tm tm;
    struct timespec *ts = NULL, nowtime, tstamp;

    if ((argc < 3) || (argc > 3))
    {
        usage_tr069chanhist();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    req.cmd = IEEE80211_DBGREQ_TR069;
    chandata = (void *)malloc(sizeof(ieee80211_channelhist_t));

    if(NULL == chandata) {
        printf("insufficient memory \n");
        close(s);
        return;
    }
    req.data.tr069_req.data_addr = chandata;
    req.data.tr069_req.cmdid = TR069_CHANHIST;
    req.data.tr069_req.data_size = sizeof(ieee80211_channelhist_t);
    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ: IEEE80211_DBGREQ_TR069 failed");
        printf("error in ioctl \n");
        free(chandata);
        close(s);
        return;
    }

    act_idx = chandata->act_index;
    fprintf(stdout," Channel | Selection Time \n");
    fprintf(stdout,"----------------------------------\n");
    /* print from latest to first */
    for(i = act_idx; i >= 0 ; i--) {
        gettimeofday(&nowtime,NULL);
        ts = &(chandata->chanlhist[i].chan_time);
        tstamp.tv_sec = nowtime.tv_sec - ts->tv_sec;
        /*Convert timespec to date/time*/
        TSPECTOTIME(tstamp,tm,chanSelTime);
        fprintf(stdout," %4d      %s \n",
                chandata->chanlhist[i].chanid,chanSelTime);
    }
    if((act_idx < (IEEE80211_CHAN_MAXHIST - 1))
        && (chandata->chanlhist[act_idx+1].chanid)) {
        for(i = (IEEE80211_CHAN_MAXHIST - 1); i > act_idx ; i--) {
            gettimeofday(&nowtime,NULL);
            ts = &(chandata->chanlhist[i].chan_time);
            tstamp.tv_sec = nowtime.tv_sec - ts->tv_sec;
            /*Convert timespec to date/time*/
            TSPECTOTIME(tstamp,tm,chanSelTime);
            fprintf(stdout," %4d      %s \n",
                chandata->chanlhist[i].chanid,chanSelTime);
        }
    }

    free(chandata);
    close(s);
    return;
}

static const char *
mac_to_string(const u_int8_t mac[IEEE80211_ADDR_LEN])
{
    static char a[18];
    int i;

    i = snprintf(a, sizeof(a), "%02x:%02x:%02x:%02x:%02x:%02x",
            mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    return (i < 17 ? NULL : a);
}

static void
get_assoc_time(const char *ifname, int argc, char *argv[])
{
    u_int8_t buf[24*1024];
    struct iwreq iwr;
    int s=0, len=0;
    u_int8_t *cp;
    struct timespec now_ts, assoc_ts, delta_ts;
    struct tm assoc_tm;
    char assoc_time[40]={'\0'};
    char *mac_string = NULL;

    if (argc != 3) {
        fprintf(stderr, "usage: wifitool athX get_assoc_time");
        return;
    }

    s = socket(AF_INET, SOCK_DGRAM, 0);
    if(s < 0) {
        fprintf(stderr, "Socket error");
        return;
    }
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
    iwr.u.data.pointer = (void *) buf;
    iwr.u.data.length = sizeof(buf);
    if (ioctl(s, IEEE80211_IOCTL_STA_INFO, &iwr) < 0) {
        fprintf(stderr, "Unable to get station information");
        close(s);
        return;
    }
    len = iwr.u.data.length;
    if (len < sizeof(struct ieee80211req_sta_info)){
        fprintf(stderr, "Unable to get station information");
        close(s);
        return;
    }
    printf("%4s %9s\n"
           , "ADDR"
           , "ASSOCTIME"
    );
    cp = buf;
    do {
        struct ieee80211req_sta_info *si;
        si = (struct ieee80211req_sta_info *) cp;

        gettimeofday(&now_ts, NULL);
        (void) memcpy(&assoc_ts, &si->isi_tr069_assoc_time, sizeof(si->isi_tr069_assoc_time));
        delta_ts.tv_sec = now_ts.tv_sec - assoc_ts.tv_sec;
        TSPECTOTIME(delta_ts, assoc_tm, assoc_time);
        mac_string = mac_to_string(si->isi_macaddr);
        printf("%s %s"
               , (mac_string != NULL) ? mac_string :"NO MAC ADDR"
               , assoc_time
        );
        printf("\n");
        cp += si->isi_len, len -= si->isi_len;
    } while (len >= sizeof(struct ieee80211req_sta_info));

    close(s);
    return;
}

static void tr069_txpower(const char *ifname, int argc, char *argv[])
{
	struct iwreq iwr = { 0 };
	struct ieee80211req_athdbg req = { 0 };
	int percent_value, s = 0;
	int *txpower;
	if ((argc != 4))  {
		usage_tr069_txpower();
		return;
	}
	memset(&req, 0, sizeof(struct ieee80211req_athdbg));
	s = socket(AF_INET, SOCK_DGRAM, 0);
	(void) memset(&iwr, 0, sizeof(iwr));
	(void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
	txpower = (void *) malloc(sizeof(int));
	if(txpower == NULL){
		printf("Insufficient memory \n");
		close(s);
		return;
	}

	req.cmd = IEEE80211_DBGREQ_TR069;

	iwr.u.data.pointer = (void *) &req;
	iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
	req.data.tr069_req.cmdid = TR069_TXPOWER;
	req.data.tr069_req.data_addr = txpower;
	req.data.tr069_req.data_size = sizeof(int);

	percent_value = atoi(argv[3]);
	if ((percent_value > 100)||(percent_value < 0)){
		fprintf(stderr, "usage: Percentage value should be below 100 and more than 0 \n");
		free(txpower);
		close(s);
		return;
	}
	if (percent_value <= 100){
		req.data.param[0] = percent_value;
	}
	if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
		perror("set tr69_txpower  failed \n");
		free(txpower);
		close(s);
		return;
	}
	if(*txpower == -1){
		printf("This operation is not permitted when the Vap is up \n");
		free(txpower);
		close(s);
		return;
	}
    free(txpower);
	close(s);
	return;
}

static void tr069_gettxpower(const char *ifname, int argc, char *argv[])
{
	struct iwreq iwr = { 0 };
	struct ieee80211req_athdbg req = { 0 };
	int value, s = 0;
	int *txpower;
	if ((argc != 3))  {
		usage_tr069_gettxpower();
		return;
	}
	memset(&req, 0, sizeof(struct ieee80211req_athdbg));
	s = socket(AF_INET, SOCK_DGRAM, 0);
	(void) memset(&iwr, 0, sizeof(iwr));
	(void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
	txpower = (void *) malloc(sizeof(int));
	if(txpower == NULL){
		printf("Insufficient memory \n");
		close(s);
		return;
	}
	req.cmd = IEEE80211_DBGREQ_TR069;
	req.data.tr069_req.cmdid = TR069_GETTXPOWER;
	req.data.tr069_req.data_addr = txpower;
	req.data.tr069_req.data_size = sizeof(int);
	iwr.u.data.pointer = (void *) &req;
	iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
	if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
		perror("set tr69_txpower  failed \n");
		free(txpower);
		close(s);
		return;
	}
	if(*txpower == -1){
		printf("This operation is not permitted when the Vap is up \n");
		free(txpower);
		close(s);
		return;
	}

	printf(" %s:      TR69TXPOWER VALUE :      %d  \n", argv[1], *txpower);
	free(txpower);
	close(s);
	return;
}

static void tr069_guardintv(const char *ifname, int argc, char *argv[])
{
	struct iwreq iwr = { 0 };
	struct ieee80211req_athdbg req = { 0 };
	int value, s = 0;
	if ((argc != 4)) {
		usage_tr069_guardintv();
		return;
	}
	memset(&req, 0, sizeof(struct ieee80211req_athdbg));
	s = socket(AF_INET, SOCK_DGRAM, 0);
	(void) memset(&iwr, 0, sizeof(iwr));
	(void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
	req.cmd = IEEE80211_DBGREQ_TR069;
	iwr.u.data.pointer = (void *) &req;
	iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
	req.data.tr069_req.cmdid = TR069_GUARDINTV;
	value = atoi(argv[3]);
	req.data.param[0] = value;
	if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
		perror("set tr069_guardintv failed due to invalid input. Input should be either 800ns or 0 (auto) \n");
		close(s);
		return;
	}
	close(s);
	return;
}

static void tr069_get_guardintv(const char *ifname, int argc, char *argv[])
{
	struct iwreq iwr = { 0 };
	struct ieee80211req_athdbg req = { 0 };
	int s = 0;
	int *guardintv = NULL;
	if (argc != 3) {
		usage_tr069_get_guardintv();
		return;
	}
	memset(&req, 0, sizeof(struct ieee80211req_athdbg));
	s = socket(AF_INET, SOCK_DGRAM, 0);
	(void) memset(&iwr, 0, sizeof(iwr));
	(void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
	guardintv = (void *)malloc(sizeof(int));
	if(guardintv == NULL) {
		printf("insufficient memory");
		close(s);
		return;
	}
	req.cmd = IEEE80211_DBGREQ_TR069;
	req.data.tr069_req.cmdid = TR069_GET_GUARDINTV;
	req.data.tr069_req.data_addr = guardintv;
	req.data.tr069_req.data_size = sizeof(int);
	iwr.u.data.pointer = (void *) &req;
	iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
	if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
		perror("tr69_get_guardintv  failed \n");
		free(guardintv);
		close(s);
		return;
	}
	if(*guardintv == 0)
		printf(" %s:  TR69GUARDINTV VALUE:     %d (AUTO) \n",argv[1], *guardintv);
	else
		printf(" %s:  TR69GUARDINTV VALUE:     %d \n",argv[1], *guardintv);
	free(guardintv);
	close(s);
	return;
}

static void tr069_getassocsta(const char *ifname, int argc, char *argv[])
{
	struct iwreq iwr = { 0 };
	struct ieee80211req_athdbg req = { 0 };
	int s = 0;
	int *sta_count;
	if (argc != 3) {
		usage_tr069_getassocsta();
		return;
	}
	memset(&req, 0, sizeof(struct ieee80211req_athdbg));
	s = socket(AF_INET, SOCK_DGRAM, 0);
	(void) memset(&iwr, 0, sizeof(iwr));
	(void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
	sta_count = (void *) malloc(sizeof(int));
	if(sta_count == NULL) {
		printf("insufficient memory");
		close(s);
		return;
	}
	req.cmd = IEEE80211_DBGREQ_TR069;
	req.data.tr069_req.cmdid = TR069_GETASSOCSTA_CNT;
    req.data.tr069_req.data_addr = sta_count;
    req.data.tr069_req.data_size =  sizeof(int);
	iwr.u.data.pointer = (void *) &req;
	iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
	if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
		perror("tr069_getassocsta  failed \n");
		free(sta_count);
		close(s);
		return;
	}
	printf(" %s:  TR069GETASSOCSTA VALUE:     %d \n",argv[1], *sta_count);
	free(sta_count);
	close(s);
	return;
}

static void tr069_gettimestamp(const char *ifname, int argc, char *argv[])
{
	struct iwreq iwr = { 0 };
	struct ieee80211req_athdbg req = { 0 };
	int s = 0;
	struct timespec *time;
	char chanScanTime[40] = "\0";
	struct tm tm;
	struct timespec nowtime, tstamp;

	if (argc != 3) {
		usage_tr069_gettimestamp();
		return;
	}
	memset(&req, 0, sizeof(struct ieee80211req_athdbg));
	s = socket(AF_INET, SOCK_DGRAM, 0);
	(void) memset(&iwr, 0, sizeof(iwr));
	(void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
	time = (void *) malloc(sizeof( struct timespec));
	if(time == NULL) {
		printf("Insufficient memory");
		close(s);
		return;
	}
	req.cmd = IEEE80211_DBGREQ_TR069;
	req.data.param[0] = (int) time;
	req.data.tr069_req.cmdid = TR069_GETTIMESTAMP;
	req.data.tr069_req.data_addr = time;
	req.data.tr069_req.data_size = sizeof(struct timespec);

	iwr.u.data.pointer = (void *) &req;
	iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
	if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
		perror("tr069_gettimestamp  failed \n");
		close(s);
		free(time);
		return;
	}
	gettimeofday(&nowtime,NULL);
	tstamp.tv_sec = nowtime.tv_sec - time->tv_sec;
	/*Convert timespec to date/time*/
	TSPECTOTIME(tstamp,tm,chanScanTime);

	printf(" %s:  TR069ACSTIMESTAMP VALUE:     %s \n",argv[1], chanScanTime);
	free(time);
	close(s);
	return;
}

static void tr069_getacsscan(const char *ifname, int argc, char *argv[])
{
	struct iwreq iwr = { 0 };
	struct ieee80211req_athdbg req = { 0 };
	int s = 0,value;
	char *state = NULL;
	if (argc != 4) {
		usage_tr069_getacsscan();
		return;
	}
	memset(&req, 0, sizeof(struct ieee80211req_athdbg));
	s = socket(AF_INET, SOCK_DGRAM, 0);
	(void) memset(&iwr, 0, sizeof(iwr));
	(void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
	state  = (void *) malloc(TR69SCANSTATEVARIABLESIZE * sizeof (char));
	if(state == NULL) {
		printf("Insufficient memory");
		close(s);
		return;
	}
	req.cmd = IEEE80211_DBGREQ_TR069;
	req.data.param[3] = atoi(argv[3]);
	req.data.tr069_req.cmdid = TR069_GETDIAGNOSTICSTATE;
	req.data.tr069_req.data_addr = state;
	req.data.tr069_req.data_size = TR69SCANSTATEVARIABLESIZE * sizeof(char);
	iwr.u.data.pointer = (void *) &req;
	iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
	if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
		perror("TR069_getdiagnosticstate  failed \n");
		close(s);
		free(state);
		return;
	}
	printf(" %s:  TR069ACSDIAGNOSTICSTATE:     %s \n",argv[1], state);
	free(state);
	close(s);

    return;
}

static void tr069_perstastatscount(const char *ifname, int argc, char *argv[])
{
	struct iwreq iwr = { 0 };
	struct ieee80211req_athdbg req = { 0 };
	int s = 0,value;
	int *stats_count;
	if (argc != 3) {
		usage_tr069_perstastatscount();
		return;
	}
	memset(&req, 0, sizeof(struct ieee80211req_athdbg));
	s = socket(AF_INET, SOCK_DGRAM, 0);
	(void) memset(&iwr, 0, sizeof(iwr));
	(void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
	stats_count = (void *)malloc(sizeof(int));
	if(stats_count == NULL) {
		printf("Insufficient memory");
		close(s);
		return;
	}
	req.cmd = IEEE80211_DBGREQ_TR069;
	req.data.tr069_req.cmdid = TR069_GETNUMBEROFENTRIES;
	req.data.tr069_req.data_addr = stats_count;
    req.data.tr069_req.data_size =  sizeof(int);
	iwr.u.data.pointer = (void *) &req;
	iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
	if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
		perror("TR069_perstastatscount  failed \n");
		close(s);
		free(stats_count);
		return;
	}
	printf(" %s:  TR069 PER STA STATS COUNT :     %d \n",argv[1], *stats_count);
	free(stats_count);
	close(s);
	return;
}
static void tr069_get11hsupported(const char *ifname, int argc, char *argv[])
{
	struct iwreq iwr = { 0 };
	struct ieee80211req_athdbg req = { 0 };
	int s = 0,value;
	int *supported;
	if (argc != 3) {
		usage_tr069_get11hsupported();
		return;
	}
	memset(&req, 0, sizeof(struct ieee80211req_athdbg));
	s = socket(AF_INET, SOCK_DGRAM, 0);
	(void) memset(&iwr, 0, sizeof(iwr));
	(void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
	supported = (void *)malloc(sizeof(int));
	if(supported == NULL) {
		printf("Insufficient memory");
		close(s);
		return;
	}
    req.cmd = IEEE80211_DBGREQ_TR069;
	req.data.tr069_req.cmdid = TR069_GET11HSUPPORTED;
	req.data.tr069_req.data_addr = supported;
	req.data.tr069_req.data_size =  sizeof(int);
	iwr.u.data.pointer = (void *) &req;
	iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
	if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
		perror("TR069_get11hsupported failed \n");
		close(s);
		free(supported);
		return;
	}
	printf(" %s:  TR069GET11HSUPPORTED VALUE:     %d \n",argv[1], *supported);
	free(supported);
	close(s);
	return;
}

static void tr069_getpowerrange(const char *ifname, int argc, char *argv[])
{
	struct iwreq iwr = { 0 };
	struct ieee80211req_athdbg req = { 0 };
	int s = 0,i,value;
	ieee80211_tr069_txpower_range *range;
	if (argc != 3) {
		usage_tr069_getpowerrange();
		return;
	}
	memset(&req, 0, sizeof(struct ieee80211req_athdbg));
	s = socket(AF_INET, SOCK_DGRAM, 0);
	(void) memset(&iwr, 0, sizeof(iwr));
	(void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
	range =  (void *) malloc(sizeof(ieee80211_tr069_txpower_range));
	if(range == NULL) {
		printf("Insufficient memory");
		close(s);
		return;
	}
	req.cmd = IEEE80211_DBGREQ_TR069;
	req.data.tr069_req.cmdid = TR069_GETPOWERRANGE;
	req.data.tr069_req.data_addr = range;
	req.data.tr069_req.data_size = sizeof(ieee80211_tr069_txpower_range);

	iwr.u.data.pointer = (void *) &req;
	iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
	if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
		perror("TR069_getpowerrange failed \n");
		close(s);
		free(range);
		return;
	}
	if(range->value == -1){
		printf("This operation is not permitted when the Vap is up \n");
		free(range);
		close(s);
		return;
	}
	for(i = 0; i <= range->value; i++){
		printf(" %s:  TR069GETPOWERRANGE VALUE:     %d \n",argv[1], range->value_array[i]);
	}
	free(range);
	close(s);
	return;
}

static void tr069_chan_inuse(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len,i;
    struct ieee80211req_athdbg req;
    struct ieee80211_acs_dbg *acs = NULL;
    char buff[5] = "/0";
    char chanbuff[1024] = "/0"; /*max according to the spec*/

    if ((argc < 3) || (argc > 3))
    {
        usage_tr069_chan_inuse();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    req.cmd = IEEE80211_DBGREQ_GETACSREPORT;

    acs = (void *)malloc(sizeof(struct ieee80211_acs_dbg));

    if(NULL == acs) {
        printf("insufficient memory \n");
        close(s);
        return;
    }
    req.data.acs_rep.data_addr = acs;
    req.data.acs_rep.data_size = sizeof(struct ieee80211_acs_dbg);
    req.data.acs_rep.index = 0;
    acs->entry_id = 0;
    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ:IEEE80211_DBGREQ_GETACSREPORT failed");
        printf("error in ioctl \n");
        free(acs);
        close(s);
        return;
    }

    for (i = 0; i < acs->nchans; i++) {
        acs->entry_id = i;
        req.cmd = IEEE80211_DBGREQ_GETACSREPORT;
        if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
            perror("DBG req failed");
            free(acs);
            close(s);
            return;
        }
        /*To make sure we are not getting more than 100 %*/
        if(acs->chan_load  > 100)
            acs->chan_load = 100;

        if(i == (acs->nchans - 1)) /*no comma at the end*/
            snprintf(buff, sizeof(buff), "%d", acs->ieee_chan);
        else
            snprintf(buff, sizeof(buff), "%d,", acs->ieee_chan);

        strncat(chanbuff,buff,strlen(buff));
    }

    fprintf(stdout," List of Channels In Use \n");
    fprintf(stdout,"-------------------------\n");
    fprintf(stdout,"%s\n",chanbuff);

    free(acs);
    close(s);
    return;
}
    static void
tr069_getsupportedfrequency(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr = { 0 };
    struct ieee80211req_athdbg req = { 0 };
    int s = 0,value;
    char *state = NULL;
    if (argc != 3) {
        usage_tr069_getsupportedfrequency();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));
    state  = (void *) malloc(15 * sizeof (char));
    if(state == NULL) {
        printf("insufficient memory");
        close(s);
        return;
    }
    req.cmd = IEEE80211_DBGREQ_TR069;
    req.data.tr069_req.cmdid = TR069_GETSUPPORTEDFREQUENCY;
    req.data.tr069_req.data_addr = state;
    req.data.tr069_req.data_size = 15 * sizeof(char);
    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        perror("tr069_getsupportedfreq  failed \n");
        free(state);
        close(s);
        return;
    }
    printf(" supported frequency is : %s \n",state);
    free(state);
    close(s);
    return;
}


static void tr069_set_oper_rate(const char *ifname, int argc, char *argv[])
{
#define MIN_PARAM  4
    struct iwreq iwr;
    int s, i;
    struct ieee80211req_athdbg req;
    u_int8_t *ratelist  = NULL ;

    if ((argc < MIN_PARAM)) {
        usage_tr069_setoper_rate();
        return;
    }

    ratelist  = argv[3] ;
    if (strlen(argv[3]) > 256)
        return;

    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    req.cmd = IEEE80211_DBGREQ_TR069;

    req.data.tr069_req.data_addr = ratelist;
    req.data.tr069_req.cmdid = TR069_SET_OPER_RATE;
    req.data.tr069_req.data_size = strlen(ratelist);

    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ: IEEE80211_DBGREQ_TR069 failed");
        printf("error in ioctl \n");
        close(s);
        return;
    }

    close(s);
    return;
#undef MIN_PARAM
}


static void tr069_get_oper_rate(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s,i;
    struct ieee80211req_athdbg req;
    char *ratelist = NULL;

    if ((argc < 3) || (argc > 3))
    {
        usage_tr069_getoper_rate();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    req.cmd = IEEE80211_DBGREQ_TR069;

    ratelist = (char *)malloc(256);

    if(NULL == ratelist) {
        printf("insufficient memory \n");
        close(s);
        return;
    }
    req.data.tr069_req.data_addr = ratelist;
    req.data.tr069_req.cmdid = TR069_GET_OPER_RATE;
    req.data.tr069_req.data_size = 256;

    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ:IEEE80211_DBGREQ_TR069 failed");
        printf("error in ioctl \n");
        free(ratelist);
        close(s);
        return;
    }

    fprintf(stdout," List of Operationl Rates \n");
    fprintf(stdout,"-------------------------\n");
    fprintf(stdout,"%s\n",ratelist);

    free(ratelist);
    close(s);
    return;
}

static void tr069_get_posiblrate(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, len,i;
    struct ieee80211req_athdbg req;
    char *ratelist = NULL;
    char buff[5] = "/0";

    if ((argc < 3) || (argc > 3))
    {
        usage_tr069_getposiblrate();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    req.cmd = IEEE80211_DBGREQ_TR069;

    ratelist = (char *)malloc(256);

    if(NULL == ratelist) {
        printf("insufficient memory \n");
        close(s);
        return;
    }
    req.data.tr069_req.data_addr = ratelist;
    req.data.tr069_req.cmdid = TR069_GET_POSIBLRATE;
    req.data.tr069_req.data_size = 256;

    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ:IEEE80211_DBGREQ_TR069 failed");
        printf("error in ioctl \n");
        free(ratelist);
        close(s);
        return;
    }

    fprintf(stdout," List of Possible Rates \n");
    fprintf(stdout,"-------------------------\n");
    fprintf(stdout,"%s\n",ratelist);

    free(ratelist);
    close(s);
    return;
}

static void
tr069_set_bsrate(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s, i;
    struct ieee80211req_athdbg req;
    u_int8_t *ratelist  = NULL ;

    if ((argc != 4)) {
        fprintf(stderr, "usage: wifitool athX tr069_set_bsrate value(s)");
        return;
    }

    ratelist = argv[3];
    if (strlen(argv[3]) > 256)
        return;

    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    req.cmd = IEEE80211_DBGREQ_TR069;

    req.data.tr069_req.data_addr = ratelist;
    req.data.tr069_req.cmdid = TR069_SET_BSRATE;
    req.data.tr069_req.data_size = strlen(ratelist);

    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ: IEEE80211_DBGREQ_TR069 failed");
        printf("error in ioctl \n");
        close(s);
        return;
    }

    close(s);
    return;
}


static void
tr069_get_bsrate(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr;
    int s,i;
    struct ieee80211req_athdbg req;
    char *ratelist = NULL;

    if(argc != 3) {
        fprintf(stderr, "usage: wifitool athX tr069_get_bsrate");
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    req.cmd = IEEE80211_DBGREQ_TR069;

    ratelist = (char *)malloc(256);

    if(NULL == ratelist) {
        printf("insufficient memory \n");
        close(s);
        return;
    }
    req.data.tr069_req.data_addr = ratelist;
    req.data.tr069_req.cmdid = TR069_GET_BSRATE;
    req.data.tr069_req.data_size = 256;

    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ:IEEE80211_DBGREQ_TR069 failed");
        printf("error in ioctl \n");
        free(ratelist);
        close(s);
        return;
    }

    fprintf(stdout," List of Basic Transmission Rates \n");
    fprintf(stdout,"-------------------------\n");
    fprintf(stdout,"%s\n",ratelist);

    free(ratelist);
    close(s);
    return;
}
static void
bsteer_setparams(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr = { 0 };
    struct ieee80211req_athdbg req = { 0 };
    int s = 0, value;
    char *state = NULL;
    if (argc != 10) {
        usage_bsteer_setparams();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    req.data.bsteering_param.inactivity_timeout_normal = atoi(argv[3]);
    req.data.bsteering_param.inactivity_timeout_overload = atoi(argv[4]);
    req.data.bsteering_param.utilization_sample_period = atoi(argv[5]);
    req.data.bsteering_param.utilization_average_num_samples = atoi(argv[6]);
    req.data.bsteering_param.inactive_rssi_crossing_threshold = atoi(argv[7]);
    req.data.bsteering_param.low_rssi_crossing_threshold = atoi(argv[8]);
    req.data.bsteering_param.inactivity_check_period = atoi(argv[9]);

    req.cmd = IEEE80211_DBGREQ_BSTEERING_SET_PARAMS;
    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ:"
             "IEEE80211_DBGREQ_BSTEERING_SET_PARAMS failed");
    }

    close(s);
    return;
}
static void
bsteer_getparams(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr = { 0 };
    struct ieee80211req_athdbg req = { 0 };
    int s = 0;
    if (argc != 3) {
        usage_bsteer_getparams();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    req.cmd = IEEE80211_DBGREQ_BSTEERING_GET_PARAMS;
    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ:"
             "IEEE80211_DBGREQ_BSTEERING_GET_PARAMS failed");
        close(s);
        return;
    }

    printf("Band steering parameters: \n");
    printf("-------------------------- ------------\n");
    printf("Normal inactivity timeout: %u s\n",
           req.data.bsteering_param.inactivity_timeout_normal);
    printf("Overload inactivity timeout: %u s\n",
           req.data.bsteering_param.inactivity_timeout_overload);
    printf("Utilization sampling period: %u s\n",
           req.data.bsteering_param.utilization_sample_period);
    printf("Utilization num samples to average: %u\n",
           req.data.bsteering_param.utilization_average_num_samples);
    printf("Inactive RSSI crossing threshold: %u dB\n",
           req.data.bsteering_param.inactive_rssi_crossing_threshold);
    printf("Low RSSI crossing threshold: %u dB\n",
           req.data.bsteering_param.low_rssi_crossing_threshold);
    printf("Inactivity check interval: %u s\n",
           req.data.bsteering_param.inactivity_check_period);

    close(s);
    return;
}

static void
bsteer_setdbgparams(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr = { 0 };
    struct ieee80211req_athdbg req = { 0 };
    int s = 0, value;
    char *state = NULL;
    if (argc != 5) {
        usage_bsteer_setdbgparams();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    req.data.bsteering_dbg_param.raw_chan_util_log_enable = atoi(argv[3]);
    req.data.bsteering_dbg_param.raw_rssi_log_enable = atoi(argv[4]);

    req.cmd = IEEE80211_DBGREQ_BSTEERING_SET_DBG_PARAMS;
    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ:"
             "IEEE80211_DBGREQ_BSTEERING_SET_DBG_PARAMS failed");
    }

    close(s);
    return;
}

static void
bsteer_getdbgparams(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr = { 0 };
    struct ieee80211req_athdbg req = { 0 };
    int s = 0;
    if (argc != 3) {
        usage_bsteer_getdbgparams();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    req.cmd = IEEE80211_DBGREQ_BSTEERING_GET_DBG_PARAMS;
    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ:"
             "IEEE80211_DBGREQ_BSTEERING_GET_DBG_PARAMS failed");
        close(s);
        return;
    }

    printf("Band steering debug parameters: \n");
    printf("-------------------------- ------------\n");
    printf("Enable raw channel utilization logging: %s\n",
           req.data.bsteering_dbg_param.raw_chan_util_log_enable ?
           "yes" : "no");
    printf("Enable raw RSSI measurement logging: %s\n",
           req.data.bsteering_dbg_param.raw_rssi_log_enable ?
           "yes" : "no");

    close(s);
    return;
}

static void
bsteer_enable(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr = { 0 };
    struct ieee80211req_athdbg req = { 0 };
    int s = 0, value;
    char *state = NULL;
    if (argc != 4) {
        usage_bsteer_enable();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    req.data.bsteering_enable = atoi(argv[3]);
    req.cmd = IEEE80211_DBGREQ_BSTEERING_ENABLE;
    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ:"
             "IEEE80211_DBGREQ_BSTEERING_ENABLE failed");
    }

    close(s);
    return;
}

static void
bsteer_setoverload(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr = { 0 };
    struct ieee80211req_athdbg req = { 0 };
    int s = 0, value;
    char *state = NULL;
    if (argc != 4) {
        usage_bsteer_setoverload();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    req.data.bsteering_overload = atoi(argv[3]);
    req.cmd = IEEE80211_DBGREQ_BSTEERING_SET_OVERLOAD;
    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ:"
             "IEEE80211_DBGREQ_BSTEERING_SET_OVERLOAD failed");
    }

    close(s);
    return;
}

static void
bsteer_getoverload(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr = { 0 };
    struct ieee80211req_athdbg req = { 0 };
    int s = 0;
    if (argc != 3) {
        usage_bsteer_getoverload();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    req.cmd = IEEE80211_DBGREQ_BSTEERING_GET_OVERLOAD;
    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ:"
             "IEEE80211_DBGREQ_BSTEERING_GET_OVERLOAD failed");
        close(s);
        return;
    }

    printf("%s is %soverloaded\n", ifname,
           req.data.bsteering_overload ? "" : "not ");
}

static void
bsteer_getrssi(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr = { 0 };
    struct ieee80211req_athdbg req = { 0 };
    int s = 0;
    if (argc != 5) {
        usage_bsteer_getrssi();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    req.cmd = IEEE80211_DBGREQ_BSTEERING_GET_RSSI;
    if (!wifitool_mac_aton(argv[3], &req.dstmac[0], 6)) {
        errx(1, "Invalid mac address");
        return;
    }
    req.data.bsteering_rssi_num_samples = atoi(argv[4]);
    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));

    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        perror("bsteer_getrssi");
        errx(1, "IEEE80211_IOCTL_DBGREQ:"
             "IEEE80211_DBGREQ_BSTEERING_GET_RSSI failed");
        close(s);
        return;
    }
}

static void
bsteer_setproberespwh(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr = { 0 };
    struct ieee80211req_athdbg req = { 0 };
    int s = 0;
    if (argc != 5) {
        usage_bsteer_setproberespwh();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    req.cmd = IEEE80211_DBGREQ_BSTEERING_SET_PROBE_RESP_WH;
    if (!wifitool_mac_aton(argv[3], &req.dstmac[0], 6)) {
       errx(1, "Invalid mac address");
       return;
    }
    req.data.bsteering_probe_resp_wh = atoi(argv[4]);
    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));

    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        perror("bsteer_setproberespwh");
        errx(1, "IEEE80211_IOCTL_DBGREQ:"
                "IEEE80211_DBGREQ_BSTEERING_SET_PROBE_RESP_WH failed");
        close(s);
        return;
    }
}

static void
bsteer_getproberespwh(const char *ifname, int argc, char *argv[])
{
    struct iwreq iwr = { 0 };
    struct ieee80211req_athdbg req = { 0 };
    int s = 0;
    if (argc != 4) {
        usage_bsteer_getproberespwh();
        return;
    }
    memset(&req, 0, sizeof(struct ieee80211req_athdbg));
    s = socket(AF_INET, SOCK_DGRAM, 0);
    (void) memset(&iwr, 0, sizeof(iwr));
    (void) strncpy(iwr.ifr_name, ifname, sizeof(iwr.ifr_name));

    req.cmd = IEEE80211_DBGREQ_BSTEERING_GET_PROBE_RESP_WH;
    if (!wifitool_mac_aton(argv[3], &req.dstmac[0], 6)) {
        errx(1, "Invalid mac address");
        return;
    }
    iwr.u.data.pointer = (void *) &req;
    iwr.u.data.length = (sizeof(struct ieee80211req_athdbg));
    if (ioctl(s, IEEE80211_IOCTL_DBGREQ, &iwr) < 0) {
        errx(1, "IEEE80211_IOCTL_DBGREQ:"
                "IEEE80211_DBGREQ_BSTEERING_GET_PROBE_RESP_WH failed");
        close(s);
        return;
    }

    printf("Probe responses withheld for %s on %s: %s\n", argv[3], ifname,
           req.data.bsteering_probe_resp_wh ? "yes" : "no");
}

#if QCA_NSS_PLATFORM
#define HOSTAPD_CONFIG_FILE_PREFIX "/var/run/hostapd"
#else
#define HOSTAPD_CONFIG_FILE_PREFIX "/tmp/sec"
#endif

static void
get_hostapd_param(const char *ifname, int argc, char *argv[])
{
    char fname[30];
    FILE *fp;
    char *pos;
    int  buflen = 0;
    char buf[80], param[40], val[64], fpar[40];

    if (argc != 4) {
        fprintf(stderr, "usage: wifitool athX get_hostapd_param param");
        return;
    }

    (void) memset(param, '\0', sizeof(param));
    (void) memset(val, '\0', sizeof(val));
    (void) memset(buf, '\0', sizeof(buf));
    strncpy(param, argv[3],sizeof(param));
    buflen = sizeof(buf);

#if QCA_NSS_PLATFORM
    sprintf(fname, "%s-%s.conf", HOSTAPD_CONFIG_FILE_PREFIX, ifname);
#else
    sprintf(fname, "%s%s", HOSTAPD_CONFIG_FILE_PREFIX, ifname);
#endif

    if ((fp = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "Unable to open file %s\n", fname);
        return;
    }
    while(fgets(buf, buflen, fp)) {
        (void) memset(fpar, '\0', sizeof(fpar));
        if((pos = strchr(buf, '=')) != NULL)
            strncpy(fpar, buf, (pos-buf)*sizeof(char));
        if (strcmp(fpar, param) == 0) {
            pos++;
            printf("%s: %s\n", ifname, pos);
            fclose(fp);
            return;
        }
    }
    printf("%s: Parameter not found\n", ifname);
    fclose(fp);
    return;
}

static pid_t
find_pid(const char *process_name)
{
    pid_t pid = -1;
    glob_t pglob;
    char *procname, *buf;
    int buflen = strlen(process_name) + 1;
    unsigned tmp;

#if QCA_NSS_PLATFORM
    #define PROC_PATH "/proc/*/comm"
#else
    #define PROC_PATH "/proc/*/cmdline"
#endif

    /* Using glob function to list all the
     * processes names and their path using
     * pattern matching over /proc filesystem
     */
    if (glob(PROC_PATH, 0, NULL, &pglob) != 0)
        return pid;

    procname = malloc(buflen);
    if(procname == NULL) {
        goto proc_mem_fail; 
    }
    strcpy(procname, process_name);
    procname[buflen - 1] = '\0';
    buf = malloc(buflen);
    if(buf == NULL) {
        goto buf_mem_fail; 
    }

    for (tmp = 0; tmp < pglob.gl_pathc; ++tmp) {
        FILE *comm;

        if((comm = fopen(pglob.gl_pathv[tmp], "r")) == NULL)
            continue;
        if((fgets(buf, buflen, comm)) == NULL) {
            fclose(comm);
            continue;
        }
        fclose(comm);
        if(strstr(buf, procname) != NULL) {
            pid = (pid_t)atoi(pglob.gl_pathv[tmp] + strlen("/proc/"));
            break;
        }
    }

    free(buf);
buf_mem_fail:
    free(procname);
proc_mem_fail:
    globfree(&pglob);
    return pid;
#undef PROC_PATH
}

/* wifitool athX set_hostapd_param param value
 *
 * This command can be used to dynamically change a value in
 * the hostapd conf file by specifying the param exactly and
 * the value to be set
 *
 * A temporary file is created and all the previous paramters
 * and their values are copied here except the parameter to be
 * changed which gets the new value
 *
 * A SIGHUP is sent to the hostapd daemon and thus the changes
 * are effected through a daemon restart
 */

static void
set_hostapd_param(const char *ifname, int argc, char *argv[])
{
    char fname[40], tempfname[40];
    FILE *fp, *fp2;
    int buflen = 0, reslen = 0;
    char *pos;
    char buf[80], param[40], fpar[40], val[64], result[80];
    pid_t hostapd_pid;
    u_int8_t file_changed = 0;
    char hostapd_name[20]="hostapd";

    if (argc != 5) {
        fprintf(stderr, "usage: wifitool athX set_hostapd_param param value");
        return;
    }

    (void) memset(param, '\0', sizeof(param));
    (void) memset(buf, '\0', sizeof(buf));
    (void) memset(val, '\0', sizeof(val));
    (void) memset(result, '\0', sizeof(result));
    strncpy(param, argv[3],sizeof(param));
    strncpy(val, argv[4], sizeof(val));
    buflen = sizeof(buf);

#if QCA_NSS_PLATFORM
    sprintf(fname, "%s-%s.conf", HOSTAPD_CONFIG_FILE_PREFIX, ifname);
    sprintf(tempfname, "%s-%s.conf.temp", HOSTAPD_CONFIG_FILE_PREFIX, ifname);
#else
    sprintf(fname, "%s%s", HOSTAPD_CONFIG_FILE_PREFIX, ifname);
    sprintf(tempfname, "%s%s.temp", HOSTAPD_CONFIG_FILE_PREFIX, ifname);
#endif

    if ((fp = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "Unable to open %s\n", fname);
        return;
    }
    if ((fp2 = fopen(tempfname, "w")) == NULL) {
        fprintf(stderr, "Unable to create a temp file %s\n", tempfname);
        fclose(fp);
        return;
    }
    rewind(fp);
    rewind(fp2);

    while (!feof(fp)) {
        if( fgets(buf, buflen, fp) == NULL )
            break;
        (void) memset(fpar, '\0', sizeof(fpar));
        if((pos = strchr(buf, '=')) != NULL)
            strncpy(fpar, buf, (pos-buf)*sizeof(char));
        if( strcmp(fpar, param) == 0) {
            snprintf(result, sizeof(result), "%s=%s\n", param, val);
            fputs(result, fp2);
            file_changed=1;
            continue;
        }
        fputs(buf, fp2);
    }
    hostapd_pid = find_pid(hostapd_name);
    if(file_changed != 1 || hostapd_pid <= 0) {
        fprintf(stderr, "Parameter set error\n");
        remove(tempfname);
        goto clean_exit;
    }
    else {
        if(remove(fname) != 0) {
            fprintf(stderr, "Unable to remove %s\n", fname);
            goto clean_exit;
        }
        if(rename(tempfname, fname) != 0) {
            fprintf(stderr, "Unable to rename temp file %s to hostapd file %s\n", fname, tempfname);
            goto clean_exit;
        }
        kill(hostapd_pid, SIGHUP);
    }
    clean_exit:
    fclose(fp);
    fclose(fp2);
    return;
}

int
main(int argc, char *argv[])
{
	const char *ifname, *cmd;

	if (argc < 3)
		usage();

	ifname = argv[1];
	cmd = argv[2];
	if (streq(cmd, "sendaddba")) {
            send_addba(ifname, argc, argv);
	} else if (streq(cmd, "senddelba")) {
            send_delba(ifname, argc, argv);
	} else if (streq(cmd, "setaddbaresp")) {
            set_addbaresp(ifname, argc, argv);
    } else if (streq(cmd, "sendsingleamsdu")) {
            send_singleamsdu(ifname, argc, argv);
	} else if (streq(cmd, "getaddbastats")) {
            get_addbastats(ifname, argc, argv);
	} else if (streq(cmd, "sendbcnrpt")) {
            send_bcnrpt(ifname, argc, argv);
	} else if (streq(cmd, "sendtsmrpt")) {
            send_tsmrpt(ifname, argc, argv);
	} else if (streq(cmd, "sendneigrpt")) {
            send_neigrpt(ifname, argc, argv);
	} else if (streq(cmd, "sendlmreq")) {
            send_lmreq(ifname, argc, argv);
	} else if (streq(cmd, "sendbstmreq")) {
            send_bstmreq(ifname, argc, argv);
	} else if (streq(cmd, "senddelts")) {
            send_delts(ifname, argc, argv);
	} else if (streq(cmd, "sendaddts")) {
        send_addts(ifname, argc, argv);
    } else if (streq(cmd, "sendchload")) {
        send_chload(ifname, argc, argv);
    } else if (streq(cmd, "sendnhist")) {
        send_noisehistogram(ifname,argc,argv);
    } else if (streq(cmd, "sendstastats")) {
        send_stastats(ifname, argc, argv);
    } else if (streq(cmd, "sendlcireq")) {
        send_lcireq(ifname, argc, argv);
    } else if (streq(cmd, "rrmstats")) {
        get_rrmstats(ifname, argc, argv);
    } else if (streq(cmd, "sendfrmreq")) {
        send_frmreq(ifname, argc, argv);
    } else if (streq(cmd, "bcnrpt")) {
        get_bcnrpt(ifname, argc, argv);
    } else if (streq(cmd, "getrssi")) {
		get_rssi(ifname, argc, argv);
    } else if (streq(cmd, "acsreport")) {
		acs_report(ifname, argc, argv);
    } else if (streq(cmd, "setchanlist")) {
		channel_loading_channel_list_set(ifname, argc, argv);
    } else if (streq(cmd, "getchanlist")) {
		channel_loading_channel_list_get(ifname, argc, argv);
    } else if (streq(cmd, "block_acs_channel")) {
		block_acs_channel(ifname, argc, argv);
    } else if (streq(cmd, "tr069_chanhist")) {
        tr069_chan_history(ifname, argc, argv);
    } else if (streq(cmd, "get_assoc_time")) {
        get_assoc_time(ifname, argc, argv);
    } else if (streq(cmd, "tr069_txpower")) {
        tr069_txpower(ifname, argc, argv);
    } else if (streq(cmd, "tr069_gettxpower")) {
        tr069_gettxpower(ifname, argc, argv);
    } else if (streq(cmd, "tr069_guardintv")) {
        tr069_guardintv(ifname, argc, argv);
    } else if (streq(cmd, "tr069_get_guardintv")) {
        tr069_get_guardintv(ifname, argc, argv);
    } else if (streq(cmd, "tr069_getassocsta")) {
        tr069_getassocsta(ifname, argc, argv);
    } else if (streq(cmd, "tr069_getacstimestamp")) {
        tr069_gettimestamp(ifname, argc, argv);
    } else if (streq(cmd, "tr069_getacsscan")) {
        tr069_getacsscan(ifname, argc, argv);
    } else if (streq(cmd, "tr069_persta_statscount")) {
        tr069_perstastatscount(ifname, argc, argv);
    } else if (streq(cmd, "tr069_get_11hsupported")) {
        tr069_get11hsupported(ifname, argc, argv);
    } else if (streq(cmd, "tr069_get_powerrange")) {
        tr069_getpowerrange(ifname, argc, argv);
    } else if (streq(cmd, "tr069_chan_inuse")) {
        tr069_chan_inuse(ifname, argc, argv);
    } else if (streq(cmd, "tr069_set_oper_rate")) {
        tr069_set_oper_rate(ifname, argc, argv);
    } else if (streq(cmd, "tr069_get_oper_rate")) {
        tr069_get_oper_rate(ifname, argc, argv);
    } else if (streq(cmd, "tr069_get_posiblrate")) {
        tr069_get_posiblrate(ifname, argc, argv);
    } else if (streq(cmd, "tr069_set_bsrate")) {
        tr069_set_bsrate(ifname, argc, argv);
    } else if (streq(cmd, "tr069_get_bsrate")) {
        tr069_get_bsrate(ifname, argc, argv);
    } else if (streq(cmd, "get_hostapd_param")) {
        get_hostapd_param(ifname, argc, argv);
    } else if (streq(cmd, "set_hostapd_param")) {
        set_hostapd_param(ifname, argc, argv);
    } else if (streq(cmd, "supported_freq")) {
        tr069_getsupportedfrequency(ifname,argc,argv);
    } else if (streq(cmd, "bsteer_getparams")) {
        bsteer_getparams(ifname, argc, argv);
    } else if (streq(cmd, "bsteer_setparams")) {
        bsteer_setparams(ifname, argc, argv);
    } else if (streq(cmd, "bsteer_getdbgparams")) {
        bsteer_getdbgparams(ifname, argc, argv);
    } else if (streq(cmd, "bsteer_setdbgparams")) {
        bsteer_setdbgparams(ifname, argc, argv);
    } else if (streq(cmd, "bsteer_enable")) {
        bsteer_enable(ifname, argc, argv);
    } else if (streq(cmd, "bsteer_setoverload")) {
        bsteer_setoverload(ifname, argc, argv);
    } else if (streq(cmd, "bsteer_getoverload")) {
        bsteer_getoverload(ifname, argc, argv);
    } else if (streq(cmd, "bsteer_getrssi")) {
        bsteer_getrssi(ifname, argc, argv);
    } else if (streq(cmd, "rrm_sta_list")) {
        rrm_sta_list(ifname, argc, argv);
    }  else if (streq(cmd, "bsteer_setproberespwh")) {
        bsteer_setproberespwh(ifname, argc, argv);
    } else if (streq(cmd, "bsteer_getproberespwh")) {
        bsteer_getproberespwh(ifname, argc, argv);
    } else if (streq(cmd, "mu_scan")) {
        mu_scan(ifname, argc, argv);
    } else if (streq(cmd, "lteu_cfg")) {
        lteu_cfg(ifname, argc, argv);
    } else if (streq(cmd, "ap_scan")) {
        ap_scan(ifname, argc, argv);
    } else {
        usage();
    }
	return 0;
}

