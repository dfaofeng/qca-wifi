//                                                                             
// File:       ./mbox_host_reg.vrh                                             
// Creator:    tyzhang                                                         
// Time:       Thursday Aug 23, 2012 [3:28:15 pm]                              
//                                                                             
// Path:       /localtrees/tyzhang/tianfang_hanw_depot/chips/rome/dev/doc/headers/wl_soc_mac
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc ./mbox_host_reg.rdl    
//                                                                             
// Sources:    /localtrees/tyzhang/tianfang_hanw_depot/chips/rome/dev/doc/rtl/wlan/mbox_wlan/blueprint/mbox_host_reg.rdl
//             /localtrees/tyzhang/tianfang_hanw_depot/chips/rome/dev/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    hanw                                                            
// OS:         Linux 2.6.9-89.ELlargesmp                                       
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _MBOX_HOST_REG_H_
#define _MBOX_HOST_REG_H_
// 0x0800 (HOST_INT_STATUS)
#define HOST_INT_STATUS_COUNTER_INT_STATUS_MSB                       31
#define HOST_INT_STATUS_COUNTER_INT_STATUS_LSB                       24
#define HOST_INT_STATUS_COUNTER_INT_STATUS_MASK                      0xff000000
#define HOST_INT_STATUS_COUNTER_INT_STATUS_GET(x)                    (((x) & HOST_INT_STATUS_COUNTER_INT_STATUS_MASK) >> HOST_INT_STATUS_COUNTER_INT_STATUS_LSB)
#define HOST_INT_STATUS_COUNTER_INT_STATUS_SET(x)                    (((0 | (x)) << HOST_INT_STATUS_COUNTER_INT_STATUS_LSB) & HOST_INT_STATUS_COUNTER_INT_STATUS_MASK)
#define HOST_INT_STATUS_COUNTER_INT_STATUS_RESET                     0
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_SYNC_ERROR_MSB 21
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_SYNC_ERROR_LSB 21
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_SYNC_ERROR_MASK 0x00200000
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_SYNC_ERROR_GET(x) (((x) & HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_SYNC_ERROR_MASK) >> HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_SYNC_ERROR_LSB)
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_SYNC_ERROR_SET(x) (((0 | (x)) << HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_SYNC_ERROR_LSB) & HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_SYNC_ERROR_MASK)
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_SYNC_ERROR_RESET 0
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_OVERFLOW_MSB 20
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_OVERFLOW_LSB 20
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_OVERFLOW_MASK 0x00100000
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_OVERFLOW_GET(x) (((x) & HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_OVERFLOW_MASK) >> HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_OVERFLOW_LSB)
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_OVERFLOW_SET(x) (((0 | (x)) << HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_OVERFLOW_LSB) & HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_OVERFLOW_MASK)
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_OVERFLOW_RESET 0
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_UNDERFLOW_MSB 19
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_UNDERFLOW_LSB 19
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_UNDERFLOW_MASK 0x00080000
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_UNDERFLOW_GET(x) (((x) & HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_UNDERFLOW_MASK) >> HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_UNDERFLOW_LSB)
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_UNDERFLOW_SET(x) (((0 | (x)) << HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_UNDERFLOW_LSB) & HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_UNDERFLOW_MASK)
#define HOST_INT_STATUS_ERROR_INT_STATUS_UART_HCI_FRAMER_UNDERFLOW_RESET 0
#define HOST_INT_STATUS_ERROR_INT_STATUS_WAKEUP_MSB                  18
#define HOST_INT_STATUS_ERROR_INT_STATUS_WAKEUP_LSB                  18
#define HOST_INT_STATUS_ERROR_INT_STATUS_WAKEUP_MASK                 0x00040000
#define HOST_INT_STATUS_ERROR_INT_STATUS_WAKEUP_GET(x)               (((x) & HOST_INT_STATUS_ERROR_INT_STATUS_WAKEUP_MASK) >> HOST_INT_STATUS_ERROR_INT_STATUS_WAKEUP_LSB)
#define HOST_INT_STATUS_ERROR_INT_STATUS_WAKEUP_SET(x)               (((0 | (x)) << HOST_INT_STATUS_ERROR_INT_STATUS_WAKEUP_LSB) & HOST_INT_STATUS_ERROR_INT_STATUS_WAKEUP_MASK)
#define HOST_INT_STATUS_ERROR_INT_STATUS_WAKEUP_RESET                0
#define HOST_INT_STATUS_ERROR_INT_STATUS_RX_UNDERFLOW_MSB            17
#define HOST_INT_STATUS_ERROR_INT_STATUS_RX_UNDERFLOW_LSB            17
#define HOST_INT_STATUS_ERROR_INT_STATUS_RX_UNDERFLOW_MASK           0x00020000
#define HOST_INT_STATUS_ERROR_INT_STATUS_RX_UNDERFLOW_GET(x)         (((x) & HOST_INT_STATUS_ERROR_INT_STATUS_RX_UNDERFLOW_MASK) >> HOST_INT_STATUS_ERROR_INT_STATUS_RX_UNDERFLOW_LSB)
#define HOST_INT_STATUS_ERROR_INT_STATUS_RX_UNDERFLOW_SET(x)         (((0 | (x)) << HOST_INT_STATUS_ERROR_INT_STATUS_RX_UNDERFLOW_LSB) & HOST_INT_STATUS_ERROR_INT_STATUS_RX_UNDERFLOW_MASK)
#define HOST_INT_STATUS_ERROR_INT_STATUS_RX_UNDERFLOW_RESET          0
#define HOST_INT_STATUS_ERROR_INT_STATUS_TX_OVERFLOW_MSB             16
#define HOST_INT_STATUS_ERROR_INT_STATUS_TX_OVERFLOW_LSB             16
#define HOST_INT_STATUS_ERROR_INT_STATUS_TX_OVERFLOW_MASK            0x00010000
#define HOST_INT_STATUS_ERROR_INT_STATUS_TX_OVERFLOW_GET(x)          (((x) & HOST_INT_STATUS_ERROR_INT_STATUS_TX_OVERFLOW_MASK) >> HOST_INT_STATUS_ERROR_INT_STATUS_TX_OVERFLOW_LSB)
#define HOST_INT_STATUS_ERROR_INT_STATUS_TX_OVERFLOW_SET(x)          (((0 | (x)) << HOST_INT_STATUS_ERROR_INT_STATUS_TX_OVERFLOW_LSB) & HOST_INT_STATUS_ERROR_INT_STATUS_TX_OVERFLOW_MASK)
#define HOST_INT_STATUS_ERROR_INT_STATUS_TX_OVERFLOW_RESET           0
#define HOST_INT_STATUS_CPU_INT_STATUS_BIT_MSB                       15
#define HOST_INT_STATUS_CPU_INT_STATUS_BIT_LSB                       8
#define HOST_INT_STATUS_CPU_INT_STATUS_BIT_MASK                      0x0000ff00
#define HOST_INT_STATUS_CPU_INT_STATUS_BIT_GET(x)                    (((x) & HOST_INT_STATUS_CPU_INT_STATUS_BIT_MASK) >> HOST_INT_STATUS_CPU_INT_STATUS_BIT_LSB)
#define HOST_INT_STATUS_CPU_INT_STATUS_BIT_SET(x)                    (((0 | (x)) << HOST_INT_STATUS_CPU_INT_STATUS_BIT_LSB) & HOST_INT_STATUS_CPU_INT_STATUS_BIT_MASK)
#define HOST_INT_STATUS_CPU_INT_STATUS_BIT_RESET                     0
#define HOST_INT_STATUS_HOST_INT_ERROR_MSB                           7
#define HOST_INT_STATUS_HOST_INT_ERROR_LSB                           7
#define HOST_INT_STATUS_HOST_INT_ERROR_MASK                          0x00000080
#define HOST_INT_STATUS_HOST_INT_ERROR_GET(x)                        (((x) & HOST_INT_STATUS_HOST_INT_ERROR_MASK) >> HOST_INT_STATUS_HOST_INT_ERROR_LSB)
#define HOST_INT_STATUS_HOST_INT_ERROR_SET(x)                        (((0 | (x)) << HOST_INT_STATUS_HOST_INT_ERROR_LSB) & HOST_INT_STATUS_HOST_INT_ERROR_MASK)
#define HOST_INT_STATUS_HOST_INT_ERROR_RESET                         0
#define HOST_INT_STATUS_HOST_INT_CPU_MSB                             6
#define HOST_INT_STATUS_HOST_INT_CPU_LSB                             6
#define HOST_INT_STATUS_HOST_INT_CPU_MASK                            0x00000040
#define HOST_INT_STATUS_HOST_INT_CPU_GET(x)                          (((x) & HOST_INT_STATUS_HOST_INT_CPU_MASK) >> HOST_INT_STATUS_HOST_INT_CPU_LSB)
#define HOST_INT_STATUS_HOST_INT_CPU_SET(x)                          (((0 | (x)) << HOST_INT_STATUS_HOST_INT_CPU_LSB) & HOST_INT_STATUS_HOST_INT_CPU_MASK)
#define HOST_INT_STATUS_HOST_INT_CPU_RESET                           0
#define HOST_INT_STATUS_HOST_INT_INT_MSB                             5
#define HOST_INT_STATUS_HOST_INT_INT_LSB                             5
#define HOST_INT_STATUS_HOST_INT_INT_MASK                            0x00000020
#define HOST_INT_STATUS_HOST_INT_INT_GET(x)                          (((x) & HOST_INT_STATUS_HOST_INT_INT_MASK) >> HOST_INT_STATUS_HOST_INT_INT_LSB)
#define HOST_INT_STATUS_HOST_INT_INT_SET(x)                          (((0 | (x)) << HOST_INT_STATUS_HOST_INT_INT_LSB) & HOST_INT_STATUS_HOST_INT_INT_MASK)
#define HOST_INT_STATUS_HOST_INT_INT_RESET                           0
#define HOST_INT_STATUS_HOST_INT_COUNTER_MSB                         4
#define HOST_INT_STATUS_HOST_INT_COUNTER_LSB                         4
#define HOST_INT_STATUS_HOST_INT_COUNTER_MASK                        0x00000010
#define HOST_INT_STATUS_HOST_INT_COUNTER_GET(x)                      (((x) & HOST_INT_STATUS_HOST_INT_COUNTER_MASK) >> HOST_INT_STATUS_HOST_INT_COUNTER_LSB)
#define HOST_INT_STATUS_HOST_INT_COUNTER_SET(x)                      (((0 | (x)) << HOST_INT_STATUS_HOST_INT_COUNTER_LSB) & HOST_INT_STATUS_HOST_INT_COUNTER_MASK)
#define HOST_INT_STATUS_HOST_INT_COUNTER_RESET                       0
#define HOST_INT_STATUS_HOST_INT_MBOX_DATA_MSB                       3
#define HOST_INT_STATUS_HOST_INT_MBOX_DATA_LSB                       0
#define HOST_INT_STATUS_HOST_INT_MBOX_DATA_MASK                      0x0000000f
#define HOST_INT_STATUS_HOST_INT_MBOX_DATA_GET(x)                    (((x) & HOST_INT_STATUS_HOST_INT_MBOX_DATA_MASK) >> HOST_INT_STATUS_HOST_INT_MBOX_DATA_LSB)
#define HOST_INT_STATUS_HOST_INT_MBOX_DATA_SET(x)                    (((0 | (x)) << HOST_INT_STATUS_HOST_INT_MBOX_DATA_LSB) & HOST_INT_STATUS_HOST_INT_MBOX_DATA_MASK)
#define HOST_INT_STATUS_HOST_INT_MBOX_DATA_RESET                     0
#define HOST_INT_STATUS_ADDRESS                                      0x0800
#define HOST_INT_STATUS_HW_MASK                                      0xff3fffff
#define HOST_INT_STATUS_SW_MASK                                      0xff3fffff
#define HOST_INT_STATUS_HW_WRITE_MASK                                0xff3fffff
#define HOST_INT_STATUS_SW_WRITE_MASK                                0x003fff00
#define HOST_INT_STATUS_RSTMASK                                      0xffffffff
#define HOST_INT_STATUS_RESET                                        0x00000000

