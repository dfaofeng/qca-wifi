#------------------------------------------------------------------------------
# <copyright file="makefile" company="Atheros">
#    Copyright (c) 2005-2010 Atheros Corporation.  All rights reserved.
# $ATH_LICENSE_HOSTSDK0_C$
#------------------------------------------------------------------------------
#==============================================================================
# Author(s): ="Atheros"
#==============================================================================

#
#  Copyright (c) 2014 Qualcomm Atheros, Inc.  All rights reserved. 
#
#  Qualcomm is a trademark of Qualcomm Incorporated, registered in the United
#  States and other countries.  All Qualcomm Incorporated trademarks are used with
#  permission.  Atheros is a trademark of Qualcomm Atheros, Inc., registered in
#  the United States and other countries.  Other products and brand names may be
#  trademarks or registered trademarks of their respective owners. 
#

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/../../include \
    $(LOCAL_PATH)/../../os/linux/include \
    $(LOCAL_PATH)/../../../include \

LOCAL_CFLAGS+= 
LOCAL_SRC_FILES:= athtestcmd.c
LOCAL_MODULE := athtestcmd
LOCAL_MODULE_TAGS := debug eng optional

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)
LOCAL_MODULE = libathtestcmd
LOCAL_MODULE_TAGS := debug eng optional
LOCAL_CFLAGS = $(L_CFLAGS)
LOCAL_SRC_FILES = athtestcmd.c athtestcmdlib.c
LOCAL_C_INCLUDES := \
        $(LOCAL_PATH)/../../include \
    $(LOCAL_PATH)/../../os/linux/include \
    $(LOCAL_PATH)/../../../include \

LOCAL_CFLAGS+=-DATHTESTCMD_LIB

LOCAL_SHARED_LIBRARIES := libcutils
LOCAL_COPY_HEADERS_TO := libathtestcmd
LOCAL_COPY_HEADERS := athtestcmdlib.h
include $(BUILD_STATIC_LIBRARY)

