/*                                                                           */
/* File:       chn2_table_map_macro.h                                        */
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


#ifndef __REG_CHN2_TABLE_MAP_MACRO_H__
#define __REG_CHN2_TABLE_MAP_MACRO_H__


/* macros for BlueprintGlobalNameSpace::paprd_power_at_am2am_cal_b2 */
#ifndef __PAPRD_POWER_AT_AM2AM_CAL_B2_MACRO__
#define __PAPRD_POWER_AT_AM2AM_CAL_B2_MACRO__

/* macros for field paprd_power_at_am2am_cal_0_b2 */
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_0_B2__SHIFT     0
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_0_B2__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_0_B2__MASK \
                    0x0000003fU
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_0_B2__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_0_B2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_0_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_0_B2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field paprd_power_at_am2am_cal_1_b2 */
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_1_B2__SHIFT     6
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_1_B2__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_1_B2__MASK \
                    0x00000fc0U
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_1_B2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_1_B2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_1_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_1_B2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field paprd_power_at_am2am_cal_2_b2 */
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_2_B2__SHIFT    12
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_2_B2__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_2_B2__MASK \
                    0x0003f000U
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_2_B2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_2_B2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_2_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_2_B2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field paprd_power_at_am2am_cal_3_b2 */
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_3_B2__SHIFT    18
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_3_B2__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_3_B2__MASK \
                    0x00fc0000U
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_3_B2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_3_B2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00fc0000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_3_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x00fc0000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_3_B2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00fc0000U)))

/* macros for field paprd_power_at_am2am_cal_4_b2 */
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_4_B2__SHIFT    24
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_4_B2__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_4_B2__MASK \
                    0x3f000000U
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_4_B2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_4_B2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_4_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B2__PAPRD_POWER_AT_AM2AM_CAL_4_B2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define PAPRD_POWER_AT_AM2AM_CAL_B2__TYPE                              uint32_t
#define PAPRD_POWER_AT_AM2AM_CAL_B2__READ                           0x3fffffffU
#define PAPRD_POWER_AT_AM2AM_CAL_B2__WRITE                          0x3fffffffU

#endif /* __PAPRD_POWER_AT_AM2AM_CAL_B2_MACRO__ */


/* macros for BB_paprd_power_at_am2am_cal_b2 */
#define INST_BB_PAPRD_POWER_AT_AM2AM_CAL_B2__NUM                              1

/* macros for BlueprintGlobalNameSpace::paprd_valid_obdb_b2 */
#ifndef __PAPRD_VALID_OBDB_B2_MACRO__
#define __PAPRD_VALID_OBDB_B2_MACRO__

/* macros for field paprd_valid_obdb_0_b2 */
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_0_B2__SHIFT                     0
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_0_B2__WIDTH                     6
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_0_B2__MASK            0x0000003fU
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_0_B2__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_0_B2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_0_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_0_B2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field paprd_valid_obdb_1_b2 */
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_1_B2__SHIFT                     6
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_1_B2__WIDTH                     6
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_1_B2__MASK            0x00000fc0U
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_1_B2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_1_B2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_1_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_1_B2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field paprd_valid_obdb_2_b2 */
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_2_B2__SHIFT                    12
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_2_B2__WIDTH                     6
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_2_B2__MASK            0x0003f000U
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_2_B2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_2_B2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_2_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_2_B2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field paprd_valid_obdb_3_b2 */
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_3_B2__SHIFT                    18
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_3_B2__WIDTH                     6
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_3_B2__MASK            0x00fc0000U
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_3_B2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_3_B2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00fc0000U)
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_3_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x00fc0000U)
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_3_B2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00fc0000U)))

/* macros for field paprd_valid_obdb_4_b2 */
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_4_B2__SHIFT                    24
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_4_B2__WIDTH                     6
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_4_B2__MASK            0x3f000000U
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_4_B2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_4_B2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_4_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define PAPRD_VALID_OBDB_B2__PAPRD_VALID_OBDB_4_B2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define PAPRD_VALID_OBDB_B2__TYPE                                      uint32_t
#define PAPRD_VALID_OBDB_B2__READ                                   0x3fffffffU
#define PAPRD_VALID_OBDB_B2__WRITE                                  0x3fffffffU

#endif /* __PAPRD_VALID_OBDB_B2_MACRO__ */


/* macros for BB_paprd_valid_obdb_b2 */
#define INST_BB_PAPRD_VALID_OBDB_B2__NUM                                      1

/* macros for BlueprintGlobalNameSpace::chn2_tables_dummy_2 */
#ifndef __CHN2_TABLES_DUMMY_2_MACRO__
#define __CHN2_TABLES_DUMMY_2_MACRO__

/* macros for field dummy2 */
#define CHN2_TABLES_DUMMY_2__DUMMY2__SHIFT                                    0
#define CHN2_TABLES_DUMMY_2__DUMMY2__WIDTH                                   32
#define CHN2_TABLES_DUMMY_2__DUMMY2__MASK                           0xffffffffU
#define CHN2_TABLES_DUMMY_2__DUMMY2__READ(src)    (uint32_t)(src) & 0xffffffffU
#define CHN2_TABLES_DUMMY_2__DUMMY2__WRITE(src) ((uint32_t)(src) & 0xffffffffU)
#define CHN2_TABLES_DUMMY_2__DUMMY2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define CHN2_TABLES_DUMMY_2__DUMMY2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define CHN2_TABLES_DUMMY_2__TYPE                                      uint32_t
#define CHN2_TABLES_DUMMY_2__READ                                   0xffffffffU
#define CHN2_TABLES_DUMMY_2__WRITE                                  0xffffffffU

#endif /* __CHN2_TABLES_DUMMY_2_MACRO__ */


/* macros for BB_chn2_tables_dummy_2 */
#define INST_BB_CHN2_TABLES_DUMMY_2__NUM                                      1

/* macros for BlueprintGlobalNameSpace::txiqcorr_txpath_coef_b2 */
#ifndef __TXIQCORR_TXPATH_COEF_B2_MACRO__
#define __TXIQCORR_TXPATH_COEF_B2_MACRO__

/* macros for field txiqcorr_txpath_coef_chn2 */
#define TXIQCORR_TXPATH_COEF_B2__TXIQCORR_TXPATH_COEF_CHN2__SHIFT             0
#define TXIQCORR_TXPATH_COEF_B2__TXIQCORR_TXPATH_COEF_CHN2__WIDTH            18
#define TXIQCORR_TXPATH_COEF_B2__TXIQCORR_TXPATH_COEF_CHN2__MASK    0x0003ffffU
#define TXIQCORR_TXPATH_COEF_B2__TXIQCORR_TXPATH_COEF_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define TXIQCORR_TXPATH_COEF_B2__TXIQCORR_TXPATH_COEF_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define TXIQCORR_TXPATH_COEF_B2__TXIQCORR_TXPATH_COEF_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define TXIQCORR_TXPATH_COEF_B2__TXIQCORR_TXPATH_COEF_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define TXIQCORR_TXPATH_COEF_B2__TYPE                                  uint32_t
#define TXIQCORR_TXPATH_COEF_B2__READ                               0x0003ffffU
#define TXIQCORR_TXPATH_COEF_B2__WRITE                              0x0003ffffU

#endif /* __TXIQCORR_TXPATH_COEF_B2_MACRO__ */


/* macros for BB_txiqcorr_txpath_coef_b2 */
#define INST_BB_TXIQCORR_TXPATH_COEF_B2__NUM                                 16

/* macros for BlueprintGlobalNameSpace::txiqcorr_rxpath_coef_b2 */
#ifndef __TXIQCORR_RXPATH_COEF_B2_MACRO__
#define __TXIQCORR_RXPATH_COEF_B2_MACRO__

