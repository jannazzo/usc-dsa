// Copyright 2025 Luke Jannazzo

// tests for the functions in this repo
// take input from driver

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <vector>
using std::vector;

#include "heapsort.h"

int main() {

  cout << "Starting Heapsort Test" << endl;

  ifstream inputFile("input.txt");
  if ( !inputFile.is_open() ) {
    cout << "Could not open input.txt. Exiting." << endl;
    return 0;  // couldn't open file, exit the function 
  }

  // initialize variables that will store data
  int size;
  vector<int> vectorData;

  cout << "Reading data from input.txt..." << endl;
  // all of this reading assumes the file is formatted correctly
  // as specified in the README

  // read the first line of the file to get the size
  string line1;
  std::getline(inputFile, line1);
  size = std::stoi(line1);

  // read the second line of the file to get the data
  int currentNum;
  while (inputFile >> currentNum) {
    vectorData.push_back(currentNum);
  }
  inputFile.close();

  if ( vectorData.empty() ) {
    cout << "Could not read any data. Exiting." << endl;
    return 0;
  }

  cout << "Building a heap..." << endl;

  // make a copy so we can output the heap by itself
  vector<int> heapData = vectorData;
  // Build the initial heap
  int startTime = clock();
  MaxHeapBottomUp(size, heapData);
  int endTime = clock();
  cout << "Time taken: " << endTime - startTime << " ms" << endl;

  cout << "Running Heapsort..." << endl;
  // call heapsort
  startTime = clock();
  Heapsort(size, vectorData);
  endTime = clock();
  cout << "Time taken: " << endTime - startTime << " ms" << endl;

  ofstream outputFile("output.txt");
  if ( !outputFile.is_open() ) {
    cout << "Could not open output.txt. Exiting" << endl;
    return 0;  // didn't work
  }
  // output the heap
  for ( int i = 0; i < size; ++i ) {
    outputFile << heapData[i];
    if ( i < size - 1 )  // we don't want the space after the last element
      outputFile << " ";
  }
  outputFile << endl;

  // output the vectorData which has been sorted with heapsort
  for ( int j = 0; j < size; ++j ) {
    outputFile << vectorData[j];
    if ( j < size - 1 )  // we don't want the space after the last element
      outputFile << " ";
  }
  outputFile.close();

  cout << "Sorted successfully." << endl;
  cout << "Output written to output.txt." << endl;

  return 0;
}
