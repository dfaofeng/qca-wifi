/*                                                                           */
/* File:       chn_table_map_macro.h                                         */
/* Creator:    yflee                                                         */
/* Time:       Thursday May 3, 2012 [6:53:57 pm]                             */
/*                                                                           */
/* Path:       /trees/yflee/yflee-dev/ip/athr/wifi/dev/rtl/bb/blueprint      */
/* Arguments:  /cad/denali/blueprint/3.7.3//Linux-64bit/blueprint -codegen   */
/*             verilogExtension.codegen -html -nojava -verilogExtension -vh  */
/*             -ansic chn_table_map.rdl                                      */
/*                                                                           */
/* Sources:    /trees/yflee/yflee-dev/ip/athr/wifi/dev/rtl/bb/blueprint/chn_table_map.rdl*/
/*             /cad/denali/blueprint/3.7.3/gen/ansic.pm                      */
/*             /cad/denali/blueprint/3.7.3/gen/html2docbook.pm               */
/*             /cad/denali/blueprint/3.7.3/gen/html2sgml.pm                  */
/*             /cad/denali/blueprint/3.7.3/gen/html.pm                       */
/*             /cad/local/lib/perl/Pinfo.pm                                  */
/*                                                                           */
/* Blueprint:   3.7.3 (Fri Aug 29 12:39:16 PDT 2008)                         */
/* Machine:    zydasc15                                                      */
/* OS:         Linux 2.6.9-78.0.8.ELsmp                                      */
/* Description:                                                              */
/*                                                                           */
/* No Description Provided                                                   */
/*                                                                           */
/*                                                                           */


#ifndef __REG_CHN_TABLE_MAP_MACRO_H__
#define __REG_CHN_TABLE_MAP_MACRO_H__


/* macros for BlueprintGlobalNameSpace::paprd_power_at_am2am_cal_b0 */
#ifndef __PAPRD_POWER_AT_AM2AM_CAL_B0_MACRO__
#define __PAPRD_POWER_AT_AM2AM_CAL_B0_MACRO__

/* macros for field paprd_power_at_am2am_cal_0_b0 */
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_0_B0__SHIFT     0
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_0_B0__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_0_B0__MASK \
                    0x0000003fU
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_0_B0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_0_B0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_0_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_0_B0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field paprd_power_at_am2am_cal_1_b0 */
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__SHIFT     6
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__MASK \
                    0x00000fc0U
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field paprd_power_at_am2am_cal_2_b0 */
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__SHIFT    12
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__MASK \
                    0x0003f000U
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field paprd_power_at_am2am_cal_3_b0 */
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__SHIFT    18
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__MASK \
                    0x00fc0000U
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00fc0000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x00fc0000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00fc0000U)))

/* macros for field paprd_power_at_am2am_cal_4_b0 */
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__SHIFT    24
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__MASK \
                    0x3f000000U
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define PAPRD_POWER_AT_AM2AM_CAL_B0__TYPE                              uint32_t
#define PAPRD_POWER_AT_AM2AM_CAL_B0__READ                           0x3fffffffU
#define PAPRD_POWER_AT_AM2AM_CAL_B0__WRITE                          0x3fffffffU

#endif /* __PAPRD_POWER_AT_AM2AM_CAL_B0_MACRO__ */


/* macros for BB_paprd_power_at_am2am_cal_b0 */
#define INST_BB_PAPRD_POWER_AT_AM2AM_CAL_B0__NUM                              1

/* macros for BlueprintGlobalNameSpace::paprd_valid_obdb_b0 */
#ifndef __PAPRD_VALID_OBDB_B0_MACRO__
#define __PAPRD_VALID_OBDB_B0_MACRO__

/* macros for field paprd_valid_obdb_0_b0 */
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__SHIFT                     0
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__WIDTH                     6
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__MASK            0x0000003fU
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field paprd_valid_obdb_1_b0 */
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__SHIFT                     6
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__WIDTH                     6
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__MASK            0x00000fc0U
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field paprd_valid_obdb_2_b0 */
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__SHIFT                    12
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__WIDTH                     6
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__MASK            0x0003f000U
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field paprd_valid_obdb_3_b0 */
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__SHIFT                    18
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__WIDTH                     6
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__MASK            0x00fc0000U
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00fc0000U)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x00fc0000U)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00fc0000U)))

/* macros for field paprd_valid_obdb_4_b0 */
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__SHIFT                    24
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__WIDTH                     6
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__MASK            0x3f000000U
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define PAPRD_VALID_OBDB_B0__TYPE                                      uint32_t
#define PAPRD_VALID_OBDB_B0__READ                                   0x3fffffffU
#define PAPRD_VALID_OBDB_B0__WRITE                                  0x3fffffffU

#endif /* __PAPRD_VALID_OBDB_B0_MACRO__ */


/* macros for BB_paprd_valid_obdb_b0 */
#define INST_BB_PAPRD_VALID_OBDB_B0__NUM                                      1

/* macros for BlueprintGlobalNameSpace::chn_tables_dummy_2 */
#ifndef __CHN_TABLES_DUMMY_2_MACRO__
#define __CHN_TABLES_DUMMY_2_MACRO__

/* macros for field dummy2 */
#define CHN_TABLES_DUMMY_2__DUMMY2__SHIFT                                     0
#define CHN_TABLES_DUMMY_2__DUMMY2__WIDTH                                    32
#define CHN_TABLES_DUMMY_2__DUMMY2__MASK                            0xffffffffU
#define CHN_TABLES_DUMMY_2__DUMMY2__READ(src)     (uint32_t)(src) & 0xffffffffU
#define CHN_TABLES_DUMMY_2__DUMMY2__WRITE(src)  ((uint32_t)(src) & 0xffffffffU)
#define CHN_TABLES_DUMMY_2__DUMMY2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define CHN_TABLES_DUMMY_2__DUMMY2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define CHN_TABLES_DUMMY_2__TYPE                                       uint32_t
#define CHN_TABLES_DUMMY_2__READ                                    0xffffffffU
#define CHN_TABLES_DUMMY_2__WRITE                                   0xffffffffU

#endif /* __CHN_TABLES_DUMMY_2_MACRO__ */


/* macros for BB_chn_tables_dummy_2 */
#define INST_BB_CHN_TABLES_DUMMY_2__NUM                                       1

/* macros for BlueprintGlobalNameSpace::txiqcorr_txpath_coef_b0 */
#ifndef __TXIQCORR_TXPATH_COEF_B0_MACRO__
#define __TXIQCORR_TXPATH_COEF_B0_MACRO__

/* macros for field txiqcorr_txpath_coef_chn0 */
#define TXIQCORR_TXPATH_COEF_B0__TXIQCORR_TXPATH_COEF_CHN0__SHIFT             0
#define TXIQCORR_TXPATH_COEF_B0__TXIQCORR_TXPATH_COEF_CHN0__WIDTH            18
#define TXIQCORR_TXPATH_COEF_B0__TXIQCORR_TXPATH_COEF_CHN0__MASK    0x0003ffffU
#define TXIQCORR_TXPATH_COEF_B0__TXIQCORR_TXPATH_COEF_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define TXIQCORR_TXPATH_COEF_B0__TXIQCORR_TXPATH_COEF_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define TXIQCORR_TXPATH_COEF_B0__TXIQCORR_TXPATH_COEF_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define TXIQCORR_TXPATH_COEF_B0__TXIQCORR_TXPATH_COEF_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define TXIQCORR_TXPATH_COEF_B0__TYPE                                  uint32_t
#define TXIQCORR_TXPATH_COEF_B0__READ                               0x0003ffffU
#define TXIQCORR_TXPATH_COEF_B0__WRITE                              0x0003ffffU

#endif /* __TXIQCORR_TXPATH_COEF_B0_MACRO__ */


/* macros for BB_txiqcorr_txpath_coef_b0 */
#define INST_BB_TXIQCORR_TXPATH_COEF_B0__NUM                                 16

/* macros for BlueprintGlobalNameSpace::txiqcorr_rxpath_coef_b0 */
#ifndef __TXIQCORR_RXPATH_COEF_B0_MACRO__
#define __TXIQCORR_RXPATH_COEF_B0_MACRO__

/* macros for field txiqcorr_rxpath_coef_chn0 */
#define TXIQCORR_RXPATH_COEF_B0__TXIQCORR_RXPATH_COEF_CHN0__SHIFT             0
#define TXIQCORR_RXPATH_COEF_B0__TXIQCORR_RXPATH_COEF_CHN0__WIDTH            18
#define TXIQCORR_RXPATH_COEF_B0__TXIQCORR_RXPATH_COEF_CHN0__MASK    0x0003ffffU
#define TXIQCORR_RXPATH_COEF_B0__TXIQCORR_RXPATH_COEF_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define TXIQCORR_RXPATH_COEF_B0__TXIQCORR_RXPATH_COEF_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define TXIQCORR_RXPATH_COEF_B0__TXIQCORR_RXPATH_COEF_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define TXIQCORR_RXPATH_COEF_B0__TXIQCORR_RXPATH_COEF_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define TXIQCORR_RXPATH_COEF_B0__TYPE                                  uint32_t
#define TXIQCORR_RXPATH_COEF_B0__READ                               0x0003ffffU
#define TXIQCORR_RXPATH_COEF_B0__WRITE                              0x0003ffffU

#endif /* __TXIQCORR_RXPATH_COEF_B0_MACRO__ */


/* macros for BB_txiqcorr_rxpath_coef_b0 */
#define INST_BB_TXIQCORR_RXPATH_COEF_B0__NUM                                 16

/* macros for BlueprintGlobalNameSpace::rxiqcorr_rxpath_coef_b0 */
#ifndef __RXIQCORR_RXPATH_COEF_B0_MACRO__
#define __RXIQCORR_RXPATH_COEF_B0_MACRO__

/* macros for field rxiqcorr_rxpath_coef_chn0 */
#define RXIQCORR_RXPATH_COEF_B0__RXIQCORR_RXPATH_COEF_CHN0__SHIFT             0
#define RXIQCORR_RXPATH_COEF_B0__RXIQCORR_RXPATH_COEF_CHN0__WIDTH            18
#define RXIQCORR_RXPATH_COEF_B0__RXIQCORR_RXPATH_COEF_CHN0__MASK    0x0003ffffU
#define RXIQCORR_RXPATH_COEF_B0__RXIQCORR_RXPATH_COEF_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define RXIQCORR_RXPATH_COEF_B0__RXIQCORR_RXPATH_COEF_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define RXIQCORR_RXPATH_COEF_B0__RXIQCORR_RXPATH_COEF_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define RXIQCORR_RXPATH_COEF_B0__RXIQCORR_RXPATH_COEF_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define RXIQCORR_RXPATH_COEF_B0__TYPE                                  uint32_t
#define RXIQCORR_RXPATH_COEF_B0__READ                               0x0003ffffU
#define RXIQCORR_RXPATH_COEF_B0__WRITE                              0x0003ffffU

#endif /* __RXIQCORR_RXPATH_COEF_B0_MACRO__ */


/* macros for BB_rxiqcorr_rxpath_coef_b0 */
#define INST_BB_RXIQCORR_RXPATH_COEF_B0__NUM                                 16

/* macros for BlueprintGlobalNameSpace::rxiqcorr_txpath_coef_b0 */
#ifndef __RXIQCORR_TXPATH_COEF_B0_MACRO__
#define __RXIQCORR_TXPATH_COEF_B0_MACRO__

/* macros for field rxiqcorr_txpath_coef_chn0 */
#define RXIQCORR_TXPATH_COEF_B0__RXIQCORR_TXPATH_COEF_CHN0__SHIFT             0
#define RXIQCORR_TXPATH_COEF_B0__RXIQCORR_TXPATH_COEF_CHN0__WIDTH            18
#define RXIQCORR_TXPATH_COEF_B0__RXIQCORR_TXPATH_COEF_CHN0__MASK    0x0003ffffU
#define RXIQCORR_TXPATH_COEF_B0__RXIQCORR_TXPATH_COEF_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define RXIQCORR_TXPATH_COEF_B0__RXIQCORR_TXPATH_COEF_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define RXIQCORR_TXPATH_COEF_B0__RXIQCORR_TXPATH_COEF_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define RXIQCORR_TXPATH_COEF_B0__RXIQCORR_TXPATH_COEF_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define RXIQCORR_TXPATH_COEF_B0__TYPE                                  uint32_t
#define RXIQCORR_TXPATH_COEF_B0__READ                               0x0003ffffU
#define RXIQCORR_TXPATH_COEF_B0__WRITE                              0x0003ffffU

#endif /* __RXIQCORR_TXPATH_COEF_B0_MACRO__ */


/* macros for BB_rxiqcorr_txpath_coef_b0 */
#define INST_BB_RXIQCORR_TXPATH_COEF_B0__NUM                                 16

/* macros for BlueprintGlobalNameSpace::rxcal_tx_gain_table_b0 */
#ifndef __RXCAL_TX_GAIN_TABLE_B0_MACRO__
#define __RXCAL_TX_GAIN_TABLE_B0_MACRO__

/* macros for field rxcal_tx_gain_table_chn0 */
#define RXCAL_TX_GAIN_TABLE_B0__RXCAL_TX_GAIN_TABLE_CHN0__SHIFT               0
#define RXCAL_TX_GAIN_TABLE_B0__RXCAL_TX_GAIN_TABLE_CHN0__WIDTH              20
#define RXCAL_TX_GAIN_TABLE_B0__RXCAL_TX_GAIN_TABLE_CHN0__MASK      0x000fffffU
#define RXCAL_TX_GAIN_TABLE_B0__RXCAL_TX_GAIN_TABLE_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000fffffU
#define RXCAL_TX_GAIN_TABLE_B0__RXCAL_TX_GAIN_TABLE_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000fffffU)
#define RXCAL_TX_GAIN_TABLE_B0__RXCAL_TX_GAIN_TABLE_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000fffffU) | ((uint32_t)(src) &\
                    0x000fffffU)
#define RXCAL_TX_GAIN_TABLE_B0__RXCAL_TX_GAIN_TABLE_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000fffffU)))
#define RXCAL_TX_GAIN_TABLE_B0__TYPE                                   uint32_t
#define RXCAL_TX_GAIN_TABLE_B0__READ                                0x000fffffU
#define RXCAL_TX_GAIN_TABLE_B0__WRITE                               0x000fffffU

#endif /* __RXCAL_TX_GAIN_TABLE_B0_MACRO__ */


/* macros for BB_rxcal_tx_gain_table_b0 */
#define INST_BB_RXCAL_TX_GAIN_TABLE_B0__NUM                                  32

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_1_0_b0 */
#ifndef __RXCAL_RX_GAIN_TABLE_1_0_B0_MACRO__
#define __RXCAL_RX_GAIN_TABLE_1_0_B0_MACRO__

/* macros for field rxcal_rx_gain_table_0_chn0 */
#define RXCAL_RX_GAIN_TABLE_1_0_B0__RXCAL_RX_GAIN_TABLE_0_CHN0__SHIFT         0
#define RXCAL_RX_GAIN_TABLE_1_0_B0__RXCAL_RX_GAIN_TABLE_0_CHN0__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_1_0_B0__RXCAL_RX_GAIN_TABLE_0_CHN0__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_1_0_B0__RXCAL_RX_GAIN_TABLE_0_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_1_0_B0__RXCAL_RX_GAIN_TABLE_0_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_1_0_B0__RXCAL_RX_GAIN_TABLE_0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_1_0_B0__RXCAL_RX_GAIN_TABLE_0_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_1_chn0 */
#define RXCAL_RX_GAIN_TABLE_1_0_B0__RXCAL_RX_GAIN_TABLE_1_CHN0__SHIFT        16
#define RXCAL_RX_GAIN_TABLE_1_0_B0__RXCAL_RX_GAIN_TABLE_1_CHN0__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_1_0_B0__RXCAL_RX_GAIN_TABLE_1_CHN0__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_1_0_B0__RXCAL_RX_GAIN_TABLE_1_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_1_0_B0__RXCAL_RX_GAIN_TABLE_1_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_1_0_B0__RXCAL_RX_GAIN_TABLE_1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_1_0_B0__RXCAL_RX_GAIN_TABLE_1_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_1_0_B0__TYPE                               uint32_t
#define RXCAL_RX_GAIN_TABLE_1_0_B0__READ                            0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_1_0_B0__WRITE                           0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_1_0_B0_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_1_0_b0 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_1_0_B0__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_3_2_b0 */
#ifndef __RXCAL_RX_GAIN_TABLE_3_2_B0_MACRO__
#define __RXCAL_RX_GAIN_TABLE_3_2_B0_MACRO__

