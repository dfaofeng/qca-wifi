//-----------------------------------------------------------------------------

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "wlantype.h"
#include "dk_ver.h"
#include "ar6004_eeprom.h"

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
    {EEP_UINT32, "length", 1, EEP_DEC_VAL, {sizeof(AR6000_EEPROM)}},
    {EEP_UINT16, "checksum", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "eeprom_version", 1, EEP_HEX_VAL, {AR6004_EEP_VER}},
    {EEP_UINT8, "template_version", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "mac_addr", 6, EEP_HEX_VAL, {0x0, 0x3, 0x7, 0x12, 0x34, 0x56}},
    {EEP_UINT8, "bdAddr", 6, EEP_HEX_VAL, {0x0, 0x3, 0x7, 0x12, 0x34, 0x56}},
    {EEP_UINT16, "regDmn", 2, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT32, "opFlags", 1, EEP_HEX_VAL, {0x3}},
    {EEP_UINT32, "boardFlags", 1, EEP_HEX_VAL, {0xc44}},
    {EEP_UINT32, "eepMisc", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT16, "subSystemId", 1, EEP_HEX_VAL, {0x6401}},
    {EEP_UINT16, "binBuildNumber", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "txrxMask", 1, EEP_HEX_VAL, {0x33}},
    {EEP_UINT8, "rfSilent", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "blueToothOptions", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "deviceCap", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "deviceType", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "featureEnable", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "miscConfiguration", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "eepromWriteEnableGpio", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "wlanDisableGpio", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "wlanLedGpio", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "rxBandSelectGpio", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "xlnaSelectGpio", 4, EEP_DEC_VAL, {40,41,42,43}},
    {EEP_UINT8, "ctlVersion", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "custData", CUSTOMER_DATA_SIZE, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "spurBaseA", 1, EEP_DEC_VAL, {0x0}},
    {EEP_UINT8, "spurBaseB", 1, EEP_DEC_VAL, {0x0}},
    {EEP_UINT8, "spurRssiThresh", 1, EEP_DEC_VAL, {0x0}},
    {EEP_UINT8, "spurRssiThreshCck", 1, EEP_DEC_VAL, {0x0}},
    {EEP_UINT8, "spurMitFlag", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "MitAct2Rcv", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT16,"mitModeMiscFlags", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "diffPwrMit", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8, "mit_tx_gain_table_max", 1, EEP_DEC_VAL, {30}},
    {EEP_UINT16, "mit_ob_db", 1, EEP_HEX_VAL, {0x5cdb}},
    {EEP_UINT16, "chan_num_mask_mit", 1, EEP_HEX_VAL, {0x0}},
    {EEP_BITFIELD, "cpuClockSelect", 3, EEP_HEX_VAL, {0x0,0x0,0x0}, {"ClockSource","Enable","reserved"},{0x3,0x1,0x4}},
    {EEP_UINT8, "baseFuture", 5, EEP_HEX_VAL, {0x00}},
};

// common eeprom 
static _EEPROM_ENTRY _eepromCommon[] = {
    {EEP_BITFIELD, "swreg", 3, EEP_HEX_VAL, {0x0,0x0,0x0}, {"pwd","nfdiv","level"},{0x1,0x3,0x4}},
    {EEP_UINT8, "pareg", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "commonReserved", 2, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8, "txrxgain", 1, EEP_HEX_VAL, {0x1}},
    {EEP_INT8, "ant_div_control", 1, EEP_HEX_VAL, {0x0}},
    {EEP_INT8, "quick_drop_low", 1, EEP_HEX_VAL, {0x0}},
    {EEP_INT8, "quick_drop_high", 1, EEP_HEX_VAL, {0x0}},
    {EEP_INT8, "temp_slope_low", 1, EEP_HEX_VAL, {0x0}},
    {EEP_INT8, "temp_slope_high", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8, "xatten1_db_low", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8, "xatten1_margin_low", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8, "xatten1_db_high", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8, "xatten1_margin_high", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_INT8, "cckOfdmDelta", 1, EEP_HEX_VAL, {0x0}},
    {EEP_INT8, "pwrTableOffset", 1, EEP_HEX_VAL, {0x0}},
    {EEP_INT8, "params_for_tuning_caps", 2, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8, "commonFuture", 10, EEP_HEX_VAL, {0x0, 0x0}},
};

// eeprom chip data 
static _EEPROM_ENTRY _eepromChipCalData[] = {
    {EEP_INT16, "thermAdcScaledGain", 1, EEP_DEC_VAL, {205}},
    {EEP_INT8,  "thermAdcOffset", 1, EEP_DEC_VAL, {0}},
    {EEP_INT8,  "xtalCapOutDac", 1, EEP_HEX_VAL, {0x40}},
    {EEP_INT8,  "xtalCapInDac", 1, EEP_HEX_VAL, {0x40}},
    {EEP_UINT8, "chipCALReserved", 3, EEP_HEX_VAL, {0x0, 0x0}},
};

// eeprom modal 2G
static _EEPROM_ENTRY _eepromModal2G_1[] = {
    {EEP_UINT32, "antCtrlCommon", 1, EEP_HEX_VAL, {0x90229}},
    {EEP_UINT32, "antCtrlCommon2", 1, EEP_HEX_VAL, {0x99999}},
    {EEP_UINT16, "antCtrlChain", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x150, 0x150}},
    {EEP_INT8,   "tempSlope", WHAL_NUM_CHAINS, EEP_DEC_VAL, {36,36}},
    {EEP_INT8,   "voltSlope", WHAL_NUM_CHAINS, EEP_DEC_VAL, {0,0}},
};

static _EEPROM_ENTRY _eepromSpurChans[] = {
    {EEP_UINT8,  "spurChans", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "spurABChoose", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "spurA_PrimSecChoose", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "spurB_PrimSecChoose", 1, EEP_HEX_VAL, {0x0}},
};

static _EEPROM_ENTRY _eepromModal2G_2[] = {
    {EEP_INT8,   "noiseFloorThreshCh", WHAL_NUM_CHAINS, EEP_DEC_VAL, {-1, 0}},
    {EEP_UINT16, "ob_db", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x5cdb, 0x5cdb}},
    {EEP_UINT8,  "xpaBiasLvl", 1, EEP_HEX_VAL, {0xa}},
    {EEP_UINT32, "papdRateMaskHt20", 1, EEP_HEX_VAL, {0x0c80C080}},
    {EEP_UINT32, "papdRateMaskHt40", 1, EEP_HEX_VAL, {0x0080C080}},
    {EEP_UINT8,  "paprdQuickDrop", 1, EEP_HEX_VAL, {0x3a}},
    {EEP_UINT8,  "txFrameToDataStart", 1, EEP_HEX_VAL, {0xe}},
    {EEP_UINT8,  "txFrameToPaOn", 1, EEP_HEX_VAL, {0xe}},  
    {EEP_UINT8,  "txClip", 1, EEP_DEC_VAL, {3}},
    {EEP_UINT8,  "switchSettling", 1, EEP_HEX_VAL, {0x2d}},
    {EEP_UINT8,  "swSettleHt40", 1, EEP_HEX_VAL, {0x2d}},
    {EEP_INT8,   "adcDesiredSize", 1, EEP_DEC_VAL, {-45}},
    {EEP_UINT8,  "txEndToXpaOff", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "txEndToRxOn", 1, EEP_HEX_VAL, {0x2}},
    {EEP_UINT8,  "txFrameToXpaOn", 1, EEP_HEX_VAL, {0xe}},
    {EEP_UINT8,  "thresh62", 1, EEP_HEX_VAL, {0x21}},
    {EEP_INT8,   "antennaGainCh", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}}, 
    {EEP_UINT8,  "xatten1Hyst", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x20, 0x20}},
    {EEP_UINT8,  "xatten1DB", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "xatten1Margin", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "xatten2Db", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x19, 0x19}},
    {EEP_UINT8,  "xatten2Margin", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "xatten2Hyst", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "xatten1HystHT40", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x20, 0x20}},
    {EEP_UINT8,  "xatten1DBHT40", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "xatten1MarginHT40", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "xatten2DbHT40", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x19, 0x19}},
    {EEP_UINT8,  "xatten2MarginHT40", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "xatten2HystHT40", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_INT8,   "rxIqCalICh", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_INT8,   "rxIqCalQCh", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "ht40PowerInc", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "enableXpaBias", 1, EEP_DEC_VAL, {0}},
    {EEP_INT8,   "adcDesiredSizeHT40", 1, EEP_HEX_VAL, {0xd8}},
    {EEP_INT8,   "txGainOffset", 1, EEP_DEC_VAL, {0}},
    {EEP_INT8,   "paprdOffset",  1, EEP_DEC_VAL, {0}},
    {EEP_UINT8,  "enableXpa", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8,  "xlnaGainDb", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}}, 
    {EEP_UINT8,  "futureModal", 31, EEP_HEX_VAL, {0x00}},
    {EEP_UINT8,  "futureModalDataExt", 128, EEP_HEX_VAL, {0x00}},
};

