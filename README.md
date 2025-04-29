# USC Data Structures & Algorithms
Final programming assignment for the Data Structures &amp; Algorithms course at the University of South Carolina.

This repository contains the solutions to Questions 1-5 and the second bonus question.

## Compile Instructions

Tested on Ubuntu 22.04.5 LTS on an x86-64 architecture. Compiler used is g++ 11.4.0.

Compiler commands are included in the makefile. The compiler is using C++17 standard.

## Makefile Commands

Each folder has a makefile in it equipped with the following two commands.

`make driver`: Builds a driver file that handles the I/O and runs the algorithm.

`make clean`: Deletes all object code, executables, and input/output text files from the working directory. Be sure to run this before committing changes to git.

## Input & Output Formatting

The programs assume that there exists a file called `input.txt` that is located in the same folder as the code and driver file. The program will create an `output.txt` file and place the specified output into it. NOTE: If a file called `output.txt` already exists, it will overwrite it.

For each algorithm, the format of the `input.txt` file and output is defined as follows. NOTE: The program does not perform input validation. It assumes that each input file will be formatted exactly as described here.

**Network Classification Algorithm:**
- Input is an n x n adjacency matrix with columns delimited by spaces and rows delimited by newlines.
- All values are 0 or 1, and only 0's on the diagonal.
- Output is a line of text that contains the name of the network topology identified.

**Sorting Algorithms:**
- Input is a n length array of floating-point numbers, delimited by spaces.
- Output is the sorted array, formatted the same way.

**Heap Algorithm:**
- Input is:
    - On the first line, an integer containing the size n of the array representing the heap.
    - On the second line, an n length array of integers, delimited by spaces.
- Output is a single line containing the heap in array form, formatted the same way.

**Horspool's String Matching Algorithm:**
- Input is two strings:
    - On the first line, a string that is the pattern being searched for.
    - On the second line, a string that is the text being searched in.
- Output will just contain an integer that is the index of the left end of the located string or -1 if not found.

**Floyd's Algorithm:**
- Input is an n x n distance matrix with nonnegative float numbers.
    - Rows are delimited by newlines, columns delimited by spaces
    - If a distance is infinity (no edge exists), the matrix will contain the string "inf" instead of a float number.
    - Diagonal entries are all 0.
- Output will be a distance matrix formatted the same way, representing the shortest path among all pairs.

## Credits

Algorithm definitons are referenced from the course textbook, Introduction to the Design and Analysis of Algorithms, 3rd Edition by Anany Levitin. When "the pseudocode" is referenced in code comments, it refers to the algorithm definition in this textbook.