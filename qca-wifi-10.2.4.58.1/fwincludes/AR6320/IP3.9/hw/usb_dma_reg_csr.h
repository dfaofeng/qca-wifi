//                                                                             
// File:       ./usb_dma_reg_csr.vrh                                           
// Creator:    tyzhang                                                         
// Time:       Sunday Feb 19, 2012 [12:30:08 am]                               
//                                                                             
// Path:       /trees/mbu-cn1/tyzhang/tianfang_enc_depot/chips/hera/dev/doc/headers/bp_wlan
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/mbu-cn1/tyzhang/tianfang_enc_depot/chips/hera/dev/blueprint/sysconfig
//             usb_dma_reg_csr.rdl                                             
//                                                                             
// Sources:    /trees/mbu-cn1/tyzhang/tianfang_enc_depot/chips/hera/dev/ip/athr/usb_dma/blueprint/usb_dma_reg.rdl
//             /trees/mbu-cn1/tyzhang/tianfang_enc_depot/chips/hera/dev/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    qing                                                            
// OS:         Linux 2.6.9-89.ELsmp                                            
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


#ifndef _USB_DMA_REG_CSR_H_
#define _USB_DMA_REG_CSR_H_
// 0x0000 (RX_0_DESC_START_ADDRESS)
#define RX_0_DESC_START_ADDRESS_REG_MSB                              31
#define RX_0_DESC_START_ADDRESS_REG_LSB                              0
#define RX_0_DESC_START_ADDRESS_REG_MASK                             0xffffffff
#define RX_0_DESC_START_ADDRESS_REG_GET(x)                           (((x) & RX_0_DESC_START_ADDRESS_REG_MASK) >> RX_0_DESC_START_ADDRESS_REG_LSB)
#define RX_0_DESC_START_ADDRESS_REG_SET(x)                           (((0 | (x)) << RX_0_DESC_START_ADDRESS_REG_LSB) & RX_0_DESC_START_ADDRESS_REG_MASK)
#define RX_0_DESC_START_ADDRESS_REG_RESET                            0
#define RX_0_DESC_START_ADDRESS_ADDRESS                              0x0000
#define RX_0_DESC_START_ADDRESS_HW_MASK                              0xffffffff
#define RX_0_DESC_START_ADDRESS_SW_MASK                              0xffffffff
#define RX_0_DESC_START_ADDRESS_HW_WRITE_MASK                        0x00000000
#define RX_0_DESC_START_ADDRESS_SW_WRITE_MASK                        0xffffffff
#define RX_0_DESC_START_ADDRESS_RSTMASK                              0xffffffff
#define RX_0_DESC_START_ADDRESS_RESET                                0x00000000

// 0x0004 (RX_0_DMA_START)
#define RX_0_DMA_START_RESTART_MSB                                   4
#define RX_0_DMA_START_RESTART_LSB                                   4
#define RX_0_DMA_START_RESTART_MASK                                  0x00000010
#define RX_0_DMA_START_RESTART_GET(x)                                (((x) & RX_0_DMA_START_RESTART_MASK) >> RX_0_DMA_START_RESTART_LSB)
#define RX_0_DMA_START_RESTART_SET(x)                                (((0 | (x)) << RX_0_DMA_START_RESTART_LSB) & RX_0_DMA_START_RESTART_MASK)
#define RX_0_DMA_START_RESTART_RESET                                 0
#define RX_0_DMA_START_START_MSB                                     0
#define RX_0_DMA_START_START_LSB                                     0
#define RX_0_DMA_START_START_MASK                                    0x00000001
#define RX_0_DMA_START_START_GET(x)                                  (((x) & RX_0_DMA_START_START_MASK) >> RX_0_DMA_START_START_LSB)
#define RX_0_DMA_START_START_SET(x)                                  (((0 | (x)) << RX_0_DMA_START_START_LSB) & RX_0_DMA_START_START_MASK)
#define RX_0_DMA_START_START_RESET                                   0
#define RX_0_DMA_START_ADDRESS                                       0x0004
#define RX_0_DMA_START_HW_MASK                                       0x00000011
#define RX_0_DMA_START_SW_MASK                                       0x00000011
#define RX_0_DMA_START_HW_WRITE_MASK                                 0x00000011
#define RX_0_DMA_START_SW_WRITE_MASK                                 0x00000011
#define RX_0_DMA_START_RSTMASK                                       0xffffffff
#define RX_0_DMA_START_RESET                                         0x00000000

// 0x0008 (RX_0_BURST_SIZE)
#define RX_0_BURST_SIZE_BURST_MSB                                    1
#define RX_0_BURST_SIZE_BURST_LSB                                    0
#define RX_0_BURST_SIZE_BURST_MASK                                   0x00000003
#define RX_0_BURST_SIZE_BURST_GET(x)                                 (((x) & RX_0_BURST_SIZE_BURST_MASK) >> RX_0_BURST_SIZE_BURST_LSB)
#define RX_0_BURST_SIZE_BURST_SET(x)                                 (((0 | (x)) << RX_0_BURST_SIZE_BURST_LSB) & RX_0_BURST_SIZE_BURST_MASK)
#define RX_0_BURST_SIZE_BURST_RESET                                  0
#define RX_0_BURST_SIZE_ADDRESS                                      0x0008
#define RX_0_BURST_SIZE_HW_MASK                                      0x00000003
#define RX_0_BURST_SIZE_SW_MASK                                      0x00000003
#define RX_0_BURST_SIZE_HW_WRITE_MASK                                0x00000000
#define RX_0_BURST_SIZE_SW_WRITE_MASK                                0x00000003
#define RX_0_BURST_SIZE_RSTMASK                                      0xffffffff
#define RX_0_BURST_SIZE_RESET                                        0x00000000

// 0x000c (RX_0_PACKET_OFFSET)
#define RX_0_PACKET_OFFSET_REG_MSB                                   7
#define RX_0_PACKET_OFFSET_REG_LSB                                   0
#define RX_0_PACKET_OFFSET_REG_MASK                                  0x000000ff
#define RX_0_PACKET_OFFSET_REG_GET(x)                                (((x) & RX_0_PACKET_OFFSET_REG_MASK) >> RX_0_PACKET_OFFSET_REG_LSB)
#define RX_0_PACKET_OFFSET_REG_SET(x)                                (((0 | (x)) << RX_0_PACKET_OFFSET_REG_LSB) & RX_0_PACKET_OFFSET_REG_MASK)
#define RX_0_PACKET_OFFSET_REG_RESET                                 0
#define RX_0_PACKET_OFFSET_ADDRESS                                   0x000c
#define RX_0_PACKET_OFFSET_HW_MASK                                   0x000000ff
#define RX_0_PACKET_OFFSET_SW_MASK                                   0x000000ff
#define RX_0_PACKET_OFFSET_HW_WRITE_MASK                             0x00000000
#define RX_0_PACKET_OFFSET_SW_WRITE_MASK                             0x000000ff
#define RX_0_PACKET_OFFSET_RSTMASK                                   0xffffffff
#define RX_0_PACKET_OFFSET_RESET                                     0x00000000

// 0x0010 (RX_0_CHECKSUM)
#define RX_0_CHECKSUM_UDP_MSB                                        1
#define RX_0_CHECKSUM_UDP_LSB                                        1
#define RX_0_CHECKSUM_UDP_MASK                                       0x00000002
#define RX_0_CHECKSUM_UDP_GET(x)                                     (((x) & RX_0_CHECKSUM_UDP_MASK) >> RX_0_CHECKSUM_UDP_LSB)
#define RX_0_CHECKSUM_UDP_SET(x)                                     (((0 | (x)) << RX_0_CHECKSUM_UDP_LSB) & RX_0_CHECKSUM_UDP_MASK)
#define RX_0_CHECKSUM_UDP_RESET                                      0
#define RX_0_CHECKSUM_TCP_MSB                                        0
#define RX_0_CHECKSUM_TCP_LSB                                        0
#define RX_0_CHECKSUM_TCP_MASK                                       0x00000001
#define RX_0_CHECKSUM_TCP_GET(x)                                     (((x) & RX_0_CHECKSUM_TCP_MASK) >> RX_0_CHECKSUM_TCP_LSB)
#define RX_0_CHECKSUM_TCP_SET(x)                                     (((0 | (x)) << RX_0_CHECKSUM_TCP_LSB) & RX_0_CHECKSUM_TCP_MASK)
#define RX_0_CHECKSUM_TCP_RESET                                      0
#define RX_0_CHECKSUM_ADDRESS                                        0x0010
#define RX_0_CHECKSUM_HW_MASK                                        0x00000003
#define RX_0_CHECKSUM_SW_MASK                                        0x00000003
#define RX_0_CHECKSUM_HW_WRITE_MASK                                  0x00000000
#define RX_0_CHECKSUM_SW_WRITE_MASK                                  0x00000003
#define RX_0_CHECKSUM_RSTMASK                                        0xffffffff
#define RX_0_CHECKSUM_RESET                                          0x00000000

// 0x0014 (RX_0_DBG_RX)
#define RX_0_DBG_RX_STATE_MSB                                        3
#define RX_0_DBG_RX_STATE_LSB                                        0
#define RX_0_DBG_RX_STATE_MASK                                       0x0000000f
#define RX_0_DBG_RX_STATE_GET(x)                                     (((x) & RX_0_DBG_RX_STATE_MASK) >> RX_0_DBG_RX_STATE_LSB)
#define RX_0_DBG_RX_STATE_SET(x)                                     (((0 | (x)) << RX_0_DBG_RX_STATE_LSB) & RX_0_DBG_RX_STATE_MASK)
#define RX_0_DBG_RX_STATE_RESET                                      0
#define RX_0_DBG_RX_ADDRESS                                          0x0014
#define RX_0_DBG_RX_HW_MASK                                          0x0000000f
#define RX_0_DBG_RX_SW_MASK                                          0x0000000f
#define RX_0_DBG_RX_HW_WRITE_MASK                                    0x0000000f
#define RX_0_DBG_RX_SW_WRITE_MASK                                    0x00000000
#define RX_0_DBG_RX_RSTMASK                                          0xffffffff
#define RX_0_DBG_RX_RESET                                            0x00000000

// 0x0018 (RX_0_DBG_RX_CUR_ADDR)
#define RX_0_DBG_RX_CUR_ADDR_REG_MSB                                 31
#define RX_0_DBG_RX_CUR_ADDR_REG_LSB                                 0
#define RX_0_DBG_RX_CUR_ADDR_REG_MASK                                0xffffffff
#define RX_0_DBG_RX_CUR_ADDR_REG_GET(x)                              (((x) & RX_0_DBG_RX_CUR_ADDR_REG_MASK) >> RX_0_DBG_RX_CUR_ADDR_REG_LSB)
#define RX_0_DBG_RX_CUR_ADDR_REG_SET(x)                              (((0 | (x)) << RX_0_DBG_RX_CUR_ADDR_REG_LSB) & RX_0_DBG_RX_CUR_ADDR_REG_MASK)
#define RX_0_DBG_RX_CUR_ADDR_REG_RESET                               0
#define RX_0_DBG_RX_CUR_ADDR_ADDRESS                                 0x0018
#define RX_0_DBG_RX_CUR_ADDR_HW_MASK                                 0xffffffff
#define RX_0_DBG_RX_CUR_ADDR_SW_MASK                                 0xffffffff
#define RX_0_DBG_RX_CUR_ADDR_HW_WRITE_MASK                           0xffffffff
#define RX_0_DBG_RX_CUR_ADDR_SW_WRITE_MASK                           0x00000000
#define RX_0_DBG_RX_CUR_ADDR_RSTMASK                                 0xffffffff
#define RX_0_DBG_RX_CUR_ADDR_RESET                                   0x00000000

// 0x001c (RX_0_DATA_SWAP)
#define RX_0_DATA_SWAP_SWAPD_MSB                                     1
#define RX_0_DATA_SWAP_SWAPD_LSB                                     1
#define RX_0_DATA_SWAP_SWAPD_MASK                                    0x00000002
#define RX_0_DATA_SWAP_SWAPD_GET(x)                                  (((x) & RX_0_DATA_SWAP_SWAPD_MASK) >> RX_0_DATA_SWAP_SWAPD_LSB)
#define RX_0_DATA_SWAP_SWAPD_SET(x)                                  (((0 | (x)) << RX_0_DATA_SWAP_SWAPD_LSB) & RX_0_DATA_SWAP_SWAPD_MASK)
#define RX_0_DATA_SWAP_SWAPD_RESET                                   0
#define RX_0_DATA_SWAP_SWAP_MSB                                      0
#define RX_0_DATA_SWAP_SWAP_LSB                                      0
#define RX_0_DATA_SWAP_SWAP_MASK                                     0x00000001
#define RX_0_DATA_SWAP_SWAP_GET(x)                                   (((x) & RX_0_DATA_SWAP_SWAP_MASK) >> RX_0_DATA_SWAP_SWAP_LSB)
#define RX_0_DATA_SWAP_SWAP_SET(x)                                   (((0 | (x)) << RX_0_DATA_SWAP_SWAP_LSB) & RX_0_DATA_SWAP_SWAP_MASK)
#define RX_0_DATA_SWAP_SWAP_RESET                                    1
#define RX_0_DATA_SWAP_ADDRESS                                       0x001c
#define RX_0_DATA_SWAP_HW_MASK                                       0x00000003
#define RX_0_DATA_SWAP_SW_MASK                                       0x00000003
#define RX_0_DATA_SWAP_HW_WRITE_MASK                                 0x00000000
#define RX_0_DATA_SWAP_SW_WRITE_MASK                                 0x00000003
#define RX_0_DATA_SWAP_RSTMASK                                       0xffffffff
#define RX_0_DATA_SWAP_RESET                                         0x00000001

// 0x0020 (RX_1_DESC_START_ADDRESS)
#define RX_1_DESC_START_ADDRESS_REG_MSB                              31
#define RX_1_DESC_START_ADDRESS_REG_LSB                              0
#define RX_1_DESC_START_ADDRESS_REG_MASK                             0xffffffff
#define RX_1_DESC_START_ADDRESS_REG_GET(x)                           (((x) & RX_1_DESC_START_ADDRESS_REG_MASK) >> RX_1_DESC_START_ADDRESS_REG_LSB)
#define RX_1_DESC_START_ADDRESS_REG_SET(x)                           (((0 | (x)) << RX_1_DESC_START_ADDRESS_REG_LSB) & RX_1_DESC_START_ADDRESS_REG_MASK)
#define RX_1_DESC_START_ADDRESS_REG_RESET                            0
#define RX_1_DESC_START_ADDRESS_ADDRESS                              0x0020
#define RX_1_DESC_START_ADDRESS_HW_MASK                              0xffffffff
#define RX_1_DESC_START_ADDRESS_SW_MASK                              0xffffffff
#define RX_1_DESC_START_ADDRESS_HW_WRITE_MASK                        0x00000000
#define RX_1_DESC_START_ADDRESS_SW_WRITE_MASK                        0xffffffff
#define RX_1_DESC_START_ADDRESS_RSTMASK                              0xffffffff
#define RX_1_DESC_START_ADDRESS_RESET                                0x00000000

// 0x0024 (RX_1_DMA_START)
#define RX_1_DMA_START_RESTART_MSB                                   4
#define RX_1_DMA_START_RESTART_LSB                                   4
#define RX_1_DMA_START_RESTART_MASK                                  0x00000010
#define RX_1_DMA_START_RESTART_GET(x)                                (((x) & RX_1_DMA_START_RESTART_MASK) >> RX_1_DMA_START_RESTART_LSB)
#define RX_1_DMA_START_RESTART_SET(x)                                (((0 | (x)) << RX_1_DMA_START_RESTART_LSB) & RX_1_DMA_START_RESTART_MASK)
#define RX_1_DMA_START_RESTART_RESET                                 0
#define RX_1_DMA_START_START_MSB                                     0
#define RX_1_DMA_START_START_LSB                                     0
#define RX_1_DMA_START_START_MASK                                    0x00000001
#define RX_1_DMA_START_START_GET(x)                                  (((x) & RX_1_DMA_START_START_MASK) >> RX_1_DMA_START_START_LSB)
#define RX_1_DMA_START_START_SET(x)                                  (((0 | (x)) << RX_1_DMA_START_START_LSB) & RX_1_DMA_START_START_MASK)
#define RX_1_DMA_START_START_RESET                                   0
#define RX_1_DMA_START_ADDRESS                                       0x0024
#define RX_1_DMA_START_HW_MASK                                       0x00000011
#define RX_1_DMA_START_SW_MASK                                       0x00000011
#define RX_1_DMA_START_HW_WRITE_MASK                                 0x00000011
#define RX_1_DMA_START_SW_WRITE_MASK                                 0x00000011
#define RX_1_DMA_START_RSTMASK                                       0xffffffff
#define RX_1_DMA_START_RESET                                         0x00000000

// 0x0028 (RX_1_BURST_SIZE)
#define RX_1_BURST_SIZE_BURST_MSB                                    1
#define RX_1_BURST_SIZE_BURST_LSB                                    0
#define RX_1_BURST_SIZE_BURST_MASK                                   0x00000003
#define RX_1_BURST_SIZE_BURST_GET(x)                                 (((x) & RX_1_BURST_SIZE_BURST_MASK) >> RX_1_BURST_SIZE_BURST_LSB)
#define RX_1_BURST_SIZE_BURST_SET(x)                                 (((0 | (x)) << RX_1_BURST_SIZE_BURST_LSB) & RX_1_BURST_SIZE_BURST_MASK)
#define RX_1_BURST_SIZE_BURST_RESET                                  0
#define RX_1_BURST_SIZE_ADDRESS                                      0x0028
#define RX_1_BURST_SIZE_HW_MASK                                      0x00000003
#define RX_1_BURST_SIZE_SW_MASK                                      0x00000003
#define RX_1_BURST_SIZE_HW_WRITE_MASK                                0x00000000
#define RX_1_BURST_SIZE_SW_WRITE_MASK                                0x00000003
#define RX_1_BURST_SIZE_RSTMASK                                      0xffffffff
#define RX_1_BURST_SIZE_RESET                                        0x00000000

// 0x002c (RX_1_PACKET_OFFSET)
#define RX_1_PACKET_OFFSET_REG_MSB                                   7
#define RX_1_PACKET_OFFSET_REG_LSB                                   0
#define RX_1_PACKET_OFFSET_REG_MASK                                  0x000000ff
#define RX_1_PACKET_OFFSET_REG_GET(x)                                (((x) & RX_1_PACKET_OFFSET_REG_MASK) >> RX_1_PACKET_OFFSET_REG_LSB)
#define RX_1_PACKET_OFFSET_REG_SET(x)                                (((0 | (x)) << RX_1_PACKET_OFFSET_REG_LSB) & RX_1_PACKET_OFFSET_REG_MASK)
#define RX_1_PACKET_OFFSET_REG_RESET                                 0
#define RX_1_PACKET_OFFSET_ADDRESS                                   0x002c
#define RX_1_PACKET_OFFSET_HW_MASK                                   0x000000ff
#define RX_1_PACKET_OFFSET_SW_MASK                                   0x000000ff
#define RX_1_PACKET_OFFSET_HW_WRITE_MASK                             0x00000000
#define RX_1_PACKET_OFFSET_SW_WRITE_MASK                             0x000000ff
#define RX_1_PACKET_OFFSET_RSTMASK                                   0xffffffff
#define RX_1_PACKET_OFFSET_RESET                                     0x00000000

// 0x0030 (RX_1_CHECKSUM)
#define RX_1_CHECKSUM_UDP_MSB                                        1
#define RX_1_CHECKSUM_UDP_LSB                                        1
#define RX_1_CHECKSUM_UDP_MASK                                       0x00000002
#define RX_1_CHECKSUM_UDP_GET(x)                                     (((x) & RX_1_CHECKSUM_UDP_MASK) >> RX_1_CHECKSUM_UDP_LSB)
#define RX_1_CHECKSUM_UDP_SET(x)                                     (((0 | (x)) << RX_1_CHECKSUM_UDP_LSB) & RX_1_CHECKSUM_UDP_MASK)
#define RX_1_CHECKSUM_UDP_RESET                                      0
#define RX_1_CHECKSUM_TCP_MSB                                        0
#define RX_1_CHECKSUM_TCP_LSB                                        0
#define RX_1_CHECKSUM_TCP_MASK                                       0x00000001
#define RX_1_CHECKSUM_TCP_GET(x)                                     (((x) & RX_1_CHECKSUM_TCP_MASK) >> RX_1_CHECKSUM_TCP_LSB)
#define RX_1_CHECKSUM_TCP_SET(x)                                     (((0 | (x)) << RX_1_CHECKSUM_TCP_LSB) & RX_1_CHECKSUM_TCP_MASK)
#define RX_1_CHECKSUM_TCP_RESET                                      0
#define RX_1_CHECKSUM_ADDRESS                                        0x0030
#define RX_1_CHECKSUM_HW_MASK                                        0x00000003
#define RX_1_CHECKSUM_SW_MASK                                        0x00000003
#define RX_1_CHECKSUM_HW_WRITE_MASK                                  0x00000000
#define RX_1_CHECKSUM_SW_WRITE_MASK                                  0x00000003
#define RX_1_CHECKSUM_RSTMASK                                        0xffffffff
#define RX_1_CHECKSUM_RESET                                          0x00000000

// 0x0034 (RX_1_DBG_RX)
#define RX_1_DBG_RX_STATE_MSB                                        3
#define RX_1_DBG_RX_STATE_LSB                                        0
#define RX_1_DBG_RX_STATE_MASK                                       0x0000000f
#define RX_1_DBG_RX_STATE_GET(x)                                     (((x) & RX_1_DBG_RX_STATE_MASK) >> RX_1_DBG_RX_STATE_LSB)
#define RX_1_DBG_RX_STATE_SET(x)                                     (((0 | (x)) << RX_1_DBG_RX_STATE_LSB) & RX_1_DBG_RX_STATE_MASK)
#define RX_1_DBG_RX_STATE_RESET                                      0
#define RX_1_DBG_RX_ADDRESS                                          0x0034
#define RX_1_DBG_RX_HW_MASK                                          0x0000000f
#define RX_1_DBG_RX_SW_MASK                                          0x0000000f
#define RX_1_DBG_RX_HW_WRITE_MASK                                    0x0000000f
#define RX_1_DBG_RX_SW_WRITE_MASK                                    0x00000000
#define RX_1_DBG_RX_RSTMASK                                          0xffffffff
#define RX_1_DBG_RX_RESET                                            0x00000000

// 0x0038 (RX_1_DBG_RX_CUR_ADDR)
#define RX_1_DBG_RX_CUR_ADDR_REG_MSB                                 31
#define RX_1_DBG_RX_CUR_ADDR_REG_LSB                                 0
#define RX_1_DBG_RX_CUR_ADDR_REG_MASK                                0xffffffff
#define RX_1_DBG_RX_CUR_ADDR_REG_GET(x)                              (((x) & RX_1_DBG_RX_CUR_ADDR_REG_MASK) >> RX_1_DBG_RX_CUR_ADDR_REG_LSB)
#define RX_1_DBG_RX_CUR_ADDR_REG_SET(x)                              (((0 | (x)) << RX_1_DBG_RX_CUR_ADDR_REG_LSB) & RX_1_DBG_RX_CUR_ADDR_REG_MASK)
#define RX_1_DBG_RX_CUR_ADDR_REG_RESET                               0
#define RX_1_DBG_RX_CUR_ADDR_ADDRESS                                 0x0038
#define RX_1_DBG_RX_CUR_ADDR_HW_MASK                                 0xffffffff
#define RX_1_DBG_RX_CUR_ADDR_SW_MASK                                 0xffffffff
#define RX_1_DBG_RX_CUR_ADDR_HW_WRITE_MASK                           0xffffffff
#define RX_1_DBG_RX_CUR_ADDR_SW_WRITE_MASK                           0x00000000
#define RX_1_DBG_RX_CUR_ADDR_RSTMASK                                 0xffffffff
#define RX_1_DBG_RX_CUR_ADDR_RESET                                   0x00000000

