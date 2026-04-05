#include "Header.h"

std::string generatePassword(int length, const std::string& charset) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, charset.size() - 1);

  std::string password;
  for (int i = 0; i < length; ++i) {
    password += charset[dis(gen)];
  }
  return password;
}