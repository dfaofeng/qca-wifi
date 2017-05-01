/*                                                                           */
/* File:       chn1_table_map_macro.h                                        */
/* Creator:    yflee                                                         */
/* Time:       Thursday May 3, 2012 [6:54:05 pm]                             */
/*                                                                           */
/* Path:       /trees/yflee/yflee-dev/ip/athr/wifi/dev/rtl/bb/blueprint      */
/* Arguments:  /cad/denali/blueprint/3.7.3//Linux-64bit/blueprint -codegen   */
/*             verilogExtension.codegen -html -nojava -verilogExtension -vh  */
/*             -ansic chn1_table_map.rdl                                     */
/*                                                                           */
/* Sources:    /trees/yflee/yflee-dev/ip/athr/wifi/dev/rtl/bb/blueprint/chn1_table_map.rdl*/
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


#ifndef __REG_CHN1_TABLE_MAP_MACRO_H__
#define __REG_CHN1_TABLE_MAP_MACRO_H__


/* macros for BlueprintGlobalNameSpace::paprd_power_at_am2am_cal_b1 */
#ifndef __PAPRD_POWER_AT_AM2AM_CAL_B1_MACRO__
#define __PAPRD_POWER_AT_AM2AM_CAL_B1_MACRO__

/* macros for field paprd_power_at_am2am_cal_0_b1 */
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_0_B1__SHIFT     0
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_0_B1__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_0_B1__MASK \
                    0x0000003fU
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_0_B1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_0_B1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_0_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_0_B1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field paprd_power_at_am2am_cal_1_b1 */
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_1_B1__SHIFT     6
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_1_B1__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_1_B1__MASK \
                    0x00000fc0U
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_1_B1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_1_B1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_1_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_1_B1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field paprd_power_at_am2am_cal_2_b1 */
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_2_B1__SHIFT    12
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_2_B1__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_2_B1__MASK \
                    0x0003f000U
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_2_B1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_2_B1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_2_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_2_B1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field paprd_power_at_am2am_cal_3_b1 */
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_3_B1__SHIFT    18
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_3_B1__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_3_B1__MASK \
                    0x00fc0000U
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_3_B1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_3_B1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00fc0000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_3_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x00fc0000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_3_B1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00fc0000U)))

/* macros for field paprd_power_at_am2am_cal_4_b1 */
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_4_B1__SHIFT    24
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_4_B1__WIDTH     6
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_4_B1__MASK \
                    0x3f000000U
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_4_B1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_4_B1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_4_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define PAPRD_POWER_AT_AM2AM_CAL_B1__PAPRD_POWER_AT_AM2AM_CAL_4_B1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define PAPRD_POWER_AT_AM2AM_CAL_B1__TYPE                              uint32_t
#define PAPRD_POWER_AT_AM2AM_CAL_B1__READ                           0x3fffffffU
#define PAPRD_POWER_AT_AM2AM_CAL_B1__WRITE                          0x3fffffffU

#endif /* __PAPRD_POWER_AT_AM2AM_CAL_B1_MACRO__ */


/* macros for BB_paprd_power_at_am2am_cal_b1 */
#define INST_BB_PAPRD_POWER_AT_AM2AM_CAL_B1__NUM                              1

/* macros for BlueprintGlobalNameSpace::paprd_valid_obdb_b1 */
#ifndef __PAPRD_VALID_OBDB_B1_MACRO__
#define __PAPRD_VALID_OBDB_B1_MACRO__

/* macros for field paprd_valid_obdb_0_b1 */
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_0_B1__SHIFT                     0
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_0_B1__WIDTH                     6
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_0_B1__MASK            0x0000003fU
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_0_B1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_0_B1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_0_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_0_B1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field paprd_valid_obdb_1_b1 */
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_1_B1__SHIFT                     6
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_1_B1__WIDTH                     6
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_1_B1__MASK            0x00000fc0U
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_1_B1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_1_B1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_1_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_1_B1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))

/* macros for field paprd_valid_obdb_2_b1 */
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_2_B1__SHIFT                    12
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_2_B1__WIDTH                     6
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_2_B1__MASK            0x0003f000U
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_2_B1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_2_B1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_2_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_2_B1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))

/* macros for field paprd_valid_obdb_3_b1 */
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_3_B1__SHIFT                    18
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_3_B1__WIDTH                     6
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_3_B1__MASK            0x00fc0000U
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_3_B1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_3_B1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00fc0000U)
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_3_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x00fc0000U)
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_3_B1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00fc0000U)))

/* macros for field paprd_valid_obdb_4_b1 */
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_4_B1__SHIFT                    24
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_4_B1__WIDTH                     6
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_4_B1__MASK            0x3f000000U
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_4_B1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_4_B1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_4_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define PAPRD_VALID_OBDB_B1__PAPRD_VALID_OBDB_4_B1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define PAPRD_VALID_OBDB_B1__TYPE                                      uint32_t
#define PAPRD_VALID_OBDB_B1__READ                                   0x3fffffffU
#define PAPRD_VALID_OBDB_B1__WRITE                                  0x3fffffffU

#endif /* __PAPRD_VALID_OBDB_B1_MACRO__ */


/* macros for BB_paprd_valid_obdb_b1 */
#define INST_BB_PAPRD_VALID_OBDB_B1__NUM                                      1

/* macros for BlueprintGlobalNameSpace::chn1_tables_dummy_2 */
#ifndef __CHN1_TABLES_DUMMY_2_MACRO__
#define __CHN1_TABLES_DUMMY_2_MACRO__

/* macros for field dummy2 */
#define CHN1_TABLES_DUMMY_2__DUMMY2__SHIFT                                    0
#define CHN1_TABLES_DUMMY_2__DUMMY2__WIDTH                                   32
#define CHN1_TABLES_DUMMY_2__DUMMY2__MASK                           0xffffffffU
#define CHN1_TABLES_DUMMY_2__DUMMY2__READ(src)    (uint32_t)(src) & 0xffffffffU
#define CHN1_TABLES_DUMMY_2__DUMMY2__WRITE(src) ((uint32_t)(src) & 0xffffffffU)
#define CHN1_TABLES_DUMMY_2__DUMMY2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define CHN1_TABLES_DUMMY_2__DUMMY2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define CHN1_TABLES_DUMMY_2__TYPE                                      uint32_t
#define CHN1_TABLES_DUMMY_2__READ                                   0xffffffffU
#define CHN1_TABLES_DUMMY_2__WRITE                                  0xffffffffU

#endif /* __CHN1_TABLES_DUMMY_2_MACRO__ */


/* macros for BB_chn1_tables_dummy_2 */
#define INST_BB_CHN1_TABLES_DUMMY_2__NUM                                      1

/* macros for BlueprintGlobalNameSpace::txiqcorr_txpath_coef_b1 */
#ifndef __TXIQCORR_TXPATH_COEF_B1_MACRO__
#define __TXIQCORR_TXPATH_COEF_B1_MACRO__

/* macros for field txiqcorr_txpath_coef_chn1 */
#define TXIQCORR_TXPATH_COEF_B1__TXIQCORR_TXPATH_COEF_CHN1__SHIFT             0
#define TXIQCORR_TXPATH_COEF_B1__TXIQCORR_TXPATH_COEF_CHN1__WIDTH            18
#define TXIQCORR_TXPATH_COEF_B1__TXIQCORR_TXPATH_COEF_CHN1__MASK    0x0003ffffU
#define TXIQCORR_TXPATH_COEF_B1__TXIQCORR_TXPATH_COEF_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define TXIQCORR_TXPATH_COEF_B1__TXIQCORR_TXPATH_COEF_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define TXIQCORR_TXPATH_COEF_B1__TXIQCORR_TXPATH_COEF_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define TXIQCORR_TXPATH_COEF_B1__TXIQCORR_TXPATH_COEF_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define TXIQCORR_TXPATH_COEF_B1__TYPE                                  uint32_t
#define TXIQCORR_TXPATH_COEF_B1__READ                               0x0003ffffU
#define TXIQCORR_TXPATH_COEF_B1__WRITE                              0x0003ffffU

#endif /* __TXIQCORR_TXPATH_COEF_B1_MACRO__ */


/* macros for BB_txiqcorr_txpath_coef_b1 */
#define INST_BB_TXIQCORR_TXPATH_COEF_B1__NUM                                 16

/* macros for BlueprintGlobalNameSpace::txiqcorr_rxpath_coef_b1 */
#ifndef __TXIQCORR_RXPATH_COEF_B1_MACRO__
#define __TXIQCORR_RXPATH_COEF_B1_MACRO__

