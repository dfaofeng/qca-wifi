#if !defined(_EEPROMUTIL_H)
#define _EEPROMUTIL_H

#ifdef _WINDOWS
	#ifdef EEPROMUTILDLL_EXPORTS
		#define EEPROMUTILDLLSPEC __declspec(dllexport)
	#else
		#define EEPROMUTILDLLSPEC __declspec(dllimport)
	#endif
#else
	#define EEPROMUTILDLLSPEC
#endif

#if defined(_DEBUG)
    #define _printf printf
#else
    #define _printf //
#endif

#if defined(_USE_AS_API)
    #define _printf //
#endif

#define FALSE 0
#define TRUE 1

#define MAX_KEY_LEN 64
#define MAX_TEMPLATE_ENTRIES 4096
#define MAX_LINE_BUF 2048
#define MAX_FILENAME_LEN 64
#define MAX_ARG_LEN 64
#define MAX_BIT_FIELD 32

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

typedef struct EEP_TYPE_BIT_FIELD {
    A_UINT8 numFields;
    char name[MAX_BIT_FIELD][16];
    char numBits[MAX_BIT_FIELD];
}EEP_TYPE_BIT_FIELD;

typedef struct eepromTemplate_struct {
    char           key[MAX_KEY_LEN];
    EEP_TYPE       type;
    int            num;
    EEP_TYPE_PRINT hex;
    char           extra[1024];
} EEPROM_TEMP;

#if 0
typedef struct _keyTempMapping {
    char key[MAX_KEY_LEN];
    char tempStr[MAX_KEY_LEN];
} KEY_TEMP_MAPPING;
 
