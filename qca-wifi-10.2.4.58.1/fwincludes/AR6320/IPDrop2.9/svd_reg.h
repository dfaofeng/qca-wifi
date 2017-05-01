//                                                                             
// File:       ./svd_reg.h                                                     
// Creator:    siju                                                            
// Time:       Sunday Jun 27, 2010 [11:23:26 pm]                               
//                                                                             
// Path:       /trees/siju/siju-mckinley3/ip/athr/wlan_mac/rtl/dev/wmac_wrap/svd/blueprint
// Arguments:  /cad/denali/blueprint/3.7.3//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -ch -Wdesc svd_reg.rdl        
//                                                                             
// Sources:    /trees/siju/siju-mckinley3/ip/athr/wlan_mac/shared/blueprint/sysconfig/svd_reg_sysconfig.rdl
//             /trees/siju/siju-mckinley3/ip/athr/wlan_mac/rtl/dev/wmac_wrap/svd/blueprint/svd_reg.rdl
//             /trees/siju/siju-mckinley3/ip/athr/wlan_mac/shared/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.3 (Fri Aug 29 12:39:16 PDT 2008)                           
// Machine:    bhushavali.users.atheros.com                                    
// OS:         Linux 2.6.18-8.el5                                              
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _SVD_REG_H_
#define _SVD_REG_H_
// 32'h10000 (TXBF_DBG)
#define TXBF_DBG_DBG_NO_CSD_MSB                                      24
#define TXBF_DBG_DBG_NO_CSD_LSB                                      24
#define TXBF_DBG_DBG_NO_CSD_MASK                                     0x01000000
#define TXBF_DBG_DBG_NO_CSD_GET(x)                                   (((x) & TXBF_DBG_DBG_NO_CSD_MASK) >> TXBF_DBG_DBG_NO_CSD_LSB)
#define TXBF_DBG_DBG_NO_CSD_SET(x)                                   (((x) << TXBF_DBG_DBG_NO_CSD_LSB) & TXBF_DBG_DBG_NO_CSD_MASK)
#define TXBF_DBG_DBG_NO_CSD_RESET                                    0x0 // 0
#define TXBF_DBG_DBG_NO_WALSH_MSB                                    23
#define TXBF_DBG_DBG_NO_WALSH_LSB                                    23
#define TXBF_DBG_DBG_NO_WALSH_MASK                                   0x00800000
#define TXBF_DBG_DBG_NO_WALSH_GET(x)                                 (((x) & TXBF_DBG_DBG_NO_WALSH_MASK) >> TXBF_DBG_DBG_NO_WALSH_LSB)
#define TXBF_DBG_DBG_NO_WALSH_SET(x)                                 (((x) << TXBF_DBG_DBG_NO_WALSH_LSB) & TXBF_DBG_DBG_NO_WALSH_MASK)
#define TXBF_DBG_DBG_NO_WALSH_RESET                                  0x0 // 0
#define TXBF_DBG_REGULAR_SOUNDING_MSB                                22
#define TXBF_DBG_REGULAR_SOUNDING_LSB                                22
#define TXBF_DBG_REGULAR_SOUNDING_MASK                               0x00400000
#define TXBF_DBG_REGULAR_SOUNDING_GET(x)                             (((x) & TXBF_DBG_REGULAR_SOUNDING_MASK) >> TXBF_DBG_REGULAR_SOUNDING_LSB)
#define TXBF_DBG_REGULAR_SOUNDING_SET(x)                             (((x) << TXBF_DBG_REGULAR_SOUNDING_LSB) & TXBF_DBG_REGULAR_SOUNDING_MASK)
#define TXBF_DBG_REGULAR_SOUNDING_RESET                              0x0 // 0
#define TXBF_DBG_CLK_CNTL_MSB                                        21
#define TXBF_DBG_CLK_CNTL_LSB                                        21
#define TXBF_DBG_CLK_CNTL_MASK                                       0x00200000
#define TXBF_DBG_CLK_CNTL_GET(x)                                     (((x) & TXBF_DBG_CLK_CNTL_MASK) >> TXBF_DBG_CLK_CNTL_LSB)
#define TXBF_DBG_CLK_CNTL_SET(x)                                     (((x) << TXBF_DBG_CLK_CNTL_LSB) & TXBF_DBG_CLK_CNTL_MASK)
#define TXBF_DBG_CLK_CNTL_RESET                                      0x0 // 0
#define TXBF_DBG_DBG_BW_MSB                                          20
#define TXBF_DBG_DBG_BW_LSB                                          20
#define TXBF_DBG_DBG_BW_MASK                                         0x00100000
#define TXBF_DBG_DBG_BW_GET(x)                                       (((x) & TXBF_DBG_DBG_BW_MASK) >> TXBF_DBG_DBG_BW_LSB)
#define TXBF_DBG_DBG_BW_SET(x)                                       (((x) << TXBF_DBG_DBG_BW_LSB) & TXBF_DBG_DBG_BW_MASK)
#define TXBF_DBG_DBG_BW_RESET                                        0x0 // 0
#define TXBF_DBG_DBG_IM_MSB                                          19
#define TXBF_DBG_DBG_IM_LSB                                          19
#define TXBF_DBG_DBG_IM_MASK                                         0x00080000
#define TXBF_DBG_DBG_IM_GET(x)                                       (((x) & TXBF_DBG_DBG_IM_MASK) >> TXBF_DBG_DBG_IM_LSB)
#define TXBF_DBG_DBG_IM_SET(x)                                       (((x) << TXBF_DBG_DBG_IM_LSB) & TXBF_DBG_DBG_IM_MASK)
#define TXBF_DBG_DBG_IM_RESET                                        0x0 // 0
#define TXBF_DBG_SW_WR_V_DONE_MSB                                    18
#define TXBF_DBG_SW_WR_V_DONE_LSB                                    18
#define TXBF_DBG_SW_WR_V_DONE_MASK                                   0x00040000
#define TXBF_DBG_SW_WR_V_DONE_GET(x)                                 (((x) & TXBF_DBG_SW_WR_V_DONE_MASK) >> TXBF_DBG_SW_WR_V_DONE_LSB)
#define TXBF_DBG_SW_WR_V_DONE_SET(x)                                 (((x) << TXBF_DBG_SW_WR_V_DONE_LSB) & TXBF_DBG_SW_WR_V_DONE_MASK)
#define TXBF_DBG_SW_WR_V_DONE_RESET                                  0x0 // 0
#define TXBF_DBG_CLIENT_TABLE_MSB                                    17
#define TXBF_DBG_CLIENT_TABLE_LSB                                    2
#define TXBF_DBG_CLIENT_TABLE_MASK                                   0x0003fffc
#define TXBF_DBG_CLIENT_TABLE_GET(x)                                 (((x) & TXBF_DBG_CLIENT_TABLE_MASK) >> TXBF_DBG_CLIENT_TABLE_LSB)
#define TXBF_DBG_CLIENT_TABLE_SET(x)                                 (((x) << TXBF_DBG_CLIENT_TABLE_LSB) & TXBF_DBG_CLIENT_TABLE_MASK)
#define TXBF_DBG_CLIENT_TABLE_RESET                                  0x0 // 0
#define TXBF_DBG_MODE_MSB                                            1
#define TXBF_DBG_MODE_LSB                                            0
#define TXBF_DBG_MODE_MASK                                           0x00000003
#define TXBF_DBG_MODE_GET(x)                                         (((x) & TXBF_DBG_MODE_MASK) >> TXBF_DBG_MODE_LSB)
#define TXBF_DBG_MODE_SET(x)                                         (((x) << TXBF_DBG_MODE_LSB) & TXBF_DBG_MODE_MASK)
#define TXBF_DBG_MODE_RESET                                          0x0 // 0
#define TXBF_DBG_ADDRESS                                             0x10000
#define TXBF_DBG_OFFSET                                              0x10000
// SW modifiable bits
#define TXBF_DBG_SW_MASK                                             0x01ffffff
// bits defined at reset
#define TXBF_DBG_RSTMASK                                             0xffffffff
// reset value (ignore bits undefined at reset)
#define TXBF_DBG_RESET                                               0x00000000

