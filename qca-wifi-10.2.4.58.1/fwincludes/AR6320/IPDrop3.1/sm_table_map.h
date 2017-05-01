//                                                                             
// File:       ./sm_table_map.vrh                                              
// Creator:    tyzhang                                                         
// Time:       Monday Sep 24, 2012 [8:14:16 pm]                                
//                                                                             
// Path:       /trees/mbu-cn1/tyzhang/tianfang_enc_depot/chips/rome/dev/doc/headers/wl_soc_mac
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc ./sm_table_map.rdl     
//                                                                             
// Sources:    /trees/mbu-cn1/tyzhang/tianfang_enc_depot/chips/rome/dev/doc/headers/wl_soc_mac/sm_table_map_sysconfig.rdl
//             /trees/mbu-cn1/tyzhang/tianfang_enc_depot/chips/rome/dev/doc/ip/R1_IP5/rtl/bb_2x2/blueprint/sm_table_map.rdl
//             /trees/mbu-cn1/tyzhang/tianfang_enc_depot/chips/rome/dev/env/blueprint/ath_vrh.pm
//             /cad/local/lib/perl/Pinfo.pm                                    
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    apr11                                                           
// OS:         Linux 2.6.9-89.ELsmp                                            
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

// Skip 404 (BB_TPC_TXGAIN_SRAM_1) - 57c (BB_TPC_TXGAIN_SRAM_95) for brevity
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

// Skip 584 (BB_TPC_PLUT_SRAM_1) - b7c (BB_TPC_PLUT_SRAM_383) for brevity
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

// Skip d84 (BB_TPC_GLUT_SRAM_1) - f14 (BB_TPC_GLUT_SRAM_101) for brevity
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

// Skip f24 (BB_TPC_ALUT_SRAM_1) - 109c (BB_TPC_ALUT_SRAM_95) for brevity
// 0x1100 (BB_RXCAL_TX_GAIN_TABLE_0)
#define BB_RXCAL_TX_GAIN_TABLE_0_RXCAL_TX_GAIN_TABLE_0_MSB           19
#define BB_RXCAL_TX_GAIN_TABLE_0_RXCAL_TX_GAIN_TABLE_0_LSB           0
#define BB_RXCAL_TX_GAIN_TABLE_0_RXCAL_TX_GAIN_TABLE_0_MASK          0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_0_RXCAL_TX_GAIN_TABLE_0_GET(x)        (((x) & BB_RXCAL_TX_GAIN_TABLE_0_RXCAL_TX_GAIN_TABLE_0_MASK) >> BB_RXCAL_TX_GAIN_TABLE_0_RXCAL_TX_GAIN_TABLE_0_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_0_RXCAL_TX_GAIN_TABLE_0_SET(x)        (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_0_RXCAL_TX_GAIN_TABLE_0_LSB) & BB_RXCAL_TX_GAIN_TABLE_0_RXCAL_TX_GAIN_TABLE_0_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_0_RXCAL_TX_GAIN_TABLE_0_RESET         0
#define BB_RXCAL_TX_GAIN_TABLE_0_ADDRESS                             0x1100
#define BB_RXCAL_TX_GAIN_TABLE_0_HW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_0_SW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_0_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_0_SW_WRITE_MASK                       0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_0_RSTMASK                             0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_0_RESET                               0x00000000

// 0x1104 (BB_RXCAL_TX_GAIN_TABLE_1)
#define BB_RXCAL_TX_GAIN_TABLE_1_RXCAL_TX_GAIN_TABLE_1_MSB           19
#define BB_RXCAL_TX_GAIN_TABLE_1_RXCAL_TX_GAIN_TABLE_1_LSB           0
#define BB_RXCAL_TX_GAIN_TABLE_1_RXCAL_TX_GAIN_TABLE_1_MASK          0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_1_RXCAL_TX_GAIN_TABLE_1_GET(x)        (((x) & BB_RXCAL_TX_GAIN_TABLE_1_RXCAL_TX_GAIN_TABLE_1_MASK) >> BB_RXCAL_TX_GAIN_TABLE_1_RXCAL_TX_GAIN_TABLE_1_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_1_RXCAL_TX_GAIN_TABLE_1_SET(x)        (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_1_RXCAL_TX_GAIN_TABLE_1_LSB) & BB_RXCAL_TX_GAIN_TABLE_1_RXCAL_TX_GAIN_TABLE_1_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_1_RXCAL_TX_GAIN_TABLE_1_RESET         0
#define BB_RXCAL_TX_GAIN_TABLE_1_ADDRESS                             0x1104
#define BB_RXCAL_TX_GAIN_TABLE_1_HW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_1_SW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_1_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_1_SW_WRITE_MASK                       0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_1_RSTMASK                             0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_1_RESET                               0x00000000

// 0x1108 (BB_RXCAL_TX_GAIN_TABLE_2)
#define BB_RXCAL_TX_GAIN_TABLE_2_RXCAL_TX_GAIN_TABLE_2_MSB           19
#define BB_RXCAL_TX_GAIN_TABLE_2_RXCAL_TX_GAIN_TABLE_2_LSB           0
#define BB_RXCAL_TX_GAIN_TABLE_2_RXCAL_TX_GAIN_TABLE_2_MASK          0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_2_RXCAL_TX_GAIN_TABLE_2_GET(x)        (((x) & BB_RXCAL_TX_GAIN_TABLE_2_RXCAL_TX_GAIN_TABLE_2_MASK) >> BB_RXCAL_TX_GAIN_TABLE_2_RXCAL_TX_GAIN_TABLE_2_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_2_RXCAL_TX_GAIN_TABLE_2_SET(x)        (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_2_RXCAL_TX_GAIN_TABLE_2_LSB) & BB_RXCAL_TX_GAIN_TABLE_2_RXCAL_TX_GAIN_TABLE_2_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_2_RXCAL_TX_GAIN_TABLE_2_RESET         0
#define BB_RXCAL_TX_GAIN_TABLE_2_ADDRESS                             0x1108
#define BB_RXCAL_TX_GAIN_TABLE_2_HW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_2_SW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_2_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_2_SW_WRITE_MASK                       0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_2_RSTMASK                             0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_2_RESET                               0x00000000

// 0x110c (BB_RXCAL_TX_GAIN_TABLE_3)
#define BB_RXCAL_TX_GAIN_TABLE_3_RXCAL_TX_GAIN_TABLE_3_MSB           19
#define BB_RXCAL_TX_GAIN_TABLE_3_RXCAL_TX_GAIN_TABLE_3_LSB           0
#define BB_RXCAL_TX_GAIN_TABLE_3_RXCAL_TX_GAIN_TABLE_3_MASK          0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_3_RXCAL_TX_GAIN_TABLE_3_GET(x)        (((x) & BB_RXCAL_TX_GAIN_TABLE_3_RXCAL_TX_GAIN_TABLE_3_MASK) >> BB_RXCAL_TX_GAIN_TABLE_3_RXCAL_TX_GAIN_TABLE_3_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_3_RXCAL_TX_GAIN_TABLE_3_SET(x)        (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_3_RXCAL_TX_GAIN_TABLE_3_LSB) & BB_RXCAL_TX_GAIN_TABLE_3_RXCAL_TX_GAIN_TABLE_3_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_3_RXCAL_TX_GAIN_TABLE_3_RESET         0
#define BB_RXCAL_TX_GAIN_TABLE_3_ADDRESS                             0x110c
#define BB_RXCAL_TX_GAIN_TABLE_3_HW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_3_SW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_3_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_3_SW_WRITE_MASK                       0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_3_RSTMASK                             0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_3_RESET                               0x00000000

// 0x1110 (BB_RXCAL_TX_GAIN_TABLE_4)
#define BB_RXCAL_TX_GAIN_TABLE_4_RXCAL_TX_GAIN_TABLE_4_MSB           19
#define BB_RXCAL_TX_GAIN_TABLE_4_RXCAL_TX_GAIN_TABLE_4_LSB           0
#define BB_RXCAL_TX_GAIN_TABLE_4_RXCAL_TX_GAIN_TABLE_4_MASK          0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_4_RXCAL_TX_GAIN_TABLE_4_GET(x)        (((x) & BB_RXCAL_TX_GAIN_TABLE_4_RXCAL_TX_GAIN_TABLE_4_MASK) >> BB_RXCAL_TX_GAIN_TABLE_4_RXCAL_TX_GAIN_TABLE_4_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_4_RXCAL_TX_GAIN_TABLE_4_SET(x)        (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_4_RXCAL_TX_GAIN_TABLE_4_LSB) & BB_RXCAL_TX_GAIN_TABLE_4_RXCAL_TX_GAIN_TABLE_4_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_4_RXCAL_TX_GAIN_TABLE_4_RESET         0
#define BB_RXCAL_TX_GAIN_TABLE_4_ADDRESS                             0x1110
#define BB_RXCAL_TX_GAIN_TABLE_4_HW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_4_SW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_4_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_4_SW_WRITE_MASK                       0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_4_RSTMASK                             0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_4_RESET                               0x00000000

