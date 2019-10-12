/* 
 * File:   IOInterrupt.h
 * Author: amin
 *
 * Created on October 11, 2019, 4:36 PM
 */

#ifndef IOINTERRUPT_H
#define	IOINTERRUPT_H

#include "thread.h"
#include "main.h"
class IOInterrupt {
public:
    IOInterrupt();
    IOInterrupt(const IOInterrupt& orig);
    virtual ~IOInterrupt();
    
    void read(Thread*, char*);
    void write(Thread*, char*);
private:

};

#endif	/* IOINTERRUPT_H */