// 32'h10004 (TXBF)
#define TXBF_RC_40_DONE_MSB                                          14
#define TXBF_RC_40_DONE_LSB                                          14
#define TXBF_RC_40_DONE_MASK                                         0x00004000
#define TXBF_RC_40_DONE_GET(x)                                       (((x) & TXBF_RC_40_DONE_MASK) >> TXBF_RC_40_DONE_LSB)
#define TXBF_RC_40_DONE_SET(x)                                       (((x) << TXBF_RC_40_DONE_LSB) & TXBF_RC_40_DONE_MASK)
#define TXBF_RC_40_DONE_RESET                                        0x0 // 0
#define TXBF_RC_20_L_DONE_MSB                                        13
#define TXBF_RC_20_L_DONE_LSB                                        13
#define TXBF_RC_20_L_DONE_MASK                                       0x00002000
#define TXBF_RC_20_L_DONE_GET(x)                                     (((x) & TXBF_RC_20_L_DONE_MASK) >> TXBF_RC_20_L_DONE_LSB)
#define TXBF_RC_20_L_DONE_SET(x)                                     (((x) << TXBF_RC_20_L_DONE_LSB) & TXBF_RC_20_L_DONE_MASK)
#define TXBF_RC_20_L_DONE_RESET                                      0x0 // 0
#define TXBF_RC_20_U_DONE_MSB                                        12
#define TXBF_RC_20_U_DONE_LSB                                        12
#define TXBF_RC_20_U_DONE_MASK                                       0x00001000
#define TXBF_RC_20_U_DONE_GET(x)                                     (((x) & TXBF_RC_20_U_DONE_MASK) >> TXBF_RC_20_U_DONE_LSB)
#define TXBF_RC_20_U_DONE_SET(x)                                     (((x) << TXBF_RC_20_U_DONE_LSB) & TXBF_RC_20_U_DONE_MASK)
#define TXBF_RC_20_U_DONE_RESET                                      0x0 // 0
#define TXBF_RLR_EN_MSB                                              11
#define TXBF_RLR_EN_LSB                                              11
#define TXBF_RLR_EN_MASK                                             0x00000800
#define TXBF_RLR_EN_GET(x)                                           (((x) & TXBF_RLR_EN_MASK) >> TXBF_RLR_EN_LSB)
#define TXBF_RLR_EN_SET(x)                                           (((x) << TXBF_RLR_EN_LSB) & TXBF_RLR_EN_MASK)
#define TXBF_RLR_EN_RESET                                            0x0 // 0
#define TXBF_TXCV_BFWEIGHT_METHOD_MSB                                10
#define TXBF_TXCV_BFWEIGHT_METHOD_LSB                                9
#define TXBF_TXCV_BFWEIGHT_METHOD_MASK                               0x00000600
#define TXBF_TXCV_BFWEIGHT_METHOD_GET(x)                             (((x) & TXBF_TXCV_BFWEIGHT_METHOD_MASK) >> TXBF_TXCV_BFWEIGHT_METHOD_LSB)
#define TXBF_TXCV_BFWEIGHT_METHOD_SET(x)                             (((x) << TXBF_TXCV_BFWEIGHT_METHOD_LSB) & TXBF_TXCV_BFWEIGHT_METHOD_MASK)
#define TXBF_TXCV_BFWEIGHT_METHOD_RESET                              0x0 // 0
#define TXBF_NG_CVCACHE_MSB                                          7
#define TXBF_NG_CVCACHE_LSB                                          6
#define TXBF_NG_CVCACHE_MASK                                         0x000000c0
#define TXBF_NG_CVCACHE_GET(x)                                       (((x) & TXBF_NG_CVCACHE_MASK) >> TXBF_NG_CVCACHE_LSB)
#define TXBF_NG_CVCACHE_SET(x)                                       (((x) << TXBF_NG_CVCACHE_LSB) & TXBF_NG_CVCACHE_MASK)
#define TXBF_NG_CVCACHE_RESET                                        0x0 // 0
#define TXBF_NG_RPT_TX_MSB                                           5
#define TXBF_NG_RPT_TX_LSB                                           4
#define TXBF_NG_RPT_TX_MASK                                          0x00000030
#define TXBF_NG_RPT_TX_GET(x)                                        (((x) & TXBF_NG_RPT_TX_MASK) >> TXBF_NG_RPT_TX_LSB)
#define TXBF_NG_RPT_TX_SET(x)                                        (((x) << TXBF_NG_RPT_TX_LSB) & TXBF_NG_RPT_TX_MASK)
#define TXBF_NG_RPT_TX_RESET                                         0x0 // 0
#define TXBF_NB_TX_MSB                                               3
#define TXBF_NB_TX_LSB                                               2
#define TXBF_NB_TX_MASK                                              0x0000000c
#define TXBF_NB_TX_GET(x)                                            (((x) & TXBF_NB_TX_MASK) >> TXBF_NB_TX_LSB)
#define TXBF_NB_TX_SET(x)                                            (((x) << TXBF_NB_TX_LSB) & TXBF_NB_TX_MASK)
#define TXBF_NB_TX_RESET                                             0x3 // 3
#define TXBF_CB_TX_MSB                                               1
#define TXBF_CB_TX_LSB                                               0
#define TXBF_CB_TX_MASK                                              0x00000003
#define TXBF_CB_TX_GET(x)                                            (((x) & TXBF_CB_TX_MASK) >> TXBF_CB_TX_LSB)
#define TXBF_CB_TX_SET(x)                                            (((x) << TXBF_CB_TX_LSB) & TXBF_CB_TX_MASK)
#define TXBF_CB_TX_RESET                                             0x3 // 3
#define TXBF_ADDRESS                                                 0x10004
#define TXBF_OFFSET                                                  0x10004
// SW modifiable bits
#define TXBF_SW_MASK                                                 0x00007eff
// bits defined at reset
#define TXBF_RSTMASK                                                 0xffffffff
// reset value (ignore bits undefined at reset)
#define TXBF_RESET                                                   0x0000000f

