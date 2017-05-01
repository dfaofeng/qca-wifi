/*
 *  Copyright (c) 2011, Atheros Communications Inc.
 *  $ATH_LICENSE_TARGET_C$
 */

#ifndef QMF_H
#define QMF_H

typedef unsigned char  	UINT8;
typedef unsigned short 	UINT16;
typedef unsigned int 	UINT32;
typedef int             BOOL;
typedef int             INT32;
typedef UINT32  TARGET_PTR; /*Based on, target pointer size*/

#define MAC_ADDR_SIZE 6 

typedef enum {
     _WAL_EOK          = 0,        /* No error */
     _WAL_ENXIO        = 1,        /* requested object not present  */
     _WAL_ENOMEM       = 2,        /* Memory allocation failed */
     _WAL_EINVAL       = 3,        /* Invalid parameter to function */
     _WAL_ENOTSUPP     = 4,        /* requested operation not supported */
     _WAL_EINPROGRESS  = 5,        /* Operation in progress */
     _WAL_EBUSY        = 6,        /* module is busy */
     _WAL_EEXIST       = 7,        /* requested object not present  */
     _WAL_ENOSPC       = 8,        /* no space left  */
     _WAL_ASYNC        = 9,        /* requested operation started and completes asynchronously  */
} _WAL_STATUS;


/* QVIT Message Code Enumeration */
typedef enum { 
/* SYNCHRONUS Message Codes Start here
   Request and Response Message Codes are always back-to-back 
   in enum listing. 
*/

    /* Messaging between DE, HA 
    Evironments (DE, HA) need to process each (REQ, RSP) pair
    */
    QVIT_MSG_SYNC_DE_HA_START,
 
    QVIT_MSG_SYS_INQUIRE_REQ = QVIT_MSG_SYNC_DE_HA_START, //MsgStruct: QVIT_Msg_Sys_Inquire_Req
    QVIT_MSG_SYS_INQUIRE_RSP,
 
    QVIT_MSG_SYS_CONNECT_REQ,                             //MsgStruct: QVIT_Msg_Sys_Connect_Req
    QVIT_MSG_SYS_CONNECT_RSP,
 
    QVIT_MSG_STREAM_CONFIG_REQ,                           //MsgStruct: QVIT_Msg_Stream_Config_Req
    QVIT_MSG_STREAM_CONFIG_RSP,
 
    QVIT_MSG_STREAM_DESTROY_REQ,                          //MsgStruct: QVIT_Msg_Stream_Destroy_Req
    QVIT_MSG_STREAM_DESTROY_RSP,
 
    QVIT_MSG_STREAM_START_STOP_REQ,                       //MsgStruct: QVIT_Msg_Stream_Start_Stop_Req
    QVIT_MSG_STREAM_START_STOP_RSP,

    QVIT_MSG_SETUP_BEACON_BUFFER_REQ,                     //MsgStruct: QVIT_Msg_Setup_Beacon_Buffer_Req  
    QVIT_MSG_SETUP_BEACON_BUFFER_RSP,

    QVIT_MSG_SYS_DISCONNECT_REQ,                             //MsgStruct: QVIT_Msg_Sys_DisConnect_Req
    QVIT_MSG_SYS_DISCONNECT_RSP,

    QVIT_MSG_SYNC_DE_HA_END,

   /* Messaging between DE, FA 
   Environments (DE,FA) need to process each (REQ, RSP) pair
   */

    QVIT_MSG_SYNC_DE_FA_START,

    QVIT_MSG_READ_REGISTER_REQ = QVIT_MSG_SYNC_DE_FA_START, //MsgStruct: QVIT_Msg_Read_Register_Req
    QVIT_MSG_READ_REGISTER_RSP,

    QVIT_MSG_WRITE_REGISTER_REQ,                            //MsgStruct: QVIT_Msg_Write_Register_Req
    QVIT_MSG_WRITE_REGISTER_RSP,

    QVIT_MSG_READ_MEMORY_REQ,                               //MsgStruct: QVIT_Msg_Read_Memory_Req
    QVIT_MSG_READ_MEMORY_RSP,
    
    QVIT_MSG_WRITE_MEMORY_REQ,                              //MsgStruct: QVIT_Msg_Write_Memory_Req
    QVIT_MSG_WRITE_MEMORY_RSP,

    /* WAL VDEV Messages */    
    QVIT_MSG_WAL_VDEV_UP_REQ,                                    //MsgStruct: QVIT_Msg_Wal_VDEV_Up_Req
    QVIT_MSG_WAL_VDEV_UP_RSP,

    QVIT_MSG_WAL_VDEV_DOWN_REQ,                                  //MsgStruct: QVIT_Msg_Wal_VDEV_Down_Req
    QVIT_MSG_WAL_VDEV_DOWN_RSP,

    QVIT_MSG_WAL_VDEV_STOP_REQ,                                  //MsgStruct: QVIT_Msg_Wal_VDEV_Stop_Req
    QVIT_MSG_WAL_VDEV_STOP_RSP,
    
    QVIT_MSG_WAL_VDEV_START_REQ,                                  //MsgStruct: QVIT_Msg_Wal_VDEV_Start_Req
    QVIT_MSG_WAL_VDEV_START_RSP,

    QVIT_MSG_WAL_VDEV_SET_INPUT_DATA_PKT_TYPE_REQ,               //MsgStruct: QVIT_Msg_Wal_VDEV_Set_Input_Data_Pkt_Type_Req
    QVIT_MSG_WAL_VDEV_SET_INPUT_DATA_PKT_TYPE_RSP,

    QVIT_MSG_WAL_PEER_SET_PARAM_REQ,                             // MsgStruct:  QVIT_Msg_Wal_Peer_Set_Param_Req
    QVIT_MSG_WAL_PEER_SET_PARAM_RSP,                        

    QVIT_MSG_WAL_PEER_SET_KEY_REQ,                              // MsgStruct: QVIT_Msg_Wal_Peer_Set_Key_Req
    QVIT_MSG_WAL_PEER_SET_KEY_RSP,

    QVIT_MSG_WAL_PDEV_SET_PARAM_REQ,                            //MsgStruct: QVIT_Msg_Wal_PDev_Set_Param_Req
    QVIT_MSG_WAL_PDEV_SET_PARAM_RSP,

    QVIT_MSG_WAL_PDEV_STATS_PUBLISH_REQ,                        //MsgStruct: QVIT_Msg_Wal_Pdev_Stats_Publish_Req
    QVIT_MSG_WAL_PDEV_STATS_PUBLISH_RSP,

    QVIT_MSG_WAL_CHANNEL_CHANGE_REQ,                            // MsgStruct:  QVIT_Msg_Wal_Channel_Change_Req
    QVIT_MSG_WAL_CHANNEL_CHANGE_RSP,                        

    QVIT_MSG_WAL_TX_SEND_SETUP_BLOCK_ACK_REQ,                   // MsgStruct: QVIT_Msg_Wal_Tx_Send_Setup_Block_Ack_Req
    QVIT_MSG_WAL_TX_SEND_SETUP_BLOCK_ACK_RSP,

    QVIT_MSG_WAL_RC_INIT_VDEV_RC_PARAMS_REQ,                    // MsgStruct: QVIT_Msg_Wal_Rc_Init_Vdev_Rc_Params_Req
    QVIT_MSG_WAL_RC_INIT_VDEV_RC_PARAMS_RSP,

    QVIT_MSG_WAL_PHY_DEV_SET_POWER_STATE_REQ,                   // MsgStruct: QVIT_Msg_Wal_Phy_Dev_Set_Power_State_Req
    QVIT_MSG_WAL_PHY_DEV_SET_POWER_STATE_RSP,

    QVIT_MSG_WAL_PHY_DEV_SET_PARAM_REQ,                             // MsgStruct: QVIT_Msg_Wal_Phy_Dev_Set_Param_Req
    QVIT_MSG_WAL_PHY_DEV_SET_PARAM_RSP,

    /* WAL Beacon messages */
    QVIT_MSG_WAL_BEACON_INIT_REQ,                           //MsgStruct: QVIT_Msg_Wal_Beacon_Init_Req  
    QVIT_MSG_WAL_BEACON_INIT_RSP,

    QVIT_MSG_WAL_BEACON_QUEUE_SETUP_REQ,                    //MsgStruct: QVIT_Msg_Wal_Beacon_Queue_Setup_Req
    QVIT_MSG_WAL_BEACON_QUEUE_SETUP_RSP,

    QVIT_MSG_WAL_VDEV_SET_BEACON_CONFIG_REQ,                //MsgStruct:  QVIT_Msg_Wal_Vdev_Set_Beacon_Config_Req
    QVIT_MSG_WAL_VDEV_SET_BEACON_CONFIG_RSP,

    /* WAL Connection Pause messages */
    QVIT_MSG_WAL_CONNECTION_PAUSE_ENABLE_REQ,               //MsgStruct: QVIT_Msg_Wal_Connection_Pause_Enable_Req  
    QVIT_MSG_WAL_CONNECTION_PAUSE_ENABLE_RSP,

    QVIT_MSG_WAL_CONNECTION_PAUSE_DISABLE_REQ,              //MsgStruct: QVIT_Msg_Wal_Connection_Pause_Disable_Req  
    QVIT_MSG_WAL_CONNECTION_PAUSE_DISABLE_RSP,

    QVIT_MSG_WAL_VDEV_PAUSE_ENABLE_REQ,                     //MsgStruct: QVIT_Msg_Wal_Vdev_Pause_Enable_Req
    QVIT_MSG_WAL_VDEV_PAUSE_ENABLE_RSP,

    QVIT_MSG_WAL_VDEV_PAUSE_DISABLE_REQ,                    //MsgStruct: QVIT_Msg_Wal_Vdev_Pause_Disable_Req 
    QVIT_MSG_WAL_VDEV_PAUSE_DISABLE_RSP, 

    QVIT_MSG_WAL_PDEV_PAUSE_ENABLE_REQ,                     //MsgStruct: QVIT_Msg_Wal_Pdev_Pause_Enable_Req
    QVIT_MSG_WAL_PDEV_PAUSE_ENABLE_RSP,

    QVIT_MSG_WAL_PDEV_PAUSE_DISABLE_REQ,                    //MsgStruct: QVIT_Msg_Wal_Pdev_Pause_Disable_Req 
    QVIT_MSG_WAL_PDEV_PAUSE_DISABLE_RSP, 

    QVIT_MSG_WAL_CONNECTION_BLOCK_ENABLE_REQ,               //MsgStruct: QVIT_Msg_Wal_Connection_Block_Enable_Req  
    QVIT_MSG_WAL_CONNECTION_BLOCK_ENABLE_RSP,

    QVIT_MSG_WAL_CONNECTION_BLOCK_DISABLE_REQ,              //MsgStruct: QVIT_Msg_Wal_Connection_Block_Disable_Req  
    QVIT_MSG_WAL_CONNECTION_BLOCK_DISABLE_RSP,

    QVIT_MSG_WAL_CONNECTION_PAUSE_SEND_FRAMES_REQ,          //MsgStruct: QVIT_Msg_Wal_Connection_Pause_Send_Frames_Req  
    QVIT_MSG_WAL_CONNECTION_PAUSE_SEND_FRAMES_RSP,

    QVIT_MSG_WAL_CONNECTION_PAUSE_GET_PAUSED_TIDS_REQ,      //MsgStruct: QVIT_Msg_Wal_Connection_Pause_Get_Paused_Tids_Req    
    QVIT_MSG_WAL_CONNECTION_PAUSE_GET_PAUSED_TIDS_RSP,         

    QVIT_MSG_WAL_CONNECTION_PAUSE_GET_BLOCKED_TIDS_REQ,     //MsgStruct: QVIT_Msg_Wal_Connection_Pause_Get_Blocked_Tids_Req    
    QVIT_MSG_WAL_CONNECTION_PAUSE_GET_BLOCKED_TIDS_RSP,         

    QVIT_MSG_WAL_CONNECTION_PAUSE_GET_CREATED_TIDS_REQ,     //MsgStruct: QVIT_Msg_Wal_Connection_Pause_Get_Created_Tids_Req    
    QVIT_MSG_WAL_CONNECTION_PAUSE_GET_CREATED_TIDS_RSP,     

    QVIT_MSG_SYNC_DE_FA_END,


    /* Messaging between HA, FA
       Environments (HA,FA) need to process each (REQ, RSP) pair
    */
    QVIT_MSG_SYNC_HA_FA_START,
    
    QVIT_MSG_SYNC_HA_FA_END,


    /* Messaging among DE, HA, FA  
       Environments (DE, HA, FA) need to process each (REQ, RSP) pair
    */
    QVIT_MSG_SYNC_DE_HA_FA_START,
    
    /* WAL VDEV messages */
    QVIT_MSG_WAL_VDEV_ATTACH_REQ = QVIT_MSG_SYNC_DE_HA_FA_START, //MsgStruct: QVIT_Msg_Wal_VDEV_Attach_Req
    QVIT_MSG_WAL_VDEV_ATTACH_RSP,
    
    QVIT_MSG_WAL_VDEV_DETACH_REQ,                                //MsgStruct: QVIT_Msg_Wal_VDEV_Detach_Req
    QVIT_MSG_WAL_VDEV_DETACH_RSP,

   
    /* WAL PEER MESSAGES */ 
    QVIT_MSG_WAL_PEER_ALLOC_REQ,                                 //MsgStruct: QVIT_Msg_Wal_Peer_Alloc_Req
    QVIT_MSG_WAL_PEER_ALLOC_RSP,

    QVIT_MSG_WAL_PEER_DEALLOC_REQ,                               //MsgStruct: QVIT_Msg_Wal_Peer_DeAlloc_Req
    QVIT_MSG_WAL_PEER_DEALLOC_RSP,
    

    QVIT_MSG_SYNC_DE_HA_FA_END,

/* ASYNCHRONUS Message Codes Starts here */

    QVIT_MSG_ASYNC_START,

    /* Messaging between FA, DE
       Environments (FA, DE) need to process these message codes.
    */
    QVIT_MSG_ASYNC_FA_DE_START = QVIT_MSG_ASYNC_START,
    
    QVIT_MSG_ASYNC_FA_DE_END,


    /* Messaging between FA, HA
       Environments (FA, HA) need to process these message codes
    */
    QVIT_MSG_ASYNC_FA_HA_START,

    /* Beacon related event messages */ 
    /* HADrv->FA */
    QVIT_MSG_ASYNC_SEND_BCN_EVENT = QVIT_MSG_ASYNC_FA_HA_START,
    /* FA->HAdrv */
    QVIT_MSG_ASYNC_SWBA_EVENT, 
    
    QVIT_MSG_ASYNC_FA_HA_END,


    /* Messaging between HA, DE 
       Environments (HA, DE) need to process these message codes
    */
    QVIT_MSG_ASYNC_HA_DE_START,

    QVIT_MSG_ASYNC_HA_DE_END,


    /* Messaging among FA, HA, DE  
       Environments (FA, HA, DE) need to process these message codes.
    */
    QVIT_MSG_ASYNC_FA_HA_DE_START,

    QVIT_MSG_ASYNC_FA_HA_DE_END,

}QMF_MSG_CODE;

