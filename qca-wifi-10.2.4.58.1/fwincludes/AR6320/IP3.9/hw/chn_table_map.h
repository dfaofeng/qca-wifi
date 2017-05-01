/*                                                                           */
/* File:       chn_table_map.h                                               */
/* Creator:    jastis                                                        */
/* Time:       Thursday Feb 9, 2012 [11:26:56 am]                            */
/*                                                                           */
/* Path:       /trees/jastis/jastis-stree/ip/athr/wifi/R1_IP3/rtl/bb_hera_1x1/blueprint*/
/* Arguments:  /cad/denali/blueprint/3.7.3//Linux-64bit/blueprint -codegen   */
/*             verilogExtension.codegen -html -nojava -verilogExtension -vh  */
/*             -ansic chn_table_map.rdl                                      */
/*                                                                           */
/* Sources:    /trees/jastis/jastis-stree/ip/athr/wifi/R1_IP3/rtl/bb_hera_1x1/blueprint/chn_table_map.rdl*/
/*             /cad/denali/blueprint/3.7.3/gen/ansic.pm                      */
/*             /cad/denali/blueprint/3.7.3/gen/html2docbook.pm               */
/*             /cad/denali/blueprint/3.7.3/gen/html2sgml.pm                  */
/*             /cad/denali/blueprint/3.7.3/gen/html.pm                       */
/*             /cad/local/lib/perl/Pinfo.pm                                  */
/*                                                                           */
/* Blueprint:   3.7.3 (Fri Aug 29 12:39:16 PDT 2008)                         */
/* Machine:    sj1jastis02                                                   */
/* OS:         Linux 2.6.9-101.ELsmp                                         */
/* Description:                                                              */
/*                                                                           */
/* No Description Provided                                                   */
/*                                                                           */
/*                                                                           */


#ifndef __REG_CHN_TABLE_MAP_H__
#define __REG_CHN_TABLE_MAP_H__

#include "chn_table_map_macro.h"

