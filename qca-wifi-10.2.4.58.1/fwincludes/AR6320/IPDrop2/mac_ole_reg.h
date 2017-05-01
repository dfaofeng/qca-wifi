//                                                                             
// File:       ./mac_ole_reg.h                                                 
// Creator:    kasi                                                            
// Time:       Monday Mar 26, 2012 [2:31:56 pm]                                
//                                                                             
// Path:       /trees/kasi/kasi-wifi/ip/athr/wifi/dev/rtl/mac/rtl/mac_ole/blueprint
// Arguments:  /cad/denali/blueprint/3.7.3//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -ch -Wdesc mac_ole_reg.rdl    
//                                                                             
// Sources:    /trees/kasi/kasi-wifi/ip/athr/wifi/dev/rtl/mac/rtl/mac_ole/blueprint/mac_ole_reg.rdl
//             /trees/kasi/kasi-wifi/ip/athr/wifi/dev/shared/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.3 (Fri Aug 29 12:39:16 PDT 2008)                           
// Machine:    bageshri                                                        
// OS:         Linux 2.6.9-78.ELsmp                                            
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _MAC_OLE_REG_H_
#define _MAC_OLE_REG_H_
// 32'h7000 (OLE_L2_WLAN_LLC_0)
#define OLE_L2_WLAN_LLC_0_ENABLE_MSB                                 24
#define OLE_L2_WLAN_LLC_0_ENABLE_LSB                                 24
#define OLE_L2_WLAN_LLC_0_ENABLE_MASK                                0x01000000
#define OLE_L2_WLAN_LLC_0_ENABLE_GET(x)                              (((x) & OLE_L2_WLAN_LLC_0_ENABLE_MASK) >> OLE_L2_WLAN_LLC_0_ENABLE_LSB)
#define OLE_L2_WLAN_LLC_0_ENABLE_SET(x)                              (((x) << OLE_L2_WLAN_LLC_0_ENABLE_LSB) & OLE_L2_WLAN_LLC_0_ENABLE_MASK)
#define OLE_L2_WLAN_LLC_0_ENABLE_RESET                               0x1 // 1
#define OLE_L2_WLAN_LLC_0_BYTE6_MSB                                  23
#define OLE_L2_WLAN_LLC_0_BYTE6_LSB                                  16
#define OLE_L2_WLAN_LLC_0_BYTE6_MASK                                 0x00ff0000
#define OLE_L2_WLAN_LLC_0_BYTE6_GET(x)                               (((x) & OLE_L2_WLAN_LLC_0_BYTE6_MASK) >> OLE_L2_WLAN_LLC_0_BYTE6_LSB)
#define OLE_L2_WLAN_LLC_0_BYTE6_SET(x)                               (((x) << OLE_L2_WLAN_LLC_0_BYTE6_LSB) & OLE_L2_WLAN_LLC_0_BYTE6_MASK)
#define OLE_L2_WLAN_LLC_0_BYTE6_RESET                                0x0 // 0
#define OLE_L2_WLAN_LLC_0_TYPE_MSB                                   15
#define OLE_L2_WLAN_LLC_0_TYPE_LSB                                   0
#define OLE_L2_WLAN_LLC_0_TYPE_MASK                                  0x0000ffff
#define OLE_L2_WLAN_LLC_0_TYPE_GET(x)                                (((x) & OLE_L2_WLAN_LLC_0_TYPE_MASK) >> OLE_L2_WLAN_LLC_0_TYPE_LSB)
#define OLE_L2_WLAN_LLC_0_TYPE_SET(x)                                (((x) << OLE_L2_WLAN_LLC_0_TYPE_LSB) & OLE_L2_WLAN_LLC_0_TYPE_MASK)
#define OLE_L2_WLAN_LLC_0_TYPE_RESET                                 0x800 // 2048
#define OLE_L2_WLAN_LLC_0_ADDRESS                                    0x7000
#define OLE_L2_WLAN_LLC_0_OFFSET                                     0x7000
// SW modifiable bits
#define OLE_L2_WLAN_LLC_0_SW_MASK                                    0x01ffffff
// bits defined at reset
#define OLE_L2_WLAN_LLC_0_RSTMASK                                    0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_L2_WLAN_LLC_0_RESET                                      0x01000800

// 32'h7004 (OLE_L2_WLAN_LLC_1)
#define OLE_L2_WLAN_LLC_1_ENABLE_MSB                                 24
#define OLE_L2_WLAN_LLC_1_ENABLE_LSB                                 24
#define OLE_L2_WLAN_LLC_1_ENABLE_MASK                                0x01000000
#define OLE_L2_WLAN_LLC_1_ENABLE_GET(x)                              (((x) & OLE_L2_WLAN_LLC_1_ENABLE_MASK) >> OLE_L2_WLAN_LLC_1_ENABLE_LSB)
#define OLE_L2_WLAN_LLC_1_ENABLE_SET(x)                              (((x) << OLE_L2_WLAN_LLC_1_ENABLE_LSB) & OLE_L2_WLAN_LLC_1_ENABLE_MASK)
#define OLE_L2_WLAN_LLC_1_ENABLE_RESET                               0x1 // 1
#define OLE_L2_WLAN_LLC_1_BYTE6_MSB                                  23
#define OLE_L2_WLAN_LLC_1_BYTE6_LSB                                  16
#define OLE_L2_WLAN_LLC_1_BYTE6_MASK                                 0x00ff0000
#define OLE_L2_WLAN_LLC_1_BYTE6_GET(x)                               (((x) & OLE_L2_WLAN_LLC_1_BYTE6_MASK) >> OLE_L2_WLAN_LLC_1_BYTE6_LSB)
#define OLE_L2_WLAN_LLC_1_BYTE6_SET(x)                               (((x) << OLE_L2_WLAN_LLC_1_BYTE6_LSB) & OLE_L2_WLAN_LLC_1_BYTE6_MASK)
#define OLE_L2_WLAN_LLC_1_BYTE6_RESET                                0x0 // 0
#define OLE_L2_WLAN_LLC_1_TYPE_MSB                                   15
#define OLE_L2_WLAN_LLC_1_TYPE_LSB                                   0
#define OLE_L2_WLAN_LLC_1_TYPE_MASK                                  0x0000ffff
#define OLE_L2_WLAN_LLC_1_TYPE_GET(x)                                (((x) & OLE_L2_WLAN_LLC_1_TYPE_MASK) >> OLE_L2_WLAN_LLC_1_TYPE_LSB)
#define OLE_L2_WLAN_LLC_1_TYPE_SET(x)                                (((x) << OLE_L2_WLAN_LLC_1_TYPE_LSB) & OLE_L2_WLAN_LLC_1_TYPE_MASK)
#define OLE_L2_WLAN_LLC_1_TYPE_RESET                                 0x806 // 2054
#define OLE_L2_WLAN_LLC_1_ADDRESS                                    0x7004
#define OLE_L2_WLAN_LLC_1_OFFSET                                     0x7004
// SW modifiable bits
#define OLE_L2_WLAN_LLC_1_SW_MASK                                    0x01ffffff
// bits defined at reset
#define OLE_L2_WLAN_LLC_1_RSTMASK                                    0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_L2_WLAN_LLC_1_RESET                                      0x01000806

// 32'h7008 (OLE_L2_WLAN_LLC_2)
#define OLE_L2_WLAN_LLC_2_ENABLE_MSB                                 24
#define OLE_L2_WLAN_LLC_2_ENABLE_LSB                                 24
#define OLE_L2_WLAN_LLC_2_ENABLE_MASK                                0x01000000
#define OLE_L2_WLAN_LLC_2_ENABLE_GET(x)                              (((x) & OLE_L2_WLAN_LLC_2_ENABLE_MASK) >> OLE_L2_WLAN_LLC_2_ENABLE_LSB)
#define OLE_L2_WLAN_LLC_2_ENABLE_SET(x)                              (((x) << OLE_L2_WLAN_LLC_2_ENABLE_LSB) & OLE_L2_WLAN_LLC_2_ENABLE_MASK)
#define OLE_L2_WLAN_LLC_2_ENABLE_RESET                               0x1 // 1
#define OLE_L2_WLAN_LLC_2_BYTE6_MSB                                  23
#define OLE_L2_WLAN_LLC_2_BYTE6_LSB                                  16
#define OLE_L2_WLAN_LLC_2_BYTE6_MASK                                 0x00ff0000
#define OLE_L2_WLAN_LLC_2_BYTE6_GET(x)                               (((x) & OLE_L2_WLAN_LLC_2_BYTE6_MASK) >> OLE_L2_WLAN_LLC_2_BYTE6_LSB)
#define OLE_L2_WLAN_LLC_2_BYTE6_SET(x)                               (((x) << OLE_L2_WLAN_LLC_2_BYTE6_LSB) & OLE_L2_WLAN_LLC_2_BYTE6_MASK)
#define OLE_L2_WLAN_LLC_2_BYTE6_RESET                                0x0 // 0
#define OLE_L2_WLAN_LLC_2_TYPE_MSB                                   15
#define OLE_L2_WLAN_LLC_2_TYPE_LSB                                   0
#define OLE_L2_WLAN_LLC_2_TYPE_MASK                                  0x0000ffff
#define OLE_L2_WLAN_LLC_2_TYPE_GET(x)                                (((x) & OLE_L2_WLAN_LLC_2_TYPE_MASK) >> OLE_L2_WLAN_LLC_2_TYPE_LSB)
#define OLE_L2_WLAN_LLC_2_TYPE_SET(x)                                (((x) << OLE_L2_WLAN_LLC_2_TYPE_LSB) & OLE_L2_WLAN_LLC_2_TYPE_MASK)
#define OLE_L2_WLAN_LLC_2_TYPE_RESET                                 0x809b // 32923
#define OLE_L2_WLAN_LLC_2_ADDRESS                                    0x7008
#define OLE_L2_WLAN_LLC_2_OFFSET                                     0x7008
// SW modifiable bits
#define OLE_L2_WLAN_LLC_2_SW_MASK                                    0x01ffffff
// bits defined at reset
#define OLE_L2_WLAN_LLC_2_RSTMASK                                    0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_L2_WLAN_LLC_2_RESET                                      0x0100809b

// 32'h700c (OLE_L2_WLAN_LLC_3)
#define OLE_L2_WLAN_LLC_3_ENABLE_MSB                                 24
#define OLE_L2_WLAN_LLC_3_ENABLE_LSB                                 24
#define OLE_L2_WLAN_LLC_3_ENABLE_MASK                                0x01000000
#define OLE_L2_WLAN_LLC_3_ENABLE_GET(x)                              (((x) & OLE_L2_WLAN_LLC_3_ENABLE_MASK) >> OLE_L2_WLAN_LLC_3_ENABLE_LSB)
#define OLE_L2_WLAN_LLC_3_ENABLE_SET(x)                              (((x) << OLE_L2_WLAN_LLC_3_ENABLE_LSB) & OLE_L2_WLAN_LLC_3_ENABLE_MASK)
#define OLE_L2_WLAN_LLC_3_ENABLE_RESET                               0x1 // 1
#define OLE_L2_WLAN_LLC_3_BYTE6_MSB                                  23
#define OLE_L2_WLAN_LLC_3_BYTE6_LSB                                  16
#define OLE_L2_WLAN_LLC_3_BYTE6_MASK                                 0x00ff0000
#define OLE_L2_WLAN_LLC_3_BYTE6_GET(x)                               (((x) & OLE_L2_WLAN_LLC_3_BYTE6_MASK) >> OLE_L2_WLAN_LLC_3_BYTE6_LSB)
#define OLE_L2_WLAN_LLC_3_BYTE6_SET(x)                               (((x) << OLE_L2_WLAN_LLC_3_BYTE6_LSB) & OLE_L2_WLAN_LLC_3_BYTE6_MASK)
#define OLE_L2_WLAN_LLC_3_BYTE6_RESET                                0xf8 // 248
#define OLE_L2_WLAN_LLC_3_TYPE_MSB                                   15
#define OLE_L2_WLAN_LLC_3_TYPE_LSB                                   0
#define OLE_L2_WLAN_LLC_3_TYPE_MASK                                  0x0000ffff
#define OLE_L2_WLAN_LLC_3_TYPE_GET(x)                                (((x) & OLE_L2_WLAN_LLC_3_TYPE_MASK) >> OLE_L2_WLAN_LLC_3_TYPE_LSB)
#define OLE_L2_WLAN_LLC_3_TYPE_SET(x)                                (((x) << OLE_L2_WLAN_LLC_3_TYPE_LSB) & OLE_L2_WLAN_LLC_3_TYPE_MASK)
#define OLE_L2_WLAN_LLC_3_TYPE_RESET                                 0x80f3 // 33011
#define OLE_L2_WLAN_LLC_3_ADDRESS                                    0x700c
#define OLE_L2_WLAN_LLC_3_OFFSET                                     0x700c
// SW modifiable bits
#define OLE_L2_WLAN_LLC_3_SW_MASK                                    0x01ffffff
// bits defined at reset
#define OLE_L2_WLAN_LLC_3_RSTMASK                                    0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_L2_WLAN_LLC_3_RESET                                      0x01f880f3

// 32'h7010 (OLE_L2_WLAN_LLC_4)
#define OLE_L2_WLAN_LLC_4_ENABLE_MSB                                 24
#define OLE_L2_WLAN_LLC_4_ENABLE_LSB                                 24
#define OLE_L2_WLAN_LLC_4_ENABLE_MASK                                0x01000000
#define OLE_L2_WLAN_LLC_4_ENABLE_GET(x)                              (((x) & OLE_L2_WLAN_LLC_4_ENABLE_MASK) >> OLE_L2_WLAN_LLC_4_ENABLE_LSB)
#define OLE_L2_WLAN_LLC_4_ENABLE_SET(x)                              (((x) << OLE_L2_WLAN_LLC_4_ENABLE_LSB) & OLE_L2_WLAN_LLC_4_ENABLE_MASK)
#define OLE_L2_WLAN_LLC_4_ENABLE_RESET                               0x1 // 1
#define OLE_L2_WLAN_LLC_4_BYTE6_MSB                                  23
#define OLE_L2_WLAN_LLC_4_BYTE6_LSB                                  16
#define OLE_L2_WLAN_LLC_4_BYTE6_MASK                                 0x00ff0000
#define OLE_L2_WLAN_LLC_4_BYTE6_GET(x)                               (((x) & OLE_L2_WLAN_LLC_4_BYTE6_MASK) >> OLE_L2_WLAN_LLC_4_BYTE6_LSB)
#define OLE_L2_WLAN_LLC_4_BYTE6_SET(x)                               (((x) << OLE_L2_WLAN_LLC_4_BYTE6_LSB) & OLE_L2_WLAN_LLC_4_BYTE6_MASK)
#define OLE_L2_WLAN_LLC_4_BYTE6_RESET                                0xf8 // 248
#define OLE_L2_WLAN_LLC_4_TYPE_MSB                                   15
#define OLE_L2_WLAN_LLC_4_TYPE_LSB                                   0
#define OLE_L2_WLAN_LLC_4_TYPE_MASK                                  0x0000ffff
#define OLE_L2_WLAN_LLC_4_TYPE_GET(x)                                (((x) & OLE_L2_WLAN_LLC_4_TYPE_MASK) >> OLE_L2_WLAN_LLC_4_TYPE_LSB)
#define OLE_L2_WLAN_LLC_4_TYPE_SET(x)                                (((x) << OLE_L2_WLAN_LLC_4_TYPE_LSB) & OLE_L2_WLAN_LLC_4_TYPE_MASK)
#define OLE_L2_WLAN_LLC_4_TYPE_RESET                                 0x8137 // 33079
#define OLE_L2_WLAN_LLC_4_ADDRESS                                    0x7010
#define OLE_L2_WLAN_LLC_4_OFFSET                                     0x7010
// SW modifiable bits
#define OLE_L2_WLAN_LLC_4_SW_MASK                                    0x01ffffff
// bits defined at reset
#define OLE_L2_WLAN_LLC_4_RSTMASK                                    0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_L2_WLAN_LLC_4_RESET                                      0x01f88137

// 32'h7014 (OLE_L2_WLAN_LLC_5)
#define OLE_L2_WLAN_LLC_5_ENABLE_MSB                                 24
#define OLE_L2_WLAN_LLC_5_ENABLE_LSB                                 24
#define OLE_L2_WLAN_LLC_5_ENABLE_MASK                                0x01000000
#define OLE_L2_WLAN_LLC_5_ENABLE_GET(x)                              (((x) & OLE_L2_WLAN_LLC_5_ENABLE_MASK) >> OLE_L2_WLAN_LLC_5_ENABLE_LSB)
#define OLE_L2_WLAN_LLC_5_ENABLE_SET(x)                              (((x) << OLE_L2_WLAN_LLC_5_ENABLE_LSB) & OLE_L2_WLAN_LLC_5_ENABLE_MASK)
#define OLE_L2_WLAN_LLC_5_ENABLE_RESET                               0x1 // 1
#define OLE_L2_WLAN_LLC_5_BYTE6_MSB                                  23
#define OLE_L2_WLAN_LLC_5_BYTE6_LSB                                  16
#define OLE_L2_WLAN_LLC_5_BYTE6_MASK                                 0x00ff0000
#define OLE_L2_WLAN_LLC_5_BYTE6_GET(x)                               (((x) & OLE_L2_WLAN_LLC_5_BYTE6_MASK) >> OLE_L2_WLAN_LLC_5_BYTE6_LSB)
#define OLE_L2_WLAN_LLC_5_BYTE6_SET(x)                               (((x) << OLE_L2_WLAN_LLC_5_BYTE6_LSB) & OLE_L2_WLAN_LLC_5_BYTE6_MASK)
#define OLE_L2_WLAN_LLC_5_BYTE6_RESET                                0x0 // 0
#define OLE_L2_WLAN_LLC_5_TYPE_MSB                                   15
#define OLE_L2_WLAN_LLC_5_TYPE_LSB                                   0
#define OLE_L2_WLAN_LLC_5_TYPE_MASK                                  0x0000ffff
#define OLE_L2_WLAN_LLC_5_TYPE_GET(x)                                (((x) & OLE_L2_WLAN_LLC_5_TYPE_MASK) >> OLE_L2_WLAN_LLC_5_TYPE_LSB)
#define OLE_L2_WLAN_LLC_5_TYPE_SET(x)                                (((x) << OLE_L2_WLAN_LLC_5_TYPE_LSB) & OLE_L2_WLAN_LLC_5_TYPE_MASK)
#define OLE_L2_WLAN_LLC_5_TYPE_RESET                                 0x86dd // 34525
#define OLE_L2_WLAN_LLC_5_ADDRESS                                    0x7014
#define OLE_L2_WLAN_LLC_5_OFFSET                                     0x7014
// SW modifiable bits
#define OLE_L2_WLAN_LLC_5_SW_MASK                                    0x01ffffff
// bits defined at reset
#define OLE_L2_WLAN_LLC_5_RSTMASK                                    0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_L2_WLAN_LLC_5_RESET                                      0x010086dd

