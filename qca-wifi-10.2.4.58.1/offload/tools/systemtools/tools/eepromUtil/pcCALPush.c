//-----------------------------------------------------------------------------

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef LINUX
#include <sys/socket.h>
#include <netinet/in.h>
#include "hif.h"
#include "htc_api.h"
#else
#include "wlantype.h"
#include "dk_ver.h"
#include "dk_cmds.h"
#endif

#include "mEeprom.h"
#include "mEepStruct6003.h"
#include "eepromUtil.h"
#include "otp_routines.h"
#include "pcCALPush.h"

#ifdef LINUX
#define strnicmp strncmp
#endif

// defines

// globals & static
RAW_CAL_DATA_OLPC RawCalData[CAL_MAX_MODE];
_MEASURED_PWR  Pwr;
_CONFIGPCDAC PcdacConfig;

TPC_VERSION tpcVersion=TPC_VER2;
int MaxTempEntries = 1;
EEPROM_TEMP EepTempEntries[MAX_TEMPLATE_ENTRIES];

static _CUR_PARSING_DATA parserData;
static AR6003_EEPROM eepromData;

const A_CHAR* otaDataRateStr[] = {
      "DSSS-1",      "CCK-2L",     "CCK-2S",      "CCK-5_5L",       "CCK-5_5S",        "CCK-11L",      "CCK-11S",      "CCK-UNUSED", 
      "OFDM-6",  "OFDM-9", "OFDM-12", "OFDM-18", "OFDM-24", "OFDM-36", "OFDM-48" ,"OFDM-54",
      "MCS0-HT20","MCS1-HT20","MCS2-HT20","MCS3-HT20","MCS4-HT20","MCS5-HT20","MCS6-HT20","MCS7-HT20",
      "MCS0-HT40","MCS1-HT40","MCS2-HT40","MCS3-HT40","MCS4-HT40","MCS5-HT40","MCS6-HT40","MCS7-HT40",
      "null"
};




PCCALPUSH_CONFIG pcCALPushConfig = {
    USUAL_ROOM_TEMP,     //thermal_value
    USUAL_ROOM_VOLT,    //volt_value
    DEFAULT_MAX_MEASPWR_GOOD,
    DEFAULT_MIN_MEASPWR_GOOD,
};

// function definitions
static void readPostProcessedData(void);
static void postProcessLPRawData(char *fileIn, A_BOOL fakePwr);
static void calcCALData(void);
static A_BOOL replaceCalDataSection( A_UINT32 devNum, AR6K_EEPROM *pEepStruct);
#ifdef LINUX
static A_BOOL sendOTPCalStream2DUT(A_UINT8 *pBuf, A_INT32 length);
static A_BOOL createOTPCalStream(A_UINT32 devNum, AR6K_EEPROM *eepStruct, A_UINT8 **pBuf, A_UINT32 *pLength);
#endif
static A_BOOL regenerateLPRawData(char *fileName);


//#define ATHEROS_CONFIG_FILE "formalOTATestFlowCALNoHT40.txt"
unsigned char *ATHEROS_CONFIG_FILE;
char finalcsv_fileName[KEY_SIZE_MAX];


const A_UCHAR *oPcDataRateStr[]={
    "_OTA_RATE_1",
    "_OTA_RATE_2L",
    "_OTA_RATE_2S",
    "_OTA_RATE_5_5L",
    "_OTA_RATE_5_5S",
    "_OTA_RATE_11L",
    "_OTA_RATE_11S",
    "_OTA_RATE_UNUSED",
    "_OTA_RATE_6",
    "_OTA_RATE_9",
    "_OTA_RATE_12",
    "_OTA_RATE_18",
    "_OTA_RATE_24",
    "_OTA_RATE_36",
    "_OTA_RATE_48",
    "_OTA_RATE_54",
    "_OTA_RATE_MCS0_HT20",
    "_OTA_RATE_MCS1_HT20",
    "_OTA_RATE_MCS2_HT20",
    "_OTA_RATE_MCS3_HT20",
    "_OTA_RATE_MCS4_HT20",
    "_OTA_RATE_MCS5_HT20",
    "_OTA_RATE_MCS6_HT20",
    "_OTA_RATE_MCS7_HT20",
    "_OTA_RATE_MCS0_HT40",
    "_OTA_RATE_MCS1_HT40",
    "_OTA_RATE_MCS2_HT40",
    "_OTA_RATE_MCS3_HT40",
    "_OTA_RATE_MCS4_HT40",
    "_OTA_RATE_MCS5_HT40",
    "_OTA_RATE_MCS6_HT40",
    "_OTA_RATE_MCS7_HT40",
    "_OTA_RATE_LAST",
};


