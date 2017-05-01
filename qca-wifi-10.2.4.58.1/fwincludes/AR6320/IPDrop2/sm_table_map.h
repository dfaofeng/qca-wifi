//                                                                             
// File:       /trees/xiaoru/xiaoru-tree/ip/athr/wifi/dev/rtl/bb/blueprint/sm_table_map.vrh
// Creator:    xiaoru                                                          
// Time:       Thursday May 17, 2012 [3:09:14 pm]                              
//                                                                             
// Path:       /trees/xiaoru/xiaoru-tree/ip/athr/wifi/dev/rtl/bb/blueprint     
// Arguments:  /cad/denali/blueprint/3.7_64_32//Linux/blueprint -odir          
//             /trees/xiaoru/xiaoru-tree/ip/athr/wifi/dev/rtl/bb/blueprint     
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc sm_table_map.rdl       
//                                                                             
// Sources:    /trees/xiaoru/xiaoru-tree/ip/athr/wifi/dev/shared/blueprint/sysconfig/sm_table_map_sysconfig.rdl
//             /trees/xiaoru/xiaoru-tree/ip/athr/wifi/dev/rtl/bb/blueprint/sm_table_map.rdl
//             /trees/xiaoru/xiaoru-tree/ip/athr/wifi/dev/shared/env/blueprint/ath_vrh.pm
//             /cad/local/lib/perl/Pinfo.pm                                    
//                                                                             
// Blueprint:   3.7 (Fri Oct 5 10:32:33 PDT 2007)                              
// Machine:    mac                                                             
// OS:         Linux 2.6.9-42.ELsmp                                            
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _SM_TABLE_MAP_H_
#define _SM_TABLE_MAP_H_
// 0x0000 (BB_SM_TABLES_DUMMY1)
#define BB_SM_TABLES_DUMMY1_DUMMY1_MSB                               31
#define BB_SM_TABLES_DUMMY1_DUMMY1_LSB                               0
#define BB_SM_TABLES_DUMMY1_DUMMY1_MASK                              0xffffffff
#define BB_SM_TABLES_DUMMY1_DUMMY1_GET(x)                            (((x) & BB_SM_TABLES_DUMMY1_DUMMY1_MASK) >> BB_SM_TABLES_DUMMY1_DUMMY1_LSB)
#define BB_SM_TABLES_DUMMY1_DUMMY1_SET(x)                            (((0 | (x)) << BB_SM_TABLES_DUMMY1_DUMMY1_LSB) & BB_SM_TABLES_DUMMY1_DUMMY1_MASK)
#define BB_SM_TABLES_DUMMY1_DUMMY1_RESET                             0
#define BB_SM_TABLES_DUMMY1_ADDRESS                                  0x0000
#define BB_SM_TABLES_DUMMY1_HW_MASK                                  0xffffffff
#define BB_SM_TABLES_DUMMY1_SW_MASK                                  0xffffffff
#define BB_SM_TABLES_DUMMY1_HW_WRITE_MASK                            0x00000000
#define BB_SM_TABLES_DUMMY1_SW_WRITE_MASK                            0xffffffff
#define BB_SM_TABLES_DUMMY1_RSTMASK                                  0x00000000
#define BB_SM_TABLES_DUMMY1_RESET                                    0x00000000

// 0x03c0 (BB_DC_DAC_MEM_B0_0)
#define BB_DC_DAC_MEM_B0_0_DC_DAC_SETTING_MSB                        19
#define BB_DC_DAC_MEM_B0_0_DC_DAC_SETTING_LSB                        0
#define BB_DC_DAC_MEM_B0_0_DC_DAC_SETTING_MASK                       0x000fffff
#define BB_DC_DAC_MEM_B0_0_DC_DAC_SETTING_GET(x)                     (((x) & BB_DC_DAC_MEM_B0_0_DC_DAC_SETTING_MASK) >> BB_DC_DAC_MEM_B0_0_DC_DAC_SETTING_LSB)
#define BB_DC_DAC_MEM_B0_0_DC_DAC_SETTING_SET(x)                     (((0 | (x)) << BB_DC_DAC_MEM_B0_0_DC_DAC_SETTING_LSB) & BB_DC_DAC_MEM_B0_0_DC_DAC_SETTING_MASK)
#define BB_DC_DAC_MEM_B0_0_DC_DAC_SETTING_RESET                      0
#define BB_DC_DAC_MEM_B0_0_ADDRESS                                   0x03c0
#define BB_DC_DAC_MEM_B0_ADDRESS                                     BB_DC_DAC_MEM_B0_0_ADDRESS
#define BB_DC_DAC_MEM_B0_0_HW_MASK                                   0x000fffff
#define BB_DC_DAC_MEM_B0_0_SW_MASK                                   0x000fffff
#define BB_DC_DAC_MEM_B0_0_HW_WRITE_MASK                             0x000fffff
#define BB_DC_DAC_MEM_B0_0_SW_WRITE_MASK                             0x000fffff
#define BB_DC_DAC_MEM_B0_0_RSTMASK                                   0xffffffff
#define BB_DC_DAC_MEM_B0_0_RESET                                     0x00000000

// 0x03c4 (BB_DC_DAC_MEM_B0_1)
#define BB_DC_DAC_MEM_B0_1_DC_DAC_SETTING_MSB                        19
#define BB_DC_DAC_MEM_B0_1_DC_DAC_SETTING_LSB                        0
#define BB_DC_DAC_MEM_B0_1_DC_DAC_SETTING_MASK                       0x000fffff
#define BB_DC_DAC_MEM_B0_1_DC_DAC_SETTING_GET(x)                     (((x) & BB_DC_DAC_MEM_B0_1_DC_DAC_SETTING_MASK) >> BB_DC_DAC_MEM_B0_1_DC_DAC_SETTING_LSB)
#define BB_DC_DAC_MEM_B0_1_DC_DAC_SETTING_SET(x)                     (((0 | (x)) << BB_DC_DAC_MEM_B0_1_DC_DAC_SETTING_LSB) & BB_DC_DAC_MEM_B0_1_DC_DAC_SETTING_MASK)
#define BB_DC_DAC_MEM_B0_1_DC_DAC_SETTING_RESET                      0
#define BB_DC_DAC_MEM_B0_1_ADDRESS                                   0x03c4
#define BB_DC_DAC_MEM_B0_1_HW_MASK                                   0x000fffff
#define BB_DC_DAC_MEM_B0_1_SW_MASK                                   0x000fffff
#define BB_DC_DAC_MEM_B0_1_HW_WRITE_MASK                             0x000fffff
#define BB_DC_DAC_MEM_B0_1_SW_WRITE_MASK                             0x000fffff
#define BB_DC_DAC_MEM_B0_1_RSTMASK                                   0xffffffff
#define BB_DC_DAC_MEM_B0_1_RESET                                     0x00000000

// 0x03c8 (BB_DC_DAC_MEM_B0_2)
#define BB_DC_DAC_MEM_B0_2_DC_DAC_SETTING_MSB                        19
#define BB_DC_DAC_MEM_B0_2_DC_DAC_SETTING_LSB                        0
#define BB_DC_DAC_MEM_B0_2_DC_DAC_SETTING_MASK                       0x000fffff
#define BB_DC_DAC_MEM_B0_2_DC_DAC_SETTING_GET(x)                     (((x) & BB_DC_DAC_MEM_B0_2_DC_DAC_SETTING_MASK) >> BB_DC_DAC_MEM_B0_2_DC_DAC_SETTING_LSB)
#define BB_DC_DAC_MEM_B0_2_DC_DAC_SETTING_SET(x)                     (((0 | (x)) << BB_DC_DAC_MEM_B0_2_DC_DAC_SETTING_LSB) & BB_DC_DAC_MEM_B0_2_DC_DAC_SETTING_MASK)
#define BB_DC_DAC_MEM_B0_2_DC_DAC_SETTING_RESET                      0
#define BB_DC_DAC_MEM_B0_2_ADDRESS                                   0x03c8
#define BB_DC_DAC_MEM_B0_2_HW_MASK                                   0x000fffff
#define BB_DC_DAC_MEM_B0_2_SW_MASK                                   0x000fffff
#define BB_DC_DAC_MEM_B0_2_HW_WRITE_MASK                             0x000fffff
#define BB_DC_DAC_MEM_B0_2_SW_WRITE_MASK                             0x000fffff
#define BB_DC_DAC_MEM_B0_2_RSTMASK                                   0xffffffff
#define BB_DC_DAC_MEM_B0_2_RESET                                     0x00000000

// 0x03cc (BB_DC_DAC_MEM_B0_3)
#define BB_DC_DAC_MEM_B0_3_DC_DAC_SETTING_MSB                        19
#define BB_DC_DAC_MEM_B0_3_DC_DAC_SETTING_LSB                        0
#define BB_DC_DAC_MEM_B0_3_DC_DAC_SETTING_MASK                       0x000fffff
#define BB_DC_DAC_MEM_B0_3_DC_DAC_SETTING_GET(x)                     (((x) & BB_DC_DAC_MEM_B0_3_DC_DAC_SETTING_MASK) >> BB_DC_DAC_MEM_B0_3_DC_DAC_SETTING_LSB)
#define BB_DC_DAC_MEM_B0_3_DC_DAC_SETTING_SET(x)                     (((0 | (x)) << BB_DC_DAC_MEM_B0_3_DC_DAC_SETTING_LSB) & BB_DC_DAC_MEM_B0_3_DC_DAC_SETTING_MASK)
#define BB_DC_DAC_MEM_B0_3_DC_DAC_SETTING_RESET                      0
#define BB_DC_DAC_MEM_B0_3_ADDRESS                                   0x03cc
#define BB_DC_DAC_MEM_B0_3_HW_MASK                                   0x000fffff
#define BB_DC_DAC_MEM_B0_3_SW_MASK                                   0x000fffff
#define BB_DC_DAC_MEM_B0_3_HW_WRITE_MASK                             0x000fffff
#define BB_DC_DAC_MEM_B0_3_SW_WRITE_MASK                             0x000fffff
#define BB_DC_DAC_MEM_B0_3_RSTMASK                                   0xffffffff
#define BB_DC_DAC_MEM_B0_3_RESET                                     0x00000000

// 0x0400 (BB_TPC_TXGAIN_SRAM_0)
#define BB_TPC_TXGAIN_SRAM_0_TPC_TXGAIN_WORD_MSB                     31
#define BB_TPC_TXGAIN_SRAM_0_TPC_TXGAIN_WORD_LSB                     0
#define BB_TPC_TXGAIN_SRAM_0_TPC_TXGAIN_WORD_MASK                    0xffffffff
#define BB_TPC_TXGAIN_SRAM_0_TPC_TXGAIN_WORD_GET(x)                  (((x) & BB_TPC_TXGAIN_SRAM_0_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_0_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_0_TPC_TXGAIN_WORD_SET(x)                  (((0 | (x)) << BB_TPC_TXGAIN_SRAM_0_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_0_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_0_TPC_TXGAIN_WORD_RESET                   0
#define BB_TPC_TXGAIN_SRAM_0_ADDRESS                                 0x0400
#define BB_TPC_TXGAIN_SRAM_ADDRESS                                   BB_TPC_TXGAIN_SRAM_0_ADDRESS
#define BB_TPC_TXGAIN_SRAM_0_HW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_0_SW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_0_HW_WRITE_MASK                           0x00000000
#define BB_TPC_TXGAIN_SRAM_0_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_TXGAIN_SRAM_0_RSTMASK                                 0x00000000
#define BB_TPC_TXGAIN_SRAM_0_RESET                                   0x00000000

// 0x0404 (BB_TPC_TXGAIN_SRAM_1)
#define BB_TPC_TXGAIN_SRAM_1_TPC_TXGAIN_WORD_MSB                     31
#define BB_TPC_TXGAIN_SRAM_1_TPC_TXGAIN_WORD_LSB                     0
#define BB_TPC_TXGAIN_SRAM_1_TPC_TXGAIN_WORD_MASK                    0xffffffff
#define BB_TPC_TXGAIN_SRAM_1_TPC_TXGAIN_WORD_GET(x)                  (((x) & BB_TPC_TXGAIN_SRAM_1_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_1_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_1_TPC_TXGAIN_WORD_SET(x)                  (((0 | (x)) << BB_TPC_TXGAIN_SRAM_1_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_1_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_1_TPC_TXGAIN_WORD_RESET                   0
#define BB_TPC_TXGAIN_SRAM_1_ADDRESS                                 0x0404
#define BB_TPC_TXGAIN_SRAM_1_HW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_1_SW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_1_HW_WRITE_MASK                           0x00000000
#define BB_TPC_TXGAIN_SRAM_1_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_TXGAIN_SRAM_1_RSTMASK                                 0x00000000
#define BB_TPC_TXGAIN_SRAM_1_RESET                                   0x00000000

// 0x0408 (BB_TPC_TXGAIN_SRAM_2)
#define BB_TPC_TXGAIN_SRAM_2_TPC_TXGAIN_WORD_MSB                     31
#define BB_TPC_TXGAIN_SRAM_2_TPC_TXGAIN_WORD_LSB                     0
#define BB_TPC_TXGAIN_SRAM_2_TPC_TXGAIN_WORD_MASK                    0xffffffff
#define BB_TPC_TXGAIN_SRAM_2_TPC_TXGAIN_WORD_GET(x)                  (((x) & BB_TPC_TXGAIN_SRAM_2_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_2_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_2_TPC_TXGAIN_WORD_SET(x)                  (((0 | (x)) << BB_TPC_TXGAIN_SRAM_2_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_2_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_2_TPC_TXGAIN_WORD_RESET                   0
#define BB_TPC_TXGAIN_SRAM_2_ADDRESS                                 0x0408
#define BB_TPC_TXGAIN_SRAM_2_HW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_2_SW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_2_HW_WRITE_MASK                           0x00000000
#define BB_TPC_TXGAIN_SRAM_2_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_TXGAIN_SRAM_2_RSTMASK                                 0x00000000
#define BB_TPC_TXGAIN_SRAM_2_RESET                                   0x00000000

// 0x040c (BB_TPC_TXGAIN_SRAM_3)
#define BB_TPC_TXGAIN_SRAM_3_TPC_TXGAIN_WORD_MSB                     31
#define BB_TPC_TXGAIN_SRAM_3_TPC_TXGAIN_WORD_LSB                     0
#define BB_TPC_TXGAIN_SRAM_3_TPC_TXGAIN_WORD_MASK                    0xffffffff
#define BB_TPC_TXGAIN_SRAM_3_TPC_TXGAIN_WORD_GET(x)                  (((x) & BB_TPC_TXGAIN_SRAM_3_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_3_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_3_TPC_TXGAIN_WORD_SET(x)                  (((0 | (x)) << BB_TPC_TXGAIN_SRAM_3_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_3_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_3_TPC_TXGAIN_WORD_RESET                   0
#define BB_TPC_TXGAIN_SRAM_3_ADDRESS                                 0x040c
#define BB_TPC_TXGAIN_SRAM_3_HW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_3_SW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_3_HW_WRITE_MASK                           0x00000000
#define BB_TPC_TXGAIN_SRAM_3_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_TXGAIN_SRAM_3_RSTMASK                                 0x00000000
#define BB_TPC_TXGAIN_SRAM_3_RESET                                   0x00000000

// 0x0410 (BB_TPC_TXGAIN_SRAM_4)
#define BB_TPC_TXGAIN_SRAM_4_TPC_TXGAIN_WORD_MSB                     31
#define BB_TPC_TXGAIN_SRAM_4_TPC_TXGAIN_WORD_LSB                     0
#define BB_TPC_TXGAIN_SRAM_4_TPC_TXGAIN_WORD_MASK                    0xffffffff
#define BB_TPC_TXGAIN_SRAM_4_TPC_TXGAIN_WORD_GET(x)                  (((x) & BB_TPC_TXGAIN_SRAM_4_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_4_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_4_TPC_TXGAIN_WORD_SET(x)                  (((0 | (x)) << BB_TPC_TXGAIN_SRAM_4_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_4_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_4_TPC_TXGAIN_WORD_RESET                   0
#define BB_TPC_TXGAIN_SRAM_4_ADDRESS                                 0x0410
#define BB_TPC_TXGAIN_SRAM_4_HW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_4_SW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_4_HW_WRITE_MASK                           0x00000000
#define BB_TPC_TXGAIN_SRAM_4_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_TXGAIN_SRAM_4_RSTMASK                                 0x00000000
#define BB_TPC_TXGAIN_SRAM_4_RESET                                   0x00000000

// 0x0414 (BB_TPC_TXGAIN_SRAM_5)
#define BB_TPC_TXGAIN_SRAM_5_TPC_TXGAIN_WORD_MSB                     31
#define BB_TPC_TXGAIN_SRAM_5_TPC_TXGAIN_WORD_LSB                     0
#define BB_TPC_TXGAIN_SRAM_5_TPC_TXGAIN_WORD_MASK                    0xffffffff
#define BB_TPC_TXGAIN_SRAM_5_TPC_TXGAIN_WORD_GET(x)                  (((x) & BB_TPC_TXGAIN_SRAM_5_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_5_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_5_TPC_TXGAIN_WORD_SET(x)                  (((0 | (x)) << BB_TPC_TXGAIN_SRAM_5_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_5_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_5_TPC_TXGAIN_WORD_RESET                   0
#define BB_TPC_TXGAIN_SRAM_5_ADDRESS                                 0x0414
#define BB_TPC_TXGAIN_SRAM_5_HW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_5_SW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_5_HW_WRITE_MASK                           0x00000000
#define BB_TPC_TXGAIN_SRAM_5_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_TXGAIN_SRAM_5_RSTMASK                                 0x00000000
#define BB_TPC_TXGAIN_SRAM_5_RESET                                   0x00000000

// 0x0418 (BB_TPC_TXGAIN_SRAM_6)
#define BB_TPC_TXGAIN_SRAM_6_TPC_TXGAIN_WORD_MSB                     31
#define BB_TPC_TXGAIN_SRAM_6_TPC_TXGAIN_WORD_LSB                     0
#define BB_TPC_TXGAIN_SRAM_6_TPC_TXGAIN_WORD_MASK                    0xffffffff
#define BB_TPC_TXGAIN_SRAM_6_TPC_TXGAIN_WORD_GET(x)                  (((x) & BB_TPC_TXGAIN_SRAM_6_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_6_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_6_TPC_TXGAIN_WORD_SET(x)                  (((0 | (x)) << BB_TPC_TXGAIN_SRAM_6_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_6_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_6_TPC_TXGAIN_WORD_RESET                   0
#define BB_TPC_TXGAIN_SRAM_6_ADDRESS                                 0x0418
#define BB_TPC_TXGAIN_SRAM_6_HW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_6_SW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_6_HW_WRITE_MASK                           0x00000000
#define BB_TPC_TXGAIN_SRAM_6_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_TXGAIN_SRAM_6_RSTMASK                                 0x00000000
#define BB_TPC_TXGAIN_SRAM_6_RESET                                   0x00000000

// 0x041c (BB_TPC_TXGAIN_SRAM_7)
#define BB_TPC_TXGAIN_SRAM_7_TPC_TXGAIN_WORD_MSB                     31
#define BB_TPC_TXGAIN_SRAM_7_TPC_TXGAIN_WORD_LSB                     0
#define BB_TPC_TXGAIN_SRAM_7_TPC_TXGAIN_WORD_MASK                    0xffffffff
#define BB_TPC_TXGAIN_SRAM_7_TPC_TXGAIN_WORD_GET(x)                  (((x) & BB_TPC_TXGAIN_SRAM_7_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_7_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_7_TPC_TXGAIN_WORD_SET(x)                  (((0 | (x)) << BB_TPC_TXGAIN_SRAM_7_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_7_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_7_TPC_TXGAIN_WORD_RESET                   0
#define BB_TPC_TXGAIN_SRAM_7_ADDRESS                                 0x041c
#define BB_TPC_TXGAIN_SRAM_7_HW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_7_SW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_7_HW_WRITE_MASK                           0x00000000
#define BB_TPC_TXGAIN_SRAM_7_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_TXGAIN_SRAM_7_RSTMASK                                 0x00000000
#define BB_TPC_TXGAIN_SRAM_7_RESET                                   0x00000000

// 0x0420 (BB_TPC_TXGAIN_SRAM_8)
#define BB_TPC_TXGAIN_SRAM_8_TPC_TXGAIN_WORD_MSB                     31
#define BB_TPC_TXGAIN_SRAM_8_TPC_TXGAIN_WORD_LSB                     0
#define BB_TPC_TXGAIN_SRAM_8_TPC_TXGAIN_WORD_MASK                    0xffffffff
#define BB_TPC_TXGAIN_SRAM_8_TPC_TXGAIN_WORD_GET(x)                  (((x) & BB_TPC_TXGAIN_SRAM_8_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_8_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_8_TPC_TXGAIN_WORD_SET(x)                  (((0 | (x)) << BB_TPC_TXGAIN_SRAM_8_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_8_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_8_TPC_TXGAIN_WORD_RESET                   0
#define BB_TPC_TXGAIN_SRAM_8_ADDRESS                                 0x0420
#define BB_TPC_TXGAIN_SRAM_8_HW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_8_SW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_8_HW_WRITE_MASK                           0x00000000
#define BB_TPC_TXGAIN_SRAM_8_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_TXGAIN_SRAM_8_RSTMASK                                 0x00000000
#define BB_TPC_TXGAIN_SRAM_8_RESET                                   0x00000000

// 0x0424 (BB_TPC_TXGAIN_SRAM_9)
#define BB_TPC_TXGAIN_SRAM_9_TPC_TXGAIN_WORD_MSB                     31
#define BB_TPC_TXGAIN_SRAM_9_TPC_TXGAIN_WORD_LSB                     0
#define BB_TPC_TXGAIN_SRAM_9_TPC_TXGAIN_WORD_MASK                    0xffffffff
#define BB_TPC_TXGAIN_SRAM_9_TPC_TXGAIN_WORD_GET(x)                  (((x) & BB_TPC_TXGAIN_SRAM_9_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_9_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_9_TPC_TXGAIN_WORD_SET(x)                  (((0 | (x)) << BB_TPC_TXGAIN_SRAM_9_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_9_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_9_TPC_TXGAIN_WORD_RESET                   0
#define BB_TPC_TXGAIN_SRAM_9_ADDRESS                                 0x0424
#define BB_TPC_TXGAIN_SRAM_9_HW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_9_SW_MASK                                 0xffffffff
#define BB_TPC_TXGAIN_SRAM_9_HW_WRITE_MASK                           0x00000000
#define BB_TPC_TXGAIN_SRAM_9_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_TXGAIN_SRAM_9_RSTMASK                                 0x00000000
#define BB_TPC_TXGAIN_SRAM_9_RESET                                   0x00000000

// 0x0428 (BB_TPC_TXGAIN_SRAM_10)
#define BB_TPC_TXGAIN_SRAM_10_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_10_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_10_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_10_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_10_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_10_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_10_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_10_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_10_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_10_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_10_ADDRESS                                0x0428
#define BB_TPC_TXGAIN_SRAM_10_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_10_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_10_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_10_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_10_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_10_RESET                                  0x00000000

// 0x042c (BB_TPC_TXGAIN_SRAM_11)
#define BB_TPC_TXGAIN_SRAM_11_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_11_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_11_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_11_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_11_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_11_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_11_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_11_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_11_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_11_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_11_ADDRESS                                0x042c
#define BB_TPC_TXGAIN_SRAM_11_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_11_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_11_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_11_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_11_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_11_RESET                                  0x00000000

// 0x0430 (BB_TPC_TXGAIN_SRAM_12)
#define BB_TPC_TXGAIN_SRAM_12_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_12_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_12_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_12_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_12_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_12_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_12_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_12_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_12_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_12_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_12_ADDRESS                                0x0430
#define BB_TPC_TXGAIN_SRAM_12_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_12_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_12_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_12_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_12_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_12_RESET                                  0x00000000

// 0x0434 (BB_TPC_TXGAIN_SRAM_13)
#define BB_TPC_TXGAIN_SRAM_13_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_13_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_13_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_13_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_13_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_13_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_13_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_13_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_13_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_13_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_13_ADDRESS                                0x0434
#define BB_TPC_TXGAIN_SRAM_13_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_13_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_13_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_13_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_13_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_13_RESET                                  0x00000000

// 0x0438 (BB_TPC_TXGAIN_SRAM_14)
#define BB_TPC_TXGAIN_SRAM_14_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_14_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_14_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_14_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_14_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_14_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_14_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_14_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_14_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_14_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_14_ADDRESS                                0x0438
#define BB_TPC_TXGAIN_SRAM_14_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_14_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_14_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_14_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_14_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_14_RESET                                  0x00000000

// 0x043c (BB_TPC_TXGAIN_SRAM_15)
#define BB_TPC_TXGAIN_SRAM_15_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_15_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_15_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_15_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_15_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_15_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_15_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_15_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_15_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_15_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_15_ADDRESS                                0x043c
#define BB_TPC_TXGAIN_SRAM_15_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_15_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_15_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_15_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_15_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_15_RESET                                  0x00000000

// 0x0440 (BB_TPC_TXGAIN_SRAM_16)
#define BB_TPC_TXGAIN_SRAM_16_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_16_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_16_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_16_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_16_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_16_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_16_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_16_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_16_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_16_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_16_ADDRESS                                0x0440
#define BB_TPC_TXGAIN_SRAM_16_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_16_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_16_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_16_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_16_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_16_RESET                                  0x00000000

// 0x0444 (BB_TPC_TXGAIN_SRAM_17)
#define BB_TPC_TXGAIN_SRAM_17_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_17_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_17_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_17_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_17_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_17_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_17_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_17_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_17_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_17_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_17_ADDRESS                                0x0444
#define BB_TPC_TXGAIN_SRAM_17_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_17_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_17_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_17_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_17_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_17_RESET                                  0x00000000

// 0x0448 (BB_TPC_TXGAIN_SRAM_18)
#define BB_TPC_TXGAIN_SRAM_18_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_18_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_18_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_18_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_18_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_18_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_18_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_18_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_18_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_18_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_18_ADDRESS                                0x0448
#define BB_TPC_TXGAIN_SRAM_18_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_18_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_18_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_18_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_18_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_18_RESET                                  0x00000000

// 0x044c (BB_TPC_TXGAIN_SRAM_19)
#define BB_TPC_TXGAIN_SRAM_19_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_19_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_19_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_19_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_19_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_19_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_19_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_19_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_19_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_19_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_19_ADDRESS                                0x044c
#define BB_TPC_TXGAIN_SRAM_19_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_19_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_19_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_19_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_19_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_19_RESET                                  0x00000000

// 0x0450 (BB_TPC_TXGAIN_SRAM_20)
#define BB_TPC_TXGAIN_SRAM_20_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_20_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_20_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_20_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_20_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_20_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_20_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_20_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_20_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_20_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_20_ADDRESS                                0x0450
#define BB_TPC_TXGAIN_SRAM_20_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_20_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_20_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_20_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_20_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_20_RESET                                  0x00000000

// 0x0454 (BB_TPC_TXGAIN_SRAM_21)
#define BB_TPC_TXGAIN_SRAM_21_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_21_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_21_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_21_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_21_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_21_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_21_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_21_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_21_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_21_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_21_ADDRESS                                0x0454
#define BB_TPC_TXGAIN_SRAM_21_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_21_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_21_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_21_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_21_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_21_RESET                                  0x00000000

// 0x0458 (BB_TPC_TXGAIN_SRAM_22)
#define BB_TPC_TXGAIN_SRAM_22_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_22_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_22_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_22_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_22_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_22_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_22_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_22_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_22_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_22_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_22_ADDRESS                                0x0458
#define BB_TPC_TXGAIN_SRAM_22_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_22_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_22_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_22_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_22_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_22_RESET                                  0x00000000

// 0x045c (BB_TPC_TXGAIN_SRAM_23)
#define BB_TPC_TXGAIN_SRAM_23_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_23_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_23_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_23_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_23_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_23_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_23_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_23_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_23_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_23_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_23_ADDRESS                                0x045c
#define BB_TPC_TXGAIN_SRAM_23_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_23_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_23_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_23_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_23_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_23_RESET                                  0x00000000

// 0x0460 (BB_TPC_TXGAIN_SRAM_24)
#define BB_TPC_TXGAIN_SRAM_24_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_24_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_24_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_24_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_24_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_24_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_24_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_24_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_24_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_24_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_24_ADDRESS                                0x0460
#define BB_TPC_TXGAIN_SRAM_24_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_24_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_24_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_24_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_24_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_24_RESET                                  0x00000000

// 0x0464 (BB_TPC_TXGAIN_SRAM_25)
#define BB_TPC_TXGAIN_SRAM_25_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_25_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_25_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_25_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_25_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_25_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_25_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_25_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_25_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_25_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_25_ADDRESS                                0x0464
#define BB_TPC_TXGAIN_SRAM_25_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_25_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_25_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_25_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_25_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_25_RESET                                  0x00000000

// 0x0468 (BB_TPC_TXGAIN_SRAM_26)
#define BB_TPC_TXGAIN_SRAM_26_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_26_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_26_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_26_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_26_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_26_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_26_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_26_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_26_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_26_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_26_ADDRESS                                0x0468
#define BB_TPC_TXGAIN_SRAM_26_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_26_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_26_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_26_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_26_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_26_RESET                                  0x00000000

// 0x046c (BB_TPC_TXGAIN_SRAM_27)
#define BB_TPC_TXGAIN_SRAM_27_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_27_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_27_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_27_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_27_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_27_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_27_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_27_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_27_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_27_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_27_ADDRESS                                0x046c
#define BB_TPC_TXGAIN_SRAM_27_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_27_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_27_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_27_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_27_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_27_RESET                                  0x00000000

// 0x0470 (BB_TPC_TXGAIN_SRAM_28)
#define BB_TPC_TXGAIN_SRAM_28_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_28_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_28_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_28_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_28_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_28_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_28_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_28_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_28_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_28_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_28_ADDRESS                                0x0470
#define BB_TPC_TXGAIN_SRAM_28_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_28_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_28_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_28_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_28_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_28_RESET                                  0x00000000

// 0x0474 (BB_TPC_TXGAIN_SRAM_29)
#define BB_TPC_TXGAIN_SRAM_29_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_29_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_29_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_29_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_29_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_29_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_29_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_29_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_29_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_29_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_29_ADDRESS                                0x0474
#define BB_TPC_TXGAIN_SRAM_29_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_29_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_29_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_29_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_29_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_29_RESET                                  0x00000000

// 0x0478 (BB_TPC_TXGAIN_SRAM_30)
#define BB_TPC_TXGAIN_SRAM_30_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_30_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_30_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_30_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_30_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_30_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_30_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_30_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_30_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_30_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_30_ADDRESS                                0x0478
#define BB_TPC_TXGAIN_SRAM_30_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_30_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_30_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_30_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_30_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_30_RESET                                  0x00000000

// 0x047c (BB_TPC_TXGAIN_SRAM_31)
#define BB_TPC_TXGAIN_SRAM_31_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_31_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_31_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_31_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_31_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_31_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_31_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_31_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_31_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_31_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_31_ADDRESS                                0x047c
#define BB_TPC_TXGAIN_SRAM_31_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_31_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_31_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_31_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_31_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_31_RESET                                  0x00000000

// 0x0480 (BB_TPC_TXGAIN_SRAM_32)
#define BB_TPC_TXGAIN_SRAM_32_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_32_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_32_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_32_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_32_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_32_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_32_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_32_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_32_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_32_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_32_ADDRESS                                0x0480
#define BB_TPC_TXGAIN_SRAM_32_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_32_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_32_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_32_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_32_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_32_RESET                                  0x00000000

// 0x0484 (BB_TPC_TXGAIN_SRAM_33)
#define BB_TPC_TXGAIN_SRAM_33_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_33_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_33_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_33_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_33_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_33_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_33_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_33_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_33_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_33_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_33_ADDRESS                                0x0484
#define BB_TPC_TXGAIN_SRAM_33_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_33_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_33_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_33_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_33_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_33_RESET                                  0x00000000

// 0x0488 (BB_TPC_TXGAIN_SRAM_34)
#define BB_TPC_TXGAIN_SRAM_34_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_34_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_34_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_34_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_34_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_34_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_34_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_34_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_34_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_34_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_34_ADDRESS                                0x0488
#define BB_TPC_TXGAIN_SRAM_34_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_34_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_34_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_34_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_34_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_34_RESET                                  0x00000000

// 0x048c (BB_TPC_TXGAIN_SRAM_35)
#define BB_TPC_TXGAIN_SRAM_35_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_35_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_35_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_35_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_35_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_35_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_35_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_35_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_35_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_35_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_35_ADDRESS                                0x048c
#define BB_TPC_TXGAIN_SRAM_35_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_35_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_35_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_35_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_35_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_35_RESET                                  0x00000000

// 0x0490 (BB_TPC_TXGAIN_SRAM_36)
#define BB_TPC_TXGAIN_SRAM_36_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_36_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_36_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_36_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_36_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_36_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_36_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_36_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_36_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_36_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_36_ADDRESS                                0x0490
#define BB_TPC_TXGAIN_SRAM_36_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_36_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_36_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_36_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_36_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_36_RESET                                  0x00000000

// 0x0494 (BB_TPC_TXGAIN_SRAM_37)
#define BB_TPC_TXGAIN_SRAM_37_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_37_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_37_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_37_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_37_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_37_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_37_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_37_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_37_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_37_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_37_ADDRESS                                0x0494
#define BB_TPC_TXGAIN_SRAM_37_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_37_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_37_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_37_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_37_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_37_RESET                                  0x00000000

// 0x0498 (BB_TPC_TXGAIN_SRAM_38)
#define BB_TPC_TXGAIN_SRAM_38_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_38_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_38_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_38_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_38_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_38_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_38_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_38_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_38_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_38_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_38_ADDRESS                                0x0498
#define BB_TPC_TXGAIN_SRAM_38_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_38_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_38_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_38_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_38_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_38_RESET                                  0x00000000

// 0x049c (BB_TPC_TXGAIN_SRAM_39)
#define BB_TPC_TXGAIN_SRAM_39_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_39_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_39_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_39_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_39_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_39_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_39_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_39_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_39_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_39_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_39_ADDRESS                                0x049c
#define BB_TPC_TXGAIN_SRAM_39_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_39_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_39_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_39_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_39_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_39_RESET                                  0x00000000

// 0x04a0 (BB_TPC_TXGAIN_SRAM_40)
#define BB_TPC_TXGAIN_SRAM_40_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_40_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_40_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_40_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_40_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_40_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_40_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_40_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_40_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_40_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_40_ADDRESS                                0x04a0
#define BB_TPC_TXGAIN_SRAM_40_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_40_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_40_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_40_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_40_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_40_RESET                                  0x00000000

// 0x04a4 (BB_TPC_TXGAIN_SRAM_41)
#define BB_TPC_TXGAIN_SRAM_41_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_41_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_41_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_41_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_41_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_41_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_41_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_41_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_41_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_41_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_41_ADDRESS                                0x04a4
#define BB_TPC_TXGAIN_SRAM_41_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_41_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_41_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_41_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_41_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_41_RESET                                  0x00000000

// 0x04a8 (BB_TPC_TXGAIN_SRAM_42)
#define BB_TPC_TXGAIN_SRAM_42_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_42_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_42_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_42_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_42_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_42_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_42_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_42_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_42_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_42_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_42_ADDRESS                                0x04a8
#define BB_TPC_TXGAIN_SRAM_42_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_42_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_42_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_42_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_42_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_42_RESET                                  0x00000000

// 0x04ac (BB_TPC_TXGAIN_SRAM_43)
#define BB_TPC_TXGAIN_SRAM_43_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_43_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_43_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_43_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_43_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_43_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_43_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_43_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_43_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_43_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_43_ADDRESS                                0x04ac
#define BB_TPC_TXGAIN_SRAM_43_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_43_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_43_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_43_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_43_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_43_RESET                                  0x00000000

// 0x04b0 (BB_TPC_TXGAIN_SRAM_44)
#define BB_TPC_TXGAIN_SRAM_44_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_44_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_44_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_44_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_44_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_44_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_44_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_44_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_44_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_44_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_44_ADDRESS                                0x04b0
#define BB_TPC_TXGAIN_SRAM_44_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_44_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_44_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_44_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_44_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_44_RESET                                  0x00000000

// 0x04b4 (BB_TPC_TXGAIN_SRAM_45)
#define BB_TPC_TXGAIN_SRAM_45_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_45_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_45_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_45_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_45_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_45_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_45_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_45_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_45_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_45_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_45_ADDRESS                                0x04b4
#define BB_TPC_TXGAIN_SRAM_45_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_45_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_45_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_45_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_45_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_45_RESET                                  0x00000000

// 0x04b8 (BB_TPC_TXGAIN_SRAM_46)
#define BB_TPC_TXGAIN_SRAM_46_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_46_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_46_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_46_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_46_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_46_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_46_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_46_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_46_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_46_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_46_ADDRESS                                0x04b8
#define BB_TPC_TXGAIN_SRAM_46_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_46_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_46_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_46_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_46_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_46_RESET                                  0x00000000

// 0x04bc (BB_TPC_TXGAIN_SRAM_47)
#define BB_TPC_TXGAIN_SRAM_47_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_47_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_47_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_47_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_47_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_47_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_47_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_47_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_47_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_47_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_47_ADDRESS                                0x04bc
#define BB_TPC_TXGAIN_SRAM_47_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_47_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_47_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_47_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_47_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_47_RESET                                  0x00000000

// 0x04c0 (BB_TPC_TXGAIN_SRAM_48)
#define BB_TPC_TXGAIN_SRAM_48_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_48_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_48_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_48_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_48_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_48_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_48_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_48_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_48_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_48_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_48_ADDRESS                                0x04c0
#define BB_TPC_TXGAIN_SRAM_48_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_48_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_48_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_48_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_48_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_48_RESET                                  0x00000000

// 0x04c4 (BB_TPC_TXGAIN_SRAM_49)
#define BB_TPC_TXGAIN_SRAM_49_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_49_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_49_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_49_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_49_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_49_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_49_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_49_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_49_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_49_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_49_ADDRESS                                0x04c4
#define BB_TPC_TXGAIN_SRAM_49_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_49_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_49_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_49_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_49_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_49_RESET                                  0x00000000

// 0x04c8 (BB_TPC_TXGAIN_SRAM_50)
#define BB_TPC_TXGAIN_SRAM_50_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_50_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_50_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_50_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_50_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_50_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_50_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_50_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_50_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_50_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_50_ADDRESS                                0x04c8
#define BB_TPC_TXGAIN_SRAM_50_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_50_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_50_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_50_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_50_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_50_RESET                                  0x00000000

