#CC := $(ATH_CROSS_COMPILE_TYPE)gcc
CC := mips-linux-uclibc-gcc
CFLAGS  =  -Wall -DLINUX -DLinux -I$(WORKAREA)/include -I$(WORKAREA)/../include -I$(WORKAREA)/os/linux/include  -I$(WORKAREA)/../include/systemtools/common/  -I$(WORKAREA)/os/linux/tools/systemtools -I $(WLAN_TOP)/os/linux/include -I $(WLAN_TOP)/include -I $(WLAN_TOP)/lmac/ath_dev

all:
	$(CC) $(CFLAGS) $(WORKAREA)/os/linux/tools/systemtools/os_if.c athtestcmd.c -o athtestcmd  -lrt
