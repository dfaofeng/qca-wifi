//                                                                             
// File:       ./rtc_wlan_reg.h                                                
// Creator:    osarode                                                         
// Time:       Tuesday Feb 14, 2012 [4:31:42 pm]                               
//                                                                             
// Path:       /trees/osarode/p4/ip/athr/wifi/dev/rtl/rtc/blueprint            
// Arguments:  /cad/denali/blueprint/3.7.3//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -ch -Wdesc rtc_wlan_reg.rdl   
//                                                                             
// Sources:    /trees/osarode/p4/ip/athr/wifi/sysconfig/rtc_wlan_reg_sysconfig.rdl
//             /trees/osarode/p4/ip/athr/wifi/dev/rtl/rtc/blueprint/rtc_wlan_reg.rdl
//             /trees/osarode/p4/ip/athr/wifi/dev/shared/env/blueprint/ath_vrh.pm
//             /cad/local/lib/perl/Pinfo.pm                                    
//                                                                             
// Blueprint:   3.7.3 (Fri Aug 29 12:39:16 PDT 2008)                           
// Machine:    halifax                                                         
// OS:         Linux 2.6.18-274.17.1.el5                                       
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _RTC_WLAN_REG_H_
#define _RTC_WLAN_REG_H_
// 32'h0000 (WLAN_RESET_CONTROL)
#define WLAN_RESET_CONTROL_MCI_RESET_MSB                             7
#define WLAN_RESET_CONTROL_MCI_RESET_LSB                             7
#define WLAN_RESET_CONTROL_MCI_RESET_MASK                            0x00000080
#define WLAN_RESET_CONTROL_MCI_RESET_GET(x)                          (((x) & WLAN_RESET_CONTROL_MCI_RESET_MASK) >> WLAN_RESET_CONTROL_MCI_RESET_LSB)
#define WLAN_RESET_CONTROL_MCI_RESET_SET(x)                          (((x) << WLAN_RESET_CONTROL_MCI_RESET_LSB) & WLAN_RESET_CONTROL_MCI_RESET_MASK)
#define WLAN_RESET_CONTROL_MCI_RESET_RESET                           0x0 // 0
#define WLAN_RESET_CONTROL_RADIO_SRESET_MSB                          6
#define WLAN_RESET_CONTROL_RADIO_SRESET_LSB                          6
#define WLAN_RESET_CONTROL_RADIO_SRESET_MASK                         0x00000040
#define WLAN_RESET_CONTROL_RADIO_SRESET_GET(x)                       (((x) & WLAN_RESET_CONTROL_RADIO_SRESET_MASK) >> WLAN_RESET_CONTROL_RADIO_SRESET_LSB)
#define WLAN_RESET_CONTROL_RADIO_SRESET_SET(x)                       (((x) << WLAN_RESET_CONTROL_RADIO_SRESET_LSB) & WLAN_RESET_CONTROL_RADIO_SRESET_MASK)
#define WLAN_RESET_CONTROL_RADIO_SRESET_RESET                        0x1 // 1
#define WLAN_RESET_CONTROL_BB_COLD_RST_MSB                           5
#define WLAN_RESET_CONTROL_BB_COLD_RST_LSB                           5
#define WLAN_RESET_CONTROL_BB_COLD_RST_MASK                          0x00000020
#define WLAN_RESET_CONTROL_BB_COLD_RST_GET(x)                        (((x) & WLAN_RESET_CONTROL_BB_COLD_RST_MASK) >> WLAN_RESET_CONTROL_BB_COLD_RST_LSB)
#define WLAN_RESET_CONTROL_BB_COLD_RST_SET(x)                        (((x) << WLAN_RESET_CONTROL_BB_COLD_RST_LSB) & WLAN_RESET_CONTROL_BB_COLD_RST_MASK)
#define WLAN_RESET_CONTROL_BB_COLD_RST_RESET                         0x1 // 1
#define WLAN_RESET_CONTROL_BB_WARM_RST_MSB                           4
#define WLAN_RESET_CONTROL_BB_WARM_RST_LSB                           4
#define WLAN_RESET_CONTROL_BB_WARM_RST_MASK                          0x00000010
#define WLAN_RESET_CONTROL_BB_WARM_RST_GET(x)                        (((x) & WLAN_RESET_CONTROL_BB_WARM_RST_MASK) >> WLAN_RESET_CONTROL_BB_WARM_RST_LSB)
#define WLAN_RESET_CONTROL_BB_WARM_RST_SET(x)                        (((x) << WLAN_RESET_CONTROL_BB_WARM_RST_LSB) & WLAN_RESET_CONTROL_BB_WARM_RST_MASK)
#define WLAN_RESET_CONTROL_BB_WARM_RST_RESET                         0x1 // 1
#define WLAN_RESET_CONTROL_COLD_RST_MSB                              3
#define WLAN_RESET_CONTROL_COLD_RST_LSB                              3
#define WLAN_RESET_CONTROL_COLD_RST_MASK                             0x00000008
#define WLAN_RESET_CONTROL_COLD_RST_GET(x)                           (((x) & WLAN_RESET_CONTROL_COLD_RST_MASK) >> WLAN_RESET_CONTROL_COLD_RST_LSB)
#define WLAN_RESET_CONTROL_COLD_RST_SET(x)                           (((x) << WLAN_RESET_CONTROL_COLD_RST_LSB) & WLAN_RESET_CONTROL_COLD_RST_MASK)
#define WLAN_RESET_CONTROL_COLD_RST_RESET                            0x0 // 0
#define WLAN_RESET_CONTROL_WARM_RST_MSB                              2
#define WLAN_RESET_CONTROL_WARM_RST_LSB                              2
#define WLAN_RESET_CONTROL_WARM_RST_MASK                             0x00000004
#define WLAN_RESET_CONTROL_WARM_RST_GET(x)                           (((x) & WLAN_RESET_CONTROL_WARM_RST_MASK) >> WLAN_RESET_CONTROL_WARM_RST_LSB)
#define WLAN_RESET_CONTROL_WARM_RST_SET(x)                           (((x) << WLAN_RESET_CONTROL_WARM_RST_LSB) & WLAN_RESET_CONTROL_WARM_RST_MASK)
#define WLAN_RESET_CONTROL_WARM_RST_RESET                            0x0 // 0
#define WLAN_RESET_CONTROL_MAC_COLD_RST_MSB                          1
#define WLAN_RESET_CONTROL_MAC_COLD_RST_LSB                          1
#define WLAN_RESET_CONTROL_MAC_COLD_RST_MASK                         0x00000002
#define WLAN_RESET_CONTROL_MAC_COLD_RST_GET(x)                       (((x) & WLAN_RESET_CONTROL_MAC_COLD_RST_MASK) >> WLAN_RESET_CONTROL_MAC_COLD_RST_LSB)
#define WLAN_RESET_CONTROL_MAC_COLD_RST_SET(x)                       (((x) << WLAN_RESET_CONTROL_MAC_COLD_RST_LSB) & WLAN_RESET_CONTROL_MAC_COLD_RST_MASK)
#define WLAN_RESET_CONTROL_MAC_COLD_RST_RESET                        0x1 // 1
#define WLAN_RESET_CONTROL_MAC_WARM_RST_MSB                          0
#define WLAN_RESET_CONTROL_MAC_WARM_RST_LSB                          0
#define WLAN_RESET_CONTROL_MAC_WARM_RST_MASK                         0x00000001
#define WLAN_RESET_CONTROL_MAC_WARM_RST_GET(x)                       (((x) & WLAN_RESET_CONTROL_MAC_WARM_RST_MASK) >> WLAN_RESET_CONTROL_MAC_WARM_RST_LSB)
#define WLAN_RESET_CONTROL_MAC_WARM_RST_SET(x)                       (((x) << WLAN_RESET_CONTROL_MAC_WARM_RST_LSB) & WLAN_RESET_CONTROL_MAC_WARM_RST_MASK)
#define WLAN_RESET_CONTROL_MAC_WARM_RST_RESET                        0x1 // 1
#define WLAN_RESET_CONTROL_ADDRESS                                   0x0000
#define WLAN_RESET_CONTROL_OFFSET                                    0x0000
// SW modifiable bits
#define WLAN_RESET_CONTROL_SW_MASK                                   0x000000ff
// bits defined at reset
#define WLAN_RESET_CONTROL_RSTMASK                                   0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_RESET_CONTROL_RESET                                     0x00000073

// 32'h0004 (WLAN_XTAL_CONTROL)
#define WLAN_XTAL_CONTROL_TCXO_MSB                                   0
#define WLAN_XTAL_CONTROL_TCXO_LSB                                   0
#define WLAN_XTAL_CONTROL_TCXO_MASK                                  0x00000001
#define WLAN_XTAL_CONTROL_TCXO_GET(x)                                (((x) & WLAN_XTAL_CONTROL_TCXO_MASK) >> WLAN_XTAL_CONTROL_TCXO_LSB)
#define WLAN_XTAL_CONTROL_TCXO_SET(x)                                (((x) << WLAN_XTAL_CONTROL_TCXO_LSB) & WLAN_XTAL_CONTROL_TCXO_MASK)
#define WLAN_XTAL_CONTROL_TCXO_RESET                                 0x0 // 0
#define WLAN_XTAL_CONTROL_ADDRESS                                    0x0004
#define WLAN_XTAL_CONTROL_OFFSET                                     0x0004
// SW modifiable bits
#define WLAN_XTAL_CONTROL_SW_MASK                                    0x00000001
// bits defined at reset
#define WLAN_XTAL_CONTROL_RSTMASK                                    0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_XTAL_CONTROL_RESET                                      0x00000000

// 32'h0008 (WLAN_REG_CONTROL0)
#define WLAN_REG_CONTROL0_SWREG_BITS_MSB                             31
#define WLAN_REG_CONTROL0_SWREG_BITS_LSB                             0
#define WLAN_REG_CONTROL0_SWREG_BITS_MASK                            0xffffffff
#define WLAN_REG_CONTROL0_SWREG_BITS_GET(x)                          (((x) & WLAN_REG_CONTROL0_SWREG_BITS_MASK) >> WLAN_REG_CONTROL0_SWREG_BITS_LSB)
#define WLAN_REG_CONTROL0_SWREG_BITS_SET(x)                          (((x) << WLAN_REG_CONTROL0_SWREG_BITS_LSB) & WLAN_REG_CONTROL0_SWREG_BITS_MASK)
#define WLAN_REG_CONTROL0_SWREG_BITS_RESET                           0x0 // 0
#define WLAN_REG_CONTROL0_ADDRESS                                    0x0008
#define WLAN_REG_CONTROL0_OFFSET                                     0x0008
// SW modifiable bits
#define WLAN_REG_CONTROL0_SW_MASK                                    0xffffffff
// bits defined at reset
#define WLAN_REG_CONTROL0_RSTMASK                                    0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_REG_CONTROL0_RESET                                      0x00000000

// 32'h000c (WLAN_REG_CONTROL1)
#define WLAN_REG_CONTROL1_OTPREG_LVL_MSB                             2
#define WLAN_REG_CONTROL1_OTPREG_LVL_LSB                             1
#define WLAN_REG_CONTROL1_OTPREG_LVL_MASK                            0x00000006
#define WLAN_REG_CONTROL1_OTPREG_LVL_GET(x)                          (((x) & WLAN_REG_CONTROL1_OTPREG_LVL_MASK) >> WLAN_REG_CONTROL1_OTPREG_LVL_LSB)
#define WLAN_REG_CONTROL1_OTPREG_LVL_SET(x)                          (((x) << WLAN_REG_CONTROL1_OTPREG_LVL_LSB) & WLAN_REG_CONTROL1_OTPREG_LVL_MASK)
#define WLAN_REG_CONTROL1_OTPREG_LVL_RESET                           0x0 // 0
#define WLAN_REG_CONTROL1_SWREG_PROGRAM_MSB                          0
#define WLAN_REG_CONTROL1_SWREG_PROGRAM_LSB                          0
#define WLAN_REG_CONTROL1_SWREG_PROGRAM_MASK                         0x00000001
#define WLAN_REG_CONTROL1_SWREG_PROGRAM_GET(x)                       (((x) & WLAN_REG_CONTROL1_SWREG_PROGRAM_MASK) >> WLAN_REG_CONTROL1_SWREG_PROGRAM_LSB)
#define WLAN_REG_CONTROL1_SWREG_PROGRAM_SET(x)                       (((x) << WLAN_REG_CONTROL1_SWREG_PROGRAM_LSB) & WLAN_REG_CONTROL1_SWREG_PROGRAM_MASK)
#define WLAN_REG_CONTROL1_SWREG_PROGRAM_RESET                        0x0 // 0
#define WLAN_REG_CONTROL1_ADDRESS                                    0x000c
#define WLAN_REG_CONTROL1_OFFSET                                     0x000c
// SW modifiable bits
#define WLAN_REG_CONTROL1_SW_MASK                                    0x00000007
// bits defined at reset
#define WLAN_REG_CONTROL1_RSTMASK                                    0xfffffffe
// reset value (ignore bits undefined at reset)
#define WLAN_REG_CONTROL1_RESET                                      0x00000000

