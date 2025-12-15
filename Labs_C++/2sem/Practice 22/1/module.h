#ifndef TREE_H
#define TREE_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>
#include <functional>

class Tree {
 public:
  Tree();
  ~Tree();
  void FillFromKeyboard();
  void FillFromFile();
  void FillRandom();
  void PrintSideways();
  void Simplify();
  void *GetRootPointer();

 private:
  struct Node {
    int value;
    Node *left;
    Node *right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
  };
  Node *root;
  Node *BuildExpression(std::istream &in);
  void Free(Node *node);
  void PrintSideways(Node *node, int indent);
  int Evaluate(Node *node);
  Node* Simplify(Node* node, bool isSubtree);
};

#endif