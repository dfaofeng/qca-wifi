/*
 * Copyright (c) 2006 Atheros Communications Inc.
 * All rights reserved.
 * 
 * $ATH_LICENSE_HOSTSDK0_C$
 * 
 */
/*
 * Copyright (c) 2013 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#include <sys/types.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/if.h>
#include <linux/wireless.h>
#include <linux/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//#include <a_types.h>
#include <a_osapi.h>
#include <athdefs.h>
#include <athtypes_linux.h>
#include <testcmd_ar988x.h>
#include <regDb.h>

#include "athtestcmd.h"
#include <os_if.h>

#include "cmdOpcodes.h"
#include "tcmdHostInternal.h"
#include "maskRateCommon.h"
#include "art_utf_common.h"
#include "genTxBinCmdTlv.h"
#include "parseRxBinCmdTlv.h"

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
      --txpwr <0-30dBm, 0.5 dBm resolution; sine: 0-60, PCDAC vaule>\n\
      --tgtpwr <target power>\n\
      --pcdac <power control DAC>\n\
      --gainIdx <tx gain table index>\n\
      --dacGain <DAC gain>\n\
      --forcedGain <power control DAC>\n\
      --txantenna <1/2/0 (auto)>\n\
      --txpktsz <pkt size, [32-1500](default 1500)>\n\
      --txpattern <tx data pattern, 0: all zeros; 1: all ones; 2: repeating 10; 3: PN7; 4: PN9; 5: PN15\n\
      --txchain (1:on chain 0, 2:on chain 1, 3:on both)\n\
      --tpcm <forcedTgtPwr/forcedGainIdx/forcedGain/txpwr/tgtpwr> : Set transmit power control mode, by default tpcm is set to txpwr \n\
      --ani (Enable ANI. The ANI is disabled if this option is not specified)\n\
      --paprd (Enable PAPRD. The PAPRD is disabled if this option is not specified)\n\
      --stbc (Enable STBC. STBC is disabled if this option is not specified)\n\
      --ldpc (Enable LDPC. LDPC is disabled if this option is not specified)\n\
      --scrambleroff (Disable scrambler. The scrambler is enabled by default)\n\
      --aifsn <AIFS slots num,[0-252](Used only under '--tx frame' mode)>\n\
      --shortguard (use short guard)\n\
      --mode <ht40plus/ht40minus/ht20/vht20/vht40plus/vht40minus/vht80_0/vht80_1/vht80_2/vht80_3>\n\
      --bw <full/half/quarter>\n\
      --setlongpreamble <1/0>\n\
      --numpackets <number of packets to send 0-65535>\n\
--tx sine --txfreq <Tx channel or freq(default 2412)>\n\
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
      --lpl <0:LPL off(default), 1:reduced receive, 2:reduced search>\n\
--pm <wakeup/sleep/deepsleep>\n\
--setmac <mac addr like 00:03:7f:be:ef:11>\n\
--setbssid <mac addr like 00:03:7f:be:ef:11>\n\
--SetAntSwitchTable <table1 in hex value> <table2 in hex value>  (Set table1=0 and table2=0 will restore the default AntSwitchTable)\n\
--efusedump --start <start address> --end <end address>\n\
--efusewrite --start <start address> --data <data> (could be one or multiple data in quotation marks)\n\
--otpwrite --data (could be one or multiple data in quotation marks)\n\
--otpdump\n\
--btmode <put DUT into BT mode>\n\
";


void setPowerPerRateIndex(A_BOOL is11ACRate,A_UINT32 value);

#define INVALID_FREQ    0
#define AR6002_REV6     1/* temporary define here */

#define A_RATE_NUM      153
#define G_RATE_NUM      153

#define MAX_FRAME_LENGTH         1500
#define TX_FRAME_DURATION        340  // the following 4 values are in micro seconds
#define PREAMBLE_TIME_OFDM       20
#define PREAMBLE_TIME_CCK_LONG   192
#define PREAMBLE_TIME_CCK_SHORT  96
#define SLOT_TIME                9
#define SLOT_TIME_LONG           20
#define MAX_NUM_SLOTS            255

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
    { "HT20 MCS8 13    Mb" },
    { "HT20 MCS9 26    Mb" },
    { "HT20 MCS10 39   Mb" },
    { "HT20 MCS11 52   Mb" },
    { "HT20 MCS12 78   Mb" },
    { "HT20 MCS13 104  Mb" },
    { "HT20 MCS14 117  Mb" },
    { "HT20 MCS15 130  Mb" },
    { "HT20 MCS16 19.5 Mb" },
    { "HT20 MCS17 39   Mb" },
    { "HT20 MCS18 58.5 Mb" },
    { "HT20 MCS19 78   Mb" },
    { "HT20 MCS20 117  Mb" },
    { "HT20 MCS21 156  Mb" },
    { "HT20 MCS22 175.5  Mb" },
    { "HT20 MCS23 195    Mb" },
    { "HT40 MCS0 13.5    Mb" },
    { "HT40 MCS1 27.0    Mb" },
    { "HT40 MCS2 40.5    Mb" },
    { "HT40 MCS3 54      Mb" },
    { "HT40 MCS4 81      Mb" },
    { "HT40 MCS5 108     Mb" },
    { "HT40 MCS6 121.5   Mb" },
    { "HT40 MCS7 135     Mb" },
    { "HT40 MCS8 27      Mb" },
    { "HT40 MCS9 54      Mb" },
    { "HT40 MCS10 81     Mb" },
    { "HT40 MCS11 108    Mb" },
    { "HT40 MCS12 162    Mb" },
    { "HT40 MCS13 216    Mb" },
    { "HT40 MCS14 243    Mb" },
    { "HT40 MCS15 270    Mb" },
    { "HT40 MCS16 40.5   Mb" },
    { "HT40 MCS17 81     Mb" },
    { "HT40 MCS18 121.5  Mb" },
    { "HT40 MCS19 162    Mb" },
    { "HT40 MCS20 243    Mb" },
    { "HT40 MCS21 324    Mb" },
    { "HT40 MCS22 364.5  Mb" },
    { "HT40 MCS23 405    Mb" },
    { "VHT20 MCS0 S1 6.5 Mb" }, //60
    { "VHT20 MCS1 S1 13 Mb" },
    { "VHT20 MCS2 S1 19.5 Mb" },
    { "VHT20 MCS3 S1 26 Mb" }, //63
    { "VHT20 MCS4 S1 39 Mb" },
    { "VHT20 MCS5 S1 52 Mb" },
    { "VHT20 MCS6 S1 58.5 Mb" },
    { "VHT20 MCS7 S1 65 Mb" },
    { "VHT20 MCS8 S1 78 Mb" },
    { "VHT20 MCS9 S1 86 Mb" },
    { "VHT20 MCS0 S2 13 Mb" },
    { "VHT20 MCS1 S2 26 Mb" },
    { "VHT20 MCS2 S2 39 Mb" },
    { "VHT20 MCS3 S2 52 Mb" },
    { "VHT20 MCS4 S2 78 Mb" },
    { "VHT20 MCS5 S2 104 Mb" },
    { "VHT20 MCS6 S2 117 Mb" },
    { "VHT20 MCS7 S2 130 Mb" },
    { "VHT20 MCS8 S2 156 Mb" },
    { "VHT20 MCS9 S2 173" },
    { "VHT20 MCS0 S3 19.5 Mb" },
    { "VHT20 MCS1 S3 39 Mb" },
    { "VHT20 MCS2 S3 58.5 Mb" },
    { "VHT20 MCS3 S3 78 Mb" },
    { "VHT20 MCS4 S3 117 Mb" },
    { "VHT20 MCS5 S3 156 Mb" },
    { "VHT20 MCS6 S3 175.5 Mb" },
    { "VHT20 MCS7 S3 195 Mb" },
    { "VHT20 MCS8 S3 234 Mb" },
    { "VHT20 MCS9 S3 260 Mb" },
    { "VHT40 MCS0 S1 13.5 Mb" },
    { "VHT40 MCS1 S1 27 Mb" },
    { "VHT40 MCS2 S1 40.5 Mb" },
    { "VHT40 MCS3 S1 54 Mb" },
    { "VHT40 MCS4 S1 81 Mb" },
    { "VHT40 MCS5 S1 108 Mb" },
    { "VHT40 MCS6 S1 121.5 Mb" },
    { "VHT40 MCS7 S1 135 Mb" },
    { "VHT40 MCS8 S1 162 Mb" },
    { "VHT40 MCS9 S1 180 Mb" },
    { "VHT40 MCS0 S2 27 Mb" },
    { "VHT40 MCS1 S2 54 Mb" },
    { "VHT40 MCS2 S2 81 Mb" },
    { "VHT40 MCS3 S2 108 Mb" },
    { "VHT40 MCS4 S2 162 Mb" },
    { "VHT40 MCS5 S2 216 Mb" },
    { "VHT40 MCS6 S2 243 Mb" },
    { "VHT40 MCS7 S2 270 Mb" },
    { "VHT40 MCS8 S2 324 Mb" },
    { "VHT40 MCS9 S2 360 Mb" },
    { "VHT40 MCS0 S3 40.5 Mb" },
    { "VHT40 MCS1 S3 81 Mb" },
    { "VHT40 MCS2 S3 121.5 Mb" },
    { "VHT40 MCS3 S3 162 Mb" },
    { "VHT40 MCS4 S3 243 Mb" },
    { "VHT40 MCS5 S3 324 Mb" },
    { "VHT40 MCS6 S3 364.5 Mb" },
    { "VHT40 MCS7 S3 405 Mb" },
    { "VHT40 MCS8 S3 486 Mb" },
    { "VHT40 MCS9 S3 540 Mb" },
    { "VHT80 MCS0 S1 29.3 Mb" },
    { "VHT80 MCS1 S1 58.5 Mb" },
    { "VHT80 MCS2 S1 87.8 Mb" },
    { "VHT80 MCS3 S1 117 Mb" },
    { "VHT80 MCS4 S1 175.5 Mb" },
    { "VHT80 MCS5 S1 234 Mb" },
    { "VHT80 MCS6 S1 263.3 Mb" },
    { "VHT80 MCS7 S1 292.5 Mb" },
    { "VHT80 MCS8 S1 351 Mb" },
    { "VHT80 MCS9 S1 390 Mb" },
    { "VHT80 MCS0 S2 58.5 Mb" },
    { "VHT80 MCS1 S2 117 Mb" },
    { "VHT80 MCS2 S2 175.5 Mb" },
    { "VHT80 MCS3 S2 234 Mb" },
    { "VHT80 MCS4 S2 351 Mb" },
    { "VHT80 MCS5 S2 468 Mb" },
    { "VHT80 MCS6 S2 526.5 Mb" },
    { "VHT80 MCS7 S2 585 Mb" },
    { "VHT80 MCS8 S2 702 Mb" },
    { "VHT80 MCS9 S2 780 Mb" },
    { "VHT80 MCS0 S3 87.8 Mb" },
    { "VHT80 MCS1 S3 175.5 Mb" },
    { "VHT80 MCS2 S3 263.3 Mb" },
    { "VHT80 MCS3 S3 351 Mb" },
    { "VHT80 MCS4 S3 526.5 Mb" },
    { "VHT80 MCS5 S3 702 Mb" },
    { "VHT80 MCS6 S3 789.8 Mb" },
    { "VHT80 MCS7 S3 877.5 Mb" },
    { "VHT80 MCS8 S3 1053 Mb" },
    { "VHT80 MCS9 S3 1170 Mb" },
