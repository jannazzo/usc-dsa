// Copyright 2025 Luke Jannazzo

// tests for the functions in this repo
// take input from driver

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <vector>
using std::vector;

#include "sort.h"
#include "heap.h"

void SortTest(string type) {
  // opens the file, parses the input, calls merge/quicksort, writes to the output file
  ifstream inputFile("input.txt");
  if ( !inputFile.is_open() ) {
    cout << "Could not open input.txt. Exiting." << endl;
    return;  // couldn't open file, exit the function 
  }
    
  
  vector<float> vectorData;
  float currentNum;

  cout << "Reading data from input.txt..." << endl;

  while (inputFile >> currentNum) {
    vectorData.push_back(currentNum);
  }
  inputFile.close();

  if ( vectorData.empty() ) {
    cout << "Could not read any data. Exiting." << endl;
    return;
  }

  cout << "Data read successfully." << endl;
  cout << "Sorting data..." << endl;
  
  // convert from vector to standard array
  const int size = vectorData.size();
  float arrayData[size];
  for ( int i = 0; i < size; ++i )
    arrayData[i] = vectorData[i];

  // pick which sort to use
  if ( type == "merge" )
    Mergesort(arrayData, size);
  else if ( type == "quick" )
    Quicksort(arrayData, 0, size - 1);
  else {
    cout << "Invalid sort type. Exiting." << endl;
    return;
  }
   
  ofstream outputFile("output.txt");
  if ( !outputFile.is_open() ) {
    cout << "Could not open output.txt. Exiting." << endl;
    return;  // didn't work
  }

  for ( int j = 0; j < size; ++j ) {
    outputFile << arrayData[j];
    if ( j < size - 1 )  // we don't want the space after the last element
      outputFile << " ";
  }
  outputFile.close();

}

void HeapTest(string type) {
  return;  // placeholder
}