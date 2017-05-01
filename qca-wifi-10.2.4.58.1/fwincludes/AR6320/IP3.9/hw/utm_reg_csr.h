//                                                                             
// File:       ./utm_reg_csr.vrh                                               
// Creator:    tyzhang                                                         
// Time:       Sunday Feb 19, 2012 [12:30:31 am]                               
//                                                                             
// Path:       /trees/mbu-cn1/tyzhang/tianfang_enc_depot/chips/hera/dev/doc/headers/bp_wlan
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/mbu-cn1/tyzhang/tianfang_enc_depot/chips/hera/dev/blueprint/sysconfig
//             utm_reg_csr.rdl                                                 
//                                                                             
// Sources:    /trees/mbu-cn1/tyzhang/tianfang_enc_depot/chips/hera/dev/ip/athr/usb_phy_digital/rtl/utm_reg/utm_reg.rdl
//             /trees/mbu-cn1/tyzhang/tianfang_enc_depot/chips/hera/dev/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    qing                                                            
// OS:         Linux 2.6.9-89.ELsmp                                            
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _UTM_REG_CSR_H_
#define _UTM_REG_CSR_H_
// 0x0000 (PHY_CTRL0)
#define PHY_CTRL0_LOOPBACK_ERR_CNT_MSB                               31
#define PHY_CTRL0_LOOPBACK_ERR_CNT_LSB                               24
#define PHY_CTRL0_LOOPBACK_ERR_CNT_MASK                              0xff000000
#define PHY_CTRL0_LOOPBACK_ERR_CNT_GET(x)                            (((x) & PHY_CTRL0_LOOPBACK_ERR_CNT_MASK) >> PHY_CTRL0_LOOPBACK_ERR_CNT_LSB)
#define PHY_CTRL0_LOOPBACK_ERR_CNT_SET(x)                            (((0 | (x)) << PHY_CTRL0_LOOPBACK_ERR_CNT_LSB) & PHY_CTRL0_LOOPBACK_ERR_CNT_MASK)
#define PHY_CTRL0_LOOPBACK_ERR_CNT_RESET                             0
#define PHY_CTRL0_DIG_LOOPBACK_EN_MSB                                23
#define PHY_CTRL0_DIG_LOOPBACK_EN_LSB                                23
#define PHY_CTRL0_DIG_LOOPBACK_EN_MASK                               0x00800000
#define PHY_CTRL0_DIG_LOOPBACK_EN_GET(x)                             (((x) & PHY_CTRL0_DIG_LOOPBACK_EN_MASK) >> PHY_CTRL0_DIG_LOOPBACK_EN_LSB)
#define PHY_CTRL0_DIG_LOOPBACK_EN_SET(x)                             (((0 | (x)) << PHY_CTRL0_DIG_LOOPBACK_EN_LSB) & PHY_CTRL0_DIG_LOOPBACK_EN_MASK)
#define PHY_CTRL0_DIG_LOOPBACK_EN_RESET                              0
#define PHY_CTRL0_ANA_LOOPBACK_EN_MSB                                22
#define PHY_CTRL0_ANA_LOOPBACK_EN_LSB                                22
#define PHY_CTRL0_ANA_LOOPBACK_EN_MASK                               0x00400000
#define PHY_CTRL0_ANA_LOOPBACK_EN_GET(x)                             (((x) & PHY_CTRL0_ANA_LOOPBACK_EN_MASK) >> PHY_CTRL0_ANA_LOOPBACK_EN_LSB)
#define PHY_CTRL0_ANA_LOOPBACK_EN_SET(x)                             (((0 | (x)) << PHY_CTRL0_ANA_LOOPBACK_EN_LSB) & PHY_CTRL0_ANA_LOOPBACK_EN_MASK)
#define PHY_CTRL0_ANA_LOOPBACK_EN_RESET                              0
#define PHY_CTRL0_TX_PATTERN_EN_MSB                                  21
#define PHY_CTRL0_TX_PATTERN_EN_LSB                                  21
#define PHY_CTRL0_TX_PATTERN_EN_MASK                                 0x00200000
#define PHY_CTRL0_TX_PATTERN_EN_GET(x)                               (((x) & PHY_CTRL0_TX_PATTERN_EN_MASK) >> PHY_CTRL0_TX_PATTERN_EN_LSB)
#define PHY_CTRL0_TX_PATTERN_EN_SET(x)                               (((0 | (x)) << PHY_CTRL0_TX_PATTERN_EN_LSB) & PHY_CTRL0_TX_PATTERN_EN_MASK)
#define PHY_CTRL0_TX_PATTERN_EN_RESET                                0
#define PHY_CTRL0_RX_PATTERN_EN_MSB                                  20
#define PHY_CTRL0_RX_PATTERN_EN_LSB                                  20
#define PHY_CTRL0_RX_PATTERN_EN_MASK                                 0x00100000
#define PHY_CTRL0_RX_PATTERN_EN_GET(x)                               (((x) & PHY_CTRL0_RX_PATTERN_EN_MASK) >> PHY_CTRL0_RX_PATTERN_EN_LSB)
#define PHY_CTRL0_RX_PATTERN_EN_SET(x)                               (((0 | (x)) << PHY_CTRL0_RX_PATTERN_EN_LSB) & PHY_CTRL0_RX_PATTERN_EN_MASK)
#define PHY_CTRL0_RX_PATTERN_EN_RESET                                0
#define PHY_CTRL0_TEST_SPEED_SELECT_MSB                              19
#define PHY_CTRL0_TEST_SPEED_SELECT_LSB                              19
#define PHY_CTRL0_TEST_SPEED_SELECT_MASK                             0x00080000
#define PHY_CTRL0_TEST_SPEED_SELECT_GET(x)                           (((x) & PHY_CTRL0_TEST_SPEED_SELECT_MASK) >> PHY_CTRL0_TEST_SPEED_SELECT_LSB)
#define PHY_CTRL0_TEST_SPEED_SELECT_SET(x)                           (((0 | (x)) << PHY_CTRL0_TEST_SPEED_SELECT_LSB) & PHY_CTRL0_TEST_SPEED_SELECT_MASK)
#define PHY_CTRL0_TEST_SPEED_SELECT_RESET                            0
#define PHY_CTRL0_PLL_OVERIDE_MSB                                    18
#define PHY_CTRL0_PLL_OVERIDE_LSB                                    18
#define PHY_CTRL0_PLL_OVERIDE_MASK                                   0x00040000
#define PHY_CTRL0_PLL_OVERIDE_GET(x)                                 (((x) & PHY_CTRL0_PLL_OVERIDE_MASK) >> PHY_CTRL0_PLL_OVERIDE_LSB)
#define PHY_CTRL0_PLL_OVERIDE_SET(x)                                 (((0 | (x)) << PHY_CTRL0_PLL_OVERIDE_LSB) & PHY_CTRL0_PLL_OVERIDE_MASK)
#define PHY_CTRL0_PLL_OVERIDE_RESET                                  0
#define PHY_CTRL0_PLL_MOD_MSB                                        17
#define PHY_CTRL0_PLL_MOD_LSB                                        15
#define PHY_CTRL0_PLL_MOD_MASK                                       0x00038000
#define PHY_CTRL0_PLL_MOD_GET(x)                                     (((x) & PHY_CTRL0_PLL_MOD_MASK) >> PHY_CTRL0_PLL_MOD_LSB)
#define PHY_CTRL0_PLL_MOD_SET(x)                                     (((0 | (x)) << PHY_CTRL0_PLL_MOD_LSB) & PHY_CTRL0_PLL_MOD_MASK)
#define PHY_CTRL0_PLL_MOD_RESET                                      0
#define PHY_CTRL0_PLL_DIV_MSB                                        14
#define PHY_CTRL0_PLL_DIV_LSB                                        6
#define PHY_CTRL0_PLL_DIV_MASK                                       0x00007fc0
#define PHY_CTRL0_PLL_DIV_GET(x)                                     (((x) & PHY_CTRL0_PLL_DIV_MASK) >> PHY_CTRL0_PLL_DIV_LSB)
#define PHY_CTRL0_PLL_DIV_SET(x)                                     (((0 | (x)) << PHY_CTRL0_PLL_DIV_LSB) & PHY_CTRL0_PLL_DIV_MASK)
#define PHY_CTRL0_PLL_DIV_RESET                                      0
#define PHY_CTRL0_PLL_RS_MSB                                         5
#define PHY_CTRL0_PLL_RS_LSB                                         3
#define PHY_CTRL0_PLL_RS_MASK                                        0x00000038
#define PHY_CTRL0_PLL_RS_GET(x)                                      (((x) & PHY_CTRL0_PLL_RS_MASK) >> PHY_CTRL0_PLL_RS_LSB)
#define PHY_CTRL0_PLL_RS_SET(x)                                      (((0 | (x)) << PHY_CTRL0_PLL_RS_LSB) & PHY_CTRL0_PLL_RS_MASK)
#define PHY_CTRL0_PLL_RS_RESET                                       2
#define PHY_CTRL0_PLL_ICP_MSB                                        2
#define PHY_CTRL0_PLL_ICP_LSB                                        0
#define PHY_CTRL0_PLL_ICP_MASK                                       0x00000007
#define PHY_CTRL0_PLL_ICP_GET(x)                                     (((x) & PHY_CTRL0_PLL_ICP_MASK) >> PHY_CTRL0_PLL_ICP_LSB)
#define PHY_CTRL0_PLL_ICP_SET(x)                                     (((0 | (x)) << PHY_CTRL0_PLL_ICP_LSB) & PHY_CTRL0_PLL_ICP_MASK)
#define PHY_CTRL0_PLL_ICP_RESET                                      5
#define PHY_CTRL0_ADDRESS                                            0x0000
#define PHY_CTRL0_HW_MASK                                            0xffffffff
#define PHY_CTRL0_SW_MASK                                            0xffffffff
#define PHY_CTRL0_HW_WRITE_MASK                                      0xff000000
#define PHY_CTRL0_SW_WRITE_MASK                                      0x00ffffff
#define PHY_CTRL0_RSTMASK                                            0xffffffff
#define PHY_CTRL0_RESET                                              0x00000015

