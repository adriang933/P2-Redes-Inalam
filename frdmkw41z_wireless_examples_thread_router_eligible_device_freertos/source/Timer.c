/*
 * Timer.c
 *
 *  Created on: 11 nov 2024
 *      Author: adrgm
 */


/*
 * MyNewTask.c
 *
 *  Created on: 17 oct 2024
 *      Author: adrgm
 */
#include "Timer.h"

osaEventId_t          mMyEvents;
/* Global Variable to store our TimerID */
tmrTimerID_t myTimerID = gTmrInvalidTimerID_c;
/* Handler ID for task */
osaTaskId_t gMyTaskHandler_ID;
/* Local variable to store the current state of the LEDs */
uint8_t gCounter = 0;

/* OSA Task Definition*/
OSA_TASK_DEFINE(My_Task, gMyTaskPriority_c, 1, gMyTaskStackSize_c, FALSE );
/* Main custom task */
void My_Task(osaTaskParam_t argument)
{
 osaEventFlags_t customEvent;
 myTimerID = TMR_AllocateTimer();

 while(1)
 {
  OSA_EventWait(mMyEvents, osaEventFlagsAll_c, FALSE, osaWaitForever_c,
&customEvent);

  if( !gUseRtos_c && !customEvent)
  {
   break;
  }

  /* Depending on the received event */
  switch(customEvent){
  case gMyNewTaskEvent1_c:
   TMR_StartIntervalTimer(myTimerID, /*myTimerID*/
     1000, /* Timer's Timeout */
     myTaskTimerCallback, /* pointer to
myTaskTimerCallback function */
     NULL
   );

   break;
  case gMyNewTaskEvent2_c: /* Event called from myTaskTimerCallback */
	  if(gCounter == 200){
		  gCounter = 0;
		  shell_writeDec(gCounter);
		  shell_write("\r\n");
	  }else{
		  gCounter++;
		  shell_writeDec(gCounter);
		  shell_write("\r\n");
	  }

   break;
  case gMyNewTaskEvent3_c: /* Event to stop the timer */
   TMR_StopTimer(myTimerID);
   break;
  default:
   break;
  }
 }
}

/* Function to init the task */
void MyTask_Init(void)
{
mMyEvents = OSA_EventCreate(TRUE);
/* The instance of the MAC is passed at task creaton */
gMyTaskHandler_ID = OSA_TaskCreate(OSA_TASK(My_Task), NULL);
}


/* This is the function called by the Timer each time it expires */
static void myTaskTimerCallback(void *param)
{
OSA_EventSet(mMyEvents, gMyNewTaskEvent2_c);
}

/* Public function to send an event to stop the timer */
void MyTaskTimer_Stop(void)
{
OSA_EventSet(mMyEvents, gMyNewTaskEvent3_c);
}

void MyTaskTimer_Start(void)
{
	OSA_EventSet(mMyEvents, gMyNewTaskEvent1_c);
}

uint32_t returnCounterValue(){
	return gCounter;
}
