//------------------------------------------------------------------------------
// <copyright file="floodtest.h" company="Atheros">
//    Copyright (c) 2004-2007 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

/* Floodtest Application Message Interface */

#define FLOOD_TX 0 /* From Host to Target */
#define FLOOD_RX 1 /* From Target to Host */

struct floodtest_control_s {
    A_UINT32 direction;        /* FLOOD_RX or FLOOD_TX */
    A_UINT32 message_size;     /* in bytes, for SEND/RX only */
    A_UINT32 duration;         /* in seconds, for SEND/RX only */
};

