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

//
// copied from winvista/osdep.h		th 090715
//
// modeified to work in nart environment
//

#ifndef _ATH_WINVISTA_OSDEP_H
#define _ATH_WINVISTA_OSDEP_H

/*
 * Globally disabled warnings
 * These are superfluous errors at warning level 4.
 */
#pragma warning(disable:4214)   // bit field types other than int
#pragma warning(disable:4200)   // non-standard extension used
#pragma warning(disable:4201)   // nameless struct/union
#pragma warning(disable:4115)   // named type definition in parentheses
#pragma warning(disable:4127)   // conditional expression is constant
#pragma warning(disable:4054)   // cast of function pointer to PVOID
#pragma warning(disable:4206)   // translation unit is empty
#pragma warning(disable:4242)   // possible data loss because of data conversion
#pragma warning(disable:4244)   // possible data loss because of data conversion
#pragma warning(disable:4245)   // signed/unsigned mismatch
#pragma warning(disable:4100)   // unreferenced formal parameter
#pragma warning(disable:4101)   // unreferenced local variable
#pragma warning(disable:4189)   // a variable is initialized but not referenced
#pragma warning(disable:4018)   // signed/unsigned mismatch during comparison
#pragma warning(disable:4389)   // signed/unsigned mismatch during assignment
#pragma warning(disable:4293)   // shift count negative or too big
#pragma warning(error  :4020)
#pragma warning(error  :4024)
#pragma warning(error  :4133)
#pragma warning(error  :4028)
#pragma warning(error  :4022)
#pragma warning(error  :4047)
#pragma warning(error  :4701)

#ifdef UNUSED	// ############################################################################################################
/*
 * For making calls into NDIS
 */
#include <ndis.h>
#include <ntstrsafe.h>

#include "compat.h"
#endif	// UNUSED ############################################################################################################

#ifndef WIN32
#error This module must be compiled in a WIN32/NDIS context.
#endif

#define AH_UNREF_PARAM(_x) UNREFERENCED_PARAMETER(_x)

/* Windows has a different packing technology */
#define __packed
#define INLINE  __inline

/*
 * Data Types
 */

typedef unsigned long dma_addr_t;	// th 091118 added this one for src3

typedef unsigned int size_t;	// th 090715 added this one
/*typedef unsigned int * uintptr_t; */
//typedef unsigned long osdev_t;

typedef char int8_t;
typedef short int16_t;
typedef long int32_t;
typedef __int64 int64_t;		// th 090715 this is wrong, but we dont seem to have a long long type

typedef unsigned char u_int8_t, uint8_t;
typedef unsigned short u_int16_t, uint16_t;
typedef unsigned long u_int32_t, uint32_t;
typedef unsigned __int64 u_int64_t;// th 090715 this is wrong, but we dont seem to have a long long type
typedef unsigned int u_int;

/* shorthands */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned __int64 u64;// th 090715 this is wrong, but we dont seem to have a long long type
typedef unsigned long u32;

typedef enum {
    false = 0,
    true  = 1
} bool;

#ifndef offsetof
#define    offsetof(type, field)    ((size_t)(&((type *)0)->field))
#endif

#define ATH_FLUSH_FIFO()

/*
 * Byte Order stuff
 * NDIS doesn't even have byte swapping functions!
 * 
 * XXX: We use swapb instead of bswap just because
 * bswap is already taken by HAL and re-define it
 * would cause more problems!
 */
static INLINE u_int16_t
__swapb16(u_int16_t _x)
{
    return (u_int16_t)(
        ((_x & 0x00ff) << 8) |
        ((_x & 0xff00) >> 8)
        );
}

static INLINE u_int32_t
__swapb32(u_int32_t _x)
{
    return (u_int32_t)(
        ((_x & 0x000000ff) << 24) |
        ((_x & 0x0000ff00) << 8) |
        ((_x & 0x00ff0000) >> 8) |
        ((_x & 0xff000000) >> 24)
        );
}

