// Copyright 2025 Luke Jannazzo

// Driver file for network classification

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <sstream>
using std::stringstream;
#include <vector>
using std::vector;

#include "classify.h"

int main() {

  cout << "Starting Network Classification Test" << endl;

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
  cout << "Time taken: " << endTime - startTime << " ms" << endl;

  ofstream outputFile("output.txt");
  if ( !outputFile.is_open() ) {
    cout << "Could not open output.txt. Exiting." << endl;
    return;  // didn't work
  }
  outputFile << result;
  outputFile.close();
  cout << "Network classified successfully." << endl;

  return 0;
}
