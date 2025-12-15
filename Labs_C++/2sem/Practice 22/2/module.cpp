// Деструктор – освобождает память под дерево
Tree::~Tree() {
  Free();
}

// =================== ФУНКЦИИ РАБОТЫ С ПАМЯТЬЮ ===================
void Tree::freeTree(Node *node) {
  if (!node)
    return;
  freeTree(node->left);
  freeTree(node->right);
  delete node;
}

void Tree::Free() {
  freeTree(root);
  root = nullptr;
}

// Целочисленное возведение в степень
int Tree::ipow(int base, int exp) const {
  int result = 1;
  for (; exp > 0; exp--)
    result *= base;
  return result;
}

// Рекурсивное вычисление выражения по дереву
int Tree::evaluate(Node *node, int x) const {
  if (!node)
    throw std::runtime_error("Пустое дерево");
  switch (node->type) {
    case VALUE:return node->value;
    case VARIABLE:return x;
    case OPERATOR: {
      int leftVal = evaluate(node->left, x);
      int rightVal = evaluate(node->right, x);
      switch (node->op) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/':
          if (rightVal == 0)
            throw std::runtime_error("Деление на ноль");
          return leftVal / rightVal;
        case '%':
          if (rightVal == 0)
            throw std::runtime_error("Деление на ноль (остаток)");
          return leftVal % rightVal;
        case '^': return ipow(leftVal, rightVal);
        default:throw std::runtime_error("Неизвестный оператор");
      }
    }
    default:throw std::runtime_error("Неверный тип узла");
  }
}

int Tree::Evaluate(int x) const {
  return evaluate(root, x);
}

// Проставляет флаг hasVar во всех узлах: если в узле или его поддереве встречалась переменная x
void Tree::markTree(Node *node) {
  if (!node)
    return;
  if (node->type == VALUE)
    node->hasVar = false;
  else if (node->type == VARIABLE)
    node->hasVar = true;
  else if (node->type == OPERATOR) {
    markTree(node->left);
    markTree(node->right);
    node->hasVar = false;
    if (node->left && node->left->hasVar)
      node->hasVar = true;
    if (node->right && node->right->hasVar)
      node->hasVar = true;
  }
}

// Преобразует дерево: во всех поддеревьях, где присутствовала переменная x,
// если после подстановки оба потомка стали константами, вычисляет значение операции,
// освобождает память под дочерними узлами и заменяет узел на значение.
void Tree::transformTree(Node *&node, int x) {
  if (!node)
    return;
  if (node->type == VARIABLE) {
    delete node;
    node = new Node(x);
    node->type = VALUE;
    node->hasVar = false;
    return;
  }
  if (node->type == OPERATOR) {
    transformTree(node->left, x);
    transformTree(node->right, x);
  }
}

void Tree::Transform(int x) {
  transformTree(root, x);
}

// Вывод дерева в многострочном формате
void Tree::printTree(Node *node, int indent, std::ostream &os) const {
  if (!node)
    return;
  printTree(node->right, indent + 8, os);
  os << std::setw(indent) << "" << std::setw(8);
  if (node->type == VALUE)
    os << node->value << "\n";
  else if (node->type == VARIABLE)
    os << "x" << "\n";
  else if (node->type == OPERATOR)
    os << node->op << "\n";
  printTree(node->left, indent + 8, os);
}

void Tree::Print(std::ostream &os) const {
  printTree(root, 0, os);
}

// Пропуск пробельных символов
void Tree::skipSpaces() {
  while (pos < input.size() && isspace(input[pos]))
    pos++;
}

// Primary -> число | 'x' | '(' Expression ')'
Node *Tree::parsePrimary() {
  skipSpaces();
  if (pos >= input.size()) {
    std::cout << ("ОШИБКА");
  }
  if (isdigit(input[pos])) {
    int num = 0;
    while (pos < input.size() && isdigit(input[pos])) {
      num = num * 10 + (input[pos] - '0');
      pos++;
    }
    if (num < 1 || num > 30)
      throw std::runtime_error("Число вне диапазона [1;30]");
    return new Node(num);
  } else if (input[pos] == 'x') {
    pos++;
    return new Node(VARIABLE);
  } else if (input[pos] == '(') {
    pos++; // пропускаем '('
    Node *node = parseExpressionInternal();
    skipSpaces();
    if (pos >= input.size() || input[pos] != ')')
      throw std::runtime_error("Ожидалась ')'");
    pos++; // пропускаем ')'
    return node;
  } else {
    std::cout <<"Неожиданный символ: " + input[pos];
    return 0;
  }
}

