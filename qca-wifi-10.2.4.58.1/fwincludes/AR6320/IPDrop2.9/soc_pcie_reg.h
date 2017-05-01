//                                                                             
// File:       ./soc_pcie_reg.h                                                
// Creator:    ctsai                                                           
// Time:       Thursday May 17, 2012 [1:50:54 pm]                              
//                                                                             
// Path:       /trees/ctsai/ctsai-merlin/chips/rome/dev/rtl/wlan/pcie_wrap/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -ch -Wdesc -I                 
//             /trees/ctsai/ctsai-merlin/chips/rome/dev/blueprint/sysconfig    
//             soc_pcie_reg.rdl                                                
//                                                                             
// Sources:    /trees/ctsai/ctsai-merlin/chips/rome/dev/rtl/wlan/pcie_wrap/blueprint/soc_pcie_reg.rdl
//             /trees/ctsai/ctsai-merlin/chips/rome/dev/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    zydasc14                                                        
// OS:         Linux 2.6.9-78.0.8.ELsmp                                        
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _SOC_PCIE_REG_H_
#define _SOC_PCIE_REG_H_
// 32'h0000 (PCIE_DEBUG_LOW)
#define PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_MSB                       31
#define PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_LSB                       0
#define PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_MASK                      0xffffffff
#define PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_GET(x)                    (((x) & PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_MASK) >> PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_LSB)
#define PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_SET(x)                    (((x) << PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_LSB) & PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_MASK)
#define PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_RESET                     0x0 // 0
#define PCIE_DEBUG_LOW_ADDRESS                                       0x0000
#define PCIE_DEBUG_LOW_OFFSET                                        0x0000
// SW modifiable bits
#define PCIE_DEBUG_LOW_SW_MASK                                       0xffffffff
// bits defined at reset
#define PCIE_DEBUG_LOW_RSTMASK                                       0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_DEBUG_LOW_RESET                                         0x00000000

// 32'h0004 (PCIE_DEBUG_HIGH)
#define PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_MSB                     31
#define PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_LSB                     0
#define PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_MASK                    0xffffffff
#define PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_GET(x)                  (((x) & PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_MASK) >> PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_LSB)
#define PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_SET(x)                  (((x) << PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_LSB) & PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_MASK)
#define PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_RESET                   0x0 // 0
#define PCIE_DEBUG_HIGH_ADDRESS                                      0x0004
#define PCIE_DEBUG_HIGH_OFFSET                                       0x0004
// SW modifiable bits
#define PCIE_DEBUG_HIGH_SW_MASK                                      0xffffffff
// bits defined at reset
#define PCIE_DEBUG_HIGH_RSTMASK                                      0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_DEBUG_HIGH_RESET                                        0x00000000

// 32'h0008 (PCIE_PM)
#define PCIE_PM_WAKE_MSB                                             25
#define PCIE_PM_WAKE_LSB                                             25
#define PCIE_PM_WAKE_MASK                                            0x02000000
#define PCIE_PM_WAKE_GET(x)                                          (((x) & PCIE_PM_WAKE_MASK) >> PCIE_PM_WAKE_LSB)
#define PCIE_PM_WAKE_SET(x)                                          (((x) << PCIE_PM_WAKE_LSB) & PCIE_PM_WAKE_MASK)
#define PCIE_PM_WAKE_RESET                                           0x0 // 0
#define PCIE_PM_XMLH_L1_EXIT_MSB                                     24
#define PCIE_PM_XMLH_L1_EXIT_LSB                                     24
#define PCIE_PM_XMLH_L1_EXIT_MASK                                    0x01000000
#define PCIE_PM_XMLH_L1_EXIT_GET(x)                                  (((x) & PCIE_PM_XMLH_L1_EXIT_MASK) >> PCIE_PM_XMLH_L1_EXIT_LSB)
#define PCIE_PM_XMLH_L1_EXIT_SET(x)                                  (((x) << PCIE_PM_XMLH_L1_EXIT_LSB) & PCIE_PM_XMLH_L1_EXIT_MASK)
#define PCIE_PM_XMLH_L1_EXIT_RESET                                   0x0 // 0
#define PCIE_PM_LINK_REQ_RST_N_MSB                                   23
#define PCIE_PM_LINK_REQ_RST_N_LSB                                   23
#define PCIE_PM_LINK_REQ_RST_N_MASK                                  0x00800000
#define PCIE_PM_LINK_REQ_RST_N_GET(x)                                (((x) & PCIE_PM_LINK_REQ_RST_N_MASK) >> PCIE_PM_LINK_REQ_RST_N_LSB)
#define PCIE_PM_LINK_REQ_RST_N_SET(x)                                (((x) << PCIE_PM_LINK_REQ_RST_N_LSB) & PCIE_PM_LINK_REQ_RST_N_MASK)
#define PCIE_PM_LINK_REQ_RST_N_RESET                                 0x0 // 0
#define PCIE_PM_RDLH_LINK_UP_MSB                                     22
#define PCIE_PM_RDLH_LINK_UP_LSB                                     22
#define PCIE_PM_RDLH_LINK_UP_MASK                                    0x00400000
#define PCIE_PM_RDLH_LINK_UP_GET(x)                                  (((x) & PCIE_PM_RDLH_LINK_UP_MASK) >> PCIE_PM_RDLH_LINK_UP_LSB)
#define PCIE_PM_RDLH_LINK_UP_SET(x)                                  (((x) << PCIE_PM_RDLH_LINK_UP_LSB) & PCIE_PM_RDLH_LINK_UP_MASK)
#define PCIE_PM_RDLH_LINK_UP_RESET                                   0x0 // 0
#define PCIE_PM_MASTER_STATE_MSB                                     21
#define PCIE_PM_MASTER_STATE_LSB                                     17
#define PCIE_PM_MASTER_STATE_MASK                                    0x003e0000
#define PCIE_PM_MASTER_STATE_GET(x)                                  (((x) & PCIE_PM_MASTER_STATE_MASK) >> PCIE_PM_MASTER_STATE_LSB)
#define PCIE_PM_MASTER_STATE_SET(x)                                  (((x) << PCIE_PM_MASTER_STATE_LSB) & PCIE_PM_MASTER_STATE_MASK)
#define PCIE_PM_MASTER_STATE_RESET                                   0x0 // 0
#define PCIE_PM_PME_EN_MSB                                           16
#define PCIE_PM_PME_EN_LSB                                           16
#define PCIE_PM_PME_EN_MASK                                          0x00010000
#define PCIE_PM_PME_EN_GET(x)                                        (((x) & PCIE_PM_PME_EN_MASK) >> PCIE_PM_PME_EN_LSB)
#define PCIE_PM_PME_EN_SET(x)                                        (((x) << PCIE_PM_PME_EN_LSB) & PCIE_PM_PME_EN_MASK)
#define PCIE_PM_PME_EN_RESET                                         0x0 // 0
#define PCIE_PM_AUX_PM_EN_MSB                                        15
#define PCIE_PM_AUX_PM_EN_LSB                                        15
#define PCIE_PM_AUX_PM_EN_MASK                                       0x00008000
#define PCIE_PM_AUX_PM_EN_GET(x)                                     (((x) & PCIE_PM_AUX_PM_EN_MASK) >> PCIE_PM_AUX_PM_EN_LSB)
#define PCIE_PM_AUX_PM_EN_SET(x)                                     (((x) << PCIE_PM_AUX_PM_EN_LSB) & PCIE_PM_AUX_PM_EN_MASK)
#define PCIE_PM_AUX_PM_EN_RESET                                      0x0 // 0
#define PCIE_PM_XTLH_BLOCK_TLP_MSB                                   14
#define PCIE_PM_XTLH_BLOCK_TLP_LSB                                   14
#define PCIE_PM_XTLH_BLOCK_TLP_MASK                                  0x00004000
#define PCIE_PM_XTLH_BLOCK_TLP_GET(x)                                (((x) & PCIE_PM_XTLH_BLOCK_TLP_MASK) >> PCIE_PM_XTLH_BLOCK_TLP_LSB)
#define PCIE_PM_XTLH_BLOCK_TLP_SET(x)                                (((x) << PCIE_PM_XTLH_BLOCK_TLP_LSB) & PCIE_PM_XTLH_BLOCK_TLP_MASK)
#define PCIE_PM_XTLH_BLOCK_TLP_RESET                                 0x0 // 0
#define PCIE_PM_DSTATE_MSB                                           13
#define PCIE_PM_DSTATE_LSB                                           11
#define PCIE_PM_DSTATE_MASK                                          0x00003800
#define PCIE_PM_DSTATE_GET(x)                                        (((x) & PCIE_PM_DSTATE_MASK) >> PCIE_PM_DSTATE_LSB)
#define PCIE_PM_DSTATE_SET(x)                                        (((x) << PCIE_PM_DSTATE_LSB) & PCIE_PM_DSTATE_MASK)
#define PCIE_PM_DSTATE_RESET                                         0x0 // 0
#define PCIE_PM_LTSSM_STATE_MSB                                      10
#define PCIE_PM_LTSSM_STATE_LSB                                      5
#define PCIE_PM_LTSSM_STATE_MASK                                     0x000007e0
#define PCIE_PM_LTSSM_STATE_GET(x)                                   (((x) & PCIE_PM_LTSSM_STATE_MASK) >> PCIE_PM_LTSSM_STATE_LSB)
#define PCIE_PM_LTSSM_STATE_SET(x)                                   (((x) << PCIE_PM_LTSSM_STATE_LSB) & PCIE_PM_LTSSM_STATE_MASK)
#define PCIE_PM_LTSSM_STATE_RESET                                    0x0 // 0
#define PCIE_PM_STATUS_MSB                                           4
#define PCIE_PM_STATUS_LSB                                           4
#define PCIE_PM_STATUS_MASK                                          0x00000010
#define PCIE_PM_STATUS_GET(x)                                        (((x) & PCIE_PM_STATUS_MASK) >> PCIE_PM_STATUS_LSB)
#define PCIE_PM_STATUS_SET(x)                                        (((x) << PCIE_PM_STATUS_LSB) & PCIE_PM_STATUS_MASK)
#define PCIE_PM_STATUS_RESET                                         0x0 // 0
#define PCIE_PM_XMLH_LINK_UP_MSB                                     3
#define PCIE_PM_XMLH_LINK_UP_LSB                                     3
#define PCIE_PM_XMLH_LINK_UP_MASK                                    0x00000008
#define PCIE_PM_XMLH_LINK_UP_GET(x)                                  (((x) & PCIE_PM_XMLH_LINK_UP_MASK) >> PCIE_PM_XMLH_LINK_UP_LSB)
#define PCIE_PM_XMLH_LINK_UP_SET(x)                                  (((x) << PCIE_PM_XMLH_LINK_UP_LSB) & PCIE_PM_XMLH_LINK_UP_MASK)
#define PCIE_PM_XMLH_LINK_UP_RESET                                   0x0 // 0
#define PCIE_PM_CURNT_STATE_MSB                                      2
#define PCIE_PM_CURNT_STATE_LSB                                      0
#define PCIE_PM_CURNT_STATE_MASK                                     0x00000007
#define PCIE_PM_CURNT_STATE_GET(x)                                   (((x) & PCIE_PM_CURNT_STATE_MASK) >> PCIE_PM_CURNT_STATE_LSB)
#define PCIE_PM_CURNT_STATE_SET(x)                                   (((x) << PCIE_PM_CURNT_STATE_LSB) & PCIE_PM_CURNT_STATE_MASK)
#define PCIE_PM_CURNT_STATE_RESET                                    0x0 // 0
#define PCIE_PM_ADDRESS                                              0x0008
#define PCIE_PM_OFFSET                                               0x0008
// SW modifiable bits
#define PCIE_PM_SW_MASK                                              0x03ffffff
// bits defined at reset
#define PCIE_PM_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_PM_RESET                                                0x00000000

