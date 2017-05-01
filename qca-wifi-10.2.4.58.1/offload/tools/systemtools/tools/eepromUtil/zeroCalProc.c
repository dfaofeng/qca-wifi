//-----------------------------------------------------------------------------

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "wlantype.h"
#include "dk_ver.h"
#include "mEeprom.h"
#include "mEepStruct6003.h"
#include "eepromUtil.h"
#include "zeroCalProc.h"

// defines

// function prototypes
int retrieveFEDeltas(int numOfArgs, char **args);
int readFEDeltas(int numOfArgs, char **args);
int createBrdGldBin(int numOfArgs, char **args);

static A_BOOL readBinStream(char *fileName, void *byteStream, size_t totalNumBytes);
static A_BOOL writeBinStream(char *fileName, void *byteStream, size_t numBytes);

// globals & static
CalProcMenuStruct CalProcMenu[] = {
    {CALPROC_PROCCALDATA,   retrieveFEDeltas},
    {CALPROC_SECCALDATA,    readFEDeltas},
    {CALPROC_PICKGOLDEN,    createBrdGldBin}
};

A_UINT32  AR6003_EEPROM_SIZE;
A_UINT32  AR6K_EEPROM_SIZE;     
static int      numBoards;

// Keep eepromUtil.c happey
int MaxTempEntries = 512;
EEPROM_TEMP EepTempEntries[MAX_TEMPLATE_ENTRIES];

#if defined(_printf)
#undef _printf
#endif
#define _printf printf

// copied from otp_routines.c, should be compile in .. TBD??
static A_BOOL deriveNumCalChans_NewTPC(AR6K_EEPROM *eepromData, int *numPier5G, int *numPier2G)
{
    int num5G=0, num2G=0, i;
#if 0
    for (i=0; i<AR6003_NUM_5G_CAL_PIERS_EXPANDED; i++) {
        if ((AR6003_BCHAN_UNUSED == eepromData->calFreqPier5GExpanded[i]) || (0 == eepromData->calFreqPier5GExpanded[i])) { 
            break; 
        } 
        else
            num5G++;
    }
#endif
    for (i=0; i<AR6003_NUM_2G_CAL_PIERS_EXPANDED; i++) {
        if ((AR6003_BCHAN_UNUSED == eepromData->calFreqPier2GExpanded[i]) || (0 == eepromData->calFreqPier2GExpanded[i])) { 
            break; 
        } 
        else
            num2G++;
    }
    *numPier5G = num5G;
    *numPier2G = num2G;
    return(TRUE);
}

static void avgCalData(ZERO_CAL_DATA_PER_FREQ_OLPC_EXPANDED *calData, int numBoards) {
    calData->olpcGainDelta_t10        /= numBoards;
    calData->desiredScaleCck_t10      /= numBoards;
    calData->desiredScale6M_t10       /= numBoards;
    calData->desiredScale36M_t10      /= numBoards;
    calData->desiredScale54M_t10      /= numBoards;
    calData->desiredScaleMCS0HT20_t10 /= numBoards;
    calData->desiredScaleMCS7HT20_t10 /= numBoards;
    calData->desiredScaleMCS0HT40_t10 /= numBoards;
    calData->desiredScaleMCS7HT40_t10 /= numBoards;
    return;
}