// 0x0804 (MBOX_STATUS)
#define MBOX_STATUS_GMBOX_RX_AVAIL_BYTE_MSB                          30
#define MBOX_STATUS_GMBOX_RX_AVAIL_BYTE_LSB                          24
#define MBOX_STATUS_GMBOX_RX_AVAIL_BYTE_MASK                         0x7f000000
#define MBOX_STATUS_GMBOX_RX_AVAIL_BYTE_GET(x)                       (((x) & MBOX_STATUS_GMBOX_RX_AVAIL_BYTE_MASK) >> MBOX_STATUS_GMBOX_RX_AVAIL_BYTE_LSB)
#define MBOX_STATUS_GMBOX_RX_AVAIL_BYTE_SET(x)                       (((0 | (x)) << MBOX_STATUS_GMBOX_RX_AVAIL_BYTE_LSB) & MBOX_STATUS_GMBOX_RX_AVAIL_BYTE_MASK)
#define MBOX_STATUS_GMBOX_RX_AVAIL_BYTE_RESET                        0
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_RX_UNDERFLOW_MSB          18
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_RX_UNDERFLOW_LSB          18
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_RX_UNDERFLOW_MASK         0x00040000
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_RX_UNDERFLOW_GET(x)       (((x) & MBOX_STATUS_HOST_INT_STATUS2_GMBOX_RX_UNDERFLOW_MASK) >> MBOX_STATUS_HOST_INT_STATUS2_GMBOX_RX_UNDERFLOW_LSB)
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_RX_UNDERFLOW_SET(x)       (((0 | (x)) << MBOX_STATUS_HOST_INT_STATUS2_GMBOX_RX_UNDERFLOW_LSB) & MBOX_STATUS_HOST_INT_STATUS2_GMBOX_RX_UNDERFLOW_MASK)
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_RX_UNDERFLOW_RESET        0
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_TX_OVERFLOW_MSB           17
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_TX_OVERFLOW_LSB           17
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_TX_OVERFLOW_MASK          0x00020000
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_TX_OVERFLOW_GET(x)        (((x) & MBOX_STATUS_HOST_INT_STATUS2_GMBOX_TX_OVERFLOW_MASK) >> MBOX_STATUS_HOST_INT_STATUS2_GMBOX_TX_OVERFLOW_LSB)
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_TX_OVERFLOW_SET(x)        (((0 | (x)) << MBOX_STATUS_HOST_INT_STATUS2_GMBOX_TX_OVERFLOW_LSB) & MBOX_STATUS_HOST_INT_STATUS2_GMBOX_TX_OVERFLOW_MASK)
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_TX_OVERFLOW_RESET         0
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_DATA_MSB                  16
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_DATA_LSB                  16
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_DATA_MASK                 0x00010000
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_DATA_GET(x)               (((x) & MBOX_STATUS_HOST_INT_STATUS2_GMBOX_DATA_MASK) >> MBOX_STATUS_HOST_INT_STATUS2_GMBOX_DATA_LSB)
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_DATA_SET(x)               (((0 | (x)) << MBOX_STATUS_HOST_INT_STATUS2_GMBOX_DATA_LSB) & MBOX_STATUS_HOST_INT_STATUS2_GMBOX_DATA_MASK)
#define MBOX_STATUS_HOST_INT_STATUS2_GMBOX_DATA_RESET                0
#define MBOX_STATUS_RX_LOOKAHEAD_VALID_MBOX_MSB                      11
#define MBOX_STATUS_RX_LOOKAHEAD_VALID_MBOX_LSB                      8
#define MBOX_STATUS_RX_LOOKAHEAD_VALID_MBOX_MASK                     0x00000f00
#define MBOX_STATUS_RX_LOOKAHEAD_VALID_MBOX_GET(x)                   (((x) & MBOX_STATUS_RX_LOOKAHEAD_VALID_MBOX_MASK) >> MBOX_STATUS_RX_LOOKAHEAD_VALID_MBOX_LSB)
#define MBOX_STATUS_RX_LOOKAHEAD_VALID_MBOX_SET(x)                   (((0 | (x)) << MBOX_STATUS_RX_LOOKAHEAD_VALID_MBOX_LSB) & MBOX_STATUS_RX_LOOKAHEAD_VALID_MBOX_MASK)
#define MBOX_STATUS_RX_LOOKAHEAD_VALID_MBOX_RESET                    0
#define MBOX_STATUS_MBOX_RX_EOM_MSB                                  7
#define MBOX_STATUS_MBOX_RX_EOM_LSB                                  4
#define MBOX_STATUS_MBOX_RX_EOM_MASK                                 0x000000f0
#define MBOX_STATUS_MBOX_RX_EOM_GET(x)                               (((x) & MBOX_STATUS_MBOX_RX_EOM_MASK) >> MBOX_STATUS_MBOX_RX_EOM_LSB)
#define MBOX_STATUS_MBOX_RX_EOM_SET(x)                               (((0 | (x)) << MBOX_STATUS_MBOX_RX_EOM_LSB) & MBOX_STATUS_MBOX_RX_EOM_MASK)
#define MBOX_STATUS_MBOX_RX_EOM_RESET                                0
#define MBOX_STATUS_MBOX_RX_SOM_MSB                                  3
#define MBOX_STATUS_MBOX_RX_SOM_LSB                                  0
#define MBOX_STATUS_MBOX_RX_SOM_MASK                                 0x0000000f
#define MBOX_STATUS_MBOX_RX_SOM_GET(x)                               (((x) & MBOX_STATUS_MBOX_RX_SOM_MASK) >> MBOX_STATUS_MBOX_RX_SOM_LSB)
#define MBOX_STATUS_MBOX_RX_SOM_SET(x)                               (((0 | (x)) << MBOX_STATUS_MBOX_RX_SOM_LSB) & MBOX_STATUS_MBOX_RX_SOM_MASK)
#define MBOX_STATUS_MBOX_RX_SOM_RESET                                15
#define MBOX_STATUS_ADDRESS                                          0x0804
#define MBOX_STATUS_HW_MASK                                          0x7f070fff
#define MBOX_STATUS_SW_MASK                                          0x7f070fff
#define MBOX_STATUS_HW_WRITE_MASK                                    0x00070fff
#define MBOX_STATUS_SW_WRITE_MASK                                    0x7f060000
#define MBOX_STATUS_RSTMASK                                          0xffffffff
#define MBOX_STATUS_RESET                                            0x0000000f

