//                                                                             
// File:       ./rtc_sync_reg.h                                                
// Creator:    saida                                                           
// Time:       Thursday Apr 19, 2012 [11:48:35 am]                             
//                                                                             
// Path:       /trees/saida/saida-dev3/ip/athr/wifi/dev/rtl/rtc_wmac/blueprint 
// Arguments:  /cad/denali/blueprint/3.7.3//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -ch -Wdesc rtc_sync_reg.rdl   
//                                                                             
// Sources:    /trees/saida/saida-dev3/ip/athr/wifi/dev/rtl/rtc_wmac/blueprint/rtc_sync_reg.rdl
//             /trees/saida/saida-dev3/ip/athr/wifi/dev/shared/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.3 (Fri Aug 29 12:39:16 PDT 2008)                           
// Machine:    rhea                                                            
// OS:         Linux 2.6.9-78.0.5.ELsmp                                        
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _RTC_SYNC_REG_H_
#define _RTC_SYNC_REG_H_
// 32'h0240 (RTC_SYNC_RESET)
#define RTC_SYNC_RESET_RESET_L_MSB                                   0
#define RTC_SYNC_RESET_RESET_L_LSB                                   0
#define RTC_SYNC_RESET_RESET_L_MASK                                  0x00000001
#define RTC_SYNC_RESET_RESET_L_GET(x)                                (((x) & RTC_SYNC_RESET_RESET_L_MASK) >> RTC_SYNC_RESET_RESET_L_LSB)
#define RTC_SYNC_RESET_RESET_L_SET(x)                                (((x) << RTC_SYNC_RESET_RESET_L_LSB) & RTC_SYNC_RESET_RESET_L_MASK)
#define RTC_SYNC_RESET_RESET_L_RESET                                 0x0 // 0
#define RTC_SYNC_RESET_ADDRESS                                       0x0240
#define RTC_SYNC_RESET_OFFSET                                        0x0240
// SW modifiable bits
#define RTC_SYNC_RESET_SW_MASK                                       0x00000001
// bits defined at reset
#define RTC_SYNC_RESET_RSTMASK                                       0xffffffff
// reset value (ignore bits undefined at reset)
#define RTC_SYNC_RESET_RESET                                         0x00000000

