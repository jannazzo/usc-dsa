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
#include "floyd.h"

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

  // collect time before running
  int startTime = clock();
  string result = BruteForceClassifyNetwork(vectorData, lineNum);
  int endTime = clock();
  int elapsedTime = endTime - startTime;
  cout << "Time taken: " << elapsedTime << " ms" << endl;

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

  int startTime = clock();
  int result = HorspoolMatch(pattern, text);
  int endTime = clock();
  cout << "Time taken: " << endTime - startTime << " ms" << endl;

  ofstream outputFile("output.txt");
  if ( !outputFile.is_open() ) {
    cout << "Could not open output.txt. Exiting." << endl;
    return;  // didn't work
  }
  
  outputFile << result;
  outputFile.close();
}

void FloydTest() {
  ifstream inputFile("input.txt");
  if ( !inputFile.is_open() ) {
    cout << "Could not open input. Error." << endl;  // couldn't open file, exit the function
    return;
  }
  //TODO handle when weight is infinity
  vector<vector<float>> vectorData;
  int lineNum = 0;
  string currentLine;
  cout << "Reading data from input.txt..." << endl;
  while (getline(inputFile, currentLine)) {
    ++lineNum;
    vector<float> currentRow;
    stringstream ss(currentLine);
    float currentNum;
    while (ss >> currentNum) {
      currentRow.push_back(currentNum);
    }
    if ( !currentRow.empty() ) {
      vectorData.push_back(currentRow);
    }
  }
  inputFile.close();
  // after this, the vectorData should be a 2D vector of floats

  if ( vectorData.empty() ) {
    cout << "Error. Could not read any data." << endl;
    return;
  }
  cout << "Data read successfully." << endl;

  cout << "Running Floyd's algorithm..." << endl;

  int startTime = clock();
  vector<vector<float>> result = Floyd(vectorData);
  int endTime = clock();
  cout << "Time taken: " << endTime - startTime << " ms" << endl;

  ofstream outputFile("output.txt");
  if ( !outputFile.is_open() ) {
    cout << "Could not open output.txt. Exiting." << endl;
    return;  // didn't work
  }

  // output the result to the output file
  for ( int i = 0; i < result.size(); ++i ) {
    for ( int j = 0; j < result[i].size(); ++j ) {
      outputFile << result[i][j];
      if ( j < result[i].size() - 1 )  // we don't want the space after the last element
        outputFile << " ";
    }
    outputFile << endl;
  }
}