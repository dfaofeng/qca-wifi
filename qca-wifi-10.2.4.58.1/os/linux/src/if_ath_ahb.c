/*
 * Copyright (c) 2010, Atheros Communications Inc.
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
 * Copyright (c) 2013 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef EXPORT_SYMTAB
#define	EXPORT_SYMTAB
#endif

#include <osdep.h>
#ifdef USE_PLATFORM_FRAMEWORK
#include <linux/platform_device.h>
#include <linux/ath9k_platform.h>
#endif
#include "if_athvar.h"
#include "ah_devid.h"
#include "if_ath_ahb.h"

#ifdef AH_CAL_IN_FLASH_AHB
static u_int32_t    CalAddr[AH_CAL_RADIOS_AHB] = {AH_CAL_LOCATIONS_AHB};
#endif

#if defined(AH_CAL_IN_DRAM_AHB) && !defined(USE_PLATFORM_FRAMEWORK)
static u_int32_t    CalAddr_dram[AH_CAL_RADIOS_AHB] = {AH_CAL_LOCATIONS_DRAM_AHB};
#endif

struct ath_ahb_softc {
	struct ath_softc_net80211   aps_sc;
	struct _NIC_DEV             aps_osdev;
#ifdef CONFIG_PM
	u32			aps_pmstate[16];
#endif
};

static struct ath_ahb_softc *sclist[2] = {NULL, NULL};
static u_int8_t num_activesc=0;

static struct ar531x_boarddata *ar5312_boardConfig=NULL;
static char *radioConfig=NULL;

extern int __ath_attach(u_int16_t devid, struct net_device *dev, HAL_BUS_CONTEXT *bus_context, osdev_t osdev);
extern int __ath_detach(struct net_device *dev);

#ifdef USE_PLATFORM_FRAMEWORK
static struct platform_device *spdev;
#endif /* USE_PLATFORM_FRAMEWORK */

static int
ar5312_get_board_config(void)
{
	int dataFound;
	char *bd_config;
	
	/*
	 * Find start of Board Configuration data, using heuristics:
	 * Search back from the (aliased) end of flash by 0x1000 bytes
	 * at a time until we find the string "5311", which marks the
	 * start of Board Configuration.  Give up if we've searched
	 * more than 500KB.
	 */
	dataFound = 0;
	for (bd_config = (char *)0xbffff000;
	     bd_config > (char *)0xbff80000;
	     bd_config -= 0x1000) {
		if ( *(int *)bd_config == AR531X_BD_MAGIC) {
			dataFound = 1;
			break;
		}
	}
	
	if (!dataFound) {
		printk("Could not find Board Configuration Data\n");
		bd_config = NULL;
	}
	ar5312_boardConfig = (struct ar531x_boarddata *) bd_config;
	return(dataFound);
}

static int
ar5312_get_radio_config(void)
{
	int dataFound;
	char *radio_config;
	
	/* 
	 * Now find the start of Radio Configuration data, using heuristics:
	 * Search forward from Board Configuration data by 0x1000 bytes
	 * at a time until we find non-0xffffffff.
	 */
	dataFound = 0;
	for (radio_config = ((char *) ar5312_boardConfig) + 0x1000;
	     radio_config < (char *)0xbffff000;
	     radio_config += 0x1000) {
		if (*(int *)radio_config != 0xffffffff) {
			dataFound = 1;
			break;
		}
	}

	if (!dataFound) { /* AR2316 relocates radio config to new location */
	    dataFound = 0;
	    for (radio_config = ((char *) ar5312_boardConfig) + 0xf8;
		 radio_config < (char *)0xbffff0f8;
		 radio_config += 0x1000) {
		if (*(int *)radio_config != 0xffffffff) {
		    dataFound = 1;
		    break;
		}
	    }
	}

	if (!dataFound) {
		printk("Could not find Radio Configuration data\n");
		radio_config = NULL;
	}
	radioConfig = radio_config;
	return(dataFound);
}