// 32'h0244 (RTC_SYNC_STATUS)
#define RTC_SYNC_STATUS_PLL_CHANGING_MSB                             5
#define RTC_SYNC_STATUS_PLL_CHANGING_LSB                             5
#define RTC_SYNC_STATUS_PLL_CHANGING_MASK                            0x00000020
#define RTC_SYNC_STATUS_PLL_CHANGING_GET(x)                          (((x) & RTC_SYNC_STATUS_PLL_CHANGING_MASK) >> RTC_SYNC_STATUS_PLL_CHANGING_LSB)
#define RTC_SYNC_STATUS_PLL_CHANGING_SET(x)                          (((x) << RTC_SYNC_STATUS_PLL_CHANGING_LSB) & RTC_SYNC_STATUS_PLL_CHANGING_MASK)
#define RTC_SYNC_STATUS_PLL_CHANGING_RESET                           0x0 // 0
#define RTC_SYNC_STATUS_WRESET_MSB                                   4
#define RTC_SYNC_STATUS_WRESET_LSB                                   4
#define RTC_SYNC_STATUS_WRESET_MASK                                  0x00000010
#define RTC_SYNC_STATUS_WRESET_GET(x)                                (((x) & RTC_SYNC_STATUS_WRESET_MASK) >> RTC_SYNC_STATUS_WRESET_LSB)
#define RTC_SYNC_STATUS_WRESET_SET(x)                                (((x) << RTC_SYNC_STATUS_WRESET_LSB) & RTC_SYNC_STATUS_WRESET_MASK)
#define RTC_SYNC_STATUS_WRESET_RESET                                 0x0 // 0
#define RTC_SYNC_STATUS_WAKEUP_STATE_MSB                             3
#define RTC_SYNC_STATUS_WAKEUP_STATE_LSB                             3
#define RTC_SYNC_STATUS_WAKEUP_STATE_MASK                            0x00000008
#define RTC_SYNC_STATUS_WAKEUP_STATE_GET(x)                          (((x) & RTC_SYNC_STATUS_WAKEUP_STATE_MASK) >> RTC_SYNC_STATUS_WAKEUP_STATE_LSB)
#define RTC_SYNC_STATUS_WAKEUP_STATE_SET(x)                          (((x) << RTC_SYNC_STATUS_WAKEUP_STATE_LSB) & RTC_SYNC_STATUS_WAKEUP_STATE_MASK)
#define RTC_SYNC_STATUS_WAKEUP_STATE_RESET                           0x0 // 0
#define RTC_SYNC_STATUS_SLEEP_STATE_MSB                              2
#define RTC_SYNC_STATUS_SLEEP_STATE_LSB                              2
#define RTC_SYNC_STATUS_SLEEP_STATE_MASK                             0x00000004
#define RTC_SYNC_STATUS_SLEEP_STATE_GET(x)                           (((x) & RTC_SYNC_STATUS_SLEEP_STATE_MASK) >> RTC_SYNC_STATUS_SLEEP_STATE_LSB)
#define RTC_SYNC_STATUS_SLEEP_STATE_SET(x)                           (((x) << RTC_SYNC_STATUS_SLEEP_STATE_LSB) & RTC_SYNC_STATUS_SLEEP_STATE_MASK)
#define RTC_SYNC_STATUS_SLEEP_STATE_RESET                            0x0 // 0
#define RTC_SYNC_STATUS_ON_STATE_MSB                                 1
#define RTC_SYNC_STATUS_ON_STATE_LSB                                 1
#define RTC_SYNC_STATUS_ON_STATE_MASK                                0x00000002
#define RTC_SYNC_STATUS_ON_STATE_GET(x)                              (((x) & RTC_SYNC_STATUS_ON_STATE_MASK) >> RTC_SYNC_STATUS_ON_STATE_LSB)
#define RTC_SYNC_STATUS_ON_STATE_SET(x)                              (((x) << RTC_SYNC_STATUS_ON_STATE_LSB) & RTC_SYNC_STATUS_ON_STATE_MASK)
#define RTC_SYNC_STATUS_ON_STATE_RESET                               0x0 // 0
#define RTC_SYNC_STATUS_SHUTDOWN_STATE_MSB                           0
#define RTC_SYNC_STATUS_SHUTDOWN_STATE_LSB                           0
#define RTC_SYNC_STATUS_SHUTDOWN_STATE_MASK                          0x00000001
#define RTC_SYNC_STATUS_SHUTDOWN_STATE_GET(x)                        (((x) & RTC_SYNC_STATUS_SHUTDOWN_STATE_MASK) >> RTC_SYNC_STATUS_SHUTDOWN_STATE_LSB)
#define RTC_SYNC_STATUS_SHUTDOWN_STATE_SET(x)                        (((x) << RTC_SYNC_STATUS_SHUTDOWN_STATE_LSB) & RTC_SYNC_STATUS_SHUTDOWN_STATE_MASK)
#define RTC_SYNC_STATUS_SHUTDOWN_STATE_RESET                         0x0 // 0
#define RTC_SYNC_STATUS_ADDRESS                                      0x0244
#define RTC_SYNC_STATUS_OFFSET                                       0x0244
// SW modifiable bits
#define RTC_SYNC_STATUS_SW_MASK                                      0x0000003f
// bits defined at reset
#define RTC_SYNC_STATUS_RSTMASK                                      0xffffffff
// reset value (ignore bits undefined at reset)
#define RTC_SYNC_STATUS_RESET                                        0x00000000