// 32'h10008 (TXBF_TIMER)
#define TXBF_TIMER_ATIMEOUT_MSB                                      15
#define TXBF_TIMER_ATIMEOUT_LSB                                      8
#define TXBF_TIMER_ATIMEOUT_MASK                                     0x0000ff00
#define TXBF_TIMER_ATIMEOUT_GET(x)                                   (((x) & TXBF_TIMER_ATIMEOUT_MASK) >> TXBF_TIMER_ATIMEOUT_LSB)
#define TXBF_TIMER_ATIMEOUT_SET(x)                                   (((x) << TXBF_TIMER_ATIMEOUT_LSB) & TXBF_TIMER_ATIMEOUT_MASK)
#define TXBF_TIMER_ATIMEOUT_RESET                                    0x3 // 3
#define TXBF_TIMER_TIMEOUT_MSB                                       7
#define TXBF_TIMER_TIMEOUT_LSB                                       0
#define TXBF_TIMER_TIMEOUT_MASK                                      0x000000ff
#define TXBF_TIMER_TIMEOUT_GET(x)                                    (((x) & TXBF_TIMER_TIMEOUT_MASK) >> TXBF_TIMER_TIMEOUT_LSB)
#define TXBF_TIMER_TIMEOUT_SET(x)                                    (((x) << TXBF_TIMER_TIMEOUT_LSB) & TXBF_TIMER_TIMEOUT_MASK)
#define TXBF_TIMER_TIMEOUT_RESET                                     0x3 // 3
#define TXBF_TIMER_ADDRESS                                           0x10008
#define TXBF_TIMER_OFFSET                                            0x10008
// SW modifiable bits
#define TXBF_TIMER_SW_MASK                                           0x0000ffff
// bits defined at reset
#define TXBF_TIMER_RSTMASK                                           0xffffffff
// reset value (ignore bits undefined at reset)
#define TXBF_TIMER_RESET                                             0x00000303

