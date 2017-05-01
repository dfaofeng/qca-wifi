//                                                                             
// File:       ./soc_core_reg.h                                                
// Creator:    axie                                                            
// Time:       Wednesday May 30, 2012 [3:36:21 pm]                             
//                                                                             
// Path:       /trees/mbu-cn1/axie/txie_dpt1/chips/rome/dev/rtl/wlan/soc_core_reg/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -ch -Wdesc -I                 
//             /trees/mbu-cn1/axie/txie_dpt1/chips/rome/dev/blueprint/sysconfig
//             soc_core_reg.rdl                                                
//                                                                             
// Sources:    /trees/mbu-cn1/axie/txie_dpt1/chips/rome/dev/rtl/wlan/soc_core_reg/blueprint/soc_core_reg.rdl
//             /trees/mbu-cn1/axie/txie_dpt1/chips/rome/dev/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    zhou                                                            
// OS:         Linux 2.6.9-89.ELsmp                                            
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _SOC_CORE_REG_H_
#define _SOC_CORE_REG_H_
// 32'h0000 (CORE_CTRL)
#define CORE_CTRL_MASK_PCIE_RST_MSB                                  19
#define CORE_CTRL_MASK_PCIE_RST_LSB                                  19
#define CORE_CTRL_MASK_PCIE_RST_MASK                                 0x00080000
#define CORE_CTRL_MASK_PCIE_RST_GET(x)                               (((x) & CORE_CTRL_MASK_PCIE_RST_MASK) >> CORE_CTRL_MASK_PCIE_RST_LSB)
#define CORE_CTRL_MASK_PCIE_RST_SET(x)                               (((x) << CORE_CTRL_MASK_PCIE_RST_LSB) & CORE_CTRL_MASK_PCIE_RST_MASK)
#define CORE_CTRL_MASK_PCIE_RST_RESET                                0x1 // 1
#define CORE_CTRL_PCIE_LTSSM_EN_MSB                                  18
#define CORE_CTRL_PCIE_LTSSM_EN_LSB                                  18
#define CORE_CTRL_PCIE_LTSSM_EN_MASK                                 0x00040000
#define CORE_CTRL_PCIE_LTSSM_EN_GET(x)                               (((x) & CORE_CTRL_PCIE_LTSSM_EN_MASK) >> CORE_CTRL_PCIE_LTSSM_EN_LSB)
#define CORE_CTRL_PCIE_LTSSM_EN_SET(x)                               (((x) << CORE_CTRL_PCIE_LTSSM_EN_LSB) & CORE_CTRL_PCIE_LTSSM_EN_MASK)
#define CORE_CTRL_PCIE_LTSSM_EN_RESET                                0x0 // 0
#define CORE_CTRL_OUTBAND_PWRUP_MSB                                  16
#define CORE_CTRL_OUTBAND_PWRUP_LSB                                  16
#define CORE_CTRL_OUTBAND_PWRUP_MASK                                 0x00010000
#define CORE_CTRL_OUTBAND_PWRUP_GET(x)                               (((x) & CORE_CTRL_OUTBAND_PWRUP_MASK) >> CORE_CTRL_OUTBAND_PWRUP_LSB)
#define CORE_CTRL_OUTBAND_PWRUP_SET(x)                               (((x) << CORE_CTRL_OUTBAND_PWRUP_LSB) & CORE_CTRL_OUTBAND_PWRUP_MASK)
#define CORE_CTRL_OUTBAND_PWRUP_RESET                                0x0 // 0
#define CORE_CTRL_WAKE_L_MSB                                         15
#define CORE_CTRL_WAKE_L_LSB                                         15
#define CORE_CTRL_WAKE_L_MASK                                        0x00008000
#define CORE_CTRL_WAKE_L_GET(x)                                      (((x) & CORE_CTRL_WAKE_L_MASK) >> CORE_CTRL_WAKE_L_LSB)
#define CORE_CTRL_WAKE_L_SET(x)                                      (((x) << CORE_CTRL_WAKE_L_LSB) & CORE_CTRL_WAKE_L_MASK)
#define CORE_CTRL_WAKE_L_RESET                                       0x1 // 1
#define CORE_CTRL_HOST_WAKE_INTR_CLR_MSB                             14
#define CORE_CTRL_HOST_WAKE_INTR_CLR_LSB                             14
#define CORE_CTRL_HOST_WAKE_INTR_CLR_MASK                            0x00004000
#define CORE_CTRL_HOST_WAKE_INTR_CLR_GET(x)                          (((x) & CORE_CTRL_HOST_WAKE_INTR_CLR_MASK) >> CORE_CTRL_HOST_WAKE_INTR_CLR_LSB)
#define CORE_CTRL_HOST_WAKE_INTR_CLR_SET(x)                          (((x) << CORE_CTRL_HOST_WAKE_INTR_CLR_LSB) & CORE_CTRL_HOST_WAKE_INTR_CLR_MASK)
#define CORE_CTRL_HOST_WAKE_INTR_CLR_RESET                           0x0 // 0
#define CORE_CTRL_CPU_INTR_MSB                                       13
#define CORE_CTRL_CPU_INTR_LSB                                       13
#define CORE_CTRL_CPU_INTR_MASK                                      0x00002000
#define CORE_CTRL_CPU_INTR_GET(x)                                    (((x) & CORE_CTRL_CPU_INTR_MASK) >> CORE_CTRL_CPU_INTR_LSB)
#define CORE_CTRL_CPU_INTR_SET(x)                                    (((x) << CORE_CTRL_CPU_INTR_LSB) & CORE_CTRL_CPU_INTR_MASK)
#define CORE_CTRL_CPU_INTR_RESET                                     0x0 // 0
#define CORE_CTRL_PCIE_INTR_MSB                                      12
#define CORE_CTRL_PCIE_INTR_LSB                                      12
#define CORE_CTRL_PCIE_INTR_MASK                                     0x00001000
#define CORE_CTRL_PCIE_INTR_GET(x)                                   (((x) & CORE_CTRL_PCIE_INTR_MASK) >> CORE_CTRL_PCIE_INTR_LSB)
#define CORE_CTRL_PCIE_INTR_SET(x)                                   (((x) << CORE_CTRL_PCIE_INTR_LSB) & CORE_CTRL_PCIE_INTR_MASK)
#define CORE_CTRL_PCIE_INTR_RESET                                    0x0 // 0
#define CORE_CTRL_PCIE_REG_31_MSB                                    11
#define CORE_CTRL_PCIE_REG_31_LSB                                    11
#define CORE_CTRL_PCIE_REG_31_MASK                                   0x00000800
#define CORE_CTRL_PCIE_REG_31_GET(x)                                 (((x) & CORE_CTRL_PCIE_REG_31_MASK) >> CORE_CTRL_PCIE_REG_31_LSB)
#define CORE_CTRL_PCIE_REG_31_SET(x)                                 (((x) << CORE_CTRL_PCIE_REG_31_LSB) & CORE_CTRL_PCIE_REG_31_MASK)
#define CORE_CTRL_PCIE_REG_31_RESET                                  0x0 // 0
#define CORE_CTRL_PCIE_BAR_MSB                                       10
#define CORE_CTRL_PCIE_BAR_LSB                                       0
#define CORE_CTRL_PCIE_BAR_MASK                                      0x000007ff
#define CORE_CTRL_PCIE_BAR_GET(x)                                    (((x) & CORE_CTRL_PCIE_BAR_MASK) >> CORE_CTRL_PCIE_BAR_LSB)
#define CORE_CTRL_PCIE_BAR_SET(x)                                    (((x) << CORE_CTRL_PCIE_BAR_LSB) & CORE_CTRL_PCIE_BAR_MASK)
#define CORE_CTRL_PCIE_BAR_RESET                                     0x2 // 2
#define CORE_CTRL_ADDRESS                                            0x0000
#define CORE_CTRL_OFFSET                                             0x0000
// SW modifiable bits
#define CORE_CTRL_SW_MASK                                            0x000dffff
// bits defined at reset
#define CORE_CTRL_RSTMASK                                            0xffffffff
// reset value (ignore bits undefined at reset)
#define CORE_CTRL_RESET                                              0x00088002