// 0x1114 (BB_RXCAL_TX_GAIN_TABLE_5)
#define BB_RXCAL_TX_GAIN_TABLE_5_RXCAL_TX_GAIN_TABLE_5_MSB           19
#define BB_RXCAL_TX_GAIN_TABLE_5_RXCAL_TX_GAIN_TABLE_5_LSB           0
#define BB_RXCAL_TX_GAIN_TABLE_5_RXCAL_TX_GAIN_TABLE_5_MASK          0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_5_RXCAL_TX_GAIN_TABLE_5_GET(x)        (((x) & BB_RXCAL_TX_GAIN_TABLE_5_RXCAL_TX_GAIN_TABLE_5_MASK) >> BB_RXCAL_TX_GAIN_TABLE_5_RXCAL_TX_GAIN_TABLE_5_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_5_RXCAL_TX_GAIN_TABLE_5_SET(x)        (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_5_RXCAL_TX_GAIN_TABLE_5_LSB) & BB_RXCAL_TX_GAIN_TABLE_5_RXCAL_TX_GAIN_TABLE_5_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_5_RXCAL_TX_GAIN_TABLE_5_RESET         0
#define BB_RXCAL_TX_GAIN_TABLE_5_ADDRESS                             0x1114
#define BB_RXCAL_TX_GAIN_TABLE_5_HW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_5_SW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_5_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_5_SW_WRITE_MASK                       0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_5_RSTMASK                             0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_5_RESET                               0x00000000

// 0x1118 (BB_RXCAL_TX_GAIN_TABLE_6)
#define BB_RXCAL_TX_GAIN_TABLE_6_RXCAL_TX_GAIN_TABLE_6_MSB           19
#define BB_RXCAL_TX_GAIN_TABLE_6_RXCAL_TX_GAIN_TABLE_6_LSB           0
#define BB_RXCAL_TX_GAIN_TABLE_6_RXCAL_TX_GAIN_TABLE_6_MASK          0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_6_RXCAL_TX_GAIN_TABLE_6_GET(x)        (((x) & BB_RXCAL_TX_GAIN_TABLE_6_RXCAL_TX_GAIN_TABLE_6_MASK) >> BB_RXCAL_TX_GAIN_TABLE_6_RXCAL_TX_GAIN_TABLE_6_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_6_RXCAL_TX_GAIN_TABLE_6_SET(x)        (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_6_RXCAL_TX_GAIN_TABLE_6_LSB) & BB_RXCAL_TX_GAIN_TABLE_6_RXCAL_TX_GAIN_TABLE_6_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_6_RXCAL_TX_GAIN_TABLE_6_RESET         0
#define BB_RXCAL_TX_GAIN_TABLE_6_ADDRESS                             0x1118
#define BB_RXCAL_TX_GAIN_TABLE_6_HW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_6_SW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_6_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_6_SW_WRITE_MASK                       0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_6_RSTMASK                             0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_6_RESET                               0x00000000

// 0x111c (BB_RXCAL_TX_GAIN_TABLE_7)
#define BB_RXCAL_TX_GAIN_TABLE_7_RXCAL_TX_GAIN_TABLE_7_MSB           19
#define BB_RXCAL_TX_GAIN_TABLE_7_RXCAL_TX_GAIN_TABLE_7_LSB           0
#define BB_RXCAL_TX_GAIN_TABLE_7_RXCAL_TX_GAIN_TABLE_7_MASK          0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_7_RXCAL_TX_GAIN_TABLE_7_GET(x)        (((x) & BB_RXCAL_TX_GAIN_TABLE_7_RXCAL_TX_GAIN_TABLE_7_MASK) >> BB_RXCAL_TX_GAIN_TABLE_7_RXCAL_TX_GAIN_TABLE_7_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_7_RXCAL_TX_GAIN_TABLE_7_SET(x)        (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_7_RXCAL_TX_GAIN_TABLE_7_LSB) & BB_RXCAL_TX_GAIN_TABLE_7_RXCAL_TX_GAIN_TABLE_7_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_7_RXCAL_TX_GAIN_TABLE_7_RESET         0
#define BB_RXCAL_TX_GAIN_TABLE_7_ADDRESS                             0x111c
#define BB_RXCAL_TX_GAIN_TABLE_7_HW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_7_SW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_7_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_7_SW_WRITE_MASK                       0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_7_RSTMASK                             0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_7_RESET                               0x00000000

// 0x1120 (BB_RXCAL_TX_GAIN_TABLE_8)
#define BB_RXCAL_TX_GAIN_TABLE_8_RXCAL_TX_GAIN_TABLE_8_MSB           19
#define BB_RXCAL_TX_GAIN_TABLE_8_RXCAL_TX_GAIN_TABLE_8_LSB           0
#define BB_RXCAL_TX_GAIN_TABLE_8_RXCAL_TX_GAIN_TABLE_8_MASK          0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_8_RXCAL_TX_GAIN_TABLE_8_GET(x)        (((x) & BB_RXCAL_TX_GAIN_TABLE_8_RXCAL_TX_GAIN_TABLE_8_MASK) >> BB_RXCAL_TX_GAIN_TABLE_8_RXCAL_TX_GAIN_TABLE_8_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_8_RXCAL_TX_GAIN_TABLE_8_SET(x)        (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_8_RXCAL_TX_GAIN_TABLE_8_LSB) & BB_RXCAL_TX_GAIN_TABLE_8_RXCAL_TX_GAIN_TABLE_8_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_8_RXCAL_TX_GAIN_TABLE_8_RESET         0
#define BB_RXCAL_TX_GAIN_TABLE_8_ADDRESS                             0x1120
#define BB_RXCAL_TX_GAIN_TABLE_8_HW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_8_SW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_8_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_8_SW_WRITE_MASK                       0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_8_RSTMASK                             0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_8_RESET                               0x00000000

// 0x1124 (BB_RXCAL_TX_GAIN_TABLE_9)
#define BB_RXCAL_TX_GAIN_TABLE_9_RXCAL_TX_GAIN_TABLE_9_MSB           19
#define BB_RXCAL_TX_GAIN_TABLE_9_RXCAL_TX_GAIN_TABLE_9_LSB           0
#define BB_RXCAL_TX_GAIN_TABLE_9_RXCAL_TX_GAIN_TABLE_9_MASK          0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_9_RXCAL_TX_GAIN_TABLE_9_GET(x)        (((x) & BB_RXCAL_TX_GAIN_TABLE_9_RXCAL_TX_GAIN_TABLE_9_MASK) >> BB_RXCAL_TX_GAIN_TABLE_9_RXCAL_TX_GAIN_TABLE_9_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_9_RXCAL_TX_GAIN_TABLE_9_SET(x)        (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_9_RXCAL_TX_GAIN_TABLE_9_LSB) & BB_RXCAL_TX_GAIN_TABLE_9_RXCAL_TX_GAIN_TABLE_9_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_9_RXCAL_TX_GAIN_TABLE_9_RESET         0
#define BB_RXCAL_TX_GAIN_TABLE_9_ADDRESS                             0x1124
#define BB_RXCAL_TX_GAIN_TABLE_9_HW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_9_SW_MASK                             0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_9_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_9_SW_WRITE_MASK                       0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_9_RSTMASK                             0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_9_RESET                               0x00000000

// 0x1128 (BB_RXCAL_TX_GAIN_TABLE_10)
#define BB_RXCAL_TX_GAIN_TABLE_10_RXCAL_TX_GAIN_TABLE_10_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_10_RXCAL_TX_GAIN_TABLE_10_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_10_RXCAL_TX_GAIN_TABLE_10_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_10_RXCAL_TX_GAIN_TABLE_10_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_10_RXCAL_TX_GAIN_TABLE_10_MASK) >> BB_RXCAL_TX_GAIN_TABLE_10_RXCAL_TX_GAIN_TABLE_10_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_10_RXCAL_TX_GAIN_TABLE_10_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_10_RXCAL_TX_GAIN_TABLE_10_LSB) & BB_RXCAL_TX_GAIN_TABLE_10_RXCAL_TX_GAIN_TABLE_10_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_10_RXCAL_TX_GAIN_TABLE_10_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_10_ADDRESS                            0x1128
#define BB_RXCAL_TX_GAIN_TABLE_10_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_10_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_10_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_10_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_10_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_10_RESET                              0x00000000

// 0x112c (BB_RXCAL_TX_GAIN_TABLE_11)
#define BB_RXCAL_TX_GAIN_TABLE_11_RXCAL_TX_GAIN_TABLE_11_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_11_RXCAL_TX_GAIN_TABLE_11_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_11_RXCAL_TX_GAIN_TABLE_11_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_11_RXCAL_TX_GAIN_TABLE_11_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_11_RXCAL_TX_GAIN_TABLE_11_MASK) >> BB_RXCAL_TX_GAIN_TABLE_11_RXCAL_TX_GAIN_TABLE_11_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_11_RXCAL_TX_GAIN_TABLE_11_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_11_RXCAL_TX_GAIN_TABLE_11_LSB) & BB_RXCAL_TX_GAIN_TABLE_11_RXCAL_TX_GAIN_TABLE_11_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_11_RXCAL_TX_GAIN_TABLE_11_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_11_ADDRESS                            0x112c
#define BB_RXCAL_TX_GAIN_TABLE_11_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_11_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_11_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_11_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_11_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_11_RESET                              0x00000000

