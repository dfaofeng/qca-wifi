//                                                                             
// File:       ./bt_coex_reg.h                                                 
// Creator:    aveetil                                                         
// Time:       Monday Apr 4, 2011 [6:45:38 pm]                                 
//                                                                             
// Path:       /trees/aveetil/anoop-wlmac/ip/athr/wifi_mac/rtl/dev/bt_coex/blueprint
// Arguments:  /cad/denali/blueprint/3.7.3//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -ch -Wdesc bt_coex_reg.rdl    
//                                                                             
// Sources:    /trees/aveetil/anoop-wlmac/ip/athr/wifi_mac/rtl/dev/bt_coex/blueprint/bt_coex_reg.rdl
//             /trees/aveetil/anoop-wlmac/ip/athr/wifi_mac/shared/env/blueprint/ath_vrh.pm
//             /cad/local/lib/perl/Pinfo.pm                                    
//                                                                             
// Blueprint:   3.7.3 (Fri Aug 29 12:39:16 PDT 2008)                           
// Machine:    thanarupi.users.atheros.com                                     
// OS:         Linux 2.6.9-89.ELsmp                                            
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _BT_COEX_REG_H_
#define _BT_COEX_REG_H_
// 32'h0000 (WLAN_INT_STATUS)
#define WLAN_INT_STATUS_BTCOEX_MSB                                   0
#define WLAN_INT_STATUS_BTCOEX_LSB                                   0
#define WLAN_INT_STATUS_BTCOEX_MASK                                  0x00000001
#define WLAN_INT_STATUS_BTCOEX_GET(x)                                (((x) & WLAN_INT_STATUS_BTCOEX_MASK) >> WLAN_INT_STATUS_BTCOEX_LSB)
#define WLAN_INT_STATUS_BTCOEX_SET(x)                                (((x) << WLAN_INT_STATUS_BTCOEX_LSB) & WLAN_INT_STATUS_BTCOEX_MASK)
#define WLAN_INT_STATUS_BTCOEX_RESET                                 0x0 // 0
#define WLAN_INT_STATUS_ADDRESS                                      0x0000
#define WLAN_INT_STATUS_OFFSET                                       0x0000
// SW modifiable bits
#define WLAN_INT_STATUS_SW_MASK                                      0x00000001
// bits defined at reset
#define WLAN_INT_STATUS_RSTMASK                                      0xffffffff
// reset value (ignore bits undefined at reset)
#define WLAN_INT_STATUS_RESET                                        0x00000000

// 32'h0004 (BTCOEXCTRL)
#define BTCOEXCTRL_WBSYNC_ON_BEACON_MSB                              25
#define BTCOEXCTRL_WBSYNC_ON_BEACON_LSB                              25
#define BTCOEXCTRL_WBSYNC_ON_BEACON_MASK                             0x02000000
#define BTCOEXCTRL_WBSYNC_ON_BEACON_GET(x)                           (((x) & BTCOEXCTRL_WBSYNC_ON_BEACON_MASK) >> BTCOEXCTRL_WBSYNC_ON_BEACON_LSB)
#define BTCOEXCTRL_WBSYNC_ON_BEACON_SET(x)                           (((x) << BTCOEXCTRL_WBSYNC_ON_BEACON_LSB) & BTCOEXCTRL_WBSYNC_ON_BEACON_MASK)
#define BTCOEXCTRL_WBSYNC_ON_BEACON_RESET                            0x0 // 0
#define BTCOEXCTRL_PTA_MODE_MSB                                      24
#define BTCOEXCTRL_PTA_MODE_LSB                                      23
#define BTCOEXCTRL_PTA_MODE_MASK                                     0x01800000
#define BTCOEXCTRL_PTA_MODE_GET(x)                                   (((x) & BTCOEXCTRL_PTA_MODE_MASK) >> BTCOEXCTRL_PTA_MODE_LSB)
#define BTCOEXCTRL_PTA_MODE_SET(x)                                   (((x) << BTCOEXCTRL_PTA_MODE_LSB) & BTCOEXCTRL_PTA_MODE_MASK)
#define BTCOEXCTRL_PTA_MODE_RESET                                    0x0 // 0
#define BTCOEXCTRL_FREQ_TIME_MSB                                     22
#define BTCOEXCTRL_FREQ_TIME_LSB                                     18
#define BTCOEXCTRL_FREQ_TIME_MASK                                    0x007c0000
#define BTCOEXCTRL_FREQ_TIME_GET(x)                                  (((x) & BTCOEXCTRL_FREQ_TIME_MASK) >> BTCOEXCTRL_FREQ_TIME_LSB)
#define BTCOEXCTRL_FREQ_TIME_SET(x)                                  (((x) << BTCOEXCTRL_FREQ_TIME_LSB) & BTCOEXCTRL_FREQ_TIME_MASK)
#define BTCOEXCTRL_FREQ_TIME_RESET                                   0x16 // 22
#define BTCOEXCTRL_PRIORITY_TIME_MSB                                 17
#define BTCOEXCTRL_PRIORITY_TIME_LSB                                 12
#define BTCOEXCTRL_PRIORITY_TIME_MASK                                0x0003f000
#define BTCOEXCTRL_PRIORITY_TIME_GET(x)                              (((x) & BTCOEXCTRL_PRIORITY_TIME_MASK) >> BTCOEXCTRL_PRIORITY_TIME_LSB)
#define BTCOEXCTRL_PRIORITY_TIME_SET(x)                              (((x) << BTCOEXCTRL_PRIORITY_TIME_LSB) & BTCOEXCTRL_PRIORITY_TIME_MASK)
#define BTCOEXCTRL_PRIORITY_TIME_RESET                               0x24 // 36
#define BTCOEXCTRL_SYNC_DET_EN_MSB                                   11
#define BTCOEXCTRL_SYNC_DET_EN_LSB                                   11
#define BTCOEXCTRL_SYNC_DET_EN_MASK                                  0x00000800
#define BTCOEXCTRL_SYNC_DET_EN_GET(x)                                (((x) & BTCOEXCTRL_SYNC_DET_EN_MASK) >> BTCOEXCTRL_SYNC_DET_EN_LSB)
#define BTCOEXCTRL_SYNC_DET_EN_SET(x)                                (((x) << BTCOEXCTRL_SYNC_DET_EN_LSB) & BTCOEXCTRL_SYNC_DET_EN_MASK)
#define BTCOEXCTRL_SYNC_DET_EN_RESET                                 0x0 // 0
#define BTCOEXCTRL_IDLE_CNT_EN_MSB                                   10
#define BTCOEXCTRL_IDLE_CNT_EN_LSB                                   10
#define BTCOEXCTRL_IDLE_CNT_EN_MASK                                  0x00000400
#define BTCOEXCTRL_IDLE_CNT_EN_GET(x)                                (((x) & BTCOEXCTRL_IDLE_CNT_EN_MASK) >> BTCOEXCTRL_IDLE_CNT_EN_LSB)
#define BTCOEXCTRL_IDLE_CNT_EN_SET(x)                                (((x) << BTCOEXCTRL_IDLE_CNT_EN_LSB) & BTCOEXCTRL_IDLE_CNT_EN_MASK)
#define BTCOEXCTRL_IDLE_CNT_EN_RESET                                 0x0 // 0
#define BTCOEXCTRL_FRAME_CNT_EN_MSB                                  9
#define BTCOEXCTRL_FRAME_CNT_EN_LSB                                  9
#define BTCOEXCTRL_FRAME_CNT_EN_MASK                                 0x00000200
#define BTCOEXCTRL_FRAME_CNT_EN_GET(x)                               (((x) & BTCOEXCTRL_FRAME_CNT_EN_MASK) >> BTCOEXCTRL_FRAME_CNT_EN_LSB)
#define BTCOEXCTRL_FRAME_CNT_EN_SET(x)                               (((x) << BTCOEXCTRL_FRAME_CNT_EN_LSB) & BTCOEXCTRL_FRAME_CNT_EN_MASK)
#define BTCOEXCTRL_FRAME_CNT_EN_RESET                                0x0 // 0
#define BTCOEXCTRL_CLK_CNT_EN_MSB                                    8
#define BTCOEXCTRL_CLK_CNT_EN_LSB                                    8
#define BTCOEXCTRL_CLK_CNT_EN_MASK                                   0x00000100
#define BTCOEXCTRL_CLK_CNT_EN_GET(x)                                 (((x) & BTCOEXCTRL_CLK_CNT_EN_MASK) >> BTCOEXCTRL_CLK_CNT_EN_LSB)
#define BTCOEXCTRL_CLK_CNT_EN_SET(x)                                 (((x) << BTCOEXCTRL_CLK_CNT_EN_LSB) & BTCOEXCTRL_CLK_CNT_EN_MASK)
#define BTCOEXCTRL_CLK_CNT_EN_RESET                                  0x0 // 0
#define BTCOEXCTRL_GAP_MSB                                           7
#define BTCOEXCTRL_GAP_LSB                                           0
#define BTCOEXCTRL_GAP_MASK                                          0x000000ff
#define BTCOEXCTRL_GAP_GET(x)                                        (((x) & BTCOEXCTRL_GAP_MASK) >> BTCOEXCTRL_GAP_LSB)
#define BTCOEXCTRL_GAP_SET(x)                                        (((x) << BTCOEXCTRL_GAP_LSB) & BTCOEXCTRL_GAP_MASK)
#define BTCOEXCTRL_GAP_RESET                                         0x0 // 0
#define BTCOEXCTRL_ADDRESS                                           0x0004
#define BTCOEXCTRL_OFFSET                                            0x0004
// SW modifiable bits
#define BTCOEXCTRL_SW_MASK                                           0x03ffffff
// bits defined at reset
#define BTCOEXCTRL_RSTMASK                                           0xffffffff
// reset value (ignore bits undefined at reset)
#define BTCOEXCTRL_RESET                                             0x005a4000

