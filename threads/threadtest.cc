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

    Thread * t[20];
    int i;
    for (i = 0; i < 20; i++) {
        char* threadNum;
        sprintf(threadNum, "%d", i);
        t[i] = new Thread(threadNum);
        t[i]->Fork((VoidFunctionPtr) SimpleThread, (void *) 1);
    }
    
    //RedBlackTree test;
    //test=Initialize();
    //test=MakeEmpty(test);
    //test=Insert(t[i],test);
    //PrintTree(test);
    
    //SimpleThread(0);

    /*while (true) {
            kernel->interrupt->SetLevel(IntOff);
            kernel->interrupt->SetLevel(IntOn);
    }*/
}
