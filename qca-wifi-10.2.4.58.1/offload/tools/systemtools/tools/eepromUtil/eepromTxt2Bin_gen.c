//-----------------------------------------------------------------------------

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "wlantype.h"
#include "eepromUtil_1.h"

// defines

// globals & static

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
EEPROMUTILDLLSPEC A_BOOL parseEepromTxtFile(char *fileName, A_UINT8 *pData, A_UINT16 length)
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
        return FALSE;
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
        if (pos > length)
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
static void prtSizes(void)
{
    QC98XX_EEPROM brdData;
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
#endif //0