// 32'h000c (PCIE_CTRL)
#define PCIE_CTRL_IGNORE_AXI_PCIE_L1_MSB                             16
#define PCIE_CTRL_IGNORE_AXI_PCIE_L1_LSB                             16
#define PCIE_CTRL_IGNORE_AXI_PCIE_L1_MASK                            0x00010000
#define PCIE_CTRL_IGNORE_AXI_PCIE_L1_GET(x)                          (((x) & PCIE_CTRL_IGNORE_AXI_PCIE_L1_MASK) >> PCIE_CTRL_IGNORE_AXI_PCIE_L1_LSB)
#define PCIE_CTRL_IGNORE_AXI_PCIE_L1_SET(x)                          (((x) << PCIE_CTRL_IGNORE_AXI_PCIE_L1_LSB) & PCIE_CTRL_IGNORE_AXI_PCIE_L1_MASK)
#define PCIE_CTRL_IGNORE_AXI_PCIE_L1_RESET                           0x0 // 0
#define PCIE_CTRL_IGNORE_MAC_FOR_L1_MSB                              15
#define PCIE_CTRL_IGNORE_MAC_FOR_L1_LSB                              15
#define PCIE_CTRL_IGNORE_MAC_FOR_L1_MASK                             0x00008000
#define PCIE_CTRL_IGNORE_MAC_FOR_L1_GET(x)                           (((x) & PCIE_CTRL_IGNORE_MAC_FOR_L1_MASK) >> PCIE_CTRL_IGNORE_MAC_FOR_L1_LSB)
#define PCIE_CTRL_IGNORE_MAC_FOR_L1_SET(x)                           (((x) << PCIE_CTRL_IGNORE_MAC_FOR_L1_LSB) & PCIE_CTRL_IGNORE_MAC_FOR_L1_MASK)
#define PCIE_CTRL_IGNORE_MAC_FOR_L1_RESET                            0x0 // 0
#define PCIE_CTRL_TARGET_L1_EN_MSB                                   14
#define PCIE_CTRL_TARGET_L1_EN_LSB                                   14
#define PCIE_CTRL_TARGET_L1_EN_MASK                                  0x00004000
#define PCIE_CTRL_TARGET_L1_EN_GET(x)                                (((x) & PCIE_CTRL_TARGET_L1_EN_MASK) >> PCIE_CTRL_TARGET_L1_EN_LSB)
#define PCIE_CTRL_TARGET_L1_EN_SET(x)                                (((x) << PCIE_CTRL_TARGET_L1_EN_LSB) & PCIE_CTRL_TARGET_L1_EN_MASK)
#define PCIE_CTRL_TARGET_L1_EN_RESET                                 0x0 // 0
#define PCIE_CTRL_HOST_L1_EN_MSB                                     13
#define PCIE_CTRL_HOST_L1_EN_LSB                                     13
#define PCIE_CTRL_HOST_L1_EN_MASK                                    0x00002000
#define PCIE_CTRL_HOST_L1_EN_GET(x)                                  (((x) & PCIE_CTRL_HOST_L1_EN_MASK) >> PCIE_CTRL_HOST_L1_EN_LSB)
#define PCIE_CTRL_HOST_L1_EN_SET(x)                                  (((x) << PCIE_CTRL_HOST_L1_EN_LSB) & PCIE_CTRL_HOST_L1_EN_MASK)
#define PCIE_CTRL_HOST_L1_EN_RESET                                   0x0 // 0
#define PCIE_CTRL_TRAINING_RST_EN_MSB                                12
#define PCIE_CTRL_TRAINING_RST_EN_LSB                                12
#define PCIE_CTRL_TRAINING_RST_EN_MASK                               0x00001000
#define PCIE_CTRL_TRAINING_RST_EN_GET(x)                             (((x) & PCIE_CTRL_TRAINING_RST_EN_MASK) >> PCIE_CTRL_TRAINING_RST_EN_LSB)
#define PCIE_CTRL_TRAINING_RST_EN_SET(x)                             (((x) << PCIE_CTRL_TRAINING_RST_EN_LSB) & PCIE_CTRL_TRAINING_RST_EN_MASK)
#define PCIE_CTRL_TRAINING_RST_EN_RESET                              0x0 // 0
#define PCIE_CTRL_RDLH_LINK_RST_EN_MSB                               11
#define PCIE_CTRL_RDLH_LINK_RST_EN_LSB                               11
#define PCIE_CTRL_RDLH_LINK_RST_EN_MASK                              0x00000800
#define PCIE_CTRL_RDLH_LINK_RST_EN_GET(x)                            (((x) & PCIE_CTRL_RDLH_LINK_RST_EN_MASK) >> PCIE_CTRL_RDLH_LINK_RST_EN_LSB)
#define PCIE_CTRL_RDLH_LINK_RST_EN_SET(x)                            (((x) << PCIE_CTRL_RDLH_LINK_RST_EN_LSB) & PCIE_CTRL_RDLH_LINK_RST_EN_MASK)
#define PCIE_CTRL_RDLH_LINK_RST_EN_RESET                             0x0 // 0
#define PCIE_CTRL_LINK_REQ_RST_EN_MSB                                10
#define PCIE_CTRL_LINK_REQ_RST_EN_LSB                                10
#define PCIE_CTRL_LINK_REQ_RST_EN_MASK                               0x00000400
#define PCIE_CTRL_LINK_REQ_RST_EN_GET(x)                             (((x) & PCIE_CTRL_LINK_REQ_RST_EN_MASK) >> PCIE_CTRL_LINK_REQ_RST_EN_LSB)
#define PCIE_CTRL_LINK_REQ_RST_EN_SET(x)                             (((x) << PCIE_CTRL_LINK_REQ_RST_EN_LSB) & PCIE_CTRL_LINK_REQ_RST_EN_MASK)
#define PCIE_CTRL_LINK_REQ_RST_EN_RESET                              0x0 // 0
#define PCIE_CTRL_XMLH_LINK_RST_EN_MSB                               9
#define PCIE_CTRL_XMLH_LINK_RST_EN_LSB                               9
#define PCIE_CTRL_XMLH_LINK_RST_EN_MASK                              0x00000200
#define PCIE_CTRL_XMLH_LINK_RST_EN_GET(x)                            (((x) & PCIE_CTRL_XMLH_LINK_RST_EN_MASK) >> PCIE_CTRL_XMLH_LINK_RST_EN_LSB)
#define PCIE_CTRL_XMLH_LINK_RST_EN_SET(x)                            (((x) << PCIE_CTRL_XMLH_LINK_RST_EN_LSB) & PCIE_CTRL_XMLH_LINK_RST_EN_MASK)
#define PCIE_CTRL_XMLH_LINK_RST_EN_RESET                             0x1 // 1
#define PCIE_CTRL_APP_LTSSM_ENABLE_MSB                               8
#define PCIE_CTRL_APP_LTSSM_ENABLE_LSB                               8
#define PCIE_CTRL_APP_LTSSM_ENABLE_MASK                              0x00000100
#define PCIE_CTRL_APP_LTSSM_ENABLE_GET(x)                            (((x) & PCIE_CTRL_APP_LTSSM_ENABLE_MASK) >> PCIE_CTRL_APP_LTSSM_ENABLE_LSB)
#define PCIE_CTRL_APP_LTSSM_ENABLE_SET(x)                            (((x) << PCIE_CTRL_APP_LTSSM_ENABLE_LSB) & PCIE_CTRL_APP_LTSSM_ENABLE_MASK)
#define PCIE_CTRL_APP_LTSSM_ENABLE_RESET                             0x0 // 0
#define PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_MSB                    7
#define PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_LSB                    7
#define PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_MASK                   0x00000080
#define PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_GET(x)                 (((x) & PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_MASK) >> PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_LSB)
#define PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_SET(x)                 (((x) << PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_LSB) & PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_MASK)
#define PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_RESET                  0x0 // 0
#define PCIE_CTRL_SYS_AUX_PWR_DET_MSB                                6
#define PCIE_CTRL_SYS_AUX_PWR_DET_LSB                                6
#define PCIE_CTRL_SYS_AUX_PWR_DET_MASK                               0x00000040
#define PCIE_CTRL_SYS_AUX_PWR_DET_GET(x)                             (((x) & PCIE_CTRL_SYS_AUX_PWR_DET_MASK) >> PCIE_CTRL_SYS_AUX_PWR_DET_LSB)
#define PCIE_CTRL_SYS_AUX_PWR_DET_SET(x)                             (((x) << PCIE_CTRL_SYS_AUX_PWR_DET_LSB) & PCIE_CTRL_SYS_AUX_PWR_DET_MASK)
#define PCIE_CTRL_SYS_AUX_PWR_DET_RESET                              0x0 // 0
#define PCIE_CTRL_D3_TO_L1_DISABLE_EN_MSB                            5
#define PCIE_CTRL_D3_TO_L1_DISABLE_EN_LSB                            5
#define PCIE_CTRL_D3_TO_L1_DISABLE_EN_MASK                           0x00000020
#define PCIE_CTRL_D3_TO_L1_DISABLE_EN_GET(x)                         (((x) & PCIE_CTRL_D3_TO_L1_DISABLE_EN_MASK) >> PCIE_CTRL_D3_TO_L1_DISABLE_EN_LSB)
#define PCIE_CTRL_D3_TO_L1_DISABLE_EN_SET(x)                         (((x) << PCIE_CTRL_D3_TO_L1_DISABLE_EN_LSB) & PCIE_CTRL_D3_TO_L1_DISABLE_EN_MASK)
#define PCIE_CTRL_D3_TO_L1_DISABLE_EN_RESET                          0x0 // 0
#define PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_MSB                       4
#define PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_LSB                       4
#define PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_MASK                      0x00000010
#define PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_GET(x)                    (((x) & PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_MASK) >> PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_LSB)
#define PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_SET(x)                    (((x) << PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_LSB) & PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_MASK)
#define PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_RESET                     0x0 // 0
#define PCIE_CTRL_NO_NAK_WA_EN_MSB                                   3
#define PCIE_CTRL_NO_NAK_WA_EN_LSB                                   3
#define PCIE_CTRL_NO_NAK_WA_EN_MASK                                  0x00000008
#define PCIE_CTRL_NO_NAK_WA_EN_GET(x)                                (((x) & PCIE_CTRL_NO_NAK_WA_EN_MASK) >> PCIE_CTRL_NO_NAK_WA_EN_LSB)
#define PCIE_CTRL_NO_NAK_WA_EN_SET(x)                                (((x) << PCIE_CTRL_NO_NAK_WA_EN_LSB) & PCIE_CTRL_NO_NAK_WA_EN_MASK)
#define PCIE_CTRL_NO_NAK_WA_EN_RESET                                 0x0 // 0
#define PCIE_CTRL_GDATA_WA_EN_MSB                                    2
#define PCIE_CTRL_GDATA_WA_EN_LSB                                    2
#define PCIE_CTRL_GDATA_WA_EN_MASK                                   0x00000004
#define PCIE_CTRL_GDATA_WA_EN_GET(x)                                 (((x) & PCIE_CTRL_GDATA_WA_EN_MASK) >> PCIE_CTRL_GDATA_WA_EN_LSB)
#define PCIE_CTRL_GDATA_WA_EN_SET(x)                                 (((x) << PCIE_CTRL_GDATA_WA_EN_LSB) & PCIE_CTRL_GDATA_WA_EN_MASK)
#define PCIE_CTRL_GDATA_WA_EN_RESET                                  0x1 // 1
#define PCIE_CTRL_TS2_WA_EN_MSB                                      1
#define PCIE_CTRL_TS2_WA_EN_LSB                                      1
#define PCIE_CTRL_TS2_WA_EN_MASK                                     0x00000002
#define PCIE_CTRL_TS2_WA_EN_GET(x)                                   (((x) & PCIE_CTRL_TS2_WA_EN_MASK) >> PCIE_CTRL_TS2_WA_EN_LSB)
#define PCIE_CTRL_TS2_WA_EN_SET(x)                                   (((x) << PCIE_CTRL_TS2_WA_EN_LSB) & PCIE_CTRL_TS2_WA_EN_MASK)
#define PCIE_CTRL_TS2_WA_EN_RESET                                    0x1 // 1
#define PCIE_CTRL_TS1_WA_EN_MSB                                      0
#define PCIE_CTRL_TS1_WA_EN_LSB                                      0
#define PCIE_CTRL_TS1_WA_EN_MASK                                     0x00000001
#define PCIE_CTRL_TS1_WA_EN_GET(x)                                   (((x) & PCIE_CTRL_TS1_WA_EN_MASK) >> PCIE_CTRL_TS1_WA_EN_LSB)
#define PCIE_CTRL_TS1_WA_EN_SET(x)                                   (((x) << PCIE_CTRL_TS1_WA_EN_LSB) & PCIE_CTRL_TS1_WA_EN_MASK)
#define PCIE_CTRL_TS1_WA_EN_RESET                                    0x1 // 1
#define PCIE_CTRL_ADDRESS                                            0x000c
#define PCIE_CTRL_OFFSET                                             0x000c
// SW modifiable bits
#define PCIE_CTRL_SW_MASK                                            0x0001ffff
// bits defined at reset
#define PCIE_CTRL_RSTMASK                                            0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_CTRL_RESET                                              0x00000207

