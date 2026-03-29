#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int backpack(int capacity, const std::vector<int>& weights,
  const std::vector<int>& profit, std::vector<int>& chosen_indices,
  int& total_weight);

bool ReadPositiveInt(std::ifstream& file, int& value,
  const std::string& errorMsg);

#endif