int readFEDeltas(int numOfArgs, char **args)
{
    char avgFEFile[50]="_tmpFEAvg.bin"; 
    char avgFEFileTxt[50]="_tmpFEAvg.txt"; 
    BOARD_FE_DELTA feDelta;
    FILE *fp;
    int i;
   
    // read average so far
    readBinStream(avgFEFile, (void*)&feDelta, sizeof(feDelta));
    
    // average
    if ((fp = fopen(avgFEFileTxt, "w")) == NULL) {
        printf("Error openning avgFEdelta file %s\n", avgFEFileTxt);
        return(-1);
    } 
    for (i=0;i<feDelta.num2G;i++) {
        avgCalData(&(feDelta.calData[i]),  feDelta.numBoards);
        avgCalData(&(feDelta.feDeltas[i]), feDelta.numBoards);

#if defined(DEBUG)
        fprintf(fp, "BRD, %d,%d,%d,%d,%d,%d,%d,%d,%d, ",
        feDelta.calData[i].olpcGainDelta_t10,       
        feDelta.calData[i].desiredScaleCck_t10,    
        feDelta.calData[i].desiredScale6M_t10,    
        feDelta.calData[i].desiredScale36M_t10,  
        feDelta.calData[i].desiredScale54M_t10, 
        feDelta.calData[i].desiredScaleMCS0HT20_t10,
        feDelta.calData[i].desiredScaleMCS7HT20_t10,
        feDelta.calData[i].desiredScaleMCS0HT40_t10,
        feDelta.calData[i].desiredScaleMCS7HT40_t10);

        fprintf(fp, "FE, %d,%d,%d,%d,%d,%d,%d,%d,%d\n",
        feDelta.feDeltas[i].olpcGainDelta_t10,       
        feDelta.feDeltas[i].desiredScaleCck_t10,    
        feDelta.feDeltas[i].desiredScale6M_t10,    
        feDelta.feDeltas[i].desiredScale36M_t10,  
        feDelta.feDeltas[i].desiredScale54M_t10, 
        feDelta.feDeltas[i].desiredScaleMCS0HT20_t10,
        feDelta.feDeltas[i].desiredScaleMCS7HT20_t10,
        feDelta.feDeltas[i].desiredScaleMCS0HT40_t10,
        feDelta.feDeltas[i].desiredScaleMCS7HT40_t10);
#endif
    } 
    if (fp) fclose(fp);

    // write back to the avg file for next bin file processing
    writeBinStream(avgFEFile, (void*)&feDelta, sizeof(feDelta));

    return 0;

}

static void setCalData(AR6003_CAL_DATA_PER_FREQ_OLPC_FE_DELTA *dst, ZERO_CAL_DATA_PER_FREQ_OLPC_EXPANDED *src) {
    dst->olpcGainDelta_t10       =(A_INT16)src->olpcGainDelta_t10;      
    dst->desiredScaleCck_t10     =(A_INT8)src->desiredScaleCck_t10;    
    dst->desiredScale6M_t10      =(A_INT8)src->desiredScale6M_t10;      
    dst->desiredScale36M_t10     =(A_INT8)src->desiredScale36M_t10;     
    dst->desiredScale54M_t10     =(A_INT8)src->desiredScale54M_t10;     
    dst->desiredScaleMCS0HT20_t10=(A_INT8)src->desiredScaleMCS0HT20_t10;
    dst->desiredScaleMCS7HT20_t10=(A_INT8)src->desiredScaleMCS7HT20_t10;
    dst->desiredScaleMCS0HT40_t10=(A_INT8)src->desiredScaleMCS0HT40_t10;
    dst->desiredScaleMCS7HT40_t10=(A_INT8)src->desiredScaleMCS7HT40_t10;
    return;
}

int createBrdGldBin(int numOfArgs, char **args)
{
#if defined(ZERO_CAL_IN_PROGRESS)
    AR6003_EEPROM brdEepromData;
    BOARD_FE_DELTA feDelta;
    FILE *fp;
    char avgFEFile[50]="_tmpFEAvg.bin"; 
    char brdGoldCAL[50]="brdGoldenCAL.bin"; 
    int i;

    // read one of the board CAL bin, and use it as base
    if (FALSE == readCalDataFromFileBin(args[1], (AR6K_EEPROM *)&brdEepromData)) {
        printf("Error reading EEPROM bin file %s \n", args[1]);
        return -1;
    }
    else {
        _printf(".read EEPROM bin file %s \n", args[1]);
    }

    // replace relevant sections of board eeprom data with GG eeprom data
    readBinStream(avgFEFile, (void*)&feDelta, sizeof(feDelta));
    for (i=0;i<feDelta.num2G;i++) {
        setCalData((AR6003_CAL_DATA_PER_FREQ_OLPC_FE_DELTA*)&(brdEepromData.calPierData2GExpanded[i].olpcGainDelta_t10), &(feDelta.calData[i]));      
        setCalData((AR6003_CAL_DATA_PER_FREQ_OLPC_FE_DELTA*)&(brdEepromData.calDataFEDelta[i].olpcGainDelta_t10), &(feDelta.feDeltas[i]));      
        // update olpcGainDelta (0.5dB resolution)
        brdEepromData.calPierData2GExpanded[i].olpcBasic.olpcGainDelta = brdEepromData.calPierData2GExpanded[i].olpcGainDelta_t10 /5;
    }

    computeChecksum(&brdEepromData);

    if ( (fp = fopen(brdGoldCAL, "wb")) == NULL) {
        _printf("Error: open to write eeprom bin %s \n", brdGoldCAL);
        return FALSE;
    }
    if (AR6K_EEPROM_SIZE != fwrite((A_UCHAR *)&brdEepromData, 1, AR6K_EEPROM_SIZE, fp)) {
        _printf("Error: writing to %s\n", brdGoldCAL);
    }
    if (fp) fclose(fp);
#endif
    return 0;
}


