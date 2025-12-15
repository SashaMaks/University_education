#include "module.h"
#include "module.cpp"

int main() {
  SetConsoleOutputCP(CP_UTF8);
  setlocale(LC_ALL, "ru_RU.UTF-8");

  int task;
  std::cout << "Введите номер задачи (13,15,2,3,4,5):\n";
  std::cin >> task;
  switch (task) {
    case 13: {
      Name name1("", "Клеопатра", "");
      Name name2("Пушкин", "Александр", "Сергеевич");
      Name name3("Маяковский", "Владимир", "");

      print(name1);
      print(name2);
      print(name3);
      break;
    }
    case 15: {
      House level1(1);
      House level2(5);
      House level3(23);

      print(level1);
      print(level2);
      print(level3);
      break;
    }
    case 2: {
      Worker work1("Петров", "IT", "Козлов");
      Worker work2("Козлов", "IT", "Козлов");
      Worker work3("Сидоров", "IT", "Козлов");

      print(work1);
      print(work2);
      print(work3);
      break;
    }
    case 3: {
      Worker_3 work1("Петров", "IT", "Козлов");
      Worker_3 work2("Козлов", "IT", "Козлов");
      Worker_3 work3("Сидоров", "IT", "Козлов");

      print(work1);
      print(work2);
      print(work3);

      work1.printDepartmentEmployees(std::cout);
      break;
    }
    case 4: { //не вижу разницы с 1.3
      Name_4 name1("Клеопатра");
      Name_4 name2("Александр", "Пушкин", "Сергеевич");
      Name_4 name3("Владимир", "Маяковский");
      Name_4 name4("Христофор", "Бонифатьевич");

      print(name1);
      print(name2);
      print(name3);
      print(name4);
      break;
    }
    case 5: {
      int f1_1,f1_2,f2_1,f2_2,f3_1,f3_2;
      std::cout << "\nВведите числитель 1 дроби:\n";
      std::cin >> f1_1;
      std::cout << "\nВведите знаменатель 1 дроби:\n";
      std::cin >> f1_2;

      std::cout << "\nВведите числитель 2 дроби:\n";
      std::cin >> f2_1;
      std::cout << "\nВведите знаменатель 2 дроби:\n";
      std::cin >> f2_2;

      std::cout << "\nВведите числитель 3 дроби:\n";
      std::cin >> f3_1;
      std::cout << "\nВведите знаменатель 3 дроби:\n";
      std::cin >> f3_2;

      std::cout << "\n\n";

      fraction f1(f1_1,f1_2);
      fraction f2(f2_1,f2_2);
      fraction f3(f3_1,f3_2);

      fraction multResult = f1.mul(f2);
      std::cout << f1.toString() << " * " << f2.toString() << " = " << multResult.toString() << "\n";

      fraction sumResult = f1.sum(f2);
      std::cout << f1.toString() << " + " << f2.toString() << " = " << sumResult.toString() << "\n";

      fraction minusResult = f2.minus(f1);
      std::cout << f2.toString() << " - " << f1.toString() << " = " << minusResult.toString() << "\n";

      fraction divResult = f1.div(f2);
      std::cout << f1.toString() << " / " << f2.toString() << " = " << divResult.toString() << "\n";

      fraction sumIntResult = f1.sum(5);
      std::cout << f1.toString() << " + " << "5" << " = " << sumIntResult.toString() << "\n";

      fraction chainResult = f1.sum(f2).div(f3).minus(5);
      std::cout << "\nРезультат вычисления f1.sum(f2).div(f3).minus(5):\n" << chainResult.toString() << "\n";
      std::cout << "Пошагово:\n";
      std::cout << f1.toString() << " + " << f2.toString() << " = " << f1.sum(f2).toString() << "\n";
      std::cout << f1.sum(f2).toString() << " / " << f3.toString() << " = " << f1.sum(f2).div(f3).toString() << "\n";
      std::cout << f1.sum(f2).div(f3).toString() << " - " << "5" << " = " << chainResult.toString() << "\n";
      break;
    }
  }
}