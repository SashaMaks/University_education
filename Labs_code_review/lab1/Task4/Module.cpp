#include "Header.h"

// FIX_ME: нет проверок на правильность ввода
bool hasValidParentheses(const std::string& expr) {
  int balance = 0;
  for (char c : expr) {
    if (c == '(') balance++;
    else if (c == ')') balance--;
    if (balance < 0) return false;
  }
  return balance == 0;
}

bool isValidExpression(const std::string& expr) {
  if (expr.empty()) {
    std::cerr << "Ошибка: пустое выражение" << std::endl;
    return false;
  }

  if (!hasValidParentheses(expr)) {
    std::cerr << "Ошибка: неверная расстановка скобок" << std::endl;
    return false;
  }

  return true;
}


// FIX_ME: код неправильно работает с вложенными выражениями + мы рекурсивно 
// не делим, поэтому правильнее переименовать
/*std::vector<std::string> splitRecursive(const std::string& s, char delimiter, 
size_t start = 0) {
  std::vector<std::string> result;
  size_t pos = s.find(delimiter, start);

  if (pos != std::string::npos) {
    result.push_back(s.substr(start, pos - start));

    std::vector<std::string> remaining = splitRecursive(s, delimiter, pos + 1);

    result.insert(result.end(), remaining.begin(), remaining.end());
  }
  else {
    if (start < s.length()) {
      result.push_back(s.substr(start));
    }
  }

  return result;
}*/
std::vector<std::string> splitArguments(const std::string& s, 
  size_t start = 0) {
  std::vector<std::string> result;
  int bracket_depth = 0;
  size_t last_start = start;

  for (size_t i = start; i < s.length(); ++i) {
    if (s[i] == '(') {
      ++bracket_depth;
    }
    else if (s[i] == ')') {
      --bracket_depth;
    }
    else if (s[i] == ',' && bracket_depth == 0) {
      result.push_back(s.substr(last_start, i - last_start));
      last_start = i + 1;
    }
  }

  if (last_start < s.length()) {
    result.push_back(s.substr(last_start));
  }

  return result;
}

bool evaluateAnd(const std::vector<std::string>& expressions, 
  size_t index = 0) {
  // FIX_ME: отсутствует проверка на пустое выражение в and
  if (expressions.empty()) {
    std::cerr << "Ошибка: And без аргументов\n";
    return false;
  }

  if (index >= expressions.size()) {
    return true;
  }

  if (!evaluate(expressions[index])) {
    return false;
  }

  return evaluateAnd(expressions, index + 1);
}

bool evaluateOr(const std::vector<std::string>& expressions, 
  size_t index = 0) {
  // FIX_ME: отсутствует проверка на пустое выражение в or
  if (expressions.empty()) {
    std::cerr << "Ошибка: Or без аргументов\n";
    return false;
  }

  if (index >= expressions.size()) {
    return false;
  }

  if (evaluate(expressions[index])) {
    return true;
  }

  return evaluateOr(expressions, index + 1);
}

bool evaluate(const std::string& expr) {
  // FIX_ME: добавлена проверка на валидность выражения
  if (!isValidExpression(expr)) {
    return false;
  }
  if (expr == "T") {
    return true;
  }
  else if (expr == "F") {
    return false;
  }
  else if (expr.substr(0, 3) == "And") {
    // FIX_ME: проверка, что выражение в and не короче чем надо
    if (expr.length() <= 5) {
      std::cerr << "Ошибка: слишком короткое выражение And\n";
      return false;
    }

    // FIX_ME: правильно убираем "And(" и ")"
    // std::string params = expr.substr(4, expr.size() - 5);
    std::string params = expr.substr(4, expr.length() - 5);
    // FIX_ME: параметры принимаемой функции поменялись
    // std::vector<std::string> sub_exprs = splitRecursive(params, ',');

    // FIX_ME: проверка что and не пустой
    if (params.empty()) {
      std::cerr << "Ошибка: And без параметров\n";
      return false;
    }
    std::vector<std::string> sub_exprs = splitArguments(params);

    // FIX_ME: проверка что and не пустой
    if (params.empty()) {
      std::cerr << "Ошибка: And без параметров\n";
      return false;
    }
    return evaluateAnd(sub_exprs);
  }
  else if (expr.substr(0, 2) == "Or") {
    // FIX_ME: проверка, что выражение в or не короче чем надо
    if (expr.length() <= 4) {
      std::cerr << "Ошибка: слишком короткое выражение Or\n";
      return false;
    }
    // FIX_ME: правильно убираем "Or(" и ")"
    //std::string params = expr.substr(3, expr.size() - 4);
    std::string params = expr.substr(3, expr.length() - 4);
    
    // FIX_ME: проверка что or не пустой
    if (params.empty()) {
      std::cerr << "Ошибка: Or без параметров\n";
      return false;
    }
    // FIX_ME: параметры принимаемой функции поменялись
    // std::vector<std::string> sub_exprs = splitRecursive(params, ',');
    std::vector<std::string> sub_exprs = splitArguments(params);

    // FIX_ME: проверка что or не пустой
    if (params.empty()) {
      std::cerr << "Ошибка: Or без параметров\n";
      return false;
    }
    return evaluateOr(sub_exprs);
  }

  // FIX_ME: неизвестный оператор
  std::cerr << "Ошибка: неизвестный оператор в выражении: " << expr << '\n';
  return false;
}
