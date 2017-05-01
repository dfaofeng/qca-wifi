/*                                                                           */
/* File:       sm_table_map_macro.h                                          */
/* Creator:    xiaoru                                                        */
/* Time:       Thursday May 17, 2012 [3:08:38 pm]                            */
/*                                                                           */
/* Path:       /trees/xiaoru/xiaoru-tree/ip/athr/wifi/dev/rtl/bb/blueprint   */
/* Arguments:  /cad/denali/blueprint/3.7.3//Linux/blueprint -codegen         */
/*             verilogExtension.codegen -html -nojava -verilogExtension -vh  */
/*             -ansic sm_table_map.rdl                                       */
/*                                                                           */
/* Sources:    /trees/xiaoru/xiaoru-tree/ip/athr/wifi/dev/shared/blueprint/sysconfig/sm_table_map_sysconfig.rdl*/
/*             /trees/xiaoru/xiaoru-tree/ip/athr/wifi/dev/rtl/bb/blueprint/sm_table_map.rdl*/
/*             /cad/denali/blueprint/3.7.3/gen/html.pm                       */
/*             /cad/denali/blueprint/3.7.3/gen/html2docbook.pm               */
/*             /cad/denali/blueprint/3.7.3/gen/ansic.pm                      */
/*             /cad/denali/blueprint/3.7.3/gen/html2sgml.pm                  */
/*             /cad/local/lib/perl/Pinfo.pm                                  */
/*                                                                           */
/* Blueprint:   3.7.3 (Fri Aug 29 12:46:00 PDT 2008)                         */
/* Machine:    mac                                                           */
/* OS:         Linux 2.6.9-42.ELsmp                                          */
/* Description:                                                              */
/*                                                                           */
/* No Description Provided                                                   */
/*                                                                           */
/*                                                                           */


#ifndef __REG_SM_TABLE_MAP_MACRO_H__
#define __REG_SM_TABLE_MAP_MACRO_H__


/* macros for BlueprintGlobalNameSpace::sm_tables_dummy1 */
#ifndef __SM_TABLES_DUMMY1_MACRO__
#define __SM_TABLES_DUMMY1_MACRO__

/* macros for field dummy1 */
#define SM_TABLES_DUMMY1__DUMMY1__SHIFT                                       0
#define SM_TABLES_DUMMY1__DUMMY1__WIDTH                                      32
#define SM_TABLES_DUMMY1__DUMMY1__MASK                              0xffffffffU
#define SM_TABLES_DUMMY1__DUMMY1__READ(src)       (uint32_t)(src) & 0xffffffffU
#define SM_TABLES_DUMMY1__DUMMY1__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define SM_TABLES_DUMMY1__DUMMY1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SM_TABLES_DUMMY1__DUMMY1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SM_TABLES_DUMMY1__TYPE                                         uint32_t
#define SM_TABLES_DUMMY1__READ                                      0xffffffffU
#define SM_TABLES_DUMMY1__WRITE                                     0xffffffffU

#endif /* __SM_TABLES_DUMMY1_MACRO__ */


/* macros for BB_sm_tables_dummy1 */
#define INST_BB_SM_TABLES_DUMMY1__NUM                                         1

/* macros for BlueprintGlobalNameSpace::dc_dac_mem_b0 */
#ifndef __DC_DAC_MEM_B0_MACRO__
#define __DC_DAC_MEM_B0_MACRO__

/* macros for field dc_dac_setting */
#define DC_DAC_MEM_B0__DC_DAC_SETTING__SHIFT                                  0
#define DC_DAC_MEM_B0__DC_DAC_SETTING__WIDTH                                 20
#define DC_DAC_MEM_B0__DC_DAC_SETTING__MASK                         0x000fffffU
#define DC_DAC_MEM_B0__DC_DAC_SETTING__READ(src)  (uint32_t)(src) & 0x000fffffU
#define DC_DAC_MEM_B0__DC_DAC_SETTING__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000fffffU)
#define DC_DAC_MEM_B0__DC_DAC_SETTING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000fffffU) | ((uint32_t)(src) &\
                    0x000fffffU)
