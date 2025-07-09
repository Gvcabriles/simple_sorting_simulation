/* Standard Includes */
#include <stdio.h>
#include <stdlib.h>

/* Local Includes */
#include "sorter.h"
#include "readFile.h"

/*
*  Function : readDataFromFile
*  Purpose  : Reads integers from file. Integers are then stored into global array A.
              Variable 'n' is then updated for every integer read.
*  Params   : fileName - path to data file
*/
void readDataFromFile(const char* fileName)
{
    int result;
    char buffer[100];
    int value;
    char* endptr;

    FILE* dataFile = fopen(fileName, "r");
    if (!dataFile)
    {
        perror("Error! Could not locate specified file!");
        exit(EXIT_FAILURE);
    }


    while ((result = fscanf(dataFile, "%s", buffer)) != EOF)
    {
        /*Parse buffer into integer.*/
        value = (int)strtol(buffer, &endptr, 10);

        /*Exits when conversion to integer of non-integer input fails.*/
        if (*endptr != '\0')
        {
            printf("Error! Non-integer value '%s' found in '%s'.\n", buffer, fileName);
            fclose(dataFile);
            exit(EXIT_FAILURE);
        }
        
        /*Exits when array exceeds array limit*/
        if (n >= MAXSIZE)
        {
            printf("Error: Array size exceeds limit of %d\n", MAXSIZE);
            fclose(dataFile);
            exit(EXIT_FAILURE);
        }

        /*Stores valid integers*/
        A[n++] = value;
    }

    fclose(dataFile);

    /*Exits when the data file is empty.*/
    if (n== 0)
    {
        printf("Error! Input file '%s' is empty or does not contain any valid integers.\n", fileName);
        exit(EXIT_FAILURE);
    }
}