/* below portion(CCK short preamble rates should always be placed to the end */
    { "2(S)   Mb" },
    { "5.5(S) Mb" },
    { "11(S)  Mb" }
};

const float ActualDataRate[] = {
/* CCK  */            1.0,  2.0,  5.5,  11.0,                              //0 - 3
/* OFDM */            6.0,  9.0,  12.0, 18.0, 24.0, 36.0, 48.0, 54.0,      // 4 - 11
/* MCS 20 1S */       6.5,  13.0, 19.5, 26.0, 39.0, 52.0, 58.5, 65.0,      // 12 - 19
#ifdef AR6002_REV6
/* MCS 20 2S */       13.0, 26.0, 39.0, 52.0, 78.0, 104.0,117.0,130.0,     // 20 - 27
#endif
/* MCS 40 1S */       13.5, 27.0, 40.5, 54.0, 81.0, 108.0,121.5,135.0,     // 28 - 35
#ifdef AR6002_REV6
/* MCS 40 2S */       27.0, 54.0, 81.0, 108.0, 162.0, 216.0, 243.0, 270.0 ,// 36 - 43
#endif
/* CCK       */       2.0,  5.5,  11,0                                     // 44 - 45
};

static A_UINT32 freqValid(A_UINT32 val);
static A_UINT16 wmic_ieee2freq(A_UINT32 chan);
static void prtRateTbl(A_UINT32 freq);
static A_UINT32 rateValid(A_UINT32 val, A_UINT32 freq);
static A_UINT32 antValid(A_UINT32 val);
static A_STATUS ath_ether_aton(const char *orig, A_UINT8 *eth);
static A_UINT32 pktSzValid(A_UINT32 val);
static A_INT32 computeNumSlots(A_UINT32 dutyCycle, A_UINT32 dataRateIndex, float txFrameDurationPercent);

static void
usage(void)
{
    fprintf(stderr, "usage:\n%s [-i device] commands\n", progname);
    fprintf(stderr, "%s\n", commands);
    prtRateTbl(INVALID_FREQ);
    A_ERR(-1, "Incorrect usage");
}

void parseResponse()
{
    A_BOOL ret = TRUE;
    A_UINT8 *data;
    A_UINT32 status,len;

    ret = getParams((A_UINT8*)"status", &data, &len);

    if ( ret == TRUE )
    {
        memcpy(&status,data,len);
        printf("Response status %d\n",status);
    }
    else
        printf("In parseResponse status not found\n");
}

