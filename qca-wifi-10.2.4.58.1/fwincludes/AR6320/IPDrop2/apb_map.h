// ------------------------------------------------------------------
// Copyright (c) 2004-2007 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
// ------------------------------------------------------------------
//===================================================================
// Author(s): ="Atheros"
//===================================================================


#ifdef WLAN_HEADERS

#include "apb_athr_wlan_map.h"

#define WLAN_ANALOG_INTF_PCIE_BASE_ADDRESS PCIE_PHY_BASE_ADDRESS

#ifndef BT_HEADERS

#define DBG_UART_BASE_ADDRESS WLAN_DBG_UART_BASE_ADDRESS
#define SI_BASE_ADDRESS WLAN_SI_BASE_ADDRESS
#define GPIO_BASE_ADDRESS WLAN_GPIO_BASE_ADDRESS
#define ANALOG_INTF_BASE_ADDRESS WLAN_ANALOG_INTF_BASE_ADDRESS
#define MBOX_BASE_ADDRESS WLAN_MBOX_BASE_ADDRESS
#define RDMA_BASE_ADDRESS WLAN_RDMA_BASE_ADDRESS
#define MAC_BASE_ADDRESS WLAN_MAC_BASE_ADDRESS
#define PCIE_BASE_ADDRESS SOC_PCIE_BASE_ADDRESS
#define CORE_BASE_ADDRESS SOC_CORE_BASE_ADDRESS
#define CXM_BASE_ADDRESS WLAN_CXM_BASE_ADDRESS


#endif
#endif