// 32'h0008 (WBSYNC_PRIORITY1)
#define WBSYNC_PRIORITY1_BITMAP_MSB                                  31
#define WBSYNC_PRIORITY1_BITMAP_LSB                                  0
#define WBSYNC_PRIORITY1_BITMAP_MASK                                 0xffffffff
#define WBSYNC_PRIORITY1_BITMAP_GET(x)                               (((x) & WBSYNC_PRIORITY1_BITMAP_MASK) >> WBSYNC_PRIORITY1_BITMAP_LSB)
#define WBSYNC_PRIORITY1_BITMAP_SET(x)                               (((x) << WBSYNC_PRIORITY1_BITMAP_LSB) & WBSYNC_PRIORITY1_BITMAP_MASK)
#define WBSYNC_PRIORITY1_BITMAP_RESET                                0x0 // 0
#define WBSYNC_PRIORITY1_ADDRESS                                     0x0008
#define WBSYNC_PRIORITY1_OFFSET                                      0x0008
// SW modifiable bits
#define WBSYNC_PRIORITY1_SW_MASK                                     0xffffffff
// bits defined at reset
#define WBSYNC_PRIORITY1_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define WBSYNC_PRIORITY1_RESET                                       0x00000000

// 32'h000c (WBSYNC_PRIORITY2)
#define WBSYNC_PRIORITY2_BITMAP_MSB                                  31
#define WBSYNC_PRIORITY2_BITMAP_LSB                                  0
#define WBSYNC_PRIORITY2_BITMAP_MASK                                 0xffffffff
#define WBSYNC_PRIORITY2_BITMAP_GET(x)                               (((x) & WBSYNC_PRIORITY2_BITMAP_MASK) >> WBSYNC_PRIORITY2_BITMAP_LSB)
#define WBSYNC_PRIORITY2_BITMAP_SET(x)                               (((x) << WBSYNC_PRIORITY2_BITMAP_LSB) & WBSYNC_PRIORITY2_BITMAP_MASK)
#define WBSYNC_PRIORITY2_BITMAP_RESET                                0x0 // 0
#define WBSYNC_PRIORITY2_ADDRESS                                     0x000c
#define WBSYNC_PRIORITY2_OFFSET                                      0x000c
// SW modifiable bits
#define WBSYNC_PRIORITY2_SW_MASK                                     0xffffffff
// bits defined at reset
#define WBSYNC_PRIORITY2_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define WBSYNC_PRIORITY2_RESET                                       0x00000000

// 32'h0010 (WBSYNC_PRIORITY3)
#define WBSYNC_PRIORITY3_BITMAP_MSB                                  31
#define WBSYNC_PRIORITY3_BITMAP_LSB                                  0
#define WBSYNC_PRIORITY3_BITMAP_MASK                                 0xffffffff
#define WBSYNC_PRIORITY3_BITMAP_GET(x)                               (((x) & WBSYNC_PRIORITY3_BITMAP_MASK) >> WBSYNC_PRIORITY3_BITMAP_LSB)
#define WBSYNC_PRIORITY3_BITMAP_SET(x)                               (((x) << WBSYNC_PRIORITY3_BITMAP_LSB) & WBSYNC_PRIORITY3_BITMAP_MASK)
#define WBSYNC_PRIORITY3_BITMAP_RESET                                0x0 // 0
#define WBSYNC_PRIORITY3_ADDRESS                                     0x0010
#define WBSYNC_PRIORITY3_OFFSET                                      0x0010
// SW modifiable bits
#define WBSYNC_PRIORITY3_SW_MASK                                     0xffffffff
// bits defined at reset
#define WBSYNC_PRIORITY3_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define WBSYNC_PRIORITY3_RESET                                       0x00000000

// 32'h0014 (BTCOEX0)
#define BTCOEX0_SYNC_DUR_MSB                                         7
#define BTCOEX0_SYNC_DUR_LSB                                         0
#define BTCOEX0_SYNC_DUR_MASK                                        0x000000ff
#define BTCOEX0_SYNC_DUR_GET(x)                                      (((x) & BTCOEX0_SYNC_DUR_MASK) >> BTCOEX0_SYNC_DUR_LSB)
#define BTCOEX0_SYNC_DUR_SET(x)                                      (((x) << BTCOEX0_SYNC_DUR_LSB) & BTCOEX0_SYNC_DUR_MASK)
#define BTCOEX0_SYNC_DUR_RESET                                       0x64 // 100
#define BTCOEX0_ADDRESS                                              0x0014
#define BTCOEX0_OFFSET                                               0x0014
// SW modifiable bits
#define BTCOEX0_SW_MASK                                              0x000000ff
// bits defined at reset
#define BTCOEX0_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define BTCOEX0_RESET                                                0x00000064