/* macros for field txiqcorr_rxpath_coef_chn2 */
#define TXIQCORR_RXPATH_COEF_B2__TXIQCORR_RXPATH_COEF_CHN2__SHIFT             0
#define TXIQCORR_RXPATH_COEF_B2__TXIQCORR_RXPATH_COEF_CHN2__WIDTH            18
#define TXIQCORR_RXPATH_COEF_B2__TXIQCORR_RXPATH_COEF_CHN2__MASK    0x0003ffffU
#define TXIQCORR_RXPATH_COEF_B2__TXIQCORR_RXPATH_COEF_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define TXIQCORR_RXPATH_COEF_B2__TXIQCORR_RXPATH_COEF_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define TXIQCORR_RXPATH_COEF_B2__TXIQCORR_RXPATH_COEF_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define TXIQCORR_RXPATH_COEF_B2__TXIQCORR_RXPATH_COEF_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define TXIQCORR_RXPATH_COEF_B2__TYPE                                  uint32_t
#define TXIQCORR_RXPATH_COEF_B2__READ                               0x0003ffffU
#define TXIQCORR_RXPATH_COEF_B2__WRITE                              0x0003ffffU

#endif /* __TXIQCORR_RXPATH_COEF_B2_MACRO__ */


/* macros for BB_txiqcorr_rxpath_coef_b2 */
#define INST_BB_TXIQCORR_RXPATH_COEF_B2__NUM                                 16

/* macros for BlueprintGlobalNameSpace::rxiqcorr_rxpath_coef_b2 */
#ifndef __RXIQCORR_RXPATH_COEF_B2_MACRO__
#define __RXIQCORR_RXPATH_COEF_B2_MACRO__

/* macros for field rxiqcorr_rxpath_coef_chn1 */
#define RXIQCORR_RXPATH_COEF_B2__RXIQCORR_RXPATH_COEF_CHN1__SHIFT             0
#define RXIQCORR_RXPATH_COEF_B2__RXIQCORR_RXPATH_COEF_CHN1__WIDTH            18
#define RXIQCORR_RXPATH_COEF_B2__RXIQCORR_RXPATH_COEF_CHN1__MASK    0x0003ffffU
#define RXIQCORR_RXPATH_COEF_B2__RXIQCORR_RXPATH_COEF_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define RXIQCORR_RXPATH_COEF_B2__RXIQCORR_RXPATH_COEF_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define RXIQCORR_RXPATH_COEF_B2__RXIQCORR_RXPATH_COEF_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define RXIQCORR_RXPATH_COEF_B2__RXIQCORR_RXPATH_COEF_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define RXIQCORR_RXPATH_COEF_B2__TYPE                                  uint32_t
#define RXIQCORR_RXPATH_COEF_B2__READ                               0x0003ffffU
#define RXIQCORR_RXPATH_COEF_B2__WRITE                              0x0003ffffU

#endif /* __RXIQCORR_RXPATH_COEF_B2_MACRO__ */


/* macros for BB_rxiqcorr_rxpath_coef_b2 */
#define INST_BB_RXIQCORR_RXPATH_COEF_B2__NUM                                 16

/* macros for BlueprintGlobalNameSpace::rxiqcorr_txpath_coef_b2 */
#ifndef __RXIQCORR_TXPATH_COEF_B2_MACRO__
#define __RXIQCORR_TXPATH_COEF_B2_MACRO__

/* macros for field rxiqcorr_txpath_coef_chn2 */
#define RXIQCORR_TXPATH_COEF_B2__RXIQCORR_TXPATH_COEF_CHN2__SHIFT             0
#define RXIQCORR_TXPATH_COEF_B2__RXIQCORR_TXPATH_COEF_CHN2__WIDTH            18
#define RXIQCORR_TXPATH_COEF_B2__RXIQCORR_TXPATH_COEF_CHN2__MASK    0x0003ffffU
#define RXIQCORR_TXPATH_COEF_B2__RXIQCORR_TXPATH_COEF_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define RXIQCORR_TXPATH_COEF_B2__RXIQCORR_TXPATH_COEF_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define RXIQCORR_TXPATH_COEF_B2__RXIQCORR_TXPATH_COEF_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define RXIQCORR_TXPATH_COEF_B2__RXIQCORR_TXPATH_COEF_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define RXIQCORR_TXPATH_COEF_B2__TYPE                                  uint32_t
#define RXIQCORR_TXPATH_COEF_B2__READ                               0x0003ffffU
#define RXIQCORR_TXPATH_COEF_B2__WRITE                              0x0003ffffU

#endif /* __RXIQCORR_TXPATH_COEF_B2_MACRO__ */


/* macros for BB_rxiqcorr_txpath_coef_b2 */
#define INST_BB_RXIQCORR_TXPATH_COEF_B2__NUM                                 16

/* macros for BlueprintGlobalNameSpace::rxcal_tx_gain_table_b2 */
#ifndef __RXCAL_TX_GAIN_TABLE_B2_MACRO__
#define __RXCAL_TX_GAIN_TABLE_B2_MACRO__

/* macros for field rxcal_tx_gain_table_chn2 */
#define RXCAL_TX_GAIN_TABLE_B2__RXCAL_TX_GAIN_TABLE_CHN2__SHIFT               0
#define RXCAL_TX_GAIN_TABLE_B2__RXCAL_TX_GAIN_TABLE_CHN2__WIDTH              20
#define RXCAL_TX_GAIN_TABLE_B2__RXCAL_TX_GAIN_TABLE_CHN2__MASK      0x000fffffU
#define RXCAL_TX_GAIN_TABLE_B2__RXCAL_TX_GAIN_TABLE_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x000fffffU
#define RXCAL_TX_GAIN_TABLE_B2__RXCAL_TX_GAIN_TABLE_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000fffffU)
#define RXCAL_TX_GAIN_TABLE_B2__RXCAL_TX_GAIN_TABLE_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000fffffU) | ((uint32_t)(src) &\
                    0x000fffffU)
#define RXCAL_TX_GAIN_TABLE_B2__RXCAL_TX_GAIN_TABLE_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000fffffU)))
#define RXCAL_TX_GAIN_TABLE_B2__TYPE                                   uint32_t
#define RXCAL_TX_GAIN_TABLE_B2__READ                                0x000fffffU
#define RXCAL_TX_GAIN_TABLE_B2__WRITE                               0x000fffffU

#endif /* __RXCAL_TX_GAIN_TABLE_B2_MACRO__ */


/* macros for BB_rxcal_tx_gain_table_b2 */
#define INST_BB_RXCAL_TX_GAIN_TABLE_B2__NUM                                  32

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_1_0_b2 */
#ifndef __RXCAL_RX_GAIN_TABLE_1_0_B2_MACRO__
#define __RXCAL_RX_GAIN_TABLE_1_0_B2_MACRO__

/* macros for field rxcal_rx_gain_table_0_chn2 */
#define RXCAL_RX_GAIN_TABLE_1_0_B2__RXCAL_RX_GAIN_TABLE_0_CHN2__SHIFT         0
#define RXCAL_RX_GAIN_TABLE_1_0_B2__RXCAL_RX_GAIN_TABLE_0_CHN2__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_1_0_B2__RXCAL_RX_GAIN_TABLE_0_CHN2__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_1_0_B2__RXCAL_RX_GAIN_TABLE_0_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_1_0_B2__RXCAL_RX_GAIN_TABLE_0_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_1_0_B2__RXCAL_RX_GAIN_TABLE_0_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_1_0_B2__RXCAL_RX_GAIN_TABLE_0_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_1_chn2 */
#define RXCAL_RX_GAIN_TABLE_1_0_B2__RXCAL_RX_GAIN_TABLE_1_CHN2__SHIFT        16
#define RXCAL_RX_GAIN_TABLE_1_0_B2__RXCAL_RX_GAIN_TABLE_1_CHN2__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_1_0_B2__RXCAL_RX_GAIN_TABLE_1_CHN2__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_1_0_B2__RXCAL_RX_GAIN_TABLE_1_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_1_0_B2__RXCAL_RX_GAIN_TABLE_1_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_1_0_B2__RXCAL_RX_GAIN_TABLE_1_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_1_0_B2__RXCAL_RX_GAIN_TABLE_1_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_1_0_B2__TYPE                               uint32_t
#define RXCAL_RX_GAIN_TABLE_1_0_B2__READ                            0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_1_0_B2__WRITE                           0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_1_0_B2_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_1_0_b2 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_1_0_B2__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_3_2_b2 */
#ifndef __RXCAL_RX_GAIN_TABLE_3_2_B2_MACRO__
#define __RXCAL_RX_GAIN_TABLE_3_2_B2_MACRO__