// 0x1130 (BB_RXCAL_TX_GAIN_TABLE_12)
#define BB_RXCAL_TX_GAIN_TABLE_12_RXCAL_TX_GAIN_TABLE_12_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_12_RXCAL_TX_GAIN_TABLE_12_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_12_RXCAL_TX_GAIN_TABLE_12_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_12_RXCAL_TX_GAIN_TABLE_12_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_12_RXCAL_TX_GAIN_TABLE_12_MASK) >> BB_RXCAL_TX_GAIN_TABLE_12_RXCAL_TX_GAIN_TABLE_12_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_12_RXCAL_TX_GAIN_TABLE_12_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_12_RXCAL_TX_GAIN_TABLE_12_LSB) & BB_RXCAL_TX_GAIN_TABLE_12_RXCAL_TX_GAIN_TABLE_12_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_12_RXCAL_TX_GAIN_TABLE_12_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_12_ADDRESS                            0x1130
#define BB_RXCAL_TX_GAIN_TABLE_12_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_12_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_12_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_12_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_12_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_12_RESET                              0x00000000

// 0x1134 (BB_RXCAL_TX_GAIN_TABLE_13)
#define BB_RXCAL_TX_GAIN_TABLE_13_RXCAL_TX_GAIN_TABLE_13_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_13_RXCAL_TX_GAIN_TABLE_13_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_13_RXCAL_TX_GAIN_TABLE_13_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_13_RXCAL_TX_GAIN_TABLE_13_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_13_RXCAL_TX_GAIN_TABLE_13_MASK) >> BB_RXCAL_TX_GAIN_TABLE_13_RXCAL_TX_GAIN_TABLE_13_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_13_RXCAL_TX_GAIN_TABLE_13_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_13_RXCAL_TX_GAIN_TABLE_13_LSB) & BB_RXCAL_TX_GAIN_TABLE_13_RXCAL_TX_GAIN_TABLE_13_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_13_RXCAL_TX_GAIN_TABLE_13_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_13_ADDRESS                            0x1134
#define BB_RXCAL_TX_GAIN_TABLE_13_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_13_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_13_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_13_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_13_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_13_RESET                              0x00000000

// 0x1138 (BB_RXCAL_TX_GAIN_TABLE_14)
#define BB_RXCAL_TX_GAIN_TABLE_14_RXCAL_TX_GAIN_TABLE_14_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_14_RXCAL_TX_GAIN_TABLE_14_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_14_RXCAL_TX_GAIN_TABLE_14_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_14_RXCAL_TX_GAIN_TABLE_14_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_14_RXCAL_TX_GAIN_TABLE_14_MASK) >> BB_RXCAL_TX_GAIN_TABLE_14_RXCAL_TX_GAIN_TABLE_14_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_14_RXCAL_TX_GAIN_TABLE_14_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_14_RXCAL_TX_GAIN_TABLE_14_LSB) & BB_RXCAL_TX_GAIN_TABLE_14_RXCAL_TX_GAIN_TABLE_14_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_14_RXCAL_TX_GAIN_TABLE_14_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_14_ADDRESS                            0x1138
#define BB_RXCAL_TX_GAIN_TABLE_14_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_14_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_14_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_14_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_14_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_14_RESET                              0x00000000

// 0x113c (BB_RXCAL_TX_GAIN_TABLE_15)
#define BB_RXCAL_TX_GAIN_TABLE_15_RXCAL_TX_GAIN_TABLE_15_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_15_RXCAL_TX_GAIN_TABLE_15_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_15_RXCAL_TX_GAIN_TABLE_15_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_15_RXCAL_TX_GAIN_TABLE_15_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_15_RXCAL_TX_GAIN_TABLE_15_MASK) >> BB_RXCAL_TX_GAIN_TABLE_15_RXCAL_TX_GAIN_TABLE_15_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_15_RXCAL_TX_GAIN_TABLE_15_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_15_RXCAL_TX_GAIN_TABLE_15_LSB) & BB_RXCAL_TX_GAIN_TABLE_15_RXCAL_TX_GAIN_TABLE_15_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_15_RXCAL_TX_GAIN_TABLE_15_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_15_ADDRESS                            0x113c
#define BB_RXCAL_TX_GAIN_TABLE_15_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_15_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_15_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_15_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_15_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_15_RESET                              0x00000000

// 0x1140 (BB_RXCAL_TX_GAIN_TABLE_16)
#define BB_RXCAL_TX_GAIN_TABLE_16_RXCAL_TX_GAIN_TABLE_16_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_16_RXCAL_TX_GAIN_TABLE_16_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_16_RXCAL_TX_GAIN_TABLE_16_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_16_RXCAL_TX_GAIN_TABLE_16_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_16_RXCAL_TX_GAIN_TABLE_16_MASK) >> BB_RXCAL_TX_GAIN_TABLE_16_RXCAL_TX_GAIN_TABLE_16_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_16_RXCAL_TX_GAIN_TABLE_16_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_16_RXCAL_TX_GAIN_TABLE_16_LSB) & BB_RXCAL_TX_GAIN_TABLE_16_RXCAL_TX_GAIN_TABLE_16_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_16_RXCAL_TX_GAIN_TABLE_16_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_16_ADDRESS                            0x1140
#define BB_RXCAL_TX_GAIN_TABLE_16_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_16_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_16_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_16_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_16_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_16_RESET                              0x00000000

// 0x1144 (BB_RXCAL_TX_GAIN_TABLE_17)
#define BB_RXCAL_TX_GAIN_TABLE_17_RXCAL_TX_GAIN_TABLE_17_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_17_RXCAL_TX_GAIN_TABLE_17_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_17_RXCAL_TX_GAIN_TABLE_17_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_17_RXCAL_TX_GAIN_TABLE_17_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_17_RXCAL_TX_GAIN_TABLE_17_MASK) >> BB_RXCAL_TX_GAIN_TABLE_17_RXCAL_TX_GAIN_TABLE_17_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_17_RXCAL_TX_GAIN_TABLE_17_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_17_RXCAL_TX_GAIN_TABLE_17_LSB) & BB_RXCAL_TX_GAIN_TABLE_17_RXCAL_TX_GAIN_TABLE_17_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_17_RXCAL_TX_GAIN_TABLE_17_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_17_ADDRESS                            0x1144
#define BB_RXCAL_TX_GAIN_TABLE_17_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_17_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_17_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_17_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_17_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_17_RESET                              0x00000000

// 0x1148 (BB_RXCAL_TX_GAIN_TABLE_18)
#define BB_RXCAL_TX_GAIN_TABLE_18_RXCAL_TX_GAIN_TABLE_18_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_18_RXCAL_TX_GAIN_TABLE_18_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_18_RXCAL_TX_GAIN_TABLE_18_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_18_RXCAL_TX_GAIN_TABLE_18_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_18_RXCAL_TX_GAIN_TABLE_18_MASK) >> BB_RXCAL_TX_GAIN_TABLE_18_RXCAL_TX_GAIN_TABLE_18_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_18_RXCAL_TX_GAIN_TABLE_18_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_18_RXCAL_TX_GAIN_TABLE_18_LSB) & BB_RXCAL_TX_GAIN_TABLE_18_RXCAL_TX_GAIN_TABLE_18_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_18_RXCAL_TX_GAIN_TABLE_18_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_18_ADDRESS                            0x1148
#define BB_RXCAL_TX_GAIN_TABLE_18_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_18_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_18_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_18_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_18_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_18_RESET                              0x00000000

// 0x114c (BB_RXCAL_TX_GAIN_TABLE_19)
#define BB_RXCAL_TX_GAIN_TABLE_19_RXCAL_TX_GAIN_TABLE_19_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_19_RXCAL_TX_GAIN_TABLE_19_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_19_RXCAL_TX_GAIN_TABLE_19_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_19_RXCAL_TX_GAIN_TABLE_19_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_19_RXCAL_TX_GAIN_TABLE_19_MASK) >> BB_RXCAL_TX_GAIN_TABLE_19_RXCAL_TX_GAIN_TABLE_19_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_19_RXCAL_TX_GAIN_TABLE_19_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_19_RXCAL_TX_GAIN_TABLE_19_LSB) & BB_RXCAL_TX_GAIN_TABLE_19_RXCAL_TX_GAIN_TABLE_19_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_19_RXCAL_TX_GAIN_TABLE_19_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_19_ADDRESS                            0x114c
#define BB_RXCAL_TX_GAIN_TABLE_19_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_19_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_19_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_19_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_19_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_19_RESET                              0x00000000