/* macros for field txiqcorr_rxpath_coef_chn1 */
#define TXIQCORR_RXPATH_COEF_B1__TXIQCORR_RXPATH_COEF_CHN1__SHIFT             0
#define TXIQCORR_RXPATH_COEF_B1__TXIQCORR_RXPATH_COEF_CHN1__WIDTH            18
#define TXIQCORR_RXPATH_COEF_B1__TXIQCORR_RXPATH_COEF_CHN1__MASK    0x0003ffffU
#define TXIQCORR_RXPATH_COEF_B1__TXIQCORR_RXPATH_COEF_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define TXIQCORR_RXPATH_COEF_B1__TXIQCORR_RXPATH_COEF_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define TXIQCORR_RXPATH_COEF_B1__TXIQCORR_RXPATH_COEF_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define TXIQCORR_RXPATH_COEF_B1__TXIQCORR_RXPATH_COEF_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define TXIQCORR_RXPATH_COEF_B1__TYPE                                  uint32_t
#define TXIQCORR_RXPATH_COEF_B1__READ                               0x0003ffffU
#define TXIQCORR_RXPATH_COEF_B1__WRITE                              0x0003ffffU

#endif /* __TXIQCORR_RXPATH_COEF_B1_MACRO__ */


/* macros for BB_txiqcorr_rxpath_coef_b1 */
#define INST_BB_TXIQCORR_RXPATH_COEF_B1__NUM                                 16

/* macros for BlueprintGlobalNameSpace::rxiqcorr_rxpath_coef_b1 */
#ifndef __RXIQCORR_RXPATH_COEF_B1_MACRO__
#define __RXIQCORR_RXPATH_COEF_B1_MACRO__

/* macros for field rxiqcorr_rxpath_coef_chn1 */
#define RXIQCORR_RXPATH_COEF_B1__RXIQCORR_RXPATH_COEF_CHN1__SHIFT             0
#define RXIQCORR_RXPATH_COEF_B1__RXIQCORR_RXPATH_COEF_CHN1__WIDTH            18
#define RXIQCORR_RXPATH_COEF_B1__RXIQCORR_RXPATH_COEF_CHN1__MASK    0x0003ffffU
#define RXIQCORR_RXPATH_COEF_B1__RXIQCORR_RXPATH_COEF_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define RXIQCORR_RXPATH_COEF_B1__RXIQCORR_RXPATH_COEF_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define RXIQCORR_RXPATH_COEF_B1__RXIQCORR_RXPATH_COEF_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define RXIQCORR_RXPATH_COEF_B1__RXIQCORR_RXPATH_COEF_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define RXIQCORR_RXPATH_COEF_B1__TYPE                                  uint32_t
#define RXIQCORR_RXPATH_COEF_B1__READ                               0x0003ffffU
#define RXIQCORR_RXPATH_COEF_B1__WRITE                              0x0003ffffU

#endif /* __RXIQCORR_RXPATH_COEF_B1_MACRO__ */


/* macros for BB_rxiqcorr_rxpath_coef_b1 */
#define INST_BB_RXIQCORR_RXPATH_COEF_B1__NUM                                 16

/* macros for BlueprintGlobalNameSpace::rxiqcorr_txpath_coef_b1 */
#ifndef __RXIQCORR_TXPATH_COEF_B1_MACRO__
#define __RXIQCORR_TXPATH_COEF_B1_MACRO__

/* macros for field rxiqcorr_txpath_coef_chn1 */
#define RXIQCORR_TXPATH_COEF_B1__RXIQCORR_TXPATH_COEF_CHN1__SHIFT             0
#define RXIQCORR_TXPATH_COEF_B1__RXIQCORR_TXPATH_COEF_CHN1__WIDTH            18
#define RXIQCORR_TXPATH_COEF_B1__RXIQCORR_TXPATH_COEF_CHN1__MASK    0x0003ffffU
#define RXIQCORR_TXPATH_COEF_B1__RXIQCORR_TXPATH_COEF_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define RXIQCORR_TXPATH_COEF_B1__RXIQCORR_TXPATH_COEF_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define RXIQCORR_TXPATH_COEF_B1__RXIQCORR_TXPATH_COEF_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define RXIQCORR_TXPATH_COEF_B1__RXIQCORR_TXPATH_COEF_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define RXIQCORR_TXPATH_COEF_B1__TYPE                                  uint32_t
#define RXIQCORR_TXPATH_COEF_B1__READ                               0x0003ffffU
#define RXIQCORR_TXPATH_COEF_B1__WRITE                              0x0003ffffU

#endif /* __RXIQCORR_TXPATH_COEF_B1_MACRO__ */


/* macros for BB_rxiqcorr_txpath_coef_b1 */
#define INST_BB_RXIQCORR_TXPATH_COEF_B1__NUM                                 16

/* macros for BlueprintGlobalNameSpace::rxcal_tx_gain_table_b1 */
#ifndef __RXCAL_TX_GAIN_TABLE_B1_MACRO__
#define __RXCAL_TX_GAIN_TABLE_B1_MACRO__

/* macros for field rxcal_tx_gain_table_chn1 */
#define RXCAL_TX_GAIN_TABLE_B1__RXCAL_TX_GAIN_TABLE_CHN1__SHIFT               0
#define RXCAL_TX_GAIN_TABLE_B1__RXCAL_TX_GAIN_TABLE_CHN1__WIDTH              20
#define RXCAL_TX_GAIN_TABLE_B1__RXCAL_TX_GAIN_TABLE_CHN1__MASK      0x000fffffU
#define RXCAL_TX_GAIN_TABLE_B1__RXCAL_TX_GAIN_TABLE_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x000fffffU
#define RXCAL_TX_GAIN_TABLE_B1__RXCAL_TX_GAIN_TABLE_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000fffffU)
#define RXCAL_TX_GAIN_TABLE_B1__RXCAL_TX_GAIN_TABLE_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000fffffU) | ((uint32_t)(src) &\
                    0x000fffffU)
#define RXCAL_TX_GAIN_TABLE_B1__RXCAL_TX_GAIN_TABLE_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000fffffU)))
#define RXCAL_TX_GAIN_TABLE_B1__TYPE                                   uint32_t
#define RXCAL_TX_GAIN_TABLE_B1__READ                                0x000fffffU
#define RXCAL_TX_GAIN_TABLE_B1__WRITE                               0x000fffffU

#endif /* __RXCAL_TX_GAIN_TABLE_B1_MACRO__ */


/* macros for BB_rxcal_tx_gain_table_b1 */
#define INST_BB_RXCAL_TX_GAIN_TABLE_B1__NUM                                  32

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_1_0_b1 */
#ifndef __RXCAL_RX_GAIN_TABLE_1_0_B1_MACRO__
#define __RXCAL_RX_GAIN_TABLE_1_0_B1_MACRO__

/* macros for field rxcal_rx_gain_table_0_chn1 */
#define RXCAL_RX_GAIN_TABLE_1_0_B1__RXCAL_RX_GAIN_TABLE_0_CHN1__SHIFT         0
#define RXCAL_RX_GAIN_TABLE_1_0_B1__RXCAL_RX_GAIN_TABLE_0_CHN1__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_1_0_B1__RXCAL_RX_GAIN_TABLE_0_CHN1__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_1_0_B1__RXCAL_RX_GAIN_TABLE_0_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_1_0_B1__RXCAL_RX_GAIN_TABLE_0_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_1_0_B1__RXCAL_RX_GAIN_TABLE_0_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_1_0_B1__RXCAL_RX_GAIN_TABLE_0_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_1_chn1 */
#define RXCAL_RX_GAIN_TABLE_1_0_B1__RXCAL_RX_GAIN_TABLE_1_CHN1__SHIFT        16
#define RXCAL_RX_GAIN_TABLE_1_0_B1__RXCAL_RX_GAIN_TABLE_1_CHN1__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_1_0_B1__RXCAL_RX_GAIN_TABLE_1_CHN1__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_1_0_B1__RXCAL_RX_GAIN_TABLE_1_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_1_0_B1__RXCAL_RX_GAIN_TABLE_1_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_1_0_B1__RXCAL_RX_GAIN_TABLE_1_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_1_0_B1__RXCAL_RX_GAIN_TABLE_1_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_1_0_B1__TYPE                               uint32_t
#define RXCAL_RX_GAIN_TABLE_1_0_B1__READ                            0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_1_0_B1__WRITE                           0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_1_0_B1_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_1_0_b1 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_1_0_B1__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_3_2_b1 */
#ifndef __RXCAL_RX_GAIN_TABLE_3_2_B1_MACRO__
#define __RXCAL_RX_GAIN_TABLE_3_2_B1_MACRO__

