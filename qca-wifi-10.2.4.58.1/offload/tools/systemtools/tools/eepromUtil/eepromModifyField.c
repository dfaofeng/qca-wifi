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

// function definitions

A_BOOL parse_field_oneValue(char *value, int entry, char *retLn, int pos)
{
    sprintf(retLn+pos, "%s", value);
    return(TRUE);
}

A_BOOL parse_field_uint16(char *value, int entry, char *retLn, int pos)
{
    return(TRUE);
}

A_BOOL parse_field_uint32(char *value, int entry, char *retLn, int pos)
{
    sprintf(retLn+pos, "%s", value);
    return(TRUE);
}

A_BOOL parse_field_int8(char *value, int entry, char *retLn, int pos)
{
    return(TRUE);
}

A_BOOL parse_field_int16(char *value, int entry, char *retLn, int pos)
{
    sprintf(retLn+pos, "%s", value);
    return(TRUE);
}

A_BOOL parse_field_int32(char *value, int entry, char *retLn, int pos)
{
    sprintf(retLn+pos, "%s", value);
    return(TRUE);
}

A_BOOL parse_field_uint8(char *value, int entry, char *retLn, int pos)
{
    int i, j=0, jMax;
    char retLine[MAX_LINE_BUF];
    if (EepTempEntries[entry].hex == EEP_HEX_VAL) 
        jMax=4;
    else if (EepTempEntries[entry].hex == EEP_DEC_VAL) 
        jMax=2;

    for (i=0;i<EepTempEntries[entry].num;i++) {
        for (j=0;j<jMax;j++) {
	    *(retLn+pos+j) = value[j];
        }
	*(retLn+pos+jMax) = ' ';
	pos +=(jMax+1);
    }

    return(TRUE);
}

A_BOOL parse_field_char(char *value, int entry, char *retLn, int pos)
{
    int i, j=0;
    char retLine[MAX_LINE_BUF];
    if (EepTempEntries[entry].hex == EEP_HEX_VAL) {
        for (i=0;i<EepTempEntries[entry].num;i++) {
	    *(retLn+pos) = '0';
	    *(retLn+pos+1) = 'x';
	    *(retLn+pos+2) = value[j];
	    *(retLn+pos+3) = value[j+1];
	    *(retLn+pos+4) = ' ';
	    j +=2;
	    pos +=5;
        }
    }
    else if (EepTempEntries[entry].hex == EEP_DEC_VAL) {
        for (i=0;i<EepTempEntries[entry].num;i++) {
	    *(retLn+pos) = value[j];
	    *(retLn+pos+1) = value[j+1];
	    *(retLn+pos+2) = ' ';
	    j +=2;
	    pos +=3;
        }
    }

    return(TRUE);
}

typedef A_BOOL (*ParseFieldFunc)(char *value, int entry, char *retLn, int pos);
ParseFieldFunc EepFieldParserFunc[] = {
    parse_field_char, 
    parse_field_oneValue,
    parse_field_oneValue,
    parse_field_oneValue, 
    parse_field_oneValue, 
    parse_field_oneValue,
    parse_field_char, 
};

// e.g. eepromWriteFile mac 112233445566 <eepromBin> (<eepromTemplate>)
int main(int argc, char *argv[])
{
    char cmd[MAX_LINE_BUF];
    char newLn[MAX_LINE_BUF];
    char myArgvArrIn[][MAX_KEY_LEN] = {"dummy", "eeprom_6_3.tmp", "eeprom.bin", "_tmpIn.dat"};
    char myArgvArrOut[][MAX_KEY_LEN] = {"dummy", "eeprom_6_3.tmp", "_tmpOut.dat", "eeprom.bin"};
    char *myArgv[4];
    char key[MAX_KEY_LEN];
    int i;

    myArgv[0] = (char *)&myArgvArrIn[0];
    myArgv[1] = (char *)&myArgvArrIn[1];
    myArgv[2] = (char *)&myArgvArrIn[2];
    myArgv[3] = (char *)&myArgvArrIn[3];

    if ((NULL != argv[1]) && (NULL != argv[2]) && (NULL != argv[3])) {
        strcpy(myArgv[2], argv[3]);
    }
    else {
        printf("Usage: eepromModifyField.out <key> <value> <eeprom.bin> (<eeprom template>)\n");
        supportedFields();
        return -1;
    }
    if ((NULL != argv[4])) {
        strcpy(myArgv[1], argv[4]); 
    }

    for (i=0;i<NumOfAllowedKeys;i++) {
        if (0 == strcmp(AllowedKeys[i], argv[1])) {
            memset(key, '\0', sizeof(key));
            strcpy(key, argv[1]);
            break;
        }
    }
    if (i == NumOfAllowedKeys)
        return(-1);

    // parse the file
    _printf("%s %s %s\n", myArgv[1], myArgv[2], myArgv[3]);
    _eepromBin2Txt(4, myArgv);

    // compose the new line
    memset(newLn, '\0', sizeof(newLn));
    for (i=0;i<MaxTempEntries;i++) {
        if (strcmp(EepTempEntries[i].key, key)) {
            continue;
        }
        else {
            sprintf(newLn, "%s ", key);
            EepFieldParserFunc[EepTempEntries[i].type](argv[2], i, newLn, strlen(key)+1);
            break;
        }
    }

    // substitute 
    sprintf(cmd, "perl substField.pl %s \"%s\"", key, newLn);
    _printf("%s\n", cmd);
    system(cmd);

    // re-make the bin
    myArgv[0] = (char *)&myArgvArrOut[0];
    myArgv[1] = (char *)&myArgvArrOut[1];
    myArgv[2] = (char *)&myArgvArrOut[2];
    myArgv[3] = (char *)&myArgvArrOut[3];
    strcpy(myArgv[3], argv[3]);

    _printf("%s %s %s %s\n", myArgv[0], myArgv[1], myArgv[2], myArgv[3]);
    _eepromTxt2Bin(4, myArgv);
 
    remove("./_tmpIn.dat");
    remove("./_tmpOut.dat");
    return 0;
}