// 32'h0010 (WLAN_QUADRATURE)
#define WLAN_QUADRATURE_ADC_MSB                                      7
#define WLAN_QUADRATURE_ADC_LSB                                      4
#define WLAN_QUADRATURE_ADC_MASK                                     0x000000f0
#define WLAN_QUADRATURE_ADC_GET(x)                                   (((x) & WLAN_QUADRATURE_ADC_MASK) >> WLAN_QUADRATURE_ADC_LSB)
#define WLAN_QUADRATURE_ADC_SET(x)                                   (((x) << WLAN_QUADRATURE_ADC_LSB) & WLAN_QUADRATURE_ADC_MASK)
#define WLAN_QUADRATURE_ADC_RESET                                    0x0 // 0
#define WLAN_QUADRATURE_DAC_MSB                                      2
#define WLAN_QUADRATURE_DAC_LSB                                      0
#define WLAN_QUADRATURE_DAC_MASK                                     0x00000007
#define WLAN_QUADRATURE_DAC_GET(x)                                   (((x) & WLAN_QUADRATURE_DAC_MASK) >> WLAN_QUADRATURE_DAC_LSB)
#define WLAN_QUADRATURE_DAC_SET(x)                                   (((x) << WLAN_QUADRATURE_DAC_LSB) & WLAN_QUADRATURE_DAC_MASK)
#define WLAN_QUADRATURE_DAC_RESET                                    0x0 // 0
#define WLAN_QUADRATURE_ADDRESS                                      0x0010
#define WLAN_QUADRATURE_OFFSET                                       0x0010
// SW modifiable bits
#define WLAN_QUADRATURE_SW_MASK                                      0x000000f7
// bits defined at reset
#define WLAN_QUADRATURE_RSTMASK                                      0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_QUADRATURE_RESET                                        0x00000000

// 32'h0014 (WLAN_PLL_CONTROL)
#define WLAN_PLL_CONTROL_DIG_TEST_CLK_MSB                            20
#define WLAN_PLL_CONTROL_DIG_TEST_CLK_LSB                            20
#define WLAN_PLL_CONTROL_DIG_TEST_CLK_MASK                           0x00100000
#define WLAN_PLL_CONTROL_DIG_TEST_CLK_GET(x)                         (((x) & WLAN_PLL_CONTROL_DIG_TEST_CLK_MASK) >> WLAN_PLL_CONTROL_DIG_TEST_CLK_LSB)
#define WLAN_PLL_CONTROL_DIG_TEST_CLK_SET(x)                         (((x) << WLAN_PLL_CONTROL_DIG_TEST_CLK_LSB) & WLAN_PLL_CONTROL_DIG_TEST_CLK_MASK)
#define WLAN_PLL_CONTROL_DIG_TEST_CLK_RESET                          0x0 // 0
#define WLAN_PLL_CONTROL_MAC_OVERRIDE_MSB                            19
#define WLAN_PLL_CONTROL_MAC_OVERRIDE_LSB                            19
#define WLAN_PLL_CONTROL_MAC_OVERRIDE_MASK                           0x00080000
#define WLAN_PLL_CONTROL_MAC_OVERRIDE_GET(x)                         (((x) & WLAN_PLL_CONTROL_MAC_OVERRIDE_MASK) >> WLAN_PLL_CONTROL_MAC_OVERRIDE_LSB)
#define WLAN_PLL_CONTROL_MAC_OVERRIDE_SET(x)                         (((x) << WLAN_PLL_CONTROL_MAC_OVERRIDE_LSB) & WLAN_PLL_CONTROL_MAC_OVERRIDE_MASK)
#define WLAN_PLL_CONTROL_MAC_OVERRIDE_RESET                          0x0 // 0
#define WLAN_PLL_CONTROL_NOPWD_MSB                                   18
#define WLAN_PLL_CONTROL_NOPWD_LSB                                   18
#define WLAN_PLL_CONTROL_NOPWD_MASK                                  0x00040000
#define WLAN_PLL_CONTROL_NOPWD_GET(x)                                (((x) & WLAN_PLL_CONTROL_NOPWD_MASK) >> WLAN_PLL_CONTROL_NOPWD_LSB)
#define WLAN_PLL_CONTROL_NOPWD_SET(x)                                (((x) << WLAN_PLL_CONTROL_NOPWD_LSB) & WLAN_PLL_CONTROL_NOPWD_MASK)
#define WLAN_PLL_CONTROL_NOPWD_RESET                                 0x0 // 0
#define WLAN_PLL_CONTROL_UPDATING_MSB                                17
#define WLAN_PLL_CONTROL_UPDATING_LSB                                17
#define WLAN_PLL_CONTROL_UPDATING_MASK                               0x00020000
#define WLAN_PLL_CONTROL_UPDATING_GET(x)                             (((x) & WLAN_PLL_CONTROL_UPDATING_MASK) >> WLAN_PLL_CONTROL_UPDATING_LSB)
#define WLAN_PLL_CONTROL_UPDATING_SET(x)                             (((x) << WLAN_PLL_CONTROL_UPDATING_LSB) & WLAN_PLL_CONTROL_UPDATING_MASK)
#define WLAN_PLL_CONTROL_UPDATING_RESET                              0x0 // 0
#define WLAN_PLL_CONTROL_BYPASS_MSB                                  16
#define WLAN_PLL_CONTROL_BYPASS_LSB                                  16
#define WLAN_PLL_CONTROL_BYPASS_MASK                                 0x00010000
#define WLAN_PLL_CONTROL_BYPASS_GET(x)                               (((x) & WLAN_PLL_CONTROL_BYPASS_MASK) >> WLAN_PLL_CONTROL_BYPASS_LSB)
#define WLAN_PLL_CONTROL_BYPASS_SET(x)                               (((x) << WLAN_PLL_CONTROL_BYPASS_LSB) & WLAN_PLL_CONTROL_BYPASS_MASK)
#define WLAN_PLL_CONTROL_BYPASS_RESET                                0x1 // 1
#define WLAN_PLL_CONTROL_CLK_SEL_MSB                                 15
#define WLAN_PLL_CONTROL_CLK_SEL_LSB                                 14
#define WLAN_PLL_CONTROL_CLK_SEL_MASK                                0x0000c000
#define WLAN_PLL_CONTROL_CLK_SEL_GET(x)                              (((x) & WLAN_PLL_CONTROL_CLK_SEL_MASK) >> WLAN_PLL_CONTROL_CLK_SEL_LSB)
#define WLAN_PLL_CONTROL_CLK_SEL_SET(x)                              (((x) << WLAN_PLL_CONTROL_CLK_SEL_LSB) & WLAN_PLL_CONTROL_CLK_SEL_MASK)
#define WLAN_PLL_CONTROL_CLK_SEL_RESET                               0x0 // 0
#define WLAN_PLL_CONTROL_REFDIV_MSB                                  13
#define WLAN_PLL_CONTROL_REFDIV_LSB                                  10
#define WLAN_PLL_CONTROL_REFDIV_MASK                                 0x00003c00
#define WLAN_PLL_CONTROL_REFDIV_GET(x)                               (((x) & WLAN_PLL_CONTROL_REFDIV_MASK) >> WLAN_PLL_CONTROL_REFDIV_LSB)
#define WLAN_PLL_CONTROL_REFDIV_SET(x)                               (((x) << WLAN_PLL_CONTROL_REFDIV_LSB) & WLAN_PLL_CONTROL_REFDIV_MASK)
#define WLAN_PLL_CONTROL_REFDIV_RESET                                0x5 // 5
#define WLAN_PLL_CONTROL_DIV_MSB                                     9
#define WLAN_PLL_CONTROL_DIV_LSB                                     0
#define WLAN_PLL_CONTROL_DIV_MASK                                    0x000003ff
#define WLAN_PLL_CONTROL_DIV_GET(x)                                  (((x) & WLAN_PLL_CONTROL_DIV_MASK) >> WLAN_PLL_CONTROL_DIV_LSB)
#define WLAN_PLL_CONTROL_DIV_SET(x)                                  (((x) << WLAN_PLL_CONTROL_DIV_LSB) & WLAN_PLL_CONTROL_DIV_MASK)
#define WLAN_PLL_CONTROL_DIV_RESET                                   0x58 // 88
#define WLAN_PLL_CONTROL_ADDRESS                                     0x0014
#define WLAN_PLL_CONTROL_OFFSET                                      0x0014
// SW modifiable bits
#define WLAN_PLL_CONTROL_SW_MASK                                     0x001fffff
// bits defined at reset
#define WLAN_PLL_CONTROL_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_PLL_CONTROL_RESET                                       0x00011458

// 32'h0018 (WLAN_PLL_SETTLE)
#define WLAN_PLL_SETTLE_TIME_MSB                                     10
#define WLAN_PLL_SETTLE_TIME_LSB                                     0
#define WLAN_PLL_SETTLE_TIME_MASK                                    0x000007ff
#define WLAN_PLL_SETTLE_TIME_GET(x)                                  (((x) & WLAN_PLL_SETTLE_TIME_MASK) >> WLAN_PLL_SETTLE_TIME_LSB)
#define WLAN_PLL_SETTLE_TIME_SET(x)                                  (((x) << WLAN_PLL_SETTLE_TIME_LSB) & WLAN_PLL_SETTLE_TIME_MASK)
#define WLAN_PLL_SETTLE_TIME_RESET                                   0x400 // 1024
#define WLAN_PLL_SETTLE_ADDRESS                                      0x0018
#define WLAN_PLL_SETTLE_OFFSET                                       0x0018
// SW modifiable bits
#define WLAN_PLL_SETTLE_SW_MASK                                      0x000007ff
// bits defined at reset
#define WLAN_PLL_SETTLE_RSTMASK                                      0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_PLL_SETTLE_RESET                                        0x00000400

// 32'h001c (WLAN_XTAL_SETTLE)
#define WLAN_XTAL_SETTLE_TIME_MSB                                    9
#define WLAN_XTAL_SETTLE_TIME_LSB                                    0
#define WLAN_XTAL_SETTLE_TIME_MASK                                   0x000003ff
#define WLAN_XTAL_SETTLE_TIME_GET(x)                                 (((x) & WLAN_XTAL_SETTLE_TIME_MASK) >> WLAN_XTAL_SETTLE_TIME_LSB)
#define WLAN_XTAL_SETTLE_TIME_SET(x)                                 (((x) << WLAN_XTAL_SETTLE_TIME_LSB) & WLAN_XTAL_SETTLE_TIME_MASK)
#define WLAN_XTAL_SETTLE_TIME_RESET                                  0x210 // 528
#define WLAN_XTAL_SETTLE_ADDRESS                                     0x001c
#define WLAN_XTAL_SETTLE_OFFSET                                      0x001c
// SW modifiable bits
#define WLAN_XTAL_SETTLE_SW_MASK                                     0x000003ff
// bits defined at reset
#define WLAN_XTAL_SETTLE_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_XTAL_SETTLE_RESET                                       0x00000210

// 32'h0020 (WLAN_CLOCK_OUT)
#define WLAN_CLOCK_OUT_DELAY_MSB                                     6
#define WLAN_CLOCK_OUT_DELAY_LSB                                     4
#define WLAN_CLOCK_OUT_DELAY_MASK                                    0x00000070
#define WLAN_CLOCK_OUT_DELAY_GET(x)                                  (((x) & WLAN_CLOCK_OUT_DELAY_MASK) >> WLAN_CLOCK_OUT_DELAY_LSB)
#define WLAN_CLOCK_OUT_DELAY_SET(x)                                  (((x) << WLAN_CLOCK_OUT_DELAY_LSB) & WLAN_CLOCK_OUT_DELAY_MASK)
#define WLAN_CLOCK_OUT_DELAY_RESET                                   0x0 // 0
#define WLAN_CLOCK_OUT_SELECT_MSB                                    3
#define WLAN_CLOCK_OUT_SELECT_LSB                                    0
#define WLAN_CLOCK_OUT_SELECT_MASK                                   0x0000000f
#define WLAN_CLOCK_OUT_SELECT_GET(x)                                 (((x) & WLAN_CLOCK_OUT_SELECT_MASK) >> WLAN_CLOCK_OUT_SELECT_LSB)
#define WLAN_CLOCK_OUT_SELECT_SET(x)                                 (((x) << WLAN_CLOCK_OUT_SELECT_LSB) & WLAN_CLOCK_OUT_SELECT_MASK)
#define WLAN_CLOCK_OUT_SELECT_RESET                                  0x0 // 0
#define WLAN_CLOCK_OUT_ADDRESS                                       0x0020
#define WLAN_CLOCK_OUT_OFFSET                                        0x0020
// SW modifiable bits
#define WLAN_CLOCK_OUT_SW_MASK                                       0x0000007f
// bits defined at reset
#define WLAN_CLOCK_OUT_RSTMASK                                       0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_CLOCK_OUT_RESET                                         0x00000000