// 0x0808 (RX_LOOKAHEAD0_0)
#define RX_LOOKAHEAD0_0_DATA_MSB                                     31
#define RX_LOOKAHEAD0_0_DATA_LSB                                     0
#define RX_LOOKAHEAD0_0_DATA_MASK                                    0xffffffff
#define RX_LOOKAHEAD0_0_DATA_GET(x)                                  (((x) & RX_LOOKAHEAD0_0_DATA_MASK) >> RX_LOOKAHEAD0_0_DATA_LSB)
#define RX_LOOKAHEAD0_0_DATA_SET(x)                                  (((0 | (x)) << RX_LOOKAHEAD0_0_DATA_LSB) & RX_LOOKAHEAD0_0_DATA_MASK)
#define RX_LOOKAHEAD0_0_DATA_RESET                                   0
#define RX_LOOKAHEAD0_0_ADDRESS                                      0x0808
#define RX_LOOKAHEAD0_ADDRESS                                        RX_LOOKAHEAD0_0_ADDRESS
#define RX_LOOKAHEAD0_0_HW_MASK                                      0xffffffff
#define RX_LOOKAHEAD0_0_SW_MASK                                      0xffffffff
#define RX_LOOKAHEAD0_0_HW_WRITE_MASK                                0xffffffff
#define RX_LOOKAHEAD0_0_SW_WRITE_MASK                                0x00000000
#define RX_LOOKAHEAD0_0_RSTMASK                                      0xffffffff
#define RX_LOOKAHEAD0_0_RESET                                        0x00000000

// 0x080c (RX_LOOKAHEAD0_1)
#define RX_LOOKAHEAD0_1_DATA_MSB                                     31
#define RX_LOOKAHEAD0_1_DATA_LSB                                     0
#define RX_LOOKAHEAD0_1_DATA_MASK                                    0xffffffff
#define RX_LOOKAHEAD0_1_DATA_GET(x)                                  (((x) & RX_LOOKAHEAD0_1_DATA_MASK) >> RX_LOOKAHEAD0_1_DATA_LSB)
#define RX_LOOKAHEAD0_1_DATA_SET(x)                                  (((0 | (x)) << RX_LOOKAHEAD0_1_DATA_LSB) & RX_LOOKAHEAD0_1_DATA_MASK)
#define RX_LOOKAHEAD0_1_DATA_RESET                                   0
#define RX_LOOKAHEAD0_1_ADDRESS                                      0x080c
#define RX_LOOKAHEAD0_1_HW_MASK                                      0xffffffff
#define RX_LOOKAHEAD0_1_SW_MASK                                      0xffffffff
#define RX_LOOKAHEAD0_1_HW_WRITE_MASK                                0xffffffff
#define RX_LOOKAHEAD0_1_SW_WRITE_MASK                                0x00000000
#define RX_LOOKAHEAD0_1_RSTMASK                                      0xffffffff
#define RX_LOOKAHEAD0_1_RESET                                        0x00000000

// 0x0810 (RX_LOOKAHEAD1_0)
#define RX_LOOKAHEAD1_0_DATA_MSB                                     31
#define RX_LOOKAHEAD1_0_DATA_LSB                                     0
#define RX_LOOKAHEAD1_0_DATA_MASK                                    0xffffffff
#define RX_LOOKAHEAD1_0_DATA_GET(x)                                  (((x) & RX_LOOKAHEAD1_0_DATA_MASK) >> RX_LOOKAHEAD1_0_DATA_LSB)
#define RX_LOOKAHEAD1_0_DATA_SET(x)                                  (((0 | (x)) << RX_LOOKAHEAD1_0_DATA_LSB) & RX_LOOKAHEAD1_0_DATA_MASK)
#define RX_LOOKAHEAD1_0_DATA_RESET                                   0
#define RX_LOOKAHEAD1_0_ADDRESS                                      0x0810
#define RX_LOOKAHEAD1_ADDRESS                                        RX_LOOKAHEAD1_0_ADDRESS
#define RX_LOOKAHEAD1_0_HW_MASK                                      0xffffffff
#define RX_LOOKAHEAD1_0_SW_MASK                                      0xffffffff
#define RX_LOOKAHEAD1_0_HW_WRITE_MASK                                0xffffffff
#define RX_LOOKAHEAD1_0_SW_WRITE_MASK                                0x00000000
#define RX_LOOKAHEAD1_0_RSTMASK                                      0xffffffff
#define RX_LOOKAHEAD1_0_RESET                                        0x00000000

// 0x0814 (RX_LOOKAHEAD1_1)
#define RX_LOOKAHEAD1_1_DATA_MSB                                     31
#define RX_LOOKAHEAD1_1_DATA_LSB                                     0
#define RX_LOOKAHEAD1_1_DATA_MASK                                    0xffffffff
#define RX_LOOKAHEAD1_1_DATA_GET(x)                                  (((x) & RX_LOOKAHEAD1_1_DATA_MASK) >> RX_LOOKAHEAD1_1_DATA_LSB)
#define RX_LOOKAHEAD1_1_DATA_SET(x)                                  (((0 | (x)) << RX_LOOKAHEAD1_1_DATA_LSB) & RX_LOOKAHEAD1_1_DATA_MASK)
#define RX_LOOKAHEAD1_1_DATA_RESET                                   0
#define RX_LOOKAHEAD1_1_ADDRESS                                      0x0814
#define RX_LOOKAHEAD1_1_HW_MASK                                      0xffffffff
#define RX_LOOKAHEAD1_1_SW_MASK                                      0xffffffff
#define RX_LOOKAHEAD1_1_HW_WRITE_MASK                                0xffffffff
#define RX_LOOKAHEAD1_1_SW_WRITE_MASK                                0x00000000
#define RX_LOOKAHEAD1_1_RSTMASK                                      0xffffffff
#define RX_LOOKAHEAD1_1_RESET                                        0x00000000

// 0x0818 (RX_LOOKAHEAD2_0)
#define RX_LOOKAHEAD2_0_DATA_MSB                                     31
#define RX_LOOKAHEAD2_0_DATA_LSB                                     0
#define RX_LOOKAHEAD2_0_DATA_MASK                                    0xffffffff
#define RX_LOOKAHEAD2_0_DATA_GET(x)                                  (((x) & RX_LOOKAHEAD2_0_DATA_MASK) >> RX_LOOKAHEAD2_0_DATA_LSB)
#define RX_LOOKAHEAD2_0_DATA_SET(x)                                  (((0 | (x)) << RX_LOOKAHEAD2_0_DATA_LSB) & RX_LOOKAHEAD2_0_DATA_MASK)
#define RX_LOOKAHEAD2_0_DATA_RESET                                   0
#define RX_LOOKAHEAD2_0_ADDRESS                                      0x0818
#define RX_LOOKAHEAD2_ADDRESS                                        RX_LOOKAHEAD2_0_ADDRESS
#define RX_LOOKAHEAD2_0_HW_MASK                                      0xffffffff
#define RX_LOOKAHEAD2_0_SW_MASK                                      0xffffffff
#define RX_LOOKAHEAD2_0_HW_WRITE_MASK                                0xffffffff
#define RX_LOOKAHEAD2_0_SW_WRITE_MASK                                0x00000000
#define RX_LOOKAHEAD2_0_RSTMASK                                      0xffffffff
#define RX_LOOKAHEAD2_0_RESET                                        0x00000000

// 0x081c (RX_LOOKAHEAD2_1)
#define RX_LOOKAHEAD2_1_DATA_MSB                                     31
#define RX_LOOKAHEAD2_1_DATA_LSB                                     0
#define RX_LOOKAHEAD2_1_DATA_MASK                                    0xffffffff
#define RX_LOOKAHEAD2_1_DATA_GET(x)                                  (((x) & RX_LOOKAHEAD2_1_DATA_MASK) >> RX_LOOKAHEAD2_1_DATA_LSB)
#define RX_LOOKAHEAD2_1_DATA_SET(x)                                  (((0 | (x)) << RX_LOOKAHEAD2_1_DATA_LSB) & RX_LOOKAHEAD2_1_DATA_MASK)
#define RX_LOOKAHEAD2_1_DATA_RESET                                   0
#define RX_LOOKAHEAD2_1_ADDRESS                                      0x081c
#define RX_LOOKAHEAD2_1_HW_MASK                                      0xffffffff
#define RX_LOOKAHEAD2_1_SW_MASK                                      0xffffffff
#define RX_LOOKAHEAD2_1_HW_WRITE_MASK                                0xffffffff
#define RX_LOOKAHEAD2_1_SW_WRITE_MASK                                0x00000000
#define RX_LOOKAHEAD2_1_RSTMASK                                      0xffffffff
#define RX_LOOKAHEAD2_1_RESET                                        0x00000000

// 0x0820 (RX_LOOKAHEAD3_0)
#define RX_LOOKAHEAD3_0_DATA_MSB                                     31
#define RX_LOOKAHEAD3_0_DATA_LSB                                     0
#define RX_LOOKAHEAD3_0_DATA_MASK                                    0xffffffff
#define RX_LOOKAHEAD3_0_DATA_GET(x)                                  (((x) & RX_LOOKAHEAD3_0_DATA_MASK) >> RX_LOOKAHEAD3_0_DATA_LSB)
#define RX_LOOKAHEAD3_0_DATA_SET(x)                                  (((0 | (x)) << RX_LOOKAHEAD3_0_DATA_LSB) & RX_LOOKAHEAD3_0_DATA_MASK)
#define RX_LOOKAHEAD3_0_DATA_RESET                                   0
#define RX_LOOKAHEAD3_0_ADDRESS                                      0x0820
#define RX_LOOKAHEAD3_ADDRESS                                        RX_LOOKAHEAD3_0_ADDRESS
#define RX_LOOKAHEAD3_0_HW_MASK                                      0xffffffff
#define RX_LOOKAHEAD3_0_SW_MASK                                      0xffffffff
#define RX_LOOKAHEAD3_0_HW_WRITE_MASK                                0xffffffff
#define RX_LOOKAHEAD3_0_SW_WRITE_MASK                                0x00000000
#define RX_LOOKAHEAD3_0_RSTMASK                                      0xffffffff
#define RX_LOOKAHEAD3_0_RESET                                        0x00000000

