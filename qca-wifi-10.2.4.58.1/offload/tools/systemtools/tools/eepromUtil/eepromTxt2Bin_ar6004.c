//-----------------------------------------------------------------------------

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "wlantype.h"
#include "dk_ver.h"
#include "mEeprom.h"
//#include "mEepStruct6003.h"
#include "ar6004_eeprom.h"
#include "eepromUtil_ar6004.h"

// defines

// globals & static

// function definitions
#if !defined(_USE_AS_API)
int MaxTempEntries = MAX_TEMPLATE_ENTRIES;
EEPROM_TEMP EepTempEntries[MAX_TEMPLATE_ENTRIES];
int EepTempEntryPos[MAX_TEMPLATE_ENTRIES];
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
    if (EepTempEntries[entry].hex == EEP_HEX_VAL || strstr(pLine,"0x")) {\
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
    if (EepTempEntries[entry].hex == EEP_HEX_VAL || strstr(pLine,"0x")) {
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

A_BOOL parse_txt_bitfield(char *pLine, A_UINT8 *pData, int entry, int *pos, int col)
{
    char *token;
    A_UINT32 readVal;
    static A_UINT8 bitpos=0;
    static A_UINT32 writeVal=0;
    A_UINT8 size; 
    EEP_TYPE_BIT_FIELD *bitField=(EEP_TYPE_BIT_FIELD*)EepTempEntries[entry].extra;

    token = strchr(pLine,':');
    token++;/* value is the one after ':') */

    if (EepTempEntries[entry].hex == EEP_HEX_VAL || strstr(pLine,"0x")) {
        if(!sscanf(token, "%x", &readVal)) {
        _printf("Error: unable to read value column %d at entry %d from %s\n", col, entry);
        }
        _printf("0x%x ", readVal);
    }
    else if (EepTempEntries[entry].hex == EEP_DEC_VAL) {
    if(!sscanf(token, "%d", &readVal)) {
        _printf("Error: unable to read value column %d at entry %d from %s\n", col, entry);
        }
        _printf("%d ", readVal);
    }


    size = bitField->numBits[col];
    writeVal |= (readVal << bitpos);
    bitpos += size;

    if (col == (EepTempEntries[entry].num-1)) { /* last column */
        size = (bitpos + 7)/8;
        if (size > sizeof(A_UINT32)) {
            size = sizeof(A_UINT32);
#ifndef WIN32
            printf("%s Template entry %s has error bit field, bitpos %d exceeded 32\n", __func__,EepTempEntries[entry].key,bitpos);
#else
			printf("%s Template entry %s has error bit field, bitpos %d exceeded 32\n", __FUNCTION__,EepTempEntries[entry].key,bitpos);
#endif
        }
        memcpy((void*)&pData[*pos], (void*)&writeVal, (size_t)size);
        (*pos) += size;
        bitpos = 0;
        writeVal = 0;
    }

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
    parse_txt_bitfield,
};

static char lineBuf[MAX_LINE_BUF+2];
A_BOOL parseEepromTxtFile(char *fileName, A_UINT8 *pData)
{
    FILE *fp;
    //char lineBuf[MAX_LINE_BUF+2], *pLine;
    char *pLine;
    char key[MAX_KEY_LEN];
    char delimiters[] = " \t\n\r;=/#" ;
    int i, j, pos=0;
    int tempEntry;

    _printf("\n..Reading in eeprom txt file %s\n", fileName);
    if( (fp = fopen( fileName, "r")) == NULL ) {
        _printf("Failed to open %s - using Defaults\n", fileName);
        return;
    }

    for (i=0;i<MAX_TEMPLATE_ENTRIES;i++) {
        if (fgets(lineBuf, MAX_LINE_BUF, fp) == NULL) {
            _printf("End of text file %s at line %d\n", fileName, i);
            break;
        }

    	pLine = lineBuf;
        key[0] = 0;
    	if (!sscanf(pLine, "%s", key)) {
    	    _printf("Error reading %s from %s\n", lineBuf, fileName);
            continue; // or break?
    	}

        if (strstr(key,"#"))
            continue;
        if (strstr(key,"/*"))
            continue;

        for (j=0;j<MaxTempEntries;j++) {/* search the whole template entry to see if this key exists */
	        if (strncmp(key, EepTempEntries[j].key, sizeof(EepTempEntries[j].key)) == 0) {
                tempEntry = j;
                pos = EepTempEntryPos[tempEntry];
                break;/* entry found */
    	    } 
        }
        if (j>=MaxTempEntries)
        {
            printf("Error: data entry %s at line %d does not exit in template\n", key,i+1);
            continue;
        }

        _printf("%s ", key);
        printf ("TRANG - [%d] %s\n", pos, key);
        
    	for (j=0;j<EepTempEntries[tempEntry].num;j++) {
    	    pLine = strchr(pLine, ' ');
    	    pLine = strtok(pLine, delimiters);
            EepParserTxtFunc[EepTempEntries[tempEntry].type](pLine, pData, tempEntry, &pos, j);
    	}
        if (pos > sizeof(AR6000_EEPROM))
        {
            printf ("Error - overflow the EEPROM size\n");
            return FALSE;
        }
        _printf("\n");

    } //end of file					

    if (fp) fclose(fp);

    return(TRUE);

}

#if 0
static A_BOOL readTemplate(char *fileName)
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

    return TRUE;
}

static A_UINT16 computeChecksumOnly(A_UINT16 *pHalf, A_UINT16 length)
{
    A_UINT16 sum = 0, i;
    for (i = 0; i < length; i++) { sum ^= *pHalf++; }
    return(sum);
}

// There are two checksums now, one for the old 1024B, the other for the expanded section
// This function encapsulates both calculation, while maintaining the existing protocol
static void computeChecksum(A_UINT8 *pEepStruct, A_UINT32 chkSumOffset, A_UINT16 sizeInBytes)
{
    A_UINT16 sum, *pHalf, i;
    
    *(pEepStruct + chkSumOffset) = 0x0000;
    pHalf = (A_UINT16 *)pEepStruct;
    sum = computeChecksumOnly(pHalf, sizeInBytes/2);
    *(pEepStruct + chkSumOffset) = 0xFFFF ^ sum;

}
#endif

static void prtSizes(void)
{
    AR6000_EEPROM brdData;
    printf("total                   %d\n", sizeof(brdData));

    printf("base                    %d\n", sizeof(brdData.baseEepHeader));

    printf("header                  %d\n", sizeof(brdData.commonEepHeader));
    printf("calDataPerChip          %d\n", sizeof(brdData.chipCalData));

    printf("modal2G                 %d\n", sizeof(brdData.modalHeader2G));

    printf("calFreq2G               %d\n", sizeof(brdData.calFreqPier2G));
    printf("calData2G               %d\n", sizeof(brdData.calPierData2G));

    printf("calTgtFreqCCK           %d\n", sizeof(brdData.calTargetFreqbinCck));
    printf("pad1                    %d\n", sizeof(brdData.pad1));
    printf("calTgtFreq2G            %d\n", sizeof(brdData.calTargetFreqbin2G));
    printf("pad2                    %d\n", sizeof(brdData.pad2));
    printf("calTgtFreq2GHT20        %d\n", sizeof(brdData.calTargetFreqbin2GHT20));
    printf("pad3                    %d\n", sizeof(brdData.pad3));
    printf("calTgtFreq2GHT40        %d\n", sizeof(brdData.calTargetFreqbin2GHT40));
    printf("pad4                    %d\n", sizeof(brdData.pad4));
    printf("calTgtPwrCCK            %d\n", sizeof(brdData.calTargetPowerCck));
    printf("calTgtPwr2G             %d\n", sizeof(brdData.calTargetPower2G));
    printf("calTgtPwr2GHT20         %d\n", sizeof(brdData.calTargetPower2GHT20));
    printf("pad5                    %d\n", sizeof(brdData.pad5));
    printf("calTgtPwr2GHT40         %d\n", sizeof(brdData.calTargetPower2GHT40));
    printf("pad6                    %d\n", sizeof(brdData.pad6));

    printf("ctIndex2G               %d\n", sizeof(brdData.ctlIndex2G));
    printf("ctlFreq2G               %d\n", sizeof(brdData.ctlFreqbin2G));
    printf("ctlData2G               %d\n", sizeof(brdData.ctlData2G));

    printf("txGainTbl2GHT20         %d\n", sizeof(brdData.txGainTbl_2GLEG_HT20));
    printf("tierTbl2GHT20           %d\n", sizeof(brdData.tierTbl_2G_HT20));

    printf("tempComp_2G             %d\n", sizeof(brdData.tempComp_2G));

    printf("ateGGCalData2G          %d\n", sizeof(brdData.ateGGCALData2G));
    printf("sysGGCalData2G          %d\n", sizeof(brdData.sysGGCALData2G));
    printf("feDeltaCalData2G        %d\n", sizeof(brdData.feDeltaCalData2G));

    printf("newFeatures2G           %d\n", sizeof(brdData.newFeaturesData_2G));

    printf("modal5G                 %d\n", sizeof(brdData.modalHeader5G));

    printf("calFreq5G               %d\n", sizeof(brdData.calFreqPier5G));
    printf("calData5G               %d\n", sizeof(brdData.calPierData5G));

    printf("calTgtFreq5G            %d\n", sizeof(brdData.calTargetFreqbin5G));
    printf("calTgtFreq5GHT20        %d\n", sizeof(brdData.calTargetFreqbin5GHT20));
    printf("calTgtFreq5GHT40        %d\n", sizeof(brdData.calTargetFreqbin5GHT40));
    printf("calTgtPwr5G             %d\n", sizeof(brdData.calTargetPower5G));
    printf("calTgtPwr5GHT20         %d\n", sizeof(brdData.calTargetPower5GHT20));
    printf("calTgtPwr5GHT40         %d\n", sizeof(brdData.calTargetPower5GHT40));

    printf("ctlIndex5G              %d\n", sizeof(brdData.ctlIndex5G));
    printf("ctlData5GFuture         %d\n", sizeof(brdData.ctl5GFuture));
    printf("ctlFreq5G               %d\n", sizeof(brdData.ctlFreqbin5G));
    printf("ctlData5G               %d\n", sizeof(brdData.ctlData5G));

    printf("txGainTbl5GHT20         %d\n", sizeof(brdData.txGainTbl_5GLEG_HT20));
    printf("tierTbl_5G_HT20         %d\n", sizeof(brdData.tierTbl_5G_HT20));

    printf("tempComp5G              %d\n", sizeof(brdData.tempComp_5G));
    printf("tempComp5G_1            %d\n", sizeof(brdData.tempComp_5G_1));

    printf("ateGGCalData5G          %d\n", sizeof(brdData.ateGGCALData5G));
    printf("sysGGCalData5G          %d\n", sizeof(brdData.sysGGCALData5G));
    printf("feDeltaCalData5G        %d\n", sizeof(brdData.feDeltaCalData_5g));

    printf("newFeature5G            %d\n", sizeof(brdData.newFeaturesData_5G));

    printf("configAddr              %d\n", sizeof(brdData.configAddr));
    printf("GPIOConfigModeNormal    %d\n", sizeof(brdData.GPIOConfigModeNormal));
    printf("GPIOConfigModeNormal    %d\n", sizeof(brdData.GPIOConfigModeMit));
    printf("GPIOConfigModeNormal    %d\n", sizeof(brdData.GPIOConfigModeVap));
    printf("padFuture               %d\n", sizeof(brdData.padFuture));

    return;
}

#if 0
#define CHECKSUM_OFFSET 4
A_BOOL genEepromBinFile(char *fileName, A_UINT8 *pEepStruct) 
{
    A_UINT8 *pData = (A_UINT8 *)pEepStruct;
    FILE *fp;
    A_UINT16 eepromSize = sizeof(AR6000_EEPROM);
    
    prtSizes();

    // re-computing checksum
    computeChecksum(pEepStruct, (A_UINT32)CHECKSUM_OFFSET, eepromSize );

    if ( (fp = fopen(fileName, "wb")) == NULL) {
        _printf("Error: open to write eeprom bin %s \n", fileName);
        return FALSE;
    }
    if (eepromSize != fwrite((A_UCHAR *)pEepStruct, 1, eepromSize, fp)) {
        _printf("Error: writing to %s\n", fileName);
    }
    if (fp) fclose(fp);
    return(TRUE);
}
#endif

static AR6000_EEPROM EepromData;
#if defined(_USE_AS_API)
int _eepromTxt2Bin(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    FILE *fp;
    int i, j;
    A_UINT8 *pData = (A_UINT8 *)&EepromData;
    AR6000_EEPROM *pEepStruct = (AR6000_EEPROM*)&EepromData;

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
    if (FALSE == parseEepromTxtFile(argv[2], (A_UINT8 *)&EepromData)) {
        printf("Error reading EEPROM text file %s \n", argv[2]);
        return -1;
    }

    //for (i = 0; i < 10; ++i)
    //{
    //    printf("%04%x: ", i * 16);
    //    for (j = 0; j < 16; ++j)
    //    {
    //        printf("%02x ", pData[i*16+j]);
    //    }
    //    printf("\n");
    //}
    // generate binary file
    //if (FALSE == genEepromBinFile(argv[3], EepromData)) {
    if (FALSE == genEepromBinFile(argv[3], pEepStruct )) {
        printf("Error creating EEPROM bin file %s \n", argv[3]);
        return -1;
    }
    else {
        printf(".created EEPROM bin file %s \n", argv[3]);
    }

    return 0;
}