// 32'h1000c (TXBF_SW)
#define TXBF_SW_CONDITION_NUMBER_MSB                                 26
#define TXBF_SW_CONDITION_NUMBER_LSB                                 22
#define TXBF_SW_CONDITION_NUMBER_MASK                                0x07c00000
#define TXBF_SW_CONDITION_NUMBER_GET(x)                              (((x) & TXBF_SW_CONDITION_NUMBER_MASK) >> TXBF_SW_CONDITION_NUMBER_LSB)
#define TXBF_SW_CONDITION_NUMBER_SET(x)                              (((x) << TXBF_SW_CONDITION_NUMBER_LSB) & TXBF_SW_CONDITION_NUMBER_MASK)
#define TXBF_SW_CONDITION_NUMBER_RESET                               0x0 // 0
#define TXBF_SW_WALSH_CSD_MODE_MSB                                   21
#define TXBF_SW_WALSH_CSD_MODE_LSB                                   21
#define TXBF_SW_WALSH_CSD_MODE_MASK                                  0x00200000
#define TXBF_SW_WALSH_CSD_MODE_GET(x)                                (((x) & TXBF_SW_WALSH_CSD_MODE_MASK) >> TXBF_SW_WALSH_CSD_MODE_LSB)
#define TXBF_SW_WALSH_CSD_MODE_SET(x)                                (((x) << TXBF_SW_WALSH_CSD_MODE_LSB) & TXBF_SW_WALSH_CSD_MODE_MASK)
#define TXBF_SW_WALSH_CSD_MODE_RESET                                 0x0 // 0
#define TXBF_SW_LRU_RD_ACK_MSB                                       20
#define TXBF_SW_LRU_RD_ACK_LSB                                       20
#define TXBF_SW_LRU_RD_ACK_MASK                                      0x00100000
#define TXBF_SW_LRU_RD_ACK_GET(x)                                    (((x) & TXBF_SW_LRU_RD_ACK_MASK) >> TXBF_SW_LRU_RD_ACK_LSB)
#define TXBF_SW_LRU_RD_ACK_SET(x)                                    (((x) << TXBF_SW_LRU_RD_ACK_LSB) & TXBF_SW_LRU_RD_ACK_MASK)
#define TXBF_SW_LRU_RD_ACK_RESET                                     0x0 // 0
#define TXBF_SW_LRU_WR_ACK_MSB                                       19
#define TXBF_SW_LRU_WR_ACK_LSB                                       19
#define TXBF_SW_LRU_WR_ACK_MASK                                      0x00080000
#define TXBF_SW_LRU_WR_ACK_GET(x)                                    (((x) & TXBF_SW_LRU_WR_ACK_MASK) >> TXBF_SW_LRU_WR_ACK_LSB)
#define TXBF_SW_LRU_WR_ACK_SET(x)                                    (((x) << TXBF_SW_LRU_WR_ACK_LSB) & TXBF_SW_LRU_WR_ACK_MASK)
#define TXBF_SW_LRU_WR_ACK_RESET                                     0x0 // 0
#define TXBF_SW_DEST_IDX_MSB                                         18
#define TXBF_SW_DEST_IDX_LSB                                         12
#define TXBF_SW_DEST_IDX_MASK                                        0x0007f000
#define TXBF_SW_DEST_IDX_GET(x)                                      (((x) & TXBF_SW_DEST_IDX_MASK) >> TXBF_SW_DEST_IDX_LSB)
#define TXBF_SW_DEST_IDX_SET(x)                                      (((x) << TXBF_SW_DEST_IDX_LSB) & TXBF_SW_DEST_IDX_MASK)
#define TXBF_SW_DEST_IDX_RESET                                       0x0 // 0
#define TXBF_SW_LRU_EN_MSB                                           11
#define TXBF_SW_LRU_EN_LSB                                           11
#define TXBF_SW_LRU_EN_MASK                                          0x00000800
#define TXBF_SW_LRU_EN_GET(x)                                        (((x) & TXBF_SW_LRU_EN_MASK) >> TXBF_SW_LRU_EN_LSB)
#define TXBF_SW_LRU_EN_SET(x)                                        (((x) << TXBF_SW_LRU_EN_LSB) & TXBF_SW_LRU_EN_MASK)
#define TXBF_SW_LRU_EN_RESET                                         0x0 // 0
#define TXBF_SW_LRU_ADDR_MSB                                         9
#define TXBF_SW_LRU_ADDR_LSB                                         1
#define TXBF_SW_LRU_ADDR_MASK                                        0x000003fe
#define TXBF_SW_LRU_ADDR_GET(x)                                      (((x) & TXBF_SW_LRU_ADDR_MASK) >> TXBF_SW_LRU_ADDR_LSB)
#define TXBF_SW_LRU_ADDR_SET(x)                                      (((x) << TXBF_SW_LRU_ADDR_LSB) & TXBF_SW_LRU_ADDR_MASK)
#define TXBF_SW_LRU_ADDR_RESET                                       0x0 // 0
#define TXBF_SW_LRU_ACK_MSB                                          0
#define TXBF_SW_LRU_ACK_LSB                                          0
#define TXBF_SW_LRU_ACK_MASK                                         0x00000001
#define TXBF_SW_LRU_ACK_GET(x)                                       (((x) & TXBF_SW_LRU_ACK_MASK) >> TXBF_SW_LRU_ACK_LSB)
#define TXBF_SW_LRU_ACK_SET(x)                                       (((x) << TXBF_SW_LRU_ACK_LSB) & TXBF_SW_LRU_ACK_MASK)
#define TXBF_SW_LRU_ACK_RESET                                        0x0 // 0
#define TXBF_SW_ADDRESS                                              0x1000c
#define TXBF_SW_OFFSET                                               0x1000c
// SW modifiable bits
#define TXBF_SW_SW_MASK                                              0x07fffbff
// bits defined at reset
#define TXBF_SW_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define TXBF_SW_RESET                                                0x00000000

