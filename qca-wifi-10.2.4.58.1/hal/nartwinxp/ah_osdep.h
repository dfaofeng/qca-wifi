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

#ifndef _ATH_AH_OSDEP_H_
#define _ATH_AH_OSDEP_H_

#include <osdep.h>
#include <asf_amem.h>

extern void HalRegisterDebug(void (*f)(unsigned long address, unsigned long before, unsigned long after));


/*
 * Atheros Hardware Access Layer (HAL) OS Dependent Definitions.
 */

/*
 * We're releasing binary HAL as a stand-alone module, so we don't
 * need to worry about compatibilities regarding calling convention.
 * By default, Windows uses PASCAL convention.
 */
#ifndef __ahdecl
#define __ahdecl
#endif

#define __va_list   va_list 
#define OS_INLINE   __inline
#define inline      __inline
#define __printflike(_a,_b)


/* no-ops */
#define HAL_USE_INTERSPERSED_READS
#define HAL_NO_INTERSPERSED_READS

typedef void*       HAL_SOFTC;
typedef unsigned long    HAL_BUS_HANDLE;		// th 090716, ?????
typedef void*       HAL_ADAPTER_HANDLE;
typedef u_int32_t   HAL_BUS_ADDR;		 /* XXX architecture dependent */
typedef void *      HAL_BUS_TAG;

/* 
 * Supported Bus types
 */
typedef enum ath_hal_bus_type {
   HAL_BUS_TYPE_PCI,
   HAL_BUS_TYPE_AHB
} HAL_BUS_TYPE;


/*
 * Bus to hal context handoff
 */
typedef struct hal_bus_context {
    HAL_BUS_TAG     bc_tag;
    HAL_BUS_HANDLE  bc_handle;
    HAL_BUS_TYPE    bc_bustype;
} HAL_BUS_CONTEXT;

#ifndef abs
#define abs(_a)       ( (_a) < 0 ? -(_a) : (_a) )
#endif

struct ath_hal;
struct hal_reg_parm {
    u_int8_t             halPciePowerSaveEnable;             // Program Serdes; Use ASPM
    u_int8_t             halPcieL1SKPEnable;                 // Enable L1 SKP workaround
    u_int32_t            halPciePowerReset;
    u_int8_t             halPcieClockReq;
    u_int32_t            halPcieWaen;
    u_int8_t             halPcieRestore;
    u_int8_t             halPllPwrSave;
    u_int8_t             htEnable;			     // Enable/disable 11n mode
    u_int32_t            ofdmTrigLow;
    u_int32_t            ofdmTrigHigh;
    u_int32_t            cckTrigHigh;
    u_int32_t            cckTrigLow;
    u_int32_t            enableANI;
    u_int8_t             noiseImmunityLvl;
    u_int32_t            ofdmWeakSigDet;
    u_int32_t            cckWeakSigThr;
    u_int8_t             spurImmunityLvl;
    u_int8_t             firStepLvl;
    int8_t               rssiThrHigh;
    int8_t               rssiThrLow;
    u_int16_t            diversityControl;                // Enable/disable antenna diversity
    u_int16_t            antennaSwitchSwap; 
    u_int32_t            forceBias;
    u_int32_t            forceBiasAuto;
#ifdef ATH_SUPERG_DYNTURBO
    u_int8_t             disableTurboG;
#endif        
    u_int8_t             serializeRegMode;
    u_int8_t             defaultAntCfg;
    u_int32_t            fastClockEnable;
    u_int32_t            hwMfpSupport;
    int                  calInFlash;
#ifdef ATH_SUPPORT_TxBF        
    u_int8_t             CVTimeOut;
    u_int16_t            TxBFCtl;
#endif
};

/*
 * Byte order/swapping support.
 */
#define	AH_LITTLE_ENDIAN    1234
#define	AH_BIG_ENDIAN       4321

#if AH_BYTE_ORDER == AH_BIG_ENDIAN
/*
 * This could be optimized but since we only use it for
 * a few registers there's little reason to do so.
 */
static OS_INLINE u_int32_t
__bswap32(u_int32_t _x)
{
    return ((u_int32_t)(
          (((const u_int8_t *)(&_x))[0]    ) |
          (((const u_int8_t *)(&_x))[1]<< 8) |
          (((const u_int8_t *)(&_x))[2]<<16) |
          (((const u_int8_t *)(&_x))[3]<<24))
    );
}