// 32'h0024 (WLAN_BIAS_OVERRIDE)
#define WLAN_BIAS_OVERRIDE_ON_MSB                                    0
#define WLAN_BIAS_OVERRIDE_ON_LSB                                    0
#define WLAN_BIAS_OVERRIDE_ON_MASK                                   0x00000001
#define WLAN_BIAS_OVERRIDE_ON_GET(x)                                 (((x) & WLAN_BIAS_OVERRIDE_ON_MASK) >> WLAN_BIAS_OVERRIDE_ON_LSB)
#define WLAN_BIAS_OVERRIDE_ON_SET(x)                                 (((x) << WLAN_BIAS_OVERRIDE_ON_LSB) & WLAN_BIAS_OVERRIDE_ON_MASK)
#define WLAN_BIAS_OVERRIDE_ON_RESET                                  0x0 // 0
#define WLAN_BIAS_OVERRIDE_ADDRESS                                   0x0024
#define WLAN_BIAS_OVERRIDE_OFFSET                                    0x0024
// SW modifiable bits
#define WLAN_BIAS_OVERRIDE_SW_MASK                                   0x00000001
// bits defined at reset
#define WLAN_BIAS_OVERRIDE_RSTMASK                                   0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_BIAS_OVERRIDE_RESET                                     0x00000000

// 32'h0028 (WLAN_RESET_CAUSE)
#define WLAN_RESET_CAUSE_LAST_MSB                                    2
#define WLAN_RESET_CAUSE_LAST_LSB                                    0
#define WLAN_RESET_CAUSE_LAST_MASK                                   0x00000007
#define WLAN_RESET_CAUSE_LAST_GET(x)                                 (((x) & WLAN_RESET_CAUSE_LAST_MASK) >> WLAN_RESET_CAUSE_LAST_LSB)
#define WLAN_RESET_CAUSE_LAST_SET(x)                                 (((x) << WLAN_RESET_CAUSE_LAST_LSB) & WLAN_RESET_CAUSE_LAST_MASK)
#define WLAN_RESET_CAUSE_LAST_RESET                                  0x0 // 0
#define WLAN_RESET_CAUSE_ADDRESS                                     0x0028
#define WLAN_RESET_CAUSE_OFFSET                                      0x0028
// SW modifiable bits
#define WLAN_RESET_CAUSE_SW_MASK                                     0x00000007
// bits defined at reset
#define WLAN_RESET_CAUSE_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_RESET_CAUSE_RESET                                       0x00000000

// 32'h002c (WLAN_SYSTEM_SLEEP)
#define WLAN_SYSTEM_SLEEP_MAC_IF_MSB                                 2
#define WLAN_SYSTEM_SLEEP_MAC_IF_LSB                                 2
#define WLAN_SYSTEM_SLEEP_MAC_IF_MASK                                0x00000004
#define WLAN_SYSTEM_SLEEP_MAC_IF_GET(x)                              (((x) & WLAN_SYSTEM_SLEEP_MAC_IF_MASK) >> WLAN_SYSTEM_SLEEP_MAC_IF_LSB)
#define WLAN_SYSTEM_SLEEP_MAC_IF_SET(x)                              (((x) << WLAN_SYSTEM_SLEEP_MAC_IF_LSB) & WLAN_SYSTEM_SLEEP_MAC_IF_MASK)
#define WLAN_SYSTEM_SLEEP_MAC_IF_RESET                               0x1 // 1
#define WLAN_SYSTEM_SLEEP_LIGHT_MSB                                  1
#define WLAN_SYSTEM_SLEEP_LIGHT_LSB                                  1
#define WLAN_SYSTEM_SLEEP_LIGHT_MASK                                 0x00000002
#define WLAN_SYSTEM_SLEEP_LIGHT_GET(x)                               (((x) & WLAN_SYSTEM_SLEEP_LIGHT_MASK) >> WLAN_SYSTEM_SLEEP_LIGHT_LSB)
#define WLAN_SYSTEM_SLEEP_LIGHT_SET(x)                               (((x) << WLAN_SYSTEM_SLEEP_LIGHT_LSB) & WLAN_SYSTEM_SLEEP_LIGHT_MASK)
#define WLAN_SYSTEM_SLEEP_LIGHT_RESET                                0x0 // 0
#define WLAN_SYSTEM_SLEEP_DISABLE_MSB                                0
#define WLAN_SYSTEM_SLEEP_DISABLE_LSB                                0
#define WLAN_SYSTEM_SLEEP_DISABLE_MASK                               0x00000001
#define WLAN_SYSTEM_SLEEP_DISABLE_GET(x)                             (((x) & WLAN_SYSTEM_SLEEP_DISABLE_MASK) >> WLAN_SYSTEM_SLEEP_DISABLE_LSB)
#define WLAN_SYSTEM_SLEEP_DISABLE_SET(x)                             (((x) << WLAN_SYSTEM_SLEEP_DISABLE_LSB) & WLAN_SYSTEM_SLEEP_DISABLE_MASK)
#define WLAN_SYSTEM_SLEEP_DISABLE_RESET                              0x1 // 1
#define WLAN_SYSTEM_SLEEP_ADDRESS                                    0x002c
#define WLAN_SYSTEM_SLEEP_OFFSET                                     0x002c
// SW modifiable bits
#define WLAN_SYSTEM_SLEEP_SW_MASK                                    0x00000007
// bits defined at reset
#define WLAN_SYSTEM_SLEEP_RSTMASK                                    0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_SYSTEM_SLEEP_RESET                                      0x00000005

// 32'h0030 (WLAN_MAC_SLEEP_CONTROL)
#define WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_MSB                  2
#define WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_LSB                  2
#define WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_MASK                 0x00000004
#define WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_GET(x)               (((x) & WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_MASK) >> WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_LSB)
#define WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_SET(x)               (((x) << WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_LSB) & WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_MASK)
#define WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_RESET                0x1 // 1
#define WLAN_MAC_SLEEP_CONTROL_RESERVED_MSB                          1
#define WLAN_MAC_SLEEP_CONTROL_RESERVED_LSB                          1
#define WLAN_MAC_SLEEP_CONTROL_RESERVED_MASK                         0x00000002
#define WLAN_MAC_SLEEP_CONTROL_RESERVED_GET(x)                       (((x) & WLAN_MAC_SLEEP_CONTROL_RESERVED_MASK) >> WLAN_MAC_SLEEP_CONTROL_RESERVED_LSB)
#define WLAN_MAC_SLEEP_CONTROL_RESERVED_SET(x)                       (((x) << WLAN_MAC_SLEEP_CONTROL_RESERVED_LSB) & WLAN_MAC_SLEEP_CONTROL_RESERVED_MASK)
#define WLAN_MAC_SLEEP_CONTROL_RESERVED_RESET                        0x0 // 0
#define WLAN_MAC_SLEEP_CONTROL_ENABLE_MSB                            0
#define WLAN_MAC_SLEEP_CONTROL_ENABLE_LSB                            0
#define WLAN_MAC_SLEEP_CONTROL_ENABLE_MASK                           0x00000001
#define WLAN_MAC_SLEEP_CONTROL_ENABLE_GET(x)                         (((x) & WLAN_MAC_SLEEP_CONTROL_ENABLE_MASK) >> WLAN_MAC_SLEEP_CONTROL_ENABLE_LSB)
#define WLAN_MAC_SLEEP_CONTROL_ENABLE_SET(x)                         (((x) << WLAN_MAC_SLEEP_CONTROL_ENABLE_LSB) & WLAN_MAC_SLEEP_CONTROL_ENABLE_MASK)
#define WLAN_MAC_SLEEP_CONTROL_ENABLE_RESET                          0x0 // 0
#define WLAN_MAC_SLEEP_CONTROL_ADDRESS                               0x0030
#define WLAN_MAC_SLEEP_CONTROL_OFFSET                                0x0030
// SW modifiable bits
#define WLAN_MAC_SLEEP_CONTROL_SW_MASK                               0x00000007
// bits defined at reset
#define WLAN_MAC_SLEEP_CONTROL_RSTMASK                               0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_MAC_SLEEP_CONTROL_RESET                                 0x00000004

// 32'h0034 (WLAN_KEEP_AWAKE)
#define WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_MSB                        15
#define WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_LSB                        8
#define WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_MASK                       0x0000ff00
#define WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_GET(x)                     (((x) & WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_MASK) >> WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_LSB)
#define WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_SET(x)                     (((x) << WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_LSB) & WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_MASK)
#define WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_RESET                      0x3 // 3
#define WLAN_KEEP_AWAKE_COUNT_MSB                                    7
#define WLAN_KEEP_AWAKE_COUNT_LSB                                    0
#define WLAN_KEEP_AWAKE_COUNT_MASK                                   0x000000ff
#define WLAN_KEEP_AWAKE_COUNT_GET(x)                                 (((x) & WLAN_KEEP_AWAKE_COUNT_MASK) >> WLAN_KEEP_AWAKE_COUNT_LSB)
#define WLAN_KEEP_AWAKE_COUNT_SET(x)                                 (((x) << WLAN_KEEP_AWAKE_COUNT_LSB) & WLAN_KEEP_AWAKE_COUNT_MASK)
#define WLAN_KEEP_AWAKE_COUNT_RESET                                  0x3 // 3
#define WLAN_KEEP_AWAKE_ADDRESS                                      0x0034
#define WLAN_KEEP_AWAKE_OFFSET                                       0x0034
// SW modifiable bits
#define WLAN_KEEP_AWAKE_SW_MASK                                      0x0000ffff
// bits defined at reset
#define WLAN_KEEP_AWAKE_RSTMASK                                      0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_KEEP_AWAKE_RESET                                        0x00000303

// 32'h0038 (WLAN_DERIVED_RTC_CLK)
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_MSB                  20
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_LSB                  20
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_MASK                 0x00100000
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_GET(x)               (((x) & WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_MASK) >> WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_LSB)
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_SET(x)               (((x) << WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_LSB) & WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_MASK)
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_RESET                0x1 // 1
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_MSB                     18
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_LSB                     18
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_MASK                    0x00040000
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_GET(x)                  (((x) & WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_MASK) >> WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_LSB)
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_SET(x)                  (((x) << WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_LSB) & WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_MASK)
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_RESET                   0x0 // 0
#define WLAN_DERIVED_RTC_CLK_PERIOD_MSB                              15
#define WLAN_DERIVED_RTC_CLK_PERIOD_LSB                              1
#define WLAN_DERIVED_RTC_CLK_PERIOD_MASK                             0x0000fffe
#define WLAN_DERIVED_RTC_CLK_PERIOD_GET(x)                           (((x) & WLAN_DERIVED_RTC_CLK_PERIOD_MASK) >> WLAN_DERIVED_RTC_CLK_PERIOD_LSB)
#define WLAN_DERIVED_RTC_CLK_PERIOD_SET(x)                           (((x) << WLAN_DERIVED_RTC_CLK_PERIOD_LSB) & WLAN_DERIVED_RTC_CLK_PERIOD_MASK)
#define WLAN_DERIVED_RTC_CLK_PERIOD_RESET                            0x262 // 610
#define WLAN_DERIVED_RTC_CLK_ADDRESS                                 0x0038
#define WLAN_DERIVED_RTC_CLK_OFFSET                                  0x0038
// SW modifiable bits
#define WLAN_DERIVED_RTC_CLK_SW_MASK                                 0x0014fffe
// bits defined at reset
#define WLAN_DERIVED_RTC_CLK_RSTMASK                                 0xfffbffff
// reset value (ignore bits undefined at reset)
#define WLAN_DERIVED_RTC_CLK_RESET                                   0x001004c4

// 32'h003c (MAC_PCU_SLP32_MODE)
#define MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_MSB                     24
#define MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_LSB                     24
#define MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_MASK                    0x01000000
#define MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_GET(x)                  (((x) & MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_MASK) >> MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_LSB)
#define MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_SET(x)                  (((x) << MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_LSB) & MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_MASK)
#define MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_RESET                   0x1 // 1
#define MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_MSB                   23
#define MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_LSB                   23
#define MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_MASK                  0x00800000
#define MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_GET(x)                (((x) & MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_MASK) >> MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_LSB)
#define MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_SET(x)                (((x) << MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_LSB) & MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_MASK)
#define MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_RESET                 0x0 // 0
#define MAC_PCU_SLP32_MODE_DISABLE_32KHZ_MSB                         22
#define MAC_PCU_SLP32_MODE_DISABLE_32KHZ_LSB                         22
#define MAC_PCU_SLP32_MODE_DISABLE_32KHZ_MASK                        0x00400000
#define MAC_PCU_SLP32_MODE_DISABLE_32KHZ_GET(x)                      (((x) & MAC_PCU_SLP32_MODE_DISABLE_32KHZ_MASK) >> MAC_PCU_SLP32_MODE_DISABLE_32KHZ_LSB)
#define MAC_PCU_SLP32_MODE_DISABLE_32KHZ_SET(x)                      (((x) << MAC_PCU_SLP32_MODE_DISABLE_32KHZ_LSB) & MAC_PCU_SLP32_MODE_DISABLE_32KHZ_MASK)
#define MAC_PCU_SLP32_MODE_DISABLE_32KHZ_RESET                       0x0 // 0
#define MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_MSB                      21
#define MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_LSB                      21
#define MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_MASK                     0x00200000
#define MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_GET(x)                   (((x) & MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_MASK) >> MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_LSB)
#define MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_SET(x)                   (((x) << MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_LSB) & MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_MASK)
#define MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_RESET                    0x1 // 1
#define MAC_PCU_SLP32_MODE_ENABLE_MSB                                20
#define MAC_PCU_SLP32_MODE_ENABLE_LSB                                20
#define MAC_PCU_SLP32_MODE_ENABLE_MASK                               0x00100000
#define MAC_PCU_SLP32_MODE_ENABLE_GET(x)                             (((x) & MAC_PCU_SLP32_MODE_ENABLE_MASK) >> MAC_PCU_SLP32_MODE_ENABLE_LSB)
#define MAC_PCU_SLP32_MODE_ENABLE_SET(x)                             (((x) << MAC_PCU_SLP32_MODE_ENABLE_LSB) & MAC_PCU_SLP32_MODE_ENABLE_MASK)
#define MAC_PCU_SLP32_MODE_ENABLE_RESET                              0x1 // 1
#define MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_MSB                      19
#define MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_LSB                      0
#define MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_MASK                     0x000fffff
#define MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_GET(x)                   (((x) & MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_MASK) >> MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_LSB)
#define MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_SET(x)                   (((x) << MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_LSB) & MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_MASK)
#define MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_RESET                    0xf424 // 62500
#define MAC_PCU_SLP32_MODE_ADDRESS                                   0x003c
#define MAC_PCU_SLP32_MODE_OFFSET                                    0x003c
// SW modifiable bits
#define MAC_PCU_SLP32_MODE_SW_MASK                                   0x01ffffff
// bits defined at reset
#define MAC_PCU_SLP32_MODE_RSTMASK                                   0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_SLP32_MODE_RESET                                     0x0130f424