// 32'h0010 (PCIE_NFTS)
#define PCIE_NFTS_CNTL_EN_MSB                                        8
#define PCIE_NFTS_CNTL_EN_LSB                                        8
#define PCIE_NFTS_CNTL_EN_MASK                                       0x00000100
#define PCIE_NFTS_CNTL_EN_GET(x)                                     (((x) & PCIE_NFTS_CNTL_EN_MASK) >> PCIE_NFTS_CNTL_EN_LSB)
#define PCIE_NFTS_CNTL_EN_SET(x)                                     (((x) << PCIE_NFTS_CNTL_EN_LSB) & PCIE_NFTS_CNTL_EN_MASK)
#define PCIE_NFTS_CNTL_EN_RESET                                      0x0 // 0
#define PCIE_NFTS_ADJ_MSB                                            7
#define PCIE_NFTS_ADJ_LSB                                            0
#define PCIE_NFTS_ADJ_MASK                                           0x000000ff
#define PCIE_NFTS_ADJ_GET(x)                                         (((x) & PCIE_NFTS_ADJ_MASK) >> PCIE_NFTS_ADJ_LSB)
#define PCIE_NFTS_ADJ_SET(x)                                         (((x) << PCIE_NFTS_ADJ_LSB) & PCIE_NFTS_ADJ_MASK)
#define PCIE_NFTS_ADJ_RESET                                          0x0 // 0
#define PCIE_NFTS_ADDRESS                                            0x0010
#define PCIE_NFTS_OFFSET                                             0x0010
// SW modifiable bits
#define PCIE_NFTS_SW_MASK                                            0x000001ff
// bits defined at reset
#define PCIE_NFTS_RSTMASK                                            0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_NFTS_RESET                                              0x00000000

