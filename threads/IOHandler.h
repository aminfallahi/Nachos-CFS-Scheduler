/* 
 * File:   IOHandler.h
 * Author: amin
 *
 * Created on October 11, 2019, 8:23 PM
 */

#ifndef IOHANDLER_H
#define	IOHANDLER_H


#include "kernel.h"
#include "main.h"
#include "IORequest.h"

class IOHandler {
public:
    IOHandler();
    IOHandler(const IOHandler& orig);
    virtual ~IOHandler();
    void read(IORequest*);
    void write(IORequest*);

private:

};

#endif	/* IOHANDLER_H */

