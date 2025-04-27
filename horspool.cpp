// Copyright 2025 Luke Jannazzo

// Implementation of Horspool's string matching algorithm

#include <string>
using std::string;

//DEBUG
#include <iostream>
using std::cout;
using std::endl;


const int ALPHABET_SIZE = 27;  // english alphabet and space

// We need to map the characters to indices 0-25 for a-z and 26 for space
int MapCharToIndex(char c) {
  if ( c == ' ' ) return 26; // space
  if ( c >= 'a' && c <= 'z' ) return c - 'a';
  if ( c >= 'A' && c <= 'Z' ) return c - 'A';
  return -1; // invalid character, this should never run because we assume the input is valid
}

void GenerateShiftTable(string pattern,  int shiftTable[ALPHABET_SIZE]) {
  int m = pattern.length();
  for ( int i = 0; i < ALPHABET_SIZE; ++i ) {
    shiftTable[i] = m;  // default shift is the length of the pattern
  }
  for ( int j = 0; j < m - 1; ++j ) { // from j to m-2
    shiftTable[MapCharToIndex(pattern[j])] = m - 1 - j;
  }
  // ShiftTable is now completed
}


int HorspoolMatch(string pattern, string text) {
  int n = text.length();
  int m = pattern.length();
  int shiftTable[ALPHABET_SIZE];
  GenerateShiftTable(pattern, shiftTable);

  cout << "text: " << text << endl;
  cout << "pattern: " << pattern << endl;

  int i = m - 1;
  while ( i <= n - 1 ) {
    int k = 0;
    while ( k <= m-1 && pattern[m - 1 - k] == text[i - k] ) {
      ++k;
    }
    if ( k == m ) {
      cout << "Pattern found at index: " << i - m + 1 << endl;
      return i - m + 1;
    } else {
      i = i + shiftTable[MapCharToIndex(text[i])];
    }
  }
  cout << "Pattern not found." << endl;
  return -1; // failed search
}