// 0x0824 (RX_LOOKAHEAD3_1)
#define RX_LOOKAHEAD3_1_DATA_MSB                                     31
#define RX_LOOKAHEAD3_1_DATA_LSB                                     0
#define RX_LOOKAHEAD3_1_DATA_MASK                                    0xffffffff
#define RX_LOOKAHEAD3_1_DATA_GET(x)                                  (((x) & RX_LOOKAHEAD3_1_DATA_MASK) >> RX_LOOKAHEAD3_1_DATA_LSB)
#define RX_LOOKAHEAD3_1_DATA_SET(x)                                  (((0 | (x)) << RX_LOOKAHEAD3_1_DATA_LSB) & RX_LOOKAHEAD3_1_DATA_MASK)
#define RX_LOOKAHEAD3_1_DATA_RESET                                   0
#define RX_LOOKAHEAD3_1_ADDRESS                                      0x0824
#define RX_LOOKAHEAD3_1_HW_MASK                                      0xffffffff
#define RX_LOOKAHEAD3_1_SW_MASK                                      0xffffffff
#define RX_LOOKAHEAD3_1_HW_WRITE_MASK                                0xffffffff
#define RX_LOOKAHEAD3_1_SW_WRITE_MASK                                0x00000000
#define RX_LOOKAHEAD3_1_RSTMASK                                      0xffffffff
#define RX_LOOKAHEAD3_1_RESET                                        0x00000000

// 0x0828 (INT_STATUS_ENABLE)
#define INT_STATUS_ENABLE_COUNTER_INT_STATUS_ENABLE_MSB              31
#define INT_STATUS_ENABLE_COUNTER_INT_STATUS_ENABLE_LSB              24
#define INT_STATUS_ENABLE_COUNTER_INT_STATUS_ENABLE_MASK             0xff000000
#define INT_STATUS_ENABLE_COUNTER_INT_STATUS_ENABLE_GET(x)           (((x) & INT_STATUS_ENABLE_COUNTER_INT_STATUS_ENABLE_MASK) >> INT_STATUS_ENABLE_COUNTER_INT_STATUS_ENABLE_LSB)
#define INT_STATUS_ENABLE_COUNTER_INT_STATUS_ENABLE_SET(x)           (((0 | (x)) << INT_STATUS_ENABLE_COUNTER_INT_STATUS_ENABLE_LSB) & INT_STATUS_ENABLE_COUNTER_INT_STATUS_ENABLE_MASK)
#define INT_STATUS_ENABLE_COUNTER_INT_STATUS_ENABLE_RESET            255
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_SYNC_ERROR_MSB             21
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_SYNC_ERROR_LSB             21
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_SYNC_ERROR_MASK            0x00200000
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_SYNC_ERROR_GET(x)          (((x) & INT_STATUS_ENABLE_UART_HCI_FRAMER_SYNC_ERROR_MASK) >> INT_STATUS_ENABLE_UART_HCI_FRAMER_SYNC_ERROR_LSB)
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_SYNC_ERROR_SET(x)          (((0 | (x)) << INT_STATUS_ENABLE_UART_HCI_FRAMER_SYNC_ERROR_LSB) & INT_STATUS_ENABLE_UART_HCI_FRAMER_SYNC_ERROR_MASK)
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_SYNC_ERROR_RESET           0
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_OVERFLOW_MSB               20
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_OVERFLOW_LSB               20
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_OVERFLOW_MASK              0x00100000
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_OVERFLOW_GET(x)            (((x) & INT_STATUS_ENABLE_UART_HCI_FRAMER_OVERFLOW_MASK) >> INT_STATUS_ENABLE_UART_HCI_FRAMER_OVERFLOW_LSB)
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_OVERFLOW_SET(x)            (((0 | (x)) << INT_STATUS_ENABLE_UART_HCI_FRAMER_OVERFLOW_LSB) & INT_STATUS_ENABLE_UART_HCI_FRAMER_OVERFLOW_MASK)
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_OVERFLOW_RESET             0
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_UNDERFLOW_MSB              19
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_UNDERFLOW_LSB              19
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_UNDERFLOW_MASK             0x00080000
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_UNDERFLOW_GET(x)           (((x) & INT_STATUS_ENABLE_UART_HCI_FRAMER_UNDERFLOW_MASK) >> INT_STATUS_ENABLE_UART_HCI_FRAMER_UNDERFLOW_LSB)
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_UNDERFLOW_SET(x)           (((0 | (x)) << INT_STATUS_ENABLE_UART_HCI_FRAMER_UNDERFLOW_LSB) & INT_STATUS_ENABLE_UART_HCI_FRAMER_UNDERFLOW_MASK)
#define INT_STATUS_ENABLE_UART_HCI_FRAMER_UNDERFLOW_RESET            0
#define INT_STATUS_ENABLE_WAKEUP_MSB                                 18
#define INT_STATUS_ENABLE_WAKEUP_LSB                                 18
#define INT_STATUS_ENABLE_WAKEUP_MASK                                0x00040000
#define INT_STATUS_ENABLE_WAKEUP_GET(x)                              (((x) & INT_STATUS_ENABLE_WAKEUP_MASK) >> INT_STATUS_ENABLE_WAKEUP_LSB)
#define INT_STATUS_ENABLE_WAKEUP_SET(x)                              (((0 | (x)) << INT_STATUS_ENABLE_WAKEUP_LSB) & INT_STATUS_ENABLE_WAKEUP_MASK)
#define INT_STATUS_ENABLE_WAKEUP_RESET                               0
#define INT_STATUS_ENABLE_RX_UNDERFLOW_MSB                           17
#define INT_STATUS_ENABLE_RX_UNDERFLOW_LSB                           17
#define INT_STATUS_ENABLE_RX_UNDERFLOW_MASK                          0x00020000
#define INT_STATUS_ENABLE_RX_UNDERFLOW_GET(x)                        (((x) & INT_STATUS_ENABLE_RX_UNDERFLOW_MASK) >> INT_STATUS_ENABLE_RX_UNDERFLOW_LSB)
#define INT_STATUS_ENABLE_RX_UNDERFLOW_SET(x)                        (((0 | (x)) << INT_STATUS_ENABLE_RX_UNDERFLOW_LSB) & INT_STATUS_ENABLE_RX_UNDERFLOW_MASK)
#define INT_STATUS_ENABLE_RX_UNDERFLOW_RESET                         0
#define INT_STATUS_ENABLE_TX_OVERFLOW_MSB                            16
#define INT_STATUS_ENABLE_TX_OVERFLOW_LSB                            16
#define INT_STATUS_ENABLE_TX_OVERFLOW_MASK                           0x00010000
#define INT_STATUS_ENABLE_TX_OVERFLOW_GET(x)                         (((x) & INT_STATUS_ENABLE_TX_OVERFLOW_MASK) >> INT_STATUS_ENABLE_TX_OVERFLOW_LSB)
#define INT_STATUS_ENABLE_TX_OVERFLOW_SET(x)                         (((0 | (x)) << INT_STATUS_ENABLE_TX_OVERFLOW_LSB) & INT_STATUS_ENABLE_TX_OVERFLOW_MASK)
#define INT_STATUS_ENABLE_TX_OVERFLOW_RESET                          0
#define INT_STATUS_ENABLE_CPU_INT_STATUS_ENABLE_MSB                  15
#define INT_STATUS_ENABLE_CPU_INT_STATUS_ENABLE_LSB                  8
#define INT_STATUS_ENABLE_CPU_INT_STATUS_ENABLE_MASK                 0x0000ff00
#define INT_STATUS_ENABLE_CPU_INT_STATUS_ENABLE_GET(x)               (((x) & INT_STATUS_ENABLE_CPU_INT_STATUS_ENABLE_MASK) >> INT_STATUS_ENABLE_CPU_INT_STATUS_ENABLE_LSB)
#define INT_STATUS_ENABLE_CPU_INT_STATUS_ENABLE_SET(x)               (((0 | (x)) << INT_STATUS_ENABLE_CPU_INT_STATUS_ENABLE_LSB) & INT_STATUS_ENABLE_CPU_INT_STATUS_ENABLE_MASK)
#define INT_STATUS_ENABLE_CPU_INT_STATUS_ENABLE_RESET                255
#define INT_STATUS_ENABLE_ERROR_MSB                                  7
#define INT_STATUS_ENABLE_ERROR_LSB                                  7
#define INT_STATUS_ENABLE_ERROR_MASK                                 0x00000080
#define INT_STATUS_ENABLE_ERROR_GET(x)                               (((x) & INT_STATUS_ENABLE_ERROR_MASK) >> INT_STATUS_ENABLE_ERROR_LSB)
#define INT_STATUS_ENABLE_ERROR_SET(x)                               (((0 | (x)) << INT_STATUS_ENABLE_ERROR_LSB) & INT_STATUS_ENABLE_ERROR_MASK)
#define INT_STATUS_ENABLE_ERROR_RESET                                1
#define INT_STATUS_ENABLE_CPU_MSB                                    6
#define INT_STATUS_ENABLE_CPU_LSB                                    6
#define INT_STATUS_ENABLE_CPU_MASK                                   0x00000040
#define INT_STATUS_ENABLE_CPU_GET(x)                                 (((x) & INT_STATUS_ENABLE_CPU_MASK) >> INT_STATUS_ENABLE_CPU_LSB)
#define INT_STATUS_ENABLE_CPU_SET(x)                                 (((0 | (x)) << INT_STATUS_ENABLE_CPU_LSB) & INT_STATUS_ENABLE_CPU_MASK)
#define INT_STATUS_ENABLE_CPU_RESET                                  1
#define INT_STATUS_ENABLE_INT_MSB                                    5
#define INT_STATUS_ENABLE_INT_LSB                                    5
#define INT_STATUS_ENABLE_INT_MASK                                   0x00000020
#define INT_STATUS_ENABLE_INT_GET(x)                                 (((x) & INT_STATUS_ENABLE_INT_MASK) >> INT_STATUS_ENABLE_INT_LSB)
#define INT_STATUS_ENABLE_INT_SET(x)                                 (((0 | (x)) << INT_STATUS_ENABLE_INT_LSB) & INT_STATUS_ENABLE_INT_MASK)
#define INT_STATUS_ENABLE_INT_RESET                                  0
#define INT_STATUS_ENABLE_COUNTER_MSB                                4
#define INT_STATUS_ENABLE_COUNTER_LSB                                4
#define INT_STATUS_ENABLE_COUNTER_MASK                               0x00000010
#define INT_STATUS_ENABLE_COUNTER_GET(x)                             (((x) & INT_STATUS_ENABLE_COUNTER_MASK) >> INT_STATUS_ENABLE_COUNTER_LSB)
#define INT_STATUS_ENABLE_COUNTER_SET(x)                             (((0 | (x)) << INT_STATUS_ENABLE_COUNTER_LSB) & INT_STATUS_ENABLE_COUNTER_MASK)
#define INT_STATUS_ENABLE_COUNTER_RESET                              0
#define INT_STATUS_ENABLE_MBOX_DATA_MSB                              3
#define INT_STATUS_ENABLE_MBOX_DATA_LSB                              0
#define INT_STATUS_ENABLE_MBOX_DATA_MASK                             0x0000000f
#define INT_STATUS_ENABLE_MBOX_DATA_GET(x)                           (((x) & INT_STATUS_ENABLE_MBOX_DATA_MASK) >> INT_STATUS_ENABLE_MBOX_DATA_LSB)
#define INT_STATUS_ENABLE_MBOX_DATA_SET(x)                           (((0 | (x)) << INT_STATUS_ENABLE_MBOX_DATA_LSB) & INT_STATUS_ENABLE_MBOX_DATA_MASK)
#define INT_STATUS_ENABLE_MBOX_DATA_RESET                            15
#define INT_STATUS_ENABLE_ADDRESS                                    0x0828
#define INT_STATUS_ENABLE_HW_MASK                                    0xff3fffff
#define INT_STATUS_ENABLE_SW_MASK                                    0xff3fffff
#define INT_STATUS_ENABLE_HW_WRITE_MASK                              0x00000000
#define INT_STATUS_ENABLE_SW_WRITE_MASK                              0xff3fffff
#define INT_STATUS_ENABLE_RSTMASK                                    0xffffffff
#define INT_STATUS_ENABLE_RESET                                      0xff00ffcf

