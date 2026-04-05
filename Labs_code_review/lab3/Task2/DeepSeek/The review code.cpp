#include "Header.h"

//FIX_ME: использование endl медленее, чем \n
//FIX_ME: исправлена табуляция с tab на 2 пробела

int main() {
  //FIX_ME: для верного отображения русского
  setlocale(LC_ALL, "ru");

  std::ifstream file("a.txt");
  if (!file.is_open()) {
    std::cerr << "Не удалось открыть файл \n";
    return 1;
  }

  auto root = build_tree(file);
  file.close();

  if (!root) {
    std::cerr << "Ошибка построения дерева" << '\n';
    return 1;
  }

  std::cout << "Префиксная запись:";
  print_tree(root.get());
  std::cout << "\n\nСтруктура дерева:\n";
  print_tree_pretty(root.get(), 0);

  //FIX_ME: Имена переменных: lower_case_with_underscores
  //int originalValue = evaluate(root.get());
  int original_value = evaluate(root.get());
  std::cout << "\nЗначение исходного выражения: " << original_value << '\n';

  //FIX_ME: Имена переменных: lower_case_with_underscores
  //auto newRoot = transform(root.get());
  auto new_root = transform(root.get());

  std::cout << "\n========== ПРЕОБРАЗОВАННОЕ ДЕРЕВО ==========\n";
  std::cout << "Префиксная запись:";
  print_tree(new_root.get());
  std::cout << "\n\nСтруктура дерева:\n";
  print_tree_pretty(new_root.get(), 0);

  //FIX_ME: Имена переменных: lower_case_with_underscores
  //int newValue = evaluate(new_root.get());
  int new_value = evaluate(new_root.get());
  std::cout << "\nЗначение преобразованного выражения: " << new_value << '\n';

  std::cout << "\n========== ПРОВЕРКА ==========\n";
  if (original_value == new_value) {
    std::cout << "✓ Значения совпадают! Преобразование корректно.\n";
  }
  else {
    std::cout << "✗ Ошибка! Значения не совпадают.\n";
    std::cout << "  Было: " << original_value << ", стало: " << new_value << '\n';
  }

  std::cout << "\n========== РЕЗУЛЬТАТ ==========\n";
  std::cout << "Указатель на корень результирующего дерева: " << new_root.get() << '\n';

  return 0;
}