// 0x1150 (BB_RXCAL_TX_GAIN_TABLE_20)
#define BB_RXCAL_TX_GAIN_TABLE_20_RXCAL_TX_GAIN_TABLE_20_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_20_RXCAL_TX_GAIN_TABLE_20_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_20_RXCAL_TX_GAIN_TABLE_20_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_20_RXCAL_TX_GAIN_TABLE_20_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_20_RXCAL_TX_GAIN_TABLE_20_MASK) >> BB_RXCAL_TX_GAIN_TABLE_20_RXCAL_TX_GAIN_TABLE_20_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_20_RXCAL_TX_GAIN_TABLE_20_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_20_RXCAL_TX_GAIN_TABLE_20_LSB) & BB_RXCAL_TX_GAIN_TABLE_20_RXCAL_TX_GAIN_TABLE_20_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_20_RXCAL_TX_GAIN_TABLE_20_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_20_ADDRESS                            0x1150
#define BB_RXCAL_TX_GAIN_TABLE_20_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_20_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_20_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_20_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_20_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_20_RESET                              0x00000000

// 0x1154 (BB_RXCAL_TX_GAIN_TABLE_21)
#define BB_RXCAL_TX_GAIN_TABLE_21_RXCAL_TX_GAIN_TABLE_21_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_21_RXCAL_TX_GAIN_TABLE_21_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_21_RXCAL_TX_GAIN_TABLE_21_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_21_RXCAL_TX_GAIN_TABLE_21_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_21_RXCAL_TX_GAIN_TABLE_21_MASK) >> BB_RXCAL_TX_GAIN_TABLE_21_RXCAL_TX_GAIN_TABLE_21_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_21_RXCAL_TX_GAIN_TABLE_21_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_21_RXCAL_TX_GAIN_TABLE_21_LSB) & BB_RXCAL_TX_GAIN_TABLE_21_RXCAL_TX_GAIN_TABLE_21_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_21_RXCAL_TX_GAIN_TABLE_21_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_21_ADDRESS                            0x1154
#define BB_RXCAL_TX_GAIN_TABLE_21_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_21_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_21_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_21_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_21_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_21_RESET                              0x00000000

// 0x1158 (BB_RXCAL_TX_GAIN_TABLE_22)
#define BB_RXCAL_TX_GAIN_TABLE_22_RXCAL_TX_GAIN_TABLE_22_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_22_RXCAL_TX_GAIN_TABLE_22_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_22_RXCAL_TX_GAIN_TABLE_22_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_22_RXCAL_TX_GAIN_TABLE_22_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_22_RXCAL_TX_GAIN_TABLE_22_MASK) >> BB_RXCAL_TX_GAIN_TABLE_22_RXCAL_TX_GAIN_TABLE_22_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_22_RXCAL_TX_GAIN_TABLE_22_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_22_RXCAL_TX_GAIN_TABLE_22_LSB) & BB_RXCAL_TX_GAIN_TABLE_22_RXCAL_TX_GAIN_TABLE_22_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_22_RXCAL_TX_GAIN_TABLE_22_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_22_ADDRESS                            0x1158
#define BB_RXCAL_TX_GAIN_TABLE_22_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_22_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_22_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_22_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_22_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_22_RESET                              0x00000000

// 0x115c (BB_RXCAL_TX_GAIN_TABLE_23)
#define BB_RXCAL_TX_GAIN_TABLE_23_RXCAL_TX_GAIN_TABLE_23_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_23_RXCAL_TX_GAIN_TABLE_23_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_23_RXCAL_TX_GAIN_TABLE_23_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_23_RXCAL_TX_GAIN_TABLE_23_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_23_RXCAL_TX_GAIN_TABLE_23_MASK) >> BB_RXCAL_TX_GAIN_TABLE_23_RXCAL_TX_GAIN_TABLE_23_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_23_RXCAL_TX_GAIN_TABLE_23_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_23_RXCAL_TX_GAIN_TABLE_23_LSB) & BB_RXCAL_TX_GAIN_TABLE_23_RXCAL_TX_GAIN_TABLE_23_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_23_RXCAL_TX_GAIN_TABLE_23_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_23_ADDRESS                            0x115c
#define BB_RXCAL_TX_GAIN_TABLE_23_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_23_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_23_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_23_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_23_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_23_RESET                              0x00000000

// 0x1160 (BB_RXCAL_TX_GAIN_TABLE_24)
#define BB_RXCAL_TX_GAIN_TABLE_24_RXCAL_TX_GAIN_TABLE_24_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_24_RXCAL_TX_GAIN_TABLE_24_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_24_RXCAL_TX_GAIN_TABLE_24_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_24_RXCAL_TX_GAIN_TABLE_24_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_24_RXCAL_TX_GAIN_TABLE_24_MASK) >> BB_RXCAL_TX_GAIN_TABLE_24_RXCAL_TX_GAIN_TABLE_24_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_24_RXCAL_TX_GAIN_TABLE_24_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_24_RXCAL_TX_GAIN_TABLE_24_LSB) & BB_RXCAL_TX_GAIN_TABLE_24_RXCAL_TX_GAIN_TABLE_24_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_24_RXCAL_TX_GAIN_TABLE_24_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_24_ADDRESS                            0x1160
#define BB_RXCAL_TX_GAIN_TABLE_24_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_24_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_24_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_24_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_24_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_24_RESET                              0x00000000

// 0x1164 (BB_RXCAL_TX_GAIN_TABLE_25)
#define BB_RXCAL_TX_GAIN_TABLE_25_RXCAL_TX_GAIN_TABLE_25_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_25_RXCAL_TX_GAIN_TABLE_25_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_25_RXCAL_TX_GAIN_TABLE_25_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_25_RXCAL_TX_GAIN_TABLE_25_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_25_RXCAL_TX_GAIN_TABLE_25_MASK) >> BB_RXCAL_TX_GAIN_TABLE_25_RXCAL_TX_GAIN_TABLE_25_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_25_RXCAL_TX_GAIN_TABLE_25_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_25_RXCAL_TX_GAIN_TABLE_25_LSB) & BB_RXCAL_TX_GAIN_TABLE_25_RXCAL_TX_GAIN_TABLE_25_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_25_RXCAL_TX_GAIN_TABLE_25_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_25_ADDRESS                            0x1164
#define BB_RXCAL_TX_GAIN_TABLE_25_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_25_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_25_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_25_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_25_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_25_RESET                              0x00000000

// 0x1168 (BB_RXCAL_TX_GAIN_TABLE_26)
#define BB_RXCAL_TX_GAIN_TABLE_26_RXCAL_TX_GAIN_TABLE_26_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_26_RXCAL_TX_GAIN_TABLE_26_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_26_RXCAL_TX_GAIN_TABLE_26_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_26_RXCAL_TX_GAIN_TABLE_26_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_26_RXCAL_TX_GAIN_TABLE_26_MASK) >> BB_RXCAL_TX_GAIN_TABLE_26_RXCAL_TX_GAIN_TABLE_26_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_26_RXCAL_TX_GAIN_TABLE_26_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_26_RXCAL_TX_GAIN_TABLE_26_LSB) & BB_RXCAL_TX_GAIN_TABLE_26_RXCAL_TX_GAIN_TABLE_26_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_26_RXCAL_TX_GAIN_TABLE_26_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_26_ADDRESS                            0x1168
#define BB_RXCAL_TX_GAIN_TABLE_26_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_26_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_26_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_26_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_26_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_26_RESET                              0x00000000

// 0x116c (BB_RXCAL_TX_GAIN_TABLE_27)
#define BB_RXCAL_TX_GAIN_TABLE_27_RXCAL_TX_GAIN_TABLE_27_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_27_RXCAL_TX_GAIN_TABLE_27_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_27_RXCAL_TX_GAIN_TABLE_27_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_27_RXCAL_TX_GAIN_TABLE_27_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_27_RXCAL_TX_GAIN_TABLE_27_MASK) >> BB_RXCAL_TX_GAIN_TABLE_27_RXCAL_TX_GAIN_TABLE_27_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_27_RXCAL_TX_GAIN_TABLE_27_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_27_RXCAL_TX_GAIN_TABLE_27_LSB) & BB_RXCAL_TX_GAIN_TABLE_27_RXCAL_TX_GAIN_TABLE_27_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_27_RXCAL_TX_GAIN_TABLE_27_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_27_ADDRESS                            0x116c
#define BB_RXCAL_TX_GAIN_TABLE_27_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_27_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_27_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_27_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_27_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_27_RESET                              0x00000000

// 0x1170 (BB_RXCAL_TX_GAIN_TABLE_28)
#define BB_RXCAL_TX_GAIN_TABLE_28_RXCAL_TX_GAIN_TABLE_28_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_28_RXCAL_TX_GAIN_TABLE_28_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_28_RXCAL_TX_GAIN_TABLE_28_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_28_RXCAL_TX_GAIN_TABLE_28_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_28_RXCAL_TX_GAIN_TABLE_28_MASK) >> BB_RXCAL_TX_GAIN_TABLE_28_RXCAL_TX_GAIN_TABLE_28_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_28_RXCAL_TX_GAIN_TABLE_28_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_28_RXCAL_TX_GAIN_TABLE_28_LSB) & BB_RXCAL_TX_GAIN_TABLE_28_RXCAL_TX_GAIN_TABLE_28_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_28_RXCAL_TX_GAIN_TABLE_28_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_28_ADDRESS                            0x1170
#define BB_RXCAL_TX_GAIN_TABLE_28_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_28_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_28_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_28_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_28_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_28_RESET                              0x00000000