// 32'h7018 (OLE_L2_WLAN_LLC_6)
#define OLE_L2_WLAN_LLC_6_ENABLE_MSB                                 24
#define OLE_L2_WLAN_LLC_6_ENABLE_LSB                                 24
#define OLE_L2_WLAN_LLC_6_ENABLE_MASK                                0x01000000
#define OLE_L2_WLAN_LLC_6_ENABLE_GET(x)                              (((x) & OLE_L2_WLAN_LLC_6_ENABLE_MASK) >> OLE_L2_WLAN_LLC_6_ENABLE_LSB)
#define OLE_L2_WLAN_LLC_6_ENABLE_SET(x)                              (((x) << OLE_L2_WLAN_LLC_6_ENABLE_LSB) & OLE_L2_WLAN_LLC_6_ENABLE_MASK)
#define OLE_L2_WLAN_LLC_6_ENABLE_RESET                               0x1 // 1
#define OLE_L2_WLAN_LLC_6_BYTE6_MSB                                  23
#define OLE_L2_WLAN_LLC_6_BYTE6_LSB                                  16
#define OLE_L2_WLAN_LLC_6_BYTE6_MASK                                 0x00ff0000
#define OLE_L2_WLAN_LLC_6_BYTE6_GET(x)                               (((x) & OLE_L2_WLAN_LLC_6_BYTE6_MASK) >> OLE_L2_WLAN_LLC_6_BYTE6_LSB)
#define OLE_L2_WLAN_LLC_6_BYTE6_SET(x)                               (((x) << OLE_L2_WLAN_LLC_6_BYTE6_LSB) & OLE_L2_WLAN_LLC_6_BYTE6_MASK)
#define OLE_L2_WLAN_LLC_6_BYTE6_RESET                                0x0 // 0
#define OLE_L2_WLAN_LLC_6_TYPE_MSB                                   15
#define OLE_L2_WLAN_LLC_6_TYPE_LSB                                   0
#define OLE_L2_WLAN_LLC_6_TYPE_MASK                                  0x0000ffff
#define OLE_L2_WLAN_LLC_6_TYPE_GET(x)                                (((x) & OLE_L2_WLAN_LLC_6_TYPE_MASK) >> OLE_L2_WLAN_LLC_6_TYPE_LSB)
#define OLE_L2_WLAN_LLC_6_TYPE_SET(x)                                (((x) << OLE_L2_WLAN_LLC_6_TYPE_LSB) & OLE_L2_WLAN_LLC_6_TYPE_MASK)
#define OLE_L2_WLAN_LLC_6_TYPE_RESET                                 0x888e // 34958
#define OLE_L2_WLAN_LLC_6_ADDRESS                                    0x7018
#define OLE_L2_WLAN_LLC_6_OFFSET                                     0x7018
// SW modifiable bits
#define OLE_L2_WLAN_LLC_6_SW_MASK                                    0x01ffffff
// bits defined at reset
#define OLE_L2_WLAN_LLC_6_RSTMASK                                    0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_L2_WLAN_LLC_6_RESET                                      0x0100888e

// 32'h7020 (OLE_RX_CONFIG)
#define OLE_RX_CONFIG_RX_HDR_BYTELEN_MSB                             7
#define OLE_RX_CONFIG_RX_HDR_BYTELEN_LSB                             0
#define OLE_RX_CONFIG_RX_HDR_BYTELEN_MASK                            0x000000ff
#define OLE_RX_CONFIG_RX_HDR_BYTELEN_GET(x)                          (((x) & OLE_RX_CONFIG_RX_HDR_BYTELEN_MASK) >> OLE_RX_CONFIG_RX_HDR_BYTELEN_LSB)
#define OLE_RX_CONFIG_RX_HDR_BYTELEN_SET(x)                          (((x) << OLE_RX_CONFIG_RX_HDR_BYTELEN_LSB) & OLE_RX_CONFIG_RX_HDR_BYTELEN_MASK)
#define OLE_RX_CONFIG_RX_HDR_BYTELEN_RESET                           0x30 // 48
#define OLE_RX_CONFIG_ADDRESS                                        0x7020
#define OLE_RX_CONFIG_OFFSET                                         0x7020
// SW modifiable bits
#define OLE_RX_CONFIG_SW_MASK                                        0x000000ff
// bits defined at reset
#define OLE_RX_CONFIG_RSTMASK                                        0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_RX_CONFIG_RESET                                          0x00000030

// 32'h7024 (OLE_RX_CONFIG_RING0)
#define OLE_RX_CONFIG_RING0_RESERVED_2_MSB                           31
#define OLE_RX_CONFIG_RING0_RESERVED_2_LSB                           28
#define OLE_RX_CONFIG_RING0_RESERVED_2_MASK                          0xf0000000
#define OLE_RX_CONFIG_RING0_RESERVED_2_GET(x)                        (((x) & OLE_RX_CONFIG_RING0_RESERVED_2_MASK) >> OLE_RX_CONFIG_RING0_RESERVED_2_LSB)
#define OLE_RX_CONFIG_RING0_RESERVED_2_SET(x)                        (((x) << OLE_RX_CONFIG_RING0_RESERVED_2_LSB) & OLE_RX_CONFIG_RING0_RESERVED_2_MASK)
#define OLE_RX_CONFIG_RING0_RESERVED_2_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING0_ETHERNET_3_MSB                           27
#define OLE_RX_CONFIG_RING0_ETHERNET_3_LSB                           27
#define OLE_RX_CONFIG_RING0_ETHERNET_3_MASK                          0x08000000
#define OLE_RX_CONFIG_RING0_ETHERNET_3_GET(x)                        (((x) & OLE_RX_CONFIG_RING0_ETHERNET_3_MASK) >> OLE_RX_CONFIG_RING0_ETHERNET_3_LSB)
#define OLE_RX_CONFIG_RING0_ETHERNET_3_SET(x)                        (((x) << OLE_RX_CONFIG_RING0_ETHERNET_3_LSB) & OLE_RX_CONFIG_RING0_ETHERNET_3_MASK)
#define OLE_RX_CONFIG_RING0_ETHERNET_3_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING0_ETHERNET_2_MSB                           26
#define OLE_RX_CONFIG_RING0_ETHERNET_2_LSB                           26
#define OLE_RX_CONFIG_RING0_ETHERNET_2_MASK                          0x04000000
#define OLE_RX_CONFIG_RING0_ETHERNET_2_GET(x)                        (((x) & OLE_RX_CONFIG_RING0_ETHERNET_2_MASK) >> OLE_RX_CONFIG_RING0_ETHERNET_2_LSB)
#define OLE_RX_CONFIG_RING0_ETHERNET_2_SET(x)                        (((x) << OLE_RX_CONFIG_RING0_ETHERNET_2_LSB) & OLE_RX_CONFIG_RING0_ETHERNET_2_MASK)
#define OLE_RX_CONFIG_RING0_ETHERNET_2_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING0_ETHERNET_1_MSB                           25
#define OLE_RX_CONFIG_RING0_ETHERNET_1_LSB                           25
#define OLE_RX_CONFIG_RING0_ETHERNET_1_MASK                          0x02000000
#define OLE_RX_CONFIG_RING0_ETHERNET_1_GET(x)                        (((x) & OLE_RX_CONFIG_RING0_ETHERNET_1_MASK) >> OLE_RX_CONFIG_RING0_ETHERNET_1_LSB)
#define OLE_RX_CONFIG_RING0_ETHERNET_1_SET(x)                        (((x) << OLE_RX_CONFIG_RING0_ETHERNET_1_LSB) & OLE_RX_CONFIG_RING0_ETHERNET_1_MASK)
#define OLE_RX_CONFIG_RING0_ETHERNET_1_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING0_ETHERNET_0_MSB                           24
#define OLE_RX_CONFIG_RING0_ETHERNET_0_LSB                           24
#define OLE_RX_CONFIG_RING0_ETHERNET_0_MASK                          0x01000000
#define OLE_RX_CONFIG_RING0_ETHERNET_0_GET(x)                        (((x) & OLE_RX_CONFIG_RING0_ETHERNET_0_MASK) >> OLE_RX_CONFIG_RING0_ETHERNET_0_LSB)
#define OLE_RX_CONFIG_RING0_ETHERNET_0_SET(x)                        (((x) << OLE_RX_CONFIG_RING0_ETHERNET_0_LSB) & OLE_RX_CONFIG_RING0_ETHERNET_0_MASK)
#define OLE_RX_CONFIG_RING0_ETHERNET_0_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING0_RESERVED_1_MSB                           23
#define OLE_RX_CONFIG_RING0_RESERVED_1_LSB                           22
#define OLE_RX_CONFIG_RING0_RESERVED_1_MASK                          0x00c00000
#define OLE_RX_CONFIG_RING0_RESERVED_1_GET(x)                        (((x) & OLE_RX_CONFIG_RING0_RESERVED_1_MASK) >> OLE_RX_CONFIG_RING0_RESERVED_1_LSB)
#define OLE_RX_CONFIG_RING0_RESERVED_1_SET(x)                        (((x) << OLE_RX_CONFIG_RING0_RESERVED_1_LSB) & OLE_RX_CONFIG_RING0_RESERVED_1_MASK)
#define OLE_RX_CONFIG_RING0_RESERVED_1_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_MSB                        21
#define OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_LSB                        21
#define OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_MASK                       0x00200000
#define OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_GET(x)                     (((x) & OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_SET(x)                     (((x) << OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING0_PHY_DATA_TYPE_RESET                      0x1 // 1
#define OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_MSB                       20
#define OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_LSB                       20
#define OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_MASK                      0x00100000
#define OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_GET(x)                    (((x) & OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_SET(x)                    (((x) << OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING0_NULL_DATA_TYPE_RESET                     0x1 // 1
#define OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_MSB                      19
#define OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_LSB                      19
#define OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_MASK                     0x00080000
#define OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_GET(x)                   (((x) & OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_SET(x)                   (((x) << OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING0_MCAST_DATA_TYPE_RESET                    0x1 // 1
#define OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_MSB                      18
#define OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_LSB                      18
#define OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_MASK                     0x00040000
#define OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_GET(x)                   (((x) & OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_SET(x)                   (((x) << OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING0_UCAST_DATA_TYPE_RESET                    0x1 // 1
#define OLE_RX_CONFIG_RING0_MGMT_TYPE_MSB                            17
#define OLE_RX_CONFIG_RING0_MGMT_TYPE_LSB                            17
#define OLE_RX_CONFIG_RING0_MGMT_TYPE_MASK                           0x00020000
#define OLE_RX_CONFIG_RING0_MGMT_TYPE_GET(x)                         (((x) & OLE_RX_CONFIG_RING0_MGMT_TYPE_MASK) >> OLE_RX_CONFIG_RING0_MGMT_TYPE_LSB)
#define OLE_RX_CONFIG_RING0_MGMT_TYPE_SET(x)                         (((x) << OLE_RX_CONFIG_RING0_MGMT_TYPE_LSB) & OLE_RX_CONFIG_RING0_MGMT_TYPE_MASK)
#define OLE_RX_CONFIG_RING0_MGMT_TYPE_RESET                          0x1 // 1
#define OLE_RX_CONFIG_RING0_CTRL_TYPE_MSB                            16
#define OLE_RX_CONFIG_RING0_CTRL_TYPE_LSB                            16
#define OLE_RX_CONFIG_RING0_CTRL_TYPE_MASK                           0x00010000
#define OLE_RX_CONFIG_RING0_CTRL_TYPE_GET(x)                         (((x) & OLE_RX_CONFIG_RING0_CTRL_TYPE_MASK) >> OLE_RX_CONFIG_RING0_CTRL_TYPE_LSB)
#define OLE_RX_CONFIG_RING0_CTRL_TYPE_SET(x)                         (((x) << OLE_RX_CONFIG_RING0_CTRL_TYPE_LSB) & OLE_RX_CONFIG_RING0_CTRL_TYPE_MASK)
#define OLE_RX_CONFIG_RING0_CTRL_TYPE_RESET                          0x1 // 1
#define OLE_RX_CONFIG_RING0_RESERVED_0_MSB                           15
#define OLE_RX_CONFIG_RING0_RESERVED_0_LSB                           10
#define OLE_RX_CONFIG_RING0_RESERVED_0_MASK                          0x0000fc00
#define OLE_RX_CONFIG_RING0_RESERVED_0_GET(x)                        (((x) & OLE_RX_CONFIG_RING0_RESERVED_0_MASK) >> OLE_RX_CONFIG_RING0_RESERVED_0_LSB)
#define OLE_RX_CONFIG_RING0_RESERVED_0_SET(x)                        (((x) << OLE_RX_CONFIG_RING0_RESERVED_0_LSB) & OLE_RX_CONFIG_RING0_RESERVED_0_MASK)
#define OLE_RX_CONFIG_RING0_RESERVED_0_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING0_FRAG_INFO_MSB                            9
#define OLE_RX_CONFIG_RING0_FRAG_INFO_LSB                            9
#define OLE_RX_CONFIG_RING0_FRAG_INFO_MASK                           0x00000200
#define OLE_RX_CONFIG_RING0_FRAG_INFO_GET(x)                         (((x) & OLE_RX_CONFIG_RING0_FRAG_INFO_MASK) >> OLE_RX_CONFIG_RING0_FRAG_INFO_LSB)
#define OLE_RX_CONFIG_RING0_FRAG_INFO_SET(x)                         (((x) << OLE_RX_CONFIG_RING0_FRAG_INFO_LSB) & OLE_RX_CONFIG_RING0_FRAG_INFO_MASK)
#define OLE_RX_CONFIG_RING0_FRAG_INFO_RESET                          0x1 // 1
#define OLE_RX_CONFIG_RING0_ATTENTION_MSB                            8
#define OLE_RX_CONFIG_RING0_ATTENTION_LSB                            8
#define OLE_RX_CONFIG_RING0_ATTENTION_MASK                           0x00000100
#define OLE_RX_CONFIG_RING0_ATTENTION_GET(x)                         (((x) & OLE_RX_CONFIG_RING0_ATTENTION_MASK) >> OLE_RX_CONFIG_RING0_ATTENTION_LSB)
#define OLE_RX_CONFIG_RING0_ATTENTION_SET(x)                         (((x) << OLE_RX_CONFIG_RING0_ATTENTION_LSB) & OLE_RX_CONFIG_RING0_ATTENTION_MASK)
#define OLE_RX_CONFIG_RING0_ATTENTION_RESET                          0x1 // 1
#define OLE_RX_CONFIG_RING0_PPDU_END_MSB                             7
#define OLE_RX_CONFIG_RING0_PPDU_END_LSB                             7
#define OLE_RX_CONFIG_RING0_PPDU_END_MASK                            0x00000080
#define OLE_RX_CONFIG_RING0_PPDU_END_GET(x)                          (((x) & OLE_RX_CONFIG_RING0_PPDU_END_MASK) >> OLE_RX_CONFIG_RING0_PPDU_END_LSB)
#define OLE_RX_CONFIG_RING0_PPDU_END_SET(x)                          (((x) << OLE_RX_CONFIG_RING0_PPDU_END_LSB) & OLE_RX_CONFIG_RING0_PPDU_END_MASK)
#define OLE_RX_CONFIG_RING0_PPDU_END_RESET                           0x1 // 1
#define OLE_RX_CONFIG_RING0_MPDU_END_MSB                             6
#define OLE_RX_CONFIG_RING0_MPDU_END_LSB                             6
#define OLE_RX_CONFIG_RING0_MPDU_END_MASK                            0x00000040
#define OLE_RX_CONFIG_RING0_MPDU_END_GET(x)                          (((x) & OLE_RX_CONFIG_RING0_MPDU_END_MASK) >> OLE_RX_CONFIG_RING0_MPDU_END_LSB)
#define OLE_RX_CONFIG_RING0_MPDU_END_SET(x)                          (((x) << OLE_RX_CONFIG_RING0_MPDU_END_LSB) & OLE_RX_CONFIG_RING0_MPDU_END_MASK)
#define OLE_RX_CONFIG_RING0_MPDU_END_RESET                           0x1 // 1
#define OLE_RX_CONFIG_RING0_MSDU_END_MSB                             5
#define OLE_RX_CONFIG_RING0_MSDU_END_LSB                             5
#define OLE_RX_CONFIG_RING0_MSDU_END_MASK                            0x00000020
#define OLE_RX_CONFIG_RING0_MSDU_END_GET(x)                          (((x) & OLE_RX_CONFIG_RING0_MSDU_END_MASK) >> OLE_RX_CONFIG_RING0_MSDU_END_LSB)
#define OLE_RX_CONFIG_RING0_MSDU_END_SET(x)                          (((x) << OLE_RX_CONFIG_RING0_MSDU_END_LSB) & OLE_RX_CONFIG_RING0_MSDU_END_MASK)
#define OLE_RX_CONFIG_RING0_MSDU_END_RESET                           0x1 // 1
#define OLE_RX_CONFIG_RING0_PKT_MSB                                  4
#define OLE_RX_CONFIG_RING0_PKT_LSB                                  4
#define OLE_RX_CONFIG_RING0_PKT_MASK                                 0x00000010
#define OLE_RX_CONFIG_RING0_PKT_GET(x)                               (((x) & OLE_RX_CONFIG_RING0_PKT_MASK) >> OLE_RX_CONFIG_RING0_PKT_LSB)
#define OLE_RX_CONFIG_RING0_PKT_SET(x)                               (((x) << OLE_RX_CONFIG_RING0_PKT_LSB) & OLE_RX_CONFIG_RING0_PKT_MASK)
#define OLE_RX_CONFIG_RING0_PKT_RESET                                0x1 // 1
#define OLE_RX_CONFIG_RING0_MSDU_START_MSB                           3
#define OLE_RX_CONFIG_RING0_MSDU_START_LSB                           3
#define OLE_RX_CONFIG_RING0_MSDU_START_MASK                          0x00000008
#define OLE_RX_CONFIG_RING0_MSDU_START_GET(x)                        (((x) & OLE_RX_CONFIG_RING0_MSDU_START_MASK) >> OLE_RX_CONFIG_RING0_MSDU_START_LSB)
#define OLE_RX_CONFIG_RING0_MSDU_START_SET(x)                        (((x) << OLE_RX_CONFIG_RING0_MSDU_START_LSB) & OLE_RX_CONFIG_RING0_MSDU_START_MASK)
#define OLE_RX_CONFIG_RING0_MSDU_START_RESET                         0x1 // 1
#define OLE_RX_CONFIG_RING0_MPDU_START_MSB                           2
#define OLE_RX_CONFIG_RING0_MPDU_START_LSB                           2
#define OLE_RX_CONFIG_RING0_MPDU_START_MASK                          0x00000004
#define OLE_RX_CONFIG_RING0_MPDU_START_GET(x)                        (((x) & OLE_RX_CONFIG_RING0_MPDU_START_MASK) >> OLE_RX_CONFIG_RING0_MPDU_START_LSB)
#define OLE_RX_CONFIG_RING0_MPDU_START_SET(x)                        (((x) << OLE_RX_CONFIG_RING0_MPDU_START_LSB) & OLE_RX_CONFIG_RING0_MPDU_START_MASK)
#define OLE_RX_CONFIG_RING0_MPDU_START_RESET                         0x1 // 1
#define OLE_RX_CONFIG_RING0_HDR_MSB                                  1
#define OLE_RX_CONFIG_RING0_HDR_LSB                                  1
#define OLE_RX_CONFIG_RING0_HDR_MASK                                 0x00000002
#define OLE_RX_CONFIG_RING0_HDR_GET(x)                               (((x) & OLE_RX_CONFIG_RING0_HDR_MASK) >> OLE_RX_CONFIG_RING0_HDR_LSB)
#define OLE_RX_CONFIG_RING0_HDR_SET(x)                               (((x) << OLE_RX_CONFIG_RING0_HDR_LSB) & OLE_RX_CONFIG_RING0_HDR_MASK)
#define OLE_RX_CONFIG_RING0_HDR_RESET                                0x1 // 1
#define OLE_RX_CONFIG_RING0_PPDU_START_MSB                           0
#define OLE_RX_CONFIG_RING0_PPDU_START_LSB                           0
#define OLE_RX_CONFIG_RING0_PPDU_START_MASK                          0x00000001
#define OLE_RX_CONFIG_RING0_PPDU_START_GET(x)                        (((x) & OLE_RX_CONFIG_RING0_PPDU_START_MASK) >> OLE_RX_CONFIG_RING0_PPDU_START_LSB)
#define OLE_RX_CONFIG_RING0_PPDU_START_SET(x)                        (((x) << OLE_RX_CONFIG_RING0_PPDU_START_LSB) & OLE_RX_CONFIG_RING0_PPDU_START_MASK)
#define OLE_RX_CONFIG_RING0_PPDU_START_RESET                         0x1 // 1
#define OLE_RX_CONFIG_RING0_ADDRESS                                  0x7024
#define OLE_RX_CONFIG_RING0_OFFSET                                   0x7024
// SW modifiable bits
#define OLE_RX_CONFIG_RING0_SW_MASK                                  0xffffffff
// bits defined at reset
#define OLE_RX_CONFIG_RING0_RSTMASK                                  0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_RX_CONFIG_RING0_RESET                                    0x003f03ff