// 0x04cc (BB_TPC_TXGAIN_SRAM_51)
#define BB_TPC_TXGAIN_SRAM_51_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_51_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_51_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_51_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_51_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_51_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_51_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_51_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_51_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_51_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_51_ADDRESS                                0x04cc
#define BB_TPC_TXGAIN_SRAM_51_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_51_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_51_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_51_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_51_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_51_RESET                                  0x00000000

// 0x04d0 (BB_TPC_TXGAIN_SRAM_52)
#define BB_TPC_TXGAIN_SRAM_52_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_52_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_52_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_52_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_52_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_52_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_52_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_52_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_52_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_52_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_52_ADDRESS                                0x04d0
#define BB_TPC_TXGAIN_SRAM_52_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_52_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_52_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_52_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_52_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_52_RESET                                  0x00000000

// 0x04d4 (BB_TPC_TXGAIN_SRAM_53)
#define BB_TPC_TXGAIN_SRAM_53_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_53_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_53_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_53_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_53_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_53_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_53_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_53_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_53_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_53_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_53_ADDRESS                                0x04d4
#define BB_TPC_TXGAIN_SRAM_53_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_53_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_53_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_53_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_53_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_53_RESET                                  0x00000000

// 0x04d8 (BB_TPC_TXGAIN_SRAM_54)
#define BB_TPC_TXGAIN_SRAM_54_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_54_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_54_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_54_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_54_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_54_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_54_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_54_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_54_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_54_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_54_ADDRESS                                0x04d8
#define BB_TPC_TXGAIN_SRAM_54_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_54_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_54_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_54_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_54_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_54_RESET                                  0x00000000

// 0x04dc (BB_TPC_TXGAIN_SRAM_55)
#define BB_TPC_TXGAIN_SRAM_55_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_55_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_55_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_55_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_55_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_55_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_55_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_55_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_55_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_55_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_55_ADDRESS                                0x04dc
#define BB_TPC_TXGAIN_SRAM_55_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_55_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_55_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_55_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_55_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_55_RESET                                  0x00000000

// 0x04e0 (BB_TPC_TXGAIN_SRAM_56)
#define BB_TPC_TXGAIN_SRAM_56_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_56_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_56_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_56_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_56_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_56_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_56_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_56_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_56_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_56_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_56_ADDRESS                                0x04e0
#define BB_TPC_TXGAIN_SRAM_56_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_56_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_56_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_56_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_56_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_56_RESET                                  0x00000000

// 0x04e4 (BB_TPC_TXGAIN_SRAM_57)
#define BB_TPC_TXGAIN_SRAM_57_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_57_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_57_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_57_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_57_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_57_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_57_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_57_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_57_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_57_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_57_ADDRESS                                0x04e4
#define BB_TPC_TXGAIN_SRAM_57_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_57_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_57_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_57_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_57_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_57_RESET                                  0x00000000

// 0x04e8 (BB_TPC_TXGAIN_SRAM_58)
#define BB_TPC_TXGAIN_SRAM_58_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_58_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_58_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_58_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_58_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_58_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_58_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_58_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_58_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_58_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_58_ADDRESS                                0x04e8
#define BB_TPC_TXGAIN_SRAM_58_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_58_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_58_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_58_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_58_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_58_RESET                                  0x00000000

// 0x04ec (BB_TPC_TXGAIN_SRAM_59)
#define BB_TPC_TXGAIN_SRAM_59_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_59_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_59_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_59_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_59_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_59_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_59_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_59_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_59_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_59_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_59_ADDRESS                                0x04ec
#define BB_TPC_TXGAIN_SRAM_59_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_59_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_59_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_59_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_59_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_59_RESET                                  0x00000000

// 0x04f0 (BB_TPC_TXGAIN_SRAM_60)
#define BB_TPC_TXGAIN_SRAM_60_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_60_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_60_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_60_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_60_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_60_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_60_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_60_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_60_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_60_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_60_ADDRESS                                0x04f0
#define BB_TPC_TXGAIN_SRAM_60_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_60_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_60_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_60_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_60_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_60_RESET                                  0x00000000

// 0x04f4 (BB_TPC_TXGAIN_SRAM_61)
#define BB_TPC_TXGAIN_SRAM_61_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_61_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_61_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_61_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_61_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_61_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_61_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_61_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_61_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_61_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_61_ADDRESS                                0x04f4
#define BB_TPC_TXGAIN_SRAM_61_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_61_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_61_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_61_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_61_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_61_RESET                                  0x00000000

// 0x04f8 (BB_TPC_TXGAIN_SRAM_62)
#define BB_TPC_TXGAIN_SRAM_62_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_62_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_62_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_62_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_62_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_62_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_62_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_62_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_62_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_62_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_62_ADDRESS                                0x04f8
#define BB_TPC_TXGAIN_SRAM_62_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_62_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_62_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_62_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_62_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_62_RESET                                  0x00000000

// 0x04fc (BB_TPC_TXGAIN_SRAM_63)
#define BB_TPC_TXGAIN_SRAM_63_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_63_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_63_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_63_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_63_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_63_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_63_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_63_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_63_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_63_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_63_ADDRESS                                0x04fc
#define BB_TPC_TXGAIN_SRAM_63_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_63_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_63_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_63_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_63_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_63_RESET                                  0x00000000

// 0x0500 (BB_TPC_TXGAIN_SRAM_64)
#define BB_TPC_TXGAIN_SRAM_64_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_64_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_64_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_64_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_64_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_64_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_64_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_64_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_64_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_64_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_64_ADDRESS                                0x0500
#define BB_TPC_TXGAIN_SRAM_64_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_64_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_64_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_64_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_64_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_64_RESET                                  0x00000000

// 0x0504 (BB_TPC_TXGAIN_SRAM_65)
#define BB_TPC_TXGAIN_SRAM_65_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_65_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_65_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_65_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_65_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_65_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_65_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_65_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_65_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_65_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_65_ADDRESS                                0x0504
#define BB_TPC_TXGAIN_SRAM_65_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_65_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_65_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_65_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_65_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_65_RESET                                  0x00000000

// 0x0508 (BB_TPC_TXGAIN_SRAM_66)
#define BB_TPC_TXGAIN_SRAM_66_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_66_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_66_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_66_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_66_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_66_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_66_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_66_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_66_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_66_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_66_ADDRESS                                0x0508
#define BB_TPC_TXGAIN_SRAM_66_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_66_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_66_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_66_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_66_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_66_RESET                                  0x00000000

// 0x050c (BB_TPC_TXGAIN_SRAM_67)
#define BB_TPC_TXGAIN_SRAM_67_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_67_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_67_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_67_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_67_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_67_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_67_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_67_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_67_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_67_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_67_ADDRESS                                0x050c
#define BB_TPC_TXGAIN_SRAM_67_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_67_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_67_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_67_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_67_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_67_RESET                                  0x00000000

// 0x0510 (BB_TPC_TXGAIN_SRAM_68)
#define BB_TPC_TXGAIN_SRAM_68_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_68_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_68_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_68_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_68_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_68_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_68_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_68_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_68_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_68_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_68_ADDRESS                                0x0510
#define BB_TPC_TXGAIN_SRAM_68_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_68_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_68_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_68_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_68_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_68_RESET                                  0x00000000

// 0x0514 (BB_TPC_TXGAIN_SRAM_69)
#define BB_TPC_TXGAIN_SRAM_69_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_69_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_69_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_69_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_69_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_69_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_69_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_69_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_69_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_69_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_69_ADDRESS                                0x0514
#define BB_TPC_TXGAIN_SRAM_69_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_69_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_69_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_69_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_69_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_69_RESET                                  0x00000000

// 0x0518 (BB_TPC_TXGAIN_SRAM_70)
#define BB_TPC_TXGAIN_SRAM_70_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_70_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_70_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_70_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_70_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_70_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_70_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_70_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_70_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_70_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_70_ADDRESS                                0x0518
#define BB_TPC_TXGAIN_SRAM_70_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_70_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_70_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_70_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_70_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_70_RESET                                  0x00000000

// 0x051c (BB_TPC_TXGAIN_SRAM_71)
#define BB_TPC_TXGAIN_SRAM_71_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_71_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_71_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_71_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_71_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_71_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_71_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_71_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_71_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_71_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_71_ADDRESS                                0x051c
#define BB_TPC_TXGAIN_SRAM_71_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_71_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_71_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_71_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_71_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_71_RESET                                  0x00000000

// 0x0520 (BB_TPC_TXGAIN_SRAM_72)
#define BB_TPC_TXGAIN_SRAM_72_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_72_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_72_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_72_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_72_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_72_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_72_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_72_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_72_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_72_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_72_ADDRESS                                0x0520
#define BB_TPC_TXGAIN_SRAM_72_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_72_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_72_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_72_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_72_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_72_RESET                                  0x00000000

// 0x0524 (BB_TPC_TXGAIN_SRAM_73)
#define BB_TPC_TXGAIN_SRAM_73_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_73_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_73_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_73_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_73_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_73_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_73_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_73_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_73_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_73_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_73_ADDRESS                                0x0524
#define BB_TPC_TXGAIN_SRAM_73_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_73_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_73_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_73_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_73_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_73_RESET                                  0x00000000

// 0x0528 (BB_TPC_TXGAIN_SRAM_74)
#define BB_TPC_TXGAIN_SRAM_74_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_74_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_74_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_74_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_74_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_74_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_74_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_74_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_74_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_74_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_74_ADDRESS                                0x0528
#define BB_TPC_TXGAIN_SRAM_74_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_74_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_74_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_74_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_74_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_74_RESET                                  0x00000000

// 0x052c (BB_TPC_TXGAIN_SRAM_75)
#define BB_TPC_TXGAIN_SRAM_75_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_75_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_75_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_75_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_75_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_75_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_75_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_75_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_75_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_75_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_75_ADDRESS                                0x052c
#define BB_TPC_TXGAIN_SRAM_75_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_75_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_75_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_75_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_75_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_75_RESET                                  0x00000000

// 0x0530 (BB_TPC_TXGAIN_SRAM_76)
#define BB_TPC_TXGAIN_SRAM_76_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_76_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_76_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_76_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_76_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_76_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_76_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_76_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_76_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_76_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_76_ADDRESS                                0x0530
#define BB_TPC_TXGAIN_SRAM_76_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_76_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_76_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_76_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_76_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_76_RESET                                  0x00000000

// 0x0534 (BB_TPC_TXGAIN_SRAM_77)
#define BB_TPC_TXGAIN_SRAM_77_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_77_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_77_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_77_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_77_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_77_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_77_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_77_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_77_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_77_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_77_ADDRESS                                0x0534
#define BB_TPC_TXGAIN_SRAM_77_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_77_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_77_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_77_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_77_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_77_RESET                                  0x00000000

// 0x0538 (BB_TPC_TXGAIN_SRAM_78)
#define BB_TPC_TXGAIN_SRAM_78_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_78_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_78_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_78_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_78_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_78_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_78_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_78_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_78_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_78_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_78_ADDRESS                                0x0538
#define BB_TPC_TXGAIN_SRAM_78_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_78_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_78_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_78_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_78_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_78_RESET                                  0x00000000

// 0x053c (BB_TPC_TXGAIN_SRAM_79)
#define BB_TPC_TXGAIN_SRAM_79_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_79_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_79_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_79_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_79_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_79_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_79_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_79_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_79_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_79_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_79_ADDRESS                                0x053c
#define BB_TPC_TXGAIN_SRAM_79_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_79_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_79_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_79_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_79_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_79_RESET                                  0x00000000

// 0x0540 (BB_TPC_TXGAIN_SRAM_80)
#define BB_TPC_TXGAIN_SRAM_80_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_80_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_80_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_80_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_80_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_80_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_80_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_80_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_80_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_80_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_80_ADDRESS                                0x0540
#define BB_TPC_TXGAIN_SRAM_80_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_80_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_80_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_80_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_80_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_80_RESET                                  0x00000000

// 0x0544 (BB_TPC_TXGAIN_SRAM_81)
#define BB_TPC_TXGAIN_SRAM_81_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_81_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_81_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_81_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_81_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_81_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_81_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_81_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_81_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_81_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_81_ADDRESS                                0x0544
#define BB_TPC_TXGAIN_SRAM_81_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_81_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_81_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_81_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_81_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_81_RESET                                  0x00000000

// 0x0548 (BB_TPC_TXGAIN_SRAM_82)
#define BB_TPC_TXGAIN_SRAM_82_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_82_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_82_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_82_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_82_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_82_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_82_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_82_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_82_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_82_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_82_ADDRESS                                0x0548
#define BB_TPC_TXGAIN_SRAM_82_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_82_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_82_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_82_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_82_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_82_RESET                                  0x00000000

// 0x054c (BB_TPC_TXGAIN_SRAM_83)
#define BB_TPC_TXGAIN_SRAM_83_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_83_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_83_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_83_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_83_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_83_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_83_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_83_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_83_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_83_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_83_ADDRESS                                0x054c
#define BB_TPC_TXGAIN_SRAM_83_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_83_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_83_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_83_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_83_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_83_RESET                                  0x00000000

// 0x0550 (BB_TPC_TXGAIN_SRAM_84)
#define BB_TPC_TXGAIN_SRAM_84_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_84_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_84_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_84_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_84_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_84_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_84_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_84_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_84_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_84_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_84_ADDRESS                                0x0550
#define BB_TPC_TXGAIN_SRAM_84_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_84_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_84_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_84_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_84_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_84_RESET                                  0x00000000

// 0x0554 (BB_TPC_TXGAIN_SRAM_85)
#define BB_TPC_TXGAIN_SRAM_85_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_85_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_85_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_85_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_85_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_85_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_85_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_85_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_85_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_85_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_85_ADDRESS                                0x0554
#define BB_TPC_TXGAIN_SRAM_85_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_85_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_85_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_85_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_85_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_85_RESET                                  0x00000000

// 0x0558 (BB_TPC_TXGAIN_SRAM_86)
#define BB_TPC_TXGAIN_SRAM_86_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_86_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_86_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_86_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_86_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_86_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_86_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_86_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_86_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_86_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_86_ADDRESS                                0x0558
#define BB_TPC_TXGAIN_SRAM_86_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_86_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_86_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_86_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_86_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_86_RESET                                  0x00000000

// 0x055c (BB_TPC_TXGAIN_SRAM_87)
#define BB_TPC_TXGAIN_SRAM_87_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_87_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_87_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_87_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_87_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_87_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_87_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_87_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_87_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_87_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_87_ADDRESS                                0x055c
#define BB_TPC_TXGAIN_SRAM_87_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_87_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_87_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_87_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_87_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_87_RESET                                  0x00000000

// 0x0560 (BB_TPC_TXGAIN_SRAM_88)
#define BB_TPC_TXGAIN_SRAM_88_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_88_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_88_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_88_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_88_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_88_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_88_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_88_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_88_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_88_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_88_ADDRESS                                0x0560
#define BB_TPC_TXGAIN_SRAM_88_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_88_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_88_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_88_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_88_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_88_RESET                                  0x00000000

// 0x0564 (BB_TPC_TXGAIN_SRAM_89)
#define BB_TPC_TXGAIN_SRAM_89_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_89_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_89_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_89_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_89_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_89_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_89_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_89_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_89_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_89_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_89_ADDRESS                                0x0564
#define BB_TPC_TXGAIN_SRAM_89_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_89_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_89_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_89_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_89_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_89_RESET                                  0x00000000

// 0x0568 (BB_TPC_TXGAIN_SRAM_90)
#define BB_TPC_TXGAIN_SRAM_90_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_90_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_90_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_90_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_90_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_90_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_90_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_90_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_90_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_90_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_90_ADDRESS                                0x0568
#define BB_TPC_TXGAIN_SRAM_90_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_90_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_90_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_90_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_90_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_90_RESET                                  0x00000000

// 0x056c (BB_TPC_TXGAIN_SRAM_91)
#define BB_TPC_TXGAIN_SRAM_91_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_91_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_91_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_91_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_91_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_91_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_91_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_91_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_91_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_91_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_91_ADDRESS                                0x056c
#define BB_TPC_TXGAIN_SRAM_91_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_91_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_91_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_91_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_91_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_91_RESET                                  0x00000000

// 0x0570 (BB_TPC_TXGAIN_SRAM_92)
#define BB_TPC_TXGAIN_SRAM_92_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_92_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_92_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_92_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_92_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_92_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_92_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_92_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_92_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_92_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_92_ADDRESS                                0x0570
#define BB_TPC_TXGAIN_SRAM_92_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_92_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_92_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_92_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_92_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_92_RESET                                  0x00000000

// 0x0574 (BB_TPC_TXGAIN_SRAM_93)
#define BB_TPC_TXGAIN_SRAM_93_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_93_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_93_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_93_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_93_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_93_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_93_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_93_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_93_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_93_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_93_ADDRESS                                0x0574
#define BB_TPC_TXGAIN_SRAM_93_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_93_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_93_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_93_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_93_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_93_RESET                                  0x00000000

// 0x0578 (BB_TPC_TXGAIN_SRAM_94)
#define BB_TPC_TXGAIN_SRAM_94_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_94_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_94_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_94_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_94_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_94_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_94_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_94_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_94_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_94_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_94_ADDRESS                                0x0578
#define BB_TPC_TXGAIN_SRAM_94_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_94_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_94_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_94_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_94_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_94_RESET                                  0x00000000

// 0x057c (BB_TPC_TXGAIN_SRAM_95)
#define BB_TPC_TXGAIN_SRAM_95_TPC_TXGAIN_WORD_MSB                    31
#define BB_TPC_TXGAIN_SRAM_95_TPC_TXGAIN_WORD_LSB                    0
#define BB_TPC_TXGAIN_SRAM_95_TPC_TXGAIN_WORD_MASK                   0xffffffff
#define BB_TPC_TXGAIN_SRAM_95_TPC_TXGAIN_WORD_GET(x)                 (((x) & BB_TPC_TXGAIN_SRAM_95_TPC_TXGAIN_WORD_MASK) >> BB_TPC_TXGAIN_SRAM_95_TPC_TXGAIN_WORD_LSB)
#define BB_TPC_TXGAIN_SRAM_95_TPC_TXGAIN_WORD_SET(x)                 (((0 | (x)) << BB_TPC_TXGAIN_SRAM_95_TPC_TXGAIN_WORD_LSB) & BB_TPC_TXGAIN_SRAM_95_TPC_TXGAIN_WORD_MASK)
#define BB_TPC_TXGAIN_SRAM_95_TPC_TXGAIN_WORD_RESET                  0
#define BB_TPC_TXGAIN_SRAM_95_ADDRESS                                0x057c
#define BB_TPC_TXGAIN_SRAM_95_HW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_95_SW_MASK                                0xffffffff
#define BB_TPC_TXGAIN_SRAM_95_HW_WRITE_MASK                          0x00000000
#define BB_TPC_TXGAIN_SRAM_95_SW_WRITE_MASK                          0xffffffff
#define BB_TPC_TXGAIN_SRAM_95_RSTMASK                                0x00000000
#define BB_TPC_TXGAIN_SRAM_95_RESET                                  0x00000000

// 0x0580 (BB_TPC_PLUT_SRAM_0)
#define BB_TPC_PLUT_SRAM_0_TPC_PLUT_WORD_MSB                         31
#define BB_TPC_PLUT_SRAM_0_TPC_PLUT_WORD_LSB                         0
#define BB_TPC_PLUT_SRAM_0_TPC_PLUT_WORD_MASK                        0xffffffff
#define BB_TPC_PLUT_SRAM_0_TPC_PLUT_WORD_GET(x)                      (((x) & BB_TPC_PLUT_SRAM_0_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_0_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_0_TPC_PLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_PLUT_SRAM_0_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_0_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_0_TPC_PLUT_WORD_RESET                       0
#define BB_TPC_PLUT_SRAM_0_ADDRESS                                   0x0580
#define BB_TPC_PLUT_SRAM_ADDRESS                                     BB_TPC_PLUT_SRAM_0_ADDRESS
#define BB_TPC_PLUT_SRAM_0_HW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_0_SW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_0_HW_WRITE_MASK                             0x00000000
#define BB_TPC_PLUT_SRAM_0_SW_WRITE_MASK                             0xffffffff
#define BB_TPC_PLUT_SRAM_0_RSTMASK                                   0x00000000
#define BB_TPC_PLUT_SRAM_0_RESET                                     0x00000000

// 0x0584 (BB_TPC_PLUT_SRAM_1)
#define BB_TPC_PLUT_SRAM_1_TPC_PLUT_WORD_MSB                         31
#define BB_TPC_PLUT_SRAM_1_TPC_PLUT_WORD_LSB                         0
#define BB_TPC_PLUT_SRAM_1_TPC_PLUT_WORD_MASK                        0xffffffff
#define BB_TPC_PLUT_SRAM_1_TPC_PLUT_WORD_GET(x)                      (((x) & BB_TPC_PLUT_SRAM_1_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_1_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_1_TPC_PLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_PLUT_SRAM_1_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_1_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_1_TPC_PLUT_WORD_RESET                       0
#define BB_TPC_PLUT_SRAM_1_ADDRESS                                   0x0584
#define BB_TPC_PLUT_SRAM_1_HW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_1_SW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_1_HW_WRITE_MASK                             0x00000000
#define BB_TPC_PLUT_SRAM_1_SW_WRITE_MASK                             0xffffffff
#define BB_TPC_PLUT_SRAM_1_RSTMASK                                   0x00000000
#define BB_TPC_PLUT_SRAM_1_RESET                                     0x00000000

// 0x0588 (BB_TPC_PLUT_SRAM_2)
#define BB_TPC_PLUT_SRAM_2_TPC_PLUT_WORD_MSB                         31
#define BB_TPC_PLUT_SRAM_2_TPC_PLUT_WORD_LSB                         0
#define BB_TPC_PLUT_SRAM_2_TPC_PLUT_WORD_MASK                        0xffffffff
#define BB_TPC_PLUT_SRAM_2_TPC_PLUT_WORD_GET(x)                      (((x) & BB_TPC_PLUT_SRAM_2_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_2_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_2_TPC_PLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_PLUT_SRAM_2_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_2_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_2_TPC_PLUT_WORD_RESET                       0
#define BB_TPC_PLUT_SRAM_2_ADDRESS                                   0x0588
#define BB_TPC_PLUT_SRAM_2_HW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_2_SW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_2_HW_WRITE_MASK                             0x00000000
#define BB_TPC_PLUT_SRAM_2_SW_WRITE_MASK                             0xffffffff
#define BB_TPC_PLUT_SRAM_2_RSTMASK                                   0x00000000
#define BB_TPC_PLUT_SRAM_2_RESET                                     0x00000000

// 0x058c (BB_TPC_PLUT_SRAM_3)
#define BB_TPC_PLUT_SRAM_3_TPC_PLUT_WORD_MSB                         31
#define BB_TPC_PLUT_SRAM_3_TPC_PLUT_WORD_LSB                         0
#define BB_TPC_PLUT_SRAM_3_TPC_PLUT_WORD_MASK                        0xffffffff
#define BB_TPC_PLUT_SRAM_3_TPC_PLUT_WORD_GET(x)                      (((x) & BB_TPC_PLUT_SRAM_3_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_3_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_3_TPC_PLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_PLUT_SRAM_3_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_3_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_3_TPC_PLUT_WORD_RESET                       0
#define BB_TPC_PLUT_SRAM_3_ADDRESS                                   0x058c
#define BB_TPC_PLUT_SRAM_3_HW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_3_SW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_3_HW_WRITE_MASK                             0x00000000
#define BB_TPC_PLUT_SRAM_3_SW_WRITE_MASK                             0xffffffff
#define BB_TPC_PLUT_SRAM_3_RSTMASK                                   0x00000000
#define BB_TPC_PLUT_SRAM_3_RESET                                     0x00000000

// 0x0590 (BB_TPC_PLUT_SRAM_4)
#define BB_TPC_PLUT_SRAM_4_TPC_PLUT_WORD_MSB                         31
#define BB_TPC_PLUT_SRAM_4_TPC_PLUT_WORD_LSB                         0
#define BB_TPC_PLUT_SRAM_4_TPC_PLUT_WORD_MASK                        0xffffffff
#define BB_TPC_PLUT_SRAM_4_TPC_PLUT_WORD_GET(x)                      (((x) & BB_TPC_PLUT_SRAM_4_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_4_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_4_TPC_PLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_PLUT_SRAM_4_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_4_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_4_TPC_PLUT_WORD_RESET                       0
#define BB_TPC_PLUT_SRAM_4_ADDRESS                                   0x0590
#define BB_TPC_PLUT_SRAM_4_HW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_4_SW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_4_HW_WRITE_MASK                             0x00000000
#define BB_TPC_PLUT_SRAM_4_SW_WRITE_MASK                             0xffffffff
#define BB_TPC_PLUT_SRAM_4_RSTMASK                                   0x00000000
#define BB_TPC_PLUT_SRAM_4_RESET                                     0x00000000

// 0x0594 (BB_TPC_PLUT_SRAM_5)
#define BB_TPC_PLUT_SRAM_5_TPC_PLUT_WORD_MSB                         31
#define BB_TPC_PLUT_SRAM_5_TPC_PLUT_WORD_LSB                         0
#define BB_TPC_PLUT_SRAM_5_TPC_PLUT_WORD_MASK                        0xffffffff
#define BB_TPC_PLUT_SRAM_5_TPC_PLUT_WORD_GET(x)                      (((x) & BB_TPC_PLUT_SRAM_5_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_5_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_5_TPC_PLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_PLUT_SRAM_5_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_5_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_5_TPC_PLUT_WORD_RESET                       0
#define BB_TPC_PLUT_SRAM_5_ADDRESS                                   0x0594
#define BB_TPC_PLUT_SRAM_5_HW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_5_SW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_5_HW_WRITE_MASK                             0x00000000
#define BB_TPC_PLUT_SRAM_5_SW_WRITE_MASK                             0xffffffff
#define BB_TPC_PLUT_SRAM_5_RSTMASK                                   0x00000000
#define BB_TPC_PLUT_SRAM_5_RESET                                     0x00000000

// 0x0598 (BB_TPC_PLUT_SRAM_6)
#define BB_TPC_PLUT_SRAM_6_TPC_PLUT_WORD_MSB                         31
#define BB_TPC_PLUT_SRAM_6_TPC_PLUT_WORD_LSB                         0
#define BB_TPC_PLUT_SRAM_6_TPC_PLUT_WORD_MASK                        0xffffffff
#define BB_TPC_PLUT_SRAM_6_TPC_PLUT_WORD_GET(x)                      (((x) & BB_TPC_PLUT_SRAM_6_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_6_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_6_TPC_PLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_PLUT_SRAM_6_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_6_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_6_TPC_PLUT_WORD_RESET                       0
#define BB_TPC_PLUT_SRAM_6_ADDRESS                                   0x0598
#define BB_TPC_PLUT_SRAM_6_HW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_6_SW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_6_HW_WRITE_MASK                             0x00000000
#define BB_TPC_PLUT_SRAM_6_SW_WRITE_MASK                             0xffffffff
#define BB_TPC_PLUT_SRAM_6_RSTMASK                                   0x00000000
#define BB_TPC_PLUT_SRAM_6_RESET                                     0x00000000

// 0x059c (BB_TPC_PLUT_SRAM_7)
#define BB_TPC_PLUT_SRAM_7_TPC_PLUT_WORD_MSB                         31
#define BB_TPC_PLUT_SRAM_7_TPC_PLUT_WORD_LSB                         0
#define BB_TPC_PLUT_SRAM_7_TPC_PLUT_WORD_MASK                        0xffffffff
#define BB_TPC_PLUT_SRAM_7_TPC_PLUT_WORD_GET(x)                      (((x) & BB_TPC_PLUT_SRAM_7_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_7_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_7_TPC_PLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_PLUT_SRAM_7_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_7_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_7_TPC_PLUT_WORD_RESET                       0
#define BB_TPC_PLUT_SRAM_7_ADDRESS                                   0x059c
#define BB_TPC_PLUT_SRAM_7_HW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_7_SW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_7_HW_WRITE_MASK                             0x00000000
#define BB_TPC_PLUT_SRAM_7_SW_WRITE_MASK                             0xffffffff
#define BB_TPC_PLUT_SRAM_7_RSTMASK                                   0x00000000
#define BB_TPC_PLUT_SRAM_7_RESET                                     0x00000000

// 0x05a0 (BB_TPC_PLUT_SRAM_8)
#define BB_TPC_PLUT_SRAM_8_TPC_PLUT_WORD_MSB                         31
#define BB_TPC_PLUT_SRAM_8_TPC_PLUT_WORD_LSB                         0
#define BB_TPC_PLUT_SRAM_8_TPC_PLUT_WORD_MASK                        0xffffffff
#define BB_TPC_PLUT_SRAM_8_TPC_PLUT_WORD_GET(x)                      (((x) & BB_TPC_PLUT_SRAM_8_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_8_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_8_TPC_PLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_PLUT_SRAM_8_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_8_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_8_TPC_PLUT_WORD_RESET                       0
#define BB_TPC_PLUT_SRAM_8_ADDRESS                                   0x05a0
#define BB_TPC_PLUT_SRAM_8_HW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_8_SW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_8_HW_WRITE_MASK                             0x00000000
#define BB_TPC_PLUT_SRAM_8_SW_WRITE_MASK                             0xffffffff
#define BB_TPC_PLUT_SRAM_8_RSTMASK                                   0x00000000
#define BB_TPC_PLUT_SRAM_8_RESET                                     0x00000000

// 0x05a4 (BB_TPC_PLUT_SRAM_9)
#define BB_TPC_PLUT_SRAM_9_TPC_PLUT_WORD_MSB                         31
#define BB_TPC_PLUT_SRAM_9_TPC_PLUT_WORD_LSB                         0
#define BB_TPC_PLUT_SRAM_9_TPC_PLUT_WORD_MASK                        0xffffffff
#define BB_TPC_PLUT_SRAM_9_TPC_PLUT_WORD_GET(x)                      (((x) & BB_TPC_PLUT_SRAM_9_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_9_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_9_TPC_PLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_PLUT_SRAM_9_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_9_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_9_TPC_PLUT_WORD_RESET                       0
#define BB_TPC_PLUT_SRAM_9_ADDRESS                                   0x05a4
#define BB_TPC_PLUT_SRAM_9_HW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_9_SW_MASK                                   0xffffffff
#define BB_TPC_PLUT_SRAM_9_HW_WRITE_MASK                             0x00000000
#define BB_TPC_PLUT_SRAM_9_SW_WRITE_MASK                             0xffffffff
#define BB_TPC_PLUT_SRAM_9_RSTMASK                                   0x00000000
#define BB_TPC_PLUT_SRAM_9_RESET                                     0x00000000

// 0x05a8 (BB_TPC_PLUT_SRAM_10)
#define BB_TPC_PLUT_SRAM_10_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_10_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_10_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_10_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_10_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_10_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_10_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_10_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_10_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_10_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_10_ADDRESS                                  0x05a8
#define BB_TPC_PLUT_SRAM_10_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_10_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_10_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_10_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_10_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_10_RESET                                    0x00000000

// 0x05ac (BB_TPC_PLUT_SRAM_11)
#define BB_TPC_PLUT_SRAM_11_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_11_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_11_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_11_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_11_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_11_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_11_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_11_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_11_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_11_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_11_ADDRESS                                  0x05ac
#define BB_TPC_PLUT_SRAM_11_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_11_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_11_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_11_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_11_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_11_RESET                                    0x00000000

// 0x05b0 (BB_TPC_PLUT_SRAM_12)
#define BB_TPC_PLUT_SRAM_12_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_12_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_12_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_12_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_12_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_12_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_12_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_12_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_12_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_12_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_12_ADDRESS                                  0x05b0
#define BB_TPC_PLUT_SRAM_12_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_12_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_12_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_12_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_12_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_12_RESET                                    0x00000000

// 0x05b4 (BB_TPC_PLUT_SRAM_13)
#define BB_TPC_PLUT_SRAM_13_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_13_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_13_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_13_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_13_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_13_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_13_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_13_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_13_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_13_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_13_ADDRESS                                  0x05b4
#define BB_TPC_PLUT_SRAM_13_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_13_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_13_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_13_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_13_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_13_RESET                                    0x00000000

// 0x05b8 (BB_TPC_PLUT_SRAM_14)
#define BB_TPC_PLUT_SRAM_14_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_14_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_14_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_14_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_14_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_14_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_14_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_14_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_14_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_14_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_14_ADDRESS                                  0x05b8
#define BB_TPC_PLUT_SRAM_14_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_14_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_14_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_14_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_14_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_14_RESET                                    0x00000000

// 0x05bc (BB_TPC_PLUT_SRAM_15)
#define BB_TPC_PLUT_SRAM_15_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_15_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_15_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_15_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_15_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_15_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_15_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_15_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_15_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_15_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_15_ADDRESS                                  0x05bc
#define BB_TPC_PLUT_SRAM_15_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_15_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_15_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_15_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_15_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_15_RESET                                    0x00000000

// 0x05c0 (BB_TPC_PLUT_SRAM_16)
#define BB_TPC_PLUT_SRAM_16_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_16_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_16_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_16_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_16_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_16_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_16_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_16_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_16_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_16_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_16_ADDRESS                                  0x05c0
#define BB_TPC_PLUT_SRAM_16_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_16_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_16_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_16_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_16_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_16_RESET                                    0x00000000

// 0x05c4 (BB_TPC_PLUT_SRAM_17)
#define BB_TPC_PLUT_SRAM_17_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_17_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_17_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_17_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_17_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_17_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_17_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_17_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_17_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_17_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_17_ADDRESS                                  0x05c4
#define BB_TPC_PLUT_SRAM_17_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_17_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_17_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_17_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_17_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_17_RESET                                    0x00000000

// 0x05c8 (BB_TPC_PLUT_SRAM_18)
#define BB_TPC_PLUT_SRAM_18_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_18_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_18_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_18_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_18_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_18_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_18_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_18_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_18_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_18_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_18_ADDRESS                                  0x05c8
#define BB_TPC_PLUT_SRAM_18_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_18_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_18_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_18_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_18_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_18_RESET                                    0x00000000

// 0x05cc (BB_TPC_PLUT_SRAM_19)
#define BB_TPC_PLUT_SRAM_19_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_19_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_19_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_19_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_19_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_19_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_19_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_19_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_19_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_19_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_19_ADDRESS                                  0x05cc
#define BB_TPC_PLUT_SRAM_19_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_19_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_19_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_19_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_19_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_19_RESET                                    0x00000000

// 0x05d0 (BB_TPC_PLUT_SRAM_20)
#define BB_TPC_PLUT_SRAM_20_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_20_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_20_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_20_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_20_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_20_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_20_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_20_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_20_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_20_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_20_ADDRESS                                  0x05d0
#define BB_TPC_PLUT_SRAM_20_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_20_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_20_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_20_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_20_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_20_RESET                                    0x00000000

// 0x05d4 (BB_TPC_PLUT_SRAM_21)
#define BB_TPC_PLUT_SRAM_21_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_21_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_21_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_21_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_21_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_21_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_21_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_21_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_21_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_21_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_21_ADDRESS                                  0x05d4
#define BB_TPC_PLUT_SRAM_21_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_21_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_21_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_21_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_21_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_21_RESET                                    0x00000000

// 0x05d8 (BB_TPC_PLUT_SRAM_22)
#define BB_TPC_PLUT_SRAM_22_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_22_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_22_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_22_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_22_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_22_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_22_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_22_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_22_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_22_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_22_ADDRESS                                  0x05d8
#define BB_TPC_PLUT_SRAM_22_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_22_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_22_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_22_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_22_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_22_RESET                                    0x00000000

// 0x05dc (BB_TPC_PLUT_SRAM_23)
#define BB_TPC_PLUT_SRAM_23_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_23_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_23_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_23_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_23_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_23_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_23_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_23_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_23_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_23_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_23_ADDRESS                                  0x05dc
#define BB_TPC_PLUT_SRAM_23_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_23_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_23_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_23_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_23_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_23_RESET                                    0x00000000

// 0x05e0 (BB_TPC_PLUT_SRAM_24)
#define BB_TPC_PLUT_SRAM_24_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_24_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_24_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_24_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_24_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_24_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_24_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_24_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_24_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_24_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_24_ADDRESS                                  0x05e0
#define BB_TPC_PLUT_SRAM_24_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_24_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_24_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_24_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_24_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_24_RESET                                    0x00000000

// 0x05e4 (BB_TPC_PLUT_SRAM_25)
#define BB_TPC_PLUT_SRAM_25_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_25_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_25_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_25_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_25_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_25_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_25_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_25_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_25_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_25_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_25_ADDRESS                                  0x05e4
#define BB_TPC_PLUT_SRAM_25_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_25_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_25_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_25_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_25_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_25_RESET                                    0x00000000

// 0x05e8 (BB_TPC_PLUT_SRAM_26)
#define BB_TPC_PLUT_SRAM_26_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_26_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_26_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_26_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_26_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_26_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_26_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_26_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_26_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_26_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_26_ADDRESS                                  0x05e8
#define BB_TPC_PLUT_SRAM_26_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_26_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_26_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_26_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_26_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_26_RESET                                    0x00000000

// 0x05ec (BB_TPC_PLUT_SRAM_27)
#define BB_TPC_PLUT_SRAM_27_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_27_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_27_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_27_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_27_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_27_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_27_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_27_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_27_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_27_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_27_ADDRESS                                  0x05ec
#define BB_TPC_PLUT_SRAM_27_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_27_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_27_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_27_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_27_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_27_RESET                                    0x00000000

// 0x05f0 (BB_TPC_PLUT_SRAM_28)
#define BB_TPC_PLUT_SRAM_28_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_28_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_28_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_28_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_28_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_28_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_28_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_28_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_28_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_28_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_28_ADDRESS                                  0x05f0
#define BB_TPC_PLUT_SRAM_28_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_28_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_28_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_28_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_28_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_28_RESET                                    0x00000000

// 0x05f4 (BB_TPC_PLUT_SRAM_29)
#define BB_TPC_PLUT_SRAM_29_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_29_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_29_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_29_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_29_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_29_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_29_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_29_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_29_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_29_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_29_ADDRESS                                  0x05f4
#define BB_TPC_PLUT_SRAM_29_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_29_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_29_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_29_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_29_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_29_RESET                                    0x00000000

// 0x05f8 (BB_TPC_PLUT_SRAM_30)
#define BB_TPC_PLUT_SRAM_30_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_30_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_30_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_30_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_30_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_30_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_30_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_30_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_30_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_30_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_30_ADDRESS                                  0x05f8
#define BB_TPC_PLUT_SRAM_30_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_30_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_30_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_30_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_30_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_30_RESET                                    0x00000000

