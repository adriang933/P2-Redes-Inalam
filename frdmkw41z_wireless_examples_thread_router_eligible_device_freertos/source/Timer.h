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
/* KSDK */
#include "fsl_common.h"
#include "EmbeddedTypes.h"
#include "fsl_os_abstraction.h"
#include "shell.h"

#define gMyNewTaskEvent1_c (1 << 0)
#define gMyNewTaskEvent2_c (1 << 1)
#define gMyNewTaskEvent3_c (1 << 2)

#define gMyTaskPriority_c 3
#define gMyTaskStackSize_c 400
void My_Task(osaTaskParam_t argument);
void MyTaskTimer_Start(void);
void MyTaskTimer_Stop(void);
void MyTask_Init(void);
static void myTaskTimerCallback(void *param);

#endif /* TIMER_H_ */