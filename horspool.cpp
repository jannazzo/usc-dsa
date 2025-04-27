// Copyright 2025 Luke Jannazzo

// Implementation of Horspool's string matching algorithm

#include <string>
using std::string;

const int ALPHABET_SIZE = 27;  // english alphabet and space

void GenerateShiftTable(string pattern,  int shiftTable[ALPHABET_SIZE]) {
  int m = pattern.length();
  for ( int i = 0; i < ALPHABET_SIZE; ++i ) {
    shiftTable[i] = m;  // default shift is the length of the pattern
  }
  for ( int j = 0; j < m - 1; ++j ) { // from j to m-2
    shiftTable[pattern[j]] = m - 1 - j;
  }
  // ShiftTable is now completed
}


int HorspoolMatch(string pattern, string text) {
  int n = text.length();
  int m = pattern.length();
  int shiftTable[ALPHABET_SIZE];
  GenerateShiftTable(pattern, shiftTable);

  int i = m - 1;
  while ( i <= n - 1 ) {
    int k = 0;
    while ( k < m-1 && pattern[m - 1 - k] == text[i - k] ) {
      ++k;
    }
    if ( k == m ) {
      i = i + shiftTable[text[i]];
    } else {
      return i - m - 1;
    }
  }

  return -1; // failed search
}