// 32'h7028 (OLE_RX_CONFIG_RING1)
#define OLE_RX_CONFIG_RING1_RESERVED_2_MSB                           31
#define OLE_RX_CONFIG_RING1_RESERVED_2_LSB                           28
#define OLE_RX_CONFIG_RING1_RESERVED_2_MASK                          0xf0000000
#define OLE_RX_CONFIG_RING1_RESERVED_2_GET(x)                        (((x) & OLE_RX_CONFIG_RING1_RESERVED_2_MASK) >> OLE_RX_CONFIG_RING1_RESERVED_2_LSB)
#define OLE_RX_CONFIG_RING1_RESERVED_2_SET(x)                        (((x) << OLE_RX_CONFIG_RING1_RESERVED_2_LSB) & OLE_RX_CONFIG_RING1_RESERVED_2_MASK)
#define OLE_RX_CONFIG_RING1_RESERVED_2_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING1_ETHERNET_3_MSB                           27
#define OLE_RX_CONFIG_RING1_ETHERNET_3_LSB                           27
#define OLE_RX_CONFIG_RING1_ETHERNET_3_MASK                          0x08000000
#define OLE_RX_CONFIG_RING1_ETHERNET_3_GET(x)                        (((x) & OLE_RX_CONFIG_RING1_ETHERNET_3_MASK) >> OLE_RX_CONFIG_RING1_ETHERNET_3_LSB)
#define OLE_RX_CONFIG_RING1_ETHERNET_3_SET(x)                        (((x) << OLE_RX_CONFIG_RING1_ETHERNET_3_LSB) & OLE_RX_CONFIG_RING1_ETHERNET_3_MASK)
#define OLE_RX_CONFIG_RING1_ETHERNET_3_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING1_ETHERNET_2_MSB                           26
#define OLE_RX_CONFIG_RING1_ETHERNET_2_LSB                           26
#define OLE_RX_CONFIG_RING1_ETHERNET_2_MASK                          0x04000000
#define OLE_RX_CONFIG_RING1_ETHERNET_2_GET(x)                        (((x) & OLE_RX_CONFIG_RING1_ETHERNET_2_MASK) >> OLE_RX_CONFIG_RING1_ETHERNET_2_LSB)
#define OLE_RX_CONFIG_RING1_ETHERNET_2_SET(x)                        (((x) << OLE_RX_CONFIG_RING1_ETHERNET_2_LSB) & OLE_RX_CONFIG_RING1_ETHERNET_2_MASK)
#define OLE_RX_CONFIG_RING1_ETHERNET_2_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING1_ETHERNET_1_MSB                           25
#define OLE_RX_CONFIG_RING1_ETHERNET_1_LSB                           25
#define OLE_RX_CONFIG_RING1_ETHERNET_1_MASK                          0x02000000
#define OLE_RX_CONFIG_RING1_ETHERNET_1_GET(x)                        (((x) & OLE_RX_CONFIG_RING1_ETHERNET_1_MASK) >> OLE_RX_CONFIG_RING1_ETHERNET_1_LSB)
#define OLE_RX_CONFIG_RING1_ETHERNET_1_SET(x)                        (((x) << OLE_RX_CONFIG_RING1_ETHERNET_1_LSB) & OLE_RX_CONFIG_RING1_ETHERNET_1_MASK)
#define OLE_RX_CONFIG_RING1_ETHERNET_1_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING1_ETHERNET_0_MSB                           24
#define OLE_RX_CONFIG_RING1_ETHERNET_0_LSB                           24
#define OLE_RX_CONFIG_RING1_ETHERNET_0_MASK                          0x01000000
#define OLE_RX_CONFIG_RING1_ETHERNET_0_GET(x)                        (((x) & OLE_RX_CONFIG_RING1_ETHERNET_0_MASK) >> OLE_RX_CONFIG_RING1_ETHERNET_0_LSB)
#define OLE_RX_CONFIG_RING1_ETHERNET_0_SET(x)                        (((x) << OLE_RX_CONFIG_RING1_ETHERNET_0_LSB) & OLE_RX_CONFIG_RING1_ETHERNET_0_MASK)
#define OLE_RX_CONFIG_RING1_ETHERNET_0_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING1_RESERVED_1_MSB                           23
#define OLE_RX_CONFIG_RING1_RESERVED_1_LSB                           22
#define OLE_RX_CONFIG_RING1_RESERVED_1_MASK                          0x00c00000
#define OLE_RX_CONFIG_RING1_RESERVED_1_GET(x)                        (((x) & OLE_RX_CONFIG_RING1_RESERVED_1_MASK) >> OLE_RX_CONFIG_RING1_RESERVED_1_LSB)
#define OLE_RX_CONFIG_RING1_RESERVED_1_SET(x)                        (((x) << OLE_RX_CONFIG_RING1_RESERVED_1_LSB) & OLE_RX_CONFIG_RING1_RESERVED_1_MASK)
#define OLE_RX_CONFIG_RING1_RESERVED_1_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_MSB                        21
#define OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_LSB                        21
#define OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_MASK                       0x00200000
#define OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_GET(x)                     (((x) & OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_SET(x)                     (((x) << OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING1_PHY_DATA_TYPE_RESET                      0x1 // 1
#define OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_MSB                       20
#define OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_LSB                       20
#define OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_MASK                      0x00100000
#define OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_GET(x)                    (((x) & OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_SET(x)                    (((x) << OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING1_NULL_DATA_TYPE_RESET                     0x1 // 1
#define OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_MSB                      19
#define OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_LSB                      19
#define OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_MASK                     0x00080000
#define OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_GET(x)                   (((x) & OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_SET(x)                   (((x) << OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING1_MCAST_DATA_TYPE_RESET                    0x1 // 1
#define OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_MSB                      18
#define OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_LSB                      18
#define OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_MASK                     0x00040000
#define OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_GET(x)                   (((x) & OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_SET(x)                   (((x) << OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING1_UCAST_DATA_TYPE_RESET                    0x1 // 1
#define OLE_RX_CONFIG_RING1_MGMT_TYPE_MSB                            17
#define OLE_RX_CONFIG_RING1_MGMT_TYPE_LSB                            17
#define OLE_RX_CONFIG_RING1_MGMT_TYPE_MASK                           0x00020000
#define OLE_RX_CONFIG_RING1_MGMT_TYPE_GET(x)                         (((x) & OLE_RX_CONFIG_RING1_MGMT_TYPE_MASK) >> OLE_RX_CONFIG_RING1_MGMT_TYPE_LSB)
#define OLE_RX_CONFIG_RING1_MGMT_TYPE_SET(x)                         (((x) << OLE_RX_CONFIG_RING1_MGMT_TYPE_LSB) & OLE_RX_CONFIG_RING1_MGMT_TYPE_MASK)
#define OLE_RX_CONFIG_RING1_MGMT_TYPE_RESET                          0x1 // 1
#define OLE_RX_CONFIG_RING1_CTRL_TYPE_MSB                            16
#define OLE_RX_CONFIG_RING1_CTRL_TYPE_LSB                            16
#define OLE_RX_CONFIG_RING1_CTRL_TYPE_MASK                           0x00010000
#define OLE_RX_CONFIG_RING1_CTRL_TYPE_GET(x)                         (((x) & OLE_RX_CONFIG_RING1_CTRL_TYPE_MASK) >> OLE_RX_CONFIG_RING1_CTRL_TYPE_LSB)
#define OLE_RX_CONFIG_RING1_CTRL_TYPE_SET(x)                         (((x) << OLE_RX_CONFIG_RING1_CTRL_TYPE_LSB) & OLE_RX_CONFIG_RING1_CTRL_TYPE_MASK)
#define OLE_RX_CONFIG_RING1_CTRL_TYPE_RESET                          0x1 // 1
#define OLE_RX_CONFIG_RING1_RESERVED_0_MSB                           15
#define OLE_RX_CONFIG_RING1_RESERVED_0_LSB                           10
#define OLE_RX_CONFIG_RING1_RESERVED_0_MASK                          0x0000fc00
#define OLE_RX_CONFIG_RING1_RESERVED_0_GET(x)                        (((x) & OLE_RX_CONFIG_RING1_RESERVED_0_MASK) >> OLE_RX_CONFIG_RING1_RESERVED_0_LSB)
#define OLE_RX_CONFIG_RING1_RESERVED_0_SET(x)                        (((x) << OLE_RX_CONFIG_RING1_RESERVED_0_LSB) & OLE_RX_CONFIG_RING1_RESERVED_0_MASK)
#define OLE_RX_CONFIG_RING1_RESERVED_0_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING1_FRAG_INFO_MSB                            9
#define OLE_RX_CONFIG_RING1_FRAG_INFO_LSB                            9
#define OLE_RX_CONFIG_RING1_FRAG_INFO_MASK                           0x00000200
#define OLE_RX_CONFIG_RING1_FRAG_INFO_GET(x)                         (((x) & OLE_RX_CONFIG_RING1_FRAG_INFO_MASK) >> OLE_RX_CONFIG_RING1_FRAG_INFO_LSB)
#define OLE_RX_CONFIG_RING1_FRAG_INFO_SET(x)                         (((x) << OLE_RX_CONFIG_RING1_FRAG_INFO_LSB) & OLE_RX_CONFIG_RING1_FRAG_INFO_MASK)
#define OLE_RX_CONFIG_RING1_FRAG_INFO_RESET                          0x0 // 0
#define OLE_RX_CONFIG_RING1_ATTENTION_MSB                            8
#define OLE_RX_CONFIG_RING1_ATTENTION_LSB                            8
#define OLE_RX_CONFIG_RING1_ATTENTION_MASK                           0x00000100
#define OLE_RX_CONFIG_RING1_ATTENTION_GET(x)                         (((x) & OLE_RX_CONFIG_RING1_ATTENTION_MASK) >> OLE_RX_CONFIG_RING1_ATTENTION_LSB)
#define OLE_RX_CONFIG_RING1_ATTENTION_SET(x)                         (((x) << OLE_RX_CONFIG_RING1_ATTENTION_LSB) & OLE_RX_CONFIG_RING1_ATTENTION_MASK)
#define OLE_RX_CONFIG_RING1_ATTENTION_RESET                          0x0 // 0
#define OLE_RX_CONFIG_RING1_PPDU_END_MSB                             7
#define OLE_RX_CONFIG_RING1_PPDU_END_LSB                             7
#define OLE_RX_CONFIG_RING1_PPDU_END_MASK                            0x00000080
#define OLE_RX_CONFIG_RING1_PPDU_END_GET(x)                          (((x) & OLE_RX_CONFIG_RING1_PPDU_END_MASK) >> OLE_RX_CONFIG_RING1_PPDU_END_LSB)
#define OLE_RX_CONFIG_RING1_PPDU_END_SET(x)                          (((x) << OLE_RX_CONFIG_RING1_PPDU_END_LSB) & OLE_RX_CONFIG_RING1_PPDU_END_MASK)
#define OLE_RX_CONFIG_RING1_PPDU_END_RESET                           0x0 // 0
#define OLE_RX_CONFIG_RING1_MPDU_END_MSB                             6
#define OLE_RX_CONFIG_RING1_MPDU_END_LSB                             6
#define OLE_RX_CONFIG_RING1_MPDU_END_MASK                            0x00000040
#define OLE_RX_CONFIG_RING1_MPDU_END_GET(x)                          (((x) & OLE_RX_CONFIG_RING1_MPDU_END_MASK) >> OLE_RX_CONFIG_RING1_MPDU_END_LSB)
#define OLE_RX_CONFIG_RING1_MPDU_END_SET(x)                          (((x) << OLE_RX_CONFIG_RING1_MPDU_END_LSB) & OLE_RX_CONFIG_RING1_MPDU_END_MASK)
#define OLE_RX_CONFIG_RING1_MPDU_END_RESET                           0x0 // 0
#define OLE_RX_CONFIG_RING1_MSDU_END_MSB                             5
#define OLE_RX_CONFIG_RING1_MSDU_END_LSB                             5
#define OLE_RX_CONFIG_RING1_MSDU_END_MASK                            0x00000020
#define OLE_RX_CONFIG_RING1_MSDU_END_GET(x)                          (((x) & OLE_RX_CONFIG_RING1_MSDU_END_MASK) >> OLE_RX_CONFIG_RING1_MSDU_END_LSB)
#define OLE_RX_CONFIG_RING1_MSDU_END_SET(x)                          (((x) << OLE_RX_CONFIG_RING1_MSDU_END_LSB) & OLE_RX_CONFIG_RING1_MSDU_END_MASK)
#define OLE_RX_CONFIG_RING1_MSDU_END_RESET                           0x0 // 0
#define OLE_RX_CONFIG_RING1_PKT_MSB                                  4
#define OLE_RX_CONFIG_RING1_PKT_LSB                                  4
#define OLE_RX_CONFIG_RING1_PKT_MASK                                 0x00000010
#define OLE_RX_CONFIG_RING1_PKT_GET(x)                               (((x) & OLE_RX_CONFIG_RING1_PKT_MASK) >> OLE_RX_CONFIG_RING1_PKT_LSB)
#define OLE_RX_CONFIG_RING1_PKT_SET(x)                               (((x) << OLE_RX_CONFIG_RING1_PKT_LSB) & OLE_RX_CONFIG_RING1_PKT_MASK)
#define OLE_RX_CONFIG_RING1_PKT_RESET                                0x0 // 0
#define OLE_RX_CONFIG_RING1_MSDU_START_MSB                           3
#define OLE_RX_CONFIG_RING1_MSDU_START_LSB                           3
#define OLE_RX_CONFIG_RING1_MSDU_START_MASK                          0x00000008
#define OLE_RX_CONFIG_RING1_MSDU_START_GET(x)                        (((x) & OLE_RX_CONFIG_RING1_MSDU_START_MASK) >> OLE_RX_CONFIG_RING1_MSDU_START_LSB)
#define OLE_RX_CONFIG_RING1_MSDU_START_SET(x)                        (((x) << OLE_RX_CONFIG_RING1_MSDU_START_LSB) & OLE_RX_CONFIG_RING1_MSDU_START_MASK)
#define OLE_RX_CONFIG_RING1_MSDU_START_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING1_MPDU_START_MSB                           2
#define OLE_RX_CONFIG_RING1_MPDU_START_LSB                           2
#define OLE_RX_CONFIG_RING1_MPDU_START_MASK                          0x00000004
#define OLE_RX_CONFIG_RING1_MPDU_START_GET(x)                        (((x) & OLE_RX_CONFIG_RING1_MPDU_START_MASK) >> OLE_RX_CONFIG_RING1_MPDU_START_LSB)
#define OLE_RX_CONFIG_RING1_MPDU_START_SET(x)                        (((x) << OLE_RX_CONFIG_RING1_MPDU_START_LSB) & OLE_RX_CONFIG_RING1_MPDU_START_MASK)
#define OLE_RX_CONFIG_RING1_MPDU_START_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING1_HDR_MSB                                  1
#define OLE_RX_CONFIG_RING1_HDR_LSB                                  1
#define OLE_RX_CONFIG_RING1_HDR_MASK                                 0x00000002
#define OLE_RX_CONFIG_RING1_HDR_GET(x)                               (((x) & OLE_RX_CONFIG_RING1_HDR_MASK) >> OLE_RX_CONFIG_RING1_HDR_LSB)
#define OLE_RX_CONFIG_RING1_HDR_SET(x)                               (((x) << OLE_RX_CONFIG_RING1_HDR_LSB) & OLE_RX_CONFIG_RING1_HDR_MASK)
#define OLE_RX_CONFIG_RING1_HDR_RESET                                0x0 // 0
#define OLE_RX_CONFIG_RING1_PPDU_START_MSB                           0
#define OLE_RX_CONFIG_RING1_PPDU_START_LSB                           0
#define OLE_RX_CONFIG_RING1_PPDU_START_MASK                          0x00000001
#define OLE_RX_CONFIG_RING1_PPDU_START_GET(x)                        (((x) & OLE_RX_CONFIG_RING1_PPDU_START_MASK) >> OLE_RX_CONFIG_RING1_PPDU_START_LSB)
#define OLE_RX_CONFIG_RING1_PPDU_START_SET(x)                        (((x) << OLE_RX_CONFIG_RING1_PPDU_START_LSB) & OLE_RX_CONFIG_RING1_PPDU_START_MASK)
#define OLE_RX_CONFIG_RING1_PPDU_START_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING1_ADDRESS                                  0x7028
#define OLE_RX_CONFIG_RING1_OFFSET                                   0x7028
// SW modifiable bits
#define OLE_RX_CONFIG_RING1_SW_MASK                                  0xffffffff
// bits defined at reset
#define OLE_RX_CONFIG_RING1_RSTMASK                                  0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_RX_CONFIG_RING1_RESET                                    0x003f0000

