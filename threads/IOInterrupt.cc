/* 
 * File:   IOInterrupt.cc
 * Author: amin
 * 
 * Created on October 11, 2019, 4:36 PM
 */

#include "IOInterrupt.h"
#include "IORequest.h"
#include "kernel.h"

#define MAX_WAIT_TIME_READ 10
#define MAX_WAIT_TIME_WRITE 5

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
	IORequest* req = new IORequest();
	int waitTime = (rand() % MAX_WAIT_TIME_READ + 1)*10;
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
        buffer="hello";
	printf("IO read processed for request %d\n",req->getId());
        delete req;
}

void IOInterrupt::write(Thread* th, char* w)
{
	IORequest* req = new IORequest();
	int waitTime = (rand() % MAX_WAIT_TIME_WRITE + 1)*10;
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
        delete req;
}