// 32'h0018 (BTCOEX1)
#define BTCOEX1_CLK_THRES_MSB                                        20
#define BTCOEX1_CLK_THRES_LSB                                        0
#define BTCOEX1_CLK_THRES_MASK                                       0x001fffff
#define BTCOEX1_CLK_THRES_GET(x)                                     (((x) & BTCOEX1_CLK_THRES_MASK) >> BTCOEX1_CLK_THRES_LSB)
#define BTCOEX1_CLK_THRES_SET(x)                                     (((x) << BTCOEX1_CLK_THRES_LSB) & BTCOEX1_CLK_THRES_MASK)
#define BTCOEX1_CLK_THRES_RESET                                      0x1fffff // 2097151
#define BTCOEX1_ADDRESS                                              0x0018
#define BTCOEX1_OFFSET                                               0x0018
// SW modifiable bits
#define BTCOEX1_SW_MASK                                              0x001fffff
// bits defined at reset
#define BTCOEX1_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define BTCOEX1_RESET                                                0x001fffff

// 32'h001c (BTCOEX2)
#define BTCOEX2_FRAME_THRES_MSB                                      7
#define BTCOEX2_FRAME_THRES_LSB                                      0
#define BTCOEX2_FRAME_THRES_MASK                                     0x000000ff
#define BTCOEX2_FRAME_THRES_GET(x)                                   (((x) & BTCOEX2_FRAME_THRES_MASK) >> BTCOEX2_FRAME_THRES_LSB)
#define BTCOEX2_FRAME_THRES_SET(x)                                   (((x) << BTCOEX2_FRAME_THRES_LSB) & BTCOEX2_FRAME_THRES_MASK)
#define BTCOEX2_FRAME_THRES_RESET                                    0xff // 255
#define BTCOEX2_ADDRESS                                              0x001c
#define BTCOEX2_OFFSET                                               0x001c
// SW modifiable bits
#define BTCOEX2_SW_MASK                                              0x000000ff
// bits defined at reset
#define BTCOEX2_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define BTCOEX2_RESET                                                0x000000ff

// 32'h0020 (BTCOEX3)
#define BTCOEX3_CLK_CNT_MSB                                          20
#define BTCOEX3_CLK_CNT_LSB                                          0
#define BTCOEX3_CLK_CNT_MASK                                         0x001fffff
#define BTCOEX3_CLK_CNT_GET(x)                                       (((x) & BTCOEX3_CLK_CNT_MASK) >> BTCOEX3_CLK_CNT_LSB)
#define BTCOEX3_CLK_CNT_SET(x)                                       (((x) << BTCOEX3_CLK_CNT_LSB) & BTCOEX3_CLK_CNT_MASK)
#define BTCOEX3_CLK_CNT_RESET                                        0x0 // 0
#define BTCOEX3_ADDRESS                                              0x0020
#define BTCOEX3_OFFSET                                               0x0020
// SW modifiable bits
#define BTCOEX3_SW_MASK                                              0x001fffff
// bits defined at reset
#define BTCOEX3_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define BTCOEX3_RESET                                                0x00000000

// 32'h0024 (BTCOEX4)
#define BTCOEX4_FRAME_CNT_MSB                                        7
#define BTCOEX4_FRAME_CNT_LSB                                        0
#define BTCOEX4_FRAME_CNT_MASK                                       0x000000ff
#define BTCOEX4_FRAME_CNT_GET(x)                                     (((x) & BTCOEX4_FRAME_CNT_MASK) >> BTCOEX4_FRAME_CNT_LSB)
#define BTCOEX4_FRAME_CNT_SET(x)                                     (((x) << BTCOEX4_FRAME_CNT_LSB) & BTCOEX4_FRAME_CNT_MASK)
#define BTCOEX4_FRAME_CNT_RESET                                      0x0 // 0
#define BTCOEX4_ADDRESS                                              0x0024
#define BTCOEX4_OFFSET                                               0x0024
// SW modifiable bits
#define BTCOEX4_SW_MASK                                              0x000000ff
// bits defined at reset
#define BTCOEX4_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define BTCOEX4_RESET                                                0x00000000

// 32'h0028 (BTCOEX5)
#define BTCOEX5_IDLE_CNT_MSB                                         15
#define BTCOEX5_IDLE_CNT_LSB                                         0
#define BTCOEX5_IDLE_CNT_MASK                                        0x0000ffff
#define BTCOEX5_IDLE_CNT_GET(x)                                      (((x) & BTCOEX5_IDLE_CNT_MASK) >> BTCOEX5_IDLE_CNT_LSB)
#define BTCOEX5_IDLE_CNT_SET(x)                                      (((x) << BTCOEX5_IDLE_CNT_LSB) & BTCOEX5_IDLE_CNT_MASK)
#define BTCOEX5_IDLE_CNT_RESET                                       0x0 // 0
#define BTCOEX5_ADDRESS                                              0x0028
#define BTCOEX5_OFFSET                                               0x0028
// SW modifiable bits
#define BTCOEX5_SW_MASK                                              0x0000ffff
// bits defined at reset
#define BTCOEX5_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define BTCOEX5_RESET                                                0x00000000

// 32'h002c (BTCOEX6)
#define BTCOEX6_IDLE_RESET_LVL_BITMAP_MSB                            31
#define BTCOEX6_IDLE_RESET_LVL_BITMAP_LSB                            0
#define BTCOEX6_IDLE_RESET_LVL_BITMAP_MASK                           0xffffffff
#define BTCOEX6_IDLE_RESET_LVL_BITMAP_GET(x)                         (((x) & BTCOEX6_IDLE_RESET_LVL_BITMAP_MASK) >> BTCOEX6_IDLE_RESET_LVL_BITMAP_LSB)
#define BTCOEX6_IDLE_RESET_LVL_BITMAP_SET(x)                         (((x) << BTCOEX6_IDLE_RESET_LVL_BITMAP_LSB) & BTCOEX6_IDLE_RESET_LVL_BITMAP_MASK)
#define BTCOEX6_IDLE_RESET_LVL_BITMAP_RESET                          0xffffffff // 4294967295
#define BTCOEX6_ADDRESS                                              0x002c
#define BTCOEX6_OFFSET                                               0x002c
// SW modifiable bits
#define BTCOEX6_SW_MASK                                              0xffffffff
// bits defined at reset
#define BTCOEX6_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define BTCOEX6_RESET                                                0xffffffff

// 32'h0030 (WBSYNC)
#define WBSYNC_BTCLOCK_MSB                                           31
#define WBSYNC_BTCLOCK_LSB                                           0
#define WBSYNC_BTCLOCK_MASK                                          0xffffffff
#define WBSYNC_BTCLOCK_GET(x)                                        (((x) & WBSYNC_BTCLOCK_MASK) >> WBSYNC_BTCLOCK_LSB)
#define WBSYNC_BTCLOCK_SET(x)                                        (((x) << WBSYNC_BTCLOCK_LSB) & WBSYNC_BTCLOCK_MASK)
#define WBSYNC_BTCLOCK_RESET                                         0x0 // 0
#define WBSYNC_ADDRESS                                               0x0030
#define WBSYNC_OFFSET                                                0x0030
// SW modifiable bits
#define WBSYNC_SW_MASK                                               0xffffffff
// bits defined at reset
#define WBSYNC_RSTMASK                                               0xffffffff
// reset value (ignore bits undefined at reset)
#define WBSYNC_RESET                                                 0x00000000

