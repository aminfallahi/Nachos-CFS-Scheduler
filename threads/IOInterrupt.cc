/* 
 * File:   IOInterrupt.cc
 * Author: amin
 * 
 * Created on October 11, 2019, 4:36 PM
 */

#include "IOInterrupt.h"
#include "IORequest.h"
#include "kernel.h"

IOInterrupt::IOInterrupt()
{
}

IOInterrupt::IOInterrupt(const IOInterrupt& orig)
{
}

IOInterrupt::~IOInterrupt()
{
}

void IOInterrupt::read(Thread* th, char* buffer)
{
	printf("IOInterupt::read()\n");
	IORequest* req = new IORequest();
	int waitTime = (rand() % 10 + 1)*10;
	req->setType(false);
	req->setWaitingTime(waitTime);
	req->setCompletionTime(kernel->stats->totalTicks + waitTime);
	req->setThread(th);
	printf("Creating read IO request with id %d waitingTime %d completionTime %d\n",req->getId(),waitTime,req->getCompletionTime());
	kernel->IOQueue->Insert(req);
	//kernel->iotimer->SetInterrupt(waitTime);
	kernel->interrupt->Schedule(kernel->ioalarm, waitTime, TimerInt);
	kernel->interrupt->SetLevel(IntOff);
	th->Sleep(false);
	printf("IO read processed for request %d\n",req->getId());
}

void IOInterrupt::write(Thread* th, char* w)
{
	printf("IOInterupt::write()\n");
	IORequest* req = new IORequest();
	int waitTime = (rand() % 5 + 1)*10;
	req->setType(true);
	req->setWaitingTime(waitTime);
	req->setCompletionTime(kernel->stats->totalTicks + waitTime);
	req->setThread(th);
	printf("Creating write IO request with id %d waitingTime %d completionTime %d\n",req->getId(),waitTime,req->getCompletionTime());
	kernel->IOQueue->Insert(req);
	//kernel->iotimer->SetInterrupt(waitTime);
	kernel->interrupt->Schedule(kernel->ioalarm, waitTime, TimerInt);
	kernel->interrupt->SetLevel(IntOff);
	th->Sleep(false);
	printf("IO write processed for request %d\n",req->getId());
}