// 0x05fc (BB_TPC_PLUT_SRAM_31)
#define BB_TPC_PLUT_SRAM_31_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_31_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_31_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_31_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_31_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_31_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_31_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_31_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_31_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_31_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_31_ADDRESS                                  0x05fc
#define BB_TPC_PLUT_SRAM_31_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_31_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_31_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_31_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_31_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_31_RESET                                    0x00000000

// 0x0600 (BB_TPC_PLUT_SRAM_32)
#define BB_TPC_PLUT_SRAM_32_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_32_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_32_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_32_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_32_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_32_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_32_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_32_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_32_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_32_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_32_ADDRESS                                  0x0600
#define BB_TPC_PLUT_SRAM_32_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_32_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_32_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_32_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_32_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_32_RESET                                    0x00000000

// 0x0604 (BB_TPC_PLUT_SRAM_33)
#define BB_TPC_PLUT_SRAM_33_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_33_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_33_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_33_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_33_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_33_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_33_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_33_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_33_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_33_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_33_ADDRESS                                  0x0604
#define BB_TPC_PLUT_SRAM_33_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_33_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_33_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_33_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_33_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_33_RESET                                    0x00000000

// 0x0608 (BB_TPC_PLUT_SRAM_34)
#define BB_TPC_PLUT_SRAM_34_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_34_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_34_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_34_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_34_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_34_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_34_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_34_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_34_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_34_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_34_ADDRESS                                  0x0608
#define BB_TPC_PLUT_SRAM_34_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_34_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_34_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_34_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_34_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_34_RESET                                    0x00000000

// 0x060c (BB_TPC_PLUT_SRAM_35)
#define BB_TPC_PLUT_SRAM_35_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_35_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_35_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_35_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_35_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_35_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_35_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_35_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_35_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_35_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_35_ADDRESS                                  0x060c
#define BB_TPC_PLUT_SRAM_35_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_35_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_35_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_35_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_35_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_35_RESET                                    0x00000000

// 0x0610 (BB_TPC_PLUT_SRAM_36)
#define BB_TPC_PLUT_SRAM_36_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_36_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_36_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_36_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_36_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_36_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_36_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_36_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_36_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_36_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_36_ADDRESS                                  0x0610
#define BB_TPC_PLUT_SRAM_36_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_36_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_36_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_36_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_36_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_36_RESET                                    0x00000000

// 0x0614 (BB_TPC_PLUT_SRAM_37)
#define BB_TPC_PLUT_SRAM_37_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_37_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_37_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_37_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_37_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_37_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_37_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_37_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_37_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_37_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_37_ADDRESS                                  0x0614
#define BB_TPC_PLUT_SRAM_37_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_37_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_37_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_37_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_37_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_37_RESET                                    0x00000000

// 0x0618 (BB_TPC_PLUT_SRAM_38)
#define BB_TPC_PLUT_SRAM_38_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_38_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_38_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_38_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_38_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_38_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_38_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_38_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_38_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_38_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_38_ADDRESS                                  0x0618
#define BB_TPC_PLUT_SRAM_38_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_38_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_38_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_38_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_38_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_38_RESET                                    0x00000000

// 0x061c (BB_TPC_PLUT_SRAM_39)
#define BB_TPC_PLUT_SRAM_39_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_39_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_39_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_39_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_39_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_39_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_39_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_39_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_39_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_39_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_39_ADDRESS                                  0x061c
#define BB_TPC_PLUT_SRAM_39_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_39_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_39_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_39_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_39_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_39_RESET                                    0x00000000

// 0x0620 (BB_TPC_PLUT_SRAM_40)
#define BB_TPC_PLUT_SRAM_40_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_40_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_40_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_40_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_40_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_40_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_40_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_40_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_40_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_40_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_40_ADDRESS                                  0x0620
#define BB_TPC_PLUT_SRAM_40_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_40_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_40_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_40_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_40_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_40_RESET                                    0x00000000

// 0x0624 (BB_TPC_PLUT_SRAM_41)
#define BB_TPC_PLUT_SRAM_41_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_41_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_41_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_41_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_41_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_41_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_41_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_41_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_41_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_41_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_41_ADDRESS                                  0x0624
#define BB_TPC_PLUT_SRAM_41_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_41_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_41_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_41_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_41_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_41_RESET                                    0x00000000

// 0x0628 (BB_TPC_PLUT_SRAM_42)
#define BB_TPC_PLUT_SRAM_42_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_42_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_42_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_42_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_42_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_42_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_42_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_42_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_42_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_42_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_42_ADDRESS                                  0x0628
#define BB_TPC_PLUT_SRAM_42_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_42_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_42_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_42_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_42_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_42_RESET                                    0x00000000

// 0x062c (BB_TPC_PLUT_SRAM_43)
#define BB_TPC_PLUT_SRAM_43_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_43_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_43_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_43_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_43_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_43_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_43_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_43_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_43_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_43_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_43_ADDRESS                                  0x062c
#define BB_TPC_PLUT_SRAM_43_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_43_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_43_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_43_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_43_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_43_RESET                                    0x00000000

// 0x0630 (BB_TPC_PLUT_SRAM_44)
#define BB_TPC_PLUT_SRAM_44_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_44_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_44_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_44_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_44_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_44_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_44_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_44_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_44_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_44_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_44_ADDRESS                                  0x0630
#define BB_TPC_PLUT_SRAM_44_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_44_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_44_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_44_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_44_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_44_RESET                                    0x00000000

// 0x0634 (BB_TPC_PLUT_SRAM_45)
#define BB_TPC_PLUT_SRAM_45_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_45_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_45_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_45_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_45_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_45_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_45_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_45_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_45_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_45_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_45_ADDRESS                                  0x0634
#define BB_TPC_PLUT_SRAM_45_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_45_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_45_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_45_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_45_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_45_RESET                                    0x00000000

// 0x0638 (BB_TPC_PLUT_SRAM_46)
#define BB_TPC_PLUT_SRAM_46_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_46_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_46_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_46_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_46_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_46_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_46_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_46_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_46_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_46_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_46_ADDRESS                                  0x0638
#define BB_TPC_PLUT_SRAM_46_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_46_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_46_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_46_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_46_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_46_RESET                                    0x00000000

// 0x063c (BB_TPC_PLUT_SRAM_47)
#define BB_TPC_PLUT_SRAM_47_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_47_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_47_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_47_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_47_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_47_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_47_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_47_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_47_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_47_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_47_ADDRESS                                  0x063c
#define BB_TPC_PLUT_SRAM_47_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_47_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_47_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_47_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_47_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_47_RESET                                    0x00000000

// 0x0640 (BB_TPC_PLUT_SRAM_48)
#define BB_TPC_PLUT_SRAM_48_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_48_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_48_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_48_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_48_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_48_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_48_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_48_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_48_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_48_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_48_ADDRESS                                  0x0640
#define BB_TPC_PLUT_SRAM_48_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_48_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_48_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_48_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_48_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_48_RESET                                    0x00000000

// 0x0644 (BB_TPC_PLUT_SRAM_49)
#define BB_TPC_PLUT_SRAM_49_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_49_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_49_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_49_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_49_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_49_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_49_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_49_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_49_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_49_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_49_ADDRESS                                  0x0644
#define BB_TPC_PLUT_SRAM_49_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_49_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_49_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_49_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_49_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_49_RESET                                    0x00000000

// 0x0648 (BB_TPC_PLUT_SRAM_50)
#define BB_TPC_PLUT_SRAM_50_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_50_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_50_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_50_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_50_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_50_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_50_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_50_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_50_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_50_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_50_ADDRESS                                  0x0648
#define BB_TPC_PLUT_SRAM_50_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_50_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_50_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_50_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_50_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_50_RESET                                    0x00000000

// 0x064c (BB_TPC_PLUT_SRAM_51)
#define BB_TPC_PLUT_SRAM_51_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_51_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_51_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_51_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_51_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_51_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_51_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_51_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_51_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_51_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_51_ADDRESS                                  0x064c
#define BB_TPC_PLUT_SRAM_51_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_51_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_51_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_51_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_51_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_51_RESET                                    0x00000000

// 0x0650 (BB_TPC_PLUT_SRAM_52)
#define BB_TPC_PLUT_SRAM_52_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_52_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_52_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_52_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_52_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_52_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_52_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_52_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_52_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_52_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_52_ADDRESS                                  0x0650
#define BB_TPC_PLUT_SRAM_52_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_52_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_52_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_52_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_52_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_52_RESET                                    0x00000000

// 0x0654 (BB_TPC_PLUT_SRAM_53)
#define BB_TPC_PLUT_SRAM_53_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_53_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_53_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_53_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_53_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_53_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_53_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_53_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_53_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_53_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_53_ADDRESS                                  0x0654
#define BB_TPC_PLUT_SRAM_53_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_53_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_53_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_53_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_53_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_53_RESET                                    0x00000000

// 0x0658 (BB_TPC_PLUT_SRAM_54)
#define BB_TPC_PLUT_SRAM_54_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_54_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_54_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_54_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_54_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_54_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_54_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_54_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_54_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_54_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_54_ADDRESS                                  0x0658
#define BB_TPC_PLUT_SRAM_54_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_54_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_54_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_54_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_54_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_54_RESET                                    0x00000000

// 0x065c (BB_TPC_PLUT_SRAM_55)
#define BB_TPC_PLUT_SRAM_55_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_55_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_55_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_55_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_55_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_55_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_55_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_55_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_55_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_55_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_55_ADDRESS                                  0x065c
#define BB_TPC_PLUT_SRAM_55_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_55_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_55_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_55_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_55_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_55_RESET                                    0x00000000

// 0x0660 (BB_TPC_PLUT_SRAM_56)
#define BB_TPC_PLUT_SRAM_56_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_56_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_56_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_56_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_56_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_56_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_56_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_56_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_56_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_56_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_56_ADDRESS                                  0x0660
#define BB_TPC_PLUT_SRAM_56_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_56_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_56_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_56_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_56_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_56_RESET                                    0x00000000

// 0x0664 (BB_TPC_PLUT_SRAM_57)
#define BB_TPC_PLUT_SRAM_57_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_57_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_57_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_57_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_57_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_57_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_57_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_57_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_57_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_57_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_57_ADDRESS                                  0x0664
#define BB_TPC_PLUT_SRAM_57_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_57_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_57_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_57_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_57_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_57_RESET                                    0x00000000

// 0x0668 (BB_TPC_PLUT_SRAM_58)
#define BB_TPC_PLUT_SRAM_58_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_58_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_58_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_58_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_58_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_58_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_58_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_58_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_58_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_58_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_58_ADDRESS                                  0x0668
#define BB_TPC_PLUT_SRAM_58_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_58_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_58_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_58_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_58_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_58_RESET                                    0x00000000

// 0x066c (BB_TPC_PLUT_SRAM_59)
#define BB_TPC_PLUT_SRAM_59_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_59_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_59_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_59_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_59_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_59_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_59_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_59_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_59_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_59_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_59_ADDRESS                                  0x066c
#define BB_TPC_PLUT_SRAM_59_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_59_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_59_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_59_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_59_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_59_RESET                                    0x00000000

// 0x0670 (BB_TPC_PLUT_SRAM_60)
#define BB_TPC_PLUT_SRAM_60_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_60_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_60_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_60_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_60_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_60_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_60_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_60_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_60_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_60_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_60_ADDRESS                                  0x0670
#define BB_TPC_PLUT_SRAM_60_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_60_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_60_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_60_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_60_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_60_RESET                                    0x00000000

// 0x0674 (BB_TPC_PLUT_SRAM_61)
#define BB_TPC_PLUT_SRAM_61_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_61_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_61_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_61_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_61_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_61_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_61_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_61_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_61_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_61_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_61_ADDRESS                                  0x0674
#define BB_TPC_PLUT_SRAM_61_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_61_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_61_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_61_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_61_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_61_RESET                                    0x00000000

// 0x0678 (BB_TPC_PLUT_SRAM_62)
#define BB_TPC_PLUT_SRAM_62_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_62_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_62_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_62_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_62_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_62_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_62_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_62_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_62_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_62_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_62_ADDRESS                                  0x0678
#define BB_TPC_PLUT_SRAM_62_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_62_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_62_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_62_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_62_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_62_RESET                                    0x00000000

// 0x067c (BB_TPC_PLUT_SRAM_63)
#define BB_TPC_PLUT_SRAM_63_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_63_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_63_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_63_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_63_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_63_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_63_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_63_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_63_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_63_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_63_ADDRESS                                  0x067c
#define BB_TPC_PLUT_SRAM_63_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_63_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_63_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_63_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_63_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_63_RESET                                    0x00000000

// 0x0680 (BB_TPC_PLUT_SRAM_64)
#define BB_TPC_PLUT_SRAM_64_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_64_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_64_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_64_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_64_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_64_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_64_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_64_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_64_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_64_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_64_ADDRESS                                  0x0680
#define BB_TPC_PLUT_SRAM_64_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_64_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_64_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_64_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_64_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_64_RESET                                    0x00000000

// 0x0684 (BB_TPC_PLUT_SRAM_65)
#define BB_TPC_PLUT_SRAM_65_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_65_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_65_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_65_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_65_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_65_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_65_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_65_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_65_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_65_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_65_ADDRESS                                  0x0684
#define BB_TPC_PLUT_SRAM_65_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_65_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_65_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_65_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_65_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_65_RESET                                    0x00000000

// 0x0688 (BB_TPC_PLUT_SRAM_66)
#define BB_TPC_PLUT_SRAM_66_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_66_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_66_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_66_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_66_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_66_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_66_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_66_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_66_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_66_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_66_ADDRESS                                  0x0688
#define BB_TPC_PLUT_SRAM_66_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_66_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_66_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_66_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_66_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_66_RESET                                    0x00000000

// 0x068c (BB_TPC_PLUT_SRAM_67)
#define BB_TPC_PLUT_SRAM_67_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_67_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_67_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_67_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_67_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_67_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_67_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_67_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_67_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_67_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_67_ADDRESS                                  0x068c
#define BB_TPC_PLUT_SRAM_67_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_67_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_67_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_67_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_67_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_67_RESET                                    0x00000000

// 0x0690 (BB_TPC_PLUT_SRAM_68)
#define BB_TPC_PLUT_SRAM_68_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_68_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_68_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_68_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_68_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_68_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_68_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_68_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_68_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_68_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_68_ADDRESS                                  0x0690
#define BB_TPC_PLUT_SRAM_68_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_68_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_68_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_68_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_68_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_68_RESET                                    0x00000000

// 0x0694 (BB_TPC_PLUT_SRAM_69)
#define BB_TPC_PLUT_SRAM_69_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_69_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_69_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_69_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_69_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_69_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_69_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_69_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_69_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_69_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_69_ADDRESS                                  0x0694
#define BB_TPC_PLUT_SRAM_69_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_69_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_69_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_69_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_69_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_69_RESET                                    0x00000000

// 0x0698 (BB_TPC_PLUT_SRAM_70)
#define BB_TPC_PLUT_SRAM_70_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_70_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_70_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_70_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_70_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_70_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_70_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_70_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_70_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_70_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_70_ADDRESS                                  0x0698
#define BB_TPC_PLUT_SRAM_70_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_70_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_70_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_70_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_70_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_70_RESET                                    0x00000000

// 0x069c (BB_TPC_PLUT_SRAM_71)
#define BB_TPC_PLUT_SRAM_71_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_71_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_71_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_71_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_71_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_71_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_71_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_71_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_71_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_71_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_71_ADDRESS                                  0x069c
#define BB_TPC_PLUT_SRAM_71_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_71_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_71_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_71_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_71_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_71_RESET                                    0x00000000

// 0x06a0 (BB_TPC_PLUT_SRAM_72)
#define BB_TPC_PLUT_SRAM_72_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_72_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_72_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_72_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_72_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_72_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_72_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_72_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_72_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_72_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_72_ADDRESS                                  0x06a0
#define BB_TPC_PLUT_SRAM_72_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_72_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_72_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_72_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_72_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_72_RESET                                    0x00000000

// 0x06a4 (BB_TPC_PLUT_SRAM_73)
#define BB_TPC_PLUT_SRAM_73_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_73_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_73_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_73_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_73_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_73_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_73_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_73_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_73_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_73_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_73_ADDRESS                                  0x06a4
#define BB_TPC_PLUT_SRAM_73_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_73_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_73_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_73_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_73_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_73_RESET                                    0x00000000

// 0x06a8 (BB_TPC_PLUT_SRAM_74)
#define BB_TPC_PLUT_SRAM_74_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_74_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_74_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_74_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_74_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_74_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_74_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_74_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_74_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_74_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_74_ADDRESS                                  0x06a8
#define BB_TPC_PLUT_SRAM_74_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_74_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_74_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_74_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_74_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_74_RESET                                    0x00000000

// 0x06ac (BB_TPC_PLUT_SRAM_75)
#define BB_TPC_PLUT_SRAM_75_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_75_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_75_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_75_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_75_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_75_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_75_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_75_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_75_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_75_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_75_ADDRESS                                  0x06ac
#define BB_TPC_PLUT_SRAM_75_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_75_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_75_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_75_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_75_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_75_RESET                                    0x00000000

// 0x06b0 (BB_TPC_PLUT_SRAM_76)
#define BB_TPC_PLUT_SRAM_76_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_76_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_76_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_76_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_76_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_76_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_76_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_76_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_76_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_76_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_76_ADDRESS                                  0x06b0
#define BB_TPC_PLUT_SRAM_76_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_76_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_76_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_76_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_76_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_76_RESET                                    0x00000000

// 0x06b4 (BB_TPC_PLUT_SRAM_77)
#define BB_TPC_PLUT_SRAM_77_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_77_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_77_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_77_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_77_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_77_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_77_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_77_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_77_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_77_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_77_ADDRESS                                  0x06b4
#define BB_TPC_PLUT_SRAM_77_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_77_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_77_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_77_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_77_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_77_RESET                                    0x00000000

// 0x06b8 (BB_TPC_PLUT_SRAM_78)
#define BB_TPC_PLUT_SRAM_78_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_78_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_78_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_78_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_78_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_78_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_78_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_78_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_78_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_78_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_78_ADDRESS                                  0x06b8
#define BB_TPC_PLUT_SRAM_78_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_78_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_78_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_78_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_78_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_78_RESET                                    0x00000000

// 0x06bc (BB_TPC_PLUT_SRAM_79)
#define BB_TPC_PLUT_SRAM_79_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_79_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_79_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_79_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_79_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_79_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_79_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_79_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_79_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_79_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_79_ADDRESS                                  0x06bc
#define BB_TPC_PLUT_SRAM_79_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_79_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_79_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_79_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_79_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_79_RESET                                    0x00000000

// 0x06c0 (BB_TPC_PLUT_SRAM_80)
#define BB_TPC_PLUT_SRAM_80_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_80_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_80_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_80_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_80_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_80_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_80_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_80_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_80_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_80_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_80_ADDRESS                                  0x06c0
#define BB_TPC_PLUT_SRAM_80_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_80_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_80_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_80_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_80_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_80_RESET                                    0x00000000

// 0x06c4 (BB_TPC_PLUT_SRAM_81)
#define BB_TPC_PLUT_SRAM_81_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_81_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_81_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_81_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_81_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_81_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_81_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_81_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_81_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_81_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_81_ADDRESS                                  0x06c4
#define BB_TPC_PLUT_SRAM_81_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_81_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_81_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_81_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_81_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_81_RESET                                    0x00000000

// 0x06c8 (BB_TPC_PLUT_SRAM_82)
#define BB_TPC_PLUT_SRAM_82_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_82_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_82_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_82_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_82_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_82_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_82_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_82_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_82_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_82_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_82_ADDRESS                                  0x06c8
#define BB_TPC_PLUT_SRAM_82_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_82_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_82_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_82_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_82_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_82_RESET                                    0x00000000

// 0x06cc (BB_TPC_PLUT_SRAM_83)
#define BB_TPC_PLUT_SRAM_83_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_83_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_83_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_83_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_83_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_83_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_83_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_83_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_83_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_83_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_83_ADDRESS                                  0x06cc
#define BB_TPC_PLUT_SRAM_83_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_83_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_83_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_83_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_83_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_83_RESET                                    0x00000000

// 0x06d0 (BB_TPC_PLUT_SRAM_84)
#define BB_TPC_PLUT_SRAM_84_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_84_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_84_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_84_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_84_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_84_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_84_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_84_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_84_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_84_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_84_ADDRESS                                  0x06d0
#define BB_TPC_PLUT_SRAM_84_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_84_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_84_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_84_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_84_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_84_RESET                                    0x00000000

// 0x06d4 (BB_TPC_PLUT_SRAM_85)
#define BB_TPC_PLUT_SRAM_85_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_85_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_85_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_85_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_85_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_85_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_85_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_85_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_85_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_85_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_85_ADDRESS                                  0x06d4
#define BB_TPC_PLUT_SRAM_85_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_85_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_85_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_85_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_85_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_85_RESET                                    0x00000000

// 0x06d8 (BB_TPC_PLUT_SRAM_86)
#define BB_TPC_PLUT_SRAM_86_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_86_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_86_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_86_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_86_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_86_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_86_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_86_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_86_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_86_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_86_ADDRESS                                  0x06d8
#define BB_TPC_PLUT_SRAM_86_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_86_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_86_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_86_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_86_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_86_RESET                                    0x00000000

// 0x06dc (BB_TPC_PLUT_SRAM_87)
#define BB_TPC_PLUT_SRAM_87_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_87_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_87_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_87_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_87_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_87_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_87_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_87_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_87_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_87_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_87_ADDRESS                                  0x06dc
#define BB_TPC_PLUT_SRAM_87_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_87_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_87_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_87_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_87_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_87_RESET                                    0x00000000

// 0x06e0 (BB_TPC_PLUT_SRAM_88)
#define BB_TPC_PLUT_SRAM_88_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_88_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_88_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_88_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_88_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_88_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_88_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_88_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_88_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_88_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_88_ADDRESS                                  0x06e0
#define BB_TPC_PLUT_SRAM_88_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_88_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_88_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_88_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_88_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_88_RESET                                    0x00000000

// 0x06e4 (BB_TPC_PLUT_SRAM_89)
#define BB_TPC_PLUT_SRAM_89_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_89_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_89_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_89_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_89_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_89_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_89_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_89_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_89_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_89_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_89_ADDRESS                                  0x06e4
#define BB_TPC_PLUT_SRAM_89_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_89_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_89_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_89_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_89_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_89_RESET                                    0x00000000

// 0x06e8 (BB_TPC_PLUT_SRAM_90)
#define BB_TPC_PLUT_SRAM_90_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_90_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_90_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_90_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_90_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_90_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_90_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_90_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_90_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_90_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_90_ADDRESS                                  0x06e8
#define BB_TPC_PLUT_SRAM_90_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_90_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_90_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_90_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_90_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_90_RESET                                    0x00000000

// 0x06ec (BB_TPC_PLUT_SRAM_91)
#define BB_TPC_PLUT_SRAM_91_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_91_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_91_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_91_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_91_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_91_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_91_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_91_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_91_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_91_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_91_ADDRESS                                  0x06ec
#define BB_TPC_PLUT_SRAM_91_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_91_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_91_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_91_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_91_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_91_RESET                                    0x00000000

// 0x06f0 (BB_TPC_PLUT_SRAM_92)
#define BB_TPC_PLUT_SRAM_92_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_92_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_92_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_92_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_92_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_92_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_92_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_92_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_92_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_92_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_92_ADDRESS                                  0x06f0
#define BB_TPC_PLUT_SRAM_92_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_92_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_92_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_92_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_92_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_92_RESET                                    0x00000000

// 0x06f4 (BB_TPC_PLUT_SRAM_93)
#define BB_TPC_PLUT_SRAM_93_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_93_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_93_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_93_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_93_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_93_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_93_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_93_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_93_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_93_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_93_ADDRESS                                  0x06f4
#define BB_TPC_PLUT_SRAM_93_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_93_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_93_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_93_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_93_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_93_RESET                                    0x00000000

// 0x06f8 (BB_TPC_PLUT_SRAM_94)
#define BB_TPC_PLUT_SRAM_94_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_94_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_94_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_94_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_94_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_94_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_94_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_94_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_94_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_94_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_94_ADDRESS                                  0x06f8
#define BB_TPC_PLUT_SRAM_94_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_94_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_94_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_94_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_94_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_94_RESET                                    0x00000000

// 0x06fc (BB_TPC_PLUT_SRAM_95)
#define BB_TPC_PLUT_SRAM_95_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_95_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_95_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_95_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_95_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_95_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_95_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_95_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_95_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_95_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_95_ADDRESS                                  0x06fc
#define BB_TPC_PLUT_SRAM_95_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_95_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_95_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_95_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_95_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_95_RESET                                    0x00000000

// 0x0700 (BB_TPC_PLUT_SRAM_96)
#define BB_TPC_PLUT_SRAM_96_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_96_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_96_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_96_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_96_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_96_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_96_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_96_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_96_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_96_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_96_ADDRESS                                  0x0700
#define BB_TPC_PLUT_SRAM_96_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_96_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_96_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_96_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_96_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_96_RESET                                    0x00000000

// 0x0704 (BB_TPC_PLUT_SRAM_97)
#define BB_TPC_PLUT_SRAM_97_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_97_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_97_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_97_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_97_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_97_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_97_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_97_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_97_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_97_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_97_ADDRESS                                  0x0704
#define BB_TPC_PLUT_SRAM_97_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_97_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_97_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_97_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_97_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_97_RESET                                    0x00000000

// 0x0708 (BB_TPC_PLUT_SRAM_98)
#define BB_TPC_PLUT_SRAM_98_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_98_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_98_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_98_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_98_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_98_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_98_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_98_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_98_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_98_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_98_ADDRESS                                  0x0708
#define BB_TPC_PLUT_SRAM_98_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_98_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_98_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_98_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_98_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_98_RESET                                    0x00000000

// 0x070c (BB_TPC_PLUT_SRAM_99)
#define BB_TPC_PLUT_SRAM_99_TPC_PLUT_WORD_MSB                        31
#define BB_TPC_PLUT_SRAM_99_TPC_PLUT_WORD_LSB                        0
#define BB_TPC_PLUT_SRAM_99_TPC_PLUT_WORD_MASK                       0xffffffff
#define BB_TPC_PLUT_SRAM_99_TPC_PLUT_WORD_GET(x)                     (((x) & BB_TPC_PLUT_SRAM_99_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_99_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_99_TPC_PLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_PLUT_SRAM_99_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_99_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_99_TPC_PLUT_WORD_RESET                      0
#define BB_TPC_PLUT_SRAM_99_ADDRESS                                  0x070c
#define BB_TPC_PLUT_SRAM_99_HW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_99_SW_MASK                                  0xffffffff
#define BB_TPC_PLUT_SRAM_99_HW_WRITE_MASK                            0x00000000
#define BB_TPC_PLUT_SRAM_99_SW_WRITE_MASK                            0xffffffff
#define BB_TPC_PLUT_SRAM_99_RSTMASK                                  0x00000000
#define BB_TPC_PLUT_SRAM_99_RESET                                    0x00000000

// 0x0710 (BB_TPC_PLUT_SRAM_100)
#define BB_TPC_PLUT_SRAM_100_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_100_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_100_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_100_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_100_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_100_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_100_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_100_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_100_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_100_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_100_ADDRESS                                 0x0710
#define BB_TPC_PLUT_SRAM_100_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_100_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_100_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_100_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_100_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_100_RESET                                   0x00000000

// 0x0714 (BB_TPC_PLUT_SRAM_101)
#define BB_TPC_PLUT_SRAM_101_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_101_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_101_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_101_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_101_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_101_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_101_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_101_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_101_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_101_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_101_ADDRESS                                 0x0714
#define BB_TPC_PLUT_SRAM_101_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_101_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_101_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_101_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_101_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_101_RESET                                   0x00000000

// 0x0718 (BB_TPC_PLUT_SRAM_102)
#define BB_TPC_PLUT_SRAM_102_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_102_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_102_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_102_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_102_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_102_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_102_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_102_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_102_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_102_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_102_ADDRESS                                 0x0718
#define BB_TPC_PLUT_SRAM_102_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_102_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_102_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_102_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_102_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_102_RESET                                   0x00000000

// 0x071c (BB_TPC_PLUT_SRAM_103)
#define BB_TPC_PLUT_SRAM_103_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_103_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_103_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_103_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_103_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_103_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_103_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_103_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_103_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_103_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_103_ADDRESS                                 0x071c
#define BB_TPC_PLUT_SRAM_103_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_103_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_103_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_103_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_103_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_103_RESET                                   0x00000000

// 0x0720 (BB_TPC_PLUT_SRAM_104)
#define BB_TPC_PLUT_SRAM_104_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_104_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_104_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_104_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_104_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_104_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_104_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_104_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_104_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_104_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_104_ADDRESS                                 0x0720
#define BB_TPC_PLUT_SRAM_104_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_104_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_104_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_104_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_104_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_104_RESET                                   0x00000000

// 0x0724 (BB_TPC_PLUT_SRAM_105)
#define BB_TPC_PLUT_SRAM_105_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_105_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_105_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_105_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_105_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_105_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_105_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_105_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_105_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_105_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_105_ADDRESS                                 0x0724
#define BB_TPC_PLUT_SRAM_105_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_105_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_105_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_105_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_105_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_105_RESET                                   0x00000000

// 0x0728 (BB_TPC_PLUT_SRAM_106)
#define BB_TPC_PLUT_SRAM_106_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_106_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_106_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_106_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_106_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_106_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_106_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_106_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_106_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_106_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_106_ADDRESS                                 0x0728
#define BB_TPC_PLUT_SRAM_106_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_106_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_106_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_106_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_106_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_106_RESET                                   0x00000000

// 0x072c (BB_TPC_PLUT_SRAM_107)
#define BB_TPC_PLUT_SRAM_107_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_107_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_107_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_107_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_107_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_107_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_107_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_107_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_107_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_107_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_107_ADDRESS                                 0x072c
#define BB_TPC_PLUT_SRAM_107_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_107_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_107_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_107_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_107_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_107_RESET                                   0x00000000

// 0x0730 (BB_TPC_PLUT_SRAM_108)
#define BB_TPC_PLUT_SRAM_108_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_108_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_108_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_108_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_108_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_108_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_108_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_108_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_108_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_108_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_108_ADDRESS                                 0x0730
#define BB_TPC_PLUT_SRAM_108_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_108_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_108_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_108_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_108_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_108_RESET                                   0x00000000

// 0x0734 (BB_TPC_PLUT_SRAM_109)
#define BB_TPC_PLUT_SRAM_109_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_109_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_109_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_109_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_109_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_109_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_109_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_109_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_109_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_109_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_109_ADDRESS                                 0x0734
#define BB_TPC_PLUT_SRAM_109_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_109_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_109_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_109_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_109_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_109_RESET                                   0x00000000

// 0x0738 (BB_TPC_PLUT_SRAM_110)
#define BB_TPC_PLUT_SRAM_110_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_110_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_110_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_110_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_110_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_110_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_110_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_110_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_110_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_110_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_110_ADDRESS                                 0x0738
#define BB_TPC_PLUT_SRAM_110_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_110_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_110_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_110_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_110_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_110_RESET                                   0x00000000

// 0x073c (BB_TPC_PLUT_SRAM_111)
#define BB_TPC_PLUT_SRAM_111_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_111_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_111_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_111_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_111_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_111_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_111_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_111_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_111_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_111_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_111_ADDRESS                                 0x073c
#define BB_TPC_PLUT_SRAM_111_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_111_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_111_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_111_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_111_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_111_RESET                                   0x00000000

// 0x0740 (BB_TPC_PLUT_SRAM_112)
#define BB_TPC_PLUT_SRAM_112_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_112_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_112_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_112_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_112_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_112_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_112_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_112_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_112_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_112_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_112_ADDRESS                                 0x0740
#define BB_TPC_PLUT_SRAM_112_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_112_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_112_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_112_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_112_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_112_RESET                                   0x00000000

// 0x0744 (BB_TPC_PLUT_SRAM_113)
#define BB_TPC_PLUT_SRAM_113_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_113_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_113_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_113_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_113_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_113_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_113_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_113_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_113_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_113_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_113_ADDRESS                                 0x0744
#define BB_TPC_PLUT_SRAM_113_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_113_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_113_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_113_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_113_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_113_RESET                                   0x00000000

// 0x0748 (BB_TPC_PLUT_SRAM_114)
#define BB_TPC_PLUT_SRAM_114_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_114_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_114_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_114_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_114_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_114_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_114_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_114_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_114_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_114_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_114_ADDRESS                                 0x0748
#define BB_TPC_PLUT_SRAM_114_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_114_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_114_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_114_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_114_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_114_RESET                                   0x00000000

// 0x074c (BB_TPC_PLUT_SRAM_115)
#define BB_TPC_PLUT_SRAM_115_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_115_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_115_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_115_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_115_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_115_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_115_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_115_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_115_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_115_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_115_ADDRESS                                 0x074c
#define BB_TPC_PLUT_SRAM_115_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_115_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_115_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_115_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_115_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_115_RESET                                   0x00000000

// 0x0750 (BB_TPC_PLUT_SRAM_116)
#define BB_TPC_PLUT_SRAM_116_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_116_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_116_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_116_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_116_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_116_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_116_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_116_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_116_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_116_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_116_ADDRESS                                 0x0750
#define BB_TPC_PLUT_SRAM_116_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_116_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_116_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_116_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_116_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_116_RESET                                   0x00000000

// 0x0754 (BB_TPC_PLUT_SRAM_117)
#define BB_TPC_PLUT_SRAM_117_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_117_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_117_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_117_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_117_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_117_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_117_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_117_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_117_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_117_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_117_ADDRESS                                 0x0754
#define BB_TPC_PLUT_SRAM_117_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_117_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_117_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_117_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_117_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_117_RESET                                   0x00000000

// 0x0758 (BB_TPC_PLUT_SRAM_118)
#define BB_TPC_PLUT_SRAM_118_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_118_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_118_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_118_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_118_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_118_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_118_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_118_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_118_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_118_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_118_ADDRESS                                 0x0758
#define BB_TPC_PLUT_SRAM_118_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_118_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_118_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_118_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_118_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_118_RESET                                   0x00000000

// 0x075c (BB_TPC_PLUT_SRAM_119)
#define BB_TPC_PLUT_SRAM_119_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_119_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_119_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_119_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_119_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_119_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_119_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_119_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_119_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_119_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_119_ADDRESS                                 0x075c
#define BB_TPC_PLUT_SRAM_119_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_119_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_119_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_119_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_119_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_119_RESET                                   0x00000000

// 0x0760 (BB_TPC_PLUT_SRAM_120)
#define BB_TPC_PLUT_SRAM_120_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_120_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_120_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_120_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_120_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_120_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_120_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_120_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_120_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_120_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_120_ADDRESS                                 0x0760
#define BB_TPC_PLUT_SRAM_120_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_120_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_120_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_120_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_120_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_120_RESET                                   0x00000000

// 0x0764 (BB_TPC_PLUT_SRAM_121)
#define BB_TPC_PLUT_SRAM_121_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_121_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_121_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_121_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_121_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_121_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_121_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_121_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_121_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_121_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_121_ADDRESS                                 0x0764
#define BB_TPC_PLUT_SRAM_121_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_121_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_121_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_121_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_121_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_121_RESET                                   0x00000000

// 0x0768 (BB_TPC_PLUT_SRAM_122)
#define BB_TPC_PLUT_SRAM_122_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_122_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_122_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_122_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_122_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_122_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_122_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_122_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_122_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_122_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_122_ADDRESS                                 0x0768
#define BB_TPC_PLUT_SRAM_122_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_122_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_122_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_122_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_122_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_122_RESET                                   0x00000000

// 0x076c (BB_TPC_PLUT_SRAM_123)
#define BB_TPC_PLUT_SRAM_123_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_123_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_123_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_123_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_123_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_123_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_123_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_123_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_123_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_123_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_123_ADDRESS                                 0x076c
#define BB_TPC_PLUT_SRAM_123_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_123_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_123_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_123_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_123_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_123_RESET                                   0x00000000

// 0x0770 (BB_TPC_PLUT_SRAM_124)
#define BB_TPC_PLUT_SRAM_124_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_124_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_124_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_124_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_124_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_124_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_124_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_124_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_124_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_124_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_124_ADDRESS                                 0x0770
#define BB_TPC_PLUT_SRAM_124_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_124_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_124_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_124_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_124_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_124_RESET                                   0x00000000

// 0x0774 (BB_TPC_PLUT_SRAM_125)
#define BB_TPC_PLUT_SRAM_125_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_125_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_125_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_125_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_125_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_125_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_125_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_125_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_125_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_125_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_125_ADDRESS                                 0x0774
#define BB_TPC_PLUT_SRAM_125_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_125_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_125_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_125_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_125_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_125_RESET                                   0x00000000

// 0x0778 (BB_TPC_PLUT_SRAM_126)
#define BB_TPC_PLUT_SRAM_126_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_126_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_126_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_126_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_126_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_126_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_126_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_126_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_126_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_126_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_126_ADDRESS                                 0x0778
#define BB_TPC_PLUT_SRAM_126_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_126_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_126_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_126_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_126_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_126_RESET                                   0x00000000

// 0x077c (BB_TPC_PLUT_SRAM_127)
#define BB_TPC_PLUT_SRAM_127_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_127_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_127_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_127_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_127_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_127_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_127_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_127_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_127_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_127_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_127_ADDRESS                                 0x077c
#define BB_TPC_PLUT_SRAM_127_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_127_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_127_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_127_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_127_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_127_RESET                                   0x00000000

// 0x0780 (BB_TPC_PLUT_SRAM_128)
#define BB_TPC_PLUT_SRAM_128_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_128_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_128_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_128_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_128_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_128_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_128_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_128_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_128_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_128_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_128_ADDRESS                                 0x0780
#define BB_TPC_PLUT_SRAM_128_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_128_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_128_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_128_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_128_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_128_RESET                                   0x00000000

// 0x0784 (BB_TPC_PLUT_SRAM_129)
#define BB_TPC_PLUT_SRAM_129_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_129_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_129_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_129_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_129_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_129_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_129_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_129_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_129_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_129_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_129_ADDRESS                                 0x0784
#define BB_TPC_PLUT_SRAM_129_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_129_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_129_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_129_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_129_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_129_RESET                                   0x00000000

// 0x0788 (BB_TPC_PLUT_SRAM_130)
#define BB_TPC_PLUT_SRAM_130_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_130_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_130_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_130_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_130_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_130_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_130_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_130_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_130_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_130_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_130_ADDRESS                                 0x0788
#define BB_TPC_PLUT_SRAM_130_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_130_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_130_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_130_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_130_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_130_RESET                                   0x00000000

