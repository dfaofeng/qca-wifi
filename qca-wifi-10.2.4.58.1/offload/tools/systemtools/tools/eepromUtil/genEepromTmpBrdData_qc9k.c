//-----------------------------------------------------------------------------

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "wlantype.h"
//#include "dk_ver.h"
#include "qc98xx_eeprom.h"

// function definitions

// defines
#define LINEBUF_SIZE 2048
#define MAX_DEFINE_ENTRY 256
#define MAX_NAME_SIZE 64
#define MAX_ENTRIES_4VALUE 32

// type for template record
typedef enum {
    EEP_UINT8   = 0,
    EEP_UINT16,
    EEP_UINT32,
    EEP_INT8,
    EEP_INT16,
    EEP_INT32,
    EEP_CHAR,
    EEP_BITFIELD,
    EEP_LAST = EEP_BITFIELD
} EEP_TYPE;

typedef enum {
    EEP_HEX_VAL = 0,
    EEP_DEC_VAL,
    EEP_LAST_VAL = EEP_DEC_VAL
} EEP_TYPE_PRINT;

typedef struct {
    EEP_TYPE        dataType;
    char            key[MAX_NAME_SIZE];
    A_UINT32        size;
    EEP_TYPE_PRINT  prtType;
    A_INT32         value[MAX_ENTRIES_4VALUE];
    char            bitFieldName[MAX_ENTRIES_4VALUE][MAX_NAME_SIZE];
    A_UINT32        numBits[MAX_ENTRIES_4VALUE];
} __ATTRIB_PACK _EEPROM_ENTRY;
    
// globals & static
// eeprom base
static _EEPROM_ENTRY _eepromBase[] = {
    {EEP_UINT16, "length", 1, EEP_DEC_VAL, {sizeof(QC98XX_EEPROM)}},
    {EEP_UINT16, "checksum", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "eeprom_version", 1, EEP_HEX_VAL, {QC98XX_EEP_VER}},
    {EEP_UINT8, "template_version", 1, EEP_HEX_VAL, {0x1}},
    {EEP_UINT8, "macAddr", 6, EEP_HEX_VAL, {0x0, 0x3, 0x7, 0x12, 0x34, 0x56}},
    {EEP_UINT16, "regDmn", 2, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8, "opFlags", 1, EEP_HEX_VAL, {0x3f}},
    {EEP_UINT8, "featureEnable", 1, EEP_HEX_VAL, {0x9}},
    {EEP_UINT8, "miscConfiguration", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "flag1", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT32, "boardFlags", 1, EEP_HEX_VAL, {0x86c44}},
    {EEP_UINT16, "blueToothOptions", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "opFlags2", 1, EEP_HEX_VAL, {0x1f}},
    {EEP_UINT8, "flag2", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT16, "binBuildNumber", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "txrxMask", 1, EEP_HEX_VAL, {0x77}},
    {EEP_UINT8, "rfSilent", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "wlanLedGpio", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "spurBaseA", 1, EEP_DEC_VAL, {0x0}},
    {EEP_UINT8, "spurBaseB", 1, EEP_DEC_VAL, {0x0}},
    {EEP_UINT8, "spurRssiThresh", 1, EEP_DEC_VAL, {0x0}},
    {EEP_UINT8, "spurRssiThreshCck", 1, EEP_DEC_VAL, {0x0}},
    {EEP_UINT8, "spurMitFlag", 1, EEP_HEX_VAL, {0x0}},
    {EEP_BITFIELD, "swreg", 3, EEP_HEX_VAL, {0x0,0x4,0x9}, {"pwd","nfdiv","level"},{0x1,0x3,0x4}},
    {EEP_UINT8, "txrxgain", 1, EEP_HEX_VAL, {0x0}},
    {EEP_INT8, "pwrTableOffset", 1, EEP_HEX_VAL, {0x0}},
	{EEP_UINT8, "param_for_tuning_caps", 1, EEP_HEX_VAL, {0x3f}},
    {EEP_INT8, "deltaCck20_t10", 1, EEP_DEC_VAL, {0}},
	{EEP_INT8, "delta4020_t10", 1, EEP_DEC_VAL, {0}},
    {EEP_INT8, "delta8020_t10", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8, "custData", CUSTOMER_DATA_SIZE, EEP_HEX_VAL, {0x0}},
	{EEP_UINT8, "param_for_tuning_caps_1", 1, EEP_HEX_VAL, {0x3f}},
    {EEP_UINT8, "baseFuture", MAX_BASE_FUTURE, EEP_HEX_VAL, {0x0}},
};

// eeprom bimodal 2G
static _EEPROM_ENTRY _eepromBiModal2G_1[] = {
    {EEP_INT8,   "voltSlope", WHAL_NUM_CHAINS, EEP_DEC_VAL, {0,0,0}},
};

static _EEPROM_ENTRY _eepromSpurChans[] = {
    {EEP_UINT8,  "spurChans", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "spurA_PrimSecChoose", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "spurB_PrimSecChoose", 1, EEP_HEX_VAL, {0x0}},
};

static _EEPROM_ENTRY _eepromBiModal2G_2[] = {
    {EEP_UINT8,  "xpaBiasLvl", 1, EEP_HEX_VAL, {0xa}},
    {EEP_INT8,   "antennaGainCh", 1, EEP_HEX_VAL, {0x01}}, 
    {EEP_UINT32, "antCtrlCommon", 1, EEP_HEX_VAL, {0x90229}},
    {EEP_UINT32, "antCtrlCommon2", 1, EEP_HEX_VAL, {0x99999}},
    {EEP_UINT16, "antCtrlChain", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x150,0x150,0x150}},
    {EEP_UINT8,  "rxFilterCap", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "rxGainCap", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "txrxgain", 1, EEP_HEX_VAL, {0x0}},
	{EEP_INT8,   "noiseFlrThr", 1, EEP_DEC_VAL, {33}},
    {EEP_INT8,   "minCcaPwr", WHAL_NUM_CHAINS, EEP_DEC_VAL, {206,206,206}},
    {EEP_UINT8,  "coarseIndex", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8,  "fineIndex", 1, EEP_DEC_VAL, {0}},
    {EEP_INT8,   "adcDesiredSize", 1, EEP_DEC_VAL, {0}},
    {EEP_INT8,   "quickDrop", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8,  "maxRetrainTimes", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8,  "settleTime", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8,  "futureBiModal", MAX_BIMODAL_FUTURE, EEP_HEX_VAL, {0x00}},
};

// eeprom bimodal 5G
static _EEPROM_ENTRY _eepromBiModal5G_1[] = {
    {EEP_INT8,   "voltSlope", WHAL_NUM_CHAINS, EEP_DEC_VAL, {0,0,0}},
};
    
static _EEPROM_ENTRY _eepromBiModal5G_2[] = {
    {EEP_UINT8,  "xpaBiasLvl", 1, EEP_HEX_VAL, {0xf}},
    {EEP_INT8,   "antennaGainCh", 1, EEP_HEX_VAL, {0x0}}, 
    {EEP_UINT32, "antCtrlCommon", 1, EEP_HEX_VAL, {0x90449}},
    {EEP_UINT32, "antCtrlCommon2", 1, EEP_HEX_VAL, {0x99999}},
    {EEP_UINT16, "antCtrlChain", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0,0x0,0x0}},
    {EEP_UINT8, "rxFilterCap", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "rxGainCap", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "txrxgain", 1, EEP_HEX_VAL, {0x0}},
	{EEP_INT8,   "noiseFlrThr", 1, EEP_DEC_VAL, {33}},
    {EEP_INT8,   "minCcaPwr", WHAL_NUM_CHAINS, EEP_DEC_VAL, {181,181,181}},
    {EEP_UINT8,  "coarseIndex", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8,  "fineIndex", 1, EEP_DEC_VAL, {0}},
    {EEP_INT8,   "adcDesiredSize", 1, EEP_DEC_VAL, {0}},
    {EEP_INT8,   "quickDrop", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8,  "maxRetrainTimes", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8,  "settleTime", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8, "futureBiModal", MAX_BIMODAL_FUTURE, EEP_HEX_VAL, {0x00}},
};

