#include <windows.h>
#include "Hamming.cpp"

int main() {
  SetConsoleOutputCP(CP_UTF8);
  setlocale(LC_ALL, "ru_RU.UTF-8");

  std::string data;
  std::cout << "Введите битовую строку сообщения: ";
  std::cin >> data;

  int r = 0, total = 0;

  int* code = buildHammingCode(data, total, r);

  std::cout << "\nПостроение кода Хэмминга:\n\n";
  std::cout << "Шаг 1. Начальное расположение битов (после вставки контрольных бит):\n";
  std::cout << "Нумерация позиций от 1 до " << total << ":\n";
  for (int i = 1; i <= total; i++)
    std::cout << code[i] << " ";

  setParityBits(code, total, r);

  insertError(code, total);

  int syndrome = detectError(code, total, r);
  if (syndrome == 0)
    std::cout << "\nОшибок не обнаружено.\n";
  else if (syndrome <= total) {
    std::cout << "\nОбнаружена одиночная ошибка в позиции " << syndrome << ". Исправляем ошибку.\n";
    correctError(code, syndrome);
    std::cout << "\nПосле коррекции исправленный код Хэмминга:\n";
    printHammingCode(code, total);
  } else {
    std::cout << "\nОшибка не может быть исправлена.\n";
  }

  delete[] code;

  return 0;
}