/* macros for field rxcal_rx_gain_table_2_chn0 */
#define RXCAL_RX_GAIN_TABLE_3_2_B0__RXCAL_RX_GAIN_TABLE_2_CHN0__SHIFT         0
#define RXCAL_RX_GAIN_TABLE_3_2_B0__RXCAL_RX_GAIN_TABLE_2_CHN0__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_3_2_B0__RXCAL_RX_GAIN_TABLE_2_CHN0__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_3_2_B0__RXCAL_RX_GAIN_TABLE_2_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_3_2_B0__RXCAL_RX_GAIN_TABLE_2_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_3_2_B0__RXCAL_RX_GAIN_TABLE_2_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_3_2_B0__RXCAL_RX_GAIN_TABLE_2_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_3_chn0 */
#define RXCAL_RX_GAIN_TABLE_3_2_B0__RXCAL_RX_GAIN_TABLE_3_CHN0__SHIFT        16
#define RXCAL_RX_GAIN_TABLE_3_2_B0__RXCAL_RX_GAIN_TABLE_3_CHN0__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_3_2_B0__RXCAL_RX_GAIN_TABLE_3_CHN0__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_3_2_B0__RXCAL_RX_GAIN_TABLE_3_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_3_2_B0__RXCAL_RX_GAIN_TABLE_3_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_3_2_B0__RXCAL_RX_GAIN_TABLE_3_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_3_2_B0__RXCAL_RX_GAIN_TABLE_3_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_3_2_B0__TYPE                               uint32_t
#define RXCAL_RX_GAIN_TABLE_3_2_B0__READ                            0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_3_2_B0__WRITE                           0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_3_2_B0_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_3_2_b0 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_3_2_B0__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_5_4_b0 */
#ifndef __RXCAL_RX_GAIN_TABLE_5_4_B0_MACRO__
#define __RXCAL_RX_GAIN_TABLE_5_4_B0_MACRO__

/* macros for field rxcal_rx_gain_table_4_chn0 */
#define RXCAL_RX_GAIN_TABLE_5_4_B0__RXCAL_RX_GAIN_TABLE_4_CHN0__SHIFT         0
#define RXCAL_RX_GAIN_TABLE_5_4_B0__RXCAL_RX_GAIN_TABLE_4_CHN0__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_5_4_B0__RXCAL_RX_GAIN_TABLE_4_CHN0__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_5_4_B0__RXCAL_RX_GAIN_TABLE_4_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_5_4_B0__RXCAL_RX_GAIN_TABLE_4_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_5_4_B0__RXCAL_RX_GAIN_TABLE_4_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_5_4_B0__RXCAL_RX_GAIN_TABLE_4_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_5_chn0 */
#define RXCAL_RX_GAIN_TABLE_5_4_B0__RXCAL_RX_GAIN_TABLE_5_CHN0__SHIFT        16
#define RXCAL_RX_GAIN_TABLE_5_4_B0__RXCAL_RX_GAIN_TABLE_5_CHN0__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_5_4_B0__RXCAL_RX_GAIN_TABLE_5_CHN0__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_5_4_B0__RXCAL_RX_GAIN_TABLE_5_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_5_4_B0__RXCAL_RX_GAIN_TABLE_5_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_5_4_B0__RXCAL_RX_GAIN_TABLE_5_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_5_4_B0__RXCAL_RX_GAIN_TABLE_5_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_5_4_B0__TYPE                               uint32_t
#define RXCAL_RX_GAIN_TABLE_5_4_B0__READ                            0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_5_4_B0__WRITE                           0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_5_4_B0_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_5_4_b0 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_5_4_B0__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_7_6_b0 */
#ifndef __RXCAL_RX_GAIN_TABLE_7_6_B0_MACRO__
#define __RXCAL_RX_GAIN_TABLE_7_6_B0_MACRO__

/* macros for field rxcal_rx_gain_table_6_chn0 */
#define RXCAL_RX_GAIN_TABLE_7_6_B0__RXCAL_RX_GAIN_TABLE_6_CHN0__SHIFT         0
#define RXCAL_RX_GAIN_TABLE_7_6_B0__RXCAL_RX_GAIN_TABLE_6_CHN0__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_7_6_B0__RXCAL_RX_GAIN_TABLE_6_CHN0__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_7_6_B0__RXCAL_RX_GAIN_TABLE_6_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_7_6_B0__RXCAL_RX_GAIN_TABLE_6_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_7_6_B0__RXCAL_RX_GAIN_TABLE_6_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_7_6_B0__RXCAL_RX_GAIN_TABLE_6_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_7_chn0 */
#define RXCAL_RX_GAIN_TABLE_7_6_B0__RXCAL_RX_GAIN_TABLE_7_CHN0__SHIFT        16
#define RXCAL_RX_GAIN_TABLE_7_6_B0__RXCAL_RX_GAIN_TABLE_7_CHN0__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_7_6_B0__RXCAL_RX_GAIN_TABLE_7_CHN0__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_7_6_B0__RXCAL_RX_GAIN_TABLE_7_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_7_6_B0__RXCAL_RX_GAIN_TABLE_7_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_7_6_B0__RXCAL_RX_GAIN_TABLE_7_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_7_6_B0__RXCAL_RX_GAIN_TABLE_7_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_7_6_B0__TYPE                               uint32_t
#define RXCAL_RX_GAIN_TABLE_7_6_B0__READ                            0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_7_6_B0__WRITE                           0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_7_6_B0_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_7_6_b0 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_7_6_B0__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_9_8_b0 */
#ifndef __RXCAL_RX_GAIN_TABLE_9_8_B0_MACRO__
#define __RXCAL_RX_GAIN_TABLE_9_8_B0_MACRO__

/* macros for field rxcal_rx_gain_table_8_chn0 */
#define RXCAL_RX_GAIN_TABLE_9_8_B0__RXCAL_RX_GAIN_TABLE_8_CHN0__SHIFT         0
#define RXCAL_RX_GAIN_TABLE_9_8_B0__RXCAL_RX_GAIN_TABLE_8_CHN0__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_9_8_B0__RXCAL_RX_GAIN_TABLE_8_CHN0__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_9_8_B0__RXCAL_RX_GAIN_TABLE_8_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_9_8_B0__RXCAL_RX_GAIN_TABLE_8_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_9_8_B0__RXCAL_RX_GAIN_TABLE_8_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_9_8_B0__RXCAL_RX_GAIN_TABLE_8_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_9_chn0 */
#define RXCAL_RX_GAIN_TABLE_9_8_B0__RXCAL_RX_GAIN_TABLE_9_CHN0__SHIFT        16
#define RXCAL_RX_GAIN_TABLE_9_8_B0__RXCAL_RX_GAIN_TABLE_9_CHN0__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_9_8_B0__RXCAL_RX_GAIN_TABLE_9_CHN0__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_9_8_B0__RXCAL_RX_GAIN_TABLE_9_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_9_8_B0__RXCAL_RX_GAIN_TABLE_9_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_9_8_B0__RXCAL_RX_GAIN_TABLE_9_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_9_8_B0__RXCAL_RX_GAIN_TABLE_9_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_9_8_B0__TYPE                               uint32_t
#define RXCAL_RX_GAIN_TABLE_9_8_B0__READ                            0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_9_8_B0__WRITE                           0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_9_8_B0_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_9_8_b0 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_9_8_B0__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_11_10_b0 */
#ifndef __RXCAL_RX_GAIN_TABLE_11_10_B0_MACRO__
#define __RXCAL_RX_GAIN_TABLE_11_10_B0_MACRO__

/* macros for field rxcal_rx_gain_table_10_chn0 */
#define RXCAL_RX_GAIN_TABLE_11_10_B0__RXCAL_RX_GAIN_TABLE_10_CHN0__SHIFT      0
#define RXCAL_RX_GAIN_TABLE_11_10_B0__RXCAL_RX_GAIN_TABLE_10_CHN0__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_11_10_B0__RXCAL_RX_GAIN_TABLE_10_CHN0__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_11_10_B0__RXCAL_RX_GAIN_TABLE_10_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_11_10_B0__RXCAL_RX_GAIN_TABLE_10_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_11_10_B0__RXCAL_RX_GAIN_TABLE_10_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_11_10_B0__RXCAL_RX_GAIN_TABLE_10_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_11_chn0 */
#define RXCAL_RX_GAIN_TABLE_11_10_B0__RXCAL_RX_GAIN_TABLE_11_CHN0__SHIFT     16
#define RXCAL_RX_GAIN_TABLE_11_10_B0__RXCAL_RX_GAIN_TABLE_11_CHN0__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_11_10_B0__RXCAL_RX_GAIN_TABLE_11_CHN0__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_11_10_B0__RXCAL_RX_GAIN_TABLE_11_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_11_10_B0__RXCAL_RX_GAIN_TABLE_11_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_11_10_B0__RXCAL_RX_GAIN_TABLE_11_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_11_10_B0__RXCAL_RX_GAIN_TABLE_11_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_11_10_B0__TYPE                             uint32_t
#define RXCAL_RX_GAIN_TABLE_11_10_B0__READ                          0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_11_10_B0__WRITE                         0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_11_10_B0_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_11_10_b0 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_11_10_B0__NUM                             1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_13_12_b0 */
#ifndef __RXCAL_RX_GAIN_TABLE_13_12_B0_MACRO__
#define __RXCAL_RX_GAIN_TABLE_13_12_B0_MACRO__

/* macros for field rxcal_rx_gain_table_12_chn0 */
#define RXCAL_RX_GAIN_TABLE_13_12_B0__RXCAL_RX_GAIN_TABLE_12_CHN0__SHIFT      0
#define RXCAL_RX_GAIN_TABLE_13_12_B0__RXCAL_RX_GAIN_TABLE_12_CHN0__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_13_12_B0__RXCAL_RX_GAIN_TABLE_12_CHN0__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_13_12_B0__RXCAL_RX_GAIN_TABLE_12_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_13_12_B0__RXCAL_RX_GAIN_TABLE_12_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_13_12_B0__RXCAL_RX_GAIN_TABLE_12_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_13_12_B0__RXCAL_RX_GAIN_TABLE_12_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_13_chn0 */
#define RXCAL_RX_GAIN_TABLE_13_12_B0__RXCAL_RX_GAIN_TABLE_13_CHN0__SHIFT     16
#define RXCAL_RX_GAIN_TABLE_13_12_B0__RXCAL_RX_GAIN_TABLE_13_CHN0__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_13_12_B0__RXCAL_RX_GAIN_TABLE_13_CHN0__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_13_12_B0__RXCAL_RX_GAIN_TABLE_13_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_13_12_B0__RXCAL_RX_GAIN_TABLE_13_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_13_12_B0__RXCAL_RX_GAIN_TABLE_13_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_13_12_B0__RXCAL_RX_GAIN_TABLE_13_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_13_12_B0__TYPE                             uint32_t
#define RXCAL_RX_GAIN_TABLE_13_12_B0__READ                          0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_13_12_B0__WRITE                         0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_13_12_B0_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_13_12_b0 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_13_12_B0__NUM                             1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_15_14_b0 */
#ifndef __RXCAL_RX_GAIN_TABLE_15_14_B0_MACRO__
#define __RXCAL_RX_GAIN_TABLE_15_14_B0_MACRO__

/* macros for field rxcal_rx_gain_table_14_chn0 */
#define RXCAL_RX_GAIN_TABLE_15_14_B0__RXCAL_RX_GAIN_TABLE_14_CHN0__SHIFT      0
#define RXCAL_RX_GAIN_TABLE_15_14_B0__RXCAL_RX_GAIN_TABLE_14_CHN0__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_15_14_B0__RXCAL_RX_GAIN_TABLE_14_CHN0__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_15_14_B0__RXCAL_RX_GAIN_TABLE_14_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_15_14_B0__RXCAL_RX_GAIN_TABLE_14_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_15_14_B0__RXCAL_RX_GAIN_TABLE_14_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_15_14_B0__RXCAL_RX_GAIN_TABLE_14_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_15_chn0 */
#define RXCAL_RX_GAIN_TABLE_15_14_B0__RXCAL_RX_GAIN_TABLE_15_CHN0__SHIFT     16
#define RXCAL_RX_GAIN_TABLE_15_14_B0__RXCAL_RX_GAIN_TABLE_15_CHN0__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_15_14_B0__RXCAL_RX_GAIN_TABLE_15_CHN0__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_15_14_B0__RXCAL_RX_GAIN_TABLE_15_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_15_14_B0__RXCAL_RX_GAIN_TABLE_15_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_15_14_B0__RXCAL_RX_GAIN_TABLE_15_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_15_14_B0__RXCAL_RX_GAIN_TABLE_15_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_15_14_B0__TYPE                             uint32_t
#define RXCAL_RX_GAIN_TABLE_15_14_B0__READ                          0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_15_14_B0__WRITE                         0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_15_14_B0_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_15_14_b0 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_15_14_B0__NUM                             1

/* macros for BlueprintGlobalNameSpace::rxcal_gain_delta_db_table_3_0_b0 */
#ifndef __RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0_MACRO__
#define __RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0_MACRO__

/* macros for field rxcal_gain_delta_db_table_0_chn0 */
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN0__SHIFT \
                    0
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN0__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN0__MASK \
                    0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field rxcal_gain_delta_db_table_1_chn0 */
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN0__SHIFT \
                    8
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN0__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN0__MASK \
                    0x00003f00U
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))

/* macros for field rxcal_gain_delta_db_table_2_chn0 */
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN0__SHIFT \
                    16
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN0__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN0__MASK \
                    0x003f0000U
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))

/* macros for field rxcal_gain_delta_db_table_3_chn0 */
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN0__SHIFT \
                    24
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN0__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN0__MASK \
                    0x3f000000U
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__TYPE                         uint32_t
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__READ                      0x3f3f3f3fU
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__WRITE                     0x3f3f3f3fU

#endif /* __RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0_MACRO__ */


/* macros for BB_rxcal_gain_delta_db_table_3_0_b0 */
#define INST_BB_RXCAL_GAIN_DELTA_DB_TABLE_3_0_B0__NUM                         1

/* macros for BlueprintGlobalNameSpace::rxcal_gain_delta_db_table_7_4_b0 */
#ifndef __RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0_MACRO__
#define __RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0_MACRO__

/* macros for field rxcal_gain_delta_db_table_4_chn0 */
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN0__SHIFT \
                    0
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN0__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN0__MASK \
                    0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field rxcal_gain_delta_db_table_5_chn0 */
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN0__SHIFT \
                    8
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN0__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN0__MASK \
                    0x00003f00U
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))

/* macros for field rxcal_gain_delta_db_table_6_chn0 */
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN0__SHIFT \
                    16
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN0__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN0__MASK \
                    0x003f0000U
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))

/* macros for field rxcal_gain_delta_db_table_7_chn0 */
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN0__SHIFT \
                    24
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN0__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN0__MASK \
                    0x3f000000U
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__TYPE                         uint32_t
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__READ                      0x3f3f3f3fU
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__WRITE                     0x3f3f3f3fU

