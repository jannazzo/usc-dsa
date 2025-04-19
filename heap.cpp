// Copyright 2025 Luke Jannazzo

// Implementation of HeapBottomUp for min and max heap

#include <cmath>

void MaxHeapBottomUp(int size, int array[]) {
  for ( int i = size / 2; i > 1; --i ) {
    int k = i;
    int v = array[k];
    bool heap = false;
    while ( !heap && (2*k) < size ) {
      int j = 2*k;
      if ( j < size ) {
        if (array[j] < array[j+1]) {
          j = j+1;
        }
      }
      if ( v >= array[j] ) {
        heap = true;
      } else {
        array[k] = array[j];
        k = j;
      }
    array[k] = v;
    }
  }
}

void MinHeapBottomUp(int size, int array[]) {
  for ( int i = size / 2; i > 1; --i ) {
    int k = i;
    int v = array[k];
    bool heap = false;
    while ( !heap && (2*k) < size ) {
      int j = 2*k;
      if ( j < size ) {  // there exist 2 children
        if (array[j] > array[j+1]) {
          j = j+1;
        }
      }
      if ( v >= array[j] ) {
        heap = true;
      } else {
        array[k] = array[j];
        k = j;
      }
    array[k] = v;
    }
  }
}

