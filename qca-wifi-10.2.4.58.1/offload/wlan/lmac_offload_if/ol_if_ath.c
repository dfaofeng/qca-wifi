/*
 * Copyright (c) 2011, Atheros Communications Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * LMAC offload interface functions for UMAC - for power and performance offload model
 */
#include "ol_if_athvar.h"
#include "ol_if_athpriv.h"
#include "ol_if_athutf.h"
#include "bmi.h"
#include "sw_version.h"
#include "targaddrs.h"
#include "ol_helper.h"
#include "ol_txrx_ctrl_api.h"
#include "adf_os_mem.h"   /* adf_os_mem_alloc,free */
#include "adf_os_lock.h"  /* adf_os_spinlock_* */
#include "adf_os_types.h" /* adf_os_vprint */
/* FIX THIS: the HL vs. LL selection will need to be done
 * at runtime rather than compile time
 */
#if defined(CONFIG_HL_SUPPORT)
#include "wlan_tgt_def_config_hl.h"    /* TODO: check if we need a seperated config file */
#else
#include "wlan_tgt_def_config.h"
#endif
#include "dbglog_host.h"
#include "ol_if_wow.h"
#include "a_debug.h"
#include "epping_test.h"

#if ATH_SUPPORT_DFS
#include "ol_if_dfs.h"
#endif

#include "osif_private.h"

#include "pktlog_ac.h"
#ifndef REMOVE_PKT_LOG
struct ol_pl_os_dep_funcs *g_ol_pl_os_dep_funcs = NULL;
#endif
#include "ol_regdomain.h"

#if ATH_SUPPORT_SPECTRAL
#include "ol_if_spectral.h"
#endif
#include "ol_ath.h"

#if ATH_SUPPORT_GREEN_AP
#include "ol_if_greenap.h"
#endif  /* ATH_SUPPORT_GREEN_AP */

#include "ol_if_stats.h"
#include "ol_ratetable.h"
#include "ol_if_vap.h"
#include "wds_addr.h"
#if UNIFIED_SMARTANTENNA
#include "ol_if_smart_ant.h"
#endif

#include "ol_if_eeprom.h"
#if ATH_PERF_PWR_OFFLOAD

#include "ath_pci.h"
#if DUMP_FW_RAM
#define FW_DRAM_ADDRESS		0x00400000
#define FW_DRAM_LENGTH		0x00050000
#define FW_IO_MEM_ADDR		0x41400000
#define FW_IO_MEM_SIZE		((1 * 1024 * 1024) - 128)
#endif /* DUMP_FW_RAM */

// Disabling scan offload
#define UMAC_SCAN_OFFLOAD 1
#if defined(EPPING_TEST) && !defined(HIF_USB)
unsigned int eppingtest = 1;
unsigned int bypasswmi = 1;
#else
unsigned int eppingtest = 0;
unsigned int bypasswmi = 0;
#endif

int wmi_unified_pdev_tpc_config_event_handler (ol_scn_t scn, u_int8_t *data, u_int16_t datalen, void *context);
int wmi_unified_gpio_input_event_handler (ol_scn_t scn, u_int8_t *data, u_int16_t datalen, void *context);
int wmi_unified_generic_buffer_event_handler (ol_scn_t scn, u_int8_t *data, u_int16_t datalen, void *context);
int wmi_unified_mcast_list_ageout_event_handler (ol_scn_t scn, u_int8_t *data, u_int16_t datalen, void *context);

#if OL_ATH_SUPPORT_LED
static OS_TIMER_FUNC(ol_ath_led_blink_timed_out);
static OS_TIMER_FUNC(ol_ath_led_poll_timed_out);

/* 50Mbps per entry */
static const
OL_LED_BLINK_RATES ol_led_blink_rate_table[] = {
    {  500, 130 },
    {  400, 100 },
    {  280,  70 },
    {  240,  60 },
    {  200,  50 },
    {  160,  40 },
    {  130,  30 },
    {  100,  30 },
    {  90,  20 },
    {  80,  20 },
    {  70,  20 },
    {  60,  10 },
    {  50,  10 },
    {  40,  10 },
};
#endif

#ifdef AH_CAL_IN_FLASH_PCI
extern u_int32_t CalAddr[];
extern int pci_dev_cnt;
#endif

#if ATH_SUPPORT_HYFI_ENHANCEMENTS
extern int ath_net80211_add_hmmc(struct ieee80211vap *vap, u_int32_t ip, u_int32_t mask);
extern int ath_net80211_del_hmmc(struct ieee80211vap *vap, u_int32_t ip, u_int32_t mask);
extern void ath_net80211_buffull_handler(struct ieee80211com *ic);
extern void ath_net80211_get_ald_statistics(struct ieee80211vap *vap);
#endif
static int
wmi_unified_dcs_interference_handler (ol_scn_t scn,
			  u_int8_t *data, u_int16_t datalen, void *context);
__inline__
u_int32_t host_interest_item_address(u_int32_t target_type, u_int32_t item_offset)
{
    switch (target_type)
    {
        default:
            ASSERT(0);
        case TARGET_TYPE_AR6002:
            return (AR6002_HOST_INTEREST_ADDRESS + item_offset);
        case TARGET_TYPE_AR6003:
            return (AR6003_HOST_INTEREST_ADDRESS + item_offset);
        case TARGET_TYPE_AR6004:
            return (AR6004_HOST_INTEREST_ADDRESS + item_offset);
        case TARGET_TYPE_AR6006:
            return (AR6006_HOST_INTEREST_ADDRESS + item_offset);
        case TARGET_TYPE_AR9888:
            return (AR9888_HOST_INTEREST_ADDRESS + item_offset);
        case TARGET_TYPE_AR6320:
            return (AR6320_HOST_INTEREST_ADDRESS + item_offset);
    }
}

/* WORDs, derived from AR600x_regdump.h */
#define REG_DUMP_COUNT_AR9888   60
#define REG_DUMP_COUNT_AR6320   60
#define REGISTER_DUMP_LEN_MAX   60

#if REG_DUMP_COUNT_AR9888 > REGISTER_DUMP_LEN_MAX
#error "REG_DUMP_COUNT_AR9888 too large"
#endif
#if REG_DUMP_COUNT_AR6320 > REGISTER_DUMP_LEN_MAX
#error "REG_DUMP_COUNT_AR6320 too large"
#endif

void
ol_target_send_suspend_complete(void *ctx)
{
    struct ol_ath_softc_net80211 *scn = (struct ol_ath_softc_net80211 *)ctx;

    scn->is_target_paused = TRUE;
    __ol_target_paused_event(scn);
}

#ifdef BIG_ENDIAN_HOST
void swap_bytes(void *pv, size_t n)
{
	int noWords;
	int i;
	A_UINT32 *wordPtr;

	noWords =   n/sizeof(u_int32_t);
	wordPtr = (u_int32_t *)pv;
	for (i=0;i<noWords;i++)
	{
		*(wordPtr + i) = __cpu_to_le32(*(wordPtr + i));
	}
}
#define SWAPME(x, len) swap_bytes(&x, len);
#endif

#if DUMP_FW_RAM
static struct ol_ath_softc_net80211 *ramdump_scn = NULL;

static void ramdump_work_handler(struct work_struct *ramdump)
{
    struct fw_ram_dump {
        A_UINT8 dram[FW_DRAM_LENGTH];
        //A_UINT8 iram[FW_IRAM_LENGTH];
    };

    struct fw_ram_dump *vaddr = NULL;

    if (!ramdump_scn) {
        printk("ramdump scn is NULL\n");
        return;
    }

    vaddr = (struct fw_ram_dump *) ioremap(FW_IO_MEM_ADDR, FW_IO_MEM_SIZE);
    if (!vaddr) {
        printk("Cannot access memory to dump WLAN Firmware data\n");
        return;
    }

    memset(vaddr, 0, FW_IO_MEM_SIZE);
    printk("Collecting WLAN Firmware Dump...\n");

    if (HIFDiagReadMem(ramdump_scn->hif_hdl,
                FW_DRAM_ADDRESS,
                (A_UCHAR*)vaddr->dram,
                FW_DRAM_LENGTH)!= A_OK)
    {
        printk("HifDiagReadDMem failed\n");
        return;
    }

    msleep(200);
    printk("Dump collected successfully\n");
    iounmap(vaddr);

    printk("Asserting host!!!\n");
    adf_os_assert_always(0);

    return;
}

static DECLARE_WORK(ramdump_work, ramdump_work_handler);
#endif /* DUMP_FW_RAM */

extern void
ce_dbg_dump(void *pdev_hdl);

char *ce_reg_type[] = {
"SR_BA",
"SR_SIZE",
"DR_BA",
"DR_SIZE",
"CE_CTRL1",
"CE_CTRL2",
"CE_CMD",
"MSI_ADDR",
"MSI_DATA",
"TARGET_IE",
"TARGET_IS",
"HOST_IE",
"HOST_IS",
"MISC_IE",
"MISC_IS",
"SR_WR_INDEX",
"DST_WR_INDEX",
"CURRENT_SRRI",
"CURRENT_DRRI",
"SRC_WATERMARK",
"DST_WATERMARK"
};

void ol_dump_ce_regs(void *instance)
{
/*
# --------- CE0-7 Base Adress  -------

# CE0_BASE_ADDRESS =  0x00057400
# CE1_BASE_ADDRESS =  0x00057800
# CE2_BASE_ADDRESS =  0x00057c00
# CE3_BASE_ADDRESS =  0x00058000
# CE4_BASE_ADDRESS =  0x00058400
# CE5_BASE_ADDRESS =  0x00058800
# CE6_BASE_ADDRESS =  0x00058c00
# CE7_BASE_ADDRESS =  0x00059000

# -------- CE Registers --------------

# SR_BA_ADDRESS        =   0x0000
# SR_SIZE_ADDRESS      =   0x0004
# DR_BA_ADDRESS        =   0x0008
# DR_SIZE_ADDRESS      =   0x000c
# CE_CTRL1_ADDRESS     =   0x0010
# CE_CTRL2_ADDRESS     =   0x0014
# CE_CMD_ADDRESS       =   0x0018
# MSI_ADDR_ADDRESS     =   0x001c
# MSI_DATA_ADDRESS     =   0x0020
# TARGET_IE_ADDRESS    =   0x0024
# TARGET_IS_ADDRESS    =   0x0028
# HOST_IE_ADDRESS      =   0x002c
# HOST_IS_ADDRESS      =   0x0030
# MISC_IE_ADDRESS      =   0x0034
# MISC_IS_ADDRESS      =   0x0038
# SR_WR_INDEX_ADDRESS  =   0x003c
# DST_WR_INDEX_ADDRESS =   0x0040
# CURRENT_SRRI_ADDRESS =   0x0044
# CURRENT_DRRI_ADDRESS =   0x0048
# SRC_WATERMARK_ADDRESS=   0x004c
# DST_WATERMARK_ADDRESS=   0x0050
*/
    struct ol_ath_softc_net80211 *scn = (struct ol_ath_softc_net80211 *)instance;
    struct ath_hif_pci_softc *sc = NULL;

    printk("CE Registers[0 - 7] dump...\n");
    sc = (struct ath_hif_pci_softc *) scn->hif_sc;

    if (sc != NULL && sc->mem != NULL) {
        A_UINT32 ce_reg_cnt = 8;
        A_UINT32 ce_reg_start_addr = 0x00057400;
        A_UINT32 ce_reg_offset = 0;
        A_UINT32 ce_reg_val = 0;
        A_UINT32 nextline_cnt = 0;
        unsigned int i, j;

        for (i = 0; i < ce_reg_cnt; i++) {
            printk("CE%d registers:\n",i);
            for (j = 0; j <= 20; j++) {
                ce_reg_val = A_PCI_READ32(sc->mem + (ce_reg_start_addr + ce_reg_offset));
                printk("%s: 0x%X, ", ce_reg_type[j], ce_reg_val);
                nextline_cnt++;
                if (nextline_cnt > 2) {
                    nextline_cnt=0;
                    printk("\n");
                }
                ce_reg_offset += 4;
            }
            ce_reg_start_addr += 0x400;
            ce_reg_offset = 0;
            printk("\n");
        }
        printk("\n");
        printk("End of CE register dump.\n");
    }
}

void
ol_target_failure(void *instance, A_STATUS status)
{
    struct ol_ath_softc_net80211 *scn = (struct ol_ath_softc_net80211 *)instance;
    A_UINT32 reg_dump_area = 0;
    A_UINT32 reg_dump_values[REGISTER_DUMP_LEN_MAX];
    A_UINT32 reg_dump_cnt = 0;
    A_UINT32 i;
    A_UINT32 dbglog_hdr_address;
    struct dbglog_hdr_s dbglog_hdr;
    struct dbglog_buf_s dbglog_buf;
    A_UINT8 *dbglog_data;
#ifdef DEBUG_CAPTURE_PCIE_LOG
    struct ath_hif_pci_softc *sc = NULL;
#endif

    /* Schedule a work queue that reset the Peregrine and
       reload the firmware.
    */
    if ((scn->recovery_enable == TRUE) && scn->pci_reconnect) {
       printk("Resetting the Peregrine %s radio\n", scn->sc_osdev->netdev->name);
       scn->pci_reconnect(scn);
    }

#ifdef DEBUG_CAPTURE_PCIE_LOG
    /* Below code does PCIe read on address 0x902c, so that PCIe analyzer can use this as trigger to
     * stop the capture. This is used for AXI hang issue.
     */
    sc = (struct ath_hif_pci_softc *) scn->hif_sc;
    if (sc != NULL && sc->mem != NULL) {
        for (i = 0; i < 5; i++) {
            /* A_PCI_READ32(sc->mem+(SOC_CORE_BASE_ADDRESS | SCRATCH_2_ADDRESS)); */
            A_PCI_READ32(sc->mem+(0x00009000 | 0x002c));
        }
        printk("Trigger for PCIe done by Reading the SCRATCH_2_ADDRESS 0x002c, BA:0X9000\n");
    }
#endif /* DEBUG_CAPTURE_PCIE_LOG */

    wmi_display_cmd_event();
    printk("[%s]: XXX TARGET ASSERTED XXX\n", scn->sc_osdev->netdev->name);
    scn->target_status = OL_TRGET_STATUS_RESET;
    if (HIFDiagReadMem(scn->hif_hdl,
                host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_failure_state)),
                (A_UCHAR *)&reg_dump_area,
                sizeof(A_UINT32))!= A_OK)
    {
        printk("HifDiagReadiMem FW Dump Area Pointer failed\n");
        return;
    }

    printk("Target Register Dump Location 0x%08X\n", reg_dump_area);

    if (scn->target_type == TARGET_TYPE_AR6320) {
        reg_dump_cnt = REG_DUMP_COUNT_AR6320;
    } else  if (scn->target_type == TARGET_TYPE_AR9888) {
        reg_dump_cnt = REG_DUMP_COUNT_AR9888;
    } else {
        A_ASSERT(0);
    }

    if (HIFDiagReadMem(scn->hif_hdl,
                reg_dump_area,
                (A_UCHAR*)&reg_dump_values[0],
                reg_dump_cnt * sizeof(A_UINT32))!= A_OK)
    {
        printk("HifDiagReadiMem for FW Dump Area failed\n");
        return;
    }

    printk("Target Register Dump\n");
    for (i = 0; i < reg_dump_cnt; i++) {
        printk("[%02d]   :  0x%08X\n", i, reg_dump_values[i]);
    }

    /* Dump CE 0-7 registers */
    ol_dump_ce_regs(instance);

    if (HIFDiagReadMem(scn->hif_hdl,
                host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_dbglog_hdr)),
                (A_UCHAR *)&dbglog_hdr_address,
                sizeof(dbglog_hdr_address))!= A_OK)
    {
        printk("HifDiagReadiMem FW dbglog_hdr_address failed\n");
        return;
    }

    if (HIFDiagReadMem(scn->hif_hdl,
                dbglog_hdr_address,
                (A_UCHAR *)&dbglog_hdr,
                sizeof(dbglog_hdr))!= A_OK)
    {
        printk("HifDiagReadiMem FW dbglog_hdr failed\n");
        return;
    }

    if (HIFDiagReadMem(scn->hif_hdl,
                (A_UINT32)dbglog_hdr.dbuf,
                (A_UCHAR *)&dbglog_buf,
                sizeof(dbglog_buf))!= A_OK)
    {
        printk("HifDiagReadiMem FW dbglog_buf failed\n");
        return;
    }

    dbglog_data = adf_os_mem_alloc(scn->adf_dev,  dbglog_buf.length + 4);
    if (dbglog_data) {
        if (HIFDiagReadMem(scn->hif_hdl,
                    (A_UINT32)dbglog_buf.buffer,
                    dbglog_data + 4,
                    dbglog_buf.length)!= A_OK)
        {
            printk("HifDiagReadiMem FW dbglog_data failed\n");
        } else {
            printk("dbglog_hdr.dbuf=%p dbglog_data=%p dbglog_buf.buffer=%p dbglog_buf.length=%u\n",
                    dbglog_hdr.dbuf, dbglog_data, dbglog_buf.buffer, dbglog_buf.length);

            OS_MEMCPY(dbglog_data, &dbglog_hdr.dropped, 4);
            (void)dbglog_parse_debug_logs(scn, dbglog_data, dbglog_buf.length + 4, NULL);
        }
        adf_os_mem_free(dbglog_data);
    }

#if DUMP_FW_RAM
    ramdump_scn = scn;
    schedule_work(&ramdump_work);
#endif /* DUMP_FW_RAM */

    return;

}

#if ATH_SUPPORT_HYFI_ENHANCEMENTS
void ol_notify_if_low_on_buffers(struct ol_ath_softc_net80211 *scn, uint32_t free_buff)
{
	struct ieee80211com *ic = &scn->sc_ic;

	scn->buff_thresh.free_descs = free_buff;
	if(scn->buff_thresh.ald_buffull_wrn && (scn->buff_thresh.free_descs <= scn->buff_thresh.ald_free_buf_lvl)) {
		ic->ic_notify_buffull(ic);
		scn->buff_thresh.ald_buffull_wrn = 0;
	}

}
#endif
/*
 * Routin to lock vap transmit
 *
 */
void ol_vap_tx_lock( void *vosdev)
{
    osif_dev  *osdev = (osif_dev  *)vosdev;
    VAP_TX_SPIN_LOCK(&osdev->tx_lock);
    return;
}

/*
 * Routin to lock vap transmit
 *
 */
void ol_vap_tx_unlock( void *vosdev)
{
    osif_dev  *osdev = (osif_dev  *)vosdev;
    VAP_TX_SPIN_UNLOCK(&osdev->tx_lock);
    return;
}

#if ATH_DEBUG
extern unsigned long ath_rtscts_enable;
#define MODE_CTS_TO_SELF 0x32
#define MODE_RTS_CTS     0x31
void set_rtscts_enable(void *vosdev)
{
   osif_dev *osdev = (osif_dev *)vosdev;
   struct net_device *comdev = osdev->os_comdev;
   struct ol_ath_softc_net80211 *scn = (struct ol_ath_softc_net80211*) ath_netdev_priv(comdev);
   wlan_if_t vap = osdev->os_if;
   struct ol_ath_vap_net80211 *avn = OL_ATH_VAP_NET80211(vap);
   unsigned int val = ath_rtscts_enable;

   if (val != scn->rtsctsenable)
   {
     scn->rtsctsenable = val;
     /* Enable CTS-to-self */
     if(val == 1)
         wmi_unified_vdev_set_param_send( scn->wmi_handle,avn->av_if_id,
                     WMI_VDEV_PARAM_ENABLE_RTSCTS, MODE_CTS_TO_SELF);
     /* Enable RTS-CTS */
     else if(val == 2)
         wmi_unified_vdev_set_param_send( scn->wmi_handle,avn->av_if_id,
                     WMI_VDEV_PARAM_ENABLE_RTSCTS, MODE_RTS_CTS);
  }
}
#endif

int
ol_ath_configure_target(struct ol_ath_softc_net80211 *scn)
{
    u_int32_t param;

#if 0
    if (enableuartprint) {
        param = 1;
        if (BMIWriteMemory(ar->arHifDevice,
                           HOST_INTEREST_ITEM_ADDRESS(ar->arTargetType, hi_serial_enable),
                           (A_UCHAR *)&param,
                           4)!= A_OK)
        {
             AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIWriteMemory for enableuartprint failed \n"));
             return A_ERROR;
        }
        AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("Serial console prints enabled\n"));
    }
#endif

    /* Tell target which HTC version it is used*/
    param = HTC_PROTOCOL_VERSION;
    if (BMIWriteMemory(scn->hif_hdl,
                       host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_app_host_interest)),
                       (u_int8_t *)&param,
                       4, scn)!= A_OK)
    {
         printk("BMIWriteMemory for htc version failed \n");
         return -1;
    }

#if 0
    if (enabletimerwar) {
        u_int32_t param;

        if (BMIReadMemory(ar->arHifDevice,
            HOST_INTEREST_ITEM_ADDRESS(ar->arTargetType, hi_option_flag),
            (A_UCHAR *)&param,
            4)!= A_OK)
        {
            AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIReadMemory for enabletimerwar failed \n"));
            return A_ERROR;
        }

        param |= HI_OPTION_TIMER_WAR;

        if (BMIWriteMemory(ar->arHifDevice,
            HOST_INTEREST_ITEM_ADDRESS(ar->arTargetType, hi_option_flag),
            (A_UCHAR *)&param,
            4) != A_OK)
        {
            AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIWriteMemory for enabletimerwar failed \n"));
            return A_ERROR;
        }
        AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("Timer WAR enabled\n"));
    }
#endif

    /* set the firmware mode to STA/IBSS/AP */
    {
        if (BMIReadMemory(scn->hif_hdl,
            host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_option_flag)),
            (A_UCHAR *)&param,
            4, scn)!= A_OK)
        {
            printk("BMIReadMemory for setting fwmode failed \n");
            return A_ERROR;
        }

    /* TODO following parameters need to be re-visited. */
        param |= (1 << HI_OPTION_NUM_DEV_SHIFT); //num_device
        param |= (HI_OPTION_FW_MODE_AP << HI_OPTION_FW_MODE_SHIFT); //Firmware mode ??
        param |= (1 << HI_OPTION_MAC_ADDR_METHOD_SHIFT); //mac_addr_method
        param |= (0 << HI_OPTION_FW_BRIDGE_SHIFT);  //firmware_bridge
        param |= (0 << HI_OPTION_FW_SUBMODE_SHIFT); //fwsubmode

        printk("NUM_DEV=%d FWMODE=0x%x FWSUBMODE=0x%x FWBR_BUF %d\n",
                            1, HI_OPTION_FW_MODE_AP, 0, 0);

        if (BMIWriteMemory(scn->hif_hdl,
            host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_option_flag)),
            (A_UCHAR *)&param,
            4, scn) != A_OK)
        {
            printk("BMIWriteMemory for setting fwmode failed \n");
            return A_ERROR;
        }
    }

#if (CONFIG_DISABLE_CDC_MAX_PERF_WAR)
    {
        /* set the firmware to disable CDC max perf WAR */
        if (BMIReadMemory(scn->hif_hdl,
            host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_option_flag2)),
            (A_UCHAR *)&param,
            4, scn)!= A_OK)
        {
            printk("BMIReadMemory for setting cdc max perf failed \n");
            return A_ERROR;
        }

        param |= HI_OPTION_DISABLE_CDC_MAX_PERF_WAR;
        if (BMIWriteMemory(scn->hif_hdl,
            host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_option_flag2)),
            (A_UCHAR *)&param,
            4, scn) != A_OK)
        {
            printk("BMIWriteMemory for setting cdc max perf failed \n");
            return A_ERROR;
        }
    }
#endif /* CONFIG_CDC_MAX_PERF_WAR */

    /* If host is running on a BE CPU, set the host interest area */
    {
#if defined(BIG_ENDIAN_HOST) && !AH_NEED_TX_DATA_SWAP
        param = 1;
#else
#if AH_NEED_TX_DATA_SWAP
        extern unsigned int testmode;
        if (testmode == 1)
            param = 1;
        else
#endif
            param = 0;
#endif
        if (BMIWriteMemory(scn->hif_hdl,
            host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_be)),
            (A_UCHAR *)&param,
            4, scn) != A_OK)
        {
            printk("BMIWriteMemory for setting host CPU BE mode failed \n");
            return A_ERROR;
        }
    }

    /* FW descriptor/Data swap flags */
    {
        param = 0;
        if (BMIWriteMemory(scn->hif_hdl,
            host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_fw_swap)),
            (A_UCHAR *)&param,
            4, scn) != A_OK)
        {
            printk("BMIWriteMemory for setting FW data/desc swap flags failed \n");
            return A_ERROR;
        }
    }
    /*Set the TX/RX DATA SWAP mode, if not define any AH_NEED_TX_DATA_SWAP and AH_NEED_RX_DATA_SWAP
	  The vlaue should be zero, that Target will not  enable TX_PACKET_BYTE_SWAP in  MAC_DMA_CFG
	  and PACKET_BYTE_SWAP and HEADER_BYTE_SWAP for MAC_DMA_RCV_RING2_2 */
    {
        param = 0;
#if AH_NEED_TX_DATA_SWAP
        param |= 0x01;
#endif
#if AH_NEED_RX_DATA_SWAP
        param |= 0x02;
#endif
#if ATH_11AC_ACK_POLICY
        param |= 0x04;
#endif
        if (BMIWriteMemory(scn->hif_hdl,
            host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_txrx_dataswap)),
            (A_UCHAR *)&param,
            4, scn) != A_OK)
        {
            printk("BMIWriteMemory for setting host TX/RX SWAP mode failed \n");
            return A_ERROR;
        }
    }

#if 0
#ifdef ATH6KL_DISABLE_TARGET_DBGLOGS
    {
        u_int32_t param;

        if (BMIReadMemory(ar->arHifDevice,
            HOST_INTEREST_ITEM_ADDRESS(ar->arTargetType, hi_option_flag),
            (A_UCHAR *)&param,
            4)!= A_OK)
        {
            AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIReadMemory for disabling debug logs failed\n"));
            return A_ERROR;
        }

        param |= HI_OPTION_DISABLE_DBGLOG;

        if (BMIWriteMemory(ar->arHifDevice,
            HOST_INTEREST_ITEM_ADDRESS(ar->arTargetType, hi_option_flag),
            (A_UCHAR *)&param,
            4) != A_OK)
        {
            AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIWriteMemory for HI_OPTION_DISABLE_DBGLOG\n"));
            return A_ERROR;
        }
        AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("Firmware mode set\n"));
    }
#endif /* ATH6KL_DISABLE_TARGET_DBGLOGS */

    if (regscanmode) {
        u_int32_t param;

        if (BMIReadMemory(ar->arHifDevice,
            HOST_INTEREST_ITEM_ADDRESS(ar->arTargetType, hi_option_flag),
            (A_UCHAR *)&param,
            4)!= A_OK)
        {
            AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIReadMemory for setting regscanmode failed\n"));
            return A_ERROR;
        }

        if (regscanmode == 1) {
            param |= HI_OPTION_SKIP_REG_SCAN;
        } else if (regscanmode == 2) {
            param |= HI_OPTION_INIT_REG_SCAN;
        }

        if (BMIWriteMemory(ar->arHifDevice,
            HOST_INTEREST_ITEM_ADDRESS(ar->arTargetType, hi_option_flag),
            (A_UCHAR *)&param,
            4) != A_OK)
        {
            AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIWriteMemory for setting regscanmode failed\n"));
            return A_ERROR;
        }
        AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("Regulatory scan mode set\n"));
    }

#if defined(AR6003_REV2_BOARD_EXT_DATA_ADDRESS)
    /*
     * Hardcode the address use for the extended board data
     * Ideally this should be pre-allocate by the OS at boot time
     * But since it is a new feature and board data is loaded
     * at init time, we have to workaround this from host.
     * It is difficult to patch the firmware boot code,
     * but possible in theory.
     */
    if (ar->arTargetType == TARGET_TYPE_AR6003) {
        u_int32_t ramReservedSz;
        if (ar->arVersion.target_ver == AR6003_REV2_VERSION) {
            param = AR6003_REV2_BOARD_EXT_DATA_ADDRESS;
            ramReservedSz =  AR6003_REV2_RAM_RESERVE_SIZE;
        } else {
            param = AR6003_REV3_BOARD_EXT_DATA_ADDRESS;
            ramReservedSz =  AR6003_REV3_RAM_RESERVE_SIZE;
        }
        if (BMIWriteMemory(ar->arHifDevice,
            HOST_INTEREST_ITEM_ADDRESS(ar->arTargetType, hi_board_ext_data),
            (A_UCHAR *)&param,
            4) != A_OK)
        {
            AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIWriteMemory for hi_board_ext_data failed \n"));
            return A_ERROR;
        }
        if (BMIWriteMemory(ar->arHifDevice,
              HOST_INTEREST_ITEM_ADDRESS(ar->arTargetType, hi_end_RAM_reserve_sz),
              (A_UCHAR *)&ramReservedSz, 4) != A_OK)
        {
            AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIWriteMemory for hi_end_RAM_reserve_sz failed \n"));
            return A_ERROR;
        }
    }
