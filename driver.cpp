// Copyright 2025 Luke Jannazzo
//
// Driver file for algorithm implementations

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <algorithm>
using std::copy;

#include "sort.h"

int main() {
  cout << "Starting Tests" << endl;

  float array1[8] = {8.1, 3.4, 2.0, 9.4, 7.1, 1.9, 5.3, 4.9};

  cout << "Mergesort Test" << endl;
  
  for ( int i = 0; i < 8; ++i ) {
    cout << array1[i] << " ";
  }
  cout << endl;

  Mergesort(array1, 8);

  for ( int i = 0; i < 8; ++i ) {
    cout << array1[i] << " ";
  }
  cout << endl;

  cout << "Quicksort Test" << endl;

  float array2[8] = {8.1, 3.4, 2.0, 9.4, 7.1, 1.9, 5.3, 4.9};

  for ( int i = 0; i < 8; ++i ) {
    cout << array2[i] << " ";
  }
  cout << endl;

  Quicksort(array2, 0, 7);

  for ( int i = 0; i < 8; ++i ) {
    cout << array2[i] << " ";
  }
  cout << endl;
}
