///////////////////////////////////////////////////////////////////////////////
//
//	Implemantation of Graph
//	@Author: Alperen Demir
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vector>

using namespace std;

class Vertex {
 private:
  int id;
  vector<pair<int, int>> destinations;

 public:
  Vertex(int id);

  int getID();
  void setID(int id);
  vector<pair<int, int>>* getDestinations();
};
