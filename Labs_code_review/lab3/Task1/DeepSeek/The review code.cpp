//FIX_ME: использование endl медленее, чем \n
//FIX_ME: исправлена табуляция с tab на 2 пробела

#include "Header.h"

int main() {
  //FIX_ME: для верного показа русской раскладки
  setlocale(LC_ALL, "ru");

  PasswordGenerator pg;
  int choice;
  //FIX_ME: Имена переменных: lower_case_with_underscores
  //char generateAgain;
  char generate_again;

  std::cout << "=====================================\n";
  std::cout << "   ГЕНЕРАТОР НАДЁЖНЫХ ПАРОЛЕЙ\n";
  std::cout << "=====================================\n\n";

  do {
    std::cout << "Выберите уровень сложности:\n\n";
    std::cout << "1. СЛАБЫЙ (8 символов)\n";
    std::cout << "   - только строчные буквы и цифры\n";
    std::cout << "   - подходит для неважных аккаунтов\n\n";

    std::cout << "2. СРЕДНИЙ (12 символов)\n";
    std::cout << "   - строчные и прописные буквы + цифры\n";
    std::cout << "   - хороший баланс безопасности\n\n";

    std::cout << "3. СИЛЬНЫЙ (16 символов)\n";
    std::cout << "   - строчные и прописные буквы + цифры + спецсимволы\n";
    std::cout << "   - максимальная защита\n\n";

    std::cout << "Ваш выбор (1-3): ";
    std::cin >> choice;

    std::cout << '\n';

    std::string password;

    switch (choice) {
    case 1:
      password = pg.generate_weak();
      std::cout << "СЛАБЫЙ ПАРОЛЬ (8 символов): " << password << '\n';
      break;
    case 2:
      password = pg.generate_medium();
      std::cout << "СРЕДНИЙ ПАРОЛЬ (12 символов): " << password << '\n';
      break;
    case 3:
      password = pg.generate_strong();
      std::cout << "СИЛЬНЫЙ ПАРОЛЬ (16 символов): " << password << '\n';
      break;
    default:
      std::cout << "Неверный выбор! Пожалуйста, выберите 1, 2 или 3.\n";
      continue;
    }

    std::cout << "\nСгенерировать ещё один пароль? (y/n): ";
    std::cin >> generate_again;
    std::cout << '\n';

  } while (generate_again == 'y' || generate_again == 'Y');

  std::cout << "Спасибо за использование генератора паролей!\n";

  return 0;
}