void parseTLVSubmitReport()
{
    A_BOOL ret = TRUE;
    A_UINT8 *data;
    A_UINT32 value,totalpkt,len,i,k;
    A_INT32 rssi;
    A_UINT8 rateCntBuf[25];
    A_UINT32 rateMask,rateMaskCnt[2],shortGuard,dataRate,index=0;
    A_UINT32 rate11ACMaskCnt[4];
    A_UINT32 bit0 = 0x00000001;

    ret = getParams((A_UINT8*)"totalpkt", &data, &len);

    if ( ret == TRUE )
    {
        memcpy(&totalpkt,data,len);
        printf("totalpkt %d\n",totalpkt);
    }

    ret = getParams((A_UINT8*)"rssiInDBm", &data, &len);

    if ( ret == TRUE )
    {
        memcpy(&rssi,data,len);

        if(totalpkt)
            printf("rssiInDBm %d\n",rssi/(A_INT32)totalpkt);
        else
            printf("rssiInDBm %d\n",rssi);
    }

    ret = getParams((A_UINT8*)"crcErrPkt", &data, &len);

    if ( ret == TRUE )
    {
        memcpy(&value,data,len);
        printf("crcErrPkt %d\n",value);
    }

    ret = getParams((A_UINT8*)"secErrPkt", &data, &len);

    if ( ret == TRUE )
    {
        memcpy(&value,data,len);
        printf("secErrPkt %d\n",value);
    }

    for(i=0;i<2;i++)
    {
        memset(rateCntBuf,0,sizeof(rateCntBuf));
        sprintf((char*)rateCntBuf,"%s%d","rcMask",i);
        ret = getParams((A_UINT8*)rateCntBuf,&data,&len);

        if ( ret == TRUE )
        {
            memcpy(&rateMaskCnt[i],data,len);
            //printf("%s %x\n",rateCntBuf,rateMaskCnt[i]);
        }
        else
        {
            rateMaskCnt[i] = 0;
        }
    }

    for(i=0;i<4;i++)
    {
        memset(rateCntBuf,0,sizeof(rateCntBuf));
        sprintf((char*)rateCntBuf,"%s%d","rcMask11ac",i);
        ret = getParams((A_UINT8*)rateCntBuf,&data,&len);

        if ( ret == TRUE )
        {
            memcpy(&rate11ACMaskCnt[i],data,len);
            //printf("%s %x\n",rateCntBuf,rate11ACMaskCnt[i]);
        }
        else
        {
            rate11ACMaskCnt[i] = 0;
        }
    }

    ret = getParams((A_UINT8*)"shortGuard", &data, &len);

    if ( ret == TRUE )
    {
        memcpy(&shortGuard,data,len);

        if ( shortGuard )
            printf("<<<<SGI set >>>>\n");
    }

    //11n and below rates..
    for (k=0;k<2;k++)
    {
        rateMask = rateMaskCnt[k];
        i=0; bit0=0x00000001;
        while (rateMask)
        {
            if (bit0 & rateMask)
            {
                rateMask &= ~bit0;
                dataRate = Mask2Rate[k][i];

                if (dataRate == ATH_RATE_2M || dataRate == ATH_RATE_5_5M || dataRate == ATH_RATE_11M){ /* CCK rates */
                    if (!(i&1)) /* even number indicates short preamble, see Mask2Rate array for details */
                        dataRate += (TCMD_MAX_RATES - 4);/* use last three rates in the rate table for shortPreamble */
                }

                //printf("RateCnt bit set %d dataRate %d %s\n",(k*32+i),dataRate,bgRateStrTbl[dataRate]);
                printf("%s .. ",bgRateStrTbl[dataRate]);

                index = (k*32+i)/2;

                memset(rateCntBuf,0,sizeof(rateCntBuf));
                sprintf((char*)rateCntBuf,"%s%d","rateCnt",index);
                ret = getParams((A_UINT8*)rateCntBuf,&data,&len);

                if ( ret == TRUE )
                {
                    memcpy(&value,data,len);

                    if (i && !(i&1))  
                        printf("rateCnt %d\n",(value & 0xFFFF));
                    else {
                        if (i && (i&1)) {
                            printf("rateCnt %d\n",(value >>16) & 0xFFFF);
                        }
                        else{
                            printf("rateCnt %d\n",(value & 0xFFFF));
                        }
                    }
                }
                else {
                    printf("rateCnt ..%d\n",0);
                }
	    }

            bit0 = bit0 << 1;i++;
        }
    }

    //11ac rates..
    for (k=0;k<4;k++)
    {
        rateMask = rate11ACMaskCnt[k];
        i=0; bit0=0x00000001;
        while (rateMask)
        {
            if (bit0 & rateMask)
            {
                rateMask &= ~bit0;
                index = k + 2;
                dataRate = Mask2Rate[index][i];
                //printf("11ac RateCnt bit set %d dataRate %d %s\n",(k*32+i),dataRate,bgRateStrTbl[dataRate]);
                printf("%s .. ",bgRateStrTbl[dataRate]);

                index = (k*32+i)/2;

                memset(rateCntBuf,0,sizeof(rateCntBuf));
                sprintf((char*)rateCntBuf,"%s%d","rateCnt11ac",index);
                ret = getParams((A_UINT8*)rateCntBuf,&data,&len);

                if ( ret == TRUE )
                {
                    memcpy(&value,data,len);

                    if (i && !(i&1))
                        printf("rateCnt %d\n",(value & 0xFFFF));
                    else {
                        if (i && (i&1)) {
                            printf("rateCnt %d\n",(value >>16) & 0xFFFF);
                        }
                        else{
                            printf("rateCnt %d\n",(value & 0xFFFF));
                        }
                    }
                }
            }

            bit0 = bit0 << 1;i++;
        }
    }
}

// 1 byte per rate (power value)
// For now.. let's make powerGainStart same for all rates..  (0-15)
void getPowerGain(unsigned int *pwrGain,unsigned int value)
{
    int i=0;

    *pwrGain = 0;
    for(i=0;i<4;i++)
    {
        *pwrGain = *pwrGain | value;
        value = value << 8;
    }
}

