//                                                                             
// File:       ./athrI2cSlaveApbCsr.vrh                                        
// Creator:    lqiang                                                          
// Time:       Tuesday Nov 1, 2011 [11:03:45 pm]                               
//                                                                             
// Path:       /trees/mbu-cn1/lqiang/lqiang_hera_dv/chips/hera/dev/doc/headers/bp_wlan
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/mbu-cn1/lqiang/lqiang_hera_dv/chips/hera/dev/blueprint/sysconfig
//             athrI2cSlaveApbCsr.rdl                                          
//                                                                             
// Sources:    /trees/mbu-cn1/lqiang/lqiang_hera_dv/chips/hera/dev/ip/athr/i2c/slave/dev/rtl/athrI2cSlaveApbCsr.rdl
//             /trees/mbu-cn1/lqiang/lqiang_hera_dv/chips/hera/dev/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    shang                                                           
// OS:         Linux 2.6.9-67.ELsmp                                            
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _ATHRI2CSLAVEAPBCSR_H_
#define _ATHRI2CSLAVEAPBCSR_H_
// 0x0000 (I2CFIFOCONTROL)
#define I2CFIFOCONTROL_I2CFIFOWRITESTALL_MSB                         29
#define I2CFIFOCONTROL_I2CFIFOWRITESTALL_LSB                         29
#define I2CFIFOCONTROL_I2CFIFOWRITESTALL_MASK                        0x20000000
#define I2CFIFOCONTROL_I2CFIFOWRITESTALL_GET(x)                      (((x) & I2CFIFOCONTROL_I2CFIFOWRITESTALL_MASK) >> I2CFIFOCONTROL_I2CFIFOWRITESTALL_LSB)
#define I2CFIFOCONTROL_I2CFIFOWRITESTALL_SET(x)                      (((0 | (x)) << I2CFIFOCONTROL_I2CFIFOWRITESTALL_LSB) & I2CFIFOCONTROL_I2CFIFOWRITESTALL_MASK)
#define I2CFIFOCONTROL_I2CFIFOWRITESTALL_RESET                       0
#define I2CFIFOCONTROL_I2CFIFOWRITETHRESHOLD_MSB                     28
#define I2CFIFOCONTROL_I2CFIFOWRITETHRESHOLD_LSB                     19
#define I2CFIFOCONTROL_I2CFIFOWRITETHRESHOLD_MASK                    0x1ff80000
#define I2CFIFOCONTROL_I2CFIFOWRITETHRESHOLD_GET(x)                  (((x) & I2CFIFOCONTROL_I2CFIFOWRITETHRESHOLD_MASK) >> I2CFIFOCONTROL_I2CFIFOWRITETHRESHOLD_LSB)
#define I2CFIFOCONTROL_I2CFIFOWRITETHRESHOLD_SET(x)                  (((0 | (x)) << I2CFIFOCONTROL_I2CFIFOWRITETHRESHOLD_LSB) & I2CFIFOCONTROL_I2CFIFOWRITETHRESHOLD_MASK)
#define I2CFIFOCONTROL_I2CFIFOWRITETHRESHOLD_RESET                   0
#define I2CFIFOCONTROL_I2CFIFOWRITELENGTH_MSB                        18
#define I2CFIFOCONTROL_I2CFIFOWRITELENGTH_LSB                        16
#define I2CFIFOCONTROL_I2CFIFOWRITELENGTH_MASK                       0x00070000
#define I2CFIFOCONTROL_I2CFIFOWRITELENGTH_GET(x)                     (((x) & I2CFIFOCONTROL_I2CFIFOWRITELENGTH_MASK) >> I2CFIFOCONTROL_I2CFIFOWRITELENGTH_LSB)
#define I2CFIFOCONTROL_I2CFIFOWRITELENGTH_SET(x)                     (((0 | (x)) << I2CFIFOCONTROL_I2CFIFOWRITELENGTH_LSB) & I2CFIFOCONTROL_I2CFIFOWRITELENGTH_MASK)
#define I2CFIFOCONTROL_I2CFIFOWRITELENGTH_RESET                      0
#define I2CFIFOCONTROL_I2CFIFOREADSTALL_MSB                          15
#define I2CFIFOCONTROL_I2CFIFOREADSTALL_LSB                          15
#define I2CFIFOCONTROL_I2CFIFOREADSTALL_MASK                         0x00008000
#define I2CFIFOCONTROL_I2CFIFOREADSTALL_GET(x)                       (((x) & I2CFIFOCONTROL_I2CFIFOREADSTALL_MASK) >> I2CFIFOCONTROL_I2CFIFOREADSTALL_LSB)
#define I2CFIFOCONTROL_I2CFIFOREADSTALL_SET(x)                       (((0 | (x)) << I2CFIFOCONTROL_I2CFIFOREADSTALL_LSB) & I2CFIFOCONTROL_I2CFIFOREADSTALL_MASK)
#define I2CFIFOCONTROL_I2CFIFOREADSTALL_RESET                        0
#define I2CFIFOCONTROL_I2CFIFOREADTHRESHOLD_MSB                      14
#define I2CFIFOCONTROL_I2CFIFOREADTHRESHOLD_LSB                      5
#define I2CFIFOCONTROL_I2CFIFOREADTHRESHOLD_MASK                     0x00007fe0
#define I2CFIFOCONTROL_I2CFIFOREADTHRESHOLD_GET(x)                   (((x) & I2CFIFOCONTROL_I2CFIFOREADTHRESHOLD_MASK) >> I2CFIFOCONTROL_I2CFIFOREADTHRESHOLD_LSB)
#define I2CFIFOCONTROL_I2CFIFOREADTHRESHOLD_SET(x)                   (((0 | (x)) << I2CFIFOCONTROL_I2CFIFOREADTHRESHOLD_LSB) & I2CFIFOCONTROL_I2CFIFOREADTHRESHOLD_MASK)
#define I2CFIFOCONTROL_I2CFIFOREADTHRESHOLD_RESET                    0
#define I2CFIFOCONTROL_I2CFIFOREADLENGTH_MSB                         4
#define I2CFIFOCONTROL_I2CFIFOREADLENGTH_LSB                         2
#define I2CFIFOCONTROL_I2CFIFOREADLENGTH_MASK                        0x0000001c
#define I2CFIFOCONTROL_I2CFIFOREADLENGTH_GET(x)                      (((x) & I2CFIFOCONTROL_I2CFIFOREADLENGTH_MASK) >> I2CFIFOCONTROL_I2CFIFOREADLENGTH_LSB)
#define I2CFIFOCONTROL_I2CFIFOREADLENGTH_SET(x)                      (((0 | (x)) << I2CFIFOCONTROL_I2CFIFOREADLENGTH_LSB) & I2CFIFOCONTROL_I2CFIFOREADLENGTH_MASK)
#define I2CFIFOCONTROL_I2CFIFOREADLENGTH_RESET                       0
#define I2CFIFOCONTROL_I2CFIFOPREFETCH_MSB                           1
#define I2CFIFOCONTROL_I2CFIFOPREFETCH_LSB                           1
#define I2CFIFOCONTROL_I2CFIFOPREFETCH_MASK                          0x00000002
#define I2CFIFOCONTROL_I2CFIFOPREFETCH_GET(x)                        (((x) & I2CFIFOCONTROL_I2CFIFOPREFETCH_MASK) >> I2CFIFOCONTROL_I2CFIFOPREFETCH_LSB)
#define I2CFIFOCONTROL_I2CFIFOPREFETCH_SET(x)                        (((0 | (x)) << I2CFIFOCONTROL_I2CFIFOPREFETCH_LSB) & I2CFIFOCONTROL_I2CFIFOPREFETCH_MASK)
#define I2CFIFOCONTROL_I2CFIFOPREFETCH_RESET                         0
#define I2CFIFOCONTROL_I2CFIFORESET_MSB                              0
#define I2CFIFOCONTROL_I2CFIFORESET_LSB                              0
#define I2CFIFOCONTROL_I2CFIFORESET_MASK                             0x00000001
#define I2CFIFOCONTROL_I2CFIFORESET_GET(x)                           (((x) & I2CFIFOCONTROL_I2CFIFORESET_MASK) >> I2CFIFOCONTROL_I2CFIFORESET_LSB)
#define I2CFIFOCONTROL_I2CFIFORESET_SET(x)                           (((0 | (x)) << I2CFIFOCONTROL_I2CFIFORESET_LSB) & I2CFIFOCONTROL_I2CFIFORESET_MASK)
#define I2CFIFOCONTROL_I2CFIFORESET_RESET                            1
#define I2CFIFOCONTROL_ADDRESS                                       0x0000
#define I2CFIFOCONTROL_HW_MASK                                       0x3fffffff
#define I2CFIFOCONTROL_SW_MASK                                       0x3fffffff
#define I2CFIFOCONTROL_HW_WRITE_MASK                                 0x00000000
#define I2CFIFOCONTROL_SW_WRITE_MASK                                 0x3fffffff
#define I2CFIFOCONTROL_RSTMASK                                       0xfff8ffe3
#define I2CFIFOCONTROL_RESET                                         0x00000001

