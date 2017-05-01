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

A_UINT32  AR6003_EEPROM_SIZE;
A_UINT32  AR6K_EEPROM_SIZE;     

void supportedFields(void)
{
    int i;
    printf("Supported fields: %d\n", NumOfAllowedKeys);
    for (i=0; i<NumOfAllowedKeys;i++) {
        printf("%s ", AllowedKeys[i]);
    }
    printf("\n");
}

#if !defined(_OTA_TOOL)
A_BOOL readTemplate(char *fileName)
{
    FILE *fp;
    int i;

    if( (fp = fopen(fileName, "r")) == NULL) {
        printf("Could not open calDataFile %s\n", fileName);
        return FALSE;
    }

    i=0;
    while (EOF != (fscanf(fp, "%s %d %d %d\n", EepTempEntries[i].key, &EepTempEntries[i].type, &EepTempEntries[i].num, &EepTempEntries[i].hex))) {
        _printf("%s %d %d %d\n", EepTempEntries[i].key, EepTempEntries[i].type, EepTempEntries[i].num, EepTempEntries[i].hex);
        i++;
    }
    MaxTempEntries=i;
    _printf("template entries: %d\n", MaxTempEntries);

    fclose(fp);
    return TRUE;
}
#endif //#if !defined(_OTA_TOOL)


A_BOOL genEepromBinFile(char *fileName, AR6003_EEPROM *pEepStruct) 
{
    A_UINT8 *pData = (A_UINT8 *)pEepStruct;
    FILE *fp;
    
    // re-computing checksum
    pEepStruct->baseEepHeader.checksum = 0;
    computeChecksum(pEepStruct);

    if ( (fp = fopen(fileName, "wb")) == NULL) {
        _printf("Error: open to write eeprom bin %s \n", fileName);
        return FALSE;
    }
    if (AR6K_EEPROM_SIZE != fwrite((A_UCHAR *)pEepStruct, 1, AR6K_EEPROM_SIZE, fp)) {
        _printf("Error: writing to %s\n", fileName);
    }
    if (fp) fclose(fp);
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
#if defined(ZERO_CAL_IN_PROGRESS)		
        if ((eepromData->baseEepHeader.version & AR6003_EEP_VER_MINOR_MASK) >= AR6003_EEP_MINOR_VER10) {
            _printf("New TPC scheme selected! %x\n", eepromData->baseEepHeader.version);
            //if (AR6K_EEPROM_SIZE_LARGEST != numBytes) {
            //    uiPrintf("Num of bytes read %d mismatch expected %d\n", numBytes, AR6K_EEPROM_SIZE_LARGEST);
            //    rc = FALSE;
            //}
            //else {
                AR6K_EEPROM_SIZE = AR6003_EEPROM_SIZE = AR6K_EEPROM_SIZE_LARGEST;
            //}
        }
        else 
#endif			
        if ((eepromData->baseEepHeader.version & AR6003_EEP_VER_MINOR_MASK) >= AR6003_EEP_MINOR_VER5) {
            _printf("New TPC scheme selected! %x\n", eepromData->baseEepHeader.version);
            //if (AR6K_EEPROM_SIZE_VER5 != numBytes) {
            //    _printf("Num of bytes read %d mismatch expected %d\n", numBytes, AR6K_EEPROM_SIZE_VER5);
            //    rc = FALSE;
            //}
            //else {
                AR6K_EEPROM_SIZE = AR6003_EEPROM_SIZE = AR6K_EEPROM_SIZE_VER5;
            //}
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

A_UINT16 computeChecksumOnly(A_UINT16 *pHalf, A_UINT16 length)
{
    A_UINT16 sum = 0, i;
    for (i = 0; i < length; i++) { sum ^= *pHalf++; }
    return(sum);
}

// There are two checksums now, one for the old 1024B, the other for the expanded section
// This function encapsulates both calculation, while maintaining the existing protocol
void computeChecksum(AR6K_EEPROM *pEepStruct)
{
  A_UINT16 sum, *pHalf, i;
  A_UINT8 eepromVersion;
    
  eepromVersion = pEepStruct->baseEepHeader.version & AR6003_EEP_VER_MINOR_MASK;
  if (eepromVersion >= AR6003_EEP_MINOR_VER5) {
    // first checksum
    pEepStruct->baseEepHeader.checksum = 0x0000;
    pHalf = (A_UINT16 *)pEepStruct;
    sum = computeChecksumOnly(pHalf, AR6K_EEPROM_SIZE_PRIOR_VER4/2);
    pEepStruct->baseEepHeader.checksum = 0xFFFF ^ sum;

    // second (expanded checksum)
    pEepStruct->checksumExpanded = 0x0000;
    //pHalf = (A_UINT16*)(pEepStruct->calFreqPier5GExpanded);
    pHalf = (A_UINT16 *)pEepStruct;
    pHalf += AR6K_EEPROM_SIZE_PRIOR_VER4/2;
    sum = computeChecksumOnly(pHalf, (AR6003_EEPROM_SIZE - AR6K_EEPROM_SIZE_PRIOR_VER4)/2);
    pEepStruct->checksumExpanded = 0xFFFF ^ sum;

    _printf("--computeChecksum old 0x%x expanded 0x%x\n", pEepStruct->baseEepHeader.checksum, pEepStruct->checksumExpanded);
  }
  else {
    pEepStruct->baseEepHeader.checksum = 0x0000;
    pHalf = (A_UINT16 *)pEepStruct;
    sum = computeChecksumOnly(pHalf, AR6K_EEPROM_SIZE_PRIOR_VER4/2);
    pEepStruct->baseEepHeader.checksum = 0xFFFF ^ sum;
    _printf("--computeChecksum old 0x%x\n", pEepStruct->baseEepHeader.checksum);
  }
}


