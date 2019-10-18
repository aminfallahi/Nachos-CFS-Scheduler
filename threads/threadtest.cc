#include "kernel.h"
#include "main.h"
#include "thread.h"
#include "IOInterrupt.h"

IOInterrupt* ioint;

void
SimpleThread(int which) {
    /*    int num;
    
            for (num = 0; num < 5; num++) {
                    printf("*** thread %d looped %d times\n", which, num);
                    kernel->currentThread->Yield();
            }*/
    int job = rand() % 3; //0: cpu bound; 1: read; 2: write
    if (job == 0) {
        //kernel->currentThread->wasteTime();
        unsigned long int i;
        //for (i=0; i<100000000; i++) rand();
    } else if (job == 1) {
        ioint->read(kernel->currentThread, "hello");
    } else {
        ioint->write(kernel->currentThread, "hello");
    }
}

void
ThreadTest() {
    IORequest::lastId = 0;
    srand(time(NULL));
    /*RedBlackTree test;
    test=Initialize();
    test=MakeEmpty(test);*/

    Thread * t[20];
    int i;
    char* threadNum=new char;
    for (i = 0; i < 20; i++) {
        sprintf(threadNum, "%d", i);
        t[i] = new Thread(threadNum);
        t[i]->Fork((VoidFunctionPtr) SimpleThread, (void *) 1);
    }
    //while (true)
        //printf("HOOOOOOOOOO %d",Scheduler::amin);
    /*Thread* t[20];
    t[0]=new Thread("1");
    t[0]->Fork((VoidFunctionPtr) SimpleThread, (void *) 1);
    t[1]=new Thread("2");
    t[1]->Fork((VoidFunctionPtr) SimpleThread, (void *) 1);
    t[2]=new Thread("3");
    t[2]->Fork((VoidFunctionPtr) SimpleThread, (void *) 1);
    t[3]=new Thread("4");
    t[3]->Fork((VoidFunctionPtr) SimpleThread, (void *) 1);
    t[4]=new Thread("5");
    t[4]->Fork((VoidFunctionPtr) SimpleThread, (void *) 1);

    test=Insert(t[1],test);
    test=Insert(t[0],test);
    test=Insert(t[2],test);
    test=Insert(t[3],test);
    test=Insert(t[4],test);
    if (t[1]==t[2])
        printf("999999999HEEEELLLOO\n");

    printf("$$$$$$$$$ %d %d %d %d %d\n",t[0]->getVRT(),t[1]->getVRT(), t[2]->getVRT(),t[3]->getVRT(),t[4]->getVRT());
    printf("********");
    PrintTree(test);*/
    
    //SimpleThread(0);

    /*while (true) {
            kernel->interrupt->SetLevel(IntOff);
            kernel->interrupt->SetLevel(IntOn);
    }*/
}