// 0x0004 (I2CFIFOREADPTR)
#define I2CFIFOREADPTR_I2CFIFOREADRDPTR_MSB                          25
#define I2CFIFOREADPTR_I2CFIFOREADRDPTR_LSB                          16
#define I2CFIFOREADPTR_I2CFIFOREADRDPTR_MASK                         0x03ff0000
#define I2CFIFOREADPTR_I2CFIFOREADRDPTR_GET(x)                       (((x) & I2CFIFOREADPTR_I2CFIFOREADRDPTR_MASK) >> I2CFIFOREADPTR_I2CFIFOREADRDPTR_LSB)
#define I2CFIFOREADPTR_I2CFIFOREADRDPTR_SET(x)                       (((0 | (x)) << I2CFIFOREADPTR_I2CFIFOREADRDPTR_LSB) & I2CFIFOREADPTR_I2CFIFOREADRDPTR_MASK)
#define I2CFIFOREADPTR_I2CFIFOREADRDPTR_RESET                        0
#define I2CFIFOREADPTR_I2CFIFOREADWRPTR_MSB                          9
#define I2CFIFOREADPTR_I2CFIFOREADWRPTR_LSB                          0
#define I2CFIFOREADPTR_I2CFIFOREADWRPTR_MASK                         0x000003ff
#define I2CFIFOREADPTR_I2CFIFOREADWRPTR_GET(x)                       (((x) & I2CFIFOREADPTR_I2CFIFOREADWRPTR_MASK) >> I2CFIFOREADPTR_I2CFIFOREADWRPTR_LSB)
#define I2CFIFOREADPTR_I2CFIFOREADWRPTR_SET(x)                       (((0 | (x)) << I2CFIFOREADPTR_I2CFIFOREADWRPTR_LSB) & I2CFIFOREADPTR_I2CFIFOREADWRPTR_MASK)
#define I2CFIFOREADPTR_I2CFIFOREADWRPTR_RESET                        0
#define I2CFIFOREADPTR_ADDRESS                                       0x0004
#define I2CFIFOREADPTR_HW_MASK                                       0x03ff03ff
#define I2CFIFOREADPTR_SW_MASK                                       0x03ff03ff
#define I2CFIFOREADPTR_HW_WRITE_MASK                                 0x03ff03ff
#define I2CFIFOREADPTR_SW_WRITE_MASK                                 0x00000000
#define I2CFIFOREADPTR_RSTMASK                                       0xfc00ffff
#define I2CFIFOREADPTR_RESET                                         0x00000000

// 0x0008 (I2CFIFOREADUPDATE)
#define I2CFIFOREADUPDATE_I2CFIFOREADUPDATE_MSB                      10
#define I2CFIFOREADUPDATE_I2CFIFOREADUPDATE_LSB                      0
#define I2CFIFOREADUPDATE_I2CFIFOREADUPDATE_MASK                     0x000007ff
#define I2CFIFOREADUPDATE_I2CFIFOREADUPDATE_GET(x)                   (((x) & I2CFIFOREADUPDATE_I2CFIFOREADUPDATE_MASK) >> I2CFIFOREADUPDATE_I2CFIFOREADUPDATE_LSB)
#define I2CFIFOREADUPDATE_I2CFIFOREADUPDATE_SET(x)                   (((0 | (x)) << I2CFIFOREADUPDATE_I2CFIFOREADUPDATE_LSB) & I2CFIFOREADUPDATE_I2CFIFOREADUPDATE_MASK)
#define I2CFIFOREADUPDATE_I2CFIFOREADUPDATE_RESET                    0
#define I2CFIFOREADUPDATE_ADDRESS                                    0x0008
#define I2CFIFOREADUPDATE_HW_MASK                                    0x000007ff
#define I2CFIFOREADUPDATE_SW_MASK                                    0x000007ff
#define I2CFIFOREADUPDATE_HW_WRITE_MASK                              0x000007ff
#define I2CFIFOREADUPDATE_SW_WRITE_MASK                              0x000007ff
#define I2CFIFOREADUPDATE_RSTMASK                                    0xfffff800
#define I2CFIFOREADUPDATE_RESET                                      0x00000000

// 0x000c (I2CFIFOREADBASEADDR)
#define I2CFIFOREADBASEADDR_I2CFIFOREADBASEADDR_MSB                  31
#define I2CFIFOREADBASEADDR_I2CFIFOREADBASEADDR_LSB                  0
#define I2CFIFOREADBASEADDR_I2CFIFOREADBASEADDR_MASK                 0xffffffff
#define I2CFIFOREADBASEADDR_I2CFIFOREADBASEADDR_GET(x)               (((x) & I2CFIFOREADBASEADDR_I2CFIFOREADBASEADDR_MASK) >> I2CFIFOREADBASEADDR_I2CFIFOREADBASEADDR_LSB)
#define I2CFIFOREADBASEADDR_I2CFIFOREADBASEADDR_SET(x)               (((0 | (x)) << I2CFIFOREADBASEADDR_I2CFIFOREADBASEADDR_LSB) & I2CFIFOREADBASEADDR_I2CFIFOREADBASEADDR_MASK)
#define I2CFIFOREADBASEADDR_I2CFIFOREADBASEADDR_RESET                0
#define I2CFIFOREADBASEADDR_ADDRESS                                  0x000c
#define I2CFIFOREADBASEADDR_HW_MASK                                  0xffffffff
#define I2CFIFOREADBASEADDR_SW_MASK                                  0xffffffff
#define I2CFIFOREADBASEADDR_HW_WRITE_MASK                            0x00000000
#define I2CFIFOREADBASEADDR_SW_WRITE_MASK                            0xffffffff
#define I2CFIFOREADBASEADDR_RSTMASK                                  0x00000000
#define I2CFIFOREADBASEADDR_RESET                                    0x00000000

// 0x0010 (I2CFIFOWRITEPTR)
#define I2CFIFOWRITEPTR_I2CFIFOWRITERDPTR_MSB                        25
#define I2CFIFOWRITEPTR_I2CFIFOWRITERDPTR_LSB                        16
#define I2CFIFOWRITEPTR_I2CFIFOWRITERDPTR_MASK                       0x03ff0000
#define I2CFIFOWRITEPTR_I2CFIFOWRITERDPTR_GET(x)                     (((x) & I2CFIFOWRITEPTR_I2CFIFOWRITERDPTR_MASK) >> I2CFIFOWRITEPTR_I2CFIFOWRITERDPTR_LSB)
#define I2CFIFOWRITEPTR_I2CFIFOWRITERDPTR_SET(x)                     (((0 | (x)) << I2CFIFOWRITEPTR_I2CFIFOWRITERDPTR_LSB) & I2CFIFOWRITEPTR_I2CFIFOWRITERDPTR_MASK)
#define I2CFIFOWRITEPTR_I2CFIFOWRITERDPTR_RESET                      0
#define I2CFIFOWRITEPTR_I2CFIFOWRITEWRPTR_MSB                        9
#define I2CFIFOWRITEPTR_I2CFIFOWRITEWRPTR_LSB                        0
#define I2CFIFOWRITEPTR_I2CFIFOWRITEWRPTR_MASK                       0x000003ff
#define I2CFIFOWRITEPTR_I2CFIFOWRITEWRPTR_GET(x)                     (((x) & I2CFIFOWRITEPTR_I2CFIFOWRITEWRPTR_MASK) >> I2CFIFOWRITEPTR_I2CFIFOWRITEWRPTR_LSB)
#define I2CFIFOWRITEPTR_I2CFIFOWRITEWRPTR_SET(x)                     (((0 | (x)) << I2CFIFOWRITEPTR_I2CFIFOWRITEWRPTR_LSB) & I2CFIFOWRITEPTR_I2CFIFOWRITEWRPTR_MASK)
#define I2CFIFOWRITEPTR_I2CFIFOWRITEWRPTR_RESET                      0
#define I2CFIFOWRITEPTR_ADDRESS                                      0x0010
#define I2CFIFOWRITEPTR_HW_MASK                                      0x03ff03ff
#define I2CFIFOWRITEPTR_SW_MASK                                      0x03ff03ff
#define I2CFIFOWRITEPTR_HW_WRITE_MASK                                0x03ff03ff
#define I2CFIFOWRITEPTR_SW_WRITE_MASK                                0x00000000
#define I2CFIFOWRITEPTR_RSTMASK                                      0xfc00ffff
#define I2CFIFOWRITEPTR_RESET                                        0x00000000

