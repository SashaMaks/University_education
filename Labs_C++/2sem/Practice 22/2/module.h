#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <functional>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <windows.h>

// Типы узлов дерева
enum NodeType {
  VALUE,     // константа (число)
  VARIABLE,  // переменная x
  OPERATOR   // операция: '+', '-', '*', '/', '%', '^'
};

struct Node {
  NodeType type;
  int value;    // если type == VALUE
  char op;      // если type == OPERATOR
  Node* left;
  Node* right;
  bool hasVar;  // true, если в поддереве встречалась переменная x

  // Конструкторы
  Node(int val)
      : type(VALUE), value(val), op('\0'),
        left(nullptr), right(nullptr), hasVar(false) {}

  Node(char oper, Node* l = nullptr, Node* r = nullptr)
      : type(OPERATOR), value(0), op(oper),
        left(l), right(r), hasVar(false) {}

  Node(NodeType t)
      : type(t), value(0), op('\0'),
        left(nullptr), right(nullptr), hasVar(false) {}
};

class Tree {
 public:
  Node* root;

  Tree() : root(nullptr) {}
  ~Tree();

  // Методы заполнения дерева
  void FillFromKeyboard(); // ввод инфиксного выражения с клавиатуры
  void FillFromFile();     // чтение выражения из файла FN1

  std::string gen(int count);
  std::string FillRandom(int count);       // случайная генерация дерева

  // Вывод дерева в понятном виде (на боку)
  void Print(std::ostream &os) const;

  // Вычисление выражения (если встречается x, подставляется заданное значение)
  int Evaluate(int x) const;

  // Трансформация дерева: замена всех поддеревьев, где встречалась переменная x, на их значение при данном x
  void Transform(int x);

  // Освобождение памяти дерева
  void Free();

  // Функции для парсинга инфиксного выражения (метод рекурсивного спуска)
  Node*parseExpression(const std::string &expr);
  Node* parseExpressionInternal();
  Node* parseTerm();
  Node* parseExponent();
  Node* parsePrimary();
  void skipSpaces();

  // Строка с выражением и текущая позиция парсера
  std::string input;
  size_t pos;

  // Вспомогательные функции для вычисления и преобразования
  int ipow(int base, int exp) const;
  int evaluate(Node* node, int x) const;
  void markTree(Node* node);
  void transformTree(Node*& node, int x);
  void printTree(Node* node, int indent, std::ostream &os) const;
  void freeTree(Node* node);
};
Node* generateRandomTree(int count);
#endif
