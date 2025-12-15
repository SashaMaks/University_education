// Конструктор
Tree::Tree() : root(nullptr) {
  std::srand(static_cast<unsigned>(std::time(0)));
}

// Деструктор
Tree::~Tree() {
  Free(root);
  root = nullptr;
}

// Рекурсивное освобождение узлов
void Tree::Free(Node *node) {
  if (!node) return;
  Free(node->left);
  Free(node->right);
  delete node;
}

// Рекурсивное построение дерева по префиксному выражению
Tree::Node *Tree::BuildExpression(std::istream &in) {
  std::string token;
  if (!(in >> token))
    return nullptr;

  int val;
  if (token.size() == 1 && (token == "+" || token == "-" || token == "*" ||
      token == "/" || token == "%" || token == "^")) {
    if (token == "+")
      val = -1;
    else if (token == "-")
      val = -2;
    else if (token == "*")
      val = -3;
    else if (token == "/")
      val = -4;
    else if (token == "%")
      val = -5;
    else if (token == "^")
      val = -6;
  } else {
    val = std::stoi(token);
  }

  Node *node = new Node(val);
  if (val < 0) {  // если значение отрицательное, то это оператор, читаем два поддерева
    node->left = BuildExpression(in);
    node->right = BuildExpression(in);
  }
  return node;
}

// Заполнение дерева вводом с клавиатуры
void Tree::FillFromKeyboard() {
  std::cout << "Введите арифметическое выражение в префиксной форме (числа разделены пробелами).\n";
  std::cout << "Используйте символы для операторов: '+' '-' '*' '/' '%' '^'.\n";
  std::string line;
  std::getline(std::cin >> std::ws, line); //читаем строку с пробелами
  std::istringstream iss(line); // читаем строку как поток
  root = BuildExpression(iss);
}

// Заполнение дерева из файла
void Tree::FillFromFile() {
  std::ifstream file("C:\\Users\\Public\\Documents\\2sem\\Practice 22\\1\\filename.txt");
  if (!file.is_open()) {
    std::cout << "Ошибка открытия файла!\n";
    return;
  }
  Free(root);
  root = BuildExpression(file);
  file.close();
}

// Генерация случайного дерева. Здесь для упрощения мы будем генерировать
void Tree::FillRandom() {
  int count;
  std::cout << "Введите количество узлов для случайного дерева: ";
  std::cin >> count;

  std::function<Node * (int & )> gen = [&](int &n) -> Node * {
    if (n <= 0)
      return nullptr;
    if (n == 1 || (std::rand() % 100) < 40) {
      n--;
      int operand = std::rand() % 10;
      return new Node(operand);
    } else {
      n--;
      int ops[6] = {-1, -2, -3, -4, -5, -6};
      int op = ops[std::rand() % 6];
      Node *node = new Node(op);
      node->left = gen(n);
      node->right = gen(n);
      return node;
    }
  };
  Free(root);
  int total = count;
  root = gen(total);
}

// Вывод дерева в виде "бокового" дерева
void Tree::PrintSideways() {
  PrintSideways(root, 0);
  std::cout << std::endl;
}

void Tree::PrintSideways(Node *node, int indent) {
  if (!node)
    return;
  PrintSideways(node->right, indent + 4);

  if (indent)
    std::cout << std::string(indent, ' ');

  if (node->value < 0) {
    char op;
    switch (node->value) {
      case -1: op = '+';
        break;
      case -2: op = '-';
        break;
      case -3: op = '*';
        break;
      case -4: op = '/';
        break;
      case -5: op = '%';
        break;
      case -6: op = '^';
        break;
      default: op = '?';
        break;
    }
    std::cout << op << "\n";
  } else {
    std::cout << node->value << "\n";
  }

  PrintSideways(node->left, indent + 4);
}

// Рекурсивное вычисление значения поддерева.
int Tree::Evaluate(Node *node) {
  if (!node)
    return 0;
  if (!node->left && !node->right)
    return node->value;

  int L = Evaluate(node->left);
  int R = Evaluate(node->right);

  switch (node->value) {
    case -1: return L + R;
    case -2: return L - R;
    case -3: return L * R;
    case -4: return (R != 0 ? L / R : 0);
    case -5: return (R != 0 ? L % R : 0);
    case -6: return static_cast<int>(pow(L, R));
    default: return node->value;
  }
}

// Рекурсивное упрощение дерева
Tree::Node *Tree::Simplify(Node *node, bool isSubtree) {
  if (!node)
    return nullptr;

  if (!node->left && !node->right)
    return node;

  node->left = Simplify(node->left, true);
  node->right = Simplify(node->right, true);

  int result = Evaluate(node);
  if (isSubtree && node->value < 0 &&
      node->left && node->right &&
      !node->left->left && !node->left->right &&
      !node->right->left && !node->right->right &&
      result == 0) {
    Free(node);
    return new Node(result);
  }
  return node;
}

void Tree::Simplify() {
  root = Simplify(root, false);
}

// Возвращает указатель на корень дерева
void *Tree::GetRootPointer() {
  return static_cast<void *>(root);
}