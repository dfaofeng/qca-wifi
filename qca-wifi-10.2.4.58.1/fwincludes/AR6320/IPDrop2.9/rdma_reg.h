#ifndef _RDMA_REG_REG_H_
#define _RDMA_REG_REG_H_

#define DMA_CONFIG_ADDRESS                       0x00000000
#define DMA_CONFIG_OFFSET                        0x00000000
#define DMA_CONFIG_WLBB_PWD_EN_MSB               4
#define DMA_CONFIG_WLBB_PWD_EN_LSB               4
#define DMA_CONFIG_WLBB_PWD_EN_MASK              0x00000010
#define DMA_CONFIG_WLBB_PWD_EN_GET(x)            (((x) & DMA_CONFIG_WLBB_PWD_EN_MASK) >> DMA_CONFIG_WLBB_PWD_EN_LSB)
#define DMA_CONFIG_WLBB_PWD_EN_SET(x)            (((x) << DMA_CONFIG_WLBB_PWD_EN_LSB) & DMA_CONFIG_WLBB_PWD_EN_MASK)
#define DMA_CONFIG_WLMAC_PWD_EN_MSB              3
#define DMA_CONFIG_WLMAC_PWD_EN_LSB              3
#define DMA_CONFIG_WLMAC_PWD_EN_MASK             0x00000008
#define DMA_CONFIG_WLMAC_PWD_EN_GET(x)           (((x) & DMA_CONFIG_WLMAC_PWD_EN_MASK) >> DMA_CONFIG_WLMAC_PWD_EN_LSB)
#define DMA_CONFIG_WLMAC_PWD_EN_SET(x)           (((x) << DMA_CONFIG_WLMAC_PWD_EN_LSB) & DMA_CONFIG_WLMAC_PWD_EN_MASK)
#define DMA_CONFIG_ENABLE_RETENTION_MSB          2
#define DMA_CONFIG_ENABLE_RETENTION_LSB          2
#define DMA_CONFIG_ENABLE_RETENTION_MASK         0x00000004
#define DMA_CONFIG_ENABLE_RETENTION_GET(x)       (((x) & DMA_CONFIG_ENABLE_RETENTION_MASK) >> DMA_CONFIG_ENABLE_RETENTION_LSB)
#define DMA_CONFIG_ENABLE_RETENTION_SET(x)       (((x) << DMA_CONFIG_ENABLE_RETENTION_LSB) & DMA_CONFIG_ENABLE_RETENTION_MASK)
#define DMA_CONFIG_RTC_PRIORITY_MSB              1
#define DMA_CONFIG_RTC_PRIORITY_LSB              1
#define DMA_CONFIG_RTC_PRIORITY_MASK             0x00000002
#define DMA_CONFIG_RTC_PRIORITY_GET(x)           (((x) & DMA_CONFIG_RTC_PRIORITY_MASK) >> DMA_CONFIG_RTC_PRIORITY_LSB)
#define DMA_CONFIG_RTC_PRIORITY_SET(x)           (((x) << DMA_CONFIG_RTC_PRIORITY_LSB) & DMA_CONFIG_RTC_PRIORITY_MASK)
#define DMA_CONFIG_DMA_TYPE_MSB                  0
#define DMA_CONFIG_DMA_TYPE_LSB                  0
#define DMA_CONFIG_DMA_TYPE_MASK                 0x00000001
#define DMA_CONFIG_DMA_TYPE_GET(x)               (((x) & DMA_CONFIG_DMA_TYPE_MASK) >> DMA_CONFIG_DMA_TYPE_LSB)
#define DMA_CONFIG_DMA_TYPE_SET(x)               (((x) << DMA_CONFIG_DMA_TYPE_LSB) & DMA_CONFIG_DMA_TYPE_MASK)

#define DMA_CONTROL_ADDRESS                      0x00000004
#define DMA_CONTROL_OFFSET                       0x00000004
#define DMA_CONTROL_START_MSB                    1
#define DMA_CONTROL_START_LSB                    1
#define DMA_CONTROL_START_MASK                   0x00000002
#define DMA_CONTROL_START_GET(x)                 (((x) & DMA_CONTROL_START_MASK) >> DMA_CONTROL_START_LSB)
#define DMA_CONTROL_START_SET(x)                 (((x) << DMA_CONTROL_START_LSB) & DMA_CONTROL_START_MASK)
#define DMA_CONTROL_STOP_MSB                     0
#define DMA_CONTROL_STOP_LSB                     0
#define DMA_CONTROL_STOP_MASK                    0x00000001
#define DMA_CONTROL_STOP_GET(x)                  (((x) & DMA_CONTROL_STOP_MASK) >> DMA_CONTROL_STOP_LSB)
#define DMA_CONTROL_STOP_SET(x)                  (((x) << DMA_CONTROL_STOP_LSB) & DMA_CONTROL_STOP_MASK)