static int restuffPcdacFromConfig()
{
    FILE *fStream;
    char lineBuf[LINEBUF_SIZE], *pLine;
    char copyLineBuf[LINEBUF_SIZE];
    char delimiters[] = " =,;\t\n\r/";
    char key[KEY_SIZE_MAX];
    A_UINT32 value, i;
    int rc;
    _PCDACPERRATE  *pPcDacPerRate;
    _PCDACPERMODE  *pMode;

    if( (fStream = fopen( ATHEROS_CONFIG_FILE, "r")) == NULL ) {
        printf("Failed to open %s\n", ATHEROS_CONFIG_FILE);
        return(1);
    }
    memset((void*)&parserData, 0, sizeof(parserData));

    while(fgets(lineBuf, LINEBUF_SIZE-1, fStream) != NULL) {
        pLine = lineBuf;

        while(isspace(*pLine)) pLine++;

        if(*pLine == '#') {
            continue;
        }
    
        pLine = strtok(pLine, delimiters);
        if (pLine == NULL) { continue; }

        memset((void*)key, 0, sizeof(key));
        if (!sscanf(pLine, "%s", key)) {
            printf("Error reading key out of %s\n", pLine);
            continue;
        }

        if (0 == strcmp(key, "op")){
            pLine = strtok(NULL, delimiters);
	    if (NULL == pLine) break;
	    if(*pLine == '#') { continue; }
	    rc = sscanf(pLine, "%d", &value);
           if (!rc) {
               printf("Warning reading value out of %s\n", pLine);
               continue;
           }
	    if(_OP_TX == value){
	        parserData.parserState = _CHANNEL;
	    }
        }
        else if (0 == strcmp(key, "channel")){
            if(_CHANNEL == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%d", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }
		  parserData.curChannel = value;
		  parserData.curMode = (value<4900)?_OTA_MODE_11G:_OTA_MODE_11A;
		  //for the channel that dont exist at raw power result, just skip
		  if(_OTA_MODE_11G == parserData.curMode){
              pMode = &PcdacConfig.G_MODE;
              parserData.curChannelIdx = pMode->ch_num++;
		      if(parserData.curChannelIdx >= NUM_CAL_2G_CHANNELS){
                  pMode->ch_num--;
		          continue;
		      }
		  }else{
		      pMode = &PcdacConfig.A_MODE;
		      parserData.curChannelIdx = pMode->ch_num++;
		      if(parserData.curChannelIdx >= NUM_CAL_5G_CHANNELS){
                  pMode->ch_num--;
		          continue;
		      }
		  }
          pMode->ch[parserData.curChannelIdx].ch_val = value;
          pPcDacPerRate = &(pMode->ch[parserData.curChannelIdx].rate[0]);
		  parserData.parserState = _MASK;
            }
        }
        else if (0 == strcmp(key, "rateMask0")){
            if(_MASK == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }
		  parserData.curMask = value;
		  parserData.parserState = PCDAC_PHASE;
            }
        }		
        else if (0 == strcmp(key, "pwrGainStart0")){
            if(PCDAC_PHASE == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }
		        pPcDacPerRate[_OTA_RATE_1].pcdac_start = (A_UINT8)(value&0xff);
                pPcDacPerRate[_OTA_RATE_2L].pcdac_start = (A_UINT8)((value>>8)&0xff);
                pPcDacPerRate[_OTA_RATE_2S].pcdac_start = (A_UINT8)((value>>16)&0xff);
                pPcDacPerRate[_OTA_RATE_5_5L].pcdac_start = (A_UINT8)((value>>24)&0xff);
            }
        }
        else if (0 == strcmp(key, "pwrGainStart1")){
            if(PCDAC_PHASE == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }
		        pPcDacPerRate[_OTA_RATE_5_5S].pcdac_start = (A_UINT8)(value&0xff);
                pPcDacPerRate[_OTA_RATE_11L].pcdac_start = (A_UINT8)((value>>8)&0xff);
                pPcDacPerRate[_OTA_RATE_11S].pcdac_start = (A_UINT8)((value>>16)&0xff);
                pPcDacPerRate[_OTA_RATE_UNUSED].pcdac_start = (A_UINT8)((value>>24)&0xff);
            }
        }
        else if (0 == strcmp(key, "pwrGainStart2")){
            if(PCDAC_PHASE == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }
    		    pPcDacPerRate[_OTA_RATE_6].pcdac_start = (A_UINT8)(value&0xff);
                pPcDacPerRate[_OTA_RATE_9].pcdac_start = (A_UINT8)((value>>8)&0xff);
                pPcDacPerRate[_OTA_RATE_12].pcdac_start = (A_UINT8)((value>>16)&0xff);
                pPcDacPerRate[_OTA_RATE_18].pcdac_start = (A_UINT8)((value>>24)&0xff);
            }
        }
        else if (0 == strcmp(key, "pwrGainStart3")){
            if(PCDAC_PHASE == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }

		        pPcDacPerRate[_OTA_RATE_24].pcdac_start = (A_UINT8)(value&0xff);
                pPcDacPerRate[_OTA_RATE_36].pcdac_start = (A_UINT8)((value>>8)&0xff);
                pPcDacPerRate[_OTA_RATE_48].pcdac_start = (A_UINT8)((value>>16)&0xff);
                pPcDacPerRate[_OTA_RATE_54].pcdac_start = (A_UINT8)((value>>24)&0xff);
            }
        }
        else if (0 == strcmp(key, "pwrGainStart4")){
            if(PCDAC_PHASE == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }

		        pPcDacPerRate[_OTA_RATE_MCS0_HT20].pcdac_start = (A_UINT8)(value&0xff);
                pPcDacPerRate[_OTA_RATE_MCS1_HT20].pcdac_start = (A_UINT8)((value>>8)&0xff);
                pPcDacPerRate[_OTA_RATE_MCS2_HT20].pcdac_start = (A_UINT8)((value>>16)&0xff);
                pPcDacPerRate[_OTA_RATE_MCS3_HT20].pcdac_start = (A_UINT8)((value>>24)&0xff);
            }
        }
        else if (0 == strcmp(key, "pwrGainStart5")){
            if(PCDAC_PHASE == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }

		        pPcDacPerRate[_OTA_RATE_MCS4_HT20].pcdac_start = (A_UINT8)(value&0xff);
                pPcDacPerRate[_OTA_RATE_MCS5_HT20].pcdac_start = (A_UINT8)((value>>8)&0xff);
                pPcDacPerRate[_OTA_RATE_MCS6_HT20].pcdac_start = (A_UINT8)((value>>16)&0xff);
                pPcDacPerRate[_OTA_RATE_MCS7_HT20].pcdac_start = (A_UINT8)((value>>24)&0xff);
            }
        }
        else if (0 == strcmp(key, "pwrGainStart6")){
            if(PCDAC_PHASE == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }
		        pPcDacPerRate[_OTA_RATE_MCS0_HT40].pcdac_start = (A_UINT8)(value&0xff);
                pPcDacPerRate[_OTA_RATE_MCS1_HT40].pcdac_start = (A_UINT8)((value>>8)&0xff);
                pPcDacPerRate[_OTA_RATE_MCS2_HT40].pcdac_start = (A_UINT8)((value>>16)&0xff);
                pPcDacPerRate[_OTA_RATE_MCS3_HT40].pcdac_start = (A_UINT8)((value>>24)&0xff);
            }
        }
        else if (0 == strcmp(key, "pwrGainStart7")){
            if(PCDAC_PHASE == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }

		        pPcDacPerRate[_OTA_RATE_MCS4_HT40].pcdac_start = (A_UINT8)(value&0xff);
                pPcDacPerRate[_OTA_RATE_MCS5_HT40].pcdac_start = (A_UINT8)((value>>8)&0xff);
                pPcDacPerRate[_OTA_RATE_MCS6_HT40].pcdac_start = (A_UINT8)((value>>16)&0xff);
                pPcDacPerRate[_OTA_RATE_MCS7_HT40].pcdac_start = (A_UINT8)((value>>24)&0xff);
            }
        }
        else if (0 == strcmp(key, "pwrGainEnd0")){
            if(PCDAC_PHASE == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }
		        pPcDacPerRate[_OTA_RATE_1].pcdac_end = (A_UINT8)(value&0xff);
                pPcDacPerRate[_OTA_RATE_2L].pcdac_end = (A_UINT8)((value>>8)&0xff);
                pPcDacPerRate[_OTA_RATE_2S].pcdac_end = (A_UINT8)((value>>16)&0xff);
                pPcDacPerRate[_OTA_RATE_5_5L].pcdac_end = (A_UINT8)((value>>24)&0xff);
            }
        }
        else if (0 == strcmp(key, "pwrGainEnd1")){
            if(PCDAC_PHASE == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }
		        pPcDacPerRate[_OTA_RATE_5_5S].pcdac_end = (A_UINT8)(value&0xff);
                pPcDacPerRate[_OTA_RATE_11L].pcdac_end = (A_UINT8)((value>>8)&0xff);
                pPcDacPerRate[_OTA_RATE_11S].pcdac_end = (A_UINT8)((value>>16)&0xff);
                pPcDacPerRate[_OTA_RATE_UNUSED].pcdac_end = (A_UINT8)((value>>24)&0xff);
            }
        }
        else if (0 == strcmp(key, "pwrGainEnd2")){
            if(PCDAC_PHASE == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }
    		    pPcDacPerRate[_OTA_RATE_6].pcdac_end = (A_UINT8)(value&0xff);
                pPcDacPerRate[_OTA_RATE_9].pcdac_end = (A_UINT8)((value>>8)&0xff);
                pPcDacPerRate[_OTA_RATE_12].pcdac_end = (A_UINT8)((value>>16)&0xff);
                pPcDacPerRate[_OTA_RATE_18].pcdac_end = (A_UINT8)((value>>24)&0xff);
            }
        }
        else if (0 == strcmp(key, "pwrGainEnd3")){
            if(PCDAC_PHASE == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }

		        pPcDacPerRate[_OTA_RATE_24].pcdac_end = (A_UINT8)(value&0xff);
                pPcDacPerRate[_OTA_RATE_36].pcdac_end = (A_UINT8)((value>>8)&0xff);
                pPcDacPerRate[_OTA_RATE_48].pcdac_end = (A_UINT8)((value>>16)&0xff);
                pPcDacPerRate[_OTA_RATE_54].pcdac_end = (A_UINT8)((value>>24)&0xff);
            }
        }
        else if (0 == strcmp(key, "pwrGainEnd4")){
            if(PCDAC_PHASE == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }

		        pPcDacPerRate[_OTA_RATE_MCS0_HT20].pcdac_end = (A_UINT8)(value&0xff);
                pPcDacPerRate[_OTA_RATE_MCS1_HT20].pcdac_end = (A_UINT8)((value>>8)&0xff);
                pPcDacPerRate[_OTA_RATE_MCS2_HT20].pcdac_end = (A_UINT8)((value>>16)&0xff);
                pPcDacPerRate[_OTA_RATE_MCS3_HT20].pcdac_end = (A_UINT8)((value>>24)&0xff);
            }
        }
        else if (0 == strcmp(key, "pwrGainEnd5")){
            if(PCDAC_PHASE == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }

		        pPcDacPerRate[_OTA_RATE_MCS4_HT20].pcdac_end = (A_UINT8)(value&0xff);
                pPcDacPerRate[_OTA_RATE_MCS5_HT20].pcdac_end = (A_UINT8)((value>>8)&0xff);
                pPcDacPerRate[_OTA_RATE_MCS6_HT20].pcdac_end = (A_UINT8)((value>>16)&0xff);
                pPcDacPerRate[_OTA_RATE_MCS7_HT20].pcdac_end = (A_UINT8)((value>>24)&0xff);
            }
        }
        else if (0 == strcmp(key, "pwrGainEnd6")){
            if(PCDAC_PHASE == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }
		        pPcDacPerRate[_OTA_RATE_MCS0_HT40].pcdac_end = (A_UINT8)(value&0xff);
                pPcDacPerRate[_OTA_RATE_MCS1_HT40].pcdac_end = (A_UINT8)((value>>8)&0xff);
                pPcDacPerRate[_OTA_RATE_MCS2_HT40].pcdac_end = (A_UINT8)((value>>16)&0xff);
                pPcDacPerRate[_OTA_RATE_MCS3_HT40].pcdac_end = (A_UINT8)((value>>24)&0xff);
            }
        }
        else if (0 == strcmp(key, "pwrGainEnd7")){
            if(PCDAC_PHASE == parserData.parserState){
                pLine = strtok(NULL, delimiters);
                if (NULL == pLine) break;
                if(*pLine == '#') { continue; }
                rc = sscanf(pLine, "%x", &value);
                if (!rc) {
                    printf("Warning reading value out of %s\n", pLine);
                    continue;
                }

		        pPcDacPerRate[_OTA_RATE_MCS4_HT40].pcdac_end = (A_UINT8)(value&0xff);
                pPcDacPerRate[_OTA_RATE_MCS5_HT40].pcdac_end = (A_UINT8)((value>>8)&0xff);
                pPcDacPerRate[_OTA_RATE_MCS6_HT40].pcdac_end = (A_UINT8)((value>>16)&0xff);
                pPcDacPerRate[_OTA_RATE_MCS7_HT40].pcdac_end = (A_UINT8)((value>>24)&0xff);
            }
        }

        else {
            continue;
        }
           
        memset((void*)&lineBuf, 0, sizeof(lineBuf));

    }    

    if (fStream) fclose(fStream);
    return(0);

}