/* macros for field rxcal_rx_gain_table_2_chn2 */
#define RXCAL_RX_GAIN_TABLE_3_2_B2__RXCAL_RX_GAIN_TABLE_2_CHN2__SHIFT         0
#define RXCAL_RX_GAIN_TABLE_3_2_B2__RXCAL_RX_GAIN_TABLE_2_CHN2__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_3_2_B2__RXCAL_RX_GAIN_TABLE_2_CHN2__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_3_2_B2__RXCAL_RX_GAIN_TABLE_2_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_3_2_B2__RXCAL_RX_GAIN_TABLE_2_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_3_2_B2__RXCAL_RX_GAIN_TABLE_2_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_3_2_B2__RXCAL_RX_GAIN_TABLE_2_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_3_chn2 */
#define RXCAL_RX_GAIN_TABLE_3_2_B2__RXCAL_RX_GAIN_TABLE_3_CHN2__SHIFT        16
#define RXCAL_RX_GAIN_TABLE_3_2_B2__RXCAL_RX_GAIN_TABLE_3_CHN2__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_3_2_B2__RXCAL_RX_GAIN_TABLE_3_CHN2__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_3_2_B2__RXCAL_RX_GAIN_TABLE_3_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_3_2_B2__RXCAL_RX_GAIN_TABLE_3_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_3_2_B2__RXCAL_RX_GAIN_TABLE_3_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_3_2_B2__RXCAL_RX_GAIN_TABLE_3_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_3_2_B2__TYPE                               uint32_t
#define RXCAL_RX_GAIN_TABLE_3_2_B2__READ                            0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_3_2_B2__WRITE                           0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_3_2_B2_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_3_2_b2 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_3_2_B2__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_5_4_b2 */
#ifndef __RXCAL_RX_GAIN_TABLE_5_4_B2_MACRO__
#define __RXCAL_RX_GAIN_TABLE_5_4_B2_MACRO__

/* macros for field rxcal_rx_gain_table_4_chn2 */
#define RXCAL_RX_GAIN_TABLE_5_4_B2__RXCAL_RX_GAIN_TABLE_4_CHN2__SHIFT         0
#define RXCAL_RX_GAIN_TABLE_5_4_B2__RXCAL_RX_GAIN_TABLE_4_CHN2__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_5_4_B2__RXCAL_RX_GAIN_TABLE_4_CHN2__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_5_4_B2__RXCAL_RX_GAIN_TABLE_4_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_5_4_B2__RXCAL_RX_GAIN_TABLE_4_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_5_4_B2__RXCAL_RX_GAIN_TABLE_4_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_5_4_B2__RXCAL_RX_GAIN_TABLE_4_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_5_chn2 */
#define RXCAL_RX_GAIN_TABLE_5_4_B2__RXCAL_RX_GAIN_TABLE_5_CHN2__SHIFT        16
#define RXCAL_RX_GAIN_TABLE_5_4_B2__RXCAL_RX_GAIN_TABLE_5_CHN2__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_5_4_B2__RXCAL_RX_GAIN_TABLE_5_CHN2__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_5_4_B2__RXCAL_RX_GAIN_TABLE_5_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_5_4_B2__RXCAL_RX_GAIN_TABLE_5_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_5_4_B2__RXCAL_RX_GAIN_TABLE_5_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_5_4_B2__RXCAL_RX_GAIN_TABLE_5_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_5_4_B2__TYPE                               uint32_t
#define RXCAL_RX_GAIN_TABLE_5_4_B2__READ                            0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_5_4_B2__WRITE                           0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_5_4_B2_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_5_4_b2 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_5_4_B2__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_7_6_b2 */
#ifndef __RXCAL_RX_GAIN_TABLE_7_6_B2_MACRO__
#define __RXCAL_RX_GAIN_TABLE_7_6_B2_MACRO__

/* macros for field rxcal_rx_gain_table_6_chn2 */
#define RXCAL_RX_GAIN_TABLE_7_6_B2__RXCAL_RX_GAIN_TABLE_6_CHN2__SHIFT         0
#define RXCAL_RX_GAIN_TABLE_7_6_B2__RXCAL_RX_GAIN_TABLE_6_CHN2__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_7_6_B2__RXCAL_RX_GAIN_TABLE_6_CHN2__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_7_6_B2__RXCAL_RX_GAIN_TABLE_6_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_7_6_B2__RXCAL_RX_GAIN_TABLE_6_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_7_6_B2__RXCAL_RX_GAIN_TABLE_6_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_7_6_B2__RXCAL_RX_GAIN_TABLE_6_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_7_chn2 */
#define RXCAL_RX_GAIN_TABLE_7_6_B2__RXCAL_RX_GAIN_TABLE_7_CHN2__SHIFT        16
#define RXCAL_RX_GAIN_TABLE_7_6_B2__RXCAL_RX_GAIN_TABLE_7_CHN2__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_7_6_B2__RXCAL_RX_GAIN_TABLE_7_CHN2__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_7_6_B2__RXCAL_RX_GAIN_TABLE_7_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_7_6_B2__RXCAL_RX_GAIN_TABLE_7_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_7_6_B2__RXCAL_RX_GAIN_TABLE_7_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_7_6_B2__RXCAL_RX_GAIN_TABLE_7_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_7_6_B2__TYPE                               uint32_t
#define RXCAL_RX_GAIN_TABLE_7_6_B2__READ                            0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_7_6_B2__WRITE                           0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_7_6_B2_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_7_6_b2 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_7_6_B2__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_9_8_b2 */
#ifndef __RXCAL_RX_GAIN_TABLE_9_8_B2_MACRO__
#define __RXCAL_RX_GAIN_TABLE_9_8_B2_MACRO__

/* macros for field rxcal_rx_gain_table_8_chn2 */
#define RXCAL_RX_GAIN_TABLE_9_8_B2__RXCAL_RX_GAIN_TABLE_8_CHN2__SHIFT         0
#define RXCAL_RX_GAIN_TABLE_9_8_B2__RXCAL_RX_GAIN_TABLE_8_CHN2__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_9_8_B2__RXCAL_RX_GAIN_TABLE_8_CHN2__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_9_8_B2__RXCAL_RX_GAIN_TABLE_8_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_9_8_B2__RXCAL_RX_GAIN_TABLE_8_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_9_8_B2__RXCAL_RX_GAIN_TABLE_8_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_9_8_B2__RXCAL_RX_GAIN_TABLE_8_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_9_chn2 */
#define RXCAL_RX_GAIN_TABLE_9_8_B2__RXCAL_RX_GAIN_TABLE_9_CHN2__SHIFT        16
#define RXCAL_RX_GAIN_TABLE_9_8_B2__RXCAL_RX_GAIN_TABLE_9_CHN2__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_9_8_B2__RXCAL_RX_GAIN_TABLE_9_CHN2__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_9_8_B2__RXCAL_RX_GAIN_TABLE_9_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_9_8_B2__RXCAL_RX_GAIN_TABLE_9_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_9_8_B2__RXCAL_RX_GAIN_TABLE_9_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_9_8_B2__RXCAL_RX_GAIN_TABLE_9_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_9_8_B2__TYPE                               uint32_t
#define RXCAL_RX_GAIN_TABLE_9_8_B2__READ                            0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_9_8_B2__WRITE                           0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_9_8_B2_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_9_8_b2 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_9_8_B2__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_11_10_b2 */
#ifndef __RXCAL_RX_GAIN_TABLE_11_10_B2_MACRO__
#define __RXCAL_RX_GAIN_TABLE_11_10_B2_MACRO__