// 32'h0034 (WBSYNC1)
#define WBSYNC1_BTCLOCK_MSB                                          31
#define WBSYNC1_BTCLOCK_LSB                                          0
#define WBSYNC1_BTCLOCK_MASK                                         0xffffffff
#define WBSYNC1_BTCLOCK_GET(x)                                       (((x) & WBSYNC1_BTCLOCK_MASK) >> WBSYNC1_BTCLOCK_LSB)
#define WBSYNC1_BTCLOCK_SET(x)                                       (((x) << WBSYNC1_BTCLOCK_LSB) & WBSYNC1_BTCLOCK_MASK)
#define WBSYNC1_BTCLOCK_RESET                                        0x0 // 0
#define WBSYNC1_ADDRESS                                              0x0034
#define WBSYNC1_OFFSET                                               0x0034
// SW modifiable bits
#define WBSYNC1_SW_MASK                                              0xffffffff
// bits defined at reset
#define WBSYNC1_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define WBSYNC1_RESET                                                0x00000000

// 32'h0038 (WBSYNC2)
#define WBSYNC2_BTCLOCK_MSB                                          31
#define WBSYNC2_BTCLOCK_LSB                                          0
#define WBSYNC2_BTCLOCK_MASK                                         0xffffffff
#define WBSYNC2_BTCLOCK_GET(x)                                       (((x) & WBSYNC2_BTCLOCK_MASK) >> WBSYNC2_BTCLOCK_LSB)
#define WBSYNC2_BTCLOCK_SET(x)                                       (((x) << WBSYNC2_BTCLOCK_LSB) & WBSYNC2_BTCLOCK_MASK)
#define WBSYNC2_BTCLOCK_RESET                                        0x0 // 0
#define WBSYNC2_ADDRESS                                              0x0038
#define WBSYNC2_OFFSET                                               0x0038
// SW modifiable bits
#define WBSYNC2_SW_MASK                                              0xffffffff
// bits defined at reset
#define WBSYNC2_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define WBSYNC2_RESET                                                0x00000000

// 32'h003c (WBSYNC3)
#define WBSYNC3_BTCLOCK_MSB                                          31
#define WBSYNC3_BTCLOCK_LSB                                          0
#define WBSYNC3_BTCLOCK_MASK                                         0xffffffff
#define WBSYNC3_BTCLOCK_GET(x)                                       (((x) & WBSYNC3_BTCLOCK_MASK) >> WBSYNC3_BTCLOCK_LSB)
#define WBSYNC3_BTCLOCK_SET(x)                                       (((x) << WBSYNC3_BTCLOCK_LSB) & WBSYNC3_BTCLOCK_MASK)
#define WBSYNC3_BTCLOCK_RESET                                        0x0 // 0
#define WBSYNC3_ADDRESS                                              0x003c
#define WBSYNC3_OFFSET                                               0x003c
// SW modifiable bits
#define WBSYNC3_SW_MASK                                              0xffffffff
// bits defined at reset
#define WBSYNC3_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define WBSYNC3_RESET                                                0x00000000

// 32'h0040 (WB_TIMER_TARGET)
#define WB_TIMER_TARGET_VALUE_MSB                                    31
#define WB_TIMER_TARGET_VALUE_LSB                                    0
#define WB_TIMER_TARGET_VALUE_MASK                                   0xffffffff
#define WB_TIMER_TARGET_VALUE_GET(x)                                 (((x) & WB_TIMER_TARGET_VALUE_MASK) >> WB_TIMER_TARGET_VALUE_LSB)
#define WB_TIMER_TARGET_VALUE_SET(x)                                 (((x) << WB_TIMER_TARGET_VALUE_LSB) & WB_TIMER_TARGET_VALUE_MASK)
#define WB_TIMER_TARGET_VALUE_RESET                                  0x0 // 0
#define WB_TIMER_TARGET_ADDRESS                                      0x0040
#define WB_TIMER_TARGET_OFFSET                                       0x0040
// SW modifiable bits
#define WB_TIMER_TARGET_SW_MASK                                      0xffffffff
// bits defined at reset
#define WB_TIMER_TARGET_RSTMASK                                      0xffffffff
// reset value (ignore bits undefined at reset)
#define WB_TIMER_TARGET_RESET                                        0x00000000

// 32'h0044 (WB_TIMER_SLOP)
#define WB_TIMER_SLOP_VALUE_MSB                                      9
#define WB_TIMER_SLOP_VALUE_LSB                                      0
#define WB_TIMER_SLOP_VALUE_MASK                                     0x000003ff
#define WB_TIMER_SLOP_VALUE_GET(x)                                   (((x) & WB_TIMER_SLOP_VALUE_MASK) >> WB_TIMER_SLOP_VALUE_LSB)
#define WB_TIMER_SLOP_VALUE_SET(x)                                   (((x) << WB_TIMER_SLOP_VALUE_LSB) & WB_TIMER_SLOP_VALUE_MASK)
#define WB_TIMER_SLOP_VALUE_RESET                                    0x0 // 0
#define WB_TIMER_SLOP_ADDRESS                                        0x0044
#define WB_TIMER_SLOP_OFFSET                                         0x0044
// SW modifiable bits
#define WB_TIMER_SLOP_SW_MASK                                        0x000003ff
// bits defined at reset
#define WB_TIMER_SLOP_RSTMASK                                        0xffffffff
// reset value (ignore bits undefined at reset)
#define WB_TIMER_SLOP_RESET                                          0x00000000