#define CONFIG_FILE "pcCALPush_config.txt"
static char delimiters[]   = " \t";
static int parseConfigPcCAL(void)
{
    FILE *fStream;
    char lineBuf[222], *pLine;

    if(access(CONFIG_FILE,0)){
        //check if there had a config file, if not, skip directly
        printf("%s not exist -using Defaults\n",CONFIG_FILE);
        return 0;
    }
    uiPrintf("\nReading in Configuration from %s \n", CONFIG_FILE);
    if( (fStream = fopen( CONFIG_FILE, "r")) == NULL ) {
        uiPrintf("Failed to open %s - using Defaults\n", CONFIG_FILE);
        return 1;
    }
    while(fgets(lineBuf, 120, fStream) != NULL) {
        pLine = lineBuf;
        while(isspace(*pLine)) pLine++;
        if(*pLine == '#') {
            continue;
        }
	else if(strnicmp("THERMAL_CAL_VALUE", pLine, strlen("THERMAL_CAL_VALUE")) == 0) {
            pLine = strchr(pLine, '=');
            pLine++;
            pLine = strtok( pLine, delimiters ); //get past any white space etc

            if(!sscanf(pLine, "%d", &pcCALPushConfig.thermal_value)) {
                uiPrintf("Unable to read the THERMAL_CAL_VALUE from %s\n", CONFIG_FILE);
                fclose(fStream);
                return 0;
            }
	     printf("pcCALPushConfig.thermal_value = %d\n",pcCALPushConfig.thermal_value);
        }
	else if(strnicmp("VOLT_CAL_VALUE", pLine, strlen("VOLT_CAL_VALUE")) == 0) {
            pLine = strchr(pLine, '=');
            pLine++;
            pLine = strtok( pLine, delimiters ); //get past any white space etc

            if(!sscanf(pLine, "%d", &pcCALPushConfig.volt_value)) {
                uiPrintf("Unable to read the VOLT_CAL_VALUE from %s\n", CONFIG_FILE);
                fclose(fStream);
                return 0;
            }
	     printf("pcCALPushConfig.volt_value = %d\n",pcCALPushConfig.volt_value);
        }
    else if(strnicmp("OLPC_MAX_MEASPWR_GOOD", pLine, strlen("OLPC_MAX_MEASPWR_GOOD")) == 0) {
            pLine = strchr(pLine, '=');
            pLine++;
            pLine = strtok( pLine, delimiters ); //get past any white space etc

            if(!sscanf(pLine, "%d", &pcCALPushConfig.maxMeasPwrGood)) {
                uiPrintf("Unable to read the OLPC_MAX_MEASPWR_GOOD from %s\n", CONFIG_FILE);
                fclose(fStream);
                return 0;
            }
	     printf("pcCALPushConfig.maxMeasPwrGood = %d\n",pcCALPushConfig.maxMeasPwrGood);
        }
    else if(strnicmp("OLPC_MIN_MEASPWR_GOOD", pLine, strlen("OLPC_MIN_MEASPWR_GOOD")) == 0) {
            pLine = strchr(pLine, '=');
            pLine++;
            pLine = strtok( pLine, delimiters ); //get past any white space etc

            if(!sscanf(pLine, "%d", &pcCALPushConfig.minMeasPwrGood)) {
                uiPrintf("Unable to read the OLPC_MIN_MEASPWR_GOOD from %s\n", CONFIG_FILE);
                fclose(fStream);
                return 0;
            }
	     printf("pcCALPushConfig.minMeasPwrGood = %d\n",pcCALPushConfig.minMeasPwrGood);
        }
    }
	
    fclose(fStream);
    return 0;
}

void printPcdacConfigInfo()
{
    int i,j,k,l;
    A_UINT32 pcdac_val;
    unsigned char str[100];
    _PCDACPERMODE *pMode;

    for(l=_OTA_MODE_11G;l<=_OTA_MODE_11A;l++){
        pMode =(l==_OTA_MODE_11G)?&PcdacConfig.G_MODE:&PcdacConfig.A_MODE;
        for(i=0;i<pMode->ch_num;i++){
            printf("channel = %d\n",pMode->ch[i].ch_val);
            for(k=0;k<8;k++){
                pcdac_val = 0;
                sprintf(str, "pwrGainStart%d", k);
                printf("%s = ",str);
                for(j=0;j<4;j++){
                    pcdac_val |= (A_UINT32)((pMode->ch[i].rate[j+k*4].pcdac_start)<<(j*8));
                }
                printf("0x%08x\n",pcdac_val);
            }
            for(k=0;k<8;k++){
                pcdac_val = 0;
                sprintf(str, "pwrGainEnd%d", k);
                printf("%s = ",str);
                for(j=0;j<4;j++){
                    pcdac_val |= (A_UINT32)((pMode->ch[i].rate[j+k*4].pcdac_end)<<(j*8));
                }
                printf("0x%08x\n",pcdac_val);
            }
        }
    }

    
}

static A_BOOL printfCSVInfo()
{
    FILE *fStream=NULL;
    int i,mode,j,k;
    const char file_name[]="csvInfo.txt";
    _PARAMPERMODE *pMode;
    A_UINT32 rateMask;
    A_UINT32 rateIdx,bit0;
    _PARAMPERRATE *pp;
    
    printf("goto %s to see the csv info\n",file_name);
    if( (fStream = fopen(file_name, "w")) == NULL ) {
            printf("Failed to open %s \n", file_name);
        return(FALSE);
    }
    for(mode = _OTA_MODE_11G;mode <= _OTA_MODE_11A;mode++){
        pMode =(_OTA_MODE_11G == mode)?&Pwr.G_MODE:&Pwr.A_MODE;
        fprintf(fStream,"%s desiredScale6M = 0x%x\n",(_OTA_MODE_11G == mode)?"2G":"5G",pMode->desiredScale6M);
        for(i=0;i<pMode->numChan;i++){
            fprintf(fStream,"CH: %d ,",pMode->channel_val[i]);
            rateMask=pMode->paramPerCh[i].rateMask;
            fprintf(fStream," rateMask(0x%08x)  \n",rateMask);
            rateIdx=_OTA_RATE_1;
            bit0 = 0x1;
            while(rateMask) {
                if (rateMask & bit0) {
                    rateMask &= ~bit0;               
                    fprintf(fStream," rate(%s) ",otaDataRateStr[rateIdx]);
                    pp=&(pMode->paramPerCh[i].param_rate[rateIdx]);
                    fprintf(fStream,"pcdacNum(%d): \n",pp->pcdacNum);
                    for(k=0;k<pp->pcdacNum;k++){
                        fprintf(fStream,"  power = %.1f, pcdac = 0x%x\n",(pp->param[k].txPower)/10.0,pp->param[k].pcdac);
                    }
                }
                rateIdx++; bit0 = bit0 << 1;
            }
        }
    }
    

    fclose(fStream);
    return(TRUE);
}

#define FILENAME_SIZE 64