#else
#define __bswap32(_x)	(_x)
#endif

void __ahdecl
writePlatformReg(struct ath_hal *ah, u_int32_t reg, u_int32_t val);

u_int32_t __ahdecl
readPlatformRegOnce(struct ath_hal *ah, u_int32_t reg);

u_int32_t __ahdecl
readPlatformReg(struct ath_hal *ah, u_int32_t reg);

void __ahdecl
writePlatformRegDelay(struct ath_hal *ah, u_int32_t reg, u_int32_t val);

void __ahdecl
writePlatformRegFlush(struct ath_hal *ah);

/*
 * Register read/write; we assume the registers will always
 * be memory-mapped.  Note that register accesses are done
 * using target-specific functions when debugging is enabled
 * (AH_DEBUG) or we are explicitly configured this way.  The
 * latter is used on some platforms where the full i/o space
 * cannot be directly mapped.
 *
 * The hardware registers are native little-endian byte order.
 * Big-endian hosts are handled by enabling hardware byte-swap
 * of register reads and writes at reset.  But the PCI clock
 * domain registers are not byte swapped!  Thus, on big-endian
 * platforms we have to byte-swap thoese registers specifically.
 * Most of this code is collapsed at compile time because the
 * register values are constants.
 */

/* _OS_REG_READ(pd, off) read the BB register up to 10 times. If the last two times 
 * return same values, then we regard the value as the reliable value of the
 * register and stop the loop. From the test, I can see the maximum reading 
 * times is 3 times. 
 * This WAR is for bug 34967 and may solve other bugs as unreliable BB register
 * value could cause any kind of strange behavior.
 * The recursive reading is applied to all BB register now except 0x99dc. 
 * Hardware people may want to exclude more later. 
 * If any register (like fast value change register) is not suitable for 
 * multiple read, please use _OS_REG_READ_ONCE(pd, off).
 */

/* Work around for issue #28654 - sometimes the value read for the
 * register PHY_DESIRED_SZ (0x9850) is not correct which makes ANI to
 * write back the bad value. This degrades the RX performance.
 * So using multiple read to get the reliable register value.
 */

#if AH_BYTE_ORDER == AH_BIG_ENDIAN
#define _OS_REG_WRITE(_ah, _reg, _val) do {                 \
    if ( (_reg) >= 0x4000 && (_reg) < 0x5000)               \
        writePlatformReg(_ah, _reg, __bswap32(_val));       \
    else                                                    \
        writePlatformReg(_ah, _reg, _val);                  \
} while (0)

#ifdef ATH_SUPPORT_HTC
#define _OS_REG_WRITE_DELAY(_ah, _reg, _val) do { \
    writePlatformRegDelay(_ah, _reg, _val);       \
} while (0)

#define _OS_REG_WRITE_FLUSH(_ah) do {             \
    writePlatformRegFlush(_ah);                   \
} while (0)
#else
#define _OS_REG_WRITE_DELAY(_ah, _reg, _val) _OS_REG_WRITE(_ah, _reg, _val)
#define _OS_REG_WRITE_FLUSH(_ah)
#endif /* ATH_SUPPORT_HTC */

#define _OS_REG_READ_ONCE(_ah, _reg) 						\
    (((_reg) >= 0x4000 && (_reg) < 0x5000) ?                \
        __bswap32(readPlatformRegOnce(_ah, _reg)) :         \
        readPlatformRegOnce(_ah, _reg))

#ifdef WAR_BB_REG_READ_CORRUPT
#define _OS_REG_READ(_ah, _reg) \
    (((_reg) >= 0x4000 && (_reg) < 0x5000) ?                \
        __bswap32(readPlatformReg(_ah, _reg)) :             \
        readPlatformReg(_ah, _reg))
#else
#define _OS_REG_READ(_ah, _reg) \
    (((_reg) >= 0x4000 && (_reg) < 0x5000) ?                \
        __bswap32(readPlatformRegOnce(_ah, _reg)) :         \
        readPlatformRegOnce(_ah, _reg))
#endif