/* QVIT Message Header */
typedef struct QMF_HDR
{
    QMF_MSG_CODE msgCode;
    UINT32 msgLen;           /* Length of Header+Payload. */
}QMF_HDR;


/* QVIT Message Structures starts here */


/* QVIT System Maintenance Messages */
/* Connect and Interface Flag  for SYS_INQUIRE messages */
typedef enum 	ConnIf
{
    CI_HOSTDRV_PCIE,    /* Host driver with PCIe */
    CI_HOSTDRV_SDIO,    /* Host driver with SDIO */
    CI_HOSTDRV_USB,     /* Host driver with USB  */
    CI_UART,            /* UART                  */
    CI_JTAG             /* JTAG                  */
} ConnIf;

/* Device parameters */
typedef struct 	PDutParam
{
    char 	netDevName[32];   /* Network device name (ASCIZ),naming conventions are OS dependent */
    ConnIf	fCI;              /* Connection / Interface flag   */
    UINT32	hwDevId;          /* Device ID                     */
    /* Following fields are NOT guaranteed to be valid. 0xffff/0xffffffff = INVALID */
    UINT16	hwDevRev;         /* Device Revision               */
    UINT16	hwDevBld;         /* Device Build:1-FPGA, 2-ASIC   */
    UINT32	hostOS;           /* Host OS type                  */
    UINT32	hostOSVer;        /* Host OS version               */ 
    UINT32	hostDriverVer;    /* Host driver version/build     */
    UINT32	hostFWVer;        /* Target firmware version/build */
    UINT32	apiWMIVer;        /* WMI version                   */
    UINT32	apiWALVer;        /* WAL version                   */
} PDutParam;

