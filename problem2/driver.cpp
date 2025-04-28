// Copyright 2025 Luke Jannazzo

// driver for the sorting algorithms

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::stringstream;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <vector>
using std::vector;

#include "sort.h"

int main() {

  cout << "Starting Sort Test" << endl;

  string type;
  int typeSelection;
  cout << "Please select a sort type." << endl;
  cout << "Enter 1 for Mergesort." << endl;
  cout << "Enter 2 for Quicksort." << endl;
  cin >> typeSelection;
  if ( typeSelection == 1 ) {
    type = "merge";
  } else if ( typeSelection == 2 ) {
    type = "quick";
  } else {
    cout << "Invalid selection. Exiting." << endl;
    return 0;
  }

  // opens the file, parses the input, calls merge/quicksort, writes to the output file
  ifstream inputFile("input.txt");
  if ( !inputFile.is_open() ) {
    cout << "Could not open input.txt. Exiting." << endl;
    return 0;  // couldn't open file, exit the function 
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
    return 0;
  }

  cout << "Data read successfully." << endl;
  cout << "Sorting data..." << endl;

  // convert from vector to standard array
  const int size = vectorData.size();
  float arrayData[size];
  for ( int i = 0; i < size; ++i )
    arrayData[i] = vectorData[i];

  // pick which sort to use
  if ( type == "merge" ) {
    cout << "Running Mergesort..." << endl;

    int startTime = clock();
    Mergesort(arrayData, size);
    int endTime = clock();
    cout << "Time taken: " << endTime - startTime << " ms" << endl;
  } else if ( type == "quick" ) {
    cout << "Running Quicksort..." << endl;

    int startTime = clock();
    Quicksort(arrayData, 0, size - 1);
    int endTime = clock();
    cout << "Time taken: " << endTime - startTime << " ms " << endl;
  } else {
    cout << "Invalid sort type. Exiting." << endl;
    // should never run
    return 0;
  }
   
  ofstream outputFile("output.txt");
  if ( !outputFile.is_open() ) {
    cout << "Could not open output.txt. Exiting." << endl;
    return 0;  // didn't work
  }

  for ( int j = 0; j < size; ++j ) {
    outputFile << arrayData[j];
    if ( j < size - 1 )  // we don't want the space after the last element
      outputFile << " ";
  }
  outputFile.close();

  cout << "Data sorted successfully and written to output.txt." << endl;

  return 0;
}