// 0x1174 (BB_RXCAL_TX_GAIN_TABLE_29)
#define BB_RXCAL_TX_GAIN_TABLE_29_RXCAL_TX_GAIN_TABLE_29_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_29_RXCAL_TX_GAIN_TABLE_29_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_29_RXCAL_TX_GAIN_TABLE_29_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_29_RXCAL_TX_GAIN_TABLE_29_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_29_RXCAL_TX_GAIN_TABLE_29_MASK) >> BB_RXCAL_TX_GAIN_TABLE_29_RXCAL_TX_GAIN_TABLE_29_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_29_RXCAL_TX_GAIN_TABLE_29_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_29_RXCAL_TX_GAIN_TABLE_29_LSB) & BB_RXCAL_TX_GAIN_TABLE_29_RXCAL_TX_GAIN_TABLE_29_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_29_RXCAL_TX_GAIN_TABLE_29_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_29_ADDRESS                            0x1174
#define BB_RXCAL_TX_GAIN_TABLE_29_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_29_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_29_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_29_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_29_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_29_RESET                              0x00000000

// 0x1178 (BB_RXCAL_TX_GAIN_TABLE_30)
#define BB_RXCAL_TX_GAIN_TABLE_30_RXCAL_TX_GAIN_TABLE_30_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_30_RXCAL_TX_GAIN_TABLE_30_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_30_RXCAL_TX_GAIN_TABLE_30_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_30_RXCAL_TX_GAIN_TABLE_30_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_30_RXCAL_TX_GAIN_TABLE_30_MASK) >> BB_RXCAL_TX_GAIN_TABLE_30_RXCAL_TX_GAIN_TABLE_30_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_30_RXCAL_TX_GAIN_TABLE_30_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_30_RXCAL_TX_GAIN_TABLE_30_LSB) & BB_RXCAL_TX_GAIN_TABLE_30_RXCAL_TX_GAIN_TABLE_30_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_30_RXCAL_TX_GAIN_TABLE_30_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_30_ADDRESS                            0x1178
#define BB_RXCAL_TX_GAIN_TABLE_30_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_30_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_30_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_30_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_30_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_30_RESET                              0x00000000

// 0x117c (BB_RXCAL_TX_GAIN_TABLE_31)
#define BB_RXCAL_TX_GAIN_TABLE_31_RXCAL_TX_GAIN_TABLE_31_MSB         19
#define BB_RXCAL_TX_GAIN_TABLE_31_RXCAL_TX_GAIN_TABLE_31_LSB         0
#define BB_RXCAL_TX_GAIN_TABLE_31_RXCAL_TX_GAIN_TABLE_31_MASK        0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_31_RXCAL_TX_GAIN_TABLE_31_GET(x)      (((x) & BB_RXCAL_TX_GAIN_TABLE_31_RXCAL_TX_GAIN_TABLE_31_MASK) >> BB_RXCAL_TX_GAIN_TABLE_31_RXCAL_TX_GAIN_TABLE_31_LSB)
#define BB_RXCAL_TX_GAIN_TABLE_31_RXCAL_TX_GAIN_TABLE_31_SET(x)      (((0 | (x)) << BB_RXCAL_TX_GAIN_TABLE_31_RXCAL_TX_GAIN_TABLE_31_LSB) & BB_RXCAL_TX_GAIN_TABLE_31_RXCAL_TX_GAIN_TABLE_31_MASK)
#define BB_RXCAL_TX_GAIN_TABLE_31_RXCAL_TX_GAIN_TABLE_31_RESET       0
#define BB_RXCAL_TX_GAIN_TABLE_31_ADDRESS                            0x117c
#define BB_RXCAL_TX_GAIN_TABLE_31_HW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_31_SW_MASK                            0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_31_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_TX_GAIN_TABLE_31_SW_WRITE_MASK                      0x000fffff
#define BB_RXCAL_TX_GAIN_TABLE_31_RSTMASK                            0xfff00000
#define BB_RXCAL_TX_GAIN_TABLE_31_RESET                              0x00000000

// 0x1180 (BB_RXCAL_RX_GAIN_TABLE_0)
#define BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_GAIN_DELTA_DB_TABLE_0_MSB     17
#define BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_GAIN_DELTA_DB_TABLE_0_LSB     12
#define BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_GAIN_DELTA_DB_TABLE_0_MASK    0x0003f000
#define BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_GAIN_DELTA_DB_TABLE_0_GET(x)  (((x) & BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_GAIN_DELTA_DB_TABLE_0_MASK) >> BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_GAIN_DELTA_DB_TABLE_0_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_GAIN_DELTA_DB_TABLE_0_SET(x)  (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_GAIN_DELTA_DB_TABLE_0_LSB) & BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_GAIN_DELTA_DB_TABLE_0_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_GAIN_DELTA_DB_TABLE_0_RESET   0
#define BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_RX_GAIN_TABLE_0_MSB           8
#define BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_RX_GAIN_TABLE_0_LSB           0
#define BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_RX_GAIN_TABLE_0_MASK          0x000001ff
#define BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_RX_GAIN_TABLE_0_GET(x)        (((x) & BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_RX_GAIN_TABLE_0_MASK) >> BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_RX_GAIN_TABLE_0_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_RX_GAIN_TABLE_0_SET(x)        (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_RX_GAIN_TABLE_0_LSB) & BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_RX_GAIN_TABLE_0_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_0_RXCAL_RX_GAIN_TABLE_0_RESET         0
#define BB_RXCAL_RX_GAIN_TABLE_0_ADDRESS                             0x1180
#define BB_RXCAL_RX_GAIN_TABLE_0_HW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_0_SW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_0_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_RX_GAIN_TABLE_0_SW_WRITE_MASK                       0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_0_RSTMASK                             0xfffc0e00
#define BB_RXCAL_RX_GAIN_TABLE_0_RESET                               0x00000000

// 0x1184 (BB_RXCAL_RX_GAIN_TABLE_1)
#define BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_GAIN_DELTA_DB_TABLE_1_MSB     17
#define BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_GAIN_DELTA_DB_TABLE_1_LSB     12
#define BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_GAIN_DELTA_DB_TABLE_1_MASK    0x0003f000
#define BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_GAIN_DELTA_DB_TABLE_1_GET(x)  (((x) & BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_GAIN_DELTA_DB_TABLE_1_MASK) >> BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_GAIN_DELTA_DB_TABLE_1_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_GAIN_DELTA_DB_TABLE_1_SET(x)  (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_GAIN_DELTA_DB_TABLE_1_LSB) & BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_GAIN_DELTA_DB_TABLE_1_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_GAIN_DELTA_DB_TABLE_1_RESET   0
#define BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_RX_GAIN_TABLE_1_MSB           8
#define BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_RX_GAIN_TABLE_1_LSB           0
#define BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_RX_GAIN_TABLE_1_MASK          0x000001ff
#define BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_RX_GAIN_TABLE_1_GET(x)        (((x) & BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_RX_GAIN_TABLE_1_MASK) >> BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_RX_GAIN_TABLE_1_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_RX_GAIN_TABLE_1_SET(x)        (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_RX_GAIN_TABLE_1_LSB) & BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_RX_GAIN_TABLE_1_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_1_RXCAL_RX_GAIN_TABLE_1_RESET         0
#define BB_RXCAL_RX_GAIN_TABLE_1_ADDRESS                             0x1184
#define BB_RXCAL_RX_GAIN_TABLE_1_HW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_1_SW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_1_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_RX_GAIN_TABLE_1_SW_WRITE_MASK                       0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_1_RSTMASK                             0xfffc0e00
#define BB_RXCAL_RX_GAIN_TABLE_1_RESET                               0x00000000

