/*
 * Timer.h
 *
 *  Created on: 11 nov 2024
 *      Author: adrgm
 */

#ifndef TIMER_H_
#define TIMER_H_

/* Fwk */
#include "TimersManager.h"
#include "FunctionLib.h"
#include "LED.h"
#include "app_init.h"
/* KSDK */
#include "fsl_common.h"
#include "EmbeddedTypes.h"
#include "fsl_os_abstraction.h"
#include "shell.h"
#include "router_eligible_device_app.h"
#include "coap.h"
#include "network_utils.h"

#define APP_RESOURCE2_URI_PATH                       "/resource2"

#define gMyNewTaskEvent1_c (1 << 0)
#define gMyNewTaskEvent2_c (1 << 1)
#define gMyNewTaskEvent3_c (1 << 2)
#define gMyNewTaskEvent4_c (1 << 3)
#define APP_RESOURCE1_URI_PATH                       "/team3"
#define gMyTaskPriority_c 3
#define gMyTaskStackSize_c 400
void My_Task(osaTaskParam_t argument);
void MyTaskTimer_Start(void);
void MyTaskTimer_Stop(void);
void MyTask_Init(void);
void MyTaskTimer_StartR2(void);
uint32_t returnCounterValue(void);
static void myTaskTimerCallback(void *param);
static void CounterASK(uint8_t *pParam);

#endif /* TIMER_H_ */
