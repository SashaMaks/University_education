#include "Header.h"

PasswordGenerator::PasswordGenerator() {
  rng.seed(std::time(nullptr));
}

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//std::string generatePassword(int length, bool useUpper, bool useDigits, bool useSpecial) {
std::string PasswordGenerator::generate_password(int length, bool useUpper, bool useDigits, bool useSpecial) {
  std::string charset = lowercase;
  if (useUpper) charset += uppercase;
  if (useDigits) charset += digits;
  if (useSpecial) charset += special;

  if (charset.empty()) return "";

  std::uniform_int_distribution<int> dist(0, charset.size() - 1);
  std::string password;

  if (useUpper) password += get_random_char(uppercase);
  if (useDigits) password += get_random_char(digits);
  if (useSpecial) password += get_random_char(special);
  password += get_random_char(lowercase);

  // Заполняем остальные символы
  while (password.length() < length) {
    password += charset[dist(rng)];
  }

  // Перемешиваем пароль
  std::shuffle(password.begin(), password.end(), rng);

  return password;
}

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//char getRandomChar(const std::string& str) {
char PasswordGenerator::get_random_char(const std::string& str) {
  std::uniform_int_distribution<int> dist(0, str.size() - 1);
  return str[dist(rng)];
}

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//std::string generateWeak() {
std::string PasswordGenerator::generate_weak() {
  return generate_password(8, false, true, false);
}

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//std::string generateMedium() {
std::string PasswordGenerator::generate_medium() {
  return generate_password(12, true, true, false);
}

//FIX_ME: Имена функций и методов: lower_case_with_underscores
//std::string generateStrong() {
std::string PasswordGenerator::generate_strong() {
  return generate_password(16, true, true, true);
}