// eeprom freq modal
static _EEPROM_ENTRY _eepromFreqModal_1[] = {
    {EEP_UINT8,  "xatten1DB2G", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "xatten1DB5GLow", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "xatten1DB5GMid", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "xatten1DB5GHigh", 1, EEP_HEX_VAL, {0x0}},
};

static _EEPROM_ENTRY _eepromFreqModal_2[] = {
    {EEP_UINT8,  "xatten1Margin2G", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "xatten1Margin5GLow", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "xatten1Margin5GMid", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "xatten1Margin5GHigh", 1, EEP_HEX_VAL, {0x0}},
};

static _EEPROM_ENTRY _eepromFreqModal_3[] = {
    {EEP_UINT8,  "obdbAux1Aux22G", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "obdbAux1Aux25GLow", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "obdbAux1Aux25GMid", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "obdbAux1Aux25GHigh", 1, EEP_HEX_VAL, {0x0}},
};

static _EEPROM_ENTRY _eepromFreqModal_4[] = {
    {EEP_UINT8,  "reserved2G", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "reserved5GLow", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "reserved5GMid", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "reserved5GHigh", 1, EEP_HEX_VAL, {0x0}},
};

// eeprom chip data 
static _EEPROM_ENTRY _eepromChipCalData[] = {
    {EEP_INT16, "thermAdcScaledGain", 1, EEP_DEC_VAL, {205}},
    {EEP_INT8,  "thermAdcOffset", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8,  "reserved", 1, EEP_HEX_VAL, {0x40}},
};

// eeprom CAL freq 2G
static _EEPROM_ENTRY _eepromCalFreq2G[] = {
    {EEP_UINT8, "calFreqPier2G", WHAL_NUM_11G_CAL_PIERS, EEP_DEC_VAL, {112, 142, 172}},
};

// eeprom CAL data 2G

static _EEPROM_ENTRY _eepromCalPerPoint[] = {
    {EEP_UINT8, "txgainIdx", WHAL_NUM_CAL_GAINS, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT16, "power_t8", WHAL_NUM_CAL_GAINS, EEP_DEC_VAL, {0, 0}}, 
};

static _EEPROM_ENTRY _eepromCalData2G[] = {
    {EEP_INT8,  "dacGain", WHAL_NUM_CAL_GAINS, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "thermCalVal", 1, EEP_DEC_VAL, {121}}, 
    {EEP_UINT8, "voltCalVal", 1, EEP_DEC_VAL, {100}}, 
};

// eeprom CAL target power freq 2G CCK
static _EEPROM_ENTRY _eepromTargetFreqbinCck[] = {
    {EEP_UINT8, "targetFreqbinCck", WHAL_NUM_11B_TARGET_POWER_CHANS, EEP_DEC_VAL, {112, 172}}, 
};

// eeprom CAL target power freq 2G OFDM
static _EEPROM_ENTRY _eepromTargetFreqbin2G[] = {
    {EEP_UINT8, "targetFreqbin2G", WHAL_NUM_11G_LEG_TARGET_POWER_CHANS, EEP_DEC_VAL, {112, 142, 172}}, 
};

// eeprom CAL target power freq 2G HT20 
static _EEPROM_ENTRY _eepromTargetFreqbin2GVHT20[] = {
    {EEP_UINT8, "targetFreqbin2GVHT20", WHAL_NUM_11G_20_TARGET_POWER_CHANS, EEP_DEC_VAL, {112, 142, 172}}, 
};

// eeprom CAL target power freq 2G HT40 
static _EEPROM_ENTRY _eepromTargetFreqbin2GVHT40[] = {
    {EEP_UINT8, "targetFreqbin2GVHT40", WHAL_NUM_11G_40_TARGET_POWER_CHANS, EEP_DEC_VAL, {112, 142, 172}}, 
};

// eeprom CAL target power 2G CCK
static _EEPROM_ENTRY _eepromTargetPowerCCK[] = {
    {EEP_UINT8, "targetPowerCck", WHAL_NUM_11B_TARGET_POWER_RATES, EEP_DEC_VAL, {28, 28, 28, 28}},
};

// eeprom CAL target power 2G OFDM
static _EEPROM_ENTRY _eepromTargetPower2G[] = {
    {EEP_UINT8, "targetPower2G", WHAL_NUM_LEGACY_TARGET_POWER_RATES, EEP_DEC_VAL, {28, 28, 26, 26}},
};
    A_UINT8  tPow2xBase[WHAL_NUM_STREAMS];

// eeprom CAL target power 2G HT20 
static _EEPROM_ENTRY _eepromTargetPower2GVHT20[] = {
    {EEP_UINT8, "targetPower2GVHT20Base", WHAL_NUM_STREAMS, EEP_DEC_VAL, {20, 20, 20}},
    {EEP_UINT8, "targetPower2GVHT20Delta", WHAL_NUM_11G_20_TARGET_POWER_RATES_DIV2, EEP_HEX_VAL, {0x88, 0x44, 0x04, 0x00, 0x44, 0x00, 0x40, 0x04, 0x00}},
};

// eeprom CAL target power 2G HT40 
static _EEPROM_ENTRY _eepromTargetPower2GVHT40[] = {
    {EEP_UINT8, "targetPower2GVHT40Base", WHAL_NUM_STREAMS, EEP_DEC_VAL, {20, 20, 20}},
    {EEP_UINT8, "targetPower2GVHT40Delta", WHAL_NUM_11G_40_TARGET_POWER_RATES_DIV2, EEP_HEX_VAL, {0x88, 0x44, 0x04, 0x00, 0x44, 0x00, 0x40, 0x04, 0x00}},
};

// eeprom CTL Index 2G 
static _EEPROM_ENTRY _eepromCtlIndex2G[] = {
    {EEP_UINT8, "ctlIndex2G", WHAL_NUM_CTLS_2G, EEP_HEX_VAL, {0x11, 0x12, 0x15, 0x17, 0x0, 0x0, 0x41, 0x42, 0x45, 0x47, 0x0, 0x0, 0x31, 0x32, 0x35, 0x37, 0x0, 0x0}},
};

