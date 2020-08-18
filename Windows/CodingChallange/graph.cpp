///////////////////////////////////////////////////////////////////////////////
//
//	Implemantation of Graph
//	@Author: Alperen Demir
//
///////////////////////////////////////////////////////////////////////////////

#include "graph.h"

// Constructer with number of vertices
Graph::Graph(int numberOfVertex) {
  // Set number of vertices
  this->numberOfVertex = numberOfVertex;

  // Create new adjancency list
  for (int i = 0; i < numberOfVertex; i++) {
    adjancencyList.push_back(new Vertex(i));
  }
  weightList = new list<int>[numberOfVertex];
};

vector<Vertex*> Graph::getList() { return adjancencyList; }

Graph::~Graph() {
  // delete[]adj;
}

void Graph::addEdge(int source, int destination, int weight) {
  adjancencyList.at(source)->getDestinations()->push_back(
      make_pair(destination, weight));
  weightList[destination].push_back(weight);
}

void Graph::deleteEdge(int source) {
  adjancencyList.at(source)->getDestinations()->clear();
}

vector<int> Graph::shortestPath(int start) {
  // Create set to store vertices
  // Use this to extract the shortest path
  set<pair<int, int>> extract_set;
  set<pair<int, int>> path;

  int new_source = 0;
  // Vector for distance
  // All paths are initialized to a large value
  vector<int> distances(numberOfVertex, INT_MAX);

  // Insert the entry point into set
  // Initialize distance to 0
  extract_set.insert(make_pair(0, start));
  distances[start] = 0;

  // Continue until all shortest distances are finalized
  while (!extract_set.empty()) {
    // Extract the minimum distances
    pair<int, int> tmp = *(extract_set.begin());
    extract_set.erase(extract_set.begin());
    path.insert(make_pair(new_source, tmp.second));

    // Get vertex number
    int new_source = tmp.second;

    // Go over the adjancency list
    for (auto i = adjancencyList.at(new_source)->getDestinations()->begin();
         i != adjancencyList.at(new_source)->getDestinations()->end(); i++) {
      // Get the vertex and weight
      int destination = (*i).first;
      int weight = (*i).second;

      // Check if we have found a shorter path to v
      if (distances[destination] > distances[new_source] + weight) {
        // Remove the current distance if it is in the set
        if (distances[destination] != INT_MAX) {
          extract_set.erase(
              extract_set.find(make_pair(distances[destination], destination)));
        }
        // Update distance
        distances[destination] = distances[new_source] + weight;
        extract_set.insert(make_pair(distances[destination], destination));
      }
    }
  }
  return distances;
}

void Graph::printShortestPaths(int s) {
  vector<int> distances = shortestPath(s);

  cout << "\n\tMinimum distances from vertex: " << s << endl << endl;
  for (int i = 0; i < numberOfVertex; i++) {
    cout << "\tVertex : " << i << "\tDistance: "
         << (distances[i] == INT_MAX ? "Unexplored vertex"
                                     : to_string(distances[i])) << endl;
  }
}

bool Graph::isACyclicUtil(int v, bool visited[], bool* recStack) {
  if (visited[v] == false) {
    // Mark the current node as visited and part of recursion stack
    visited[v] = true;
    recStack[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = weightList[v].begin(); i != weightList[v].end(); ++i) {
      if (!visited[*i] && isACyclicUtil(*i, visited, recStack))
        return true;
      else if (recStack[*i])
        return true;
      else if (numberOfVertex == 0)
        return true;
    }
  }
  // Remove the vertex from recursion stack
  recStack[v] = false;
  return false;
}

bool Graph::isACyclic() {
  // Mark all the vertices as not visited and not part of recursion
  // stack
  bool* visited = new bool[numberOfVertex];
  bool* recStack = new bool[numberOfVertex];
  for (int i = 0; i < numberOfVertex; i++) {
    visited[i] = false;
    recStack[i] = false;
  }

  // Call the recursive helper function to detect cycle in different
  // DFS trees
  for (int i = 0; i < numberOfVertex; i++) {
    if (isACyclicUtil(i, visited, recStack)) {
      return true;
    }
  }
  return false;
}