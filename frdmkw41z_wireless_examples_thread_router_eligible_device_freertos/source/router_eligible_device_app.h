/*
* Copyright (c) 2014 - 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2017 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef _ROUTER_ELIGIBLE_DEVICE_APP_H_
#define _ROUTER_ELIGIBLE_DEVICE_APP_H_

/*!=================================================================================================
\file       router_app.h
\brief      This is a header file for the router eligible device demo application.
==================================================================================================*/

/*==================================================================================================
Include Files
==================================================================================================*/

#include "EmbeddedTypes.h"
#include "network_utils.h"
#include "acc_cfg.h"
#include "board.h"
#include "fsl_port.h"
#include <stdlib.h>
/*==================================================================================================
Public macros
==================================================================================================*/                       
#define APP_DEFAULT_DEST_ADDR                   in6addr_realmlocal_allthreadnodes
/*==================================================================================================
Public type definitions
==================================================================================================*/

/* None */

/*==================================================================================================
Public global variables declarations
==================================================================================================*/

/* None */
#define APP_LED_URI_PATH                        "/led"
#define APP_TEMP_URI_PATH                       "/temp"
#define APP_SINK_URI_PATH                       "/sink"
#define APP_RESOURCE1_URI_PATH                       "/team3"
#define APP_RESOURCE2_URI_PATH                       "/resource2"
#define APP_ACC_URI_PATH                       "/accel"
#define APP_ACC2_URI_PATH                       "/accelResp"
#define BOARD_LED_GPIO BOARD_LED_RED_GPIO
#define BOARD_LED_GPIO_PIN BOARD_LED_RED_GPIO_PIN
/*==================================================================================================
Public function prototypes
==================================================================================================*/
ipAddr_t RetCoapDestAddress (void);
uint8_t RetmAppCoapInstId (void);
void LEDsConfig(void);
#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
/*================================================================================================*/


#endif /* _ROUTER_ELIGIBLE_DEVICE_APP_H_ */