// 32'h0004 (CORE_PM)
#define CORE_PM_DSTATE_MSB                                           5
#define CORE_PM_DSTATE_LSB                                           3
#define CORE_PM_DSTATE_MASK                                          0x00000038
#define CORE_PM_DSTATE_GET(x)                                        (((x) & CORE_PM_DSTATE_MASK) >> CORE_PM_DSTATE_LSB)
#define CORE_PM_DSTATE_SET(x)                                        (((x) << CORE_PM_DSTATE_LSB) & CORE_PM_DSTATE_MASK)
#define CORE_PM_DSTATE_RESET                                         0x0 // 0
#define CORE_PM_STATUS_MSB                                           2
#define CORE_PM_STATUS_LSB                                           2
#define CORE_PM_STATUS_MASK                                          0x00000004
#define CORE_PM_STATUS_GET(x)                                        (((x) & CORE_PM_STATUS_MASK) >> CORE_PM_STATUS_LSB)
#define CORE_PM_STATUS_SET(x)                                        (((x) << CORE_PM_STATUS_LSB) & CORE_PM_STATUS_MASK)
#define CORE_PM_STATUS_RESET                                         0x0 // 0
#define CORE_PM_AUX_PM_EN_MSB                                        1
#define CORE_PM_AUX_PM_EN_LSB                                        1
#define CORE_PM_AUX_PM_EN_MASK                                       0x00000002
#define CORE_PM_AUX_PM_EN_GET(x)                                     (((x) & CORE_PM_AUX_PM_EN_MASK) >> CORE_PM_AUX_PM_EN_LSB)
#define CORE_PM_AUX_PM_EN_SET(x)                                     (((x) << CORE_PM_AUX_PM_EN_LSB) & CORE_PM_AUX_PM_EN_MASK)
#define CORE_PM_AUX_PM_EN_RESET                                      0x0 // 0
#define CORE_PM_PME_EN_MSB                                           0
#define CORE_PM_PME_EN_LSB                                           0
#define CORE_PM_PME_EN_MASK                                          0x00000001
#define CORE_PM_PME_EN_GET(x)                                        (((x) & CORE_PM_PME_EN_MASK) >> CORE_PM_PME_EN_LSB)
#define CORE_PM_PME_EN_SET(x)                                        (((x) << CORE_PM_PME_EN_LSB) & CORE_PM_PME_EN_MASK)
#define CORE_PM_PME_EN_RESET                                         0x0 // 0
#define CORE_PM_ADDRESS                                              0x0004
#define CORE_PM_OFFSET                                               0x0004
// SW modifiable bits
#define CORE_PM_SW_MASK                                              0x0000003f
// bits defined at reset
#define CORE_PM_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define CORE_PM_RESET                                                0x00000000

// 32'h0008 (PCIE_INTR_ENABLE)
#define PCIE_INTR_ENABLE_VAL_MSB                                     29
#define PCIE_INTR_ENABLE_VAL_LSB                                     0
#define PCIE_INTR_ENABLE_VAL_MASK                                    0x3fffffff
#define PCIE_INTR_ENABLE_VAL_GET(x)                                  (((x) & PCIE_INTR_ENABLE_VAL_MASK) >> PCIE_INTR_ENABLE_VAL_LSB)
#define PCIE_INTR_ENABLE_VAL_SET(x)                                  (((x) << PCIE_INTR_ENABLE_VAL_LSB) & PCIE_INTR_ENABLE_VAL_MASK)
#define PCIE_INTR_ENABLE_VAL_RESET                                   0x0 // 0
#define PCIE_INTR_ENABLE_ADDRESS                                     0x0008
#define PCIE_INTR_ENABLE_OFFSET                                      0x0008
// SW modifiable bits
#define PCIE_INTR_ENABLE_SW_MASK                                     0x3fffffff
// bits defined at reset
#define PCIE_INTR_ENABLE_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_INTR_ENABLE_RESET                                       0x00000000