// 0x0004 (PHY_CTRL1)
#define PHY_CTRL1_PLL_OBS_MODE_N_MSB                                 31
#define PHY_CTRL1_PLL_OBS_MODE_N_LSB                                 31
#define PHY_CTRL1_PLL_OBS_MODE_N_MASK                                0x80000000
#define PHY_CTRL1_PLL_OBS_MODE_N_GET(x)                              (((x) & PHY_CTRL1_PLL_OBS_MODE_N_MASK) >> PHY_CTRL1_PLL_OBS_MODE_N_LSB)
#define PHY_CTRL1_PLL_OBS_MODE_N_SET(x)                              (((0 | (x)) << PHY_CTRL1_PLL_OBS_MODE_N_LSB) & PHY_CTRL1_PLL_OBS_MODE_N_MASK)
#define PHY_CTRL1_PLL_OBS_MODE_N_RESET                               1
#define PHY_CTRL1_RESUME_ON_PWDPLL_RADIO_MSB                         29
#define PHY_CTRL1_RESUME_ON_PWDPLL_RADIO_LSB                         29
#define PHY_CTRL1_RESUME_ON_PWDPLL_RADIO_MASK                        0x20000000
#define PHY_CTRL1_RESUME_ON_PWDPLL_RADIO_GET(x)                      (((x) & PHY_CTRL1_RESUME_ON_PWDPLL_RADIO_MASK) >> PHY_CTRL1_RESUME_ON_PWDPLL_RADIO_LSB)
#define PHY_CTRL1_RESUME_ON_PWDPLL_RADIO_SET(x)                      (((0 | (x)) << PHY_CTRL1_RESUME_ON_PWDPLL_RADIO_LSB) & PHY_CTRL1_RESUME_ON_PWDPLL_RADIO_MASK)
#define PHY_CTRL1_RESUME_ON_PWDPLL_RADIO_RESET                       1
#define PHY_CTRL1_SWAP_USB_EN_MSB                                    28
#define PHY_CTRL1_SWAP_USB_EN_LSB                                    28
#define PHY_CTRL1_SWAP_USB_EN_MASK                                   0x10000000
#define PHY_CTRL1_SWAP_USB_EN_GET(x)                                 (((x) & PHY_CTRL1_SWAP_USB_EN_MASK) >> PHY_CTRL1_SWAP_USB_EN_LSB)
#define PHY_CTRL1_SWAP_USB_EN_SET(x)                                 (((0 | (x)) << PHY_CTRL1_SWAP_USB_EN_LSB) & PHY_CTRL1_SWAP_USB_EN_MASK)
#define PHY_CTRL1_SWAP_USB_EN_RESET                                  0
#define PHY_CTRL1_DISABLE_CLK_GATING_MSB                             27
#define PHY_CTRL1_DISABLE_CLK_GATING_LSB                             27
#define PHY_CTRL1_DISABLE_CLK_GATING_MASK                            0x08000000
#define PHY_CTRL1_DISABLE_CLK_GATING_GET(x)                          (((x) & PHY_CTRL1_DISABLE_CLK_GATING_MASK) >> PHY_CTRL1_DISABLE_CLK_GATING_LSB)
#define PHY_CTRL1_DISABLE_CLK_GATING_SET(x)                          (((0 | (x)) << PHY_CTRL1_DISABLE_CLK_GATING_LSB) & PHY_CTRL1_DISABLE_CLK_GATING_MASK)
#define PHY_CTRL1_DISABLE_CLK_GATING_RESET                           0
#define PHY_CTRL1_ENABLE_REFCLK_GATE_MSB                             26
#define PHY_CTRL1_ENABLE_REFCLK_GATE_LSB                             26
#define PHY_CTRL1_ENABLE_REFCLK_GATE_MASK                            0x04000000
#define PHY_CTRL1_ENABLE_REFCLK_GATE_GET(x)                          (((x) & PHY_CTRL1_ENABLE_REFCLK_GATE_MASK) >> PHY_CTRL1_ENABLE_REFCLK_GATE_LSB)
#define PHY_CTRL1_ENABLE_REFCLK_GATE_SET(x)                          (((0 | (x)) << PHY_CTRL1_ENABLE_REFCLK_GATE_LSB) & PHY_CTRL1_ENABLE_REFCLK_GATE_MASK)
#define PHY_CTRL1_ENABLE_REFCLK_GATE_RESET                           1
#define PHY_CTRL1_CLKOBS_SEL_MSB                                     25
#define PHY_CTRL1_CLKOBS_SEL_LSB                                     23
#define PHY_CTRL1_CLKOBS_SEL_MASK                                    0x03800000
#define PHY_CTRL1_CLKOBS_SEL_GET(x)                                  (((x) & PHY_CTRL1_CLKOBS_SEL_MASK) >> PHY_CTRL1_CLKOBS_SEL_LSB)
#define PHY_CTRL1_CLKOBS_SEL_SET(x)                                  (((0 | (x)) << PHY_CTRL1_CLKOBS_SEL_LSB) & PHY_CTRL1_CLKOBS_SEL_MASK)
#define PHY_CTRL1_CLKOBS_SEL_RESET                                   0
#define PHY_CTRL1_USE_PLL_LOCK_DLY_SEL_MSB                           22
#define PHY_CTRL1_USE_PLL_LOCK_DLY_SEL_LSB                           21
#define PHY_CTRL1_USE_PLL_LOCK_DLY_SEL_MASK                          0x00600000
#define PHY_CTRL1_USE_PLL_LOCK_DLY_SEL_GET(x)                        (((x) & PHY_CTRL1_USE_PLL_LOCK_DLY_SEL_MASK) >> PHY_CTRL1_USE_PLL_LOCK_DLY_SEL_LSB)
#define PHY_CTRL1_USE_PLL_LOCK_DLY_SEL_SET(x)                        (((0 | (x)) << PHY_CTRL1_USE_PLL_LOCK_DLY_SEL_LSB) & PHY_CTRL1_USE_PLL_LOCK_DLY_SEL_MASK)
#define PHY_CTRL1_USE_PLL_LOCK_DLY_SEL_RESET                         3
#define PHY_CTRL1_USE_PLL_LOCKDETECT_MSB                             20
#define PHY_CTRL1_USE_PLL_LOCKDETECT_LSB                             20
#define PHY_CTRL1_USE_PLL_LOCKDETECT_MASK                            0x00100000
#define PHY_CTRL1_USE_PLL_LOCKDETECT_GET(x)                          (((x) & PHY_CTRL1_USE_PLL_LOCKDETECT_MASK) >> PHY_CTRL1_USE_PLL_LOCKDETECT_LSB)
#define PHY_CTRL1_USE_PLL_LOCKDETECT_SET(x)                          (((0 | (x)) << PHY_CTRL1_USE_PLL_LOCKDETECT_LSB) & PHY_CTRL1_USE_PLL_LOCKDETECT_MASK)
#define PHY_CTRL1_USE_PLL_LOCKDETECT_RESET                           0
#define PHY_CTRL1_TX_PATTERN_SEL_MSB                                 19
#define PHY_CTRL1_TX_PATTERN_SEL_LSB                                 18
#define PHY_CTRL1_TX_PATTERN_SEL_MASK                                0x000c0000
#define PHY_CTRL1_TX_PATTERN_SEL_GET(x)                              (((x) & PHY_CTRL1_TX_PATTERN_SEL_MASK) >> PHY_CTRL1_TX_PATTERN_SEL_LSB)
#define PHY_CTRL1_TX_PATTERN_SEL_SET(x)                              (((0 | (x)) << PHY_CTRL1_TX_PATTERN_SEL_LSB) & PHY_CTRL1_TX_PATTERN_SEL_MASK)
#define PHY_CTRL1_TX_PATTERN_SEL_RESET                               0
#define PHY_CTRL1_FORCE_SUSPEND_MSB                                  13
#define PHY_CTRL1_FORCE_SUSPEND_LSB                                  13
#define PHY_CTRL1_FORCE_SUSPEND_MASK                                 0x00002000
#define PHY_CTRL1_FORCE_SUSPEND_GET(x)                               (((x) & PHY_CTRL1_FORCE_SUSPEND_MASK) >> PHY_CTRL1_FORCE_SUSPEND_LSB)
#define PHY_CTRL1_FORCE_SUSPEND_SET(x)                               (((0 | (x)) << PHY_CTRL1_FORCE_SUSPEND_LSB) & PHY_CTRL1_FORCE_SUSPEND_MASK)
#define PHY_CTRL1_FORCE_SUSPEND_RESET                                1
#define PHY_CTRL1_NO_PLL_PWD_MSB                                     12
#define PHY_CTRL1_NO_PLL_PWD_LSB                                     12
#define PHY_CTRL1_NO_PLL_PWD_MASK                                    0x00001000
#define PHY_CTRL1_NO_PLL_PWD_GET(x)                                  (((x) & PHY_CTRL1_NO_PLL_PWD_MASK) >> PHY_CTRL1_NO_PLL_PWD_LSB)
#define PHY_CTRL1_NO_PLL_PWD_SET(x)                                  (((0 | (x)) << PHY_CTRL1_NO_PLL_PWD_LSB) & PHY_CTRL1_NO_PLL_PWD_MASK)
#define PHY_CTRL1_NO_PLL_PWD_RESET                                   0
#define PHY_CTRL1_RX_RSVD_MSB                                        11
#define PHY_CTRL1_RX_RSVD_LSB                                        9
#define PHY_CTRL1_RX_RSVD_MASK                                       0x00000e00
#define PHY_CTRL1_RX_RSVD_GET(x)                                     (((x) & PHY_CTRL1_RX_RSVD_MASK) >> PHY_CTRL1_RX_RSVD_LSB)
#define PHY_CTRL1_RX_RSVD_SET(x)                                     (((0 | (x)) << PHY_CTRL1_RX_RSVD_LSB) & PHY_CTRL1_RX_RSVD_MASK)
#define PHY_CTRL1_RX_RSVD_RESET                                      0
#define PHY_CTRL1_RX_SELVREF0P25_MSB                                 8
#define PHY_CTRL1_RX_SELVREF0P25_LSB                                 8
#define PHY_CTRL1_RX_SELVREF0P25_MASK                                0x00000100
#define PHY_CTRL1_RX_SELVREF0P25_GET(x)                              (((x) & PHY_CTRL1_RX_SELVREF0P25_MASK) >> PHY_CTRL1_RX_SELVREF0P25_LSB)
#define PHY_CTRL1_RX_SELVREF0P25_SET(x)                              (((0 | (x)) << PHY_CTRL1_RX_SELVREF0P25_LSB) & PHY_CTRL1_RX_SELVREF0P25_MASK)
#define PHY_CTRL1_RX_SELVREF0P25_RESET                               0
#define PHY_CTRL1_RX_SELVREF0P6_MSB                                  7
#define PHY_CTRL1_RX_SELVREF0P6_LSB                                  7
#define PHY_CTRL1_RX_SELVREF0P6_MASK                                 0x00000080
#define PHY_CTRL1_RX_SELVREF0P6_GET(x)                               (((x) & PHY_CTRL1_RX_SELVREF0P6_MASK) >> PHY_CTRL1_RX_SELVREF0P6_LSB)
#define PHY_CTRL1_RX_SELVREF0P6_SET(x)                               (((0 | (x)) << PHY_CTRL1_RX_SELVREF0P6_LSB) & PHY_CTRL1_RX_SELVREF0P6_MASK)
#define PHY_CTRL1_RX_SELVREF0P6_RESET                                1
#define PHY_CTRL1_RX_SELIR_100M_MSB                                  6
#define PHY_CTRL1_RX_SELIR_100M_LSB                                  5
#define PHY_CTRL1_RX_SELIR_100M_MASK                                 0x00000060
#define PHY_CTRL1_RX_SELIR_100M_GET(x)                               (((x) & PHY_CTRL1_RX_SELIR_100M_MASK) >> PHY_CTRL1_RX_SELIR_100M_LSB)
#define PHY_CTRL1_RX_SELIR_100M_SET(x)                               (((0 | (x)) << PHY_CTRL1_RX_SELIR_100M_LSB) & PHY_CTRL1_RX_SELIR_100M_MASK)
#define PHY_CTRL1_RX_SELIR_100M_RESET                                0
#define PHY_CTRL1_RX_LOWR_PDET_MSB                                   4
#define PHY_CTRL1_RX_LOWR_PDET_LSB                                   4
#define PHY_CTRL1_RX_LOWR_PDET_MASK                                  0x00000010
#define PHY_CTRL1_RX_LOWR_PDET_GET(x)                                (((x) & PHY_CTRL1_RX_LOWR_PDET_MASK) >> PHY_CTRL1_RX_LOWR_PDET_LSB)
#define PHY_CTRL1_RX_LOWR_PDET_SET(x)                                (((0 | (x)) << PHY_CTRL1_RX_LOWR_PDET_LSB) & PHY_CTRL1_RX_LOWR_PDET_MASK)
#define PHY_CTRL1_RX_LOWR_PDET_RESET                                 1
#define PHY_CTRL1_RX_BYPASSEQ_MSB                                    3
#define PHY_CTRL1_RX_BYPASSEQ_LSB                                    3
#define PHY_CTRL1_RX_BYPASSEQ_MASK                                   0x00000008
#define PHY_CTRL1_RX_BYPASSEQ_GET(x)                                 (((x) & PHY_CTRL1_RX_BYPASSEQ_MASK) >> PHY_CTRL1_RX_BYPASSEQ_LSB)
#define PHY_CTRL1_RX_BYPASSEQ_SET(x)                                 (((0 | (x)) << PHY_CTRL1_RX_BYPASSEQ_LSB) & PHY_CTRL1_RX_BYPASSEQ_MASK)
#define PHY_CTRL1_RX_BYPASSEQ_RESET                                  0
#define PHY_CTRL1_RX_FORCERXON_MSB                                   2
#define PHY_CTRL1_RX_FORCERXON_LSB                                   2
#define PHY_CTRL1_RX_FORCERXON_MASK                                  0x00000004
#define PHY_CTRL1_RX_FORCERXON_GET(x)                                (((x) & PHY_CTRL1_RX_FORCERXON_MASK) >> PHY_CTRL1_RX_FORCERXON_LSB)
#define PHY_CTRL1_RX_FORCERXON_SET(x)                                (((0 | (x)) << PHY_CTRL1_RX_FORCERXON_LSB) & PHY_CTRL1_RX_FORCERXON_MASK)
#define PHY_CTRL1_RX_FORCERXON_RESET                                 1
#define PHY_CTRL1_RX_FILBW_SEL_MSB                                   1
#define PHY_CTRL1_RX_FILBW_SEL_LSB                                   0
#define PHY_CTRL1_RX_FILBW_SEL_MASK                                  0x00000003
#define PHY_CTRL1_RX_FILBW_SEL_GET(x)                                (((x) & PHY_CTRL1_RX_FILBW_SEL_MASK) >> PHY_CTRL1_RX_FILBW_SEL_LSB)
#define PHY_CTRL1_RX_FILBW_SEL_SET(x)                                (((0 | (x)) << PHY_CTRL1_RX_FILBW_SEL_LSB) & PHY_CTRL1_RX_FILBW_SEL_MASK)
#define PHY_CTRL1_RX_FILBW_SEL_RESET                                 1
#define PHY_CTRL1_ADDRESS                                            0x0004
#define PHY_CTRL1_HW_MASK                                            0xbffc3fff
#define PHY_CTRL1_SW_MASK                                            0xbffc3fff
#define PHY_CTRL1_HW_WRITE_MASK                                      0x00000000
#define PHY_CTRL1_SW_WRITE_MASK                                      0xbffc3fff
#define PHY_CTRL1_RSTMASK                                            0xffffffff
#define PHY_CTRL1_RESET                                              0xa4602095

