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
#include <limits>

#include "floyd.h"

int main() {

  cout << "Starting Floyd's algorithm test." << endl;

  ifstream inputFile("input.txt");
  if ( !inputFile.is_open() ) {
    cout << "Could not open input. Error." << endl;  // couldn't open file, exit the function
    return 1;
  }

  const float INF = std::numeric_limits<float>::infinity();

  //TODO handle when weight is infinity
  vector<vector<float>> vectorData;
  int lineNum = 0;
  string currentLine;
  cout << "Reading data from input.txt..." << endl;
  while (getline(inputFile, currentLine)) {
    ++lineNum;
    vector<float> currentRow;
    stringstream ss(currentLine);
    string currentItem;
    while (ss >> currentItem) {
      // if it is the string "i", set to infinity
      // if it is anything else, assume it is a float
      // again this assumes valid input
      if ( currentItem == "i" ) {
        currentRow.push_back(INF);
      } else {
        float currentFloat = stof(currentItem);
        currentRow.push_back(currentFloat);
      }
    }
    if ( !currentRow.empty() ) {
      vectorData.push_back(currentRow);
    }
  }
  inputFile.close();
  // after this, the vectorData should be a 2D vector of floats

  if ( vectorData.empty() ) {
    cout << "Error. Could not read any data." << endl;
    return 1;
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
    return 1;  // didn't work
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
  outputFile.close();

  cout << "Output written to output.txt." << endl;

  return 0;
}
