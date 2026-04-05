#include "Header.h"

//FIX_ME: исправлена табуляция с tab на 2 пробела

//FIX_ME: нейросеть написала вместо /n "//n"

int main() {
  int choice;

  //FIX_ME: для верного показа русской раскладки
  setlocale(LC_ALL, "ru");

  std::cout << "Выберите уровень сложности пароля:\n";
  std::cout << "1. Лёгкий (8 символов, только строчные буквы и цифры)\n";
  std::cout << "2. Средний (12 символов, строчные, прописные буквы и цифры)\n";
  std::cout << "3. Высокий (16 символов, все категории)\n";
  std::cout << "Ваш выбор: ";
  std::cin >> choice;

  int length;
  //FIX_ME: Имена переменных: lower_case_with_underscores
  //bool useUpper = false, useDigits = false, useSymbols = false;
  bool use_upper = false, use_digits = false, use_symbols = false;

  switch (choice) {
  case 1:
    length = 8;
    use_digits = true;
    break;
  case 2:
    length = 12;
    use_upper = true;
    use_digits = true;
    break;
  case 3:
    length = 16;
    use_upper = true;
    use_digits = true;
    use_symbols = true;
    break;
  default:
    std::cout << "Неверный выбор!\n";
    return 1;
  }

  std::string password = generate_password(length, use_upper, use_digits, 
    use_symbols);
  std::cout << "Ваш новый пароль: " << password << "\n";

  return 0;
}