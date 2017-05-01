//-----------------------------------------------------------------------------

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "wlantype.h"
#include "qc98xx_eeprom.h"
#include "eepromUtil_1.h"

static QC98XX_EEPROM EepromData;
#if defined(_USE_AS_API)
int _eepromBin2Txt(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    A_UINT8 *pData;

    if ((NULL != argv[1]) && (NULL != argv[2]) && (NULL != argv[3])) {
    }
    else {
        printf("Usage: eepromBin2Txt.out <eeprom template> <input eeprom.bin> <output eeprom.txt> <templateHeaderFile.h>\n");
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
    if (FALSE == readCalDataFromFileBin(argv[2], (A_UINT8 *)&EepromData, sizeof(QC98XX_EEPROM))) {
        printf("Error reading EEPROM bin file %s \n", argv[2]);
        return -1;
    }
    else {
        _printf(".reading EEPROM bin file %s \n", argv[2]);
    }

    // parse bin file based on template
    pData = (A_UINT8 *)&EepromData;
    if (FALSE == parseBin(pData, sizeof(QC98XX_EEPROM), argv[3])) {
        printf("Error parsing EEPROM bin file %s \n", argv[2]);
        return -1;
    }
    else {
        _printf(".parsed EEPROM bin file %s into text file %s\n", argv[2], argv[3]);
    }

	if (argc == 5)
	{
		// generate template header file
		if (genEepromTemplateHFile (argv[4], pData, sizeof(QC98XX_EEPROM), &(EepromData.baseEepHeader.checksum)) == FALSE)
		{
			printf("Error creating template header file %s \n", argv[4]);
			return -1;
		}
		else	
		{
			printf(".created template header file %s \n", argv[4]);
		}
	}
    return 0;
}