// 0x003c (RX_1_DATA_SWAP)
#define RX_1_DATA_SWAP_SWAPD_MSB                                     1
#define RX_1_DATA_SWAP_SWAPD_LSB                                     1
#define RX_1_DATA_SWAP_SWAPD_MASK                                    0x00000002
#define RX_1_DATA_SWAP_SWAPD_GET(x)                                  (((x) & RX_1_DATA_SWAP_SWAPD_MASK) >> RX_1_DATA_SWAP_SWAPD_LSB)
#define RX_1_DATA_SWAP_SWAPD_SET(x)                                  (((0 | (x)) << RX_1_DATA_SWAP_SWAPD_LSB) & RX_1_DATA_SWAP_SWAPD_MASK)
#define RX_1_DATA_SWAP_SWAPD_RESET                                   0
#define RX_1_DATA_SWAP_SWAP_MSB                                      0
#define RX_1_DATA_SWAP_SWAP_LSB                                      0
#define RX_1_DATA_SWAP_SWAP_MASK                                     0x00000001
#define RX_1_DATA_SWAP_SWAP_GET(x)                                   (((x) & RX_1_DATA_SWAP_SWAP_MASK) >> RX_1_DATA_SWAP_SWAP_LSB)
#define RX_1_DATA_SWAP_SWAP_SET(x)                                   (((0 | (x)) << RX_1_DATA_SWAP_SWAP_LSB) & RX_1_DATA_SWAP_SWAP_MASK)
#define RX_1_DATA_SWAP_SWAP_RESET                                    1
#define RX_1_DATA_SWAP_ADDRESS                                       0x003c
#define RX_1_DATA_SWAP_HW_MASK                                       0x00000003
#define RX_1_DATA_SWAP_SW_MASK                                       0x00000003
#define RX_1_DATA_SWAP_HW_WRITE_MASK                                 0x00000000
#define RX_1_DATA_SWAP_SW_WRITE_MASK                                 0x00000003
#define RX_1_DATA_SWAP_RSTMASK                                       0xffffffff
#define RX_1_DATA_SWAP_RESET                                         0x00000001

// 0x0040 (RX_2_DESC_START_ADDRESS)
#define RX_2_DESC_START_ADDRESS_REG_MSB                              31
#define RX_2_DESC_START_ADDRESS_REG_LSB                              0
#define RX_2_DESC_START_ADDRESS_REG_MASK                             0xffffffff
#define RX_2_DESC_START_ADDRESS_REG_GET(x)                           (((x) & RX_2_DESC_START_ADDRESS_REG_MASK) >> RX_2_DESC_START_ADDRESS_REG_LSB)
#define RX_2_DESC_START_ADDRESS_REG_SET(x)                           (((0 | (x)) << RX_2_DESC_START_ADDRESS_REG_LSB) & RX_2_DESC_START_ADDRESS_REG_MASK)
#define RX_2_DESC_START_ADDRESS_REG_RESET                            0
#define RX_2_DESC_START_ADDRESS_ADDRESS                              0x0040
#define RX_2_DESC_START_ADDRESS_HW_MASK                              0xffffffff
#define RX_2_DESC_START_ADDRESS_SW_MASK                              0xffffffff
#define RX_2_DESC_START_ADDRESS_HW_WRITE_MASK                        0x00000000
#define RX_2_DESC_START_ADDRESS_SW_WRITE_MASK                        0xffffffff
#define RX_2_DESC_START_ADDRESS_RSTMASK                              0xffffffff
#define RX_2_DESC_START_ADDRESS_RESET                                0x00000000

// 0x0044 (RX_2_DMA_START)
#define RX_2_DMA_START_RESTART_MSB                                   4
#define RX_2_DMA_START_RESTART_LSB                                   4
#define RX_2_DMA_START_RESTART_MASK                                  0x00000010
#define RX_2_DMA_START_RESTART_GET(x)                                (((x) & RX_2_DMA_START_RESTART_MASK) >> RX_2_DMA_START_RESTART_LSB)
#define RX_2_DMA_START_RESTART_SET(x)                                (((0 | (x)) << RX_2_DMA_START_RESTART_LSB) & RX_2_DMA_START_RESTART_MASK)
#define RX_2_DMA_START_RESTART_RESET                                 0
#define RX_2_DMA_START_START_MSB                                     0
#define RX_2_DMA_START_START_LSB                                     0
#define RX_2_DMA_START_START_MASK                                    0x00000001
#define RX_2_DMA_START_START_GET(x)                                  (((x) & RX_2_DMA_START_START_MASK) >> RX_2_DMA_START_START_LSB)
#define RX_2_DMA_START_START_SET(x)                                  (((0 | (x)) << RX_2_DMA_START_START_LSB) & RX_2_DMA_START_START_MASK)
#define RX_2_DMA_START_START_RESET                                   0
#define RX_2_DMA_START_ADDRESS                                       0x0044
#define RX_2_DMA_START_HW_MASK                                       0x00000011
#define RX_2_DMA_START_SW_MASK                                       0x00000011
#define RX_2_DMA_START_HW_WRITE_MASK                                 0x00000011
#define RX_2_DMA_START_SW_WRITE_MASK                                 0x00000011
#define RX_2_DMA_START_RSTMASK                                       0xffffffff
#define RX_2_DMA_START_RESET                                         0x00000000

// 0x0048 (RX_2_BURST_SIZE)
#define RX_2_BURST_SIZE_BURST_MSB                                    1
#define RX_2_BURST_SIZE_BURST_LSB                                    0
#define RX_2_BURST_SIZE_BURST_MASK                                   0x00000003
#define RX_2_BURST_SIZE_BURST_GET(x)                                 (((x) & RX_2_BURST_SIZE_BURST_MASK) >> RX_2_BURST_SIZE_BURST_LSB)
#define RX_2_BURST_SIZE_BURST_SET(x)                                 (((0 | (x)) << RX_2_BURST_SIZE_BURST_LSB) & RX_2_BURST_SIZE_BURST_MASK)
#define RX_2_BURST_SIZE_BURST_RESET                                  0
#define RX_2_BURST_SIZE_ADDRESS                                      0x0048
#define RX_2_BURST_SIZE_HW_MASK                                      0x00000003
#define RX_2_BURST_SIZE_SW_MASK                                      0x00000003
#define RX_2_BURST_SIZE_HW_WRITE_MASK                                0x00000000
#define RX_2_BURST_SIZE_SW_WRITE_MASK                                0x00000003
#define RX_2_BURST_SIZE_RSTMASK                                      0xffffffff
#define RX_2_BURST_SIZE_RESET                                        0x00000000

// 0x004c (RX_2_PACKET_OFFSET)
#define RX_2_PACKET_OFFSET_REG_MSB                                   7
#define RX_2_PACKET_OFFSET_REG_LSB                                   0
#define RX_2_PACKET_OFFSET_REG_MASK                                  0x000000ff
#define RX_2_PACKET_OFFSET_REG_GET(x)                                (((x) & RX_2_PACKET_OFFSET_REG_MASK) >> RX_2_PACKET_OFFSET_REG_LSB)
#define RX_2_PACKET_OFFSET_REG_SET(x)                                (((0 | (x)) << RX_2_PACKET_OFFSET_REG_LSB) & RX_2_PACKET_OFFSET_REG_MASK)
#define RX_2_PACKET_OFFSET_REG_RESET                                 0
#define RX_2_PACKET_OFFSET_ADDRESS                                   0x004c
#define RX_2_PACKET_OFFSET_HW_MASK                                   0x000000ff
#define RX_2_PACKET_OFFSET_SW_MASK                                   0x000000ff
#define RX_2_PACKET_OFFSET_HW_WRITE_MASK                             0x00000000
#define RX_2_PACKET_OFFSET_SW_WRITE_MASK                             0x000000ff
#define RX_2_PACKET_OFFSET_RSTMASK                                   0xffffffff
#define RX_2_PACKET_OFFSET_RESET                                     0x00000000

// 0x0050 (RX_2_CHECKSUM)
#define RX_2_CHECKSUM_UDP_MSB                                        1
#define RX_2_CHECKSUM_UDP_LSB                                        1
#define RX_2_CHECKSUM_UDP_MASK                                       0x00000002
#define RX_2_CHECKSUM_UDP_GET(x)                                     (((x) & RX_2_CHECKSUM_UDP_MASK) >> RX_2_CHECKSUM_UDP_LSB)
#define RX_2_CHECKSUM_UDP_SET(x)                                     (((0 | (x)) << RX_2_CHECKSUM_UDP_LSB) & RX_2_CHECKSUM_UDP_MASK)
#define RX_2_CHECKSUM_UDP_RESET                                      0
#define RX_2_CHECKSUM_TCP_MSB                                        0
#define RX_2_CHECKSUM_TCP_LSB                                        0
#define RX_2_CHECKSUM_TCP_MASK                                       0x00000001
#define RX_2_CHECKSUM_TCP_GET(x)                                     (((x) & RX_2_CHECKSUM_TCP_MASK) >> RX_2_CHECKSUM_TCP_LSB)
#define RX_2_CHECKSUM_TCP_SET(x)                                     (((0 | (x)) << RX_2_CHECKSUM_TCP_LSB) & RX_2_CHECKSUM_TCP_MASK)
#define RX_2_CHECKSUM_TCP_RESET                                      0
#define RX_2_CHECKSUM_ADDRESS                                        0x0050
#define RX_2_CHECKSUM_HW_MASK                                        0x00000003
#define RX_2_CHECKSUM_SW_MASK                                        0x00000003
#define RX_2_CHECKSUM_HW_WRITE_MASK                                  0x00000000
#define RX_2_CHECKSUM_SW_WRITE_MASK                                  0x00000003
#define RX_2_CHECKSUM_RSTMASK                                        0xffffffff
#define RX_2_CHECKSUM_RESET                                          0x00000000

// 0x0054 (RX_2_DBG_RX)
#define RX_2_DBG_RX_STATE_MSB                                        3
#define RX_2_DBG_RX_STATE_LSB                                        0
#define RX_2_DBG_RX_STATE_MASK                                       0x0000000f
#define RX_2_DBG_RX_STATE_GET(x)                                     (((x) & RX_2_DBG_RX_STATE_MASK) >> RX_2_DBG_RX_STATE_LSB)
#define RX_2_DBG_RX_STATE_SET(x)                                     (((0 | (x)) << RX_2_DBG_RX_STATE_LSB) & RX_2_DBG_RX_STATE_MASK)
#define RX_2_DBG_RX_STATE_RESET                                      0
#define RX_2_DBG_RX_ADDRESS                                          0x0054
#define RX_2_DBG_RX_HW_MASK                                          0x0000000f
#define RX_2_DBG_RX_SW_MASK                                          0x0000000f
#define RX_2_DBG_RX_HW_WRITE_MASK                                    0x0000000f
#define RX_2_DBG_RX_SW_WRITE_MASK                                    0x00000000
#define RX_2_DBG_RX_RSTMASK                                          0xffffffff
#define RX_2_DBG_RX_RESET                                            0x00000000

// 0x0058 (RX_2_DBG_RX_CUR_ADDR)
#define RX_2_DBG_RX_CUR_ADDR_REG_MSB                                 31
#define RX_2_DBG_RX_CUR_ADDR_REG_LSB                                 0
#define RX_2_DBG_RX_CUR_ADDR_REG_MASK                                0xffffffff
#define RX_2_DBG_RX_CUR_ADDR_REG_GET(x)                              (((x) & RX_2_DBG_RX_CUR_ADDR_REG_MASK) >> RX_2_DBG_RX_CUR_ADDR_REG_LSB)
#define RX_2_DBG_RX_CUR_ADDR_REG_SET(x)                              (((0 | (x)) << RX_2_DBG_RX_CUR_ADDR_REG_LSB) & RX_2_DBG_RX_CUR_ADDR_REG_MASK)
#define RX_2_DBG_RX_CUR_ADDR_REG_RESET                               0
#define RX_2_DBG_RX_CUR_ADDR_ADDRESS                                 0x0058
#define RX_2_DBG_RX_CUR_ADDR_HW_MASK                                 0xffffffff
#define RX_2_DBG_RX_CUR_ADDR_SW_MASK                                 0xffffffff
#define RX_2_DBG_RX_CUR_ADDR_HW_WRITE_MASK                           0xffffffff
#define RX_2_DBG_RX_CUR_ADDR_SW_WRITE_MASK                           0x00000000
#define RX_2_DBG_RX_CUR_ADDR_RSTMASK                                 0xffffffff
#define RX_2_DBG_RX_CUR_ADDR_RESET                                   0x00000000

// 0x005c (RX_2_DATA_SWAP)
#define RX_2_DATA_SWAP_SWAPD_MSB                                     1
#define RX_2_DATA_SWAP_SWAPD_LSB                                     1
#define RX_2_DATA_SWAP_SWAPD_MASK                                    0x00000002
#define RX_2_DATA_SWAP_SWAPD_GET(x)                                  (((x) & RX_2_DATA_SWAP_SWAPD_MASK) >> RX_2_DATA_SWAP_SWAPD_LSB)
#define RX_2_DATA_SWAP_SWAPD_SET(x)                                  (((0 | (x)) << RX_2_DATA_SWAP_SWAPD_LSB) & RX_2_DATA_SWAP_SWAPD_MASK)
#define RX_2_DATA_SWAP_SWAPD_RESET                                   0
#define RX_2_DATA_SWAP_SWAP_MSB                                      0
#define RX_2_DATA_SWAP_SWAP_LSB                                      0
#define RX_2_DATA_SWAP_SWAP_MASK                                     0x00000001
#define RX_2_DATA_SWAP_SWAP_GET(x)                                   (((x) & RX_2_DATA_SWAP_SWAP_MASK) >> RX_2_DATA_SWAP_SWAP_LSB)
#define RX_2_DATA_SWAP_SWAP_SET(x)                                   (((0 | (x)) << RX_2_DATA_SWAP_SWAP_LSB) & RX_2_DATA_SWAP_SWAP_MASK)
#define RX_2_DATA_SWAP_SWAP_RESET                                    1
#define RX_2_DATA_SWAP_ADDRESS                                       0x005c
#define RX_2_DATA_SWAP_HW_MASK                                       0x00000003
#define RX_2_DATA_SWAP_SW_MASK                                       0x00000003
#define RX_2_DATA_SWAP_HW_WRITE_MASK                                 0x00000000
#define RX_2_DATA_SWAP_SW_WRITE_MASK                                 0x00000003
#define RX_2_DATA_SWAP_RSTMASK                                       0xffffffff
#define RX_2_DATA_SWAP_RESET                                         0x00000001

// 0x0060 (RX_3_DESC_START_ADDRESS)
#define RX_3_DESC_START_ADDRESS_REG_MSB                              31
#define RX_3_DESC_START_ADDRESS_REG_LSB                              0
#define RX_3_DESC_START_ADDRESS_REG_MASK                             0xffffffff
#define RX_3_DESC_START_ADDRESS_REG_GET(x)                           (((x) & RX_3_DESC_START_ADDRESS_REG_MASK) >> RX_3_DESC_START_ADDRESS_REG_LSB)
#define RX_3_DESC_START_ADDRESS_REG_SET(x)                           (((0 | (x)) << RX_3_DESC_START_ADDRESS_REG_LSB) & RX_3_DESC_START_ADDRESS_REG_MASK)
#define RX_3_DESC_START_ADDRESS_REG_RESET                            0
#define RX_3_DESC_START_ADDRESS_ADDRESS                              0x0060
#define RX_3_DESC_START_ADDRESS_HW_MASK                              0xffffffff
#define RX_3_DESC_START_ADDRESS_SW_MASK                              0xffffffff
#define RX_3_DESC_START_ADDRESS_HW_WRITE_MASK                        0x00000000
#define RX_3_DESC_START_ADDRESS_SW_WRITE_MASK                        0xffffffff
#define RX_3_DESC_START_ADDRESS_RSTMASK                              0xffffffff
#define RX_3_DESC_START_ADDRESS_RESET                                0x00000000

// 0x0064 (RX_3_DMA_START)
#define RX_3_DMA_START_RESTART_MSB                                   4
#define RX_3_DMA_START_RESTART_LSB                                   4
#define RX_3_DMA_START_RESTART_MASK                                  0x00000010
#define RX_3_DMA_START_RESTART_GET(x)                                (((x) & RX_3_DMA_START_RESTART_MASK) >> RX_3_DMA_START_RESTART_LSB)
#define RX_3_DMA_START_RESTART_SET(x)                                (((0 | (x)) << RX_3_DMA_START_RESTART_LSB) & RX_3_DMA_START_RESTART_MASK)
#define RX_3_DMA_START_RESTART_RESET                                 0
#define RX_3_DMA_START_START_MSB                                     0
#define RX_3_DMA_START_START_LSB                                     0
#define RX_3_DMA_START_START_MASK                                    0x00000001
#define RX_3_DMA_START_START_GET(x)                                  (((x) & RX_3_DMA_START_START_MASK) >> RX_3_DMA_START_START_LSB)
#define RX_3_DMA_START_START_SET(x)                                  (((0 | (x)) << RX_3_DMA_START_START_LSB) & RX_3_DMA_START_START_MASK)
#define RX_3_DMA_START_START_RESET                                   0
#define RX_3_DMA_START_ADDRESS                                       0x0064
#define RX_3_DMA_START_HW_MASK                                       0x00000011
#define RX_3_DMA_START_SW_MASK                                       0x00000011
#define RX_3_DMA_START_HW_WRITE_MASK                                 0x00000011
#define RX_3_DMA_START_SW_WRITE_MASK                                 0x00000011
#define RX_3_DMA_START_RSTMASK                                       0xffffffff
#define RX_3_DMA_START_RESET                                         0x00000000

// 0x0068 (RX_3_BURST_SIZE)
#define RX_3_BURST_SIZE_BURST_MSB                                    1
#define RX_3_BURST_SIZE_BURST_LSB                                    0
#define RX_3_BURST_SIZE_BURST_MASK                                   0x00000003
#define RX_3_BURST_SIZE_BURST_GET(x)                                 (((x) & RX_3_BURST_SIZE_BURST_MASK) >> RX_3_BURST_SIZE_BURST_LSB)
#define RX_3_BURST_SIZE_BURST_SET(x)                                 (((0 | (x)) << RX_3_BURST_SIZE_BURST_LSB) & RX_3_BURST_SIZE_BURST_MASK)
#define RX_3_BURST_SIZE_BURST_RESET                                  0
#define RX_3_BURST_SIZE_ADDRESS                                      0x0068
#define RX_3_BURST_SIZE_HW_MASK                                      0x00000003
#define RX_3_BURST_SIZE_SW_MASK                                      0x00000003
#define RX_3_BURST_SIZE_HW_WRITE_MASK                                0x00000000
#define RX_3_BURST_SIZE_SW_WRITE_MASK                                0x00000003
#define RX_3_BURST_SIZE_RSTMASK                                      0xffffffff
#define RX_3_BURST_SIZE_RESET                                        0x00000000

// 0x006c (RX_3_PACKET_OFFSET)
#define RX_3_PACKET_OFFSET_REG_MSB                                   7
#define RX_3_PACKET_OFFSET_REG_LSB                                   0
#define RX_3_PACKET_OFFSET_REG_MASK                                  0x000000ff
#define RX_3_PACKET_OFFSET_REG_GET(x)                                (((x) & RX_3_PACKET_OFFSET_REG_MASK) >> RX_3_PACKET_OFFSET_REG_LSB)
#define RX_3_PACKET_OFFSET_REG_SET(x)                                (((0 | (x)) << RX_3_PACKET_OFFSET_REG_LSB) & RX_3_PACKET_OFFSET_REG_MASK)
#define RX_3_PACKET_OFFSET_REG_RESET                                 0
#define RX_3_PACKET_OFFSET_ADDRESS                                   0x006c
#define RX_3_PACKET_OFFSET_HW_MASK                                   0x000000ff
#define RX_3_PACKET_OFFSET_SW_MASK                                   0x000000ff
#define RX_3_PACKET_OFFSET_HW_WRITE_MASK                             0x00000000
#define RX_3_PACKET_OFFSET_SW_WRITE_MASK                             0x000000ff
#define RX_3_PACKET_OFFSET_RSTMASK                                   0xffffffff
#define RX_3_PACKET_OFFSET_RESET                                     0x00000000

// 0x0070 (RX_3_CHECKSUM)
#define RX_3_CHECKSUM_UDP_MSB                                        1
#define RX_3_CHECKSUM_UDP_LSB                                        1
#define RX_3_CHECKSUM_UDP_MASK                                       0x00000002
#define RX_3_CHECKSUM_UDP_GET(x)                                     (((x) & RX_3_CHECKSUM_UDP_MASK) >> RX_3_CHECKSUM_UDP_LSB)
#define RX_3_CHECKSUM_UDP_SET(x)                                     (((0 | (x)) << RX_3_CHECKSUM_UDP_LSB) & RX_3_CHECKSUM_UDP_MASK)
#define RX_3_CHECKSUM_UDP_RESET                                      0
#define RX_3_CHECKSUM_TCP_MSB                                        0
#define RX_3_CHECKSUM_TCP_LSB                                        0
#define RX_3_CHECKSUM_TCP_MASK                                       0x00000001
#define RX_3_CHECKSUM_TCP_GET(x)                                     (((x) & RX_3_CHECKSUM_TCP_MASK) >> RX_3_CHECKSUM_TCP_LSB)
#define RX_3_CHECKSUM_TCP_SET(x)                                     (((0 | (x)) << RX_3_CHECKSUM_TCP_LSB) & RX_3_CHECKSUM_TCP_MASK)
#define RX_3_CHECKSUM_TCP_RESET                                      0
#define RX_3_CHECKSUM_ADDRESS                                        0x0070
#define RX_3_CHECKSUM_HW_MASK                                        0x00000003
#define RX_3_CHECKSUM_SW_MASK                                        0x00000003
#define RX_3_CHECKSUM_HW_WRITE_MASK                                  0x00000000
#define RX_3_CHECKSUM_SW_WRITE_MASK                                  0x00000003
#define RX_3_CHECKSUM_RSTMASK                                        0xffffffff
#define RX_3_CHECKSUM_RESET                                          0x00000000

// 0x0074 (RX_3_DBG_RX)
#define RX_3_DBG_RX_STATE_MSB                                        3
#define RX_3_DBG_RX_STATE_LSB                                        0
#define RX_3_DBG_RX_STATE_MASK                                       0x0000000f
#define RX_3_DBG_RX_STATE_GET(x)                                     (((x) & RX_3_DBG_RX_STATE_MASK) >> RX_3_DBG_RX_STATE_LSB)
#define RX_3_DBG_RX_STATE_SET(x)                                     (((0 | (x)) << RX_3_DBG_RX_STATE_LSB) & RX_3_DBG_RX_STATE_MASK)
#define RX_3_DBG_RX_STATE_RESET                                      0
#define RX_3_DBG_RX_ADDRESS                                          0x0074
#define RX_3_DBG_RX_HW_MASK                                          0x0000000f
#define RX_3_DBG_RX_SW_MASK                                          0x0000000f
#define RX_3_DBG_RX_HW_WRITE_MASK                                    0x0000000f
#define RX_3_DBG_RX_SW_WRITE_MASK                                    0x00000000
#define RX_3_DBG_RX_RSTMASK                                          0xffffffff
#define RX_3_DBG_RX_RESET                                            0x00000000

// 0x0078 (RX_3_DBG_RX_CUR_ADDR)
#define RX_3_DBG_RX_CUR_ADDR_REG_MSB                                 31
#define RX_3_DBG_RX_CUR_ADDR_REG_LSB                                 0
#define RX_3_DBG_RX_CUR_ADDR_REG_MASK                                0xffffffff
#define RX_3_DBG_RX_CUR_ADDR_REG_GET(x)                              (((x) & RX_3_DBG_RX_CUR_ADDR_REG_MASK) >> RX_3_DBG_RX_CUR_ADDR_REG_LSB)
#define RX_3_DBG_RX_CUR_ADDR_REG_SET(x)                              (((0 | (x)) << RX_3_DBG_RX_CUR_ADDR_REG_LSB) & RX_3_DBG_RX_CUR_ADDR_REG_MASK)
#define RX_3_DBG_RX_CUR_ADDR_REG_RESET                               0
#define RX_3_DBG_RX_CUR_ADDR_ADDRESS                                 0x0078
#define RX_3_DBG_RX_CUR_ADDR_HW_MASK                                 0xffffffff
#define RX_3_DBG_RX_CUR_ADDR_SW_MASK                                 0xffffffff
#define RX_3_DBG_RX_CUR_ADDR_HW_WRITE_MASK                           0xffffffff
#define RX_3_DBG_RX_CUR_ADDR_SW_WRITE_MASK                           0x00000000
#define RX_3_DBG_RX_CUR_ADDR_RSTMASK                                 0xffffffff
#define RX_3_DBG_RX_CUR_ADDR_RESET                                   0x00000000

