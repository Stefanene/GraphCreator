#include <iostream>

#include "vertex.h"

using namespace std;

Vertex::Vertex() {
  //constructor
  name = '\0';
  
}

Vertex::~Vertex() {
  //destructor
  
}

void Vertex::setName(char newN) {
  name = newN;
}

char Vertex::getName() {
  return name;
}

void Vertex::setIndex(int newI) {
  index = newI;
}

int Vertex::getIndex() {
  return index;
}

void Vertex::setEdge(int from, int val) {
  edges[from] = val;
}

int Vertex::getEdge(int from) {
  return edges[from];
}