// 0x0014 (I2CFIFOWRITEUPDATE)
#define I2CFIFOWRITEUPDATE_I2CFIFOWRITEUPDATE_MSB                    10
#define I2CFIFOWRITEUPDATE_I2CFIFOWRITEUPDATE_LSB                    0
#define I2CFIFOWRITEUPDATE_I2CFIFOWRITEUPDATE_MASK                   0x000007ff
#define I2CFIFOWRITEUPDATE_I2CFIFOWRITEUPDATE_GET(x)                 (((x) & I2CFIFOWRITEUPDATE_I2CFIFOWRITEUPDATE_MASK) >> I2CFIFOWRITEUPDATE_I2CFIFOWRITEUPDATE_LSB)
#define I2CFIFOWRITEUPDATE_I2CFIFOWRITEUPDATE_SET(x)                 (((0 | (x)) << I2CFIFOWRITEUPDATE_I2CFIFOWRITEUPDATE_LSB) & I2CFIFOWRITEUPDATE_I2CFIFOWRITEUPDATE_MASK)
#define I2CFIFOWRITEUPDATE_I2CFIFOWRITEUPDATE_RESET                  0
#define I2CFIFOWRITEUPDATE_ADDRESS                                   0x0014
#define I2CFIFOWRITEUPDATE_HW_MASK                                   0x000007ff
#define I2CFIFOWRITEUPDATE_SW_MASK                                   0x000007ff
#define I2CFIFOWRITEUPDATE_HW_WRITE_MASK                             0x000007ff
#define I2CFIFOWRITEUPDATE_SW_WRITE_MASK                             0x000007ff
#define I2CFIFOWRITEUPDATE_RSTMASK                                   0xfffff800
#define I2CFIFOWRITEUPDATE_RESET                                     0x00000000

// 0x0018 (I2CFIFOWRITEBASEADDR)
#define I2CFIFOWRITEBASEADDR_I2CFIFOWRITEBASEADDR_MSB                31
#define I2CFIFOWRITEBASEADDR_I2CFIFOWRITEBASEADDR_LSB                0
#define I2CFIFOWRITEBASEADDR_I2CFIFOWRITEBASEADDR_MASK               0xffffffff
#define I2CFIFOWRITEBASEADDR_I2CFIFOWRITEBASEADDR_GET(x)             (((x) & I2CFIFOWRITEBASEADDR_I2CFIFOWRITEBASEADDR_MASK) >> I2CFIFOWRITEBASEADDR_I2CFIFOWRITEBASEADDR_LSB)
#define I2CFIFOWRITEBASEADDR_I2CFIFOWRITEBASEADDR_SET(x)             (((0 | (x)) << I2CFIFOWRITEBASEADDR_I2CFIFOWRITEBASEADDR_LSB) & I2CFIFOWRITEBASEADDR_I2CFIFOWRITEBASEADDR_MASK)
#define I2CFIFOWRITEBASEADDR_I2CFIFOWRITEBASEADDR_RESET              0
#define I2CFIFOWRITEBASEADDR_ADDRESS                                 0x0018
#define I2CFIFOWRITEBASEADDR_HW_MASK                                 0xffffffff
#define I2CFIFOWRITEBASEADDR_SW_MASK                                 0xffffffff
#define I2CFIFOWRITEBASEADDR_HW_WRITE_MASK                           0x00000000
#define I2CFIFOWRITEBASEADDR_SW_WRITE_MASK                           0xffffffff
#define I2CFIFOWRITEBASEADDR_RSTMASK                                 0x00000000
#define I2CFIFOWRITEBASEADDR_RESET                                   0x00000000

// 0x001c (I2CMEMCONTROL)
#define I2CMEMCONTROL_I2CMEMFLUSH_MSB                                1
#define I2CMEMCONTROL_I2CMEMFLUSH_LSB                                1
#define I2CMEMCONTROL_I2CMEMFLUSH_MASK                               0x00000002
#define I2CMEMCONTROL_I2CMEMFLUSH_GET(x)                             (((x) & I2CMEMCONTROL_I2CMEMFLUSH_MASK) >> I2CMEMCONTROL_I2CMEMFLUSH_LSB)
#define I2CMEMCONTROL_I2CMEMFLUSH_SET(x)                             (((0 | (x)) << I2CMEMCONTROL_I2CMEMFLUSH_LSB) & I2CMEMCONTROL_I2CMEMFLUSH_MASK)
#define I2CMEMCONTROL_I2CMEMFLUSH_RESET                              0
#define I2CMEMCONTROL_I2CMEMRESET_MSB                                0
#define I2CMEMCONTROL_I2CMEMRESET_LSB                                0
#define I2CMEMCONTROL_I2CMEMRESET_MASK                               0x00000001
#define I2CMEMCONTROL_I2CMEMRESET_GET(x)                             (((x) & I2CMEMCONTROL_I2CMEMRESET_MASK) >> I2CMEMCONTROL_I2CMEMRESET_LSB)
#define I2CMEMCONTROL_I2CMEMRESET_SET(x)                             (((0 | (x)) << I2CMEMCONTROL_I2CMEMRESET_LSB) & I2CMEMCONTROL_I2CMEMRESET_MASK)
#define I2CMEMCONTROL_I2CMEMRESET_RESET                              1
#define I2CMEMCONTROL_ADDRESS                                        0x001c
#define I2CMEMCONTROL_HW_MASK                                        0x00000003
#define I2CMEMCONTROL_SW_MASK                                        0x00000003
#define I2CMEMCONTROL_HW_WRITE_MASK                                  0x00000000
#define I2CMEMCONTROL_SW_WRITE_MASK                                  0x00000003
#define I2CMEMCONTROL_RSTMASK                                        0xffffffff
#define I2CMEMCONTROL_RESET                                          0x00000001

// 0x0020 (I2CMEMBASEADDR)
#define I2CMEMBASEADDR_I2CMEMBASEADDR_MSB                            31
#define I2CMEMBASEADDR_I2CMEMBASEADDR_LSB                            0
#define I2CMEMBASEADDR_I2CMEMBASEADDR_MASK                           0xffffffff
#define I2CMEMBASEADDR_I2CMEMBASEADDR_GET(x)                         (((x) & I2CMEMBASEADDR_I2CMEMBASEADDR_MASK) >> I2CMEMBASEADDR_I2CMEMBASEADDR_LSB)
#define I2CMEMBASEADDR_I2CMEMBASEADDR_SET(x)                         (((0 | (x)) << I2CMEMBASEADDR_I2CMEMBASEADDR_LSB) & I2CMEMBASEADDR_I2CMEMBASEADDR_MASK)
#define I2CMEMBASEADDR_I2CMEMBASEADDR_RESET                          0
#define I2CMEMBASEADDR_ADDRESS                                       0x0020
#define I2CMEMBASEADDR_HW_MASK                                       0xffffffff
#define I2CMEMBASEADDR_SW_MASK                                       0xffffffff
#define I2CMEMBASEADDR_HW_WRITE_MASK                                 0xffffffff
#define I2CMEMBASEADDR_SW_WRITE_MASK                                 0xffffffff
#define I2CMEMBASEADDR_RSTMASK                                       0xffffffff
#define I2CMEMBASEADDR_RESET                                         0x00000000

// 0x0024 (I2CREGREADDATA)
#define I2CREGREADDATA_I2CREGREADDATA_MSB                            31
#define I2CREGREADDATA_I2CREGREADDATA_LSB                            0
#define I2CREGREADDATA_I2CREGREADDATA_MASK                           0xffffffff
#define I2CREGREADDATA_I2CREGREADDATA_GET(x)                         (((x) & I2CREGREADDATA_I2CREGREADDATA_MASK) >> I2CREGREADDATA_I2CREGREADDATA_LSB)
#define I2CREGREADDATA_I2CREGREADDATA_SET(x)                         (((0 | (x)) << I2CREGREADDATA_I2CREGREADDATA_LSB) & I2CREGREADDATA_I2CREGREADDATA_MASK)
#define I2CREGREADDATA_I2CREGREADDATA_RESET                          0
#define I2CREGREADDATA_ADDRESS                                       0x0024
#define I2CREGREADDATA_HW_MASK                                       0xffffffff
#define I2CREGREADDATA_SW_MASK                                       0xffffffff
#define I2CREGREADDATA_HW_WRITE_MASK                                 0x00000000
#define I2CREGREADDATA_SW_WRITE_MASK                                 0xffffffff
#define I2CREGREADDATA_RSTMASK                                       0x00000000
#define I2CREGREADDATA_RESET                                         0x00000000

// 0x0028 (I2CREGWRITEDATA)
#define I2CREGWRITEDATA_I2CREGWRITEDATA_MSB                          31
#define I2CREGWRITEDATA_I2CREGWRITEDATA_LSB                          0
#define I2CREGWRITEDATA_I2CREGWRITEDATA_MASK                         0xffffffff
#define I2CREGWRITEDATA_I2CREGWRITEDATA_GET(x)                       (((x) & I2CREGWRITEDATA_I2CREGWRITEDATA_MASK) >> I2CREGWRITEDATA_I2CREGWRITEDATA_LSB)
#define I2CREGWRITEDATA_I2CREGWRITEDATA_SET(x)                       (((0 | (x)) << I2CREGWRITEDATA_I2CREGWRITEDATA_LSB) & I2CREGWRITEDATA_I2CREGWRITEDATA_MASK)
#define I2CREGWRITEDATA_I2CREGWRITEDATA_RESET                        0
#define I2CREGWRITEDATA_ADDRESS                                      0x0028
#define I2CREGWRITEDATA_HW_MASK                                      0xffffffff
#define I2CREGWRITEDATA_SW_MASK                                      0xffffffff
#define I2CREGWRITEDATA_HW_WRITE_MASK                                0xffffffff
#define I2CREGWRITEDATA_SW_WRITE_MASK                                0x00000000
#define I2CREGWRITEDATA_RSTMASK                                      0x00000000
#define I2CREGWRITEDATA_RESET                                        0x00000000

