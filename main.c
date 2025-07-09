/* Standard Includes*/
#include <stdio.h>
#include <stdlib.h>

/* Local Includes*/
#include "sorter.h"
#include "readFile.h"

int main(int argc, char *argv[])
{
    int i;
    pthread_t T1, T2;

    /*Checks for proper in line argument usage*/
    if (argc != 2)
    {
        printf("Usage: ./sss file.txt\n");
        exit(EXIT_FAILURE);
    }

    /*Reads data from file*/
    readDataFromFile(argv[1]);

    /*Prints out the initial unsorted array*/
    printf("Initial Array: ");
    for (i = 0; i < n; i++ )
    {
        printf("%d, ", A[i]);
    }
    printf("\n");

    /*Initializing mutex and condition variable*/
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    /*Starting both threads*/
    pthread_create(&T1, NULL, threadT1, NULL);
    pthread_create(&T2, NULL, threadT2, NULL);

    /*Waiting for both threads to finish*/
    pthread_join(T1, NULL);
    pthread_join(T2, NULL);

    /*Prints out final sorter array*/
    printf("Sorted array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d, ", A[i]);
    }
    /*Prints out total number of swaps performed*/
    printf("\nTotal number of swaps to sort array A = %d\n", totalSwaps);

    /*Clean up synchronization resources*/
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}   