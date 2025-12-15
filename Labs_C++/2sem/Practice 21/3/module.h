#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <windows.h>
#include <fstream>

struct Node {
  int key;
  Node* left, * right;
};
typedef Node* PNode;

void AddToTree(PNode& Tree, int data);
void PrintTree(PNode Tree, int h);
PNode findMax(PNode tree);
PNode findSecondMax(PNode root);
#endif