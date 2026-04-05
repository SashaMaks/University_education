//DeepSeek

#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>

class PasswordGenerator {
private:
  // Наборы символов
  const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
  const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const std::string digits = "0123456789";
  const std::string special = "!@#$%^&*()_+-=[]{}|;:,.<>?";

  std::mt19937 rng;

public:
  PasswordGenerator() {
    rng.seed(std::time(nullptr));
  }

  // FIX_ME: 
  std::string generatePassword(int length, bool useUpper, bool useDigits, bool useSpecial) {
    std::string charset = lowercase;
    if (useUpper) charset += uppercase;
    if (useDigits) charset += digits;
    if (useSpecial) charset += special;

    if (charset.empty()) return "";

    std::uniform_int_distribution<int> dist(0, charset.size() - 1);
    std::string password;

    // Гарантируем хотя бы один символ из каждого выбранного набора
    if (useUpper) password += getRandomChar(uppercase);
    if (useDigits) password += getRandomChar(digits);
    if (useSpecial) password += getRandomChar(special);
    password += getRandomChar(lowercase); // хотя бы одна строчная буква

    // Заполняем остальные символы
    while (password.length() < length) {
      password += charset[dist(rng)];
    }

    // Перемешиваем пароль
    std::shuffle(password.begin(), password.end(), rng);

    return password;
  }

  char getRandomChar(const std::string& str) {
    std::uniform_int_distribution<int> dist(0, str.size() - 1);
    return str[dist(rng)];
  }

  // Генерация пароля для слабого уровня
  std::string generateWeak() {
    return generatePassword(8, false, true, false);
  }

  // Генерация пароля для среднего уровня
  std::string generateMedium() {
    return generatePassword(12, true, true, false);
  }

  //FIX_ME: Имена функций и методов: lower_case_with_underscores
  //std::string generateStrong() {
  std::string generate_strong() {
    return generatePassword(16, true, true, true);
  }
};

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

    std::cout << "\n";

    std::string password;

    switch (choice) {
    case 1:
      password = pg.generateWeak();
      std::cout << "СЛАБЫЙ ПАРОЛЬ (8 символов): " << password << std::endl;
      break;
    case 2:
      password = pg.generateMedium();
      std::cout << "СРЕДНИЙ ПАРОЛЬ (12 символов): " << password << std::endl;
      break;
    case 3:
      password = pg.generate_strong();
      std::cout << "СИЛЬНЫЙ ПАРОЛЬ (16 символов): " << password << std::endl;
      break;
    default:
      std::cout << "Неверный выбор! Пожалуйста, выберите 1, 2 или 3.\n";
      continue;
    }

    std::cout << "\nСгенерировать ещё один пароль? (y/n): ";
    std::cin >> generate_again;
    std::cout << "\n";

  } while (generate_again == 'y' || generate_again == 'Y');

  std::cout << "Спасибо за использование генератора паролей!\n";

  return 0;
}