// 0x007c (RX_3_DATA_SWAP)
#define RX_3_DATA_SWAP_SWAPD_MSB                                     1
#define RX_3_DATA_SWAP_SWAPD_LSB                                     1
#define RX_3_DATA_SWAP_SWAPD_MASK                                    0x00000002
#define RX_3_DATA_SWAP_SWAPD_GET(x)                                  (((x) & RX_3_DATA_SWAP_SWAPD_MASK) >> RX_3_DATA_SWAP_SWAPD_LSB)
#define RX_3_DATA_SWAP_SWAPD_SET(x)                                  (((0 | (x)) << RX_3_DATA_SWAP_SWAPD_LSB) & RX_3_DATA_SWAP_SWAPD_MASK)
#define RX_3_DATA_SWAP_SWAPD_RESET                                   0
#define RX_3_DATA_SWAP_SWAP_MSB                                      0
#define RX_3_DATA_SWAP_SWAP_LSB                                      0
#define RX_3_DATA_SWAP_SWAP_MASK                                     0x00000001
#define RX_3_DATA_SWAP_SWAP_GET(x)                                   (((x) & RX_3_DATA_SWAP_SWAP_MASK) >> RX_3_DATA_SWAP_SWAP_LSB)
#define RX_3_DATA_SWAP_SWAP_SET(x)                                   (((0 | (x)) << RX_3_DATA_SWAP_SWAP_LSB) & RX_3_DATA_SWAP_SWAP_MASK)
#define RX_3_DATA_SWAP_SWAP_RESET                                    1
#define RX_3_DATA_SWAP_ADDRESS                                       0x007c
#define RX_3_DATA_SWAP_HW_MASK                                       0x00000003
#define RX_3_DATA_SWAP_SW_MASK                                       0x00000003
#define RX_3_DATA_SWAP_HW_WRITE_MASK                                 0x00000000
#define RX_3_DATA_SWAP_SW_WRITE_MASK                                 0x00000003
#define RX_3_DATA_SWAP_RSTMASK                                       0xffffffff
#define RX_3_DATA_SWAP_RESET                                         0x00000001

// 0x0080 (RX_4_DESC_START_ADDRESS)
#define RX_4_DESC_START_ADDRESS_REG_MSB                              31
#define RX_4_DESC_START_ADDRESS_REG_LSB                              0
#define RX_4_DESC_START_ADDRESS_REG_MASK                             0xffffffff
#define RX_4_DESC_START_ADDRESS_REG_GET(x)                           (((x) & RX_4_DESC_START_ADDRESS_REG_MASK) >> RX_4_DESC_START_ADDRESS_REG_LSB)
#define RX_4_DESC_START_ADDRESS_REG_SET(x)                           (((0 | (x)) << RX_4_DESC_START_ADDRESS_REG_LSB) & RX_4_DESC_START_ADDRESS_REG_MASK)
#define RX_4_DESC_START_ADDRESS_REG_RESET                            0
#define RX_4_DESC_START_ADDRESS_ADDRESS                              0x0080
#define RX_4_DESC_START_ADDRESS_HW_MASK                              0xffffffff
#define RX_4_DESC_START_ADDRESS_SW_MASK                              0xffffffff
#define RX_4_DESC_START_ADDRESS_HW_WRITE_MASK                        0x00000000
#define RX_4_DESC_START_ADDRESS_SW_WRITE_MASK                        0xffffffff
#define RX_4_DESC_START_ADDRESS_RSTMASK                              0xffffffff
#define RX_4_DESC_START_ADDRESS_RESET                                0x00000000

// 0x0084 (RX_4_DMA_START)
#define RX_4_DMA_START_RESTART_MSB                                   4
#define RX_4_DMA_START_RESTART_LSB                                   4
#define RX_4_DMA_START_RESTART_MASK                                  0x00000010
#define RX_4_DMA_START_RESTART_GET(x)                                (((x) & RX_4_DMA_START_RESTART_MASK) >> RX_4_DMA_START_RESTART_LSB)
#define RX_4_DMA_START_RESTART_SET(x)                                (((0 | (x)) << RX_4_DMA_START_RESTART_LSB) & RX_4_DMA_START_RESTART_MASK)
#define RX_4_DMA_START_RESTART_RESET                                 0
#define RX_4_DMA_START_START_MSB                                     0
#define RX_4_DMA_START_START_LSB                                     0
#define RX_4_DMA_START_START_MASK                                    0x00000001
#define RX_4_DMA_START_START_GET(x)                                  (((x) & RX_4_DMA_START_START_MASK) >> RX_4_DMA_START_START_LSB)
#define RX_4_DMA_START_START_SET(x)                                  (((0 | (x)) << RX_4_DMA_START_START_LSB) & RX_4_DMA_START_START_MASK)
#define RX_4_DMA_START_START_RESET                                   0
#define RX_4_DMA_START_ADDRESS                                       0x0084
#define RX_4_DMA_START_HW_MASK                                       0x00000011
#define RX_4_DMA_START_SW_MASK                                       0x00000011
#define RX_4_DMA_START_HW_WRITE_MASK                                 0x00000011
#define RX_4_DMA_START_SW_WRITE_MASK                                 0x00000011
#define RX_4_DMA_START_RSTMASK                                       0xffffffff
#define RX_4_DMA_START_RESET                                         0x00000000

// 0x0088 (RX_4_BURST_SIZE)
#define RX_4_BURST_SIZE_BURST_MSB                                    1
#define RX_4_BURST_SIZE_BURST_LSB                                    0
#define RX_4_BURST_SIZE_BURST_MASK                                   0x00000003
#define RX_4_BURST_SIZE_BURST_GET(x)                                 (((x) & RX_4_BURST_SIZE_BURST_MASK) >> RX_4_BURST_SIZE_BURST_LSB)
#define RX_4_BURST_SIZE_BURST_SET(x)                                 (((0 | (x)) << RX_4_BURST_SIZE_BURST_LSB) & RX_4_BURST_SIZE_BURST_MASK)
#define RX_4_BURST_SIZE_BURST_RESET                                  0
#define RX_4_BURST_SIZE_ADDRESS                                      0x0088
#define RX_4_BURST_SIZE_HW_MASK                                      0x00000003
#define RX_4_BURST_SIZE_SW_MASK                                      0x00000003
#define RX_4_BURST_SIZE_HW_WRITE_MASK                                0x00000000
#define RX_4_BURST_SIZE_SW_WRITE_MASK                                0x00000003
#define RX_4_BURST_SIZE_RSTMASK                                      0xffffffff
#define RX_4_BURST_SIZE_RESET                                        0x00000000

// 0x008c (RX_4_PACKET_OFFSET)
#define RX_4_PACKET_OFFSET_REG_MSB                                   7
#define RX_4_PACKET_OFFSET_REG_LSB                                   0
#define RX_4_PACKET_OFFSET_REG_MASK                                  0x000000ff
#define RX_4_PACKET_OFFSET_REG_GET(x)                                (((x) & RX_4_PACKET_OFFSET_REG_MASK) >> RX_4_PACKET_OFFSET_REG_LSB)
#define RX_4_PACKET_OFFSET_REG_SET(x)                                (((0 | (x)) << RX_4_PACKET_OFFSET_REG_LSB) & RX_4_PACKET_OFFSET_REG_MASK)
#define RX_4_PACKET_OFFSET_REG_RESET                                 0
#define RX_4_PACKET_OFFSET_ADDRESS                                   0x008c
#define RX_4_PACKET_OFFSET_HW_MASK                                   0x000000ff
#define RX_4_PACKET_OFFSET_SW_MASK                                   0x000000ff
#define RX_4_PACKET_OFFSET_HW_WRITE_MASK                             0x00000000
#define RX_4_PACKET_OFFSET_SW_WRITE_MASK                             0x000000ff
#define RX_4_PACKET_OFFSET_RSTMASK                                   0xffffffff
#define RX_4_PACKET_OFFSET_RESET                                     0x00000000

// 0x0090 (RX_4_CHECKSUM)
#define RX_4_CHECKSUM_UDP_MSB                                        1
#define RX_4_CHECKSUM_UDP_LSB                                        1
#define RX_4_CHECKSUM_UDP_MASK                                       0x00000002
#define RX_4_CHECKSUM_UDP_GET(x)                                     (((x) & RX_4_CHECKSUM_UDP_MASK) >> RX_4_CHECKSUM_UDP_LSB)
#define RX_4_CHECKSUM_UDP_SET(x)                                     (((0 | (x)) << RX_4_CHECKSUM_UDP_LSB) & RX_4_CHECKSUM_UDP_MASK)
#define RX_4_CHECKSUM_UDP_RESET                                      0
#define RX_4_CHECKSUM_TCP_MSB                                        0
#define RX_4_CHECKSUM_TCP_LSB                                        0
#define RX_4_CHECKSUM_TCP_MASK                                       0x00000001
#define RX_4_CHECKSUM_TCP_GET(x)                                     (((x) & RX_4_CHECKSUM_TCP_MASK) >> RX_4_CHECKSUM_TCP_LSB)
#define RX_4_CHECKSUM_TCP_SET(x)                                     (((0 | (x)) << RX_4_CHECKSUM_TCP_LSB) & RX_4_CHECKSUM_TCP_MASK)
#define RX_4_CHECKSUM_TCP_RESET                                      0
#define RX_4_CHECKSUM_ADDRESS                                        0x0090
#define RX_4_CHECKSUM_HW_MASK                                        0x00000003
#define RX_4_CHECKSUM_SW_MASK                                        0x00000003
#define RX_4_CHECKSUM_HW_WRITE_MASK                                  0x00000000
#define RX_4_CHECKSUM_SW_WRITE_MASK                                  0x00000003
#define RX_4_CHECKSUM_RSTMASK                                        0xffffffff
#define RX_4_CHECKSUM_RESET                                          0x00000000

// 0x0094 (RX_4_DBG_RX)
#define RX_4_DBG_RX_STATE_MSB                                        3
#define RX_4_DBG_RX_STATE_LSB                                        0
#define RX_4_DBG_RX_STATE_MASK                                       0x0000000f
#define RX_4_DBG_RX_STATE_GET(x)                                     (((x) & RX_4_DBG_RX_STATE_MASK) >> RX_4_DBG_RX_STATE_LSB)
#define RX_4_DBG_RX_STATE_SET(x)                                     (((0 | (x)) << RX_4_DBG_RX_STATE_LSB) & RX_4_DBG_RX_STATE_MASK)
#define RX_4_DBG_RX_STATE_RESET                                      0
#define RX_4_DBG_RX_ADDRESS                                          0x0094
#define RX_4_DBG_RX_HW_MASK                                          0x0000000f
#define RX_4_DBG_RX_SW_MASK                                          0x0000000f
#define RX_4_DBG_RX_HW_WRITE_MASK                                    0x0000000f
#define RX_4_DBG_RX_SW_WRITE_MASK                                    0x00000000
#define RX_4_DBG_RX_RSTMASK                                          0xffffffff
#define RX_4_DBG_RX_RESET                                            0x00000000

// 0x0098 (RX_4_DBG_RX_CUR_ADDR)
#define RX_4_DBG_RX_CUR_ADDR_REG_MSB                                 31
#define RX_4_DBG_RX_CUR_ADDR_REG_LSB                                 0
#define RX_4_DBG_RX_CUR_ADDR_REG_MASK                                0xffffffff
#define RX_4_DBG_RX_CUR_ADDR_REG_GET(x)                              (((x) & RX_4_DBG_RX_CUR_ADDR_REG_MASK) >> RX_4_DBG_RX_CUR_ADDR_REG_LSB)
#define RX_4_DBG_RX_CUR_ADDR_REG_SET(x)                              (((0 | (x)) << RX_4_DBG_RX_CUR_ADDR_REG_LSB) & RX_4_DBG_RX_CUR_ADDR_REG_MASK)
#define RX_4_DBG_RX_CUR_ADDR_REG_RESET                               0
#define RX_4_DBG_RX_CUR_ADDR_ADDRESS                                 0x0098
#define RX_4_DBG_RX_CUR_ADDR_HW_MASK                                 0xffffffff
#define RX_4_DBG_RX_CUR_ADDR_SW_MASK                                 0xffffffff
#define RX_4_DBG_RX_CUR_ADDR_HW_WRITE_MASK                           0xffffffff
#define RX_4_DBG_RX_CUR_ADDR_SW_WRITE_MASK                           0x00000000
#define RX_4_DBG_RX_CUR_ADDR_RSTMASK                                 0xffffffff
#define RX_4_DBG_RX_CUR_ADDR_RESET                                   0x00000000

// 0x009c (RX_4_DATA_SWAP)
#define RX_4_DATA_SWAP_SWAPD_MSB                                     1
#define RX_4_DATA_SWAP_SWAPD_LSB                                     1
#define RX_4_DATA_SWAP_SWAPD_MASK                                    0x00000002
#define RX_4_DATA_SWAP_SWAPD_GET(x)                                  (((x) & RX_4_DATA_SWAP_SWAPD_MASK) >> RX_4_DATA_SWAP_SWAPD_LSB)
#define RX_4_DATA_SWAP_SWAPD_SET(x)                                  (((0 | (x)) << RX_4_DATA_SWAP_SWAPD_LSB) & RX_4_DATA_SWAP_SWAPD_MASK)
#define RX_4_DATA_SWAP_SWAPD_RESET                                   0
#define RX_4_DATA_SWAP_SWAP_MSB                                      0
#define RX_4_DATA_SWAP_SWAP_LSB                                      0
#define RX_4_DATA_SWAP_SWAP_MASK                                     0x00000001
#define RX_4_DATA_SWAP_SWAP_GET(x)                                   (((x) & RX_4_DATA_SWAP_SWAP_MASK) >> RX_4_DATA_SWAP_SWAP_LSB)
#define RX_4_DATA_SWAP_SWAP_SET(x)                                   (((0 | (x)) << RX_4_DATA_SWAP_SWAP_LSB) & RX_4_DATA_SWAP_SWAP_MASK)
#define RX_4_DATA_SWAP_SWAP_RESET                                    1
#define RX_4_DATA_SWAP_ADDRESS                                       0x009c
#define RX_4_DATA_SWAP_HW_MASK                                       0x00000003
#define RX_4_DATA_SWAP_SW_MASK                                       0x00000003
#define RX_4_DATA_SWAP_HW_WRITE_MASK                                 0x00000000
#define RX_4_DATA_SWAP_SW_WRITE_MASK                                 0x00000003
#define RX_4_DATA_SWAP_RSTMASK                                       0xffffffff
#define RX_4_DATA_SWAP_RESET                                         0x00000001

// 0x00a0 (RX_5_DESC_START_ADDRESS)
#define RX_5_DESC_START_ADDRESS_REG_MSB                              31
#define RX_5_DESC_START_ADDRESS_REG_LSB                              0
#define RX_5_DESC_START_ADDRESS_REG_MASK                             0xffffffff
#define RX_5_DESC_START_ADDRESS_REG_GET(x)                           (((x) & RX_5_DESC_START_ADDRESS_REG_MASK) >> RX_5_DESC_START_ADDRESS_REG_LSB)
#define RX_5_DESC_START_ADDRESS_REG_SET(x)                           (((0 | (x)) << RX_5_DESC_START_ADDRESS_REG_LSB) & RX_5_DESC_START_ADDRESS_REG_MASK)
#define RX_5_DESC_START_ADDRESS_REG_RESET                            0
#define RX_5_DESC_START_ADDRESS_ADDRESS                              0x00a0
#define RX_5_DESC_START_ADDRESS_HW_MASK                              0xffffffff
#define RX_5_DESC_START_ADDRESS_SW_MASK                              0xffffffff
#define RX_5_DESC_START_ADDRESS_HW_WRITE_MASK                        0x00000000
#define RX_5_DESC_START_ADDRESS_SW_WRITE_MASK                        0xffffffff
#define RX_5_DESC_START_ADDRESS_RSTMASK                              0xffffffff
#define RX_5_DESC_START_ADDRESS_RESET                                0x00000000

// 0x00a4 (RX_5_DMA_START)
#define RX_5_DMA_START_RESTART_MSB                                   4
#define RX_5_DMA_START_RESTART_LSB                                   4
#define RX_5_DMA_START_RESTART_MASK                                  0x00000010
#define RX_5_DMA_START_RESTART_GET(x)                                (((x) & RX_5_DMA_START_RESTART_MASK) >> RX_5_DMA_START_RESTART_LSB)
#define RX_5_DMA_START_RESTART_SET(x)                                (((0 | (x)) << RX_5_DMA_START_RESTART_LSB) & RX_5_DMA_START_RESTART_MASK)
#define RX_5_DMA_START_RESTART_RESET                                 0
#define RX_5_DMA_START_START_MSB                                     0
#define RX_5_DMA_START_START_LSB                                     0
#define RX_5_DMA_START_START_MASK                                    0x00000001
#define RX_5_DMA_START_START_GET(x)                                  (((x) & RX_5_DMA_START_START_MASK) >> RX_5_DMA_START_START_LSB)
#define RX_5_DMA_START_START_SET(x)                                  (((0 | (x)) << RX_5_DMA_START_START_LSB) & RX_5_DMA_START_START_MASK)
#define RX_5_DMA_START_START_RESET                                   0
#define RX_5_DMA_START_ADDRESS                                       0x00a4
#define RX_5_DMA_START_HW_MASK                                       0x00000011
#define RX_5_DMA_START_SW_MASK                                       0x00000011
#define RX_5_DMA_START_HW_WRITE_MASK                                 0x00000011
#define RX_5_DMA_START_SW_WRITE_MASK                                 0x00000011
#define RX_5_DMA_START_RSTMASK                                       0xffffffff
#define RX_5_DMA_START_RESET                                         0x00000000

// 0x00a8 (RX_5_BURST_SIZE)
#define RX_5_BURST_SIZE_BURST_MSB                                    1
#define RX_5_BURST_SIZE_BURST_LSB                                    0
#define RX_5_BURST_SIZE_BURST_MASK                                   0x00000003
#define RX_5_BURST_SIZE_BURST_GET(x)                                 (((x) & RX_5_BURST_SIZE_BURST_MASK) >> RX_5_BURST_SIZE_BURST_LSB)
#define RX_5_BURST_SIZE_BURST_SET(x)                                 (((0 | (x)) << RX_5_BURST_SIZE_BURST_LSB) & RX_5_BURST_SIZE_BURST_MASK)
#define RX_5_BURST_SIZE_BURST_RESET                                  0
#define RX_5_BURST_SIZE_ADDRESS                                      0x00a8
#define RX_5_BURST_SIZE_HW_MASK                                      0x00000003
#define RX_5_BURST_SIZE_SW_MASK                                      0x00000003
#define RX_5_BURST_SIZE_HW_WRITE_MASK                                0x00000000
#define RX_5_BURST_SIZE_SW_WRITE_MASK                                0x00000003
#define RX_5_BURST_SIZE_RSTMASK                                      0xffffffff
#define RX_5_BURST_SIZE_RESET                                        0x00000000

// 0x00ac (RX_5_PACKET_OFFSET)
#define RX_5_PACKET_OFFSET_REG_MSB                                   7
#define RX_5_PACKET_OFFSET_REG_LSB                                   0
#define RX_5_PACKET_OFFSET_REG_MASK                                  0x000000ff
#define RX_5_PACKET_OFFSET_REG_GET(x)                                (((x) & RX_5_PACKET_OFFSET_REG_MASK) >> RX_5_PACKET_OFFSET_REG_LSB)
#define RX_5_PACKET_OFFSET_REG_SET(x)                                (((0 | (x)) << RX_5_PACKET_OFFSET_REG_LSB) & RX_5_PACKET_OFFSET_REG_MASK)
#define RX_5_PACKET_OFFSET_REG_RESET                                 0
#define RX_5_PACKET_OFFSET_ADDRESS                                   0x00ac
#define RX_5_PACKET_OFFSET_HW_MASK                                   0x000000ff
#define RX_5_PACKET_OFFSET_SW_MASK                                   0x000000ff
#define RX_5_PACKET_OFFSET_HW_WRITE_MASK                             0x00000000
#define RX_5_PACKET_OFFSET_SW_WRITE_MASK                             0x000000ff
#define RX_5_PACKET_OFFSET_RSTMASK                                   0xffffffff
#define RX_5_PACKET_OFFSET_RESET                                     0x00000000

// 0x00b0 (RX_5_CHECKSUM)
#define RX_5_CHECKSUM_UDP_MSB                                        1
#define RX_5_CHECKSUM_UDP_LSB                                        1
#define RX_5_CHECKSUM_UDP_MASK                                       0x00000002
#define RX_5_CHECKSUM_UDP_GET(x)                                     (((x) & RX_5_CHECKSUM_UDP_MASK) >> RX_5_CHECKSUM_UDP_LSB)
#define RX_5_CHECKSUM_UDP_SET(x)                                     (((0 | (x)) << RX_5_CHECKSUM_UDP_LSB) & RX_5_CHECKSUM_UDP_MASK)
#define RX_5_CHECKSUM_UDP_RESET                                      0
#define RX_5_CHECKSUM_TCP_MSB                                        0
#define RX_5_CHECKSUM_TCP_LSB                                        0
#define RX_5_CHECKSUM_TCP_MASK                                       0x00000001
#define RX_5_CHECKSUM_TCP_GET(x)                                     (((x) & RX_5_CHECKSUM_TCP_MASK) >> RX_5_CHECKSUM_TCP_LSB)
#define RX_5_CHECKSUM_TCP_SET(x)                                     (((0 | (x)) << RX_5_CHECKSUM_TCP_LSB) & RX_5_CHECKSUM_TCP_MASK)
#define RX_5_CHECKSUM_TCP_RESET                                      0
#define RX_5_CHECKSUM_ADDRESS                                        0x00b0
#define RX_5_CHECKSUM_HW_MASK                                        0x00000003
#define RX_5_CHECKSUM_SW_MASK                                        0x00000003
#define RX_5_CHECKSUM_HW_WRITE_MASK                                  0x00000000
#define RX_5_CHECKSUM_SW_WRITE_MASK                                  0x00000003
#define RX_5_CHECKSUM_RSTMASK                                        0xffffffff
#define RX_5_CHECKSUM_RESET                                          0x00000000

// 0x00b4 (RX_5_DBG_RX)
#define RX_5_DBG_RX_STATE_MSB                                        3
#define RX_5_DBG_RX_STATE_LSB                                        0
#define RX_5_DBG_RX_STATE_MASK                                       0x0000000f
#define RX_5_DBG_RX_STATE_GET(x)                                     (((x) & RX_5_DBG_RX_STATE_MASK) >> RX_5_DBG_RX_STATE_LSB)
#define RX_5_DBG_RX_STATE_SET(x)                                     (((0 | (x)) << RX_5_DBG_RX_STATE_LSB) & RX_5_DBG_RX_STATE_MASK)
#define RX_5_DBG_RX_STATE_RESET                                      0
#define RX_5_DBG_RX_ADDRESS                                          0x00b4
#define RX_5_DBG_RX_HW_MASK                                          0x0000000f
#define RX_5_DBG_RX_SW_MASK                                          0x0000000f
#define RX_5_DBG_RX_HW_WRITE_MASK                                    0x0000000f
#define RX_5_DBG_RX_SW_WRITE_MASK                                    0x00000000
#define RX_5_DBG_RX_RSTMASK                                          0xffffffff
#define RX_5_DBG_RX_RESET                                            0x00000000