// 0x078c (BB_TPC_PLUT_SRAM_131)
#define BB_TPC_PLUT_SRAM_131_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_131_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_131_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_131_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_131_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_131_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_131_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_131_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_131_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_131_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_131_ADDRESS                                 0x078c
#define BB_TPC_PLUT_SRAM_131_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_131_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_131_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_131_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_131_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_131_RESET                                   0x00000000

// 0x0790 (BB_TPC_PLUT_SRAM_132)
#define BB_TPC_PLUT_SRAM_132_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_132_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_132_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_132_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_132_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_132_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_132_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_132_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_132_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_132_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_132_ADDRESS                                 0x0790
#define BB_TPC_PLUT_SRAM_132_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_132_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_132_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_132_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_132_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_132_RESET                                   0x00000000

// 0x0794 (BB_TPC_PLUT_SRAM_133)
#define BB_TPC_PLUT_SRAM_133_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_133_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_133_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_133_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_133_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_133_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_133_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_133_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_133_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_133_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_133_ADDRESS                                 0x0794
#define BB_TPC_PLUT_SRAM_133_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_133_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_133_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_133_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_133_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_133_RESET                                   0x00000000

// 0x0798 (BB_TPC_PLUT_SRAM_134)
#define BB_TPC_PLUT_SRAM_134_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_134_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_134_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_134_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_134_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_134_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_134_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_134_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_134_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_134_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_134_ADDRESS                                 0x0798
#define BB_TPC_PLUT_SRAM_134_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_134_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_134_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_134_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_134_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_134_RESET                                   0x00000000

// 0x079c (BB_TPC_PLUT_SRAM_135)
#define BB_TPC_PLUT_SRAM_135_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_135_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_135_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_135_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_135_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_135_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_135_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_135_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_135_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_135_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_135_ADDRESS                                 0x079c
#define BB_TPC_PLUT_SRAM_135_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_135_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_135_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_135_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_135_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_135_RESET                                   0x00000000

// 0x07a0 (BB_TPC_PLUT_SRAM_136)
#define BB_TPC_PLUT_SRAM_136_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_136_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_136_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_136_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_136_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_136_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_136_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_136_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_136_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_136_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_136_ADDRESS                                 0x07a0
#define BB_TPC_PLUT_SRAM_136_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_136_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_136_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_136_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_136_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_136_RESET                                   0x00000000

// 0x07a4 (BB_TPC_PLUT_SRAM_137)
#define BB_TPC_PLUT_SRAM_137_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_137_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_137_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_137_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_137_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_137_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_137_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_137_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_137_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_137_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_137_ADDRESS                                 0x07a4
#define BB_TPC_PLUT_SRAM_137_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_137_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_137_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_137_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_137_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_137_RESET                                   0x00000000

// 0x07a8 (BB_TPC_PLUT_SRAM_138)
#define BB_TPC_PLUT_SRAM_138_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_138_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_138_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_138_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_138_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_138_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_138_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_138_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_138_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_138_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_138_ADDRESS                                 0x07a8
#define BB_TPC_PLUT_SRAM_138_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_138_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_138_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_138_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_138_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_138_RESET                                   0x00000000

// 0x07ac (BB_TPC_PLUT_SRAM_139)
#define BB_TPC_PLUT_SRAM_139_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_139_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_139_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_139_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_139_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_139_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_139_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_139_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_139_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_139_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_139_ADDRESS                                 0x07ac
#define BB_TPC_PLUT_SRAM_139_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_139_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_139_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_139_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_139_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_139_RESET                                   0x00000000

// 0x07b0 (BB_TPC_PLUT_SRAM_140)
#define BB_TPC_PLUT_SRAM_140_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_140_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_140_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_140_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_140_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_140_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_140_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_140_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_140_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_140_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_140_ADDRESS                                 0x07b0
#define BB_TPC_PLUT_SRAM_140_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_140_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_140_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_140_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_140_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_140_RESET                                   0x00000000

// 0x07b4 (BB_TPC_PLUT_SRAM_141)
#define BB_TPC_PLUT_SRAM_141_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_141_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_141_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_141_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_141_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_141_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_141_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_141_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_141_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_141_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_141_ADDRESS                                 0x07b4
#define BB_TPC_PLUT_SRAM_141_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_141_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_141_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_141_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_141_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_141_RESET                                   0x00000000

// 0x07b8 (BB_TPC_PLUT_SRAM_142)
#define BB_TPC_PLUT_SRAM_142_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_142_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_142_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_142_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_142_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_142_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_142_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_142_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_142_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_142_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_142_ADDRESS                                 0x07b8
#define BB_TPC_PLUT_SRAM_142_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_142_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_142_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_142_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_142_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_142_RESET                                   0x00000000

// 0x07bc (BB_TPC_PLUT_SRAM_143)
#define BB_TPC_PLUT_SRAM_143_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_143_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_143_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_143_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_143_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_143_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_143_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_143_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_143_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_143_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_143_ADDRESS                                 0x07bc
#define BB_TPC_PLUT_SRAM_143_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_143_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_143_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_143_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_143_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_143_RESET                                   0x00000000

// 0x07c0 (BB_TPC_PLUT_SRAM_144)
#define BB_TPC_PLUT_SRAM_144_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_144_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_144_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_144_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_144_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_144_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_144_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_144_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_144_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_144_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_144_ADDRESS                                 0x07c0
#define BB_TPC_PLUT_SRAM_144_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_144_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_144_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_144_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_144_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_144_RESET                                   0x00000000

// 0x07c4 (BB_TPC_PLUT_SRAM_145)
#define BB_TPC_PLUT_SRAM_145_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_145_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_145_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_145_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_145_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_145_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_145_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_145_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_145_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_145_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_145_ADDRESS                                 0x07c4
#define BB_TPC_PLUT_SRAM_145_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_145_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_145_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_145_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_145_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_145_RESET                                   0x00000000

// 0x07c8 (BB_TPC_PLUT_SRAM_146)
#define BB_TPC_PLUT_SRAM_146_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_146_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_146_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_146_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_146_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_146_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_146_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_146_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_146_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_146_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_146_ADDRESS                                 0x07c8
#define BB_TPC_PLUT_SRAM_146_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_146_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_146_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_146_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_146_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_146_RESET                                   0x00000000

// 0x07cc (BB_TPC_PLUT_SRAM_147)
#define BB_TPC_PLUT_SRAM_147_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_147_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_147_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_147_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_147_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_147_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_147_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_147_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_147_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_147_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_147_ADDRESS                                 0x07cc
#define BB_TPC_PLUT_SRAM_147_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_147_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_147_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_147_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_147_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_147_RESET                                   0x00000000

// 0x07d0 (BB_TPC_PLUT_SRAM_148)
#define BB_TPC_PLUT_SRAM_148_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_148_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_148_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_148_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_148_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_148_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_148_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_148_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_148_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_148_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_148_ADDRESS                                 0x07d0
#define BB_TPC_PLUT_SRAM_148_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_148_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_148_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_148_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_148_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_148_RESET                                   0x00000000

// 0x07d4 (BB_TPC_PLUT_SRAM_149)
#define BB_TPC_PLUT_SRAM_149_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_149_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_149_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_149_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_149_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_149_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_149_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_149_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_149_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_149_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_149_ADDRESS                                 0x07d4
#define BB_TPC_PLUT_SRAM_149_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_149_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_149_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_149_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_149_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_149_RESET                                   0x00000000

// 0x07d8 (BB_TPC_PLUT_SRAM_150)
#define BB_TPC_PLUT_SRAM_150_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_150_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_150_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_150_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_150_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_150_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_150_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_150_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_150_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_150_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_150_ADDRESS                                 0x07d8
#define BB_TPC_PLUT_SRAM_150_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_150_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_150_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_150_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_150_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_150_RESET                                   0x00000000

// 0x07dc (BB_TPC_PLUT_SRAM_151)
#define BB_TPC_PLUT_SRAM_151_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_151_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_151_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_151_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_151_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_151_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_151_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_151_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_151_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_151_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_151_ADDRESS                                 0x07dc
#define BB_TPC_PLUT_SRAM_151_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_151_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_151_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_151_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_151_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_151_RESET                                   0x00000000

// 0x07e0 (BB_TPC_PLUT_SRAM_152)
#define BB_TPC_PLUT_SRAM_152_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_152_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_152_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_152_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_152_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_152_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_152_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_152_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_152_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_152_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_152_ADDRESS                                 0x07e0
#define BB_TPC_PLUT_SRAM_152_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_152_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_152_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_152_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_152_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_152_RESET                                   0x00000000

// 0x07e4 (BB_TPC_PLUT_SRAM_153)
#define BB_TPC_PLUT_SRAM_153_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_153_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_153_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_153_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_153_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_153_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_153_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_153_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_153_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_153_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_153_ADDRESS                                 0x07e4
#define BB_TPC_PLUT_SRAM_153_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_153_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_153_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_153_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_153_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_153_RESET                                   0x00000000

// 0x07e8 (BB_TPC_PLUT_SRAM_154)
#define BB_TPC_PLUT_SRAM_154_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_154_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_154_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_154_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_154_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_154_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_154_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_154_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_154_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_154_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_154_ADDRESS                                 0x07e8
#define BB_TPC_PLUT_SRAM_154_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_154_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_154_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_154_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_154_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_154_RESET                                   0x00000000

// 0x07ec (BB_TPC_PLUT_SRAM_155)
#define BB_TPC_PLUT_SRAM_155_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_155_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_155_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_155_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_155_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_155_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_155_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_155_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_155_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_155_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_155_ADDRESS                                 0x07ec
#define BB_TPC_PLUT_SRAM_155_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_155_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_155_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_155_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_155_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_155_RESET                                   0x00000000

// 0x07f0 (BB_TPC_PLUT_SRAM_156)
#define BB_TPC_PLUT_SRAM_156_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_156_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_156_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_156_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_156_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_156_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_156_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_156_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_156_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_156_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_156_ADDRESS                                 0x07f0
#define BB_TPC_PLUT_SRAM_156_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_156_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_156_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_156_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_156_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_156_RESET                                   0x00000000

// 0x07f4 (BB_TPC_PLUT_SRAM_157)
#define BB_TPC_PLUT_SRAM_157_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_157_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_157_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_157_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_157_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_157_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_157_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_157_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_157_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_157_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_157_ADDRESS                                 0x07f4
#define BB_TPC_PLUT_SRAM_157_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_157_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_157_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_157_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_157_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_157_RESET                                   0x00000000

// 0x07f8 (BB_TPC_PLUT_SRAM_158)
#define BB_TPC_PLUT_SRAM_158_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_158_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_158_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_158_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_158_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_158_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_158_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_158_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_158_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_158_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_158_ADDRESS                                 0x07f8
#define BB_TPC_PLUT_SRAM_158_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_158_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_158_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_158_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_158_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_158_RESET                                   0x00000000

// 0x07fc (BB_TPC_PLUT_SRAM_159)
#define BB_TPC_PLUT_SRAM_159_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_159_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_159_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_159_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_159_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_159_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_159_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_159_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_159_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_159_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_159_ADDRESS                                 0x07fc
#define BB_TPC_PLUT_SRAM_159_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_159_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_159_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_159_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_159_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_159_RESET                                   0x00000000

// 0x0800 (BB_TPC_PLUT_SRAM_160)
#define BB_TPC_PLUT_SRAM_160_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_160_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_160_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_160_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_160_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_160_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_160_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_160_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_160_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_160_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_160_ADDRESS                                 0x0800
#define BB_TPC_PLUT_SRAM_160_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_160_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_160_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_160_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_160_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_160_RESET                                   0x00000000

// 0x0804 (BB_TPC_PLUT_SRAM_161)
#define BB_TPC_PLUT_SRAM_161_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_161_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_161_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_161_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_161_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_161_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_161_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_161_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_161_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_161_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_161_ADDRESS                                 0x0804
#define BB_TPC_PLUT_SRAM_161_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_161_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_161_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_161_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_161_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_161_RESET                                   0x00000000

// 0x0808 (BB_TPC_PLUT_SRAM_162)
#define BB_TPC_PLUT_SRAM_162_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_162_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_162_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_162_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_162_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_162_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_162_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_162_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_162_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_162_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_162_ADDRESS                                 0x0808
#define BB_TPC_PLUT_SRAM_162_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_162_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_162_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_162_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_162_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_162_RESET                                   0x00000000

// 0x080c (BB_TPC_PLUT_SRAM_163)
#define BB_TPC_PLUT_SRAM_163_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_163_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_163_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_163_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_163_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_163_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_163_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_163_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_163_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_163_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_163_ADDRESS                                 0x080c
#define BB_TPC_PLUT_SRAM_163_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_163_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_163_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_163_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_163_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_163_RESET                                   0x00000000

// 0x0810 (BB_TPC_PLUT_SRAM_164)
#define BB_TPC_PLUT_SRAM_164_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_164_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_164_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_164_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_164_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_164_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_164_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_164_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_164_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_164_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_164_ADDRESS                                 0x0810
#define BB_TPC_PLUT_SRAM_164_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_164_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_164_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_164_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_164_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_164_RESET                                   0x00000000

// 0x0814 (BB_TPC_PLUT_SRAM_165)
#define BB_TPC_PLUT_SRAM_165_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_165_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_165_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_165_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_165_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_165_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_165_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_165_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_165_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_165_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_165_ADDRESS                                 0x0814
#define BB_TPC_PLUT_SRAM_165_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_165_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_165_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_165_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_165_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_165_RESET                                   0x00000000

// 0x0818 (BB_TPC_PLUT_SRAM_166)
#define BB_TPC_PLUT_SRAM_166_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_166_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_166_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_166_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_166_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_166_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_166_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_166_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_166_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_166_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_166_ADDRESS                                 0x0818
#define BB_TPC_PLUT_SRAM_166_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_166_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_166_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_166_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_166_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_166_RESET                                   0x00000000

// 0x081c (BB_TPC_PLUT_SRAM_167)
#define BB_TPC_PLUT_SRAM_167_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_167_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_167_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_167_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_167_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_167_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_167_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_167_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_167_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_167_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_167_ADDRESS                                 0x081c
#define BB_TPC_PLUT_SRAM_167_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_167_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_167_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_167_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_167_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_167_RESET                                   0x00000000

// 0x0820 (BB_TPC_PLUT_SRAM_168)
#define BB_TPC_PLUT_SRAM_168_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_168_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_168_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_168_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_168_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_168_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_168_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_168_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_168_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_168_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_168_ADDRESS                                 0x0820
#define BB_TPC_PLUT_SRAM_168_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_168_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_168_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_168_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_168_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_168_RESET                                   0x00000000

// 0x0824 (BB_TPC_PLUT_SRAM_169)
#define BB_TPC_PLUT_SRAM_169_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_169_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_169_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_169_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_169_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_169_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_169_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_169_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_169_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_169_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_169_ADDRESS                                 0x0824
#define BB_TPC_PLUT_SRAM_169_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_169_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_169_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_169_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_169_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_169_RESET                                   0x00000000

// 0x0828 (BB_TPC_PLUT_SRAM_170)
#define BB_TPC_PLUT_SRAM_170_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_170_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_170_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_170_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_170_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_170_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_170_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_170_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_170_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_170_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_170_ADDRESS                                 0x0828
#define BB_TPC_PLUT_SRAM_170_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_170_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_170_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_170_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_170_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_170_RESET                                   0x00000000

// 0x082c (BB_TPC_PLUT_SRAM_171)
#define BB_TPC_PLUT_SRAM_171_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_171_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_171_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_171_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_171_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_171_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_171_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_171_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_171_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_171_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_171_ADDRESS                                 0x082c
#define BB_TPC_PLUT_SRAM_171_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_171_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_171_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_171_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_171_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_171_RESET                                   0x00000000

// 0x0830 (BB_TPC_PLUT_SRAM_172)
#define BB_TPC_PLUT_SRAM_172_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_172_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_172_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_172_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_172_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_172_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_172_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_172_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_172_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_172_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_172_ADDRESS                                 0x0830
#define BB_TPC_PLUT_SRAM_172_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_172_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_172_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_172_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_172_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_172_RESET                                   0x00000000

// 0x0834 (BB_TPC_PLUT_SRAM_173)
#define BB_TPC_PLUT_SRAM_173_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_173_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_173_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_173_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_173_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_173_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_173_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_173_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_173_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_173_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_173_ADDRESS                                 0x0834
#define BB_TPC_PLUT_SRAM_173_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_173_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_173_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_173_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_173_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_173_RESET                                   0x00000000

// 0x0838 (BB_TPC_PLUT_SRAM_174)
#define BB_TPC_PLUT_SRAM_174_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_174_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_174_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_174_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_174_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_174_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_174_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_174_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_174_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_174_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_174_ADDRESS                                 0x0838
#define BB_TPC_PLUT_SRAM_174_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_174_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_174_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_174_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_174_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_174_RESET                                   0x00000000

// 0x083c (BB_TPC_PLUT_SRAM_175)
#define BB_TPC_PLUT_SRAM_175_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_175_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_175_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_175_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_175_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_175_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_175_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_175_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_175_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_175_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_175_ADDRESS                                 0x083c
#define BB_TPC_PLUT_SRAM_175_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_175_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_175_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_175_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_175_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_175_RESET                                   0x00000000

// 0x0840 (BB_TPC_PLUT_SRAM_176)
#define BB_TPC_PLUT_SRAM_176_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_176_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_176_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_176_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_176_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_176_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_176_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_176_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_176_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_176_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_176_ADDRESS                                 0x0840
#define BB_TPC_PLUT_SRAM_176_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_176_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_176_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_176_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_176_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_176_RESET                                   0x00000000

// 0x0844 (BB_TPC_PLUT_SRAM_177)
#define BB_TPC_PLUT_SRAM_177_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_177_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_177_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_177_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_177_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_177_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_177_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_177_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_177_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_177_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_177_ADDRESS                                 0x0844
#define BB_TPC_PLUT_SRAM_177_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_177_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_177_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_177_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_177_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_177_RESET                                   0x00000000

// 0x0848 (BB_TPC_PLUT_SRAM_178)
#define BB_TPC_PLUT_SRAM_178_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_178_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_178_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_178_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_178_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_178_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_178_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_178_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_178_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_178_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_178_ADDRESS                                 0x0848
#define BB_TPC_PLUT_SRAM_178_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_178_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_178_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_178_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_178_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_178_RESET                                   0x00000000

// 0x084c (BB_TPC_PLUT_SRAM_179)
#define BB_TPC_PLUT_SRAM_179_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_179_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_179_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_179_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_179_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_179_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_179_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_179_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_179_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_179_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_179_ADDRESS                                 0x084c
#define BB_TPC_PLUT_SRAM_179_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_179_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_179_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_179_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_179_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_179_RESET                                   0x00000000

// 0x0850 (BB_TPC_PLUT_SRAM_180)
#define BB_TPC_PLUT_SRAM_180_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_180_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_180_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_180_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_180_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_180_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_180_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_180_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_180_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_180_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_180_ADDRESS                                 0x0850
#define BB_TPC_PLUT_SRAM_180_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_180_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_180_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_180_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_180_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_180_RESET                                   0x00000000

// 0x0854 (BB_TPC_PLUT_SRAM_181)
#define BB_TPC_PLUT_SRAM_181_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_181_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_181_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_181_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_181_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_181_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_181_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_181_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_181_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_181_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_181_ADDRESS                                 0x0854
#define BB_TPC_PLUT_SRAM_181_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_181_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_181_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_181_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_181_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_181_RESET                                   0x00000000

// 0x0858 (BB_TPC_PLUT_SRAM_182)
#define BB_TPC_PLUT_SRAM_182_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_182_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_182_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_182_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_182_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_182_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_182_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_182_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_182_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_182_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_182_ADDRESS                                 0x0858
#define BB_TPC_PLUT_SRAM_182_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_182_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_182_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_182_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_182_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_182_RESET                                   0x00000000

// 0x085c (BB_TPC_PLUT_SRAM_183)
#define BB_TPC_PLUT_SRAM_183_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_183_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_183_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_183_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_183_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_183_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_183_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_183_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_183_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_183_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_183_ADDRESS                                 0x085c
#define BB_TPC_PLUT_SRAM_183_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_183_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_183_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_183_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_183_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_183_RESET                                   0x00000000

// 0x0860 (BB_TPC_PLUT_SRAM_184)
#define BB_TPC_PLUT_SRAM_184_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_184_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_184_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_184_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_184_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_184_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_184_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_184_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_184_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_184_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_184_ADDRESS                                 0x0860
#define BB_TPC_PLUT_SRAM_184_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_184_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_184_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_184_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_184_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_184_RESET                                   0x00000000

// 0x0864 (BB_TPC_PLUT_SRAM_185)
#define BB_TPC_PLUT_SRAM_185_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_185_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_185_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_185_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_185_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_185_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_185_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_185_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_185_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_185_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_185_ADDRESS                                 0x0864
#define BB_TPC_PLUT_SRAM_185_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_185_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_185_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_185_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_185_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_185_RESET                                   0x00000000

// 0x0868 (BB_TPC_PLUT_SRAM_186)
#define BB_TPC_PLUT_SRAM_186_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_186_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_186_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_186_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_186_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_186_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_186_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_186_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_186_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_186_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_186_ADDRESS                                 0x0868
#define BB_TPC_PLUT_SRAM_186_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_186_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_186_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_186_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_186_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_186_RESET                                   0x00000000

// 0x086c (BB_TPC_PLUT_SRAM_187)
#define BB_TPC_PLUT_SRAM_187_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_187_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_187_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_187_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_187_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_187_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_187_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_187_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_187_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_187_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_187_ADDRESS                                 0x086c
#define BB_TPC_PLUT_SRAM_187_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_187_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_187_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_187_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_187_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_187_RESET                                   0x00000000

// 0x0870 (BB_TPC_PLUT_SRAM_188)
#define BB_TPC_PLUT_SRAM_188_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_188_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_188_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_188_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_188_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_188_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_188_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_188_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_188_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_188_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_188_ADDRESS                                 0x0870
#define BB_TPC_PLUT_SRAM_188_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_188_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_188_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_188_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_188_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_188_RESET                                   0x00000000

// 0x0874 (BB_TPC_PLUT_SRAM_189)
#define BB_TPC_PLUT_SRAM_189_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_189_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_189_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_189_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_189_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_189_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_189_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_189_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_189_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_189_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_189_ADDRESS                                 0x0874
#define BB_TPC_PLUT_SRAM_189_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_189_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_189_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_189_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_189_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_189_RESET                                   0x00000000

// 0x0878 (BB_TPC_PLUT_SRAM_190)
#define BB_TPC_PLUT_SRAM_190_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_190_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_190_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_190_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_190_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_190_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_190_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_190_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_190_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_190_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_190_ADDRESS                                 0x0878
#define BB_TPC_PLUT_SRAM_190_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_190_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_190_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_190_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_190_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_190_RESET                                   0x00000000

// 0x087c (BB_TPC_PLUT_SRAM_191)
#define BB_TPC_PLUT_SRAM_191_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_191_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_191_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_191_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_191_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_191_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_191_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_191_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_191_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_191_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_191_ADDRESS                                 0x087c
#define BB_TPC_PLUT_SRAM_191_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_191_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_191_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_191_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_191_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_191_RESET                                   0x00000000

// 0x0880 (BB_TPC_PLUT_SRAM_192)
#define BB_TPC_PLUT_SRAM_192_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_192_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_192_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_192_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_192_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_192_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_192_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_192_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_192_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_192_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_192_ADDRESS                                 0x0880
#define BB_TPC_PLUT_SRAM_192_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_192_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_192_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_192_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_192_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_192_RESET                                   0x00000000

// 0x0884 (BB_TPC_PLUT_SRAM_193)
#define BB_TPC_PLUT_SRAM_193_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_193_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_193_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_193_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_193_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_193_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_193_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_193_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_193_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_193_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_193_ADDRESS                                 0x0884
#define BB_TPC_PLUT_SRAM_193_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_193_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_193_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_193_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_193_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_193_RESET                                   0x00000000

// 0x0888 (BB_TPC_PLUT_SRAM_194)
#define BB_TPC_PLUT_SRAM_194_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_194_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_194_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_194_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_194_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_194_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_194_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_194_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_194_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_194_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_194_ADDRESS                                 0x0888
#define BB_TPC_PLUT_SRAM_194_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_194_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_194_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_194_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_194_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_194_RESET                                   0x00000000

// 0x088c (BB_TPC_PLUT_SRAM_195)
#define BB_TPC_PLUT_SRAM_195_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_195_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_195_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_195_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_195_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_195_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_195_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_195_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_195_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_195_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_195_ADDRESS                                 0x088c
#define BB_TPC_PLUT_SRAM_195_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_195_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_195_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_195_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_195_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_195_RESET                                   0x00000000

// 0x0890 (BB_TPC_PLUT_SRAM_196)
#define BB_TPC_PLUT_SRAM_196_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_196_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_196_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_196_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_196_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_196_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_196_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_196_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_196_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_196_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_196_ADDRESS                                 0x0890
#define BB_TPC_PLUT_SRAM_196_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_196_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_196_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_196_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_196_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_196_RESET                                   0x00000000

// 0x0894 (BB_TPC_PLUT_SRAM_197)
#define BB_TPC_PLUT_SRAM_197_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_197_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_197_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_197_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_197_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_197_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_197_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_197_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_197_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_197_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_197_ADDRESS                                 0x0894
#define BB_TPC_PLUT_SRAM_197_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_197_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_197_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_197_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_197_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_197_RESET                                   0x00000000

// 0x0898 (BB_TPC_PLUT_SRAM_198)
#define BB_TPC_PLUT_SRAM_198_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_198_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_198_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_198_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_198_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_198_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_198_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_198_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_198_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_198_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_198_ADDRESS                                 0x0898
#define BB_TPC_PLUT_SRAM_198_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_198_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_198_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_198_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_198_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_198_RESET                                   0x00000000

// 0x089c (BB_TPC_PLUT_SRAM_199)
#define BB_TPC_PLUT_SRAM_199_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_199_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_199_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_199_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_199_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_199_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_199_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_199_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_199_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_199_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_199_ADDRESS                                 0x089c
#define BB_TPC_PLUT_SRAM_199_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_199_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_199_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_199_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_199_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_199_RESET                                   0x00000000

// 0x08a0 (BB_TPC_PLUT_SRAM_200)
#define BB_TPC_PLUT_SRAM_200_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_200_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_200_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_200_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_200_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_200_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_200_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_200_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_200_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_200_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_200_ADDRESS                                 0x08a0
#define BB_TPC_PLUT_SRAM_200_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_200_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_200_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_200_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_200_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_200_RESET                                   0x00000000

// 0x08a4 (BB_TPC_PLUT_SRAM_201)
#define BB_TPC_PLUT_SRAM_201_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_201_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_201_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_201_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_201_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_201_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_201_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_201_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_201_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_201_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_201_ADDRESS                                 0x08a4
#define BB_TPC_PLUT_SRAM_201_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_201_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_201_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_201_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_201_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_201_RESET                                   0x00000000

// 0x08a8 (BB_TPC_PLUT_SRAM_202)
#define BB_TPC_PLUT_SRAM_202_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_202_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_202_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_202_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_202_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_202_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_202_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_202_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_202_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_202_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_202_ADDRESS                                 0x08a8
#define BB_TPC_PLUT_SRAM_202_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_202_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_202_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_202_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_202_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_202_RESET                                   0x00000000

// 0x08ac (BB_TPC_PLUT_SRAM_203)
#define BB_TPC_PLUT_SRAM_203_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_203_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_203_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_203_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_203_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_203_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_203_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_203_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_203_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_203_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_203_ADDRESS                                 0x08ac
#define BB_TPC_PLUT_SRAM_203_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_203_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_203_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_203_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_203_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_203_RESET                                   0x00000000

// 0x08b0 (BB_TPC_PLUT_SRAM_204)
#define BB_TPC_PLUT_SRAM_204_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_204_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_204_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_204_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_204_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_204_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_204_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_204_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_204_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_204_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_204_ADDRESS                                 0x08b0
#define BB_TPC_PLUT_SRAM_204_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_204_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_204_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_204_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_204_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_204_RESET                                   0x00000000

// 0x08b4 (BB_TPC_PLUT_SRAM_205)
#define BB_TPC_PLUT_SRAM_205_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_205_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_205_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_205_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_205_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_205_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_205_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_205_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_205_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_205_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_205_ADDRESS                                 0x08b4
#define BB_TPC_PLUT_SRAM_205_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_205_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_205_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_205_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_205_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_205_RESET                                   0x00000000

// 0x08b8 (BB_TPC_PLUT_SRAM_206)
#define BB_TPC_PLUT_SRAM_206_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_206_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_206_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_206_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_206_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_206_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_206_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_206_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_206_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_206_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_206_ADDRESS                                 0x08b8
#define BB_TPC_PLUT_SRAM_206_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_206_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_206_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_206_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_206_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_206_RESET                                   0x00000000

// 0x08bc (BB_TPC_PLUT_SRAM_207)
#define BB_TPC_PLUT_SRAM_207_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_207_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_207_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_207_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_207_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_207_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_207_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_207_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_207_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_207_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_207_ADDRESS                                 0x08bc
#define BB_TPC_PLUT_SRAM_207_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_207_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_207_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_207_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_207_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_207_RESET                                   0x00000000

// 0x08c0 (BB_TPC_PLUT_SRAM_208)
#define BB_TPC_PLUT_SRAM_208_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_208_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_208_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_208_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_208_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_208_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_208_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_208_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_208_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_208_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_208_ADDRESS                                 0x08c0
#define BB_TPC_PLUT_SRAM_208_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_208_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_208_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_208_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_208_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_208_RESET                                   0x00000000

// 0x08c4 (BB_TPC_PLUT_SRAM_209)
#define BB_TPC_PLUT_SRAM_209_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_209_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_209_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_209_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_209_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_209_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_209_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_209_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_209_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_209_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_209_ADDRESS                                 0x08c4
#define BB_TPC_PLUT_SRAM_209_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_209_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_209_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_209_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_209_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_209_RESET                                   0x00000000

// 0x08c8 (BB_TPC_PLUT_SRAM_210)
#define BB_TPC_PLUT_SRAM_210_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_210_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_210_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_210_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_210_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_210_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_210_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_210_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_210_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_210_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_210_ADDRESS                                 0x08c8
#define BB_TPC_PLUT_SRAM_210_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_210_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_210_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_210_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_210_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_210_RESET                                   0x00000000

// 0x08cc (BB_TPC_PLUT_SRAM_211)
#define BB_TPC_PLUT_SRAM_211_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_211_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_211_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_211_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_211_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_211_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_211_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_211_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_211_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_211_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_211_ADDRESS                                 0x08cc
#define BB_TPC_PLUT_SRAM_211_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_211_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_211_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_211_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_211_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_211_RESET                                   0x00000000

// 0x08d0 (BB_TPC_PLUT_SRAM_212)
#define BB_TPC_PLUT_SRAM_212_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_212_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_212_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_212_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_212_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_212_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_212_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_212_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_212_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_212_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_212_ADDRESS                                 0x08d0
#define BB_TPC_PLUT_SRAM_212_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_212_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_212_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_212_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_212_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_212_RESET                                   0x00000000

// 0x08d4 (BB_TPC_PLUT_SRAM_213)
#define BB_TPC_PLUT_SRAM_213_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_213_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_213_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_213_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_213_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_213_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_213_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_213_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_213_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_213_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_213_ADDRESS                                 0x08d4
#define BB_TPC_PLUT_SRAM_213_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_213_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_213_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_213_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_213_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_213_RESET                                   0x00000000

// 0x08d8 (BB_TPC_PLUT_SRAM_214)
#define BB_TPC_PLUT_SRAM_214_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_214_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_214_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_214_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_214_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_214_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_214_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_214_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_214_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_214_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_214_ADDRESS                                 0x08d8
#define BB_TPC_PLUT_SRAM_214_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_214_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_214_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_214_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_214_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_214_RESET                                   0x00000000

// 0x08dc (BB_TPC_PLUT_SRAM_215)
#define BB_TPC_PLUT_SRAM_215_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_215_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_215_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_215_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_215_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_215_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_215_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_215_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_215_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_215_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_215_ADDRESS                                 0x08dc
#define BB_TPC_PLUT_SRAM_215_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_215_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_215_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_215_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_215_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_215_RESET                                   0x00000000

// 0x08e0 (BB_TPC_PLUT_SRAM_216)
#define BB_TPC_PLUT_SRAM_216_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_216_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_216_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_216_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_216_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_216_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_216_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_216_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_216_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_216_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_216_ADDRESS                                 0x08e0
#define BB_TPC_PLUT_SRAM_216_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_216_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_216_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_216_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_216_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_216_RESET                                   0x00000000

// 0x08e4 (BB_TPC_PLUT_SRAM_217)
#define BB_TPC_PLUT_SRAM_217_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_217_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_217_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_217_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_217_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_217_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_217_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_217_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_217_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_217_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_217_ADDRESS                                 0x08e4
#define BB_TPC_PLUT_SRAM_217_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_217_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_217_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_217_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_217_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_217_RESET                                   0x00000000

// 0x08e8 (BB_TPC_PLUT_SRAM_218)
#define BB_TPC_PLUT_SRAM_218_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_218_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_218_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_218_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_218_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_218_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_218_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_218_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_218_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_218_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_218_ADDRESS                                 0x08e8
#define BB_TPC_PLUT_SRAM_218_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_218_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_218_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_218_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_218_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_218_RESET                                   0x00000000

// 0x08ec (BB_TPC_PLUT_SRAM_219)
#define BB_TPC_PLUT_SRAM_219_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_219_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_219_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_219_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_219_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_219_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_219_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_219_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_219_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_219_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_219_ADDRESS                                 0x08ec
#define BB_TPC_PLUT_SRAM_219_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_219_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_219_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_219_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_219_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_219_RESET                                   0x00000000

// 0x08f0 (BB_TPC_PLUT_SRAM_220)
#define BB_TPC_PLUT_SRAM_220_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_220_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_220_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_220_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_220_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_220_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_220_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_220_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_220_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_220_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_220_ADDRESS                                 0x08f0
#define BB_TPC_PLUT_SRAM_220_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_220_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_220_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_220_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_220_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_220_RESET                                   0x00000000

// 0x08f4 (BB_TPC_PLUT_SRAM_221)
#define BB_TPC_PLUT_SRAM_221_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_221_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_221_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_221_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_221_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_221_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_221_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_221_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_221_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_221_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_221_ADDRESS                                 0x08f4
#define BB_TPC_PLUT_SRAM_221_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_221_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_221_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_221_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_221_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_221_RESET                                   0x00000000

// 0x08f8 (BB_TPC_PLUT_SRAM_222)
#define BB_TPC_PLUT_SRAM_222_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_222_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_222_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_222_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_222_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_222_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_222_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_222_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_222_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_222_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_222_ADDRESS                                 0x08f8
#define BB_TPC_PLUT_SRAM_222_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_222_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_222_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_222_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_222_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_222_RESET                                   0x00000000

// 0x08fc (BB_TPC_PLUT_SRAM_223)
#define BB_TPC_PLUT_SRAM_223_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_223_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_223_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_223_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_223_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_223_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_223_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_223_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_223_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_223_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_223_ADDRESS                                 0x08fc
#define BB_TPC_PLUT_SRAM_223_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_223_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_223_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_223_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_223_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_223_RESET                                   0x00000000

// 0x0900 (BB_TPC_PLUT_SRAM_224)
#define BB_TPC_PLUT_SRAM_224_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_224_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_224_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_224_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_224_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_224_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_224_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_224_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_224_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_224_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_224_ADDRESS                                 0x0900
#define BB_TPC_PLUT_SRAM_224_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_224_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_224_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_224_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_224_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_224_RESET                                   0x00000000

// 0x0904 (BB_TPC_PLUT_SRAM_225)
#define BB_TPC_PLUT_SRAM_225_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_225_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_225_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_225_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_225_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_225_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_225_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_225_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_225_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_225_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_225_ADDRESS                                 0x0904
#define BB_TPC_PLUT_SRAM_225_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_225_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_225_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_225_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_225_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_225_RESET                                   0x00000000

// 0x0908 (BB_TPC_PLUT_SRAM_226)
#define BB_TPC_PLUT_SRAM_226_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_226_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_226_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_226_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_226_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_226_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_226_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_226_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_226_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_226_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_226_ADDRESS                                 0x0908
#define BB_TPC_PLUT_SRAM_226_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_226_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_226_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_226_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_226_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_226_RESET                                   0x00000000

// 0x090c (BB_TPC_PLUT_SRAM_227)
#define BB_TPC_PLUT_SRAM_227_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_227_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_227_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_227_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_227_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_227_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_227_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_227_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_227_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_227_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_227_ADDRESS                                 0x090c
#define BB_TPC_PLUT_SRAM_227_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_227_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_227_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_227_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_227_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_227_RESET                                   0x00000000

// 0x0910 (BB_TPC_PLUT_SRAM_228)
#define BB_TPC_PLUT_SRAM_228_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_228_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_228_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_228_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_228_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_228_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_228_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_228_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_228_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_228_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_228_ADDRESS                                 0x0910
#define BB_TPC_PLUT_SRAM_228_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_228_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_228_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_228_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_228_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_228_RESET                                   0x00000000

// 0x0914 (BB_TPC_PLUT_SRAM_229)
#define BB_TPC_PLUT_SRAM_229_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_229_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_229_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_229_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_229_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_229_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_229_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_229_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_229_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_229_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_229_ADDRESS                                 0x0914
#define BB_TPC_PLUT_SRAM_229_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_229_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_229_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_229_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_229_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_229_RESET                                   0x00000000

// 0x0918 (BB_TPC_PLUT_SRAM_230)
#define BB_TPC_PLUT_SRAM_230_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_230_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_230_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_230_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_230_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_230_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_230_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_230_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_230_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_230_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_230_ADDRESS                                 0x0918
#define BB_TPC_PLUT_SRAM_230_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_230_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_230_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_230_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_230_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_230_RESET                                   0x00000000

// 0x091c (BB_TPC_PLUT_SRAM_231)
#define BB_TPC_PLUT_SRAM_231_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_231_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_231_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_231_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_231_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_231_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_231_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_231_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_231_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_231_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_231_ADDRESS                                 0x091c
#define BB_TPC_PLUT_SRAM_231_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_231_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_231_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_231_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_231_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_231_RESET                                   0x00000000

