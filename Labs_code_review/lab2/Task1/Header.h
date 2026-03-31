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


  TNode* getTop();

  //FIX_ME: переименование
  //void clearStack();
  void clear();

  friend void addElementAndPrintAddress(Stack& stack, int D);
};

void addElementAndPrintAddress(Stack& stack, int D);

#endif