#endif /* __RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0_MACRO__ */


/* macros for BB_rxcal_gain_delta_db_table_7_4_b0 */
#define INST_BB_RXCAL_GAIN_DELTA_DB_TABLE_7_4_B0__NUM                         1

/* macros for BlueprintGlobalNameSpace::rxcal_gain_delta_db_table_11_8_b0 */
#ifndef __RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0_MACRO__
#define __RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0_MACRO__

/* macros for field rxcal_gain_delta_db_table_8_chn0 */
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN0__SHIFT \
                    0
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN0__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN0__MASK \
                    0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field rxcal_gain_delta_db_table_9_chn0 */
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN0__SHIFT \
                    8
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN0__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN0__MASK \
                    0x00003f00U
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))

/* macros for field rxcal_gain_delta_db_table_10_chn0 */
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN0__SHIFT \
                    16
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN0__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN0__MASK \
                    0x003f0000U
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))

/* macros for field rxcal_gain_delta_db_table_11_chn0 */
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN0__SHIFT \
                    24
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN0__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN0__MASK \
                    0x3f000000U
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__TYPE                        uint32_t
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__READ                     0x3f3f3f3fU
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__WRITE                    0x3f3f3f3fU

#endif /* __RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0_MACRO__ */


/* macros for BB_rxcal_gain_delta_db_table_11_8_b0 */
#define INST_BB_RXCAL_GAIN_DELTA_DB_TABLE_11_8_B0__NUM                        1

/* macros for BlueprintGlobalNameSpace::rxcal_gain_delta_db_table_15_12_b0 */
#ifndef __RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0_MACRO__
#define __RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0_MACRO__

/* macros for field rxcal_gain_delta_db_table_12_chn0 */
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN0__SHIFT \
                    0
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN0__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN0__MASK \
                    0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field rxcal_gain_delta_db_table_13_chn0 */
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN0__SHIFT \
                    8
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN0__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN0__MASK \
                    0x00003f00U
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))

/* macros for field rxcal_gain_delta_db_table_14_chn0 */
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN0__SHIFT \
                    16
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN0__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN0__MASK \
                    0x003f0000U
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))

/* macros for field rxcal_gain_delta_db_table_15_chn0 */
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN0__SHIFT \
                    24
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN0__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN0__MASK \
                    0x3f000000U
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__TYPE                       uint32_t
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__READ                    0x3f3f3f3fU
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__WRITE                   0x3f3f3f3fU

#endif /* __RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0_MACRO__ */


/* macros for BB_rxcal_gain_delta_db_table_15_12_b0 */
#define INST_BB_RXCAL_GAIN_DELTA_DB_TABLE_15_12_B0__NUM                       1

/* macros for BlueprintGlobalNameSpace::rxcal_tx_iqcorr_idx_7_0_b0 */
#ifndef __RXCAL_TX_IQCORR_IDX_7_0_B0_MACRO__
#define __RXCAL_TX_IQCORR_IDX_7_0_B0_MACRO__

/* macros for field rxcal_tx_iqcorr_idx_0_chn0 */
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_0_CHN0__SHIFT         0
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_0_CHN0__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_0_CHN0__MASK \
                    0x0000000fU
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_0_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_0_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_0_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_0_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field rxcal_tx_iqcorr_idx_1_chn0 */
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_1_CHN0__SHIFT         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_1_CHN0__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_1_CHN0__MASK \
                    0x000000f0U
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_1_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_1_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_1_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_1_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field rxcal_tx_iqcorr_idx_2_chn0 */
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_2_CHN0__SHIFT         8
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_2_CHN0__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_2_CHN0__MASK \
                    0x00000f00U
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_2_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_2_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_2_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_2_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field rxcal_tx_iqcorr_idx_3_chn0 */
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_3_CHN0__SHIFT        12
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_3_CHN0__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_3_CHN0__MASK \
                    0x0000f000U
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_3_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_3_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_3_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_3_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field rxcal_tx_iqcorr_idx_4_chn0 */
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_4_CHN0__SHIFT        16
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_4_CHN0__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_4_CHN0__MASK \
                    0x000f0000U
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_4_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_4_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_4_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_4_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field rxcal_tx_iqcorr_idx_5_chn0 */
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_5_CHN0__SHIFT        20
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_5_CHN0__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_5_CHN0__MASK \
                    0x00f00000U
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_5_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_5_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_5_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_5_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field rxcal_tx_iqcorr_idx_6_chn0 */
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_6_CHN0__SHIFT        24
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_6_CHN0__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_6_CHN0__MASK \
                    0x0f000000U
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_6_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_6_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_6_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_6_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field rxcal_tx_iqcorr_idx_7_chn0 */
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_7_CHN0__SHIFT        28
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_7_CHN0__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_7_CHN0__MASK \
                    0xf0000000U
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_7_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_7_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_7_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B0__RXCAL_TX_IQCORR_IDX_7_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RXCAL_TX_IQCORR_IDX_7_0_B0__TYPE                               uint32_t
#define RXCAL_TX_IQCORR_IDX_7_0_B0__READ                            0xffffffffU
#define RXCAL_TX_IQCORR_IDX_7_0_B0__WRITE                           0xffffffffU

#endif /* __RXCAL_TX_IQCORR_IDX_7_0_B0_MACRO__ */


/* macros for BB_rxcal_tx_iqcorr_idx_7_0_b0 */
#define INST_BB_RXCAL_TX_IQCORR_IDX_7_0_B0__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_tx_iqcorr_idx_15_8_b0 */
#ifndef __RXCAL_TX_IQCORR_IDX_15_8_B0_MACRO__
#define __RXCAL_TX_IQCORR_IDX_15_8_B0_MACRO__

/* macros for field rxcal_tx_iqcorr_idx_8_chn0 */
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_8_CHN0__SHIFT        0
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_8_CHN0__WIDTH        4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_8_CHN0__MASK \
                    0x0000000fU
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_8_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_8_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_8_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_8_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field rxcal_tx_iqcorr_idx_9_chn0 */
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_9_CHN0__SHIFT        4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_9_CHN0__WIDTH        4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_9_CHN0__MASK \
                    0x000000f0U
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_9_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_9_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_9_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_9_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field rxcal_tx_iqcorr_idx_10_chn0 */
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_10_CHN0__SHIFT       8
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_10_CHN0__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_10_CHN0__MASK \
                    0x00000f00U
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_10_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_10_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_10_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_10_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field rxcal_tx_iqcorr_idx_11_chn0 */
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_11_CHN0__SHIFT      12
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_11_CHN0__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_11_CHN0__MASK \
                    0x0000f000U
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_11_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_11_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_11_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_11_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field rxcal_tx_iqcorr_idx_12_chn0 */
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_12_CHN0__SHIFT      16
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_12_CHN0__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_12_CHN0__MASK \
                    0x000f0000U
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_12_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_12_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_12_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_12_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field rxcal_tx_iqcorr_idx_13_chn0 */
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_13_CHN0__SHIFT      20
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_13_CHN0__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_13_CHN0__MASK \
                    0x00f00000U
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_13_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_13_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_13_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_13_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field rxcal_tx_iqcorr_idx_14_chn0 */
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_14_CHN0__SHIFT      24
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_14_CHN0__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_14_CHN0__MASK \
                    0x0f000000U
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_14_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_14_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_14_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_14_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field rxcal_tx_iqcorr_idx_15_chn0 */
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_15_CHN0__SHIFT      28
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_15_CHN0__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_15_CHN0__MASK \
                    0xf0000000U
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_15_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_15_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_15_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B0__RXCAL_TX_IQCORR_IDX_15_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RXCAL_TX_IQCORR_IDX_15_8_B0__TYPE                              uint32_t
#define RXCAL_TX_IQCORR_IDX_15_8_B0__READ                           0xffffffffU
#define RXCAL_TX_IQCORR_IDX_15_8_B0__WRITE                          0xffffffffU

#endif /* __RXCAL_TX_IQCORR_IDX_15_8_B0_MACRO__ */


/* macros for BB_rxcal_tx_iqcorr_idx_15_8_b0 */
#define INST_BB_RXCAL_TX_IQCORR_IDX_15_8_B0__NUM                              1

/* macros for BlueprintGlobalNameSpace::rxcal_tx_iqcorr_idx_23_16_b0 */
#ifndef __RXCAL_TX_IQCORR_IDX_23_16_B0_MACRO__
#define __RXCAL_TX_IQCORR_IDX_23_16_B0_MACRO__

/* macros for field rxcal_tx_iqcorr_idx_16_chn0 */
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_16_CHN0__SHIFT      0
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_16_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_16_CHN0__MASK \
                    0x0000000fU
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_16_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_16_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_16_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_16_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field rxcal_tx_iqcorr_idx_17_chn0 */
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_17_CHN0__SHIFT      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_17_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_17_CHN0__MASK \
                    0x000000f0U
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_17_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_17_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_17_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_17_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field rxcal_tx_iqcorr_idx_18_chn0 */
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_18_CHN0__SHIFT      8
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_18_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_18_CHN0__MASK \
                    0x00000f00U
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_18_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_18_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_18_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_18_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field rxcal_tx_iqcorr_idx_19_chn0 */
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_19_CHN0__SHIFT     12
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_19_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_19_CHN0__MASK \
                    0x0000f000U
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_19_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_19_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_19_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_19_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field rxcal_tx_iqcorr_idx_20_chn0 */
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_20_CHN0__SHIFT     16
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_20_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_20_CHN0__MASK \
                    0x000f0000U
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_20_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_20_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_20_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_20_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field rxcal_tx_iqcorr_idx_21_chn0 */
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_21_CHN0__SHIFT     20
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_21_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_21_CHN0__MASK \
                    0x00f00000U
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_21_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_21_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_21_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_21_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field rxcal_tx_iqcorr_idx_22_chn0 */
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_22_CHN0__SHIFT     24
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_22_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_22_CHN0__MASK \
                    0x0f000000U
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_22_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_22_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_22_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_22_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field rxcal_tx_iqcorr_idx_23_chn0 */
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_23_CHN0__SHIFT     28
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_23_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_23_CHN0__MASK \
                    0xf0000000U
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_23_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_23_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_23_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B0__RXCAL_TX_IQCORR_IDX_23_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RXCAL_TX_IQCORR_IDX_23_16_B0__TYPE                             uint32_t
#define RXCAL_TX_IQCORR_IDX_23_16_B0__READ                          0xffffffffU
#define RXCAL_TX_IQCORR_IDX_23_16_B0__WRITE                         0xffffffffU

#endif /* __RXCAL_TX_IQCORR_IDX_23_16_B0_MACRO__ */


/* macros for BB_rxcal_tx_iqcorr_idx_23_16_b0 */
#define INST_BB_RXCAL_TX_IQCORR_IDX_23_16_B0__NUM                             1

/* macros for BlueprintGlobalNameSpace::rxcal_tx_iqcorr_idx_31_24_b0 */
#ifndef __RXCAL_TX_IQCORR_IDX_31_24_B0_MACRO__
#define __RXCAL_TX_IQCORR_IDX_31_24_B0_MACRO__

/* macros for field rxcal_tx_iqcorr_idx_24_chn0 */
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_24_CHN0__SHIFT      0
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_24_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_24_CHN0__MASK \
                    0x0000000fU
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_24_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_24_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_24_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_24_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field rxcal_tx_iqcorr_idx_25_chn0 */
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_25_CHN0__SHIFT      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_25_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_25_CHN0__MASK \
                    0x000000f0U
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_25_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_25_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_25_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_25_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field rxcal_tx_iqcorr_idx_26_chn0 */
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_26_CHN0__SHIFT      8
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_26_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_26_CHN0__MASK \
                    0x00000f00U
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_26_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_26_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_26_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_26_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field rxcal_tx_iqcorr_idx_27_chn0 */
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_27_CHN0__SHIFT     12
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_27_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_27_CHN0__MASK \
                    0x0000f000U
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_27_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_27_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_27_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_27_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field rxcal_tx_iqcorr_idx_28_chn0 */
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_28_CHN0__SHIFT     16
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_28_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_28_CHN0__MASK \
                    0x000f0000U
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_28_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_28_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_28_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_28_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field rxcal_tx_iqcorr_idx_29_chn0 */
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_29_CHN0__SHIFT     20
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_29_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_29_CHN0__MASK \
                    0x00f00000U
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_29_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_29_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_29_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_29_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field rxcal_tx_iqcorr_idx_30_chn0 */
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_30_CHN0__SHIFT     24
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_30_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_30_CHN0__MASK \
                    0x0f000000U
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_30_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_30_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_30_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_30_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field rxcal_tx_iqcorr_idx_31_chn0 */
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_31_CHN0__SHIFT     28
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_31_CHN0__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_31_CHN0__MASK \
                    0xf0000000U
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_31_CHN0__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_31_CHN0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_31_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B0__RXCAL_TX_IQCORR_IDX_31_CHN0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RXCAL_TX_IQCORR_IDX_31_24_B0__TYPE                             uint32_t
#define RXCAL_TX_IQCORR_IDX_31_24_B0__READ                          0xffffffffU
#define RXCAL_TX_IQCORR_IDX_31_24_B0__WRITE                         0xffffffffU

#endif /* __RXCAL_TX_IQCORR_IDX_31_24_B0_MACRO__ */


/* macros for BB_rxcal_tx_iqcorr_idx_31_24_b0 */
#define INST_BB_RXCAL_TX_IQCORR_IDX_31_24_B0__NUM                             1

/* macros for BlueprintGlobalNameSpace::txcal_rx_iqcorr_idx_7_0 */
#ifndef __TXCAL_RX_IQCORR_IDX_7_0_MACRO__
#define __TXCAL_RX_IQCORR_IDX_7_0_MACRO__

/* macros for field txcal_rx_iqcorr_idx_0 */
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_0__SHIFT                 0
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_0__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_0__MASK        0x0000000fU
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field txcal_rx_iqcorr_idx_1 */
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_1__SHIFT                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_1__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_1__MASK        0x000000f0U
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field txcal_rx_iqcorr_idx_2 */
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_2__SHIFT                 8
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_2__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_2__MASK        0x00000f00U
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field txcal_rx_iqcorr_idx_3 */
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_3__SHIFT                12
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_3__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_3__MASK        0x0000f000U
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field txcal_rx_iqcorr_idx_4 */
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_4__SHIFT                16
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_4__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_4__MASK        0x000f0000U
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_4__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_4__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_4__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field txcal_rx_iqcorr_idx_5 */
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_5__SHIFT                20
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_5__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_5__MASK        0x00f00000U
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_5__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_5__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_5__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field txcal_rx_iqcorr_idx_6 */
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_6__SHIFT                24
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_6__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_6__MASK        0x0f000000U
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_6__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_6__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_6__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field txcal_rx_iqcorr_idx_7 */
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_7__SHIFT                28
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_7__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_7__MASK        0xf0000000U
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_7__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_7__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define TXCAL_RX_IQCORR_IDX_7_0__TXCAL_RX_IQCORR_IDX_7__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define TXCAL_RX_IQCORR_IDX_7_0__TYPE                                  uint32_t
#define TXCAL_RX_IQCORR_IDX_7_0__READ                               0xffffffffU
#define TXCAL_RX_IQCORR_IDX_7_0__WRITE                              0xffffffffU

#endif /* __TXCAL_RX_IQCORR_IDX_7_0_MACRO__ */


/* macros for BB_txcal_rx_iqcorr_idx_7_0 */
#define INST_BB_TXCAL_RX_IQCORR_IDX_7_0__NUM                                  1

/* macros for BlueprintGlobalNameSpace::txcal_rx_iqcorr_idx_15_8 */
#ifndef __TXCAL_RX_IQCORR_IDX_15_8_MACRO__
#define __TXCAL_RX_IQCORR_IDX_15_8_MACRO__

