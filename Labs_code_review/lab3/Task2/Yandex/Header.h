#ifndef Header_h
#define Header_h

#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <string>
#include <cmath>
#include <iterator>

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int val);
};

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//int symbolToValue(const std::string& symbol);
int symbol_to_value(const std::string& symbol);

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//Node* buildTreeFromPrefix(const std::vector<std::string>& tokens);
Node* build_tree_from_prefix(const std::vector<std::string>& tokens);

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//bool simplifySubtree(Node*& node);
bool simplify_subtree(Node*& node);

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//Node* solveCalcTree7(const std::string& filename);
Node* solve_calc_tree(const std::string& filename);

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//void printTree(Node* node, int depth);
void print_tree(Node* node, int depth);

#endif