// 0x00b8 (RX_5_DBG_RX_CUR_ADDR)
#define RX_5_DBG_RX_CUR_ADDR_REG_MSB                                 31
#define RX_5_DBG_RX_CUR_ADDR_REG_LSB                                 0
#define RX_5_DBG_RX_CUR_ADDR_REG_MASK                                0xffffffff
#define RX_5_DBG_RX_CUR_ADDR_REG_GET(x)                              (((x) & RX_5_DBG_RX_CUR_ADDR_REG_MASK) >> RX_5_DBG_RX_CUR_ADDR_REG_LSB)
#define RX_5_DBG_RX_CUR_ADDR_REG_SET(x)                              (((0 | (x)) << RX_5_DBG_RX_CUR_ADDR_REG_LSB) & RX_5_DBG_RX_CUR_ADDR_REG_MASK)
#define RX_5_DBG_RX_CUR_ADDR_REG_RESET                               0
#define RX_5_DBG_RX_CUR_ADDR_ADDRESS                                 0x00b8
#define RX_5_DBG_RX_CUR_ADDR_HW_MASK                                 0xffffffff
#define RX_5_DBG_RX_CUR_ADDR_SW_MASK                                 0xffffffff
#define RX_5_DBG_RX_CUR_ADDR_HW_WRITE_MASK                           0xffffffff
#define RX_5_DBG_RX_CUR_ADDR_SW_WRITE_MASK                           0x00000000
#define RX_5_DBG_RX_CUR_ADDR_RSTMASK                                 0xffffffff
#define RX_5_DBG_RX_CUR_ADDR_RESET                                   0x00000000

// 0x00bc (RX_5_DATA_SWAP)
#define RX_5_DATA_SWAP_SWAPD_MSB                                     1
#define RX_5_DATA_SWAP_SWAPD_LSB                                     1
#define RX_5_DATA_SWAP_SWAPD_MASK                                    0x00000002
#define RX_5_DATA_SWAP_SWAPD_GET(x)                                  (((x) & RX_5_DATA_SWAP_SWAPD_MASK) >> RX_5_DATA_SWAP_SWAPD_LSB)
#define RX_5_DATA_SWAP_SWAPD_SET(x)                                  (((0 | (x)) << RX_5_DATA_SWAP_SWAPD_LSB) & RX_5_DATA_SWAP_SWAPD_MASK)
#define RX_5_DATA_SWAP_SWAPD_RESET                                   0
#define RX_5_DATA_SWAP_SWAP_MSB                                      0
#define RX_5_DATA_SWAP_SWAP_LSB                                      0
#define RX_5_DATA_SWAP_SWAP_MASK                                     0x00000001
#define RX_5_DATA_SWAP_SWAP_GET(x)                                   (((x) & RX_5_DATA_SWAP_SWAP_MASK) >> RX_5_DATA_SWAP_SWAP_LSB)
#define RX_5_DATA_SWAP_SWAP_SET(x)                                   (((0 | (x)) << RX_5_DATA_SWAP_SWAP_LSB) & RX_5_DATA_SWAP_SWAP_MASK)
#define RX_5_DATA_SWAP_SWAP_RESET                                    1
#define RX_5_DATA_SWAP_ADDRESS                                       0x00bc
#define RX_5_DATA_SWAP_HW_MASK                                       0x00000003
#define RX_5_DATA_SWAP_SW_MASK                                       0x00000003
#define RX_5_DATA_SWAP_HW_WRITE_MASK                                 0x00000000
#define RX_5_DATA_SWAP_SW_WRITE_MASK                                 0x00000003
#define RX_5_DATA_SWAP_RSTMASK                                       0xffffffff
#define RX_5_DATA_SWAP_RESET                                         0x00000001

// 0x00c0 (TX_0_DESC_START_ADDRESS)
#define TX_0_DESC_START_ADDRESS_REG_MSB                              31
#define TX_0_DESC_START_ADDRESS_REG_LSB                              0
#define TX_0_DESC_START_ADDRESS_REG_MASK                             0xffffffff
#define TX_0_DESC_START_ADDRESS_REG_GET(x)                           (((x) & TX_0_DESC_START_ADDRESS_REG_MASK) >> TX_0_DESC_START_ADDRESS_REG_LSB)
#define TX_0_DESC_START_ADDRESS_REG_SET(x)                           (((0 | (x)) << TX_0_DESC_START_ADDRESS_REG_LSB) & TX_0_DESC_START_ADDRESS_REG_MASK)
#define TX_0_DESC_START_ADDRESS_REG_RESET                            0
#define TX_0_DESC_START_ADDRESS_ADDRESS                              0x00c0
#define TX_0_DESC_START_ADDRESS_HW_MASK                              0xffffffff
#define TX_0_DESC_START_ADDRESS_SW_MASK                              0xffffffff
#define TX_0_DESC_START_ADDRESS_HW_WRITE_MASK                        0x00000000
#define TX_0_DESC_START_ADDRESS_SW_WRITE_MASK                        0xffffffff
#define TX_0_DESC_START_ADDRESS_RSTMASK                              0xffffffff
#define TX_0_DESC_START_ADDRESS_RESET                                0x00000000

// 0x00c4 (TX_0_DMA_START)
#define TX_0_DMA_START_RESTART_MSB                                   4
#define TX_0_DMA_START_RESTART_LSB                                   4
#define TX_0_DMA_START_RESTART_MASK                                  0x00000010
#define TX_0_DMA_START_RESTART_GET(x)                                (((x) & TX_0_DMA_START_RESTART_MASK) >> TX_0_DMA_START_RESTART_LSB)
#define TX_0_DMA_START_RESTART_SET(x)                                (((0 | (x)) << TX_0_DMA_START_RESTART_LSB) & TX_0_DMA_START_RESTART_MASK)
#define TX_0_DMA_START_RESTART_RESET                                 0
#define TX_0_DMA_START_START_MSB                                     0
#define TX_0_DMA_START_START_LSB                                     0
#define TX_0_DMA_START_START_MASK                                    0x00000001
#define TX_0_DMA_START_START_GET(x)                                  (((x) & TX_0_DMA_START_START_MASK) >> TX_0_DMA_START_START_LSB)
#define TX_0_DMA_START_START_SET(x)                                  (((0 | (x)) << TX_0_DMA_START_START_LSB) & TX_0_DMA_START_START_MASK)
#define TX_0_DMA_START_START_RESET                                   0
#define TX_0_DMA_START_ADDRESS                                       0x00c4
#define TX_0_DMA_START_HW_MASK                                       0x00000011
#define TX_0_DMA_START_SW_MASK                                       0x00000011
#define TX_0_DMA_START_HW_WRITE_MASK                                 0x00000011
#define TX_0_DMA_START_SW_WRITE_MASK                                 0x00000011
#define TX_0_DMA_START_RSTMASK                                       0xffffffff
#define TX_0_DMA_START_RESET                                         0x00000000

// 0x00c8 (TX_0_INTERRUPT_LIMIT)
#define TX_0_INTERRUPT_LIMIT_TIMEOUT_MSB                             15
#define TX_0_INTERRUPT_LIMIT_TIMEOUT_LSB                             4
#define TX_0_INTERRUPT_LIMIT_TIMEOUT_MASK                            0x0000fff0
#define TX_0_INTERRUPT_LIMIT_TIMEOUT_GET(x)                          (((x) & TX_0_INTERRUPT_LIMIT_TIMEOUT_MASK) >> TX_0_INTERRUPT_LIMIT_TIMEOUT_LSB)
#define TX_0_INTERRUPT_LIMIT_TIMEOUT_SET(x)                          (((0 | (x)) << TX_0_INTERRUPT_LIMIT_TIMEOUT_LSB) & TX_0_INTERRUPT_LIMIT_TIMEOUT_MASK)
#define TX_0_INTERRUPT_LIMIT_TIMEOUT_RESET                           0
#define TX_0_INTERRUPT_LIMIT_COUNT_MSB                               3
#define TX_0_INTERRUPT_LIMIT_COUNT_LSB                               0
#define TX_0_INTERRUPT_LIMIT_COUNT_MASK                              0x0000000f
#define TX_0_INTERRUPT_LIMIT_COUNT_GET(x)                            (((x) & TX_0_INTERRUPT_LIMIT_COUNT_MASK) >> TX_0_INTERRUPT_LIMIT_COUNT_LSB)
#define TX_0_INTERRUPT_LIMIT_COUNT_SET(x)                            (((0 | (x)) << TX_0_INTERRUPT_LIMIT_COUNT_LSB) & TX_0_INTERRUPT_LIMIT_COUNT_MASK)
#define TX_0_INTERRUPT_LIMIT_COUNT_RESET                             1
#define TX_0_INTERRUPT_LIMIT_ADDRESS                                 0x00c8
#define TX_0_INTERRUPT_LIMIT_HW_MASK                                 0x0000ffff
#define TX_0_INTERRUPT_LIMIT_SW_MASK                                 0x0000ffff
#define TX_0_INTERRUPT_LIMIT_HW_WRITE_MASK                           0x00000000
#define TX_0_INTERRUPT_LIMIT_SW_WRITE_MASK                           0x0000ffff
#define TX_0_INTERRUPT_LIMIT_RSTMASK                                 0xffffffff
#define TX_0_INTERRUPT_LIMIT_RESET                                   0x00000001

// 0x00cc (TX_0_BURST_SIZE)
#define TX_0_BURST_SIZE_BURST_MSB                                    1
#define TX_0_BURST_SIZE_BURST_LSB                                    0
#define TX_0_BURST_SIZE_BURST_MASK                                   0x00000003
#define TX_0_BURST_SIZE_BURST_GET(x)                                 (((x) & TX_0_BURST_SIZE_BURST_MASK) >> TX_0_BURST_SIZE_BURST_LSB)
#define TX_0_BURST_SIZE_BURST_SET(x)                                 (((0 | (x)) << TX_0_BURST_SIZE_BURST_LSB) & TX_0_BURST_SIZE_BURST_MASK)
#define TX_0_BURST_SIZE_BURST_RESET                                  0
#define TX_0_BURST_SIZE_ADDRESS                                      0x00cc
#define TX_0_BURST_SIZE_HW_MASK                                      0x00000003
#define TX_0_BURST_SIZE_SW_MASK                                      0x00000003
#define TX_0_BURST_SIZE_HW_WRITE_MASK                                0x00000000
#define TX_0_BURST_SIZE_SW_WRITE_MASK                                0x00000003
#define TX_0_BURST_SIZE_RSTMASK                                      0xffffffff
#define TX_0_BURST_SIZE_RESET                                        0x00000000

// 0x00d0 (TX_0_DBG_TX)
#define TX_0_DBG_TX_FIFO_TOTAL_LEN_MSB                               31
#define TX_0_DBG_TX_FIFO_TOTAL_LEN_LSB                               16
#define TX_0_DBG_TX_FIFO_TOTAL_LEN_MASK                              0xffff0000
#define TX_0_DBG_TX_FIFO_TOTAL_LEN_GET(x)                            (((x) & TX_0_DBG_TX_FIFO_TOTAL_LEN_MASK) >> TX_0_DBG_TX_FIFO_TOTAL_LEN_LSB)
#define TX_0_DBG_TX_FIFO_TOTAL_LEN_SET(x)                            (((0 | (x)) << TX_0_DBG_TX_FIFO_TOTAL_LEN_LSB) & TX_0_DBG_TX_FIFO_TOTAL_LEN_MASK)
#define TX_0_DBG_TX_FIFO_TOTAL_LEN_RESET                             0
#define TX_0_DBG_TX_FIFO_WATERMARK_MSB                               15
#define TX_0_DBG_TX_FIFO_WATERMARK_LSB                               3
#define TX_0_DBG_TX_FIFO_WATERMARK_MASK                              0x0000fff8
#define TX_0_DBG_TX_FIFO_WATERMARK_GET(x)                            (((x) & TX_0_DBG_TX_FIFO_WATERMARK_MASK) >> TX_0_DBG_TX_FIFO_WATERMARK_LSB)
#define TX_0_DBG_TX_FIFO_WATERMARK_SET(x)                            (((0 | (x)) << TX_0_DBG_TX_FIFO_WATERMARK_LSB) & TX_0_DBG_TX_FIFO_WATERMARK_MASK)
#define TX_0_DBG_TX_FIFO_WATERMARK_RESET                             0
#define TX_0_DBG_TX_STATE_MSB                                        2
#define TX_0_DBG_TX_STATE_LSB                                        0
#define TX_0_DBG_TX_STATE_MASK                                       0x00000007
#define TX_0_DBG_TX_STATE_GET(x)                                     (((x) & TX_0_DBG_TX_STATE_MASK) >> TX_0_DBG_TX_STATE_LSB)
#define TX_0_DBG_TX_STATE_SET(x)                                     (((0 | (x)) << TX_0_DBG_TX_STATE_LSB) & TX_0_DBG_TX_STATE_MASK)
#define TX_0_DBG_TX_STATE_RESET                                      0
#define TX_0_DBG_TX_ADDRESS                                          0x00d0
#define TX_0_DBG_TX_HW_MASK                                          0xffffffff
#define TX_0_DBG_TX_SW_MASK                                          0xffffffff
#define TX_0_DBG_TX_HW_WRITE_MASK                                    0xffff0007
#define TX_0_DBG_TX_SW_WRITE_MASK                                    0x0000fff8
#define TX_0_DBG_TX_RSTMASK                                          0xffffffff
#define TX_0_DBG_TX_RESET                                            0x00000000

// 0x00d4 (TX_0_DBG_TX_CUR_ADDR)
#define TX_0_DBG_TX_CUR_ADDR_REG_MSB                                 31
#define TX_0_DBG_TX_CUR_ADDR_REG_LSB                                 0
#define TX_0_DBG_TX_CUR_ADDR_REG_MASK                                0xffffffff
#define TX_0_DBG_TX_CUR_ADDR_REG_GET(x)                              (((x) & TX_0_DBG_TX_CUR_ADDR_REG_MASK) >> TX_0_DBG_TX_CUR_ADDR_REG_LSB)
#define TX_0_DBG_TX_CUR_ADDR_REG_SET(x)                              (((0 | (x)) << TX_0_DBG_TX_CUR_ADDR_REG_LSB) & TX_0_DBG_TX_CUR_ADDR_REG_MASK)
#define TX_0_DBG_TX_CUR_ADDR_REG_RESET                               0
#define TX_0_DBG_TX_CUR_ADDR_ADDRESS                                 0x00d4
#define TX_0_DBG_TX_CUR_ADDR_HW_MASK                                 0xffffffff
#define TX_0_DBG_TX_CUR_ADDR_SW_MASK                                 0xffffffff
#define TX_0_DBG_TX_CUR_ADDR_HW_WRITE_MASK                           0xffffffff
#define TX_0_DBG_TX_CUR_ADDR_SW_WRITE_MASK                           0x00000000
#define TX_0_DBG_TX_CUR_ADDR_RSTMASK                                 0xffffffff
#define TX_0_DBG_TX_CUR_ADDR_RESET                                   0x00000000

// 0x00d8 (TX_0_DATA_SWAP)
#define TX_0_DATA_SWAP_SWAPD_MSB                                     1
#define TX_0_DATA_SWAP_SWAPD_LSB                                     1
#define TX_0_DATA_SWAP_SWAPD_MASK                                    0x00000002
#define TX_0_DATA_SWAP_SWAPD_GET(x)                                  (((x) & TX_0_DATA_SWAP_SWAPD_MASK) >> TX_0_DATA_SWAP_SWAPD_LSB)
#define TX_0_DATA_SWAP_SWAPD_SET(x)                                  (((0 | (x)) << TX_0_DATA_SWAP_SWAPD_LSB) & TX_0_DATA_SWAP_SWAPD_MASK)
#define TX_0_DATA_SWAP_SWAPD_RESET                                   0
#define TX_0_DATA_SWAP_SWAP_MSB                                      0
#define TX_0_DATA_SWAP_SWAP_LSB                                      0
#define TX_0_DATA_SWAP_SWAP_MASK                                     0x00000001
#define TX_0_DATA_SWAP_SWAP_GET(x)                                   (((x) & TX_0_DATA_SWAP_SWAP_MASK) >> TX_0_DATA_SWAP_SWAP_LSB)
#define TX_0_DATA_SWAP_SWAP_SET(x)                                   (((0 | (x)) << TX_0_DATA_SWAP_SWAP_LSB) & TX_0_DATA_SWAP_SWAP_MASK)
#define TX_0_DATA_SWAP_SWAP_RESET                                    1
#define TX_0_DATA_SWAP_ADDRESS                                       0x00d8
#define TX_0_DATA_SWAP_HW_MASK                                       0x00000003
#define TX_0_DATA_SWAP_SW_MASK                                       0x00000003
#define TX_0_DATA_SWAP_HW_WRITE_MASK                                 0x00000000
#define TX_0_DATA_SWAP_SW_WRITE_MASK                                 0x00000003
#define TX_0_DATA_SWAP_RSTMASK                                       0xffffffff
#define TX_0_DATA_SWAP_RESET                                         0x00000001

// 0x00dc (TX_1_DESC_START_ADDRESS)
#define TX_1_DESC_START_ADDRESS_REG_MSB                              31
#define TX_1_DESC_START_ADDRESS_REG_LSB                              0
#define TX_1_DESC_START_ADDRESS_REG_MASK                             0xffffffff
#define TX_1_DESC_START_ADDRESS_REG_GET(x)                           (((x) & TX_1_DESC_START_ADDRESS_REG_MASK) >> TX_1_DESC_START_ADDRESS_REG_LSB)
#define TX_1_DESC_START_ADDRESS_REG_SET(x)                           (((0 | (x)) << TX_1_DESC_START_ADDRESS_REG_LSB) & TX_1_DESC_START_ADDRESS_REG_MASK)
#define TX_1_DESC_START_ADDRESS_REG_RESET                            0
#define TX_1_DESC_START_ADDRESS_ADDRESS                              0x00dc
#define TX_1_DESC_START_ADDRESS_HW_MASK                              0xffffffff
#define TX_1_DESC_START_ADDRESS_SW_MASK                              0xffffffff
#define TX_1_DESC_START_ADDRESS_HW_WRITE_MASK                        0x00000000
#define TX_1_DESC_START_ADDRESS_SW_WRITE_MASK                        0xffffffff
#define TX_1_DESC_START_ADDRESS_RSTMASK                              0xffffffff
#define TX_1_DESC_START_ADDRESS_RESET                                0x00000000

// 0x00e0 (TX_1_DMA_START)
#define TX_1_DMA_START_RESTART_MSB                                   4
#define TX_1_DMA_START_RESTART_LSB                                   4
#define TX_1_DMA_START_RESTART_MASK                                  0x00000010
#define TX_1_DMA_START_RESTART_GET(x)                                (((x) & TX_1_DMA_START_RESTART_MASK) >> TX_1_DMA_START_RESTART_LSB)
#define TX_1_DMA_START_RESTART_SET(x)                                (((0 | (x)) << TX_1_DMA_START_RESTART_LSB) & TX_1_DMA_START_RESTART_MASK)
#define TX_1_DMA_START_RESTART_RESET                                 0
#define TX_1_DMA_START_START_MSB                                     0
#define TX_1_DMA_START_START_LSB                                     0
#define TX_1_DMA_START_START_MASK                                    0x00000001
#define TX_1_DMA_START_START_GET(x)                                  (((x) & TX_1_DMA_START_START_MASK) >> TX_1_DMA_START_START_LSB)
#define TX_1_DMA_START_START_SET(x)                                  (((0 | (x)) << TX_1_DMA_START_START_LSB) & TX_1_DMA_START_START_MASK)
#define TX_1_DMA_START_START_RESET                                   0
#define TX_1_DMA_START_ADDRESS                                       0x00e0
#define TX_1_DMA_START_HW_MASK                                       0x00000011
#define TX_1_DMA_START_SW_MASK                                       0x00000011
#define TX_1_DMA_START_HW_WRITE_MASK                                 0x00000011
#define TX_1_DMA_START_SW_WRITE_MASK                                 0x00000011
#define TX_1_DMA_START_RSTMASK                                       0xffffffff
#define TX_1_DMA_START_RESET                                         0x00000000

// 0x00e4 (TX_1_INTERRUPT_LIMIT)
#define TX_1_INTERRUPT_LIMIT_TIMEOUT_MSB                             15
#define TX_1_INTERRUPT_LIMIT_TIMEOUT_LSB                             4
#define TX_1_INTERRUPT_LIMIT_TIMEOUT_MASK                            0x0000fff0
#define TX_1_INTERRUPT_LIMIT_TIMEOUT_GET(x)                          (((x) & TX_1_INTERRUPT_LIMIT_TIMEOUT_MASK) >> TX_1_INTERRUPT_LIMIT_TIMEOUT_LSB)
#define TX_1_INTERRUPT_LIMIT_TIMEOUT_SET(x)                          (((0 | (x)) << TX_1_INTERRUPT_LIMIT_TIMEOUT_LSB) & TX_1_INTERRUPT_LIMIT_TIMEOUT_MASK)
#define TX_1_INTERRUPT_LIMIT_TIMEOUT_RESET                           0
#define TX_1_INTERRUPT_LIMIT_COUNT_MSB                               3
#define TX_1_INTERRUPT_LIMIT_COUNT_LSB                               0
#define TX_1_INTERRUPT_LIMIT_COUNT_MASK                              0x0000000f
#define TX_1_INTERRUPT_LIMIT_COUNT_GET(x)                            (((x) & TX_1_INTERRUPT_LIMIT_COUNT_MASK) >> TX_1_INTERRUPT_LIMIT_COUNT_LSB)
#define TX_1_INTERRUPT_LIMIT_COUNT_SET(x)                            (((0 | (x)) << TX_1_INTERRUPT_LIMIT_COUNT_LSB) & TX_1_INTERRUPT_LIMIT_COUNT_MASK)
#define TX_1_INTERRUPT_LIMIT_COUNT_RESET                             1
#define TX_1_INTERRUPT_LIMIT_ADDRESS                                 0x00e4
#define TX_1_INTERRUPT_LIMIT_HW_MASK                                 0x0000ffff
#define TX_1_INTERRUPT_LIMIT_SW_MASK                                 0x0000ffff
#define TX_1_INTERRUPT_LIMIT_HW_WRITE_MASK                           0x00000000
#define TX_1_INTERRUPT_LIMIT_SW_WRITE_MASK                           0x0000ffff
#define TX_1_INTERRUPT_LIMIT_RSTMASK                                 0xffffffff
#define TX_1_INTERRUPT_LIMIT_RESET                                   0x00000001

// 0x00e8 (TX_1_BURST_SIZE)
#define TX_1_BURST_SIZE_BURST_MSB                                    1
#define TX_1_BURST_SIZE_BURST_LSB                                    0
#define TX_1_BURST_SIZE_BURST_MASK                                   0x00000003
#define TX_1_BURST_SIZE_BURST_GET(x)                                 (((x) & TX_1_BURST_SIZE_BURST_MASK) >> TX_1_BURST_SIZE_BURST_LSB)
#define TX_1_BURST_SIZE_BURST_SET(x)                                 (((0 | (x)) << TX_1_BURST_SIZE_BURST_LSB) & TX_1_BURST_SIZE_BURST_MASK)
#define TX_1_BURST_SIZE_BURST_RESET                                  0
#define TX_1_BURST_SIZE_ADDRESS                                      0x00e8
#define TX_1_BURST_SIZE_HW_MASK                                      0x00000003
#define TX_1_BURST_SIZE_SW_MASK                                      0x00000003
#define TX_1_BURST_SIZE_HW_WRITE_MASK                                0x00000000
#define TX_1_BURST_SIZE_SW_WRITE_MASK                                0x00000003
#define TX_1_BURST_SIZE_RSTMASK                                      0xffffffff
#define TX_1_BURST_SIZE_RESET                                        0x00000000