// 0x0830 (COUNT_0)
#define COUNT_0_VALUE_MSB                                            31
#define COUNT_0_VALUE_LSB                                            0
#define COUNT_0_VALUE_MASK                                           0xffffffff
#define COUNT_0_VALUE_GET(x)                                         (((x) & COUNT_0_VALUE_MASK) >> COUNT_0_VALUE_LSB)
#define COUNT_0_VALUE_SET(x)                                         (((0 | (x)) << COUNT_0_VALUE_LSB) & COUNT_0_VALUE_MASK)
#define COUNT_0_VALUE_RESET                                          0
#define COUNT_0_ADDRESS                                              0x0830
#define COUNT_ADDRESS                                                COUNT_0_ADDRESS
#define COUNT_0_HW_MASK                                              0xffffffff
#define COUNT_0_SW_MASK                                              0xffffffff
#define COUNT_0_HW_WRITE_MASK                                        0xffffffff
#define COUNT_0_SW_WRITE_MASK                                        0xffffffff
#define COUNT_0_RSTMASK                                              0xffffffff
#define COUNT_0_RESET                                                0x00000000

// 0x0834 (COUNT_1)
#define COUNT_1_VALUE_MSB                                            31
#define COUNT_1_VALUE_LSB                                            0
#define COUNT_1_VALUE_MASK                                           0xffffffff
#define COUNT_1_VALUE_GET(x)                                         (((x) & COUNT_1_VALUE_MASK) >> COUNT_1_VALUE_LSB)
#define COUNT_1_VALUE_SET(x)                                         (((0 | (x)) << COUNT_1_VALUE_LSB) & COUNT_1_VALUE_MASK)
#define COUNT_1_VALUE_RESET                                          0
#define COUNT_1_ADDRESS                                              0x0834
#define COUNT_1_HW_MASK                                              0xffffffff
#define COUNT_1_SW_MASK                                              0xffffffff
#define COUNT_1_HW_WRITE_MASK                                        0xffffffff
#define COUNT_1_SW_WRITE_MASK                                        0xffffffff
#define COUNT_1_RSTMASK                                              0xffffffff
#define COUNT_1_RESET                                                0x00000000

// 0x0840 (COUNT_DEC_0)
#define COUNT_DEC_0_VALUE_MSB                                        31
#define COUNT_DEC_0_VALUE_LSB                                        0
#define COUNT_DEC_0_VALUE_MASK                                       0xffffffff
#define COUNT_DEC_0_VALUE_GET(x)                                     (((x) & COUNT_DEC_0_VALUE_MASK) >> COUNT_DEC_0_VALUE_LSB)
#define COUNT_DEC_0_VALUE_SET(x)                                     (((0 | (x)) << COUNT_DEC_0_VALUE_LSB) & COUNT_DEC_0_VALUE_MASK)
#define COUNT_DEC_0_VALUE_RESET                                      0
#define COUNT_DEC_0_ADDRESS                                          0x0840
#define COUNT_DEC_ADDRESS                                            COUNT_DEC_0_ADDRESS
#define COUNT_DEC_0_HW_MASK                                          0xffffffff
#define COUNT_DEC_0_SW_MASK                                          0xffffffff
#define COUNT_DEC_0_HW_WRITE_MASK                                    0xffffffff
#define COUNT_DEC_0_SW_WRITE_MASK                                    0xffffffff
#define COUNT_DEC_0_RSTMASK                                          0xffffffff
#define COUNT_DEC_0_RESET                                            0x00000000

// 0x0844 (COUNT_DEC_1)
#define COUNT_DEC_1_VALUE_MSB                                        31
#define COUNT_DEC_1_VALUE_LSB                                        0
#define COUNT_DEC_1_VALUE_MASK                                       0xffffffff
#define COUNT_DEC_1_VALUE_GET(x)                                     (((x) & COUNT_DEC_1_VALUE_MASK) >> COUNT_DEC_1_VALUE_LSB)
#define COUNT_DEC_1_VALUE_SET(x)                                     (((0 | (x)) << COUNT_DEC_1_VALUE_LSB) & COUNT_DEC_1_VALUE_MASK)
#define COUNT_DEC_1_VALUE_RESET                                      0
#define COUNT_DEC_1_ADDRESS                                          0x0844
#define COUNT_DEC_1_HW_MASK                                          0xffffffff
#define COUNT_DEC_1_SW_MASK                                          0xffffffff
#define COUNT_DEC_1_HW_WRITE_MASK                                    0xffffffff
#define COUNT_DEC_1_SW_WRITE_MASK                                    0xffffffff
#define COUNT_DEC_1_RSTMASK                                          0xffffffff
#define COUNT_DEC_1_RESET                                            0x00000000

// 0x0848 (COUNT_DEC_2)
#define COUNT_DEC_2_VALUE_MSB                                        31
#define COUNT_DEC_2_VALUE_LSB                                        0
#define COUNT_DEC_2_VALUE_MASK                                       0xffffffff
#define COUNT_DEC_2_VALUE_GET(x)                                     (((x) & COUNT_DEC_2_VALUE_MASK) >> COUNT_DEC_2_VALUE_LSB)
#define COUNT_DEC_2_VALUE_SET(x)                                     (((0 | (x)) << COUNT_DEC_2_VALUE_LSB) & COUNT_DEC_2_VALUE_MASK)
#define COUNT_DEC_2_VALUE_RESET                                      0
#define COUNT_DEC_2_ADDRESS                                          0x0848
#define COUNT_DEC_2_HW_MASK                                          0xffffffff
#define COUNT_DEC_2_SW_MASK                                          0xffffffff
#define COUNT_DEC_2_HW_WRITE_MASK                                    0xffffffff
#define COUNT_DEC_2_SW_WRITE_MASK                                    0xffffffff
#define COUNT_DEC_2_RSTMASK                                          0xffffffff
#define COUNT_DEC_2_RESET                                            0x00000000

// 0x084c (COUNT_DEC_3)
#define COUNT_DEC_3_VALUE_MSB                                        31
#define COUNT_DEC_3_VALUE_LSB                                        0
#define COUNT_DEC_3_VALUE_MASK                                       0xffffffff
#define COUNT_DEC_3_VALUE_GET(x)                                     (((x) & COUNT_DEC_3_VALUE_MASK) >> COUNT_DEC_3_VALUE_LSB)
#define COUNT_DEC_3_VALUE_SET(x)                                     (((0 | (x)) << COUNT_DEC_3_VALUE_LSB) & COUNT_DEC_3_VALUE_MASK)
#define COUNT_DEC_3_VALUE_RESET                                      0
#define COUNT_DEC_3_ADDRESS                                          0x084c
#define COUNT_DEC_3_HW_MASK                                          0xffffffff
#define COUNT_DEC_3_SW_MASK                                          0xffffffff
#define COUNT_DEC_3_HW_WRITE_MASK                                    0xffffffff
#define COUNT_DEC_3_SW_WRITE_MASK                                    0xffffffff
#define COUNT_DEC_3_RSTMASK                                          0xffffffff
#define COUNT_DEC_3_RESET                                            0x00000000