// eeprom CTL Freq 2G 
static _EEPROM_ENTRY _eepromCtlFreqbin2G[] = {
    {EEP_UINT8, "ctlFreqbin2G_0", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2457, 1), WHAL_FREQ2FBIN(2462, 1)}},
    {EEP_UINT8, "ctlFreqbin2G_1", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2462, 1), 0xFF}},
    {EEP_UINT8, "ctlFreqbin2G_2", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2462, 1), 0xFF}},
    {EEP_UINT8, "ctlFreqbin2G_3", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2422, 1), WHAL_FREQ2FBIN(2427, 1), WHAL_FREQ2FBIN(2447, 1), WHAL_FREQ2FBIN(2452, 1)}},
    {EEP_UINT8, "ctlFreqbin2G_4", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {0, 0, 0, 0}},
    {EEP_UINT8, "ctlFreqbin2G_5", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {0, 0, 0, 0}},
    {EEP_UINT8, "ctlFreqbin2G_6", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2472, 1), WHAL_FREQ2FBIN(2484, 1)}},
    {EEP_UINT8, "ctlFreqbin2G_7", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2472, 1), 0}},
    {EEP_UINT8, "ctlFreqbin2G_8", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2472, 1), 0}}, 
    {EEP_UINT8, "ctlFreqbin2G_9", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2422, 1), WHAL_FREQ2FBIN(2427, 1), WHAL_FREQ2FBIN(2447, 1), WHAL_FREQ2FBIN(2462, 1)}},
    {EEP_UINT8, "ctlFreqbin2G_10", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {0, 0, 0, 0}}, 
    {EEP_UINT8, "ctlFreqbin2G_11", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {0, 0, 0, 0}},
    {EEP_UINT8, "ctlFreqbin2G_12", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2472, 1), 0}}, 
    {EEP_UINT8, "ctlFreqbin2G_13", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2472, 1), 0}}, 
    {EEP_UINT8, "ctlFreqbin2G_14", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2472, 1), 0}},
    {EEP_UINT8, "ctlFreqbin2G_15", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2422, 1), WHAL_FREQ2FBIN(2427, 1), WHAL_FREQ2FBIN(2447, 1), WHAL_FREQ2FBIN(2462, 1)}},
    {EEP_UINT8, "ctlFreqbin2G_16", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {0, 0, 0, 0}},
    {EEP_UINT8, "ctlFreqbin2G_17", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {0, 0, 0, 0}},
};

// eeprom CTL data 2G 
static _EEPROM_ENTRY _eepromCtlData2G[] = {
    {EEP_UINT8, "ctlData2G_0", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 60, 60}},
    {EEP_UINT8, "ctlData2G_1", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 60, 60}}, 
    {EEP_UINT8, "ctlData2G_2", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {61, 60, 60, 61}},
    {EEP_UINT8, "ctlData2G_3", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {61, 60, 60, 60}},
    {EEP_UINT8, "ctlData2G_4", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {0, 0, 0, 0}},
    {EEP_UINT8, "ctlData2G_5", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {0, 0, 0, 0}},
    {EEP_UINT8, "ctlData2G_6", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 60, 60}},
    {EEP_UINT8, "ctlData2G_7", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 60, 60}},
    {EEP_UINT8, "ctlData2G_8", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 61, 60}},
    {EEP_UINT8, "ctlData2G_9", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 60, 60}},
    {EEP_UINT8, "ctlData2G_10", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {0, 0, 0, 0}},
    {EEP_UINT8, "ctlData2G_11", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {0, 0, 0, 0}},
    {EEP_UINT8, "ctlData2G_12", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 60, 60}},
    {EEP_UINT8, "ctlData2G_13", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 60, 60}},
    {EEP_UINT8, "ctlData2G_14", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 61, 61}},
    {EEP_UINT8, "ctlData2G_15", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 61, 61}},
    {EEP_UINT8, "ctlData2G_16", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {0, 0, 0, 0}},
    {EEP_UINT8, "ctlData2G_17", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {0, 0, 0, 0}},
};

// eeprom temp compensation 2G
static _EEPROM_ENTRY _eepromTempCompChansData2G[] = {
    {EEP_UINT8, "alphaThermTbl", QC98XX_NUM_ALPHATHERM_TEMPS, EEP_HEX_VAL, {0x25, 0x25, 0x25, 0x25}},
};

// ==========================================================
// ==========================================================

// eeprom CAL freq 5G
static _EEPROM_ENTRY _eepromCalFreq5G[] = {
    {EEP_UINT8, "calFreqPier5G", WHAL_NUM_11A_CAL_PIERS, EEP_DEC_VAL, {76, 88, 92, 104, 140, 160, 189, 205}},
};

// eeprom CAL data 5G
static _EEPROM_ENTRY _eepromCalData5G[] = {
    {EEP_INT8,  "dacGain", WHAL_NUM_CAL_GAINS, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "thermCalVal", 1, EEP_DEC_VAL, {129}}, 
    {EEP_UINT8, "voltCalVal", 1, EEP_DEC_VAL, {98}}, 
};

// eeprom CAL target power freq 5G OFDM
static _EEPROM_ENTRY _eepromTargetFreqbin5G[] = {
    {EEP_UINT8, "targetFreqbin5G", WHAL_NUM_11A_LEG_TARGET_POWER_CHANS, EEP_DEC_VAL, {76, 92, 104, 140, 180, 205}}, 
};

// eeprom CAL target power freq 5G HT20 
static _EEPROM_ENTRY _eepromTargetFreqbin5GVHT20[] = {
    {EEP_UINT8, "targetFreqbin5GVHT20", WHAL_NUM_11A_20_TARGET_POWER_CHANS, EEP_DEC_VAL, {76, 92, 104, 140, 180, 205}}, 
};

// eeprom CAL target power freq 5G HT40 
static _EEPROM_ENTRY _eepromTargetFreqbin5GVHT40[] = {
    {EEP_UINT8, "targetFreqbin5GVHT40", WHAL_NUM_11A_40_TARGET_POWER_CHANS, EEP_DEC_VAL, {76, 92, 104, 140, 180, 205}}, 
};

// eeprom CAL target power freq 5G HT80 
static _EEPROM_ENTRY _eepromTargetFreqbin5GVHT80[] = {
    {EEP_UINT8, "targetFreqbin5GVHT80", WHAL_NUM_11A_80_TARGET_POWER_CHANS, EEP_DEC_VAL, {76, 92, 104, 140, 180, 205}}, 
};

// eeprom CAL target power 5G OFDM
static _EEPROM_ENTRY _eepromTargetPower5G[] = {
    {EEP_UINT8, "targetPower5G", WHAL_NUM_LEGACY_TARGET_POWER_RATES, EEP_DEC_VAL, {28, 28, 28, 26}},
};

// eeprom CAL target power 5G HT20 
static _EEPROM_ENTRY _eepromTargetPower5GVHT20[] = {
    {EEP_UINT8, "targetPower5GVHT20Base", WHAL_NUM_STREAMS, EEP_DEC_VAL, {20, 20, 20}},
    {EEP_UINT8, "targetPower5GVHT20Delta", WHAL_NUM_11A_20_TARGET_POWER_RATES_DIV2, EEP_HEX_VAL, {0x88, 0x44, 0x04, 0x00, 0x44, 0x00, 0x40, 0x04, 0x00}},
};

// eeprom CAL target power 5G HT40 
static _EEPROM_ENTRY _eepromTargetPower5GVHT40[] = {
    {EEP_UINT8, "targetPower5GVHT40Base", WHAL_NUM_STREAMS, EEP_DEC_VAL, {20, 20, 20}},
    {EEP_UINT8, "targetPower5GVHT40Delta", WHAL_NUM_11A_40_TARGET_POWER_RATES_DIV2, EEP_HEX_VAL, {0x88, 0x44, 0x04, 0x00, 0x44, 0x00, 0x40, 0x04, 0x00}},
};

// eeprom CAL target power 5G HT80 
static _EEPROM_ENTRY _eepromTargetPower5GVHT80[] = {
    {EEP_UINT8, "targetPower5GVHT80Base", WHAL_NUM_STREAMS, EEP_DEC_VAL, {20, 20, 20}},
    {EEP_UINT8, "targetPower5GVHT80Delta", WHAL_NUM_11A_80_TARGET_POWER_RATES_DIV2, EEP_HEX_VAL, {0x88, 0x44, 0x04, 0x00, 0x44, 0x00, 0x40, 0x04, 0x00}},
};

