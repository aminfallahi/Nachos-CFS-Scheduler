#include "kernel.h"
#include "main.h"
#include "thread.h"
#include "IOInterrupt.h"

#define MAX_NUM_TASKS 5
#define MAX_WASTE_TIME 10
#define NUM_OF_THREADS 20

IOInterrupt* ioint;

void wasteTime(int w) {
    int i = 0;
    for (i = 0; i < w * 10000000; i++);
}

void
SimpleThread(int which) {

    int tasks[MAX_NUM_TASKS]; //this will store tasks 0=cpu wasteTime, 1=read, 2=write
    int tasksCount[3] = {0}; //this will count the number of each task to be done by this thread
    int numTasks = rand() % MAX_NUM_TASKS + 1; //how many tasks to run? choosing from read, write, and wasteTime
    int i;

    for (i = 0; i < numTasks; i++) {
        int taskNum = rand() % 3; //choose between read, write, and wasteTime
        tasks[i] = taskNum;
        tasksCount[taskNum]++;
    }

    printf("Talking from thread %s. Will do %d cpu bound tasks, %d reads, and %d writes\n", kernel->currentThread->getName(), tasksCount[0], tasksCount[1], tasksCount[2]);

    for (i = 0; i < numTasks; i++) {
        if (tasks[i] == 0) {
            wasteTime(rand() % MAX_WASTE_TIME); //waste time for random amount of instructions
        } else if (tasks[i] == 1) {
            char *buffer;
            ioint->read(kernel->currentThread, buffer);
        } else
            ioint->write(kernel->currentThread, "hello");
    }


}

void
ThreadTest() {
    IORequest::lastId = 0;
    srand(time(NULL));

    Thread * t[NUM_OF_THREADS];
    int i;
    for (i = 0; i < NUM_OF_THREADS; i++) {
        char* threadNum = new char;
        sprintf(threadNum, "%d", i);
        t[i] = new Thread(threadNum);
        t[i]->Fork((VoidFunctionPtr) SimpleThread, (void *) i);
    }

}