/* Note that if there are multiple options of connections for the same device, e.g. HostDrv with PCIe, 
   UART and JTAG, these three options will be in 3 separate PDutParm structures. */
#define QVIT_MAX_DEV 16  /* Max number of options per device */

/* SYS_INQUIRE */

typedef struct  QVIT_Msg_Sys_Inquire_Req
{ /* QVIT_MSG_SYS_INQUIRE_REQ */
    QMF_HDR hdr;  /* QMF header */
} QVIT_Msg_Sys_Inquire_Req;

typedef struct  QVIT_Msg_Sys_Inquire_Rsp
{ /* QVIT_MSG_SYS_INQUIRE_RSP */
    QMF_HDR hdr;    /* QMF header                   */
    UINT32 nDevArray;   /* No of elements in arrary     */
    PDutParam pDutp[QVIT_MAX_DEV]; /* DUT param array return by HE */ 
} QVIT_Msg_Sys_Inquire_Rsp;


/* SYS_CONNECT */
typedef enum    SysConnRc               /* SYS_INQUIRE Return COde        */
{
        RC_SYS_CONN_OK,                 /* OK                             */
        RC_ALREADY_CONNECTED,           /* Already Connected this ConnID  */
        RC_INVALID_CID,                 /* Requested ID invalid           */
        RC_ALREADY_CONN_DIFF_ID,        /* Already connected with diff ID */
} SysConnRc;

typedef struct  QVIT_Msg_Sys_Connect_Req
{	/* QVIT_MSG_SYS_CONNECT_REQ */
	QMF_HDR	hdr;			/* QMF header                               */
	char 	netDevName[32];	/* Network device name (ASCIZ),naming conventions are OS dependent */
	ConnIf	fCI;			/* Connection / Interface flag              */
} QVIT_Msg_Sys_Connect_Req;

typedef struct  QVIT_Msg_Sys_Connect_Rsp
{	/* QVIT_MSG_SYS_CONNECT_RSP */
	QMF_HDR	hdr;			/* QMF header                               */
	char 	netDevName[32];	/* Network device name (ASCIZ),naming conventions are OS dependent */
	UINT32	connStat;		/* Connection status 0-OK                   */
} QVIT_Msg_Sys_Connect_Rsp;


typedef struct  QVIT_Msg_Sys_DisConnect_Req
{	/* QVIT_MSG_SYS_DISCONNECT_REQ */
	QMF_HDR	hdr;			/* QMF header                               */
	char 	netDevName[32];	/* Network device name (ASCIZ),naming conventions are OS dependent */
} QVIT_Msg_Sys_DisConnect_Req;

typedef struct  QVIT_Msg_Sys_DisConnect_Rsp
{	/* QVIT_MSG_SYS_DISCONNECT_RSP */
	QMF_HDR	hdr;			/* QMF header                               */
	UINT32	connStat;		/* Connection status 0-OK                   */
} QVIT_Msg_Sys_DisConnect_Rsp;


/* Debug Messages */
/* READ_REGISTER */
typedef struct QVIT_Msg_Read_Register_Req
{	/* QVIT_MSG_READ_REGISTER_REQ */
	QMF_HDR	hdr;
	UINT32 	regAddr;		/* Register address             */
} QVIT_Msg_Read_Register_Req;

typedef struct QVIT_Msg_Read_Register_Rsp
{	/* QVIT_MSG_READ_REGISTER_RSP */
	QMF_HDR	hdr;
	UINT32	regValue;		/* Register value               */
} QVIT_Msg_Read_Register_Rsp;


/* WRITE_REGISTER */
typedef struct QVIT_Msg_Write_Register_Req
{	/* QVIT_MSG_WRITE_REGISTER_REQ */
	QMF_HDR	hdr;
	UINT32 	regAddr;		/* Register address             */
	UINT32	regValue;		/* Register value               */
} QVIT_Msg_Write_Register_Req;

typedef struct QVIT_Msg_Write_Register_Rsp
{	/* QVIT_MSG_WRITE_REGISTER_RSP */
	QMF_HDR	hdr;
	UINT32	rc;			/* Return code                  */
} QVIT_Msg_Write_Register_Rsp;


/* READ_MEMORY */
#define MAX_MB_LEN	256		/* Max number of bytes to read per call */
typedef struct QVIT_Msg_Read_Memory_Req
{	/* QVIT_MSG_READ_MEMORY_REQ */
	QMF_HDR	hdr;
	UINT32 	memAddr;		/* Starting memory address       */
	UINT32 	memLen;			/* Number of bytes to read       */
} QVIT_Msg_Read_Memory_Req;

typedef struct QVIT_Msg_Read_Memory_Rsp
{	/* QVIT_MSG_READ_MEMORY_RSP */
	QMF_HDR	hdr;
	UINT8	memBuf[MAX_MB_LEN];	/* Memory contents               */
} QVIT_Msg_Read_Memory_Rsp;


/* WRITE_MEMORY */
typedef struct QVIT_Msg_Write_Memory_Req
{	/* QVIT_MSG_WRITE_MEMORY_REQ */
	QMF_HDR	hdr;
	UINT32 	memAddr;		/* Starting memory address       */
	UINT32 	memLen;			/* Number of bytes to write      */
	UINT8	memBuf[MAX_MB_LEN];	/* Memory contents               */
} QVIT_Msg_Write_Memory_Req;

typedef struct QVIT_Msg_Write_Memory_Rsp
{	/* QVIT_MSG_ WRITE_MEMORY_RSP */
	QMF_HDR	hdr;
	UINT32	rc;			/* Return code                   */
} QVIT_Msg_Write_Memory_Rsp;


typedef enum {
    _WAL_VDEV_TYPE_AP,
    _WAL_VDEV_TYPE_STA,
    _WAL_VDEV_TYPE_IBSS,
    _WAL_VDEV_TYPE_MONITOR,
    _WAL_VDEV_TYPE_MAX,
} _WAL_VDEV_TYPE;

typedef struct QVIT_Msg_Wal_VDEV_Attach_Req
{	/* QVIT_MSG_WAL_VDEV_ATTACH_REQ */
	QMF_HDR	hdr;
    UINT8 macAddr[MAC_ADDR_SIZE];	
	_WAL_VDEV_TYPE vdevType;			
    UINT8 vdevId;
} QVIT_Msg_Wal_VDEV_Attach_Req;

typedef struct QVIT_Msg_Wal_VDEV_Attach_Rsp
{	/* QVIT_MSG_WAL_VDEV_ATTACH_RSP */
	QMF_HDR	hdr;
	_WAL_STATUS walStatus;
    TARGET_PTR vdevHandle;
} QVIT_Msg_Wal_VDEV_Attach_Rsp;


typedef struct QVIT_Msg_Wal_VDEV_Up_Req
{	/* QVIT_MSG_WAL_VDEV_UP_REQ */
	QMF_HDR	hdr;
    TARGET_PTR vdevHandle;
    UINT8 bssId[MAC_ADDR_SIZE];	
    UINT8 assocId;
} QVIT_Msg_Wal_VDEV_Up_Req;

typedef struct QVIT_Msg_Wal_VDEV_Up_Rsp
{	/* QVIT_MSG_WAL_VDEV_UP_RSP */
	QMF_HDR	hdr;
	_WAL_STATUS walStatus;
} QVIT_Msg_Wal_VDEV_Up_Rsp;

typedef struct QVIT_Msg_Wal_VDEV_Down_Req
{	/* QVIT_MSG_WAL_VDEV_Down_REQ */
	QMF_HDR	hdr;
    TARGET_PTR vdevHandle;
    UINT8 vdevId;
} QVIT_Msg_Wal_VDEV_Down_Req;

typedef struct QVIT_Msg_Wal_VDEV_Down_Rsp
{	/* QVIT_MSG_WAL_VDEV_Down_RSP */
	QMF_HDR	hdr;
	_WAL_STATUS walStatus;
} QVIT_Msg_Wal_VDEV_Down_Rsp;


typedef struct QVIT_Msg_Wal_VDEV_Start_Req
{	/* QVIT_MSG_WAL_VDEV_Start_REQ */
	QMF_HDR	hdr;
    TARGET_PTR vdevHandle;
    UINT8 vdevId;
} QVIT_Msg_Wal_VDEV_Start_Req;

