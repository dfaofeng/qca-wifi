//                                                                             
// File:       ./pcie_local_reg.h                                              
// Creator:    cedar                                                           
// Time:       Monday Apr 9, 2012 [10:00:29 am]                                
//                                                                             
// Path:       /trees/mbu-cn1/cedar/xlu_rome/chips/rome/dev/rtl/wlan/pcie_wrap/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -ch -Wdesc -I                 
//             /trees/mbu-cn1/cedar/xlu_rome/chips/rome/dev/blueprint/sysconfig
//             pcie_local_reg.rdl                                              
//                                                                             
// Sources:    /trees/mbu-cn1/cedar/xlu_rome/chips/rome/dev/rtl/wlan/pcie_wrap/blueprint/pcie_local_reg.rdl
//             /trees/mbu-cn1/cedar/xlu_rome/chips/rome/dev/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    qing                                                            
// OS:         Linux 2.6.9-89.ELsmp                                            
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _PCIE_LOCAL_REG_H_
#define _PCIE_LOCAL_REG_H_
// 32'h0000 (RTC_STATE)
#define RTC_STATE_COLD_RESET_MSB                                     13
#define RTC_STATE_COLD_RESET_LSB                                     13
#define RTC_STATE_COLD_RESET_MASK                                    0x00002000
#define RTC_STATE_COLD_RESET_GET(x)                                  (((x) & RTC_STATE_COLD_RESET_MASK) >> RTC_STATE_COLD_RESET_LSB)
#define RTC_STATE_COLD_RESET_SET(x)                                  (((x) << RTC_STATE_COLD_RESET_LSB) & RTC_STATE_COLD_RESET_MASK)
#define RTC_STATE_COLD_RESET_RESET                                   0x0 // 0
#define RTC_STATE_XTAL_COUNT_MSB                                     12
#define RTC_STATE_XTAL_COUNT_LSB                                     3
#define RTC_STATE_XTAL_COUNT_MASK                                    0x00001ff8
#define RTC_STATE_XTAL_COUNT_GET(x)                                  (((x) & RTC_STATE_XTAL_COUNT_MASK) >> RTC_STATE_XTAL_COUNT_LSB)
#define RTC_STATE_XTAL_COUNT_SET(x)                                  (((x) << RTC_STATE_XTAL_COUNT_LSB) & RTC_STATE_XTAL_COUNT_MASK)
#define RTC_STATE_XTAL_COUNT_RESET                                   0x0 // 0
#define RTC_STATE_V_MSB                                              2
#define RTC_STATE_V_LSB                                              0
#define RTC_STATE_V_MASK                                             0x00000007
#define RTC_STATE_V_GET(x)                                           (((x) & RTC_STATE_V_MASK) >> RTC_STATE_V_LSB)
#define RTC_STATE_V_SET(x)                                           (((x) << RTC_STATE_V_LSB) & RTC_STATE_V_MASK)
#define RTC_STATE_V_RESET                                            0x0 // 0
#define RTC_STATE_ADDRESS                                            0x0000
#define RTC_STATE_OFFSET                                             0x0000
// SW modifiable bits
#define RTC_STATE_SW_MASK                                            0x00003fff
// bits defined at reset
#define RTC_STATE_RSTMASK                                            0xffffffff
// reset value (ignore bits undefined at reset)
#define RTC_STATE_RESET                                              0x00000000

// 32'h0004 (PCIE_SOC_WAKE)
#define PCIE_SOC_WAKE_V_MSB                                          0
#define PCIE_SOC_WAKE_V_LSB                                          0
#define PCIE_SOC_WAKE_V_MASK                                         0x00000001
#define PCIE_SOC_WAKE_V_GET(x)                                       (((x) & PCIE_SOC_WAKE_V_MASK) >> PCIE_SOC_WAKE_V_LSB)
#define PCIE_SOC_WAKE_V_SET(x)                                       (((x) << PCIE_SOC_WAKE_V_LSB) & PCIE_SOC_WAKE_V_MASK)
#define PCIE_SOC_WAKE_V_RESET                                        0x0 // 0
#define PCIE_SOC_WAKE_ADDRESS                                        0x0004
#define PCIE_SOC_WAKE_OFFSET                                         0x0004
// SW modifiable bits
#define PCIE_SOC_WAKE_SW_MASK                                        0x00000001
// bits defined at reset
#define PCIE_SOC_WAKE_RSTMASK                                        0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_SOC_WAKE_RESET                                          0x00000000

// 32'h0008 (SOC_GLOBAL_RESET)
#define SOC_GLOBAL_RESET_V_MSB                                       0
#define SOC_GLOBAL_RESET_V_LSB                                       0
#define SOC_GLOBAL_RESET_V_MASK                                      0x00000001
#define SOC_GLOBAL_RESET_V_GET(x)                                    (((x) & SOC_GLOBAL_RESET_V_MASK) >> SOC_GLOBAL_RESET_V_LSB)
#define SOC_GLOBAL_RESET_V_SET(x)                                    (((x) << SOC_GLOBAL_RESET_V_LSB) & SOC_GLOBAL_RESET_V_MASK)
#define SOC_GLOBAL_RESET_V_RESET                                     0x0 // 0
#define SOC_GLOBAL_RESET_ADDRESS                                     0x0008
#define SOC_GLOBAL_RESET_OFFSET                                      0x0008
// SW modifiable bits
#define SOC_GLOBAL_RESET_SW_MASK                                     0x00000001
// bits defined at reset
#define SOC_GLOBAL_RESET_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define SOC_GLOBAL_RESET_RESET                                       0x00000000


#endif /* _PCIE_LOCAL_REG_H_ */
