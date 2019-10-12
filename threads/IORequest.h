/* 
 * File:   IORequest.h
 * Author: amin
 *
 * Created on October 9, 2019, 6:56 PM
 */

#ifndef IOREQUEST_H
#define	IOREQUEST_H
#include "thread.h"


class IORequest {
public:
    IORequest();
    IORequest(bool);
    IORequest(const IORequest& orig);
    virtual ~IORequest();
    int getWaitingTime();
    void setWaitingTime(int);
    void setThread(Thread*);
    int getCompletionTime();
    void setCompletionTime(int);
    void setType(bool);
    Thread* getThread();
private:
    int waitingTime;
    int completionTime;
    bool type; //true=write
    Thread* thread;
};

#endif	/* IOREQUEST_H */

