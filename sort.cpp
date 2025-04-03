// Copyright 2025 Luke Jannazzo

#include <cmath>

// Question 2

void Mergesort(int array[], int size) {
  if ( size > 1 ) {
    // define subarrays
    int B[size];
    int C[size];
    
    // fill subarrays
    int floorhalf = floor(size / 2);
    //int ceilhalf = ceil(size / 2);
    for ( int i = 0; i < size; ++i ) {
      if ( i < floorhalf )
        B[i] = array[i];
      else
        C[i] = array[i + floorhalf];
    }
    Mergesort(B, floorhalf);
    Mergesort(C, floorhalf);
  }
}

void Merge(int B[], int p, int C[], int q, int merged[]) {
  int i = 0; 
  int j = 0;
  int k = 0;
  while ( i < p && j < q) {
    if ( B[i] <= C[j] ) {
        merged[k] = B[i];
        ++i;
    } else {
        merged[k] = C[j];
        ++j;
    }
    ++k;
  }
  if ( i == p ) {
    while ( j < q ) {
      merged[k] = C[j];
      ++j;
      ++k;
    }
  } else {
    while ( i < q ) {
        merged[k] = B[i];
        ++i;
        ++k;
      }
  }
}


void Quicksort(int array[], int size) {
  return;  // placeholder
}

int HoarePartition(int array[]) {
  return 0;  // placeholder
}
