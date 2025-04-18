// Copyright 2025 Luke Jannazzo

// Question 2

#ifndef SORT_HH_
#define SORT_HH_

void Mergesort(float array[], int size);

void Merge(float sub1[], float sub2[], float merged[]);

int Quicksort(float array[], int l, int r);

int HoarePartition(float array[]);

#endif