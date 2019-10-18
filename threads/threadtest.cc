#include "kernel.h"
#include "main.h"
#include "thread.h"
#include "IOInterrupt.h"

IOInterrupt* ioint;

void wasteTime(int w) {
    int i = 0;
    for (i = 0; i < w * 10000000; i++);
}

void
SimpleThread(int which) {
    /*    int num;
    
            for (num = 0; num < 5; num++) {
                    printf("*** thread %d looped %d times\n", which, num);
                    kernel->currentThread->Yield();
            }*/
    /*int job = rand() % 3; //0: cpu bound; 1: read; 2: write
    if (job == 0) {
        //kernel->currentThread->wasteTime();
        unsigned long int i;
        //for (i=0; i<100000000; i++) rand();
    } else if (job == 1) {
        ioint->read(kernel->currentThread, "hello");
    } else {
        ioint->write(kernel->currentThread, "hello");
    }*/

    int tasks[5]; //this will store tasks 0=cpu wasteTime, 1=read, 2=write
    int tasksCount[3]={0}; //this will count the number of each task to be done by this thread
    int numTasks = rand() % 5; //how many tasks to run? choosing from read, write, and wasteTime
    int i;

    for (i = 0; i < numTasks; i++) {
        int taskNum = rand() % 3; //choose between read, write, and wasteTime
        tasks[i] = taskNum; 
        tasksCount[taskNum]++;
    }
    
    printf("Talking from thread %s. Will do %d cpu bound tasks, %d reads, and %d writes\n",kernel->currentThread->getName(),tasksCount[0],tasksCount[1],tasksCount[2]);
    
    for (i = 0; i < numTasks; i++) {
        if (tasks[i] == 0) {
            wasteTime(rand() % 10); //waste time for random amount of instructions
        } else if (tasks[i] == 1){
            char *buffer;
            ioint->read(kernel->currentThread, buffer);
        }
        else
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
        char* threadNum = new char;
        sprintf(threadNum, "%d", i);
        t[i] = new Thread(threadNum);
        t[i]->Fork((VoidFunctionPtr) SimpleThread, (void *) i);
    }

}
