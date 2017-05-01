//                                                                             
// File:       blueprint/athrUartCsr.vh                                        
// Creator:    jeff                                                            
// Time:       Tuesday Nov 3, 2009 [4:09:39 pm]                                
//                                                                             
// Path:       /trees/jeff/valkyrie/ip/uart/dev/rtl                            
// Arguments:  /cad/denali/blueprint/3.7//Linux/blueprint -odir blueprint      
//             -verilog -vh -truncateenum -cpuerroroff -addrwidth 8 -datawidth 
//             32 -validheld -cycleaccess athrUartCsr.rdl                      
//                                                                             
// Sources:    /trees/jeff/valkyrie/ip/uart/dev/rtl/athrUartCsr.rdl            
//                                                                             
// Blueprint:   3.7 (Fri Oct 5 10:32:33 PDT 2007)                              
// Machine:    wobegon                                                         
// OS:         Linux 2.6.18-128.1.1.el5                                        
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
//                                                                             


// macros for register UartData
`define UARTDATA_REG_NUM                                                  1
`define UARTDATA_REG_ADDR                                                 0
`define UARTDATA_REG_STRIDE                                               4
`define UARTDATA_REG_SIZE                                                32
`define UARTDATA_REG_ACC_SIZE                                            32
`define UARTDATA_REG_READ_MSB                                             9
`define UARTDATA_REG_READ_LSB                                             0
`define UARTDATA_REG_READ_RANGE                                         9:0
`define UARTDATA_REG_WRITE_MSB                                            9
`define UARTDATA_REG_WRITE_LSB                                            0
`define UARTDATA_REG_WRITE_RANGE                                        9:0

// macros for field UartData.UartTxRxData
`define UARTDATA_UARTTXRXDATA_RANGE                                     7:0
`define UARTDATA_UARTTXRXDATA_MSB                                         7
`define UARTDATA_UARTTXRXDATA_LSB                                         0
`define UARTDATA_UARTTXRXDATA_WIDTH                                       8

// macros for field UartData.UartRxCsr
`define UARTDATA_UARTRXCSR_RANGE                                        8:8
`define UARTDATA_UARTRXCSR_MSB                                            8
`define UARTDATA_UARTRXCSR_LSB                                            8
`define UARTDATA_UARTRXCSR_WIDTH                                          1

// macros for field UartData.UartTxCsr
`define UARTDATA_UARTTXCSR_RANGE                                        9:9
`define UARTDATA_UARTTXCSR_MSB                                            9
`define UARTDATA_UARTTXCSR_LSB                                            9
`define UARTDATA_UARTTXCSR_WIDTH                                          1

// macros for register UartCs
`define UARTCS_REG_NUM                                                    1
`define UARTCS_REG_ADDR                                                   4
`define UARTCS_REG_STRIDE                                                 4
`define UARTCS_REG_SIZE                                                  32
`define UARTCS_REG_ACC_SIZE                                              32
`define UARTCS_REG_READ_MSB                                              15
`define UARTCS_REG_READ_LSB                                               0
`define UARTCS_REG_READ_RANGE                                          15:0
`define UARTCS_REG_WRITE_MSB                                             13
`define UARTCS_REG_WRITE_LSB                                              0
`define UARTCS_REG_WRITE_RANGE                                         13:0

// macros for field UartCs.UartRxBusy
`define UARTCS_UARTRXBUSY_RANGE                                       15:15
`define UARTCS_UARTRXBUSY_MSB                                            15
`define UARTCS_UARTRXBUSY_LSB                                            15
`define UARTCS_UARTRXBUSY_WIDTH                                           1

// macros for field UartCs.UartTxBusy
`define UARTCS_UARTTXBUSY_RANGE                                       14:14
`define UARTCS_UARTTXBUSY_MSB                                            14
`define UARTCS_UARTTXBUSY_LSB                                            14
`define UARTCS_UARTTXBUSY_WIDTH                                           1

// macros for field UartCs.UartHostIntEn
`define UARTCS_UARTHOSTINTEN_RANGE                                    13:13
`define UARTCS_UARTHOSTINTEN_MSB                                         13
`define UARTCS_UARTHOSTINTEN_LSB                                         13
`define UARTCS_UARTHOSTINTEN_WIDTH                                        1

// macros for field UartCs.UartHostInt
`define UARTCS_UARTHOSTINT_RANGE                                      12:12
`define UARTCS_UARTHOSTINT_MSB                                           12
`define UARTCS_UARTHOSTINT_LSB                                           12
`define UARTCS_UARTHOSTINT_WIDTH                                          1

