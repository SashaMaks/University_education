#include "module.h"
#include "module.cpp"

int main() {
  SetConsoleOutputCP(CP_UTF8);

  std::string text;
  int key, var = 0;

  std::cout << "Что вы хотите сделать? (1-шифровка, 2-дешифровка):\n";
  std::cin >> var;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  switch (var) {
    case 1: {
      std::cout << "Введите текст:\n";
      std::getline(std::cin, text);

      std::cout << "Введите ключ (целое число):\n";
      std::cin >> key;

      std::string encrypted = CaesarCipher::encrypt(text, key);
      std::cout << "\nЗашифрованный текст: " << encrypted << "\n";
      break;
    }
    case 2: {
      std::cout << "Введите текст:\n";
      std::getline(std::cin, text);

      std::cout << "Введите ключ (целое число):\n";
      std::cin >> key;

      std::string decrypted = CaesarCipher::decrypt(text, key);

      std::cout << "Расшифрованный текст: " << decrypted << "\n";
      break;
    }
  }
}