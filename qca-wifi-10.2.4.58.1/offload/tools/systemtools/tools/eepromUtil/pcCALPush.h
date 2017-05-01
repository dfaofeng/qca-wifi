#if !defined(_PCCALPUSH_H)
#define  _PCCALPUSH_H 
  
// defines
#define uiPrintf printf
#define OTPSTREAM_MAXSZ_APP 256

typedef enum {
    _RESERVED=0,
    _CHANNEL,
    _MASK,
    _PWR,
} TESTFLOW_PARSER_STATE;

#define PCDAC_PHASE  77
typedef struct _curParsingData {
    TESTFLOW_PARSER_STATE parserState;
    A_UINT32 curChannel;
    A_UINT32 curChannelIdx;
    A_UINT32 curMask;
    A_UINT32 curMaskRead;
    A_UINT32 curMode;
} _CUR_PARSING_DATA;

typedef enum {
    _OTA_RATE_1 =0,
    _OTA_RATE_2L,
    _OTA_RATE_2S,
    _OTA_RATE_5_5L,
    _OTA_RATE_5_5S,
    _OTA_RATE_11L,
    _OTA_RATE_11S,
    _OTA_RATE_UNUSED,
    _OTA_RATE_6,
    _OTA_RATE_9,
    _OTA_RATE_12,
    _OTA_RATE_18,
    _OTA_RATE_24,
    _OTA_RATE_36,
    _OTA_RATE_48,
    _OTA_RATE_54,
    _OTA_RATE_MCS0_HT20,
    _OTA_RATE_MCS1_HT20,
    _OTA_RATE_MCS2_HT20,
    _OTA_RATE_MCS3_HT20,
    _OTA_RATE_MCS4_HT20,
    _OTA_RATE_MCS5_HT20,
    _OTA_RATE_MCS6_HT20,
    _OTA_RATE_MCS7_HT20,
    _OTA_RATE_MCS0_HT40,
    _OTA_RATE_MCS1_HT40,
    _OTA_RATE_MCS2_HT40,
    _OTA_RATE_MCS3_HT40,
    _OTA_RATE_MCS4_HT40,
    _OTA_RATE_MCS5_HT40,
    _OTA_RATE_MCS6_HT40,
    _OTA_RATE_MCS7_HT40,

    _OTA_RATE_LAST,
} _OTA_RATES;

typedef enum {
    _OTA_MODE_NULL=255,
    _OTA_MODE_11G=0,
    _OTA_MODE_11A,

    _OTA_MODE_LAST,
} _OTA_MODE;



#define  NUM_CAL_2G_CHANNELS 16   //?tbd
#define  NUM_CAL_5G_CHANNELS (32*2)   //?tbd

typedef struct rawPerChanCalDataOlpc {
    A_INT16  olpc_gain_delta_t10;
    A_INT8   olpc_gain_delta;
    A_UINT8  therm_cal_value;
    A_UINT8  volt_cal_value;
    A_UINT8  desired_scale_cck;
    A_UINT8  desired_scale_psk;
    A_UINT8  desired_scale_qam;
    A_UINT8  desired_scale_bpsk;
    A_UINT8  desired_scale_qpsk;
    A_UINT8  desired_scale_qam16;
    A_UINT8  desired_scale_qam64;
    A_UINT8  desired_scale_1m;
    A_UINT8  desired_scale_11m;
    A_UINT8  desired_scale_6m;
    A_UINT8  desired_scale_36m;
    A_UINT8  desired_scale_54m;
    A_UINT8  desired_scale_mcs0ht20;
    A_UINT8  desired_scale_mcs7ht20;
    A_UINT8  desired_scale_mcs0ht40;
    A_UINT8  desired_scale_mcs7ht40;

    A_UINT8  desiredScale[_OTA_RATE_LAST];
} RAW_PER_CHAN_CALDATA_OLPC;

// hold the power data from LP

// for code reuse purpose
typedef struct rawCalDataOlpc {
    A_UINT16                  *pChannels;
    A_UINT16                  numChannels;
    RAW_PER_CHAN_CALDATA_OLPC *pPerChanDataPALOff;
    RAW_PER_CHAN_CALDATA_OLPC *pPerChanDataPALOn;
} RAW_CAL_DATA_OLPC;

#define CAL_MAX_MODE  2
extern RAW_CAL_DATA_OLPC RawCalData[CAL_MAX_MODE];