// 32'h0014 (PCIE_MSI_STATUS)
#define PCIE_MSI_STATUS_MSI_INT_PENDING_MSB                          24
#define PCIE_MSI_STATUS_MSI_INT_PENDING_LSB                          21
#define PCIE_MSI_STATUS_MSI_INT_PENDING_MASK                         0x01e00000
#define PCIE_MSI_STATUS_MSI_INT_PENDING_GET(x)                       (((x) & PCIE_MSI_STATUS_MSI_INT_PENDING_MASK) >> PCIE_MSI_STATUS_MSI_INT_PENDING_LSB)
#define PCIE_MSI_STATUS_MSI_INT_PENDING_SET(x)                       (((x) << PCIE_MSI_STATUS_MSI_INT_PENDING_LSB) & PCIE_MSI_STATUS_MSI_INT_PENDING_MASK)
#define PCIE_MSI_STATUS_MSI_INT_PENDING_RESET                        0x0 // 0
#define PCIE_MSI_STATUS_MULTI_MSB                                    20
#define PCIE_MSI_STATUS_MULTI_LSB                                    18
#define PCIE_MSI_STATUS_MULTI_MASK                                   0x001c0000
#define PCIE_MSI_STATUS_MULTI_GET(x)                                 (((x) & PCIE_MSI_STATUS_MULTI_MASK) >> PCIE_MSI_STATUS_MULTI_LSB)
#define PCIE_MSI_STATUS_MULTI_SET(x)                                 (((x) << PCIE_MSI_STATUS_MULTI_LSB) & PCIE_MSI_STATUS_MULTI_MASK)
#define PCIE_MSI_STATUS_MULTI_RESET                                  0x0 // 0
#define PCIE_MSI_STATUS__64_BIT_MSB                                  17
#define PCIE_MSI_STATUS__64_BIT_LSB                                  17
#define PCIE_MSI_STATUS__64_BIT_MASK                                 0x00020000
#define PCIE_MSI_STATUS__64_BIT_GET(x)                               (((x) & PCIE_MSI_STATUS__64_BIT_MASK) >> PCIE_MSI_STATUS__64_BIT_LSB)
#define PCIE_MSI_STATUS__64_BIT_SET(x)                               (((x) << PCIE_MSI_STATUS__64_BIT_LSB) & PCIE_MSI_STATUS__64_BIT_MASK)
#define PCIE_MSI_STATUS__64_BIT_RESET                                0x0 // 0
#define PCIE_MSI_STATUS_DATA_MSB                                     16
#define PCIE_MSI_STATUS_DATA_LSB                                     1
#define PCIE_MSI_STATUS_DATA_MASK                                    0x0001fffe
#define PCIE_MSI_STATUS_DATA_GET(x)                                  (((x) & PCIE_MSI_STATUS_DATA_MASK) >> PCIE_MSI_STATUS_DATA_LSB)
#define PCIE_MSI_STATUS_DATA_SET(x)                                  (((x) << PCIE_MSI_STATUS_DATA_LSB) & PCIE_MSI_STATUS_DATA_MASK)
#define PCIE_MSI_STATUS_DATA_RESET                                   0x0 // 0
#define PCIE_MSI_STATUS_EN_MSB                                       0
#define PCIE_MSI_STATUS_EN_LSB                                       0
#define PCIE_MSI_STATUS_EN_MASK                                      0x00000001
#define PCIE_MSI_STATUS_EN_GET(x)                                    (((x) & PCIE_MSI_STATUS_EN_MASK) >> PCIE_MSI_STATUS_EN_LSB)
#define PCIE_MSI_STATUS_EN_SET(x)                                    (((x) << PCIE_MSI_STATUS_EN_LSB) & PCIE_MSI_STATUS_EN_MASK)
#define PCIE_MSI_STATUS_EN_RESET                                     0x0 // 0
#define PCIE_MSI_STATUS_ADDRESS                                      0x0014
#define PCIE_MSI_STATUS_OFFSET                                       0x0014
// SW modifiable bits
#define PCIE_MSI_STATUS_SW_MASK                                      0x01ffffff
// bits defined at reset
#define PCIE_MSI_STATUS_RSTMASK                                      0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_MSI_STATUS_RESET                                        0x00000000

// 32'h0018 (PCIE_MSI_MASK)
#define PCIE_MSI_MASK_VALUE_MSB                                      31
#define PCIE_MSI_MASK_VALUE_LSB                                      0
#define PCIE_MSI_MASK_VALUE_MASK                                     0xffffffff
#define PCIE_MSI_MASK_VALUE_GET(x)                                   (((x) & PCIE_MSI_MASK_VALUE_MASK) >> PCIE_MSI_MASK_VALUE_LSB)
#define PCIE_MSI_MASK_VALUE_SET(x)                                   (((x) << PCIE_MSI_MASK_VALUE_LSB) & PCIE_MSI_MASK_VALUE_MASK)
#define PCIE_MSI_MASK_VALUE_RESET                                    0x0 // 0
#define PCIE_MSI_MASK_ADDRESS                                        0x0018
#define PCIE_MSI_MASK_OFFSET                                         0x0018
// SW modifiable bits
#define PCIE_MSI_MASK_SW_MASK                                        0xffffffff
// bits defined at reset
#define PCIE_MSI_MASK_RSTMASK                                        0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_MSI_MASK_RESET                                          0x00000000

// 32'h001c (PCIE_MSI_ADDR)
#define PCIE_MSI_ADDR_LOW_MSB                                        31
#define PCIE_MSI_ADDR_LOW_LSB                                        0
#define PCIE_MSI_ADDR_LOW_MASK                                       0xffffffff
#define PCIE_MSI_ADDR_LOW_GET(x)                                     (((x) & PCIE_MSI_ADDR_LOW_MASK) >> PCIE_MSI_ADDR_LOW_LSB)
#define PCIE_MSI_ADDR_LOW_SET(x)                                     (((x) << PCIE_MSI_ADDR_LOW_LSB) & PCIE_MSI_ADDR_LOW_MASK)
#define PCIE_MSI_ADDR_LOW_RESET                                      0x0 // 0
#define PCIE_MSI_ADDR_ADDRESS                                        0x001c
#define PCIE_MSI_ADDR_OFFSET                                         0x001c
// SW modifiable bits
#define PCIE_MSI_ADDR_SW_MASK                                        0xffffffff
// bits defined at reset
#define PCIE_MSI_ADDR_RSTMASK                                        0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_MSI_ADDR_RESET                                          0x00000000

// 32'h0020 (PCIE_CO_ERR_CTR0)
#define PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_MSB                            23
#define PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_LSB                            16
#define PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_MASK                           0x00ff0000
#define PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_GET(x)                         (((x) & PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_MASK) >> PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_LSB)
#define PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_SET(x)                         (((x) << PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_LSB) & PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_MASK)
#define PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_RESET                          0x0 // 0
#define PCIE_CO_ERR_CTR0_BAD_TLP_ERR_MSB                             15
#define PCIE_CO_ERR_CTR0_BAD_TLP_ERR_LSB                             8
#define PCIE_CO_ERR_CTR0_BAD_TLP_ERR_MASK                            0x0000ff00
#define PCIE_CO_ERR_CTR0_BAD_TLP_ERR_GET(x)                          (((x) & PCIE_CO_ERR_CTR0_BAD_TLP_ERR_MASK) >> PCIE_CO_ERR_CTR0_BAD_TLP_ERR_LSB)
#define PCIE_CO_ERR_CTR0_BAD_TLP_ERR_SET(x)                          (((x) << PCIE_CO_ERR_CTR0_BAD_TLP_ERR_LSB) & PCIE_CO_ERR_CTR0_BAD_TLP_ERR_MASK)
#define PCIE_CO_ERR_CTR0_BAD_TLP_ERR_RESET                           0x0 // 0
#define PCIE_CO_ERR_CTR0_RCVD_ERR_MSB                                7
#define PCIE_CO_ERR_CTR0_RCVD_ERR_LSB                                0
#define PCIE_CO_ERR_CTR0_RCVD_ERR_MASK                               0x000000ff
#define PCIE_CO_ERR_CTR0_RCVD_ERR_GET(x)                             (((x) & PCIE_CO_ERR_CTR0_RCVD_ERR_MASK) >> PCIE_CO_ERR_CTR0_RCVD_ERR_LSB)
#define PCIE_CO_ERR_CTR0_RCVD_ERR_SET(x)                             (((x) << PCIE_CO_ERR_CTR0_RCVD_ERR_LSB) & PCIE_CO_ERR_CTR0_RCVD_ERR_MASK)
#define PCIE_CO_ERR_CTR0_RCVD_ERR_RESET                              0x0 // 0
#define PCIE_CO_ERR_CTR0_ADDRESS                                     0x0020
#define PCIE_CO_ERR_CTR0_OFFSET                                      0x0020
// SW modifiable bits
#define PCIE_CO_ERR_CTR0_SW_MASK                                     0x00ffffff
// bits defined at reset
#define PCIE_CO_ERR_CTR0_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_CO_ERR_CTR0_RESET                                       0x00000000

