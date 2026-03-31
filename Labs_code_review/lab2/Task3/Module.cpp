#include "Header.h"

TNode::TNode(int value) : data(value), next(nullptr) {}


LinkedList::LinkedList() : head(nullptr) {}


void LinkedList::insertSorted(int value) {
  TNode* newNode = new TNode(value);
  if (head == nullptr || head->data < value) {
    newNode->next = head;
    head = newNode;
  }
  else {
    TNode* current = head;
    while (current->next != nullptr && current->next->data > value) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
}


void LinkedList::print() {
  TNode* current = head;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << '\n';
}


void LinkedList::readFromFile(const std::string& filename) {
  std::ifstream file(filename); // Открываем файл для чтения
  if (!file.is_open()) { // Проверяем, удалось ли открыть файл
    std::cerr << "Ошибка открытия файла!" << '\n';
    return;
  }
  //FIX_ME: нет проверки на то что файл пуст
  if (file.peek() == std::ifstream::traits_type::eof()) {
    std::cout << "Ошибка: Файл пуст!\n";
    return;
  }

  int N;

  //FIX_ME: нет проверки на правильность чтения
  //file >> N;
  if (!read_int_from_file(file, N, "Ошибка: Не удалось прочитать N")) return;

  std::cout << N;
  int value;
  for (int i = 0; i < N; ++i) { // Читаем элементы и добавляем их в список
    if (!read_int_from_file(file, value, "Ошибка: Не удалось прочитать элемент")) return;
    LinkedList::insertSorted(value); // Вставляем элемент с сохранением упорядоченности
  }

  file.close();// Закрываем файл
}


void readFromFile(LinkedList& list, const std::string& filename) {
  list.readFromFile(filename);
}

//FIX_ME: функция, для чтения из файла
bool read_int_from_file(std::ifstream& file, int& value,
  const std::string& errorMsg) {
  if (!(file >> value)) {
    std::cout << errorMsg << "\n";
    return false;
  }
  return true;
}