/* macros for field txcal_rx_iqcorr_idx_8 */
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_8__SHIFT                0
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_8__WIDTH                4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_8__MASK       0x0000000fU
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_8__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_8__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_8__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_8__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field txcal_rx_iqcorr_idx_9 */
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_9__SHIFT                4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_9__WIDTH                4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_9__MASK       0x000000f0U
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_9__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_9__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_9__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_9__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field txcal_rx_iqcorr_idx_10 */
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_10__SHIFT               8
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_10__WIDTH               4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_10__MASK      0x00000f00U
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_10__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_10__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_10__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_10__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field txcal_rx_iqcorr_idx_11 */
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_11__SHIFT              12
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_11__WIDTH               4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_11__MASK      0x0000f000U
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_11__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_11__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_11__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_11__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field txcal_rx_iqcorr_idx_12 */
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_12__SHIFT              16
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_12__WIDTH               4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_12__MASK      0x000f0000U
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_12__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_12__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_12__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_12__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field txcal_rx_iqcorr_idx_13 */
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_13__SHIFT              20
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_13__WIDTH               4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_13__MASK      0x00f00000U
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_13__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_13__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_13__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_13__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field txcal_rx_iqcorr_idx_14 */
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_14__SHIFT              24
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_14__WIDTH               4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_14__MASK      0x0f000000U
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_14__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_14__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_14__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_14__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field txcal_rx_iqcorr_idx_15 */
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_15__SHIFT              28
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_15__WIDTH               4
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_15__MASK      0xf0000000U
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_15__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_15__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_15__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define TXCAL_RX_IQCORR_IDX_15_8__TXCAL_RX_IQCORR_IDX_15__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define TXCAL_RX_IQCORR_IDX_15_8__TYPE                                 uint32_t
#define TXCAL_RX_IQCORR_IDX_15_8__READ                              0xffffffffU
#define TXCAL_RX_IQCORR_IDX_15_8__WRITE                             0xffffffffU

#endif /* __TXCAL_RX_IQCORR_IDX_15_8_MACRO__ */


/* macros for BB_txcal_rx_iqcorr_idx_15_8 */
#define INST_BB_TXCAL_RX_IQCORR_IDX_15_8__NUM                                 1

/* macros for BlueprintGlobalNameSpace::txcal_rx_iqcorr_idx_23_16 */
#ifndef __TXCAL_RX_IQCORR_IDX_23_16_MACRO__
#define __TXCAL_RX_IQCORR_IDX_23_16_MACRO__

/* macros for field txcal_rx_iqcorr_idx_16 */
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_16__SHIFT              0
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_16__WIDTH              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_16__MASK     0x0000000fU
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_16__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_16__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_16__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_16__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field txcal_rx_iqcorr_idx_17 */
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_17__SHIFT              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_17__WIDTH              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_17__MASK     0x000000f0U
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_17__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_17__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_17__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_17__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field txcal_rx_iqcorr_idx_18 */
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_18__SHIFT              8
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_18__WIDTH              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_18__MASK     0x00000f00U
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_18__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_18__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_18__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_18__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field txcal_rx_iqcorr_idx_19 */
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_19__SHIFT             12
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_19__WIDTH              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_19__MASK     0x0000f000U
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_19__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_19__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_19__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_19__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field txcal_rx_iqcorr_idx_20 */
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_20__SHIFT             16
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_20__WIDTH              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_20__MASK     0x000f0000U
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_20__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_20__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_20__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_20__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field txcal_rx_iqcorr_idx_21 */
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_21__SHIFT             20
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_21__WIDTH              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_21__MASK     0x00f00000U
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_21__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_21__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_21__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_21__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field txcal_rx_iqcorr_idx_22 */
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_22__SHIFT             24
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_22__WIDTH              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_22__MASK     0x0f000000U
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_22__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_22__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_22__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_22__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field txcal_rx_iqcorr_idx_23 */
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_23__SHIFT             28
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_23__WIDTH              4
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_23__MASK     0xf0000000U
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_23__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_23__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_23__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define TXCAL_RX_IQCORR_IDX_23_16__TXCAL_RX_IQCORR_IDX_23__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define TXCAL_RX_IQCORR_IDX_23_16__TYPE                                uint32_t
#define TXCAL_RX_IQCORR_IDX_23_16__READ                             0xffffffffU
#define TXCAL_RX_IQCORR_IDX_23_16__WRITE                            0xffffffffU

#endif /* __TXCAL_RX_IQCORR_IDX_23_16_MACRO__ */


/* macros for BB_txcal_rx_iqcorr_idx_23_16 */
#define INST_BB_TXCAL_RX_IQCORR_IDX_23_16__NUM                                1

/* macros for BlueprintGlobalNameSpace::txcal_rx_iqcorr_idx_24 */
#ifndef __TXCAL_RX_IQCORR_IDX_24_MACRO__
#define __TXCAL_RX_IQCORR_IDX_24_MACRO__

/* macros for field txcal_rx_iqcorr_idx_24 */
#define TXCAL_RX_IQCORR_IDX_24__TXCAL_RX_IQCORR_IDX_24__SHIFT                 0
#define TXCAL_RX_IQCORR_IDX_24__TXCAL_RX_IQCORR_IDX_24__WIDTH                 4
#define TXCAL_RX_IQCORR_IDX_24__TXCAL_RX_IQCORR_IDX_24__MASK        0x0000000fU
#define TXCAL_RX_IQCORR_IDX_24__TXCAL_RX_IQCORR_IDX_24__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define TXCAL_RX_IQCORR_IDX_24__TXCAL_RX_IQCORR_IDX_24__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define TXCAL_RX_IQCORR_IDX_24__TXCAL_RX_IQCORR_IDX_24__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define TXCAL_RX_IQCORR_IDX_24__TXCAL_RX_IQCORR_IDX_24__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define TXCAL_RX_IQCORR_IDX_24__TYPE                                   uint32_t
#define TXCAL_RX_IQCORR_IDX_24__READ                                0x0000000fU
#define TXCAL_RX_IQCORR_IDX_24__WRITE                               0x0000000fU

#endif /* __TXCAL_RX_IQCORR_IDX_24_MACRO__ */


/* macros for BB_txcal_rx_iqcorr_idx_24 */
#define INST_BB_TXCAL_RX_IQCORR_IDX_24__NUM                                   1

/* macros for BlueprintGlobalNameSpace::paprd_sm_sig_gain_table_0_2_b0 */
#ifndef __PAPRD_SM_SIG_GAIN_TABLE_0_2_B0_MACRO__
#define __PAPRD_SM_SIG_GAIN_TABLE_0_2_B0_MACRO__

/* macros for field paprd_sm_sig_gain_0 */
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_0__SHIFT            0
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_0__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_0__MASK   0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_sm_sig_gain_1 */
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_1__SHIFT           10
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_1__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_1__MASK   0x000ffc00U
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_sm_sig_gain_2 */
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_2__SHIFT           20
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_2__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_2__MASK   0x3ff00000U
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__PAPRD_SM_SIG_GAIN_2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__TYPE                           uint32_t
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__READ                        0x3fffffffU
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__WRITE                       0x3fffffffU

#endif /* __PAPRD_SM_SIG_GAIN_TABLE_0_2_B0_MACRO__ */


/* macros for BB_paprd_sm_sig_gain_table_0_2_b0 */
#define INST_BB_PAPRD_SM_SIG_GAIN_TABLE_0_2_B0__NUM                           1

/* macros for BlueprintGlobalNameSpace::paprd_sm_sig_gain_table_3_5_b0 */
#ifndef __PAPRD_SM_SIG_GAIN_TABLE_3_5_B0_MACRO__
#define __PAPRD_SM_SIG_GAIN_TABLE_3_5_B0_MACRO__

/* macros for field paprd_sm_sig_gain_3 */
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_3__SHIFT            0
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_3__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_3__MASK   0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_3__READ(src) \
                    (uint32_t)(src)\
                    & 0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_3__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_sm_sig_gain_4 */
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_4__SHIFT           10
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_4__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_4__MASK   0x000ffc00U
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_4__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_4__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_4__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_sm_sig_gain_5 */
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_5__SHIFT           20
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_5__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_5__MASK   0x3ff00000U
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_5__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_5__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__PAPRD_SM_SIG_GAIN_5__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__TYPE                           uint32_t
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__READ                        0x3fffffffU
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__WRITE                       0x3fffffffU

#endif /* __PAPRD_SM_SIG_GAIN_TABLE_3_5_B0_MACRO__ */


/* macros for BB_paprd_sm_sig_gain_table_3_5_b0 */
#define INST_BB_PAPRD_SM_SIG_GAIN_TABLE_3_5_B0__NUM                           1

/* macros for BlueprintGlobalNameSpace::paprd_sm_sig_gain_table_6_b0 */
#ifndef __PAPRD_SM_SIG_GAIN_TABLE_6_B0_MACRO__
#define __PAPRD_SM_SIG_GAIN_TABLE_6_B0_MACRO__

/* macros for field paprd_sm_sig_gain_6 */
#define PAPRD_SM_SIG_GAIN_TABLE_6_B0__PAPRD_SM_SIG_GAIN_6__SHIFT              0
#define PAPRD_SM_SIG_GAIN_TABLE_6_B0__PAPRD_SM_SIG_GAIN_6__WIDTH             10
#define PAPRD_SM_SIG_GAIN_TABLE_6_B0__PAPRD_SM_SIG_GAIN_6__MASK     0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_6_B0__PAPRD_SM_SIG_GAIN_6__READ(src) \
                    (uint32_t)(src)\
                    & 0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_6_B0__PAPRD_SM_SIG_GAIN_6__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_6_B0__PAPRD_SM_SIG_GAIN_6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_6_B0__PAPRD_SM_SIG_GAIN_6__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define PAPRD_SM_SIG_GAIN_TABLE_6_B0__TYPE                             uint32_t
#define PAPRD_SM_SIG_GAIN_TABLE_6_B0__READ                          0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_6_B0__WRITE                         0x000003ffU

#endif /* __PAPRD_SM_SIG_GAIN_TABLE_6_B0_MACRO__ */


/* macros for BB_paprd_sm_sig_gain_table_6_b0 */
#define INST_BB_PAPRD_SM_SIG_GAIN_TABLE_6_B0__NUM                             1

/* macros for BlueprintGlobalNameSpace::preemp_coef_set0_b0 */
#ifndef __PREEMP_COEF_SET0_B0_MACRO__
#define __PREEMP_COEF_SET0_B0_MACRO__

/* macros for field tx_preemp_coef_0_b0 */
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_0_B0__SHIFT                       0
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_0_B0__WIDTH                       9
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_0_B0__MASK              0x000001ffU
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_0_B0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_0_B0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_0_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_0_B0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field tx_preemp_coef_1_b0 */
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_1_B0__SHIFT                       9
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_1_B0__WIDTH                       9
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_1_B0__MASK              0x0003fe00U
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_1_B0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_1_B0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_1_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_1_B0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field tx_preemp_coef_2_b0 */
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_2_B0__SHIFT                      18
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_2_B0__WIDTH                       9
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_2_B0__MASK              0x07fc0000U
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_2_B0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_2_B0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_2_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PREEMP_COEF_SET0_B0__TX_PREEMP_COEF_2_B0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))

/* macros for field tx_preemp_fir_en */
#define PREEMP_COEF_SET0_B0__TX_PREEMP_FIR_EN__SHIFT                         31
#define PREEMP_COEF_SET0_B0__TX_PREEMP_FIR_EN__WIDTH                          1
#define PREEMP_COEF_SET0_B0__TX_PREEMP_FIR_EN__MASK                 0x80000000U
#define PREEMP_COEF_SET0_B0__TX_PREEMP_FIR_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PREEMP_COEF_SET0_B0__TX_PREEMP_FIR_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PREEMP_COEF_SET0_B0__TX_PREEMP_FIR_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PREEMP_COEF_SET0_B0__TX_PREEMP_FIR_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PREEMP_COEF_SET0_B0__TX_PREEMP_FIR_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PREEMP_COEF_SET0_B0__TX_PREEMP_FIR_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PREEMP_COEF_SET0_B0__TYPE                                      uint32_t
#define PREEMP_COEF_SET0_B0__READ                                   0x87ffffffU
#define PREEMP_COEF_SET0_B0__WRITE                                  0x87ffffffU

#endif /* __PREEMP_COEF_SET0_B0_MACRO__ */


/* macros for BB_preemp_coef_set0_b0 */
#define INST_BB_PREEMP_COEF_SET0_B0__NUM                                      1

/* macros for BlueprintGlobalNameSpace::preemp_coef_set1_b0 */
#ifndef __PREEMP_COEF_SET1_B0_MACRO__
#define __PREEMP_COEF_SET1_B0_MACRO__

/* macros for field tx_preemp_coef_3_b0 */
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_3_B0__SHIFT                       0
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_3_B0__WIDTH                       9
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_3_B0__MASK              0x000001ffU
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_3_B0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_3_B0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_3_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_3_B0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field tx_preemp_coef_4_b0 */
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_4_B0__SHIFT                       9
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_4_B0__WIDTH                       9
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_4_B0__MASK              0x0003fe00U
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_4_B0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_4_B0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_4_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_4_B0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field tx_preemp_coef_5_b0 */
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_5_B0__SHIFT                      18
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_5_B0__WIDTH                       9
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_5_B0__MASK              0x07fc0000U
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_5_B0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_5_B0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_5_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PREEMP_COEF_SET1_B0__TX_PREEMP_COEF_5_B0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define PREEMP_COEF_SET1_B0__TYPE                                      uint32_t
#define PREEMP_COEF_SET1_B0__READ                                   0x07ffffffU
#define PREEMP_COEF_SET1_B0__WRITE                                  0x07ffffffU

#endif /* __PREEMP_COEF_SET1_B0_MACRO__ */


/* macros for BB_preemp_coef_set1_b0 */
#define INST_BB_PREEMP_COEF_SET1_B0__NUM                                      1

/* macros for BlueprintGlobalNameSpace::preemp_coef_set2_b0 */
#ifndef __PREEMP_COEF_SET2_B0_MACRO__
#define __PREEMP_COEF_SET2_B0_MACRO__

/* macros for field tx_preemp_coef_6_b0 */
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_6_B0__SHIFT                       0
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_6_B0__WIDTH                       9
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_6_B0__MASK              0x000001ffU
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_6_B0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_6_B0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_6_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_6_B0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field tx_preemp_coef_7_b0 */
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_7_B0__SHIFT                       9
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_7_B0__WIDTH                       9
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_7_B0__MASK              0x0003fe00U
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_7_B0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_7_B0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_7_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_7_B0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field tx_preemp_coef_8_b0 */
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_8_B0__SHIFT                      18
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_8_B0__WIDTH                       9
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_8_B0__MASK              0x07fc0000U
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_8_B0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_8_B0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_8_B0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PREEMP_COEF_SET2_B0__TX_PREEMP_COEF_8_B0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define PREEMP_COEF_SET2_B0__TYPE                                      uint32_t
#define PREEMP_COEF_SET2_B0__READ                                   0x07ffffffU
#define PREEMP_COEF_SET2_B0__WRITE                                  0x07ffffffU

#endif /* __PREEMP_COEF_SET2_B0_MACRO__ */


/* macros for BB_preemp_coef_set2_b0 */
#define INST_BB_PREEMP_COEF_SET2_B0__NUM                                      1

/* macros for BlueprintGlobalNameSpace::tx_plybck_ctrl_0_b0 */
#ifndef __TX_PLYBCK_CTRL_0_B0_MACRO__
#define __TX_PLYBCK_CTRL_0_B0_MACRO__

