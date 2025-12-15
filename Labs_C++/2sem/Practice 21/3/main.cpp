#include "module.h"
#include "module.cpp"

int main() {
  SetConsoleOutputCP(CP_UTF8);
  setlocale(LC_ALL, "ru_RU.UTF-8");
  PNode root = nullptr;
  int var = 0;
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
  PrintTree(root,0);

  PNode maxNode = findMax(root);
  if (!maxNode) {
    std::cout << "Дерево пусто.\n";
    return 0;
  }

  PNode secondMax = findSecondMax(root);
  if (secondMax)
    std::cout << "Второе максимальное значение в дереве: " << secondMax->key << "\n";
  else
    std::cout << "В дереве нет второго максимального значения.\n";
}