/* macros for field rxcal_rx_gain_table_2_chn1 */
#define RXCAL_RX_GAIN_TABLE_3_2_B1__RXCAL_RX_GAIN_TABLE_2_CHN1__SHIFT         0
#define RXCAL_RX_GAIN_TABLE_3_2_B1__RXCAL_RX_GAIN_TABLE_2_CHN1__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_3_2_B1__RXCAL_RX_GAIN_TABLE_2_CHN1__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_3_2_B1__RXCAL_RX_GAIN_TABLE_2_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_3_2_B1__RXCAL_RX_GAIN_TABLE_2_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_3_2_B1__RXCAL_RX_GAIN_TABLE_2_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_3_2_B1__RXCAL_RX_GAIN_TABLE_2_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_3_chn1 */
#define RXCAL_RX_GAIN_TABLE_3_2_B1__RXCAL_RX_GAIN_TABLE_3_CHN1__SHIFT        16
#define RXCAL_RX_GAIN_TABLE_3_2_B1__RXCAL_RX_GAIN_TABLE_3_CHN1__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_3_2_B1__RXCAL_RX_GAIN_TABLE_3_CHN1__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_3_2_B1__RXCAL_RX_GAIN_TABLE_3_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_3_2_B1__RXCAL_RX_GAIN_TABLE_3_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_3_2_B1__RXCAL_RX_GAIN_TABLE_3_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_3_2_B1__RXCAL_RX_GAIN_TABLE_3_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_3_2_B1__TYPE                               uint32_t
#define RXCAL_RX_GAIN_TABLE_3_2_B1__READ                            0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_3_2_B1__WRITE                           0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_3_2_B1_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_3_2_b1 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_3_2_B1__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_5_4_b1 */
#ifndef __RXCAL_RX_GAIN_TABLE_5_4_B1_MACRO__
#define __RXCAL_RX_GAIN_TABLE_5_4_B1_MACRO__

/* macros for field rxcal_rx_gain_table_4_chn1 */
#define RXCAL_RX_GAIN_TABLE_5_4_B1__RXCAL_RX_GAIN_TABLE_4_CHN1__SHIFT         0
#define RXCAL_RX_GAIN_TABLE_5_4_B1__RXCAL_RX_GAIN_TABLE_4_CHN1__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_5_4_B1__RXCAL_RX_GAIN_TABLE_4_CHN1__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_5_4_B1__RXCAL_RX_GAIN_TABLE_4_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_5_4_B1__RXCAL_RX_GAIN_TABLE_4_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_5_4_B1__RXCAL_RX_GAIN_TABLE_4_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_5_4_B1__RXCAL_RX_GAIN_TABLE_4_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_5_chn1 */
#define RXCAL_RX_GAIN_TABLE_5_4_B1__RXCAL_RX_GAIN_TABLE_5_CHN1__SHIFT        16
#define RXCAL_RX_GAIN_TABLE_5_4_B1__RXCAL_RX_GAIN_TABLE_5_CHN1__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_5_4_B1__RXCAL_RX_GAIN_TABLE_5_CHN1__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_5_4_B1__RXCAL_RX_GAIN_TABLE_5_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_5_4_B1__RXCAL_RX_GAIN_TABLE_5_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_5_4_B1__RXCAL_RX_GAIN_TABLE_5_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_5_4_B1__RXCAL_RX_GAIN_TABLE_5_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_5_4_B1__TYPE                               uint32_t
#define RXCAL_RX_GAIN_TABLE_5_4_B1__READ                            0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_5_4_B1__WRITE                           0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_5_4_B1_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_5_4_b1 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_5_4_B1__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_7_6_b1 */
#ifndef __RXCAL_RX_GAIN_TABLE_7_6_B1_MACRO__
#define __RXCAL_RX_GAIN_TABLE_7_6_B1_MACRO__

/* macros for field rxcal_rx_gain_table_6_chn1 */
#define RXCAL_RX_GAIN_TABLE_7_6_B1__RXCAL_RX_GAIN_TABLE_6_CHN1__SHIFT         0
#define RXCAL_RX_GAIN_TABLE_7_6_B1__RXCAL_RX_GAIN_TABLE_6_CHN1__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_7_6_B1__RXCAL_RX_GAIN_TABLE_6_CHN1__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_7_6_B1__RXCAL_RX_GAIN_TABLE_6_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_7_6_B1__RXCAL_RX_GAIN_TABLE_6_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_7_6_B1__RXCAL_RX_GAIN_TABLE_6_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_7_6_B1__RXCAL_RX_GAIN_TABLE_6_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_7_chn1 */
#define RXCAL_RX_GAIN_TABLE_7_6_B1__RXCAL_RX_GAIN_TABLE_7_CHN1__SHIFT        16
#define RXCAL_RX_GAIN_TABLE_7_6_B1__RXCAL_RX_GAIN_TABLE_7_CHN1__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_7_6_B1__RXCAL_RX_GAIN_TABLE_7_CHN1__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_7_6_B1__RXCAL_RX_GAIN_TABLE_7_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_7_6_B1__RXCAL_RX_GAIN_TABLE_7_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_7_6_B1__RXCAL_RX_GAIN_TABLE_7_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_7_6_B1__RXCAL_RX_GAIN_TABLE_7_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_7_6_B1__TYPE                               uint32_t
#define RXCAL_RX_GAIN_TABLE_7_6_B1__READ                            0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_7_6_B1__WRITE                           0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_7_6_B1_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_7_6_b1 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_7_6_B1__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_9_8_b1 */
#ifndef __RXCAL_RX_GAIN_TABLE_9_8_B1_MACRO__
#define __RXCAL_RX_GAIN_TABLE_9_8_B1_MACRO__

/* macros for field rxcal_rx_gain_table_8_chn1 */
#define RXCAL_RX_GAIN_TABLE_9_8_B1__RXCAL_RX_GAIN_TABLE_8_CHN1__SHIFT         0
#define RXCAL_RX_GAIN_TABLE_9_8_B1__RXCAL_RX_GAIN_TABLE_8_CHN1__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_9_8_B1__RXCAL_RX_GAIN_TABLE_8_CHN1__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_9_8_B1__RXCAL_RX_GAIN_TABLE_8_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_9_8_B1__RXCAL_RX_GAIN_TABLE_8_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_9_8_B1__RXCAL_RX_GAIN_TABLE_8_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_9_8_B1__RXCAL_RX_GAIN_TABLE_8_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_9_chn1 */
#define RXCAL_RX_GAIN_TABLE_9_8_B1__RXCAL_RX_GAIN_TABLE_9_CHN1__SHIFT        16
#define RXCAL_RX_GAIN_TABLE_9_8_B1__RXCAL_RX_GAIN_TABLE_9_CHN1__WIDTH         9
#define RXCAL_RX_GAIN_TABLE_9_8_B1__RXCAL_RX_GAIN_TABLE_9_CHN1__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_9_8_B1__RXCAL_RX_GAIN_TABLE_9_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_9_8_B1__RXCAL_RX_GAIN_TABLE_9_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_9_8_B1__RXCAL_RX_GAIN_TABLE_9_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_9_8_B1__RXCAL_RX_GAIN_TABLE_9_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_9_8_B1__TYPE                               uint32_t
#define RXCAL_RX_GAIN_TABLE_9_8_B1__READ                            0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_9_8_B1__WRITE                           0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_9_8_B1_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_9_8_b1 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_9_8_B1__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_11_10_b1 */
#ifndef __RXCAL_RX_GAIN_TABLE_11_10_B1_MACRO__
#define __RXCAL_RX_GAIN_TABLE_11_10_B1_MACRO__

/* macros for field rxcal_rx_gain_table_10_chn1 */
#define RXCAL_RX_GAIN_TABLE_11_10_B1__RXCAL_RX_GAIN_TABLE_10_CHN1__SHIFT      0
#define RXCAL_RX_GAIN_TABLE_11_10_B1__RXCAL_RX_GAIN_TABLE_10_CHN1__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_11_10_B1__RXCAL_RX_GAIN_TABLE_10_CHN1__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_11_10_B1__RXCAL_RX_GAIN_TABLE_10_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_11_10_B1__RXCAL_RX_GAIN_TABLE_10_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_11_10_B1__RXCAL_RX_GAIN_TABLE_10_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_11_10_B1__RXCAL_RX_GAIN_TABLE_10_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_11_chn1 */
#define RXCAL_RX_GAIN_TABLE_11_10_B1__RXCAL_RX_GAIN_TABLE_11_CHN1__SHIFT     16
#define RXCAL_RX_GAIN_TABLE_11_10_B1__RXCAL_RX_GAIN_TABLE_11_CHN1__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_11_10_B1__RXCAL_RX_GAIN_TABLE_11_CHN1__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_11_10_B1__RXCAL_RX_GAIN_TABLE_11_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_11_10_B1__RXCAL_RX_GAIN_TABLE_11_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_11_10_B1__RXCAL_RX_GAIN_TABLE_11_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_11_10_B1__RXCAL_RX_GAIN_TABLE_11_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_11_10_B1__TYPE                             uint32_t
#define RXCAL_RX_GAIN_TABLE_11_10_B1__READ                          0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_11_10_B1__WRITE                         0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_11_10_B1_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_11_10_b1 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_11_10_B1__NUM                             1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_13_12_b1 */
#ifndef __RXCAL_RX_GAIN_TABLE_13_12_B1_MACRO__
#define __RXCAL_RX_GAIN_TABLE_13_12_B1_MACRO__