static INLINE u_int64_t
__swapb64(u_int64_t _x)
{
    return (u_int64_t)(
        ((_x & 0x00000000000000ff) << 56) |
        ((_x & 0x000000000000ff00) << 40) |
        ((_x & 0x0000000000ff0000) << 24) |
        ((_x & 0x00000000ff000000) << 8) |
        ((_x & 0x000000ff00000000) >> 8) |
        ((_x & 0x0000ff0000000000) >> 24) |
        ((_x & 0x00ff000000000000) >> 40) |
        ((_x & 0xff00000000000000) >> 56)
        );
}

#define __LITTLE_ENDIAN

#define    _LITTLE_ENDIAN    1234    /* LSB first: i386, vax */
#define    _BIG_ENDIAN    4321    /* MSB first: 68000, ibm, net */
#if defined(__LITTLE_ENDIAN)
#define    _BYTE_ORDER    _LITTLE_ENDIAN
#elif defined(__BIG_ENDIAN)
#define    _BYTE_ORDER    _BIG_ENDIAN
#else
#error "Please fix asm/byteorder.h"
#endif

#ifdef __LITTLE_ENDIAN
#define le16_to_cpu(_x)     (_x)
#define cpu_to_le16(_x)     (_x)
#define le32_to_cpu(_x)     (_x)
#define cpu_to_le32(_x)     (_x)
#define le64_to_cpu(_x)     (_x)
#define cpu_to_le64(_x)     (_x)
#define be16_to_cpu(_x)     __swapb16(_x)
#define cpu_to_be16(_x)     __swapb16(_x)
#define be32_to_cpu(_x)     __swapb32(_x)
#define cpu_to_be32(_x)     __swapb32(_x)
#else  /* __BIG_ENDIAN */
#define le16_to_cpu(_x)     __swapb16(_x)
#define cpu_to_le16(_x)     __swapb16(_x)
#define le32_to_cpu(_x)     __swapb32(_x)
#define cpu_to_le32(_x)     __swapb32(_x)
#define le64_to_cpu(_x)     __swapb64(_x)
#define cpu_to_le64(_x)     __swapb64(_x)
#define cpu_to_be16(_x)     (_x)
#define be32_to_cpu(_x)     (_x)
#define cpu_to_be32(_x)     (_x)
#endif

#define le16toh(_x)    le16_to_cpu(_x)
#define htole16(_x)    cpu_to_le16(_x)
#define htobe16(_x)    cpu_to_be16(_x)
#define le32toh(_x)    le32_to_cpu(_x)
#define htole32(_x)    cpu_to_le32(_x)
#define be32toh(_x)    be32_to_cpu(_x)
#define htobe32(_x)    cpu_to_be32(_x)

/*
 * Atomic interface
 */
typedef long atomic_t;

#define atomic_read(_patomic_arg)           (*(_patomic_arg))
#define atomic_set(_patomic_arg, v)         InterlockedExchange(_patomic_arg, (v))
#define atomic_add(v, _patomic_arg)         InterlockedExchangeAdd(_patomic_arg, (v))
#define atomic_inc(_patomic_arg)            NdisInterlockedIncrement(_patomic_arg)
#define atomic_dec(_patomic_arg)            NdisInterlockedDecrement(_patomic_arg)
#define atomic_dec_and_test(_patomic_arg)   (NdisInterlockedDecrement(_patomic_arg) == 0)

#define cmpxchg(_m, _old, _new)             InterlockedCompareExchange(_m, _new, _old)

#ifdef UNUSED	// #########################################################################################
/* Resource Pool Handle */
typedef NDIS_HANDLE             OS_POOL_HANDLE;

/* DMA address */
typedef u_int32_t               dma_addr_t;
typedef void *                  dma_context_t;
typedef unsigned char *                  caddr_t;

#define BUS_DMA_TODEVICE        0
#define BUS_DMA_FROMDEVICE      1

/* Opaque S/G List Entry */
typedef SCATTER_GATHER_ELEMENT  sg_t;
#define sg_dma_address(_sg)     NdisGetPhysicalAddressLow((_sg)->Address)
#define sg_dma_len(_sg)         (_sg)->Length

#define OS_DMA_MEM_CONTEXT(context)
#define OS_GET_DMA_MEM_CONTEXT(var, field)  (NULL)
#define OS_COPY_DMA_MEM_CONTEXT(dst, src)
#define OS_ZERO_DMA_MEM_CONTEXT(context)

/*
 * Locking Interfaces
 */
