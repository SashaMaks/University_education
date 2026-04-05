#include "Header.h"

//FIX_ME: исправлена табуляция с tab на 2 пробела

//FIX_ME: использование endl медленее, чем \n

int main() {
  //FIX_ME: для верного отображения русского
  setlocale(LC_ALL, "ru");

  const std::string level1 = "abcdefghijklmnopqrstuvwxyz";
  const std::string level2 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV"
    "WXYZ0123456789";
  const std::string level3 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV"
    "WXYZ0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";

  int choice;
  std::cout << "Выберите уровень сложности пароля:\n";
  std::cout << "1 - Низкий (8 символов, только строчные буквы)\n";
  std::cout << "2 - Средний (12 символов, буквы и цифры)\n";
  std::cout << "3 - Высокий (16 символов, все символы)\n";
  std::cout << "Ваш выбор: ";
  std::cin >> choice;

  std::string password;
  switch (choice) {
  case 1:
    password = generate_password(8, level1);
    break;
  case 2:
    password = generate_password(12, level2);
    break;
  case 3:
    password = generate_password(16, level3);
    break;
  default:
    std::cout << "Неверный выбор! Используется уровень 2.\n";
    password = generate_password(12, level2);
    break;
  }

  std::cout << "Сгенерированный пароль: " << password << '\n';
  return 0;
}
