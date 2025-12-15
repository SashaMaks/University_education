#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <windows.h>
#include <fstream>

// Структура узла дерева
struct Node {
  int key;
  Node* left;
  Node* right;
};

typedef Node* PNode;

// Прототипы функций:
void AddToTree(PNode& Tree, int data);
void Print(PNode Tree,int h);
void my_lapki(PNode &p);
void my_rand(PNode &p);
void my_file(PNode &p);

#endif