#include "Header.h"

Node::Node(int val) : data(val), left(nullptr), right(nullptr) {}

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//int symbolToValue(const std::string& symbol) {
int symbol_to_value(const std::string& symbol) {
  if (symbol == "+") return -1;
  if (symbol == "-") return -2;
  if (symbol == "*") return -3;
  if (symbol == "/") return -4;
  if (symbol == "%") return -5;
  if (symbol == "^") return -6;
  return std::stoi(symbol);
}

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//Node* buildTreeFromPrefix(const std::vector<std::string>& tokens) {
Node* build_tree_from_prefix(const std::vector<std::string>& tokens) {
  std::stack<Node*> nodeStack;

  // Обрабатываем токены справа налево (для префиксной нотации)
  for (auto it = tokens.rbegin(); it != tokens.rend(); ++it) {
    std::string token = *it;
    int value = symbol_to_value(token);

    Node* newNode = new Node(value);

    // Если это операция (отрицательное число), берём два операнда из стека
    if (value < 0) {
      if (nodeStack.size() < 2) {
        // Ошибка: недостаточно операндов для операции
        delete newNode;
        while (!nodeStack.empty()) {
          delete nodeStack.top();
          nodeStack.pop();
        }
        return nullptr;
      }

      newNode->right = nodeStack.top();
      nodeStack.pop();
      newNode->left = nodeStack.top();
      nodeStack.pop();
    }

    nodeStack.push(newNode);
  }

  if (nodeStack.size() != 1) {
    while (!nodeStack.empty()) {
      delete nodeStack.top();
      nodeStack.pop();
    }
    return nullptr;
  }

  return nodeStack.top();
}

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//bool simplifySubtree(Node*& node) {
bool simplify_subtree(Node*& node) {
  if (!node) return false;

  // Если узел — лист (операнд), ничего не делаем
  if (!node->left && !node->right) {
    return (node->data >= 0 && node->data <= 9);
  }

  // Рекурсивно упрощаем левое и правое поддеревья
  bool leftSimplified = simplify_subtree(node->left);
  bool rightSimplified = simplify_subtree(node->right);

  // Если оба поддерева — числа из диапазона 0-9, вычисляем результат
  if (leftSimplified && rightSimplified) {
    int leftVal = node->left->data;
    int rightVal = node->right->data;
    int result = 0;
    bool valid = true;

    switch (node->data) {
    case -1: result = leftVal + rightVal; break;
    case -2: result = leftVal - rightVal; break;
    case -3: result = leftVal * rightVal; break;
    case -4:
      if (rightVal == 0) valid = false;
      else result = leftVal / rightVal;
      break;
    case -5:
      if (rightVal == 0) valid = false;
      else result = leftVal % rightVal;
      break;
    case -6:
      if (rightVal < 0) valid = false;
      else result = static_cast<int>(std::pow(leftVal, rightVal));
      break;
    default: valid = false; break;
    }

    // Если результат валиден и в диапазоне 0-9, заменяем поддерево
    if (valid && result >= 0 && result <= 9) {
      delete node->left;
      delete node->right;
      node->left = nullptr;
      node->right = nullptr;
      node->data = result;
      return true;
    }
  }

  return false;
}

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//Node* solveCalcTree7(const std::string& filename) {
Node* solve_calc_tree(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Ошибка: не удалось открыть файл " << filename << '\n';
    return nullptr;
  }

  //FIX_ME: ошибка при запуске кода, так как неверно написан код
  /*std::vector<std::string> tokens(
    std::istream_iterator<std::string>(file),
    std::istream_iterator<std::string>()
  );*/
  std::vector<std::string> tokens;
  std::string token;
  while (file >> token) {
    tokens.push_back(token);
  }

  file.close();

  if (tokens.empty()) {
    std::cerr << "Ошибка: файл пуст\n";
    return nullptr;
  }

  Node* root = build_tree_from_prefix(tokens);
  if (!root) {
    std::cerr << "Ошибка: некорректное префиксное выражение\n";
    return nullptr;
  }

  simplify_subtree(root);

  return root;
}

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//void printTree(Node* node, int depth) {
void print_tree(Node* node, int depth) {
  if (!node) return;
  print_tree(node->right, depth + 1);
  for (int i = 0; i < depth; ++i) std::cout << "  ";
  std::cout << node->data << '\n';
  print_tree(node->left, depth + 1);
}