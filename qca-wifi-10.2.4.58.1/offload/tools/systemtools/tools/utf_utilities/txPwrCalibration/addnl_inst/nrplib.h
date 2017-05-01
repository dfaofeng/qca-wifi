/***************************************************************************
 *
 * Company: Rohde & Schwarz
 *
 * Project: NrpControl2.dll port for linux
 *
 * $Workfile: nrplib.h $
 *
 * Author: Stefani Seibold
 *
 * Date of creation: 26.05.2006
 *
 ***************************************************************************/

#ifndef	__NRPLIB_H__
#define	__NRPLIB_H__

#include "nrpdef.h"

#ifdef __cplusplus
extern "C" {
#endif

extern long GetRootHubCount(void);
extern long GetHubPortCount(long HubIndex);
extern long GetPortResource(long HubIndex,long PortIndex,char* Resource);

extern long NrpOpenDriver(void);
extern long NrpCloseDriver(void);
extern long NrpLockDeviceList(void);
extern long NrpGetDeviceListLength(long *pLength);
extern long NrpGetDeviceInfo(long index,char name[],char type[],char serial[],long *pIsConnected);
extern long NrpGetResourceName(long index,char resource[],unsigned int maxLen);
extern long NrpOpenSensor(const char *resourceDescriptor,long *pHandle);
extern long NrpCloseSensor(long session);
extern long NrpGetSensorInfo(long session,char name[],char type[],char serial[]);
extern long NrpSendCommand(long session,const char *command,long timeout);
extern long NrpGetData(long session,long *pBlockType,long *pGroupNr,long *paramNr);
extern long NrpGetFloatArray(long session,float *pArray,long arraysize,long *pReadCount);
extern long NrpGetFloatArrayLength(long session,long *size);
extern long NrpGetAuxFloatArray(long session,float *pArray,float *pAux1,float *pAux2,long arraysize,long *pReadCount);
extern long NrpGetAuxFloatArrayLength(long session,long *size);
extern long NrpGetFloatResult(long session,float *pFloatVal1,float *pFloatVal2,float *pFloatVal3);
extern long NrpGetLongResult(long session,long *pLongVal1,long *pLongVal2,long *pLongVal3);
extern long NrpGetBitfieldResult(long session,long *pBitVal1,long *pBitVal2,long *pBitVal3);
extern long NrpGetStringResultLength(long session,long *size);
extern long NrpGetStringResult(long session,char *pBuffer,long size);
extern long NrpGetBinaryResultLength(long session,long *size);
extern long NrpGetBinaryResult(long session,unsigned char *pBuffer,long buflen,long *size);
extern long NrpEmptyAllBuffers(long session);
extern long NrpGetTriggerState(long session,long *state);
extern long NrpGetError(long session,long *pError);
extern long NrpEmptyErrorQueue(long session);
extern long NrpGetErrorText(long errorcode,char pBuffer[],long size);
extern long NrpClearDevice(long session);
extern long NrpDataAvailable(long session,long *pDataCount);
extern long NrpCommitDeviceList(void);
extern long NrpSendBinaryBlock( long session, const char *command, void *pBuffer, long count, long timeout );

/** Registers the callback for command accepted event. */
extern long NrpSetNotifyCallbackCommandAccepted(Nrp_CommandAcceptedFuncPtr callbackPtr, long usrArgument);

/** Registers the callback for data available event. */
extern long NrpSetNotifyCallbackDataAvailable(Nrp_DataAvailableFuncPtr callbackPtr,long usrArgument);

/** Registers the callback for error occured event. */
extern long NrpSetNotifyCallbackErrorOccurred(Nrp_ErrorOccurredFuncPtr callbackPtr,long usrArgument);

/** Registers the callback for state changed event. */
extern long NrpSetNotifyCallbackStateChanged(Nrp_StateChangedFuncPtr callbackPtr,long usrArgument);

/** Registers the callback for device changed event. */
extern long NrpSetNotifyCallbackDeviceChanged(Nrp_DeviceChangedFuncPtr callbackPtr,long usrArgument);

/** Registers the callback for still alive events. */
extern long NrpSetNotifyCallbackStillAlive(Nrp_StillAliveFuncPtr callbackPtr,long usrArgument);

/** translate a given numeric state into a text string. */
extern long NrpGetTriggerStateText(long state,char *pBuffer[],long size);


/** Sets a specified attribute for given object. */
extern long NrpSetAttribute(long session,unsigned long attrName,long attrValue);

/** Queries the specified attribute for a given object. */
extern long NrpGetAttribute(long session,unsigned long attrName,void* pAttrValue);

extern long NrpSendVendorOutRequest( long session, long request, long index, long value );

#if 0
extern long NrpSetDeviceInfo(long index,char *pname,char *ptype,char *pserial);
extern long NrpAddDeviceInfo(const char *pname,const char *ptype,const char *pserial);
extern long NrpDeleteDeviceInfo(long index);
extern long NrpSendVendorInRequest(long session,char *pBuffer,long count,long request,long index);
#endif

//extern long NrpSDRGetDescriptor(long session,void *pBuffer,long *pByteCount,long recipient,long descrType,long descrIndex,long langID);

//void __stdcall CommmandAcceptedCallback(long session,long i_grp_par,long i_usr_arg);
//void __stdcall DataAvailableCallback(long session,long i_cbarg,long i_usr_arg);
//void __stdcall ErrorOccurredCallback(long session,long i_error,long i_usr_arg);
//void __stdcall StateChangedCallback(long session,long i_sensorstate,long i_usr_arg);
//void __stdcall DeviceChangedCallback(long i_usr_arg);

#ifdef __cplusplus
}
#endif

#endif

/* vi:set ts=4 sw=4: */

