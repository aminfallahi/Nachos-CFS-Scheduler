/* 
 * File:   IORequest.cc
 * Author: amin
 * 
 * Created on October 9, 2019, 6:56 PM
 */

#include "IORequest.h"

int IORequest::lastId;

IORequest::IORequest()
{
	id=lastId;
	lastId++;
	printf("Creating new IO Request with id %d\n",id);
}

IORequest::IORequest(const IORequest& orig)
{
}

IORequest::~IORequest()
{
}

IORequest::IORequest(bool t)
{
	type = t;
}

int IORequest::getCompletionTime()
{
	return completionTime;
}

Thread* IORequest::getThread()
{
	return thread;
}

int IORequest::getWaitingTime()
{
	return waitingTime;
}

void IORequest::setCompletionTime(int ct)
{
	completionTime=ct;
}

void IORequest::setThread(Thread* th)
{
	thread=th;
}

void IORequest::setType(bool t)
{
	type=t;
}

void IORequest::setWaitingTime(int wt)
{
	waitingTime=wt;
}

int IORequest::getId()
{
	return id;
}

bool operator==(const IORequest &r1, const IORequest &r2){
	return r1.id==r2.id;
}