// eeprom CAL freq 2G
static _EEPROM_ENTRY _eepromCalFreq2G[] = {
    {EEP_UINT8, "calFreqPier2G", WHAL_NUM_11G_CAL_PIERS, EEP_DEC_VAL, {112, 142, 172, 255, 255, 255, 255, 255, 255, 255, 255, 255}},
};

// eeprom CAL data 2G
static _EEPROM_ENTRY _eepromCalData2G[] = {
    {EEP_INT8, "refPower", 1, EEP_DEC_VAL, {1}},
    {EEP_INT8, "rxNoisefloorCal", 1, EEP_DEC_VAL, {0}},
    {EEP_INT8, "rxNoisefloorPower", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8, "rxTempMeas", 1, EEP_DEC_VAL, {0}},
    {EEP_INT16, "olpcGainDelta_t10", 1, EEP_DEC_VAL, {-100, 0}},
    {EEP_UINT8, "thermCalVal", 1, EEP_DEC_VAL, {121, 0}}, 
    {EEP_UINT8, "voltCalVal", 1, EEP_DEC_VAL, {100, 0}}, 
    {EEP_UINT8, "desiredScaleCck", 1, EEP_DEC_VAL, {14, 0}}, 
    {EEP_UINT8, "desiredScalePSKLeg_t10", 1, EEP_DEC_VAL, {69, 0}}, 
    {EEP_UINT8, "desiredScaleQAM16Leg_t10", 1, EEP_DEC_VAL, {72, 0}}, 
    {EEP_UINT8, "desiredScaleQAM64Leg_t10", 1, EEP_DEC_VAL, {73, 0}}, 
    {EEP_UINT8, "desiredScalePSKHT20_t10", 1, EEP_DEC_VAL, {71, 0}}, 
    {EEP_UINT8, "desiredScaleQAM16HT20_t10", 1, EEP_DEC_VAL, {75, 0}}, 
    {EEP_UINT8, "desiredScaleQAM64HT20_t10", 1, EEP_DEC_VAL, {65, 0}}, 
    {EEP_UINT8, "desiredScalePSKHT40_t10", 1, EEP_DEC_VAL, {80, 0}}, 
    {EEP_UINT8, "desiredScaleQAM16HT40_t10", 1, EEP_DEC_VAL, {75, 0}}, 
    {EEP_UINT8, "desiredScaleQAM64HT40_t10", 1, EEP_DEC_VAL, {65, 0}}, 
};

// eeprom CAL target power freq 2G CCK
static _EEPROM_ENTRY _eepromCalTargetFreqbinCck[] = {
    {EEP_UINT8, "calTargetFreqbinCck", WHAL_NUM_11B_TARGET_POWERS, EEP_DEC_VAL, {112, 117, 122, 127, 132, 137, 142, 147, 152, 157, 162, 167, 172, 184, 255, 255}}, 
};

// eeprom CAL target power freq 2G OFDM
static _EEPROM_ENTRY _eepromCalTargetFreqbin2G[] = {
//    {EEP_UINT8, "calTargetFreqbin2G", WHAL_NUM_11G_20_TARGET_POWERS, EEP_DEC_VAL, {112, 117, 122, 127, 132, 137, 142, 147, 152, 157, 162, 167, 172, 184, 255, 255}}, 
//};
    {EEP_UINT8, "calTargetFreqbin2G", WHAL_NUM_11G_20_TARGET_POWERS, EEP_DEC_VAL, {112, 142, 172, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255}}, 
};

// eeprom CAL target power freq 2G HT20 
static _EEPROM_ENTRY _eepromCalTargetFreqbin2GHT20[] = {
    {EEP_UINT8, "calTargetFreqbin2GHT20", WHAL_NUM_11G_20_TARGET_POWERS, EEP_DEC_VAL, {112, 142, 172, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255}}, 
};

// eeprom CAL target power freq 2G HT40 
static _EEPROM_ENTRY _eepromCalTargetFreqbin2GHT40[] = {
    {EEP_UINT8, "calTargetFreqbin2GHT40", WHAL_NUM_11G_20_TARGET_POWERS, EEP_DEC_VAL, {112, 117, 122, 127, 132, 137, 142, 147, 152, 157, 162, 167, 172, 184, 255, 255}}, 
};

// eeprom CAL target power 2G CCK
static _EEPROM_ENTRY _eepromCalTargetPowerCCK[] = {
    {EEP_UINT8, "calTargetPowerCck", WHAL_NUM_LEGACY_TARGET_POWER_RATES, EEP_DEC_VAL, {28, 28, 28, 28, 0}},
};

// eeprom CAL target power 2G OFDM
static _EEPROM_ENTRY _eepromCalTargetPower2G[] = {
    {EEP_UINT8, "calTargetPower2G", WHAL_NUM_LEGACY_TARGET_POWER_RATES, EEP_DEC_VAL, {28, 28, 26, 26, 0}},
};

// eeprom CAL target power 2G HT20 
static _EEPROM_ENTRY _eepromCalTargetPower2GHT20[] = {
    {EEP_UINT8, "calTargetPower2GHT20", WHAL_NUM_HT_TARGET_POWER_RATES, EEP_DEC_VAL, {28, 28, 24, 24, 24, 20, 20, 28, 28, 24, 24, 24, 20, 20, 0}},
};

// eeprom CAL target power 2G HT40 
static _EEPROM_ENTRY _eepromCalTargetPower2GHT40[] = {
    {EEP_UINT8, "calTargetPower2GHT40", WHAL_NUM_HT_TARGET_POWER_RATES, EEP_DEC_VAL, {28, 28, 24, 24, 24, 20, 20, 28, 28, 24, 24, 24, 20, 20, 0}},
};

// eeprom CTL Index 2G 
static _EEPROM_ENTRY _eepromCtlIndex2G[] = {
    {EEP_UINT8, "ctlIndex2G", WHAL_NUM_CTLS_2G, EEP_HEX_VAL, {0x11, 0x12, 0x15, 0x17, 0x41, 0x42, 0x45, 0x47, 0x31, 0x32, 0x35, 0x37, 0}},
};

// eeprom CTL Freq 2G 
static _EEPROM_ENTRY _eepromCtlFreqbin2G[] = {
    {EEP_UINT8, "ctlFreqbin2G_0", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2457, 1), WHAL_FREQ2FBIN(2462, 1)}},
    {EEP_UINT8, "ctlFreqbin2G_1", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2462, 1), 0xFF}},
    {EEP_UINT8, "ctlFreqbin2G_2", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2462, 1), 0xFF}},
    {EEP_UINT8, "ctlFreqbin2G_3", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2422, 1), WHAL_FREQ2FBIN(2427, 1), WHAL_FREQ2FBIN(2447, 1), WHAL_FREQ2FBIN(2452, 1)}},
    {EEP_UINT8, "ctlFreqbin2G_4", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2472, 1), WHAL_FREQ2FBIN(2484, 1)}},
    {EEP_UINT8, "ctlFreqbin2G_5", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2472, 1), 0}},
    {EEP_UINT8, "ctlFreqbin2G_6", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2472, 1), 0}}, 
    {EEP_UINT8, "ctlFreqbin2G_7", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2422, 1), WHAL_FREQ2FBIN(2427, 1), WHAL_FREQ2FBIN(2447, 1), WHAL_FREQ2FBIN(2462, 1)}},
    {EEP_UINT8, "ctlFreqbin2G_8", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2472, 1), 0}}, 
    {EEP_UINT8, "ctlFreqbin2G_9", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2472, 1), 0}}, 
    {EEP_UINT8, "ctlFreqbin2G_10", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2417, 1), WHAL_FREQ2FBIN(2472, 1), 0}},
    {EEP_UINT8, "ctlFreqbin2G_11", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(2422, 1), WHAL_FREQ2FBIN(2427, 1), WHAL_FREQ2FBIN(2447, 1), WHAL_FREQ2FBIN(2462, 1)}},
};

// eeprom CTL data 2G 
static _EEPROM_ENTRY _eepromCtlData2G[] = {
    {EEP_UINT8, "ctlData2G_0", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 60, 60}},
    {EEP_UINT8, "ctlData2G_1", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 60, 60}}, 
    {EEP_UINT8, "ctlData2G_2", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {61, 60, 60, 61}},
    {EEP_UINT8, "ctlData2G_3", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {61, 60,  0,  0}},
    {EEP_UINT8, "ctlData2G_4", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 60, 60}},
    {EEP_UINT8, "ctlData2G_5", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 60, 60}},
    {EEP_UINT8, "ctlData2G_6", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 61, 60}},
    {EEP_UINT8, "ctlData2G_7", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 60, 60}},
    {EEP_UINT8, "ctlData2G_8", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 60, 60}},
    {EEP_UINT8, "ctlData2G_9", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 60, 60}},
    {EEP_UINT8, "ctlData2G_10", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 61, 61}},
    {EEP_UINT8, "ctlData2G_11", WHAL_NUM_BAND_EDGES_2G, EEP_HEX_VAL, {60, 61, 61, 61}},
};

// eeprom Tx gain table legacy & HT20 
static _EEPROM_ENTRY _eepromTxGainTbl2GLegHT20[] = {
    {EEP_UINT32, "txGainEntryLegHT20", 1, EEP_HEX_VAL, {0x1, 0}},
};