// 0x0008 (PHY_CTRL2)
#define PHY_CTRL2_PWD_EXTBIAS_MSB                                    31
#define PHY_CTRL2_PWD_EXTBIAS_LSB                                    31
#define PHY_CTRL2_PWD_EXTBIAS_MASK                                   0x80000000
#define PHY_CTRL2_PWD_EXTBIAS_GET(x)                                 (((x) & PHY_CTRL2_PWD_EXTBIAS_MASK) >> PHY_CTRL2_PWD_EXTBIAS_LSB)
#define PHY_CTRL2_PWD_EXTBIAS_SET(x)                                 (((0 | (x)) << PHY_CTRL2_PWD_EXTBIAS_LSB) & PHY_CTRL2_PWD_EXTBIAS_MASK)
#define PHY_CTRL2_PWD_EXTBIAS_RESET                                  0
#define PHY_CTRL2_TX_RSVD_MSB                                        30
#define PHY_CTRL2_TX_RSVD_LSB                                        27
#define PHY_CTRL2_TX_RSVD_MASK                                       0x78000000
#define PHY_CTRL2_TX_RSVD_GET(x)                                     (((x) & PHY_CTRL2_TX_RSVD_MASK) >> PHY_CTRL2_TX_RSVD_LSB)
#define PHY_CTRL2_TX_RSVD_SET(x)                                     (((0 | (x)) << PHY_CTRL2_TX_RSVD_LSB) & PHY_CTRL2_TX_RSVD_MASK)
#define PHY_CTRL2_TX_RSVD_RESET                                      0
#define PHY_CTRL2_TX_LCKDET_OVR_MSB                                  26
#define PHY_CTRL2_TX_LCKDET_OVR_LSB                                  26
#define PHY_CTRL2_TX_LCKDET_OVR_MASK                                 0x04000000
#define PHY_CTRL2_TX_LCKDET_OVR_GET(x)                               (((x) & PHY_CTRL2_TX_LCKDET_OVR_MASK) >> PHY_CTRL2_TX_LCKDET_OVR_LSB)
#define PHY_CTRL2_TX_LCKDET_OVR_SET(x)                               (((0 | (x)) << PHY_CTRL2_TX_LCKDET_OVR_LSB) & PHY_CTRL2_TX_LCKDET_OVR_MASK)
#define PHY_CTRL2_TX_LCKDET_OVR_RESET                                0
#define PHY_CTRL2_TX_MAN_CAL_MSB                                     25
#define PHY_CTRL2_TX_MAN_CAL_LSB                                     22
#define PHY_CTRL2_TX_MAN_CAL_MASK                                    0x03c00000
#define PHY_CTRL2_TX_MAN_CAL_GET(x)                                  (((x) & PHY_CTRL2_TX_MAN_CAL_MASK) >> PHY_CTRL2_TX_MAN_CAL_LSB)
#define PHY_CTRL2_TX_MAN_CAL_SET(x)                                  (((0 | (x)) << PHY_CTRL2_TX_MAN_CAL_LSB) & PHY_CTRL2_TX_MAN_CAL_MASK)
#define PHY_CTRL2_TX_MAN_CAL_RESET                                   3
#define PHY_CTRL2_TX_CAL_SEL_MSB                                     21
#define PHY_CTRL2_TX_CAL_SEL_LSB                                     21
#define PHY_CTRL2_TX_CAL_SEL_MASK                                    0x00200000
#define PHY_CTRL2_TX_CAL_SEL_GET(x)                                  (((x) & PHY_CTRL2_TX_CAL_SEL_MASK) >> PHY_CTRL2_TX_CAL_SEL_LSB)
#define PHY_CTRL2_TX_CAL_SEL_SET(x)                                  (((0 | (x)) << PHY_CTRL2_TX_CAL_SEL_LSB) & PHY_CTRL2_TX_CAL_SEL_MASK)
#define PHY_CTRL2_TX_CAL_SEL_RESET                                   1
#define PHY_CTRL2_TX_CAL_EN_MSB                                      20
#define PHY_CTRL2_TX_CAL_EN_LSB                                      20
#define PHY_CTRL2_TX_CAL_EN_MASK                                     0x00100000
#define PHY_CTRL2_TX_CAL_EN_GET(x)                                   (((x) & PHY_CTRL2_TX_CAL_EN_MASK) >> PHY_CTRL2_TX_CAL_EN_LSB)
#define PHY_CTRL2_TX_CAL_EN_SET(x)                                   (((0 | (x)) << PHY_CTRL2_TX_CAL_EN_LSB) & PHY_CTRL2_TX_CAL_EN_MASK)
#define PHY_CTRL2_TX_CAL_EN_RESET                                    1
#define PHY_CTRL2_PWD_ISP_MSB                                        13
#define PHY_CTRL2_PWD_ISP_LSB                                        8
#define PHY_CTRL2_PWD_ISP_MASK                                       0x00003f00
#define PHY_CTRL2_PWD_ISP_GET(x)                                     (((x) & PHY_CTRL2_PWD_ISP_MASK) >> PHY_CTRL2_PWD_ISP_LSB)
#define PHY_CTRL2_PWD_ISP_SET(x)                                     (((0 | (x)) << PHY_CTRL2_PWD_ISP_LSB) & PHY_CTRL2_PWD_ISP_MASK)
#define PHY_CTRL2_PWD_ISP_RESET                                      27
#define PHY_CTRL2_PWD_IPLL_MSB                                       7
#define PHY_CTRL2_PWD_IPLL_LSB                                       2
#define PHY_CTRL2_PWD_IPLL_MASK                                      0x000000fc
#define PHY_CTRL2_PWD_IPLL_GET(x)                                    (((x) & PHY_CTRL2_PWD_IPLL_MASK) >> PHY_CTRL2_PWD_IPLL_LSB)
#define PHY_CTRL2_PWD_IPLL_SET(x)                                    (((0 | (x)) << PHY_CTRL2_PWD_IPLL_LSB) & PHY_CTRL2_PWD_IPLL_MASK)
#define PHY_CTRL2_PWD_IPLL_RESET                                     27
#define PHY_CTRL2_HSRXPHASE_PS_EN_MSB                                1
#define PHY_CTRL2_HSRXPHASE_PS_EN_LSB                                1
#define PHY_CTRL2_HSRXPHASE_PS_EN_MASK                               0x00000002
#define PHY_CTRL2_HSRXPHASE_PS_EN_GET(x)                             (((x) & PHY_CTRL2_HSRXPHASE_PS_EN_MASK) >> PHY_CTRL2_HSRXPHASE_PS_EN_LSB)
#define PHY_CTRL2_HSRXPHASE_PS_EN_SET(x)                             (((0 | (x)) << PHY_CTRL2_HSRXPHASE_PS_EN_LSB) & PHY_CTRL2_HSRXPHASE_PS_EN_MASK)
#define PHY_CTRL2_HSRXPHASE_PS_EN_RESET                              0
#define PHY_CTRL2_HSTXBIAS_PS_EN_MSB                                 0
#define PHY_CTRL2_HSTXBIAS_PS_EN_LSB                                 0
#define PHY_CTRL2_HSTXBIAS_PS_EN_MASK                                0x00000001
#define PHY_CTRL2_HSTXBIAS_PS_EN_GET(x)                              (((x) & PHY_CTRL2_HSTXBIAS_PS_EN_MASK) >> PHY_CTRL2_HSTXBIAS_PS_EN_LSB)
#define PHY_CTRL2_HSTXBIAS_PS_EN_SET(x)                              (((0 | (x)) << PHY_CTRL2_HSTXBIAS_PS_EN_LSB) & PHY_CTRL2_HSTXBIAS_PS_EN_MASK)
#define PHY_CTRL2_HSTXBIAS_PS_EN_RESET                               0
#define PHY_CTRL2_ADDRESS                                            0x0008
#define PHY_CTRL2_HW_MASK                                            0xfff03fff
#define PHY_CTRL2_SW_MASK                                            0xfff03fff
#define PHY_CTRL2_HW_WRITE_MASK                                      0x00000000
#define PHY_CTRL2_SW_WRITE_MASK                                      0xfff03fff
#define PHY_CTRL2_RSTMASK                                            0xffffffff
#define PHY_CTRL2_RESET                                              0x00f01b6c