// 32'h702c (OLE_RX_CONFIG_RING2)
#define OLE_RX_CONFIG_RING2_RESERVED_2_MSB                           31
#define OLE_RX_CONFIG_RING2_RESERVED_2_LSB                           28
#define OLE_RX_CONFIG_RING2_RESERVED_2_MASK                          0xf0000000
#define OLE_RX_CONFIG_RING2_RESERVED_2_GET(x)                        (((x) & OLE_RX_CONFIG_RING2_RESERVED_2_MASK) >> OLE_RX_CONFIG_RING2_RESERVED_2_LSB)
#define OLE_RX_CONFIG_RING2_RESERVED_2_SET(x)                        (((x) << OLE_RX_CONFIG_RING2_RESERVED_2_LSB) & OLE_RX_CONFIG_RING2_RESERVED_2_MASK)
#define OLE_RX_CONFIG_RING2_RESERVED_2_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING2_ETHERNET_3_MSB                           27
#define OLE_RX_CONFIG_RING2_ETHERNET_3_LSB                           27
#define OLE_RX_CONFIG_RING2_ETHERNET_3_MASK                          0x08000000
#define OLE_RX_CONFIG_RING2_ETHERNET_3_GET(x)                        (((x) & OLE_RX_CONFIG_RING2_ETHERNET_3_MASK) >> OLE_RX_CONFIG_RING2_ETHERNET_3_LSB)
#define OLE_RX_CONFIG_RING2_ETHERNET_3_SET(x)                        (((x) << OLE_RX_CONFIG_RING2_ETHERNET_3_LSB) & OLE_RX_CONFIG_RING2_ETHERNET_3_MASK)
#define OLE_RX_CONFIG_RING2_ETHERNET_3_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING2_ETHERNET_2_MSB                           26
#define OLE_RX_CONFIG_RING2_ETHERNET_2_LSB                           26
#define OLE_RX_CONFIG_RING2_ETHERNET_2_MASK                          0x04000000
#define OLE_RX_CONFIG_RING2_ETHERNET_2_GET(x)                        (((x) & OLE_RX_CONFIG_RING2_ETHERNET_2_MASK) >> OLE_RX_CONFIG_RING2_ETHERNET_2_LSB)
#define OLE_RX_CONFIG_RING2_ETHERNET_2_SET(x)                        (((x) << OLE_RX_CONFIG_RING2_ETHERNET_2_LSB) & OLE_RX_CONFIG_RING2_ETHERNET_2_MASK)
#define OLE_RX_CONFIG_RING2_ETHERNET_2_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING2_ETHERNET_1_MSB                           25
#define OLE_RX_CONFIG_RING2_ETHERNET_1_LSB                           25
#define OLE_RX_CONFIG_RING2_ETHERNET_1_MASK                          0x02000000
#define OLE_RX_CONFIG_RING2_ETHERNET_1_GET(x)                        (((x) & OLE_RX_CONFIG_RING2_ETHERNET_1_MASK) >> OLE_RX_CONFIG_RING2_ETHERNET_1_LSB)
#define OLE_RX_CONFIG_RING2_ETHERNET_1_SET(x)                        (((x) << OLE_RX_CONFIG_RING2_ETHERNET_1_LSB) & OLE_RX_CONFIG_RING2_ETHERNET_1_MASK)
#define OLE_RX_CONFIG_RING2_ETHERNET_1_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING2_ETHERNET_0_MSB                           24
#define OLE_RX_CONFIG_RING2_ETHERNET_0_LSB                           24
#define OLE_RX_CONFIG_RING2_ETHERNET_0_MASK                          0x01000000
#define OLE_RX_CONFIG_RING2_ETHERNET_0_GET(x)                        (((x) & OLE_RX_CONFIG_RING2_ETHERNET_0_MASK) >> OLE_RX_CONFIG_RING2_ETHERNET_0_LSB)
#define OLE_RX_CONFIG_RING2_ETHERNET_0_SET(x)                        (((x) << OLE_RX_CONFIG_RING2_ETHERNET_0_LSB) & OLE_RX_CONFIG_RING2_ETHERNET_0_MASK)
#define OLE_RX_CONFIG_RING2_ETHERNET_0_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING2_RESERVED_1_MSB                           23
#define OLE_RX_CONFIG_RING2_RESERVED_1_LSB                           22
#define OLE_RX_CONFIG_RING2_RESERVED_1_MASK                          0x00c00000
#define OLE_RX_CONFIG_RING2_RESERVED_1_GET(x)                        (((x) & OLE_RX_CONFIG_RING2_RESERVED_1_MASK) >> OLE_RX_CONFIG_RING2_RESERVED_1_LSB)
#define OLE_RX_CONFIG_RING2_RESERVED_1_SET(x)                        (((x) << OLE_RX_CONFIG_RING2_RESERVED_1_LSB) & OLE_RX_CONFIG_RING2_RESERVED_1_MASK)
#define OLE_RX_CONFIG_RING2_RESERVED_1_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_MSB                        21
#define OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_LSB                        21
#define OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_MASK                       0x00200000
#define OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_GET(x)                     (((x) & OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_SET(x)                     (((x) << OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING2_PHY_DATA_TYPE_RESET                      0x1 // 1
#define OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_MSB                       20
#define OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_LSB                       20
#define OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_MASK                      0x00100000
#define OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_GET(x)                    (((x) & OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_SET(x)                    (((x) << OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING2_NULL_DATA_TYPE_RESET                     0x1 // 1
#define OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_MSB                      19
#define OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_LSB                      19
#define OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_MASK                     0x00080000
#define OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_GET(x)                   (((x) & OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_SET(x)                   (((x) << OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING2_MCAST_DATA_TYPE_RESET                    0x1 // 1
#define OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_MSB                      18
#define OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_LSB                      18
#define OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_MASK                     0x00040000
#define OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_GET(x)                   (((x) & OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_SET(x)                   (((x) << OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING2_UCAST_DATA_TYPE_RESET                    0x1 // 1
#define OLE_RX_CONFIG_RING2_MGMT_TYPE_MSB                            17
#define OLE_RX_CONFIG_RING2_MGMT_TYPE_LSB                            17
#define OLE_RX_CONFIG_RING2_MGMT_TYPE_MASK                           0x00020000
#define OLE_RX_CONFIG_RING2_MGMT_TYPE_GET(x)                         (((x) & OLE_RX_CONFIG_RING2_MGMT_TYPE_MASK) >> OLE_RX_CONFIG_RING2_MGMT_TYPE_LSB)
#define OLE_RX_CONFIG_RING2_MGMT_TYPE_SET(x)                         (((x) << OLE_RX_CONFIG_RING2_MGMT_TYPE_LSB) & OLE_RX_CONFIG_RING2_MGMT_TYPE_MASK)
#define OLE_RX_CONFIG_RING2_MGMT_TYPE_RESET                          0x1 // 1
#define OLE_RX_CONFIG_RING2_CTRL_TYPE_MSB                            16
#define OLE_RX_CONFIG_RING2_CTRL_TYPE_LSB                            16
#define OLE_RX_CONFIG_RING2_CTRL_TYPE_MASK                           0x00010000
#define OLE_RX_CONFIG_RING2_CTRL_TYPE_GET(x)                         (((x) & OLE_RX_CONFIG_RING2_CTRL_TYPE_MASK) >> OLE_RX_CONFIG_RING2_CTRL_TYPE_LSB)
#define OLE_RX_CONFIG_RING2_CTRL_TYPE_SET(x)                         (((x) << OLE_RX_CONFIG_RING2_CTRL_TYPE_LSB) & OLE_RX_CONFIG_RING2_CTRL_TYPE_MASK)
#define OLE_RX_CONFIG_RING2_CTRL_TYPE_RESET                          0x1 // 1
#define OLE_RX_CONFIG_RING2_RESERVED_0_MSB                           15
#define OLE_RX_CONFIG_RING2_RESERVED_0_LSB                           10
#define OLE_RX_CONFIG_RING2_RESERVED_0_MASK                          0x0000fc00
#define OLE_RX_CONFIG_RING2_RESERVED_0_GET(x)                        (((x) & OLE_RX_CONFIG_RING2_RESERVED_0_MASK) >> OLE_RX_CONFIG_RING2_RESERVED_0_LSB)
#define OLE_RX_CONFIG_RING2_RESERVED_0_SET(x)                        (((x) << OLE_RX_CONFIG_RING2_RESERVED_0_LSB) & OLE_RX_CONFIG_RING2_RESERVED_0_MASK)
#define OLE_RX_CONFIG_RING2_RESERVED_0_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING2_FRAG_INFO_MSB                            9
#define OLE_RX_CONFIG_RING2_FRAG_INFO_LSB                            9
#define OLE_RX_CONFIG_RING2_FRAG_INFO_MASK                           0x00000200
#define OLE_RX_CONFIG_RING2_FRAG_INFO_GET(x)                         (((x) & OLE_RX_CONFIG_RING2_FRAG_INFO_MASK) >> OLE_RX_CONFIG_RING2_FRAG_INFO_LSB)
#define OLE_RX_CONFIG_RING2_FRAG_INFO_SET(x)                         (((x) << OLE_RX_CONFIG_RING2_FRAG_INFO_LSB) & OLE_RX_CONFIG_RING2_FRAG_INFO_MASK)
#define OLE_RX_CONFIG_RING2_FRAG_INFO_RESET                          0x0 // 0
#define OLE_RX_CONFIG_RING2_ATTENTION_MSB                            8
#define OLE_RX_CONFIG_RING2_ATTENTION_LSB                            8
#define OLE_RX_CONFIG_RING2_ATTENTION_MASK                           0x00000100
#define OLE_RX_CONFIG_RING2_ATTENTION_GET(x)                         (((x) & OLE_RX_CONFIG_RING2_ATTENTION_MASK) >> OLE_RX_CONFIG_RING2_ATTENTION_LSB)
#define OLE_RX_CONFIG_RING2_ATTENTION_SET(x)                         (((x) << OLE_RX_CONFIG_RING2_ATTENTION_LSB) & OLE_RX_CONFIG_RING2_ATTENTION_MASK)
#define OLE_RX_CONFIG_RING2_ATTENTION_RESET                          0x0 // 0
#define OLE_RX_CONFIG_RING2_PPDU_END_MSB                             7
#define OLE_RX_CONFIG_RING2_PPDU_END_LSB                             7
#define OLE_RX_CONFIG_RING2_PPDU_END_MASK                            0x00000080
#define OLE_RX_CONFIG_RING2_PPDU_END_GET(x)                          (((x) & OLE_RX_CONFIG_RING2_PPDU_END_MASK) >> OLE_RX_CONFIG_RING2_PPDU_END_LSB)
#define OLE_RX_CONFIG_RING2_PPDU_END_SET(x)                          (((x) << OLE_RX_CONFIG_RING2_PPDU_END_LSB) & OLE_RX_CONFIG_RING2_PPDU_END_MASK)
#define OLE_RX_CONFIG_RING2_PPDU_END_RESET                           0x0 // 0
#define OLE_RX_CONFIG_RING2_MPDU_END_MSB                             6
#define OLE_RX_CONFIG_RING2_MPDU_END_LSB                             6
#define OLE_RX_CONFIG_RING2_MPDU_END_MASK                            0x00000040
#define OLE_RX_CONFIG_RING2_MPDU_END_GET(x)                          (((x) & OLE_RX_CONFIG_RING2_MPDU_END_MASK) >> OLE_RX_CONFIG_RING2_MPDU_END_LSB)
#define OLE_RX_CONFIG_RING2_MPDU_END_SET(x)                          (((x) << OLE_RX_CONFIG_RING2_MPDU_END_LSB) & OLE_RX_CONFIG_RING2_MPDU_END_MASK)
#define OLE_RX_CONFIG_RING2_MPDU_END_RESET                           0x0 // 0
#define OLE_RX_CONFIG_RING2_MSDU_END_MSB                             5
#define OLE_RX_CONFIG_RING2_MSDU_END_LSB                             5
#define OLE_RX_CONFIG_RING2_MSDU_END_MASK                            0x00000020
#define OLE_RX_CONFIG_RING2_MSDU_END_GET(x)                          (((x) & OLE_RX_CONFIG_RING2_MSDU_END_MASK) >> OLE_RX_CONFIG_RING2_MSDU_END_LSB)
#define OLE_RX_CONFIG_RING2_MSDU_END_SET(x)                          (((x) << OLE_RX_CONFIG_RING2_MSDU_END_LSB) & OLE_RX_CONFIG_RING2_MSDU_END_MASK)
#define OLE_RX_CONFIG_RING2_MSDU_END_RESET                           0x0 // 0
#define OLE_RX_CONFIG_RING2_PKT_MSB                                  4
#define OLE_RX_CONFIG_RING2_PKT_LSB                                  4
#define OLE_RX_CONFIG_RING2_PKT_MASK                                 0x00000010
#define OLE_RX_CONFIG_RING2_PKT_GET(x)                               (((x) & OLE_RX_CONFIG_RING2_PKT_MASK) >> OLE_RX_CONFIG_RING2_PKT_LSB)
#define OLE_RX_CONFIG_RING2_PKT_SET(x)                               (((x) << OLE_RX_CONFIG_RING2_PKT_LSB) & OLE_RX_CONFIG_RING2_PKT_MASK)
#define OLE_RX_CONFIG_RING2_PKT_RESET                                0x0 // 0
#define OLE_RX_CONFIG_RING2_MSDU_START_MSB                           3
#define OLE_RX_CONFIG_RING2_MSDU_START_LSB                           3
#define OLE_RX_CONFIG_RING2_MSDU_START_MASK                          0x00000008
#define OLE_RX_CONFIG_RING2_MSDU_START_GET(x)                        (((x) & OLE_RX_CONFIG_RING2_MSDU_START_MASK) >> OLE_RX_CONFIG_RING2_MSDU_START_LSB)
#define OLE_RX_CONFIG_RING2_MSDU_START_SET(x)                        (((x) << OLE_RX_CONFIG_RING2_MSDU_START_LSB) & OLE_RX_CONFIG_RING2_MSDU_START_MASK)
#define OLE_RX_CONFIG_RING2_MSDU_START_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING2_MPDU_START_MSB                           2
#define OLE_RX_CONFIG_RING2_MPDU_START_LSB                           2
#define OLE_RX_CONFIG_RING2_MPDU_START_MASK                          0x00000004
#define OLE_RX_CONFIG_RING2_MPDU_START_GET(x)                        (((x) & OLE_RX_CONFIG_RING2_MPDU_START_MASK) >> OLE_RX_CONFIG_RING2_MPDU_START_LSB)
#define OLE_RX_CONFIG_RING2_MPDU_START_SET(x)                        (((x) << OLE_RX_CONFIG_RING2_MPDU_START_LSB) & OLE_RX_CONFIG_RING2_MPDU_START_MASK)
#define OLE_RX_CONFIG_RING2_MPDU_START_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING2_HDR_MSB                                  1
#define OLE_RX_CONFIG_RING2_HDR_LSB                                  1
#define OLE_RX_CONFIG_RING2_HDR_MASK                                 0x00000002
#define OLE_RX_CONFIG_RING2_HDR_GET(x)                               (((x) & OLE_RX_CONFIG_RING2_HDR_MASK) >> OLE_RX_CONFIG_RING2_HDR_LSB)
#define OLE_RX_CONFIG_RING2_HDR_SET(x)                               (((x) << OLE_RX_CONFIG_RING2_HDR_LSB) & OLE_RX_CONFIG_RING2_HDR_MASK)
#define OLE_RX_CONFIG_RING2_HDR_RESET                                0x0 // 0
#define OLE_RX_CONFIG_RING2_PPDU_START_MSB                           0
#define OLE_RX_CONFIG_RING2_PPDU_START_LSB                           0
#define OLE_RX_CONFIG_RING2_PPDU_START_MASK                          0x00000001
#define OLE_RX_CONFIG_RING2_PPDU_START_GET(x)                        (((x) & OLE_RX_CONFIG_RING2_PPDU_START_MASK) >> OLE_RX_CONFIG_RING2_PPDU_START_LSB)
#define OLE_RX_CONFIG_RING2_PPDU_START_SET(x)                        (((x) << OLE_RX_CONFIG_RING2_PPDU_START_LSB) & OLE_RX_CONFIG_RING2_PPDU_START_MASK)
#define OLE_RX_CONFIG_RING2_PPDU_START_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING2_ADDRESS                                  0x702c
#define OLE_RX_CONFIG_RING2_OFFSET                                   0x702c
// SW modifiable bits
#define OLE_RX_CONFIG_RING2_SW_MASK                                  0xffffffff
// bits defined at reset
#define OLE_RX_CONFIG_RING2_RSTMASK                                  0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_RX_CONFIG_RING2_RESET                                    0x003f0000

