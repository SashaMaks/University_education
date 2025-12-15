
// Добавление нового одночлена в конец списка
void append(PNode *&root, int coeff, int exp) {
  PNode *newNode = new PNode(coeff, exp);
  if (!root) {
    root = newNode;
  } else {
    PNode *temp = root;
    while (temp->next != nullptr)
      temp = temp->next;
    temp->next = newNode;
  }
}

// Функция парсинга строки вида "52y^10 - 3y^8 + y"
PNode *parse(const std::string &str) {
  PNode* root = nullptr;
  size_t i = 0;
  size_t len = str.length();

  while (i < len) {
    while (i < len && std::isspace(str[i]))
      i++;

    if (i >= len)
      break;

    // Определяем знак одночлена
    int sign = 1;
    if (str[i] == '+') {
      sign = 1;
      i++;
    } else if (str[i] == '-') {
      sign = -1;
      i++;
    }
    // Пропускаем пробелы после знака
    while (i < len && std::isspace(str[i]))
      i++;

    // Читаем числовой коэффициент, если он есть
    int coeff = 0;
    bool coeffSpecified = false;
    size_t startIndex = i;
    while (i < len && std::isdigit(str[i])) {
      coeffSpecified = true;
      coeff = coeff * 10 + (str[i] - '0');
      i++;
    }

    if (!coeffSpecified) {
      if (i < len && std::isalpha(str[i])) {
        coeff = 1;
      } else {
        throw PolynomialParseException("Ошибка: ожидается коэффициент или переменная, позиция " + std::to_string(startIndex));
      }
    }
    coeff *= sign;

    // Обработка переменной и степени
    int exp = 0;
    if (i < len && std::isalpha(str[i])) {
      char varLetter = str[i];
      i++;
      exp = 1;
      if (i < len && str[i] == '^') {
        i++;
        if (i >= len || !std::isdigit(str[i])) {
          throw PolynomialParseException("Ошибка: после '^' ожидается число, позиция " + std::to_string(i));
        }
        exp = 0;
        while (i < len && std::isdigit(str[i])) {
          exp = exp * 10 + (str[i] - '0');
          i++;
        }
      }
    } else {
      exp = 0;
    }
    append(root, coeff, exp);

    while (i < len && std::isspace(str[i]))
      i++;
    if (i < len && str[i] != '+' && str[i] != '-') {
      throw PolynomialParseException("Ошибка: недопустимый символ '" + std::string(1, str[i]) + "' на позиции " + std::to_string(i));
    }
  }
  return root;
}

// Сортировка многочлена по убыванию степеней методом вставки
PNode *sort(PNode *root) {
  if (!root || !root->next)
    return root;

  PNode *sorted = nullptr;
  PNode *current = root;
  while (current != nullptr) {
    PNode *next = current->next;
    if (sorted == nullptr || current->exp > sorted->exp) {
      current->next = sorted;
      sorted = current;
    } else {
      PNode *temp = sorted;
      while (temp->next != nullptr && temp->next->exp >= current->exp)
        temp = temp->next;
      current->next = temp->next;
      temp->next = current;
    }
    current = next;
  }
  return sorted;
}

// Объединение одночленов с одинаковыми степенями (функция предполагает, что список отсортирован)
PNode *combineLikePNodes(PNode *root) {
  if (!root)
    return nullptr;
  PNode *current = root;
  while (current && current->next) {
    if (current->exp == current->next->exp) {
      current->coeff += current->next->coeff;
      PNode *temp = current->next;
      current->next = temp->next;
      delete temp;
    } else {
      current = current->next;
    }
  }
  return root;
}

// Преобразование списка многочлена в строку
std::string polynomialToString(PNode *root) {
  std::string result;
  bool firstPNode = true;
  PNode *current = root;
  while (current != nullptr) {
    if (current->coeff != 0) {
      std::string PNodeStr;
      if (firstPNode) {
        // Для первого одночлена выводим знак только если коэффициент отрицательный
        if (current->coeff < 0)
          PNodeStr += "-";
      } else {
        // Для последующих одночленов выводим " + " или " - " в зависимости от знака
        PNodeStr += (current->coeff < 0) ? " - " : " + ";
      }
      int absCoeff = std::abs(current->coeff);
      // Для свободного члена (exp == 0) выводим только число
      if (current->exp == 0) {
        PNodeStr += std::to_string(absCoeff);
      } else {
        // Если коэффициент равен 1 (или -1) не выводим число
        if (absCoeff != 1)
          PNodeStr += std::to_string(absCoeff);
        PNodeStr += "y";
        if (current->exp != 1)
          PNodeStr += "^" + std::to_string(current->exp);
      }
      result += PNodeStr;
      firstPNode = false;
    }
    current = current->next;
  }
  if (firstPNode)
    result = "0"; // если ни одного одночлена не было добавлено
  return result;
}

// Освобождение памяти, выделенной под список
void freePolynomial(PNode *root) {
  while (root) {
    PNode *temp = root;
    root = root->next;
    delete temp;
  }
}
