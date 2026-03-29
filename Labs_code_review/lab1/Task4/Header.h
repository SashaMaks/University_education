#ifndef Header_h
#define Header_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <sstream>

bool hasValidParentheses(const std::string& expr);
bool isValidExpression(const std::string& expr);
bool evaluate(const std::string& expr);
std::vector<std::string> splitArguments(const std::string& s, size_t start);
bool evaluateAnd(const std::vector<std::string>& expressions, size_t index);
bool evaluateOr(const std::vector<std::string>& expressions, size_t index);

#endif