static const KEY_TEMP_MAPPING key_template_mapping[] = {
    {"mac", "macAddr"},
    {"bd",  "bdAddr"},
    {"custData", "custData"},
};
#endif
static const char AllowedKeys[][MAX_KEY_LEN] = {
//length 
//checksum 
//"version", 
//"opCapFlags", 
//"boardFlags", 
//"regDmn", 
//"subSystemId", 
//blueToothOptions 
//binBuildNumber 
  "macAddr", 
  "bdAddr", 
//"rxMask", 
//txMask 
//"cckOfdmDelta", 
//cckDesiredScale 
  "custData", 
//futureBase 
  "antCtrlChain_a",
  "antCtrlCom1_a", 
  "antCtrlCom2_a", 
//"ob_db_a", 
//anaXtalConfig_a 
//antennaGainCh_a 
//switchSettling_a 
//swSettleHt40_a 
//xatten1Db_a 
//xatten1Margin_a 
//xatten1Hyst_a 
//xatten2Db_a 
//xatten2Margin_a 
//xatten2Hyst_a 
//adcDesiredSize_a 
//txEndToXpaOff_a 
//txEndToRxOn_a 
//txFrameToXpaOn_a 
//txFrameToDataStart_a 
//txFrameToPaOn_a 
//thresh62_a 
//noiseFloorThreshCh_a 
//rxIqCalICh_a 
//rxIqCalQCh_a 
//xpaBiasLvl_a 
//ht40PowerIncForPdadc_a 
//enableXpa_a 
//spurChan_a_0 
//spurRangeLow_a_0 
//spurRangeHigh_a_0 
//spurChan_a_1 
//spurRangeLow_a_1 
//spurRangeHigh_a_1 
//spurChan_a_2 
//spurRangeLow_a_2 
//spurRangeHigh_a_2 
//spurChan_a_3 
//spurRangeLow_a_3 
//spurRangeHigh_a_3 
//spurChan_a_4 
//spurRangeLow_a_4 
//spurRangeHigh_a_4 
//"alphaTherm_a",
//alphaThermPalOn_a 
//alphaVolt_a 
//alphaVoltPalOn_a 
//adcDesiredSizeHT40_a 
//pskDesiredScale_a 
//qamDesiredScale_a 
//futureModal_a 
  "antCtrlChain_g", 
  "antCtrlCom1_g", 
  "antCtrlCom2_g", 
//"ob_db_g", 
//anaXtalConfig_g 
//antennaGainCh_g 
//switchSettling_g 
//swSettleHt40_g 
//xatten1Db_g 
//xatten1Margin_g 
//xatten1Hyst_g 
//xatten2Db_g 
//xatten2Margin_g 
//xatten2Hyst_g 
//adcDesiredSize_g 
//txEndToXpaOff_g 
//txEndToRxOn_g 
//txFrameToXpaOn_g 
//txFrameToDataStart_g 
//txFrameToPaOn_g 
//thresh62_g 
//noiseFloorThreshCh_g 
//rxIqCalICh_g 
//rxIqCalQCh_g 
//xpaBiasLvl_g 
//ht40PowerIncForPdadc_g 
//enableXpa_g 
//spurChan_g_0 
//spurRangeLow_g_0 
//spurRangeHigh_g_0 
//spurChan_g_1 
//spurRangeLow_g_1 
//spurRangeHigh_g_1 
//spurChan_g_2 
//spurRangeLow_g_2 
//spurRangeHigh_g_2 
//spurChan_g_3 
//spurRangeLow_g_3 
//spurRangeHigh_g_3 
//spurChan_g_4 
//spurRangeLow_g_4 
//spurRangeHigh_g_4 
//"alphaTherm_g", 
//alphaThermPalOn_g 
//alphaVolt_g 
//alphaVoltPalOn_g 
//adcDesiredSizeHT40_g 
//pskDesiredScale_g 
//qamDesiredScale_g 
//futureModal_g 
//calFreqPier5G 
//calFreqPier2G 
//padding1 
  "olpcGainDelta_A_0",
//thermCalVal_A_0 
//voltCalVal_A_0 
//olpcGainDeltaPALOn_A_0 
  "olpcGainDelta_A_1", 
//thermCalVal_A_1 
//voltCalVal_A_1 
//olpcGainDeltaPALOn_A_1 
  "olpcGainDelta_A_2", 
//thermCalVal_A_2 
//voltCalVal_A_2 
//olpcGainDeltaPALOn_A_2 
  "olpcGainDelta_A_3", 
//thermCalVal_A_3 
//voltCalVal_A_3 
//olpcGainDeltaPALOn_A_3 
  "olpcGainDelta_A_4", 
//thermCalVal_A_4 
//voltCalVal_A_4 
//olpcGainDeltaPALOn_A_4 
  "olpcGainDelta_A_5", 
//thermCalVal_A_5 
//voltCalVal_A_5 
//olpcGainDeltaPALOn_A_5 
  "olpcGainDelta_A_6", 
//thermCalVal_A_6 
//voltCalVal_A_6 
//olpcGainDeltaPALOn_A_6 
  "olpcGainDelta_A_7", 
//thermCalVal_A_7 
//voltCalVal_A_7 
//olpcGainDeltaPALOn_A_7 
  "olpcGainDelta_G_0", 
//thermCalVal_G_0 
//voltCalVal_G_0 
//olpcGainDeltaPALOn_G_0 
  "olpcGainDelta_G_1", 
//thermCalVal_G_1 
//voltCalVal_G_1 
//olpcGainDeltaPALOn_G_1 
  "olpcGainDelta_G_2", 
//thermCalVal_G_2 
//voltCalVal_G_2 
//olpcGainDeltaPALOn_G_2 
//thermAdcScaledGain 
//thermAdcOffset 
//xtalCapOutDac 
//xtalCapInDac 
//refBiasTrim 
//calFuture 
//calTargetPower5G_0 
//calTargetPower5G_1 
//calTargetPower5G_2 
//calTargetPower5G_3 
//calTargetPower5G_4 
//calTargetPower5G_5 
//calTargetPower5G_6 
//calTargetPower5G_7 
//calTargetPower5GHT20_0 
//calTargetPower5GHT20_1 
//calTargetPower5GHT20_2 
//calTargetPower5GHT20_3 
//calTargetPower5GHT20_4 
//calTargetPower5GHT20_5 
//calTargetPower5GHT20_6 
//calTargetPower5GHT20_7 
//calTargetPower5GHT40_0 
//calTargetPower5GHT40_1 
//calTargetPower5GHT40_2 
//calTargetPower5GHT40_3 
//calTargetPower5GHT40_4 
//calTargetPower5GHT40_5 
//calTargetPower5GHT40_6 
//calTargetPower5GHT40_7 
//calTargetPowerCck_0 
//calTargetPowerCck_1 
//calTargetPower2G_0 
//calTargetPower2G_1 
//calTargetPower2G_2 
//calTargetPower2GHT20_0 
//calTargetPower2GHT20_1 
//calTargetPower2GHT20_2 
//calTargetPower2GHT40_0 
//calTargetPower2GHT40_1 
//calTargetPower2GHT40_2 
//padding2 
//ctlIndex 
//padding3 
//ctlEdges_0_0 
//ctlEdges_0_1 
//ctlEdges_0_2 
//ctlEdges_0_3 
//ctlEdges_0_4 
//ctlEdges_0_5 
//ctlEdges_0_6 
//ctlEdges_0_7 
//ctlEdges_1_0 
//ctlEdges_1_1 
//ctlEdges_1_2 
//ctlEdges_1_3 
//ctlEdges_1_4 
//ctlEdges_1_5 
//ctlEdges_1_6 
//ctlEdges_1_7 
//ctlEdges_2_0 
//ctlEdges_2_1 
//ctlEdges_2_2 
//ctlEdges_2_3 
//ctlEdges_2_4 
//ctlEdges_2_5 
//ctlEdges_2_6 
//ctlEdges_2_7 
//ctlEdges_3_0 
//ctlEdges_3_1 
//ctlEdges_3_2 
//ctlEdges_3_3 
//ctlEdges_3_4 
//ctlEdges_3_5 
//ctlEdges_3_6 
//ctlEdges_3_7 
//ctlEdges_4_0 
//ctlEdges_4_1 
//ctlEdges_4_2 
//ctlEdges_4_3 
//ctlEdges_4_4 
//ctlEdges_4_5 
//ctlEdges_4_6 
//ctlEdges_4_7 
//ctlEdges_5_0 
//ctlEdges_5_1 
//ctlEdges_5_2 
//ctlEdges_5_3 
//ctlEdges_5_4 
//ctlEdges_5_5 
//ctlEdges_5_6 
//ctlEdges_5_7 
//ctlEdges_6_0 
//ctlEdges_6_1 
//ctlEdges_6_2 
//ctlEdges_6_3 
//ctlEdges_6_4 
//ctlEdges_6_5 
//ctlEdges_6_6 
//ctlEdges_6_7 
//ctlEdges_7_0 
//ctlEdges_7_1 
//ctlEdges_7_2 
//ctlEdges_7_3 
//ctlEdges_7_4 
//ctlEdges_7_5 
//ctlEdges_7_6 
//ctlEdges_7_7 
//ctlEdges_8_0 
//ctlEdges_8_1 
//ctlEdges_8_2 
//ctlEdges_8_3 
//ctlEdges_8_4 
//ctlEdges_8_5 
//ctlEdges_8_6 
//ctlEdges_8_7 
//ctlEdges_9_0 
//ctlEdges_9_1 
//ctlEdges_9_2 
//ctlEdges_9_3 
//ctlEdges_9_4 
//ctlEdges_9_5 
//ctlEdges_9_6 
//ctlEdges_9_7 
//ctlEdges_10_0 
//ctlEdges_10_1 
//ctlEdges_10_2 
//ctlEdges_10_3 
//ctlEdges_10_4 
//ctlEdges_10_5 
//ctlEdges_10_6 
//ctlEdges_10_7 
//ctlEdges_11_0 
//ctlEdges_11_1 
//ctlEdges_11_2 
//ctlEdges_11_3 
//ctlEdges_11_4 
//ctlEdges_11_5 
//ctlEdges_11_6 
//ctlEdges_11_7 
//ctlEdges_12_0 
//ctlEdges_12_1 
//ctlEdges_12_2 
//ctlEdges_12_3 
//ctlEdges_12_4 
//ctlEdges_12_5 
//ctlEdges_12_6 
//ctlEdges_12_7 
//ctlEdges_13_0 
//ctlEdges_13_1 
//ctlEdges_13_2 
//ctlEdges_13_3 
//ctlEdges_13_4 
//ctlEdges_13_5 
//ctlEdges_13_6 
//ctlEdges_13_7 
//ctlEdges_14_0 
//ctlEdges_14_1 
//ctlEdges_14_2 
//ctlEdges_14_3 
//ctlEdges_14_4 
//ctlEdges_14_5 
//ctlEdges_14_6 
//ctlEdges_14_7 
//ctlEdges_15_0 
//ctlEdges_15_1 
//ctlEdges_15_2 
//ctlEdges_15_3 
//ctlEdges_15_4 
//ctlEdges_15_5 
//ctlEdges_15_6 
//ctlEdges_15_7 
//ctlEdges_16_0 
//ctlEdges_16_1 
//ctlEdges_16_2 
//ctlEdges_16_3 
//ctlEdges_16_4 
//ctlEdges_16_5 
//ctlEdges_16_6 
//ctlEdges_16_7 
//ctlEdges_17_0 
//ctlEdges_17_1 
//ctlEdges_17_2 
//ctlEdges_17_3 
//ctlEdges_17_4 
//ctlEdges_17_5 
//ctlEdges_17_6 
//ctlEdges_17_7 
//ctlEdges_18_0 
//ctlEdges_18_1 
//ctlEdges_18_2 
//ctlEdges_18_3 
//ctlEdges_18_4 
//ctlEdges_18_5 
//ctlEdges_18_6 
//ctlEdges_18_7 
//ctlEdges_19_0 
//ctlEdges_19_1 
//ctlEdges_19_2 
//ctlEdges_19_3 
//ctlEdges_19_4 
//ctlEdges_19_5 
//ctlEdges_19_6 
//ctlEdges_19_7 
//ctlEdges_20_0 
//ctlEdges_20_1 
//ctlEdges_20_2 
//ctlEdges_20_3 
//ctlEdges_20_4 
//ctlEdges_20_5 
//ctlEdges_20_6 
//ctlEdges_20_7 
};
static const int NumOfAllowedKeys = sizeof(AllowedKeys)/MAX_KEY_LEN;