// 32'h000c (PCIE_INTR_CAUSE)
#define PCIE_INTR_CAUSE_VAL_MSB                                      29
#define PCIE_INTR_CAUSE_VAL_LSB                                      0
#define PCIE_INTR_CAUSE_VAL_MASK                                     0x3fffffff
#define PCIE_INTR_CAUSE_VAL_GET(x)                                   (((x) & PCIE_INTR_CAUSE_VAL_MASK) >> PCIE_INTR_CAUSE_VAL_LSB)
#define PCIE_INTR_CAUSE_VAL_SET(x)                                   (((x) << PCIE_INTR_CAUSE_VAL_LSB) & PCIE_INTR_CAUSE_VAL_MASK)
#define PCIE_INTR_CAUSE_VAL_RESET                                    0x0 // 0
#define PCIE_INTR_CAUSE_ADDRESS                                      0x000c
#define PCIE_INTR_CAUSE_OFFSET                                       0x000c
// SW modifiable bits
#define PCIE_INTR_CAUSE_SW_MASK                                      0x3fffffff
// bits defined at reset
#define PCIE_INTR_CAUSE_RSTMASK                                      0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_INTR_CAUSE_RESET                                        0x00000000

// 32'h0010 (CPU_INTR)
#define CPU_INTR_STATUS_MSB                                          29
#define CPU_INTR_STATUS_LSB                                          0
#define CPU_INTR_STATUS_MASK                                         0x3fffffff
#define CPU_INTR_STATUS_GET(x)                                       (((x) & CPU_INTR_STATUS_MASK) >> CPU_INTR_STATUS_LSB)
#define CPU_INTR_STATUS_SET(x)                                       (((x) << CPU_INTR_STATUS_LSB) & CPU_INTR_STATUS_MASK)
#define CPU_INTR_STATUS_RESET                                        0x0 // 0
#define CPU_INTR_ADDRESS                                             0x0010
#define CPU_INTR_OFFSET                                              0x0010
// SW modifiable bits
#define CPU_INTR_SW_MASK                                             0x3fffffff
// bits defined at reset
#define CPU_INTR_RSTMASK                                             0xffffffff
// reset value (ignore bits undefined at reset)
#define CPU_INTR_RESET                                               0x00000000

// 32'h0014 (PCIE_INTR_CLR)
#define PCIE_INTR_CLR_VAL_MSB                                        29
#define PCIE_INTR_CLR_VAL_LSB                                        0
#define PCIE_INTR_CLR_VAL_MASK                                       0x3fffffff
#define PCIE_INTR_CLR_VAL_GET(x)                                     (((x) & PCIE_INTR_CLR_VAL_MASK) >> PCIE_INTR_CLR_VAL_LSB)
#define PCIE_INTR_CLR_VAL_SET(x)                                     (((x) << PCIE_INTR_CLR_VAL_LSB) & PCIE_INTR_CLR_VAL_MASK)
#define PCIE_INTR_CLR_VAL_RESET                                      0x0 // 0
#define PCIE_INTR_CLR_ADDRESS                                        0x0014
#define PCIE_INTR_CLR_OFFSET                                         0x0014
// SW modifiable bits
#define PCIE_INTR_CLR_SW_MASK                                        0x3fffffff
// bits defined at reset
#define PCIE_INTR_CLR_RSTMASK                                        0xffffffff
// reset value (ignore bits undefined at reset)
#define PCIE_INTR_CLR_RESET                                          0x00000000

// 32'h0018 (CPU_ADDR_MSB)
#define CPU_ADDR_MSB_V_MSB                                           3
#define CPU_ADDR_MSB_V_LSB                                           0
#define CPU_ADDR_MSB_V_MASK                                          0x0000000f
#define CPU_ADDR_MSB_V_GET(x)                                        (((x) & CPU_ADDR_MSB_V_MASK) >> CPU_ADDR_MSB_V_LSB)
#define CPU_ADDR_MSB_V_SET(x)                                        (((x) << CPU_ADDR_MSB_V_LSB) & CPU_ADDR_MSB_V_MASK)
#define CPU_ADDR_MSB_V_RESET                                         0x4 // 4
#define CPU_ADDR_MSB_ADDRESS                                         0x0018
#define CPU_ADDR_MSB_OFFSET                                          0x0018
// SW modifiable bits
#define CPU_ADDR_MSB_SW_MASK                                         0x0000000f
// bits defined at reset
#define CPU_ADDR_MSB_RSTMASK                                         0xffffffff
// reset value (ignore bits undefined at reset)
#define CPU_ADDR_MSB_RESET                                           0x00000004

// 32'h001c (SCRATCH_0)
#define SCRATCH_0_VAL_MSB                                            31
#define SCRATCH_0_VAL_LSB                                            0
#define SCRATCH_0_VAL_MASK                                           0xffffffff
#define SCRATCH_0_VAL_GET(x)                                         (((x) & SCRATCH_0_VAL_MASK) >> SCRATCH_0_VAL_LSB)
#define SCRATCH_0_VAL_SET(x)                                         (((x) << SCRATCH_0_VAL_LSB) & SCRATCH_0_VAL_MASK)
#define SCRATCH_0_VAL_RESET                                          0x0 // 0
#define SCRATCH_0_ADDRESS                                            0x001c
#define SCRATCH_0_OFFSET                                             0x001c
// SW modifiable bits
#define SCRATCH_0_SW_MASK                                            0xffffffff
// bits defined at reset
#define SCRATCH_0_RSTMASK                                            0xffffffff
// reset value (ignore bits undefined at reset)
#define SCRATCH_0_RESET                                              0x00000000