// 32'h7030 (OLE_RX_CONFIG_RING3)
#define OLE_RX_CONFIG_RING3_RESERVED_2_MSB                           31
#define OLE_RX_CONFIG_RING3_RESERVED_2_LSB                           28
#define OLE_RX_CONFIG_RING3_RESERVED_2_MASK                          0xf0000000
#define OLE_RX_CONFIG_RING3_RESERVED_2_GET(x)                        (((x) & OLE_RX_CONFIG_RING3_RESERVED_2_MASK) >> OLE_RX_CONFIG_RING3_RESERVED_2_LSB)
#define OLE_RX_CONFIG_RING3_RESERVED_2_SET(x)                        (((x) << OLE_RX_CONFIG_RING3_RESERVED_2_LSB) & OLE_RX_CONFIG_RING3_RESERVED_2_MASK)
#define OLE_RX_CONFIG_RING3_RESERVED_2_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING3_ETHERNET_3_MSB                           27
#define OLE_RX_CONFIG_RING3_ETHERNET_3_LSB                           27
#define OLE_RX_CONFIG_RING3_ETHERNET_3_MASK                          0x08000000
#define OLE_RX_CONFIG_RING3_ETHERNET_3_GET(x)                        (((x) & OLE_RX_CONFIG_RING3_ETHERNET_3_MASK) >> OLE_RX_CONFIG_RING3_ETHERNET_3_LSB)
#define OLE_RX_CONFIG_RING3_ETHERNET_3_SET(x)                        (((x) << OLE_RX_CONFIG_RING3_ETHERNET_3_LSB) & OLE_RX_CONFIG_RING3_ETHERNET_3_MASK)
#define OLE_RX_CONFIG_RING3_ETHERNET_3_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING3_ETHERNET_2_MSB                           26
#define OLE_RX_CONFIG_RING3_ETHERNET_2_LSB                           26
#define OLE_RX_CONFIG_RING3_ETHERNET_2_MASK                          0x04000000
#define OLE_RX_CONFIG_RING3_ETHERNET_2_GET(x)                        (((x) & OLE_RX_CONFIG_RING3_ETHERNET_2_MASK) >> OLE_RX_CONFIG_RING3_ETHERNET_2_LSB)
#define OLE_RX_CONFIG_RING3_ETHERNET_2_SET(x)                        (((x) << OLE_RX_CONFIG_RING3_ETHERNET_2_LSB) & OLE_RX_CONFIG_RING3_ETHERNET_2_MASK)
#define OLE_RX_CONFIG_RING3_ETHERNET_2_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING3_ETHERNET_1_MSB                           25
#define OLE_RX_CONFIG_RING3_ETHERNET_1_LSB                           25
#define OLE_RX_CONFIG_RING3_ETHERNET_1_MASK                          0x02000000
#define OLE_RX_CONFIG_RING3_ETHERNET_1_GET(x)                        (((x) & OLE_RX_CONFIG_RING3_ETHERNET_1_MASK) >> OLE_RX_CONFIG_RING3_ETHERNET_1_LSB)
#define OLE_RX_CONFIG_RING3_ETHERNET_1_SET(x)                        (((x) << OLE_RX_CONFIG_RING3_ETHERNET_1_LSB) & OLE_RX_CONFIG_RING3_ETHERNET_1_MASK)
#define OLE_RX_CONFIG_RING3_ETHERNET_1_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING3_ETHERNET_0_MSB                           24
#define OLE_RX_CONFIG_RING3_ETHERNET_0_LSB                           24
#define OLE_RX_CONFIG_RING3_ETHERNET_0_MASK                          0x01000000
#define OLE_RX_CONFIG_RING3_ETHERNET_0_GET(x)                        (((x) & OLE_RX_CONFIG_RING3_ETHERNET_0_MASK) >> OLE_RX_CONFIG_RING3_ETHERNET_0_LSB)
#define OLE_RX_CONFIG_RING3_ETHERNET_0_SET(x)                        (((x) << OLE_RX_CONFIG_RING3_ETHERNET_0_LSB) & OLE_RX_CONFIG_RING3_ETHERNET_0_MASK)
#define OLE_RX_CONFIG_RING3_ETHERNET_0_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING3_RESERVED_1_MSB                           23
#define OLE_RX_CONFIG_RING3_RESERVED_1_LSB                           22
#define OLE_RX_CONFIG_RING3_RESERVED_1_MASK                          0x00c00000
#define OLE_RX_CONFIG_RING3_RESERVED_1_GET(x)                        (((x) & OLE_RX_CONFIG_RING3_RESERVED_1_MASK) >> OLE_RX_CONFIG_RING3_RESERVED_1_LSB)
#define OLE_RX_CONFIG_RING3_RESERVED_1_SET(x)                        (((x) << OLE_RX_CONFIG_RING3_RESERVED_1_LSB) & OLE_RX_CONFIG_RING3_RESERVED_1_MASK)
#define OLE_RX_CONFIG_RING3_RESERVED_1_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_MSB                        21
#define OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_LSB                        21
#define OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_MASK                       0x00200000
#define OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_GET(x)                     (((x) & OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_SET(x)                     (((x) << OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING3_PHY_DATA_TYPE_RESET                      0x1 // 1
#define OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_MSB                       20
#define OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_LSB                       20
#define OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_MASK                      0x00100000
#define OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_GET(x)                    (((x) & OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_SET(x)                    (((x) << OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING3_NULL_DATA_TYPE_RESET                     0x1 // 1
#define OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_MSB                      19
#define OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_LSB                      19
#define OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_MASK                     0x00080000
#define OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_GET(x)                   (((x) & OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_SET(x)                   (((x) << OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING3_MCAST_DATA_TYPE_RESET                    0x1 // 1
#define OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_MSB                      18
#define OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_LSB                      18
#define OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_MASK                     0x00040000
#define OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_GET(x)                   (((x) & OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_MASK) >> OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_LSB)
#define OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_SET(x)                   (((x) << OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_LSB) & OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_MASK)
#define OLE_RX_CONFIG_RING3_UCAST_DATA_TYPE_RESET                    0x1 // 1
#define OLE_RX_CONFIG_RING3_MGMT_TYPE_MSB                            17
#define OLE_RX_CONFIG_RING3_MGMT_TYPE_LSB                            17
#define OLE_RX_CONFIG_RING3_MGMT_TYPE_MASK                           0x00020000
#define OLE_RX_CONFIG_RING3_MGMT_TYPE_GET(x)                         (((x) & OLE_RX_CONFIG_RING3_MGMT_TYPE_MASK) >> OLE_RX_CONFIG_RING3_MGMT_TYPE_LSB)
#define OLE_RX_CONFIG_RING3_MGMT_TYPE_SET(x)                         (((x) << OLE_RX_CONFIG_RING3_MGMT_TYPE_LSB) & OLE_RX_CONFIG_RING3_MGMT_TYPE_MASK)
#define OLE_RX_CONFIG_RING3_MGMT_TYPE_RESET                          0x1 // 1
#define OLE_RX_CONFIG_RING3_CTRL_TYPE_MSB                            16
#define OLE_RX_CONFIG_RING3_CTRL_TYPE_LSB                            16
#define OLE_RX_CONFIG_RING3_CTRL_TYPE_MASK                           0x00010000
#define OLE_RX_CONFIG_RING3_CTRL_TYPE_GET(x)                         (((x) & OLE_RX_CONFIG_RING3_CTRL_TYPE_MASK) >> OLE_RX_CONFIG_RING3_CTRL_TYPE_LSB)
#define OLE_RX_CONFIG_RING3_CTRL_TYPE_SET(x)                         (((x) << OLE_RX_CONFIG_RING3_CTRL_TYPE_LSB) & OLE_RX_CONFIG_RING3_CTRL_TYPE_MASK)
#define OLE_RX_CONFIG_RING3_CTRL_TYPE_RESET                          0x1 // 1
#define OLE_RX_CONFIG_RING3_RESERVED_0_MSB                           15
#define OLE_RX_CONFIG_RING3_RESERVED_0_LSB                           10
#define OLE_RX_CONFIG_RING3_RESERVED_0_MASK                          0x0000fc00
#define OLE_RX_CONFIG_RING3_RESERVED_0_GET(x)                        (((x) & OLE_RX_CONFIG_RING3_RESERVED_0_MASK) >> OLE_RX_CONFIG_RING3_RESERVED_0_LSB)
#define OLE_RX_CONFIG_RING3_RESERVED_0_SET(x)                        (((x) << OLE_RX_CONFIG_RING3_RESERVED_0_LSB) & OLE_RX_CONFIG_RING3_RESERVED_0_MASK)
#define OLE_RX_CONFIG_RING3_RESERVED_0_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING3_FRAG_INFO_MSB                            9
#define OLE_RX_CONFIG_RING3_FRAG_INFO_LSB                            9
#define OLE_RX_CONFIG_RING3_FRAG_INFO_MASK                           0x00000200
#define OLE_RX_CONFIG_RING3_FRAG_INFO_GET(x)                         (((x) & OLE_RX_CONFIG_RING3_FRAG_INFO_MASK) >> OLE_RX_CONFIG_RING3_FRAG_INFO_LSB)
#define OLE_RX_CONFIG_RING3_FRAG_INFO_SET(x)                         (((x) << OLE_RX_CONFIG_RING3_FRAG_INFO_LSB) & OLE_RX_CONFIG_RING3_FRAG_INFO_MASK)
#define OLE_RX_CONFIG_RING3_FRAG_INFO_RESET                          0x0 // 0
#define OLE_RX_CONFIG_RING3_ATTENTION_MSB                            8
#define OLE_RX_CONFIG_RING3_ATTENTION_LSB                            8
#define OLE_RX_CONFIG_RING3_ATTENTION_MASK                           0x00000100
#define OLE_RX_CONFIG_RING3_ATTENTION_GET(x)                         (((x) & OLE_RX_CONFIG_RING3_ATTENTION_MASK) >> OLE_RX_CONFIG_RING3_ATTENTION_LSB)
#define OLE_RX_CONFIG_RING3_ATTENTION_SET(x)                         (((x) << OLE_RX_CONFIG_RING3_ATTENTION_LSB) & OLE_RX_CONFIG_RING3_ATTENTION_MASK)
#define OLE_RX_CONFIG_RING3_ATTENTION_RESET                          0x0 // 0
#define OLE_RX_CONFIG_RING3_PPDU_END_MSB                             7
#define OLE_RX_CONFIG_RING3_PPDU_END_LSB                             7
#define OLE_RX_CONFIG_RING3_PPDU_END_MASK                            0x00000080
#define OLE_RX_CONFIG_RING3_PPDU_END_GET(x)                          (((x) & OLE_RX_CONFIG_RING3_PPDU_END_MASK) >> OLE_RX_CONFIG_RING3_PPDU_END_LSB)
#define OLE_RX_CONFIG_RING3_PPDU_END_SET(x)                          (((x) << OLE_RX_CONFIG_RING3_PPDU_END_LSB) & OLE_RX_CONFIG_RING3_PPDU_END_MASK)
#define OLE_RX_CONFIG_RING3_PPDU_END_RESET                           0x0 // 0
#define OLE_RX_CONFIG_RING3_MPDU_END_MSB                             6
#define OLE_RX_CONFIG_RING3_MPDU_END_LSB                             6
#define OLE_RX_CONFIG_RING3_MPDU_END_MASK                            0x00000040
#define OLE_RX_CONFIG_RING3_MPDU_END_GET(x)                          (((x) & OLE_RX_CONFIG_RING3_MPDU_END_MASK) >> OLE_RX_CONFIG_RING3_MPDU_END_LSB)
#define OLE_RX_CONFIG_RING3_MPDU_END_SET(x)                          (((x) << OLE_RX_CONFIG_RING3_MPDU_END_LSB) & OLE_RX_CONFIG_RING3_MPDU_END_MASK)
#define OLE_RX_CONFIG_RING3_MPDU_END_RESET                           0x0 // 0
#define OLE_RX_CONFIG_RING3_MSDU_END_MSB                             5
#define OLE_RX_CONFIG_RING3_MSDU_END_LSB                             5
#define OLE_RX_CONFIG_RING3_MSDU_END_MASK                            0x00000020
#define OLE_RX_CONFIG_RING3_MSDU_END_GET(x)                          (((x) & OLE_RX_CONFIG_RING3_MSDU_END_MASK) >> OLE_RX_CONFIG_RING3_MSDU_END_LSB)
#define OLE_RX_CONFIG_RING3_MSDU_END_SET(x)                          (((x) << OLE_RX_CONFIG_RING3_MSDU_END_LSB) & OLE_RX_CONFIG_RING3_MSDU_END_MASK)
#define OLE_RX_CONFIG_RING3_MSDU_END_RESET                           0x0 // 0
#define OLE_RX_CONFIG_RING3_PKT_MSB                                  4
#define OLE_RX_CONFIG_RING3_PKT_LSB                                  4
#define OLE_RX_CONFIG_RING3_PKT_MASK                                 0x00000010
#define OLE_RX_CONFIG_RING3_PKT_GET(x)                               (((x) & OLE_RX_CONFIG_RING3_PKT_MASK) >> OLE_RX_CONFIG_RING3_PKT_LSB)
#define OLE_RX_CONFIG_RING3_PKT_SET(x)                               (((x) << OLE_RX_CONFIG_RING3_PKT_LSB) & OLE_RX_CONFIG_RING3_PKT_MASK)
#define OLE_RX_CONFIG_RING3_PKT_RESET                                0x0 // 0
#define OLE_RX_CONFIG_RING3_MSDU_START_MSB                           3
#define OLE_RX_CONFIG_RING3_MSDU_START_LSB                           3
#define OLE_RX_CONFIG_RING3_MSDU_START_MASK                          0x00000008
#define OLE_RX_CONFIG_RING3_MSDU_START_GET(x)                        (((x) & OLE_RX_CONFIG_RING3_MSDU_START_MASK) >> OLE_RX_CONFIG_RING3_MSDU_START_LSB)
#define OLE_RX_CONFIG_RING3_MSDU_START_SET(x)                        (((x) << OLE_RX_CONFIG_RING3_MSDU_START_LSB) & OLE_RX_CONFIG_RING3_MSDU_START_MASK)
#define OLE_RX_CONFIG_RING3_MSDU_START_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING3_MPDU_START_MSB                           2
#define OLE_RX_CONFIG_RING3_MPDU_START_LSB                           2
#define OLE_RX_CONFIG_RING3_MPDU_START_MASK                          0x00000004
#define OLE_RX_CONFIG_RING3_MPDU_START_GET(x)                        (((x) & OLE_RX_CONFIG_RING3_MPDU_START_MASK) >> OLE_RX_CONFIG_RING3_MPDU_START_LSB)
#define OLE_RX_CONFIG_RING3_MPDU_START_SET(x)                        (((x) << OLE_RX_CONFIG_RING3_MPDU_START_LSB) & OLE_RX_CONFIG_RING3_MPDU_START_MASK)
#define OLE_RX_CONFIG_RING3_MPDU_START_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING3_HDR_MSB                                  1
#define OLE_RX_CONFIG_RING3_HDR_LSB                                  1
#define OLE_RX_CONFIG_RING3_HDR_MASK                                 0x00000002
#define OLE_RX_CONFIG_RING3_HDR_GET(x)                               (((x) & OLE_RX_CONFIG_RING3_HDR_MASK) >> OLE_RX_CONFIG_RING3_HDR_LSB)
#define OLE_RX_CONFIG_RING3_HDR_SET(x)                               (((x) << OLE_RX_CONFIG_RING3_HDR_LSB) & OLE_RX_CONFIG_RING3_HDR_MASK)
#define OLE_RX_CONFIG_RING3_HDR_RESET                                0x0 // 0
#define OLE_RX_CONFIG_RING3_PPDU_START_MSB                           0
#define OLE_RX_CONFIG_RING3_PPDU_START_LSB                           0
#define OLE_RX_CONFIG_RING3_PPDU_START_MASK                          0x00000001
#define OLE_RX_CONFIG_RING3_PPDU_START_GET(x)                        (((x) & OLE_RX_CONFIG_RING3_PPDU_START_MASK) >> OLE_RX_CONFIG_RING3_PPDU_START_LSB)
#define OLE_RX_CONFIG_RING3_PPDU_START_SET(x)                        (((x) << OLE_RX_CONFIG_RING3_PPDU_START_LSB) & OLE_RX_CONFIG_RING3_PPDU_START_MASK)
#define OLE_RX_CONFIG_RING3_PPDU_START_RESET                         0x0 // 0
#define OLE_RX_CONFIG_RING3_ADDRESS                                  0x7030
#define OLE_RX_CONFIG_RING3_OFFSET                                   0x7030
// SW modifiable bits
#define OLE_RX_CONFIG_RING3_SW_MASK                                  0xffffffff
// bits defined at reset
#define OLE_RX_CONFIG_RING3_RSTMASK                                  0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_RX_CONFIG_RING3_RESET                                    0x003f0000

// 32'h7034 (OLE_DECAP_CONFIG)
#define OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_MSB                        15
#define OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_LSB                        8
#define OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_MASK                       0x0000ff00
#define OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_GET(x)                     (((x) & OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_MASK) >> OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_LSB)
#define OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_SET(x)                     (((x) << OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_LSB) & OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_MASK)
#define OLE_DECAP_CONFIG_CHECKSUM_TIMEOUT_RESET                      0x10 // 16
#define OLE_DECAP_CONFIG_CHECKSUM_DISABLE_MSB                        7
#define OLE_DECAP_CONFIG_CHECKSUM_DISABLE_LSB                        7
#define OLE_DECAP_CONFIG_CHECKSUM_DISABLE_MASK                       0x00000080
#define OLE_DECAP_CONFIG_CHECKSUM_DISABLE_GET(x)                     (((x) & OLE_DECAP_CONFIG_CHECKSUM_DISABLE_MASK) >> OLE_DECAP_CONFIG_CHECKSUM_DISABLE_LSB)
#define OLE_DECAP_CONFIG_CHECKSUM_DISABLE_SET(x)                     (((x) << OLE_DECAP_CONFIG_CHECKSUM_DISABLE_LSB) & OLE_DECAP_CONFIG_CHECKSUM_DISABLE_MASK)
#define OLE_DECAP_CONFIG_CHECKSUM_DISABLE_RESET                      0x0 // 0
#define OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_MSB               6
#define OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_LSB               6
#define OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_MASK              0x00000040
#define OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_GET(x)            (((x) & OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_MASK) >> OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_LSB)
#define OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_SET(x)            (((x) << OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_LSB) & OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_MASK)
#define OLE_DECAP_CONFIG_ONLY_DIRECTED_MCAST_BCAST_RESET             0x1 // 1
#define OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_MSB                    5
#define OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_LSB                    5
#define OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_MASK                   0x00000020
#define OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_GET(x)                 (((x) & OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_MASK) >> OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_LSB)
#define OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_SET(x)                 (((x) << OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_LSB) & OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_MASK)
#define OLE_DECAP_CONFIG_TCP_UDP_CHECKSUM_SEL_RESET                  0x1 // 1
#define OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_MSB                         4
#define OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_LSB                         4
#define OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_MASK                        0x00000010
#define OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_GET(x)                      (((x) & OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_MASK) >> OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_LSB)
#define OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_SET(x)                      (((x) << OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_LSB) & OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_MASK)
#define OLE_DECAP_CONFIG_IP_CHECKSUM_SEL_RESET                       0x1 // 1
#define OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_MSB                3
#define OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_LSB                3
#define OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_MASK               0x00000008
#define OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_GET(x)             (((x) & OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_MASK) >> OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_LSB)
#define OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_SET(x)             (((x) << OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_LSB) & OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_MASK)
#define OLE_DECAP_CONFIG_UNKNOWN_LLC_DECAP_ENABLE_RESET              0x1 // 1
#define OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_MSB                         2
#define OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_LSB                         2
#define OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_MASK                        0x00000004
#define OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_GET(x)                      (((x) & OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_MASK) >> OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_LSB)
#define OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_SET(x)                      (((x) << OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_LSB) & OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_MASK)
#define OLE_DECAP_CONFIG_REMOVE_VLAN_TAG_RESET                       0x0 // 0
#define OLE_DECAP_CONFIG_TARGET_FORMAT_MSB                           1
#define OLE_DECAP_CONFIG_TARGET_FORMAT_LSB                           1
#define OLE_DECAP_CONFIG_TARGET_FORMAT_MASK                          0x00000002
#define OLE_DECAP_CONFIG_TARGET_FORMAT_GET(x)                        (((x) & OLE_DECAP_CONFIG_TARGET_FORMAT_MASK) >> OLE_DECAP_CONFIG_TARGET_FORMAT_LSB)
#define OLE_DECAP_CONFIG_TARGET_FORMAT_SET(x)                        (((x) << OLE_DECAP_CONFIG_TARGET_FORMAT_LSB) & OLE_DECAP_CONFIG_TARGET_FORMAT_MASK)
#define OLE_DECAP_CONFIG_TARGET_FORMAT_RESET                         0x1 // 1
#define OLE_DECAP_CONFIG_ENABLE_MSB                                  0
#define OLE_DECAP_CONFIG_ENABLE_LSB                                  0
#define OLE_DECAP_CONFIG_ENABLE_MASK                                 0x00000001
#define OLE_DECAP_CONFIG_ENABLE_GET(x)                               (((x) & OLE_DECAP_CONFIG_ENABLE_MASK) >> OLE_DECAP_CONFIG_ENABLE_LSB)
#define OLE_DECAP_CONFIG_ENABLE_SET(x)                               (((x) << OLE_DECAP_CONFIG_ENABLE_LSB) & OLE_DECAP_CONFIG_ENABLE_MASK)
#define OLE_DECAP_CONFIG_ENABLE_RESET                                0x0 // 0
#define OLE_DECAP_CONFIG_ADDRESS                                     0x7034
#define OLE_DECAP_CONFIG_OFFSET                                      0x7034
// SW modifiable bits
#define OLE_DECAP_CONFIG_SW_MASK                                     0x0000ffff
// bits defined at reset
#define OLE_DECAP_CONFIG_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_CONFIG_RESET                                       0x0000107a