// 32'h0040 (MAC_PCU_SLP32_WAKE)
#define MAC_PCU_SLP32_WAKE_XTL_TIME_MSB                              15
#define MAC_PCU_SLP32_WAKE_XTL_TIME_LSB                              0
#define MAC_PCU_SLP32_WAKE_XTL_TIME_MASK                             0x0000ffff
#define MAC_PCU_SLP32_WAKE_XTL_TIME_GET(x)                           (((x) & MAC_PCU_SLP32_WAKE_XTL_TIME_MASK) >> MAC_PCU_SLP32_WAKE_XTL_TIME_LSB)
#define MAC_PCU_SLP32_WAKE_XTL_TIME_SET(x)                           (((x) << MAC_PCU_SLP32_WAKE_XTL_TIME_LSB) & MAC_PCU_SLP32_WAKE_XTL_TIME_MASK)
#define MAC_PCU_SLP32_WAKE_XTL_TIME_RESET                            0x800 // 2048
#define MAC_PCU_SLP32_WAKE_ADDRESS                                   0x0040
#define MAC_PCU_SLP32_WAKE_OFFSET                                    0x0040
// SW modifiable bits
#define MAC_PCU_SLP32_WAKE_SW_MASK                                   0x0000ffff
// bits defined at reset
#define MAC_PCU_SLP32_WAKE_RSTMASK                                   0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_SLP32_WAKE_RESET                                     0x00000800

// 32'h0044 (MAC_PCU_SLP32_INC)
#define MAC_PCU_SLP32_INC_TSF_INC_MSB                                19
#define MAC_PCU_SLP32_INC_TSF_INC_LSB                                0
#define MAC_PCU_SLP32_INC_TSF_INC_MASK                               0x000fffff
#define MAC_PCU_SLP32_INC_TSF_INC_GET(x)                             (((x) & MAC_PCU_SLP32_INC_TSF_INC_MASK) >> MAC_PCU_SLP32_INC_TSF_INC_LSB)
#define MAC_PCU_SLP32_INC_TSF_INC_SET(x)                             (((x) << MAC_PCU_SLP32_INC_TSF_INC_LSB) & MAC_PCU_SLP32_INC_TSF_INC_MASK)
#define MAC_PCU_SLP32_INC_TSF_INC_RESET                              0x1e848 // 125000
#define MAC_PCU_SLP32_INC_ADDRESS                                    0x0044
#define MAC_PCU_SLP32_INC_OFFSET                                     0x0044
// SW modifiable bits
#define MAC_PCU_SLP32_INC_SW_MASK                                    0x000fffff
// bits defined at reset
#define MAC_PCU_SLP32_INC_RSTMASK                                    0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_SLP32_INC_RESET                                      0x0001e848

// 32'h0048 (MAC_PCU_SLP_MIB1)
#define MAC_PCU_SLP_MIB1_SLEEP_CNT_MSB                               31
#define MAC_PCU_SLP_MIB1_SLEEP_CNT_LSB                               0
#define MAC_PCU_SLP_MIB1_SLEEP_CNT_MASK                              0xffffffff
#define MAC_PCU_SLP_MIB1_SLEEP_CNT_GET(x)                            (((x) & MAC_PCU_SLP_MIB1_SLEEP_CNT_MASK) >> MAC_PCU_SLP_MIB1_SLEEP_CNT_LSB)
#define MAC_PCU_SLP_MIB1_SLEEP_CNT_SET(x)                            (((x) << MAC_PCU_SLP_MIB1_SLEEP_CNT_LSB) & MAC_PCU_SLP_MIB1_SLEEP_CNT_MASK)
#define MAC_PCU_SLP_MIB1_SLEEP_CNT_RESET                             0x0 // 0
#define MAC_PCU_SLP_MIB1_ADDRESS                                     0x0048
#define MAC_PCU_SLP_MIB1_OFFSET                                      0x0048
// SW modifiable bits
#define MAC_PCU_SLP_MIB1_SW_MASK                                     0xffffffff
// bits defined at reset
#define MAC_PCU_SLP_MIB1_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_SLP_MIB1_RESET                                       0x00000000

// 32'h004c (MAC_PCU_SLP_MIB2)
#define MAC_PCU_SLP_MIB2_CYCLE_CNT_MSB                               31
#define MAC_PCU_SLP_MIB2_CYCLE_CNT_LSB                               0
#define MAC_PCU_SLP_MIB2_CYCLE_CNT_MASK                              0xffffffff
#define MAC_PCU_SLP_MIB2_CYCLE_CNT_GET(x)                            (((x) & MAC_PCU_SLP_MIB2_CYCLE_CNT_MASK) >> MAC_PCU_SLP_MIB2_CYCLE_CNT_LSB)
#define MAC_PCU_SLP_MIB2_CYCLE_CNT_SET(x)                            (((x) << MAC_PCU_SLP_MIB2_CYCLE_CNT_LSB) & MAC_PCU_SLP_MIB2_CYCLE_CNT_MASK)
#define MAC_PCU_SLP_MIB2_CYCLE_CNT_RESET                             0x0 // 0
#define MAC_PCU_SLP_MIB2_ADDRESS                                     0x004c
#define MAC_PCU_SLP_MIB2_OFFSET                                      0x004c
// SW modifiable bits
#define MAC_PCU_SLP_MIB2_SW_MASK                                     0xffffffff
// bits defined at reset
#define MAC_PCU_SLP_MIB2_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_SLP_MIB2_RESET                                       0x00000000

// 32'h0050 (MAC_PCU_SLP_MIB3)
#define MAC_PCU_SLP_MIB3_PENDING_MSB                                 1
#define MAC_PCU_SLP_MIB3_PENDING_LSB                                 1
#define MAC_PCU_SLP_MIB3_PENDING_MASK                                0x00000002
#define MAC_PCU_SLP_MIB3_PENDING_GET(x)                              (((x) & MAC_PCU_SLP_MIB3_PENDING_MASK) >> MAC_PCU_SLP_MIB3_PENDING_LSB)
#define MAC_PCU_SLP_MIB3_PENDING_SET(x)                              (((x) << MAC_PCU_SLP_MIB3_PENDING_LSB) & MAC_PCU_SLP_MIB3_PENDING_MASK)
#define MAC_PCU_SLP_MIB3_PENDING_RESET                               0x0 // 0
#define MAC_PCU_SLP_MIB3_CLR_CNT_MSB                                 0
#define MAC_PCU_SLP_MIB3_CLR_CNT_LSB                                 0
#define MAC_PCU_SLP_MIB3_CLR_CNT_MASK                                0x00000001
#define MAC_PCU_SLP_MIB3_CLR_CNT_GET(x)                              (((x) & MAC_PCU_SLP_MIB3_CLR_CNT_MASK) >> MAC_PCU_SLP_MIB3_CLR_CNT_LSB)
#define MAC_PCU_SLP_MIB3_CLR_CNT_SET(x)                              (((x) << MAC_PCU_SLP_MIB3_CLR_CNT_LSB) & MAC_PCU_SLP_MIB3_CLR_CNT_MASK)
#define MAC_PCU_SLP_MIB3_CLR_CNT_RESET                               0x0 // 0
#define MAC_PCU_SLP_MIB3_ADDRESS                                     0x0050
#define MAC_PCU_SLP_MIB3_OFFSET                                      0x0050
// SW modifiable bits
#define MAC_PCU_SLP_MIB3_SW_MASK                                     0x00000003
// bits defined at reset
#define MAC_PCU_SLP_MIB3_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_SLP_MIB3_RESET                                       0x00000000

// 32'h0054 (MAC_PCU_TSF_L32)
#define MAC_PCU_TSF_L32_VALUE_MSB                                    31
#define MAC_PCU_TSF_L32_VALUE_LSB                                    0
#define MAC_PCU_TSF_L32_VALUE_MASK                                   0xffffffff
#define MAC_PCU_TSF_L32_VALUE_GET(x)                                 (((x) & MAC_PCU_TSF_L32_VALUE_MASK) >> MAC_PCU_TSF_L32_VALUE_LSB)
#define MAC_PCU_TSF_L32_VALUE_SET(x)                                 (((x) << MAC_PCU_TSF_L32_VALUE_LSB) & MAC_PCU_TSF_L32_VALUE_MASK)
#define MAC_PCU_TSF_L32_VALUE_RESET                                  0xfffffff // 268435455
#define MAC_PCU_TSF_L32_ADDRESS                                      0x0054
#define MAC_PCU_TSF_L32_OFFSET                                       0x0054
// SW modifiable bits
#define MAC_PCU_TSF_L32_SW_MASK                                      0xffffffff
// bits defined at reset
#define MAC_PCU_TSF_L32_RSTMASK                                      0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_TSF_L32_RESET                                        0x0fffffff

// 32'h0058 (MAC_PCU_TSF_U32)
#define MAC_PCU_TSF_U32_VALUE_MSB                                    31
#define MAC_PCU_TSF_U32_VALUE_LSB                                    0
#define MAC_PCU_TSF_U32_VALUE_MASK                                   0xffffffff
#define MAC_PCU_TSF_U32_VALUE_GET(x)                                 (((x) & MAC_PCU_TSF_U32_VALUE_MASK) >> MAC_PCU_TSF_U32_VALUE_LSB)
#define MAC_PCU_TSF_U32_VALUE_SET(x)                                 (((x) << MAC_PCU_TSF_U32_VALUE_LSB) & MAC_PCU_TSF_U32_VALUE_MASK)
#define MAC_PCU_TSF_U32_VALUE_RESET                                  0xfffffff // 268435455
#define MAC_PCU_TSF_U32_ADDRESS                                      0x0058
#define MAC_PCU_TSF_U32_OFFSET                                       0x0058
// SW modifiable bits
#define MAC_PCU_TSF_U32_SW_MASK                                      0xffffffff
// bits defined at reset
#define MAC_PCU_TSF_U32_RSTMASK                                      0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_TSF_U32_RESET                                        0x0fffffff

// 32'h005c (MAC_PCU_WBTIMER_0)
#define MAC_PCU_WBTIMER_0_ENABLE_MSB                                 0
#define MAC_PCU_WBTIMER_0_ENABLE_LSB                                 0
#define MAC_PCU_WBTIMER_0_ENABLE_MASK                                0x00000001
#define MAC_PCU_WBTIMER_0_ENABLE_GET(x)                              (((x) & MAC_PCU_WBTIMER_0_ENABLE_MASK) >> MAC_PCU_WBTIMER_0_ENABLE_LSB)
#define MAC_PCU_WBTIMER_0_ENABLE_SET(x)                              (((x) << MAC_PCU_WBTIMER_0_ENABLE_LSB) & MAC_PCU_WBTIMER_0_ENABLE_MASK)
#define MAC_PCU_WBTIMER_0_ENABLE_RESET                               0x0 // 0
#define MAC_PCU_WBTIMER_0_ADDRESS                                    0x005c
#define MAC_PCU_WBTIMER_0_OFFSET                                     0x005c
// SW modifiable bits
#define MAC_PCU_WBTIMER_0_SW_MASK                                    0x00000001
// bits defined at reset
#define MAC_PCU_WBTIMER_0_RSTMASK                                    0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_WBTIMER_0_RESET                                      0x00000000

// 32'h0060 (MAC_PCU_WBTIMER_1)
#define MAC_PCU_WBTIMER_1_VALUE_MSB                                  31
#define MAC_PCU_WBTIMER_1_VALUE_LSB                                  0
#define MAC_PCU_WBTIMER_1_VALUE_MASK                                 0xffffffff
#define MAC_PCU_WBTIMER_1_VALUE_GET(x)                               (((x) & MAC_PCU_WBTIMER_1_VALUE_MASK) >> MAC_PCU_WBTIMER_1_VALUE_LSB)
#define MAC_PCU_WBTIMER_1_VALUE_SET(x)                               (((x) << MAC_PCU_WBTIMER_1_VALUE_LSB) & MAC_PCU_WBTIMER_1_VALUE_MASK)
#define MAC_PCU_WBTIMER_1_VALUE_RESET                                0x0 // 0
#define MAC_PCU_WBTIMER_1_ADDRESS                                    0x0060
#define MAC_PCU_WBTIMER_1_OFFSET                                     0x0060
// SW modifiable bits
#define MAC_PCU_WBTIMER_1_SW_MASK                                    0xffffffff
// bits defined at reset
#define MAC_PCU_WBTIMER_1_RSTMASK                                    0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_WBTIMER_1_RESET                                      0x00000000

