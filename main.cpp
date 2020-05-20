/*
  This is a Graph Creator by Stefan Ene
 */

#include <iostream>
#include <cstring>

#include "vertex.h"

using namespace std;



//functions
void PRINT(Vertex **list, int iC);
void ADDV(Vertex **list, int iC);
void ADDE(Vertex **list);

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
    else if (strcmp(input, "adde") == 0) {
      ADDE(list);
    }
    else if (strcmp(input, "quit") == 0) {
      cout << endl << "Thank you for using my program." << endl;
      cout << "=========================" << endl;
      break;
    }
    else if (strcmp(input, "print") == 0) {
      PRINT(list, iC);
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

void ADDE(Vertex **list) {
  char in1, in2;
  cout << endl << "Between which two vertices should the edge be constructed:" << endl;
  cout << ">>V1: ";
  cin >> in1;
  cin.clear();
  cin.ignore(10000, '\n');
  cin >> in2;
  cin.clear();
  cin.ignore(10000, '\n');
  //find positions/index of vectors in list
  int vI1, vI2 = 0;
  Vertex* v1 = NULL;
  Vertex* v2 = NULL;
  while (true) {
    if ((list[vI1])->getName() == in1) {
      v1 = list[vI1];
    } else vI1++;
    if ((list[vI2])->getName() == in2) {
      v2 = list[vI2];
    } else vI2++;
    if (v1->getIndex() == vI1 && v2->getIndex() == vI2) break;
  }
  //assign edges
  cout << " >>Edge value: ";
  int val;
  cin >> val;
  cin.clear();
  cin.ignore(10000, '\n');
  v1->setEdge(vI2, val);
  v2->setEdge(vI1, val);
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
  int matrix[20][20];
  int count = 0;
  //construct adjacency matrix visual
  //first row and column
  display[0][0] = ' ';
  while (count < iC) {
    display[0][count+1] = (list[count])->getName();
    display[count+1][0] = (list[count])->getName();
    count++;
  }
  //edge list
  
  //place edge matrix in display array
  
  //display adjacency matrix
  for (int r = 0; r < 21; r++) {
    for (int c = 0; c < 21; c++) {
      cout << display[r][c] << '\t';
    }
    cout << endl;
    if (display[r+1][0] == ' ') break;
  }
}
