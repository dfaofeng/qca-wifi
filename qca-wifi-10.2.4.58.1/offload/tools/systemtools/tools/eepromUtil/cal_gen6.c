#ifdef _WINDOWS
#include <windows.h>
#endif 
#include <stdio.h>
#include <time.h>
#if !defined(LINUX) && !defined(__linux__)
#include <conio.h>
#endif
#include <assert.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include "wlantype.h"   /* typedefs for A_UINT16 etc.. */
#include "wlanproto.h"
#include "athreg.h"
#include "manlib.h"     /* The Manufacturing Library */
#include "MLIBif.h"     /* Manufacturing Library low level driver support functions */
#ifdef JUNGO
#include "mld.h"        /* Low level driver information */
#endif
#include "common_hw.h"
#include "manlibInst.h" /* The Manufacturing Library Instrument Library extension */
#include "mEeprom.h"    /* Definitions for the data structure */
#include "dynamic_optimizations.h"
#include "rssi_power.h"
#include "test.h"
#include "parse.h"
#include "dk_cmds.h"
#include "dk_ver.h"

#if defined(LINUX) || defined(__linux__)
#include "linux_ansi.h"
#include "unistd.h"
#endif    

#include "art_if.h"

#include "ar2413/mEEPROM_g.h"
#include "ar5212/mEEPROM_d.h"
#include "cal_gen5.h"
#include "mEepStruct6003.h"
#include "otp_routines.h"
#include "eepromUtil.h"
#include "pcCALPush.h"

A_BOOL fillIDs(A_UINT32 devNum, AR6003_OTP_ID *otpId, AR6K_EEPROM *eepStruct);
A_BOOL custDataIDs(A_UINT32 devNum, AR6003_OTP_ID *otpId, AR6K_EEPROM *eepStruct);
A_BOOL fillCALOTP(A_UINT32 devNum, A_UINT8 *otpCalBuf, A_UINT32 *calLength, AR6K_EEPROM *eepStruct);
A_BOOL fillCfg(A_UINT32 devNum, A_UINT8 *buf, A_UINT32 *length);

extern RAW_CAL_DATA_OLPC RawCalData[CAL_MAX_MODE];

// TBD???
A_BOOL fillIDs(A_UINT32 devNum, AR6003_OTP_ID *otpId, AR6K_EEPROM *eepStruct)
{
    //otpId->version = (AR6003_OTP_MAJOR_VER << AR6003_OTP_MAJOR_VER_SHIFT) | AR6003_OTP_MINOR_VER;
    if (TPC_VER2 == tpcVersion) {
        otpId->version = AR6003_OTP_VER2;
    }
    else if (TPC_VER1 == tpcVersion) {
        otpId->version = AR6003_OTP_VER;
    }

    memcpy((void*)otpId->macAddr, (void*)eepStruct->baseEepHeader.macAddr, sizeof(otpId->macAddr));
    printf("..otp mac 0x%02x %02x %02x %02x %02x %02x\n", otpId->macAddr[0], otpId->macAddr[1],
	otpId->macAddr[2], otpId->macAddr[3], otpId->macAddr[4], otpId->macAddr[5]);

    memcpy((void*)otpId->bdAddr, (void*)eepStruct->baseEepHeader.bdAddr, sizeof(otpId->bdAddr));
    printf("..otp bt 0x%02x %02x %02x %02x %02x %02x\n", otpId->bdAddr[0], otpId->bdAddr[1],
	otpId->bdAddr[2], otpId->bdAddr[3], otpId->bdAddr[4], otpId->bdAddr[5]);

    otpId->regDmn[0] = eepStruct->baseEepHeader.regDmn[0]; 
    otpId->regDmn[1] = eepStruct->baseEepHeader.regDmn[1];
 
    return(TRUE);
}