// 32'h0020 (SCRATCH_1)
#define SCRATCH_1_VAL_MSB                                            31
#define SCRATCH_1_VAL_LSB                                            0
#define SCRATCH_1_VAL_MASK                                           0xffffffff
#define SCRATCH_1_VAL_GET(x)                                         (((x) & SCRATCH_1_VAL_MASK) >> SCRATCH_1_VAL_LSB)
#define SCRATCH_1_VAL_SET(x)                                         (((x) << SCRATCH_1_VAL_LSB) & SCRATCH_1_VAL_MASK)
#define SCRATCH_1_VAL_RESET                                          0x0 // 0
#define SCRATCH_1_ADDRESS                                            0x0020
#define SCRATCH_1_OFFSET                                             0x0020
// SW modifiable bits
#define SCRATCH_1_SW_MASK                                            0xffffffff
// bits defined at reset
#define SCRATCH_1_RSTMASK                                            0xffffffff
// reset value (ignore bits undefined at reset)
#define SCRATCH_1_RESET                                              0x00000000

// 32'h0024 (SCRATCH_2)
#define SCRATCH_2_VAL_MSB                                            31
#define SCRATCH_2_VAL_LSB                                            0
#define SCRATCH_2_VAL_MASK                                           0xffffffff
#define SCRATCH_2_VAL_GET(x)                                         (((x) & SCRATCH_2_VAL_MASK) >> SCRATCH_2_VAL_LSB)
#define SCRATCH_2_VAL_SET(x)                                         (((x) << SCRATCH_2_VAL_LSB) & SCRATCH_2_VAL_MASK)
#define SCRATCH_2_VAL_RESET                                          0x0 // 0
#define SCRATCH_2_ADDRESS                                            0x0024
#define SCRATCH_2_OFFSET                                             0x0024
// SW modifiable bits
#define SCRATCH_2_SW_MASK                                            0xffffffff
// bits defined at reset
#define SCRATCH_2_RSTMASK                                            0xffffffff
// reset value (ignore bits undefined at reset)
#define SCRATCH_2_RESET                                              0x00000000

// 32'h0028 (SCRATCH_3)
#define SCRATCH_3_VAL_MSB                                            31
#define SCRATCH_3_VAL_LSB                                            0
#define SCRATCH_3_VAL_MASK                                           0xffffffff
#define SCRATCH_3_VAL_GET(x)                                         (((x) & SCRATCH_3_VAL_MASK) >> SCRATCH_3_VAL_LSB)
#define SCRATCH_3_VAL_SET(x)                                         (((x) << SCRATCH_3_VAL_LSB) & SCRATCH_3_VAL_MASK)
#define SCRATCH_3_VAL_RESET                                          0x0 // 0
#define SCRATCH_3_ADDRESS                                            0x0028
#define SCRATCH_3_OFFSET                                             0x0028
// SW modifiable bits
#define SCRATCH_3_SW_MASK                                            0xffffffff
// bits defined at reset
#define SCRATCH_3_RSTMASK                                            0xffffffff
// reset value (ignore bits undefined at reset)
#define SCRATCH_3_RESET                                              0x00000000

// 32'h002c (WLAN_APB_ADDR_ERROR_CONTROL)
#define WLAN_APB_ADDR_ERROR_CONTROL_QUAL_ENABLE_MSB                  1
#define WLAN_APB_ADDR_ERROR_CONTROL_QUAL_ENABLE_LSB                  1
#define WLAN_APB_ADDR_ERROR_CONTROL_QUAL_ENABLE_MASK                 0x00000002
#define WLAN_APB_ADDR_ERROR_CONTROL_QUAL_ENABLE_GET(x)               (((x) & WLAN_APB_ADDR_ERROR_CONTROL_QUAL_ENABLE_MASK) >> WLAN_APB_ADDR_ERROR_CONTROL_QUAL_ENABLE_LSB)
#define WLAN_APB_ADDR_ERROR_CONTROL_QUAL_ENABLE_SET(x)               (((x) << WLAN_APB_ADDR_ERROR_CONTROL_QUAL_ENABLE_LSB) & WLAN_APB_ADDR_ERROR_CONTROL_QUAL_ENABLE_MASK)
#define WLAN_APB_ADDR_ERROR_CONTROL_QUAL_ENABLE_RESET                0x0 // 0
#define WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_MSB                       0
#define WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_LSB                       0
#define WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_MASK                      0x00000001
#define WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_GET(x)                    (((x) & WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_MASK) >> WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_LSB)
#define WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_SET(x)                    (((x) << WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_LSB) & WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_MASK)
#define WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_RESET                     0x0 // 0
#define WLAN_APB_ADDR_ERROR_CONTROL_ADDRESS                          0x002c
#define WLAN_APB_ADDR_ERROR_CONTROL_OFFSET                           0x002c
// SW modifiable bits
#define WLAN_APB_ADDR_ERROR_CONTROL_SW_MASK                          0x00000003
// bits defined at reset
#define WLAN_APB_ADDR_ERROR_CONTROL_RSTMASK                          0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_APB_ADDR_ERROR_CONTROL_RESET                            0x00000000

