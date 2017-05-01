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
 * $Id: //depot/sw/qca_main/components/wlan/qca-wifi-fw/1.2/drivers/host/tools/tcmd/athtestcmd.h#1 $
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
};

#ifdef __cplusplus
}
#endif

#endif /* _TCMD_H_ */