#endif /* AR6003_REV2_BOARD_EXT_DATA_ADDRESS */
    /* For AR6004: Size reserved at the end of RAM is done by wlansetup app */

        /* since BMIInit is called in the driver layer, we have to set the block
         * size here for the target */

    if (A_FAILED(ar6000_set_htc_params(ar->arHifDevice,
                                       ar->arTargetType,
                                       mbox_yield_limit,
                                       0 /* use default number of control buffers */
                                       ))) {
        return A_ERROR;
    }

    if (setupbtdev != 0) {
        if (A_FAILED(ar6000_set_hci_bridge_flags(ar->arHifDevice,
                                                 ar->arTargetType,
                                                 setupbtdev))) {
            return A_ERROR;
        }
    }
#endif
    return A_OK;
}

int
ol_check_dataset_patch(struct ol_ath_softc_net80211 *scn, u_int32_t *address)
{
    /* Check if patch file needed for this target type/version. */
    return 0;
}


#ifdef HIF_SDIO
static A_STATUS
ol_sdio_extra_initialization(struct ol_ath_softc_net80211 *scn)
{
    A_STATUS status;
    do{
        A_UINT32 blocksizes[HTC_MAILBOX_NUM_MAX];
        unsigned int MboxIsrYieldValue = 99;
        A_UINT32 TargetType = TARGET_TYPE_AR6320;
        /* get the block sizes */
        status = HIFConfigureDevice(scn->hif_hdl, HIF_DEVICE_GET_MBOX_BLOCK_SIZE,
                                    blocksizes, sizeof(blocksizes));

        if (A_FAILED(status)) {
            printk("Failed to get block size info from HIF layer...\n");
            break;
        }else{
            printk("get block size info from HIF layer:%x,%x,%x,%x\n",
                    blocksizes[0], blocksizes[1], blocksizes[2], blocksizes[3]);
        }
            /* note: we actually get the block size for mailbox 1, for SDIO the block
             * size on mailbox 0 is artificially set to 1 */
            /* must be a power of 2 */
        A_ASSERT((blocksizes[1] & (blocksizes[1] - 1)) == 0);

            /* set the host interest area for the block size */
        status = BMIWriteMemory(scn->hif_hdl,
                                HOST_INTEREST_ITEM_ADDRESS(TargetType, hi_mbox_io_block_sz),
                                (A_UCHAR *)&blocksizes[1],
                                4,
                                scn);

        if (A_FAILED(status)) {
            printk("BMIWriteMemory for IO block size failed \n");
            break;
        }else{
            printk("BMIWriteMemory for IO block size succeeded \n");
        }

        printk("Block Size Set: %d (target address:0x%X)\n",
                blocksizes[1], HOST_INTEREST_ITEM_ADDRESS(TargetType, hi_mbox_io_block_sz));

        if (MboxIsrYieldValue != 0) {
                /* set the host interest area for the mbox ISR yield limit */
            status = BMIWriteMemory(scn->hif_hdl,
                                    HOST_INTEREST_ITEM_ADDRESS(TargetType, hi_mbox_isr_yield_limit),
                                    (A_UCHAR *)&MboxIsrYieldValue,
                                    4,
                                    scn);

            if (A_FAILED(status)) {
                printk("BMIWriteMemory for yield limit failed \n");
                break;
            }
        }
    }while(FALSE);
    return status;
}
#endif

int
ol_ath_download_firmware(struct ol_ath_softc_net80211 *scn)
{
    u_int32_t param, address = 0;
    int status = !EOK;
    struct ath_hif_pci_softc *sc = (struct ath_hif_pci_softc *)(scn->hif_sc);

    /* Transfer Board Data from Target EEPROM to Target RAM */
    /* Determine where in Target RAM to write Board Data */
    if (scn->target_version != AR6004_VERSION_REV1_3) {
         BMIReadMemory(scn->hif_hdl,
         host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_board_data)),
                                   (u_int8_t *)&address, 4, scn);
    }

    if (!address) {
         if (scn->target_version == AR6004_REV1_VERSION)  {
             address = AR6004_REV1_BOARD_DATA_ADDRESS;
         } else if (scn->target_version == AR6004_VERSION_REV1_3) {
              address = AR6004_REV5_BOARD_DATA_ADDRESS;
         }
        printk("%s: Target address not known! Using 0x%x\n", __func__, address);
    }

    if(sc->id->device == AR9887_DEVICE_ID) {
            printk("%s: Using caldata from Target EEPROM for AR9887\n", __func__);
            status = ol_transfer_target_eeprom_caldata(scn, address, FALSE);
    }
    else {
        if (scn->cal_in_flash) {
            /* Write EEPROM or Flash data to Target RAM */
            status = ol_transfer_bin_file(scn, ATH_FLASH_FILE, address, FALSE);
        }
    }

    if (status == EOK) {
        /* Record the fact that Board Data is initialized */
        if (scn->target_version != AR6004_VERSION_REV1_3) {
            param = 1;
            BMIWriteMemory(scn->hif_hdl,
                           host_interest_item_address(scn->target_type,
                               offsetof(struct host_interest_s, hi_board_data_initialized)),
                           (u_int8_t *)&param, 4, scn);
        }
    } else {
        /* Flash is either not available or invalid */
        if (ol_transfer_bin_file(scn, ATH_BOARD_DATA_FILE, address, FALSE) != EOK) {
            return -1;
        }

        /* Record the fact that Board Data is initialized */
        if (scn->target_version != AR6004_VERSION_REV1_3) {
            param = 1;
            BMIWriteMemory(scn->hif_hdl,
                           host_interest_item_address(scn->target_type,
                               offsetof(struct host_interest_s, hi_board_data_initialized)),
                           (u_int8_t *)&param, 4, scn);
        }

        /* Transfer One Time Programmable data */
        address = BMI_SEGMENTED_WRITE_ADDR;
        printk("%s: Using 0x%x for the remainder of init\n", __func__, address);

        status = ol_transfer_bin_file(scn, ATH_OTP_FILE, address, TRUE);
        if (status == EOK) {
            /* Execute the OTP code only if entry found and downloaded */
            param = 0;
            BMIExecute(scn->hif_hdl, address, &param, scn);
        } else if (status == -1) {
            return status;
        }
    }

    /* Bypass PLL setting */
    if (scn->target_version == AR9888_REV2_VERSION || scn->target_version == AR9887_REV1_VERSION) {
        param = 1;
        BMIWriteMemory(scn->hif_hdl,host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_skip_clock_init)),(u_int8_t *)&param, 4, scn);
    }

    /* Download Target firmware - TODO point to target specific files in runtime */
    address = BMI_SEGMENTED_WRITE_ADDR;
    if (ol_transfer_bin_file(scn, ATH_FIRMWARE_FILE, address, TRUE) != EOK) {
        return -1;
    }

    /* Apply the patches */
    if (ol_check_dataset_patch(scn, &address))
    {
        if ((ol_transfer_bin_file(scn, ATH_PATCH_FILE, address, FALSE)) != EOK) {
            return -1;
        }
        BMIWriteMemory(scn->hif_hdl,
                     host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_dset_list_head)),
                     (u_int8_t *)&address, 4, scn);
    }

    if (scn->enableuartprint) {
        /* Configure GPIO AR9888 UART */
        if (scn->target_version == AR6004_VERSION_REV1_3) {
            param = 15;
        } else {
            param = 7;
        }
        BMIWriteMemory(scn->hif_hdl,
                host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_dbg_uart_txpin)),
                (u_int8_t *)&param, 4, scn);
        param = 1;
        BMIWriteMemory(scn->hif_hdl,
                host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_serial_enable)),
                (u_int8_t *)&param, 4, scn);

        /* band rates is 19200 for AR9888v2 */
        if (scn->target_version == AR9888_REV2_VERSION || scn->target_version == AR9887_REV1_VERSION) {
            param = 19200;
            BMIWriteMemory(scn->hif_hdl,
                    host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_desired_baud_rate)),
                    (u_int8_t *)&param, 4, scn);
        }
    }else {
        /*
         * Explicitly setting UART prints to zero as target turns it on
         * based on scratch registers.
         */
        param = 0;
        BMIWriteMemory(scn->hif_hdl,
                host_interest_item_address(scn->target_type, offsetof(struct host_interest_s,hi_serial_enable)),
                (u_int8_t *)&param, 4, scn);
    }

    if (scn->target_version == AR6004_VERSION_REV1_3) {
        A_UINT32 blocksizes[HTC_MAILBOX_NUM_MAX] = {0x10,0x10,0x10,0x10};
        BMIWriteMemory(scn->hif_hdl,
                host_interest_item_address(scn->target_type, offsetof(struct host_interest_s, hi_mbox_io_block_sz)),
                 (A_UCHAR *)&blocksizes[1], 4, scn);
    }
#ifdef HIF_SDIO
    return ol_sdio_extra_initialization(scn);
#else
    return EOK;
#endif
}

int
ol_ath_set_host_app_area(struct ol_ath_softc_net80211 *scn)
{
    printk("ol_ath_set_host_app_area TODO\n");
#if 0
    u_int32_t address, data;
    struct host_app_area_s host_app_area;

    /* Fetch the address of the host_app_area_s instance in the host interest area */
    address = TARG_VTOP(scn->target_type, HOST_INTEREST_ITEM_ADDRESS(scn->target_type, hi_app_host_interest));
    if (ar6000_ReadRegDiag(scn->hif_hdl, &address, &data) != A_OK) {
        return A_ERROR;
    }
    address = TARG_VTOP(scn->target_type, data);
    host_app_area.wmi_protocol_ver = WMI_PROTOCOL_VERSION;
    if (ar6000_WriteDataDiag(scn->hif_hdl, address,
                             (A_UCHAR *)&host_app_area,
                             sizeof(struct host_app_area_s)) != A_OK)
    {
        return A_ERROR;
    }
#endif
    return A_OK;
}
A_STATUS HIF_USB_connect_service(struct ol_ath_softc_net80211 *scn)
{
    int status;
    HTC_SERVICE_CONNECT_REQ connect;
    HTC_SERVICE_CONNECT_RESP response;
    A_MEMZERO(&connect,sizeof(connect));

    connect.EpCallbacks.EpSendFull        = NULL;
    connect.EpCallbacks.EpRecv            = NULL;
    connect.LocalConnectionFlags |= HTC_LOCAL_CONN_FLAGS_ENABLE_SEND_BUNDLE_PADDING;
    connect.MaxSendMsgSize =  1664;
    connect.ServiceID = WMI_DATA_BE_SVC;
    if ((status = HTCConnectService(scn->htc_handle, &connect, &response))
            != EOK) {
        printk("Failed to connect to Endpoint Ping BE service status:%d \n", status);
        return -1;;
    } else {
        printk("eppingtest BE endpoint:%d\n", response.Endpoint);
    }
    connect.ServiceID = WMI_DATA_BK_SVC;
    if ((status = HTCConnectService(scn->htc_handle, &connect, &response))
            != EOK) {
        printk("Failed to connect to Endpoint Ping BK service status:%d \n", status);
        return -1;;
    } else {
        printk("eppingtest BK endpoint:%d\n", response.Endpoint);
    }
    connect.ServiceID = WMI_DATA_VI_SVC;
    if ((status = HTCConnectService(scn->htc_handle, &connect, &response))
            != EOK) {
        printk("Failed to connect to Endpoint Ping VI service status:%d \n", status);
        return -1;;
    } else {
        printk("eppingtest VI endpoint:%d\n", response.Endpoint);
    }
    connect.ServiceID = WMI_DATA_VO_SVC;
    if ((status = HTCConnectService(scn->htc_handle, &connect, &response))
            != EOK) {
        printk("Failed to connect to Endpoint Ping VO service status:%d \n", status);
        return -1;;
    } else {
        printk("eppingtest VO endpoint:%d\n", response.Endpoint);
    }
    return EOK;
}
int
ol_ath_connect_htc(struct ol_ath_softc_net80211 *scn)
{
    int status;
    HTC_SERVICE_CONNECT_REQ connect;

    OS_MEMZERO(&connect,sizeof(connect));

    /* meta data is unused for now */
    connect.pMetaData = NULL;
    connect.MetaDataLength = 0;
    /* these fields are the same for all service endpoints */
    connect.EpCallbacks.pContext = scn;
    connect.EpCallbacks.EpTxCompleteMultiple = NULL /* Control path completion ar6000_tx_complete */;
    connect.EpCallbacks.EpRecv = NULL /* Control path rx */;
    connect.EpCallbacks.EpRecvRefill = NULL /* ar6000_rx_refill */;
    connect.EpCallbacks.EpSendFull = NULL /* ar6000_tx_queue_full */;
#if 0
    /* set the max queue depth so that our ar6000_tx_queue_full handler gets called.
     * Linux has the peculiarity of not providing flow control between the
     * NIC and the network stack. There is no API to indicate that a TX packet
     * was sent which could provide some back pressure to the network stack.
     * Under linux you would have to wait till the network stack consumed all sk_buffs
     * before any back-flow kicked in. Which isn't very friendly.
     * So we have to manage this ourselves */
    connect.MaxSendQueueDepth = MAX_DEFAULT_SEND_QUEUE_DEPTH;
    connect.EpCallbacks.RecvRefillWaterMark = AR6000_MAX_RX_BUFFERS / 4; /* set to 25 % */
    if (0 == connect.EpCallbacks.RecvRefillWaterMark) {
        connect.EpCallbacks.RecvRefillWaterMark++;
    }
#endif
#if 0
    /* connect to control service */
    connect.ServiceID = WMI_CONTROL_SVC;
    if ((status = ol_ath_connectservice(scn, &connect, "WMI CONTROL")) != EOK)
        goto conn_fail;
#endif
    if (!bypasswmi) {
        if ((status = wmi_unified_connect_htc_service(scn->wmi_handle, scn->htc_handle)) != EOK)
             goto conn_fail;
    }
#if defined(EPPING_TEST) && !defined(HIF_USB)
    if (eppingtest){
        extern A_STATUS epping_connect_service(struct ol_ath_softc_net80211 *scn);
        if ((status = epping_connect_service(scn)) != EOK)
             goto conn_fail;
    }
#endif
    if (scn->target_version == AR6004_VERSION_REV1_3) {
      if ((status = HIF_USB_connect_service(scn)) != EOK)
               goto conn_fail;
    }
    /*
     * give our connected endpoints some buffers
     */
#if 0
    ar6000_rx_refill(scn, scn->htt_control_ep);
    ar6000_rx_refill(scn, scn->htt_data_ep);
#endif

    /*
     * Since cookies are used for HTC transports, they should be
     * initialized prior to enabling HTC.
     */
    ol_cookie_init((void *)scn);


    /*
     * Start HTC
     */
    if ((status = HTCStart(scn->htc_handle)) != A_OK) {
        goto conn_fail;
    }

    if (!bypasswmi) {
        /*
         * Wait for WMI event to be ready
         */
        if (scn->target_version == AR6004_VERSION_REV1_3) {
            scn->wmi_ready = TRUE;
            scn->wlan_init_status = WLAN_INIT_STATUS_SUCCESS;
        } else {
            if ((status = __ol_ath_check_wmi_ready(scn)) != EOK) {
                goto conn_fail1;
            }
            printk("%s() WMI is ready\n", __func__);

            if(scn->wlan_init_status != WLAN_INIT_STATUS_SUCCESS)
            {
              printk("%s Target wmi init failed with status %d\n", __func__,scn->wlan_init_status);
              status = ENODEV;
              goto conn_fail1;
            }
        }
        /* Communicate the wmi protocol verision to the target */
        if ((ol_ath_set_host_app_area(scn)) != EOK) {
            printk("Unable to set the host app area\n");
        }
    }

    // TODO is this needed
//            ar6000_target_config_wlan_params(arPriv);
    return EOK;

conn_fail1:
    HTCStop(scn->htc_handle);
conn_fail:
    return status;
}

int
ol_ath_disconnect_htc(struct ol_ath_softc_net80211 *scn)
{
    if (scn->htc_handle != NULL) {
        HTCStop(scn->htc_handle);
    }
    return 0;
}

#if ATH_BAND_STEERING
static bool
ol_ath_bs_set_params(struct ieee80211com *ic,
                     ieee80211_bsteering_lmac_param_t *params)
{
    return ol_txrx_set_inact_params((OL_ATH_SOFTC_NET80211(ic))->pdev_txrx_handle,
                                    params->inactivity_check_period,
                                    params->inactivity_threshold_normal,
                                    params->inactivity_threshold_overload);
}

static bool
ol_ath_bs_enable(struct ieee80211com *ic, bool enable)
{
    return ol_txrx_start_inact_timer((OL_ATH_SOFTC_NET80211(ic))->pdev_txrx_handle,
                                      enable);
}

static void
ol_ath_bs_set_overload(struct ieee80211 *ic, bool overload)
{
    ol_txrx_set_overload((OL_ATH_SOFTC_NET80211(ic))->pdev_txrx_handle,
                         overload);
}
#endif /* ATH_BAND_STEERING */

static void
ol_ath_update_caps(struct ieee80211com *ic, wmi_service_ready_event *ev,
                           A_UINT32 *wmi_service_bitmap)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    u_int32_t ampdu_exp = 0;
    u_int16_t caps  = 0;

    /* setup ieee80211 flags */
    ieee80211com_clear_cap(ic, -1);
    ieee80211com_clear_athcap(ic, -1);
    ieee80211com_clear_athextcap(ic, -1);

    ieee80211com_set_phytype(ic, IEEE80211_T_OFDM);

    ieee80211com_set_cap(ic,IEEE80211_C_SHPREAMBLE);

    ieee80211com_set_cap(ic,
                     IEEE80211_C_IBSS           /* ibss, nee adhoc, mode */
                     | IEEE80211_C_HOSTAP       /* hostap mode */
                     | IEEE80211_C_MONITOR      /* monitor mode */
                     | IEEE80211_C_SHSLOT       /* short slot time supported */
                     | IEEE80211_C_PMGT         /* capable of power management*/
                     | IEEE80211_C_WPA          /* capable of WPA1+WPA2 */
                     | IEEE80211_C_BGSCAN       /* capable of bg scanning */
                  );

    /* WMM enable */
    ieee80211com_set_cap(ic, IEEE80211_C_WME);

    scn->burst_enable = WMI_SERVICE_IS_ENABLED(wmi_service_bitmap, WMI_SERVICE_BURST);

    if (WMI_SERVICE_IS_ENABLED(wmi_service_bitmap, WMI_SERVICE_AP_UAPSD)) {
        ieee80211com_set_cap(ic, IEEE80211_C_UAPSD);
        IEEE80211_UAPSD_ENABLE(ic);
    }

    /* Default 11h to start enabled  */
    ieee80211_ic_doth_set(ic);
#if UMAC_SUPPORT_WNM
    /* Disabled, till offload supports WNM  */
    ieee80211_ic_wnm_clear(ic);
#endif
    /* setup the chainmasks */
    ieee80211com_set_tx_chainmask(ic,
        (u_int8_t) (scn->wlan_resource_config.tx_chain_mask));

    ieee80211com_set_rx_chainmask(ic,
        (u_int8_t) (scn->wlan_resource_config.rx_chain_mask));

#ifdef ATH_SUPPORT_WAPI
    /*WAPI HW engine support upto 300 Mbps (MCS15h),
      limiting the chains to 2*/
    ic->ic_num_wapi_rx_maxchains = 2;
    ic->ic_num_wapi_tx_maxchains = 2;
#endif
    /* 11n Capabilities */
    ieee80211com_set_num_tx_chain(ic,1);
    ieee80211com_set_num_rx_chain(ic,1);
    ieee80211com_clear_htcap(ic, -1);
    ieee80211com_clear_htextcap(ic, -1);
    if (ev->ht_cap_info & WMI_HT_CAP_ENABLED) {
        ieee80211com_set_cap(ic, IEEE80211_C_HT);
        ieee80211com_set_htcap(ic, IEEE80211_HTCAP_C_SHORTGI40
                        | IEEE80211_HTCAP_C_CHWIDTH40
                        | IEEE80211_HTCAP_C_DSSSCCK40);
        if (ev->ht_cap_info & WMI_HT_CAP_HT20_SGI)  {
            ieee80211com_set_htcap(ic, IEEE80211_HTCAP_C_SHORTGI20);
        }
        if (ev->ht_cap_info & WMI_HT_CAP_DYNAMIC_SMPS) {
            ieee80211com_set_htcap(ic, IEEE80211_HTCAP_C_SMPOWERSAVE_DYNAMIC);
        } else {
            ieee80211com_set_htcap(ic, IEEE80211_HTCAP_C_SM_ENABLED);
        }
        ieee80211com_set_htextcap(ic, IEEE80211_HTCAP_EXTC_TRANS_TIME_5000
                        | IEEE80211_HTCAP_EXTC_MCS_FEEDBACK_NONE);
        ieee80211com_set_maxampdu(ic, IEEE80211_HTCAP_MAXRXAMPDU_65536);

        /* Force this to 8usec for now, instead of checking min_pkt_size_enable */
        if(0) {
            ieee80211com_set_mpdudensity(ic,IEEE80211_HTCAP_MPDUDENSITY_NA);
        }
        else {
            ieee80211com_set_mpdudensity(ic,IEEE80211_HTCAP_MPDUDENSITY_8);
        }

        IEEE80211_ENABLE_AMPDU(ic);

        ieee80211com_set_num_rx_chain(ic, ev->num_rf_chains);
        ieee80211com_set_num_tx_chain(ic, ev->num_rf_chains);
    }

    /* Tx STBC is a 2-bit mask. Convert to ieee definition. */
    caps = (ev->ht_cap_info & WMI_HT_CAP_TX_STBC) >> WMI_HT_CAP_TX_STBC_MASK_SHIFT;
    ieee80211com_set_htcap(ic, IEEE80211_HTCAP_C_TXSTBC & (caps << IEEE80211_HTCAP_C_TXSTBC_S));


    /* Rx STBC is a 2-bit mask. Convert to ieee definition. */
    caps = (ev->ht_cap_info & WMI_HT_CAP_RX_STBC) >> WMI_HT_CAP_RX_STBC_MASK_SHIFT;
    ieee80211com_set_htcap(ic, IEEE80211_HTCAP_C_RXSTBC & (caps << IEEE80211_HTCAP_C_RXSTBC_S));

    if (ev->ht_cap_info & WMI_HT_CAP_LDPC) {
        ieee80211com_set_htcap(ic, IEEE80211_HTCAP_C_ADVCODING);
        /* enable LDPC capability */
        ieee80211com_set_ldpccap(ic, IEEE80211_HTCAP_C_LDPC_TXRX);
    }

    /* 11n configuration */
    ieee80211com_clear_htflags(ic, -1);

    /*
     * Note that in the offload architecture chain_masks
     * and spatial_streams are synonymous
     */
    ieee80211com_set_spatialstreams(ic, ev->num_rf_chains);

    /*
     * Indicate we need the 802.11 header padded to a
     * 32-bit boundary for 4-address and QoS frames.
     */
    IEEE80211_ENABLE_DATAPAD(ic);

    /* Check whether the hardware is VHT capable */
    ieee80211com_clear_vhtcap(ic, -1);
    if (WMI_SERVICE_IS_ENABLED(wmi_service_bitmap, WMI_SERVICE_11AC)) {

        /* Copy the VHT capabilities information */
        ieee80211com_set_vhtcap(ic, ev->vht_cap_info);

        /* Adjust HT AMSDU len based on VHT MPDU len */
        if ((ev->vht_cap_info & IEEE80211_VHTCAP_MAX_MPDU_LEN_7935) ||
            (ev->vht_cap_info & IEEE80211_VHTCAP_MAX_MPDU_LEN_11454)) {
            ieee80211com_set_htcap(ic,IEEE80211_HTCAP_C_MAXAMSDUSIZE);
        } else {
            ieee80211com_clear_htcap(ic,IEEE80211_HTCAP_C_MAXAMSDUSIZE);
        }

        /* Adjust HT AMPDU len Exp  based on VHT MPDU len */
        ampdu_exp = ev->vht_cap_info >> IEEE80211_VHTCAP_MAX_AMPDU_LEN_EXP_S;
        switch (ampdu_exp) {
            case 0:
            case 1:
            case 2:
            case 3:
                ieee80211com_set_maxampdu(ic, ampdu_exp);
            break;

            default:
                ieee80211com_set_maxampdu(ic, IEEE80211_HTCAP_MAXRXAMPDU_65536);
            break;
        }


        /* Set the VHT  rate information */
        {
            /*  11ac spec states it is mandatory to support MCS 0-7 and NSS=1 */
            u_int16_t basic_mcs = 0xfffc;
            ol_ath_vht_rate_setup(ic, ev->vht_supp_mcs, 0, basic_mcs );

        }
#ifdef TEMP_AGGR_CFG
        ic->ic_vht_ampdu = 64;
        ic->ic_vht_amsdu = 3;
#endif

    }

    if (WMI_SERVICE_IS_ENABLED(wmi_service_bitmap, WMI_SERVICE_RATECTRL)) {
        ol_txrx_enable_host_ratectrl(
                (OL_ATH_SOFTC_NET80211(ic))->pdev_txrx_handle, 1);
    }

    /* ToDo, check ev->sys_cap_info for  WMI_SYS_CAP_ENABLE and WMI_SYS_CAP_TXPOWER when it is available from FW */
    ieee80211com_set_cap(ic, IEEE80211_C_TXPMGT);

}

void
ol_ath_set_default_tgt_config(struct ol_ath_softc_net80211 *scn)
{
    wmi_resource_config  tgt_cfg = {
        CFG_TGT_NUM_VDEV,
        CFG_TGT_NUM_PEERS + CFG_TGT_NUM_VDEV, /* need to reserve an additional peer for each VDEV */
        CFG_TGT_NUM_PEER_KEYS,
        CFG_TGT_NUM_TIDS,
        CFG_TGT_AST_SKID_LIMIT,
        CFG_TGT_DEFAULT_TX_CHAIN_MASK,
        CFG_TGT_DEFAULT_RX_CHAIN_MASK,
        { CFG_TGT_RX_TIMEOUT_LO_PRI, CFG_TGT_RX_TIMEOUT_LO_PRI, CFG_TGT_RX_TIMEOUT_LO_PRI, CFG_TGT_RX_TIMEOUT_HI_PRI },
#ifdef ATHR_WIN_NWF
        CFG_TGT_RX_DECAP_MODE_NWIFI,
#else
        CFG_TGT_RX_DECAP_MODE,
#endif
        CFG_TGT_DEFAULT_SCAN_MAX_REQS,
        CFG_TGT_DEFAULT_BMISS_OFFLOAD_MAX_VDEV,
        CFG_TGT_DEFAULT_ROAM_OFFLOAD_MAX_VDEV,
        CFG_TGT_DEFAULT_ROAM_OFFLOAD_MAX_PROFILES,
        CFG_TGT_DEFAULT_NUM_MCAST_GROUPS,
        CFG_TGT_DEFAULT_NUM_MCAST_TABLE_ELEMS,
        CFG_TGT_DEFAULT_MCAST2UCAST_MODE,
        CFG_TGT_DEFAULT_TX_DBG_LOG_SIZE,
        CFG_TGT_WDS_ENTRIES,
        CFG_TGT_DEFAULT_DMA_BURST_SIZE,
        CFG_TGT_DEFAULT_MAC_AGGR_DELIM,
        CFG_TGT_DEFAULT_RX_SKIP_DEFRAG_TIMEOUT_DUP_DETECTION_CHECK,
        CFG_TGT_DEFAULT_VOW_CONFIG,
        CFG_TGT_NUM_MSDU_DESC,
        0,
        CFG_TGT_DEFAULT_MAX_PEER_EXT_STATS,
		0,
		0,
		0,
		0,
		0,
		0
    };

    /* Override the specific configuration if max_client_support is enabled
    */
    if (scn->enable_max_clients) {
        tgt_cfg.num_peers = CFG_TGT_NUM_PEERS_MAX_200;
        tgt_cfg.num_msdu_desc = CFG_TGT_NUM_MSDU_DESC_200;
        tgt_cfg.tx_dbg_log_size = CFG_TGT_DEFAULT_TX_DBG_LOG_SIZE_200;
        tgt_cfg.ast_skid_limit = CFG_TGT_AST_SKID_LIMIT_200;
    }
    /* reduce the peer/vdev if CFG_TGT_NUM_MSDU_DESC exceeds 1000 */
    // TODO:

    /* Override VoW specific configuration, if VoW is enabled (no of peers,
     * no of vdevs, No of wds entries, No of Vi Nodes, No of Descs per Vi Node)
     */
    if(scn->vow_config >> 16)
    {
        tgt_cfg.num_vdevs = CFG_TGT_NUM_VDEV_VOW;
        tgt_cfg.num_peers = CFG_TGT_NUM_PEERS_VOW + CFG_TGT_NUM_VDEV_VOW;
        tgt_cfg.num_tids = CFG_TGT_NUM_TIDS_VOW;
        tgt_cfg.num_wds_entries = CFG_TGT_WDS_ENTRIES_VOW;

        tgt_cfg.vow_config = scn->vow_config;
    }
#if  QCA_OL_RX_BATCHMODE
    tgt_cfg.fw_feature_bitmap |= FW_FEATURE_RX_BATCHMODE_BIT;
#endif

#if PERE_IP_HDR_ALIGNMENT_WAR
    if (scn->host_80211_enable) {
        /*
         * To make the IP header begins at dword aligned address,
         * we make the decapsulation mode as Native Wifi.
         */
        tgt_cfg.rx_decap_mode = CFG_TGT_RX_DECAP_MODE_NWIFI;
    }
#endif

    {
        extern unsigned int OL_ACBKMinfree, OL_ACBEMinfree, OL_ACVIMinfree, OL_ACVOMinfree;

        /* Set the Min buffer free for each AC, from the module param values */
        tgt_cfg.BK_Minfree = OL_ACBKMinfree;
        tgt_cfg.BE_Minfree = OL_ACBEMinfree;
        tgt_cfg.VI_Minfree = OL_ACVIMinfree;
        tgt_cfg.VO_Minfree = OL_ACVOMinfree;

        printk("%s : AC Minfree buffer allocation through module param (umac.ko)\n", __func__);
        printk(" OL_ACBKMinfree : %d\n", OL_ACBKMinfree);
        printk(" OL_ACBEMinfree : %d\n", OL_ACBEMinfree);
        printk(" OL_ACVIMinfree : %d\n", OL_ACVIMinfree);
        printk(" OL_ACVOMinfree : %d\n", OL_ACVOMinfree);
    }


    scn->wlan_resource_config = tgt_cfg;

}