// 32'h0248 (RTC_SYNC_DERIVED)
#define RTC_SYNC_DERIVED_FORCE_LPO_PWD_MSB                           3
#define RTC_SYNC_DERIVED_FORCE_LPO_PWD_LSB                           3
#define RTC_SYNC_DERIVED_FORCE_LPO_PWD_MASK                          0x00000008
#define RTC_SYNC_DERIVED_FORCE_LPO_PWD_GET(x)                        (((x) & RTC_SYNC_DERIVED_FORCE_LPO_PWD_MASK) >> RTC_SYNC_DERIVED_FORCE_LPO_PWD_LSB)
#define RTC_SYNC_DERIVED_FORCE_LPO_PWD_SET(x)                        (((x) << RTC_SYNC_DERIVED_FORCE_LPO_PWD_LSB) & RTC_SYNC_DERIVED_FORCE_LPO_PWD_MASK)
#define RTC_SYNC_DERIVED_FORCE_LPO_PWD_RESET                         0x0 // 0
#define RTC_SYNC_DERIVED_FORCE_SWREG_PWD_MSB                         2
#define RTC_SYNC_DERIVED_FORCE_SWREG_PWD_LSB                         2
#define RTC_SYNC_DERIVED_FORCE_SWREG_PWD_MASK                        0x00000004
#define RTC_SYNC_DERIVED_FORCE_SWREG_PWD_GET(x)                      (((x) & RTC_SYNC_DERIVED_FORCE_SWREG_PWD_MASK) >> RTC_SYNC_DERIVED_FORCE_SWREG_PWD_LSB)
#define RTC_SYNC_DERIVED_FORCE_SWREG_PWD_SET(x)                      (((x) << RTC_SYNC_DERIVED_FORCE_SWREG_PWD_LSB) & RTC_SYNC_DERIVED_FORCE_SWREG_PWD_MASK)
#define RTC_SYNC_DERIVED_FORCE_SWREG_PWD_RESET                       0x0 // 0
#define RTC_SYNC_DERIVED_FORCE_MSB                                   1
#define RTC_SYNC_DERIVED_FORCE_LSB                                   1
#define RTC_SYNC_DERIVED_FORCE_MASK                                  0x00000002
#define RTC_SYNC_DERIVED_FORCE_GET(x)                                (((x) & RTC_SYNC_DERIVED_FORCE_MASK) >> RTC_SYNC_DERIVED_FORCE_LSB)
#define RTC_SYNC_DERIVED_FORCE_SET(x)                                (((x) << RTC_SYNC_DERIVED_FORCE_LSB) & RTC_SYNC_DERIVED_FORCE_MASK)
#define RTC_SYNC_DERIVED_FORCE_RESET                                 0x0 // 0
#define RTC_SYNC_DERIVED_BYPASS_MSB                                  0
#define RTC_SYNC_DERIVED_BYPASS_LSB                                  0
#define RTC_SYNC_DERIVED_BYPASS_MASK                                 0x00000001
#define RTC_SYNC_DERIVED_BYPASS_GET(x)                               (((x) & RTC_SYNC_DERIVED_BYPASS_MASK) >> RTC_SYNC_DERIVED_BYPASS_LSB)
#define RTC_SYNC_DERIVED_BYPASS_SET(x)                               (((x) << RTC_SYNC_DERIVED_BYPASS_LSB) & RTC_SYNC_DERIVED_BYPASS_MASK)
#define RTC_SYNC_DERIVED_BYPASS_RESET                                0x0 // 0
#define RTC_SYNC_DERIVED_ADDRESS                                     0x0248
#define RTC_SYNC_DERIVED_OFFSET                                      0x0248
// SW modifiable bits
#define RTC_SYNC_DERIVED_SW_MASK                                     0x0000000f
// bits defined at reset
#define RTC_SYNC_DERIVED_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define RTC_SYNC_DERIVED_RESET                                       0x00000000

