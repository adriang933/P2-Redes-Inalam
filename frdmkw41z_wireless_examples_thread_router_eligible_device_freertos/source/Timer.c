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
 coapSession_t *pMySession = NULL;
 ipAddr_t Dest;
osaEventId_t          mMyEvents;
uint8_t mAppCoapInstId2;
/* Global Variable to store our TimerID */
tmrTimerID_t myTimerID = gTmrInvalidTimerID_c;
/* Handler ID for task */
osaTaskId_t gMyTaskHandler_ID;
/* Local variable to store the current state of the LEDs */
uint8_t gCounter = 0;

uint8_t ImR2 = 0;

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
  case gMyNewTaskEvent4_c:
	  ImR2 = 1;
	  TMR_StartIntervalTimer(myTimerID, /*myTimerID*/
	       5000, /* Timer's Timeout */
	       myTaskTimerCallback, /* pointer to
	  myTaskTimerCallback function */
	       NULL
	     );

   break;
  case gMyNewTaskEvent2_c: /* Event called from myTaskTimerCallback */

	  if (ImR2 == 0){
		  if(gCounter == 200){
			  gCounter = 0;
			  shell_writeDec(gCounter);
			  shell_write("\r\n");
		  }else{
			  gCounter++;
			  shell_writeDec(gCounter);
			  shell_write("\r\n");
		  }
	  }else{
		  shell_write("Requesting Counter Value");
		  shell_write("\r\n");
		  Dest = RetCoapDestAddress();
		  mAppCoapInstId2 = RetmAppCoapInstId();
		  pMySession = COAP_OpenSession(mAppCoapInstId2);
		  COAP_AddOptionToList(pMySession,COAP_URI_PATH_OPTION, APP_RESOURCE2_URI_PATH,SizeOfString(APP_RESOURCE2_URI_PATH));
			pMySession -> msgType=gCoapConfirmable_c;
			pMySession -> code= gCoapGET_c;
			pMySession -> pCallback =NULL;
			FLib_MemCpy(&pMySession->remoteAddrStorage,&Dest,sizeof(ipAddr_t));
			COAP_Send(pMySession, gCoapMsgTypeConGet_c, 0, 1);
			COAP_CloseSession(pMySession);
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

void MyTaskTimer_StartR2(void)
{
	OSA_EventSet(mMyEvents, gMyNewTaskEvent4_c);
}

uint32_t returnCounterValue(void){
	return gCounter;
}
