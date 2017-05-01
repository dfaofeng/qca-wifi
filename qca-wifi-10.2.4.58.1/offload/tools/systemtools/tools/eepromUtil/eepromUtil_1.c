#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "wlantype.h"
#include "eepromUtil_1.h"

// globals & static
int MaxTempEntries = MAX_TEMPLATE_ENTRIES;
EEPROM_TEMP EepTempEntries[MAX_TEMPLATE_ENTRIES];
int EepTempEntryPos[MAX_TEMPLATE_ENTRIES];

void computeChecksum(A_UINT8 *pData, A_UINT16 length, A_UINT16 *checkSum);

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
	return TRUE;
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

EEPROMUTILDLLSPEC A_BOOL genEepromBinFile(char *fileName, A_UINT8 *pData, A_UINT16 length, A_UINT16 *checkSum)
{
    //A_UINT8 *pData = (A_UINT8 *)pEepStruct;
    FILE *fp;
  
    // re-computing checksum
    computeChecksum(pData, length, checkSum);

    if ( (fp = fopen(fileName, "wb")) == NULL) {
        _printf("Error: open to write eeprom bin %s \n", fileName);
        return FALSE;
    }
    if (length != fwrite(pData, 1, length, fp)) {
        _printf("Error: writing to %s\n", fileName);
    }
    if (fp) fclose(fp);
    return(TRUE);
}

EEPROMUTILDLLSPEC A_BOOL genEepromTemplateHFile(char *fileName, A_UINT8 *pData, A_UINT16 length, A_UINT16 *checkSum)
{
    //A_UINT8 *pData = (A_UINT8 *)pEepStruct;
    FILE *fp;
	unsigned char buffer[300];
	unsigned char templateName[300];
	int i, j;
  
    // re-computing checksum
    computeChecksum(pData, length, checkSum);

    if ( (fp = fopen(fileName, "w")) == NULL) {
        _printf("Error: open %s file\n", fileName);
        return FALSE;
    }

	strcpy(templateName, fileName);
	templateName[strlen(templateName)-2] = 0; //remove .h#
	
	fprintf(fp, "//\n");
	fprintf(fp, "// This files is generated from EepromUtil. Do not modify it.\n");
	fprintf(fp, "//\n");
	fprintf(fp, "#ifndef __%s_h__\n", templateName);
	fprintf(fp, "#define __%s_h__\n\n", templateName);
	fprintf(fp, "static unsigned char %s[] = \n", templateName);
	fprintf(fp, "{\n");

	i = 0;
	while (i < length)
	{
		fprintf(fp, "    ");
		for (j = i; (j < i+16) && j < length; j++)
		{
			fprintf(fp, "0x%02x,", pData[j]);
		}
		fprintf(fp, "\n");
		i = j;
	}

	fprintf(fp, "};\n\n");
	fprintf(fp, "#endif //__%s_h__\n\n", templateName);

    fclose(fp);
    return(TRUE);
}

A_BOOL readCalDataFromFileBin(char *fileName, A_UCHAR *pData, A_UINT16 length)
{
    FILE *fp;
    A_BOOL rc=TRUE;
    size_t numBytes;

    _printf("readCalDataFromFile - reading EEPROM file %s\n",fileName);

    if( (fp = fopen(fileName, "rb")) == NULL) {
        _printf("Could not open %s to read\n", fileName);
        return FALSE;
    }

    if (length == (numBytes = fread(pData, 1, length, fp))) {
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

A_UINT16 computeChecksumOnly(A_UINT16 *pHalf, A_UINT16 length)
{
    A_UINT16 sum = 0, i;
    for (i = 0; i < length; i++) { sum ^= *pHalf++; }
    return(sum);
}

// There are two checksums now, one for the old 1024B, the other for the expanded section
// This function encapsulates both calculation, while maintaining the existing protocol
void computeChecksum(A_UINT8 *pData, A_UINT16 length, A_UINT16 *checkSum)//AR6000_EEPROM *pEepStruct)
{
    A_UINT16 sum, *pHalf;
    
	*checkSum = 0;
    pHalf = (A_UINT16 *)pData;
    sum = computeChecksumOnly(pHalf, length/2);
	*checkSum = 0xFFFF ^ sum;
}