// 32'h0024 (PCIE_CO_ERR_CTR1)
#define PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_MSB                         15
#define PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_LSB                         8
#define PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_MASK                        0x0000ff00
#define PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_GET(x)                      (((x) & PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_MASK) >> PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_LSB)
#define PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_SET(x)                      (((x) << PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_LSB) & PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_MASK)
#define PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_RESET                       0x0 // 0
#define PCIE_CO_ERR_CTR1_RPLY_TO_ERR_MSB                             7
#define PCIE_CO_ERR_CTR1_RPLY_TO_ERR_LSB                             0
#define PCIE_CO_ERR_CTR1_RPLY_TO_ERR_MASK                            0x000000ff
#define PCIE_CO_ERR_CTR1_RPLY_TO_ERR_GET(x)                          (((x) & PCIE_CO_ERR_CTR1_RPLY_TO_ERR_MASK) >> PCIE_CO_ERR_CTR1_RPLY_TO_ERR_LSB)
#define PCIE_CO_ERR_CTR1_RPLY_TO_ERR_SET(x)                          (((x) << PCIE_CO_ERR_CTR1_RPLY_TO_ERR_LSB) & PCIE_CO_ERR_CTR1_RPLY_TO_ERR_MASK)
#define PCIE_CO_ERR_CTR1_RPLY_TO_ERR_RESET                           0x0 // 0
#define PCIE_CO_ERR_CTR1_ADDRESS                                     0x0024
#define PCIE_CO_ERR_CTR1_OFFSET                                      0x0024
// SW modifiable bits
#define PCIE_CO_ERR_CTR1_SW_MASK                                     0x0000ffff
// bits defined at reset
#define PCIE_CO_ERR_CTR1_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_CO_ERR_CTR1_RESET                                       0x00000000

// 32'h0028 (PCIE_CO_ERR_CTR_CTRL)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_MSB       9
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_LSB       9
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_MASK      0x00000200
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_GET(x)    (((x) & PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_MASK) >> PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_LSB)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_SET(x)    (((x) << PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_LSB) & PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_MASK)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_RESET     0x0 // 0
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_MSB             8
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_LSB             8
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_MASK            0x00000100
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_GET(x)          (((x) & PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_MASK) >> PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_LSB)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_SET(x)          (((x) << PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_LSB) & PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_MASK)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_RESET           0x0 // 0
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_MSB           7
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_LSB           7
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_MASK          0x00000080
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_GET(x)        (((x) & PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_MASK) >> PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_LSB)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_SET(x)        (((x) << PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_LSB) & PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_MASK)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_RESET         0x0 // 0
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_MSB                 6
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_LSB                 6
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_MASK                0x00000040
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_GET(x)              (((x) & PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_MASK) >> PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_LSB)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_SET(x)              (((x) << PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_LSB) & PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_MASK)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_RESET               0x0 // 0
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_MSB          5
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_LSB          5
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_MASK         0x00000020
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_GET(x)       (((x) & PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_MASK) >> PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_LSB)
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_SET(x)       (((x) << PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_LSB) & PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_MASK)
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_RESET        0x0 // 0
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_MSB                4
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_LSB                4
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_MASK               0x00000010
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_GET(x)             (((x) & PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_MASK) >> PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_LSB)
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_SET(x)             (((x) << PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_LSB) & PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_MASK)
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_RESET              0x0 // 0
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_MSB           3
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_LSB           3
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_MASK          0x00000008
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_GET(x)        (((x) & PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_MASK) >> PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_LSB)
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_SET(x)        (((x) << PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_LSB) & PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_MASK)
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_RESET         0x0 // 0
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_MSB                 2
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_LSB                 2
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_MASK                0x00000004
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_GET(x)              (((x) & PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_MASK) >> PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_LSB)
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_SET(x)              (((x) << PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_LSB) & PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_MASK)
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_RESET               0x0 // 0
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_MSB              1
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_LSB              1
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_MASK             0x00000002
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_GET(x)           (((x) & PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_MASK) >> PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_LSB)
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_SET(x)           (((x) << PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_LSB) & PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_MASK)
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_RESET            0x0 // 0
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_MSB                    0
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_LSB                    0
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_MASK                   0x00000001
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_GET(x)                 (((x) & PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_MASK) >> PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_LSB)
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_SET(x)                 (((x) << PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_LSB) & PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_MASK)
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_RESET                  0x0 // 0
#define PCIE_CO_ERR_CTR_CTRL_ADDRESS                                 0x0028
#define PCIE_CO_ERR_CTR_CTRL_OFFSET                                  0x0028
// SW modifiable bits
#define PCIE_CO_ERR_CTR_CTRL_SW_MASK                                 0x000003ff
// bits defined at reset
#define PCIE_CO_ERR_CTR_CTRL_RSTMASK                                 0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_CO_ERR_CTR_CTRL_RESET                                   0x00000000

// 32'h002c (PCIE_MISC_STATUS)
#define PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_MSB                      9
#define PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_LSB                      9
#define PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_MASK                     0x00000200
#define PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_GET(x)                   (((x) & PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_MASK) >> PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_LSB)
#define PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_SET(x)                   (((x) << PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_LSB) & PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_MASK)
#define PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_RESET                    0x0 // 0
#define PCIE_MISC_STATUS_CFG_RCB_MSB                                 8
#define PCIE_MISC_STATUS_CFG_RCB_LSB                                 8
#define PCIE_MISC_STATUS_CFG_RCB_MASK                                0x00000100
#define PCIE_MISC_STATUS_CFG_RCB_GET(x)                              (((x) & PCIE_MISC_STATUS_CFG_RCB_MASK) >> PCIE_MISC_STATUS_CFG_RCB_LSB)
#define PCIE_MISC_STATUS_CFG_RCB_SET(x)                              (((x) << PCIE_MISC_STATUS_CFG_RCB_LSB) & PCIE_MISC_STATUS_CFG_RCB_MASK)
#define PCIE_MISC_STATUS_CFG_RCB_RESET                               0x0 // 0
#define PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_MSB                    7
#define PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_LSB                    5
#define PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_MASK                   0x000000e0
#define PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_GET(x)                 (((x) & PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_MASK) >> PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_LSB)
#define PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_SET(x)                 (((x) << PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_LSB) & PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_MASK)
#define PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_RESET                  0x0 // 0
#define PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_MSB                     4
#define PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_LSB                     2
#define PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_MASK                    0x0000001c
#define PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_GET(x)                  (((x) & PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_MASK) >> PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_LSB)
#define PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_SET(x)                  (((x) << PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_LSB) & PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_MASK)
#define PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_RESET                   0x0 // 0
#define PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_MSB                        1
#define PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_LSB                        1
#define PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_MASK                       0x00000002
#define PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_GET(x)                     (((x) & PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_MASK) >> PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_LSB)
#define PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_SET(x)                     (((x) << PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_LSB) & PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_MASK)
#define PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_RESET                      0x0 // 0
#define PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_MSB                       0
#define PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_LSB                       0
#define PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_MASK                      0x00000001
#define PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_GET(x)                    (((x) & PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_MASK) >> PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_LSB)
#define PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_SET(x)                    (((x) << PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_LSB) & PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_MASK)
#define PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_RESET                     0x0 // 0
#define PCIE_MISC_STATUS_ADDRESS                                     0x002c
#define PCIE_MISC_STATUS_OFFSET                                      0x002c
// SW modifiable bits
#define PCIE_MISC_STATUS_SW_MASK                                     0x000003ff
// bits defined at reset
#define PCIE_MISC_STATUS_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_MISC_STATUS_RESET                                       0x00000000

// 32'h0030 (PCIE_BAR0_START)
#define PCIE_BAR0_START_VAL_MSB                                      31
#define PCIE_BAR0_START_VAL_LSB                                      0
#define PCIE_BAR0_START_VAL_MASK                                     0xffffffff
#define PCIE_BAR0_START_VAL_GET(x)                                   (((x) & PCIE_BAR0_START_VAL_MASK) >> PCIE_BAR0_START_VAL_LSB)
#define PCIE_BAR0_START_VAL_SET(x)                                   (((x) << PCIE_BAR0_START_VAL_LSB) & PCIE_BAR0_START_VAL_MASK)
#define PCIE_BAR0_START_VAL_RESET                                    0x0 // 0
#define PCIE_BAR0_START_ADDRESS                                      0x0030
#define PCIE_BAR0_START_OFFSET                                       0x0030
// SW modifiable bits
#define PCIE_BAR0_START_SW_MASK                                      0xffffffff
// bits defined at reset
#define PCIE_BAR0_START_RSTMASK                                      0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_BAR0_START_RESET                                        0x00000000

