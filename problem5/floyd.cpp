// Copyright 2025 Luke Jannazzo

#include <vector>
using std::vector;
#include <cmath>

vector<vector<float>> Floyd(vector<vector<float>> weightMatrix) {
  int n = weightMatrix.size();
  vector<vector<float>> distanceMatrix = weightMatrix;  // make a copy
  
  // this is 0-based while the pseudocode is 1-based
  for ( int k = 0; k < n; ++k ) {
    for ( int i = 0; i < n; ++i ) {
      for ( int j = 0; j < n; ++j ) {
        distanceMatrix[i][j] = std::min(distanceMatrix[i][j], distanceMatrix[i][k] + distanceMatrix[k][j]);
      }
    }
  }
  return distanceMatrix;
}