#define DC_DAC_MEM_B0__DC_DAC_SETTING__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000fffffU)))
#define DC_DAC_MEM_B0__TYPE                                            uint32_t
#define DC_DAC_MEM_B0__READ                                         0x000fffffU
#define DC_DAC_MEM_B0__WRITE                                        0x000fffffU

#endif /* __DC_DAC_MEM_B0_MACRO__ */


/* macros for BB_dc_dac_mem_b0 */
#define INST_BB_DC_DAC_MEM_B0__NUM                                            4

/* macros for BlueprintGlobalNameSpace::tpc_txgain_sram */
#ifndef __TPC_TXGAIN_SRAM_MACRO__
#define __TPC_TXGAIN_SRAM_MACRO__

/* macros for field tpc_txgain_word */
#define TPC_TXGAIN_SRAM__TPC_TXGAIN_WORD__SHIFT                               0
#define TPC_TXGAIN_SRAM__TPC_TXGAIN_WORD__WIDTH                              32
#define TPC_TXGAIN_SRAM__TPC_TXGAIN_WORD__MASK                      0xffffffffU
#define TPC_TXGAIN_SRAM__TPC_TXGAIN_WORD__READ(src) \
                    (uint32_t)(src)\
                    & 0xffffffffU
#define TPC_TXGAIN_SRAM__TPC_TXGAIN_WORD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define TPC_TXGAIN_SRAM__TPC_TXGAIN_WORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define TPC_TXGAIN_SRAM__TPC_TXGAIN_WORD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define TPC_TXGAIN_SRAM__TYPE                                          uint32_t
#define TPC_TXGAIN_SRAM__READ                                       0xffffffffU
#define TPC_TXGAIN_SRAM__WRITE                                      0xffffffffU

#endif /* __TPC_TXGAIN_SRAM_MACRO__ */


/* macros for BB_tpc_txgain_sram */
#define INST_BB_TPC_TXGAIN_SRAM__NUM                                         96

/* macros for BlueprintGlobalNameSpace::tpc_plut_sram */
#ifndef __TPC_PLUT_SRAM_MACRO__
#define __TPC_PLUT_SRAM_MACRO__

/* macros for field tpc_plut_word */
#define TPC_PLUT_SRAM__TPC_PLUT_WORD__SHIFT                                   0
#define TPC_PLUT_SRAM__TPC_PLUT_WORD__WIDTH                                  32
#define TPC_PLUT_SRAM__TPC_PLUT_WORD__MASK                          0xffffffffU
#define TPC_PLUT_SRAM__TPC_PLUT_WORD__READ(src)   (uint32_t)(src) & 0xffffffffU
#define TPC_PLUT_SRAM__TPC_PLUT_WORD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0xffffffffU)
#define TPC_PLUT_SRAM__TPC_PLUT_WORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define TPC_PLUT_SRAM__TPC_PLUT_WORD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define TPC_PLUT_SRAM__TYPE                                            uint32_t
#define TPC_PLUT_SRAM__READ                                         0xffffffffU
#define TPC_PLUT_SRAM__WRITE                                        0xffffffffU

#endif /* __TPC_PLUT_SRAM_MACRO__ */


/* macros for BB_tpc_plut_sram */
#define INST_BB_TPC_PLUT_SRAM__NUM                                          384

/* macros for BlueprintGlobalNameSpace::tpc_glut_sram */
#ifndef __TPC_GLUT_SRAM_MACRO__
#define __TPC_GLUT_SRAM_MACRO__

/* macros for field tpc_glut_word */
#define TPC_GLUT_SRAM__TPC_GLUT_WORD__SHIFT                                   0
#define TPC_GLUT_SRAM__TPC_GLUT_WORD__WIDTH                                  26
#define TPC_GLUT_SRAM__TPC_GLUT_WORD__MASK                          0x03ffffffU
#define TPC_GLUT_SRAM__TPC_GLUT_WORD__READ(src)   (uint32_t)(src) & 0x03ffffffU
#define TPC_GLUT_SRAM__TPC_GLUT_WORD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x03ffffffU)
#define TPC_GLUT_SRAM__TPC_GLUT_WORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03ffffffU) | ((uint32_t)(src) &\
                    0x03ffffffU)