// 0x000c (PHY_CTRL3)
#define PHY_CTRL3_TX_STARTCAL_MSB                                    25
#define PHY_CTRL3_TX_STARTCAL_LSB                                    25
#define PHY_CTRL3_TX_STARTCAL_MASK                                   0x02000000
#define PHY_CTRL3_TX_STARTCAL_GET(x)                                 (((x) & PHY_CTRL3_TX_STARTCAL_MASK) >> PHY_CTRL3_TX_STARTCAL_LSB)
#define PHY_CTRL3_TX_STARTCAL_SET(x)                                 (((0 | (x)) << PHY_CTRL3_TX_STARTCAL_LSB) & PHY_CTRL3_TX_STARTCAL_MASK)
#define PHY_CTRL3_TX_STARTCAL_RESET                                  0
#define PHY_CTRL3_TX_SELTEST_MSB                                     24
#define PHY_CTRL3_TX_SELTEST_LSB                                     22
#define PHY_CTRL3_TX_SELTEST_MASK                                    0x01c00000
#define PHY_CTRL3_TX_SELTEST_GET(x)                                  (((x) & PHY_CTRL3_TX_SELTEST_MASK) >> PHY_CTRL3_TX_SELTEST_LSB)
#define PHY_CTRL3_TX_SELTEST_SET(x)                                  (((0 | (x)) << PHY_CTRL3_TX_SELTEST_LSB) & PHY_CTRL3_TX_SELTEST_MASK)
#define PHY_CTRL3_TX_SELTEST_RESET                                   0
#define PHY_CTRL3_TX_DISABLE_SHORT_DET_MSB                           21
#define PHY_CTRL3_TX_DISABLE_SHORT_DET_LSB                           21
#define PHY_CTRL3_TX_DISABLE_SHORT_DET_MASK                          0x00200000
#define PHY_CTRL3_TX_DISABLE_SHORT_DET_GET(x)                        (((x) & PHY_CTRL3_TX_DISABLE_SHORT_DET_MASK) >> PHY_CTRL3_TX_DISABLE_SHORT_DET_LSB)
#define PHY_CTRL3_TX_DISABLE_SHORT_DET_SET(x)                        (((0 | (x)) << PHY_CTRL3_TX_DISABLE_SHORT_DET_LSB) & PHY_CTRL3_TX_DISABLE_SHORT_DET_MASK)
#define PHY_CTRL3_TX_DISABLE_SHORT_DET_RESET                         0
#define PHY_CTRL3_PWD_ITX_MSB                                        18
#define PHY_CTRL3_PWD_ITX_LSB                                        0
#define PHY_CTRL3_PWD_ITX_MASK                                       0x0007ffff
#define PHY_CTRL3_PWD_ITX_GET(x)                                     (((x) & PHY_CTRL3_PWD_ITX_MASK) >> PHY_CTRL3_PWD_ITX_LSB)
#define PHY_CTRL3_PWD_ITX_SET(x)                                     (((0 | (x)) << PHY_CTRL3_PWD_ITX_LSB) & PHY_CTRL3_PWD_ITX_MASK)
#define PHY_CTRL3_PWD_ITX_RESET                                      83813
#define PHY_CTRL3_ADDRESS                                            0x000c
#define PHY_CTRL3_HW_MASK                                            0x03e7ffff
#define PHY_CTRL3_SW_MASK                                            0x03e7ffff
#define PHY_CTRL3_HW_WRITE_MASK                                      0x00000000
#define PHY_CTRL3_SW_WRITE_MASK                                      0x03e7ffff
#define PHY_CTRL3_RSTMASK                                            0xffffffff
#define PHY_CTRL3_RESET                                              0x00014765

