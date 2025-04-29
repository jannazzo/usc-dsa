// Copyright 2025 Luke Jannazzo

// Implementation of HeapBottomUp for maxheap (same as question 3)
// and Heapsort

#include <vector>
using std::vector;

// DEBUG
#include <iostream>
using std::cout;
using std::endl;

#include "heapsort.h"

void MaxHeapBottomUp(int size, vector<int>& array) {
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
          ++j;
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

// removes the root and returns it
void DeleteRoot(int currentSize, vector<int>& heap) {
  // swap root with last element
  int root = heap[0];
  heap[0] = heap[currentSize - 1];
  heap[currentSize - 1] = root;
  // remove the last element from the heap (was the previous root)
  heap.pop_back();
  // heapify again
  MaxHeapBottomUp(currentSize - 1, heap);
}

void Heapsort(int size, vector<int>& heap) {
  // heapify at the start
  MaxHeapBottomUp(size, heap);

  // perform key deletion size-1 times and form a new array
  for ( int i = size; i > 0; --i ) {
    DeleteRoot(i, heap);
  }
}