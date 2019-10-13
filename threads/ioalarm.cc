// alarm.cc
//	Routines to use a hardware timer device to provide a
//	software alarm clock.  For now, we just provide time-slicing.
//
//	Not completely implemented.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "ioalarm.h"
#include "main.h"

//----------------------------------------------------------------------
// Alarm::Alarm
//      Initialize a software alarm clock.  Start up a timer device
//
//      "doRandom" -- if true, arrange for the hardware interrupts to 
//		occur at random, instead of fixed, intervals.
//----------------------------------------------------------------------

IOAlarm::IOAlarm(bool doRandom)
{
    iotimer = new IOTimer(doRandom, this);
}

//----------------------------------------------------------------------
// Alarm::CallBack
//	Software interrupt handler for the timer device. The timer device is
//	set up to interrupt the CPU periodically (once every TimerTicks).
//	This routine is called each time there is a timer interrupt,
//	with interrupts disabled.
//
//	Note that instead of calling Yield() directly (which would
//	suspend the interrupt handler, not the interrupted thread
//	which is what we wanted to context switch), we set a flag
//	so that once the interrupt handler is done, it will appear as 
//	if the interrupted thread called Yield at the point it is 
//	was interrupted.
//
//	For now, just provide time-slicing.  Only need to time slice 
//      if we're currently running something (in other words, not idle).
//----------------------------------------------------------------------

void 
IOAlarm::CallBack() 
{
	printf("Talking from ioalarm callback. Time is %d and I'm here.\n",kernel->stats->totalTicks);
	
	while (!kernel->IOQueue->IsEmpty()){
		IORequest* req=kernel->IOQueue->Front();
		if (req->getCompletionTime()<=kernel->stats->totalTicks){
			printf("Servicing io request %d with completion time %d\n",req->getId(),req->getCompletionTime());
			kernel->IOQueue->RemoveFront();
			kernel->scheduler->ReadyToRun(req->getThread());
		}
		else
			break;
	}
	
    Interrupt *interrupt = kernel->interrupt;
    MachineStatus status = interrupt->getStatus();
    
    if (status != IdleMode) {
	interrupt->YieldOnReturn();
    }
}