// 0x0010 (PHY_CTRL4)
#define PHY_CTRL4_PWD_IRX_MSB                                        11
#define PHY_CTRL4_PWD_IRX_LSB                                        0
#define PHY_CTRL4_PWD_IRX_MASK                                       0x00000fff
#define PHY_CTRL4_PWD_IRX_GET(x)                                     (((x) & PHY_CTRL4_PWD_IRX_MASK) >> PHY_CTRL4_PWD_IRX_LSB)
#define PHY_CTRL4_PWD_IRX_SET(x)                                     (((0 | (x)) << PHY_CTRL4_PWD_IRX_LSB) & PHY_CTRL4_PWD_IRX_MASK)
#define PHY_CTRL4_PWD_IRX_RESET                                      1757
#define PHY_CTRL4_ADDRESS                                            0x0010
#define PHY_CTRL4_HW_MASK                                            0x00000fff
#define PHY_CTRL4_SW_MASK                                            0x00000fff
#define PHY_CTRL4_HW_WRITE_MASK                                      0x00000000
#define PHY_CTRL4_SW_WRITE_MASK                                      0x00000fff
#define PHY_CTRL4_RSTMASK                                            0xffffffff
#define PHY_CTRL4_RESET                                              0x000006dd

// 0x0014 (PHY_CTRL5)
#define PHY_CTRL5_HSIC_EXTEND_IDLE_EN_MSB                            30
#define PHY_CTRL5_HSIC_EXTEND_IDLE_EN_LSB                            30
#define PHY_CTRL5_HSIC_EXTEND_IDLE_EN_MASK                           0x40000000
#define PHY_CTRL5_HSIC_EXTEND_IDLE_EN_GET(x)                         (((x) & PHY_CTRL5_HSIC_EXTEND_IDLE_EN_MASK) >> PHY_CTRL5_HSIC_EXTEND_IDLE_EN_LSB)
#define PHY_CTRL5_HSIC_EXTEND_IDLE_EN_SET(x)                         (((0 | (x)) << PHY_CTRL5_HSIC_EXTEND_IDLE_EN_LSB) & PHY_CTRL5_HSIC_EXTEND_IDLE_EN_MASK)
#define PHY_CTRL5_HSIC_EXTEND_IDLE_EN_RESET                          0
#define PHY_CTRL5_HSIC_MODE_MSB                                      29
#define PHY_CTRL5_HSIC_MODE_LSB                                      29
#define PHY_CTRL5_HSIC_MODE_MASK                                     0x20000000
#define PHY_CTRL5_HSIC_MODE_GET(x)                                   (((x) & PHY_CTRL5_HSIC_MODE_MASK) >> PHY_CTRL5_HSIC_MODE_LSB)
#define PHY_CTRL5_HSIC_MODE_SET(x)                                   (((0 | (x)) << PHY_CTRL5_HSIC_MODE_LSB) & PHY_CTRL5_HSIC_MODE_MASK)
#define PHY_CTRL5_HSIC_MODE_RESET                                    0
#define PHY_CTRL5_HOST_DISCON_SAMPLE_WIDTH_MSB                       28
#define PHY_CTRL5_HOST_DISCON_SAMPLE_WIDTH_LSB                       26
#define PHY_CTRL5_HOST_DISCON_SAMPLE_WIDTH_MASK                      0x1c000000
#define PHY_CTRL5_HOST_DISCON_SAMPLE_WIDTH_GET(x)                    (((x) & PHY_CTRL5_HOST_DISCON_SAMPLE_WIDTH_MASK) >> PHY_CTRL5_HOST_DISCON_SAMPLE_WIDTH_LSB)
#define PHY_CTRL5_HOST_DISCON_SAMPLE_WIDTH_SET(x)                    (((0 | (x)) << PHY_CTRL5_HOST_DISCON_SAMPLE_WIDTH_LSB) & PHY_CTRL5_HOST_DISCON_SAMPLE_WIDTH_MASK)
#define PHY_CTRL5_HOST_DISCON_SAMPLE_WIDTH_RESET                     6
#define PHY_CTRL5_HOST_DISCON_DETECT_ON_MSB                          25
#define PHY_CTRL5_HOST_DISCON_DETECT_ON_LSB                          25
#define PHY_CTRL5_HOST_DISCON_DETECT_ON_MASK                         0x02000000
#define PHY_CTRL5_HOST_DISCON_DETECT_ON_GET(x)                       (((x) & PHY_CTRL5_HOST_DISCON_DETECT_ON_MASK) >> PHY_CTRL5_HOST_DISCON_DETECT_ON_LSB)
#define PHY_CTRL5_HOST_DISCON_DETECT_ON_SET(x)                       (((0 | (x)) << PHY_CTRL5_HOST_DISCON_DETECT_ON_LSB) & PHY_CTRL5_HOST_DISCON_DETECT_ON_MASK)
#define PHY_CTRL5_HOST_DISCON_DETECT_ON_RESET                        1
#define PHY_CTRL5_HOST_DISCON_FIX_ON_MSB                             24
#define PHY_CTRL5_HOST_DISCON_FIX_ON_LSB                             24
#define PHY_CTRL5_HOST_DISCON_FIX_ON_MASK                            0x01000000
#define PHY_CTRL5_HOST_DISCON_FIX_ON_GET(x)                          (((x) & PHY_CTRL5_HOST_DISCON_FIX_ON_MASK) >> PHY_CTRL5_HOST_DISCON_FIX_ON_LSB)
#define PHY_CTRL5_HOST_DISCON_FIX_ON_SET(x)                          (((0 | (x)) << PHY_CTRL5_HOST_DISCON_FIX_ON_LSB) & PHY_CTRL5_HOST_DISCON_FIX_ON_MASK)
#define PHY_CTRL5_HOST_DISCON_FIX_ON_RESET                           1
#define PHY_CTRL5_DM_PULLDOWN_MSB                                    23
#define PHY_CTRL5_DM_PULLDOWN_LSB                                    23
#define PHY_CTRL5_DM_PULLDOWN_MASK                                   0x00800000
#define PHY_CTRL5_DM_PULLDOWN_GET(x)                                 (((x) & PHY_CTRL5_DM_PULLDOWN_MASK) >> PHY_CTRL5_DM_PULLDOWN_LSB)
#define PHY_CTRL5_DM_PULLDOWN_SET(x)                                 (((0 | (x)) << PHY_CTRL5_DM_PULLDOWN_LSB) & PHY_CTRL5_DM_PULLDOWN_MASK)
#define PHY_CTRL5_DM_PULLDOWN_RESET                                  0
#define PHY_CTRL5_DP_PULLDOWN_MSB                                    22
#define PHY_CTRL5_DP_PULLDOWN_LSB                                    22
#define PHY_CTRL5_DP_PULLDOWN_MASK                                   0x00400000
#define PHY_CTRL5_DP_PULLDOWN_GET(x)                                 (((x) & PHY_CTRL5_DP_PULLDOWN_MASK) >> PHY_CTRL5_DP_PULLDOWN_LSB)
#define PHY_CTRL5_DP_PULLDOWN_SET(x)                                 (((0 | (x)) << PHY_CTRL5_DP_PULLDOWN_LSB) & PHY_CTRL5_DP_PULLDOWN_MASK)
#define PHY_CTRL5_DP_PULLDOWN_RESET                                  0
#define PHY_CTRL5_SUSPEND_N_MSB                                      21
#define PHY_CTRL5_SUSPEND_N_LSB                                      21
#define PHY_CTRL5_SUSPEND_N_MASK                                     0x00200000
#define PHY_CTRL5_SUSPEND_N_GET(x)                                   (((x) & PHY_CTRL5_SUSPEND_N_MASK) >> PHY_CTRL5_SUSPEND_N_LSB)
#define PHY_CTRL5_SUSPEND_N_SET(x)                                   (((0 | (x)) << PHY_CTRL5_SUSPEND_N_LSB) & PHY_CTRL5_SUSPEND_N_MASK)
#define PHY_CTRL5_SUSPEND_N_RESET                                    1
#define PHY_CTRL5_TERM_SEL_MSB                                       20
#define PHY_CTRL5_TERM_SEL_LSB                                       20
#define PHY_CTRL5_TERM_SEL_MASK                                      0x00100000
#define PHY_CTRL5_TERM_SEL_GET(x)                                    (((x) & PHY_CTRL5_TERM_SEL_MASK) >> PHY_CTRL5_TERM_SEL_LSB)
#define PHY_CTRL5_TERM_SEL_SET(x)                                    (((0 | (x)) << PHY_CTRL5_TERM_SEL_LSB) & PHY_CTRL5_TERM_SEL_MASK)
#define PHY_CTRL5_TERM_SEL_RESET                                     0
#define PHY_CTRL5_XCVR_SEL_MSB                                       19
#define PHY_CTRL5_XCVR_SEL_LSB                                       18
#define PHY_CTRL5_XCVR_SEL_MASK                                      0x000c0000
#define PHY_CTRL5_XCVR_SEL_GET(x)                                    (((x) & PHY_CTRL5_XCVR_SEL_MASK) >> PHY_CTRL5_XCVR_SEL_LSB)
#define PHY_CTRL5_XCVR_SEL_SET(x)                                    (((0 | (x)) << PHY_CTRL5_XCVR_SEL_LSB) & PHY_CTRL5_XCVR_SEL_MASK)
#define PHY_CTRL5_XCVR_SEL_RESET                                     0
#define PHY_CTRL5_TEST_JK_OVERRIDE_MSB                               17
#define PHY_CTRL5_TEST_JK_OVERRIDE_LSB                               17
#define PHY_CTRL5_TEST_JK_OVERRIDE_MASK                              0x00020000
#define PHY_CTRL5_TEST_JK_OVERRIDE_GET(x)                            (((x) & PHY_CTRL5_TEST_JK_OVERRIDE_MASK) >> PHY_CTRL5_TEST_JK_OVERRIDE_LSB)
#define PHY_CTRL5_TEST_JK_OVERRIDE_SET(x)                            (((0 | (x)) << PHY_CTRL5_TEST_JK_OVERRIDE_LSB) & PHY_CTRL5_TEST_JK_OVERRIDE_MASK)
#define PHY_CTRL5_TEST_JK_OVERRIDE_RESET                             0
#define PHY_CTRL5_FORCE_TEST_SE0_NAK_MSB                             16
#define PHY_CTRL5_FORCE_TEST_SE0_NAK_LSB                             16
#define PHY_CTRL5_FORCE_TEST_SE0_NAK_MASK                            0x00010000
#define PHY_CTRL5_FORCE_TEST_SE0_NAK_GET(x)                          (((x) & PHY_CTRL5_FORCE_TEST_SE0_NAK_MASK) >> PHY_CTRL5_FORCE_TEST_SE0_NAK_LSB)
#define PHY_CTRL5_FORCE_TEST_SE0_NAK_SET(x)                          (((0 | (x)) << PHY_CTRL5_FORCE_TEST_SE0_NAK_LSB) & PHY_CTRL5_FORCE_TEST_SE0_NAK_MASK)
#define PHY_CTRL5_FORCE_TEST_SE0_NAK_RESET                           0
#define PHY_CTRL5_FORCE_TEST_K_MSB                                   15
#define PHY_CTRL5_FORCE_TEST_K_LSB                                   15
#define PHY_CTRL5_FORCE_TEST_K_MASK                                  0x00008000
#define PHY_CTRL5_FORCE_TEST_K_GET(x)                                (((x) & PHY_CTRL5_FORCE_TEST_K_MASK) >> PHY_CTRL5_FORCE_TEST_K_LSB)
#define PHY_CTRL5_FORCE_TEST_K_SET(x)                                (((0 | (x)) << PHY_CTRL5_FORCE_TEST_K_LSB) & PHY_CTRL5_FORCE_TEST_K_MASK)
#define PHY_CTRL5_FORCE_TEST_K_RESET                                 0
#define PHY_CTRL5_FORCE_TEST_J_MSB                                   14
#define PHY_CTRL5_FORCE_TEST_J_LSB                                   14
#define PHY_CTRL5_FORCE_TEST_J_MASK                                  0x00004000
#define PHY_CTRL5_FORCE_TEST_J_GET(x)                                (((x) & PHY_CTRL5_FORCE_TEST_J_MASK) >> PHY_CTRL5_FORCE_TEST_J_LSB)
#define PHY_CTRL5_FORCE_TEST_J_SET(x)                                (((0 | (x)) << PHY_CTRL5_FORCE_TEST_J_LSB) & PHY_CTRL5_FORCE_TEST_J_MASK)
#define PHY_CTRL5_FORCE_TEST_J_RESET                                 0
#define PHY_CTRL5_FORCE_IDDQ_MSB                                     13
#define PHY_CTRL5_FORCE_IDDQ_LSB                                     13
#define PHY_CTRL5_FORCE_IDDQ_MASK                                    0x00002000
#define PHY_CTRL5_FORCE_IDDQ_GET(x)                                  (((x) & PHY_CTRL5_FORCE_IDDQ_MASK) >> PHY_CTRL5_FORCE_IDDQ_LSB)
#define PHY_CTRL5_FORCE_IDDQ_SET(x)                                  (((0 | (x)) << PHY_CTRL5_FORCE_IDDQ_LSB) & PHY_CTRL5_FORCE_IDDQ_MASK)
#define PHY_CTRL5_FORCE_IDDQ_RESET                                   1
#define PHY_CTRL5_EB_WATERMARK_MSB                                   12
#define PHY_CTRL5_EB_WATERMARK_LSB                                   7
#define PHY_CTRL5_EB_WATERMARK_MASK                                  0x00001f80
#define PHY_CTRL5_EB_WATERMARK_GET(x)                                (((x) & PHY_CTRL5_EB_WATERMARK_MASK) >> PHY_CTRL5_EB_WATERMARK_LSB)
#define PHY_CTRL5_EB_WATERMARK_SET(x)                                (((0 | (x)) << PHY_CTRL5_EB_WATERMARK_LSB) & PHY_CTRL5_EB_WATERMARK_MASK)
#define PHY_CTRL5_EB_WATERMARK_RESET                                 20
#define PHY_CTRL5_TX_BIAS_DELAY_MSB                                  6
#define PHY_CTRL5_TX_BIAS_DELAY_LSB                                  0
#define PHY_CTRL5_TX_BIAS_DELAY_MASK                                 0x0000007f
#define PHY_CTRL5_TX_BIAS_DELAY_GET(x)                               (((x) & PHY_CTRL5_TX_BIAS_DELAY_MASK) >> PHY_CTRL5_TX_BIAS_DELAY_LSB)
#define PHY_CTRL5_TX_BIAS_DELAY_SET(x)                               (((0 | (x)) << PHY_CTRL5_TX_BIAS_DELAY_LSB) & PHY_CTRL5_TX_BIAS_DELAY_MASK)
#define PHY_CTRL5_TX_BIAS_DELAY_RESET                                50
#define PHY_CTRL5_ADDRESS                                            0x0014
#define PHY_CTRL5_HW_MASK                                            0x7fffffff
#define PHY_CTRL5_SW_MASK                                            0x7fffffff
#define PHY_CTRL5_HW_WRITE_MASK                                      0x00000000
#define PHY_CTRL5_SW_WRITE_MASK                                      0x7fffffff
#define PHY_CTRL5_RSTMASK                                            0xffffffff
#define PHY_CTRL5_RESET                                              0x1b202a32