// 32'h0048 (BTCOEX_INT_EN)
#define BTCOEX_INT_EN_WB_TIMER_MSB                                   7
#define BTCOEX_INT_EN_WB_TIMER_LSB                                   7
#define BTCOEX_INT_EN_WB_TIMER_MASK                                  0x00000080
#define BTCOEX_INT_EN_WB_TIMER_GET(x)                                (((x) & BTCOEX_INT_EN_WB_TIMER_MASK) >> BTCOEX_INT_EN_WB_TIMER_LSB)
#define BTCOEX_INT_EN_WB_TIMER_SET(x)                                (((x) << BTCOEX_INT_EN_WB_TIMER_LSB) & BTCOEX_INT_EN_WB_TIMER_MASK)
#define BTCOEX_INT_EN_WB_TIMER_RESET                                 0x0 // 0
#define BTCOEX_INT_EN_NOSYNC_MSB                                     4
#define BTCOEX_INT_EN_NOSYNC_LSB                                     4
#define BTCOEX_INT_EN_NOSYNC_MASK                                    0x00000010
#define BTCOEX_INT_EN_NOSYNC_GET(x)                                  (((x) & BTCOEX_INT_EN_NOSYNC_MASK) >> BTCOEX_INT_EN_NOSYNC_LSB)
#define BTCOEX_INT_EN_NOSYNC_SET(x)                                  (((x) << BTCOEX_INT_EN_NOSYNC_LSB) & BTCOEX_INT_EN_NOSYNC_MASK)
#define BTCOEX_INT_EN_NOSYNC_RESET                                   0x0 // 0
#define BTCOEX_INT_EN_SYNC_MSB                                       3
#define BTCOEX_INT_EN_SYNC_LSB                                       3
#define BTCOEX_INT_EN_SYNC_MASK                                      0x00000008
#define BTCOEX_INT_EN_SYNC_GET(x)                                    (((x) & BTCOEX_INT_EN_SYNC_MASK) >> BTCOEX_INT_EN_SYNC_LSB)
#define BTCOEX_INT_EN_SYNC_SET(x)                                    (((x) << BTCOEX_INT_EN_SYNC_LSB) & BTCOEX_INT_EN_SYNC_MASK)
#define BTCOEX_INT_EN_SYNC_RESET                                     0x0 // 0
#define BTCOEX_INT_EN_END_MSB                                        2
#define BTCOEX_INT_EN_END_LSB                                        2
#define BTCOEX_INT_EN_END_MASK                                       0x00000004
#define BTCOEX_INT_EN_END_GET(x)                                     (((x) & BTCOEX_INT_EN_END_MASK) >> BTCOEX_INT_EN_END_LSB)
#define BTCOEX_INT_EN_END_SET(x)                                     (((x) << BTCOEX_INT_EN_END_LSB) & BTCOEX_INT_EN_END_MASK)
#define BTCOEX_INT_EN_END_RESET                                      0x0 // 0
#define BTCOEX_INT_EN_FRAME_CNT_MSB                                  1
#define BTCOEX_INT_EN_FRAME_CNT_LSB                                  1
#define BTCOEX_INT_EN_FRAME_CNT_MASK                                 0x00000002
#define BTCOEX_INT_EN_FRAME_CNT_GET(x)                               (((x) & BTCOEX_INT_EN_FRAME_CNT_MASK) >> BTCOEX_INT_EN_FRAME_CNT_LSB)
#define BTCOEX_INT_EN_FRAME_CNT_SET(x)                               (((x) << BTCOEX_INT_EN_FRAME_CNT_LSB) & BTCOEX_INT_EN_FRAME_CNT_MASK)
#define BTCOEX_INT_EN_FRAME_CNT_RESET                                0x0 // 0
#define BTCOEX_INT_EN_CLK_CNT_MSB                                    0
#define BTCOEX_INT_EN_CLK_CNT_LSB                                    0
#define BTCOEX_INT_EN_CLK_CNT_MASK                                   0x00000001
#define BTCOEX_INT_EN_CLK_CNT_GET(x)                                 (((x) & BTCOEX_INT_EN_CLK_CNT_MASK) >> BTCOEX_INT_EN_CLK_CNT_LSB)
#define BTCOEX_INT_EN_CLK_CNT_SET(x)                                 (((x) << BTCOEX_INT_EN_CLK_CNT_LSB) & BTCOEX_INT_EN_CLK_CNT_MASK)
#define BTCOEX_INT_EN_CLK_CNT_RESET                                  0x0 // 0
#define BTCOEX_INT_EN_ADDRESS                                        0x0048
#define BTCOEX_INT_EN_OFFSET                                         0x0048
// SW modifiable bits
#define BTCOEX_INT_EN_SW_MASK                                        0x0000009f
// bits defined at reset
#define BTCOEX_INT_EN_RSTMASK                                        0xffffffff
// reset value (ignore bits undefined at reset)
#define BTCOEX_INT_EN_RESET                                          0x00000000

// 32'h004c (BTCOEX_INT_STAT)
#define BTCOEX_INT_STAT_MCI_MSB                                      12
#define BTCOEX_INT_STAT_MCI_LSB                                      12
#define BTCOEX_INT_STAT_MCI_MASK                                     0x00001000
#define BTCOEX_INT_STAT_MCI_GET(x)                                   (((x) & BTCOEX_INT_STAT_MCI_MASK) >> BTCOEX_INT_STAT_MCI_LSB)
#define BTCOEX_INT_STAT_MCI_SET(x)                                   (((x) << BTCOEX_INT_STAT_MCI_LSB) & BTCOEX_INT_STAT_MCI_MASK)
#define BTCOEX_INT_STAT_MCI_RESET                                    0x0 // 0
#define BTCOEX_INT_STAT_WB_TIMER_MSB                                 7
#define BTCOEX_INT_STAT_WB_TIMER_LSB                                 7
#define BTCOEX_INT_STAT_WB_TIMER_MASK                                0x00000080
#define BTCOEX_INT_STAT_WB_TIMER_GET(x)                              (((x) & BTCOEX_INT_STAT_WB_TIMER_MASK) >> BTCOEX_INT_STAT_WB_TIMER_LSB)
#define BTCOEX_INT_STAT_WB_TIMER_SET(x)                              (((x) << BTCOEX_INT_STAT_WB_TIMER_LSB) & BTCOEX_INT_STAT_WB_TIMER_MASK)
#define BTCOEX_INT_STAT_WB_TIMER_RESET                               0x0 // 0
#define BTCOEX_INT_STAT_BTPRIORITY_STOMP_MSB                         6
#define BTCOEX_INT_STAT_BTPRIORITY_STOMP_LSB                         6
#define BTCOEX_INT_STAT_BTPRIORITY_STOMP_MASK                        0x00000040
#define BTCOEX_INT_STAT_BTPRIORITY_STOMP_GET(x)                      (((x) & BTCOEX_INT_STAT_BTPRIORITY_STOMP_MASK) >> BTCOEX_INT_STAT_BTPRIORITY_STOMP_LSB)
#define BTCOEX_INT_STAT_BTPRIORITY_STOMP_SET(x)                      (((x) << BTCOEX_INT_STAT_BTPRIORITY_STOMP_LSB) & BTCOEX_INT_STAT_BTPRIORITY_STOMP_MASK)
#define BTCOEX_INT_STAT_BTPRIORITY_STOMP_RESET                       0x0 // 0
#define BTCOEX_INT_STAT_BTPRIORITY_MSB                               5
#define BTCOEX_INT_STAT_BTPRIORITY_LSB                               5
#define BTCOEX_INT_STAT_BTPRIORITY_MASK                              0x00000020
#define BTCOEX_INT_STAT_BTPRIORITY_GET(x)                            (((x) & BTCOEX_INT_STAT_BTPRIORITY_MASK) >> BTCOEX_INT_STAT_BTPRIORITY_LSB)
#define BTCOEX_INT_STAT_BTPRIORITY_SET(x)                            (((x) << BTCOEX_INT_STAT_BTPRIORITY_LSB) & BTCOEX_INT_STAT_BTPRIORITY_MASK)
#define BTCOEX_INT_STAT_BTPRIORITY_RESET                             0x0 // 0
#define BTCOEX_INT_STAT_NOSYNC_MSB                                   4
#define BTCOEX_INT_STAT_NOSYNC_LSB                                   4
#define BTCOEX_INT_STAT_NOSYNC_MASK                                  0x00000010
#define BTCOEX_INT_STAT_NOSYNC_GET(x)                                (((x) & BTCOEX_INT_STAT_NOSYNC_MASK) >> BTCOEX_INT_STAT_NOSYNC_LSB)
#define BTCOEX_INT_STAT_NOSYNC_SET(x)                                (((x) << BTCOEX_INT_STAT_NOSYNC_LSB) & BTCOEX_INT_STAT_NOSYNC_MASK)
#define BTCOEX_INT_STAT_NOSYNC_RESET                                 0x0 // 0
#define BTCOEX_INT_STAT_SYNC_MSB                                     3
#define BTCOEX_INT_STAT_SYNC_LSB                                     3
#define BTCOEX_INT_STAT_SYNC_MASK                                    0x00000008
#define BTCOEX_INT_STAT_SYNC_GET(x)                                  (((x) & BTCOEX_INT_STAT_SYNC_MASK) >> BTCOEX_INT_STAT_SYNC_LSB)
#define BTCOEX_INT_STAT_SYNC_SET(x)                                  (((x) << BTCOEX_INT_STAT_SYNC_LSB) & BTCOEX_INT_STAT_SYNC_MASK)
#define BTCOEX_INT_STAT_SYNC_RESET                                   0x0 // 0
#define BTCOEX_INT_STAT_END_MSB                                      2
#define BTCOEX_INT_STAT_END_LSB                                      2
#define BTCOEX_INT_STAT_END_MASK                                     0x00000004
#define BTCOEX_INT_STAT_END_GET(x)                                   (((x) & BTCOEX_INT_STAT_END_MASK) >> BTCOEX_INT_STAT_END_LSB)
#define BTCOEX_INT_STAT_END_SET(x)                                   (((x) << BTCOEX_INT_STAT_END_LSB) & BTCOEX_INT_STAT_END_MASK)
#define BTCOEX_INT_STAT_END_RESET                                    0x0 // 0
#define BTCOEX_INT_STAT_FRAME_CNT_MSB                                1
#define BTCOEX_INT_STAT_FRAME_CNT_LSB                                1
#define BTCOEX_INT_STAT_FRAME_CNT_MASK                               0x00000002
#define BTCOEX_INT_STAT_FRAME_CNT_GET(x)                             (((x) & BTCOEX_INT_STAT_FRAME_CNT_MASK) >> BTCOEX_INT_STAT_FRAME_CNT_LSB)
#define BTCOEX_INT_STAT_FRAME_CNT_SET(x)                             (((x) << BTCOEX_INT_STAT_FRAME_CNT_LSB) & BTCOEX_INT_STAT_FRAME_CNT_MASK)
#define BTCOEX_INT_STAT_FRAME_CNT_RESET                              0x0 // 0
#define BTCOEX_INT_STAT_CLK_CNT_MSB                                  0
#define BTCOEX_INT_STAT_CLK_CNT_LSB                                  0
#define BTCOEX_INT_STAT_CLK_CNT_MASK                                 0x00000001
#define BTCOEX_INT_STAT_CLK_CNT_GET(x)                               (((x) & BTCOEX_INT_STAT_CLK_CNT_MASK) >> BTCOEX_INT_STAT_CLK_CNT_LSB)
#define BTCOEX_INT_STAT_CLK_CNT_SET(x)                               (((x) << BTCOEX_INT_STAT_CLK_CNT_LSB) & BTCOEX_INT_STAT_CLK_CNT_MASK)
#define BTCOEX_INT_STAT_CLK_CNT_RESET                                0x0 // 0
#define BTCOEX_INT_STAT_ADDRESS                                      0x004c
#define BTCOEX_INT_STAT_OFFSET                                       0x004c
// SW modifiable bits
#define BTCOEX_INT_STAT_SW_MASK                                      0x000010ff
// bits defined at reset
#define BTCOEX_INT_STAT_RSTMASK                                      0xffffffff
// reset value (ignore bits undefined at reset)
#define BTCOEX_INT_STAT_RESET                                        0x00000000

