#ifndef Header_h
#define Header_h

#include <iostream>

//FIX_ME: переименование Node в TNode по условию задачи
//class Node {
class TNode {
public:
  int data;
  TNode* next;

  TNode(int value);
};

class Stack {
private:
  TNode* top;

public:
  Stack();

  // FIX_ME: отсутствует деструктор 
  ~Stack();

  //  для добавления элемента в стек
  void push(int value);

  // Метод для удаления элемента из стека
  void pop();

  void print();

  //FIX_ME: переименование под вид lower_case_with_underscores
  TNode* get_top();

  //FIX_ME: переименование
  //void clearStack();
  void clear();

  friend void add_element_and_print_address(Stack& stack, int D);
};

//FIX_ME: переименование под вид lower_case_with_underscores
void add_element_and_print_address(Stack& stack, int D);

#endif
