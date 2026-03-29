//К-ичные числа. Среди чисел в системе счисления с основанием K (2≤K≤10) определить сколько 
//имеется чисел из N (1<N<20, K+N<26) разрядов таких, что в их записи не содержится два и 
//более подряд идущих нулей. Для того, чтобы избежать переполнения, ответ
//представьте в виде вещественного числа.

#include <iostream>
#include <vector>


//FIX_ME: использование пространств имен
//using namespace std;

//FIX_ME: (опционально) использование std::endl медленнее чем '\n'

int main() {
  int K, N;

  setlocale(LC_ALL, "rus");

  //FIX_ME: нет проверки корректности ввода
  std::cout << "Введите основание K (2 <= K <= 10): ";
  std::cin >> K;
  if (std::cin.fail()) {
    std::cout << "Ошибка: нужно ввести целое число!" << std::endl;
    return 1;
  }
  //FIX_ME: нет проверки корректности ввода
  std::cout << "Введите количество разрядов N (1 < N < 20): ";
  std::cin >> N;
  if (std::cin.fail()) {
    std::cout << "Ошибка: нужно ввести целое число!" << std::endl;
    return 1;
  }


  if (K < 2 || K > 10) {
    std::cout << "Некорректные входные данные." << '\n';
    return 1;
  }
  if (K + N >= 26)
  {
    std::cout << "Некорректные входные данные." << '\n';
    return 1;
  }
  if (N <= 1 || N >= 20)
  {
    std::cout << "Некорректные входные данные." << '\n';
    return 1;
  }

  
  // FIX_ME: лишняя переменная tz + переполнение int при больших значениях + неинформативные названия переменных
  //int nz, oz, tz, _tz, _oz, _nz;
  double non_zero_count, zero_count, prev_zero, prev_non_zero;
  non_zero_count = K - 1;
  // FIX_ME: однозначное число не может начинаться с нуля
  // zero_count = 1;
  zero_count = 0; // числа, оканчивающиеся на ноль

  // FIX_ME: лишняя переменная tz
  //tz = 0;
  for (int i = 2; i <= N; i++)
  {
    prev_non_zero = non_zero_count;
    prev_zero = zero_count;
    // FIX_ME: лишняя переменная tz
    //_tz = tz;
    non_zero_count = prev_non_zero * (K - 1) + prev_zero * (K - 1);
    zero_count = prev_non_zero;
    // FIX_ME: лишняя переменная tz
    //tz = _tz * K + _oz;
  }
  double total = non_zero_count + zero_count;
  
  std::cout << "Количество подходящих K-ичных чисел: " << total << '\n';

  // FIX_ME: main является int, но нет return
  return 0;
}

