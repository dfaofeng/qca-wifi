//------------------------------------------------------------------------------
// Copyright (c) 2004-2010 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

#ifndef __SOC_ADDRS_H__
#define __SOC_ADDRS_H__

/*
 * Special Platform Addresses that may be needed by special
 * applications (e.g. ART) on the Host as well as Target.
 *
 * TBDXXX: Use AR6004_ prefix for definitions that are visible
 * to both Host and Target.  Host may simultaneously include
 * soc_addrs.h files from multiple platforms, so avoid name
 * conflicts.  For Target, use more generic TARG_ prefix;
 * but only do this under a Target-specific ifdef.  There's
 * no use for an AR6K_ prefix.
 */

#define TARG_DRAM_START 0x00400000
#define TARG_RAM_START TARG_DRAM_START
#define AR6K_RAM_START TARG_DRAM_START
#define TARG_RAM_OFFSET(vaddr) (((A_UINT32)(vaddr) & 0x0fffff))
#define TARG_RAM_SZ     (320*1024)
#ifdef FPGA
#define TARG_RAM_SZ_MAX (352*1024) /* Max possible DRAM size (320+32)-- actual size may be smaller */
#define AR6K_SWITCHABLE_RAM_BANK 1
#else
#define TARG_RAM_SZ_MAX (416*1024) /* Max possible DRAM size (320+96)-- actual size may be smaller */
#define AR6K_SWITCHABLE_RAM_BANK 3
#endif
#define TARG_ROM_SZ (256*1024)

/* TODO: ROME*/
#define INTF_ALLOCRAM_START INTF_MC0_ALLOCRAM_START
#ifdef FPGA
#define INTF_MC0_ALLOCRAM_START 0x000B0000
#define INTF_MC0_ALLOCRAM_SZ (32*1024)
#define INTF_MC1_ALLOCRAM_SZ (32*1024)
#else
#define INTF_MC0_ALLOCRAM_START 0x000A0000
#define INTF_MC0_ALLOCRAM_SZ (2*32*1024)
#define INTF_MC1_ALLOCRAM_SZ (2*32*1024)
#endif
#define INTF_MC1_ALLOCRAM_START (INTF_MC0_ALLOCRAM_START + INTF_MC0_ALLOCRAM_SZ)
#define INTF_ALLOCRAM_SZ_HL (INTF_MC0_ALLOCRAM_SZ + INTF_MC1_ALLOCRAM_SZ)

#ifdef FPGA
#define INTF_ALLOCRAM_SZ_LL (32*1024)
#else
#define INTF_ALLOCRAM_SZ_LL (96*1024)
#endif

/* IRAM consists of 7 fixed bank plus up to 3 switchable I/D banks */
#define AR6K_SWITCHABLE_RAM_BANK_SZ (32*1024)
#define TARG_IRAM_START 0x00980000
#define TARG_SWITCHABLE_IRAM_START (TARG_IRAM_START + 224*1024)
#define TARG_IRAM_SZ (224*1024 + 3*AR6K_SWITCHABLE_RAM_BANK_SZ)

#define TARG_RAM_ACS_RESERVE  32

#define AR6K_RAM_ADDR(byte_offset) (AR6K_RAM_START+(byte_offset))
#define TARG_RAM_ADDRS(byte_offset) AR6K_RAM_ADDR(byte_offset)

#define AR6K_ROM_START 0x00940000
#define TARG_ROM_OFFSET(vaddr) ((A_UINT32)(vaddr) & 0xfffff)
#define AR6K_ROM_ADDR(byte_offset) (AR6K_ROM_START+(byte_offset))
#define TARG_ROM_ADDRS(byte_offset) AR6K_ROM_ADDR(byte_offset)

/*
 * At this ROM address is a pointer to the start of the ROM DataSet Index.
 * If there are no ROM DataSets, there's a 0 at this address.
 */
#define ROM_DATASET_INDEX_ADDR          (TARG_ROM_ADDRS(TARG_ROM_SZ)-8)
#define ROM_MBIST_CKSUM_ADDR            (TARG_ROM_ADDRS(TARG_ROM_SZ)-4)

/*
 * The API A_BOARD_DATA_ADDR() is the proper way to get a read pointer to
 * board data.
 */

/* Size of Board Data, in bytes */
#define BOARD_DATA_SZ AR6320_BOARD_DATA_SZ

#endif /* __SOC_ADDRS_H__ */
