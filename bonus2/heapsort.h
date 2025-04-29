// Copyright 2025 Luke Jannazzo

// Header for heap functions
// Extends Question 3's solution to include Heapsort
// switches from arrays to vectors to allow for the resizing during heapsort

#ifndef HEAPSORT_H_
#define HEAPSORT_H_

// we use call by reference to edit the array as we work on it
// parameters for the size allow us to edit subsections of the array
// this keeps the algorithm in-place

// this is copied from problem 3 but switches to vector
void MaxHeapBottomUp(int size, vector<int>& array);

// necessary functions for heapsort
void DeleteRoot(int size, vector<int>& heap);
// this heapsort takes an array already heapified
void Heapsort(int size, vector<int>& heap);

#endif
