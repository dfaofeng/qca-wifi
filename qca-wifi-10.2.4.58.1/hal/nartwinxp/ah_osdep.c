/*
 * Copyright (c) 2005, Atheros Communications Inc.
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



#include "opt_ah.h"

#include "../ah.h"
#include "../ah_internal.h"

#ifdef AH_DEBUG
static	int ath_hal_debug = 0;
#else
static const int ath_hal_debug = 0;
#endif

#ifndef DEBUG_PKTLOG
#include "pktlog_hal.h"
struct ath_pktlog_halfuncs *g_pktlog_halfuncs = NULL;
#endif


/*
** Callback table used to access OS specific functions, such
** as PCI configuration space read.
*/

static struct ath_hal_callback    ath_hal_callback_table;


struct ath_hal *
_ath_hal_attach(u_int16_t devid, HAL_ADAPTER_HANDLE osdev, HAL_SOFTC sc,
                HAL_BUS_CONTEXT *bus_context,
                struct hal_reg_parm *hal_conf_parm,
                asf_amem_instance_handle amem_handle,
                const struct ath_hal_callback *callbackTable,
                void* s)
{
	HAL_STATUS status;
	struct ath_hal *ah;
	int category;

	/* 
	 * save callback table locally; 
         * can be made dynamically;
         * other handles are passed to the chip-specific routine.
	 */
	ath_hal_callback_table = *callbackTable;
	ah = ath_hal_attach(
        devid, osdev, sc, bus_context->bc_tag, bus_context->bc_handle,
        bus_context->bc_bustype, amem_handle, hal_conf_parm, &status);

#ifdef AH_DEBUG
	/*
	 * enable all the HAL print masks
 	 */
	for (category = 0; category < HAL_DBG_NUM_CATEGORIES; category++) {
		asf_print_mask_set(&AH_PRIVATE(ah)->ah_asf_print, category, 1);
	}
#endif

	*(HAL_STATUS *)s = status;
	return ah;
}

void
ath_hal_detach(struct ath_hal *ah)
{
	(*ah->ah_detach)(ah);
}


#ifdef UNUSED // #############################################
void
module_init_hal(struct hal_reg_parm* pHalParameters )
{
    /* Serialization of Register Accesses:
     *
     * Owl (ar5416) has some issues with platforms that do not correctly
     * serialize PCI register accesses. 
     *
     * Enable serialization of register accesses when the following are true:
     *      - device requires serialization (e.g. Owl 2.2 and PCI/miniPCI)
     *      - Multiprocessor/HT system
     *
     * See bug 21930 and 32666 for more information.
     * Note: register accesses are serialized using the interrupt spinlock.
     *       This means that all register accesses will not be serialized until
     *       interrupts are registered.  This should be fine as only one driver thread 
     *       should be running during intialization.
     *
     * Note: The NdisSystemProcessorCount() should be called at IRQL: PASSIVE_LEVEL and
     *       this is why this code portion is in this routine called at Passive level.
     */
    switch (pHalParameters->serializeRegMode) {

        case SER_REG_MODE_OFF:
        case SER_REG_MODE_ON:
            /* no change */
            break;

        case SER_REG_MODE_AUTO:
            /*
             * For Auto mode, we will disable this feature if single processor.
             * Note: This hardware bug is seen in hyperthreaded and multicore CPU's. 
             * The NdisSystemProcessorCount() will return >1 for hyperthreaded CPU.
             * Note: NdisSystemProcessorCount() should be called at IRQL: PASSIVE_LEVEL.
             */
            if (NdisSystemProcessorCount() == 1) {
                pHalParameters->serializeRegMode = SER_REG_MODE_OFF;
            }
            break;
    }
}
#endif	// UNUSED #############################################################


/******************************************************************************/
/*!
**  \brief Set Factory Defaults for the HAL instance
**
**  This function will set factory default values for the HAL operations
**  configuration structure, used in the operation of each HAL instance.
**  Specific values can be overriden using IOCTL interfaces, as required.
**
**  \param ahp  Pointer to HAL private data structure
**
**  \return N/A
*/

