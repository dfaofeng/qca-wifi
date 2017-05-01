// ------------------------------------------------------------------
// Copyright (c) 2004-2007 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
// ------------------------------------------------------------------
//===================================================================
// Author(s): ="Atheros"
//===================================================================


#ifdef WLAN_HEADERS

#if defined(ATH_TARGET)
/* nothing */
#else
/* This part is for host side compile using only. The tools depend on this
 * part will never be used
 */
#include "../../hw/soc_core_reg.h"

#include "../../hw/removed/si_WLAN_reg.h"


#ifndef SOC_CLOCK_CONTROL_SI0_CLK_MASK
#define SOC_CLOCK_CONTROL_SI0_CLK_MASK 0
#endif
#ifndef SOC_RESET_CONTROL_SI0_RST_MASK
#define SOC_RESET_CONTROL_SI0_RST_MASK 0
#endif
#ifndef WLAN_SI_BASE_ADDRESS
#define WLAN_SI_BASE_ADDRESS 0xfffffff0 
#endif

#endif

#endif