A_BOOL fillCALOTP(A_UINT32 devNum, A_UINT8 *otpCalBuf, A_UINT32 *calLength, AR6K_EEPROM *eepStruct)
{
    A_UINT32 ii, jj, startIdx=1, length; // header
    A_UINT32 numPiers;
    AR6003_CAL_DATA_PER_FREQ_OLPC calPierData;
    A_BOOL rc=FALSE;
    *calLength = length = 0;

    if(_OTA_MODE_11A == _OTA_MODE_11A) {
        numPiers = RawCalData[MODE_11A].numChannels;

        //fill 11a frequency piers and cal data
        if (numPiers > AR6003_NUM_5G_CAL_PIERS) {
            numPiers = AR6003_NUM_5G_CAL_PIERS;
        }

        //should probably check against chain mask, TODO
	for (ii=0; ii<numPiers; ii++) {

	    //fill the 11a calibration values for the chan
            calPierData.olpcGainDelta = RawCalData[MODE_11A].pPerChanDataPALOff[ii].olpc_gain_delta;
            calPierData.thermCalVal   = RawCalData[MODE_11A].pPerChanDataPALOff[ii].therm_cal_value;
            calPierData.voltCalVal    = RawCalData[MODE_11A].pPerChanDataPALOff[ii].volt_cal_value;
            calPierData.olpcGainDeltaPALOn = 0;//RawCalData[MODE_11A].pPerChanDataPALOn[ii].olpc_gain_delta;
#if 0
            calPierData.desiredScaleCck = RawCalData[MODE_11A].pPerChanDataPALOff[ii].desired_scale_cck;
            calPierData.desiredScalePsk = RawCalData[MODE_11A].pPerChanDataPALOff[ii].desired_scale_psk;
            calPierData.desiredScaleQam = RawCalData[MODE_11A].pPerChanDataPALOff[ii].desired_scale_qam;
#endif

            memcpy((void*)&otpCalBuf[startIdx], (void*)&calPierData, sizeof(AR6003_CAL_DATA_PER_FREQ_OLPC));
            length += 4;
            startIdx += 4;
	}
    } //end Amode

    if(_OTA_MODE_11G == _OTA_MODE_11G) {	
        //11g frequency piers
        numPiers = RawCalData[MODE_11G].numChannels;
        if (numPiers > AR6003_NUM_2G_CAL_PIERS) {
            numPiers = AR6003_NUM_2G_CAL_PIERS;
        }

	for(ii = 0; ii < numPiers; ii++) {

	    //fill the 11g calibration values
            calPierData.olpcGainDelta = RawCalData[MODE_11G].pPerChanDataPALOff[ii].olpc_gain_delta;
            calPierData.thermCalVal   = RawCalData[MODE_11G].pPerChanDataPALOff[ii].therm_cal_value;
            calPierData.voltCalVal    = RawCalData[MODE_11G].pPerChanDataPALOff[ii].volt_cal_value;
            calPierData.olpcGainDeltaPALOn = 0;//RawCalData[MODE_11G].pPerChanDataPALOn[ii].olpc_gain_delta;
#if 0
            calPierData.desiredScaleCck = RawCalData[MODE_11G].pPerChanDataPALOff[ii].desired_scale_cck;
            calPierData.desiredScalePsk = RawCalData[MODE_11G].pPerChanDataPALOff[ii].desired_scale_psk;
            calPierData.desiredScaleQam = RawCalData[MODE_11G].pPerChanDataPALOff[ii].desired_scale_qam;
#endif
            memcpy((void*)&otpCalBuf[startIdx], (void*)&calPierData, sizeof(AR6003_CAL_DATA_PER_FREQ_OLPC));
            length += 4;
            startIdx += 4;
	}

    } //end g mode

    // header byte reserved by earlier startIdx =1, 
    // header byte length doesn't count header itself, only the data portion
    otpCalBuf[0] = (((AR6003_OTP_HEADER_CAL << AR6003_OTP_HEADER_TYPE_SHIFT) & AR6003_OTP_HEADER_TYPE_MASK) |
                    ((length << AR6003_OTP_HEADER_LEN_SHIFT) & AR6003_OTP_HEADER_LEN_MASK) );
    if (length) {
        *calLength = length + 1; // including header
        rc=TRUE;
    }

    return(rc);
}

// fill chip configuration sections, both common and modal, if any available in .eep
// tbd?? 1. we need to dynamically create the entries to write to OTP.
//       2. eeprom can have a maximum entries with numEntries preceeding the section.
// Note: chip configuration section implementation is postponed for Venus1.0. 
//       The thinking is to add a new (not well publicized) section, @chip_config_section_begin/end, 
//       at the end of .eep. Then we parse the section to get all entries, and write offset/addr. per
//       the design slides.
A_BOOL fillCfg(A_UINT32 devNum, A_UINT8 *buf, A_UINT32 *length)
{
    // parse .eep file, two sections
    
    return FALSE;
}

A_BOOL fillCustData(A_UINT32 devNum, A_UINT8 *buf, A_UINT32 *custDataLength)
{
    // read custdata.txt in the current directory, limited to 16B
    A_CHAR fileName[30]="custdata.txt";
    FILE *fp;
    size_t length;
    A_BOOL rc=FALSE;
    A_INT32 i;

    *custDataLength=0;
#if defined(READ_AS_BINARY_STREAM)
    if( (fp = fopen(fileName, "rb")) == NULL) {
        uiPrintf("%s doesn't exist, or can't be open\n", fileName);
        return TRUE;//FALSE;
    }

    length = fread((void*)&buf[1], 1, MAX_CUSTDATA_BYTES, fp);
#endif
    // read as hex bytes
    if( (fp = fopen(fileName, "r")) == NULL) {
        uiPrintf("%s doesn't exist, or can't be open\n", fileName);
        return TRUE;//FALSE;
    }

    length=0;
    for (i=0; i<MAX_CUSTDATA_BYTES; i++) {
        if (EOF == fscanf(fp, "%x ", &buf[i+1])) {
            break;
        }
        length++;
    }
 
    if(fp) fclose(fp);

    buf[0] = (((AR6003_OTP_HEADER_CUS_DATA << AR6003_OTP_HEADER_TYPE_SHIFT) & AR6003_OTP_HEADER_TYPE_MASK) |
                    ((length << AR6003_OTP_HEADER_LEN_SHIFT) & AR6003_OTP_HEADER_LEN_MASK) );
    if (length) {
        *custDataLength = length + 1; // including header
        rc=TRUE;
    }

    return(rc);
}



