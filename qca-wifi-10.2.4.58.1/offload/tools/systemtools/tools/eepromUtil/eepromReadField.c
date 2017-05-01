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

// e.g. eepromReadFile mac <eepromBin> (<eepromTemplate>)
int main(int argc, char *argv[])
{
    char cmd[MAX_LINE_BUF];
    char myArgvArr[][MAX_KEY_LEN] = {"dummy", "eeprom_6_3.tmp", "eeprom.bin", "_tmpIn.dat"};
    char *myArgv[4];
    int i;

    myArgv[0] = (char *)&myArgvArr[0];
    myArgv[1] = (char *)&myArgvArr[1];
    myArgv[2] = (char *)&myArgvArr[2];
    myArgv[3] = (char *)&myArgvArr[3];

    if ((NULL != argv[1]) && (NULL != argv[2]) ) {
        strcpy(myArgv[2], argv[2]);
    }
    else {
        printf("Usage: eepromReadField.out <key> <eeprom.bin> (<eeprom template>)\n");
        supportedFields();
        return -1;
    }
    if ((NULL != argv[3])) {
        strcpy(myArgv[1], argv[3]); 
    }

    for (i=0;i<NumOfAllowedKeys;i++) {
        if (0 == strcmp(AllowedKeys[i], argv[1]))
            break;
    }
    if (i == NumOfAllowedKeys)
        return(-1);

    _printf("%s %s %s\n", myArgv[1], myArgv[2], myArgv[3]);
    _eepromBin2Txt(4, myArgv);

    sprintf(cmd, "perl pickField.pl %s", argv[1]);
    _printf("%s\n", cmd);
    system(cmd);

    remove("./_tmpIn.dat");

    return 0;
}

