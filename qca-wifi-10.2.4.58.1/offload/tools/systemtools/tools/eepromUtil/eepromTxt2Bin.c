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
extern A_UINT32  AR6003_EEPROM_SIZE;
extern A_UINT32  AR6K_EEPROM_SIZE;     

// function definitions
#if !defined(_USE_AS_API)
int MaxTempEntries = MAX_TEMPLATE_ENTRIES;
EEPROM_TEMP EepTempEntries[MAX_TEMPLATE_ENTRIES];
#endif

// TBD: find a better way than macro (to avoid any future trouble)
#define PARSE_BIN_COMM(size) \
    int i; \
    _printf("%s ", EepTempEntries[entry].key); \
    for (i=0;i<EepTempEntries[entry].num;i++) { \
        memcpy((void*)&value, (void*)(&pData[*pos]), (size_t)(size)); \
        *pos +=(size); \
        if (EepTempEntries[entry].hex == EEP_HEX_VAL) \
            _printf("0x%x ", value); \
        else if (EepTempEntries[entry].hex == EEP_DEC_VAL) \
            _printf("%d ", value); \
    } \
    _printf("\n");

#define PARSE_TXT_COMM(type, size)\
    A_UINT32 readVal;\
    if (EepTempEntries[entry].hex == EEP_HEX_VAL) {\
        if(!sscanf(pLine, "%x", &readVal)) {\
	    _printf("Error: unable to read value column %d at entry %d from %s\n", col, entry);\
        }\
        _printf("0x%x ", readVal);\
    }\
    else if (EepTempEntries[entry].hex == EEP_DEC_VAL) {\
	if(!sscanf(pLine, "%d", &readVal)) {\
	    _printf("Error: unable to read value column %d at entry %d from %s\n", col, entry);\
        }\
        _printf("%d ", readVal);\
    }\
    value = (type)readVal;\
    memcpy((void*)&pData[*pos], (void*)&value, (size_t)size);\
    (*pos) +=size;


A_BOOL parse_txt_uint8(char *pLine, A_UINT8 *pData, int entry, int *pos, int col)
{ 
    A_UINT8 value;
    //PARSE_TXT_COMM(A_UINT8, 1);
    A_UINT32 readVal;
    if (EepTempEntries[entry].hex == EEP_HEX_VAL) {
        if(!sscanf(pLine, "%x", &readVal)) {
	    _printf("Error: unable to read value column %d at entry %d from %s\n", col, entry);
        }
        _printf("0x%x ", readVal);
    }
    else if (EepTempEntries[entry].hex == EEP_DEC_VAL) {
	if(!sscanf(pLine, "%d", &readVal)) {
	    _printf("Error: unable to read value column %d at entry %d from %s\n", col, entry);
        }
        _printf("%d ", readVal);
    }
    value = (A_UINT8)readVal;
    memcpy((void*)&pData[*pos], (void*)&value, (size_t)1);
    (*pos) +=1;
    return TRUE;
}

A_BOOL parse_txt_uint32(char *pLine, A_UINT8 *pData, int entry, int *pos, int col)
{
    A_UINT32 value;
    PARSE_TXT_COMM(A_UINT32, 4);
    return TRUE;
}


A_BOOL parse_txt_int8(char *pLine, A_UINT8 *pData, int entry, int *pos, int col)
{
    A_INT8 value;
    PARSE_TXT_COMM(A_INT8, 1);
    return TRUE;
}

A_BOOL parse_txt_int16(char *pLine, A_UINT8 *pData, int entry, int *pos, int col)
{
    A_INT16 value;
    PARSE_TXT_COMM(A_INT16, 2);
    return TRUE;
}

A_BOOL parse_txt_int32(char *pLine, A_UINT8 *pData, int entry, int *pos, int col)
{
    A_INT32 value;
    PARSE_TXT_COMM(A_INT32, 4);
    return TRUE;
}

A_BOOL parse_txt_char(char *pLine, A_UINT8 *pData, int entry, int *pos, int col)
{
    A_UCHAR value;
    PARSE_TXT_COMM(A_UCHAR, 1);
    return TRUE;
}

A_BOOL parse_txt_uint16(char *pLine, A_UINT8 *pData, int entry, int *pos, int col)
{
    A_UINT16 value;
    PARSE_TXT_COMM(A_UINT16, 2);
    return TRUE;
}

typedef A_BOOL (*ParseTxtFunc)(char *pLine, A_UINT8 *pData, int entry, int *pos, int col);
ParseTxtFunc EepParserTxtFunc[] = {
    parse_txt_uint8, 
    parse_txt_uint16,
    parse_txt_uint32,
    parse_txt_int8, 
    parse_txt_int16,
    parse_txt_int32,
    parse_txt_char, 
};

