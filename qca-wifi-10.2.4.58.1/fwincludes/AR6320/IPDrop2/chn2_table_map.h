/*                                                                           */
/* File:       chn2_table_map.h                                              */
/* Creator:    cychao                                                        */
/* Time:       Thursday Apr 5, 2012 [11:28:25 pm]                            */
/*                                                                           */
/* Path:       /trees/cychao/cychao_peregrine_dev/ip/athr/wifi/dev/rtl/bb/blueprint*/
/* Arguments:  /cad/denali/blueprint/3.7.3//Linux-64bit/blueprint -codegen   */
/*             verilogExtension.codegen -html -nojava -verilogExtension -vh  */
/*             -ansic chn2_table_map.rdl                                     */
/*                                                                           */
/* Sources:    /trees/cychao/cychao_peregrine_dev/ip/athr/wifi/dev/rtl/bb/blueprint/chn2_table_map.rdl*/
/*             /cad/denali/blueprint/3.7.3/gen/ansic.pm                      */
/*             /cad/denali/blueprint/3.7.3/gen/html2docbook.pm               */
/*             /cad/denali/blueprint/3.7.3/gen/html2sgml.pm                  */
/*             /cad/denali/blueprint/3.7.3/gen/html.pm                       */
/*             /cad/local/lib/perl/Pinfo.pm                                  */
/*                                                                           */
/* Blueprint:   3.7.3 (Fri Aug 29 12:39:16 PDT 2008)                         */
/* Machine:    sparrow                                                       */
/* OS:         Linux 2.6.9-89.ELsmp                                          */
/* Description:                                                              */
/*                                                                           */
/* No Description Provided                                                   */
/*                                                                           */
/*                                                                           */


#ifndef __REG_CHN2_TABLE_MAP_H__
#define __REG_CHN2_TABLE_MAP_H__

#include "chn2_table_map_macro.h"

struct chn2_table_map {
  volatile char pad__0[0x80];                     /*        0x0 - 0x80       */
  volatile uint32_t BB_paprd_power_at_am2am_cal_b2;
                                                  /*       0x80 - 0x84       */
  volatile uint32_t BB_paprd_valid_obdb_b2;       /*       0x84 - 0x88       */
  volatile char pad__1[0x78];                     /*       0x88 - 0x100      */
  volatile uint32_t BB_chn2_tables_dummy_2;       /*      0x100 - 0x104      */
  volatile char pad__2[0x78c];                    /*      0x104 - 0x890      */
  volatile uint32_t BB_txiqcorr_txpath_coef_b2[16];
                                                  /*      0x890 - 0x8d0      */
  volatile uint32_t BB_txiqcorr_rxpath_coef_b2[16];
                                                  /*      0x8d0 - 0x910      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_b2[16];
                                                  /*      0x910 - 0x950      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_b2[16];
                                                  /*      0x950 - 0x990      */
  volatile uint32_t BB_rxcal_tx_gain_table_b2[32];
                                                  /*      0x990 - 0xa10      */
  volatile uint32_t BB_rxcal_rx_gain_table_1_0_b2;
                                                  /*      0xa10 - 0xa14      */
  volatile uint32_t BB_rxcal_rx_gain_table_3_2_b2;
                                                  /*      0xa14 - 0xa18      */
  volatile uint32_t BB_rxcal_rx_gain_table_5_4_b2;
                                                  /*      0xa18 - 0xa1c      */
  volatile uint32_t BB_rxcal_rx_gain_table_7_6_b2;
                                                  /*      0xa1c - 0xa20      */
  volatile uint32_t BB_rxcal_rx_gain_table_9_8_b2;
                                                  /*      0xa20 - 0xa24      */
  volatile uint32_t BB_rxcal_rx_gain_table_11_10_b2;
                                                  /*      0xa24 - 0xa28      */
  volatile uint32_t BB_rxcal_rx_gain_table_13_12_b2;
                                                  /*      0xa28 - 0xa2c      */
  volatile uint32_t BB_rxcal_rx_gain_table_15_14_b2;
                                                  /*      0xa2c - 0xa30      */
  volatile uint32_t BB_rxcal_gain_delta_db_table_3_0_b2;
                                                  /*      0xa30 - 0xa34      */
  volatile uint32_t BB_rxcal_gain_delta_db_table_7_4_b2;
                                                  /*      0xa34 - 0xa38      */
  volatile uint32_t BB_rxcal_gain_delta_db_table_11_8_b2;
                                                  /*      0xa38 - 0xa3c      */
  volatile uint32_t BB_rxcal_gain_delta_db_table_15_12_b2;
                                                  /*      0xa3c - 0xa40      */
  volatile uint32_t BB_rxcal_tx_iqcorr_idx_7_0_b2;
                                                  /*      0xa40 - 0xa44      */
  volatile uint32_t BB_rxcal_tx_iqcorr_idx_15_8_b2;
                                                  /*      0xa44 - 0xa48      */
  volatile uint32_t BB_rxcal_tx_iqcorr_idx_23_16_b2;
                                                  /*      0xa48 - 0xa4c      */
  volatile uint32_t BB_rxcal_tx_iqcorr_idx_31_24_b2;
                                                  /*      0xa4c - 0xa50      */
  volatile uint32_t BB_paprd_sm_sig_gain_table_0_2_b2;
                                                  /*      0xa50 - 0xa54      */
  volatile uint32_t BB_paprd_sm_sig_gain_table_3_5_b2;
                                                  /*      0xa54 - 0xa58      */
  volatile uint32_t BB_paprd_sm_sig_gain_table_6_b2;
                                                  /*      0xa58 - 0xa5c      */
  volatile char pad__3[0x14];                     /*      0xa5c - 0xa70      */
  volatile uint32_t BB_preemp_coef_set0_b2;       /*      0xa70 - 0xa74      */
  volatile uint32_t BB_preemp_coef_set1_b2;       /*      0xa74 - 0xa78      */
  volatile uint32_t BB_preemp_coef_set2_b2;       /*      0xa78 - 0xa7c      */
  volatile char pad__4[0x84];                     /*      0xa7c - 0xb00      */
  volatile uint32_t BB_chaninfo_vht80_b2[64];     /*      0xb00 - 0xc00      */
  volatile uint32_t BB_normrx_rxiq_corr_coeff_b2[160];
                                                  /*      0xc00 - 0xe80      */
  volatile uint32_t BB_paprd_mem_tab_b2[1344];    /*      0xe80 - 0x2380     */
  volatile uint32_t BB_normtx_txiq_corr_coeff_b2[160];
                                                  /*     0x2380 - 0x2600     */
  volatile char pad__5[0x64ac];                   /*     0x2600 - 0x8aac     */
  volatile uint32_t BB_chn2_tables_dummy_1;       /*     0x8aac - 0x8ab0     */
};

#endif /* __REG_CHN2_TABLE_MAP_H__ */