/* macros for field rxcal_rx_gain_table_12_chn1 */
#define RXCAL_RX_GAIN_TABLE_13_12_B1__RXCAL_RX_GAIN_TABLE_12_CHN1__SHIFT      0
#define RXCAL_RX_GAIN_TABLE_13_12_B1__RXCAL_RX_GAIN_TABLE_12_CHN1__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_13_12_B1__RXCAL_RX_GAIN_TABLE_12_CHN1__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_13_12_B1__RXCAL_RX_GAIN_TABLE_12_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_13_12_B1__RXCAL_RX_GAIN_TABLE_12_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_13_12_B1__RXCAL_RX_GAIN_TABLE_12_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_13_12_B1__RXCAL_RX_GAIN_TABLE_12_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_13_chn1 */
#define RXCAL_RX_GAIN_TABLE_13_12_B1__RXCAL_RX_GAIN_TABLE_13_CHN1__SHIFT     16
#define RXCAL_RX_GAIN_TABLE_13_12_B1__RXCAL_RX_GAIN_TABLE_13_CHN1__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_13_12_B1__RXCAL_RX_GAIN_TABLE_13_CHN1__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_13_12_B1__RXCAL_RX_GAIN_TABLE_13_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_13_12_B1__RXCAL_RX_GAIN_TABLE_13_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_13_12_B1__RXCAL_RX_GAIN_TABLE_13_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_13_12_B1__RXCAL_RX_GAIN_TABLE_13_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_13_12_B1__TYPE                             uint32_t
#define RXCAL_RX_GAIN_TABLE_13_12_B1__READ                          0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_13_12_B1__WRITE                         0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_13_12_B1_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_13_12_b1 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_13_12_B1__NUM                             1

/* macros for BlueprintGlobalNameSpace::rxcal_rx_gain_table_15_14_b1 */
#ifndef __RXCAL_RX_GAIN_TABLE_15_14_B1_MACRO__
#define __RXCAL_RX_GAIN_TABLE_15_14_B1_MACRO__

/* macros for field rxcal_rx_gain_table_14_chn1 */
#define RXCAL_RX_GAIN_TABLE_15_14_B1__RXCAL_RX_GAIN_TABLE_14_CHN1__SHIFT      0
#define RXCAL_RX_GAIN_TABLE_15_14_B1__RXCAL_RX_GAIN_TABLE_14_CHN1__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_15_14_B1__RXCAL_RX_GAIN_TABLE_14_CHN1__MASK \
                    0x000001ffU
#define RXCAL_RX_GAIN_TABLE_15_14_B1__RXCAL_RX_GAIN_TABLE_14_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define RXCAL_RX_GAIN_TABLE_15_14_B1__RXCAL_RX_GAIN_TABLE_14_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_15_14_B1__RXCAL_RX_GAIN_TABLE_14_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define RXCAL_RX_GAIN_TABLE_15_14_B1__RXCAL_RX_GAIN_TABLE_14_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field rxcal_rx_gain_table_15_chn1 */
#define RXCAL_RX_GAIN_TABLE_15_14_B1__RXCAL_RX_GAIN_TABLE_15_CHN1__SHIFT     16
#define RXCAL_RX_GAIN_TABLE_15_14_B1__RXCAL_RX_GAIN_TABLE_15_CHN1__WIDTH      9
#define RXCAL_RX_GAIN_TABLE_15_14_B1__RXCAL_RX_GAIN_TABLE_15_CHN1__MASK \
                    0x01ff0000U
#define RXCAL_RX_GAIN_TABLE_15_14_B1__RXCAL_RX_GAIN_TABLE_15_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define RXCAL_RX_GAIN_TABLE_15_14_B1__RXCAL_RX_GAIN_TABLE_15_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_15_14_B1__RXCAL_RX_GAIN_TABLE_15_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define RXCAL_RX_GAIN_TABLE_15_14_B1__RXCAL_RX_GAIN_TABLE_15_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define RXCAL_RX_GAIN_TABLE_15_14_B1__TYPE                             uint32_t
#define RXCAL_RX_GAIN_TABLE_15_14_B1__READ                          0x01ff01ffU
#define RXCAL_RX_GAIN_TABLE_15_14_B1__WRITE                         0x01ff01ffU

#endif /* __RXCAL_RX_GAIN_TABLE_15_14_B1_MACRO__ */


/* macros for BB_rxcal_rx_gain_table_15_14_b1 */
#define INST_BB_RXCAL_RX_GAIN_TABLE_15_14_B1__NUM                             1

/* macros for BlueprintGlobalNameSpace::rxcal_gain_delta_db_table_3_0_b1 */
#ifndef __RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1_MACRO__
#define __RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1_MACRO__

/* macros for field rxcal_gain_delta_db_table_0_chn1 */
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN1__SHIFT \
                    0
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN1__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN1__MASK \
                    0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_0_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field rxcal_gain_delta_db_table_1_chn1 */
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN1__SHIFT \
                    8
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN1__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN1__MASK \
                    0x00003f00U
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_1_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))

/* macros for field rxcal_gain_delta_db_table_2_chn1 */
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN1__SHIFT \
                    16
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN1__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN1__MASK \
                    0x003f0000U
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_2_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))

/* macros for field rxcal_gain_delta_db_table_3_chn1 */
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN1__SHIFT \
                    24
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN1__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN1__MASK \
                    0x3f000000U
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__RXCAL_GAIN_DELTA_DB_TABLE_3_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__TYPE                         uint32_t
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__READ                      0x3f3f3f3fU
#define RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__WRITE                     0x3f3f3f3fU

#endif /* __RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1_MACRO__ */


/* macros for BB_rxcal_gain_delta_db_table_3_0_b1 */
#define INST_BB_RXCAL_GAIN_DELTA_DB_TABLE_3_0_B1__NUM                         1

/* macros for BlueprintGlobalNameSpace::rxcal_gain_delta_db_table_7_4_b1 */
#ifndef __RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1_MACRO__
#define __RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1_MACRO__

/* macros for field rxcal_gain_delta_db_table_4_chn1 */
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN1__SHIFT \
                    0
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN1__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN1__MASK \
                    0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_4_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field rxcal_gain_delta_db_table_5_chn1 */
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN1__SHIFT \
                    8
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN1__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN1__MASK \
                    0x00003f00U
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_5_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))

/* macros for field rxcal_gain_delta_db_table_6_chn1 */
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN1__SHIFT \
                    16
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN1__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN1__MASK \
                    0x003f0000U
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_6_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))

/* macros for field rxcal_gain_delta_db_table_7_chn1 */
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN1__SHIFT \
                    24
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN1__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN1__MASK \
                    0x3f000000U
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__RXCAL_GAIN_DELTA_DB_TABLE_7_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__TYPE                         uint32_t
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__READ                      0x3f3f3f3fU
#define RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__WRITE                     0x3f3f3f3fU

#endif /* __RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1_MACRO__ */


/* macros for BB_rxcal_gain_delta_db_table_7_4_b1 */
#define INST_BB_RXCAL_GAIN_DELTA_DB_TABLE_7_4_B1__NUM                         1

/* macros for BlueprintGlobalNameSpace::rxcal_gain_delta_db_table_11_8_b1 */
#ifndef __RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1_MACRO__
#define __RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1_MACRO__

/* macros for field rxcal_gain_delta_db_table_8_chn1 */
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN1__SHIFT \
                    0
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN1__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN1__MASK \
                    0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_8_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field rxcal_gain_delta_db_table_9_chn1 */
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN1__SHIFT \
                    8
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN1__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN1__MASK \
                    0x00003f00U
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_9_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))

/* macros for field rxcal_gain_delta_db_table_10_chn1 */
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN1__SHIFT \
                    16
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN1__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN1__MASK \
                    0x003f0000U
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_10_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))

/* macros for field rxcal_gain_delta_db_table_11_chn1 */
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN1__SHIFT \
                    24
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN1__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN1__MASK \
                    0x3f000000U
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__RXCAL_GAIN_DELTA_DB_TABLE_11_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__TYPE                        uint32_t
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__READ                     0x3f3f3f3fU
#define RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__WRITE                    0x3f3f3f3fU

#endif /* __RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1_MACRO__ */


/* macros for BB_rxcal_gain_delta_db_table_11_8_b1 */
#define INST_BB_RXCAL_GAIN_DELTA_DB_TABLE_11_8_B1__NUM                        1

/* macros for BlueprintGlobalNameSpace::rxcal_gain_delta_db_table_15_12_b1 */
#ifndef __RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1_MACRO__
#define __RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1_MACRO__

/* macros for field rxcal_gain_delta_db_table_12_chn1 */
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN1__SHIFT \
                    0
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN1__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN1__MASK \
                    0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000003fU
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_12_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))