// 0x00ec (TX_1_DBG_TX)
#define TX_1_DBG_TX_FIFO_TOTAL_LEN_MSB                               31
#define TX_1_DBG_TX_FIFO_TOTAL_LEN_LSB                               16
#define TX_1_DBG_TX_FIFO_TOTAL_LEN_MASK                              0xffff0000
#define TX_1_DBG_TX_FIFO_TOTAL_LEN_GET(x)                            (((x) & TX_1_DBG_TX_FIFO_TOTAL_LEN_MASK) >> TX_1_DBG_TX_FIFO_TOTAL_LEN_LSB)
#define TX_1_DBG_TX_FIFO_TOTAL_LEN_SET(x)                            (((0 | (x)) << TX_1_DBG_TX_FIFO_TOTAL_LEN_LSB) & TX_1_DBG_TX_FIFO_TOTAL_LEN_MASK)
#define TX_1_DBG_TX_FIFO_TOTAL_LEN_RESET                             0
#define TX_1_DBG_TX_FIFO_WATERMARK_MSB                               15
#define TX_1_DBG_TX_FIFO_WATERMARK_LSB                               3
#define TX_1_DBG_TX_FIFO_WATERMARK_MASK                              0x0000fff8
#define TX_1_DBG_TX_FIFO_WATERMARK_GET(x)                            (((x) & TX_1_DBG_TX_FIFO_WATERMARK_MASK) >> TX_1_DBG_TX_FIFO_WATERMARK_LSB)
#define TX_1_DBG_TX_FIFO_WATERMARK_SET(x)                            (((0 | (x)) << TX_1_DBG_TX_FIFO_WATERMARK_LSB) & TX_1_DBG_TX_FIFO_WATERMARK_MASK)
#define TX_1_DBG_TX_FIFO_WATERMARK_RESET                             0
#define TX_1_DBG_TX_STATE_MSB                                        2
#define TX_1_DBG_TX_STATE_LSB                                        0
#define TX_1_DBG_TX_STATE_MASK                                       0x00000007
#define TX_1_DBG_TX_STATE_GET(x)                                     (((x) & TX_1_DBG_TX_STATE_MASK) >> TX_1_DBG_TX_STATE_LSB)
#define TX_1_DBG_TX_STATE_SET(x)                                     (((0 | (x)) << TX_1_DBG_TX_STATE_LSB) & TX_1_DBG_TX_STATE_MASK)
#define TX_1_DBG_TX_STATE_RESET                                      0
#define TX_1_DBG_TX_ADDRESS                                          0x00ec
#define TX_1_DBG_TX_HW_MASK                                          0xffffffff
#define TX_1_DBG_TX_SW_MASK                                          0xffffffff
#define TX_1_DBG_TX_HW_WRITE_MASK                                    0xffff0007
#define TX_1_DBG_TX_SW_WRITE_MASK                                    0x0000fff8
#define TX_1_DBG_TX_RSTMASK                                          0xffffffff
#define TX_1_DBG_TX_RESET                                            0x00000000

// 0x00f0 (TX_1_DBG_TX_CUR_ADDR)
#define TX_1_DBG_TX_CUR_ADDR_REG_MSB                                 31
#define TX_1_DBG_TX_CUR_ADDR_REG_LSB                                 0
#define TX_1_DBG_TX_CUR_ADDR_REG_MASK                                0xffffffff
#define TX_1_DBG_TX_CUR_ADDR_REG_GET(x)                              (((x) & TX_1_DBG_TX_CUR_ADDR_REG_MASK) >> TX_1_DBG_TX_CUR_ADDR_REG_LSB)
#define TX_1_DBG_TX_CUR_ADDR_REG_SET(x)                              (((0 | (x)) << TX_1_DBG_TX_CUR_ADDR_REG_LSB) & TX_1_DBG_TX_CUR_ADDR_REG_MASK)
#define TX_1_DBG_TX_CUR_ADDR_REG_RESET                               0
#define TX_1_DBG_TX_CUR_ADDR_ADDRESS                                 0x00f0
#define TX_1_DBG_TX_CUR_ADDR_HW_MASK                                 0xffffffff
#define TX_1_DBG_TX_CUR_ADDR_SW_MASK                                 0xffffffff
#define TX_1_DBG_TX_CUR_ADDR_HW_WRITE_MASK                           0xffffffff
#define TX_1_DBG_TX_CUR_ADDR_SW_WRITE_MASK                           0x00000000
#define TX_1_DBG_TX_CUR_ADDR_RSTMASK                                 0xffffffff
#define TX_1_DBG_TX_CUR_ADDR_RESET                                   0x00000000

// 0x00f4 (TX_1_DATA_SWAP)
#define TX_1_DATA_SWAP_SWAPD_MSB                                     1
#define TX_1_DATA_SWAP_SWAPD_LSB                                     1
#define TX_1_DATA_SWAP_SWAPD_MASK                                    0x00000002
#define TX_1_DATA_SWAP_SWAPD_GET(x)                                  (((x) & TX_1_DATA_SWAP_SWAPD_MASK) >> TX_1_DATA_SWAP_SWAPD_LSB)
#define TX_1_DATA_SWAP_SWAPD_SET(x)                                  (((0 | (x)) << TX_1_DATA_SWAP_SWAPD_LSB) & TX_1_DATA_SWAP_SWAPD_MASK)
#define TX_1_DATA_SWAP_SWAPD_RESET                                   0
#define TX_1_DATA_SWAP_SWAP_MSB                                      0
#define TX_1_DATA_SWAP_SWAP_LSB                                      0
#define TX_1_DATA_SWAP_SWAP_MASK                                     0x00000001
#define TX_1_DATA_SWAP_SWAP_GET(x)                                   (((x) & TX_1_DATA_SWAP_SWAP_MASK) >> TX_1_DATA_SWAP_SWAP_LSB)
#define TX_1_DATA_SWAP_SWAP_SET(x)                                   (((0 | (x)) << TX_1_DATA_SWAP_SWAP_LSB) & TX_1_DATA_SWAP_SWAP_MASK)
#define TX_1_DATA_SWAP_SWAP_RESET                                    1
#define TX_1_DATA_SWAP_ADDRESS                                       0x00f4
#define TX_1_DATA_SWAP_HW_MASK                                       0x00000003
#define TX_1_DATA_SWAP_SW_MASK                                       0x00000003
#define TX_1_DATA_SWAP_HW_WRITE_MASK                                 0x00000000
#define TX_1_DATA_SWAP_SW_WRITE_MASK                                 0x00000003
#define TX_1_DATA_SWAP_RSTMASK                                       0xffffffff
#define TX_1_DATA_SWAP_RESET                                         0x00000001

// 0x00f8 (TX_2_DESC_START_ADDRESS)
#define TX_2_DESC_START_ADDRESS_REG_MSB                              31
#define TX_2_DESC_START_ADDRESS_REG_LSB                              0
#define TX_2_DESC_START_ADDRESS_REG_MASK                             0xffffffff
#define TX_2_DESC_START_ADDRESS_REG_GET(x)                           (((x) & TX_2_DESC_START_ADDRESS_REG_MASK) >> TX_2_DESC_START_ADDRESS_REG_LSB)
#define TX_2_DESC_START_ADDRESS_REG_SET(x)                           (((0 | (x)) << TX_2_DESC_START_ADDRESS_REG_LSB) & TX_2_DESC_START_ADDRESS_REG_MASK)
#define TX_2_DESC_START_ADDRESS_REG_RESET                            0
#define TX_2_DESC_START_ADDRESS_ADDRESS                              0x00f8
#define TX_2_DESC_START_ADDRESS_HW_MASK                              0xffffffff
#define TX_2_DESC_START_ADDRESS_SW_MASK                              0xffffffff
#define TX_2_DESC_START_ADDRESS_HW_WRITE_MASK                        0x00000000
#define TX_2_DESC_START_ADDRESS_SW_WRITE_MASK                        0xffffffff
#define TX_2_DESC_START_ADDRESS_RSTMASK                              0xffffffff
#define TX_2_DESC_START_ADDRESS_RESET                                0x00000000

// 0x00fc (TX_2_DMA_START)
#define TX_2_DMA_START_RESTART_MSB                                   4
#define TX_2_DMA_START_RESTART_LSB                                   4
#define TX_2_DMA_START_RESTART_MASK                                  0x00000010
#define TX_2_DMA_START_RESTART_GET(x)                                (((x) & TX_2_DMA_START_RESTART_MASK) >> TX_2_DMA_START_RESTART_LSB)
#define TX_2_DMA_START_RESTART_SET(x)                                (((0 | (x)) << TX_2_DMA_START_RESTART_LSB) & TX_2_DMA_START_RESTART_MASK)
#define TX_2_DMA_START_RESTART_RESET                                 0
#define TX_2_DMA_START_START_MSB                                     0
#define TX_2_DMA_START_START_LSB                                     0
#define TX_2_DMA_START_START_MASK                                    0x00000001
#define TX_2_DMA_START_START_GET(x)                                  (((x) & TX_2_DMA_START_START_MASK) >> TX_2_DMA_START_START_LSB)
#define TX_2_DMA_START_START_SET(x)                                  (((0 | (x)) << TX_2_DMA_START_START_LSB) & TX_2_DMA_START_START_MASK)
#define TX_2_DMA_START_START_RESET                                   0
#define TX_2_DMA_START_ADDRESS                                       0x00fc
#define TX_2_DMA_START_HW_MASK                                       0x00000011
#define TX_2_DMA_START_SW_MASK                                       0x00000011
#define TX_2_DMA_START_HW_WRITE_MASK                                 0x00000011
#define TX_2_DMA_START_SW_WRITE_MASK                                 0x00000011
#define TX_2_DMA_START_RSTMASK                                       0xffffffff
#define TX_2_DMA_START_RESET                                         0x00000000

// 0x0100 (TX_2_INTERRUPT_LIMIT)
#define TX_2_INTERRUPT_LIMIT_TIMEOUT_MSB                             15
#define TX_2_INTERRUPT_LIMIT_TIMEOUT_LSB                             4
#define TX_2_INTERRUPT_LIMIT_TIMEOUT_MASK                            0x0000fff0
#define TX_2_INTERRUPT_LIMIT_TIMEOUT_GET(x)                          (((x) & TX_2_INTERRUPT_LIMIT_TIMEOUT_MASK) >> TX_2_INTERRUPT_LIMIT_TIMEOUT_LSB)
#define TX_2_INTERRUPT_LIMIT_TIMEOUT_SET(x)                          (((0 | (x)) << TX_2_INTERRUPT_LIMIT_TIMEOUT_LSB) & TX_2_INTERRUPT_LIMIT_TIMEOUT_MASK)
#define TX_2_INTERRUPT_LIMIT_TIMEOUT_RESET                           0
#define TX_2_INTERRUPT_LIMIT_COUNT_MSB                               3
#define TX_2_INTERRUPT_LIMIT_COUNT_LSB                               0
#define TX_2_INTERRUPT_LIMIT_COUNT_MASK                              0x0000000f
#define TX_2_INTERRUPT_LIMIT_COUNT_GET(x)                            (((x) & TX_2_INTERRUPT_LIMIT_COUNT_MASK) >> TX_2_INTERRUPT_LIMIT_COUNT_LSB)
#define TX_2_INTERRUPT_LIMIT_COUNT_SET(x)                            (((0 | (x)) << TX_2_INTERRUPT_LIMIT_COUNT_LSB) & TX_2_INTERRUPT_LIMIT_COUNT_MASK)
#define TX_2_INTERRUPT_LIMIT_COUNT_RESET                             1
#define TX_2_INTERRUPT_LIMIT_ADDRESS                                 0x0100
#define TX_2_INTERRUPT_LIMIT_HW_MASK                                 0x0000ffff
#define TX_2_INTERRUPT_LIMIT_SW_MASK                                 0x0000ffff
#define TX_2_INTERRUPT_LIMIT_HW_WRITE_MASK                           0x00000000
#define TX_2_INTERRUPT_LIMIT_SW_WRITE_MASK                           0x0000ffff
#define TX_2_INTERRUPT_LIMIT_RSTMASK                                 0xffffffff
#define TX_2_INTERRUPT_LIMIT_RESET                                   0x00000001

// 0x0104 (TX_2_BURST_SIZE)
#define TX_2_BURST_SIZE_BURST_MSB                                    1
#define TX_2_BURST_SIZE_BURST_LSB                                    0
#define TX_2_BURST_SIZE_BURST_MASK                                   0x00000003
#define TX_2_BURST_SIZE_BURST_GET(x)                                 (((x) & TX_2_BURST_SIZE_BURST_MASK) >> TX_2_BURST_SIZE_BURST_LSB)
#define TX_2_BURST_SIZE_BURST_SET(x)                                 (((0 | (x)) << TX_2_BURST_SIZE_BURST_LSB) & TX_2_BURST_SIZE_BURST_MASK)
#define TX_2_BURST_SIZE_BURST_RESET                                  0
#define TX_2_BURST_SIZE_ADDRESS                                      0x0104
#define TX_2_BURST_SIZE_HW_MASK                                      0x00000003
#define TX_2_BURST_SIZE_SW_MASK                                      0x00000003
#define TX_2_BURST_SIZE_HW_WRITE_MASK                                0x00000000
#define TX_2_BURST_SIZE_SW_WRITE_MASK                                0x00000003
#define TX_2_BURST_SIZE_RSTMASK                                      0xffffffff
#define TX_2_BURST_SIZE_RESET                                        0x00000000

// 0x0108 (TX_2_DBG_TX)
#define TX_2_DBG_TX_FIFO_TOTAL_LEN_MSB                               31
#define TX_2_DBG_TX_FIFO_TOTAL_LEN_LSB                               16
#define TX_2_DBG_TX_FIFO_TOTAL_LEN_MASK                              0xffff0000
#define TX_2_DBG_TX_FIFO_TOTAL_LEN_GET(x)                            (((x) & TX_2_DBG_TX_FIFO_TOTAL_LEN_MASK) >> TX_2_DBG_TX_FIFO_TOTAL_LEN_LSB)
#define TX_2_DBG_TX_FIFO_TOTAL_LEN_SET(x)                            (((0 | (x)) << TX_2_DBG_TX_FIFO_TOTAL_LEN_LSB) & TX_2_DBG_TX_FIFO_TOTAL_LEN_MASK)
#define TX_2_DBG_TX_FIFO_TOTAL_LEN_RESET                             0
#define TX_2_DBG_TX_FIFO_WATERMARK_MSB                               15
#define TX_2_DBG_TX_FIFO_WATERMARK_LSB                               3
#define TX_2_DBG_TX_FIFO_WATERMARK_MASK                              0x0000fff8
#define TX_2_DBG_TX_FIFO_WATERMARK_GET(x)                            (((x) & TX_2_DBG_TX_FIFO_WATERMARK_MASK) >> TX_2_DBG_TX_FIFO_WATERMARK_LSB)
#define TX_2_DBG_TX_FIFO_WATERMARK_SET(x)                            (((0 | (x)) << TX_2_DBG_TX_FIFO_WATERMARK_LSB) & TX_2_DBG_TX_FIFO_WATERMARK_MASK)
#define TX_2_DBG_TX_FIFO_WATERMARK_RESET                             0
#define TX_2_DBG_TX_STATE_MSB                                        2
#define TX_2_DBG_TX_STATE_LSB                                        0
#define TX_2_DBG_TX_STATE_MASK                                       0x00000007
#define TX_2_DBG_TX_STATE_GET(x)                                     (((x) & TX_2_DBG_TX_STATE_MASK) >> TX_2_DBG_TX_STATE_LSB)
#define TX_2_DBG_TX_STATE_SET(x)                                     (((0 | (x)) << TX_2_DBG_TX_STATE_LSB) & TX_2_DBG_TX_STATE_MASK)
#define TX_2_DBG_TX_STATE_RESET                                      0
#define TX_2_DBG_TX_ADDRESS                                          0x0108
#define TX_2_DBG_TX_HW_MASK                                          0xffffffff
#define TX_2_DBG_TX_SW_MASK                                          0xffffffff
#define TX_2_DBG_TX_HW_WRITE_MASK                                    0xffff0007
#define TX_2_DBG_TX_SW_WRITE_MASK                                    0x0000fff8
#define TX_2_DBG_TX_RSTMASK                                          0xffffffff
#define TX_2_DBG_TX_RESET                                            0x00000000

// 0x010c (TX_2_DBG_TX_CUR_ADDR)
#define TX_2_DBG_TX_CUR_ADDR_REG_MSB                                 31
#define TX_2_DBG_TX_CUR_ADDR_REG_LSB                                 0
#define TX_2_DBG_TX_CUR_ADDR_REG_MASK                                0xffffffff
#define TX_2_DBG_TX_CUR_ADDR_REG_GET(x)                              (((x) & TX_2_DBG_TX_CUR_ADDR_REG_MASK) >> TX_2_DBG_TX_CUR_ADDR_REG_LSB)
#define TX_2_DBG_TX_CUR_ADDR_REG_SET(x)                              (((0 | (x)) << TX_2_DBG_TX_CUR_ADDR_REG_LSB) & TX_2_DBG_TX_CUR_ADDR_REG_MASK)
#define TX_2_DBG_TX_CUR_ADDR_REG_RESET                               0
#define TX_2_DBG_TX_CUR_ADDR_ADDRESS                                 0x010c
#define TX_2_DBG_TX_CUR_ADDR_HW_MASK                                 0xffffffff
#define TX_2_DBG_TX_CUR_ADDR_SW_MASK                                 0xffffffff
#define TX_2_DBG_TX_CUR_ADDR_HW_WRITE_MASK                           0xffffffff
#define TX_2_DBG_TX_CUR_ADDR_SW_WRITE_MASK                           0x00000000
#define TX_2_DBG_TX_CUR_ADDR_RSTMASK                                 0xffffffff
#define TX_2_DBG_TX_CUR_ADDR_RESET                                   0x00000000

// 0x0110 (TX_2_DATA_SWAP)
#define TX_2_DATA_SWAP_SWAPD_MSB                                     1
#define TX_2_DATA_SWAP_SWAPD_LSB                                     1
#define TX_2_DATA_SWAP_SWAPD_MASK                                    0x00000002
#define TX_2_DATA_SWAP_SWAPD_GET(x)                                  (((x) & TX_2_DATA_SWAP_SWAPD_MASK) >> TX_2_DATA_SWAP_SWAPD_LSB)
#define TX_2_DATA_SWAP_SWAPD_SET(x)                                  (((0 | (x)) << TX_2_DATA_SWAP_SWAPD_LSB) & TX_2_DATA_SWAP_SWAPD_MASK)
#define TX_2_DATA_SWAP_SWAPD_RESET                                   0
#define TX_2_DATA_SWAP_SWAP_MSB                                      0
#define TX_2_DATA_SWAP_SWAP_LSB                                      0
#define TX_2_DATA_SWAP_SWAP_MASK                                     0x00000001
#define TX_2_DATA_SWAP_SWAP_GET(x)                                   (((x) & TX_2_DATA_SWAP_SWAP_MASK) >> TX_2_DATA_SWAP_SWAP_LSB)
#define TX_2_DATA_SWAP_SWAP_SET(x)                                   (((0 | (x)) << TX_2_DATA_SWAP_SWAP_LSB) & TX_2_DATA_SWAP_SWAP_MASK)
#define TX_2_DATA_SWAP_SWAP_RESET                                    1
#define TX_2_DATA_SWAP_ADDRESS                                       0x0110
#define TX_2_DATA_SWAP_HW_MASK                                       0x00000003
#define TX_2_DATA_SWAP_SW_MASK                                       0x00000003
#define TX_2_DATA_SWAP_HW_WRITE_MASK                                 0x00000000
#define TX_2_DATA_SWAP_SW_WRITE_MASK                                 0x00000003
#define TX_2_DATA_SWAP_RSTMASK                                       0xffffffff
#define TX_2_DATA_SWAP_RESET                                         0x00000001

// 0x0114 (TX_3_DESC_START_ADDRESS)
#define TX_3_DESC_START_ADDRESS_REG_MSB                              31
#define TX_3_DESC_START_ADDRESS_REG_LSB                              0
#define TX_3_DESC_START_ADDRESS_REG_MASK                             0xffffffff
#define TX_3_DESC_START_ADDRESS_REG_GET(x)                           (((x) & TX_3_DESC_START_ADDRESS_REG_MASK) >> TX_3_DESC_START_ADDRESS_REG_LSB)
#define TX_3_DESC_START_ADDRESS_REG_SET(x)                           (((0 | (x)) << TX_3_DESC_START_ADDRESS_REG_LSB) & TX_3_DESC_START_ADDRESS_REG_MASK)
#define TX_3_DESC_START_ADDRESS_REG_RESET                            0
#define TX_3_DESC_START_ADDRESS_ADDRESS                              0x0114
#define TX_3_DESC_START_ADDRESS_HW_MASK                              0xffffffff
#define TX_3_DESC_START_ADDRESS_SW_MASK                              0xffffffff
#define TX_3_DESC_START_ADDRESS_HW_WRITE_MASK                        0x00000000
#define TX_3_DESC_START_ADDRESS_SW_WRITE_MASK                        0xffffffff
#define TX_3_DESC_START_ADDRESS_RSTMASK                              0xffffffff
#define TX_3_DESC_START_ADDRESS_RESET                                0x00000000

// 0x0118 (TX_3_DMA_START)
#define TX_3_DMA_START_RESTART_MSB                                   4
#define TX_3_DMA_START_RESTART_LSB                                   4
#define TX_3_DMA_START_RESTART_MASK                                  0x00000010
#define TX_3_DMA_START_RESTART_GET(x)                                (((x) & TX_3_DMA_START_RESTART_MASK) >> TX_3_DMA_START_RESTART_LSB)
#define TX_3_DMA_START_RESTART_SET(x)                                (((0 | (x)) << TX_3_DMA_START_RESTART_LSB) & TX_3_DMA_START_RESTART_MASK)
#define TX_3_DMA_START_RESTART_RESET                                 0
#define TX_3_DMA_START_START_MSB                                     0
#define TX_3_DMA_START_START_LSB                                     0
#define TX_3_DMA_START_START_MASK                                    0x00000001
#define TX_3_DMA_START_START_GET(x)                                  (((x) & TX_3_DMA_START_START_MASK) >> TX_3_DMA_START_START_LSB)
#define TX_3_DMA_START_START_SET(x)                                  (((0 | (x)) << TX_3_DMA_START_START_LSB) & TX_3_DMA_START_START_MASK)
#define TX_3_DMA_START_START_RESET                                   0
#define TX_3_DMA_START_ADDRESS                                       0x0118
#define TX_3_DMA_START_HW_MASK                                       0x00000011
#define TX_3_DMA_START_SW_MASK                                       0x00000011
#define TX_3_DMA_START_HW_WRITE_MASK                                 0x00000011
#define TX_3_DMA_START_SW_WRITE_MASK                                 0x00000011
#define TX_3_DMA_START_RSTMASK                                       0xffffffff
#define TX_3_DMA_START_RESET                                         0x00000000

// 0x011c (TX_3_INTERRUPT_LIMIT)
#define TX_3_INTERRUPT_LIMIT_TIMEOUT_MSB                             15
#define TX_3_INTERRUPT_LIMIT_TIMEOUT_LSB                             4
#define TX_3_INTERRUPT_LIMIT_TIMEOUT_MASK                            0x0000fff0
#define TX_3_INTERRUPT_LIMIT_TIMEOUT_GET(x)                          (((x) & TX_3_INTERRUPT_LIMIT_TIMEOUT_MASK) >> TX_3_INTERRUPT_LIMIT_TIMEOUT_LSB)
#define TX_3_INTERRUPT_LIMIT_TIMEOUT_SET(x)                          (((0 | (x)) << TX_3_INTERRUPT_LIMIT_TIMEOUT_LSB) & TX_3_INTERRUPT_LIMIT_TIMEOUT_MASK)
#define TX_3_INTERRUPT_LIMIT_TIMEOUT_RESET                           0
#define TX_3_INTERRUPT_LIMIT_COUNT_MSB                               3
#define TX_3_INTERRUPT_LIMIT_COUNT_LSB                               0
#define TX_3_INTERRUPT_LIMIT_COUNT_MASK                              0x0000000f
#define TX_3_INTERRUPT_LIMIT_COUNT_GET(x)                            (((x) & TX_3_INTERRUPT_LIMIT_COUNT_MASK) >> TX_3_INTERRUPT_LIMIT_COUNT_LSB)
#define TX_3_INTERRUPT_LIMIT_COUNT_SET(x)                            (((0 | (x)) << TX_3_INTERRUPT_LIMIT_COUNT_LSB) & TX_3_INTERRUPT_LIMIT_COUNT_MASK)
#define TX_3_INTERRUPT_LIMIT_COUNT_RESET                             1
#define TX_3_INTERRUPT_LIMIT_ADDRESS                                 0x011c
#define TX_3_INTERRUPT_LIMIT_HW_MASK                                 0x0000ffff
#define TX_3_INTERRUPT_LIMIT_SW_MASK                                 0x0000ffff
#define TX_3_INTERRUPT_LIMIT_HW_WRITE_MASK                           0x00000000
#define TX_3_INTERRUPT_LIMIT_SW_WRITE_MASK                           0x0000ffff
#define TX_3_INTERRUPT_LIMIT_RSTMASK                                 0xffffffff
#define TX_3_INTERRUPT_LIMIT_RESET                                   0x00000001

