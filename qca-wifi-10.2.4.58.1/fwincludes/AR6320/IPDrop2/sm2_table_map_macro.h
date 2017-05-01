/*                                                                           */
/* File:       sm2_table_map_macro.h                                         */
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


#ifndef __REG_SM2_TABLE_MAP_MACRO_H__
#define __REG_SM2_TABLE_MAP_MACRO_H__


/* macros for BlueprintGlobalNameSpace::aic_srams_b2 */
#ifndef __AIC_SRAMS_B2_MACRO__
#define __AIC_SRAMS_B2_MACRO__

/* macros for field aic_word */
#define AIC_SRAMS_B2__AIC_WORD__SHIFT                                         0
#define AIC_SRAMS_B2__AIC_WORD__WIDTH                                        20
#define AIC_SRAMS_B2__AIC_WORD__MASK                                0x000fffffU
#define AIC_SRAMS_B2__AIC_WORD__READ(src)         (uint32_t)(src) & 0x000fffffU
#define AIC_SRAMS_B2__AIC_WORD__WRITE(src)      ((uint32_t)(src) & 0x000fffffU)
#define AIC_SRAMS_B2__AIC_WORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000fffffU) | ((uint32_t)(src) &\
                    0x000fffffU)
#define AIC_SRAMS_B2__AIC_WORD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000fffffU)))
#define AIC_SRAMS_B2__TYPE                                             uint32_t
#define AIC_SRAMS_B2__READ                                          0x000fffffU
#define AIC_SRAMS_B2__WRITE                                         0x000fffffU

#endif /* __AIC_SRAMS_B2_MACRO__ */


/* macros for BB_aic_srams_b2 */
#define INST_BB_AIC_SRAMS_B2__NUM                                            80

/* macros for BlueprintGlobalNameSpace::aic_cal_srams_b2 */
#ifndef __AIC_CAL_SRAMS_B2_MACRO__
#define __AIC_CAL_SRAMS_B2_MACRO__

/* macros for field aic_word */
#define AIC_CAL_SRAMS_B2__AIC_WORD__SHIFT                                     0
#define AIC_CAL_SRAMS_B2__AIC_WORD__WIDTH                                    29
#define AIC_CAL_SRAMS_B2__AIC_WORD__MASK                            0x1fffffffU
#define AIC_CAL_SRAMS_B2__AIC_WORD__READ(src)     (uint32_t)(src) & 0x1fffffffU
#define AIC_CAL_SRAMS_B2__AIC_WORD__WRITE(src)  ((uint32_t)(src) & 0x1fffffffU)
#define AIC_CAL_SRAMS_B2__AIC_WORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1fffffffU) | ((uint32_t)(src) &\
                    0x1fffffffU)
#define AIC_CAL_SRAMS_B2__AIC_WORD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x1fffffffU)))
#define AIC_CAL_SRAMS_B2__TYPE                                         uint32_t
#define AIC_CAL_SRAMS_B2__READ                                      0x1fffffffU
#define AIC_CAL_SRAMS_B2__WRITE                                     0x1fffffffU

#endif /* __AIC_CAL_SRAMS_B2_MACRO__ */


/* macros for BB_aic_cal_srams_b2 */
#define INST_BB_AIC_CAL_SRAMS_B2__NUM                                        80

/* macros for BlueprintGlobalNameSpace::aic_gaintab_b2 */
#ifndef __AIC_GAINTAB_B2_MACRO__
#define __AIC_GAINTAB_B2_MACRO__

/* macros for field aic_atten */
#define AIC_GAINTAB_B2__AIC_ATTEN__SHIFT                                      0
#define AIC_GAINTAB_B2__AIC_ATTEN__WIDTH                                     18
#define AIC_GAINTAB_B2__AIC_ATTEN__MASK                             0x0003ffffU
#define AIC_GAINTAB_B2__AIC_ATTEN__READ(src)      (uint32_t)(src) & 0x0003ffffU
#define AIC_GAINTAB_B2__AIC_ATTEN__WRITE(src)   ((uint32_t)(src) & 0x0003ffffU)
#define AIC_GAINTAB_B2__AIC_ATTEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003ffffU) | ((uint32_t)(src) &\
                    0x0003ffffU)
