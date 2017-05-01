/*! \file ah_wmi.c
**  \brief Linux support for WMI function in HAL
**    
**  Copyright (c) 2002-2004 Sam Leffler, Errno Consulting.
**  Copyright (c) 2005-2007 Atheros Communications Inc.
**
**  All rights reserved.
**
** Redistribution and use in source and binary forms are permitted
** provided that the following conditions are met:
** 1. The materials contained herein are unmodified and are used
**    unmodified.
** 2. Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following NO
**    ''WARRANTY'' disclaimer below (''Disclaimer''), without
**    modification.
** 3. Redistributions in binary form must reproduce at minimum a
**    disclaimer similar to the Disclaimer below and any redistribution
**    must be conditioned upon including a substantially similar
**    Disclaimer requirement for further binary redistribution.
** 4. Neither the names of the above-listed copyright holders nor the
**    names of any contributors may be used to endorse or promote
**    product derived from this software without specific prior written
**    permission.
**
** NO WARRANTY
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT,
** MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE
** FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
** USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
** ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
** OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
** OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
** SUCH DAMAGES.
**
*/
#ifndef ATH_WINHTC

#include "opt_ah.h"

#ifndef EXPORT_SYMTAB
#define EXPORT_SYMTAB
#endif

#endif

typedef void*                     adf_os_handle_t;
typedef void*                     HTC_HANDLE;

/*
** HTC Includes
*/
#include "a_osapi.h"
#include "a_types.h"
#include "athdefs.h"
#include "htc.h"
#include "htc_host_api.h"
#include "wmi.h"
#include "wmi_host_api.h"

/*
** HAL Includes
*/

#include "ah.h"
#include "ah_internal.h"

/* printf interfaces */
extern  void __ahdecl ath_hal_printf(struct ath_hal *, const char*, ...)
        __printflike(2,3);

struct registerWrite {
    u_int32_t reg;
    u_int32_t val;
} /*data*/;

void
ath_hal_wmi_reg_write_delay(struct ath_hal *ah, u_int reg, u_int32_t val)
{
    wmi_reg_write_delay(AH_PRIVATE(ah)->hal_wmi_handle, reg, val);
}

void
ath_hal_wmi_reg_write_flush(struct ath_hal *ah)
{
    wmi_reg_write_flush(AH_PRIVATE(ah)->hal_wmi_handle);
}

void
ath_hal_wmi_reg_write(struct ath_hal *ah, u_int reg, u_int32_t val)
{
    u_int32_t cmd_status = -1;
    struct registerWrite data;

    //data.reg = htonl(reg);
    //data.val = htonl(val);
    data.reg = cpu_to_be32(reg);
    data.val = cpu_to_be32(val);

    cmd_status = wmi_cmd(AH_PRIVATE(ah)->hal_wmi_handle, 
        WMI_REG_WRITE_CMDID, 
        (u_int8_t *) &data, 
        sizeof(struct registerWrite), 
        (u_int8_t *) &val,
        sizeof(val),
        100 /* timeout unit? */);

    if(cmd_status){
        ath_hal_printf(NULL, "Host : WMI COMMAND WRITE FAILURE stat = %x\n", cmd_status);
        return;
    }
}

u_int32_t
ath_hal_wmi_reg_read(struct ath_hal *ah, u_int reg)
{
    u_int32_t val;
    u_int32_t cmd_status = -1;
    //u_int32_t tmp = htonl(reg);
    u_int32_t tmp = cpu_to_be32(reg);

    cmd_status = wmi_cmd(AH_PRIVATE(ah)->hal_wmi_handle, 
        WMI_REG_READ_CMDID, 
        (u_int8_t *) &tmp, 
        sizeof(tmp),
        (u_int8_t *) &val,
        sizeof(val),
        100 /* timeout unit? */);

    if(cmd_status == A_ERROR) {
        ath_hal_printf(NULL, "Host : WMI COMMAND READ FAILURE stat = %x\n", cmd_status);
        return EIO; /*TODO: return value is for read reg value result, not for read reg status result, need enhence later*/
    }

    //return ntohl(val);
    return be32_to_cpu(val);
}

void
ath_hal_wmi_ps_set_state(struct ath_hal *ah, u_int16_t mode)
{
    u_int32_t val;
    u_int32_t cmd_status = -1;

    mode = cpu_to_be16(mode);
        
    cmd_status = wmi_cmd(AH_PRIVATE(ah)->hal_wmi_handle, 
        WMI_PS_SET_STATE_CMD, 
        (u_int8_t *)&mode, 
        sizeof(u_int16_t),
        (u_int8_t *) &val,
        sizeof(val),
        100 /* timeout unit? */);

    if (cmd_status) {
        if (cmd_status != -1) {
            ath_hal_printf(NULL, "Host : WMI COMMAND SET PS STATE FAILURE stat = %x\n", cmd_status);
        }
    }
    return;
}