static A_BOOL readBinStream(char *fileName, void *byteStream, size_t totalNumBytes)
{
    FILE *fp;
    A_BOOL rc=TRUE;
    size_t numBytes;

    _printf("readBinStream file %s\n",fileName);
    if( (fp = fopen(fileName, "rb")) == NULL) {
        _printf("Could not open %s to read\n", fileName);
        return FALSE;
    }

    if (totalNumBytes == (numBytes = fread((A_UCHAR *)byteStream, 1, totalNumBytes, fp))) {
        _printf("Read %d from %s\n", numBytes, fileName);  
        rc = TRUE;
    }
    else {
        if (feof(fp)) {
            _printf("Read %d from %s\n", numBytes, fileName);  
            rc = TRUE;
        } 
        else if (ferror(fp)) {
            _printf("Error reading %s\n", fileName);
            rc = FALSE;
        }
        else { _printf("Unknown fread rc\n"); rc = FALSE; }
    }
    if (fp) fclose(fp);
    return rc;
}

static A_BOOL writeBinStream(char *fileName, void *byteStream, size_t numBytes)
{
    FILE *fStream;
    if( (fStream = fopen(fileName, "wb")) == NULL) {
        uiPrintf("Could not open calDataFile %s to write\n", fileName);
        return FALSE;
    }
    if (numBytes != fwrite((A_UCHAR *)byteStream, 1, numBytes, fStream)) {
        uiPrintf("Error writing to %s\n", fileName);
    }
    if (fStream) fclose(fStream);

    uiPrintf("... written to %s\n", fileName);

    return(TRUE);
}

static void totalCalData(ZERO_CAL_DATA_PER_FREQ_OLPC_EXPANDED *total, AR6003_CAL_DATA_PER_FREQ_OLPC_FE_DELTA *src)
{
    total->olpcGainDelta_t10        += (A_INT32)src->olpcGainDelta_t10; 
    total->desiredScaleCck_t10      += (A_INT32)src->desiredScaleCck_t10; 
    total->desiredScale6M_t10       += (A_INT32)src->desiredScale6M_t10; 
    total->desiredScale36M_t10      += (A_INT32)src->desiredScale36M_t10; 
    total->desiredScale54M_t10      += (A_INT32)src->desiredScale54M_t10; 
    total->desiredScaleMCS0HT20_t10 += (A_INT32)src->desiredScaleMCS0HT20_t10;
    total->desiredScaleMCS7HT20_t10 += (A_INT32)src->desiredScaleMCS7HT20_t10;
    total->desiredScaleMCS0HT40_t10 += (A_INT32)src->desiredScaleMCS0HT40_t10;
    total->desiredScaleMCS7HT40_t10 += (A_INT32)src->desiredScaleMCS7HT40_t10;
}

