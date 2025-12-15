#include "module.h"
#include "module.cpp"

int main() {
  SetConsoleOutputCP(CP_UTF8);
  setlocale(LC_ALL, "ru_RU.UTF-8");
  // Инициализация генератора случайных чисел
  srand(time(0));

  std::ofstream fout("C:\\Users\\Public\\Documents\\2sem\\Practice 22\\2\\FN2.txt");
  if (!fout.is_open()) {
    std::cout << "Ошибка открытия файла FN2 для записи.\n";
    return 1;
  }

  Tree tree;
  int var;
  std::cout << "1 - ручками, 2 - случайно, 3 - файлик\n";
  std::cin >> var;

  switch (var) {
    case 1: {
      tree.FillFromKeyboard();
      fout << "Введенное дерево (на боку):\n";
      tree.Print(fout);
      break;
    }
    case 2: {
      int height;
      std::string expression;
      std::cout << "Введите высоту дерева, которое вы хотите построить:\n";
      std::cin >> height;

      expression = tree.FillRandom(height);
      std::cout << "Сгенерированное выражение:\n" << expression << "\n";

      tree.Free();

      tree.root = tree.parseExpression(expression);
      tree.markTree(tree.root);

      fout << "Введенное дерево (на боку):\n";
      tree.Print(fout);
      break;
    }
    case 3: {
      tree.FillFromFile();
      fout << "Введенное дерево (на боку):\n";
      tree.Print(fout);
      break;
    }
    default: {
      std::cout << "ОШИБКА: неверный выбор.\n";
      return 1;
    }
  }

  std::cout << "Введите значение переменной x: ";
  int x;
  std::cin >> x;

  int result = tree.Evaluate(x);
  std::cout << "Результат вычисления выражения: " << result << "\n";

  tree.Transform(x);

  fout << "\n";

  fout << "\n\nПреобразованное дерево (на боку):\n";
  tree.Print(fout);
  fout.close();
}