#define DMA_SRC_ADDRESS                          0x00000008
#define DMA_SRC_OFFSET                           0x00000008
#define DMA_SRC_ADDR_MSB                         31
#define DMA_SRC_ADDR_LSB                         2
#define DMA_SRC_ADDR_MASK                        0xfffffffc
#define DMA_SRC_ADDR_GET(x)                      (((x) & DMA_SRC_ADDR_MASK) >> DMA_SRC_ADDR_LSB)
#define DMA_SRC_ADDR_SET(x)                      (((x) << DMA_SRC_ADDR_LSB) & DMA_SRC_ADDR_MASK)

#define DMA_DEST_ADDRESS                         0x0000000c
#define DMA_DEST_OFFSET                          0x0000000c
#define DMA_DEST_ADDR_MSB                        31
#define DMA_DEST_ADDR_LSB                        2
#define DMA_DEST_ADDR_MASK                       0xfffffffc
#define DMA_DEST_ADDR_GET(x)                     (((x) & DMA_DEST_ADDR_MASK) >> DMA_DEST_ADDR_LSB)
#define DMA_DEST_ADDR_SET(x)                     (((x) << DMA_DEST_ADDR_LSB) & DMA_DEST_ADDR_MASK)

#define DMA_LENGTH_ADDRESS                       0x00000010
#define DMA_LENGTH_OFFSET                        0x00000010
#define DMA_LENGTH_WORDS_MSB                     11
#define DMA_LENGTH_WORDS_LSB                     0
#define DMA_LENGTH_WORDS_MASK                    0x00000fff
#define DMA_LENGTH_WORDS_GET(x)                  (((x) & DMA_LENGTH_WORDS_MASK) >> DMA_LENGTH_WORDS_LSB)
#define DMA_LENGTH_WORDS_SET(x)                  (((x) << DMA_LENGTH_WORDS_LSB) & DMA_LENGTH_WORDS_MASK)

#define VMC_BASE_ADDRESS                         0x00000014
#define VMC_BASE_OFFSET                          0x00000014
#define VMC_BASE_ADDR_MSB                        31
#define VMC_BASE_ADDR_LSB                        2
#define VMC_BASE_ADDR_MASK                       0xfffffffc
#define VMC_BASE_ADDR_GET(x)                     (((x) & VMC_BASE_ADDR_MASK) >> VMC_BASE_ADDR_LSB)
#define VMC_BASE_ADDR_SET(x)                     (((x) << VMC_BASE_ADDR_LSB) & VMC_BASE_ADDR_MASK)

#define INDIRECT_REG_ADDRESS                     0x00000018
#define INDIRECT_REG_OFFSET                      0x00000018
#define INDIRECT_REG_ID_MSB                      31
#define INDIRECT_REG_ID_LSB                      2
#define INDIRECT_REG_ID_MASK                     0xfffffffc
#define INDIRECT_REG_ID_GET(x)                   (((x) & INDIRECT_REG_ID_MASK) >> INDIRECT_REG_ID_LSB)
#define INDIRECT_REG_ID_SET(x)                   (((x) << INDIRECT_REG_ID_LSB) & INDIRECT_REG_ID_MASK)

#define INDIRECT_RETURN_ADDRESS                  0x0000001c
#define INDIRECT_RETURN_OFFSET                   0x0000001c
#define INDIRECT_RETURN_ADDR_MSB                 31
#define INDIRECT_RETURN_ADDR_LSB                 2
#define INDIRECT_RETURN_ADDR_MASK                0xfffffffc
#define INDIRECT_RETURN_ADDR_GET(x)              (((x) & INDIRECT_RETURN_ADDR_MASK) >> INDIRECT_RETURN_ADDR_LSB)
#define INDIRECT_RETURN_ADDR_SET(x)              (((x) << INDIRECT_RETURN_ADDR_LSB) & INDIRECT_RETURN_ADDR_MASK)

#define RDMA_LINK_LIST_TABLE_ADDRESS             0x00000200
#define RDMA_LINK_LIST_TABLE_OFFSET              0x00000200
#define RDMA_LINK_LIST_TABLE_DATA_MSB            31
#define RDMA_LINK_LIST_TABLE_DATA_LSB            0
#define RDMA_LINK_LIST_TABLE_DATA_MASK           0xffffffff
#define RDMA_LINK_LIST_TABLE_DATA_GET(x)         (((x) & RDMA_LINK_LIST_TABLE_DATA_MASK) >> RDMA_LINK_LIST_TABLE_DATA_LSB)
#define RDMA_LINK_LIST_TABLE_DATA_SET(x)         (((x) << RDMA_LINK_LIST_TABLE_DATA_LSB) & RDMA_LINK_LIST_TABLE_DATA_MASK)