// 0x002c (I2CREGCONTROL)
#define I2CREGCONTROL_I2CREGWRITEFULL_MSB                            10
#define I2CREGCONTROL_I2CREGWRITEFULL_LSB                            10
#define I2CREGCONTROL_I2CREGWRITEFULL_MASK                           0x00000400
#define I2CREGCONTROL_I2CREGWRITEFULL_GET(x)                         (((x) & I2CREGCONTROL_I2CREGWRITEFULL_MASK) >> I2CREGCONTROL_I2CREGWRITEFULL_LSB)
#define I2CREGCONTROL_I2CREGWRITEFULL_SET(x)                         (((0 | (x)) << I2CREGCONTROL_I2CREGWRITEFULL_LSB) & I2CREGCONTROL_I2CREGWRITEFULL_MASK)
#define I2CREGCONTROL_I2CREGWRITEFULL_RESET                          0
#define I2CREGCONTROL_I2CREGREADEMPTY_MSB                            9
#define I2CREGCONTROL_I2CREGREADEMPTY_LSB                            9
#define I2CREGCONTROL_I2CREGREADEMPTY_MASK                           0x00000200
#define I2CREGCONTROL_I2CREGREADEMPTY_GET(x)                         (((x) & I2CREGCONTROL_I2CREGREADEMPTY_MASK) >> I2CREGCONTROL_I2CREGREADEMPTY_LSB)
#define I2CREGCONTROL_I2CREGREADEMPTY_SET(x)                         (((0 | (x)) << I2CREGCONTROL_I2CREGREADEMPTY_LSB) & I2CREGCONTROL_I2CREGREADEMPTY_MASK)
#define I2CREGCONTROL_I2CREGREADEMPTY_RESET                          0
#define I2CREGCONTROL_I2CREGWRITECOUNT_MSB                           8
#define I2CREGCONTROL_I2CREGWRITECOUNT_LSB                           6
#define I2CREGCONTROL_I2CREGWRITECOUNT_MASK                          0x000001c0
#define I2CREGCONTROL_I2CREGWRITECOUNT_GET(x)                        (((x) & I2CREGCONTROL_I2CREGWRITECOUNT_MASK) >> I2CREGCONTROL_I2CREGWRITECOUNT_LSB)
#define I2CREGCONTROL_I2CREGWRITECOUNT_SET(x)                        (((0 | (x)) << I2CREGCONTROL_I2CREGWRITECOUNT_LSB) & I2CREGCONTROL_I2CREGWRITECOUNT_MASK)
#define I2CREGCONTROL_I2CREGWRITECOUNT_RESET                         0
#define I2CREGCONTROL_I2CREGREADCOUNT_MSB                            5
#define I2CREGCONTROL_I2CREGREADCOUNT_LSB                            3
#define I2CREGCONTROL_I2CREGREADCOUNT_MASK                           0x00000038
#define I2CREGCONTROL_I2CREGREADCOUNT_GET(x)                         (((x) & I2CREGCONTROL_I2CREGREADCOUNT_MASK) >> I2CREGCONTROL_I2CREGREADCOUNT_LSB)
#define I2CREGCONTROL_I2CREGREADCOUNT_SET(x)                         (((0 | (x)) << I2CREGCONTROL_I2CREGREADCOUNT_LSB) & I2CREGCONTROL_I2CREGREADCOUNT_MASK)
#define I2CREGCONTROL_I2CREGREADCOUNT_RESET                          0
#define I2CREGCONTROL_I2CREGWRITESTALL_MSB                           2
#define I2CREGCONTROL_I2CREGWRITESTALL_LSB                           2
#define I2CREGCONTROL_I2CREGWRITESTALL_MASK                          0x00000004
#define I2CREGCONTROL_I2CREGWRITESTALL_GET(x)                        (((x) & I2CREGCONTROL_I2CREGWRITESTALL_MASK) >> I2CREGCONTROL_I2CREGWRITESTALL_LSB)
#define I2CREGCONTROL_I2CREGWRITESTALL_SET(x)                        (((0 | (x)) << I2CREGCONTROL_I2CREGWRITESTALL_LSB) & I2CREGCONTROL_I2CREGWRITESTALL_MASK)
#define I2CREGCONTROL_I2CREGWRITESTALL_RESET                         0
#define I2CREGCONTROL_I2CREGREADSTALL_MSB                            1
#define I2CREGCONTROL_I2CREGREADSTALL_LSB                            1
#define I2CREGCONTROL_I2CREGREADSTALL_MASK                           0x00000002
#define I2CREGCONTROL_I2CREGREADSTALL_GET(x)                         (((x) & I2CREGCONTROL_I2CREGREADSTALL_MASK) >> I2CREGCONTROL_I2CREGREADSTALL_LSB)
#define I2CREGCONTROL_I2CREGREADSTALL_SET(x)                         (((0 | (x)) << I2CREGCONTROL_I2CREGREADSTALL_LSB) & I2CREGCONTROL_I2CREGREADSTALL_MASK)
#define I2CREGCONTROL_I2CREGREADSTALL_RESET                          0
#define I2CREGCONTROL_I2CREGRESET_MSB                                0
#define I2CREGCONTROL_I2CREGRESET_LSB                                0
#define I2CREGCONTROL_I2CREGRESET_MASK                               0x00000001
#define I2CREGCONTROL_I2CREGRESET_GET(x)                             (((x) & I2CREGCONTROL_I2CREGRESET_MASK) >> I2CREGCONTROL_I2CREGRESET_LSB)
#define I2CREGCONTROL_I2CREGRESET_SET(x)                             (((0 | (x)) << I2CREGCONTROL_I2CREGRESET_LSB) & I2CREGCONTROL_I2CREGRESET_MASK)
#define I2CREGCONTROL_I2CREGRESET_RESET                              1
#define I2CREGCONTROL_ADDRESS                                        0x002c
#define I2CREGCONTROL_HW_MASK                                        0x000007ff
#define I2CREGCONTROL_SW_MASK                                        0x000007ff
#define I2CREGCONTROL_HW_WRITE_MASK                                  0x000007f8
#define I2CREGCONTROL_SW_WRITE_MASK                                  0x00000007
#define I2CREGCONTROL_RSTMASK                                        0xfffff807
#define I2CREGCONTROL_RESET                                          0x00000001

// 0x0030 (I2CCSRREADDATA)
#define I2CCSRREADDATA_I2CCSRREADDATA_MSB                            5
#define I2CCSRREADDATA_I2CCSRREADDATA_LSB                            0
#define I2CCSRREADDATA_I2CCSRREADDATA_MASK                           0x0000003f
#define I2CCSRREADDATA_I2CCSRREADDATA_GET(x)                         (((x) & I2CCSRREADDATA_I2CCSRREADDATA_MASK) >> I2CCSRREADDATA_I2CCSRREADDATA_LSB)
#define I2CCSRREADDATA_I2CCSRREADDATA_SET(x)                         (((0 | (x)) << I2CCSRREADDATA_I2CCSRREADDATA_LSB) & I2CCSRREADDATA_I2CCSRREADDATA_MASK)
#define I2CCSRREADDATA_I2CCSRREADDATA_RESET                          0
#define I2CCSRREADDATA_ADDRESS                                       0x0030
#define I2CCSRREADDATA_HW_MASK                                       0x0000003f
#define I2CCSRREADDATA_SW_MASK                                       0x0000003f
#define I2CCSRREADDATA_HW_WRITE_MASK                                 0x00000000
#define I2CCSRREADDATA_SW_WRITE_MASK                                 0x0000003f
#define I2CCSRREADDATA_RSTMASK                                       0xffffffff
#define I2CCSRREADDATA_RESET                                         0x00000000

// 0x0034 (I2CCSRWRITEDATA)
#define I2CCSRWRITEDATA_I2CCSRWRITEDATA_MSB                          5
#define I2CCSRWRITEDATA_I2CCSRWRITEDATA_LSB                          0
#define I2CCSRWRITEDATA_I2CCSRWRITEDATA_MASK                         0x0000003f
#define I2CCSRWRITEDATA_I2CCSRWRITEDATA_GET(x)                       (((x) & I2CCSRWRITEDATA_I2CCSRWRITEDATA_MASK) >> I2CCSRWRITEDATA_I2CCSRWRITEDATA_LSB)
#define I2CCSRWRITEDATA_I2CCSRWRITEDATA_SET(x)                       (((0 | (x)) << I2CCSRWRITEDATA_I2CCSRWRITEDATA_LSB) & I2CCSRWRITEDATA_I2CCSRWRITEDATA_MASK)
#define I2CCSRWRITEDATA_I2CCSRWRITEDATA_RESET                        0
#define I2CCSRWRITEDATA_ADDRESS                                      0x0034
#define I2CCSRWRITEDATA_HW_MASK                                      0x0000003f
#define I2CCSRWRITEDATA_SW_MASK                                      0x0000003f
#define I2CCSRWRITEDATA_HW_WRITE_MASK                                0x0000003f
#define I2CCSRWRITEDATA_SW_WRITE_MASK                                0x00000000
#define I2CCSRWRITEDATA_RSTMASK                                      0xffffffff
#define I2CCSRWRITEDATA_RESET                                        0x00000000