typedef struct QVIT_Msg_Wal_VDEV_Start_Rsp
{	/* QVIT_MSG_WAL_VDEV_Start_RSP */
	QMF_HDR	hdr;
	_WAL_STATUS walStatus;
} QVIT_Msg_Wal_VDEV_Start_Rsp;

typedef struct QVIT_Msg_Wal_VDEV_Stop_Req
{	/* QVIT_MSG_WAL_VDEV_Stop_REQ */
	QMF_HDR	hdr;
    TARGET_PTR vdevHandle;
    UINT8 vdevId;
} QVIT_Msg_Wal_VDEV_Stop_Req;

typedef struct QVIT_Msg_Wal_VDEV_Stop_Rsp
{	/* QVIT_MSG_WAL_VDEV_Stop_RSP */
	QMF_HDR	hdr;
	_WAL_STATUS walStatus;
} QVIT_Msg_Wal_VDEV_Stop_Rsp;

typedef enum {
    _WAL_PKT_TYPE_RAW = 0,
    _WAL_PKT_TYPE_NWIFI,
    _WAL_PKT_TYPE_ETHERNET,   /* 802.3 OR ETH2 allowed */
}_WAL_PKT_TYPE;

typedef struct QVIT_Msg_Wal_VDEV_Set_Input_Data_Pkt_Type_Req
{	/* QVIT_MSG_WAL_VDEV_SET_INPUT_DATA_PKT_TYPE_REQ */
	QMF_HDR	hdr;
    TARGET_PTR vdevHandle;
    _WAL_PKT_TYPE type;
} QVIT_Msg_Wal_VDEV_Set_Input_Data_Pkt_Type_Req;

typedef struct QVIT_Msg_Wal_VDEV_Set_Input_Data_Pkt_Type_Rsp
{	/* QVIT_MSG_WAL_VDEV_SET_INPUT_DATA_PKT_TYPE_RSP */
	QMF_HDR	hdr;
	_WAL_STATUS walStatus;
} QVIT_Msg_Wal_VDEV_Set_Input_Data_Pkt_Type_Rsp;


typedef struct QVIT_Msg_Wal_Peer_Alloc_Req
{	/* QVIT_MSG_WAL_PEER_ALLOC_REQ */
	QMF_HDR	hdr;
    TARGET_PTR vdevHandle;
    UINT8 macAddr[MAC_ADDR_SIZE];
    UINT8 bssId[MAC_ADDR_SIZE];
    BOOL bss_peer;
    UINT8 vdevId;
} QVIT_Msg_Wal_Peer_Alloc_Req;

typedef struct QVIT_Msg_Wal_Peer_Alloc_Rsp
{	/* QVIT_MSG_WAL_PEER_ALLOC_RSP */
	QMF_HDR	hdr;
	_WAL_STATUS walStatus;
    TARGET_PTR peerHandle;
} QVIT_Msg_Wal_Peer_Alloc_Rsp;


typedef struct QVIT_Msg_Wal_Peer_DeAlloc_Req
{	/* QVIT_MSG_WAL_PEER_DEALLOC_REQ */
	QMF_HDR	hdr;
    TARGET_PTR vdevHandle;
    UINT8 macAddr[MAC_ADDR_SIZE];
    UINT8 vdevId;    
    TARGET_PTR peerHandle;
} QVIT_Msg_Wal_Peer_DeAlloc_Req;

typedef struct QVIT_Msg_Wal_Peer_DeAlloc_Rsp
{	/* QVIT_MSG_WAL_PEER_DEALLOC_RSP */
	QMF_HDR	hdr;
	_WAL_STATUS walStatus;
} QVIT_Msg_Wal_Peer_DeAlloc_Rsp;

typedef struct QVIT_Msg_Wal_VDEV_Detach_Req
{	/* QVIT_MSG_WAL_VDEV_DETACH_REQ */
	QMF_HDR	hdr;
    UINT8 macAddr[MAC_ADDR_SIZE];
    TARGET_PTR vdevHandle;
    UINT8 vdevId;
} QVIT_Msg_Wal_VDEV_Detach_Req;

typedef struct QVIT_Msg_Wal_VDEV_Detach_Rsp
{	/* QVIT_MSG_WAL_VDEV_DETACH_RSP */
	QMF_HDR	hdr;
	_WAL_STATUS walStatus;
} QVIT_Msg_Wal_VDEV_Detach_Rsp;


typedef enum {
    _WAL_PDEV_PARAM_NON_AGG_SW_RETRY_TH,
    _WAL_PDEV_PARAM_AGG_SW_RETRY_TH,
    _WAL_PDEV_PARAM_STA_KICKOUT_TH,
    _WAL_PDEV_PARAM_BCN_TX_MODE,
    _WAL_PDEV_PARAM_PMF_QOS,
}_WAL_PDEV_PARAM_T;

typedef struct QVIT_Msg_Wal_PDev_Set_Param_Req
{
    /* QVIT_MSG_WAL_PHY_DEV_SET_PARAM_REQ */   
	QMF_HDR hdr;
	_WAL_PDEV_PARAM_T param_type;
    UINT32 param_val; 
}QVIT_Msg_Wal_PDev_Set_Param_Req;

typedef struct QVIT_Msg_Wal_PDev_Set_Param_Rsp
{
    /* QVIT_MSG_WAL_PHY_DEV_SET_PARAM_RSP */   
	QMF_HDR hdr;
	_WAL_STATUS walStatus;
}QVIT_Msg_Wal_PDev_Set_Param_Rsp;


typedef struct QVIT_Msg_Wal_Phy_Dev_Set_Param_Req
{
    /* QVIT_MSG_WAL_PHY_DEV_SET_PARAM_REQ */   
	QMF_HDR hdr;
	_WAL_PDEV_PARAM_T param_type;
    UINT32 param_val; 
}QVIT_Msg_Wal_Phy_Dev_Set_Param_Req;

typedef struct QVIT_Msg_Wal_Phy_Dev_Set_Param_Rsp
{
    /* QVIT_MSG_WAL_PHY_DEV_SET_PARAM_RSP */   
	QMF_HDR hdr;
	_WAL_STATUS walStatus;
}QVIT_Msg_Wal_Phy_Dev_Set_Param_Rsp;


typedef enum {
    _MODE_11A        = 0,   /* 11a Mode */
    _MODE_11G        = 1,   /* 11b/g Mode */
    _MODE_11B        = 2,   /* 11b Mode */
    _MODE_11GONLY    = 3,   /* 11g only Mode */
    _MODE_11NA_HT20   = 4,  /* 11a HT20 mode */
    _MODE_11NG_HT20   = 5,  /* 11g HT20 mode */
    _MODE_11NA_HT40   = 6,  /* 11a HT40 mode */
    _MODE_11NG_HT40   = 7,  /* 11g HT40 mode */
    _MODE_11AC_VHT20 = 8,
    _MODE_11AC_VHT40 = 9,
    _MODE_11AC_VHT80 = 10,
//  _MODE_11AC_VHT160 = 11,
    _MODE_11AC_VHT20_2G = 11,
    _MODE_11AC_VHT40_2G = 12,
    _MODE_11AC_VHT80_2G = 13,
    _MODE_UNKNOWN    = 14,
    _MODE_MAX        = 14
} _WLAN_PHY_MODE;

typedef struct _CHANNEL {
    /** primary 20 MHz channel frequency in mhz */ 
    UINT16 mhz;
    /** Center frequency 1 in MHz*/
    UINT16 band_center_freq1;
    /** Center frequency 2 in MHz - valid only for 11acvht 80plus80 mode*/
    UINT16 band_center_freq2;
    /* phy mode */
    _WLAN_PHY_MODE phy_mode;
    /* max transmit power, in half db*/
    UINT8   max_reg_power;     
    UINT8   antenna_max;
    /* extra flags to specify other channel attributes */
    UINT8   flags;
} _CHANNEL_T;

typedef struct QVIT_Msg_Wal_Channel_Change_Req
{	/* QVIT_MSG_WAL_CHANNEL_CHANGE_REQ */
	QMF_HDR	hdr;
	UINT8 opMode;
    _CHANNEL_T chan;
    UINT16 flags;
} QVIT_Msg_Wal_Channel_Change_Req;

typedef struct QVIT_Msg_Wal_Channel_Change_Rsp
{	/* QVIT_MSG_WAL_CHANNEL_CHANGE_RSP */
	QMF_HDR	hdr;
	BOOL status;
} QVIT_Msg_Wal_Channel_Change_Rsp;