// 32'h10010 (TXBF_SM)
#define TXBF_SM_OBS_MSB                                              31
#define TXBF_SM_OBS_LSB                                              0
#define TXBF_SM_OBS_MASK                                             0xffffffff
#define TXBF_SM_OBS_GET(x)                                           (((x) & TXBF_SM_OBS_MASK) >> TXBF_SM_OBS_LSB)
#define TXBF_SM_OBS_SET(x)                                           (((x) << TXBF_SM_OBS_LSB) & TXBF_SM_OBS_MASK)
#define TXBF_SM_OBS_RESET                                            0x0 // 0
#define TXBF_SM_ADDRESS                                              0x10010
#define TXBF_SM_OFFSET                                               0x10010
// SW modifiable bits
#define TXBF_SM_SW_MASK                                              0xffffffff
// bits defined at reset
#define TXBF_SM_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define TXBF_SM_RESET                                                0x00000000

// 32'h10014 (TXBF1_CNTL)
#define TXBF1_CNTL_OBS_MSB                                           31
#define TXBF1_CNTL_OBS_LSB                                           0
#define TXBF1_CNTL_OBS_MASK                                          0xffffffff
#define TXBF1_CNTL_OBS_GET(x)                                        (((x) & TXBF1_CNTL_OBS_MASK) >> TXBF1_CNTL_OBS_LSB)
#define TXBF1_CNTL_OBS_SET(x)                                        (((x) << TXBF1_CNTL_OBS_LSB) & TXBF1_CNTL_OBS_MASK)
#define TXBF1_CNTL_OBS_RESET                                         0x0 // 0
#define TXBF1_CNTL_ADDRESS                                           0x10014
#define TXBF1_CNTL_OFFSET                                            0x10014
// SW modifiable bits
#define TXBF1_CNTL_SW_MASK                                           0xffffffff
// bits defined at reset
#define TXBF1_CNTL_RSTMASK                                           0xffffffff
// reset value (ignore bits undefined at reset)
#define TXBF1_CNTL_RESET                                             0x00000000

// 32'h10018 (TXBF2_CNTL)
#define TXBF2_CNTL_OBS_MSB                                           31
#define TXBF2_CNTL_OBS_LSB                                           0
#define TXBF2_CNTL_OBS_MASK                                          0xffffffff
#define TXBF2_CNTL_OBS_GET(x)                                        (((x) & TXBF2_CNTL_OBS_MASK) >> TXBF2_CNTL_OBS_LSB)
#define TXBF2_CNTL_OBS_SET(x)                                        (((x) << TXBF2_CNTL_OBS_LSB) & TXBF2_CNTL_OBS_MASK)
#define TXBF2_CNTL_OBS_RESET                                         0x0 // 0
#define TXBF2_CNTL_ADDRESS                                           0x10018
#define TXBF2_CNTL_OFFSET                                            0x10018
// SW modifiable bits
#define TXBF2_CNTL_SW_MASK                                           0xffffffff
// bits defined at reset
#define TXBF2_CNTL_RSTMASK                                           0xffffffff
// reset value (ignore bits undefined at reset)
#define TXBF2_CNTL_RESET                                             0x00000000

// 32'h1001c (TXBF3_CNTL)
#define TXBF3_CNTL_OBS_MSB                                           31
#define TXBF3_CNTL_OBS_LSB                                           0
#define TXBF3_CNTL_OBS_MASK                                          0xffffffff
#define TXBF3_CNTL_OBS_GET(x)                                        (((x) & TXBF3_CNTL_OBS_MASK) >> TXBF3_CNTL_OBS_LSB)
#define TXBF3_CNTL_OBS_SET(x)                                        (((x) << TXBF3_CNTL_OBS_LSB) & TXBF3_CNTL_OBS_MASK)
#define TXBF3_CNTL_OBS_RESET                                         0x0 // 0
#define TXBF3_CNTL_ADDRESS                                           0x1001c
#define TXBF3_CNTL_OFFSET                                            0x1001c
// SW modifiable bits
#define TXBF3_CNTL_SW_MASK                                           0xffffffff
// bits defined at reset
#define TXBF3_CNTL_RSTMASK                                           0xffffffff
// reset value (ignore bits undefined at reset)
#define TXBF3_CNTL_RESET                                             0x00000000