// 32'h0034 (PCIE_BAR0_LIMIT)
#define PCIE_BAR0_LIMIT_VAL_MSB                                      31
#define PCIE_BAR0_LIMIT_VAL_LSB                                      0
#define PCIE_BAR0_LIMIT_VAL_MASK                                     0xffffffff
#define PCIE_BAR0_LIMIT_VAL_GET(x)                                   (((x) & PCIE_BAR0_LIMIT_VAL_MASK) >> PCIE_BAR0_LIMIT_VAL_LSB)
#define PCIE_BAR0_LIMIT_VAL_SET(x)                                   (((x) << PCIE_BAR0_LIMIT_VAL_LSB) & PCIE_BAR0_LIMIT_VAL_MASK)
#define PCIE_BAR0_LIMIT_VAL_RESET                                    0x0 // 0
#define PCIE_BAR0_LIMIT_ADDRESS                                      0x0034
#define PCIE_BAR0_LIMIT_OFFSET                                       0x0034
// SW modifiable bits
#define PCIE_BAR0_LIMIT_SW_MASK                                      0xffffffff
// bits defined at reset
#define PCIE_BAR0_LIMIT_RSTMASK                                      0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_BAR0_LIMIT_RESET                                        0x00000000

// 32'h0038 (AUTOCOMPL)
#define AUTOCOMPL_ENABLE_MSB                                         0
#define AUTOCOMPL_ENABLE_LSB                                         0
#define AUTOCOMPL_ENABLE_MASK                                        0x00000001
#define AUTOCOMPL_ENABLE_GET(x)                                      (((x) & AUTOCOMPL_ENABLE_MASK) >> AUTOCOMPL_ENABLE_LSB)
#define AUTOCOMPL_ENABLE_SET(x)                                      (((x) << AUTOCOMPL_ENABLE_LSB) & AUTOCOMPL_ENABLE_MASK)
#define AUTOCOMPL_ENABLE_RESET                                       0x1 // 1
#define AUTOCOMPL_ADDRESS                                            0x0038
#define AUTOCOMPL_OFFSET                                             0x0038
// SW modifiable bits
#define AUTOCOMPL_SW_MASK                                            0x00000001
// bits defined at reset
#define AUTOCOMPL_RSTMASK                                            0xffffffff
// reset value (ignore bits undefined at reset)
#define AUTOCOMPL_RESET                                              0x00000001

// 32'h003c (NUM_READS_WR_PENDING)
#define NUM_READS_WR_PENDING_V_MSB                                   4
#define NUM_READS_WR_PENDING_V_LSB                                   0
#define NUM_READS_WR_PENDING_V_MASK                                  0x0000001f
#define NUM_READS_WR_PENDING_V_GET(x)                                (((x) & NUM_READS_WR_PENDING_V_MASK) >> NUM_READS_WR_PENDING_V_LSB)
#define NUM_READS_WR_PENDING_V_SET(x)                                (((x) << NUM_READS_WR_PENDING_V_LSB) & NUM_READS_WR_PENDING_V_MASK)
#define NUM_READS_WR_PENDING_V_RESET                                 0x8 // 8
#define NUM_READS_WR_PENDING_ADDRESS                                 0x003c
#define NUM_READS_WR_PENDING_OFFSET                                  0x003c
// SW modifiable bits
#define NUM_READS_WR_PENDING_SW_MASK                                 0x0000001f
// bits defined at reset
#define NUM_READS_WR_PENDING_RSTMASK                                 0xffffffff
// reset value (ignore bits undefined at reset)
#define NUM_READS_WR_PENDING_RESET                                   0x00000008

// 32'h0040 (LOW_POWER_INT_ENABLE)
#define LOW_POWER_INT_ENABLE_DATA_MSB                                2
#define LOW_POWER_INT_ENABLE_DATA_LSB                                0
#define LOW_POWER_INT_ENABLE_DATA_MASK                               0x00000007
#define LOW_POWER_INT_ENABLE_DATA_GET(x)                             (((x) & LOW_POWER_INT_ENABLE_DATA_MASK) >> LOW_POWER_INT_ENABLE_DATA_LSB)
#define LOW_POWER_INT_ENABLE_DATA_SET(x)                             (((x) << LOW_POWER_INT_ENABLE_DATA_LSB) & LOW_POWER_INT_ENABLE_DATA_MASK)
#define LOW_POWER_INT_ENABLE_DATA_RESET                              0x0 // 0
#define LOW_POWER_INT_ENABLE_ADDRESS                                 0x0040
#define LOW_POWER_INT_ENABLE_OFFSET                                  0x0040
// SW modifiable bits
#define LOW_POWER_INT_ENABLE_SW_MASK                                 0x00000007
// bits defined at reset
#define LOW_POWER_INT_ENABLE_RSTMASK                                 0xffffffff
// reset value (ignore bits undefined at reset)
#define LOW_POWER_INT_ENABLE_RESET                                   0x00000000

// 32'h0044 (LOW_POWER_INT_MASK)
#define LOW_POWER_INT_MASK_DATA_MSB                                  2
#define LOW_POWER_INT_MASK_DATA_LSB                                  0
#define LOW_POWER_INT_MASK_DATA_MASK                                 0x00000007
#define LOW_POWER_INT_MASK_DATA_GET(x)                               (((x) & LOW_POWER_INT_MASK_DATA_MASK) >> LOW_POWER_INT_MASK_DATA_LSB)
#define LOW_POWER_INT_MASK_DATA_SET(x)                               (((x) << LOW_POWER_INT_MASK_DATA_LSB) & LOW_POWER_INT_MASK_DATA_MASK)
#define LOW_POWER_INT_MASK_DATA_RESET                                0x0 // 0
#define LOW_POWER_INT_MASK_ADDRESS                                   0x0044
#define LOW_POWER_INT_MASK_OFFSET                                    0x0044
// SW modifiable bits
#define LOW_POWER_INT_MASK_SW_MASK                                   0x00000007
// bits defined at reset
#define LOW_POWER_INT_MASK_RSTMASK                                   0xffffffff
// reset value (ignore bits undefined at reset)
#define LOW_POWER_INT_MASK_RESET                                     0x00000000

// 32'h0048 (LOW_POWER_INT_STATUS)
#define LOW_POWER_INT_STATUS_DATA_MSB                                2
#define LOW_POWER_INT_STATUS_DATA_LSB                                0
#define LOW_POWER_INT_STATUS_DATA_MASK                               0x00000007
#define LOW_POWER_INT_STATUS_DATA_GET(x)                             (((x) & LOW_POWER_INT_STATUS_DATA_MASK) >> LOW_POWER_INT_STATUS_DATA_LSB)
#define LOW_POWER_INT_STATUS_DATA_SET(x)                             (((x) << LOW_POWER_INT_STATUS_DATA_LSB) & LOW_POWER_INT_STATUS_DATA_MASK)
#define LOW_POWER_INT_STATUS_DATA_RESET                              0x0 // 0
#define LOW_POWER_INT_STATUS_ADDRESS                                 0x0048
#define LOW_POWER_INT_STATUS_OFFSET                                  0x0048
// SW modifiable bits
#define LOW_POWER_INT_STATUS_SW_MASK                                 0x00000007
// bits defined at reset
#define LOW_POWER_INT_STATUS_RSTMASK                                 0xffffffff
// reset value (ignore bits undefined at reset)
#define LOW_POWER_INT_STATUS_RESET                                   0x00000000

