# USC Data Structures & Algorithms
Final programming assignment for the Data Structures &amp; Algorithms course at the University of South Carolina

## Compile Instructions

Tested on Ubuntu 22.04.5 LTS on an x86-64 architecture. Compiler used is g++ 11.4.0.

Compiler commands are included in the makefile. The compiler is using C++17 standard.

## Makefile Commands

`make driver`: Builds a driver file that contains tests for all of the functions.

`make clean`: Deletes all object code and executables from the working directory. Be sure to run this before committing changes to git.

## Input Formatting

For each algorithm, the format of the `input.txt` file is defined as follows. NOTE: The program does not perform input validation. It assumes that each input file will be formatted exactly as described here.

Network Classification Algorithm:
- Input is an n x n adjacency matrix with columns delimited by spaces and rows delimited by newlines.

Sorting Algorithms:
- Input is a n length array of floating-point numbers, delimited by spaces.

Heap Algorithm:
- Input is an n length array of integers, delimited by spaces.
