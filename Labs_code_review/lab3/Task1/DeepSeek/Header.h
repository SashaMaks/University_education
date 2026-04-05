#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>

class PasswordGenerator {
private:
  const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
  const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const std::string digits = "0123456789";
  const std::string special = "!@#$%^&*()_+-=[]{}|;:,.<>?";

  std::mt19937 rng;

public:
  PasswordGenerator();

  //FIX_ME: Имена функций и методов: lower_case_with_underscores
  //std::string generatePassword(int length, bool useUpper, bool useDigits, bool useSpecial) {
  std::string generate_password(int length, bool useUpper,
bool useDigits, bool useSpecial);

  //FIX_ME: Имена функций и методов: lower_case_with_underscores
  //char getRandomChar(const std::string& str) {
  char get_random_char(const std::string& str);

  //FIX_ME: Имена функций и методов: lower_case_with_underscores
  //std::string generateWeak() {
  std::string generate_weak();

  //FIX_ME: Имена функций и методов: lower_case_with_underscores
  //std::string generateMedium() {
  std::string generate_medium();

  //FIX_ME: Имена функций и методов: lower_case_with_underscores
  //std::string generateStrong() {
  std::string generate_strong();
};

#endif
