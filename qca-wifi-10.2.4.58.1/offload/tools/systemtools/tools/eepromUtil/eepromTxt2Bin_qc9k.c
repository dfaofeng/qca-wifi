//-----------------------------------------------------------------------------

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "wlantype.h"
#include "qc98xx_eeprom.h"
#include "eepromUtil_1.h"

// defines

// globals & static

static QC98XX_EEPROM EepromData;
#if defined(_USE_AS_API)
int _eepromTxt2Bin(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    A_UINT8 *pData = (A_UINT8 *)&EepromData;
    QC98XX_EEPROM *pEepStruct = (QC98XX_EEPROM*)&EepromData;

    if ((NULL != argv[1]) && (NULL != argv[2]) && (NULL != argv[3])) {
    }
    else {
        printf("Usage: eepromBin2Txt.out <eeprom template> <input eeprom text> <output eeprom bin> <templateHeaderFile.h>\n");
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
    if (FALSE == parseEepromTxtFile(argv[2], (A_UINT8 *)&EepromData, sizeof(QC98XX_EEPROM))) {
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
	if (FALSE == genEepromBinFile(argv[3], pData, sizeof(QC98XX_EEPROM), &(pEepStruct->baseEepHeader.checksum) )) {
        printf("Error creating EEPROM bin file %s \n", argv[3]);
        return -1;
    }
    else {
        printf(".created EEPROM bin file %s \n", argv[3]);
    }

	if (argc == 5)
	{
		// generate template header file
		if (genEepromTemplateHFile (argv[4], pData, sizeof(QC98XX_EEPROM), &(pEepStruct->baseEepHeader.checksum)) == FALSE)
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