// 0x0018 (PHY_CTRL6)
#define PHY_CTRL6_IDDIG_MSB                                          4
#define PHY_CTRL6_IDDIG_LSB                                          4
#define PHY_CTRL6_IDDIG_MASK                                         0x00000010
#define PHY_CTRL6_IDDIG_GET(x)                                       (((x) & PHY_CTRL6_IDDIG_MASK) >> PHY_CTRL6_IDDIG_LSB)
#define PHY_CTRL6_IDDIG_SET(x)                                       (((0 | (x)) << PHY_CTRL6_IDDIG_LSB) & PHY_CTRL6_IDDIG_MASK)
#define PHY_CTRL6_IDDIG_RESET                                        0
#define PHY_CTRL6_SESSEND_MSB                                        3
#define PHY_CTRL6_SESSEND_LSB                                        3
#define PHY_CTRL6_SESSEND_MASK                                       0x00000008
#define PHY_CTRL6_SESSEND_GET(x)                                     (((x) & PHY_CTRL6_SESSEND_MASK) >> PHY_CTRL6_SESSEND_LSB)
#define PHY_CTRL6_SESSEND_SET(x)                                     (((0 | (x)) << PHY_CTRL6_SESSEND_LSB) & PHY_CTRL6_SESSEND_MASK)
#define PHY_CTRL6_SESSEND_RESET                                      0
#define PHY_CTRL6_VBUSVALID_MSB                                      2
#define PHY_CTRL6_VBUSVALID_LSB                                      2
#define PHY_CTRL6_VBUSVALID_MASK                                     0x00000004
#define PHY_CTRL6_VBUSVALID_GET(x)                                   (((x) & PHY_CTRL6_VBUSVALID_MASK) >> PHY_CTRL6_VBUSVALID_LSB)
#define PHY_CTRL6_VBUSVALID_SET(x)                                   (((0 | (x)) << PHY_CTRL6_VBUSVALID_LSB) & PHY_CTRL6_VBUSVALID_MASK)
#define PHY_CTRL6_VBUSVALID_RESET                                    1
#define PHY_CTRL6_BVALID_MSB                                         1
#define PHY_CTRL6_BVALID_LSB                                         1
#define PHY_CTRL6_BVALID_MASK                                        0x00000002
#define PHY_CTRL6_BVALID_GET(x)                                      (((x) & PHY_CTRL6_BVALID_MASK) >> PHY_CTRL6_BVALID_LSB)
#define PHY_CTRL6_BVALID_SET(x)                                      (((0 | (x)) << PHY_CTRL6_BVALID_LSB) & PHY_CTRL6_BVALID_MASK)
#define PHY_CTRL6_BVALID_RESET                                       1
#define PHY_CTRL6_AVALID_MSB                                         0
#define PHY_CTRL6_AVALID_LSB                                         0
#define PHY_CTRL6_AVALID_MASK                                        0x00000001
#define PHY_CTRL6_AVALID_GET(x)                                      (((x) & PHY_CTRL6_AVALID_MASK) >> PHY_CTRL6_AVALID_LSB)
#define PHY_CTRL6_AVALID_SET(x)                                      (((0 | (x)) << PHY_CTRL6_AVALID_LSB) & PHY_CTRL6_AVALID_MASK)
#define PHY_CTRL6_AVALID_RESET                                       1
#define PHY_CTRL6_ADDRESS                                            0x0018
#define PHY_CTRL6_HW_MASK                                            0x0000001f
#define PHY_CTRL6_SW_MASK                                            0x0000001f
#define PHY_CTRL6_HW_WRITE_MASK                                      0x00000000
#define PHY_CTRL6_SW_WRITE_MASK                                      0x0000001f
#define PHY_CTRL6_RSTMASK                                            0xffffffff
#define PHY_CTRL6_RESET                                              0x00000007