// 0x0850 (COUNT_DEC_4)
#define COUNT_DEC_4_VALUE_MSB                                        31
#define COUNT_DEC_4_VALUE_LSB                                        0
#define COUNT_DEC_4_VALUE_MASK                                       0xffffffff
#define COUNT_DEC_4_VALUE_GET(x)                                     (((x) & COUNT_DEC_4_VALUE_MASK) >> COUNT_DEC_4_VALUE_LSB)
#define COUNT_DEC_4_VALUE_SET(x)                                     (((0 | (x)) << COUNT_DEC_4_VALUE_LSB) & COUNT_DEC_4_VALUE_MASK)
#define COUNT_DEC_4_VALUE_RESET                                      0
#define COUNT_DEC_4_ADDRESS                                          0x0850
#define COUNT_DEC_4_HW_MASK                                          0xffffffff
#define COUNT_DEC_4_SW_MASK                                          0xffffffff
#define COUNT_DEC_4_HW_WRITE_MASK                                    0xffffffff
#define COUNT_DEC_4_SW_WRITE_MASK                                    0xffffffff
#define COUNT_DEC_4_RSTMASK                                          0xffffffff
#define COUNT_DEC_4_RESET                                            0x00000000

// 0x0854 (COUNT_DEC_5)
#define COUNT_DEC_5_VALUE_MSB                                        31
#define COUNT_DEC_5_VALUE_LSB                                        0
#define COUNT_DEC_5_VALUE_MASK                                       0xffffffff
#define COUNT_DEC_5_VALUE_GET(x)                                     (((x) & COUNT_DEC_5_VALUE_MASK) >> COUNT_DEC_5_VALUE_LSB)
#define COUNT_DEC_5_VALUE_SET(x)                                     (((0 | (x)) << COUNT_DEC_5_VALUE_LSB) & COUNT_DEC_5_VALUE_MASK)
#define COUNT_DEC_5_VALUE_RESET                                      0
#define COUNT_DEC_5_ADDRESS                                          0x0854
#define COUNT_DEC_5_HW_MASK                                          0xffffffff
#define COUNT_DEC_5_SW_MASK                                          0xffffffff
#define COUNT_DEC_5_HW_WRITE_MASK                                    0xffffffff
#define COUNT_DEC_5_SW_WRITE_MASK                                    0xffffffff
#define COUNT_DEC_5_RSTMASK                                          0xffffffff
#define COUNT_DEC_5_RESET                                            0x00000000

// 0x0858 (COUNT_DEC_6)
#define COUNT_DEC_6_VALUE_MSB                                        31
#define COUNT_DEC_6_VALUE_LSB                                        0
#define COUNT_DEC_6_VALUE_MASK                                       0xffffffff
#define COUNT_DEC_6_VALUE_GET(x)                                     (((x) & COUNT_DEC_6_VALUE_MASK) >> COUNT_DEC_6_VALUE_LSB)
#define COUNT_DEC_6_VALUE_SET(x)                                     (((0 | (x)) << COUNT_DEC_6_VALUE_LSB) & COUNT_DEC_6_VALUE_MASK)
#define COUNT_DEC_6_VALUE_RESET                                      0
#define COUNT_DEC_6_ADDRESS                                          0x0858
#define COUNT_DEC_6_HW_MASK                                          0xffffffff
#define COUNT_DEC_6_SW_MASK                                          0xffffffff
#define COUNT_DEC_6_HW_WRITE_MASK                                    0xffffffff
#define COUNT_DEC_6_SW_WRITE_MASK                                    0xffffffff
#define COUNT_DEC_6_RSTMASK                                          0xffffffff
#define COUNT_DEC_6_RESET                                            0x00000000

// 0x085c (COUNT_DEC_7)
#define COUNT_DEC_7_VALUE_MSB                                        31
#define COUNT_DEC_7_VALUE_LSB                                        0
#define COUNT_DEC_7_VALUE_MASK                                       0xffffffff
#define COUNT_DEC_7_VALUE_GET(x)                                     (((x) & COUNT_DEC_7_VALUE_MASK) >> COUNT_DEC_7_VALUE_LSB)
#define COUNT_DEC_7_VALUE_SET(x)                                     (((0 | (x)) << COUNT_DEC_7_VALUE_LSB) & COUNT_DEC_7_VALUE_MASK)
#define COUNT_DEC_7_VALUE_RESET                                      0
#define COUNT_DEC_7_ADDRESS                                          0x085c
#define COUNT_DEC_7_HW_MASK                                          0xffffffff
#define COUNT_DEC_7_SW_MASK                                          0xffffffff
#define COUNT_DEC_7_HW_WRITE_MASK                                    0xffffffff
#define COUNT_DEC_7_SW_WRITE_MASK                                    0xffffffff
#define COUNT_DEC_7_RSTMASK                                          0xffffffff
#define COUNT_DEC_7_RESET                                            0x00000000

// 0x0860 (SCRATCH_0)
#define SCRATCH_0_VALUE_MSB                                          31
#define SCRATCH_0_VALUE_LSB                                          0
#define SCRATCH_0_VALUE_MASK                                         0xffffffff
#define SCRATCH_0_VALUE_GET(x)                                       (((x) & SCRATCH_0_VALUE_MASK) >> SCRATCH_0_VALUE_LSB)
#define SCRATCH_0_VALUE_SET(x)                                       (((0 | (x)) << SCRATCH_0_VALUE_LSB) & SCRATCH_0_VALUE_MASK)
#define SCRATCH_0_VALUE_RESET                                        0
#define SCRATCH_0_ADDRESS                                            0x0860
#define SCRATCH_ADDRESS                                              SCRATCH_0_ADDRESS
#define SCRATCH_0_HW_MASK                                            0xffffffff
#define SCRATCH_0_SW_MASK                                            0xffffffff
#define SCRATCH_0_HW_WRITE_MASK                                      0xffffffff
#define SCRATCH_0_SW_WRITE_MASK                                      0xffffffff
#define SCRATCH_0_RSTMASK                                            0xffffffff
#define SCRATCH_0_RESET                                              0x00000000

// 0x0864 (SCRATCH_1)
#define SCRATCH_1_VALUE_MSB                                          31
#define SCRATCH_1_VALUE_LSB                                          0
#define SCRATCH_1_VALUE_MASK                                         0xffffffff
#define SCRATCH_1_VALUE_GET(x)                                       (((x) & SCRATCH_1_VALUE_MASK) >> SCRATCH_1_VALUE_LSB)
#define SCRATCH_1_VALUE_SET(x)                                       (((0 | (x)) << SCRATCH_1_VALUE_LSB) & SCRATCH_1_VALUE_MASK)
#define SCRATCH_1_VALUE_RESET                                        0
#define SCRATCH_1_ADDRESS                                            0x0864
#define SCRATCH_1_HW_MASK                                            0xffffffff
#define SCRATCH_1_SW_MASK                                            0xffffffff
#define SCRATCH_1_HW_WRITE_MASK                                      0xffffffff
#define SCRATCH_1_SW_WRITE_MASK                                      0xffffffff
#define SCRATCH_1_RSTMASK                                            0xffffffff
#define SCRATCH_1_RESET                                              0x00000000

// 0x0868 (FIFO_TIMEOUT_AND_CHIP_CONTROL)
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_FOR_INT_MSB      17
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_FOR_INT_LSB      17
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_FOR_INT_MASK     0x00020000
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_FOR_INT_GET(x)   (((x) & FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_FOR_INT_MASK) >> FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_FOR_INT_LSB)
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_FOR_INT_SET(x)   (((0 | (x)) << FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_FOR_INT_LSB) & FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_FOR_INT_MASK)
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_FOR_INT_RESET    0
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_ON_MSB           16
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_ON_LSB           16
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_ON_MASK          0x00010000
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_ON_GET(x)        (((x) & FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_ON_MASK) >> FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_ON_LSB)
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_ON_SET(x)        (((0 | (x)) << FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_ON_LSB) & FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_ON_MASK)
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_DISABLE_SLEEP_ON_RESET         0
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_ENABLE_MSB        8
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_ENABLE_LSB        8
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_ENABLE_MASK       0x00000100
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_ENABLE_GET(x)     (((x) & FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_ENABLE_MASK) >> FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_ENABLE_LSB)
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_ENABLE_SET(x)     (((0 | (x)) << FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_ENABLE_LSB) & FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_ENABLE_MASK)
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_ENABLE_RESET      1
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_VALUE_MSB         7
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_VALUE_LSB         0
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_VALUE_MASK        0x000000ff
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_VALUE_GET(x)      (((x) & FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_VALUE_MASK) >> FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_VALUE_LSB)
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_VALUE_SET(x)      (((0 | (x)) << FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_VALUE_LSB) & FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_VALUE_MASK)
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_FIFO_TIMEOUT_VALUE_RESET       255
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_ADDRESS                        0x0868
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_HW_MASK                        0x000301ff
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_SW_MASK                        0x000301ff
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_HW_WRITE_MASK                  0x00000000
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_SW_WRITE_MASK                  0x000301ff
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_RSTMASK                        0xffffffff
#define FIFO_TIMEOUT_AND_CHIP_CONTROL_RESET                          0x000001ff