struct chn_table_map {
  volatile char pad__0[0x80];                     /*        0x0 - 0x80       */
  volatile uint32_t BB_paprd_power_at_am2am_cal_b0;
                                                  /*       0x80 - 0x84       */
  volatile uint32_t BB_paprd_valid_obdb_b0;       /*       0x84 - 0x88       */
  volatile char pad__1[0x78];                     /*       0x88 - 0x100      */
  volatile uint32_t BB_chn_tables_dummy_2;        /*      0x100 - 0x104      */
  volatile char pad__2[0x78c];                    /*      0x104 - 0x890      */
  volatile uint32_t BB_txiq_corr_coeff_0_b0;      /*      0x890 - 0x894      */
  volatile uint32_t BB_txiq_corr_coeff_1_b0;      /*      0x894 - 0x898      */
  volatile uint32_t BB_txiq_corr_coeff_2_b0;      /*      0x898 - 0x89c      */
  volatile uint32_t BB_txiq_corr_coeff_3_b0;      /*      0x89c - 0x8a0      */
  volatile uint32_t BB_txiq_corr_coeff_4_b0;      /*      0x8a0 - 0x8a4      */
  volatile uint32_t BB_txiq_corr_coeff_5_b0;      /*      0x8a4 - 0x8a8      */
  volatile uint32_t BB_txiq_corr_coeff_6_b0;      /*      0x8a8 - 0x8ac      */
  volatile uint32_t BB_txiq_corr_coeff_7_b0;      /*      0x8ac - 0x8b0      */
  volatile uint32_t BB_txiq_corr_coeff_8_b0;      /*      0x8b0 - 0x8b4      */
  volatile uint32_t BB_txiq_corr_coeff_9_b0;      /*      0x8b4 - 0x8b8      */
  volatile uint32_t BB_txiq_corr_coeff_a_b0;      /*      0x8b8 - 0x8bc      */
  volatile uint32_t BB_txiq_corr_coeff_b_b0;      /*      0x8bc - 0x8c0      */
  volatile uint32_t BB_txiq_corr_coeff_c_b0;      /*      0x8c0 - 0x8c4      */
  volatile uint32_t BB_txiq_corr_coeff_d_b0;      /*      0x8c4 - 0x8c8      */
  volatile uint32_t BB_txiq_corr_coeff_e_b0;      /*      0x8c8 - 0x8cc      */
  volatile uint32_t BB_txiq_corr_coeff_f_b0;      /*      0x8cc - 0x8d0      */
  volatile uint32_t BB_rxcal_txiqcorr_coef_0_b0;  /*      0x8d0 - 0x8d4      */
  volatile uint32_t BB_rxcal_txiqcorr_coef_1_b0;  /*      0x8d4 - 0x8d8      */
  volatile uint32_t BB_rxcal_txiqcorr_coef_2_b0;  /*      0x8d8 - 0x8dc      */
  volatile uint32_t BB_rxcal_txiqcorr_coef_3_b0;  /*      0x8dc - 0x8e0      */
  volatile uint32_t BB_rxcal_txiqcorr_coef_4_b0;  /*      0x8e0 - 0x8e4      */
  volatile uint32_t BB_rxcal_txiqcorr_coef_5_b0;  /*      0x8e4 - 0x8e8      */
  volatile uint32_t BB_rxcal_txiqcorr_coef_6_b0;  /*      0x8e8 - 0x8ec      */
  volatile uint32_t BB_rxcal_txiqcorr_coef_7_b0;  /*      0x8ec - 0x8f0      */
  volatile uint32_t BB_rxcal_txiqcorr_coef_8_b0;  /*      0x8f0 - 0x8f4      */
  volatile uint32_t BB_rxcal_txiqcorr_coef_9_b0;  /*      0x8f4 - 0x8f8      */
  volatile uint32_t BB_rxcal_txiqcorr_coef_10_b0; /*      0x8f8 - 0x8fc      */
  volatile uint32_t BB_rxcal_txiqcorr_coef_11_b0; /*      0x8fc - 0x900      */
  volatile uint32_t BB_rxcal_txiqcorr_coef_12_b0; /*      0x900 - 0x904      */
  volatile uint32_t BB_rxcal_txiqcorr_coef_13_b0; /*      0x904 - 0x908      */
  volatile uint32_t BB_rxcal_txiqcorr_coef_14_b0; /*      0x908 - 0x90c      */
  volatile uint32_t BB_rxcal_txiqcorr_coef_15_b0; /*      0x90c - 0x910      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_0_b0; /*      0x910 - 0x914      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_1_b0; /*      0x914 - 0x918      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_2_b0; /*      0x918 - 0x91c      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_3_b0; /*      0x91c - 0x920      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_4_b0; /*      0x920 - 0x924      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_5_b0; /*      0x924 - 0x928      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_6_b0; /*      0x928 - 0x92c      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_7_b0; /*      0x92c - 0x930      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_8_b0; /*      0x930 - 0x934      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_9_b0; /*      0x934 - 0x938      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_10_b0;
                                                  /*      0x938 - 0x93c      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_11_b0;
                                                  /*      0x93c - 0x940      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_12_b0;
                                                  /*      0x940 - 0x944      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_13_b0;
                                                  /*      0x944 - 0x948      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_14_b0;
                                                  /*      0x948 - 0x94c      */
  volatile uint32_t BB_rxiqcorr_rxpath_coef_15_b0;
                                                  /*      0x94c - 0x950      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_0_b0; /*      0x950 - 0x954      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_1_b0; /*      0x954 - 0x958      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_2_b0; /*      0x958 - 0x95c      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_3_b0; /*      0x95c - 0x960      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_4_b0; /*      0x960 - 0x964      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_5_b0; /*      0x964 - 0x968      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_6_b0; /*      0x968 - 0x96c      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_7_b0; /*      0x96c - 0x970      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_8_b0; /*      0x970 - 0x974      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_9_b0; /*      0x974 - 0x978      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_10_b0;
                                                  /*      0x978 - 0x97c      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_11_b0;
                                                  /*      0x97c - 0x980      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_12_b0;
                                                  /*      0x980 - 0x984      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_13_b0;
                                                  /*      0x984 - 0x988      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_14_b0;
                                                  /*      0x988 - 0x98c      */
  volatile uint32_t BB_rxiqcorr_txpath_coef_15_b0;
                                                  /*      0x98c - 0x990      */
  volatile uint32_t BB_rxcal_tx_gain_table_0_b0;  /*      0x990 - 0x994      */
  volatile uint32_t BB_rxcal_tx_gain_table_1_b0;  /*      0x994 - 0x998      */
  volatile uint32_t BB_rxcal_tx_gain_table_2_b0;  /*      0x998 - 0x99c      */
  volatile uint32_t BB_rxcal_tx_gain_table_3_b0;  /*      0x99c - 0x9a0      */
  volatile uint32_t BB_rxcal_tx_gain_table_4_b0;  /*      0x9a0 - 0x9a4      */
  volatile uint32_t BB_rxcal_tx_gain_table_5_b0;  /*      0x9a4 - 0x9a8      */
  volatile uint32_t BB_rxcal_tx_gain_table_6_b0;  /*      0x9a8 - 0x9ac      */
  volatile uint32_t BB_rxcal_tx_gain_table_7_b0;  /*      0x9ac - 0x9b0      */
  volatile uint32_t BB_rxcal_tx_gain_table_8_b0;  /*      0x9b0 - 0x9b4      */
  volatile uint32_t BB_rxcal_tx_gain_table_9_b0;  /*      0x9b4 - 0x9b8      */
  volatile uint32_t BB_rxcal_tx_gain_table_10_b0; /*      0x9b8 - 0x9bc      */
  volatile uint32_t BB_rxcal_tx_gain_table_11_b0; /*      0x9bc - 0x9c0      */
  volatile uint32_t BB_rxcal_tx_gain_table_12_b0; /*      0x9c0 - 0x9c4      */
  volatile uint32_t BB_rxcal_tx_gain_table_13_b0; /*      0x9c4 - 0x9c8      */
  volatile uint32_t BB_rxcal_tx_gain_table_14_b0; /*      0x9c8 - 0x9cc      */
  volatile uint32_t BB_rxcal_tx_gain_table_15_b0; /*      0x9cc - 0x9d0      */
  volatile uint32_t BB_rxcal_tx_gain_table_16_b0; /*      0x9d0 - 0x9d4      */
  volatile uint32_t BB_rxcal_tx_gain_table_17_b0; /*      0x9d4 - 0x9d8      */
  volatile uint32_t BB_rxcal_tx_gain_table_18_b0; /*      0x9d8 - 0x9dc      */
  volatile uint32_t BB_rxcal_tx_gain_table_19_b0; /*      0x9dc - 0x9e0      */
  volatile uint32_t BB_rxcal_tx_gain_table_20_b0; /*      0x9e0 - 0x9e4      */
  volatile uint32_t BB_rxcal_tx_gain_table_21_b0; /*      0x9e4 - 0x9e8      */
  volatile uint32_t BB_rxcal_tx_gain_table_22_b0; /*      0x9e8 - 0x9ec      */
  volatile uint32_t BB_rxcal_tx_gain_table_23_b0; /*      0x9ec - 0x9f0      */
  volatile uint32_t BB_rxcal_tx_gain_table_24_b0; /*      0x9f0 - 0x9f4      */
  volatile uint32_t BB_rxcal_tx_gain_table_25_b0; /*      0x9f4 - 0x9f8      */
  volatile uint32_t BB_rxcal_tx_gain_table_26_b0; /*      0x9f8 - 0x9fc      */
  volatile uint32_t BB_rxcal_tx_gain_table_27_b0; /*      0x9fc - 0xa00      */
  volatile uint32_t BB_rxcal_tx_gain_table_28_b0; /*      0xa00 - 0xa04      */
  volatile uint32_t BB_rxcal_tx_gain_table_29_b0; /*      0xa04 - 0xa08      */
  volatile uint32_t BB_rxcal_tx_gain_table_30_b0; /*      0xa08 - 0xa0c      */
  volatile uint32_t BB_rxcal_tx_gain_table_31_b0; /*      0xa0c - 0xa10      */
  volatile uint32_t BB_rxcal_rx_gain_table_1_0_b0;
                                                  /*      0xa10 - 0xa14      */
  volatile uint32_t BB_rxcal_rx_gain_table_3_2_b0;
                                                  /*      0xa14 - 0xa18      */
  volatile uint32_t BB_rxcal_rx_gain_table_5_4_b0;
                                                  /*      0xa18 - 0xa1c      */
  volatile uint32_t BB_rxcal_rx_gain_table_7_6_b0;
                                                  /*      0xa1c - 0xa20      */
  volatile uint32_t BB_rxcal_rx_gain_table_9_8_b0;
                                                  /*      0xa20 - 0xa24      */
  volatile uint32_t BB_rxcal_rx_gain_table_11_10_b0;
                                                  /*      0xa24 - 0xa28      */
  volatile uint32_t BB_rxcal_rx_gain_table_13_12_b0;
                                                  /*      0xa28 - 0xa2c      */
  volatile uint32_t BB_rxcal_rx_gain_table_15_14_b0;
                                                  /*      0xa2c - 0xa30      */
  volatile uint32_t BB_rxcal_gain_delta_db_table_3_0_b0;
                                                  /*      0xa30 - 0xa34      */
  volatile uint32_t BB_rxcal_gain_delta_db_table_7_4_b0;
                                                  /*      0xa34 - 0xa38      */
  volatile uint32_t BB_rxcal_gain_delta_db_table_11_8_b0;
                                                  /*      0xa38 - 0xa3c      */
  volatile uint32_t BB_rxcal_gain_delta_db_table_15_12_b0;
                                                  /*      0xa3c - 0xa40      */
  volatile uint32_t BB_rxcal_tx_iqcorr_idx_7_0_b0;
                                                  /*      0xa40 - 0xa44      */
  volatile uint32_t BB_rxcal_tx_iqcorr_idx_15_8_b0;
                                                  /*      0xa44 - 0xa48      */
  volatile uint32_t BB_rxcal_tx_iqcorr_idx_23_16_b0;
                                                  /*      0xa48 - 0xa4c      */
  volatile uint32_t BB_rxcal_tx_iqcorr_idx_31_24_b0;
                                                  /*      0xa4c - 0xa50      */
  volatile uint32_t BB_txcal_rx_iqcorr_idx_7_0;   /*      0xa50 - 0xa54      */
  volatile uint32_t BB_txcal_rx_iqcorr_idx_15_8;  /*      0xa54 - 0xa58      */
  volatile uint32_t BB_txcal_rx_iqcorr_idx_23_16; /*      0xa58 - 0xa5c      */
  volatile uint32_t BB_txcal_rx_iqcorr_idx_24;    /*      0xa5c - 0xa60      */
  volatile char pad__3[0xa0];                     /*      0xa60 - 0xb00      */
  volatile uint32_t BB_chaninfo_vht80_b0[64];     /*      0xb00 - 0xc00      */
  volatile char pad__4[0x7eac];                   /*      0xc00 - 0x8aac     */
  volatile uint32_t BB_chn_tables_dummy_1;        /*     0x8aac - 0x8ab0     */
};

#endif /* __REG_CHN_TABLE_MAP_H__ */
