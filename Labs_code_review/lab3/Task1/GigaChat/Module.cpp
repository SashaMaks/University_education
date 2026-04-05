#include "Header.h"

//FIX_ME: Имена переменных: lower_case_with_underscores
//std::string generatePassword(int length, bool useUpper,
// bool useDigits, bool useSymbols) {
std::string generate_password(int length, bool useUpper,
  bool useDigits, bool useSymbols) {
  //FIX_ME: Имена переменных: lower_case_with_underscores
  //std::string allChars = LOWER;
  std::string all_chars = LOWER;
  if (useUpper) all_chars += UPPER;
  if (useDigits) all_chars += DIGITS;
  if (useSymbols) all_chars += SYMBOLS;

  std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
  std::uniform_int_distribution<> dist(0, all_chars.size() - 1);

  std::string password;
  for (int i = 0; i < length; ++i) {
    password += all_chars[dist(rng)];
  }

  if (useUpper) {
    password[dist(rng) % length] = UPPER[dist(rng) % UPPER.size()];
  }
  if (useDigits) {
    password[dist(rng) % length] = DIGITS[dist(rng) % DIGITS.size()];
  }
  if (useSymbols) {
    password[dist(rng) % length] = SYMBOLS[dist(rng) % SYMBOLS.size()];
  }

  return password;
}