static void dbg_print_wmi_service_11ac(wmi_service_ready_event *ev)
{
    if (WMI_SERVICE_IS_ENABLED(ev->wmi_service_bitmap, WMI_SERVICE_11AC)) {
        printk("num_rf_chain : %08x\n",ev->num_rf_chains);
        printk("ht_cap_info: : %08x\n",ev->ht_cap_info);
        printk("vht_cap_info : %08x\n",ev->vht_cap_info);
        printk("vht_supp_mcs : %08x\n",ev->vht_supp_mcs);
    }
    else {
        printk("\n No WMI 11AC service event received\n");
    }
}


/**
 * allocate a chunk of memory at the index indicated and
 * if allocation fail allocate smallest size possiblr and
 * return number of units allocated.
 */
u_int32_t
ol_ath_alloc_host_mem_chunk(ol_scn_t scn, u_int32_t req_id, u_int32_t idx, u_int32_t num_units, u_int32_t unit_len)
{
    adf_os_dma_addr_t paddr;
    if (!num_units  || !unit_len)  {
        return 0;
    }
    scn->mem_chunks[idx].vaddr = NULL ;
    /** reduce the requested allocation by half until allocation succeeds */
    while(scn->mem_chunks[idx].vaddr == NULL && num_units ) {
        scn->mem_chunks[idx].vaddr = adf_os_mem_alloc_consistent(
            scn->adf_dev, num_units*unit_len, &paddr,
            adf_os_get_dma_mem_context((&(scn->mem_chunks[idx])), memctx));
        if(scn->mem_chunks[idx].vaddr == NULL) {
            num_units = (num_units >> 1) ; /* reduce length by half */
        } else {
           scn->mem_chunks[idx].paddr = paddr;
           scn->mem_chunks[idx].len = num_units*unit_len;
           scn->mem_chunks[idx].req_id =  req_id;
        }
    }
    return num_units;
}


#define HOST_MEM_SIZE_UNIT 4

/*
 * allocate amount of memory requested by FW.
 */
void
ol_ath_alloc_host_mem (ol_scn_t scn, u_int32_t req_id, u_int32_t num_units, u_int32_t unit_len)
{
    u_int32_t remaining_units,allocated_units,idx;
    /* adjust the length to nearest multiple of unit size */
    unit_len = (unit_len + (HOST_MEM_SIZE_UNIT - 1)) & (~(HOST_MEM_SIZE_UNIT - 1));
    idx = scn->num_mem_chunks ;
    remaining_units = num_units;
    while(remaining_units) {
        allocated_units = ol_ath_alloc_host_mem_chunk(scn,req_id,  idx, remaining_units,unit_len);
        if (allocated_units == 0) {
            printk("FAILED TO ALLOCATED memory unit len %d units requested %d units allocated %d \n",unit_len, num_units,(num_units - remaining_units));
            scn->num_mem_chunks = idx;
            break;
        }
        remaining_units -= allocated_units;
        ++idx;
        if (idx == MAX_MEM_CHUNKS ) {
            printk("RWACHED MAX CHUNK LIMIT for memory units %d unit len %d requested by FW, only allocated %d \n",
                   num_units,unit_len, (num_units - remaining_units));
            scn->num_mem_chunks = idx;
            break;
        }
    }
    scn->num_mem_chunks = idx;
}

static int ol_ath_get_sta_num(struct ol_ath_softc_net80211 *scn,
        int msdu_desc_size, int peer_size)
{
     /* If VoW is enabled, memory for TOTAL_VOW_ALLOCABLE number of descriptors are reserved
      * for VoW statsions. To accomadate this memory, number of peers is reduced to 16.
      * Incase, vow is configured such that it doesn't need all those memory, it can be used
      * to support more stations.
      */
    int sta_num = 0;
    unsigned short num_vi_sta = VOW_GET_NUM_VI_STA(scn->vow_config);
    unsigned short num_vi_desc_per_sta = VOW_GET_DESC_PER_VI_STA(scn->vow_config);
    int total_vow_desc = num_vi_sta * num_vi_desc_per_sta;
    int total_free_desc = TOTAL_VOW_ALLOCABLE - total_vow_desc;

    if(total_free_desc > 0) {
        int bytes_avail = total_free_desc * msdu_desc_size;
        sta_num = bytes_avail / peer_size;
    }
    return sta_num;
}