// 0x0038 (I2CCSRCONTROL)
#define I2CCSRCONTROL_I2CCSRFILTERSCLRXSELECT_MSB                    20
#define I2CCSRCONTROL_I2CCSRFILTERSCLRXSELECT_LSB                    18
#define I2CCSRCONTROL_I2CCSRFILTERSCLRXSELECT_MASK                   0x001c0000
#define I2CCSRCONTROL_I2CCSRFILTERSCLRXSELECT_GET(x)                 (((x) & I2CCSRCONTROL_I2CCSRFILTERSCLRXSELECT_MASK) >> I2CCSRCONTROL_I2CCSRFILTERSCLRXSELECT_LSB)
#define I2CCSRCONTROL_I2CCSRFILTERSCLRXSELECT_SET(x)                 (((0 | (x)) << I2CCSRCONTROL_I2CCSRFILTERSCLRXSELECT_LSB) & I2CCSRCONTROL_I2CCSRFILTERSCLRXSELECT_MASK)
#define I2CCSRCONTROL_I2CCSRFILTERSCLRXSELECT_RESET                  0
#define I2CCSRCONTROL_I2CCSRFILTERSDARXSELECT_MSB                    17
#define I2CCSRCONTROL_I2CCSRFILTERSDARXSELECT_LSB                    15
#define I2CCSRCONTROL_I2CCSRFILTERSDARXSELECT_MASK                   0x00038000
#define I2CCSRCONTROL_I2CCSRFILTERSDARXSELECT_GET(x)                 (((x) & I2CCSRCONTROL_I2CCSRFILTERSDARXSELECT_MASK) >> I2CCSRCONTROL_I2CCSRFILTERSDARXSELECT_LSB)
#define I2CCSRCONTROL_I2CCSRFILTERSDARXSELECT_SET(x)                 (((0 | (x)) << I2CCSRCONTROL_I2CCSRFILTERSDARXSELECT_LSB) & I2CCSRCONTROL_I2CCSRFILTERSDARXSELECT_MASK)
#define I2CCSRCONTROL_I2CCSRFILTERSDARXSELECT_RESET                  0
#define I2CCSRCONTROL_I2CCSRFILTERCLOCKSCALE_MSB                     14
#define I2CCSRCONTROL_I2CCSRFILTERCLOCKSCALE_LSB                     12
#define I2CCSRCONTROL_I2CCSRFILTERCLOCKSCALE_MASK                    0x00007000
#define I2CCSRCONTROL_I2CCSRFILTERCLOCKSCALE_GET(x)                  (((x) & I2CCSRCONTROL_I2CCSRFILTERCLOCKSCALE_MASK) >> I2CCSRCONTROL_I2CCSRFILTERCLOCKSCALE_LSB)
#define I2CCSRCONTROL_I2CCSRFILTERCLOCKSCALE_SET(x)                  (((0 | (x)) << I2CCSRCONTROL_I2CCSRFILTERCLOCKSCALE_LSB) & I2CCSRCONTROL_I2CCSRFILTERCLOCKSCALE_MASK)
#define I2CCSRCONTROL_I2CCSRFILTERCLOCKSCALE_RESET                   0
#define I2CCSRCONTROL_I2CCSRFILTERCLOCKSELECT_MSB                    11
#define I2CCSRCONTROL_I2CCSRFILTERCLOCKSELECT_LSB                    9
#define I2CCSRCONTROL_I2CCSRFILTERCLOCKSELECT_MASK                   0x00000e00
#define I2CCSRCONTROL_I2CCSRFILTERCLOCKSELECT_GET(x)                 (((x) & I2CCSRCONTROL_I2CCSRFILTERCLOCKSELECT_MASK) >> I2CCSRCONTROL_I2CCSRFILTERCLOCKSELECT_LSB)
#define I2CCSRCONTROL_I2CCSRFILTERCLOCKSELECT_SET(x)                 (((0 | (x)) << I2CCSRCONTROL_I2CCSRFILTERCLOCKSELECT_LSB) & I2CCSRCONTROL_I2CCSRFILTERCLOCKSELECT_MASK)
#define I2CCSRCONTROL_I2CCSRFILTERCLOCKSELECT_RESET                  0
#define I2CCSRCONTROL_I2CCSRCLOCKREQUESTENABLE_MSB                   8
#define I2CCSRCONTROL_I2CCSRCLOCKREQUESTENABLE_LSB                   8
#define I2CCSRCONTROL_I2CCSRCLOCKREQUESTENABLE_MASK                  0x00000100
#define I2CCSRCONTROL_I2CCSRCLOCKREQUESTENABLE_GET(x)                (((x) & I2CCSRCONTROL_I2CCSRCLOCKREQUESTENABLE_MASK) >> I2CCSRCONTROL_I2CCSRCLOCKREQUESTENABLE_LSB)
#define I2CCSRCONTROL_I2CCSRCLOCKREQUESTENABLE_SET(x)                (((0 | (x)) << I2CCSRCONTROL_I2CCSRCLOCKREQUESTENABLE_LSB) & I2CCSRCONTROL_I2CCSRCLOCKREQUESTENABLE_MASK)
#define I2CCSRCONTROL_I2CCSRCLOCKREQUESTENABLE_RESET                 0
#define I2CCSRCONTROL_I2CCSRREADDELAY_MSB                            7
#define I2CCSRCONTROL_I2CCSRREADDELAY_LSB                            0
#define I2CCSRCONTROL_I2CCSRREADDELAY_MASK                           0x000000ff
#define I2CCSRCONTROL_I2CCSRREADDELAY_GET(x)                         (((x) & I2CCSRCONTROL_I2CCSRREADDELAY_MASK) >> I2CCSRCONTROL_I2CCSRREADDELAY_LSB)
#define I2CCSRCONTROL_I2CCSRREADDELAY_SET(x)                         (((0 | (x)) << I2CCSRCONTROL_I2CCSRREADDELAY_LSB) & I2CCSRCONTROL_I2CCSRREADDELAY_MASK)
#define I2CCSRCONTROL_I2CCSRREADDELAY_RESET                          255
#define I2CCSRCONTROL_ADDRESS                                        0x0038
#define I2CCSRCONTROL_HW_MASK                                        0x001fffff
#define I2CCSRCONTROL_SW_MASK                                        0x001fffff
#define I2CCSRCONTROL_HW_WRITE_MASK                                  0x00000000
#define I2CCSRCONTROL_SW_WRITE_MASK                                  0x001fffff
#define I2CCSRCONTROL_RSTMASK                                        0xffffffff
#define I2CCSRCONTROL_RESET                                          0x000000ff

// 0x003c (I2CFILTERSIZE)
#define I2CFILTERSIZE_I2CFILTERSCLRXSIZE_MSB                         15
#define I2CFILTERSIZE_I2CFILTERSCLRXSIZE_LSB                         8
#define I2CFILTERSIZE_I2CFILTERSCLRXSIZE_MASK                        0x0000ff00
#define I2CFILTERSIZE_I2CFILTERSCLRXSIZE_GET(x)                      (((x) & I2CFILTERSIZE_I2CFILTERSCLRXSIZE_MASK) >> I2CFILTERSIZE_I2CFILTERSCLRXSIZE_LSB)
#define I2CFILTERSIZE_I2CFILTERSCLRXSIZE_SET(x)                      (((0 | (x)) << I2CFILTERSIZE_I2CFILTERSCLRXSIZE_LSB) & I2CFILTERSIZE_I2CFILTERSCLRXSIZE_MASK)
#define I2CFILTERSIZE_I2CFILTERSCLRXSIZE_RESET                       0
#define I2CFILTERSIZE_I2CFILTERSDARXSIZE_MSB                         7
#define I2CFILTERSIZE_I2CFILTERSDARXSIZE_LSB                         0
#define I2CFILTERSIZE_I2CFILTERSDARXSIZE_MASK                        0x000000ff
#define I2CFILTERSIZE_I2CFILTERSDARXSIZE_GET(x)                      (((x) & I2CFILTERSIZE_I2CFILTERSDARXSIZE_MASK) >> I2CFILTERSIZE_I2CFILTERSDARXSIZE_LSB)
#define I2CFILTERSIZE_I2CFILTERSDARXSIZE_SET(x)                      (((0 | (x)) << I2CFILTERSIZE_I2CFILTERSDARXSIZE_LSB) & I2CFILTERSIZE_I2CFILTERSDARXSIZE_MASK)
#define I2CFILTERSIZE_I2CFILTERSDARXSIZE_RESET                       0
#define I2CFILTERSIZE_ADDRESS                                        0x003c
#define I2CFILTERSIZE_HW_MASK                                        0x0000ffff
#define I2CFILTERSIZE_SW_MASK                                        0x0000ffff
#define I2CFILTERSIZE_HW_WRITE_MASK                                  0x00000000
#define I2CFILTERSIZE_SW_WRITE_MASK                                  0x0000ffff
#define I2CFILTERSIZE_RSTMASK                                        0xffffffff
#define I2CFILTERSIZE_RESET                                          0x00000000

