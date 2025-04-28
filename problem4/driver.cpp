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

#include "horspool.h"

int main() {
  cout << "Starting Horspool algorithm test." << endl;
  
  // test the horspool function
  ifstream inputFile("input.txt");
  if ( !inputFile.is_open() ) {
    cout << "Could not open input.txt. Exiting." << endl;
    return 0;  // couldn't open file, exit the function 
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
    return 0;
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
    return 0;  // didn't work
  }
  
  outputFile << result;
  outputFile.close();

  cout << "Finished searching." << endl;
  cout << "Found index written to output.txt" << endl;

  return 0;
}
