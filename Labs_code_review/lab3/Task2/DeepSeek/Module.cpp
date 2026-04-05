#include "Header.h"

Node::Node(int val) : value(val), left(nullptr), right(nullptr) {}
Node::Node(int val, std::shared_ptr<Node> l, std::shared_ptr<Node> r)
  : value(val), left(l), right(r) {}

// Функция для вычисления значения поддерева
int evaluate(Node* node) {
  if (!node) return 0;
  if (node->value >= 0) return node->value;

  int lval = evaluate(node->left.get());
  int rval = evaluate(node->right.get());

  switch (node->value) {
  case ADD: return lval + rval;
  case SUB: return lval - rval;
  case MUL: return lval * rval;
  case DIV: return rval != 0 ? lval / rval : 0;
  case MOD: return rval != 0 ? lval % rval : 0;
  case POW: {
    int res = 1;
    for (int i = 0; i < rval; ++i) res *= lval;
    return res;
  }
  default: return 0;
  }
}

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//std::shared_ptr<Node> buildTree(std::istream& is) {
std::shared_ptr<Node> build_tree(std::istream& is) {
  std::string token;
  if (!(is >> token)) return nullptr;

  if (std::isdigit(token[0])) {
    return std::make_shared<Node>(token[0] - '0');
  }
  //FIX_ME: Имена переменных: lower_case_with_underscores
  //int opCode = 0;
  int op_code = 0;
  if (token == "+") op_code = ADD;
  else if (token == "-") op_code = SUB;
  else if (token == "*") op_code = MUL;
  else if (token == "/") op_code = DIV;
  else if (token == "%") op_code = MOD;
  else if (token == "^") op_code = POW;
  else return nullptr;

  auto left = build_tree(is);
  auto right = build_tree(is);
  return std::make_shared<Node>(op_code, left, right);
}

// Рекурсивное преобразование дерева: заменяем поддеревья с результатом 0..9 на лист
std::shared_ptr<Node> transform(Node* node) {
  if (!node) return nullptr;
  if (node->value >= 0) return std::make_shared<Node>(node->value); // лист

  //FIX_ME: Имена переменных: lower_case_with_underscores
  //auto newLeft = transform(node->left.get());
  auto new_left = transform(node->left.get());

  //FIX_ME: Имена переменных: lower_case_with_underscores
  //auto newRight = transform(node->right.get());
  auto new_right = transform(node->right.get());

  //FIX_ME: Имена переменных: lower_case_with_underscores
  //auto tempNode = std::make_shared<Node>(node->value, new_left, new_right);
  auto temp_node = std::make_shared<Node>(node->value, new_left, new_right);
  int res = evaluate(temp_node.get());

  if (res >= 0 && res <= 9) {
    return std::make_shared<Node>(res);
  }
  else {
    return temp_node;
  }
}

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//void printTree(Node* node) {
void print_tree(Node* node) {
  if (!node) {
    std::cout << " null";
    return;
  }

  if (node->value >= 0) {
    std::cout << " " << node->value;
  }
  else {
    std::string op;
    switch (node->value) {
    case ADD: op = "+"; break;
    case SUB: op = "-"; break;
    case MUL: op = "*"; break;
    case DIV: op = "/"; break;
    case MOD: op = "%"; break;
    case POW: op = "^"; break;
    }
    std::cout << " " << op;
    print_tree(node->left.get());
    print_tree(node->right.get());
  }
}

//FIX_ME: Имена функций и методов: lower_case_with_underscores 
// + бессмысленная переменная isLeft
//void printTreePretty(Node* node, int depth, bool isLeft) {
void print_tree_pretty(Node* node, int depth) {
  if (!node) return;

  for (int i = 0; i < depth; i++) {
    std::cout << "    ";
  }

  if (node->value >= 0) {
    std::cout << "|- " << node->value << '\n';
  }
  else {
    std::string op;
    switch (node->value) {
    case ADD: op = "+"; break;
    case SUB: op = "-"; break;
    case MUL: op = "*"; break;
    case DIV: op = "/"; break;
    case MOD: op = "%"; break;
    case POW: op = "^"; break;
    }
    std::cout << "|- [" << op << "]" << '\n';
  }

  if (node->left) {
    print_tree_pretty(node->left.get(), depth + 1);
  }
  if (node->right) {
    print_tree_pretty(node->right.get(), depth + 1);
  }
}

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//bool compareTrees(Node* a, Node* b) {
bool compare_trees(Node* a, Node* b) {
  if (!a && !b) return true;
  if (!a || !b) return false;
  if (a->value != b->value) return false;
  return compare_trees(a->left.get(), b->left.get()) &&
    compare_trees(a->right.get(), b->right.get());
}