// 0x0040 (I2CADDR)
#define I2CADDR_I2CCSRADDR_MSB                                       30
#define I2CADDR_I2CCSRADDR_LSB                                       24
#define I2CADDR_I2CCSRADDR_MASK                                      0x7f000000
#define I2CADDR_I2CCSRADDR_GET(x)                                    (((x) & I2CADDR_I2CCSRADDR_MASK) >> I2CADDR_I2CCSRADDR_LSB)
#define I2CADDR_I2CCSRADDR_SET(x)                                    (((0 | (x)) << I2CADDR_I2CCSRADDR_LSB) & I2CADDR_I2CCSRADDR_MASK)
#define I2CADDR_I2CCSRADDR_RESET                                     0
#define I2CADDR_I2CREGADDR_MSB                                       22
#define I2CADDR_I2CREGADDR_LSB                                       16
#define I2CADDR_I2CREGADDR_MASK                                      0x007f0000
#define I2CADDR_I2CREGADDR_GET(x)                                    (((x) & I2CADDR_I2CREGADDR_MASK) >> I2CADDR_I2CREGADDR_LSB)
#define I2CADDR_I2CREGADDR_SET(x)                                    (((0 | (x)) << I2CADDR_I2CREGADDR_LSB) & I2CADDR_I2CREGADDR_MASK)
#define I2CADDR_I2CREGADDR_RESET                                     0
#define I2CADDR_I2CMEMADDR_MSB                                       14
#define I2CADDR_I2CMEMADDR_LSB                                       8
#define I2CADDR_I2CMEMADDR_MASK                                      0x00007f00
#define I2CADDR_I2CMEMADDR_GET(x)                                    (((x) & I2CADDR_I2CMEMADDR_MASK) >> I2CADDR_I2CMEMADDR_LSB)
#define I2CADDR_I2CMEMADDR_SET(x)                                    (((0 | (x)) << I2CADDR_I2CMEMADDR_LSB) & I2CADDR_I2CMEMADDR_MASK)
#define I2CADDR_I2CMEMADDR_RESET                                     0
#define I2CADDR_I2CFIFOADDR_MSB                                      6
#define I2CADDR_I2CFIFOADDR_LSB                                      0
#define I2CADDR_I2CFIFOADDR_MASK                                     0x0000007f
#define I2CADDR_I2CFIFOADDR_GET(x)                                   (((x) & I2CADDR_I2CFIFOADDR_MASK) >> I2CADDR_I2CFIFOADDR_LSB)
#define I2CADDR_I2CFIFOADDR_SET(x)                                   (((0 | (x)) << I2CADDR_I2CFIFOADDR_LSB) & I2CADDR_I2CFIFOADDR_MASK)
#define I2CADDR_I2CFIFOADDR_RESET                                    0
#define I2CADDR_ADDRESS                                              0x0040
#define I2CADDR_HW_MASK                                              0x7f7f7f7f
#define I2CADDR_SW_MASK                                              0x7f7f7f7f
#define I2CADDR_HW_WRITE_MASK                                        0x00000000
#define I2CADDR_SW_WRITE_MASK                                        0x7f7f7f7f
#define I2CADDR_RSTMASK                                              0x80808080
#define I2CADDR_RESET                                                0x00000000

// 0x0044 (I2CINT)
#define I2CINT_I2CCSRINT_MSB                                         12
#define I2CINT_I2CCSRINT_LSB                                         12
#define I2CINT_I2CCSRINT_MASK                                        0x00001000
#define I2CINT_I2CCSRINT_GET(x)                                      (((x) & I2CINT_I2CCSRINT_MASK) >> I2CINT_I2CCSRINT_LSB)
#define I2CINT_I2CCSRINT_SET(x)                                      (((0 | (x)) << I2CINT_I2CCSRINT_LSB) & I2CINT_I2CCSRINT_MASK)
#define I2CINT_I2CCSRINT_RESET                                       0
#define I2CINT_I2CFIFOWRITETHRESHOLDINT_MSB                          11
#define I2CINT_I2CFIFOWRITETHRESHOLDINT_LSB                          11
#define I2CINT_I2CFIFOWRITETHRESHOLDINT_MASK                         0x00000800
#define I2CINT_I2CFIFOWRITETHRESHOLDINT_GET(x)                       (((x) & I2CINT_I2CFIFOWRITETHRESHOLDINT_MASK) >> I2CINT_I2CFIFOWRITETHRESHOLDINT_LSB)
#define I2CINT_I2CFIFOWRITETHRESHOLDINT_SET(x)                       (((0 | (x)) << I2CINT_I2CFIFOWRITETHRESHOLDINT_LSB) & I2CINT_I2CFIFOWRITETHRESHOLDINT_MASK)
#define I2CINT_I2CFIFOWRITETHRESHOLDINT_RESET                        0
#define I2CINT_I2CFIFOREADTHRESHOLDINT_MSB                           10
#define I2CINT_I2CFIFOREADTHRESHOLDINT_LSB                           10
#define I2CINT_I2CFIFOREADTHRESHOLDINT_MASK                          0x00000400
#define I2CINT_I2CFIFOREADTHRESHOLDINT_GET(x)                        (((x) & I2CINT_I2CFIFOREADTHRESHOLDINT_MASK) >> I2CINT_I2CFIFOREADTHRESHOLDINT_LSB)
#define I2CINT_I2CFIFOREADTHRESHOLDINT_SET(x)                        (((0 | (x)) << I2CINT_I2CFIFOREADTHRESHOLDINT_LSB) & I2CINT_I2CFIFOREADTHRESHOLDINT_MASK)
#define I2CINT_I2CFIFOREADTHRESHOLDINT_RESET                         0
#define I2CINT_I2CFIFOWRITEFULLINT_MSB                               9
#define I2CINT_I2CFIFOWRITEFULLINT_LSB                               9
#define I2CINT_I2CFIFOWRITEFULLINT_MASK                              0x00000200
#define I2CINT_I2CFIFOWRITEFULLINT_GET(x)                            (((x) & I2CINT_I2CFIFOWRITEFULLINT_MASK) >> I2CINT_I2CFIFOWRITEFULLINT_LSB)
#define I2CINT_I2CFIFOWRITEFULLINT_SET(x)                            (((0 | (x)) << I2CINT_I2CFIFOWRITEFULLINT_LSB) & I2CINT_I2CFIFOWRITEFULLINT_MASK)
#define I2CINT_I2CFIFOWRITEFULLINT_RESET                             0
#define I2CINT_I2CFIFOREADEMPTYINT_MSB                               8
#define I2CINT_I2CFIFOREADEMPTYINT_LSB                               8
#define I2CINT_I2CFIFOREADEMPTYINT_MASK                              0x00000100
#define I2CINT_I2CFIFOREADEMPTYINT_GET(x)                            (((x) & I2CINT_I2CFIFOREADEMPTYINT_MASK) >> I2CINT_I2CFIFOREADEMPTYINT_LSB)
#define I2CINT_I2CFIFOREADEMPTYINT_SET(x)                            (((0 | (x)) << I2CINT_I2CFIFOREADEMPTYINT_LSB) & I2CINT_I2CFIFOREADEMPTYINT_MASK)
#define I2CINT_I2CFIFOREADEMPTYINT_RESET                             0
#define I2CINT_I2CREGWRITEFINISHINT_MSB                              7
#define I2CINT_I2CREGWRITEFINISHINT_LSB                              7
#define I2CINT_I2CREGWRITEFINISHINT_MASK                             0x00000080
#define I2CINT_I2CREGWRITEFINISHINT_GET(x)                           (((x) & I2CINT_I2CREGWRITEFINISHINT_MASK) >> I2CINT_I2CREGWRITEFINISHINT_LSB)
#define I2CINT_I2CREGWRITEFINISHINT_SET(x)                           (((0 | (x)) << I2CINT_I2CREGWRITEFINISHINT_LSB) & I2CINT_I2CREGWRITEFINISHINT_MASK)
#define I2CINT_I2CREGWRITEFINISHINT_RESET                            0
#define I2CINT_I2CREGWRITESTARTINT_MSB                               6
#define I2CINT_I2CREGWRITESTARTINT_LSB                               6
#define I2CINT_I2CREGWRITESTARTINT_MASK                              0x00000040
#define I2CINT_I2CREGWRITESTARTINT_GET(x)                            (((x) & I2CINT_I2CREGWRITESTARTINT_MASK) >> I2CINT_I2CREGWRITESTARTINT_LSB)
#define I2CINT_I2CREGWRITESTARTINT_SET(x)                            (((0 | (x)) << I2CINT_I2CREGWRITESTARTINT_LSB) & I2CINT_I2CREGWRITESTARTINT_MASK)
#define I2CINT_I2CREGWRITESTARTINT_RESET                             0
#define I2CINT_I2CREGREADFINISHINT_MSB                               5
#define I2CINT_I2CREGREADFINISHINT_LSB                               5
#define I2CINT_I2CREGREADFINISHINT_MASK                              0x00000020
#define I2CINT_I2CREGREADFINISHINT_GET(x)                            (((x) & I2CINT_I2CREGREADFINISHINT_MASK) >> I2CINT_I2CREGREADFINISHINT_LSB)
#define I2CINT_I2CREGREADFINISHINT_SET(x)                            (((0 | (x)) << I2CINT_I2CREGREADFINISHINT_LSB) & I2CINT_I2CREGREADFINISHINT_MASK)
#define I2CINT_I2CREGREADFINISHINT_RESET                             0
#define I2CINT_I2CREGREADSTARTINT_MSB                                4
#define I2CINT_I2CREGREADSTARTINT_LSB                                4
#define I2CINT_I2CREGREADSTARTINT_MASK                               0x00000010
#define I2CINT_I2CREGREADSTARTINT_GET(x)                             (((x) & I2CINT_I2CREGREADSTARTINT_MASK) >> I2CINT_I2CREGREADSTARTINT_LSB)
#define I2CINT_I2CREGREADSTARTINT_SET(x)                             (((0 | (x)) << I2CINT_I2CREGREADSTARTINT_LSB) & I2CINT_I2CREGREADSTARTINT_MASK)
#define I2CINT_I2CREGREADSTARTINT_RESET                              0
#define I2CINT_I2CFIFOWRITEFINISHINT_MSB                             3
#define I2CINT_I2CFIFOWRITEFINISHINT_LSB                             3
#define I2CINT_I2CFIFOWRITEFINISHINT_MASK                            0x00000008
#define I2CINT_I2CFIFOWRITEFINISHINT_GET(x)                          (((x) & I2CINT_I2CFIFOWRITEFINISHINT_MASK) >> I2CINT_I2CFIFOWRITEFINISHINT_LSB)
#define I2CINT_I2CFIFOWRITEFINISHINT_SET(x)                          (((0 | (x)) << I2CINT_I2CFIFOWRITEFINISHINT_LSB) & I2CINT_I2CFIFOWRITEFINISHINT_MASK)
#define I2CINT_I2CFIFOWRITEFINISHINT_RESET                           0
#define I2CINT_I2CFIFOWRITESTARTINT_MSB                              2
#define I2CINT_I2CFIFOWRITESTARTINT_LSB                              2
#define I2CINT_I2CFIFOWRITESTARTINT_MASK                             0x00000004
#define I2CINT_I2CFIFOWRITESTARTINT_GET(x)                           (((x) & I2CINT_I2CFIFOWRITESTARTINT_MASK) >> I2CINT_I2CFIFOWRITESTARTINT_LSB)
#define I2CINT_I2CFIFOWRITESTARTINT_SET(x)                           (((0 | (x)) << I2CINT_I2CFIFOWRITESTARTINT_LSB) & I2CINT_I2CFIFOWRITESTARTINT_MASK)
#define I2CINT_I2CFIFOWRITESTARTINT_RESET                            0
#define I2CINT_I2CFIFOREADFINISHINT_MSB                              1
#define I2CINT_I2CFIFOREADFINISHINT_LSB                              1
#define I2CINT_I2CFIFOREADFINISHINT_MASK                             0x00000002
#define I2CINT_I2CFIFOREADFINISHINT_GET(x)                           (((x) & I2CINT_I2CFIFOREADFINISHINT_MASK) >> I2CINT_I2CFIFOREADFINISHINT_LSB)
#define I2CINT_I2CFIFOREADFINISHINT_SET(x)                           (((0 | (x)) << I2CINT_I2CFIFOREADFINISHINT_LSB) & I2CINT_I2CFIFOREADFINISHINT_MASK)
#define I2CINT_I2CFIFOREADFINISHINT_RESET                            0
#define I2CINT_I2CFIFOREADSTARTINT_MSB                               0
#define I2CINT_I2CFIFOREADSTARTINT_LSB                               0
#define I2CINT_I2CFIFOREADSTARTINT_MASK                              0x00000001
#define I2CINT_I2CFIFOREADSTARTINT_GET(x)                            (((x) & I2CINT_I2CFIFOREADSTARTINT_MASK) >> I2CINT_I2CFIFOREADSTARTINT_LSB)
#define I2CINT_I2CFIFOREADSTARTINT_SET(x)                            (((0 | (x)) << I2CINT_I2CFIFOREADSTARTINT_LSB) & I2CINT_I2CFIFOREADSTARTINT_MASK)
#define I2CINT_I2CFIFOREADSTARTINT_RESET                             0
#define I2CINT_ADDRESS                                               0x0044
#define I2CINT_HW_MASK                                               0x00001fff
#define I2CINT_SW_MASK                                               0x00001fff
#define I2CINT_HW_WRITE_MASK                                         0x00001fff
#define I2CINT_SW_WRITE_MASK                                         0x000010ff
#define I2CINT_RSTMASK                                               0xffffffff
#define I2CINT_RESET                                                 0x00000000

