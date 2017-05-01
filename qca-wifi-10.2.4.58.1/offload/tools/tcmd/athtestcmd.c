/*
 *  Copyright (c) 2014 Qualcomm Atheros, Inc.  All rights reserved. 
 *
 *  Qualcomm is a trademark of Qualcomm Incorporated, registered in the United
 *  States and other countries.  All Qualcomm Incorporated trademarks are used with
 *  permission.  Atheros is a trademark of Qualcomm Atheros, Inc., registered in
 *  the United States and other countries.  Other products and brand names may be
 *  trademarks or registered trademarks of their respective owners. 
 */
/*
 * 
 * $ATH_LICENSE_HOSTSDK0_C$
 * 
 */

#include <sys/types.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/if.h>
#include <linux/wireless.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//#include <a_types.h>

//#include <a_config.h>
#include <a_osapi.h>
#include <athdefs.h>
#ifndef bool  
typedef _Bool			bool;
#endif
#include <wmi.h>
#include <testcmd_ar988x.h>
#include <regDb.h>

#include "os_if.h"
#include "athtestcmd.h"
#include "athtypes_linux.h"

#ifdef ATHTESTCMD_LIB
#include <setjmp.h>
extern void testcmd_error(int code, const char *fmt, ...);
#define A_ERR testcmd_error
#else
#define A_ERR err
#endif

const char *progname;
const char commands[] =
"commands:\n\
--tx <frame/tx99/tx100/sine/off> \n\
      --txfreq <Tx channel or freq(default 2412)> \n\
      --txrate <rate index> \n\
      --txpwr <0-30dBm, 0.5 dBm resolution>\n\
      --tgtpwr <target power>\n\
      --pcdac <power control DAC>\n\
      --txantenna <1/2/0 (auto)>\n\
      --txpktsz <pkt size, [32-1500](default 1500)>\n\
      --txpattern <tx data pattern, 0: all zeros; 1: all ones; 2: repeating 10; 3: PN7; 4: PN9; 5: PN15\n\
      --txchain (1:on chain 0, 2:on chain 1, 3:on both)\n\
      --tpcm <forcedGain/txpwr/tgtpwr> : Set transmit power control mode, by default tpcm is set to txpwr \n\
      --ani (Enable ANI. The ANI is disabled if this option is not specified)\n\
      --scrambleroff (Disable scrambler. The scrambler is enabled by default)\n\
      --aifsn <AIFS slots num,[0-252](Used only under '--tx frame' mode)>\n\
      --shortguard (use short guard)\n\
      --mode <ht40plus/ht40minus/ht20>\n\
      --setlongpreamble <1/0>\n\
      --numpackets <number of packets to send 0-65535>\n\
      --agg <number of aggregate packets>\n\
      --bssid\n\
      --srcmac <source MAC address>\n\
      --dstmac <destination MAC address>\n\
--tx sine --txfreq <Tx channel or freq(default 2412)>\n\
--rx <promis/filter/report> \n\
      --rxfreq <Rx channel or freq(default 2412)> \n\
      --rxantenna <1/2/0 (auto)> \n\
      --rxchain <1:chain 0, 2:chain 1, 3:both>\n\
      --mode <ht40plus/ht40minus> \n\
      --ack <Enable/Disable ACK, 0:disable; 1:enable, by default ACK is enabled>\n\
      --bc <0:receive unicast frame, 1:receive broadcast frame (default)>\n\
--pm <wakeup/sleep/deepsleep>\n\
--setmac <mac addr like 00:03:7f:be:ef:11>\n\
--setbssid <mac addr like 00:03:7f:be:ef:11>\n\
--SetAntSwitchTable <table1 in hex value> <table2 in hex value>  (Set table1=0 and table2=0 will restore the default AntSwitchTable)\n\
";

#define INVALID_FREQ    0
#define AR6002_REV6     1/* temporary define here */

#ifdef AR6002_REV6
#define A_RATE_NUM      47
#define G_RATE_NUM      47
#else
#define A_RATE_NUM      28 
#define G_RATE_NUM      28
#endif

#define RATE_STR_LEN    30
typedef const char RATE_STR[RATE_STR_LEN];

