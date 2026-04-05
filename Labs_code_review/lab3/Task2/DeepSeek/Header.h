#ifndef Header_h
#define Header_h

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <cctype>
#include <vector>

const int ADD = -1;
const int SUB = -2;
const int MUL = -3;
const int DIV = -4;
const int MOD = -5;
const int POW = -6;

struct Node {
  int value;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;

  Node(int val);
  Node(int val, std::shared_ptr<Node> l, std::shared_ptr<Node> r);
};

int evaluate(Node* node);

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//std::shared_ptr<Node> buildTree(std::istream& is);
std::shared_ptr<Node> build_tree(std::istream& is);

std::shared_ptr<Node> transform(Node* node);

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//void printTree(Node* node);
void print_tree(Node* node);

//FIX_ME: Имена функций и методов: lower_case_with_underscores 
// + бессмысленная переменная isLeft
//void printTreePretty(Node* node, int depth, bool isLeft);
void print_tree_pretty(Node* node, int depth);

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//bool compareTrees(Node* a, Node* b);
bool compare_trees(Node* a, Node* b);

#endif