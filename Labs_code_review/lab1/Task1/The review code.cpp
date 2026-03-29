//Археолог нашел N артефактов.Известны веса(сi) и ценности(di) артефактов.Нужно
//выбрать такое подмножество найденных вещей, чтобы суммарный их вес не превысил Z кг, а их
//общая ценность оказалась максимальной.Известно, что решение единственно.Укажите поряд
//ковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом файле, в
//первой строке указаны N и Z, а во второй строке значения весов(в кг), в третьей - ценность
//находок.Вывести так же суммарный вес и общую ценность результата.

//FIX_ME: исправлена табуляция с tab на 2 пробела

#include "Header.h"

int main()
{
  setlocale(LC_ALL, "ru");

  int n, W;

  //FIX_ME: чтение данных идет вручную, по заданию необхрдимо чтение из файла
    //FIX_ME: нет полной проверки на корректность введенных данных
    /*do {
        std::cout << "Введите объем рюкзака >=0 ";
        std::cin >> W;
    } while (W <= 0);
    //Добавлена функция проверки на корректность ввода

    //FIX_ME: нет полной проверки на корректность введенных данных
    do {
        std::cout << "Введите кол-во артефактов >=0 ";
        std::cin >> n;
    } while (n <= 0);
    //Добавлена функция проверки на корректность ввода

    std::cout << "Поочередно вводите параметры артефактов";

    std::vector<int> profit(n);
    std::vector<int> weight(n);

    //FIX_ME: нет проверки на корректность введенных данных
    for (int i = 0; i < n; i++) {
        std::cout << std::endl<< "Вес " << i + 1 << ": ";
        std::cin >> weight[i];
        std::cout << std::endl << "стоимость " << i + 1 << ": ";
        std::cin >> profit[i];
    }*/
    //Добавлена функция проверки на корректность ввода
  //Код переписан под чтение из файла и добавлена проверка корректности ввода

  std::ifstream file("C:\\Users\\aleks\\source\\repos\\The review code\\The review code\\Input.txt");
  if (!file.is_open()) {
    std::cout << "Ошибка открытия файла!\n";
    return 1;
  }
  if (file.peek() == std::ifstream::traits_type::eof()) {
    std::cout << "Ошибка: Файл пуст!\n";
    return 1;
  }

  if (!ReadPositiveInt(file, n, "Ошибка: Не удалось прочитать N")) return 1;
  if (!ReadPositiveInt(file, W, "Ошибка: Не удалось прочитать Z")) return 1;

  std::vector<int> profits(n);
  std::vector<int> weights(n);

  for (int i = 0; i < n; i++) {
    if (!ReadPositiveInt(file, weights[i], "Ошибка: Не удалось прочитать вес "
      + std::to_string(i + 1) + "-го артефакта")) {
      return 1;
    }
  }

  for (int i = 0; i < n; i++) {
    if (!ReadPositiveInt(file, profits[i], 
      "Ошибка: Не удалось прочитать ценность " + std::to_string(i + 1)
      + "-го артефакта"))
      return 1;
  }
  file.close();

  //FIX_ME: функция больше не нужна
  //insert_sort(weights, profits);

  //FIX_ME: выводится только ценность, а необходим еще и вес
  //std::cout << "Максимальная возможная стоимость вещей, уместимых в рюкзак:
  // " << backpack(W, weights, profits, n) << std::endl;

  std::vector<int> chosen_indices;
  int total_weight = 0;
  int max_value = backpack(W, weights, profits, chosen_indices, total_weight);

  std::cout << "Максимальная ценность: " << max_value << '\n';

  std::cout << "Выбранные артефакты: ";
  for (int i : chosen_indices) std::cout << i << " ";
  std::cout << '\n';

  std::cout << "Суммарный вес: " << total_weight << '\n';
  std::cout << "Суммарная ценность: " << max_value << '\n';

  return 0;
}