// 0x0920 (BB_TPC_PLUT_SRAM_232)
#define BB_TPC_PLUT_SRAM_232_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_232_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_232_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_232_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_232_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_232_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_232_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_232_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_232_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_232_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_232_ADDRESS                                 0x0920
#define BB_TPC_PLUT_SRAM_232_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_232_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_232_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_232_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_232_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_232_RESET                                   0x00000000

// 0x0924 (BB_TPC_PLUT_SRAM_233)
#define BB_TPC_PLUT_SRAM_233_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_233_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_233_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_233_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_233_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_233_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_233_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_233_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_233_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_233_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_233_ADDRESS                                 0x0924
#define BB_TPC_PLUT_SRAM_233_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_233_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_233_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_233_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_233_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_233_RESET                                   0x00000000

// 0x0928 (BB_TPC_PLUT_SRAM_234)
#define BB_TPC_PLUT_SRAM_234_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_234_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_234_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_234_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_234_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_234_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_234_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_234_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_234_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_234_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_234_ADDRESS                                 0x0928
#define BB_TPC_PLUT_SRAM_234_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_234_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_234_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_234_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_234_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_234_RESET                                   0x00000000

// 0x092c (BB_TPC_PLUT_SRAM_235)
#define BB_TPC_PLUT_SRAM_235_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_235_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_235_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_235_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_235_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_235_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_235_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_235_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_235_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_235_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_235_ADDRESS                                 0x092c
#define BB_TPC_PLUT_SRAM_235_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_235_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_235_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_235_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_235_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_235_RESET                                   0x00000000

// 0x0930 (BB_TPC_PLUT_SRAM_236)
#define BB_TPC_PLUT_SRAM_236_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_236_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_236_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_236_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_236_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_236_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_236_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_236_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_236_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_236_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_236_ADDRESS                                 0x0930
#define BB_TPC_PLUT_SRAM_236_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_236_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_236_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_236_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_236_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_236_RESET                                   0x00000000

// 0x0934 (BB_TPC_PLUT_SRAM_237)
#define BB_TPC_PLUT_SRAM_237_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_237_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_237_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_237_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_237_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_237_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_237_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_237_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_237_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_237_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_237_ADDRESS                                 0x0934
#define BB_TPC_PLUT_SRAM_237_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_237_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_237_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_237_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_237_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_237_RESET                                   0x00000000

// 0x0938 (BB_TPC_PLUT_SRAM_238)
#define BB_TPC_PLUT_SRAM_238_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_238_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_238_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_238_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_238_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_238_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_238_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_238_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_238_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_238_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_238_ADDRESS                                 0x0938
#define BB_TPC_PLUT_SRAM_238_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_238_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_238_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_238_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_238_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_238_RESET                                   0x00000000

// 0x093c (BB_TPC_PLUT_SRAM_239)
#define BB_TPC_PLUT_SRAM_239_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_239_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_239_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_239_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_239_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_239_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_239_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_239_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_239_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_239_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_239_ADDRESS                                 0x093c
#define BB_TPC_PLUT_SRAM_239_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_239_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_239_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_239_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_239_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_239_RESET                                   0x00000000

// 0x0940 (BB_TPC_PLUT_SRAM_240)
#define BB_TPC_PLUT_SRAM_240_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_240_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_240_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_240_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_240_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_240_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_240_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_240_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_240_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_240_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_240_ADDRESS                                 0x0940
#define BB_TPC_PLUT_SRAM_240_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_240_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_240_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_240_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_240_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_240_RESET                                   0x00000000

// 0x0944 (BB_TPC_PLUT_SRAM_241)
#define BB_TPC_PLUT_SRAM_241_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_241_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_241_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_241_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_241_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_241_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_241_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_241_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_241_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_241_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_241_ADDRESS                                 0x0944
#define BB_TPC_PLUT_SRAM_241_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_241_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_241_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_241_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_241_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_241_RESET                                   0x00000000

// 0x0948 (BB_TPC_PLUT_SRAM_242)
#define BB_TPC_PLUT_SRAM_242_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_242_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_242_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_242_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_242_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_242_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_242_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_242_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_242_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_242_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_242_ADDRESS                                 0x0948
#define BB_TPC_PLUT_SRAM_242_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_242_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_242_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_242_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_242_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_242_RESET                                   0x00000000

// 0x094c (BB_TPC_PLUT_SRAM_243)
#define BB_TPC_PLUT_SRAM_243_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_243_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_243_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_243_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_243_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_243_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_243_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_243_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_243_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_243_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_243_ADDRESS                                 0x094c
#define BB_TPC_PLUT_SRAM_243_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_243_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_243_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_243_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_243_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_243_RESET                                   0x00000000

// 0x0950 (BB_TPC_PLUT_SRAM_244)
#define BB_TPC_PLUT_SRAM_244_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_244_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_244_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_244_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_244_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_244_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_244_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_244_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_244_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_244_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_244_ADDRESS                                 0x0950
#define BB_TPC_PLUT_SRAM_244_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_244_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_244_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_244_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_244_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_244_RESET                                   0x00000000

// 0x0954 (BB_TPC_PLUT_SRAM_245)
#define BB_TPC_PLUT_SRAM_245_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_245_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_245_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_245_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_245_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_245_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_245_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_245_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_245_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_245_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_245_ADDRESS                                 0x0954
#define BB_TPC_PLUT_SRAM_245_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_245_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_245_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_245_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_245_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_245_RESET                                   0x00000000

// 0x0958 (BB_TPC_PLUT_SRAM_246)
#define BB_TPC_PLUT_SRAM_246_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_246_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_246_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_246_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_246_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_246_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_246_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_246_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_246_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_246_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_246_ADDRESS                                 0x0958
#define BB_TPC_PLUT_SRAM_246_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_246_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_246_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_246_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_246_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_246_RESET                                   0x00000000

// 0x095c (BB_TPC_PLUT_SRAM_247)
#define BB_TPC_PLUT_SRAM_247_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_247_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_247_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_247_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_247_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_247_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_247_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_247_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_247_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_247_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_247_ADDRESS                                 0x095c
#define BB_TPC_PLUT_SRAM_247_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_247_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_247_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_247_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_247_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_247_RESET                                   0x00000000

// 0x0960 (BB_TPC_PLUT_SRAM_248)
#define BB_TPC_PLUT_SRAM_248_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_248_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_248_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_248_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_248_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_248_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_248_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_248_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_248_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_248_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_248_ADDRESS                                 0x0960
#define BB_TPC_PLUT_SRAM_248_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_248_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_248_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_248_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_248_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_248_RESET                                   0x00000000

// 0x0964 (BB_TPC_PLUT_SRAM_249)
#define BB_TPC_PLUT_SRAM_249_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_249_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_249_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_249_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_249_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_249_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_249_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_249_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_249_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_249_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_249_ADDRESS                                 0x0964
#define BB_TPC_PLUT_SRAM_249_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_249_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_249_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_249_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_249_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_249_RESET                                   0x00000000

// 0x0968 (BB_TPC_PLUT_SRAM_250)
#define BB_TPC_PLUT_SRAM_250_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_250_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_250_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_250_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_250_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_250_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_250_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_250_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_250_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_250_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_250_ADDRESS                                 0x0968
#define BB_TPC_PLUT_SRAM_250_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_250_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_250_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_250_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_250_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_250_RESET                                   0x00000000

// 0x096c (BB_TPC_PLUT_SRAM_251)
#define BB_TPC_PLUT_SRAM_251_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_251_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_251_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_251_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_251_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_251_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_251_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_251_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_251_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_251_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_251_ADDRESS                                 0x096c
#define BB_TPC_PLUT_SRAM_251_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_251_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_251_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_251_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_251_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_251_RESET                                   0x00000000

// 0x0970 (BB_TPC_PLUT_SRAM_252)
#define BB_TPC_PLUT_SRAM_252_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_252_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_252_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_252_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_252_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_252_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_252_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_252_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_252_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_252_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_252_ADDRESS                                 0x0970
#define BB_TPC_PLUT_SRAM_252_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_252_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_252_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_252_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_252_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_252_RESET                                   0x00000000

// 0x0974 (BB_TPC_PLUT_SRAM_253)
#define BB_TPC_PLUT_SRAM_253_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_253_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_253_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_253_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_253_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_253_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_253_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_253_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_253_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_253_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_253_ADDRESS                                 0x0974
#define BB_TPC_PLUT_SRAM_253_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_253_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_253_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_253_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_253_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_253_RESET                                   0x00000000

// 0x0978 (BB_TPC_PLUT_SRAM_254)
#define BB_TPC_PLUT_SRAM_254_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_254_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_254_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_254_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_254_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_254_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_254_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_254_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_254_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_254_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_254_ADDRESS                                 0x0978
#define BB_TPC_PLUT_SRAM_254_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_254_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_254_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_254_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_254_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_254_RESET                                   0x00000000

// 0x097c (BB_TPC_PLUT_SRAM_255)
#define BB_TPC_PLUT_SRAM_255_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_255_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_255_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_255_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_255_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_255_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_255_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_255_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_255_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_255_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_255_ADDRESS                                 0x097c
#define BB_TPC_PLUT_SRAM_255_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_255_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_255_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_255_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_255_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_255_RESET                                   0x00000000

// 0x0980 (BB_TPC_PLUT_SRAM_256)
#define BB_TPC_PLUT_SRAM_256_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_256_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_256_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_256_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_256_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_256_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_256_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_256_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_256_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_256_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_256_ADDRESS                                 0x0980
#define BB_TPC_PLUT_SRAM_256_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_256_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_256_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_256_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_256_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_256_RESET                                   0x00000000

// 0x0984 (BB_TPC_PLUT_SRAM_257)
#define BB_TPC_PLUT_SRAM_257_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_257_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_257_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_257_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_257_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_257_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_257_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_257_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_257_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_257_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_257_ADDRESS                                 0x0984
#define BB_TPC_PLUT_SRAM_257_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_257_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_257_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_257_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_257_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_257_RESET                                   0x00000000

// 0x0988 (BB_TPC_PLUT_SRAM_258)
#define BB_TPC_PLUT_SRAM_258_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_258_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_258_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_258_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_258_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_258_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_258_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_258_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_258_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_258_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_258_ADDRESS                                 0x0988
#define BB_TPC_PLUT_SRAM_258_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_258_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_258_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_258_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_258_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_258_RESET                                   0x00000000

// 0x098c (BB_TPC_PLUT_SRAM_259)
#define BB_TPC_PLUT_SRAM_259_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_259_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_259_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_259_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_259_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_259_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_259_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_259_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_259_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_259_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_259_ADDRESS                                 0x098c
#define BB_TPC_PLUT_SRAM_259_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_259_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_259_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_259_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_259_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_259_RESET                                   0x00000000

// 0x0990 (BB_TPC_PLUT_SRAM_260)
#define BB_TPC_PLUT_SRAM_260_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_260_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_260_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_260_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_260_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_260_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_260_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_260_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_260_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_260_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_260_ADDRESS                                 0x0990
#define BB_TPC_PLUT_SRAM_260_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_260_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_260_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_260_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_260_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_260_RESET                                   0x00000000

// 0x0994 (BB_TPC_PLUT_SRAM_261)
#define BB_TPC_PLUT_SRAM_261_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_261_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_261_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_261_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_261_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_261_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_261_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_261_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_261_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_261_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_261_ADDRESS                                 0x0994
#define BB_TPC_PLUT_SRAM_261_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_261_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_261_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_261_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_261_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_261_RESET                                   0x00000000

// 0x0998 (BB_TPC_PLUT_SRAM_262)
#define BB_TPC_PLUT_SRAM_262_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_262_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_262_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_262_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_262_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_262_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_262_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_262_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_262_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_262_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_262_ADDRESS                                 0x0998
#define BB_TPC_PLUT_SRAM_262_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_262_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_262_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_262_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_262_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_262_RESET                                   0x00000000

// 0x099c (BB_TPC_PLUT_SRAM_263)
#define BB_TPC_PLUT_SRAM_263_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_263_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_263_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_263_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_263_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_263_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_263_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_263_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_263_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_263_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_263_ADDRESS                                 0x099c
#define BB_TPC_PLUT_SRAM_263_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_263_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_263_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_263_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_263_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_263_RESET                                   0x00000000

// 0x09a0 (BB_TPC_PLUT_SRAM_264)
#define BB_TPC_PLUT_SRAM_264_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_264_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_264_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_264_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_264_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_264_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_264_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_264_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_264_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_264_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_264_ADDRESS                                 0x09a0
#define BB_TPC_PLUT_SRAM_264_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_264_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_264_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_264_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_264_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_264_RESET                                   0x00000000

// 0x09a4 (BB_TPC_PLUT_SRAM_265)
#define BB_TPC_PLUT_SRAM_265_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_265_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_265_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_265_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_265_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_265_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_265_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_265_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_265_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_265_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_265_ADDRESS                                 0x09a4
#define BB_TPC_PLUT_SRAM_265_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_265_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_265_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_265_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_265_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_265_RESET                                   0x00000000

// 0x09a8 (BB_TPC_PLUT_SRAM_266)
#define BB_TPC_PLUT_SRAM_266_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_266_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_266_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_266_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_266_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_266_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_266_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_266_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_266_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_266_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_266_ADDRESS                                 0x09a8
#define BB_TPC_PLUT_SRAM_266_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_266_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_266_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_266_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_266_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_266_RESET                                   0x00000000

// 0x09ac (BB_TPC_PLUT_SRAM_267)
#define BB_TPC_PLUT_SRAM_267_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_267_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_267_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_267_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_267_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_267_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_267_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_267_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_267_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_267_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_267_ADDRESS                                 0x09ac
#define BB_TPC_PLUT_SRAM_267_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_267_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_267_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_267_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_267_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_267_RESET                                   0x00000000

// 0x09b0 (BB_TPC_PLUT_SRAM_268)
#define BB_TPC_PLUT_SRAM_268_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_268_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_268_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_268_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_268_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_268_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_268_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_268_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_268_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_268_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_268_ADDRESS                                 0x09b0
#define BB_TPC_PLUT_SRAM_268_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_268_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_268_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_268_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_268_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_268_RESET                                   0x00000000

// 0x09b4 (BB_TPC_PLUT_SRAM_269)
#define BB_TPC_PLUT_SRAM_269_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_269_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_269_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_269_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_269_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_269_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_269_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_269_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_269_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_269_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_269_ADDRESS                                 0x09b4
#define BB_TPC_PLUT_SRAM_269_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_269_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_269_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_269_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_269_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_269_RESET                                   0x00000000

// 0x09b8 (BB_TPC_PLUT_SRAM_270)
#define BB_TPC_PLUT_SRAM_270_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_270_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_270_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_270_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_270_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_270_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_270_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_270_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_270_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_270_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_270_ADDRESS                                 0x09b8
#define BB_TPC_PLUT_SRAM_270_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_270_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_270_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_270_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_270_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_270_RESET                                   0x00000000

// 0x09bc (BB_TPC_PLUT_SRAM_271)
#define BB_TPC_PLUT_SRAM_271_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_271_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_271_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_271_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_271_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_271_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_271_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_271_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_271_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_271_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_271_ADDRESS                                 0x09bc
#define BB_TPC_PLUT_SRAM_271_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_271_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_271_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_271_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_271_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_271_RESET                                   0x00000000

// 0x09c0 (BB_TPC_PLUT_SRAM_272)
#define BB_TPC_PLUT_SRAM_272_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_272_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_272_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_272_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_272_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_272_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_272_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_272_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_272_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_272_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_272_ADDRESS                                 0x09c0
#define BB_TPC_PLUT_SRAM_272_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_272_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_272_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_272_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_272_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_272_RESET                                   0x00000000

// 0x09c4 (BB_TPC_PLUT_SRAM_273)
#define BB_TPC_PLUT_SRAM_273_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_273_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_273_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_273_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_273_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_273_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_273_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_273_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_273_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_273_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_273_ADDRESS                                 0x09c4
#define BB_TPC_PLUT_SRAM_273_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_273_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_273_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_273_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_273_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_273_RESET                                   0x00000000

// 0x09c8 (BB_TPC_PLUT_SRAM_274)
#define BB_TPC_PLUT_SRAM_274_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_274_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_274_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_274_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_274_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_274_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_274_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_274_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_274_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_274_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_274_ADDRESS                                 0x09c8
#define BB_TPC_PLUT_SRAM_274_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_274_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_274_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_274_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_274_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_274_RESET                                   0x00000000

// 0x09cc (BB_TPC_PLUT_SRAM_275)
#define BB_TPC_PLUT_SRAM_275_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_275_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_275_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_275_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_275_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_275_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_275_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_275_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_275_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_275_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_275_ADDRESS                                 0x09cc
#define BB_TPC_PLUT_SRAM_275_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_275_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_275_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_275_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_275_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_275_RESET                                   0x00000000

// 0x09d0 (BB_TPC_PLUT_SRAM_276)
#define BB_TPC_PLUT_SRAM_276_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_276_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_276_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_276_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_276_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_276_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_276_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_276_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_276_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_276_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_276_ADDRESS                                 0x09d0
#define BB_TPC_PLUT_SRAM_276_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_276_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_276_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_276_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_276_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_276_RESET                                   0x00000000

// 0x09d4 (BB_TPC_PLUT_SRAM_277)
#define BB_TPC_PLUT_SRAM_277_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_277_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_277_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_277_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_277_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_277_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_277_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_277_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_277_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_277_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_277_ADDRESS                                 0x09d4
#define BB_TPC_PLUT_SRAM_277_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_277_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_277_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_277_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_277_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_277_RESET                                   0x00000000

// 0x09d8 (BB_TPC_PLUT_SRAM_278)
#define BB_TPC_PLUT_SRAM_278_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_278_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_278_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_278_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_278_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_278_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_278_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_278_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_278_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_278_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_278_ADDRESS                                 0x09d8
#define BB_TPC_PLUT_SRAM_278_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_278_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_278_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_278_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_278_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_278_RESET                                   0x00000000

// 0x09dc (BB_TPC_PLUT_SRAM_279)
#define BB_TPC_PLUT_SRAM_279_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_279_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_279_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_279_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_279_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_279_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_279_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_279_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_279_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_279_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_279_ADDRESS                                 0x09dc
#define BB_TPC_PLUT_SRAM_279_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_279_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_279_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_279_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_279_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_279_RESET                                   0x00000000

// 0x09e0 (BB_TPC_PLUT_SRAM_280)
#define BB_TPC_PLUT_SRAM_280_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_280_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_280_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_280_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_280_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_280_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_280_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_280_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_280_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_280_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_280_ADDRESS                                 0x09e0
#define BB_TPC_PLUT_SRAM_280_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_280_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_280_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_280_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_280_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_280_RESET                                   0x00000000

// 0x09e4 (BB_TPC_PLUT_SRAM_281)
#define BB_TPC_PLUT_SRAM_281_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_281_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_281_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_281_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_281_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_281_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_281_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_281_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_281_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_281_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_281_ADDRESS                                 0x09e4
#define BB_TPC_PLUT_SRAM_281_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_281_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_281_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_281_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_281_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_281_RESET                                   0x00000000

// 0x09e8 (BB_TPC_PLUT_SRAM_282)
#define BB_TPC_PLUT_SRAM_282_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_282_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_282_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_282_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_282_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_282_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_282_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_282_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_282_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_282_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_282_ADDRESS                                 0x09e8
#define BB_TPC_PLUT_SRAM_282_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_282_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_282_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_282_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_282_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_282_RESET                                   0x00000000

// 0x09ec (BB_TPC_PLUT_SRAM_283)
#define BB_TPC_PLUT_SRAM_283_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_283_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_283_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_283_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_283_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_283_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_283_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_283_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_283_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_283_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_283_ADDRESS                                 0x09ec
#define BB_TPC_PLUT_SRAM_283_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_283_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_283_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_283_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_283_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_283_RESET                                   0x00000000

// 0x09f0 (BB_TPC_PLUT_SRAM_284)
#define BB_TPC_PLUT_SRAM_284_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_284_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_284_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_284_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_284_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_284_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_284_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_284_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_284_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_284_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_284_ADDRESS                                 0x09f0
#define BB_TPC_PLUT_SRAM_284_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_284_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_284_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_284_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_284_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_284_RESET                                   0x00000000

// 0x09f4 (BB_TPC_PLUT_SRAM_285)
#define BB_TPC_PLUT_SRAM_285_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_285_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_285_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_285_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_285_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_285_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_285_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_285_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_285_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_285_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_285_ADDRESS                                 0x09f4
#define BB_TPC_PLUT_SRAM_285_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_285_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_285_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_285_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_285_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_285_RESET                                   0x00000000

// 0x09f8 (BB_TPC_PLUT_SRAM_286)
#define BB_TPC_PLUT_SRAM_286_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_286_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_286_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_286_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_286_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_286_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_286_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_286_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_286_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_286_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_286_ADDRESS                                 0x09f8
#define BB_TPC_PLUT_SRAM_286_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_286_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_286_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_286_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_286_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_286_RESET                                   0x00000000

// 0x09fc (BB_TPC_PLUT_SRAM_287)
#define BB_TPC_PLUT_SRAM_287_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_287_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_287_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_287_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_287_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_287_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_287_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_287_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_287_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_287_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_287_ADDRESS                                 0x09fc
#define BB_TPC_PLUT_SRAM_287_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_287_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_287_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_287_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_287_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_287_RESET                                   0x00000000

// 0x0a00 (BB_TPC_PLUT_SRAM_288)
#define BB_TPC_PLUT_SRAM_288_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_288_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_288_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_288_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_288_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_288_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_288_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_288_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_288_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_288_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_288_ADDRESS                                 0x0a00
#define BB_TPC_PLUT_SRAM_288_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_288_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_288_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_288_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_288_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_288_RESET                                   0x00000000

// 0x0a04 (BB_TPC_PLUT_SRAM_289)
#define BB_TPC_PLUT_SRAM_289_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_289_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_289_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_289_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_289_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_289_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_289_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_289_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_289_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_289_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_289_ADDRESS                                 0x0a04
#define BB_TPC_PLUT_SRAM_289_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_289_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_289_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_289_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_289_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_289_RESET                                   0x00000000

// 0x0a08 (BB_TPC_PLUT_SRAM_290)
#define BB_TPC_PLUT_SRAM_290_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_290_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_290_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_290_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_290_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_290_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_290_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_290_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_290_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_290_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_290_ADDRESS                                 0x0a08
#define BB_TPC_PLUT_SRAM_290_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_290_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_290_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_290_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_290_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_290_RESET                                   0x00000000

// 0x0a0c (BB_TPC_PLUT_SRAM_291)
#define BB_TPC_PLUT_SRAM_291_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_291_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_291_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_291_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_291_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_291_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_291_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_291_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_291_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_291_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_291_ADDRESS                                 0x0a0c
#define BB_TPC_PLUT_SRAM_291_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_291_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_291_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_291_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_291_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_291_RESET                                   0x00000000

// 0x0a10 (BB_TPC_PLUT_SRAM_292)
#define BB_TPC_PLUT_SRAM_292_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_292_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_292_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_292_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_292_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_292_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_292_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_292_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_292_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_292_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_292_ADDRESS                                 0x0a10
#define BB_TPC_PLUT_SRAM_292_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_292_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_292_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_292_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_292_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_292_RESET                                   0x00000000

// 0x0a14 (BB_TPC_PLUT_SRAM_293)
#define BB_TPC_PLUT_SRAM_293_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_293_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_293_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_293_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_293_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_293_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_293_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_293_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_293_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_293_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_293_ADDRESS                                 0x0a14
#define BB_TPC_PLUT_SRAM_293_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_293_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_293_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_293_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_293_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_293_RESET                                   0x00000000

// 0x0a18 (BB_TPC_PLUT_SRAM_294)
#define BB_TPC_PLUT_SRAM_294_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_294_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_294_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_294_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_294_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_294_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_294_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_294_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_294_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_294_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_294_ADDRESS                                 0x0a18
#define BB_TPC_PLUT_SRAM_294_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_294_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_294_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_294_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_294_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_294_RESET                                   0x00000000

// 0x0a1c (BB_TPC_PLUT_SRAM_295)
#define BB_TPC_PLUT_SRAM_295_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_295_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_295_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_295_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_295_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_295_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_295_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_295_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_295_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_295_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_295_ADDRESS                                 0x0a1c
#define BB_TPC_PLUT_SRAM_295_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_295_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_295_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_295_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_295_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_295_RESET                                   0x00000000

// 0x0a20 (BB_TPC_PLUT_SRAM_296)
#define BB_TPC_PLUT_SRAM_296_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_296_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_296_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_296_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_296_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_296_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_296_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_296_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_296_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_296_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_296_ADDRESS                                 0x0a20
#define BB_TPC_PLUT_SRAM_296_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_296_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_296_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_296_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_296_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_296_RESET                                   0x00000000

// 0x0a24 (BB_TPC_PLUT_SRAM_297)
#define BB_TPC_PLUT_SRAM_297_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_297_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_297_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_297_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_297_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_297_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_297_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_297_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_297_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_297_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_297_ADDRESS                                 0x0a24
#define BB_TPC_PLUT_SRAM_297_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_297_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_297_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_297_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_297_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_297_RESET                                   0x00000000

// 0x0a28 (BB_TPC_PLUT_SRAM_298)
#define BB_TPC_PLUT_SRAM_298_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_298_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_298_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_298_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_298_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_298_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_298_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_298_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_298_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_298_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_298_ADDRESS                                 0x0a28
#define BB_TPC_PLUT_SRAM_298_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_298_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_298_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_298_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_298_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_298_RESET                                   0x00000000

// 0x0a2c (BB_TPC_PLUT_SRAM_299)
#define BB_TPC_PLUT_SRAM_299_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_299_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_299_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_299_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_299_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_299_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_299_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_299_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_299_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_299_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_299_ADDRESS                                 0x0a2c
#define BB_TPC_PLUT_SRAM_299_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_299_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_299_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_299_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_299_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_299_RESET                                   0x00000000

// 0x0a30 (BB_TPC_PLUT_SRAM_300)
#define BB_TPC_PLUT_SRAM_300_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_300_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_300_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_300_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_300_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_300_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_300_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_300_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_300_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_300_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_300_ADDRESS                                 0x0a30
#define BB_TPC_PLUT_SRAM_300_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_300_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_300_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_300_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_300_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_300_RESET                                   0x00000000

// 0x0a34 (BB_TPC_PLUT_SRAM_301)
#define BB_TPC_PLUT_SRAM_301_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_301_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_301_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_301_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_301_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_301_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_301_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_301_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_301_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_301_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_301_ADDRESS                                 0x0a34
#define BB_TPC_PLUT_SRAM_301_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_301_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_301_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_301_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_301_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_301_RESET                                   0x00000000

// 0x0a38 (BB_TPC_PLUT_SRAM_302)
#define BB_TPC_PLUT_SRAM_302_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_302_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_302_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_302_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_302_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_302_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_302_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_302_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_302_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_302_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_302_ADDRESS                                 0x0a38
#define BB_TPC_PLUT_SRAM_302_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_302_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_302_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_302_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_302_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_302_RESET                                   0x00000000

// 0x0a3c (BB_TPC_PLUT_SRAM_303)
#define BB_TPC_PLUT_SRAM_303_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_303_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_303_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_303_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_303_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_303_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_303_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_303_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_303_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_303_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_303_ADDRESS                                 0x0a3c
#define BB_TPC_PLUT_SRAM_303_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_303_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_303_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_303_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_303_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_303_RESET                                   0x00000000

// 0x0a40 (BB_TPC_PLUT_SRAM_304)
#define BB_TPC_PLUT_SRAM_304_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_304_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_304_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_304_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_304_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_304_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_304_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_304_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_304_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_304_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_304_ADDRESS                                 0x0a40
#define BB_TPC_PLUT_SRAM_304_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_304_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_304_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_304_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_304_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_304_RESET                                   0x00000000

// 0x0a44 (BB_TPC_PLUT_SRAM_305)
#define BB_TPC_PLUT_SRAM_305_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_305_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_305_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_305_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_305_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_305_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_305_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_305_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_305_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_305_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_305_ADDRESS                                 0x0a44
#define BB_TPC_PLUT_SRAM_305_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_305_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_305_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_305_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_305_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_305_RESET                                   0x00000000

// 0x0a48 (BB_TPC_PLUT_SRAM_306)
#define BB_TPC_PLUT_SRAM_306_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_306_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_306_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_306_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_306_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_306_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_306_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_306_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_306_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_306_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_306_ADDRESS                                 0x0a48
#define BB_TPC_PLUT_SRAM_306_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_306_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_306_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_306_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_306_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_306_RESET                                   0x00000000

// 0x0a4c (BB_TPC_PLUT_SRAM_307)
#define BB_TPC_PLUT_SRAM_307_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_307_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_307_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_307_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_307_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_307_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_307_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_307_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_307_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_307_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_307_ADDRESS                                 0x0a4c
#define BB_TPC_PLUT_SRAM_307_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_307_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_307_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_307_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_307_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_307_RESET                                   0x00000000

// 0x0a50 (BB_TPC_PLUT_SRAM_308)
#define BB_TPC_PLUT_SRAM_308_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_308_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_308_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_308_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_308_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_308_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_308_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_308_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_308_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_308_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_308_ADDRESS                                 0x0a50
#define BB_TPC_PLUT_SRAM_308_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_308_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_308_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_308_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_308_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_308_RESET                                   0x00000000

// 0x0a54 (BB_TPC_PLUT_SRAM_309)
#define BB_TPC_PLUT_SRAM_309_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_309_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_309_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_309_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_309_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_309_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_309_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_309_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_309_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_309_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_309_ADDRESS                                 0x0a54
#define BB_TPC_PLUT_SRAM_309_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_309_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_309_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_309_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_309_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_309_RESET                                   0x00000000

// 0x0a58 (BB_TPC_PLUT_SRAM_310)
#define BB_TPC_PLUT_SRAM_310_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_310_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_310_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_310_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_310_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_310_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_310_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_310_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_310_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_310_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_310_ADDRESS                                 0x0a58
#define BB_TPC_PLUT_SRAM_310_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_310_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_310_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_310_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_310_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_310_RESET                                   0x00000000

// 0x0a5c (BB_TPC_PLUT_SRAM_311)
#define BB_TPC_PLUT_SRAM_311_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_311_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_311_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_311_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_311_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_311_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_311_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_311_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_311_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_311_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_311_ADDRESS                                 0x0a5c
#define BB_TPC_PLUT_SRAM_311_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_311_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_311_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_311_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_311_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_311_RESET                                   0x00000000

// 0x0a60 (BB_TPC_PLUT_SRAM_312)
#define BB_TPC_PLUT_SRAM_312_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_312_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_312_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_312_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_312_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_312_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_312_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_312_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_312_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_312_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_312_ADDRESS                                 0x0a60
#define BB_TPC_PLUT_SRAM_312_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_312_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_312_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_312_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_312_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_312_RESET                                   0x00000000

// 0x0a64 (BB_TPC_PLUT_SRAM_313)
#define BB_TPC_PLUT_SRAM_313_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_313_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_313_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_313_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_313_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_313_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_313_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_313_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_313_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_313_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_313_ADDRESS                                 0x0a64
#define BB_TPC_PLUT_SRAM_313_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_313_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_313_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_313_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_313_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_313_RESET                                   0x00000000

// 0x0a68 (BB_TPC_PLUT_SRAM_314)
#define BB_TPC_PLUT_SRAM_314_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_314_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_314_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_314_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_314_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_314_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_314_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_314_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_314_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_314_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_314_ADDRESS                                 0x0a68
#define BB_TPC_PLUT_SRAM_314_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_314_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_314_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_314_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_314_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_314_RESET                                   0x00000000

// 0x0a6c (BB_TPC_PLUT_SRAM_315)
#define BB_TPC_PLUT_SRAM_315_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_315_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_315_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_315_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_315_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_315_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_315_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_315_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_315_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_315_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_315_ADDRESS                                 0x0a6c
#define BB_TPC_PLUT_SRAM_315_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_315_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_315_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_315_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_315_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_315_RESET                                   0x00000000

// 0x0a70 (BB_TPC_PLUT_SRAM_316)
#define BB_TPC_PLUT_SRAM_316_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_316_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_316_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_316_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_316_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_316_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_316_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_316_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_316_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_316_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_316_ADDRESS                                 0x0a70
#define BB_TPC_PLUT_SRAM_316_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_316_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_316_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_316_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_316_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_316_RESET                                   0x00000000

// 0x0a74 (BB_TPC_PLUT_SRAM_317)
#define BB_TPC_PLUT_SRAM_317_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_317_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_317_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_317_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_317_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_317_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_317_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_317_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_317_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_317_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_317_ADDRESS                                 0x0a74
#define BB_TPC_PLUT_SRAM_317_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_317_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_317_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_317_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_317_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_317_RESET                                   0x00000000

// 0x0a78 (BB_TPC_PLUT_SRAM_318)
#define BB_TPC_PLUT_SRAM_318_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_318_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_318_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_318_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_318_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_318_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_318_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_318_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_318_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_318_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_318_ADDRESS                                 0x0a78
#define BB_TPC_PLUT_SRAM_318_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_318_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_318_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_318_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_318_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_318_RESET                                   0x00000000

// 0x0a7c (BB_TPC_PLUT_SRAM_319)
#define BB_TPC_PLUT_SRAM_319_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_319_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_319_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_319_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_319_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_319_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_319_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_319_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_319_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_319_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_319_ADDRESS                                 0x0a7c
#define BB_TPC_PLUT_SRAM_319_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_319_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_319_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_319_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_319_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_319_RESET                                   0x00000000

// 0x0a80 (BB_TPC_PLUT_SRAM_320)
#define BB_TPC_PLUT_SRAM_320_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_320_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_320_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_320_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_320_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_320_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_320_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_320_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_320_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_320_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_320_ADDRESS                                 0x0a80
#define BB_TPC_PLUT_SRAM_320_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_320_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_320_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_320_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_320_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_320_RESET                                   0x00000000

// 0x0a84 (BB_TPC_PLUT_SRAM_321)
#define BB_TPC_PLUT_SRAM_321_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_321_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_321_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_321_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_321_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_321_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_321_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_321_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_321_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_321_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_321_ADDRESS                                 0x0a84
#define BB_TPC_PLUT_SRAM_321_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_321_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_321_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_321_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_321_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_321_RESET                                   0x00000000

// 0x0a88 (BB_TPC_PLUT_SRAM_322)
#define BB_TPC_PLUT_SRAM_322_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_322_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_322_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_322_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_322_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_322_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_322_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_322_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_322_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_322_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_322_ADDRESS                                 0x0a88
#define BB_TPC_PLUT_SRAM_322_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_322_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_322_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_322_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_322_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_322_RESET                                   0x00000000

// 0x0a8c (BB_TPC_PLUT_SRAM_323)
#define BB_TPC_PLUT_SRAM_323_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_323_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_323_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_323_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_323_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_323_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_323_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_323_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_323_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_323_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_323_ADDRESS                                 0x0a8c
#define BB_TPC_PLUT_SRAM_323_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_323_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_323_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_323_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_323_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_323_RESET                                   0x00000000

// 0x0a90 (BB_TPC_PLUT_SRAM_324)
#define BB_TPC_PLUT_SRAM_324_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_324_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_324_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_324_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_324_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_324_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_324_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_324_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_324_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_324_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_324_ADDRESS                                 0x0a90
#define BB_TPC_PLUT_SRAM_324_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_324_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_324_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_324_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_324_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_324_RESET                                   0x00000000

// 0x0a94 (BB_TPC_PLUT_SRAM_325)
#define BB_TPC_PLUT_SRAM_325_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_325_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_325_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_325_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_325_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_325_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_325_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_325_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_325_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_325_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_325_ADDRESS                                 0x0a94
#define BB_TPC_PLUT_SRAM_325_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_325_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_325_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_325_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_325_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_325_RESET                                   0x00000000

// 0x0a98 (BB_TPC_PLUT_SRAM_326)
#define BB_TPC_PLUT_SRAM_326_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_326_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_326_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_326_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_326_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_326_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_326_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_326_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_326_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_326_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_326_ADDRESS                                 0x0a98
#define BB_TPC_PLUT_SRAM_326_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_326_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_326_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_326_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_326_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_326_RESET                                   0x00000000

// 0x0a9c (BB_TPC_PLUT_SRAM_327)
#define BB_TPC_PLUT_SRAM_327_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_327_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_327_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_327_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_327_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_327_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_327_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_327_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_327_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_327_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_327_ADDRESS                                 0x0a9c
#define BB_TPC_PLUT_SRAM_327_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_327_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_327_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_327_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_327_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_327_RESET                                   0x00000000

// 0x0aa0 (BB_TPC_PLUT_SRAM_328)
#define BB_TPC_PLUT_SRAM_328_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_328_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_328_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_328_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_328_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_328_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_328_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_328_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_328_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_328_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_328_ADDRESS                                 0x0aa0
#define BB_TPC_PLUT_SRAM_328_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_328_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_328_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_328_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_328_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_328_RESET                                   0x00000000

// 0x0aa4 (BB_TPC_PLUT_SRAM_329)
#define BB_TPC_PLUT_SRAM_329_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_329_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_329_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_329_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_329_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_329_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_329_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_329_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_329_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_329_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_329_ADDRESS                                 0x0aa4
#define BB_TPC_PLUT_SRAM_329_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_329_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_329_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_329_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_329_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_329_RESET                                   0x00000000

// 0x0aa8 (BB_TPC_PLUT_SRAM_330)
#define BB_TPC_PLUT_SRAM_330_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_330_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_330_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_330_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_330_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_330_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_330_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_330_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_330_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_330_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_330_ADDRESS                                 0x0aa8
#define BB_TPC_PLUT_SRAM_330_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_330_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_330_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_330_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_330_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_330_RESET                                   0x00000000

// 0x0aac (BB_TPC_PLUT_SRAM_331)
#define BB_TPC_PLUT_SRAM_331_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_331_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_331_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_331_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_331_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_331_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_331_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_331_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_331_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_331_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_331_ADDRESS                                 0x0aac
#define BB_TPC_PLUT_SRAM_331_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_331_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_331_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_331_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_331_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_331_RESET                                   0x00000000

// 0x0ab0 (BB_TPC_PLUT_SRAM_332)
#define BB_TPC_PLUT_SRAM_332_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_332_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_332_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_332_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_332_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_332_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_332_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_332_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_332_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_332_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_332_ADDRESS                                 0x0ab0
#define BB_TPC_PLUT_SRAM_332_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_332_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_332_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_332_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_332_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_332_RESET                                   0x00000000

// 0x0ab4 (BB_TPC_PLUT_SRAM_333)
#define BB_TPC_PLUT_SRAM_333_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_333_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_333_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_333_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_333_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_333_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_333_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_333_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_333_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_333_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_333_ADDRESS                                 0x0ab4
#define BB_TPC_PLUT_SRAM_333_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_333_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_333_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_333_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_333_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_333_RESET                                   0x00000000

