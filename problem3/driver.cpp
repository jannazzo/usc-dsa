// Copyright 2025 Luke Jannazzo

// tests for the functions in this repo
// take input from driver

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
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

#include "heap.h"

int main() {

  cout << "Starting Heap Test" << endl;
  string type;
  int typeSelection;

  cout << "Please select a heap type." << endl;
  cout << "Enter 1 for Max Heap." << endl;
  cout << "Enter 2 for Min Heap." << endl;
  cin >> typeSelection;
  if ( typeSelection == 1 ) {
    type = "max";
  } else if ( typeSelection == 2 ) {
    type = "min";
  } else {
    cout << "Invalid selection. Exiting." << endl;
    return 0;
  }

  ifstream inputFile("input.txt");
  if ( !inputFile.is_open() ) {
    cout << "Could not open input.txt. Exiting." << endl;
    return;  // couldn't open file, exit the function 
  }

  // initialize variables that will store data
  int size;
  vector<int> vectorData;

  cout << "Reading data from input.txt..." << endl;
  // all of this reading assumes the file is formatted correctly
  // as specified in the README

  // read the first line of the file to get the size
  string line1;
  getline(inputFile, line1);
  size = std::stoi(line1);

  // read the second line of the file to get the data
  int currentNum;
  while (inputFile >> currentNum) {
    vectorData.push_back(currentNum);
  }
  inputFile.close();

  if ( vectorData.empty() ) {
    cout << "Could not read any data. Exiting." << endl;
    return;
  }

  // covert vector to standard array to be used in the heap functions
  int arrayData[size];
  for ( int i = 0; i < size; ++i )
    arrayData[i] = vectorData[i];
  cout << "Data read successfully." << endl;

  // call the appropriate heap function
  if ( type == "max" ) {
    cout << "Building a max heap..." << endl;

    int startTime = clock();
    MaxHeapBottomUp(size, arrayData);
    int endTime = clock();
    cout << "Time taken: " << endTime - startTime << " ms" << endl;

  } else if ( type == "min" ) {
    cout << "Building a min heap..." << endl;

    int startTime = clock();
    MinHeapBottomUp(size, arrayData);
    int endTime = clock();
    cout << "Time taken: " << endTime - startTime << " ms" << endl;

  } else {
    cout << "Invalid heap type. Exiting." << endl;
    // should never run
    return;
  }

  ofstream outputFile("output.txt");
  if ( !outputFile.is_open() ) {
    cout << "Could not open output.txt. Exiting" << endl;
    return;  // didn't work
  }
  for ( int j = 0; j < size; ++j ) {
    outputFile << arrayData[j];
    if ( j < size - 1 )  // we don't want the space after the last element
      outputFile << " ";
  }
  outputFile.close();

  cout << "Heap built successfully." << endl;
  cout << "Output written to output.txt." << endl;

  return 0;
}