// 0x0120 (TX_3_BURST_SIZE)
#define TX_3_BURST_SIZE_BURST_MSB                                    1
#define TX_3_BURST_SIZE_BURST_LSB                                    0
#define TX_3_BURST_SIZE_BURST_MASK                                   0x00000003
#define TX_3_BURST_SIZE_BURST_GET(x)                                 (((x) & TX_3_BURST_SIZE_BURST_MASK) >> TX_3_BURST_SIZE_BURST_LSB)
#define TX_3_BURST_SIZE_BURST_SET(x)                                 (((0 | (x)) << TX_3_BURST_SIZE_BURST_LSB) & TX_3_BURST_SIZE_BURST_MASK)
#define TX_3_BURST_SIZE_BURST_RESET                                  0
#define TX_3_BURST_SIZE_ADDRESS                                      0x0120
#define TX_3_BURST_SIZE_HW_MASK                                      0x00000003
#define TX_3_BURST_SIZE_SW_MASK                                      0x00000003
#define TX_3_BURST_SIZE_HW_WRITE_MASK                                0x00000000
#define TX_3_BURST_SIZE_SW_WRITE_MASK                                0x00000003
#define TX_3_BURST_SIZE_RSTMASK                                      0xffffffff
#define TX_3_BURST_SIZE_RESET                                        0x00000000

// 0x0124 (TX_3_DBG_TX)
#define TX_3_DBG_TX_FIFO_TOTAL_LEN_MSB                               31
#define TX_3_DBG_TX_FIFO_TOTAL_LEN_LSB                               16
#define TX_3_DBG_TX_FIFO_TOTAL_LEN_MASK                              0xffff0000
#define TX_3_DBG_TX_FIFO_TOTAL_LEN_GET(x)                            (((x) & TX_3_DBG_TX_FIFO_TOTAL_LEN_MASK) >> TX_3_DBG_TX_FIFO_TOTAL_LEN_LSB)
#define TX_3_DBG_TX_FIFO_TOTAL_LEN_SET(x)                            (((0 | (x)) << TX_3_DBG_TX_FIFO_TOTAL_LEN_LSB) & TX_3_DBG_TX_FIFO_TOTAL_LEN_MASK)
#define TX_3_DBG_TX_FIFO_TOTAL_LEN_RESET                             0
#define TX_3_DBG_TX_FIFO_WATERMARK_MSB                               15
#define TX_3_DBG_TX_FIFO_WATERMARK_LSB                               3
#define TX_3_DBG_TX_FIFO_WATERMARK_MASK                              0x0000fff8
#define TX_3_DBG_TX_FIFO_WATERMARK_GET(x)                            (((x) & TX_3_DBG_TX_FIFO_WATERMARK_MASK) >> TX_3_DBG_TX_FIFO_WATERMARK_LSB)
#define TX_3_DBG_TX_FIFO_WATERMARK_SET(x)                            (((0 | (x)) << TX_3_DBG_TX_FIFO_WATERMARK_LSB) & TX_3_DBG_TX_FIFO_WATERMARK_MASK)
#define TX_3_DBG_TX_FIFO_WATERMARK_RESET                             0
#define TX_3_DBG_TX_STATE_MSB                                        2
#define TX_3_DBG_TX_STATE_LSB                                        0
#define TX_3_DBG_TX_STATE_MASK                                       0x00000007
#define TX_3_DBG_TX_STATE_GET(x)                                     (((x) & TX_3_DBG_TX_STATE_MASK) >> TX_3_DBG_TX_STATE_LSB)
#define TX_3_DBG_TX_STATE_SET(x)                                     (((0 | (x)) << TX_3_DBG_TX_STATE_LSB) & TX_3_DBG_TX_STATE_MASK)
#define TX_3_DBG_TX_STATE_RESET                                      0
#define TX_3_DBG_TX_ADDRESS                                          0x0124
#define TX_3_DBG_TX_HW_MASK                                          0xffffffff
#define TX_3_DBG_TX_SW_MASK                                          0xffffffff
#define TX_3_DBG_TX_HW_WRITE_MASK                                    0xffff0007
#define TX_3_DBG_TX_SW_WRITE_MASK                                    0x0000fff8
#define TX_3_DBG_TX_RSTMASK                                          0xffffffff
#define TX_3_DBG_TX_RESET                                            0x00000000

// 0x0128 (TX_3_DBG_TX_CUR_ADDR)
#define TX_3_DBG_TX_CUR_ADDR_REG_MSB                                 31
#define TX_3_DBG_TX_CUR_ADDR_REG_LSB                                 0
#define TX_3_DBG_TX_CUR_ADDR_REG_MASK                                0xffffffff
#define TX_3_DBG_TX_CUR_ADDR_REG_GET(x)                              (((x) & TX_3_DBG_TX_CUR_ADDR_REG_MASK) >> TX_3_DBG_TX_CUR_ADDR_REG_LSB)
#define TX_3_DBG_TX_CUR_ADDR_REG_SET(x)                              (((0 | (x)) << TX_3_DBG_TX_CUR_ADDR_REG_LSB) & TX_3_DBG_TX_CUR_ADDR_REG_MASK)
#define TX_3_DBG_TX_CUR_ADDR_REG_RESET                               0
#define TX_3_DBG_TX_CUR_ADDR_ADDRESS                                 0x0128
#define TX_3_DBG_TX_CUR_ADDR_HW_MASK                                 0xffffffff
#define TX_3_DBG_TX_CUR_ADDR_SW_MASK                                 0xffffffff
#define TX_3_DBG_TX_CUR_ADDR_HW_WRITE_MASK                           0xffffffff
#define TX_3_DBG_TX_CUR_ADDR_SW_WRITE_MASK                           0x00000000
#define TX_3_DBG_TX_CUR_ADDR_RSTMASK                                 0xffffffff
#define TX_3_DBG_TX_CUR_ADDR_RESET                                   0x00000000

// 0x012c (TX_3_DATA_SWAP)
#define TX_3_DATA_SWAP_SWAPD_MSB                                     1
#define TX_3_DATA_SWAP_SWAPD_LSB                                     1
#define TX_3_DATA_SWAP_SWAPD_MASK                                    0x00000002
#define TX_3_DATA_SWAP_SWAPD_GET(x)                                  (((x) & TX_3_DATA_SWAP_SWAPD_MASK) >> TX_3_DATA_SWAP_SWAPD_LSB)
#define TX_3_DATA_SWAP_SWAPD_SET(x)                                  (((0 | (x)) << TX_3_DATA_SWAP_SWAPD_LSB) & TX_3_DATA_SWAP_SWAPD_MASK)
#define TX_3_DATA_SWAP_SWAPD_RESET                                   0
#define TX_3_DATA_SWAP_SWAP_MSB                                      0
#define TX_3_DATA_SWAP_SWAP_LSB                                      0
#define TX_3_DATA_SWAP_SWAP_MASK                                     0x00000001
#define TX_3_DATA_SWAP_SWAP_GET(x)                                   (((x) & TX_3_DATA_SWAP_SWAP_MASK) >> TX_3_DATA_SWAP_SWAP_LSB)
#define TX_3_DATA_SWAP_SWAP_SET(x)                                   (((0 | (x)) << TX_3_DATA_SWAP_SWAP_LSB) & TX_3_DATA_SWAP_SWAP_MASK)
#define TX_3_DATA_SWAP_SWAP_RESET                                    1
#define TX_3_DATA_SWAP_ADDRESS                                       0x012c
#define TX_3_DATA_SWAP_HW_MASK                                       0x00000003
#define TX_3_DATA_SWAP_SW_MASK                                       0x00000003
#define TX_3_DATA_SWAP_HW_WRITE_MASK                                 0x00000000
#define TX_3_DATA_SWAP_SW_WRITE_MASK                                 0x00000003
#define TX_3_DATA_SWAP_RSTMASK                                       0xffffffff
#define TX_3_DATA_SWAP_RESET                                         0x00000001

// 0x0130 (TX_4_DESC_START_ADDRESS)
#define TX_4_DESC_START_ADDRESS_REG_MSB                              31
#define TX_4_DESC_START_ADDRESS_REG_LSB                              0
#define TX_4_DESC_START_ADDRESS_REG_MASK                             0xffffffff
#define TX_4_DESC_START_ADDRESS_REG_GET(x)                           (((x) & TX_4_DESC_START_ADDRESS_REG_MASK) >> TX_4_DESC_START_ADDRESS_REG_LSB)
#define TX_4_DESC_START_ADDRESS_REG_SET(x)                           (((0 | (x)) << TX_4_DESC_START_ADDRESS_REG_LSB) & TX_4_DESC_START_ADDRESS_REG_MASK)
#define TX_4_DESC_START_ADDRESS_REG_RESET                            0
#define TX_4_DESC_START_ADDRESS_ADDRESS                              0x0130
#define TX_4_DESC_START_ADDRESS_HW_MASK                              0xffffffff
#define TX_4_DESC_START_ADDRESS_SW_MASK                              0xffffffff
#define TX_4_DESC_START_ADDRESS_HW_WRITE_MASK                        0x00000000
#define TX_4_DESC_START_ADDRESS_SW_WRITE_MASK                        0xffffffff
#define TX_4_DESC_START_ADDRESS_RSTMASK                              0xffffffff
#define TX_4_DESC_START_ADDRESS_RESET                                0x00000000

// 0x0134 (TX_4_DMA_START)
#define TX_4_DMA_START_RESTART_MSB                                   4
#define TX_4_DMA_START_RESTART_LSB                                   4
#define TX_4_DMA_START_RESTART_MASK                                  0x00000010
#define TX_4_DMA_START_RESTART_GET(x)                                (((x) & TX_4_DMA_START_RESTART_MASK) >> TX_4_DMA_START_RESTART_LSB)
#define TX_4_DMA_START_RESTART_SET(x)                                (((0 | (x)) << TX_4_DMA_START_RESTART_LSB) & TX_4_DMA_START_RESTART_MASK)
#define TX_4_DMA_START_RESTART_RESET                                 0
#define TX_4_DMA_START_START_MSB                                     0
#define TX_4_DMA_START_START_LSB                                     0
#define TX_4_DMA_START_START_MASK                                    0x00000001
#define TX_4_DMA_START_START_GET(x)                                  (((x) & TX_4_DMA_START_START_MASK) >> TX_4_DMA_START_START_LSB)
#define TX_4_DMA_START_START_SET(x)                                  (((0 | (x)) << TX_4_DMA_START_START_LSB) & TX_4_DMA_START_START_MASK)
#define TX_4_DMA_START_START_RESET                                   0
#define TX_4_DMA_START_ADDRESS                                       0x0134
#define TX_4_DMA_START_HW_MASK                                       0x00000011
#define TX_4_DMA_START_SW_MASK                                       0x00000011
#define TX_4_DMA_START_HW_WRITE_MASK                                 0x00000011
#define TX_4_DMA_START_SW_WRITE_MASK                                 0x00000011
#define TX_4_DMA_START_RSTMASK                                       0xffffffff
#define TX_4_DMA_START_RESET                                         0x00000000

// 0x0138 (TX_4_INTERRUPT_LIMIT)
#define TX_4_INTERRUPT_LIMIT_TIMEOUT_MSB                             15
#define TX_4_INTERRUPT_LIMIT_TIMEOUT_LSB                             4
#define TX_4_INTERRUPT_LIMIT_TIMEOUT_MASK                            0x0000fff0
#define TX_4_INTERRUPT_LIMIT_TIMEOUT_GET(x)                          (((x) & TX_4_INTERRUPT_LIMIT_TIMEOUT_MASK) >> TX_4_INTERRUPT_LIMIT_TIMEOUT_LSB)
#define TX_4_INTERRUPT_LIMIT_TIMEOUT_SET(x)                          (((0 | (x)) << TX_4_INTERRUPT_LIMIT_TIMEOUT_LSB) & TX_4_INTERRUPT_LIMIT_TIMEOUT_MASK)
#define TX_4_INTERRUPT_LIMIT_TIMEOUT_RESET                           0
#define TX_4_INTERRUPT_LIMIT_COUNT_MSB                               3
#define TX_4_INTERRUPT_LIMIT_COUNT_LSB                               0
#define TX_4_INTERRUPT_LIMIT_COUNT_MASK                              0x0000000f
#define TX_4_INTERRUPT_LIMIT_COUNT_GET(x)                            (((x) & TX_4_INTERRUPT_LIMIT_COUNT_MASK) >> TX_4_INTERRUPT_LIMIT_COUNT_LSB)
#define TX_4_INTERRUPT_LIMIT_COUNT_SET(x)                            (((0 | (x)) << TX_4_INTERRUPT_LIMIT_COUNT_LSB) & TX_4_INTERRUPT_LIMIT_COUNT_MASK)
#define TX_4_INTERRUPT_LIMIT_COUNT_RESET                             1
#define TX_4_INTERRUPT_LIMIT_ADDRESS                                 0x0138
#define TX_4_INTERRUPT_LIMIT_HW_MASK                                 0x0000ffff
#define TX_4_INTERRUPT_LIMIT_SW_MASK                                 0x0000ffff
#define TX_4_INTERRUPT_LIMIT_HW_WRITE_MASK                           0x00000000
#define TX_4_INTERRUPT_LIMIT_SW_WRITE_MASK                           0x0000ffff
#define TX_4_INTERRUPT_LIMIT_RSTMASK                                 0xffffffff
#define TX_4_INTERRUPT_LIMIT_RESET                                   0x00000001

// 0x013c (TX_4_BURST_SIZE)
#define TX_4_BURST_SIZE_BURST_MSB                                    1
#define TX_4_BURST_SIZE_BURST_LSB                                    0
#define TX_4_BURST_SIZE_BURST_MASK                                   0x00000003
#define TX_4_BURST_SIZE_BURST_GET(x)                                 (((x) & TX_4_BURST_SIZE_BURST_MASK) >> TX_4_BURST_SIZE_BURST_LSB)
#define TX_4_BURST_SIZE_BURST_SET(x)                                 (((0 | (x)) << TX_4_BURST_SIZE_BURST_LSB) & TX_4_BURST_SIZE_BURST_MASK)
#define TX_4_BURST_SIZE_BURST_RESET                                  0
#define TX_4_BURST_SIZE_ADDRESS                                      0x013c
#define TX_4_BURST_SIZE_HW_MASK                                      0x00000003
#define TX_4_BURST_SIZE_SW_MASK                                      0x00000003
#define TX_4_BURST_SIZE_HW_WRITE_MASK                                0x00000000
#define TX_4_BURST_SIZE_SW_WRITE_MASK                                0x00000003
#define TX_4_BURST_SIZE_RSTMASK                                      0xffffffff
#define TX_4_BURST_SIZE_RESET                                        0x00000000

// 0x0140 (TX_4_DBG_TX)
#define TX_4_DBG_TX_FIFO_TOTAL_LEN_MSB                               31
#define TX_4_DBG_TX_FIFO_TOTAL_LEN_LSB                               16
#define TX_4_DBG_TX_FIFO_TOTAL_LEN_MASK                              0xffff0000
#define TX_4_DBG_TX_FIFO_TOTAL_LEN_GET(x)                            (((x) & TX_4_DBG_TX_FIFO_TOTAL_LEN_MASK) >> TX_4_DBG_TX_FIFO_TOTAL_LEN_LSB)
#define TX_4_DBG_TX_FIFO_TOTAL_LEN_SET(x)                            (((0 | (x)) << TX_4_DBG_TX_FIFO_TOTAL_LEN_LSB) & TX_4_DBG_TX_FIFO_TOTAL_LEN_MASK)
#define TX_4_DBG_TX_FIFO_TOTAL_LEN_RESET                             0
#define TX_4_DBG_TX_FIFO_WATERMARK_MSB                               15
#define TX_4_DBG_TX_FIFO_WATERMARK_LSB                               3
#define TX_4_DBG_TX_FIFO_WATERMARK_MASK                              0x0000fff8
#define TX_4_DBG_TX_FIFO_WATERMARK_GET(x)                            (((x) & TX_4_DBG_TX_FIFO_WATERMARK_MASK) >> TX_4_DBG_TX_FIFO_WATERMARK_LSB)
#define TX_4_DBG_TX_FIFO_WATERMARK_SET(x)                            (((0 | (x)) << TX_4_DBG_TX_FIFO_WATERMARK_LSB) & TX_4_DBG_TX_FIFO_WATERMARK_MASK)
#define TX_4_DBG_TX_FIFO_WATERMARK_RESET                             0
#define TX_4_DBG_TX_STATE_MSB                                        2
#define TX_4_DBG_TX_STATE_LSB                                        0
#define TX_4_DBG_TX_STATE_MASK                                       0x00000007
#define TX_4_DBG_TX_STATE_GET(x)                                     (((x) & TX_4_DBG_TX_STATE_MASK) >> TX_4_DBG_TX_STATE_LSB)
#define TX_4_DBG_TX_STATE_SET(x)                                     (((0 | (x)) << TX_4_DBG_TX_STATE_LSB) & TX_4_DBG_TX_STATE_MASK)
#define TX_4_DBG_TX_STATE_RESET                                      0
#define TX_4_DBG_TX_ADDRESS                                          0x0140
#define TX_4_DBG_TX_HW_MASK                                          0xffffffff
#define TX_4_DBG_TX_SW_MASK                                          0xffffffff
#define TX_4_DBG_TX_HW_WRITE_MASK                                    0xffff0007
#define TX_4_DBG_TX_SW_WRITE_MASK                                    0x0000fff8
#define TX_4_DBG_TX_RSTMASK                                          0xffffffff
#define TX_4_DBG_TX_RESET                                            0x00000000

// 0x0144 (TX_4_DBG_TX_CUR_ADDR)
#define TX_4_DBG_TX_CUR_ADDR_REG_MSB                                 31
#define TX_4_DBG_TX_CUR_ADDR_REG_LSB                                 0
#define TX_4_DBG_TX_CUR_ADDR_REG_MASK                                0xffffffff
#define TX_4_DBG_TX_CUR_ADDR_REG_GET(x)                              (((x) & TX_4_DBG_TX_CUR_ADDR_REG_MASK) >> TX_4_DBG_TX_CUR_ADDR_REG_LSB)
#define TX_4_DBG_TX_CUR_ADDR_REG_SET(x)                              (((0 | (x)) << TX_4_DBG_TX_CUR_ADDR_REG_LSB) & TX_4_DBG_TX_CUR_ADDR_REG_MASK)
#define TX_4_DBG_TX_CUR_ADDR_REG_RESET                               0
#define TX_4_DBG_TX_CUR_ADDR_ADDRESS                                 0x0144
#define TX_4_DBG_TX_CUR_ADDR_HW_MASK                                 0xffffffff
#define TX_4_DBG_TX_CUR_ADDR_SW_MASK                                 0xffffffff
#define TX_4_DBG_TX_CUR_ADDR_HW_WRITE_MASK                           0xffffffff
#define TX_4_DBG_TX_CUR_ADDR_SW_WRITE_MASK                           0x00000000
#define TX_4_DBG_TX_CUR_ADDR_RSTMASK                                 0xffffffff
#define TX_4_DBG_TX_CUR_ADDR_RESET                                   0x00000000

// 0x0148 (TX_4_DATA_SWAP)
#define TX_4_DATA_SWAP_SWAPD_MSB                                     1
#define TX_4_DATA_SWAP_SWAPD_LSB                                     1
#define TX_4_DATA_SWAP_SWAPD_MASK                                    0x00000002
#define TX_4_DATA_SWAP_SWAPD_GET(x)                                  (((x) & TX_4_DATA_SWAP_SWAPD_MASK) >> TX_4_DATA_SWAP_SWAPD_LSB)
#define TX_4_DATA_SWAP_SWAPD_SET(x)                                  (((0 | (x)) << TX_4_DATA_SWAP_SWAPD_LSB) & TX_4_DATA_SWAP_SWAPD_MASK)
#define TX_4_DATA_SWAP_SWAPD_RESET                                   0
#define TX_4_DATA_SWAP_SWAP_MSB                                      0
#define TX_4_DATA_SWAP_SWAP_LSB                                      0
#define TX_4_DATA_SWAP_SWAP_MASK                                     0x00000001
#define TX_4_DATA_SWAP_SWAP_GET(x)                                   (((x) & TX_4_DATA_SWAP_SWAP_MASK) >> TX_4_DATA_SWAP_SWAP_LSB)
#define TX_4_DATA_SWAP_SWAP_SET(x)                                   (((0 | (x)) << TX_4_DATA_SWAP_SWAP_LSB) & TX_4_DATA_SWAP_SWAP_MASK)
#define TX_4_DATA_SWAP_SWAP_RESET                                    1
#define TX_4_DATA_SWAP_ADDRESS                                       0x0148
#define TX_4_DATA_SWAP_HW_MASK                                       0x00000003
#define TX_4_DATA_SWAP_SW_MASK                                       0x00000003
#define TX_4_DATA_SWAP_HW_WRITE_MASK                                 0x00000000
#define TX_4_DATA_SWAP_SW_WRITE_MASK                                 0x00000003
#define TX_4_DATA_SWAP_RSTMASK                                       0xffffffff
#define TX_4_DATA_SWAP_RESET                                         0x00000001