#define DMA_STATUS_ADDRESS                       0x00000400
#define DMA_STATUS_OFFSET                        0x00000400
#define DMA_STATUS_ERROR_CODE_MSB                14
#define DMA_STATUS_ERROR_CODE_LSB                4
#define DMA_STATUS_ERROR_CODE_MASK               0x00007ff0
#define DMA_STATUS_ERROR_CODE_GET(x)             (((x) & DMA_STATUS_ERROR_CODE_MASK) >> DMA_STATUS_ERROR_CODE_LSB)
#define DMA_STATUS_ERROR_CODE_SET(x)             (((x) << DMA_STATUS_ERROR_CODE_LSB) & DMA_STATUS_ERROR_CODE_MASK)
#define DMA_STATUS_ERROR_MSB                     3
#define DMA_STATUS_ERROR_LSB                     3
#define DMA_STATUS_ERROR_MASK                    0x00000008
#define DMA_STATUS_ERROR_GET(x)                  (((x) & DMA_STATUS_ERROR_MASK) >> DMA_STATUS_ERROR_LSB)
#define DMA_STATUS_ERROR_SET(x)                  (((x) << DMA_STATUS_ERROR_LSB) & DMA_STATUS_ERROR_MASK)
#define DMA_STATUS_DONE_MSB                      2
#define DMA_STATUS_DONE_LSB                      2
#define DMA_STATUS_DONE_MASK                     0x00000004
#define DMA_STATUS_DONE_GET(x)                   (((x) & DMA_STATUS_DONE_MASK) >> DMA_STATUS_DONE_LSB)
#define DMA_STATUS_DONE_SET(x)                   (((x) << DMA_STATUS_DONE_LSB) & DMA_STATUS_DONE_MASK)
#define DMA_STATUS_STOPPED_MSB                   1
#define DMA_STATUS_STOPPED_LSB                   1
#define DMA_STATUS_STOPPED_MASK                  0x00000002
#define DMA_STATUS_STOPPED_GET(x)                (((x) & DMA_STATUS_STOPPED_MASK) >> DMA_STATUS_STOPPED_LSB)
#define DMA_STATUS_STOPPED_SET(x)                (((x) << DMA_STATUS_STOPPED_LSB) & DMA_STATUS_STOPPED_MASK)
#define DMA_STATUS_RUNNING_MSB                   0
#define DMA_STATUS_RUNNING_LSB                   0
#define DMA_STATUS_RUNNING_MASK                  0x00000001
#define DMA_STATUS_RUNNING_GET(x)                (((x) & DMA_STATUS_RUNNING_MASK) >> DMA_STATUS_RUNNING_LSB)
#define DMA_STATUS_RUNNING_SET(x)                (((x) << DMA_STATUS_RUNNING_LSB) & DMA_STATUS_RUNNING_MASK)

#define DMA_INT_EN_ADDRESS                       0x00000404
#define DMA_INT_EN_OFFSET                        0x00000404
#define DMA_INT_EN_ERROR_ENA_MSB                 3
#define DMA_INT_EN_ERROR_ENA_LSB                 3
#define DMA_INT_EN_ERROR_ENA_MASK                0x00000008
#define DMA_INT_EN_ERROR_ENA_GET(x)              (((x) & DMA_INT_EN_ERROR_ENA_MASK) >> DMA_INT_EN_ERROR_ENA_LSB)
#define DMA_INT_EN_ERROR_ENA_SET(x)              (((x) << DMA_INT_EN_ERROR_ENA_LSB) & DMA_INT_EN_ERROR_ENA_MASK)
#define DMA_INT_EN_DONE_ENA_MSB                  2
#define DMA_INT_EN_DONE_ENA_LSB                  2
#define DMA_INT_EN_DONE_ENA_MASK                 0x00000004
#define DMA_INT_EN_DONE_ENA_GET(x)               (((x) & DMA_INT_EN_DONE_ENA_MASK) >> DMA_INT_EN_DONE_ENA_LSB)
#define DMA_INT_EN_DONE_ENA_SET(x)               (((x) << DMA_INT_EN_DONE_ENA_LSB) & DMA_INT_EN_DONE_ENA_MASK)
#define DMA_INT_EN_STOPPED_ENA_MSB               1
#define DMA_INT_EN_STOPPED_ENA_LSB               1
#define DMA_INT_EN_STOPPED_ENA_MASK              0x00000002
#define DMA_INT_EN_STOPPED_ENA_GET(x)            (((x) & DMA_INT_EN_STOPPED_ENA_MASK) >> DMA_INT_EN_STOPPED_ENA_LSB)
#define DMA_INT_EN_STOPPED_ENA_SET(x)            (((x) << DMA_INT_EN_STOPPED_ENA_LSB) & DMA_INT_EN_STOPPED_ENA_MASK)

#ifndef __ASSEMBLER__
typedef struct rdma_reg_reg_s {
  volatile unsigned int dma_config;
  volatile unsigned int dma_control;
  volatile unsigned int dma_src;
  volatile unsigned int dma_dest;
  volatile unsigned int dma_length;
  volatile unsigned int vmc_base;
  volatile unsigned int indirect_reg;
  volatile unsigned int indirect_return;
  unsigned char pad0[480]; /* pad to 0x200 */
  volatile unsigned int rdma_link_list_table[128];
  volatile unsigned int dma_status;
  volatile unsigned int dma_int_en;
} rdma_reg_reg_t;
#endif /* __ASSEMBLER__ */

#endif /* _RDMA_REG_H_ */