static int
ar5312SetupFlash(void)
{
	if (ar5312_get_board_config()) {
		if (ar5312_get_radio_config()) {
			return(1);
		}
	}
	return(0);
}	

/*
 * Read 16 bits of data from offset into *data
 */

static void
ar5312BspEepromRead(u_int32_t off, u_int32_t nbytes, u_int8_t *data)
{
	int i;
	char *eepromAddr = radioConfig;
	
	for (i=0; i<nbytes; i++,off++) {
		data[i] = eepromAddr[off];
	}
}

int ahb_enable_wmac(u_int16_t devid,u_int16_t wlanNum)
{

	if((devid & AR5315_REV_MAJ_M) == AR5315_REV_MAJ) {
		u_int32_t reg;
		/* Enable Arbitration for WLAN */
		u_int32_t *en = (u_int32_t *) AR5315_AHB_ARB_CTL;
		KASSERT(wlanNum == 0,("invalid wlan # %d",wlanNum) ); 
		*en  |= AR5315_ARB_WLAN;

		/* Enable global swapping so this looks like a normal BE system */
		reg = REG_READ(AR5315_ENDIAN_CTL);
		reg |= AR5315_CONFIG_WLAN;
		REG_WRITE(AR5315_ENDIAN_CTL, reg);

		/* wake up the MAC */
		/* NOTE: for the following write to succeed the
		   RST_AHB_ARB_CTL should be set to 0. This driver
		   asuumes that the register has been set to 0 by boot loader */ 
		reg = REG_READ(AR5315_PCI_MAC_SCR);
		reg= (reg & ~AR5315_PCI_MAC_SCR_SLMODE_M) | 
			(AR5315_PCI_MAC_SCR_SLM_FWAKE << AR5315_PCI_MAC_SCR_SLMODE_S);
		REG_WRITE(AR5315_PCI_MAC_SCR, reg);

		/* wait for the MAC to wakeup */
		while (REG_READ(AR5315_PCI_MAC_PCICFG) & AR5315_PCI_MAC_PCICFG_SPWR_DN);

  } else {

        u_int32_t *en = (u_int32_t *)AR531X_ENABLE;
        switch (wlanNum) {
        case AR531X_WLAN0_NUM:
                *en |= AR531X_ENABLE_WLAN0;
                break;
        case AR531X_WLAN1_NUM:
                *en |= AR531X_ENABLE_WLAN1;
                break;
        default:
                return -ENODEV;
        }
  }
        return 0;
}

#ifdef when_ar531x_is_implemented
int ahb_disable_wmac(u_int16_t devid, u_int16_t wlanNum)
{
	if((devid & AR5315_REV_MAJ_M) == AR5315_REV_MAJ) {
		/* Enable Arbitration for WLAN */
		u_int32_t *en = (u_int32_t *) AR5315_AHB_ARB_CTL;
		KASSERT(wlanNum == 0,("invalid wlan # %d",wlanNum) ); 
		*en  &= ~AR5315_ARB_WLAN;
	}
	else { 
		u_int32_t *en = (u_int32_t *)AR531X_ENABLE;
		switch (wlanNum) {
		case AR531X_WLAN0_NUM:
			*en &= ~AR531X_ENABLE_WLAN0;
			break;
		case AR531X_WLAN1_NUM:
			*en &= ~AR531X_ENABLE_WLAN1;
			break;
		default:
			return -ENODEV;
		}
	}
	return 0;
}


int exit_ath_wmac(u_int16_t wlanNum)
{
	struct ath_ahb_softc *sc = sclist[wlanNum];
	struct net_device *dev;
	const char *sysType;
	u_int16_t devid;

        if(sc == NULL)
                return -ENODEV; /* XXX: correct return value? */

        dev = sc->aps_osdev.sc_dev;
	__ath_detach(dev);
	sysType = get_system_type();
	if(strcmp(sysType,"Atheros AR5315") == 0) {
		devid = (u_int16_t) (sysRegRead(AR5315_SREV) & (AR5315_REV_MAJ_M | AR5315_REV_MIN_M));
	} else {
		devid = ((u_int16_t) ((sysRegRead(AR531X_REV) >>8) &
							  (AR531X_REV_MAJ | AR531X_REV_MIN)));
	}

	ahb_disable_wmac(devid,wlanNum);
	free_netdev(dev);
        sclist[wlanNum]=NULL;
        return 0;
}

