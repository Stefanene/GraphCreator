/*
  This is a Graph Creator by Stefan Ene
 */

#include <iostream>
#include <cstring>
//colors
#define RESET "\033[0m"
#define RED   "\033[31m"
#define BLUE  "\033[34m"

#include "vertex.h"

using namespace std;



//functions
void PRINT(Vertex **list, int iC);
void ADDV(Vertex **list, int iC);
void REMOVEV(Vertex **list, int iC);
void ADDE(Vertex **list, int iC);
void REMOVEE(Vertex** list, int iC);
void FSP(Vertex **list, int iC);
Vertex* findVertex(Vertex** list, char in, int iC);

//MAIN function
int main() {
  //vertex list
  Vertex **list = new Vertex*[20];
  //variables
  int iC = 0;  //index counter
  //program
  cout << "=========================" << endl;
  cout << "Welcome to my Graph Creator." << endl;
  while (true) {
    cout << endl << "You can: addv, removev, adde, removee, print, fsp, quit." << endl;
    char input[20];
    cin.get(input, 20);
    cin.clear();
    cin.ignore(10000,'\n');
    if (strcmp(input, "addv") == 0) {
      ADDV(list, iC);
      iC++;
    }
    else if (strcmp(input, "removev") == 0) {
      REMOVEV(list, iC);
      iC--;
    }
    else if (strcmp(input, "adde") == 0) {
      ADDE(list, iC);
    }
    else if (strcmp(input, "removee") == 0) {
      REMOVEE(list, iC);
    }
    else if (strcmp(input, "quit") == 0) {
      cout << endl << "Thank you for using my program." << endl;
      cout << "=========================" << endl;
      break;
    }
    else if (strcmp(input, "print") == 0) {
      PRINT(list, iC);
    }
    else if (strcmp(input, "fsp") == 0) {
      cout << endl << "Find the shortest path with Dijkstra's Algorithm." << endl;
      FSP(list, iC);
    }
    else {
      cout << endl << "Invalid input. Try again." << endl;
    }
  }
  return 0; //end program
}

void ADDV(Vertex **list, int iC) {
  //initialize new vector object
  Vertex* newPt = new Vertex();
  newPt->setIndex(iC);
  //read user input
  char in;
  cout << ">>Char of new vertex: ";
  cin >> in;
  cin.clear();
  cin.ignore(10000, '\n');
  //assign input values to object
  newPt->setName(in);
  //add vertex to list
  list[iC] = newPt;
  cout << endl << "Vertex " << newPt->getName() << " was added." << endl;
}

void REMOVEV(Vertex **list, int iC) {
  if (list[0] == NULL) {
    //at least one vertex
    cout << endl << "YOu need a vertex first." << endl;
    return;
  }
  char in;
  cout << ">>Vertex to be removed: ";
  cin >> in;
  cin.clear();
  cin.ignore(10000, '\n');
  Vertex* v = findVertex(list, in, iC);
  if (v == NULL) {
    cout << endl << "No such vector found. Try again." << endl;
    return;
  }
  //begin edge removal (zero)
  int i = v->getIndex();
  int c = 0;
  while (c < iC) {
    //set its partners' edges to it to zero
    (list[c])->setEdge(i, 0);
    c++;
  }
  //delete this vertex
  v->~Vertex();
  //remove it from list
  list[i] = NULL;
  int rem = i;
  //redo edge list
  while (rem < iC) {
    for (int ce = i; ce < 20; ce++) {
      if (ce = 19) {
	list[rem]->setEdge(ce, 0);
	break;
      }
      list[rem]->setEdge(ce, list[rem]->getEdge(ce+1));
    }
    rem++;
  }
  //move all elements that follow down by 1 index
  while (i < iC) {
    if (i == 19) {
      //last case
      list[i] = NULL;
      break;
    }
    list[i] = list[i+1];
    (list[i])->setIndex(i);
    i++;
  }
}

