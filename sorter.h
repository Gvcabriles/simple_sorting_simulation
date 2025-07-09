#ifndef SORTER_H
#define SORTER_H

#include <pthread.h>
#include <stdbool.h>

#define MAXSIZE 200

extern pthread_mutex_t lock;
extern pthread_cond_t cond;

extern int turn;
extern int n;
extern int A[MAXSIZE];
extern int swapT1;
extern int swapT2;
extern bool doneT1;
extern bool doneT2;
extern int totalSwaps;

void* threadT1(void* arg);
void* threadT2(void* arg);



#endif 