// 32'h7038 (OLE_HEADER_PADDING)
#define OLE_HEADER_PADDING_RX_ETH_PAD_INSERT_BEFORE_DA_MSB           4
#define OLE_HEADER_PADDING_RX_ETH_PAD_INSERT_BEFORE_DA_LSB           4
#define OLE_HEADER_PADDING_RX_ETH_PAD_INSERT_BEFORE_DA_MASK          0x00000010
#define OLE_HEADER_PADDING_RX_ETH_PAD_INSERT_BEFORE_DA_GET(x)        (((x) & OLE_HEADER_PADDING_RX_ETH_PAD_INSERT_BEFORE_DA_MASK) >> OLE_HEADER_PADDING_RX_ETH_PAD_INSERT_BEFORE_DA_LSB)
#define OLE_HEADER_PADDING_RX_ETH_PAD_INSERT_BEFORE_DA_SET(x)        (((x) << OLE_HEADER_PADDING_RX_ETH_PAD_INSERT_BEFORE_DA_LSB) & OLE_HEADER_PADDING_RX_ETH_PAD_INSERT_BEFORE_DA_MASK)
#define OLE_HEADER_PADDING_RX_ETH_PAD_INSERT_BEFORE_DA_RESET         0x0 // 0
#define OLE_HEADER_PADDING_RX_INSERT_HEADER_PADDING_MSB              3
#define OLE_HEADER_PADDING_RX_INSERT_HEADER_PADDING_LSB              3
#define OLE_HEADER_PADDING_RX_INSERT_HEADER_PADDING_MASK             0x00000008
#define OLE_HEADER_PADDING_RX_INSERT_HEADER_PADDING_GET(x)           (((x) & OLE_HEADER_PADDING_RX_INSERT_HEADER_PADDING_MASK) >> OLE_HEADER_PADDING_RX_INSERT_HEADER_PADDING_LSB)
#define OLE_HEADER_PADDING_RX_INSERT_HEADER_PADDING_SET(x)           (((x) << OLE_HEADER_PADDING_RX_INSERT_HEADER_PADDING_LSB) & OLE_HEADER_PADDING_RX_INSERT_HEADER_PADDING_MASK)
#define OLE_HEADER_PADDING_RX_INSERT_HEADER_PADDING_RESET            0x0 // 0
#define OLE_HEADER_PADDING_RX_INPUT_HEADER_PADDING_MSB               2
#define OLE_HEADER_PADDING_RX_INPUT_HEADER_PADDING_LSB               2
#define OLE_HEADER_PADDING_RX_INPUT_HEADER_PADDING_MASK              0x00000004
#define OLE_HEADER_PADDING_RX_INPUT_HEADER_PADDING_GET(x)            (((x) & OLE_HEADER_PADDING_RX_INPUT_HEADER_PADDING_MASK) >> OLE_HEADER_PADDING_RX_INPUT_HEADER_PADDING_LSB)
#define OLE_HEADER_PADDING_RX_INPUT_HEADER_PADDING_SET(x)            (((x) << OLE_HEADER_PADDING_RX_INPUT_HEADER_PADDING_LSB) & OLE_HEADER_PADDING_RX_INPUT_HEADER_PADDING_MASK)
#define OLE_HEADER_PADDING_RX_INPUT_HEADER_PADDING_RESET             0x1 // 1
#define OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_MSB              1
#define OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_LSB              1
#define OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_MASK             0x00000002
#define OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_GET(x)           (((x) & OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_MASK) >> OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_LSB)
#define OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_SET(x)           (((x) << OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_LSB) & OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_MASK)
#define OLE_HEADER_PADDING_TX_INSERT_HEADER_PADDING_RESET            0x1 // 1
#define OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_MSB               0
#define OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_LSB               0
#define OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_MASK              0x00000001
#define OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_GET(x)            (((x) & OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_MASK) >> OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_LSB)
#define OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_SET(x)            (((x) << OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_LSB) & OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_MASK)
#define OLE_HEADER_PADDING_TX_INPUT_HEADER_PADDING_RESET             0x0 // 0
#define OLE_HEADER_PADDING_ADDRESS                                   0x7038
#define OLE_HEADER_PADDING_OFFSET                                    0x7038
// SW modifiable bits
#define OLE_HEADER_PADDING_SW_MASK                                   0x0000001f
// bits defined at reset
#define OLE_HEADER_PADDING_RSTMASK                                   0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_HEADER_PADDING_RESET                                     0x00000006

// 32'h703c (OLE_DECAP_TABLE_0_HALF1)
#define OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_MSB                    25
#define OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_LSB                    25
#define OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_MASK                   0x02000000
#define OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_GET(x)                 (((x) & OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_MASK) >> OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_LSB)
#define OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_SET(x)                 (((x) << OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_LSB) & OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_MASK)
#define OLE_DECAP_TABLE_0_HALF1_SNAP_OR_TYPE2_RESET                  0x1 // 1
#define OLE_DECAP_TABLE_0_HALF1_ENABLE_MSB                           24
#define OLE_DECAP_TABLE_0_HALF1_ENABLE_LSB                           24
#define OLE_DECAP_TABLE_0_HALF1_ENABLE_MASK                          0x01000000
#define OLE_DECAP_TABLE_0_HALF1_ENABLE_GET(x)                        (((x) & OLE_DECAP_TABLE_0_HALF1_ENABLE_MASK) >> OLE_DECAP_TABLE_0_HALF1_ENABLE_LSB)
#define OLE_DECAP_TABLE_0_HALF1_ENABLE_SET(x)                        (((x) << OLE_DECAP_TABLE_0_HALF1_ENABLE_LSB) & OLE_DECAP_TABLE_0_HALF1_ENABLE_MASK)
#define OLE_DECAP_TABLE_0_HALF1_ENABLE_RESET                         0x1 // 1
#define OLE_DECAP_TABLE_0_HALF1_OUI_MSB                              23
#define OLE_DECAP_TABLE_0_HALF1_OUI_LSB                              0
#define OLE_DECAP_TABLE_0_HALF1_OUI_MASK                             0x00ffffff
#define OLE_DECAP_TABLE_0_HALF1_OUI_GET(x)                           (((x) & OLE_DECAP_TABLE_0_HALF1_OUI_MASK) >> OLE_DECAP_TABLE_0_HALF1_OUI_LSB)
#define OLE_DECAP_TABLE_0_HALF1_OUI_SET(x)                           (((x) << OLE_DECAP_TABLE_0_HALF1_OUI_LSB) & OLE_DECAP_TABLE_0_HALF1_OUI_MASK)
#define OLE_DECAP_TABLE_0_HALF1_OUI_RESET                            0x0 // 0
#define OLE_DECAP_TABLE_0_HALF1_ADDRESS                              0x703c
#define OLE_DECAP_TABLE_0_HALF1_OFFSET                               0x703c
// SW modifiable bits
#define OLE_DECAP_TABLE_0_HALF1_SW_MASK                              0x03ffffff
// bits defined at reset
#define OLE_DECAP_TABLE_0_HALF1_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_TABLE_0_HALF1_RESET                                0x03000000

// 32'h7040 (OLE_DECAP_TABLE_0_HALF2)
#define OLE_DECAP_TABLE_0_HALF2_TYPE_MSB                             15
#define OLE_DECAP_TABLE_0_HALF2_TYPE_LSB                             0
#define OLE_DECAP_TABLE_0_HALF2_TYPE_MASK                            0x0000ffff
#define OLE_DECAP_TABLE_0_HALF2_TYPE_GET(x)                          (((x) & OLE_DECAP_TABLE_0_HALF2_TYPE_MASK) >> OLE_DECAP_TABLE_0_HALF2_TYPE_LSB)
#define OLE_DECAP_TABLE_0_HALF2_TYPE_SET(x)                          (((x) << OLE_DECAP_TABLE_0_HALF2_TYPE_LSB) & OLE_DECAP_TABLE_0_HALF2_TYPE_MASK)
#define OLE_DECAP_TABLE_0_HALF2_TYPE_RESET                           0x800 // 2048
#define OLE_DECAP_TABLE_0_HALF2_ADDRESS                              0x7040
#define OLE_DECAP_TABLE_0_HALF2_OFFSET                               0x7040
// SW modifiable bits
#define OLE_DECAP_TABLE_0_HALF2_SW_MASK                              0x0000ffff
// bits defined at reset
#define OLE_DECAP_TABLE_0_HALF2_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_TABLE_0_HALF2_RESET                                0x00000800

// 32'h7044 (OLE_DECAP_TABLE_1_HALF1)
#define OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_MSB                    25
#define OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_LSB                    25
#define OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_MASK                   0x02000000
#define OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_GET(x)                 (((x) & OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_MASK) >> OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_LSB)
#define OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_SET(x)                 (((x) << OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_LSB) & OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_MASK)
#define OLE_DECAP_TABLE_1_HALF1_SNAP_OR_TYPE2_RESET                  0x1 // 1
#define OLE_DECAP_TABLE_1_HALF1_ENABLE_MSB                           24
#define OLE_DECAP_TABLE_1_HALF1_ENABLE_LSB                           24
#define OLE_DECAP_TABLE_1_HALF1_ENABLE_MASK                          0x01000000
#define OLE_DECAP_TABLE_1_HALF1_ENABLE_GET(x)                        (((x) & OLE_DECAP_TABLE_1_HALF1_ENABLE_MASK) >> OLE_DECAP_TABLE_1_HALF1_ENABLE_LSB)
#define OLE_DECAP_TABLE_1_HALF1_ENABLE_SET(x)                        (((x) << OLE_DECAP_TABLE_1_HALF1_ENABLE_LSB) & OLE_DECAP_TABLE_1_HALF1_ENABLE_MASK)
#define OLE_DECAP_TABLE_1_HALF1_ENABLE_RESET                         0x1 // 1
#define OLE_DECAP_TABLE_1_HALF1_OUI_MSB                              23
#define OLE_DECAP_TABLE_1_HALF1_OUI_LSB                              0
#define OLE_DECAP_TABLE_1_HALF1_OUI_MASK                             0x00ffffff
#define OLE_DECAP_TABLE_1_HALF1_OUI_GET(x)                           (((x) & OLE_DECAP_TABLE_1_HALF1_OUI_MASK) >> OLE_DECAP_TABLE_1_HALF1_OUI_LSB)
#define OLE_DECAP_TABLE_1_HALF1_OUI_SET(x)                           (((x) << OLE_DECAP_TABLE_1_HALF1_OUI_LSB) & OLE_DECAP_TABLE_1_HALF1_OUI_MASK)
#define OLE_DECAP_TABLE_1_HALF1_OUI_RESET                            0x0 // 0
#define OLE_DECAP_TABLE_1_HALF1_ADDRESS                              0x7044
#define OLE_DECAP_TABLE_1_HALF1_OFFSET                               0x7044
// SW modifiable bits
#define OLE_DECAP_TABLE_1_HALF1_SW_MASK                              0x03ffffff
// bits defined at reset
#define OLE_DECAP_TABLE_1_HALF1_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_TABLE_1_HALF1_RESET                                0x03000000

// 32'h7048 (OLE_DECAP_TABLE_1_HALF2)
#define OLE_DECAP_TABLE_1_HALF2_TYPE_MSB                             15
#define OLE_DECAP_TABLE_1_HALF2_TYPE_LSB                             0
#define OLE_DECAP_TABLE_1_HALF2_TYPE_MASK                            0x0000ffff
#define OLE_DECAP_TABLE_1_HALF2_TYPE_GET(x)                          (((x) & OLE_DECAP_TABLE_1_HALF2_TYPE_MASK) >> OLE_DECAP_TABLE_1_HALF2_TYPE_LSB)
#define OLE_DECAP_TABLE_1_HALF2_TYPE_SET(x)                          (((x) << OLE_DECAP_TABLE_1_HALF2_TYPE_LSB) & OLE_DECAP_TABLE_1_HALF2_TYPE_MASK)
#define OLE_DECAP_TABLE_1_HALF2_TYPE_RESET                           0x86dd // 34525
#define OLE_DECAP_TABLE_1_HALF2_ADDRESS                              0x7048
#define OLE_DECAP_TABLE_1_HALF2_OFFSET                               0x7048
// SW modifiable bits
#define OLE_DECAP_TABLE_1_HALF2_SW_MASK                              0x0000ffff
// bits defined at reset
#define OLE_DECAP_TABLE_1_HALF2_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_TABLE_1_HALF2_RESET                                0x000086dd

// 32'h704c (OLE_DECAP_TABLE_2_HALF1)
#define OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_MSB                    25
#define OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_LSB                    25
#define OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_MASK                   0x02000000
#define OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_GET(x)                 (((x) & OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_MASK) >> OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_LSB)
#define OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_SET(x)                 (((x) << OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_LSB) & OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_MASK)
#define OLE_DECAP_TABLE_2_HALF1_SNAP_OR_TYPE2_RESET                  0x1 // 1
#define OLE_DECAP_TABLE_2_HALF1_ENABLE_MSB                           24
#define OLE_DECAP_TABLE_2_HALF1_ENABLE_LSB                           24
#define OLE_DECAP_TABLE_2_HALF1_ENABLE_MASK                          0x01000000
#define OLE_DECAP_TABLE_2_HALF1_ENABLE_GET(x)                        (((x) & OLE_DECAP_TABLE_2_HALF1_ENABLE_MASK) >> OLE_DECAP_TABLE_2_HALF1_ENABLE_LSB)
#define OLE_DECAP_TABLE_2_HALF1_ENABLE_SET(x)                        (((x) << OLE_DECAP_TABLE_2_HALF1_ENABLE_LSB) & OLE_DECAP_TABLE_2_HALF1_ENABLE_MASK)
#define OLE_DECAP_TABLE_2_HALF1_ENABLE_RESET                         0x1 // 1
#define OLE_DECAP_TABLE_2_HALF1_OUI_MSB                              23
#define OLE_DECAP_TABLE_2_HALF1_OUI_LSB                              0
#define OLE_DECAP_TABLE_2_HALF1_OUI_MASK                             0x00ffffff
#define OLE_DECAP_TABLE_2_HALF1_OUI_GET(x)                           (((x) & OLE_DECAP_TABLE_2_HALF1_OUI_MASK) >> OLE_DECAP_TABLE_2_HALF1_OUI_LSB)
#define OLE_DECAP_TABLE_2_HALF1_OUI_SET(x)                           (((x) << OLE_DECAP_TABLE_2_HALF1_OUI_LSB) & OLE_DECAP_TABLE_2_HALF1_OUI_MASK)
#define OLE_DECAP_TABLE_2_HALF1_OUI_RESET                            0x0 // 0
#define OLE_DECAP_TABLE_2_HALF1_ADDRESS                              0x704c
#define OLE_DECAP_TABLE_2_HALF1_OFFSET                               0x704c
// SW modifiable bits
#define OLE_DECAP_TABLE_2_HALF1_SW_MASK                              0x03ffffff
// bits defined at reset
#define OLE_DECAP_TABLE_2_HALF1_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_TABLE_2_HALF1_RESET                                0x03000000

// 32'h7050 (OLE_DECAP_TABLE_2_HALF2)
#define OLE_DECAP_TABLE_2_HALF2_TYPE_MSB                             15
#define OLE_DECAP_TABLE_2_HALF2_TYPE_LSB                             0
#define OLE_DECAP_TABLE_2_HALF2_TYPE_MASK                            0x0000ffff
#define OLE_DECAP_TABLE_2_HALF2_TYPE_GET(x)                          (((x) & OLE_DECAP_TABLE_2_HALF2_TYPE_MASK) >> OLE_DECAP_TABLE_2_HALF2_TYPE_LSB)
#define OLE_DECAP_TABLE_2_HALF2_TYPE_SET(x)                          (((x) << OLE_DECAP_TABLE_2_HALF2_TYPE_LSB) & OLE_DECAP_TABLE_2_HALF2_TYPE_MASK)
#define OLE_DECAP_TABLE_2_HALF2_TYPE_RESET                           0x806 // 2054
#define OLE_DECAP_TABLE_2_HALF2_ADDRESS                              0x7050
#define OLE_DECAP_TABLE_2_HALF2_OFFSET                               0x7050
// SW modifiable bits
#define OLE_DECAP_TABLE_2_HALF2_SW_MASK                              0x0000ffff
// bits defined at reset
#define OLE_DECAP_TABLE_2_HALF2_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_TABLE_2_HALF2_RESET                                0x00000806

// 32'h7054 (OLE_DECAP_TABLE_3_HALF1)
#define OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_MSB                    25
#define OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_LSB                    25
#define OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_MASK                   0x02000000
#define OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_GET(x)                 (((x) & OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_MASK) >> OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_LSB)
#define OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_SET(x)                 (((x) << OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_LSB) & OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_MASK)
#define OLE_DECAP_TABLE_3_HALF1_SNAP_OR_TYPE2_RESET                  0x1 // 1
#define OLE_DECAP_TABLE_3_HALF1_ENABLE_MSB                           24
#define OLE_DECAP_TABLE_3_HALF1_ENABLE_LSB                           24
#define OLE_DECAP_TABLE_3_HALF1_ENABLE_MASK                          0x01000000
#define OLE_DECAP_TABLE_3_HALF1_ENABLE_GET(x)                        (((x) & OLE_DECAP_TABLE_3_HALF1_ENABLE_MASK) >> OLE_DECAP_TABLE_3_HALF1_ENABLE_LSB)
#define OLE_DECAP_TABLE_3_HALF1_ENABLE_SET(x)                        (((x) << OLE_DECAP_TABLE_3_HALF1_ENABLE_LSB) & OLE_DECAP_TABLE_3_HALF1_ENABLE_MASK)
#define OLE_DECAP_TABLE_3_HALF1_ENABLE_RESET                         0x1 // 1
#define OLE_DECAP_TABLE_3_HALF1_OUI_MSB                              23
#define OLE_DECAP_TABLE_3_HALF1_OUI_LSB                              0
#define OLE_DECAP_TABLE_3_HALF1_OUI_MASK                             0x00ffffff
#define OLE_DECAP_TABLE_3_HALF1_OUI_GET(x)                           (((x) & OLE_DECAP_TABLE_3_HALF1_OUI_MASK) >> OLE_DECAP_TABLE_3_HALF1_OUI_LSB)
#define OLE_DECAP_TABLE_3_HALF1_OUI_SET(x)                           (((x) << OLE_DECAP_TABLE_3_HALF1_OUI_LSB) & OLE_DECAP_TABLE_3_HALF1_OUI_MASK)
#define OLE_DECAP_TABLE_3_HALF1_OUI_RESET                            0x0 // 0
#define OLE_DECAP_TABLE_3_HALF1_ADDRESS                              0x7054
#define OLE_DECAP_TABLE_3_HALF1_OFFSET                               0x7054
// SW modifiable bits
#define OLE_DECAP_TABLE_3_HALF1_SW_MASK                              0x03ffffff
// bits defined at reset
#define OLE_DECAP_TABLE_3_HALF1_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_TABLE_3_HALF1_RESET                                0x03000000

// 32'h7058 (OLE_DECAP_TABLE_3_HALF2)
#define OLE_DECAP_TABLE_3_HALF2_TYPE_MSB                             15
#define OLE_DECAP_TABLE_3_HALF2_TYPE_LSB                             0
#define OLE_DECAP_TABLE_3_HALF2_TYPE_MASK                            0x0000ffff
#define OLE_DECAP_TABLE_3_HALF2_TYPE_GET(x)                          (((x) & OLE_DECAP_TABLE_3_HALF2_TYPE_MASK) >> OLE_DECAP_TABLE_3_HALF2_TYPE_LSB)
#define OLE_DECAP_TABLE_3_HALF2_TYPE_SET(x)                          (((x) << OLE_DECAP_TABLE_3_HALF2_TYPE_LSB) & OLE_DECAP_TABLE_3_HALF2_TYPE_MASK)
#define OLE_DECAP_TABLE_3_HALF2_TYPE_RESET                           0x809b // 32923
#define OLE_DECAP_TABLE_3_HALF2_ADDRESS                              0x7058
#define OLE_DECAP_TABLE_3_HALF2_OFFSET                               0x7058
// SW modifiable bits
#define OLE_DECAP_TABLE_3_HALF2_SW_MASK                              0x0000ffff
// bits defined at reset
#define OLE_DECAP_TABLE_3_HALF2_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_TABLE_3_HALF2_RESET                                0x0000809b