#else /* AH_LITTLE_ENDIAN */
#define _OS_REG_WRITE(_ah, _reg, _val) do { \
    writePlatformReg(_ah, _reg, _val); \
} while (0)

#ifdef ATH_SUPPORT_HTC
#define _OS_REG_WRITE_DELAY(_ah, _reg, _val) do { \
    writePlatformRegDelay(_ah, _reg, _val);       \
} while (0)

#define _OS_REG_WRITE_FLUSH(_ah) do {             \
    writePlatformRegFlush(_ah);                   \
} while (0)
#else
#define _OS_REG_WRITE_DELAY(_ah, _reg, _val) _OS_REG_WRITE(_ah, _reg, _val)
#define _OS_REG_WRITE_FLUSH(_ah)
#endif /* ATH_SUPPORT_HTC */

#define _OS_REG_READ_ONCE(_ah, _reg) \
    readPlatformRegOnce(_ah, _reg)

#ifdef WAR_BB_REG_READ_CORRUPT
#define _OS_REG_READ(_ah, _reg) \
    readPlatformReg(_ah, _reg)
#else
#define _OS_REG_READ(_ah, _reg) \
    readPlatformRegOnce(_ah, _reg)
#endif

#endif /* AH_BYTE_ORDER */

#ifndef ATH_SUPPORT_HTC

    /* no-op for non-USB solutions */
    #define ENABLE_REG_WRITE_BUFFER
    #define DISABLE_REG_WRITE_BUFFER
    #define OS_REG_WRITE_FLUSH(_ah)
    #define HTC_SET_PS_STATE(_ah, _mode)

#else /* #ifdef ATH_SUPPORT_HTC */

#define ENABLE_REG_WRITE_BUFFER                                                      \
    if (!AH_PRIVATE(ah)->ah_reg_write_buffer_flag)                                   \
        AH_PRIVATE(ah)->ah_reg_write_buffer_flag = 1;                                \
	else                                                                             \
		HDPRINTF(ah, HAL_DBG_REG_IO,                                                 \
                    "%s: Error:REG_WRITE_BUFFER had not been correctly disabled!\n", \
                    __func__);                                                       

#define DISABLE_REG_WRITE_BUFFER                                                     \
    if (AH_PRIVATE(ah)->ah_reg_write_buffer_flag)                                    \
        AH_PRIVATE(ah)->ah_reg_write_buffer_flag = 0;                                \
	else                                                                             \
		HDPRINTF(ah, HAL_DBG_REG_IO,                                                 \
                    "%s: Error:REG_WRITE_BUFFER had not been correctly disabled!\n", \
                    __func__);                                                       

#define OS_REG_WRITE_FLUSH(_ah)                                                      \
    if (AH_PRIVATE(_ah)->ah_reg_write_buffer_flag)                                   \
        { _OS_REG_WRITE_FLUSH(_ah); }                                                \
    else                                                                             \
		HDPRINTF(ah, HAL_DBG_REG_IO,                                                 \
                    "%s: Error:REG_WRITE_BUFFER musat be enabled!\n",                \
                    __func__)                                                       

extern void ath_hal_wmi_ps_set_state(struct ath_hal *ah, u_int16_t mode);

#define HTC_SET_PS_STATE(_ah, _mode)\
    ath_hal_wmi_ps_set_state(_ah, _mode);
#endif /* #ifdef ATH_SUPPORT_HTC */

#if defined(AH_DEBUG) || defined(AH_REGOPS_FUNC) || defined(AH_DEBUG_ALQ)
/* use functions to do register operations */
#define OS_REG_WRITE(_ah, _reg, _val)   ath_hal_reg_write(_ah, _reg, _val)
#define OS_REG_READ(_ah, _reg)          ath_hal_reg_read(_ah, _reg)

extern  void __ahdecl ath_hal_reg_write(struct ath_hal *ah,
        u_int reg, u_int32_t val);
extern  u_int32_t __ahdecl ath_hal_reg_read(struct ath_hal *ah, u_int reg);
#else
/* inline register operations */
    #define OS_REG_READ(_ah, _reg)          _OS_REG_READ(_ah, _reg)

