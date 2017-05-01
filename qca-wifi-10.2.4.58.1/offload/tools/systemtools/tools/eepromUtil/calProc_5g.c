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

// defines

// globals & static
A_UINT32  AR6003_EEPROM_SIZE;
A_UINT32  AR6K_EEPROM_SIZE;     
A_BOOL    newTPCScheme=FALSE;
A_INT32   numPier5G, numPier2G;

// function definitions

#if defined(_printf)
#undef _printf
#endif
#define _printf printf

static A_BOOL deriveNumCalChans_NewTPC(AR6K_EEPROM *eepromData, A_UINT32 *numPier5G, A_UINT32 *numPier2G)
{
    A_UINT32 num5G=0, num2G=0, i;
    for (i=0; i<AR6003_NUM_5G_CAL_PIERS_EXPANDED; i++) {
        if ((AR6003_BCHAN_UNUSED == eepromData->calFreqPier5GExpanded[i]) || (0 == eepromData->calFreqPier5GExpanded[i])) { 
            break; 
        } 
        else
            num5G++;
    }
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

static A_BOOL deriveNumCalChans_OldTPC(AR6K_EEPROM *eepromData, A_UINT32 *numPier5G, A_UINT32 *numPier2G)
{
    A_UINT32 num5G=0, num2G=0, i;
    for (i=0; i<AR6003_NUM_5G_CAL_PIERS; i++) {
        if ((AR6003_BCHAN_UNUSED == eepromData->calFreqPier5G[i]) || (0 == eepromData->calFreqPier5G[i])) { 
            break; 
        } 
        else
            num5G++;
    }
    for (i=0; i<AR6003_NUM_2G_CAL_PIERS; i++) {
        if ((AR6003_BCHAN_UNUSED == eepromData->calFreqPier2G[i]) || (0 == eepromData->calFreqPier2G[i])) { 
            break; 
        } 
        else
            num2G++;
    }
    *numPier5G = num5G;
    *numPier2G = num2G;
    return(TRUE);
}

A_BOOL readCalDataFromFileBin(char *fileName, AR6003_EEPROM *eepromData)
{
    FILE *fp;
    A_BOOL rc=TRUE;
    size_t numBytes;

    _printf("readCalDataFromFile - reading EEPROM file %s\n",fileName);
    if( (fp = fopen(fileName, "rb")) == NULL) {
        _printf("Could not open %s to read\n", fileName);
        return FALSE;
    }

    if (AR6K_EEPROM_SIZE_LARGEST == (numBytes = fread((A_UCHAR *)eepromData, 1, AR6K_EEPROM_SIZE_LARGEST, fp))) {
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
    if (rc) {
        if ((eepromData->baseEepHeader.version & AR6003_EEP_VER_MINOR_MASK) >= AR6003_EEP_MINOR_VER5) {
            _printf("New TPC scheme selected! %x\n", eepromData->baseEepHeader.version);
            if (AR6K_EEPROM_SIZE_LARGEST != numBytes) {
                _printf("Num of bytes read %d mismatch expected %d\n", numBytes, AR6K_EEPROM_SIZE_VER5);
                rc = FALSE;
            }
            else {
                AR6K_EEPROM_SIZE = AR6003_EEPROM_SIZE = AR6K_EEPROM_SIZE_LARGEST;
            }
        }
        else if ((eepromData->baseEepHeader.version & AR6003_EEP_VER_MINOR_MASK) == AR6003_EEP_MINOR_VER2) {
            _printf("Old TPC scheme selected! %x\n", eepromData->baseEepHeader.version);
            if (AR6K_EEPROM_SIZE_PRIOR_VER4 != numBytes) {
                _printf("Num of bytes read %d mismatch expected %d\n", numBytes, AR6K_EEPROM_SIZE_PRIOR_VER4);
                rc = FALSE;
            }
            else {
                AR6K_EEPROM_SIZE = AR6003_EEPROM_SIZE = AR6K_EEPROM_SIZE_PRIOR_VER4;
            }
        }
        else {
            _printf("EEPROM file version %d not supported, please re-calibrate it.\n", eepromData->baseEepHeader.version);
            rc = FALSE;
        }
    }

    return rc;
}


A_BOOL readCalDataFromFile(char *fileName, AR6K_EEPROM *eepromData)
{
    FILE *fp;
    A_BOOL rc=TRUE, recomputeChksum=FALSE;
    size_t numBytes;

    _printf("readCalDataFromFile - reading EEPROM file %s\n",fileName);
    // write to binary file
    if( (fp = fopen(fileName, "rb")) == NULL) {
        _printf("Could not open %s to read\n", fileName);
        return FALSE;
    }

    if (AR6K_EEPROM_SIZE_LARGEST == (numBytes = fread((A_UCHAR *)eepromData, 1, AR6K_EEPROM_SIZE_LARGEST, fp))) {
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
    if (rc) {
        if ((eepromData->baseEepHeader.version & AR6003_EEP_VER_MINOR_MASK) >= AR6003_EEP_MINOR_VER5) {
            _printf("New TPC scheme selected! %x\n", eepromData->baseEepHeader.version);
            if (AR6K_EEPROM_SIZE_LARGEST != numBytes) {
                _printf("Num of bytes read %d mismatch expected %d\n", numBytes, AR6K_EEPROM_SIZE_LARGEST);
                rc = FALSE;
            }
            else {
                newTPCScheme = TRUE;
                AR6K_EEPROM_SIZE = AR6003_EEPROM_SIZE = AR6K_EEPROM_SIZE_LARGEST;
            }
            rc = deriveNumCalChans_NewTPC(eepromData, &numPier5G, &numPier2G);
        }
        else if ((eepromData->baseEepHeader.version & AR6003_EEP_VER_MINOR_MASK) <= AR6003_EEP_MINOR_VER4) {
            _printf("Old TPC scheme selected! %x\n", eepromData->baseEepHeader.version);
            if (AR6K_EEPROM_SIZE_PRIOR_VER4 != numBytes) {
                _printf("Num of bytes read %d mismatch expected %d\n", numBytes, AR6K_EEPROM_SIZE_PRIOR_VER4);
                rc = FALSE;
            }
            else {
                AR6K_EEPROM_SIZE = AR6003_EEPROM_SIZE = AR6K_EEPROM_SIZE_PRIOR_VER4;
            }
            rc = deriveNumCalChans_OldTPC(eepromData, &numPier5G, &numPier2G);
        }
        else {
            _printf("EEPROM file version %d not supported, please re-calibrate it.\n", eepromData->baseEepHeader.version);
            rc = FALSE;
        }
    }

    return rc;
}


int main(int argc, char *argv[])
{
    AR6003_EEPROM eepromData;
    char fileName[50] = "./calData/caldata.csv";
    FILE *fp;
    int ii;

    if ((NULL != argv[1]) ) {
    }
    else {
        printf("Usage: eepromBin2Txt.out <eeprom template> <input eeprom.bin> <output eeprom.txt>\n");
        return -1;
    }
    // read the binary file back to verify
    //if (FALSE == readCalDataFromFileBin(argv[1], (AR6K_EEPROM *)&eepromData)) 
    if (FALSE == readCalDataFromFile(argv[1], (AR6K_EEPROM *)&eepromData)) {
        printf("Error reading EEPROM bin file %s \n", argv[1]);
        return -1;
    }
    else {
        _printf(".reading EEPROM bin file %s \n", argv[1]);
    }

    if( (fp = fopen(fileName, "a")) == NULL) {
        printf("Could not open %s to read\n", fileName);
        return -1;
    }

    // 5G
    for (ii=0; ii<numPier5G; ii++) {
        if (newTPCScheme) {
        fprintf(fp, "%d, %d, ", eepromData.calPierData5GExpanded[ii].olpcBasic.olpcGainDelta, eepromData.calPierData5GExpanded[ii].olpcBasic.thermCalVal ); 
        _printf("%d, %d, ", eepromData.calPierData5GExpanded[ii].olpcBasic.olpcGainDelta, eepromData.calPierData5GExpanded[ii].olpcBasic.thermCalVal ); 
        }
        else {
        fprintf(fp, "%d, %d, ", eepromData.calPierData5G[ii].olpcGainDelta, eepromData.calPierData5G[ii].thermCalVal ); 
        _printf("%d, %d, ", eepromData.calPierData5G[ii].olpcGainDelta, eepromData.calPierData5G[ii].thermCalVal ); 
        }
    }
    fprintf(fp, "\n");

    if (fp) fclose(fp);

    return 0;
}