const RATE_STR  bgRateStrTbl[G_RATE_NUM] = {
    { "1   Mb" },
    { "2   Mb" },
    { "5.5 Mb" },
    { "11  Mb" },
    { "6   Mb" },
    { "9   Mb" },
    { "12  Mb" },
    { "18  Mb" },
    { "24  Mb" },
    { "36  Mb" },
    { "48  Mb" },
    { "54  Mb" },
    { "HT20 MCS0 6.5   Mb" },
    { "HT20 MCS1 13    Mb" },
    { "HT20 MCS2 19.5  Mb" },
    { "HT20 MCS3 26    Mb" },
    { "HT20 MCS4 39    Mb" },
    { "HT20 MCS5 52    Mb" },
    { "HT20 MCS6 58.5  Mb" },
    { "HT20 MCS7 65    Mb" },
#ifdef AR6002_REV6
    { "HT20 MCS8 13    Mb" },
    { "HT20 MCS9 26    Mb" },
    { "HT20 MCS10 39   Mb" },
    { "HT20 MCS11 52   Mb" },
    { "HT20 MCS12 78   Mb" },
    { "HT20 MCS13 104  Mb" },
    { "HT20 MCS14 117  Mb" },
    { "HT20 MCS15 130  Mb" },
#endif
    { "HT40 MCS0 13.5    Mb" },
    { "HT40 MCS1 27.0    Mb" },
    { "HT40 MCS2 40.5    Mb" },
    { "HT40 MCS3 54      Mb" },
    { "HT40 MCS4 81      Mb" },
    { "HT40 MCS5 108     Mb" },
    { "HT40 MCS6 121.5   Mb" },
    { "HT40 MCS7 135     Mb" },
#ifdef AR6002_REV6
    { "HT40 MCS8 27      Mb" },
    { "HT40 MCS9 54      Mb" },
    { "HT40 MCS10 81     Mb" },
    { "HT40 MCS11 108    Mb" },
    { "HT40 MCS12 162    Mb" },
    { "HT40 MCS13 216    Mb" },
    { "HT40 MCS14 243    Mb" },
    { "HT40 MCS15 270    Mb" },
#endif
/* below portion(CCK short preamble rates should always be placed to the end */
    { "2(S)   Mb" },
    { "5.5(S) Mb" },
    { "11(S)  Mb" }
};

static A_UINT8 BSSID_DEFAULT[ATH_MAC_LEN] = {0x00,0x03,0x7f,0x03,0x40,0x33}; /* arbitary macAddr*/

static void rxReport(void *buf);
static A_UINT32 freqValid(A_UINT32 val);
static A_UINT16 wmic_ieee2freq(A_UINT32 chan);
static void prtRateTbl(A_UINT32 freq);
static A_UINT32 rateValid(A_UINT32 val, A_UINT32 freq);
static A_UINT32 antValid(A_UINT32 val);
static A_UINT32 txPwrValid(TCMD_CONT_TX *txCmd);
static A_STATUS ath_ether_aton(const char *orig, A_UINT8 *eth);
static A_UINT32 pktSzValid(A_UINT32 val);

static void
usage(void)
{
    fprintf(stderr, "usage:\n%s [-i device] commands\n", progname);
    fprintf(stderr, "%s\n", commands);
    prtRateTbl(INVALID_FREQ);
    A_ERR(-1, "Incorrect usage");
}

#ifdef ATHTESTCMD_LIB
static int parseCmd(const char *cmdline, char *buf, char **argv, size_t argvlen)
{
    int argc = 0;
    char *token = buf;
    strcpy(buf, cmdline);

    while ( *token && isspace(*token) )
            ++token;
    while (*token)
    {
        if (argc>=argvlen)
        {
            break;           
        }
        argv[argc++] = token;
        while ( *token && !isspace(*token) )
            ++token;
        if (*token)
        {
            *token++ = '\0';
            while ( *token && isspace(*token) )
                ++token;
        }
    }
    if (argc==0 || (argc>0 && strcmp(argv[0], "athtestcmd")!=0))
    {
        argv[0] = "athtestcmd";
    }
    return argc;
}