// 32'h004c (LTR_CFG)
#define LTR_CFG_LTR_ENABLE_MSB                                       31
#define LTR_CFG_LTR_ENABLE_LSB                                       31
#define LTR_CFG_LTR_ENABLE_MASK                                      0x80000000
#define LTR_CFG_LTR_ENABLE_GET(x)                                    (((x) & LTR_CFG_LTR_ENABLE_MASK) >> LTR_CFG_LTR_ENABLE_LSB)
#define LTR_CFG_LTR_ENABLE_SET(x)                                    (((x) << LTR_CFG_LTR_ENABLE_LSB) & LTR_CFG_LTR_ENABLE_MASK)
#define LTR_CFG_LTR_ENABLE_RESET                                     0x0 // 0
#define LTR_CFG_RESERVED_1_MSB                                       30
#define LTR_CFG_RESERVED_1_LSB                                       29
#define LTR_CFG_RESERVED_1_MASK                                      0x60000000
#define LTR_CFG_RESERVED_1_GET(x)                                    (((x) & LTR_CFG_RESERVED_1_MASK) >> LTR_CFG_RESERVED_1_LSB)
#define LTR_CFG_RESERVED_1_SET(x)                                    (((x) << LTR_CFG_RESERVED_1_LSB) & LTR_CFG_RESERVED_1_MASK)
#define LTR_CFG_RESERVED_1_RESET                                     0x0 // 0
#define LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_MSB                         28
#define LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_LSB                         26
#define LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_MASK                        0x1c000000
#define LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_GET(x)                      (((x) & LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_MASK) >> LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_LSB)
#define LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_SET(x)                      (((x) << LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_LSB) & LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_MASK)
#define LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_RESET                       0x0 // 0
#define LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_MSB                         25
#define LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_LSB                         16
#define LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_MASK                        0x03ff0000
#define LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_GET(x)                      (((x) & LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_MASK) >> LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_LSB)
#define LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_SET(x)                      (((x) << LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_LSB) & LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_MASK)
#define LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_RESET                       0x0 // 0
#define LTR_CFG_RESERVED_0_MSB                                       15
#define LTR_CFG_RESERVED_0_LSB                                       13
#define LTR_CFG_RESERVED_0_MASK                                      0x0000e000
#define LTR_CFG_RESERVED_0_GET(x)                                    (((x) & LTR_CFG_RESERVED_0_MASK) >> LTR_CFG_RESERVED_0_LSB)
#define LTR_CFG_RESERVED_0_SET(x)                                    (((x) << LTR_CFG_RESERVED_0_LSB) & LTR_CFG_RESERVED_0_MASK)
#define LTR_CFG_RESERVED_0_RESET                                     0x0 // 0
#define LTR_CFG_MAX_SNOOP_LATENCY_SCALE_MSB                          12
#define LTR_CFG_MAX_SNOOP_LATENCY_SCALE_LSB                          10
#define LTR_CFG_MAX_SNOOP_LATENCY_SCALE_MASK                         0x00001c00
#define LTR_CFG_MAX_SNOOP_LATENCY_SCALE_GET(x)                       (((x) & LTR_CFG_MAX_SNOOP_LATENCY_SCALE_MASK) >> LTR_CFG_MAX_SNOOP_LATENCY_SCALE_LSB)
#define LTR_CFG_MAX_SNOOP_LATENCY_SCALE_SET(x)                       (((x) << LTR_CFG_MAX_SNOOP_LATENCY_SCALE_LSB) & LTR_CFG_MAX_SNOOP_LATENCY_SCALE_MASK)
#define LTR_CFG_MAX_SNOOP_LATENCY_SCALE_RESET                        0x0 // 0
#define LTR_CFG_MAX_SNOOP_LATENCY_VALUE_MSB                          9
#define LTR_CFG_MAX_SNOOP_LATENCY_VALUE_LSB                          0
#define LTR_CFG_MAX_SNOOP_LATENCY_VALUE_MASK                         0x000003ff
#define LTR_CFG_MAX_SNOOP_LATENCY_VALUE_GET(x)                       (((x) & LTR_CFG_MAX_SNOOP_LATENCY_VALUE_MASK) >> LTR_CFG_MAX_SNOOP_LATENCY_VALUE_LSB)
#define LTR_CFG_MAX_SNOOP_LATENCY_VALUE_SET(x)                       (((x) << LTR_CFG_MAX_SNOOP_LATENCY_VALUE_LSB) & LTR_CFG_MAX_SNOOP_LATENCY_VALUE_MASK)
#define LTR_CFG_MAX_SNOOP_LATENCY_VALUE_RESET                        0x0 // 0
#define LTR_CFG_ADDRESS                                              0x004c
#define LTR_CFG_OFFSET                                               0x004c
// SW modifiable bits
#define LTR_CFG_SW_MASK                                              0xffffffff
// bits defined at reset
#define LTR_CFG_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define LTR_CFG_RESET                                                0x00000000

// 32'h0050 (LTR_MSG)
#define LTR_MSG_V_MSB                                                31
#define LTR_MSG_V_LSB                                                0
#define LTR_MSG_V_MASK                                               0xffffffff
#define LTR_MSG_V_GET(x)                                             (((x) & LTR_MSG_V_MASK) >> LTR_MSG_V_LSB)
#define LTR_MSG_V_SET(x)                                             (((x) << LTR_MSG_V_LSB) & LTR_MSG_V_MASK)
#define LTR_MSG_V_RESET                                              0x0 // 0
#define LTR_MSG_ADDRESS                                              0x0050
#define LTR_MSG_OFFSET                                               0x0050
// SW modifiable bits
#define LTR_MSG_SW_MASK                                              0xffffffff
// bits defined at reset
#define LTR_MSG_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define LTR_MSG_RESET                                                0x00000000

// 32'h0054 (LTR_REQ)
#define LTR_REQ_REQ_MSB                                              0
#define LTR_REQ_REQ_LSB                                              0
#define LTR_REQ_REQ_MASK                                             0x00000001
#define LTR_REQ_REQ_GET(x)                                           (((x) & LTR_REQ_REQ_MASK) >> LTR_REQ_REQ_LSB)
#define LTR_REQ_REQ_SET(x)                                           (((x) << LTR_REQ_REQ_LSB) & LTR_REQ_REQ_MASK)
#define LTR_REQ_REQ_RESET                                            0x0 // 0
#define LTR_REQ_ADDRESS                                              0x0054
#define LTR_REQ_OFFSET                                               0x0054
// SW modifiable bits
#define LTR_REQ_SW_MASK                                              0x00000001
// bits defined at reset
#define LTR_REQ_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define LTR_REQ_RESET                                                0x00000000

// 32'h0058 (OBFF_STATUS)
#define OBFF_STATUS_OBFF_ENABLE_MSB                                  6
#define OBFF_STATUS_OBFF_ENABLE_LSB                                  5
#define OBFF_STATUS_OBFF_ENABLE_MASK                                 0x00000060
#define OBFF_STATUS_OBFF_ENABLE_GET(x)                               (((x) & OBFF_STATUS_OBFF_ENABLE_MASK) >> OBFF_STATUS_OBFF_ENABLE_LSB)
#define OBFF_STATUS_OBFF_ENABLE_SET(x)                               (((x) << OBFF_STATUS_OBFF_ENABLE_LSB) & OBFF_STATUS_OBFF_ENABLE_MASK)
#define OBFF_STATUS_OBFF_ENABLE_RESET                                0x0 // 0
#define OBFF_STATUS_VALID_MSB                                        4
#define OBFF_STATUS_VALID_LSB                                        4
#define OBFF_STATUS_VALID_MASK                                       0x00000010
#define OBFF_STATUS_VALID_GET(x)                                     (((x) & OBFF_STATUS_VALID_MASK) >> OBFF_STATUS_VALID_LSB)
#define OBFF_STATUS_VALID_SET(x)                                     (((x) << OBFF_STATUS_VALID_LSB) & OBFF_STATUS_VALID_MASK)
#define OBFF_STATUS_VALID_RESET                                      0x0 // 0
#define OBFF_STATUS_STATUS_MSB                                       3
#define OBFF_STATUS_STATUS_LSB                                       0
#define OBFF_STATUS_STATUS_MASK                                      0x0000000f
#define OBFF_STATUS_STATUS_GET(x)                                    (((x) & OBFF_STATUS_STATUS_MASK) >> OBFF_STATUS_STATUS_LSB)
#define OBFF_STATUS_STATUS_SET(x)                                    (((x) << OBFF_STATUS_STATUS_LSB) & OBFF_STATUS_STATUS_MASK)
#define OBFF_STATUS_STATUS_RESET                                     0x0 // 0
#define OBFF_STATUS_ADDRESS                                          0x0058
#define OBFF_STATUS_OFFSET                                           0x0058
// SW modifiable bits
#define OBFF_STATUS_SW_MASK                                          0x0000007f
// bits defined at reset
#define OBFF_STATUS_RSTMASK                                          0xffffffff
// reset value (ignore bits undefined at reset)
#define OBFF_STATUS_RESET                                            0x00000000

