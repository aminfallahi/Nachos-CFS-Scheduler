/* 
 * File:   IOHandler.cc
 * Author: amin
 * 
 * Created on October 11, 2019, 8:23 PM
 */

#include "IOHandler.h"

IOHandler::IOHandler()
{
}

IOHandler::IOHandler(const IOHandler& orig)
{
}

IOHandler::~IOHandler()
{
}

void IOHandler::read(IORequest* req)
{
	kernel->scheduler->ReadyToRun(req->getThread());
}