int main(int argc, char *argv[])
{
    A_UINT8 *pBuf;
    A_UINT32 length;
    char configFile[FILENAME_SIZE];
    int i;
		
    parseConfigPcCAL();
    //temporarily remove the checking 
    //if (5 != argc) {
    if(0){
        printf("Usage: pcCALPush.out <lp.pwr> <golden eeprom.bin> <output eeprom.bin> <testscript>\n");
        return -1;
    }
    strcpy(configFile, argv[3]);
    ATHEROS_CONFIG_FILE = configFile;

    printf("configFile = %s\n",ATHEROS_CONFIG_FILE);

    
    memset((void*)&PcdacConfig, 0, sizeof(PcdacConfig));    
    if(restuffPcdacFromConfig()){
        return(-1);
    }
    //printPcdacConfigInfo(); 

    regenerateLPRawData(argv[1]);  //we re_generate LP raw Data, here, restuff the pcdac into the .csv
   
    
    // read LP power file
    // LP raw file -> post processor based on demand -> output file as needed
    //   For example, TPC CAL post processor only picks the one in the range
    //   but power sweeping post processor picks all power measurement per gain/tgt power
    postProcessLPRawData(finalcsv_fileName, FALSE);  // could call a perl script, e.g.


#if 1
        printf("2G: ");
        for(i=0;i<Pwr.G_MODE.numChan;i++){
			printf("%d ",Pwr.G_MODE.channel_val[i]);
        }
        printf("\n");
        printf("5G: ");
        for(i=0;i<Pwr.A_MODE.numChan;i++){
			printf("%d ",Pwr.A_MODE.channel_val[i]);
        }
        printf("\n");
#endif
    printfCSVInfo();
    
    readPostProcessedData(); 
    
    //
    // read the same "golden" bin file
    if (FALSE == readCalDataFromFileBin(argv[2], (AR6K_EEPROM *)&eepromData)) {
        printf("Error reading EEPROM bin file %s \n", argv[2]);
        return -1;
    }

    // calculate CAL data
    calcCALData();

    // populate eeprom CAL data section
    replaceCalDataSection(0, &eepromData);

    // generate binary file
    if (FALSE == genEepromBinFile(argv[4], &eepromData)) {
        printf("Error creating EEPROM bin file %s \n", argv[3]);
        return -1;
    }
    else {
        printf(".created EEPROM bin file %s \n", argv[3]);
    }
#ifdef LINUX
    // create OTP CAL stream,
    if (FALSE == createOTPCalStream(0, &eepromData, &pBuf, &length)) { printf("Error creating OTP bin stream \n");
        return -1;
    }
#if 0
    // send to DUT
    if (!sendOTPCalStream2DUT(pBuf, length)) {
        return -1;
    }
#endif
#endif
    return 0;
}

#define HT40_PWR_DELTA  5
#define OLPC_CCK_PWRDELTA 20
static void calcCALData(void)
{
    A_UINT32 i, j, c;
    A_INT16 actualOlpcGainDelta_t10, roundedOlpcGainDelta_t10; 
    A_INT16     newDesiredScale_t10;
    A_INT16 *txPwr;
    RAW_PER_CHAN_CALDATA_OLPC *parms;
    A_UINT32 numChans; 
    A_INT32  desiredScale6M;
    A_UINT32 mode;
    A_UINT16  *pChannel;
    A_UINT16 channel_val;
    A_UINT8  *pDesiredScale;
    A_UINT8  *pcDac;
    A_UINT32 rateMask, bit0;
    A_UINT32    rateIdx, desiredScaleCompDelta;
    A_UINT32 rddata; 
    A_INT16     power_to_store_t10;
    A_UINT32 idx;
    _PARAMPERRATE *pParmPerRate=NULL;
    _PARAMPERPCDAC *pParmPerPcdac=NULL;
    A_BOOL gotIt=FALSE;

  for (mode=_OTA_MODE_11G, numChans=Pwr.G_MODE.numChan, desiredScale6M = Pwr.G_MODE.desiredScale6M; 
       mode < _OTA_MODE_LAST; 
       mode++, numChans=Pwr.A_MODE.numChan, desiredScale6M = Pwr.A_MODE.desiredScale6M) {
    for (c=0;c<numChans;c++) {
        if (_OTA_MODE_11G == mode) {
            parms = &(Pwr.G_MODE.perChanData[c]);
            pParmPerRate = &(Pwr.G_MODE.paramPerCh[c].param_rate[0]); 
            pChannel = &(Pwr.G_MODE.channel_val[0]);
            pDesiredScale = &(Pwr.G_MODE.perChanData[c].desiredScale[0]);
            rateMask = Pwr.G_MODE.paramPerCh[c].rateMask;
        }
        else {
            parms = &(Pwr.A_MODE.perChanData[c]);
            pParmPerRate = &(Pwr.A_MODE.paramPerCh[c].param_rate[0]); 
            pChannel = &(Pwr.A_MODE.channel_val[0]);
            pDesiredScale = &(Pwr.A_MODE.perChanData[c].desiredScale[0]);
            rateMask = Pwr.A_MODE.paramPerCh[c].rateMask;
        }

        //do sweep pwr checking
        if(!pParmPerRate[_OTA_RATE_6].pcdacNum){
            printf("ERROR: at ch(%d), rate(%s), no corresponding pcdac/pwr , need to check the result...\n",pChannel[c],otaDataRateStr[_OTA_RATE_6]);
            exit(0);
        }
        
        gotIt = FALSE;
        for(idx=0;idx<pParmPerRate[_OTA_RATE_6].pcdacNum;idx++){
            pParmPerPcdac = &(pParmPerRate[_OTA_RATE_6].param[idx]); //temporarily set 
            if((2*(pParmPerPcdac->txPower/10)>=pcCALPushConfig.minMeasPwrGood)&&(2*(pParmPerPcdac->txPower/10)<=pcCALPushConfig.maxMeasPwrGood)){
                printf("ch(%d),rate(%s) used: pcdac(0x%x), power(%d),idx(%d)\n",pChannel[c],otaDataRateStr[_OTA_RATE_6],pParmPerPcdac->pcdac,pParmPerPcdac->txPower,idx);
                pParmPerRate[_OTA_RATE_6].param[PCDAC_MAX-1].pcdac = idx; //store it, maybe need  in future.
                gotIt = TRUE;
                break;
            }
        }

        if(!gotIt){
            printf("ERROR: ch(%d),power(%.1f) at csv file don't drop into range of %.1f-%.1f,plz check!\n",pChannel[c],(pParmPerPcdac->txPower/10.0),pcCALPushConfig.minMeasPwrGood/2.0,pcCALPushConfig.maxMeasPwrGood/2.0);
            exit(0);
        }

        /* calculate olpc_gain_delta, signed 8b in half dB */
        //power_to_store_t10 = (A_INT16)(txPwr[_OTA_RATE_6]  - 0.5);
        power_to_store_t10 = pParmPerPcdac->txPower;
        actualOlpcGainDelta_t10 = (A_INT16) ((power_to_store_t10 - pParmPerPcdac->pcdac*5) + desiredScale6M*5);
        //actualOlpcGainDelta_t10 = (A_INT16) (txPwr[_OTA_RATE_6] + desiredScale6M*5);
        //printf("actualOlpcGainDelta_t10 = %d\n",actualOlpcGainDelta_t10);

        parms->olpc_gain_delta = roundedOlpcGainDelta_t10 = actualOlpcGainDelta_t10 /5; 
        parms->olpc_gain_delta_t10 = actualOlpcGainDelta_t10; 
        roundedOlpcGainDelta_t10 *= 5; 
        desiredScaleCompDelta = actualOlpcGainDelta_t10 - roundedOlpcGainDelta_t10;

	    *(pDesiredScale + _OTA_RATE_6) = desiredScale6M*5 - desiredScaleCompDelta;
	    printf("channel(%d) = %d\n",c,pChannel[c]);
   	    printf("++ rate(%s), power(%d),pcdac(%d),newDesiredScale_t10(%d)\n",oPcDataRateStr[_OTA_RATE_6],pParmPerPcdac->txPower,pParmPerPcdac->pcdac,pDesiredScale[_OTA_RATE_6]);
    
        rateIdx=_OTA_RATE_1;
        
        bit0 = 0x1;
        // 6M is done already
        rateMask &= ~0x100;
        while(rateMask) {
            if (rateMask & bit0) {
                pParmPerPcdac = &(pParmPerRate[rateIdx].param[idx]); //temporarily set 
                newDesiredScale_t10 = pParmPerPcdac->pcdac*5 + actualOlpcGainDelta_t10 - (A_INT16)(pParmPerPcdac->txPower);
		        printf("--> pcDac[rateIdx]=0x%02x,roundedOlpcGainDelta_t10=%d,(txPwr[rateIdx])=%d\n",pParmPerPcdac->pcdac,roundedOlpcGainDelta_t10,(A_INT16)(pParmPerPcdac->txPower));
		        if (rateIdx >= _OTA_RATE_MCS0_HT40 && rateIdx <= _OTA_RATE_MCS7_HT40) {
		            newDesiredScale_t10 -= HT40_PWR_DELTA;  
		        }
		        *(pDesiredScale +rateIdx) = newDesiredScale_t10;
                //printf("rate(%s), power(%d),pcdac(%d),newDesiredScale_t10(%d)\n",oPcDataRateStr[rateIdx],(txPwr[rateIdx]),pcDac[rateIdx],pDesiredScale[rateIdx]);
                rateMask &= ~bit0; 
            }
            rateIdx++; bit0 = bit0 << 1;
        }
	    //printf("-- rate(%s), power(%d),pcdac(%d),newDesiredScale_t10(%d)\n",oPcDataRateStr[_OTA_RATE_6],(txPwr[_OTA_RATE_6]),pcDac[_OTA_RATE_6],pDesiredScale[_OTA_RATE_6]);
        // calculate average desired scale for cck, psk, qam
        if (mode == _OTA_MODE_11G) {
            parms->desired_scale_1m = (A_UINT8)(pDesiredScale[_OTA_RATE_1]); 
            parms->desired_scale_11m = (A_UINT8)(pDesiredScale[_OTA_RATE_11S]); 
            parms->desired_scale_6m = (A_UINT8)(pDesiredScale[_OTA_RATE_6]); 
            parms->desired_scale_36m = (A_UINT8)(pDesiredScale[_OTA_RATE_36]); 
            parms->desired_scale_54m = (A_UINT8)(pDesiredScale[_OTA_RATE_54]); 
            parms->desired_scale_mcs0ht20 = (A_UINT8)(pDesiredScale[_OTA_RATE_MCS0_HT20]); 
            parms->desired_scale_mcs7ht20 = (A_UINT8)(pDesiredScale[_OTA_RATE_MCS7_HT20]); 

            parms->desired_scale_mcs0ht40 = (A_UINT8)(pDesiredScale[_OTA_RATE_MCS0_HT40]); 
            parms->desired_scale_mcs7ht40 = (A_UINT8)(pDesiredScale[_OTA_RATE_MCS7_HT40]); 
            // since we don't CAL HT40 for 2G, set to cfg values
            parms->desired_scale_mcs0ht40 = (A_UINT8)0xd; //art_getFieldForModeChecked(0,"bb_tpc_12_desired_scale_ht40_0", 1, 0); 
            parms->desired_scale_mcs0ht40 *=5;
            parms->desired_scale_mcs7ht40 = (A_UINT8)0xe; //art_getFieldForModeChecked(0,"bb_tpc_12_desired_scale_ht40_5", 1, 0); 
            parms->desired_scale_mcs7ht40 *=5;

            parms->desired_scale_psk = (A_UINT8)((pDesiredScale[_OTA_RATE_6] + pDesiredScale[_OTA_RATE_MCS0_HT20]) /2); 
            parms->desired_scale_qam = (A_UINT8)((pDesiredScale[_OTA_RATE_36] + pDesiredScale[_OTA_RATE_54] + pDesiredScale[_OTA_RATE_MCS7_HT20]) /3); 
            parms->desired_scale_cck = (A_UINT8)((pDesiredScale[_OTA_RATE_1] + pDesiredScale[_OTA_RATE_11S]) /2); 
	/*
            if ( parms->desired_scale_cck > OLPC_CCK_PWRDELTA)
                parms->desired_scale_cck  -= OLPC_CCK_PWRDELTA;
        */
            parms->desired_scale_cck  = 0;
        }
        else {
            parms->desired_scale_6m = (A_UINT8)(pDesiredScale[_OTA_RATE_6]); 
            parms->desired_scale_36m = (A_UINT8)(pDesiredScale[_OTA_RATE_36]); 
            parms->desired_scale_54m = (A_UINT8)(pDesiredScale[_OTA_RATE_54]); 
            parms->desired_scale_mcs0ht20 = (A_UINT8)(pDesiredScale[_OTA_RATE_MCS0_HT20]); 
            parms->desired_scale_mcs7ht20 = (A_UINT8)(pDesiredScale[_OTA_RATE_MCS7_HT20]); 
            parms->desired_scale_mcs0ht40 = (A_UINT8)(pDesiredScale[_OTA_RATE_MCS0_HT40]); 
            parms->desired_scale_mcs7ht40 = (A_UINT8)(pDesiredScale[_OTA_RATE_MCS7_HT40]); 

            parms->desired_scale_psk = (A_UINT8)((pDesiredScale[_OTA_RATE_6] + pDesiredScale[_OTA_RATE_MCS0_HT20] + pDesiredScale[_OTA_RATE_MCS2_HT40]) /3)/5;
            parms->desired_scale_qam = (A_UINT8)((pDesiredScale[_OTA_RATE_36] + pDesiredScale[_OTA_RATE_54] + pDesiredScale[_OTA_RATE_MCS7_HT20] + pDesiredScale[_OTA_RATE_MCS7_HT40] ) /4) /5;
            parms->desired_scale_cck = 0;
	}
    
#if 1  // this has to be done at OTP now   
        /* read latest_therm_value and volt_value */
        //rddata = art_regRead(0, PHY_BB_THERM_ADC_4_ADDRESS);
        parms->therm_cal_value = pcCALPushConfig.thermal_value;
        parms->volt_cal_value = pcCALPushConfig.volt_value;
#endif

     }
  }
  return;
}

