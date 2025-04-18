// Copyright 2025 Luke Jannazzo
//
// Driver file for algorithm implementations

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "sort.h"

int main() {
  cout << "Starting Tests" << endl;

  // testing mergesort
  int array[8] = {8, 3, 2, 9, 7, 1, 5, 4};

  for ( int i = 0; i < 8; ++i ) {
    cout << array[i] << " ";
  }
  cout << endl;

  Quicksort(array, 0, 7);

  for ( int i = 0; i < 8; ++i ) {
    cout << array[i] << " ";
  }
  cout << endl;
}