void rateIndexToArrayMapping (A_UINT32 rateIndex, A_UINT32 *rowIndex, A_UINT32 *bitmask, A_BOOL *is11AcRate )
{
    *is11AcRate = FALSE;

    if ((rateIndex == 150) || (rateIndex==151) || (rateIndex==152) ) {
        *is11AcRate = FALSE;
    }
    else if (rateIndex >= 60)
        *is11AcRate = TRUE;

    printf("Is11AcRate %d\n",*is11AcRate);

    switch(rateIndex)
    {
        case 0: // 1 Mb
            *rowIndex = 0;
            *bitmask = 0x00000001; // set Bit 1
             break;
        case 1: // 2 Mb Long CCK
            *rowIndex = 0;
            *bitmask = 0x00000002; // set Bit 2
             break;
        case 150: // 2 Mb Short CCK
            *rowIndex = 0;
            *bitmask = 0x00000004; // set Bit 3 (SHORT CCK)
             break;
        case 2: // 5.5 Mb Long CCK
            *rowIndex = 0;
            *bitmask = 0x00000008; // set Bit 4
             break;
        case 151: // 5.5 Mb Short CCK
            *rowIndex = 0;
            *bitmask = 0x00000010; // set Bit 5 (SHORT CCK)
             break;
        case 3: // 11 Mb Long CCK
            *rowIndex = 0;
            *bitmask = 0x00000020; // set Bit 6
             break;
        case 152: // 11 Mb Short CCK
            *rowIndex = 0;
            *bitmask = 0x00000040; // set Bit 7 (SHORT CCK)
             break;

        case 4: // 6 Mb
            *rowIndex = 0;
            *bitmask = 0x00000100;
             break;
        case 5: // 9 Mb
            *rowIndex = 0;
            *bitmask = 0x00000200;
             break;
        case 6: // 12 Mb
            *rowIndex = 0;
            *bitmask = 0x00000400;
             break;
        case 7: // 18 Mb
            *rowIndex = 0;
            *bitmask = 0x00000800;
             break;
        case 8: // 24 Mb
            *rowIndex = 0;
            *bitmask = 0x00001000;
             break;
        case 9: // 36 Mb
            *rowIndex = 0;
            *bitmask = 0x00002000;
             break;
        case 10: // 48 Mb
            *rowIndex = 0;
            *bitmask = 0x00004000;
             break;
        case 11: // 54 Mb
            *rowIndex = 0;
            *bitmask = 0x00008000;
             break;

        case 12: // HT20 MCS0
            *rowIndex = 0;
            *bitmask = 0x00010000;
             break;
        case 13: // HT20 MCS1
            *rowIndex = 0;
            *bitmask = 0x00020000;
             break;
        case 14: // HT20 MCS2
            *rowIndex = 0;
            *bitmask = 0x00040000;
             break;
        case 15: // HT20 MCS3
            *rowIndex = 0;
            *bitmask = 0x00080000;
             break;
        case 16: // HT20 MCS4
            *rowIndex = 0;
            *bitmask = 0x00100000;
             break;
        case 17: // HT20 MCS5
            *rowIndex = 0;
            *bitmask = 0x00200000;
             break;
        case 18: // HT20 MCS6
            *rowIndex = 0;
            *bitmask = 0x00400000;
             break;
        case 19: // HT20 MCS7
            *rowIndex = 0;
            *bitmask = 0x00800000;
             break;

        case 20: // HT20 MCS8
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000001; // set Bit 1
             break;
        case 21: // HT20 MCS9
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000002; // set Bit 2
             break;
        case 22: // HT20 MCS10
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000004; // set Bit
             break;
        case 23: // HT20 MCS11
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000008; // set Bit
             break;
        case 24: // HT20 MCS12
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000010; // set Bit
             break;
        case 25: // HT20 MCS13
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000020; // set Bit
             break;
        case 26: // HT20 MCS14
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000040; // set Bit
             break;
        case 27: // HT20 MCS15
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000080; // set Bit
             break;

        case 28: // HT20 MCS16
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00010000; // set Bit 1
             break;
        case 29: // HT20 MCS17
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00020000; // set Bit 2
             break;
        case 30: // HT20 MCS18
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00040000; // set Bit
             break;
        case 31: // HT20 MCS19
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00080000; // set Bit
             break;
        case 32: // HT20 MCS20
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00100000; // set Bit
             break;
        case 33: // HT20 MCS21
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00200000; // set Bit
             break;
        case 34: // HT20 MCS22
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00400000; // set Bit
             break;
        case 35: // HT20 MCS23
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00800000; // set Bit
             break;

        case 36: // HT40 MCS0
            *rowIndex = 0;
            *bitmask = 0x01000000;
             break;
        case 37: // HT40 MCS1
            *rowIndex = 0;
            *bitmask = 0x02000000;
             break;
        case 38: // HT40 MCS2
            *rowIndex = 0;
            *bitmask = 0x04000000;
             break;
        case 39: // HT40 MCS3
            *rowIndex = 0;
            *bitmask = 0x08000000;
             break;
        case 40: // HT40 MCS4
            *rowIndex = 0;
            *bitmask = 0x10000000;
             break;
        case 41: // HT40 MCS5
            *rowIndex = 0;
            *bitmask = 0x20000000;
             break;
        case 42: // HT40 MCS6
            *rowIndex = 0;
            *bitmask = 0x40000000;
             break;
        case 43: // HT40 MCS7 135
            *rowIndex = 0;
            *bitmask = 0x80000000; // set Bit 32
             break;

        case 44: // HT40 MCS8
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000100; // set Bit  
             break;
        case 45: // HT40 MCS9
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000200; // set Bit  
             break;
        case 46: // HT40 MCS10
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000400; // set Bit  
             break;
        case 47: // HT40 MCS11
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000800; // set Bit  
             break;
        case 48: // HT40 MCS12
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00001000; // set Bit  
             break;
        case 49: // HT40 MCS13
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00002000; // set Bit  
             break;
        case 50: // HT40 MCS14
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00004000; // set Bit  
             break;
        case 51: // HT40 MCS15
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00008000; // set Bit  
             break;

        case 52: // HT40 MCS16
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x01000000; // set Bit
             break;
        case 53: // HT40 MCS17
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x02000000; // set Bit
             break;
        case 54: // HT40 MCS18
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x04000000; // set Bit
             break;
        case 55: // HT40 MCS19
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x08000000; // set Bit
             break;
        case 56: // HT40 MCS20
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x10000000; // set Bit
             break;
        case 57: // HT40 MCS21
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x20000000; // set Bit
             break;
        case 58: // HT40 MCS22
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x40000000; // set Bit
             break;
        case 59: // HT40 MCS23
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x80000000; // set Bit
             break;

        case 60: // HTV20 MCS0 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00000001; // set Bit
             break;
        case 61: // HTV20 MCS1 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00000002; // set Bit
             break;
        case 62: // HTV20 MCS2 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00000004; // set Bit
             break;
        case 63: // HTV20 MCS3 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00000008; // set Bit
             break;
        case 64: // HTV20 MCS4 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00000010; // set Bit
             break;
        case 65: // HTV20 MCS5 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00000020; // set Bit
             break;
        case 66: // HTV20 MCS6 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00000040; // set Bit
             break;
        case 67: // HTV20 MCS7 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00000080; // set Bit
             break;
        case 68: // HTV20 MCS8 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00000100; // set Bit
             break;
        case 69: // HTV20 MCS9 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00000200; // set Bit
             break;

        case 70: // HTV20 MCS0 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000010; // set Bit
             break;
        case 71: // HTV20 MCS1 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000020; // set Bit
             break;
        case 72: // HTV20 MCS2 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000040; // set Bit
             break;
        case 73: // HTV20 MCS3 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000080; // set Bit
             break;
        case 74: // HTV20 MCS4 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000100; // set Bit
             break;
        case 75: // HTV20 MCS5 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000200; // set Bit
             break;
        case 76: // HTV20 MCS6 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000400; // set Bit
             break;
        case 77: // HTV20 MCS7 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000800; // set Bit
             break;
        case 78: // HTV20 MCS8 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00001000; // set Bit
             break;
        case 79: // HTV20 MCS9 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00002000; // set Bit
             break;

        case 80: // HTV20 MCS0 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00000100; // set Bit
             break;
        case 81: // HTV20 MCS1 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00000200; // set Bit
             break;
        case 82: // HTV20 MCS2 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00000400; // set Bit
             break;
        case 83: // HTV20 MCS3 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00000800; // set Bit
             break;
        case 84: // HTV20 MCS4 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00001000; // set Bit
             break;
        case 85: // HTV20 MCS5 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00002000; // set Bit
             break;
        case 86: // HTV20 MCS6 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00004000; // set Bit
             break;
        case 87: // HTV20 MCS7 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00008000; // set Bit
             break;
        case 88: // HTV20 MCS8 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00010000; // set Bit
             break;
        case 89: // HTV20 MCS9 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00020000; // set Bit
             break;

        case 90: // HTV40 MCS0 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00001000; // set Bit
             break;
        case 91: // HTV40 MCS1 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00002000; // set Bit
             break;
        case 92: // HTV40 MCS2 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00004000; // set Bit
             break;
        case 93: // HTV40 MCS3 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00008000; // set Bit
             break;
        case 94: // HTV40 MCS4 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00010000; // set Bit
             break;
        case 95: // HTV40 MCS5 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00020000; // set Bit
             break;
        case 96: // HTV40 MCS6 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00040000; // set Bit
             break;
        case 97: // HTV40 MCS7 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00080000; // set Bit
             break;
        case 98: // HTV40 MCS8 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00100000; // set Bit
             break;
        case 99: // HTV40 MCS9 S1
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x00200000; // set Bit
             break;

        case 100: // HTV40 MCS0 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00010000; // set Bit
             break;
        case 101: // HTV40 MCS1 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00020000; // set Bit
             break;
        case 102: // HTV40 MCS2 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00040000; // set Bit
             break;
        case 103: // HTV40 MCS3 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00080000; // set Bit
             break;
        case 104: // HTV40 MCS4 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00100000; // set Bit
             break;
        case 105: // HTV40 MCS5 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00200000; // set Bit
             break;
        case 106: // HTV40 MCS6 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00400000; // set Bit
             break;
        case 107: // HTV40 MCS7 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00800000; // set Bit
             break;
        case 108: // HTV40 MCS8 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x01000000; // set Bit
             break;
        case 109: // HTV40 MCS9 S2
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x02000000; // set Bit
             break;

        case 110: // HTV40 MCS0 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00100000; // set Bit
             break;
        case 111: // HTV40 MCS1 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00200000; // set Bit
             break;
        case 112: // HTV40 MCS2 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00400000; // set Bit
             break;
        case 113: // HTV40 MCS3 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00800000; // set Bit
             break;
        case 114: // HTV40 MCS4 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x01000000; // set Bit
             break;
        case 115: // HTV40 MCS5 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x02000000; // set Bit
             break;
        case 116: // HTV40 MCS6 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x04000000; // set Bit
             break;
        case 117: // HTV40 MCS7 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x08000000; // set Bit
             break;
        case 118: // HTV40 MCS8 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x10000000; // set Bit
             break;
        case 119: // HTV40 MCS9 S3
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x20000000; // set Bit
             break;

        case 120: // HTV80 MCS0 S0
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x01000000; // set Bit
             break;
        case 121: // HTV80 MCS1 S0
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x02000000; // set Bit
             break;
        case 122: // HTV80 MCS2 S0
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x04000000; // set Bit
             break;
        case 123: // HTV80 MCS3 S0
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x08000000; // set Bit
             break;
        case 124: // HTV80 MCS4 S0
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x10000000; // set Bit
             break;
        case 125: // HTV80 MCS5 S0
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x20000000; // set Bit
             break;
        case 126: // HTV80 MCS6 S0
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x40000000; // set Bit
             break;
        case 127: // HTV80 MCS7 S0
            *rowIndex = 0;         // row Index 0
            *bitmask = 0x80000000; // set Bit
             break;
        case 128: // HTV80 MCS8 S0
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000001; // set Bit
             break;
        case 129: // HTV80 MCS9 S0
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x00000002; // set Bit
             break;

        case 130: // HTV80 MCS0 S1
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x10000000; // set Bit
             break;
        case 131: // HTV80 MCS1 S1
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x20000000; // set Bit
             break;
        case 132: // HTV80 MCS2 S1
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x40000000; // set Bit
             break;
        case 133: // HTV80 MCS3 S1
            *rowIndex = 1;         // row Index 1
            *bitmask = 0x80000000; // set Bit
             break;
        case 134: // HTV80 MCS4 S1
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00000001; // set Bit
             break;
        case 135: // HTV80 MCS5 S1
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00000002; // set Bit
             break;
        case 136: // HTV80 MCS6 S1
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00000004; // set Bit
             break;
        case 137: // HTV80 MCS7 S1
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00000008; // set Bit
             break;
        case 138: // HTV80 MCS8 S1
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00000010; // set Bit
             break;
        case 139: // HTV80 MCS9 S1
            *rowIndex = 2;         // row Index 2
            *bitmask = 0x00000020; // set Bit
             break;

        case 140: // HTV80 MCS0 S3
            *rowIndex = 3;         // row Index 3
            *bitmask = 0x00000001; // set Bit
             break;
        case 141: // HTV80 MCS1 S3
            *rowIndex = 3;         // row Index 3
            *bitmask = 0x00000002; // set Bit
             break;
        case 142: // HTV80 MCS2 S3
            *rowIndex = 3;         // row Index 3
            *bitmask = 0x00000004; // set Bit
             break;
        case 143: // HTV80 MCS3 S3
            *rowIndex = 3;         // row Index 3
            *bitmask = 0x00000008; // set Bit
             break;
        case 144: // HTV80 MCS4 S3
            *rowIndex = 3;         // row Index 3
            *bitmask = 0x00000010; // set Bit
             break;
        case 145: // HTV80 MCS5 S3
            *rowIndex = 3;         // row Index 3
            *bitmask = 0x00000020; // set Bit
             break;
        case 146: // HTV80 MCS6 S3
            *rowIndex = 3;         // row Index 3
            *bitmask = 0x00000040; // set Bit
             break;
        case 147: // HTV80 MCS7 S3
            *rowIndex = 3;         // row Index 3
            *bitmask = 0x00000080; // set Bit
             break;
        case 148: // HTV80 MCS8 S3
            *rowIndex = 3;         // row Index 3
            *bitmask = 0x00000100; // set Bit
             break;
        case 149: // HTV80 MCS9 S3
            *rowIndex = 3;         // row Index 3
            *bitmask = 0x00000200; // set Bit
             break;
    }
}

