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
 * This file contains the definitions for wmiconfig utility
 *
 * $Id: //depot/sw/qca_main/components/wlan/qca-wifi-fw/1.2/drivers/host/tools/systemtools/testcmd_tlv/athtestcmd.h#1 $
 */

#ifndef _TCMD_H_
#define _TCMD_H_

#ifdef __cplusplus
extern "C" {
#endif

enum {
    TESTMODE_CONT_TX = 801,     /* something that doesn't collide with ascii */
    TESTMODE_CONT_RX,
    TESTMODE_PM,
    TESTMODE_SETLPREAMBLE,
    TESTMODE_SETREG,
    TESTMODE_CMDS,
};

enum {
    TCMD_SET_RX_LPL=501,     /* something that doesn't collide with ascii */
    TCMD_EFUSE_START=502,
    TCMD_EFUSE_END=503,
    TCMD_EFUSE_DATA=504,
    TCMD_EFUSE_DUMP=505,
    TCMD_EFUSE_WRITE=506,
    TCMD_OTP_DUMP=507,
    TCMD_OTP_WRITE=508,
    TCMD_READ_THERMAL=509,
    TCMD_SET_BT_MODE=510,
    TCMD_TX_FORCED_GAIN=511,
    TCMD_TX_FORCED_GAINIDX=512,
    TCMD_TX_DAC_GAIN=513,
    TCMD_CAL=514,
};

#ifdef __cplusplus
}
#endif

#endif /* _TCMD_H_ */