void __ahdecl
ath_hal_factory_defaults(struct ath_hal_private *ap, struct hal_reg_parm *hal_conf_parm)
{
    int i;
    
    ap->ah_config.ath_hal_dma_beacon_response_time  = 512;   /* microseconds */
    ap->ah_config.ath_hal_sw_beacon_response_time   = 10240; /* microseconds */
    ap->ah_config.ath_hal_additional_swba_backoff   = 0;     /* microseconds */
    ap->ah_config.ath_hal_6mb_ack                   = 0x0;
    ap->ah_config.ath_hal_cwm_ignore_ext_cca        = 0;
    ap->ah_config.ath_hal_rifs_enable         	    = 0;
    ap->ah_config.ath_hal_soft_eeprom               = 0;
    ap->ah_config.ath_hal_desc_tpc                  = 0;
    ap->ah_config.ath_hal_redchn_maxpwr             = 0;
    
#ifdef ATH_FORCE_BIAS
    ap->ah_config.ath_hal_forceBias                 = hal_conf_parm->forceBias;
    ap->ah_config.ath_hal_forceBiasAuto             = hal_conf_parm->forceBiasAuto;
#endif
    ap->ah_config.ath_hal_pcie_power_save_enable    = hal_conf_parm->halPciePowerSaveEnable;
    ap->ah_config.ath_hal_pcieL1SKPEnable           = hal_conf_parm->halPcieL1SKPEnable;
    ap->ah_config.ath_hal_pcie_clock_req            = hal_conf_parm->halPcieClockReq;
    ap->ah_config.ath_hal_pciePowerReset            = hal_conf_parm->halPciePowerReset;
    ap->ah_config.ath_hal_pcie_waen                 = hal_conf_parm->halPcieWaen;
    ap->ah_config.ath_hal_pcieRestore               = hal_conf_parm->halPcieRestore;
    ap->ah_config.ath_hal_pll_pwr_save              = hal_conf_parm->halPllPwrSave;
    ap->ah_config.ath_hal_ht_enable                 = hal_conf_parm->htEnable;
#ifdef ATH_SUPERG_DYNTURBO
    ap->ah_config.ath_hal_disableTurboG             = hal_conf_parm->disableTurboG;
#endif
    ap->ah_config.ath_hal_ofdmTrigLow               = hal_conf_parm->ofdmTrigLow;
    ap->ah_config.ath_hal_ofdmTrigHigh              = hal_conf_parm->ofdmTrigHigh;
    ap->ah_config.ath_hal_cckTrigHigh               = hal_conf_parm->cckTrigHigh;
    ap->ah_config.ath_hal_cckTrigLow                = hal_conf_parm->cckTrigLow;
    ap->ah_config.ath_hal_enable_ani                = hal_conf_parm->enableANI;
    ap->ah_config.ath_hal_noiseImmunityLvl          = hal_conf_parm->noiseImmunityLvl;
    ap->ah_config.ath_hal_ofdmWeakSigDet            = hal_conf_parm->ofdmWeakSigDet;
    ap->ah_config.ath_hal_cckWeakSigThr             = hal_conf_parm->cckWeakSigThr;
    ap->ah_config.ath_hal_spurImmunityLvl           = hal_conf_parm->spurImmunityLvl;
    ap->ah_config.ath_hal_firStepLvl                = hal_conf_parm->firStepLvl;
    ap->ah_config.ath_hal_rssiThrHigh               = hal_conf_parm->rssiThrHigh;
    ap->ah_config.ath_hal_rssiThrLow                = hal_conf_parm->rssiThrLow;
    ap->ah_config.ath_hal_diversity_control         = hal_conf_parm->diversityControl;
    ap->ah_config.ath_hal_antenna_switch_swap       = hal_conf_parm->antennaSwitchSwap;
    for (i=0; i< AR_EEPROM_MODAL_SPURS; i++) {
        ap->ah_config.ath_hal_spur_chans[i][0] = AR_NO_SPUR;
        ap->ah_config.ath_hal_spur_chans[i][1] = AR_NO_SPUR;
    }
    ap->ah_config.ath_hal_serialize_reg_mode          = hal_conf_parm->serializeRegMode;
    ap->ah_config.ath_hal_defaultAntCfg             = hal_conf_parm->defaultAntCfg;
    ap->ah_config.ath_hal_fastClockEnable           = hal_conf_parm->fastClockEnable;
    ap->ah_config.ath_hal_mfp_support                = hal_conf_parm->hwMfpSupport;
    ap->ah_config.ath_hal_enable_msi                 = 0;
    ap->ah_config.ath_hal_keep_alive_timeout          = 60000;  /* 60 seconds */
}