// 32'h0064 (MAC_PCU_GENERIC_TIMERS_0)
#define MAC_PCU_GENERIC_TIMERS_0_DATA_MSB                            31
#define MAC_PCU_GENERIC_TIMERS_0_DATA_LSB                            0
#define MAC_PCU_GENERIC_TIMERS_0_DATA_MASK                           0xffffffff
#define MAC_PCU_GENERIC_TIMERS_0_DATA_GET(x)                         (((x) & MAC_PCU_GENERIC_TIMERS_0_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_0_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_0_DATA_SET(x)                         (((x) << MAC_PCU_GENERIC_TIMERS_0_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_0_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_0_DATA_RESET                          0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_0_ADDRESS                             0x0064
#define MAC_PCU_GENERIC_TIMERS_0_OFFSET                              0x0064
#define MAC_PCU_GENERIC_TIMERS_ADDRESS                               MAC_PCU_GENERIC_TIMERS_0_ADDRESS
#define MAC_PCU_GENERIC_TIMERS_OFFSET                                MAC_PCU_GENERIC_TIMERS_0_OFFSET
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_0_SW_MASK                             0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_0_RSTMASK                             0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_0_RESET                               0x00000000

// 32'h0068 (MAC_PCU_GENERIC_TIMERS_1)
#define MAC_PCU_GENERIC_TIMERS_1_DATA_MSB                            31
#define MAC_PCU_GENERIC_TIMERS_1_DATA_LSB                            0
#define MAC_PCU_GENERIC_TIMERS_1_DATA_MASK                           0xffffffff
#define MAC_PCU_GENERIC_TIMERS_1_DATA_GET(x)                         (((x) & MAC_PCU_GENERIC_TIMERS_1_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_1_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_1_DATA_SET(x)                         (((x) << MAC_PCU_GENERIC_TIMERS_1_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_1_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_1_DATA_RESET                          0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_1_ADDRESS                             0x0068
#define MAC_PCU_GENERIC_TIMERS_1_OFFSET                              0x0068
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_1_SW_MASK                             0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_1_RSTMASK                             0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_1_RESET                               0x00000000

// 32'h006c (MAC_PCU_GENERIC_TIMERS_2)
#define MAC_PCU_GENERIC_TIMERS_2_DATA_MSB                            31
#define MAC_PCU_GENERIC_TIMERS_2_DATA_LSB                            0
#define MAC_PCU_GENERIC_TIMERS_2_DATA_MASK                           0xffffffff
#define MAC_PCU_GENERIC_TIMERS_2_DATA_GET(x)                         (((x) & MAC_PCU_GENERIC_TIMERS_2_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_2_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_2_DATA_SET(x)                         (((x) << MAC_PCU_GENERIC_TIMERS_2_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_2_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_2_DATA_RESET                          0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_2_ADDRESS                             0x006c
#define MAC_PCU_GENERIC_TIMERS_2_OFFSET                              0x006c
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_2_SW_MASK                             0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_2_RSTMASK                             0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_2_RESET                               0x00000000

// 32'h0070 (MAC_PCU_GENERIC_TIMERS_3)
#define MAC_PCU_GENERIC_TIMERS_3_DATA_MSB                            31
#define MAC_PCU_GENERIC_TIMERS_3_DATA_LSB                            0
#define MAC_PCU_GENERIC_TIMERS_3_DATA_MASK                           0xffffffff
#define MAC_PCU_GENERIC_TIMERS_3_DATA_GET(x)                         (((x) & MAC_PCU_GENERIC_TIMERS_3_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_3_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_3_DATA_SET(x)                         (((x) << MAC_PCU_GENERIC_TIMERS_3_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_3_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_3_DATA_RESET                          0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_3_ADDRESS                             0x0070
#define MAC_PCU_GENERIC_TIMERS_3_OFFSET                              0x0070
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_3_SW_MASK                             0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_3_RSTMASK                             0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_3_RESET                               0x00000000

// 32'h0074 (MAC_PCU_GENERIC_TIMERS_4)
#define MAC_PCU_GENERIC_TIMERS_4_DATA_MSB                            31
#define MAC_PCU_GENERIC_TIMERS_4_DATA_LSB                            0
#define MAC_PCU_GENERIC_TIMERS_4_DATA_MASK                           0xffffffff
#define MAC_PCU_GENERIC_TIMERS_4_DATA_GET(x)                         (((x) & MAC_PCU_GENERIC_TIMERS_4_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_4_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_4_DATA_SET(x)                         (((x) << MAC_PCU_GENERIC_TIMERS_4_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_4_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_4_DATA_RESET                          0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_4_ADDRESS                             0x0074
#define MAC_PCU_GENERIC_TIMERS_4_OFFSET                              0x0074
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_4_SW_MASK                             0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_4_RSTMASK                             0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_4_RESET                               0x00000000

// 32'h0078 (MAC_PCU_GENERIC_TIMERS_5)
#define MAC_PCU_GENERIC_TIMERS_5_DATA_MSB                            31
#define MAC_PCU_GENERIC_TIMERS_5_DATA_LSB                            0
#define MAC_PCU_GENERIC_TIMERS_5_DATA_MASK                           0xffffffff
#define MAC_PCU_GENERIC_TIMERS_5_DATA_GET(x)                         (((x) & MAC_PCU_GENERIC_TIMERS_5_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_5_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_5_DATA_SET(x)                         (((x) << MAC_PCU_GENERIC_TIMERS_5_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_5_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_5_DATA_RESET                          0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_5_ADDRESS                             0x0078
#define MAC_PCU_GENERIC_TIMERS_5_OFFSET                              0x0078
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_5_SW_MASK                             0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_5_RSTMASK                             0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_5_RESET                               0x00000000

// 32'h007c (MAC_PCU_GENERIC_TIMERS_6)
#define MAC_PCU_GENERIC_TIMERS_6_DATA_MSB                            31
#define MAC_PCU_GENERIC_TIMERS_6_DATA_LSB                            0
#define MAC_PCU_GENERIC_TIMERS_6_DATA_MASK                           0xffffffff
#define MAC_PCU_GENERIC_TIMERS_6_DATA_GET(x)                         (((x) & MAC_PCU_GENERIC_TIMERS_6_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_6_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_6_DATA_SET(x)                         (((x) << MAC_PCU_GENERIC_TIMERS_6_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_6_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_6_DATA_RESET                          0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_6_ADDRESS                             0x007c
#define MAC_PCU_GENERIC_TIMERS_6_OFFSET                              0x007c
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_6_SW_MASK                             0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_6_RSTMASK                             0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_6_RESET                               0x00000000

// 32'h0080 (MAC_PCU_GENERIC_TIMERS_7)
#define MAC_PCU_GENERIC_TIMERS_7_DATA_MSB                            31
#define MAC_PCU_GENERIC_TIMERS_7_DATA_LSB                            0
#define MAC_PCU_GENERIC_TIMERS_7_DATA_MASK                           0xffffffff
#define MAC_PCU_GENERIC_TIMERS_7_DATA_GET(x)                         (((x) & MAC_PCU_GENERIC_TIMERS_7_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_7_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_7_DATA_SET(x)                         (((x) << MAC_PCU_GENERIC_TIMERS_7_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_7_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_7_DATA_RESET                          0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_7_ADDRESS                             0x0080
#define MAC_PCU_GENERIC_TIMERS_7_OFFSET                              0x0080
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_7_SW_MASK                             0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_7_RSTMASK                             0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_7_RESET                               0x00000000

// 32'h0084 (MAC_PCU_GENERIC_TIMERS_8)
#define MAC_PCU_GENERIC_TIMERS_8_DATA_MSB                            31
#define MAC_PCU_GENERIC_TIMERS_8_DATA_LSB                            0
#define MAC_PCU_GENERIC_TIMERS_8_DATA_MASK                           0xffffffff
#define MAC_PCU_GENERIC_TIMERS_8_DATA_GET(x)                         (((x) & MAC_PCU_GENERIC_TIMERS_8_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_8_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_8_DATA_SET(x)                         (((x) << MAC_PCU_GENERIC_TIMERS_8_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_8_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_8_DATA_RESET                          0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_8_ADDRESS                             0x0084
#define MAC_PCU_GENERIC_TIMERS_8_OFFSET                              0x0084
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_8_SW_MASK                             0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_8_RSTMASK                             0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_8_RESET                               0x00000000

// 32'h0088 (MAC_PCU_GENERIC_TIMERS_9)
#define MAC_PCU_GENERIC_TIMERS_9_DATA_MSB                            31
#define MAC_PCU_GENERIC_TIMERS_9_DATA_LSB                            0
#define MAC_PCU_GENERIC_TIMERS_9_DATA_MASK                           0xffffffff
#define MAC_PCU_GENERIC_TIMERS_9_DATA_GET(x)                         (((x) & MAC_PCU_GENERIC_TIMERS_9_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_9_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_9_DATA_SET(x)                         (((x) << MAC_PCU_GENERIC_TIMERS_9_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_9_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_9_DATA_RESET                          0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_9_ADDRESS                             0x0088
#define MAC_PCU_GENERIC_TIMERS_9_OFFSET                              0x0088
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_9_SW_MASK                             0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_9_RSTMASK                             0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_9_RESET                               0x00000000

// 32'h008c (MAC_PCU_GENERIC_TIMERS_10)
#define MAC_PCU_GENERIC_TIMERS_10_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS_10_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS_10_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS_10_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS_10_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_10_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_10_DATA_SET(x)                        (((x) << MAC_PCU_GENERIC_TIMERS_10_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_10_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_10_DATA_RESET                         0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_10_ADDRESS                            0x008c
#define MAC_PCU_GENERIC_TIMERS_10_OFFSET                             0x008c
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_10_SW_MASK                            0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_10_RSTMASK                            0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_10_RESET                              0x00000000

// 32'h0090 (MAC_PCU_GENERIC_TIMERS_11)
#define MAC_PCU_GENERIC_TIMERS_11_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS_11_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS_11_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS_11_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS_11_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_11_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_11_DATA_SET(x)                        (((x) << MAC_PCU_GENERIC_TIMERS_11_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_11_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_11_DATA_RESET                         0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_11_ADDRESS                            0x0090
#define MAC_PCU_GENERIC_TIMERS_11_OFFSET                             0x0090
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_11_SW_MASK                            0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_11_RSTMASK                            0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_11_RESET                              0x00000000

// 32'h0094 (MAC_PCU_GENERIC_TIMERS_12)
#define MAC_PCU_GENERIC_TIMERS_12_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS_12_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS_12_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS_12_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS_12_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_12_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_12_DATA_SET(x)                        (((x) << MAC_PCU_GENERIC_TIMERS_12_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_12_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_12_DATA_RESET                         0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_12_ADDRESS                            0x0094
#define MAC_PCU_GENERIC_TIMERS_12_OFFSET                             0x0094
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_12_SW_MASK                            0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_12_RSTMASK                            0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_12_RESET                              0x00000000

// 32'h0098 (MAC_PCU_GENERIC_TIMERS_13)
#define MAC_PCU_GENERIC_TIMERS_13_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS_13_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS_13_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS_13_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS_13_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_13_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_13_DATA_SET(x)                        (((x) << MAC_PCU_GENERIC_TIMERS_13_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_13_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_13_DATA_RESET                         0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_13_ADDRESS                            0x0098
#define MAC_PCU_GENERIC_TIMERS_13_OFFSET                             0x0098
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_13_SW_MASK                            0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_13_RSTMASK                            0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_13_RESET                              0x00000000

// 32'h009c (MAC_PCU_GENERIC_TIMERS_14)
#define MAC_PCU_GENERIC_TIMERS_14_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS_14_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS_14_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS_14_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS_14_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_14_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_14_DATA_SET(x)                        (((x) << MAC_PCU_GENERIC_TIMERS_14_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_14_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_14_DATA_RESET                         0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_14_ADDRESS                            0x009c
#define MAC_PCU_GENERIC_TIMERS_14_OFFSET                             0x009c
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_14_SW_MASK                            0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_14_RSTMASK                            0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_14_RESET                              0x00000000

// 32'h00a0 (MAC_PCU_GENERIC_TIMERS_15)
#define MAC_PCU_GENERIC_TIMERS_15_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS_15_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS_15_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS_15_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS_15_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_15_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_15_DATA_SET(x)                        (((x) << MAC_PCU_GENERIC_TIMERS_15_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_15_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_15_DATA_RESET                         0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_15_ADDRESS                            0x00a0
#define MAC_PCU_GENERIC_TIMERS_15_OFFSET                             0x00a0
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_15_SW_MASK                            0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_15_RSTMASK                            0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_15_RESET                              0x00000000