typedef NDIS_SPIN_LOCK spinlock_t;
typedef NDIS_RW_LOCK rwlock_t;
typedef LOCK_STATE rwlock_state_t;

#define spin_lock_init(_k)      NdisAllocateSpinLock(_k) 
#define spin_lock_destroy(_k)   NdisFreeSpinLock(_k)
#define spin_lock(_k)           NdisAcquireSpinLock(_k)
#define spin_unlock(_k)         NdisReleaseSpinLock(_k)
/*
 * For Vista: we do not differentiate between the normal spinlock and
 * the DPC spinlock. We assumed that the both spinlocks are used in Dispatch
 * (which is equal DPC IRQL) level.
 */
#define spin_lock_dpc(_k)       NdisAcquireSpinLock(_k)
#define spin_unlock_dpc(_k)     NdisReleaseSpinLock(_k)
#define rwlock_init(_k)         NdisInitializeReadWriteLock(_k)
#define read_lock(_k, _s)       NdisAcquireReadWriteLock(_k, FALSE, _s)
#define write_lock(_k, _s)      NdisAcquireReadWriteLock(_k, TRUE, _s)
#define read_unlock(_k, _s)     NdisReleaseReadWriteLock(_k, _s)
#define write_unlock(_k, _s)    NdisReleaseReadWriteLock(_k, _s)

#define os_tasklet_lock(a, b)        spin_lock(a)
#define os_tasklet_unlock(a, b)      spin_unlock(a)

typedef spinlock_t ieee80211_scan_lock_t;
typedef spinlock_t ieee80211com_lock_t;

/*
 * Mutexes.
 * For performance reasons, we use guarded mutexes instead of NDIS' 
 * standard mutexes.
 * If necessary to change the object type, all related macros must be changed
 * accordingly.
 */
typedef KGUARDED_MUTEX          OS_MUTEX;
#define mutex_init(_m)          KeInitializeGuardedMutex(_m);
#define acquire_mutex(_m)       KeAcquireGuardedMutex(_m);
#define release_mutex(_m)       KeReleaseGuardedMutex(_m);

/*
 * Delay functions. Time specified in microseconds.
 */
#define OS_DELAY(_us)   NdisStallExecution(_us)
#define OS_SLEEP(_us)   NdisMSleep(_us)

#define OS_MEMCPY(_dst, _src, _len)     NdisMoveMemory(_dst, _src, _len)
#define OS_MEMZERO(_buf, _len)          NdisZeroMemory(_buf, _len)
#define OS_MEMSET(_buf, _ch, _len)      NdisFillMemory(_buf, _len, _ch)
// ANSI's memcmp returns 0 if _mem1 and _mem2 are equal, while NdisEqualMemory returns 1.
// For consistency, we convert NdisEqualMemory's return value to match memcmp's.
#define OS_MEMCMP(_mem1, _mem2, _len)   (! NdisEqualMemory(_mem1, _mem2, _len))

/*
 * System time interface
 */
typedef ULONGLONG   systime_t;
typedef ULONGLONG   systick_t;

static INLINE systime_t
OS_GET_TIMESTAMP(void)
{
    systime_t sysTime;
    NdisGetSystemUpTimeEx((PLARGE_INTEGER)&sysTime);
    return sysTime;
}

static INLINE systick_t
OS_GET_TICKS(void)
{
    systick_t ticks;
    KeQueryTickCount((PLARGE_INTEGER)&ticks);
    return ticks;
}

// convert 100ns units returned by some OS time functions to ms
#define CONVERT_SYSTEM_TIME_TO_MS(_t)         (_t)
#define CONVERT_SYSTEM_TIME_TO_SEC(_t)        ((_t) / 1000i64)
#define CONVERT_SEC_TO_SYSTEM_TIME(_t)        ((_t) * 1000i64)
#define CONVERT_MS_TO_SYSTEM_TIME(_t)         (_t)

#define time_before(a,b)                      ((long)(a) - (long)(b) < 0)    

/*
 * Prink Interface
 */
#if DBG
#define printk DbgPrint
#else
static INLINE void printk(char *fmt, ...) {return;}
#endif

#define    KASSERT(exp, msg) do {                  \
    if (!(exp)) {                               \
        printk msg;                             \
        ASSERT(0);                              \
    }                                           \
} while (0)