// macros for field UartCs.UartTxBreak
`define UARTCS_UARTTXBREAK_RANGE                                      11:11
`define UARTCS_UARTTXBREAK_MSB                                           11
`define UARTCS_UARTTXBREAK_LSB                                           11
`define UARTCS_UARTTXBREAK_WIDTH                                          1

// macros for field UartCs.UartRxBreak
`define UARTCS_UARTRXBREAK_RANGE                                      10:10
`define UARTCS_UARTRXBREAK_MSB                                           10
`define UARTCS_UARTRXBREAK_LSB                                           10
`define UARTCS_UARTRXBREAK_WIDTH                                          1

// macros for field UartCs.UartSeriaTxReady
`define UARTCS_UARTSERIATXREADY_RANGE                                   9:9
`define UARTCS_UARTSERIATXREADY_MSB                                       9
`define UARTCS_UARTSERIATXREADY_LSB                                       9
`define UARTCS_UARTSERIATXREADY_WIDTH                                     1

// macros for field UartCs.UartTxReadyOride
`define UARTCS_UARTTXREADYORIDE_RANGE                                   8:8
`define UARTCS_UARTTXREADYORIDE_MSB                                       8
`define UARTCS_UARTTXREADYORIDE_LSB                                       8
`define UARTCS_UARTTXREADYORIDE_WIDTH                                     1

// macros for field UartCs.UartRxReadyOride
`define UARTCS_UARTRXREADYORIDE_RANGE                                   7:7
`define UARTCS_UARTRXREADYORIDE_MSB                                       7
`define UARTCS_UARTRXREADYORIDE_LSB                                       7
`define UARTCS_UARTRXREADYORIDE_WIDTH                                     1

// macros for field UartCs.UartDmaEn
`define UARTCS_UARTDMAEN_RANGE                                          6:6
`define UARTCS_UARTDMAEN_MSB                                              6
`define UARTCS_UARTDMAEN_LSB                                              6
`define UARTCS_UARTDMAEN_WIDTH                                            1

// macros for field UartCs.UartFlowControlMode
`define UARTCS_UARTFLOWCONTROLMODE_RANGE                                5:4
`define UARTCS_UARTFLOWCONTROLMODE_MSB                                    5
`define UARTCS_UARTFLOWCONTROLMODE_LSB                                    4
`define UARTCS_UARTFLOWCONTROLMODE_WIDTH                                  2
//  *enum*  macros for field UartCs.UartFlowControlMode
`define UARTFLOWCONTROLNONE                                           2'b00
`define UARTFLOWCONTROLHW                                             2'b10
`define UARTFLOWCONTROLINVERT                                         2'b11

// macros for field UartCs.UartInterfaceMode
`define UARTCS_UARTINTERFACEMODE_RANGE                                  3:2
`define UARTCS_UARTINTERFACEMODE_MSB                                      3
`define UARTCS_UARTINTERFACEMODE_LSB                                      2
`define UARTCS_UARTINTERFACEMODE_WIDTH                                    2
//  *enum*  macros for field UartCs.UartInterfaceMode
`define UARTINTERFACENONE                                             2'b00
`define UARTINTERFACEDTE                                              2'b10
`define UARTINTERFACEDCE                                              2'b11

// macros for field UartCs.UartParityMode
`define UARTCS_UARTPARITYMODE_RANGE                                     1:0
`define UARTCS_UARTPARITYMODE_MSB                                         1
`define UARTCS_UARTPARITYMODE_LSB                                         0
`define UARTCS_UARTPARITYMODE_WIDTH                                       2
//  *enum*  macros for field UartCs.UartParityMode
`define UARTPARITYNONE                                                2'b00
`define UARTPARITYODD                                                 2'b10
`define UARTPARITYEVEN                                                2'b11

// macros for register UartClock
`define UARTCLOCK_REG_NUM                                                 1
`define UARTCLOCK_REG_ADDR                                                8
`define UARTCLOCK_REG_STRIDE                                              4
`define UARTCLOCK_REG_SIZE                                               32
`define UARTCLOCK_REG_ACC_SIZE                                           32
`define UARTCLOCK_REG_READ_MSB                                           23
`define UARTCLOCK_REG_READ_LSB                                            0
`define UARTCLOCK_REG_READ_RANGE                                       23:0
`define UARTCLOCK_REG_WRITE_MSB                                          23
`define UARTCLOCK_REG_WRITE_LSB                                           0
`define UARTCLOCK_REG_WRITE_RANGE                                      23:0

// macros for field UartClock.UartClockScale
`define UARTCLOCK_UARTCLOCKSCALE_RANGE                                23:16
`define UARTCLOCK_UARTCLOCKSCALE_MSB                                     23
`define UARTCLOCK_UARTCLOCKSCALE_LSB                                     16
`define UARTCLOCK_UARTCLOCKSCALE_WIDTH                                    8