static A_BOOL replaceCalDataSection( A_UINT32 devNum, AR6K_EEPROM *pEepStruct)
{
    A_UINT32 ii, jj;
    A_UINT32 numPiers;
    A_UINT32 maxCALChans5G, maxCALChans2G;
    A_UINT8 *pFreqPier5G=NULL, *pFreqPier2G;
    AR6003_CAL_DATA_PER_FREQ_OLPC *pCalDataPerFreq=NULL;

    RawCalData[_OTA_MODE_11A].numChannels = Pwr.A_MODE.numChan;
    RawCalData[_OTA_MODE_11G].numChannels = Pwr.G_MODE.numChan;
    RawCalData[_OTA_MODE_11A].pChannels   = &(Pwr.A_MODE.channel_val[0]); 
    RawCalData[_OTA_MODE_11G].pChannels   = &(Pwr.G_MODE.channel_val[0]);
    RawCalData[_OTA_MODE_11A].pPerChanDataPALOff = &(Pwr.A_MODE.perChanData[0]);
    RawCalData[_OTA_MODE_11G].pPerChanDataPALOff = &(Pwr.G_MODE.perChanData[0]);

    if (TPC_VER2 == tpcVersion) {
	maxCALChans5G = AR6003_NUM_5G_CAL_PIERS_EXPANDED;
	maxCALChans2G = AR6003_NUM_2G_CAL_PIERS_EXPANDED;
	pFreqPier5G = &pEepStruct->calFreqPier5GExpanded[0];
	pFreqPier2G = &pEepStruct->calFreqPier2GExpanded[0];
        // the old CAL data segment should be all 0s
    }
    else if (TPC_VER1 == tpcVersion) {
	maxCALChans5G = AR6003_NUM_5G_CAL_PIERS;
	maxCALChans2G = AR6003_NUM_2G_CAL_PIERS;
	pFreqPier5G = &pEepStruct->calFreqPier5G[0];
	pFreqPier2G = &pEepStruct->calFreqPier2G[0];
        // the new CAL data segment should be all 0s
    }
    else { uiPrintf("unknown tpc scheme\n"); return(FALSE);}

    if(_OTA_MODE_11A == _OTA_MODE_11A) {

        numPiers = RawCalData[_OTA_MODE_11A].numChannels;

        //fill 11a frequency piers and cal data
        if (numPiers > maxCALChans5G) {
            numPiers = maxCALChans5G;
        }

        //should probably check against chain mask, TODO
	for (ii=0; ii<numPiers; ii++) {

            if (TPC_VER2 == tpcVersion) {
                pCalDataPerFreq = &(pEepStruct->calPierData5GExpanded[ii].olpcBasic);
            }
            else if (TPC_VER1 == tpcVersion) {
                pCalDataPerFreq = &(pEepStruct->calPierData5G[ii]);
            }
            else { 
                uiPrintf("unknown tpc scheme\n"); 
                pCalDataPerFreq = &(pEepStruct->calPierData5G[ii]);
            }

	    //frequency pier, 
	    pFreqPier5G[ii] = (A_UINT8)(FREQ2FBIN(RawCalData[_OTA_MODE_11A].pChannels[ii], FALSE));

	    //fill the 11a calibration values for the chan
            pCalDataPerFreq->olpcGainDelta = RawCalData[_OTA_MODE_11A].pPerChanDataPALOff[ii].olpc_gain_delta;
            pCalDataPerFreq->olpcGainDeltaPALOn = 0;//RawCalData[_OTA_MODE_11A].pPerChanDataPALOn[ii].olpc_gain_delta;
            pCalDataPerFreq->thermCalVal   = RawCalData[_OTA_MODE_11A].pPerChanDataPALOff[ii].therm_cal_value;
            pCalDataPerFreq->voltCalVal    = RawCalData[_OTA_MODE_11A].pPerChanDataPALOff[ii].volt_cal_value;
            if (TPC_VER2 == tpcVersion) {
		pEepStruct->calPierData5GExpanded[ii].olpcGainDelta_t10 = RawCalData[_OTA_MODE_11A].pPerChanDataPALOff[ii].olpc_gain_delta_t10;
		pEepStruct->calPierData5GExpanded[ii].desiredScaleCck_t10 = 0;
		pEepStruct->calPierData5GExpanded[ii].desiredScale6M_t10 = RawCalData[_OTA_MODE_11A].pPerChanDataPALOff[ii].desired_scale_6m;
		pEepStruct->calPierData5GExpanded[ii].desiredScale36M_t10 = RawCalData[_OTA_MODE_11A].pPerChanDataPALOff[ii].desired_scale_36m;
		pEepStruct->calPierData5GExpanded[ii].desiredScale54M_t10 = RawCalData[_OTA_MODE_11A].pPerChanDataPALOff[ii].desired_scale_54m;
		pEepStruct->calPierData5GExpanded[ii].desiredScaleMCS0HT20_t10 = RawCalData[_OTA_MODE_11A].pPerChanDataPALOff[ii].desired_scale_mcs0ht20;
		pEepStruct->calPierData5GExpanded[ii].desiredScaleMCS7HT20_t10 = RawCalData[_OTA_MODE_11A].pPerChanDataPALOff[ii].desired_scale_mcs7ht20;
		pEepStruct->calPierData5GExpanded[ii].desiredScaleMCS0HT40_t10 = RawCalData[_OTA_MODE_11A].pPerChanDataPALOff[ii].desired_scale_mcs0ht40;
		pEepStruct->calPierData5GExpanded[ii].desiredScaleMCS7HT40_t10 = RawCalData[_OTA_MODE_11A].pPerChanDataPALOff[ii].desired_scale_mcs7ht40;
            }
#if 1
            printf("chan %d PAL %s olpc_delta_t10 %d olpc_delta %d therm 0x%x volt 0x%x pcDac %d power_t2 %d offsets: cck %d, 6m %d, 36m %d 54m %d mcs0_20 %d mcs7_20 %d mcs0_40 %d mcs7_40 %d, \n", 
                     RawCalData[_OTA_MODE_11A].pChannels[ii],
                    ("Off"),pEepStruct->calPierData5GExpanded[ii].olpcGainDelta_t10, pCalDataPerFreq->olpcGainDelta, pCalDataPerFreq->thermCalVal, 
                    pCalDataPerFreq->voltCalVal , \
                    Pwr.A_MODE.paramPerCh[ii].param_rate[_OTA_RATE_6].param[Pwr.A_MODE.paramPerCh[ii].param_rate[_OTA_RATE_6].param[PCDAC_MAX-1].pcdac].pcdac, \
                    (Pwr.A_MODE.paramPerCh[ii].param_rate[_OTA_RATE_6].param[Pwr.A_MODE.paramPerCh[ii].param_rate[_OTA_RATE_6].param[PCDAC_MAX-1].pcdac].txPower)/5, 
                    pEepStruct->calPierData5GExpanded[ii].desiredScaleCck_t10,
                    pEepStruct->calPierData5GExpanded[ii].desiredScale6M_t10,
                    pEepStruct->calPierData5GExpanded[ii].desiredScale36M_t10,
                    pEepStruct->calPierData5GExpanded[ii].desiredScale54M_t10,
                    pEepStruct->calPierData5GExpanded[ii].desiredScaleMCS0HT20_t10,
                    pEepStruct->calPierData5GExpanded[ii].desiredScaleMCS7HT20_t10,
                    pEepStruct->calPierData5GExpanded[ii].desiredScaleMCS0HT40_t10,
                    pEepStruct->calPierData5GExpanded[ii].desiredScaleMCS7HT40_t10
                    );
#endif
	}

        if(numPiers < maxCALChans5G) {
            for(jj = ii ; jj < maxCALChans5G; jj++) {
                pFreqPier5G[jj] = AR6003_BCHAN_UNUSED;
            }
        }
    } 
    else {  // mark un-calibrated channels
        for(jj = 0 ; jj < maxCALChans5G; jj++) {
            pFreqPier5G[jj] = AR6003_BCHAN_UNUSED;
        }
    } //end Amode

    if(_OTA_MODE_11G == _OTA_MODE_11G) {	
        //11g frequency piers
        numPiers = RawCalData[_OTA_MODE_11G].numChannels;
        //numPiers = CalSetup.numForcedPiers_2p4[_OTA_MODE_11g];
        if (numPiers > maxCALChans2G) {
            numPiers = maxCALChans2G;
        }

        //should probably check against chain mask, TODO
	for(ii = 0; ii < numPiers; ii++) {

            if (TPC_VER2 == tpcVersion) {
                pCalDataPerFreq = &(pEepStruct->calPierData2GExpanded[ii].olpcBasic);
            }
            else if (TPC_VER1 == tpcVersion) {
                pCalDataPerFreq = &(pEepStruct->calPierData2G[ii]);
            }
            else { 
                uiPrintf("unknown tpc scheme\n"); 
                pCalDataPerFreq = &(pEepStruct->calPierData2G[ii]);
            }

	    pFreqPier2G[ii] = (A_UINT8)(FREQ2FBIN(RawCalData[_OTA_MODE_11G].pChannels[ii], TRUE));

	    //fill the 11g calibration values
            pCalDataPerFreq->olpcGainDelta = RawCalData[_OTA_MODE_11G].pPerChanDataPALOff[ii].olpc_gain_delta;
            pCalDataPerFreq->olpcGainDeltaPALOn = 0;//RawCalData[_OTA_MODE_11G].pPerChanDataPALOn[ii].olpc_gain_delta;
            pCalDataPerFreq->thermCalVal   = RawCalData[_OTA_MODE_11G].pPerChanDataPALOff[ii].therm_cal_value;
            pCalDataPerFreq->voltCalVal    = RawCalData[_OTA_MODE_11G].pPerChanDataPALOff[ii].volt_cal_value;
            if (TPC_VER2 == tpcVersion) {
	        pEepStruct->calPierData2GExpanded[ii].olpcGainDelta_t10 = RawCalData[_OTA_MODE_11G].pPerChanDataPALOff[ii].olpc_gain_delta_t10;
	        pEepStruct->calPierData2GExpanded[ii].desiredScaleCck_t10 = RawCalData[_OTA_MODE_11G].pPerChanDataPALOff[ii].desired_scale_cck;
	        pEepStruct->calPierData2GExpanded[ii].desiredScale6M_t10 = RawCalData[_OTA_MODE_11G].pPerChanDataPALOff[ii].desired_scale_6m;
	        pEepStruct->calPierData2GExpanded[ii].desiredScale36M_t10 = RawCalData[_OTA_MODE_11G].pPerChanDataPALOff[ii].desired_scale_36m;
	        pEepStruct->calPierData2GExpanded[ii].desiredScale54M_t10 = RawCalData[_OTA_MODE_11G].pPerChanDataPALOff[ii].desired_scale_54m;
	        pEepStruct->calPierData2GExpanded[ii].desiredScaleMCS0HT20_t10 = RawCalData[_OTA_MODE_11G].pPerChanDataPALOff[ii].desired_scale_mcs0ht20;
	        pEepStruct->calPierData2GExpanded[ii].desiredScaleMCS7HT20_t10 = RawCalData[_OTA_MODE_11G].pPerChanDataPALOff[ii].desired_scale_mcs7ht20;
	        pEepStruct->calPierData2GExpanded[ii].desiredScaleMCS0HT40_t10 = RawCalData[_OTA_MODE_11G].pPerChanDataPALOff[ii].desired_scale_mcs0ht40;
	        pEepStruct->calPierData2GExpanded[ii].desiredScaleMCS7HT40_t10 = RawCalData[_OTA_MODE_11G].pPerChanDataPALOff[ii].desired_scale_mcs7ht40;
            }
#if 1
            printf("chan %d PAL %s olpc_delta_t10 %d olpc_delta %d therm 0x%x volt 0x%x pcDac %d power_t2 %d offsets: cck %d, 6m %d, 36m %d 54m %d mcs0_20 %d mcs7_20 %d mcs0_40 %d mcs7_40 %d, \n", 
                     RawCalData[_OTA_MODE_11G].pChannels[ii],
                    ("Off"),pEepStruct->calPierData2GExpanded[ii].olpcGainDelta_t10, pCalDataPerFreq->olpcGainDelta, pCalDataPerFreq->thermCalVal, 
                    pCalDataPerFreq->voltCalVal , \
                    Pwr.G_MODE.paramPerCh[ii].param_rate[_OTA_RATE_6].param[Pwr.G_MODE.paramPerCh[ii].param_rate[_OTA_RATE_6].param[PCDAC_MAX-1].pcdac].pcdac, \
                    (Pwr.G_MODE.paramPerCh[ii].param_rate[_OTA_RATE_6].param[Pwr.G_MODE.paramPerCh[ii].param_rate[_OTA_RATE_6].param[PCDAC_MAX-1].pcdac].txPower)/5, 
                    pEepStruct->calPierData2GExpanded[ii].desiredScaleCck_t10,
                    pEepStruct->calPierData2GExpanded[ii].desiredScale6M_t10,
                    pEepStruct->calPierData2GExpanded[ii].desiredScale36M_t10,
                    pEepStruct->calPierData2GExpanded[ii].desiredScale54M_t10,
                    pEepStruct->calPierData2GExpanded[ii].desiredScaleMCS0HT20_t10,
                    pEepStruct->calPierData2GExpanded[ii].desiredScaleMCS7HT20_t10,
                    pEepStruct->calPierData2GExpanded[ii].desiredScaleMCS0HT40_t10,
                    pEepStruct->calPierData2GExpanded[ii].desiredScaleMCS7HT40_t10
                    );
#endif
	}

        if(numPiers < maxCALChans2G) {
            for(jj = ii ; jj < maxCALChans2G; jj++) {
                pFreqPier2G[jj] = AR6003_BCHAN_UNUSED;
            }
        }
    } 
    else {
        for(jj = 0 ; jj < maxCALChans2G; jj++) {
            pFreqPier2G[jj] = AR6003_BCHAN_UNUSED;
        }
    } //end g mode

    return(TRUE);
}