// Exponent -> Primary { '^' Primary }*
// Для обеспечения вычисления операторов того же приоритета слева направо
Node *Tree::parseExponent() {
  Node *node = parsePrimary();
  skipSpaces();
  while (pos < input.size() && input[pos] == '^') {
    pos++; // пропускаем '^'
    Node *right = parsePrimary();
    node = new Node('^', node, right);
    skipSpaces();
  }
  return node;
}

// Term -> Exponent { ('*' | '/' | '%') Exponent }*
Node *Tree::parseTerm() {
  Node *node = parseExponent();
  skipSpaces();
  while (pos < input.size() && (input[pos] == '*' || input[pos] == '/' || input[pos] == '%')) {
    char op = input[pos++];
    Node *right = parseExponent();
    node = new Node(op, node, right);
    skipSpaces();
  }
  return node;
}

// Expression -> Term { ('+' | '-') Term }*
Node *Tree::parseExpressionInternal() {
  Node *node = parseTerm();
  skipSpaces();
  while (pos < input.size() && (input[pos] == '+' || input[pos] == '-')) {
    char op = input[pos++];
    Node *right = parseTerm();
    node = new Node(op, node, right);
    skipSpaces();
  }
  return node;
}

// Основная функция парсинга, вызываемая в методах заполнения дерева
Node *Tree::parseExpression(const std::string &expr) {
  input = expr;
  pos = 0;
  Node *node = parseExpressionInternal();
  skipSpaces();
  if (pos != input.size())
    throw std::runtime_error("Лишние символы в выражении");
  return node;
}

//ЗАПОЛНЕНИЕ ДЕРЕВА

// Заполнение дерева вводом с клавиатуры
void Tree::FillFromKeyboard() {
  std::cout << "Введите арифметическое выражение в инфиксной форме.\n"
            << "Используйте числа из диапазона [1;30], операторы +, -, *, /, %, ^ и переменную x.\n";
  std::string line;
  std::getline(std::cin >> std::ws, line);
  Free();
  try {
    root = parseExpression(line);
    markTree(root);
  } catch (std::exception &ex) {
    std::cout << "Ошибка при разборе выражения: " << ex.what() << "\n";
  }
}

// Заполнение дерева из файла FN1
void Tree::FillFromFile() {
  std::ifstream file("C:\\Users\\Public\\Documents\\2sem\\Practice 22\\2\\FN1.txt");
  if (!file.is_open()) {
    std::cout << "Ошибка открытия файла FN1!\n";
    return;
  }
  std::string line;
  std::getline(file, line);
  file.close();
  Free();
  try {
    root = parseExpression(line);
    markTree(root);
  } catch (std::exception &ex) {
    std::cout << "Ошибка при разборе выражения из файла: " << ex.what() << "\n";
  }
}

// Случайная генерация дерева.
std::string Tree::gen(int count) {
  if (count == 1) {
    if (std::rand() % 100 < 50)
      return "x";
    else {
      int num = 1 + std::rand() % 30;
      return std::to_string(num);
    }
  }
  int n = count - 1;
  int possibilities = n / 2;
  int index = std::rand() % possibilities;
  int leftCount = 1 + index * 2;
  int rightCount = n - leftCount;
  std::string leftExpr = gen(leftCount);
  std::string rightExpr = gen(rightCount);

  char ops[] = {'+', '-', '*', '/', '%', '^'};
  char op = ops[std::rand() % 6];

  return "(" + leftExpr + op + rightExpr + ")";
}

std::string Tree::FillRandom(int count) {
  if (count < 1) {
    throw std::invalid_argument("Количество узлов должно быть >= 1");
  }
  if (count != 1 && count % 2 == 0) {
    std::cout << "Внимание: для корректного выражения число узлов должно быть нечётным. "
              << "Используем count = " << count - 1 << ".\n";
    count = count - 1;
  }
  return gen(count);
}