// macros for field UartClock.UartClockStep
`define UARTCLOCK_UARTCLOCKSTEP_RANGE                                  15:0
`define UARTCLOCK_UARTCLOCKSTEP_MSB                                      15
`define UARTCLOCK_UARTCLOCKSTEP_LSB                                       0
`define UARTCLOCK_UARTCLOCKSTEP_WIDTH                                    16

// macros for register UartInt
`define UARTINT_REG_NUM                                                   1
`define UARTINT_REG_ADDR                                                 12
`define UARTINT_REG_STRIDE                                                4
`define UARTINT_REG_SIZE                                                 32
`define UARTINT_REG_ACC_SIZE                                             32
`define UARTINT_REG_READ_MSB                                              9
`define UARTINT_REG_READ_LSB                                              0
`define UARTINT_REG_READ_RANGE                                          9:0
`define UARTINT_REG_WRITE_MSB                                             9
`define UARTINT_REG_WRITE_LSB                                             0
`define UARTINT_REG_WRITE_RANGE                                         9:0

// macros for field UartInt.UartTxEmptyInt
`define UARTINT_UARTTXEMPTYINT_RANGE                                    9:9
`define UARTINT_UARTTXEMPTYINT_MSB                                        9
`define UARTINT_UARTTXEMPTYINT_LSB                                        9
`define UARTINT_UARTTXEMPTYINT_WIDTH                                      1

// macros for field UartInt.UartRxFullInt
`define UARTINT_UARTRXFULLINT_RANGE                                     8:8
`define UARTINT_UARTRXFULLINT_MSB                                         8
`define UARTINT_UARTRXFULLINT_LSB                                         8
`define UARTINT_UARTRXFULLINT_WIDTH                                       1

// macros for field UartInt.UartRxBreakOffInt
`define UARTINT_UARTRXBREAKOFFINT_RANGE                                 7:7
`define UARTINT_UARTRXBREAKOFFINT_MSB                                     7
`define UARTINT_UARTRXBREAKOFFINT_LSB                                     7
`define UARTINT_UARTRXBREAKOFFINT_WIDTH                                   1

// macros for field UartInt.UartRxBreakOnInt
`define UARTINT_UARTRXBREAKONINT_RANGE                                  6:6
`define UARTINT_UARTRXBREAKONINT_MSB                                      6
`define UARTINT_UARTRXBREAKONINT_LSB                                      6
`define UARTINT_UARTRXBREAKONINT_WIDTH                                    1

// macros for field UartInt.UartRxParityErrInt
`define UARTINT_UARTRXPARITYERRINT_RANGE                                5:5
`define UARTINT_UARTRXPARITYERRINT_MSB                                    5
`define UARTINT_UARTRXPARITYERRINT_LSB                                    5
`define UARTINT_UARTRXPARITYERRINT_WIDTH                                  1

// macros for field UartInt.UartTxOflowErrInt
`define UARTINT_UARTTXOFLOWERRINT_RANGE                                 4:4
`define UARTINT_UARTTXOFLOWERRINT_MSB                                     4
`define UARTINT_UARTTXOFLOWERRINT_LSB                                     4
`define UARTINT_UARTTXOFLOWERRINT_WIDTH                                   1

// macros for field UartInt.UartRxOflowErrInt
`define UARTINT_UARTRXOFLOWERRINT_RANGE                                 3:3
`define UARTINT_UARTRXOFLOWERRINT_MSB                                     3
`define UARTINT_UARTRXOFLOWERRINT_LSB                                     3
`define UARTINT_UARTRXOFLOWERRINT_WIDTH                                   1

// macros for field UartInt.UartRxFramingErrInt
`define UARTINT_UARTRXFRAMINGERRINT_RANGE                               2:2
`define UARTINT_UARTRXFRAMINGERRINT_MSB                                   2
`define UARTINT_UARTRXFRAMINGERRINT_LSB                                   2
`define UARTINT_UARTRXFRAMINGERRINT_WIDTH                                 1

// macros for field UartInt.UartTxReadyInt
`define UARTINT_UARTTXREADYINT_RANGE                                    1:1
`define UARTINT_UARTTXREADYINT_MSB                                        1
`define UARTINT_UARTTXREADYINT_LSB                                        1
`define UARTINT_UARTTXREADYINT_WIDTH                                      1

// macros for field UartInt.UartRxValidInt
`define UARTINT_UARTRXVALIDINT_RANGE                                    0:0
`define UARTINT_UARTRXVALIDINT_MSB                                        0
`define UARTINT_UARTRXVALIDINT_LSB                                        0
`define UARTINT_UARTRXVALIDINT_WIDTH                                      1

// macros for register UartIntEn
`define UARTINTEN_REG_NUM                                                 1
`define UARTINTEN_REG_ADDR                                               16
`define UARTINTEN_REG_STRIDE                                              4
`define UARTINTEN_REG_SIZE                                               32
`define UARTINTEN_REG_ACC_SIZE                                           32
`define UARTINTEN_REG_READ_MSB                                            9
`define UARTINTEN_REG_READ_LSB                                            0
`define UARTINTEN_REG_READ_RANGE                                        9:0
`define UARTINTEN_REG_WRITE_MSB                                           9
`define UARTINTEN_REG_WRITE_LSB                                           0
`define UARTINTEN_REG_WRITE_RANGE                                       9:0