// 32'h10020 (TXBF4_CNTL)
#define TXBF4_CNTL_OBS_MSB                                           31
#define TXBF4_CNTL_OBS_LSB                                           0
#define TXBF4_CNTL_OBS_MASK                                          0xffffffff
#define TXBF4_CNTL_OBS_GET(x)                                        (((x) & TXBF4_CNTL_OBS_MASK) >> TXBF4_CNTL_OBS_LSB)
#define TXBF4_CNTL_OBS_SET(x)                                        (((x) << TXBF4_CNTL_OBS_LSB) & TXBF4_CNTL_OBS_MASK)
#define TXBF4_CNTL_OBS_RESET                                         0x0 // 0
#define TXBF4_CNTL_ADDRESS                                           0x10020
#define TXBF4_CNTL_OFFSET                                            0x10020
// SW modifiable bits
#define TXBF4_CNTL_SW_MASK                                           0xffffffff
// bits defined at reset
#define TXBF4_CNTL_RSTMASK                                           0xffffffff
// reset value (ignore bits undefined at reset)
#define TXBF4_CNTL_RESET                                             0x00000000

// 32'h10024 (TXBF5_CNTL)
#define TXBF5_CNTL_OBS_MSB                                           31
#define TXBF5_CNTL_OBS_LSB                                           0
#define TXBF5_CNTL_OBS_MASK                                          0xffffffff
#define TXBF5_CNTL_OBS_GET(x)                                        (((x) & TXBF5_CNTL_OBS_MASK) >> TXBF5_CNTL_OBS_LSB)
#define TXBF5_CNTL_OBS_SET(x)                                        (((x) << TXBF5_CNTL_OBS_LSB) & TXBF5_CNTL_OBS_MASK)
#define TXBF5_CNTL_OBS_RESET                                         0x0 // 0
#define TXBF5_CNTL_ADDRESS                                           0x10024
#define TXBF5_CNTL_OFFSET                                            0x10024
// SW modifiable bits
#define TXBF5_CNTL_SW_MASK                                           0xffffffff
// bits defined at reset
#define TXBF5_CNTL_RSTMASK                                           0xffffffff
// reset value (ignore bits undefined at reset)
#define TXBF5_CNTL_RESET                                             0x00000000

// 32'h10028 (TXBF6_CNTL)
#define TXBF6_CNTL_OBS_MSB                                           31
#define TXBF6_CNTL_OBS_LSB                                           0
#define TXBF6_CNTL_OBS_MASK                                          0xffffffff
#define TXBF6_CNTL_OBS_GET(x)                                        (((x) & TXBF6_CNTL_OBS_MASK) >> TXBF6_CNTL_OBS_LSB)
#define TXBF6_CNTL_OBS_SET(x)                                        (((x) << TXBF6_CNTL_OBS_LSB) & TXBF6_CNTL_OBS_MASK)
#define TXBF6_CNTL_OBS_RESET                                         0x0 // 0
#define TXBF6_CNTL_ADDRESS                                           0x10028
#define TXBF6_CNTL_OFFSET                                            0x10028
// SW modifiable bits
#define TXBF6_CNTL_SW_MASK                                           0xffffffff
// bits defined at reset
#define TXBF6_CNTL_RSTMASK                                           0xffffffff
// reset value (ignore bits undefined at reset)
#define TXBF6_CNTL_RESET                                             0x00000000

// 32'h1002c (TXBF7_CNTL)
#define TXBF7_CNTL_OBS_MSB                                           31
#define TXBF7_CNTL_OBS_LSB                                           0
#define TXBF7_CNTL_OBS_MASK                                          0xffffffff
#define TXBF7_CNTL_OBS_GET(x)                                        (((x) & TXBF7_CNTL_OBS_MASK) >> TXBF7_CNTL_OBS_LSB)
#define TXBF7_CNTL_OBS_SET(x)                                        (((x) << TXBF7_CNTL_OBS_LSB) & TXBF7_CNTL_OBS_MASK)
#define TXBF7_CNTL_OBS_RESET                                         0x0 // 0
#define TXBF7_CNTL_ADDRESS                                           0x1002c
#define TXBF7_CNTL_OFFSET                                            0x1002c
// SW modifiable bits
#define TXBF7_CNTL_SW_MASK                                           0xffffffff
// bits defined at reset
#define TXBF7_CNTL_RSTMASK                                           0xffffffff
// reset value (ignore bits undefined at reset)
#define TXBF7_CNTL_RESET                                             0x00000000