// eeprom temp compensation 2G
static _EEPROM_ENTRY _eepromTempCompChans2G[] = {
    {EEP_UINT8, "alphaThermChans", AR6004_NUM_ALPHATHERM_CHANS, EEP_DEC_VAL, {WHAL_FREQ2FBIN(2412, 1), WHAL_FREQ2FBIN(2437, 1), WHAL_FREQ2FBIN(2457, 1), WHAL_FREQ2FBIN(2472, 1)}},
};
static _EEPROM_ENTRY _eepromTempCompChansData2G[] = {
    {EEP_UINT8, "alphaThermTbl", AR6004_NUM_ALPHATHERM_CHANS, EEP_HEX_VAL, {0x25, 0x25, 0x25, 0x25, 0}},
};

// eeprom ATE GG data 2G
static _EEPROM_ENTRY _eepromATEGGData2G[] = {
    {EEP_UINT8, "GoldenThermAte", 1, EEP_DEC_VAL, {117, 0}},
    {EEP_UINT8, "GoldenVolt", 1, EEP_DEC_VAL, {0, 0}},
    {EEP_UINT8, "pcDac", 1, EEP_DEC_VAL, {59, 0}},
    {EEP_UINT8, "vtestLCodeGolden", 1, EEP_DEC_VAL, {20, 0}},           
    {EEP_INT8,  "vtestLVoltGolden", 1, EEP_DEC_VAL, {4, 0}},            
    {EEP_UINT8, "vtestHCodeGolden", 1, EEP_DEC_VAL, {218, 0}},             
    {EEP_INT8,  "vtestHVoltGolden", 1, EEP_DEC_VAL, {8, 0}},              
    {EEP_UINT8, "numCalChans", 1, EEP_DEC_VAL, {3, 0}},
    {EEP_UINT8, "calFreqPier", 8, EEP_DEC_VAL, {112, 142, 172, 0}},       
};

// eeprom System GG data 2G
static _EEPROM_ENTRY _eepromSystemGGData2G[] = {
    {EEP_UINT8, "GoldenThermSys", 1, EEP_DEC_VAL, {128, 0}},
    {EEP_UINT8, "future", 3, EEP_DEC_VAL, {6}},
};

// eeprom FE delta data 2G
static _EEPROM_ENTRY _eepromFeDeltaCalData2G[] = {
    {EEP_INT8, "refPower_fe", 1, EEP_DEC_VAL, {0}},
    {EEP_INT8, "rxNoisefloorCal_fe", 1, EEP_DEC_VAL, {0}},
    {EEP_INT8, "rxNoisefloorPower_fe", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8, "rxTempMeas_fe", 1, EEP_DEC_VAL, {0}},
    {EEP_INT16, "olpcGainDelta_t10_fe", 1, EEP_DEC_VAL, {0, 0}},
    {EEP_UINT8, "thermCalVal_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "voltCalVal_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScaleCck_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScalePSKLeg_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScaleQAM16Leg_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScaleQAM64Leg_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScalePSKHT20_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScaleQAM16HT20_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScaleQAM64HT20_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScalePSKHT40_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScaleQAM16HT40_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScaleQAM64HT40_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
};

// ==========================================================
// ==========================================================

// eeprom modal 5G
static _EEPROM_ENTRY _eepromModal5G_1[] = {
    {EEP_UINT32, "antCtrlCommon", 1, EEP_HEX_VAL, {0x90449}},
    {EEP_UINT32, "antCtrlCommon2", 1, EEP_HEX_VAL, {0x99999}},
    {EEP_UINT16, "antCtrlChain", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_INT8,   "tempSlope", WHAL_NUM_CHAINS, EEP_DEC_VAL, {36,36}},
    {EEP_INT8,   "voltSlope", WHAL_NUM_CHAINS, EEP_DEC_VAL, {0,0}},
};
    
static _EEPROM_ENTRY _eepromModal5G_2[] = {
    {EEP_INT8,   "noiseFloorThreshCh", WHAL_NUM_CHAINS, EEP_DEC_VAL, {-1, 0}},
    {EEP_UINT16, "ob_db", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x724, 0x724}},
    {EEP_UINT8,  "xpaBiasLvl", 1, EEP_HEX_VAL, {0xf}},
    {EEP_UINT32, "papdRateMaskHt20", 1, EEP_HEX_VAL, {0x0c80C080}},
    {EEP_UINT32, "papdRateMaskHt40", 1, EEP_HEX_VAL, {0x0080C080}},
    {EEP_UINT8,  "paprdQuickDrop", 1, EEP_HEX_VAL, {0x3a}},
    {EEP_UINT8,  "txFrameToDataStart", 1, EEP_HEX_VAL, {0xe}},
    {EEP_UINT8,  "txFrameToPaOn", 1, EEP_HEX_VAL, {0xe}},
    {EEP_UINT8,  "txClip", 1, EEP_DEC_VAL, {3}},
    {EEP_UINT8,  "switchSettling", 1, EEP_HEX_VAL, {0x2d}},
    {EEP_UINT8,  "swSettleHt40", 1, EEP_HEX_VAL, {0x2d}},
    {EEP_INT8,   "adcDesiredSize", 1, EEP_DEC_VAL, {-45}},
    {EEP_UINT8,  "txEndToXpaOff", 1, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "txEndToRxOn", 1, EEP_HEX_VAL, {0x2}},
    {EEP_UINT8,  "txFrameToXpaOn", 1, EEP_HEX_VAL, {0xe}},
    {EEP_UINT8,  "thresh62", 1, EEP_HEX_VAL, {0x1c}},
    {EEP_INT8,   "antennaGainCh", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}}, 
    {EEP_UINT8,  "xatten1Hyst", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x20, 0x20}},
    {EEP_UINT8,  "xatten1DB", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "xatten1Margin", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "xatten2Db", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x19, 0x19}},
    {EEP_UINT8,  "xatten2Margin", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "xatten2Hyst", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "xatten1HystHT40", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x20, 0x20}},
    {EEP_UINT8,  "xatten1DBHT40", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "xatten1MarginHT40", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "xatten2DbHT40", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x2a, 0x2a}},
    {EEP_UINT8,  "xatten2MarginHT40", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x16, 0x16}},
    {EEP_UINT8,  "xatten2HystHT40", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_INT8,   "rxIqCalICh", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_INT8,   "rxIqCalQCh", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "ht40PowerInc", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x2, 0x2}},
    {EEP_UINT8,  "enableXpaBias", 1, EEP_DEC_VAL, {1}},
    {EEP_INT8,   "adcDesiredSizeHT40", 1, EEP_HEX_VAL, {0xd3}},
    {EEP_INT8,   "txGainOffset", 1, EEP_DEC_VAL, {0}},
    {EEP_INT8,   "paprdOffset",  1, EEP_DEC_VAL, {0}},
    {EEP_UINT8,  "enableXpa", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8,  "xlnaGainDb", WHAL_NUM_CHAINS, EEP_HEX_VAL, {0x0, 0x0}},
    {EEP_UINT8,  "futureModal", 31, EEP_HEX_VAL, {0x0}},
    {EEP_UINT8,  "futureModalDataExt", 128, EEP_HEX_VAL, {0x00}},
};

// eeprom CAL freq 5G
static _EEPROM_ENTRY _eepromCalFreq5G[] = {
    {EEP_UINT8, "calFreqPier5G", WHAL_NUM_11A_CAL_PIERS, EEP_DEC_VAL, {76, 88, 92, 104, 140, 160, 180, 189, 201, 205, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,}},
};

// eeprom CAL data 5G
static _EEPROM_ENTRY _eepromCalData5G[] = {
    {EEP_INT8, "refPower", 1, EEP_DEC_VAL, {0}},
    {EEP_INT8, "rxNoisefloorCal", 1, EEP_DEC_VAL, {0}},
    {EEP_INT8, "rxNoisefloorPower", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8, "rxTempMeas", 1, EEP_DEC_VAL, {0}},
    {EEP_INT16, "olpcGainDelta_t10", 1, EEP_DEC_VAL, {-174, 0}},
    {EEP_UINT8, "thermCalVal", 1, EEP_DEC_VAL, {129, 0}}, 
    {EEP_UINT8, "voltCalVal", 1, EEP_DEC_VAL, {98, 0}}, 
    {EEP_UINT8, "desiredScaleCck", 1, EEP_DEC_VAL, {14, 0}}, 
    {EEP_UINT8, "desiredScalePSKLeg_t10", 1, EEP_DEC_VAL, {69, 0}}, 
    {EEP_UINT8, "desiredScaleQAM16Leg_t10", 1, EEP_DEC_VAL, {74, 0}}, 
    {EEP_UINT8, "desiredScaleQAM64Leg_t10", 1, EEP_DEC_VAL, {76, 0}}, 
    {EEP_UINT8, "desiredScalePSKHT20_t10", 1, EEP_DEC_VAL, {78, 0}}, 
    {EEP_UINT8, "desiredScaleQAM16HT20_t10", 1, EEP_DEC_VAL, {75, 0}}, 
    {EEP_UINT8, "desiredScaleQAM64HT20_t10", 1, EEP_DEC_VAL, {79, 0}}, 
    {EEP_UINT8, "desiredScalePSKHT40_t10", 1, EEP_DEC_VAL, {78, 0}}, 
    {EEP_UINT8, "desiredScaleQAM16HT40_t10", 1, EEP_DEC_VAL, {75, 0}}, 
    {EEP_UINT8, "desiredScaleQAM64HT40_t10", 1, EEP_DEC_VAL, {79, 0}}, 
};