/* macros for field rxcal_gain_delta_db_table_13_chn1 */
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN1__SHIFT \
                    8
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN1__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN1__MASK \
                    0x00003f00U
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f00U) | (((uint32_t)(src) <<\
                    8) & 0x00003f00U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_13_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00003f00U)))

/* macros for field rxcal_gain_delta_db_table_14_chn1 */
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN1__SHIFT \
                    16
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN1__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN1__MASK \
                    0x003f0000U
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f0000U) >> 16)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f0000U) | (((uint32_t)(src) <<\
                    16) & 0x003f0000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_14_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x003f0000U)))

/* macros for field rxcal_gain_delta_db_table_15_chn1 */
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN1__SHIFT \
                    24
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN1__WIDTH \
                    6
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN1__MASK \
                    0x3f000000U
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f000000U) >> 24)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f000000U) | (((uint32_t)(src) <<\
                    24) & 0x3f000000U)
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__RXCAL_GAIN_DELTA_DB_TABLE_15_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x3f000000U)))
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__TYPE                       uint32_t
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__READ                    0x3f3f3f3fU
#define RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__WRITE                   0x3f3f3f3fU

#endif /* __RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1_MACRO__ */


/* macros for BB_rxcal_gain_delta_db_table_15_12_b1 */
#define INST_BB_RXCAL_GAIN_DELTA_DB_TABLE_15_12_B1__NUM                       1

/* macros for BlueprintGlobalNameSpace::rxcal_tx_iqcorr_idx_7_0_b1 */
#ifndef __RXCAL_TX_IQCORR_IDX_7_0_B1_MACRO__
#define __RXCAL_TX_IQCORR_IDX_7_0_B1_MACRO__

/* macros for field rxcal_tx_iqcorr_idx_0_chn1 */
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_0_CHN1__SHIFT         0
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_0_CHN1__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_0_CHN1__MASK \
                    0x0000000fU
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_0_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_0_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_0_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_0_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field rxcal_tx_iqcorr_idx_1_chn1 */
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_1_CHN1__SHIFT         4
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_1_CHN1__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_1_CHN1__MASK \
                    0x000000f0U
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_1_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_1_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_1_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_1_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field rxcal_tx_iqcorr_idx_2_chn1 */
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_2_CHN1__SHIFT         8
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_2_CHN1__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_2_CHN1__MASK \
                    0x00000f00U
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_2_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_2_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_2_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_2_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field rxcal_tx_iqcorr_idx_3_chn1 */
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_3_CHN1__SHIFT        12
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_3_CHN1__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_3_CHN1__MASK \
                    0x0000f000U
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_3_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_3_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_3_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_3_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field rxcal_tx_iqcorr_idx_4_chn1 */
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_4_CHN1__SHIFT        16
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_4_CHN1__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_4_CHN1__MASK \
                    0x000f0000U
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_4_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_4_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_4_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_4_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field rxcal_tx_iqcorr_idx_5_chn1 */
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_5_CHN1__SHIFT        20
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_5_CHN1__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_5_CHN1__MASK \
                    0x00f00000U
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_5_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_5_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_5_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_5_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field rxcal_tx_iqcorr_idx_6_chn1 */
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_6_CHN1__SHIFT        24
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_6_CHN1__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_6_CHN1__MASK \
                    0x0f000000U
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_6_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_6_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_6_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_6_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field rxcal_tx_iqcorr_idx_7_chn1 */
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_7_CHN1__SHIFT        28
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_7_CHN1__WIDTH         4
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_7_CHN1__MASK \
                    0xf0000000U
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_7_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_7_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_7_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_7_0_B1__RXCAL_TX_IQCORR_IDX_7_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RXCAL_TX_IQCORR_IDX_7_0_B1__TYPE                               uint32_t
#define RXCAL_TX_IQCORR_IDX_7_0_B1__READ                            0xffffffffU
#define RXCAL_TX_IQCORR_IDX_7_0_B1__WRITE                           0xffffffffU

#endif /* __RXCAL_TX_IQCORR_IDX_7_0_B1_MACRO__ */


/* macros for BB_rxcal_tx_iqcorr_idx_7_0_b1 */
#define INST_BB_RXCAL_TX_IQCORR_IDX_7_0_B1__NUM                               1

/* macros for BlueprintGlobalNameSpace::rxcal_tx_iqcorr_idx_15_8_b1 */
#ifndef __RXCAL_TX_IQCORR_IDX_15_8_B1_MACRO__
#define __RXCAL_TX_IQCORR_IDX_15_8_B1_MACRO__

/* macros for field rxcal_tx_iqcorr_idx_8_chn1 */
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_8_CHN1__SHIFT        0
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_8_CHN1__WIDTH        4
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_8_CHN1__MASK \
                    0x0000000fU
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_8_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_8_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_8_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_8_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field rxcal_tx_iqcorr_idx_9_chn1 */
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_9_CHN1__SHIFT        4
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_9_CHN1__WIDTH        4
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_9_CHN1__MASK \
                    0x000000f0U
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_9_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_9_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_9_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_9_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field rxcal_tx_iqcorr_idx_10_chn1 */
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_10_CHN1__SHIFT       8
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_10_CHN1__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_10_CHN1__MASK \
                    0x00000f00U
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_10_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_10_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_10_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_10_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field rxcal_tx_iqcorr_idx_11_chn1 */
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_11_CHN1__SHIFT      12
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_11_CHN1__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_11_CHN1__MASK \
                    0x0000f000U
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_11_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_11_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_11_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_11_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field rxcal_tx_iqcorr_idx_12_chn1 */
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_12_CHN1__SHIFT      16
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_12_CHN1__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_12_CHN1__MASK \
                    0x000f0000U
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_12_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_12_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_12_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_12_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field rxcal_tx_iqcorr_idx_13_chn1 */
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_13_CHN1__SHIFT      20
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_13_CHN1__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_13_CHN1__MASK \
                    0x00f00000U
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_13_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_13_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_13_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_13_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field rxcal_tx_iqcorr_idx_14_chn1 */
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_14_CHN1__SHIFT      24
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_14_CHN1__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_14_CHN1__MASK \
                    0x0f000000U
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_14_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_14_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_14_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_14_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field rxcal_tx_iqcorr_idx_15_chn1 */
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_15_CHN1__SHIFT      28
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_15_CHN1__WIDTH       4
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_15_CHN1__MASK \
                    0xf0000000U
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_15_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_15_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_15_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_15_8_B1__RXCAL_TX_IQCORR_IDX_15_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RXCAL_TX_IQCORR_IDX_15_8_B1__TYPE                              uint32_t
#define RXCAL_TX_IQCORR_IDX_15_8_B1__READ                           0xffffffffU
#define RXCAL_TX_IQCORR_IDX_15_8_B1__WRITE                          0xffffffffU

#endif /* __RXCAL_TX_IQCORR_IDX_15_8_B1_MACRO__ */


/* macros for BB_rxcal_tx_iqcorr_idx_15_8_b1 */
#define INST_BB_RXCAL_TX_IQCORR_IDX_15_8_B1__NUM                              1

/* macros for BlueprintGlobalNameSpace::rxcal_tx_iqcorr_idx_23_16_b1 */
#ifndef __RXCAL_TX_IQCORR_IDX_23_16_B1_MACRO__
#define __RXCAL_TX_IQCORR_IDX_23_16_B1_MACRO__

/* macros for field rxcal_tx_iqcorr_idx_16_chn1 */
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_16_CHN1__SHIFT      0
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_16_CHN1__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_16_CHN1__MASK \
                    0x0000000fU
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_16_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_16_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_16_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_16_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field rxcal_tx_iqcorr_idx_17_chn1 */
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_17_CHN1__SHIFT      4
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_17_CHN1__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_17_CHN1__MASK \
                    0x000000f0U
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_17_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_17_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_17_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_17_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field rxcal_tx_iqcorr_idx_18_chn1 */
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_18_CHN1__SHIFT      8
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_18_CHN1__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_18_CHN1__MASK \
                    0x00000f00U
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_18_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_18_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_18_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_18_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field rxcal_tx_iqcorr_idx_19_chn1 */
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_19_CHN1__SHIFT     12
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_19_CHN1__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_19_CHN1__MASK \
                    0x0000f000U
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_19_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_19_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_19_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_19_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field rxcal_tx_iqcorr_idx_20_chn1 */
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_20_CHN1__SHIFT     16
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_20_CHN1__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_20_CHN1__MASK \
                    0x000f0000U
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_20_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_20_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_20_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_20_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field rxcal_tx_iqcorr_idx_21_chn1 */
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_21_CHN1__SHIFT     20
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_21_CHN1__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_21_CHN1__MASK \
                    0x00f00000U
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_21_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_21_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_21_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_21_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field rxcal_tx_iqcorr_idx_22_chn1 */
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_22_CHN1__SHIFT     24
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_22_CHN1__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_22_CHN1__MASK \
                    0x0f000000U
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_22_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_22_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_22_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_22_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field rxcal_tx_iqcorr_idx_23_chn1 */
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_23_CHN1__SHIFT     28
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_23_CHN1__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_23_CHN1__MASK \
                    0xf0000000U
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_23_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_23_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_23_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_23_16_B1__RXCAL_TX_IQCORR_IDX_23_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RXCAL_TX_IQCORR_IDX_23_16_B1__TYPE                             uint32_t
#define RXCAL_TX_IQCORR_IDX_23_16_B1__READ                          0xffffffffU
#define RXCAL_TX_IQCORR_IDX_23_16_B1__WRITE                         0xffffffffU

