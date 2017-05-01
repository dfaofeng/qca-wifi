//                                                                             
// File:       ./merlin2_0_radio_reg.vrh                                       
// Creator:    tyzhang                                                         
// Time:       Saturday Jul 14, 2012 [7:44:02 am]                              
//                                                                             
// Path:       /trees/mbu-cn1/tyzhang/tianfang_enc_depot/chips/rome/dev/doc/headers/wl_soc_mac
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc                        
//             ./merlin2_0_radio_reg.rdl                                       
//                                                                             
// Sources:    /trees/mbu-cn1/tyzhang/tianfang_enc_depot/chips/rome/dev/doc/headers/wl_soc_mac/./merlin2_0_radio_reg.rdl
//             /trees/mbu-cn1/tyzhang/tianfang_enc_depot/chips/rome/dev/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    dev24                                                           
// OS:         Linux 2.6.9-89.ELlargesmp                                       
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _MERLIN2_0_RADIO_REG_H_
#define _MERLIN2_0_RADIO_REG_H_
// 0x0000 (RXTXBB1_CH1)
#define RXTXBB1_CH1_SPARE_MSB                                        31
#define RXTXBB1_CH1_SPARE_LSB                                        19
#define RXTXBB1_CH1_SPARE_MASK                                       0xfff80000
#define RXTXBB1_CH1_SPARE_GET(x)                                     (((x) & RXTXBB1_CH1_SPARE_MASK) >> RXTXBB1_CH1_SPARE_LSB)
#define RXTXBB1_CH1_SPARE_SET(x)                                     (((0 | (x)) << RXTXBB1_CH1_SPARE_LSB) & RXTXBB1_CH1_SPARE_MASK)
#define RXTXBB1_CH1_SPARE_RESET                                      0
#define RXTXBB1_CH1_FNOTCH_MSB                                       18
#define RXTXBB1_CH1_FNOTCH_LSB                                       17
#define RXTXBB1_CH1_FNOTCH_MASK                                      0x00060000
#define RXTXBB1_CH1_FNOTCH_GET(x)                                    (((x) & RXTXBB1_CH1_FNOTCH_MASK) >> RXTXBB1_CH1_FNOTCH_LSB)
#define RXTXBB1_CH1_FNOTCH_SET(x)                                    (((0 | (x)) << RXTXBB1_CH1_FNOTCH_LSB) & RXTXBB1_CH1_FNOTCH_MASK)
#define RXTXBB1_CH1_FNOTCH_RESET                                     0
#define RXTXBB1_CH1_SEL_ATB_MSB                                      16
#define RXTXBB1_CH1_SEL_ATB_LSB                                      9
#define RXTXBB1_CH1_SEL_ATB_MASK                                     0x0001fe00
#define RXTXBB1_CH1_SEL_ATB_GET(x)                                   (((x) & RXTXBB1_CH1_SEL_ATB_MASK) >> RXTXBB1_CH1_SEL_ATB_LSB)
#define RXTXBB1_CH1_SEL_ATB_SET(x)                                   (((0 | (x)) << RXTXBB1_CH1_SEL_ATB_LSB) & RXTXBB1_CH1_SEL_ATB_MASK)
#define RXTXBB1_CH1_SEL_ATB_RESET                                    0
#define RXTXBB1_CH1_PDDACINTERFACE_MSB                               8
#define RXTXBB1_CH1_PDDACINTERFACE_LSB                               8
#define RXTXBB1_CH1_PDDACINTERFACE_MASK                              0x00000100
#define RXTXBB1_CH1_PDDACINTERFACE_GET(x)                            (((x) & RXTXBB1_CH1_PDDACINTERFACE_MASK) >> RXTXBB1_CH1_PDDACINTERFACE_LSB)
#define RXTXBB1_CH1_PDDACINTERFACE_SET(x)                            (((0 | (x)) << RXTXBB1_CH1_PDDACINTERFACE_LSB) & RXTXBB1_CH1_PDDACINTERFACE_MASK)
#define RXTXBB1_CH1_PDDACINTERFACE_RESET                             0
#define RXTXBB1_CH1_PDV2I_MSB                                        7
#define RXTXBB1_CH1_PDV2I_LSB                                        7
#define RXTXBB1_CH1_PDV2I_MASK                                       0x00000080
#define RXTXBB1_CH1_PDV2I_GET(x)                                     (((x) & RXTXBB1_CH1_PDV2I_MASK) >> RXTXBB1_CH1_PDV2I_LSB)
#define RXTXBB1_CH1_PDV2I_SET(x)                                     (((0 | (x)) << RXTXBB1_CH1_PDV2I_LSB) & RXTXBB1_CH1_PDV2I_MASK)
#define RXTXBB1_CH1_PDV2I_RESET                                      0
#define RXTXBB1_CH1_PDI2V_MSB                                        6
#define RXTXBB1_CH1_PDI2V_LSB                                        6
#define RXTXBB1_CH1_PDI2V_MASK                                       0x00000040
#define RXTXBB1_CH1_PDI2V_GET(x)                                     (((x) & RXTXBB1_CH1_PDI2V_MASK) >> RXTXBB1_CH1_PDI2V_LSB)
#define RXTXBB1_CH1_PDI2V_SET(x)                                     (((0 | (x)) << RXTXBB1_CH1_PDI2V_LSB) & RXTXBB1_CH1_PDI2V_MASK)
#define RXTXBB1_CH1_PDI2V_RESET                                      0
#define RXTXBB1_CH1_PDRXTXBB_MSB                                     5
#define RXTXBB1_CH1_PDRXTXBB_LSB                                     5
#define RXTXBB1_CH1_PDRXTXBB_MASK                                    0x00000020
#define RXTXBB1_CH1_PDRXTXBB_GET(x)                                  (((x) & RXTXBB1_CH1_PDRXTXBB_MASK) >> RXTXBB1_CH1_PDRXTXBB_LSB)
#define RXTXBB1_CH1_PDRXTXBB_SET(x)                                  (((0 | (x)) << RXTXBB1_CH1_PDRXTXBB_LSB) & RXTXBB1_CH1_PDRXTXBB_MASK)
#define RXTXBB1_CH1_PDRXTXBB_RESET                                   0
#define RXTXBB1_CH1_PDOFFSETLOQ_MSB                                  4
#define RXTXBB1_CH1_PDOFFSETLOQ_LSB                                  4
#define RXTXBB1_CH1_PDOFFSETLOQ_MASK                                 0x00000010
#define RXTXBB1_CH1_PDOFFSETLOQ_GET(x)                               (((x) & RXTXBB1_CH1_PDOFFSETLOQ_MASK) >> RXTXBB1_CH1_PDOFFSETLOQ_LSB)
#define RXTXBB1_CH1_PDOFFSETLOQ_SET(x)                               (((0 | (x)) << RXTXBB1_CH1_PDOFFSETLOQ_LSB) & RXTXBB1_CH1_PDOFFSETLOQ_MASK)
#define RXTXBB1_CH1_PDOFFSETLOQ_RESET                                0
#define RXTXBB1_CH1_PDOFFSETHIQ_MSB                                  3
#define RXTXBB1_CH1_PDOFFSETHIQ_LSB                                  3
#define RXTXBB1_CH1_PDOFFSETHIQ_MASK                                 0x00000008
#define RXTXBB1_CH1_PDOFFSETHIQ_GET(x)                               (((x) & RXTXBB1_CH1_PDOFFSETHIQ_MASK) >> RXTXBB1_CH1_PDOFFSETHIQ_LSB)
#define RXTXBB1_CH1_PDOFFSETHIQ_SET(x)                               (((0 | (x)) << RXTXBB1_CH1_PDOFFSETHIQ_LSB) & RXTXBB1_CH1_PDOFFSETHIQ_MASK)
#define RXTXBB1_CH1_PDOFFSETHIQ_RESET                                0
#define RXTXBB1_CH1_PDOFFSETI2V_MSB                                  2
#define RXTXBB1_CH1_PDOFFSETI2V_LSB                                  2
#define RXTXBB1_CH1_PDOFFSETI2V_MASK                                 0x00000004
#define RXTXBB1_CH1_PDOFFSETI2V_GET(x)                               (((x) & RXTXBB1_CH1_PDOFFSETI2V_MASK) >> RXTXBB1_CH1_PDOFFSETI2V_LSB)
#define RXTXBB1_CH1_PDOFFSETI2V_SET(x)                               (((0 | (x)) << RXTXBB1_CH1_PDOFFSETI2V_LSB) & RXTXBB1_CH1_PDOFFSETI2V_MASK)
#define RXTXBB1_CH1_PDOFFSETI2V_RESET                                0
#define RXTXBB1_CH1_PDLOQ_MSB                                        1
#define RXTXBB1_CH1_PDLOQ_LSB                                        1
#define RXTXBB1_CH1_PDLOQ_MASK                                       0x00000002
#define RXTXBB1_CH1_PDLOQ_GET(x)                                     (((x) & RXTXBB1_CH1_PDLOQ_MASK) >> RXTXBB1_CH1_PDLOQ_LSB)
#define RXTXBB1_CH1_PDLOQ_SET(x)                                     (((0 | (x)) << RXTXBB1_CH1_PDLOQ_LSB) & RXTXBB1_CH1_PDLOQ_MASK)
#define RXTXBB1_CH1_PDLOQ_RESET                                      0
#define RXTXBB1_CH1_PDHIQ_MSB                                        0
#define RXTXBB1_CH1_PDHIQ_LSB                                        0
#define RXTXBB1_CH1_PDHIQ_MASK                                       0x00000001
#define RXTXBB1_CH1_PDHIQ_GET(x)                                     (((x) & RXTXBB1_CH1_PDHIQ_MASK) >> RXTXBB1_CH1_PDHIQ_LSB)
#define RXTXBB1_CH1_PDHIQ_SET(x)                                     (((0 | (x)) << RXTXBB1_CH1_PDHIQ_LSB) & RXTXBB1_CH1_PDHIQ_MASK)
#define RXTXBB1_CH1_PDHIQ_RESET                                      0
#define RXTXBB1_CH1_ADDRESS                                          0x0000
#define RXTXBB1_CH1_HW_MASK                                          0xffffffff
#define RXTXBB1_CH1_SW_MASK                                          0xffffffff
#define RXTXBB1_CH1_HW_WRITE_MASK                                    0x00000000
#define RXTXBB1_CH1_SW_WRITE_MASK                                    0xffffffff
#define RXTXBB1_CH1_RSTMASK                                          0xffffffff
#define RXTXBB1_CH1_RESET                                            0x00000000

// 0x0004 (RXTXBB2_CH1)
#define RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_MSB                           31
#define RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_LSB                           29
#define RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_MASK                          0xe0000000
#define RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_GET(x)                        (((x) & RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_MASK) >> RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_LSB)
#define RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_SET(x)                        (((0 | (x)) << RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_LSB) & RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_MASK)
#define RXTXBB2_CH1_IBN_37P5_OSHI_CTRL_RESET                         6
#define RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_MSB                           28
#define RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_LSB                           26
#define RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_MASK                          0x1c000000
#define RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_GET(x)                        (((x) & RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_MASK) >> RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_LSB)
#define RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_SET(x)                        (((0 | (x)) << RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_LSB) & RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_MASK)
#define RXTXBB2_CH1_IBN_37P5_OSLO_CTRL_RESET                         6
#define RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_MSB                          25
#define RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_LSB                          23
#define RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_MASK                         0x03800000
#define RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_GET(x)                       (((x) & RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_MASK) >> RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_LSB)
#define RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_SET(x)                       (((0 | (x)) << RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_LSB) & RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_MASK)
#define RXTXBB2_CH1_IBN_37P5_OSI2V_CTRL_RESET                        6
#define RXTXBB2_CH1_SPARE_MSB                                        22
#define RXTXBB2_CH1_SPARE_LSB                                        21
#define RXTXBB2_CH1_SPARE_MASK                                       0x00600000
#define RXTXBB2_CH1_SPARE_GET(x)                                     (((x) & RXTXBB2_CH1_SPARE_MASK) >> RXTXBB2_CH1_SPARE_LSB)
#define RXTXBB2_CH1_SPARE_SET(x)                                     (((0 | (x)) << RXTXBB2_CH1_SPARE_LSB) & RXTXBB2_CH1_SPARE_MASK)
#define RXTXBB2_CH1_SPARE_RESET                                      0
#define RXTXBB2_CH1_SHORTBUFFER_MSB                                  20
#define RXTXBB2_CH1_SHORTBUFFER_LSB                                  20
#define RXTXBB2_CH1_SHORTBUFFER_MASK                                 0x00100000
#define RXTXBB2_CH1_SHORTBUFFER_GET(x)                               (((x) & RXTXBB2_CH1_SHORTBUFFER_MASK) >> RXTXBB2_CH1_SHORTBUFFER_LSB)
#define RXTXBB2_CH1_SHORTBUFFER_SET(x)                               (((0 | (x)) << RXTXBB2_CH1_SHORTBUFFER_LSB) & RXTXBB2_CH1_SHORTBUFFER_MASK)
#define RXTXBB2_CH1_SHORTBUFFER_RESET                                0
#define RXTXBB2_CH1_SELBUFFER_MSB                                    19
#define RXTXBB2_CH1_SELBUFFER_LSB                                    19
#define RXTXBB2_CH1_SELBUFFER_MASK                                   0x00080000
#define RXTXBB2_CH1_SELBUFFER_GET(x)                                 (((x) & RXTXBB2_CH1_SELBUFFER_MASK) >> RXTXBB2_CH1_SELBUFFER_LSB)
#define RXTXBB2_CH1_SELBUFFER_SET(x)                                 (((0 | (x)) << RXTXBB2_CH1_SELBUFFER_LSB) & RXTXBB2_CH1_SELBUFFER_MASK)
#define RXTXBB2_CH1_SELBUFFER_RESET                                  0
#define RXTXBB2_CH1_SEL_DAC_TEST_MSB                                 18
#define RXTXBB2_CH1_SEL_DAC_TEST_LSB                                 18
#define RXTXBB2_CH1_SEL_DAC_TEST_MASK                                0x00040000
#define RXTXBB2_CH1_SEL_DAC_TEST_GET(x)                              (((x) & RXTXBB2_CH1_SEL_DAC_TEST_MASK) >> RXTXBB2_CH1_SEL_DAC_TEST_LSB)
#define RXTXBB2_CH1_SEL_DAC_TEST_SET(x)                              (((0 | (x)) << RXTXBB2_CH1_SEL_DAC_TEST_LSB) & RXTXBB2_CH1_SEL_DAC_TEST_MASK)
#define RXTXBB2_CH1_SEL_DAC_TEST_RESET                               0
#define RXTXBB2_CH1_SEL_LOQ_TEST_MSB                                 17
#define RXTXBB2_CH1_SEL_LOQ_TEST_LSB                                 17
#define RXTXBB2_CH1_SEL_LOQ_TEST_MASK                                0x00020000
#define RXTXBB2_CH1_SEL_LOQ_TEST_GET(x)                              (((x) & RXTXBB2_CH1_SEL_LOQ_TEST_MASK) >> RXTXBB2_CH1_SEL_LOQ_TEST_LSB)
#define RXTXBB2_CH1_SEL_LOQ_TEST_SET(x)                              (((0 | (x)) << RXTXBB2_CH1_SEL_LOQ_TEST_LSB) & RXTXBB2_CH1_SEL_LOQ_TEST_MASK)
#define RXTXBB2_CH1_SEL_LOQ_TEST_RESET                               0
#define RXTXBB2_CH1_SEL_HIQ_TEST_MSB                                 16
#define RXTXBB2_CH1_SEL_HIQ_TEST_LSB                                 16
#define RXTXBB2_CH1_SEL_HIQ_TEST_MASK                                0x00010000
#define RXTXBB2_CH1_SEL_HIQ_TEST_GET(x)                              (((x) & RXTXBB2_CH1_SEL_HIQ_TEST_MASK) >> RXTXBB2_CH1_SEL_HIQ_TEST_LSB)
#define RXTXBB2_CH1_SEL_HIQ_TEST_SET(x)                              (((0 | (x)) << RXTXBB2_CH1_SEL_HIQ_TEST_LSB) & RXTXBB2_CH1_SEL_HIQ_TEST_MASK)
#define RXTXBB2_CH1_SEL_HIQ_TEST_RESET                               0
#define RXTXBB2_CH1_SEL_I2V_TEST_MSB                                 15
#define RXTXBB2_CH1_SEL_I2V_TEST_LSB                                 15
#define RXTXBB2_CH1_SEL_I2V_TEST_MASK                                0x00008000
#define RXTXBB2_CH1_SEL_I2V_TEST_GET(x)                              (((x) & RXTXBB2_CH1_SEL_I2V_TEST_MASK) >> RXTXBB2_CH1_SEL_I2V_TEST_LSB)
#define RXTXBB2_CH1_SEL_I2V_TEST_SET(x)                              (((0 | (x)) << RXTXBB2_CH1_SEL_I2V_TEST_LSB) & RXTXBB2_CH1_SEL_I2V_TEST_MASK)
#define RXTXBB2_CH1_SEL_I2V_TEST_RESET                               0
#define RXTXBB2_CH1_CMSEL_MSB                                        14
#define RXTXBB2_CH1_CMSEL_LSB                                        13
#define RXTXBB2_CH1_CMSEL_MASK                                       0x00006000
#define RXTXBB2_CH1_CMSEL_GET(x)                                     (((x) & RXTXBB2_CH1_CMSEL_MASK) >> RXTXBB2_CH1_CMSEL_LSB)
#define RXTXBB2_CH1_CMSEL_SET(x)                                     (((0 | (x)) << RXTXBB2_CH1_CMSEL_LSB) & RXTXBB2_CH1_CMSEL_MASK)
#define RXTXBB2_CH1_CMSEL_RESET                                      1
#define RXTXBB2_CH1_FILTERFC_MSB                                     12
#define RXTXBB2_CH1_FILTERFC_LSB                                     8
#define RXTXBB2_CH1_FILTERFC_MASK                                    0x00001f00
#define RXTXBB2_CH1_FILTERFC_GET(x)                                  (((x) & RXTXBB2_CH1_FILTERFC_MASK) >> RXTXBB2_CH1_FILTERFC_LSB)
#define RXTXBB2_CH1_FILTERFC_SET(x)                                  (((0 | (x)) << RXTXBB2_CH1_FILTERFC_LSB) & RXTXBB2_CH1_FILTERFC_MASK)
#define RXTXBB2_CH1_FILTERFC_RESET                                   16
#define RXTXBB2_CH1_LOCALFILTERTUNING_MSB                            7
#define RXTXBB2_CH1_LOCALFILTERTUNING_LSB                            7
#define RXTXBB2_CH1_LOCALFILTERTUNING_MASK                           0x00000080
#define RXTXBB2_CH1_LOCALFILTERTUNING_GET(x)                         (((x) & RXTXBB2_CH1_LOCALFILTERTUNING_MASK) >> RXTXBB2_CH1_LOCALFILTERTUNING_LSB)
#define RXTXBB2_CH1_LOCALFILTERTUNING_SET(x)                         (((0 | (x)) << RXTXBB2_CH1_LOCALFILTERTUNING_LSB) & RXTXBB2_CH1_LOCALFILTERTUNING_MASK)
#define RXTXBB2_CH1_LOCALFILTERTUNING_RESET                          0
#define RXTXBB2_CH1_FILTERDOUBLEBW_MSB                               6
#define RXTXBB2_CH1_FILTERDOUBLEBW_LSB                               6
#define RXTXBB2_CH1_FILTERDOUBLEBW_MASK                              0x00000040
#define RXTXBB2_CH1_FILTERDOUBLEBW_GET(x)                            (((x) & RXTXBB2_CH1_FILTERDOUBLEBW_MASK) >> RXTXBB2_CH1_FILTERDOUBLEBW_LSB)
#define RXTXBB2_CH1_FILTERDOUBLEBW_SET(x)                            (((0 | (x)) << RXTXBB2_CH1_FILTERDOUBLEBW_LSB) & RXTXBB2_CH1_FILTERDOUBLEBW_MASK)
#define RXTXBB2_CH1_FILTERDOUBLEBW_RESET                             0
#define RXTXBB2_CH1_PATH2HIQ_EN_MSB                                  5
#define RXTXBB2_CH1_PATH2HIQ_EN_LSB                                  5
#define RXTXBB2_CH1_PATH2HIQ_EN_MASK                                 0x00000020
#define RXTXBB2_CH1_PATH2HIQ_EN_GET(x)                               (((x) & RXTXBB2_CH1_PATH2HIQ_EN_MASK) >> RXTXBB2_CH1_PATH2HIQ_EN_LSB)
#define RXTXBB2_CH1_PATH2HIQ_EN_SET(x)                               (((0 | (x)) << RXTXBB2_CH1_PATH2HIQ_EN_LSB) & RXTXBB2_CH1_PATH2HIQ_EN_MASK)
#define RXTXBB2_CH1_PATH2HIQ_EN_RESET                                0
#define RXTXBB2_CH1_PATH1HIQ_EN_MSB                                  4
#define RXTXBB2_CH1_PATH1HIQ_EN_LSB                                  4
#define RXTXBB2_CH1_PATH1HIQ_EN_MASK                                 0x00000010
#define RXTXBB2_CH1_PATH1HIQ_EN_GET(x)                               (((x) & RXTXBB2_CH1_PATH1HIQ_EN_MASK) >> RXTXBB2_CH1_PATH1HIQ_EN_LSB)
#define RXTXBB2_CH1_PATH1HIQ_EN_SET(x)                               (((0 | (x)) << RXTXBB2_CH1_PATH1HIQ_EN_LSB) & RXTXBB2_CH1_PATH1HIQ_EN_MASK)
#define RXTXBB2_CH1_PATH1HIQ_EN_RESET                                1
#define RXTXBB2_CH1_PATH3LOQ_EN_MSB                                  3
#define RXTXBB2_CH1_PATH3LOQ_EN_LSB                                  3
#define RXTXBB2_CH1_PATH3LOQ_EN_MASK                                 0x00000008
#define RXTXBB2_CH1_PATH3LOQ_EN_GET(x)                               (((x) & RXTXBB2_CH1_PATH3LOQ_EN_MASK) >> RXTXBB2_CH1_PATH3LOQ_EN_LSB)
#define RXTXBB2_CH1_PATH3LOQ_EN_SET(x)                               (((0 | (x)) << RXTXBB2_CH1_PATH3LOQ_EN_LSB) & RXTXBB2_CH1_PATH3LOQ_EN_MASK)
#define RXTXBB2_CH1_PATH3LOQ_EN_RESET                                0
#define RXTXBB2_CH1_PATH2LOQ_EN_MSB                                  2
#define RXTXBB2_CH1_PATH2LOQ_EN_LSB                                  2
#define RXTXBB2_CH1_PATH2LOQ_EN_MASK                                 0x00000004
#define RXTXBB2_CH1_PATH2LOQ_EN_GET(x)                               (((x) & RXTXBB2_CH1_PATH2LOQ_EN_MASK) >> RXTXBB2_CH1_PATH2LOQ_EN_LSB)
#define RXTXBB2_CH1_PATH2LOQ_EN_SET(x)                               (((0 | (x)) << RXTXBB2_CH1_PATH2LOQ_EN_LSB) & RXTXBB2_CH1_PATH2LOQ_EN_MASK)
#define RXTXBB2_CH1_PATH2LOQ_EN_RESET                                0
#define RXTXBB2_CH1_PATH1LOQ_EN_MSB                                  1
#define RXTXBB2_CH1_PATH1LOQ_EN_LSB                                  1
#define RXTXBB2_CH1_PATH1LOQ_EN_MASK                                 0x00000002
#define RXTXBB2_CH1_PATH1LOQ_EN_GET(x)                               (((x) & RXTXBB2_CH1_PATH1LOQ_EN_MASK) >> RXTXBB2_CH1_PATH1LOQ_EN_LSB)
#define RXTXBB2_CH1_PATH1LOQ_EN_SET(x)                               (((0 | (x)) << RXTXBB2_CH1_PATH1LOQ_EN_LSB) & RXTXBB2_CH1_PATH1LOQ_EN_MASK)
#define RXTXBB2_CH1_PATH1LOQ_EN_RESET                                1
#define RXTXBB2_CH1_PATH_OVERRIDE_MSB                                0
#define RXTXBB2_CH1_PATH_OVERRIDE_LSB                                0
#define RXTXBB2_CH1_PATH_OVERRIDE_MASK                               0x00000001
#define RXTXBB2_CH1_PATH_OVERRIDE_GET(x)                             (((x) & RXTXBB2_CH1_PATH_OVERRIDE_MASK) >> RXTXBB2_CH1_PATH_OVERRIDE_LSB)
#define RXTXBB2_CH1_PATH_OVERRIDE_SET(x)                             (((0 | (x)) << RXTXBB2_CH1_PATH_OVERRIDE_LSB) & RXTXBB2_CH1_PATH_OVERRIDE_MASK)
#define RXTXBB2_CH1_PATH_OVERRIDE_RESET                              0
#define RXTXBB2_CH1_ADDRESS                                          0x0004
#define RXTXBB2_CH1_HW_MASK                                          0xffffffff
#define RXTXBB2_CH1_SW_MASK                                          0xffffffff
#define RXTXBB2_CH1_HW_WRITE_MASK                                    0x00001f00
#define RXTXBB2_CH1_SW_WRITE_MASK                                    0xffffffff
#define RXTXBB2_CH1_RSTMASK                                          0xffffffff
#define RXTXBB2_CH1_RESET                                            0xdb003012

// 0x0008 (RXTXBB3_CH1)
#define RXTXBB3_CH1_SPARE_MSB                                        31
#define RXTXBB3_CH1_SPARE_LSB                                        27
#define RXTXBB3_CH1_SPARE_MASK                                       0xf8000000
#define RXTXBB3_CH1_SPARE_GET(x)                                     (((x) & RXTXBB3_CH1_SPARE_MASK) >> RXTXBB3_CH1_SPARE_LSB)
#define RXTXBB3_CH1_SPARE_SET(x)                                     (((0 | (x)) << RXTXBB3_CH1_SPARE_LSB) & RXTXBB3_CH1_SPARE_MASK)
#define RXTXBB3_CH1_SPARE_RESET                                      0
#define RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_MSB                       26
#define RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_LSB                       24
#define RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_MASK                      0x07000000
#define RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_GET(x)                    (((x) & RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_MASK) >> RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_LSB)
#define RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_SET(x)                    (((0 | (x)) << RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_LSB) & RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_MASK)
#define RXTXBB3_CH1_IBN_25U_CM_BUFAMP_CTRL_RESET                     4
#define RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_MSB                           23
#define RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_LSB                           21
#define RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_MASK                          0x00e00000
#define RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_GET(x)                        (((x) & RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_MASK) >> RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_LSB)
#define RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_SET(x)                        (((0 | (x)) << RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_LSB) & RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_MASK)
#define RXTXBB3_CH1_IBN_25U_BKV2I_CTRL_RESET                         4
#define RXTXBB3_CH1_IBN_25U_I2V_CTRL_MSB                             20
#define RXTXBB3_CH1_IBN_25U_I2V_CTRL_LSB                             18
#define RXTXBB3_CH1_IBN_25U_I2V_CTRL_MASK                            0x001c0000
#define RXTXBB3_CH1_IBN_25U_I2V_CTRL_GET(x)                          (((x) & RXTXBB3_CH1_IBN_25U_I2V_CTRL_MASK) >> RXTXBB3_CH1_IBN_25U_I2V_CTRL_LSB)
#define RXTXBB3_CH1_IBN_25U_I2V_CTRL_SET(x)                          (((0 | (x)) << RXTXBB3_CH1_IBN_25U_I2V_CTRL_LSB) & RXTXBB3_CH1_IBN_25U_I2V_CTRL_MASK)
#define RXTXBB3_CH1_IBN_25U_I2V_CTRL_RESET                           4
#define RXTXBB3_CH1_IBN_25U_HI1_CTRL_MSB                             17
#define RXTXBB3_CH1_IBN_25U_HI1_CTRL_LSB                             15
#define RXTXBB3_CH1_IBN_25U_HI1_CTRL_MASK                            0x00038000
#define RXTXBB3_CH1_IBN_25U_HI1_CTRL_GET(x)                          (((x) & RXTXBB3_CH1_IBN_25U_HI1_CTRL_MASK) >> RXTXBB3_CH1_IBN_25U_HI1_CTRL_LSB)
#define RXTXBB3_CH1_IBN_25U_HI1_CTRL_SET(x)                          (((0 | (x)) << RXTXBB3_CH1_IBN_25U_HI1_CTRL_LSB) & RXTXBB3_CH1_IBN_25U_HI1_CTRL_MASK)
#define RXTXBB3_CH1_IBN_25U_HI1_CTRL_RESET                           4
#define RXTXBB3_CH1_IBN_25U_HI2_CTRL_MSB                             14
#define RXTXBB3_CH1_IBN_25U_HI2_CTRL_LSB                             12
#define RXTXBB3_CH1_IBN_25U_HI2_CTRL_MASK                            0x00007000
#define RXTXBB3_CH1_IBN_25U_HI2_CTRL_GET(x)                          (((x) & RXTXBB3_CH1_IBN_25U_HI2_CTRL_MASK) >> RXTXBB3_CH1_IBN_25U_HI2_CTRL_LSB)
#define RXTXBB3_CH1_IBN_25U_HI2_CTRL_SET(x)                          (((0 | (x)) << RXTXBB3_CH1_IBN_25U_HI2_CTRL_LSB) & RXTXBB3_CH1_IBN_25U_HI2_CTRL_MASK)
#define RXTXBB3_CH1_IBN_25U_HI2_CTRL_RESET                           4
#define RXTXBB3_CH1_IBN_25U_LO1_CTRL_MSB                             11
#define RXTXBB3_CH1_IBN_25U_LO1_CTRL_LSB                             9
#define RXTXBB3_CH1_IBN_25U_LO1_CTRL_MASK                            0x00000e00
#define RXTXBB3_CH1_IBN_25U_LO1_CTRL_GET(x)                          (((x) & RXTXBB3_CH1_IBN_25U_LO1_CTRL_MASK) >> RXTXBB3_CH1_IBN_25U_LO1_CTRL_LSB)
#define RXTXBB3_CH1_IBN_25U_LO1_CTRL_SET(x)                          (((0 | (x)) << RXTXBB3_CH1_IBN_25U_LO1_CTRL_LSB) & RXTXBB3_CH1_IBN_25U_LO1_CTRL_MASK)
#define RXTXBB3_CH1_IBN_25U_LO1_CTRL_RESET                           4
#define RXTXBB3_CH1_IBN_25U_LO2_CTRL_MSB                             8
#define RXTXBB3_CH1_IBN_25U_LO2_CTRL_LSB                             6
#define RXTXBB3_CH1_IBN_25U_LO2_CTRL_MASK                            0x000001c0
#define RXTXBB3_CH1_IBN_25U_LO2_CTRL_GET(x)                          (((x) & RXTXBB3_CH1_IBN_25U_LO2_CTRL_MASK) >> RXTXBB3_CH1_IBN_25U_LO2_CTRL_LSB)
#define RXTXBB3_CH1_IBN_25U_LO2_CTRL_SET(x)                          (((0 | (x)) << RXTXBB3_CH1_IBN_25U_LO2_CTRL_LSB) & RXTXBB3_CH1_IBN_25U_LO2_CTRL_MASK)
#define RXTXBB3_CH1_IBN_25U_LO2_CTRL_RESET                           4
#define RXTXBB3_CH1_IBRN_12P5_CM_CTRL_MSB                            5
#define RXTXBB3_CH1_IBRN_12P5_CM_CTRL_LSB                            3
#define RXTXBB3_CH1_IBRN_12P5_CM_CTRL_MASK                           0x00000038
#define RXTXBB3_CH1_IBRN_12P5_CM_CTRL_GET(x)                         (((x) & RXTXBB3_CH1_IBRN_12P5_CM_CTRL_MASK) >> RXTXBB3_CH1_IBRN_12P5_CM_CTRL_LSB)
#define RXTXBB3_CH1_IBRN_12P5_CM_CTRL_SET(x)                         (((0 | (x)) << RXTXBB3_CH1_IBRN_12P5_CM_CTRL_LSB) & RXTXBB3_CH1_IBRN_12P5_CM_CTRL_MASK)
#define RXTXBB3_CH1_IBRN_12P5_CM_CTRL_RESET                          2
#define RXTXBB3_CH1_IBN_100U_TEST_CTRL_MSB                           2
#define RXTXBB3_CH1_IBN_100U_TEST_CTRL_LSB                           0
#define RXTXBB3_CH1_IBN_100U_TEST_CTRL_MASK                          0x00000007
#define RXTXBB3_CH1_IBN_100U_TEST_CTRL_GET(x)                        (((x) & RXTXBB3_CH1_IBN_100U_TEST_CTRL_MASK) >> RXTXBB3_CH1_IBN_100U_TEST_CTRL_LSB)
#define RXTXBB3_CH1_IBN_100U_TEST_CTRL_SET(x)                        (((0 | (x)) << RXTXBB3_CH1_IBN_100U_TEST_CTRL_LSB) & RXTXBB3_CH1_IBN_100U_TEST_CTRL_MASK)
#define RXTXBB3_CH1_IBN_100U_TEST_CTRL_RESET                         4
#define RXTXBB3_CH1_ADDRESS                                          0x0008
#define RXTXBB3_CH1_HW_MASK                                          0xffffffff
#define RXTXBB3_CH1_SW_MASK                                          0xffffffff
#define RXTXBB3_CH1_HW_WRITE_MASK                                    0x00000000
#define RXTXBB3_CH1_SW_WRITE_MASK                                    0xffffffff
#define RXTXBB3_CH1_RSTMASK                                          0xffffffff
#define RXTXBB3_CH1_RESET                                            0x04924914

// 0x000c (RXTXBB4_CH1)
#define RXTXBB4_CH1_SPARE_MSB                                        31
#define RXTXBB4_CH1_SPARE_LSB                                        31
#define RXTXBB4_CH1_SPARE_MASK                                       0x80000000
#define RXTXBB4_CH1_SPARE_GET(x)                                     (((x) & RXTXBB4_CH1_SPARE_MASK) >> RXTXBB4_CH1_SPARE_LSB)
#define RXTXBB4_CH1_SPARE_SET(x)                                     (((0 | (x)) << RXTXBB4_CH1_SPARE_LSB) & RXTXBB4_CH1_SPARE_MASK)
#define RXTXBB4_CH1_SPARE_RESET                                      0
#define RXTXBB4_CH1_LOCALOFFSET_MSB                                  30
#define RXTXBB4_CH1_LOCALOFFSET_LSB                                  30
#define RXTXBB4_CH1_LOCALOFFSET_MASK                                 0x40000000
#define RXTXBB4_CH1_LOCALOFFSET_GET(x)                               (((x) & RXTXBB4_CH1_LOCALOFFSET_MASK) >> RXTXBB4_CH1_LOCALOFFSET_LSB)
#define RXTXBB4_CH1_LOCALOFFSET_SET(x)                               (((0 | (x)) << RXTXBB4_CH1_LOCALOFFSET_LSB) & RXTXBB4_CH1_LOCALOFFSET_MASK)
#define RXTXBB4_CH1_LOCALOFFSET_RESET                                0
#define RXTXBB4_CH1_OFSTCORRHII_MSB                                  29
#define RXTXBB4_CH1_OFSTCORRHII_LSB                                  25
#define RXTXBB4_CH1_OFSTCORRHII_MASK                                 0x3e000000
#define RXTXBB4_CH1_OFSTCORRHII_GET(x)                               (((x) & RXTXBB4_CH1_OFSTCORRHII_MASK) >> RXTXBB4_CH1_OFSTCORRHII_LSB)
#define RXTXBB4_CH1_OFSTCORRHII_SET(x)                               (((0 | (x)) << RXTXBB4_CH1_OFSTCORRHII_LSB) & RXTXBB4_CH1_OFSTCORRHII_MASK)
#define RXTXBB4_CH1_OFSTCORRHII_RESET                                16
#define RXTXBB4_CH1_OFSTCORRHIQ_MSB                                  24
#define RXTXBB4_CH1_OFSTCORRHIQ_LSB                                  20
#define RXTXBB4_CH1_OFSTCORRHIQ_MASK                                 0x01f00000
#define RXTXBB4_CH1_OFSTCORRHIQ_GET(x)                               (((x) & RXTXBB4_CH1_OFSTCORRHIQ_MASK) >> RXTXBB4_CH1_OFSTCORRHIQ_LSB)
#define RXTXBB4_CH1_OFSTCORRHIQ_SET(x)                               (((0 | (x)) << RXTXBB4_CH1_OFSTCORRHIQ_LSB) & RXTXBB4_CH1_OFSTCORRHIQ_MASK)
#define RXTXBB4_CH1_OFSTCORRHIQ_RESET                                16
#define RXTXBB4_CH1_OFSTCORRLOI_MSB                                  19
#define RXTXBB4_CH1_OFSTCORRLOI_LSB                                  15
#define RXTXBB4_CH1_OFSTCORRLOI_MASK                                 0x000f8000
#define RXTXBB4_CH1_OFSTCORRLOI_GET(x)                               (((x) & RXTXBB4_CH1_OFSTCORRLOI_MASK) >> RXTXBB4_CH1_OFSTCORRLOI_LSB)
#define RXTXBB4_CH1_OFSTCORRLOI_SET(x)                               (((0 | (x)) << RXTXBB4_CH1_OFSTCORRLOI_LSB) & RXTXBB4_CH1_OFSTCORRLOI_MASK)
#define RXTXBB4_CH1_OFSTCORRLOI_RESET                                16
#define RXTXBB4_CH1_OFSTCORRLOQ_MSB                                  14
#define RXTXBB4_CH1_OFSTCORRLOQ_LSB                                  10
#define RXTXBB4_CH1_OFSTCORRLOQ_MASK                                 0x00007c00
#define RXTXBB4_CH1_OFSTCORRLOQ_GET(x)                               (((x) & RXTXBB4_CH1_OFSTCORRLOQ_MASK) >> RXTXBB4_CH1_OFSTCORRLOQ_LSB)
#define RXTXBB4_CH1_OFSTCORRLOQ_SET(x)                               (((0 | (x)) << RXTXBB4_CH1_OFSTCORRLOQ_LSB) & RXTXBB4_CH1_OFSTCORRLOQ_MASK)
#define RXTXBB4_CH1_OFSTCORRLOQ_RESET                                16
#define RXTXBB4_CH1_OFSTCORRI2VI_MSB                                 9
#define RXTXBB4_CH1_OFSTCORRI2VI_LSB                                 5
#define RXTXBB4_CH1_OFSTCORRI2VI_MASK                                0x000003e0
#define RXTXBB4_CH1_OFSTCORRI2VI_GET(x)                              (((x) & RXTXBB4_CH1_OFSTCORRI2VI_MASK) >> RXTXBB4_CH1_OFSTCORRI2VI_LSB)
#define RXTXBB4_CH1_OFSTCORRI2VI_SET(x)                              (((0 | (x)) << RXTXBB4_CH1_OFSTCORRI2VI_LSB) & RXTXBB4_CH1_OFSTCORRI2VI_MASK)
#define RXTXBB4_CH1_OFSTCORRI2VI_RESET                               16
#define RXTXBB4_CH1_OFSTCORRI2VQ_MSB                                 4
#define RXTXBB4_CH1_OFSTCORRI2VQ_LSB                                 0
#define RXTXBB4_CH1_OFSTCORRI2VQ_MASK                                0x0000001f
#define RXTXBB4_CH1_OFSTCORRI2VQ_GET(x)                              (((x) & RXTXBB4_CH1_OFSTCORRI2VQ_MASK) >> RXTXBB4_CH1_OFSTCORRI2VQ_LSB)
#define RXTXBB4_CH1_OFSTCORRI2VQ_SET(x)                              (((0 | (x)) << RXTXBB4_CH1_OFSTCORRI2VQ_LSB) & RXTXBB4_CH1_OFSTCORRI2VQ_MASK)
#define RXTXBB4_CH1_OFSTCORRI2VQ_RESET                               16
#define RXTXBB4_CH1_ADDRESS                                          0x000c
#define RXTXBB4_CH1_HW_MASK                                          0xffffffff
#define RXTXBB4_CH1_SW_MASK                                          0xffffffff
#define RXTXBB4_CH1_HW_WRITE_MASK                                    0x3fffffff
#define RXTXBB4_CH1_SW_WRITE_MASK                                    0xffffffff
#define RXTXBB4_CH1_RSTMASK                                          0xffffffff
#define RXTXBB4_CH1_RESET                                            0x21084210

// 0x0010 (RF2G1_CH1)
#define RF2G1_CH1_PDIC25U_LNA_MSB                                    31
#define RF2G1_CH1_PDIC25U_LNA_LSB                                    29
#define RF2G1_CH1_PDIC25U_LNA_MASK                                   0xe0000000
#define RF2G1_CH1_PDIC25U_LNA_GET(x)                                 (((x) & RF2G1_CH1_PDIC25U_LNA_MASK) >> RF2G1_CH1_PDIC25U_LNA_LSB)
#define RF2G1_CH1_PDIC25U_LNA_SET(x)                                 (((0 | (x)) << RF2G1_CH1_PDIC25U_LNA_LSB) & RF2G1_CH1_PDIC25U_LNA_MASK)
#define RF2G1_CH1_PDIC25U_LNA_RESET                                  3
#define RF2G1_CH1_DB_MSB                                             28
#define RF2G1_CH1_DB_LSB                                             26
#define RF2G1_CH1_DB_MASK                                            0x1c000000
#define RF2G1_CH1_DB_GET(x)                                          (((x) & RF2G1_CH1_DB_MASK) >> RF2G1_CH1_DB_LSB)
#define RF2G1_CH1_DB_SET(x)                                          (((0 | (x)) << RF2G1_CH1_DB_LSB) & RF2G1_CH1_DB_MASK)
#define RF2G1_CH1_DB_RESET                                           3
#define RF2G1_CH1_OB_MSB                                             25
#define RF2G1_CH1_OB_LSB                                             23
#define RF2G1_CH1_OB_MASK                                            0x03800000
#define RF2G1_CH1_OB_GET(x)                                          (((x) & RF2G1_CH1_OB_MASK) >> RF2G1_CH1_OB_LSB)
#define RF2G1_CH1_OB_SET(x)                                          (((0 | (x)) << RF2G1_CH1_OB_LSB) & RF2G1_CH1_OB_MASK)
#define RF2G1_CH1_OB_RESET                                           3
#define RF2G1_CH1_LOATB_SEL_MSB                                      22
#define RF2G1_CH1_LOATB_SEL_LSB                                      20
#define RF2G1_CH1_LOATB_SEL_MASK                                     0x00700000
#define RF2G1_CH1_LOATB_SEL_GET(x)                                   (((x) & RF2G1_CH1_LOATB_SEL_MASK) >> RF2G1_CH1_LOATB_SEL_LSB)
#define RF2G1_CH1_LOATB_SEL_SET(x)                                   (((0 | (x)) << RF2G1_CH1_LOATB_SEL_LSB) & RF2G1_CH1_LOATB_SEL_MASK)
#define RF2G1_CH1_LOATB_SEL_RESET                                    0
#define RF2G1_CH1_RXATB_SEL_MSB                                      19
#define RF2G1_CH1_RXATB_SEL_LSB                                      17
#define RF2G1_CH1_RXATB_SEL_MASK                                     0x000e0000
#define RF2G1_CH1_RXATB_SEL_GET(x)                                   (((x) & RF2G1_CH1_RXATB_SEL_MASK) >> RF2G1_CH1_RXATB_SEL_LSB)
#define RF2G1_CH1_RXATB_SEL_SET(x)                                   (((0 | (x)) << RF2G1_CH1_RXATB_SEL_LSB) & RF2G1_CH1_RXATB_SEL_MASK)
#define RF2G1_CH1_RXATB_SEL_RESET                                    0
#define RF2G1_CH1_TXATB_SEL_MSB                                      16
#define RF2G1_CH1_TXATB_SEL_LSB                                      14
#define RF2G1_CH1_TXATB_SEL_MASK                                     0x0001c000
#define RF2G1_CH1_TXATB_SEL_GET(x)                                   (((x) & RF2G1_CH1_TXATB_SEL_MASK) >> RF2G1_CH1_TXATB_SEL_LSB)
#define RF2G1_CH1_TXATB_SEL_SET(x)                                   (((0 | (x)) << RF2G1_CH1_TXATB_SEL_LSB) & RF2G1_CH1_TXATB_SEL_MASK)
#define RF2G1_CH1_TXATB_SEL_RESET                                    0
#define RF2G1_CH1_LOCONTROL_MSB                                      13
#define RF2G1_CH1_LOCONTROL_LSB                                      13
#define RF2G1_CH1_LOCONTROL_MASK                                     0x00002000
#define RF2G1_CH1_LOCONTROL_GET(x)                                   (((x) & RF2G1_CH1_LOCONTROL_MASK) >> RF2G1_CH1_LOCONTROL_LSB)
#define RF2G1_CH1_LOCONTROL_SET(x)                                   (((0 | (x)) << RF2G1_CH1_LOCONTROL_LSB) & RF2G1_CH1_LOCONTROL_MASK)
#define RF2G1_CH1_LOCONTROL_RESET                                    0
#define RF2G1_CH1_PACA_SEL_MSB                                       12
#define RF2G1_CH1_PACA_SEL_LSB                                       11
#define RF2G1_CH1_PACA_SEL_MASK                                      0x00001800
#define RF2G1_CH1_PACA_SEL_GET(x)                                    (((x) & RF2G1_CH1_PACA_SEL_MASK) >> RF2G1_CH1_PACA_SEL_LSB)
#define RF2G1_CH1_PACA_SEL_SET(x)                                    (((0 | (x)) << RF2G1_CH1_PACA_SEL_LSB) & RF2G1_CH1_PACA_SEL_MASK)
#define RF2G1_CH1_PACA_SEL_RESET                                     2
#define RF2G1_CH1_PDIC25U_VGM_MSB                                    10
#define RF2G1_CH1_PDIC25U_VGM_LSB                                    8
#define RF2G1_CH1_PDIC25U_VGM_MASK                                   0x00000700
#define RF2G1_CH1_PDIC25U_VGM_GET(x)                                 (((x) & RF2G1_CH1_PDIC25U_VGM_MASK) >> RF2G1_CH1_PDIC25U_VGM_LSB)
#define RF2G1_CH1_PDIC25U_VGM_SET(x)                                 (((0 | (x)) << RF2G1_CH1_PDIC25U_VGM_LSB) & RF2G1_CH1_PDIC25U_VGM_MASK)
#define RF2G1_CH1_PDIC25U_VGM_RESET                                  3
#define RF2G1_CH1_REGLNA_BYPASS_MSB                                  7
#define RF2G1_CH1_REGLNA_BYPASS_LSB                                  7
#define RF2G1_CH1_REGLNA_BYPASS_MASK                                 0x00000080
#define RF2G1_CH1_REGLNA_BYPASS_GET(x)                               (((x) & RF2G1_CH1_REGLNA_BYPASS_MASK) >> RF2G1_CH1_REGLNA_BYPASS_LSB)
#define RF2G1_CH1_REGLNA_BYPASS_SET(x)                               (((0 | (x)) << RF2G1_CH1_REGLNA_BYPASS_LSB) & RF2G1_CH1_REGLNA_BYPASS_MASK)
#define RF2G1_CH1_REGLNA_BYPASS_RESET                                0
#define RF2G1_CH1_REGLO_BYPASS_MSB                                   6
#define RF2G1_CH1_REGLO_BYPASS_LSB                                   6
#define RF2G1_CH1_REGLO_BYPASS_MASK                                  0x00000040
#define RF2G1_CH1_REGLO_BYPASS_GET(x)                                (((x) & RF2G1_CH1_REGLO_BYPASS_MASK) >> RF2G1_CH1_REGLO_BYPASS_LSB)
#define RF2G1_CH1_REGLO_BYPASS_SET(x)                                (((0 | (x)) << RF2G1_CH1_REGLO_BYPASS_LSB) & RF2G1_CH1_REGLO_BYPASS_MASK)
#define RF2G1_CH1_REGLO_BYPASS_RESET                                 0
#define RF2G1_CH1_SPARES_MSB                                         5
#define RF2G1_CH1_SPARES_LSB                                         0
#define RF2G1_CH1_SPARES_MASK                                        0x0000003f
#define RF2G1_CH1_SPARES_GET(x)                                      (((x) & RF2G1_CH1_SPARES_MASK) >> RF2G1_CH1_SPARES_LSB)
#define RF2G1_CH1_SPARES_SET(x)                                      (((0 | (x)) << RF2G1_CH1_SPARES_LSB) & RF2G1_CH1_SPARES_MASK)
#define RF2G1_CH1_SPARES_RESET                                       0
#define RF2G1_CH1_ADDRESS                                            0x0010
#define RF2G1_CH1_HW_MASK                                            0xffffffff
#define RF2G1_CH1_SW_MASK                                            0xffffffff
#define RF2G1_CH1_HW_WRITE_MASK                                      0x00000000
#define RF2G1_CH1_SW_WRITE_MASK                                      0xffffffff
#define RF2G1_CH1_RSTMASK                                            0xffffffff
#define RF2G1_CH1_RESET                                              0x6d801300

// 0x0014 (RF2G2_CH1)
#define RF2G2_CH1_PDLNA_MSB                                          31
#define RF2G2_CH1_PDLNA_LSB                                          31
#define RF2G2_CH1_PDLNA_MASK                                         0x80000000
#define RF2G2_CH1_PDLNA_GET(x)                                       (((x) & RF2G2_CH1_PDLNA_MASK) >> RF2G2_CH1_PDLNA_LSB)
#define RF2G2_CH1_PDLNA_SET(x)                                       (((0 | (x)) << RF2G2_CH1_PDLNA_LSB) & RF2G2_CH1_PDLNA_MASK)
#define RF2G2_CH1_PDLNA_RESET                                        0
#define RF2G2_CH1_PDDIV_MSB                                          30
#define RF2G2_CH1_PDDIV_LSB                                          30
#define RF2G2_CH1_PDDIV_MASK                                         0x40000000
#define RF2G2_CH1_PDDIV_GET(x)                                       (((x) & RF2G2_CH1_PDDIV_MASK) >> RF2G2_CH1_PDDIV_LSB)
#define RF2G2_CH1_PDDIV_SET(x)                                       (((0 | (x)) << RF2G2_CH1_PDDIV_LSB) & RF2G2_CH1_PDDIV_MASK)
#define RF2G2_CH1_PDDIV_RESET                                        0
#define RF2G2_CH1_PDPADRV_MSB                                        29
#define RF2G2_CH1_PDPADRV_LSB                                        29
#define RF2G2_CH1_PDPADRV_MASK                                       0x20000000
#define RF2G2_CH1_PDPADRV_GET(x)                                     (((x) & RF2G2_CH1_PDPADRV_MASK) >> RF2G2_CH1_PDPADRV_LSB)
#define RF2G2_CH1_PDPADRV_SET(x)                                     (((0 | (x)) << RF2G2_CH1_PDPADRV_LSB) & RF2G2_CH1_PDPADRV_MASK)
#define RF2G2_CH1_PDPADRV_RESET                                      0
#define RF2G2_CH1_PDPAOUT_MSB                                        28
#define RF2G2_CH1_PDPAOUT_LSB                                        28
#define RF2G2_CH1_PDPAOUT_MASK                                       0x10000000
#define RF2G2_CH1_PDPAOUT_GET(x)                                     (((x) & RF2G2_CH1_PDPAOUT_MASK) >> RF2G2_CH1_PDPAOUT_LSB)
#define RF2G2_CH1_PDPAOUT_SET(x)                                     (((0 | (x)) << RF2G2_CH1_PDPAOUT_LSB) & RF2G2_CH1_PDPAOUT_MASK)
#define RF2G2_CH1_PDPAOUT_RESET                                      0
#define RF2G2_CH1_PDREGLNA_MSB                                       27
#define RF2G2_CH1_PDREGLNA_LSB                                       27
#define RF2G2_CH1_PDREGLNA_MASK                                      0x08000000
#define RF2G2_CH1_PDREGLNA_GET(x)                                    (((x) & RF2G2_CH1_PDREGLNA_MASK) >> RF2G2_CH1_PDREGLNA_LSB)
#define RF2G2_CH1_PDREGLNA_SET(x)                                    (((0 | (x)) << RF2G2_CH1_PDREGLNA_LSB) & RF2G2_CH1_PDREGLNA_MASK)
#define RF2G2_CH1_PDREGLNA_RESET                                     0
#define RF2G2_CH1_PDREGLO_MSB                                        26
#define RF2G2_CH1_PDREGLO_LSB                                        26
#define RF2G2_CH1_PDREGLO_MASK                                       0x04000000
#define RF2G2_CH1_PDREGLO_GET(x)                                     (((x) & RF2G2_CH1_PDREGLO_MASK) >> RF2G2_CH1_PDREGLO_LSB)
#define RF2G2_CH1_PDREGLO_SET(x)                                     (((0 | (x)) << RF2G2_CH1_PDREGLO_LSB) & RF2G2_CH1_PDREGLO_MASK)
#define RF2G2_CH1_PDREGLO_RESET                                      0
#define RF2G2_CH1_PDVGM_MSB                                          25
#define RF2G2_CH1_PDVGM_LSB                                          25
#define RF2G2_CH1_PDVGM_MASK                                         0x02000000
#define RF2G2_CH1_PDVGM_GET(x)                                       (((x) & RF2G2_CH1_PDVGM_MASK) >> RF2G2_CH1_PDVGM_LSB)
#define RF2G2_CH1_PDVGM_SET(x)                                       (((0 | (x)) << RF2G2_CH1_PDVGM_LSB) & RF2G2_CH1_PDVGM_MASK)
#define RF2G2_CH1_PDVGM_RESET                                        0
#define RF2G2_CH1_PDRXLO_MSB                                         24
#define RF2G2_CH1_PDRXLO_LSB                                         24
#define RF2G2_CH1_PDRXLO_MASK                                        0x01000000
#define RF2G2_CH1_PDRXLO_GET(x)                                      (((x) & RF2G2_CH1_PDRXLO_MASK) >> RF2G2_CH1_PDRXLO_LSB)
#define RF2G2_CH1_PDRXLO_SET(x)                                      (((0 | (x)) << RF2G2_CH1_PDRXLO_LSB) & RF2G2_CH1_PDRXLO_MASK)
#define RF2G2_CH1_PDRXLO_RESET                                       0
#define RF2G2_CH1_PDTXLO_MSB                                         23
#define RF2G2_CH1_PDTXLO_LSB                                         23
#define RF2G2_CH1_PDTXLO_MASK                                        0x00800000
#define RF2G2_CH1_PDTXLO_GET(x)                                      (((x) & RF2G2_CH1_PDTXLO_MASK) >> RF2G2_CH1_PDTXLO_LSB)
#define RF2G2_CH1_PDTXLO_SET(x)                                      (((0 | (x)) << RF2G2_CH1_PDTXLO_LSB) & RF2G2_CH1_PDTXLO_MASK)
#define RF2G2_CH1_PDTXLO_RESET                                       0
#define RF2G2_CH1_PDTXMIX_MSB                                        22
#define RF2G2_CH1_PDTXMIX_LSB                                        22
#define RF2G2_CH1_PDTXMIX_MASK                                       0x00400000
#define RF2G2_CH1_PDTXMIX_GET(x)                                     (((x) & RF2G2_CH1_PDTXMIX_MASK) >> RF2G2_CH1_PDTXMIX_LSB)
#define RF2G2_CH1_PDTXMIX_SET(x)                                     (((0 | (x)) << RF2G2_CH1_PDTXMIX_LSB) & RF2G2_CH1_PDTXMIX_MASK)
#define RF2G2_CH1_PDTXMIX_RESET                                      0
#define RF2G2_CH1_PDIR25U_TXMIX_MSB                                  21
#define RF2G2_CH1_PDIR25U_TXMIX_LSB                                  19
#define RF2G2_CH1_PDIR25U_TXMIX_MASK                                 0x00380000
#define RF2G2_CH1_PDIR25U_TXMIX_GET(x)                               (((x) & RF2G2_CH1_PDIR25U_TXMIX_MASK) >> RF2G2_CH1_PDIR25U_TXMIX_LSB)
#define RF2G2_CH1_PDIR25U_TXMIX_SET(x)                               (((0 | (x)) << RF2G2_CH1_PDIR25U_TXMIX_LSB) & RF2G2_CH1_PDIR25U_TXMIX_MASK)
#define RF2G2_CH1_PDIR25U_TXMIX_RESET                                3
#define RF2G2_CH1_PDIR25U_TXPA_MSB                                   18
#define RF2G2_CH1_PDIR25U_TXPA_LSB                                   18
#define RF2G2_CH1_PDIR25U_TXPA_MASK                                  0x00040000
#define RF2G2_CH1_PDIR25U_TXPA_GET(x)                                (((x) & RF2G2_CH1_PDIR25U_TXPA_MASK) >> RF2G2_CH1_PDIR25U_TXPA_LSB)
#define RF2G2_CH1_PDIR25U_TXPA_SET(x)                                (((0 | (x)) << RF2G2_CH1_PDIR25U_TXPA_LSB) & RF2G2_CH1_PDIR25U_TXPA_MASK)
#define RF2G2_CH1_PDIR25U_TXPA_RESET                                 0
#define RF2G2_CH1_PDIC25U_TXPA_MSB                                   17
#define RF2G2_CH1_PDIC25U_TXPA_LSB                                   15
#define RF2G2_CH1_PDIC25U_TXPA_MASK                                  0x00038000
#define RF2G2_CH1_PDIC25U_TXPA_GET(x)                                (((x) & RF2G2_CH1_PDIC25U_TXPA_MASK) >> RF2G2_CH1_PDIC25U_TXPA_LSB)
#define RF2G2_CH1_PDIC25U_TXPA_SET(x)                                (((0 | (x)) << RF2G2_CH1_PDIC25U_TXPA_LSB) & RF2G2_CH1_PDIC25U_TXPA_MASK)
#define RF2G2_CH1_PDIC25U_TXPA_RESET                                 3
#define RF2G2_CH1_PDIC25U_TXRF_MSB                                   14
#define RF2G2_CH1_PDIC25U_TXRF_LSB                                   12
#define RF2G2_CH1_PDIC25U_TXRF_MASK                                  0x00007000
#define RF2G2_CH1_PDIC25U_TXRF_GET(x)                                (((x) & RF2G2_CH1_PDIC25U_TXRF_MASK) >> RF2G2_CH1_PDIC25U_TXRF_LSB)
#define RF2G2_CH1_PDIC25U_TXRF_SET(x)                                (((0 | (x)) << RF2G2_CH1_PDIC25U_TXRF_LSB) & RF2G2_CH1_PDIC25U_TXRF_MASK)
#define RF2G2_CH1_PDIC25U_TXRF_RESET                                 3
#define RF2G2_CH1_PDIC25U_RXRF_MSB                                   11
#define RF2G2_CH1_PDIC25U_RXRF_LSB                                   9
#define RF2G2_CH1_PDIC25U_RXRF_MASK                                  0x00000e00
#define RF2G2_CH1_PDIC25U_RXRF_GET(x)                                (((x) & RF2G2_CH1_PDIC25U_RXRF_MASK) >> RF2G2_CH1_PDIC25U_RXRF_LSB)
#define RF2G2_CH1_PDIC25U_RXRF_SET(x)                                (((0 | (x)) << RF2G2_CH1_PDIC25U_RXRF_LSB) & RF2G2_CH1_PDIC25U_RXRF_MASK)
#define RF2G2_CH1_PDIC25U_RXRF_RESET                                 7
#define RF2G2_CH1_PDIC50U_DIV_MSB                                    8
#define RF2G2_CH1_PDIC50U_DIV_LSB                                    6
#define RF2G2_CH1_PDIC50U_DIV_MASK                                   0x000001c0
#define RF2G2_CH1_PDIC50U_DIV_GET(x)                                 (((x) & RF2G2_CH1_PDIC50U_DIV_MASK) >> RF2G2_CH1_PDIC50U_DIV_LSB)
#define RF2G2_CH1_PDIC50U_DIV_SET(x)                                 (((0 | (x)) << RF2G2_CH1_PDIC50U_DIV_LSB) & RF2G2_CH1_PDIC50U_DIV_MASK)
#define RF2G2_CH1_PDIC50U_DIV_RESET                                  3
#define RF2G2_CH1_PDIC25U_VREGLO_MSB                                 5
#define RF2G2_CH1_PDIC25U_VREGLO_LSB                                 3
#define RF2G2_CH1_PDIC25U_VREGLO_MASK                                0x00000038
#define RF2G2_CH1_PDIC25U_VREGLO_GET(x)                              (((x) & RF2G2_CH1_PDIC25U_VREGLO_MASK) >> RF2G2_CH1_PDIC25U_VREGLO_LSB)
#define RF2G2_CH1_PDIC25U_VREGLO_SET(x)                              (((0 | (x)) << RF2G2_CH1_PDIC25U_VREGLO_LSB) & RF2G2_CH1_PDIC25U_VREGLO_MASK)
#define RF2G2_CH1_PDIC25U_VREGLO_RESET                               7
#define RF2G2_CH1_PDIR25U_VREGLO_MSB                                 2
#define RF2G2_CH1_PDIR25U_VREGLO_LSB                                 0
#define RF2G2_CH1_PDIR25U_VREGLO_MASK                                0x00000007
#define RF2G2_CH1_PDIR25U_VREGLO_GET(x)                              (((x) & RF2G2_CH1_PDIR25U_VREGLO_MASK) >> RF2G2_CH1_PDIR25U_VREGLO_LSB)
#define RF2G2_CH1_PDIR25U_VREGLO_SET(x)                              (((0 | (x)) << RF2G2_CH1_PDIR25U_VREGLO_LSB) & RF2G2_CH1_PDIR25U_VREGLO_MASK)
#define RF2G2_CH1_PDIR25U_VREGLO_RESET                               7
#define RF2G2_CH1_ADDRESS                                            0x0014
#define RF2G2_CH1_HW_MASK                                            0xffffffff
#define RF2G2_CH1_SW_MASK                                            0xffffffff
#define RF2G2_CH1_HW_WRITE_MASK                                      0x00000000
#define RF2G2_CH1_SW_WRITE_MASK                                      0xffffffff
#define RF2G2_CH1_RSTMASK                                            0xffffffff
#define RF2G2_CH1_RESET                                              0x0019beff

// 0x0018 (RF5G1_CH1)
#define RF5G1_CH1_PDTXLO5_MSB                                        31
#define RF5G1_CH1_PDTXLO5_LSB                                        31
#define RF5G1_CH1_PDTXLO5_MASK                                       0x80000000
#define RF5G1_CH1_PDTXLO5_GET(x)                                     (((x) & RF5G1_CH1_PDTXLO5_MASK) >> RF5G1_CH1_PDTXLO5_LSB)
#define RF5G1_CH1_PDTXLO5_SET(x)                                     (((0 | (x)) << RF5G1_CH1_PDTXLO5_LSB) & RF5G1_CH1_PDTXLO5_MASK)
#define RF5G1_CH1_PDTXLO5_RESET                                      0
#define RF5G1_CH1_PDTXMIX5_MSB                                       30
#define RF5G1_CH1_PDTXMIX5_LSB                                       30
#define RF5G1_CH1_PDTXMIX5_MASK                                      0x40000000
#define RF5G1_CH1_PDTXMIX5_GET(x)                                    (((x) & RF5G1_CH1_PDTXMIX5_MASK) >> RF5G1_CH1_PDTXMIX5_LSB)
#define RF5G1_CH1_PDTXMIX5_SET(x)                                    (((0 | (x)) << RF5G1_CH1_PDTXMIX5_LSB) & RF5G1_CH1_PDTXMIX5_MASK)
#define RF5G1_CH1_PDTXMIX5_RESET                                     0
#define RF5G1_CH1_PDTXBUF5_MSB                                       29
#define RF5G1_CH1_PDTXBUF5_LSB                                       29
#define RF5G1_CH1_PDTXBUF5_MASK                                      0x20000000
#define RF5G1_CH1_PDTXBUF5_GET(x)                                    (((x) & RF5G1_CH1_PDTXBUF5_MASK) >> RF5G1_CH1_PDTXBUF5_LSB)
#define RF5G1_CH1_PDTXBUF5_SET(x)                                    (((0 | (x)) << RF5G1_CH1_PDTXBUF5_LSB) & RF5G1_CH1_PDTXBUF5_MASK)
#define RF5G1_CH1_PDTXBUF5_RESET                                     0
#define RF5G1_CH1_PDPADRV5_MSB                                       28
#define RF5G1_CH1_PDPADRV5_LSB                                       28
#define RF5G1_CH1_PDPADRV5_MASK                                      0x10000000
#define RF5G1_CH1_PDPADRV5_GET(x)                                    (((x) & RF5G1_CH1_PDPADRV5_MASK) >> RF5G1_CH1_PDPADRV5_LSB)
#define RF5G1_CH1_PDPADRV5_SET(x)                                    (((0 | (x)) << RF5G1_CH1_PDPADRV5_LSB) & RF5G1_CH1_PDPADRV5_MASK)
#define RF5G1_CH1_PDPADRV5_RESET                                     0
#define RF5G1_CH1_PDPAOUT5_MSB                                       27
#define RF5G1_CH1_PDPAOUT5_LSB                                       27
#define RF5G1_CH1_PDPAOUT5_MASK                                      0x08000000
#define RF5G1_CH1_PDPAOUT5_GET(x)                                    (((x) & RF5G1_CH1_PDPAOUT5_MASK) >> RF5G1_CH1_PDPAOUT5_LSB)
#define RF5G1_CH1_PDPAOUT5_SET(x)                                    (((0 | (x)) << RF5G1_CH1_PDPAOUT5_LSB) & RF5G1_CH1_PDPAOUT5_MASK)
#define RF5G1_CH1_PDPAOUT5_RESET                                     0
#define RF5G1_CH1_PACASCBIAS_MSB                                     26
#define RF5G1_CH1_PACASCBIAS_LSB                                     25
#define RF5G1_CH1_PACASCBIAS_MASK                                    0x06000000
#define RF5G1_CH1_PACASCBIAS_GET(x)                                  (((x) & RF5G1_CH1_PACASCBIAS_MASK) >> RF5G1_CH1_PACASCBIAS_LSB)
#define RF5G1_CH1_PACASCBIAS_SET(x)                                  (((0 | (x)) << RF5G1_CH1_PACASCBIAS_LSB) & RF5G1_CH1_PACASCBIAS_MASK)
#define RF5G1_CH1_PACASCBIAS_RESET                                   3
#define RF5G1_CH1_PWDTXPKD_MSB                                       24
#define RF5G1_CH1_PWDTXPKD_LSB                                       22
#define RF5G1_CH1_PWDTXPKD_MASK                                      0x01c00000
#define RF5G1_CH1_PWDTXPKD_GET(x)                                    (((x) & RF5G1_CH1_PWDTXPKD_MASK) >> RF5G1_CH1_PWDTXPKD_LSB)
#define RF5G1_CH1_PWDTXPKD_SET(x)                                    (((0 | (x)) << RF5G1_CH1_PWDTXPKD_LSB) & RF5G1_CH1_PWDTXPKD_MASK)
#define RF5G1_CH1_PWDTXPKD_RESET                                     7
#define RF5G1_CH1_DB5_MSB                                            21
#define RF5G1_CH1_DB5_LSB                                            19
#define RF5G1_CH1_DB5_MASK                                           0x00380000
#define RF5G1_CH1_DB5_GET(x)                                         (((x) & RF5G1_CH1_DB5_MASK) >> RF5G1_CH1_DB5_LSB)
#define RF5G1_CH1_DB5_SET(x)                                         (((0 | (x)) << RF5G1_CH1_DB5_LSB) & RF5G1_CH1_DB5_MASK)
#define RF5G1_CH1_DB5_RESET                                          4
#define RF5G1_CH1_OB5_MSB                                            18
#define RF5G1_CH1_OB5_LSB                                            16
#define RF5G1_CH1_OB5_MASK                                           0x00070000
#define RF5G1_CH1_OB5_GET(x)                                         (((x) & RF5G1_CH1_OB5_MASK) >> RF5G1_CH1_OB5_LSB)
#define RF5G1_CH1_OB5_SET(x)                                         (((0 | (x)) << RF5G1_CH1_OB5_LSB) & RF5G1_CH1_OB5_MASK)
#define RF5G1_CH1_OB5_RESET                                          4
#define RF5G1_CH1_TX5_ATB_SEL_MSB                                    15
#define RF5G1_CH1_TX5_ATB_SEL_LSB                                    13
#define RF5G1_CH1_TX5_ATB_SEL_MASK                                   0x0000e000
#define RF5G1_CH1_TX5_ATB_SEL_GET(x)                                 (((x) & RF5G1_CH1_TX5_ATB_SEL_MASK) >> RF5G1_CH1_TX5_ATB_SEL_LSB)
#define RF5G1_CH1_TX5_ATB_SEL_SET(x)                                 (((0 | (x)) << RF5G1_CH1_TX5_ATB_SEL_LSB) & RF5G1_CH1_TX5_ATB_SEL_MASK)
#define RF5G1_CH1_TX5_ATB_SEL_RESET                                  0
#define RF5G1_CH1_LO5CONTROL_MSB                                     12
#define RF5G1_CH1_LO5CONTROL_LSB                                     12
#define RF5G1_CH1_LO5CONTROL_MASK                                    0x00001000
#define RF5G1_CH1_LO5CONTROL_GET(x)                                  (((x) & RF5G1_CH1_LO5CONTROL_MASK) >> RF5G1_CH1_LO5CONTROL_LSB)
#define RF5G1_CH1_LO5CONTROL_SET(x)                                  (((0 | (x)) << RF5G1_CH1_LO5CONTROL_LSB) & RF5G1_CH1_LO5CONTROL_MASK)
#define RF5G1_CH1_LO5CONTROL_RESET                                   0
#define RF5G1_CH1_REGLO_BYPASS5_MSB                                  11
#define RF5G1_CH1_REGLO_BYPASS5_LSB                                  11
#define RF5G1_CH1_REGLO_BYPASS5_MASK                                 0x00000800
#define RF5G1_CH1_REGLO_BYPASS5_GET(x)                               (((x) & RF5G1_CH1_REGLO_BYPASS5_MASK) >> RF5G1_CH1_REGLO_BYPASS5_LSB)
#define RF5G1_CH1_REGLO_BYPASS5_SET(x)                               (((0 | (x)) << RF5G1_CH1_REGLO_BYPASS5_LSB) & RF5G1_CH1_REGLO_BYPASS5_MASK)
#define RF5G1_CH1_REGLO_BYPASS5_RESET                                0
#define RF5G1_CH1_PDREGLO5_MSB                                       10
#define RF5G1_CH1_PDREGLO5_LSB                                       10
#define RF5G1_CH1_PDREGLO5_MASK                                      0x00000400
#define RF5G1_CH1_PDREGLO5_GET(x)                                    (((x) & RF5G1_CH1_PDREGLO5_MASK) >> RF5G1_CH1_PDREGLO5_LSB)
#define RF5G1_CH1_PDREGLO5_SET(x)                                    (((0 | (x)) << RF5G1_CH1_PDREGLO5_LSB) & RF5G1_CH1_PDREGLO5_MASK)
#define RF5G1_CH1_PDREGLO5_RESET                                     0
#define RF5G1_CH1_SPARE_MSB                                          9
#define RF5G1_CH1_SPARE_LSB                                          0
#define RF5G1_CH1_SPARE_MASK                                         0x000003ff
#define RF5G1_CH1_SPARE_GET(x)                                       (((x) & RF5G1_CH1_SPARE_MASK) >> RF5G1_CH1_SPARE_LSB)
#define RF5G1_CH1_SPARE_SET(x)                                       (((0 | (x)) << RF5G1_CH1_SPARE_LSB) & RF5G1_CH1_SPARE_MASK)
#define RF5G1_CH1_SPARE_RESET                                        0
#define RF5G1_CH1_ADDRESS                                            0x0018
#define RF5G1_CH1_HW_MASK                                            0xffffffff
#define RF5G1_CH1_SW_MASK                                            0xffffffff
#define RF5G1_CH1_HW_WRITE_MASK                                      0x00000000
#define RF5G1_CH1_SW_WRITE_MASK                                      0xffffffff
#define RF5G1_CH1_RSTMASK                                            0xffffffff
#define RF5G1_CH1_RESET                                              0x07e40000

// 0x001c (RF5G2_CH1)
#define RF5G2_CH1_REGFE_BYPASS5_MSB                                  31
#define RF5G2_CH1_REGFE_BYPASS5_LSB                                  31
#define RF5G2_CH1_REGFE_BYPASS5_MASK                                 0x80000000
#define RF5G2_CH1_REGFE_BYPASS5_GET(x)                               (((x) & RF5G2_CH1_REGFE_BYPASS5_MASK) >> RF5G2_CH1_REGFE_BYPASS5_LSB)
#define RF5G2_CH1_REGFE_BYPASS5_SET(x)                               (((0 | (x)) << RF5G2_CH1_REGFE_BYPASS5_LSB) & RF5G2_CH1_REGFE_BYPASS5_MASK)
#define RF5G2_CH1_REGFE_BYPASS5_RESET                                0
#define RF5G2_CH1_PDREGFE5_MSB                                       30
#define RF5G2_CH1_PDREGFE5_LSB                                       30
#define RF5G2_CH1_PDREGFE5_MASK                                      0x40000000
#define RF5G2_CH1_PDREGFE5_GET(x)                                    (((x) & RF5G2_CH1_PDREGFE5_MASK) >> RF5G2_CH1_PDREGFE5_LSB)
#define RF5G2_CH1_PDREGFE5_SET(x)                                    (((0 | (x)) << RF5G2_CH1_PDREGFE5_LSB) & RF5G2_CH1_PDREGFE5_MASK)
#define RF5G2_CH1_PDREGFE5_RESET                                     0
#define RF5G2_CH1_PDRXLO5_MSB                                        29
#define RF5G2_CH1_PDRXLO5_LSB                                        29
#define RF5G2_CH1_PDRXLO5_MASK                                       0x20000000
#define RF5G2_CH1_PDRXLO5_GET(x)                                     (((x) & RF5G2_CH1_PDRXLO5_MASK) >> RF5G2_CH1_PDRXLO5_LSB)
#define RF5G2_CH1_PDRXLO5_SET(x)                                     (((0 | (x)) << RF5G2_CH1_PDRXLO5_LSB) & RF5G2_CH1_PDRXLO5_MASK)
#define RF5G2_CH1_PDRXLO5_RESET                                      0
#define RF5G2_CH1_PDVGM5_MSB                                         28
#define RF5G2_CH1_PDVGM5_LSB                                         28
#define RF5G2_CH1_PDVGM5_MASK                                        0x10000000
#define RF5G2_CH1_PDVGM5_GET(x)                                      (((x) & RF5G2_CH1_PDVGM5_MASK) >> RF5G2_CH1_PDVGM5_LSB)
#define RF5G2_CH1_PDVGM5_SET(x)                                      (((0 | (x)) << RF5G2_CH1_PDVGM5_LSB) & RF5G2_CH1_PDVGM5_MASK)
#define RF5G2_CH1_PDVGM5_RESET                                       0
#define RF5G2_CH1_PDCSLNA5_MSB                                       27
#define RF5G2_CH1_PDCSLNA5_LSB                                       27
#define RF5G2_CH1_PDCSLNA5_MASK                                      0x08000000
#define RF5G2_CH1_PDCSLNA5_GET(x)                                    (((x) & RF5G2_CH1_PDCSLNA5_MASK) >> RF5G2_CH1_PDCSLNA5_LSB)
#define RF5G2_CH1_PDCSLNA5_SET(x)                                    (((0 | (x)) << RF5G2_CH1_PDCSLNA5_LSB) & RF5G2_CH1_PDCSLNA5_MASK)
#define RF5G2_CH1_PDCSLNA5_RESET                                     0
#define RF5G2_CH1_PDRFVGA5_MSB                                       26
#define RF5G2_CH1_PDRFVGA5_LSB                                       26
#define RF5G2_CH1_PDRFVGA5_MASK                                      0x04000000
#define RF5G2_CH1_PDRFVGA5_GET(x)                                    (((x) & RF5G2_CH1_PDRFVGA5_MASK) >> RF5G2_CH1_PDRFVGA5_LSB)
#define RF5G2_CH1_PDRFVGA5_SET(x)                                    (((0 | (x)) << RF5G2_CH1_PDRFVGA5_LSB) & RF5G2_CH1_PDRFVGA5_MASK)
#define RF5G2_CH1_PDRFVGA5_RESET                                     0
#define RF5G2_CH1_RX5_ATB_SEL_MSB                                    25
#define RF5G2_CH1_RX5_ATB_SEL_LSB                                    23
#define RF5G2_CH1_RX5_ATB_SEL_MASK                                   0x03800000
#define RF5G2_CH1_RX5_ATB_SEL_GET(x)                                 (((x) & RF5G2_CH1_RX5_ATB_SEL_MASK) >> RF5G2_CH1_RX5_ATB_SEL_LSB)
#define RF5G2_CH1_RX5_ATB_SEL_SET(x)                                 (((0 | (x)) << RF5G2_CH1_RX5_ATB_SEL_LSB) & RF5G2_CH1_RX5_ATB_SEL_MASK)
#define RF5G2_CH1_RX5_ATB_SEL_RESET                                  0
#define RF5G2_CH1_PDBIRTXMIX_MSB                                     22
#define RF5G2_CH1_PDBIRTXMIX_LSB                                     20
#define RF5G2_CH1_PDBIRTXMIX_MASK                                    0x00700000
#define RF5G2_CH1_PDBIRTXMIX_GET(x)                                  (((x) & RF5G2_CH1_PDBIRTXMIX_MASK) >> RF5G2_CH1_PDBIRTXMIX_LSB)
#define RF5G2_CH1_PDBIRTXMIX_SET(x)                                  (((0 | (x)) << RF5G2_CH1_PDBIRTXMIX_LSB) & RF5G2_CH1_PDBIRTXMIX_MASK)
#define RF5G2_CH1_PDBIRTXMIX_RESET                                   4
#define RF5G2_CH1_PDBIRTXPA_MSB                                      19
#define RF5G2_CH1_PDBIRTXPA_LSB                                      17
#define RF5G2_CH1_PDBIRTXPA_MASK                                     0x000e0000
#define RF5G2_CH1_PDBIRTXPA_GET(x)                                   (((x) & RF5G2_CH1_PDBIRTXPA_MASK) >> RF5G2_CH1_PDBIRTXPA_LSB)
#define RF5G2_CH1_PDBIRTXPA_SET(x)                                   (((0 | (x)) << RF5G2_CH1_PDBIRTXPA_LSB) & RF5G2_CH1_PDBIRTXPA_MASK)
#define RF5G2_CH1_PDBIRTXPA_RESET                                    4
#define RF5G2_CH1_PDBIR1_MSB                                         16
#define RF5G2_CH1_PDBIR1_LSB                                         14
#define RF5G2_CH1_PDBIR1_MASK                                        0x0001c000
#define RF5G2_CH1_PDBIR1_GET(x)                                      (((x) & RF5G2_CH1_PDBIR1_MASK) >> RF5G2_CH1_PDBIR1_LSB)
#define RF5G2_CH1_PDBIR1_SET(x)                                      (((0 | (x)) << RF5G2_CH1_PDBIR1_LSB) & RF5G2_CH1_PDBIR1_MASK)
#define RF5G2_CH1_PDBIR1_RESET                                       4
#define RF5G2_CH1_PDBIR2_MSB                                         13
#define RF5G2_CH1_PDBIR2_LSB                                         11
#define RF5G2_CH1_PDBIR2_MASK                                        0x00003800
#define RF5G2_CH1_PDBIR2_GET(x)                                      (((x) & RF5G2_CH1_PDBIR2_MASK) >> RF5G2_CH1_PDBIR2_LSB)
#define RF5G2_CH1_PDBIR2_SET(x)                                      (((0 | (x)) << RF5G2_CH1_PDBIR2_LSB) & RF5G2_CH1_PDBIR2_MASK)
#define RF5G2_CH1_PDBIR2_RESET                                       4
#define RF5G2_CH1_SPARE_MSB                                          10
#define RF5G2_CH1_SPARE_LSB                                          0
#define RF5G2_CH1_SPARE_MASK                                         0x000007ff
#define RF5G2_CH1_SPARE_GET(x)                                       (((x) & RF5G2_CH1_SPARE_MASK) >> RF5G2_CH1_SPARE_LSB)
#define RF5G2_CH1_SPARE_SET(x)                                       (((0 | (x)) << RF5G2_CH1_SPARE_LSB) & RF5G2_CH1_SPARE_MASK)
#define RF5G2_CH1_SPARE_RESET                                        0
#define RF5G2_CH1_ADDRESS                                            0x001c
#define RF5G2_CH1_HW_MASK                                            0xffffffff
#define RF5G2_CH1_SW_MASK                                            0xffffffff
#define RF5G2_CH1_HW_WRITE_MASK                                      0x00000000
#define RF5G2_CH1_SW_WRITE_MASK                                      0xffffffff
#define RF5G2_CH1_RSTMASK                                            0xffffffff
#define RF5G2_CH1_RESET                                              0x00492000

// 0x0020 (RF5G3_CH1)
#define RF5G3_CH1_PDBICTXBUF_MSB                                     31
#define RF5G3_CH1_PDBICTXBUF_LSB                                     29
#define RF5G3_CH1_PDBICTXBUF_MASK                                    0xe0000000
#define RF5G3_CH1_PDBICTXBUF_GET(x)                                  (((x) & RF5G3_CH1_PDBICTXBUF_MASK) >> RF5G3_CH1_PDBICTXBUF_LSB)
#define RF5G3_CH1_PDBICTXBUF_SET(x)                                  (((0 | (x)) << RF5G3_CH1_PDBICTXBUF_LSB) & RF5G3_CH1_PDBICTXBUF_MASK)
#define RF5G3_CH1_PDBICTXBUF_RESET                                   4
#define RF5G3_CH1_PDBICTXPA_MSB                                      28
#define RF5G3_CH1_PDBICTXPA_LSB                                      26
#define RF5G3_CH1_PDBICTXPA_MASK                                     0x1c000000
#define RF5G3_CH1_PDBICTXPA_GET(x)                                   (((x) & RF5G3_CH1_PDBICTXPA_MASK) >> RF5G3_CH1_PDBICTXPA_LSB)
#define RF5G3_CH1_PDBICTXPA_SET(x)                                   (((0 | (x)) << RF5G3_CH1_PDBICTXPA_LSB) & RF5G3_CH1_PDBICTXPA_MASK)
#define RF5G3_CH1_PDBICTXPA_RESET                                    4
#define RF5G3_CH1_PDBICTXMIX_MSB                                     25
#define RF5G3_CH1_PDBICTXMIX_LSB                                     23
#define RF5G3_CH1_PDBICTXMIX_MASK                                    0x03800000
#define RF5G3_CH1_PDBICTXMIX_GET(x)                                  (((x) & RF5G3_CH1_PDBICTXMIX_MASK) >> RF5G3_CH1_PDBICTXMIX_LSB)
#define RF5G3_CH1_PDBICTXMIX_SET(x)                                  (((0 | (x)) << RF5G3_CH1_PDBICTXMIX_LSB) & RF5G3_CH1_PDBICTXMIX_MASK)
#define RF5G3_CH1_PDBICTXMIX_RESET                                   4
#define RF5G3_CH1_PDBIC1_MSB                                         22
#define RF5G3_CH1_PDBIC1_LSB                                         20
#define RF5G3_CH1_PDBIC1_MASK                                        0x00700000
#define RF5G3_CH1_PDBIC1_GET(x)                                      (((x) & RF5G3_CH1_PDBIC1_MASK) >> RF5G3_CH1_PDBIC1_LSB)
#define RF5G3_CH1_PDBIC1_SET(x)                                      (((0 | (x)) << RF5G3_CH1_PDBIC1_LSB) & RF5G3_CH1_PDBIC1_MASK)
#define RF5G3_CH1_PDBIC1_RESET                                       4
#define RF5G3_CH1_PDBIC2_MSB                                         19
#define RF5G3_CH1_PDBIC2_LSB                                         17
#define RF5G3_CH1_PDBIC2_MASK                                        0x000e0000
#define RF5G3_CH1_PDBIC2_GET(x)                                      (((x) & RF5G3_CH1_PDBIC2_MASK) >> RF5G3_CH1_PDBIC2_LSB)
#define RF5G3_CH1_PDBIC2_SET(x)                                      (((0 | (x)) << RF5G3_CH1_PDBIC2_LSB) & RF5G3_CH1_PDBIC2_MASK)
#define RF5G3_CH1_PDBIC2_RESET                                       4
#define RF5G3_CH1_PDBIC3_MSB                                         16
#define RF5G3_CH1_PDBIC3_LSB                                         14
#define RF5G3_CH1_PDBIC3_MASK                                        0x0001c000
#define RF5G3_CH1_PDBIC3_GET(x)                                      (((x) & RF5G3_CH1_PDBIC3_MASK) >> RF5G3_CH1_PDBIC3_LSB)
#define RF5G3_CH1_PDBIC3_SET(x)                                      (((0 | (x)) << RF5G3_CH1_PDBIC3_LSB) & RF5G3_CH1_PDBIC3_MASK)
#define RF5G3_CH1_PDBIC3_RESET                                       4
#define RF5G3_CH1_PDBIBCLNA_MSB                                      13
#define RF5G3_CH1_PDBIBCLNA_LSB                                      11
#define RF5G3_CH1_PDBIBCLNA_MASK                                     0x00003800
#define RF5G3_CH1_PDBIBCLNA_GET(x)                                   (((x) & RF5G3_CH1_PDBIBCLNA_MASK) >> RF5G3_CH1_PDBIBCLNA_LSB)
#define RF5G3_CH1_PDBIBCLNA_SET(x)                                   (((0 | (x)) << RF5G3_CH1_PDBIBCLNA_LSB) & RF5G3_CH1_PDBIBCLNA_MASK)
#define RF5G3_CH1_PDBIBCLNA_RESET                                    4
#define RF5G3_CH1_PDBIBCRFVGA_MSB                                    10
#define RF5G3_CH1_PDBIBCRFVGA_LSB                                    8
#define RF5G3_CH1_PDBIBCRFVGA_MASK                                   0x00000700
#define RF5G3_CH1_PDBIBCRFVGA_GET(x)                                 (((x) & RF5G3_CH1_PDBIBCRFVGA_MASK) >> RF5G3_CH1_PDBIBCRFVGA_LSB)
#define RF5G3_CH1_PDBIBCRFVGA_SET(x)                                 (((0 | (x)) << RF5G3_CH1_PDBIBCRFVGA_LSB) & RF5G3_CH1_PDBIBCRFVGA_MASK)
#define RF5G3_CH1_PDBIBCRFVGA_RESET                                  4
#define RF5G3_CH1_PDBIBCVGM_MSB                                      7
#define RF5G3_CH1_PDBIBCVGM_LSB                                      5
#define RF5G3_CH1_PDBIBCVGM_MASK                                     0x000000e0
#define RF5G3_CH1_PDBIBCVGM_GET(x)                                   (((x) & RF5G3_CH1_PDBIBCVGM_MASK) >> RF5G3_CH1_PDBIBCVGM_LSB)
#define RF5G3_CH1_PDBIBCVGM_SET(x)                                   (((0 | (x)) << RF5G3_CH1_PDBIBCVGM_LSB) & RF5G3_CH1_PDBIBCVGM_MASK)
#define RF5G3_CH1_PDBIBCVGM_RESET                                    4
#define RF5G3_CH1_SPARE_MSB                                          4
#define RF5G3_CH1_SPARE_LSB                                          0
#define RF5G3_CH1_SPARE_MASK                                         0x0000001f
#define RF5G3_CH1_SPARE_GET(x)                                       (((x) & RF5G3_CH1_SPARE_MASK) >> RF5G3_CH1_SPARE_LSB)
#define RF5G3_CH1_SPARE_SET(x)                                       (((0 | (x)) << RF5G3_CH1_SPARE_LSB) & RF5G3_CH1_SPARE_MASK)
#define RF5G3_CH1_SPARE_RESET                                        0
#define RF5G3_CH1_ADDRESS                                            0x0020
#define RF5G3_CH1_HW_MASK                                            0xffffffff
#define RF5G3_CH1_SW_MASK                                            0xffffffff
#define RF5G3_CH1_HW_WRITE_MASK                                      0x00000000
#define RF5G3_CH1_SW_WRITE_MASK                                      0xffffffff
#define RF5G3_CH1_RSTMASK                                            0xffffffff
#define RF5G3_CH1_RESET                                              0x92492480

// 0x0024 (RXTXBB1_CH0)
#define RXTXBB1_CH0_SPARE_MSB                                        31
#define RXTXBB1_CH0_SPARE_LSB                                        19
#define RXTXBB1_CH0_SPARE_MASK                                       0xfff80000
#define RXTXBB1_CH0_SPARE_GET(x)                                     (((x) & RXTXBB1_CH0_SPARE_MASK) >> RXTXBB1_CH0_SPARE_LSB)
#define RXTXBB1_CH0_SPARE_SET(x)                                     (((0 | (x)) << RXTXBB1_CH0_SPARE_LSB) & RXTXBB1_CH0_SPARE_MASK)
#define RXTXBB1_CH0_SPARE_RESET                                      0
#define RXTXBB1_CH0_FNOTCH_MSB                                       18
#define RXTXBB1_CH0_FNOTCH_LSB                                       17
#define RXTXBB1_CH0_FNOTCH_MASK                                      0x00060000
#define RXTXBB1_CH0_FNOTCH_GET(x)                                    (((x) & RXTXBB1_CH0_FNOTCH_MASK) >> RXTXBB1_CH0_FNOTCH_LSB)
#define RXTXBB1_CH0_FNOTCH_SET(x)                                    (((0 | (x)) << RXTXBB1_CH0_FNOTCH_LSB) & RXTXBB1_CH0_FNOTCH_MASK)
#define RXTXBB1_CH0_FNOTCH_RESET                                     0
#define RXTXBB1_CH0_SEL_ATB_MSB                                      16
#define RXTXBB1_CH0_SEL_ATB_LSB                                      9
#define RXTXBB1_CH0_SEL_ATB_MASK                                     0x0001fe00
#define RXTXBB1_CH0_SEL_ATB_GET(x)                                   (((x) & RXTXBB1_CH0_SEL_ATB_MASK) >> RXTXBB1_CH0_SEL_ATB_LSB)
#define RXTXBB1_CH0_SEL_ATB_SET(x)                                   (((0 | (x)) << RXTXBB1_CH0_SEL_ATB_LSB) & RXTXBB1_CH0_SEL_ATB_MASK)
#define RXTXBB1_CH0_SEL_ATB_RESET                                    0
#define RXTXBB1_CH0_PDDACINTERFACE_MSB                               8
#define RXTXBB1_CH0_PDDACINTERFACE_LSB                               8
#define RXTXBB1_CH0_PDDACINTERFACE_MASK                              0x00000100
#define RXTXBB1_CH0_PDDACINTERFACE_GET(x)                            (((x) & RXTXBB1_CH0_PDDACINTERFACE_MASK) >> RXTXBB1_CH0_PDDACINTERFACE_LSB)
#define RXTXBB1_CH0_PDDACINTERFACE_SET(x)                            (((0 | (x)) << RXTXBB1_CH0_PDDACINTERFACE_LSB) & RXTXBB1_CH0_PDDACINTERFACE_MASK)
#define RXTXBB1_CH0_PDDACINTERFACE_RESET                             0
#define RXTXBB1_CH0_PDV2I_MSB                                        7
#define RXTXBB1_CH0_PDV2I_LSB                                        7
#define RXTXBB1_CH0_PDV2I_MASK                                       0x00000080
#define RXTXBB1_CH0_PDV2I_GET(x)                                     (((x) & RXTXBB1_CH0_PDV2I_MASK) >> RXTXBB1_CH0_PDV2I_LSB)
#define RXTXBB1_CH0_PDV2I_SET(x)                                     (((0 | (x)) << RXTXBB1_CH0_PDV2I_LSB) & RXTXBB1_CH0_PDV2I_MASK)
#define RXTXBB1_CH0_PDV2I_RESET                                      0
#define RXTXBB1_CH0_PDI2V_MSB                                        6
#define RXTXBB1_CH0_PDI2V_LSB                                        6
#define RXTXBB1_CH0_PDI2V_MASK                                       0x00000040
#define RXTXBB1_CH0_PDI2V_GET(x)                                     (((x) & RXTXBB1_CH0_PDI2V_MASK) >> RXTXBB1_CH0_PDI2V_LSB)
#define RXTXBB1_CH0_PDI2V_SET(x)                                     (((0 | (x)) << RXTXBB1_CH0_PDI2V_LSB) & RXTXBB1_CH0_PDI2V_MASK)
#define RXTXBB1_CH0_PDI2V_RESET                                      0
#define RXTXBB1_CH0_PDRXTXBB_MSB                                     5
#define RXTXBB1_CH0_PDRXTXBB_LSB                                     5
#define RXTXBB1_CH0_PDRXTXBB_MASK                                    0x00000020
#define RXTXBB1_CH0_PDRXTXBB_GET(x)                                  (((x) & RXTXBB1_CH0_PDRXTXBB_MASK) >> RXTXBB1_CH0_PDRXTXBB_LSB)
#define RXTXBB1_CH0_PDRXTXBB_SET(x)                                  (((0 | (x)) << RXTXBB1_CH0_PDRXTXBB_LSB) & RXTXBB1_CH0_PDRXTXBB_MASK)
#define RXTXBB1_CH0_PDRXTXBB_RESET                                   0
#define RXTXBB1_CH0_PDOFFSETLOQ_MSB                                  4
#define RXTXBB1_CH0_PDOFFSETLOQ_LSB                                  4
#define RXTXBB1_CH0_PDOFFSETLOQ_MASK                                 0x00000010
#define RXTXBB1_CH0_PDOFFSETLOQ_GET(x)                               (((x) & RXTXBB1_CH0_PDOFFSETLOQ_MASK) >> RXTXBB1_CH0_PDOFFSETLOQ_LSB)
#define RXTXBB1_CH0_PDOFFSETLOQ_SET(x)                               (((0 | (x)) << RXTXBB1_CH0_PDOFFSETLOQ_LSB) & RXTXBB1_CH0_PDOFFSETLOQ_MASK)
#define RXTXBB1_CH0_PDOFFSETLOQ_RESET                                0
#define RXTXBB1_CH0_PDOFFSETHIQ_MSB                                  3
#define RXTXBB1_CH0_PDOFFSETHIQ_LSB                                  3
#define RXTXBB1_CH0_PDOFFSETHIQ_MASK                                 0x00000008
#define RXTXBB1_CH0_PDOFFSETHIQ_GET(x)                               (((x) & RXTXBB1_CH0_PDOFFSETHIQ_MASK) >> RXTXBB1_CH0_PDOFFSETHIQ_LSB)
#define RXTXBB1_CH0_PDOFFSETHIQ_SET(x)                               (((0 | (x)) << RXTXBB1_CH0_PDOFFSETHIQ_LSB) & RXTXBB1_CH0_PDOFFSETHIQ_MASK)
#define RXTXBB1_CH0_PDOFFSETHIQ_RESET                                0
#define RXTXBB1_CH0_PDOFFSETI2V_MSB                                  2
#define RXTXBB1_CH0_PDOFFSETI2V_LSB                                  2
#define RXTXBB1_CH0_PDOFFSETI2V_MASK                                 0x00000004
#define RXTXBB1_CH0_PDOFFSETI2V_GET(x)                               (((x) & RXTXBB1_CH0_PDOFFSETI2V_MASK) >> RXTXBB1_CH0_PDOFFSETI2V_LSB)
#define RXTXBB1_CH0_PDOFFSETI2V_SET(x)                               (((0 | (x)) << RXTXBB1_CH0_PDOFFSETI2V_LSB) & RXTXBB1_CH0_PDOFFSETI2V_MASK)
#define RXTXBB1_CH0_PDOFFSETI2V_RESET                                0
#define RXTXBB1_CH0_PDLOQ_MSB                                        1
#define RXTXBB1_CH0_PDLOQ_LSB                                        1
#define RXTXBB1_CH0_PDLOQ_MASK                                       0x00000002
#define RXTXBB1_CH0_PDLOQ_GET(x)                                     (((x) & RXTXBB1_CH0_PDLOQ_MASK) >> RXTXBB1_CH0_PDLOQ_LSB)
#define RXTXBB1_CH0_PDLOQ_SET(x)                                     (((0 | (x)) << RXTXBB1_CH0_PDLOQ_LSB) & RXTXBB1_CH0_PDLOQ_MASK)
#define RXTXBB1_CH0_PDLOQ_RESET                                      0
#define RXTXBB1_CH0_PDHIQ_MSB                                        0
#define RXTXBB1_CH0_PDHIQ_LSB                                        0
#define RXTXBB1_CH0_PDHIQ_MASK                                       0x00000001
#define RXTXBB1_CH0_PDHIQ_GET(x)                                     (((x) & RXTXBB1_CH0_PDHIQ_MASK) >> RXTXBB1_CH0_PDHIQ_LSB)
#define RXTXBB1_CH0_PDHIQ_SET(x)                                     (((0 | (x)) << RXTXBB1_CH0_PDHIQ_LSB) & RXTXBB1_CH0_PDHIQ_MASK)
#define RXTXBB1_CH0_PDHIQ_RESET                                      0
#define RXTXBB1_CH0_ADDRESS                                          0x0024
#define RXTXBB1_CH0_HW_MASK                                          0xffffffff
#define RXTXBB1_CH0_SW_MASK                                          0xffffffff
#define RXTXBB1_CH0_HW_WRITE_MASK                                    0x00000000
#define RXTXBB1_CH0_SW_WRITE_MASK                                    0xffffffff
#define RXTXBB1_CH0_RSTMASK                                          0xffffffff
#define RXTXBB1_CH0_RESET                                            0x00000000

// 0x0028 (RXTXBB2_CH0)
#define RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_MSB                           31
#define RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_LSB                           29
#define RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_MASK                          0xe0000000
#define RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_GET(x)                        (((x) & RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_MASK) >> RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_LSB)
#define RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_SET(x)                        (((0 | (x)) << RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_LSB) & RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_MASK)
#define RXTXBB2_CH0_IBN_37P5_OSHI_CTRL_RESET                         6
#define RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_MSB                           28
#define RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_LSB                           26
#define RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_MASK                          0x1c000000
#define RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_GET(x)                        (((x) & RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_MASK) >> RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_LSB)
#define RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_SET(x)                        (((0 | (x)) << RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_LSB) & RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_MASK)
#define RXTXBB2_CH0_IBN_37P5_OSLO_CTRL_RESET                         6
#define RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_MSB                          25
#define RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_LSB                          23
#define RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_MASK                         0x03800000
#define RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_GET(x)                       (((x) & RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_MASK) >> RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_LSB)
#define RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_SET(x)                       (((0 | (x)) << RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_LSB) & RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_MASK)
#define RXTXBB2_CH0_IBN_37P5_OSI2V_CTRL_RESET                        6
#define RXTXBB2_CH0_SPARE_MSB                                        22
#define RXTXBB2_CH0_SPARE_LSB                                        21
#define RXTXBB2_CH0_SPARE_MASK                                       0x00600000
#define RXTXBB2_CH0_SPARE_GET(x)                                     (((x) & RXTXBB2_CH0_SPARE_MASK) >> RXTXBB2_CH0_SPARE_LSB)
#define RXTXBB2_CH0_SPARE_SET(x)                                     (((0 | (x)) << RXTXBB2_CH0_SPARE_LSB) & RXTXBB2_CH0_SPARE_MASK)
#define RXTXBB2_CH0_SPARE_RESET                                      0
#define RXTXBB2_CH0_SHORTBUFFER_MSB                                  20
#define RXTXBB2_CH0_SHORTBUFFER_LSB                                  20
#define RXTXBB2_CH0_SHORTBUFFER_MASK                                 0x00100000
#define RXTXBB2_CH0_SHORTBUFFER_GET(x)                               (((x) & RXTXBB2_CH0_SHORTBUFFER_MASK) >> RXTXBB2_CH0_SHORTBUFFER_LSB)
#define RXTXBB2_CH0_SHORTBUFFER_SET(x)                               (((0 | (x)) << RXTXBB2_CH0_SHORTBUFFER_LSB) & RXTXBB2_CH0_SHORTBUFFER_MASK)
#define RXTXBB2_CH0_SHORTBUFFER_RESET                                0
#define RXTXBB2_CH0_SELBUFFER_MSB                                    19
#define RXTXBB2_CH0_SELBUFFER_LSB                                    19
#define RXTXBB2_CH0_SELBUFFER_MASK                                   0x00080000
#define RXTXBB2_CH0_SELBUFFER_GET(x)                                 (((x) & RXTXBB2_CH0_SELBUFFER_MASK) >> RXTXBB2_CH0_SELBUFFER_LSB)
#define RXTXBB2_CH0_SELBUFFER_SET(x)                                 (((0 | (x)) << RXTXBB2_CH0_SELBUFFER_LSB) & RXTXBB2_CH0_SELBUFFER_MASK)
#define RXTXBB2_CH0_SELBUFFER_RESET                                  0
#define RXTXBB2_CH0_SEL_DAC_TEST_MSB                                 18
#define RXTXBB2_CH0_SEL_DAC_TEST_LSB                                 18
#define RXTXBB2_CH0_SEL_DAC_TEST_MASK                                0x00040000
#define RXTXBB2_CH0_SEL_DAC_TEST_GET(x)                              (((x) & RXTXBB2_CH0_SEL_DAC_TEST_MASK) >> RXTXBB2_CH0_SEL_DAC_TEST_LSB)
#define RXTXBB2_CH0_SEL_DAC_TEST_SET(x)                              (((0 | (x)) << RXTXBB2_CH0_SEL_DAC_TEST_LSB) & RXTXBB2_CH0_SEL_DAC_TEST_MASK)
#define RXTXBB2_CH0_SEL_DAC_TEST_RESET                               0
#define RXTXBB2_CH0_SEL_LOQ_TEST_MSB                                 17
#define RXTXBB2_CH0_SEL_LOQ_TEST_LSB                                 17
#define RXTXBB2_CH0_SEL_LOQ_TEST_MASK                                0x00020000
#define RXTXBB2_CH0_SEL_LOQ_TEST_GET(x)                              (((x) & RXTXBB2_CH0_SEL_LOQ_TEST_MASK) >> RXTXBB2_CH0_SEL_LOQ_TEST_LSB)
#define RXTXBB2_CH0_SEL_LOQ_TEST_SET(x)                              (((0 | (x)) << RXTXBB2_CH0_SEL_LOQ_TEST_LSB) & RXTXBB2_CH0_SEL_LOQ_TEST_MASK)
#define RXTXBB2_CH0_SEL_LOQ_TEST_RESET                               0
#define RXTXBB2_CH0_SEL_HIQ_TEST_MSB                                 16
#define RXTXBB2_CH0_SEL_HIQ_TEST_LSB                                 16
#define RXTXBB2_CH0_SEL_HIQ_TEST_MASK                                0x00010000
#define RXTXBB2_CH0_SEL_HIQ_TEST_GET(x)                              (((x) & RXTXBB2_CH0_SEL_HIQ_TEST_MASK) >> RXTXBB2_CH0_SEL_HIQ_TEST_LSB)
#define RXTXBB2_CH0_SEL_HIQ_TEST_SET(x)                              (((0 | (x)) << RXTXBB2_CH0_SEL_HIQ_TEST_LSB) & RXTXBB2_CH0_SEL_HIQ_TEST_MASK)
#define RXTXBB2_CH0_SEL_HIQ_TEST_RESET                               0
#define RXTXBB2_CH0_SEL_I2V_TEST_MSB                                 15
#define RXTXBB2_CH0_SEL_I2V_TEST_LSB                                 15
#define RXTXBB2_CH0_SEL_I2V_TEST_MASK                                0x00008000
#define RXTXBB2_CH0_SEL_I2V_TEST_GET(x)                              (((x) & RXTXBB2_CH0_SEL_I2V_TEST_MASK) >> RXTXBB2_CH0_SEL_I2V_TEST_LSB)
#define RXTXBB2_CH0_SEL_I2V_TEST_SET(x)                              (((0 | (x)) << RXTXBB2_CH0_SEL_I2V_TEST_LSB) & RXTXBB2_CH0_SEL_I2V_TEST_MASK)
#define RXTXBB2_CH0_SEL_I2V_TEST_RESET                               0
#define RXTXBB2_CH0_CMSEL_MSB                                        14
#define RXTXBB2_CH0_CMSEL_LSB                                        13
#define RXTXBB2_CH0_CMSEL_MASK                                       0x00006000
#define RXTXBB2_CH0_CMSEL_GET(x)                                     (((x) & RXTXBB2_CH0_CMSEL_MASK) >> RXTXBB2_CH0_CMSEL_LSB)
#define RXTXBB2_CH0_CMSEL_SET(x)                                     (((0 | (x)) << RXTXBB2_CH0_CMSEL_LSB) & RXTXBB2_CH0_CMSEL_MASK)
#define RXTXBB2_CH0_CMSEL_RESET                                      1
#define RXTXBB2_CH0_FILTERFC_MSB                                     12
#define RXTXBB2_CH0_FILTERFC_LSB                                     8
#define RXTXBB2_CH0_FILTERFC_MASK                                    0x00001f00
#define RXTXBB2_CH0_FILTERFC_GET(x)                                  (((x) & RXTXBB2_CH0_FILTERFC_MASK) >> RXTXBB2_CH0_FILTERFC_LSB)
#define RXTXBB2_CH0_FILTERFC_SET(x)                                  (((0 | (x)) << RXTXBB2_CH0_FILTERFC_LSB) & RXTXBB2_CH0_FILTERFC_MASK)
#define RXTXBB2_CH0_FILTERFC_RESET                                   16
#define RXTXBB2_CH0_LOCALFILTERTUNING_MSB                            7
#define RXTXBB2_CH0_LOCALFILTERTUNING_LSB                            7
#define RXTXBB2_CH0_LOCALFILTERTUNING_MASK                           0x00000080
#define RXTXBB2_CH0_LOCALFILTERTUNING_GET(x)                         (((x) & RXTXBB2_CH0_LOCALFILTERTUNING_MASK) >> RXTXBB2_CH0_LOCALFILTERTUNING_LSB)
#define RXTXBB2_CH0_LOCALFILTERTUNING_SET(x)                         (((0 | (x)) << RXTXBB2_CH0_LOCALFILTERTUNING_LSB) & RXTXBB2_CH0_LOCALFILTERTUNING_MASK)
#define RXTXBB2_CH0_LOCALFILTERTUNING_RESET                          0
#define RXTXBB2_CH0_FILTERDOUBLEBW_MSB                               6
#define RXTXBB2_CH0_FILTERDOUBLEBW_LSB                               6
#define RXTXBB2_CH0_FILTERDOUBLEBW_MASK                              0x00000040
#define RXTXBB2_CH0_FILTERDOUBLEBW_GET(x)                            (((x) & RXTXBB2_CH0_FILTERDOUBLEBW_MASK) >> RXTXBB2_CH0_FILTERDOUBLEBW_LSB)
#define RXTXBB2_CH0_FILTERDOUBLEBW_SET(x)                            (((0 | (x)) << RXTXBB2_CH0_FILTERDOUBLEBW_LSB) & RXTXBB2_CH0_FILTERDOUBLEBW_MASK)
#define RXTXBB2_CH0_FILTERDOUBLEBW_RESET                             0
#define RXTXBB2_CH0_PATH2HIQ_EN_MSB                                  5
#define RXTXBB2_CH0_PATH2HIQ_EN_LSB                                  5
#define RXTXBB2_CH0_PATH2HIQ_EN_MASK                                 0x00000020
#define RXTXBB2_CH0_PATH2HIQ_EN_GET(x)                               (((x) & RXTXBB2_CH0_PATH2HIQ_EN_MASK) >> RXTXBB2_CH0_PATH2HIQ_EN_LSB)
#define RXTXBB2_CH0_PATH2HIQ_EN_SET(x)                               (((0 | (x)) << RXTXBB2_CH0_PATH2HIQ_EN_LSB) & RXTXBB2_CH0_PATH2HIQ_EN_MASK)
#define RXTXBB2_CH0_PATH2HIQ_EN_RESET                                0
#define RXTXBB2_CH0_PATH1HIQ_EN_MSB                                  4
#define RXTXBB2_CH0_PATH1HIQ_EN_LSB                                  4
#define RXTXBB2_CH0_PATH1HIQ_EN_MASK                                 0x00000010
#define RXTXBB2_CH0_PATH1HIQ_EN_GET(x)                               (((x) & RXTXBB2_CH0_PATH1HIQ_EN_MASK) >> RXTXBB2_CH0_PATH1HIQ_EN_LSB)
#define RXTXBB2_CH0_PATH1HIQ_EN_SET(x)                               (((0 | (x)) << RXTXBB2_CH0_PATH1HIQ_EN_LSB) & RXTXBB2_CH0_PATH1HIQ_EN_MASK)
#define RXTXBB2_CH0_PATH1HIQ_EN_RESET                                1
#define RXTXBB2_CH0_PATH3LOQ_EN_MSB                                  3
#define RXTXBB2_CH0_PATH3LOQ_EN_LSB                                  3
#define RXTXBB2_CH0_PATH3LOQ_EN_MASK                                 0x00000008
#define RXTXBB2_CH0_PATH3LOQ_EN_GET(x)                               (((x) & RXTXBB2_CH0_PATH3LOQ_EN_MASK) >> RXTXBB2_CH0_PATH3LOQ_EN_LSB)
#define RXTXBB2_CH0_PATH3LOQ_EN_SET(x)                               (((0 | (x)) << RXTXBB2_CH0_PATH3LOQ_EN_LSB) & RXTXBB2_CH0_PATH3LOQ_EN_MASK)
#define RXTXBB2_CH0_PATH3LOQ_EN_RESET                                0
#define RXTXBB2_CH0_PATH2LOQ_EN_MSB                                  2
#define RXTXBB2_CH0_PATH2LOQ_EN_LSB                                  2
#define RXTXBB2_CH0_PATH2LOQ_EN_MASK                                 0x00000004
#define RXTXBB2_CH0_PATH2LOQ_EN_GET(x)                               (((x) & RXTXBB2_CH0_PATH2LOQ_EN_MASK) >> RXTXBB2_CH0_PATH2LOQ_EN_LSB)
#define RXTXBB2_CH0_PATH2LOQ_EN_SET(x)                               (((0 | (x)) << RXTXBB2_CH0_PATH2LOQ_EN_LSB) & RXTXBB2_CH0_PATH2LOQ_EN_MASK)
#define RXTXBB2_CH0_PATH2LOQ_EN_RESET                                0
#define RXTXBB2_CH0_PATH1LOQ_EN_MSB                                  1
#define RXTXBB2_CH0_PATH1LOQ_EN_LSB                                  1
#define RXTXBB2_CH0_PATH1LOQ_EN_MASK                                 0x00000002
#define RXTXBB2_CH0_PATH1LOQ_EN_GET(x)                               (((x) & RXTXBB2_CH0_PATH1LOQ_EN_MASK) >> RXTXBB2_CH0_PATH1LOQ_EN_LSB)
#define RXTXBB2_CH0_PATH1LOQ_EN_SET(x)                               (((0 | (x)) << RXTXBB2_CH0_PATH1LOQ_EN_LSB) & RXTXBB2_CH0_PATH1LOQ_EN_MASK)
#define RXTXBB2_CH0_PATH1LOQ_EN_RESET                                1
#define RXTXBB2_CH0_PATH_OVERRIDE_MSB                                0
#define RXTXBB2_CH0_PATH_OVERRIDE_LSB                                0
#define RXTXBB2_CH0_PATH_OVERRIDE_MASK                               0x00000001
#define RXTXBB2_CH0_PATH_OVERRIDE_GET(x)                             (((x) & RXTXBB2_CH0_PATH_OVERRIDE_MASK) >> RXTXBB2_CH0_PATH_OVERRIDE_LSB)
#define RXTXBB2_CH0_PATH_OVERRIDE_SET(x)                             (((0 | (x)) << RXTXBB2_CH0_PATH_OVERRIDE_LSB) & RXTXBB2_CH0_PATH_OVERRIDE_MASK)
#define RXTXBB2_CH0_PATH_OVERRIDE_RESET                              0
#define RXTXBB2_CH0_ADDRESS                                          0x0028
#define RXTXBB2_CH0_HW_MASK                                          0xffffffff
#define RXTXBB2_CH0_SW_MASK                                          0xffffffff
#define RXTXBB2_CH0_HW_WRITE_MASK                                    0x00001f00
#define RXTXBB2_CH0_SW_WRITE_MASK                                    0xffffffff
#define RXTXBB2_CH0_RSTMASK                                          0xffffffff
#define RXTXBB2_CH0_RESET                                            0xdb003012

// 0x002c (RXTXBB3_CH0)
#define RXTXBB3_CH0_SPARE_MSB                                        31
#define RXTXBB3_CH0_SPARE_LSB                                        27
#define RXTXBB3_CH0_SPARE_MASK                                       0xf8000000
#define RXTXBB3_CH0_SPARE_GET(x)                                     (((x) & RXTXBB3_CH0_SPARE_MASK) >> RXTXBB3_CH0_SPARE_LSB)
#define RXTXBB3_CH0_SPARE_SET(x)                                     (((0 | (x)) << RXTXBB3_CH0_SPARE_LSB) & RXTXBB3_CH0_SPARE_MASK)
#define RXTXBB3_CH0_SPARE_RESET                                      0
#define RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_MSB                       26
#define RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_LSB                       24
#define RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_MASK                      0x07000000
#define RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_GET(x)                    (((x) & RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_MASK) >> RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_LSB)
#define RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_SET(x)                    (((0 | (x)) << RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_LSB) & RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_MASK)
#define RXTXBB3_CH0_IBN_25U_CM_BUFAMP_CTRL_RESET                     4
#define RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_MSB                           23
#define RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_LSB                           21
#define RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_MASK                          0x00e00000
#define RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_GET(x)                        (((x) & RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_MASK) >> RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_LSB)
#define RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_SET(x)                        (((0 | (x)) << RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_LSB) & RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_MASK)
#define RXTXBB3_CH0_IBN_25U_BKV2I_CTRL_RESET                         4
#define RXTXBB3_CH0_IBN_25U_I2V_CTRL_MSB                             20
#define RXTXBB3_CH0_IBN_25U_I2V_CTRL_LSB                             18
#define RXTXBB3_CH0_IBN_25U_I2V_CTRL_MASK                            0x001c0000
#define RXTXBB3_CH0_IBN_25U_I2V_CTRL_GET(x)                          (((x) & RXTXBB3_CH0_IBN_25U_I2V_CTRL_MASK) >> RXTXBB3_CH0_IBN_25U_I2V_CTRL_LSB)
#define RXTXBB3_CH0_IBN_25U_I2V_CTRL_SET(x)                          (((0 | (x)) << RXTXBB3_CH0_IBN_25U_I2V_CTRL_LSB) & RXTXBB3_CH0_IBN_25U_I2V_CTRL_MASK)
#define RXTXBB3_CH0_IBN_25U_I2V_CTRL_RESET                           4
#define RXTXBB3_CH0_IBN_25U_HI1_CTRL_MSB                             17
#define RXTXBB3_CH0_IBN_25U_HI1_CTRL_LSB                             15
#define RXTXBB3_CH0_IBN_25U_HI1_CTRL_MASK                            0x00038000
#define RXTXBB3_CH0_IBN_25U_HI1_CTRL_GET(x)                          (((x) & RXTXBB3_CH0_IBN_25U_HI1_CTRL_MASK) >> RXTXBB3_CH0_IBN_25U_HI1_CTRL_LSB)
#define RXTXBB3_CH0_IBN_25U_HI1_CTRL_SET(x)                          (((0 | (x)) << RXTXBB3_CH0_IBN_25U_HI1_CTRL_LSB) & RXTXBB3_CH0_IBN_25U_HI1_CTRL_MASK)
#define RXTXBB3_CH0_IBN_25U_HI1_CTRL_RESET                           4
#define RXTXBB3_CH0_IBN_25U_HI2_CTRL_MSB                             14
#define RXTXBB3_CH0_IBN_25U_HI2_CTRL_LSB                             12
#define RXTXBB3_CH0_IBN_25U_HI2_CTRL_MASK                            0x00007000
#define RXTXBB3_CH0_IBN_25U_HI2_CTRL_GET(x)                          (((x) & RXTXBB3_CH0_IBN_25U_HI2_CTRL_MASK) >> RXTXBB3_CH0_IBN_25U_HI2_CTRL_LSB)
#define RXTXBB3_CH0_IBN_25U_HI2_CTRL_SET(x)                          (((0 | (x)) << RXTXBB3_CH0_IBN_25U_HI2_CTRL_LSB) & RXTXBB3_CH0_IBN_25U_HI2_CTRL_MASK)
#define RXTXBB3_CH0_IBN_25U_HI2_CTRL_RESET                           4
#define RXTXBB3_CH0_IBN_25U_LO1_CTRL_MSB                             11
#define RXTXBB3_CH0_IBN_25U_LO1_CTRL_LSB                             9
#define RXTXBB3_CH0_IBN_25U_LO1_CTRL_MASK                            0x00000e00
#define RXTXBB3_CH0_IBN_25U_LO1_CTRL_GET(x)                          (((x) & RXTXBB3_CH0_IBN_25U_LO1_CTRL_MASK) >> RXTXBB3_CH0_IBN_25U_LO1_CTRL_LSB)
#define RXTXBB3_CH0_IBN_25U_LO1_CTRL_SET(x)                          (((0 | (x)) << RXTXBB3_CH0_IBN_25U_LO1_CTRL_LSB) & RXTXBB3_CH0_IBN_25U_LO1_CTRL_MASK)
#define RXTXBB3_CH0_IBN_25U_LO1_CTRL_RESET                           4
#define RXTXBB3_CH0_IBN_25U_LO2_CTRL_MSB                             8
#define RXTXBB3_CH0_IBN_25U_LO2_CTRL_LSB                             6
#define RXTXBB3_CH0_IBN_25U_LO2_CTRL_MASK                            0x000001c0
#define RXTXBB3_CH0_IBN_25U_LO2_CTRL_GET(x)                          (((x) & RXTXBB3_CH0_IBN_25U_LO2_CTRL_MASK) >> RXTXBB3_CH0_IBN_25U_LO2_CTRL_LSB)
#define RXTXBB3_CH0_IBN_25U_LO2_CTRL_SET(x)                          (((0 | (x)) << RXTXBB3_CH0_IBN_25U_LO2_CTRL_LSB) & RXTXBB3_CH0_IBN_25U_LO2_CTRL_MASK)
#define RXTXBB3_CH0_IBN_25U_LO2_CTRL_RESET                           4
#define RXTXBB3_CH0_IBRN_12P5_CM_CTRL_MSB                            5
#define RXTXBB3_CH0_IBRN_12P5_CM_CTRL_LSB                            3
#define RXTXBB3_CH0_IBRN_12P5_CM_CTRL_MASK                           0x00000038
#define RXTXBB3_CH0_IBRN_12P5_CM_CTRL_GET(x)                         (((x) & RXTXBB3_CH0_IBRN_12P5_CM_CTRL_MASK) >> RXTXBB3_CH0_IBRN_12P5_CM_CTRL_LSB)
#define RXTXBB3_CH0_IBRN_12P5_CM_CTRL_SET(x)                         (((0 | (x)) << RXTXBB3_CH0_IBRN_12P5_CM_CTRL_LSB) & RXTXBB3_CH0_IBRN_12P5_CM_CTRL_MASK)
#define RXTXBB3_CH0_IBRN_12P5_CM_CTRL_RESET                          2
#define RXTXBB3_CH0_IBN_100U_TEST_CTRL_MSB                           2
#define RXTXBB3_CH0_IBN_100U_TEST_CTRL_LSB                           0
#define RXTXBB3_CH0_IBN_100U_TEST_CTRL_MASK                          0x00000007
#define RXTXBB3_CH0_IBN_100U_TEST_CTRL_GET(x)                        (((x) & RXTXBB3_CH0_IBN_100U_TEST_CTRL_MASK) >> RXTXBB3_CH0_IBN_100U_TEST_CTRL_LSB)
#define RXTXBB3_CH0_IBN_100U_TEST_CTRL_SET(x)                        (((0 | (x)) << RXTXBB3_CH0_IBN_100U_TEST_CTRL_LSB) & RXTXBB3_CH0_IBN_100U_TEST_CTRL_MASK)
#define RXTXBB3_CH0_IBN_100U_TEST_CTRL_RESET                         4
#define RXTXBB3_CH0_ADDRESS                                          0x002c
#define RXTXBB3_CH0_HW_MASK                                          0xffffffff
#define RXTXBB3_CH0_SW_MASK                                          0xffffffff
#define RXTXBB3_CH0_HW_WRITE_MASK                                    0x00000000
#define RXTXBB3_CH0_SW_WRITE_MASK                                    0xffffffff
#define RXTXBB3_CH0_RSTMASK                                          0xffffffff
#define RXTXBB3_CH0_RESET                                            0x04924914

// 0x0030 (RXTXBB4_CH0)
#define RXTXBB4_CH0_SPARE_MSB                                        31
#define RXTXBB4_CH0_SPARE_LSB                                        31
#define RXTXBB4_CH0_SPARE_MASK                                       0x80000000
#define RXTXBB4_CH0_SPARE_GET(x)                                     (((x) & RXTXBB4_CH0_SPARE_MASK) >> RXTXBB4_CH0_SPARE_LSB)
#define RXTXBB4_CH0_SPARE_SET(x)                                     (((0 | (x)) << RXTXBB4_CH0_SPARE_LSB) & RXTXBB4_CH0_SPARE_MASK)
#define RXTXBB4_CH0_SPARE_RESET                                      0
#define RXTXBB4_CH0_LOCALOFFSET_MSB                                  30
#define RXTXBB4_CH0_LOCALOFFSET_LSB                                  30
#define RXTXBB4_CH0_LOCALOFFSET_MASK                                 0x40000000
#define RXTXBB4_CH0_LOCALOFFSET_GET(x)                               (((x) & RXTXBB4_CH0_LOCALOFFSET_MASK) >> RXTXBB4_CH0_LOCALOFFSET_LSB)
#define RXTXBB4_CH0_LOCALOFFSET_SET(x)                               (((0 | (x)) << RXTXBB4_CH0_LOCALOFFSET_LSB) & RXTXBB4_CH0_LOCALOFFSET_MASK)
#define RXTXBB4_CH0_LOCALOFFSET_RESET                                0
#define RXTXBB4_CH0_OFSTCORRHII_MSB                                  29
#define RXTXBB4_CH0_OFSTCORRHII_LSB                                  25
#define RXTXBB4_CH0_OFSTCORRHII_MASK                                 0x3e000000
#define RXTXBB4_CH0_OFSTCORRHII_GET(x)                               (((x) & RXTXBB4_CH0_OFSTCORRHII_MASK) >> RXTXBB4_CH0_OFSTCORRHII_LSB)
#define RXTXBB4_CH0_OFSTCORRHII_SET(x)                               (((0 | (x)) << RXTXBB4_CH0_OFSTCORRHII_LSB) & RXTXBB4_CH0_OFSTCORRHII_MASK)
#define RXTXBB4_CH0_OFSTCORRHII_RESET                                16
#define RXTXBB4_CH0_OFSTCORRHIQ_MSB                                  24
#define RXTXBB4_CH0_OFSTCORRHIQ_LSB                                  20
#define RXTXBB4_CH0_OFSTCORRHIQ_MASK                                 0x01f00000
#define RXTXBB4_CH0_OFSTCORRHIQ_GET(x)                               (((x) & RXTXBB4_CH0_OFSTCORRHIQ_MASK) >> RXTXBB4_CH0_OFSTCORRHIQ_LSB)
#define RXTXBB4_CH0_OFSTCORRHIQ_SET(x)                               (((0 | (x)) << RXTXBB4_CH0_OFSTCORRHIQ_LSB) & RXTXBB4_CH0_OFSTCORRHIQ_MASK)
#define RXTXBB4_CH0_OFSTCORRHIQ_RESET                                16
#define RXTXBB4_CH0_OFSTCORRLOI_MSB                                  19
#define RXTXBB4_CH0_OFSTCORRLOI_LSB                                  15
#define RXTXBB4_CH0_OFSTCORRLOI_MASK                                 0x000f8000
#define RXTXBB4_CH0_OFSTCORRLOI_GET(x)                               (((x) & RXTXBB4_CH0_OFSTCORRLOI_MASK) >> RXTXBB4_CH0_OFSTCORRLOI_LSB)
#define RXTXBB4_CH0_OFSTCORRLOI_SET(x)                               (((0 | (x)) << RXTXBB4_CH0_OFSTCORRLOI_LSB) & RXTXBB4_CH0_OFSTCORRLOI_MASK)
#define RXTXBB4_CH0_OFSTCORRLOI_RESET                                16
#define RXTXBB4_CH0_OFSTCORRLOQ_MSB                                  14
#define RXTXBB4_CH0_OFSTCORRLOQ_LSB                                  10
#define RXTXBB4_CH0_OFSTCORRLOQ_MASK                                 0x00007c00
#define RXTXBB4_CH0_OFSTCORRLOQ_GET(x)                               (((x) & RXTXBB4_CH0_OFSTCORRLOQ_MASK) >> RXTXBB4_CH0_OFSTCORRLOQ_LSB)
#define RXTXBB4_CH0_OFSTCORRLOQ_SET(x)                               (((0 | (x)) << RXTXBB4_CH0_OFSTCORRLOQ_LSB) & RXTXBB4_CH0_OFSTCORRLOQ_MASK)
#define RXTXBB4_CH0_OFSTCORRLOQ_RESET                                16
#define RXTXBB4_CH0_OFSTCORRI2VI_MSB                                 9
#define RXTXBB4_CH0_OFSTCORRI2VI_LSB                                 5
#define RXTXBB4_CH0_OFSTCORRI2VI_MASK                                0x000003e0
#define RXTXBB4_CH0_OFSTCORRI2VI_GET(x)                              (((x) & RXTXBB4_CH0_OFSTCORRI2VI_MASK) >> RXTXBB4_CH0_OFSTCORRI2VI_LSB)
#define RXTXBB4_CH0_OFSTCORRI2VI_SET(x)                              (((0 | (x)) << RXTXBB4_CH0_OFSTCORRI2VI_LSB) & RXTXBB4_CH0_OFSTCORRI2VI_MASK)
#define RXTXBB4_CH0_OFSTCORRI2VI_RESET                               16
#define RXTXBB4_CH0_OFSTCORRI2VQ_MSB                                 4
#define RXTXBB4_CH0_OFSTCORRI2VQ_LSB                                 0
#define RXTXBB4_CH0_OFSTCORRI2VQ_MASK                                0x0000001f
#define RXTXBB4_CH0_OFSTCORRI2VQ_GET(x)                              (((x) & RXTXBB4_CH0_OFSTCORRI2VQ_MASK) >> RXTXBB4_CH0_OFSTCORRI2VQ_LSB)
#define RXTXBB4_CH0_OFSTCORRI2VQ_SET(x)                              (((0 | (x)) << RXTXBB4_CH0_OFSTCORRI2VQ_LSB) & RXTXBB4_CH0_OFSTCORRI2VQ_MASK)
#define RXTXBB4_CH0_OFSTCORRI2VQ_RESET                               16
#define RXTXBB4_CH0_ADDRESS                                          0x0030
#define RXTXBB4_CH0_HW_MASK                                          0xffffffff
#define RXTXBB4_CH0_SW_MASK                                          0xffffffff
#define RXTXBB4_CH0_HW_WRITE_MASK                                    0x3fffffff
#define RXTXBB4_CH0_SW_WRITE_MASK                                    0xffffffff
#define RXTXBB4_CH0_RSTMASK                                          0xffffffff
#define RXTXBB4_CH0_RESET                                            0x21084210

// 0x0034 (RF5G1_CH0)
#define RF5G1_CH0_PDTXLO5_MSB                                        31
#define RF5G1_CH0_PDTXLO5_LSB                                        31
#define RF5G1_CH0_PDTXLO5_MASK                                       0x80000000
#define RF5G1_CH0_PDTXLO5_GET(x)                                     (((x) & RF5G1_CH0_PDTXLO5_MASK) >> RF5G1_CH0_PDTXLO5_LSB)
#define RF5G1_CH0_PDTXLO5_SET(x)                                     (((0 | (x)) << RF5G1_CH0_PDTXLO5_LSB) & RF5G1_CH0_PDTXLO5_MASK)
#define RF5G1_CH0_PDTXLO5_RESET                                      0
#define RF5G1_CH0_PDTXMIX5_MSB                                       30
#define RF5G1_CH0_PDTXMIX5_LSB                                       30
#define RF5G1_CH0_PDTXMIX5_MASK                                      0x40000000
#define RF5G1_CH0_PDTXMIX5_GET(x)                                    (((x) & RF5G1_CH0_PDTXMIX5_MASK) >> RF5G1_CH0_PDTXMIX5_LSB)
#define RF5G1_CH0_PDTXMIX5_SET(x)                                    (((0 | (x)) << RF5G1_CH0_PDTXMIX5_LSB) & RF5G1_CH0_PDTXMIX5_MASK)
#define RF5G1_CH0_PDTXMIX5_RESET                                     0
#define RF5G1_CH0_PDTXBUF5_MSB                                       29
#define RF5G1_CH0_PDTXBUF5_LSB                                       29
#define RF5G1_CH0_PDTXBUF5_MASK                                      0x20000000
#define RF5G1_CH0_PDTXBUF5_GET(x)                                    (((x) & RF5G1_CH0_PDTXBUF5_MASK) >> RF5G1_CH0_PDTXBUF5_LSB)
#define RF5G1_CH0_PDTXBUF5_SET(x)                                    (((0 | (x)) << RF5G1_CH0_PDTXBUF5_LSB) & RF5G1_CH0_PDTXBUF5_MASK)
#define RF5G1_CH0_PDTXBUF5_RESET                                     0
#define RF5G1_CH0_PDPADRV5_MSB                                       28
#define RF5G1_CH0_PDPADRV5_LSB                                       28
#define RF5G1_CH0_PDPADRV5_MASK                                      0x10000000
#define RF5G1_CH0_PDPADRV5_GET(x)                                    (((x) & RF5G1_CH0_PDPADRV5_MASK) >> RF5G1_CH0_PDPADRV5_LSB)
#define RF5G1_CH0_PDPADRV5_SET(x)                                    (((0 | (x)) << RF5G1_CH0_PDPADRV5_LSB) & RF5G1_CH0_PDPADRV5_MASK)
#define RF5G1_CH0_PDPADRV5_RESET                                     0
#define RF5G1_CH0_PDPAOUT5_MSB                                       27
#define RF5G1_CH0_PDPAOUT5_LSB                                       27
#define RF5G1_CH0_PDPAOUT5_MASK                                      0x08000000
#define RF5G1_CH0_PDPAOUT5_GET(x)                                    (((x) & RF5G1_CH0_PDPAOUT5_MASK) >> RF5G1_CH0_PDPAOUT5_LSB)
#define RF5G1_CH0_PDPAOUT5_SET(x)                                    (((0 | (x)) << RF5G1_CH0_PDPAOUT5_LSB) & RF5G1_CH0_PDPAOUT5_MASK)
#define RF5G1_CH0_PDPAOUT5_RESET                                     0
#define RF5G1_CH0_PACASCBIAS_MSB                                     26
#define RF5G1_CH0_PACASCBIAS_LSB                                     25
#define RF5G1_CH0_PACASCBIAS_MASK                                    0x06000000
#define RF5G1_CH0_PACASCBIAS_GET(x)                                  (((x) & RF5G1_CH0_PACASCBIAS_MASK) >> RF5G1_CH0_PACASCBIAS_LSB)
#define RF5G1_CH0_PACASCBIAS_SET(x)                                  (((0 | (x)) << RF5G1_CH0_PACASCBIAS_LSB) & RF5G1_CH0_PACASCBIAS_MASK)
#define RF5G1_CH0_PACASCBIAS_RESET                                   3
#define RF5G1_CH0_PWDTXPKD_MSB                                       24
#define RF5G1_CH0_PWDTXPKD_LSB                                       22
#define RF5G1_CH0_PWDTXPKD_MASK                                      0x01c00000
#define RF5G1_CH0_PWDTXPKD_GET(x)                                    (((x) & RF5G1_CH0_PWDTXPKD_MASK) >> RF5G1_CH0_PWDTXPKD_LSB)
#define RF5G1_CH0_PWDTXPKD_SET(x)                                    (((0 | (x)) << RF5G1_CH0_PWDTXPKD_LSB) & RF5G1_CH0_PWDTXPKD_MASK)
#define RF5G1_CH0_PWDTXPKD_RESET                                     7
#define RF5G1_CH0_DB5_MSB                                            21
#define RF5G1_CH0_DB5_LSB                                            19
#define RF5G1_CH0_DB5_MASK                                           0x00380000
#define RF5G1_CH0_DB5_GET(x)                                         (((x) & RF5G1_CH0_DB5_MASK) >> RF5G1_CH0_DB5_LSB)
#define RF5G1_CH0_DB5_SET(x)                                         (((0 | (x)) << RF5G1_CH0_DB5_LSB) & RF5G1_CH0_DB5_MASK)
#define RF5G1_CH0_DB5_RESET                                          4
#define RF5G1_CH0_OB5_MSB                                            18
#define RF5G1_CH0_OB5_LSB                                            16
#define RF5G1_CH0_OB5_MASK                                           0x00070000
#define RF5G1_CH0_OB5_GET(x)                                         (((x) & RF5G1_CH0_OB5_MASK) >> RF5G1_CH0_OB5_LSB)
#define RF5G1_CH0_OB5_SET(x)                                         (((0 | (x)) << RF5G1_CH0_OB5_LSB) & RF5G1_CH0_OB5_MASK)
#define RF5G1_CH0_OB5_RESET                                          4
#define RF5G1_CH0_TX5_ATB_SEL_MSB                                    15
#define RF5G1_CH0_TX5_ATB_SEL_LSB                                    13
#define RF5G1_CH0_TX5_ATB_SEL_MASK                                   0x0000e000
#define RF5G1_CH0_TX5_ATB_SEL_GET(x)                                 (((x) & RF5G1_CH0_TX5_ATB_SEL_MASK) >> RF5G1_CH0_TX5_ATB_SEL_LSB)
#define RF5G1_CH0_TX5_ATB_SEL_SET(x)                                 (((0 | (x)) << RF5G1_CH0_TX5_ATB_SEL_LSB) & RF5G1_CH0_TX5_ATB_SEL_MASK)
#define RF5G1_CH0_TX5_ATB_SEL_RESET                                  0
#define RF5G1_CH0_LO5CONTROL_MSB                                     12
#define RF5G1_CH0_LO5CONTROL_LSB                                     12
#define RF5G1_CH0_LO5CONTROL_MASK                                    0x00001000
#define RF5G1_CH0_LO5CONTROL_GET(x)                                  (((x) & RF5G1_CH0_LO5CONTROL_MASK) >> RF5G1_CH0_LO5CONTROL_LSB)
#define RF5G1_CH0_LO5CONTROL_SET(x)                                  (((0 | (x)) << RF5G1_CH0_LO5CONTROL_LSB) & RF5G1_CH0_LO5CONTROL_MASK)
#define RF5G1_CH0_LO5CONTROL_RESET                                   0
#define RF5G1_CH0_REGLO_BYPASS5_MSB                                  11
#define RF5G1_CH0_REGLO_BYPASS5_LSB                                  11
#define RF5G1_CH0_REGLO_BYPASS5_MASK                                 0x00000800
#define RF5G1_CH0_REGLO_BYPASS5_GET(x)                               (((x) & RF5G1_CH0_REGLO_BYPASS5_MASK) >> RF5G1_CH0_REGLO_BYPASS5_LSB)
#define RF5G1_CH0_REGLO_BYPASS5_SET(x)                               (((0 | (x)) << RF5G1_CH0_REGLO_BYPASS5_LSB) & RF5G1_CH0_REGLO_BYPASS5_MASK)
#define RF5G1_CH0_REGLO_BYPASS5_RESET                                0
#define RF5G1_CH0_PDREGLO5_MSB                                       10
#define RF5G1_CH0_PDREGLO5_LSB                                       10
#define RF5G1_CH0_PDREGLO5_MASK                                      0x00000400
#define RF5G1_CH0_PDREGLO5_GET(x)                                    (((x) & RF5G1_CH0_PDREGLO5_MASK) >> RF5G1_CH0_PDREGLO5_LSB)
#define RF5G1_CH0_PDREGLO5_SET(x)                                    (((0 | (x)) << RF5G1_CH0_PDREGLO5_LSB) & RF5G1_CH0_PDREGLO5_MASK)
#define RF5G1_CH0_PDREGLO5_RESET                                     0
#define RF5G1_CH0_SPARE_MSB                                          9
#define RF5G1_CH0_SPARE_LSB                                          0
#define RF5G1_CH0_SPARE_MASK                                         0x000003ff
#define RF5G1_CH0_SPARE_GET(x)                                       (((x) & RF5G1_CH0_SPARE_MASK) >> RF5G1_CH0_SPARE_LSB)
#define RF5G1_CH0_SPARE_SET(x)                                       (((0 | (x)) << RF5G1_CH0_SPARE_LSB) & RF5G1_CH0_SPARE_MASK)
#define RF5G1_CH0_SPARE_RESET                                        0
#define RF5G1_CH0_ADDRESS                                            0x0034
#define RF5G1_CH0_HW_MASK                                            0xffffffff
#define RF5G1_CH0_SW_MASK                                            0xffffffff
#define RF5G1_CH0_HW_WRITE_MASK                                      0x00000000
#define RF5G1_CH0_SW_WRITE_MASK                                      0xffffffff
#define RF5G1_CH0_RSTMASK                                            0xffffffff
#define RF5G1_CH0_RESET                                              0x07e40000

// 0x0038 (RF5G2_CH0)
#define RF5G2_CH0_REGFE_BYPASS5_MSB                                  31
#define RF5G2_CH0_REGFE_BYPASS5_LSB                                  31
#define RF5G2_CH0_REGFE_BYPASS5_MASK                                 0x80000000
#define RF5G2_CH0_REGFE_BYPASS5_GET(x)                               (((x) & RF5G2_CH0_REGFE_BYPASS5_MASK) >> RF5G2_CH0_REGFE_BYPASS5_LSB)
#define RF5G2_CH0_REGFE_BYPASS5_SET(x)                               (((0 | (x)) << RF5G2_CH0_REGFE_BYPASS5_LSB) & RF5G2_CH0_REGFE_BYPASS5_MASK)
#define RF5G2_CH0_REGFE_BYPASS5_RESET                                0
#define RF5G2_CH0_PDREGFE5_MSB                                       30
#define RF5G2_CH0_PDREGFE5_LSB                                       30
#define RF5G2_CH0_PDREGFE5_MASK                                      0x40000000
#define RF5G2_CH0_PDREGFE5_GET(x)                                    (((x) & RF5G2_CH0_PDREGFE5_MASK) >> RF5G2_CH0_PDREGFE5_LSB)
#define RF5G2_CH0_PDREGFE5_SET(x)                                    (((0 | (x)) << RF5G2_CH0_PDREGFE5_LSB) & RF5G2_CH0_PDREGFE5_MASK)
#define RF5G2_CH0_PDREGFE5_RESET                                     0
#define RF5G2_CH0_PDRXLO5_MSB                                        29
#define RF5G2_CH0_PDRXLO5_LSB                                        29
#define RF5G2_CH0_PDRXLO5_MASK                                       0x20000000
#define RF5G2_CH0_PDRXLO5_GET(x)                                     (((x) & RF5G2_CH0_PDRXLO5_MASK) >> RF5G2_CH0_PDRXLO5_LSB)
#define RF5G2_CH0_PDRXLO5_SET(x)                                     (((0 | (x)) << RF5G2_CH0_PDRXLO5_LSB) & RF5G2_CH0_PDRXLO5_MASK)
#define RF5G2_CH0_PDRXLO5_RESET                                      0
#define RF5G2_CH0_PDVGM5_MSB                                         28
#define RF5G2_CH0_PDVGM5_LSB                                         28
#define RF5G2_CH0_PDVGM5_MASK                                        0x10000000
#define RF5G2_CH0_PDVGM5_GET(x)                                      (((x) & RF5G2_CH0_PDVGM5_MASK) >> RF5G2_CH0_PDVGM5_LSB)
#define RF5G2_CH0_PDVGM5_SET(x)                                      (((0 | (x)) << RF5G2_CH0_PDVGM5_LSB) & RF5G2_CH0_PDVGM5_MASK)
#define RF5G2_CH0_PDVGM5_RESET                                       0
#define RF5G2_CH0_PDCSLNA5_MSB                                       27
#define RF5G2_CH0_PDCSLNA5_LSB                                       27
#define RF5G2_CH0_PDCSLNA5_MASK                                      0x08000000
#define RF5G2_CH0_PDCSLNA5_GET(x)                                    (((x) & RF5G2_CH0_PDCSLNA5_MASK) >> RF5G2_CH0_PDCSLNA5_LSB)
#define RF5G2_CH0_PDCSLNA5_SET(x)                                    (((0 | (x)) << RF5G2_CH0_PDCSLNA5_LSB) & RF5G2_CH0_PDCSLNA5_MASK)
#define RF5G2_CH0_PDCSLNA5_RESET                                     0
#define RF5G2_CH0_PDRFVGA5_MSB                                       26
#define RF5G2_CH0_PDRFVGA5_LSB                                       26
#define RF5G2_CH0_PDRFVGA5_MASK                                      0x04000000
#define RF5G2_CH0_PDRFVGA5_GET(x)                                    (((x) & RF5G2_CH0_PDRFVGA5_MASK) >> RF5G2_CH0_PDRFVGA5_LSB)
#define RF5G2_CH0_PDRFVGA5_SET(x)                                    (((0 | (x)) << RF5G2_CH0_PDRFVGA5_LSB) & RF5G2_CH0_PDRFVGA5_MASK)
#define RF5G2_CH0_PDRFVGA5_RESET                                     0
#define RF5G2_CH0_RX5_ATB_SEL_MSB                                    25
#define RF5G2_CH0_RX5_ATB_SEL_LSB                                    23
#define RF5G2_CH0_RX5_ATB_SEL_MASK                                   0x03800000
#define RF5G2_CH0_RX5_ATB_SEL_GET(x)                                 (((x) & RF5G2_CH0_RX5_ATB_SEL_MASK) >> RF5G2_CH0_RX5_ATB_SEL_LSB)
#define RF5G2_CH0_RX5_ATB_SEL_SET(x)                                 (((0 | (x)) << RF5G2_CH0_RX5_ATB_SEL_LSB) & RF5G2_CH0_RX5_ATB_SEL_MASK)
#define RF5G2_CH0_RX5_ATB_SEL_RESET                                  0
#define RF5G2_CH0_PDBIRTXMIX_MSB                                     22
#define RF5G2_CH0_PDBIRTXMIX_LSB                                     20
#define RF5G2_CH0_PDBIRTXMIX_MASK                                    0x00700000
#define RF5G2_CH0_PDBIRTXMIX_GET(x)                                  (((x) & RF5G2_CH0_PDBIRTXMIX_MASK) >> RF5G2_CH0_PDBIRTXMIX_LSB)
#define RF5G2_CH0_PDBIRTXMIX_SET(x)                                  (((0 | (x)) << RF5G2_CH0_PDBIRTXMIX_LSB) & RF5G2_CH0_PDBIRTXMIX_MASK)
#define RF5G2_CH0_PDBIRTXMIX_RESET                                   4
#define RF5G2_CH0_PDBIRTXPA_MSB                                      19
#define RF5G2_CH0_PDBIRTXPA_LSB                                      17
#define RF5G2_CH0_PDBIRTXPA_MASK                                     0x000e0000
#define RF5G2_CH0_PDBIRTXPA_GET(x)                                   (((x) & RF5G2_CH0_PDBIRTXPA_MASK) >> RF5G2_CH0_PDBIRTXPA_LSB)
#define RF5G2_CH0_PDBIRTXPA_SET(x)                                   (((0 | (x)) << RF5G2_CH0_PDBIRTXPA_LSB) & RF5G2_CH0_PDBIRTXPA_MASK)
#define RF5G2_CH0_PDBIRTXPA_RESET                                    4
#define RF5G2_CH0_PDBIR1_MSB                                         16
#define RF5G2_CH0_PDBIR1_LSB                                         14
#define RF5G2_CH0_PDBIR1_MASK                                        0x0001c000
#define RF5G2_CH0_PDBIR1_GET(x)                                      (((x) & RF5G2_CH0_PDBIR1_MASK) >> RF5G2_CH0_PDBIR1_LSB)
#define RF5G2_CH0_PDBIR1_SET(x)                                      (((0 | (x)) << RF5G2_CH0_PDBIR1_LSB) & RF5G2_CH0_PDBIR1_MASK)
#define RF5G2_CH0_PDBIR1_RESET                                       4
#define RF5G2_CH0_PDBIR2_MSB                                         13
#define RF5G2_CH0_PDBIR2_LSB                                         11
#define RF5G2_CH0_PDBIR2_MASK                                        0x00003800
#define RF5G2_CH0_PDBIR2_GET(x)                                      (((x) & RF5G2_CH0_PDBIR2_MASK) >> RF5G2_CH0_PDBIR2_LSB)
#define RF5G2_CH0_PDBIR2_SET(x)                                      (((0 | (x)) << RF5G2_CH0_PDBIR2_LSB) & RF5G2_CH0_PDBIR2_MASK)
#define RF5G2_CH0_PDBIR2_RESET                                       4
#define RF5G2_CH0_SPARE_MSB                                          10
#define RF5G2_CH0_SPARE_LSB                                          0
#define RF5G2_CH0_SPARE_MASK                                         0x000007ff
#define RF5G2_CH0_SPARE_GET(x)                                       (((x) & RF5G2_CH0_SPARE_MASK) >> RF5G2_CH0_SPARE_LSB)
#define RF5G2_CH0_SPARE_SET(x)                                       (((0 | (x)) << RF5G2_CH0_SPARE_LSB) & RF5G2_CH0_SPARE_MASK)
#define RF5G2_CH0_SPARE_RESET                                        0
#define RF5G2_CH0_ADDRESS                                            0x0038
#define RF5G2_CH0_HW_MASK                                            0xffffffff
#define RF5G2_CH0_SW_MASK                                            0xffffffff
#define RF5G2_CH0_HW_WRITE_MASK                                      0x00000000
#define RF5G2_CH0_SW_WRITE_MASK                                      0xffffffff
#define RF5G2_CH0_RSTMASK                                            0xffffffff
#define RF5G2_CH0_RESET                                              0x00492000

// 0x003c (RF5G3_CH0)
#define RF5G3_CH0_PDBICTXBUF_MSB                                     31
#define RF5G3_CH0_PDBICTXBUF_LSB                                     29
#define RF5G3_CH0_PDBICTXBUF_MASK                                    0xe0000000
#define RF5G3_CH0_PDBICTXBUF_GET(x)                                  (((x) & RF5G3_CH0_PDBICTXBUF_MASK) >> RF5G3_CH0_PDBICTXBUF_LSB)
#define RF5G3_CH0_PDBICTXBUF_SET(x)                                  (((0 | (x)) << RF5G3_CH0_PDBICTXBUF_LSB) & RF5G3_CH0_PDBICTXBUF_MASK)
#define RF5G3_CH0_PDBICTXBUF_RESET                                   4
#define RF5G3_CH0_PDBICTXPA_MSB                                      28
#define RF5G3_CH0_PDBICTXPA_LSB                                      26
#define RF5G3_CH0_PDBICTXPA_MASK                                     0x1c000000
#define RF5G3_CH0_PDBICTXPA_GET(x)                                   (((x) & RF5G3_CH0_PDBICTXPA_MASK) >> RF5G3_CH0_PDBICTXPA_LSB)
#define RF5G3_CH0_PDBICTXPA_SET(x)                                   (((0 | (x)) << RF5G3_CH0_PDBICTXPA_LSB) & RF5G3_CH0_PDBICTXPA_MASK)
#define RF5G3_CH0_PDBICTXPA_RESET                                    4
#define RF5G3_CH0_PDBICTXMIX_MSB                                     25
#define RF5G3_CH0_PDBICTXMIX_LSB                                     23
#define RF5G3_CH0_PDBICTXMIX_MASK                                    0x03800000
#define RF5G3_CH0_PDBICTXMIX_GET(x)                                  (((x) & RF5G3_CH0_PDBICTXMIX_MASK) >> RF5G3_CH0_PDBICTXMIX_LSB)
#define RF5G3_CH0_PDBICTXMIX_SET(x)                                  (((0 | (x)) << RF5G3_CH0_PDBICTXMIX_LSB) & RF5G3_CH0_PDBICTXMIX_MASK)
#define RF5G3_CH0_PDBICTXMIX_RESET                                   4
#define RF5G3_CH0_PDBIC1_MSB                                         22
#define RF5G3_CH0_PDBIC1_LSB                                         20
#define RF5G3_CH0_PDBIC1_MASK                                        0x00700000
#define RF5G3_CH0_PDBIC1_GET(x)                                      (((x) & RF5G3_CH0_PDBIC1_MASK) >> RF5G3_CH0_PDBIC1_LSB)
#define RF5G3_CH0_PDBIC1_SET(x)                                      (((0 | (x)) << RF5G3_CH0_PDBIC1_LSB) & RF5G3_CH0_PDBIC1_MASK)
#define RF5G3_CH0_PDBIC1_RESET                                       4
#define RF5G3_CH0_PDBIC2_MSB                                         19
#define RF5G3_CH0_PDBIC2_LSB                                         17
#define RF5G3_CH0_PDBIC2_MASK                                        0x000e0000
#define RF5G3_CH0_PDBIC2_GET(x)                                      (((x) & RF5G3_CH0_PDBIC2_MASK) >> RF5G3_CH0_PDBIC2_LSB)
#define RF5G3_CH0_PDBIC2_SET(x)                                      (((0 | (x)) << RF5G3_CH0_PDBIC2_LSB) & RF5G3_CH0_PDBIC2_MASK)
#define RF5G3_CH0_PDBIC2_RESET                                       4
#define RF5G3_CH0_PDBIC3_MSB                                         16
#define RF5G3_CH0_PDBIC3_LSB                                         14
#define RF5G3_CH0_PDBIC3_MASK                                        0x0001c000
#define RF5G3_CH0_PDBIC3_GET(x)                                      (((x) & RF5G3_CH0_PDBIC3_MASK) >> RF5G3_CH0_PDBIC3_LSB)
#define RF5G3_CH0_PDBIC3_SET(x)                                      (((0 | (x)) << RF5G3_CH0_PDBIC3_LSB) & RF5G3_CH0_PDBIC3_MASK)
#define RF5G3_CH0_PDBIC3_RESET                                       4
#define RF5G3_CH0_PDBIBCLNA_MSB                                      13
#define RF5G3_CH0_PDBIBCLNA_LSB                                      11
#define RF5G3_CH0_PDBIBCLNA_MASK                                     0x00003800
#define RF5G3_CH0_PDBIBCLNA_GET(x)                                   (((x) & RF5G3_CH0_PDBIBCLNA_MASK) >> RF5G3_CH0_PDBIBCLNA_LSB)
#define RF5G3_CH0_PDBIBCLNA_SET(x)                                   (((0 | (x)) << RF5G3_CH0_PDBIBCLNA_LSB) & RF5G3_CH0_PDBIBCLNA_MASK)
#define RF5G3_CH0_PDBIBCLNA_RESET                                    4
#define RF5G3_CH0_PDBIBCRFVGA_MSB                                    10
#define RF5G3_CH0_PDBIBCRFVGA_LSB                                    8
#define RF5G3_CH0_PDBIBCRFVGA_MASK                                   0x00000700
#define RF5G3_CH0_PDBIBCRFVGA_GET(x)                                 (((x) & RF5G3_CH0_PDBIBCRFVGA_MASK) >> RF5G3_CH0_PDBIBCRFVGA_LSB)
#define RF5G3_CH0_PDBIBCRFVGA_SET(x)                                 (((0 | (x)) << RF5G3_CH0_PDBIBCRFVGA_LSB) & RF5G3_CH0_PDBIBCRFVGA_MASK)
#define RF5G3_CH0_PDBIBCRFVGA_RESET                                  4
#define RF5G3_CH0_PDBIBCVGM_MSB                                      7
#define RF5G3_CH0_PDBIBCVGM_LSB                                      5
#define RF5G3_CH0_PDBIBCVGM_MASK                                     0x000000e0
#define RF5G3_CH0_PDBIBCVGM_GET(x)                                   (((x) & RF5G3_CH0_PDBIBCVGM_MASK) >> RF5G3_CH0_PDBIBCVGM_LSB)
#define RF5G3_CH0_PDBIBCVGM_SET(x)                                   (((0 | (x)) << RF5G3_CH0_PDBIBCVGM_LSB) & RF5G3_CH0_PDBIBCVGM_MASK)
#define RF5G3_CH0_PDBIBCVGM_RESET                                    4
#define RF5G3_CH0_SPARE_MSB                                          4
#define RF5G3_CH0_SPARE_LSB                                          0
#define RF5G3_CH0_SPARE_MASK                                         0x0000001f
#define RF5G3_CH0_SPARE_GET(x)                                       (((x) & RF5G3_CH0_SPARE_MASK) >> RF5G3_CH0_SPARE_LSB)
#define RF5G3_CH0_SPARE_SET(x)                                       (((0 | (x)) << RF5G3_CH0_SPARE_LSB) & RF5G3_CH0_SPARE_MASK)
#define RF5G3_CH0_SPARE_RESET                                        0
#define RF5G3_CH0_ADDRESS                                            0x003c
#define RF5G3_CH0_HW_MASK                                            0xffffffff
#define RF5G3_CH0_SW_MASK                                            0xffffffff
#define RF5G3_CH0_HW_WRITE_MASK                                      0x00000000
#define RF5G3_CH0_SW_WRITE_MASK                                      0xffffffff
#define RF5G3_CH0_RSTMASK                                            0xffffffff
#define RF5G3_CH0_RESET                                              0x92492480

// 0x0040 (RF2G1_CH0)
#define RF2G1_CH0_PDIC25U_LNA_MSB                                    31
#define RF2G1_CH0_PDIC25U_LNA_LSB                                    29
#define RF2G1_CH0_PDIC25U_LNA_MASK                                   0xe0000000
#define RF2G1_CH0_PDIC25U_LNA_GET(x)                                 (((x) & RF2G1_CH0_PDIC25U_LNA_MASK) >> RF2G1_CH0_PDIC25U_LNA_LSB)
#define RF2G1_CH0_PDIC25U_LNA_SET(x)                                 (((0 | (x)) << RF2G1_CH0_PDIC25U_LNA_LSB) & RF2G1_CH0_PDIC25U_LNA_MASK)
#define RF2G1_CH0_PDIC25U_LNA_RESET                                  3
#define RF2G1_CH0_DB_MSB                                             28
#define RF2G1_CH0_DB_LSB                                             26
#define RF2G1_CH0_DB_MASK                                            0x1c000000
#define RF2G1_CH0_DB_GET(x)                                          (((x) & RF2G1_CH0_DB_MASK) >> RF2G1_CH0_DB_LSB)
#define RF2G1_CH0_DB_SET(x)                                          (((0 | (x)) << RF2G1_CH0_DB_LSB) & RF2G1_CH0_DB_MASK)
#define RF2G1_CH0_DB_RESET                                           3
#define RF2G1_CH0_OB_MSB                                             25
#define RF2G1_CH0_OB_LSB                                             23
#define RF2G1_CH0_OB_MASK                                            0x03800000
#define RF2G1_CH0_OB_GET(x)                                          (((x) & RF2G1_CH0_OB_MASK) >> RF2G1_CH0_OB_LSB)
#define RF2G1_CH0_OB_SET(x)                                          (((0 | (x)) << RF2G1_CH0_OB_LSB) & RF2G1_CH0_OB_MASK)
#define RF2G1_CH0_OB_RESET                                           3
#define RF2G1_CH0_LOATB_SEL_MSB                                      22
#define RF2G1_CH0_LOATB_SEL_LSB                                      20
#define RF2G1_CH0_LOATB_SEL_MASK                                     0x00700000
#define RF2G1_CH0_LOATB_SEL_GET(x)                                   (((x) & RF2G1_CH0_LOATB_SEL_MASK) >> RF2G1_CH0_LOATB_SEL_LSB)
#define RF2G1_CH0_LOATB_SEL_SET(x)                                   (((0 | (x)) << RF2G1_CH0_LOATB_SEL_LSB) & RF2G1_CH0_LOATB_SEL_MASK)
#define RF2G1_CH0_LOATB_SEL_RESET                                    0
#define RF2G1_CH0_RXATB_SEL_MSB                                      19
#define RF2G1_CH0_RXATB_SEL_LSB                                      17
#define RF2G1_CH0_RXATB_SEL_MASK                                     0x000e0000
#define RF2G1_CH0_RXATB_SEL_GET(x)                                   (((x) & RF2G1_CH0_RXATB_SEL_MASK) >> RF2G1_CH0_RXATB_SEL_LSB)
#define RF2G1_CH0_RXATB_SEL_SET(x)                                   (((0 | (x)) << RF2G1_CH0_RXATB_SEL_LSB) & RF2G1_CH0_RXATB_SEL_MASK)
#define RF2G1_CH0_RXATB_SEL_RESET                                    0
#define RF2G1_CH0_TXATB_SEL_MSB                                      16
#define RF2G1_CH0_TXATB_SEL_LSB                                      14
#define RF2G1_CH0_TXATB_SEL_MASK                                     0x0001c000
#define RF2G1_CH0_TXATB_SEL_GET(x)                                   (((x) & RF2G1_CH0_TXATB_SEL_MASK) >> RF2G1_CH0_TXATB_SEL_LSB)
#define RF2G1_CH0_TXATB_SEL_SET(x)                                   (((0 | (x)) << RF2G1_CH0_TXATB_SEL_LSB) & RF2G1_CH0_TXATB_SEL_MASK)
#define RF2G1_CH0_TXATB_SEL_RESET                                    0
#define RF2G1_CH0_LOCONTROL_MSB                                      13
#define RF2G1_CH0_LOCONTROL_LSB                                      13
#define RF2G1_CH0_LOCONTROL_MASK                                     0x00002000
#define RF2G1_CH0_LOCONTROL_GET(x)                                   (((x) & RF2G1_CH0_LOCONTROL_MASK) >> RF2G1_CH0_LOCONTROL_LSB)
#define RF2G1_CH0_LOCONTROL_SET(x)                                   (((0 | (x)) << RF2G1_CH0_LOCONTROL_LSB) & RF2G1_CH0_LOCONTROL_MASK)
#define RF2G1_CH0_LOCONTROL_RESET                                    0
#define RF2G1_CH0_PACA_SEL_MSB                                       12
#define RF2G1_CH0_PACA_SEL_LSB                                       11
#define RF2G1_CH0_PACA_SEL_MASK                                      0x00001800
#define RF2G1_CH0_PACA_SEL_GET(x)                                    (((x) & RF2G1_CH0_PACA_SEL_MASK) >> RF2G1_CH0_PACA_SEL_LSB)
#define RF2G1_CH0_PACA_SEL_SET(x)                                    (((0 | (x)) << RF2G1_CH0_PACA_SEL_LSB) & RF2G1_CH0_PACA_SEL_MASK)
#define RF2G1_CH0_PACA_SEL_RESET                                     2
#define RF2G1_CH0_PDIC25U_VGM_MSB                                    10
#define RF2G1_CH0_PDIC25U_VGM_LSB                                    8
#define RF2G1_CH0_PDIC25U_VGM_MASK                                   0x00000700
#define RF2G1_CH0_PDIC25U_VGM_GET(x)                                 (((x) & RF2G1_CH0_PDIC25U_VGM_MASK) >> RF2G1_CH0_PDIC25U_VGM_LSB)
#define RF2G1_CH0_PDIC25U_VGM_SET(x)                                 (((0 | (x)) << RF2G1_CH0_PDIC25U_VGM_LSB) & RF2G1_CH0_PDIC25U_VGM_MASK)
#define RF2G1_CH0_PDIC25U_VGM_RESET                                  3
#define RF2G1_CH0_REGLNA_BYPASS_MSB                                  7
#define RF2G1_CH0_REGLNA_BYPASS_LSB                                  7
#define RF2G1_CH0_REGLNA_BYPASS_MASK                                 0x00000080
#define RF2G1_CH0_REGLNA_BYPASS_GET(x)                               (((x) & RF2G1_CH0_REGLNA_BYPASS_MASK) >> RF2G1_CH0_REGLNA_BYPASS_LSB)
#define RF2G1_CH0_REGLNA_BYPASS_SET(x)                               (((0 | (x)) << RF2G1_CH0_REGLNA_BYPASS_LSB) & RF2G1_CH0_REGLNA_BYPASS_MASK)
#define RF2G1_CH0_REGLNA_BYPASS_RESET                                0
#define RF2G1_CH0_REGLO_BYPASS_MSB                                   6
#define RF2G1_CH0_REGLO_BYPASS_LSB                                   6
#define RF2G1_CH0_REGLO_BYPASS_MASK                                  0x00000040
#define RF2G1_CH0_REGLO_BYPASS_GET(x)                                (((x) & RF2G1_CH0_REGLO_BYPASS_MASK) >> RF2G1_CH0_REGLO_BYPASS_LSB)
#define RF2G1_CH0_REGLO_BYPASS_SET(x)                                (((0 | (x)) << RF2G1_CH0_REGLO_BYPASS_LSB) & RF2G1_CH0_REGLO_BYPASS_MASK)
#define RF2G1_CH0_REGLO_BYPASS_RESET                                 0
#define RF2G1_CH0_SPARES_MSB                                         5
#define RF2G1_CH0_SPARES_LSB                                         0
#define RF2G1_CH0_SPARES_MASK                                        0x0000003f
#define RF2G1_CH0_SPARES_GET(x)                                      (((x) & RF2G1_CH0_SPARES_MASK) >> RF2G1_CH0_SPARES_LSB)
#define RF2G1_CH0_SPARES_SET(x)                                      (((0 | (x)) << RF2G1_CH0_SPARES_LSB) & RF2G1_CH0_SPARES_MASK)
#define RF2G1_CH0_SPARES_RESET                                       0
#define RF2G1_CH0_ADDRESS                                            0x0040
#define RF2G1_CH0_HW_MASK                                            0xffffffff
#define RF2G1_CH0_SW_MASK                                            0xffffffff
#define RF2G1_CH0_HW_WRITE_MASK                                      0x00000000
#define RF2G1_CH0_SW_WRITE_MASK                                      0xffffffff
#define RF2G1_CH0_RSTMASK                                            0xffffffff
#define RF2G1_CH0_RESET                                              0x6d801300

// 0x0044 (RF2G2_CH0)
#define RF2G2_CH0_PDLNA_MSB                                          31
#define RF2G2_CH0_PDLNA_LSB                                          31
#define RF2G2_CH0_PDLNA_MASK                                         0x80000000
#define RF2G2_CH0_PDLNA_GET(x)                                       (((x) & RF2G2_CH0_PDLNA_MASK) >> RF2G2_CH0_PDLNA_LSB)
#define RF2G2_CH0_PDLNA_SET(x)                                       (((0 | (x)) << RF2G2_CH0_PDLNA_LSB) & RF2G2_CH0_PDLNA_MASK)
#define RF2G2_CH0_PDLNA_RESET                                        0
#define RF2G2_CH0_PDDIV_MSB                                          30
#define RF2G2_CH0_PDDIV_LSB                                          30
#define RF2G2_CH0_PDDIV_MASK                                         0x40000000
#define RF2G2_CH0_PDDIV_GET(x)                                       (((x) & RF2G2_CH0_PDDIV_MASK) >> RF2G2_CH0_PDDIV_LSB)
#define RF2G2_CH0_PDDIV_SET(x)                                       (((0 | (x)) << RF2G2_CH0_PDDIV_LSB) & RF2G2_CH0_PDDIV_MASK)
#define RF2G2_CH0_PDDIV_RESET                                        0
#define RF2G2_CH0_PDPADRV_MSB                                        29
#define RF2G2_CH0_PDPADRV_LSB                                        29
#define RF2G2_CH0_PDPADRV_MASK                                       0x20000000
#define RF2G2_CH0_PDPADRV_GET(x)                                     (((x) & RF2G2_CH0_PDPADRV_MASK) >> RF2G2_CH0_PDPADRV_LSB)
#define RF2G2_CH0_PDPADRV_SET(x)                                     (((0 | (x)) << RF2G2_CH0_PDPADRV_LSB) & RF2G2_CH0_PDPADRV_MASK)
#define RF2G2_CH0_PDPADRV_RESET                                      0
#define RF2G2_CH0_PDPAOUT_MSB                                        28
#define RF2G2_CH0_PDPAOUT_LSB                                        28
#define RF2G2_CH0_PDPAOUT_MASK                                       0x10000000
#define RF2G2_CH0_PDPAOUT_GET(x)                                     (((x) & RF2G2_CH0_PDPAOUT_MASK) >> RF2G2_CH0_PDPAOUT_LSB)
#define RF2G2_CH0_PDPAOUT_SET(x)                                     (((0 | (x)) << RF2G2_CH0_PDPAOUT_LSB) & RF2G2_CH0_PDPAOUT_MASK)
#define RF2G2_CH0_PDPAOUT_RESET                                      0
#define RF2G2_CH0_PDREGLNA_MSB                                       27
#define RF2G2_CH0_PDREGLNA_LSB                                       27
#define RF2G2_CH0_PDREGLNA_MASK                                      0x08000000
#define RF2G2_CH0_PDREGLNA_GET(x)                                    (((x) & RF2G2_CH0_PDREGLNA_MASK) >> RF2G2_CH0_PDREGLNA_LSB)
#define RF2G2_CH0_PDREGLNA_SET(x)                                    (((0 | (x)) << RF2G2_CH0_PDREGLNA_LSB) & RF2G2_CH0_PDREGLNA_MASK)
#define RF2G2_CH0_PDREGLNA_RESET                                     0
#define RF2G2_CH0_PDREGLO_MSB                                        26
#define RF2G2_CH0_PDREGLO_LSB                                        26
#define RF2G2_CH0_PDREGLO_MASK                                       0x04000000
#define RF2G2_CH0_PDREGLO_GET(x)                                     (((x) & RF2G2_CH0_PDREGLO_MASK) >> RF2G2_CH0_PDREGLO_LSB)
#define RF2G2_CH0_PDREGLO_SET(x)                                     (((0 | (x)) << RF2G2_CH0_PDREGLO_LSB) & RF2G2_CH0_PDREGLO_MASK)
#define RF2G2_CH0_PDREGLO_RESET                                      0
#define RF2G2_CH0_PDVGM_MSB                                          25
#define RF2G2_CH0_PDVGM_LSB                                          25
#define RF2G2_CH0_PDVGM_MASK                                         0x02000000
#define RF2G2_CH0_PDVGM_GET(x)                                       (((x) & RF2G2_CH0_PDVGM_MASK) >> RF2G2_CH0_PDVGM_LSB)
#define RF2G2_CH0_PDVGM_SET(x)                                       (((0 | (x)) << RF2G2_CH0_PDVGM_LSB) & RF2G2_CH0_PDVGM_MASK)
#define RF2G2_CH0_PDVGM_RESET                                        0
#define RF2G2_CH0_PDRXLO_MSB                                         24
#define RF2G2_CH0_PDRXLO_LSB                                         24
#define RF2G2_CH0_PDRXLO_MASK                                        0x01000000
#define RF2G2_CH0_PDRXLO_GET(x)                                      (((x) & RF2G2_CH0_PDRXLO_MASK) >> RF2G2_CH0_PDRXLO_LSB)
#define RF2G2_CH0_PDRXLO_SET(x)                                      (((0 | (x)) << RF2G2_CH0_PDRXLO_LSB) & RF2G2_CH0_PDRXLO_MASK)
#define RF2G2_CH0_PDRXLO_RESET                                       0
#define RF2G2_CH0_PDTXLO_MSB                                         23
#define RF2G2_CH0_PDTXLO_LSB                                         23
#define RF2G2_CH0_PDTXLO_MASK                                        0x00800000
#define RF2G2_CH0_PDTXLO_GET(x)                                      (((x) & RF2G2_CH0_PDTXLO_MASK) >> RF2G2_CH0_PDTXLO_LSB)
#define RF2G2_CH0_PDTXLO_SET(x)                                      (((0 | (x)) << RF2G2_CH0_PDTXLO_LSB) & RF2G2_CH0_PDTXLO_MASK)
#define RF2G2_CH0_PDTXLO_RESET                                       0
#define RF2G2_CH0_PDTXMIX_MSB                                        22
#define RF2G2_CH0_PDTXMIX_LSB                                        22
#define RF2G2_CH0_PDTXMIX_MASK                                       0x00400000
#define RF2G2_CH0_PDTXMIX_GET(x)                                     (((x) & RF2G2_CH0_PDTXMIX_MASK) >> RF2G2_CH0_PDTXMIX_LSB)
#define RF2G2_CH0_PDTXMIX_SET(x)                                     (((0 | (x)) << RF2G2_CH0_PDTXMIX_LSB) & RF2G2_CH0_PDTXMIX_MASK)
#define RF2G2_CH0_PDTXMIX_RESET                                      0
#define RF2G2_CH0_PDIR25U_TXMIX_MSB                                  21
#define RF2G2_CH0_PDIR25U_TXMIX_LSB                                  19
#define RF2G2_CH0_PDIR25U_TXMIX_MASK                                 0x00380000
#define RF2G2_CH0_PDIR25U_TXMIX_GET(x)                               (((x) & RF2G2_CH0_PDIR25U_TXMIX_MASK) >> RF2G2_CH0_PDIR25U_TXMIX_LSB)
#define RF2G2_CH0_PDIR25U_TXMIX_SET(x)                               (((0 | (x)) << RF2G2_CH0_PDIR25U_TXMIX_LSB) & RF2G2_CH0_PDIR25U_TXMIX_MASK)
#define RF2G2_CH0_PDIR25U_TXMIX_RESET                                3
#define RF2G2_CH0_PDIR25U_TXPA_MSB                                   18
#define RF2G2_CH0_PDIR25U_TXPA_LSB                                   18
#define RF2G2_CH0_PDIR25U_TXPA_MASK                                  0x00040000
#define RF2G2_CH0_PDIR25U_TXPA_GET(x)                                (((x) & RF2G2_CH0_PDIR25U_TXPA_MASK) >> RF2G2_CH0_PDIR25U_TXPA_LSB)
#define RF2G2_CH0_PDIR25U_TXPA_SET(x)                                (((0 | (x)) << RF2G2_CH0_PDIR25U_TXPA_LSB) & RF2G2_CH0_PDIR25U_TXPA_MASK)
#define RF2G2_CH0_PDIR25U_TXPA_RESET                                 0
#define RF2G2_CH0_PDIC25U_TXPA_MSB                                   17
#define RF2G2_CH0_PDIC25U_TXPA_LSB                                   15
#define RF2G2_CH0_PDIC25U_TXPA_MASK                                  0x00038000
#define RF2G2_CH0_PDIC25U_TXPA_GET(x)                                (((x) & RF2G2_CH0_PDIC25U_TXPA_MASK) >> RF2G2_CH0_PDIC25U_TXPA_LSB)
#define RF2G2_CH0_PDIC25U_TXPA_SET(x)                                (((0 | (x)) << RF2G2_CH0_PDIC25U_TXPA_LSB) & RF2G2_CH0_PDIC25U_TXPA_MASK)
#define RF2G2_CH0_PDIC25U_TXPA_RESET                                 3
#define RF2G2_CH0_PDIC25U_TXRF_MSB                                   14
#define RF2G2_CH0_PDIC25U_TXRF_LSB                                   12
#define RF2G2_CH0_PDIC25U_TXRF_MASK                                  0x00007000
#define RF2G2_CH0_PDIC25U_TXRF_GET(x)                                (((x) & RF2G2_CH0_PDIC25U_TXRF_MASK) >> RF2G2_CH0_PDIC25U_TXRF_LSB)
#define RF2G2_CH0_PDIC25U_TXRF_SET(x)                                (((0 | (x)) << RF2G2_CH0_PDIC25U_TXRF_LSB) & RF2G2_CH0_PDIC25U_TXRF_MASK)
#define RF2G2_CH0_PDIC25U_TXRF_RESET                                 3
#define RF2G2_CH0_PDIC25U_RXRF_MSB                                   11
#define RF2G2_CH0_PDIC25U_RXRF_LSB                                   9
#define RF2G2_CH0_PDIC25U_RXRF_MASK                                  0x00000e00
#define RF2G2_CH0_PDIC25U_RXRF_GET(x)                                (((x) & RF2G2_CH0_PDIC25U_RXRF_MASK) >> RF2G2_CH0_PDIC25U_RXRF_LSB)
#define RF2G2_CH0_PDIC25U_RXRF_SET(x)                                (((0 | (x)) << RF2G2_CH0_PDIC25U_RXRF_LSB) & RF2G2_CH0_PDIC25U_RXRF_MASK)
#define RF2G2_CH0_PDIC25U_RXRF_RESET                                 7
#define RF2G2_CH0_PDIC50U_DIV_MSB                                    8
#define RF2G2_CH0_PDIC50U_DIV_LSB                                    6
#define RF2G2_CH0_PDIC50U_DIV_MASK                                   0x000001c0
#define RF2G2_CH0_PDIC50U_DIV_GET(x)                                 (((x) & RF2G2_CH0_PDIC50U_DIV_MASK) >> RF2G2_CH0_PDIC50U_DIV_LSB)
#define RF2G2_CH0_PDIC50U_DIV_SET(x)                                 (((0 | (x)) << RF2G2_CH0_PDIC50U_DIV_LSB) & RF2G2_CH0_PDIC50U_DIV_MASK)
#define RF2G2_CH0_PDIC50U_DIV_RESET                                  3
#define RF2G2_CH0_PDIC25U_VREGLO_MSB                                 5
#define RF2G2_CH0_PDIC25U_VREGLO_LSB                                 3
#define RF2G2_CH0_PDIC25U_VREGLO_MASK                                0x00000038
#define RF2G2_CH0_PDIC25U_VREGLO_GET(x)                              (((x) & RF2G2_CH0_PDIC25U_VREGLO_MASK) >> RF2G2_CH0_PDIC25U_VREGLO_LSB)
#define RF2G2_CH0_PDIC25U_VREGLO_SET(x)                              (((0 | (x)) << RF2G2_CH0_PDIC25U_VREGLO_LSB) & RF2G2_CH0_PDIC25U_VREGLO_MASK)
#define RF2G2_CH0_PDIC25U_VREGLO_RESET                               7
#define RF2G2_CH0_PDIR25U_VREGLO_MSB                                 2
#define RF2G2_CH0_PDIR25U_VREGLO_LSB                                 0
#define RF2G2_CH0_PDIR25U_VREGLO_MASK                                0x00000007
#define RF2G2_CH0_PDIR25U_VREGLO_GET(x)                              (((x) & RF2G2_CH0_PDIR25U_VREGLO_MASK) >> RF2G2_CH0_PDIR25U_VREGLO_LSB)
#define RF2G2_CH0_PDIR25U_VREGLO_SET(x)                              (((0 | (x)) << RF2G2_CH0_PDIR25U_VREGLO_LSB) & RF2G2_CH0_PDIR25U_VREGLO_MASK)
#define RF2G2_CH0_PDIR25U_VREGLO_RESET                               7
#define RF2G2_CH0_ADDRESS                                            0x0044
#define RF2G2_CH0_HW_MASK                                            0xffffffff
#define RF2G2_CH0_SW_MASK                                            0xffffffff
#define RF2G2_CH0_HW_WRITE_MASK                                      0x00000000
#define RF2G2_CH0_SW_WRITE_MASK                                      0xffffffff
#define RF2G2_CH0_RSTMASK                                            0xffffffff
#define RF2G2_CH0_RESET                                              0x0019beff

// 0x0048 (SYNTH1)
#define SYNTH1_PWD_BIAS_MSB                                          31
#define SYNTH1_PWD_BIAS_LSB                                          31
#define SYNTH1_PWD_BIAS_MASK                                         0x80000000
#define SYNTH1_PWD_BIAS_GET(x)                                       (((x) & SYNTH1_PWD_BIAS_MASK) >> SYNTH1_PWD_BIAS_LSB)
#define SYNTH1_PWD_BIAS_SET(x)                                       (((0 | (x)) << SYNTH1_PWD_BIAS_LSB) & SYNTH1_PWD_BIAS_MASK)
#define SYNTH1_PWD_BIAS_RESET                                        0
#define SYNTH1_PWD_CP_MSB                                            30
#define SYNTH1_PWD_CP_LSB                                            30
#define SYNTH1_PWD_CP_MASK                                           0x40000000
#define SYNTH1_PWD_CP_GET(x)                                         (((x) & SYNTH1_PWD_CP_MASK) >> SYNTH1_PWD_CP_LSB)
#define SYNTH1_PWD_CP_SET(x)                                         (((0 | (x)) << SYNTH1_PWD_CP_LSB) & SYNTH1_PWD_CP_MASK)
#define SYNTH1_PWD_CP_RESET                                          0
#define SYNTH1_PWD_VCMON_MSB                                         29
#define SYNTH1_PWD_VCMON_LSB                                         29
#define SYNTH1_PWD_VCMON_MASK                                        0x20000000
#define SYNTH1_PWD_VCMON_GET(x)                                      (((x) & SYNTH1_PWD_VCMON_MASK) >> SYNTH1_PWD_VCMON_LSB)
#define SYNTH1_PWD_VCMON_SET(x)                                      (((0 | (x)) << SYNTH1_PWD_VCMON_LSB) & SYNTH1_PWD_VCMON_MASK)
#define SYNTH1_PWD_VCMON_RESET                                       0
#define SYNTH1_PWD_VCO_MSB                                           28
#define SYNTH1_PWD_VCO_LSB                                           28
#define SYNTH1_PWD_VCO_MASK                                          0x10000000
#define SYNTH1_PWD_VCO_GET(x)                                        (((x) & SYNTH1_PWD_VCO_MASK) >> SYNTH1_PWD_VCO_LSB)
#define SYNTH1_PWD_VCO_SET(x)                                        (((0 | (x)) << SYNTH1_PWD_VCO_LSB) & SYNTH1_PWD_VCO_MASK)
#define SYNTH1_PWD_VCO_RESET                                         0
#define SYNTH1_PWD_PRESC_MSB                                         27
#define SYNTH1_PWD_PRESC_LSB                                         27
#define SYNTH1_PWD_PRESC_MASK                                        0x08000000
#define SYNTH1_PWD_PRESC_GET(x)                                      (((x) & SYNTH1_PWD_PRESC_MASK) >> SYNTH1_PWD_PRESC_LSB)
#define SYNTH1_PWD_PRESC_SET(x)                                      (((0 | (x)) << SYNTH1_PWD_PRESC_LSB) & SYNTH1_PWD_PRESC_MASK)
#define SYNTH1_PWD_PRESC_RESET                                       0
#define SYNTH1_PWD_LOBUF2G_MSB                                       26
#define SYNTH1_PWD_LOBUF2G_LSB                                       26
#define SYNTH1_PWD_LOBUF2G_MASK                                      0x04000000
#define SYNTH1_PWD_LOBUF2G_GET(x)                                    (((x) & SYNTH1_PWD_LOBUF2G_MASK) >> SYNTH1_PWD_LOBUF2G_LSB)
#define SYNTH1_PWD_LOBUF2G_SET(x)                                    (((0 | (x)) << SYNTH1_PWD_LOBUF2G_LSB) & SYNTH1_PWD_LOBUF2G_MASK)
#define SYNTH1_PWD_LOBUF2G_RESET                                     0
#define SYNTH1_PWD_LOBUF5G_MSB                                       25
#define SYNTH1_PWD_LOBUF5G_LSB                                       25
#define SYNTH1_PWD_LOBUF5G_MASK                                      0x02000000
#define SYNTH1_PWD_LOBUF5G_GET(x)                                    (((x) & SYNTH1_PWD_LOBUF5G_MASK) >> SYNTH1_PWD_LOBUF5G_LSB)
#define SYNTH1_PWD_LOBUF5G_SET(x)                                    (((0 | (x)) << SYNTH1_PWD_LOBUF5G_LSB) & SYNTH1_PWD_LOBUF5G_MASK)
#define SYNTH1_PWD_LOBUF5G_RESET                                     0
#define SYNTH1_PWD_LODIV_MSB                                         24
#define SYNTH1_PWD_LODIV_LSB                                         24
#define SYNTH1_PWD_LODIV_MASK                                        0x01000000
#define SYNTH1_PWD_LODIV_GET(x)                                      (((x) & SYNTH1_PWD_LODIV_MASK) >> SYNTH1_PWD_LODIV_LSB)
#define SYNTH1_PWD_LODIV_SET(x)                                      (((0 | (x)) << SYNTH1_PWD_LODIV_LSB) & SYNTH1_PWD_LODIV_MASK)
#define SYNTH1_PWD_LODIV_RESET                                       0
#define SYNTH1_PWD_LOMIX_MSB                                         23
#define SYNTH1_PWD_LOMIX_LSB                                         23
#define SYNTH1_PWD_LOMIX_MASK                                        0x00800000
#define SYNTH1_PWD_LOMIX_GET(x)                                      (((x) & SYNTH1_PWD_LOMIX_MASK) >> SYNTH1_PWD_LOMIX_LSB)
#define SYNTH1_PWD_LOMIX_SET(x)                                      (((0 | (x)) << SYNTH1_PWD_LOMIX_LSB) & SYNTH1_PWD_LOMIX_MASK)
#define SYNTH1_PWD_LOMIX_RESET                                       0
#define SYNTH1_PWUP_LOREF_MSB                                        22
#define SYNTH1_PWUP_LOREF_LSB                                        22
#define SYNTH1_PWUP_LOREF_MASK                                       0x00400000
#define SYNTH1_PWUP_LOREF_GET(x)                                     (((x) & SYNTH1_PWUP_LOREF_MASK) >> SYNTH1_PWUP_LOREF_LSB)
#define SYNTH1_PWUP_LOREF_SET(x)                                     (((0 | (x)) << SYNTH1_PWUP_LOREF_LSB) & SYNTH1_PWUP_LOREF_MASK)
#define SYNTH1_PWUP_LOREF_RESET                                      0
#define SYNTH1_VCOREGBYPASS_MSB                                      21
#define SYNTH1_VCOREGBYPASS_LSB                                      21
#define SYNTH1_VCOREGBYPASS_MASK                                     0x00200000
#define SYNTH1_VCOREGBYPASS_GET(x)                                   (((x) & SYNTH1_VCOREGBYPASS_MASK) >> SYNTH1_VCOREGBYPASS_LSB)
#define SYNTH1_VCOREGBYPASS_SET(x)                                   (((0 | (x)) << SYNTH1_VCOREGBYPASS_LSB) & SYNTH1_VCOREGBYPASS_MASK)
#define SYNTH1_VCOREGBYPASS_RESET                                    0
#define SYNTH1_VCOREGLEVEL_MSB                                       20
#define SYNTH1_VCOREGLEVEL_LSB                                       19
#define SYNTH1_VCOREGLEVEL_MASK                                      0x00180000
#define SYNTH1_VCOREGLEVEL_GET(x)                                    (((x) & SYNTH1_VCOREGLEVEL_MASK) >> SYNTH1_VCOREGLEVEL_LSB)
#define SYNTH1_VCOREGLEVEL_SET(x)                                    (((0 | (x)) << SYNTH1_VCOREGLEVEL_LSB) & SYNTH1_VCOREGLEVEL_MASK)
#define SYNTH1_VCOREGLEVEL_RESET                                     1
#define SYNTH1_VCOBUFBIAS_MSB                                        18
#define SYNTH1_VCOBUFBIAS_LSB                                        17
#define SYNTH1_VCOBUFBIAS_MASK                                       0x00060000
#define SYNTH1_VCOBUFBIAS_GET(x)                                     (((x) & SYNTH1_VCOBUFBIAS_MASK) >> SYNTH1_VCOBUFBIAS_LSB)
#define SYNTH1_VCOBUFBIAS_SET(x)                                     (((0 | (x)) << SYNTH1_VCOBUFBIAS_LSB) & SYNTH1_VCOBUFBIAS_MASK)
#define SYNTH1_VCOBUFBIAS_RESET                                      1
#define SYNTH1_PWUP_VCOBUF_PD_MSB                                    16
#define SYNTH1_PWUP_VCOBUF_PD_LSB                                    16
#define SYNTH1_PWUP_VCOBUF_PD_MASK                                   0x00010000
#define SYNTH1_PWUP_VCOBUF_PD_GET(x)                                 (((x) & SYNTH1_PWUP_VCOBUF_PD_MASK) >> SYNTH1_PWUP_VCOBUF_PD_LSB)
#define SYNTH1_PWUP_VCOBUF_PD_SET(x)                                 (((0 | (x)) << SYNTH1_PWUP_VCOBUF_PD_LSB) & SYNTH1_PWUP_VCOBUF_PD_MASK)
#define SYNTH1_PWUP_VCOBUF_PD_RESET                                  0
#define SYNTH1_PWUP_LOBUF2G_PD_MSB                                   15
#define SYNTH1_PWUP_LOBUF2G_PD_LSB                                   15
#define SYNTH1_PWUP_LOBUF2G_PD_MASK                                  0x00008000
#define SYNTH1_PWUP_LOBUF2G_PD_GET(x)                                (((x) & SYNTH1_PWUP_LOBUF2G_PD_MASK) >> SYNTH1_PWUP_LOBUF2G_PD_LSB)
#define SYNTH1_PWUP_LOBUF2G_PD_SET(x)                                (((0 | (x)) << SYNTH1_PWUP_LOBUF2G_PD_LSB) & SYNTH1_PWUP_LOBUF2G_PD_MASK)
#define SYNTH1_PWUP_LOBUF2G_PD_RESET                                 0
#define SYNTH1_PWUP_LOBUF5G_PD_MSB                                   14
#define SYNTH1_PWUP_LOBUF5G_PD_LSB                                   14
#define SYNTH1_PWUP_LOBUF5G_PD_MASK                                  0x00004000
#define SYNTH1_PWUP_LOBUF5G_PD_GET(x)                                (((x) & SYNTH1_PWUP_LOBUF5G_PD_MASK) >> SYNTH1_PWUP_LOBUF5G_PD_LSB)
#define SYNTH1_PWUP_LOBUF5G_PD_SET(x)                                (((0 | (x)) << SYNTH1_PWUP_LOBUF5G_PD_LSB) & SYNTH1_PWUP_LOBUF5G_PD_MASK)
#define SYNTH1_PWUP_LOBUF5G_PD_RESET                                 0
#define SYNTH1_PWUP_LODIV_PD_MSB                                     13
#define SYNTH1_PWUP_LODIV_PD_LSB                                     13
#define SYNTH1_PWUP_LODIV_PD_MASK                                    0x00002000
#define SYNTH1_PWUP_LODIV_PD_GET(x)                                  (((x) & SYNTH1_PWUP_LODIV_PD_MASK) >> SYNTH1_PWUP_LODIV_PD_LSB)
#define SYNTH1_PWUP_LODIV_PD_SET(x)                                  (((0 | (x)) << SYNTH1_PWUP_LODIV_PD_LSB) & SYNTH1_PWUP_LODIV_PD_MASK)
#define SYNTH1_PWUP_LODIV_PD_RESET                                   0
#define SYNTH1_PWUP_LOMIX_PD_MSB                                     12
#define SYNTH1_PWUP_LOMIX_PD_LSB                                     12
#define SYNTH1_PWUP_LOMIX_PD_MASK                                    0x00001000
#define SYNTH1_PWUP_LOMIX_PD_GET(x)                                  (((x) & SYNTH1_PWUP_LOMIX_PD_MASK) >> SYNTH1_PWUP_LOMIX_PD_LSB)
#define SYNTH1_PWUP_LOMIX_PD_SET(x)                                  (((0 | (x)) << SYNTH1_PWUP_LOMIX_PD_LSB) & SYNTH1_PWUP_LOMIX_PD_MASK)
#define SYNTH1_PWUP_LOMIX_PD_RESET                                   0
#define SYNTH1_MONITOR_FB_MSB                                        11
#define SYNTH1_MONITOR_FB_LSB                                        11
#define SYNTH1_MONITOR_FB_MASK                                       0x00000800
#define SYNTH1_MONITOR_FB_GET(x)                                     (((x) & SYNTH1_MONITOR_FB_MASK) >> SYNTH1_MONITOR_FB_LSB)
#define SYNTH1_MONITOR_FB_SET(x)                                     (((0 | (x)) << SYNTH1_MONITOR_FB_LSB) & SYNTH1_MONITOR_FB_MASK)
#define SYNTH1_MONITOR_FB_RESET                                      0
#define SYNTH1_MONITOR_REF_MSB                                       10
#define SYNTH1_MONITOR_REF_LSB                                       10
#define SYNTH1_MONITOR_REF_MASK                                      0x00000400
#define SYNTH1_MONITOR_REF_GET(x)                                    (((x) & SYNTH1_MONITOR_REF_MASK) >> SYNTH1_MONITOR_REF_LSB)
#define SYNTH1_MONITOR_REF_SET(x)                                    (((0 | (x)) << SYNTH1_MONITOR_REF_LSB) & SYNTH1_MONITOR_REF_MASK)
#define SYNTH1_MONITOR_REF_RESET                                     0
#define SYNTH1_MONITOR_FB_DIV2_MSB                                   9
#define SYNTH1_MONITOR_FB_DIV2_LSB                                   9
#define SYNTH1_MONITOR_FB_DIV2_MASK                                  0x00000200
#define SYNTH1_MONITOR_FB_DIV2_GET(x)                                (((x) & SYNTH1_MONITOR_FB_DIV2_MASK) >> SYNTH1_MONITOR_FB_DIV2_LSB)
#define SYNTH1_MONITOR_FB_DIV2_SET(x)                                (((0 | (x)) << SYNTH1_MONITOR_FB_DIV2_LSB) & SYNTH1_MONITOR_FB_DIV2_MASK)
#define SYNTH1_MONITOR_FB_DIV2_RESET                                 0
#define SYNTH1_MONITOR_VC2HIGH_MSB                                   8
#define SYNTH1_MONITOR_VC2HIGH_LSB                                   8
#define SYNTH1_MONITOR_VC2HIGH_MASK                                  0x00000100
#define SYNTH1_MONITOR_VC2HIGH_GET(x)                                (((x) & SYNTH1_MONITOR_VC2HIGH_MASK) >> SYNTH1_MONITOR_VC2HIGH_LSB)
#define SYNTH1_MONITOR_VC2HIGH_SET(x)                                (((0 | (x)) << SYNTH1_MONITOR_VC2HIGH_LSB) & SYNTH1_MONITOR_VC2HIGH_MASK)
#define SYNTH1_MONITOR_VC2HIGH_RESET                                 0
#define SYNTH1_MONITOR_VC2LOW_MSB                                    7
#define SYNTH1_MONITOR_VC2LOW_LSB                                    7
#define SYNTH1_MONITOR_VC2LOW_MASK                                   0x00000080
#define SYNTH1_MONITOR_VC2LOW_GET(x)                                 (((x) & SYNTH1_MONITOR_VC2LOW_MASK) >> SYNTH1_MONITOR_VC2LOW_LSB)
#define SYNTH1_MONITOR_VC2LOW_SET(x)                                 (((0 | (x)) << SYNTH1_MONITOR_VC2LOW_LSB) & SYNTH1_MONITOR_VC2LOW_MASK)
#define SYNTH1_MONITOR_VC2LOW_RESET                                  0
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_MSB                             6
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_LSB                             6
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_MASK                            0x00000040
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_GET(x)                          (((x) & SYNTH1_MONITOR_SYNTHLOCKVCOK_MASK) >> SYNTH1_MONITOR_SYNTHLOCKVCOK_LSB)
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_SET(x)                          (((0 | (x)) << SYNTH1_MONITOR_SYNTHLOCKVCOK_LSB) & SYNTH1_MONITOR_SYNTHLOCKVCOK_MASK)
#define SYNTH1_MONITOR_SYNTHLOCKVCOK_RESET                           0
#define SYNTH1_CON_VDDVCOREG_MSB                                     5
#define SYNTH1_CON_VDDVCOREG_LSB                                     5
#define SYNTH1_CON_VDDVCOREG_MASK                                    0x00000020
#define SYNTH1_CON_VDDVCOREG_GET(x)                                  (((x) & SYNTH1_CON_VDDVCOREG_MASK) >> SYNTH1_CON_VDDVCOREG_LSB)
#define SYNTH1_CON_VDDVCOREG_SET(x)                                  (((0 | (x)) << SYNTH1_CON_VDDVCOREG_LSB) & SYNTH1_CON_VDDVCOREG_MASK)
#define SYNTH1_CON_VDDVCOREG_RESET                                   0
#define SYNTH1_CON_IVCOREG_MSB                                       4
#define SYNTH1_CON_IVCOREG_LSB                                       4
#define SYNTH1_CON_IVCOREG_MASK                                      0x00000010
#define SYNTH1_CON_IVCOREG_GET(x)                                    (((x) & SYNTH1_CON_IVCOREG_MASK) >> SYNTH1_CON_IVCOREG_LSB)
#define SYNTH1_CON_IVCOREG_SET(x)                                    (((0 | (x)) << SYNTH1_CON_IVCOREG_LSB) & SYNTH1_CON_IVCOREG_MASK)
#define SYNTH1_CON_IVCOREG_RESET                                     0
#define SYNTH1_CON_IVCOBUF_MSB                                       3
#define SYNTH1_CON_IVCOBUF_LSB                                       3
#define SYNTH1_CON_IVCOBUF_MASK                                      0x00000008
#define SYNTH1_CON_IVCOBUF_GET(x)                                    (((x) & SYNTH1_CON_IVCOBUF_MASK) >> SYNTH1_CON_IVCOBUF_LSB)
#define SYNTH1_CON_IVCOBUF_SET(x)                                    (((0 | (x)) << SYNTH1_CON_IVCOBUF_LSB) & SYNTH1_CON_IVCOBUF_MASK)
#define SYNTH1_CON_IVCOBUF_RESET                                     0
#define SYNTH1_SEL_VCMONABUS_MSB                                     2
#define SYNTH1_SEL_VCMONABUS_LSB                                     0
#define SYNTH1_SEL_VCMONABUS_MASK                                    0x00000007
#define SYNTH1_SEL_VCMONABUS_GET(x)                                  (((x) & SYNTH1_SEL_VCMONABUS_MASK) >> SYNTH1_SEL_VCMONABUS_LSB)
#define SYNTH1_SEL_VCMONABUS_SET(x)                                  (((0 | (x)) << SYNTH1_SEL_VCMONABUS_LSB) & SYNTH1_SEL_VCMONABUS_MASK)
#define SYNTH1_SEL_VCMONABUS_RESET                                   0
#define SYNTH1_ADDRESS                                               0x0048
#define SYNTH1_HW_MASK                                               0xffffffff
#define SYNTH1_SW_MASK                                               0xffffffff
#define SYNTH1_HW_WRITE_MASK                                         0x00000000
#define SYNTH1_SW_WRITE_MASK                                         0xffffffff
#define SYNTH1_RSTMASK                                               0xffffffff
#define SYNTH1_RESET                                                 0x000a0000

// 0x004c (SYNTH2)
#define SYNTH2_VC_CAL_REF_MSB                                        31
#define SYNTH2_VC_CAL_REF_LSB                                        29
#define SYNTH2_VC_CAL_REF_MASK                                       0xe0000000
#define SYNTH2_VC_CAL_REF_GET(x)                                     (((x) & SYNTH2_VC_CAL_REF_MASK) >> SYNTH2_VC_CAL_REF_LSB)
#define SYNTH2_VC_CAL_REF_SET(x)                                     (((0 | (x)) << SYNTH2_VC_CAL_REF_LSB) & SYNTH2_VC_CAL_REF_MASK)
#define SYNTH2_VC_CAL_REF_RESET                                      0
#define SYNTH2_VC_HI_REF_MSB                                         28
#define SYNTH2_VC_HI_REF_LSB                                         26
#define SYNTH2_VC_HI_REF_MASK                                        0x1c000000
#define SYNTH2_VC_HI_REF_GET(x)                                      (((x) & SYNTH2_VC_HI_REF_MASK) >> SYNTH2_VC_HI_REF_LSB)
#define SYNTH2_VC_HI_REF_SET(x)                                      (((0 | (x)) << SYNTH2_VC_HI_REF_LSB) & SYNTH2_VC_HI_REF_MASK)
#define SYNTH2_VC_HI_REF_RESET                                       3
#define SYNTH2_VC_MID_REF_MSB                                        25
#define SYNTH2_VC_MID_REF_LSB                                        23
#define SYNTH2_VC_MID_REF_MASK                                       0x03800000
#define SYNTH2_VC_MID_REF_GET(x)                                     (((x) & SYNTH2_VC_MID_REF_MASK) >> SYNTH2_VC_MID_REF_LSB)
#define SYNTH2_VC_MID_REF_SET(x)                                     (((0 | (x)) << SYNTH2_VC_MID_REF_LSB) & SYNTH2_VC_MID_REF_MASK)
#define SYNTH2_VC_MID_REF_RESET                                      4
#define SYNTH2_VC_LOW_REF_MSB                                        22
#define SYNTH2_VC_LOW_REF_LSB                                        20
#define SYNTH2_VC_LOW_REF_MASK                                       0x00700000
#define SYNTH2_VC_LOW_REF_GET(x)                                     (((x) & SYNTH2_VC_LOW_REF_MASK) >> SYNTH2_VC_LOW_REF_LSB)
#define SYNTH2_VC_LOW_REF_SET(x)                                     (((0 | (x)) << SYNTH2_VC_LOW_REF_LSB) & SYNTH2_VC_LOW_REF_MASK)
#define SYNTH2_VC_LOW_REF_RESET                                      4
#define SYNTH2_CPBIAS_MSB                                            19
#define SYNTH2_CPBIAS_LSB                                            18
#define SYNTH2_CPBIAS_MASK                                           0x000c0000
#define SYNTH2_CPBIAS_GET(x)                                         (((x) & SYNTH2_CPBIAS_MASK) >> SYNTH2_CPBIAS_LSB)
#define SYNTH2_CPBIAS_SET(x)                                         (((0 | (x)) << SYNTH2_CPBIAS_LSB) & SYNTH2_CPBIAS_MASK)
#define SYNTH2_CPBIAS_RESET                                          3
#define SYNTH2_CPSTEERING_EN_INTN_MSB                                17
#define SYNTH2_CPSTEERING_EN_INTN_LSB                                17
#define SYNTH2_CPSTEERING_EN_INTN_MASK                               0x00020000
#define SYNTH2_CPSTEERING_EN_INTN_GET(x)                             (((x) & SYNTH2_CPSTEERING_EN_INTN_MASK) >> SYNTH2_CPSTEERING_EN_INTN_LSB)
#define SYNTH2_CPSTEERING_EN_INTN_SET(x)                             (((0 | (x)) << SYNTH2_CPSTEERING_EN_INTN_LSB) & SYNTH2_CPSTEERING_EN_INTN_MASK)
#define SYNTH2_CPSTEERING_EN_INTN_RESET                              1
#define SYNTH2_CPLOWLK_MSB                                           16
#define SYNTH2_CPLOWLK_LSB                                           16
#define SYNTH2_CPLOWLK_MASK                                          0x00010000
#define SYNTH2_CPLOWLK_GET(x)                                        (((x) & SYNTH2_CPLOWLK_MASK) >> SYNTH2_CPLOWLK_LSB)
#define SYNTH2_CPLOWLK_SET(x)                                        (((0 | (x)) << SYNTH2_CPLOWLK_LSB) & SYNTH2_CPLOWLK_MASK)
#define SYNTH2_CPLOWLK_RESET                                         0
#define SYNTH2_LOOPLEAKCUR_MSB                                       15
#define SYNTH2_LOOPLEAKCUR_LSB                                       12
#define SYNTH2_LOOPLEAKCUR_MASK                                      0x0000f000
#define SYNTH2_LOOPLEAKCUR_GET(x)                                    (((x) & SYNTH2_LOOPLEAKCUR_MASK) >> SYNTH2_LOOPLEAKCUR_LSB)
#define SYNTH2_LOOPLEAKCUR_SET(x)                                    (((0 | (x)) << SYNTH2_LOOPLEAKCUR_LSB) & SYNTH2_LOOPLEAKCUR_MASK)
#define SYNTH2_LOOPLEAKCUR_RESET                                     0
#define SYNTH2_CAPRANGE1_MSB                                         11
#define SYNTH2_CAPRANGE1_LSB                                         8
#define SYNTH2_CAPRANGE1_MASK                                        0x00000f00
#define SYNTH2_CAPRANGE1_GET(x)                                      (((x) & SYNTH2_CAPRANGE1_MASK) >> SYNTH2_CAPRANGE1_LSB)
#define SYNTH2_CAPRANGE1_SET(x)                                      (((0 | (x)) << SYNTH2_CAPRANGE1_LSB) & SYNTH2_CAPRANGE1_MASK)
#define SYNTH2_CAPRANGE1_RESET                                       4
#define SYNTH2_CAPRANGE2_MSB                                         7
#define SYNTH2_CAPRANGE2_LSB                                         4
#define SYNTH2_CAPRANGE2_MASK                                        0x000000f0
#define SYNTH2_CAPRANGE2_GET(x)                                      (((x) & SYNTH2_CAPRANGE2_MASK) >> SYNTH2_CAPRANGE2_LSB)
#define SYNTH2_CAPRANGE2_SET(x)                                      (((0 | (x)) << SYNTH2_CAPRANGE2_LSB) & SYNTH2_CAPRANGE2_MASK)
#define SYNTH2_CAPRANGE2_RESET                                       8
#define SYNTH2_CAPRANGE3_MSB                                         3
#define SYNTH2_CAPRANGE3_LSB                                         0
#define SYNTH2_CAPRANGE3_MASK                                        0x0000000f
#define SYNTH2_CAPRANGE3_GET(x)                                      (((x) & SYNTH2_CAPRANGE3_MASK) >> SYNTH2_CAPRANGE3_LSB)
#define SYNTH2_CAPRANGE3_SET(x)                                      (((0 | (x)) << SYNTH2_CAPRANGE3_LSB) & SYNTH2_CAPRANGE3_MASK)
#define SYNTH2_CAPRANGE3_RESET                                       12
#define SYNTH2_ADDRESS                                               0x004c
#define SYNTH2_HW_MASK                                               0xffffffff
#define SYNTH2_SW_MASK                                               0xffffffff
#define SYNTH2_HW_WRITE_MASK                                         0x00000000
#define SYNTH2_SW_WRITE_MASK                                         0xffffffff
#define SYNTH2_RSTMASK                                               0xffffffff
#define SYNTH2_RESET                                                 0x0e4e048c

// 0x0050 (SYNTH3)
#define SYNTH3_DIS_CLK_XTAL_MSB                                      31
#define SYNTH3_DIS_CLK_XTAL_LSB                                      31
#define SYNTH3_DIS_CLK_XTAL_MASK                                     0x80000000
#define SYNTH3_DIS_CLK_XTAL_GET(x)                                   (((x) & SYNTH3_DIS_CLK_XTAL_MASK) >> SYNTH3_DIS_CLK_XTAL_LSB)
#define SYNTH3_DIS_CLK_XTAL_SET(x)                                   (((0 | (x)) << SYNTH3_DIS_CLK_XTAL_LSB) & SYNTH3_DIS_CLK_XTAL_MASK)
#define SYNTH3_DIS_CLK_XTAL_RESET                                    0
#define SYNTH3_SEL_CLK_DIV2_MSB                                      30
#define SYNTH3_SEL_CLK_DIV2_LSB                                      30
#define SYNTH3_SEL_CLK_DIV2_MASK                                     0x40000000
#define SYNTH3_SEL_CLK_DIV2_GET(x)                                   (((x) & SYNTH3_SEL_CLK_DIV2_MASK) >> SYNTH3_SEL_CLK_DIV2_LSB)
#define SYNTH3_SEL_CLK_DIV2_SET(x)                                   (((0 | (x)) << SYNTH3_SEL_CLK_DIV2_LSB) & SYNTH3_SEL_CLK_DIV2_MASK)
#define SYNTH3_SEL_CLK_DIV2_RESET                                    1
#define SYNTH3_WAIT_SHORTR_PWRUP_MSB                                 29
#define SYNTH3_WAIT_SHORTR_PWRUP_LSB                                 24
#define SYNTH3_WAIT_SHORTR_PWRUP_MASK                                0x3f000000
#define SYNTH3_WAIT_SHORTR_PWRUP_GET(x)                              (((x) & SYNTH3_WAIT_SHORTR_PWRUP_MASK) >> SYNTH3_WAIT_SHORTR_PWRUP_LSB)
#define SYNTH3_WAIT_SHORTR_PWRUP_SET(x)                              (((0 | (x)) << SYNTH3_WAIT_SHORTR_PWRUP_LSB) & SYNTH3_WAIT_SHORTR_PWRUP_MASK)
#define SYNTH3_WAIT_SHORTR_PWRUP_RESET                               20
#define SYNTH3_WAIT_PWRUP_MSB                                        23
#define SYNTH3_WAIT_PWRUP_LSB                                        18
#define SYNTH3_WAIT_PWRUP_MASK                                       0x00fc0000
#define SYNTH3_WAIT_PWRUP_GET(x)                                     (((x) & SYNTH3_WAIT_PWRUP_MASK) >> SYNTH3_WAIT_PWRUP_LSB)
#define SYNTH3_WAIT_PWRUP_SET(x)                                     (((0 | (x)) << SYNTH3_WAIT_PWRUP_LSB) & SYNTH3_WAIT_PWRUP_MASK)
#define SYNTH3_WAIT_PWRUP_RESET                                      8
#define SYNTH3_WAIT_CAL_BIN_MSB                                      17
#define SYNTH3_WAIT_CAL_BIN_LSB                                      12
#define SYNTH3_WAIT_CAL_BIN_MASK                                     0x0003f000
#define SYNTH3_WAIT_CAL_BIN_GET(x)                                   (((x) & SYNTH3_WAIT_CAL_BIN_MASK) >> SYNTH3_WAIT_CAL_BIN_LSB)
#define SYNTH3_WAIT_CAL_BIN_SET(x)                                   (((0 | (x)) << SYNTH3_WAIT_CAL_BIN_LSB) & SYNTH3_WAIT_CAL_BIN_MASK)
#define SYNTH3_WAIT_CAL_BIN_RESET                                    20
#define SYNTH3_WAIT_CAL_LIN_MSB                                      11
#define SYNTH3_WAIT_CAL_LIN_LSB                                      6
#define SYNTH3_WAIT_CAL_LIN_MASK                                     0x00000fc0
#define SYNTH3_WAIT_CAL_LIN_GET(x)                                   (((x) & SYNTH3_WAIT_CAL_LIN_MASK) >> SYNTH3_WAIT_CAL_LIN_LSB)
#define SYNTH3_WAIT_CAL_LIN_SET(x)                                   (((0 | (x)) << SYNTH3_WAIT_CAL_LIN_LSB) & SYNTH3_WAIT_CAL_LIN_MASK)
#define SYNTH3_WAIT_CAL_LIN_RESET                                    20
#define SYNTH3_WAIT_VC_CHECK_MSB                                     5
#define SYNTH3_WAIT_VC_CHECK_LSB                                     0
#define SYNTH3_WAIT_VC_CHECK_MASK                                    0x0000003f
#define SYNTH3_WAIT_VC_CHECK_GET(x)                                  (((x) & SYNTH3_WAIT_VC_CHECK_MASK) >> SYNTH3_WAIT_VC_CHECK_LSB)
#define SYNTH3_WAIT_VC_CHECK_SET(x)                                  (((0 | (x)) << SYNTH3_WAIT_VC_CHECK_LSB) & SYNTH3_WAIT_VC_CHECK_MASK)
#define SYNTH3_WAIT_VC_CHECK_RESET                                   20
#define SYNTH3_ADDRESS                                               0x0050
#define SYNTH3_HW_MASK                                               0xffffffff
#define SYNTH3_SW_MASK                                               0xffffffff
#define SYNTH3_HW_WRITE_MASK                                         0x00000000
#define SYNTH3_SW_WRITE_MASK                                         0xffffffff
#define SYNTH3_RSTMASK                                               0xffffffff
#define SYNTH3_RESET                                                 0x54214514

// 0x0054 (SYNTH4)
#define SYNTH4_DIS_LIN_CAPSEARCH_MSB                                 31
#define SYNTH4_DIS_LIN_CAPSEARCH_LSB                                 31
#define SYNTH4_DIS_LIN_CAPSEARCH_MASK                                0x80000000
#define SYNTH4_DIS_LIN_CAPSEARCH_GET(x)                              (((x) & SYNTH4_DIS_LIN_CAPSEARCH_MASK) >> SYNTH4_DIS_LIN_CAPSEARCH_LSB)
#define SYNTH4_DIS_LIN_CAPSEARCH_SET(x)                              (((0 | (x)) << SYNTH4_DIS_LIN_CAPSEARCH_LSB) & SYNTH4_DIS_LIN_CAPSEARCH_MASK)
#define SYNTH4_DIS_LIN_CAPSEARCH_RESET                               0
#define SYNTH4_DIS_LOSTVC_MSB                                        30
#define SYNTH4_DIS_LOSTVC_LSB                                        30
#define SYNTH4_DIS_LOSTVC_MASK                                       0x40000000
#define SYNTH4_DIS_LOSTVC_GET(x)                                     (((x) & SYNTH4_DIS_LOSTVC_MASK) >> SYNTH4_DIS_LOSTVC_LSB)
#define SYNTH4_DIS_LOSTVC_SET(x)                                     (((0 | (x)) << SYNTH4_DIS_LOSTVC_LSB) & SYNTH4_DIS_LOSTVC_MASK)
#define SYNTH4_DIS_LOSTVC_RESET                                      0
#define SYNTH4_ALWAYS_SHORTR_MSB                                     29
#define SYNTH4_ALWAYS_SHORTR_LSB                                     29
#define SYNTH4_ALWAYS_SHORTR_MASK                                    0x20000000
#define SYNTH4_ALWAYS_SHORTR_GET(x)                                  (((x) & SYNTH4_ALWAYS_SHORTR_MASK) >> SYNTH4_ALWAYS_SHORTR_LSB)
#define SYNTH4_ALWAYS_SHORTR_SET(x)                                  (((0 | (x)) << SYNTH4_ALWAYS_SHORTR_LSB) & SYNTH4_ALWAYS_SHORTR_MASK)
#define SYNTH4_ALWAYS_SHORTR_RESET                                   0
#define SYNTH4_SHORTR_UNTIL_LOCKED_MSB                               28
#define SYNTH4_SHORTR_UNTIL_LOCKED_LSB                               28
#define SYNTH4_SHORTR_UNTIL_LOCKED_MASK                              0x10000000
#define SYNTH4_SHORTR_UNTIL_LOCKED_GET(x)                            (((x) & SYNTH4_SHORTR_UNTIL_LOCKED_MASK) >> SYNTH4_SHORTR_UNTIL_LOCKED_LSB)
#define SYNTH4_SHORTR_UNTIL_LOCKED_SET(x)                            (((0 | (x)) << SYNTH4_SHORTR_UNTIL_LOCKED_LSB) & SYNTH4_SHORTR_UNTIL_LOCKED_MASK)
#define SYNTH4_SHORTR_UNTIL_LOCKED_RESET                             1
#define SYNTH4_FORCE_PINVC_MSB                                       27
#define SYNTH4_FORCE_PINVC_LSB                                       27
#define SYNTH4_FORCE_PINVC_MASK                                      0x08000000
#define SYNTH4_FORCE_PINVC_GET(x)                                    (((x) & SYNTH4_FORCE_PINVC_MASK) >> SYNTH4_FORCE_PINVC_LSB)
#define SYNTH4_FORCE_PINVC_SET(x)                                    (((0 | (x)) << SYNTH4_FORCE_PINVC_LSB) & SYNTH4_FORCE_PINVC_MASK)
#define SYNTH4_FORCE_PINVC_RESET                                     0
#define SYNTH4_FORCE_VCOCAP_MSB                                      26
#define SYNTH4_FORCE_VCOCAP_LSB                                      26
#define SYNTH4_FORCE_VCOCAP_MASK                                     0x04000000
#define SYNTH4_FORCE_VCOCAP_GET(x)                                   (((x) & SYNTH4_FORCE_VCOCAP_MASK) >> SYNTH4_FORCE_VCOCAP_LSB)
#define SYNTH4_FORCE_VCOCAP_SET(x)                                   (((0 | (x)) << SYNTH4_FORCE_VCOCAP_LSB) & SYNTH4_FORCE_VCOCAP_MASK)
#define SYNTH4_FORCE_VCOCAP_RESET                                    0
#define SYNTH4_VCOCAP_OVR_MSB                                        25
#define SYNTH4_VCOCAP_OVR_LSB                                        18
#define SYNTH4_VCOCAP_OVR_MASK                                       0x03fc0000
#define SYNTH4_VCOCAP_OVR_GET(x)                                     (((x) & SYNTH4_VCOCAP_OVR_MASK) >> SYNTH4_VCOCAP_OVR_LSB)
#define SYNTH4_VCOCAP_OVR_SET(x)                                     (((0 | (x)) << SYNTH4_VCOCAP_OVR_LSB) & SYNTH4_VCOCAP_OVR_MASK)
#define SYNTH4_VCOCAP_OVR_RESET                                      128
#define SYNTH4_VCOCAPPULLUP_MSB                                      17
#define SYNTH4_VCOCAPPULLUP_LSB                                      17
#define SYNTH4_VCOCAPPULLUP_MASK                                     0x00020000
#define SYNTH4_VCOCAPPULLUP_GET(x)                                   (((x) & SYNTH4_VCOCAPPULLUP_MASK) >> SYNTH4_VCOCAPPULLUP_LSB)
#define SYNTH4_VCOCAPPULLUP_SET(x)                                   (((0 | (x)) << SYNTH4_VCOCAPPULLUP_LSB) & SYNTH4_VCOCAPPULLUP_MASK)
#define SYNTH4_VCOCAPPULLUP_RESET                                    1
#define SYNTH4_CLKXTAL_EDGE_SEL_MSB                                  16
#define SYNTH4_CLKXTAL_EDGE_SEL_LSB                                  16
#define SYNTH4_CLKXTAL_EDGE_SEL_MASK                                 0x00010000
#define SYNTH4_CLKXTAL_EDGE_SEL_GET(x)                               (((x) & SYNTH4_CLKXTAL_EDGE_SEL_MASK) >> SYNTH4_CLKXTAL_EDGE_SEL_LSB)
#define SYNTH4_CLKXTAL_EDGE_SEL_SET(x)                               (((0 | (x)) << SYNTH4_CLKXTAL_EDGE_SEL_LSB) & SYNTH4_CLKXTAL_EDGE_SEL_MASK)
#define SYNTH4_CLKXTAL_EDGE_SEL_RESET                                0
#define SYNTH4_FORCE_LO_ON_MSB                                       15
#define SYNTH4_FORCE_LO_ON_LSB                                       15
#define SYNTH4_FORCE_LO_ON_MASK                                      0x00008000
#define SYNTH4_FORCE_LO_ON_GET(x)                                    (((x) & SYNTH4_FORCE_LO_ON_MASK) >> SYNTH4_FORCE_LO_ON_LSB)
#define SYNTH4_FORCE_LO_ON_SET(x)                                    (((0 | (x)) << SYNTH4_FORCE_LO_ON_LSB) & SYNTH4_FORCE_LO_ON_MASK)
#define SYNTH4_FORCE_LO_ON_RESET                                     0
#define SYNTH4_PFDDELAY_FRACN_MSB                                    14
#define SYNTH4_PFDDELAY_FRACN_LSB                                    14
#define SYNTH4_PFDDELAY_FRACN_MASK                                   0x00004000
#define SYNTH4_PFDDELAY_FRACN_GET(x)                                 (((x) & SYNTH4_PFDDELAY_FRACN_MASK) >> SYNTH4_PFDDELAY_FRACN_LSB)
#define SYNTH4_PFDDELAY_FRACN_SET(x)                                 (((0 | (x)) << SYNTH4_PFDDELAY_FRACN_LSB) & SYNTH4_PFDDELAY_FRACN_MASK)
#define SYNTH4_PFDDELAY_FRACN_RESET                                  1
#define SYNTH4_PFD_DISABLE_MSB                                       13
#define SYNTH4_PFD_DISABLE_LSB                                       13
#define SYNTH4_PFD_DISABLE_MASK                                      0x00002000
#define SYNTH4_PFD_DISABLE_GET(x)                                    (((x) & SYNTH4_PFD_DISABLE_MASK) >> SYNTH4_PFD_DISABLE_LSB)
#define SYNTH4_PFD_DISABLE_SET(x)                                    (((0 | (x)) << SYNTH4_PFD_DISABLE_LSB) & SYNTH4_PFD_DISABLE_MASK)
#define SYNTH4_PFD_DISABLE_RESET                                     0
#define SYNTH4_PRESCSEL_MSB                                          12
#define SYNTH4_PRESCSEL_LSB                                          11
#define SYNTH4_PRESCSEL_MASK                                         0x00001800
#define SYNTH4_PRESCSEL_GET(x)                                       (((x) & SYNTH4_PRESCSEL_MASK) >> SYNTH4_PRESCSEL_LSB)
#define SYNTH4_PRESCSEL_SET(x)                                       (((0 | (x)) << SYNTH4_PRESCSEL_LSB) & SYNTH4_PRESCSEL_MASK)
#define SYNTH4_PRESCSEL_RESET                                        3
#define SYNTH4_RESET_PRESC_MSB                                       10
#define SYNTH4_RESET_PRESC_LSB                                       10
#define SYNTH4_RESET_PRESC_MASK                                      0x00000400
#define SYNTH4_RESET_PRESC_GET(x)                                    (((x) & SYNTH4_RESET_PRESC_MASK) >> SYNTH4_RESET_PRESC_LSB)
#define SYNTH4_RESET_PRESC_SET(x)                                    (((0 | (x)) << SYNTH4_RESET_PRESC_LSB) & SYNTH4_RESET_PRESC_MASK)
#define SYNTH4_RESET_PRESC_RESET                                     0
#define SYNTH4_SDM_DISABLE_MSB                                       9
#define SYNTH4_SDM_DISABLE_LSB                                       9
#define SYNTH4_SDM_DISABLE_MASK                                      0x00000200
#define SYNTH4_SDM_DISABLE_GET(x)                                    (((x) & SYNTH4_SDM_DISABLE_MASK) >> SYNTH4_SDM_DISABLE_LSB)
#define SYNTH4_SDM_DISABLE_SET(x)                                    (((0 | (x)) << SYNTH4_SDM_DISABLE_LSB) & SYNTH4_SDM_DISABLE_MASK)
#define SYNTH4_SDM_DISABLE_RESET                                     0
#define SYNTH4_SDM_MODE_MSB                                          8
#define SYNTH4_SDM_MODE_LSB                                          8
#define SYNTH4_SDM_MODE_MASK                                         0x00000100
#define SYNTH4_SDM_MODE_GET(x)                                       (((x) & SYNTH4_SDM_MODE_MASK) >> SYNTH4_SDM_MODE_LSB)
#define SYNTH4_SDM_MODE_SET(x)                                       (((0 | (x)) << SYNTH4_SDM_MODE_LSB) & SYNTH4_SDM_MODE_MASK)
#define SYNTH4_SDM_MODE_RESET                                        0
#define SYNTH4_SDM_DITHER_MSB                                        7
#define SYNTH4_SDM_DITHER_LSB                                        6
#define SYNTH4_SDM_DITHER_MASK                                       0x000000c0
#define SYNTH4_SDM_DITHER_GET(x)                                     (((x) & SYNTH4_SDM_DITHER_MASK) >> SYNTH4_SDM_DITHER_LSB)
#define SYNTH4_SDM_DITHER_SET(x)                                     (((0 | (x)) << SYNTH4_SDM_DITHER_LSB) & SYNTH4_SDM_DITHER_MASK)
#define SYNTH4_SDM_DITHER_RESET                                      0
#define SYNTH4_PSCOUNT_FBSEL_MSB                                     5
#define SYNTH4_PSCOUNT_FBSEL_LSB                                     5
#define SYNTH4_PSCOUNT_FBSEL_MASK                                    0x00000020
#define SYNTH4_PSCOUNT_FBSEL_GET(x)                                  (((x) & SYNTH4_PSCOUNT_FBSEL_MASK) >> SYNTH4_PSCOUNT_FBSEL_LSB)
#define SYNTH4_PSCOUNT_FBSEL_SET(x)                                  (((0 | (x)) << SYNTH4_PSCOUNT_FBSEL_LSB) & SYNTH4_PSCOUNT_FBSEL_MASK)
#define SYNTH4_PSCOUNT_FBSEL_RESET                                   0
#define SYNTH4_FORCE_LOBUF5GTUNE_MSB                                 4
#define SYNTH4_FORCE_LOBUF5GTUNE_LSB                                 4
#define SYNTH4_FORCE_LOBUF5GTUNE_MASK                                0x00000010
#define SYNTH4_FORCE_LOBUF5GTUNE_GET(x)                              (((x) & SYNTH4_FORCE_LOBUF5GTUNE_MASK) >> SYNTH4_FORCE_LOBUF5GTUNE_LSB)
#define SYNTH4_FORCE_LOBUF5GTUNE_SET(x)                              (((0 | (x)) << SYNTH4_FORCE_LOBUF5GTUNE_LSB) & SYNTH4_FORCE_LOBUF5GTUNE_MASK)
#define SYNTH4_FORCE_LOBUF5GTUNE_RESET                               0
#define SYNTH4_LOBUF5GTUNE_OVR_MSB                                   3
#define SYNTH4_LOBUF5GTUNE_OVR_LSB                                   2
#define SYNTH4_LOBUF5GTUNE_OVR_MASK                                  0x0000000c
#define SYNTH4_LOBUF5GTUNE_OVR_GET(x)                                (((x) & SYNTH4_LOBUF5GTUNE_OVR_MASK) >> SYNTH4_LOBUF5GTUNE_OVR_LSB)
#define SYNTH4_LOBUF5GTUNE_OVR_SET(x)                                (((0 | (x)) << SYNTH4_LOBUF5GTUNE_OVR_LSB) & SYNTH4_LOBUF5GTUNE_OVR_MASK)
#define SYNTH4_LOBUF5GTUNE_OVR_RESET                                 2
#define SYNTH4_LONGSHIFTSEL_MSB                                      1
#define SYNTH4_LONGSHIFTSEL_LSB                                      1
#define SYNTH4_LONGSHIFTSEL_MASK                                     0x00000002
#define SYNTH4_LONGSHIFTSEL_GET(x)                                   (((x) & SYNTH4_LONGSHIFTSEL_MASK) >> SYNTH4_LONGSHIFTSEL_LSB)
#define SYNTH4_LONGSHIFTSEL_SET(x)                                   (((0 | (x)) << SYNTH4_LONGSHIFTSEL_LSB) & SYNTH4_LONGSHIFTSEL_MASK)
#define SYNTH4_LONGSHIFTSEL_RESET                                    0
#define SYNTH4_FORCE_SHIFTREG_MSB                                    0
#define SYNTH4_FORCE_SHIFTREG_LSB                                    0
#define SYNTH4_FORCE_SHIFTREG_MASK                                   0x00000001
#define SYNTH4_FORCE_SHIFTREG_GET(x)                                 (((x) & SYNTH4_FORCE_SHIFTREG_MASK) >> SYNTH4_FORCE_SHIFTREG_LSB)
#define SYNTH4_FORCE_SHIFTREG_SET(x)                                 (((0 | (x)) << SYNTH4_FORCE_SHIFTREG_LSB) & SYNTH4_FORCE_SHIFTREG_MASK)
#define SYNTH4_FORCE_SHIFTREG_RESET                                  0
#define SYNTH4_ADDRESS                                               0x0054
#define SYNTH4_HW_MASK                                               0xffffffff
#define SYNTH4_SW_MASK                                               0xffffffff
#define SYNTH4_HW_WRITE_MASK                                         0x00000000
#define SYNTH4_SW_WRITE_MASK                                         0xffffffff
#define SYNTH4_RSTMASK                                               0xffffffff
#define SYNTH4_RESET                                                 0x12025808

// 0x0058 (SYNTH5)
#define SYNTH5_IRCP_MSB                                              31
#define SYNTH5_IRCP_LSB                                              29
#define SYNTH5_IRCP_MASK                                             0xe0000000
#define SYNTH5_IRCP_GET(x)                                           (((x) & SYNTH5_IRCP_MASK) >> SYNTH5_IRCP_LSB)
#define SYNTH5_IRCP_SET(x)                                           (((0 | (x)) << SYNTH5_IRCP_LSB) & SYNTH5_IRCP_MASK)
#define SYNTH5_IRCP_RESET                                            4
#define SYNTH5_IRVCMON_MSB                                           28
#define SYNTH5_IRVCMON_LSB                                           26
#define SYNTH5_IRVCMON_MASK                                          0x1c000000
#define SYNTH5_IRVCMON_GET(x)                                        (((x) & SYNTH5_IRVCMON_MASK) >> SYNTH5_IRVCMON_LSB)
#define SYNTH5_IRVCMON_SET(x)                                        (((0 | (x)) << SYNTH5_IRVCMON_LSB) & SYNTH5_IRVCMON_MASK)
#define SYNTH5_IRVCMON_RESET                                         4
#define SYNTH5_IRLOPKDET_MSB                                         25
#define SYNTH5_IRLOPKDET_LSB                                         23
#define SYNTH5_IRLOPKDET_MASK                                        0x03800000
#define SYNTH5_IRLOPKDET_GET(x)                                      (((x) & SYNTH5_IRLOPKDET_MASK) >> SYNTH5_IRLOPKDET_LSB)
#define SYNTH5_IRLOPKDET_SET(x)                                      (((0 | (x)) << SYNTH5_IRLOPKDET_LSB) & SYNTH5_IRLOPKDET_MASK)
#define SYNTH5_IRLOPKDET_RESET                                       4
#define SYNTH5_ICPRESC_MSB                                           22
#define SYNTH5_ICPRESC_LSB                                           20
#define SYNTH5_ICPRESC_MASK                                          0x00700000
#define SYNTH5_ICPRESC_GET(x)                                        (((x) & SYNTH5_ICPRESC_MASK) >> SYNTH5_ICPRESC_LSB)
#define SYNTH5_ICPRESC_SET(x)                                        (((0 | (x)) << SYNTH5_ICPRESC_LSB) & SYNTH5_ICPRESC_MASK)
#define SYNTH5_ICPRESC_RESET                                         4
#define SYNTH5_ICLODIV_MSB                                           19
#define SYNTH5_ICLODIV_LSB                                           17
#define SYNTH5_ICLODIV_MASK                                          0x000e0000
#define SYNTH5_ICLODIV_GET(x)                                        (((x) & SYNTH5_ICLODIV_MASK) >> SYNTH5_ICLODIV_LSB)
#define SYNTH5_ICLODIV_SET(x)                                        (((0 | (x)) << SYNTH5_ICLODIV_LSB) & SYNTH5_ICLODIV_MASK)
#define SYNTH5_ICLODIV_RESET                                         4
#define SYNTH5_ICLOMIX_MSB                                           16
#define SYNTH5_ICLOMIX_LSB                                           14
#define SYNTH5_ICLOMIX_MASK                                          0x0001c000
#define SYNTH5_ICLOMIX_GET(x)                                        (((x) & SYNTH5_ICLOMIX_MASK) >> SYNTH5_ICLOMIX_LSB)
#define SYNTH5_ICLOMIX_SET(x)                                        (((0 | (x)) << SYNTH5_ICLOMIX_LSB) & SYNTH5_ICLOMIX_MASK)
#define SYNTH5_ICLOMIX_RESET                                         4
#define SYNTH5_ICVCOREG_MSB                                          13
#define SYNTH5_ICVCOREG_LSB                                          11
#define SYNTH5_ICVCOREG_MASK                                         0x00003800
#define SYNTH5_ICVCOREG_GET(x)                                       (((x) & SYNTH5_ICVCOREG_MASK) >> SYNTH5_ICVCOREG_LSB)
#define SYNTH5_ICVCOREG_SET(x)                                       (((0 | (x)) << SYNTH5_ICVCOREG_LSB) & SYNTH5_ICVCOREG_MASK)
#define SYNTH5_ICVCOREG_RESET                                        4
#define SYNTH5_ICVCO_MSB                                             10
#define SYNTH5_ICVCO_LSB                                             8
#define SYNTH5_ICVCO_MASK                                            0x00000700
#define SYNTH5_ICVCO_GET(x)                                          (((x) & SYNTH5_ICVCO_MASK) >> SYNTH5_ICVCO_LSB)
#define SYNTH5_ICVCO_SET(x)                                          (((0 | (x)) << SYNTH5_ICVCO_LSB) & SYNTH5_ICVCO_MASK)
#define SYNTH5_ICVCO_RESET                                           4
#define SYNTH5_ICLOBUF2G_MSB                                         7
#define SYNTH5_ICLOBUF2G_LSB                                         5
#define SYNTH5_ICLOBUF2G_MASK                                        0x000000e0
#define SYNTH5_ICLOBUF2G_GET(x)                                      (((x) & SYNTH5_ICLOBUF2G_MASK) >> SYNTH5_ICLOBUF2G_LSB)
#define SYNTH5_ICLOBUF2G_SET(x)                                      (((0 | (x)) << SYNTH5_ICLOBUF2G_LSB) & SYNTH5_ICLOBUF2G_MASK)
#define SYNTH5_ICLOBUF2G_RESET                                       4
#define SYNTH5_ICLOBUF5G_MSB                                         4
#define SYNTH5_ICLOBUF5G_LSB                                         2
#define SYNTH5_ICLOBUF5G_MASK                                        0x0000001c
#define SYNTH5_ICLOBUF5G_GET(x)                                      (((x) & SYNTH5_ICLOBUF5G_MASK) >> SYNTH5_ICLOBUF5G_LSB)
#define SYNTH5_ICLOBUF5G_SET(x)                                      (((0 | (x)) << SYNTH5_ICLOBUF5G_LSB) & SYNTH5_ICLOBUF5G_MASK)
#define SYNTH5_ICLOBUF5G_RESET                                       4
#define SYNTH5_ICPKCOMP_MSB                                          1
#define SYNTH5_ICPKCOMP_LSB                                          0
#define SYNTH5_ICPKCOMP_MASK                                         0x00000003
#define SYNTH5_ICPKCOMP_GET(x)                                       (((x) & SYNTH5_ICPKCOMP_MASK) >> SYNTH5_ICPKCOMP_LSB)
#define SYNTH5_ICPKCOMP_SET(x)                                       (((0 | (x)) << SYNTH5_ICPKCOMP_LSB) & SYNTH5_ICPKCOMP_MASK)
#define SYNTH5_ICPKCOMP_RESET                                        2
#define SYNTH5_ADDRESS                                               0x0058
#define SYNTH5_HW_MASK                                               0xffffffff
#define SYNTH5_SW_MASK                                               0xffffffff
#define SYNTH5_HW_WRITE_MASK                                         0x00000000
#define SYNTH5_SW_WRITE_MASK                                         0xffffffff
#define SYNTH5_RSTMASK                                               0xffffffff
#define SYNTH5_RESET                                                 0x92492492

// 0x005c (SYNTH6)
#define SYNTH6_SYNTH_ON_MSB                                          31
#define SYNTH6_SYNTH_ON_LSB                                          31
#define SYNTH6_SYNTH_ON_MASK                                         0x80000000
#define SYNTH6_SYNTH_ON_GET(x)                                       (((x) & SYNTH6_SYNTH_ON_MASK) >> SYNTH6_SYNTH_ON_LSB)
#define SYNTH6_SYNTH_ON_SET(x)                                       (((0 | (x)) << SYNTH6_SYNTH_ON_LSB) & SYNTH6_SYNTH_ON_MASK)
#define SYNTH6_SYNTH_ON_RESET                                        0
#define SYNTH6_SYNTH_SM_STATE_MSB                                    30
#define SYNTH6_SYNTH_SM_STATE_LSB                                    27
#define SYNTH6_SYNTH_SM_STATE_MASK                                   0x78000000
#define SYNTH6_SYNTH_SM_STATE_GET(x)                                 (((x) & SYNTH6_SYNTH_SM_STATE_MASK) >> SYNTH6_SYNTH_SM_STATE_LSB)
#define SYNTH6_SYNTH_SM_STATE_SET(x)                                 (((0 | (x)) << SYNTH6_SYNTH_SM_STATE_LSB) & SYNTH6_SYNTH_SM_STATE_MASK)
#define SYNTH6_SYNTH_SM_STATE_RESET                                  0
#define SYNTH6_CAP_SEARCH_MSB                                        26
#define SYNTH6_CAP_SEARCH_LSB                                        26
#define SYNTH6_CAP_SEARCH_MASK                                       0x04000000
#define SYNTH6_CAP_SEARCH_GET(x)                                     (((x) & SYNTH6_CAP_SEARCH_MASK) >> SYNTH6_CAP_SEARCH_LSB)
#define SYNTH6_CAP_SEARCH_SET(x)                                     (((0 | (x)) << SYNTH6_CAP_SEARCH_LSB) & SYNTH6_CAP_SEARCH_MASK)
#define SYNTH6_CAP_SEARCH_RESET                                      0
#define SYNTH6_SYNTH_LOCK_VC_OK_MSB                                  25
#define SYNTH6_SYNTH_LOCK_VC_OK_LSB                                  25
#define SYNTH6_SYNTH_LOCK_VC_OK_MASK                                 0x02000000
#define SYNTH6_SYNTH_LOCK_VC_OK_GET(x)                               (((x) & SYNTH6_SYNTH_LOCK_VC_OK_MASK) >> SYNTH6_SYNTH_LOCK_VC_OK_LSB)
#define SYNTH6_SYNTH_LOCK_VC_OK_SET(x)                               (((0 | (x)) << SYNTH6_SYNTH_LOCK_VC_OK_LSB) & SYNTH6_SYNTH_LOCK_VC_OK_MASK)
#define SYNTH6_SYNTH_LOCK_VC_OK_RESET                                0
#define SYNTH6_PIN_VC_MSB                                            24
#define SYNTH6_PIN_VC_LSB                                            24
#define SYNTH6_PIN_VC_MASK                                           0x01000000
#define SYNTH6_PIN_VC_GET(x)                                         (((x) & SYNTH6_PIN_VC_MASK) >> SYNTH6_PIN_VC_LSB)
#define SYNTH6_PIN_VC_SET(x)                                         (((0 | (x)) << SYNTH6_PIN_VC_LSB) & SYNTH6_PIN_VC_MASK)
#define SYNTH6_PIN_VC_RESET                                          0
#define SYNTH6_VCO_CAP_ST_MSB                                        23
#define SYNTH6_VCO_CAP_ST_LSB                                        16
#define SYNTH6_VCO_CAP_ST_MASK                                       0x00ff0000
#define SYNTH6_VCO_CAP_ST_GET(x)                                     (((x) & SYNTH6_VCO_CAP_ST_MASK) >> SYNTH6_VCO_CAP_ST_LSB)
#define SYNTH6_VCO_CAP_ST_SET(x)                                     (((0 | (x)) << SYNTH6_VCO_CAP_ST_LSB) & SYNTH6_VCO_CAP_ST_MASK)
#define SYNTH6_VCO_CAP_ST_RESET                                      0
#define SYNTH6_SHORT_R_MSB                                           15
#define SYNTH6_SHORT_R_LSB                                           15
#define SYNTH6_SHORT_R_MASK                                          0x00008000
#define SYNTH6_SHORT_R_GET(x)                                        (((x) & SYNTH6_SHORT_R_MASK) >> SYNTH6_SHORT_R_LSB)
#define SYNTH6_SHORT_R_SET(x)                                        (((0 | (x)) << SYNTH6_SHORT_R_LSB) & SYNTH6_SHORT_R_MASK)
#define SYNTH6_SHORT_R_RESET                                         0
#define SYNTH6_RESET_RFD_MSB                                         14
#define SYNTH6_RESET_RFD_LSB                                         14
#define SYNTH6_RESET_RFD_MASK                                        0x00004000
#define SYNTH6_RESET_RFD_GET(x)                                      (((x) & SYNTH6_RESET_RFD_MASK) >> SYNTH6_RESET_RFD_LSB)
#define SYNTH6_RESET_RFD_SET(x)                                      (((0 | (x)) << SYNTH6_RESET_RFD_LSB) & SYNTH6_RESET_RFD_MASK)
#define SYNTH6_RESET_RFD_RESET                                       0
#define SYNTH6_RESET_PFD_MSB                                         13
#define SYNTH6_RESET_PFD_LSB                                         13
#define SYNTH6_RESET_PFD_MASK                                        0x00002000
#define SYNTH6_RESET_PFD_GET(x)                                      (((x) & SYNTH6_RESET_PFD_MASK) >> SYNTH6_RESET_PFD_LSB)
#define SYNTH6_RESET_PFD_SET(x)                                      (((0 | (x)) << SYNTH6_RESET_PFD_LSB) & SYNTH6_RESET_PFD_MASK)
#define SYNTH6_RESET_PFD_RESET                                       0
#define SYNTH6_RESET_PSCOUNTERS_MSB                                  12
#define SYNTH6_RESET_PSCOUNTERS_LSB                                  12
#define SYNTH6_RESET_PSCOUNTERS_MASK                                 0x00001000
#define SYNTH6_RESET_PSCOUNTERS_GET(x)                               (((x) & SYNTH6_RESET_PSCOUNTERS_MASK) >> SYNTH6_RESET_PSCOUNTERS_LSB)
#define SYNTH6_RESET_PSCOUNTERS_SET(x)                               (((0 | (x)) << SYNTH6_RESET_PSCOUNTERS_LSB) & SYNTH6_RESET_PSCOUNTERS_MASK)
#define SYNTH6_RESET_PSCOUNTERS_RESET                                0
#define SYNTH6_RESET_SDM_B_MSB                                       11
#define SYNTH6_RESET_SDM_B_LSB                                       11
#define SYNTH6_RESET_SDM_B_MASK                                      0x00000800
#define SYNTH6_RESET_SDM_B_GET(x)                                    (((x) & SYNTH6_RESET_SDM_B_MASK) >> SYNTH6_RESET_SDM_B_LSB)
#define SYNTH6_RESET_SDM_B_SET(x)                                    (((0 | (x)) << SYNTH6_RESET_SDM_B_LSB) & SYNTH6_RESET_SDM_B_MASK)
#define SYNTH6_RESET_SDM_B_RESET                                     0
#define SYNTH6_VC2HIGH_MSB                                           10
#define SYNTH6_VC2HIGH_LSB                                           10
#define SYNTH6_VC2HIGH_MASK                                          0x00000400
#define SYNTH6_VC2HIGH_GET(x)                                        (((x) & SYNTH6_VC2HIGH_MASK) >> SYNTH6_VC2HIGH_LSB)
#define SYNTH6_VC2HIGH_SET(x)                                        (((0 | (x)) << SYNTH6_VC2HIGH_LSB) & SYNTH6_VC2HIGH_MASK)
#define SYNTH6_VC2HIGH_RESET                                         0
#define SYNTH6_VC2LOW_MSB                                            9
#define SYNTH6_VC2LOW_LSB                                            9
#define SYNTH6_VC2LOW_MASK                                           0x00000200
#define SYNTH6_VC2LOW_GET(x)                                         (((x) & SYNTH6_VC2LOW_MASK) >> SYNTH6_VC2LOW_LSB)
#define SYNTH6_VC2LOW_SET(x)                                         (((0 | (x)) << SYNTH6_VC2LOW_LSB) & SYNTH6_VC2LOW_MASK)
#define SYNTH6_VC2LOW_RESET                                          0
#define SYNTH6_LOOP_IP_MSB                                           8
#define SYNTH6_LOOP_IP_LSB                                           2
#define SYNTH6_LOOP_IP_MASK                                          0x000001fc
#define SYNTH6_LOOP_IP_GET(x)                                        (((x) & SYNTH6_LOOP_IP_MASK) >> SYNTH6_LOOP_IP_LSB)
#define SYNTH6_LOOP_IP_SET(x)                                        (((0 | (x)) << SYNTH6_LOOP_IP_LSB) & SYNTH6_LOOP_IP_MASK)
#define SYNTH6_LOOP_IP_RESET                                         0
#define SYNTH6_LOBUF5GTUNE_MSB                                       1
#define SYNTH6_LOBUF5GTUNE_LSB                                       0
#define SYNTH6_LOBUF5GTUNE_MASK                                      0x00000003
#define SYNTH6_LOBUF5GTUNE_GET(x)                                    (((x) & SYNTH6_LOBUF5GTUNE_MASK) >> SYNTH6_LOBUF5GTUNE_LSB)
#define SYNTH6_LOBUF5GTUNE_SET(x)                                    (((0 | (x)) << SYNTH6_LOBUF5GTUNE_LSB) & SYNTH6_LOBUF5GTUNE_MASK)
#define SYNTH6_LOBUF5GTUNE_RESET                                     0
#define SYNTH6_ADDRESS                                               0x005c
#define SYNTH6_HW_MASK                                               0xffffffff
#define SYNTH6_SW_MASK                                               0xffffffff
#define SYNTH6_HW_WRITE_MASK                                         0xffffffff
#define SYNTH6_SW_WRITE_MASK                                         0x00000000
#define SYNTH6_RSTMASK                                               0xffffffff
#define SYNTH6_RESET                                                 0x00000000

// 0x0060 (SYNTH7)
#define SYNTH7_LOADSYNTHCHANNEL_MSB                                  31
#define SYNTH7_LOADSYNTHCHANNEL_LSB                                  31
#define SYNTH7_LOADSYNTHCHANNEL_MASK                                 0x80000000
#define SYNTH7_LOADSYNTHCHANNEL_GET(x)                               (((x) & SYNTH7_LOADSYNTHCHANNEL_MASK) >> SYNTH7_LOADSYNTHCHANNEL_LSB)
#define SYNTH7_LOADSYNTHCHANNEL_SET(x)                               (((0 | (x)) << SYNTH7_LOADSYNTHCHANNEL_LSB) & SYNTH7_LOADSYNTHCHANNEL_MASK)
#define SYNTH7_LOADSYNTHCHANNEL_RESET                                0
#define SYNTH7_FRACMODE_MSB                                          30
#define SYNTH7_FRACMODE_LSB                                          30
#define SYNTH7_FRACMODE_MASK                                         0x40000000
#define SYNTH7_FRACMODE_GET(x)                                       (((x) & SYNTH7_FRACMODE_MASK) >> SYNTH7_FRACMODE_LSB)
#define SYNTH7_FRACMODE_SET(x)                                       (((0 | (x)) << SYNTH7_FRACMODE_LSB) & SYNTH7_FRACMODE_MASK)
#define SYNTH7_FRACMODE_RESET                                        0
#define SYNTH7_AMODEREFSEL_MSB                                       29
#define SYNTH7_AMODEREFSEL_LSB                                       28
#define SYNTH7_AMODEREFSEL_MASK                                      0x30000000
#define SYNTH7_AMODEREFSEL_GET(x)                                    (((x) & SYNTH7_AMODEREFSEL_MASK) >> SYNTH7_AMODEREFSEL_LSB)
#define SYNTH7_AMODEREFSEL_SET(x)                                    (((0 | (x)) << SYNTH7_AMODEREFSEL_LSB) & SYNTH7_AMODEREFSEL_MASK)
#define SYNTH7_AMODEREFSEL_RESET                                     0
#define SYNTH7_CHANSEL_MSB                                           27
#define SYNTH7_CHANSEL_LSB                                           19
#define SYNTH7_CHANSEL_MASK                                          0x0ff80000
#define SYNTH7_CHANSEL_GET(x)                                        (((x) & SYNTH7_CHANSEL_MASK) >> SYNTH7_CHANSEL_LSB)
#define SYNTH7_CHANSEL_SET(x)                                        (((0 | (x)) << SYNTH7_CHANSEL_LSB) & SYNTH7_CHANSEL_MASK)
#define SYNTH7_CHANSEL_RESET                                         0
#define SYNTH7_CHANFRAC_MSB                                          18
#define SYNTH7_CHANFRAC_LSB                                          2
#define SYNTH7_CHANFRAC_MASK                                         0x0007fffc
#define SYNTH7_CHANFRAC_GET(x)                                       (((x) & SYNTH7_CHANFRAC_MASK) >> SYNTH7_CHANFRAC_LSB)
#define SYNTH7_CHANFRAC_SET(x)                                       (((0 | (x)) << SYNTH7_CHANFRAC_LSB) & SYNTH7_CHANFRAC_MASK)
#define SYNTH7_CHANFRAC_RESET                                        0
#define SYNTH7_FORCE_FRACLSB_MSB                                     1
#define SYNTH7_FORCE_FRACLSB_LSB                                     1
#define SYNTH7_FORCE_FRACLSB_MASK                                    0x00000002
#define SYNTH7_FORCE_FRACLSB_GET(x)                                  (((x) & SYNTH7_FORCE_FRACLSB_MASK) >> SYNTH7_FORCE_FRACLSB_LSB)
#define SYNTH7_FORCE_FRACLSB_SET(x)                                  (((0 | (x)) << SYNTH7_FORCE_FRACLSB_LSB) & SYNTH7_FORCE_FRACLSB_MASK)
#define SYNTH7_FORCE_FRACLSB_RESET                                   0
#define SYNTH7_OVRCHANDECODER_MSB                                    0
#define SYNTH7_OVRCHANDECODER_LSB                                    0
#define SYNTH7_OVRCHANDECODER_MASK                                   0x00000001
#define SYNTH7_OVRCHANDECODER_GET(x)                                 (((x) & SYNTH7_OVRCHANDECODER_MASK) >> SYNTH7_OVRCHANDECODER_LSB)
#define SYNTH7_OVRCHANDECODER_SET(x)                                 (((0 | (x)) << SYNTH7_OVRCHANDECODER_LSB) & SYNTH7_OVRCHANDECODER_MASK)
#define SYNTH7_OVRCHANDECODER_RESET                                  0
#define SYNTH7_ADDRESS                                               0x0060
#define SYNTH7_HW_MASK                                               0xffffffff
#define SYNTH7_SW_MASK                                               0xffffffff
#define SYNTH7_HW_WRITE_MASK                                         0x7ffffffc
#define SYNTH7_SW_WRITE_MASK                                         0xffffffff
#define SYNTH7_RSTMASK                                               0xffffffff
#define SYNTH7_RESET                                                 0x00000000

// 0x0064 (SYNTH8)
#define SYNTH8_REFDIVB_MSB                                           31
#define SYNTH8_REFDIVB_LSB                                           27
#define SYNTH8_REFDIVB_MASK                                          0xf8000000
#define SYNTH8_REFDIVB_GET(x)                                        (((x) & SYNTH8_REFDIVB_MASK) >> SYNTH8_REFDIVB_LSB)
#define SYNTH8_REFDIVB_SET(x)                                        (((0 | (x)) << SYNTH8_REFDIVB_LSB) & SYNTH8_REFDIVB_MASK)
#define SYNTH8_REFDIVB_RESET                                         1
#define SYNTH8_LOOP_3RD_ORDER_RB_MSB                                 26
#define SYNTH8_LOOP_3RD_ORDER_RB_LSB                                 22
#define SYNTH8_LOOP_3RD_ORDER_RB_MASK                                0x07c00000
#define SYNTH8_LOOP_3RD_ORDER_RB_GET(x)                              (((x) & SYNTH8_LOOP_3RD_ORDER_RB_MASK) >> SYNTH8_LOOP_3RD_ORDER_RB_LSB)
#define SYNTH8_LOOP_3RD_ORDER_RB_SET(x)                              (((0 | (x)) << SYNTH8_LOOP_3RD_ORDER_RB_LSB) & SYNTH8_LOOP_3RD_ORDER_RB_MASK)
#define SYNTH8_LOOP_3RD_ORDER_RB_RESET                               8
#define SYNTH8_LOOP_CPB_MSB                                          21
#define SYNTH8_LOOP_CPB_LSB                                          17
#define SYNTH8_LOOP_CPB_MASK                                         0x003e0000
#define SYNTH8_LOOP_CPB_GET(x)                                       (((x) & SYNTH8_LOOP_CPB_MASK) >> SYNTH8_LOOP_CPB_LSB)
#define SYNTH8_LOOP_CPB_SET(x)                                       (((0 | (x)) << SYNTH8_LOOP_CPB_LSB) & SYNTH8_LOOP_CPB_MASK)
#define SYNTH8_LOOP_CPB_RESET                                        8
#define SYNTH8_LOOP_RSB_MSB                                          16
#define SYNTH8_LOOP_RSB_LSB                                          12
#define SYNTH8_LOOP_RSB_MASK                                         0x0001f000
#define SYNTH8_LOOP_RSB_GET(x)                                       (((x) & SYNTH8_LOOP_RSB_MASK) >> SYNTH8_LOOP_RSB_LSB)
#define SYNTH8_LOOP_RSB_SET(x)                                       (((0 | (x)) << SYNTH8_LOOP_RSB_LSB) & SYNTH8_LOOP_RSB_MASK)
#define SYNTH8_LOOP_RSB_RESET                                        5
#define SYNTH8_LOOP_CSB_MSB                                          11
#define SYNTH8_LOOP_CSB_LSB                                          8
#define SYNTH8_LOOP_CSB_MASK                                         0x00000f00
#define SYNTH8_LOOP_CSB_GET(x)                                       (((x) & SYNTH8_LOOP_CSB_MASK) >> SYNTH8_LOOP_CSB_LSB)
#define SYNTH8_LOOP_CSB_SET(x)                                       (((0 | (x)) << SYNTH8_LOOP_CSB_LSB) & SYNTH8_LOOP_CSB_MASK)
#define SYNTH8_LOOP_CSB_RESET                                        3
#define SYNTH8_LOOP_ICPB_MSB                                         7
#define SYNTH8_LOOP_ICPB_LSB                                         1
#define SYNTH8_LOOP_ICPB_MASK                                        0x000000fe
#define SYNTH8_LOOP_ICPB_GET(x)                                      (((x) & SYNTH8_LOOP_ICPB_MASK) >> SYNTH8_LOOP_ICPB_LSB)
#define SYNTH8_LOOP_ICPB_SET(x)                                      (((0 | (x)) << SYNTH8_LOOP_ICPB_LSB) & SYNTH8_LOOP_ICPB_MASK)
#define SYNTH8_LOOP_ICPB_RESET                                       7
#define SYNTH8_CPSTEERING_EN_FRACN_MSB                               0
#define SYNTH8_CPSTEERING_EN_FRACN_LSB                               0
#define SYNTH8_CPSTEERING_EN_FRACN_MASK                              0x00000001
#define SYNTH8_CPSTEERING_EN_FRACN_GET(x)                            (((x) & SYNTH8_CPSTEERING_EN_FRACN_MASK) >> SYNTH8_CPSTEERING_EN_FRACN_LSB)
#define SYNTH8_CPSTEERING_EN_FRACN_SET(x)                            (((0 | (x)) << SYNTH8_CPSTEERING_EN_FRACN_LSB) & SYNTH8_CPSTEERING_EN_FRACN_MASK)
#define SYNTH8_CPSTEERING_EN_FRACN_RESET                             0
#define SYNTH8_ADDRESS                                               0x0064
#define SYNTH8_HW_MASK                                               0xffffffff
#define SYNTH8_SW_MASK                                               0xffffffff
#define SYNTH8_HW_WRITE_MASK                                         0x00000000
#define SYNTH8_SW_WRITE_MASK                                         0xffffffff
#define SYNTH8_RSTMASK                                               0xffffffff
#define SYNTH8_RESET                                                 0x0a10530e

// 0x0068 (SYNTH9)
#define SYNTH9_REFDIVA_MSB                                           31
#define SYNTH9_REFDIVA_LSB                                           27
#define SYNTH9_REFDIVA_MASK                                          0xf8000000
#define SYNTH9_REFDIVA_GET(x)                                        (((x) & SYNTH9_REFDIVA_MASK) >> SYNTH9_REFDIVA_LSB)
#define SYNTH9_REFDIVA_SET(x)                                        (((0 | (x)) << SYNTH9_REFDIVA_LSB) & SYNTH9_REFDIVA_MASK)
#define SYNTH9_REFDIVA_RESET                                         24
#define SYNTH9_LOOP_3RD_ORDER_RA_MSB                                 26
#define SYNTH9_LOOP_3RD_ORDER_RA_LSB                                 22
#define SYNTH9_LOOP_3RD_ORDER_RA_MASK                                0x07c00000
#define SYNTH9_LOOP_3RD_ORDER_RA_GET(x)                              (((x) & SYNTH9_LOOP_3RD_ORDER_RA_MASK) >> SYNTH9_LOOP_3RD_ORDER_RA_LSB)
#define SYNTH9_LOOP_3RD_ORDER_RA_SET(x)                              (((0 | (x)) << SYNTH9_LOOP_3RD_ORDER_RA_LSB) & SYNTH9_LOOP_3RD_ORDER_RA_MASK)
#define SYNTH9_LOOP_3RD_ORDER_RA_RESET                               0
#define SYNTH9_LOOP_CPA0_MSB                                         21
#define SYNTH9_LOOP_CPA0_LSB                                         17
#define SYNTH9_LOOP_CPA0_MASK                                        0x003e0000
#define SYNTH9_LOOP_CPA0_GET(x)                                      (((x) & SYNTH9_LOOP_CPA0_MASK) >> SYNTH9_LOOP_CPA0_LSB)
#define SYNTH9_LOOP_CPA0_SET(x)                                      (((0 | (x)) << SYNTH9_LOOP_CPA0_LSB) & SYNTH9_LOOP_CPA0_MASK)
#define SYNTH9_LOOP_CPA0_RESET                                       16
#define SYNTH9_LOOP_RSA0_MSB                                         16
#define SYNTH9_LOOP_RSA0_LSB                                         12
#define SYNTH9_LOOP_RSA0_MASK                                        0x0001f000
#define SYNTH9_LOOP_RSA0_GET(x)                                      (((x) & SYNTH9_LOOP_RSA0_MASK) >> SYNTH9_LOOP_RSA0_LSB)
#define SYNTH9_LOOP_RSA0_SET(x)                                      (((0 | (x)) << SYNTH9_LOOP_RSA0_LSB) & SYNTH9_LOOP_RSA0_MASK)
#define SYNTH9_LOOP_RSA0_RESET                                       4
#define SYNTH9_LOOP_CSA0_MSB                                         11
#define SYNTH9_LOOP_CSA0_LSB                                         8
#define SYNTH9_LOOP_CSA0_MASK                                        0x00000f00
#define SYNTH9_LOOP_CSA0_GET(x)                                      (((x) & SYNTH9_LOOP_CSA0_MASK) >> SYNTH9_LOOP_CSA0_LSB)
#define SYNTH9_LOOP_CSA0_SET(x)                                      (((0 | (x)) << SYNTH9_LOOP_CSA0_LSB) & SYNTH9_LOOP_CSA0_MASK)
#define SYNTH9_LOOP_CSA0_RESET                                       11
#define SYNTH9_LOOP_ICPA0_MSB                                        7
#define SYNTH9_LOOP_ICPA0_LSB                                        4
#define SYNTH9_LOOP_ICPA0_MASK                                       0x000000f0
#define SYNTH9_LOOP_ICPA0_GET(x)                                     (((x) & SYNTH9_LOOP_ICPA0_MASK) >> SYNTH9_LOOP_ICPA0_LSB)
#define SYNTH9_LOOP_ICPA0_SET(x)                                     (((0 | (x)) << SYNTH9_LOOP_ICPA0_LSB) & SYNTH9_LOOP_ICPA0_MASK)
#define SYNTH9_LOOP_ICPA0_RESET                                      2
#define SYNTH9_SLOPE_ICPA0_MSB                                       3
#define SYNTH9_SLOPE_ICPA0_LSB                                       1
#define SYNTH9_SLOPE_ICPA0_MASK                                      0x0000000e
#define SYNTH9_SLOPE_ICPA0_GET(x)                                    (((x) & SYNTH9_SLOPE_ICPA0_MASK) >> SYNTH9_SLOPE_ICPA0_LSB)
#define SYNTH9_SLOPE_ICPA0_SET(x)                                    (((0 | (x)) << SYNTH9_SLOPE_ICPA0_LSB) & SYNTH9_SLOPE_ICPA0_MASK)
#define SYNTH9_SLOPE_ICPA0_RESET                                     0
#define SYNTH9_PFDDELAY_INTN_MSB                                     0
#define SYNTH9_PFDDELAY_INTN_LSB                                     0
#define SYNTH9_PFDDELAY_INTN_MASK                                    0x00000001
#define SYNTH9_PFDDELAY_INTN_GET(x)                                  (((x) & SYNTH9_PFDDELAY_INTN_MASK) >> SYNTH9_PFDDELAY_INTN_LSB)
#define SYNTH9_PFDDELAY_INTN_SET(x)                                  (((0 | (x)) << SYNTH9_PFDDELAY_INTN_LSB) & SYNTH9_PFDDELAY_INTN_MASK)
#define SYNTH9_PFDDELAY_INTN_RESET                                   0
#define SYNTH9_ADDRESS                                               0x0068
#define SYNTH9_HW_MASK                                               0xffffffff
#define SYNTH9_SW_MASK                                               0xffffffff
#define SYNTH9_HW_WRITE_MASK                                         0x00000000
#define SYNTH9_SW_WRITE_MASK                                         0xffffffff
#define SYNTH9_RSTMASK                                               0xffffffff
#define SYNTH9_RESET                                                 0xc0204b20

// 0x006c (SYNTH10)
#define SYNTH10_LOOP_CPA1_MSB                                        31
#define SYNTH10_LOOP_CPA1_LSB                                        27
#define SYNTH10_LOOP_CPA1_MASK                                       0xf8000000
#define SYNTH10_LOOP_CPA1_GET(x)                                     (((x) & SYNTH10_LOOP_CPA1_MASK) >> SYNTH10_LOOP_CPA1_LSB)
#define SYNTH10_LOOP_CPA1_SET(x)                                     (((0 | (x)) << SYNTH10_LOOP_CPA1_LSB) & SYNTH10_LOOP_CPA1_MASK)
#define SYNTH10_LOOP_CPA1_RESET                                      16
#define SYNTH10_LOOP_RSA1_MSB                                        26
#define SYNTH10_LOOP_RSA1_LSB                                        22
#define SYNTH10_LOOP_RSA1_MASK                                       0x07c00000
#define SYNTH10_LOOP_RSA1_GET(x)                                     (((x) & SYNTH10_LOOP_RSA1_MASK) >> SYNTH10_LOOP_RSA1_LSB)
#define SYNTH10_LOOP_RSA1_SET(x)                                     (((0 | (x)) << SYNTH10_LOOP_RSA1_LSB) & SYNTH10_LOOP_RSA1_MASK)
#define SYNTH10_LOOP_RSA1_RESET                                      4
#define SYNTH10_LOOP_CSA1_MSB                                        21
#define SYNTH10_LOOP_CSA1_LSB                                        18
#define SYNTH10_LOOP_CSA1_MASK                                       0x003c0000
#define SYNTH10_LOOP_CSA1_GET(x)                                     (((x) & SYNTH10_LOOP_CSA1_MASK) >> SYNTH10_LOOP_CSA1_LSB)
#define SYNTH10_LOOP_CSA1_SET(x)                                     (((0 | (x)) << SYNTH10_LOOP_CSA1_LSB) & SYNTH10_LOOP_CSA1_MASK)
#define SYNTH10_LOOP_CSA1_RESET                                      11
#define SYNTH10_LOOP_ICPA1_MSB                                       17
#define SYNTH10_LOOP_ICPA1_LSB                                       14
#define SYNTH10_LOOP_ICPA1_MASK                                      0x0003c000
#define SYNTH10_LOOP_ICPA1_GET(x)                                    (((x) & SYNTH10_LOOP_ICPA1_MASK) >> SYNTH10_LOOP_ICPA1_LSB)
#define SYNTH10_LOOP_ICPA1_SET(x)                                    (((0 | (x)) << SYNTH10_LOOP_ICPA1_LSB) & SYNTH10_LOOP_ICPA1_MASK)
#define SYNTH10_LOOP_ICPA1_RESET                                     5
#define SYNTH10_SLOPE_ICPA1_MSB                                      13
#define SYNTH10_SLOPE_ICPA1_LSB                                      11
#define SYNTH10_SLOPE_ICPA1_MASK                                     0x00003800
#define SYNTH10_SLOPE_ICPA1_GET(x)                                   (((x) & SYNTH10_SLOPE_ICPA1_MASK) >> SYNTH10_SLOPE_ICPA1_LSB)
#define SYNTH10_SLOPE_ICPA1_SET(x)                                   (((0 | (x)) << SYNTH10_SLOPE_ICPA1_LSB) & SYNTH10_SLOPE_ICPA1_MASK)
#define SYNTH10_SLOPE_ICPA1_RESET                                    0
#define SYNTH10_SPARE_MSB                                            10
#define SYNTH10_SPARE_LSB                                            0
#define SYNTH10_SPARE_MASK                                           0x000007ff
#define SYNTH10_SPARE_GET(x)                                         (((x) & SYNTH10_SPARE_MASK) >> SYNTH10_SPARE_LSB)
#define SYNTH10_SPARE_SET(x)                                         (((0 | (x)) << SYNTH10_SPARE_LSB) & SYNTH10_SPARE_MASK)
#define SYNTH10_SPARE_RESET                                          0
#define SYNTH10_ADDRESS                                              0x006c
#define SYNTH10_HW_MASK                                              0xffffffff
#define SYNTH10_SW_MASK                                              0xffffffff
#define SYNTH10_HW_WRITE_MASK                                        0x00000000
#define SYNTH10_SW_WRITE_MASK                                        0xffffffff
#define SYNTH10_RSTMASK                                              0xffffffff
#define SYNTH10_RESET                                                0x812d4000

// 0x0070 (SYNTH11)
#define SYNTH11_LOOP_CPA2_MSB                                        31
#define SYNTH11_LOOP_CPA2_LSB                                        27
#define SYNTH11_LOOP_CPA2_MASK                                       0xf8000000
#define SYNTH11_LOOP_CPA2_GET(x)                                     (((x) & SYNTH11_LOOP_CPA2_MASK) >> SYNTH11_LOOP_CPA2_LSB)
#define SYNTH11_LOOP_CPA2_SET(x)                                     (((0 | (x)) << SYNTH11_LOOP_CPA2_LSB) & SYNTH11_LOOP_CPA2_MASK)
#define SYNTH11_LOOP_CPA2_RESET                                      16
#define SYNTH11_LOOP_RSA2_MSB                                        26
#define SYNTH11_LOOP_RSA2_LSB                                        22
#define SYNTH11_LOOP_RSA2_MASK                                       0x07c00000
#define SYNTH11_LOOP_RSA2_GET(x)                                     (((x) & SYNTH11_LOOP_RSA2_MASK) >> SYNTH11_LOOP_RSA2_LSB)
#define SYNTH11_LOOP_RSA2_SET(x)                                     (((0 | (x)) << SYNTH11_LOOP_RSA2_LSB) & SYNTH11_LOOP_RSA2_MASK)
#define SYNTH11_LOOP_RSA2_RESET                                      4
#define SYNTH11_LOOP_CSA2_MSB                                        21
#define SYNTH11_LOOP_CSA2_LSB                                        18
#define SYNTH11_LOOP_CSA2_MASK                                       0x003c0000
#define SYNTH11_LOOP_CSA2_GET(x)                                     (((x) & SYNTH11_LOOP_CSA2_MASK) >> SYNTH11_LOOP_CSA2_LSB)
#define SYNTH11_LOOP_CSA2_SET(x)                                     (((0 | (x)) << SYNTH11_LOOP_CSA2_LSB) & SYNTH11_LOOP_CSA2_MASK)
#define SYNTH11_LOOP_CSA2_RESET                                      11
#define SYNTH11_LOOP_ICPA2_MSB                                       17
#define SYNTH11_LOOP_ICPA2_LSB                                       14
#define SYNTH11_LOOP_ICPA2_MASK                                      0x0003c000
#define SYNTH11_LOOP_ICPA2_GET(x)                                    (((x) & SYNTH11_LOOP_ICPA2_MASK) >> SYNTH11_LOOP_ICPA2_LSB)
#define SYNTH11_LOOP_ICPA2_SET(x)                                    (((0 | (x)) << SYNTH11_LOOP_ICPA2_LSB) & SYNTH11_LOOP_ICPA2_MASK)
#define SYNTH11_LOOP_ICPA2_RESET                                     11
#define SYNTH11_SLOPE_ICPA2_MSB                                      13
#define SYNTH11_SLOPE_ICPA2_LSB                                      11
#define SYNTH11_SLOPE_ICPA2_MASK                                     0x00003800
#define SYNTH11_SLOPE_ICPA2_GET(x)                                   (((x) & SYNTH11_SLOPE_ICPA2_MASK) >> SYNTH11_SLOPE_ICPA2_LSB)
#define SYNTH11_SLOPE_ICPA2_SET(x)                                   (((0 | (x)) << SYNTH11_SLOPE_ICPA2_LSB) & SYNTH11_SLOPE_ICPA2_MASK)
#define SYNTH11_SLOPE_ICPA2_RESET                                    0
#define SYNTH11_CPSTEERING_MODE_MSB                                  10
#define SYNTH11_CPSTEERING_MODE_LSB                                  10
#define SYNTH11_CPSTEERING_MODE_MASK                                 0x00000400
#define SYNTH11_CPSTEERING_MODE_GET(x)                               (((x) & SYNTH11_CPSTEERING_MODE_MASK) >> SYNTH11_CPSTEERING_MODE_LSB)
#define SYNTH11_CPSTEERING_MODE_SET(x)                               (((0 | (x)) << SYNTH11_CPSTEERING_MODE_LSB) & SYNTH11_CPSTEERING_MODE_MASK)
#define SYNTH11_CPSTEERING_MODE_RESET                                1
#define SYNTH11_LO2GSEL_MSB                                          9
#define SYNTH11_LO2GSEL_LSB                                          8
#define SYNTH11_LO2GSEL_MASK                                         0x00000300
#define SYNTH11_LO2GSEL_GET(x)                                       (((x) & SYNTH11_LO2GSEL_MASK) >> SYNTH11_LO2GSEL_LSB)
#define SYNTH11_LO2GSEL_SET(x)                                       (((0 | (x)) << SYNTH11_LO2GSEL_LSB) & SYNTH11_LO2GSEL_MASK)
#define SYNTH11_LO2GSEL_RESET                                        0
#define SYNTH11_LOREFSEL_MSB                                         7
#define SYNTH11_LOREFSEL_LSB                                         6
#define SYNTH11_LOREFSEL_MASK                                        0x000000c0
#define SYNTH11_LOREFSEL_GET(x)                                      (((x) & SYNTH11_LOREFSEL_MASK) >> SYNTH11_LOREFSEL_LSB)
#define SYNTH11_LOREFSEL_SET(x)                                      (((0 | (x)) << SYNTH11_LOREFSEL_LSB) & SYNTH11_LOREFSEL_MASK)
#define SYNTH11_LOREFSEL_RESET                                       0
#define SYNTH11_FORCE_LOBUF5G_ON_MSB                                 5
#define SYNTH11_FORCE_LOBUF5G_ON_LSB                                 5
#define SYNTH11_FORCE_LOBUF5G_ON_MASK                                0x00000020
#define SYNTH11_FORCE_LOBUF5G_ON_GET(x)                              (((x) & SYNTH11_FORCE_LOBUF5G_ON_MASK) >> SYNTH11_FORCE_LOBUF5G_ON_LSB)
#define SYNTH11_FORCE_LOBUF5G_ON_SET(x)                              (((0 | (x)) << SYNTH11_FORCE_LOBUF5G_ON_LSB) & SYNTH11_FORCE_LOBUF5G_ON_MASK)
#define SYNTH11_FORCE_LOBUF5G_ON_RESET                               0
#define SYNTH11_SPARE_MSB                                            4
#define SYNTH11_SPARE_LSB                                            0
#define SYNTH11_SPARE_MASK                                           0x0000001f
#define SYNTH11_SPARE_GET(x)                                         (((x) & SYNTH11_SPARE_MASK) >> SYNTH11_SPARE_LSB)
#define SYNTH11_SPARE_SET(x)                                         (((0 | (x)) << SYNTH11_SPARE_LSB) & SYNTH11_SPARE_MASK)
#define SYNTH11_SPARE_RESET                                          0
#define SYNTH11_ADDRESS                                              0x0070
#define SYNTH11_HW_MASK                                              0xffffffff
#define SYNTH11_SW_MASK                                              0xffffffff
#define SYNTH11_HW_WRITE_MASK                                        0x00000000
#define SYNTH11_SW_WRITE_MASK                                        0xffffffff
#define SYNTH11_RSTMASK                                              0xffffffff
#define SYNTH11_RESET                                                0x812ec400

// 0x0074 (BIAS1)
#define BIAS1_PADON_MSB                                              31
#define BIAS1_PADON_LSB                                              31
#define BIAS1_PADON_MASK                                             0x80000000
#define BIAS1_PADON_GET(x)                                           (((x) & BIAS1_PADON_MASK) >> BIAS1_PADON_LSB)
#define BIAS1_PADON_SET(x)                                           (((0 | (x)) << BIAS1_PADON_LSB) & BIAS1_PADON_MASK)
#define BIAS1_PADON_RESET                                            0
#define BIAS1_SEL_BIAS_MSB                                           30
#define BIAS1_SEL_BIAS_LSB                                           25
#define BIAS1_SEL_BIAS_MASK                                          0x7e000000
#define BIAS1_SEL_BIAS_GET(x)                                        (((x) & BIAS1_SEL_BIAS_MASK) >> BIAS1_SEL_BIAS_LSB)
#define BIAS1_SEL_BIAS_SET(x)                                        (((0 | (x)) << BIAS1_SEL_BIAS_LSB) & BIAS1_SEL_BIAS_MASK)
#define BIAS1_SEL_BIAS_RESET                                         0
#define BIAS1_BIAS1_SPARE_MSB                                        24
#define BIAS1_BIAS1_SPARE_LSB                                        22
#define BIAS1_BIAS1_SPARE_MASK                                       0x01c00000
#define BIAS1_BIAS1_SPARE_GET(x)                                     (((x) & BIAS1_BIAS1_SPARE_MASK) >> BIAS1_BIAS1_SPARE_LSB)
#define BIAS1_BIAS1_SPARE_SET(x)                                     (((0 | (x)) << BIAS1_BIAS1_SPARE_LSB) & BIAS1_BIAS1_SPARE_MASK)
#define BIAS1_BIAS1_SPARE_RESET                                      0
#define BIAS1_PWD_ICXTAL25_MSB                                       21
#define BIAS1_PWD_ICXTAL25_LSB                                       19
#define BIAS1_PWD_ICXTAL25_MASK                                      0x00380000
#define BIAS1_PWD_ICXTAL25_GET(x)                                    (((x) & BIAS1_PWD_ICXTAL25_MASK) >> BIAS1_PWD_ICXTAL25_LSB)
#define BIAS1_PWD_ICXTAL25_SET(x)                                    (((0 | (x)) << BIAS1_PWD_ICXTAL25_LSB) & BIAS1_PWD_ICXTAL25_MASK)
#define BIAS1_PWD_ICXTAL25_RESET                                     3
#define BIAS1_PWD_IRXTAL25_MSB                                       18
#define BIAS1_PWD_IRXTAL25_LSB                                       16
#define BIAS1_PWD_IRXTAL25_MASK                                      0x00070000
#define BIAS1_PWD_IRXTAL25_GET(x)                                    (((x) & BIAS1_PWD_IRXTAL25_MASK) >> BIAS1_PWD_IRXTAL25_LSB)
#define BIAS1_PWD_IRXTAL25_SET(x)                                    (((0 | (x)) << BIAS1_PWD_IRXTAL25_LSB) & BIAS1_PWD_IRXTAL25_MASK)
#define BIAS1_PWD_IRXTAL25_RESET                                     3
#define BIAS1_PWD_ICXPALDO25_MSB                                     15
#define BIAS1_PWD_ICXPALDO25_LSB                                     13
#define BIAS1_PWD_ICXPALDO25_MASK                                    0x0000e000
#define BIAS1_PWD_ICXPALDO25_GET(x)                                  (((x) & BIAS1_PWD_ICXPALDO25_MASK) >> BIAS1_PWD_ICXPALDO25_LSB)
#define BIAS1_PWD_ICXPALDO25_SET(x)                                  (((0 | (x)) << BIAS1_PWD_ICXPALDO25_LSB) & BIAS1_PWD_ICXPALDO25_MASK)
#define BIAS1_PWD_ICXPALDO25_RESET                                   3
#define BIAS1_PWD_IRXPALDO25_MSB                                     12
#define BIAS1_PWD_IRXPALDO25_LSB                                     10
#define BIAS1_PWD_IRXPALDO25_MASK                                    0x00001c00
#define BIAS1_PWD_IRXPALDO25_GET(x)                                  (((x) & BIAS1_PWD_IRXPALDO25_MASK) >> BIAS1_PWD_IRXPALDO25_LSB)
#define BIAS1_PWD_IRXPALDO25_SET(x)                                  (((0 | (x)) << BIAS1_PWD_IRXPALDO25_LSB) & BIAS1_PWD_IRXPALDO25_MASK)
#define BIAS1_PWD_IRXPALDO25_RESET                                   3
#define BIAS1_PWD_ICRXLDO25_MSB                                      9
#define BIAS1_PWD_ICRXLDO25_LSB                                      7
#define BIAS1_PWD_ICRXLDO25_MASK                                     0x00000380
#define BIAS1_PWD_ICRXLDO25_GET(x)                                   (((x) & BIAS1_PWD_ICRXLDO25_MASK) >> BIAS1_PWD_ICRXLDO25_LSB)
#define BIAS1_PWD_ICRXLDO25_SET(x)                                   (((0 | (x)) << BIAS1_PWD_ICRXLDO25_LSB) & BIAS1_PWD_ICRXLDO25_MASK)
#define BIAS1_PWD_ICRXLDO25_RESET                                    3
#define BIAS1_PWD_IRRXLDO25_MSB                                      6
#define BIAS1_PWD_IRRXLDO25_LSB                                      4
#define BIAS1_PWD_IRRXLDO25_MASK                                     0x00000070
#define BIAS1_PWD_IRRXLDO25_GET(x)                                   (((x) & BIAS1_PWD_IRRXLDO25_MASK) >> BIAS1_PWD_IRRXLDO25_LSB)
#define BIAS1_PWD_IRRXLDO25_SET(x)                                   (((0 | (x)) << BIAS1_PWD_IRRXLDO25_LSB) & BIAS1_PWD_IRRXLDO25_MASK)
#define BIAS1_PWD_IRRXLDO25_RESET                                    3
#define BIAS1_PWD_ICPLL25_MSB                                        3
#define BIAS1_PWD_ICPLL25_LSB                                        3
#define BIAS1_PWD_ICPLL25_MASK                                       0x00000008
#define BIAS1_PWD_ICPLL25_GET(x)                                     (((x) & BIAS1_PWD_ICPLL25_MASK) >> BIAS1_PWD_ICPLL25_LSB)
#define BIAS1_PWD_ICPLL25_SET(x)                                     (((0 | (x)) << BIAS1_PWD_ICPLL25_LSB) & BIAS1_PWD_ICPLL25_MASK)
#define BIAS1_PWD_ICPLL25_RESET                                      0
#define BIAS1_PWD_IRPLL25_MSB                                        2
#define BIAS1_PWD_IRPLL25_LSB                                        2
#define BIAS1_PWD_IRPLL25_MASK                                       0x00000004
#define BIAS1_PWD_IRPLL25_GET(x)                                     (((x) & BIAS1_PWD_IRPLL25_MASK) >> BIAS1_PWD_IRPLL25_LSB)
#define BIAS1_PWD_IRPLL25_SET(x)                                     (((0 | (x)) << BIAS1_PWD_IRPLL25_LSB) & BIAS1_PWD_IRPLL25_MASK)
#define BIAS1_PWD_IRPLL25_RESET                                      0
#define BIAS1_PWD_ICPCIE50_MSB                                       1
#define BIAS1_PWD_ICPCIE50_LSB                                       1
#define BIAS1_PWD_ICPCIE50_MASK                                      0x00000002
#define BIAS1_PWD_ICPCIE50_GET(x)                                    (((x) & BIAS1_PWD_ICPCIE50_MASK) >> BIAS1_PWD_ICPCIE50_LSB)
#define BIAS1_PWD_ICPCIE50_SET(x)                                    (((0 | (x)) << BIAS1_PWD_ICPCIE50_LSB) & BIAS1_PWD_ICPCIE50_MASK)
#define BIAS1_PWD_ICPCIE50_RESET                                     0
#define BIAS1_PWD_IRPCIE50_MSB                                       0
#define BIAS1_PWD_IRPCIE50_LSB                                       0
#define BIAS1_PWD_IRPCIE50_MASK                                      0x00000001
#define BIAS1_PWD_IRPCIE50_GET(x)                                    (((x) & BIAS1_PWD_IRPCIE50_MASK) >> BIAS1_PWD_IRPCIE50_LSB)
#define BIAS1_PWD_IRPCIE50_SET(x)                                    (((0 | (x)) << BIAS1_PWD_IRPCIE50_LSB) & BIAS1_PWD_IRPCIE50_MASK)
#define BIAS1_PWD_IRPCIE50_RESET                                     0
#define BIAS1_ADDRESS                                                0x0074
#define BIAS1_HW_MASK                                                0xffffffff
#define BIAS1_SW_MASK                                                0xffffffff
#define BIAS1_HW_WRITE_MASK                                          0x00000000
#define BIAS1_SW_WRITE_MASK                                          0xffffffff
#define BIAS1_RSTMASK                                                0x003fffff
#define BIAS1_RESET                                                  0x001b6db0

// 0x0078 (BIAS2)
#define BIAS2_PWD_ICSYNTH50_MSB                                      31
#define BIAS2_PWD_ICSYNTH50_LSB                                      31
#define BIAS2_PWD_ICSYNTH50_MASK                                     0x80000000
#define BIAS2_PWD_ICSYNTH50_GET(x)                                   (((x) & BIAS2_PWD_ICSYNTH50_MASK) >> BIAS2_PWD_ICSYNTH50_LSB)
#define BIAS2_PWD_ICSYNTH50_SET(x)                                   (((0 | (x)) << BIAS2_PWD_ICSYNTH50_LSB) & BIAS2_PWD_ICSYNTH50_MASK)
#define BIAS2_PWD_ICSYNTH50_RESET                                    0
#define BIAS2_PWD_IRSYNTH50_MSB                                      30
#define BIAS2_PWD_IRSYNTH50_LSB                                      30
#define BIAS2_PWD_IRSYNTH50_MASK                                     0x40000000
#define BIAS2_PWD_IRSYNTH50_GET(x)                                   (((x) & BIAS2_PWD_IRSYNTH50_MASK) >> BIAS2_PWD_IRSYNTH50_LSB)
#define BIAS2_PWD_IRSYNTH50_SET(x)                                   (((0 | (x)) << BIAS2_PWD_IRSYNTH50_LSB) & BIAS2_PWD_IRSYNTH50_MASK)
#define BIAS2_PWD_IRSYNTH50_RESET                                    0
#define BIAS2_PWD_ICRF5G50_MSB                                       29
#define BIAS2_PWD_ICRF5G50_LSB                                       29
#define BIAS2_PWD_ICRF5G50_MASK                                      0x20000000
#define BIAS2_PWD_ICRF5G50_GET(x)                                    (((x) & BIAS2_PWD_ICRF5G50_MASK) >> BIAS2_PWD_ICRF5G50_LSB)
#define BIAS2_PWD_ICRF5G50_SET(x)                                    (((0 | (x)) << BIAS2_PWD_ICRF5G50_LSB) & BIAS2_PWD_ICRF5G50_MASK)
#define BIAS2_PWD_ICRF5G50_RESET                                     0
#define BIAS2_PWD_ICRF2G50_MSB                                       28
#define BIAS2_PWD_ICRF2G50_LSB                                       28
#define BIAS2_PWD_ICRF2G50_MASK                                      0x10000000
#define BIAS2_PWD_ICRF2G50_GET(x)                                    (((x) & BIAS2_PWD_ICRF2G50_MASK) >> BIAS2_PWD_ICRF2G50_LSB)
#define BIAS2_PWD_ICRF2G50_SET(x)                                    (((0 | (x)) << BIAS2_PWD_ICRF2G50_LSB) & BIAS2_PWD_ICRF2G50_MASK)
#define BIAS2_PWD_ICRF2G50_RESET                                     0
#define BIAS2_PWD_IRRF5G50_MSB                                       27
#define BIAS2_PWD_IRRF5G50_LSB                                       27
#define BIAS2_PWD_IRRF5G50_MASK                                      0x08000000
#define BIAS2_PWD_IRRF5G50_GET(x)                                    (((x) & BIAS2_PWD_IRRF5G50_MASK) >> BIAS2_PWD_IRRF5G50_LSB)
#define BIAS2_PWD_IRRF5G50_SET(x)                                    (((0 | (x)) << BIAS2_PWD_IRRF5G50_LSB) & BIAS2_PWD_IRRF5G50_MASK)
#define BIAS2_PWD_IRRF5G50_RESET                                     0
#define BIAS2_PWD_IRRF2G50_MSB                                       26
#define BIAS2_PWD_IRRF2G50_LSB                                       26
#define BIAS2_PWD_IRRF2G50_MASK                                      0x04000000
#define BIAS2_PWD_IRRF2G50_GET(x)                                    (((x) & BIAS2_PWD_IRRF2G50_MASK) >> BIAS2_PWD_IRRF2G50_LSB)
#define BIAS2_PWD_IRRF2G50_SET(x)                                    (((0 | (x)) << BIAS2_PWD_IRRF2G50_LSB) & BIAS2_PWD_IRRF2G50_MASK)
#define BIAS2_PWD_IRRF2G50_RESET                                     0
#define BIAS2_PWD_ICBB50_MSB                                         25
#define BIAS2_PWD_ICBB50_LSB                                         25
#define BIAS2_PWD_ICBB50_MASK                                        0x02000000
#define BIAS2_PWD_ICBB50_GET(x)                                      (((x) & BIAS2_PWD_ICBB50_MASK) >> BIAS2_PWD_ICBB50_LSB)
#define BIAS2_PWD_ICBB50_SET(x)                                      (((0 | (x)) << BIAS2_PWD_ICBB50_LSB) & BIAS2_PWD_ICBB50_MASK)
#define BIAS2_PWD_ICBB50_RESET                                       0
#define BIAS2_PWD_IRBB50_MSB                                         24
#define BIAS2_PWD_IRBB50_LSB                                         24
#define BIAS2_PWD_IRBB50_MASK                                        0x01000000
#define BIAS2_PWD_IRBB50_GET(x)                                      (((x) & BIAS2_PWD_IRBB50_MASK) >> BIAS2_PWD_IRBB50_LSB)
#define BIAS2_PWD_IRBB50_SET(x)                                      (((0 | (x)) << BIAS2_PWD_IRBB50_LSB) & BIAS2_PWD_IRBB50_MASK)
#define BIAS2_PWD_IRBB50_RESET                                       0
#define BIAS2_PWD_ICDACINTFACE25_MSB                                 23
#define BIAS2_PWD_ICDACINTFACE25_LSB                                 23
#define BIAS2_PWD_ICDACINTFACE25_MASK                                0x00800000
#define BIAS2_PWD_ICDACINTFACE25_GET(x)                              (((x) & BIAS2_PWD_ICDACINTFACE25_MASK) >> BIAS2_PWD_ICDACINTFACE25_LSB)
#define BIAS2_PWD_ICDACINTFACE25_SET(x)                              (((0 | (x)) << BIAS2_PWD_ICDACINTFACE25_LSB) & BIAS2_PWD_ICDACINTFACE25_MASK)
#define BIAS2_PWD_ICDACINTFACE25_RESET                               0
#define BIAS2_PWD_ICADCCOMPI25_MSB                                   22
#define BIAS2_PWD_ICADCCOMPI25_LSB                                   20
#define BIAS2_PWD_ICADCCOMPI25_MASK                                  0x00700000
#define BIAS2_PWD_ICADCCOMPI25_GET(x)                                (((x) & BIAS2_PWD_ICADCCOMPI25_MASK) >> BIAS2_PWD_ICADCCOMPI25_LSB)
#define BIAS2_PWD_ICADCCOMPI25_SET(x)                                (((0 | (x)) << BIAS2_PWD_ICADCCOMPI25_LSB) & BIAS2_PWD_ICADCCOMPI25_MASK)
#define BIAS2_PWD_ICADCCOMPI25_RESET                                 3
#define BIAS2_PWD_ICADCCOMPQ25_MSB                                   19
#define BIAS2_PWD_ICADCCOMPQ25_LSB                                   17
#define BIAS2_PWD_ICADCCOMPQ25_MASK                                  0x000e0000
#define BIAS2_PWD_ICADCCOMPQ25_GET(x)                                (((x) & BIAS2_PWD_ICADCCOMPQ25_MASK) >> BIAS2_PWD_ICADCCOMPQ25_LSB)
#define BIAS2_PWD_ICADCCOMPQ25_SET(x)                                (((0 | (x)) << BIAS2_PWD_ICADCCOMPQ25_LSB) & BIAS2_PWD_ICADCCOMPQ25_MASK)
#define BIAS2_PWD_ICADCCOMPQ25_RESET                                 3
#define BIAS2_PWD_ICADCREFBUFI12P5_MSB                               16
#define BIAS2_PWD_ICADCREFBUFI12P5_LSB                               14
#define BIAS2_PWD_ICADCREFBUFI12P5_MASK                              0x0001c000
#define BIAS2_PWD_ICADCREFBUFI12P5_GET(x)                            (((x) & BIAS2_PWD_ICADCREFBUFI12P5_MASK) >> BIAS2_PWD_ICADCREFBUFI12P5_LSB)
#define BIAS2_PWD_ICADCREFBUFI12P5_SET(x)                            (((0 | (x)) << BIAS2_PWD_ICADCREFBUFI12P5_LSB) & BIAS2_PWD_ICADCREFBUFI12P5_MASK)
#define BIAS2_PWD_ICADCREFBUFI12P5_RESET                             5
#define BIAS2_PWD_ICADCREFBUFQ12P5_MSB                               13
#define BIAS2_PWD_ICADCREFBUFQ12P5_LSB                               11
#define BIAS2_PWD_ICADCREFBUFQ12P5_MASK                              0x00003800
#define BIAS2_PWD_ICADCREFBUFQ12P5_GET(x)                            (((x) & BIAS2_PWD_ICADCREFBUFQ12P5_MASK) >> BIAS2_PWD_ICADCREFBUFQ12P5_LSB)
#define BIAS2_PWD_ICADCREFBUFQ12P5_SET(x)                            (((0 | (x)) << BIAS2_PWD_ICADCREFBUFQ12P5_LSB) & BIAS2_PWD_ICADCREFBUFQ12P5_MASK)
#define BIAS2_PWD_ICADCREFBUFQ12P5_RESET                             5
#define BIAS2_PWD_ICADCREFOPAMPI25_MSB                               10
#define BIAS2_PWD_ICADCREFOPAMPI25_LSB                               8
#define BIAS2_PWD_ICADCREFOPAMPI25_MASK                              0x00000700
#define BIAS2_PWD_ICADCREFOPAMPI25_GET(x)                            (((x) & BIAS2_PWD_ICADCREFOPAMPI25_MASK) >> BIAS2_PWD_ICADCREFOPAMPI25_LSB)
#define BIAS2_PWD_ICADCREFOPAMPI25_SET(x)                            (((0 | (x)) << BIAS2_PWD_ICADCREFOPAMPI25_LSB) & BIAS2_PWD_ICADCREFOPAMPI25_MASK)
#define BIAS2_PWD_ICADCREFOPAMPI25_RESET                             3
#define BIAS2_PWD_ICADCREFOPAMPQ25_MSB                               7
#define BIAS2_PWD_ICADCREFOPAMPQ25_LSB                               5
#define BIAS2_PWD_ICADCREFOPAMPQ25_MASK                              0x000000e0
#define BIAS2_PWD_ICADCREFOPAMPQ25_GET(x)                            (((x) & BIAS2_PWD_ICADCREFOPAMPQ25_MASK) >> BIAS2_PWD_ICADCREFOPAMPQ25_LSB)
#define BIAS2_PWD_ICADCREFOPAMPQ25_SET(x)                            (((0 | (x)) << BIAS2_PWD_ICADCREFOPAMPQ25_LSB) & BIAS2_PWD_ICADCREFOPAMPQ25_MASK)
#define BIAS2_PWD_ICADCREFOPAMPQ25_RESET                             3
#define BIAS2_PWD_IRADCREFMSTRI12P5_MSB                              4
#define BIAS2_PWD_IRADCREFMSTRI12P5_LSB                              4
#define BIAS2_PWD_IRADCREFMSTRI12P5_MASK                             0x00000010
#define BIAS2_PWD_IRADCREFMSTRI12P5_GET(x)                           (((x) & BIAS2_PWD_IRADCREFMSTRI12P5_MASK) >> BIAS2_PWD_IRADCREFMSTRI12P5_LSB)
#define BIAS2_PWD_IRADCREFMSTRI12P5_SET(x)                           (((0 | (x)) << BIAS2_PWD_IRADCREFMSTRI12P5_LSB) & BIAS2_PWD_IRADCREFMSTRI12P5_MASK)
#define BIAS2_PWD_IRADCREFMSTRI12P5_RESET                            0
#define BIAS2_PWD_IRADCREFMSTRQ12P5_MSB                              3
#define BIAS2_PWD_IRADCREFMSTRQ12P5_LSB                              3
#define BIAS2_PWD_IRADCREFMSTRQ12P5_MASK                             0x00000008
#define BIAS2_PWD_IRADCREFMSTRQ12P5_GET(x)                           (((x) & BIAS2_PWD_IRADCREFMSTRQ12P5_MASK) >> BIAS2_PWD_IRADCREFMSTRQ12P5_LSB)
#define BIAS2_PWD_IRADCREFMSTRQ12P5_SET(x)                           (((0 | (x)) << BIAS2_PWD_IRADCREFMSTRQ12P5_LSB) & BIAS2_PWD_IRADCREFMSTRQ12P5_MASK)
#define BIAS2_PWD_IRADCREFMSTRQ12P5_RESET                            0
#define BIAS2_PWD_ICDAC50_MSB                                        2
#define BIAS2_PWD_ICDAC50_LSB                                        0
#define BIAS2_PWD_ICDAC50_MASK                                       0x00000007
#define BIAS2_PWD_ICDAC50_GET(x)                                     (((x) & BIAS2_PWD_ICDAC50_MASK) >> BIAS2_PWD_ICDAC50_LSB)
#define BIAS2_PWD_ICDAC50_SET(x)                                     (((0 | (x)) << BIAS2_PWD_ICDAC50_LSB) & BIAS2_PWD_ICDAC50_MASK)
#define BIAS2_PWD_ICDAC50_RESET                                      3
#define BIAS2_ADDRESS                                                0x0078
#define BIAS2_HW_MASK                                                0xffffffff
#define BIAS2_SW_MASK                                                0xffffffff
#define BIAS2_HW_WRITE_MASK                                          0x00000000
#define BIAS2_SW_WRITE_MASK                                          0xffffffff
#define BIAS2_RSTMASK                                                0xffffffff
#define BIAS2_RESET                                                  0x00376b63

// 0x007c (BIAS3)
#define BIAS3_PWD_ICTXPC25_MSB                                       31
#define BIAS3_PWD_ICTXPC25_LSB                                       31
#define BIAS3_PWD_ICTXPC25_MASK                                      0x80000000
#define BIAS3_PWD_ICTXPC25_GET(x)                                    (((x) & BIAS3_PWD_ICTXPC25_MASK) >> BIAS3_PWD_ICTXPC25_LSB)
#define BIAS3_PWD_ICTXPC25_SET(x)                                    (((0 | (x)) << BIAS3_PWD_ICTXPC25_LSB) & BIAS3_PWD_ICTXPC25_MASK)
#define BIAS3_PWD_ICTXPC25_RESET                                     0
#define BIAS3_PWD_IRTXPC25_MSB                                       30
#define BIAS3_PWD_IRTXPC25_LSB                                       30
#define BIAS3_PWD_IRTXPC25_MASK                                      0x40000000
#define BIAS3_PWD_IRTXPC25_GET(x)                                    (((x) & BIAS3_PWD_IRTXPC25_MASK) >> BIAS3_PWD_IRTXPC25_LSB)
#define BIAS3_PWD_IRTXPC25_SET(x)                                    (((0 | (x)) << BIAS3_PWD_IRTXPC25_LSB) & BIAS3_PWD_IRTXPC25_MASK)
#define BIAS3_PWD_IRTXPC25_RESET                                     0
#define BIAS3_PWD_ICTSENS25_MSB                                      29
#define BIAS3_PWD_ICTSENS25_LSB                                      29
#define BIAS3_PWD_ICTSENS25_MASK                                     0x20000000
#define BIAS3_PWD_ICTSENS25_GET(x)                                   (((x) & BIAS3_PWD_ICTSENS25_MASK) >> BIAS3_PWD_ICTSENS25_LSB)
#define BIAS3_PWD_ICTSENS25_SET(x)                                   (((0 | (x)) << BIAS3_PWD_ICTSENS25_LSB) & BIAS3_PWD_ICTSENS25_MASK)
#define BIAS3_PWD_ICTSENS25_RESET                                    0
#define BIAS3_PWD_IRTSENS25_MSB                                      28
#define BIAS3_PWD_IRTSENS25_LSB                                      28
#define BIAS3_PWD_IRTSENS25_MASK                                     0x10000000
#define BIAS3_PWD_IRTSENS25_GET(x)                                   (((x) & BIAS3_PWD_IRTSENS25_MASK) >> BIAS3_PWD_IRTSENS25_LSB)
#define BIAS3_PWD_IRTSENS25_SET(x)                                   (((0 | (x)) << BIAS3_PWD_IRTSENS25_LSB) & BIAS3_PWD_IRTSENS25_MASK)
#define BIAS3_PWD_IRTSENS25_RESET                                    0
#define BIAS3_PWD_IC25SPARE1_MSB                                     27
#define BIAS3_PWD_IC25SPARE1_LSB                                     25
#define BIAS3_PWD_IC25SPARE1_MASK                                    0x0e000000
#define BIAS3_PWD_IC25SPARE1_GET(x)                                  (((x) & BIAS3_PWD_IC25SPARE1_MASK) >> BIAS3_PWD_IC25SPARE1_LSB)
#define BIAS3_PWD_IC25SPARE1_SET(x)                                  (((0 | (x)) << BIAS3_PWD_IC25SPARE1_LSB) & BIAS3_PWD_IC25SPARE1_MASK)
#define BIAS3_PWD_IC25SPARE1_RESET                                   3
#define BIAS3_PWD_IC25SPARE2_MSB                                     24
#define BIAS3_PWD_IC25SPARE2_LSB                                     22
#define BIAS3_PWD_IC25SPARE2_MASK                                    0x01c00000
#define BIAS3_PWD_IC25SPARE2_GET(x)                                  (((x) & BIAS3_PWD_IC25SPARE2_MASK) >> BIAS3_PWD_IC25SPARE2_LSB)
#define BIAS3_PWD_IC25SPARE2_SET(x)                                  (((0 | (x)) << BIAS3_PWD_IC25SPARE2_LSB) & BIAS3_PWD_IC25SPARE2_MASK)
#define BIAS3_PWD_IC25SPARE2_RESET                                   3
#define BIAS3_PWD_IC25SPARE3_MSB                                     21
#define BIAS3_PWD_IC25SPARE3_LSB                                     19
#define BIAS3_PWD_IC25SPARE3_MASK                                    0x00380000
#define BIAS3_PWD_IC25SPARE3_GET(x)                                  (((x) & BIAS3_PWD_IC25SPARE3_MASK) >> BIAS3_PWD_IC25SPARE3_LSB)
#define BIAS3_PWD_IC25SPARE3_SET(x)                                  (((0 | (x)) << BIAS3_PWD_IC25SPARE3_LSB) & BIAS3_PWD_IC25SPARE3_MASK)
#define BIAS3_PWD_IC25SPARE3_RESET                                   3
#define BIAS3_PWD_IC25SPARE4_MSB                                     18
#define BIAS3_PWD_IC25SPARE4_LSB                                     16
#define BIAS3_PWD_IC25SPARE4_MASK                                    0x00070000
#define BIAS3_PWD_IC25SPARE4_GET(x)                                  (((x) & BIAS3_PWD_IC25SPARE4_MASK) >> BIAS3_PWD_IC25SPARE4_LSB)
#define BIAS3_PWD_IC25SPARE4_SET(x)                                  (((0 | (x)) << BIAS3_PWD_IC25SPARE4_LSB) & BIAS3_PWD_IC25SPARE4_MASK)
#define BIAS3_PWD_IC25SPARE4_RESET                                   3
#define BIAS3_PWD_IR25SPARE1_MSB                                     15
#define BIAS3_PWD_IR25SPARE1_LSB                                     13
#define BIAS3_PWD_IR25SPARE1_MASK                                    0x0000e000
#define BIAS3_PWD_IR25SPARE1_GET(x)                                  (((x) & BIAS3_PWD_IR25SPARE1_MASK) >> BIAS3_PWD_IR25SPARE1_LSB)
#define BIAS3_PWD_IR25SPARE1_SET(x)                                  (((0 | (x)) << BIAS3_PWD_IR25SPARE1_LSB) & BIAS3_PWD_IR25SPARE1_MASK)
#define BIAS3_PWD_IR25SPARE1_RESET                                   3
#define BIAS3_PWD_IR25SPARE2_MSB                                     12
#define BIAS3_PWD_IR25SPARE2_LSB                                     10
#define BIAS3_PWD_IR25SPARE2_MASK                                    0x00001c00
#define BIAS3_PWD_IR25SPARE2_GET(x)                                  (((x) & BIAS3_PWD_IR25SPARE2_MASK) >> BIAS3_PWD_IR25SPARE2_LSB)
#define BIAS3_PWD_IR25SPARE2_SET(x)                                  (((0 | (x)) << BIAS3_PWD_IR25SPARE2_LSB) & BIAS3_PWD_IR25SPARE2_MASK)
#define BIAS3_PWD_IR25SPARE2_RESET                                   3
#define BIAS3_PWD_IR25SPARE3_MSB                                     9
#define BIAS3_PWD_IR25SPARE3_LSB                                     7
#define BIAS3_PWD_IR25SPARE3_MASK                                    0x00000380
#define BIAS3_PWD_IR25SPARE3_GET(x)                                  (((x) & BIAS3_PWD_IR25SPARE3_MASK) >> BIAS3_PWD_IR25SPARE3_LSB)
#define BIAS3_PWD_IR25SPARE3_SET(x)                                  (((0 | (x)) << BIAS3_PWD_IR25SPARE3_LSB) & BIAS3_PWD_IR25SPARE3_MASK)
#define BIAS3_PWD_IR25SPARE3_RESET                                   3
#define BIAS3_PWD_IR25SPARE4_MSB                                     6
#define BIAS3_PWD_IR25SPARE4_LSB                                     4
#define BIAS3_PWD_IR25SPARE4_MASK                                    0x00000070
#define BIAS3_PWD_IR25SPARE4_GET(x)                                  (((x) & BIAS3_PWD_IR25SPARE4_MASK) >> BIAS3_PWD_IR25SPARE4_LSB)
#define BIAS3_PWD_IR25SPARE4_SET(x)                                  (((0 | (x)) << BIAS3_PWD_IR25SPARE4_LSB) & BIAS3_PWD_IR25SPARE4_MASK)
#define BIAS3_PWD_IR25SPARE4_RESET                                   3
#define BIAS3_PWD_ICLOLDO25_MSB                                      3
#define BIAS3_PWD_ICLOLDO25_LSB                                      1
#define BIAS3_PWD_ICLOLDO25_MASK                                     0x0000000e
#define BIAS3_PWD_ICLOLDO25_GET(x)                                   (((x) & BIAS3_PWD_ICLOLDO25_MASK) >> BIAS3_PWD_ICLOLDO25_LSB)
#define BIAS3_PWD_ICLOLDO25_SET(x)                                   (((0 | (x)) << BIAS3_PWD_ICLOLDO25_LSB) & BIAS3_PWD_ICLOLDO25_MASK)
#define BIAS3_PWD_ICLOLDO25_RESET                                    3
#define BIAS3_BIAS3_SPARE_MSB                                        0
#define BIAS3_BIAS3_SPARE_LSB                                        0
#define BIAS3_BIAS3_SPARE_MASK                                       0x00000001
#define BIAS3_BIAS3_SPARE_GET(x)                                     (((x) & BIAS3_BIAS3_SPARE_MASK) >> BIAS3_BIAS3_SPARE_LSB)
#define BIAS3_BIAS3_SPARE_SET(x)                                     (((0 | (x)) << BIAS3_BIAS3_SPARE_LSB) & BIAS3_BIAS3_SPARE_MASK)
#define BIAS3_BIAS3_SPARE_RESET                                      0
#define BIAS3_ADDRESS                                                0x007c
#define BIAS3_HW_MASK                                                0xffffffff
#define BIAS3_SW_MASK                                                0xffffffff
#define BIAS3_HW_WRITE_MASK                                          0x00000000
#define BIAS3_SW_WRITE_MASK                                          0xffffffff
#define BIAS3_RSTMASK                                                0xffffffff
#define BIAS3_RESET                                                  0x06db6db6

// 0x0080 (BIAS4)
#define BIAS4_BIAS4_SEL_SPARE_MSB                                    31
#define BIAS4_BIAS4_SEL_SPARE_LSB                                    24
#define BIAS4_BIAS4_SEL_SPARE_MASK                                   0xff000000
#define BIAS4_BIAS4_SEL_SPARE_GET(x)                                 (((x) & BIAS4_BIAS4_SEL_SPARE_MASK) >> BIAS4_BIAS4_SEL_SPARE_LSB)
#define BIAS4_BIAS4_SEL_SPARE_SET(x)                                 (((0 | (x)) << BIAS4_BIAS4_SEL_SPARE_LSB) & BIAS4_BIAS4_SEL_SPARE_MASK)
#define BIAS4_BIAS4_SEL_SPARE_RESET                                  0
#define BIAS4_PWD_ICXLNA2G50_MSB                                     23
#define BIAS4_PWD_ICXLNA2G50_LSB                                     21
#define BIAS4_PWD_ICXLNA2G50_MASK                                    0x00e00000
#define BIAS4_PWD_ICXLNA2G50_GET(x)                                  (((x) & BIAS4_PWD_ICXLNA2G50_MASK) >> BIAS4_PWD_ICXLNA2G50_LSB)
#define BIAS4_PWD_ICXLNA2G50_SET(x)                                  (((0 | (x)) << BIAS4_PWD_ICXLNA2G50_LSB) & BIAS4_PWD_ICXLNA2G50_MASK)
#define BIAS4_PWD_ICXLNA2G50_RESET                                   3
#define BIAS4_PWD_ICXLNA5G50_MSB                                     20
#define BIAS4_PWD_ICXLNA5G50_LSB                                     18
#define BIAS4_PWD_ICXLNA5G50_MASK                                    0x001c0000
#define BIAS4_PWD_ICXLNA5G50_GET(x)                                  (((x) & BIAS4_PWD_ICXLNA5G50_MASK) >> BIAS4_PWD_ICXLNA5G50_LSB)
#define BIAS4_PWD_ICXLNA5G50_SET(x)                                  (((0 | (x)) << BIAS4_PWD_ICXLNA5G50_LSB) & BIAS4_PWD_ICXLNA5G50_MASK)
#define BIAS4_PWD_ICXLNA5G50_RESET                                   3
#define BIAS4_PWD_IRLOLDO25_MSB                                      17
#define BIAS4_PWD_IRLOLDO25_LSB                                      15
#define BIAS4_PWD_IRLOLDO25_MASK                                     0x00038000
#define BIAS4_PWD_IRLOLDO25_GET(x)                                   (((x) & BIAS4_PWD_IRLOLDO25_MASK) >> BIAS4_PWD_IRLOLDO25_LSB)
#define BIAS4_PWD_IRLOLDO25_SET(x)                                   (((0 | (x)) << BIAS4_PWD_IRLOLDO25_LSB) & BIAS4_PWD_IRLOLDO25_MASK)
#define BIAS4_PWD_IRLOLDO25_RESET                                    3
#define BIAS4_BIAS4_SPARE_MSB                                        14
#define BIAS4_BIAS4_SPARE_LSB                                        0
#define BIAS4_BIAS4_SPARE_MASK                                       0x00007fff
#define BIAS4_BIAS4_SPARE_GET(x)                                     (((x) & BIAS4_BIAS4_SPARE_MASK) >> BIAS4_BIAS4_SPARE_LSB)
#define BIAS4_BIAS4_SPARE_SET(x)                                     (((0 | (x)) << BIAS4_BIAS4_SPARE_LSB) & BIAS4_BIAS4_SPARE_MASK)
#define BIAS4_BIAS4_SPARE_RESET                                      0
#define BIAS4_ADDRESS                                                0x0080
#define BIAS4_HW_MASK                                                0xffffffff
#define BIAS4_SW_MASK                                                0xffffffff
#define BIAS4_HW_WRITE_MASK                                          0x00000000
#define BIAS4_SW_WRITE_MASK                                          0xffffffff
#define BIAS4_RSTMASK                                                0xffffffff
#define BIAS4_RESET                                                  0x006d8000

// 0x0084 (GAIN0)
#define GAIN0_TX6DBLOQGAIN_MSB                                       31
#define GAIN0_TX6DBLOQGAIN_LSB                                       30
#define GAIN0_TX6DBLOQGAIN_MASK                                      0xc0000000
#define GAIN0_TX6DBLOQGAIN_GET(x)                                    (((x) & GAIN0_TX6DBLOQGAIN_MASK) >> GAIN0_TX6DBLOQGAIN_LSB)
#define GAIN0_TX6DBLOQGAIN_SET(x)                                    (((0 | (x)) << GAIN0_TX6DBLOQGAIN_LSB) & GAIN0_TX6DBLOQGAIN_MASK)
#define GAIN0_TX6DBLOQGAIN_RESET                                     3
#define GAIN0_TX1DBLOQGAIN_MSB                                       29
#define GAIN0_TX1DBLOQGAIN_LSB                                       27
#define GAIN0_TX1DBLOQGAIN_MASK                                      0x38000000
#define GAIN0_TX1DBLOQGAIN_GET(x)                                    (((x) & GAIN0_TX1DBLOQGAIN_MASK) >> GAIN0_TX1DBLOQGAIN_LSB)
#define GAIN0_TX1DBLOQGAIN_SET(x)                                    (((0 | (x)) << GAIN0_TX1DBLOQGAIN_LSB) & GAIN0_TX1DBLOQGAIN_MASK)
#define GAIN0_TX1DBLOQGAIN_RESET                                     6
#define GAIN0_TXV2IGAIN_MSB                                          26
#define GAIN0_TXV2IGAIN_LSB                                          25
#define GAIN0_TXV2IGAIN_MASK                                         0x06000000
#define GAIN0_TXV2IGAIN_GET(x)                                       (((x) & GAIN0_TXV2IGAIN_MASK) >> GAIN0_TXV2IGAIN_LSB)
#define GAIN0_TXV2IGAIN_SET(x)                                       (((0 | (x)) << GAIN0_TXV2IGAIN_LSB) & GAIN0_TXV2IGAIN_MASK)
#define GAIN0_TXV2IGAIN_RESET                                        3
#define GAIN0_PABUF5GN_MSB                                           24
#define GAIN0_PABUF5GN_LSB                                           24
#define GAIN0_PABUF5GN_MASK                                          0x01000000
#define GAIN0_PABUF5GN_GET(x)                                        (((x) & GAIN0_PABUF5GN_MASK) >> GAIN0_PABUF5GN_LSB)
#define GAIN0_PABUF5GN_SET(x)                                        (((0 | (x)) << GAIN0_PABUF5GN_LSB) & GAIN0_PABUF5GN_MASK)
#define GAIN0_PABUF5GN_RESET                                         1
#define GAIN0_PADRVGN_MSB                                            23
#define GAIN0_PADRVGN_LSB                                            21
#define GAIN0_PADRVGN_MASK                                           0x00e00000
#define GAIN0_PADRVGN_GET(x)                                         (((x) & GAIN0_PADRVGN_MASK) >> GAIN0_PADRVGN_LSB)
#define GAIN0_PADRVGN_SET(x)                                         (((0 | (x)) << GAIN0_PADRVGN_LSB) & GAIN0_PADRVGN_MASK)
#define GAIN0_PADRVGN_RESET                                          7
#define GAIN0_PAOUT2GN_MSB                                           20
#define GAIN0_PAOUT2GN_LSB                                           18
#define GAIN0_PAOUT2GN_MASK                                          0x001c0000
#define GAIN0_PAOUT2GN_GET(x)                                        (((x) & GAIN0_PAOUT2GN_MASK) >> GAIN0_PAOUT2GN_LSB)
#define GAIN0_PAOUT2GN_SET(x)                                        (((0 | (x)) << GAIN0_PAOUT2GN_LSB) & GAIN0_PAOUT2GN_MASK)
#define GAIN0_PAOUT2GN_RESET                                         7
#define GAIN0_LNAON_MSB                                              17
#define GAIN0_LNAON_LSB                                              17
#define GAIN0_LNAON_MASK                                             0x00020000
#define GAIN0_LNAON_GET(x)                                           (((x) & GAIN0_LNAON_MASK) >> GAIN0_LNAON_LSB)
#define GAIN0_LNAON_SET(x)                                           (((0 | (x)) << GAIN0_LNAON_LSB) & GAIN0_LNAON_MASK)
#define GAIN0_LNAON_RESET                                            1
#define GAIN0_LNAGAIN_MSB                                            16
#define GAIN0_LNAGAIN_LSB                                            13
#define GAIN0_LNAGAIN_MASK                                           0x0001e000
#define GAIN0_LNAGAIN_GET(x)                                         (((x) & GAIN0_LNAGAIN_MASK) >> GAIN0_LNAGAIN_LSB)
#define GAIN0_LNAGAIN_SET(x)                                         (((0 | (x)) << GAIN0_LNAGAIN_LSB) & GAIN0_LNAGAIN_MASK)
#define GAIN0_LNAGAIN_RESET                                          15
#define GAIN0_RFVGA5GAIN_MSB                                         12
#define GAIN0_RFVGA5GAIN_LSB                                         11
#define GAIN0_RFVGA5GAIN_MASK                                        0x00001800
#define GAIN0_RFVGA5GAIN_GET(x)                                      (((x) & GAIN0_RFVGA5GAIN_MASK) >> GAIN0_RFVGA5GAIN_LSB)
#define GAIN0_RFVGA5GAIN_SET(x)                                      (((0 | (x)) << GAIN0_RFVGA5GAIN_LSB) & GAIN0_RFVGA5GAIN_MASK)
#define GAIN0_RFVGA5GAIN_RESET                                       3
#define GAIN0_RFGMGN_MSB                                             10
#define GAIN0_RFGMGN_LSB                                             8
#define GAIN0_RFGMGN_MASK                                            0x00000700
#define GAIN0_RFGMGN_GET(x)                                          (((x) & GAIN0_RFGMGN_MASK) >> GAIN0_RFGMGN_LSB)
#define GAIN0_RFGMGN_SET(x)                                          (((0 | (x)) << GAIN0_RFGMGN_LSB) & GAIN0_RFGMGN_MASK)
#define GAIN0_RFGMGN_RESET                                           7
#define GAIN0_RX6DBLOQGAIN_MSB                                       7
#define GAIN0_RX6DBLOQGAIN_LSB                                       6
#define GAIN0_RX6DBLOQGAIN_MASK                                      0x000000c0
#define GAIN0_RX6DBLOQGAIN_GET(x)                                    (((x) & GAIN0_RX6DBLOQGAIN_MASK) >> GAIN0_RX6DBLOQGAIN_LSB)
#define GAIN0_RX6DBLOQGAIN_SET(x)                                    (((0 | (x)) << GAIN0_RX6DBLOQGAIN_LSB) & GAIN0_RX6DBLOQGAIN_MASK)
#define GAIN0_RX6DBLOQGAIN_RESET                                     3
#define GAIN0_RX1DBLOQGAIN_MSB                                       5
#define GAIN0_RX1DBLOQGAIN_LSB                                       3
#define GAIN0_RX1DBLOQGAIN_MASK                                      0x00000038
#define GAIN0_RX1DBLOQGAIN_GET(x)                                    (((x) & GAIN0_RX1DBLOQGAIN_MASK) >> GAIN0_RX1DBLOQGAIN_LSB)
#define GAIN0_RX1DBLOQGAIN_SET(x)                                    (((0 | (x)) << GAIN0_RX1DBLOQGAIN_LSB) & GAIN0_RX1DBLOQGAIN_MASK)
#define GAIN0_RX1DBLOQGAIN_RESET                                     6
#define GAIN0_RX6DBHIQGAIN_MSB                                       2
#define GAIN0_RX6DBHIQGAIN_LSB                                       1
#define GAIN0_RX6DBHIQGAIN_MASK                                      0x00000006
#define GAIN0_RX6DBHIQGAIN_GET(x)                                    (((x) & GAIN0_RX6DBHIQGAIN_MASK) >> GAIN0_RX6DBHIQGAIN_LSB)
#define GAIN0_RX6DBHIQGAIN_SET(x)                                    (((0 | (x)) << GAIN0_RX6DBHIQGAIN_LSB) & GAIN0_RX6DBHIQGAIN_MASK)
#define GAIN0_RX6DBHIQGAIN_RESET                                     3
#define GAIN0_SPARE_MSB                                              0
#define GAIN0_SPARE_LSB                                              0
#define GAIN0_SPARE_MASK                                             0x00000001
#define GAIN0_SPARE_GET(x)                                           (((x) & GAIN0_SPARE_MASK) >> GAIN0_SPARE_LSB)
#define GAIN0_SPARE_SET(x)                                           (((0 | (x)) << GAIN0_SPARE_LSB) & GAIN0_SPARE_MASK)
#define GAIN0_SPARE_RESET                                            0
#define GAIN0_ADDRESS                                                0x0084
#define GAIN0_HW_MASK                                                0xffffffff
#define GAIN0_SW_MASK                                                0xffffffff
#define GAIN0_HW_WRITE_MASK                                          0xffffffff
#define GAIN0_SW_WRITE_MASK                                          0xffffffff
#define GAIN0_RSTMASK                                                0xffffffff
#define GAIN0_RESET                                                  0xf7fffff6

// 0x0088 (GAIN1)
#define GAIN1_TX6DBLOQGAIN_MSB                                       31
#define GAIN1_TX6DBLOQGAIN_LSB                                       30
#define GAIN1_TX6DBLOQGAIN_MASK                                      0xc0000000
#define GAIN1_TX6DBLOQGAIN_GET(x)                                    (((x) & GAIN1_TX6DBLOQGAIN_MASK) >> GAIN1_TX6DBLOQGAIN_LSB)
#define GAIN1_TX6DBLOQGAIN_SET(x)                                    (((0 | (x)) << GAIN1_TX6DBLOQGAIN_LSB) & GAIN1_TX6DBLOQGAIN_MASK)
#define GAIN1_TX6DBLOQGAIN_RESET                                     3
#define GAIN1_TX1DBLOQGAIN_MSB                                       29
#define GAIN1_TX1DBLOQGAIN_LSB                                       27
#define GAIN1_TX1DBLOQGAIN_MASK                                      0x38000000
#define GAIN1_TX1DBLOQGAIN_GET(x)                                    (((x) & GAIN1_TX1DBLOQGAIN_MASK) >> GAIN1_TX1DBLOQGAIN_LSB)
#define GAIN1_TX1DBLOQGAIN_SET(x)                                    (((0 | (x)) << GAIN1_TX1DBLOQGAIN_LSB) & GAIN1_TX1DBLOQGAIN_MASK)
#define GAIN1_TX1DBLOQGAIN_RESET                                     6
#define GAIN1_TXV2IGAIN_MSB                                          26
#define GAIN1_TXV2IGAIN_LSB                                          25
#define GAIN1_TXV2IGAIN_MASK                                         0x06000000
#define GAIN1_TXV2IGAIN_GET(x)                                       (((x) & GAIN1_TXV2IGAIN_MASK) >> GAIN1_TXV2IGAIN_LSB)
#define GAIN1_TXV2IGAIN_SET(x)                                       (((0 | (x)) << GAIN1_TXV2IGAIN_LSB) & GAIN1_TXV2IGAIN_MASK)
#define GAIN1_TXV2IGAIN_RESET                                        3
#define GAIN1_PABUF5GN_MSB                                           24
#define GAIN1_PABUF5GN_LSB                                           24
#define GAIN1_PABUF5GN_MASK                                          0x01000000
#define GAIN1_PABUF5GN_GET(x)                                        (((x) & GAIN1_PABUF5GN_MASK) >> GAIN1_PABUF5GN_LSB)
#define GAIN1_PABUF5GN_SET(x)                                        (((0 | (x)) << GAIN1_PABUF5GN_LSB) & GAIN1_PABUF5GN_MASK)
#define GAIN1_PABUF5GN_RESET                                         1
#define GAIN1_PADRVGN_MSB                                            23
#define GAIN1_PADRVGN_LSB                                            21
#define GAIN1_PADRVGN_MASK                                           0x00e00000
#define GAIN1_PADRVGN_GET(x)                                         (((x) & GAIN1_PADRVGN_MASK) >> GAIN1_PADRVGN_LSB)
#define GAIN1_PADRVGN_SET(x)                                         (((0 | (x)) << GAIN1_PADRVGN_LSB) & GAIN1_PADRVGN_MASK)
#define GAIN1_PADRVGN_RESET                                          7
#define GAIN1_PAOUT2GN_MSB                                           20
#define GAIN1_PAOUT2GN_LSB                                           18
#define GAIN1_PAOUT2GN_MASK                                          0x001c0000
#define GAIN1_PAOUT2GN_GET(x)                                        (((x) & GAIN1_PAOUT2GN_MASK) >> GAIN1_PAOUT2GN_LSB)
#define GAIN1_PAOUT2GN_SET(x)                                        (((0 | (x)) << GAIN1_PAOUT2GN_LSB) & GAIN1_PAOUT2GN_MASK)
#define GAIN1_PAOUT2GN_RESET                                         7
#define GAIN1_LNAON_MSB                                              17
#define GAIN1_LNAON_LSB                                              17
#define GAIN1_LNAON_MASK                                             0x00020000
#define GAIN1_LNAON_GET(x)                                           (((x) & GAIN1_LNAON_MASK) >> GAIN1_LNAON_LSB)
#define GAIN1_LNAON_SET(x)                                           (((0 | (x)) << GAIN1_LNAON_LSB) & GAIN1_LNAON_MASK)
#define GAIN1_LNAON_RESET                                            1
#define GAIN1_LNAGAIN_MSB                                            16
#define GAIN1_LNAGAIN_LSB                                            13
#define GAIN1_LNAGAIN_MASK                                           0x0001e000
#define GAIN1_LNAGAIN_GET(x)                                         (((x) & GAIN1_LNAGAIN_MASK) >> GAIN1_LNAGAIN_LSB)
#define GAIN1_LNAGAIN_SET(x)                                         (((0 | (x)) << GAIN1_LNAGAIN_LSB) & GAIN1_LNAGAIN_MASK)
#define GAIN1_LNAGAIN_RESET                                          15
#define GAIN1_RFVGA5GAIN_MSB                                         12
#define GAIN1_RFVGA5GAIN_LSB                                         11
#define GAIN1_RFVGA5GAIN_MASK                                        0x00001800
#define GAIN1_RFVGA5GAIN_GET(x)                                      (((x) & GAIN1_RFVGA5GAIN_MASK) >> GAIN1_RFVGA5GAIN_LSB)
#define GAIN1_RFVGA5GAIN_SET(x)                                      (((0 | (x)) << GAIN1_RFVGA5GAIN_LSB) & GAIN1_RFVGA5GAIN_MASK)
#define GAIN1_RFVGA5GAIN_RESET                                       3
#define GAIN1_RFGMGN_MSB                                             10
#define GAIN1_RFGMGN_LSB                                             8
#define GAIN1_RFGMGN_MASK                                            0x00000700
#define GAIN1_RFGMGN_GET(x)                                          (((x) & GAIN1_RFGMGN_MASK) >> GAIN1_RFGMGN_LSB)
#define GAIN1_RFGMGN_SET(x)                                          (((0 | (x)) << GAIN1_RFGMGN_LSB) & GAIN1_RFGMGN_MASK)
#define GAIN1_RFGMGN_RESET                                           7
#define GAIN1_RX6DBLOQGAIN_MSB                                       7
#define GAIN1_RX6DBLOQGAIN_LSB                                       6
#define GAIN1_RX6DBLOQGAIN_MASK                                      0x000000c0
#define GAIN1_RX6DBLOQGAIN_GET(x)                                    (((x) & GAIN1_RX6DBLOQGAIN_MASK) >> GAIN1_RX6DBLOQGAIN_LSB)
#define GAIN1_RX6DBLOQGAIN_SET(x)                                    (((0 | (x)) << GAIN1_RX6DBLOQGAIN_LSB) & GAIN1_RX6DBLOQGAIN_MASK)
#define GAIN1_RX6DBLOQGAIN_RESET                                     3
#define GAIN1_RX1DBLOQGAIN_MSB                                       5
#define GAIN1_RX1DBLOQGAIN_LSB                                       3
#define GAIN1_RX1DBLOQGAIN_MASK                                      0x00000038
#define GAIN1_RX1DBLOQGAIN_GET(x)                                    (((x) & GAIN1_RX1DBLOQGAIN_MASK) >> GAIN1_RX1DBLOQGAIN_LSB)
#define GAIN1_RX1DBLOQGAIN_SET(x)                                    (((0 | (x)) << GAIN1_RX1DBLOQGAIN_LSB) & GAIN1_RX1DBLOQGAIN_MASK)
#define GAIN1_RX1DBLOQGAIN_RESET                                     6
#define GAIN1_RX6DBHIQGAIN_MSB                                       2
#define GAIN1_RX6DBHIQGAIN_LSB                                       1
#define GAIN1_RX6DBHIQGAIN_MASK                                      0x00000006
#define GAIN1_RX6DBHIQGAIN_GET(x)                                    (((x) & GAIN1_RX6DBHIQGAIN_MASK) >> GAIN1_RX6DBHIQGAIN_LSB)
#define GAIN1_RX6DBHIQGAIN_SET(x)                                    (((0 | (x)) << GAIN1_RX6DBHIQGAIN_LSB) & GAIN1_RX6DBHIQGAIN_MASK)
#define GAIN1_RX6DBHIQGAIN_RESET                                     3
#define GAIN1_SPARE_MSB                                              0
#define GAIN1_SPARE_LSB                                              0
#define GAIN1_SPARE_MASK                                             0x00000001
#define GAIN1_SPARE_GET(x)                                           (((x) & GAIN1_SPARE_MASK) >> GAIN1_SPARE_LSB)
#define GAIN1_SPARE_SET(x)                                           (((0 | (x)) << GAIN1_SPARE_LSB) & GAIN1_SPARE_MASK)
#define GAIN1_SPARE_RESET                                            0
#define GAIN1_ADDRESS                                                0x0088
#define GAIN1_HW_MASK                                                0xffffffff
#define GAIN1_SW_MASK                                                0xffffffff
#define GAIN1_HW_WRITE_MASK                                          0xffffffff
#define GAIN1_SW_WRITE_MASK                                          0xffffffff
#define GAIN1_RSTMASK                                                0xffffffff
#define GAIN1_RESET                                                  0xf7fffff6

// 0x008c (TOP0)
#define TOP0_LOCALTXGAIN_MSB                                         31
#define TOP0_LOCALTXGAIN_LSB                                         31
#define TOP0_LOCALTXGAIN_MASK                                        0x80000000
#define TOP0_LOCALTXGAIN_GET(x)                                      (((x) & TOP0_LOCALTXGAIN_MASK) >> TOP0_LOCALTXGAIN_LSB)
#define TOP0_LOCALTXGAIN_SET(x)                                      (((0 | (x)) << TOP0_LOCALTXGAIN_LSB) & TOP0_LOCALTXGAIN_MASK)
#define TOP0_LOCALTXGAIN_RESET                                       0
#define TOP0_LOCALRXGAIN_MSB                                         30
#define TOP0_LOCALRXGAIN_LSB                                         30
#define TOP0_LOCALRXGAIN_MASK                                        0x40000000
#define TOP0_LOCALRXGAIN_GET(x)                                      (((x) & TOP0_LOCALRXGAIN_MASK) >> TOP0_LOCALRXGAIN_LSB)
#define TOP0_LOCALRXGAIN_SET(x)                                      (((0 | (x)) << TOP0_LOCALRXGAIN_LSB) & TOP0_LOCALRXGAIN_MASK)
#define TOP0_LOCALRXGAIN_RESET                                       0
#define TOP0_LOCALMODE_MSB                                           29
#define TOP0_LOCALMODE_LSB                                           29
#define TOP0_LOCALMODE_MASK                                          0x20000000
#define TOP0_LOCALMODE_GET(x)                                        (((x) & TOP0_LOCALMODE_MASK) >> TOP0_LOCALMODE_LSB)
#define TOP0_LOCALMODE_SET(x)                                        (((0 | (x)) << TOP0_LOCALMODE_LSB) & TOP0_LOCALMODE_MASK)
#define TOP0_LOCALMODE_RESET                                         0
#define TOP0_CALFC_MSB                                               28
#define TOP0_CALFC_LSB                                               27
#define TOP0_CALFC_MASK                                              0x18000000
#define TOP0_CALFC_GET(x)                                            (((x) & TOP0_CALFC_MASK) >> TOP0_CALFC_LSB)
#define TOP0_CALFC_SET(x)                                            (((0 | (x)) << TOP0_CALFC_LSB) & TOP0_CALFC_MASK)
#define TOP0_CALFC_RESET                                             0
#define TOP0_CALDC_MSB                                               26
#define TOP0_CALDC_LSB                                               25
#define TOP0_CALDC_MASK                                              0x06000000
#define TOP0_CALDC_GET(x)                                            (((x) & TOP0_CALDC_MASK) >> TOP0_CALDC_LSB)
#define TOP0_CALDC_SET(x)                                            (((0 | (x)) << TOP0_CALDC_LSB) & TOP0_CALDC_MASK)
#define TOP0_CALDC_RESET                                             0
#define TOP0_CAL_RESIDUE_MSB                                         24
#define TOP0_CAL_RESIDUE_LSB                                         23
#define TOP0_CAL_RESIDUE_MASK                                        0x01800000
#define TOP0_CAL_RESIDUE_GET(x)                                      (((x) & TOP0_CAL_RESIDUE_MASK) >> TOP0_CAL_RESIDUE_LSB)
#define TOP0_CAL_RESIDUE_SET(x)                                      (((0 | (x)) << TOP0_CAL_RESIDUE_LSB) & TOP0_CAL_RESIDUE_MASK)
#define TOP0_CAL_RESIDUE_RESET                                       0
#define TOP0_CALTX_MSB                                               22
#define TOP0_CALTX_LSB                                               21
#define TOP0_CALTX_MASK                                              0x00600000
#define TOP0_CALTX_GET(x)                                            (((x) & TOP0_CALTX_MASK) >> TOP0_CALTX_LSB)
#define TOP0_CALTX_SET(x)                                            (((0 | (x)) << TOP0_CALTX_LSB) & TOP0_CALTX_MASK)
#define TOP0_CALTX_RESET                                             0
#define TOP0_BMODE_MSB                                               20
#define TOP0_BMODE_LSB                                               20
#define TOP0_BMODE_MASK                                              0x00100000
#define TOP0_BMODE_GET(x)                                            (((x) & TOP0_BMODE_MASK) >> TOP0_BMODE_LSB)
#define TOP0_BMODE_SET(x)                                            (((0 | (x)) << TOP0_BMODE_LSB) & TOP0_BMODE_MASK)
#define TOP0_BMODE_RESET                                             1
#define TOP0_BMODERXTX_MSB                                           19
#define TOP0_BMODERXTX_LSB                                           18
#define TOP0_BMODERXTX_MASK                                          0x000c0000
#define TOP0_BMODERXTX_GET(x)                                        (((x) & TOP0_BMODERXTX_MASK) >> TOP0_BMODERXTX_LSB)
#define TOP0_BMODERXTX_SET(x)                                        (((0 | (x)) << TOP0_BMODERXTX_LSB) & TOP0_BMODERXTX_MASK)
#define TOP0_BMODERXTX_RESET                                         0
#define TOP0_TURBOMODE_MSB                                           17
#define TOP0_TURBOMODE_LSB                                           17
#define TOP0_TURBOMODE_MASK                                          0x00020000
#define TOP0_TURBOMODE_GET(x)                                        (((x) & TOP0_TURBOMODE_MASK) >> TOP0_TURBOMODE_LSB)
#define TOP0_TURBOMODE_SET(x)                                        (((0 | (x)) << TOP0_TURBOMODE_LSB) & TOP0_TURBOMODE_MASK)
#define TOP0_TURBOMODE_RESET                                         0
#define TOP0_SYNTHON_MSB                                             16
#define TOP0_SYNTHON_LSB                                             16
#define TOP0_SYNTHON_MASK                                            0x00010000
#define TOP0_SYNTHON_GET(x)                                          (((x) & TOP0_SYNTHON_MASK) >> TOP0_SYNTHON_LSB)
#define TOP0_SYNTHON_SET(x)                                          (((0 | (x)) << TOP0_SYNTHON_LSB) & TOP0_SYNTHON_MASK)
#define TOP0_SYNTHON_RESET                                           0
#define TOP0_RXON_MSB                                                15
#define TOP0_RXON_LSB                                                14
#define TOP0_RXON_MASK                                               0x0000c000
#define TOP0_RXON_GET(x)                                             (((x) & TOP0_RXON_MASK) >> TOP0_RXON_LSB)
#define TOP0_RXON_SET(x)                                             (((0 | (x)) << TOP0_RXON_LSB) & TOP0_RXON_MASK)
#define TOP0_RXON_RESET                                              0
#define TOP0_TXON_MSB                                                13
#define TOP0_TXON_LSB                                                12
#define TOP0_TXON_MASK                                               0x00003000
#define TOP0_TXON_GET(x)                                             (((x) & TOP0_TXON_MASK) >> TOP0_TXON_LSB)
#define TOP0_TXON_SET(x)                                             (((0 | (x)) << TOP0_TXON_LSB) & TOP0_TXON_MASK)
#define TOP0_TXON_RESET                                              0
#define TOP0_PAON_MSB                                                11
#define TOP0_PAON_LSB                                                10
#define TOP0_PAON_MASK                                               0x00000c00
#define TOP0_PAON_GET(x)                                             (((x) & TOP0_PAON_MASK) >> TOP0_PAON_LSB)
#define TOP0_PAON_SET(x)                                             (((0 | (x)) << TOP0_PAON_LSB) & TOP0_PAON_MASK)
#define TOP0_PAON_RESET                                              0
#define TOP0_XLNAON_MSB                                              9
#define TOP0_XLNAON_LSB                                              8
#define TOP0_XLNAON_MASK                                             0x00000300
#define TOP0_XLNAON_GET(x)                                           (((x) & TOP0_XLNAON_MASK) >> TOP0_XLNAON_LSB)
#define TOP0_XLNAON_SET(x)                                           (((0 | (x)) << TOP0_XLNAON_LSB) & TOP0_XLNAON_MASK)
#define TOP0_XLNAON_RESET                                            1
#define TOP0_XPAON_MSB                                               7
#define TOP0_XPAON_LSB                                               7
#define TOP0_XPAON_MASK                                              0x00000080
#define TOP0_XPAON_GET(x)                                            (((x) & TOP0_XPAON_MASK) >> TOP0_XPAON_LSB)
#define TOP0_XPAON_SET(x)                                            (((0 | (x)) << TOP0_XPAON_LSB) & TOP0_XPAON_MASK)
#define TOP0_XPAON_RESET                                             0
#define TOP0_LOCALXTAL_MSB                                           6
#define TOP0_LOCALXTAL_LSB                                           6
#define TOP0_LOCALXTAL_MASK                                          0x00000040
#define TOP0_LOCALXTAL_GET(x)                                        (((x) & TOP0_LOCALXTAL_MASK) >> TOP0_LOCALXTAL_LSB)
#define TOP0_LOCALXTAL_SET(x)                                        (((0 | (x)) << TOP0_LOCALXTAL_LSB) & TOP0_LOCALXTAL_MASK)
#define TOP0_LOCALXTAL_RESET                                         0
#define TOP0_PWDCLKIN_MSB                                            5
#define TOP0_PWDCLKIN_LSB                                            5
#define TOP0_PWDCLKIN_MASK                                           0x00000020
#define TOP0_PWDCLKIN_GET(x)                                         (((x) & TOP0_PWDCLKIN_MASK) >> TOP0_PWDCLKIN_LSB)
#define TOP0_PWDCLKIN_SET(x)                                         (((0 | (x)) << TOP0_PWDCLKIN_LSB) & TOP0_PWDCLKIN_MASK)
#define TOP0_PWDCLKIN_RESET                                          0
#define TOP0_OSCON_MSB                                               4
#define TOP0_OSCON_LSB                                               4
#define TOP0_OSCON_MASK                                              0x00000010
#define TOP0_OSCON_GET(x)                                            (((x) & TOP0_OSCON_MASK) >> TOP0_OSCON_LSB)
#define TOP0_OSCON_SET(x)                                            (((0 | (x)) << TOP0_OSCON_LSB) & TOP0_OSCON_MASK)
#define TOP0_OSCON_RESET                                             1
#define TOP0_SCLKEN_FORCE_MSB                                        3
#define TOP0_SCLKEN_FORCE_LSB                                        3
#define TOP0_SCLKEN_FORCE_MASK                                       0x00000008
#define TOP0_SCLKEN_FORCE_GET(x)                                     (((x) & TOP0_SCLKEN_FORCE_MASK) >> TOP0_SCLKEN_FORCE_LSB)
#define TOP0_SCLKEN_FORCE_SET(x)                                     (((0 | (x)) << TOP0_SCLKEN_FORCE_LSB) & TOP0_SCLKEN_FORCE_MASK)
#define TOP0_SCLKEN_FORCE_RESET                                      0
#define TOP0_SYNTHON_FORCE_MSB                                       2
#define TOP0_SYNTHON_FORCE_LSB                                       2
#define TOP0_SYNTHON_FORCE_MASK                                      0x00000004
#define TOP0_SYNTHON_FORCE_GET(x)                                    (((x) & TOP0_SYNTHON_FORCE_MASK) >> TOP0_SYNTHON_FORCE_LSB)
#define TOP0_SYNTHON_FORCE_SET(x)                                    (((0 | (x)) << TOP0_SYNTHON_FORCE_LSB) & TOP0_SYNTHON_FORCE_MASK)
#define TOP0_SYNTHON_FORCE_RESET                                     0
#define TOP0_PWDBIAS_MSB                                             1
#define TOP0_PWDBIAS_LSB                                             1
#define TOP0_PWDBIAS_MASK                                            0x00000002
#define TOP0_PWDBIAS_GET(x)                                          (((x) & TOP0_PWDBIAS_MASK) >> TOP0_PWDBIAS_LSB)
#define TOP0_PWDBIAS_SET(x)                                          (((0 | (x)) << TOP0_PWDBIAS_LSB) & TOP0_PWDBIAS_MASK)
#define TOP0_PWDBIAS_RESET                                           0
#define TOP0_FORCEMSBLOW_MSB                                         0
#define TOP0_FORCEMSBLOW_LSB                                         0
#define TOP0_FORCEMSBLOW_MASK                                        0x00000001
#define TOP0_FORCEMSBLOW_GET(x)                                      (((x) & TOP0_FORCEMSBLOW_MASK) >> TOP0_FORCEMSBLOW_LSB)
#define TOP0_FORCEMSBLOW_SET(x)                                      (((0 | (x)) << TOP0_FORCEMSBLOW_LSB) & TOP0_FORCEMSBLOW_MASK)
#define TOP0_FORCEMSBLOW_RESET                                       0
#define TOP0_ADDRESS                                                 0x008c
#define TOP0_HW_MASK                                                 0xffffffff
#define TOP0_SW_MASK                                                 0xffffffff
#define TOP0_HW_WRITE_MASK                                           0x1ff3fc30
#define TOP0_SW_WRITE_MASK                                           0xffffffff
#define TOP0_RSTMASK                                                 0xffffffff
#define TOP0_RESET                                                   0x00100110

// 0x0090 (TOP1)
#define TOP1_REVID_MSB                                               31
#define TOP1_REVID_LSB                                               29
#define TOP1_REVID_MASK                                              0xe0000000
#define TOP1_REVID_GET(x)                                            (((x) & TOP1_REVID_MASK) >> TOP1_REVID_LSB)
#define TOP1_REVID_SET(x)                                            (((0 | (x)) << TOP1_REVID_LSB) & TOP1_REVID_MASK)
#define TOP1_REVID_RESET                                             0
#define TOP1_INT2PAD_MSB                                             28
#define TOP1_INT2PAD_LSB                                             28
#define TOP1_INT2PAD_MASK                                            0x10000000
#define TOP1_INT2PAD_GET(x)                                          (((x) & TOP1_INT2PAD_MASK) >> TOP1_INT2PAD_LSB)
#define TOP1_INT2PAD_SET(x)                                          (((0 | (x)) << TOP1_INT2PAD_LSB) & TOP1_INT2PAD_MASK)
#define TOP1_INT2PAD_RESET                                           0
#define TOP1_INTH2PAD_MSB                                            27
#define TOP1_INTH2PAD_LSB                                            27
#define TOP1_INTH2PAD_MASK                                           0x08000000
#define TOP1_INTH2PAD_GET(x)                                         (((x) & TOP1_INTH2PAD_MASK) >> TOP1_INTH2PAD_LSB)
#define TOP1_INTH2PAD_SET(x)                                         (((0 | (x)) << TOP1_INTH2PAD_LSB) & TOP1_INTH2PAD_MASK)
#define TOP1_INTH2PAD_RESET                                          0
#define TOP1_PAD2GND_MSB                                             26
#define TOP1_PAD2GND_LSB                                             26
#define TOP1_PAD2GND_MASK                                            0x04000000
#define TOP1_PAD2GND_GET(x)                                          (((x) & TOP1_PAD2GND_MASK) >> TOP1_PAD2GND_LSB)
#define TOP1_PAD2GND_SET(x)                                          (((0 | (x)) << TOP1_PAD2GND_LSB) & TOP1_PAD2GND_MASK)
#define TOP1_PAD2GND_RESET                                           0
#define TOP1_INT2GND_MSB                                             25
#define TOP1_INT2GND_LSB                                             25
#define TOP1_INT2GND_MASK                                            0x02000000
#define TOP1_INT2GND_GET(x)                                          (((x) & TOP1_INT2GND_MASK) >> TOP1_INT2GND_LSB)
#define TOP1_INT2GND_SET(x)                                          (((0 | (x)) << TOP1_INT2GND_LSB) & TOP1_INT2GND_MASK)
#define TOP1_INT2GND_RESET                                           0
#define TOP1_LOCALADDAC_MSB                                          24
#define TOP1_LOCALADDAC_LSB                                          24
#define TOP1_LOCALADDAC_MASK                                         0x01000000
#define TOP1_LOCALADDAC_GET(x)                                       (((x) & TOP1_LOCALADDAC_MASK) >> TOP1_LOCALADDAC_LSB)
#define TOP1_LOCALADDAC_SET(x)                                       (((0 | (x)) << TOP1_LOCALADDAC_LSB) & TOP1_LOCALADDAC_MASK)
#define TOP1_LOCALADDAC_RESET                                        0
#define TOP1_PWDPLL_MSB                                              23
#define TOP1_PWDPLL_LSB                                              23
#define TOP1_PWDPLL_MASK                                             0x00800000
#define TOP1_PWDPLL_GET(x)                                           (((x) & TOP1_PWDPLL_MASK) >> TOP1_PWDPLL_LSB)
#define TOP1_PWDPLL_SET(x)                                           (((0 | (x)) << TOP1_PWDPLL_LSB) & TOP1_PWDPLL_MASK)
#define TOP1_PWDPLL_RESET                                            0
#define TOP1_PWDADC_MSB                                              22
#define TOP1_PWDADC_LSB                                              21
#define TOP1_PWDADC_MASK                                             0x00600000
#define TOP1_PWDADC_GET(x)                                           (((x) & TOP1_PWDADC_MASK) >> TOP1_PWDADC_LSB)
#define TOP1_PWDADC_SET(x)                                           (((0 | (x)) << TOP1_PWDADC_LSB) & TOP1_PWDADC_MASK)
#define TOP1_PWDADC_RESET                                            0
#define TOP1_PWDDAC_MSB                                              20
#define TOP1_PWDDAC_LSB                                              19
#define TOP1_PWDDAC_MASK                                             0x00180000
#define TOP1_PWDDAC_GET(x)                                           (((x) & TOP1_PWDDAC_MASK) >> TOP1_PWDDAC_LSB)
#define TOP1_PWDDAC_SET(x)                                           (((0 | (x)) << TOP1_PWDDAC_LSB) & TOP1_PWDDAC_MASK)
#define TOP1_PWDDAC_RESET                                            0
#define TOP1_DACLPMODE_MSB                                           18
#define TOP1_DACLPMODE_LSB                                           18
#define TOP1_DACLPMODE_MASK                                          0x00040000
#define TOP1_DACLPMODE_GET(x)                                        (((x) & TOP1_DACLPMODE_MASK) >> TOP1_DACLPMODE_LSB)
#define TOP1_DACLPMODE_SET(x)                                        (((0 | (x)) << TOP1_DACLPMODE_LSB) & TOP1_DACLPMODE_MASK)
#define TOP1_DACLPMODE_RESET                                         0
#define TOP1_INV_CLK160_ADC_MSB                                      17
#define TOP1_INV_CLK160_ADC_LSB                                      17
#define TOP1_INV_CLK160_ADC_MASK                                     0x00020000
#define TOP1_INV_CLK160_ADC_GET(x)                                   (((x) & TOP1_INV_CLK160_ADC_MASK) >> TOP1_INV_CLK160_ADC_LSB)
#define TOP1_INV_CLK160_ADC_SET(x)                                   (((0 | (x)) << TOP1_INV_CLK160_ADC_LSB) & TOP1_INV_CLK160_ADC_MASK)
#define TOP1_INV_CLK160_ADC_RESET                                    0
#define TOP1_PLL_ATB_MSB                                             16
#define TOP1_PLL_ATB_LSB                                             15
#define TOP1_PLL_ATB_MASK                                            0x00018000
#define TOP1_PLL_ATB_GET(x)                                          (((x) & TOP1_PLL_ATB_MASK) >> TOP1_PLL_ATB_LSB)
#define TOP1_PLL_ATB_SET(x)                                          (((0 | (x)) << TOP1_PLL_ATB_LSB) & TOP1_PLL_ATB_MASK)
#define TOP1_PLL_ATB_RESET                                           0
#define TOP1_PLL_FILTER_MSB                                          14
#define TOP1_PLL_FILTER_LSB                                          7
#define TOP1_PLL_FILTER_MASK                                         0x00007f80
#define TOP1_PLL_FILTER_GET(x)                                       (((x) & TOP1_PLL_FILTER_MASK) >> TOP1_PLL_FILTER_LSB)
#define TOP1_PLL_FILTER_SET(x)                                       (((0 | (x)) << TOP1_PLL_FILTER_LSB) & TOP1_PLL_FILTER_MASK)
#define TOP1_PLL_FILTER_RESET                                        52
#define TOP1_PLL_ICP_MSB                                             6
#define TOP1_PLL_ICP_LSB                                             4
#define TOP1_PLL_ICP_MASK                                            0x00000070
#define TOP1_PLL_ICP_GET(x)                                          (((x) & TOP1_PLL_ICP_MASK) >> TOP1_PLL_ICP_LSB)
#define TOP1_PLL_ICP_SET(x)                                          (((0 | (x)) << TOP1_PLL_ICP_LSB) & TOP1_PLL_ICP_MASK)
#define TOP1_PLL_ICP_RESET                                           5
#define TOP1_PLL_SCLAMP_MSB                                          3
#define TOP1_PLL_SCLAMP_LSB                                          1
#define TOP1_PLL_SCLAMP_MASK                                         0x0000000e
#define TOP1_PLL_SCLAMP_GET(x)                                       (((x) & TOP1_PLL_SCLAMP_MASK) >> TOP1_PLL_SCLAMP_LSB)
#define TOP1_PLL_SCLAMP_SET(x)                                       (((0 | (x)) << TOP1_PLL_SCLAMP_LSB) & TOP1_PLL_SCLAMP_MASK)
#define TOP1_PLL_SCLAMP_RESET                                        5
#define TOP1_PLL_SVREG_MSB                                           0
#define TOP1_PLL_SVREG_LSB                                           0
#define TOP1_PLL_SVREG_MASK                                          0x00000001
#define TOP1_PLL_SVREG_GET(x)                                        (((x) & TOP1_PLL_SVREG_MASK) >> TOP1_PLL_SVREG_LSB)
#define TOP1_PLL_SVREG_SET(x)                                        (((0 | (x)) << TOP1_PLL_SVREG_LSB) & TOP1_PLL_SVREG_MASK)
#define TOP1_PLL_SVREG_RESET                                         1
#define TOP1_ADDRESS                                                 0x0090
#define TOP1_HW_MASK                                                 0xffffffff
#define TOP1_SW_MASK                                                 0xffffffff
#define TOP1_HW_WRITE_MASK                                           0xe0f80000
#define TOP1_SW_WRITE_MASK                                           0x1fffffff
#define TOP1_RSTMASK                                                 0xffffffff
#define TOP1_RESET                                                   0x00001a5b

// 0x0094 (TOP2)
#define TOP2_XPABIAS_LVL_MSB                                         31
#define TOP2_XPABIAS_LVL_LSB                                         30
#define TOP2_XPABIAS_LVL_MASK                                        0xc0000000
#define TOP2_XPABIAS_LVL_GET(x)                                      (((x) & TOP2_XPABIAS_LVL_MASK) >> TOP2_XPABIAS_LVL_LSB)
#define TOP2_XPABIAS_LVL_SET(x)                                      (((0 | (x)) << TOP2_XPABIAS_LVL_LSB) & TOP2_XPABIAS_LVL_MASK)
#define TOP2_XPABIAS_LVL_RESET                                       1
#define TOP2_FORCE_XLDO_ON_MSB                                       29
#define TOP2_FORCE_XLDO_ON_LSB                                       29
#define TOP2_FORCE_XLDO_ON_MASK                                      0x20000000
#define TOP2_FORCE_XLDO_ON_GET(x)                                    (((x) & TOP2_FORCE_XLDO_ON_MASK) >> TOP2_FORCE_XLDO_ON_LSB)
#define TOP2_FORCE_XLDO_ON_SET(x)                                    (((0 | (x)) << TOP2_FORCE_XLDO_ON_LSB) & TOP2_FORCE_XLDO_ON_MASK)
#define TOP2_FORCE_XLDO_ON_RESET                                     0
#define TOP2_XLNABUFMODE_MSB                                         28
#define TOP2_XLNABUFMODE_LSB                                         28
#define TOP2_XLNABUFMODE_MASK                                        0x10000000
#define TOP2_XLNABUFMODE_GET(x)                                      (((x) & TOP2_XLNABUFMODE_MASK) >> TOP2_XLNABUFMODE_LSB)
#define TOP2_XLNABUFMODE_SET(x)                                      (((0 | (x)) << TOP2_XLNABUFMODE_LSB) & TOP2_XLNABUFMODE_MASK)
#define TOP2_XLNABUFMODE_RESET                                       0
#define TOP2_XLNAISEL_MSB                                            27
#define TOP2_XLNAISEL_LSB                                            26
#define TOP2_XLNAISEL_MASK                                           0x0c000000
#define TOP2_XLNAISEL_GET(x)                                         (((x) & TOP2_XLNAISEL_MASK) >> TOP2_XLNAISEL_LSB)
#define TOP2_XLNAISEL_SET(x)                                         (((0 | (x)) << TOP2_XLNAISEL_LSB) & TOP2_XLNAISEL_MASK)
#define TOP2_XLNAISEL_RESET                                          2
#define TOP2_XLNABUFIN_MSB                                           25
#define TOP2_XLNABUFIN_LSB                                           25
#define TOP2_XLNABUFIN_MASK                                          0x02000000
#define TOP2_XLNABUFIN_GET(x)                                        (((x) & TOP2_XLNABUFIN_MASK) >> TOP2_XLNABUFIN_LSB)
#define TOP2_XLNABUFIN_SET(x)                                        (((0 | (x)) << TOP2_XLNABUFIN_LSB) & TOP2_XLNABUFIN_MASK)
#define TOP2_XLNABUFIN_RESET                                         0
#define TOP2_NOTCXODET_MSB                                           24
#define TOP2_NOTCXODET_LSB                                           24
#define TOP2_NOTCXODET_MASK                                          0x01000000
#define TOP2_NOTCXODET_GET(x)                                        (((x) & TOP2_NOTCXODET_MASK) >> TOP2_NOTCXODET_LSB)
#define TOP2_NOTCXODET_SET(x)                                        (((0 | (x)) << TOP2_NOTCXODET_LSB) & TOP2_NOTCXODET_MASK)
#define TOP2_NOTCXODET_RESET                                         0
#define TOP2_PWDXINPAD_MSB                                           23
#define TOP2_PWDXINPAD_LSB                                           23
#define TOP2_PWDXINPAD_MASK                                          0x00800000
#define TOP2_PWDXINPAD_GET(x)                                        (((x) & TOP2_PWDXINPAD_MASK) >> TOP2_PWDXINPAD_LSB)
#define TOP2_PWDXINPAD_SET(x)                                        (((0 | (x)) << TOP2_PWDXINPAD_LSB) & TOP2_PWDXINPAD_MASK)
#define TOP2_PWDXINPAD_RESET                                         0
#define TOP2_PWDCLKIND_MSB                                           22
#define TOP2_PWDCLKIND_LSB                                           22
#define TOP2_PWDCLKIND_MASK                                          0x00400000
#define TOP2_PWDCLKIND_GET(x)                                        (((x) & TOP2_PWDCLKIND_MASK) >> TOP2_PWDCLKIND_LSB)
#define TOP2_PWDCLKIND_SET(x)                                        (((0 | (x)) << TOP2_PWDCLKIND_LSB) & TOP2_PWDCLKIND_MASK)
#define TOP2_PWDCLKIND_RESET                                         0
#define TOP2_LOCALBIAS_MSB                                           21
#define TOP2_LOCALBIAS_LSB                                           21
#define TOP2_LOCALBIAS_MASK                                          0x00200000
#define TOP2_LOCALBIAS_GET(x)                                        (((x) & TOP2_LOCALBIAS_MASK) >> TOP2_LOCALBIAS_LSB)
#define TOP2_LOCALBIAS_SET(x)                                        (((0 | (x)) << TOP2_LOCALBIAS_LSB) & TOP2_LOCALBIAS_MASK)
#define TOP2_LOCALBIAS_RESET                                         0
#define TOP2_LOCALBIAS2X_MSB                                         20
#define TOP2_LOCALBIAS2X_LSB                                         20
#define TOP2_LOCALBIAS2X_MASK                                        0x00100000
#define TOP2_LOCALBIAS2X_GET(x)                                      (((x) & TOP2_LOCALBIAS2X_MASK) >> TOP2_LOCALBIAS2X_LSB)
#define TOP2_LOCALBIAS2X_SET(x)                                      (((0 | (x)) << TOP2_LOCALBIAS2X_LSB) & TOP2_LOCALBIAS2X_MASK)
#define TOP2_LOCALBIAS2X_RESET                                       1
#define TOP2_XTALDIV_MSB                                             19
#define TOP2_XTALDIV_LSB                                             18
#define TOP2_XTALDIV_MASK                                            0x000c0000
#define TOP2_XTALDIV_GET(x)                                          (((x) & TOP2_XTALDIV_MASK) >> TOP2_XTALDIV_LSB)
#define TOP2_XTALDIV_SET(x)                                          (((0 | (x)) << TOP2_XTALDIV_LSB) & TOP2_XTALDIV_MASK)
#define TOP2_XTALDIV_RESET                                           0
#define TOP2_TXPC_NEGOUT_MSB                                         17
#define TOP2_TXPC_NEGOUT_LSB                                         17
#define TOP2_TXPC_NEGOUT_MASK                                        0x00020000
#define TOP2_TXPC_NEGOUT_GET(x)                                      (((x) & TOP2_TXPC_NEGOUT_MASK) >> TOP2_TXPC_NEGOUT_LSB)
#define TOP2_TXPC_NEGOUT_SET(x)                                      (((0 | (x)) << TOP2_TXPC_NEGOUT_LSB) & TOP2_TXPC_NEGOUT_MASK)
#define TOP2_TXPC_NEGOUT_RESET                                       0
#define TOP2_TXPC_TEST_MSB                                           16
#define TOP2_TXPC_TEST_LSB                                           16
#define TOP2_TXPC_TEST_MASK                                          0x00010000
#define TOP2_TXPC_TEST_GET(x)                                        (((x) & TOP2_TXPC_TEST_MASK) >> TOP2_TXPC_TEST_LSB)
#define TOP2_TXPC_TEST_SET(x)                                        (((0 | (x)) << TOP2_TXPC_TEST_LSB) & TOP2_TXPC_TEST_MASK)
#define TOP2_TXPC_TEST_RESET                                         0
#define TOP2_TXPC_TESTDAC_MSB                                        15
#define TOP2_TXPC_TESTDAC_LSB                                        10
#define TOP2_TXPC_TESTDAC_MASK                                       0x0000fc00
#define TOP2_TXPC_TESTDAC_GET(x)                                     (((x) & TOP2_TXPC_TESTDAC_MASK) >> TOP2_TXPC_TESTDAC_LSB)
#define TOP2_TXPC_TESTDAC_SET(x)                                     (((0 | (x)) << TOP2_TXPC_TESTDAC_LSB) & TOP2_TXPC_TESTDAC_MASK)
#define TOP2_TXPC_TESTDAC_RESET                                      32
#define TOP2_TXPC_TESTGAIN_MSB                                       9
#define TOP2_TXPC_TESTGAIN_LSB                                       8
#define TOP2_TXPC_TESTGAIN_MASK                                      0x00000300
#define TOP2_TXPC_TESTGAIN_GET(x)                                    (((x) & TOP2_TXPC_TESTGAIN_MASK) >> TOP2_TXPC_TESTGAIN_LSB)
#define TOP2_TXPC_TESTGAIN_SET(x)                                    (((0 | (x)) << TOP2_TXPC_TESTGAIN_LSB) & TOP2_TXPC_TESTGAIN_MASK)
#define TOP2_TXPC_TESTGAIN_RESET                                     0
#define TOP2_TXPC_TESTPWD_MSB                                        7
#define TOP2_TXPC_TESTPWD_LSB                                        7
#define TOP2_TXPC_TESTPWD_MASK                                       0x00000080
#define TOP2_TXPC_TESTPWD_GET(x)                                     (((x) & TOP2_TXPC_TESTPWD_MASK) >> TOP2_TXPC_TESTPWD_LSB)
#define TOP2_TXPC_TESTPWD_SET(x)                                     (((0 | (x)) << TOP2_TXPC_TESTPWD_LSB) & TOP2_TXPC_TESTPWD_MASK)
#define TOP2_TXPC_TESTPWD_RESET                                      0
#define TOP2_TXPC_XPDBS_MSB                                          6
#define TOP2_TXPC_XPDBS_LSB                                          4
#define TOP2_TXPC_XPDBS_MASK                                         0x00000070
#define TOP2_TXPC_XPDBS_GET(x)                                       (((x) & TOP2_TXPC_XPDBS_MASK) >> TOP2_TXPC_XPDBS_LSB)
#define TOP2_TXPC_XPDBS_SET(x)                                       (((0 | (x)) << TOP2_TXPC_XPDBS_LSB) & TOP2_TXPC_XPDBS_MASK)
#define TOP2_TXPC_XPDBS_RESET                                        0
#define TOP2_TXPC_CLKDELAY_MSB                                       3
#define TOP2_TXPC_CLKDELAY_LSB                                       3
#define TOP2_TXPC_CLKDELAY_MASK                                      0x00000008
#define TOP2_TXPC_CLKDELAY_GET(x)                                    (((x) & TOP2_TXPC_CLKDELAY_MASK) >> TOP2_TXPC_CLKDELAY_LSB)
#define TOP2_TXPC_CLKDELAY_SET(x)                                    (((0 | (x)) << TOP2_TXPC_CLKDELAY_LSB) & TOP2_TXPC_CLKDELAY_MASK)
#define TOP2_TXPC_CLKDELAY_RESET                                     0
#define TOP2_DATAOUTSEL_MSB                                          2
#define TOP2_DATAOUTSEL_LSB                                          1
#define TOP2_DATAOUTSEL_MASK                                         0x00000006
#define TOP2_DATAOUTSEL_GET(x)                                       (((x) & TOP2_DATAOUTSEL_MASK) >> TOP2_DATAOUTSEL_LSB)
#define TOP2_DATAOUTSEL_SET(x)                                       (((0 | (x)) << TOP2_DATAOUTSEL_LSB) & TOP2_DATAOUTSEL_MASK)
#define TOP2_DATAOUTSEL_RESET                                        0
#define TOP2_BYPASSVREGLO_MSB                                        0
#define TOP2_BYPASSVREGLO_LSB                                        0
#define TOP2_BYPASSVREGLO_MASK                                       0x00000001
#define TOP2_BYPASSVREGLO_GET(x)                                     (((x) & TOP2_BYPASSVREGLO_MASK) >> TOP2_BYPASSVREGLO_LSB)
#define TOP2_BYPASSVREGLO_SET(x)                                     (((0 | (x)) << TOP2_BYPASSVREGLO_LSB) & TOP2_BYPASSVREGLO_MASK)
#define TOP2_BYPASSVREGLO_RESET                                      0
#define TOP2_ADDRESS                                                 0x0094
#define TOP2_HW_MASK                                                 0xffffffff
#define TOP2_SW_MASK                                                 0xffffffff
#define TOP2_HW_WRITE_MASK                                           0x00000000
#define TOP2_SW_WRITE_MASK                                           0xffffffff
#define TOP2_RSTMASK                                                 0xffffffff
#define TOP2_RESET                                                   0x48108000

// 0x0098 (TOP3)
#define TOP3_LOCALPLLDIV_MSB                                         31
#define TOP3_LOCALPLLDIV_LSB                                         31
#define TOP3_LOCALPLLDIV_MASK                                        0x80000000
#define TOP3_LOCALPLLDIV_GET(x)                                      (((x) & TOP3_LOCALPLLDIV_MASK) >> TOP3_LOCALPLLDIV_LSB)
#define TOP3_LOCALPLLDIV_SET(x)                                      (((0 | (x)) << TOP3_LOCALPLLDIV_LSB) & TOP3_LOCALPLLDIV_MASK)
#define TOP3_LOCALPLLDIV_RESET                                       0
#define TOP3_PLLREFDIVA_MSB                                          30
#define TOP3_PLLREFDIVA_LSB                                          27
#define TOP3_PLLREFDIVA_MASK                                         0x78000000
#define TOP3_PLLREFDIVA_GET(x)                                       (((x) & TOP3_PLLREFDIVA_MASK) >> TOP3_PLLREFDIVA_LSB)
#define TOP3_PLLREFDIVA_SET(x)                                       (((0 | (x)) << TOP3_PLLREFDIVA_LSB) & TOP3_PLLREFDIVA_MASK)
#define TOP3_PLLREFDIVA_RESET                                        5
#define TOP3_PLLREFDIVB_MSB                                          26
#define TOP3_PLLREFDIVB_LSB                                          23
#define TOP3_PLLREFDIVB_MASK                                         0x07800000
#define TOP3_PLLREFDIVB_GET(x)                                       (((x) & TOP3_PLLREFDIVB_MASK) >> TOP3_PLLREFDIVB_LSB)
#define TOP3_PLLREFDIVB_SET(x)                                       (((0 | (x)) << TOP3_PLLREFDIVB_LSB) & TOP3_PLLREFDIVB_MASK)
#define TOP3_PLLREFDIVB_RESET                                        5
#define TOP3_PLLFBDIVA_MSB                                           22
#define TOP3_PLLFBDIVA_LSB                                           13
#define TOP3_PLLFBDIVA_MASK                                          0x007fe000
#define TOP3_PLLFBDIVA_GET(x)                                        (((x) & TOP3_PLLFBDIVA_MASK) >> TOP3_PLLFBDIVA_LSB)
#define TOP3_PLLFBDIVA_SET(x)                                        (((0 | (x)) << TOP3_PLLFBDIVA_LSB) & TOP3_PLLFBDIVA_MASK)
#define TOP3_PLLFBDIVA_RESET                                         40
#define TOP3_PLLFBDIVB_MSB                                           12
#define TOP3_PLLFBDIVB_LSB                                           3
#define TOP3_PLLFBDIVB_MASK                                          0x00001ff8
#define TOP3_PLLFBDIVB_GET(x)                                        (((x) & TOP3_PLLFBDIVB_MASK) >> TOP3_PLLFBDIVB_LSB)
#define TOP3_PLLFBDIVB_SET(x)                                        (((0 | (x)) << TOP3_PLLFBDIVB_LSB) & TOP3_PLLFBDIVB_MASK)
#define TOP3_PLLFBDIVB_RESET                                         44
#define TOP3_VREGLO_ATBSEL_MSB                                       2
#define TOP3_VREGLO_ATBSEL_LSB                                       0
#define TOP3_VREGLO_ATBSEL_MASK                                      0x00000007
#define TOP3_VREGLO_ATBSEL_GET(x)                                    (((x) & TOP3_VREGLO_ATBSEL_MASK) >> TOP3_VREGLO_ATBSEL_LSB)
#define TOP3_VREGLO_ATBSEL_SET(x)                                    (((0 | (x)) << TOP3_VREGLO_ATBSEL_LSB) & TOP3_VREGLO_ATBSEL_MASK)
#define TOP3_VREGLO_ATBSEL_RESET                                     0
#define TOP3_ADDRESS                                                 0x0098
#define TOP3_HW_MASK                                                 0xffffffff
#define TOP3_SW_MASK                                                 0xffffffff
#define TOP3_HW_WRITE_MASK                                           0x00000000
#define TOP3_SW_WRITE_MASK                                           0xffffffff
#define TOP3_RSTMASK                                                 0xffffffff
#define TOP3_RESET                                                   0x2a850160


#endif /* _MERLIN2_0_RADIO_REG_H_ */
