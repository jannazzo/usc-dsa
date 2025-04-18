// Copyright 2025 Luke Jannazzo

#include <cmath>

// Question 2
// implement mergesort and quicksort

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

// reused code to swap two indicies in an array
void swap(int array[], int i, int j) {
  int tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

int HoarePartition(int array[], int l, int r) {
  int p = array[l];  // set pivot as the first element
  int i = l;
  int j = r+1;
  do {  // repeat until i >= j
    do {
      i += 1;
      if ( i >= r ) break;
    } while ( array[i] < p );
    do {
      j -= 1;
      if ( j <= l ) break;
    } while ( array[j] > p );
    // swap items at i & j
    swap(array, i, j);
  } while ( i < j );
  swap(array, i, j);
  swap(array, l, j);  // swap with the pivot
  return j;
}

void Quicksort(int array[], int l, int r) {
  if ( l < r ) {
    int s = HoarePartition(array, l, r);
    Quicksort(array, l, s-1);
    Quicksort(array, s+1, r);
  }
}