// 0x0048 (I2CINTEN)
#define I2CINTEN_I2CCSRINTEN_MSB                                     12
#define I2CINTEN_I2CCSRINTEN_LSB                                     12
#define I2CINTEN_I2CCSRINTEN_MASK                                    0x00001000
#define I2CINTEN_I2CCSRINTEN_GET(x)                                  (((x) & I2CINTEN_I2CCSRINTEN_MASK) >> I2CINTEN_I2CCSRINTEN_LSB)
#define I2CINTEN_I2CCSRINTEN_SET(x)                                  (((0 | (x)) << I2CINTEN_I2CCSRINTEN_LSB) & I2CINTEN_I2CCSRINTEN_MASK)
#define I2CINTEN_I2CCSRINTEN_RESET                                   0
#define I2CINTEN_I2CFIFOWRITETHRESHOLDINTEN_MSB                      11
#define I2CINTEN_I2CFIFOWRITETHRESHOLDINTEN_LSB                      11
#define I2CINTEN_I2CFIFOWRITETHRESHOLDINTEN_MASK                     0x00000800
#define I2CINTEN_I2CFIFOWRITETHRESHOLDINTEN_GET(x)                   (((x) & I2CINTEN_I2CFIFOWRITETHRESHOLDINTEN_MASK) >> I2CINTEN_I2CFIFOWRITETHRESHOLDINTEN_LSB)
#define I2CINTEN_I2CFIFOWRITETHRESHOLDINTEN_SET(x)                   (((0 | (x)) << I2CINTEN_I2CFIFOWRITETHRESHOLDINTEN_LSB) & I2CINTEN_I2CFIFOWRITETHRESHOLDINTEN_MASK)
#define I2CINTEN_I2CFIFOWRITETHRESHOLDINTEN_RESET                    0
#define I2CINTEN_I2CFIFOREADTHRESHOLDINTEN_MSB                       10
#define I2CINTEN_I2CFIFOREADTHRESHOLDINTEN_LSB                       10
#define I2CINTEN_I2CFIFOREADTHRESHOLDINTEN_MASK                      0x00000400
#define I2CINTEN_I2CFIFOREADTHRESHOLDINTEN_GET(x)                    (((x) & I2CINTEN_I2CFIFOREADTHRESHOLDINTEN_MASK) >> I2CINTEN_I2CFIFOREADTHRESHOLDINTEN_LSB)
#define I2CINTEN_I2CFIFOREADTHRESHOLDINTEN_SET(x)                    (((0 | (x)) << I2CINTEN_I2CFIFOREADTHRESHOLDINTEN_LSB) & I2CINTEN_I2CFIFOREADTHRESHOLDINTEN_MASK)
#define I2CINTEN_I2CFIFOREADTHRESHOLDINTEN_RESET                     0
#define I2CINTEN_I2CFIFOWRITEFULLINTEN_MSB                           9
#define I2CINTEN_I2CFIFOWRITEFULLINTEN_LSB                           9
#define I2CINTEN_I2CFIFOWRITEFULLINTEN_MASK                          0x00000200
#define I2CINTEN_I2CFIFOWRITEFULLINTEN_GET(x)                        (((x) & I2CINTEN_I2CFIFOWRITEFULLINTEN_MASK) >> I2CINTEN_I2CFIFOWRITEFULLINTEN_LSB)
#define I2CINTEN_I2CFIFOWRITEFULLINTEN_SET(x)                        (((0 | (x)) << I2CINTEN_I2CFIFOWRITEFULLINTEN_LSB) & I2CINTEN_I2CFIFOWRITEFULLINTEN_MASK)
#define I2CINTEN_I2CFIFOWRITEFULLINTEN_RESET                         0
#define I2CINTEN_I2CFIFOREADEMPTYINTEN_MSB                           8
#define I2CINTEN_I2CFIFOREADEMPTYINTEN_LSB                           8
#define I2CINTEN_I2CFIFOREADEMPTYINTEN_MASK                          0x00000100
#define I2CINTEN_I2CFIFOREADEMPTYINTEN_GET(x)                        (((x) & I2CINTEN_I2CFIFOREADEMPTYINTEN_MASK) >> I2CINTEN_I2CFIFOREADEMPTYINTEN_LSB)
#define I2CINTEN_I2CFIFOREADEMPTYINTEN_SET(x)                        (((0 | (x)) << I2CINTEN_I2CFIFOREADEMPTYINTEN_LSB) & I2CINTEN_I2CFIFOREADEMPTYINTEN_MASK)
#define I2CINTEN_I2CFIFOREADEMPTYINTEN_RESET                         0
#define I2CINTEN_I2CREGWRITEFINISHINTEN_MSB                          7
#define I2CINTEN_I2CREGWRITEFINISHINTEN_LSB                          7
#define I2CINTEN_I2CREGWRITEFINISHINTEN_MASK                         0x00000080
#define I2CINTEN_I2CREGWRITEFINISHINTEN_GET(x)                       (((x) & I2CINTEN_I2CREGWRITEFINISHINTEN_MASK) >> I2CINTEN_I2CREGWRITEFINISHINTEN_LSB)
#define I2CINTEN_I2CREGWRITEFINISHINTEN_SET(x)                       (((0 | (x)) << I2CINTEN_I2CREGWRITEFINISHINTEN_LSB) & I2CINTEN_I2CREGWRITEFINISHINTEN_MASK)
#define I2CINTEN_I2CREGWRITEFINISHINTEN_RESET                        0
#define I2CINTEN_I2CREGWRITESTARTINTEN_MSB                           6
#define I2CINTEN_I2CREGWRITESTARTINTEN_LSB                           6
#define I2CINTEN_I2CREGWRITESTARTINTEN_MASK                          0x00000040
#define I2CINTEN_I2CREGWRITESTARTINTEN_GET(x)                        (((x) & I2CINTEN_I2CREGWRITESTARTINTEN_MASK) >> I2CINTEN_I2CREGWRITESTARTINTEN_LSB)
#define I2CINTEN_I2CREGWRITESTARTINTEN_SET(x)                        (((0 | (x)) << I2CINTEN_I2CREGWRITESTARTINTEN_LSB) & I2CINTEN_I2CREGWRITESTARTINTEN_MASK)
#define I2CINTEN_I2CREGWRITESTARTINTEN_RESET                         0
#define I2CINTEN_I2CREGREADFINISHINTEN_MSB                           5
#define I2CINTEN_I2CREGREADFINISHINTEN_LSB                           5
#define I2CINTEN_I2CREGREADFINISHINTEN_MASK                          0x00000020
#define I2CINTEN_I2CREGREADFINISHINTEN_GET(x)                        (((x) & I2CINTEN_I2CREGREADFINISHINTEN_MASK) >> I2CINTEN_I2CREGREADFINISHINTEN_LSB)
#define I2CINTEN_I2CREGREADFINISHINTEN_SET(x)                        (((0 | (x)) << I2CINTEN_I2CREGREADFINISHINTEN_LSB) & I2CINTEN_I2CREGREADFINISHINTEN_MASK)
#define I2CINTEN_I2CREGREADFINISHINTEN_RESET                         0
#define I2CINTEN_I2CREGREADSTARTINTEN_MSB                            4
#define I2CINTEN_I2CREGREADSTARTINTEN_LSB                            4
#define I2CINTEN_I2CREGREADSTARTINTEN_MASK                           0x00000010
#define I2CINTEN_I2CREGREADSTARTINTEN_GET(x)                         (((x) & I2CINTEN_I2CREGREADSTARTINTEN_MASK) >> I2CINTEN_I2CREGREADSTARTINTEN_LSB)
#define I2CINTEN_I2CREGREADSTARTINTEN_SET(x)                         (((0 | (x)) << I2CINTEN_I2CREGREADSTARTINTEN_LSB) & I2CINTEN_I2CREGREADSTARTINTEN_MASK)
#define I2CINTEN_I2CREGREADSTARTINTEN_RESET                          0
#define I2CINTEN_I2CFIFOWRITEFINISHINTEN_MSB                         3
#define I2CINTEN_I2CFIFOWRITEFINISHINTEN_LSB                         3
#define I2CINTEN_I2CFIFOWRITEFINISHINTEN_MASK                        0x00000008
#define I2CINTEN_I2CFIFOWRITEFINISHINTEN_GET(x)                      (((x) & I2CINTEN_I2CFIFOWRITEFINISHINTEN_MASK) >> I2CINTEN_I2CFIFOWRITEFINISHINTEN_LSB)
#define I2CINTEN_I2CFIFOWRITEFINISHINTEN_SET(x)                      (((0 | (x)) << I2CINTEN_I2CFIFOWRITEFINISHINTEN_LSB) & I2CINTEN_I2CFIFOWRITEFINISHINTEN_MASK)
#define I2CINTEN_I2CFIFOWRITEFINISHINTEN_RESET                       0
#define I2CINTEN_I2CFIFOWRITESTARTINTEN_MSB                          2
#define I2CINTEN_I2CFIFOWRITESTARTINTEN_LSB                          2
#define I2CINTEN_I2CFIFOWRITESTARTINTEN_MASK                         0x00000004
#define I2CINTEN_I2CFIFOWRITESTARTINTEN_GET(x)                       (((x) & I2CINTEN_I2CFIFOWRITESTARTINTEN_MASK) >> I2CINTEN_I2CFIFOWRITESTARTINTEN_LSB)
#define I2CINTEN_I2CFIFOWRITESTARTINTEN_SET(x)                       (((0 | (x)) << I2CINTEN_I2CFIFOWRITESTARTINTEN_LSB) & I2CINTEN_I2CFIFOWRITESTARTINTEN_MASK)
#define I2CINTEN_I2CFIFOWRITESTARTINTEN_RESET                        0
#define I2CINTEN_I2CFIFOREADFINISHINTEN_MSB                          1
#define I2CINTEN_I2CFIFOREADFINISHINTEN_LSB                          1
#define I2CINTEN_I2CFIFOREADFINISHINTEN_MASK                         0x00000002
#define I2CINTEN_I2CFIFOREADFINISHINTEN_GET(x)                       (((x) & I2CINTEN_I2CFIFOREADFINISHINTEN_MASK) >> I2CINTEN_I2CFIFOREADFINISHINTEN_LSB)
#define I2CINTEN_I2CFIFOREADFINISHINTEN_SET(x)                       (((0 | (x)) << I2CINTEN_I2CFIFOREADFINISHINTEN_LSB) & I2CINTEN_I2CFIFOREADFINISHINTEN_MASK)
#define I2CINTEN_I2CFIFOREADFINISHINTEN_RESET                        0
#define I2CINTEN_I2CFIFOREADSTARTINTEN_MSB                           0
#define I2CINTEN_I2CFIFOREADSTARTINTEN_LSB                           0
#define I2CINTEN_I2CFIFOREADSTARTINTEN_MASK                          0x00000001
#define I2CINTEN_I2CFIFOREADSTARTINTEN_GET(x)                        (((x) & I2CINTEN_I2CFIFOREADSTARTINTEN_MASK) >> I2CINTEN_I2CFIFOREADSTARTINTEN_LSB)
#define I2CINTEN_I2CFIFOREADSTARTINTEN_SET(x)                        (((0 | (x)) << I2CINTEN_I2CFIFOREADSTARTINTEN_LSB) & I2CINTEN_I2CFIFOREADSTARTINTEN_MASK)
#define I2CINTEN_I2CFIFOREADSTARTINTEN_RESET                         0
#define I2CINTEN_ADDRESS                                             0x0048
#define I2CINTEN_HW_MASK                                             0x00001fff
#define I2CINTEN_SW_MASK                                             0x00001fff
#define I2CINTEN_HW_WRITE_MASK                                       0x00000000
#define I2CINTEN_SW_WRITE_MASK                                       0x00001fff
#define I2CINTEN_RSTMASK                                             0xffffffff
#define I2CINTEN_RESET                                               0x00000000

