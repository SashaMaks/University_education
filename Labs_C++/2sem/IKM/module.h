#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <string>
#include <windows.h>

class PolynomialParseException : public std::runtime_error {
 public:
  explicit PolynomialParseException(const std::string & msg)
      : std::runtime_error(msg) {}
};

// Структура для представления одночлена многочлена в виде узла однонаправленного списка
struct PNode {
  int coeff;      // коэффициент
  int exp;        // показатель степени
  PNode* next;     // указатель на следующий узел

  PNode(int coefficient, int exponent)
      : coeff(coefficient), exp(exponent), next(nullptr) {}
};

// Функция для добавления нового одночлена в конец списка
void append(PNode*& head, int coeff, int exp);

// Функция для парсинга строкового представления многочлена
PNode* parse(const std::string &str);

// Сортировка списка по убыванию значений показателей степени (методом вставки)
PNode* sort(PNode* head);

// Объединение одночленов с одинаковыми степенями в отсортированном списке
PNode* combineLikePNodes(PNode* head);

// Преобразование списка многочлена в строковый формат
std::string polynomialToString(PNode* head);

// Освобождение памяти, занимаемой узлами списка
void freePolynomial(PNode* head);

#endif