// 0x1188 (BB_RXCAL_RX_GAIN_TABLE_2)
#define BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_GAIN_DELTA_DB_TABLE_2_MSB     17
#define BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_GAIN_DELTA_DB_TABLE_2_LSB     12
#define BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_GAIN_DELTA_DB_TABLE_2_MASK    0x0003f000
#define BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_GAIN_DELTA_DB_TABLE_2_GET(x)  (((x) & BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_GAIN_DELTA_DB_TABLE_2_MASK) >> BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_GAIN_DELTA_DB_TABLE_2_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_GAIN_DELTA_DB_TABLE_2_SET(x)  (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_GAIN_DELTA_DB_TABLE_2_LSB) & BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_GAIN_DELTA_DB_TABLE_2_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_GAIN_DELTA_DB_TABLE_2_RESET   0
#define BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_RX_GAIN_TABLE_2_MSB           8
#define BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_RX_GAIN_TABLE_2_LSB           0
#define BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_RX_GAIN_TABLE_2_MASK          0x000001ff
#define BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_RX_GAIN_TABLE_2_GET(x)        (((x) & BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_RX_GAIN_TABLE_2_MASK) >> BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_RX_GAIN_TABLE_2_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_RX_GAIN_TABLE_2_SET(x)        (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_RX_GAIN_TABLE_2_LSB) & BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_RX_GAIN_TABLE_2_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_2_RXCAL_RX_GAIN_TABLE_2_RESET         0
#define BB_RXCAL_RX_GAIN_TABLE_2_ADDRESS                             0x1188
#define BB_RXCAL_RX_GAIN_TABLE_2_HW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_2_SW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_2_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_RX_GAIN_TABLE_2_SW_WRITE_MASK                       0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_2_RSTMASK                             0xfffc0e00
#define BB_RXCAL_RX_GAIN_TABLE_2_RESET                               0x00000000

// 0x118c (BB_RXCAL_RX_GAIN_TABLE_3)
#define BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_GAIN_DELTA_DB_TABLE_3_MSB     17
#define BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_GAIN_DELTA_DB_TABLE_3_LSB     12
#define BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_GAIN_DELTA_DB_TABLE_3_MASK    0x0003f000
#define BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_GAIN_DELTA_DB_TABLE_3_GET(x)  (((x) & BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_GAIN_DELTA_DB_TABLE_3_MASK) >> BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_GAIN_DELTA_DB_TABLE_3_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_GAIN_DELTA_DB_TABLE_3_SET(x)  (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_GAIN_DELTA_DB_TABLE_3_LSB) & BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_GAIN_DELTA_DB_TABLE_3_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_GAIN_DELTA_DB_TABLE_3_RESET   0
#define BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_RX_GAIN_TABLE_3_MSB           8
#define BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_RX_GAIN_TABLE_3_LSB           0
#define BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_RX_GAIN_TABLE_3_MASK          0x000001ff
#define BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_RX_GAIN_TABLE_3_GET(x)        (((x) & BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_RX_GAIN_TABLE_3_MASK) >> BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_RX_GAIN_TABLE_3_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_RX_GAIN_TABLE_3_SET(x)        (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_RX_GAIN_TABLE_3_LSB) & BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_RX_GAIN_TABLE_3_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_3_RXCAL_RX_GAIN_TABLE_3_RESET         0
#define BB_RXCAL_RX_GAIN_TABLE_3_ADDRESS                             0x118c
#define BB_RXCAL_RX_GAIN_TABLE_3_HW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_3_SW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_3_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_RX_GAIN_TABLE_3_SW_WRITE_MASK                       0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_3_RSTMASK                             0xfffc0e00
#define BB_RXCAL_RX_GAIN_TABLE_3_RESET                               0x00000000

// 0x1190 (BB_RXCAL_RX_GAIN_TABLE_4)
#define BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_GAIN_DELTA_DB_TABLE_4_MSB     17
#define BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_GAIN_DELTA_DB_TABLE_4_LSB     12
#define BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_GAIN_DELTA_DB_TABLE_4_MASK    0x0003f000
#define BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_GAIN_DELTA_DB_TABLE_4_GET(x)  (((x) & BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_GAIN_DELTA_DB_TABLE_4_MASK) >> BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_GAIN_DELTA_DB_TABLE_4_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_GAIN_DELTA_DB_TABLE_4_SET(x)  (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_GAIN_DELTA_DB_TABLE_4_LSB) & BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_GAIN_DELTA_DB_TABLE_4_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_GAIN_DELTA_DB_TABLE_4_RESET   0
#define BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_RX_GAIN_TABLE_4_MSB           8
#define BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_RX_GAIN_TABLE_4_LSB           0
#define BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_RX_GAIN_TABLE_4_MASK          0x000001ff
#define BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_RX_GAIN_TABLE_4_GET(x)        (((x) & BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_RX_GAIN_TABLE_4_MASK) >> BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_RX_GAIN_TABLE_4_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_RX_GAIN_TABLE_4_SET(x)        (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_RX_GAIN_TABLE_4_LSB) & BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_RX_GAIN_TABLE_4_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_4_RXCAL_RX_GAIN_TABLE_4_RESET         0
#define BB_RXCAL_RX_GAIN_TABLE_4_ADDRESS                             0x1190
#define BB_RXCAL_RX_GAIN_TABLE_4_HW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_4_SW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_4_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_RX_GAIN_TABLE_4_SW_WRITE_MASK                       0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_4_RSTMASK                             0xfffc0e00
#define BB_RXCAL_RX_GAIN_TABLE_4_RESET                               0x00000000

// 0x1194 (BB_RXCAL_RX_GAIN_TABLE_5)
#define BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_GAIN_DELTA_DB_TABLE_5_MSB     17
#define BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_GAIN_DELTA_DB_TABLE_5_LSB     12
#define BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_GAIN_DELTA_DB_TABLE_5_MASK    0x0003f000
#define BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_GAIN_DELTA_DB_TABLE_5_GET(x)  (((x) & BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_GAIN_DELTA_DB_TABLE_5_MASK) >> BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_GAIN_DELTA_DB_TABLE_5_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_GAIN_DELTA_DB_TABLE_5_SET(x)  (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_GAIN_DELTA_DB_TABLE_5_LSB) & BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_GAIN_DELTA_DB_TABLE_5_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_GAIN_DELTA_DB_TABLE_5_RESET   0
#define BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_RX_GAIN_TABLE_5_MSB           8
#define BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_RX_GAIN_TABLE_5_LSB           0
#define BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_RX_GAIN_TABLE_5_MASK          0x000001ff
#define BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_RX_GAIN_TABLE_5_GET(x)        (((x) & BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_RX_GAIN_TABLE_5_MASK) >> BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_RX_GAIN_TABLE_5_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_RX_GAIN_TABLE_5_SET(x)        (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_RX_GAIN_TABLE_5_LSB) & BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_RX_GAIN_TABLE_5_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_5_RXCAL_RX_GAIN_TABLE_5_RESET         0
#define BB_RXCAL_RX_GAIN_TABLE_5_ADDRESS                             0x1194
#define BB_RXCAL_RX_GAIN_TABLE_5_HW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_5_SW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_5_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_RX_GAIN_TABLE_5_SW_WRITE_MASK                       0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_5_RSTMASK                             0xfffc0e00
#define BB_RXCAL_RX_GAIN_TABLE_5_RESET                               0x00000000

// 0x1198 (BB_RXCAL_RX_GAIN_TABLE_6)
#define BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_GAIN_DELTA_DB_TABLE_6_MSB     17
#define BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_GAIN_DELTA_DB_TABLE_6_LSB     12
#define BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_GAIN_DELTA_DB_TABLE_6_MASK    0x0003f000
#define BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_GAIN_DELTA_DB_TABLE_6_GET(x)  (((x) & BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_GAIN_DELTA_DB_TABLE_6_MASK) >> BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_GAIN_DELTA_DB_TABLE_6_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_GAIN_DELTA_DB_TABLE_6_SET(x)  (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_GAIN_DELTA_DB_TABLE_6_LSB) & BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_GAIN_DELTA_DB_TABLE_6_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_GAIN_DELTA_DB_TABLE_6_RESET   0
#define BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_RX_GAIN_TABLE_6_MSB           8
#define BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_RX_GAIN_TABLE_6_LSB           0
#define BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_RX_GAIN_TABLE_6_MASK          0x000001ff
#define BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_RX_GAIN_TABLE_6_GET(x)        (((x) & BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_RX_GAIN_TABLE_6_MASK) >> BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_RX_GAIN_TABLE_6_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_RX_GAIN_TABLE_6_SET(x)        (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_RX_GAIN_TABLE_6_LSB) & BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_RX_GAIN_TABLE_6_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_6_RXCAL_RX_GAIN_TABLE_6_RESET         0
#define BB_RXCAL_RX_GAIN_TABLE_6_ADDRESS                             0x1198
#define BB_RXCAL_RX_GAIN_TABLE_6_HW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_6_SW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_6_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_RX_GAIN_TABLE_6_SW_WRITE_MASK                       0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_6_RSTMASK                             0xfffc0e00
#define BB_RXCAL_RX_GAIN_TABLE_6_RESET                               0x00000000