#define TPC_GLUT_SRAM__TPC_GLUT_WORD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x03ffffffU)))
#define TPC_GLUT_SRAM__TYPE                                            uint32_t
#define TPC_GLUT_SRAM__READ                                         0x03ffffffU
#define TPC_GLUT_SRAM__WRITE                                        0x03ffffffU

#endif /* __TPC_GLUT_SRAM_MACRO__ */


/* macros for BB_tpc_glut_sram */
#define INST_BB_TPC_GLUT_SRAM__NUM                                          102

/* macros for BlueprintGlobalNameSpace::tpc_alut_sram */
#ifndef __TPC_ALUT_SRAM_MACRO__
#define __TPC_ALUT_SRAM_MACRO__

/* macros for field tpc_alut_word */
#define TPC_ALUT_SRAM__TPC_ALUT_WORD__SHIFT                                   0
#define TPC_ALUT_SRAM__TPC_ALUT_WORD__WIDTH                                  26
#define TPC_ALUT_SRAM__TPC_ALUT_WORD__MASK                          0x03ffffffU
#define TPC_ALUT_SRAM__TPC_ALUT_WORD__READ(src)   (uint32_t)(src) & 0x03ffffffU
#define TPC_ALUT_SRAM__TPC_ALUT_WORD__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x03ffffffU)
#define TPC_ALUT_SRAM__TPC_ALUT_WORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03ffffffU) | ((uint32_t)(src) &\
                    0x03ffffffU)
#define TPC_ALUT_SRAM__TPC_ALUT_WORD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x03ffffffU)))
#define TPC_ALUT_SRAM__TYPE                                            uint32_t
#define TPC_ALUT_SRAM__READ                                         0x03ffffffU
#define TPC_ALUT_SRAM__WRITE                                        0x03ffffffU

#endif /* __TPC_ALUT_SRAM_MACRO__ */


/* macros for BB_tpc_alut_sram */
#define INST_BB_TPC_ALUT_SRAM__NUM                                           96

/* macros for BlueprintGlobalNameSpace::sm_tables_dummy2 */
#ifndef __SM_TABLES_DUMMY2_MACRO__
#define __SM_TABLES_DUMMY2_MACRO__

/* macros for field dummy2 */
#define SM_TABLES_DUMMY2__DUMMY2__SHIFT                                       0
#define SM_TABLES_DUMMY2__DUMMY2__WIDTH                                      32
#define SM_TABLES_DUMMY2__DUMMY2__MASK                              0xffffffffU
#define SM_TABLES_DUMMY2__DUMMY2__READ(src)       (uint32_t)(src) & 0xffffffffU
#define SM_TABLES_DUMMY2__DUMMY2__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define SM_TABLES_DUMMY2__DUMMY2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SM_TABLES_DUMMY2__DUMMY2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SM_TABLES_DUMMY2__TYPE                                         uint32_t
#define SM_TABLES_DUMMY2__READ                                      0xffffffffU
#define SM_TABLES_DUMMY2__WRITE                                     0xffffffffU

#endif /* __SM_TABLES_DUMMY2_MACRO__ */


/* macros for BB_sm_tables_dummy2 */
#define INST_BB_SM_TABLES_DUMMY2__NUM                                         1

#define SM_TABLE_MAP__VERSION \
                    "/cad/denali/blueprint/3.7.3/gen/ansic.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html2docbook.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html2sgml.pm\n\
                    /cad/local/lib/perl/Pinfo.pm\n\
                    /trees/xiaoru/xiaoru-tree/ip/athr/wifi/dev/rtl/bb/blueprint/sm_table_map.rdl\n\
                    /trees/xiaoru/xiaoru-tree/ip/athr/wifi/dev/shared/blueprint/sysconfig/sm_table_map_sysconfig.rdl"
#endif /* __REG_SM_TABLE_MAP_MACRO_H__ */
