#include "Header.h"

// FIX_ME: некорректное название и использование конструктора
/*void Initsializatsiya() {
  head = nullptr;
}*/
LinkedList::LinkedList() : head(nullptr) {}


// FIX_ME: некорректное название
//void LinkedList::Ochistka() {
void LinkedList::clear() {
  // FIX_ME: некорректное название
  // TNode* Tekushiy = head;
  TNode* current = head;
  while (current != nullptr) {
    // FIX_ME: некорректное название
    // TNode* Vremenniy = Tekushiy;
    TNode* new_node = current;
    current = current->next;
    delete new_node;
  }
  head = nullptr;
}

// FIX_ME: некорректное название 
//void LinkedList::DobavitElement(int Znachenie) {
void LinkedList::add(int value) {
  // FIX_ME: некорректное название 
  // TNode* Noviy = new TNode;
  TNode* new_node = new TNode;
  new_node->data = value;
  new_node->previous = nullptr;
  new_node->next = nullptr;

  if (head == nullptr) {
    head = new_node;
  }
  else {
    // FIX_ME: некорректное название 
    // TNode* Tekushiy = head;
    TNode* current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new_node;
    new_node->previous = current;
  }
}

// FIX_ME: некорректное название
// void LinkedList::VivodSpiska() {
void LinkedList::print() {
  // FIX_ME: некорректное название 
  TNode* current = head;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << '\n';
}

// FIX_ME: некорректное название
// void LinkedList::PoiskMinMax(Uzel*& Min, Uzel*& Max) {
void LinkedList::find_min_and_max(TNode*& min_node, TNode*& max_node) {
  if (head == nullptr) return;

  min_node = max_node = head;
  // FIX_ME: некорректное название
  // TNode* Tekushiy = head->next;
  TNode* current = head->next;

  while (current != nullptr) {
    if (current->data < min_node->data) min_node = current;
    if (current->data > max_node->data) max_node = current;
    current = current->next;
  }
}

// FIX_ME: некорректное название
// bool LinkedList::ProverkaPoryadka(TNode* A, TNode* B) {
bool LinkedList::is_first_before_second(TNode* a, TNode* b) {
  // FIX_ME: некорректное название
  //TNode* Tekushiy = head;
  TNode* current = head;
  while (current != nullptr) {
    if (current == a) return true;
    if (current == b) return false;
    current = current->next;
  }
  return false;
}

// FIX_ME: некорректное название
// void LinkedList::VivodMezhduMinMax() {
void LinkedList::print_between_min_max() {
  // FIX_ME: некорректное название
  //TNode* Min = nullptr;
  //TNode* Max = nullptr;
  TNode* min_node = nullptr;
  TNode* max_node = nullptr;
  find_min_and_max(min_node, max_node);

  if (min_node == nullptr || max_node == nullptr || min_node == max_node) {
    std::cout << "Нет элементов для вывода!\n";
    return;
  }

  // FIX_ME: должно быть в виде lower_case_with_underscores
  // bool MinPerviy = is_first_before_second(min_node, max_node);
  bool min_first = is_first_before_second(min_node, max_node);

  // FIX_ME: должно быть в виде lower_case_with_underscores
  // TNode* Start = MinPerviy ? min_node : max_node;
  // TNode* End = MinPerviy ? max_node : min_node;
  TNode* start = min_first ? min_node : max_node;
  TNode* end = min_first ? max_node : min_node;

  std::cout << "Элементы между " << min_node->data << " и " << max_node->data << ": ";
  // FIX_ME: некорректное название
  //TNode* Tekushiy = start->next;
  TNode* current = start->next;

  // FIX_ME: некорректное название
  //bool EstElementy = false;
  bool found = false;

  while (current != nullptr && current != end) {
    std::cout << current->data << " ";
    found = true;
    current = current->next;
  }

  if (!found) std::cout << "Отсутствуют";
  std::cout << '\n';
}
// FIX_ME: нет деструктора
LinkedList::~LinkedList() {
  clear();
}