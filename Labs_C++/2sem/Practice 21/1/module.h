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
void Print(PNode Tree);
void my_lapki(PNode &Tree);
void my_file(PNode &Tree);
void my_rand(PNode &Tree);
void PrintTree(PNode Tree, int h);
#endif