static _EEPROM_ENTRY _eepromBoardGpioCfgExt[] = {
    {EEP_UINT8, "Board_GPIO_Number", 1, EEP_DEC_VAL, {0}}, 
    {EEP_UINT8, "Board_GPIO_Config", 1, EEP_HEX_VAL, {0x0}}, 
};

// eeprom CAL target power freq 5G OFDM
static _EEPROM_ENTRY _eepromCalTargetFreqbin5G[] = {
    {EEP_UINT8, "calTargetFreqbin5G", WHAL_NUM_11A_20_TARGET_POWERS, EEP_DEC_VAL, {76, 88, 92, 104, 140, 160, 180, 189, 201, 205, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255}}, 
};

// eeprom CAL target power freq 5G HT20 
static _EEPROM_ENTRY _eepromCalTargetFreqbin5GHT20[] = {
    {EEP_UINT8, "calTargetFreqbin5GHT20", WHAL_NUM_11A_20_TARGET_POWERS, EEP_DEC_VAL, {76, 88, 92, 104, 140, 160, 180, 189, 201, 205, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255}}, 
};

// eeprom CAL target power freq 5G HT40 
static _EEPROM_ENTRY _eepromCalTargetFreqbin5GHT40[] = {
    {EEP_UINT8, "calTargetFreqbin5GHT40", WHAL_NUM_11A_40_TARGET_POWERS, EEP_DEC_VAL, {76, 88, 92, 104, 140, 160, 180, 189, 201, 205, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255}}, 
};

// eeprom CAL target power 5G OFDM
static _EEPROM_ENTRY _eepromCalTargetPower5G[] = {
    {EEP_UINT8, "calTargetPower5G", WHAL_NUM_LEGACY_TARGET_POWER_RATES, EEP_DEC_VAL, {28, 28, 28, 26, 0}},
};

// eeprom CAL target power 5G HT20 
static _EEPROM_ENTRY _eepromCalTargetPower5GHT20[] = {
    {EEP_UINT8, "calTargetPower5GHT20", WHAL_NUM_HT_TARGET_POWER_RATES, EEP_DEC_VAL, {28, 28, 24, 24, 24, 20, 20, 28, 28, 24, 24, 24, 20, 20, 0}},
};

// eeprom CAL target power 5G HT40 
static _EEPROM_ENTRY _eepromCalTargetPower5GHT40[] = {
    {EEP_UINT8, "calTargetPower5GHT40", WHAL_NUM_HT_TARGET_POWER_RATES, EEP_DEC_VAL, {28, 28, 24, 24, 24, 20, 20, 28, 28, 24, 24, 24, 20, 20, 0}},
};

// eeprom CTL Index 5G 
static _EEPROM_ENTRY _eepromCtlIndex5G[] = {
    {EEP_UINT8, "ctlIndex5G", WHAL_NUM_CTLS_5G, EEP_HEX_VAL, {0x30, 0x36, 0x38, 0x31, 0x32, 0x35, 0x37, 0x0, 0x0}}, 
};

// eeprom CTL Freq 5G 
static _EEPROM_ENTRY _eepromCtlFreqbin5G[] = {
    {EEP_UINT8, "ctlFreqbin5G_0", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5180, 0), WHAL_FREQ2FBIN(5260, 0), WHAL_FREQ2FBIN(5280, 0), WHAL_FREQ2FBIN(5500, 0), WHAL_FREQ2FBIN(5600, 0), WHAL_FREQ2FBIN(5700, 0), WHAL_FREQ2FBIN(5745, 0), WHAL_FREQ2FBIN(5825, 0)}},
    {EEP_UINT8, "ctlFreqbin5G_1", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5180, 0), WHAL_FREQ2FBIN(5260, 0), WHAL_FREQ2FBIN(5280, 0), WHAL_FREQ2FBIN(5500, 0), WHAL_FREQ2FBIN(5520, 0), WHAL_FREQ2FBIN(5700, 0), WHAL_FREQ2FBIN(5745, 0), WHAL_FREQ2FBIN(5825, 0)}},
    {EEP_UINT8, "ctlFreqbin5G_2", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5190, 0), WHAL_FREQ2FBIN(5230, 0), WHAL_FREQ2FBIN(5270, 0), WHAL_FREQ2FBIN(5310, 0), WHAL_FREQ2FBIN(5510, 0), WHAL_FREQ2FBIN(5550, 0), WHAL_FREQ2FBIN(5670, 0), WHAL_FREQ2FBIN(5755, 0)}},
    {EEP_UINT8, "ctlFreqbin5G_3", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5180, 0), WHAL_FREQ2FBIN(5200, 0), WHAL_FREQ2FBIN(5260, 0), WHAL_FREQ2FBIN(5320, 0), WHAL_FREQ2FBIN(5500, 0), WHAL_FREQ2FBIN(5700, 0), 0xFF, 0xFF}},
    {EEP_UINT8, "ctlFreqbin5G_4", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5180, 0), WHAL_FREQ2FBIN(5260, 0), WHAL_FREQ2FBIN(5500, 0), WHAL_FREQ2FBIN(5700, 0), 0xFF, 0xFF, 0xFF, 0xFF}},
    {EEP_UINT8, "ctlFreqbin5G_5", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5190, 0), WHAL_FREQ2FBIN(5270, 0), WHAL_FREQ2FBIN(5310, 0), WHAL_FREQ2FBIN(5510, 0), WHAL_FREQ2FBIN(5590, 0), WHAL_FREQ2FBIN(5670, 0), 0xFF, 0xFF}},
    {EEP_UINT8, "ctlFreqbin5G_6", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5180, 0), WHAL_FREQ2FBIN(5200, 0), WHAL_FREQ2FBIN(5220, 0), WHAL_FREQ2FBIN(5260, 0), WHAL_FREQ2FBIN(5500, 0), WHAL_FREQ2FBIN(5600, 0), WHAL_FREQ2FBIN(5700, 0), WHAL_FREQ2FBIN(5745, 0)}},
    {EEP_UINT8, "ctlFreqbin5G_7", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5180, 0), WHAL_FREQ2FBIN(5260, 0), WHAL_FREQ2FBIN(5320, 0), WHAL_FREQ2FBIN(5500, 0), WHAL_FREQ2FBIN(5560, 0), WHAL_FREQ2FBIN(5700, 0), WHAL_FREQ2FBIN(5745, 0), WHAL_FREQ2FBIN(5825, 0)}},
    {EEP_UINT8, "ctlFreqbin5G_8", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {WHAL_FREQ2FBIN(5190, 0), WHAL_FREQ2FBIN(5230, 0), WHAL_FREQ2FBIN(5270, 0), WHAL_FREQ2FBIN(5510, 0), WHAL_FREQ2FBIN(5550, 0), WHAL_FREQ2FBIN(5670, 0), WHAL_FREQ2FBIN(5755, 0), WHAL_FREQ2FBIN(5795, 0)}},
};

// eeprom CTL data 5G 
static _EEPROM_ENTRY _eepromCtlData5G[] = {
    {EEP_UINT8, "ctlData5G_0", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 61, 61, 61, 61, 61, 61, 60}},
    {EEP_UINT8, "ctlData5G_1", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 61, 61, 61, 61, 61, 61, 60}},
    {EEP_UINT8, "ctlData5G_2", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {60, 61, 60, 61, 61, 61, 61, 61}},
    {EEP_UINT8, "ctlData5G_3", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {60, 61, 61, 60, 61, 60, 60, 60}},
    {EEP_UINT8, "ctlData5G_4", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 61, 61, 60, 60, 60, 60, 60}},
    {EEP_UINT8, "ctlData5G_5", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 61, 61, 61, 61, 60, 60, 60}},
    {EEP_UINT8, "ctlData5G_6", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 61, 61, 61, 61, 61, 61, 61}},
    {EEP_UINT8, "ctlData5G_7", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 61, 60, 61, 61, 61, 61, 60}},
    {EEP_UINT8, "ctlData5G_8", WHAL_NUM_BAND_EDGES_5G, EEP_HEX_VAL, {61, 60, 61, 61, 61, 61, 60, 61}},
};

// eeprom Tx gain table legacy & HT20 
static _EEPROM_ENTRY _eepromTxGainTbl5GLegHT20[] = {
    {EEP_UINT32, "txGainEntryLegHT20", 1, EEP_HEX_VAL, {0x3, 0}},
};

static _EEPROM_ENTRY _eepromTierTbl2G_HT20[] = {
    {EEP_UINT32, "tierTbl2G_HT20", 1, EEP_HEX_VAL, {0}},
};

