/* Standard Includes */
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

/* Local Includes */
#include "sorter.h"

/* Global Variables */
int A[MAXSIZE];
int n = 0;
int totalSwaps = 0;
int swapT1 = 0;
int swapT2 = 0;
bool doneT1 = false;
bool doneT2 = false;
int turn = 1;
pthread_mutex_t lock;
pthread_cond_t cond;

/*
*   Function: threadT1
*   Purpose : Sorts even-indexed pairs in the array A.
*   Params  : void* arg
*/
void* threadT1(void* arg)
{
    /*Obtain thread ID*/
    pthread_t tID = pthread_self();

    while(true)
    {
        /*Lock state*/
        pthread_mutex_lock(&lock);

        /*Wait until T1's turn*/
        while (turn != 1)
        {
            pthread_cond_wait(&cond, &lock);
        }

        int swaps = 0;

        /*Loop through even pairs*/
        for (int i = 0; i + 1 < n; i += 2)
        {
            if (A[i] > A[i +1])
            {
                /*Swap if out of order*/
                int temp = A[i];
                A[i] = A[i +1];
                A[i + 1] = temp;
                swaps++;
            }
        }

        /*Update statistics*/
        swapT1 += swaps;
        totalSwaps += swaps;
        doneT1 = (swaps == 0); //Set as done when no swaps
        
        /*Pass control to T2*/
        turn = 2;
        pthread_cond_broadcast(&cond);  // Wake T2
        pthread_mutex_unlock(&lock);    // Release Lock

        /*Exit if both threads have no swaps*/
        if (doneT1 && doneT2) break;
    }

    /*Print final result for thread*/
    printf("Thread T1 (ID: %lu), Total number of swaps = %d\n", tID, swapT1);
    pthread_exit(NULL);
}

/*
*   Function: threadT2
*   Purpose : Sorts odd-indexed pairs in the array A.
*   Params  : void* arg
*/
void* threadT2(void* arg)
{
    /*Obtain thread ID*/
    pthread_t tID = pthread_self();\

    /*Wait until T2's turn*/
    while (true)
    {
        /*Lock state*/
        pthread_mutex_lock(&lock);

        while (turn != 2)
        {
            pthread_cond_wait(&cond, &lock);
        }

        int swaps = 0;

        /*Loop through odd pairs*/
        for (int i = 1; i + 1 < n; i += 2)
        {
            if (A[i] > A[i +1])
            {
                /*Swap if out of order*/
                int temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                swaps++;
            }
        }

        /*Update statistics*/
        swapT2 += swaps;
        totalSwaps += swaps;
        doneT2 = (swaps == 0); //Set as done when no swaps

        /*Pass control to T1*/
        turn = 1;
        pthread_cond_broadcast(&cond);  // Wake T1
        pthread_mutex_unlock(&lock);    // Release Lock

        /*Exit if both threads have no swaps*/
        if (doneT1 && doneT2) break;
    }
    
    /*Print final result for thread*/
    printf("Thread T2 (ID: %lu), Total number of swaps = %d\n", tID, swapT2);
    pthread_exit(NULL);
}