int init_ath_wmac(u_int16_t devid, u_int16_t wlanNum)
{
        const char *athname;
        struct net_device *dev;
        struct ath_ahb_softc *sc;
        HAL_BUS_CONTEXT bus_context;

        if (((wlanNum != 0) && (wlanNum != 1)) ||
            (sclist[wlanNum] != NULL)) {
                goto bad;
        }

	ahb_enable_wmac(devid,wlanNum);

	dev = alloc_netdev(sizeof(struct ath_ahb_softc), "radio%d", NET_NAME_UNKNOWN, ether_setup);
	if (dev == NULL) {
		printk(KERN_ERR "ath_dev_probe: no memory for device state\n");
		goto bad2;
	}
	sc = ath_netdev_priv(dev);
	sc->aps_osdev.netdev = dev;

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2,5,41)
	dev->owner = THIS_MODULE;
#elif LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,24)
	SET_MODULE_OWNER(dev);
#endif
        sclist[wlanNum] = sc;

        switch (wlanNum) {
        case AR531X_WLAN0_NUM:
	        if((devid & AR5315_REV_MAJ_M) == AR5315_REV_MAJ) {
                    dev->irq = AR5315_IRQ_WLAN0_INTRS;
                    dev->mem_start = AR5315_WLAN0;
                } else {
		    dev->irq = AR531X_IRQ_WLAN0_INTRS;
                    dev->mem_start = AR531X_WLAN0;
		}
                break;
        case AR531X_WLAN1_NUM:
                dev->irq = AR531X_IRQ_WLAN1_INTRS;
                dev->mem_start = KSEG1ADDR(AR531X_WLAN1);
                break;
        default:
                goto bad3;
        }
        dev->mem_end = dev->mem_start + AR531X_WLANX_LEN;
        sc->aps_osdev.bdev = (void *) NULL;

        bus_context.bc_tag = NULL;
        bus_context.bc_handle = (void *)dev->mem_start;
        bus_context.bc_bustype = HAL_BUS_TYPE_AHB;

        if (__ath_attach(devid, dev, &bus_context, &sc->aps_osdev) != 0)
                goto bad3;
        athname = ath_hal_probe(ATHEROS_VENDOR_ID, devid);
        printk(KERN_INFO "%s: %s: mem=0x%lx, irq=%d\n",
               dev->name, athname ? athname : "Atheros ???", dev->mem_start, dev->irq);
        num_activesc++;
        return 0;

 bad3:
        free_netdev(dev);
        sclist[wlanNum]=NULL;
 bad2:
        ahb_disable_wmac(devid,wlanNum);
 bad:
        return -ENODEV;
}
#endif /* when_ar531x_is_implemented */

#ifdef USE_PLATFORM_FRAMEWORK
int
get_wmac_irq(u_int16_t wmac_num)
{
	int ret;
	struct resource *res;

	res = platform_get_resource(spdev, IORESOURCE_IRQ, 0);
	if (res == NULL) {
		printk("no IRQ resource found\n");
		ret = -ENXIO;
		goto out;
	}

	ret = res->start;
out:
	return ret;
}

unsigned long
get_wmac_base(u_int16_t wmac_num)
{
	void __iomem *mem;
	struct resource *res;
	unsigned long ret;

	res = platform_get_resource(spdev, IORESOURCE_MEM, 0);
	if (res == NULL) {
		printk("no memory resource found\n");
		ret = -ENXIO;
		goto err_out;
	}

	mem = ioremap_nocache(res->start, resource_size(res));
	if (mem == NULL) {
		printk("ioremap failed\n");
		ret = -ENOMEM;
		goto err_out;
	}

	return (unsigned long) mem;
err_out:
	iounmap(mem);
	return ret;
}