// 0x119c (BB_RXCAL_RX_GAIN_TABLE_7)
#define BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_GAIN_DELTA_DB_TABLE_7_MSB     17
#define BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_GAIN_DELTA_DB_TABLE_7_LSB     12
#define BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_GAIN_DELTA_DB_TABLE_7_MASK    0x0003f000
#define BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_GAIN_DELTA_DB_TABLE_7_GET(x)  (((x) & BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_GAIN_DELTA_DB_TABLE_7_MASK) >> BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_GAIN_DELTA_DB_TABLE_7_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_GAIN_DELTA_DB_TABLE_7_SET(x)  (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_GAIN_DELTA_DB_TABLE_7_LSB) & BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_GAIN_DELTA_DB_TABLE_7_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_GAIN_DELTA_DB_TABLE_7_RESET   0
#define BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_RX_GAIN_TABLE_7_MSB           8
#define BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_RX_GAIN_TABLE_7_LSB           0
#define BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_RX_GAIN_TABLE_7_MASK          0x000001ff
#define BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_RX_GAIN_TABLE_7_GET(x)        (((x) & BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_RX_GAIN_TABLE_7_MASK) >> BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_RX_GAIN_TABLE_7_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_RX_GAIN_TABLE_7_SET(x)        (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_RX_GAIN_TABLE_7_LSB) & BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_RX_GAIN_TABLE_7_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_7_RXCAL_RX_GAIN_TABLE_7_RESET         0
#define BB_RXCAL_RX_GAIN_TABLE_7_ADDRESS                             0x119c
#define BB_RXCAL_RX_GAIN_TABLE_7_HW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_7_SW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_7_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_RX_GAIN_TABLE_7_SW_WRITE_MASK                       0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_7_RSTMASK                             0xfffc0e00
#define BB_RXCAL_RX_GAIN_TABLE_7_RESET                               0x00000000

// 0x11a0 (BB_RXCAL_RX_GAIN_TABLE_8)
#define BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_GAIN_DELTA_DB_TABLE_8_MSB     17
#define BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_GAIN_DELTA_DB_TABLE_8_LSB     12
#define BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_GAIN_DELTA_DB_TABLE_8_MASK    0x0003f000
#define BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_GAIN_DELTA_DB_TABLE_8_GET(x)  (((x) & BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_GAIN_DELTA_DB_TABLE_8_MASK) >> BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_GAIN_DELTA_DB_TABLE_8_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_GAIN_DELTA_DB_TABLE_8_SET(x)  (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_GAIN_DELTA_DB_TABLE_8_LSB) & BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_GAIN_DELTA_DB_TABLE_8_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_GAIN_DELTA_DB_TABLE_8_RESET   0
#define BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_RX_GAIN_TABLE_8_MSB           8
#define BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_RX_GAIN_TABLE_8_LSB           0
#define BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_RX_GAIN_TABLE_8_MASK          0x000001ff
#define BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_RX_GAIN_TABLE_8_GET(x)        (((x) & BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_RX_GAIN_TABLE_8_MASK) >> BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_RX_GAIN_TABLE_8_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_RX_GAIN_TABLE_8_SET(x)        (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_RX_GAIN_TABLE_8_LSB) & BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_RX_GAIN_TABLE_8_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_8_RXCAL_RX_GAIN_TABLE_8_RESET         0
#define BB_RXCAL_RX_GAIN_TABLE_8_ADDRESS                             0x11a0
#define BB_RXCAL_RX_GAIN_TABLE_8_HW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_8_SW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_8_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_RX_GAIN_TABLE_8_SW_WRITE_MASK                       0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_8_RSTMASK                             0xfffc0e00
#define BB_RXCAL_RX_GAIN_TABLE_8_RESET                               0x00000000

// 0x11a4 (BB_RXCAL_RX_GAIN_TABLE_9)
#define BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_GAIN_DELTA_DB_TABLE_9_MSB     17
#define BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_GAIN_DELTA_DB_TABLE_9_LSB     12
#define BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_GAIN_DELTA_DB_TABLE_9_MASK    0x0003f000
#define BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_GAIN_DELTA_DB_TABLE_9_GET(x)  (((x) & BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_GAIN_DELTA_DB_TABLE_9_MASK) >> BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_GAIN_DELTA_DB_TABLE_9_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_GAIN_DELTA_DB_TABLE_9_SET(x)  (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_GAIN_DELTA_DB_TABLE_9_LSB) & BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_GAIN_DELTA_DB_TABLE_9_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_GAIN_DELTA_DB_TABLE_9_RESET   0
#define BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_RX_GAIN_TABLE_9_MSB           8
#define BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_RX_GAIN_TABLE_9_LSB           0
#define BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_RX_GAIN_TABLE_9_MASK          0x000001ff
#define BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_RX_GAIN_TABLE_9_GET(x)        (((x) & BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_RX_GAIN_TABLE_9_MASK) >> BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_RX_GAIN_TABLE_9_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_RX_GAIN_TABLE_9_SET(x)        (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_RX_GAIN_TABLE_9_LSB) & BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_RX_GAIN_TABLE_9_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_9_RXCAL_RX_GAIN_TABLE_9_RESET         0
#define BB_RXCAL_RX_GAIN_TABLE_9_ADDRESS                             0x11a4
#define BB_RXCAL_RX_GAIN_TABLE_9_HW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_9_SW_MASK                             0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_9_HW_WRITE_MASK                       0x00000000
#define BB_RXCAL_RX_GAIN_TABLE_9_SW_WRITE_MASK                       0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_9_RSTMASK                             0xfffc0e00
#define BB_RXCAL_RX_GAIN_TABLE_9_RESET                               0x00000000

// 0x11a8 (BB_RXCAL_RX_GAIN_TABLE_10)
#define BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_GAIN_DELTA_DB_TABLE_10_MSB   17
#define BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_GAIN_DELTA_DB_TABLE_10_LSB   12
#define BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_GAIN_DELTA_DB_TABLE_10_MASK  0x0003f000
#define BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_GAIN_DELTA_DB_TABLE_10_GET(x) (((x) & BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_GAIN_DELTA_DB_TABLE_10_MASK) >> BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_GAIN_DELTA_DB_TABLE_10_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_GAIN_DELTA_DB_TABLE_10_SET(x) (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_GAIN_DELTA_DB_TABLE_10_LSB) & BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_GAIN_DELTA_DB_TABLE_10_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_GAIN_DELTA_DB_TABLE_10_RESET 0
#define BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_RX_GAIN_TABLE_10_MSB         8
#define BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_RX_GAIN_TABLE_10_LSB         0
#define BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_RX_GAIN_TABLE_10_MASK        0x000001ff
#define BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_RX_GAIN_TABLE_10_GET(x)      (((x) & BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_RX_GAIN_TABLE_10_MASK) >> BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_RX_GAIN_TABLE_10_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_RX_GAIN_TABLE_10_SET(x)      (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_RX_GAIN_TABLE_10_LSB) & BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_RX_GAIN_TABLE_10_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_10_RXCAL_RX_GAIN_TABLE_10_RESET       0
#define BB_RXCAL_RX_GAIN_TABLE_10_ADDRESS                            0x11a8
#define BB_RXCAL_RX_GAIN_TABLE_10_HW_MASK                            0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_10_SW_MASK                            0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_10_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_RX_GAIN_TABLE_10_SW_WRITE_MASK                      0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_10_RSTMASK                            0xfffc0e00
#define BB_RXCAL_RX_GAIN_TABLE_10_RESET                              0x00000000

// 0x11ac (BB_RXCAL_RX_GAIN_TABLE_11)
#define BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_GAIN_DELTA_DB_TABLE_11_MSB   17
#define BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_GAIN_DELTA_DB_TABLE_11_LSB   12
#define BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_GAIN_DELTA_DB_TABLE_11_MASK  0x0003f000
#define BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_GAIN_DELTA_DB_TABLE_11_GET(x) (((x) & BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_GAIN_DELTA_DB_TABLE_11_MASK) >> BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_GAIN_DELTA_DB_TABLE_11_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_GAIN_DELTA_DB_TABLE_11_SET(x) (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_GAIN_DELTA_DB_TABLE_11_LSB) & BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_GAIN_DELTA_DB_TABLE_11_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_GAIN_DELTA_DB_TABLE_11_RESET 0
#define BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_RX_GAIN_TABLE_11_MSB         8
#define BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_RX_GAIN_TABLE_11_LSB         0
#define BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_RX_GAIN_TABLE_11_MASK        0x000001ff
#define BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_RX_GAIN_TABLE_11_GET(x)      (((x) & BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_RX_GAIN_TABLE_11_MASK) >> BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_RX_GAIN_TABLE_11_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_RX_GAIN_TABLE_11_SET(x)      (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_RX_GAIN_TABLE_11_LSB) & BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_RX_GAIN_TABLE_11_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_11_RXCAL_RX_GAIN_TABLE_11_RESET       0
#define BB_RXCAL_RX_GAIN_TABLE_11_ADDRESS                            0x11ac
#define BB_RXCAL_RX_GAIN_TABLE_11_HW_MASK                            0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_11_SW_MASK                            0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_11_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_RX_GAIN_TABLE_11_SW_WRITE_MASK                      0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_11_RSTMASK                            0xfffc0e00
#define BB_RXCAL_RX_GAIN_TABLE_11_RESET                              0x00000000