// eeprom CTL Index 5G 
static _EEPROM_ENTRY _eepromCtlIndex5G[] = {
    {EEP_UINT8, "ctlIndex5G", WHAL_NUM_CTLS_5G, EEP_HEX_VAL, {0x10, 0x16, 0x18, 0x19, 0x0, 0x0, 0x40, 0x46, 0x48, 0x49, 0x0, 0x0, 0x30, 0x36, 0x38, 0x39, 0x0, 0x0}}, 
};

// eeprom CTL Freq 5G 
static _EEPROM_ENTRY _eepromCtlFreqbin5G[] = {
    {EEP_UINT8, "ctlFreqbin5G_0", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5180, 0), WHAL_FREQ2FBIN(5260, 0), WHAL_FREQ2FBIN(5280, 0), WHAL_FREQ2FBIN(5500, 0), WHAL_FREQ2FBIN(5600, 0), WHAL_FREQ2FBIN(5700, 0), WHAL_FREQ2FBIN(5745, 0), WHAL_FREQ2FBIN(5825, 0)}},
    {EEP_UINT8, "ctlFreqbin5G_1", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5180, 0), WHAL_FREQ2FBIN(5260, 0), WHAL_FREQ2FBIN(5280, 0), WHAL_FREQ2FBIN(5500, 0), WHAL_FREQ2FBIN(5520, 0), WHAL_FREQ2FBIN(5700, 0), WHAL_FREQ2FBIN(5745, 0), WHAL_FREQ2FBIN(5825, 0)}},
    {EEP_UINT8, "ctlFreqbin5G_2", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5190, 0), WHAL_FREQ2FBIN(5230, 0), WHAL_FREQ2FBIN(5270, 0), WHAL_FREQ2FBIN(5310, 0), WHAL_FREQ2FBIN(5510, 0), WHAL_FREQ2FBIN(5550, 0), WHAL_FREQ2FBIN(5670, 0), WHAL_FREQ2FBIN(5755, 0)}},
    {EEP_UINT8, "ctlFreqbin5G_3", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5210, 0), WHAL_FREQ2FBIN(5290, 0), WHAL_FREQ2FBIN(5530, 0), WHAL_FREQ2FBIN(5610, 0), WHAL_FREQ2FBIN(5690, 0), WHAL_FREQ2FBIN(5775, 0), 0xFF, 0xFF}},
    {EEP_UINT8, "ctlFreqbin5G_4", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {0, 0, 0, 0, 0, 0, 0, 0}},
    {EEP_UINT8, "ctlFreqbin5G_5", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {0, 0, 0, 0, 0, 0, 0, 0}},
    {EEP_UINT8, "ctlFreqbin5G_6", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5180, 0), WHAL_FREQ2FBIN(5200, 0), WHAL_FREQ2FBIN(5260, 0), WHAL_FREQ2FBIN(5320, 0), WHAL_FREQ2FBIN(5500, 0), WHAL_FREQ2FBIN(5700, 0), 0xFF, 0xFF}},
    {EEP_UINT8, "ctlFreqbin5G_7", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5180, 0), WHAL_FREQ2FBIN(5260, 0), WHAL_FREQ2FBIN(5500, 0), WHAL_FREQ2FBIN(5700, 0), 0xFF, 0xFF, 0xFF, 0xFF}},
    {EEP_UINT8, "ctlFreqbin5G_8", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5190, 0), WHAL_FREQ2FBIN(5270, 0), WHAL_FREQ2FBIN(5310, 0), WHAL_FREQ2FBIN(5510, 0), WHAL_FREQ2FBIN(5590, 0), WHAL_FREQ2FBIN(5670, 0), 0xFF, 0xFF}},
    {EEP_UINT8, "ctlFreqbin5G_9", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5210, 0), WHAL_FREQ2FBIN(5290, 0), WHAL_FREQ2FBIN(5530, 0), WHAL_FREQ2FBIN(5610, 0), WHAL_FREQ2FBIN(5690, 0), WHAL_FREQ2FBIN(5775, 0), 0xFF, 0xFF}},
    {EEP_UINT8, "ctlFreqbin5G_10", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {0, 0, 0, 0, 0, 0, 0, 0}},
    {EEP_UINT8, "ctlFreqbin5G_11", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {0, 0, 0, 0, 0, 0, 0, 0}},
    {EEP_UINT8, "ctlFreqbin5G_12", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5180, 0), WHAL_FREQ2FBIN(5200, 0), WHAL_FREQ2FBIN(5220, 0), WHAL_FREQ2FBIN(5260, 0), WHAL_FREQ2FBIN(5500, 0), WHAL_FREQ2FBIN(5600, 0), WHAL_FREQ2FBIN(5700, 0), WHAL_FREQ2FBIN(5745, 0)}},
    {EEP_UINT8, "ctlFreqbin5G_13", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5180, 0), WHAL_FREQ2FBIN(5260, 0), WHAL_FREQ2FBIN(5320, 0), WHAL_FREQ2FBIN(5500, 0), WHAL_FREQ2FBIN(5560, 0), WHAL_FREQ2FBIN(5700, 0), WHAL_FREQ2FBIN(5745, 0), WHAL_FREQ2FBIN(5825, 0)}},
    {EEP_UINT8, "ctlFreqbin5G_14", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5190, 0), WHAL_FREQ2FBIN(5230, 0), WHAL_FREQ2FBIN(5270, 0), WHAL_FREQ2FBIN(5510, 0), WHAL_FREQ2FBIN(5550, 0), WHAL_FREQ2FBIN(5670, 0), WHAL_FREQ2FBIN(5755, 0), WHAL_FREQ2FBIN(5795, 0)}},
    {EEP_UINT8, "ctlFreqbin5G_15", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5210, 0), WHAL_FREQ2FBIN(5290, 0), WHAL_FREQ2FBIN(5530, 0), WHAL_FREQ2FBIN(5610, 0), WHAL_FREQ2FBIN(5690, 0), WHAL_FREQ2FBIN(5775, 0), 0xFF, 0xFF}},
    {EEP_UINT8, "ctlFreqbin5G_16", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {0, 0, 0, 0, 0, 0, 0, 0}},
    {EEP_UINT8, "ctlFreqbin5G_17", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {0, 0, 0, 0, 0, 0, 0, 0}},
};

// eeprom CTL data 5G 
static _EEPROM_ENTRY _eepromCtlData5G[] = {
    {EEP_UINT8, "ctlData5G_0", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 61, 61, 61, 61, 61, 61, 60}},
    {EEP_UINT8, "ctlData5G_1", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 61, 61, 61, 61, 61, 61, 60}},
    {EEP_UINT8, "ctlData5G_2", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {60, 61, 60, 61, 61, 61, 61, 61}},
    {EEP_UINT8, "ctlData5G_3", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 61, 61, 61, 61, 61, 61, 60}},
    {EEP_UINT8, "ctlData5G_4", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {0, 0, 0, 0, 0, 0, 0, 0}},
    {EEP_UINT8, "ctlData5G_5", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {0, 0, 0, 0, 0, 0, 0, 0}},
    {EEP_UINT8, "ctlData5G_6", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {60, 61, 61, 60, 61, 60, 60, 60}},
    {EEP_UINT8, "ctlData5G_7", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 61, 61, 60, 60, 60, 60, 60}},
    {EEP_UINT8, "ctlData5G_8", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 61, 61, 61, 61, 60, 60, 60}},
    {EEP_UINT8, "ctlData5G_9", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 61, 61, 60, 60, 60, 60, 60}},
    {EEP_UINT8, "ctlData5G_10", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {0, 0, 0, 0, 0, 0, 0, 0}},
    {EEP_UINT8, "ctlData5G_11", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {0, 0, 0, 0, 0, 0, 0, 0}},
    {EEP_UINT8, "ctlData5G_12", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 61, 61, 61, 61, 61, 61, 61}},
    {EEP_UINT8, "ctlData5G_13", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 61, 60, 61, 61, 61, 61, 60}},
    {EEP_UINT8, "ctlData5G_14", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 60, 61, 61, 61, 61, 60, 61}},
    {EEP_UINT8, "ctlData5G_15", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 61, 60, 61, 61, 61, 61, 60}},
    {EEP_UINT8, "ctlData5G_16", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {0, 0, 0, 0, 0, 0, 0, 0}},
    {EEP_UINT8, "ctlData5G_17", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {0, 0, 0, 0, 0, 0, 0, 0}},
};


