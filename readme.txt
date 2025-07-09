=========================
Simple Sorting Simulation
         (SSS)
=========================

Author  : Gerard Vincent Aum Cabriles
Date    : 05/05/2025

-----------------------------------------
1. Description
-----------------------------------------
This program uses multithreading to simulate sorting of an algorithm. Two thread are used (T1 and T2) for the sorting algorithm.
An array of unsorted integers is read by the program, where two threads (T1 and T2) will then be used to sort the array in ascending order.

The array of integers is read by the program by providing a text file.

------------------------
2. Platform Information
------------------------
Tested and compiled on:
- Operating System  : Linus (Ubuntu 24.04.2)
- Compiler          : GCC version 13.3.0

-------------------
3. Files Included
-------------------

- main.c
- readFile.c
- sorter.c 
- readFile.h
- sorter.h
- input.txt 
- char.txt 
- empty.txt 
- max.txt 
- readme.txt (this file)
- MakeFile

---------------------------
4. How to Run and Compile
---------------------------
To compile the program, enter the following into the command line:

    make -f MakeFile 

Once compilation is complete, the program can be run by the following:

    ./sss (file).txt

Where '(file).txt' is a text file containing a list maximum of 200 integers.

Example:

    ./sss input.txt

------------------
5. Example Output
------------------
Initial Array: 5, 3, 11, 2, 1, 4, 5, 1, 10, 11, 21, 17, 25, 16, 6, 
Thread T2 (ID: 139768676320960), Total number of swaps = 13
Thread T1 (ID: 139768684713664), Total number of swaps = 16
Sorted array: 1, 1, 2, 3, 4, 5, 5, 6, 10, 11, 11, 16, 17, 21, 25, 
Total number of swaps to sort array A = 29