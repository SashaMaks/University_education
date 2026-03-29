#ifndef Header_h
#define Header_h

#include <fstream>  
#include <iostream>  
#include <vector>  
#include <string>  

extern int n;

void Solve(const std::vector<std::vector<int>>& a, 
  std::vector<std::vector<int>>& b,
  std::vector<std::vector<char>>& put, int size);
void GetPath(const std::vector<std::vector<char>>& put,
  std::string& path, int size);
bool ReadPositiveInt(std::ifstream& file, int& value,
  const std::string& errorMsg);
#endif