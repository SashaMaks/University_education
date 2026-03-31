#include "Header.h"

TNode::TNode(int value) : data(value), next(nullptr) {}

Stack::Stack() : top(nullptr) {}

// FIX_ME: отсутствует деструктор 
Stack::~Stack() {
  clear();
}

// для добавления элемента в стек
void Stack::push(int value) {
  TNode* newNode = new TNode(value);
  newNode->next = top;
  top = newNode;
  std::cout << "Элемент " << value << " добавлен в стек.\n";
}

// Метод для удаления элемента из стека
void Stack::pop() {
  if (top == nullptr) {
    std::cout << "Стек пуст! Невозможно удалить элемент.\n";
    return;
  }
  TNode* temp = top;
  top = top->next;
  std::cout << "Элемент " << temp->data << " удален из стека.\n";
  delete temp;
}

void Stack::print() {
  if (top == nullptr) {
    std::cout << "Стек пуст!\n";
    return;
  }
  TNode* current = top;
  std::cout << "Элементы стека: ";
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << '\n';
}


TNode* Stack::get_top() {
  return top;
}

//FIX_ME: переименование
//void clearStack() { 
void Stack::clear() {
  while (top != nullptr) {
    TNode* temp = top;
    top = top->next;
    delete temp;                 // Удаляем узел
  }
  std::cout << "Стек очищен.\n";
}

void add_element_and_print_address(Stack& stack, int D) {
  stack.push(D);
  std::cout << "Адрес новой вершины стека: " << stack.get_top() << '\n';
}