#if 0
    // from loadAR6000.sh
            # CAL data 512B, starting at 0x57D684
            #calotpdatafile=${calotpdatafile:-$WORKAREA/otpCalData.bin}
            #$IMAGEPATH/bmiloader -i $NETIF --set --address=0x540668 --param=11520
            #$IMAGEPATH/bmiloader -i $NETIF --write --address=0x57D684 --file=$calotpdatafile
            #$IMAGEPATH/bmiloader -i $NETIF --write --address=0x5406e0 --param=0x57D684
            #$IMAGEPATH/bmiloader -i $NETIF --set --address=0x5406e4 --param=1

    // from targetaddr.h
    A_UINT32               hi_cal_data;                               /* 0xe0 */
    A_UINT32               hi_cal_data_avail;                         /* 0xe4 */
#endif
#define _CAL_DATA_ADDR             0x57D684
#define _HI_CAL_DATA               0x5406e0
#define _HI_CAL_DATA_AVAIL         0x5406e4
#define _HI_END_RAM_RESERVE_SZ     0x540668
#define _RESERVED_RAM_SIZE         11520
#define _CAL_DATA_SIZE             512

#if 0
A_STATUS
ar6000_WriteDataDiag(HIF_DEVICE *hifDevice, A_UINT32 address,
                    A_UCHAR *data, A_UINT32 length)
{
    A_UINT32 count;
    A_STATUS status = A_OK;

    for (count = 0; count < length; count += 4, address += 4) {
        if ((status = HIFDiagWriteAccess(hifDevice, address,
                                         *(A_UINT32 *)&data[count])) != A_OK)
        {
            break;
        }
    }

    return status;
}
#endif

