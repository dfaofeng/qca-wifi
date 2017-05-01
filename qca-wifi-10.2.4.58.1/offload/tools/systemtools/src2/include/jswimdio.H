/*************************************************************************
 * Copyright ?2004 Atheros Communications, Inc., All Rights Reserved
 *
 * Atheros and the Atheros logo and design are trademarks of Atheros
 * Communications, Inc.
 *
 * Sample Code from Microsoft Windows XP Driver Development Kit is
 * used under license from Microsoft Corporation
 *************************************************************************/

#ifndef _JSWIMDIO__H
#define _JSWIMDIO__H

//
//  Structure to go with IOCTL_ATHJSWCT_SET_INFORMATION.
//  The Data part is of variable length, determined
//  by the input buffer length passed to DeviceIoControl.
//
typedef struct _NDISIM_SET_OID
{
    NDIS_OID        Oid;
    UCHAR           Data[sizeof(ULONG)];

} NDISIM_SET_OID, *PNDISIM_SET_OID;

#define FSCTL_ATHJSWCT_BASE      FILE_DEVICE_NETWORK

#define _ATHJSWCT_CTL_CODE(_Function, _Method, _Access)  \
            CTL_CODE(FSCTL_ATHJSWCT_BASE, _Function, _Method, _Access)

#define IOCTL_ATHJSWCT_ENUMERATE   \
            _ATHJSWCT_CTL_CODE(0x201, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
    
#define IOCTL_ATHJSWCT_OPEN_ADAPTER   \
            _ATHJSWCT_CTL_CODE(0x202, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_ATHJSWCT_CLOSE_ADAPTER   \
            _ATHJSWCT_CTL_CODE(0x203, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
    
#define IOCTL_ATHJSWCT_QUERY_INFORMATION   \
            _ATHJSWCT_CTL_CODE(0x204, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
    
#define IOCTL_ATHJSWCT_SET_INFORMATION   \
            _ATHJSWCT_CTL_CODE(0x205, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_ATHJSWCT_SET_FILTER   \
            _ATHJSWCT_CTL_CODE(0x206, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)    

#endif // __IOCOMMON__H