void ADDE(Vertex **list, int iC) {
  if(list[0] == NULL || list[1] == NULL) {
    //have at least two vectors
    cout << endl << "Input at least two vectors first." << endl;
    return;
  }
  char in1, in2;
  cout << endl << "Between which two vertices should the edge be constructed:" << endl;
  cout << ">>V1: ";
  cin >> in1;
  cin.clear();
  cin.ignore(10000, '\n');
  cout << ">>V2: ";
  cin >> in2;
  cin.clear();
  cin.ignore(10000, '\n');
  //find positions/index of vectors in list
  Vertex* v1 = findVertex(list, in1, iC);
  Vertex* v2 = findVertex(list, in2, iC);
  if (v1 == NULL || v2 == NULL) {
    cout << endl << "Try again. Invalid vertex." << endl;
    return;
  }
  //assign edges
  cout << " >>Edge value: ";
  int val;
  cin >> val;
  cin.clear();
  cin.ignore(10000, '\n');
  v1->setEdge(v2->getIndex(), val);
  v2->setEdge(v1->getIndex(), val);
}

void REMOVEE(Vertex **list, int iC) {
  if(list[0] == NULL || list[1] == NULL) {
    //have at least two vectors
    cout << endl << "Input at least two vertices first." << endl;
    return;
  }
  char in1, in2;
  cout << "What vectors are connected by this edge?" << endl;
  cout << ">>V1: ";
  cin >> in1;
  cin.clear();
  cin.ignore(10000, '\n');
  cout << ">>V2: ";
  cin >> in2;
  cin.clear();
  cin.ignore(10000, '\n');
  Vertex* v1 = findVertex(list, in1, iC);
  Vertex* v2 = findVertex(list, in2, iC);
  if (v1 == NULL || v2 == NULL) {
    cout << endl << "Try again. Invalid vertex." << endl;
    return;
  }
  cout << endl << "Edge found ... ";
  v1->setEdge(v2->getIndex(), 0);
  v2->setEdge(v1->getIndex(), 0);
  cout << "Edge removed." << endl;
}

void FSP(Vertex **list, int iC) {
  if (list[0] == NULL || list[1] == NULL) {
    //need at least two vectors
    cout << endl << "Input at least two vertices first." << endl;
    return;
  }
  char in1, in2;
  cout << ">>Starting vertex: ";
  cin >> in1;
  cin.clear();
  cin.ignore(10000, '\n');
  cout << ">>Ending vertex: ";
  cin >> in2;
  cin.clear();
  cin.ignore(10000, '\n');
  Vertex* start = findVertex(list, in1, iC);
  Vertex* end = findVertex(list, in2, iC);
  if (start == NULL || end == NULL) {
    cout << endl << "Try again. Invalid vertex." << endl;
    return;
  }
}

//print adjacency matrix
void PRINT(Vertex **list, int iC) {
  char display[21][21];  //[row][col]
  //initialize empty matrix
  for (int r = 0; r < 21; r++) {
    for (int c = 0; c < 21; c++) {
      display[r][c] = ' ';
    }
  }
  int edgeDisp[20][20];
  int count = 0;
  //construct adjacency matrix visual
  //first row and column
  display[0][0] = ' ';
  while (count < iC) {
    display[0][count+1] = (list[count])->getName();
    display[count+1][0] = (list[count])->getName();
    count++;
  }
  //create edge display list
  for (int r = 0; r < iC; r++) {
    Vertex* v = list[r];
    for (int c = 0; c < iC; c++) {
      Vertex* vr = list[c];
      if (v->getEdge(vr->getIndex()) != 0) {
	edgeDisp[r][c] = 'T';
      } else {
	edgeDisp[r][c] = 'F';
      }
    }
  }
  //place edge matrix in display array
  for (int r = 0; r < iC; r++) {
    for (int c = 0; c < iC; c++) {
      display[r+1][c+1] = edgeDisp[r][c];
    }
  }
  //display adjacency matrix
  for (int r = 0; r < 21; r++) {
    for (int c = 0; c < 21; c++) {
      if (display[r][c] == 'T' && c != 0 && r != 0) {
	cout << BLUE << display[r][c] << RESET << '\t';
      } else if (display[r][c] == 'F' && c != 0 && r != 0) {
	cout << RED << display[r][c] << RESET << '\t';
      } else {
	cout << display[r][c] << '\t';
      }
    }
    cout << endl;
    if (display[r+1][0] == ' ') break;
  }
}

Vertex* findVertex(Vertex** list, char in, int iC) {
  int i = 0;
  while(i < iC) {
    if((list[i])->getName() == in) {
      return (list[i]);
    } else {
      i++;
    }
  }
  return NULL;
}
