#include "Header.h"

bool is_number(const std::string& str) {
  if (str.empty()) return false;
  int start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
  for (int i = start; i < str.length(); ++i) {
    if (!isdigit(str[i])) return false;
  }
  return start < str.length();
}

Queue::Queue() : P1(nullptr), P2(nullptr) {}

void Queue::push(int num) { // Добавление элемента в очередь
  TNode* newNode = new TNode;
  newNode->data = num;
  newNode->next = nullptr;
  //FIX_ME: проверка, что очередь не пустая лучше делать через nullptr
  //if (!P2) {
  if (P2 == nullptr) {
    P1 = P2 = newNode;
  }
  else {
    P2->next = newNode;
    P2 = newNode;
  }
  //FIX_ME: расходуется лишняя память:
  //newNode->next = nullptr;
}

void Queue::show() { // Вывод элементов
  if (P1==nullptr) {
    std::cout << "Очередь пустая\n";
    return;
  }

  TNode* temp = P1;
  //FIX_ME: это можно сделать и до создания дополнительной переменной, с полем
  /*if (!temp) {
    std::cout << "Очередь пустая\n";
    return;
  }*/

  //FIX_ME: для проверки на пустоту сравниваем с nullptr
  //while (temp) {
  while (temp != nullptr) {
    //FIX_ME: для знака пробела лучше исппользовать тип чар ' '
    //std::cout << temp->data << " ";
    std::cout << temp->data << ' ';
    temp = temp->next;
  }
  std::cout << '\n';
}

bool Queue::pop(int& num) {  // Извлечение элемента из очереди
  //FIX_ME: для проверки на пустоту сравниваем с nullptr
  //if (!P1) return false; // Очередь пуста
  if (P1 == nullptr) {
    return false;
  }

  TNode* temp = P1;
  num = P1->data;
  P1 = P1->next;

  //FIX_ME: для проверки на пустоту сравниваем с nullptr
  //if (!P1) P2 = nullptr; // Если очередь стала пустой
  if (P1 == nullptr) {
    P2 = nullptr;
  }

  delete temp;
  return true;
}

//FIX_ME: переименование под вид lower_case_with_underscores
//Queue::TNode* Queue::getP1() const;
Queue::TNode* Queue::get_p1() const {
  return P1;
}

//FIX_ME: переименование под вид lower_case_with_underscores
//void Queue::getP1data() const;
void Queue::get_p1_data() const {
  int num1 = P1->data;
  std::cout << num1;
}

//FIX_ME: переименование под вид lower_case_with_underscores
//void Queue::getP2data() const {
void Queue::get_p2_data() const {
  int num1 = P2->data;
  std::cout << num1;
}

//FIX_ME: переименование под вид lower_case_with_underscores
//Queue::TNode* Queue::getP2() const {
Queue::TNode* Queue::get_p2() const {
  return P2;
}

//FIX_ME: переименование под вид lower_case_with_underscores
//void Queue::EvenHead() {
void Queue::even_head() {
  int num;
  while (!(P1 == nullptr) && (P1->data % 2 != 0)) {
    pop(num);
    std::cout << num << " ";
  }
  std::cout << '\n';
}

Queue::~Queue() {
  int del;
  while (pop(del));
}

// FIX_ME: очистка очереди
void Queue::clear() {
  int del;
  while (pop(del));
}