#ifndef Header_h
#define Header_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
#include <windows.h>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

//FIX_ME: функция для проверки, что подается число 
bool is_number(const std::string& s);

bool is_valid_prefix(const std::vector<int>& tokens);

std::vector<int> read_expression(const std::string& filename);

Node* build_tree(std::vector<int>& tokens, int& pos);

int compute(int op, int a, int b);

void print_tree(Node* node);

Node* simplify(Node* node);
// FIX_ME: бессмысленная функция для вывода и так имеющегося значения
//void printRootPointer(Node* root);

//FIX_ME: переименование под вид lower_case_with_underscores
//void freeTree(Node* node);
void free_tree(Node* node);

//FIX_ME: две бессмысленные функции с одинаковым функционалом
/* 
void printTreeBefore(Node* root);

void printTreeAfter(Node* root); */

#endif