// 32'h00bc (MAC_PCU_GENERIC_TIMERS_MODE)
#define MAC_PCU_GENERIC_TIMERS_MODE_THRESH_MSB                       31
#define MAC_PCU_GENERIC_TIMERS_MODE_THRESH_LSB                       12
#define MAC_PCU_GENERIC_TIMERS_MODE_THRESH_MASK                      0xfffff000
#define MAC_PCU_GENERIC_TIMERS_MODE_THRESH_GET(x)                    (((x) & MAC_PCU_GENERIC_TIMERS_MODE_THRESH_MASK) >> MAC_PCU_GENERIC_TIMERS_MODE_THRESH_LSB)
#define MAC_PCU_GENERIC_TIMERS_MODE_THRESH_SET(x)                    (((x) << MAC_PCU_GENERIC_TIMERS_MODE_THRESH_LSB) & MAC_PCU_GENERIC_TIMERS_MODE_THRESH_MASK)
#define MAC_PCU_GENERIC_TIMERS_MODE_THRESH_RESET                     0x100 // 256
#define MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_MSB               10
#define MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_LSB               8
#define MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_MASK              0x00000700
#define MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_GET(x)            (((x) & MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_MASK) >> MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_LSB)
#define MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_SET(x)            (((x) << MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_LSB) & MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_MASK)
#define MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_RESET             0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_MSB                       7
#define MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_LSB                       0
#define MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_MASK                      0x000000ff
#define MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_GET(x)                    (((x) & MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_MASK) >> MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_LSB)
#define MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_SET(x)                    (((x) << MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_LSB) & MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_MASK)
#define MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_RESET                     0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_MODE_ADDRESS                          0x00bc
#define MAC_PCU_GENERIC_TIMERS_MODE_OFFSET                           0x00bc
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_MODE_SW_MASK                          0xfffff7ff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_MODE_RSTMASK                          0xfffff8ff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_MODE_RESET                            0x00100000

// 32'h00c0 (MAC_PCU_SLP1)
#define MAC_PCU_SLP1_CAB_TIMEOUT_MSB                                 31
#define MAC_PCU_SLP1_CAB_TIMEOUT_LSB                                 21
#define MAC_PCU_SLP1_CAB_TIMEOUT_MASK                                0xffe00000
#define MAC_PCU_SLP1_CAB_TIMEOUT_GET(x)                              (((x) & MAC_PCU_SLP1_CAB_TIMEOUT_MASK) >> MAC_PCU_SLP1_CAB_TIMEOUT_LSB)
#define MAC_PCU_SLP1_CAB_TIMEOUT_SET(x)                              (((x) << MAC_PCU_SLP1_CAB_TIMEOUT_LSB) & MAC_PCU_SLP1_CAB_TIMEOUT_MASK)
#define MAC_PCU_SLP1_CAB_TIMEOUT_RESET                               0x5 // 5
#define MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_MSB                        20
#define MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_LSB                        20
#define MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_MASK                       0x00100000
#define MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_GET(x)                     (((x) & MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_MASK) >> MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_LSB)
#define MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_SET(x)                     (((x) << MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_LSB) & MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_MASK)
#define MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_RESET                      0x0 // 0
#define MAC_PCU_SLP1_ASSUME_DTIM_MSB                                 19
#define MAC_PCU_SLP1_ASSUME_DTIM_LSB                                 19
#define MAC_PCU_SLP1_ASSUME_DTIM_MASK                                0x00080000
#define MAC_PCU_SLP1_ASSUME_DTIM_GET(x)                              (((x) & MAC_PCU_SLP1_ASSUME_DTIM_MASK) >> MAC_PCU_SLP1_ASSUME_DTIM_LSB)
#define MAC_PCU_SLP1_ASSUME_DTIM_SET(x)                              (((x) << MAC_PCU_SLP1_ASSUME_DTIM_LSB) & MAC_PCU_SLP1_ASSUME_DTIM_MASK)
#define MAC_PCU_SLP1_ASSUME_DTIM_RESET                               0x0 // 0
#define MAC_PCU_SLP1_CAB_TIMEOUT_EXT_MSB                             4
#define MAC_PCU_SLP1_CAB_TIMEOUT_EXT_LSB                             0
#define MAC_PCU_SLP1_CAB_TIMEOUT_EXT_MASK                            0x0000001f
#define MAC_PCU_SLP1_CAB_TIMEOUT_EXT_GET(x)                          (((x) & MAC_PCU_SLP1_CAB_TIMEOUT_EXT_MASK) >> MAC_PCU_SLP1_CAB_TIMEOUT_EXT_LSB)
#define MAC_PCU_SLP1_CAB_TIMEOUT_EXT_SET(x)                          (((x) << MAC_PCU_SLP1_CAB_TIMEOUT_EXT_LSB) & MAC_PCU_SLP1_CAB_TIMEOUT_EXT_MASK)
#define MAC_PCU_SLP1_CAB_TIMEOUT_EXT_RESET                           0x0 // 0
#define MAC_PCU_SLP1_ADDRESS                                         0x00c0
#define MAC_PCU_SLP1_OFFSET                                          0x00c0
// SW modifiable bits
#define MAC_PCU_SLP1_SW_MASK                                         0xfff8001f
// bits defined at reset
#define MAC_PCU_SLP1_RSTMASK                                         0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_SLP1_RESET                                           0x00a00000

// 32'h00c4 (MAC_PCU_SLP2)
#define MAC_PCU_SLP2_BEACON_TIMEOUT_MSB                              31
#define MAC_PCU_SLP2_BEACON_TIMEOUT_LSB                              21
#define MAC_PCU_SLP2_BEACON_TIMEOUT_MASK                             0xffe00000
#define MAC_PCU_SLP2_BEACON_TIMEOUT_GET(x)                           (((x) & MAC_PCU_SLP2_BEACON_TIMEOUT_MASK) >> MAC_PCU_SLP2_BEACON_TIMEOUT_LSB)
#define MAC_PCU_SLP2_BEACON_TIMEOUT_SET(x)                           (((x) << MAC_PCU_SLP2_BEACON_TIMEOUT_LSB) & MAC_PCU_SLP2_BEACON_TIMEOUT_MASK)
#define MAC_PCU_SLP2_BEACON_TIMEOUT_RESET                            0x2 // 2
#define MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_MSB                          4
#define MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_LSB                          0
#define MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_MASK                         0x0000001f
#define MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_GET(x)                       (((x) & MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_MASK) >> MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_LSB)
#define MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_SET(x)                       (((x) << MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_LSB) & MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_MASK)
#define MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_RESET                        0x0 // 0
#define MAC_PCU_SLP2_ADDRESS                                         0x00c4
#define MAC_PCU_SLP2_OFFSET                                          0x00c4
// SW modifiable bits
#define MAC_PCU_SLP2_SW_MASK                                         0xffe0001f
// bits defined at reset
#define MAC_PCU_SLP2_RSTMASK                                         0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_SLP2_RESET                                           0x00400000

// 32'h00c8 (MAC_PCU_SLP3)
#define MAC_PCU_SLP3_CAB_AWAKE_ENABLE_MSB                            16
#define MAC_PCU_SLP3_CAB_AWAKE_ENABLE_LSB                            16
#define MAC_PCU_SLP3_CAB_AWAKE_ENABLE_MASK                           0x00010000
#define MAC_PCU_SLP3_CAB_AWAKE_ENABLE_GET(x)                         (((x) & MAC_PCU_SLP3_CAB_AWAKE_ENABLE_MASK) >> MAC_PCU_SLP3_CAB_AWAKE_ENABLE_LSB)
#define MAC_PCU_SLP3_CAB_AWAKE_ENABLE_SET(x)                         (((x) << MAC_PCU_SLP3_CAB_AWAKE_ENABLE_LSB) & MAC_PCU_SLP3_CAB_AWAKE_ENABLE_MASK)
#define MAC_PCU_SLP3_CAB_AWAKE_ENABLE_RESET                          0x0 // 0
#define MAC_PCU_SLP3_CAB_AWAKE_DUR_MSB                               15
#define MAC_PCU_SLP3_CAB_AWAKE_DUR_LSB                               0
#define MAC_PCU_SLP3_CAB_AWAKE_DUR_MASK                              0x0000ffff
#define MAC_PCU_SLP3_CAB_AWAKE_DUR_GET(x)                            (((x) & MAC_PCU_SLP3_CAB_AWAKE_DUR_MASK) >> MAC_PCU_SLP3_CAB_AWAKE_DUR_LSB)
#define MAC_PCU_SLP3_CAB_AWAKE_DUR_SET(x)                            (((x) << MAC_PCU_SLP3_CAB_AWAKE_DUR_LSB) & MAC_PCU_SLP3_CAB_AWAKE_DUR_MASK)
#define MAC_PCU_SLP3_CAB_AWAKE_DUR_RESET                             0x5 // 5
#define MAC_PCU_SLP3_ADDRESS                                         0x00c8
#define MAC_PCU_SLP3_OFFSET                                          0x00c8
// SW modifiable bits
#define MAC_PCU_SLP3_SW_MASK                                         0x0001ffff
// bits defined at reset
#define MAC_PCU_SLP3_RSTMASK                                         0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_SLP3_RESET                                           0x00000005

// 32'h00cc (MAC_PCU_SLP4)
#define MAC_PCU_SLP4_ASSUME_DTIM2_MSB                                31
#define MAC_PCU_SLP4_ASSUME_DTIM2_LSB                                31
#define MAC_PCU_SLP4_ASSUME_DTIM2_MASK                               0x80000000
#define MAC_PCU_SLP4_ASSUME_DTIM2_GET(x)                             (((x) & MAC_PCU_SLP4_ASSUME_DTIM2_MASK) >> MAC_PCU_SLP4_ASSUME_DTIM2_LSB)
#define MAC_PCU_SLP4_ASSUME_DTIM2_SET(x)                             (((x) << MAC_PCU_SLP4_ASSUME_DTIM2_LSB) & MAC_PCU_SLP4_ASSUME_DTIM2_MASK)
#define MAC_PCU_SLP4_ASSUME_DTIM2_RESET                              0x0 // 0
#define MAC_PCU_SLP4_CAB2_TIMEOUT_MSB                                30
#define MAC_PCU_SLP4_CAB2_TIMEOUT_LSB                                16
#define MAC_PCU_SLP4_CAB2_TIMEOUT_MASK                               0x7fff0000
#define MAC_PCU_SLP4_CAB2_TIMEOUT_GET(x)                             (((x) & MAC_PCU_SLP4_CAB2_TIMEOUT_MASK) >> MAC_PCU_SLP4_CAB2_TIMEOUT_LSB)
#define MAC_PCU_SLP4_CAB2_TIMEOUT_SET(x)                             (((x) << MAC_PCU_SLP4_CAB2_TIMEOUT_LSB) & MAC_PCU_SLP4_CAB2_TIMEOUT_MASK)
#define MAC_PCU_SLP4_CAB2_TIMEOUT_RESET                              0x5 // 5
#define MAC_PCU_SLP4_BEACON2_TIMEOUT_MSB                             15
#define MAC_PCU_SLP4_BEACON2_TIMEOUT_LSB                             0
#define MAC_PCU_SLP4_BEACON2_TIMEOUT_MASK                            0x0000ffff
#define MAC_PCU_SLP4_BEACON2_TIMEOUT_GET(x)                          (((x) & MAC_PCU_SLP4_BEACON2_TIMEOUT_MASK) >> MAC_PCU_SLP4_BEACON2_TIMEOUT_LSB)
#define MAC_PCU_SLP4_BEACON2_TIMEOUT_SET(x)                          (((x) << MAC_PCU_SLP4_BEACON2_TIMEOUT_LSB) & MAC_PCU_SLP4_BEACON2_TIMEOUT_MASK)
#define MAC_PCU_SLP4_BEACON2_TIMEOUT_RESET                           0x2 // 2
#define MAC_PCU_SLP4_ADDRESS                                         0x00cc
#define MAC_PCU_SLP4_OFFSET                                          0x00cc
// SW modifiable bits
#define MAC_PCU_SLP4_SW_MASK                                         0xffffffff
// bits defined at reset
#define MAC_PCU_SLP4_RSTMASK                                         0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_SLP4_RESET                                           0x00050002