typedef enum {
    /** Enable QOS for this node */
   _WAL_PEER_PARAM_QOS_EN,
    /**ampdu density 0 for no restriction, 1 for 1/4 us, 2 for 1/2 us, 3 for 1 us,4 for 2 us, 5 for 4 us, 6 for 8 us,7 for 16 us */
   _WAL_PEER_PARAM_AMPDU_DENSITY,   
   /** max amdu size 0 = 8K, 1 = 16K etc. */
   _WAL_PEER_PARAM_AMPDU_MAXBYTES, 
   /** 11ac capability  */
   _WAL_PEER_PARAM_11AC,  
   /** MAX allowed AMSDU size */
   _WAL_PEER_PARAM_AMSDU_MAX_SIZE,
   /** Are AMSDUs allowed inside AMPDU */
   _WAL_PEER_PARAM_AMSDU_IN_AMPDU_OK,
   /** Frame control to be used for 802.11 encapsulation. initial value =0 */
   _WAL_PEER_PARAM_TX_FRAME_CONTROL,  
   /** TX chain mask to be used for triansmission.  initial value : the max supported by HW   */
   _WAL_PEER_PARAM_TX_CHAIN_MASK, 
   /** the peer connection state. see below for possible values and their sematics */ 
   _WAL_PEER_PARAM_CONNECTION_STATE,      
   /** set TKIP counter measure 1: enable and no data can tx/rx, 0: disable and alow all tx/rx data.initial value 0 */ 
   _WAL_PEER_PARAM_TKIP_ENABLE_CM,   
   /** tx power 1/2 db.  initial value = max value suported */   
   _WAL_PEER_PARAM_TX_POWER,        
   /** type of ethernet frame allowed during unauthorized state */     
   _WAL_PEER_PARAM_ALLOWED_ETH_TYPE, 
   /** enable mimo ps state 1: enable, 0:diable. initial value = 0 */     
   _WAL_PEER_PARAM_ENABLE_DYN_MIMO_PS,
   /** send every frame from this peer with PS=1. initial value=0 */     
   _WAL_PEER_PARAM_FORCE_PS,          
   /** pointer to TX BF structure (TBD). initial value = NULL */     
   _WAL_PEER_PARAM_TXBF_VECTOR,       
   /** lower tsf32 value at which HW will start filtering frames. initial value =0 (0 means disable filtering)*/     
   _WAL_PEER_PARAM_FILTER_TSF32,    
   /** wb timer values  at which HW will start filtering frames. initial value =0 (0 means disable filtering)*/     
   _WAL_PEER_PARAM_WB_TIMER,      
   /** context stored and used by the reordering module above wal (inside HTT)  */     
   _WAL_PEER_PARAM_RX_CONTEXT,    
   /** default key id to be used for transmission of frames */     
   _WAL_PEER_PARAM_TX_KEYID,
   /** Average RSSI value for the PPDUs received by the peer */
   _WAL_PEER_PARAM_AVG_RSSI,
   /** Lower and Upper Thresholds for RX-rate to be used for comparison with last PPDU's rate and notifying btcoex */
   _WAL_PEER_PARAM_RXRATE_THRESHOLDS,
   /** 4 way handshake needs to complete before allowing data */
   _WAL_PEER_PARAM_NEED_PTK_4_WAY,
   /** 2 way handshake needs to complete after 4-way */
   _WAL_PEER_PARAM_NEED_GTK_2_WAY,
   /** Enables encryption for the peer and adjusts header sizes*/
   _WAL_PEER_PARAM_ENCR_EN,
   /* #ifdef WAPI_ENABLE */
      /** Checks whether peer keytype is WAPI */
      _WAL_PEER_PARAM_KEYTYPE_WAPI,
   /* #endif */
} _WAL_PEER_PARAM;

typedef struct QVIT_Msg_Wal_Peer_Set_Param_Req
{	/* QVIT_MSG_WAL_PEER_SET_PARAM_REQ */
    QMF_HDR	hdr;
    TARGET_PTR peerHandle;
    _WAL_PEER_PARAM param_type;
    UINT32 val;
} QVIT_Msg_Wal_Peer_Set_Param_Req;

typedef struct QVIT_Msg_Wal_Peer_Set_Param_Rsp
{	/* QVIT_MSG_WAL_PEER_SET_PARAM_RSP */
    QMF_HDR	hdr;
    _WAL_STATUS walStatus;
} QVIT_Msg_Wal_Peer_Set_Param_Rsp;


typedef enum {
    _WAL_KEY_TYPE_CLEAR,
    _WAL_KEY_TYPE_WEP128,
    _WAL_KEY_TYPE_WEP104,
    _WAL_KEY_TYPE_WEP40,
    _WAL_KEY_TYPE_TKIP,
    _WAL_KEY_TYPE_TKIP_NOMIC,
    _WAL_KEY_TYPE_AES_CCMP,
    _WAL_KEY_TYPE_WAPI
} _WAL_KEY_TYPE;

typedef enum {
    _WAL_KEY_DIR_TX,
    _WAL_KEY_DIR_RX,
    _WAL_KEY_DIR_BOTH
} _WAL_KEY_DIR;

typedef struct _WAL_KEY_INFO {
   TARGET_PTR key_val; /* Key material */
   _WAL_KEY_TYPE key_type;  /* key type */
   UINT32 key_len;   /* key len */
   _WAL_KEY_DIR  key_dir;   /* wal key direction */
   TARGET_PTR rx_mic;  /* optional rx mic */
   TARGET_PTR tx_mic;  /* optional tx mic */
   UINT32 rx_mic_len; /* rx mic length */
   UINT32 tx_mic_len; /* tx mic length */
   TARGET_PTR wapi_rx_pn;  /* wapi rx pin*/
   TARGET_PTR wapi_tx_pn;  /* wapi tx pin */
} _WAL_KEY_INFO_T ;

typedef struct _KEY_VAL{
   UINT8 key_val[32];
   UINT8 rx_mic[16];
   UINT8 tx_mic[16];
   UINT8 wapi_rx_pn[16];
   UINT8 wapi_tx_pn[16];
}_KEY_VAL_T;

typedef struct QVIT_Msg_Wal_Peer_Set_Key_Req
{
    /* QVIT_MSG_WAL_PEER_SET_KEY_REQ */
    QMF_HDR	hdr;
    TARGET_PTR peerHandle;
    _WAL_KEY_INFO_T key_info;	
    _KEY_VAL_T keys;
    UINT8 key_id;
BOOL is_multicast;
}QVIT_Msg_Wal_Peer_Set_Key_Req;

typedef struct QVIT_Msg_Wal_Peer_Set_Key_Rsp
{
    /* QVIT_MSG_WAL_PEER_SET_KEY_RSP */
    QMF_HDR	hdr;
    _WAL_STATUS walStatus;
}QVIT_Msg_Wal_Peer_Set_Key_Rsp;


#define QVIT_NUM_SPATIAL_STREAM 3
typedef struct {
   UINT8 data_rc;  /* HW rate code for data frame */
   UINT8 max_bw;   /* maxmium allowed bandwidth */
   UINT8 max_nss;  /* Max NSS to use */
   UINT8 rts_cts;  /* RTS/CTS enabled */
   UINT8 def_tpc;  /* default TPC value */
   UINT8 def_tries; /* Total Transmission attempt */
   UINT8 non_data_rc; /* HW rate for mgmt/control frames */
   UINT8 rc_flags; /* RC flags SGI/LDPC/STBC etc */
   UINT8 aggr_dur_limit; /* max duraton any aggregate may have */
   UINT8 tx_chain_mask[QVIT_NUM_SPATIAL_STREAM];
   UINT8 bcast_data_rc;
   UINT8 mcast_data_rc;
} _AR_WAL_RC_INFO_T;

typedef struct QVIT_Msg_Wal_Rc_Init_Vdev_Rc_Params_Req{
	/*QVIT_MSG_WAL_RC_INIT_VDEV_RC_PARAMS_REQ*/
    QMF_HDR	hdr;
    TARGET_PTR vdevHandle;
    _AR_WAL_RC_INFO_T rc_params;
}QVIT_Msg_Wal_Rc_Init_Vdev_Rc_Params_Req;

typedef struct QVIT_Msg_Wal_Rc_Init_Vdev_Rc_Params_Rsp{
	/*QVIT_MSG_WAL_RC_INIT_VDEV_RC_PARAMS_RSP*/
    QMF_HDR	hdr;
	/*Even though WAL API doesn't return status, we'll return dummy OK status for scripts*/
    _WAL_STATUS walStatus;
}QVIT_Msg_Wal_Rc_Init_Vdev_Rc_Params_Rsp;