/* macros for field rxcal_rx_gain_table_10_chn2 */
#define RXCAL_RX_GAIN_TABLE_11_10_B2__RXCAL_RX_GAIN_TABLE_10_CHN2__SHIFT      0
#define RXCAL_RX_GAIN_TABLE_11_10_B2__RXCAL_RX_GAIN_TABLE_10_CHN2__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_11_10_B2__RXCAL_RX_GAIN_TABLE_10_CHN2__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_11_10_B2__RXCAL_RX_GAIN_TABLE_10_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_11_10_B2__RXCAL_RX_GAIN_TABLE_10_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_11_10_B2__RXCAL_RX_GAIN_TABLE_10_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_11_10_B2__RXCAL_RX_GAIN_TABLE_10_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_11_chn2 */
#define RXCAL_RX_GAIN_TABLE_11_10_B2__RXCAL_RX_GAIN_TABLE_11_CHN2__SHIFT     16
#define RXCAL_RX_GAIN_TABLE_11_10_B2__RXCAL_RX_GAIN_TABLE_11_CHN2__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_11_10_B2__RXCAL_RX_GAIN_TABLE_11_CHN2__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_11_10_B2__RXCAL_RX_GAIN_TABLE_11_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_11_10_B2__RXCAL_RX_GAIN_TABLE_11_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_11_10_B2__RXCAL_RX_GAIN_TABLE_11_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_11_10_B2__RXCAL_RX_GAIN_TABLE_11_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_11_10_B2__TYPE                             uint32_t
#define RXCAL_RX_GAIN_TABLE_11_10_B2__READ                          0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_11_10_B2__WRITE                         0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_11_10_B2_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_11_10_b2 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_11_10_B2__NUM                             1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_13_12_b2 */
#ifndef __RXCAL_RX_GAIN_TABLE_13_12_B2_MACRO__
#define __RXCAL_RX_GAIN_TABLE_13_12_B2_MACRO__

/* macros for field rxcal_rx_gain_table_12_chn2 */
#define RXCAL_RX_GAIN_TABLE_13_12_B2__RXCAL_RX_GAIN_TABLE_12_CHN2__SHIFT      0
#define RXCAL_RX_GAIN_TABLE_13_12_B2__RXCAL_RX_GAIN_TABLE_12_CHN2__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_13_12_B2__RXCAL_RX_GAIN_TABLE_12_CHN2__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_13_12_B2__RXCAL_RX_GAIN_TABLE_12_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_13_12_B2__RXCAL_RX_GAIN_TABLE_12_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_13_12_B2__RXCAL_RX_GAIN_TABLE_12_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_13_12_B2__RXCAL_RX_GAIN_TABLE_12_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_13_chn2 */
#define RXCAL_RX_GAIN_TABLE_13_12_B2__RXCAL_RX_GAIN_TABLE_13_CHN2__SHIFT     16
#define RXCAL_RX_GAIN_TABLE_13_12_B2__RXCAL_RX_GAIN_TABLE_13_CHN2__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_13_12_B2__RXCAL_RX_GAIN_TABLE_13_CHN2__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_13_12_B2__RXCAL_RX_GAIN_TABLE_13_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_13_12_B2__RXCAL_RX_GAIN_TABLE_13_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_13_12_B2__RXCAL_RX_GAIN_TABLE_13_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_13_12_B2__RXCAL_RX_GAIN_TABLE_13_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_13_12_B2__TYPE                             uint32_t
#define RXCAL_RX_GAIN_TABLE_13_12_B2__READ                          0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_13_12_B2__WRITE                         0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_13_12_B2_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_13_12_b2 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_13_12_B2__NUM                             1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_15_14_b2 */
#ifndef __RXCAL_RX_GAIN_TABLE_15_14_B2_MACRO__
#define __RXCAL_RX_GAIN_TABLE_15_14_B2_MACRO__

/* macros for field rxcal_rx_gain_table_14_chn2 */
#define RXCAL_RX_GAIN_TABLE_15_14_B2__RXCAL_RX_GAIN_TABLE_14_CHN2__SHIFT      0
#define RXCAL_RX_GAIN_TABLE_15_14_B2__RXCAL_RX_GAIN_TABLE_14_CHN2__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_15_14_B2__RXCAL_RX_GAIN_TABLE_14_CHN2__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_15_14_B2__RXCAL_RX_GAIN_TABLE_14_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_15_14_B2__RXCAL_RX_GAIN_TABLE_14_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_15_14_B2__RXCAL_RX_GAIN_TABLE_14_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_15_14_B2__RXCAL_RX_GAIN_TABLE_14_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_15_chn2 */
#define RXCAL_RX_GAIN_TABLE_15_14_B2__RXCAL_RX_GAIN_TABLE_15_CHN2__SHIFT     16
#define RXCAL_RX_GAIN_TABLE_15_14_B2__RXCAL_RX_GAIN_TABLE_15_CHN2__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_15_14_B2__RXCAL_RX_GAIN_TABLE_15_CHN2__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_15_14_B2__RXCAL_RX_GAIN_TABLE_15_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_15_14_B2__RXCAL_RX_GAIN_TABLE_15_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_15_14_B2__RXCAL_RX_GAIN_TABLE_15_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_15_14_B2__RXCAL_RX_GAIN_TABLE_15_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_15_14_B2__TYPE                             uint32_t
#define RXCAL_RX_GAIN_TABLE_15_14_B2__READ                          0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_15_14_B2__WRITE                         0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_15_14_B2_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_15_14_b2 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_15_14_B2__NUM                             1

/* macros for BlueprintGlobalNameSpace::rxcal_gain_delta_db_table_3_0_b2 */
#ifndef __RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2_MACRO__
#define __RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2_MACRO__

/* macros for field rxcal_gain_delta_db_table_0_chn2 */
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN2__SHIFT \
                    0
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN2__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN2__MASK \
                    0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field rxcal_gain_delta_db_table_1_chn2 */
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN2__SHIFT \
                    8
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN2__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN2__MASK \
                    0x00003f00U
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))

/* macros for field rxcal_gain_delta_db_table_2_chn2 */
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN2__SHIFT \
                    16
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN2__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN2__MASK \
                    0x003f0000U
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))

/* macros for field rxcal_gain_delta_db_table_3_chn2 */
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN2__SHIFT \
                    24
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN2__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN2__MASK \
                    0x3f000000U
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__TYPE                         uint32_t
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__READ                      0x3f3f3f3fU
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__WRITE                     0x3f3f3f3fU

#endif /* __RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2_MACRO__ */


/* macros for BB_rxcal_gain_delta_db_table_3_0_b2 */
#define INST_BB_RXCAL_GAIN_DELTA_DB_TABLE_3_0_B2__NUM                         1

/* macros for BlueprintGlobalNameSpace::rxcal_gain_delta_db_table_7_4_b2 */
#ifndef __RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2_MACRO__
#define __RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2_MACRO__

