#include "Hamming.h"
#include <iostream>

//подсчет количества битов четности
int computeParityCount(int m) {
  int r = 0;
  while ((m + r + 1) > (1 << r)) {
    r++;
  }
  return r;
}

//построение кода Хэмминга из изначально данного сообщения
int *buildHammingCode(const std::string &data, int &total, int &r) {
  int m = data.size();
  r = computeParityCount(m);
  total = m + r;

  int *code = new int[total + 1];

  int j = 0;
  for (int i = 1; i <= total; i++) {
    if ((i & (i - 1)) == 0)
      code[i] = 0;
    else {
      code[i] = data[j] - '0';
      j++;
    }
  }
  return code;
}

//вывод кода Хэмминга
void printHammingCode(const int *code, int total) {
  for (int i = 1; i <= total; i++) {
    std::cout << code[i];
  }
  std::cout << "\n";
}
//вычисление контрольных битов
void setParityBits(int *code, int total, int r) {
  for (int i = 0; i < r; i++) {
    int parityPos = (1 << i);
    int parity = 0;
    std::cout << "Шаг 2." << i + 1 << ". Вычисляем контрольный бит на позиции " << parityPos << ":\n";
    for (int j = parityPos; j <= total; j += (parityPos << 1)) {
      for (int k = j; k < j + parityPos && k <= total; k++) {
        parity += code[k];
      }
    }
    if (parity % 2 == 0) code[parityPos] = 0;
    else code[parityPos] = 1;
    std::cout << "\nКонтрольный бит равен " << code[parityPos] << "\n\n";
  }

  std::cout << "Шаг 3. Итоговое закодированное сообщение (код Хэмминга):\n";
  printHammingCode(code, total);
}

//вставка ошибки в код Хэмминга
void insertError(int *code, int total) {
  int errorPos;
  std::cout << "\nПоиск ошибки:\n\n";
  std::cout << "Введите позицию ошибки (от 1 до " << total << ", введите 0 если ошибки нет): ";
  std::cin >> errorPos;

  if (errorPos > 0 && errorPos <= total) {
    code[errorPos] = 1 - code[errorPos];
    std::cout << "\nОшибка внесена в позицию " << errorPos << ". Изменён код:\n";
    printHammingCode(code, total);
  }
}

//обнаружение ошибки в коде Хэмминга
int detectError(const int *code, int total, int r) {
  int syndrome = 0;
  std::cout << "\nШаг 4. Обнаружение ошибки:\n";
  for (int i = 0; i < r; i++) {
    int parityPos = (1 << i);
    int parity = 0;
    std::cout << "Для контрольного бита на позиции " << parityPos << ": ";
    for (int j = parityPos; j <= total; j += (parityPos << 1)) {
      for (int k = j; k < j + parityPos && k <= total; k++) {
        parity += code[k];
      }
    }
    if (parity % 2 == 0) parity = 0;
    else parity = 1;
    std::cout << "вычисленная четность = " << parity << "\n";
    if (parity != 0)
      syndrome += parityPos;
  }
  return syndrome;
}

//исправление ошибки
void correctError(int *code, int errorPos) {
  if (errorPos > 0)
    code[errorPos] = 1 - code[errorPos];
}