// 32'h705c (OLE_DECAP_TABLE_4_HALF1)
#define OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_MSB                    25
#define OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_LSB                    25
#define OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_MASK                   0x02000000
#define OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_GET(x)                 (((x) & OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_MASK) >> OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_LSB)
#define OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_SET(x)                 (((x) << OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_LSB) & OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_MASK)
#define OLE_DECAP_TABLE_4_HALF1_SNAP_OR_TYPE2_RESET                  0x1 // 1
#define OLE_DECAP_TABLE_4_HALF1_ENABLE_MSB                           24
#define OLE_DECAP_TABLE_4_HALF1_ENABLE_LSB                           24
#define OLE_DECAP_TABLE_4_HALF1_ENABLE_MASK                          0x01000000
#define OLE_DECAP_TABLE_4_HALF1_ENABLE_GET(x)                        (((x) & OLE_DECAP_TABLE_4_HALF1_ENABLE_MASK) >> OLE_DECAP_TABLE_4_HALF1_ENABLE_LSB)
#define OLE_DECAP_TABLE_4_HALF1_ENABLE_SET(x)                        (((x) << OLE_DECAP_TABLE_4_HALF1_ENABLE_LSB) & OLE_DECAP_TABLE_4_HALF1_ENABLE_MASK)
#define OLE_DECAP_TABLE_4_HALF1_ENABLE_RESET                         0x1 // 1
#define OLE_DECAP_TABLE_4_HALF1_OUI_MSB                              23
#define OLE_DECAP_TABLE_4_HALF1_OUI_LSB                              0
#define OLE_DECAP_TABLE_4_HALF1_OUI_MASK                             0x00ffffff
#define OLE_DECAP_TABLE_4_HALF1_OUI_GET(x)                           (((x) & OLE_DECAP_TABLE_4_HALF1_OUI_MASK) >> OLE_DECAP_TABLE_4_HALF1_OUI_LSB)
#define OLE_DECAP_TABLE_4_HALF1_OUI_SET(x)                           (((x) << OLE_DECAP_TABLE_4_HALF1_OUI_LSB) & OLE_DECAP_TABLE_4_HALF1_OUI_MASK)
#define OLE_DECAP_TABLE_4_HALF1_OUI_RESET                            0xf8 // 248
#define OLE_DECAP_TABLE_4_HALF1_ADDRESS                              0x705c
#define OLE_DECAP_TABLE_4_HALF1_OFFSET                               0x705c
// SW modifiable bits
#define OLE_DECAP_TABLE_4_HALF1_SW_MASK                              0x03ffffff
// bits defined at reset
#define OLE_DECAP_TABLE_4_HALF1_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_TABLE_4_HALF1_RESET                                0x030000f8

// 32'h7060 (OLE_DECAP_TABLE_4_HALF2)
#define OLE_DECAP_TABLE_4_HALF2_TYPE_MSB                             15
#define OLE_DECAP_TABLE_4_HALF2_TYPE_LSB                             0
#define OLE_DECAP_TABLE_4_HALF2_TYPE_MASK                            0x0000ffff
#define OLE_DECAP_TABLE_4_HALF2_TYPE_GET(x)                          (((x) & OLE_DECAP_TABLE_4_HALF2_TYPE_MASK) >> OLE_DECAP_TABLE_4_HALF2_TYPE_LSB)
#define OLE_DECAP_TABLE_4_HALF2_TYPE_SET(x)                          (((x) << OLE_DECAP_TABLE_4_HALF2_TYPE_LSB) & OLE_DECAP_TABLE_4_HALF2_TYPE_MASK)
#define OLE_DECAP_TABLE_4_HALF2_TYPE_RESET                           0x80f3 // 33011
#define OLE_DECAP_TABLE_4_HALF2_ADDRESS                              0x7060
#define OLE_DECAP_TABLE_4_HALF2_OFFSET                               0x7060
// SW modifiable bits
#define OLE_DECAP_TABLE_4_HALF2_SW_MASK                              0x0000ffff
// bits defined at reset
#define OLE_DECAP_TABLE_4_HALF2_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_TABLE_4_HALF2_RESET                                0x000080f3

// 32'h7064 (OLE_DECAP_TABLE_5_HALF1)
#define OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_MSB                    25
#define OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_LSB                    25
#define OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_MASK                   0x02000000
#define OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_GET(x)                 (((x) & OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_MASK) >> OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_LSB)
#define OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_SET(x)                 (((x) << OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_LSB) & OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_MASK)
#define OLE_DECAP_TABLE_5_HALF1_SNAP_OR_TYPE2_RESET                  0x1 // 1
#define OLE_DECAP_TABLE_5_HALF1_ENABLE_MSB                           24
#define OLE_DECAP_TABLE_5_HALF1_ENABLE_LSB                           24
#define OLE_DECAP_TABLE_5_HALF1_ENABLE_MASK                          0x01000000
#define OLE_DECAP_TABLE_5_HALF1_ENABLE_GET(x)                        (((x) & OLE_DECAP_TABLE_5_HALF1_ENABLE_MASK) >> OLE_DECAP_TABLE_5_HALF1_ENABLE_LSB)
#define OLE_DECAP_TABLE_5_HALF1_ENABLE_SET(x)                        (((x) << OLE_DECAP_TABLE_5_HALF1_ENABLE_LSB) & OLE_DECAP_TABLE_5_HALF1_ENABLE_MASK)
#define OLE_DECAP_TABLE_5_HALF1_ENABLE_RESET                         0x1 // 1
#define OLE_DECAP_TABLE_5_HALF1_OUI_MSB                              23
#define OLE_DECAP_TABLE_5_HALF1_OUI_LSB                              0
#define OLE_DECAP_TABLE_5_HALF1_OUI_MASK                             0x00ffffff
#define OLE_DECAP_TABLE_5_HALF1_OUI_GET(x)                           (((x) & OLE_DECAP_TABLE_5_HALF1_OUI_MASK) >> OLE_DECAP_TABLE_5_HALF1_OUI_LSB)
#define OLE_DECAP_TABLE_5_HALF1_OUI_SET(x)                           (((x) << OLE_DECAP_TABLE_5_HALF1_OUI_LSB) & OLE_DECAP_TABLE_5_HALF1_OUI_MASK)
#define OLE_DECAP_TABLE_5_HALF1_OUI_RESET                            0xf8 // 248
#define OLE_DECAP_TABLE_5_HALF1_ADDRESS                              0x7064
#define OLE_DECAP_TABLE_5_HALF1_OFFSET                               0x7064
// SW modifiable bits
#define OLE_DECAP_TABLE_5_HALF1_SW_MASK                              0x03ffffff
// bits defined at reset
#define OLE_DECAP_TABLE_5_HALF1_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_TABLE_5_HALF1_RESET                                0x030000f8

// 32'h7068 (OLE_DECAP_TABLE_5_HALF2)
#define OLE_DECAP_TABLE_5_HALF2_TYPE_MSB                             15
#define OLE_DECAP_TABLE_5_HALF2_TYPE_LSB                             0
#define OLE_DECAP_TABLE_5_HALF2_TYPE_MASK                            0x0000ffff
#define OLE_DECAP_TABLE_5_HALF2_TYPE_GET(x)                          (((x) & OLE_DECAP_TABLE_5_HALF2_TYPE_MASK) >> OLE_DECAP_TABLE_5_HALF2_TYPE_LSB)
#define OLE_DECAP_TABLE_5_HALF2_TYPE_SET(x)                          (((x) << OLE_DECAP_TABLE_5_HALF2_TYPE_LSB) & OLE_DECAP_TABLE_5_HALF2_TYPE_MASK)
#define OLE_DECAP_TABLE_5_HALF2_TYPE_RESET                           0x8137 // 33079
#define OLE_DECAP_TABLE_5_HALF2_ADDRESS                              0x7068
#define OLE_DECAP_TABLE_5_HALF2_OFFSET                               0x7068
// SW modifiable bits
#define OLE_DECAP_TABLE_5_HALF2_SW_MASK                              0x0000ffff
// bits defined at reset
#define OLE_DECAP_TABLE_5_HALF2_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_TABLE_5_HALF2_RESET                                0x00008137

// 32'h706c (OLE_DECAP_TABLE_6_HALF1)
#define OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_MSB                    25
#define OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_LSB                    25
#define OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_MASK                   0x02000000
#define OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_GET(x)                 (((x) & OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_MASK) >> OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_LSB)
#define OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_SET(x)                 (((x) << OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_LSB) & OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_MASK)
#define OLE_DECAP_TABLE_6_HALF1_SNAP_OR_TYPE2_RESET                  0x1 // 1
#define OLE_DECAP_TABLE_6_HALF1_ENABLE_MSB                           24
#define OLE_DECAP_TABLE_6_HALF1_ENABLE_LSB                           24
#define OLE_DECAP_TABLE_6_HALF1_ENABLE_MASK                          0x01000000
#define OLE_DECAP_TABLE_6_HALF1_ENABLE_GET(x)                        (((x) & OLE_DECAP_TABLE_6_HALF1_ENABLE_MASK) >> OLE_DECAP_TABLE_6_HALF1_ENABLE_LSB)
#define OLE_DECAP_TABLE_6_HALF1_ENABLE_SET(x)                        (((x) << OLE_DECAP_TABLE_6_HALF1_ENABLE_LSB) & OLE_DECAP_TABLE_6_HALF1_ENABLE_MASK)
#define OLE_DECAP_TABLE_6_HALF1_ENABLE_RESET                         0x0 // 0
#define OLE_DECAP_TABLE_6_HALF1_OUI_MSB                              23
#define OLE_DECAP_TABLE_6_HALF1_OUI_LSB                              0
#define OLE_DECAP_TABLE_6_HALF1_OUI_MASK                             0x00ffffff
#define OLE_DECAP_TABLE_6_HALF1_OUI_GET(x)                           (((x) & OLE_DECAP_TABLE_6_HALF1_OUI_MASK) >> OLE_DECAP_TABLE_6_HALF1_OUI_LSB)
#define OLE_DECAP_TABLE_6_HALF1_OUI_SET(x)                           (((x) << OLE_DECAP_TABLE_6_HALF1_OUI_LSB) & OLE_DECAP_TABLE_6_HALF1_OUI_MASK)
#define OLE_DECAP_TABLE_6_HALF1_OUI_RESET                            0x0 // 0
#define OLE_DECAP_TABLE_6_HALF1_ADDRESS                              0x706c
#define OLE_DECAP_TABLE_6_HALF1_OFFSET                               0x706c
// SW modifiable bits
#define OLE_DECAP_TABLE_6_HALF1_SW_MASK                              0x03ffffff
// bits defined at reset
#define OLE_DECAP_TABLE_6_HALF1_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_TABLE_6_HALF1_RESET                                0x02000000

// 32'h7070 (OLE_DECAP_TABLE_6_HALF2)
#define OLE_DECAP_TABLE_6_HALF2_TYPE_MSB                             15
#define OLE_DECAP_TABLE_6_HALF2_TYPE_LSB                             0
#define OLE_DECAP_TABLE_6_HALF2_TYPE_MASK                            0x0000ffff
#define OLE_DECAP_TABLE_6_HALF2_TYPE_GET(x)                          (((x) & OLE_DECAP_TABLE_6_HALF2_TYPE_MASK) >> OLE_DECAP_TABLE_6_HALF2_TYPE_LSB)
#define OLE_DECAP_TABLE_6_HALF2_TYPE_SET(x)                          (((x) << OLE_DECAP_TABLE_6_HALF2_TYPE_LSB) & OLE_DECAP_TABLE_6_HALF2_TYPE_MASK)
#define OLE_DECAP_TABLE_6_HALF2_TYPE_RESET                           0x800 // 2048
#define OLE_DECAP_TABLE_6_HALF2_ADDRESS                              0x7070
#define OLE_DECAP_TABLE_6_HALF2_OFFSET                               0x7070
// SW modifiable bits
#define OLE_DECAP_TABLE_6_HALF2_SW_MASK                              0x0000ffff
// bits defined at reset
#define OLE_DECAP_TABLE_6_HALF2_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_TABLE_6_HALF2_RESET                                0x00000800

// 32'h7074 (OLE_DECAP_TABLE_7_HALF1)
#define OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_MSB                    25
#define OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_LSB                    25
#define OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_MASK                   0x02000000
#define OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_GET(x)                 (((x) & OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_MASK) >> OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_LSB)
#define OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_SET(x)                 (((x) << OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_LSB) & OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_MASK)
#define OLE_DECAP_TABLE_7_HALF1_SNAP_OR_TYPE2_RESET                  0x1 // 1
#define OLE_DECAP_TABLE_7_HALF1_ENABLE_MSB                           24
#define OLE_DECAP_TABLE_7_HALF1_ENABLE_LSB                           24
#define OLE_DECAP_TABLE_7_HALF1_ENABLE_MASK                          0x01000000
#define OLE_DECAP_TABLE_7_HALF1_ENABLE_GET(x)                        (((x) & OLE_DECAP_TABLE_7_HALF1_ENABLE_MASK) >> OLE_DECAP_TABLE_7_HALF1_ENABLE_LSB)
#define OLE_DECAP_TABLE_7_HALF1_ENABLE_SET(x)                        (((x) << OLE_DECAP_TABLE_7_HALF1_ENABLE_LSB) & OLE_DECAP_TABLE_7_HALF1_ENABLE_MASK)
#define OLE_DECAP_TABLE_7_HALF1_ENABLE_RESET                         0x0 // 0
#define OLE_DECAP_TABLE_7_HALF1_OUI_MSB                              23
#define OLE_DECAP_TABLE_7_HALF1_OUI_LSB                              0
#define OLE_DECAP_TABLE_7_HALF1_OUI_MASK                             0x00ffffff
#define OLE_DECAP_TABLE_7_HALF1_OUI_GET(x)                           (((x) & OLE_DECAP_TABLE_7_HALF1_OUI_MASK) >> OLE_DECAP_TABLE_7_HALF1_OUI_LSB)
#define OLE_DECAP_TABLE_7_HALF1_OUI_SET(x)                           (((x) << OLE_DECAP_TABLE_7_HALF1_OUI_LSB) & OLE_DECAP_TABLE_7_HALF1_OUI_MASK)
#define OLE_DECAP_TABLE_7_HALF1_OUI_RESET                            0x0 // 0
#define OLE_DECAP_TABLE_7_HALF1_ADDRESS                              0x7074
#define OLE_DECAP_TABLE_7_HALF1_OFFSET                               0x7074
// SW modifiable bits
#define OLE_DECAP_TABLE_7_HALF1_SW_MASK                              0x03ffffff
// bits defined at reset
#define OLE_DECAP_TABLE_7_HALF1_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_TABLE_7_HALF1_RESET                                0x02000000

// 32'h7078 (OLE_DECAP_TABLE_7_HALF2)
#define OLE_DECAP_TABLE_7_HALF2_TYPE_MSB                             15
#define OLE_DECAP_TABLE_7_HALF2_TYPE_LSB                             0
#define OLE_DECAP_TABLE_7_HALF2_TYPE_MASK                            0x0000ffff
#define OLE_DECAP_TABLE_7_HALF2_TYPE_GET(x)                          (((x) & OLE_DECAP_TABLE_7_HALF2_TYPE_MASK) >> OLE_DECAP_TABLE_7_HALF2_TYPE_LSB)
#define OLE_DECAP_TABLE_7_HALF2_TYPE_SET(x)                          (((x) << OLE_DECAP_TABLE_7_HALF2_TYPE_LSB) & OLE_DECAP_TABLE_7_HALF2_TYPE_MASK)
#define OLE_DECAP_TABLE_7_HALF2_TYPE_RESET                           0x800 // 2048
#define OLE_DECAP_TABLE_7_HALF2_ADDRESS                              0x7078
#define OLE_DECAP_TABLE_7_HALF2_OFFSET                               0x7078
// SW modifiable bits
#define OLE_DECAP_TABLE_7_HALF2_SW_MASK                              0x0000ffff
// bits defined at reset
#define OLE_DECAP_TABLE_7_HALF2_RSTMASK                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_DECAP_TABLE_7_HALF2_RESET                                0x00000800

// 32'h707c (OLE_ASE_AST_BASE_ADDR)
#define OLE_ASE_AST_BASE_ADDR_VALUE_MSB                              31
#define OLE_ASE_AST_BASE_ADDR_VALUE_LSB                              0
#define OLE_ASE_AST_BASE_ADDR_VALUE_MASK                             0xffffffff
#define OLE_ASE_AST_BASE_ADDR_VALUE_GET(x)                           (((x) & OLE_ASE_AST_BASE_ADDR_VALUE_MASK) >> OLE_ASE_AST_BASE_ADDR_VALUE_LSB)
#define OLE_ASE_AST_BASE_ADDR_VALUE_SET(x)                           (((x) << OLE_ASE_AST_BASE_ADDR_VALUE_LSB) & OLE_ASE_AST_BASE_ADDR_VALUE_MASK)
#define OLE_ASE_AST_BASE_ADDR_VALUE_RESET                            0x0 // 0
#define OLE_ASE_AST_BASE_ADDR_ADDRESS                                0x707c
#define OLE_ASE_AST_BASE_ADDR_OFFSET                                 0x707c
// SW modifiable bits
#define OLE_ASE_AST_BASE_ADDR_SW_MASK                                0xffffffff
// bits defined at reset
#define OLE_ASE_AST_BASE_ADDR_RSTMASK                                0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_ASE_AST_BASE_ADDR_RESET                                  0x00000000

// 32'h7080 (OLE_ASE_AST_SIZE)
#define OLE_ASE_AST_SIZE_VALUE_MSB                                   12
#define OLE_ASE_AST_SIZE_VALUE_LSB                                   0
#define OLE_ASE_AST_SIZE_VALUE_MASK                                  0x00001fff
#define OLE_ASE_AST_SIZE_VALUE_GET(x)                                (((x) & OLE_ASE_AST_SIZE_VALUE_MASK) >> OLE_ASE_AST_SIZE_VALUE_LSB)
#define OLE_ASE_AST_SIZE_VALUE_SET(x)                                (((x) << OLE_ASE_AST_SIZE_VALUE_LSB) & OLE_ASE_AST_SIZE_VALUE_MASK)
#define OLE_ASE_AST_SIZE_VALUE_RESET                                 0x0 // 0
#define OLE_ASE_AST_SIZE_ADDRESS                                     0x7080
#define OLE_ASE_AST_SIZE_OFFSET                                      0x7080
// SW modifiable bits
#define OLE_ASE_AST_SIZE_SW_MASK                                     0x00001fff
// bits defined at reset
#define OLE_ASE_AST_SIZE_RSTMASK                                     0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_ASE_AST_SIZE_RESET                                       0x00000000

