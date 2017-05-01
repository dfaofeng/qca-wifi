//                                                                             
// File:       ./sm_table_map.vrh                                              
// Creator:    tyzhang                                                         
// Time:       Thursday Aug 23, 2012 [3:27:41 pm]                              
//                                                                             
// Path:       /localtrees/tyzhang/tianfang_hanw_depot/chips/rome/dev/doc/headers/wl_soc_mac
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc ./sm_table_map.rdl     
//                                                                             
// Sources:    /localtrees/tyzhang/tianfang_hanw_depot/chips/rome/dev/doc/headers/wl_soc_mac/sm_table_map_sysconfig.rdl
//             /localtrees/tyzhang/tianfang_hanw_depot/chips/rome/dev/doc/ip/R1_IP5/rtl/bb_2x2/blueprint/sm_table_map.rdl
//             /localtrees/tyzhang/tianfang_hanw_depot/chips/rome/dev/env/blueprint/ath_vrh.pm
//             /cad/local/lib/perl/Pinfo.pm                                    
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    hanw                                                            
// OS:         Linux 2.6.9-89.ELlargesmp                                       
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