// 32'h10030 (TXBF8_CNTL)
#define TXBF8_CNTL_OBS_MSB                                           31
#define TXBF8_CNTL_OBS_LSB                                           0
#define TXBF8_CNTL_OBS_MASK                                          0xffffffff
#define TXBF8_CNTL_OBS_GET(x)                                        (((x) & TXBF8_CNTL_OBS_MASK) >> TXBF8_CNTL_OBS_LSB)
#define TXBF8_CNTL_OBS_SET(x)                                        (((x) << TXBF8_CNTL_OBS_LSB) & TXBF8_CNTL_OBS_MASK)
#define TXBF8_CNTL_OBS_RESET                                         0x0 // 0
#define TXBF8_CNTL_ADDRESS                                           0x10030
#define TXBF8_CNTL_OFFSET                                            0x10030
// SW modifiable bits
#define TXBF8_CNTL_SW_MASK                                           0xffffffff
// bits defined at reset
#define TXBF8_CNTL_RSTMASK                                           0xffffffff
// reset value (ignore bits undefined at reset)
#define TXBF8_CNTL_RESET                                             0x00000000

// 32'h11000 (RC0_0)
#define RC0_0_DATA_MSB                                               31
#define RC0_0_DATA_LSB                                               0
#define RC0_0_DATA_MASK                                              0xffffffff
#define RC0_0_DATA_GET(x)                                            (((x) & RC0_0_DATA_MASK) >> RC0_0_DATA_LSB)
#define RC0_0_DATA_SET(x)                                            (((x) << RC0_0_DATA_LSB) & RC0_0_DATA_MASK)
#define RC0_0_DATA_RESET                                             0x0 // 0
#define RC0_0_ADDRESS                                                0x11000
#define RC0_0_OFFSET                                                 0x11000
#define RC0_ADDRESS                                                  RC0_0_ADDRESS
#define RC0_OFFSET                                                   RC0_0_OFFSET
// SW modifiable bits
#define RC0_0_SW_MASK                                                0xffffffff
// bits defined at reset
#define RC0_0_RSTMASK                                                0x00000000
// reset value (ignore bits undefined at reset)
#define RC0_0_RESET                                                  0x00000000

// 32'h11200 (RC1_0)
#define RC1_0_DATA_MSB                                               31
#define RC1_0_DATA_LSB                                               0
#define RC1_0_DATA_MASK                                              0xffffffff
#define RC1_0_DATA_GET(x)                                            (((x) & RC1_0_DATA_MASK) >> RC1_0_DATA_LSB)
#define RC1_0_DATA_SET(x)                                            (((x) << RC1_0_DATA_LSB) & RC1_0_DATA_MASK)
#define RC1_0_DATA_RESET                                             0x0 // 0
#define RC1_0_ADDRESS                                                0x11200
#define RC1_0_OFFSET                                                 0x11200
#define RC1_ADDRESS                                                  RC1_0_ADDRESS
#define RC1_OFFSET                                                   RC1_0_OFFSET
// SW modifiable bits
#define RC1_0_SW_MASK                                                0xffffffff
// bits defined at reset
#define RC1_0_RSTMASK                                                0x00000000
// reset value (ignore bits undefined at reset)
#define RC1_0_RESET                                                  0x00000000

// 32'h11400 (SVD_MEM0_0)
#define SVD_MEM0_0_DATA_MSB                                          31
#define SVD_MEM0_0_DATA_LSB                                          0
#define SVD_MEM0_0_DATA_MASK                                         0xffffffff
#define SVD_MEM0_0_DATA_GET(x)                                       (((x) & SVD_MEM0_0_DATA_MASK) >> SVD_MEM0_0_DATA_LSB)
#define SVD_MEM0_0_DATA_SET(x)                                       (((x) << SVD_MEM0_0_DATA_LSB) & SVD_MEM0_0_DATA_MASK)
#define SVD_MEM0_0_DATA_RESET                                        0x0 // 0
#define SVD_MEM0_0_ADDRESS                                           0x11400
#define SVD_MEM0_0_OFFSET                                            0x11400
#define SVD_MEM0_ADDRESS                                             SVD_MEM0_0_ADDRESS
#define SVD_MEM0_OFFSET                                              SVD_MEM0_0_OFFSET
// SW modifiable bits
#define SVD_MEM0_0_SW_MASK                                           0xffffffff
// bits defined at reset
#define SVD_MEM0_0_RSTMASK                                           0x00000000
// reset value (ignore bits undefined at reset)
#define SVD_MEM0_0_RESET                                             0x00000000

// 32'h11600 (SVD_MEM1_0)
#define SVD_MEM1_0_DATA_MSB                                          31
#define SVD_MEM1_0_DATA_LSB                                          0
#define SVD_MEM1_0_DATA_MASK                                         0xffffffff
#define SVD_MEM1_0_DATA_GET(x)                                       (((x) & SVD_MEM1_0_DATA_MASK) >> SVD_MEM1_0_DATA_LSB)
#define SVD_MEM1_0_DATA_SET(x)                                       (((x) << SVD_MEM1_0_DATA_LSB) & SVD_MEM1_0_DATA_MASK)
#define SVD_MEM1_0_DATA_RESET                                        0x0 // 0
#define SVD_MEM1_0_ADDRESS                                           0x11600
#define SVD_MEM1_0_OFFSET                                            0x11600
#define SVD_MEM1_ADDRESS                                             SVD_MEM1_0_ADDRESS
#define SVD_MEM1_OFFSET                                              SVD_MEM1_0_OFFSET
// SW modifiable bits
#define SVD_MEM1_0_SW_MASK                                           0xffffffff
// bits defined at reset
#define SVD_MEM1_0_RSTMASK                                           0x00000000
// reset value (ignore bits undefined at reset)
#define SVD_MEM1_0_RESET                                             0x00000000

