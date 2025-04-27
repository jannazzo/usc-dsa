// Copyright 2025 Luke Jannazzo

// Header for horspool function
// Question 4

#include <string>
using std::string;

#ifndef HORSPOOL_H_
#define HORSPOOL_H_

const int ALPHABET_SIZE = 27;  // english alphabet and space

void GenerateShiftTable(string pattern,  int shiftTable[ALPHABET_SIZE]);
int Horspool(string pattern, string text);

#endif