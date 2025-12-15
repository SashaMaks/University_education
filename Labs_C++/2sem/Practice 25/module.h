#ifndef UNTITLED__MODULE_H_
#define UNTITLED__MODULE_H_

#include <iostream>
#include <windows.h>
#include <limits>
#include <ctime>
#include <fstream>

class Money {
 public:
  unsigned int rubles;
  short int kopeks;

  Money();
  Money(unsigned int rub, short int kop);
  Money(const Money &other);

  Money& operator=(const Money &other);
  Money operator-(const Money &other);
  Money operator-(int rub);

  Money& operator++(); //++m
  Money operator++(int); //m++

  Money& operator--(); //--m
  Money operator--(int); //m--

  bool operator<(const Money &other);
  bool operator>(const Money &other);

  operator unsigned int();
  explicit operator double();

  friend std::istream& operator>>(std::istream &in, Money &m);
  friend std::ostream& operator<<(std::ostream &out, const Money &m);
};

void my_lapki(Money &m);
void my_rand(Money &m);
void my_file(Money &m1, Money &m2);

#endif
