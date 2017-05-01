//                                                                             
// File:       /trees/xiaoru/xiaoru-tree/ip/athr/wifi/dev/rtl/bb/blueprint/sm1_table_map.vrh
// Creator:    xiaoru                                                          
// Time:       Thursday May 17, 2012 [3:09:20 pm]                              
//                                                                             
// Path:       /trees/xiaoru/xiaoru-tree/ip/athr/wifi/dev/rtl/bb/blueprint     
// Arguments:  /cad/denali/blueprint/3.7_64_32//Linux/blueprint -odir          
//             /trees/xiaoru/xiaoru-tree/ip/athr/wifi/dev/rtl/bb/blueprint     
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc sm1_table_map.rdl      
//                                                                             
// Sources:    /trees/xiaoru/xiaoru-tree/ip/athr/wifi/dev/shared/blueprint/sysconfig/sm1_table_map_sysconfig.rdl
//             /trees/xiaoru/xiaoru-tree/ip/athr/wifi/dev/rtl/bb/blueprint/sm1_table_map.rdl
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


#ifndef _SM1_TABLE_MAP_H_
#define _SM1_TABLE_MAP_H_
// 0x0000 (BB_SM1_TABLES_DUMMY1)
#define BB_SM1_TABLES_DUMMY1_DUMMY1_MSB                              31
#define BB_SM1_TABLES_DUMMY1_DUMMY1_LSB                              0
#define BB_SM1_TABLES_DUMMY1_DUMMY1_MASK                             0xffffffff
#define BB_SM1_TABLES_DUMMY1_DUMMY1_GET(x)                           (((x) & BB_SM1_TABLES_DUMMY1_DUMMY1_MASK) >> BB_SM1_TABLES_DUMMY1_DUMMY1_LSB)
#define BB_SM1_TABLES_DUMMY1_DUMMY1_SET(x)                           (((0 | (x)) << BB_SM1_TABLES_DUMMY1_DUMMY1_LSB) & BB_SM1_TABLES_DUMMY1_DUMMY1_MASK)
#define BB_SM1_TABLES_DUMMY1_DUMMY1_RESET                            0
#define BB_SM1_TABLES_DUMMY1_ADDRESS                                 0x0000
#define BB_SM1_TABLES_DUMMY1_HW_MASK                                 0xffffffff
#define BB_SM1_TABLES_DUMMY1_SW_MASK                                 0xffffffff
#define BB_SM1_TABLES_DUMMY1_HW_WRITE_MASK                           0x00000000
#define BB_SM1_TABLES_DUMMY1_SW_WRITE_MASK                           0xffffffff
#define BB_SM1_TABLES_DUMMY1_RSTMASK                                 0x00000000
#define BB_SM1_TABLES_DUMMY1_RESET                                   0x00000000

// 0x03c0 (BB_DC_DAC_MEM_B1_0)
#define BB_DC_DAC_MEM_B1_0_DC_DAC_SETTING_MSB                        19
#define BB_DC_DAC_MEM_B1_0_DC_DAC_SETTING_LSB                        0
#define BB_DC_DAC_MEM_B1_0_DC_DAC_SETTING_MASK                       0x000fffff
#define BB_DC_DAC_MEM_B1_0_DC_DAC_SETTING_GET(x)                     (((x) & BB_DC_DAC_MEM_B1_0_DC_DAC_SETTING_MASK) >> BB_DC_DAC_MEM_B1_0_DC_DAC_SETTING_LSB)
#define BB_DC_DAC_MEM_B1_0_DC_DAC_SETTING_SET(x)                     (((0 | (x)) << BB_DC_DAC_MEM_B1_0_DC_DAC_SETTING_LSB) & BB_DC_DAC_MEM_B1_0_DC_DAC_SETTING_MASK)
#define BB_DC_DAC_MEM_B1_0_DC_DAC_SETTING_RESET                      0
#define BB_DC_DAC_MEM_B1_0_ADDRESS                                   0x03c0
#define BB_DC_DAC_MEM_B1_ADDRESS                                     BB_DC_DAC_MEM_B1_0_ADDRESS
#define BB_DC_DAC_MEM_B1_0_HW_MASK                                   0x000fffff
#define BB_DC_DAC_MEM_B1_0_SW_MASK                                   0x000fffff
#define BB_DC_DAC_MEM_B1_0_HW_WRITE_MASK                             0x000fffff
#define BB_DC_DAC_MEM_B1_0_SW_WRITE_MASK                             0x000fffff
#define BB_DC_DAC_MEM_B1_0_RSTMASK                                   0xffffffff
#define BB_DC_DAC_MEM_B1_0_RESET                                     0x00000000

// 0x03c4 (BB_DC_DAC_MEM_B1_1)
#define BB_DC_DAC_MEM_B1_1_DC_DAC_SETTING_MSB                        19
#define BB_DC_DAC_MEM_B1_1_DC_DAC_SETTING_LSB                        0
#define BB_DC_DAC_MEM_B1_1_DC_DAC_SETTING_MASK                       0x000fffff
#define BB_DC_DAC_MEM_B1_1_DC_DAC_SETTING_GET(x)                     (((x) & BB_DC_DAC_MEM_B1_1_DC_DAC_SETTING_MASK) >> BB_DC_DAC_MEM_B1_1_DC_DAC_SETTING_LSB)
#define BB_DC_DAC_MEM_B1_1_DC_DAC_SETTING_SET(x)                     (((0 | (x)) << BB_DC_DAC_MEM_B1_1_DC_DAC_SETTING_LSB) & BB_DC_DAC_MEM_B1_1_DC_DAC_SETTING_MASK)
#define BB_DC_DAC_MEM_B1_1_DC_DAC_SETTING_RESET                      0
#define BB_DC_DAC_MEM_B1_1_ADDRESS                                   0x03c4
#define BB_DC_DAC_MEM_B1_1_HW_MASK                                   0x000fffff
#define BB_DC_DAC_MEM_B1_1_SW_MASK                                   0x000fffff
#define BB_DC_DAC_MEM_B1_1_HW_WRITE_MASK                             0x000fffff
#define BB_DC_DAC_MEM_B1_1_SW_WRITE_MASK                             0x000fffff
#define BB_DC_DAC_MEM_B1_1_RSTMASK                                   0xffffffff
#define BB_DC_DAC_MEM_B1_1_RESET                                     0x00000000

