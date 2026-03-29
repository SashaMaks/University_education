#include "Header.h"

// FIX_ME: имена параметров неинформативные, используетс€ глобальный n
// void Solve(vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<char>>& put)
void Solve(const std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& b, std::vector<std::vector<char>>& put, int size)
{
  // FIX_ME: переменна€ max не инициализирована, плохое им€ (конфликт с функцией max)
  // int max;
  int bestSum;

  b[size - 1][size - 1] = a[size - 1][size - 1];

  for (int i = size - 2; i >= 0; i--)
  {
    b[i][size - 1] = b[i + 1][size - 1] + a[i][size - 1];
    put[i][size - 1] = 'U';
  }

  for (int j = size - 2; j >= 0; j--)
  {
    b[size - 1][j] = b[size - 1][j + 1] + a[size - 1][j];
    put[size - 1][j] = 'L';
  }

  for (int i = size - 2; i >= 0; i--)
  {
    for (int j = size - 2; j >= 0; j--)
    {
      // FIX_ME: при равенстве нужно выбирать любое направление, но условие должно быть >=
      // if (b[i + 1][j] > b[i][j + 1])
      if (b[i + 1][j] >= b[i][j + 1])
      {
        bestSum = b[i + 1][j];
        put[i][j] = 'U';
      }
      else
      {
        bestSum = b[i][j + 1];
        put[i][j] = 'L';
      }
      b[i][j] = bestSum + a[i][j];
    }
  }
}

// FIX_ME: непон€тное им€ функции и переменной
// void p(vector<vector<char>>& put, string& put1)
void GetPath(const std::vector<std::vector<char>>& put, std::string& path, int size)
{
  int i = 0;
  int j = 0;

  while (i < size - 1 || j < size - 1)
  {
    if (put[i][j] == 'U')
    {
      // FIX_ME: добавл€ютс€ пробелы, которых не должно быть по условию
      // put1 = put1 + "U ";
      path += 'U';
      i++;
    }
    else if (put[i][j] == 'L')
    {
      // FIX_ME: добавл€ютс€ пробелы, которых не должно быть по условию
      // put1 = put1 + "L ";
      path += 'L';
      j++;
    }
  }
  std::reverse(path.begin(), path.end());
}

// FIX_ME: нет функции дл€ проверки правильности ввода
bool ReadPositiveInt(std::ifstream& file, int& value,
  const std::string& errorMsg) {
  if (!(file >> value)) {
    std::cout << errorMsg << "\n";
    return false;
  }
  if (value <= 0) {
    std::cout << "ќшибка: число не положительное!\n";
    return false;
  }
  return true;
}