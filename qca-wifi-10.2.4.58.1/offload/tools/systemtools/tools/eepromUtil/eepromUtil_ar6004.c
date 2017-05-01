#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "wlantype.h"
#if defined(_HOSTTOOLS_AR98XX)
#include "qc98xx_eeprom.h"
#else
#include "dk_ver.h"
#include "mEeprom.h"
#include "ar6004_eeprom.h"
#endif
#include "eepromUtil_ar6004.h"

A_UINT32  AR6000_EEPROM_SIZE;
A_UINT32  AR6K_EEPROM_SIZE;     

void computeChecksum(AR6000_EEPROM *pEepStruct);

int templateEntrySize(EEPROM_TEMP *tempEntry)
{
    int size=0;
    int numBits=0;
    int i;
    EEP_TYPE_BIT_FIELD *bitField;

    switch (tempEntry->type) {
        case EEP_UINT8:
            size = 1;
            break;
        case EEP_UINT16:
            size = 2;
            break;
        case EEP_UINT32:
            size = 4;
            break;
        case EEP_INT8:
            size = 1;
            break;
        case EEP_INT16:
            size = 2;
            break;
        case EEP_INT32:
            size = 4;
            break;
        case EEP_CHAR:
            size = 1;
            break;
        case EEP_BITFIELD:
            bitField=(EEP_TYPE_BIT_FIELD*)tempEntry->extra;
            for (i=0; i < bitField->numFields;i++) {
                numBits += bitField->numBits[i];
            }

            size = (numBits + 7) / 8;
            if (size > sizeof(A_UINT32)) {
                size = sizeof(A_UINT32);
                printf("Template entry %s has error bit field, total number of bits %d exceeded 32\n", tempEntry->key,numBits);
            }
            return size;
            break;
        default:
            printf("Template entry %s has invalid type %d\n", tempEntry->key,tempEntry->type);
            break;
    }
    
    return size*tempEntry->num;
}

A_BOOL parseBitFieldDef(char *lineBuf)
{
    char *token;
    char delimiters[] = " \t\n;:";
    int  i=0;
    EEP_TYPE_BIT_FIELD field;
    EEP_TYPE_BIT_FIELD *fields=&field;

    /* 
     * BitField definition:
     * NAME1:numBits;NAME2:numBits;NAME3:numBits;....;NAMEx:numBits 
     */
    fields->numFields=0;
    token = strtok(lineBuf,delimiters);
    while (token != NULL){
        if (i&1) {
            fields->numBits[fields->numFields] = atoi(token);
            fields->numFields++;
        }
        else {
            strcpy(fields->name[fields->numFields],token);
        }
        token = strtok(NULL,delimiters);
        i++;
    }
    memcpy(lineBuf,fields,sizeof(EEP_TYPE_BIT_FIELD));
    return(TRUE);
}

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
static char lineBuf[MAX_LINE_BUF+2];
A_BOOL readTemplate(char *fileName)
{
    FILE *fp;
    int i;
    int pos;

    if( (fp = fopen(fileName, "r")) == NULL) {
        printf("Could not open calDataFile %s\n", fileName);
        return FALSE;
    }

    i=0;
    pos=0;
    while((fgets(lineBuf, MAX_LINE_BUF, fp) != NULL))
    {
        if (strstr(lineBuf,"#"))
            continue;
        if (strstr(lineBuf,"/*"))
            continue;

        if ((sscanf(lineBuf, "%s %d %d %d %s\n", EepTempEntries[i].key, (int)&EepTempEntries[i].type, (int)&EepTempEntries[i].num, (int)&EepTempEntries[i].hex,EepTempEntries[i].extra))) {
            _printf("%s %d %d %d %s\n", EepTempEntries[i].key, EepTempEntries[i].type, EepTempEntries[i].num, EepTempEntries[i].hex,EepTempEntries[i].extra);
            if (EepTempEntries[i].type == EEP_BITFIELD) {
                parseBitFieldDef(EepTempEntries[i].extra);
            }
            EepTempEntryPos[i] = pos;
            pos += templateEntrySize(&EepTempEntries[i]);
            i++;
        }
    }
    MaxTempEntries=i;
    _printf("template entries: %d\n", MaxTempEntries);

    return TRUE;
}
#endif //#if !defined(_OTA_TOOL)


A_BOOL genEepromBinFile(char *fileName, AR6000_EEPROM *pEepStruct) 
{
    //A_UINT8 *pData = (A_UINT8 *)pEepStruct;
    FILE *fp;

    AR6K_EEPROM_SIZE = AR6000_EEPROM_SIZE = sizeof(AR6000_EEPROM);
    
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



A_BOOL readCalDataFromFileBin(char *fileName, AR6000_EEPROM *eepromData)
{
    FILE *fp;
    A_BOOL rc=TRUE;
    size_t numBytes;

    _printf("readCalDataFromFile - reading EEPROM file %s\n",fileName);
    AR6K_EEPROM_SIZE = AR6000_EEPROM_SIZE = sizeof(AR6000_EEPROM);

    if( (fp = fopen(fileName, "rb")) == NULL) {
        _printf("Could not open %s to read\n", fileName);
        return FALSE;
    }

    if (AR6K_EEPROM_SIZE == (numBytes = fread((A_UCHAR *)eepromData, 1, AR6K_EEPROM_SIZE, fp))) {
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
    //if (rc) {
    //    AR6K_EEPROM_SIZE = AR6000_EEPROM_SIZE = sizeof(AR6000_EEPROM);
    //}

    return rc;
}

#ifdef WIN32
A_UINT16 computeChecksumOnly(A_UINT16 *pHalf, A_UINT16 length)
{
    A_UINT16 sum = 0, i;
    for (i = 0; i < length; i++) { sum ^= *pHalf++; }
    return(sum);
}
#else
extern A_UINT16 computeChecksumOnly(A_UINT16 *pHalf, A_UINT16 length);
#endif

// There are two checksums now, one for the old 1024B, the other for the expanded section
// This function encapsulates both calculation, while maintaining the existing protocol
void computeChecksum(AR6000_EEPROM *pEepStruct)
{
    A_UINT16 sum, *pHalf;
    //A_UINT8 eepromVersion;
    AR6K_EEPROM_SIZE = AR6000_EEPROM_SIZE = sizeof(AR6000_EEPROM);
    
    pEepStruct->baseEepHeader.checksum = 0x0000;
    pHalf = (A_UINT16 *)pEepStruct;
    sum = computeChecksumOnly(pHalf, AR6K_EEPROM_SIZE/2);
    pEepStruct->baseEepHeader.checksum = 0xFFFF ^ sum;
}