// 32'h0050 (BTPRIORITY_INT_EN)
#define BTPRIORITY_INT_EN_BITMAP_MSB                                 31
#define BTPRIORITY_INT_EN_BITMAP_LSB                                 0
#define BTPRIORITY_INT_EN_BITMAP_MASK                                0xffffffff
#define BTPRIORITY_INT_EN_BITMAP_GET(x)                              (((x) & BTPRIORITY_INT_EN_BITMAP_MASK) >> BTPRIORITY_INT_EN_BITMAP_LSB)
#define BTPRIORITY_INT_EN_BITMAP_SET(x)                              (((x) << BTPRIORITY_INT_EN_BITMAP_LSB) & BTPRIORITY_INT_EN_BITMAP_MASK)
#define BTPRIORITY_INT_EN_BITMAP_RESET                               0x0 // 0
#define BTPRIORITY_INT_EN_ADDRESS                                    0x0050
#define BTPRIORITY_INT_EN_OFFSET                                     0x0050
// SW modifiable bits
#define BTPRIORITY_INT_EN_SW_MASK                                    0xffffffff
// bits defined at reset
#define BTPRIORITY_INT_EN_RSTMASK                                    0xffffffff
// reset value (ignore bits undefined at reset)
#define BTPRIORITY_INT_EN_RESET                                      0x00000000

// 32'h0054 (BTPRIORITY_INT_STAT)
#define BTPRIORITY_INT_STAT_BITMAP_MSB                               31
#define BTPRIORITY_INT_STAT_BITMAP_LSB                               0
#define BTPRIORITY_INT_STAT_BITMAP_MASK                              0xffffffff
#define BTPRIORITY_INT_STAT_BITMAP_GET(x)                            (((x) & BTPRIORITY_INT_STAT_BITMAP_MASK) >> BTPRIORITY_INT_STAT_BITMAP_LSB)
#define BTPRIORITY_INT_STAT_BITMAP_SET(x)                            (((x) << BTPRIORITY_INT_STAT_BITMAP_LSB) & BTPRIORITY_INT_STAT_BITMAP_MASK)
#define BTPRIORITY_INT_STAT_BITMAP_RESET                             0x0 // 0
#define BTPRIORITY_INT_STAT_ADDRESS                                  0x0054
#define BTPRIORITY_INT_STAT_OFFSET                                   0x0054
// SW modifiable bits
#define BTPRIORITY_INT_STAT_SW_MASK                                  0xffffffff
// bits defined at reset
#define BTPRIORITY_INT_STAT_RSTMASK                                  0xffffffff
// reset value (ignore bits undefined at reset)
#define BTPRIORITY_INT_STAT_RESET                                    0x00000000

// 32'h0058 (BTPRIORITY_STOMP_INT_EN)
#define BTPRIORITY_STOMP_INT_EN_BITMAP_MSB                           31
#define BTPRIORITY_STOMP_INT_EN_BITMAP_LSB                           0
#define BTPRIORITY_STOMP_INT_EN_BITMAP_MASK                          0xffffffff
#define BTPRIORITY_STOMP_INT_EN_BITMAP_GET(x)                        (((x) & BTPRIORITY_STOMP_INT_EN_BITMAP_MASK) >> BTPRIORITY_STOMP_INT_EN_BITMAP_LSB)
#define BTPRIORITY_STOMP_INT_EN_BITMAP_SET(x)                        (((x) << BTPRIORITY_STOMP_INT_EN_BITMAP_LSB) & BTPRIORITY_STOMP_INT_EN_BITMAP_MASK)
#define BTPRIORITY_STOMP_INT_EN_BITMAP_RESET                         0x0 // 0
#define BTPRIORITY_STOMP_INT_EN_ADDRESS                              0x0058
#define BTPRIORITY_STOMP_INT_EN_OFFSET                               0x0058
// SW modifiable bits
#define BTPRIORITY_STOMP_INT_EN_SW_MASK                              0xffffffff
// bits defined at reset
#define BTPRIORITY_STOMP_INT_EN_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define BTPRIORITY_STOMP_INT_EN_RESET                                0x00000000

