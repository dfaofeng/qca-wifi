/* usb_pm.h - contians function definitions for using rhode and schwarz usb power meter */
/* Copyright (c) 2003 Atheros Communications, Inc., All Rights Reserved */

#if !defined(AFX_EXPORTFUNCS_H__85659BD7_94B9_4086_B156_6FA146D9C357__INCLUDED_)
#define AFX_EXPORTFUNCS_H__85659BD7_94B9_4086_B156_6FA146D9C357__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



/***************************************************************************
macros
CREATED:     14.12.2000
LAST CHANGE: 26.08.2001
***************************************************************************/
#ifdef NRP_DLL
#define DllExport(tp) tp EXPORT __stdcall
#else
#define DllExport(tp) extern tp __stdcall
#endif

// device event notification codes (from dbt.h)
#define DBT_DEVNODES_CHANGED            0x0007
#define DBT_DEVICEARRIVAL               0x8000  // system detected a new device
#define DBT_DEVICEQUERYREMOVE           0x8001  // wants to remove, may fail
#define DBT_DEVICEQUERYREMOVEFAILED     0x8002  // removal aborted
#define DBT_DEVICEREMOVEPENDING         0x8003  // about to remove, still avail.
#define DBT_DEVICEREMOVECOMPLETE        0x8004  // device is gone
#define DBT_DEVICETYPESPECIFIC          0x8005  // type specific event
#if(WINVER >= 0x040A)
#define DBT_CUSTOMEVENT                 0x8006  // user-defined event
#endif /* WINVER >= 0x040A */


/***************************************************************************
typedefs
CREATED:       31.01.2001
LAST CHANGE:   26.01.2002
***************************************************************************/
typedef void (__stdcall * function)(void* arg1, void* arg2);


typedef struct   // Ergebnisstruktur, die die DeviceChanged - Callbackfunktion als Argument übergibt.
{
  long  wResult;
  long  wEventType;
  long  wEventTextHandle;
  char  *pEventText;
  char  *pDeviceName;
} USB_DEVICECHANGED_HANDLER_RESULT;


/***************************************************************************
Erweiterung von NRPERROR
last change:   28.03.2001
***************************************************************************/
typedef enum
{
    /****************************************************************/
    /* nonfatal errors                                              */
    /****************************************************************/
    NRPERROR_NOERROR = 0,           /*  0  */
    NRPERROR_CALDATA_FORMAT,        /*  1  */
    NRPERROR_OVERRANGE,             /*  2  */
    NRPERROR_NOTINSERVICEMODE,      /*  3  */
    NRPERROR_CALZERO,               /*  4  */
    NRPERROR_TRIGGERQUEUEFULL,      /*  5  */
    NRPERROR_EVENTQUEUEFULL,        /*  6  */
    NRPERROR_SAMPLEERROR,           /*  7  */
    NRPERROR_OVERLOAD,              /*  8  */
    NRPERROR_HARDWARE,              /*  9  */
    NRPERROR_CHECKSUM,              /* 10  */
    NRPERROR_ILLEGALSERIAL,         /* 11  */
    NRPERROR_FILTERTRUNCATED,	      /* 12  */
    NRPERROR_BURST_TOO_SHORT,       /* 13  */
    
    NONFATAL_ERRORCODE_LIMIT = 0x7F, /* max allowed error number nonfatal errors*/

    /****************************************************************/
    /* fatal errors                                                 */
    /****************************************************************/
    NRPERROR_GENERIC,           /* 0x80  */
    NRPERROR_OVERMAX,           /* 0x81  */
    NRPERROR_UNDERMIN,          /* 0x82  */
    NRPERROR_VOLTAGE,           /* 0x83  */ 
    NRPERROR_SYNTAX,            /* 0x84  */
    NRPERROR_MEMORY,            /* 0x85  */
    NRPERROR_PARAMETER,         /* 0x86  */
    NRPERROR_TIMING,            /* 0x87  */
    NRPERROR_NOTIDLE,           /* 0x88  */
    NRPERROR_UNKNOWNCOMMAND,    /* 0x89  */
    NRPERROR_OUTBUFFERFULL,     /* 0x8a  */
    NRPERROR_FLASHPROG,         /* 0x8b  */
    NRPERROR_CALDATANOTPRESENT, /* 0x8c  */

    FATAL_ERRORCODE_LIMIT = 0x9F,    /* max allowed error number nonfatal errors*/

} NRPERROR;


typedef enum
{
  NRPERROR_BLOCKMISSING =  0xa0,
  NRPERROR_DEVICENOTOPEN,
  NRPERROR_SENDCOMMAND,
  NRPERROR_UNKNOWNERROR
} NRPERROR_EXT;


/***************************************************************************
Erweiterung von SENSORHW_STATE
LAST CHANGE: 28.03.2001
***************************************************************************/
typedef enum
{
  SENSORHW_STATE_IDLE,              /* 0 */
  SENSORHW_STATE_WAIT_FOR_ARM,      /* 1 */
  SENSORHW_STATE_WAIT_FOR_TRIGGER,  /* 2 */
  SENSORHW_STATE_MEASURING,         /* 3 */
  /*-------------------------------------*/
  SENSORHW_STATE_Count              /* 4 */
} SENSORHW_STATE;