// 0x11b0 (BB_RXCAL_RX_GAIN_TABLE_12)
#define BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_GAIN_DELTA_DB_TABLE_12_MSB   17
#define BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_GAIN_DELTA_DB_TABLE_12_LSB   12
#define BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_GAIN_DELTA_DB_TABLE_12_MASK  0x0003f000
#define BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_GAIN_DELTA_DB_TABLE_12_GET(x) (((x) & BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_GAIN_DELTA_DB_TABLE_12_MASK) >> BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_GAIN_DELTA_DB_TABLE_12_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_GAIN_DELTA_DB_TABLE_12_SET(x) (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_GAIN_DELTA_DB_TABLE_12_LSB) & BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_GAIN_DELTA_DB_TABLE_12_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_GAIN_DELTA_DB_TABLE_12_RESET 0
#define BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_RX_GAIN_TABLE_12_MSB         8
#define BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_RX_GAIN_TABLE_12_LSB         0
#define BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_RX_GAIN_TABLE_12_MASK        0x000001ff
#define BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_RX_GAIN_TABLE_12_GET(x)      (((x) & BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_RX_GAIN_TABLE_12_MASK) >> BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_RX_GAIN_TABLE_12_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_RX_GAIN_TABLE_12_SET(x)      (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_RX_GAIN_TABLE_12_LSB) & BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_RX_GAIN_TABLE_12_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_12_RXCAL_RX_GAIN_TABLE_12_RESET       0
#define BB_RXCAL_RX_GAIN_TABLE_12_ADDRESS                            0x11b0
#define BB_RXCAL_RX_GAIN_TABLE_12_HW_MASK                            0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_12_SW_MASK                            0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_12_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_RX_GAIN_TABLE_12_SW_WRITE_MASK                      0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_12_RSTMASK                            0xfffc0e00
#define BB_RXCAL_RX_GAIN_TABLE_12_RESET                              0x00000000

// 0x11b4 (BB_RXCAL_RX_GAIN_TABLE_13)
#define BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_GAIN_DELTA_DB_TABLE_13_MSB   17
#define BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_GAIN_DELTA_DB_TABLE_13_LSB   12
#define BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_GAIN_DELTA_DB_TABLE_13_MASK  0x0003f000
#define BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_GAIN_DELTA_DB_TABLE_13_GET(x) (((x) & BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_GAIN_DELTA_DB_TABLE_13_MASK) >> BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_GAIN_DELTA_DB_TABLE_13_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_GAIN_DELTA_DB_TABLE_13_SET(x) (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_GAIN_DELTA_DB_TABLE_13_LSB) & BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_GAIN_DELTA_DB_TABLE_13_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_GAIN_DELTA_DB_TABLE_13_RESET 0
#define BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_RX_GAIN_TABLE_13_MSB         8
#define BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_RX_GAIN_TABLE_13_LSB         0
#define BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_RX_GAIN_TABLE_13_MASK        0x000001ff
#define BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_RX_GAIN_TABLE_13_GET(x)      (((x) & BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_RX_GAIN_TABLE_13_MASK) >> BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_RX_GAIN_TABLE_13_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_RX_GAIN_TABLE_13_SET(x)      (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_RX_GAIN_TABLE_13_LSB) & BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_RX_GAIN_TABLE_13_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_13_RXCAL_RX_GAIN_TABLE_13_RESET       0
#define BB_RXCAL_RX_GAIN_TABLE_13_ADDRESS                            0x11b4
#define BB_RXCAL_RX_GAIN_TABLE_13_HW_MASK                            0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_13_SW_MASK                            0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_13_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_RX_GAIN_TABLE_13_SW_WRITE_MASK                      0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_13_RSTMASK                            0xfffc0e00
#define BB_RXCAL_RX_GAIN_TABLE_13_RESET                              0x00000000

// 0x11b8 (BB_RXCAL_RX_GAIN_TABLE_14)
#define BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_GAIN_DELTA_DB_TABLE_14_MSB   17
#define BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_GAIN_DELTA_DB_TABLE_14_LSB   12
#define BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_GAIN_DELTA_DB_TABLE_14_MASK  0x0003f000
#define BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_GAIN_DELTA_DB_TABLE_14_GET(x) (((x) & BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_GAIN_DELTA_DB_TABLE_14_MASK) >> BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_GAIN_DELTA_DB_TABLE_14_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_GAIN_DELTA_DB_TABLE_14_SET(x) (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_GAIN_DELTA_DB_TABLE_14_LSB) & BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_GAIN_DELTA_DB_TABLE_14_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_GAIN_DELTA_DB_TABLE_14_RESET 0
#define BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_RX_GAIN_TABLE_14_MSB         8
#define BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_RX_GAIN_TABLE_14_LSB         0
#define BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_RX_GAIN_TABLE_14_MASK        0x000001ff
#define BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_RX_GAIN_TABLE_14_GET(x)      (((x) & BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_RX_GAIN_TABLE_14_MASK) >> BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_RX_GAIN_TABLE_14_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_RX_GAIN_TABLE_14_SET(x)      (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_RX_GAIN_TABLE_14_LSB) & BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_RX_GAIN_TABLE_14_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_14_RXCAL_RX_GAIN_TABLE_14_RESET       0
#define BB_RXCAL_RX_GAIN_TABLE_14_ADDRESS                            0x11b8
#define BB_RXCAL_RX_GAIN_TABLE_14_HW_MASK                            0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_14_SW_MASK                            0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_14_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_RX_GAIN_TABLE_14_SW_WRITE_MASK                      0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_14_RSTMASK                            0xfffc0e00
#define BB_RXCAL_RX_GAIN_TABLE_14_RESET                              0x00000000

// 0x11bc (BB_RXCAL_RX_GAIN_TABLE_15)
#define BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_GAIN_DELTA_DB_TABLE_15_MSB   17
#define BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_GAIN_DELTA_DB_TABLE_15_LSB   12
#define BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_GAIN_DELTA_DB_TABLE_15_MASK  0x0003f000
#define BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_GAIN_DELTA_DB_TABLE_15_GET(x) (((x) & BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_GAIN_DELTA_DB_TABLE_15_MASK) >> BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_GAIN_DELTA_DB_TABLE_15_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_GAIN_DELTA_DB_TABLE_15_SET(x) (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_GAIN_DELTA_DB_TABLE_15_LSB) & BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_GAIN_DELTA_DB_TABLE_15_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_GAIN_DELTA_DB_TABLE_15_RESET 0
#define BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_RX_GAIN_TABLE_15_MSB         8
#define BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_RX_GAIN_TABLE_15_LSB         0
#define BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_RX_GAIN_TABLE_15_MASK        0x000001ff
#define BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_RX_GAIN_TABLE_15_GET(x)      (((x) & BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_RX_GAIN_TABLE_15_MASK) >> BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_RX_GAIN_TABLE_15_LSB)
#define BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_RX_GAIN_TABLE_15_SET(x)      (((0 | (x)) << BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_RX_GAIN_TABLE_15_LSB) & BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_RX_GAIN_TABLE_15_MASK)
#define BB_RXCAL_RX_GAIN_TABLE_15_RXCAL_RX_GAIN_TABLE_15_RESET       0
#define BB_RXCAL_RX_GAIN_TABLE_15_ADDRESS                            0x11bc
#define BB_RXCAL_RX_GAIN_TABLE_15_HW_MASK                            0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_15_SW_MASK                            0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_15_HW_WRITE_MASK                      0x00000000
#define BB_RXCAL_RX_GAIN_TABLE_15_SW_WRITE_MASK                      0x0003f1ff
#define BB_RXCAL_RX_GAIN_TABLE_15_RSTMASK                            0xfffc0e00
#define BB_RXCAL_RX_GAIN_TABLE_15_RESET                              0x00000000

// 0x1200 (BB_SM_TABLES_DUMMY2)
#define BB_SM_TABLES_DUMMY2_DUMMY2_MSB                               31
#define BB_SM_TABLES_DUMMY2_DUMMY2_LSB                               0
#define BB_SM_TABLES_DUMMY2_DUMMY2_MASK                              0xffffffff
#define BB_SM_TABLES_DUMMY2_DUMMY2_GET(x)                            (((x) & BB_SM_TABLES_DUMMY2_DUMMY2_MASK) >> BB_SM_TABLES_DUMMY2_DUMMY2_LSB)
#define BB_SM_TABLES_DUMMY2_DUMMY2_SET(x)                            (((0 | (x)) << BB_SM_TABLES_DUMMY2_DUMMY2_LSB) & BB_SM_TABLES_DUMMY2_DUMMY2_MASK)
#define BB_SM_TABLES_DUMMY2_DUMMY2_RESET                             0
#define BB_SM_TABLES_DUMMY2_ADDRESS                                  0x1200
#define BB_SM_TABLES_DUMMY2_HW_MASK                                  0xffffffff
#define BB_SM_TABLES_DUMMY2_SW_MASK                                  0xffffffff
#define BB_SM_TABLES_DUMMY2_HW_WRITE_MASK                            0x00000000
#define BB_SM_TABLES_DUMMY2_SW_WRITE_MASK                            0xffffffff
#define BB_SM_TABLES_DUMMY2_RSTMASK                                  0x00000000
#define BB_SM_TABLES_DUMMY2_RESET                                    0x00000000


#endif /* _SM_TABLE_MAP_H_ */