// 32'h11800 (SVD_MEM2_0)
#define SVD_MEM2_0_DATA_MSB                                          31
#define SVD_MEM2_0_DATA_LSB                                          0
#define SVD_MEM2_0_DATA_MASK                                         0xffffffff
#define SVD_MEM2_0_DATA_GET(x)                                       (((x) & SVD_MEM2_0_DATA_MASK) >> SVD_MEM2_0_DATA_LSB)
#define SVD_MEM2_0_DATA_SET(x)                                       (((x) << SVD_MEM2_0_DATA_LSB) & SVD_MEM2_0_DATA_MASK)
#define SVD_MEM2_0_DATA_RESET                                        0x0 // 0
#define SVD_MEM2_0_ADDRESS                                           0x11800
#define SVD_MEM2_0_OFFSET                                            0x11800
#define SVD_MEM2_ADDRESS                                             SVD_MEM2_0_ADDRESS
#define SVD_MEM2_OFFSET                                              SVD_MEM2_0_OFFSET
// SW modifiable bits
#define SVD_MEM2_0_SW_MASK                                           0xffffffff
// bits defined at reset
#define SVD_MEM2_0_RSTMASK                                           0x00000000
// reset value (ignore bits undefined at reset)
#define SVD_MEM2_0_RESET                                             0x00000000

// 32'h11a00 (SVD_MEM3_0)
#define SVD_MEM3_0_DATA_MSB                                          31
#define SVD_MEM3_0_DATA_LSB                                          0
#define SVD_MEM3_0_DATA_MASK                                         0xffffffff
#define SVD_MEM3_0_DATA_GET(x)                                       (((x) & SVD_MEM3_0_DATA_MASK) >> SVD_MEM3_0_DATA_LSB)
#define SVD_MEM3_0_DATA_SET(x)                                       (((x) << SVD_MEM3_0_DATA_LSB) & SVD_MEM3_0_DATA_MASK)
#define SVD_MEM3_0_DATA_RESET                                        0x0 // 0
#define SVD_MEM3_0_ADDRESS                                           0x11a00
#define SVD_MEM3_0_OFFSET                                            0x11a00
#define SVD_MEM3_ADDRESS                                             SVD_MEM3_0_ADDRESS
#define SVD_MEM3_OFFSET                                              SVD_MEM3_0_OFFSET
// SW modifiable bits
#define SVD_MEM3_0_SW_MASK                                           0xffffffff
// bits defined at reset
#define SVD_MEM3_0_RSTMASK                                           0x00000000
// reset value (ignore bits undefined at reset)
#define SVD_MEM3_0_RESET                                             0x00000000

// 32'h11c00 (SVD_MEM4_0)
#define SVD_MEM4_0_DATA_MSB                                          31
#define SVD_MEM4_0_DATA_LSB                                          0
#define SVD_MEM4_0_DATA_MASK                                         0xffffffff
#define SVD_MEM4_0_DATA_GET(x)                                       (((x) & SVD_MEM4_0_DATA_MASK) >> SVD_MEM4_0_DATA_LSB)
#define SVD_MEM4_0_DATA_SET(x)                                       (((x) << SVD_MEM4_0_DATA_LSB) & SVD_MEM4_0_DATA_MASK)
#define SVD_MEM4_0_DATA_RESET                                        0x0 // 0
#define SVD_MEM4_0_ADDRESS                                           0x11c00
#define SVD_MEM4_0_OFFSET                                            0x11c00
#define SVD_MEM4_ADDRESS                                             SVD_MEM4_0_ADDRESS
#define SVD_MEM4_OFFSET                                              SVD_MEM4_0_OFFSET
// SW modifiable bits
#define SVD_MEM4_0_SW_MASK                                           0xffffffff
// bits defined at reset
#define SVD_MEM4_0_RSTMASK                                           0x00000000
// reset value (ignore bits undefined at reset)
#define SVD_MEM4_0_RESET                                             0x00000000

// 32'h12400 (CVCACHE_0)
#define CVCACHE_0_DATA_MSB                                           31
#define CVCACHE_0_DATA_LSB                                           0
#define CVCACHE_0_DATA_MASK                                          0xffffffff
#define CVCACHE_0_DATA_GET(x)                                        (((x) & CVCACHE_0_DATA_MASK) >> CVCACHE_0_DATA_LSB)
#define CVCACHE_0_DATA_SET(x)                                        (((x) << CVCACHE_0_DATA_LSB) & CVCACHE_0_DATA_MASK)
#define CVCACHE_0_DATA_RESET                                         0x0 // 0
#define CVCACHE_0_ADDRESS                                            0x12400
#define CVCACHE_0_OFFSET                                             0x12400
#define CVCACHE_ADDRESS                                              CVCACHE_0_ADDRESS
#define CVCACHE_OFFSET                                               CVCACHE_0_OFFSET
// SW modifiable bits
#define CVCACHE_0_SW_MASK                                            0xffffffff
// bits defined at reset
#define CVCACHE_0_RSTMASK                                            0x00000000
// reset value (ignore bits undefined at reset)
#define CVCACHE_0_RESET                                              0x00000000


#endif /* _SVD_REG_H_ */
