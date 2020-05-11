#include <iostream>

#include "vertex.h"

using namespace std;

Vertex::Vertex() {
  //constructor
  data = '\0';
  
}

void Vertex::setData(char newD) {
  data = newD;
}

char Vertex::getData() {
  return data;
}
