// Copyright 2025 Luke Jannazzo

// Driver file for algorithm implementations

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
using std::ofstream;

#include "tests.h"

int main() {

  cout << "Starting Tests" << endl;

  cout << "Please select a test." << endl;
  cout << "These tests assume the desired input file named 'input.txt' is already located in the same directory as this program." << endl;
  cout << "Enter 1 for the Network Classification test." << endl;
  cout << "Enter 2 for the Mergesort test." << endl;
  cout << "Enter 3 for the Quicksort test." << endl;
  cout << "Enter 4 for the Max HeapBottomUp test." << endl;
  cout << "Enter 5 for the Min HeapBottomUp test." << endl;

  int selection = 0;
  cin >> selection;
  if ( selection == 1 ) {
    cout << "Running the Network Classification Test" << endl;
    cout << ClassifyTest() << endl;
  } else if ( selection == 2 ) {
    cout << "Running the Mergesort test." << endl;
    SortTest("merge");
  } else if ( selection == 3 ) {
    cout << "Running the Quicksort test." << endl;
    SortTest("quick");
  } else if ( selection == 4 ) {
    cout << "Running the Max HeapBottomUp test." << endl;
    HeapTest("max");
  } else if ( selection == 5 ) {
    cout << "Running the Min HeapBottomUp test." << endl;
    HeapTest("min");
  } else {
    cout << "Invalid selection. Exiting." << endl;
    return 0;
  }

  cout << "Tests completed successfully" << endl;
  return 0;
}