// 32'h024c (RTC_SYNC_FORCE_WAKE)
#define RTC_SYNC_FORCE_WAKE_LEGACY_MODE_MSB                          3
#define RTC_SYNC_FORCE_WAKE_LEGACY_MODE_LSB                          3
#define RTC_SYNC_FORCE_WAKE_LEGACY_MODE_MASK                         0x00000008
#define RTC_SYNC_FORCE_WAKE_LEGACY_MODE_GET(x)                       (((x) & RTC_SYNC_FORCE_WAKE_LEGACY_MODE_MASK) >> RTC_SYNC_FORCE_WAKE_LEGACY_MODE_LSB)
#define RTC_SYNC_FORCE_WAKE_LEGACY_MODE_SET(x)                       (((x) << RTC_SYNC_FORCE_WAKE_LEGACY_MODE_LSB) & RTC_SYNC_FORCE_WAKE_LEGACY_MODE_MASK)
#define RTC_SYNC_FORCE_WAKE_LEGACY_MODE_RESET                        0x0 // 0
#define RTC_SYNC_FORCE_WAKE_STATE_MSB                                2
#define RTC_SYNC_FORCE_WAKE_STATE_LSB                                2
#define RTC_SYNC_FORCE_WAKE_STATE_MASK                               0x00000004
#define RTC_SYNC_FORCE_WAKE_STATE_GET(x)                             (((x) & RTC_SYNC_FORCE_WAKE_STATE_MASK) >> RTC_SYNC_FORCE_WAKE_STATE_LSB)
#define RTC_SYNC_FORCE_WAKE_STATE_SET(x)                             (((x) << RTC_SYNC_FORCE_WAKE_STATE_LSB) & RTC_SYNC_FORCE_WAKE_STATE_MASK)
#define RTC_SYNC_FORCE_WAKE_STATE_RESET                              0x0 // 0
#define RTC_SYNC_FORCE_WAKE_INTR_MSB                                 1
#define RTC_SYNC_FORCE_WAKE_INTR_LSB                                 1
#define RTC_SYNC_FORCE_WAKE_INTR_MASK                                0x00000002
#define RTC_SYNC_FORCE_WAKE_INTR_GET(x)                              (((x) & RTC_SYNC_FORCE_WAKE_INTR_MASK) >> RTC_SYNC_FORCE_WAKE_INTR_LSB)
#define RTC_SYNC_FORCE_WAKE_INTR_SET(x)                              (((x) << RTC_SYNC_FORCE_WAKE_INTR_LSB) & RTC_SYNC_FORCE_WAKE_INTR_MASK)
#define RTC_SYNC_FORCE_WAKE_INTR_RESET                               0x1 // 1
#define RTC_SYNC_FORCE_WAKE_ENABLE_MSB                               0
#define RTC_SYNC_FORCE_WAKE_ENABLE_LSB                               0
#define RTC_SYNC_FORCE_WAKE_ENABLE_MASK                              0x00000001
#define RTC_SYNC_FORCE_WAKE_ENABLE_GET(x)                            (((x) & RTC_SYNC_FORCE_WAKE_ENABLE_MASK) >> RTC_SYNC_FORCE_WAKE_ENABLE_LSB)
#define RTC_SYNC_FORCE_WAKE_ENABLE_SET(x)                            (((x) << RTC_SYNC_FORCE_WAKE_ENABLE_LSB) & RTC_SYNC_FORCE_WAKE_ENABLE_MASK)
#define RTC_SYNC_FORCE_WAKE_ENABLE_RESET                             0x0 // 0
#define RTC_SYNC_FORCE_WAKE_ADDRESS                                  0x024c
#define RTC_SYNC_FORCE_WAKE_OFFSET                                   0x024c
// SW modifiable bits
#define RTC_SYNC_FORCE_WAKE_SW_MASK                                  0x0000000f
// bits defined at reset
#define RTC_SYNC_FORCE_WAKE_RSTMASK                                  0xffffffff
// reset value (ignore bits undefined at reset)
#define RTC_SYNC_FORCE_WAKE_RESET                                    0x00000002

