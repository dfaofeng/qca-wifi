/*                                                                           */
/* File:       sm2_table_map.h                                               */
/* Creator:    cychao                                                        */
/* Time:       Thursday Apr 5, 2012 [11:28:23 pm]                            */
/*                                                                           */
/* Path:       /trees/cychao/cychao_peregrine_dev/ip/athr/wifi/dev/rtl/bb/blueprint*/
/* Arguments:  /cad/denali/blueprint/3.7.3//Linux-64bit/blueprint -codegen   */
/*             verilogExtension.codegen -html -nojava -verilogExtension -vh  */
/*             -ansic sm2_table_map.rdl                                      */
/*                                                                           */
/* Sources:    /trees/cychao/cychao_peregrine_dev/ip/athr/wifi/dev/rtl/bb/blueprint/sm2_table_map.rdl*/
/*             /trees/cychao/cychao_peregrine_dev/ip/athr/wifi/dev/rtl/bb/blueprint/sm2_table_map_sysconfig.rdl*/
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


#ifndef __REG_SM2_TABLE_MAP_H__
#define __REG_SM2_TABLE_MAP_H__

#include "sm2_table_map_macro.h"

struct sm2_table_map {
  volatile uint32_t BB_aic_srams_b2[80];          /*        0x0 - 0x140      */
  volatile uint32_t BB_aic_cal_srams_b2[80];      /*      0x140 - 0x280      */
  volatile uint32_t BB_aic_gain_tab_b2[19];       /*      0x280 - 0x2cc      */
  volatile char pad__0[0xf4];                     /*      0x2cc - 0x3c0      */
  volatile uint32_t BB_dc_dac_mem_b2[4];          /*      0x3c0 - 0x3d0      */
  volatile char pad__1[0x22c];                    /*      0x3d0 - 0x5fc      */
  volatile uint32_t BB_sm2_tables_dummy2;         /*      0x5fc - 0x600      */
};

#endif /* __REG_SM2_TABLE_MAP_H__ */