int tcmd_exec(const char *cmdline, void (*reportCB)(void *), jmp_buf *jbuf)
{
#define MAX_ARGS 30
    char cmdbuf[2048];
    char *argv[MAX_ARGS]; /* max 30 arguments */
    int argc = parseCmd(cmdline, cmdbuf, argv, MAX_ARGS);
#else
int main (int argc, char **argv)
{
    void (*reportCB)(void *) = NULL;
#endif /* ATHTESTCMD_LIB */
    int c,ret;
    char ifname[IFNAMSIZ];
    unsigned int cmd = 0;
    progname = argv[0];
    char buf[2048 + 8];
    /* first 32-bit is XIOCTL_CMD */
    /* second 32-bit is len */
    TCMD_CONT_TX *txCmd = (TCMD_CONT_TX *)((A_UINT32 *)buf + 2); /* first 32-bit is XIOCTL_CMD */
    TCMD_CONT_RX *rxCmd   = (TCMD_CONT_RX *)((A_UINT32 *)buf + 2);
    TCMD_PM *pmCmd = (TCMD_PM *)((A_UINT32 *)buf + 2);
    WMI_SET_LPREAMBLE_CMD *setLpreambleCmd = (WMI_SET_LPREAMBLE_CMD *)((A_UINT32 *)buf + 2);
    TCMD_SET_REG *setRegCmd = (TCMD_SET_REG *)((A_UINT32 *)buf + 2);
    A_BOOL needResponse = FALSE;    
    int datalen =0;

    memset(buf, 0, sizeof(buf));
    txCmd->numPackets = 0;
    txCmd->wlanMode = TCMD_WLAN_MODE_NOHT;
    txCmd->txChain = 1;/* default to use chain 0 */
    txCmd->tpcm = TPC_TGT_PWR;/* default to target power */
    txCmd->broadcast = 0;/* default to broadcast */
    txCmd->agg = 1;
    memcpy(txCmd->bssid,BSSID_DEFAULT,ATH_MAC_LEN);
    rxCmd->u.para.wlanMode = TCMD_WLAN_MODE_NOHT;
    rxCmd->u.para.ack = TRUE;
    rxCmd->u.para.rxChain = 1;/* default to use chain 0 */
    rxCmd->u.para.bc = 1;/* default to receive broadcast frame */

    if (argc == 1) {
        usage();
    }

    memset(ifname, '\0', IFNAMSIZ);
    strcpy(ifname, "radio0");

    while (1) {
        int option_index = 0;
        static struct option long_options[] = {
            {"version", 0, NULL, 'v'},
            {"interface", 1, NULL, 'i'},
            {"tx", 1, NULL, 't'},
            {"txfreq", 1, NULL, 'f'},
            {"txrate", 1, NULL, 'g'},
            {"txpwr", 1, NULL, 'h'},
            {"tgtpwr", 0, NULL, 'H'},
            {"pcdac", 1, NULL, 'I'},
            {"txantenna", 1, NULL, 'j'},
            {"txpktsz", 1, NULL, 'z'},
            {"txpattern", 1, NULL, 'e'},
            {"txchain", 1, NULL, 'c'},
            {"rxchain", 1, NULL, 'C'},
            {"bssid", 1, NULL, 'b'},
            {"srcmac", 1, NULL, 'd'},
            {"dstmac", 1, NULL, 'D'},
            {"rx", 1, NULL, 'r'},
            {"rxfreq", 1, NULL, 'p'},
            {"rxantenna", 1, NULL, 'q'},
            {"ack", 1, NULL, 'k'},
            {"bc", 1, NULL, 'K'},
            {"pm", 1, NULL, 'x'},
            {"setmac", 1, NULL, 's'},
            {"setbssid", 1, NULL, 'X'},
            {"ani", 0, NULL, 'a'},
            {"scrambleroff", 0, NULL, 'o'},
            {"aifsn", 1, NULL, 'u'},
            {"SetAntSwitchTable", 1, NULL, 'S'},
            {"shortguard", 0, NULL, 'G'},
            {"numpackets", 1, NULL, 'n'},
            {"agg", 1, NULL, 'N'},
            {"mode", 1, NULL, 'M'},
            {"setlongpreamble", 1, NULL, 'l'},
            {"setreg", 1, NULL, 'R'},                  
            {"regval", 1, NULL, 'V'},                
            {"flag", 1, NULL, 'F'},     
            {"writeotp", 0, NULL, 'w'},  	
            {"otpregdmn", 1, NULL, 'E'},		
            {"btaddr", 1, NULL, 'B'},			
            {"tpcm", 1, NULL, 'P'},
            {0, 0, 0, 0}
        };

        c = getopt_long(argc, argv, "vi:t:f:g:h:HI:j:z:e:c:C:b:d:D:r:p:q:k:K:x:s:X:aou:S:Gn:N:M:l:P:",
                         long_options, &option_index);
        if (c == -1)
            break;

        switch (c) {
        case 'i':
            memset(ifname, '\0', 8);
            strcpy(ifname, optarg);
            break;
        case 't':
            cmd = TESTMODE_CONT_TX;
            txCmd->testCmdId = TCMD_CONT_TX_ID;
            datalen = sizeof(TCMD_CONT_TX);
            if (!strcmp(optarg, "sine")) {
                txCmd->mode = TCMD_CONT_TX_SINE;
            } else if (!strcmp(optarg, "frame")) {
                txCmd->mode = TCMD_CONT_TX_FRAME;
            } else if (!strcmp(optarg, "tx99")) {
                txCmd->mode = TCMD_CONT_TX_TX99;
            } else if (!strcmp(optarg, "tx100")) {
                txCmd->mode = TCMD_CONT_TX_TX100;
            } else if (!strcmp(optarg, "off")) {
                txCmd->mode = TCMD_CONT_TX_OFF;
            }else {
                cmd = 0;
            }
            break;
        case 'f':
            txCmd->freq = freqValid(atoi(optarg));
            break;
        case 'G':
            txCmd->shortGuard = 1;
            break;
        case 'P':
            if(cmd == TESTMODE_CONT_TX) {
                if (!strcmp(optarg, "forcedGain")) {
                    txCmd->tpcm = TPC_FORCED_GAIN;
                } 
            }
            break;
        case 'M':
            if(cmd == TESTMODE_CONT_TX) {
                if (!strcmp(optarg, "ht20")) {
                    txCmd->wlanMode = TCMD_WLAN_MODE_HT20;
                } else if (!strcmp(optarg, "ht40plus")) {
                    txCmd->wlanMode = TCMD_WLAN_MODE_HT40PLUS;
                } else if (!strcmp(optarg, "ht40minus")) {
                    txCmd->wlanMode = TCMD_WLAN_MODE_HT40MINUS;
                } 
            } else if(cmd == TESTMODE_CONT_RX) {
                if (!strcmp(optarg, "ht20")) {
                    rxCmd->u.para.wlanMode = TCMD_WLAN_MODE_HT20;
                } else if (!strcmp(optarg, "ht40plus")) {
                    rxCmd->u.para.wlanMode = TCMD_WLAN_MODE_HT40PLUS;
                } else if (!strcmp(optarg, "ht40minus")) {
                    rxCmd->u.para.wlanMode = TCMD_WLAN_MODE_HT40MINUS;
                }
            }
            break;
        case 'n':
            txCmd->numPackets = atoi(optarg);
            break;
        case 'N':
            txCmd->agg = atoi(optarg);
            break;
        case 'g':
            /* let user input index of rateTable instead of string parse */
            txCmd->dataRate = rateValid(atoi(optarg), txCmd->freq);
            break;
        case 'h':
        {
            int txPowerAsInt;
            /* Get tx power from user.  This is given in the form of a number
             * that's either an integer, or an integer + 0.5
             */
	    double txPowerIndBm = atof(optarg);

            /*
             * Check to make sure that the number given is either an integer
             * or an integer + 0.5
             */
            txPowerAsInt = (int)txPowerIndBm;
            if (((txPowerIndBm - (double)txPowerAsInt) == 0) ||
                (((txPowerIndBm - (double)txPowerAsInt)) == 0.5) ||
                (((txPowerIndBm - (double)txPowerAsInt)) == -0.5)) {
                if (txCmd->tpcm != TPC_FORCED_GAIN)
                    txCmd->txPwr = txPowerIndBm * 2;
                else
                    txCmd->txPwr = txPowerIndBm;/* for forcedGain, do not multiply the value */
            } else {
                printf("Bad argument to --txpwr, must be in steps of 0.5 dBm\n");
            }
        }
            if (txCmd->tpcm != TPC_FORCED_GAIN) {
                /* 
                 * if tpcm was set to forcedGain through --tpcm option then do not modify tpcm
                 * --tpcm option should be eliminated eventually
                 * for now we just leave it as it is as people may have gotten used to the combination of --txpwr --tpcm  
                 */
                txCmd->tpcm = TPC_TX_PWR;
            }
            break;
        case 'H':
            txCmd->tpcm = TPC_TGT_PWR;
            break;
        case 'I':
            txCmd->tpcm = TPC_FORCED_GAIN;
            txCmd->txPwr = atof(optarg);
            break;
        case 'j':
            txCmd->antenna = antValid(atoi(optarg));
            break;       
        case 'z':
            txCmd->pktSz = pktSzValid(atoi(optarg));
            break;
        case 'e':
            txCmd->txPattern = atoi(optarg);
            break;
        case 'c':
            txCmd->txChain = atoi(optarg);
            break;
        case 'C':
            rxCmd->u.para.rxChain = atoi(optarg);
            break;
        case 'b':
            {
                A_UINT8 mac[ATH_MAC_LEN];

                if (ath_ether_aton(optarg, mac) != A_OK) {
                    A_ERR(-1, "Invalid bssid address format! \n");
                }
                memcpy(txCmd->bssid, mac, ATH_MAC_LEN);
#ifdef TCMD_DEBUG
                printf("JLU: tcmd: set bssid 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n", 
                        mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
#endif
                break;
            }
        case 'd':
            {
                A_UINT8 mac[ATH_MAC_LEN];

                if (ath_ether_aton(optarg, mac) != A_OK) {
                    A_ERR(-1, "Invalid srcmac address format! \n");
                }
                memcpy(txCmd->txStation, mac, ATH_MAC_LEN);
#ifdef TCMD_DEBUG
                printf("JLU: tcmd: set srcmac 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n", 
                        mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
#endif
                break;
            }
        case 'D':
            {
                A_UINT8 mac[ATH_MAC_LEN];

                if (ath_ether_aton(optarg, mac) != A_OK) {
                    A_ERR(-1, "Invalid dstmac address format! \n");
                }
                memcpy(txCmd->rxStation, mac, ATH_MAC_LEN);
#ifdef TCMD_DEBUG
                printf("JLU: tcmd: set dstmac 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n", 
                        mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
#endif
                txCmd->broadcast = 0;/* if destination MAC address is present then set broadcast to off */
                break;
            }
        case 'r':
            cmd = TESTMODE_CONT_RX;
	    rxCmd->testCmdId = TCMD_CONT_RX_ID;
            datalen = sizeof(TCMD_CONT_RX);
            if (!strcmp(optarg, "promis")) {
                rxCmd->act = TCMD_CONT_RX_PROMIS;
			 	printf(" Its cont Rx promis mode \n");
            } else if (!strcmp(optarg, "filter")) {
                rxCmd->act = TCMD_CONT_RX_FILTER;
				printf(" Its cont Rx  filter  mode \n");
            } else if (!strcmp(optarg, "report")) {
				 printf(" Its cont Rx report  mode \n");
                rxCmd->act = TCMD_CONT_RX_REPORT;
                needResponse = TRUE;
            } else {
                cmd = 0;
            }
            break;
        case 'p':
            rxCmd->u.para.freq = freqValid(atoi(optarg));
            break;
        case 'q':
            rxCmd->u.para.antenna = antValid(atoi(optarg));
            break;
        case 'k':
            rxCmd->u.para.ack = atoi(optarg);
            break;
        case 'K':
            rxCmd->u.para.bc = atoi(optarg);
            break;
        case 'x':
            cmd = TESTMODE_PM;
            datalen = sizeof(TCMD_PM);
            pmCmd->testCmdId = TCMD_PM_ID;
            if (!strcmp(optarg, "wakeup")) {
                pmCmd->mode = TCMD_PM_WAKEUP;
            } else if (!strcmp(optarg, "sleep")) {
                pmCmd->mode = TCMD_PM_SLEEP;
            } else if (!strcmp(optarg, "deepsleep")) {
                pmCmd->mode = TCMD_PM_DEEPSLEEP;
            } else {
                cmd = 0;
            }
            break;
        case 's':
            {
                A_UINT8 mac[ATH_MAC_LEN];

                cmd = TESTMODE_CONT_RX;
                datalen = sizeof(TCMD_CONT_RX);
                rxCmd->testCmdId = TCMD_CONT_RX_ID;
                rxCmd->act = TCMD_CONT_RX_SETMAC;
                if (ath_ether_aton(optarg, mac) != A_OK) {
                    A_ERR(-1, "Invalid mac address format! \n");
                }
                memcpy(rxCmd->u.mac.addr, mac, ATH_MAC_LEN);
#ifdef TCMD_DEBUG
                printf("JLU: tcmd: setmac 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n", 
                        mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
#endif
                break;
            }
        case 'X':
            {
                A_UINT8 mac[ATH_MAC_LEN];

                cmd = TESTMODE_CONT_RX;
                datalen = sizeof(TCMD_CONT_RX);
                rxCmd->testCmdId = TCMD_CONT_RX_ID;
                rxCmd->act = TCMD_CONT_RX_SETMAC;
                if (ath_ether_aton(optarg, mac) != A_OK) {
                    A_ERR(-1, "Invalid bssid address format! \n");
                }
                memcpy(rxCmd->u.mac.bssid, mac, ATH_MAC_LEN);
#ifdef TCMD_DEBUG
                printf("JLU: tcmd: setbssid 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n", 
                        mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
#endif
                break;
            }
        case 'u':
            {
                txCmd->aifsn = atoi(optarg) & 0xff;
                printf("AIFS:%d\n", txCmd->aifsn);
            }
            break;
        case 'a':
            if(cmd == TESTMODE_CONT_TX) {
                txCmd->enANI = TRUE;
            } else if(cmd == TESTMODE_CONT_RX) {
                rxCmd->enANI = TRUE;
            }
            break;
        case 'o':
            txCmd->scramblerOff = TRUE;
            break;
        case 'S':
            if (argc < 4)
                usage();
            cmd = TESTMODE_CONT_RX;
            datalen = sizeof(TCMD_CONT_RX);
            rxCmd->testCmdId = TCMD_CONT_RX_ID;		
            rxCmd->act = TCMD_CONT_RX_SET_ANT_SWITCH_TABLE;				
            rxCmd->u.antswitchtable.antswitch1 = strtoul(argv[2], (char **)NULL,0);
            rxCmd->u.antswitchtable.antswitch2 = strtoul(argv[3], (char **)NULL,0);
            break;
        case 'l':
            setLpreambleCmd->status = atoi(optarg);
            break;
        case 'R':
            if (argc < 5) {
                printf("usage:athtestcmd -i eth0 --setreg 0x1234 --regval 0x01 --flag 0\n");
            }
            cmd = TESTMODE_SETREG;
            datalen = sizeof (TCMD_SET_REG);
            setRegCmd->testCmdId = TCMD_SET_REG_ID;
            setRegCmd->regAddr   = strtoul(optarg, (char **)NULL, 0);//atoi(optarg);
            break; 
        case 'V':
            setRegCmd->val = strtoul(optarg, (char **)NULL, 0);
            break;            
        case 'F':
            setRegCmd->flag = atoi(optarg);
            break;                       
        case 'w':
            rxCmd->u.mac.otpWriteFlag = 1;	
            break;		
        case 'E':
            rxCmd->u.mac.regDmn[0] = 0xffff&(strtoul(optarg, (char **)NULL, 0));
            rxCmd->u.mac.regDmn[1] = 0xffff&(strtoul(optarg, (char **)NULL, 0)>>16);		
            break;		
        case 'B':
            {    				           
                A_UINT8 btaddr[ATH_MAC_LEN];
                if (ath_ether_aton(optarg, btaddr) != A_OK) {
                    A_ERR(-1, "Invalid mac address format! \n");
                } 
                memcpy(rxCmd->u.mac.btaddr, btaddr, ATH_MAC_LEN);
#ifdef TCMD_DEBUG
                printf("JLU: tcmd: setbtaddr 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n", 
                        btaddr[0], btaddr[1], btaddr[2], btaddr[3], btaddr[4], btaddr[5]);
#endif		
            }
            break;		
			
        default:
            usage();
        }
    }

    ret = cmd_init(ifname,rxReport);

    if (rxCmd->act == TCMD_CONT_RX_PROMIS ||
         rxCmd->act == TCMD_CONT_RX_FILTER) {
         if (rxCmd->u.para.freq == 0)
            rxCmd->u.para.freq = 2412;
    }

    if (datalen )
        cmd_send(buf,datalen,needResponse);
    else
        printf("data len is ZERO!! not transmitting..\n");

#if 0
    switch (cmd) {
    case TESTMODE_CONT_TX:
#ifdef CONFIG_HOST_TCMD_SUPPORT
        *(A_UINT32 *)buf = AR6000_XIOCTL_TCMD_CONT_TX;

        txPwrValid(txCmd);

        ifr.ifr_data = (void *)buf;
        if (ioctl(s, AR6000_IOCTL_EXTENDED, &ifr) < 0) {
            A_ERR(1, "%s", ifr.ifr_name);
        }
#endif /* CONFIG_HOST_TCMD_SUPPORT */
        break;
    case TESTMODE_CONT_RX:
#ifdef CONFIG_HOST_TCMD_SUPPORT
        *(A_UINT32 *)buf = AR6000_XIOCTL_TCMD_CONT_RX;

        if (rxCmd->act == TCMD_CONT_RX_PROMIS ||
             rxCmd->act == TCMD_CONT_RX_FILTER) {
            if (rxCmd->u.para.freq == 0)
                rxCmd->u.para.freq = 2412;
        }

        ifr.ifr_data = (void *)buf;
        if (ioctl(s, AR6000_IOCTL_EXTENDED, &ifr) < 0) {
            A_ERR(1, "%s", ifr.ifr_name);
        }
        if (reportCB) {
            reportCB(ifr.ifr_data);
        }
        if (needResponse) {
            rxReport(ifr.ifr_data);
            needResponse = FALSE;
        }
#endif /* CONFIG_HOST_TCMD_SUPPORT */
        break;
    case TESTMODE_PM:
#ifdef CONFIG_HOST_TCMD_SUPPORT
        *(A_UINT32 *)buf = AR6000_XIOCTL_TCMD_PM;
        ifr.ifr_data = (void *)buf;
        if (ioctl(s, AR6000_IOCTL_EXTENDED, &ifr) < 0) {
            A_ERR(1, "%s", ifr.ifr_name);
        }
#endif /* CONFIG_HOST_TCMD_SUPPORT */
        break;
    case TESTMODE_SETLPREAMBLE:
        *(A_UINT32 *)buf = AR6000_XIOCTL_WMI_SET_LPREAMBLE;
        ifr.ifr_data = (void *)buf;
        if (ioctl(s, AR6000_IOCTL_EXTENDED, &ifr) < 0) {
            A_ERR(1, "%s", ifr.ifr_name);
        }   
        break;   
    case TESTMODE_SETREG:
        *(A_UINT32 *)buf = AR6000_XIOCTL_TCMD_SETREG;
        ifr.ifr_data = (void *)buf;
        if (ioctl(s, AR6000_IOCTL_EXTENDED, &ifr) < 0) {
            printf("%s", ifr.ifr_name);
        }   
        break;              
    default:
        usage();
    }
#endif

#ifdef ATHTESTCMD_LIB
    return 0;
#else
    exit (0);
#endif
}

static void
rxReport(void *buf)
{
    A_UINT8 *reply = (A_UINT8*)buf;
    A_UINT32 length =0;

    length = *(A_UINT32 *)&(reply[0]);

    printf("Got response len %d..\n",length);
#if 0
    A_UINT32 pkt;
    A_INT32  rssi;
    A_UINT32 crcError;
    A_UINT32 secErr;
    A_UINT16 rateCnt[TCMD_MAX_RATES];
    A_UINT16 rateCntShortGuard[TCMD_MAX_RATES];
    A_UINT16 rcidx=0;
    A_UINT16 rcsidx=0;

    pkt = *(A_UINT32 *)buf;
    rssi = *((A_INT32 *)buf + 1);
    crcError = *((A_UINT32 *)buf + 2);
    secErr = *((A_UINT32 *)buf + 3);

    printf("total pkt %d ; crcError pkt %d ; secErr pkt %d ;  average rssi %d\n", pkt, crcError, secErr,
          (A_INT32)( pkt ? (rssi / (A_INT32)pkt) : 0));


    A_MEMCPY(rateCnt, ((A_UCHAR *)buf)+(4*sizeof(A_UINT32)), sizeof(rateCnt));
    A_MEMCPY(rateCntShortGuard, ((A_UCHAR *)buf)+(4*sizeof(A_UINT32))+(TCMD_MAX_RATES * sizeof(A_UINT16)), sizeof(rateCntShortGuard));

    if (rateCnt[rcidx])
        printf("1Mbps      %d\n", rateCnt[rcidx]);
    rcidx++;
    if (rateCnt[rcidx])
        printf("2Mbps(L)   %d\n",rateCnt[rcidx]);
    rcidx++;
    if (rateCnt[TCMD_MAX_RATES-3])
        printf("2Mbps(S)   %d\n",rateCnt[TCMD_MAX_RATES-3]);
    if (rateCnt[rcidx])
        printf("5.5Mbps(L) %d\n",  rateCnt[rcidx]);
    rcidx++;
    if (rateCnt[TCMD_MAX_RATES-2])
        printf("5.5Mbps(S) %d\n",  rateCnt[TCMD_MAX_RATES-2]);
    if (rateCnt[rcidx])
        printf("11Mbps(L)  %d\n",  rateCnt[rcidx++]);
    rcidx++;
    if (rateCnt[TCMD_MAX_RATES-1])
        printf("11Mbps(S)  %d\n", rateCnt[TCMD_MAX_RATES-1]);
    if (rateCnt[rcidx])
        printf("6Mbps      %d\n", rateCnt[rcidx]);
    rcidx++;
    if (rateCnt[rcidx])
        printf("9Mbps      %d\n", rateCnt[rcidx]);
    rcidx++;
    if (rateCnt[rcidx])
        printf("12Mbps     %d\n", rateCnt[rcidx]);
    rcidx++;
    if (rateCnt[rcidx])
        printf("18Mbps     %d\n", rateCnt[rcidx]);
    rcidx++;
    if (rateCnt[rcidx])
        printf("24Mbps     %d\n", rateCnt[rcidx]);
    rcidx++;
    if (rateCnt[rcidx])
        printf("36Mbps     %d\n", rateCnt[rcidx]);
    rcidx++;
    if (rateCnt[rcidx])
        printf("48Mbps     %d\n", rateCnt[rcidx]);
    rcidx++;
    if (rateCnt[rcidx])
        printf("54Mbps     %d\n", rateCnt[rcidx]);
    rcidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT20 MCS0 6.5Mbps   %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT20 MCS1 13Mbps    %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT20 MCS2 19.5Mbps  %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT20 MCS3 26Mbps    %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT20 MCS4 39Mbps    %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT20 MCS5 52Mbps    %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT20 MCS6 58.5Mbps  %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT20 MCS7 65Mbps    %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
#ifdef AR6002_REV6
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT20 MCS8 13Mbps    %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT20 MCS9 26Mbps    %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT20 MCS10 39Mbps   %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT20 MCS11 52Mbps   %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT20 MCS12 78Mbps   %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT20 MCS13 104Mbps  %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT20 MCS14 117Mbps  %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT20 MCS15 130Mbps  %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
#endif
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT40 MCS0 13.5Mbps  %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT40 MCS1 27.0Mbps  %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT40 MCS2 40.5Mbps  %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT40 MCS3 54Mbps    %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT40 MCS4 81Mbps    %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT40 MCS5 108Mbps   %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT40 MCS6 121.5Mbps %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT40 MCS7 135Mbps   %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
#ifdef AR6002_REV6
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT40 MCS8 27Mbps    %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT40 MCS9 54Mbps    %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT40 MCS10 81Mbps   %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT40 MCS11 108Mbps  %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT40 MCS12 162Mbps  %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT40 MCS13 216Mbps  %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT40 MCS14 243Mbps  %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
    if (rateCnt[rcidx] || rateCntShortGuard[rcsidx])
        printf("HT40 MCS15 270Mbps  %d (SGI: %d)\n", rateCnt[rcidx], rateCntShortGuard[rcsidx]);
    rcidx++;rcsidx++;
#endif
    printf("\n");	
#endif
}

static A_UINT32
freqValid(A_UINT32 val)
{
    do {
        if (val <= A_CHAN_MAX) {
            A_UINT16 freq;

            if (val < BG_CHAN_MIN)
                break;

            freq = wmic_ieee2freq(val);
            if (INVALID_FREQ == freq)
                break;
            else
                return freq;
        }

        if ((val == BG_FREQ_MAX) || 
            ((val < BG_FREQ_MAX) && (val >= BG_FREQ_MIN) && !((val - BG_FREQ_MIN) % 5)))
            return val;
        else if ((val >= A_FREQ_MIN) && (val < A_20MHZ_BAND_FREQ_MAX) && !((val - A_FREQ_MIN) % 20))
            return val;
        else if ((val >= A_20MHZ_BAND_FREQ_MAX) && (val <= A_FREQ_MAX) && !((val - A_20MHZ_BAND_FREQ_MAX) % 5))
            return val;
    } while (FALSE);

    A_ERR(-1, "Invalid channel or freq #: %d !\n", val);
    return 0;
}

static A_UINT32 rateValid(A_UINT32 val, A_UINT32 freq)
{
    if (((freq >= A_FREQ_MIN) && (freq <= A_FREQ_MAX) && (val >= A_RATE_NUM)) ||
        ((freq >= BG_FREQ_MIN) && (freq <= BG_FREQ_MAX) && (val >= G_RATE_NUM))) {
        printf("Invalid rate value %d for frequency %d! \n", val, freq);
        prtRateTbl(freq);
        A_ERR(-1, "Invalid rate value %d for frequency %d! \n", val, freq);
    }

    return val;
}

static void prtRateTbl(A_UINT32 freq)
{
    int i;

        for (i = 0; i < G_RATE_NUM; i++) {
            printf("<rate> %d \t \t %s \n", i, bgRateStrTbl[i]);
        }
        printf("\n");
    }
    
/*
 * converts ieee channel number to frequency
 */
static A_UINT16
wmic_ieee2freq(A_UINT32 chan)
{
    if (chan == BG_CHAN_MAX) {
        return BG_FREQ_MAX;
    }
    if (chan < BG_CHAN_MAX) {    /* 0-13 */
        return (BG_CHAN0_FREQ + (chan*5));
    }
    if (chan <= A_CHAN_MAX) {
        return (A_CHAN0_FREQ + (chan*5));
    }
    else {
        return INVALID_FREQ;
    }
}

static A_UINT32 antValid(A_UINT32 val)
{
    if (val > 2) {
        A_ERR(-1, "Invalid antenna setting! <0: auto;  1/2: ant 1/2>\n");
    }

//    return val;
    return 0;  //TODO: antenna diversity currently not supported
}

static A_UINT32 txPwrValid(TCMD_CONT_TX *txCmd)
{
#if 0
    if (txCmd->mode == TCMD_CONT_TX_SINE) {
        if ((txCmd->txPwr >= 0) && (txCmd->txPwr <= 10))
            return txCmd->txPwr;
    } else if (txCmd->mode != TCMD_CONT_TX_OFF) {
        if ((txCmd->txPwr >= -15) && (txCmd->txPwr <= 30))
            return txCmd->txPwr;
    } else if (txCmd->mode == TCMD_CONT_TX_OFF) {
        return 0;
    }

    A_ERR(1, "Invalid Tx Power value! \nTx data: [-15 - 14]dBm  \nTx sine: [-15 - 11]dBm  \n");
    return 0;
#endif
    return txCmd->txPwr;
}
static A_UINT32 pktSzValid(A_UINT32 val)
{
    if (( val < 32 )||(val > 1500)){
        A_ERR(-1, "Invalid package size! < 32 - 1500 >\n");
    }
    return val;
}
#ifdef NOTYET

// Validate a hex character
static A_BOOL
_is_hex(char c)
{
    return (((c >= '0') && (c <= '9')) ||
            ((c >= 'A') && (c <= 'F')) ||
            ((c >= 'a') && (c <= 'f')));
}

// Convert a single hex nibble
static int
_from_hex(char c) 
{
    int ret = 0;

    if ((c >= '0') && (c <= '9')) {
        ret = (c - '0');
    } else if ((c >= 'a') && (c <= 'f')) {
        ret = (c - 'a' + 0x0a);
    } else if ((c >= 'A') && (c <= 'F')) {
        ret = (c - 'A' + 0x0A);
    }
    return ret;
}

// Convert a character to lower case
static char
_tolower(char c)
{
    if ((c >= 'A') && (c <= 'Z')) {
        c = (c - 'A') + 'a';
    }
    return c;
}

// Validate alpha
static A_BOOL
isalpha(int c)
{
    return (((c >= 'a') && (c <= 'z')) || 
            ((c >= 'A') && (c <= 'Z')));
}

// Validate digit
static A_BOOL
isdigit(int c)
{
    return ((c >= '0') && (c <= '9'));
}

// Validate alphanum
static A_BOOL
isalnum(int c)
{
    return (isalpha(c) || isdigit(c));
}
#endif

/*------------------------------------------------------------------*/
/*
 * Input an Ethernet address and convert to binary.
 */
static A_STATUS
ath_ether_aton(const char *orig, A_UINT8 *eth)
{
    int mac[6];
    if (sscanf(orig, "%02x:%02x:%02X:%02X:%02X:%02X", 
               &mac[0], &mac[1], &mac[2],  
               &mac[3], &mac[4], &mac[5])==6) {
        int i;
#ifdef DEBUG
        if (*(orig+12+5) !=0) {
            fprintf(stderr, "%s: trailing junk '%s'!\n", __func__, orig);
            return A_EINVAL;
        }
#endif
        for (i=0; i<6; ++i) 
            eth[i] = mac[i] & 0xff;
        return A_OK;
    }
    return A_EINVAL;
}
