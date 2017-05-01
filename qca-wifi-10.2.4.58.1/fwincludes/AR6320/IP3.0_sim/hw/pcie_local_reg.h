//                                                                             
// File:       ./pcie_local_reg.vrh                                            
// Creator:    lqiang                                                          
// Time:       Tuesday Nov 1, 2011 [11:04:09 pm]                               
//                                                                             
// Path:       /trees/mbu-cn1/lqiang/lqiang_hera_dv/chips/hera/dev/doc/headers/bp_wlan
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/mbu-cn1/lqiang/lqiang_hera_dv/chips/hera/dev/blueprint/sysconfig
//             pcie_local_reg.rdl                                              
//                                                                             
// Sources:    /trees/mbu-cn1/lqiang/lqiang_hera_dv/chips/hera/dev/rtl/wlan/pcie_wrap/blueprint/pcie_local_reg.rdl
//             /trees/mbu-cn1/lqiang/lqiang_hera_dv/chips/hera/dev/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    shang                                                           
// OS:         Linux 2.6.9-67.ELsmp                                            
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _PCIE_LOCAL_REG_H_
#define _PCIE_LOCAL_REG_H_
// 0x0000 (RTC_STATE)
#define RTC_STATE_COLD_RESET_MSB                                     10
#define RTC_STATE_COLD_RESET_LSB                                     10
#define RTC_STATE_COLD_RESET_MASK                                    0x00000400
#define RTC_STATE_COLD_RESET_GET(x)                                  (((x) & RTC_STATE_COLD_RESET_MASK) >> RTC_STATE_COLD_RESET_LSB)
#define RTC_STATE_COLD_RESET_SET(x)                                  (((0 | (x)) << RTC_STATE_COLD_RESET_LSB) & RTC_STATE_COLD_RESET_MASK)
#define RTC_STATE_COLD_RESET_RESET                                   0
#define RTC_STATE_XTAL_COUNT_MSB                                     9
#define RTC_STATE_XTAL_COUNT_LSB                                     3
#define RTC_STATE_XTAL_COUNT_MASK                                    0x000003f8
#define RTC_STATE_XTAL_COUNT_GET(x)                                  (((x) & RTC_STATE_XTAL_COUNT_MASK) >> RTC_STATE_XTAL_COUNT_LSB)
#define RTC_STATE_XTAL_COUNT_SET(x)                                  (((0 | (x)) << RTC_STATE_XTAL_COUNT_LSB) & RTC_STATE_XTAL_COUNT_MASK)
#define RTC_STATE_XTAL_COUNT_RESET                                   0
#define RTC_STATE_V_MSB                                              2
#define RTC_STATE_V_LSB                                              0
#define RTC_STATE_V_MASK                                             0x00000007
#define RTC_STATE_V_GET(x)                                           (((x) & RTC_STATE_V_MASK) >> RTC_STATE_V_LSB)
#define RTC_STATE_V_SET(x)                                           (((0 | (x)) << RTC_STATE_V_LSB) & RTC_STATE_V_MASK)
#define RTC_STATE_V_RESET                                            0
#define RTC_STATE_ADDRESS                                            0x0000
#define RTC_STATE_HW_MASK                                            0x000007ff
#define RTC_STATE_SW_MASK                                            0x000007ff
#define RTC_STATE_HW_WRITE_MASK                                      0x000007ff
#define RTC_STATE_SW_WRITE_MASK                                      0x00000000
#define RTC_STATE_RSTMASK                                            0xffffffff
#define RTC_STATE_RESET                                              0x00000000

// 0x0004 (PCIE_SOC_WAKE)
#define PCIE_SOC_WAKE_V_MSB                                          0
#define PCIE_SOC_WAKE_V_LSB                                          0
#define PCIE_SOC_WAKE_V_MASK                                         0x00000001
#define PCIE_SOC_WAKE_V_GET(x)                                       (((x) & PCIE_SOC_WAKE_V_MASK) >> PCIE_SOC_WAKE_V_LSB)
#define PCIE_SOC_WAKE_V_SET(x)                                       (((0 | (x)) << PCIE_SOC_WAKE_V_LSB) & PCIE_SOC_WAKE_V_MASK)
#define PCIE_SOC_WAKE_V_RESET                                        0
#define PCIE_SOC_WAKE_ADDRESS                                        0x0004
#define PCIE_SOC_WAKE_HW_MASK                                        0x00000001
#define PCIE_SOC_WAKE_SW_MASK                                        0x00000001
#define PCIE_SOC_WAKE_HW_WRITE_MASK                                  0x00000000
#define PCIE_SOC_WAKE_SW_WRITE_MASK                                  0x00000001
#define PCIE_SOC_WAKE_RSTMASK                                        0xffffffff
#define PCIE_SOC_WAKE_RESET                                          0x00000000

// 0x0008 (SOC_GLOBAL_RESET)
#define SOC_GLOBAL_RESET_V_MSB                                       0
#define SOC_GLOBAL_RESET_V_LSB                                       0
#define SOC_GLOBAL_RESET_V_MASK                                      0x00000001
#define SOC_GLOBAL_RESET_V_GET(x)                                    (((x) & SOC_GLOBAL_RESET_V_MASK) >> SOC_GLOBAL_RESET_V_LSB)
#define SOC_GLOBAL_RESET_V_SET(x)                                    (((0 | (x)) << SOC_GLOBAL_RESET_V_LSB) & SOC_GLOBAL_RESET_V_MASK)
#define SOC_GLOBAL_RESET_V_RESET                                     0
#define SOC_GLOBAL_RESET_ADDRESS                                     0x0008
#define SOC_GLOBAL_RESET_HW_MASK                                     0x00000001
#define SOC_GLOBAL_RESET_SW_MASK                                     0x00000001
#define SOC_GLOBAL_RESET_HW_WRITE_MASK                               0x00000000
#define SOC_GLOBAL_RESET_SW_WRITE_MASK                               0x00000001
#define SOC_GLOBAL_RESET_RSTMASK                                     0xffffffff
#define SOC_GLOBAL_RESET_RESET                                       0x00000000


#endif /* _PCIE_LOCAL_REG_H_ */