// 32'h005c (L1SS_OBS)
#define L1SS_OBS_L1SS_STATE_MSB                                      8
#define L1SS_OBS_L1SS_STATE_LSB                                      5
#define L1SS_OBS_L1SS_STATE_MASK                                     0x000001e0
#define L1SS_OBS_L1SS_STATE_GET(x)                                   (((x) & L1SS_OBS_L1SS_STATE_MASK) >> L1SS_OBS_L1SS_STATE_LSB)
#define L1SS_OBS_L1SS_STATE_SET(x)                                   (((x) << L1SS_OBS_L1SS_STATE_LSB) & L1SS_OBS_L1SS_STATE_MASK)
#define L1SS_OBS_L1SS_STATE_RESET                                    0x0 // 0
#define L1SS_OBS_PCLKREQ_N_MSB                                       4
#define L1SS_OBS_PCLKREQ_N_LSB                                       4
#define L1SS_OBS_PCLKREQ_N_MASK                                      0x00000010
#define L1SS_OBS_PCLKREQ_N_GET(x)                                    (((x) & L1SS_OBS_PCLKREQ_N_MASK) >> L1SS_OBS_PCLKREQ_N_LSB)
#define L1SS_OBS_PCLKREQ_N_SET(x)                                    (((x) << L1SS_OBS_PCLKREQ_N_LSB) & L1SS_OBS_PCLKREQ_N_MASK)
#define L1SS_OBS_PCLKREQ_N_RESET                                     0x0 // 0
#define L1SS_OBS_CLKREQIN_MSB                                        3
#define L1SS_OBS_CLKREQIN_LSB                                        3
#define L1SS_OBS_CLKREQIN_MASK                                       0x00000008
#define L1SS_OBS_CLKREQIN_GET(x)                                     (((x) & L1SS_OBS_CLKREQIN_MASK) >> L1SS_OBS_CLKREQIN_LSB)
#define L1SS_OBS_CLKREQIN_SET(x)                                     (((x) << L1SS_OBS_CLKREQIN_LSB) & L1SS_OBS_CLKREQIN_MASK)
#define L1SS_OBS_CLKREQIN_RESET                                      0x0 // 0
#define L1SS_OBS_AUXCLKACTIVE_MSB                                    2
#define L1SS_OBS_AUXCLKACTIVE_LSB                                    2
#define L1SS_OBS_AUXCLKACTIVE_MASK                                   0x00000004
#define L1SS_OBS_AUXCLKACTIVE_GET(x)                                 (((x) & L1SS_OBS_AUXCLKACTIVE_MASK) >> L1SS_OBS_AUXCLKACTIVE_LSB)
#define L1SS_OBS_AUXCLKACTIVE_SET(x)                                 (((x) << L1SS_OBS_AUXCLKACTIVE_LSB) & L1SS_OBS_AUXCLKACTIVE_MASK)
#define L1SS_OBS_AUXCLKACTIVE_RESET                                  0x0 // 0
#define L1SS_OBS_TXCMODE_DIS_MSB                                     1
#define L1SS_OBS_TXCMODE_DIS_LSB                                     1
#define L1SS_OBS_TXCMODE_DIS_MASK                                    0x00000002
#define L1SS_OBS_TXCMODE_DIS_GET(x)                                  (((x) & L1SS_OBS_TXCMODE_DIS_MASK) >> L1SS_OBS_TXCMODE_DIS_LSB)
#define L1SS_OBS_TXCMODE_DIS_SET(x)                                  (((x) << L1SS_OBS_TXCMODE_DIS_LSB) & L1SS_OBS_TXCMODE_DIS_MASK)
#define L1SS_OBS_TXCMODE_DIS_RESET                                   0x0 // 0
#define L1SS_OBS_RXEIDLE_DIS_MSB                                     0
#define L1SS_OBS_RXEIDLE_DIS_LSB                                     0
#define L1SS_OBS_RXEIDLE_DIS_MASK                                    0x00000001
#define L1SS_OBS_RXEIDLE_DIS_GET(x)                                  (((x) & L1SS_OBS_RXEIDLE_DIS_MASK) >> L1SS_OBS_RXEIDLE_DIS_LSB)
#define L1SS_OBS_RXEIDLE_DIS_SET(x)                                  (((x) << L1SS_OBS_RXEIDLE_DIS_LSB) & L1SS_OBS_RXEIDLE_DIS_MASK)
#define L1SS_OBS_RXEIDLE_DIS_RESET                                   0x0 // 0
#define L1SS_OBS_ADDRESS                                             0x005c
#define L1SS_OBS_OFFSET                                              0x005c
// SW modifiable bits
#define L1SS_OBS_SW_MASK                                             0x000001ff
// bits defined at reset
#define L1SS_OBS_RSTMASK                                             0xffffffff
// reset value (ignore bits undefined at reset)
#define L1SS_OBS_RESET                                               0x00000000

// 32'h0060 (L1SS_OVRD)
#define L1SS_OVRD_ENABLE_MSB                                         15
#define L1SS_OVRD_ENABLE_LSB                                         8
#define L1SS_OVRD_ENABLE_MASK                                        0x0000ff00
#define L1SS_OVRD_ENABLE_GET(x)                                      (((x) & L1SS_OVRD_ENABLE_MASK) >> L1SS_OVRD_ENABLE_LSB)
#define L1SS_OVRD_ENABLE_SET(x)                                      (((x) << L1SS_OVRD_ENABLE_LSB) & L1SS_OVRD_ENABLE_MASK)
#define L1SS_OVRD_ENABLE_RESET                                       0x0 // 0
#define L1SS_OVRD_VALUE_MSB                                          7
#define L1SS_OVRD_VALUE_LSB                                          0
#define L1SS_OVRD_VALUE_MASK                                         0x000000ff
#define L1SS_OVRD_VALUE_GET(x)                                       (((x) & L1SS_OVRD_VALUE_MASK) >> L1SS_OVRD_VALUE_LSB)
#define L1SS_OVRD_VALUE_SET(x)                                       (((x) << L1SS_OVRD_VALUE_LSB) & L1SS_OVRD_VALUE_MASK)
#define L1SS_OVRD_VALUE_RESET                                        0x0 // 0
#define L1SS_OVRD_ADDRESS                                            0x0060
#define L1SS_OVRD_OFFSET                                             0x0060
// SW modifiable bits
#define L1SS_OVRD_SW_MASK                                            0x0000ffff
// bits defined at reset
#define L1SS_OVRD_RSTMASK                                            0xffffffff
// reset value (ignore bits undefined at reset)
#define L1SS_OVRD_RESET                                              0x00000000

// 32'h0064 (PCIE_ELBI_DEBUG)
#define PCIE_ELBI_DEBUG_DBGAXIWR_MSB                                 25
#define PCIE_ELBI_DEBUG_DBGAXIWR_LSB                                 17
#define PCIE_ELBI_DEBUG_DBGAXIWR_MASK                                0x03fe0000
#define PCIE_ELBI_DEBUG_DBGAXIWR_GET(x)                              (((x) & PCIE_ELBI_DEBUG_DBGAXIWR_MASK) >> PCIE_ELBI_DEBUG_DBGAXIWR_LSB)
#define PCIE_ELBI_DEBUG_DBGAXIWR_SET(x)                              (((x) << PCIE_ELBI_DEBUG_DBGAXIWR_LSB) & PCIE_ELBI_DEBUG_DBGAXIWR_MASK)
#define PCIE_ELBI_DEBUG_DBGAXIWR_RESET                               0x0 // 0
#define PCIE_ELBI_DEBUG_DBGAXIRD_MSB                                 16
#define PCIE_ELBI_DEBUG_DBGAXIRD_LSB                                 11
#define PCIE_ELBI_DEBUG_DBGAXIRD_MASK                                0x0001f800
#define PCIE_ELBI_DEBUG_DBGAXIRD_GET(x)                              (((x) & PCIE_ELBI_DEBUG_DBGAXIRD_MASK) >> PCIE_ELBI_DEBUG_DBGAXIRD_LSB)
#define PCIE_ELBI_DEBUG_DBGAXIRD_SET(x)                              (((x) << PCIE_ELBI_DEBUG_DBGAXIRD_LSB) & PCIE_ELBI_DEBUG_DBGAXIRD_MASK)
#define PCIE_ELBI_DEBUG_DBGAXIRD_RESET                               0x0 // 0
#define PCIE_ELBI_DEBUG_DBGELBIAHB1_MSB                              10
#define PCIE_ELBI_DEBUG_DBGELBIAHB1_LSB                              7
#define PCIE_ELBI_DEBUG_DBGELBIAHB1_MASK                             0x00000780
#define PCIE_ELBI_DEBUG_DBGELBIAHB1_GET(x)                           (((x) & PCIE_ELBI_DEBUG_DBGELBIAHB1_MASK) >> PCIE_ELBI_DEBUG_DBGELBIAHB1_LSB)
#define PCIE_ELBI_DEBUG_DBGELBIAHB1_SET(x)                           (((x) << PCIE_ELBI_DEBUG_DBGELBIAHB1_LSB) & PCIE_ELBI_DEBUG_DBGELBIAHB1_MASK)
#define PCIE_ELBI_DEBUG_DBGELBIAHB1_RESET                            0x0 // 0
#define PCIE_ELBI_DEBUG_DBGELBIAHB0_MSB                              6
#define PCIE_ELBI_DEBUG_DBGELBIAHB0_LSB                              0
#define PCIE_ELBI_DEBUG_DBGELBIAHB0_MASK                             0x0000007f
#define PCIE_ELBI_DEBUG_DBGELBIAHB0_GET(x)                           (((x) & PCIE_ELBI_DEBUG_DBGELBIAHB0_MASK) >> PCIE_ELBI_DEBUG_DBGELBIAHB0_LSB)
#define PCIE_ELBI_DEBUG_DBGELBIAHB0_SET(x)                           (((x) << PCIE_ELBI_DEBUG_DBGELBIAHB0_LSB) & PCIE_ELBI_DEBUG_DBGELBIAHB0_MASK)
#define PCIE_ELBI_DEBUG_DBGELBIAHB0_RESET                            0x0 // 0
#define PCIE_ELBI_DEBUG_ADDRESS                                      0x0064
#define PCIE_ELBI_DEBUG_OFFSET                                       0x0064
// SW modifiable bits
#define PCIE_ELBI_DEBUG_SW_MASK                                      0x03ffffff
// bits defined at reset
#define PCIE_ELBI_DEBUG_RSTMASK                                      0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_ELBI_DEBUG_RESET                                        0x00000000


#endif /* _SOC_PCIE_REG_H_ */
