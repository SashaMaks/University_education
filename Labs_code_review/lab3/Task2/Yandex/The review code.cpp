#include "Header.h"

//FIX_ME: использование endl медленее, чем \n
//FIX_ME: исправлена табуляция с tab на 2 пробела

int main() {
  std::string filename = "a.txt";

  Node* resultRoot = solve_calc_tree(filename);

  if (resultRoot) {
    std::cout << "Указатель на корень полученного дерева: " << resultRoot << '\n';
    std::cout << "Значение корня: " << resultRoot->data << '\n';

    // Для отладки можно вывести структуру дерева
    std::cout << "\nСтруктура дерева (справа-корень-слева):\n";
    print_tree(resultRoot, 0);
  }
  else {
    std::cout << "Не удалось построить дерево.\n";
  }

  return 0;
}