// 0x001c (PHY_STATUS)
#define PHY_STATUS_CLK_USABLE_MSB                                    4
#define PHY_STATUS_CLK_USABLE_LSB                                    4
#define PHY_STATUS_CLK_USABLE_MASK                                   0x00000010
#define PHY_STATUS_CLK_USABLE_GET(x)                                 (((x) & PHY_STATUS_CLK_USABLE_MASK) >> PHY_STATUS_CLK_USABLE_LSB)
#define PHY_STATUS_CLK_USABLE_SET(x)                                 (((0 | (x)) << PHY_STATUS_CLK_USABLE_LSB) & PHY_STATUS_CLK_USABLE_MASK)
#define PHY_STATUS_CLK_USABLE_RESET                                  0
#define PHY_STATUS_TX_CAL_MSB                                        3
#define PHY_STATUS_TX_CAL_LSB                                        0
#define PHY_STATUS_TX_CAL_MASK                                       0x0000000f
#define PHY_STATUS_TX_CAL_GET(x)                                     (((x) & PHY_STATUS_TX_CAL_MASK) >> PHY_STATUS_TX_CAL_LSB)
#define PHY_STATUS_TX_CAL_SET(x)                                     (((0 | (x)) << PHY_STATUS_TX_CAL_LSB) & PHY_STATUS_TX_CAL_MASK)
#define PHY_STATUS_TX_CAL_RESET                                      0
#define PHY_STATUS_ADDRESS                                           0x001c
#define PHY_STATUS_HW_MASK                                           0x0000001f
#define PHY_STATUS_SW_MASK                                           0x0000001f
#define PHY_STATUS_HW_WRITE_MASK                                     0x0000001f
#define PHY_STATUS_SW_WRITE_MASK                                     0x00000000
#define PHY_STATUS_RSTMASK                                           0xffffffff
#define PHY_STATUS_RESET                                             0x00000000

// 0x0020 (DEBUG)
#define DEBUG_SEL_MSB                                                3
#define DEBUG_SEL_LSB                                                0
#define DEBUG_SEL_MASK                                               0x0000000f
#define DEBUG_SEL_GET(x)                                             (((x) & DEBUG_SEL_MASK) >> DEBUG_SEL_LSB)
#define DEBUG_SEL_SET(x)                                             (((0 | (x)) << DEBUG_SEL_LSB) & DEBUG_SEL_MASK)
#define DEBUG_SEL_RESET                                              0
#define DEBUG_ADDRESS                                                0x0020
#define DEBUG_HW_MASK                                                0x0000000f
#define DEBUG_SW_MASK                                                0x0000000f
#define DEBUG_HW_WRITE_MASK                                          0x00000000
#define DEBUG_SW_WRITE_MASK                                          0x0000000f
#define DEBUG_RSTMASK                                                0xffffffff
#define DEBUG_RESET                                                  0x00000000


#endif /* _UTM_REG_CSR_H_ */