// 32'h0250 (RTC_SYNC_INTR_CAUSE)
#define RTC_SYNC_INTR_CAUSE_PLL_CHANGING_MSB                         5
#define RTC_SYNC_INTR_CAUSE_PLL_CHANGING_LSB                         5
#define RTC_SYNC_INTR_CAUSE_PLL_CHANGING_MASK                        0x00000020
#define RTC_SYNC_INTR_CAUSE_PLL_CHANGING_GET(x)                      (((x) & RTC_SYNC_INTR_CAUSE_PLL_CHANGING_MASK) >> RTC_SYNC_INTR_CAUSE_PLL_CHANGING_LSB)
#define RTC_SYNC_INTR_CAUSE_PLL_CHANGING_SET(x)                      (((x) << RTC_SYNC_INTR_CAUSE_PLL_CHANGING_LSB) & RTC_SYNC_INTR_CAUSE_PLL_CHANGING_MASK)
#define RTC_SYNC_INTR_CAUSE_PLL_CHANGING_RESET                       0x0 // 0
#define RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_MSB                         4
#define RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_LSB                         4
#define RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_MASK                        0x00000010
#define RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_GET(x)                      (((x) & RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_MASK) >> RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_LSB)
#define RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_SET(x)                      (((x) << RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_LSB) & RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_MASK)
#define RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_RESET                       0x0 // 0
#define RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_MSB                         3
#define RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_LSB                         3
#define RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_MASK                        0x00000008
#define RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_GET(x)                      (((x) & RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_MASK) >> RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_LSB)
#define RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_SET(x)                      (((x) << RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_LSB) & RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_MASK)
#define RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_RESET                       0x0 // 0
#define RTC_SYNC_INTR_CAUSE_SLEEP_STATE_MSB                          2
#define RTC_SYNC_INTR_CAUSE_SLEEP_STATE_LSB                          2
#define RTC_SYNC_INTR_CAUSE_SLEEP_STATE_MASK                         0x00000004
#define RTC_SYNC_INTR_CAUSE_SLEEP_STATE_GET(x)                       (((x) & RTC_SYNC_INTR_CAUSE_SLEEP_STATE_MASK) >> RTC_SYNC_INTR_CAUSE_SLEEP_STATE_LSB)
#define RTC_SYNC_INTR_CAUSE_SLEEP_STATE_SET(x)                       (((x) << RTC_SYNC_INTR_CAUSE_SLEEP_STATE_LSB) & RTC_SYNC_INTR_CAUSE_SLEEP_STATE_MASK)
#define RTC_SYNC_INTR_CAUSE_SLEEP_STATE_RESET                        0x0 // 0
#define RTC_SYNC_INTR_CAUSE_ON_STATE_MSB                             1
#define RTC_SYNC_INTR_CAUSE_ON_STATE_LSB                             1
#define RTC_SYNC_INTR_CAUSE_ON_STATE_MASK                            0x00000002
#define RTC_SYNC_INTR_CAUSE_ON_STATE_GET(x)                          (((x) & RTC_SYNC_INTR_CAUSE_ON_STATE_MASK) >> RTC_SYNC_INTR_CAUSE_ON_STATE_LSB)
#define RTC_SYNC_INTR_CAUSE_ON_STATE_SET(x)                          (((x) << RTC_SYNC_INTR_CAUSE_ON_STATE_LSB) & RTC_SYNC_INTR_CAUSE_ON_STATE_MASK)
#define RTC_SYNC_INTR_CAUSE_ON_STATE_RESET                           0x0 // 0
#define RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_MSB                       0
#define RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_LSB                       0
#define RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_MASK                      0x00000001
#define RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_GET(x)                    (((x) & RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_MASK) >> RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_LSB)
#define RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_SET(x)                    (((x) << RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_LSB) & RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_MASK)
#define RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_RESET                     0x0 // 0
#define RTC_SYNC_INTR_CAUSE_ADDRESS                                  0x0250
#define RTC_SYNC_INTR_CAUSE_OFFSET                                   0x0250
// SW modifiable bits
#define RTC_SYNC_INTR_CAUSE_SW_MASK                                  0x0000003f
// bits defined at reset
#define RTC_SYNC_INTR_CAUSE_RSTMASK                                  0xffffffc0
// reset value (ignore bits undefined at reset)
#define RTC_SYNC_INTR_CAUSE_RESET                                    0x00000000