// 32'h0030 (WLAN_APB_ADDR_ERROR_STATUS)
#define WLAN_APB_ADDR_ERROR_STATUS_WRITE_MSB                         25
#define WLAN_APB_ADDR_ERROR_STATUS_WRITE_LSB                         25
#define WLAN_APB_ADDR_ERROR_STATUS_WRITE_MASK                        0x02000000
#define WLAN_APB_ADDR_ERROR_STATUS_WRITE_GET(x)                      (((x) & WLAN_APB_ADDR_ERROR_STATUS_WRITE_MASK) >> WLAN_APB_ADDR_ERROR_STATUS_WRITE_LSB)
#define WLAN_APB_ADDR_ERROR_STATUS_WRITE_SET(x)                      (((x) << WLAN_APB_ADDR_ERROR_STATUS_WRITE_LSB) & WLAN_APB_ADDR_ERROR_STATUS_WRITE_MASK)
#define WLAN_APB_ADDR_ERROR_STATUS_WRITE_RESET                       0x0 // 0
#define WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_MSB                       24
#define WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_LSB                       0
#define WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_MASK                      0x01ffffff
#define WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_GET(x)                    (((x) & WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_MASK) >> WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_LSB)
#define WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_SET(x)                    (((x) << WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_LSB) & WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_MASK)
#define WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_RESET                     0x0 // 0
#define WLAN_APB_ADDR_ERROR_STATUS_ADDRESS                           0x0030
#define WLAN_APB_ADDR_ERROR_STATUS_OFFSET                            0x0030
// SW modifiable bits
#define WLAN_APB_ADDR_ERROR_STATUS_SW_MASK                           0x03ffffff
// bits defined at reset
#define WLAN_APB_ADDR_ERROR_STATUS_RSTMASK                           0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_APB_ADDR_ERROR_STATUS_RESET                             0x00000000

// 32'h0034 (WLAN_AHB_ADDR_ERROR_CONTROL)
#define WLAN_AHB_ADDR_ERROR_CONTROL_ENABLE_MSB                       0
#define WLAN_AHB_ADDR_ERROR_CONTROL_ENABLE_LSB                       0
#define WLAN_AHB_ADDR_ERROR_CONTROL_ENABLE_MASK                      0x00000001
#define WLAN_AHB_ADDR_ERROR_CONTROL_ENABLE_GET(x)                    (((x) & WLAN_AHB_ADDR_ERROR_CONTROL_ENABLE_MASK) >> WLAN_AHB_ADDR_ERROR_CONTROL_ENABLE_LSB)
#define WLAN_AHB_ADDR_ERROR_CONTROL_ENABLE_SET(x)                    (((x) << WLAN_AHB_ADDR_ERROR_CONTROL_ENABLE_LSB) & WLAN_AHB_ADDR_ERROR_CONTROL_ENABLE_MASK)
#define WLAN_AHB_ADDR_ERROR_CONTROL_ENABLE_RESET                     0x0 // 0
#define WLAN_AHB_ADDR_ERROR_CONTROL_ADDRESS                          0x0034
#define WLAN_AHB_ADDR_ERROR_CONTROL_OFFSET                           0x0034
// SW modifiable bits
#define WLAN_AHB_ADDR_ERROR_CONTROL_SW_MASK                          0x00000001
// bits defined at reset
#define WLAN_AHB_ADDR_ERROR_CONTROL_RSTMASK                          0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_AHB_ADDR_ERROR_CONTROL_RESET                            0x00000000

// 32'h0038 (WLAN_AHB_ADDR_ERROR_STATUS)
#define WLAN_AHB_ADDR_ERROR_STATUS_MAC_MSB                           31
#define WLAN_AHB_ADDR_ERROR_STATUS_MAC_LSB                           31
#define WLAN_AHB_ADDR_ERROR_STATUS_MAC_MASK                          0x80000000
#define WLAN_AHB_ADDR_ERROR_STATUS_MAC_GET(x)                        (((x) & WLAN_AHB_ADDR_ERROR_STATUS_MAC_MASK) >> WLAN_AHB_ADDR_ERROR_STATUS_MAC_LSB)
#define WLAN_AHB_ADDR_ERROR_STATUS_MAC_SET(x)                        (((x) << WLAN_AHB_ADDR_ERROR_STATUS_MAC_LSB) & WLAN_AHB_ADDR_ERROR_STATUS_MAC_MASK)
#define WLAN_AHB_ADDR_ERROR_STATUS_MAC_RESET                         0x0 // 0
#define WLAN_AHB_ADDR_ERROR_STATUS_MBOX_MSB                          30
#define WLAN_AHB_ADDR_ERROR_STATUS_MBOX_LSB                          30
#define WLAN_AHB_ADDR_ERROR_STATUS_MBOX_MASK                         0x40000000
#define WLAN_AHB_ADDR_ERROR_STATUS_MBOX_GET(x)                       (((x) & WLAN_AHB_ADDR_ERROR_STATUS_MBOX_MASK) >> WLAN_AHB_ADDR_ERROR_STATUS_MBOX_LSB)
#define WLAN_AHB_ADDR_ERROR_STATUS_MBOX_SET(x)                       (((x) << WLAN_AHB_ADDR_ERROR_STATUS_MBOX_LSB) & WLAN_AHB_ADDR_ERROR_STATUS_MBOX_MASK)
#define WLAN_AHB_ADDR_ERROR_STATUS_MBOX_RESET                        0x0 // 0
#define WLAN_AHB_ADDR_ERROR_STATUS_ADDRESS_MSB                       23
#define WLAN_AHB_ADDR_ERROR_STATUS_ADDRESS_LSB                       0
#define WLAN_AHB_ADDR_ERROR_STATUS_ADDRESS_MASK                      0x00ffffff
#define WLAN_AHB_ADDR_ERROR_STATUS_ADDRESS_GET(x)                    (((x) & WLAN_AHB_ADDR_ERROR_STATUS_ADDRESS_MASK) >> WLAN_AHB_ADDR_ERROR_STATUS_ADDRESS_LSB)
#define WLAN_AHB_ADDR_ERROR_STATUS_ADDRESS_SET(x)                    (((x) << WLAN_AHB_ADDR_ERROR_STATUS_ADDRESS_LSB) & WLAN_AHB_ADDR_ERROR_STATUS_ADDRESS_MASK)
#define WLAN_AHB_ADDR_ERROR_STATUS_ADDRESS_RESET                     0x0 // 0
#define WLAN_AHB_ADDR_ERROR_STATUS_ADDRESS                           0x0038
#define WLAN_AHB_ADDR_ERROR_STATUS_OFFSET                            0x0038
// SW modifiable bits
#define WLAN_AHB_ADDR_ERROR_STATUS_SW_MASK                           0xc0ffffff
// bits defined at reset
#define WLAN_AHB_ADDR_ERROR_STATUS_RSTMASK                           0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_AHB_ADDR_ERROR_STATUS_RESET                             0x00000000