// 0x03c8 (BB_DC_DAC_MEM_B1_2)
#define BB_DC_DAC_MEM_B1_2_DC_DAC_SETTING_MSB                        19
#define BB_DC_DAC_MEM_B1_2_DC_DAC_SETTING_LSB                        0
#define BB_DC_DAC_MEM_B1_2_DC_DAC_SETTING_MASK                       0x000fffff
#define BB_DC_DAC_MEM_B1_2_DC_DAC_SETTING_GET(x)                     (((x) & BB_DC_DAC_MEM_B1_2_DC_DAC_SETTING_MASK) >> BB_DC_DAC_MEM_B1_2_DC_DAC_SETTING_LSB)
#define BB_DC_DAC_MEM_B1_2_DC_DAC_SETTING_SET(x)                     (((0 | (x)) << BB_DC_DAC_MEM_B1_2_DC_DAC_SETTING_LSB) & BB_DC_DAC_MEM_B1_2_DC_DAC_SETTING_MASK)
#define BB_DC_DAC_MEM_B1_2_DC_DAC_SETTING_RESET                      0
#define BB_DC_DAC_MEM_B1_2_ADDRESS                                   0x03c8
#define BB_DC_DAC_MEM_B1_2_HW_MASK                                   0x000fffff
#define BB_DC_DAC_MEM_B1_2_SW_MASK                                   0x000fffff
#define BB_DC_DAC_MEM_B1_2_HW_WRITE_MASK                             0x000fffff
#define BB_DC_DAC_MEM_B1_2_SW_WRITE_MASK                             0x000fffff
#define BB_DC_DAC_MEM_B1_2_RSTMASK                                   0xffffffff
#define BB_DC_DAC_MEM_B1_2_RESET                                     0x00000000

// 0x03cc (BB_DC_DAC_MEM_B1_3)
#define BB_DC_DAC_MEM_B1_3_DC_DAC_SETTING_MSB                        19
#define BB_DC_DAC_MEM_B1_3_DC_DAC_SETTING_LSB                        0
#define BB_DC_DAC_MEM_B1_3_DC_DAC_SETTING_MASK                       0x000fffff
#define BB_DC_DAC_MEM_B1_3_DC_DAC_SETTING_GET(x)                     (((x) & BB_DC_DAC_MEM_B1_3_DC_DAC_SETTING_MASK) >> BB_DC_DAC_MEM_B1_3_DC_DAC_SETTING_LSB)
#define BB_DC_DAC_MEM_B1_3_DC_DAC_SETTING_SET(x)                     (((0 | (x)) << BB_DC_DAC_MEM_B1_3_DC_DAC_SETTING_LSB) & BB_DC_DAC_MEM_B1_3_DC_DAC_SETTING_MASK)
#define BB_DC_DAC_MEM_B1_3_DC_DAC_SETTING_RESET                      0
#define BB_DC_DAC_MEM_B1_3_ADDRESS                                   0x03cc
#define BB_DC_DAC_MEM_B1_3_HW_MASK                                   0x000fffff
#define BB_DC_DAC_MEM_B1_3_SW_MASK                                   0x000fffff
#define BB_DC_DAC_MEM_B1_3_HW_WRITE_MASK                             0x000fffff
#define BB_DC_DAC_MEM_B1_3_SW_WRITE_MASK                             0x000fffff
#define BB_DC_DAC_MEM_B1_3_RSTMASK                                   0xffffffff
#define BB_DC_DAC_MEM_B1_3_RESET                                     0x00000000

// 0x05fc (BB_SM1_TABLES_DUMMY2)
#define BB_SM1_TABLES_DUMMY2_DUMMY2_MSB                              31
#define BB_SM1_TABLES_DUMMY2_DUMMY2_LSB                              0
#define BB_SM1_TABLES_DUMMY2_DUMMY2_MASK                             0xffffffff
#define BB_SM1_TABLES_DUMMY2_DUMMY2_GET(x)                           (((x) & BB_SM1_TABLES_DUMMY2_DUMMY2_MASK) >> BB_SM1_TABLES_DUMMY2_DUMMY2_LSB)
#define BB_SM1_TABLES_DUMMY2_DUMMY2_SET(x)                           (((0 | (x)) << BB_SM1_TABLES_DUMMY2_DUMMY2_LSB) & BB_SM1_TABLES_DUMMY2_DUMMY2_MASK)
#define BB_SM1_TABLES_DUMMY2_DUMMY2_RESET                            0
#define BB_SM1_TABLES_DUMMY2_ADDRESS                                 0x05fc
#define BB_SM1_TABLES_DUMMY2_HW_MASK                                 0xffffffff
#define BB_SM1_TABLES_DUMMY2_SW_MASK                                 0xffffffff
#define BB_SM1_TABLES_DUMMY2_HW_WRITE_MASK                           0x00000000
#define BB_SM1_TABLES_DUMMY2_SW_WRITE_MASK                           0xffffffff
#define BB_SM1_TABLES_DUMMY2_RSTMASK                                 0x00000000
#define BB_SM1_TABLES_DUMMY2_RESET                                   0x00000000


#endif /* _SM1_TABLE_MAP_H_ */
