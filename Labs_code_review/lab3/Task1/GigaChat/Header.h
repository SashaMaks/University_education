#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>

const std::string LOWER = "abcdefghijklmnopqrstuvwxyz";
const std::string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string DIGITS = "0123456789";
const std::string SYMBOLS = "!@#$%^&*()-_=+[]{}|;:,.<>?";

//FIX_ME: Имена переменных: lower_case_with_underscores
//std::string generatePassword(int length, bool useUpper,
// bool useDigits, bool useSymbols);
std::string generate_password(int length, bool useUpper,
	bool useDigits, bool useSymbols);

#endif