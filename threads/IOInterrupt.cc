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
	IORequest* req=new IORequest();
	int waitTime = rand() % 50 + 50;
	req->setType(false);
	req->setWaitingTime(waitTime);
	req->setCompletionTime(kernel->stats->totalTicks + waitTime);
	req->setThread(th);
	kernel->IOQueue->Insert(req);
	//kernel->iotimer->SetInterrupt(waitTime);
	kernel->interrupt->SetLevel(IntOff);
	th->Sleep(false);
}

void IOInterrupt::write(Thread* th, char* w)
{
	printf("IOInterupt::write()\n");
	IORequest* req= new IORequest();
	int waitTime = rand() % 50;
	req->setType(false);
	req->setWaitingTime(waitTime);
	req->setCompletionTime(kernel->stats->totalTicks + waitTime);
	req->setThread(th);
	kernel->IOQueue->Insert(req);
	//kernel->iotimer->SetInterrupt(waitTime);
	kernel->interrupt->SetLevel(IntOff);
	th->Sleep(false);
}