// 0x0870 (LOCAL_BUS_AND_INT_WLAN)
#define LOCAL_BUS_AND_INT_WLAN_INT_WLAN_VECTOR_MSB                   23
#define LOCAL_BUS_AND_INT_WLAN_INT_WLAN_VECTOR_LSB                   16
#define LOCAL_BUS_AND_INT_WLAN_INT_WLAN_VECTOR_MASK                  0x00ff0000
#define LOCAL_BUS_AND_INT_WLAN_INT_WLAN_VECTOR_GET(x)                (((x) & LOCAL_BUS_AND_INT_WLAN_INT_WLAN_VECTOR_MASK) >> LOCAL_BUS_AND_INT_WLAN_INT_WLAN_VECTOR_LSB)
#define LOCAL_BUS_AND_INT_WLAN_INT_WLAN_VECTOR_SET(x)                (((0 | (x)) << LOCAL_BUS_AND_INT_WLAN_INT_WLAN_VECTOR_LSB) & LOCAL_BUS_AND_INT_WLAN_INT_WLAN_VECTOR_MASK)
#define LOCAL_BUS_AND_INT_WLAN_INT_WLAN_VECTOR_RESET                 0
#define LOCAL_BUS_AND_INT_WLAN_LOCAL_BUS_STATE_MSB                   1
#define LOCAL_BUS_AND_INT_WLAN_LOCAL_BUS_STATE_LSB                   0
#define LOCAL_BUS_AND_INT_WLAN_LOCAL_BUS_STATE_MASK                  0x00000003
#define LOCAL_BUS_AND_INT_WLAN_LOCAL_BUS_STATE_GET(x)                (((x) & LOCAL_BUS_AND_INT_WLAN_LOCAL_BUS_STATE_MASK) >> LOCAL_BUS_AND_INT_WLAN_LOCAL_BUS_STATE_LSB)
#define LOCAL_BUS_AND_INT_WLAN_LOCAL_BUS_STATE_SET(x)                (((0 | (x)) << LOCAL_BUS_AND_INT_WLAN_LOCAL_BUS_STATE_LSB) & LOCAL_BUS_AND_INT_WLAN_LOCAL_BUS_STATE_MASK)
#define LOCAL_BUS_AND_INT_WLAN_LOCAL_BUS_STATE_RESET                 0
#define LOCAL_BUS_AND_INT_WLAN_ADDRESS                               0x0870
#define LOCAL_BUS_AND_INT_WLAN_HW_MASK                               0x00ff0003
#define LOCAL_BUS_AND_INT_WLAN_SW_MASK                               0x00ff0003
#define LOCAL_BUS_AND_INT_WLAN_HW_WRITE_MASK                         0x00ff0003
#define LOCAL_BUS_AND_INT_WLAN_SW_WRITE_MASK                         0x00ff0000
#define LOCAL_BUS_AND_INT_WLAN_RSTMASK                               0xffffffff
#define LOCAL_BUS_AND_INT_WLAN_RESET                                 0x00000000

// 0x0874 (WINDOW_DATA)
#define WINDOW_DATA_DATA_MSB                                         31
#define WINDOW_DATA_DATA_LSB                                         0
#define WINDOW_DATA_DATA_MASK                                        0xffffffff
#define WINDOW_DATA_DATA_GET(x)                                      (((x) & WINDOW_DATA_DATA_MASK) >> WINDOW_DATA_DATA_LSB)
#define WINDOW_DATA_DATA_SET(x)                                      (((0 | (x)) << WINDOW_DATA_DATA_LSB) & WINDOW_DATA_DATA_MASK)
#define WINDOW_DATA_DATA_RESET                                       0
#define WINDOW_DATA_ADDRESS                                          0x0874
#define WINDOW_DATA_HW_MASK                                          0xffffffff
#define WINDOW_DATA_SW_MASK                                          0xffffffff
#define WINDOW_DATA_HW_WRITE_MASK                                    0xffffffff
#define WINDOW_DATA_SW_WRITE_MASK                                    0xffffffff
#define WINDOW_DATA_RSTMASK                                          0xffffffff
#define WINDOW_DATA_RESET                                            0x00000000

// 0x0878 (WINDOW_WRITE_ADDR)
#define WINDOW_WRITE_ADDR_ADDR_MSB                                   31
#define WINDOW_WRITE_ADDR_ADDR_LSB                                   0
#define WINDOW_WRITE_ADDR_ADDR_MASK                                  0xffffffff
#define WINDOW_WRITE_ADDR_ADDR_GET(x)                                (((x) & WINDOW_WRITE_ADDR_ADDR_MASK) >> WINDOW_WRITE_ADDR_ADDR_LSB)
#define WINDOW_WRITE_ADDR_ADDR_SET(x)                                (((0 | (x)) << WINDOW_WRITE_ADDR_ADDR_LSB) & WINDOW_WRITE_ADDR_ADDR_MASK)
#define WINDOW_WRITE_ADDR_ADDR_RESET                                 0
#define WINDOW_WRITE_ADDR_ADDRESS                                    0x0878
#define WINDOW_WRITE_ADDR_HW_MASK                                    0xffffffff
#define WINDOW_WRITE_ADDR_SW_MASK                                    0xffffffff
#define WINDOW_WRITE_ADDR_HW_WRITE_MASK                              0x00000000
#define WINDOW_WRITE_ADDR_SW_WRITE_MASK                              0xffffffff
#define WINDOW_WRITE_ADDR_RSTMASK                                    0xffffffff
#define WINDOW_WRITE_ADDR_RESET                                      0x00000000

// 0x087c (WINDOW_READ_ADDR)
#define WINDOW_READ_ADDR_ADDR_MSB                                    31
#define WINDOW_READ_ADDR_ADDR_LSB                                    0
#define WINDOW_READ_ADDR_ADDR_MASK                                   0xffffffff
#define WINDOW_READ_ADDR_ADDR_GET(x)                                 (((x) & WINDOW_READ_ADDR_ADDR_MASK) >> WINDOW_READ_ADDR_ADDR_LSB)
#define WINDOW_READ_ADDR_ADDR_SET(x)                                 (((0 | (x)) << WINDOW_READ_ADDR_ADDR_LSB) & WINDOW_READ_ADDR_ADDR_MASK)
#define WINDOW_READ_ADDR_ADDR_RESET                                  0
#define WINDOW_READ_ADDR_ADDRESS                                     0x087c
#define WINDOW_READ_ADDR_HW_MASK                                     0xffffffff
#define WINDOW_READ_ADDR_SW_MASK                                     0xffffffff
#define WINDOW_READ_ADDR_HW_WRITE_MASK                               0x00000000
#define WINDOW_READ_ADDR_SW_WRITE_MASK                               0xffffffff
#define WINDOW_READ_ADDR_RSTMASK                                     0xffffffff
#define WINDOW_READ_ADDR_RESET                                       0x00000000

// 0x0880 (NON_ASSOC_SLEEP_EN)
#define NON_ASSOC_SLEEP_EN_BIT_MSB                                   0
#define NON_ASSOC_SLEEP_EN_BIT_LSB                                   0
#define NON_ASSOC_SLEEP_EN_BIT_MASK                                  0x00000001
#define NON_ASSOC_SLEEP_EN_BIT_GET(x)                                (((x) & NON_ASSOC_SLEEP_EN_BIT_MASK) >> NON_ASSOC_SLEEP_EN_BIT_LSB)
#define NON_ASSOC_SLEEP_EN_BIT_SET(x)                                (((0 | (x)) << NON_ASSOC_SLEEP_EN_BIT_LSB) & NON_ASSOC_SLEEP_EN_BIT_MASK)
#define NON_ASSOC_SLEEP_EN_BIT_RESET                                 0
#define NON_ASSOC_SLEEP_EN_ADDRESS                                   0x0880
#define NON_ASSOC_SLEEP_EN_HW_MASK                                   0x00000001
#define NON_ASSOC_SLEEP_EN_SW_MASK                                   0x00000001
#define NON_ASSOC_SLEEP_EN_HW_WRITE_MASK                             0x00000000
#define NON_ASSOC_SLEEP_EN_SW_WRITE_MASK                             0x00000001
#define NON_ASSOC_SLEEP_EN_RSTMASK                                   0xffffffff
#define NON_ASSOC_SLEEP_EN_RESET                                     0x00000000

// 0x0884 (CPU_DBG_SEL)
#define CPU_DBG_SEL_BIT_MSB                                          5
#define CPU_DBG_SEL_BIT_LSB                                          0
#define CPU_DBG_SEL_BIT_MASK                                         0x0000003f
#define CPU_DBG_SEL_BIT_GET(x)                                       (((x) & CPU_DBG_SEL_BIT_MASK) >> CPU_DBG_SEL_BIT_LSB)
#define CPU_DBG_SEL_BIT_SET(x)                                       (((0 | (x)) << CPU_DBG_SEL_BIT_LSB) & CPU_DBG_SEL_BIT_MASK)
#define CPU_DBG_SEL_BIT_RESET                                        0
#define CPU_DBG_SEL_ADDRESS                                          0x0884
#define CPU_DBG_SEL_HW_MASK                                          0x0000003f
#define CPU_DBG_SEL_SW_MASK                                          0x0000003f
#define CPU_DBG_SEL_HW_WRITE_MASK                                    0x00000000
#define CPU_DBG_SEL_SW_WRITE_MASK                                    0x0000003f
#define CPU_DBG_SEL_RSTMASK                                          0xffffffff
#define CPU_DBG_SEL_RESET                                            0x00000000