/* macros for field rxcal_gain_delta_db_table_4_chn2 */
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN2__SHIFT \
                    0
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN2__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN2__MASK \
                    0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field rxcal_gain_delta_db_table_5_chn2 */
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN2__SHIFT \
                    8
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN2__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN2__MASK \
                    0x00003f00U
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))

/* macros for field rxcal_gain_delta_db_table_6_chn2 */
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN2__SHIFT \
                    16
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN2__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN2__MASK \
                    0x003f0000U
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))

/* macros for field rxcal_gain_delta_db_table_7_chn2 */
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN2__SHIFT \
                    24
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN2__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN2__MASK \
                    0x3f000000U
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__TYPE                         uint32_t
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__READ                      0x3f3f3f3fU
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__WRITE                     0x3f3f3f3fU

#endif /* __RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2_MACRO__ */


/* macros for BB_rxcal_gain_delta_db_table_7_4_b2 */
#define INST_BB_RXCAL_GAIN_DELTA_DB_TABLE_7_4_B2__NUM                         1

/* macros for BlueprintGlobalNameSpace::rxcal_gain_delta_db_table_11_8_b2 */
#ifndef __RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2_MACRO__
#define __RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2_MACRO__

/* macros for field rxcal_gain_delta_db_table_8_chn2 */
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN2__SHIFT \
                    0
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN2__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN2__MASK \
                    0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field rxcal_gain_delta_db_table_9_chn2 */
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN2__SHIFT \
                    8
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN2__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN2__MASK \
                    0x00003f00U
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))

/* macros for field rxcal_gain_delta_db_table_10_chn2 */
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN2__SHIFT \
                    16
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN2__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN2__MASK \
                    0x003f0000U
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))

/* macros for field rxcal_gain_delta_db_table_11_chn2 */
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN2__SHIFT \
                    24
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN2__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN2__MASK \
                    0x3f000000U
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__TYPE                        uint32_t
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__READ                     0x3f3f3f3fU
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__WRITE                    0x3f3f3f3fU

#endif /* __RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2_MACRO__ */


/* macros for BB_rxcal_gain_delta_db_table_11_8_b2 */
#define INST_BB_RXCAL_GAIN_DELTA_DB_TABLE_11_8_B2__NUM                        1

/* macros for BlueprintGlobalNameSpace::rxcal_gain_delta_db_table_15_12_b2 */
#ifndef __RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2_MACRO__
#define __RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2_MACRO__

/* macros for field rxcal_gain_delta_db_table_12_chn2 */
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN2__SHIFT \
                    0
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN2__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN2__MASK \
                    0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field rxcal_gain_delta_db_table_13_chn2 */
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN2__SHIFT \
                    8
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN2__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN2__MASK \
                    0x00003f00U
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))

/* macros for field rxcal_gain_delta_db_table_14_chn2 */
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN2__SHIFT \
                    16
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN2__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN2__MASK \
                    0x003f0000U
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))

/* macros for field rxcal_gain_delta_db_table_15_chn2 */
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN2__SHIFT \
                    24
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN2__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN2__MASK \
                    0x3f000000U
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__TYPE                       uint32_t
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__READ                    0x3f3f3f3fU
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__WRITE                   0x3f3f3f3fU

#endif /* __RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2_MACRO__ */


/* macros for BB_rxcal_gain_delta_db_table_15_12_b2 */
#define INST_BB_RXCAL_GAIN_DELTA_DB_TABLE_15_12_B2__NUM                       1

/* macros for BlueprintGlobalNameSpace::rxcal_tx_iqcorr_idx_7_0_b2 */
#ifndef __RXCAL_TX_IQCORR_IDX_7_0_B2_MACRO__
#define __RXCAL_TX_IQCORR_IDX_7_0_B2_MACRO__

/* macros for field rxcal_tx_iqcorr_idx_0_chn2 */
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_0_CHN2__SHIFT         0
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_0_CHN2__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_0_CHN2__MASK \
                    0x0000000fU
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_0_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_0_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_0_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_0_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field rxcal_tx_iqcorr_idx_1_chn2 */
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_1_CHN2__SHIFT         4
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_1_CHN2__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_1_CHN2__MASK \
                    0x000000f0U
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_1_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_1_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_1_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_1_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field rxcal_tx_iqcorr_idx_2_chn2 */
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_2_CHN2__SHIFT         8
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_2_CHN2__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_2_CHN2__MASK \
                    0x00000f00U
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_2_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_2_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_2_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_2_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field rxcal_tx_iqcorr_idx_3_chn2 */
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_3_CHN2__SHIFT        12
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_3_CHN2__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_3_CHN2__MASK \
                    0x0000f000U
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_3_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_3_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_3_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_3_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field rxcal_tx_iqcorr_idx_4_chn2 */
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_4_CHN2__SHIFT        16
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_4_CHN2__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_4_CHN2__MASK \
                    0x000f0000U
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_4_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_4_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_4_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_4_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field rxcal_tx_iqcorr_idx_5_chn2 */
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_5_CHN2__SHIFT        20
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_5_CHN2__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_5_CHN2__MASK \
                    0x00f00000U
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_5_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_5_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_5_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_5_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field rxcal_tx_iqcorr_idx_6_chn2 */
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_6_CHN2__SHIFT        24
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_6_CHN2__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_6_CHN2__MASK \
                    0x0f000000U
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_6_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_6_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_6_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_6_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field rxcal_tx_iqcorr_idx_7_chn2 */
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_7_CHN2__SHIFT        28
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_7_CHN2__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_7_CHN2__MASK \
                    0xf0000000U
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_7_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_7_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_7_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B2__RXCAL_TX_IQCORR_IDX_7_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RXCAL_TX_IQCORR_IDX_7_0_B2__TYPE                               uint32_t
#define RXCAL_TX_IQCORR_IDX_7_0_B2__READ                            0xffffffffU
#define RXCAL_TX_IQCORR_IDX_7_0_B2__WRITE                           0xffffffffU

#endif /* __RXCAL_TX_IQCORR_IDX_7_0_B2_MACRO__ */


/* macros for BB_rxcal_tx_iqcorr_idx_7_0_b2 */
#define INST_BB_RXCAL_TX_IQCORR_IDX_7_0_B2__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_tx_iqcorr_idx_15_8_b2 */
#ifndef __RXCAL_TX_IQCORR_IDX_15_8_B2_MACRO__
#define __RXCAL_TX_IQCORR_IDX_15_8_B2_MACRO__

/* macros for field rxcal_tx_iqcorr_idx_8_chn2 */
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_8_CHN2__SHIFT        0
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_8_CHN2__WIDTH        4
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_8_CHN2__MASK \
                    0x0000000fU
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_8_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_8_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_8_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_8_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field rxcal_tx_iqcorr_idx_9_chn2 */
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_9_CHN2__SHIFT        4
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_9_CHN2__WIDTH        4
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_9_CHN2__MASK \
                    0x000000f0U
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_9_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_9_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_9_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_9_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field rxcal_tx_iqcorr_idx_10_chn2 */
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_10_CHN2__SHIFT       8
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_10_CHN2__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_10_CHN2__MASK \
                    0x00000f00U
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_10_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_10_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_10_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_10_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field rxcal_tx_iqcorr_idx_11_chn2 */
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_11_CHN2__SHIFT      12
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_11_CHN2__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_11_CHN2__MASK \
                    0x0000f000U
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_11_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_11_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_11_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_11_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field rxcal_tx_iqcorr_idx_12_chn2 */
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_12_CHN2__SHIFT      16
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_12_CHN2__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_12_CHN2__MASK \
                    0x000f0000U
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_12_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_12_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_12_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_12_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field rxcal_tx_iqcorr_idx_13_chn2 */
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_13_CHN2__SHIFT      20
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_13_CHN2__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_13_CHN2__MASK \
                    0x00f00000U
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_13_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_13_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_13_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_13_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field rxcal_tx_iqcorr_idx_14_chn2 */
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_14_CHN2__SHIFT      24
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_14_CHN2__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_14_CHN2__MASK \
                    0x0f000000U
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_14_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_14_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_14_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_14_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field rxcal_tx_iqcorr_idx_15_chn2 */
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_15_CHN2__SHIFT      28
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_15_CHN2__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_15_CHN2__MASK \
                    0xf0000000U
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_15_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_15_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_15_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B2__RXCAL_TX_IQCORR_IDX_15_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RXCAL_TX_IQCORR_IDX_15_8_B2__TYPE                              uint32_t
#define RXCAL_TX_IQCORR_IDX_15_8_B2__READ                           0xffffffffU
#define RXCAL_TX_IQCORR_IDX_15_8_B2__WRITE                          0xffffffffU