#ifndef __func__
#define __func__    __FUNCTION__
#endif

/*
 * Mapping Unixism status to NDIS_STATUS_XXX
 */
#define ENOMEM     (-NDIS_STATUS_RESOURCES)
#define EIO        (-NDIS_STATUS_FAILURE)
#define ENXIO      (-NDIS_STATUS_FAILURE)
#define EINVAL     (-NDIS_STATUS_INVALID_PARAMETER)
#define EOVERFLOW  (-NDIS_STATUS_BUFFER_OVERFLOW)

/* Miscellanous globals to improve code readability etc. */
#include "Globals.h"

/* Various functions and data structures provided by WiFi */
#include "Windot11.h"

/*
 * XXX: Include this because we need to interface with MP layer of sample driver.
 * This could be a bit of duplication, because ath layers will use
 * ieee80211_xxx headers from net80211 module.
 */
#include "80211hdr.h"

/* Definitions made by the Hw files needed in *Interface.h come here */
#include "Hw_Defines.h"

/* Definitions necessary to interact with the station functionality */
#include "Sta_Defines.h"

/* Definitions necessary to interact with the miniport functionality */
#include "Mp_defines.h"

/* Calls made by the miniport/station portion into the vendor defined
 * (hardware specific) */
#include "HW_Interface.h"

/* Calls made by the hardware/station portion into the miniport funtions */
#include "MP_Interface.h"

/* Calls made by the miniport/hardware portion into the station functions
 * (for managing MAC state) */
#include "STA_Interface.h"

/* To provide debugging macros and functions to everyone */
#include "Mp_dbg.h"

/* various files could use the ability to wrk with INFO_ELEMENTS */
#include "Mp_Element.h"

typedef struct _NICCARDINFO {
    /* These are our mapped Control/Status registers */
    PVOID                    CSRAddress;
    ULONG                    CSRLength;

    USHORT                   DeviceID;
    UCHAR                    RevisionID;
    USHORT                   SubVendorID;
    USHORT                   SubSystemID;

    ULONG                    InterruptLevel;

    NDIS_PHYSICAL_ADDRESS    MemPhysAddress;

    BOOLEAN                  MWIEnable;

    ULONG                    cacheLineSize; // PCI-reported cacheLineSize
    ULONG                    dwBridge;
} NICCARDINFO, *PNICCARDINFO;

/*
 * Definition of OS-dependent device structure.
 * It'll be opaque to the actual ATH layer.
 */
struct _NIC_DEV {
    NDIS_HANDLE            MiniportAdapterHandle;
    PADAPTER               pAdapter;
    PSTATION               pStation;

    /* Card Information */
    NICCARDINFO            CardInfo;
};

typedef PNIC_DEV osdev_t;

#define ATHR_MEMORY_TAG     'HhtA'

/*
 * Memory allocation/free API's.
 * XXX: Right now the syntax looks like Linux's, so we can minimize the
 * changes made to ath layer
 */
#define GFP_KERNEL      NormalPoolPriority
#define GFP_ATOMIC      NormalPoolPriority

static INLINE PUCHAR
OS_MALLOC(osdev_t pNicDev, ULONG ulSizeInBytes, EX_POOL_PRIORITY Priority)
{
    PUCHAR pMemory = NULL;
    MP_ALLOCATE_MEMORY_WITH_PRIORITY(
            pNicDev->MiniportAdapterHandle,
            (PVOID *)&pMemory, ulSizeInBytes,
            ATHR_MEMORY_TAG, Priority);
    return pMemory;
}

#define OS_FREE(_pMemory)   MP_FREE_MEMORY(_pMemory)

static INLINE PVOID
OS_MALLOC_WITH_TAG(void **ppMem, u_int32_t size, u_int32_t tag)
{
    NDIS_STATUS ndisStatus;

    ndisStatus = NdisAllocateMemoryWithTag(ppMem, size, tag);
    if (ndisStatus == NDIS_STATUS_SUCCESS)
        return *ppMem;
    else
        return NULL;
}

static INLINE void
OS_FREE_WITH_TAG(void *pMem, u_int32_t size)
{
    NdisFreeMemory(pMem, size, 0);
    return;
}

