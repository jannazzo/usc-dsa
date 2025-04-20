// Copyright 2025 Luke Jannazzo
//
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
  cout << "Enter 1 for the Mergesort test." << endl;
  cout << "Enter 2 for the Quicksort test." << endl;

  int selection = 0;
  cin >> selection;
  if ( selection == 0 ) {
    cout << "No selection made. Exiting." << endl;
    return 0;
  } else if ( selection == 1 ) {
    cout << "Running the Mergesort test." << endl;
    SortTest("merge");
  } else if ( selection == 2 ) {
    cout << "Running the Quicksort test." << endl;
    SortTest("quick");
  }

}
