//                                                                             
// File:       ./ce_wrapper_reg_csr.h                                          
// Creator:    aadlakha                                                        
// Time:       Tuesday Jan 10, 2012 [3:32:26 pm]                               
//                                                                             
// Path:       /trees/aadlakha/aadlakha_peregrine/chips/peregrine/dev/ip/athr/ce/rtl/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux/blueprint -odir . -codegen   
//             ath_vrh.codegen -ath_vrh -ch -Wdesc ce_wrapper_reg.rdl          
//                                                                             
// Sources:    /trees/aadlakha/aadlakha_peregrine/chips/peregrine/dev/ip/athr/ce/rtl/blueprint/ce_wrapper_reg.rdl
//             /trees/aadlakha/aadlakha_peregrine/chips/peregrine/dev/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Tue Jun 23 00:17:01 PDT 2009)                           
// Machine:    underdog                                                        
// OS:         Linux 2.6.9-42.ELsmp                                            
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _CE_WRAPPER_REG_CSR_H_
#define _CE_WRAPPER_REG_CSR_H_
// 32'h0000 (CE_WRAPPER_INTERRUPT_SUMMARY)
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_MSB                    15
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_LSB                    8
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_MASK                   0x0000ff00
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_GET(x)                 (((x) & CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_MASK) >> CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_LSB)
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_SET(x)                 (((x) << CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_LSB) & CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_MASK)
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_RESET                  0x0 // 0
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_MSB                        7
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_LSB                        0
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_MASK                       0x000000ff
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_GET(x)                     (((x) & CE_WRAPPER_INTERRUPT_SUMMARY_MISC_MASK) >> CE_WRAPPER_INTERRUPT_SUMMARY_MISC_LSB)
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_SET(x)                     (((x) << CE_WRAPPER_INTERRUPT_SUMMARY_MISC_LSB) & CE_WRAPPER_INTERRUPT_SUMMARY_MISC_MASK)
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_RESET                      0x0 // 0
#define CE_WRAPPER_INTERRUPT_SUMMARY_ADDRESS                         0x0000
#define CE_WRAPPER_INTERRUPT_SUMMARY_OFFSET                          0x0000
// SW modifiable bits
#define CE_WRAPPER_INTERRUPT_SUMMARY_SW_MASK                         0x0000ffff
// bits defined at reset
#define CE_WRAPPER_INTERRUPT_SUMMARY_RSTMASK                         0xffffffff
// reset value (ignore bits undefined at reset)
#define CE_WRAPPER_INTERRUPT_SUMMARY_RESET                           0x00000000

// 32'h0004 (NUM_AXI_OUTSTANDING)
#define NUM_AXI_OUTSTANDING_WRITES_MSB                               9
#define NUM_AXI_OUTSTANDING_WRITES_LSB                               5
#define NUM_AXI_OUTSTANDING_WRITES_MASK                              0x000003e0
#define NUM_AXI_OUTSTANDING_WRITES_GET(x)                            (((x) & NUM_AXI_OUTSTANDING_WRITES_MASK) >> NUM_AXI_OUTSTANDING_WRITES_LSB)
#define NUM_AXI_OUTSTANDING_WRITES_SET(x)                            (((x) << NUM_AXI_OUTSTANDING_WRITES_LSB) & NUM_AXI_OUTSTANDING_WRITES_MASK)
#define NUM_AXI_OUTSTANDING_WRITES_RESET                             0x8 // 8
#define NUM_AXI_OUTSTANDING_READS_MSB                                4
#define NUM_AXI_OUTSTANDING_READS_LSB                                0
#define NUM_AXI_OUTSTANDING_READS_MASK                               0x0000001f
#define NUM_AXI_OUTSTANDING_READS_GET(x)                             (((x) & NUM_AXI_OUTSTANDING_READS_MASK) >> NUM_AXI_OUTSTANDING_READS_LSB)
#define NUM_AXI_OUTSTANDING_READS_SET(x)                             (((x) << NUM_AXI_OUTSTANDING_READS_LSB) & NUM_AXI_OUTSTANDING_READS_MASK)
#define NUM_AXI_OUTSTANDING_READS_RESET                              0x18 // 24
#define NUM_AXI_OUTSTANDING_ADDRESS                                  0x0004
#define NUM_AXI_OUTSTANDING_OFFSET                                   0x0004
// SW modifiable bits
#define NUM_AXI_OUTSTANDING_SW_MASK                                  0x000003ff
// bits defined at reset
#define NUM_AXI_OUTSTANDING_RSTMASK                                  0xffffffff
// reset value (ignore bits undefined at reset)
#define NUM_AXI_OUTSTANDING_RESET                                    0x00000118

// 32'h0008 (CE_WRAPPER_DEBUG)
#define CE_WRAPPER_DEBUG_SEL_MSB                                     5
#define CE_WRAPPER_DEBUG_SEL_LSB                                     0
#define CE_WRAPPER_DEBUG_SEL_MASK                                    0x0000003f
#define CE_WRAPPER_DEBUG_SEL_GET(x)                                  (((x) & CE_WRAPPER_DEBUG_SEL_MASK) >> CE_WRAPPER_DEBUG_SEL_LSB)
#define CE_WRAPPER_DEBUG_SEL_SET(x)                                  (((x) << CE_WRAPPER_DEBUG_SEL_LSB) & CE_WRAPPER_DEBUG_SEL_MASK)
#define CE_WRAPPER_DEBUG_SEL_RESET                                   0x0 // 0
#define CE_WRAPPER_DEBUG_ADDRESS                                     0x0008
#define CE_WRAPPER_DEBUG_OFFSET                                      0x0008
// SW modifiable bits
#define CE_WRAPPER_DEBUG_SW_MASK                                     0x0000003f
// bits defined at reset
#define CE_WRAPPER_DEBUG_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define CE_WRAPPER_DEBUG_RESET                                       0x00000000


#endif /* _CE_WRAPPER_REG_CSR_H_ */