#endif /* __RXCAL_TX_IQCORR_IDX_15_8_B2_MACRO__ */


/* macros for BB_rxcal_tx_iqcorr_idx_15_8_b2 */
#define INST_BB_RXCAL_TX_IQCORR_IDX_15_8_B2__NUM                              1

/* macros for BlueprintGlobalNameSpace::rxcal_tx_iqcorr_idx_23_16_b2 */
#ifndef __RXCAL_TX_IQCORR_IDX_23_16_B2_MACRO__
#define __RXCAL_TX_IQCORR_IDX_23_16_B2_MACRO__

/* macros for field rxcal_tx_iqcorr_idx_16_chn2 */
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_16_CHN2__SHIFT      0
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_16_CHN2__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_16_CHN2__MASK \
                    0x0000000fU
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_16_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_16_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_16_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_16_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field rxcal_tx_iqcorr_idx_17_chn2 */
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_17_CHN2__SHIFT      4
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_17_CHN2__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_17_CHN2__MASK \
                    0x000000f0U
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_17_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_17_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_17_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_17_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field rxcal_tx_iqcorr_idx_18_chn2 */
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_18_CHN2__SHIFT      8
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_18_CHN2__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_18_CHN2__MASK \
                    0x00000f00U
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_18_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_18_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_18_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_18_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field rxcal_tx_iqcorr_idx_19_chn2 */
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_19_CHN2__SHIFT     12
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_19_CHN2__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_19_CHN2__MASK \
                    0x0000f000U
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_19_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_19_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_19_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_19_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field rxcal_tx_iqcorr_idx_20_chn2 */
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_20_CHN2__SHIFT     16
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_20_CHN2__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_20_CHN2__MASK \
                    0x000f0000U
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_20_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_20_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_20_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_20_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field rxcal_tx_iqcorr_idx_21_chn2 */
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_21_CHN2__SHIFT     20
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_21_CHN2__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_21_CHN2__MASK \
                    0x00f00000U
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_21_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_21_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_21_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_21_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field rxcal_tx_iqcorr_idx_22_chn2 */
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_22_CHN2__SHIFT     24
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_22_CHN2__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_22_CHN2__MASK \
                    0x0f000000U
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_22_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_22_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_22_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_22_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field rxcal_tx_iqcorr_idx_23_chn2 */
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_23_CHN2__SHIFT     28
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_23_CHN2__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_23_CHN2__MASK \
                    0xf0000000U
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_23_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_23_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_23_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B2__RXCAL_TX_IQCORR_IDX_23_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RXCAL_TX_IQCORR_IDX_23_16_B2__TYPE                             uint32_t
#define RXCAL_TX_IQCORR_IDX_23_16_B2__READ                          0xffffffffU
#define RXCAL_TX_IQCORR_IDX_23_16_B2__WRITE                         0xffffffffU

#endif /* __RXCAL_TX_IQCORR_IDX_23_16_B2_MACRO__ */


/* macros for BB_rxcal_tx_iqcorr_idx_23_16_b2 */
#define INST_BB_RXCAL_TX_IQCORR_IDX_23_16_B2__NUM                             1

/* macros for BlueprintGlobalNameSpace::rxcal_tx_iqcorr_idx_31_24_b2 */
#ifndef __RXCAL_TX_IQCORR_IDX_31_24_B2_MACRO__
#define __RXCAL_TX_IQCORR_IDX_31_24_B2_MACRO__

/* macros for field rxcal_tx_iqcorr_idx_24_chn2 */
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_24_CHN2__SHIFT      0
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_24_CHN2__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_24_CHN2__MASK \
                    0x0000000fU
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_24_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_24_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_24_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_24_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field rxcal_tx_iqcorr_idx_25_chn2 */
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_25_CHN2__SHIFT      4
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_25_CHN2__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_25_CHN2__MASK \
                    0x000000f0U
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_25_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_25_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_25_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_25_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field rxcal_tx_iqcorr_idx_26_chn2 */
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_26_CHN2__SHIFT      8
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_26_CHN2__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_26_CHN2__MASK \
                    0x00000f00U
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_26_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_26_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_26_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_26_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field rxcal_tx_iqcorr_idx_27_chn2 */
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_27_CHN2__SHIFT     12
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_27_CHN2__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_27_CHN2__MASK \
                    0x0000f000U
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_27_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_27_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_27_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_27_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field rxcal_tx_iqcorr_idx_28_chn2 */
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_28_CHN2__SHIFT     16
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_28_CHN2__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_28_CHN2__MASK \
                    0x000f0000U
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_28_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_28_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_28_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_28_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field rxcal_tx_iqcorr_idx_29_chn2 */
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_29_CHN2__SHIFT     20
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_29_CHN2__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_29_CHN2__MASK \
                    0x00f00000U
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_29_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_29_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_29_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_29_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field rxcal_tx_iqcorr_idx_30_chn2 */
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_30_CHN2__SHIFT     24
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_30_CHN2__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_30_CHN2__MASK \
                    0x0f000000U
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_30_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_30_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_30_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_30_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field rxcal_tx_iqcorr_idx_31_chn2 */
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_31_CHN2__SHIFT     28
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_31_CHN2__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_31_CHN2__MASK \
                    0xf0000000U
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_31_CHN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_31_CHN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_31_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B2__RXCAL_TX_IQCORR_IDX_31_CHN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RXCAL_TX_IQCORR_IDX_31_24_B2__TYPE                             uint32_t
#define RXCAL_TX_IQCORR_IDX_31_24_B2__READ                          0xffffffffU
#define RXCAL_TX_IQCORR_IDX_31_24_B2__WRITE                         0xffffffffU

#endif /* __RXCAL_TX_IQCORR_IDX_31_24_B2_MACRO__ */


/* macros for BB_rxcal_tx_iqcorr_idx_31_24_b2 */
#define INST_BB_RXCAL_TX_IQCORR_IDX_31_24_B2__NUM                             1

/* macros for BlueprintGlobalNameSpace::paprd_sm_sig_gain_table_0_2_b2 */
#ifndef __PAPRD_SM_SIG_GAIN_TABLE_0_2_B2_MACRO__
#define __PAPRD_SM_SIG_GAIN_TABLE_0_2_B2_MACRO__

/* macros for field paprd_sm_sig_gain_0 */
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_0__SHIFT            0
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_0__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_0__MASK   0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_sm_sig_gain_1 */
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_1__SHIFT           10
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_1__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_1__MASK   0x000ffc00U
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_sm_sig_gain_2 */
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_2__SHIFT           20
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_2__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_2__MASK   0x3ff00000U
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__PAPRD_SM_SIG_GAIN_2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__TYPE                           uint32_t
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__READ                        0x3fffffffU
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__WRITE                       0x3fffffffU

#endif /* __PAPRD_SM_SIG_GAIN_TABLE_0_2_B2_MACRO__ */


