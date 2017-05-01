//                                                                             
// File:       ./dbi_reg.h                                                     
// Creator:    pyang                                                           
// Time:       Wednesday Aug 17, 2011 [11:18:25 am]                            
//                                                                             
// Path:       /trees/mbu-cn1/pyang/pyang_sn1/chips/hera/dev/rtl/wlan/pcie_wrap/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -ch -Wdesc -I                 
//             /trees/mbu-cn1/pyang/pyang_sn1/chips/hera/dev/blueprint/sysconfig
//             dbi_reg.rdl                                                     
//                                                                             
// Sources:    /trees/mbu-cn1/pyang/pyang_sn1/chips/hera/dev/rtl/wlan/pcie_wrap/blueprint/dbi_reg.rdl
//             /trees/mbu-cn1/pyang/pyang_sn1/chips/hera/dev/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    yuan                                                            
// OS:         Linux 2.6.9-89.ELlargesmp                                       
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _DBI_REG_H_
#define _DBI_REG_H_
// 32'h0000 (DBI_WINDOW_REG)
#define DBI_WINDOW_REG_DATA_MSB                                      31
#define DBI_WINDOW_REG_DATA_LSB                                      0
#define DBI_WINDOW_REG_DATA_MASK                                     0xffffffff
#define DBI_WINDOW_REG_DATA_GET(x)                                   (((x) & DBI_WINDOW_REG_DATA_MASK) >> DBI_WINDOW_REG_DATA_LSB)
#define DBI_WINDOW_REG_DATA_SET(x)                                   (((x) << DBI_WINDOW_REG_DATA_LSB) & DBI_WINDOW_REG_DATA_MASK)
#define DBI_WINDOW_REG_DATA_RESET                                    0x0 // 0
#define DBI_WINDOW_REG_ADDRESS                                       0x0000
#define DBI_WINDOW_REG_OFFSET                                        0x0000
// SW modifiable bits
#define DBI_WINDOW_REG_SW_MASK                                       0xffffffff
// bits defined at reset
#define DBI_WINDOW_REG_RSTMASK                                       0xffffffff
// reset value (ignore bits undefined at reset)
#define DBI_WINDOW_REG_RESET                                         0x00000000


#endif /* _DBI_REG_H_ */
