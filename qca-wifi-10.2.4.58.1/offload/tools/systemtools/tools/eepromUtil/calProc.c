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

// function definitions

#if defined(_printf)
#undef _printf
#endif
#define _printf printf

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
    if (FALSE == readCalDataFromFileBin(argv[1], (AR6K_EEPROM *)&eepromData)) {
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
#if 0
#define MAX_CHAN_5G  8
    for (ii=0; ii<MAX_CHAN_5G; ii++) {
        eepromData.calPierData5G[ii].olpcGainDelta 
        eepromData.calPierData5G[ii].thermCalVal  
    }
#endif 
#define MAX_CHAN_2G  3
    for (ii=0; ii<MAX_CHAN_2G; ii++) {
        fprintf(fp, "%d, %d, ", eepromData.calPierData2G[ii].olpcGainDelta, eepromData.calPierData2G[ii].thermCalVal ); 
        _printf("%d, %d, ", eepromData.calPierData2G[ii].olpcGainDelta, eepromData.calPierData2G[ii].thermCalVal ); 
    }
    fprintf(fp, "\n");

    if (fp) fclose(fp);

    return 0;
}