/* macros for BB_paprd_sm_sig_gain_table_0_2_b2 */
#define INST_BB_PAPRD_SM_SIG_GAIN_TABLE_0_2_B2__NUM                           1

/* macros for BlueprintGlobalNameSpace::paprd_sm_sig_gain_table_3_5_b2 */
#ifndef __PAPRD_SM_SIG_GAIN_TABLE_3_5_B2_MACRO__
#define __PAPRD_SM_SIG_GAIN_TABLE_3_5_B2_MACRO__

/* macros for field paprd_sm_sig_gain_3 */
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_3__SHIFT            0
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_3__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_3__MASK   0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_3__READ(src) \
                    (uint32_t)(src)\
                    & 0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_3__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_sm_sig_gain_4 */
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_4__SHIFT           10
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_4__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_4__MASK   0x000ffc00U
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_4__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_4__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_4__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_sm_sig_gain_5 */
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_5__SHIFT           20
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_5__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_5__MASK   0x3ff00000U
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_5__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_5__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__PAPRD_SM_SIG_GAIN_5__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__TYPE                           uint32_t
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__READ                        0x3fffffffU
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__WRITE                       0x3fffffffU

#endif /* __PAPRD_SM_SIG_GAIN_TABLE_3_5_B2_MACRO__ */


/* macros for BB_paprd_sm_sig_gain_table_3_5_b2 */
#define INST_BB_PAPRD_SM_SIG_GAIN_TABLE_3_5_B2__NUM                           1

/* macros for BlueprintGlobalNameSpace::paprd_sm_sig_gain_table_6_b2 */
#ifndef __PAPRD_SM_SIG_GAIN_TABLE_6_B2_MACRO__
#define __PAPRD_SM_SIG_GAIN_TABLE_6_B2_MACRO__

/* macros for field paprd_sm_sig_gain_6 */
#define PAPRD_SM_SIG_GAIN_TABLE_6_B2__PAPRD_SM_SIG_GAIN_6__SHIFT              0
#define PAPRD_SM_SIG_GAIN_TABLE_6_B2__PAPRD_SM_SIG_GAIN_6__WIDTH             10
#define PAPRD_SM_SIG_GAIN_TABLE_6_B2__PAPRD_SM_SIG_GAIN_6__MASK     0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_6_B2__PAPRD_SM_SIG_GAIN_6__READ(src) \
                    (uint32_t)(src)\
                    & 0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_6_B2__PAPRD_SM_SIG_GAIN_6__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_6_B2__PAPRD_SM_SIG_GAIN_6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_6_B2__PAPRD_SM_SIG_GAIN_6__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define PAPRD_SM_SIG_GAIN_TABLE_6_B2__TYPE                             uint32_t
#define PAPRD_SM_SIG_GAIN_TABLE_6_B2__READ                          0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_6_B2__WRITE                         0x000003ffU

#endif /* __PAPRD_SM_SIG_GAIN_TABLE_6_B2_MACRO__ */


/* macros for BB_paprd_sm_sig_gain_table_6_b2 */
#define INST_BB_PAPRD_SM_SIG_GAIN_TABLE_6_B2__NUM                             1

/* macros for BlueprintGlobalNameSpace::preemp_coef_set0_b2 */
#ifndef __PREEMP_COEF_SET0_B2_MACRO__
#define __PREEMP_COEF_SET0_B2_MACRO__

/* macros for field tx_preemp_coef_0_b2 */
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_0_B2__SHIFT                       0
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_0_B2__WIDTH                       9
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_0_B2__MASK              0x000001ffU
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_0_B2__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_0_B2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_0_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_0_B2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field tx_preemp_coef_1_b2 */
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_1_B2__SHIFT                       9
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_1_B2__WIDTH                       9
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_1_B2__MASK              0x0003fe00U
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_1_B2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_1_B2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_1_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_1_B2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field tx_preemp_coef_2_b2 */
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_2_B2__SHIFT                      18
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_2_B2__WIDTH                       9
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_2_B2__MASK              0x07fc0000U
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_2_B2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_2_B2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_2_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PREEMP_COEF_SET0_B2__TX_PREEMP_COEF_2_B2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define PREEMP_COEF_SET0_B2__TYPE                                      uint32_t
#define PREEMP_COEF_SET0_B2__READ                                   0x07ffffffU
#define PREEMP_COEF_SET0_B2__WRITE                                  0x07ffffffU

#endif /* __PREEMP_COEF_SET0_B2_MACRO__ */


/* macros for BB_preemp_coef_set0_b2 */
#define INST_BB_PREEMP_COEF_SET0_B2__NUM                                      1

/* macros for BlueprintGlobalNameSpace::preemp_coef_set1_b2 */
#ifndef __PREEMP_COEF_SET1_B2_MACRO__
#define __PREEMP_COEF_SET1_B2_MACRO__

/* macros for field tx_preemp_coef_3_b2 */
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_3_B2__SHIFT                       0
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_3_B2__WIDTH                       9
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_3_B2__MASK              0x000001ffU
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_3_B2__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_3_B2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_3_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_3_B2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field tx_preemp_coef_4_b2 */
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_4_B2__SHIFT                       9
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_4_B2__WIDTH                       9
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_4_B2__MASK              0x0003fe00U
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_4_B2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_4_B2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_4_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_4_B2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field tx_preemp_coef_5_b2 */
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_5_B2__SHIFT                      18
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_5_B2__WIDTH                       9
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_5_B2__MASK              0x07fc0000U
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_5_B2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_5_B2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_5_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PREEMP_COEF_SET1_B2__TX_PREEMP_COEF_5_B2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define PREEMP_COEF_SET1_B2__TYPE                                      uint32_t
#define PREEMP_COEF_SET1_B2__READ                                   0x07ffffffU
#define PREEMP_COEF_SET1_B2__WRITE                                  0x07ffffffU

#endif /* __PREEMP_COEF_SET1_B2_MACRO__ */


/* macros for BB_preemp_coef_set1_b2 */
#define INST_BB_PREEMP_COEF_SET1_B2__NUM                                      1

/* macros for BlueprintGlobalNameSpace::preemp_coef_set2_b2 */
#ifndef __PREEMP_COEF_SET2_B2_MACRO__
#define __PREEMP_COEF_SET2_B2_MACRO__

/* macros for field tx_preemp_coef_6_b2 */
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_6_B2__SHIFT                       0
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_6_B2__WIDTH                       9
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_6_B2__MASK              0x000001ffU
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_6_B2__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_6_B2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_6_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_6_B2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field tx_preemp_coef_7_b2 */
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_7_B2__SHIFT                       9
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_7_B2__WIDTH                       9
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_7_B2__MASK              0x0003fe00U
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_7_B2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_7_B2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_7_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_7_B2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field tx_preemp_coef_8_b2 */
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_8_B2__SHIFT                      18
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_8_B2__WIDTH                       9
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_8_B2__MASK              0x07fc0000U
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_8_B2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_8_B2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_8_B2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PREEMP_COEF_SET2_B2__TX_PREEMP_COEF_8_B2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define PREEMP_COEF_SET2_B2__TYPE                                      uint32_t
#define PREEMP_COEF_SET2_B2__READ                                   0x07ffffffU
#define PREEMP_COEF_SET2_B2__WRITE                                  0x07ffffffU

#endif /* __PREEMP_COEF_SET2_B2_MACRO__ */


/* macros for BB_preemp_coef_set2_b2 */
#define INST_BB_PREEMP_COEF_SET2_B2__NUM                                      1

/* macros for BlueprintGlobalNameSpace::chaninfo_vht80_b2 */
#ifndef __CHANINFO_VHT80_B2_MACRO__
#define __CHANINFO_VHT80_B2_MACRO__