// 32'h005c (BTPRIORITY_STOMP_INT_STAT)
#define BTPRIORITY_STOMP_INT_STAT_BITMAP_MSB                         31
#define BTPRIORITY_STOMP_INT_STAT_BITMAP_LSB                         0
#define BTPRIORITY_STOMP_INT_STAT_BITMAP_MASK                        0xffffffff
#define BTPRIORITY_STOMP_INT_STAT_BITMAP_GET(x)                      (((x) & BTPRIORITY_STOMP_INT_STAT_BITMAP_MASK) >> BTPRIORITY_STOMP_INT_STAT_BITMAP_LSB)
#define BTPRIORITY_STOMP_INT_STAT_BITMAP_SET(x)                      (((x) << BTPRIORITY_STOMP_INT_STAT_BITMAP_LSB) & BTPRIORITY_STOMP_INT_STAT_BITMAP_MASK)
#define BTPRIORITY_STOMP_INT_STAT_BITMAP_RESET                       0x0 // 0
#define BTPRIORITY_STOMP_INT_STAT_ADDRESS                            0x005c
#define BTPRIORITY_STOMP_INT_STAT_OFFSET                             0x005c
// SW modifiable bits
#define BTPRIORITY_STOMP_INT_STAT_SW_MASK                            0xffffffff
// bits defined at reset
#define BTPRIORITY_STOMP_INT_STAT_RSTMASK                            0xffffffff
// reset value (ignore bits undefined at reset)
#define BTPRIORITY_STOMP_INT_STAT_RESET                              0x00000000

// 32'h0060 (BTPRIORITY_INT)
#define BTPRIORITY_INT_DELAY_MSB                                     7
#define BTPRIORITY_INT_DELAY_LSB                                     0
#define BTPRIORITY_INT_DELAY_MASK                                    0x000000ff
#define BTPRIORITY_INT_DELAY_GET(x)                                  (((x) & BTPRIORITY_INT_DELAY_MASK) >> BTPRIORITY_INT_DELAY_LSB)
#define BTPRIORITY_INT_DELAY_SET(x)                                  (((x) << BTPRIORITY_INT_DELAY_LSB) & BTPRIORITY_INT_DELAY_MASK)
#define BTPRIORITY_INT_DELAY_RESET                                   0x0 // 0
#define BTPRIORITY_INT_ADDRESS                                       0x0060
#define BTPRIORITY_INT_OFFSET                                        0x0060
// SW modifiable bits
#define BTPRIORITY_INT_SW_MASK                                       0x000000ff
// bits defined at reset
#define BTPRIORITY_INT_RSTMASK                                       0xffffffff
// reset value (ignore bits undefined at reset)
#define BTPRIORITY_INT_RESET                                         0x00000000

// 32'h0064 (SCO_PARAMS)
#define SCO_PARAMS_SLOP_MSB                                          23
#define SCO_PARAMS_SLOP_LSB                                          14
#define SCO_PARAMS_SLOP_MASK                                         0x00ffc000
#define SCO_PARAMS_SLOP_GET(x)                                       (((x) & SCO_PARAMS_SLOP_MASK) >> SCO_PARAMS_SLOP_LSB)
#define SCO_PARAMS_SLOP_SET(x)                                       (((x) << SCO_PARAMS_SLOP_LSB) & SCO_PARAMS_SLOP_MASK)
#define SCO_PARAMS_SLOP_RESET                                        0x0 // 0
#define SCO_PARAMS_PERIOD_MSB                                        13
#define SCO_PARAMS_PERIOD_LSB                                        0
#define SCO_PARAMS_PERIOD_MASK                                       0x00003fff
#define SCO_PARAMS_PERIOD_GET(x)                                     (((x) & SCO_PARAMS_PERIOD_MASK) >> SCO_PARAMS_PERIOD_LSB)
#define SCO_PARAMS_PERIOD_SET(x)                                     (((x) << SCO_PARAMS_PERIOD_LSB) & SCO_PARAMS_PERIOD_MASK)
#define SCO_PARAMS_PERIOD_RESET                                      0x0 // 0
#define SCO_PARAMS_ADDRESS                                           0x0064
#define SCO_PARAMS_OFFSET                                            0x0064
// SW modifiable bits
#define SCO_PARAMS_SW_MASK                                           0x00ffffff
// bits defined at reset
#define SCO_PARAMS_RSTMASK                                           0xffffffff
// reset value (ignore bits undefined at reset)
#define SCO_PARAMS_RESET                                             0x00000000

// 32'h0068 (SCO_PRIORITY)
#define SCO_PRIORITY_BITMAP_MSB                                      31
#define SCO_PRIORITY_BITMAP_LSB                                      0
#define SCO_PRIORITY_BITMAP_MASK                                     0xffffffff
#define SCO_PRIORITY_BITMAP_GET(x)                                   (((x) & SCO_PRIORITY_BITMAP_MASK) >> SCO_PRIORITY_BITMAP_LSB)
#define SCO_PRIORITY_BITMAP_SET(x)                                   (((x) << SCO_PRIORITY_BITMAP_LSB) & SCO_PRIORITY_BITMAP_MASK)
#define SCO_PRIORITY_BITMAP_RESET                                    0x0 // 0
#define SCO_PRIORITY_ADDRESS                                         0x0068
#define SCO_PRIORITY_OFFSET                                          0x0068
// SW modifiable bits
#define SCO_PRIORITY_SW_MASK                                         0xffffffff
// bits defined at reset
#define SCO_PRIORITY_RSTMASK                                         0xffffffff
// reset value (ignore bits undefined at reset)
#define SCO_PRIORITY_RESET                                           0x00000000

// 32'h006c (SCO_SYNC)
#define SCO_SYNC_BTCLOCK_MSB                                         31
#define SCO_SYNC_BTCLOCK_LSB                                         0
#define SCO_SYNC_BTCLOCK_MASK                                        0xffffffff
#define SCO_SYNC_BTCLOCK_GET(x)                                      (((x) & SCO_SYNC_BTCLOCK_MASK) >> SCO_SYNC_BTCLOCK_LSB)
#define SCO_SYNC_BTCLOCK_SET(x)                                      (((x) << SCO_SYNC_BTCLOCK_LSB) & SCO_SYNC_BTCLOCK_MASK)
#define SCO_SYNC_BTCLOCK_RESET                                       0x0 // 0
#define SCO_SYNC_ADDRESS                                             0x006c
#define SCO_SYNC_OFFSET                                              0x006c
// SW modifiable bits
#define SCO_SYNC_SW_MASK                                             0xffffffff
// bits defined at reset
#define SCO_SYNC_RSTMASK                                             0xffffffff
// reset value (ignore bits undefined at reset)
#define SCO_SYNC_RESET                                               0x00000000