/* macros for field tx_plybck_enable */
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__SHIFT                          0
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__WIDTH                          1
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__MASK                 0x00000001U
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__READ(src) \
                    (uint32_t)(src)\
                    & 0x00000001U
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)

/* macros for field tx_plybck_sw_we */
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_WE__SHIFT                           1
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_WE__WIDTH                           1
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_WE__MASK                  0x00000002U
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_WE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_WE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_WE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_WE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_WE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_SW_WE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)

/* macros for field tx_plybck_start_addr */
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_START_ADDR__SHIFT                      8
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_START_ADDR__WIDTH                      8
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_START_ADDR__MASK             0x0000ff00U
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_START_ADDR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_START_ADDR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_START_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_START_ADDR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))

/* macros for field tx_plybck_nsamples */
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_NSAMPLES__SHIFT                       16
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_NSAMPLES__WIDTH                       16
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_NSAMPLES__MASK               0xffff0000U
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_NSAMPLES__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_NSAMPLES__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_NSAMPLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define TX_PLYBCK_CTRL_0_B0__TX_PLYBCK_NSAMPLES__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define TX_PLYBCK_CTRL_0_B0__TYPE                                      uint32_t
#define TX_PLYBCK_CTRL_0_B0__READ                                   0xffffff03U
#define TX_PLYBCK_CTRL_0_B0__WRITE                                  0xffffff03U

#endif /* __TX_PLYBCK_CTRL_0_B0_MACRO__ */


/* macros for BB_tx_plybck_ctrl_0_b0 */
#define INST_BB_TX_PLYBCK_CTRL_0_B0__NUM                                      1

/* macros for BlueprintGlobalNameSpace::tx_plybck_ctrl_1_b0 */
#ifndef __TX_PLYBCK_CTRL_1_B0_MACRO__
#define __TX_PLYBCK_CTRL_1_B0_MACRO__

/* macros for field tx_plybck_swdata_i */
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_SWDATA_I__SHIFT                        0
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_SWDATA_I__WIDTH                       11
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_SWDATA_I__MASK               0x000007ffU
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_SWDATA_I__READ(src) \
                    (uint32_t)(src)\
                    & 0x000007ffU
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_SWDATA_I__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000007ffU)
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_SWDATA_I__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000007ffU) | ((uint32_t)(src) &\
                    0x000007ffU)
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_SWDATA_I__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000007ffU)))

/* macros for field tx_plybck_swdata_q */
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_SWDATA_Q__SHIFT                       11
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_SWDATA_Q__WIDTH                       11
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_SWDATA_Q__MASK               0x003ff800U
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_SWDATA_Q__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003ff800U) >> 11)
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_SWDATA_Q__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x003ff800U)
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_SWDATA_Q__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003ff800U) | (((uint32_t)(src) <<\
                    11) & 0x003ff800U)
#define TX_PLYBCK_CTRL_1_B0__TX_PLYBCK_SWDATA_Q__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x003ff800U)))
#define TX_PLYBCK_CTRL_1_B0__TYPE                                      uint32_t
#define TX_PLYBCK_CTRL_1_B0__READ                                   0x003fffffU
#define TX_PLYBCK_CTRL_1_B0__WRITE                                  0x003fffffU

#endif /* __TX_PLYBCK_CTRL_1_B0_MACRO__ */


/* macros for BB_tx_plybck_ctrl_1_b0 */
#define INST_BB_TX_PLYBCK_CTRL_1_B0__NUM                                      1

/* macros for BlueprintGlobalNameSpace::chaninfo_vht80_b0 */
#ifndef __CHANINFO_VHT80_B0_MACRO__
#define __CHANINFO_VHT80_B0_MACRO__

/* macros for field chaninfo_vht80_chn0 */
#define CHANINFO_VHT80_B0__CHANINFO_VHT80_CHN0__SHIFT                         0
#define CHANINFO_VHT80_B0__CHANINFO_VHT80_CHN0__WIDTH                        32
#define CHANINFO_VHT80_B0__CHANINFO_VHT80_CHN0__MASK                0xffffffffU
#define CHANINFO_VHT80_B0__CHANINFO_VHT80_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0xffffffffU
#define CHANINFO_VHT80_B0__TYPE                                        uint32_t
#define CHANINFO_VHT80_B0__READ                                     0xffffffffU

#endif /* __CHANINFO_VHT80_B0_MACRO__ */


/* macros for BB_chaninfo_vht80_b0 */
#define INST_BB_CHANINFO_VHT80_B0__NUM                                       64

/* macros for BlueprintGlobalNameSpace::normrx_rxiq_corr_coeff_b0 */
#ifndef __NORMRX_RXIQ_CORR_COEFF_B0_MACRO__
#define __NORMRX_RXIQ_CORR_COEFF_B0_MACRO__

/* macros for field normrx_iqc_coeff_table_chn0 */
#define NORMRX_RXIQ_CORR_COEFF_B0__NORMRX_IQC_COEFF_TABLE_CHN0__SHIFT         0
#define NORMRX_RXIQ_CORR_COEFF_B0__NORMRX_IQC_COEFF_TABLE_CHN0__WIDTH        18
#define NORMRX_RXIQ_CORR_COEFF_B0__NORMRX_IQC_COEFF_TABLE_CHN0__MASK \
                    0x0003ffffU
#define NORMRX_RXIQ_CORR_COEFF_B0__NORMRX_IQC_COEFF_TABLE_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define NORMRX_RXIQ_CORR_COEFF_B0__NORMRX_IQC_COEFF_TABLE_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define NORMRX_RXIQ_CORR_COEFF_B0__NORMRX_IQC_COEFF_TABLE_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define NORMRX_RXIQ_CORR_COEFF_B0__NORMRX_IQC_COEFF_TABLE_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define NORMRX_RXIQ_CORR_COEFF_B0__TYPE                                uint32_t
#define NORMRX_RXIQ_CORR_COEFF_B0__READ                             0x0003ffffU
#define NORMRX_RXIQ_CORR_COEFF_B0__WRITE                            0x0003ffffU

#endif /* __NORMRX_RXIQ_CORR_COEFF_B0_MACRO__ */


/* macros for BB_normrx_rxiq_corr_coeff_b0 */
#define INST_BB_NORMRX_RXIQ_CORR_COEFF_B0__NUM                              160

/* macros for BlueprintGlobalNameSpace::paprd_mem_tab_b0 */
#ifndef __PAPRD_MEM_TAB_B0_MACRO__
#define __PAPRD_MEM_TAB_B0_MACRO__

/* macros for field paprd_mem */
#define PAPRD_MEM_TAB_B0__PAPRD_MEM__SHIFT                                    0
#define PAPRD_MEM_TAB_B0__PAPRD_MEM__WIDTH                                   22
#define PAPRD_MEM_TAB_B0__PAPRD_MEM__MASK                           0x003fffffU
#define PAPRD_MEM_TAB_B0__PAPRD_MEM__READ(src)    (uint32_t)(src) & 0x003fffffU
#define PAPRD_MEM_TAB_B0__PAPRD_MEM__WRITE(src) ((uint32_t)(src) & 0x003fffffU)
#define PAPRD_MEM_TAB_B0__PAPRD_MEM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define PAPRD_MEM_TAB_B0__PAPRD_MEM__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define PAPRD_MEM_TAB_B0__TYPE                                         uint32_t
#define PAPRD_MEM_TAB_B0__READ                                      0x003fffffU
#define PAPRD_MEM_TAB_B0__WRITE                                     0x003fffffU

#endif /* __PAPRD_MEM_TAB_B0_MACRO__ */


/* macros for BB_paprd_mem_tab_b0 */
#define INST_BB_PAPRD_MEM_TAB_B0__NUM                                      1344

/* macros for BlueprintGlobalNameSpace::paprd_trainer_cntl1 */
#ifndef __PAPRD_TRAINER_CNTL1_MACRO__
#define __PAPRD_TRAINER_CNTL1_MACRO__

/* macros for field cf_paprd_train_enable */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__SHIFT                     0
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__WIDTH                     1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__MASK            0x00000001U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__READ(src) \
                    (uint32_t)(src)\
                    & 0x00000001U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)

/* macros for field cf_paprd_agc2_settling */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_AGC2_SETTLING__SHIFT                    1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_AGC2_SETTLING__WIDTH                    7
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_AGC2_SETTLING__MASK           0x000000feU
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_AGC2_SETTLING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000feU) >> 1)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_AGC2_SETTLING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000000feU)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_AGC2_SETTLING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000feU) | (((uint32_t)(src) <<\
                    1) & 0x000000feU)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_AGC2_SETTLING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000000feU)))

/* macros for field cf_paprd_iqcorr_enable */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__SHIFT                    8
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__WIDTH                    1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__MASK           0x00000100U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_IQCORR_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)

/* macros for field cf_paprd_rx_bb_gain_force */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__SHIFT                 9
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__WIDTH                 1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__MASK        0x00000200U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_RX_BB_GAIN_FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)

/* macros for field cf_paprd_tx_gain_force */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__SHIFT                   10
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__WIDTH                    1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__MASK           0x00000400U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TX_GAIN_FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)

/* macros for field cf_paprd_dc_corr_enable */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__SHIFT                  11
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__WIDTH                   1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__MASK          0x00000800U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_DC_CORR_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)

/* macros for field cf_paprd_corr_force */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__SHIFT                      19
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__WIDTH                       1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__MASK              0x00080000U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_CORR_FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)

/* macros for field cf_paprd_forced_coarse_idx */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_COARSE_IDX__SHIFT               20
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_COARSE_IDX__WIDTH                5
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_COARSE_IDX__MASK       0x01f00000U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_COARSE_IDX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01f00000U) >> 20)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_COARSE_IDX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x01f00000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_COARSE_IDX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01f00000U) | (((uint32_t)(src) <<\
                    20) & 0x01f00000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_COARSE_IDX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x01f00000U)))

/* macros for field cf_paprd_forced_fine_idx */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_FINE_IDX__SHIFT                 25
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_FINE_IDX__WIDTH                  2
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_FINE_IDX__MASK         0x06000000U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_FINE_IDX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x06000000U) >> 25)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_FINE_IDX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x06000000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_FINE_IDX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x06000000U) | (((uint32_t)(src) <<\
                    25) & 0x06000000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_FORCED_FINE_IDX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x06000000U)))

/* macros for field cf_paprd_train_mode */
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__SHIFT                      31
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__WIDTH                       1
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__MASK              0x80000000U
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PAPRD_TRAINER_CNTL1__CF_PAPRD_TRAIN_MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PAPRD_TRAINER_CNTL1__TYPE                                      uint32_t
#define PAPRD_TRAINER_CNTL1__READ                                   0x87f80fffU
#define PAPRD_TRAINER_CNTL1__WRITE                                  0x87f80fffU

#endif /* __PAPRD_TRAINER_CNTL1_MACRO__ */


/* macros for BB_paprd_trainer_cntl1 */
#define INST_BB_PAPRD_TRAINER_CNTL1__NUM                                      1

/* macros for BlueprintGlobalNameSpace::paprd_trainer_cntl2 */
#ifndef __PAPRD_TRAINER_CNTL2_MACRO__
#define __PAPRD_TRAINER_CNTL2_MACRO__

/* macros for field cf_paprd_init_rx_bb_gain */
#define PAPRD_TRAINER_CNTL2__CF_PAPRD_INIT_RX_BB_GAIN__SHIFT                  0
#define PAPRD_TRAINER_CNTL2__CF_PAPRD_INIT_RX_BB_GAIN__WIDTH                 32
#define PAPRD_TRAINER_CNTL2__CF_PAPRD_INIT_RX_BB_GAIN__MASK         0xffffffffU
#define PAPRD_TRAINER_CNTL2__CF_PAPRD_INIT_RX_BB_GAIN__READ(src) \
                    (uint32_t)(src)\
                    & 0xffffffffU
#define PAPRD_TRAINER_CNTL2__CF_PAPRD_INIT_RX_BB_GAIN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define PAPRD_TRAINER_CNTL2__CF_PAPRD_INIT_RX_BB_GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PAPRD_TRAINER_CNTL2__CF_PAPRD_INIT_RX_BB_GAIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PAPRD_TRAINER_CNTL2__TYPE                                      uint32_t
#define PAPRD_TRAINER_CNTL2__READ                                   0xffffffffU
#define PAPRD_TRAINER_CNTL2__WRITE                                  0xffffffffU

#endif /* __PAPRD_TRAINER_CNTL2_MACRO__ */


/* macros for BB_paprd_trainer_cntl2 */
#define INST_BB_PAPRD_TRAINER_CNTL2__NUM                                      1

/* macros for BlueprintGlobalNameSpace::paprd_trainer_cntl3 */
#ifndef __PAPRD_TRAINER_CNTL3_MACRO__
#define __PAPRD_TRAINER_CNTL3_MACRO__

/* macros for field cf_paprd_quick_drop */
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_QUICK_DROP__SHIFT                       6
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_QUICK_DROP__WIDTH                       6
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_QUICK_DROP__MASK              0x00000fc0U
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_QUICK_DROP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_QUICK_DROP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_QUICK_DROP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_QUICK_DROP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field cf_paprd_min_loopback_del */
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_MIN_LOOPBACK_DEL__SHIFT                12
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_MIN_LOOPBACK_DEL__WIDTH                 5
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_MIN_LOOPBACK_DEL__MASK        0x0001f000U
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_MIN_LOOPBACK_DEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001f000U) >> 12)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_MIN_LOOPBACK_DEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0001f000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_MIN_LOOPBACK_DEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001f000U) | (((uint32_t)(src) <<\
                    12) & 0x0001f000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_MIN_LOOPBACK_DEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0001f000U)))

/* macros for field cf_paprd_num_corr_stages */
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_NUM_CORR_STAGES__SHIFT                 17
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_NUM_CORR_STAGES__WIDTH                  3
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_NUM_CORR_STAGES__MASK         0x000e0000U
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_NUM_CORR_STAGES__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000e0000U) >> 17)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_NUM_CORR_STAGES__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x000e0000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_NUM_CORR_STAGES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000e0000U) | (((uint32_t)(src) <<\
                    17) & 0x000e0000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_NUM_CORR_STAGES__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x000e0000U)))

/* macros for field cf_paprd_coarse_corr_len */
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_COARSE_CORR_LEN__SHIFT                 20
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_COARSE_CORR_LEN__WIDTH                  4
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_COARSE_CORR_LEN__MASK         0x00f00000U
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_COARSE_CORR_LEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_COARSE_CORR_LEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_COARSE_CORR_LEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_COARSE_CORR_LEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field cf_paprd_fine_corr_len */
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_FINE_CORR_LEN__SHIFT                   24
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_FINE_CORR_LEN__WIDTH                    4
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_FINE_CORR_LEN__MASK           0x0f000000U
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_FINE_CORR_LEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_FINE_CORR_LEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_FINE_CORR_LEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_FINE_CORR_LEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field cf_paprd_bbtxmix_disable */
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__SHIFT                 29
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__WIDTH                  1
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__MASK         0x20000000U
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define PAPRD_TRAINER_CNTL3__CF_PAPRD_BBTXMIX_DISABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define PAPRD_TRAINER_CNTL3__TYPE                                      uint32_t
#define PAPRD_TRAINER_CNTL3__READ                                   0x2fffffc0U
#define PAPRD_TRAINER_CNTL3__WRITE                                  0x2fffffc0U

#endif /* __PAPRD_TRAINER_CNTL3_MACRO__ */


/* macros for BB_paprd_trainer_cntl3 */
#define INST_BB_PAPRD_TRAINER_CNTL3__NUM                                      1

/* macros for BlueprintGlobalNameSpace::paprd_trainer_cntl4 */
#ifndef __PAPRD_TRAINER_CNTL4_MACRO__
#define __PAPRD_TRAINER_CNTL4_MACRO__