// 32'h00d0 (MAC_PCU_RESET_TSF)
#define MAC_PCU_RESET_TSF_ONE_SHOT2_MSB                              25
#define MAC_PCU_RESET_TSF_ONE_SHOT2_LSB                              25
#define MAC_PCU_RESET_TSF_ONE_SHOT2_MASK                             0x02000000
#define MAC_PCU_RESET_TSF_ONE_SHOT2_GET(x)                           (((x) & MAC_PCU_RESET_TSF_ONE_SHOT2_MASK) >> MAC_PCU_RESET_TSF_ONE_SHOT2_LSB)
#define MAC_PCU_RESET_TSF_ONE_SHOT2_SET(x)                           (((x) << MAC_PCU_RESET_TSF_ONE_SHOT2_LSB) & MAC_PCU_RESET_TSF_ONE_SHOT2_MASK)
#define MAC_PCU_RESET_TSF_ONE_SHOT2_RESET                            0x0 // 0
#define MAC_PCU_RESET_TSF_ONE_SHOT_MSB                               24
#define MAC_PCU_RESET_TSF_ONE_SHOT_LSB                               24
#define MAC_PCU_RESET_TSF_ONE_SHOT_MASK                              0x01000000
#define MAC_PCU_RESET_TSF_ONE_SHOT_GET(x)                            (((x) & MAC_PCU_RESET_TSF_ONE_SHOT_MASK) >> MAC_PCU_RESET_TSF_ONE_SHOT_LSB)
#define MAC_PCU_RESET_TSF_ONE_SHOT_SET(x)                            (((x) << MAC_PCU_RESET_TSF_ONE_SHOT_LSB) & MAC_PCU_RESET_TSF_ONE_SHOT_MASK)
#define MAC_PCU_RESET_TSF_ONE_SHOT_RESET                             0x0 // 0
#define MAC_PCU_RESET_TSF_ADDRESS                                    0x00d0
#define MAC_PCU_RESET_TSF_OFFSET                                     0x00d0
// SW modifiable bits
#define MAC_PCU_RESET_TSF_SW_MASK                                    0x03000000
// bits defined at reset
#define MAC_PCU_RESET_TSF_RSTMASK                                    0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_RESET_TSF_RESET                                      0x00000000

// 32'h00d4 (MAC_PCU_TSF2_L32)
#define MAC_PCU_TSF2_L32_VALUE_MSB                                   31
#define MAC_PCU_TSF2_L32_VALUE_LSB                                   0
#define MAC_PCU_TSF2_L32_VALUE_MASK                                  0xffffffff
#define MAC_PCU_TSF2_L32_VALUE_GET(x)                                (((x) & MAC_PCU_TSF2_L32_VALUE_MASK) >> MAC_PCU_TSF2_L32_VALUE_LSB)
#define MAC_PCU_TSF2_L32_VALUE_SET(x)                                (((x) << MAC_PCU_TSF2_L32_VALUE_LSB) & MAC_PCU_TSF2_L32_VALUE_MASK)
#define MAC_PCU_TSF2_L32_VALUE_RESET                                 0xfffffff // 268435455
#define MAC_PCU_TSF2_L32_ADDRESS                                     0x00d4
#define MAC_PCU_TSF2_L32_OFFSET                                      0x00d4
// SW modifiable bits
#define MAC_PCU_TSF2_L32_SW_MASK                                     0xffffffff
// bits defined at reset
#define MAC_PCU_TSF2_L32_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_TSF2_L32_RESET                                       0x0fffffff

// 32'h00d8 (MAC_PCU_TSF2_U32)
#define MAC_PCU_TSF2_U32_VALUE_MSB                                   31
#define MAC_PCU_TSF2_U32_VALUE_LSB                                   0
#define MAC_PCU_TSF2_U32_VALUE_MASK                                  0xffffffff
#define MAC_PCU_TSF2_U32_VALUE_GET(x)                                (((x) & MAC_PCU_TSF2_U32_VALUE_MASK) >> MAC_PCU_TSF2_U32_VALUE_LSB)
#define MAC_PCU_TSF2_U32_VALUE_SET(x)                                (((x) << MAC_PCU_TSF2_U32_VALUE_LSB) & MAC_PCU_TSF2_U32_VALUE_MASK)
#define MAC_PCU_TSF2_U32_VALUE_RESET                                 0xfffffff // 268435455
#define MAC_PCU_TSF2_U32_ADDRESS                                     0x00d8
#define MAC_PCU_TSF2_U32_OFFSET                                      0x00d8
// SW modifiable bits
#define MAC_PCU_TSF2_U32_SW_MASK                                     0xffffffff
// bits defined at reset
#define MAC_PCU_TSF2_U32_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_TSF2_U32_RESET                                       0x0fffffff

// 32'h00dc (MAC_PCU_GENERIC_TIMERS2_0)
#define MAC_PCU_GENERIC_TIMERS2_0_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS2_0_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS2_0_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_0_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS2_0_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_0_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_0_DATA_SET(x)                        (((x) << MAC_PCU_GENERIC_TIMERS2_0_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_0_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_0_DATA_RESET                         0x0 // 0
#define MAC_PCU_GENERIC_TIMERS2_0_ADDRESS                            0x00dc
#define MAC_PCU_GENERIC_TIMERS2_0_OFFSET                             0x00dc
#define MAC_PCU_GENERIC_TIMERS2_ADDRESS                              MAC_PCU_GENERIC_TIMERS2_0_ADDRESS
#define MAC_PCU_GENERIC_TIMERS2_OFFSET                               MAC_PCU_GENERIC_TIMERS2_0_OFFSET
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS2_0_SW_MASK                            0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS2_0_RSTMASK                            0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS2_0_RESET                              0x00000000

// 32'h00e0 (MAC_PCU_GENERIC_TIMERS2_1)
#define MAC_PCU_GENERIC_TIMERS2_1_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS2_1_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS2_1_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_1_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS2_1_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_1_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_1_DATA_SET(x)                        (((x) << MAC_PCU_GENERIC_TIMERS2_1_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_1_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_1_DATA_RESET                         0x0 // 0
#define MAC_PCU_GENERIC_TIMERS2_1_ADDRESS                            0x00e0
#define MAC_PCU_GENERIC_TIMERS2_1_OFFSET                             0x00e0
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS2_1_SW_MASK                            0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS2_1_RSTMASK                            0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS2_1_RESET                              0x00000000

// 32'h00e4 (MAC_PCU_GENERIC_TIMERS2_2)
#define MAC_PCU_GENERIC_TIMERS2_2_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS2_2_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS2_2_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_2_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS2_2_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_2_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_2_DATA_SET(x)                        (((x) << MAC_PCU_GENERIC_TIMERS2_2_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_2_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_2_DATA_RESET                         0x0 // 0
#define MAC_PCU_GENERIC_TIMERS2_2_ADDRESS                            0x00e4
#define MAC_PCU_GENERIC_TIMERS2_2_OFFSET                             0x00e4
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS2_2_SW_MASK                            0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS2_2_RSTMASK                            0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS2_2_RESET                              0x00000000

// 32'h00e8 (MAC_PCU_GENERIC_TIMERS2_3)
#define MAC_PCU_GENERIC_TIMERS2_3_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS2_3_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS2_3_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_3_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS2_3_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_3_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_3_DATA_SET(x)                        (((x) << MAC_PCU_GENERIC_TIMERS2_3_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_3_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_3_DATA_RESET                         0x0 // 0
#define MAC_PCU_GENERIC_TIMERS2_3_ADDRESS                            0x00e8
#define MAC_PCU_GENERIC_TIMERS2_3_OFFSET                             0x00e8
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS2_3_SW_MASK                            0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS2_3_RSTMASK                            0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS2_3_RESET                              0x00000000

// 32'h00ec (MAC_PCU_GENERIC_TIMERS2_4)
#define MAC_PCU_GENERIC_TIMERS2_4_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS2_4_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS2_4_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_4_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS2_4_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_4_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_4_DATA_SET(x)                        (((x) << MAC_PCU_GENERIC_TIMERS2_4_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_4_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_4_DATA_RESET                         0x0 // 0
#define MAC_PCU_GENERIC_TIMERS2_4_ADDRESS                            0x00ec
#define MAC_PCU_GENERIC_TIMERS2_4_OFFSET                             0x00ec
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS2_4_SW_MASK                            0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS2_4_RSTMASK                            0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS2_4_RESET                              0x00000000

// 32'h00f0 (MAC_PCU_GENERIC_TIMERS2_5)
#define MAC_PCU_GENERIC_TIMERS2_5_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS2_5_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS2_5_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_5_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS2_5_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_5_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_5_DATA_SET(x)                        (((x) << MAC_PCU_GENERIC_TIMERS2_5_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_5_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_5_DATA_RESET                         0x0 // 0
#define MAC_PCU_GENERIC_TIMERS2_5_ADDRESS                            0x00f0
#define MAC_PCU_GENERIC_TIMERS2_5_OFFSET                             0x00f0
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS2_5_SW_MASK                            0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS2_5_RSTMASK                            0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS2_5_RESET                              0x00000000

// 32'h00f4 (MAC_PCU_GENERIC_TIMERS2_6)
#define MAC_PCU_GENERIC_TIMERS2_6_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS2_6_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS2_6_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_6_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS2_6_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_6_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_6_DATA_SET(x)                        (((x) << MAC_PCU_GENERIC_TIMERS2_6_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_6_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_6_DATA_RESET                         0x0 // 0
#define MAC_PCU_GENERIC_TIMERS2_6_ADDRESS                            0x00f4
#define MAC_PCU_GENERIC_TIMERS2_6_OFFSET                             0x00f4
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS2_6_SW_MASK                            0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS2_6_RSTMASK                            0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS2_6_RESET                              0x00000000

// 32'h00f8 (MAC_PCU_GENERIC_TIMERS2_7)
#define MAC_PCU_GENERIC_TIMERS2_7_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS2_7_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS2_7_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_7_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS2_7_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_7_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_7_DATA_SET(x)                        (((x) << MAC_PCU_GENERIC_TIMERS2_7_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_7_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_7_DATA_RESET                         0x0 // 0
#define MAC_PCU_GENERIC_TIMERS2_7_ADDRESS                            0x00f8
#define MAC_PCU_GENERIC_TIMERS2_7_OFFSET                             0x00f8
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS2_7_SW_MASK                            0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS2_7_RSTMASK                            0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS2_7_RESET                              0x00000000

// 32'h00fc (MAC_PCU_GENERIC_TIMERS2_8)
#define MAC_PCU_GENERIC_TIMERS2_8_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS2_8_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS2_8_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_8_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS2_8_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_8_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_8_DATA_SET(x)                        (((x) << MAC_PCU_GENERIC_TIMERS2_8_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_8_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_8_DATA_RESET                         0x0 // 0
#define MAC_PCU_GENERIC_TIMERS2_8_ADDRESS                            0x00fc
#define MAC_PCU_GENERIC_TIMERS2_8_OFFSET                             0x00fc
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS2_8_SW_MASK                            0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS2_8_RSTMASK                            0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS2_8_RESET                              0x00000000

// 32'h0100 (MAC_PCU_GENERIC_TIMERS2_9)
#define MAC_PCU_GENERIC_TIMERS2_9_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS2_9_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS2_9_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_9_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS2_9_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_9_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_9_DATA_SET(x)                        (((x) << MAC_PCU_GENERIC_TIMERS2_9_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_9_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_9_DATA_RESET                         0x0 // 0
#define MAC_PCU_GENERIC_TIMERS2_9_ADDRESS                            0x0100
#define MAC_PCU_GENERIC_TIMERS2_9_OFFSET                             0x0100
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS2_9_SW_MASK                            0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS2_9_RSTMASK                            0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS2_9_RESET                              0x00000000

// 32'h0104 (MAC_PCU_GENERIC_TIMERS2_10)
#define MAC_PCU_GENERIC_TIMERS2_10_DATA_MSB                          31
#define MAC_PCU_GENERIC_TIMERS2_10_DATA_LSB                          0
#define MAC_PCU_GENERIC_TIMERS2_10_DATA_MASK                         0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_10_DATA_GET(x)                       (((x) & MAC_PCU_GENERIC_TIMERS2_10_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_10_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_10_DATA_SET(x)                       (((x) << MAC_PCU_GENERIC_TIMERS2_10_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_10_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_10_DATA_RESET                        0x0 // 0
#define MAC_PCU_GENERIC_TIMERS2_10_ADDRESS                           0x0104
#define MAC_PCU_GENERIC_TIMERS2_10_OFFSET                            0x0104
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS2_10_SW_MASK                           0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS2_10_RSTMASK                           0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS2_10_RESET                             0x00000000

// 32'h0108 (MAC_PCU_GENERIC_TIMERS2_11)
#define MAC_PCU_GENERIC_TIMERS2_11_DATA_MSB                          31
#define MAC_PCU_GENERIC_TIMERS2_11_DATA_LSB                          0
#define MAC_PCU_GENERIC_TIMERS2_11_DATA_MASK                         0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_11_DATA_GET(x)                       (((x) & MAC_PCU_GENERIC_TIMERS2_11_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_11_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_11_DATA_SET(x)                       (((x) << MAC_PCU_GENERIC_TIMERS2_11_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_11_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_11_DATA_RESET                        0x0 // 0
#define MAC_PCU_GENERIC_TIMERS2_11_ADDRESS                           0x0108
#define MAC_PCU_GENERIC_TIMERS2_11_OFFSET                            0x0108
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS2_11_SW_MASK                           0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS2_11_RSTMASK                           0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS2_11_RESET                             0x00000000

// 32'h010c (MAC_PCU_GENERIC_TIMERS2_12)
#define MAC_PCU_GENERIC_TIMERS2_12_DATA_MSB                          31
#define MAC_PCU_GENERIC_TIMERS2_12_DATA_LSB                          0
#define MAC_PCU_GENERIC_TIMERS2_12_DATA_MASK                         0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_12_DATA_GET(x)                       (((x) & MAC_PCU_GENERIC_TIMERS2_12_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_12_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_12_DATA_SET(x)                       (((x) << MAC_PCU_GENERIC_TIMERS2_12_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_12_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_12_DATA_RESET                        0x0 // 0
#define MAC_PCU_GENERIC_TIMERS2_12_ADDRESS                           0x010c
#define MAC_PCU_GENERIC_TIMERS2_12_OFFSET                            0x010c
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS2_12_SW_MASK                           0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS2_12_RSTMASK                           0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS2_12_RESET                             0x00000000

