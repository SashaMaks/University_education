#include "module.h"
#include "module.cpp"

int main() {
  SetConsoleOutputCP(CP_UTF8);
  setlocale(LC_ALL, "ru_RU.UTF-8");

  int var = 0, X;
  PNode root = nullptr;

  std::cout << "1 - ручками, 2 - случайно, 3 - файлик\n";

  std::cin >> var;
  switch (var) {
    case 1:
      my_lapki(root);
      break;
    case 2:
      my_rand(root);
      break;
    case 3:
      my_file(root);
      break;
    default: std::cout << "ОШИБКА";
      return 0;
  }
  std::cout << "\nВывод дерева:\n";
  Print(root,0);

  std::cout << "\nВведите значение X для вставки в дерево:\n";
  std::cin >> X;
  AddToTree(root, X);

  std::cout << "\nВывод дерева после вставки эллемента:\n";
  Print(root,0);
  std::cout << "\n";
}