// 32'h003c (WLAN_HMASTER)
#define WLAN_HMASTER_IDLE_LIMIT_MSB                                  31
#define WLAN_HMASTER_IDLE_LIMIT_LSB                                  28
#define WLAN_HMASTER_IDLE_LIMIT_MASK                                 0xf0000000
#define WLAN_HMASTER_IDLE_LIMIT_GET(x)                               (((x) & WLAN_HMASTER_IDLE_LIMIT_MASK) >> WLAN_HMASTER_IDLE_LIMIT_LSB)
#define WLAN_HMASTER_IDLE_LIMIT_SET(x)                               (((x) << WLAN_HMASTER_IDLE_LIMIT_LSB) & WLAN_HMASTER_IDLE_LIMIT_MASK)
#define WLAN_HMASTER_IDLE_LIMIT_RESET                                0xf // 15
#define WLAN_HMASTER_LOCK_DET_MSB                                    9
#define WLAN_HMASTER_LOCK_DET_LSB                                    0
#define WLAN_HMASTER_LOCK_DET_MASK                                   0x000003ff
#define WLAN_HMASTER_LOCK_DET_GET(x)                                 (((x) & WLAN_HMASTER_LOCK_DET_MASK) >> WLAN_HMASTER_LOCK_DET_LSB)
#define WLAN_HMASTER_LOCK_DET_SET(x)                                 (((x) << WLAN_HMASTER_LOCK_DET_LSB) & WLAN_HMASTER_LOCK_DET_MASK)
#define WLAN_HMASTER_LOCK_DET_RESET                                  0x0 // 0
#define WLAN_HMASTER_ADDRESS                                         0x003c
#define WLAN_HMASTER_OFFSET                                          0x003c
// SW modifiable bits
#define WLAN_HMASTER_SW_MASK                                         0xf00003ff
// bits defined at reset
#define WLAN_HMASTER_RSTMASK                                         0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_HMASTER_RESET                                           0xf0000000

// 32'h0040 (WLAN_HMASTER_STATUS)
#define WLAN_HMASTER_STATUS_LOCK_MSB                                 9
#define WLAN_HMASTER_STATUS_LOCK_LSB                                 0
#define WLAN_HMASTER_STATUS_LOCK_MASK                                0x000003ff
#define WLAN_HMASTER_STATUS_LOCK_GET(x)                              (((x) & WLAN_HMASTER_STATUS_LOCK_MASK) >> WLAN_HMASTER_STATUS_LOCK_LSB)
#define WLAN_HMASTER_STATUS_LOCK_SET(x)                              (((x) << WLAN_HMASTER_STATUS_LOCK_LSB) & WLAN_HMASTER_STATUS_LOCK_MASK)
#define WLAN_HMASTER_STATUS_LOCK_RESET                               0x0 // 0
#define WLAN_HMASTER_STATUS_ADDRESS                                  0x0040
#define WLAN_HMASTER_STATUS_OFFSET                                   0x0040
// SW modifiable bits
#define WLAN_HMASTER_STATUS_SW_MASK                                  0x000003ff
// bits defined at reset
#define WLAN_HMASTER_STATUS_RSTMASK                                  0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_HMASTER_STATUS_RESET                                    0x00000000