// 32'h0110 (MAC_PCU_GENERIC_TIMERS2_13)
#define MAC_PCU_GENERIC_TIMERS2_13_DATA_MSB                          31
#define MAC_PCU_GENERIC_TIMERS2_13_DATA_LSB                          0
#define MAC_PCU_GENERIC_TIMERS2_13_DATA_MASK                         0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_13_DATA_GET(x)                       (((x) & MAC_PCU_GENERIC_TIMERS2_13_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_13_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_13_DATA_SET(x)                       (((x) << MAC_PCU_GENERIC_TIMERS2_13_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_13_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_13_DATA_RESET                        0x0 // 0
#define MAC_PCU_GENERIC_TIMERS2_13_ADDRESS                           0x0110
#define MAC_PCU_GENERIC_TIMERS2_13_OFFSET                            0x0110
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS2_13_SW_MASK                           0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS2_13_RSTMASK                           0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS2_13_RESET                             0x00000000

// 32'h0114 (MAC_PCU_GENERIC_TIMERS2_14)
#define MAC_PCU_GENERIC_TIMERS2_14_DATA_MSB                          31
#define MAC_PCU_GENERIC_TIMERS2_14_DATA_LSB                          0
#define MAC_PCU_GENERIC_TIMERS2_14_DATA_MASK                         0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_14_DATA_GET(x)                       (((x) & MAC_PCU_GENERIC_TIMERS2_14_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_14_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_14_DATA_SET(x)                       (((x) << MAC_PCU_GENERIC_TIMERS2_14_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_14_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_14_DATA_RESET                        0x0 // 0
#define MAC_PCU_GENERIC_TIMERS2_14_ADDRESS                           0x0114
#define MAC_PCU_GENERIC_TIMERS2_14_OFFSET                            0x0114
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS2_14_SW_MASK                           0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS2_14_RSTMASK                           0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS2_14_RESET                             0x00000000

// 32'h0118 (MAC_PCU_GENERIC_TIMERS2_15)
#define MAC_PCU_GENERIC_TIMERS2_15_DATA_MSB                          31
#define MAC_PCU_GENERIC_TIMERS2_15_DATA_LSB                          0
#define MAC_PCU_GENERIC_TIMERS2_15_DATA_MASK                         0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_15_DATA_GET(x)                       (((x) & MAC_PCU_GENERIC_TIMERS2_15_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_15_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_15_DATA_SET(x)                       (((x) << MAC_PCU_GENERIC_TIMERS2_15_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_15_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_15_DATA_RESET                        0x0 // 0
#define MAC_PCU_GENERIC_TIMERS2_15_ADDRESS                           0x0118
#define MAC_PCU_GENERIC_TIMERS2_15_OFFSET                            0x0118
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS2_15_SW_MASK                           0xffffffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS2_15_RSTMASK                           0x00000000
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS2_15_RESET                             0x00000000

// 32'h0134 (MAC_PCU_GENERIC_TIMERS_MODE2)
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_MSB             15
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_LSB             12
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_MASK            0x0000f000
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_GET(x)          (((x) & MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_MASK) >> MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_LSB)
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_SET(x)          (((x) << MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_LSB) & MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_MASK)
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_RESET           0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_MSB              11
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_LSB              8
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_MASK             0x00000f00
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_GET(x)           (((x) & MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_MASK) >> MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_LSB)
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_SET(x)           (((x) << MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_LSB) & MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_MASK)
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_RESET            0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_MSB                      7
#define MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_LSB                      0
#define MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_MASK                     0x000000ff
#define MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_GET(x)                   (((x) & MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_MASK) >> MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_LSB)
#define MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_SET(x)                   (((x) << MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_LSB) & MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_MASK)
#define MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_RESET                    0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_MODE2_ADDRESS                         0x0134
#define MAC_PCU_GENERIC_TIMERS_MODE2_OFFSET                          0x0134
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_MODE2_SW_MASK                         0x0000ffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_MODE2_RSTMASK                         0xffff00ff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_MODE2_RESET                           0x00000000

// 32'h0144 (MAC_PCU_TSF_THRESHOLD)
#define MAC_PCU_TSF_THRESHOLD_VALUE_MSB                              15
#define MAC_PCU_TSF_THRESHOLD_VALUE_LSB                              0
#define MAC_PCU_TSF_THRESHOLD_VALUE_MASK                             0x0000ffff
#define MAC_PCU_TSF_THRESHOLD_VALUE_GET(x)                           (((x) & MAC_PCU_TSF_THRESHOLD_VALUE_MASK) >> MAC_PCU_TSF_THRESHOLD_VALUE_LSB)
#define MAC_PCU_TSF_THRESHOLD_VALUE_SET(x)                           (((x) << MAC_PCU_TSF_THRESHOLD_VALUE_LSB) & MAC_PCU_TSF_THRESHOLD_VALUE_MASK)
#define MAC_PCU_TSF_THRESHOLD_VALUE_RESET                            0xffff // 65535
#define MAC_PCU_TSF_THRESHOLD_ADDRESS                                0x0144
#define MAC_PCU_TSF_THRESHOLD_OFFSET                                 0x0144
// SW modifiable bits
#define MAC_PCU_TSF_THRESHOLD_SW_MASK                                0x0000ffff
// bits defined at reset
#define MAC_PCU_TSF_THRESHOLD_RSTMASK                                0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_TSF_THRESHOLD_RESET                                  0x0000ffff

// 32'h0148 (WLAN_HT)
#define WLAN_HT_MODE_MSB                                             0
#define WLAN_HT_MODE_LSB                                             0
#define WLAN_HT_MODE_MASK                                            0x00000001
#define WLAN_HT_MODE_GET(x)                                          (((x) & WLAN_HT_MODE_MASK) >> WLAN_HT_MODE_LSB)
#define WLAN_HT_MODE_SET(x)                                          (((x) << WLAN_HT_MODE_LSB) & WLAN_HT_MODE_MASK)
#define WLAN_HT_MODE_RESET                                           0x0 // 0
#define WLAN_HT_ADDRESS                                              0x0148
#define WLAN_HT_OFFSET                                               0x0148
// SW modifiable bits
#define WLAN_HT_SW_MASK                                              0x00000001
// bits defined at reset
#define WLAN_HT_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_HT_RESET                                                0x00000000

// 32'h0150 (MAC_PCU_GENERIC_TIMERS_TSF_SEL)
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_MSB                     15
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_LSB                     0
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_MASK                    0x0000ffff
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_GET(x)                  (((x) & MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_MASK) >> MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_LSB)
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_SET(x)                  (((x) << MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_LSB) & MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_MASK)
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_RESET                   0x0 // 0
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_ADDRESS                       0x0150
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_OFFSET                        0x0150
// SW modifiable bits
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_SW_MASK                       0x0000ffff
// bits defined at reset
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_RSTMASK                       0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_RESET                         0x00000000

// 32'h0154 (MAC_PCU_BMISS_TIMEOUT)
#define MAC_PCU_BMISS_TIMEOUT_ENABLE_MSB                             24
#define MAC_PCU_BMISS_TIMEOUT_ENABLE_LSB                             24
#define MAC_PCU_BMISS_TIMEOUT_ENABLE_MASK                            0x01000000
#define MAC_PCU_BMISS_TIMEOUT_ENABLE_GET(x)                          (((x) & MAC_PCU_BMISS_TIMEOUT_ENABLE_MASK) >> MAC_PCU_BMISS_TIMEOUT_ENABLE_LSB)
#define MAC_PCU_BMISS_TIMEOUT_ENABLE_SET(x)                          (((x) << MAC_PCU_BMISS_TIMEOUT_ENABLE_LSB) & MAC_PCU_BMISS_TIMEOUT_ENABLE_MASK)
#define MAC_PCU_BMISS_TIMEOUT_ENABLE_RESET                           0x0 // 0
#define MAC_PCU_BMISS_TIMEOUT_VALUE_MSB                              23
#define MAC_PCU_BMISS_TIMEOUT_VALUE_LSB                              0
#define MAC_PCU_BMISS_TIMEOUT_VALUE_MASK                             0x00ffffff
#define MAC_PCU_BMISS_TIMEOUT_VALUE_GET(x)                           (((x) & MAC_PCU_BMISS_TIMEOUT_VALUE_MASK) >> MAC_PCU_BMISS_TIMEOUT_VALUE_LSB)
#define MAC_PCU_BMISS_TIMEOUT_VALUE_SET(x)                           (((x) << MAC_PCU_BMISS_TIMEOUT_VALUE_LSB) & MAC_PCU_BMISS_TIMEOUT_VALUE_MASK)
#define MAC_PCU_BMISS_TIMEOUT_VALUE_RESET                            0xffffff // 16777215
#define MAC_PCU_BMISS_TIMEOUT_ADDRESS                                0x0154
#define MAC_PCU_BMISS_TIMEOUT_OFFSET                                 0x0154
// SW modifiable bits
#define MAC_PCU_BMISS_TIMEOUT_SW_MASK                                0x01ffffff
// bits defined at reset
#define MAC_PCU_BMISS_TIMEOUT_RSTMASK                                0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_BMISS_TIMEOUT_RESET                                  0x00ffffff

// 32'h0158 (MAC_PCU_BMISS2_TIMEOUT)
#define MAC_PCU_BMISS2_TIMEOUT_ENABLE_MSB                            24
#define MAC_PCU_BMISS2_TIMEOUT_ENABLE_LSB                            24
#define MAC_PCU_BMISS2_TIMEOUT_ENABLE_MASK                           0x01000000
#define MAC_PCU_BMISS2_TIMEOUT_ENABLE_GET(x)                         (((x) & MAC_PCU_BMISS2_TIMEOUT_ENABLE_MASK) >> MAC_PCU_BMISS2_TIMEOUT_ENABLE_LSB)
#define MAC_PCU_BMISS2_TIMEOUT_ENABLE_SET(x)                         (((x) << MAC_PCU_BMISS2_TIMEOUT_ENABLE_LSB) & MAC_PCU_BMISS2_TIMEOUT_ENABLE_MASK)
#define MAC_PCU_BMISS2_TIMEOUT_ENABLE_RESET                          0x0 // 0
#define MAC_PCU_BMISS2_TIMEOUT_VALUE_MSB                             23
#define MAC_PCU_BMISS2_TIMEOUT_VALUE_LSB                             0
#define MAC_PCU_BMISS2_TIMEOUT_VALUE_MASK                            0x00ffffff
#define MAC_PCU_BMISS2_TIMEOUT_VALUE_GET(x)                          (((x) & MAC_PCU_BMISS2_TIMEOUT_VALUE_MASK) >> MAC_PCU_BMISS2_TIMEOUT_VALUE_LSB)
#define MAC_PCU_BMISS2_TIMEOUT_VALUE_SET(x)                          (((x) << MAC_PCU_BMISS2_TIMEOUT_VALUE_LSB) & MAC_PCU_BMISS2_TIMEOUT_VALUE_MASK)
#define MAC_PCU_BMISS2_TIMEOUT_VALUE_RESET                           0xffffff // 16777215
#define MAC_PCU_BMISS2_TIMEOUT_ADDRESS                               0x0158
#define MAC_PCU_BMISS2_TIMEOUT_OFFSET                                0x0158
// SW modifiable bits
#define MAC_PCU_BMISS2_TIMEOUT_SW_MASK                               0x01ffffff
// bits defined at reset
#define MAC_PCU_BMISS2_TIMEOUT_RSTMASK                               0xffffffff
// reset value (ignore bits undefined at reset)
#define MAC_PCU_BMISS2_TIMEOUT_RESET                                 0x00ffffff

// 32'h0160 (UNIFIED_MAC_REVID)
#define UNIFIED_MAC_REVID_VALUE_MSB                                  31
#define UNIFIED_MAC_REVID_VALUE_LSB                                  0
#define UNIFIED_MAC_REVID_VALUE_MASK                                 0xffffffff
#define UNIFIED_MAC_REVID_VALUE_GET(x)                               (((x) & UNIFIED_MAC_REVID_VALUE_MASK) >> UNIFIED_MAC_REVID_VALUE_LSB)
#define UNIFIED_MAC_REVID_VALUE_SET(x)                               (((x) << UNIFIED_MAC_REVID_VALUE_LSB) & UNIFIED_MAC_REVID_VALUE_MASK)
#define UNIFIED_MAC_REVID_VALUE_RESET                                0x0 // 0
#define UNIFIED_MAC_REVID_ADDRESS                                    0x0160
#define UNIFIED_MAC_REVID_OFFSET                                     0x0160
// SW modifiable bits
#define UNIFIED_MAC_REVID_SW_MASK                                    0xffffffff
// bits defined at reset
#define UNIFIED_MAC_REVID_RSTMASK                                    0x00000000
// reset value (ignore bits undefined at reset)
#define UNIFIED_MAC_REVID_RESET                                      0x00000000


#endif /* _RTC_WLAN_REG_H_ */