#endif /* __RXCAL_TX_IQCORR_IDX_23_16_B1_MACRO__ */


/* macros for BB_rxcal_tx_iqcorr_idx_23_16_b1 */
#define INST_BB_RXCAL_TX_IQCORR_IDX_23_16_B1__NUM                             1

/* macros for BlueprintGlobalNameSpace::rxcal_tx_iqcorr_idx_31_24_b1 */
#ifndef __RXCAL_TX_IQCORR_IDX_31_24_B1_MACRO__
#define __RXCAL_TX_IQCORR_IDX_31_24_B1_MACRO__

/* macros for field rxcal_tx_iqcorr_idx_24_chn1 */
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_24_CHN1__SHIFT      0
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_24_CHN1__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_24_CHN1__MASK \
                    0x0000000fU
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_24_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0000000fU
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_24_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_24_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_24_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))

/* macros for field rxcal_tx_iqcorr_idx_25_chn1 */
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_25_CHN1__SHIFT      4
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_25_CHN1__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_25_CHN1__MASK \
                    0x000000f0U
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_25_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_25_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_25_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_25_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))

/* macros for field rxcal_tx_iqcorr_idx_26_chn1 */
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_26_CHN1__SHIFT      8
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_26_CHN1__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_26_CHN1__MASK \
                    0x00000f00U
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_26_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_26_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_26_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_26_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))

/* macros for field rxcal_tx_iqcorr_idx_27_chn1 */
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_27_CHN1__SHIFT     12
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_27_CHN1__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_27_CHN1__MASK \
                    0x0000f000U
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_27_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_27_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_27_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_27_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))

/* macros for field rxcal_tx_iqcorr_idx_28_chn1 */
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_28_CHN1__SHIFT     16
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_28_CHN1__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_28_CHN1__MASK \
                    0x000f0000U
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_28_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_28_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_28_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_28_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))

/* macros for field rxcal_tx_iqcorr_idx_29_chn1 */
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_29_CHN1__SHIFT     20
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_29_CHN1__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_29_CHN1__MASK \
                    0x00f00000U
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_29_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_29_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_29_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_29_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))

/* macros for field rxcal_tx_iqcorr_idx_30_chn1 */
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_30_CHN1__SHIFT     24
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_30_CHN1__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_30_CHN1__MASK \
                    0x0f000000U
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_30_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0f000000U) >> 24)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_30_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_30_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0f000000U) | (((uint32_t)(src) <<\
                    24) & 0x0f000000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_30_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x0f000000U)))

/* macros for field rxcal_tx_iqcorr_idx_31_chn1 */
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_31_CHN1__SHIFT     28
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_31_CHN1__WIDTH      4
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_31_CHN1__MASK \
                    0xf0000000U
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_31_CHN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf0000000U) >> 28)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_31_CHN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_31_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf0000000U) | (((uint32_t)(src) <<\
                    28) & 0xf0000000U)
#define RXCAL_TX_IQCORR_IDX_31_24_B1__RXCAL_TX_IQCORR_IDX_31_CHN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0xf0000000U)))
#define RXCAL_TX_IQCORR_IDX_31_24_B1__TYPE                             uint32_t
#define RXCAL_TX_IQCORR_IDX_31_24_B1__READ                          0xffffffffU
#define RXCAL_TX_IQCORR_IDX_31_24_B1__WRITE                         0xffffffffU

#endif /* __RXCAL_TX_IQCORR_IDX_31_24_B1_MACRO__ */


/* macros for BB_rxcal_tx_iqcorr_idx_31_24_b1 */
#define INST_BB_RXCAL_TX_IQCORR_IDX_31_24_B1__NUM                             1

/* macros for BlueprintGlobalNameSpace::paprd_sm_sig_gain_table_0_2_b1 */
#ifndef __PAPRD_SM_SIG_GAIN_TABLE_0_2_B1_MACRO__
#define __PAPRD_SM_SIG_GAIN_TABLE_0_2_B1_MACRO__

/* macros for field paprd_sm_sig_gain_0 */
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_0__SHIFT            0
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_0__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_0__MASK   0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_0__READ(src) \
                    (uint32_t)(src)\
                    & 0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_sm_sig_gain_1 */
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_1__SHIFT           10
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_1__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_1__MASK   0x000ffc00U
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_sm_sig_gain_2 */
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_2__SHIFT           20
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_2__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_2__MASK   0x3ff00000U
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__PAPRD_SM_SIG_GAIN_2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__TYPE                           uint32_t
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__READ                        0x3fffffffU
#define PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__WRITE                       0x3fffffffU

#endif /* __PAPRD_SM_SIG_GAIN_TABLE_0_2_B1_MACRO__ */


/* macros for BB_paprd_sm_sig_gain_table_0_2_b1 */
#define INST_BB_PAPRD_SM_SIG_GAIN_TABLE_0_2_B1__NUM                           1

/* macros for BlueprintGlobalNameSpace::paprd_sm_sig_gain_table_3_5_b1 */
#ifndef __PAPRD_SM_SIG_GAIN_TABLE_3_5_B1_MACRO__
#define __PAPRD_SM_SIG_GAIN_TABLE_3_5_B1_MACRO__

/* macros for field paprd_sm_sig_gain_3 */
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_3__SHIFT            0
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_3__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_3__MASK   0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_3__READ(src) \
                    (uint32_t)(src)\
                    & 0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_3__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_3__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))

/* macros for field paprd_sm_sig_gain_4 */
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_4__SHIFT           10
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_4__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_4__MASK   0x000ffc00U
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_4__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_4__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_4__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))

/* macros for field paprd_sm_sig_gain_5 */
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_5__SHIFT           20
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_5__WIDTH           10
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_5__MASK   0x3ff00000U
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_5__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_5__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__PAPRD_SM_SIG_GAIN_5__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__TYPE                           uint32_t
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__READ                        0x3fffffffU
#define PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__WRITE                       0x3fffffffU

#endif /* __PAPRD_SM_SIG_GAIN_TABLE_3_5_B1_MACRO__ */


/* macros for BB_paprd_sm_sig_gain_table_3_5_b1 */
#define INST_BB_PAPRD_SM_SIG_GAIN_TABLE_3_5_B1__NUM                           1

/* macros for BlueprintGlobalNameSpace::paprd_sm_sig_gain_table_6_b1 */
#ifndef __PAPRD_SM_SIG_GAIN_TABLE_6_B1_MACRO__
#define __PAPRD_SM_SIG_GAIN_TABLE_6_B1_MACRO__

/* macros for field paprd_sm_sig_gain_6 */
#define PAPRD_SM_SIG_GAIN_TABLE_6_B1__PAPRD_SM_SIG_GAIN_6__SHIFT              0
#define PAPRD_SM_SIG_GAIN_TABLE_6_B1__PAPRD_SM_SIG_GAIN_6__WIDTH             10
#define PAPRD_SM_SIG_GAIN_TABLE_6_B1__PAPRD_SM_SIG_GAIN_6__MASK     0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_6_B1__PAPRD_SM_SIG_GAIN_6__READ(src) \
                    (uint32_t)(src)\
                    & 0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_6_B1__PAPRD_SM_SIG_GAIN_6__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_6_B1__PAPRD_SM_SIG_GAIN_6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define PAPRD_SM_SIG_GAIN_TABLE_6_B1__PAPRD_SM_SIG_GAIN_6__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define PAPRD_SM_SIG_GAIN_TABLE_6_B1__TYPE                             uint32_t
#define PAPRD_SM_SIG_GAIN_TABLE_6_B1__READ                          0x000003ffU
#define PAPRD_SM_SIG_GAIN_TABLE_6_B1__WRITE                         0x000003ffU

#endif /* __PAPRD_SM_SIG_GAIN_TABLE_6_B1_MACRO__ */


/* macros for BB_paprd_sm_sig_gain_table_6_b1 */
#define INST_BB_PAPRD_SM_SIG_GAIN_TABLE_6_B1__NUM                             1

/* macros for BlueprintGlobalNameSpace::preemp_coef_set0_b1 */
#ifndef __PREEMP_COEF_SET0_B1_MACRO__
#define __PREEMP_COEF_SET0_B1_MACRO__