/* macros for field cf_paprd_min_corr */
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_MIN_CORR__SHIFT                         0
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_MIN_CORR__WIDTH                        12
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_MIN_CORR__MASK                0x00000fffU
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_MIN_CORR__READ(src) \
                    (uint32_t)(src)\
                    & 0x00000fffU
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_MIN_CORR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000fffU)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_MIN_CORR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fffU) | ((uint32_t)(src) &\
                    0x00000fffU)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_MIN_CORR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000fffU)))

/* macros for field cf_paprd_safety_delta */
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_SAFETY_DELTA__SHIFT                    12
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_SAFETY_DELTA__WIDTH                     4
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_SAFETY_DELTA__MASK            0x0000f000U
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_SAFETY_DELTA__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_SAFETY_DELTA__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_SAFETY_DELTA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_SAFETY_DELTA__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field cf_paprd_num_train_samples */
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_NUM_TRAIN_SAMPLES__SHIFT               16
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_NUM_TRAIN_SAMPLES__WIDTH               10
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_NUM_TRAIN_SAMPLES__MASK       0x03ff0000U
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_NUM_TRAIN_SAMPLES__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03ff0000U) >> 16)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_NUM_TRAIN_SAMPLES__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x03ff0000U)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_NUM_TRAIN_SAMPLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x03ff0000U)
#define PAPRD_TRAINER_CNTL4__CF_PAPRD_NUM_TRAIN_SAMPLES__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x03ff0000U)))
#define PAPRD_TRAINER_CNTL4__TYPE                                      uint32_t
#define PAPRD_TRAINER_CNTL4__READ                                   0x03ffffffU
#define PAPRD_TRAINER_CNTL4__WRITE                                  0x03ffffffU

#endif /* __PAPRD_TRAINER_CNTL4_MACRO__ */


/* macros for BB_paprd_trainer_cntl4 */
#define INST_BB_PAPRD_TRAINER_CNTL4__NUM                                      1

/* macros for BlueprintGlobalNameSpace::paprd_trainer_stat1 */
#ifndef __PAPRD_TRAINER_STAT1_MACRO__
#define __PAPRD_TRAINER_STAT1_MACRO__

/* macros for field paprd_train_done */
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__SHIFT                          0
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__WIDTH                          1
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__MASK                 0x00000001U
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__READ(src) \
                    (uint32_t)(src)\
                    & 0x00000001U
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)

/* macros for field paprd_train_incomplete */
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_INCOMPLETE__SHIFT                    1
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_INCOMPLETE__WIDTH                    1
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_INCOMPLETE__MASK           0x00000002U
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_INCOMPLETE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_INCOMPLETE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_INCOMPLETE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)

/* macros for field paprd_corr_err */
#define PAPRD_TRAINER_STAT1__PAPRD_CORR_ERR__SHIFT                            2
#define PAPRD_TRAINER_STAT1__PAPRD_CORR_ERR__WIDTH                            1
#define PAPRD_TRAINER_STAT1__PAPRD_CORR_ERR__MASK                   0x00000004U
#define PAPRD_TRAINER_STAT1__PAPRD_CORR_ERR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PAPRD_TRAINER_STAT1__PAPRD_CORR_ERR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PAPRD_TRAINER_STAT1__PAPRD_CORR_ERR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)

/* macros for field paprd_train_active */
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_ACTIVE__SHIFT                        3
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_ACTIVE__WIDTH                        1
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_ACTIVE__MASK               0x00000008U
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_ACTIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_ACTIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PAPRD_TRAINER_STAT1__PAPRD_TRAIN_ACTIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)

/* macros for field paprd_rx_gain_idx */
#define PAPRD_TRAINER_STAT1__PAPRD_RX_GAIN_IDX__SHIFT                         4
#define PAPRD_TRAINER_STAT1__PAPRD_RX_GAIN_IDX__WIDTH                         5
#define PAPRD_TRAINER_STAT1__PAPRD_RX_GAIN_IDX__MASK                0x000001f0U
#define PAPRD_TRAINER_STAT1__PAPRD_RX_GAIN_IDX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001f0U) >> 4)

/* macros for field paprd_agc2_pwr */
#define PAPRD_TRAINER_STAT1__PAPRD_AGC2_PWR__SHIFT                            9
#define PAPRD_TRAINER_STAT1__PAPRD_AGC2_PWR__WIDTH                            8
#define PAPRD_TRAINER_STAT1__PAPRD_AGC2_PWR__MASK                   0x0001fe00U
#define PAPRD_TRAINER_STAT1__PAPRD_AGC2_PWR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fe00U) >> 9)
#define PAPRD_TRAINER_STAT1__TYPE                                      uint32_t
#define PAPRD_TRAINER_STAT1__READ                                   0x0001ffffU
#define PAPRD_TRAINER_STAT1__WRITE                                  0x0001ffffU

#endif /* __PAPRD_TRAINER_STAT1_MACRO__ */


/* macros for BB_paprd_trainer_stat1 */
#define INST_BB_PAPRD_TRAINER_STAT1__NUM                                      1

/* macros for BlueprintGlobalNameSpace::paprd_trainer_stat2 */
#ifndef __PAPRD_TRAINER_STAT2_MACRO__
#define __PAPRD_TRAINER_STAT2_MACRO__

/* macros for field paprd_fine_val */
#define PAPRD_TRAINER_STAT2__PAPRD_FINE_VAL__SHIFT                            0
#define PAPRD_TRAINER_STAT2__PAPRD_FINE_VAL__WIDTH                           16
#define PAPRD_TRAINER_STAT2__PAPRD_FINE_VAL__MASK                   0x0000ffffU
#define PAPRD_TRAINER_STAT2__PAPRD_FINE_VAL__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000ffffU

/* macros for field paprd_coarse_idx */
#define PAPRD_TRAINER_STAT2__PAPRD_COARSE_IDX__SHIFT                         16
#define PAPRD_TRAINER_STAT2__PAPRD_COARSE_IDX__WIDTH                          5
#define PAPRD_TRAINER_STAT2__PAPRD_COARSE_IDX__MASK                 0x001f0000U
#define PAPRD_TRAINER_STAT2__PAPRD_COARSE_IDX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)

/* macros for field paprd_fine_idx */
#define PAPRD_TRAINER_STAT2__PAPRD_FINE_IDX__SHIFT                           21
#define PAPRD_TRAINER_STAT2__PAPRD_FINE_IDX__WIDTH                            2
#define PAPRD_TRAINER_STAT2__PAPRD_FINE_IDX__MASK                   0x00600000U
#define PAPRD_TRAINER_STAT2__PAPRD_FINE_IDX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define PAPRD_TRAINER_STAT2__TYPE                                      uint32_t
#define PAPRD_TRAINER_STAT2__READ                                   0x007fffffU

#endif /* __PAPRD_TRAINER_STAT2_MACRO__ */


/* macros for BB_paprd_trainer_stat2 */
#define INST_BB_PAPRD_TRAINER_STAT2__NUM                                      1

/* macros for BlueprintGlobalNameSpace::paprd_trainer_stat3 */
#ifndef __PAPRD_TRAINER_STAT3_MACRO__
#define __PAPRD_TRAINER_STAT3_MACRO__

/* macros for field paprd_train_samples_cnt */
#define PAPRD_TRAINER_STAT3__PAPRD_TRAIN_SAMPLES_CNT__SHIFT                   0
#define PAPRD_TRAINER_STAT3__PAPRD_TRAIN_SAMPLES_CNT__WIDTH                  20
#define PAPRD_TRAINER_STAT3__PAPRD_TRAIN_SAMPLES_CNT__MASK          0x000fffffU
#define PAPRD_TRAINER_STAT3__PAPRD_TRAIN_SAMPLES_CNT__READ(src) \
                    (uint32_t)(src)\
                    & 0x000fffffU
#define PAPRD_TRAINER_STAT3__TYPE                                      uint32_t
#define PAPRD_TRAINER_STAT3__READ                                   0x000fffffU

#endif /* __PAPRD_TRAINER_STAT3_MACRO__ */


/* macros for BB_paprd_trainer_stat3 */
#define INST_BB_PAPRD_TRAINER_STAT3__NUM                                      1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set0 */
#ifndef __PAPRD_TRAIN_GAIN_SET0_MACRO__
#define __PAPRD_TRAIN_GAIN_SET0_MACRO__

/* macros for field paprd_gain_tbl_0 */
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_0__SHIFT                        0
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_0__WIDTH                        9
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_0__MASK               0x000001ffU
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field paprd_gain_tbl_1 */
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_1__SHIFT                        9
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_1__WIDTH                        9
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_1__MASK               0x0003fe00U
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field paprd_gain_tbl_2 */
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_2__SHIFT                       18
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_2__WIDTH                        9
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_2__MASK               0x07fc0000U
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PAPRD_TRAIN_GAIN_SET0__PAPRD_GAIN_TBL_2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define PAPRD_TRAIN_GAIN_SET0__TYPE                                    uint32_t
#define PAPRD_TRAIN_GAIN_SET0__READ                                 0x07ffffffU
#define PAPRD_TRAIN_GAIN_SET0__WRITE                                0x07ffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET0_MACRO__ */


/* macros for BB_paprd_train_gain_set0 */
#define INST_BB_PAPRD_TRAIN_GAIN_SET0__NUM                                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set1 */
#ifndef __PAPRD_TRAIN_GAIN_SET1_MACRO__
#define __PAPRD_TRAIN_GAIN_SET1_MACRO__

/* macros for field paprd_gain_tbl_3 */
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_3__SHIFT                        0
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_3__WIDTH                        9
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_3__MASK               0x000001ffU
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_3__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_3__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field paprd_gain_tbl_4 */
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_4__SHIFT                        9
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_4__WIDTH                        9
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_4__MASK               0x0003fe00U
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_4__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_4__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_4__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field paprd_gain_tbl_5 */
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_5__SHIFT                       18
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_5__WIDTH                        9
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_5__MASK               0x07fc0000U
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_5__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_5__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PAPRD_TRAIN_GAIN_SET1__PAPRD_GAIN_TBL_5__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define PAPRD_TRAIN_GAIN_SET1__TYPE                                    uint32_t
#define PAPRD_TRAIN_GAIN_SET1__READ                                 0x07ffffffU
#define PAPRD_TRAIN_GAIN_SET1__WRITE                                0x07ffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET1_MACRO__ */


/* macros for BB_paprd_train_gain_set1 */
#define INST_BB_PAPRD_TRAIN_GAIN_SET1__NUM                                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set2 */
#ifndef __PAPRD_TRAIN_GAIN_SET2_MACRO__
#define __PAPRD_TRAIN_GAIN_SET2_MACRO__

/* macros for field paprd_gain_tbl_6 */
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_6__SHIFT                        0
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_6__WIDTH                        9
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_6__MASK               0x000001ffU
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_6__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_6__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_6__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field paprd_gain_tbl_7 */
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_7__SHIFT                        9
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_7__WIDTH                        9
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_7__MASK               0x0003fe00U
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_7__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_7__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_7__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field paprd_gain_tbl_8 */
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_8__SHIFT                       18
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_8__WIDTH                        9
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_8__MASK               0x07fc0000U
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_8__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_8__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_8__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PAPRD_TRAIN_GAIN_SET2__PAPRD_GAIN_TBL_8__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define PAPRD_TRAIN_GAIN_SET2__TYPE                                    uint32_t
#define PAPRD_TRAIN_GAIN_SET2__READ                                 0x07ffffffU
#define PAPRD_TRAIN_GAIN_SET2__WRITE                                0x07ffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET2_MACRO__ */


/* macros for BB_paprd_train_gain_set2 */
#define INST_BB_PAPRD_TRAIN_GAIN_SET2__NUM                                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set3 */
#ifndef __PAPRD_TRAIN_GAIN_SET3_MACRO__
#define __PAPRD_TRAIN_GAIN_SET3_MACRO__

/* macros for field paprd_gain_tbl_9 */
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_9__SHIFT                        0
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_9__WIDTH                        9
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_9__MASK               0x000001ffU
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_9__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_9__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_9__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_9__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field paprd_gain_tbl_10 */
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_10__SHIFT                       9
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_10__WIDTH                       9
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_10__MASK              0x0003fe00U
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_10__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_10__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_10__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_10__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field paprd_gain_tbl_11 */
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_11__SHIFT                      18
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_11__WIDTH                       9
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_11__MASK              0x07fc0000U
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_11__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_11__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_11__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PAPRD_TRAIN_GAIN_SET3__PAPRD_GAIN_TBL_11__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define PAPRD_TRAIN_GAIN_SET3__TYPE                                    uint32_t
#define PAPRD_TRAIN_GAIN_SET3__READ                                 0x07ffffffU
#define PAPRD_TRAIN_GAIN_SET3__WRITE                                0x07ffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET3_MACRO__ */


/* macros for BB_paprd_train_gain_set3 */
#define INST_BB_PAPRD_TRAIN_GAIN_SET3__NUM                                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set4 */
#ifndef __PAPRD_TRAIN_GAIN_SET4_MACRO__
#define __PAPRD_TRAIN_GAIN_SET4_MACRO__

/* macros for field paprd_gain_tbl_12 */
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_12__SHIFT                       0
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_12__WIDTH                       9
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_12__MASK              0x000001ffU
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_12__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_12__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_12__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_12__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field paprd_gain_tbl_13 */
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_13__SHIFT                       9
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_13__WIDTH                       9
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_13__MASK              0x0003fe00U
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_13__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_13__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_13__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_13__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field paprd_gain_tbl_14 */
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_14__SHIFT                      18
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_14__WIDTH                       9
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_14__MASK              0x07fc0000U
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_14__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_14__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_14__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PAPRD_TRAIN_GAIN_SET4__PAPRD_GAIN_TBL_14__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define PAPRD_TRAIN_GAIN_SET4__TYPE                                    uint32_t
#define PAPRD_TRAIN_GAIN_SET4__READ                                 0x07ffffffU
#define PAPRD_TRAIN_GAIN_SET4__WRITE                                0x07ffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET4_MACRO__ */


/* macros for BB_paprd_train_gain_set4 */
#define INST_BB_PAPRD_TRAIN_GAIN_SET4__NUM                                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set5 */
#ifndef __PAPRD_TRAIN_GAIN_SET5_MACRO__
#define __PAPRD_TRAIN_GAIN_SET5_MACRO__

/* macros for field paprd_gain_tbl_15 */
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_15__SHIFT                       0
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_15__WIDTH                       9
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_15__MASK              0x000001ffU
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_15__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_15__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_15__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_15__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field paprd_gain_tbl_16 */
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_16__SHIFT                       9
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_16__WIDTH                       9
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_16__MASK              0x0003fe00U
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_16__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_16__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_16__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_16__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field paprd_gain_tbl_17 */
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_17__SHIFT                      18
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_17__WIDTH                       9
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_17__MASK              0x07fc0000U
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_17__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_17__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_17__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PAPRD_TRAIN_GAIN_SET5__PAPRD_GAIN_TBL_17__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define PAPRD_TRAIN_GAIN_SET5__TYPE                                    uint32_t
#define PAPRD_TRAIN_GAIN_SET5__READ                                 0x07ffffffU
#define PAPRD_TRAIN_GAIN_SET5__WRITE                                0x07ffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET5_MACRO__ */


/* macros for BB_paprd_train_gain_set5 */
#define INST_BB_PAPRD_TRAIN_GAIN_SET5__NUM                                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set6 */
#ifndef __PAPRD_TRAIN_GAIN_SET6_MACRO__
#define __PAPRD_TRAIN_GAIN_SET6_MACRO__