void
ol_ath_service_ready_event(ol_scn_t scn_handle, wmi_service_ready_event *ev)
{
    struct ol_ath_softc_net80211 *scn = (struct ol_ath_softc_net80211 *)scn_handle;
    struct ieee80211com *ic = &scn->sc_ic;
    wmi_init_cmd *cmd;
    struct ol_ath_target_cap target_cap;
    wmi_buf_t buf;
    int len = sizeof(wmi_init_cmd),idx;
#if UNIFIED_SMARTANTENNA
    unsigned int smart_ant_enable = 0;
#endif

    scn->phy_capability = ev->phy_capability;
	scn->max_frag_entry = ev->max_frag_entry;

    /* Dump service ready event for debugging */
    dbg_print_wmi_service_11ac(ev);

    /* wmi service is ready */
    OS_MEMCPY(scn->wmi_service_bitmap,ev->wmi_service_bitmap,sizeof(scn->wmi_service_bitmap));
    buf = wmi_buf_alloc(scn->wmi_handle, len + (sizeof(wlan_host_memory_chunk) * MAX_MEM_CHUNKS) );
    if (!buf) {
        printk("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return ;
    }
#if UNIFIED_SMARTANTENNA
    smart_ant_enable = ((WMI_SERVICE_IS_ENABLED(scn->wmi_service_bitmap, WMI_SERVICE_SMART_ANTENNA_SW_SUPPORT) &&
                         WMI_SERVICE_IS_ENABLED(scn->wmi_service_bitmap, WMI_SERVICE_SMART_ANTENNA_HW_SUPPORT))
                         || (WMI_SERVICE_IS_ENABLED(scn->wmi_service_bitmap, WMI_SERVICE_SMART_ANTENNA_SW_SUPPORT) && scn->sa_validate_sw));
#endif

    if (WMI_SERVICE_IS_ENABLED(scn->wmi_service_bitmap, WMI_SERVICE_RATECTRL_CACHE) &&
        WMI_SERVICE_IS_ENABLED(scn->wmi_service_bitmap, WMI_SERVICE_IRAM_TIDS) &&
        !(scn->vow_config >> 16)) {

        if (scn->max_peers) {
            scn->wlan_resource_config.num_peers = scn->max_peers;
#if UNIFIED_SMARTANTENNA
           /* Both Host and Firmware has Smart Antenna support */
            if (smart_ant_enable) {
                scn->wlan_resource_config.num_peers = (scn->max_peers > CFG_TGT_NUM_SMART_ANT_PEERS_MAX ? CFG_TGT_NUM_SMART_ANT_PEERS_MAX:scn->max_peers);
                scn->wlan_resource_config.smart_ant_cap = 1;
            } else {
                scn->wlan_resource_config.smart_ant_cap = 0;
            }
#else
            scn->wlan_resource_config.smart_ant_cap = 0;
#endif

        }
        else {
            if (scn->lteu_support) {
                scn->wlan_resource_config.num_peers = 10;
            } else if (scn->enable_max_clients) {
                scn->wlan_resource_config.num_peers = CFG_TGT_NUM_PEERS_MAX_200;
            } else {
                scn->wlan_resource_config.num_peers = CFG_TGT_NUM_PEERS_MAX;
            }
#if UNIFIED_SMARTANTENNA
            /* Both Host and Firmware has Smart Antenna support */
            if (smart_ant_enable) {
                scn->wlan_resource_config.num_peers = CFG_TGT_NUM_SMART_ANT_PEERS_MAX;
                scn->wlan_resource_config.smart_ant_cap = 1;
            } else {
                scn->wlan_resource_config.smart_ant_cap = 0;
            }
#else
            scn->wlan_resource_config.smart_ant_cap = 0;
#endif
        }

        if (WMI_SERVICE_IS_ENABLED(scn->wmi_service_bitmap, WMI_SERVICE_RTT)) {
            if (scn->wlan_resource_config.num_peers > CFG_TGT_NUM_RTT_PEERS_MAX)
                scn->wlan_resource_config.num_peers = CFG_TGT_NUM_RTT_PEERS_MAX;
        }

        if (scn->enable_max_clients) {
            if ((scn->wlan_resource_config.num_peers * 2) > CFG_TGT_NUM_TIDS_MAX_200) {
                /* one data tid per peer */
                scn->wlan_resource_config.num_tids = scn->wlan_resource_config.num_peers;
            }
            else if ((scn->wlan_resource_config.num_peers * 4) > CFG_TGT_NUM_TIDS_MAX_200) {
               /* two tids per peer */
               scn->wlan_resource_config.num_tids = scn->wlan_resource_config.num_peers * 2;
            }
            else {
            /* four tids per peer */
                scn->wlan_resource_config.num_tids = scn->wlan_resource_config.num_peers * 4;
            }
        } else {
	    if ((scn->wlan_resource_config.num_peers * 2) > CFG_TGT_NUM_TIDS_MAX) {
                /* one data tid per peer */
                scn->wlan_resource_config.num_tids = scn->wlan_resource_config.num_peers;
            }
            else if ((scn->wlan_resource_config.num_peers * 4) > CFG_TGT_NUM_TIDS_MAX) {
               /* two tids per peer */
               scn->wlan_resource_config.num_tids = scn->wlan_resource_config.num_peers * 2;
            }
            else {
            /* four tids per peer */
                scn->wlan_resource_config.num_tids = scn->wlan_resource_config.num_peers * 4;
            }
        }

        if (scn->max_vdevs) {
            scn->wlan_resource_config.num_vdevs = scn->max_vdevs;
            scn->wlan_resource_config.num_peers += scn->max_vdevs;
        }
        else {
            /* There is a target aseert seen, so temporarily
             * increasing num_vdevs to 16 for LTEu. Ideally,
             * it should be 1. */
            //if (scn->lteu_support) {
                //scn->wlan_resource_config.num_vdevs = 1;
                //scn->wlan_resource_config.num_peers += 1;
            //} else {
                scn->wlan_resource_config.num_peers += CFG_TGT_NUM_VDEV;
            //}
        }
        if (scn->lteu_support)
            scn->wlan_resource_config.fw_feature_bitmap |= FW_FEATURE_LTEU_SUPPORT;
        printk("LARGE_AP enabled. num_peers %d, num_vdevs %d, num_tids %d, lteu_support %d\n",
            scn->wlan_resource_config.num_peers,
            scn->wlan_resource_config.num_vdevs,
            scn->wlan_resource_config.num_tids,
            scn->wlan_resource_config.fw_feature_bitmap & FW_FEATURE_LTEU_SUPPORT);
    }else if(scn->vow_config>>16) {
        //VoW enabled
        scn->wlan_resource_config.num_vdevs = CFG_TGT_NUM_VDEV_VOW;
        scn->wlan_resource_config.num_peers = CFG_TGT_NUM_PEERS_VOW +
                    CFG_TGT_NUM_VDEV_VOW + ol_ath_get_sta_num(scn, \
                            MSDU_DESC_SIZE, MEMORY_REQ_FOR_PEER);
#if UNIFIED_SMARTANTENNA
        /* Both Host and Firmware has Smart Antenna support */
        if (smart_ant_enable) {
            scn->wlan_resource_config.num_peers = ((scn->wlan_resource_config.num_peers > CFG_TGT_NUM_SMART_ANT_PEERS_MAX) ?
                    CFG_TGT_NUM_SMART_ANT_PEERS_MAX:(scn->wlan_resource_config.num_peers));
            scn->wlan_resource_config.smart_ant_cap = 1;
        } else {
            scn->wlan_resource_config.smart_ant_cap = 0;
        }
#else
        scn->wlan_resource_config.smart_ant_cap = 0;
#endif
        scn->wlan_resource_config.num_tids =
                    2 * ( scn->wlan_resource_config.num_vdevs +
                    scn->wlan_resource_config.num_peers );
        scn->wlan_resource_config.num_wds_entries = CFG_TGT_WDS_ENTRIES_VOW;

        scn->wlan_resource_config.vow_config = scn->vow_config;
        printk("VoW Enabled: Num peers = %d Num vdevs = %d Num TIDs = %d\n",
                scn->wlan_resource_config.num_peers,
                scn->wlan_resource_config.num_vdevs,
                scn->wlan_resource_config.num_tids );
    }

#if QCA_AIRTIME_FAIRNESS
    if (WMI_SERVICE_IS_ENABLED(scn->wmi_service_bitmap, WMI_SERVICE_ATF))
    {
        /*Need to add host input if support this feature, if yes, add sta number configuration for resoures as VoW????*/
        ic->atf_fmcap = 1;
        if(ic->atf_mode) {
            if(ic->atf_fmcap) {
                /*Before here, should add if host need to support this one */
                scn->wlan_resource_config.num_peers = CFG_TGT_NUM_PEERS_ATF + CFG_TGT_NUM_VDEV;
                /* When ATF is Enabled the number of active clients is 32 and number of Vdevs is 16 */
                printk("ATF Enabled: Num peers = %d Num vdevs = %d Num TIDs = %d\n",
                        scn->wlan_resource_config.num_peers,
                        scn->wlan_resource_config.num_vdevs,
                        scn->wlan_resource_config.num_tids );
                scn->wlan_resource_config.fw_feature_bitmap |= FW_FEATURE_ATF_CONFIG_BIT;
            }
        }
    }
#endif
    OS_MEMCPY(target_cap.wmi_service_bitmap,scn->wmi_service_bitmap,sizeof(scn->wmi_service_bitmap));
    target_cap.wlan_resource_config = scn->wlan_resource_config;

    /* call back into  os shim with the services bitmap and resource config to let
     * the os shim layer modify it according to its needs and requirements */
    if (scn->cfg_cb) {
        scn->cfg_cb(scn, &target_cap);
        OS_MEMCPY(scn->wmi_service_bitmap,target_cap.wmi_service_bitmap, sizeof(scn->wmi_service_bitmap));
        scn->wlan_resource_config = target_cap.wlan_resource_config;
    }

    ol_ath_update_caps(ic, ev, scn->wmi_service_bitmap);
    OS_MEMCPY(&scn->hal_reg_capabilities, &ev->hal_reg_capabilities, sizeof(HAL_REG_CAPABILITIES));
    scn->max_tx_power = ev->hw_max_tx_power;
    scn->min_tx_power = ev->hw_min_tx_power;

    scn->txpowlimit2G = scn->max_tx_power;
    scn->txpowlimit5G = scn->max_tx_power;
    scn->txpower_scale = WMI_TP_SCALE_MAX;

    ieee80211com_set_txpowerlimit(ic, scn->max_tx_power);

    ol_regdmn_attach(scn);

    ol_regdmn_set_regdomain(scn->ol_regdmn_handle, scn->hal_reg_capabilities.eeprom_rd);
    ol_regdmn_set_regdomain_ext(scn->ol_regdmn_handle, scn->hal_reg_capabilities.eeprom_rd_ext);

    cmd = (wmi_init_cmd *)wmi_buf_data(buf);
    cmd->resource_config = scn->wlan_resource_config;
    /* allocate memory requested by FW */
    ASSERT (ev->num_mem_reqs <= WMI_MAX_MEM_REQS);
    cmd->num_host_mem_chunks = 0;
    if (ev->num_mem_reqs) {
        u_int32_t num_units;
        for(idx=0;idx < ev->num_mem_reqs; ++idx) {
            num_units = ev->mem_reqs[idx].num_units;
            if ( ev->mem_reqs[idx].num_unit_info ) {
               if  ( ev->mem_reqs[idx].num_unit_info & NUM_UNITS_IS_NUM_PEERS ) {
	            /* number of units to allocate is number of peers, 1 extra for self peer on target */
                   /* this needs to be fied, host and target can get out of sync */
                    num_units = cmd->resource_config.num_peers + 1;
               }
            }
           printk("idx %d req %d  num_units %d num_unit_info %d unit size %d actual units %d \n",idx,
                                   ev->mem_reqs[idx].req_id,
                                   ev->mem_reqs[idx].num_units,
                                   ev->mem_reqs[idx].num_unit_info,
                                   ev->mem_reqs[idx].unit_size,
                                   num_units);
            ol_ath_alloc_host_mem(scn_handle, ev->mem_reqs[idx].req_id,
                                   num_units,
                                   ev->mem_reqs[idx].unit_size);
        }
        for(idx=0;idx<scn->num_mem_chunks; ++idx) {
           cmd->host_mem_chunks[idx].ptr = scn->mem_chunks[idx].paddr;
           cmd->host_mem_chunks[idx].size = scn->mem_chunks[idx].len;
           cmd->host_mem_chunks[idx].req_id = scn->mem_chunks[idx].req_id;
           printk("chunk %d len %d requested ,ptr  0x%x \n",idx,
           cmd->host_mem_chunks[idx].size ,
              cmd->host_mem_chunks[idx].ptr ) ;
        }
        cmd->num_host_mem_chunks = scn->num_mem_chunks;
        if (scn->num_mem_chunks > 1 ) {
            len += ((scn->num_mem_chunks-1) * sizeof(wlan_host_memory_chunk)) ;
        }
    }
    wmi_unified_cmd_send(scn->wmi_handle, buf, len, WMI_INIT_CMDID);
}

void
ol_ath_ready_event(ol_scn_t scn_handle, wmi_ready_event *ev)
{
    struct ol_ath_softc_net80211 *scn = (struct ol_ath_softc_net80211 *)scn_handle;

    scn->version.wlan_ver = ev->sw_version;
    scn->version.abi_ver = ev->abi_version;

    /*
     * Indicate to the waiting thread that the ready
     * event was received
     */
    scn->wmi_ready = TRUE;
    scn->wlan_init_status = ev->status;
    /* copy the mac addr */
    WMI_MAC_ADDR_TO_CHAR_ARRAY (&ev->mac_addr, scn->sc_ic.ic_myaddr);
    WMI_MAC_ADDR_TO_CHAR_ARRAY (&ev->mac_addr, scn->sc_ic.ic_my_hwaddr);
    __ol_ath_wmi_ready_event(scn);

}

/*
 *  WMI API for getting TPC configuration
 */
int
wmi_unified_pdev_get_tpc_config(wmi_unified_t wmi_handle, u_int32_t param)
{
    wmi_pdev_get_tpc_config_cmd *cmd;
    wmi_buf_t buf;
    int32_t len = sizeof(wmi_pdev_get_tpc_config_cmd);

    buf = wmi_buf_alloc(wmi_handle, len);
    if (!buf) {
        printk("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return -1;
    }
    cmd = (wmi_pdev_get_tpc_config_cmd *)wmi_buf_data(buf);
    cmd->param = param;
    return wmi_unified_cmd_send(wmi_handle, buf, len, WMI_PDEV_GET_TPC_CONFIG_CMDID);
}

#if WLAN_DEBUG_CMD_SUPPORT
int
wmi_unified_pdev_print_info(wmi_unified_t wmi_handle)
{
   wmi_buf_t buf;

   buf = wmi_buf_alloc(wmi_handle, 0);
   if (!buf) {
       printk("%s:wmi_buf_alloc failed\n", __FUNCTION__);
       return -1;
   }
   return wmi_unified_cmd_send(wmi_handle, buf, 0, WMI_PDEV_GET_INFO);

}

int
wmi_unified_vdev_print_info(wmi_unified_t wmi_handle, u_int32_t param)
{
   wmi_vdev_get_info *cmd;
   wmi_buf_t buf;
   int32_t len = sizeof(wmi_vdev_get_info);

   buf = wmi_buf_alloc(wmi_handle, len);
   if (!buf) {
       printk("%s:wmi_buf_alloc failed\n", __FUNCTION__);
       return -1;
   }
   cmd = (wmi_vdev_get_info *)wmi_buf_data(buf);
   cmd->vdev_id = param;

   return wmi_unified_cmd_send(wmi_handle, buf, len, WMI_VDEV_GET_INFO);

}
#endif

/*
 *  WMI API for setting fw hang.
 *  type parameter can be one of the 6 values defined in
 *  wmi_unified.h enumerated as RECOVERY_SIM_TYPE
 */
int
wmi_unified_pdev_set_fw_hang(wmi_unified_t wmi_handle, u_int32_t delay_time_ms)
{
    WMI_FORCE_FW_HANG_CMD *cmd;
    wmi_buf_t buf;
    int32_t len = sizeof(WMI_FORCE_FW_HANG_CMD);

    buf = wmi_buf_alloc(wmi_handle, len);
    if (!buf) {
        printk("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return -1;
    }
    cmd = (WMI_FORCE_FW_HANG_CMD *)wmi_buf_data(buf);
    cmd->type = 1;
    cmd->delay_time_ms = delay_time_ms;
    return wmi_unified_cmd_send(wmi_handle, buf, len, WMI_FORCE_FW_HANG_CMDID);
}


/*
 *  WMI API for setting device params
 */
int
wmi_unified_pdev_set_param(wmi_unified_t wmi_handle, u_int32_t param_id,
                           u_int32_t param_value)
{
    wmi_pdev_set_param_cmd *cmd;
    wmi_buf_t buf;
    int len = sizeof(wmi_pdev_set_param_cmd);
    buf = wmi_buf_alloc(wmi_handle, len);
    if (!buf) {
        printk("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return -1;
    }
    cmd = (wmi_pdev_set_param_cmd *)wmi_buf_data(buf);
    cmd->param_id = param_id;
    cmd->param_value = param_value;
    return wmi_unified_cmd_send(wmi_handle, buf, len, WMI_PDEV_SET_PARAM_CMDID);
}

#if QCA_AIRTIME_FAIRNESS
/*
 *  WMI API for ATF
 */
    int
wmi_unified_pdev_set_atf(wmi_unified_t wmi_handle, struct ieee80211vap *vap)
{
#define ENOBUFF 1
    struct ieee80211com *ic = vap->iv_ic;
    struct wmi_atf_peer_info   *peer_info;
    wmi_peer_atf_request *cmd;
    wmi_buf_t buf;
    int len = sizeof(wmi_peer_atf_request);
    int i,retval = 0;

    len += ic->wmi_atfreq.num_peers * sizeof(struct wmi_atf_peer_info);
    buf = wmi_buf_alloc(wmi_handle, len);
    if (!buf) {
        printk("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return -ENOBUFF;
    }

    cmd = (wmi_peer_atf_request *)wmi_buf_data(buf);
    OS_MEMCPY((void *)&(cmd->num_peers),(void *)&(ic->wmi_atfreq.num_peers),sizeof(u_int32_t));
    peer_info = (struct wmi_atf_peer_info *)&(cmd->peer_info[0]);
    for (i =0; i< ic->wmi_atfreq.num_peers;i++)
    {
        OS_MEMCPY((void *)&(peer_info[i]),(void *)&(ic->wmi_atfreq.atf_peer_info[i]),sizeof(struct wmi_atf_peer_info));
    }
    retval = wmi_unified_cmd_send(wmi_handle, buf, len, WMI_PEER_ATF_REQUEST_CMDID);
    return retval;
}
#endif

int
wmi_unified_wlan_profile_enable(wmi_unified_t wmi_handle, u_int32_t param_id,
                           u_int32_t param_value)
{
    wmi_wlan_profile_trigger_cmd *cmd;
    wmi_buf_t buf;
    int len = sizeof(wmi_wlan_profile_trigger_cmd);
    buf = wmi_buf_alloc(wmi_handle, len);
    if (!buf) {
        printk("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return -1;
    }
    cmd = (wmi_wlan_profile_trigger_cmd *)wmi_buf_data(buf);
    cmd->enable = param_value;

    return wmi_unified_cmd_send(wmi_handle, buf, len, WMI_WLAN_PROFILE_TRIGGER_CMDID);
}

int
wmi_unified_pdev_set_channel(wmi_unified_t wmi_handle,
                           struct ieee80211_channel *chan, u_int32_t freq)
{
    wmi_set_channel_cmd *cmd;
    wmi_buf_t buf;
    u_int32_t chan_mode;
    static const u_int modeflags[] = {
        0,                            /* IEEE80211_MODE_AUTO           */
        MODE_11A,         /* IEEE80211_MODE_11A            */
        MODE_11B,         /* IEEE80211_MODE_11B            */
        MODE_11G,         /* IEEE80211_MODE_11G            */
        0,                            /* IEEE80211_MODE_FH             */
        0,                            /* IEEE80211_MODE_TURBO_A        */
        0,                            /* IEEE80211_MODE_TURBO_G        */
        MODE_11NA_HT20,   /* IEEE80211_MODE_11NA_HT20      */
        MODE_11NG_HT20,   /* IEEE80211_MODE_11NG_HT20      */
        MODE_11NA_HT40,   /* IEEE80211_MODE_11NA_HT40PLUS  */
        MODE_11NA_HT40,   /* IEEE80211_MODE_11NA_HT40MINUS */
        MODE_11NG_HT40,   /* IEEE80211_MODE_11NG_HT40PLUS  */
        MODE_11NG_HT40,   /* IEEE80211_MODE_11NG_HT40MINUS */
        MODE_11NG_HT40,   /* IEEE80211_MODE_11NG_HT40      */
        MODE_11NA_HT40,   /* IEEE80211_MODE_11NA_HT40      */
        MODE_11AC_VHT20,  /* IEEE80211_MODE_11AC_VHT20     */
        MODE_11AC_VHT40,  /* IEEE80211_MODE_11AC_VHT40PLUS */
        MODE_11AC_VHT40,  /* IEEE80211_MODE_11AC_VHT40MINUS*/
        MODE_11AC_VHT40,  /* IEEE80211_MODE_11AC_VHT40     */
        MODE_11AC_VHT80,  /* IEEE80211_MODE_11AC_VHT80     */
    };

    int len = sizeof(wmi_set_channel_cmd);
    struct ol_ath_softc_net80211 *scn;

    scn = (struct ol_ath_softc_net80211 *)wmi_get_scn_handle(wmi_handle);

    buf = wmi_buf_alloc(wmi_handle, len);
    if (!buf) {
        printk("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return -1;
    }

    cmd = (wmi_set_channel_cmd *)wmi_buf_data(buf);

    cmd->chan.mhz = freq;

    chan_mode = ieee80211_chan2mode(chan);
    WMI_SET_CHANNEL_MODE(&cmd->chan, modeflags[chan_mode]);

    if(chan_mode == IEEE80211_MODE_11AC_VHT80) {
            if (chan->ic_ieee < 20)
                cmd->chan.band_center_freq1 = ieee80211_ieee2mhz(&scn->sc_ic,
                                                          chan->ic_vhtop_ch_freq_seg1, IEEE80211_CHAN_2GHZ);
            else
                cmd->chan.band_center_freq1 = ieee80211_ieee2mhz(&scn->sc_ic,
                                                          chan->ic_vhtop_ch_freq_seg1, IEEE80211_CHAN_5GHZ);
    } else if((chan_mode == IEEE80211_MODE_11NA_HT40PLUS) || (chan_mode == IEEE80211_MODE_11NG_HT40PLUS) ||
        (chan_mode == IEEE80211_MODE_11AC_VHT40PLUS)) {
            cmd->chan.band_center_freq1 = freq + 10;
    } else if((chan_mode == IEEE80211_MODE_11NA_HT40MINUS) || (chan_mode == IEEE80211_MODE_11NG_HT40MINUS) ||
        (chan_mode == IEEE80211_MODE_11AC_VHT40MINUS)) {
            cmd->chan.band_center_freq1 = freq - 10;
    } else {
            cmd->chan.band_center_freq1 = freq;
    }
    /* we do not support HT80PLUS80 yet */
    cmd->chan.band_center_freq2=0;

    WMI_SET_CHANNEL_MIN_POWER(&cmd->chan, chan->ic_minpower);
    WMI_SET_CHANNEL_MAX_POWER(&cmd->chan, chan->ic_maxpower);
    WMI_SET_CHANNEL_REG_POWER(&cmd->chan, chan->ic_maxregpower);
    WMI_SET_CHANNEL_ANTENNA_MAX(&cmd->chan, chan->ic_antennamax);
    WMI_SET_CHANNEL_REG_CLASSID(&cmd->chan, chan->ic_regClassId);

    if (IEEE80211_IS_CHAN_DFS(chan))
        WMI_SET_CHANNEL_FLAG(&cmd->chan, WMI_CHAN_FLAG_DFS);
    if (IEEE80211_IS_CHAN_HALF(chan))
        WMI_SET_CHANNEL_FLAG(&cmd->chan, WMI_CHAN_FLAG_HALF);
    if (IEEE80211_IS_CHAN_QUARTER(chan))
        WMI_SET_CHANNEL_FLAG(&cmd->chan, WMI_CHAN_FLAG_QUARTER);

    printk("WMI channel freq=%d, mode=%x band_center_freq1=%d\n", cmd->chan.mhz,
        WMI_GET_CHANNEL_MODE(&cmd->chan), cmd->chan.band_center_freq1);

    return wmi_unified_cmd_send(wmi_handle, buf, len,
                                WMI_PDEV_SET_CHANNEL_CMDID);
}

int
wmi_unified_pdev_set_ht_ie(wmi_unified_t wmi_handle, u_int32_t ie_len, u_int8_t *ie_data)
{
    wmi_pdev_set_ht_ie_cmd *cmd;
    wmi_buf_t buf;
    /* adjust length to be next multiple of four */
    int len = (ie_len + (sizeof(u_int32_t) - 1)) & (~(sizeof(u_int32_t) - 1));
    len += (sizeof(wmi_pdev_set_ht_ie_cmd) - 4 /* to account for extra four bytes of ie data in the struct */);

    buf = wmi_buf_alloc(wmi_handle, len);
    if (!buf) {
        printk("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return -1;
    }
    cmd = (wmi_pdev_set_ht_ie_cmd  *)wmi_buf_data(buf);
    cmd->ie_len = ie_len;
    OS_MEMCPY(cmd->ie_data,ie_data,ie_len);
#ifdef BIG_ENDIAN_HOST
	SWAPME(cmd->ie_data,len-(offsetof(wmi_pdev_set_ht_ie_cmd, ie_data)));
#endif
    return wmi_unified_cmd_send(wmi_handle, buf, len, WMI_PDEV_SET_HT_CAP_IE_CMDID);
}

int
wmi_unified_pdev_set_vht_ie(wmi_unified_t wmi_handle, u_int32_t ie_len, u_int8_t *ie_data)
{
    wmi_pdev_set_vht_ie_cmd *cmd;
    wmi_buf_t buf;
    /* adjust length to be next multiple of four */
    int len = (ie_len + (sizeof(u_int32_t) - 1)) & (~(sizeof(u_int32_t) - 1));
    len += (sizeof(wmi_pdev_set_vht_ie_cmd) - 4 /* to account for extra four bytes of ie data in the struct */);

    buf = wmi_buf_alloc(wmi_handle, len);
    if (!buf) {
        printk("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return -1;
    }
    cmd = (wmi_pdev_set_vht_ie_cmd *)wmi_buf_data(buf);
    cmd->ie_len = ie_len;
    OS_MEMCPY(cmd->ie_data,ie_data,ie_len);
#ifdef BIG_ENDIAN_HOST
	SWAPME(cmd->ie_data,len-(offsetof(wmi_pdev_set_vht_ie_cmd, ie_data)));
#endif
    return wmi_unified_cmd_send(wmi_handle, buf, len, WMI_PDEV_SET_VHT_CAP_IE_CMDID);
}

#define MAX_IE_SIZE 512

void ol_ath_set_ht_vht_ies(struct ieee80211_node *ni)
{
    struct ieee80211com *ic = ni->ni_ic;
    struct ieee80211vap *vap = ni->ni_vap;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    if (!scn->set_ht_vht_ies) {
        u_int8_t *buf=adf_os_mem_alloc(scn->adf_dev, MAX_IE_SIZE);
        u_int8_t *buf_end;
        if (buf) {
            buf_end = ieee80211_add_htcap(buf, vap->iv_bss,IEEE80211_FC0_SUBTYPE_PROBE_REQ);
            if ((buf_end - buf ) <= MAX_HT_IE_LEN ) {
                wmi_unified_pdev_set_ht_ie(scn->wmi_handle,buf_end-buf, buf);
            } else {
                printk("%s: HT IE length %d is more than expected\n",__func__, (buf_end-buf));
            }
            buf_end = ieee80211_add_vhtcap(buf, vap->iv_bss,ic, IEEE80211_FC0_SUBTYPE_PROBE_REQ);
            if ((buf_end - buf ) <= MAX_VHT_IE_LEN ) {
                wmi_unified_pdev_set_vht_ie(scn->wmi_handle,buf_end-buf,buf);
            } else {
                printk("%s: VHT IE length %d is more than expected\n",__func__, (buf_end-buf));
            }
            scn->set_ht_vht_ies = 1;
            adf_os_mem_free(buf);
        }
    }
}

struct ieee80211_channel *
ol_ath_find_full_channel(struct ieee80211com *ic, u_int32_t freq)
{
    struct ieee80211_channel    *c;
    c = NULL;
#define IEEE80211_2GHZ_FREQUENCY_THRESHOLD    3000            // in kHz
    if (freq < IEEE80211_2GHZ_FREQUENCY_THRESHOLD) { /* 2GHZ channel */
        if (IEEE80211_SUPPORT_PHY_MODE(ic, IEEE80211_MODE_11NG_HT20)) {
            c = ieee80211_find_channel(ic, freq, IEEE80211_CHAN_11NG_HT20);
        }

        if (c == NULL) {
            c = ieee80211_find_channel(ic, freq, IEEE80211_CHAN_G);
        }


        if (c == NULL) {
            c = ieee80211_find_channel(ic, freq, IEEE80211_CHAN_PUREG);
        }

        if (c == NULL) {
            c = ieee80211_find_channel(ic, freq, IEEE80211_CHAN_B);
        }
    } else {
        if (IEEE80211_SUPPORT_PHY_MODE(ic, IEEE80211_MODE_11NA_HT20)) {
            c = ieee80211_find_channel(ic, freq, IEEE80211_CHAN_11NA_HT20);
        }

        if (c == NULL) {
            u_int32_t halfquarter = ic->ic_chanbwflag & (IEEE80211_CHAN_HALF | IEEE80211_CHAN_QUARTER);
            c = ieee80211_find_channel(ic, freq, IEEE80211_CHAN_A | halfquarter);
        }
    }
    return c;
#undef IEEE80211_2GHZ_FREQUENCY_THRESHOLD
}

/* Offload Interface functions for UMAC */
static int
ol_ath_init(struct ieee80211com *ic)
{
    /* TBD */
    return 0;
}

static int
ol_ath_reset_start(struct ieee80211com *ic, bool no_flush)
{
    /* TBD */
    return 0;
}

static int
ol_ath_reset_end(struct ieee80211com *ic, bool no_flush)
{
    /* TBD */
    return 0;
}

static void
ol_set_beacon_interval(struct ieee80211com *ic)
{
    /* TBD */
    return;
}

static int
ol_ath_reset(struct ieee80211com *ic)
{
    /* TBD */
    return 0;
}

static void
ol_ath_updateslot(struct ieee80211com *ic)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wlan_if_t vap = NULL;
    struct ol_ath_vap_net80211 *avn = NULL;
    int slottime;

    TAILQ_FOREACH(vap, &ic->ic_vaps, iv_next) {
        if (vap != NULL) {
            avn = OL_ATH_VAP_NET80211(vap);
            break;
        }
    }
    if (NULL == avn) {
        return;
    }

    slottime = (IEEE80211_IS_SHSLOT_ENABLED(ic)) ?  9 : 20;

    if(IEEE80211_IS_SHSLOT_ENABLED(ic)) {
        wmi_unified_vdev_set_param_send(scn->wmi_handle, avn->av_if_id,
            WMI_VDEV_PARAM_SLOT_TIME, WMI_VDEV_SLOT_TIME_SHORT);
    } else {
        wmi_unified_vdev_set_param_send(scn->wmi_handle, avn->av_if_id,
            WMI_VDEV_PARAM_SLOT_TIME, WMI_VDEV_SLOT_TIME_LONG);
    }
    return;
}

static int
ol_ath_wmm_update(struct ieee80211com *ic)
{
#define ATH_EXPONENT_TO_VALUE(v)    ((1<<v)-1)
#define ATH_TXOP_TO_US(v)           (v<<5)
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_buf_t buf;
    wmi_pdev_set_wmm_params_cmd *cmd;
    wmi_wmm_params *wmi_param = 0;
    int ac;
    struct wmeParams *wmep;
    int len = sizeof(wmi_pdev_set_wmm_params_cmd);

    buf = wmi_buf_alloc(scn->wmi_handle, len);
    printk("%s:\n", __FUNCTION__);
    if (!buf) {
        printk("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return 0;
    }
    cmd = (wmi_pdev_set_wmm_params_cmd*)wmi_buf_data(buf);

    for (ac = 0; ac < WME_NUM_AC; ac++) {
        wmep = ieee80211com_wmm_chanparams(ic, ac);

        switch (ac) {
        case WME_AC_BE:
            wmi_param = &cmd->wmm_params_ac_be;
            break;
        case WME_AC_BK:
            wmi_param = &cmd->wmm_params_ac_bk;
            break;
        case WME_AC_VI:
            wmi_param = &cmd->wmm_params_ac_vi;
            break;
        case WME_AC_VO:
            wmi_param = &cmd->wmm_params_ac_vo;
            break;
        default:
            break;
        }

        wmi_param->aifs = wmep->wmep_aifsn;
        wmi_param->cwmin = ATH_EXPONENT_TO_VALUE(wmep->wmep_logcwmin);
        wmi_param->cwmax = ATH_EXPONENT_TO_VALUE(wmep->wmep_logcwmax);
        wmi_param->txoplimit = ATH_TXOP_TO_US(wmep->wmep_txopLimit);
        wmi_param->acm = wmep->wmep_acm;
        wmi_param->no_ack = wmep->wmep_noackPolicy;

#if 0
        printk("WMM PARAMS AC [%d]: AIFS %d Min %d Max %d TXOP %d ACM %d NOACK %d\n",
                ac,
                wmi_param->aifs,
                wmi_param->cwmin,
                wmi_param->cwmax,
                wmi_param->txoplimit,
                wmi_param->acm,
                wmi_param->no_ack
                );
#endif
    }

    wmi_unified_cmd_send(scn->wmi_handle, buf, len, WMI_PDEV_SET_WMM_PARAMS_CMDID);
    return 0;
}


static u_int32_t
ol_ath_txq_depth(struct ieee80211com *ic)
{
    /* TBD */
    return 0;
}

static u_int32_t
ol_ath_txq_depth_ac(struct ieee80211com *ic,int ac)
{
    /* TBD */
    return 0;
}

/*
 * Function to set 802.11 protection mode
 */
static void
ol_ath_update_protmode(struct ieee80211com *ic)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wlan_if_t vap = NULL;
    struct ol_ath_vap_net80211 *avn = NULL;
    A_UINT8  protmode = IEEE80211_PROT_NONE;

    if (IEEE80211_IS_PROTECTION_ENABLED(ic)) {
        /* Protection flag is set. Use ic_protmode */
        protmode = ic->ic_protmode;
    }

    TAILQ_FOREACH(vap, &ic->ic_vaps, iv_next) {
        if (vap != NULL) {
	    avn = OL_ATH_VAP_NET80211(vap);
	    if (NULL != avn)
                wmi_unified_vdev_set_param_send(scn->wmi_handle, avn->av_if_id,
                                WMI_VDEV_PARAM_PROTECTION_MODE, protmode);
        }
    }
}

static void
ol_net80211_chwidth_change(struct ieee80211_node *ni)
{
    struct ieee80211com *ic = ni->ni_ic;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    struct ol_ath_vap_net80211 *avn = OL_ATH_VAP_NET80211(ni->ni_vap);

    if(wmi_unified_node_set_param(scn->wmi_handle,ni->ni_macaddr,WMI_PEER_CHWIDTH,
            ni->ni_chwidth,avn->av_if_id)) {
        printk("%s:Unable to change peer bandwidth\n", __func__);
    }
}

static void
ol_net80211_nss_change(struct ieee80211_node *ni)
{
    struct ieee80211com *ic = ni->ni_ic;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    struct ol_ath_vap_net80211 *avn = OL_ATH_VAP_NET80211(ni->ni_vap);

    if(wmi_unified_node_set_param(scn->wmi_handle,ni->ni_macaddr,WMI_PEER_NSS,
            ni->ni_streams,avn->av_if_id)) {
        printk("%s:Unable to change peer Nss\n", __func__);
    }

    ol_ath_node_update(ni);
}

struct ol_vap_mode_count {
    u_int32_t non_monitor_mode_vap_cnt;
    u_int32_t monitor_mode_vap_cnt;
};

static void check_monitor_only_vapmode(void *arg, struct ieee80211vap *vap)
{
    struct ol_vap_mode_count *mode_cnt = (struct ol_vap_mode_count *)arg;

    if (IEEE80211_M_MONITOR != vap->iv_opmode) {
        mode_cnt->non_monitor_mode_vap_cnt++;
    } else if (IEEE80211_M_MONITOR == vap->iv_opmode) {
        mode_cnt->monitor_mode_vap_cnt++;
    }

    return;
}


static void get_monitor_mode_vap(void *arg, struct ieee80211vap *vap)
{
    ieee80211_vap_t *ppvap=(ieee80211_vap_t *)arg;

    if (IEEE80211_M_MONITOR == vap->iv_opmode) {
        *ppvap = vap;
    }

    return;
}

static void get_ap_mode_vap(void *arg, struct ieee80211vap *vap)
{
    ieee80211_vap_t *ppvap=(ieee80211_vap_t *)arg;

    if (IEEE80211_M_HOSTAP == vap->iv_opmode) {
        *ppvap = vap;
    }

    return;
}

static void get_sta_mode_vap(void *arg, struct ieee80211vap *vap)
{
    ieee80211_vap_t *ppvap=(ieee80211_vap_t *)arg;

    if (IEEE80211_M_STA == vap->iv_opmode) {
        *ppvap = vap;
    }

    return;
}

static void ol_vap_restart_iter_func(void *arg, struct ieee80211vap *vap)
{
    struct ol_ath_vap_net80211 *avn;
    struct ol_ath_softc_net80211 *scn;
    struct ieee80211_channel *chan = (struct ieee80211_channel *)arg;
    if (IEEE80211_M_HOSTAP == vap->iv_opmode) {
        avn = OL_ATH_VAP_NET80211(vap);
        scn = avn->av_sc;
        if (wmi_unified_vdev_restart_send(scn->wmi_handle,
            avn->av_if_id, chan,
            chan->ic_freq, IEEE80211_IS_CHAN_DFS(chan))) {
            printk("ERROR : %s[%d] Unable to bring up the interface for ath_dev.\n", __func__, __LINE__);
        }
        avn->av_ol_resmgr_wait = TRUE;
    }
    return;
}

static void
ol_ath_net80211_enable_radar(struct ieee80211com *ic, int no_cac)
{
}

static int
ol_ath_set_channel(struct ieee80211com *ic)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    struct ieee80211_channel *chan;
    u_int32_t freq;
    ieee80211_vap_t vap = NULL;
    struct ol_ath_vap_net80211 *avn = NULL;
    struct ol_vap_mode_count mode_cnt;

    chan = ieee80211_get_current_channel(ic);

    freq = ieee80211_chan2freq(ic, chan);
    if (!freq) {
        printk("ERROR : INVALID Freq \n");
        return 0;
    }

    printk("set channel freq %d \n",freq);

    /* update max channel power to max regpower of current channel */
    ieee80211com_set_curchanmaxpwr(ic, chan->ic_maxregpower);

    /* Update the channel for monitor mode path */
    ol_txrx_set_curchan(scn->pdev_txrx_handle, freq);

    /* Call a new channel change WMI cmd for monitor mode only. For all other
     * modes the vdev_start would happen via the resmgr_vap_start() path.
     */
    mode_cnt.non_monitor_mode_vap_cnt = 0;
    mode_cnt.monitor_mode_vap_cnt = 0;

    wlan_iterate_vap_list(ic, check_monitor_only_vapmode ,(void *)&mode_cnt);

    if (mode_cnt.non_monitor_mode_vap_cnt == 0 && mode_cnt.monitor_mode_vap_cnt >= 1) {

        wlan_iterate_vap_list(ic, get_monitor_mode_vap ,(void *)&vap );
        if (vap) {
            avn = OL_ATH_VAP_NET80211(vap);
            if (wmi_unified_vdev_restart_send(scn->wmi_handle,
                     avn->av_if_id, chan,
                     freq, IEEE80211_IS_CHAN_DFS(chan))) {
                printk("%s[%d] Unable to bring up the interface for ath_dev.\n", __func__, __LINE__);
                return -1;
            }
            avn->av_ol_resmgr_wait = TRUE;
        }
    } else {
        wlan_iterate_vap_list(ic, get_sta_mode_vap ,(void *)&vap );
        if (vap) {
            /* There is a active STA mode vap.
             * for STA mode channel change will happen through resmgr channnel change
             */
             return -1;
        }
        else {
            /* Call a new channel change WMI cmd for all AP mode.  */
            wlan_iterate_vap_list(ic, ol_vap_restart_iter_func ,(void *)chan );
        }
    }
#if ATH_SUPPORT_DFS
    /*
        EV129487 :
        We should not call ol_if_dfs_configure here.
        This will be done when FW indicates that channel
        switch request is complete. This is handled in
        ol_vdev_wmi_event_handler when firmware sends
        ol_vdev_start_resp_ev
    */

    //ol_if_dfs_configure(ic);
#endif
    /* once the channel change is complete, turn on the dcs,
     * use the same state as what the current enabled state of the dcs. Also
     * set the run state accordingly.
     */
    (void)wmi_unified_pdev_set_param(scn->wmi_handle, WMI_PDEV_PARAM_DCS, scn->scn_dcs.dcs_enable&0x0f);
    printk("DCS previous state is restored \n");

    (OL_IS_DCS_ENABLED(scn->scn_dcs.dcs_enable)) ? (OL_ATH_DCS_SET_RUNSTATE(scn->scn_dcs.dcs_enable)) :
                            (OL_ATH_DCS_CLR_RUNSTATE(scn->scn_dcs.dcs_enable));

    return 0;
}

static void
ol_ath_log_text(struct ieee80211com *ic, char *text)
{
    /* TBD */
    return;
}

static void
ol_ath_pwrsave_set_state(struct ieee80211com *ic, IEEE80211_PWRSAVE_STATE newstate)
{
    /* The host does not manage the HW power state with offload FW. This function
     * exists solely for completeness.
     */
}

u_int
ol_ath_mhz2ieee(struct ieee80211com *ic, u_int freq, u_int flags)
{
#define IS_CHAN_IN_PUBLIC_SAFETY_BAND(_c) ((_c) > 4940 && (_c) < 4990)
struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    /* TBD */
     /* FIXME: This change has been added for testing
      * This below code block is copied from direct attach architecture
      * Some of the code has been disabled because those APIs and Macros yet
      * to be defined
      */

#if 0
    if (flags & CHANNEL_2GHZ) { /* 2GHz band */
        if (freq == 2484)
            return 14;
        if (freq < 2484)
            return (freq - 2407) / 5;
        else
            return 15 + ((freq - 2512) / 20);
    } else if (flags & CHANNEL_5GHZ) {/* 5Ghz band */
     /*   if (ath_hal_ispublicsafetysku(ah) &&
            IS_CHAN_IN_PUBLIC_SAFETY_BAND(freq)) {
            return ((freq * 10) +
                (((freq % 5) == 2) ? 5 : 0) - 49400) / 5;
        } else */if ((flags & CHANNEL_A) && (freq <= 5000)) {
            return (freq - 4000) / 5;
        } else {
            return (freq - 5000) / 5;
        }
    } else
#endif
    {            /* either, guess */
        if (freq == 2484)
            return 14;
        if (freq < 2484)
            return (freq - 2407) / 5;
        if (freq < 5000) {
            if (ol_regdmn_ispublicsafetysku(scn->ol_regdmn_handle)
                && IS_CHAN_IN_PUBLIC_SAFETY_BAND(freq)) {
                return ((freq * 10) +
                    (((freq % 5) == 2) ? 5 : 0) - 49400)/5;
            } else if (freq > 4900) {
                return (freq - 4000) / 5;
            } else {
                return 15 + ((freq - 2512) / 20);
            }
        }
        return (freq - 5000) / 5;
    }
}


static int16_t ol_ath_get_noisefloor (struct ieee80211com *ic, struct ieee80211_channel *chan,
                                        int wait_time)
{
    /* TBD */
    return 0;
}
#if ATH_SUPPORT_HYFI_ENHANCEMENTS
static  void ol_ath_net80211_check_buffull_condition(struct ieee80211com *ic)
{
	struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
	if(scn->buff_thresh.free_descs <= scn->buff_thresh.ald_free_buf_lvl)
	{
			scn->buff_thresh.ald_buffull_wrn = 0;
	}
	else
			scn->buff_thresh.ald_buffull_wrn = 1;
}
#endif
static int16_t ol_ath_net80211_get_cur_chan_noisefloor(struct ieee80211com *ic)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    return scn->chan_nf;
}

static void
ol_ath_get_chainnoisefloor(struct ieee80211com *ic, struct ieee80211_channel *chan, int16_t *nfBuf)
{
    /* TBD */
    return;
}

static void
ol_ath_set_ant_switch_tbl(struct ieee80211com *ic, u_int32_t antCtrlCommon1, u_int32_t antCtrlCommon2)
{
    u_int8_t len;
    wmi_buf_t buf;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    wmi_pdev_set_ant_switch_tbl_cmd *cmd;
    len = sizeof(wmi_pdev_set_ant_switch_tbl_cmd);
    buf = wmi_buf_alloc(scn->wmi_handle, len);
    if (!buf) {
        adf_os_print("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return;
    }
    cmd = (wmi_pdev_set_ant_switch_tbl_cmd *)wmi_buf_data(buf);
    cmd->antCtrlCommon1 = antCtrlCommon1;
    cmd->antCtrlCommon2 = antCtrlCommon2;

    if(wmi_unified_cmd_send(scn->wmi_handle, buf, len,
        WMI_PDEV_SET_ANTENNA_SWITCH_TABLE_CMDID)) {
        return;
    }

    return;

}

/*
 * Override the rate power table in EEPROM
 */
static void
ol_ath_set_ratepwr_table(struct ieee80211com *ic, u_int8_t *ratepwr_tbl, u_int16_t ratepwr_len)
{
    u_int16_t len;
    wmi_buf_t buf;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_pdev_ratepwr_table_cmd *cmd;

    if (!ratepwr_tbl)
        return;

    len = sizeof(wmi_pdev_ratepwr_table_cmd);
    len += roundup(ratepwr_len, sizeof(A_UINT32)) - sizeof(A_UINT32);  /* already 4 bytes in cmd structure */
    printk("wmi buf len = %d\n", len);
    buf = wmi_buf_alloc(scn->wmi_handle, len);
    if (!buf) {
        adf_os_print("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return;
    }
    cmd = (wmi_pdev_ratepwr_table_cmd *)wmi_buf_data(buf);

    cmd->op = RATEPWR_TABLE_OPS_SET;
    cmd->ratepwr_len = ratepwr_len;
    OL_IF_MSG_COPY_CHAR_ARRAY(&cmd->ratepwr_tbl[0], ratepwr_tbl, ratepwr_len);

    if(wmi_unified_cmd_send(scn->wmi_handle, buf, len,
        WMI_PDEV_RATEPWR_TABLE_CMDID)) {
        return;
    }

    return;
}

/*
 * Get the rate power table in EEPROM
 */
static void
ol_ath_get_ratepwr_table(struct ieee80211com *ic)
{
    u_int16_t len;
    wmi_buf_t buf;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_pdev_ratepwr_table_cmd *cmd;

    len = sizeof(wmi_pdev_ratepwr_table_cmd);
    printk("wmi buf len = %d\n", len);
    buf = wmi_buf_alloc(scn->wmi_handle, len);
    if (!buf) {
        adf_os_print("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return;
    }
    cmd = (wmi_pdev_ratepwr_table_cmd *)wmi_buf_data(buf);

    cmd->op = RATEPWR_TABLE_OPS_GET;
    cmd->ratepwr_len = 0;
    cmd->ratepwr_tbl[0] = 0;

    if(wmi_unified_cmd_send(scn->wmi_handle, buf, len,
        WMI_PDEV_RATEPWR_TABLE_CMDID)) {
        return;
    }

    return;
}

/*
 * EEPROM rate power table operations
 */
static void
ol_ath_ratepwr_table_ops(struct ieee80211com *ic, u_int8_t ops,
                        u_int8_t *ratepwr_tbl, u_int16_t ratepwr_len)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    if (scn->target_type != TARGET_TYPE_AR9888) {
        printk("rate power table override is only supported for AR98XX\n");
        return;
    }

    if (ops == RATEPWR_TABLE_OPS_SET) {
        QC98XX_EEPROM_RATETBL eep_tbl;

        memset((u_int8_t *)&eep_tbl, 0, sizeof(QC98XX_EEPROM_RATETBL));
        /* convert user format to eeprom format */
        ol_if_ratepwr_usr_to_eeprom((u_int8_t *)&eep_tbl, sizeof(QC98XX_EEPROM_RATETBL),
                                    ratepwr_tbl, ratepwr_len);

        ol_ath_set_ratepwr_table(ic, (u_int8_t*)&eep_tbl, sizeof(QC98XX_EEPROM_RATETBL));
    } else if (ops == RATEPWR_TABLE_OPS_GET) {
        ol_ath_get_ratepwr_table(ic);
    } else
        printk("Unknown ratepwr table ops %d\n", ops);

    return;
}

/*
 * The format of the CTL table defined as below
 */
#if 0
typedef struct {
    A_UINT8  ctl_edges[WHAL_NUM_BAND_EDGES_2G];
} __packed CAL_CTL_DATA_2G;

typedef struct {
    A_UINT8  ctl_edges[WHAL_NUM_BAND_EDGES_5G];
} __packed CAL_CTL_DATA_5G;

typedef struct {
    A_UINT8                       ctlFreqbin2G[WHAL_NUM_CTLS_2G][WHAL_NUM_BAND_EDGES_2G];
    CAL_CTL_DATA_2G               ctlData2G[WHAL_NUM_CTLS_2G];
    A_UINT8                       ctlFreqbin5G[WHAL_NUM_CTLS_5G][WHAL_NUM_BAND_EDGES_5G];
    CAL_CTL_DATA_5G               ctlData5G[WHAL_NUM_CTLS_5G];
} __packed CAL_INFO;
#endif

static void
ol_ath_set_ctl_table(struct ieee80211com *ic, u_int8_t *ctl_array, u_int16_t ctl_len)
{
/* for QC98XX only */
#define WHAL_NUM_CTLS_5G                        18      //6 modes (A, HT20, HT40, VHT20, VHT40, VHT80) * 3 reg dommains
#define WHAL_NUM_CTLS_2G                        18      //6 modes (B, G, HT20, HT40, VHT20, VHT40) * 3 reg domains
#define WHAL_NUM_BAND_EDGES_5G                  8
#define WHAL_NUM_BAND_EDGES_2G                  4
    u_int16_t len;
    wmi_buf_t buf;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_pdev_set_ctl_table_cmd *cmd;

    if (!ctl_array)
        return;

    if (ctl_len != WHAL_NUM_CTLS_2G * WHAL_NUM_BAND_EDGES_2G * 2 +
                   WHAL_NUM_CTLS_5G * WHAL_NUM_BAND_EDGES_5G * 2) {
        printk("CTL array len not correct\n");
        return;
    }

    len = sizeof(wmi_pdev_set_ctl_table_cmd);
    len += roundup(ctl_len, sizeof(A_UINT32)) - sizeof(A_UINT32);  /* already 4 bytes in cmd structure */
    printk("wmi buf len = %d\n", len);
    buf = wmi_buf_alloc(scn->wmi_handle, len);
    if (!buf) {
        adf_os_print("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return;
    }
    cmd = (wmi_pdev_set_ctl_table_cmd *)wmi_buf_data(buf);

    cmd->ctl_len = ctl_len;
    OL_IF_MSG_COPY_CHAR_ARRAY(&cmd->ctl_info[0], ctl_array, ctl_len);

    if(wmi_unified_cmd_send(scn->wmi_handle, buf, len,
        WMI_PDEV_SET_CTL_TABLE_CMDID)) {
        return;
    }

    return;
#undef WHAL_NUM_CTLS_5G
#undef WHAL_NUM_CTLS_2G
#undef WHAL_NUM_BAND_EDGES_5G
#undef WHAL_NUM_BAND_EDGES_2G
}

static void
ol_ath_set_mimogain_table(struct ieee80211com *ic, u_int8_t *array_gain,
                            u_int16_t tbl_len, bool multichain_gain_bypass)
{
/* for QC98XX only */
#define WHAL_TX_NUM_CHAIN       0x3
#define WHAL_TPC_REGINDEX_MAX   4
#define WHAL_ARRAY_GAIN_NUM_STREAMS     2

    u_int16_t len;
    wmi_buf_t buf;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_pdev_set_mimogain_table_cmd *cmd;

    if (!array_gain)
        return;

    /* len must be multiple of a single array gain table */
    if (tbl_len % ((WHAL_TX_NUM_CHAIN-1) * WHAL_TPC_REGINDEX_MAX * WHAL_ARRAY_GAIN_NUM_STREAMS) != 0) {
        printk("Array gain table len not correct\n");
        return;
    }

    len = sizeof(wmi_pdev_set_mimogain_table_cmd);
    len += roundup(tbl_len, sizeof(A_UINT32)) - sizeof(A_UINT32);  /* already 4 bytes in cmd structure */
    buf = wmi_buf_alloc(scn->wmi_handle, len);
    if (!buf) {
        adf_os_print("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return;
    }
    cmd = (wmi_pdev_set_mimogain_table_cmd *)wmi_buf_data(buf);

    WMI_MIMOGAIN_ARRAY_GAIN_LEN_SET(cmd->mimogain_info, tbl_len);
    WMI_MIMOGAIN_MULTI_CHAIN_BYPASS_SET(cmd->mimogain_info, multichain_gain_bypass);
    OL_IF_MSG_COPY_CHAR_ARRAY(&cmd->arraygain_tbl[0], array_gain, tbl_len);

    if(wmi_unified_cmd_send(scn->wmi_handle, buf, len,
        WMI_PDEV_SET_MIMOGAIN_TABLE_CMDID)) {
        return;
    }

    return;
#undef WHAL_TX_NUM_CHAIN
#undef WHAL_TPC_REGINDEX_MAX
#undef WHAL_ARRAY_GAIN_NUM_STREAMS
}

/*
 * Override the rate power and chain mask used in the FW
 * @param ratepwr_chain_tbl : input ratepwr table, each element in u_int32_t format
 * @param num_rate          : 12 rates for CCK/OFDM, 48 rates for HT20/40, 90 rates for VHT rate
 * @param pream_type        : 0=CCK/OFDM, 1=HT20/40, 2=VHT rate
 * @param ops               : 0=disable, 1=enable
 */
static void
ol_ath_set_ratepwr_chainmsk(struct ieee80211com *ic, u_int32_t *ratepwr_chain_tbl,
                            u_int16_t num_rate, u_int8_t pream_type, u_int8_t ops)
{
#define RC_CCK_OFDM_RATES       0
#define RC_HT_RATES             1
#define RC_VHT_RATES            2
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    u_int16_t len;
    wmi_buf_t buf;
    wmi_pdev_ratepwr_chainmsk_tbl_cmd *cmd;

    if (!ratepwr_chain_tbl)
        return;

    if (pream_type == RC_CCK_OFDM_RATES &&
        num_rate != HT_20_RATE_TABLE_INDEX - CCK_RATE_TABLE_INDEX) {
        printk("CCK/OFDM rate num should be %d\n", HT_20_RATE_TABLE_INDEX - CCK_RATE_TABLE_INDEX);
        return;
    }

    if (pream_type == RC_HT_RATES &&
        num_rate != VHT_20_RATE_TABLE_INDEX - HT_20_RATE_TABLE_INDEX) {
        printk("HT20/40 rate num should be %d\n", VHT_20_RATE_TABLE_INDEX - HT_20_RATE_TABLE_INDEX);
        return;
    }

    if (pream_type == RC_VHT_RATES &&
        num_rate != RATE_TABLE_SIZE - VHT_20_RATE_TABLE_INDEX) {
        printk("VHT rate num should be %d\n", RATE_TABLE_SIZE - VHT_20_RATE_TABLE_INDEX);
        return;
    }

    len = sizeof(wmi_pdev_ratepwr_chainmsk_tbl_cmd);
    len += roundup(num_rate*sizeof(u_int32_t), sizeof(A_UINT32));
    buf = wmi_buf_alloc(scn->wmi_handle, len);
    if (!buf) {
        adf_os_print("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return;
    }
    cmd = (wmi_pdev_ratepwr_chainmsk_tbl_cmd *)wmi_buf_data(buf);
    cmd->op = ops;
    cmd->pream_type = pream_type;
    cmd->rate_len = num_rate;

    if(ops == RATEPWR_CHAINMSK_TABLE_OPS_EN) {
        OS_MEMCPY(&cmd->ratepwr_chaintbl[0], ratepwr_chain_tbl,
                                   num_rate*sizeof(u_int32_t));
    }

    return wmi_unified_cmd_send(scn->wmi_handle, buf, len,
                                WMI_PDEV_RATEPWR_CHAINMSK_TABLE_CMDID);
}

/* per node tpc control */
static void
ol_ath_set_node_tpc(struct ieee80211com *ic, struct ieee80211_node *ni, u_int8_t tpc)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    struct ol_ath_vap_net80211 *avn;

    avn = (ni!=NULL)? OL_ATH_VAP_NET80211(ni->ni_vap):NULL;

    if (!avn)
        return;

    if(wmi_unified_node_set_param(scn->wmi_handle, ni->ni_macaddr,
            WMI_PEER_USE_FIXED_PWR, tpc, avn->av_if_id)) {
        printk("%s:Unable to send fixed pwr\n", __func__);
    }
}

static void
ol_ath_set_rxfilter(struct ieee80211com *ic, u_int32_t filter)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    if (wmi_unified_pdev_set_param(scn->wmi_handle,
                WMI_PDEV_PARAM_RX_FILTER, filter) != EOK)
        printk("Error setting rxfilter 0x%08x\n", filter);
}

void
ol_ath_setTxPowerLimit(struct ieee80211com *ic, u_int32_t limit, u_int16_t tpcInDb, u_int32_t is2GHz)
{
    int retval = 0;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    u_int16_t cur_tx_power = ieee80211com_get_txpowerlimit(ic);

    if (cur_tx_power != limit) {
        /* Update max tx power only if the current max tx power is different */
        if (limit > scn->max_tx_power) {
                printk("Tx power value is greater than supported max tx power %d, Limiting to default Max\n",
                    scn->max_tx_power);
		limit = scn->max_tx_power;
        }
        if (is2GHz) {
            retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                WMI_PDEV_PARAM_TXPOWER_LIMIT2G, limit);
        } else {
            retval = wmi_unified_pdev_set_param(scn->wmi_handle,
                WMI_PDEV_PARAM_TXPOWER_LIMIT5G, limit);
        }
        if (retval == EOK) {
            /* Update the ic_txpowlimit */
            if (is2GHz) {
                scn->txpowlimit2G = limit;
            } else {
                scn->txpowlimit5G = limit;
            }
            if ((is2GHz && IEEE80211_IS_CHAN_2GHZ(ic->ic_curchan)) ||
                (!is2GHz && !IEEE80211_IS_CHAN_2GHZ(ic->ic_curchan)))
            {
                ieee80211com_set_txpowerlimit(ic, (u_int16_t) (limit));
            }
        }
    }
}

static u_int8_t
ol_ath_get_common_power(struct ieee80211com *ic, struct ieee80211_channel *chan)
{
    /* TBD */
    return 0;
}

static u_int32_t
ol_ath_getTSF32(struct ieee80211com *ic)
{
    /* TBD */
    return 0;
}

static int
ol_ath_getrmcounters(struct ieee80211com *ic, struct ieee80211_mib_cycle_cnts *pCnts)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    /* "ic->ic_mib_cycle_cnts" gets updated during a periodic stats event */
    pCnts->tx_frame_count = scn->mib_cycle_cnts.tx_frame_count;
    pCnts->rx_frame_count = scn->mib_cycle_cnts.rx_frame_count;
    pCnts->rx_clear_count = scn->mib_cycle_cnts.rx_clear_count;
    pCnts->cycle_count = scn->mib_cycle_cnts.cycle_count;

    /* "is_rx_active" and "is_tx_active" not being used, but for safety, set it to 0 */
    pCnts->is_rx_active = 0;
    pCnts->is_tx_active = 0;

    return 0;
}

static u_int32_t
ol_ath_wpsPushButton(struct ieee80211com *ic)
{
    /* TBD */
    return 0;
}

static void
ol_ath_clear_phystats(struct ieee80211com *ic)
{
    /* TBD */
    return;
}

static int
ol_ath_set_macaddr(struct ieee80211com *ic, u_int8_t *macaddr)
{
    u_int8_t len;
    wmi_buf_t buf;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    wmi_pdev_set_base_macaddr_cmd *cmd;
    len = sizeof(wmi_pdev_set_base_macaddr_cmd);
    buf = wmi_buf_alloc(scn->wmi_handle, len);
    if (!buf) {
        adf_os_print("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return -1;
    }
    cmd = (wmi_pdev_set_base_macaddr_cmd *)wmi_buf_data(buf);
    WMI_CHAR_ARRAY_TO_MAC_ADDR(macaddr, &cmd->base_macaddr);

    if(wmi_unified_cmd_send(scn->wmi_handle, buf, len,
        WMI_PDEV_SET_BASE_MACADDR_CMDID)) {
        return -1;
    }

    return 0;
}

static int
ol_ath_set_chain_mask(struct ieee80211com *ic, ieee80211_device_param type, u_int32_t mask)
{
    /* TBD */
    return 0;
}

static u_int32_t
ol_ath_getmfpsupport(struct ieee80211com *ic)
{
    return IEEE80211_MFP_HW_CRYPTO;
}

static void
ol_ath_setmfpQos(struct ieee80211com *ic, u_int32_t dot11w)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_unified_pdev_set_param(scn->wmi_handle,
                               WMI_PDEV_PARAM_PMF_QOS, dot11w);
    return;
}

static u_int64_t
ol_ath_get_tx_hw_retries(struct ieee80211com *ic)
{
    /* TBD */
    return 0;
}

static u_int64_t
ol_ath_get_tx_hw_success(struct ieee80211com *ic)
{
    /* TBD */
    return 0;
}

int
wmi_unified_send_peer_assoc(wmi_unified_t wmi_handle, struct ieee80211com *ic,
                            struct ieee80211_node *ni, int isnew );
/* Update peer rate table */
static void
ol_ath_rate_node_update(struct ieee80211com *ic, struct ieee80211_node *ni,
                                   int isnew)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    /* reuse the ASSOC_CMDID to perform the dynamic rate setting */
    wmi_unified_send_peer_assoc(scn->wmi_handle, ic, ni, isnew);
}


/* wrapper func for the inline function in ol_tx_desc.h */
u_int16_t
ol_ath_desc_alloc_and_mark_for_mcast_clone(struct ieee80211com *ic, u_int16_t buf_count)
{
    u_int16_t allocated, cur_alloc;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    /* TODO: Increase of high traffic scenario, there is a possiblity that alloc fails due
     * to lack of free descriptors. Need handle this by grabbing those descriptors while freeing*/
    cur_alloc = ol_tx_get_mcast_buf_allocated_marked(OL_ATH_SOFTC_NET80211(ic)->pdev_txrx_handle);
    //Wait for FW to complete previous removal before adding any new request
    if( scn->pend_desc_removal ) {
        scn->pend_desc_addition += buf_count;
        return cur_alloc;
    }

    allocated = ol_tx_desc_alloc_and_mark_for_mcast_clone(OL_ATH_SOFTC_NET80211(ic)->pdev_txrx_handle, buf_count);

    if( (cur_alloc + buf_count) < allocated ) {
        scn->pend_desc_addition += (cur_alloc + buf_count) - allocated;
    }
    if( allocated > cur_alloc ) {
        wmi_unified_pdev_set_param(scn->wmi_handle,
                WMI_PDEV_PARAM_SET_MCAST2UCAST_BUFFER, allocated);
        printk("%s: VAP Mcast to Unicast buffer allocated: %u\n", __func__, allocated);
    }

    return allocated;
}

/* wrappers func for the inline function in ol_tx_desc.h */
u_int16_t
ol_ath_desc_free_and_unmark_for_mcast_clone(struct ieee80211com *ic, u_int16_t buf_count)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    scn->pend_desc_removal += buf_count;
    return (wmi_unified_pdev_set_param(scn->wmi_handle, WMI_PDEV_PARAM_REMOVE_MCAST2UCAST_BUFFER,
                buf_count));
}

/* function to get the value from txrx structure, instead of accessing directly */
u_int16_t
ol_ath_get_mcast_buf_allocated_marked(struct ieee80211com *ic)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    return(ol_tx_get_mcast_buf_allocated_marked(OL_ATH_SOFTC_NET80211(ic)->pdev_txrx_handle) - scn->pend_desc_removal);
}

#if ATH_SUPPORT_IQUE
static void
ol_ath_mcast_group_update(
    struct ieee80211com *ic,
    int action,
    int wildcard,
    u_int8_t *mcast_ip_addr,
    int mcast_ip_addr_bytes,
    u_int8_t *ucast_mac_addr,
    u_int8_t filter_mode,
    u_int8_t nsrcs,
    u_int8_t *srcs,
    u_int8_t *mask,
    u_int8_t vap_id)
{
 struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_peer_mcast_group_cmd *cmd;
    wmi_buf_t buf;
    int len;
    int offset = 0;
	char dummymask[4] = { 0xFF, 0xFF, 0xFF, 0xFF};

    len = sizeof(wmi_peer_mcast_group_cmd);
    buf = wmi_buf_alloc(scn->wmi_handle, len);
    if (!buf) {
        printk("%s: wmi_buf_alloc failed\n", __FUNCTION__);
        return;
    }
    cmd = (wmi_peer_mcast_group_cmd *) wmi_buf_data(buf);
    /* confirm the buffer is 4-byte aligned */
    ASSERT((((size_t) cmd) & 0x3) == 0);
	OS_MEMZERO(cmd,sizeof(wmi_peer_mcast_group_cmd));

    /* construct the message assuming our endianness matches the target */
    cmd->flags |= WMI_PEER_MCAST_GROUP_FLAG_ACTION_M &
        (action << WMI_PEER_MCAST_GROUP_FLAG_ACTION_S);
    cmd->flags |= WMI_PEER_MCAST_GROUP_FLAG_WILDCARD_M &
        (wildcard << WMI_PEER_MCAST_GROUP_FLAG_WILDCARD_S);
	if(action == IGMP_ACTION_DELETE_MEMBER && wildcard && !mcast_ip_addr)  {
		cmd->flags |= WMI_PEER_MCAST_GROUP_FLAG_DELETEALL_M;
	}

    if(mcast_ip_addr_bytes != IGMP_IP_ADDR_LENGTH)
		cmd->flags |=  WMI_PEER_MCAST_GROUP_FLAG_IPV6_M;
	if(filter_mode != IGMP_SNOOP_CMD_ADD_INC_LIST)
			cmd->flags |=WMI_PEER_MCAST_GROUP_FLAG_SRC_FILTER_EXCLUDE_M;

    /* unicast address spec only applies for non-wildcard cases */
    if (!wildcard && ucast_mac_addr) {
        OS_MEMCPY(
            &cmd->ucast_mac_addr,
            ucast_mac_addr,
            sizeof(cmd->ucast_mac_addr));
    }
	if(mcast_ip_addr) {
	    ASSERT(mcast_ip_addr_bytes <= sizeof(cmd->mcast_ip_addr));
	   	offset = sizeof(cmd->mcast_ip_addr) - mcast_ip_addr_bytes;
	    OS_MEMCPY(((u_int8_t *) &cmd->mcast_ip_addr) + offset,
	        mcast_ip_addr,
        	mcast_ip_addr_bytes);
	}

	if(!mask){
		mask= &dummymask[0];
    }
	OS_MEMCPY( ((u_int8_t *) &cmd->mcast_ip_mask) + offset, mask, mcast_ip_addr_bytes);

	if(srcs && nsrcs) {
	    cmd->num_filter_addr = nsrcs;
    	ASSERT((nsrcs * mcast_ip_addr_bytes) <= sizeof(cmd->srcs));

		OS_MEMCPY(((u_int8_t *) &cmd->filter_addr),srcs,nsrcs * mcast_ip_addr_bytes);
	}
		/* now correct for endianness, if necessary */
	/*
	 * For Little Endian, N/w Stack gives packets in Network byte order and issue occurs
         * if both Host and Target happens to be in Little Endian. Target when compares IP
         * addresses in packet with MCAST_GROUP_CMDID given IP addresses, it fails. Hence
         * swap only mcast_ip_addr ( 16 bytes ) for now.
	 * TODO : filter
         */
#ifdef BIG_ENDIAN_HOST
	ol_bytestream_endian_fix(
		(u_int32_t *)&cmd->ucast_mac_addr, (sizeof(*cmd)-4) / sizeof(u_int32_t));
#else
	ol_bytestream_endian_fix(
		(u_int32_t *)&cmd->mcast_ip_addr, (sizeof(cmd->mcast_ip_addr)) / sizeof(u_int32_t));
#endif /* Little Endian */
    wmi_unified_cmd_send(
        scn->wmi_handle, buf, len, WMI_PEER_MCAST_GROUP_CMDID);
}
#endif

	static int
wmi_unified_debug_print_event_handler (ol_scn_t scn, u_int8_t *data, u_int16_t datalen, void *context)
{
#ifdef BIG_ENDIAN_HOST
	char dbgbuf[500] = {0};
	memcpy(dbgbuf, data, datalen);
	SWAPME(dbgbuf, datalen);
	printk("FIRMWARE:%s \n",dbgbuf);
	return 0;
#else
	printk("FIRMWARE:%s \n",data);
	return 0;
#endif
}

static void
ol_ath_set_config(struct ieee80211vap* vap)
{
    /* Currently Not used for Offload */
}

static void
ol_ath_set_safemode(struct ieee80211vap* vap, int val)
{
    ol_txrx_vdev_handle vdev = (ol_txrx_vdev_handle) vap->iv_txrx_handle;
    if (vdev) {
        ol_txrx_set_safemode(vdev, val);
    }
    return;
}

static void
ol_ath_set_privacy_filters(struct ieee80211vap* vap)
{
    ol_txrx_vdev_handle vdev = (ol_txrx_vdev_handle) vap->iv_txrx_handle;
    if (vdev) {
        ol_txrx_set_privacy_filters(vdev, vap->iv_privacy_filters, vap->iv_num_privacy_filters);
    }
    return;
}

static void
ol_ath_set_drop_unenc(struct ieee80211vap* vap, int val)
{
    ol_txrx_vdev_handle vdev = (ol_txrx_vdev_handle) vap->iv_txrx_handle;
    if (vdev) {
        ol_txrx_set_drop_unenc(vdev, val);
    }
    return;
}
#undef DEPRECATED
static void
ol_ath_scan_start(struct ieee80211com *ic)
{
#ifdef DEPRECATED
    /*
     * this command was added to support host scan egine which is deprecated.
     * now  the scan engine is in FW and host directly isssues a scan request
     * to perform scan and provide results back to host
     */
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_buf_t buf;
    wmi_pdev_scan_cmd *cmd;
    int len = sizeof(wmi_pdev_scan_cmd);
    buf = wmi_buf_alloc(scn->wmi_handle, len);
    printk("%s:\n", __FUNCTION__);
    if (!buf) {
        printk("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return ;
    }
    cmd = (wmi_pdev_scan_cmd *)wmi_buf_data(buf);
    cmd->scan_start = TRUE;
    wmi_unified_cmd_send(scn->wmi_handle, buf, len, WMI_PDEV_SCAN_CMDID);
#endif
}

static void
ol_ath_scan_end(struct ieee80211com *ic)
{
#ifdef DEPRECATED
    /*
     * this command was added to support host scan egine which is deprecated.
     * now  the scan engine is in FW and host directly isssues a scan request
     * to perform scan and provide results back to host
     */
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_pdev_scan_cmd *cmd;
    wmi_buf_t buf;
    int len = sizeof(wmi_pdev_scan_cmd);
    buf = wmi_buf_alloc(scn->wmi_handle, len);
    printk("%s:\n", __FUNCTION__);
    if (!buf) {
        printk("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return ;
    }
    cmd = (wmi_pdev_scan_cmd *)wmi_buf_data(buf);
    cmd->scan_start = FALSE;
    wmi_unified_cmd_send(scn->wmi_handle, buf, len, WMI_PDEV_SCAN_CMDID);
#endif
}

#if ATH_SUPPORT_IQUE
void
ol_ath_set_acparams(struct ieee80211com *ic, u_int8_t ac, u_int8_t use_rts,
                          u_int8_t aggrsize_scaling, u_int32_t min_kbps)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    wmi_pdev_set_param_cmd *cmd;
    wmi_buf_t buf;
    u_int32_t param_value = 0;
    int len = sizeof(wmi_pdev_set_param_cmd);

    buf = wmi_buf_alloc(scn->wmi_handle, len);
    if (!buf) {
        printk("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return;
    }

    cmd = (wmi_pdev_set_param_cmd *)wmi_buf_data(buf);
    cmd->param_id = WMI_PDEV_PARAM_AC_AGGRSIZE_SCALING;
    param_value = ac;
    param_value |= (aggrsize_scaling << 8);
    cmd->param_value = param_value;

    wmi_unified_cmd_send(scn->wmi_handle, buf, len, WMI_PDEV_SET_PARAM_CMDID);
    return;
}

void
ol_ath_set_rtparams(struct ieee80211com *ic, u_int8_t ac, u_int8_t perThresh,
                          u_int8_t probeInterval)
{
    /* TBD */
    return;
}

void
ol_ath_get_iqueconfig(struct ieee80211com *ic)
{
    /* TBD */
    return;
}

void
ol_ath_set_hbrparams(struct ieee80211vap *iv, u_int8_t ac, u_int8_t enable, u_int8_t per)
{
    /* TBD */
    return;
}
#endif /*ATH_SUPPORT_IQUE*/

/*
 * Disable the dcs im when the intereference is detected too many times. for
 * thresholds check umac
 */
static void
ol_ath_disable_dcsim(struct ieee80211com *ic)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    if (!ic->ic_nl_handle) {
        printk("DCS: %s dcs state %x \n",__func__,scn->scn_dcs.dcs_enable);
    }

    /* clear the run state, only when cwim is not set */
    if (!(OL_IS_DCS_ENABLED(scn->scn_dcs.dcs_enable) & ATH_CAP_DCS_CWIM)) {
        OL_ATH_DCS_CLR_RUNSTATE(scn->scn_dcs.dcs_enable);
    }

    OL_ATH_DCS_DISABLE(scn->scn_dcs.dcs_enable, ATH_CAP_DCS_WLANIM);

    /* send target to disable and then disable in host */
    wmi_unified_pdev_set_param(scn->wmi_handle, WMI_PDEV_PARAM_DCS, scn->scn_dcs.dcs_enable);

}
#ifdef ATH_SUPPORT_TxBF
#ifdef TXBF_TODO
static void
ol_ath_net80211_get_pos2_data(struct ieee80211com *ic, u_int8_t **p_data,
    u_int16_t* p_len,void **rx_status)
{
    /* TBD */
    return;
}

static bool
ol_ath_net80211_txbfrcupdate(struct ieee80211com *ic,void *rx_status,u_int8_t *local_h,
    u_int8_t *CSIFrame, u_int8_t NESSA, u_int8_t NESSB, int BW)
{
    /* TBD */
    return 1;
}

static void
ol_ath_net80211_ap_save_join_mac(struct ieee80211com *ic, u_int8_t *join_macaddr)
{
	struct ath_softc_net80211 *scn = ATH_SOFTC_NET80211(ic);

	scn->sc_ops->ap_save_join_mac(scn->sc_dev, join_macaddr);
}

static void
ol_ath_net80211_start_imbf_cal(struct ieee80211com *ic)
{
    return;
}
#endif

static int
ol_ath_net80211_txbf_alloc_key(struct ieee80211com *ic, struct ieee80211_node *ni)
{
    return 0;
}

static void
ol_ath_net80211_txbf_set_key(struct ieee80211com *ic, struct ieee80211_node *ni)
{
    return;
}

static void
ol_ath_net80211_init_sw_cv_timeout(struct ieee80211com *ic, struct ieee80211_node *ni)
{
    return;
}

static int
ol_ath_set_txbfcapability(struct ieee80211com *ic)
{
    return 0;
}

#ifdef TXBF_DEBUG
static void
ol_ath_net80211_txbf_check_cvcache(struct ieee80211com *ic, struct ieee80211_node *ni)
{
    return 0;
}
#endif

static void
ol_ath_net80211_CSI_Frame_send(struct ieee80211_node *ni,
						u_int8_t	*CSI_buf,
                        u_int16_t	buf_len,
						u_int8_t    *mimo_control)
{
    return;
}

static void
ol_ath_net80211_v_cv_send(struct ieee80211_node *ni,
                       u_int8_t *data_buf,
                       u_int16_t buf_len)
{
    return;
}
static void
ol_ath_net80211_txbf_stats_rpt_inc(struct ieee80211com *ic,
                                struct ieee80211_node *ni)
{
    return;
}
static void
ol_ath_net80211_txbf_set_rpt_received(struct ieee80211com *ic,
                                struct ieee80211_node *ni)
{
    return;
}
#endif

static bool
ol_ath_net80211_is_mode_offload(struct ieee80211com *ic)
{
    /*
     * If this function executes, it is offload mode
     */
    return TRUE;
}

static bool
ol_ath_net80211_is_macreq_enabled(struct ieee80211com *ic)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    return ((scn->macreq_enabled == 1) ? TRUE : FALSE);
}

static u_int32_t
ol_ath_net80211_get_mac_prealloc_idmask(struct ieee80211com *ic)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    return scn->sc_prealloc_idmask;
}

/*
 * Register the DCS functionality
 * As such this is very small function and is not going to contain too many
 * functions, right now continuing in the same file. Once it grows bigger,
 * move to different file.
 *
 *  # register event handler to receive non-wireless lan interference event
 *  # register event handler to receive the extended stats that are meant for
 *    receiving the timed extra stats
 *        - right now this is not implemented and would implement
 *          as we go with second implementation
 *  # initialize the initial enabled state
 *  # initialize the host data strucutres that are meant for handling
 *    the wireless lan interference.
 *          - right now these variables would not be used
 *  # Keep the initialized state as disabled, and enable
 *    when first channel gets activated.
 *  # Keep the status as disabled until completely qualified
 */
void
ol_ath_dcs_attach(struct ieee80211com *ic)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    /* Register WMI event handlers */
	scn->scn_dcs.dcs_enable                 = 0;
    OL_ATH_DCS_CLR_RUNSTATE(scn->scn_dcs.dcs_enable);
	scn->scn_dcs.phy_err_penalty            = DCS_PHYERR_PENALTY;
	scn->scn_dcs.phy_err_threshold          = DCS_PHYERR_THRESHOLD ;
	scn->scn_dcs.radar_err_threshold        = DCS_RADARERR_THRESHOLD;
	scn->scn_dcs.coch_intr_thresh           = DCS_COCH_INTR_THRESHOLD ;
	scn->scn_dcs.user_max_cu                = DCS_USER_MAX_CU; /* tx_cu + rx_cu */
	scn->scn_dcs.intr_detection_threshold   = DCS_INTR_DETECTION_THR;
	scn->scn_dcs.intr_detection_window      = DCS_SAMPLE_SIZE;
	scn->scn_dcs.scn_dcs_im_stats.im_intr_cnt = 0;
	scn->scn_dcs.scn_dcs_im_stats.im_samp_cnt = 0;
    scn->scn_dcs.dcs_debug                  = DCS_DEBUG_DISABLE;

    wmi_unified_register_event_handler(scn->wmi_handle, WMI_DCS_INTERFERENCE_EVENTID,
                                            wmi_unified_dcs_interference_handler, NULL);
    return;
}

#if ATH_OL_FAST_CHANNEL_RESET_WAR
#define DISABLE_FAST_CHANNEL_RESET 1
     /*WAR for EV#117307, MSDU_DONE is not set for data packet,
      to fix this issue, fast channel change is disabled for x86 platform*/
void ol_ath_fast_chan_change(struct ol_ath_softc_net80211 *scn)
{
    printk("Disabling fast channel reset \n");
    if(wmi_unified_pdev_set_param(scn->wmi_handle,
                       WMI_PDEV_PARAM_FAST_CHANNEL_RESET,
                       DISABLE_FAST_CHANNEL_RESET)) {
        printk(" Failed to disable fast channel reset \n");
    }
}
#endif

/* The below mapping is according the doc, which is as follows,

DSCP        TID     AC
000000      0       WME_AC_BE
001000      1       WME_AC_BK
010000      1       WME_AC_BK
011000      0       WME_AC_BE
100000      5       WME_AC_VI
101000      5       WME_AC_VI
110000      6       WME_AC_VO
111000      6       WME_AC_VO

*/
	A_UINT32 dscp_tid_map[WMI_DSCP_MAP_MAX] = {
			0, 0, 0, 0, 0, 0, 0, 0,
			1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1,
			0, 0, 0, 0, 0, 0, 0, 0,
			5, 5, 5, 5, 5, 5, 5, 5,
			5, 5, 5, 5, 5, 5, 5, 5,
			6, 6, 6, 6, 6, 6, 6, 6,
			6, 6, 6, 6, 6, 6, 6, 6,
	};

int
ol_ath_set_vap_dscp_tid_map(struct ieee80211vap *vap)
{
    struct ieee80211com *ic = vap->iv_ic;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);
    struct ol_ath_vap_net80211 *avn = OL_ATH_VAP_NET80211(vap);
    wmi_buf_t buf;
    wmi_vdev_set_dscp_tid_map_cmd *cmd;
    int len = sizeof(wmi_vdev_set_dscp_tid_map_cmd);
    buf = wmi_buf_alloc(scn->wmi_handle, len);
    if (!buf) {
        printk("%s:wmi_buf_alloc failed\n", __FUNCTION__);
        return -1;
    }

    cmd = (wmi_vdev_set_dscp_tid_map_cmd *)wmi_buf_data(buf);

#if ATH_SUPPORT_DSCP_OVERRIDE
    if(vap->iv_override_dscp) {
        /* Send updated copy of the TID-Map */
        OS_MEMCPY(cmd->dscp_to_tid_map, vap->iv_dscp_tid_map, sizeof(A_UINT32) * WMI_DSCP_MAP_MAX);
    }
    else if (ic->ic_override_dscp) {
        OS_MEMCPY(cmd->dscp_to_tid_map, ic->ic_dscp_tid_map, sizeof(A_UINT32) * WMI_DSCP_MAP_MAX);
    }
    else {
#endif
        OS_MEMCPY(cmd->dscp_to_tid_map, dscp_tid_map, sizeof(A_UINT32) * WMI_DSCP_MAP_MAX);
#if ATH_SUPPORT_DSCP_OVERRIDE
}
#endif
    cmd->vdev_id = avn->av_if_id;

    printk("Setting dscp for vap id: %d\n", cmd->vdev_id);
    return wmi_unified_cmd_send(scn->wmi_handle, buf, len, WMI_VDEV_SET_DSCP_TID_MAP_CMDID);
}

#if ATH_SUPPORT_DSCP_OVERRIDE
u_int32_t
ol_ath_get_dscp_tid_map(struct ieee80211com *ic, u_int8_t tos)
{
    return ic->ic_dscp_tid_map[(tos >> IP_DSCP_SHIFT) & IP_DSCP_MASK];
}

void
ol_ath_set_dscp_override(struct ieee80211com *ic , u_int32_t val)
{
    struct ieee80211vap *vap;

    ic->ic_override_dscp = !!val;

    /* Update the TID-MAP table at Firmware */
    TAILQ_FOREACH(vap, &ic->ic_vaps, iv_next) {
	if(!vap->iv_override_dscp) {
            ol_ath_set_vap_dscp_tid_map(vap);
        }
    }

    return;
}

u_int32_t
ol_ath_get_dscp_override(struct ieee80211com *ic)
{
    return ic->ic_override_dscp;
}

void
ol_ath_set_hmmc_tid(struct ieee80211com *ic , u_int32_t tid)
{
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(ic);

    /* If Override is disabled: send default TID  else passed the intended tid value */
    if(!ic->ic_override_hmmc_dscp) {
        tid = 0xFF;                 //TBD::Replace it with proper macro
    }
    wmi_unified_pdev_set_param(scn->wmi_handle, WMI_PDEV_SET_MCAST_TO_UCAST_TID, tid);
    ic->ic_dscp_hmmc_tid = tid;

    return;
}

u_int32_t
ol_ath_get_hmmc_tid(struct ieee80211com *ic)
{
    return ic->ic_dscp_hmmc_tid;
}

void
ol_ath_set_hmmc_dscp_override(struct ieee80211com *ic , u_int32_t val)
{
    /* If nothing to do just return */
    if(ic->ic_override_hmmc_dscp == val) {
	return;
    }
    ic->ic_override_hmmc_dscp = !!val;

    /* Inform target as well */
    ol_ath_set_hmmc_tid(ic, ic->ic_dscp_hmmc_tid);
    return;
}

u_int32_t
ol_ath_get_hmmc_dscp_override(struct ieee80211com *ic)
{
    return ic->ic_override_hmmc_dscp;
}
#endif

#if ATH_SUPPORT_HYFI_ENHANCEMENTS
static void ol_ieee80211_me_hifitbl_update_target(wlan_if_t vap)
{
    int i, j;
    int group_count = 0, node_count = 0;
    int action = IGMP_ACTION_ADD_MEMBER;
    int wildcard = IGMP_WILDCARD_SINGLE;
    struct ol_ath_softc_net80211 *scn = OL_ATH_SOFTC_NET80211(vap->iv_ic);
    struct ieee80211_me_hifi_table *ht = &vap->iv_me->me_hifi_table;
    struct ieee80211_me_hifi_node *node;
    char *grpaddr;
    int grpaddrlen;

    group_count = vap->iv_me->me_hifi_table.entry_cnt;

    if( group_count != 0)
    {
        vap->iv_ic->ic_mcast_group_update(vap->iv_ic, IGMP_ACTION_DELETE_MEMBER, IGMP_WILDCARD_ALL, NULL, 0, NULL, 0, 0, NULL, NULL, vap->iv_unit);
        if(group_count > scn->wlan_resource_config.num_mcast_groups)
            group_count = scn->wlan_resource_config.num_mcast_groups;

        for(i = 0; i < group_count ; i++) {
            node_count = ht->entry[i].node_cnt;

            if(node_count > scn->wlan_resource_config.num_mcast_table_elems)
                node_count = scn->wlan_resource_config.num_mcast_table_elems;

            grpaddr = (int8_t *)(&ht->entry[i].group.u);
            grpaddrlen = (ht->entry[i].group.pro == ETHERTYPE_IP) ? IGMP_IP_ADDR_LENGTH : 16;
            for(j=0; j< node_count; j++){
                node = &ht->entry[i].nodes[j];
                vap->iv_ic->ic_mcast_group_update(vap->iv_ic, action, wildcard,
                        grpaddr, grpaddrlen, node->mac, node->filter_mode, node->nsrcs, node->srcs, NULL, vap->iv_unit);
            }
        }
    } else {
        vap->iv_ic->ic_mcast_group_update(vap->iv_ic, IGMP_ACTION_DELETE_MEMBER, IGMP_WILDCARD_ALL, NULL, 0, NULL, 0, 0, NULL, NULL, vap->iv_unit);
    }
}
#endif
int
ol_ath_dev_attach(struct ol_ath_softc_net80211 *scn,
                   IEEE80211_REG_PARAMETERS *ieee80211_conf_parm)
{
    struct ieee80211com *ic = &scn->sc_ic;
    int error = 0;

    spin_lock_init(&ic->ic_lock);
    spin_lock_init(&ic->ic_addba_lock);
    IEEE80211_STATE_LOCK_INIT(ic);


    /* attach channel width management */
    error = ol_ath_cwm_attach(scn);
    if (error) {
        printk("%s : ol_ath_cwm_attach failed \n", __func__);
        return error;
    }

    /* XXX not right but it's not used anywhere important */
    ieee80211com_set_phytype(ic, IEEE80211_T_OFDM);

    /*
     * Set the Atheros Advanced Capabilities from station config before
     * starting 802.11 state machine.
     */
     /* TBD */

    /* this matches the FW default value */
    scn->arp_override = WME_AC_VO;
    scn->igmpmld_override = 0;
    scn->igmpmld_tid = 0;

    /* Set the mac address */

    /* Setup Min frame size */
    ic->ic_minframesize = sizeof(struct ieee80211_frame_min);

    ic->id_mask_vap_downed = 0;

    /*
     * Setup some device specific ieee80211com methods
     */
    ic->ic_init = ol_ath_init;
    ic->ic_reset_start = ol_ath_reset_start;
    ic->ic_reset = ol_ath_reset;
    ic->ic_reset_end = ol_ath_reset_end;
    ic->ic_updateslot = ol_ath_updateslot;
    ic->ic_wme.wme_update = ol_ath_wmm_update;
    ic->ic_txq_depth = ol_ath_txq_depth;
    ic->ic_txq_depth_ac = ol_ath_txq_depth_ac;
    ic->ic_update_protmode = ol_ath_update_protmode;
    ic->ic_chwidth_change = ol_net80211_chwidth_change;
    ic->ic_nss_change = ol_net80211_nss_change;
    ic->ic_start_csa = ieee80211_start_csa;
    ic->ic_set_beacon_interval = ol_set_beacon_interval;

    /* dummy scan start/end commands */
    ic->ic_scan_start = ol_ath_scan_start;
    ic->ic_scan_end = ol_ath_scan_end;
#if ATH_SUPPORT_VOW_DCS
	/* host side umac compiles with this flag, so we have no
	   option than writing this with flag, otherwise the other
	   drivers in oher OSes would fail*/
    ic->ic_disable_dcsim = ol_ath_disable_dcsim;
#endif


    /* Attach resmgr module */
    ol_ath_resmgr_attach(ic);

    /* attach scan module */
#if UMAC_SCAN_OFFLOAD
    ol_ath_scan_attach(ic);
#else
    ieee80211_scan_class_attach(ic);
#endif

    ol_ath_power_attach(ic);

    /*
     * Attach ieee80211com object to net80211 protocal stack.
     */
    error = ieee80211_ifattach(ic, ieee80211_conf_parm);
    if (error)
	return error;

     /*
     * Complete device specific ieee80211com methods init
     */
    ic->ic_set_channel = ol_ath_set_channel;
    ic->ic_enable_radar = ol_ath_net80211_enable_radar;
    ic->ic_pwrsave_set_state = ol_ath_pwrsave_set_state;
    ic->ic_mhz2ieee = ol_ath_mhz2ieee;
    ic->ic_get_noisefloor = ol_ath_get_noisefloor;
    ic->ic_get_chainnoisefloor = ol_ath_get_chainnoisefloor;
    ic->ic_set_txPowerLimit = ol_ath_setTxPowerLimit;
    ic->ic_get_common_power = ol_ath_get_common_power;
    ic->ic_get_TSF32        = ol_ath_getTSF32;
    ic->ic_rmgetcounters = ol_ath_getrmcounters;
    ic->ic_get_wpsPushButton = ol_ath_wpsPushButton;
    ic->ic_clear_phystats = ol_ath_clear_phystats;
    ic->ic_set_macaddr = ol_ath_set_macaddr;
    ic->ic_log_text = ol_ath_log_text;
    ic->ic_set_chain_mask = ol_ath_set_chain_mask;
    ic->ic_get_mfpsupport = ol_ath_getmfpsupport;
    ic->ic_set_hwmfpQos   = ol_ath_setmfpQos;
    ic->ic_get_tx_hw_retries  = ol_ath_get_tx_hw_retries;
    ic->ic_get_tx_hw_success  = ol_ath_get_tx_hw_success;
    ic->ic_rate_node_update = ol_ath_rate_node_update;
#if ATH_SUPPORT_IQUE
    ic->ic_set_acparams = ol_ath_set_acparams;
    ic->ic_set_rtparams = ol_ath_set_rtparams;
    ic->ic_get_iqueconfig = ol_ath_get_iqueconfig;
    ic->ic_set_hbrparams = ol_ath_set_hbrparams;
#endif
    ic->ic_set_config = ol_ath_set_config;
    ic->ic_set_safemode = ol_ath_set_safemode;
    ic->ic_set_dropunenc = ol_ath_set_drop_unenc;
    ic->ic_set_privacy_filters = ol_ath_set_privacy_filters;

#ifdef ATH_SUPPORT_TxBF // For TxBF RC
#ifdef TXBF_TODO
    ic->ic_get_pos2_data = ol_ath_net80211_get_pos2_data;
    ic->ic_txbfrcupdate = ol_ath_net80211_txbfrcupdate;
    ic->ic_ieee80211_send_cal_qos_nulldata = ieee80211_send_cal_qos_nulldata;
    ic->ic_ap_save_join_mac = ol_ath_net80211_ap_save_join_mac;
    ic->ic_start_imbf_cal = ol_ath_net80211_start_imbf_cal;
    ic->ic_csi_report_send = ol_ath_net80211_CSI_Frame_send;
#endif

#ifdef IEEE80211_DEBUG_REFCNT
    ic->ic_ieee80211_find_node_debug = ieee80211_find_node_debug;
#else
    ic->ic_ieee80211_find_node = ieee80211_find_node;
#endif //IEEE80211_DEBUG_REFCNT
    ic->ic_v_cv_send = ol_ath_net80211_v_cv_send;
    ic->ic_txbf_alloc_key = ol_ath_net80211_txbf_alloc_key;
    ic->ic_txbf_set_key = ol_ath_net80211_txbf_set_key;
    ic->ic_init_sw_cv_timeout = ol_ath_net80211_init_sw_cv_timeout;
    ic->ic_set_txbf_caps = ol_ath_set_txbfcapability;
#ifdef TXBF_DEBUG
	ic->ic_txbf_check_cvcache = ol_ath_net80211_txbf_check_cvcache;
#endif
    ic->ic_txbf_stats_rpt_inc = ol_ath_net80211_txbf_stats_rpt_inc;
    ic->ic_txbf_set_rpt_received = ol_ath_net80211_txbf_set_rpt_received;
#endif
#if ATH_SUPPORT_IQUE
    ic->ic_mcast_group_update = ol_ath_mcast_group_update;
#endif
    ic->ic_desc_alloc_and_mark_for_mcast_clone = ol_ath_desc_alloc_and_mark_for_mcast_clone;
    ic->ic_desc_free_and_unmark_for_mcast_clone = ol_ath_desc_free_and_unmark_for_mcast_clone;
    ic->ic_get_mcast_buf_allocated_marked = ol_ath_get_mcast_buf_allocated_marked;
#if ATH_SUPPORT_HYFI_ENHANCEMENTS
	ic->ic_hifitbl_update_target = ol_ieee80211_me_hifitbl_update_target;
#endif
    ic->ic_get_cur_chan_nf = ol_ath_net80211_get_cur_chan_noisefloor;
    ic->ic_set_rxfilter = ol_ath_set_rxfilter;
    ic->ic_set_ctl_table = ol_ath_set_ctl_table;
    ic->ic_set_mimogain_table = ol_ath_set_mimogain_table;
    ic->ic_ratepwr_table_ops = ol_ath_ratepwr_table_ops;
    ic->ic_set_ratepwr_chainmsk = ol_ath_set_ratepwr_chainmsk;
    ic->ic_set_node_tpc = ol_ath_set_node_tpc;
#if ATH_BAND_STEERING
    ic->ic_bs_enable = ol_ath_bs_enable;
    ic->ic_bs_set_overload = ol_ath_bs_set_overload;
    ic->ic_bs_set_params = ol_ath_bs_set_params;
#endif

    ol_ath_nl_attach(ic);

    /*
     * pktlog scn initialization
     */
#ifndef REMOVE_PKT_LOG
    ol_pktlog_attach(scn);
#endif

#if QCA_AIRTIME_FAIRNESS
  spin_lock_init(&ic->atf_lock);
#endif

#if ATH_SUPPORT_SPECTRAL
    if (ol_if_spectral_setup(ic) == 0) {
        printk("SPECTRAL : Not supported\n");
    }
#endif

#if ATH_SUPPORT_GREEN_AP
    if (ol_if_green_ap_attach(ic) == 0) {
        printk("GREEN-AP : Not supported\n");
    }
#endif  /* ATH_SUPPORT_GREEN_AP */

    ol_if_eeprom_attach(ic);

    ol_ath_wow_attach(ic);
    ol_ath_stats_attach(ic);
#if UNIFIED_SMARTANTENNA
    ol_ath_smart_ant_attach(ic);
#endif

#if ATH_OL_FAST_CHANNEL_RESET_WAR
    ol_ath_fast_chan_change(scn);
#endif

    return EOK;
}

int
ol_asf_adf_attach(struct ol_ath_softc_net80211 *scn)
{
    static int first = 1;
    osdev_t osdev = scn->sc_osdev;

    /*
     * Configure the shared asf_amem and asf_print instances with ADF
     * function pointers for mem alloc/free, lock/unlock, and print.
     * (Do this initialization just once.)
     */
    if (first) {
        static adf_os_spinlock_t asf_amem_lock;
        static adf_os_spinlock_t asf_print_lock;

        first = 0;

        adf_os_spinlock_init(&asf_amem_lock);
        asf_amem_setup(
            (asf_amem_alloc_fp) adf_os_mem_alloc_outline,
            (asf_amem_free_fp) adf_os_mem_free_outline,
            (void *) osdev,
            (asf_amem_lock_fp) adf_os_spin_lock_bh_outline,
            (asf_amem_unlock_fp) adf_os_spin_unlock_bh_outline,
            (void *) &asf_amem_lock);
        adf_os_spinlock_init(&asf_print_lock);
        asf_print_setup(
            (asf_vprint_fp) adf_os_vprint,
            (asf_print_lock_fp) adf_os_spin_lock_bh_outline,
            (asf_print_unlock_fp) adf_os_spin_unlock_bh_outline,
            (void *) &asf_print_lock);
    }

    /*
     * Also allocate our own dedicated asf_amem instance.
     * For now, this dedicated amem instance will be used by the
     * HAL's ath_hal_malloc.
     * Later this dedicated amem instance will be used throughout
     * the driver, rather than using the shared asf_amem instance.
     *
     * The platform-specific code that calls this ath_attach function
     * may have already set up an amem instance, if it had to do
     * memory allocation before calling ath_attach.  So, check if
     * scn->amem.handle is initialized already - if not, set it up here.
     */
    if (!scn->amem.handle) {
        adf_os_spinlock_init(&scn->amem.lock);
        scn->amem.handle = asf_amem_create(
            NULL, /* name */
            0,  /* no limit on allocations */
            (asf_amem_alloc_fp) adf_os_mem_alloc_outline,
            (asf_amem_free_fp) adf_os_mem_free_outline,
            (void *) osdev,
            (asf_amem_lock_fp) adf_os_spin_lock_bh_outline,
            (asf_amem_unlock_fp) adf_os_spin_unlock_bh_outline,
            (void *) &scn->amem.lock,
            NULL /* use adf_os_mem_alloc + osdev to alloc this amem object */);
        if (!scn->amem.handle) {
            adf_os_spinlock_destroy(&scn->amem.lock);
            return -ENOMEM;
        }
    }

    return EOK;
}

int
ol_ath_attach(u_int16_t devid, struct ol_ath_softc_net80211 *scn,
              IEEE80211_REG_PARAMETERS *ieee80211_conf_parm,
              ol_ath_update_fw_config_cb cfg_cb)
{
    struct ieee80211com     *ic = &scn->sc_ic;
    HTC_INIT_INFO  htcInfo;
    int status = 0,dev_disabled = 0;
    osdev_t osdev = scn->sc_osdev;
#ifdef AH_CAL_IN_FLASH_PCI
    u_int32_t cal_location;
#endif

#if ATH_SUPPORT_DSCP_OVERRIDE
	/* Initializing tid-map parameters to default vaules. */
	OS_MEMCPY(ic->ic_dscp_tid_map,dscp_tid_map, sizeof(A_UINT32) * WMI_DSCP_MAP_MAX);
	ic->ic_override_dscp = 0x00;
	ic->ic_dscp_hmmc_tid = 0x00;
	ic->ic_override_hmmc_dscp = 0x00;
#endif

    adf_os_spinlock_init(&scn->scn_lock);

    scn->cfg_cb = cfg_cb;
    /* initialize default target config */
    ol_ath_set_default_tgt_config(scn);

#ifdef AH_CAL_IN_FLASH_PCI
#define HOST_CALDATA_SIZE (16 * 1024)
    scn->cal_in_flash = 1;
    cal_location = CalAddr[pci_dev_cnt-1];
#ifndef ATH_CAL_NAND_FLASH
    scn->cal_mem = A_IOREMAP(cal_location, HOST_CALDATA_SIZE);
    if (!scn->cal_mem) {
        printk("%s: A_IOREMAP failed\n", __func__);
        return -1;
    }
#endif
#endif
#ifdef ATH_CAL_FROM_FILE_11AC_PCIE
	scn->cal_in_flash = 1;
#endif
#if ATH_DEBUG
    scn->rtsctsenable = 0;
#endif
    /*
     * 1. Initialize BMI
     */
    BMIInit(scn);
    printk("%s() BMI inited.\n", __func__);

    if (!scn->is_sim) {
        unsigned int bmi_user_agent;
        struct bmi_target_info targ_info;

        /*
         * 2. Get target information
         */
        OS_MEMZERO(&targ_info, sizeof(targ_info));
        if (BMIGetTargetInfo(scn->hif_hdl, &targ_info, scn) != A_OK) {
            status = -1;
            goto attach_failed;
        }
        printk("%s() BMI Get Target Info.\n", __func__);

        scn->target_type = targ_info.target_type;
        scn->target_version = targ_info.target_ver;
        printk("%s() TARGET TYPE: %d Vers 0x%x\n", __func__, scn->target_type, scn->target_version);
        ol_ath_host_config_update(scn);

        bmi_user_agent = ol_ath_bmi_user_agent_init(scn);
        if (bmi_user_agent) {
            /* User agent handles BMI phase */
            int rv;

            rv = ol_ath_wait_for_bmi_user_agent(scn);
            if (rv) {
                status = -1;
                goto attach_failed;
            }
        } else {
            /* Driver handles BMI phase */

            /*
             * 3. Configure target
             */
            if (ol_ath_configure_target(scn) != EOK) {
                status = -1;
                goto attach_failed;
            }
            printk("%s() configure Target .\n", __func__);

            /*
             * 4. Download firmware image and data files
             */
            if (ol_ath_download_firmware(scn) != EOK)
            {
                status = -EIO;
                goto attach_failed;
            }
            printk("%s() Download FW. \n", __func__);
        }
    }

    /*
     * 5. Create HTC
     */
    OS_MEMZERO(&htcInfo,sizeof(htcInfo));
    htcInfo.pContext = scn;
    htcInfo.TargetFailure = ol_target_failure;
    htcInfo.TargetSendSuspendComplete = ol_target_send_suspend_complete;

    if ((scn->htc_handle = HTCCreate(scn->hif_hdl, &htcInfo, scn->adf_dev)) == NULL)
    {
        status = -1;
        goto attach_failed;
    }
    printk("%s() HT Create .\n", __func__);

    HIFClaimDevice(scn->hif_hdl, scn);
    printk("%s() HIF Claim.\n", __func__);

    /*
     * 6. Complete BMI phase
     */
    if (BMIDone(scn->hif_hdl, scn) != A_OK)
    {
         status = -EIO;
         goto attach_failed;
    }
    printk("%s() BMI Done. \n", __func__);

    if (!bypasswmi) {
        /*
         * 7. Initialize WMI
         */
        if ((scn->wmi_handle = wmi_unified_attach(scn, scn->sc_osdev)) == NULL)
        {
            printk("%s() Failed to initialize WMI.\n", __func__);
            status = -1;
            goto attach_failed;
        }
        printk("%s() WMI attached. wmi_handle %p \n", __func__, scn->wmi_handle);
        wmi_unified_register_event_handler(scn->wmi_handle, WMI_DEBUG_PRINT_EVENTID,
                                                wmi_unified_debug_print_event_handler, NULL);
    }
    if (HTCWaitTarget(scn->htc_handle) != A_OK) {
        status = -EIO;
        goto attach_failed;
    }
    if (!bypasswmi) {
        dbglog_init(scn);
#if PERF_FIND_WDS_NODE
        wds_addr_init(scn->wmi_handle);
#endif
        /* FIXME: casting sc_osdev to adf_os_device is not ok for all OS
          (not an issue for linux as linux ignores the handle) */
        /*
         * ol_txrx_pdev_attach needs to be called after calling
         * HTCWaitTarget but before calling HTCStart, so HTT can
         * do its HTC service connection.
         */
        scn->pdev_txrx_handle = ol_txrx_pdev_attach((ol_pdev_handle)scn,
                                                    scn->htc_handle,
                                                    scn->adf_dev);
        if (scn->pdev_txrx_handle == NULL) {
           printk("%s: pdev attach failed\n",__func__);
            status = -EIO;
            goto attach_failed;
        }
    }
    /*
     * 8. Connect Services to HTC
     */
#if ATH_SUPPORT_HYFI_ENHANCEMENTS
	scn->buff_thresh.ald_free_buf_lvl = scn->buff_thresh.pool_size - (( scn->buff_thresh.pool_size * 75 ) / 100);
	scn->buff_thresh.ald_buffull_wrn = 0;
#endif
    if ((status = ol_ath_connect_htc(scn)) != A_OK)
    {
        status = -EIO;
        printk("%s: connect_htc failed\n",__func__);
        goto attach_failed;
    }

#if QCA_OL_11AC_FAST_PATH
    hif_start_set(scn->hif_hdl);
#endif

    if (!bypasswmi) {
        /*
         * Invoke the host datapath initializations that involve messages
         * to the target.
         * (This can't be done until after the HTCStart call, which is in
         * ol_ath_connect_htc.)
         */
        if (scn->target_version != AR6004_VERSION_REV1_3) {
           if (ol_txrx_pdev_attach_target(scn->pdev_txrx_handle) != A_OK) {
                printk("%s: txrx pdev attach failed\n",__func__);
                status = -EIO;
                goto attach_failed;
            }
        }
    }

    printk("%s() connect HTC. \n", __func__);
    printk("bypasswmi : %d\n",bypasswmi);
    if (!bypasswmi) {
        // Use attach_failed1 for failures beyond this
        /*
         * 9. WLAN/UMAC initialization
         */
        ic->ic_is_mode_offload = ol_ath_net80211_is_mode_offload;
        ic->ic_is_macreq_enabled = ol_ath_net80211_is_macreq_enabled;
        ic->ic_get_mac_prealloc_idmask = ol_ath_net80211_get_mac_prealloc_idmask;
        ic->ic_osdev = osdev;
        ic->ic_adf_dev = scn->adf_dev;
        if (scn->target_version == AR6004_VERSION_REV1_3) {
        /*
           It's Hard code for HAL capability and We don't use this branch for McKinley.
           Because McKinley don't support WMI UNIFIED SERVICE READY,
        */
            scn->hal_reg_capabilities.eeprom_rd = 0;
            scn->hal_reg_capabilities.eeprom_rd_ext = 0x1f;
            scn->hal_reg_capabilities.high_2ghz_chan = 0xaac;
            scn->hal_reg_capabilities.high_5ghz_chan = 0x17d4;
            scn->hal_reg_capabilities.low_2ghz_chan = 0x908;
            scn->hal_reg_capabilities.low_5ghz_chan = 0x1338;
            scn->hal_reg_capabilities.regcap1 = 7;
            scn->hal_reg_capabilities.regcap2 = 0xbc0;
            scn->hal_reg_capabilities.wireless_modes = 0x1f9001;
            scn->phy_capability = 1;
            ol_regdmn_attach(scn);
            ol_regdmn_set_regdomain(scn->ol_regdmn_handle, scn->hal_reg_capabilities.eeprom_rd);
            ol_regdmn_set_regdomain_ext(scn->ol_regdmn_handle, scn->hal_reg_capabilities.eeprom_rd_ext);
        }
        ol_regdmn_start(scn->ol_regdmn_handle, ieee80211_conf_parm);

        /*
        To propagate the country settings to UMAC layer so that
        tools like wlanmon is able to get the information they want
        */
        ic->ic_get_currentCountry(ic, &ic->ic_country);

        ol_ath_setup_rates(ic);
        ol_ath_phyerr_attach(ic);
        ieee80211com_set_cap_ext(ic, IEEE80211_CEXT_PERF_PWR_OFLD);

        status = ol_ath_dev_attach(scn, ieee80211_conf_parm);
        if (status)
            goto devattach_failed;

#if ATH_SUPPORT_DFS
        ol_if_dfs_setup(ic);
#endif

#if ATH_SUPPORT_HYFI_ENHANCEMENTS
		ic->ic_add_hmmc = ath_net80211_add_hmmc;
		ic->ic_del_hmmc = ath_net80211_del_hmmc;
		ic->ic_hmmc_cnt = 3;
		ic->ic_hmmcs[0].ip = be32toh(0xeffffffa); /* 239.255.255.250 */
		ic->ic_hmmcs[0].mask = 0xffffffff;
		ic->ic_hmmcs[1].ip = be32toh(0xe00000fb); /* 224.0.0.251 */
		ic->ic_hmmcs[1].mask = 0xffffffff;
		ic->ic_hmmcs[2].ip = be32toh(0xe00000fc); /* 224.0.0.252 */
		ic->ic_hmmcs[2].mask = 0xffffffff;
		ic->ic_get_ald_statistics = ath_net80211_get_ald_statistics;
		ic->ic_notify_buffull = ath_net80211_buffull_handler;
		ic->ic_check_buffull_condition = ol_ath_net80211_check_buffull_condition;
#endif

        ol_ath_vap_attach(ic);
        ol_ath_node_attach(scn, ic);
        ol_ath_beacon_attach(ic);
        ol_ath_rtt_meas_report_attach(ic);
#ifdef QVIT
        ol_ath_qvit_attach(scn);
#endif
        ol_ath_utf_attach(scn);

        ol_ath_mgmt_attach(ic);

        ol_ath_chan_info_attach(ic);
        /* attach the dcs functionality */
        ol_ath_dcs_attach(ic);
        /* As of now setting ic with all ciphers assuming
         * hardware will support, eventually to query
         * the hardware to figure out h/w crypto support.
         */
        ieee80211com_set_cap(ic, IEEE80211_C_WEP);
        ieee80211com_set_cap(ic, IEEE80211_C_AES);
        ieee80211com_set_cap(ic, IEEE80211_C_AES_CCM);
        ieee80211com_set_cap(ic, IEEE80211_C_CKIP);
        ieee80211com_set_cap(ic, IEEE80211_C_TKIP);
        ieee80211com_set_cap(ic, IEEE80211_C_TKIPMIC);
        if (WMI_SERVICE_IS_ENABLED(scn->wmi_service_bitmap, WMI_SERVICE_11AC)) {
            ieee80211com_set_cap_ext(ic, IEEE80211_CEXT_11AC);
        }

        if (ieee80211_conf_parm->wmeEnabled) {
            ieee80211com_set_cap(ic, IEEE80211_C_WME);
        }

#if ATH_SUPPORT_WAPI
        ieee80211com_set_cap(ic, IEEE80211_C_WAPI);
#endif
#if UMAC_SCAN_OFFLOAD
        ol_scan_update_channel_list(ic->ic_scanner);
#endif
        wds_addr_init(scn->wmi_handle);

        wmi_unified_register_event_handler(scn->wmi_handle, WMI_WLAN_PROFILE_DATA_EVENTID,
                                                wmi_unified_wlan_profile_data_event_handler, NULL);

        wmi_unified_register_event_handler(scn->wmi_handle, WMI_PDEV_TPC_CONFIG_EVENTID,
                                                wmi_unified_pdev_tpc_config_event_handler, NULL);

        wmi_unified_register_event_handler(scn->wmi_handle, WMI_GPIO_INPUT_EVENTID,
                                                wmi_unified_gpio_input_event_handler, NULL);

        wmi_unified_register_event_handler(scn->wmi_handle, WMI_GENERIC_BUFFER_EVENTID,
                                                wmi_unified_generic_buffer_event_handler, NULL);

        wmi_unified_register_event_handler(scn->wmi_handle, WMI_MCAST_LIST_AGEOUT_EVENTID,
                                                wmi_unified_mcast_list_ageout_event_handler, NULL);

#if OL_ATH_SUPPORT_LED
        if (scn->target_version == AR9888_REV2_VERSION || scn->target_version == AR9887_REV1_VERSION) {
            scn->scn_led_gpio = PEREGRINE_LED_GPIO ;
        }
        if (scn->lteu_support) {
            wmi_unified_gpio_config(scn->wmi_handle, scn->scn_led_gpio, 1, WMI_GPIO_PULL_DOWN, WMI_GPIO_INTTYPE_RISING_EDGE);
        } else {
            wmi_unified_gpio_config(scn->wmi_handle, scn->scn_led_gpio, 0, 0, 0);
            wmi_unified_gpio_output(scn->wmi_handle, scn->scn_led_gpio, 1);

            OS_INIT_TIMER(scn->sc_osdev, &(scn->scn_led_blink_timer), ol_ath_led_blink_timed_out, (void *)scn);
            OS_INIT_TIMER(scn->sc_osdev, &(scn->scn_led_poll_timer), ol_ath_led_poll_timed_out, (void *)scn);
            scn->scn_blinking = OL_BLINK_DONE;
            scn->scn_led_byte_cnt = 0;
            scn->scn_led_last_time = CONVERT_SYSTEM_TIME_TO_MS(OS_GET_TIMESTAMP());
            scn->scn_led_blink_rate_table         = ol_led_blink_rate_table;
            scn->scn_led_max_blink_rate_idx = ARRAY_LENGTH(ol_led_blink_rate_table) - 1;
        }
#endif
    }
    printk("%s() UMAC attach . \n", __func__);
#if ATH_SUPPORT_DFS
    ol_if_dfs_configure(ic);
    printk("%s: Calling ol_if_dfs_configure\n", __func__);
#endif

    ic->ic_scan_entry_max_count = ATH_SCANENTRY_MAX;
    atomic_set(&(ic->ic_scan_entry_current_count),0);
    ic->ic_scan_entry_timeout = ATH_SCANENTRY_TIMEOUT;
    status = wmi_unified_pdev_set_param(scn->wmi_handle,
            WMI_PDEV_PARAM_ANI_ENABLE, 1);
    if(status == EOK )
        scn->is_ani_enable = true;
    else
        scn->is_ani_enable = false;

    return EOK;

devattach_failed:
    if(scn->hif_sc) {
        struct ath_hif_pci_softc *sc = (struct ath_hif_pci_softc *) scn->hif_sc;
        ol_ath_pci_disable_device(sc->pdev);
        dev_disabled = 1; /*to prevent it from double disabled */
    }
    ol_ath_disconnect_htc(scn);
attach_failed:
    if(scn->hif_sc && ! dev_disabled ) {
        struct ath_hif_pci_softc *sc = (struct ath_hif_pci_softc *) scn->hif_sc;
        ol_ath_pci_disable_device(sc->pdev);
    }
    if (scn->htc_handle) {
        HTCDestroy(scn->htc_handle);
        scn->htc_handle = NULL;
    }
    BMICleanup(scn);

    if (scn->hif_hdl != NULL) {
        HIFReleaseDevice(scn->hif_hdl);
        HIFShutDownDevice(scn->hif_hdl);
    }

    if (!bypasswmi) {
        if (scn->wmi_handle) {
            wmi_unified_detach(scn->wmi_handle);
            scn->wmi_handle = NULL;
        }
        if (scn->pdev_txrx_handle) {
            /* Force delete txrx pdev */
            ol_txrx_pdev_detach(scn->pdev_txrx_handle, 1);
            scn->pdev_txrx_handle = NULL;
        }
    }
#ifdef AH_CAL_IN_FLASH_PCI
#ifndef ATH_CAL_NAND_FLASH
    if (scn->cal_mem) {
        A_IOUNMAP(scn->cal_mem);
        scn->cal_mem = 0;
        scn->cal_in_flash = 0;
    }
#endif
#endif
    return status;
}

int
ol_ath_detach(struct ol_ath_softc_net80211 *scn, int force)
{
    struct ieee80211com     *ic;
    int status = 0,idx;
    ic = &scn->sc_ic;

#if OL_ATH_SUPPORT_LED
    if (!bypasswmi && !scn->lteu_support) {
        scn->scn_led_blink_rate_table = NULL;
        adf_os_timer_sync_cancel(&scn->scn_led_blink_timer);
        adf_os_timer_sync_cancel(&scn->scn_led_poll_timer);
    }
#endif
    wds_addr_detach(scn->wmi_handle);

    ol_ath_stats_detach(ic);

    ol_ath_wow_detach(ic);

    if (!bypasswmi) {
        ieee80211_stop_running(ic);
#if ATH_SUPPORT_DFS
        ol_if_dfs_teardown(ic);
#endif
        ol_ath_phyerr_detach(ic);

        /*
         * NB: the order of these is important:
         * o call the 802.11 layer before detaching the hal to
         *   insure callbacks into the driver to delete global
         *   key cache entries can be handled
         * o reclaim the tx queue data structures after calling
         *   the 802.11 layer as we'll get called back to reclaim
         *   node state and potentially want to use them
         * o to cleanup the tx queues the hal is called, so detach
         *   it last
         * Other than that, it's straightforward...
         */
        ieee80211_ifdetach(ic);
    }
#if 0 /* TBD */
    ol_ath_vap_detach(ic);
    ol_ath_node_detach(scn, ic);
    ol_ath_beacon_detach(ic);
    ol_ath_scan_detach(ic);

    ol_ath_mgmt_detach(ic);
#endif

    ol_ath_nl_detach(ic);

#ifndef REMOVE_PKT_LOG
    if (scn->pl_dev){
        ol_pktlog_detach(scn);
		ol_pl_freehandle(scn->pl_dev);
    }
#endif

    ol_regdmn_detach(scn->ol_regdmn_handle);

    adf_os_spinlock_destroy(&scn->amem.lock);
    asf_amem_destroy(scn->amem.handle, NULL);
    scn->amem.handle = NULL;

    ol_ath_disconnect_htc(scn);
#ifdef QVIT
    ol_ath_qvit_detach(scn);
#endif
    if (!bypasswmi) {
        ol_ath_utf_detach(scn);
        /*
         * The call to ol_txrx_pdev_detach has to happen after the call to
         * ol_ath_disconnect_htc, so that if there are any outstanding
         * tx packets inside HTC, the cleanup callbacks into HTT and txrx
         * will still be valid.
         */
        if (scn->pdev_txrx_handle) {
           ol_txrx_pdev_detach(scn->pdev_txrx_handle, force);
            scn->pdev_txrx_handle = NULL;
        }
        dbglog_free(scn);
    }

#if UNIFIED_SMARTANTENNA
    ol_ath_smart_ant_detach(ic);
#endif
    if (scn->htc_handle) {
        HTCDestroy(scn->htc_handle);
        scn->htc_handle = NULL;
    }
    if (!bypasswmi) {
        if (scn->wmi_handle) {
            wmi_unified_detach(scn->wmi_handle);
            scn->wmi_handle =NULL;
        }
    }
    /* Cleanup BMI */
    BMICleanup(scn);

    if (scn->hif_hdl != NULL) {
        /*
         * Release the device so we do not get called back on remove
         * incase we we're explicity destroyed by module unload
         */
        HIFReleaseDevice(scn->hif_hdl);
        HIFShutDownDevice(scn->hif_hdl);
        scn->hif_hdl = NULL;
    }

#if ATH_SUPPORT_SPECTRAL
    ol_if_spectral_detach(ic);
#endif  // ATH_SUPPORT_SPECTRAL

#if ATH_SUPPORT_GREEN_AP
    ol_if_green_ap_detach(ic);
#endif  /* ATH_SUPPORT_GREEN_AP */

#ifdef AH_CAL_IN_FLASH_PCI
#ifndef ATH_CAL_NAND_FLASH
    if (scn->cal_mem) {
        A_IOUNMAP(scn->cal_mem);
        scn->cal_mem = 0;
        scn->cal_in_flash = 0;
    }
#endif
#endif
    adf_os_spinlock_destroy(&scn->scn_lock);

    for(idx=0;idx<scn->num_mem_chunks; ++idx) {
        adf_os_mem_free_consistent(
            scn->adf_dev,
            scn->mem_chunks[idx].len,
            scn->mem_chunks[idx].vaddr,
            scn->mem_chunks[idx].paddr,
            adf_os_get_dma_mem_context((&(scn->mem_chunks[idx])), memctx));
    }
    /* No Target accesses of any kind after this point */
    return status;
}

int
ol_ath_resume(struct ol_ath_softc_net80211 *scn)
{
    return 0;
}

int
ol_ath_suspend(struct ol_ath_softc_net80211 *scn)
{
    return 0;
}

void
ol_ath_target_status_update(struct ol_ath_softc_net80211 *scn, ol_target_status status)
{
    /* target lost, host needs to recover/reattach */
    scn->target_status = status;
}

void
ol_ath_suspend_resume_attach(struct ol_ath_softc_net80211 *scn)
{
}


int
ol_ath_suspend_target(struct ol_ath_softc_net80211 *scn, int disable_target_intr)
{
    wmi_pdev_suspend_cmd* cmd;
    wmi_buf_t wmibuf;
    u_int32_t len = sizeof(wmi_pdev_suspend_cmd);
    /*send the comand to Target to ignore the
    * PCIE reset so as to ensure that Host and target
    * states are in sync*/
    wmibuf = wmi_buf_alloc(scn->wmi_handle, len);
    if (wmibuf == NULL) {
        return -1;
    }

    cmd = (wmi_pdev_suspend_cmd *)wmi_buf_data(wmibuf);
    if (disable_target_intr) {
        cmd->suspend_opt = WMI_PDEV_SUSPEND_AND_DISABLE_INTR;
    }
    else {
        cmd->suspend_opt = WMI_PDEV_SUSPEND;
    }

    /*
     * Flush pending packets in HTC endpoint queue
     *
     */
    wmi_flush_endpoint(scn->wmi_handle);

    return wmi_unified_cmd_send(scn->wmi_handle, wmibuf, len,
                                WMI_PDEV_SUSPEND_CMDID);
}

int
ol_ath_resume_target(struct ol_ath_softc_net80211 *scn)
{
    wmi_buf_t wmibuf;

    wmibuf = wmi_buf_alloc(scn->wmi_handle, 0);
    if (wmibuf == NULL) {
        return  -1;
    }
    return wmi_unified_cmd_send(scn->wmi_handle, wmibuf, 0,
                                WMI_PDEV_RESUME_CMDID);
}
#ifndef A_MIN
#define A_MIN(a,b)    ((a)<(b)?(a):(b))
#endif
/*
 * ol_ath_cw_interference_handler
 *
 * Functionality of this should be the same as
 * ath_net80211_cw_interference_handler() in lmac layer of the direct attach
 * drivers. Keep this same across both.
 *
 * When the cw interference is sent from the target, kick start the scan
 * with auto channel. This is disruptive channel change. Non-discruptive
 * channel change is the responsibility of scan module.
 *
 */
static void
ol_ath_wlan_n_cw_interference_handler(struct ol_ath_softc_net80211 *scn,
                                      A_UINT32 interference_type)
{
    struct ieee80211vap *vap;
    struct ieee80211com *ic = &scn->sc_ic;

    /* Check if CW Interference is already been found and being handled */
    if (ic->cw_inter_found)
        return;

	printk("DCS: inteference_handler - start");

    spin_lock(&ic->ic_lock);

    /*
	 * mark this channel as cw_interference is found
     * Set the CW interference flag so that ACS does not bail out this flag
     * would be reset in ieee80211_beacon.c:ieee80211_beacon_update()
     */
    ic->cw_inter_found = 1;

    /* Before triggering the channel change, turn off the dcs until the
     * channel change completes, to avoid repeated reports.
     */
    (void)wmi_unified_pdev_set_param(scn->wmi_handle, WMI_PDEV_PARAM_DCS, 0);
    printk("DCS channel change triggered, disabling until channel change completes\n");
    OL_ATH_DCS_CLR_RUNSTATE(scn->scn_dcs.dcs_enable);
    spin_unlock(&ic->ic_lock);

    TAILQ_FOREACH(vap, &ic->ic_vaps, iv_next) {
        if (vap->iv_opmode == IEEE80211_M_HOSTAP) {
            printk("De-authenticating all the nodes before channel change \n");
            wlan_deauth_all_stas(vap);
        }
    }

#if ATH_SUPPORT_SPECTRAL
    if (scn->scn_icm_active) {
        struct ath_spectral *spectral = ic->ic_spectral;
        spin_lock(&ic->ic_lock);

        printk("ICM is active, sending message to change channel with "
               "DCS flag %d\n",
               OL_IS_DCS_ENABLED(scn->scn_dcs.dcs_enable));

        /* Currently, ol_ath_wlan_n_cw_interference_handler()
           is common to both CW AND WLAN interferences */
        if (interference_type == ATH_CAP_DCS_CWIM) {
            spectral_send_intf_found_msg(spectral,
                                   1,
                                   OL_IS_DCS_ENABLED(scn->scn_dcs.dcs_enable));
        } else if (interference_type == ATH_CAP_DCS_WLANIM) {
            spectral_send_intf_found_msg(spectral,
                                   0,
                                   OL_IS_DCS_ENABLED(scn->scn_dcs.dcs_enable));
        }
        spin_unlock(&ic->ic_lock);
    } else {
#endif /* ATH_SUPPORT_SPECTRAL */
        /* Loop through and figure the first VAP on this radio */
        /* FIXME
         * There could be some issue in mbssid mode. It does look like if
         * wlan_set_channel fails on first vap, it tries on the second vap
         * again. Given that all vaps on same radio, we may need not do this.
         * Need a test case for this. Leaving the code as it is.
         */
        TAILQ_FOREACH(vap, &ic->ic_vaps, iv_next) {
            if (vap->iv_opmode == IEEE80211_M_HOSTAP) {
                if (ieee80211_vap_active_is_set(vap) &&
                      !wlan_set_channel(vap, IEEE80211_CHAN_ANY)) {
                    /* ACS is done on per radio, so calling it once is
                    * good enough
                    */
                    goto done;
                }
            }
        }
        spin_lock(&ic->ic_lock);
        /*
         * reset cw_interference found flag since ACS is not triggered, so
         * it can change the channel on next CW intf detection
         */
        ic->cw_inter_found = 0;
        spin_unlock(&ic->ic_lock);

#if ATH_SUPPORT_SPECTRAL
    }
#endif /* ATH_SUPPORT_SPECTRAL */

#if ATH_SUPPORT_SPECTRAL
    if (!(scn->scn_icm_active)) {
        printk("DCS: %s ACS Trigger failed ", __func__);
    }
#else
    printk("DCS: %s ACS Trigger failed ", __func__);
#endif /* ATH_SUPPORT_SPECTRAL */

    /* Should not come here (if ICM is not active), something is not right, hope
     * something better happens next time the flag is set
     */

done:
	printk("DCS: %s interference_handling is complete...", __func__);
}

inline static void
wlan_dcs_im_copy_stats(wlan_dcs_im_tgt_stats_t *prev_stats, wlan_dcs_im_tgt_stats_t *curr_stats)
{
	/* right now no other actions are required beyond memcopy, if
	 * rquired the rest of the code would follow
	 */
	OS_MEMCPY(prev_stats, curr_stats, sizeof(wlan_dcs_im_tgt_stats_t));
}

inline static void
wlan_dcs_im_print_stats(wlan_dcs_im_tgt_stats_t *prev_stats, wlan_dcs_im_tgt_stats_t *curr_stats)
{
	/* debug, dump all received stats first */
	printk("tgt_curr/tsf,%u", curr_stats->reg_tsf32);
	printk(",tgt_curr/last_ack_rssi,%u", curr_stats->last_ack_rssi);
    printk(",tgt_curr/tx_waste_time,%u", curr_stats->tx_waste_time);
    printk(",tgt_curr/dcs_rx_time,%u", curr_stats->rx_time);
	printk(",tgt_curr/listen_time,%u", curr_stats->mib_stats.listen_time);
	printk(",tgt_curr/tx_frame_cnt,%u", curr_stats->mib_stats.reg_tx_frame_cnt);
	printk(",tgt_curr/rx_frame_cnt,%u", curr_stats->mib_stats.reg_rx_frame_cnt);
	printk(",tgt_curr/rxclr_cnt,%u", curr_stats->mib_stats.reg_rxclr_cnt);
	printk(",tgt_curr/reg_cycle_cnt,%u", curr_stats->mib_stats.reg_cycle_cnt);
	printk(",tgt_curr/rxclr_ext_cnt,%u", curr_stats->mib_stats.reg_rxclr_ext_cnt);
	printk(",tgt_curr/ofdm_phyerr_cnt,%u", curr_stats->mib_stats.reg_ofdm_phyerr_cnt);
	printk(",tgt_curr/cck_phyerr_cnt,%u", curr_stats->mib_stats.reg_cck_phyerr_cnt);

	printk("tgt_prev/tsf,%u", prev_stats->reg_tsf32);
	printk(",tgt_prev/last_ack_rssi,%u", prev_stats->last_ack_rssi);
    printk(",tgt_prev/tx_waste_time,%u", prev_stats->tx_waste_time);
    printk(",tgt_prev/rx_time,%u", prev_stats->rx_time);
	printk(",tgt_prev/listen_time,%u", prev_stats->mib_stats.listen_time);
	printk(",tgt_prev/tx_frame_cnt,%u", prev_stats->mib_stats.reg_tx_frame_cnt);
	printk(",tgt_prev/rx_frame_cnt,%u", prev_stats->mib_stats.reg_rx_frame_cnt);
	printk(",tgt_prev/rxclr_cnt,%u", prev_stats->mib_stats.reg_rxclr_cnt);
	printk(",tgt_prev/reg_cycle_cnt,%u", prev_stats->mib_stats.reg_cycle_cnt);
	printk(",tgt_prev/rxclr_ext_cnt,%u", prev_stats->mib_stats.reg_rxclr_ext_cnt);
	printk(",tgt_prev/ofdm_phyerr_cnt,%u", prev_stats->mib_stats.reg_ofdm_phyerr_cnt);
	printk(",tgt_prev/cck_phyerr_cnt,%u", prev_stats->mib_stats.reg_cck_phyerr_cnt);
}

/*
 * reg_xxx - All the variables are contents of the corresponding
 *  		register contents
 * xxx_delta - computed difference between previous cycle and c
 * 		    current cycle
 * reg_xxx_cu	- Computed channel utillization in %,
 *  		computed through register statistics
 *
 * FIXME ideally OL and non-OL layers can re-use the same code.
 * But this is done differently between OL and non-OL paths.
 * We may need to rework this completely for both to work with single
 * piece of code. The non-OL path also need lot of rework. All
 * stats need to be taken to UMAC layer. That seems to be too
 * much of work to do at this point of time. Right now host code
 * is limited to one below function, and this function alone
 * need to go UMAC. Given that function is small, tend to keep
 * only here here. If this gets any bigger we shall try doing it
 * in umac, and merge entire code ( ol and non-ol to umac ).
 */
static void
ol_ath_wlan_interference_handler(ol_scn_t scn,
                                 wlan_dcs_im_tgt_stats_t *curr_stats,
                                 A_UINT32 interference_type)
{
	wlan_dcs_im_tgt_stats_t *prev_stats;

	u_int32_t reg_tsf_delta = 0;                /* prev-tsf32  - curr-tsf32 */
	u_int32_t rxclr_delta = 0;                  /* prev-RXCLR - curr-RXCLR */
	u_int32_t rxclr_ext_delta = 0;              /* prev-RXEXTCLR - curreent RXEXTCLR, most of the time this is zero, chip issue ?? */
	u_int32_t cycle_count_delta = 0;            /* prev CCYCLE - curr CCYCLE */
	u_int32_t tx_frame_delta = 0;               /* prev TFCT - curr TFCNT */
	u_int32_t rx_frame_delta = 0;               /* prev RFCNT - curr RFCNT */
	u_int32_t reg_total_cu = 0; 				/* total channel utilization in %*/
	u_int32_t reg_tx_cu = 0;					/* transmit channel utilization in %*/
    u_int32_t reg_rx_cu = 0;					/* receive channel utilization in %*/
	u_int32_t reg_unused_cu = 0;                /* unused channel utillization */
	u_int32_t rx_time_cu=0;						/* computed rx time*/
	u_int32_t reg_ofdm_phyerr_delta = 0;		/* delta ofdm errors */
	u_int32_t reg_cck_phyerr_delta = 0;			/* delta cck errors*/
	u_int32_t reg_ofdm_phyerr_cu = 0;			/* amount utilization by ofdm errors*/
	u_int32_t ofdm_phy_err_rate = 0;			/* rate at which ofdm errors are seen*/
	u_int32_t cck_phy_err_rate=0;				/* rate at which cck errors are seen*/
	u_int32_t max_phy_err_rate = 0;
    u_int32_t max_phy_err_count = 0;
	u_int32_t total_wasted_cu = 0;
	u_int32_t wasted_tx_cu = 0;
	u_int32_t tx_err = 0;
	int too_many_phy_errors = 0;

	if (!scn || !curr_stats) {
		printk("\nDCS: scn is NULL\n");
		return;
	}

    prev_stats =  &scn->scn_dcs.scn_dcs_im_stats.prev_dcs_im_stats;

    if (unlikely(scn->scn_dcs.dcs_debug >= DCS_DEBUG_VERBOSE)) {
        wlan_dcs_im_print_stats(prev_stats, curr_stats);
    }

    /* counters would have wrapped. Ideally we should be able to figure this
     * out, but we never know how many times counters wrapped. just ignore
     */
	if ((curr_stats->mib_stats.listen_time <= 0) ||
        (curr_stats->reg_tsf32 <= prev_stats->reg_tsf32)) {

		if (unlikely(scn->scn_dcs.dcs_debug >= DCS_DEBUG_VERBOSE)) {
            printk("\nDCS: ignoring due to negative TSF value\n");
        }
        /* copy the current stats to previous stats for next run */
		wlan_dcs_im_copy_stats(prev_stats, curr_stats);
		return;
	}

	reg_tsf_delta = curr_stats->reg_tsf32 - prev_stats->reg_tsf32;

	/* do nothing if current stats are not seeming good, probably
	 * a reset happened on chip, force cleared
	 */
	if (prev_stats->mib_stats.reg_rxclr_cnt > curr_stats->mib_stats.reg_rxclr_cnt) {
		if (unlikely(scn->scn_dcs.dcs_debug >= DCS_DEBUG_VERBOSE)) {
            printk("\nDCS: ignoring due to negative rxclr count\n");
        }

        /* copy the current stats to previous stats for next run */
		wlan_dcs_im_copy_stats(prev_stats, curr_stats);
		return;
	}

	rxclr_delta = curr_stats->mib_stats.reg_rxclr_cnt - prev_stats->mib_stats.reg_rxclr_cnt;
	rxclr_ext_delta = curr_stats->mib_stats.reg_rxclr_ext_cnt -
								prev_stats->mib_stats.reg_rxclr_ext_cnt;
	tx_frame_delta = curr_stats->mib_stats.reg_tx_frame_cnt -
								prev_stats->mib_stats.reg_tx_frame_cnt;

	rx_frame_delta = curr_stats->mib_stats.reg_rx_frame_cnt -
								prev_stats->mib_stats.reg_rx_frame_cnt;

	cycle_count_delta = curr_stats->mib_stats.reg_cycle_cnt -
								prev_stats->mib_stats.reg_cycle_cnt;

    if (unlikely(scn->scn_dcs.dcs_debug >= DCS_DEBUG_VERBOSE)) {
        printk(",rxclr_delta,%u,rxclr_ext_delta,%u,tx_frame_delta,%u,rx_frame_delta,%u,cycle_count_delta,%u",
                rxclr_delta , rxclr_ext_delta , tx_frame_delta,
                rx_frame_delta , cycle_count_delta );
    }

    if(0 == (cycle_count_delta >>8)) {
        wlan_dcs_im_copy_stats(prev_stats, curr_stats);
        if (unlikely(scn->scn_dcs.dcs_debug >= DCS_DEBUG_VERBOSE))
            printk(" cycle count NULL---Investigate--\n");
        return;
    }

	/* total channel utiliztaion is the amount of time RXCLR is
	 * counted. RXCLR is counted, when 'RX is NOT clear', please
	 * refer to mac documentation. It means either TX or RX is ON
     *
     * Why shift by 8 ? after multiplication it could overflow. At one
     * second rate, neither cycle_count_celta, nor the tsf_delta would be
     * zero after shift by 8 bits
	 */
	reg_total_cu = ((rxclr_delta >> 8) * 100) / (cycle_count_delta >>8);
	reg_tx_cu = ((tx_frame_delta >> 8 ) * 100) / (cycle_count_delta >> 8);
	reg_rx_cu = ((rx_frame_delta >> 8 ) * 100) / (cycle_count_delta >> 8);
	rx_time_cu = ((curr_stats->rx_time >> 8) * 100 ) / (reg_tsf_delta >> 8);

    /**
     * Amount of the time AP received cannot go higher than the receive
     * cycle count delta. If at all it is, there should have been a
     * compution error, ceil it to receive_cycle_count_diff
     */
	if (rx_time_cu > reg_rx_cu) {
		rx_time_cu = reg_rx_cu;
	}

    if (unlikely(scn->scn_dcs.dcs_debug >= DCS_DEBUG_VERBOSE)) {
        printk(",reg_total_cu,%u,reg_tx_cu,%u,reg_rx_cu,%u,rx_time_cu,%u",
                    reg_total_cu, reg_tx_cu, reg_rx_cu, rx_time_cu);
    }

	/* Unusable channel utilization is amount of time that we
	 * spent in backoff or waiting for other transmit/receive to
	 * complete. If there is interference it is more likely that
	 * we overshoot the limit. In case of multiple stations, we
	 * still see increased channel utilization.  This assumption may
	 * not be true for the VOW scenario where either multicast or
	 * unicast-UDP is used ( mixed traffic would still cause high
	 * channel utilization).
     */
	wasted_tx_cu = ((curr_stats->tx_waste_time >> 8) * 100 ) / (reg_tsf_delta >> 8);

    /**
     * transmit channel utilization cannot go higher than the amount of time
     * wasted, if so cap the wastage to transmit channel utillzation. This
     * could happen to compution error.
     */
	if (reg_tx_cu < wasted_tx_cu) {
		wasted_tx_cu = reg_tx_cu;
	}

	tx_err = (reg_tx_cu  && wasted_tx_cu) ? (wasted_tx_cu * 100 )/reg_tx_cu : 0;

    /**
     * The below actually gives amount of time we are not using, or the
     * interferer is active.
     * rx_time_cu is what computed receive time *NOT* rx_cycle_count
     * rx_cycle_count is our receive+interferer's transmit
     * un-used is really total_cycle_counts -
     *      (our_rx_time(rx_time_cu)+ our_receive_time)
     */
	reg_unused_cu = (reg_total_cu >= (reg_tx_cu + rx_time_cu)) ?
							(reg_total_cu - (reg_tx_cu + rx_time_cu)) : 0;

    /* if any retransmissions are there, count them as wastage
     */
	total_wasted_cu = reg_unused_cu + wasted_tx_cu;

	/* check ofdm and cck errors */
    if (unlikely(curr_stats->mib_stats.reg_ofdm_phyerr_cnt  <
            prev_stats->mib_stats.reg_ofdm_phyerr_cnt)) {
        reg_ofdm_phyerr_delta = curr_stats->mib_stats.reg_ofdm_phyerr_cnt ;
    } else {
        reg_ofdm_phyerr_delta = curr_stats->mib_stats.reg_ofdm_phyerr_cnt -
                                    prev_stats->mib_stats.reg_ofdm_phyerr_cnt;
    }

	if (unlikely(curr_stats->mib_stats.reg_cck_phyerr_cnt  <
            prev_stats->mib_stats.reg_cck_phyerr_cnt)) {
        reg_cck_phyerr_delta = curr_stats->mib_stats.reg_cck_phyerr_cnt;
    } else {
        reg_cck_phyerr_delta = curr_stats->mib_stats.reg_cck_phyerr_cnt -
                                    prev_stats->mib_stats.reg_cck_phyerr_cnt;
    }

	/* add the influence of ofdm phy errors to the wasted channel
	 * utillization, this computed through time wasted in errors,
	 */
	reg_ofdm_phyerr_cu = reg_ofdm_phyerr_delta * scn->scn_dcs.phy_err_penalty ;
	total_wasted_cu += (reg_ofdm_phyerr_cu > 0) ?  (((reg_ofdm_phyerr_cu >> 8) * 100) / (reg_tsf_delta >> 8)) : 0;

	ofdm_phy_err_rate = (curr_stats->mib_stats.reg_ofdm_phyerr_cnt * 1000) /
                                curr_stats->mib_stats.listen_time;
	cck_phy_err_rate = (curr_stats->mib_stats.reg_cck_phyerr_cnt * 1000) /
                                curr_stats->mib_stats.listen_time;

    if (unlikely(scn->scn_dcs.dcs_debug >= DCS_DEBUG_VERBOSE)) {
        printk(",reg_unused_cu,%u,reg_ofdm_phyerr_delta,%u,reg_cck_phyerr_delta,%u,reg_ofdm_phyerr_cu,%u",
                    reg_unused_cu , reg_ofdm_phyerr_delta , reg_cck_phyerr_delta , reg_ofdm_phyerr_cu);
        printk(",total_wasted_cu,%u,ofdm_phy_err_rate,%u,cck_phy_err_rate,%u",
                    total_wasted_cu , ofdm_phy_err_rate , cck_phy_err_rate );
        printk(",new_unused_cu,%u,reg_ofdm_phy_error_cu,%u\n",
                reg_unused_cu, (curr_stats->mib_stats.reg_ofdm_phyerr_cnt*100)/
                                        curr_stats->mib_stats.listen_time);
    }

	/* check if the error rates are higher than the thresholds*/
	max_phy_err_rate = MAX(ofdm_phy_err_rate, cck_phy_err_rate);

	max_phy_err_count = MAX(curr_stats->mib_stats.reg_ofdm_phyerr_cnt,
                                curr_stats->mib_stats.reg_cck_phyerr_cnt);

    if (unlikely(scn->scn_dcs.dcs_debug >= DCS_DEBUG_VERBOSE)) {
        printk(",max_phy_err_rate,%u, max_phy_err_count,%u",max_phy_err_rate , max_phy_err_count);
    }

	if (((max_phy_err_rate >= scn->scn_dcs.phy_err_threshold) &&
				(max_phy_err_count > scn->scn_dcs.phy_err_threshold)) ||
         (curr_stats->phyerr_cnt > scn->scn_dcs.radar_err_threshold)) {
		too_many_phy_errors = 1;
	}

    if (unlikely(scn->scn_dcs.dcs_debug >= DCS_DEBUG_CRITICAL)) {
		printk("\nDCS: total_cu %u ,tx_cu %u ,rx_cu %u ,rx_time_cu %u, unused cu %u ",reg_total_cu, reg_tx_cu, reg_rx_cu, rx_time_cu, reg_unused_cu);
                printk("\nDCS: phyerr %u ,total_wasted_cu %u ,phyerror_cu %u ,wasted_cu %u, reg_tx_cu %u ,reg_rx_cu %u",too_many_phy_errors, total_wasted_cu, reg_ofdm_phyerr_cu, wasted_tx_cu, reg_tx_cu, reg_rx_cu);
                printk("\nDCS: tx_err %u",tx_err);
	}

	if (reg_unused_cu >= scn->scn_dcs.coch_intr_thresh) {
		scn->scn_dcs.scn_dcs_im_stats.im_intr_cnt+=2; /* quickly reach to decision*/
	} else if (too_many_phy_errors &&
			   ((total_wasted_cu > scn->scn_dcs.coch_intr_thresh) &&
					(reg_tx_cu + reg_rx_cu) > scn->scn_dcs.user_max_cu)){ /* removed tx_err check here */
		scn->scn_dcs.scn_dcs_im_stats.im_intr_cnt++;
	}

	if (scn->scn_dcs.scn_dcs_im_stats.im_intr_cnt >= scn->scn_dcs.intr_detection_threshold) {

        if (unlikely(scn->scn_dcs.dcs_debug >= DCS_DEBUG_CRITICAL)) {
            printk("\n%s interference threshould exceeded\n", __func__);
            printk(",unused_cu,%u,too_any_phy_errors,%u,total_wasted_cu,%u,reg_tx_cu,%u,reg_rx_cu,%u\n",
                    reg_unused_cu, too_many_phy_errors, total_wasted_cu,reg_tx_cu, reg_rx_cu);
        }

		scn->scn_dcs.scn_dcs_im_stats.im_intr_cnt = 0;
		scn->scn_dcs.scn_dcs_im_stats.im_samp_cnt = 0;
        /* once the interference is detected, change the channel, as on
         * today this is common routine for wirelesslan and non-wirelesslan
         * interference. Name as such kept the same because of the DA code,
         * which is using the same function.
         */
		ol_ath_wlan_n_cw_interference_handler(scn, interference_type);
	} else if (!scn->scn_dcs.scn_dcs_im_stats.im_intr_cnt ||
				scn->scn_dcs.scn_dcs_im_stats.im_samp_cnt >= scn->scn_dcs.intr_detection_window) {
		scn->scn_dcs.scn_dcs_im_stats.im_intr_cnt = 0;
		scn->scn_dcs.scn_dcs_im_stats.im_samp_cnt = 0;
	}

	/* count the current run too*/
	scn->scn_dcs.scn_dcs_im_stats.im_samp_cnt++;

    /* copy the stats for next cycle */
	wlan_dcs_im_copy_stats(prev_stats, curr_stats);

    if (unlikely(scn->scn_dcs.dcs_debug >= DCS_DEBUG_VERBOSE)) {
        printk(",intr_count,%u,sample_count,%d\n",scn->scn_dcs.scn_dcs_im_stats.im_intr_cnt,scn->scn_dcs.scn_dcs_im_stats.im_samp_cnt);
    }
}

/*
 * wmi_unified_dcs_interference_handler
 *
 * There are two different interference types can be reported by the
 * target firmware. Today either that is wireless interference or
 * could be a non-wireless lan interference. All of these are reported
 * WMI message.
 *
 * Message is of type wmi_dcs_interence_type_t
 *
 */
static int
wmi_unified_dcs_interference_handler (ol_scn_t scn, u_int8_t *data, u_int16_t datalen, void *context)
{
	wmi_dcs_interference_event_t *int_event = (wmi_dcs_interference_event_t*)data;

    /* do not handle any thing if host is in disabled state
     * This shall not happen, provide extra safty for against any delays
     * causing any kind of races.
     */
    if (!(OL_IS_DCS_RUNNING(scn->scn_dcs.dcs_enable))) {
        return 0;
    }
	switch (int_event->interference_type) {
	case ATH_CAP_DCS_CWIM: /* cw interferecne*/
		if (OL_IS_DCS_ENABLED(scn->scn_dcs.dcs_enable) & ATH_CAP_DCS_CWIM) {
			ol_ath_wlan_n_cw_interference_handler(scn,
                                                  int_event->interference_type);
		}
		break;
	case ATH_CAP_DCS_WLANIM: /* wlan interference stats*/
		if (OL_IS_DCS_ENABLED(scn->scn_dcs.dcs_enable) & ATH_CAP_DCS_WLANIM) {
			ol_ath_wlan_interference_handler(scn,
                                             &int_event->int_event.wlan_stat,
                                             int_event->interference_type);
		}
		break;
	default:
		if (unlikely(scn->scn_dcs.dcs_debug >= DCS_DEBUG_CRITICAL)) {
            printk("DCS: unidentified interference type reported");
        }
		break;
	}
    return 0;
}


#define TPC_TABLE_TYPE_CDD  0
#define TPC_TABLE_TYPE_STBC 1
#define TPC_TABLE_TYPE_TXBF 2

u_int8_t
tpc_config_get_rate_tpc(wmi_pdev_tpc_config_event *ev, u_int32_t rate_idx, u_int32_t num_chains, u_int8_t rate_code, u_int8_t type)
{
    u_int8_t tpc;
    u_int8_t num_streams;
    u_int8_t preamble;
    u_int8_t chain_idx;

    num_streams = 1 + AR600P_GET_HW_RATECODE_NSS(rate_code);
    preamble = AR600P_GET_HW_RATECODE_PREAM(rate_code);
    chain_idx = num_chains - 1;

    /*
     * find TPC based on the target power for that rate and the maximum
     * allowed regulatory power based on the number of tx chains.
     */
    tpc = A_MIN(ev->ratesArray[rate_idx], ev->maxRegAllowedPower[chain_idx]);

    if (ev->numTxChain > 1) {
        /*
         * Apply array gain factor for non-cck frames and when
         * num of chains used is more than the number of streams
         */
        if (preamble != AR600P_HW_RATECODE_PREAM_CCK) {
            u_int8_t stream_idx;

            stream_idx = num_streams - 1;
            if (type == TPC_TABLE_TYPE_STBC) {
                if (num_chains > num_streams) {
                    tpc = A_MIN(tpc, ev->maxRegAllowedPowerAGSTBC[chain_idx - 1][stream_idx]);
                }
            } else if (type == TPC_TABLE_TYPE_TXBF) {
                if (num_chains > num_streams) {
                    tpc = A_MIN(tpc, ev->maxRegAllowedPowerAGTXBF[chain_idx - 1][stream_idx]);
                }
            } else {
                if (num_chains > num_streams) {
                    tpc = A_MIN(tpc, ev->maxRegAllowedPowerAGCDD[chain_idx - 1][stream_idx]);
                }
            }
        }
    }

    return tpc;
}


void
tpc_config_disp_tables(wmi_pdev_tpc_config_event *ev, u_int8_t *rate_code, u_int16_t *pream_table, u_int8_t type)
{
    u_int32_t i;
    u_char table_str[3][5] =  {
        "CDD ",
        "STBC",
        "TXBF"
    };
    u_char pream_str[8][6] = {
        "CCK  ",
        "OFDM ",
        "HT20 ",
        "HT40 ",
        "VHT20",
        "VHT40",
        "VHT80",
        "HTDUP"
    };
    u_int32_t pream_idx;
    u_int8_t tpc1 = 0;
    u_int8_t tpc2 = 0;
    u_int8_t tpc3 = 0;

    switch (type) {
        case TPC_TABLE_TYPE_CDD:
            if (!(ev->flags & WMI_TPC_CONFIG_EVENT_FLAG_TABLE_CDD)) {
                AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%s : CDD not supported \n",__func__));
                return;
            }
            break;
        case TPC_TABLE_TYPE_STBC:
            if (!(ev->flags & WMI_TPC_CONFIG_EVENT_FLAG_TABLE_STBC)) {
                AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%s : STBC not supported \n",__func__));
                return;
            }
            break;
        case TPC_TABLE_TYPE_TXBF:
            if (!(ev->flags & WMI_TPC_CONFIG_EVENT_FLAG_TABLE_TXBF)) {
                AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%s : TXBF not supported \n",__func__));
                return;
            }
            break;
        default:
            AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%s : Invalid type %d \n",__func__, type));
            return;
    }

    AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("**************** %s POWER TABLE ****************\n",table_str[type])) ;
    AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("**************************************************\n"));

    pream_idx = 0;
    for(i = 0;i < ev->rateMax; i++) {
        if (i == pream_table[pream_idx]) {
            pream_idx++;
        }
        tpc1 = tpc_config_get_rate_tpc(ev, i, 1, rate_code[i], type);
        if (ev->numTxChain > 1) {
            tpc2 = tpc_config_get_rate_tpc(ev, i, 2, rate_code[i], type);
        }
        if (ev->numTxChain > 2) {
            tpc3 = tpc_config_get_rate_tpc(ev, i, 3, rate_code[i], type);
        }
        if (ev->numTxChain == 1) {
            AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("%8d %s 0x%2x %8d \n", i, pream_str[pream_idx], rate_code[i], tpc1));
        } else if (ev->numTxChain == 2) {
            AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("%8d %s 0x%2x %8d %8d \n", i, pream_str[pream_idx], rate_code[i], tpc1, tpc2));
        } else if (ev->numTxChain == 3) {
            AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("%8d %s 0x%2x %8d %8d %8d \n",i, pream_str[pream_idx], rate_code[i], tpc1, tpc2, tpc3));
        }
    }
    AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("**************************************************\n"));

    return;
}

