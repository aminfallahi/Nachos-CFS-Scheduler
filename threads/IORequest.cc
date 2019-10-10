/* 
 * File:   IORequest.cc
 * Author: amin
 * 
 * Created on October 9, 2019, 6:56 PM
 */

#include "IORequest.h"

IORequest::IORequest()
{
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