// 0x0ab8 (BB_TPC_PLUT_SRAM_334)
#define BB_TPC_PLUT_SRAM_334_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_334_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_334_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_334_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_334_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_334_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_334_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_334_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_334_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_334_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_334_ADDRESS                                 0x0ab8
#define BB_TPC_PLUT_SRAM_334_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_334_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_334_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_334_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_334_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_334_RESET                                   0x00000000

// 0x0abc (BB_TPC_PLUT_SRAM_335)
#define BB_TPC_PLUT_SRAM_335_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_335_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_335_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_335_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_335_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_335_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_335_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_335_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_335_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_335_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_335_ADDRESS                                 0x0abc
#define BB_TPC_PLUT_SRAM_335_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_335_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_335_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_335_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_335_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_335_RESET                                   0x00000000

// 0x0ac0 (BB_TPC_PLUT_SRAM_336)
#define BB_TPC_PLUT_SRAM_336_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_336_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_336_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_336_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_336_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_336_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_336_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_336_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_336_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_336_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_336_ADDRESS                                 0x0ac0
#define BB_TPC_PLUT_SRAM_336_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_336_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_336_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_336_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_336_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_336_RESET                                   0x00000000

// 0x0ac4 (BB_TPC_PLUT_SRAM_337)
#define BB_TPC_PLUT_SRAM_337_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_337_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_337_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_337_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_337_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_337_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_337_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_337_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_337_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_337_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_337_ADDRESS                                 0x0ac4
#define BB_TPC_PLUT_SRAM_337_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_337_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_337_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_337_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_337_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_337_RESET                                   0x00000000

// 0x0ac8 (BB_TPC_PLUT_SRAM_338)
#define BB_TPC_PLUT_SRAM_338_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_338_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_338_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_338_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_338_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_338_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_338_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_338_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_338_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_338_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_338_ADDRESS                                 0x0ac8
#define BB_TPC_PLUT_SRAM_338_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_338_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_338_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_338_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_338_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_338_RESET                                   0x00000000

// 0x0acc (BB_TPC_PLUT_SRAM_339)
#define BB_TPC_PLUT_SRAM_339_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_339_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_339_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_339_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_339_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_339_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_339_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_339_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_339_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_339_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_339_ADDRESS                                 0x0acc
#define BB_TPC_PLUT_SRAM_339_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_339_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_339_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_339_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_339_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_339_RESET                                   0x00000000

// 0x0ad0 (BB_TPC_PLUT_SRAM_340)
#define BB_TPC_PLUT_SRAM_340_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_340_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_340_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_340_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_340_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_340_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_340_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_340_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_340_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_340_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_340_ADDRESS                                 0x0ad0
#define BB_TPC_PLUT_SRAM_340_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_340_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_340_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_340_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_340_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_340_RESET                                   0x00000000

// 0x0ad4 (BB_TPC_PLUT_SRAM_341)
#define BB_TPC_PLUT_SRAM_341_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_341_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_341_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_341_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_341_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_341_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_341_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_341_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_341_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_341_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_341_ADDRESS                                 0x0ad4
#define BB_TPC_PLUT_SRAM_341_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_341_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_341_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_341_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_341_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_341_RESET                                   0x00000000

// 0x0ad8 (BB_TPC_PLUT_SRAM_342)
#define BB_TPC_PLUT_SRAM_342_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_342_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_342_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_342_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_342_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_342_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_342_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_342_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_342_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_342_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_342_ADDRESS                                 0x0ad8
#define BB_TPC_PLUT_SRAM_342_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_342_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_342_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_342_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_342_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_342_RESET                                   0x00000000

// 0x0adc (BB_TPC_PLUT_SRAM_343)
#define BB_TPC_PLUT_SRAM_343_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_343_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_343_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_343_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_343_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_343_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_343_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_343_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_343_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_343_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_343_ADDRESS                                 0x0adc
#define BB_TPC_PLUT_SRAM_343_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_343_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_343_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_343_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_343_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_343_RESET                                   0x00000000

// 0x0ae0 (BB_TPC_PLUT_SRAM_344)
#define BB_TPC_PLUT_SRAM_344_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_344_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_344_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_344_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_344_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_344_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_344_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_344_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_344_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_344_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_344_ADDRESS                                 0x0ae0
#define BB_TPC_PLUT_SRAM_344_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_344_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_344_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_344_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_344_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_344_RESET                                   0x00000000

// 0x0ae4 (BB_TPC_PLUT_SRAM_345)
#define BB_TPC_PLUT_SRAM_345_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_345_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_345_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_345_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_345_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_345_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_345_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_345_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_345_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_345_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_345_ADDRESS                                 0x0ae4
#define BB_TPC_PLUT_SRAM_345_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_345_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_345_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_345_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_345_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_345_RESET                                   0x00000000

// 0x0ae8 (BB_TPC_PLUT_SRAM_346)
#define BB_TPC_PLUT_SRAM_346_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_346_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_346_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_346_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_346_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_346_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_346_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_346_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_346_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_346_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_346_ADDRESS                                 0x0ae8
#define BB_TPC_PLUT_SRAM_346_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_346_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_346_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_346_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_346_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_346_RESET                                   0x00000000

// 0x0aec (BB_TPC_PLUT_SRAM_347)
#define BB_TPC_PLUT_SRAM_347_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_347_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_347_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_347_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_347_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_347_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_347_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_347_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_347_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_347_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_347_ADDRESS                                 0x0aec
#define BB_TPC_PLUT_SRAM_347_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_347_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_347_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_347_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_347_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_347_RESET                                   0x00000000

// 0x0af0 (BB_TPC_PLUT_SRAM_348)
#define BB_TPC_PLUT_SRAM_348_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_348_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_348_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_348_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_348_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_348_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_348_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_348_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_348_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_348_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_348_ADDRESS                                 0x0af0
#define BB_TPC_PLUT_SRAM_348_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_348_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_348_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_348_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_348_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_348_RESET                                   0x00000000

// 0x0af4 (BB_TPC_PLUT_SRAM_349)
#define BB_TPC_PLUT_SRAM_349_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_349_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_349_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_349_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_349_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_349_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_349_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_349_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_349_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_349_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_349_ADDRESS                                 0x0af4
#define BB_TPC_PLUT_SRAM_349_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_349_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_349_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_349_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_349_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_349_RESET                                   0x00000000

// 0x0af8 (BB_TPC_PLUT_SRAM_350)
#define BB_TPC_PLUT_SRAM_350_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_350_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_350_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_350_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_350_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_350_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_350_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_350_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_350_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_350_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_350_ADDRESS                                 0x0af8
#define BB_TPC_PLUT_SRAM_350_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_350_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_350_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_350_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_350_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_350_RESET                                   0x00000000

// 0x0afc (BB_TPC_PLUT_SRAM_351)
#define BB_TPC_PLUT_SRAM_351_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_351_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_351_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_351_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_351_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_351_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_351_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_351_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_351_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_351_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_351_ADDRESS                                 0x0afc
#define BB_TPC_PLUT_SRAM_351_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_351_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_351_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_351_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_351_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_351_RESET                                   0x00000000

// 0x0b00 (BB_TPC_PLUT_SRAM_352)
#define BB_TPC_PLUT_SRAM_352_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_352_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_352_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_352_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_352_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_352_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_352_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_352_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_352_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_352_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_352_ADDRESS                                 0x0b00
#define BB_TPC_PLUT_SRAM_352_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_352_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_352_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_352_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_352_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_352_RESET                                   0x00000000

// 0x0b04 (BB_TPC_PLUT_SRAM_353)
#define BB_TPC_PLUT_SRAM_353_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_353_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_353_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_353_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_353_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_353_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_353_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_353_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_353_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_353_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_353_ADDRESS                                 0x0b04
#define BB_TPC_PLUT_SRAM_353_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_353_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_353_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_353_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_353_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_353_RESET                                   0x00000000

// 0x0b08 (BB_TPC_PLUT_SRAM_354)
#define BB_TPC_PLUT_SRAM_354_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_354_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_354_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_354_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_354_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_354_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_354_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_354_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_354_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_354_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_354_ADDRESS                                 0x0b08
#define BB_TPC_PLUT_SRAM_354_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_354_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_354_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_354_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_354_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_354_RESET                                   0x00000000

// 0x0b0c (BB_TPC_PLUT_SRAM_355)
#define BB_TPC_PLUT_SRAM_355_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_355_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_355_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_355_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_355_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_355_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_355_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_355_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_355_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_355_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_355_ADDRESS                                 0x0b0c
#define BB_TPC_PLUT_SRAM_355_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_355_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_355_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_355_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_355_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_355_RESET                                   0x00000000

// 0x0b10 (BB_TPC_PLUT_SRAM_356)
#define BB_TPC_PLUT_SRAM_356_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_356_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_356_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_356_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_356_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_356_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_356_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_356_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_356_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_356_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_356_ADDRESS                                 0x0b10
#define BB_TPC_PLUT_SRAM_356_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_356_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_356_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_356_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_356_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_356_RESET                                   0x00000000

// 0x0b14 (BB_TPC_PLUT_SRAM_357)
#define BB_TPC_PLUT_SRAM_357_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_357_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_357_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_357_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_357_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_357_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_357_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_357_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_357_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_357_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_357_ADDRESS                                 0x0b14
#define BB_TPC_PLUT_SRAM_357_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_357_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_357_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_357_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_357_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_357_RESET                                   0x00000000

// 0x0b18 (BB_TPC_PLUT_SRAM_358)
#define BB_TPC_PLUT_SRAM_358_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_358_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_358_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_358_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_358_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_358_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_358_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_358_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_358_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_358_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_358_ADDRESS                                 0x0b18
#define BB_TPC_PLUT_SRAM_358_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_358_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_358_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_358_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_358_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_358_RESET                                   0x00000000

// 0x0b1c (BB_TPC_PLUT_SRAM_359)
#define BB_TPC_PLUT_SRAM_359_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_359_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_359_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_359_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_359_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_359_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_359_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_359_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_359_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_359_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_359_ADDRESS                                 0x0b1c
#define BB_TPC_PLUT_SRAM_359_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_359_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_359_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_359_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_359_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_359_RESET                                   0x00000000

// 0x0b20 (BB_TPC_PLUT_SRAM_360)
#define BB_TPC_PLUT_SRAM_360_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_360_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_360_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_360_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_360_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_360_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_360_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_360_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_360_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_360_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_360_ADDRESS                                 0x0b20
#define BB_TPC_PLUT_SRAM_360_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_360_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_360_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_360_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_360_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_360_RESET                                   0x00000000

// 0x0b24 (BB_TPC_PLUT_SRAM_361)
#define BB_TPC_PLUT_SRAM_361_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_361_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_361_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_361_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_361_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_361_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_361_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_361_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_361_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_361_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_361_ADDRESS                                 0x0b24
#define BB_TPC_PLUT_SRAM_361_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_361_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_361_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_361_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_361_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_361_RESET                                   0x00000000

// 0x0b28 (BB_TPC_PLUT_SRAM_362)
#define BB_TPC_PLUT_SRAM_362_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_362_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_362_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_362_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_362_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_362_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_362_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_362_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_362_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_362_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_362_ADDRESS                                 0x0b28
#define BB_TPC_PLUT_SRAM_362_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_362_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_362_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_362_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_362_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_362_RESET                                   0x00000000

// 0x0b2c (BB_TPC_PLUT_SRAM_363)
#define BB_TPC_PLUT_SRAM_363_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_363_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_363_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_363_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_363_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_363_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_363_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_363_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_363_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_363_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_363_ADDRESS                                 0x0b2c
#define BB_TPC_PLUT_SRAM_363_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_363_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_363_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_363_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_363_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_363_RESET                                   0x00000000

// 0x0b30 (BB_TPC_PLUT_SRAM_364)
#define BB_TPC_PLUT_SRAM_364_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_364_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_364_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_364_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_364_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_364_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_364_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_364_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_364_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_364_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_364_ADDRESS                                 0x0b30
#define BB_TPC_PLUT_SRAM_364_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_364_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_364_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_364_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_364_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_364_RESET                                   0x00000000

// 0x0b34 (BB_TPC_PLUT_SRAM_365)
#define BB_TPC_PLUT_SRAM_365_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_365_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_365_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_365_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_365_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_365_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_365_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_365_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_365_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_365_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_365_ADDRESS                                 0x0b34
#define BB_TPC_PLUT_SRAM_365_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_365_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_365_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_365_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_365_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_365_RESET                                   0x00000000

// 0x0b38 (BB_TPC_PLUT_SRAM_366)
#define BB_TPC_PLUT_SRAM_366_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_366_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_366_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_366_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_366_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_366_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_366_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_366_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_366_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_366_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_366_ADDRESS                                 0x0b38
#define BB_TPC_PLUT_SRAM_366_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_366_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_366_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_366_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_366_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_366_RESET                                   0x00000000

// 0x0b3c (BB_TPC_PLUT_SRAM_367)
#define BB_TPC_PLUT_SRAM_367_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_367_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_367_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_367_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_367_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_367_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_367_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_367_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_367_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_367_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_367_ADDRESS                                 0x0b3c
#define BB_TPC_PLUT_SRAM_367_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_367_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_367_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_367_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_367_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_367_RESET                                   0x00000000

// 0x0b40 (BB_TPC_PLUT_SRAM_368)
#define BB_TPC_PLUT_SRAM_368_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_368_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_368_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_368_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_368_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_368_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_368_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_368_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_368_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_368_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_368_ADDRESS                                 0x0b40
#define BB_TPC_PLUT_SRAM_368_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_368_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_368_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_368_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_368_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_368_RESET                                   0x00000000

// 0x0b44 (BB_TPC_PLUT_SRAM_369)
#define BB_TPC_PLUT_SRAM_369_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_369_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_369_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_369_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_369_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_369_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_369_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_369_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_369_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_369_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_369_ADDRESS                                 0x0b44
#define BB_TPC_PLUT_SRAM_369_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_369_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_369_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_369_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_369_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_369_RESET                                   0x00000000

// 0x0b48 (BB_TPC_PLUT_SRAM_370)
#define BB_TPC_PLUT_SRAM_370_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_370_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_370_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_370_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_370_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_370_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_370_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_370_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_370_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_370_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_370_ADDRESS                                 0x0b48
#define BB_TPC_PLUT_SRAM_370_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_370_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_370_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_370_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_370_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_370_RESET                                   0x00000000

// 0x0b4c (BB_TPC_PLUT_SRAM_371)
#define BB_TPC_PLUT_SRAM_371_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_371_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_371_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_371_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_371_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_371_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_371_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_371_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_371_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_371_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_371_ADDRESS                                 0x0b4c
#define BB_TPC_PLUT_SRAM_371_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_371_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_371_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_371_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_371_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_371_RESET                                   0x00000000

// 0x0b50 (BB_TPC_PLUT_SRAM_372)
#define BB_TPC_PLUT_SRAM_372_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_372_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_372_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_372_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_372_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_372_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_372_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_372_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_372_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_372_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_372_ADDRESS                                 0x0b50
#define BB_TPC_PLUT_SRAM_372_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_372_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_372_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_372_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_372_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_372_RESET                                   0x00000000

// 0x0b54 (BB_TPC_PLUT_SRAM_373)
#define BB_TPC_PLUT_SRAM_373_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_373_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_373_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_373_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_373_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_373_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_373_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_373_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_373_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_373_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_373_ADDRESS                                 0x0b54
#define BB_TPC_PLUT_SRAM_373_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_373_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_373_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_373_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_373_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_373_RESET                                   0x00000000

// 0x0b58 (BB_TPC_PLUT_SRAM_374)
#define BB_TPC_PLUT_SRAM_374_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_374_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_374_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_374_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_374_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_374_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_374_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_374_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_374_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_374_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_374_ADDRESS                                 0x0b58
#define BB_TPC_PLUT_SRAM_374_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_374_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_374_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_374_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_374_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_374_RESET                                   0x00000000

// 0x0b5c (BB_TPC_PLUT_SRAM_375)
#define BB_TPC_PLUT_SRAM_375_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_375_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_375_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_375_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_375_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_375_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_375_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_375_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_375_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_375_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_375_ADDRESS                                 0x0b5c
#define BB_TPC_PLUT_SRAM_375_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_375_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_375_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_375_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_375_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_375_RESET                                   0x00000000

// 0x0b60 (BB_TPC_PLUT_SRAM_376)
#define BB_TPC_PLUT_SRAM_376_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_376_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_376_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_376_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_376_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_376_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_376_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_376_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_376_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_376_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_376_ADDRESS                                 0x0b60
#define BB_TPC_PLUT_SRAM_376_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_376_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_376_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_376_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_376_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_376_RESET                                   0x00000000

// 0x0b64 (BB_TPC_PLUT_SRAM_377)
#define BB_TPC_PLUT_SRAM_377_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_377_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_377_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_377_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_377_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_377_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_377_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_377_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_377_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_377_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_377_ADDRESS                                 0x0b64
#define BB_TPC_PLUT_SRAM_377_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_377_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_377_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_377_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_377_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_377_RESET                                   0x00000000

// 0x0b68 (BB_TPC_PLUT_SRAM_378)
#define BB_TPC_PLUT_SRAM_378_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_378_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_378_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_378_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_378_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_378_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_378_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_378_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_378_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_378_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_378_ADDRESS                                 0x0b68
#define BB_TPC_PLUT_SRAM_378_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_378_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_378_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_378_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_378_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_378_RESET                                   0x00000000

// 0x0b6c (BB_TPC_PLUT_SRAM_379)
#define BB_TPC_PLUT_SRAM_379_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_379_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_379_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_379_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_379_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_379_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_379_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_379_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_379_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_379_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_379_ADDRESS                                 0x0b6c
#define BB_TPC_PLUT_SRAM_379_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_379_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_379_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_379_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_379_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_379_RESET                                   0x00000000

// 0x0b70 (BB_TPC_PLUT_SRAM_380)
#define BB_TPC_PLUT_SRAM_380_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_380_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_380_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_380_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_380_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_380_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_380_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_380_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_380_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_380_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_380_ADDRESS                                 0x0b70
#define BB_TPC_PLUT_SRAM_380_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_380_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_380_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_380_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_380_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_380_RESET                                   0x00000000

// 0x0b74 (BB_TPC_PLUT_SRAM_381)
#define BB_TPC_PLUT_SRAM_381_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_381_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_381_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_381_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_381_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_381_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_381_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_381_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_381_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_381_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_381_ADDRESS                                 0x0b74
#define BB_TPC_PLUT_SRAM_381_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_381_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_381_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_381_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_381_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_381_RESET                                   0x00000000

// 0x0b78 (BB_TPC_PLUT_SRAM_382)
#define BB_TPC_PLUT_SRAM_382_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_382_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_382_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_382_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_382_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_382_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_382_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_382_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_382_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_382_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_382_ADDRESS                                 0x0b78
#define BB_TPC_PLUT_SRAM_382_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_382_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_382_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_382_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_382_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_382_RESET                                   0x00000000

// 0x0b7c (BB_TPC_PLUT_SRAM_383)
#define BB_TPC_PLUT_SRAM_383_TPC_PLUT_WORD_MSB                       31
#define BB_TPC_PLUT_SRAM_383_TPC_PLUT_WORD_LSB                       0
#define BB_TPC_PLUT_SRAM_383_TPC_PLUT_WORD_MASK                      0xffffffff
#define BB_TPC_PLUT_SRAM_383_TPC_PLUT_WORD_GET(x)                    (((x) & BB_TPC_PLUT_SRAM_383_TPC_PLUT_WORD_MASK) >> BB_TPC_PLUT_SRAM_383_TPC_PLUT_WORD_LSB)
#define BB_TPC_PLUT_SRAM_383_TPC_PLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_PLUT_SRAM_383_TPC_PLUT_WORD_LSB) & BB_TPC_PLUT_SRAM_383_TPC_PLUT_WORD_MASK)
#define BB_TPC_PLUT_SRAM_383_TPC_PLUT_WORD_RESET                     0
#define BB_TPC_PLUT_SRAM_383_ADDRESS                                 0x0b7c
#define BB_TPC_PLUT_SRAM_383_HW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_383_SW_MASK                                 0xffffffff
#define BB_TPC_PLUT_SRAM_383_HW_WRITE_MASK                           0x00000000
#define BB_TPC_PLUT_SRAM_383_SW_WRITE_MASK                           0xffffffff
#define BB_TPC_PLUT_SRAM_383_RSTMASK                                 0x00000000
#define BB_TPC_PLUT_SRAM_383_RESET                                   0x00000000

// 0x0d80 (BB_TPC_GLUT_SRAM_0)
#define BB_TPC_GLUT_SRAM_0_TPC_GLUT_WORD_MSB                         25
#define BB_TPC_GLUT_SRAM_0_TPC_GLUT_WORD_LSB                         0
#define BB_TPC_GLUT_SRAM_0_TPC_GLUT_WORD_MASK                        0x03ffffff
#define BB_TPC_GLUT_SRAM_0_TPC_GLUT_WORD_GET(x)                      (((x) & BB_TPC_GLUT_SRAM_0_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_0_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_0_TPC_GLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_GLUT_SRAM_0_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_0_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_0_TPC_GLUT_WORD_RESET                       0
#define BB_TPC_GLUT_SRAM_0_ADDRESS                                   0x0d80
#define BB_TPC_GLUT_SRAM_ADDRESS                                     BB_TPC_GLUT_SRAM_0_ADDRESS
#define BB_TPC_GLUT_SRAM_0_HW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_0_SW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_0_HW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_0_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_0_RSTMASK                                   0xfc000000
#define BB_TPC_GLUT_SRAM_0_RESET                                     0x00000000

// 0x0d84 (BB_TPC_GLUT_SRAM_1)
#define BB_TPC_GLUT_SRAM_1_TPC_GLUT_WORD_MSB                         25
#define BB_TPC_GLUT_SRAM_1_TPC_GLUT_WORD_LSB                         0
#define BB_TPC_GLUT_SRAM_1_TPC_GLUT_WORD_MASK                        0x03ffffff
#define BB_TPC_GLUT_SRAM_1_TPC_GLUT_WORD_GET(x)                      (((x) & BB_TPC_GLUT_SRAM_1_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_1_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_1_TPC_GLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_GLUT_SRAM_1_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_1_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_1_TPC_GLUT_WORD_RESET                       0
#define BB_TPC_GLUT_SRAM_1_ADDRESS                                   0x0d84
#define BB_TPC_GLUT_SRAM_1_HW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_1_SW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_1_HW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_1_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_1_RSTMASK                                   0xfc000000
#define BB_TPC_GLUT_SRAM_1_RESET                                     0x00000000

// 0x0d88 (BB_TPC_GLUT_SRAM_2)
#define BB_TPC_GLUT_SRAM_2_TPC_GLUT_WORD_MSB                         25
#define BB_TPC_GLUT_SRAM_2_TPC_GLUT_WORD_LSB                         0
#define BB_TPC_GLUT_SRAM_2_TPC_GLUT_WORD_MASK                        0x03ffffff
#define BB_TPC_GLUT_SRAM_2_TPC_GLUT_WORD_GET(x)                      (((x) & BB_TPC_GLUT_SRAM_2_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_2_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_2_TPC_GLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_GLUT_SRAM_2_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_2_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_2_TPC_GLUT_WORD_RESET                       0
#define BB_TPC_GLUT_SRAM_2_ADDRESS                                   0x0d88
#define BB_TPC_GLUT_SRAM_2_HW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_2_SW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_2_HW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_2_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_2_RSTMASK                                   0xfc000000
#define BB_TPC_GLUT_SRAM_2_RESET                                     0x00000000

// 0x0d8c (BB_TPC_GLUT_SRAM_3)
#define BB_TPC_GLUT_SRAM_3_TPC_GLUT_WORD_MSB                         25
#define BB_TPC_GLUT_SRAM_3_TPC_GLUT_WORD_LSB                         0
#define BB_TPC_GLUT_SRAM_3_TPC_GLUT_WORD_MASK                        0x03ffffff
#define BB_TPC_GLUT_SRAM_3_TPC_GLUT_WORD_GET(x)                      (((x) & BB_TPC_GLUT_SRAM_3_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_3_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_3_TPC_GLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_GLUT_SRAM_3_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_3_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_3_TPC_GLUT_WORD_RESET                       0
#define BB_TPC_GLUT_SRAM_3_ADDRESS                                   0x0d8c
#define BB_TPC_GLUT_SRAM_3_HW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_3_SW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_3_HW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_3_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_3_RSTMASK                                   0xfc000000
#define BB_TPC_GLUT_SRAM_3_RESET                                     0x00000000

// 0x0d90 (BB_TPC_GLUT_SRAM_4)
#define BB_TPC_GLUT_SRAM_4_TPC_GLUT_WORD_MSB                         25
#define BB_TPC_GLUT_SRAM_4_TPC_GLUT_WORD_LSB                         0
#define BB_TPC_GLUT_SRAM_4_TPC_GLUT_WORD_MASK                        0x03ffffff
#define BB_TPC_GLUT_SRAM_4_TPC_GLUT_WORD_GET(x)                      (((x) & BB_TPC_GLUT_SRAM_4_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_4_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_4_TPC_GLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_GLUT_SRAM_4_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_4_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_4_TPC_GLUT_WORD_RESET                       0
#define BB_TPC_GLUT_SRAM_4_ADDRESS                                   0x0d90
#define BB_TPC_GLUT_SRAM_4_HW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_4_SW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_4_HW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_4_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_4_RSTMASK                                   0xfc000000
#define BB_TPC_GLUT_SRAM_4_RESET                                     0x00000000

// 0x0d94 (BB_TPC_GLUT_SRAM_5)
#define BB_TPC_GLUT_SRAM_5_TPC_GLUT_WORD_MSB                         25
#define BB_TPC_GLUT_SRAM_5_TPC_GLUT_WORD_LSB                         0
#define BB_TPC_GLUT_SRAM_5_TPC_GLUT_WORD_MASK                        0x03ffffff
#define BB_TPC_GLUT_SRAM_5_TPC_GLUT_WORD_GET(x)                      (((x) & BB_TPC_GLUT_SRAM_5_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_5_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_5_TPC_GLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_GLUT_SRAM_5_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_5_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_5_TPC_GLUT_WORD_RESET                       0
#define BB_TPC_GLUT_SRAM_5_ADDRESS                                   0x0d94
#define BB_TPC_GLUT_SRAM_5_HW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_5_SW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_5_HW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_5_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_5_RSTMASK                                   0xfc000000
#define BB_TPC_GLUT_SRAM_5_RESET                                     0x00000000

// 0x0d98 (BB_TPC_GLUT_SRAM_6)
#define BB_TPC_GLUT_SRAM_6_TPC_GLUT_WORD_MSB                         25
#define BB_TPC_GLUT_SRAM_6_TPC_GLUT_WORD_LSB                         0
#define BB_TPC_GLUT_SRAM_6_TPC_GLUT_WORD_MASK                        0x03ffffff
#define BB_TPC_GLUT_SRAM_6_TPC_GLUT_WORD_GET(x)                      (((x) & BB_TPC_GLUT_SRAM_6_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_6_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_6_TPC_GLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_GLUT_SRAM_6_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_6_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_6_TPC_GLUT_WORD_RESET                       0
#define BB_TPC_GLUT_SRAM_6_ADDRESS                                   0x0d98
#define BB_TPC_GLUT_SRAM_6_HW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_6_SW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_6_HW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_6_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_6_RSTMASK                                   0xfc000000
#define BB_TPC_GLUT_SRAM_6_RESET                                     0x00000000

// 0x0d9c (BB_TPC_GLUT_SRAM_7)
#define BB_TPC_GLUT_SRAM_7_TPC_GLUT_WORD_MSB                         25
#define BB_TPC_GLUT_SRAM_7_TPC_GLUT_WORD_LSB                         0
#define BB_TPC_GLUT_SRAM_7_TPC_GLUT_WORD_MASK                        0x03ffffff
#define BB_TPC_GLUT_SRAM_7_TPC_GLUT_WORD_GET(x)                      (((x) & BB_TPC_GLUT_SRAM_7_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_7_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_7_TPC_GLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_GLUT_SRAM_7_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_7_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_7_TPC_GLUT_WORD_RESET                       0
#define BB_TPC_GLUT_SRAM_7_ADDRESS                                   0x0d9c
#define BB_TPC_GLUT_SRAM_7_HW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_7_SW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_7_HW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_7_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_7_RSTMASK                                   0xfc000000
#define BB_TPC_GLUT_SRAM_7_RESET                                     0x00000000

// 0x0da0 (BB_TPC_GLUT_SRAM_8)
#define BB_TPC_GLUT_SRAM_8_TPC_GLUT_WORD_MSB                         25
#define BB_TPC_GLUT_SRAM_8_TPC_GLUT_WORD_LSB                         0
#define BB_TPC_GLUT_SRAM_8_TPC_GLUT_WORD_MASK                        0x03ffffff
#define BB_TPC_GLUT_SRAM_8_TPC_GLUT_WORD_GET(x)                      (((x) & BB_TPC_GLUT_SRAM_8_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_8_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_8_TPC_GLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_GLUT_SRAM_8_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_8_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_8_TPC_GLUT_WORD_RESET                       0
#define BB_TPC_GLUT_SRAM_8_ADDRESS                                   0x0da0
#define BB_TPC_GLUT_SRAM_8_HW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_8_SW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_8_HW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_8_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_8_RSTMASK                                   0xfc000000
#define BB_TPC_GLUT_SRAM_8_RESET                                     0x00000000

// 0x0da4 (BB_TPC_GLUT_SRAM_9)
#define BB_TPC_GLUT_SRAM_9_TPC_GLUT_WORD_MSB                         25
#define BB_TPC_GLUT_SRAM_9_TPC_GLUT_WORD_LSB                         0
#define BB_TPC_GLUT_SRAM_9_TPC_GLUT_WORD_MASK                        0x03ffffff
#define BB_TPC_GLUT_SRAM_9_TPC_GLUT_WORD_GET(x)                      (((x) & BB_TPC_GLUT_SRAM_9_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_9_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_9_TPC_GLUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_GLUT_SRAM_9_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_9_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_9_TPC_GLUT_WORD_RESET                       0
#define BB_TPC_GLUT_SRAM_9_ADDRESS                                   0x0da4
#define BB_TPC_GLUT_SRAM_9_HW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_9_SW_MASK                                   0x03ffffff
#define BB_TPC_GLUT_SRAM_9_HW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_9_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_GLUT_SRAM_9_RSTMASK                                   0xfc000000
#define BB_TPC_GLUT_SRAM_9_RESET                                     0x00000000

// 0x0da8 (BB_TPC_GLUT_SRAM_10)
#define BB_TPC_GLUT_SRAM_10_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_10_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_10_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_10_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_10_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_10_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_10_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_10_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_10_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_10_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_10_ADDRESS                                  0x0da8
#define BB_TPC_GLUT_SRAM_10_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_10_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_10_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_10_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_10_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_10_RESET                                    0x00000000

// 0x0dac (BB_TPC_GLUT_SRAM_11)
#define BB_TPC_GLUT_SRAM_11_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_11_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_11_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_11_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_11_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_11_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_11_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_11_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_11_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_11_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_11_ADDRESS                                  0x0dac
#define BB_TPC_GLUT_SRAM_11_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_11_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_11_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_11_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_11_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_11_RESET                                    0x00000000

// 0x0db0 (BB_TPC_GLUT_SRAM_12)
#define BB_TPC_GLUT_SRAM_12_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_12_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_12_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_12_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_12_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_12_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_12_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_12_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_12_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_12_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_12_ADDRESS                                  0x0db0
#define BB_TPC_GLUT_SRAM_12_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_12_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_12_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_12_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_12_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_12_RESET                                    0x00000000

// 0x0db4 (BB_TPC_GLUT_SRAM_13)
#define BB_TPC_GLUT_SRAM_13_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_13_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_13_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_13_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_13_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_13_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_13_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_13_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_13_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_13_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_13_ADDRESS                                  0x0db4
#define BB_TPC_GLUT_SRAM_13_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_13_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_13_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_13_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_13_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_13_RESET                                    0x00000000

// 0x0db8 (BB_TPC_GLUT_SRAM_14)
#define BB_TPC_GLUT_SRAM_14_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_14_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_14_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_14_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_14_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_14_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_14_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_14_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_14_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_14_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_14_ADDRESS                                  0x0db8
#define BB_TPC_GLUT_SRAM_14_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_14_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_14_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_14_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_14_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_14_RESET                                    0x00000000

// 0x0dbc (BB_TPC_GLUT_SRAM_15)
#define BB_TPC_GLUT_SRAM_15_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_15_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_15_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_15_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_15_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_15_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_15_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_15_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_15_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_15_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_15_ADDRESS                                  0x0dbc
#define BB_TPC_GLUT_SRAM_15_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_15_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_15_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_15_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_15_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_15_RESET                                    0x00000000

// 0x0dc0 (BB_TPC_GLUT_SRAM_16)
#define BB_TPC_GLUT_SRAM_16_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_16_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_16_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_16_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_16_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_16_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_16_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_16_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_16_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_16_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_16_ADDRESS                                  0x0dc0
#define BB_TPC_GLUT_SRAM_16_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_16_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_16_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_16_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_16_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_16_RESET                                    0x00000000

// 0x0dc4 (BB_TPC_GLUT_SRAM_17)
#define BB_TPC_GLUT_SRAM_17_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_17_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_17_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_17_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_17_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_17_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_17_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_17_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_17_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_17_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_17_ADDRESS                                  0x0dc4
#define BB_TPC_GLUT_SRAM_17_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_17_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_17_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_17_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_17_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_17_RESET                                    0x00000000

// 0x0dc8 (BB_TPC_GLUT_SRAM_18)
#define BB_TPC_GLUT_SRAM_18_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_18_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_18_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_18_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_18_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_18_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_18_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_18_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_18_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_18_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_18_ADDRESS                                  0x0dc8
#define BB_TPC_GLUT_SRAM_18_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_18_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_18_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_18_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_18_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_18_RESET                                    0x00000000

// 0x0dcc (BB_TPC_GLUT_SRAM_19)
#define BB_TPC_GLUT_SRAM_19_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_19_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_19_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_19_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_19_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_19_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_19_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_19_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_19_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_19_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_19_ADDRESS                                  0x0dcc
#define BB_TPC_GLUT_SRAM_19_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_19_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_19_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_19_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_19_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_19_RESET                                    0x00000000

// 0x0dd0 (BB_TPC_GLUT_SRAM_20)
#define BB_TPC_GLUT_SRAM_20_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_20_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_20_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_20_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_20_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_20_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_20_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_20_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_20_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_20_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_20_ADDRESS                                  0x0dd0
#define BB_TPC_GLUT_SRAM_20_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_20_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_20_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_20_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_20_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_20_RESET                                    0x00000000

// 0x0dd4 (BB_TPC_GLUT_SRAM_21)
#define BB_TPC_GLUT_SRAM_21_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_21_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_21_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_21_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_21_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_21_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_21_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_21_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_21_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_21_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_21_ADDRESS                                  0x0dd4
#define BB_TPC_GLUT_SRAM_21_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_21_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_21_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_21_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_21_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_21_RESET                                    0x00000000

// 0x0dd8 (BB_TPC_GLUT_SRAM_22)
#define BB_TPC_GLUT_SRAM_22_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_22_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_22_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_22_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_22_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_22_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_22_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_22_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_22_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_22_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_22_ADDRESS                                  0x0dd8
#define BB_TPC_GLUT_SRAM_22_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_22_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_22_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_22_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_22_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_22_RESET                                    0x00000000

// 0x0ddc (BB_TPC_GLUT_SRAM_23)
#define BB_TPC_GLUT_SRAM_23_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_23_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_23_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_23_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_23_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_23_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_23_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_23_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_23_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_23_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_23_ADDRESS                                  0x0ddc
#define BB_TPC_GLUT_SRAM_23_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_23_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_23_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_23_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_23_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_23_RESET                                    0x00000000

// 0x0de0 (BB_TPC_GLUT_SRAM_24)
#define BB_TPC_GLUT_SRAM_24_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_24_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_24_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_24_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_24_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_24_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_24_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_24_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_24_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_24_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_24_ADDRESS                                  0x0de0
#define BB_TPC_GLUT_SRAM_24_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_24_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_24_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_24_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_24_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_24_RESET                                    0x00000000

// 0x0de4 (BB_TPC_GLUT_SRAM_25)
#define BB_TPC_GLUT_SRAM_25_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_25_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_25_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_25_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_25_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_25_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_25_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_25_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_25_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_25_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_25_ADDRESS                                  0x0de4
#define BB_TPC_GLUT_SRAM_25_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_25_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_25_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_25_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_25_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_25_RESET                                    0x00000000

// 0x0de8 (BB_TPC_GLUT_SRAM_26)
#define BB_TPC_GLUT_SRAM_26_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_26_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_26_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_26_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_26_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_26_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_26_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_26_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_26_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_26_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_26_ADDRESS                                  0x0de8
#define BB_TPC_GLUT_SRAM_26_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_26_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_26_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_26_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_26_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_26_RESET                                    0x00000000

// 0x0dec (BB_TPC_GLUT_SRAM_27)
#define BB_TPC_GLUT_SRAM_27_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_27_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_27_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_27_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_27_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_27_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_27_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_27_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_27_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_27_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_27_ADDRESS                                  0x0dec
#define BB_TPC_GLUT_SRAM_27_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_27_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_27_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_27_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_27_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_27_RESET                                    0x00000000

// 0x0df0 (BB_TPC_GLUT_SRAM_28)
#define BB_TPC_GLUT_SRAM_28_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_28_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_28_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_28_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_28_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_28_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_28_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_28_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_28_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_28_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_28_ADDRESS                                  0x0df0
#define BB_TPC_GLUT_SRAM_28_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_28_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_28_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_28_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_28_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_28_RESET                                    0x00000000

// 0x0df4 (BB_TPC_GLUT_SRAM_29)
#define BB_TPC_GLUT_SRAM_29_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_29_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_29_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_29_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_29_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_29_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_29_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_29_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_29_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_29_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_29_ADDRESS                                  0x0df4
#define BB_TPC_GLUT_SRAM_29_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_29_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_29_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_29_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_29_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_29_RESET                                    0x00000000

// 0x0df8 (BB_TPC_GLUT_SRAM_30)
#define BB_TPC_GLUT_SRAM_30_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_30_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_30_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_30_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_30_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_30_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_30_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_30_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_30_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_30_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_30_ADDRESS                                  0x0df8
#define BB_TPC_GLUT_SRAM_30_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_30_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_30_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_30_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_30_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_30_RESET                                    0x00000000