typedef struct _WAL_DBG_TX_STATS {
    /* Num HTT cookies queued to dispatch list */
    INT32 comp_queued;
    /* Num HTT cookies dispatched */
    INT32 comp_delivered;
    /* Num MSDU queued to WAL */
    INT32 msdu_enqued;
    /* Num MPDU queue to WAL */
    INT32 mpdu_enqued;
    /* Num MSDUs dropped by WMM limit */
    INT32 wmm_drop;
    /* Num Local frames queued */
    INT32 local_enqued;
    /* Num Local frames done */
    INT32 local_freed;
    /* Num queued to HW */
    INT32 hw_queued;
    /* Num PPDU reaped from HW */
    INT32 hw_reaped;
    /* Num underruns */
    INT32 underrun;
    /* Num PPDUs cleaned up in TX abort */
    INT32 tx_abort;
    /* Num MPDUs requed by SW */
    INT32 mpdus_requed;
    /* excessive retries */
    UINT32 tx_ko; 
    /* data hw rate code */
    UINT32 data_rc;
    /* Scheduler self triggers */
    UINT32 self_triggers;
}_WAL_DBG_TX_STATS;

typedef struct _WAL_DBG_RX_STATS {
    /* Cnts any change in ring routing mid-ppdu */
    INT32 mid_ppdu_route_change;
    /* Total number of statuses processed */
    INT32 status_rcvd;
    /* Extra frags on rings 0-3 */
    INT32 r0_frags;
    INT32 r1_frags;
    INT32 r2_frags;
    INT32 r3_frags;
    /* MSDUs / MPDUs delivered to HTT */
    INT32 htt_msdus;
    INT32 htt_mpdus;
    /* MSDUs / MPDUs delivered to local stack */
    INT32 loc_msdus;
    INT32 loc_mpdus;
    /* AMSDUs that have more MSDUs than the status ring size */
    INT32 oversize_amsdu;
    /* Number of PHY errors */
    INT32 phy_errs;
    /* Number of PHY errors drops */
    INT32 phy_err_drop;
    /* Number of mpdu errors - FCS, MIC, ENC etc. */
    INT32 mpdu_errs;
}_WAL_DBG_RX_STATS;

typedef struct _WAL_DBG_PEER_STATS {

	INT32 dummy; /* REMOVE THIS ONCE REAL PEER STAT COUNTERS ARE ADDED */
}_WAL_DBG_PEER_STATS;

typedef struct _WAL_DBG_STATS {
    struct _WAL_DBG_TX_STATS tx;
    struct _WAL_DBG_RX_STATS rx;
    struct _WAL_DBG_PEER_STATS peer;
}_WAL_DBG_STATS;

typedef struct QVIT_Msg_Wal_Pdev_Stats_Publish_Req{
    /* QVIT_MSG_WAL_PDEV_STATS_PUBLISH_REQ */
    QMF_HDR	hdr;
    /* Dummy variable, in case automation needs at least one variable*/
    UINT32 dummy;
}QVIT_Msg_Wal_Pdev_Stats_Publish_Req;

typedef struct QVIT_Msg_Wal_Pdev_Stats_Publish_Rsp{
    /* QVIT_MSG_WAL_PDEV_STATS_PUBLISH_RSP */
    QMF_HDR	hdr;
    INT32 num_bytes_returned;
    _WAL_DBG_STATS stats;
}QVIT_Msg_Wal_Pdev_Stats_Publish_Rsp;


typedef struct QVIT_Msg_Wal_Tx_Send_Setup_Block_Ack_Req{
    /* QVIT_MSG_WAL_TX_SEND_SETUP_BLOCK_ACK_REQ */
    QMF_HDR	hdr;
    TARGET_PTR peerHandle;
    UINT8 tid;
    UINT32 seq_st;
    UINT32 win_sz;
    BOOL state;
    BOOL enable_amsdu;
}QVIT_Msg_Wal_Tx_Send_Setup_Block_Ack_Req;

typedef struct QVIT_Msg_Wal_Tx_Send_Setup_Block_Ack_Rsp{
    /* QVIT_MSG_WAL_TX_SEND_SETUP_BLOCK_ACK_RSP */
    QMF_HDR	hdr;
    _WAL_STATUS walStatus;
}QVIT_Msg_Wal_Tx_Send_Setup_Block_Ack_Rsp;

typedef enum {
    _WAL_POWER_STATE_SLEEP = 1,
    _WAL_POWER_STATE_AWAKE = 2,
    _WAL_POWER_STATE_FULL_SLEEP = 3
} _WAL_POWER_STATE;


typedef struct QVIT_Msg_Wal_Phy_Dev_Set_Power_State_Req
{    
     QMF_HDR	hdr;
    _WAL_POWER_STATE powerState;
} QVIT_Msg_Wal_Phy_Dev_Set_Power_State_Req;


typedef struct QVIT_Msg_Wal_Phy_Dev_Set_Power_State_Rsp
{    
    QMF_HDR	hdr;
	_WAL_STATUS status;
} QVIT_Msg_Wal_Phy_Dev_Set_Power_State_Rsp;


/* Data Path Messages */
typedef enum packetType
{
     ETHII,
     E8023,
     NATIVE_WIFI
} PACKET_TYPE;
#define MAX_STREAMS 10
/*  Frame control (2 bytes) */
typedef struct  FrameCtrl
{
        UINT16          wFrameCtrl;
#if 0		
        UINT16          protVer :2;     /* Set by DE */
        UINT16          type :2;        /* Set by DE */
        UINT16          subType :4;     /* Set by DE */
        UINT16          toDS :1;        /* Set by DE */
        UINT16          fromDS :1;      /* Set by DE */
        UINT16          moreFrag :1;
        UINT16          retry :1;
        UINT16          pwrMgmt :1;
        UINT16          moreData :1;
        UINT16          protFrame :1;
        UINT16          order :1;       /* Set by DE */
#endif		
}  FrameCtrl;

#define	MAX_RATE_INDEX	256

typedef enum STREAMTYPE
{
    streamRX = 0,
    streamTX
} stream_type;


typedef struct  QVIT_Msg_Stream_Config_Req
{
	/* QVIT_MSG_STREAM_CONFIG_REQ */
	QMF_HDR	hdr;

	UINT32		vdev_handle;  
    UINT32      vdevId;
	UINT32		stream_handle;		/* NULL = failed */
    UINT32      stream_type;       /* Tx = 1 or Rx = 0 */

	/* Packet Type */ 
	UINT32		pktType;		/* ethii, 802.3, Native WiFi */

	/* 802.11 */ 
	FrameCtrl	fc;
  	/* UNIT16	duration; */		/*??? – set by FW, to be removed */
  	UINT8		addr1[6];		/* Set by DE */ /* DA */
	UINT8		addr2[6];		/* Set by DE */ /* SA */
	UINT8		addr3[6];		/* Set by DE */
	/* SecCtrl	seqControl; */		/*??? – set by FWHW, to be removed  */
  	UINT8		addr4[6];		/* Set by DE */

	/* 802.3 */
	UINT16		etherType;		/* protocol – 2B  */
	UINT16		ieee8021qPCP;		/* 802.1p priority – 3 bit */
	UINT16		ieee8021qVID;		/* VLAN ID – 12 bit  */

	/* Stream  param control  */
	UINT32		minLen;			/* Min length */
	UINT32		maxLen	;		/* Max length. If Min = Max -> Fix length */
	UINT32		intgrChk;		/* 0 – No Chk, 1 – CKS, 2 - TCP/IP CKS */
	UINT32		minTID;			/* Min TID */
	UINT32		maxTID	;		/* Max TID  */

	/* Cycle control  */
	UINT32		minBurstCnt;		/* Min burst count in the cycle */
	UINT32		maxBurstCnt;		/* Max. If min = max -> fixed */
	UINT32		minDelay;		/* Quiet time (mS) in between burst - min */
	UINT32		maxDelay;		/* max */
	UINT32		repeatCnt;		/* Cycle repeat count  (0xffffffff = continuous)  */
	
	/* For example:
	 * 1,1,20,20 – Simulate VoIP (with appropriate len/TID) 			*
	 * 3,6,100,200 – Random burst traffic  						*
	 * 1,1,0,0 – max performance    						*			
	 * Nota that more than 1 stream can be combined to simulate VoIP + data traffic */

	/* Randomization Control  */
	/* Rate  - No of rate to walk thru and their index */
	UINT32		rateUpdateTime;			/* In mS,  send rate change after this interval */
	UINT32		cntElem;			/* No of sets in the following array */
	UINT8		rateIDX1[MAX_RATE_INDEX];	/* Rate Index – Pri */
	UINT8		rateIDX2[MAX_RATE_INDEX];	/* Rate Index – Sec */
	BOOL		randomRate;			/* Random or sequential(rate walk)   */

	/* Protection – RTS/CTS, CTS2S – should this be “randomized”??? */
	UINT32		protUpdateTime;			/* In mS,  send Prot  change after this internal */
	UINT32		minProtType;			/*   */
	UINT32		maxProtType;			/*   */
    UINT32      spare;

} QVIT_Msg_Stream_Config_Req;