// 0x014c (INTERRUPT)
#define INTERRUPT_TX_7_END_MSB                                       31
#define INTERRUPT_TX_7_END_LSB                                       31
#define INTERRUPT_TX_7_END_MASK                                      0x80000000
#define INTERRUPT_TX_7_END_GET(x)                                    (((x) & INTERRUPT_TX_7_END_MASK) >> INTERRUPT_TX_7_END_LSB)
#define INTERRUPT_TX_7_END_SET(x)                                    (((0 | (x)) << INTERRUPT_TX_7_END_LSB) & INTERRUPT_TX_7_END_MASK)
#define INTERRUPT_TX_7_END_RESET                                     0
#define INTERRUPT_TX_6_END_MSB                                       30
#define INTERRUPT_TX_6_END_LSB                                       30
#define INTERRUPT_TX_6_END_MASK                                      0x40000000
#define INTERRUPT_TX_6_END_GET(x)                                    (((x) & INTERRUPT_TX_6_END_MASK) >> INTERRUPT_TX_6_END_LSB)
#define INTERRUPT_TX_6_END_SET(x)                                    (((0 | (x)) << INTERRUPT_TX_6_END_LSB) & INTERRUPT_TX_6_END_MASK)
#define INTERRUPT_TX_6_END_RESET                                     0
#define INTERRUPT_TX_5_END_MSB                                       29
#define INTERRUPT_TX_5_END_LSB                                       29
#define INTERRUPT_TX_5_END_MASK                                      0x20000000
#define INTERRUPT_TX_5_END_GET(x)                                    (((x) & INTERRUPT_TX_5_END_MASK) >> INTERRUPT_TX_5_END_LSB)
#define INTERRUPT_TX_5_END_SET(x)                                    (((0 | (x)) << INTERRUPT_TX_5_END_LSB) & INTERRUPT_TX_5_END_MASK)
#define INTERRUPT_TX_5_END_RESET                                     0
#define INTERRUPT_TX_4_END_MSB                                       28
#define INTERRUPT_TX_4_END_LSB                                       28
#define INTERRUPT_TX_4_END_MASK                                      0x10000000
#define INTERRUPT_TX_4_END_GET(x)                                    (((x) & INTERRUPT_TX_4_END_MASK) >> INTERRUPT_TX_4_END_LSB)
#define INTERRUPT_TX_4_END_SET(x)                                    (((0 | (x)) << INTERRUPT_TX_4_END_LSB) & INTERRUPT_TX_4_END_MASK)
#define INTERRUPT_TX_4_END_RESET                                     0
#define INTERRUPT_TX_3_END_MSB                                       27
#define INTERRUPT_TX_3_END_LSB                                       27
#define INTERRUPT_TX_3_END_MASK                                      0x08000000
#define INTERRUPT_TX_3_END_GET(x)                                    (((x) & INTERRUPT_TX_3_END_MASK) >> INTERRUPT_TX_3_END_LSB)
#define INTERRUPT_TX_3_END_SET(x)                                    (((0 | (x)) << INTERRUPT_TX_3_END_LSB) & INTERRUPT_TX_3_END_MASK)
#define INTERRUPT_TX_3_END_RESET                                     0
#define INTERRUPT_TX_2_END_MSB                                       26
#define INTERRUPT_TX_2_END_LSB                                       26
#define INTERRUPT_TX_2_END_MASK                                      0x04000000
#define INTERRUPT_TX_2_END_GET(x)                                    (((x) & INTERRUPT_TX_2_END_MASK) >> INTERRUPT_TX_2_END_LSB)
#define INTERRUPT_TX_2_END_SET(x)                                    (((0 | (x)) << INTERRUPT_TX_2_END_LSB) & INTERRUPT_TX_2_END_MASK)
#define INTERRUPT_TX_2_END_RESET                                     0
#define INTERRUPT_TX_1_END_MSB                                       25
#define INTERRUPT_TX_1_END_LSB                                       25
#define INTERRUPT_TX_1_END_MASK                                      0x02000000
#define INTERRUPT_TX_1_END_GET(x)                                    (((x) & INTERRUPT_TX_1_END_MASK) >> INTERRUPT_TX_1_END_LSB)
#define INTERRUPT_TX_1_END_SET(x)                                    (((0 | (x)) << INTERRUPT_TX_1_END_LSB) & INTERRUPT_TX_1_END_MASK)
#define INTERRUPT_TX_1_END_RESET                                     0
#define INTERRUPT_TX_0_END_MSB                                       24
#define INTERRUPT_TX_0_END_LSB                                       24
#define INTERRUPT_TX_0_END_MASK                                      0x01000000
#define INTERRUPT_TX_0_END_GET(x)                                    (((x) & INTERRUPT_TX_0_END_MASK) >> INTERRUPT_TX_0_END_LSB)
#define INTERRUPT_TX_0_END_SET(x)                                    (((0 | (x)) << INTERRUPT_TX_0_END_LSB) & INTERRUPT_TX_0_END_MASK)
#define INTERRUPT_TX_0_END_RESET                                     0
#define INTERRUPT_TX_7_COMPLETE_MSB                                  23
#define INTERRUPT_TX_7_COMPLETE_LSB                                  23
#define INTERRUPT_TX_7_COMPLETE_MASK                                 0x00800000
#define INTERRUPT_TX_7_COMPLETE_GET(x)                               (((x) & INTERRUPT_TX_7_COMPLETE_MASK) >> INTERRUPT_TX_7_COMPLETE_LSB)
#define INTERRUPT_TX_7_COMPLETE_SET(x)                               (((0 | (x)) << INTERRUPT_TX_7_COMPLETE_LSB) & INTERRUPT_TX_7_COMPLETE_MASK)
#define INTERRUPT_TX_7_COMPLETE_RESET                                0
#define INTERRUPT_TX_6_COMPLETE_MSB                                  22
#define INTERRUPT_TX_6_COMPLETE_LSB                                  22
#define INTERRUPT_TX_6_COMPLETE_MASK                                 0x00400000
#define INTERRUPT_TX_6_COMPLETE_GET(x)                               (((x) & INTERRUPT_TX_6_COMPLETE_MASK) >> INTERRUPT_TX_6_COMPLETE_LSB)
#define INTERRUPT_TX_6_COMPLETE_SET(x)                               (((0 | (x)) << INTERRUPT_TX_6_COMPLETE_LSB) & INTERRUPT_TX_6_COMPLETE_MASK)
#define INTERRUPT_TX_6_COMPLETE_RESET                                0
#define INTERRUPT_TX_5_COMPLETE_MSB                                  21
#define INTERRUPT_TX_5_COMPLETE_LSB                                  21
#define INTERRUPT_TX_5_COMPLETE_MASK                                 0x00200000
#define INTERRUPT_TX_5_COMPLETE_GET(x)                               (((x) & INTERRUPT_TX_5_COMPLETE_MASK) >> INTERRUPT_TX_5_COMPLETE_LSB)
#define INTERRUPT_TX_5_COMPLETE_SET(x)                               (((0 | (x)) << INTERRUPT_TX_5_COMPLETE_LSB) & INTERRUPT_TX_5_COMPLETE_MASK)
#define INTERRUPT_TX_5_COMPLETE_RESET                                0
#define INTERRUPT_TX_4_COMPLETE_MSB                                  20
#define INTERRUPT_TX_4_COMPLETE_LSB                                  20
#define INTERRUPT_TX_4_COMPLETE_MASK                                 0x00100000
#define INTERRUPT_TX_4_COMPLETE_GET(x)                               (((x) & INTERRUPT_TX_4_COMPLETE_MASK) >> INTERRUPT_TX_4_COMPLETE_LSB)
#define INTERRUPT_TX_4_COMPLETE_SET(x)                               (((0 | (x)) << INTERRUPT_TX_4_COMPLETE_LSB) & INTERRUPT_TX_4_COMPLETE_MASK)
#define INTERRUPT_TX_4_COMPLETE_RESET                                0
#define INTERRUPT_TX_3_COMPLETE_MSB                                  19
#define INTERRUPT_TX_3_COMPLETE_LSB                                  19
#define INTERRUPT_TX_3_COMPLETE_MASK                                 0x00080000
#define INTERRUPT_TX_3_COMPLETE_GET(x)                               (((x) & INTERRUPT_TX_3_COMPLETE_MASK) >> INTERRUPT_TX_3_COMPLETE_LSB)
#define INTERRUPT_TX_3_COMPLETE_SET(x)                               (((0 | (x)) << INTERRUPT_TX_3_COMPLETE_LSB) & INTERRUPT_TX_3_COMPLETE_MASK)
#define INTERRUPT_TX_3_COMPLETE_RESET                                0
#define INTERRUPT_TX_2_COMPLETE_MSB                                  18
#define INTERRUPT_TX_2_COMPLETE_LSB                                  18
#define INTERRUPT_TX_2_COMPLETE_MASK                                 0x00040000
#define INTERRUPT_TX_2_COMPLETE_GET(x)                               (((x) & INTERRUPT_TX_2_COMPLETE_MASK) >> INTERRUPT_TX_2_COMPLETE_LSB)
#define INTERRUPT_TX_2_COMPLETE_SET(x)                               (((0 | (x)) << INTERRUPT_TX_2_COMPLETE_LSB) & INTERRUPT_TX_2_COMPLETE_MASK)
#define INTERRUPT_TX_2_COMPLETE_RESET                                0
#define INTERRUPT_TX_1_COMPLETE_MSB                                  17
#define INTERRUPT_TX_1_COMPLETE_LSB                                  17
#define INTERRUPT_TX_1_COMPLETE_MASK                                 0x00020000
#define INTERRUPT_TX_1_COMPLETE_GET(x)                               (((x) & INTERRUPT_TX_1_COMPLETE_MASK) >> INTERRUPT_TX_1_COMPLETE_LSB)
#define INTERRUPT_TX_1_COMPLETE_SET(x)                               (((0 | (x)) << INTERRUPT_TX_1_COMPLETE_LSB) & INTERRUPT_TX_1_COMPLETE_MASK)
#define INTERRUPT_TX_1_COMPLETE_RESET                                0
#define INTERRUPT_TX_0_COMPLETE_MSB                                  16
#define INTERRUPT_TX_0_COMPLETE_LSB                                  16
#define INTERRUPT_TX_0_COMPLETE_MASK                                 0x00010000
#define INTERRUPT_TX_0_COMPLETE_GET(x)                               (((x) & INTERRUPT_TX_0_COMPLETE_MASK) >> INTERRUPT_TX_0_COMPLETE_LSB)
#define INTERRUPT_TX_0_COMPLETE_SET(x)                               (((0 | (x)) << INTERRUPT_TX_0_COMPLETE_LSB) & INTERRUPT_TX_0_COMPLETE_MASK)
#define INTERRUPT_TX_0_COMPLETE_RESET                                0
#define INTERRUPT_RX_7_END_MSB                                       15
#define INTERRUPT_RX_7_END_LSB                                       15
#define INTERRUPT_RX_7_END_MASK                                      0x00008000
#define INTERRUPT_RX_7_END_GET(x)                                    (((x) & INTERRUPT_RX_7_END_MASK) >> INTERRUPT_RX_7_END_LSB)
#define INTERRUPT_RX_7_END_SET(x)                                    (((0 | (x)) << INTERRUPT_RX_7_END_LSB) & INTERRUPT_RX_7_END_MASK)
#define INTERRUPT_RX_7_END_RESET                                     0
#define INTERRUPT_RX_6_END_MSB                                       14
#define INTERRUPT_RX_6_END_LSB                                       14
#define INTERRUPT_RX_6_END_MASK                                      0x00004000
#define INTERRUPT_RX_6_END_GET(x)                                    (((x) & INTERRUPT_RX_6_END_MASK) >> INTERRUPT_RX_6_END_LSB)
#define INTERRUPT_RX_6_END_SET(x)                                    (((0 | (x)) << INTERRUPT_RX_6_END_LSB) & INTERRUPT_RX_6_END_MASK)
#define INTERRUPT_RX_6_END_RESET                                     0
#define INTERRUPT_RX_5_END_MSB                                       13
#define INTERRUPT_RX_5_END_LSB                                       13
#define INTERRUPT_RX_5_END_MASK                                      0x00002000
#define INTERRUPT_RX_5_END_GET(x)                                    (((x) & INTERRUPT_RX_5_END_MASK) >> INTERRUPT_RX_5_END_LSB)
#define INTERRUPT_RX_5_END_SET(x)                                    (((0 | (x)) << INTERRUPT_RX_5_END_LSB) & INTERRUPT_RX_5_END_MASK)
#define INTERRUPT_RX_5_END_RESET                                     0
#define INTERRUPT_RX_4_END_MSB                                       12
#define INTERRUPT_RX_4_END_LSB                                       12
#define INTERRUPT_RX_4_END_MASK                                      0x00001000
#define INTERRUPT_RX_4_END_GET(x)                                    (((x) & INTERRUPT_RX_4_END_MASK) >> INTERRUPT_RX_4_END_LSB)
#define INTERRUPT_RX_4_END_SET(x)                                    (((0 | (x)) << INTERRUPT_RX_4_END_LSB) & INTERRUPT_RX_4_END_MASK)
#define INTERRUPT_RX_4_END_RESET                                     0
#define INTERRUPT_RX_3_END_MSB                                       11
#define INTERRUPT_RX_3_END_LSB                                       11
#define INTERRUPT_RX_3_END_MASK                                      0x00000800
#define INTERRUPT_RX_3_END_GET(x)                                    (((x) & INTERRUPT_RX_3_END_MASK) >> INTERRUPT_RX_3_END_LSB)
#define INTERRUPT_RX_3_END_SET(x)                                    (((0 | (x)) << INTERRUPT_RX_3_END_LSB) & INTERRUPT_RX_3_END_MASK)
#define INTERRUPT_RX_3_END_RESET                                     0
#define INTERRUPT_RX_2_END_MSB                                       10
#define INTERRUPT_RX_2_END_LSB                                       10
#define INTERRUPT_RX_2_END_MASK                                      0x00000400
#define INTERRUPT_RX_2_END_GET(x)                                    (((x) & INTERRUPT_RX_2_END_MASK) >> INTERRUPT_RX_2_END_LSB)
#define INTERRUPT_RX_2_END_SET(x)                                    (((0 | (x)) << INTERRUPT_RX_2_END_LSB) & INTERRUPT_RX_2_END_MASK)
#define INTERRUPT_RX_2_END_RESET                                     0
#define INTERRUPT_RX_1_END_MSB                                       9
#define INTERRUPT_RX_1_END_LSB                                       9
#define INTERRUPT_RX_1_END_MASK                                      0x00000200
#define INTERRUPT_RX_1_END_GET(x)                                    (((x) & INTERRUPT_RX_1_END_MASK) >> INTERRUPT_RX_1_END_LSB)
#define INTERRUPT_RX_1_END_SET(x)                                    (((0 | (x)) << INTERRUPT_RX_1_END_LSB) & INTERRUPT_RX_1_END_MASK)
#define INTERRUPT_RX_1_END_RESET                                     0
#define INTERRUPT_RX_0_END_MSB                                       8
#define INTERRUPT_RX_0_END_LSB                                       8
#define INTERRUPT_RX_0_END_MASK                                      0x00000100
#define INTERRUPT_RX_0_END_GET(x)                                    (((x) & INTERRUPT_RX_0_END_MASK) >> INTERRUPT_RX_0_END_LSB)
#define INTERRUPT_RX_0_END_SET(x)                                    (((0 | (x)) << INTERRUPT_RX_0_END_LSB) & INTERRUPT_RX_0_END_MASK)
#define INTERRUPT_RX_0_END_RESET                                     0
#define INTERRUPT_RX_7_COMPLETE_MSB                                  7
#define INTERRUPT_RX_7_COMPLETE_LSB                                  7
#define INTERRUPT_RX_7_COMPLETE_MASK                                 0x00000080
#define INTERRUPT_RX_7_COMPLETE_GET(x)                               (((x) & INTERRUPT_RX_7_COMPLETE_MASK) >> INTERRUPT_RX_7_COMPLETE_LSB)
#define INTERRUPT_RX_7_COMPLETE_SET(x)                               (((0 | (x)) << INTERRUPT_RX_7_COMPLETE_LSB) & INTERRUPT_RX_7_COMPLETE_MASK)
#define INTERRUPT_RX_7_COMPLETE_RESET                                0
#define INTERRUPT_RX_6_COMPLETE_MSB                                  6
#define INTERRUPT_RX_6_COMPLETE_LSB                                  6
#define INTERRUPT_RX_6_COMPLETE_MASK                                 0x00000040
#define INTERRUPT_RX_6_COMPLETE_GET(x)                               (((x) & INTERRUPT_RX_6_COMPLETE_MASK) >> INTERRUPT_RX_6_COMPLETE_LSB)
#define INTERRUPT_RX_6_COMPLETE_SET(x)                               (((0 | (x)) << INTERRUPT_RX_6_COMPLETE_LSB) & INTERRUPT_RX_6_COMPLETE_MASK)
#define INTERRUPT_RX_6_COMPLETE_RESET                                0
#define INTERRUPT_RX_5_COMPLETE_MSB                                  5
#define INTERRUPT_RX_5_COMPLETE_LSB                                  5
#define INTERRUPT_RX_5_COMPLETE_MASK                                 0x00000020
#define INTERRUPT_RX_5_COMPLETE_GET(x)                               (((x) & INTERRUPT_RX_5_COMPLETE_MASK) >> INTERRUPT_RX_5_COMPLETE_LSB)
#define INTERRUPT_RX_5_COMPLETE_SET(x)                               (((0 | (x)) << INTERRUPT_RX_5_COMPLETE_LSB) & INTERRUPT_RX_5_COMPLETE_MASK)
#define INTERRUPT_RX_5_COMPLETE_RESET                                0
#define INTERRUPT_RX_4_COMPLETE_MSB                                  4
#define INTERRUPT_RX_4_COMPLETE_LSB                                  4
#define INTERRUPT_RX_4_COMPLETE_MASK                                 0x00000010
#define INTERRUPT_RX_4_COMPLETE_GET(x)                               (((x) & INTERRUPT_RX_4_COMPLETE_MASK) >> INTERRUPT_RX_4_COMPLETE_LSB)
#define INTERRUPT_RX_4_COMPLETE_SET(x)                               (((0 | (x)) << INTERRUPT_RX_4_COMPLETE_LSB) & INTERRUPT_RX_4_COMPLETE_MASK)
#define INTERRUPT_RX_4_COMPLETE_RESET                                0
#define INTERRUPT_RX_3_COMPLETE_MSB                                  3
#define INTERRUPT_RX_3_COMPLETE_LSB                                  3
#define INTERRUPT_RX_3_COMPLETE_MASK                                 0x00000008
#define INTERRUPT_RX_3_COMPLETE_GET(x)                               (((x) & INTERRUPT_RX_3_COMPLETE_MASK) >> INTERRUPT_RX_3_COMPLETE_LSB)
#define INTERRUPT_RX_3_COMPLETE_SET(x)                               (((0 | (x)) << INTERRUPT_RX_3_COMPLETE_LSB) & INTERRUPT_RX_3_COMPLETE_MASK)
#define INTERRUPT_RX_3_COMPLETE_RESET                                0
#define INTERRUPT_RX_2_COMPLETE_MSB                                  2
#define INTERRUPT_RX_2_COMPLETE_LSB                                  2
#define INTERRUPT_RX_2_COMPLETE_MASK                                 0x00000004
#define INTERRUPT_RX_2_COMPLETE_GET(x)                               (((x) & INTERRUPT_RX_2_COMPLETE_MASK) >> INTERRUPT_RX_2_COMPLETE_LSB)
#define INTERRUPT_RX_2_COMPLETE_SET(x)                               (((0 | (x)) << INTERRUPT_RX_2_COMPLETE_LSB) & INTERRUPT_RX_2_COMPLETE_MASK)
#define INTERRUPT_RX_2_COMPLETE_RESET                                0
#define INTERRUPT_RX_1_COMPLETE_MSB                                  1
#define INTERRUPT_RX_1_COMPLETE_LSB                                  1
#define INTERRUPT_RX_1_COMPLETE_MASK                                 0x00000002
#define INTERRUPT_RX_1_COMPLETE_GET(x)                               (((x) & INTERRUPT_RX_1_COMPLETE_MASK) >> INTERRUPT_RX_1_COMPLETE_LSB)
#define INTERRUPT_RX_1_COMPLETE_SET(x)                               (((0 | (x)) << INTERRUPT_RX_1_COMPLETE_LSB) & INTERRUPT_RX_1_COMPLETE_MASK)
#define INTERRUPT_RX_1_COMPLETE_RESET                                0
#define INTERRUPT_RX_0_COMPLETE_MSB                                  0
#define INTERRUPT_RX_0_COMPLETE_LSB                                  0
#define INTERRUPT_RX_0_COMPLETE_MASK                                 0x00000001
#define INTERRUPT_RX_0_COMPLETE_GET(x)                               (((x) & INTERRUPT_RX_0_COMPLETE_MASK) >> INTERRUPT_RX_0_COMPLETE_LSB)
#define INTERRUPT_RX_0_COMPLETE_SET(x)                               (((0 | (x)) << INTERRUPT_RX_0_COMPLETE_LSB) & INTERRUPT_RX_0_COMPLETE_MASK)
#define INTERRUPT_RX_0_COMPLETE_RESET                                0
#define INTERRUPT_ADDRESS                                            0x014c
#define INTERRUPT_HW_MASK                                            0xffffffff
#define INTERRUPT_SW_MASK                                            0xffffffff
#define INTERRUPT_HW_WRITE_MASK                                      0xffffffff
#define INTERRUPT_SW_WRITE_MASK                                      0x00000000
#define INTERRUPT_RSTMASK                                            0xffffffff
#define INTERRUPT_RESET                                              0x00000000