// macros for field UartIntEn.UartTxEmptyIntEn
`define UARTINTEN_UARTTXEMPTYINTEN_RANGE                                9:9
`define UARTINTEN_UARTTXEMPTYINTEN_MSB                                    9
`define UARTINTEN_UARTTXEMPTYINTEN_LSB                                    9
`define UARTINTEN_UARTTXEMPTYINTEN_WIDTH                                  1

// macros for field UartIntEn.UartRxFullIntEn
`define UARTINTEN_UARTRXFULLINTEN_RANGE                                 8:8
`define UARTINTEN_UARTRXFULLINTEN_MSB                                     8
`define UARTINTEN_UARTRXFULLINTEN_LSB                                     8
`define UARTINTEN_UARTRXFULLINTEN_WIDTH                                   1

// macros for field UartIntEn.UartRxBreakOffIntEn
`define UARTINTEN_UARTRXBREAKOFFINTEN_RANGE                             7:7
`define UARTINTEN_UARTRXBREAKOFFINTEN_MSB                                 7
`define UARTINTEN_UARTRXBREAKOFFINTEN_LSB                                 7
`define UARTINTEN_UARTRXBREAKOFFINTEN_WIDTH                               1

// macros for field UartIntEn.UartRxBreakOnIntEn
`define UARTINTEN_UARTRXBREAKONINTEN_RANGE                              6:6
`define UARTINTEN_UARTRXBREAKONINTEN_MSB                                  6
`define UARTINTEN_UARTRXBREAKONINTEN_LSB                                  6
`define UARTINTEN_UARTRXBREAKONINTEN_WIDTH                                1

// macros for field UartIntEn.UartRxParityErrIntEn
`define UARTINTEN_UARTRXPARITYERRINTEN_RANGE                            5:5
`define UARTINTEN_UARTRXPARITYERRINTEN_MSB                                5
`define UARTINTEN_UARTRXPARITYERRINTEN_LSB                                5
`define UARTINTEN_UARTRXPARITYERRINTEN_WIDTH                              1

// macros for field UartIntEn.UartTxOflowErrIntEn
`define UARTINTEN_UARTTXOFLOWERRINTEN_RANGE                             4:4
`define UARTINTEN_UARTTXOFLOWERRINTEN_MSB                                 4
`define UARTINTEN_UARTTXOFLOWERRINTEN_LSB                                 4
`define UARTINTEN_UARTTXOFLOWERRINTEN_WIDTH                               1

// macros for field UartIntEn.UartRxOflowErrIntEn
`define UARTINTEN_UARTRXOFLOWERRINTEN_RANGE                             3:3
`define UARTINTEN_UARTRXOFLOWERRINTEN_MSB                                 3
`define UARTINTEN_UARTRXOFLOWERRINTEN_LSB                                 3
`define UARTINTEN_UARTRXOFLOWERRINTEN_WIDTH                               1

// macros for field UartIntEn.UartRxFramingErrIntEn
`define UARTINTEN_UARTRXFRAMINGERRINTEN_RANGE                           2:2
`define UARTINTEN_UARTRXFRAMINGERRINTEN_MSB                               2
`define UARTINTEN_UARTRXFRAMINGERRINTEN_LSB                               2
`define UARTINTEN_UARTRXFRAMINGERRINTEN_WIDTH                             1

// macros for field UartIntEn.UartTxReadyIntEn
`define UARTINTEN_UARTTXREADYINTEN_RANGE                                1:1
`define UARTINTEN_UARTTXREADYINTEN_MSB                                    1
`define UARTINTEN_UARTTXREADYINTEN_LSB                                    1
`define UARTINTEN_UARTTXREADYINTEN_WIDTH                                  1

// macros for field UartIntEn.UartRxValidIntEn
`define UARTINTEN_UARTRXVALIDINTEN_RANGE                                0:0
`define UARTINTEN_UARTRXVALIDINTEN_MSB                                    0
`define UARTINTEN_UARTRXVALIDINTEN_LSB                                    0
`define UARTINTEN_UARTRXVALIDINTEN_WIDTH                                  1