// 32'h0254 (RTC_SYNC_INTR_ENABLE)
#define RTC_SYNC_INTR_ENABLE_PLL_CHANGING_MSB                        5
#define RTC_SYNC_INTR_ENABLE_PLL_CHANGING_LSB                        5
#define RTC_SYNC_INTR_ENABLE_PLL_CHANGING_MASK                       0x00000020
#define RTC_SYNC_INTR_ENABLE_PLL_CHANGING_GET(x)                     (((x) & RTC_SYNC_INTR_ENABLE_PLL_CHANGING_MASK) >> RTC_SYNC_INTR_ENABLE_PLL_CHANGING_LSB)
#define RTC_SYNC_INTR_ENABLE_PLL_CHANGING_SET(x)                     (((x) << RTC_SYNC_INTR_ENABLE_PLL_CHANGING_LSB) & RTC_SYNC_INTR_ENABLE_PLL_CHANGING_MASK)
#define RTC_SYNC_INTR_ENABLE_PLL_CHANGING_RESET                      0x0 // 0
#define RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_MSB                        4
#define RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_LSB                        4
#define RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_MASK                       0x00000010
#define RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_GET(x)                     (((x) & RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_MASK) >> RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_LSB)
#define RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_SET(x)                     (((x) << RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_LSB) & RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_MASK)
#define RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_RESET                      0x0 // 0
#define RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_MSB                        3
#define RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_LSB                        3
#define RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_MASK                       0x00000008
#define RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_GET(x)                     (((x) & RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_MASK) >> RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_LSB)
#define RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_SET(x)                     (((x) << RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_LSB) & RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_MASK)
#define RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_RESET                      0x0 // 0
#define RTC_SYNC_INTR_ENABLE_SLEEP_STATE_MSB                         2
#define RTC_SYNC_INTR_ENABLE_SLEEP_STATE_LSB                         2
#define RTC_SYNC_INTR_ENABLE_SLEEP_STATE_MASK                        0x00000004
#define RTC_SYNC_INTR_ENABLE_SLEEP_STATE_GET(x)                      (((x) & RTC_SYNC_INTR_ENABLE_SLEEP_STATE_MASK) >> RTC_SYNC_INTR_ENABLE_SLEEP_STATE_LSB)
#define RTC_SYNC_INTR_ENABLE_SLEEP_STATE_SET(x)                      (((x) << RTC_SYNC_INTR_ENABLE_SLEEP_STATE_LSB) & RTC_SYNC_INTR_ENABLE_SLEEP_STATE_MASK)
#define RTC_SYNC_INTR_ENABLE_SLEEP_STATE_RESET                       0x0 // 0
#define RTC_SYNC_INTR_ENABLE_ON_STATE_MSB                            1
#define RTC_SYNC_INTR_ENABLE_ON_STATE_LSB                            1
#define RTC_SYNC_INTR_ENABLE_ON_STATE_MASK                           0x00000002
#define RTC_SYNC_INTR_ENABLE_ON_STATE_GET(x)                         (((x) & RTC_SYNC_INTR_ENABLE_ON_STATE_MASK) >> RTC_SYNC_INTR_ENABLE_ON_STATE_LSB)
#define RTC_SYNC_INTR_ENABLE_ON_STATE_SET(x)                         (((x) << RTC_SYNC_INTR_ENABLE_ON_STATE_LSB) & RTC_SYNC_INTR_ENABLE_ON_STATE_MASK)
#define RTC_SYNC_INTR_ENABLE_ON_STATE_RESET                          0x0 // 0
#define RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_MSB                      0
#define RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_LSB                      0
#define RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_MASK                     0x00000001
#define RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_GET(x)                   (((x) & RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_MASK) >> RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_LSB)
#define RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_SET(x)                   (((x) << RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_LSB) & RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_MASK)
#define RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_RESET                    0x0 // 0
#define RTC_SYNC_INTR_ENABLE_ADDRESS                                 0x0254
#define RTC_SYNC_INTR_ENABLE_OFFSET                                  0x0254
// SW modifiable bits
#define RTC_SYNC_INTR_ENABLE_SW_MASK                                 0x0000003f
// bits defined at reset
#define RTC_SYNC_INTR_ENABLE_RSTMASK                                 0xffffffff
// reset value (ignore bits undefined at reset)
#define RTC_SYNC_INTR_ENABLE_RESET                                   0x00000000

