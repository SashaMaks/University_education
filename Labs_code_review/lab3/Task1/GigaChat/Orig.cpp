//#include <iostream>
//#include <string>
//#include <random>
//#include <ctime>
//#include <algorithm>
//
//// Набор символов для генерации паролей
//const std::string LOWER = "abcdefghijklmnopqrstuvwxyz";
//const std::string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//const std::string DIGITS = "0123456789";
//const std::string SYMBOLS = "!@#$%^&*()-_=+[]{}|;:,.<>?";
//
//// Функция генерации пароля
//std::string generatePassword(int length, bool useUpper, bool useDigits, bool useSymbols) {
//  std::string allChars = LOWER;
//  if (useUpper) allChars += UPPER;
//  if (useDigits) allChars += DIGITS;
//  if (useSymbols) allChars += SYMBOLS;
//
//  // Инициализация генератора случайных чисел
//  std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
//  std::uniform_int_distribution<> dist(0, allChars.size() - 1);
//
//  std::string password;
//  for (int i = 0; i < length; ++i) {
//    password += allChars[dist(rng)];
//  }
//
//  // Гарантируем наличие хотя бы одного символа из каждой выбранной категории
//  if (useUpper) {
//    password[dist(rng) % length] = UPPER[dist(rng) % UPPER.size()];
//  }
//  if (useDigits) {
//    password[dist(rng) % length] = DIGITS[dist(rng) % DIGITS.size()];
//  }
//  if (useSymbols) {
//    password[dist(rng) % length] = SYMBOLS[dist(rng) % SYMBOLS.size()];
//  }
//
//  return password;
//}
//
//int main() {
//  int choice;
//
//  std::cout << "Выберите уровень сложности пароля:\\n";
//  std::cout << "1. Лёгкий (8 символов, только строчные буквы и цифры)\\n";
//  std::cout << "2. Средний (12 символов, строчные, прописные буквы и цифры)\\n";
//  std::cout << "3. Высокий (16 символов, все категории)\\n";
//  std::cout << "Ваш выбор: ";
//  std::cin >> choice;
//
//  int length;
//  bool useUpper = false, useDigits = false, useSymbols = false;
//
//  switch (choice) {
//  case 1:
//    length = 8;
//    useDigits = true;
//    break;
//  case 2:
//    length = 12;
//    useUpper = true;
//    useDigits = true;
//    break;
//  case 3:
//    length = 16;
//    useUpper = true;
//    useDigits = true;
//    useSymbols = true;
//    break;
//  default:
//    std::cout << "Неверный выбор!\\n";
//    return 1;
//  }
//
//  std::string password = generatePassword(length, useUpper, useDigits, useSymbols);
//
//  std::cout << "Ваш новый пароль: " << password << "\\n";
//
//  return 0;
//}