/* macros for field paprd_gain_tbl_18 */
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_18__SHIFT                       0
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_18__WIDTH                       9
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_18__MASK              0x000001ffU
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_18__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_18__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_18__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_18__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field paprd_gain_tbl_19 */
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_19__SHIFT                       9
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_19__WIDTH                       9
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_19__MASK              0x0003fe00U
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_19__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_19__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_19__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_19__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field paprd_gain_tbl_20 */
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_20__SHIFT                      18
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_20__WIDTH                       9
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_20__MASK              0x07fc0000U
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_20__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_20__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_20__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PAPRD_TRAIN_GAIN_SET6__PAPRD_GAIN_TBL_20__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define PAPRD_TRAIN_GAIN_SET6__TYPE                                    uint32_t
#define PAPRD_TRAIN_GAIN_SET6__READ                                 0x07ffffffU
#define PAPRD_TRAIN_GAIN_SET6__WRITE                                0x07ffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET6_MACRO__ */


/* macros for BB_paprd_train_gain_set6 */
#define INST_BB_PAPRD_TRAIN_GAIN_SET6__NUM                                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set7 */
#ifndef __PAPRD_TRAIN_GAIN_SET7_MACRO__
#define __PAPRD_TRAIN_GAIN_SET7_MACRO__

/* macros for field paprd_gain_tbl_21 */
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_21__SHIFT                       0
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_21__WIDTH                       9
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_21__MASK              0x000001ffU
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_21__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_21__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_21__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_21__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field paprd_gain_tbl_22 */
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_22__SHIFT                       9
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_22__WIDTH                       9
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_22__MASK              0x0003fe00U
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_22__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_22__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_22__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_22__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field paprd_gain_tbl_23 */
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_23__SHIFT                      18
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_23__WIDTH                       9
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_23__MASK              0x07fc0000U
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_23__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_23__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_23__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PAPRD_TRAIN_GAIN_SET7__PAPRD_GAIN_TBL_23__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define PAPRD_TRAIN_GAIN_SET7__TYPE                                    uint32_t
#define PAPRD_TRAIN_GAIN_SET7__READ                                 0x07ffffffU
#define PAPRD_TRAIN_GAIN_SET7__WRITE                                0x07ffffffU

#endif /* __PAPRD_TRAIN_GAIN_SET7_MACRO__ */


/* macros for BB_paprd_train_gain_set7 */
#define INST_BB_PAPRD_TRAIN_GAIN_SET7__NUM                                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_set8 */
#ifndef __PAPRD_TRAIN_GAIN_SET8_MACRO__
#define __PAPRD_TRAIN_GAIN_SET8_MACRO__

/* macros for field paprd_gain_tbl_24 */
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_24__SHIFT                       0
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_24__WIDTH                       9
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_24__MASK              0x000001ffU
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_24__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_24__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_24__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PAPRD_TRAIN_GAIN_SET8__PAPRD_GAIN_TBL_24__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))
#define PAPRD_TRAIN_GAIN_SET8__TYPE                                    uint32_t
#define PAPRD_TRAIN_GAIN_SET8__READ                                 0x000001ffU
#define PAPRD_TRAIN_GAIN_SET8__WRITE                                0x000001ffU

#endif /* __PAPRD_TRAIN_GAIN_SET8_MACRO__ */


/* macros for BB_paprd_train_gain_set8 */
#define INST_BB_PAPRD_TRAIN_GAIN_SET8__NUM                                    1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_idx_set0 */
#ifndef __PAPRD_TRAIN_GAIN_IDX_SET0_MACRO__
#define __PAPRD_TRAIN_GAIN_IDX_SET0_MACRO__

/* macros for field paprd_gain_idx_0 */
#define PAPRD_TRAIN_GAIN_IDX_SET0__PAPRD_GAIN_IDX_0__SHIFT                    0
#define PAPRD_TRAIN_GAIN_IDX_SET0__PAPRD_GAIN_IDX_0__WIDTH                   32
#define PAPRD_TRAIN_GAIN_IDX_SET0__PAPRD_GAIN_IDX_0__MASK           0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET0__PAPRD_GAIN_IDX_0__READ(src) \
                    (uint32_t)(src)\
                    & 0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET0__PAPRD_GAIN_IDX_0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define PAPRD_TRAIN_GAIN_IDX_SET0__PAPRD_GAIN_IDX_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PAPRD_TRAIN_GAIN_IDX_SET0__PAPRD_GAIN_IDX_0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PAPRD_TRAIN_GAIN_IDX_SET0__TYPE                                uint32_t
#define PAPRD_TRAIN_GAIN_IDX_SET0__READ                             0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET0__WRITE                            0xffffffffU

#endif /* __PAPRD_TRAIN_GAIN_IDX_SET0_MACRO__ */


/* macros for BB_paprd_train_gain_idx_set0 */
#define INST_BB_PAPRD_TRAIN_GAIN_IDX_SET0__NUM                                1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_idx_set1 */
#ifndef __PAPRD_TRAIN_GAIN_IDX_SET1_MACRO__
#define __PAPRD_TRAIN_GAIN_IDX_SET1_MACRO__

/* macros for field paprd_gain_idx_1 */
#define PAPRD_TRAIN_GAIN_IDX_SET1__PAPRD_GAIN_IDX_1__SHIFT                    0
#define PAPRD_TRAIN_GAIN_IDX_SET1__PAPRD_GAIN_IDX_1__WIDTH                   32
#define PAPRD_TRAIN_GAIN_IDX_SET1__PAPRD_GAIN_IDX_1__MASK           0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET1__PAPRD_GAIN_IDX_1__READ(src) \
                    (uint32_t)(src)\
                    & 0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET1__PAPRD_GAIN_IDX_1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define PAPRD_TRAIN_GAIN_IDX_SET1__PAPRD_GAIN_IDX_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PAPRD_TRAIN_GAIN_IDX_SET1__PAPRD_GAIN_IDX_1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PAPRD_TRAIN_GAIN_IDX_SET1__TYPE                                uint32_t
#define PAPRD_TRAIN_GAIN_IDX_SET1__READ                             0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET1__WRITE                            0xffffffffU

#endif /* __PAPRD_TRAIN_GAIN_IDX_SET1_MACRO__ */


/* macros for BB_paprd_train_gain_idx_set1 */
#define INST_BB_PAPRD_TRAIN_GAIN_IDX_SET1__NUM                                1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_idx_set2 */
#ifndef __PAPRD_TRAIN_GAIN_IDX_SET2_MACRO__
#define __PAPRD_TRAIN_GAIN_IDX_SET2_MACRO__

/* macros for field paprd_gain_idx_2 */
#define PAPRD_TRAIN_GAIN_IDX_SET2__PAPRD_GAIN_IDX_2__SHIFT                    0
#define PAPRD_TRAIN_GAIN_IDX_SET2__PAPRD_GAIN_IDX_2__WIDTH                   32
#define PAPRD_TRAIN_GAIN_IDX_SET2__PAPRD_GAIN_IDX_2__MASK           0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET2__PAPRD_GAIN_IDX_2__READ(src) \
                    (uint32_t)(src)\
                    & 0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET2__PAPRD_GAIN_IDX_2__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define PAPRD_TRAIN_GAIN_IDX_SET2__PAPRD_GAIN_IDX_2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define PAPRD_TRAIN_GAIN_IDX_SET2__PAPRD_GAIN_IDX_2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define PAPRD_TRAIN_GAIN_IDX_SET2__TYPE                                uint32_t
#define PAPRD_TRAIN_GAIN_IDX_SET2__READ                             0xffffffffU
#define PAPRD_TRAIN_GAIN_IDX_SET2__WRITE                            0xffffffffU

#endif /* __PAPRD_TRAIN_GAIN_IDX_SET2_MACRO__ */


/* macros for BB_paprd_train_gain_idx_set2 */
#define INST_BB_PAPRD_TRAIN_GAIN_IDX_SET2__NUM                                1

/* macros for BlueprintGlobalNameSpace::paprd_train_gain_idx_set3 */
#ifndef __PAPRD_TRAIN_GAIN_IDX_SET3_MACRO__
#define __PAPRD_TRAIN_GAIN_IDX_SET3_MACRO__

/* macros for field paprd_gain_idx_3 */
#define PAPRD_TRAIN_GAIN_IDX_SET3__PAPRD_GAIN_IDX_3__SHIFT                    0
#define PAPRD_TRAIN_GAIN_IDX_SET3__PAPRD_GAIN_IDX_3__WIDTH                    4
#define PAPRD_TRAIN_GAIN_IDX_SET3__PAPRD_GAIN_IDX_3__MASK           0x0000000fU
#define PAPRD_TRAIN_GAIN_IDX_SET3__PAPRD_GAIN_IDX_3__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define PAPRD_TRAIN_GAIN_IDX_SET3__PAPRD_GAIN_IDX_3__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define PAPRD_TRAIN_GAIN_IDX_SET3__PAPRD_GAIN_IDX_3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define PAPRD_TRAIN_GAIN_IDX_SET3__PAPRD_GAIN_IDX_3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define PAPRD_TRAIN_GAIN_IDX_SET3__TYPE                                uint32_t
#define PAPRD_TRAIN_GAIN_IDX_SET3__READ                             0x0000000fU
#define PAPRD_TRAIN_GAIN_IDX_SET3__WRITE                            0x0000000fU

#endif /* __PAPRD_TRAIN_GAIN_IDX_SET3_MACRO__ */


/* macros for BB_paprd_train_gain_idx_set3 */
#define INST_BB_PAPRD_TRAIN_GAIN_IDX_SET3__NUM                                1

/* macros for BlueprintGlobalNameSpace::paprd_train_agc0 */
#ifndef __PAPRD_TRAIN_AGC0_MACRO__
#define __PAPRD_TRAIN_AGC0_MACRO__

/* macros for field paprd_pwr_high */
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_HIGH__SHIFT                               0
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_HIGH__WIDTH                               8
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_HIGH__MASK                      0x000000ffU
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_HIGH__READ(src) \
                    (uint32_t)(src)\
                    & 0x000000ffU
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_HIGH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_HIGH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))

/* macros for field paprd_pwr_low */
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_LOW__SHIFT                                8
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_LOW__WIDTH                                8
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_LOW__MASK                       0x0000ff00U
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_LOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_LOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_LOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))

/* macros for field paprd_pwr_weak */
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_WEAK__SHIFT                              16
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_WEAK__WIDTH                               8
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_WEAK__MASK                      0x00ff0000U
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_WEAK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_WEAK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_WEAK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define PAPRD_TRAIN_AGC0__PAPRD_PWR_WEAK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))

/* macros for field consec_pwr_low_cnt */
#define PAPRD_TRAIN_AGC0__CONSEC_PWR_LOW_CNT__SHIFT                          24
#define PAPRD_TRAIN_AGC0__CONSEC_PWR_LOW_CNT__WIDTH                           2
#define PAPRD_TRAIN_AGC0__CONSEC_PWR_LOW_CNT__MASK                  0x03000000U
#define PAPRD_TRAIN_AGC0__CONSEC_PWR_LOW_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define PAPRD_TRAIN_AGC0__CONSEC_PWR_LOW_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define PAPRD_TRAIN_AGC0__CONSEC_PWR_LOW_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define PAPRD_TRAIN_AGC0__CONSEC_PWR_LOW_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define PAPRD_TRAIN_AGC0__TYPE                                         uint32_t
#define PAPRD_TRAIN_AGC0__READ                                      0x03ffffffU
#define PAPRD_TRAIN_AGC0__WRITE                                     0x03ffffffU

#endif /* __PAPRD_TRAIN_AGC0_MACRO__ */


/* macros for BB_paprd_train_agc0 */
#define INST_BB_PAPRD_TRAIN_AGC0__NUM                                         1

/* macros for BlueprintGlobalNameSpace::paprd_train_agc1 */
#ifndef __PAPRD_TRAIN_AGC1_MACRO__
#define __PAPRD_TRAIN_AGC1_MACRO__

/* macros for field target_lvl_hi_db */
#define PAPRD_TRAIN_AGC1__TARGET_LVL_HI_DB__SHIFT                             0
#define PAPRD_TRAIN_AGC1__TARGET_LVL_HI_DB__WIDTH                             6
#define PAPRD_TRAIN_AGC1__TARGET_LVL_HI_DB__MASK                    0x0000003fU
#define PAPRD_TRAIN_AGC1__TARGET_LVL_HI_DB__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define PAPRD_TRAIN_AGC1__TARGET_LVL_HI_DB__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PAPRD_TRAIN_AGC1__TARGET_LVL_HI_DB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define PAPRD_TRAIN_AGC1__TARGET_LVL_HI_DB__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field target_lvl_low_db */
#define PAPRD_TRAIN_AGC1__TARGET_LVL_LOW_DB__SHIFT                            6
#define PAPRD_TRAIN_AGC1__TARGET_LVL_LOW_DB__WIDTH                            6
#define PAPRD_TRAIN_AGC1__TARGET_LVL_LOW_DB__MASK                   0x00000fc0U
#define PAPRD_TRAIN_AGC1__TARGET_LVL_LOW_DB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define PAPRD_TRAIN_AGC1__TARGET_LVL_LOW_DB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define PAPRD_TRAIN_AGC1__TARGET_LVL_LOW_DB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define PAPRD_TRAIN_AGC1__TARGET_LVL_LOW_DB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field target_lvl_weak_db */
#define PAPRD_TRAIN_AGC1__TARGET_LVL_WEAK_DB__SHIFT                          12
#define PAPRD_TRAIN_AGC1__TARGET_LVL_WEAK_DB__WIDTH                           6
#define PAPRD_TRAIN_AGC1__TARGET_LVL_WEAK_DB__MASK                  0x0003f000U
#define PAPRD_TRAIN_AGC1__TARGET_LVL_WEAK_DB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define PAPRD_TRAIN_AGC1__TARGET_LVL_WEAK_DB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define PAPRD_TRAIN_AGC1__TARGET_LVL_WEAK_DB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define PAPRD_TRAIN_AGC1__TARGET_LVL_WEAK_DB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))
#define PAPRD_TRAIN_AGC1__TYPE                                         uint32_t
#define PAPRD_TRAIN_AGC1__READ                                      0x0003ffffU
#define PAPRD_TRAIN_AGC1__WRITE                                     0x0003ffffU

#endif /* __PAPRD_TRAIN_AGC1_MACRO__ */


/* macros for BB_paprd_train_agc1 */
#define INST_BB_PAPRD_TRAIN_AGC1__NUM                                         1

/* macros for BlueprintGlobalNameSpace::paprd_train_qchk_acc_0 */
#ifndef __PAPRD_TRAIN_QCHK_ACC_0_MACRO__
#define __PAPRD_TRAIN_QCHK_ACC_0_MACRO__

/* macros for field paprd_qchk_acc_0 */
#define PAPRD_TRAIN_QCHK_ACC_0__PAPRD_QCHK_ACC_0__SHIFT                       0
#define PAPRD_TRAIN_QCHK_ACC_0__PAPRD_QCHK_ACC_0__WIDTH                      27
#define PAPRD_TRAIN_QCHK_ACC_0__PAPRD_QCHK_ACC_0__MASK              0x07ffffffU
#define PAPRD_TRAIN_QCHK_ACC_0__PAPRD_QCHK_ACC_0__READ(src) \
                    (uint32_t)(src)\
                    & 0x07ffffffU
#define PAPRD_TRAIN_QCHK_ACC_0__TYPE                                   uint32_t
#define PAPRD_TRAIN_QCHK_ACC_0__READ                                0x07ffffffU

#endif /* __PAPRD_TRAIN_QCHK_ACC_0_MACRO__ */


/* macros for BB_paprd_train_qchk_acc_0 */
#define INST_BB_PAPRD_TRAIN_QCHK_ACC_0__NUM                                   1

/* macros for BlueprintGlobalNameSpace::paprd_train_qchk_acc_1 */
#ifndef __PAPRD_TRAIN_QCHK_ACC_1_MACRO__
#define __PAPRD_TRAIN_QCHK_ACC_1_MACRO__