void cmdReplyFunc(void *buf)
{
    A_UINT8 *reply = (A_UINT8*)buf;
    A_UINT32 length =0;
    A_UINT8 responseOpCode = _OP_GENERIC_RSP;
    A_BOOL ret = FALSE;

    length = *(A_UINT32 *)&(reply[0]);

    //printf("TLV length got %d\n",length);

    ret = initResponse((A_UINT8*)&reply[4], length,&responseOpCode);

    if ( ret == FALSE )
    {
        printf("Error in init Response\n");
        return;
    }

    //printf("Response code got %d\n",responseOpCode);

    if ( responseOpCode == _OP_SUBMIT_REPORT_RSP )
    {
        parseTLVSubmitReport();
    }
    else if ( responseOpCode == _OP_GENERIC_RSP )
    {
        parseResponse();
    }

    return;
}
    
int main (int argc, char **argv)
{
    int c, error=0;
    char ifname[IFNAMSIZ];
    progname = argv[0];
    char buf[2048 + 8];
    A_UINT8 *rCmdStream = NULL;
    A_UINT32 cmdStreamLen=0,opCode=_OP_TX;;
    A_UINT32 value=0,freq=0,dataRate = 0,miscFlags=0;
    A_UINT16 regDmn[2];
    A_BOOL tlvConstruct = FALSE,ret=FALSE;
    A_BOOL is11ACRate = FALSE;
    A_BOOL respNeeded = TRUE;
    A_BOOL rxSetMac = FALSE;

    memset(buf, 0, sizeof(buf));

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
            {"tgtpwr", 1, NULL, 'H'},
            {"pcdac", 1, NULL, 'I'},
            {"forcedGain", 1, NULL, TCMD_TX_FORCED_GAIN},
            {"gainIdx", 1, NULL, TCMD_TX_FORCED_GAINIDX},
            {"dacGain", 1, NULL, TCMD_TX_DAC_GAIN},
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
            {"paprd", 0, NULL, 'A'},
            {"stbc", 0, NULL, 'Y'},
            {"ldpc", 0, NULL, 'Z'},
            {"scrambleroff", 0, NULL, 'o'},
            {"aifsn", 1, NULL, 'u'},
            {"dutycyc", 1, NULL, 'U'},
            {"SetAntSwitchTable", 1, NULL, 'S'},
            {"shortguard", 0, NULL, 'G'},
            {"numpackets", 1, NULL, 'n'},
            {"agg", 1, NULL, 'N'},
            {"mode", 1, NULL, 'M'},
            {"bw", 1, NULL, 'm'},
            {"setlongpreamble", 1, NULL, 'l'},
            {"setreg", 1, NULL, 'R'},
            {"regval", 1, NULL, 'V'},
            {"writeotp", 0, NULL, 'w'},
            {"otpregdmn", 1, NULL, 'E'},
            {"btaddr", 1, NULL, 'B'},
            {"therm", 0, NULL, TCMD_READ_THERMAL},
            {"tpcm", 1, NULL, 'P'},
            {"lpl", 1, NULL, TCMD_SET_RX_LPL},
            {"cal", 1, NULL, TCMD_CAL},
            {0, 0, 0, 0}
        };


        c = getopt_long(argc, argv, "vi:t:f:g:h:HI:j:z:e:c:C:b:d:D:r:p:q:k:K:x:s:X:aAYZouU:S:Gn:N:M:m:l:P:",
                         long_options, &option_index);

        if (c == -1)
            break;

        switch (c) {
        case 'i':
            memset(ifname, '\0', 8);
            strcpy(ifname, optarg);
            break;
        case 't':
            tlvConstruct = TRUE;
            createCommand(_OP_TX);
            opCode = _OP_TX;
            if (!strcmp(optarg, "sine")) {
                value = TCMD_CONT_TX_SINE;
            } else if (!strcmp(optarg, "frame")) {
                value = TCMD_CONT_TX_FRAME;
            } else if (!strcmp(optarg, "tx99")) {
                value = TCMD_CONT_TX_TX99;
            } else if (!strcmp(optarg, "tx100")) {
                value = TCMD_CONT_TX_TX100;
            } else if (!strcmp(optarg, "off")) {
                value = TCMD_CONT_TX_OFF;
            }else {
                printf("Error \n");
		usage();
                return 0;
            }

            addParameterToCommand((A_UINT8 *)"txMode",(A_UINT8 *)&value);
            break;
        case 'f':
            freq = value = freqValid(atoi(optarg));
            addParameterToCommand((A_UINT8 *)"channel",(A_UINT8 *)&value);
            break;
        case 'G':
            value = 1;
            addParameterToCommand((A_UINT8 *)"shortGuard",(A_UINT8 *)&value);
            break;
        case 'P':
            {
                if (!strcmp(optarg, "forcedGain")) {
                    value = TPC_FORCED_GAIN;
                } else if (!strcmp(optarg, "txpwr")) {
                    value = TPC_TX_PWR;
                } else if (!strcmp(optarg, "tgtpwr")) {
                    value = TPC_TGT_PWR;
                } else if (!strcmp(optarg, "forcedGainIdx")) {
                    value = TPC_FORCED_GAINIDX;
                } else if (!strcmp(optarg, "forcedTgtPwr")) {
                    value = TPC_FORCED_TGTPWR;
                } 
                else {
                    value = TPC_TX_PWR;
                }

                addParameterToCommand((A_UINT8 *)"tpcm",(A_UINT8 *)&value);
            }
            break;
        case 'M':
              if (!strcmp(optarg, "ht20")) {
                  value  = TCMD_WLAN_MODE_HT20;
              } else if (!strcmp(optarg, "ht40plus")) {
                  value  = TCMD_WLAN_MODE_HT40PLUS;
              } else if (!strcmp(optarg, "ht40minus")) {
                  value  = TCMD_WLAN_MODE_HT40MINUS;
              } else if (!strcmp(optarg, "vht20")) {
                  value  = TCMD_WLAN_MODE_VHT20;
              } else if (!strcmp(optarg, "vht40plus")) {
                  value  = TCMD_WLAN_MODE_VHT40PLUS;
              } else if (!strcmp(optarg, "vht40minus")) {
                  value  = TCMD_WLAN_MODE_VHT40MINUS;
              } else if (!strcmp(optarg, "vht80_0")) {
                  value  = TCMD_WLAN_MODE_VHT80_0;
              } else if (!strcmp(optarg, "vht80_1")) {
                  value  = TCMD_WLAN_MODE_VHT80_1;
              } else if (!strcmp(optarg, "vht80_2")) {
                  value  = TCMD_WLAN_MODE_VHT80_2;
              } else if (!strcmp(optarg, "vht80_3")) {
                  value  = TCMD_WLAN_MODE_VHT80_3;
              }
              else {
                  printf("Error\n");
                  usage();
                  return 0;
              }

            addParameterToCommand((A_UINT8 *)"wlanMode",(A_UINT8 *)&value);
            break;
        case 'm':
            if (!strcmp(optarg, "half")) {
                value = HALF_SPEED_MODE;
            } else if (!strcmp(optarg, "quarter")) {
                value = QUARTER_SPEED_MODE;
            }
            else {
                printf("Error\n");
                usage();
                return 0;
            }

            addParameterToCommand((A_UINT8 *)"bandwidth",(A_UINT8 *)&value);
            break;
        case TCMD_TX_FORCED_GAINIDX:
            value = atoi(optarg);
            ret = addParameterToCommand((A_UINT8 *)"gainIdx",(A_UINT8 *)&value);
            printf("r1 %d value %d\n", ret,value);
            break;
        case TCMD_TX_DAC_GAIN:
            value = atoi(optarg);
            ret = addParameterToCommand((A_UINT8 *)"dacGain",(A_UINT8 *)&value);
            printf("r2 %d value %d\n", ret,value);
            break;
        case 'n':
            value = atoi(optarg);
            addParameterToCommand((A_UINT8 *)"numPackets",(A_UINT8 *)&value);
            break;
        case 'N':
            value = atoi(optarg);
            addParameterToCommand((A_UINT8 *)"agg",(A_UINT8 *)&value);
            break;
        case 'g':
        {
            A_UINT32 rowIndex=0,rateBitMask=0;
            A_UINT8 rateMask[25];
            /* let user input index of rateTable instead of string parse */
            //dataRate = value = rateValid(atoi(optarg), freq);
            dataRate = value = atoi(optarg);

            if ( value > 154 ) {
                printf("Invalid Index\n");
                return 0;
            }

            if ( value == 153 ) // Sweep all rates
            {
                memset(rateMask,0,sizeof(rateMask));
                sprintf((char*)rateMask,"%s%d","rateMask",0);
                rateBitMask = 0xFFFFFF00;
                addParameterToCommand((A_UINT8 *)rateMask,(A_UINT8 *)&rateBitMask);

                memset(rateMask,0,sizeof(rateMask));
                sprintf((char*)rateMask,"%s%d","rateMask",1);
                rateBitMask = 0xFFFFFFFF;
                addParameterToCommand((A_UINT8 *)rateMask,(A_UINT8 *)&rateBitMask);

                memset(rateMask,0,sizeof(rateMask));
                sprintf((char*)rateMask,"%s%d","rateMask11AC",0);
                rateBitMask = 0xFF3FF1FF;
                addParameterToCommand((A_UINT8 *)rateMask,(A_UINT8 *)&rateBitMask);

                memset(rateMask,0,sizeof(rateMask));
                sprintf((char*)rateMask,"%s%d","rateMask11AC",1);
                rateBitMask = 0xF3FF1FF3;
                addParameterToCommand((A_UINT8 *)rateMask,(A_UINT8 *)&rateBitMask);

                memset(rateMask,0,sizeof(rateMask));
                sprintf((char*)rateMask,"%s%d","rateMask11AC",2);
                rateBitMask = 0x3FF3FF3F;
                addParameterToCommand((A_UINT8 *)rateMask,(A_UINT8 *)&rateBitMask);

                memset(rateMask,0,sizeof(rateMask));
                sprintf((char*)rateMask,"%s%d","rateMask11AC",3);
                rateBitMask = 0x3BF;
                addParameterToCommand((A_UINT8 *)rateMask,(A_UINT8 *)&rateBitMask);
            }
            else {
            // Map ratemask to the bitmask value..
            rateIndexToArrayMapping (value, &rowIndex, &rateBitMask, &is11ACRate);

            printf("rowIndex %d bitMask %d\n",rowIndex,rateBitMask);

            memset(rateMask,0,sizeof(rateMask));

            if (is11ACRate == FALSE ) {
                sprintf((char*)rateMask,"%s%d","rateMask",rowIndex);
                addParameterToCommand((A_UINT8 *)rateMask,(A_UINT8 *)&rateBitMask);

                if ( rowIndex != 0 ) {
                    //NOTE: This is required as on the firmware default rateMask0 is set to rate 11
                    memset(rateMask,0,sizeof(rateMask));
                    sprintf((char*)rateMask,"%s%d","rateMask",0);
                    value = 0;
                    addParameterToCommand((A_UINT8 *)rateMask,(A_UINT8 *)&value);
                }
            }
            else {
                sprintf((char*)rateMask,"%s%d","rateMask11AC",rowIndex);
                addParameterToCommand((A_UINT8 *)rateMask,(A_UINT8 *)&rateBitMask);

                //NOTE: This is required as on the firmware default rateMask0 is set to rate 11
                memset(rateMask,0,sizeof(rateMask));
                sprintf((char*)rateMask,"%s%d","rateMask",0);
                value = 0;
                addParameterToCommand((A_UINT8 *)rateMask,(A_UINT8 *)&value);
            }
          }
        }
            break;
        case 'h':
        {
            //value = TPC_TX_PWR;
            goto _txpwrProcessing;
        }
        case 'H':
        {
            //value = TPC_TGT_PWR;
            goto _txpwrProcessing;
        }

        _txpwrProcessing:
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
                value = txPowerIndBm * 2;

                //Let's set all the pwrGainStart,pwrGainEnd to same txPower values
                //Currently we only get one power value
                setPowerPerRateIndex(is11ACRate,value);
            } else {
                printf("Bad argument to --txpwr, must be in steps of 0.5 dBm");
                usage();
                return 0;
            }
            
            //addParameterToCommand((A_UINT8 *)"tpcm",(A_UINT8 *)&value);
        }
        break;
        case 'I':
        {
            value = TPC_FORCED_GAIN;
            addParameterToCommand((A_UINT8 *)"tpcm",(A_UINT8 *)&value);

            value = atof(optarg); //txPwr

            //Let's set all the pwrGainStart,pwrGainEnd to same txPower values
            //Currently we only get one power value
            setPowerPerRateIndex(is11ACRate,value);
        }
            break;
        case TCMD_TX_FORCED_GAIN:
        {
            value = TPC_TX_FORCED_GAIN;
            addParameterToCommand((A_UINT8 *)"tpcm",(A_UINT8 *)&value);

            value = atof(optarg); //txPwr
            //Let's set all the pwrGainStart,pwrGainEnd to same txPower values
            //Currently we only get one power value
            setPowerPerRateIndex(is11ACRate,value);
        }
            break;
        case 'j':
            value = antValid(atoi(optarg));
            addParameterToCommand((A_UINT8 *)"antenna",(A_UINT8 *)&value);
            break;       
        case 'z':
            value = pktSzValid(atoi(optarg));
            addParameterToCommand((A_UINT8 *)"pktSz",(A_UINT8 *)&value);
            break;
        case 'e':
            value = atoi(optarg);
            addParameterToCommand((A_UINT8 *)"txPattern",(A_UINT8 *)&value);
            break;
        case 'c':
            value = atoi(optarg);
            addParameterToCommand((A_UINT8 *)"txChain0",(A_UINT8 *)&value);
            break;
        case 'C':
            value = atoi(optarg);
            addParameterToCommand((A_UINT8 *)"rxChain",(A_UINT8 *)&value);
            break;
        case 'b':
            {
                A_UINT8 mac[ATH_MAC_LEN];

                if (ath_ether_aton(optarg, mac) != A_OK) {
                    A_ERR(-1, "Invalid bssid address format! \n");
                }
                addParameterToCommand((A_UINT8 *)"bssid",(A_UINT8 *)mac);
                printf("JLU: tcmd: set bssid 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
                        mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
                break;
            }
        case 'd':
            {
                A_UINT8 mac[ATH_MAC_LEN];

                if (ath_ether_aton(optarg, mac) != A_OK) {
                    A_ERR(-1, "Invalid srcmac address format! \n");
                }
                addParameterToCommand((A_UINT8 *)"txStation",(A_UINT8 *)mac);
                printf("JLU: tcmd: set srcmac 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
                        mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
                break;
            }
        case 'D':
            {
                A_UINT8 mac[ATH_MAC_LEN];

                if (ath_ether_aton(optarg, mac) != A_OK) {
                    A_ERR(-1, "Invalid dstmac address format! \n");
                }
                addParameterToCommand((A_UINT8 *)"rxStation",(A_UINT8 *)mac);
                printf("JLU: tcmd: set dstmac 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
                        mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

                /* if destination MAC address is present then set broadcast to off */
                value = 0;
                addParameterToCommand((A_UINT8 *)"broadcast",(A_UINT8 *)&value);
                break;
            }
        case 'r':
            tlvConstruct = TRUE;
            createCommand(_OP_RX);
            opCode = _OP_RX;

            if (!strcmp(optarg, "promis")) {
                value = TCMD_CONT_RX_PROMIS;
                printf(" Its cont Rx promis mode \n");
            } else if (!strcmp(optarg, "filter")) {
                value = TCMD_CONT_RX_FILTER;
                printf(" Its cont Rx  filter  mode \n");
            } else if (!strcmp(optarg, "report")) {
                printf(" Its cont Rx report  mode \n");
                value = TCMD_CONT_RX_REPORT;
            } else {
                printf("Error\n");
                usage();
                return 0;
            }
            addParameterToCommand((A_UINT8 *)"rxMode",(A_UINT8 *)&value);
            break;
        case 'p':
            value = freqValid(atoi(optarg));
            addParameterToCommand((A_UINT8 *)"channel",(A_UINT8 *)&value);
            break;
        case 'q':
            value = antValid(atoi(optarg));
            addParameterToCommand((A_UINT8 *)"antenna",(A_UINT8 *)&value);
            break;
        case 'k':
            value = atoi(optarg);
            addParameterToCommand((A_UINT8 *)"ack",(A_UINT8 *)&value);
            break;
        case 'K':
            value = atoi(optarg);
            if ( opCode == _OP_TX )
                addParameterToCommand((A_UINT8 *)"broadcast",(A_UINT8 *)&value);
            else
                addParameterToCommand((A_UINT8 *)"bc",(A_UINT8 *)&value);
            break;
        case TCMD_SET_RX_LPL:
            value = atoi(optarg);
            addParameterToCommand((A_UINT8 *)"lpl",(A_UINT8 *)&value);
            break;
        case 'l':
            printf("NOT supported\n");
            break;
        case 'x':
            printf("In pm..\n");
            tlvConstruct = TRUE;
            ret = createCommand(_OP_PM);
            opCode = _OP_PM;

            if (ret == FALSE)
               printf("Error in creating command _OP_PM\n");

            if (!strcmp(optarg, "wakeup")) {
                value = TCMD_PM_WAKEUP;
            } else if (!strcmp(optarg, "sleep")) {
                value = TCMD_PM_SLEEP;
            } else if (!strcmp(optarg, "deepsleep")) {
                value = TCMD_PM_DEEPSLEEP;
            } else {
                printf("Error\n");
                usage();
                return 0;
            }

            ret = addParameterToCommand((A_UINT8 *)"mode",(A_UINT8 *)&value);
            if (ret == FALSE)
               printf("Error in adding param mode to command _OP_PM\n");

            break;
        case 'R':
            printf("NOT supported\n");
            break;
        case 'V':
            printf("NOT supported\n");
            break;
        case 's':
            {
                A_UINT8 mac[ATH_MAC_LEN];

                if ( tlvConstruct == FALSE )
                {
                    createCommand(_OP_RX);
                    opCode = _OP_RX;
                    tlvConstruct = TRUE;
                }
              
                if ( rxSetMac == FALSE ) {
                    value = TCMD_CONT_RX_SETMAC;
                    addParameterToCommand((A_UINT8 *)"rxMode",(A_UINT8 *)&value);
                    rxSetMac = TRUE;
                }

                if (ath_ether_aton(optarg, mac) != A_OK) {
                    A_ERR(-1, "Invalid mac address format! \n");
                }

                addParameterToCommand((A_UINT8 *)"addr",(A_UINT8 *)mac);

                printf("JLU: tcmd: setmac 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n", 
                        mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
                break;
            }
        case 'X':
            {
                A_UINT8 mac[ATH_MAC_LEN];

                if ( tlvConstruct == FALSE )
                {
                    createCommand(_OP_RX);
                    opCode = _OP_RX;
                    tlvConstruct = TRUE;
                }

                if ( rxSetMac == FALSE ) {
                    value = TCMD_CONT_RX_SETMAC;
                    addParameterToCommand((A_UINT8 *)"rxMode",(A_UINT8 *)&value);
                    rxSetMac = TRUE;
                }

                if (ath_ether_aton(optarg, mac) != A_OK) {
                    A_ERR(-1, "Invalid mac address format! \n");
                }

                addParameterToCommand((A_UINT8 *)"bssid",(A_UINT8 *)mac);

                printf("JLU: tcmd: setbssid 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
                        mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
                break;
            }

        case 'u':
            {
                value = atoi(optarg) & 0xff;
                addParameterToCommand((A_UINT8 *)"aifsn",(A_UINT8 *)&value);
                printf("AIFS:%d\n", value);
            }
            break;
        case 'U':
            {           
                int dutyCycle, frameLength;
                float txFrameDurPercent;

                frameLength = (A_UINT32) (((TX_FRAME_DURATION + 20) *2 * ActualDataRate[dataRate]) / 8.0);
                txFrameDurPercent = 1.0;
                if (frameLength > MAX_FRAME_LENGTH) {
                    txFrameDurPercent = ((float) MAX_FRAME_LENGTH) / (float) frameLength;
                    frameLength = MAX_FRAME_LENGTH;
                }
                
                dutyCycle = atoi(optarg) & 0xff;
                if (dutyCycle == 0) {
                    dutyCycle = 1;              
                } 
                if(dutyCycle > 99) {
                    dutyCycle = 99;                  
                }
                
                value = computeNumSlots(dutyCycle,dataRate,txFrameDurPercent);
                addParameterToCommand((A_UINT8 *)"aifsn",(A_UINT8 *)&value);
                addParameterToCommand((A_UINT8 *)"pktSz",(A_UINT8 *)&frameLength);
            }
            break;
        case 'a':
            value = TRUE;
            addParameterToCommand((A_UINT8 *)"enANI",(A_UINT8 *)&value);
            break;
        case 'A':
            miscFlags |= PAPRD_ENA_MASK;
            addParameterToCommand((A_UINT8 *)"flags",(A_UINT8 *)&miscFlags);
            break;
        case 'Y':
            miscFlags |= DESC_STBC_ENA_MASK;
            addParameterToCommand((A_UINT8 *)"flags",(A_UINT8 *)&miscFlags);
            break;
        case 'Z':
            miscFlags |= DESC_LDPC_ENA_MASK;
            addParameterToCommand((A_UINT8 *)"flags",(A_UINT8 *)&miscFlags);
            break;
        case 'o':
            value = TRUE;
            addParameterToCommand((A_UINT8 *)"scramblerOff",(A_UINT8 *)&value);
            break;
        case 'S':
            if (argc < 4)
            {
                usage();
                return 0;
            }

            if ( tlvConstruct == FALSE )
            {
                createCommand(_OP_RX);
                opCode = _OP_RX;
                tlvConstruct = TRUE;
            }

            value = TCMD_CONT_RX_SET_ANT_SWITCH_TABLE;
            addParameterToCommand((A_UINT8 *)"rxMode",(A_UINT8 *)&value);

            value = (unsigned int) atoi(argv[2]);
            addParameterToCommand((A_UINT8 *)"antswitch1",(A_UINT8 *)&value);
            value = (unsigned int) atoi(argv[3]);
            addParameterToCommand((A_UINT8 *)"antswitch2",(A_UINT8 *)&value);
            break;
        case 'w':
            value = 1;
            addParameterToCommand((A_UINT8 *)"otpWriteFlag",(A_UINT8 *)&value);
            break;
        case 'E':
            {
                regDmn[0] = 0xffff&(strtoul(optarg, (char **)NULL, 0));
                regDmn[1] = 0xffff&(strtoul(optarg, (char **)NULL, 0)>>16);

                addParameterToCommand((A_UINT8 *)"regDmn0",(A_UINT8 *)&regDmn[0]);
                addParameterToCommand((A_UINT8 *)"regDmn1",(A_UINT8 *)&regDmn[0]);
            }
            break;
        case 'B':
            {
                A_UINT8 btaddr[ATH_MAC_LEN];
                if (ath_ether_aton(optarg, btaddr) != A_OK) {
                    A_ERR(-1, "Invalid mac address format! \n");
                }

                addParameterToCommand((A_UINT8 *)"btaddr",(A_UINT8 *)btaddr);

                printf("JLU: tcmd: setbtaddr 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
                        btaddr[0], btaddr[1], btaddr[2], btaddr[3], btaddr[4], btaddr[5]);
            }
            break;
        case TCMD_READ_THERMAL:
            {
               printf("TODO... readThermal need to support in TLV ..\n");
            }
            break;
        case TCMD_CAL:
            printf("CAL\n");
            tlvConstruct = TRUE;
            createCommand(_OP_CAL);
            opCode = _OP_CAL;
            if (!strcmp(optarg, "sweep")) {
                value = TCMD_CAL_SWEEP;
            } else if (!strcmp(optarg, "verify")) {
                value = TCMD_CAL_VERIFY;
            } else if (!strcmp(optarg, "forcedGainIdx")) {
                value = TCMD_CAL_BY_FORCED_GAIN_IDX;
            } else if (!strcmp(optarg, "forcedTgtPwr")) {
                value = TCMD_CAL_BY_TGT_PWR;
            }else {
                printf("Error \n");
		usage();
                return 0;
            }
            respNeeded = FALSE;
            addParameterToCommand((A_UINT8 *)"_calParm_code_addrMode0",(A_UINT8 *)&value); // "borrow" the first field

            break;
        case '?':
            break;
        default:
            usage();
        }
    }

    commandComplete(&rCmdStream, &cmdStreamLen);

    error = cmd_init(ifname,cmdReplyFunc);

    memcpy(&buf[8],rCmdStream,cmdStreamLen);

    cmd_send(buf,cmdStreamLen,((respNeeded) ? 1 : 0));

    exit (0);
}

void setPowerPerRateIndex(A_BOOL is11ACRate,A_UINT32 value) 
{
    A_UINT8 pwrGainBuf[25];
    A_UINT32 i=0,powerGain=0,endPwrGain = 16; //PWRGAIN_ROW_MAX

    if (is11ACRate == TRUE )
        endPwrGain = 27; //PWRGAIN_11AC_ROW_MAX

    for(i=0;i<endPwrGain;i++)
    {
        memset(pwrGainBuf,0,sizeof(pwrGainBuf));
        if (is11ACRate == TRUE ) {
            sprintf((char*)pwrGainBuf,"%s%d","pwrGnACStart",i);
        }
        else
            sprintf((char*)pwrGainBuf,"%s%d","pwrGainStart",i);

        getPowerGain(&powerGain,value);
        addParameterToCommand((A_UINT8 *)pwrGainBuf,(A_UINT8 *)&powerGain);

        if (is11ACRate == FALSE ) {
            memset(pwrGainBuf,0,sizeof(pwrGainBuf));
            sprintf((char*)pwrGainBuf,"%s%d","pwrGainEnd",i);
            getPowerGain(&powerGain,value);
            addParameterToCommand((A_UINT8 *)pwrGainBuf,(A_UINT8 *)&powerGain);
       }
   }

   if ( is11ACRate == TRUE ){
      memset(pwrGainBuf,0,sizeof(pwrGainBuf));
      sprintf((char*)pwrGainBuf,"%s","pwrGnACEnd");
      addParameterToCommand((A_UINT8 *)pwrGainBuf,(A_UINT8 *)&value);
   }
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

static A_UINT32 pktSzValid(A_UINT32 val)
{
    if (( val < 32 )||(val > 4000)){
        A_ERR(-1, "Invalid package size! < 32 - 4000 >\n");
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

static A_INT32 
computeNumSlots(A_UINT32 dutyCycle, A_UINT32 dataRateIndex, float txFrameDurationPercent)
{
    A_UINT32 frameLength = TX_FRAME_DURATION, slotTime; 
    A_INT32  numSlots;
    frameLength = (A_UINT32) ((float)TX_FRAME_DURATION * txFrameDurationPercent);
    if ((dataRateIndex >= 0 && dataRateIndex <= 3) ||
       (dataRateIndex >= 44 && dataRateIndex <= 45)) { 
        if (dataRateIndex >= 44 && dataRateIndex <= 45) {
            frameLength += PREAMBLE_TIME_CCK_SHORT; 
        }
        else {
            frameLength += PREAMBLE_TIME_CCK_LONG; 
        }
        slotTime = SLOT_TIME;
    }
    else {
        frameLength += PREAMBLE_TIME_OFDM; 
        slotTime = SLOT_TIME;
    }
    numSlots = ((A_INT32)(((float)frameLength * (100 - dutyCycle)) / ((float)dutyCycle * slotTime)));
    if (numSlots > MAX_NUM_SLOTS) numSlots = MAX_NUM_SLOTS;
    return(numSlots);
}