// 32'h0044 (AXI_SPOOFER)
#define AXI_SPOOFER_JTAG_EN_MSB                                      13
#define AXI_SPOOFER_JTAG_EN_LSB                                      13
#define AXI_SPOOFER_JTAG_EN_MASK                                     0x00002000
#define AXI_SPOOFER_JTAG_EN_GET(x)                                   (((x) & AXI_SPOOFER_JTAG_EN_MASK) >> AXI_SPOOFER_JTAG_EN_LSB)
#define AXI_SPOOFER_JTAG_EN_SET(x)                                   (((x) << AXI_SPOOFER_JTAG_EN_LSB) & AXI_SPOOFER_JTAG_EN_MASK)
#define AXI_SPOOFER_JTAG_EN_RESET                                    0x0 // 0
#define AXI_SPOOFER_AHB2AXI_EN_MSB                                   12
#define AXI_SPOOFER_AHB2AXI_EN_LSB                                   12
#define AXI_SPOOFER_AHB2AXI_EN_MASK                                  0x00001000
#define AXI_SPOOFER_AHB2AXI_EN_GET(x)                                (((x) & AXI_SPOOFER_AHB2AXI_EN_MASK) >> AXI_SPOOFER_AHB2AXI_EN_LSB)
#define AXI_SPOOFER_AHB2AXI_EN_SET(x)                                (((x) << AXI_SPOOFER_AHB2AXI_EN_LSB) & AXI_SPOOFER_AHB2AXI_EN_MASK)
#define AXI_SPOOFER_AHB2AXI_EN_RESET                                 0x0 // 0
#define AXI_SPOOFER_INTF_MEM_EN_1_MSB                                11
#define AXI_SPOOFER_INTF_MEM_EN_1_LSB                                11
#define AXI_SPOOFER_INTF_MEM_EN_1_MASK                               0x00000800
#define AXI_SPOOFER_INTF_MEM_EN_1_GET(x)                             (((x) & AXI_SPOOFER_INTF_MEM_EN_1_MASK) >> AXI_SPOOFER_INTF_MEM_EN_1_LSB)
#define AXI_SPOOFER_INTF_MEM_EN_1_SET(x)                             (((x) << AXI_SPOOFER_INTF_MEM_EN_1_LSB) & AXI_SPOOFER_INTF_MEM_EN_1_MASK)
#define AXI_SPOOFER_INTF_MEM_EN_1_RESET                              0x0 // 0
#define AXI_SPOOFER_INTF_MEM_EN_0_MSB                                10
#define AXI_SPOOFER_INTF_MEM_EN_0_LSB                                10
#define AXI_SPOOFER_INTF_MEM_EN_0_MASK                               0x00000400
#define AXI_SPOOFER_INTF_MEM_EN_0_GET(x)                             (((x) & AXI_SPOOFER_INTF_MEM_EN_0_MASK) >> AXI_SPOOFER_INTF_MEM_EN_0_LSB)
#define AXI_SPOOFER_INTF_MEM_EN_0_SET(x)                             (((x) << AXI_SPOOFER_INTF_MEM_EN_0_LSB) & AXI_SPOOFER_INTF_MEM_EN_0_MASK)
#define AXI_SPOOFER_INTF_MEM_EN_0_RESET                              0x0 // 0
#define AXI_SPOOFER_CPU_SLAVE_EN_MSB                                 9
#define AXI_SPOOFER_CPU_SLAVE_EN_LSB                                 9
#define AXI_SPOOFER_CPU_SLAVE_EN_MASK                                0x00000200
#define AXI_SPOOFER_CPU_SLAVE_EN_GET(x)                              (((x) & AXI_SPOOFER_CPU_SLAVE_EN_MASK) >> AXI_SPOOFER_CPU_SLAVE_EN_LSB)
#define AXI_SPOOFER_CPU_SLAVE_EN_SET(x)                              (((x) << AXI_SPOOFER_CPU_SLAVE_EN_LSB) & AXI_SPOOFER_CPU_SLAVE_EN_MASK)
#define AXI_SPOOFER_CPU_SLAVE_EN_RESET                               0x0 // 0
#define AXI_SPOOFER_PCIE_ELBI_EN_MSB                                 8
#define AXI_SPOOFER_PCIE_ELBI_EN_LSB                                 8
#define AXI_SPOOFER_PCIE_ELBI_EN_MASK                                0x00000100
#define AXI_SPOOFER_PCIE_ELBI_EN_GET(x)                              (((x) & AXI_SPOOFER_PCIE_ELBI_EN_MASK) >> AXI_SPOOFER_PCIE_ELBI_EN_LSB)
#define AXI_SPOOFER_PCIE_ELBI_EN_SET(x)                              (((x) << AXI_SPOOFER_PCIE_ELBI_EN_LSB) & AXI_SPOOFER_PCIE_ELBI_EN_MASK)
#define AXI_SPOOFER_PCIE_ELBI_EN_RESET                               0x0 // 0
#define AXI_SPOOFER_AXI2AHB_BT_EN_MSB                                7
#define AXI_SPOOFER_AXI2AHB_BT_EN_LSB                                7
#define AXI_SPOOFER_AXI2AHB_BT_EN_MASK                               0x00000080
#define AXI_SPOOFER_AXI2AHB_BT_EN_GET(x)                             (((x) & AXI_SPOOFER_AXI2AHB_BT_EN_MASK) >> AXI_SPOOFER_AXI2AHB_BT_EN_LSB)
#define AXI_SPOOFER_AXI2AHB_BT_EN_SET(x)                             (((x) << AXI_SPOOFER_AXI2AHB_BT_EN_LSB) & AXI_SPOOFER_AXI2AHB_BT_EN_MASK)
#define AXI_SPOOFER_AXI2AHB_BT_EN_RESET                              0x0 // 0
#define AXI_SPOOFER_SDIO_EN_MSB                                      6
#define AXI_SPOOFER_SDIO_EN_LSB                                      6
#define AXI_SPOOFER_SDIO_EN_MASK                                     0x00000040
#define AXI_SPOOFER_SDIO_EN_GET(x)                                   (((x) & AXI_SPOOFER_SDIO_EN_MASK) >> AXI_SPOOFER_SDIO_EN_LSB)
#define AXI_SPOOFER_SDIO_EN_SET(x)                                   (((x) << AXI_SPOOFER_SDIO_EN_LSB) & AXI_SPOOFER_SDIO_EN_MASK)
#define AXI_SPOOFER_SDIO_EN_RESET                                    0x0 // 0
#define AXI_SPOOFER_USB_EN_MSB                                       5
#define AXI_SPOOFER_USB_EN_LSB                                       5
#define AXI_SPOOFER_USB_EN_MASK                                      0x00000020
#define AXI_SPOOFER_USB_EN_GET(x)                                    (((x) & AXI_SPOOFER_USB_EN_MASK) >> AXI_SPOOFER_USB_EN_LSB)
#define AXI_SPOOFER_USB_EN_SET(x)                                    (((x) << AXI_SPOOFER_USB_EN_LSB) & AXI_SPOOFER_USB_EN_MASK)
#define AXI_SPOOFER_USB_EN_RESET                                     0x0 // 0
#define AXI_SPOOFER_CPU_MASTER_EN_MSB                                4
#define AXI_SPOOFER_CPU_MASTER_EN_LSB                                4
#define AXI_SPOOFER_CPU_MASTER_EN_MASK                               0x00000010
#define AXI_SPOOFER_CPU_MASTER_EN_GET(x)                             (((x) & AXI_SPOOFER_CPU_MASTER_EN_MASK) >> AXI_SPOOFER_CPU_MASTER_EN_LSB)
#define AXI_SPOOFER_CPU_MASTER_EN_SET(x)                             (((x) << AXI_SPOOFER_CPU_MASTER_EN_LSB) & AXI_SPOOFER_CPU_MASTER_EN_MASK)
#define AXI_SPOOFER_CPU_MASTER_EN_RESET                              0x0 // 0
#define AXI_SPOOFER_PCIE_EN_MSB                                      3
#define AXI_SPOOFER_PCIE_EN_LSB                                      3
#define AXI_SPOOFER_PCIE_EN_MASK                                     0x00000008
#define AXI_SPOOFER_PCIE_EN_GET(x)                                   (((x) & AXI_SPOOFER_PCIE_EN_MASK) >> AXI_SPOOFER_PCIE_EN_LSB)
#define AXI_SPOOFER_PCIE_EN_SET(x)                                   (((x) << AXI_SPOOFER_PCIE_EN_LSB) & AXI_SPOOFER_PCIE_EN_MASK)
#define AXI_SPOOFER_PCIE_EN_RESET                                    0x0 // 0
#define AXI_SPOOFER_AXI2AHB_EN_MSB                                   2
#define AXI_SPOOFER_AXI2AHB_EN_LSB                                   2
#define AXI_SPOOFER_AXI2AHB_EN_MASK                                  0x00000004
#define AXI_SPOOFER_AXI2AHB_EN_GET(x)                                (((x) & AXI_SPOOFER_AXI2AHB_EN_MASK) >> AXI_SPOOFER_AXI2AHB_EN_LSB)
#define AXI_SPOOFER_AXI2AHB_EN_SET(x)                                (((x) << AXI_SPOOFER_AXI2AHB_EN_LSB) & AXI_SPOOFER_AXI2AHB_EN_MASK)
#define AXI_SPOOFER_AXI2AHB_EN_RESET                                 0x0 // 0
#define AXI_SPOOFER_CE_EN_MSB                                        1
#define AXI_SPOOFER_CE_EN_LSB                                        1
#define AXI_SPOOFER_CE_EN_MASK                                       0x00000002
#define AXI_SPOOFER_CE_EN_GET(x)                                     (((x) & AXI_SPOOFER_CE_EN_MASK) >> AXI_SPOOFER_CE_EN_LSB)
#define AXI_SPOOFER_CE_EN_SET(x)                                     (((x) << AXI_SPOOFER_CE_EN_LSB) & AXI_SPOOFER_CE_EN_MASK)
#define AXI_SPOOFER_CE_EN_RESET                                      0x0 // 0
#define AXI_SPOOFER_WMAC_EN_MSB                                      0
#define AXI_SPOOFER_WMAC_EN_LSB                                      0
#define AXI_SPOOFER_WMAC_EN_MASK                                     0x00000001
#define AXI_SPOOFER_WMAC_EN_GET(x)                                   (((x) & AXI_SPOOFER_WMAC_EN_MASK) >> AXI_SPOOFER_WMAC_EN_LSB)
#define AXI_SPOOFER_WMAC_EN_SET(x)                                   (((x) << AXI_SPOOFER_WMAC_EN_LSB) & AXI_SPOOFER_WMAC_EN_MASK)
#define AXI_SPOOFER_WMAC_EN_RESET                                    0x0 // 0
#define AXI_SPOOFER_ADDRESS                                          0x0044
#define AXI_SPOOFER_OFFSET                                           0x0044
// SW modifiable bits
#define AXI_SPOOFER_SW_MASK                                          0x00003fff
// bits defined at reset
#define AXI_SPOOFER_RSTMASK                                          0xffffffff
// reset value (ignore bits undefined at reset)
#define AXI_SPOOFER_RESET                                            0x00000000

