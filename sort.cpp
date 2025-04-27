// Copyright 2025 Luke Jannazzo

// implement mergesort and quicksort

// these fuctions are written using stadnard arrays for algorithmic simplicity
// this is done to allow for consistency with pseudocode implementations elsewhere in the course

void Merge(float B[], int p, float C[], int q, float A[]) {
  int i = 0; 
  int j = 0;
  int k = 0;
  while ( i < p && j < q ) {
    if ( B[i] <= C[j] ) {
        A[k] = B[i];
        ++i;
    } else {
        A[k] = C[j];
        ++j;
    }
    ++k;
  }

  if ( i == p ) {
    while ( j < q ) {
      A[k] = C[j];
      ++j;
      ++k;
    }
  } else {
    while ( i < p ) {
        A[k] = B[i];
        ++i;
        ++k;
      }
  }
}

void Mergesort(float array[], int size) {
  if ( size > 1 ) {
    // define shorthand terms
    int floorhalf = size / 2;  // integer division means this is floor
    int ceilhalf = size - floorhalf;

    // define subarrays
    float B[floorhalf];
    float C[ceilhalf];

    // fill subarrays 
    for ( int i = 0; i < size; ++i ) {
      if ( i < floorhalf )
        B[i] = array[i];
      else
        C[i] = array[floorhalf + i];
    }
    Mergesort(B, floorhalf);
    Mergesort(C, ceilhalf);
    Merge(B, floorhalf, C, ceilhalf, array);
  }
}

// reused code to swap two indicies in an array
void swap(float array[], int i, int j) {
  float tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

int HoarePartition(float array[], int l, int r) {
  float p = array[l];  // set pivot as the first element
  int i = l;
  int j = r+1;
  do {  // repeat until i >= j
    do {
      i += 1;
      if ( i >= r ) break;
    } while ( array[i] < p );
    do {
      j -= 1;
      if ( j <= l ) break;
    } while ( array[j] > p );
    // swap items at i & j
    swap(array, i, j);
  } while ( i < j );
  swap(array, i, j);
  swap(array, l, j);  // swap with the pivot
  return j;
}

void Quicksort(float array[], int l, int r) {
  if ( l < r ) {
    int s = HoarePartition(array, l, r);
    Quicksort(array, l, s-1);
    Quicksort(array, s+1, r);
  }
}