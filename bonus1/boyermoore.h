// Copyright 2025 Luke Jannazzo

// Header for horspool function
// Question 4

#include <string>
using std::string;

#ifndef HORSPOOL_H_
#define HORSPOOL_H_

const int ALPHABET_SIZE = 27;  // english alphabet and space

void GenerateGoodShiftTable(string pattern,  int shiftTable[ALPHABET_SIZE]);
void GenerateBadShiftTable(string pattern,  int shiftTable[ALPHABET_SIZE]);
int BoyerMooreMatch(string pattern, string text);

#endif