static INLINE PUCHAR
OS_MALLOC_CONSISTENT(osdev_t pNicDev,
                     ULONG ulSizeInBytes,
                     dma_addr_t *pa,
                     dma_context_t context,
                     u_int32_t shmemalloc_retry)
{
#define MEMALLOC_DELAY_IN_MS          500
    PUCHAR pMemory = NULL;
    NDIS_PHYSICAL_ADDRESS PhysicalAddress;
    int i;

    for (i=0; i < shmemalloc_retry; i++) {
        NdisMAllocateSharedMemory(
            pNicDev->MiniportAdapterHandle,
            ulSizeInBytes,
            FALSE,
            (PVOID *)&pMemory,
            &PhysicalAddress);

        if (pMemory != NULL) {
            ASSERT(NdisGetPhysicalAddressHigh(PhysicalAddress) == 0);
            *pa = NdisGetPhysicalAddressLow(PhysicalAddress);
            break;
        } else {
            NdisMSleep(MEMALLOC_DELAY_IN_MS * 1000);
        }
    }

    return pMemory;
#undef MEMALLOC_DELAY_IN_MS
}

static INLINE void
OS_FREE_CONSISTENT(osdev_t pNicDev,
                   ULONG Length,
                   PVOID VirtualAddress,
                   dma_addr_t Pa,
                   dma_context_t context)
{
    NDIS_PHYSICAL_ADDRESS PhysicalAddress;

    NdisSetPhysicalAddressHigh(PhysicalAddress, 0);
    NdisSetPhysicalAddressLow(PhysicalAddress, Pa);
    NdisMFreeSharedMemory(pNicDev->MiniportAdapterHandle,
                          Length, FALSE,
                          VirtualAddress, PhysicalAddress);
}

#define OS_SYNC_SINGLE(_dev, _pa, _len, _dir, _context)
#define OS_UNMAP_SINGLE(_dev, _pa, _len, _dir, _context)

#define OS_EXEC_INTSAFE(_osdev, _fn, _arg) do {                                                         \
    NDIS_HANDLE InterruptHandle = Mp11GetInterruptHandle((_osdev)->pAdapter);                           \
    if (InterruptHandle) {                                                                              \
        NdisMSynchronizeWithInterruptEx(InterruptHandle, 0, (PVOID)(_fn), (_arg));                      \
    }                                                                                                   \
    else {                                                                                              \
        _fn(_arg);                                                                                      \
    }                                                                                                   \
} while (0)


/*
 * Timer Interfaces. Use these macros to declare timer
 * and retrieve timer argument. This is mainly for resolving
 * different argument types for timer function in different OS.
 */
typedef NDIS_MINIPORT_TIMER os_timer_t;

#define OS_DECLARE_TIMER(_fn)                   \
    VOID _fn(                                   \
        IN PVOID  SystemSpecific1,              \
        IN PVOID  FunctionContext,              \
        IN PVOID  SystemSpecific2,              \
        IN PVOID  SystemSpecific3               \
    )

#define OS_TIMER_FUNC(_fn)                      \
    VOID _fn(                                   \
        IN PVOID  SystemSpecific1,              \
        IN PVOID  FunctionContext,              \
        IN PVOID  SystemSpecific2,              \
        IN PVOID  SystemSpecific3               \
    )

#define OS_GET_TIMER_ARG(_arg, _type)           \
    (_arg) = (_type)(FunctionContext)

static INLINE NDIS_HANDLE
OS_GET_POOL_HANDLE(osdev_t pNicDev)
{
    return pNicDev->MiniportAdapterHandle;
}

/*
 * Return 1 if timer has been initialized, or 0 otherwise.
 */
static INLINE u_int32_t
OS_INIT_TIMER(osdev_t              pNicDev, 
              PNDIS_MINIPORT_TIMER timer,
              PNDIS_TIMER_FUNCTION fn, 
              PVOID                arg)
{
    NdisMInitializeTimer(timer, pNicDev->MiniportAdapterHandle, fn, arg);

    return 1;
}

static INLINE void
OS_FREE_TIMER(PNDIS_MINIPORT_TIMER timer)
{
}

/*
 * Return 1 if timer has been set, or 0 otherwise.
 */