// 0x0888 (GMBOX)
#define GMBOX_GMBOX_RX_LOOKAHEAD_MUX_SEL_MSB                         8
#define GMBOX_GMBOX_RX_LOOKAHEAD_MUX_SEL_LSB                         8
#define GMBOX_GMBOX_RX_LOOKAHEAD_MUX_SEL_MASK                        0x00000100
#define GMBOX_GMBOX_RX_LOOKAHEAD_MUX_SEL_GET(x)                      (((x) & GMBOX_GMBOX_RX_LOOKAHEAD_MUX_SEL_MASK) >> GMBOX_GMBOX_RX_LOOKAHEAD_MUX_SEL_LSB)
#define GMBOX_GMBOX_RX_LOOKAHEAD_MUX_SEL_SET(x)                      (((0 | (x)) << GMBOX_GMBOX_RX_LOOKAHEAD_MUX_SEL_LSB) & GMBOX_GMBOX_RX_LOOKAHEAD_MUX_SEL_MASK)
#define GMBOX_GMBOX_RX_LOOKAHEAD_MUX_SEL_RESET                       0
#define GMBOX_GMBOX_RX_UNDERFLOW_INT_EN_MSB                          2
#define GMBOX_GMBOX_RX_UNDERFLOW_INT_EN_LSB                          2
#define GMBOX_GMBOX_RX_UNDERFLOW_INT_EN_MASK                         0x00000004
#define GMBOX_GMBOX_RX_UNDERFLOW_INT_EN_GET(x)                       (((x) & GMBOX_GMBOX_RX_UNDERFLOW_INT_EN_MASK) >> GMBOX_GMBOX_RX_UNDERFLOW_INT_EN_LSB)
#define GMBOX_GMBOX_RX_UNDERFLOW_INT_EN_SET(x)                       (((0 | (x)) << GMBOX_GMBOX_RX_UNDERFLOW_INT_EN_LSB) & GMBOX_GMBOX_RX_UNDERFLOW_INT_EN_MASK)
#define GMBOX_GMBOX_RX_UNDERFLOW_INT_EN_RESET                        0
#define GMBOX_GMBOX_TX_OVERERFLOW_INT_EN_MSB                         1
#define GMBOX_GMBOX_TX_OVERERFLOW_INT_EN_LSB                         1
#define GMBOX_GMBOX_TX_OVERERFLOW_INT_EN_MASK                        0x00000002
#define GMBOX_GMBOX_TX_OVERERFLOW_INT_EN_GET(x)                      (((x) & GMBOX_GMBOX_TX_OVERERFLOW_INT_EN_MASK) >> GMBOX_GMBOX_TX_OVERERFLOW_INT_EN_LSB)
#define GMBOX_GMBOX_TX_OVERERFLOW_INT_EN_SET(x)                      (((0 | (x)) << GMBOX_GMBOX_TX_OVERERFLOW_INT_EN_LSB) & GMBOX_GMBOX_TX_OVERERFLOW_INT_EN_MASK)
#define GMBOX_GMBOX_TX_OVERERFLOW_INT_EN_RESET                       0
#define GMBOX_GMBOX_DATA_INT_EN_MSB                                  0
#define GMBOX_GMBOX_DATA_INT_EN_LSB                                  0
#define GMBOX_GMBOX_DATA_INT_EN_MASK                                 0x00000001
#define GMBOX_GMBOX_DATA_INT_EN_GET(x)                               (((x) & GMBOX_GMBOX_DATA_INT_EN_MASK) >> GMBOX_GMBOX_DATA_INT_EN_LSB)
#define GMBOX_GMBOX_DATA_INT_EN_SET(x)                               (((0 | (x)) << GMBOX_GMBOX_DATA_INT_EN_LSB) & GMBOX_GMBOX_DATA_INT_EN_MASK)
#define GMBOX_GMBOX_DATA_INT_EN_RESET                                0
#define GMBOX_ADDRESS                                                0x0888
#define GMBOX_HW_MASK                                                0x00000107
#define GMBOX_SW_MASK                                                0x00000107
#define GMBOX_HW_WRITE_MASK                                          0x00000000
#define GMBOX_SW_WRITE_MASK                                          0x00000107
#define GMBOX_RSTMASK                                                0xffffffff
#define GMBOX_RESET                                                  0x00000000

// 0x088c (CPU_DBG)
#define CPU_DBG_DATA_MSB                                             31
#define CPU_DBG_DATA_LSB                                             0
#define CPU_DBG_DATA_MASK                                            0xffffffff
#define CPU_DBG_DATA_GET(x)                                          (((x) & CPU_DBG_DATA_MASK) >> CPU_DBG_DATA_LSB)
#define CPU_DBG_DATA_SET(x)                                          (((0 | (x)) << CPU_DBG_DATA_LSB) & CPU_DBG_DATA_MASK)
#define CPU_DBG_DATA_RESET                                           0
#define CPU_DBG_ADDRESS                                              0x088c
#define CPU_DBG_HW_MASK                                              0xffffffff
#define CPU_DBG_SW_MASK                                              0xffffffff
#define CPU_DBG_HW_WRITE_MASK                                        0xffffffff
#define CPU_DBG_SW_WRITE_MASK                                        0x00000000
#define CPU_DBG_RSTMASK                                              0xffffffff
#define CPU_DBG_RESET                                                0x00000000

// 0x0890 (GMBOX_RX_LOOKAHEAD_0)
#define GMBOX_RX_LOOKAHEAD_0_DATA_MSB                                31
#define GMBOX_RX_LOOKAHEAD_0_DATA_LSB                                0
#define GMBOX_RX_LOOKAHEAD_0_DATA_MASK                               0xffffffff
#define GMBOX_RX_LOOKAHEAD_0_DATA_GET(x)                             (((x) & GMBOX_RX_LOOKAHEAD_0_DATA_MASK) >> GMBOX_RX_LOOKAHEAD_0_DATA_LSB)
#define GMBOX_RX_LOOKAHEAD_0_DATA_SET(x)                             (((0 | (x)) << GMBOX_RX_LOOKAHEAD_0_DATA_LSB) & GMBOX_RX_LOOKAHEAD_0_DATA_MASK)
#define GMBOX_RX_LOOKAHEAD_0_DATA_RESET                              0
#define GMBOX_RX_LOOKAHEAD_0_ADDRESS                                 0x0890
#define GMBOX_RX_LOOKAHEAD_ADDRESS                                   GMBOX_RX_LOOKAHEAD_0_ADDRESS
#define GMBOX_RX_LOOKAHEAD_0_HW_MASK                                 0xffffffff
#define GMBOX_RX_LOOKAHEAD_0_SW_MASK                                 0xffffffff
#define GMBOX_RX_LOOKAHEAD_0_HW_WRITE_MASK                           0xffffffff
#define GMBOX_RX_LOOKAHEAD_0_SW_WRITE_MASK                           0x00000000
#define GMBOX_RX_LOOKAHEAD_0_RSTMASK                                 0xffffffff
#define GMBOX_RX_LOOKAHEAD_0_RESET                                   0x00000000

// 0x0894 (GMBOX_RX_LOOKAHEAD_1)
#define GMBOX_RX_LOOKAHEAD_1_DATA_MSB                                31
#define GMBOX_RX_LOOKAHEAD_1_DATA_LSB                                0
#define GMBOX_RX_LOOKAHEAD_1_DATA_MASK                               0xffffffff
#define GMBOX_RX_LOOKAHEAD_1_DATA_GET(x)                             (((x) & GMBOX_RX_LOOKAHEAD_1_DATA_MASK) >> GMBOX_RX_LOOKAHEAD_1_DATA_LSB)
#define GMBOX_RX_LOOKAHEAD_1_DATA_SET(x)                             (((0 | (x)) << GMBOX_RX_LOOKAHEAD_1_DATA_LSB) & GMBOX_RX_LOOKAHEAD_1_DATA_MASK)
#define GMBOX_RX_LOOKAHEAD_1_DATA_RESET                              0
#define GMBOX_RX_LOOKAHEAD_1_ADDRESS                                 0x0894
#define GMBOX_RX_LOOKAHEAD_1_HW_MASK                                 0xffffffff
#define GMBOX_RX_LOOKAHEAD_1_SW_MASK                                 0xffffffff
#define GMBOX_RX_LOOKAHEAD_1_HW_WRITE_MASK                           0xffffffff
#define GMBOX_RX_LOOKAHEAD_1_SW_WRITE_MASK                           0x00000000
#define GMBOX_RX_LOOKAHEAD_1_RSTMASK                                 0xffffffff
#define GMBOX_RX_LOOKAHEAD_1_RESET                                   0x00000000

// 0x0a00 (CIS_WINDOW_0)
#define CIS_WINDOW_0_DATA_MSB                                        31
#define CIS_WINDOW_0_DATA_LSB                                        0
#define CIS_WINDOW_0_DATA_MASK                                       0xffffffff
#define CIS_WINDOW_0_DATA_GET(x)                                     (((x) & CIS_WINDOW_0_DATA_MASK) >> CIS_WINDOW_0_DATA_LSB)
#define CIS_WINDOW_0_DATA_SET(x)                                     (((0 | (x)) << CIS_WINDOW_0_DATA_LSB) & CIS_WINDOW_0_DATA_MASK)
#define CIS_WINDOW_0_DATA_RESET                                      0
#define CIS_WINDOW_0_ADDRESS                                         0x0a00
#define CIS_WINDOW_ADDRESS                                           CIS_WINDOW_0_ADDRESS
#define CIS_WINDOW_0_HW_MASK                                         0xffffffff
#define CIS_WINDOW_0_SW_MASK                                         0xffffffff
#define CIS_WINDOW_0_HW_WRITE_MASK                                   0x00000000
#define CIS_WINDOW_0_SW_WRITE_MASK                                   0xffffffff
#define CIS_WINDOW_0_RSTMASK                                         0xffffffff
#define CIS_WINDOW_0_RESET                                           0x00000000

// Skip a04 (CIS_WINDOW_1) - bfc (CIS_WINDOW_127) for brevity

#endif /* _MBOX_HOST_REG_H_ */