int retrieveFEDeltas(int numOfArgs, char **args)
{
#if defined(ZERO_CAL_IN_PROGRESS)
    AR6003_EEPROM eepromData;
    char fileName[100], avgFEFile[50]="_tmpFEAvg.bin"; 
    FILE *fp;
    int i;
    int numPier5G, numPier2G;
    BOARD_FE_DELTA feDelta;

    // read the FE average
    memset((void*)&feDelta, 0, sizeof(feDelta));
    readBinStream(avgFEFile, (void*)&feDelta, sizeof(feDelta));

    // read the binary file back to verify
    if (FALSE == readCalDataFromFileBin(args[1], (AR6K_EEPROM *)&eepromData)) {
        printf("Error reading EEPROM bin file %s \n", args[1]);
        return -1;
    }
    else {
        _printf(".read EEPROM bin file %s \n", args[1]);
    }

    if (!deriveNumCalChans_NewTPC(&eepromData, &numPier5G, &numPier2G)) {
        printf("Error: finding the number channels\n");
        return -1;
    }

    for (i=0; i<numPier2G; i++) {
#if defined(DEBUG)
        sprintf(fileName, "zeroCalData/zCalFEDelta_%d.csv", FBIN2FREQ(eepromData.calFreqPier2GExpanded[i], TRUE));
        if( (fp = fopen(fileName, "a")) == NULL) {
            printf("Could not open %s to read\n", fileName);
            return -1;
        }

        fprintf(fp, "%s,%d, BRD, %d, %d, %d, %d, %d, %d, %d, %d, %d, FE, ", 
                args[1],
                FBIN2FREQ(eepromData.calFreqPier2GExpanded[i],  TRUE),
                eepromData.calPierData2GExpanded[i].olpcGainDelta_t10, 
                eepromData.calPierData2GExpanded[i].desiredScaleCck_t10, 
                eepromData.calPierData2GExpanded[i].desiredScale6M_t10, 
                eepromData.calPierData2GExpanded[i].desiredScale36M_t10, 
                eepromData.calPierData2GExpanded[i].desiredScale54M_t10, 
                eepromData.calPierData2GExpanded[i].desiredScaleMCS0HT20_t10,
                eepromData.calPierData2GExpanded[i].desiredScaleMCS7HT20_t10,
                eepromData.calPierData2GExpanded[i].desiredScaleMCS0HT40_t10,
                eepromData.calPierData2GExpanded[i].desiredScaleMCS7HT40_t10);
        fprintf(fp, "%d, %d, %d, %d, %d, %d, %d, %d, %d \n", 
                eepromData.calDataFEDelta[i].olpcGainDelta_t10, 
                eepromData.calDataFEDelta[i].desiredScaleCck_t10, 
                eepromData.calDataFEDelta[i].desiredScale6M_t10, 
                eepromData.calDataFEDelta[i].desiredScale36M_t10, 
                eepromData.calDataFEDelta[i].desiredScale54M_t10, 
                eepromData.calDataFEDelta[i].desiredScaleMCS0HT20_t10,
                eepromData.calDataFEDelta[i].desiredScaleMCS7HT20_t10,
                eepromData.calDataFEDelta[i].desiredScaleMCS0HT40_t10,
                eepromData.calDataFEDelta[i].desiredScaleMCS7HT40_t10);
        if (fp) fclose(fp);
#endif
        // add to FE delta sum, for later averaging
        totalCalData(&(feDelta.calData[i]), (AR6003_CAL_DATA_PER_FREQ_OLPC_FE_DELTA *)&(eepromData.calPierData2GExpanded[i].olpcGainDelta_t10));
        totalCalData(&(feDelta.feDeltas[i]), &(eepromData.calDataFEDelta[i]));
    }    

    // write back to the avg file for next bin file processing
    feDelta.numBoards++;
    feDelta.num2G = numPier2G;
    feDelta.num5G = numPier5G;
    writeBinStream(avgFEFile, (void*)&feDelta, sizeof(feDelta));
#endif
    return 0;
}


int main(int argc, char *argv[])
{
    int numOfArgs, i;
    char **args;

    if (argc < 2)
    {
        printf ("Invalid number of arguments\n");
        return -1;
    }

    for (i = 0; i < CALPROC_NUMOFCOMMANDS; ++i)
    {
        if (strcmp(argv[1], CalProcMenu[i].id) == 0)
        {
            numOfArgs = argc - 1;
            args = &argv[1];

            return (CalProcMenu[i].pFunc (numOfArgs, args));
        }
    }

    printf ("Invalid command\n");
    return -1;
}