/* macros for field paprd_qchk_acc_1 */
#define PAPRD_TRAIN_QCHK_ACC_1__PAPRD_QCHK_ACC_1__SHIFT                       0
#define PAPRD_TRAIN_QCHK_ACC_1__PAPRD_QCHK_ACC_1__WIDTH                      27
#define PAPRD_TRAIN_QCHK_ACC_1__PAPRD_QCHK_ACC_1__MASK              0x07ffffffU
#define PAPRD_TRAIN_QCHK_ACC_1__PAPRD_QCHK_ACC_1__READ(src) \
                    (uint32_t)(src)\
                    & 0x07ffffffU
#define PAPRD_TRAIN_QCHK_ACC_1__TYPE                                   uint32_t
#define PAPRD_TRAIN_QCHK_ACC_1__READ                                0x07ffffffU

#endif /* __PAPRD_TRAIN_QCHK_ACC_1_MACRO__ */


/* macros for BB_paprd_train_qchk_acc_1 */
#define INST_BB_PAPRD_TRAIN_QCHK_ACC_1__NUM                                   1

/* macros for BlueprintGlobalNameSpace::paprd_train_qchk_acc_2 */
#ifndef __PAPRD_TRAIN_QCHK_ACC_2_MACRO__
#define __PAPRD_TRAIN_QCHK_ACC_2_MACRO__

/* macros for field paprd_qchk_acc_2 */
#define PAPRD_TRAIN_QCHK_ACC_2__PAPRD_QCHK_ACC_2__SHIFT                       0
#define PAPRD_TRAIN_QCHK_ACC_2__PAPRD_QCHK_ACC_2__WIDTH                      27
#define PAPRD_TRAIN_QCHK_ACC_2__PAPRD_QCHK_ACC_2__MASK              0x07ffffffU
#define PAPRD_TRAIN_QCHK_ACC_2__PAPRD_QCHK_ACC_2__READ(src) \
                    (uint32_t)(src)\
                    & 0x07ffffffU
#define PAPRD_TRAIN_QCHK_ACC_2__TYPE                                   uint32_t
#define PAPRD_TRAIN_QCHK_ACC_2__READ                                0x07ffffffU

#endif /* __PAPRD_TRAIN_QCHK_ACC_2_MACRO__ */


/* macros for BB_paprd_train_qchk_acc_2 */
#define INST_BB_PAPRD_TRAIN_QCHK_ACC_2__NUM                                   1

/* macros for BlueprintGlobalNameSpace::paprd_train_qchk_acc_3 */
#ifndef __PAPRD_TRAIN_QCHK_ACC_3_MACRO__
#define __PAPRD_TRAIN_QCHK_ACC_3_MACRO__

/* macros for field paprd_qchk_acc_3 */
#define PAPRD_TRAIN_QCHK_ACC_3__PAPRD_QCHK_ACC_3__SHIFT                       0
#define PAPRD_TRAIN_QCHK_ACC_3__PAPRD_QCHK_ACC_3__WIDTH                      27
#define PAPRD_TRAIN_QCHK_ACC_3__PAPRD_QCHK_ACC_3__MASK              0x07ffffffU
#define PAPRD_TRAIN_QCHK_ACC_3__PAPRD_QCHK_ACC_3__READ(src) \
                    (uint32_t)(src)\
                    & 0x07ffffffU
#define PAPRD_TRAIN_QCHK_ACC_3__TYPE                                   uint32_t
#define PAPRD_TRAIN_QCHK_ACC_3__READ                                0x07ffffffU

#endif /* __PAPRD_TRAIN_QCHK_ACC_3_MACRO__ */


/* macros for BB_paprd_train_qchk_acc_3 */
#define INST_BB_PAPRD_TRAIN_QCHK_ACC_3__NUM                                   1

/* macros for BlueprintGlobalNameSpace::paprd_train_qchk_data_0 */
#ifndef __PAPRD_TRAIN_QCHK_DATA_0_MACRO__
#define __PAPRD_TRAIN_QCHK_DATA_0_MACRO__

/* macros for field paprd_qchk_min_0 */
#define PAPRD_TRAIN_QCHK_DATA_0__PAPRD_QCHK_MIN_0__SHIFT                      0
#define PAPRD_TRAIN_QCHK_DATA_0__PAPRD_QCHK_MIN_0__WIDTH                     11
#define PAPRD_TRAIN_QCHK_DATA_0__PAPRD_QCHK_MIN_0__MASK             0x000007ffU
#define PAPRD_TRAIN_QCHK_DATA_0__PAPRD_QCHK_MIN_0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000007ffU

/* macros for field paprd_qchk_max_0 */
#define PAPRD_TRAIN_QCHK_DATA_0__PAPRD_QCHK_MAX_0__SHIFT                     11
#define PAPRD_TRAIN_QCHK_DATA_0__PAPRD_QCHK_MAX_0__WIDTH                     11
#define PAPRD_TRAIN_QCHK_DATA_0__PAPRD_QCHK_MAX_0__MASK             0x003ff800U
#define PAPRD_TRAIN_QCHK_DATA_0__PAPRD_QCHK_MAX_0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003ff800U) >> 11)
#define PAPRD_TRAIN_QCHK_DATA_0__TYPE                                  uint32_t
#define PAPRD_TRAIN_QCHK_DATA_0__READ                               0x003fffffU

#endif /* __PAPRD_TRAIN_QCHK_DATA_0_MACRO__ */


/* macros for BB_paprd_train_qchk_data_0 */
#define INST_BB_PAPRD_TRAIN_QCHK_DATA_0__NUM                                  1

/* macros for BlueprintGlobalNameSpace::paprd_train_qchk_data_1 */
#ifndef __PAPRD_TRAIN_QCHK_DATA_1_MACRO__
#define __PAPRD_TRAIN_QCHK_DATA_1_MACRO__

/* macros for field paprd_qchk_min_1 */
#define PAPRD_TRAIN_QCHK_DATA_1__PAPRD_QCHK_MIN_1__SHIFT                      0
#define PAPRD_TRAIN_QCHK_DATA_1__PAPRD_QCHK_MIN_1__WIDTH                     11
#define PAPRD_TRAIN_QCHK_DATA_1__PAPRD_QCHK_MIN_1__MASK             0x000007ffU
#define PAPRD_TRAIN_QCHK_DATA_1__PAPRD_QCHK_MIN_1__READ(src) \
                    (uint32_t)(src)\
                    & 0x000007ffU

/* macros for field paprd_qchk_max_1 */
#define PAPRD_TRAIN_QCHK_DATA_1__PAPRD_QCHK_MAX_1__SHIFT                     11
#define PAPRD_TRAIN_QCHK_DATA_1__PAPRD_QCHK_MAX_1__WIDTH                     11
#define PAPRD_TRAIN_QCHK_DATA_1__PAPRD_QCHK_MAX_1__MASK             0x003ff800U
#define PAPRD_TRAIN_QCHK_DATA_1__PAPRD_QCHK_MAX_1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003ff800U) >> 11)
#define PAPRD_TRAIN_QCHK_DATA_1__TYPE                                  uint32_t
#define PAPRD_TRAIN_QCHK_DATA_1__READ                               0x003fffffU

#endif /* __PAPRD_TRAIN_QCHK_DATA_1_MACRO__ */


/* macros for BB_paprd_train_qchk_data_1 */
#define INST_BB_PAPRD_TRAIN_QCHK_DATA_1__NUM                                  1

/* macros for BlueprintGlobalNameSpace::paprd_train_qchk_data_2 */
#ifndef __PAPRD_TRAIN_QCHK_DATA_2_MACRO__
#define __PAPRD_TRAIN_QCHK_DATA_2_MACRO__

/* macros for field paprd_qchk_min_2 */
#define PAPRD_TRAIN_QCHK_DATA_2__PAPRD_QCHK_MIN_2__SHIFT                      0
#define PAPRD_TRAIN_QCHK_DATA_2__PAPRD_QCHK_MIN_2__WIDTH                     11
#define PAPRD_TRAIN_QCHK_DATA_2__PAPRD_QCHK_MIN_2__MASK             0x000007ffU
#define PAPRD_TRAIN_QCHK_DATA_2__PAPRD_QCHK_MIN_2__READ(src) \
                    (uint32_t)(src)\
                    & 0x000007ffU

/* macros for field paprd_qchk_max_2 */
#define PAPRD_TRAIN_QCHK_DATA_2__PAPRD_QCHK_MAX_2__SHIFT                     11
#define PAPRD_TRAIN_QCHK_DATA_2__PAPRD_QCHK_MAX_2__WIDTH                     11
#define PAPRD_TRAIN_QCHK_DATA_2__PAPRD_QCHK_MAX_2__MASK             0x003ff800U
#define PAPRD_TRAIN_QCHK_DATA_2__PAPRD_QCHK_MAX_2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003ff800U) >> 11)
#define PAPRD_TRAIN_QCHK_DATA_2__TYPE                                  uint32_t
#define PAPRD_TRAIN_QCHK_DATA_2__READ                               0x003fffffU

#endif /* __PAPRD_TRAIN_QCHK_DATA_2_MACRO__ */


/* macros for BB_paprd_train_qchk_data_2 */
#define INST_BB_PAPRD_TRAIN_QCHK_DATA_2__NUM                                  1

/* macros for BlueprintGlobalNameSpace::paprd_train_qchk_data_3 */
#ifndef __PAPRD_TRAIN_QCHK_DATA_3_MACRO__
#define __PAPRD_TRAIN_QCHK_DATA_3_MACRO__

/* macros for field paprd_qchk_min_3 */
#define PAPRD_TRAIN_QCHK_DATA_3__PAPRD_QCHK_MIN_3__SHIFT                      0
#define PAPRD_TRAIN_QCHK_DATA_3__PAPRD_QCHK_MIN_3__WIDTH                     11
#define PAPRD_TRAIN_QCHK_DATA_3__PAPRD_QCHK_MIN_3__MASK             0x000007ffU
#define PAPRD_TRAIN_QCHK_DATA_3__PAPRD_QCHK_MIN_3__READ(src) \
                    (uint32_t)(src)\
                    & 0x000007ffU

/* macros for field paprd_qchk_max_3 */
#define PAPRD_TRAIN_QCHK_DATA_3__PAPRD_QCHK_MAX_3__SHIFT                     11
#define PAPRD_TRAIN_QCHK_DATA_3__PAPRD_QCHK_MAX_3__WIDTH                     11
#define PAPRD_TRAIN_QCHK_DATA_3__PAPRD_QCHK_MAX_3__MASK             0x003ff800U
#define PAPRD_TRAIN_QCHK_DATA_3__PAPRD_QCHK_MAX_3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003ff800U) >> 11)
#define PAPRD_TRAIN_QCHK_DATA_3__TYPE                                  uint32_t
#define PAPRD_TRAIN_QCHK_DATA_3__READ                               0x003fffffU

#endif /* __PAPRD_TRAIN_QCHK_DATA_3_MACRO__ */


/* macros for BB_paprd_train_qchk_data_3 */
#define INST_BB_PAPRD_TRAIN_QCHK_DATA_3__NUM                                  1

/* macros for BlueprintGlobalNameSpace::paprd_train_mem */
#ifndef __PAPRD_TRAIN_MEM_MACRO__
#define __PAPRD_TRAIN_MEM_MACRO__

/* macros for field paprd_trn_data */
#define PAPRD_TRAIN_MEM__PAPRD_TRN_DATA__SHIFT                                0
#define PAPRD_TRAIN_MEM__PAPRD_TRN_DATA__WIDTH                               32
#define PAPRD_TRAIN_MEM__PAPRD_TRN_DATA__MASK                       0xffffffffU
#define PAPRD_TRAIN_MEM__PAPRD_TRN_DATA__READ(src) \
                    (uint32_t)(src)\
                    & 0xffffffffU
#define PAPRD_TRAIN_MEM__TYPE                                          uint32_t
#define PAPRD_TRAIN_MEM__READ                                       0xffffffffU

#endif /* __PAPRD_TRAIN_MEM_MACRO__ */


/* macros for BB_paprd_train_mem */
#define INST_BB_PAPRD_TRAIN_MEM__NUM                                        576

/* macros for BlueprintGlobalNameSpace::normtx_txiq_corr_coeff_b0 */
#ifndef __NORMTX_TXIQ_CORR_COEFF_B0_MACRO__
#define __NORMTX_TXIQ_CORR_COEFF_B0_MACRO__

/* macros for field normtx_iqc_coeff_table_chn0 */
#define NORMTX_TXIQ_CORR_COEFF_B0__NORMTX_IQC_COEFF_TABLE_CHN0__SHIFT         0
#define NORMTX_TXIQ_CORR_COEFF_B0__NORMTX_IQC_COEFF_TABLE_CHN0__WIDTH        18
#define NORMTX_TXIQ_CORR_COEFF_B0__NORMTX_IQC_COEFF_TABLE_CHN0__MASK \
                    0x0003ffffU
#define NORMTX_TXIQ_CORR_COEFF_B0__NORMTX_IQC_COEFF_TABLE_CHN0__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define NORMTX_TXIQ_CORR_COEFF_B0__NORMTX_IQC_COEFF_TABLE_CHN0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define NORMTX_TXIQ_CORR_COEFF_B0__NORMTX_IQC_COEFF_TABLE_CHN0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define NORMTX_TXIQ_CORR_COEFF_B0__NORMTX_IQC_COEFF_TABLE_CHN0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define NORMTX_TXIQ_CORR_COEFF_B0__TYPE                                uint32_t
#define NORMTX_TXIQ_CORR_COEFF_B0__READ                             0x0003ffffU
#define NORMTX_TXIQ_CORR_COEFF_B0__WRITE                            0x0003ffffU

#endif /* __NORMTX_TXIQ_CORR_COEFF_B0_MACRO__ */


/* macros for BB_normtx_txiq_corr_coeff_b0 */
#define INST_BB_NORMTX_TXIQ_CORR_COEFF_B0__NUM                              160

/* macros for BlueprintGlobalNameSpace::chn_tables_dummy_1 */
#ifndef __CHN_TABLES_DUMMY_1_MACRO__
#define __CHN_TABLES_DUMMY_1_MACRO__

/* macros for field dummy1 */
#define CHN_TABLES_DUMMY_1__DUMMY1__SHIFT                                     0
#define CHN_TABLES_DUMMY_1__DUMMY1__WIDTH                                    32
#define CHN_TABLES_DUMMY_1__DUMMY1__MASK                            0xffffffffU
#define CHN_TABLES_DUMMY_1__DUMMY1__READ(src)     (uint32_t)(src) & 0xffffffffU
#define CHN_TABLES_DUMMY_1__DUMMY1__WRITE(src)  ((uint32_t)(src) & 0xffffffffU)
#define CHN_TABLES_DUMMY_1__DUMMY1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define CHN_TABLES_DUMMY_1__DUMMY1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define CHN_TABLES_DUMMY_1__TYPE                                       uint32_t
#define CHN_TABLES_DUMMY_1__READ                                    0xffffffffU
#define CHN_TABLES_DUMMY_1__WRITE                                   0xffffffffU

#endif /* __CHN_TABLES_DUMMY_1_MACRO__ */


/* macros for BB_chn_tables_dummy_1 */
#define INST_BB_CHN_TABLES_DUMMY_1__NUM                                       1

#define CHN_TABLE_MAP__VERSION \
                    "/cad/denali/blueprint/3.7.3/gen/ansic.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html2docbook.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html2sgml.pm\n\
                    /cad/local/lib/perl/Pinfo.pm\n\
                    /trees/yflee/yflee-dev/ip/athr/wifi/dev/rtl/bb/blueprint/chn_table_map.rdl"
#endif /* __REG_CHN_TABLE_MAP_MACRO_H__ */