typedef struct  QVIT_Msg_Stream_Config_Rsp
{
	/* QVIT_MSG_STREAM_CONFIG_RSP */
	QMF_HDR	hdr;

	UINT32		vdev_handle;
	UINT32		stream_handle;		/* NULL = failed */
} QVIT_Msg_Stream_Config_Rsp;


typedef struct  QVIT_Msg_Stream_Destroy_Req
{
	/* QVIT_MSG_STREAM_DESTROY_REQ */
	QMF_HDR	hdr;

	UINT32		vdev_handle;
	UINT32		stream_handle;		
    UINT32      stream_type;
} QVIT_Msg_Stream_Destroy_Req;

typedef struct  QVIT_Msg_Stream_Destroy_Rsp
{
	/* QVIT_MSG_STREAM_DESTROY_RSP */
	QMF_HDR	hdr;

	UINT32		vdev_handle;
	UINT32		stream_handle;
	UINT32		rc;	
} QVIT_Msg_Stream_Destroy_Rsp;


typedef struct  QVIT_Msg_Stream_Start_Stop_Req
{
	/* QVIT_Msg_STREAM_START_STOP_REQ */
	QMF_HDR		hdr;
    UINT32      stream_type;
	UINT32		stream_handle;		/* Stream handle returned by STreamConfig */
	UINT32		startFlag;		/* 1 – start, 0 - stop, 2 - exit*/

} QVIT_Msg_Stream_Start_Stop_Req;

typedef struct  QVIT_Msg_Stream_Start_Stop_Rsp
{
	/* QVIT_Msg_STREAM_START_STOP_RSP */
	QMF_HDR		hdr;

	UINT32		stream_handle;		/* Stream handle returned by STreamConfig */
	UINT32		rc;			/* 1 – started, 0 - stopped, 2 - exit */

} QVIT_Msg_Stream_Start_Stop_Rsp;

typedef struct QVIT_Msg_Wal_Beacon_Init_Req
{   /* QVIT_MSG_WAL_BEACON_INIT_REQ */
    QMF_HDR	hdr;
} QVIT_Msg_Wal_Beacon_Init_Req;

typedef struct QVIT_Msg_Wal_Beacon_Init_Rsp
{   /* QVIT_MSG_WAL_BEACON_INIT_RSP */
    QMF_HDR	hdr;
    _WAL_STATUS  walStatus; 
} QVIT_Msg_Wal_Beacon_Init_Rsp;

typedef struct QVIT_Msg_Wal_Beacon_Queue_Setup_Req
{   /* QVIT_MSG_WAL_BEACON_QUEUE_SETUP_REQ */
    QMF_HDR	hdr;
    TARGET_PTR    vdevHandle;
    UINT32        aifs;
    UINT32        cwmin;
    UINT32        cwmax;
} QVIT_Msg_Wal_Beacon_Queue_Setup_Req;

typedef struct QVIT_Msg_Wal_Beacon_Queue_Setup_Rsp
{	/* QVIT_MSG_WAL_BEACON_QUEUE_SETUP_RSP */
    QMF_HDR	hdr;
    _WAL_STATUS  walStatus; 
} QVIT_Msg_Wal_Beacon_Queue_Setup_Rsp;

#define MAX_BEACON_SIZE 256

typedef struct QVIT_Msg_Setup_Beacon_Buffer_Req
{   /* QVIT_MSG_SETUP_BEACON_BUFFER_REQ */
    QMF_HDR	hdr;
    UINT8   vdevId;
    UINT8 buffer [MAX_BEACON_SIZE];
} QVIT_Msg_Setup_Beacon_Buffer_Req;

typedef struct QVIT_Msg_Setup_Beacon_Buffer_Rsp
{   /* QVIT_MSG_SETUP_BEACON_BUFFER_RSP */
    QMF_HDR	hdr;
    UINT8  status;   /* 0 success */
} QVIT_Msg_Setup_Beacon_Buffer_Rsp;

typedef enum {
    _WAL_BEACON_SWBA_CB_IGNORE = 0x0,
    _WAL_BEACON_SWBA_CB_STAGGERED, 
    _WAL_BEACON_SWBA_CB_BURST,
    _WAL_BEACON_SWBA_CB_MAX
} _WAL_BEACON_SWBA_CB_TYPE;

typedef struct  {
    UINT32    next_tbtt;        /* next beacon in us */
    UINT32    next_dtim;        /* next DTIM in us */
    UINT32    beacon_interval;  /* beacon interval in us */
    UINT32    dtim_period;
    UINT16    bmiss_th_awake;   /* beacon miss threshold when awake */
    UINT16    bmiss_th_sleep;   /* beacon miss threshold when network sleep */
    UINT32    sleep_duration;   /* max sleep duration */
    UINT32    cab_timeout;      /* cab timeout in TU */
    UINT32    bcn_timeout;      /* beacon timeout in TU */
    UINT32    cab_awake_dur;    /* cab awake duration in TU */
    UINT32    bmiss_time;       /* beacon miss time in TU */
    UINT32    listen_interval;  /* listen intrerval  in number of beacons */
    UINT32    max_cabq_duration;/* maximum amount of time in us allowed for AP to send CAB */
    UINT8     ic_lpreamble;     /* Indicate beacon preamble length. */
    _WAL_BEACON_SWBA_CB_TYPE swba_cb_type; /* AP mode parameter for Software Beacon Alert callback type*/
} _wal_beacon_config_t;

typedef struct QVIT_Msg_Wal_Vdev_Set_Beacon_Config_Req
{   /* QVIT_MSG_WAL_VDEV_SET_BEACON_CONFIG_REQ */
    QMF_HDR	hdr;
    TARGET_PTR    vdevHandle;
    _wal_beacon_config_t beacon_config;
} QVIT_Msg_Wal_Vdev_Set_Beacon_Config_Req;

typedef struct QVIT_Msg_Wal_Vdev_Set_Beacon_Config_Rsp
{   /* QVIT_MSG_WAL_VDEV_SET_BEACON_CONFIG_RSP */
    QMF_HDR	hdr;
    _WAL_STATUS  walStatus; 
} QVIT_Msg_Wal_Vdev_Set_Beacon_Config_Rsp;

typedef struct QVIT_Msg_Async_Send_Bcn_Event{
    /* QVIT_MSG_ASYNC_SEND_BCN_EVENT */
    QMF_HDR	hdr;
    UINT32 vdev_id;
    UINT32 data_len;
    UINT32 frag_ptr; /* Physical address of the frame */
    UINT32 virt_addr; /* virtual address of host bcn buffer (needed for Packet Log only) */
    UINT16 frame_ctrl; /* farme ctrl to setup PPDU desc */
    UINT8 dtim_flag;   /* to control CABQ traffic */
} QVIT_Msg_Async_Send_Bcn_Event;

#define MAX_AP_VDEV 16

typedef struct QVIT_Msg_Async_SWBA_Event{
    /* QVIT_MSG_ASYNC_SWBA_EVENT */
    QMF_HDR	hdr;
    UINT32 swba_map;
    UINT32 vdev_map;
    UINT32 tbttoffset_list[MAX_AP_VDEV];
} QVIT_Msg_Async_SWBA_Event;


typedef struct QVIT_Msg_Wal_Connection_Pause_Enable_Req{

    /* QVIT_MSG_WAL_CONNECTION_PAUSE_ENABLE_REQ */
    QMF_HDR	hdr;
    TARGET_PTR peerHandle;
    UINT32 module_id;
    UINT32 tid_bitmap;
    BOOL   filter;    
}QVIT_Msg_Wal_Connection_Pause_Enable_Req;