static _EEPROM_ENTRY _eepromTierTbl5G_HT20[] = {
    {EEP_UINT32, "tierTbl5G_HT20", 1, EEP_HEX_VAL, {0}},
};

static _EEPROM_ENTRY _eepromTxGainOverFreq5G[] = {
    {EEP_INT8, "deltaTxGainOverFreq5G", AR6004_OB_NUM, EEP_DEC_VAL, {0}},
};

static _EEPROM_ENTRY _eepromConfigAddr[] = {
    {EEP_UINT32, "configAddr", 50, EEP_HEX_VAL, {0}},
};

static _EEPROM_ENTRY _GPIOConfigEnable[] = {
    {EEP_UINT8, "GPIOConfigEnable", 1, EEP_HEX_VAL, {0}},
};

static _EEPROM_ENTRY _eepromGPIOConfigMode1[] = {
    {EEP_BITFIELD, "GPIOConfigMode1", 7, EEP_HEX_VAL, {0,0,0,0,0,0,0}, {{"config"},{"strengh"},{"output"},{"pull"},{"applied"},{"avail"},{"swfunc"}}, {0x4,0x2,0x1,0x2,0x1,0x1,0x5}},
};

static _EEPROM_ENTRY _eepromGPIOConfigMode2[] = {
    {EEP_BITFIELD, "GPIOConfigMode2", 7, EEP_HEX_VAL, {0,0,0,0,0,0,0}, {{"config"},{"strengh"},{"output"},{"pull"},{"applied"},{"avail"},{"swfunc"}}, {0x4,0x2,0x1,0x2,0x1,0x1,0x5}},
};

static _EEPROM_ENTRY _eepromGPIOConfigMode3[] = {
    {EEP_BITFIELD, "GPIOConfigMode3", 7, EEP_HEX_VAL, {0,0,0,0,0,0,0}, {{"config"},{"strengh"},{"output"},{"pull"},{"applied"},{"avail"},{"swfunc"}}, {0x4,0x2,0x1,0x2,0x1,0x1,0x5}},
};

// eeprom temp compensation 5G
static _EEPROM_ENTRY _eepromTempCompChans5G[] = {
    {EEP_UINT8, "alphaThermChans", AR6004_NUM_ALPHATHERM_CHANS, EEP_DEC_VAL, {WHAL_FREQ2FBIN(5180, 0), WHAL_FREQ2FBIN(5320, 0), WHAL_FREQ2FBIN(5600, 0), WHAL_FREQ2FBIN(5805, 0)}},
};

static _EEPROM_ENTRY _eepromTempCompChans5G_1[] = {
    {EEP_UINT8, "alphaThermChans_Ext", AR6004_NUM_ALPHATHERM_CHANS, EEP_DEC_VAL, {WHAL_FREQ2FBIN(5180, 0), WHAL_FREQ2FBIN(5320, 0), WHAL_FREQ2FBIN(5600, 0), WHAL_FREQ2FBIN(5805, 0)}},
};

static _EEPROM_ENTRY _eepromTempCompChansData5G[] = {
    {EEP_UINT8, "alphaThermTbl", AR6004_NUM_ALPHATHERM_CHANS, EEP_HEX_VAL, {0x27, 0x26, 0x25, 0x24, 0}},
};

static _EEPROM_ENTRY _eepromTempCompChansData5G_1[] = {
    {EEP_UINT8, "alphaThermTbl_Ext", AR6004_NUM_ALPHATHERM_CHANS, EEP_HEX_VAL, {0x27, 0x26, 0x25, 0x24, 0}},
};

static _EEPROM_ENTRY _eepromCCKPwr4BT[] = {
    { EEP_BITFIELD, "CCKPwr4BT", 3, EEP_HEX_VAL, {0,0,0}, {{"pwr"},{"reserve"},{"enable"}},{0x6,0x1,0x1}},
};

static _EEPROM_ENTRY _eepromOFDMPwr4BT[] = {
    { EEP_BITFIELD, "OFDMPwr4BT", 3, EEP_HEX_VAL, {0,0,0}, {{"pwr"},{"reserve"},{"enable"}},{0x6,0x1,0x1}},
};

// eeprom ATE GG data 5G
static _EEPROM_ENTRY _eepromATEGGData5G[] = {
    {EEP_UINT8, "GoldenThermAte", 1, EEP_DEC_VAL, {117, 0}},
    {EEP_UINT8, "GoldenVolt", 1, EEP_DEC_VAL, {0, 0}},
    {EEP_UINT8, "pcDac", 1, EEP_DEC_VAL, {59, 0}},
    {EEP_UINT8, "vtestLCodeGolden", 1, EEP_DEC_VAL, {20, 0}},           
    {EEP_INT8,  "vtestLVoltGolden", 1, EEP_DEC_VAL, {4, 0}},            
    {EEP_UINT8, "vtestHCodeGolden", 1, EEP_DEC_VAL, {218, 0}},             
    {EEP_INT8,  "vtestHVoltGolden", 1, EEP_DEC_VAL, {8, 0}},              
    {EEP_UINT8, "numCalChans", 1, EEP_DEC_VAL, {8, 0}},
    {EEP_UINT8, "calFreqPier", 8, EEP_DEC_VAL, {76, 92, 104, 140, 160, 180, 201, 205, 0}},       
};

// eeprom System GG data 5G
static _EEPROM_ENTRY _eepromSystemGGData5G[] = {
    {EEP_UINT8, "GoldenThermSys", 1, EEP_DEC_VAL, {128, 0}},
    {EEP_UINT8, "future", 3, EEP_DEC_VAL, {6}},
};