void
module_exit_hal(void)
{
}

#include <stdarg.h>
#include "ErrorPrint.h"

const char* __ahdecl ath_hal_ether_sprintf(const u_int8_t *mac)
{
	static char *address="address";

	return address;
}

/*
 * Print/log message support.
 */
void __ahdecl
ath_hal_vprintf(struct ath_hal *ah, const char* fmt, va_list ap)
{
#define MBUFFER 1024
    char buffer[MBUFFER];

#ifdef UNUSED
    RtlStringCbVPrintfA(buf, sizeof(buf), fmt, ap);
#else
//	vprintf(fmt,ap);
    _vsnprintf(buffer,MBUFFER-1,fmt,ap);
    buffer[MBUFFER-1]=0;
	ErrorPrint(ErrorNone,buffer);
#endif
#ifdef AH_DEBUG
//    uiPrintf(buf);
#endif
    return;
}


void __ahdecl
ath_hal_printf(struct ath_hal *ah, const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	ath_hal_vprintf(ah, fmt, ap);
	va_end(ap);
}

#ifdef UNUSED
/*
 * Format an Ethernet MAC for printing.
 */
const char* __ahdecl
ath_hal_ether_sprintf(const u_int8_t *mac)
{
	static char etherbuf[18];

        RtlStringCbPrintfA(etherbuf, sizeof(etherbuf), "%02x:%02x:%02x:%02x:%02x:%02x", 
		mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

	return etherbuf;
}
#endif

#ifdef AH_ASSERT
void __ahdecl
ath_hal_assert_failed(const char* filename, int lineno, const char *msg)
{
        ath_hal_printf(NULL, "Atheros HAL assertion failure: %s: line %u: %s\n",
		filename, lineno, msg);

//	panic("ath_hal_assert");
}
#endif /* AH_ASSERT */

#ifdef AH_DEBUG_ALQ
/*
 * ALQ register tracing support.
 *
 * Setting hw.ath.hal.alq=1 enables tracing of all register reads and
 * writes to the file /tmp/ath_hal.log.  The file format is a simple
 * fixed-size array of records.  When done logging set hw.ath.hal.alq=0
 * and then decode the file with the ardecode program (that is part of the
 * HAL).  If you start+stop tracing the data will be appended to an
 * existing file.
 *
 * NB: doesn't handle multiple devices properly; only one DEVICE record
 *     is emitted and the different devices are not identified.
 */
#include "alq/alq.h"
#include "ah_decode.h"

static	struct alq *ath_hal_alq;
static	int ath_hal_alq_emitdev;	/* need to emit DEVICE record */
static	u_int ath_hal_alq_lost;		/* count of lost records */
static	const char *ath_hal_logfile = "/tmp/ath_hal.log";
static	u_int ath_hal_alq_qsize = 8*1024;

static int
ath_hal_setlogging(int enable)
{
	int error;

	if (enable) {
		if (!capable(CAP_NET_ADMIN))
			return -EPERM;
		error = alq_open(&ath_hal_alq, ath_hal_logfile,
				sizeof (struct athregrec), ath_hal_alq_qsize);
		ath_hal_alq_lost = 0;
		ath_hal_alq_emitdev = 1;
		printk("ath_hal: logging to %s %s\n", ath_hal_logfile,
			error == 0 ? "enabled" : "could not be setup");
	} else {
		if (ath_hal_alq)
			alq_close(ath_hal_alq);
		ath_hal_alq = NULL;
		printk("ath_hal: logging disabled\n");
		error = 0;
	}
	return error;
}

/*
 * Deal with the sysctl handler api changing.
 */
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,8)
#define	AH_SYSCTL_ARGS_DECL \
	ctl_table *ctl, int write, struct file *filp, void *buffer, \
		size_t *lenp
