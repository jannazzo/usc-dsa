// Copyright 2025 Luke Jannazzo

// tests for the functions in this repo
// take input from driver

#include <iostream>
using std::cout;
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

#include "classify.h"
#include "sort.h"
#include "heap.h"
#include "horspool.h"

void ClassifyTest() {
  ifstream inputFile("input.txt");
  if ( !inputFile.is_open() ) {
    cout << "Could not open input. Error." << endl;  // couldn't open file, exit the function
    return;
  }
  vector<vector<int>> vectorData;
  int lineNum = 0;
  string currentLine;
  cout << "Reading data from input.txt..." << endl;
  while (getline(inputFile, currentLine)) {
    ++lineNum;
    vector<int> currentRow;
    stringstream ss(currentLine);
    int currentNum;
    while (ss >> currentNum) {
      currentRow.push_back(currentNum);
    }
    if ( !currentRow.empty() ) {
      vectorData.push_back(currentRow);
    }
  }
  inputFile.close();
  // after this, the vectorData should be a 2D vector of ints
  // assumes columns are the same size as rows

  if ( vectorData.empty() ) {
    cout << "Error. Could not read any data." << endl;
    return;
  }
  cout << "Data read successfully." << endl;

  cout << "Classifying network..." << endl;
  string result = BruteForceClassifyNetwork(vectorData, lineNum);

  ofstream outputFile("output.txt");
  if ( !outputFile.is_open() ) {
    cout << "Could not open output.txt. Exiting." << endl;
    return;  // didn't work
  }
  outputFile << result;
  outputFile.close();
  cout << "Network classified successfully." << endl;

}

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
    // should never run
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
    MaxHeapBottomUp(size, arrayData);
  } else if ( type == "min" ) {
    cout << "Building a min heap..." << endl;
    MinHeapBottomUp(size, arrayData);
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

}

void HorspoolTest() {
  // test the horspool function
  ifstream inputFile("input.txt");
  if ( !inputFile.is_open() ) {
    cout << "Could not open input.txt. Exiting." << endl;
    return;  // couldn't open file, exit the function 
  }

  string pattern;
  string text;

  cout << "Reading data from input.txt..." << endl;

  // read the first line of the file to get the pattern
  getline(inputFile, pattern);
  // read the second line of the file to get the text
  getline(inputFile, text);
  inputFile.close();

  if ( pattern.empty() || text.empty() ) {
    cout << "Could not read any data. Exiting." << endl;
    return;
  }

  cout << "Data read successfully." << endl;
  cout << "Searching for pattern..." << endl;

  int result = HorspoolMatch(pattern, text);

  ofstream outputFile("output.txt");
  if ( !outputFile.is_open() ) {
    cout << "Could not open output.txt. Exiting." << endl;
    return;  // didn't work
  }
  
  outputFile << result;
  outputFile.close();
}