// 32'h0048 (WLAN_USB_BURST_ALIGN)
#define WLAN_USB_BURST_ALIGN_EN_MSB                                  0
#define WLAN_USB_BURST_ALIGN_EN_LSB                                  0
#define WLAN_USB_BURST_ALIGN_EN_MASK                                 0x00000001
#define WLAN_USB_BURST_ALIGN_EN_GET(x)                               (((x) & WLAN_USB_BURST_ALIGN_EN_MASK) >> WLAN_USB_BURST_ALIGN_EN_LSB)
#define WLAN_USB_BURST_ALIGN_EN_SET(x)                               (((x) << WLAN_USB_BURST_ALIGN_EN_LSB) & WLAN_USB_BURST_ALIGN_EN_MASK)
#define WLAN_USB_BURST_ALIGN_EN_RESET                                0x1 // 1
#define WLAN_USB_BURST_ALIGN_ADDRESS                                 0x0048
#define WLAN_USB_BURST_ALIGN_OFFSET                                  0x0048
// SW modifiable bits
#define WLAN_USB_BURST_ALIGN_SW_MASK                                 0x00000001
// bits defined at reset
#define WLAN_USB_BURST_ALIGN_RSTMASK                                 0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_USB_BURST_ALIGN_RESET                                   0x00000001

// 32'h004c (WLAN2BT_BRIDGE)
#define WLAN2BT_BRIDGE_EN_MSB                                        0
#define WLAN2BT_BRIDGE_EN_LSB                                        0
#define WLAN2BT_BRIDGE_EN_MASK                                       0x00000001
#define WLAN2BT_BRIDGE_EN_GET(x)                                     (((x) & WLAN2BT_BRIDGE_EN_MASK) >> WLAN2BT_BRIDGE_EN_LSB)
#define WLAN2BT_BRIDGE_EN_SET(x)                                     (((x) << WLAN2BT_BRIDGE_EN_LSB) & WLAN2BT_BRIDGE_EN_MASK)
#define WLAN2BT_BRIDGE_EN_RESET                                      0x0 // 0
#define WLAN2BT_BRIDGE_ADDRESS                                       0x004c
#define WLAN2BT_BRIDGE_OFFSET                                        0x004c
// SW modifiable bits
#define WLAN2BT_BRIDGE_SW_MASK                                       0x00000001
// bits defined at reset
#define WLAN2BT_BRIDGE_RSTMASK                                       0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN2BT_BRIDGE_RESET                                         0x00000000


#endif /* _SOC_CORE_REG_H_ */
