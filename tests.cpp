// Copyright 2025 Luke Jannazzo

// tests for the functions in this repo
// take input from driver

#include <string>
using std::string;
#include <fstream>
using std::ifstream;
using std::ofstream;

#include "sort.h"
#include "heap.h"

void SortTest(string type) {
  // opens the file, parses the input, calls merge/quicksort, writes to the output file
  ifstream inputFileforCount("input.txt");
  if ( !inputFileforCount.is_open() )
    return;  // couldn't open file, exit the function 
  
  // count the numbers in the array
  int size;
  float tmp;
  while ( inputFileforCount >> tmp )  // will be false when the file is empty
    ++size;
  inputFileforCount.close();  // close the file

  if ( size > 0 ) {  // only works if we found the array has a nonzero size
    ifstream inputFile("input.txt");  // open the file again, but now we know the size.
    float array[size];
    for ( int i = 0; (i < size) && (inputFile >> array[i]); ++i );  // reads in the data
    inputFile.close();
    // pick which sort to use
    if ( type == "merge" )
      Mergesort(array, size);
    else if ( type == "quick" )
      Quicksort(array, 0, size - 1);
    else
      return;
    
    ofstream outputFile("output.txt");
    if ( !outputFile.is_open() )
      return;  // didn't work

    for ( int j = 0; j < size; ++j ) {
      outputFile << array[j];
      if ( j < size - 1 )  // we don't want the space after the last element
        outputFile << " ";
    }
    outputFile.close();

  } else return;
}

void HeapTest(string type) {
  return;  // placeholder
}