//#include <iostream>
//#include <fstream>
//#include <stack>
//#include <vector>
//#include <string>
//#include <cmath>
//#include <iterator>
//
//// Структура узла дерева
//struct Node {
//  int data;
//  Node* left;
//  Node* right;
//
//  Node(int val) : data(val), left(nullptr), right(nullptr) {}
//};
//
//// Функция преобразования символа в код операции или число
//int symbolToValue(const std::string& symbol) {
//  if (symbol == "+") return -1;
//  if (symbol == "-") return -2;
//  if (symbol == "*") return -3;
//  if (symbol == "/") return -4;
//  if (symbol == "%") return -5;
//  if (symbol == "^") return -6;
//  // Если не операция — это число (0-9)
//  return std::stoi(symbol);
//}
//
//// Построение дерева из префиксного выражения
//Node* buildTreeFromPrefix(const std::vector<std::string>& tokens) {
//  std::stack<Node*> nodeStack;
//
//  // Обрабатываем токены справа налево (для префиксной нотации)
//  for (auto it = tokens.rbegin(); it != tokens.rend(); ++it) {
//    std::string token = *it;
//    int value = symbolToValue(token);
//
//    Node* newNode = new Node(value);
//
//    // Если это операция (отрицательное число), берём два операнда из стека
//    if (value < 0) {
//      if (nodeStack.size() < 2) {
//        // Ошибка: недостаточно операндов для операции
//        delete newNode;
//        while (!nodeStack.empty()) {
//          delete nodeStack.top();
//          nodeStack.pop();
//        }
//        return nullptr;
//      }
//
//      newNode->right = nodeStack.top();
//      nodeStack.pop();
//      newNode->left = nodeStack.top();
//      nodeStack.pop();
//    }
//
//    nodeStack.push(newNode);
//  }
//
//  if (nodeStack.size() != 1) {
//    // Ошибка: некорректное выражение
//    while (!nodeStack.empty()) {
//      delete nodeStack.top();
//      nodeStack.pop();
//    }
//    return nullptr;
//  }
//
//  return nodeStack.top();
//}
//
//// Рекурсивное вычисление и упрощение поддеревьев
//bool simplifySubtree(Node*& node) {
//  if (!node) return false;
//
//  // Если узел — лист (операнд), ничего не делаем
//  if (!node->left && !node->right) {
//    return (node->data >= 0 && node->data <= 9);
//  }
//
//  // Рекурсивно упрощаем левое и правое поддеревья
//  bool leftSimplified = simplifySubtree(node->left);
//  bool rightSimplified = simplifySubtree(node->right);
//
//  // Если оба поддерева — числа из диапазона 0-9, вычисляем результат
//  if (leftSimplified && rightSimplified) {
//    int leftVal = node->left->data;
//    int rightVal = node->right->data;
//    int result = 0;
//    bool valid = true;
//
//    switch (node->data) {
//    case -1: result = leftVal + rightVal; break;
//    case -2: result = leftVal - rightVal; break;
//    case -3: result = leftVal * rightVal; break;
//    case -4:
//      if (rightVal == 0) valid = false;
//      else result = leftVal / rightVal;
//      break;
//    case -5:
//      if (rightVal == 0) valid = false;
//      else result = leftVal % rightVal;
//      break;
//    case -6:
//      if (rightVal < 0) valid = false;
//      else result = static_cast<int>(std::pow(leftVal, rightVal));
//      break;
//    default: valid = false; break;
//    }
//
//    // Если результат валиден и в диапазоне 0-9, заменяем поддерево
//    if (valid && result >= 0 && result <= 9) {
//      // Удаляем старые узлы
//      delete node->left;
//      delete node->right;
//      node->left = nullptr;
//      node->right = nullptr;
//      node->data = result;
//      return true;
//    }
//  }
//
//  return false;
//}
//
//// Основная функция решения
//Node* solveCalcTree7(const std::string& filename) {
//  std::ifstream file(filename);
//  if (!file.is_open()) {
//    std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
//    return nullptr;
//  }
//
//  // Считываем все токены из файла
//  std::vector<std::string> tokens(
//    std::istream_iterator<std::string>(file),
//    std::istream_iterator<std::string>()
//  );
//  file.close();
//
//  if (tokens.empty()) {
//    std::cerr << "Ошибка: файл пуст" << std::endl;
//    return nullptr;
//  }
//
//  // Строим дерево из префиксного выражения
//  Node* root = buildTreeFromPrefix(tokens);
//  if (!root) {
//    std::cerr << "Ошибка: некорректное префиксное выражение" << std::endl;
//    return nullptr;
//  }
//
//  // Упрощаем дерево, вычисляя поддеревья с результатами 0-9
//  simplifySubtree(root);
//
//  return root;
//}
//
//// Вспомогательная функция для вывода дерева (для отладки)
//void printTree(Node* node, int depth = 0) {
//  if (!node) return;
//  printTree(node->right, depth + 1);
//  for (int i = 0; i < depth; ++i) std::cout << "  ";
//  std::cout << node->data << std::endl;
//  printTree(node->left, depth + 1);
//}
//
//int main() {
//  std::string filename;
//  std::cout << "Введите имя файла: ";
//  std::cin >> filename;
//
//  Node* resultRoot = solveCalcTree7(filename);
//
//  if (resultRoot) {
//    std::cout << "Указатель на корень полученного дерева: " << resultRoot << std::endl;
//    std::cout << "Значение корня: " << resultRoot->data << std::endl;
//
//    // Для отладки можно вывести структуру дерева
//    std::cout << "\nСтруктура дерева (справа-корень-слева):\n";
//    printTree(resultRoot);
//  }
//  else {
//    std::cout << "Не удалось построить дерево." << std::endl;
//  }
//
//  return 0;
//}