// eeprom temp compensation 5G
static _EEPROM_ENTRY _eepromTempCompChansData5G[] = {
    {EEP_UINT8, "alphaThermTbl", QC98XX_NUM_ALPHATHERM_TEMPS, EEP_HEX_VAL, {0x27, 0x26, 0x25, 0x24}},
};

// eeprom config
static _EEPROM_ENTRY _eepromConfigAddr[] = {
    {EEP_UINT32, "configAddr", QC98XX_CONFIG_ENTRIES, EEP_HEX_VAL, {0}},
};



// functions
static void addEepromDataHex(char *key, EEP_TYPE type, A_UINT32 size, EEP_TYPE_PRINT prt, A_INT32 *value, char (*bitFieldName)[MAX_NAME_SIZE], A_UINT32 arraySize); 
static void addEepromDataDec(char *key, EEP_TYPE type, A_UINT32 size, EEP_TYPE_PRINT prt, A_INT32 *value, char (*bitFieldName)[MAX_NAME_SIZE], A_UINT32 numCol); 
static FILE *fpTpl, *fpData;
#define addEepromTemplate(key, type, num, prt) \
    fprintf(fpTpl, "%s %d %d %d\n", key, type, num, prt) 
#define addEepromTemplateWithBitField(key, type, num, prt, bitfieldname,numofbits) \
    fprintf(fpTpl, "%s %d %d %d ", key, type, num, prt); \
    for (i=0;i<num;i++) { \
        fprintf(fpTpl, "%s:",bitfieldname[i]);\
        fprintf(fpTpl, "%d;",numofbits[i]);\
    } \
    fprintf(fpTpl,"\n");

typedef void (*_pAddEepromDataFunc)(char *key, EEP_TYPE type, A_UINT32 size, EEP_TYPE_PRINT prt, A_INT32 *value, char (*bitFieldName)[MAX_NAME_SIZE], A_UINT32 numCol);
static _pAddEepromDataFunc pAddEepromData[EEP_LAST_VAL +1] =
{
    addEepromDataHex,
    addEepromDataDec,
};

static void addEepromData(char *key, EEP_TYPE type, A_UINT32 size, char *prtStr, A_INT32 *value, char (*bitFieldName)[MAX_NAME_SIZE], A_UINT32 numCol) 
{
    A_UINT32 i;
    fprintf(fpData, "%s ", key);
    for (i=0;i<size/*numCol*/;i++) {
        if (type == EEP_BITFIELD) {
            fprintf(fpData, "%s:", bitFieldName[i]);
            fprintf(fpData, prtStr, value[i]);
            fprintf(fpData, " ");
        }
        else
            fprintf(fpData, prtStr, value[i]);
    }
    fprintf(fpData, "\n");
    return;
}


static void addEepromDataHex(char *key, EEP_TYPE type, A_UINT32 size, EEP_TYPE_PRINT prt, A_INT32 *value, char (*bitFieldName)[MAX_NAME_SIZE], A_UINT32 numCol) 
{
	if (type == EEP_BITFIELD)
	{
		addEepromData(key, type, size, "0x%x", value, bitFieldName, numCol);
	}
	else
	{
		addEepromData(key, type, size, " 0x%x", value, bitFieldName, numCol);
	}
}

static void addEepromDataDec(char *key, EEP_TYPE type, A_UINT32 size, EEP_TYPE_PRINT prt, A_INT32 *value, char (*bitFieldName)[MAX_NAME_SIZE], A_UINT32 numCol) 
{
    addEepromData(key, type, size, " %d", value, bitFieldName, numCol);
}

static void genEepromTemplateAndDefaultData(_EEPROM_ENTRY *tbl, A_UINT32 numEntries, char *band, A_UINT32 numRow1, A_UINT32 numRow2, A_UINT32 numCol)
{
    A_UINT32 r1, r2, e, i;
    char key[MAX_NAME_SIZE]; 
    for (r1=0;r1<numRow1;r1++) {
        for (r2=0;r2<numRow2;r2++) {
            for (e=0;e<numEntries;e++) {
                // add to template
                memset((void*)key, '0', sizeof(key));
                sprintf(key, "%s_%s_%d_%d", (tbl+e)->key, band, r1, r2);
                if ((tbl+e)->dataType == EEP_BITFIELD) {
                    addEepromTemplateWithBitField(key, (tbl+e)->dataType, (tbl+e)->size, (tbl+e)->prtType, (tbl+e)->bitFieldName, (tbl+e)->numBits);
                }
                else
                    addEepromTemplate(key, (tbl+e)->dataType, (tbl+e)->size, (tbl+e)->prtType);

                // add to data file
                (pAddEepromData[(tbl+e)->prtType])(key, (tbl+e)->dataType, (tbl+e)->size, (tbl+e)->prtType, (tbl+e)->value, (tbl+e)->bitFieldName, numCol);
            }
        }
    }
    return;
}

static void genEepromTemplateAndDefaultData_1(_EEPROM_ENTRY *tbl, A_UINT32 numEntries, char *band, A_UINT32 rowNum, A_UINT32 numRow2, A_UINT32 numCol)
{
    A_UINT32 r2, e, i;
    char key[MAX_NAME_SIZE]; 
    //for (r1=0;r1<numRow1;r1++) {
        for (r2=0;r2<numRow2;r2++) {
            for (e=0;e<numEntries;e++) {
                // add to template
                memset((void*)key, '0', sizeof(key));
                sprintf(key, "%s_%s_%d_%d", (tbl+e)->key, band, rowNum, r2);
                if ((tbl+e)->dataType == EEP_BITFIELD) {
                    addEepromTemplateWithBitField(key, (tbl+e)->dataType, (tbl+e)->size, (tbl+e)->prtType, (tbl+e)->bitFieldName, (tbl+e)->numBits);
                }
                else
                    addEepromTemplate(key, (tbl+e)->dataType, (tbl+e)->size, (tbl+e)->prtType);

                // add to data file
                (pAddEepromData[(tbl+e)->prtType])(key, (tbl+e)->dataType, (tbl+e)->size, (tbl+e)->prtType, (tbl+e)->value, (tbl+e)->bitFieldName, numCol);
            }
        }
    //}
    return;
}

// eeprom reserved data
#define MAX_VALUE_SIZE 1024
static A_INT32 ZeroValues[MAX_VALUE_SIZE] = {0};
static void addReservedData(char *key, A_UINT32 size)
{ 
    addEepromTemplate(key, EEP_UINT8, size, EEP_DEC_VAL);
    addEepromDataDec(key, EEP_UINT8, size, EEP_DEC_VAL, ZeroValues, NULL, 1); 
    return;
};


