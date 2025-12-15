#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <windows.h>

class Name {
 private:
  std::string surname;
  std::string givenName;
  std::string patronymic;
 public:
  // Конструкторы
  Name();
  Name(const std::string &name);
  Name(const std::string &surname_, const std::string &givenName_);
  Name(const std::string &surname_, const std::string &givenName_, const std::string &patronymic_);

  // Преобразование объекта в строку
  std::string toString() const;
  // Функция print(), принимающая поток вывода
  void print(std::ostream &out) const;
};

class House {
 private:
  int level;
 public:
  House(const int &num);
  void print(std::ostream &out) const;
};

class Worker {
 private:
  std::string name;
  std::string department;
  std::string boss;
 public:
  Worker(const std::string &iname, const std::string &idepartment, const std::string &iboss);
  void print(std::ostream &out) const;
};

class Worker_3 {
 private:
  std::string name;
  std::string department;
  std::string boss;
  static std::map<std::string, std::vector<Worker_3*>> deptEmployees;
 public:
  Worker_3(const std::string &iname, const std::string &idepartment, const std::string &iboss);
  void print(std::ostream &out) const;
  // Вывести список сотрудников отдела, к которому принадлежит данный работник
  void printDepartmentEmployees(std::ostream &out) const;
};

class Name_4 {
 private:
  std::string surname;
  std::string givenName;
  std::string patronymic;
 public:
  // Конструкторы:
  // 1) Создать, указав только личное имя
  Name_4();
  Name_4(const std::string &name);
  // 2) Создать, указав личное имя и фамилию
  Name_4(const std::string &givenName_, const std::string &surname_);
  // 3) Создать, указав личное имя, фамилию и отчество
  Name_4(const std::string &givenName_, const std::string &surname_, const std::string &patronymic_);

  std::string toString() const;
  void print(std::ostream &out) const;
};

class fraction {
 private:
  int numerator;     // числитель
  int denominator;   // знаменатель

  static int gcd(int a, int b);
  void reduce();
 public:
  fraction(int num, int den = 1);
  std::string toString() const;

  // Арифметические операции
  fraction sum(const fraction &other) const;
  fraction sum(int value) const;

  fraction minus(const fraction &other) const;
  fraction minus(int value) const;

  fraction mul(const fraction &other) const;
  fraction mul(int value) const;

  fraction div(const fraction &other) const;
  fraction div(int value) const;
};

void print(const Name &name);
void print(const House &house);
void print(const Worker &worker);
void print(const Worker_3 &worker);
void print(const Name_4 &name);

#endif