/* macros for field chaninfo_vht80_chn2 */
#define CHANINFO_VHT80_B2__CHANINFO_VHT80_CHN2__SHIFT                         0
#define CHANINFO_VHT80_B2__CHANINFO_VHT80_CHN2__WIDTH                        32
#define CHANINFO_VHT80_B2__CHANINFO_VHT80_CHN2__MASK                0xffffffffU
#define CHANINFO_VHT80_B2__CHANINFO_VHT80_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0xffffffffU
#define CHANINFO_VHT80_B2__TYPE                                        uint32_t
#define CHANINFO_VHT80_B2__READ                                     0xffffffffU

#endif /* __CHANINFO_VHT80_B2_MACRO__ */


/* macros for BB_chaninfo_vht80_b2 */
#define INST_BB_CHANINFO_VHT80_B2__NUM                                       64

/* macros for BlueprintGlobalNameSpace::normrx_rxiq_corr_coeff_b2 */
#ifndef __NORMRX_RXIQ_CORR_COEFF_B2_MACRO__
#define __NORMRX_RXIQ_CORR_COEFF_B2_MACRO__

/* macros for field normrx_iqc_coeff_table_chn2 */
#define NORMRX_RXIQ_CORR_COEFF_B2__NORMRX_IQC_COEFF_TABLE_CHN2__SHIFT         0
#define NORMRX_RXIQ_CORR_COEFF_B2__NORMRX_IQC_COEFF_TABLE_CHN2__WIDTH        18
#define NORMRX_RXIQ_CORR_COEFF_B2__NORMRX_IQC_COEFF_TABLE_CHN2__MASK \
                    0x0003ffffU
#define NORMRX_RXIQ_CORR_COEFF_B2__NORMRX_IQC_COEFF_TABLE_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define NORMRX_RXIQ_CORR_COEFF_B2__NORMRX_IQC_COEFF_TABLE_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define NORMRX_RXIQ_CORR_COEFF_B2__NORMRX_IQC_COEFF_TABLE_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define NORMRX_RXIQ_CORR_COEFF_B2__NORMRX_IQC_COEFF_TABLE_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define NORMRX_RXIQ_CORR_COEFF_B2__TYPE                                uint32_t
#define NORMRX_RXIQ_CORR_COEFF_B2__READ                             0x0003ffffU
#define NORMRX_RXIQ_CORR_COEFF_B2__WRITE                            0x0003ffffU

#endif /* __NORMRX_RXIQ_CORR_COEFF_B2_MACRO__ */


/* macros for BB_normrx_rxiq_corr_coeff_b2 */
#define INST_BB_NORMRX_RXIQ_CORR_COEFF_B2__NUM                              160

/* macros for BlueprintGlobalNameSpace::paprd_mem_tab_b2 */
#ifndef __PAPRD_MEM_TAB_B2_MACRO__
#define __PAPRD_MEM_TAB_B2_MACRO__

/* macros for field paprd_mem */
#define PAPRD_MEM_TAB_B2__PAPRD_MEM__SHIFT                                    0
#define PAPRD_MEM_TAB_B2__PAPRD_MEM__WIDTH                                   22
#define PAPRD_MEM_TAB_B2__PAPRD_MEM__MASK                           0x003fffffU
#define PAPRD_MEM_TAB_B2__PAPRD_MEM__READ(src)    (uint32_t)(src) & 0x003fffffU
#define PAPRD_MEM_TAB_B2__PAPRD_MEM__WRITE(src) ((uint32_t)(src) & 0x003fffffU)
#define PAPRD_MEM_TAB_B2__PAPRD_MEM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define PAPRD_MEM_TAB_B2__PAPRD_MEM__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define PAPRD_MEM_TAB_B2__TYPE                                         uint32_t
#define PAPRD_MEM_TAB_B2__READ                                      0x003fffffU
#define PAPRD_MEM_TAB_B2__WRITE                                     0x003fffffU

#endif /* __PAPRD_MEM_TAB_B2_MACRO__ */


/* macros for BB_paprd_mem_tab_b2 */
#define INST_BB_PAPRD_MEM_TAB_B2__NUM                                      1344

/* macros for BlueprintGlobalNameSpace::normtx_txiq_corr_coeff_b2 */
#ifndef __NORMTX_TXIQ_CORR_COEFF_B2_MACRO__
#define __NORMTX_TXIQ_CORR_COEFF_B2_MACRO__

/* macros for field normtx_iqc_coeff_table_chn2 */
#define NORMTX_TXIQ_CORR_COEFF_B2__NORMTX_IQC_COEFF_TABLE_CHN2__SHIFT         0
#define NORMTX_TXIQ_CORR_COEFF_B2__NORMTX_IQC_COEFF_TABLE_CHN2__WIDTH        18
#define NORMTX_TXIQ_CORR_COEFF_B2__NORMTX_IQC_COEFF_TABLE_CHN2__MASK \
                    0x0003ffffU
#define NORMTX_TXIQ_CORR_COEFF_B2__NORMTX_IQC_COEFF_TABLE_CHN2__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define NORMTX_TXIQ_CORR_COEFF_B2__NORMTX_IQC_COEFF_TABLE_CHN2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define NORMTX_TXIQ_CORR_COEFF_B2__NORMTX_IQC_COEFF_TABLE_CHN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define NORMTX_TXIQ_CORR_COEFF_B2__NORMTX_IQC_COEFF_TABLE_CHN2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define NORMTX_TXIQ_CORR_COEFF_B2__TYPE                                uint32_t
#define NORMTX_TXIQ_CORR_COEFF_B2__READ                             0x0003ffffU
#define NORMTX_TXIQ_CORR_COEFF_B2__WRITE                            0x0003ffffU

#endif /* __NORMTX_TXIQ_CORR_COEFF_B2_MACRO__ */


/* macros for BB_normtx_txiq_corr_coeff_b2 */
#define INST_BB_NORMTX_TXIQ_CORR_COEFF_B2__NUM                              160

/* macros for BlueprintGlobalNameSpace::chn2_tables_dummy_1 */
#ifndef __CHN2_TABLES_DUMMY_1_MACRO__
#define __CHN2_TABLES_DUMMY_1_MACRO__

/* macros for field dummy1 */
#define CHN2_TABLES_DUMMY_1__DUMMY1__SHIFT                                    0
#define CHN2_TABLES_DUMMY_1__DUMMY1__WIDTH                                   32
#define CHN2_TABLES_DUMMY_1__DUMMY1__MASK                           0xffffffffU
#define CHN2_TABLES_DUMMY_1__DUMMY1__READ(src)    (uint32_t)(src) & 0xffffffffU
#define CHN2_TABLES_DUMMY_1__DUMMY1__WRITE(src) ((uint32_t)(src) & 0xffffffffU)
#define CHN2_TABLES_DUMMY_1__DUMMY1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define CHN2_TABLES_DUMMY_1__DUMMY1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define CHN2_TABLES_DUMMY_1__TYPE                                      uint32_t
#define CHN2_TABLES_DUMMY_1__READ                                   0xffffffffU
#define CHN2_TABLES_DUMMY_1__WRITE                                  0xffffffffU

#endif /* __CHN2_TABLES_DUMMY_1_MACRO__ */


/* macros for BB_chn2_tables_dummy_1 */
#define INST_BB_CHN2_TABLES_DUMMY_1__NUM                                      1

#define CHN2_TABLE_MAP__VERSION \
                    "/cad/denali/blueprint/3.7.3/gen/ansic.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html2docbook.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html2sgml.pm\n\
                    /cad/local/lib/perl/Pinfo.pm\n\
                    /trees/cychao/cychao_peregrine_dev/ip/athr/wifi/dev/rtl/bb/blueprint/chn2_table_map.rdl"
#endif /* __REG_CHN2_TABLE_MAP_MACRO_H__ */
