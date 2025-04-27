// Copyright 2025 Luke Jannazzo

// tests for the functions in this repo
// the tests will open the input file, call the algorithm,
// and write the output to the output file
// the driver creates the UI to call the test funcitons

#include <string>
using std::string;
#include <fstream>

#include "sort.h"
#include "heap.h"

#ifndef TESTS_H_
#define TESTS_H_

void ClassifyTest();
void SortTest(string type);
void HeapTest(string type);
void HorspoolTest();
void FloydTest();

#endif