int
wmi_unified_pdev_tpc_config_event_handler (ol_scn_t scn, u_int8_t *data, u_int16_t datalen, void *context)
{
    wmi_pdev_tpc_config_event *ev;
    u_int32_t i, j;
    u_int8_t rate_code[200];
    u_int16_t pream_table[10];
    u_int8_t rate_idx;
    u_int32_t pream_idx;

    ev = (wmi_pdev_tpc_config_event *)data;

#ifdef BIG_ENDIAN_HOST
    {
        /*
         * Target is in little endian, copy engine interface will
         * swap at the dword boundary. Re-swap the byte stream
         * arrays
         */
        u_int32_t *destp, *srcp;
        u_int32_t len;

        srcp = (u_int32_t *)&ev->maxRegAllowedPower[0];
        destp = (u_int32_t *)&ev->maxRegAllowedPower[0];
        len = sizeof(wmi_pdev_tpc_config_event) - offsetof(wmi_pdev_tpc_config_event, maxRegAllowedPower);
        for(i=0; i < (roundup(len, sizeof(u_int32_t))/4); i++) {
            *destp = le32_to_cpu(*srcp);
            destp++; srcp++;
        }
    }
#endif

    /* Create the rate code table based on the chains supported */
    rate_idx = 0;
    pream_idx = 0;

    /* Fill CCK rate code */
    for (i=0;i<4;i++) {
        rate_code[rate_idx] = AR600P_ASSEMBLE_HW_RATECODE(i, 0, AR600P_HW_RATECODE_PREAM_CCK);
        rate_idx++;
    }
    pream_table[pream_idx] = rate_idx;
    pream_idx++;

    /* Fill OFDM rate code */
    for (i=0;i<8;i++) {
        rate_code[rate_idx] = AR600P_ASSEMBLE_HW_RATECODE(i, 0, AR600P_HW_RATECODE_PREAM_OFDM);
        rate_idx++;
    }
    pream_table[pream_idx] = rate_idx;
    pream_idx++;

    /* Fill HT20 rate code */
    for (i=0;i<ev->numTxChain;i++) {
        for (j=0;j<8;j++) {
            rate_code[rate_idx] = AR600P_ASSEMBLE_HW_RATECODE(j, i, AR600P_HW_RATECODE_PREAM_HT);
            rate_idx++;
        }
    }
    pream_table[pream_idx] = rate_idx;
    pream_idx++;

    /* Fill HT40 rate code */
    for (i=0;i<ev->numTxChain;i++) {
        for (j=0;j<8;j++) {
            rate_code[rate_idx] = AR600P_ASSEMBLE_HW_RATECODE(j, i, AR600P_HW_RATECODE_PREAM_HT);
            rate_idx++;
        }
    }
    pream_table[pream_idx] = rate_idx;
    pream_idx++;

    /* Fill VHT20 rate code */
    for (i=0;i<ev->numTxChain;i++) {
        for (j=0;j<10;j++) {
            rate_code[rate_idx] = AR600P_ASSEMBLE_HW_RATECODE(j, i, AR600P_HW_RATECODE_PREAM_VHT);
            rate_idx++;
        }
    }
    pream_table[pream_idx] = rate_idx;
    pream_idx++;

    /* Fill VHT40 rate code */
    for (i=0;i<ev->numTxChain;i++) {
        for (j=0;j<10;j++) {
            rate_code[rate_idx] = AR600P_ASSEMBLE_HW_RATECODE(j, i, AR600P_HW_RATECODE_PREAM_VHT);
            rate_idx++;
        }
    }
    pream_table[pream_idx] = rate_idx;
    pream_idx++;

    /* Fill VHT80 rate code */
    for (i=0;i<ev->numTxChain;i++) {
        for (j=0;j<10;j++) {
            rate_code[rate_idx] = AR600P_ASSEMBLE_HW_RATECODE(j, i, AR600P_HW_RATECODE_PREAM_VHT);
            rate_idx++;
        }
    }
    pream_table[pream_idx] = rate_idx;
    pream_idx++;

    rate_code[rate_idx++] = AR600P_ASSEMBLE_HW_RATECODE(0, 0, AR600P_HW_RATECODE_PREAM_CCK);
    rate_code[rate_idx++] = AR600P_ASSEMBLE_HW_RATECODE(0, 0, AR600P_HW_RATECODE_PREAM_OFDM);
    rate_code[rate_idx++] = AR600P_ASSEMBLE_HW_RATECODE(0, 0, AR600P_HW_RATECODE_PREAM_CCK);
    rate_code[rate_idx++] = AR600P_ASSEMBLE_HW_RATECODE(0, 0, AR600P_HW_RATECODE_PREAM_OFDM);
    rate_code[rate_idx++] = AR600P_ASSEMBLE_HW_RATECODE(0, 0, AR600P_HW_RATECODE_PREAM_OFDM);

    /* use 0xFFFF to indicate end of table */
    pream_table[pream_idx] = 0xFFFF;

    AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("**************************************************\n"));
    AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("TPC Config for channel %4d mode %2d \n", ev->chanFreq, ev->phyMode));
    AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("**************************************************\n"));

    AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("CTL           = 0x%2x   Reg. Domain           = %2d \n", ev->ctl, ev->regDomain));
    AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Antenna Gain  = %2d     Reg. Max Antenna Gain = %2d \n", ev->twiceAntennaGain, ev->twiceAntennaReduction));
    AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Power Limit   = %2d     Reg. Max Power        = %2d \n", ev->powerLimit, ev->twiceMaxRDPower));
    AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Num tx chains = %2d    Num  Supported Rates  = %2d \n", ev->numTxChain, ev->rateMax));
    AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("**************************************************\n"));

    tpc_config_disp_tables(ev, rate_code, pream_table, TPC_TABLE_TYPE_CDD);
    tpc_config_disp_tables(ev, rate_code, pream_table, TPC_TABLE_TYPE_STBC);
    tpc_config_disp_tables(ev, rate_code, pream_table, TPC_TABLE_TYPE_TXBF);


    return 0;
}