#define	AH_SYSCTL_ARGS		ctl, write, filp, buffer, lenp
#else /* LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,8) */
#define	AH_SYSCTL_ARGS_DECL \
	ctl_table *ctl, int write, struct file *filp, void *buffer,\
		size_t *lenp, loff_t *ppos
#define	AH_SYSCTL_ARGS		ctl, write, filp, buffer, lenp, ppos
#endif /* LINUX_VERSION_CODE */

static int
sysctl_hw_ath_hal_log(AH_SYSCTL_ARGS_DECL)
{
	int error, enable;

	ctl->data = &enable;
	ctl->maxlen = sizeof(enable);
	enable = (ath_hal_alq != NULL);
        error = proc_dointvec(AH_SYSCTL_ARGS);
        if (error || !write)
                return error;
	else
		return ath_hal_setlogging(enable);
}

static struct ale *
ath_hal_alq_get(struct ath_hal *ah)
{
	struct ale *ale;

	if (ath_hal_alq_emitdev) {
		ale = alq_get(ath_hal_alq, ALQ_NOWAIT);
		if (ale) {
			struct athregrec *r =
				(struct athregrec *) ale->ae_data;
			r->op = OP_DEVICE;
			r->reg = 0;
			r->val = AH_PRIVATE(ah)->ah_devid;
			alq_post(ath_hal_alq, ale);
			ath_hal_alq_emitdev = 0;
		} else
			ath_hal_alq_lost++;
	}
	ale = alq_get(ath_hal_alq, ALQ_NOWAIT);
	if (!ale)
		ath_hal_alq_lost++;
	return ale;
}

void __ahdecl
ath_hal_reg_write(struct ath_hal *ah, u_int32_t reg, u_int32_t val)
{
	if (ath_hal_alq) {
		unsigned long flags;
		struct ale *ale;

		local_irq_save(flags);
		ale = ath_hal_alq_get(ah);
		if (ale) {
			struct athregrec *r = (struct athregrec *) ale->ae_data;
			r->op = OP_WRITE;
			r->reg = reg;
			r->val = val;
			alq_post(ath_hal_alq, ale);
		}
		local_irq_restore(flags);
	}
	_OS_REG_WRITE(ah, reg, val);
}

u_int32_t __ahdecl
ath_hal_reg_read(struct ath_hal *ah, u_int32_t reg)
{
	u_int32_t val;

	val = _OS_REG_READ(ah, reg);
	if (ath_hal_alq) {
		unsigned long flags;
		struct ale *ale;

		local_irq_save(flags);
		ale = ath_hal_alq_get(ah);
		if (ale) {
			struct athregrec *r = (struct athregrec *) ale->ae_data;
			r->op = OP_READ;
			r->reg = reg;
			r->val = val;
			alq_post(ath_hal_alq, ale);
		}
		local_irq_restore(flags);
	}
	return val;
}

void __ahdecl
OS_MARK(struct ath_hal *ah, u_int id, u_int32_t v)
{
	if (ath_hal_alq) {
		unsigned long flags;
		struct ale *ale;

		local_irq_save(flags);
		ale = ath_hal_alq_get(ah);
		if (ale) {
			struct athregrec *r = (struct athregrec *) ale->ae_data;
			r->op = OP_MARK;
			r->reg = id;
			r->val = v;
			alq_post(ath_hal_alq, ale);
		}
		local_irq_restore(flags);
	}
}
#elif defined(AH_DEBUG) || defined(AH_REGOPS_FUNC)
/*
 * Memory-mapped device register read/write.  These are here
 * as routines when debugging support is enabled and/or when
 * explicitly configured to use function calls.  The latter is
 * for architectures that might need to do something before
 * referencing memory (e.g. remap an i/o window).
 *
 * NB: see the comments in ah_osdep.h about byte-swapping register
 *     reads and writes to understand what's going on below.
 */
