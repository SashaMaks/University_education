#include "module.h"
#include "module.cpp"

int main() {
  SetConsoleOutputCP(CP_UTF8);
  setlocale(LC_ALL, "ru_RU.UTF-8");

  srand(time(0));

  Money i1, i2;

  // Конструктор по умолчанию
  Money m1;
  std::cout << "Конструктор по умолчанию: " << m1 << "\n\n";

  // Параметризованный конструктор
  Money m2(10, 50);
  std::cout << "Параметризованный конструктор (10 руб, 50 коп): " << m2 << "\n\n";

  // Конструктор копирования
  Money m3 = m2;
  std::cout << "Конструктор копирования: " << m3 << "\n\n";

  // Ввод
  int var = 0;
  std::cout << "1 - ручками, 2 - случайно, 3 - файлик\n";
  std::cin >> var;
  switch (var) {
    case 1: {
      my_lapki(i1);
      my_lapki(i2);
      break;
    }
    case 2: {
      my_rand(i1);
      my_rand(i2);
      break;
    }
    case 3: {
      my_file(i1, i2);
      break;
    }
  }

  // Тест унарных операторов
  std::cout << "\nТест унарных операторов:\n";
  Money m_unary = i1;
  std::cout << "Начальное значение: " << m_unary << "\n";
  ++m_unary;
  std::cout << "После префиксного ++: " << m_unary << "\n";
  m_unary++;
  std::cout << "После постфиксного ++: " << m_unary << "\n";
  --m_unary;
  std::cout << "После префиксного --: " << m_unary << "\n";
  m_unary--;
  std::cout << "После постфиксного --: " << m_unary << "\n";

  // Тест бинарного оператора вычитания (Money - Money)
  Money res = i1 - i2;
  std::cout << "\nВычитание " << i1 << " - " << i2 << " = " << res << "\n";

  // Если результат отрицательный, возвращается 0 руб. 0 коп.
  Money a(0, 1);
  res = a - i2;
  std::cout << "Вычитание " << a << " - " << i2 << " = " << res << " (отрицательный результат заменён на 0)" << "\n";

  // Тест бинарного оператора вычитания (Money - unsigned int);
  Money b(15, 20);
  res = i1 - 123452;
  std::cout << "\nВычитание " << i1 << " - 10 руб. = " << res << "\n";
  res = b - 20;
  std::cout << "Вычитание " << b << " - 20 руб. = " << res << " (отрицательный результат заменён на 0)" << "\n";


}