static INLINE u_int32_t
OS_SET_TIMER(PNDIS_MINIPORT_TIMER timer, u_int32_t ms)
{
    NdisMSetTimer(timer, ms);

    return 1;
}

/*
 * Return 1 if timer has been canceled, or 0 otherwise.
 */
static INLINE u_int32_t
OS_CANCEL_TIMER(PNDIS_MINIPORT_TIMER timer)
{
    BOOLEAN    timerCanceled;

    NdisMCancelTimer(timer, &timerCanceled);

    return (u_int32_t) timerCanceled;
}

static INLINE void
bus_read_cachesize(PNIC_DEV pNicDev, int *pLineSize, int bustype)
{
    if (pNicDev->CardInfo.cacheLineSize)
        *pLineSize = pNicDev->CardInfo.cacheLineSize;
    else /* PNP OS did not do its job */
        *pLineSize = 32 >> 2; /* caller will shift back up */
}

static INLINE void *
OS_ALLOC_VAP(osdev_t osdev, u_int32_t len)
{
    void *netif;
    
    /*
     * In NDIS, we just allocate memory for interface object here.
     * For Linux, it may need to allocate and setup a net_device.
     */
    netif = OS_MALLOC(osdev, len, GFP_KERNEL);
    if (netif != NULL)
        OS_MEMZERO(netif, len);
    
    return netif;
}

static INLINE void
OS_FREE_VAP(void *netif)
{
    /* Just free the structure in NDIS.
     * In Linux, it should call unregister_netdevice
     * to free the memory */
    OS_FREE(netif);
}

static INLINE u_int32_t
OS_PCI_READ_CONFIG(osdev_t osdev, u_int32_t offset, void *buffer, u_int32_t len)
{
    return (NdisMGetBusData(osdev->MiniportAdapterHandle,
                            PCI_WHICHSPACE_CONFIG,
                            offset,
                            buffer,
                            len)); 
}

static INLINE void
OS_PCI_WRITE_CONFIG(osdev_t osdev, u_int32_t offset, void *buffer, u_int32_t len)
{
    NdisMSetBusData(osdev->MiniportAdapterHandle,
                    PCI_WHICHSPACE_CONFIG,
                    offset,
                    buffer,
                    len);
}

// ALLOC_DMA_MAP_CONTEXT_AREA is a NULL macro and is implemented only for BSD.
#define ALLOC_DMA_MAP_CONTEXT_AREA(os_handle, p_memctx)
#define FREE_DMA_CONTEXT_POOL(os_handle, name)
#define ALLOC_DMA_CONTEXT_POOL(os_handle, name, nbuf)

#define ATH_FRAG_PER_MSDU   4
/*
 * minimum h/w qdepth to be sustained to maximize aggregation
 */
#define ATH_AGGR_MIN_QDEPTH  2
#if ATH_TX_POLL
#define ATH_TX_POLL_TIMER    80
#define hz                   100
#define MSEC_TO_TICKS(ms)    (((ms)*hz)/1000)
#endif

#define vsnprintf            RtlStringCbVPrintfA
u_int32_t snprintf(char* string, u_int32_t len, const char* fmt, ...);

#define ATH_GET_RX_CONTEXT_BUF(_wbuf)  \
                          ((struct ath_buf *) ATH_RX_CONTEXT(_wbuf)->ctx_rxbuf)
#define ATH_SET_RX_CONTEXT_BUF(_wbuf, _bf)  \
                          (ATH_GET_RX_CONTEXT_BUF(_wbuf) = _bf)

#endif	// UNUSED	############################################################################################

#include <malloc.h>

#define OS_MALLOC(a,b,c) malloc(b);

#define OS_FREE(a) free(a);

#include <memory.h>

#define OS_MEMZERO(addr, len) memset(addr, 0, len)

#define OS_MEMCPY(a,b,c) memcpy(a,b,c)

#define OS_MEMSET(_buf, _ch, _len) memset(_buf, _ch, _len)

#include <stdio.h>			// also defines NULL

#define printk printf

#include "MyDelay.h"

#define OS_DELAY(x) MyDelay(x/1000)

#define __func__ "__func__"

#endif /* end of _ATH_WINVISTA_OSDEP_H */