void __ahdecl
ath_hal_reg_write(struct ath_hal *ah, u_int reg, u_int32_t val)
{
#ifdef AH_DEBUG
	if (ath_hal_debug > 1)
		ath_hal_printf(ah, "WRITE 0x%x <= 0x%x\n", reg, val);
#endif

	if (AH_PRIVATE(ah)->ah_reg_write_buffer_flag) { 
		_OS_REG_WRITE_DELAY(ah, reg, val); 
	}
	else {
		_OS_REG_WRITE(ah, reg, val); 
	}
}

u_int32_t __ahdecl
ath_hal_reg_read(struct ath_hal *ah, u_int reg)
{
 	u_int32_t val;

	val = _OS_REG_READ(ah, reg);
#ifdef AH_DEBUG
	if (ath_hal_debug > 1)
		ath_hal_printf(ah, "READ 0x%x => 0x%x\n", reg, val);
#endif
	return val;
}
#endif /* AH_DEBUG || AH_REGOPS_FUNC */

#ifdef AH_DEBUG
void __ahdecl
HALDEBUG(struct ath_hal *ah, const char* fmt, ...)
{
    if (ath_hal_debug) {
        __va_list ap;
        va_start(ap, fmt);
        ath_hal_vprintf(ah, fmt, ap);
        va_end(ap);
    }
}
#endif /* AH_DEBUG */

#ifdef UNUSEDSRC3
/*
 * Allocate/free memory.
 */

void * __ahdecl
ath_hal_malloc(struct ath_hal *ah, size_t size)
{
    void *p;

    p = OS_MALLOC(ah->osdev, (u_int32_t)size, 0);
    if (p != NULL) {
        OS_MEMZERO(p, size);
    }
    return p;
}

void __ahdecl
ath_hal_free(struct ath_hal *ah, void* p)
{
    OS_FREE(p);
}
#endif

u_int32_t
ath_hal_read_pci_config_space(struct ath_hal *ah, u_int32_t offset, void *pBuffer, u_int32_t length)
{
    u_int32_t bytesRead = 0;

    if (ath_hal_callback_table.read_pci_config_space != NULL) {
        bytesRead = ath_hal_callback_table.read_pci_config_space(
            AH_PRIVATE(ah)->ah_sc, offset, pBuffer, length);
    }

    return (bytesRead);
}

typedef struct regAccess {
    struct ath_hal  *ah;
    u_int32_t       off;
    u_int32_t       val;
} REG_ACCESS;



static void (*_RegisterDebug)(unsigned long address, unsigned long before, unsigned long after);

void HalRegisterDebug(void (*f)(unsigned long address, unsigned long before, unsigned long after))
{
    _RegisterDebug=f;
}

static void writeReg(REG_ACCESS *reg)
{
#ifdef UNUSED
    *((volatile u_int32_t *)(AH_PRIVATE(reg->ah)->ah_sh + reg->off)) = reg->val;
#else
	unsigned long *rptr, value;

	rptr=(unsigned long *)(AH_PRIVATE(reg->ah)->ah_sh + reg->off);
	value=reg->val;
	if(_RegisterDebug!=0)
	{
		(*_RegisterDebug)(reg->off,*((volatile u_int32_t *)(rptr)),reg->val);
	}
    *((volatile u_int32_t *)(rptr)) = reg->val;
#endif
}

static void readReg(REG_ACCESS *reg)
{
    reg->val = (*((volatile u_int32_t *)(AH_PRIVATE(reg->ah)->ah_sh + (reg->off))));
}

void __ahdecl
writePlatformRegDelay(struct ath_hal *ah, u_int32_t reg, u_int32_t val)
{
    ath_hal_wmi_reg_write_delay(ah, reg, val);
}

void __ahdecl
writePlatformRegFlush(struct ath_hal *ah)
{
    ath_hal_wmi_reg_write_flush(ah);
}

