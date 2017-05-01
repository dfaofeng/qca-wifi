/*
 * Copyright (c) 2008-2010, Atheros Communications Inc. 
 * All Rights Reserved.
 * 
 * Copyright (c) 2011 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * 
 */

//----------------------------------------------------------------------------
//
//  Project:   Seattle_Release
//
//  Filename:  bt_debug.c
//
//  Author:    Mike Tsai
//
//  Created:   6/19/2008
//
//  Descriptions:
//
//    - Provide some generic debug utility
//    
//
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//
//  Includes
//
//----------------------------------------------------------------------------
#include <stdio.h>
#include <conio.h>
#include <stdarg.h>
#include "bt_debug.h"
#include "wdm.h"
//----------------------------------------------------------------------------
//
//  Defines
//
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//
//  Types
//
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//
//  Local Variables
//
//----------------------------------------------------------------------------

const char *szDbgList[] = 
{
	"DBG_GLOBAL: ",
	"DBG_ERTM: ",
	"DBG_AMP: ",
	"DBG_PAL: "
};

btDbgSetting BT_DbgSetting = {
	DL_VERY_LOUD,  //declare the debug level here, will change to registry setting
	{1, 1, 1, 1}   //All control blocks enabled
};