// 0x0150 (INTERRUPT_MASK)
#define INTERRUPT_MASK_TX_7_END_MASK_MSB                             31
#define INTERRUPT_MASK_TX_7_END_MASK_LSB                             31
#define INTERRUPT_MASK_TX_7_END_MASK_MASK                            0x80000000
#define INTERRUPT_MASK_TX_7_END_MASK_GET(x)                          (((x) & INTERRUPT_MASK_TX_7_END_MASK_MASK) >> INTERRUPT_MASK_TX_7_END_MASK_LSB)
#define INTERRUPT_MASK_TX_7_END_MASK_SET(x)                          (((0 | (x)) << INTERRUPT_MASK_TX_7_END_MASK_LSB) & INTERRUPT_MASK_TX_7_END_MASK_MASK)
#define INTERRUPT_MASK_TX_7_END_MASK_RESET                           0
#define INTERRUPT_MASK_TX_6_END_MASK_MSB                             30
#define INTERRUPT_MASK_TX_6_END_MASK_LSB                             30
#define INTERRUPT_MASK_TX_6_END_MASK_MASK                            0x40000000
#define INTERRUPT_MASK_TX_6_END_MASK_GET(x)                          (((x) & INTERRUPT_MASK_TX_6_END_MASK_MASK) >> INTERRUPT_MASK_TX_6_END_MASK_LSB)
#define INTERRUPT_MASK_TX_6_END_MASK_SET(x)                          (((0 | (x)) << INTERRUPT_MASK_TX_6_END_MASK_LSB) & INTERRUPT_MASK_TX_6_END_MASK_MASK)
#define INTERRUPT_MASK_TX_6_END_MASK_RESET                           0
#define INTERRUPT_MASK_TX_5_END_MASK_MSB                             29
#define INTERRUPT_MASK_TX_5_END_MASK_LSB                             29
#define INTERRUPT_MASK_TX_5_END_MASK_MASK                            0x20000000
#define INTERRUPT_MASK_TX_5_END_MASK_GET(x)                          (((x) & INTERRUPT_MASK_TX_5_END_MASK_MASK) >> INTERRUPT_MASK_TX_5_END_MASK_LSB)
#define INTERRUPT_MASK_TX_5_END_MASK_SET(x)                          (((0 | (x)) << INTERRUPT_MASK_TX_5_END_MASK_LSB) & INTERRUPT_MASK_TX_5_END_MASK_MASK)
#define INTERRUPT_MASK_TX_5_END_MASK_RESET                           0
#define INTERRUPT_MASK_TX_4_END_MASK_MSB                             28
#define INTERRUPT_MASK_TX_4_END_MASK_LSB                             28
#define INTERRUPT_MASK_TX_4_END_MASK_MASK                            0x10000000
#define INTERRUPT_MASK_TX_4_END_MASK_GET(x)                          (((x) & INTERRUPT_MASK_TX_4_END_MASK_MASK) >> INTERRUPT_MASK_TX_4_END_MASK_LSB)
#define INTERRUPT_MASK_TX_4_END_MASK_SET(x)                          (((0 | (x)) << INTERRUPT_MASK_TX_4_END_MASK_LSB) & INTERRUPT_MASK_TX_4_END_MASK_MASK)
#define INTERRUPT_MASK_TX_4_END_MASK_RESET                           0
#define INTERRUPT_MASK_TX_3_END_MASK_MSB                             27
#define INTERRUPT_MASK_TX_3_END_MASK_LSB                             27
#define INTERRUPT_MASK_TX_3_END_MASK_MASK                            0x08000000
#define INTERRUPT_MASK_TX_3_END_MASK_GET(x)                          (((x) & INTERRUPT_MASK_TX_3_END_MASK_MASK) >> INTERRUPT_MASK_TX_3_END_MASK_LSB)
#define INTERRUPT_MASK_TX_3_END_MASK_SET(x)                          (((0 | (x)) << INTERRUPT_MASK_TX_3_END_MASK_LSB) & INTERRUPT_MASK_TX_3_END_MASK_MASK)
#define INTERRUPT_MASK_TX_3_END_MASK_RESET                           0
#define INTERRUPT_MASK_TX_2_END_MASK_MSB                             26
#define INTERRUPT_MASK_TX_2_END_MASK_LSB                             26
#define INTERRUPT_MASK_TX_2_END_MASK_MASK                            0x04000000
#define INTERRUPT_MASK_TX_2_END_MASK_GET(x)                          (((x) & INTERRUPT_MASK_TX_2_END_MASK_MASK) >> INTERRUPT_MASK_TX_2_END_MASK_LSB)
#define INTERRUPT_MASK_TX_2_END_MASK_SET(x)                          (((0 | (x)) << INTERRUPT_MASK_TX_2_END_MASK_LSB) & INTERRUPT_MASK_TX_2_END_MASK_MASK)
#define INTERRUPT_MASK_TX_2_END_MASK_RESET                           0
#define INTERRUPT_MASK_TX_1_END_MASK_MSB                             25
#define INTERRUPT_MASK_TX_1_END_MASK_LSB                             25
#define INTERRUPT_MASK_TX_1_END_MASK_MASK                            0x02000000
#define INTERRUPT_MASK_TX_1_END_MASK_GET(x)                          (((x) & INTERRUPT_MASK_TX_1_END_MASK_MASK) >> INTERRUPT_MASK_TX_1_END_MASK_LSB)
#define INTERRUPT_MASK_TX_1_END_MASK_SET(x)                          (((0 | (x)) << INTERRUPT_MASK_TX_1_END_MASK_LSB) & INTERRUPT_MASK_TX_1_END_MASK_MASK)
#define INTERRUPT_MASK_TX_1_END_MASK_RESET                           0
#define INTERRUPT_MASK_TX_0_END_MASK_MSB                             24
#define INTERRUPT_MASK_TX_0_END_MASK_LSB                             24
#define INTERRUPT_MASK_TX_0_END_MASK_MASK                            0x01000000
#define INTERRUPT_MASK_TX_0_END_MASK_GET(x)                          (((x) & INTERRUPT_MASK_TX_0_END_MASK_MASK) >> INTERRUPT_MASK_TX_0_END_MASK_LSB)
#define INTERRUPT_MASK_TX_0_END_MASK_SET(x)                          (((0 | (x)) << INTERRUPT_MASK_TX_0_END_MASK_LSB) & INTERRUPT_MASK_TX_0_END_MASK_MASK)
#define INTERRUPT_MASK_TX_0_END_MASK_RESET                           0
#define INTERRUPT_MASK_TX_7_COMPLETE_MASK_MSB                        23
#define INTERRUPT_MASK_TX_7_COMPLETE_MASK_LSB                        23
#define INTERRUPT_MASK_TX_7_COMPLETE_MASK_MASK                       0x00800000
#define INTERRUPT_MASK_TX_7_COMPLETE_MASK_GET(x)                     (((x) & INTERRUPT_MASK_TX_7_COMPLETE_MASK_MASK) >> INTERRUPT_MASK_TX_7_COMPLETE_MASK_LSB)
#define INTERRUPT_MASK_TX_7_COMPLETE_MASK_SET(x)                     (((0 | (x)) << INTERRUPT_MASK_TX_7_COMPLETE_MASK_LSB) & INTERRUPT_MASK_TX_7_COMPLETE_MASK_MASK)
#define INTERRUPT_MASK_TX_7_COMPLETE_MASK_RESET                      0
#define INTERRUPT_MASK_TX_6_COMPLETE_MASK_MSB                        22
#define INTERRUPT_MASK_TX_6_COMPLETE_MASK_LSB                        22
#define INTERRUPT_MASK_TX_6_COMPLETE_MASK_MASK                       0x00400000
#define INTERRUPT_MASK_TX_6_COMPLETE_MASK_GET(x)                     (((x) & INTERRUPT_MASK_TX_6_COMPLETE_MASK_MASK) >> INTERRUPT_MASK_TX_6_COMPLETE_MASK_LSB)
#define INTERRUPT_MASK_TX_6_COMPLETE_MASK_SET(x)                     (((0 | (x)) << INTERRUPT_MASK_TX_6_COMPLETE_MASK_LSB) & INTERRUPT_MASK_TX_6_COMPLETE_MASK_MASK)
#define INTERRUPT_MASK_TX_6_COMPLETE_MASK_RESET                      0
#define INTERRUPT_MASK_TX_5_COMPLETE_MASK_MSB                        21
#define INTERRUPT_MASK_TX_5_COMPLETE_MASK_LSB                        21
#define INTERRUPT_MASK_TX_5_COMPLETE_MASK_MASK                       0x00200000
#define INTERRUPT_MASK_TX_5_COMPLETE_MASK_GET(x)                     (((x) & INTERRUPT_MASK_TX_5_COMPLETE_MASK_MASK) >> INTERRUPT_MASK_TX_5_COMPLETE_MASK_LSB)
#define INTERRUPT_MASK_TX_5_COMPLETE_MASK_SET(x)                     (((0 | (x)) << INTERRUPT_MASK_TX_5_COMPLETE_MASK_LSB) & INTERRUPT_MASK_TX_5_COMPLETE_MASK_MASK)
#define INTERRUPT_MASK_TX_5_COMPLETE_MASK_RESET                      0
#define INTERRUPT_MASK_TX_4_COMPLETE_MASK_MSB                        20
#define INTERRUPT_MASK_TX_4_COMPLETE_MASK_LSB                        20
#define INTERRUPT_MASK_TX_4_COMPLETE_MASK_MASK                       0x00100000
#define INTERRUPT_MASK_TX_4_COMPLETE_MASK_GET(x)                     (((x) & INTERRUPT_MASK_TX_4_COMPLETE_MASK_MASK) >> INTERRUPT_MASK_TX_4_COMPLETE_MASK_LSB)
#define INTERRUPT_MASK_TX_4_COMPLETE_MASK_SET(x)                     (((0 | (x)) << INTERRUPT_MASK_TX_4_COMPLETE_MASK_LSB) & INTERRUPT_MASK_TX_4_COMPLETE_MASK_MASK)
#define INTERRUPT_MASK_TX_4_COMPLETE_MASK_RESET                      0
#define INTERRUPT_MASK_TX_3_COMPLETE_MASK_MSB                        19
#define INTERRUPT_MASK_TX_3_COMPLETE_MASK_LSB                        19
#define INTERRUPT_MASK_TX_3_COMPLETE_MASK_MASK                       0x00080000
#define INTERRUPT_MASK_TX_3_COMPLETE_MASK_GET(x)                     (((x) & INTERRUPT_MASK_TX_3_COMPLETE_MASK_MASK) >> INTERRUPT_MASK_TX_3_COMPLETE_MASK_LSB)
#define INTERRUPT_MASK_TX_3_COMPLETE_MASK_SET(x)                     (((0 | (x)) << INTERRUPT_MASK_TX_3_COMPLETE_MASK_LSB) & INTERRUPT_MASK_TX_3_COMPLETE_MASK_MASK)
#define INTERRUPT_MASK_TX_3_COMPLETE_MASK_RESET                      0
#define INTERRUPT_MASK_TX_2_COMPLETE_MASK_MSB                        18
#define INTERRUPT_MASK_TX_2_COMPLETE_MASK_LSB                        18
#define INTERRUPT_MASK_TX_2_COMPLETE_MASK_MASK                       0x00040000
#define INTERRUPT_MASK_TX_2_COMPLETE_MASK_GET(x)                     (((x) & INTERRUPT_MASK_TX_2_COMPLETE_MASK_MASK) >> INTERRUPT_MASK_TX_2_COMPLETE_MASK_LSB)
#define INTERRUPT_MASK_TX_2_COMPLETE_MASK_SET(x)                     (((0 | (x)) << INTERRUPT_MASK_TX_2_COMPLETE_MASK_LSB) & INTERRUPT_MASK_TX_2_COMPLETE_MASK_MASK)
#define INTERRUPT_MASK_TX_2_COMPLETE_MASK_RESET                      0
#define INTERRUPT_MASK_TX_1_COMPLETE_MASK_MSB                        17
#define INTERRUPT_MASK_TX_1_COMPLETE_MASK_LSB                        17
#define INTERRUPT_MASK_TX_1_COMPLETE_MASK_MASK                       0x00020000
#define INTERRUPT_MASK_TX_1_COMPLETE_MASK_GET(x)                     (((x) & INTERRUPT_MASK_TX_1_COMPLETE_MASK_MASK) >> INTERRUPT_MASK_TX_1_COMPLETE_MASK_LSB)
#define INTERRUPT_MASK_TX_1_COMPLETE_MASK_SET(x)                     (((0 | (x)) << INTERRUPT_MASK_TX_1_COMPLETE_MASK_LSB) & INTERRUPT_MASK_TX_1_COMPLETE_MASK_MASK)
#define INTERRUPT_MASK_TX_1_COMPLETE_MASK_RESET                      0
#define INTERRUPT_MASK_TX_0_COMPLETE_MASK_MSB                        16
#define INTERRUPT_MASK_TX_0_COMPLETE_MASK_LSB                        16
#define INTERRUPT_MASK_TX_0_COMPLETE_MASK_MASK                       0x00010000
#define INTERRUPT_MASK_TX_0_COMPLETE_MASK_GET(x)                     (((x) & INTERRUPT_MASK_TX_0_COMPLETE_MASK_MASK) >> INTERRUPT_MASK_TX_0_COMPLETE_MASK_LSB)
#define INTERRUPT_MASK_TX_0_COMPLETE_MASK_SET(x)                     (((0 | (x)) << INTERRUPT_MASK_TX_0_COMPLETE_MASK_LSB) & INTERRUPT_MASK_TX_0_COMPLETE_MASK_MASK)
#define INTERRUPT_MASK_TX_0_COMPLETE_MASK_RESET                      0
#define INTERRUPT_MASK_RX_7_END_MASK_MSB                             15
#define INTERRUPT_MASK_RX_7_END_MASK_LSB                             15
#define INTERRUPT_MASK_RX_7_END_MASK_MASK                            0x00008000
#define INTERRUPT_MASK_RX_7_END_MASK_GET(x)                          (((x) & INTERRUPT_MASK_RX_7_END_MASK_MASK) >> INTERRUPT_MASK_RX_7_END_MASK_LSB)
#define INTERRUPT_MASK_RX_7_END_MASK_SET(x)                          (((0 | (x)) << INTERRUPT_MASK_RX_7_END_MASK_LSB) & INTERRUPT_MASK_RX_7_END_MASK_MASK)
#define INTERRUPT_MASK_RX_7_END_MASK_RESET                           0
#define INTERRUPT_MASK_RX_6_END_MASK_MSB                             14
#define INTERRUPT_MASK_RX_6_END_MASK_LSB                             14
#define INTERRUPT_MASK_RX_6_END_MASK_MASK                            0x00004000
#define INTERRUPT_MASK_RX_6_END_MASK_GET(x)                          (((x) & INTERRUPT_MASK_RX_6_END_MASK_MASK) >> INTERRUPT_MASK_RX_6_END_MASK_LSB)
#define INTERRUPT_MASK_RX_6_END_MASK_SET(x)                          (((0 | (x)) << INTERRUPT_MASK_RX_6_END_MASK_LSB) & INTERRUPT_MASK_RX_6_END_MASK_MASK)
#define INTERRUPT_MASK_RX_6_END_MASK_RESET                           0
#define INTERRUPT_MASK_RX_5_END_MASK_MSB                             13
#define INTERRUPT_MASK_RX_5_END_MASK_LSB                             13
#define INTERRUPT_MASK_RX_5_END_MASK_MASK                            0x00002000
#define INTERRUPT_MASK_RX_5_END_MASK_GET(x)                          (((x) & INTERRUPT_MASK_RX_5_END_MASK_MASK) >> INTERRUPT_MASK_RX_5_END_MASK_LSB)
#define INTERRUPT_MASK_RX_5_END_MASK_SET(x)                          (((0 | (x)) << INTERRUPT_MASK_RX_5_END_MASK_LSB) & INTERRUPT_MASK_RX_5_END_MASK_MASK)
#define INTERRUPT_MASK_RX_5_END_MASK_RESET                           0
#define INTERRUPT_MASK_RX_4_END_MASK_MSB                             12
#define INTERRUPT_MASK_RX_4_END_MASK_LSB                             12
#define INTERRUPT_MASK_RX_4_END_MASK_MASK                            0x00001000
#define INTERRUPT_MASK_RX_4_END_MASK_GET(x)                          (((x) & INTERRUPT_MASK_RX_4_END_MASK_MASK) >> INTERRUPT_MASK_RX_4_END_MASK_LSB)
#define INTERRUPT_MASK_RX_4_END_MASK_SET(x)                          (((0 | (x)) << INTERRUPT_MASK_RX_4_END_MASK_LSB) & INTERRUPT_MASK_RX_4_END_MASK_MASK)
#define INTERRUPT_MASK_RX_4_END_MASK_RESET                           0
#define INTERRUPT_MASK_RX_3_END_MASK_MSB                             11
#define INTERRUPT_MASK_RX_3_END_MASK_LSB                             11
#define INTERRUPT_MASK_RX_3_END_MASK_MASK                            0x00000800
#define INTERRUPT_MASK_RX_3_END_MASK_GET(x)                          (((x) & INTERRUPT_MASK_RX_3_END_MASK_MASK) >> INTERRUPT_MASK_RX_3_END_MASK_LSB)
#define INTERRUPT_MASK_RX_3_END_MASK_SET(x)                          (((0 | (x)) << INTERRUPT_MASK_RX_3_END_MASK_LSB) & INTERRUPT_MASK_RX_3_END_MASK_MASK)
#define INTERRUPT_MASK_RX_3_END_MASK_RESET                           0
#define INTERRUPT_MASK_RX_2_END_MASK_MSB                             10
#define INTERRUPT_MASK_RX_2_END_MASK_LSB                             10
#define INTERRUPT_MASK_RX_2_END_MASK_MASK                            0x00000400
#define INTERRUPT_MASK_RX_2_END_MASK_GET(x)                          (((x) & INTERRUPT_MASK_RX_2_END_MASK_MASK) >> INTERRUPT_MASK_RX_2_END_MASK_LSB)
#define INTERRUPT_MASK_RX_2_END_MASK_SET(x)                          (((0 | (x)) << INTERRUPT_MASK_RX_2_END_MASK_LSB) & INTERRUPT_MASK_RX_2_END_MASK_MASK)
#define INTERRUPT_MASK_RX_2_END_MASK_RESET                           0
#define INTERRUPT_MASK_RX_1_END_MASK_MSB                             9
#define INTERRUPT_MASK_RX_1_END_MASK_LSB                             9
#define INTERRUPT_MASK_RX_1_END_MASK_MASK                            0x00000200
#define INTERRUPT_MASK_RX_1_END_MASK_GET(x)                          (((x) & INTERRUPT_MASK_RX_1_END_MASK_MASK) >> INTERRUPT_MASK_RX_1_END_MASK_LSB)
#define INTERRUPT_MASK_RX_1_END_MASK_SET(x)                          (((0 | (x)) << INTERRUPT_MASK_RX_1_END_MASK_LSB) & INTERRUPT_MASK_RX_1_END_MASK_MASK)
#define INTERRUPT_MASK_RX_1_END_MASK_RESET                           0
#define INTERRUPT_MASK_RX_0_END_MASK_MSB                             8
#define INTERRUPT_MASK_RX_0_END_MASK_LSB                             8
#define INTERRUPT_MASK_RX_0_END_MASK_MASK                            0x00000100
#define INTERRUPT_MASK_RX_0_END_MASK_GET(x)                          (((x) & INTERRUPT_MASK_RX_0_END_MASK_MASK) >> INTERRUPT_MASK_RX_0_END_MASK_LSB)
#define INTERRUPT_MASK_RX_0_END_MASK_SET(x)                          (((0 | (x)) << INTERRUPT_MASK_RX_0_END_MASK_LSB) & INTERRUPT_MASK_RX_0_END_MASK_MASK)
#define INTERRUPT_MASK_RX_0_END_MASK_RESET                           0
#define INTERRUPT_MASK_RX_7_COMPLETE_MASK_MSB                        7
#define INTERRUPT_MASK_RX_7_COMPLETE_MASK_LSB                        7
#define INTERRUPT_MASK_RX_7_COMPLETE_MASK_MASK                       0x00000080
#define INTERRUPT_MASK_RX_7_COMPLETE_MASK_GET(x)                     (((x) & INTERRUPT_MASK_RX_7_COMPLETE_MASK_MASK) >> INTERRUPT_MASK_RX_7_COMPLETE_MASK_LSB)
#define INTERRUPT_MASK_RX_7_COMPLETE_MASK_SET(x)                     (((0 | (x)) << INTERRUPT_MASK_RX_7_COMPLETE_MASK_LSB) & INTERRUPT_MASK_RX_7_COMPLETE_MASK_MASK)
#define INTERRUPT_MASK_RX_7_COMPLETE_MASK_RESET                      0
#define INTERRUPT_MASK_RX_6_COMPLETE_MASK_MSB                        6
#define INTERRUPT_MASK_RX_6_COMPLETE_MASK_LSB                        6
#define INTERRUPT_MASK_RX_6_COMPLETE_MASK_MASK                       0x00000040
#define INTERRUPT_MASK_RX_6_COMPLETE_MASK_GET(x)                     (((x) & INTERRUPT_MASK_RX_6_COMPLETE_MASK_MASK) >> INTERRUPT_MASK_RX_6_COMPLETE_MASK_LSB)
#define INTERRUPT_MASK_RX_6_COMPLETE_MASK_SET(x)                     (((0 | (x)) << INTERRUPT_MASK_RX_6_COMPLETE_MASK_LSB) & INTERRUPT_MASK_RX_6_COMPLETE_MASK_MASK)
#define INTERRUPT_MASK_RX_6_COMPLETE_MASK_RESET                      0
#define INTERRUPT_MASK_RX_5_COMPLETE_MASK_MSB                        5
#define INTERRUPT_MASK_RX_5_COMPLETE_MASK_LSB                        5
#define INTERRUPT_MASK_RX_5_COMPLETE_MASK_MASK                       0x00000020
#define INTERRUPT_MASK_RX_5_COMPLETE_MASK_GET(x)                     (((x) & INTERRUPT_MASK_RX_5_COMPLETE_MASK_MASK) >> INTERRUPT_MASK_RX_5_COMPLETE_MASK_LSB)
#define INTERRUPT_MASK_RX_5_COMPLETE_MASK_SET(x)                     (((0 | (x)) << INTERRUPT_MASK_RX_5_COMPLETE_MASK_LSB) & INTERRUPT_MASK_RX_5_COMPLETE_MASK_MASK)
#define INTERRUPT_MASK_RX_5_COMPLETE_MASK_RESET                      0
#define INTERRUPT_MASK_RX_4_COMPLETE_MASK_MSB                        4
#define INTERRUPT_MASK_RX_4_COMPLETE_MASK_LSB                        4
#define INTERRUPT_MASK_RX_4_COMPLETE_MASK_MASK                       0x00000010
#define INTERRUPT_MASK_RX_4_COMPLETE_MASK_GET(x)                     (((x) & INTERRUPT_MASK_RX_4_COMPLETE_MASK_MASK) >> INTERRUPT_MASK_RX_4_COMPLETE_MASK_LSB)
#define INTERRUPT_MASK_RX_4_COMPLETE_MASK_SET(x)                     (((0 | (x)) << INTERRUPT_MASK_RX_4_COMPLETE_MASK_LSB) & INTERRUPT_MASK_RX_4_COMPLETE_MASK_MASK)
#define INTERRUPT_MASK_RX_4_COMPLETE_MASK_RESET                      0
#define INTERRUPT_MASK_RX_3_COMPLETE_MASK_MSB                        3
#define INTERRUPT_MASK_RX_3_COMPLETE_MASK_LSB                        3
#define INTERRUPT_MASK_RX_3_COMPLETE_MASK_MASK                       0x00000008
#define INTERRUPT_MASK_RX_3_COMPLETE_MASK_GET(x)                     (((x) & INTERRUPT_MASK_RX_3_COMPLETE_MASK_MASK) >> INTERRUPT_MASK_RX_3_COMPLETE_MASK_LSB)
#define INTERRUPT_MASK_RX_3_COMPLETE_MASK_SET(x)                     (((0 | (x)) << INTERRUPT_MASK_RX_3_COMPLETE_MASK_LSB) & INTERRUPT_MASK_RX_3_COMPLETE_MASK_MASK)
#define INTERRUPT_MASK_RX_3_COMPLETE_MASK_RESET                      0
#define INTERRUPT_MASK_RX_2_COMPLETE_MASK_MSB                        2
#define INTERRUPT_MASK_RX_2_COMPLETE_MASK_LSB                        2
#define INTERRUPT_MASK_RX_2_COMPLETE_MASK_MASK                       0x00000004
#define INTERRUPT_MASK_RX_2_COMPLETE_MASK_GET(x)                     (((x) & INTERRUPT_MASK_RX_2_COMPLETE_MASK_MASK) >> INTERRUPT_MASK_RX_2_COMPLETE_MASK_LSB)
#define INTERRUPT_MASK_RX_2_COMPLETE_MASK_SET(x)                     (((0 | (x)) << INTERRUPT_MASK_RX_2_COMPLETE_MASK_LSB) & INTERRUPT_MASK_RX_2_COMPLETE_MASK_MASK)
#define INTERRUPT_MASK_RX_2_COMPLETE_MASK_RESET                      0
#define INTERRUPT_MASK_RX_1_COMPLETE_MASK_MSB                        1
#define INTERRUPT_MASK_RX_1_COMPLETE_MASK_LSB                        1
#define INTERRUPT_MASK_RX_1_COMPLETE_MASK_MASK                       0x00000002
#define INTERRUPT_MASK_RX_1_COMPLETE_MASK_GET(x)                     (((x) & INTERRUPT_MASK_RX_1_COMPLETE_MASK_MASK) >> INTERRUPT_MASK_RX_1_COMPLETE_MASK_LSB)
#define INTERRUPT_MASK_RX_1_COMPLETE_MASK_SET(x)                     (((0 | (x)) << INTERRUPT_MASK_RX_1_COMPLETE_MASK_LSB) & INTERRUPT_MASK_RX_1_COMPLETE_MASK_MASK)
#define INTERRUPT_MASK_RX_1_COMPLETE_MASK_RESET                      0
#define INTERRUPT_MASK_RX_0_COMPLETE_MASK_MSB                        0
#define INTERRUPT_MASK_RX_0_COMPLETE_MASK_LSB                        0
#define INTERRUPT_MASK_RX_0_COMPLETE_MASK_MASK                       0x00000001
#define INTERRUPT_MASK_RX_0_COMPLETE_MASK_GET(x)                     (((x) & INTERRUPT_MASK_RX_0_COMPLETE_MASK_MASK) >> INTERRUPT_MASK_RX_0_COMPLETE_MASK_LSB)
#define INTERRUPT_MASK_RX_0_COMPLETE_MASK_SET(x)                     (((0 | (x)) << INTERRUPT_MASK_RX_0_COMPLETE_MASK_LSB) & INTERRUPT_MASK_RX_0_COMPLETE_MASK_MASK)
#define INTERRUPT_MASK_RX_0_COMPLETE_MASK_RESET                      0
#define INTERRUPT_MASK_ADDRESS                                       0x0150
#define INTERRUPT_MASK_HW_MASK                                       0xffffffff
#define INTERRUPT_MASK_SW_MASK                                       0xffffffff
#define INTERRUPT_MASK_HW_WRITE_MASK                                 0x00000000
#define INTERRUPT_MASK_SW_WRITE_MASK                                 0xffffffff
#define INTERRUPT_MASK_RSTMASK                                       0xffffffff
#define INTERRUPT_MASK_RESET                                         0x00000000

// 0x0154 (USB_DEBUG)
#define USB_DEBUG_SEL_MSB                                            3
#define USB_DEBUG_SEL_LSB                                            0
#define USB_DEBUG_SEL_MASK                                           0x0000000f
#define USB_DEBUG_SEL_GET(x)                                         (((x) & USB_DEBUG_SEL_MASK) >> USB_DEBUG_SEL_LSB)
#define USB_DEBUG_SEL_SET(x)                                         (((0 | (x)) << USB_DEBUG_SEL_LSB) & USB_DEBUG_SEL_MASK)
#define USB_DEBUG_SEL_RESET                                          0
#define USB_DEBUG_ADDRESS                                            0x0154
#define USB_DEBUG_HW_MASK                                            0x0000000f
#define USB_DEBUG_SW_MASK                                            0x0000000f
#define USB_DEBUG_HW_WRITE_MASK                                      0x00000000
#define USB_DEBUG_SW_WRITE_MASK                                      0x0000000f
#define USB_DEBUG_RSTMASK                                            0xffffffff
#define USB_DEBUG_RESET                                              0x00000000


#endif /* _USB_DMA_REG_CSR_H_ */