int main(int argc, char *argv[])
{
    char fileName[64];
	int i;

    sprintf(fileName, "eeprom_qc9k_%d.tpl", QC98XX_EEP_VER);
    if( (fpTpl = fopen(fileName, "w")) == NULL) {
        printf("Error: could not open template %s\n", fileName);
        return(-1);
    }
    
    sprintf(fileName, "eeprom_qc9k_dflt_%d.txt", QC98XX_EEP_VER);
    if( (fpData = fopen(fileName, "w")) == NULL) {
        printf("Error: could not open default data %s\n", fileName);
        return(-1);
    }
    
    // follow the flow of qc98xx_eeprom.h
//typedef struct qc98xxEeprom {
    //BASE_EEP_HEADER               baseEepHeader;   // 132B   
    printf("BASE_EEP_HEADER    baseEepHeader %d;\n", sizeof(_eepromBase));
    genEepromTemplateAndDefaultData(_eepromBase, sizeof(_eepromBase)/sizeof(_EEPROM_ENTRY), "", 1, 1, 1);

    //BIMODAL_EEP_HEADER            biModalHeader[WHAL_NUM_BI_MODAL];								// 144B 
    printf("BIMODAL_EEP_HEADER biModalHeader %d;\n", (sizeof(_eepromBiModal2G_1) + sizeof(_eepromSpurChans) + sizeof(_eepromBiModal2G_2) + sizeof(_eepromBiModal5G_1) + sizeof(_eepromSpurChans) + sizeof(_eepromBiModal5G_2)));

    genEepromTemplateAndDefaultData(_eepromBiModal5G_1, sizeof(_eepromBiModal5G_1)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);
    genEepromTemplateAndDefaultData(_eepromSpurChans, sizeof(_eepromSpurChans)/sizeof(_EEPROM_ENTRY), "A", QC98XX_EEPROM_MODAL_SPURS, 1, 1);
    genEepromTemplateAndDefaultData(_eepromBiModal5G_2, sizeof(_eepromBiModal5G_2)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);

    genEepromTemplateAndDefaultData(_eepromBiModal2G_1, sizeof(_eepromBiModal2G_1)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);
    genEepromTemplateAndDefaultData(_eepromSpurChans, sizeof(_eepromSpurChans)/sizeof(_EEPROM_ENTRY), "G", QC98XX_EEPROM_MODAL_SPURS, 1, 1);
    genEepromTemplateAndDefaultData(_eepromBiModal2G_2, sizeof(_eepromBiModal2G_2)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);

    //FREQ_MODAL_EEP_HEADER         freqModalHeader;                                              //  48B
    printf("FREQ_MODAL_EEP_HEADER    freqModalHeader %d;\n", (sizeof(_eepromFreqModal_1) + sizeof(_eepromFreqModal_2) + sizeof(_eepromFreqModal_3) + sizeof(_eepromFreqModal_4)));
    genEepromTemplateAndDefaultData(_eepromFreqModal_1, sizeof(_eepromFreqModal_1)/sizeof(_EEPROM_ENTRY), "", WHAL_NUM_CHAINS, 1, 1);
    genEepromTemplateAndDefaultData(_eepromFreqModal_2, sizeof(_eepromFreqModal_2)/sizeof(_EEPROM_ENTRY), "", WHAL_NUM_CHAINS, 1, 1);
    genEepromTemplateAndDefaultData(_eepromFreqModal_3, sizeof(_eepromFreqModal_3)/sizeof(_EEPROM_ENTRY), "", WHAL_NUM_CHAINS, 1, 1);
    genEepromTemplateAndDefaultData(_eepromFreqModal_4, sizeof(_eepromFreqModal_4)/sizeof(_EEPROM_ENTRY), "", WHAL_NUM_CHAINS*4, 1, 1);
	
    //CAL_DATA_PER_CHIP             chipCalData;                                                  //   4B
    printf("CAL_DATA_PER_CHIP    chipCalData %d;\n", sizeof(_eepromChipCalData));
    genEepromTemplateAndDefaultData(_eepromChipCalData, sizeof(_eepromChipCalData)/sizeof(_EEPROM_ENTRY), "", 1, 1, 1);
	
    // 2G
    //A_UINT8                       calFreqPier2G[WHAL_NUM_11G_CAL_PIERS];						//   3B
    printf("A_UINT8   calFreqPier2G[WHAL_NUM_11G_CAL_PIERS] %d;\n", sizeof(_eepromCalFreq2G));
    genEepromTemplateAndDefaultData(_eepromCalFreq2G, sizeof(_eepromCalFreq2G)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);   // 3B
	
    //A_UINT8                       pad0[1];   
    printf("A_UINT8   pad0[1] %d;\n", 1);
    addReservedData("pad0", 1);
	
    //CAL_DATA_PER_FREQ_OLPC        calPierData2G[WHAL_NUM_11G_CAL_PIERS];						//  78B   
    printf("CAL_DATA_PER_FREQ_OLPC    calPierData2G[WHAL_NUM_11G_CAL_PIERS] %d;\n", (WHAL_NUM_11G_CAL_PIERS * (sizeof(_eepromCalPerPoint) + sizeof(_eepromCalData2G))));
    for (i = 0; i < WHAL_NUM_11G_CAL_PIERS; ++i)
    {
        genEepromTemplateAndDefaultData_1(_eepromCalPerPoint, sizeof(_eepromCalPerPoint)/sizeof(_EEPROM_ENTRY), "G", i, WHAL_NUM_CHAINS, 1);
        genEepromTemplateAndDefaultData_1(_eepromCalData2G, sizeof(_eepromCalData2G)/sizeof(_EEPROM_ENTRY), "G", i, 1, 1);   //  16B
    }
	
    //A_UINT8                       pad1[46];                                                     //  46B 
    printf("A_UINT8    pad1[46] %d;\n", 46);
    addReservedData("pad1", 46);

    //A_UINT8                       extTPow2xDelta2G[QC98XX_EXT_TARGET_POWER_SIZE_2G];	    	//   16B
    printf("A_UINT8    extTPow2xDelta2G[QC98XX_EXT_TARGET_POWER_SIZE_2G] %d;\n", QC98XX_EXT_TARGET_POWER_SIZE_2G);
    addReservedData("extTPow2xDelta2G", QC98XX_EXT_TARGET_POWER_SIZE_2G);

    //A_UINT8                       targetFreqbinCck[WHAL_NUM_11B_TARGET_POWER_CHANS];			//   2B
    printf("A_UINT8    targetFreqbinCck[WHAL_NUM_11B_TARGET_POWER_CHANS];\n", sizeof(_eepromTargetFreqbinCck));
    genEepromTemplateAndDefaultData(_eepromTargetFreqbinCck, sizeof(_eepromTargetFreqbinCck)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1); 
    
    //A_UINT8                       targetFreqbin2G[WHAL_NUM_11G_LEG_TARGET_POWER_CHANS];         //   3B
    printf("A_UINT8    targetFreqbin2G[WHAL_NUM_11G_LEG_TARGET_POWER_CHANS];\n", sizeof(_eepromTargetFreqbin2G));
    genEepromTemplateAndDefaultData(_eepromTargetFreqbin2G, sizeof(_eepromTargetFreqbin2G)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);  
    
    // A_UINT8                       pad11[1];
    printf("A_UINT8    pad11[1]\n", 1);
    addReservedData("pad11", 1);

    //A_UINT8                       targetFreqbin2GVHT20[WHAL_NUM_11G_20_TARGET_POWER_CHANS];     //   3B
    printf("A_UINT8    targetFreqbin2GVHT20[WHAL_NUM_11G_20_TARGET_POWER_CHANS];\n", sizeof(_eepromTargetFreqbin2GVHT20));
    genEepromTemplateAndDefaultData(_eepromTargetFreqbin2GVHT20, sizeof(_eepromTargetFreqbin2GVHT20)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);
    
    //A_UINT8                       pad12[1];
    printf("A_UINT8    pad12[1]\n", 1);
    addReservedData("pad12", 1);

    //A_UINT8                       targetFreqbin2GVHT40[WHAL_NUM_11G_40_TARGET_POWER_CHANS];     //   3B
    printf("A_UINT8    targetFreqbin2GVHT40[WHAL_NUM_11G_40_TARGET_POWER_CHANS];\n", sizeof(_eepromTargetFreqbin2GVHT40));
    genEepromTemplateAndDefaultData(_eepromTargetFreqbin2GVHT40, sizeof(_eepromTargetFreqbin2GVHT40)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);
   
    //A_UINT8                       pad2[1];  //   1B
    printf("A_UINT8    pad2[1];\n", 1);
    addReservedData("pad2", 1);

    //CAL_TARGET_POWER_11B          targetPowerCck[WHAL_NUM_11B_TARGET_POWER_CHANS];              //   8B
    printf("CAL_TARGET_POWER_11B    targetPowerCck[WHAL_NUM_11B_TARGET_POWER_CHANS];\n", sizeof(_eepromTargetPowerCCK));
    genEepromTemplateAndDefaultData(_eepromTargetPowerCCK, sizeof(_eepromTargetPowerCCK)/sizeof(_EEPROM_ENTRY), "G", WHAL_NUM_11B_TARGET_POWER_CHANS, 1, 1);                 
    
    //CAL_TARGET_POWER_LEG          targetPower2G[WHAL_NUM_11G_LEG_TARGET_POWER_CHANS];           //  12B
    printf("CAL_TARGET_POWER_LEG    targetPower2G[WHAL_NUM_11G_LEG_TARGET_POWER_CHANS];\n", sizeof(_eepromTargetPower2G));
    genEepromTemplateAndDefaultData(_eepromTargetPower2G, sizeof(_eepromTargetPower2G)/sizeof(_EEPROM_ENTRY), "G", WHAL_NUM_11G_LEG_TARGET_POWER_CHANS, 1, 1);              
    
    //CAL_TARGET_POWER_11G_20       targetPower2GVHT20[WHAL_NUM_11G_20_TARGET_POWER_CHANS];       //  36B
    printf("CAL_TARGET_POWER_11G_20   targetPower2GVHT20[WHAL_NUM_11G_20_TARGET_POWER_CHANS];\n", sizeof(_eepromTargetPower2GVHT20));
    genEepromTemplateAndDefaultData(_eepromTargetPower2GVHT20, sizeof(_eepromTargetPower2GVHT20)/sizeof(_EEPROM_ENTRY), "G", WHAL_NUM_11G_20_TARGET_POWER_CHANS, 1, 1);                     
    
    //CAL_TARGET_POWER_11G_40       targetPower2GVHT40[WHAL_NUM_11G_40_TARGET_POWER_CHANS];      //   36B
    printf("CAL_TARGET_POWER_11G_40    targetPower2GVHT40[WHAL_NUM_11G_40_TARGET_POWER_CHANS];\n", sizeof(_eepromTargetPower2GVHT40));
    genEepromTemplateAndDefaultData(_eepromTargetPower2GVHT40, sizeof(_eepromTargetPower2GVHT40)/sizeof(_EEPROM_ENTRY), "G", WHAL_NUM_11G_40_TARGET_POWER_CHANS, 1, 1);                      

    //A_UINT8                       ctlIndex2G[WHAL_NUM_CTLS_2G];             //  18B
    printf("A_UINT8   ctlIndex2G[WHAL_NUM_CTLS_2G];\n", sizeof(_eepromCtlIndex2G));
    genEepromTemplateAndDefaultData(_eepromCtlIndex2G, sizeof(_eepromCtlIndex2G)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1); 
    
    //A_UINT8						  ctl2GFuture[2];							//   2B
    printf("A_UINT8    ctl2GFuture[2];\n", 1);
    addReservedData("ctl2GFuture", 2);

	//A_UINT8                       ctlFreqbin2G[WHAL_NUM_CTLS_2G][WHAL_NUM_BAND_EDGES_2G];		//  72B
    printf("A_UINT8   ctlFreqbin2G[WHAL_NUM_CTLS_2G][WHAL_NUM_BAND_EDGES_2G] %d\n", sizeof(_eepromCtlFreqbin2G));
    genEepromTemplateAndDefaultData(_eepromCtlFreqbin2G, sizeof(_eepromCtlFreqbin2G)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);
    
	//CAL_CTL_DATA_2G               ctlData2G[WHAL_NUM_CTLS_2G];    //  72B  
    printf("CAL_CTL_DATA_2G   ctlData2G[WHAL_NUM_CTLS_2G] %d;\n", sizeof(_eepromCtlData2G));
    genEepromTemplateAndDefaultData(_eepromCtlData2G, sizeof(_eepromCtlData2G)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);
                                                                                               
    //A_UINT8						  ctl2GFuture1[40];							//  40B
    printf("A_UINT8    ctl2GFuture1[40] %d;\n", 40);
    addReservedData("ctl2GFuture1", 40);

    //TEMP_COMP_TBL_2G              tempComp2G;     //  48B   
    printf("TEMP_COMP_TBL_2G   tempComp2G %d;\n", sizeof(_eepromTempCompChansData2G));
    genEepromTemplateAndDefaultData(_eepromTempCompChansData2G, sizeof(_eepromTempCompChansData2G)/sizeof(_EEPROM_ENTRY), "G", WHAL_NUM_CHAINS, QC98XX_NUM_ALPHATHERM_CHANS_2G, 1);                      //  32B

    //A_UINT8                       pad21[2];
    printf("A_UINT8   pad21[2] %d;\n", 2);
    addReservedData("pad21", 2);

    // 5G
    //A_UINT8                       calFreqPier5G[WHAL_NUM_11A_CAL_PIERS];						//   8B
    printf("A_UINT8   calFreqPier5G[WHAL_NUM_11A_CAL_PIERS] %d;\n", sizeof(_eepromCalFreq5G));
    genEepromTemplateAndDefaultData(_eepromCalFreq5G, sizeof(_eepromCalFreq5G)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1); 
    
    //CAL_DATA_PER_FREQ_OLPC        calPierData5G[WHAL_NUM_11A_CAL_PIERS];						// 176B
    printf("CAL_DATA_PER_FREQ_OLPC   calPierData5G[WHAL_NUM_11A_CAL_PIERS] %d;\n", (WHAL_NUM_11A_CAL_PIERS * (sizeof(_eepromCalData5G) + sizeof(_eepromCalPerPoint))));
    for (i = 0; i < WHAL_NUM_11A_CAL_PIERS; ++i) {
        genEepromTemplateAndDefaultData_1(_eepromCalPerPoint, sizeof(_eepromCalPerPoint)/sizeof(_EEPROM_ENTRY), "A", i, WHAL_NUM_CHAINS, 1);
        genEepromTemplateAndDefaultData_1(_eepromCalData5G, sizeof(_eepromCalData5G)/sizeof(_EEPROM_ENTRY), "A", i, 1, 1);
    }

    //A_UINT8                       pad3[20];
    printf("A_UINT8    pad3[20] %d;\n", 20);
    addReservedData("pad3", 20);
    
    //A_UINT8                       extTPow2xDelta5G[QC98XX_EXT_TARGET_POWER_SIZE_5G];	    	//   44B
    printf("A_UINT8    extTPow2xDelta5G[QC98XX_EXT_TARGET_POWER_SIZE_5G] %d;\n", QC98XX_EXT_TARGET_POWER_SIZE_5G);
    addReservedData("extTPow2xDelta5G", QC98XX_EXT_TARGET_POWER_SIZE_5G);
  
    //A_UINT8                       targetFreqbin5G[WHAL_NUM_11A_LEG_TARGET_POWER_CHANS];			//   6B
    printf("A_UINT8   targetFreqbin5G[WHAL_NUM_11A_LEG_TARGET_POWER_CHANS] %d;\n", sizeof(_eepromTargetFreqbin5G));
    genEepromTemplateAndDefaultData(_eepromTargetFreqbin5G, sizeof(_eepromTargetFreqbin5G)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);
    
    //A_UINT8                       targetFreqbin5GVHT20[WHAL_NUM_11A_20_TARGET_POWER_CHANS];		//   6B
    printf("A_UINT8   targetFreqbin5GVHT20[WHAL_NUM_11A_20_TARGET_POWER_CHANS] %d;\n", sizeof(_eepromTargetFreqbin5GVHT20));
    genEepromTemplateAndDefaultData(_eepromTargetFreqbin5GVHT20, sizeof(_eepromTargetFreqbin5GVHT20)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);
    
    //A_UINT8                       targetFreqbin5GVHT40[WHAL_NUM_11A_40_TARGET_POWER_CHANS];		//   6B
    printf("A_UINT8   targetFreqbin5GVHT40[WHAL_NUM_11A_40_TARGET_POWER_CHANS];\n", sizeof(_eepromTargetFreqbin5GVHT40));
    genEepromTemplateAndDefaultData(_eepromTargetFreqbin5GVHT40, sizeof(_eepromTargetFreqbin5GVHT40)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);
    
    //A_UINT8                       targetFreqbin5GVHT80[WHAL_NUM_11A_80_TARGET_POWER_CHANS];		//   6B
    printf("A_UINT8   targetFreqbin5GVHT80[WHAL_NUM_11A_80_TARGET_POWER_CHANS];\n", sizeof(_eepromTargetFreqbin5GVHT80));
    genEepromTemplateAndDefaultData(_eepromTargetFreqbin5GVHT80, sizeof(_eepromTargetFreqbin5GVHT80)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);
    
    //CAL_TARGET_POWER_LEG		  targetPower5G[WHAL_NUM_11A_LEG_TARGET_POWER_CHANS];			//  24B
    printf("CAL_TARGET_POWER_LEG    targetPower5G[WHAL_NUM_11A_LEG_TARGET_POWER_CHANS] %d;\n", sizeof(_eepromTargetPower5G));
    genEepromTemplateAndDefaultData(_eepromTargetPower5G, sizeof(_eepromTargetPower5G)/sizeof(_EEPROM_ENTRY), "A", WHAL_NUM_11A_LEG_TARGET_POWER_CHANS, 1, 1);                      
    
    //CAL_TARGET_POWER_11A_20		  targetPower5GVHT20[WHAL_NUM_11A_20_TARGET_POWER_CHANS];		//  72B
    printf("CAL_TARGET_POWER_11A_20    targetPower5GVHT20[WHAL_NUM_11A_20_TARGET_POWER_CHANS] %d;\n", sizeof(_eepromTargetPower5GVHT20));
    genEepromTemplateAndDefaultData(_eepromTargetPower5GVHT20, sizeof(_eepromTargetPower5GVHT20)/sizeof(_EEPROM_ENTRY), "A", WHAL_NUM_11A_20_TARGET_POWER_CHANS, 1, 1);                      //  16B
    
    //CAL_TARGET_POWER_11A_40		  targetPower5GVHT40[WHAL_NUM_11A_40_TARGET_POWER_CHANS];		//  72B
    printf("CAL_TARGET_POWER_11A_40    targetPower5GVHT40[WHAL_NUM_11A_40_TARGET_POWER_CHANS] %d;\n", sizeof(_eepromTargetPower5GVHT40));
    genEepromTemplateAndDefaultData(_eepromTargetPower5GVHT40, sizeof(_eepromTargetPower5GVHT40)/sizeof(_EEPROM_ENTRY), "A", WHAL_NUM_11A_40_TARGET_POWER_CHANS, 1, 1);                      //  16B
    
    //CAL_TARGET_POWER_11A_80		  targetPower5GVHT80[WHAL_NUM_11A_80_TARGET_POWER_CHANS];		//  72B
    printf("CAL_TARGET_POWER_11A_80    targetPower5GVHT80[WHAL_NUM_11A_80_TARGET_POWER_CHANS] %d;\n", sizeof(_eepromTargetPower5GVHT80));
    genEepromTemplateAndDefaultData(_eepromTargetPower5GVHT80, sizeof(_eepromTargetPower5GVHT80)/sizeof(_EEPROM_ENTRY), "A", WHAL_NUM_11A_80_TARGET_POWER_CHANS, 1, 1);                      //  16B

    //A_UINT8                       ctlIndex5G[WHAL_NUM_CTLS_5G];    //   18B
    printf("A_UINT8    ctlIndex5G[WHAL_NUM_CTLS_5G] %d;\n", sizeof(_eepromCtlIndex5G));
    genEepromTemplateAndDefaultData(_eepromCtlIndex5G, sizeof(_eepromCtlIndex5G)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);
    
    //A_UINT8                       ctl5GFuture[2];    //   2B  
    printf("A_UINT8    ctl5GFuture[2] %d;\n", 2);
    addReservedData("ctl5GFuture", 2);
    
    //A_UINT8                       ctlFreqbin5G[WHAL_NUM_CTLS_5G][WHAL_NUM_BAND_EDGES_5G];		//  144B
    printf("A_UINT8    ctlFreqbin5G[WHAL_NUM_CTLS_5G][WHAL_NUM_BAND_EDGES_5G] %d;\n", sizeof(_eepromCtlFreqbin5G));
    genEepromTemplateAndDefaultData(_eepromCtlFreqbin5G, sizeof(_eepromCtlFreqbin5G)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);

    //CAL_CTL_DATA_5G               ctlData5G[WHAL_NUM_CTLS_5G];    //  144B
    printf("CAL_CTL_DATA_5G    ctlData5G[WHAL_NUM_CTLS_5G] %d;\n", sizeof(_eepromCtlData5G));
    genEepromTemplateAndDefaultData(_eepromCtlData5G, sizeof(_eepromCtlData5G)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);  
    
    //A_UINT8                       ctl5GFuture1[64];    //   64B  
    printf("A_UINT8    ctl5GFuture1[64] %d;\n", 64);
    addReservedData("ctl5GFuture1",64);
    
    //TEMP_COMP_TBL_5G			  tempComp5G;    //  96B  
    printf("TEMP_COMP_TBL_5G    tempComp5G %d;\n", sizeof(_eepromTempCompChansData5G));
    genEepromTemplateAndDefaultData(_eepromTempCompChansData5G, sizeof(_eepromTempCompChansData5G)/sizeof(_EEPROM_ENTRY), "A", WHAL_NUM_CHAINS, QC98XX_NUM_ALPHATHERM_CHANS_5G, 1);                     

    // Config section (sticky writes)
    //A_UINT32					  configAddr[QC98XX_CONFIG_ENTRIES];		// 96B
    printf("A_UINT32    configAddr[QC98XX_CONFIG_ENTRIES] %d;\n", sizeof(_eepromConfigAddr));
    genEepromTemplateAndDefaultData(_eepromConfigAddr, sizeof(_eepromConfigAddr)/sizeof(_EEPROM_ENTRY), "", 1, 1, 1);                     
    																							
//} __ATTRIB_PACK QC98XX_EEPROM;    // 264 + 344 + 804 + 96 = 1532B

    return 0;
}


