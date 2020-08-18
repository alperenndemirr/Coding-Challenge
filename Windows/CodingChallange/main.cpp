///////////////////////////////////////////////////////////////////////////////
//
//	Implemantation of Graph
//	@Author: Alperen Demir
//
///////////////////////////////////////////////////////////////////////////////

#include "Graph.h"

int main() {
  // Create a graph
  Graph graph(5);

  // Gives some edges and weights to the vertices
  // Add node 0
  graph.addEdge(0, 1, 3);
  graph.addEdge(0, 4, 8);
  graph.addEdge(0, 3, 7);

  // Add node 1
  graph.addEdge(1, 3, 4);
  graph.addEdge(1, 1, 2);

  // Add node 3
  graph.addEdge(3, 2, 2);

  // Add node 4
  graph.addEdge(4, 3, 3);

  // Operations
  graph.printShortestPaths(0);
  cout << (graph.isACyclic() ? "\n\tDirected acycle graph"
                             : "\n\tNot directed acycle graph") << endl;
  return 0;
}