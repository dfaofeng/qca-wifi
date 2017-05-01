/*
 * Copyright (c) 2004-2009 Atheros Communications Inc.
 * All rights reserved.
 * 
 * $ATH_LICENSE_HOSTSDK0_C$
 *
 *
 */
#define SUPPORT_11N
#include <sys/types.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/types.h>
#include <linux/if.h>
#include <linux/wireless.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <a_config.h>
#include <a_osapi.h>
#include <athdefs.h>
#include <a_types.h>
#include <wmi.h>
#include <ar6kap_common.h>
#include "athdrv_linux.h"
//#include "ieee80211.h"
//#include "ieee80211_ioctl.h"
//#include "wmiconfig.h"
//#include "targaddrs.h"
//#include "pkt_log.h"

#define _BUF_SIZE  32

A_BOOL sendData2DUTAtomic(A_UINT8 *dataBuf, A_UINT32 startAddr, A_UINT32 length)
{
    int s, i;
    char ifname[IFNAMSIZ];
    struct ifreq ifr;
    char buf[_BUF_SIZE];
    A_UINT32 *diagaddr = (A_UINT32 *)(buf + 4);
    A_UINT32 *diagdata = (A_UINT32 *)(buf + 8);
    char *ethIf;

    memset(buf, 0, sizeof(buf));
    memset(ifname, '\0', IFNAMSIZ);
    if ((ethIf = getenv("NETIF")) == NULL) {
        ethIf = "eth1";
    }
    strcpy(ifname, ethIf);
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        printf("Error: socket\n");
        return(FALSE);
    }

    for (i=0, *diagaddr = startAddr; i< length; i +=4, *diagaddr +=4) {
        *diagdata = *((A_UINT32 *) &dataBuf[i]);
        ((int *)buf)[0] = AR6000_XIOCTL_DIAG_WRITE;
        ifr.ifr_data = buf;
        if (ioctl(s, AR6000_IOCTL_EXTENDED, &ifr) < 0) {
            printf("Error %s", ifr.ifr_name);
            return(FALSE);
        }
    }

    return(TRUE);
}

static struct ifreq ifr;
static int s;

//
// Usage:
// int s
// open2DUT(&s);
// sendData2DUT(s, &buf, startAddr, length);
//
A_BOOL open2DUT(void)
{
    char ifname[IFNAMSIZ];
    char *ethIf;

    memset(ifname, '\0', IFNAMSIZ);
    if ((ethIf = getenv("NETIF")) == NULL) {
        ethIf = "eth1";
    }
    strcpy(ifname, ethIf);
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        printf("Error: socket\n");
        return(FALSE);
    }
    strncpy(ifr.ifr_name, ifname, sizeof(ifr.ifr_name));
    return(TRUE);
}

A_BOOL sendDataBuf2DUT(A_UINT8 *dataBuf, A_UINT32 startAddr, A_UINT32 length)
{
    char buf[_BUF_SIZE];
    A_UINT32 *diagaddr = (A_UINT32 *)(buf + 4);
    A_UINT32 *diagdata = (A_UINT32 *)(buf + 8);
    int i;

    memset(buf, 0, sizeof(buf));
    for (i=0, *diagaddr = startAddr; i< length; i +=4, *diagaddr +=4) {
        *diagdata = *((A_UINT32 *) &dataBuf[i]);
        ((int *)buf)[0] = AR6000_XIOCTL_DIAG_WRITE;
        ifr.ifr_data = buf;
        if (ioctl(s, AR6000_IOCTL_EXTENDED, &ifr) < 0) {
            printf("Error %s", ifr.ifr_name);
            return(FALSE);
        }
    }

    return(TRUE);
}

A_BOOL sendReg2DUT(A_UINT32 data, A_UINT32 addr)
{
    char buf[_BUF_SIZE];
    A_UINT32 *diagaddr = (A_UINT32 *)(buf + 4);
    A_UINT32 *diagdata = (A_UINT32 *)(buf + 8);

    memset(buf, 0, sizeof(buf));
    *diagaddr = addr;
    *diagdata = data;
    ((int *)buf)[0] = AR6000_XIOCTL_DIAG_WRITE;
    ifr.ifr_data = buf;
    if (ioctl(s, AR6000_IOCTL_EXTENDED, &ifr) < 0) {
        printf("Error %s", ifr.ifr_name);
        return(FALSE);
    }

    return(TRUE);
}



A_BOOL sendData2DUT_tmp(A_UINT8 *pBuf, A_INT32 length)
{
    int c, s;
    char ifname[IFNAMSIZ];
    char buf[_BUF_SIZE];
    char *ethIf;
    A_UINT32 *diagaddr; 
    A_UINT32 *diagdata;
    A_BOOL rc;

    memset(buf, 0, sizeof(buf));
    memset(ifname, '\0', IFNAMSIZ);
    if ((ethIf = getenv("NETIF")) == NULL) {
        ethIf = "eth1";
    }
    strcpy(ifname, ethIf);
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        err(1, "socket");
    }

    strncpy(ifr.ifr_name, ifname, sizeof(ifr.ifr_name));

    diagaddr = (A_UINT32 *)(buf + 4);
    diagdata = (A_UINT32 *)(buf + 8);

    memset(buf, 0, sizeof(buf));
    *diagaddr = (A_UINT32)0x540688;
    *diagdata = (A_UINT32)512;
    ((int *)buf)[0] = AR6000_XIOCTL_DIAG_WRITE;
    ifr.ifr_data = buf;
    if (ioctl(s, AR6000_IOCTL_EXTENDED, &ifr) < 0) {
        printf("Error %s", ifr.ifr_name);
        return(FALSE);
    }

        ((int *)buf)[0] = AR6000_XIOCTL_DIAG_WRITE;
        ifr.ifr_data = buf;
        if (ioctl(s, AR6000_IOCTL_EXTENDED, &ifr) < 0) {
            err(1, "%s", ifr.ifr_name);
        }


#if 0
    case DIAG_READ:
        ((int *)buf)[0] = AR6000_XIOCTL_DIAG_READ;
        ifr.ifr_data = buf;
        if (ioctl(s, AR6000_IOCTL_EXTENDED, &ifr) < 0) {
            err(1, "%s", ifr.ifr_name);
        }
        printf("diagdata: 0x%x\n", *diagdata);
        break;
    case DIAG_WRITE:
        ((int *)buf)[0] = AR6000_XIOCTL_DIAG_WRITE;
        ifr.ifr_data = buf;
        if (ioctl(s, AR6000_IOCTL_EXTENDED, &ifr) < 0) {
            err(1, "%s", ifr.ifr_name);
        }
    case DIAG_DUMP_CHIP_MEM_VENUS:
        printf("Venus:Chip state\n");
        for(i = 0; i < 8; i++) {
            p = &venus_internal[i];
            printf("%s\n", p->info);
            printf("Address range = 0x%x, 0x%x\n",
                    p->addr_st, p->addr_end);
            for(*diagaddr = p->addr_st;
                *diagaddr < p->addr_end;
                *diagaddr += 4) {
                ((int *)buf)[0] = AR6000_XIOCTL_DIAG_READ;
                ifr.ifr_data = buf;
                if (ioctl(s, AR6000_IOCTL_EXTENDED, &ifr) < 0) {
                    err(1, "%s", ifr.ifr_name);
                }
                printf("0x%04x:0x%04x\n", *diagaddr, *diagdata);
            }
            printf("\n");
        }
        break;
#endif
}