typedef enum
{
  /* device notification states ---------*/
  SENSORHW_STATE_DEVICEARRIVAL = SENSORHW_STATE_Count + 1,
  SENSORHW_STATE_DEVICEQUERYREMOVE      ,
  SENSORHW_STATE_DEVICEQUERYREMOVEFAILED,
  SENSORHW_STATE_DEVICEREMOVEPENDING    ,
  SENSORHW_STATE_DEVICEREMOVECOMPLETE   ,
  SENSORHW_STATE_DEVICETYPESPECIFIC     ,
  SENSORHW_STATE_DEVICECUSTOMEVENT      ,
  SENSORHW_STATE_DEVICEUSERDEFINED      ,
  SENSORHW_STATE_DEVICECHANGED          ,

  SENSORHW_STATE_DEVICEUNKNOWN          ,


  /*-------------------------------------*/
  SENSORHW_STATE_EXT_Count
} SENSORHW_STATE_EXT;


typedef enum
{
  GET_DLSTAT_FINISHED = 1,
  GET_DLSTAT_CSOK
} GET_DLSTAT_INDEX;


typedef enum
{
  DATA_BINARYBLOCK,
  DATA_BITFIELDLIMIT,
  DATA_BITFIELDPARAM,
  DATA_BITFIELDFEATURE,
  DATA_FLOATARRAY,
  DATA_FLOATLIMIT,
  DATA_FLOATPARAM,
  DATA_FLOATRESULT,
  DATA_LONGLIMIT,
  DATA_LONGPARAM,
  DATA_STRING,
  DATA_NROF
} DATA_TYPE;


/***************************************************************************
function definitions
CREATED:     26.01.2001
LAST CHANGE: 27.01.2002
***************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

// USB specific commands

DllExport(long)   NrpGetDeviceID(void);
DllExport(long)   NrpGetIDByLogicalName(const char *i_pcLogicalName);
DllExport(long)   NrpGetLogicalName(long i_wID, char *o_pcBuf, long i_wCount);
DllExport(long)   NrpGetManufacturerCode(long i_wID, char *o_pcBuf, long i_wCount);
DllExport(long)   NrpGetNrOfDevices(void);
DllExport(long)   NrpGetProductID(long i_wID, char *o_pBuf, long i_wCount);
DllExport(long)   NrpGetSerialNumber(long i_wID, char *o_pcBuf, long i_wCount);
DllExport(void)   NrpOpenDriver(void);
DllExport(long)   NrpSelectDevice(long i_wID);
DllExport(void)   NrpCloseDriver(void);

DllExport(long)   NrpSendVendorInRequest(char *o_pcBuf, long i_wCount, long i_wRequest, long i_wIndex);
DllExport(long)   NrpSendVendorOutRequest(long i_wRequest, long i_wIndex, long i_wValue);

// USB standard device request
DllExport(long)   NrpSDRGetDescriptor(void *o_pBuffer, long *io_wByteCount, long i_wRecipient, long i_wDescrType, long i_wDescrIndex, long i_wLangID);

// Universal Interface
DllExport(long)   NrpDataAvailable(void);
DllExport(long)   NrpGetBinaryResultLength(void) ;
DllExport(long)   NrpGetBinaryResult(unsigned char *o_pBuf,long i_wCount);
DllExport(long)   NrpGetBitfieldResult (long  *o_pdwR1, long  *o_pdwR2, long  *o_pdwR3);
DllExport(long)   NrpGetErrorText(long i_wErr,char *o_pBuf, long i_wCount);
DllExport(long)   NrpGetFloatArray(float *o_pFarr , long *o_pwIarr, long i_wCount);
DllExport(long)   NrpGetFloatArrayLength(void);
DllExport(long)   NrpGetFloatResult(float *o_pfR1, float *o_pfR2, float *o_pfR3);
DllExport(long)   NrpGetLastError(void); 
DllExport(long)   NrpGetLongResult (long  *o_pwR1, long  *o_pwR2, long  *o_pwR3);
DllExport(long)   NrpGetStringResult(char *o_pcBuf,long i_wCount);
DllExport(long)   NrpGetTriggerState(void);
DllExport(long)   NrpGetTriggerStateText(long i_wState, char *o_pBuf, long i_wCount);
DllExport(long)   NrpIsAlive(void);
DllExport(long)   NrpSendCommand(const char *i_pcCommand,long i_wTimeoutMs);
DllExport(void)   NrpChannelAssignment(void);
DllExport(void)   NrpClearDevice(void);
DllExport(void)   NrpEmptyAllBuffers(void);
DllExport(void)   NrpEmptyErrorQueue(void);
DllExport(void)   NrpGetData(long *o_pBlockType, long *o_pGroupNr, long *o_pParamNr);
DllExport(void)   NrpMessageLoopBody(void);
DllExport(void)   NrpSendBinaryBlock(const char *i_pcCommand, void *o_pBuf, long i_wCount);
DllExport(void)   NrpStartApplicationMode(void);
DllExport(void)   NrpStartFlashupMode(void);

// Callback setting functions
DllExport(void)   NrpSetNotifyCallbackCommandAccepted (function i_pF ,void *i_pArg);
DllExport(void)   NrpSetNotifyCallbackDataAvailable   (function i_pF ,void *i_pArg);
DllExport(void)   NrpSetNotifyCallbackErrorOccurred   (function i_pF ,void *i_pArg);
DllExport(void)   NrpSetNotifyCallbackStateChanged    (function i_pF ,void *i_pArg);
DllExport(void)   NrpSetNotifyCallbackDeviceChanged   (function i_pF ,void *i_pArg);
DllExport(long)   NrpGetDeviceChangedMsgText          (long i_wEventTextHandle, char *o_pcBuf, long i_wCount);
DllExport(long)   NrpGetDeviceChangedDevName          (char *o_pcBuf, long i_wCount); 

int reset_nrp (void);
float aquire_data();



#ifdef __cplusplus
}
#endif

#endif // !defined(AFX_EXPORTFUNCS_H__85659BD7_94B9_4086_B156_6FA146D9C357__INCLUDED_)

