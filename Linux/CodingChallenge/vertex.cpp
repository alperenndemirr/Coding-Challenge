///////////////////////////////////////////////////////////////////////////////
//
//	Implemantation of Graph
//	@Author: Alperen Demir
//
///////////////////////////////////////////////////////////////////////////////

#include "vertex.h"

Vertex::Vertex(int id) : id(id) {}

Vertex::~Vertex() {}

int Vertex::getID() { return id; }

void Vertex::setID(int id) { this->id = id; }

vector<pair<int, int>>* Vertex::getDestinations() { return &destinations; }