#ifdef LINUX
extern A_BOOL open2DUT(void);
extern A_BOOL sendDataBuf2DUT(A_UINT8 *dataBuf, A_UINT32 startAddr, A_UINT32 length);
extern A_BOOL sendReg2DUT(A_UINT32 data, A_UINT32 addr);
static A_BOOL sendOTPCalStream2DUT(A_UINT8 *pBuf, A_INT32 length)
{
    A_UINT32 data;
    A_UINT32 address; 
    printf("Sending OTP bin stream to DUT ...\n");

    if (!open2DUT()) {
        return(FALSE);
    }

    address = _CAL_DATA_ADDR;          // 0x57D684
    if (!sendDataBuf2DUT(pBuf, address, length)) {
        return(FALSE);
    }

    address = _HI_END_RAM_RESERVE_SZ;  // 0x540668
    data = _RESERVED_RAM_SIZE;         // 11520
    if (!sendReg2DUT(data, address)) {
        return(FALSE);
    }

    address = _HI_CAL_DATA;  // 0x5406e0
    data = _CAL_DATA_ADDR;   // 0x57D684
    if (!sendReg2DUT(data, address)) {
        return(FALSE);
    }

    address = _HI_CAL_DATA_AVAIL; // 0x5406e4
    data = 1; 
    if (!sendReg2DUT(data,address)) {
        return(FALSE);
    }

    return(TRUE);
}

#define OTPSTREAM_MAXSZ_APP 256
A_UINT8 buf[OTPSTREAM_MAXSZ_APP];
#define OTPBuf buf
static A_BOOL createOTPCalStream(A_UINT32 devNum, AR6K_EEPROM *eepStruct, A_UINT8 **pBuf, A_UINT32 *pLength)
{
    A_BOOL rc=TRUE, firstTime, streamGood;
    A_INT32 startIdx=0, i, repeatedReadCount, goodReadCount;
    A_UINT32 nbytes, lenRead;
    A_UINT8 otpCalBuf[sizeof(AR6003_CAL_DATA_PER_FREQ_OLPC) * (AR6003_NUM_5G_CAL_PIERS + AR6003_NUM_2G_CAL_PIERS) + 1];
    A_UINT8 otpCfgBuf[OTPSTREAM_MAXSZ_APP]; // tbd??
    A_UINT8 otpCustDataBuf[MAX_CUSTDATA_BYTES+1];
    A_UINT32 calLength, cfgLength, custDataLength;
    AR6003_OTP_ID otpId;
    void *pTempPtr;

    if (!fillIDs(devNum, &otpId, eepStruct)) {
        uiPrintf("Error: makeIDs in programOTPCAL\n");
        return(FALSE); // tbd? abort? never fails
    }
    else {
        memcpy((void*)&buf[startIdx], (void *)&otpId, sizeof(otpId));
        startIdx += sizeof(otpId);
    }

    // fill CAL section
    if (rc = fillCALOTP(devNum, otpCalBuf, &calLength, eepStruct)) {
        memcpy((void*)&buf[startIdx], (void *)otpCalBuf, calLength);
        startIdx += calLength;
    }

    // fill cfg section
    if (rc = fillCfg(devNum, otpCfgBuf, &cfgLength)) {
        // tbd??
        memcpy((void*)&buf[startIdx], (void *)otpCfgBuf, cfgLength);
        startIdx += cfgLength;
    }

    // update customer data section, if any
    // Even custData failed, not big deal
    if (rc = fillCustData(devNum, otpCustDataBuf, &custDataLength)) {
        // tbd??
        if (custDataLength) {
            memcpy((void*)&buf[startIdx], (void *)otpCustDataBuf, custDataLength);
            startIdx += custDataLength;
        }
    }

    *pLength = (A_UINT32)startIdx;
    *pBuf = (A_UINT8*)&(buf[0]);
    return(rc);
}
#endif


static A_UINT32 getRateIdx(A_UCHAR *pRateStr)
{
    A_UINT32 i;
    for(i=0;i<_OTA_RATE_LAST;i++){
        if (0 == strcmp(pRateStr, otaDataRateStr[i])) {
            return i;
        }
    }
    return i;
}

static A_BOOL printParseData(_CUR_PARSING_DATA data)
{
    printf("===== parse data ====\n");
    printf("parserState = %d\n",data.parserState);
    printf("curChannel = %d\n",data.curChannel);
    printf("curChannelIdx = %d\n",data.curChannelIdx);
    printf("curMask = %d\n",data.curMask);
    printf("curMaskRead = %d\n",data.curMaskRead);
    printf("curMode = %d\n",data.curMode);
    return(TRUE);
}   

static A_BOOL checkCHFromTsTxt_ReturnIdx(A_UINT32 ch,A_UINT32 *idx)
{
    int i,num_ch;
    _PCDACPERMODE *pMode;
    if(0==ch){
        printf("the csv file could not have the ch that is 0, need to check!!\n");
        return(FALSE);
    }
    pMode = (ch<4900)?&PcdacConfig.G_MODE:&PcdacConfig.A_MODE;
    num_ch = (ch<4900)?NUM_CAL_2G_CHANNELS:NUM_CAL_5G_CHANNELS;
    for(i=0;i<num_ch;i++){
        if(ch == pMode->ch[i].ch_val)
            break;
    }
    if(num_ch == i){
        printf("can not find the ch(%d) at the file %s, plz check\n!",ch,ATHEROS_CONFIG_FILE);
        return(FALSE);
    }
    *idx = i;
    return(TRUE);
    
}


