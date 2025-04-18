// Copyright 2025 Luke Jannazzo

// Question 2

#ifndef SORT_HH_
#define SORT_HH_

void Mergesort(int array[], int size);

void Merge(int sub1[], int sub2[], int merged[]);

int Quicksort(int array[], int l, int r);

int HoarePartition(int array[]); 

#endif