#include "module.h"

// Реализация класса Name
Name::Name() : surname(""), givenName(""), patronymic("") {}

Name::Name(const std::string &name) : surname(""), givenName(name), patronymic("") {}

Name::Name(const std::string &surname_, const std::string &givenName_)
    : surname(surname_), givenName(givenName_), patronymic("") {}

Name::Name(const std::string &surname_, const std::string &givenName_, const std::string &patronymic_)
    : surname(surname_), givenName(givenName_), patronymic(patronymic_) {}

std::string Name::toString() const {
  std::string result;
  if (!surname.empty())
    result += surname;
  if (!givenName.empty()) {
    if (!result.empty())
      result += " ";
    result += givenName;
  }
  if (!patronymic.empty()) {
    if (!result.empty())
      result += " ";
    result += patronymic;
  }
  return result;
}

void Name::print(std::ostream &out) const {
  out << toString() << "\n";
}

// Реализация класса House
House::House(const int &num) : level(num) {}

void House::print(std::ostream &out) const {
  if (level <= 0) {
    out << "В доме нет этажей\n";
  } else if (level % 10 == 1 && level % 100 != 11) {
    out << "Дом с " << level << " этажом\n";
  } else {
    out << "Дом с " << level << " этажами\n";
  }
}

// Реализация класса Worker
Worker::Worker(const std::string &iname, const std::string &idepartment, const std::string &iboss)
    : name(iname), department(idepartment), boss(iboss) {}

void Worker::print(std::ostream &out) const {
  if (boss == name) {
    out << name << " начальник отдела " << department << "\n";
  } else {
    out << name << " работает в отделе " << department << ", начальник которого " << boss << "\n";
  }
}

// Реализация класса Worker_3
std::map<std::string, std::vector<Worker_3*>> Worker_3::deptEmployees;

Worker_3::Worker_3(const std::string &iname, const std::string &idepartment, const std::string &iboss)
    : name(iname), department(idepartment), boss(iboss) {
  deptEmployees[idepartment].push_back(this);
}

void Worker_3::print(std::ostream &out) const {
  if (boss == name) {
    out << name << " начальник отдела " << department << "\n";
  } else {
    out << name << " работает в отделе " << department << ", начальник которого " << boss << "\n";
  }
}

void Worker_3::printDepartmentEmployees(std::ostream &out) const {
  out << "\nСотрудники отдела " << department << ":\n";
  const std::vector<Worker_3*> &workers = deptEmployees.at(department);
  for (const Worker_3* w : workers) {
    out << " - " << w->name << "\n";
  }
}

// Реализация класса Name_4
Name_4::Name_4() : surname(""), givenName(""), patronymic("") {}

Name_4::Name_4(const std::string &name) : surname(""), givenName(name), patronymic("") {}

Name_4::Name_4(const std::string &givenName_, const std::string &surname_)
    : surname(surname_), givenName(givenName_), patronymic("") {}

Name_4::Name_4(const std::string &givenName_, const std::string &surname_, const std::string &patronymic_)
    : surname(surname_), givenName(givenName_), patronymic(patronymic_) {}

std::string Name_4::toString() const {
  std::string result;
  if (!surname.empty())
    result += surname;
  if (!givenName.empty()) {
    if (!result.empty())
      result += " ";
    result += givenName;
  }
  if (!patronymic.empty()) {
    if (!result.empty())
      result += " ";
    result += patronymic;
  }
  return result;
}

void Name_4::print(std::ostream &out) const {
  out << toString() << "\n";
}

// Реализация класса fraction
int fraction::gcd(int a, int b) {
  a = std::abs(a);
  b = std::abs(b);
  while(b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

void fraction::reduce() {
  int g = gcd(numerator, denominator);
  if(g != 0) {
    numerator /= g;
    denominator /= g;
  }
  if(denominator < 0) {
    numerator = -numerator;
    denominator = -denominator;
  }
}

fraction::fraction(int num, int den) : numerator(num), denominator(den) {
  if (den == 0) {
    throw std::invalid_argument("Знаменатель не может быть равен 0");
  }
  reduce();
}

std::string fraction::toString() const {
  std::stringstream ss;
  ss << numerator << "/" << denominator;
  return ss.str();
}

fraction fraction::sum(const fraction &other) const {
  int num = numerator * other.denominator + other.numerator * denominator;
  int den = denominator * other.denominator;
  return fraction(num, den);
}

fraction fraction::sum(int value) const {
  return sum(fraction(value));
}

fraction fraction::minus(const fraction &other) const {
  int num = numerator * other.denominator - other.numerator * denominator;
  int den = denominator * other.denominator;
  return fraction(num, den);
}

fraction fraction::minus(int value) const {
  return minus(fraction(value));
}

fraction fraction::mul(const fraction &other) const {
  int num = numerator * other.numerator;
  int den = denominator * other.denominator;
  return fraction(num, den);
}

fraction fraction::mul(int value) const {
  return mul(fraction(value));
}

fraction fraction::div(const fraction &other) const {
  if(other.numerator == 0) {
    throw std::invalid_argument("Деление на ноль недопустимо");
  }
  int num = numerator * other.denominator;
  int den = denominator * other.numerator;
  return fraction(num, den);
}

fraction fraction::div(int value) const {
  if(value == 0) {
    throw std::invalid_argument("Деление на ноль недопустимо");
  }
  return div(fraction(value));
}

// Реализация функций print

void print(const Name &name) {
  name.print(std::cout);
}

void print(const House &house) {
  house.print(std::cout);
}

void print(const Worker &worker) {
  worker.print(std::cout);
}

void print(const Worker_3 &worker) {
  worker.print(std::cout);
}

void print(const Name_4 &name) {
  name.print(std::cout);
}