#ifndef ATH_SUPPORT_HTC

    /* no-op for non-USB solutions */
    #define OS_REG_WRITE(_ah, _reg, _val) _OS_REG_WRITE(_ah, _reg, _val)        

#else /* #ifdef ATH_SUPPORT_HTC */

#define OS_REG_WRITE(_ah, _reg, _val)                                                \
    ath_hal_htc_reg_write(_ah, _reg, _val)

#endif /* #ifdef ATH_SUPPORT_HTC */

#endif  /* AH_DEBUG || AH_REGFUNC || AH_DEBUG_ALQ */

#ifdef AH_DEBUG_ALQ
extern  void __ahdecl OS_MARK(struct ath_hal *, u_int id, u_int32_t value);
#else
#define	OS_MARK(_ah, _id, _v)
#endif

/*
 * Linux-specific attach/detach methods needed for module reference counting.
 *
 * XXX We can't use HAL_STATUS because the type isn't defined at this
 *     point (circular dependency); we wack the type and patch things
 *     up in the function.
 *
 * NB: These are intentionally not marked __ahdecl since they are
 *     compiled with the default calling convetion and are not called
 *     from within the HAL.
 */
typedef u_int32_t (*HAL_BUS_CONFIG_READER)(HAL_SOFTC sc, u_int32_t offset, void *pBuffer, u_int32_t length);

struct ath_hal_callback {
    /* Callback Functions */
    HAL_BUS_CONFIG_READER read_pci_config_space;
};

extern  struct ath_hal *_ath_hal_attach(u_int16_t devid,
                                        HAL_ADAPTER_HANDLE osdev, 
                                        HAL_SOFTC,
                                        HAL_BUS_CONTEXT *bus_context,
                                        struct hal_reg_parm *hal_conf_parm,
                                        asf_amem_instance_handle amem_handle,
                                        const struct ath_hal_callback *,
                                        void* status);
extern  void ath_hal_detach(struct ath_hal *);
extern  void module_init_hal(struct hal_reg_parm* pHalParameters);
extern void HalRegisterDebug(void (*f)(unsigned long address, unsigned long before, unsigned long after));

#ifdef ATH_SUPPORT_HTC
extern void ath_hal_wmi_reg_write_delay(struct ath_hal *ah, u_int reg, u_int32_t val);
extern void ath_hal_wmi_reg_write_flush(struct ath_hal *ah);
extern void ath_hal_wmi_reg_write(struct ath_hal *ah, u_int reg, u_int32_t val);
extern u_int32_t ath_hal_wmi_reg_read(struct ath_hal *ah, u_int reg);
#else
#define ath_hal_wmi_reg_write_delay(_ah, _reg, _val)
#define ath_hal_wmi_reg_write_flush(_ah)
#define ath_hal_wmi_reg_write(_ah, _reg, _val)
#define ath_hal_wmi_reg_read(_ah, _reg)
#endif

#ifndef REMOVE_PKT_LOG
#define hal_log_ani(_hal_sc, _hal_log_data, _flags)
#endif

/*
 * Atomic interface
 */
typedef long os_atomic_t;

//#ifdef UNUSED
#define OS_ATOMIC_READ(_patomic_arg)           (*(_patomic_arg))
#define OS_ATOMIC_SET(_patomic_arg, v)         ((*(_patomic_arg))=v)
#ifdef UNUSED
#define OS_ATOMIC_SET(_patomic_arg, v)         InterlockedExchange(_patomic_arg, (v))
#define OS_ATOMIC_ADD(v, _patomic_arg)         InterlockedExchangeAdd(_patomic_arg, (v))
#define OS_ATOMIC_DEC_AND_TEST(_patomic_arg)   (NdisInterlockedDecrement(_patomic_arg) == 0)

#define OS_CMPXCHG(_m, _old, _new)             InterlockedCompareExchange(_m, _new, _old)
#else
#define OS_ATOMIC_INC(_patomic_arg)            ((*(_patomic_arg))++)
#define OS_ATOMIC_DEC(_patomic_arg)            ((*(_patomic_arg))--)
#endif


/*
 * Calculation of array length
 */
#ifndef ARRAY_LENGTH
#define ARRAY_LENGTH(a)         (sizeof(a) / sizeof((a)[0]))
#endif

#endif /* _ATH_AH_OSDEP_H_ */
