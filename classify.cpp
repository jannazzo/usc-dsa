// Copyright 2025 Luke Jannazzo

#include <string>
using std::string;

void dfs(int i, int visited[], int size, int** adjacency) {
  visited[i] = 1;
  for ( int v = 0; v < size; ++v ) {
    if ( adjacency[i][v] == 1 && visited[v] == 0)
      dfs(v, visited, size, adjacency);
  }
}

string BruteForceClassifyNetwork(int** adjacency, int size) {
  // check if it's a mesh network
  bool mesh = true;
  for ( int i = 0; i < size; ++i ) {
    for ( int j = 0; j < size; ++j ) {
      if ( i != j && adjacency[i][j] != 1 )
        mesh = false;
    }
  }
  if ( mesh )
    return "fully connected mesh";
  
  // calcluate the degree of each node
  int degree[size];
  for ( int i = 0; i < size; ++i ) {
    int d = 0;
    for ( int j = 0; j < size; ++j ) {
      d += adjacency[i][j];
    }
    degree[i] = d;
  }
  // check if it's a ring network
  bool ring = true;
  for ( int i = 0; i < size; ++i ) {
    if ( degree[i] != 2 )
      ring = false;
  }
  int visited[size];
  dfs(0, visited, size, adjacency);
  for ( int i = 0; i < size; ++i ) {
    if ( visited[i] == 0 )
      ring = false;
  }
  if ( ring )
    return "ring network";
  
  // check for star network
  bool star = true;
  for ( int i = 0; i < size; ++i ) {
    if ( degree[i] == size - 1 ) {
      for ( int j = 0; j < size; ++j ) {
        if ( j != i ) {
          if ( degree[j] != 1 || adjacency[i][j] == 0 )
            star = false;
        }
      }
    }
  }
  if ( star )
    return "star network";
  
  return "other topology of network";
}