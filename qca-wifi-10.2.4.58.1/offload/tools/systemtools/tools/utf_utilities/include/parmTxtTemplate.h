#if !defined(_TEST_CMD_PARMS_TXT_TEMPLATE)
#define _TEST_CMD_PARMS_TXT_TEMPLATE

#include <string.h>
#include "otaHostCommon.h"
#include "wlantype.h"

typedef struct _testFlowTxtParmTemplate {
    char     parm[KEY_SIZE_MAX];
    unsigned long parmType;
    unsigned long offset;
    size_t   len;
} __ATTRIB_PACK _TESTFLOW_TXT_PARM_TEMPLATE;

#endif // #if !defined(_TEST_CMD_PARMS_TXT_TEMPLATE)