int
wmi_unified_gpio_config(wmi_unified_t wmi_handle, u_int32_t gpio_num, u_int32_t input,
                        u_int32_t pull_type, u_int32_t intr_mode)
{
    wmi_gpio_config_cmd *cmd;
    wmi_buf_t wmibuf;
    u_int32_t len = sizeof(wmi_gpio_config_cmd);

    /* Sanity Checks */
    if (pull_type > WMI_GPIO_PULL_DOWN || intr_mode > WMI_GPIO_INTTYPE_LEVEL_HIGH) {
        return -1;
    }

    wmibuf = wmi_buf_alloc(wmi_handle, len);
    if (wmibuf == NULL) {
        return -1;
    }

    cmd = (wmi_gpio_config_cmd *)wmi_buf_data(wmibuf);
    cmd->gpio_num = gpio_num;
    cmd->input = input;
    cmd->pull_type = pull_type;
    cmd->intr_mode = intr_mode;
    return wmi_unified_cmd_send(wmi_handle, wmibuf, len, WMI_GPIO_CONFIG_CMDID);
}

int
wmi_unified_gpio_output(wmi_unified_t wmi_handle, u_int32_t gpio_num, u_int32_t set)
{
    wmi_gpio_output_cmd *cmd;
    wmi_buf_t wmibuf;
    u_int32_t len = sizeof(wmi_gpio_output_cmd);

    wmibuf = wmi_buf_alloc(wmi_handle, len);
    if (wmibuf == NULL) {
        return -1;
    }

    cmd = (wmi_gpio_output_cmd *)wmi_buf_data(wmibuf);
    cmd->gpio_num = gpio_num;
    cmd->set = set;
    return wmi_unified_cmd_send(wmi_handle, wmibuf, len, WMI_GPIO_OUTPUT_CMDID);
}