// 0x0dfc (BB_TPC_GLUT_SRAM_31)
#define BB_TPC_GLUT_SRAM_31_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_31_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_31_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_31_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_31_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_31_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_31_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_31_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_31_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_31_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_31_ADDRESS                                  0x0dfc
#define BB_TPC_GLUT_SRAM_31_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_31_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_31_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_31_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_31_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_31_RESET                                    0x00000000

// 0x0e00 (BB_TPC_GLUT_SRAM_32)
#define BB_TPC_GLUT_SRAM_32_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_32_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_32_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_32_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_32_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_32_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_32_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_32_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_32_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_32_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_32_ADDRESS                                  0x0e00
#define BB_TPC_GLUT_SRAM_32_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_32_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_32_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_32_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_32_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_32_RESET                                    0x00000000

// 0x0e04 (BB_TPC_GLUT_SRAM_33)
#define BB_TPC_GLUT_SRAM_33_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_33_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_33_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_33_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_33_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_33_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_33_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_33_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_33_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_33_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_33_ADDRESS                                  0x0e04
#define BB_TPC_GLUT_SRAM_33_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_33_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_33_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_33_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_33_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_33_RESET                                    0x00000000

// 0x0e08 (BB_TPC_GLUT_SRAM_34)
#define BB_TPC_GLUT_SRAM_34_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_34_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_34_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_34_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_34_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_34_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_34_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_34_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_34_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_34_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_34_ADDRESS                                  0x0e08
#define BB_TPC_GLUT_SRAM_34_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_34_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_34_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_34_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_34_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_34_RESET                                    0x00000000

// 0x0e0c (BB_TPC_GLUT_SRAM_35)
#define BB_TPC_GLUT_SRAM_35_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_35_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_35_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_35_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_35_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_35_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_35_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_35_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_35_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_35_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_35_ADDRESS                                  0x0e0c
#define BB_TPC_GLUT_SRAM_35_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_35_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_35_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_35_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_35_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_35_RESET                                    0x00000000

// 0x0e10 (BB_TPC_GLUT_SRAM_36)
#define BB_TPC_GLUT_SRAM_36_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_36_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_36_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_36_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_36_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_36_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_36_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_36_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_36_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_36_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_36_ADDRESS                                  0x0e10
#define BB_TPC_GLUT_SRAM_36_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_36_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_36_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_36_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_36_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_36_RESET                                    0x00000000

// 0x0e14 (BB_TPC_GLUT_SRAM_37)
#define BB_TPC_GLUT_SRAM_37_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_37_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_37_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_37_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_37_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_37_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_37_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_37_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_37_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_37_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_37_ADDRESS                                  0x0e14
#define BB_TPC_GLUT_SRAM_37_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_37_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_37_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_37_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_37_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_37_RESET                                    0x00000000

// 0x0e18 (BB_TPC_GLUT_SRAM_38)
#define BB_TPC_GLUT_SRAM_38_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_38_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_38_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_38_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_38_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_38_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_38_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_38_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_38_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_38_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_38_ADDRESS                                  0x0e18
#define BB_TPC_GLUT_SRAM_38_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_38_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_38_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_38_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_38_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_38_RESET                                    0x00000000

// 0x0e1c (BB_TPC_GLUT_SRAM_39)
#define BB_TPC_GLUT_SRAM_39_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_39_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_39_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_39_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_39_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_39_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_39_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_39_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_39_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_39_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_39_ADDRESS                                  0x0e1c
#define BB_TPC_GLUT_SRAM_39_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_39_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_39_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_39_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_39_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_39_RESET                                    0x00000000

// 0x0e20 (BB_TPC_GLUT_SRAM_40)
#define BB_TPC_GLUT_SRAM_40_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_40_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_40_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_40_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_40_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_40_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_40_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_40_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_40_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_40_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_40_ADDRESS                                  0x0e20
#define BB_TPC_GLUT_SRAM_40_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_40_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_40_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_40_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_40_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_40_RESET                                    0x00000000

// 0x0e24 (BB_TPC_GLUT_SRAM_41)
#define BB_TPC_GLUT_SRAM_41_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_41_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_41_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_41_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_41_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_41_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_41_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_41_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_41_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_41_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_41_ADDRESS                                  0x0e24
#define BB_TPC_GLUT_SRAM_41_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_41_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_41_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_41_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_41_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_41_RESET                                    0x00000000

// 0x0e28 (BB_TPC_GLUT_SRAM_42)
#define BB_TPC_GLUT_SRAM_42_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_42_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_42_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_42_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_42_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_42_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_42_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_42_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_42_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_42_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_42_ADDRESS                                  0x0e28
#define BB_TPC_GLUT_SRAM_42_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_42_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_42_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_42_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_42_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_42_RESET                                    0x00000000

// 0x0e2c (BB_TPC_GLUT_SRAM_43)
#define BB_TPC_GLUT_SRAM_43_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_43_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_43_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_43_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_43_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_43_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_43_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_43_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_43_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_43_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_43_ADDRESS                                  0x0e2c
#define BB_TPC_GLUT_SRAM_43_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_43_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_43_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_43_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_43_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_43_RESET                                    0x00000000

// 0x0e30 (BB_TPC_GLUT_SRAM_44)
#define BB_TPC_GLUT_SRAM_44_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_44_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_44_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_44_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_44_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_44_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_44_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_44_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_44_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_44_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_44_ADDRESS                                  0x0e30
#define BB_TPC_GLUT_SRAM_44_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_44_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_44_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_44_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_44_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_44_RESET                                    0x00000000

// 0x0e34 (BB_TPC_GLUT_SRAM_45)
#define BB_TPC_GLUT_SRAM_45_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_45_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_45_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_45_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_45_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_45_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_45_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_45_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_45_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_45_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_45_ADDRESS                                  0x0e34
#define BB_TPC_GLUT_SRAM_45_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_45_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_45_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_45_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_45_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_45_RESET                                    0x00000000

// 0x0e38 (BB_TPC_GLUT_SRAM_46)
#define BB_TPC_GLUT_SRAM_46_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_46_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_46_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_46_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_46_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_46_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_46_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_46_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_46_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_46_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_46_ADDRESS                                  0x0e38
#define BB_TPC_GLUT_SRAM_46_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_46_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_46_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_46_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_46_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_46_RESET                                    0x00000000

// 0x0e3c (BB_TPC_GLUT_SRAM_47)
#define BB_TPC_GLUT_SRAM_47_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_47_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_47_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_47_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_47_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_47_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_47_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_47_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_47_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_47_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_47_ADDRESS                                  0x0e3c
#define BB_TPC_GLUT_SRAM_47_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_47_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_47_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_47_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_47_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_47_RESET                                    0x00000000

// 0x0e40 (BB_TPC_GLUT_SRAM_48)
#define BB_TPC_GLUT_SRAM_48_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_48_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_48_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_48_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_48_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_48_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_48_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_48_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_48_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_48_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_48_ADDRESS                                  0x0e40
#define BB_TPC_GLUT_SRAM_48_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_48_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_48_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_48_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_48_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_48_RESET                                    0x00000000

// 0x0e44 (BB_TPC_GLUT_SRAM_49)
#define BB_TPC_GLUT_SRAM_49_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_49_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_49_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_49_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_49_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_49_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_49_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_49_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_49_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_49_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_49_ADDRESS                                  0x0e44
#define BB_TPC_GLUT_SRAM_49_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_49_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_49_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_49_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_49_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_49_RESET                                    0x00000000

// 0x0e48 (BB_TPC_GLUT_SRAM_50)
#define BB_TPC_GLUT_SRAM_50_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_50_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_50_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_50_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_50_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_50_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_50_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_50_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_50_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_50_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_50_ADDRESS                                  0x0e48
#define BB_TPC_GLUT_SRAM_50_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_50_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_50_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_50_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_50_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_50_RESET                                    0x00000000

// 0x0e4c (BB_TPC_GLUT_SRAM_51)
#define BB_TPC_GLUT_SRAM_51_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_51_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_51_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_51_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_51_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_51_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_51_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_51_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_51_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_51_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_51_ADDRESS                                  0x0e4c
#define BB_TPC_GLUT_SRAM_51_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_51_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_51_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_51_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_51_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_51_RESET                                    0x00000000

// 0x0e50 (BB_TPC_GLUT_SRAM_52)
#define BB_TPC_GLUT_SRAM_52_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_52_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_52_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_52_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_52_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_52_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_52_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_52_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_52_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_52_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_52_ADDRESS                                  0x0e50
#define BB_TPC_GLUT_SRAM_52_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_52_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_52_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_52_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_52_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_52_RESET                                    0x00000000

// 0x0e54 (BB_TPC_GLUT_SRAM_53)
#define BB_TPC_GLUT_SRAM_53_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_53_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_53_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_53_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_53_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_53_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_53_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_53_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_53_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_53_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_53_ADDRESS                                  0x0e54
#define BB_TPC_GLUT_SRAM_53_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_53_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_53_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_53_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_53_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_53_RESET                                    0x00000000

// 0x0e58 (BB_TPC_GLUT_SRAM_54)
#define BB_TPC_GLUT_SRAM_54_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_54_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_54_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_54_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_54_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_54_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_54_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_54_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_54_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_54_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_54_ADDRESS                                  0x0e58
#define BB_TPC_GLUT_SRAM_54_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_54_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_54_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_54_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_54_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_54_RESET                                    0x00000000

// 0x0e5c (BB_TPC_GLUT_SRAM_55)
#define BB_TPC_GLUT_SRAM_55_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_55_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_55_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_55_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_55_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_55_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_55_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_55_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_55_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_55_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_55_ADDRESS                                  0x0e5c
#define BB_TPC_GLUT_SRAM_55_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_55_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_55_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_55_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_55_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_55_RESET                                    0x00000000

// 0x0e60 (BB_TPC_GLUT_SRAM_56)
#define BB_TPC_GLUT_SRAM_56_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_56_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_56_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_56_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_56_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_56_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_56_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_56_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_56_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_56_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_56_ADDRESS                                  0x0e60
#define BB_TPC_GLUT_SRAM_56_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_56_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_56_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_56_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_56_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_56_RESET                                    0x00000000

// 0x0e64 (BB_TPC_GLUT_SRAM_57)
#define BB_TPC_GLUT_SRAM_57_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_57_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_57_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_57_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_57_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_57_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_57_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_57_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_57_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_57_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_57_ADDRESS                                  0x0e64
#define BB_TPC_GLUT_SRAM_57_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_57_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_57_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_57_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_57_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_57_RESET                                    0x00000000

// 0x0e68 (BB_TPC_GLUT_SRAM_58)
#define BB_TPC_GLUT_SRAM_58_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_58_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_58_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_58_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_58_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_58_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_58_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_58_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_58_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_58_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_58_ADDRESS                                  0x0e68
#define BB_TPC_GLUT_SRAM_58_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_58_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_58_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_58_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_58_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_58_RESET                                    0x00000000

// 0x0e6c (BB_TPC_GLUT_SRAM_59)
#define BB_TPC_GLUT_SRAM_59_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_59_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_59_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_59_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_59_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_59_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_59_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_59_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_59_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_59_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_59_ADDRESS                                  0x0e6c
#define BB_TPC_GLUT_SRAM_59_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_59_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_59_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_59_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_59_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_59_RESET                                    0x00000000

// 0x0e70 (BB_TPC_GLUT_SRAM_60)
#define BB_TPC_GLUT_SRAM_60_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_60_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_60_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_60_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_60_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_60_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_60_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_60_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_60_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_60_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_60_ADDRESS                                  0x0e70
#define BB_TPC_GLUT_SRAM_60_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_60_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_60_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_60_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_60_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_60_RESET                                    0x00000000

// 0x0e74 (BB_TPC_GLUT_SRAM_61)
#define BB_TPC_GLUT_SRAM_61_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_61_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_61_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_61_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_61_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_61_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_61_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_61_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_61_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_61_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_61_ADDRESS                                  0x0e74
#define BB_TPC_GLUT_SRAM_61_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_61_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_61_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_61_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_61_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_61_RESET                                    0x00000000

// 0x0e78 (BB_TPC_GLUT_SRAM_62)
#define BB_TPC_GLUT_SRAM_62_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_62_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_62_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_62_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_62_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_62_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_62_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_62_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_62_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_62_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_62_ADDRESS                                  0x0e78
#define BB_TPC_GLUT_SRAM_62_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_62_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_62_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_62_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_62_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_62_RESET                                    0x00000000

// 0x0e7c (BB_TPC_GLUT_SRAM_63)
#define BB_TPC_GLUT_SRAM_63_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_63_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_63_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_63_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_63_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_63_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_63_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_63_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_63_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_63_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_63_ADDRESS                                  0x0e7c
#define BB_TPC_GLUT_SRAM_63_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_63_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_63_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_63_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_63_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_63_RESET                                    0x00000000

// 0x0e80 (BB_TPC_GLUT_SRAM_64)
#define BB_TPC_GLUT_SRAM_64_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_64_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_64_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_64_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_64_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_64_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_64_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_64_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_64_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_64_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_64_ADDRESS                                  0x0e80
#define BB_TPC_GLUT_SRAM_64_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_64_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_64_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_64_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_64_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_64_RESET                                    0x00000000

// 0x0e84 (BB_TPC_GLUT_SRAM_65)
#define BB_TPC_GLUT_SRAM_65_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_65_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_65_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_65_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_65_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_65_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_65_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_65_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_65_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_65_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_65_ADDRESS                                  0x0e84
#define BB_TPC_GLUT_SRAM_65_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_65_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_65_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_65_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_65_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_65_RESET                                    0x00000000

// 0x0e88 (BB_TPC_GLUT_SRAM_66)
#define BB_TPC_GLUT_SRAM_66_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_66_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_66_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_66_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_66_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_66_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_66_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_66_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_66_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_66_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_66_ADDRESS                                  0x0e88
#define BB_TPC_GLUT_SRAM_66_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_66_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_66_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_66_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_66_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_66_RESET                                    0x00000000

// 0x0e8c (BB_TPC_GLUT_SRAM_67)
#define BB_TPC_GLUT_SRAM_67_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_67_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_67_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_67_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_67_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_67_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_67_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_67_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_67_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_67_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_67_ADDRESS                                  0x0e8c
#define BB_TPC_GLUT_SRAM_67_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_67_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_67_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_67_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_67_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_67_RESET                                    0x00000000

// 0x0e90 (BB_TPC_GLUT_SRAM_68)
#define BB_TPC_GLUT_SRAM_68_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_68_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_68_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_68_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_68_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_68_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_68_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_68_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_68_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_68_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_68_ADDRESS                                  0x0e90
#define BB_TPC_GLUT_SRAM_68_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_68_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_68_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_68_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_68_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_68_RESET                                    0x00000000

// 0x0e94 (BB_TPC_GLUT_SRAM_69)
#define BB_TPC_GLUT_SRAM_69_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_69_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_69_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_69_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_69_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_69_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_69_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_69_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_69_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_69_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_69_ADDRESS                                  0x0e94
#define BB_TPC_GLUT_SRAM_69_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_69_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_69_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_69_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_69_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_69_RESET                                    0x00000000

// 0x0e98 (BB_TPC_GLUT_SRAM_70)
#define BB_TPC_GLUT_SRAM_70_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_70_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_70_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_70_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_70_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_70_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_70_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_70_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_70_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_70_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_70_ADDRESS                                  0x0e98
#define BB_TPC_GLUT_SRAM_70_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_70_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_70_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_70_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_70_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_70_RESET                                    0x00000000

// 0x0e9c (BB_TPC_GLUT_SRAM_71)
#define BB_TPC_GLUT_SRAM_71_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_71_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_71_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_71_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_71_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_71_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_71_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_71_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_71_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_71_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_71_ADDRESS                                  0x0e9c
#define BB_TPC_GLUT_SRAM_71_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_71_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_71_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_71_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_71_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_71_RESET                                    0x00000000

// 0x0ea0 (BB_TPC_GLUT_SRAM_72)
#define BB_TPC_GLUT_SRAM_72_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_72_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_72_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_72_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_72_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_72_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_72_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_72_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_72_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_72_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_72_ADDRESS                                  0x0ea0
#define BB_TPC_GLUT_SRAM_72_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_72_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_72_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_72_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_72_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_72_RESET                                    0x00000000

// 0x0ea4 (BB_TPC_GLUT_SRAM_73)
#define BB_TPC_GLUT_SRAM_73_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_73_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_73_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_73_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_73_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_73_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_73_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_73_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_73_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_73_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_73_ADDRESS                                  0x0ea4
#define BB_TPC_GLUT_SRAM_73_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_73_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_73_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_73_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_73_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_73_RESET                                    0x00000000

// 0x0ea8 (BB_TPC_GLUT_SRAM_74)
#define BB_TPC_GLUT_SRAM_74_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_74_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_74_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_74_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_74_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_74_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_74_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_74_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_74_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_74_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_74_ADDRESS                                  0x0ea8
#define BB_TPC_GLUT_SRAM_74_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_74_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_74_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_74_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_74_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_74_RESET                                    0x00000000

// 0x0eac (BB_TPC_GLUT_SRAM_75)
#define BB_TPC_GLUT_SRAM_75_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_75_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_75_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_75_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_75_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_75_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_75_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_75_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_75_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_75_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_75_ADDRESS                                  0x0eac
#define BB_TPC_GLUT_SRAM_75_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_75_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_75_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_75_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_75_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_75_RESET                                    0x00000000

// 0x0eb0 (BB_TPC_GLUT_SRAM_76)
#define BB_TPC_GLUT_SRAM_76_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_76_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_76_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_76_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_76_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_76_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_76_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_76_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_76_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_76_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_76_ADDRESS                                  0x0eb0
#define BB_TPC_GLUT_SRAM_76_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_76_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_76_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_76_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_76_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_76_RESET                                    0x00000000

// 0x0eb4 (BB_TPC_GLUT_SRAM_77)
#define BB_TPC_GLUT_SRAM_77_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_77_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_77_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_77_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_77_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_77_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_77_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_77_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_77_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_77_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_77_ADDRESS                                  0x0eb4
#define BB_TPC_GLUT_SRAM_77_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_77_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_77_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_77_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_77_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_77_RESET                                    0x00000000

// 0x0eb8 (BB_TPC_GLUT_SRAM_78)
#define BB_TPC_GLUT_SRAM_78_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_78_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_78_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_78_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_78_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_78_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_78_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_78_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_78_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_78_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_78_ADDRESS                                  0x0eb8
#define BB_TPC_GLUT_SRAM_78_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_78_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_78_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_78_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_78_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_78_RESET                                    0x00000000

// 0x0ebc (BB_TPC_GLUT_SRAM_79)
#define BB_TPC_GLUT_SRAM_79_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_79_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_79_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_79_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_79_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_79_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_79_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_79_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_79_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_79_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_79_ADDRESS                                  0x0ebc
#define BB_TPC_GLUT_SRAM_79_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_79_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_79_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_79_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_79_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_79_RESET                                    0x00000000

// 0x0ec0 (BB_TPC_GLUT_SRAM_80)
#define BB_TPC_GLUT_SRAM_80_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_80_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_80_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_80_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_80_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_80_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_80_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_80_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_80_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_80_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_80_ADDRESS                                  0x0ec0
#define BB_TPC_GLUT_SRAM_80_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_80_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_80_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_80_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_80_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_80_RESET                                    0x00000000

// 0x0ec4 (BB_TPC_GLUT_SRAM_81)
#define BB_TPC_GLUT_SRAM_81_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_81_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_81_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_81_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_81_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_81_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_81_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_81_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_81_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_81_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_81_ADDRESS                                  0x0ec4
#define BB_TPC_GLUT_SRAM_81_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_81_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_81_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_81_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_81_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_81_RESET                                    0x00000000

// 0x0ec8 (BB_TPC_GLUT_SRAM_82)
#define BB_TPC_GLUT_SRAM_82_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_82_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_82_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_82_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_82_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_82_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_82_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_82_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_82_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_82_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_82_ADDRESS                                  0x0ec8
#define BB_TPC_GLUT_SRAM_82_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_82_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_82_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_82_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_82_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_82_RESET                                    0x00000000

// 0x0ecc (BB_TPC_GLUT_SRAM_83)
#define BB_TPC_GLUT_SRAM_83_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_83_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_83_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_83_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_83_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_83_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_83_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_83_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_83_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_83_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_83_ADDRESS                                  0x0ecc
#define BB_TPC_GLUT_SRAM_83_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_83_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_83_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_83_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_83_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_83_RESET                                    0x00000000

// 0x0ed0 (BB_TPC_GLUT_SRAM_84)
#define BB_TPC_GLUT_SRAM_84_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_84_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_84_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_84_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_84_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_84_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_84_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_84_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_84_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_84_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_84_ADDRESS                                  0x0ed0
#define BB_TPC_GLUT_SRAM_84_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_84_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_84_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_84_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_84_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_84_RESET                                    0x00000000

// 0x0ed4 (BB_TPC_GLUT_SRAM_85)
#define BB_TPC_GLUT_SRAM_85_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_85_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_85_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_85_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_85_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_85_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_85_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_85_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_85_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_85_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_85_ADDRESS                                  0x0ed4
#define BB_TPC_GLUT_SRAM_85_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_85_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_85_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_85_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_85_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_85_RESET                                    0x00000000

// 0x0ed8 (BB_TPC_GLUT_SRAM_86)
#define BB_TPC_GLUT_SRAM_86_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_86_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_86_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_86_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_86_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_86_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_86_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_86_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_86_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_86_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_86_ADDRESS                                  0x0ed8
#define BB_TPC_GLUT_SRAM_86_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_86_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_86_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_86_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_86_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_86_RESET                                    0x00000000

// 0x0edc (BB_TPC_GLUT_SRAM_87)
#define BB_TPC_GLUT_SRAM_87_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_87_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_87_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_87_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_87_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_87_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_87_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_87_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_87_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_87_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_87_ADDRESS                                  0x0edc
#define BB_TPC_GLUT_SRAM_87_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_87_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_87_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_87_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_87_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_87_RESET                                    0x00000000

// 0x0ee0 (BB_TPC_GLUT_SRAM_88)
#define BB_TPC_GLUT_SRAM_88_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_88_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_88_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_88_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_88_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_88_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_88_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_88_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_88_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_88_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_88_ADDRESS                                  0x0ee0
#define BB_TPC_GLUT_SRAM_88_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_88_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_88_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_88_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_88_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_88_RESET                                    0x00000000

// 0x0ee4 (BB_TPC_GLUT_SRAM_89)
#define BB_TPC_GLUT_SRAM_89_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_89_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_89_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_89_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_89_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_89_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_89_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_89_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_89_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_89_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_89_ADDRESS                                  0x0ee4
#define BB_TPC_GLUT_SRAM_89_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_89_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_89_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_89_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_89_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_89_RESET                                    0x00000000

// 0x0ee8 (BB_TPC_GLUT_SRAM_90)
#define BB_TPC_GLUT_SRAM_90_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_90_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_90_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_90_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_90_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_90_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_90_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_90_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_90_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_90_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_90_ADDRESS                                  0x0ee8
#define BB_TPC_GLUT_SRAM_90_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_90_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_90_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_90_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_90_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_90_RESET                                    0x00000000

// 0x0eec (BB_TPC_GLUT_SRAM_91)
#define BB_TPC_GLUT_SRAM_91_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_91_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_91_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_91_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_91_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_91_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_91_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_91_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_91_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_91_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_91_ADDRESS                                  0x0eec
#define BB_TPC_GLUT_SRAM_91_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_91_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_91_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_91_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_91_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_91_RESET                                    0x00000000

// 0x0ef0 (BB_TPC_GLUT_SRAM_92)
#define BB_TPC_GLUT_SRAM_92_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_92_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_92_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_92_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_92_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_92_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_92_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_92_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_92_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_92_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_92_ADDRESS                                  0x0ef0
#define BB_TPC_GLUT_SRAM_92_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_92_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_92_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_92_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_92_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_92_RESET                                    0x00000000

// 0x0ef4 (BB_TPC_GLUT_SRAM_93)
#define BB_TPC_GLUT_SRAM_93_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_93_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_93_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_93_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_93_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_93_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_93_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_93_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_93_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_93_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_93_ADDRESS                                  0x0ef4
#define BB_TPC_GLUT_SRAM_93_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_93_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_93_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_93_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_93_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_93_RESET                                    0x00000000

// 0x0ef8 (BB_TPC_GLUT_SRAM_94)
#define BB_TPC_GLUT_SRAM_94_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_94_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_94_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_94_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_94_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_94_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_94_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_94_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_94_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_94_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_94_ADDRESS                                  0x0ef8
#define BB_TPC_GLUT_SRAM_94_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_94_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_94_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_94_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_94_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_94_RESET                                    0x00000000

// 0x0efc (BB_TPC_GLUT_SRAM_95)
#define BB_TPC_GLUT_SRAM_95_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_95_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_95_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_95_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_95_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_95_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_95_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_95_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_95_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_95_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_95_ADDRESS                                  0x0efc
#define BB_TPC_GLUT_SRAM_95_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_95_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_95_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_95_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_95_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_95_RESET                                    0x00000000

// 0x0f00 (BB_TPC_GLUT_SRAM_96)
#define BB_TPC_GLUT_SRAM_96_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_96_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_96_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_96_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_96_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_96_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_96_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_96_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_96_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_96_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_96_ADDRESS                                  0x0f00
#define BB_TPC_GLUT_SRAM_96_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_96_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_96_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_96_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_96_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_96_RESET                                    0x00000000

// 0x0f04 (BB_TPC_GLUT_SRAM_97)
#define BB_TPC_GLUT_SRAM_97_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_97_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_97_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_97_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_97_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_97_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_97_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_97_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_97_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_97_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_97_ADDRESS                                  0x0f04
#define BB_TPC_GLUT_SRAM_97_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_97_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_97_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_97_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_97_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_97_RESET                                    0x00000000

// 0x0f08 (BB_TPC_GLUT_SRAM_98)
#define BB_TPC_GLUT_SRAM_98_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_98_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_98_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_98_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_98_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_98_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_98_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_98_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_98_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_98_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_98_ADDRESS                                  0x0f08
#define BB_TPC_GLUT_SRAM_98_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_98_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_98_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_98_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_98_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_98_RESET                                    0x00000000

// 0x0f0c (BB_TPC_GLUT_SRAM_99)
#define BB_TPC_GLUT_SRAM_99_TPC_GLUT_WORD_MSB                        25
#define BB_TPC_GLUT_SRAM_99_TPC_GLUT_WORD_LSB                        0
#define BB_TPC_GLUT_SRAM_99_TPC_GLUT_WORD_MASK                       0x03ffffff
#define BB_TPC_GLUT_SRAM_99_TPC_GLUT_WORD_GET(x)                     (((x) & BB_TPC_GLUT_SRAM_99_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_99_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_99_TPC_GLUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_GLUT_SRAM_99_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_99_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_99_TPC_GLUT_WORD_RESET                      0
#define BB_TPC_GLUT_SRAM_99_ADDRESS                                  0x0f0c
#define BB_TPC_GLUT_SRAM_99_HW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_99_SW_MASK                                  0x03ffffff
#define BB_TPC_GLUT_SRAM_99_HW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_99_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_GLUT_SRAM_99_RSTMASK                                  0xfc000000
#define BB_TPC_GLUT_SRAM_99_RESET                                    0x00000000

// 0x0f10 (BB_TPC_GLUT_SRAM_100)
#define BB_TPC_GLUT_SRAM_100_TPC_GLUT_WORD_MSB                       25
#define BB_TPC_GLUT_SRAM_100_TPC_GLUT_WORD_LSB                       0
#define BB_TPC_GLUT_SRAM_100_TPC_GLUT_WORD_MASK                      0x03ffffff
#define BB_TPC_GLUT_SRAM_100_TPC_GLUT_WORD_GET(x)                    (((x) & BB_TPC_GLUT_SRAM_100_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_100_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_100_TPC_GLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_GLUT_SRAM_100_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_100_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_100_TPC_GLUT_WORD_RESET                     0
#define BB_TPC_GLUT_SRAM_100_ADDRESS                                 0x0f10
#define BB_TPC_GLUT_SRAM_100_HW_MASK                                 0x03ffffff
#define BB_TPC_GLUT_SRAM_100_SW_MASK                                 0x03ffffff
#define BB_TPC_GLUT_SRAM_100_HW_WRITE_MASK                           0x03ffffff
#define BB_TPC_GLUT_SRAM_100_SW_WRITE_MASK                           0x03ffffff
#define BB_TPC_GLUT_SRAM_100_RSTMASK                                 0xfc000000
#define BB_TPC_GLUT_SRAM_100_RESET                                   0x00000000

// 0x0f14 (BB_TPC_GLUT_SRAM_101)
#define BB_TPC_GLUT_SRAM_101_TPC_GLUT_WORD_MSB                       25
#define BB_TPC_GLUT_SRAM_101_TPC_GLUT_WORD_LSB                       0
#define BB_TPC_GLUT_SRAM_101_TPC_GLUT_WORD_MASK                      0x03ffffff
#define BB_TPC_GLUT_SRAM_101_TPC_GLUT_WORD_GET(x)                    (((x) & BB_TPC_GLUT_SRAM_101_TPC_GLUT_WORD_MASK) >> BB_TPC_GLUT_SRAM_101_TPC_GLUT_WORD_LSB)
#define BB_TPC_GLUT_SRAM_101_TPC_GLUT_WORD_SET(x)                    (((0 | (x)) << BB_TPC_GLUT_SRAM_101_TPC_GLUT_WORD_LSB) & BB_TPC_GLUT_SRAM_101_TPC_GLUT_WORD_MASK)
#define BB_TPC_GLUT_SRAM_101_TPC_GLUT_WORD_RESET                     0
#define BB_TPC_GLUT_SRAM_101_ADDRESS                                 0x0f14
#define BB_TPC_GLUT_SRAM_101_HW_MASK                                 0x03ffffff
#define BB_TPC_GLUT_SRAM_101_SW_MASK                                 0x03ffffff
#define BB_TPC_GLUT_SRAM_101_HW_WRITE_MASK                           0x03ffffff
#define BB_TPC_GLUT_SRAM_101_SW_WRITE_MASK                           0x03ffffff
#define BB_TPC_GLUT_SRAM_101_RSTMASK                                 0xfc000000
#define BB_TPC_GLUT_SRAM_101_RESET                                   0x00000000

// 0x0f20 (BB_TPC_ALUT_SRAM_0)
#define BB_TPC_ALUT_SRAM_0_TPC_ALUT_WORD_MSB                         25
#define BB_TPC_ALUT_SRAM_0_TPC_ALUT_WORD_LSB                         0
#define BB_TPC_ALUT_SRAM_0_TPC_ALUT_WORD_MASK                        0x03ffffff
#define BB_TPC_ALUT_SRAM_0_TPC_ALUT_WORD_GET(x)                      (((x) & BB_TPC_ALUT_SRAM_0_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_0_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_0_TPC_ALUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_ALUT_SRAM_0_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_0_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_0_TPC_ALUT_WORD_RESET                       0
#define BB_TPC_ALUT_SRAM_0_ADDRESS                                   0x0f20
#define BB_TPC_ALUT_SRAM_ADDRESS                                     BB_TPC_ALUT_SRAM_0_ADDRESS
#define BB_TPC_ALUT_SRAM_0_HW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_0_SW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_0_HW_WRITE_MASK                             0x00000000
#define BB_TPC_ALUT_SRAM_0_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_ALUT_SRAM_0_RSTMASK                                   0xfc000000
#define BB_TPC_ALUT_SRAM_0_RESET                                     0x00000000

// 0x0f24 (BB_TPC_ALUT_SRAM_1)
#define BB_TPC_ALUT_SRAM_1_TPC_ALUT_WORD_MSB                         25
#define BB_TPC_ALUT_SRAM_1_TPC_ALUT_WORD_LSB                         0
#define BB_TPC_ALUT_SRAM_1_TPC_ALUT_WORD_MASK                        0x03ffffff
#define BB_TPC_ALUT_SRAM_1_TPC_ALUT_WORD_GET(x)                      (((x) & BB_TPC_ALUT_SRAM_1_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_1_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_1_TPC_ALUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_ALUT_SRAM_1_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_1_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_1_TPC_ALUT_WORD_RESET                       0
#define BB_TPC_ALUT_SRAM_1_ADDRESS                                   0x0f24
#define BB_TPC_ALUT_SRAM_1_HW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_1_SW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_1_HW_WRITE_MASK                             0x00000000
#define BB_TPC_ALUT_SRAM_1_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_ALUT_SRAM_1_RSTMASK                                   0xfc000000
#define BB_TPC_ALUT_SRAM_1_RESET                                     0x00000000

// 0x0f28 (BB_TPC_ALUT_SRAM_2)
#define BB_TPC_ALUT_SRAM_2_TPC_ALUT_WORD_MSB                         25
#define BB_TPC_ALUT_SRAM_2_TPC_ALUT_WORD_LSB                         0
#define BB_TPC_ALUT_SRAM_2_TPC_ALUT_WORD_MASK                        0x03ffffff
#define BB_TPC_ALUT_SRAM_2_TPC_ALUT_WORD_GET(x)                      (((x) & BB_TPC_ALUT_SRAM_2_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_2_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_2_TPC_ALUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_ALUT_SRAM_2_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_2_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_2_TPC_ALUT_WORD_RESET                       0
#define BB_TPC_ALUT_SRAM_2_ADDRESS                                   0x0f28
#define BB_TPC_ALUT_SRAM_2_HW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_2_SW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_2_HW_WRITE_MASK                             0x00000000
#define BB_TPC_ALUT_SRAM_2_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_ALUT_SRAM_2_RSTMASK                                   0xfc000000
#define BB_TPC_ALUT_SRAM_2_RESET                                     0x00000000

// 0x0f2c (BB_TPC_ALUT_SRAM_3)
#define BB_TPC_ALUT_SRAM_3_TPC_ALUT_WORD_MSB                         25
#define BB_TPC_ALUT_SRAM_3_TPC_ALUT_WORD_LSB                         0
#define BB_TPC_ALUT_SRAM_3_TPC_ALUT_WORD_MASK                        0x03ffffff
#define BB_TPC_ALUT_SRAM_3_TPC_ALUT_WORD_GET(x)                      (((x) & BB_TPC_ALUT_SRAM_3_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_3_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_3_TPC_ALUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_ALUT_SRAM_3_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_3_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_3_TPC_ALUT_WORD_RESET                       0
#define BB_TPC_ALUT_SRAM_3_ADDRESS                                   0x0f2c
#define BB_TPC_ALUT_SRAM_3_HW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_3_SW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_3_HW_WRITE_MASK                             0x00000000
#define BB_TPC_ALUT_SRAM_3_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_ALUT_SRAM_3_RSTMASK                                   0xfc000000
#define BB_TPC_ALUT_SRAM_3_RESET                                     0x00000000

// 0x0f30 (BB_TPC_ALUT_SRAM_4)
#define BB_TPC_ALUT_SRAM_4_TPC_ALUT_WORD_MSB                         25
#define BB_TPC_ALUT_SRAM_4_TPC_ALUT_WORD_LSB                         0
#define BB_TPC_ALUT_SRAM_4_TPC_ALUT_WORD_MASK                        0x03ffffff
#define BB_TPC_ALUT_SRAM_4_TPC_ALUT_WORD_GET(x)                      (((x) & BB_TPC_ALUT_SRAM_4_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_4_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_4_TPC_ALUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_ALUT_SRAM_4_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_4_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_4_TPC_ALUT_WORD_RESET                       0
#define BB_TPC_ALUT_SRAM_4_ADDRESS                                   0x0f30
#define BB_TPC_ALUT_SRAM_4_HW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_4_SW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_4_HW_WRITE_MASK                             0x00000000
#define BB_TPC_ALUT_SRAM_4_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_ALUT_SRAM_4_RSTMASK                                   0xfc000000
#define BB_TPC_ALUT_SRAM_4_RESET                                     0x00000000

// 0x0f34 (BB_TPC_ALUT_SRAM_5)
#define BB_TPC_ALUT_SRAM_5_TPC_ALUT_WORD_MSB                         25
#define BB_TPC_ALUT_SRAM_5_TPC_ALUT_WORD_LSB                         0
#define BB_TPC_ALUT_SRAM_5_TPC_ALUT_WORD_MASK                        0x03ffffff
#define BB_TPC_ALUT_SRAM_5_TPC_ALUT_WORD_GET(x)                      (((x) & BB_TPC_ALUT_SRAM_5_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_5_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_5_TPC_ALUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_ALUT_SRAM_5_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_5_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_5_TPC_ALUT_WORD_RESET                       0
#define BB_TPC_ALUT_SRAM_5_ADDRESS                                   0x0f34
#define BB_TPC_ALUT_SRAM_5_HW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_5_SW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_5_HW_WRITE_MASK                             0x00000000
#define BB_TPC_ALUT_SRAM_5_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_ALUT_SRAM_5_RSTMASK                                   0xfc000000
#define BB_TPC_ALUT_SRAM_5_RESET                                     0x00000000

// 0x0f38 (BB_TPC_ALUT_SRAM_6)
#define BB_TPC_ALUT_SRAM_6_TPC_ALUT_WORD_MSB                         25
#define BB_TPC_ALUT_SRAM_6_TPC_ALUT_WORD_LSB                         0
#define BB_TPC_ALUT_SRAM_6_TPC_ALUT_WORD_MASK                        0x03ffffff
#define BB_TPC_ALUT_SRAM_6_TPC_ALUT_WORD_GET(x)                      (((x) & BB_TPC_ALUT_SRAM_6_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_6_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_6_TPC_ALUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_ALUT_SRAM_6_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_6_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_6_TPC_ALUT_WORD_RESET                       0
#define BB_TPC_ALUT_SRAM_6_ADDRESS                                   0x0f38
#define BB_TPC_ALUT_SRAM_6_HW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_6_SW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_6_HW_WRITE_MASK                             0x00000000
#define BB_TPC_ALUT_SRAM_6_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_ALUT_SRAM_6_RSTMASK                                   0xfc000000
#define BB_TPC_ALUT_SRAM_6_RESET                                     0x00000000

