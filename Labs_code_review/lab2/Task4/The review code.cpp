/* Дан двусвязный линейный список и указатель первый элемент этого
списка. Все элементы списка хранят различные между собой значения. Необходимо
вывести значения элементов списка, которые находятся между наименьшим и
наибольшим элементами списка, в том порядке, в каком они находятся в исходном
списке. Использовать процедуры.

Все динамические структуры данных реализовывать через классы. Не использовать STL.
Для каждой динамической структуры должен быть предусмотрен
стандартный набор методов - добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.*/

#include "Header.h"

//FIX_ME: использование пространств имен
// using namespace std;

//FIX_ME: использование endl медленее, чем \n

// FIX_ME: некорректное название
// struct Uzel {

int main() {
  setlocale(LC_ALL, "Russian");
  int choice;

  // FIX_ME: некорректное название
  // LinkedList Spisok;
  LinkedList my_list;

  // FIX_ME: при написании конструктора, это больше не требуется
  // Spisok.Initsializatsiya();

  // FIX_ME: нет дружественного интерфейса
  /*std::cout << "Введите количество элементов: ";
  int N;
  // FIX_ME: не полная проверка
  // std::cin >> N;
  if (!(std::cin >> N) and N <= 0) {
    std::cout << "Некорректное число N!\n";
    return 1;
  }

  std::cout << "Вводите элементы:\n";
  for (int i = 0; i < N; i++) {
    int Chislo;
    if (!(std::cin >> Chislo)) {
      std::cout << "Ошибка ввода!\n";
      return 1;
    }
    my_list.add(Chislo);
  }

  std::cout << "Список: ";
  my_list.print();
  my_list.print_between_min_max();

  // FIX_ME: при написании деструктора объект сам будет удаляться
  // после завершения работы кода
  //Spisok.Ochistka();
  */

  while (true) {
    std::cout << "\n===== МЕНЮ =====\n";
    std::cout << "1 — Создать список\n";
    std::cout << "2 — Показать список\n";
    std::cout << "3 — Добавить элемент\n";
    std::cout << "4 — Очистить список\n";
    std::cout << "5 — Вывести числа между максимальным и минимальным\n";
    std::cout << "0 — Выход\n";
    std::cout << "Ваш выбор: ";

    if (!(std::cin >> choice)) {
      std::cout << "Некорректный ввод, попробуйте заново\n";
      continue;
    }

    switch (choice) {
      case 1: {
        my_list.clear();
        int N;
        std::cout << "Введите количество элементов в очереди: ";

        if (!(std::cin >> N) || N <= 0) {
          std::cout << "Недопустимое значение.\n";
          std::cin.clear();
          std::cin.ignore(10000, '\n');
          continue;
        }

        std::cout << "Вводите элементы:\n";
        for (int i = 0; i < N; i++) {
          int num;
          if (!(std::cin >> num)) {
            std::cout << "Ошибка ввода!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            break;
          }
          my_list.add(num);
        }
        std::cout << "Список создан\n";
        break;
      }
      case 2: {
        my_list.print();
        break;
      }
      case 3: {
        std::cout << "Введите элемент:\n";
        int num;
        if (!(std::cin >> num)) {
          std::cout << "Ошибка ввода!\n";
          break;
        }
        my_list.add(num);
        std::cout << "Эллемент добавлен\n";
        break;
      }
      case 4: {
        my_list.clear();
        std::cout << "Список очищен\n";
        break;
      }
      case 5: {
        my_list.print_between_min_max();
        break;
      }
      case 0: {
        std::cout << "Выход из программы.\n";
        return 0;
      }
      default: {
        std::cout << "Нет такого пункта. Выберите 0-6.\n";
        break;
      }
    }
  }
  return 0;
}