unsigned long
get_wmac_mem_len(u_int16_t wmac_num)
{
	struct resource *res;
	unsigned long ret;

	res = platform_get_resource(spdev, IORESOURCE_MEM, 0);
	if (res == NULL) {
		dev_err(&spdev->dev, "no memory resource found\n");
		ret = -ENXIO;
		goto out;
	}
	ret = resource_size(res);
out:
	return ret;
}
#endif /* USE_PLATFORM_FRAMEWORK */

static int
init_ath_wmac(u_int16_t devid, u_int16_t wlanNum)
{
    const char *athname;
    struct net_device *dev;
    struct ath_ahb_softc *sc;
    HAL_BUS_CONTEXT bc;

#ifdef USE_PLATFORM_FRAMEWORK
    struct ath9k_platform_data *spdata;
#endif

    if (wlanNum != 0 || sclist[wlanNum] != NULL) {
        return -ENODEV;
    }

    dev = alloc_netdev(sizeof(struct ath_ahb_softc), "radio%d", NET_NAME_UNKNOWN, ether_setup);
    if (dev == NULL) {
        printk(KERN_ERR "%s: no memory for device state\n", __func__);
        goto bad1;
    }
    sc = ath_netdev_priv(dev);
    sc->aps_osdev.netdev = dev;

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2,5,41)
    dev->owner = THIS_MODULE;
#elif LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,24)
    SET_MODULE_OWNER(dev);

#endif



       
    sclist[wlanNum] = sc;

    dev->irq = get_wmac_irq(wlanNum);
	dev->mem_start = get_wmac_base(wlanNum);
	dev->mem_end = dev->mem_start + get_wmac_mem_len(wlanNum);

    /*
     * Don't leave arp type as ARPHRD_ETHER as this is no eth device
     */
    dev->type = ARPHRD_IEEE80211;

    sc->aps_osdev.bdev = NULL;

#ifdef AH_CAL_IN_FLASH_AHB
    bc.bc_info.bc_tag = (void *) CalAddr[0];
    bc.bc_info.cal_in_flash = 1;
#else
    bc.bc_info.bc_tag = NULL;
    bc.bc_info.cal_in_flash = 0;
#endif

#ifdef AH_CAL_IN_DRAM_AHB
#ifdef USE_PLATFORM_FRAMEWORK
    spdata = (struct ath9k_platform_data *) spdev->dev.platform_data;
    bc.bc_info.bc_tag = (void *) spdata->eeprom_data;
#else
    bc.bc_info.bc_tag = (void *) CalAddr_dram[0];
#endif
    bc.bc_info.cal_in_flash = 0;
#endif

    bc.bc_handle = (HAL_BUS_HANDLE)dev->mem_start;
    bc.bc_bustype = HAL_BUS_TYPE_AHB;

    if (__ath_attach(devid, dev, &bc, &sc->aps_osdev) != 0) {
        goto bad2;
    }

    athname = ath_hal_probe(ATHEROS_VENDOR_ID, devid);

#if 0
    enable_wmac_led();
#endif

    printk(KERN_INFO "%s: %s: mem=0x%lx, irq=%d\n",
        dev->name, athname ? athname : "Atheros ???",
        dev->mem_start, dev->irq);

    num_activesc++;

    return 0;
bad2:
    free_netdev(dev);
bad1:
    sclist[wlanNum]=NULL;
    return -ENODEV;
}

static int
exit_ath_wmac(u_int16_t wlanNum)
{
    struct ath_ahb_softc *sc = sclist[wlanNum];
    struct net_device *dev;

    if(sc == NULL) {
        return -ENODEV; /* XXX: correct return value? */
    }

    dev = sc->aps_osdev.netdev;
    if(dev == NULL) {
        printk("%s: No device\n", __func__);
        return -ENODEV;
    }
    __ath_detach(dev);
    free_netdev(dev);
#if 0
    disable_wmac_led();
#endif
    sclist[wlanNum]=NULL;
    return 0;
}