/*
typedef struct _measuredPwr {
    // settings
    A_UINT32      num2GChan;
    A_UINT32      num5GChan;
    A_UINT32      num2GChanReal;
    A_UINT32      num5GChanReal;    
    A_UINT32      desiredScale6M_2G;
    A_UINT32      desiredScale6M_5G;
    A_UINT32      rateMask2G[NUM_CAL_2G_CHANNELS];
    A_UINT32      rateMask5G[NUM_CAL_5G_CHANNELS];
    A_INT16       channel2G[NUM_CAL_2G_CHANNELS];
    A_INT16       channel5G[NUM_CAL_5G_CHANNELS];
    A_UINT8       pcDac2G[NUM_CAL_2G_CHANNELS][_OTA_RATE_LAST];
    A_UINT8       pcDac5G[NUM_CAL_5G_CHANNELS][_OTA_RATE_LAST];

    // measurement
    A_INT16       txPwr2G[NUM_CAL_2G_CHANNELS][_OTA_RATE_LAST];
    A_INT16       txPwr5G[NUM_CAL_5G_CHANNELS][_OTA_RATE_LAST];

    // outcome 
    RAW_PER_CHAN_CALDATA_OLPC perChanData2G[NUM_CAL_2G_CHANNELS];
    RAW_PER_CHAN_CALDATA_OLPC perChanData5G[NUM_CAL_5G_CHANNELS];

} _MEASURED_PWR;
*/

#define PCDAC_MIN                       0
#define PCDAC_MAX                       150

typedef struct _paramPerPcdac{
  A_UINT8 pcdac;
  A_INT16 txPower;
}_PARAMPERPCDAC;

typedef struct _paramPerRate{
  A_UINT32 pcdacNum;
  _PARAMPERPCDAC param[PCDAC_MAX];
}_PARAMPERRATE;

typedef struct _paramPerCH{
  A_UINT32 rateMask;
  _PARAMPERRATE param_rate[_OTA_RATE_LAST];
}_PARAMPERCH;

typedef struct _paramPerMODE{
  A_UINT32 numChan;  
  A_UINT16 channel_val[NUM_CAL_5G_CHANNELS];
  A_UINT32 desiredScale6M;
  _PARAMPERCH paramPerCh[NUM_CAL_5G_CHANNELS]; //it's not only 5G channel, just make the MAX space of array
  RAW_PER_CHAN_CALDATA_OLPC perChanData[NUM_CAL_5G_CHANNELS];
}_PARAMPERMODE;

typedef struct _measuredPwr{
    _PARAMPERMODE       A_MODE;
    _PARAMPERMODE       G_MODE;
}_MEASURED_PWR;



typedef struct _pcdacPerRate{
    A_UINT8 pcdac_start; 
    A_UINT8 pcdac_end;
}_PCDACPERRATE;

typedef struct _pcdacPerCh{
    A_UINT32 ch_val;
    _PCDACPERRATE rate[_OTA_RATE_LAST];
}_PCDACPERCH;

typedef struct _pcdacPerMode{
 A_UINT32 ch_num;
 _PCDACPERCH ch[NUM_CAL_5G_CHANNELS];  //it's not only 5G channel, just make the MAX space of array
}_PCDACPERMODE;
    
typedef struct _configPcdac{
    _PCDACPERMODE       A_MODE;
    _PCDACPERMODE       G_MODE;
}_CONFIGPCDAC;

// function definitions
#define HT40_PWR_DELTA  5

typedef enum {
    TPC_VER_NOT_SUPPORTED=0,    
    TPC_VER1,
    TPC_VER2
} TPC_VERSION;


// Read test flow file 
#define LINEBUF_SIZE 256
#define KEY_SIZE_MAX 64

// declaration
extern TPC_VERSION tpcVersion;

// command structure: cmdOpcode(1B) cmdNumParms(1B) parm1(6B)
//
// command opcodes
typedef enum {
    _OP_TEST_CONFIG = 255,
    _OP_SYNC = 0,               // 0
    _OP_TX,                     // 1
    _OP_RX,                     // 2
    _OP_CAL,                    // 3
    _OP_CAL_DONE,               // 4
    _OP_TESTSCRIPT_LAST,        // 5, basically the size of testscript I/F cmds

    _OP_REMAINING = _OP_TESTSCRIPT_LAST,
    _OP_SLEEP,
    _OP_RESET,
    _OP_OTP,
    _OP_EEPROM,
    _OP_READ_REG,
    _OP_WRITE_REG,
    _OP_READ_MEM,
    _OP_WRITE_MEM,    

    _OP_MAX,
} _CMD_OPCODES;

#define USUAL_ROOM_TEMP   0x7f
#define USUAL_ROOM_VOLT   0x64
#define DEFAULT_MAX_MEASPWR_GOOD 31
#define DEFAULT_MIN_MEASPWR_GOOD 20

typedef struct __PCCALPUSH_CONFIG{
    A_UINT8 thermal_value;
    A_UINT8 volt_value;
    A_INT32 maxMeasPwrGood;
    A_INT32 minMeasPwrGood;
}PCCALPUSH_CONFIG;


#endif //#if !defined(_PCCALPUSH_H)


