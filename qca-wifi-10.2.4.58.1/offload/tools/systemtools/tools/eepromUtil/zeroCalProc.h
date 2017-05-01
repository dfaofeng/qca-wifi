//-----------------------------------------------------------------------------
// calProc.h - Process calibration header include and definitions 
//
// Copyright (c) 2004 Atheros Communications, Inc., All Rights Reserved
//-----------------------------------------------------------------------------

#ifndef _ZEROCALPROC_H
#define _ZEROCALPROC_H

#define MAX_CAL_BOARDS 1000

#define uiPrintf printf

#define CALPROC_PROCCALDATA             "1"
#define CALPROC_SECCALDATA              "2"
#define CALPROC_PICKGOLDEN              "3"
#define CALPROC_NUMOFCOMMANDS           3

typedef struct calProcMenuStruct {
    char *id;
    int (*pFunc) (int numOfArgs, char **args);
} CalProcMenuStruct;
	
// defines
typedef struct _calDataPerFreqOlpc {
    A_INT32  olpcGainDelta;                                         
    A_UINT32 thermCalVal;                                           
    A_UINT32 voltCalVal;                                            
    A_INT32  olpcGainDeltaPALOn;                                   
} ZERO_CAL_DATA_PER_FREQ_OLPC;                      

typedef struct _calDataPerFreqOlpcExpanded {
    ZERO_CAL_DATA_PER_FREQ_OLPC olpcBasic;                      
    A_INT32 olpcGainDelta_t10;                                  
    A_INT32 desiredScaleCck_t10;                               
    A_INT32 desiredScale6M_t10;                                    
    A_INT32 desiredScale36M_t10;                                   
    A_INT32 desiredScale54M_t10;                                   
    A_INT32 desiredScaleMCS0HT20_t10;                              
    A_INT32 desiredScaleMCS7HT20_t10;                              
    A_INT32 desiredScaleMCS0HT40_t10;                              
    A_INT32 desiredScaleMCS7HT40_t10;                              
} ZERO_CAL_DATA_PER_FREQ_OLPC_EXPANDED;             

typedef struct _zeroCALData_struct {
    A_INT32 olpcGainDelta_t10;   
    A_INT32 desiredScaleCck_t10;  
    A_INT32 desiredScale6M_t10;    
    A_INT32 desiredScale36M_t10;    
    A_INT32 desiredScale54M_t10;     
    A_INT32 desiredScaleMCS0HT20_t10; 
    A_INT32 desiredScaleMCS7HT20_t10;
    A_INT32 desiredScaleMCS0HT40_t10; 
    A_INT32 desiredScaleMCS7HT40_t10;  
} ZERO_CAL_DATA;                        

typedef struct _brdFEDelta_struct {
    ZERO_CAL_DATA_PER_FREQ_OLPC_EXPANDED feDeltas[AR6003_NUM_2G_CAL_PIERS_EXPANDED];
    ZERO_CAL_DATA_PER_FREQ_OLPC_EXPANDED calData[AR6003_NUM_2G_CAL_PIERS_EXPANDED];
    A_INT32 numBoards;
    A_INT32 num2G;
    A_INT32 num5G;
} BOARD_FE_DELTA;

// globals & static
extern A_UINT32  AR6003_EEPROM_SIZE;
extern A_UINT32  AR6K_EEPROM_SIZE;     

#endif //_ZEROCALPROC_H