static A_BOOL regenerateLPRawData(char *fileName)
    {
        FILE *fStream,*fStreamCsv;
        char lineBuf[LINEBUF_SIZE], *pLine;
        char delimiters[] = " =,;\t\n\r/";
        char rateStr[KEY_SIZE_MAX];
        A_UINT32 value, i;
        int rc;
        A_UINT32 rateIdx=0;
        char copyLineBuf[LINEBUF_SIZE];
        A_UINT8 first_line = 0;
        A_UINT32 chIdx = 0;
        A_UINT32 rateIdx_pre = 255;
        _PCDACPERMODE *pMode;
        A_UINT8 pcdac_st;

        strcpy(finalcsv_fileName,fileName);
        pLine = finalcsv_fileName;
        if (NULL != strchr(finalcsv_fileName, '/')) {
            pLine = strtok(pLine, "/");
            pLine=strtok(NULL, "."); 
        }
        else {
            pLine=strtok(pLine, ".");
        }
        sprintf(finalcsv_fileName, "%s_final.csv", pLine);
        printf("final csv file name is %s\n",finalcsv_fileName);
        
        if( (fStreamCsv = fopen( finalcsv_fileName, "w")) == NULL ) {
            printf("Failed to open %s \n", finalcsv_fileName);
            return(FALSE);
        }
        if( (fStream = fopen( fileName, "r")) == NULL ) {
            printf("Failed to open %s \n", fileName);
            return(FALSE);
        }
        
        first_line = 0;
        while(fgets(lineBuf, LINEBUF_SIZE-1, fStream) != NULL) {
            memcpy(copyLineBuf,lineBuf,LINEBUF_SIZE);
            pLine = lineBuf;
            //printf("%s\n",pLine);
            while(isspace(*pLine)) pLine++;
            if(*pLine == '#') {
                continue;
            }
            pLine = strtok(pLine, delimiters);
            if (pLine == NULL) { continue; }
            //directly copy, based on the format of the raw cal result given from lp
            if(0 == first_line++) {
                //directly copy
                pLine = copyLineBuf;
                pLine=strtok(pLine, "\n");
                fprintf(fStreamCsv,"%s,pcdac\n",pLine);
                continue;
            }
            //first get the channel
            if (!sscanf(pLine, "%d", &value)) {
                printf("Warning reading value out of %s\n", pLine);
                continue;
            }
            //printf("--> value = %d\n",value); 
            if(FALSE == checkCHFromTsTxt_ReturnIdx(value,&chIdx)) {exit(0);};
            pMode = (value < 4900)?&PcdacConfig.G_MODE:&PcdacConfig.A_MODE;
            
            //then get the rate and generate the rateMask, finally get the involved pcdac & power
            pLine = strtok(NULL, delimiters);
            if (NULL == pLine) break;
            if(*pLine == '#') { continue; }
            rc = sscanf(pLine, "%s", rateStr);
            if (!rc) {
                printf("Warning reading value out of %s\n", pLine);
                continue;
            }
            //printf("--> rateStr = |%s|\n",rateStr); 
            rateIdx = getRateIdx(rateStr);
            if(_OTA_RATE_LAST == rateIdx){
                printf("warnning, no corresponding rate for %s\n",rateStr);
                printf("plz check the csv file\n");
                exit(0);
            }
            if(rateIdx_pre != rateIdx){  
                //do the reset for each rate
                if((rateIdx>=_OTA_RATE_MCS0_HT40)&&(rateIdx<=_OTA_RATE_MCS7_HT40)){
                    //ht40 right shift 10MHz
                    if(FALSE == checkCHFromTsTxt_ReturnIdx(value+10,&chIdx)) {exit(0);};
                }
                pcdac_st = pMode->ch[chIdx].rate[rateIdx].pcdac_start;
                rateIdx_pre = rateIdx;
            }

            pLine = copyLineBuf;
            pLine=strtok(pLine, "\n");
            fprintf(fStreamCsv,"%s,0x%x\n",copyLineBuf,pcdac_st++);
            if(pcdac_st > pMode->ch[chIdx].rate[rateIdx].pcdac_end+1){
                printf("ch(%d),rate(%s),pcdac(0x%x) setting is not match between csv and ts.txt file, need to check.\n",
                    value,oPcDataRateStr[rateIdx],pcdac_st);
                exit(0);
            }
            
        }

        
        if (fStreamCsv) fclose(fStreamCsv);
        if (fStream) fclose(fStream);
        return(TRUE);

    }


static A_BOOL parseRawPowerResults(char *fileName, A_BOOL fakePwr)
{
    FILE *fStream;
    char lineBuf[LINEBUF_SIZE], *pLine;
    char delimiters[] = " =,;\t\n\r/";
    char rateStr[KEY_SIZE_MAX];
    A_UINT32 value;
    int rc;
    A_UINT32 previous_ch=0;
    A_UINT32 previous_rateIdx=255;
    A_UINT32 rateIdx=0;
    float valueReal;
    A_UINT32 *pRateMask;
    A_UINT8 first_line = 0;
    _PARAMPERMODE *pMode = NULL;
    _PARAMPERRATE *pParmPerRate = NULL;

    if( (fStream = fopen( fileName, "r")) == NULL ) {
        printf("Failed to open %s - the MACID will not be written\n", fileName);
        return(FALSE);
    }

    memset((void*)&Pwr, 0, sizeof(Pwr));
    Pwr.G_MODE.desiredScale6M = 0xd; // per venus2_0.cfg
    Pwr.A_MODE.desiredScale6M = 0xe;

    //--- stuff the param into specific channel...
    first_line = 0;
    while(fgets(lineBuf, LINEBUF_SIZE-1, fStream) != NULL) {
        pLine = lineBuf;
        while(isspace(*pLine)) pLine++;
        if(*pLine == '#') {
            continue;
        }
        pLine = strtok(pLine, delimiters);
        if (pLine == NULL) { continue; }
        //-1-  skip the first line, based on the format of the raw cal result given from lp
        if(0 == first_line++) {continue;}
        //first get the channel
        if (!sscanf(pLine, "%d", &value)) {
            printf("Warning reading value out of %s\n", pLine);
            continue;
        }
	    //printf("--> value = %d\n",value); 
	    if(previous_ch != value){
            previous_ch = value;
            pMode = (value < 4900)?&Pwr.G_MODE:&Pwr.A_MODE;
            pMode->channel_val[pMode->numChan] = (A_UINT16)value;
            pRateMask = &(pMode->paramPerCh[pMode->numChan].rateMask);
            pMode->numChan++;
        }
        //-2- get the rate and generate the rateMask
        pLine = strtok(NULL, delimiters);
        if (NULL == pLine) break;
        if(*pLine == '#') { continue; }
        rc = sscanf(pLine, "%s", rateStr);
        if (!rc) {
            printf("Warning reading value out of %s\n", pLine);
            continue;
        }
        //printf("--> rateStr = |%s|\n",rateStr); 
        rateIdx = getRateIdx(rateStr);
        if(_OTA_RATE_LAST == rateIdx){
            printf("warnning, no corresponding rate for %s\n",rateStr);
        }
        *(pRateMask) |= 0x1<<rateIdx; 
        if(previous_rateIdx != rateIdx){
            previous_rateIdx = rateIdx;
            pParmPerRate = &(pMode->paramPerCh[pMode->numChan-1].param_rate[rateIdx]);
        }

        //-3- get the power for each rate
        pLine = strtok(NULL, delimiters);
        if (NULL == pLine) break;
        if(*pLine == '#') { continue; }
        rc = sscanf(pLine, "%f", &valueReal);
        if (!rc) {
            printf("Warning reading value out of %s\n", pLine);
            continue;
        }
        pParmPerRate->param[pParmPerRate->pcdacNum].txPower = (A_INT16)(valueReal*10);
        //*(pPwr)= (A_INT16)((valueReal - 0.5)*10);
        //*(pPwr)=   (A_INT16)(valueReal* 10 + 0.5);

        // -4- get the pcdac for each pwr
        pLine = strtok(NULL, delimiters);
        if (NULL == pLine) break;
        if(*pLine == '#') { continue; }
        rc = sscanf(pLine, "%x", &value);
        if (!rc) {
            printf("Warning reading value out of %s\n", pLine);
            continue;
        }
        pParmPerRate->param[pParmPerRate->pcdacNum++].pcdac= value;
        
    }

    if (fStream) fclose(fStream);
    return (TRUE);
}


static void readPostProcessedData(void) {} 

static void postProcessLPRawData(char *fileIn, A_BOOL fakePwr)
{
    FILE *fpIn;

    if( (fpIn = fopen(fileIn, "r")) == NULL) {
        printf("Could not open %s to read\n", fileIn);
        exit(0);
    }
    parseRawPowerResults(fileIn, fakePwr);
  
    if (fpIn) fclose(fpIn);
    
    return;
}

#if 0
A_STATUS
ar6000_ReadDataDiag(HIF_DEVICE *hifDevice, A_UINT32 address,
                    A_UCHAR *data, A_UINT32 length)
{
    A_UINT32 count;
    A_STATUS status = A_OK;

    for (count = 0; count < length; count += 4, address += 4) {
        if ((status = ar6000_ReadRegDiag(hifDevice, &address,
                                         (A_UINT32 *)&data[count])) != A_OK)
        {
            break;
        }
    }

    return status;
}
#endif

