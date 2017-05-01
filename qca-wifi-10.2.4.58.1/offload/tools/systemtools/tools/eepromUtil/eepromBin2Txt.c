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
int MaxTempEntries = MAX_TEMPLATE_ENTRIES;
EEPROM_TEMP EepTempEntries[MAX_TEMPLATE_ENTRIES];


// function definitions

// TBD: find a better way than macro (to avoid any future trouble)
#define PARSE_BIN_COMM(size) \
    int i; \
    _printf("%s ", EepTempEntries[entry].key); \
    fprintf(fp, "%s ", EepTempEntries[entry].key); \
    for (i=0;i<EepTempEntries[entry].num;i++) { \
        memcpy((void*)&value, (void*)(&pData[*pos]), (size_t)(size)); \
        *pos +=(size); \
        if (EepTempEntries[entry].hex == EEP_HEX_VAL) {\
            _printf("0x%x ", value); \
            fprintf(fp, "0x%x ", value); \
        }\
        else if (EepTempEntries[entry].hex == EEP_DEC_VAL) {\
            _printf("%d ", value); \
            fprintf(fp, "%d ", value); \
        }\
    } \
    _printf("\n");\
    fprintf(fp,"\n");

A_BOOL parse_bin_uint8(FILE *fp, int entry, A_UINT8 *pData, int *pos)
{ 
    A_UINT8 value;
    PARSE_BIN_COMM(1);
    return TRUE;
}

A_BOOL parse_bin_uint32(FILE *fp, int entry, A_UINT8 *pData, int *pos)
{
    A_UINT32 value;
    PARSE_BIN_COMM(4);
    return TRUE;
}


A_BOOL parse_bin_int8(FILE *fp, int entry, A_UINT8 *pData, int *pos)
{
    A_INT8 value;
    PARSE_BIN_COMM(1);
    return TRUE;
}

A_BOOL parse_bin_int16(FILE *fp, int entry, A_UINT8 *pData, int *pos)
{
    A_INT16 value;
    PARSE_BIN_COMM(2);
    return TRUE;
}

A_BOOL parse_bin_int32(FILE *fp, int entry, A_UINT8 *pData, int *pos)
{
    A_INT32 value;
    PARSE_BIN_COMM(4);
    return TRUE;
}

A_BOOL parse_bin_char(FILE *fp, int entry, A_UINT8 *pData, int *pos)
{
    A_UCHAR value;
    PARSE_BIN_COMM(1);
    return TRUE;
}

A_BOOL parse_bin_uint16(FILE *fp, int entry, A_UINT8 *pData, int *pos)
{
    A_UINT16 value;
    PARSE_BIN_COMM(2);
    return TRUE;
}

typedef A_BOOL (*ParseBinFunc)(FILE *fp, int entry, A_UINT8 *pData, int *pos);
ParseBinFunc EepParserFunc[] = {
    parse_bin_uint8, 
    parse_bin_uint16,
    parse_bin_uint32,
    parse_bin_int8, 
    parse_bin_int16,
    parse_bin_int32,
    parse_bin_char, 
};

static A_BOOL parseBin(A_UINT8 *pData, int numBytes, char *fileName) 
{
    int i;
    int pos=0;
    FILE *fp;

    if( (fp = fopen(fileName, "w")) == NULL) {
        printf("Could not open %s to write\n", fileName);
        return FALSE;
    }

    for (i=0;i<MaxTempEntries;i++) {
        EepParserFunc[EepTempEntries[i].type](fp, i, pData, &pos); 
    }

    _printf(" parsed %d input %d\n", pos, numBytes);
    if (pos != numBytes) {
        printf("parsed %d not equal given %d bytes\n", pos, numBytes);
    }
    fclose(fp);

    return TRUE;
}

#if defined(_USE_AS_API)
int _eepromBin2Txt(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    FILE *fp;
    int i, j;
    AR6003_EEPROM eepromData;
    A_UINT8 *pData;

    if ((NULL != argv[1]) && (NULL != argv[2]) && (NULL != argv[3])) {
    }
    else {
        printf("Usage: eepromBin2Txt.out <eeprom template> <input eeprom.bin> <output eeprom.txt>\n");
        return -1;
    }

    // read template 
    if (FALSE == readTemplate(argv[1])) {
        printf("Error reading template file %s \n", argv[1]);
        return -1;
    }
    else {
        _printf(".reading template file %s \n", argv[1]);
    }

    // read the binary file back to verify
    if (FALSE == readCalDataFromFileBin(argv[2], (AR6K_EEPROM *)&eepromData)) {
        printf("Error reading EEPROM bin file %s \n", argv[2]);
        return -1;
    }
    else {
        _printf(".reading EEPROM bin file %s \n", argv[2]);
    }

    // parse bin file based on template
    pData = (A_UINT8 *)&eepromData;
    if (FALSE == parseBin(pData, AR6003_EEPROM_SIZE, argv[3])) {
        printf("Error parsing EEPROM bin file %s \n", argv[2]);
        return -1;
    }
    else {
        _printf(".parsed EEPROM bin file %s into text file %s\n", argv[2], argv[3]);
    }

    return 0;
}

