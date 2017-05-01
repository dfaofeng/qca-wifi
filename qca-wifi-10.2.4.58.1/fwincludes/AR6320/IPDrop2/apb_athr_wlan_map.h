#ifndef _APB_ATHR_WLAN_MAP_H_
#define _APB_ATHR_WLAN_MAP_H_

#if defined(A_SIMOS) || defined(A_SIMOS_DEVHOST)

#define RTC_SOC_BASE_ADDRESS                     0x00004000
#define RTC_WMAC_BASE_ADDRESS                    0x00005000
#define MAC_COEX_BASE_ADDRESS                    0x00006000
#define BT_COEX_BASE_ADDRESS                     0x00007000
#define SOC_PCIE_BASE_ADDRESS                    0x00008000
#define SOC_CORE_BASE_ADDRESS                    0x00009000
#define WLAN_UART_BASE_ADDRESS                   0x0000c000
#define WLAN_SI_BASE_ADDRESS                     0x00010000
#define WLAN_GPIO_BASE_ADDRESS                   0x00014000
#define WLAN_ANALOG_INTF_BASE_ADDRESS            0x0001c000
#define WLAN_MAC_BASE_ADDRESS                    0x00020000
#define EFUSE_BASE_ADDRESS                       0x00030000
#define FPGA_REG_BASE_ADDRESS                    0x00039000
#define WLAN_UART2_BASE_ADDRESS                  0x00054c00
#define CE_WRAPPER_BASE_ADDRESS                  0x00057000
#define CE0_BASE_ADDRESS                         0x00057400
#define CE1_BASE_ADDRESS                         0x00057800
#define CE2_BASE_ADDRESS                         0x00057c00
#define CE3_BASE_ADDRESS                         0x00058000
#define CE4_BASE_ADDRESS                         0x00058400
#define CE5_BASE_ADDRESS                         0x00058800
#define CE6_BASE_ADDRESS                         0x00058c00
#define CE7_BASE_ADDRESS                         0x00059000
#define DBI_BASE_ADDRESS                         0x00060000
//#define WLAN_ANALOG_INTF_PCIE_BASE_ADDRESS       0x0006c000

#define WLAN_MBOX_BASE_ADDRESS                   0x00068000
#define WLAN_DBG_UART_BASE_ADDRESS               0x00069000

#else

#define RTC_SOC_BASE_ADDRESS                     0x00000000
#define RTC_WMAC_BASE_ADDRESS                    0x00001000
#define BT_COEX_BASE_ADDRESS                     0x00002000
#define WLAN_DBG_UART_BASE_ADDRESS               0x00003000
#define HCI_UART_BASE_ADDRESS                    0x00004000
#define WLAN_GPIO_BASE_ADDRESS                   0x00005000
#define WLAN_ANALOG_INTF_BASE_ADDRESS            0x00006000
#define PCIE_PHY_BASE_ADDRESS                    0x00007800
#define WLAN_MBOX_BASE_ADDRESS                   0x00008000
#define MAC_COEX_BASE_ADDRESS                    0x0000d000
#define WLAN_RDMA_BASE_ADDRESS                   0x0000f000
#define WLAN_MAC_BASE_ADDRESS                    0x00010000
#define EFUSE_BASE_ADDRESS                       0x00024000
#define RADIO_BASE_ADDRESS                       0x00028000
#define CE_WRAPPER_BASE_ADDRESS                  0x00034000
#define CE0_BASE_ADDRESS                         0x00034400
#define CE1_BASE_ADDRESS                         0x00034800
#define CE2_BASE_ADDRESS                         0x00034c00
#define CE3_BASE_ADDRESS                         0x00035000
#define CE4_BASE_ADDRESS                         0x00035400
#define CE5_BASE_ADDRESS                         0x00035800
#define CE6_BASE_ADDRESS                         0x00035c00
#define CE7_BASE_ADDRESS                         0x00036000
#define SOC_PCIE_BASE_ADDRESS                    0x00038000
#define SOC_CORE_BASE_ADDRESS                    0x0003a000
#define DBI_BASE_ADDRESS                         0x0003c000
#define WLAN_CXM_BASE_ADDRESS                    0x00040000


#endif

#endif /* _APB_ATHR_WLAN_MAP_REG_H_ */