int
wmi_unified_gpio_input_event_handler (ol_scn_t scn, u_int8_t *data, u_int16_t datalen, void *context)
{
    wmi_gpio_input_event *ev;
    ev = (wmi_gpio_input_event*) data;
    printk("\n%s: GPIO Input Event on Num %d\n", __func__, ev->gpio_num);
    return 0;
}

int
wmi_unified_generic_buffer_event_handler (ol_scn_t scn, u_int8_t *data, u_int16_t datalen, void *context)
{
    wmi_pdev_generic_buffer_event *ev;
    u_int8_t i;
    ev = (wmi_pdev_generic_buffer_event*) data;
    printk("Generic buffer received: type=%d len=%d frag_id=%d, more_frag=%d\n",
            ev->buf_type, ev->buf_len, ev->frag_id, ev->more_frag);

#ifdef BIG_ENDIAN_HOST
    {
        u_int32_t *destp, *srcp;
        u_int32_t len;

        srcp = &ev->buf_info[0];
        destp = &ev->buf_info[0];
        len = ev->buf_len;
        for(i=0; i < (roundup(len, sizeof(u_int32_t))/4); i++) {
            *destp = le32_to_cpu(*srcp);
            destp++; srcp++;
        }
    }
#endif

    if (ev->buf_type == WMI_BUFFER_TYPE_RATEPWR_TABLE) {
        ol_if_ratepwr_recv_buf((u_int8_t *)(&ev->buf_info[0]), ev->buf_len,
                                ev->frag_id, ev->more_frag);
    } else if (ev->buf_type == WMI_BUFFER_TYPE_CTL_TABLE) {
        /* TODO */
    }

    return 0;
}