/* macros for field tx_preemp_coef_0_b1 */
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_0_B1__SHIFT                       0
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_0_B1__WIDTH                       9
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_0_B1__MASK              0x000001ffU
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_0_B1__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_0_B1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_0_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_0_B1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field tx_preemp_coef_1_b1 */
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_1_B1__SHIFT                       9
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_1_B1__WIDTH                       9
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_1_B1__MASK              0x0003fe00U
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_1_B1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_1_B1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_1_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_1_B1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field tx_preemp_coef_2_b1 */
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_2_B1__SHIFT                      18
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_2_B1__WIDTH                       9
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_2_B1__MASK              0x07fc0000U
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_2_B1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_2_B1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_2_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PREEMP_COEF_SET0_B1__TX_PREEMP_COEF_2_B1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define PREEMP_COEF_SET0_B1__TYPE                                      uint32_t
#define PREEMP_COEF_SET0_B1__READ                                   0x07ffffffU
#define PREEMP_COEF_SET0_B1__WRITE                                  0x07ffffffU

#endif /* __PREEMP_COEF_SET0_B1_MACRO__ */


/* macros for BB_preemp_coef_set0_b1 */
#define INST_BB_PREEMP_COEF_SET0_B1__NUM                                      1

/* macros for BlueprintGlobalNameSpace::preemp_coef_set1_b1 */
#ifndef __PREEMP_COEF_SET1_B1_MACRO__
#define __PREEMP_COEF_SET1_B1_MACRO__

/* macros for field tx_preemp_coef_3_b1 */
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_3_B1__SHIFT                       0
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_3_B1__WIDTH                       9
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_3_B1__MASK              0x000001ffU
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_3_B1__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_3_B1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_3_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_3_B1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field tx_preemp_coef_4_b1 */
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_4_B1__SHIFT                       9
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_4_B1__WIDTH                       9
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_4_B1__MASK              0x0003fe00U
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_4_B1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_4_B1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_4_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_4_B1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field tx_preemp_coef_5_b1 */
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_5_B1__SHIFT                      18
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_5_B1__WIDTH                       9
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_5_B1__MASK              0x07fc0000U
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_5_B1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_5_B1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_5_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PREEMP_COEF_SET1_B1__TX_PREEMP_COEF_5_B1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define PREEMP_COEF_SET1_B1__TYPE                                      uint32_t
#define PREEMP_COEF_SET1_B1__READ                                   0x07ffffffU
#define PREEMP_COEF_SET1_B1__WRITE                                  0x07ffffffU

#endif /* __PREEMP_COEF_SET1_B1_MACRO__ */


/* macros for BB_preemp_coef_set1_b1 */
#define INST_BB_PREEMP_COEF_SET1_B1__NUM                                      1

/* macros for BlueprintGlobalNameSpace::preemp_coef_set2_b1 */
#ifndef __PREEMP_COEF_SET2_B1_MACRO__
#define __PREEMP_COEF_SET2_B1_MACRO__

/* macros for field tx_preemp_coef_6_b1 */
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_6_B1__SHIFT                       0
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_6_B1__WIDTH                       9
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_6_B1__MASK              0x000001ffU
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_6_B1__READ(src) \
                    (uint32_t)(src)\
                    & 0x000001ffU
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_6_B1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000001ffU)
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_6_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_6_B1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))

/* macros for field tx_preemp_coef_7_b1 */
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_7_B1__SHIFT                       9
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_7_B1__WIDTH                       9
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_7_B1__MASK              0x0003fe00U
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_7_B1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_7_B1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_7_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_7_B1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))

/* macros for field tx_preemp_coef_8_b1 */
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_8_B1__SHIFT                      18
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_8_B1__WIDTH                       9
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_8_B1__MASK              0x07fc0000U
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_8_B1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07fc0000U) >> 18)
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_8_B1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x07fc0000U)
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_8_B1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x07fc0000U)
#define PREEMP_COEF_SET2_B1__TX_PREEMP_COEF_8_B1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x07fc0000U)))
#define PREEMP_COEF_SET2_B1__TYPE                                      uint32_t
#define PREEMP_COEF_SET2_B1__READ                                   0x07ffffffU
#define PREEMP_COEF_SET2_B1__WRITE                                  0x07ffffffU

#endif /* __PREEMP_COEF_SET2_B1_MACRO__ */


/* macros for BB_preemp_coef_set2_b1 */
#define INST_BB_PREEMP_COEF_SET2_B1__NUM                                      1

/* macros for BlueprintGlobalNameSpace::tx_plybck_ctrl_0_b1 */
#ifndef __TX_PLYBCK_CTRL_0_B1_MACRO__
#define __TX_PLYBCK_CTRL_0_B1_MACRO__

/* macros for field tx_plybck_enable */
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_ENABLE__SHIFT                          0
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_ENABLE__WIDTH                          1
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_ENABLE__MASK                 0x00000001U
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_ENABLE__READ(src) \
                    (uint32_t)(src)\
                    & 0x00000001U
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_ENABLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_ENABLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)

/* macros for field tx_plybck_sw_we */
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_SW_WE__SHIFT                           1
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_SW_WE__WIDTH                           1
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_SW_WE__MASK                  0x00000002U
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_SW_WE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_SW_WE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_SW_WE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_SW_WE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_SW_WE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_SW_WE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)

/* macros for field tx_plybck_start_addr */
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_START_ADDR__SHIFT                      8
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_START_ADDR__WIDTH                      8
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_START_ADDR__MASK             0x0000ff00U
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_START_ADDR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_START_ADDR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_START_ADDR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_START_ADDR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))

/* macros for field tx_plybck_nsamples */
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_NSAMPLES__SHIFT                       16
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_NSAMPLES__WIDTH                       16
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_NSAMPLES__MASK               0xffff0000U
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_NSAMPLES__READ(src) \
                    (((uint32_t)(src)\
                    & 0xffff0000U) >> 16)
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_NSAMPLES__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0xffff0000U)
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_NSAMPLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffff0000U) | (((uint32_t)(src) <<\
                    16) & 0xffff0000U)
#define TX_PLYBCK_CTRL_0_B1__TX_PLYBCK_NSAMPLES__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0xffff0000U)))
#define TX_PLYBCK_CTRL_0_B1__TYPE                                      uint32_t
#define TX_PLYBCK_CTRL_0_B1__READ                                   0xffffff03U
#define TX_PLYBCK_CTRL_0_B1__WRITE                                  0xffffff03U

#endif /* __TX_PLYBCK_CTRL_0_B1_MACRO__ */


/* macros for BB_tx_plybck_ctrl_0_b1 */
#define INST_BB_TX_PLYBCK_CTRL_0_B1__NUM                                      1

/* macros for BlueprintGlobalNameSpace::tx_plybck_ctrl_1_b1 */
#ifndef __TX_PLYBCK_CTRL_1_B1_MACRO__
#define __TX_PLYBCK_CTRL_1_B1_MACRO__

/* macros for field tx_plybck_swdata_i */
#define TX_PLYBCK_CTRL_1_B1__TX_PLYBCK_SWDATA_I__SHIFT                        0
#define TX_PLYBCK_CTRL_1_B1__TX_PLYBCK_SWDATA_I__WIDTH                       11
#define TX_PLYBCK_CTRL_1_B1__TX_PLYBCK_SWDATA_I__MASK               0x000007ffU
#define TX_PLYBCK_CTRL_1_B1__TX_PLYBCK_SWDATA_I__READ(src) \
                    (uint32_t)(src)\
                    & 0x000007ffU
#define TX_PLYBCK_CTRL_1_B1__TX_PLYBCK_SWDATA_I__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000007ffU)
#define TX_PLYBCK_CTRL_1_B1__TX_PLYBCK_SWDATA_I__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000007ffU) | ((uint32_t)(src) &\
                    0x000007ffU)
#define TX_PLYBCK_CTRL_1_B1__TX_PLYBCK_SWDATA_I__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000007ffU)))

/* macros for field tx_plybck_swdata_q */
#define TX_PLYBCK_CTRL_1_B1__TX_PLYBCK_SWDATA_Q__SHIFT                       11
#define TX_PLYBCK_CTRL_1_B1__TX_PLYBCK_SWDATA_Q__WIDTH                       11
#define TX_PLYBCK_CTRL_1_B1__TX_PLYBCK_SWDATA_Q__MASK               0x003ff800U
#define TX_PLYBCK_CTRL_1_B1__TX_PLYBCK_SWDATA_Q__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003ff800U) >> 11)
#define TX_PLYBCK_CTRL_1_B1__TX_PLYBCK_SWDATA_Q__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x003ff800U)
#define TX_PLYBCK_CTRL_1_B1__TX_PLYBCK_SWDATA_Q__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003ff800U) | (((uint32_t)(src) <<\
                    11) & 0x003ff800U)