extern int MaxTempEntries;
extern EEPROM_TEMP EepTempEntries[];
extern int EepTempEntryPos[MAX_TEMPLATE_ENTRIES];

//
// eepromUtil_1.c - Function prototypes
//

//extern int _eepromBin2Txt(int argc, char *argv[]);
//extern void supportedFields(void);
extern EEPROMUTILDLLSPEC A_BOOL genEepromBinFile(char *fileName, A_UINT8 *pData, A_UINT16 length, A_UINT16 *checkSum);
extern EEPROMUTILDLLSPEC A_BOOL genEepromTemplateHFile(char *fileName, A_UINT8 *pData, A_UINT16 length, A_UINT16 *checkSum);
extern EEPROMUTILDLLSPEC A_BOOL readCalDataFromFileBin(char *fileName, A_UCHAR *pData, A_UINT16 length);
extern EEPROMUTILDLLSPEC A_BOOL readTemplate(char *fileName);


//
// eepromBin2Txt_gen.c - Function prototypes
//
extern EEPROMUTILDLLSPEC A_BOOL parseBin(A_UINT8 *pData, int numBytes, char *fileName); 


//
// eepromTxt2Bin_gen.c - Function prototypes
//
extern EEPROMUTILDLLSPEC A_BOOL parseEepromTxtFile(char *fileName, A_UINT8 *pData, A_UINT16 length);

#endif //#if !defined(_EEPROMUTIL_H)