typedef struct QVIT_Msg_Wal_Connection_Pause_Enable_Rsp{

    /* QVIT_MSG_WAL_CONNECTION_PAUSE_ENABLE_RSP */
    QMF_HDR	hdr;
    _WAL_STATUS  walStatus;   
}QVIT_Msg_Wal_Connection_Pause_Enable_Rsp;

typedef struct QVIT_Msg_Wal_Connection_Pause_Disable_Req{

    /* QVIT_MSG_WAL_CONNECTION_PAUSE_DISABLE_REQ */
    QMF_HDR	hdr;
    TARGET_PTR peerHandle;
    UINT32 module_id;
    UINT32 tid_bitmap;
}QVIT_Msg_Wal_Connection_Pause_Disable_Req;

typedef struct QVIT_Msg_Wal_Connection_Pause_Disable_Rsp{

    /* QVIT_MSG_WAL_CONNECTION_PAUSE_DISABLE_RSP */
    QMF_HDR	hdr;
    _WAL_STATUS  walStatus;   
}QVIT_Msg_Wal_Connection_Pause_Disable_Rsp;


typedef struct QVIT_Msg_Wal_Vdev_Pause_Enable_Req {
    /*QVIT_MSG_WAL_VDEV_PAUSE_ENABLE_REQ */
    QMF_HDR	hdr;
    TARGET_PTR vdevHandle;    
    UINT32 module_id;
    BOOL   filter;   
}QVIT_Msg_Wal_Vdev_Pause_Enable_Req ;

typedef struct QVIT_Msg_Wal_Vdev_Pause_Enable_Rsp {
    /*QVIT_MSG_WAL_VDEV_PAUSE_ENABLE_RSP */
    QMF_HDR	hdr;
    _WAL_STATUS  walStatus;   
}QVIT_Msg_Wal_Vdev_Pause_Enable_Rsp;                     

typedef struct QVIT_Msg_Wal_Vdev_Pause_Disable_Req {
    /*QVIT_MSG_WAL_VDEV_PAUSE_DISABLE_REQ */
    QMF_HDR	hdr;
    TARGET_PTR vdevHandle;    
    UINT32 module_id;
}QVIT_Msg_Wal_Vdev_Pause_Disable_Req;

typedef struct QVIT_Msg_Wal_Vdev_Pause_Disable_Rsp {
    /*QVIT_MSG_WAL_VDEV_PAUSE_DISABLE_RSP */
    QMF_HDR	hdr;
    _WAL_STATUS  walStatus;   
}QVIT_Msg_Wal_Vdev_Pause_Disable_Rsp;   

typedef struct QVIT_Msg_Wal_Pdev_Pause_Enable_Req {
    /*QVIT_MSG_WAL_PDEV_PAUSE_ENABLE_REQ */
    QMF_HDR	hdr;
    UINT32 module_id;
    BOOL   filter;   
}QVIT_Msg_Wal_Pdev_Pause_Enable_Req;

typedef struct QVIT_Msg_Wal_Pdev_Pause_Enable_Rsp {
    /*QVIT_MSG_WAL_PDEV_PAUSE_ENABLE_RSP */
    QMF_HDR	hdr;
    _WAL_STATUS  walStatus;   
}QVIT_Msg_Wal_Pdev_Pause_Enable_Rsp;   

typedef struct QVIT_Msg_Wal_Pdev_Pause_Disable_Req {
    /*QVIT_MSG_WAL_PDEV_PAUSE_DISABLE_REQ */
    QMF_HDR	hdr;   
    UINT32 module_id;
}QVIT_Msg_Wal_Pdev_Pause_Disable_Req;

typedef struct QVIT_Msg_Wal_Pdev_Pause_Disable_Rsp {
    /*QVIT_MSG_WAL_PDEV_PAUSE_DISABLE_RSP */
    QMF_HDR	hdr;
    _WAL_STATUS  walStatus;   
}QVIT_Msg_Wal_Pdev_Pause_Disable_Rsp;   

typedef struct QVIT_Msg_Wal_Connection_Block_Enable_Req{

    /* QVIT_MSG_WAL_CONNECTION_BLOCK_ENABLE_REQ */
    QMF_HDR	hdr;
    TARGET_PTR peerHandle;
    UINT32 module_id;
    UINT32 tid_bitmap;
    BOOL   filter;    
}QVIT_Msg_Wal_Connection_Block_Enable_Req;

typedef struct QVIT_Msg_Wal_Connection_Block_Enable_Rsp{

    /* QVIT_MSG_WAL_CONNECTION_BLOCK_ENABLE_RSP */
    QMF_HDR	hdr;
    _WAL_STATUS  walStatus;   
}QVIT_Msg_Wal_Connection_Block_Enable_Rsp;

typedef struct QVIT_Msg_Wal_Connection_Block_Disable_Req{

    /* QVIT_MSG_WAL_CONNECTION_BLOCK_DISABLE_REQ */
    QMF_HDR	hdr;
    TARGET_PTR peerHandle;
    UINT32 module_id;
    UINT32 tid_bitmap;
}QVIT_Msg_Wal_Connection_Block_Disable_Req;

typedef struct QVIT_Msg_Wal_Connection_Block_Disable_Rsp{

    /* QVIT_MSG_WAL_CONNECTION_BLOCK_DISABLE_RSP */
    QMF_HDR	hdr;
    _WAL_STATUS  walStatus;   
}QVIT_Msg_Wal_Connection_Block_Disable_Rsp;

typedef struct QVIT_Msg_Wal_Connection_Pause_Send_Frames_Req{

    /* QVIT_MSG_WAL_CONNECTION_PAUSE_SEND_FRAMES_REQ */
    QMF_HDR hdr;
    TARGET_PTR peerHandle;
    UINT32 tidno;
    UINT16 num_frames;
    UINT8  flags;
}QVIT_Msg_Wal_Connection_Pause_Send_Frames_Req;

typedef struct QVIT_Msg_Wal_Connection_Pause_Send_Frames_Rsp{

    /* QVIT_MSG_WAL_CONNECTION_PAUSE_SEND_FRAMES_RSP */
    QMF_HDR hdr;
    _WAL_STATUS  walStatus;  
}QVIT_Msg_Wal_Connection_Pause_Send_Frames_Rsp;

typedef struct QVIT_Msg_Wal_Connection_Pause_Get_Paused_Tids_Req {
    /* QVIT_MSG_WAL_CONNECTION_PAUSE_GET_PAUSED_TIDS_REQ */
    QMF_HDR hdr;
    TARGET_PTR peerHandle;
    UINT32 tidmask;
}QVIT_Msg_Wal_Connection_Pause_Get_Paused_Tids_Req;

typedef struct QVIT_Msg_Wal_Connection_Pause_Get_Paused_Tids_Rsp {
    /* QVIT_MSG_WAL_CONNECTION_PAUSE_GET_PAUSED_TIDS_RSP*/
    QMF_HDR hdr;
    UINT32 tids;
}QVIT_Msg_Wal_Connection_Pause_Get_Paused_Tids_Rsp;

typedef struct QVIT_Msg_Wal_Connection_Pause_Get_Blocked_Tids_Req {
    /* QVIT_MSG_WAL_CONNECTION_PAUSE_GET_BLOCKED_TIDS_REQ */
    QMF_HDR hdr;
    TARGET_PTR peerHandle;
    UINT32 tidmask;
}QVIT_Msg_Wal_Connection_Pause_Get_Blocked_Tids_Req ;

typedef struct QVIT_Msg_Wal_Connection_Pause_Get_Blocked_Tids_Rsp {
    /* QVIT_MSG_WAL_CONNECTION_PAUSE_GET_BLOCKED_TIDS_RSP*/
    QMF_HDR hdr;
    UINT32 tids;
}QVIT_Msg_Wal_Connection_Pause_Get_Blocked_Tids_Rsp;

typedef struct QVIT_Msg_Wal_Connection_Pause_Get_Created_Tids_Req {
    /* QVIT_MSG_WAL_CONNECTION_PAUSE_GET_CREATED_TIDS_REQ */
    QMF_HDR hdr;
    TARGET_PTR peerHandle;
    UINT32 tidmask;
}QVIT_Msg_Wal_Connection_Pause_Get_Created_Tids_Req;

typedef struct QVIT_Msg_Wal_Connection_Pause_Get_Created_Tids_Rsp {
    /* QVIT_MSG_WAL_CONNECTION_PAUSE_GET_CREATED_TIDS_RSP*/
    QMF_HDR hdr;
    UINT32 tids;
}QVIT_Msg_Wal_Connection_Pause_Get_Created_Tids_Rsp;



#endif