#if !defined(USE_PLATFORM_FRAMEWORK)
int init_ahb(void)
{
#if 0
	int ret;
	u_int16_t devid = AR9300_DEVID_AR9380_PCIE;
#endif
	u_int16_t devid = 0;
	const char *sysType;

	sysType = get_system_type(); /* Get the devid from BSP */

	if(strcmp(sysType, "Atheros AR9330 (Hornet)") == 0) {
		devid = AR9300_DEVID_AR9380_PCIE;
	} else if ((strcmp(sysType,"QCA955x emu") == 0) ||
                   (strcmp(sysType,"Atheros AR934x emu") == 0) || 
                   (strcmp(sysType,"QCA953x emu") == 0))  {
//		printk(" QCA953X EMu dev id \n");
		devid = AR9300_DEVID_EMU_PCIE;
	} else if(strncmp(sysType,"Atheros AR934", strlen("Atheros AR934")) == 0) {
		devid = AR9300_DEVID_AR9340;
	} else if(strcmp(sysType,"QCA955x") == 0) {
		devid = AR9300_DEVID_AR955X;
	} else if(strcmp(sysType, "QCA953x") == 0) {
		devid = AR9300_DEVID_AR953X;
    } else if(strcmp(sysType, "QCA956x") == 0) {
		devid = AR9300_DEVID_AR956X;
	} else if(strcmp(sysType, "QCA956x emu") == 0) {
		devid = AR9300_DEVID_AR956X;
	} else {
        printk("Unknow sysType: %s\n", sysType);
		return -ENODEV;
	}

    return init_ath_wmac(devid, 0);
#if 0
	u_int16_t devid,radioMask;

	const char *sysType;
	sysType = get_system_type();
#ifdef AR9100
	if(strcmp(sysType,"Atheros AR9100") == 0) {
		devid = (ar7100_reg_rd(AR7100_CHIP_REV) &
				AR7100_CHIP_REV_MAJOR_M) >>
				AR7100_CHIP_REV_MAJOR_S;
		return init_ath_wmac(devid, 0);
	} else
#endif
	if(strcmp(sysType,"Atheros AR5315") == 0) {
		devid = (u_int16_t) (sysRegRead(AR5315_SREV) & (AR5315_REV_MAJ_M | AR5315_REV_MIN_M));
		if((devid & AR5315_REV_MAJ_M) == AR5315_REV_MAJ)
			return init_ath_wmac(devid,0);
	}

	/* Probe to find out the silicon revision and enable the
	   correct number of macs */
	if (!ar5312SetupFlash())
	  return -ENODEV;
        devid = ((u_int16_t) ((sysRegRead(AR531X_REV) >>8) & 
                            (AR531X_REV_MAJ | AR531X_REV_MIN)));
        switch (devid) {
        case AR5212_AR5312_REV2:
        case AR5212_AR5312_REV7:
	  /* Need to determine if we have a 5312 or a 2312 since they
	     have the same Silicon Rev ID*/
		ar5312BspEepromRead(2*AR531X_RADIO_MASK_OFF,2,
				    (char *) &radioMask);
		if ((radioMask & AR531X_RADIO0_MASK) != 0) {
		  if((ret=init_ath_wmac(devid,0))!=0)
		    return ret;
		}
        case AR5212_AR2313_REV8:
                if((ret=init_ath_wmac(devid,1))!=0)
                        return ret;
                break;
        default:
                return -ENODEV;
        }
        return 0;
#endif
}
#endif


/*
 * Module glue.
 */
#include "version.h"
#include <linux/ethtool.h>

#if !defined(ATH_PCI) || !defined(USE_PLATFORM_FRAMEWORK)
    static char *version = ATH_PCI_VERSION " (Atheros/multi-bss)";
    static char *dev_info = "ath_ahb";
#endif

#if !defined(ATH_PCI)
/*
 * Typically, only one of ATH_PCI or ATH_AHB will be defined.
 * This file getting compiled implies ATH_AHB is defined.
 * However, in the 'dual' bus case, the foll. definition and
 * the one from pci will conflict. Hence, knock this off if
 * PCI is also defined (i.e. dual case).
 */