// 32'h0070 (BTCOEX_RAW_STAT)
#define BTCOEX_RAW_STAT_WB_TIMER_MSB                                 7
#define BTCOEX_RAW_STAT_WB_TIMER_LSB                                 7
#define BTCOEX_RAW_STAT_WB_TIMER_MASK                                0x00000080
#define BTCOEX_RAW_STAT_WB_TIMER_GET(x)                              (((x) & BTCOEX_RAW_STAT_WB_TIMER_MASK) >> BTCOEX_RAW_STAT_WB_TIMER_LSB)
#define BTCOEX_RAW_STAT_WB_TIMER_SET(x)                              (((x) << BTCOEX_RAW_STAT_WB_TIMER_LSB) & BTCOEX_RAW_STAT_WB_TIMER_MASK)
#define BTCOEX_RAW_STAT_WB_TIMER_RESET                               0x0 // 0
#define BTCOEX_RAW_STAT_NOSYNC_MSB                                   4
#define BTCOEX_RAW_STAT_NOSYNC_LSB                                   4
#define BTCOEX_RAW_STAT_NOSYNC_MASK                                  0x00000010
#define BTCOEX_RAW_STAT_NOSYNC_GET(x)                                (((x) & BTCOEX_RAW_STAT_NOSYNC_MASK) >> BTCOEX_RAW_STAT_NOSYNC_LSB)
#define BTCOEX_RAW_STAT_NOSYNC_SET(x)                                (((x) << BTCOEX_RAW_STAT_NOSYNC_LSB) & BTCOEX_RAW_STAT_NOSYNC_MASK)
#define BTCOEX_RAW_STAT_NOSYNC_RESET                                 0x0 // 0
#define BTCOEX_RAW_STAT_SYNC_MSB                                     3
#define BTCOEX_RAW_STAT_SYNC_LSB                                     3
#define BTCOEX_RAW_STAT_SYNC_MASK                                    0x00000008
#define BTCOEX_RAW_STAT_SYNC_GET(x)                                  (((x) & BTCOEX_RAW_STAT_SYNC_MASK) >> BTCOEX_RAW_STAT_SYNC_LSB)
#define BTCOEX_RAW_STAT_SYNC_SET(x)                                  (((x) << BTCOEX_RAW_STAT_SYNC_LSB) & BTCOEX_RAW_STAT_SYNC_MASK)
#define BTCOEX_RAW_STAT_SYNC_RESET                                   0x0 // 0
#define BTCOEX_RAW_STAT_END_MSB                                      2
#define BTCOEX_RAW_STAT_END_LSB                                      2
#define BTCOEX_RAW_STAT_END_MASK                                     0x00000004
#define BTCOEX_RAW_STAT_END_GET(x)                                   (((x) & BTCOEX_RAW_STAT_END_MASK) >> BTCOEX_RAW_STAT_END_LSB)
#define BTCOEX_RAW_STAT_END_SET(x)                                   (((x) << BTCOEX_RAW_STAT_END_LSB) & BTCOEX_RAW_STAT_END_MASK)
#define BTCOEX_RAW_STAT_END_RESET                                    0x0 // 0
#define BTCOEX_RAW_STAT_FRAME_CNT_MSB                                1
#define BTCOEX_RAW_STAT_FRAME_CNT_LSB                                1
#define BTCOEX_RAW_STAT_FRAME_CNT_MASK                               0x00000002
#define BTCOEX_RAW_STAT_FRAME_CNT_GET(x)                             (((x) & BTCOEX_RAW_STAT_FRAME_CNT_MASK) >> BTCOEX_RAW_STAT_FRAME_CNT_LSB)
#define BTCOEX_RAW_STAT_FRAME_CNT_SET(x)                             (((x) << BTCOEX_RAW_STAT_FRAME_CNT_LSB) & BTCOEX_RAW_STAT_FRAME_CNT_MASK)
#define BTCOEX_RAW_STAT_FRAME_CNT_RESET                              0x0 // 0
#define BTCOEX_RAW_STAT_CLK_CNT_MSB                                  0
#define BTCOEX_RAW_STAT_CLK_CNT_LSB                                  0
#define BTCOEX_RAW_STAT_CLK_CNT_MASK                                 0x00000001
#define BTCOEX_RAW_STAT_CLK_CNT_GET(x)                               (((x) & BTCOEX_RAW_STAT_CLK_CNT_MASK) >> BTCOEX_RAW_STAT_CLK_CNT_LSB)
#define BTCOEX_RAW_STAT_CLK_CNT_SET(x)                               (((x) << BTCOEX_RAW_STAT_CLK_CNT_LSB) & BTCOEX_RAW_STAT_CLK_CNT_MASK)
#define BTCOEX_RAW_STAT_CLK_CNT_RESET                                0x0 // 0
#define BTCOEX_RAW_STAT_ADDRESS                                      0x0070
#define BTCOEX_RAW_STAT_OFFSET                                       0x0070
// SW modifiable bits
#define BTCOEX_RAW_STAT_SW_MASK                                      0x0000009f
// bits defined at reset
#define BTCOEX_RAW_STAT_RSTMASK                                      0xffffffff
// reset value (ignore bits undefined at reset)
#define BTCOEX_RAW_STAT_RESET                                        0x00000000

// 32'h0074 (BTPRIORITY_RAW_STAT)
#define BTPRIORITY_RAW_STAT_BITMAP_MSB                               31
#define BTPRIORITY_RAW_STAT_BITMAP_LSB                               0
#define BTPRIORITY_RAW_STAT_BITMAP_MASK                              0xffffffff
#define BTPRIORITY_RAW_STAT_BITMAP_GET(x)                            (((x) & BTPRIORITY_RAW_STAT_BITMAP_MASK) >> BTPRIORITY_RAW_STAT_BITMAP_LSB)
#define BTPRIORITY_RAW_STAT_BITMAP_SET(x)                            (((x) << BTPRIORITY_RAW_STAT_BITMAP_LSB) & BTPRIORITY_RAW_STAT_BITMAP_MASK)
#define BTPRIORITY_RAW_STAT_BITMAP_RESET                             0x0 // 0
#define BTPRIORITY_RAW_STAT_ADDRESS                                  0x0074
#define BTPRIORITY_RAW_STAT_OFFSET                                   0x0074
// SW modifiable bits
#define BTPRIORITY_RAW_STAT_SW_MASK                                  0xffffffff
// bits defined at reset
#define BTPRIORITY_RAW_STAT_RSTMASK                                  0xffffffff
// reset value (ignore bits undefined at reset)
#define BTPRIORITY_RAW_STAT_RESET                                    0x00000000

// 32'h0078 (BTPRIORITY_STOMP_RAW_STAT)
#define BTPRIORITY_STOMP_RAW_STAT_BITMAP_MSB                         31
#define BTPRIORITY_STOMP_RAW_STAT_BITMAP_LSB                         0
#define BTPRIORITY_STOMP_RAW_STAT_BITMAP_MASK                        0xffffffff
#define BTPRIORITY_STOMP_RAW_STAT_BITMAP_GET(x)                      (((x) & BTPRIORITY_STOMP_RAW_STAT_BITMAP_MASK) >> BTPRIORITY_STOMP_RAW_STAT_BITMAP_LSB)
#define BTPRIORITY_STOMP_RAW_STAT_BITMAP_SET(x)                      (((x) << BTPRIORITY_STOMP_RAW_STAT_BITMAP_LSB) & BTPRIORITY_STOMP_RAW_STAT_BITMAP_MASK)
#define BTPRIORITY_STOMP_RAW_STAT_BITMAP_RESET                       0x0 // 0
#define BTPRIORITY_STOMP_RAW_STAT_ADDRESS                            0x0078
#define BTPRIORITY_STOMP_RAW_STAT_OFFSET                             0x0078
// SW modifiable bits
#define BTPRIORITY_STOMP_RAW_STAT_SW_MASK                            0xffffffff
// bits defined at reset
#define BTPRIORITY_STOMP_RAW_STAT_RSTMASK                            0xffffffff
// reset value (ignore bits undefined at reset)
#define BTPRIORITY_STOMP_RAW_STAT_RESET                              0x00000000


#endif /* _BT_COEX_REG_H_ */
