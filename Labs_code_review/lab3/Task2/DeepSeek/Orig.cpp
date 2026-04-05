//#include <iostream>
//#include <fstream>
//#include <string>
//#include <memory>
//#include <cctype>
//#include <vector>
//
//// Коды операций
//const int ADD = -1;
//const int SUB = -2;
//const int MUL = -3;
//const int DIV = -4;
//const int MOD = -5;
//const int POW = -6;
//
//// Узел дерева
//struct Node {
//  int value;          // если >=0, то число-лист; если <0, то код операции
//  std::shared_ptr<Node> left;
//  std::shared_ptr<Node> right;
//
//  Node(int val) : value(val), left(nullptr), right(nullptr) {}
//  Node(int val, std::shared_ptr<Node> l, std::shared_ptr<Node> r)
//    : value(val), left(l), right(r) {}
//};
//
//// Функция для вычисления значения поддерева
//int evaluate(Node* node) {
//  if (!node) return 0;
//  if (node->value >= 0) return node->value; // лист
//
//  int lval = evaluate(node->left.get());
//  int rval = evaluate(node->right.get());
//
//  switch (node->value) {
//  case ADD: return lval + rval;
//  case SUB: return lval - rval;
//  case MUL: return lval * rval;
//  case DIV: return rval != 0 ? lval / rval : 0; // защита от деления на 0
//  case MOD: return rval != 0 ? lval % rval : 0;
//  case POW: {
//    int res = 1;
//    for (int i = 0; i < rval; ++i) res *= lval;
//    return res;
//  }
//  default: return 0;
//  }
//}
//
//// Построение дерева из потока лексем (рекурсивный спуск)
//std::shared_ptr<Node> buildTree(std::istream& is) {
//  std::string token;
//  if (!(is >> token)) return nullptr;
//
//  // Если токен - число (0-9)
//  if (std::isdigit(token[0])) {
//    return std::make_shared<Node>(token[0] - '0');
//  }
//
//  // Иначе это операция (кодируем её кодом)
//  int opCode = 0;
//  if (token == "+") opCode = ADD;
//  else if (token == "-") opCode = SUB;
//  else if (token == "*") opCode = MUL;
//  else if (token == "/") opCode = DIV;
//  else if (token == "%") opCode = MOD;
//  else if (token == "^") opCode = POW;
//  else return nullptr; // неизвестный токен
//
//  // У операции два поддерева
//  auto left = buildTree(is);
//  auto right = buildTree(is);
//  return std::make_shared<Node>(opCode, left, right);
//}
//
//// Рекурсивное преобразование дерева: заменяем поддеревья с результатом 0..9 на лист
//std::shared_ptr<Node> transform(Node* node) {
//  if (!node) return nullptr;
//  if (node->value >= 0) return std::make_shared<Node>(node->value); // лист
//
//  // Сначала преобразуем левое и правое поддеревья
//  auto newLeft = transform(node->left.get());
//  auto newRight = transform(node->right.get());
//
//  // Создаём временный узел для вычисления
//  auto tempNode = std::make_shared<Node>(node->value, newLeft, newRight);
//  int res = evaluate(tempNode.get());
//
//  // Если результат в [0,9] — заменяем поддерево листом
//  if (res >= 0 && res <= 9) {
//    return std::make_shared<Node>(res);
//  }
//  else {
//    return tempNode; // иначе оставляем как есть
//  }
//}
//
// // Функция для печати дерева (в префиксной форме)
//void printTree(Node* node) {
//  if (!node) {
//    std::cout << " null";
//    return;
//  }
//
//  if (node->value >= 0) {
//    // Лист с числом
//    std::cout << " " << node->value;
//  }
//  else {
//    // Узел-операция
//    std::string op;
//    switch (node->value) {
//    case ADD: op = "+"; break;
//    case SUB: op = "-"; break;
//    case MUL: op = "*"; break;
//    case DIV: op = "/"; break;
//    case MOD: op = "%"; break;
//    case POW: op = "^"; break;
//    }
//    std::cout << " " << op;
//    printTree(node->left.get());
//    printTree(node->right.get());
//  }
//}
//
//// Функция для визуализации дерева (с отступами)
//void printTreePretty(Node* node, int depth = 0, bool isLeft = true) {
//  if (!node) return;
//
//  // Отступы
//  for (int i = 0; i < depth; i++) {
//    std::cout << "    ";
//  }
//
//  // Вывод текущего узла
//  if (node->value >= 0) {
//    std::cout << "├─ " << node->value << std::endl;
//  }
//  else {
//    std::string op;
//    switch (node->value) {
//    case ADD: op = "+"; break;
//    case SUB: op = "-"; break;
//    case MUL: op = "*"; break;
//    case DIV: op = "/"; break;
//    case MOD: op = "%"; break;
//    case POW: op = "^"; break;
//    }
//    std::cout << "├─ [" << op << "]" << std::endl;
//  }
//
//  // Рекурсивный вывод детей
//  if (node->left) {
//    printTreePretty(node->left.get(), depth + 1, true);
//  }
//  if (node->right) {
//    printTreePretty(node->right.get(), depth + 1, false);
//  }
//}
//
//// Функция для сравнения деревьев (проверка корректности)
//bool compareTrees(Node* a, Node* b) {
//  if (!a && !b) return true;
//  if (!a || !b) return false;
//  if (a->value != b->value) return false;
//  return compareTrees(a->left.get(), b->left.get()) &&
//    compareTrees(a->right.get(), b->right.get());
//}
// 
//int main() {
//  std::string filename = "input.txt";
//  std::ifstream file(filename);
//  if (!file.is_open()) {
//    std::cerr << "Не удалось открыть файл " << filename << std::endl;
//    return 1;
//  }
//
//  // Строим исходное дерево
//  auto root = buildTree(file);
//  file.close();
//
//  if (!root) {
//    std::cerr << "Ошибка построения дерева" << std::endl;
//    return 1;
//  }
//
//  // ВЫВОД 1: Исходное дерево
//  std::cout << "\n========== ИСХОДНОЕ ДЕРЕВО ==========\n";
//  std::cout << "Префиксная запись:";
//  printTree(root.get());
//  std::cout << "\n\nСтруктура дерева:\n";
//  printTreePretty(root.get());
//
//  // Вычисляем значение исходного дерева
//  int originalValue = evaluate(root.get());
//  std::cout << "\nЗначение исходного выражения: " << originalValue << std::endl;
//
//  // Преобразуем дерево
//  auto newRoot = transform(root.get());
//
//  // ВЫВОД 2: Преобразованное дерево
//  std::cout << "\n========== ПРЕОБРАЗОВАННОЕ ДЕРЕВО ==========\n";
//  std::cout << "Префиксная запись:";
//  printTree(newRoot.get());
//  std::cout << "\n\nСтруктура дерева:\n";
//  printTreePretty(newRoot.get());
//
//  // Вычисляем значение преобразованного дерева
//  int newValue = evaluate(newRoot.get());
//  std::cout << "\nЗначение преобразованного выражения: " << newValue << std::endl;
//
//  // Проверка: значения должны совпадать
//  std::cout << "\n========== ПРОВЕРКА ==========\n";
//  if (originalValue == newValue) {
//    std::cout << "✓ Значения совпадают! Преобразование корректно.\n";
//  }
//  else {
//    std::cout << "✗ Ошибка! Значения не совпадают.\n";
//    std::cout << "  Было: " << originalValue << ", стало: " << newValue << std::endl;
//  }
//
//  // ВЫВОД 3: Указатель на корень
//  std::cout << "\n========== РЕЗУЛЬТАТ ==========\n";
//  std::cout << "Указатель на корень результирующего дерева: " << newRoot.get() << std::endl;
//
//  // Дополнительная проверка: поддеревья, которые должны были замениться
//  std::cout << "\n========== ДИАГНОСТИКА ==========\n";
//  std::cout << "Поддеревья с результатом 0-9 были заменены на листья.\n";
//  std::cout << "Проверьте визуально структуру дерева выше.\n";
//
//  return 0;
//}