int
ath_ioctl_ethtool(struct ath_softc *sc, int cmd, void *addr)
{
	struct ethtool_drvinfo info;

	if (cmd != ETHTOOL_GDRVINFO)
		return -EOPNOTSUPP;
	memset(&info, 0, sizeof(info));
	info.cmd = cmd;
	strncpy(info.driver, dev_info, sizeof(info.driver)-1);
	strncpy(info.version, version, sizeof(info.version)-1);
	return _copy_to_user(addr, &info, sizeof(info)) ? -EFAULT : 0;
}
#endif /* ATH_PCI */

MODULE_AUTHOR("Atheros Communications, Inc.");
MODULE_DESCRIPTION("Support for Atheros 802.11 wireless LAN cards.");
MODULE_SUPPORTED_DEVICE("Atheros WLAN cards");
#ifdef MODULE_LICENSE
MODULE_LICENSE("Dual BSD/GPL");
#endif

#if !defined(USE_PLATFORM_FRAMEWORK)

int __init
init_ath_ahb(void)
{
    printk(KERN_INFO "%s: %s\n", dev_info, version);

	if (init_ahb() != 0) {
		printk("ath_ahb: No devices found, driver not installed.\n");
		return (-ENODEV);
	}
	

#ifdef notyet
#if defined(CONFIG_SYSCTL) && !defined(AR9100)
    ath_sysctl_register();
#endif
#endif
    return (0);

}

void __exit
exit_ath_ahb(void)
{
#ifdef notyet
#if defined(CONFIG_SYSCTL) && !defined(AR9100)
    ath_sysctl_unregister();
#endif
#endif

    exit_ath_wmac(0);
#if 0
#ifdef AR9100
	exit_ath_wmac(0);
#else
	exit_ath_wmac(AR531X_WLAN0_NUM);
	exit_ath_wmac(AR531X_WLAN1_NUM);
#endif
#endif

    printk(KERN_INFO "%s: driver unloaded\n", dev_info);
}

#else
static const struct platform_device_id ath9k_platform_id_table[] = {
	{
		.name = "ath9k",
		.driver_data = AR5416_AR9100_DEVID,
	},
	{
		.name = "ar933x_wmac",
		.driver_data = AR9300_DEVID_AR9380_PCIE,
	},
	{
		.name = "ar934x_wmac",
		.driver_data = AR9300_DEVID_AR9340,
	},
	{
		.name = "qca955x_wmac",
		.driver_data = AR9300_DEVID_AR955X,
	},
	{
		.name = "qca956x_wmac",
		.driver_data = AR9300_DEVID_AR956X,
	},
	{
		.name = "qca953x_wmac",
		.driver_data = AR9300_DEVID_AR953X,
	},
	{},
};

static int ath_ahb_probe(struct platform_device *pdev)
{
	const struct platform_device_id *id = platform_get_device_id(pdev);
	int ret;

	spdev = pdev;

	if (!pdev->dev.platform_data) {
		printk("no platform data specified\n");
		ret = -EINVAL;
		goto out;
	}

	ret = init_ath_wmac(id->driver_data, 0);
out:
	return ret;
}

static int ath_ahb_remove(struct platform_device *pdev)
{
	spdev = NULL;
	exit_ath_wmac(0);
	return 0;
}

static struct platform_driver ath_ahb_driver = {
	.probe      = ath_ahb_probe,
	.remove     = ath_ahb_remove,
	.driver		= {
		.name	= "ath9k",
		.owner	= THIS_MODULE,
	},
	.id_table    = ath9k_platform_id_table,
};

MODULE_DEVICE_TABLE(platform, ath9k_platform_id_table);

int init_ath_ahb(void)
{
	return platform_driver_register(&ath_ahb_driver);
}

void exit_ath_ahb(void)
{
	platform_driver_unregister(&ath_ahb_driver);
}
#endif

#if !defined(ATH_PCI)
module_init(init_ath_ahb);
module_exit(exit_ath_ahb);
#endif /* ATH_PCI */