// 0x004c (I2CINTCSR)
#define I2CINTCSR_I2CINTEN_MSB                                       1
#define I2CINTCSR_I2CINTEN_LSB                                       1
#define I2CINTCSR_I2CINTEN_MASK                                      0x00000002
#define I2CINTCSR_I2CINTEN_GET(x)                                    (((x) & I2CINTCSR_I2CINTEN_MASK) >> I2CINTCSR_I2CINTEN_LSB)
#define I2CINTCSR_I2CINTEN_SET(x)                                    (((0 | (x)) << I2CINTCSR_I2CINTEN_LSB) & I2CINTCSR_I2CINTEN_MASK)
#define I2CINTCSR_I2CINTEN_RESET                                     0
#define I2CINTCSR_I2CINT_MSB                                         0
#define I2CINTCSR_I2CINT_LSB                                         0
#define I2CINTCSR_I2CINT_MASK                                        0x00000001
#define I2CINTCSR_I2CINT_GET(x)                                      (((x) & I2CINTCSR_I2CINT_MASK) >> I2CINTCSR_I2CINT_LSB)
#define I2CINTCSR_I2CINT_SET(x)                                      (((0 | (x)) << I2CINTCSR_I2CINT_LSB) & I2CINTCSR_I2CINT_MASK)
#define I2CINTCSR_I2CINT_RESET                                       0
#define I2CINTCSR_ADDRESS                                            0x004c
#define I2CINTCSR_HW_MASK                                            0x00000003
#define I2CINTCSR_SW_MASK                                            0x00000003
#define I2CINTCSR_HW_WRITE_MASK                                      0x00000001
#define I2CINTCSR_SW_WRITE_MASK                                      0x00000002
#define I2CINTCSR_RSTMASK                                            0xfffffffe
#define I2CINTCSR_RESET                                              0x00000000


#endif /* _ATHRI2CSLAVEAPBCSR_H_ */