int
wmi_unified_mcast_list_ageout_event_handler (ol_scn_t scn, u_int8_t *data, u_int16_t datalen, void *context)
{
    wmi_mcast_list_ageout_event *ev;
    struct ieee80211vap *vap;
    int i;
    wmi_mcast_ageout_entry *temp_ptr;
    u_int8_t grp_addr[6]; /* mcast mac addr */
    u_int32_t grp_ipaddr; /* mcast ip addr */

    ev = (wmi_mcast_list_ageout_event*) data;

    if(ev){
        temp_ptr = ev->entry;

        grp_addr[0] = 0x01;
        grp_addr[1] = 0x00;
        grp_addr[2] = 0x5e;

        for(i=0; i< ev->num_entry; i++) {
            if( temp_ptr->grp_addr[0] != 0xff ){
                /* Not ipv6 mcast group address */
                /* Converting the multicast group ip address to multicast mac address */
                grp_addr[3] = temp_ptr->grp_addr[14] & 0x7f;
                grp_addr[4] = temp_ptr->grp_addr[13];
                grp_addr[5] = temp_ptr->grp_addr[12];
                grp_ipaddr  = temp_ptr->grp_addr[15] << 24 |
                              temp_ptr->grp_addr[14] << 16 |
                              temp_ptr->grp_addr[13] << 8  |
                              temp_ptr->grp_addr[12];
                vap = ol_ath_vap_get(scn, temp_ptr->vdev_id);
                if(vap){
                    if(vap->iv_ique_ops.me_deletegrp){
                        vap->iv_ique_ops.me_deletegrp( vap, grp_addr, grp_ipaddr);
                    }
               }
            }
            temp_ptr++;
        }
    }
    return 0;
}

u_int8_t ol_scn_vow_extstats(ol_pdev_handle pdev)
{
    struct ol_ath_softc_net80211 *scn = (struct ol_ath_softc_net80211 *)pdev;
    return scn->vow_extstats;
}

u_int32_t ol_scn_vow_get_rxstats(ol_pdev_handle pdev, u_int32_t *phy_err_count, u_int32_t *rx_clear_count, u_int32_t *rx_cycle_count)
{
    struct ol_ath_softc_net80211 *scn = (struct ol_ath_softc_net80211 *)pdev;
    *phy_err_count = scn->chan_stats.phy_err_cnt;
    *rx_clear_count = scn->mib_cycle_cnts.rx_clear_count;
    *rx_cycle_count = scn->mib_cycle_cnts.cycle_count;
    return 0;
}

#if OL_ATH_SUPPORT_LED
static OS_TIMER_FUNC(ol_ath_led_poll_timed_out)
{
    struct ol_ath_softc_net80211 *scn ;
    OS_GET_TIMER_ARG(scn, struct ol_ath_softc_net80211 *);

    if (!scn->scn_led_blink_rate_table) {
        return;
    }

    if (scn->scn_blinking != OL_BLINK_DONE)        /* don't interrupt active blink */
        return;

    ol_ath_led_event(scn, OL_ATH_LED_POLL);
}

static OS_TIMER_FUNC(ol_ath_led_blink_timed_out)
{
    struct ol_ath_softc_net80211 *scn ;
    OS_GET_TIMER_ARG(scn, struct ol_ath_softc_net80211 *);

    if (!scn->scn_led_blink_rate_table) {
        return;
    }

    switch (scn->scn_blinking) {
    case OL_BLINK_ON_START:
            scn->scn_blinking = OL_BLINK_DONE;
#if OL_ATH_SUPPORT_LED_POLL
            OS_SET_TIMER(&scn->scn_led_poll_timer, 500);
#endif
        break;
    case OL_BLINK_OFF_START:
            wmi_unified_gpio_output(scn->wmi_handle, scn->scn_led_gpio, 0);
            scn->scn_blinking = OL_BLINK_ON_START;
            OS_SET_TIMER(&scn->scn_led_blink_timer, scn->scn_led_time_on);
        break;
    case OL_BLINK_STOP:
            wmi_unified_gpio_output(scn->wmi_handle, scn->scn_led_gpio, 1);
            scn->scn_blinking = OL_BLINK_DONE;
        break;
    case OL_BLINK_DONE:
    default:
        break;
    }
}

/*
 * Blink the LED according to the specified on/off times.
 */
static void
ol_ath_led_blink(struct ol_ath_softc_net80211 *scn, u_int32_t on, u_int32_t off)
{
    wmi_unified_gpio_output(scn->wmi_handle, scn->scn_led_gpio, 1);
    scn->scn_blinking = OL_BLINK_OFF_START;
    scn->scn_led_time_on = on;
    OS_SET_TIMER(&scn->scn_led_blink_timer, off);
}

void
ol_ath_led_event(struct ol_ath_softc_net80211 *scn, OL_LED_EVENT event)
{
    u_int32_t led_last_time = CONVERT_SYSTEM_TIME_TO_MS(OS_GET_TIMESTAMP());
    u_int32_t map_idx;

    if (scn->lteu_support)
        return;

    if (scn->scn_blinking != OL_BLINK_DONE)        /* don't interrupt active blink */
        return;
    switch (event) {
    case OL_ATH_LED_TX:
    case OL_ATH_LED_RX:
            /* 1/6554 = 1000 (ms -> sec) * 8 (Byte -> Bits) / 1024 *1024 ( -> Mega) * 50 (50 Mbps per entry) */
            map_idx = scn->scn_led_byte_cnt / ((led_last_time - scn->scn_led_last_time) * 6554);
            scn->scn_led_last_time = led_last_time;
            scn->scn_led_byte_cnt = 0;
            if (map_idx < 0) {
                map_idx = 0;
            } else if (map_idx > scn->scn_led_max_blink_rate_idx) {
                map_idx = scn->scn_led_max_blink_rate_idx;
            }
            ol_ath_led_blink(scn, scn->scn_led_blink_rate_table[map_idx].timeOn, scn->scn_led_blink_rate_table[map_idx].timeOff);
        break;
    case OL_ATH_LED_POLL:
            ol_ath_led_blink(scn, 100, 500);
        break;
    default:
        break;
    }
}
#endif

#endif