#define TX_PLYBCK_CTRL_1_B1__TX_PLYBCK_SWDATA_Q__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x003ff800U)))
#define TX_PLYBCK_CTRL_1_B1__TYPE                                      uint32_t
#define TX_PLYBCK_CTRL_1_B1__READ                                   0x003fffffU
#define TX_PLYBCK_CTRL_1_B1__WRITE                                  0x003fffffU

#endif /* __TX_PLYBCK_CTRL_1_B1_MACRO__ */


/* macros for BB_tx_plybck_ctrl_1_b1 */
#define INST_BB_TX_PLYBCK_CTRL_1_B1__NUM                                      1

/* macros for BlueprintGlobalNameSpace::chaninfo_vht80_b1 */
#ifndef __CHANINFO_VHT80_B1_MACRO__
#define __CHANINFO_VHT80_B1_MACRO__

/* macros for field chaninfo_vht80_chn1 */
#define CHANINFO_VHT80_B1__CHANINFO_VHT80_CHN1__SHIFT                         0
#define CHANINFO_VHT80_B1__CHANINFO_VHT80_CHN1__WIDTH                        32
#define CHANINFO_VHT80_B1__CHANINFO_VHT80_CHN1__MASK                0xffffffffU
#define CHANINFO_VHT80_B1__CHANINFO_VHT80_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0xffffffffU
#define CHANINFO_VHT80_B1__TYPE                                        uint32_t
#define CHANINFO_VHT80_B1__READ                                     0xffffffffU

#endif /* __CHANINFO_VHT80_B1_MACRO__ */


/* macros for BB_chaninfo_vht80_b1 */
#define INST_BB_CHANINFO_VHT80_B1__NUM                                       64

/* macros for BlueprintGlobalNameSpace::normrx_rxiq_corr_coeff_b1 */
#ifndef __NORMRX_RXIQ_CORR_COEFF_B1_MACRO__
#define __NORMRX_RXIQ_CORR_COEFF_B1_MACRO__

/* macros for field normrx_iqc_coeff_table_chn1 */
#define NORMRX_RXIQ_CORR_COEFF_B1__NORMRX_IQC_COEFF_TABLE_CHN1__SHIFT         0
#define NORMRX_RXIQ_CORR_COEFF_B1__NORMRX_IQC_COEFF_TABLE_CHN1__WIDTH        18
#define NORMRX_RXIQ_CORR_COEFF_B1__NORMRX_IQC_COEFF_TABLE_CHN1__MASK \
                    0x0003ffffU
#define NORMRX_RXIQ_CORR_COEFF_B1__NORMRX_IQC_COEFF_TABLE_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define NORMRX_RXIQ_CORR_COEFF_B1__NORMRX_IQC_COEFF_TABLE_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define NORMRX_RXIQ_CORR_COEFF_B1__NORMRX_IQC_COEFF_TABLE_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define NORMRX_RXIQ_CORR_COEFF_B1__NORMRX_IQC_COEFF_TABLE_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define NORMRX_RXIQ_CORR_COEFF_B1__TYPE                                uint32_t
#define NORMRX_RXIQ_CORR_COEFF_B1__READ                             0x0003ffffU
#define NORMRX_RXIQ_CORR_COEFF_B1__WRITE                            0x0003ffffU

#endif /* __NORMRX_RXIQ_CORR_COEFF_B1_MACRO__ */


/* macros for BB_normrx_rxiq_corr_coeff_b1 */
#define INST_BB_NORMRX_RXIQ_CORR_COEFF_B1__NUM                              160

/* macros for BlueprintGlobalNameSpace::paprd_mem_tab_b1 */
#ifndef __PAPRD_MEM_TAB_B1_MACRO__
#define __PAPRD_MEM_TAB_B1_MACRO__

/* macros for field paprd_mem */
#define PAPRD_MEM_TAB_B1__PAPRD_MEM__SHIFT                                    0
#define PAPRD_MEM_TAB_B1__PAPRD_MEM__WIDTH                                   22
#define PAPRD_MEM_TAB_B1__PAPRD_MEM__MASK                           0x003fffffU
#define PAPRD_MEM_TAB_B1__PAPRD_MEM__READ(src)    (uint32_t)(src) & 0x003fffffU
#define PAPRD_MEM_TAB_B1__PAPRD_MEM__WRITE(src) ((uint32_t)(src) & 0x003fffffU)
#define PAPRD_MEM_TAB_B1__PAPRD_MEM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fffffU) | ((uint32_t)(src) &\
                    0x003fffffU)
#define PAPRD_MEM_TAB_B1__PAPRD_MEM__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x003fffffU)))
#define PAPRD_MEM_TAB_B1__TYPE                                         uint32_t
#define PAPRD_MEM_TAB_B1__READ                                      0x003fffffU
#define PAPRD_MEM_TAB_B1__WRITE                                     0x003fffffU

#endif /* __PAPRD_MEM_TAB_B1_MACRO__ */


/* macros for BB_paprd_mem_tab_b1 */
#define INST_BB_PAPRD_MEM_TAB_B1__NUM                                      1344

/* macros for BlueprintGlobalNameSpace::normtx_txiq_corr_coeff_b1 */
#ifndef __NORMTX_TXIQ_CORR_COEFF_B1_MACRO__
#define __NORMTX_TXIQ_CORR_COEFF_B1_MACRO__

/* macros for field normtx_iqc_coeff_table_chn1 */
#define NORMTX_TXIQ_CORR_COEFF_B1__NORMTX_IQC_COEFF_TABLE_CHN1__SHIFT         0
#define NORMTX_TXIQ_CORR_COEFF_B1__NORMTX_IQC_COEFF_TABLE_CHN1__WIDTH        18
#define NORMTX_TXIQ_CORR_COEFF_B1__NORMTX_IQC_COEFF_TABLE_CHN1__MASK \
                    0x0003ffffU
#define NORMTX_TXIQ_CORR_COEFF_B1__NORMTX_IQC_COEFF_TABLE_CHN1__READ(src) \
                    (uint32_t)(src)\
                    & 0x0003ffffU
#define NORMTX_TXIQ_CORR_COEFF_B1__NORMTX_IQC_COEFF_TABLE_CHN1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0003ffffU)
#define NORMTX_TXIQ_CORR_COEFF_B1__NORMTX_IQC_COEFF_TABLE_CHN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define NORMTX_TXIQ_CORR_COEFF_B1__NORMTX_IQC_COEFF_TABLE_CHN1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define NORMTX_TXIQ_CORR_COEFF_B1__TYPE                                uint32_t
#define NORMTX_TXIQ_CORR_COEFF_B1__READ                             0x0003ffffU
#define NORMTX_TXIQ_CORR_COEFF_B1__WRITE                            0x0003ffffU

#endif /* __NORMTX_TXIQ_CORR_COEFF_B1_MACRO__ */


/* macros for BB_normtx_txiq_corr_coeff_b1 */
#define INST_BB_NORMTX_TXIQ_CORR_COEFF_B1__NUM                              160

/* macros for BlueprintGlobalNameSpace::chn1_tables_dummy_1 */
#ifndef __CHN1_TABLES_DUMMY_1_MACRO__
#define __CHN1_TABLES_DUMMY_1_MACRO__

/* macros for field dummy1 */
#define CHN1_TABLES_DUMMY_1__DUMMY1__SHIFT                                    0
#define CHN1_TABLES_DUMMY_1__DUMMY1__WIDTH                                   32
#define CHN1_TABLES_DUMMY_1__DUMMY1__MASK                           0xffffffffU
#define CHN1_TABLES_DUMMY_1__DUMMY1__READ(src)    (uint32_t)(src) & 0xffffffffU
#define CHN1_TABLES_DUMMY_1__DUMMY1__WRITE(src) ((uint32_t)(src) & 0xffffffffU)
#define CHN1_TABLES_DUMMY_1__DUMMY1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define CHN1_TABLES_DUMMY_1__DUMMY1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define CHN1_TABLES_DUMMY_1__TYPE                                      uint32_t
#define CHN1_TABLES_DUMMY_1__READ                                   0xffffffffU
#define CHN1_TABLES_DUMMY_1__WRITE                                  0xffffffffU

#endif /* __CHN1_TABLES_DUMMY_1_MACRO__ */


/* macros for BB_chn1_tables_dummy_1 */
#define INST_BB_CHN1_TABLES_DUMMY_1__NUM                                      1

#define CHN1_TABLE_MAP__VERSION \
                    "/cad/denali/blueprint/3.7.3/gen/ansic.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html2docbook.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html2sgml.pm\n\
                    /cad/local/lib/perl/Pinfo.pm\n\
                    /trees/yflee/yflee-dev/ip/athr/wifi/dev/rtl/bb/blueprint/chn1_table_map.rdl"
#endif /* __REG_CHN1_TABLE_MAP_MACRO_H__ */