// 0x0f3c (BB_TPC_ALUT_SRAM_7)
#define BB_TPC_ALUT_SRAM_7_TPC_ALUT_WORD_MSB                         25
#define BB_TPC_ALUT_SRAM_7_TPC_ALUT_WORD_LSB                         0
#define BB_TPC_ALUT_SRAM_7_TPC_ALUT_WORD_MASK                        0x03ffffff
#define BB_TPC_ALUT_SRAM_7_TPC_ALUT_WORD_GET(x)                      (((x) & BB_TPC_ALUT_SRAM_7_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_7_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_7_TPC_ALUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_ALUT_SRAM_7_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_7_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_7_TPC_ALUT_WORD_RESET                       0
#define BB_TPC_ALUT_SRAM_7_ADDRESS                                   0x0f3c
#define BB_TPC_ALUT_SRAM_7_HW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_7_SW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_7_HW_WRITE_MASK                             0x00000000
#define BB_TPC_ALUT_SRAM_7_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_ALUT_SRAM_7_RSTMASK                                   0xfc000000
#define BB_TPC_ALUT_SRAM_7_RESET                                     0x00000000

// 0x0f40 (BB_TPC_ALUT_SRAM_8)
#define BB_TPC_ALUT_SRAM_8_TPC_ALUT_WORD_MSB                         25
#define BB_TPC_ALUT_SRAM_8_TPC_ALUT_WORD_LSB                         0
#define BB_TPC_ALUT_SRAM_8_TPC_ALUT_WORD_MASK                        0x03ffffff
#define BB_TPC_ALUT_SRAM_8_TPC_ALUT_WORD_GET(x)                      (((x) & BB_TPC_ALUT_SRAM_8_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_8_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_8_TPC_ALUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_ALUT_SRAM_8_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_8_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_8_TPC_ALUT_WORD_RESET                       0
#define BB_TPC_ALUT_SRAM_8_ADDRESS                                   0x0f40
#define BB_TPC_ALUT_SRAM_8_HW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_8_SW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_8_HW_WRITE_MASK                             0x00000000
#define BB_TPC_ALUT_SRAM_8_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_ALUT_SRAM_8_RSTMASK                                   0xfc000000
#define BB_TPC_ALUT_SRAM_8_RESET                                     0x00000000

// 0x0f44 (BB_TPC_ALUT_SRAM_9)
#define BB_TPC_ALUT_SRAM_9_TPC_ALUT_WORD_MSB                         25
#define BB_TPC_ALUT_SRAM_9_TPC_ALUT_WORD_LSB                         0
#define BB_TPC_ALUT_SRAM_9_TPC_ALUT_WORD_MASK                        0x03ffffff
#define BB_TPC_ALUT_SRAM_9_TPC_ALUT_WORD_GET(x)                      (((x) & BB_TPC_ALUT_SRAM_9_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_9_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_9_TPC_ALUT_WORD_SET(x)                      (((0 | (x)) << BB_TPC_ALUT_SRAM_9_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_9_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_9_TPC_ALUT_WORD_RESET                       0
#define BB_TPC_ALUT_SRAM_9_ADDRESS                                   0x0f44
#define BB_TPC_ALUT_SRAM_9_HW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_9_SW_MASK                                   0x03ffffff
#define BB_TPC_ALUT_SRAM_9_HW_WRITE_MASK                             0x00000000
#define BB_TPC_ALUT_SRAM_9_SW_WRITE_MASK                             0x03ffffff
#define BB_TPC_ALUT_SRAM_9_RSTMASK                                   0xfc000000
#define BB_TPC_ALUT_SRAM_9_RESET                                     0x00000000

// 0x0f48 (BB_TPC_ALUT_SRAM_10)
#define BB_TPC_ALUT_SRAM_10_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_10_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_10_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_10_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_10_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_10_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_10_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_10_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_10_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_10_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_10_ADDRESS                                  0x0f48
#define BB_TPC_ALUT_SRAM_10_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_10_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_10_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_10_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_10_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_10_RESET                                    0x00000000

// 0x0f4c (BB_TPC_ALUT_SRAM_11)
#define BB_TPC_ALUT_SRAM_11_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_11_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_11_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_11_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_11_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_11_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_11_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_11_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_11_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_11_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_11_ADDRESS                                  0x0f4c
#define BB_TPC_ALUT_SRAM_11_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_11_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_11_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_11_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_11_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_11_RESET                                    0x00000000

// 0x0f50 (BB_TPC_ALUT_SRAM_12)
#define BB_TPC_ALUT_SRAM_12_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_12_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_12_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_12_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_12_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_12_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_12_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_12_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_12_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_12_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_12_ADDRESS                                  0x0f50
#define BB_TPC_ALUT_SRAM_12_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_12_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_12_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_12_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_12_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_12_RESET                                    0x00000000

// 0x0f54 (BB_TPC_ALUT_SRAM_13)
#define BB_TPC_ALUT_SRAM_13_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_13_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_13_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_13_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_13_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_13_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_13_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_13_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_13_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_13_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_13_ADDRESS                                  0x0f54
#define BB_TPC_ALUT_SRAM_13_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_13_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_13_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_13_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_13_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_13_RESET                                    0x00000000

// 0x0f58 (BB_TPC_ALUT_SRAM_14)
#define BB_TPC_ALUT_SRAM_14_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_14_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_14_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_14_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_14_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_14_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_14_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_14_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_14_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_14_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_14_ADDRESS                                  0x0f58
#define BB_TPC_ALUT_SRAM_14_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_14_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_14_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_14_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_14_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_14_RESET                                    0x00000000

// 0x0f5c (BB_TPC_ALUT_SRAM_15)
#define BB_TPC_ALUT_SRAM_15_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_15_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_15_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_15_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_15_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_15_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_15_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_15_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_15_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_15_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_15_ADDRESS                                  0x0f5c
#define BB_TPC_ALUT_SRAM_15_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_15_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_15_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_15_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_15_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_15_RESET                                    0x00000000

// 0x0f60 (BB_TPC_ALUT_SRAM_16)
#define BB_TPC_ALUT_SRAM_16_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_16_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_16_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_16_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_16_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_16_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_16_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_16_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_16_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_16_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_16_ADDRESS                                  0x0f60
#define BB_TPC_ALUT_SRAM_16_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_16_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_16_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_16_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_16_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_16_RESET                                    0x00000000

// 0x0f64 (BB_TPC_ALUT_SRAM_17)
#define BB_TPC_ALUT_SRAM_17_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_17_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_17_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_17_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_17_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_17_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_17_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_17_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_17_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_17_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_17_ADDRESS                                  0x0f64
#define BB_TPC_ALUT_SRAM_17_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_17_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_17_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_17_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_17_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_17_RESET                                    0x00000000

// 0x0f68 (BB_TPC_ALUT_SRAM_18)
#define BB_TPC_ALUT_SRAM_18_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_18_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_18_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_18_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_18_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_18_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_18_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_18_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_18_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_18_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_18_ADDRESS                                  0x0f68
#define BB_TPC_ALUT_SRAM_18_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_18_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_18_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_18_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_18_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_18_RESET                                    0x00000000

// 0x0f6c (BB_TPC_ALUT_SRAM_19)
#define BB_TPC_ALUT_SRAM_19_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_19_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_19_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_19_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_19_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_19_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_19_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_19_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_19_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_19_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_19_ADDRESS                                  0x0f6c
#define BB_TPC_ALUT_SRAM_19_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_19_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_19_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_19_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_19_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_19_RESET                                    0x00000000

// 0x0f70 (BB_TPC_ALUT_SRAM_20)
#define BB_TPC_ALUT_SRAM_20_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_20_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_20_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_20_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_20_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_20_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_20_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_20_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_20_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_20_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_20_ADDRESS                                  0x0f70
#define BB_TPC_ALUT_SRAM_20_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_20_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_20_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_20_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_20_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_20_RESET                                    0x00000000

// 0x0f74 (BB_TPC_ALUT_SRAM_21)
#define BB_TPC_ALUT_SRAM_21_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_21_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_21_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_21_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_21_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_21_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_21_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_21_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_21_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_21_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_21_ADDRESS                                  0x0f74
#define BB_TPC_ALUT_SRAM_21_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_21_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_21_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_21_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_21_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_21_RESET                                    0x00000000

// 0x0f78 (BB_TPC_ALUT_SRAM_22)
#define BB_TPC_ALUT_SRAM_22_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_22_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_22_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_22_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_22_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_22_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_22_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_22_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_22_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_22_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_22_ADDRESS                                  0x0f78
#define BB_TPC_ALUT_SRAM_22_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_22_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_22_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_22_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_22_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_22_RESET                                    0x00000000

// 0x0f7c (BB_TPC_ALUT_SRAM_23)
#define BB_TPC_ALUT_SRAM_23_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_23_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_23_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_23_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_23_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_23_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_23_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_23_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_23_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_23_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_23_ADDRESS                                  0x0f7c
#define BB_TPC_ALUT_SRAM_23_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_23_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_23_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_23_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_23_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_23_RESET                                    0x00000000

// 0x0f80 (BB_TPC_ALUT_SRAM_24)
#define BB_TPC_ALUT_SRAM_24_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_24_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_24_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_24_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_24_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_24_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_24_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_24_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_24_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_24_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_24_ADDRESS                                  0x0f80
#define BB_TPC_ALUT_SRAM_24_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_24_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_24_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_24_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_24_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_24_RESET                                    0x00000000

// 0x0f84 (BB_TPC_ALUT_SRAM_25)
#define BB_TPC_ALUT_SRAM_25_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_25_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_25_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_25_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_25_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_25_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_25_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_25_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_25_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_25_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_25_ADDRESS                                  0x0f84
#define BB_TPC_ALUT_SRAM_25_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_25_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_25_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_25_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_25_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_25_RESET                                    0x00000000

// 0x0f88 (BB_TPC_ALUT_SRAM_26)
#define BB_TPC_ALUT_SRAM_26_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_26_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_26_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_26_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_26_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_26_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_26_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_26_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_26_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_26_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_26_ADDRESS                                  0x0f88
#define BB_TPC_ALUT_SRAM_26_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_26_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_26_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_26_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_26_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_26_RESET                                    0x00000000

// 0x0f8c (BB_TPC_ALUT_SRAM_27)
#define BB_TPC_ALUT_SRAM_27_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_27_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_27_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_27_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_27_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_27_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_27_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_27_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_27_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_27_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_27_ADDRESS                                  0x0f8c
#define BB_TPC_ALUT_SRAM_27_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_27_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_27_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_27_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_27_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_27_RESET                                    0x00000000

// 0x0f90 (BB_TPC_ALUT_SRAM_28)
#define BB_TPC_ALUT_SRAM_28_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_28_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_28_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_28_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_28_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_28_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_28_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_28_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_28_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_28_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_28_ADDRESS                                  0x0f90
#define BB_TPC_ALUT_SRAM_28_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_28_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_28_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_28_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_28_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_28_RESET                                    0x00000000

// 0x0f94 (BB_TPC_ALUT_SRAM_29)
#define BB_TPC_ALUT_SRAM_29_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_29_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_29_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_29_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_29_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_29_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_29_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_29_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_29_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_29_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_29_ADDRESS                                  0x0f94
#define BB_TPC_ALUT_SRAM_29_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_29_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_29_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_29_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_29_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_29_RESET                                    0x00000000

// 0x0f98 (BB_TPC_ALUT_SRAM_30)
#define BB_TPC_ALUT_SRAM_30_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_30_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_30_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_30_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_30_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_30_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_30_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_30_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_30_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_30_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_30_ADDRESS                                  0x0f98
#define BB_TPC_ALUT_SRAM_30_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_30_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_30_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_30_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_30_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_30_RESET                                    0x00000000

// 0x0f9c (BB_TPC_ALUT_SRAM_31)
#define BB_TPC_ALUT_SRAM_31_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_31_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_31_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_31_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_31_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_31_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_31_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_31_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_31_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_31_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_31_ADDRESS                                  0x0f9c
#define BB_TPC_ALUT_SRAM_31_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_31_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_31_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_31_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_31_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_31_RESET                                    0x00000000

// 0x0fa0 (BB_TPC_ALUT_SRAM_32)
#define BB_TPC_ALUT_SRAM_32_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_32_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_32_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_32_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_32_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_32_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_32_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_32_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_32_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_32_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_32_ADDRESS                                  0x0fa0
#define BB_TPC_ALUT_SRAM_32_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_32_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_32_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_32_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_32_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_32_RESET                                    0x00000000

// 0x0fa4 (BB_TPC_ALUT_SRAM_33)
#define BB_TPC_ALUT_SRAM_33_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_33_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_33_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_33_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_33_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_33_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_33_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_33_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_33_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_33_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_33_ADDRESS                                  0x0fa4
#define BB_TPC_ALUT_SRAM_33_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_33_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_33_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_33_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_33_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_33_RESET                                    0x00000000

// 0x0fa8 (BB_TPC_ALUT_SRAM_34)
#define BB_TPC_ALUT_SRAM_34_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_34_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_34_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_34_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_34_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_34_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_34_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_34_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_34_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_34_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_34_ADDRESS                                  0x0fa8
#define BB_TPC_ALUT_SRAM_34_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_34_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_34_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_34_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_34_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_34_RESET                                    0x00000000

// 0x0fac (BB_TPC_ALUT_SRAM_35)
#define BB_TPC_ALUT_SRAM_35_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_35_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_35_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_35_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_35_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_35_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_35_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_35_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_35_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_35_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_35_ADDRESS                                  0x0fac
#define BB_TPC_ALUT_SRAM_35_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_35_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_35_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_35_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_35_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_35_RESET                                    0x00000000

// 0x0fb0 (BB_TPC_ALUT_SRAM_36)
#define BB_TPC_ALUT_SRAM_36_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_36_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_36_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_36_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_36_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_36_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_36_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_36_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_36_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_36_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_36_ADDRESS                                  0x0fb0
#define BB_TPC_ALUT_SRAM_36_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_36_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_36_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_36_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_36_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_36_RESET                                    0x00000000

// 0x0fb4 (BB_TPC_ALUT_SRAM_37)
#define BB_TPC_ALUT_SRAM_37_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_37_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_37_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_37_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_37_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_37_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_37_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_37_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_37_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_37_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_37_ADDRESS                                  0x0fb4
#define BB_TPC_ALUT_SRAM_37_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_37_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_37_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_37_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_37_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_37_RESET                                    0x00000000

// 0x0fb8 (BB_TPC_ALUT_SRAM_38)
#define BB_TPC_ALUT_SRAM_38_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_38_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_38_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_38_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_38_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_38_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_38_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_38_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_38_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_38_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_38_ADDRESS                                  0x0fb8
#define BB_TPC_ALUT_SRAM_38_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_38_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_38_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_38_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_38_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_38_RESET                                    0x00000000

// 0x0fbc (BB_TPC_ALUT_SRAM_39)
#define BB_TPC_ALUT_SRAM_39_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_39_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_39_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_39_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_39_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_39_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_39_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_39_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_39_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_39_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_39_ADDRESS                                  0x0fbc
#define BB_TPC_ALUT_SRAM_39_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_39_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_39_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_39_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_39_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_39_RESET                                    0x00000000

// 0x0fc0 (BB_TPC_ALUT_SRAM_40)
#define BB_TPC_ALUT_SRAM_40_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_40_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_40_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_40_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_40_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_40_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_40_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_40_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_40_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_40_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_40_ADDRESS                                  0x0fc0
#define BB_TPC_ALUT_SRAM_40_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_40_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_40_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_40_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_40_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_40_RESET                                    0x00000000

// 0x0fc4 (BB_TPC_ALUT_SRAM_41)
#define BB_TPC_ALUT_SRAM_41_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_41_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_41_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_41_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_41_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_41_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_41_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_41_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_41_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_41_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_41_ADDRESS                                  0x0fc4
#define BB_TPC_ALUT_SRAM_41_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_41_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_41_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_41_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_41_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_41_RESET                                    0x00000000

// 0x0fc8 (BB_TPC_ALUT_SRAM_42)
#define BB_TPC_ALUT_SRAM_42_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_42_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_42_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_42_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_42_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_42_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_42_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_42_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_42_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_42_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_42_ADDRESS                                  0x0fc8
#define BB_TPC_ALUT_SRAM_42_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_42_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_42_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_42_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_42_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_42_RESET                                    0x00000000

// 0x0fcc (BB_TPC_ALUT_SRAM_43)
#define BB_TPC_ALUT_SRAM_43_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_43_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_43_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_43_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_43_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_43_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_43_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_43_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_43_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_43_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_43_ADDRESS                                  0x0fcc
#define BB_TPC_ALUT_SRAM_43_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_43_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_43_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_43_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_43_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_43_RESET                                    0x00000000

// 0x0fd0 (BB_TPC_ALUT_SRAM_44)
#define BB_TPC_ALUT_SRAM_44_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_44_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_44_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_44_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_44_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_44_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_44_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_44_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_44_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_44_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_44_ADDRESS                                  0x0fd0
#define BB_TPC_ALUT_SRAM_44_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_44_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_44_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_44_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_44_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_44_RESET                                    0x00000000

// 0x0fd4 (BB_TPC_ALUT_SRAM_45)
#define BB_TPC_ALUT_SRAM_45_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_45_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_45_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_45_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_45_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_45_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_45_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_45_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_45_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_45_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_45_ADDRESS                                  0x0fd4
#define BB_TPC_ALUT_SRAM_45_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_45_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_45_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_45_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_45_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_45_RESET                                    0x00000000

// 0x0fd8 (BB_TPC_ALUT_SRAM_46)
#define BB_TPC_ALUT_SRAM_46_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_46_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_46_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_46_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_46_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_46_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_46_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_46_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_46_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_46_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_46_ADDRESS                                  0x0fd8
#define BB_TPC_ALUT_SRAM_46_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_46_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_46_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_46_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_46_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_46_RESET                                    0x00000000

// 0x0fdc (BB_TPC_ALUT_SRAM_47)
#define BB_TPC_ALUT_SRAM_47_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_47_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_47_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_47_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_47_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_47_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_47_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_47_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_47_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_47_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_47_ADDRESS                                  0x0fdc
#define BB_TPC_ALUT_SRAM_47_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_47_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_47_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_47_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_47_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_47_RESET                                    0x00000000

// 0x0fe0 (BB_TPC_ALUT_SRAM_48)
#define BB_TPC_ALUT_SRAM_48_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_48_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_48_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_48_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_48_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_48_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_48_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_48_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_48_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_48_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_48_ADDRESS                                  0x0fe0
#define BB_TPC_ALUT_SRAM_48_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_48_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_48_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_48_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_48_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_48_RESET                                    0x00000000

// 0x0fe4 (BB_TPC_ALUT_SRAM_49)
#define BB_TPC_ALUT_SRAM_49_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_49_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_49_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_49_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_49_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_49_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_49_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_49_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_49_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_49_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_49_ADDRESS                                  0x0fe4
#define BB_TPC_ALUT_SRAM_49_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_49_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_49_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_49_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_49_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_49_RESET                                    0x00000000

// 0x0fe8 (BB_TPC_ALUT_SRAM_50)
#define BB_TPC_ALUT_SRAM_50_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_50_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_50_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_50_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_50_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_50_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_50_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_50_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_50_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_50_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_50_ADDRESS                                  0x0fe8
#define BB_TPC_ALUT_SRAM_50_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_50_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_50_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_50_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_50_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_50_RESET                                    0x00000000

// 0x0fec (BB_TPC_ALUT_SRAM_51)
#define BB_TPC_ALUT_SRAM_51_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_51_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_51_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_51_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_51_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_51_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_51_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_51_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_51_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_51_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_51_ADDRESS                                  0x0fec
#define BB_TPC_ALUT_SRAM_51_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_51_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_51_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_51_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_51_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_51_RESET                                    0x00000000

// 0x0ff0 (BB_TPC_ALUT_SRAM_52)
#define BB_TPC_ALUT_SRAM_52_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_52_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_52_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_52_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_52_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_52_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_52_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_52_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_52_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_52_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_52_ADDRESS                                  0x0ff0
#define BB_TPC_ALUT_SRAM_52_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_52_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_52_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_52_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_52_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_52_RESET                                    0x00000000

// 0x0ff4 (BB_TPC_ALUT_SRAM_53)
#define BB_TPC_ALUT_SRAM_53_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_53_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_53_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_53_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_53_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_53_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_53_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_53_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_53_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_53_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_53_ADDRESS                                  0x0ff4
#define BB_TPC_ALUT_SRAM_53_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_53_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_53_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_53_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_53_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_53_RESET                                    0x00000000

// 0x0ff8 (BB_TPC_ALUT_SRAM_54)
#define BB_TPC_ALUT_SRAM_54_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_54_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_54_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_54_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_54_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_54_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_54_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_54_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_54_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_54_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_54_ADDRESS                                  0x0ff8
#define BB_TPC_ALUT_SRAM_54_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_54_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_54_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_54_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_54_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_54_RESET                                    0x00000000

// 0x0ffc (BB_TPC_ALUT_SRAM_55)
#define BB_TPC_ALUT_SRAM_55_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_55_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_55_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_55_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_55_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_55_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_55_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_55_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_55_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_55_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_55_ADDRESS                                  0x0ffc
#define BB_TPC_ALUT_SRAM_55_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_55_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_55_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_55_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_55_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_55_RESET                                    0x00000000

// 0x1000 (BB_TPC_ALUT_SRAM_56)
#define BB_TPC_ALUT_SRAM_56_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_56_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_56_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_56_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_56_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_56_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_56_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_56_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_56_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_56_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_56_ADDRESS                                  0x1000
#define BB_TPC_ALUT_SRAM_56_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_56_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_56_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_56_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_56_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_56_RESET                                    0x00000000

// 0x1004 (BB_TPC_ALUT_SRAM_57)
#define BB_TPC_ALUT_SRAM_57_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_57_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_57_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_57_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_57_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_57_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_57_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_57_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_57_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_57_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_57_ADDRESS                                  0x1004
#define BB_TPC_ALUT_SRAM_57_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_57_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_57_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_57_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_57_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_57_RESET                                    0x00000000

// 0x1008 (BB_TPC_ALUT_SRAM_58)
#define BB_TPC_ALUT_SRAM_58_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_58_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_58_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_58_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_58_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_58_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_58_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_58_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_58_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_58_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_58_ADDRESS                                  0x1008
#define BB_TPC_ALUT_SRAM_58_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_58_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_58_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_58_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_58_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_58_RESET                                    0x00000000

// 0x100c (BB_TPC_ALUT_SRAM_59)
#define BB_TPC_ALUT_SRAM_59_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_59_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_59_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_59_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_59_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_59_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_59_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_59_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_59_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_59_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_59_ADDRESS                                  0x100c
#define BB_TPC_ALUT_SRAM_59_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_59_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_59_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_59_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_59_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_59_RESET                                    0x00000000

// 0x1010 (BB_TPC_ALUT_SRAM_60)
#define BB_TPC_ALUT_SRAM_60_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_60_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_60_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_60_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_60_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_60_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_60_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_60_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_60_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_60_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_60_ADDRESS                                  0x1010
#define BB_TPC_ALUT_SRAM_60_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_60_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_60_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_60_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_60_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_60_RESET                                    0x00000000

// 0x1014 (BB_TPC_ALUT_SRAM_61)
#define BB_TPC_ALUT_SRAM_61_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_61_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_61_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_61_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_61_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_61_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_61_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_61_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_61_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_61_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_61_ADDRESS                                  0x1014
#define BB_TPC_ALUT_SRAM_61_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_61_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_61_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_61_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_61_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_61_RESET                                    0x00000000

// 0x1018 (BB_TPC_ALUT_SRAM_62)
#define BB_TPC_ALUT_SRAM_62_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_62_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_62_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_62_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_62_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_62_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_62_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_62_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_62_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_62_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_62_ADDRESS                                  0x1018
#define BB_TPC_ALUT_SRAM_62_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_62_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_62_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_62_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_62_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_62_RESET                                    0x00000000

// 0x101c (BB_TPC_ALUT_SRAM_63)
#define BB_TPC_ALUT_SRAM_63_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_63_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_63_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_63_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_63_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_63_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_63_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_63_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_63_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_63_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_63_ADDRESS                                  0x101c
#define BB_TPC_ALUT_SRAM_63_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_63_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_63_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_63_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_63_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_63_RESET                                    0x00000000

// 0x1020 (BB_TPC_ALUT_SRAM_64)
#define BB_TPC_ALUT_SRAM_64_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_64_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_64_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_64_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_64_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_64_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_64_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_64_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_64_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_64_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_64_ADDRESS                                  0x1020
#define BB_TPC_ALUT_SRAM_64_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_64_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_64_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_64_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_64_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_64_RESET                                    0x00000000

// 0x1024 (BB_TPC_ALUT_SRAM_65)
#define BB_TPC_ALUT_SRAM_65_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_65_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_65_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_65_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_65_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_65_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_65_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_65_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_65_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_65_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_65_ADDRESS                                  0x1024
#define BB_TPC_ALUT_SRAM_65_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_65_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_65_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_65_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_65_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_65_RESET                                    0x00000000

// 0x1028 (BB_TPC_ALUT_SRAM_66)
#define BB_TPC_ALUT_SRAM_66_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_66_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_66_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_66_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_66_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_66_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_66_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_66_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_66_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_66_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_66_ADDRESS                                  0x1028
#define BB_TPC_ALUT_SRAM_66_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_66_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_66_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_66_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_66_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_66_RESET                                    0x00000000

// 0x102c (BB_TPC_ALUT_SRAM_67)
#define BB_TPC_ALUT_SRAM_67_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_67_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_67_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_67_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_67_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_67_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_67_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_67_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_67_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_67_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_67_ADDRESS                                  0x102c
#define BB_TPC_ALUT_SRAM_67_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_67_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_67_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_67_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_67_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_67_RESET                                    0x00000000

// 0x1030 (BB_TPC_ALUT_SRAM_68)
#define BB_TPC_ALUT_SRAM_68_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_68_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_68_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_68_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_68_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_68_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_68_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_68_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_68_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_68_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_68_ADDRESS                                  0x1030
#define BB_TPC_ALUT_SRAM_68_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_68_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_68_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_68_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_68_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_68_RESET                                    0x00000000

// 0x1034 (BB_TPC_ALUT_SRAM_69)
#define BB_TPC_ALUT_SRAM_69_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_69_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_69_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_69_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_69_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_69_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_69_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_69_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_69_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_69_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_69_ADDRESS                                  0x1034
#define BB_TPC_ALUT_SRAM_69_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_69_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_69_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_69_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_69_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_69_RESET                                    0x00000000

// 0x1038 (BB_TPC_ALUT_SRAM_70)
#define BB_TPC_ALUT_SRAM_70_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_70_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_70_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_70_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_70_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_70_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_70_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_70_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_70_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_70_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_70_ADDRESS                                  0x1038
#define BB_TPC_ALUT_SRAM_70_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_70_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_70_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_70_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_70_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_70_RESET                                    0x00000000

// 0x103c (BB_TPC_ALUT_SRAM_71)
#define BB_TPC_ALUT_SRAM_71_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_71_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_71_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_71_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_71_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_71_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_71_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_71_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_71_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_71_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_71_ADDRESS                                  0x103c
#define BB_TPC_ALUT_SRAM_71_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_71_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_71_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_71_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_71_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_71_RESET                                    0x00000000

// 0x1040 (BB_TPC_ALUT_SRAM_72)
#define BB_TPC_ALUT_SRAM_72_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_72_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_72_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_72_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_72_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_72_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_72_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_72_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_72_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_72_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_72_ADDRESS                                  0x1040
#define BB_TPC_ALUT_SRAM_72_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_72_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_72_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_72_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_72_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_72_RESET                                    0x00000000

// 0x1044 (BB_TPC_ALUT_SRAM_73)
#define BB_TPC_ALUT_SRAM_73_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_73_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_73_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_73_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_73_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_73_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_73_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_73_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_73_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_73_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_73_ADDRESS                                  0x1044
#define BB_TPC_ALUT_SRAM_73_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_73_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_73_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_73_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_73_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_73_RESET                                    0x00000000

// 0x1048 (BB_TPC_ALUT_SRAM_74)
#define BB_TPC_ALUT_SRAM_74_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_74_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_74_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_74_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_74_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_74_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_74_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_74_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_74_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_74_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_74_ADDRESS                                  0x1048
#define BB_TPC_ALUT_SRAM_74_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_74_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_74_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_74_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_74_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_74_RESET                                    0x00000000

// 0x104c (BB_TPC_ALUT_SRAM_75)
#define BB_TPC_ALUT_SRAM_75_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_75_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_75_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_75_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_75_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_75_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_75_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_75_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_75_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_75_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_75_ADDRESS                                  0x104c
#define BB_TPC_ALUT_SRAM_75_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_75_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_75_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_75_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_75_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_75_RESET                                    0x00000000

// 0x1050 (BB_TPC_ALUT_SRAM_76)
#define BB_TPC_ALUT_SRAM_76_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_76_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_76_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_76_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_76_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_76_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_76_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_76_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_76_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_76_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_76_ADDRESS                                  0x1050
#define BB_TPC_ALUT_SRAM_76_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_76_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_76_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_76_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_76_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_76_RESET                                    0x00000000

// 0x1054 (BB_TPC_ALUT_SRAM_77)
#define BB_TPC_ALUT_SRAM_77_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_77_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_77_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_77_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_77_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_77_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_77_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_77_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_77_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_77_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_77_ADDRESS                                  0x1054
#define BB_TPC_ALUT_SRAM_77_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_77_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_77_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_77_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_77_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_77_RESET                                    0x00000000

// 0x1058 (BB_TPC_ALUT_SRAM_78)
#define BB_TPC_ALUT_SRAM_78_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_78_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_78_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_78_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_78_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_78_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_78_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_78_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_78_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_78_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_78_ADDRESS                                  0x1058
#define BB_TPC_ALUT_SRAM_78_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_78_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_78_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_78_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_78_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_78_RESET                                    0x00000000

// 0x105c (BB_TPC_ALUT_SRAM_79)
#define BB_TPC_ALUT_SRAM_79_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_79_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_79_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_79_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_79_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_79_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_79_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_79_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_79_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_79_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_79_ADDRESS                                  0x105c
#define BB_TPC_ALUT_SRAM_79_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_79_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_79_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_79_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_79_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_79_RESET                                    0x00000000

// 0x1060 (BB_TPC_ALUT_SRAM_80)
#define BB_TPC_ALUT_SRAM_80_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_80_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_80_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_80_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_80_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_80_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_80_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_80_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_80_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_80_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_80_ADDRESS                                  0x1060
#define BB_TPC_ALUT_SRAM_80_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_80_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_80_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_80_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_80_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_80_RESET                                    0x00000000

// 0x1064 (BB_TPC_ALUT_SRAM_81)
#define BB_TPC_ALUT_SRAM_81_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_81_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_81_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_81_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_81_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_81_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_81_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_81_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_81_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_81_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_81_ADDRESS                                  0x1064
#define BB_TPC_ALUT_SRAM_81_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_81_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_81_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_81_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_81_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_81_RESET                                    0x00000000

// 0x1068 (BB_TPC_ALUT_SRAM_82)
#define BB_TPC_ALUT_SRAM_82_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_82_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_82_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_82_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_82_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_82_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_82_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_82_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_82_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_82_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_82_ADDRESS                                  0x1068
#define BB_TPC_ALUT_SRAM_82_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_82_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_82_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_82_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_82_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_82_RESET                                    0x00000000

// 0x106c (BB_TPC_ALUT_SRAM_83)
#define BB_TPC_ALUT_SRAM_83_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_83_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_83_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_83_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_83_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_83_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_83_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_83_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_83_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_83_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_83_ADDRESS                                  0x106c
#define BB_TPC_ALUT_SRAM_83_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_83_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_83_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_83_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_83_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_83_RESET                                    0x00000000

// 0x1070 (BB_TPC_ALUT_SRAM_84)
#define BB_TPC_ALUT_SRAM_84_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_84_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_84_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_84_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_84_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_84_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_84_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_84_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_84_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_84_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_84_ADDRESS                                  0x1070
#define BB_TPC_ALUT_SRAM_84_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_84_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_84_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_84_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_84_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_84_RESET                                    0x00000000

// 0x1074 (BB_TPC_ALUT_SRAM_85)
#define BB_TPC_ALUT_SRAM_85_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_85_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_85_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_85_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_85_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_85_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_85_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_85_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_85_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_85_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_85_ADDRESS                                  0x1074
#define BB_TPC_ALUT_SRAM_85_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_85_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_85_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_85_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_85_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_85_RESET                                    0x00000000

// 0x1078 (BB_TPC_ALUT_SRAM_86)
#define BB_TPC_ALUT_SRAM_86_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_86_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_86_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_86_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_86_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_86_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_86_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_86_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_86_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_86_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_86_ADDRESS                                  0x1078
#define BB_TPC_ALUT_SRAM_86_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_86_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_86_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_86_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_86_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_86_RESET                                    0x00000000

// 0x107c (BB_TPC_ALUT_SRAM_87)
#define BB_TPC_ALUT_SRAM_87_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_87_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_87_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_87_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_87_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_87_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_87_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_87_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_87_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_87_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_87_ADDRESS                                  0x107c
#define BB_TPC_ALUT_SRAM_87_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_87_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_87_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_87_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_87_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_87_RESET                                    0x00000000

// 0x1080 (BB_TPC_ALUT_SRAM_88)
#define BB_TPC_ALUT_SRAM_88_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_88_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_88_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_88_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_88_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_88_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_88_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_88_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_88_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_88_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_88_ADDRESS                                  0x1080
#define BB_TPC_ALUT_SRAM_88_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_88_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_88_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_88_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_88_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_88_RESET                                    0x00000000

// 0x1084 (BB_TPC_ALUT_SRAM_89)
#define BB_TPC_ALUT_SRAM_89_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_89_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_89_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_89_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_89_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_89_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_89_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_89_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_89_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_89_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_89_ADDRESS                                  0x1084
#define BB_TPC_ALUT_SRAM_89_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_89_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_89_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_89_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_89_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_89_RESET                                    0x00000000

// 0x1088 (BB_TPC_ALUT_SRAM_90)
#define BB_TPC_ALUT_SRAM_90_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_90_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_90_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_90_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_90_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_90_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_90_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_90_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_90_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_90_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_90_ADDRESS                                  0x1088
#define BB_TPC_ALUT_SRAM_90_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_90_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_90_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_90_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_90_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_90_RESET                                    0x00000000

// 0x108c (BB_TPC_ALUT_SRAM_91)
#define BB_TPC_ALUT_SRAM_91_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_91_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_91_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_91_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_91_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_91_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_91_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_91_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_91_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_91_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_91_ADDRESS                                  0x108c
#define BB_TPC_ALUT_SRAM_91_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_91_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_91_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_91_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_91_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_91_RESET                                    0x00000000

// 0x1090 (BB_TPC_ALUT_SRAM_92)
#define BB_TPC_ALUT_SRAM_92_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_92_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_92_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_92_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_92_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_92_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_92_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_92_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_92_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_92_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_92_ADDRESS                                  0x1090
#define BB_TPC_ALUT_SRAM_92_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_92_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_92_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_92_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_92_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_92_RESET                                    0x00000000

// 0x1094 (BB_TPC_ALUT_SRAM_93)
#define BB_TPC_ALUT_SRAM_93_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_93_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_93_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_93_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_93_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_93_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_93_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_93_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_93_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_93_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_93_ADDRESS                                  0x1094
#define BB_TPC_ALUT_SRAM_93_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_93_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_93_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_93_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_93_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_93_RESET                                    0x00000000

// 0x1098 (BB_TPC_ALUT_SRAM_94)
#define BB_TPC_ALUT_SRAM_94_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_94_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_94_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_94_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_94_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_94_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_94_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_94_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_94_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_94_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_94_ADDRESS                                  0x1098
#define BB_TPC_ALUT_SRAM_94_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_94_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_94_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_94_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_94_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_94_RESET                                    0x00000000

// 0x109c (BB_TPC_ALUT_SRAM_95)
#define BB_TPC_ALUT_SRAM_95_TPC_ALUT_WORD_MSB                        25
#define BB_TPC_ALUT_SRAM_95_TPC_ALUT_WORD_LSB                        0
#define BB_TPC_ALUT_SRAM_95_TPC_ALUT_WORD_MASK                       0x03ffffff
#define BB_TPC_ALUT_SRAM_95_TPC_ALUT_WORD_GET(x)                     (((x) & BB_TPC_ALUT_SRAM_95_TPC_ALUT_WORD_MASK) >> BB_TPC_ALUT_SRAM_95_TPC_ALUT_WORD_LSB)
#define BB_TPC_ALUT_SRAM_95_TPC_ALUT_WORD_SET(x)                     (((0 | (x)) << BB_TPC_ALUT_SRAM_95_TPC_ALUT_WORD_LSB) & BB_TPC_ALUT_SRAM_95_TPC_ALUT_WORD_MASK)
#define BB_TPC_ALUT_SRAM_95_TPC_ALUT_WORD_RESET                      0
#define BB_TPC_ALUT_SRAM_95_ADDRESS                                  0x109c
#define BB_TPC_ALUT_SRAM_95_HW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_95_SW_MASK                                  0x03ffffff
#define BB_TPC_ALUT_SRAM_95_HW_WRITE_MASK                            0x00000000
#define BB_TPC_ALUT_SRAM_95_SW_WRITE_MASK                            0x03ffffff
#define BB_TPC_ALUT_SRAM_95_RSTMASK                                  0xfc000000
#define BB_TPC_ALUT_SRAM_95_RESET                                    0x00000000

// 0x1110 (BB_SM_TABLES_DUMMY2)
#define BB_SM_TABLES_DUMMY2_DUMMY2_MSB                               31
#define BB_SM_TABLES_DUMMY2_DUMMY2_LSB                               0
#define BB_SM_TABLES_DUMMY2_DUMMY2_MASK                              0xffffffff
#define BB_SM_TABLES_DUMMY2_DUMMY2_GET(x)                            (((x) & BB_SM_TABLES_DUMMY2_DUMMY2_MASK) >> BB_SM_TABLES_DUMMY2_DUMMY2_LSB)
#define BB_SM_TABLES_DUMMY2_DUMMY2_SET(x)                            (((0 | (x)) << BB_SM_TABLES_DUMMY2_DUMMY2_LSB) & BB_SM_TABLES_DUMMY2_DUMMY2_MASK)
#define BB_SM_TABLES_DUMMY2_DUMMY2_RESET                             0
#define BB_SM_TABLES_DUMMY2_ADDRESS                                  0x1110
#define BB_SM_TABLES_DUMMY2_HW_MASK                                  0xffffffff
#define BB_SM_TABLES_DUMMY2_SW_MASK                                  0xffffffff
#define BB_SM_TABLES_DUMMY2_HW_WRITE_MASK                            0x00000000
#define BB_SM_TABLES_DUMMY2_SW_WRITE_MASK                            0xffffffff
#define BB_SM_TABLES_DUMMY2_RSTMASK                                  0x00000000
#define BB_SM_TABLES_DUMMY2_RESET                                    0x00000000


#endif /* _SM_TABLE_MAP_H_ */
