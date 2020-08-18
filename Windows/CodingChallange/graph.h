///////////////////////////////////////////////////////////////////////////////
//
//	Implemantation of Graph
//	@Author: Alperen Demir
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>

#include "Vertex.h"

using namespace std;

class Graph {
 private:
  int numberOfVertex;
  vector<Vertex*> adjancencyList;
  list<int>* weightList;

  bool isACyclicUtil(int v, bool visited[], bool* rs);

 public:
  Graph(int numberOfVertex);
  ~Graph();

  // Method to add an edge/edge pair
  void addEdge(int source, int destination, int weight);
  // Method to delete an edge/edge pair
  void deleteEdge(int source);
  // Method for shortest path with Dijkstra Algorithm
  vector<int> shortestPath(int s);
  // Method for get adjacency list
  vector<Vertex*> getList();
  // Method for print shortest path
  void printShortestPaths(int s);
  // Method for checks if a graph is directed acyclic graph or not
  bool isACyclic();
};