// 32'h0258 (RTC_SYNC_INTR_MASK)
#define RTC_SYNC_INTR_MASK_PLL_CHANGING_MSB                          5
#define RTC_SYNC_INTR_MASK_PLL_CHANGING_LSB                          5
#define RTC_SYNC_INTR_MASK_PLL_CHANGING_MASK                         0x00000020
#define RTC_SYNC_INTR_MASK_PLL_CHANGING_GET(x)                       (((x) & RTC_SYNC_INTR_MASK_PLL_CHANGING_MASK) >> RTC_SYNC_INTR_MASK_PLL_CHANGING_LSB)
#define RTC_SYNC_INTR_MASK_PLL_CHANGING_SET(x)                       (((x) << RTC_SYNC_INTR_MASK_PLL_CHANGING_LSB) & RTC_SYNC_INTR_MASK_PLL_CHANGING_MASK)
#define RTC_SYNC_INTR_MASK_PLL_CHANGING_RESET                        0x0 // 0
#define RTC_SYNC_INTR_MASK_SLEEP_ACCESS_MSB                          4
#define RTC_SYNC_INTR_MASK_SLEEP_ACCESS_LSB                          4
#define RTC_SYNC_INTR_MASK_SLEEP_ACCESS_MASK                         0x00000010
#define RTC_SYNC_INTR_MASK_SLEEP_ACCESS_GET(x)                       (((x) & RTC_SYNC_INTR_MASK_SLEEP_ACCESS_MASK) >> RTC_SYNC_INTR_MASK_SLEEP_ACCESS_LSB)
#define RTC_SYNC_INTR_MASK_SLEEP_ACCESS_SET(x)                       (((x) << RTC_SYNC_INTR_MASK_SLEEP_ACCESS_LSB) & RTC_SYNC_INTR_MASK_SLEEP_ACCESS_MASK)
#define RTC_SYNC_INTR_MASK_SLEEP_ACCESS_RESET                        0x0 // 0
#define RTC_SYNC_INTR_MASK_WAKEUP_STATE_MSB                          3
#define RTC_SYNC_INTR_MASK_WAKEUP_STATE_LSB                          3
#define RTC_SYNC_INTR_MASK_WAKEUP_STATE_MASK                         0x00000008
#define RTC_SYNC_INTR_MASK_WAKEUP_STATE_GET(x)                       (((x) & RTC_SYNC_INTR_MASK_WAKEUP_STATE_MASK) >> RTC_SYNC_INTR_MASK_WAKEUP_STATE_LSB)
#define RTC_SYNC_INTR_MASK_WAKEUP_STATE_SET(x)                       (((x) << RTC_SYNC_INTR_MASK_WAKEUP_STATE_LSB) & RTC_SYNC_INTR_MASK_WAKEUP_STATE_MASK)
#define RTC_SYNC_INTR_MASK_WAKEUP_STATE_RESET                        0x0 // 0
#define RTC_SYNC_INTR_MASK_SLEEP_STATE_MSB                           2
#define RTC_SYNC_INTR_MASK_SLEEP_STATE_LSB                           2
#define RTC_SYNC_INTR_MASK_SLEEP_STATE_MASK                          0x00000004
#define RTC_SYNC_INTR_MASK_SLEEP_STATE_GET(x)                        (((x) & RTC_SYNC_INTR_MASK_SLEEP_STATE_MASK) >> RTC_SYNC_INTR_MASK_SLEEP_STATE_LSB)
#define RTC_SYNC_INTR_MASK_SLEEP_STATE_SET(x)                        (((x) << RTC_SYNC_INTR_MASK_SLEEP_STATE_LSB) & RTC_SYNC_INTR_MASK_SLEEP_STATE_MASK)
#define RTC_SYNC_INTR_MASK_SLEEP_STATE_RESET                         0x0 // 0
#define RTC_SYNC_INTR_MASK_ON_STATE_MSB                              1
#define RTC_SYNC_INTR_MASK_ON_STATE_LSB                              1
#define RTC_SYNC_INTR_MASK_ON_STATE_MASK                             0x00000002
#define RTC_SYNC_INTR_MASK_ON_STATE_GET(x)                           (((x) & RTC_SYNC_INTR_MASK_ON_STATE_MASK) >> RTC_SYNC_INTR_MASK_ON_STATE_LSB)
#define RTC_SYNC_INTR_MASK_ON_STATE_SET(x)                           (((x) << RTC_SYNC_INTR_MASK_ON_STATE_LSB) & RTC_SYNC_INTR_MASK_ON_STATE_MASK)
#define RTC_SYNC_INTR_MASK_ON_STATE_RESET                            0x0 // 0
#define RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_MSB                        0
#define RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_LSB                        0
#define RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_MASK                       0x00000001
#define RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_GET(x)                     (((x) & RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_MASK) >> RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_LSB)
#define RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_SET(x)                     (((x) << RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_LSB) & RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_MASK)
#define RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_RESET                      0x0 // 0
#define RTC_SYNC_INTR_MASK_ADDRESS                                   0x0258
#define RTC_SYNC_INTR_MASK_OFFSET                                    0x0258
// SW modifiable bits
#define RTC_SYNC_INTR_MASK_SW_MASK                                   0x0000003f
// bits defined at reset
#define RTC_SYNC_INTR_MASK_RSTMASK                                   0xffffffff
// reset value (ignore bits undefined at reset)
#define RTC_SYNC_INTR_MASK_RESET                                     0x00000000


#endif /* _RTC_SYNC_REG_H_ */
