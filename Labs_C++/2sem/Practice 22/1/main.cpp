#include "module.h"
#include "module.cpp"

int main() {
  SetConsoleOutputCP(CP_UTF8);
  setlocale(LC_ALL, "ru_RU.UTF-8");

  Tree tree;
  int var;
  std::cout << "1 - ручками, 2 - случайно, 3 - файлик\n";
  std::cin >> var;

  switch(var) {
    case 1:
      tree.FillFromKeyboard();
      break;
    case 2: {
      tree.FillRandom();
      break;
    }
    case 3: {
      tree.FillFromFile();
      break;
    }
    default:
      std::cerr << "ОШИБКА\n";
      return 0;
  }

  std::cout << "\nПостроенное дерево:\n";
  tree.PrintSideways();

  // Преобразуем дерево (упрощаем, вычисляя поддеревья, где левое или правое равно 0)
  tree.Simplify();

  std::cout << "\nДерево после преобразования:\n";
  tree.PrintSideways();

  std::cout << "\nУказатель на корень полученного дерева: " << tree.GetRootPointer() << "\n";

  return 0;
}