/*                                                                           */
/* File:       sm1_table_map_macro.h                                         */
/* Creator:    yflee                                                         */
/* Time:       Thursday May 3, 2012 [6:54:01 pm]                             */
/*                                                                           */
/* Path:       /trees/yflee/yflee-dev/ip/athr/wifi/dev/rtl/bb/blueprint      */
/* Arguments:  /cad/denali/blueprint/3.7.3//Linux-64bit/blueprint -codegen   */
/*             verilogExtension.codegen -html -nojava -verilogExtension -vh  */
/*             -ansic sm1_table_map.rdl                                      */
/*                                                                           */
/* Sources:    /trees/yflee/yflee-dev/ip/athr/wifi/dev/rtl/bb/blueprint/sm1_table_map.rdl*/
/*             /trees/yflee/yflee-dev/ip/athr/wifi/dev/shared/blueprint/sysconfig/sm1_table_map_sysconfig.rdl*/
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


#ifndef __REG_SM1_TABLE_MAP_MACRO_H__
#define __REG_SM1_TABLE_MAP_MACRO_H__


/* macros for BlueprintGlobalNameSpace::sm1_tables_dummy1 */
#ifndef __SM1_TABLES_DUMMY1_MACRO__
#define __SM1_TABLES_DUMMY1_MACRO__

/* macros for field dummy1 */
#define SM1_TABLES_DUMMY1__DUMMY1__SHIFT                                      0
#define SM1_TABLES_DUMMY1__DUMMY1__WIDTH                                     32
#define SM1_TABLES_DUMMY1__DUMMY1__MASK                             0xffffffffU
#define SM1_TABLES_DUMMY1__DUMMY1__READ(src)      (uint32_t)(src) & 0xffffffffU
#define SM1_TABLES_DUMMY1__DUMMY1__WRITE(src)   ((uint32_t)(src) & 0xffffffffU)
#define SM1_TABLES_DUMMY1__DUMMY1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SM1_TABLES_DUMMY1__DUMMY1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SM1_TABLES_DUMMY1__TYPE                                        uint32_t
#define SM1_TABLES_DUMMY1__READ                                     0xffffffffU
#define SM1_TABLES_DUMMY1__WRITE                                    0xffffffffU

#endif /* __SM1_TABLES_DUMMY1_MACRO__ */


/* macros for BB_sm1_tables_dummy1 */
#define INST_BB_SM1_TABLES_DUMMY1__NUM                                        1

/* macros for BlueprintGlobalNameSpace::dc_dac_mem_b1 */
#ifndef __DC_DAC_MEM_B1_MACRO__
#define __DC_DAC_MEM_B1_MACRO__

/* macros for field dc_dac_setting */
#define DC_DAC_MEM_B1__DC_DAC_SETTING__SHIFT                                  0
#define DC_DAC_MEM_B1__DC_DAC_SETTING__WIDTH                                 20
#define DC_DAC_MEM_B1__DC_DAC_SETTING__MASK                         0x000fffffU
#define DC_DAC_MEM_B1__DC_DAC_SETTING__READ(src)  (uint32_t)(src) & 0x000fffffU
#define DC_DAC_MEM_B1__DC_DAC_SETTING__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000fffffU)
#define DC_DAC_MEM_B1__DC_DAC_SETTING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000fffffU) | ((uint32_t)(src) &\
                    0x000fffffU)
#define DC_DAC_MEM_B1__DC_DAC_SETTING__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000fffffU)))
#define DC_DAC_MEM_B1__TYPE                                            uint32_t
#define DC_DAC_MEM_B1__READ                                         0x000fffffU
#define DC_DAC_MEM_B1__WRITE                                        0x000fffffU

#endif /* __DC_DAC_MEM_B1_MACRO__ */


/* macros for BB_dc_dac_mem_b1 */
#define INST_BB_DC_DAC_MEM_B1__NUM                                            4

/* macros for BlueprintGlobalNameSpace::sm1_tables_dummy2 */
#ifndef __SM1_TABLES_DUMMY2_MACRO__
#define __SM1_TABLES_DUMMY2_MACRO__

/* macros for field dummy2 */
#define SM1_TABLES_DUMMY2__DUMMY2__SHIFT                                      0
#define SM1_TABLES_DUMMY2__DUMMY2__WIDTH                                     32
#define SM1_TABLES_DUMMY2__DUMMY2__MASK                             0xffffffffU
#define SM1_TABLES_DUMMY2__DUMMY2__READ(src)      (uint32_t)(src) & 0xffffffffU
#define SM1_TABLES_DUMMY2__DUMMY2__WRITE(src)   ((uint32_t)(src) & 0xffffffffU)
#define SM1_TABLES_DUMMY2__DUMMY2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define SM1_TABLES_DUMMY2__DUMMY2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define SM1_TABLES_DUMMY2__TYPE                                        uint32_t
#define SM1_TABLES_DUMMY2__READ                                     0xffffffffU
#define SM1_TABLES_DUMMY2__WRITE                                    0xffffffffU

#endif /* __SM1_TABLES_DUMMY2_MACRO__ */


/* macros for BB_sm1_tables_dummy2 */
#define INST_BB_SM1_TABLES_DUMMY2__NUM                                        1

#define SM1_TABLE_MAP__VERSION \
                    "/cad/denali/blueprint/3.7.3/gen/ansic.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html2docbook.pm\n\
                    /cad/denali/blueprint/3.7.3/gen/html2sgml.pm\n\
                    /cad/local/lib/perl/Pinfo.pm\n\
                    /trees/yflee/yflee-dev/ip/athr/wifi/dev/rtl/bb/blueprint/sm1_table_map.rdl\n\
                    /trees/yflee/yflee-dev/ip/athr/wifi/dev/shared/blueprint/sysconfig/sm1_table_map_sysconfig.rdl"
#endif /* __REG_SM1_TABLE_MAP_MACRO_H__ */
