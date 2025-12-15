//функция для ввода руками
void my_lapki(Money &m) {
  std::cout << "Введите денежную сумму (рубли и копейки, например: 12 25): ";
  while (!(std::cin >> m)) {
    std::cout << "Некорректный ввод, повторите попытку: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  std::cout << "\nВы ввели: " << m << "\n";
}

//функция случайного ввода
void my_rand(Money &m) {
  Money m_tmp(std::rand() % 100, std::rand() % 100);
  m = m_tmp;
}

//функция для чтения из файла
void my_file(Money &m1, Money &m2) {
  std::ifstream file("C:\\Users\\User\\CLionProjects\\untitled\\lab25_1");
  int tmp1 = 0, tmp2 = 0;

  file >> tmp1 >> tmp2;
  Money m_tmp1(tmp1, tmp2);
  file >> tmp1 >> tmp2;
  Money m_tmp2(tmp1, tmp2);

  m1 = m_tmp1;
  m2 = m_tmp2;
}

// Конструктор по умолчанию.
Money::Money() : rubles(0), kopeks(0) {}

// Параметризованный конструктор.
Money::Money(unsigned int rub, short int kop) : rubles(rub), kopeks(kop) {
  if (kopeks < 0 || kopeks > 99)
    throw std::invalid_argument("Копейки должны быть в диапазоне от 0 до 99");
}

// Конструктор копирования.
Money::Money(const Money &other) : rubles(other.rubles), kopeks(other.kopeks) {}

// Вспомогательная функция для перевода денежных значений в копейки.
static unsigned int toTotalKopeks(const Money &m) {
  return m.rubles * 100 + m.kopeks;
}

// Перегрузка оператора присваивания.
Money &Money::operator=(const Money &other) {
  if (this != &other) {
    rubles = other.rubles;
    kopeks = other.kopeks;
  }
  return *this;
}

// Перегрузка оператора вычитания при (Money - Money)
Money Money::operator-(const Money &other) {
  unsigned int total1 = toTotalKopeks(*this);
  unsigned int total2 = toTotalKopeks(other);
  if (total1 <= total2) {
    // Если результат отрицательный – возвращаем 0 рублей 0 копеек.
    return Money();
  }
  unsigned int diff = total1 - total2;
  unsigned int newRubles = diff / 100;
  short int newKopeks = diff % 100;
  return Money(newRubles, newKopeks);
}

// Перегрузка оператора вычитания при (Money - Money)
Money Money::operator-(int rub) {
  unsigned int total1 = toTotalKopeks(*this);
  unsigned int total2 = rub;
  if (total1 <= total2) {
    return Money();
  }
  unsigned int diff = total1 - total2;
  unsigned int newRubles = diff / 100;
  short int newKopeks = diff % 100;
  return Money(newRubles, newKopeks);
}

//++
Money& Money::operator++() {
  unsigned int total = toTotalKopeks(*this) + 1;
  rubles = total / 100;
  kopeks = total % 100;
  return *this;
}

Money Money::operator++(int) {
  Money temp(*this);
  ++(*this);
  return temp;
}

//--
Money& Money::operator--() {
  unsigned int total = toTotalKopeks(*this) - 1;
  rubles = total / 100;
  kopeks = total % 100;
  return *this;
}

Money Money::operator--(int) {
  Money temp(*this);
  --(*this);
  return temp;
}

// Перегрузка оператора «<» (для сравнения денежных сумм).
bool Money::operator<(const Money &other) {
  return toTotalKopeks(*this) < toTotalKopeks(other);
}

// Перегрузка оператора «>» (для сравнения денежных сумм).
bool Money::operator>(const Money &other) {
  return toTotalKopeks(*this) > toTotalKopeks(other);
}

// Приведение к unsigned int (неявное)
Money::operator unsigned int() {
  return rubles;
}

// Приведение к double (явное)
Money::operator double() {
  return kopeks / 100.0;
}

// Перегрузка оператора ввода.
std::istream &operator>>(std::istream &in, Money &m) {
  int rub;
  int kop;
  in >> rub >> kop;
  if (rub < 0 || kop < 0 || kop > 99) {
    in.setstate(std::ios::failbit);
    return in;
  }
  m.rubles = rub;
  m.kopeks = static_cast<short int>(kop);
  return in;
}

// Перегрузка оператора вывода.
std::ostream &operator<<(std::ostream &out, const Money &m) {
  out << m.rubles << " руб. " << m.kopeks << " коп.";
  return out;
}
