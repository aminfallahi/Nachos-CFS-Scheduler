#include "kernel.h"
#include "main.h"
#include "thread.h"
#include "IOInterrupt.h"

IOInterrupt* ioint;

void write(Thread* th)
{
	IORequest* ioreq = new IORequest(true);
	ioreq->setThread(th);
	int waitTime = rand() % 50;
	ioreq->setWaitingTime(waitTime);
	ioreq->setCompletionTime(kernel->stats->totalTicks + waitTime);
	//kernel->addToIOQueue(ioreq);
	th->block();
	printf("I am done writing\n");
}

void read(Thread* th)
{
	IORequest* ioreq = new IORequest(false);
	ioreq->setThread(th);
	int waitTime = rand() % 50 + 50;
	ioreq->setWaitingTime(waitTime);
	ioreq->setCompletionTime(kernel->stats->totalTicks + waitTime);
	//kernel->addToIOQueue(ioreq);
	th->block();
	printf("I am done reading\n");
}

void
SimpleThread(int which)
{
	/*    int num;
    
		for (num = 0; num < 5; num++) {
			printf("*** thread %d looped %d times\n", which, num);
			kernel->currentThread->Yield();
		}*/
	srand(time(NULL));
	int job = rand() % 3; //0: cpu bound; 1: read; 2: write
	if (job == 0) {
		//kernel->currentThread->wasteTime();
	} else if (job == 1) {
		ioint->read(kernel->currentThread,"hello");
	} else {
		ioint->write(kernel->currentThread,"hello");
	}
}

void
ThreadTest()
{
	
	Thread *t = new Thread("forked thread");
	int i;
	//for (i=0; i<20; i++)
		t->Fork((VoidFunctionPtr) SimpleThread, (void *) 1);

	//SimpleThread(0);

	/*while (true) {
		kernel->interrupt->SetLevel(IntOff);
		kernel->interrupt->SetLevel(IntOn);
	}*/
}