#define AIC_GAINTAB_B2__AIC_ATTEN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0003ffffU)))
#define AIC_GAINTAB_B2__TYPE                                           uint32_t
#define AIC_GAINTAB_B2__READ                                        0x0003ffffU
#define AIC_GAINTAB_B2__WRITE                                       0x0003ffffU

#endif /* __AIC_GAINTAB_B2_MACRO__ */


/* macros for BB_aic_gain_tab_b2 */
#define INST_BB_AIC_GAIN_TAB_B2__NUM                                         19

/* macros for BlueprintGlobalNameSpace::dc_dac_mem_b2 */
#ifndef __DC_DAC_MEM_B2_MACRO__
#define __DC_DAC_MEM_B2_MACRO__

/* macros for field dc_dac_setting */
#define DC_DAC_MEM_B2__DC_DAC_SETTING__SHIFT                                  0
#define DC_DAC_MEM_B2__DC_DAC_SETTING__WIDTH                                 20
#define DC_DAC_MEM_B2__DC_DAC_SETTING__MASK                         0x000fffffU
#define DC_DAC_MEM_B2__DC_DAC_SETTING__READ(src)  (uint32_t)(src) & 0x000fffffU
#define DC_DAC_MEM_B2__DC_DAC_SETTING__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000fffffU)
#define DC_DAC_MEM_B2__DC_DAC_SETTING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000fffffU) | ((uint32_t)(src) &\
                    0x000fffffU)
#define DC_DAC_MEM_B2__DC_DAC_SETTING__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000fffffU)))
#define DC_DAC_MEM_B2__TYPE                                            uint32_t
#define DC_DAC_MEM_B2__READ                                         0x000fffffU
#define DC_DAC_MEM_B2__WRITE                                        0x000fffffU

#endif /* __DC_DAC_MEM_B2_MACRO__ */


/* macros for BB_dc_dac_mem_b2 */
#define INST_BB_DC_DAC_MEM_B2__NUM                                            4

/* macros for BlueprintGlobalNameSpace::sm2_tables_dummy2 */
#ifndef __SM2_TABLES_DUMMY2_MACRO__
#define __SM2_TABLES_DUMMY2_MACRO__

/* macros for field dummy2 */
#define SM2_TABLES_DUMMY2__DUMMY2__SHIFT                                      0
#define SM2_TABLES_DUMMY2__DUMMY2__WIDTH                                     32
#define SM2_TABLES_DUMMY2__DUMMY2__MASK                             0xffffffffU
#define SM2_TABLES_DUMMY2__DUMMY2__READ(src)      (uint32_t)(src) & 0xffffffffU
#define SM2_TABLES_DUMMY2__DUMMY2__WRITE(src)   ((uint32_t)(src) & 0xffffffffU)
#define SM2_TABLES_DUMMY2__DUMMY2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SM2_TABLES_DUMMY2__DUMMY2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SM2_TABLES_DUMMY2__TYPE                                        uint32_t
#define SM2_TABLES_DUMMY2__READ                                     0xffffffffU
#define SM2_TABLES_DUMMY2__WRITE                                    0xffffffffU

#endif /* __SM2_TABLES_DUMMY2_MACRO__ */


/* macros for BB_sm2_tables_dummy2 */
#define INST_BB_SM2_TABLES_DUMMY2__NUM                                        1

#define SM2_TABLE_MAP__VERSION \
                    "/cad/denali/blueprint/3.7.3/gen/ansic.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html2docbook.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html2sgml.pm\n\
                    /cad/local/lib/perl/Pinfo.pm\n\
                    /trees/cychao/cychao_peregrine_dev/ip/athr/wifi/dev/rtl/bb/blueprint/sm2_table_map.rdl\n\
                    /trees/cychao/cychao_peregrine_dev/ip/athr/wifi/dev/rtl/bb/blueprint/sm2_table_map_sysconfig.rdl"
#endif /* __REG_SM2_TABLE_MAP_MACRO_H__ */
