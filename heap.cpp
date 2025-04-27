// Copyright 2025 Luke Jannazzo

// Implementation of HeapBottomUp for min and max heap

#include "heap.h"

void MaxHeapBottomUp(int size, int array[]) {
  if ( size <= 1 ) {
    return;  // no heap to build
  }
  // adjust indices iterated so that it's 0-based
  for ( int i = (size / 2) - 1; i >= 0; --i ) {
    int k = i;
    int v = array[k];

    bool heap = false;

    while ( !heap && (2*k + 1) < size ) {
      int j = 2*k + 1;  // left child
      if ( j + 1 < size ) {
        if (array[j] < array[j+1]) {
          j++;
        }
      }

      if ( v >= array[j] ) {
        heap = true;
      } else {
        array[k] = array[j];
        k = j;
      }
    }
    array[k] = v;
  }
}

void MinHeapBottomUp(int size, int array[]) {
  if ( size <= 1 ) {
    return;  // no heap to build
  }
  // adjust indices iterated so that it's 0-based
  for ( int i = (size / 2) - 1; i >= 0; --i ) {
    int k = i;
    int v = array[k];

    bool heap = false;

    while ( !heap && (2*k + 1) < size ) {
      int j = 2*k + 1;  // left child
      if ( j + 1 < size ) {
        if (array[j] > array[j+1]) {
          j++;
        }
      }

      if ( v <= array[j] ) {
        heap = true;
      } else {
        array[k] = array[j];
        k = j;
      }
    }
    array[k] = v;
  }
}