// eeprom FE delta data 5G
static _EEPROM_ENTRY _eepromFeDeltaCalData5G[] = {
    {EEP_INT8, "refPower_fe", 1, EEP_DEC_VAL, {0}},
    {EEP_INT8, "rxNoisefloorCal_fe", 1, EEP_DEC_VAL, {0}},
    {EEP_INT8, "rxNoisefloorPower_fe", 1, EEP_DEC_VAL, {0}},
    {EEP_UINT8, "rxTempMeas_fe", 1, EEP_DEC_VAL, {0}},
    {EEP_INT16, "olpcGainDelta_t10_fe", 1, EEP_DEC_VAL, {0, 0}},
    {EEP_UINT8, "thermCalVal_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "voltCalVal_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScaleCck_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScalePSKLeg_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScaleQAM16Leg_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScaleQAM64Leg_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScalePSKHT20_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScaleQAM16HT20_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScaleQAM64HT20_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScalePSKHT40_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScaleQAM16HT40_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
    {EEP_UINT8, "desiredScaleQAM64HT40_t10_fe", 1, EEP_DEC_VAL, {0, 0}}, 
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
    int i;
    fprintf(fpData, "%s ", key);
    for (i=0;i<size/*numCol*/;i++) {
        if (type == EEP_BITFIELD) {
            fprintf(fpData, "%s:", bitFieldName[i]);
            fprintf(fpData, prtStr, value[i]);
            fprintf(fpData, " ", value[i]);
        }
        else
            fprintf(fpData, prtStr, value[i]);
    }
    fprintf(fpData, "\n");
    return;
}


static void addEepromDataHex(char *key, EEP_TYPE type, A_UINT32 size, EEP_TYPE_PRINT prt, A_INT32 *value, char (*bitFieldName)[MAX_NAME_SIZE], A_UINT32 numCol) 
{
    return(addEepromData(key, type, size, " 0x%x", value, bitFieldName, numCol));
}

static void addEepromDataDec(char *key, EEP_TYPE type, A_UINT32 size, EEP_TYPE_PRINT prt, A_INT32 *value, char (*bitFieldName)[MAX_NAME_SIZE], A_UINT32 numCol) 
{
    return(addEepromData(key, type, size, " %d", value, bitFieldName, numCol));
}

static void genEepromTemplateAndDefaultData(_EEPROM_ENTRY *tbl, A_UINT32 numEntries, char *band, A_UINT32 numRow1, A_UINT32 numRow2, A_UINT32 numCol)
{
    int r1, r2, e, i;
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

    sprintf(fileName, "eeprom_%d_%d.tpl", AR6004_EEP_VER, AR6004_EEP_MINOR_VER);
    if( (fpTpl = fopen(fileName, "w")) == NULL) {
        printf("Error: could not open template %s\n", fileName);
        return(-1);
    }
    
    sprintf(fileName, "eeprom_dflt_%d_%d.txt", AR6004_EEP_VER, AR6004_EEP_MINOR_VER);
    if( (fpData = fopen(fileName, "w")) == NULL) {
        printf("Error: could not open default data %s\n", fileName);
        return(-1);
    }
    
    // follow the flow of ar6004_eeprom.h
//typedef struct ar6004Eeprom {
    //BASE_EEP_HEADER               baseEepHeader;                                               //  96B   //  96B
    printf("BASE_EEP_HEADER               baseEepHeader;\n");
    genEepromTemplateAndDefaultData(_eepromBase, sizeof(_eepromBase)/sizeof(_EEPROM_ENTRY), "", 1, 1, 1);

    //COMMON_EEP_HEADER             commonEepHeader;                                             //  32B   //  32B
    printf("COMMON_EEP_HEADER             commonEepHeader;\n");
    genEepromTemplateAndDefaultData(_eepromCommon, sizeof(_eepromCommon)/sizeof(_EEPROM_ENTRY), "", 1, 1, 1);

    //CAL_DATA_PER_CHIP             chipCalData;                                                 //  3B
    printf("CAL_DATA_PER_CHIP             chipCalData;\n");
    genEepromTemplateAndDefaultData(_eepromChipCalData, sizeof(_eepromChipCalData)/sizeof(_EEPROM_ENTRY), "", 1, 1, 1);                      //  16B

    //MODAL_EEP_HEADER              modalHeader2G;                                               // 128B   // 128B
    printf("MODAL_EEP_HEADER              modalHeader2G;\n");
    genEepromTemplateAndDefaultData(_eepromModal2G_1, sizeof(_eepromModal2G_1)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);
    genEepromTemplateAndDefaultData(_eepromSpurChans, sizeof(_eepromSpurChans)/sizeof(_EEPROM_ENTRY), "G", AR6004_EEPROM_MODAL_SPURS, 1, 1);
    genEepromTemplateAndDefaultData(_eepromModal2G_2, sizeof(_eepromModal2G_2)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);

    //A_UINT8                       calFreqPier2G[WHAL_NUM_11G_CAL_PIERS];                      //  16B
    printf("A_UINT8                       calFreqPier2G[WHAL_NUM_11G_CAL_PIERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalFreq2G, sizeof(_eepromCalFreq2G)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1); //  16B
      
    //CAL_DATA_PER_FREQ_OLPC        calPierData2G[WHAL_NUM_CHAINS][WHAL_NUM_11G_CAL_PIERS];     // 288B   // 304B
    printf("CAL_DATA_PER_FREQ_OLPC        calPierData2G[WHAL_NUM_CHAINS][WHAL_NUM_11G_CAL_PIERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalData2G, sizeof(_eepromCalData2G)/sizeof(_EEPROM_ENTRY), "G", WHAL_NUM_CHAINS, WHAL_NUM_11G_CAL_PIERS, 1);                      //  16B

    //addReservedData("pad2GCALData", 64);

    //A_UINT8                       calTargetFreqbinCck[WHAL_NUM_11B_TARGET_POWERS];             //   2B
    printf("A_UINT8                       calTargetFreqbinCck[WHAL_NUM_11B_TARGET_POWERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalTargetFreqbinCck, sizeof(_eepromCalTargetFreqbinCck)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);                      //  16B
      
    //A_UINT8                       pad1[2];                                                     //   2B   
    printf("A_UINT8                       pad1[2];\n");
    addReservedData("pad1", 2);

    //A_UINT8                       calTargetFreqbin2G[WHAL_NUM_11G_20_TARGET_POWERS];           //   3B
    printf("A_UINT8                       calTargetFreqbin2G[WHAL_NUM_11G_20_TARGET_POWERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalTargetFreqbin2G, sizeof(_eepromCalTargetFreqbin2G)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);                      //  16B

    //A_UINT8                       pad2[1];                                                     //   1B   
    printf("A_UINT8                       pad2[1];\n");
    addReservedData("pad2", 1);

    //A_UINT8                       calTargetFreqbin2GHT20[WHAL_NUM_11G_20_TARGET_POWERS];       //   3B
    printf("A_UINT8                       calTargetFreqbin2GHT20[WHAL_NUM_11G_20_TARGET_POWERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalTargetFreqbin2GHT20, sizeof(_eepromCalTargetFreqbin2GHT20)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);                      //  16B
      
    //A_UINT8                       pad3[1];                                                     //   1B   
    printf("A_UINT8                       pad3[1];\n");
    addReservedData("pad3", 1);

    //A_UINT8                       calTargetFreqbin2GHT40[WHAL_NUM_11G_40_TARGET_POWERS];       //   3B
    printf("A_UINT8                       calTargetFreqbin2GHT40[WHAL_NUM_11G_40_TARGET_POWERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalTargetFreqbin2GHT40, sizeof(_eepromCalTargetFreqbin2GHT40)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);                      //  16B
      
    //A_UINT8                       pad4[1];                                                     //   1B   
    printf("A_UINT8                       pad4[1];\n");
    addReservedData("pad4", 1);

    //CAL_TARGET_POWER_LEG          calTargetPowerCck[WHAL_NUM_11B_TARGET_POWERS];               //   8B
    printf("CAL_TARGET_POWER_LEG          calTargetPowerCck[WHAL_NUM_11B_TARGET_POWERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalTargetPowerCCK, sizeof(_eepromCalTargetPowerCCK)/sizeof(_EEPROM_ENTRY), "G", WHAL_NUM_11B_TARGET_POWERS, 1, 1);                      //  16B
    
    //CAL_TARGET_POWER_LEG          calTargetPower2G[WHAL_NUM_11G_20_TARGET_POWERS];             //  12B
    printf("CAL_TARGET_POWER_LEG          calTargetPower2G[WHAL_NUM_11G_20_TARGET_POWERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalTargetPower2G, sizeof(_eepromCalTargetPower2G)/sizeof(_EEPROM_ENTRY), "G", WHAL_NUM_11G_20_TARGET_POWERS, 1, 1);                      //  16B

    //CAL_TARGET_POWER_HT           calTargetPower2GHT20[WHAL_NUM_11G_20_TARGET_POWERS];         //  42B
    printf("CAL_TARGET_POWER_HT           calTargetPower2GHT20[WHAL_NUM_11G_20_TARGET_POWERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalTargetPower2GHT20, sizeof(_eepromCalTargetPower2GHT20)/sizeof(_EEPROM_ENTRY), "G", WHAL_NUM_11G_20_TARGET_POWERS, 1, 1);                      //  16B

    //A_UINT8                       pad5[2];                                                     //   2B   
    printf("A_UINT8                       pad5[2];\n");
    addReservedData("pad5", 2);

    //CAL_TARGET_POWER_HT           calTargetPower2GHT40[WHAL_NUM_11G_40_TARGET_POWERS];         //  42B
    printf("CAL_TARGET_POWER_HT           calTargetPower2GHT40[WHAL_NUM_11G_40_TARGET_POWERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalTargetPower2GHT40, sizeof(_eepromCalTargetPower2GHT40)/sizeof(_EEPROM_ENTRY), "G", WHAL_NUM_11G_40_TARGET_POWERS, 1, 1);                      //  16B
      
    //A_UINT8                       pad6[2];                                                     //   2B   
    printf("A_UINT8                       pad6[2];\n");
    addReservedData("pad6", 2);

    //A_UINT8                       ctlIndex2G[WHAL_NUM_CTLS_2G];                                //  12B
    printf("A_UINT8                       ctlIndex2G[WHAL_NUM_CTLS_2G];\n");
    genEepromTemplateAndDefaultData(_eepromCtlIndex2G, sizeof(_eepromCtlIndex2G)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);                      //  16B

    printf("A_UINT8                       ctlFreqbin2G[WHAL_NUM_CTLS][WHAL_NUM_BAND_EDGES];\n");
    //A_UINT8                       ctlFreqbin2G[WHAL_NUM_CTLS][NUM_BAND_EDGES];           //  48B
    genEepromTemplateAndDefaultData(_eepromCtlFreqbin2G, sizeof(_eepromCtlFreqbin2G)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);                      //  16B
    printf("CAL_CTL_DATA                  ctlData2G[WHAL_NUM_CTLS_2G];\n");
    //CAL_CTL_DATA               ctlData2G[WHAL_NUM_CTLS];                               //  48B   // 108B
    genEepromTemplateAndDefaultData(_eepromCtlData2G, sizeof(_eepromCtlData2G)/sizeof(_EEPROM_ENTRY), "G", 1, 1, 1);                      //  16B

    // Venus addition
    //TX_GAIN_TBL                   txGainTblLEG_HT20;                                        // 128B     
    printf("TX_GAIN_TBL                   txGainTblLEG_HT20;\n");
    genEepromTemplateAndDefaultData(_eepromTxGainTbl2GLegHT20, sizeof(_eepromTxGainTbl2GLegHT20)/sizeof(_EEPROM_ENTRY), "G", AR6004_TX_GAIN_ENTRIES, 1, 1);                      //  16B

    printf("TIER_TBL                      tierTbl_2G_HT20;\n");
    genEepromTemplateAndDefaultData(_eepromTierTbl2G_HT20, sizeof(_eepromTierTbl2G_HT20)/sizeof(_EEPROM_ENTRY), "G", AR6004_TX_GAIN_ENTRIES, 1, 1);

    //A_UINT32                      config_2GHT20;                                             //  64B              
    //printf("A_UINT32                      config_2GHT20;\n");
    //genEepromTemplateAndDefaultData(_eepromConfig2GHT20, sizeof(_eepromConfig2GHT20)/sizeof(_EEPROM_ENTRY), "G", AR6004_CONFIG_ENTRIES, 1, 1);

    //TX_GAIN_TBL                   txGainTblHT40;                                            // 128B   
    //printf("TX_GAIN_TBL                   txGainTbl_2GHT40;\n");
    //genEepromTemplateAndDefaultData(_eepromTxGainTbl2GHT40, sizeof(_eepromTxGainTbl2GHT40)/sizeof(_EEPROM_ENTRY), "G", AR6004_TX_GAIN_ENTRIES, 1, 1);                      //  16B

    //A_UINT32                      config_2GHT40;                                             //  64B              
    //printf("A_UINT32                      config_2GHT40;\n");
    //genEepromTemplateAndDefaultData(_eepromConfig2GHT40, sizeof(_eepromConfig2GHT40)/sizeof(_EEPROM_ENTRY), "G", AR6004_CONFIG_ENTRIES, 1, 1);

    //TEMP_COMP_TBL                 tempComp_2G;                                                  //  36B   //  36B     
    printf("TEMP_COMP_TBL                 tempComp_2G;\n");
    genEepromTemplateAndDefaultData(_eepromTempCompChans2G, sizeof(_eepromTempCompChans2G)/sizeof(_EEPROM_ENTRY), "G", WHAL_NUM_CHAINS, 1, 1);                      //  8B
    genEepromTemplateAndDefaultData(_eepromTempCompChansData2G, sizeof(_eepromTempCompChansData2G)/sizeof(_EEPROM_ENTRY), "G", WHAL_NUM_CHAINS, AR6004_NUM_ALPHATHERM_CHANS, 1);                      //  32B


    // New features expansion
    //A_UINT8                       newFeaturesData_2G[480];                                     // 480B   // 480B
    printf("A_UINT8                       newFeaturesData_2G[128];\n");
    addReservedData("newFeaturesData_2G", 128);

    //MODAL_EEP_HEADER              modalHeader5G;                                                // 128B  // 128B
    printf("MODAL_EEP_HEADER              modalHeader5G;\n");
    genEepromTemplateAndDefaultData(_eepromModal5G_1, sizeof(_eepromModal5G_1)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);
    genEepromTemplateAndDefaultData(_eepromSpurChans, sizeof(_eepromSpurChans)/sizeof(_EEPROM_ENTRY), "A", AR6004_EEPROM_MODAL_SPURS, 1, 1);
    genEepromTemplateAndDefaultData(_eepromModal5G_2, sizeof(_eepromModal5G_2)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);

    //A_UINT8                       calFreqPier5G[WHAL_NUM_11A_CAL_PIERS];                       //  32B
    printf("A_UINT8                       calFreqPier5G[WHAL_NUM_11A_CAL_PIERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalFreq5G, sizeof(_eepromCalFreq5G)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1); //  16B

    //CAL_DATA_PER_FREQ_OLPC        calPierData5G[WHAL_NUM_CHAINS][WHAL_NUM_11A_CAL_PIERS];      // 576B  // 608B
    printf("CAL_DATA_PER_FREQ_OLPC        calPierData5G[WHAL_NUM_CHAINS][WHAL_NUM_11A_CAL_PIERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalData5G, sizeof(_eepromCalData5G)/sizeof(_EEPROM_ENTRY), "A", WHAL_NUM_CHAINS, WHAL_NUM_11A_CAL_PIERS, 1);                      //  16B

    //addReservedData("pad5GCALData", 64);
    
    //A_UINT8                       calTargetFreqbin5G[WHAL_NUM_11A_20_TARGET_POWERS];           //   8B
    printf("A_UINT8                       calTargetFreqbin5G[WHAL_NUM_11A_20_TARGET_POWERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalTargetFreqbin5G, sizeof(_eepromCalTargetFreqbin5G)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);                      //  16B

    //A_UINT8                       calTargetFreqbin5GHT20[WHAL_NUM_11A_20_TARGET_POWERS];       //   8B
    printf("A_UINT8                       calTargetFreqbin5GHT20[WHAL_NUM_11A_20_TARGET_POWERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalTargetFreqbin5GHT20, sizeof(_eepromCalTargetFreqbin5GHT20)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);                      //  16B

    //A_UINT8                       calTargetFreqbin5GHT40[WHAL_NUM_11A_40_TARGET_POWERS];       //   8B
    printf("A_UINT8                       calTargetFreqbin5GHT40[WHAL_NUM_11A_40_TARGET_POWERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalTargetFreqbin5GHT40, sizeof(_eepromCalTargetFreqbin5GHT40)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);                      //  16B

    //CAL_TARGET_POWER_LEG          calTargetPower5G[WHAL_NUM_11A_20_TARGET_POWERS];             //  32B
    printf("CAL_TARGET_POWER_LEG          calTargetPower5G[WHAL_NUM_11A_20_TARGET_POWERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalTargetPower5G, sizeof(_eepromCalTargetPower5G)/sizeof(_EEPROM_ENTRY), "A", WHAL_NUM_11A_20_TARGET_POWERS, 1, 1);                      //  16B

    //CAL_TARGET_POWER_HT           calTargetPower5GHT20[WHAL_NUM_11A_20_TARGET_POWERS];         // 112B
    printf("CAL_TARGET_POWER_HT           calTargetPower5GHT20[WHAL_NUM_11A_20_TARGET_POWERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalTargetPower5GHT20, sizeof(_eepromCalTargetPower5GHT20)/sizeof(_EEPROM_ENTRY), "A", WHAL_NUM_11A_20_TARGET_POWERS, 1, 1);                      //  16B

    //CAL_TARGET_POWER_HT           calTargetPower5GHT40[WHAL_NUM_11A_40_TARGET_POWERS];         // 112B  // 280B
    printf("CAL_TARGET_POWER_HT           calTargetPower5GHT40[WHAL_NUM_11A_40_TARGET_POWERS];\n");
    genEepromTemplateAndDefaultData(_eepromCalTargetPower5GHT40, sizeof(_eepromCalTargetPower5GHT40)/sizeof(_EEPROM_ENTRY), "A", WHAL_NUM_11A_40_TARGET_POWERS, 1, 1);                      //  16B

    //A_UINT8                       ctlIndex5G[WHAL_NUM_CTLS];                               //   9B
    printf("A_UINT8                       ctlIndex5G[WHAL_NUM_CTLS_5G];\n");
    genEepromTemplateAndDefaultData(_eepromCtlIndex5G, sizeof(_eepromCtlIndex5G)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);                      //  16B
      
    //A_UINT8                       ctl5GFuture[3];                                               //   3B  // 156B 
    printf("A_UINT8                       ctl5GFuture[3];\n");
    addReservedData("ctl5GFuture", 3);

    //A_UINT8                       ctlFreqbin5G[WHAL_NUM_CTLS][NUM_BAND_EDGES];          //  72B
    printf("A_UINT8                       ctlFreqbin5G[WHAL_NUM_CTLS_5G][WHAL_NUM_BAND_EDGES_5G];\n");
    genEepromTemplateAndDefaultData(_eepromCtlFreqbin5G, sizeof(_eepromCtlFreqbin5G)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);                      //  16B

    //CAL_CTL_DATA               ctlData5G[WHAL_NUM_CTLS];                                //  72B
    printf("CAL_CTL_DATA                  ctlData5G[WHAL_NUM_CTLS_5G];\n");                                //  72B
    genEepromTemplateAndDefaultData(_eepromCtlData5G, sizeof(_eepromCtlData5G)/sizeof(_EEPROM_ENTRY), "A", 1, 1, 1);                      //  16B
    
    // Venus addition
    //TX_GAIN_TBL                   txGainTblLEG_HT20;                                         // 128B              
    printf("TX_GAIN_TBL                   txGainTbl_5GLEG_HT20;\n");
    genEepromTemplateAndDefaultData(_eepromTxGainTbl5GLegHT20, sizeof(_eepromTxGainTbl5GLegHT20)/sizeof(_EEPROM_ENTRY), "A", AR6004_TX_GAIN_ENTRIES, 1, 1);                      //  16B

    printf("TIER_TBL                      tierTbl_5G_HT20;\n");
    genEepromTemplateAndDefaultData(_eepromTierTbl5G_HT20, sizeof(_eepromTierTbl5G_HT20)/sizeof(_EEPROM_ENTRY), "A", AR6004_TX_GAIN_ENTRIES, 1, 1);

    //printf("TX_GAIN_OVER_FREQ             txGainOverFreq5G;\n");
    //genEepromTemplateAndDefaultData(_eepromTxGainOverFreq5G, sizeof(_eepromTxGainOverFreq5G)/sizeof(_EEPROM_ENTRY), "A", AR6004_NUM_5G_PER_100M, 1, AR6004_TX_GAIN_ENTRIES);

    //A_UINT32                      config_5GHT20;                                             //  64B              
    //printf("A_UINT32                      config_5GHT20;\n");
    //genEepromTemplateAndDefaultData(_eepromConfig5GHT20, sizeof(_eepromConfig5GHT20)/sizeof(_EEPROM_ENTRY), "A", AR6004_CONFIG_ENTRIES, 1, 1);

    //TX_GAIN_TBL                   txGainTblHT40                                              // 128B  // 256B
    //printf("TX_GAIN_TBL                   txGainTbl_5GHT40;\n");
    //genEepromTemplateAndDefaultData(_eepromTxGainTbl5GHT40, sizeof(_eepromTxGainTbl5GHT40)/sizeof(_EEPROM_ENTRY), "A", AR6004_TX_GAIN_ENTRIES, 1, 1);                      //  16B

    //A_UINT32                      config_5GHT40;                                             //  64B              
    //printf("A_UINT32                      config_5GHT40;\n");
    //genEepromTemplateAndDefaultData(_eepromConfig5GHT40, sizeof(_eepromConfig5GHT40)/sizeof(_EEPROM_ENTRY), "A", AR6004_CONFIG_ENTRIES, 1, 1);

    //TEMP_COMP_TBL                 tempComp;                                                  //  36B  //  36B                 
    printf("TEMP_COMP_TBL                 tempComp_5G;\n");
    genEepromTemplateAndDefaultData(_eepromTempCompChans5G, sizeof(_eepromTempCompChans5G)/sizeof(_EEPROM_ENTRY), "A", WHAL_NUM_CHAINS, 1, 1);                      //  8B
    genEepromTemplateAndDefaultData(_eepromTempCompChansData5G, sizeof(_eepromTempCompChansData5G)/sizeof(_EEPROM_ENTRY), "A", WHAL_NUM_CHAINS, AR6004_NUM_ALPHATHERM_CHANS, 1);                      //  32B

    printf("TEMP_COMP_TBL                 tempComp_5G_1;\n");
    genEepromTemplateAndDefaultData(_eepromTempCompChans5G_1, sizeof(_eepromTempCompChans5G_1)/sizeof(_EEPROM_ENTRY), "A", WHAL_NUM_CHAINS, 1, 1);                      //  8B
    genEepromTemplateAndDefaultData(_eepromTempCompChansData5G_1, sizeof(_eepromTempCompChansData5G_1)/sizeof(_EEPROM_ENTRY), "A", WHAL_NUM_CHAINS, AR6004_NUM_ALPHATHERM_CHANS, 1);
                      //  32B
    // New features expansion
    //A_UINT8                       newFeaturesData[480];                                      // 768B  // 768B
    printf("A_UINT8                       newFeaturesData_5G[88];  \n");
    addReservedData("newFeaturesData_5G", 88);
                                                                                                         //4836B
    //A_UINT32                      configAddr                                              // 64B
    printf("A_UINT32                      configAddr[80];\n");
    genEepromTemplateAndDefaultData(_eepromConfigAddr, sizeof(_eepromConfigAddr)/sizeof(_EEPROM_ENTRY), "", 1, 1, 1);                      //  16B

    printf("A_UINT8                       configAddrFuture[19];\n");
    addReservedData("configAddrFuture", 19);

    printf("A_UINT8                       GPIOConfigEnable[1];\n");
    genEepromTemplateAndDefaultData(_GPIOConfigEnable, sizeof(_GPIOConfigEnable)/sizeof(_EEPROM_ENTRY), "", 1, 1, 1);                      //  1B

    //A_UINT32                      GPIOConfig[114];                                            // 114B
    printf("A_UINT8                       GPIOConfigMode1[114];\n");
    genEepromTemplateAndDefaultData(_eepromGPIOConfigMode1, sizeof(_eepromGPIOConfigMode1)/sizeof(_EEPROM_ENTRY), "", 1, 57, 1);                      //  114

    printf("A_UINT8                       GPIOConfigMode2[114];\n");
    genEepromTemplateAndDefaultData(_eepromGPIOConfigMode2, sizeof(_eepromGPIOConfigMode2)/sizeof(_EEPROM_ENTRY), "", 1, 57, 1);       

    printf("A_UINT8                       txGainTblEepEna;\n");
    addReservedData("txGainTblEepEna", 1);

    printf("A_UINT8                       txGainTblScheme;\n");
    addReservedData("txGainTblScheme", 1);

    printf("TX_GAIN_OVER_FREQ             txGainOverFreq5G;\n");
    genEepromTemplateAndDefaultData(_eepromTxGainOverFreq5G, sizeof(_eepromTxGainOverFreq5G)/sizeof(_EEPROM_ENTRY), "A", AR6004_NUM_5G_PER_100M, 1, AR6004_OB_NUM); //80B

    printf("A_UINT8                       GPIOConfigMode3[114];\n");
    genEepromTemplateAndDefaultData(_eepromGPIOConfigMode3, sizeof(_eepromGPIOConfigMode3)/sizeof(_EEPROM_ENTRY), "", 1, 57, 1);    

    printf("A_UINT8                       eepromBoardGpioCfgExt[6];\n");
    genEepromTemplateAndDefaultData(_eepromBoardGpioCfgExt, sizeof(_eepromBoardGpioCfgExt)/sizeof(_EEPROM_ENTRY), "", 1, MAX_BOARD_GPIO_CFG_EXT, 1);

    printf("A_UINT8                       CCKPwr4BT;\n");
    genEepromTemplateAndDefaultData(_eepromCCKPwr4BT, sizeof(_eepromCCKPwr4BT)/sizeof(_EEPROM_ENTRY), "", 1, 1, 1);

    printf("A_UINT8                       OFDMPwr4BT;\n");
    genEepromTemplateAndDefaultData(_eepromOFDMPwr4BT, sizeof(_eepromOFDMPwr4BT)/sizeof(_EEPROM_ENTRY), "", 1, 1, 1);

    printf("A_UINT8                       padFuture[28];\n");
    addReservedData("padFuture", 28);
    
    //ATE_GG_DATA                   ateGGCALData2G[WHAL_NUM_CHAINS];                             //  32B
    printf("ATE_GG_DATA                   ateGGCALData2G[WHAL_NUM_CHAINS];\n");
    genEepromTemplateAndDefaultData(_eepromATEGGData2G, sizeof(_eepromATEGGData2G)/sizeof(_EEPROM_ENTRY), "G", WHAL_NUM_CHAINS, 1, 1);                      //  16B

    //SYSTEM_GG_DATA                sysGGCALData2G[WHAL_NUM_CHAINS];                             //   8B
    printf("SYSTEM_GG_DATA                sysGGCALData2G[WHAL_NUM_CHAINS];\n");
    genEepromTemplateAndDefaultData(_eepromSystemGGData2G, sizeof(_eepromSystemGGData2G)/sizeof(_EEPROM_ENTRY), "G", WHAL_NUM_CHAINS, 1, 1);                      //  16B

    //CAL_DATA_PER_FREQ_OLPC        feDeltaCalData2G[WHAL_NUM_CHAINS][WHAL_NUM_11G_CAL_PIERS];   // 576B
    printf("CAL_DATA_PER_FREQ_OLPC        feDeltaCalData2G[WHAL_NUM_CHAINS][WHAL_NUM_11G_CAL_PIERS];\n");
    genEepromTemplateAndDefaultData(_eepromFeDeltaCalData2G, sizeof(_eepromFeDeltaCalData2G)/sizeof(_EEPROM_ENTRY), "G", WHAL_NUM_CHAINS, WHAL_NUM_11G_CAL_PIERS, 1);                      //  16B

    //addReservedData("pad2GFEData", 64);
    //ATE_GG_DATA                   ateGGCALData5G[WHAL_NUM_CHAINS];                              //  23B             
    printf("ATE_GG_DATA                   ateGGCALData5G[WHAL_NUM_CHAINS];\n");
    genEepromTemplateAndDefaultData(_eepromATEGGData5G, sizeof(_eepromATEGGData5G)/sizeof(_EEPROM_ENTRY), "A", WHAL_NUM_CHAINS, 1, 1);                      //  16B

    //SYSTEM_GG_DATA                sysGGCALData5G[WHAL_NUM_CHAINS];                              //   8B             
    printf("SYSTEM_GG_DATA                sysGGCALData5G[WHAL_NUM_CHAINS];\n");
    genEepromTemplateAndDefaultData(_eepromSystemGGData5G, sizeof(_eepromSystemGGData5G)/sizeof(_EEPROM_ENTRY), "A", WHAL_NUM_CHAINS, 1, 1);                      //  16B

    //CAL_DATA_PER_FREQ_OLPC        feDeltaCalData_5g[WHAL_NUM_CHAINS][WHAL_NUM_11A_CAL_PIERS];   //1088B
    printf("CAL_DATA_PER_FREQ_OLPC        feDeltaCalData_5g[WHAL_NUM_CHAINS][WHAL_NUM_11A_CAL_PIERS];\n");
    genEepromTemplateAndDefaultData(_eepromFeDeltaCalData5G, sizeof(_eepromFeDeltaCalData5G)/sizeof(_EEPROM_ENTRY), "A", WHAL_NUM_CHAINS, WHAL_NUM_11A_CAL_PIERS, 1);                      //  16B

    //A_UINT8                       padNonRAM[672]; 
    printf("A_UINT8                       padNonRAM[672];  \n");
    addReservedData("padNonRAM", 672);
// } struct ar6004Eeprom 

    return 0;
}


