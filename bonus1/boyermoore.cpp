// Copyright 2025 Luke Jannazzo

// Implementation of Horspool's string matching algorithm

#include <string>
using std::string;

const int ALPHABET_SIZE = 27;  // english alphabet and space

// We need to map the characters to indices 0-25 for a-z and 26 for space
int MapCharToIndex(char c) {
  if ( c == ' ' ) return 26; // space
  if ( c >= 'a' && c <= 'z' ) return c - 'a';
  if ( c >= 'A' && c <= 'Z' ) return c - 'A';
  return -1; // invalid character, this should never run because we assume the input is valid
}

void GenerateGoodShiftTable(string pattern,  int shiftTable[ALPHABET_SIZE]) {
  return; // TODO generate the good shift table
  // ShiftTable is now completed
}

void GenerateBadShiftTable(string pattern, int shiftTable[ALPHABET_SIZE]) {
  // this is the exact same implementation as GenerateShiftTable() from horspool.cpp
  int m = pattern.length();
  for ( int i = 0; i < ALPHABET_SIZE; ++i ) {
    shiftTable[i] = m;  // default shift is the length of the pattern
  }
  for ( int j = 0; j < m - 1; ++j ) { // from j to m-2
    shiftTable[MapCharToIndex(pattern[j])] = m - 1 - j;
  }
  // ShiftTable is now completed
}


int BoyerMooreMatch(string pattern, string text) {
  int n = text.length();
  int m = pattern.length();
  int goodShiftTable[ALPHABET_SIZE];
  int badShiftTable[ALPHABET_SIZE];
  GenerateGoodShiftTable(pattern, goodShiftTable);
  GenerateBadShiftTable(pattern, badShiftTable);

  //TODO implement the Boyer-Moore algorithm

  return -1; // failed search
}