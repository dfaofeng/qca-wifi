//------------------------------------------------------------------------------
// Copyright (c) 2010 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

#ifndef __TLPM_H__
#define __TLPM_H__

/* idle timeout in 16-bit value as in HOST_INTEREST hi_hci_uart_pwr_mgmt_params */
#define TLPM_DEFAULT_IDLE_TIMEOUT_MS         1000
/* hex in LSB and MSB for HCI command */
#define TLPM_DEFAULT_IDLE_TIMEOUT_LSB        0xE8
#define TLPM_DEFAULT_IDLE_TIMEOUT_MSB        0x3

/* wakeup timeout in 8-bit value as in HOST_INTEREST hi_hci_uart_pwr_mgmt_params */
#define TLPM_DEFAULT_WAKEUP_TIMEOUT_MS       10

/* default UART FC polarity is low */
#define TLPM_DEFAULT_UART_FC_POLARITY        0

#endif