// 32'h7084 (OLE_ASE_SEARCH_CTRL)
#define OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_MSB                       31
#define OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_LSB                       16
#define OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_MASK                      0xffff0000
#define OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_GET(x)                    (((x) & OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_MASK) >> OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_LSB)
#define OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_SET(x)                    (((x) << OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_LSB) & OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_MASK)
#define OLE_ASE_SEARCH_CTRL_TIMEOUT_THRESH_RESET                     0x0 // 0
#define OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_MSB                     8
#define OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_LSB                     8
#define OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_MASK                    0x00000100
#define OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_GET(x)                  (((x) & OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_MASK) >> OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_LSB)
#define OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_SET(x)                  (((x) << OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_LSB) & OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_MASK)
#define OLE_ASE_SEARCH_CTRL_ADDR_SEARCH_SWAP_RESET                   0x0 // 0
#define OLE_ASE_SEARCH_CTRL_MAX_SEARCH_MSB                           7
#define OLE_ASE_SEARCH_CTRL_MAX_SEARCH_LSB                           0
#define OLE_ASE_SEARCH_CTRL_MAX_SEARCH_MASK                          0x000000ff
#define OLE_ASE_SEARCH_CTRL_MAX_SEARCH_GET(x)                        (((x) & OLE_ASE_SEARCH_CTRL_MAX_SEARCH_MASK) >> OLE_ASE_SEARCH_CTRL_MAX_SEARCH_LSB)
#define OLE_ASE_SEARCH_CTRL_MAX_SEARCH_SET(x)                        (((x) << OLE_ASE_SEARCH_CTRL_MAX_SEARCH_LSB) & OLE_ASE_SEARCH_CTRL_MAX_SEARCH_MASK)
#define OLE_ASE_SEARCH_CTRL_MAX_SEARCH_RESET                         0x0 // 0
#define OLE_ASE_SEARCH_CTRL_ADDRESS                                  0x7084
#define OLE_ASE_SEARCH_CTRL_OFFSET                                   0x7084
// SW modifiable bits
#define OLE_ASE_SEARCH_CTRL_SW_MASK                                  0xffff01ff
// bits defined at reset
#define OLE_ASE_SEARCH_CTRL_RSTMASK                                  0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_ASE_SEARCH_CTRL_RESET                                    0x00000000

// 32'h7088 (OLE_ASE_HASH_CTRL)
#define OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_MSB                       23
#define OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_LSB                       23
#define OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_MASK                      0x00800000
#define OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_GET(x)                    (((x) & OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_MASK) >> OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_LSB)
#define OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_SET(x)                    (((x) << OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_LSB) & OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_MASK)
#define OLE_ASE_HASH_CTRL_CACHE_INVALIDATE_RESET                     0x0 // 0
#define OLE_ASE_HASH_CTRL_CACHE_DISABLE_MSB                          22
#define OLE_ASE_HASH_CTRL_CACHE_DISABLE_LSB                          22
#define OLE_ASE_HASH_CTRL_CACHE_DISABLE_MASK                         0x00400000
#define OLE_ASE_HASH_CTRL_CACHE_DISABLE_GET(x)                       (((x) & OLE_ASE_HASH_CTRL_CACHE_DISABLE_MASK) >> OLE_ASE_HASH_CTRL_CACHE_DISABLE_LSB)
#define OLE_ASE_HASH_CTRL_CACHE_DISABLE_SET(x)                       (((x) << OLE_ASE_HASH_CTRL_CACHE_DISABLE_LSB) & OLE_ASE_HASH_CTRL_CACHE_DISABLE_MASK)
#define OLE_ASE_HASH_CTRL_CACHE_DISABLE_RESET                        0x0 // 0
#define OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_MSB                   21
#define OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_LSB                   21
#define OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_MASK                  0x00200000
#define OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_GET(x)                (((x) & OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_MASK) >> OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_LSB)
#define OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_SET(x)                (((x) << OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_LSB) & OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_MASK)
#define OLE_ASE_HASH_CTRL_HASH_MAC_31_0_IGNORE_RESET                 0x0 // 0
#define OLE_ASE_HASH_CTRL_HASH_SEL_MSB                               20
#define OLE_ASE_HASH_CTRL_HASH_SEL_LSB                               20
#define OLE_ASE_HASH_CTRL_HASH_SEL_MASK                              0x00100000
#define OLE_ASE_HASH_CTRL_HASH_SEL_GET(x)                            (((x) & OLE_ASE_HASH_CTRL_HASH_SEL_MASK) >> OLE_ASE_HASH_CTRL_HASH_SEL_LSB)
#define OLE_ASE_HASH_CTRL_HASH_SEL_SET(x)                            (((x) << OLE_ASE_HASH_CTRL_HASH_SEL_LSB) & OLE_ASE_HASH_CTRL_HASH_SEL_MASK)
#define OLE_ASE_HASH_CTRL_HASH_SEL_RESET                             0x1 // 1
#define OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_MSB                       19
#define OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_LSB                       16
#define OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_MASK                      0x000f0000
#define OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_GET(x)                    (((x) & OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_MASK) >> OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_LSB)
#define OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_SET(x)                    (((x) << OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_LSB) & OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_MASK)
#define OLE_ASE_HASH_CTRL_HASH_MCAST_SHIFT_RESET                     0x2 // 2
#define OLE_ASE_HASH_CTRL_HASH_XOR_MSB                               15
#define OLE_ASE_HASH_CTRL_HASH_XOR_LSB                               0
#define OLE_ASE_HASH_CTRL_HASH_XOR_MASK                              0x0000ffff
#define OLE_ASE_HASH_CTRL_HASH_XOR_GET(x)                            (((x) & OLE_ASE_HASH_CTRL_HASH_XOR_MASK) >> OLE_ASE_HASH_CTRL_HASH_XOR_LSB)
#define OLE_ASE_HASH_CTRL_HASH_XOR_SET(x)                            (((x) << OLE_ASE_HASH_CTRL_HASH_XOR_LSB) & OLE_ASE_HASH_CTRL_HASH_XOR_MASK)
#define OLE_ASE_HASH_CTRL_HASH_XOR_RESET                             0xabcd // 43981
#define OLE_ASE_HASH_CTRL_ADDRESS                                    0x7088
#define OLE_ASE_HASH_CTRL_OFFSET                                     0x7088
// SW modifiable bits
#define OLE_ASE_HASH_CTRL_SW_MASK                                    0x00ffffff
// bits defined at reset
#define OLE_ASE_HASH_CTRL_RSTMASK                                    0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_ASE_HASH_CTRL_RESET                                      0x0012abcd

// 32'h708c (OLE_CONFIG)
#define OLE_CONFIG_USE_BSSID_FOR_AMSDU_MSB                           4
#define OLE_CONFIG_USE_BSSID_FOR_AMSDU_LSB                           4
#define OLE_CONFIG_USE_BSSID_FOR_AMSDU_MASK                          0x00000010
#define OLE_CONFIG_USE_BSSID_FOR_AMSDU_GET(x)                        (((x) & OLE_CONFIG_USE_BSSID_FOR_AMSDU_MASK) >> OLE_CONFIG_USE_BSSID_FOR_AMSDU_LSB)
#define OLE_CONFIG_USE_BSSID_FOR_AMSDU_SET(x)                        (((x) << OLE_CONFIG_USE_BSSID_FOR_AMSDU_LSB) & OLE_CONFIG_USE_BSSID_FOR_AMSDU_MASK)
#define OLE_CONFIG_USE_BSSID_FOR_AMSDU_RESET                         0x1 // 1
#define OLE_CONFIG_TX_ABORT_MSB                                      3
#define OLE_CONFIG_TX_ABORT_LSB                                      3
#define OLE_CONFIG_TX_ABORT_MASK                                     0x00000008
#define OLE_CONFIG_TX_ABORT_GET(x)                                   (((x) & OLE_CONFIG_TX_ABORT_MASK) >> OLE_CONFIG_TX_ABORT_LSB)
#define OLE_CONFIG_TX_ABORT_SET(x)                                   (((x) << OLE_CONFIG_TX_ABORT_LSB) & OLE_CONFIG_TX_ABORT_MASK)
#define OLE_CONFIG_TX_ABORT_RESET                                    0x0 // 0
#define OLE_CONFIG_RX_RESET_MSB                                      2
#define OLE_CONFIG_RX_RESET_LSB                                      2
#define OLE_CONFIG_RX_RESET_MASK                                     0x00000004
#define OLE_CONFIG_RX_RESET_GET(x)                                   (((x) & OLE_CONFIG_RX_RESET_MASK) >> OLE_CONFIG_RX_RESET_LSB)
#define OLE_CONFIG_RX_RESET_SET(x)                                   (((x) << OLE_CONFIG_RX_RESET_LSB) & OLE_CONFIG_RX_RESET_MASK)
#define OLE_CONFIG_RX_RESET_RESET                                    0x0 // 0
#define OLE_CONFIG_TX_RESET_MSB                                      1
#define OLE_CONFIG_TX_RESET_LSB                                      1
#define OLE_CONFIG_TX_RESET_MASK                                     0x00000002
#define OLE_CONFIG_TX_RESET_GET(x)                                   (((x) & OLE_CONFIG_TX_RESET_MASK) >> OLE_CONFIG_TX_RESET_LSB)
#define OLE_CONFIG_TX_RESET_SET(x)                                   (((x) << OLE_CONFIG_TX_RESET_LSB) & OLE_CONFIG_TX_RESET_MASK)
#define OLE_CONFIG_TX_RESET_RESET                                    0x0 // 0
#define OLE_CONFIG_RESET_MSB                                         0
#define OLE_CONFIG_RESET_LSB                                         0
#define OLE_CONFIG_RESET_MASK                                        0x00000001
#define OLE_CONFIG_RESET_GET(x)                                      (((x) & OLE_CONFIG_RESET_MASK) >> OLE_CONFIG_RESET_LSB)
#define OLE_CONFIG_RESET_SET(x)                                      (((x) << OLE_CONFIG_RESET_LSB) & OLE_CONFIG_RESET_MASK)
#define OLE_CONFIG_RESET_RESET                                       0x0 // 0
#define OLE_CONFIG_ADDRESS                                           0x708c
#define OLE_CONFIG_OFFSET                                            0x708c
// SW modifiable bits
#define OLE_CONFIG_SW_MASK                                           0x0000001f
// bits defined at reset
#define OLE_CONFIG_RSTMASK                                           0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_CONFIG_RESET                                             0x00000010

// 32'h7090 (OLE_PN_SHIFT_FACTOR)
#define OLE_PN_SHIFT_FACTOR_VALUE_MSB                                3
#define OLE_PN_SHIFT_FACTOR_VALUE_LSB                                0
#define OLE_PN_SHIFT_FACTOR_VALUE_MASK                               0x0000000f
#define OLE_PN_SHIFT_FACTOR_VALUE_GET(x)                             (((x) & OLE_PN_SHIFT_FACTOR_VALUE_MASK) >> OLE_PN_SHIFT_FACTOR_VALUE_LSB)
#define OLE_PN_SHIFT_FACTOR_VALUE_SET(x)                             (((x) << OLE_PN_SHIFT_FACTOR_VALUE_LSB) & OLE_PN_SHIFT_FACTOR_VALUE_MASK)
#define OLE_PN_SHIFT_FACTOR_VALUE_RESET                              0x3 // 3
#define OLE_PN_SHIFT_FACTOR_ADDRESS                                  0x7090
#define OLE_PN_SHIFT_FACTOR_OFFSET                                   0x7090
// SW modifiable bits
#define OLE_PN_SHIFT_FACTOR_SW_MASK                                  0x0000000f
// bits defined at reset
#define OLE_PN_SHIFT_FACTOR_RSTMASK                                  0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_PN_SHIFT_FACTOR_RESET                                    0x00000003

// 32'h7094 (OLE_RX_CLASSIFY_ETHERNET_0)
#define OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_MSB                        16
#define OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_LSB                        16
#define OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_MASK                       0x00010000
#define OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_GET(x)                     (((x) & OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_MASK) >> OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_LSB)
#define OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_SET(x)                     (((x) << OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_LSB) & OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_MASK)
#define OLE_RX_CLASSIFY_ETHERNET_0_ENABLE_RESET                      0x0 // 0
#define OLE_RX_CLASSIFY_ETHERNET_0_TYPE_MSB                          15
#define OLE_RX_CLASSIFY_ETHERNET_0_TYPE_LSB                          0
#define OLE_RX_CLASSIFY_ETHERNET_0_TYPE_MASK                         0x0000ffff
#define OLE_RX_CLASSIFY_ETHERNET_0_TYPE_GET(x)                       (((x) & OLE_RX_CLASSIFY_ETHERNET_0_TYPE_MASK) >> OLE_RX_CLASSIFY_ETHERNET_0_TYPE_LSB)
#define OLE_RX_CLASSIFY_ETHERNET_0_TYPE_SET(x)                       (((x) << OLE_RX_CLASSIFY_ETHERNET_0_TYPE_LSB) & OLE_RX_CLASSIFY_ETHERNET_0_TYPE_MASK)
#define OLE_RX_CLASSIFY_ETHERNET_0_TYPE_RESET                        0x888e // 34958
#define OLE_RX_CLASSIFY_ETHERNET_0_ADDRESS                           0x7094
#define OLE_RX_CLASSIFY_ETHERNET_0_OFFSET                            0x7094
// SW modifiable bits
#define OLE_RX_CLASSIFY_ETHERNET_0_SW_MASK                           0x0001ffff
// bits defined at reset
#define OLE_RX_CLASSIFY_ETHERNET_0_RSTMASK                           0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_RX_CLASSIFY_ETHERNET_0_RESET                             0x0000888e

// 32'h7098 (OLE_RX_CLASSIFY_ETHERNET_1)
#define OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_MSB                        16
#define OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_LSB                        16
#define OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_MASK                       0x00010000
#define OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_GET(x)                     (((x) & OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_MASK) >> OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_LSB)
#define OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_SET(x)                     (((x) << OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_LSB) & OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_MASK)
#define OLE_RX_CLASSIFY_ETHERNET_1_ENABLE_RESET                      0x0 // 0
#define OLE_RX_CLASSIFY_ETHERNET_1_TYPE_MSB                          15
#define OLE_RX_CLASSIFY_ETHERNET_1_TYPE_LSB                          0
#define OLE_RX_CLASSIFY_ETHERNET_1_TYPE_MASK                         0x0000ffff
#define OLE_RX_CLASSIFY_ETHERNET_1_TYPE_GET(x)                       (((x) & OLE_RX_CLASSIFY_ETHERNET_1_TYPE_MASK) >> OLE_RX_CLASSIFY_ETHERNET_1_TYPE_LSB)
#define OLE_RX_CLASSIFY_ETHERNET_1_TYPE_SET(x)                       (((x) << OLE_RX_CLASSIFY_ETHERNET_1_TYPE_LSB) & OLE_RX_CLASSIFY_ETHERNET_1_TYPE_MASK)
#define OLE_RX_CLASSIFY_ETHERNET_1_TYPE_RESET                        0x888e // 34958
#define OLE_RX_CLASSIFY_ETHERNET_1_ADDRESS                           0x7098
#define OLE_RX_CLASSIFY_ETHERNET_1_OFFSET                            0x7098
// SW modifiable bits
#define OLE_RX_CLASSIFY_ETHERNET_1_SW_MASK                           0x0001ffff
// bits defined at reset
#define OLE_RX_CLASSIFY_ETHERNET_1_RSTMASK                           0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_RX_CLASSIFY_ETHERNET_1_RESET                             0x0000888e

// 32'h709c (OLE_RX_CLASSIFY_ETHERNET_2)
#define OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_MSB                        16
#define OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_LSB                        16
#define OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_MASK                       0x00010000
#define OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_GET(x)                     (((x) & OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_MASK) >> OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_LSB)
#define OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_SET(x)                     (((x) << OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_LSB) & OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_MASK)
#define OLE_RX_CLASSIFY_ETHERNET_2_ENABLE_RESET                      0x0 // 0
#define OLE_RX_CLASSIFY_ETHERNET_2_TYPE_MSB                          15
#define OLE_RX_CLASSIFY_ETHERNET_2_TYPE_LSB                          0
#define OLE_RX_CLASSIFY_ETHERNET_2_TYPE_MASK                         0x0000ffff
#define OLE_RX_CLASSIFY_ETHERNET_2_TYPE_GET(x)                       (((x) & OLE_RX_CLASSIFY_ETHERNET_2_TYPE_MASK) >> OLE_RX_CLASSIFY_ETHERNET_2_TYPE_LSB)
#define OLE_RX_CLASSIFY_ETHERNET_2_TYPE_SET(x)                       (((x) << OLE_RX_CLASSIFY_ETHERNET_2_TYPE_LSB) & OLE_RX_CLASSIFY_ETHERNET_2_TYPE_MASK)
#define OLE_RX_CLASSIFY_ETHERNET_2_TYPE_RESET                        0x888e // 34958
#define OLE_RX_CLASSIFY_ETHERNET_2_ADDRESS                           0x709c
#define OLE_RX_CLASSIFY_ETHERNET_2_OFFSET                            0x709c
// SW modifiable bits
#define OLE_RX_CLASSIFY_ETHERNET_2_SW_MASK                           0x0001ffff
// bits defined at reset
#define OLE_RX_CLASSIFY_ETHERNET_2_RSTMASK                           0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_RX_CLASSIFY_ETHERNET_2_RESET                             0x0000888e

// 32'h70a0 (OLE_RX_CLASSIFY_ETHERNET_3)
#define OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_MSB                        16
#define OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_LSB                        16
#define OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_MASK                       0x00010000
#define OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_GET(x)                     (((x) & OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_MASK) >> OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_LSB)
#define OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_SET(x)                     (((x) << OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_LSB) & OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_MASK)
#define OLE_RX_CLASSIFY_ETHERNET_3_ENABLE_RESET                      0x0 // 0
#define OLE_RX_CLASSIFY_ETHERNET_3_TYPE_MSB                          15
#define OLE_RX_CLASSIFY_ETHERNET_3_TYPE_LSB                          0
#define OLE_RX_CLASSIFY_ETHERNET_3_TYPE_MASK                         0x0000ffff
#define OLE_RX_CLASSIFY_ETHERNET_3_TYPE_GET(x)                       (((x) & OLE_RX_CLASSIFY_ETHERNET_3_TYPE_MASK) >> OLE_RX_CLASSIFY_ETHERNET_3_TYPE_LSB)
#define OLE_RX_CLASSIFY_ETHERNET_3_TYPE_SET(x)                       (((x) << OLE_RX_CLASSIFY_ETHERNET_3_TYPE_LSB) & OLE_RX_CLASSIFY_ETHERNET_3_TYPE_MASK)
#define OLE_RX_CLASSIFY_ETHERNET_3_TYPE_RESET                        0x888e // 34958
#define OLE_RX_CLASSIFY_ETHERNET_3_ADDRESS                           0x70a0
#define OLE_RX_CLASSIFY_ETHERNET_3_OFFSET                            0x70a0
// SW modifiable bits
#define OLE_RX_CLASSIFY_ETHERNET_3_SW_MASK                           0x0001ffff
// bits defined at reset
#define OLE_RX_CLASSIFY_ETHERNET_3_RSTMASK                           0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_RX_CLASSIFY_ETHERNET_3_RESET                             0x0000888e

// 32'h70a4 (OLE_OBS)
#define OLE_OBS_VALUE_MSB                                            31
#define OLE_OBS_VALUE_LSB                                            0
#define OLE_OBS_VALUE_MASK                                           0xffffffff
#define OLE_OBS_VALUE_GET(x)                                         (((x) & OLE_OBS_VALUE_MASK) >> OLE_OBS_VALUE_LSB)
#define OLE_OBS_VALUE_SET(x)                                         (((x) << OLE_OBS_VALUE_LSB) & OLE_OBS_VALUE_MASK)
#define OLE_OBS_VALUE_RESET                                          0x0 // 0
#define OLE_OBS_ADDRESS                                              0x70a4
#define OLE_OBS_OFFSET                                               0x70a4
// SW modifiable bits
#define OLE_OBS_SW_MASK                                              0xffffffff
// bits defined at reset
#define OLE_OBS_RSTMASK                                              0xffffffff
// reset value (ignore bits undefined at reset)
#define OLE_OBS_RESET                                                0x00000000


#endif /* _MAC_OLE_REG_H_ */