void __ahdecl
writePlatformReg(struct ath_hal *ah, u_int32_t reg, u_int32_t val)
{
#ifdef ATH_SUPPORT_HTC
    ath_hal_wmi_reg_write(ah, reg, val);
#else
    REG_ACCESS  regStruc;
#ifdef UNUSED
    osdev_t     osdev = (osdev_t)AH_PRIVATE(ah)->ah_osdev;
#endif

    regStruc.ah = ah;
    regStruc.val = val;
    regStruc.off = reg;

#ifdef UNUSED
    if ((AH_PRIVATE(ah)->ah_config.ath_hal_serialize_reg_mode == SER_REG_MODE_ON) && 
        osdev && osdev->InterruptRegistered && (KeGetCurrentIrql() <= DISPATCH_LEVEL)) {
        NdisMSynchronizeWithInterrupt(&osdev->Interrupt, writeReg, &regStruc);
    } else 
#endif
	{
        writeReg(&regStruc);
    }    
#endif
}

u_int32_t __ahdecl
readPlatformRegOnce(struct ath_hal *ah, u_int32_t reg)
{
#ifdef ATH_SUPPORT_HTC
    u_int32_t val;

    val = ath_hal_wmi_reg_read(ah, reg);

    return val;
#else
    REG_ACCESS      regStruc;
#ifdef UNUSED
    osdev_t         osdev = (osdev_t)AH_PRIVATE(ah)->ah_osdev;
#endif
    
    regStruc.ah = ah;
    regStruc.off = reg;

#ifdef UNUSED
    if ((AH_PRIVATE(ah)->ah_config.ath_hal_serialize_reg_mode == SER_REG_MODE_ON) &&
        osdev && osdev->InterruptRegistered && (KeGetCurrentIrql() <= DISPATCH_LEVEL)) {
        /* Synchronize all Registers Accesses with the ISR */
        NdisMSynchronizeWithInterrupt(&osdev->Interrupt, readReg, &regStruc);
    } else 
#endif
	{
        readReg(&regStruc);
    }
    return regStruc.val;
#endif
}

/* This function read the BB register up to 10 times. If the last two times 
 * return same values, then we regard the value as the reliable value of the
 * register and stop the loop. From the test, I can see the maximum reading 
 * times is 3 times. To do the test, please change
 * #define DEBUG_BB_REG 1
 * This WAR is for bug 34967 and may solve other bugs as unreliable BB register
 * value could cause any kind of strange behavior.
 * The recursive reading is applied to all BB register now except 0x99dc. 
 * Hardware people may want to exclude more later. 
 */
#define DEBUG_BB_REG 0
#define READ_REG_NUM 9
#define AR_BB_START_ADDR 0x9800

u_int32_t __ahdecl
readPlatformReg(struct ath_hal *ah, u_int32_t reg)
{
    u_int32_t       regval1, regval2=0;
    int i;
#if DEBUG_BB_REG
    int j;
    u_int32_t       regval[10];
#endif
    
    if (reg < AR_BB_START_ADDR || reg == 0x99dc || reg == 0x9860) {
        return (readPlatformRegOnce(ah, reg));
    }

    regval1 = readPlatformRegOnce(ah, reg);

#if DEBUG_BB_REG
    regval[0] = regval1;
#endif

    for (i=0; i<READ_REG_NUM; i++) {
        regval2 = readPlatformRegOnce(ah, reg);
 
#if DEBUG_BB_REG
        regval[i+1] = regval2;
#endif
        if (regval1 == regval2) {
#if DEBUG_BB_REG
            if (i>0) {
                printk("*** Read 0x%0x %d times to get right regval!\n", reg, i+1);
                for (j =0; j< i+1; j++ ) {
                    printk("regval 0x%0x  ", regval[j]);
                }
                printk("\n");
            }
#endif
            return regval2;
        }
         regval1 = regval2;
     }

    printk("******!!! Can not get Reg 0x%0x right value!\n", reg, i+1);

    return regval2;
}

void asf_vprint_category_private(
    struct asf_print_ctrl *handle,
    unsigned category,
    const char *fmt,
	va_list args){}
void asf_print_ctrl_register_private(
    struct asf_print_instance *handle,
	struct asf_print_ctrl *p){}
void asf_print_mask_set(
    struct asf_print_ctrl *handle,
    int category,
	int enable){}
extern int asf_print_ctrl_unregister_private(
    struct asf_print_instance *handle,
	struct asf_print_ctrl *p){return 0;}