A_BOOL parseEepromTxtFile(char *fileName, A_UINT8 *pData)
{
    FILE *fp;
    char lineBuf[MAX_LINE_BUF+2], *pLine;
    char key[MAX_KEY_LEN];
    char delimiters[] = " \t\n\r;=" ;
    int i, j, pos=0;

    _printf("\n..Reading in eeprom txt file %s\n", fileName);
    if( (fp = fopen( fileName, "r")) == NULL ) {
        _printf("Failed to open %s - using Defaults\n", fileName);
        return;
    }

    for (i=0;i<MaxTempEntries;i++) {
        if (fgets(lineBuf, MAX_LINE_BUF, fp) == NULL) {
            printf("End of text file %s after only entry %d.\n", fileName, i);
            break;
        }

	pLine = lineBuf;
	if (!sscanf(pLine, "%s", key)) {
	    _printf("Error reading %s from %s\n", lineBuf, fileName);
            continue; // or break?
	}
	if (strncmp(key, EepTempEntries[i].key, sizeof(EepTempEntries[i].key)) != 0) {
	    _printf("Error: data entry %s mismatch template entry %s\n", key, EepTempEntries[i].key);
            continue;
	} 
        _printf("%s ", key);
	for (j=0;j<EepTempEntries[i].num;j++) {
	    pLine = strchr(pLine, ' ');
	    pLine = strtok(pLine, delimiters);
            EepParserTxtFunc[EepTempEntries[i].type](pLine, pData, i, &pos, j);
	}
        _printf("\n");
    } //end of file					

    if (fp) fclose(fp);

    return(TRUE);

}

#if 0
static A_BOOL genEepromBinFile(char *fileName, AR6003_EEPROM *pEepStruct) 
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
#endif

#if defined(_USE_AS_API)
int _eepromTxt2Bin(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    FILE *fp;
    int i, j;
    AR6003_EEPROM eepromData;
    A_UINT8 *pData = (A_UINT8 *)&eepromData;

    if ((NULL != argv[1]) && (NULL != argv[2]) && (NULL != argv[3])) {
    }
    else {
        printf("Usage: eepromBin2Txt.out <eeprom template> <input eeprom text> <output eeprom bin>\n");
        return -1;
    }

#if !defined(_USE_AS_API)
    // read template 
    if (FALSE == readTemplate(argv[1])) {
        printf("Error reading template file %s \n", argv[1]);
        return -1;
    }
    else {
        _printf(".reading template file %s \n", argv[1]);
    }
#endif

    // parse eeprom txt and fill the binary data.
    if (FALSE == parseEepromTxtFile(argv[2], (A_UINT8 *)&eepromData)) {
        printf("Error reading EEPROM bin file %s \n", argv[2]);
        return -1;
    }
    else {
        _printf(".reading EEPROM bin file %s \n", argv[2]);

        if ((eepromData.baseEepHeader.version & AR6003_EEP_VER_MINOR_MASK) >= AR6003_EEP_MINOR_VER10) {
            _printf("New TPC scheme selected! %x\n", eepromData.baseEepHeader.version);
            AR6K_EEPROM_SIZE = AR6003_EEPROM_SIZE = AR6K_EEPROM_SIZE_LARGEST;
        }
        else if ((eepromData.baseEepHeader.version & AR6003_EEP_VER_MINOR_MASK) >= AR6003_EEP_MINOR_VER5) {
            _printf("New TPC scheme selected! %x\n", eepromData.baseEepHeader.version);
            AR6K_EEPROM_SIZE = AR6003_EEPROM_SIZE = AR6K_EEPROM_SIZE_VER5;
        }
        else if ((eepromData.baseEepHeader.version & AR6003_EEP_VER_MINOR_MASK) == AR6003_EEP_MINOR_VER2) {
            _printf("Old TPC scheme selected! %x\n", eepromData.baseEepHeader.version);
            AR6K_EEPROM_SIZE = AR6003_EEPROM_SIZE = AR6K_EEPROM_SIZE_PRIOR_VER4;
        }
        else {
            _printf("EEPROM file version %d not supported, please re-calibrate it.\n", eepromData.baseEepHeader.version);
        }

    }

    // generate binary file
    if (FALSE == genEepromBinFile(argv[3], &eepromData)) {
        printf("Error creating EEPROM bin file %s \n", argv[3]);
        return -1;
    }
    else {
        _printf(".created EEPROM bin file %s \n", argv[3]);
    }

    return 0;
}

