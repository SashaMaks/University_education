import java.util.*;
import java.util.Scanner;

class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        boolean go = true;
        while (go) {
            System.out.println("Выберете задание для показа задач (1.1 - 1.9, 2.1 - 2.9, 3.1 - 3.9, 4.1 - 4.9 (вторые номера нечетные) | 0 - для выхода):");
            String choice = scanner.nextLine();
            switch (choice) {
                case "1.1":
                    System.out.print("Введите число: \n");
                    double input11 = scanner.nextDouble();

                    System.out.print("Дробная часть числа: \n");
                    System.out.print(Lab1.fraction(input11));
                    break;
                case "1.3":
                    System.out.print("Введите один из символов (0 1 2 3 4 5 6 7 8 9): \n");
                    char input13 = scanner.next().charAt(0);

                    System.out.print("Число преобразованное из char в int: \n");
                    System.out.print(Lab1.charToNum(input13));
                    break;
                case "1.5":
                    System.out.print("Введите число: \n");
                    int input15 = scanner.nextInt();

                    System.out.print("Двухзначное ли число? \n");
                    System.out.print(Lab1.is2Digits(input15));
                    break;
                case "1.7":
                    System.out.print("Введите первую грань: \n");
                    int a_Range17 = scanner.nextInt();
                    System.out.print("Введите вторую грань: \n");
                    int b_Range17 = scanner.nextInt();
                    System.out.print("Введите число: \n");
                    int num17 = scanner.nextInt();

                    System.out.print("Находится ли число в диапазоне? \n");
                    System.out.print(Lab1.isInRange(a_Range17, b_Range17, num17));
                    break;
                case "1.9":
                    System.out.print("Введите первое число: \n");
                    int one19 = scanner.nextInt();
                    System.out.print("Введите второе число: \n");
                    int two19 = scanner.nextInt();
                    System.out.print("Введите третье число: \n");
                    int three19 = scanner.nextInt();

                    System.out.print("Равны ли все три числа? \n");
                    System.out.print(Lab1.isEqual(one19, two19, three19));
                    break;
                case "2.1":
                    System.out.print("Введите число: \n");
                    int input21 = scanner.nextInt();

                    System.out.print("Модуль числа " + input21 + ": \n");
                    System.out.print(Lab1.abs(input21));
                    break;
                case "2.3":
                    System.out.print("Введите число: \n");
                    int input23 = scanner.nextInt();

                    System.out.print(
                            "Делится ли число на 3 или на 5 (false так же если делится и на 3 и на 5)?\n");
                    System.out.print(Lab1.is35(input23));
                    break;
                case "2.5":
                    System.out.print("Введите первое число: \n");
                    int one25 = scanner.nextInt();
                    System.out.print("Введите второе число: \n");
                    int two25 = scanner.nextInt();
                    System.out.print("Введите третье число: \n");
                    int three25 = scanner.nextInt();

                    System.out.print("Максимальное из этих трех чисел: \n");
                    System.out.print(Lab1.max3(one25, two25, three25));
                    break;
                case "2.7":
                    System.out.print("Введите первое число: \n");
                    int one27 = scanner.nextInt();
                    System.out.print("Введите второе число: \n");
                    int two27 = scanner.nextInt();

                    System.out.print("Сумма чисел (если в диапазоне от 10 до 19, то вывести 20): \n");
                    System.out.print(Lab1.sum2(one27, two27));
                    break;
                case "2.9":
                    System.out.print("Введите день недели: \n");
                    int input29 = scanner.nextInt();

                    System.out.print(Lab1.day(input29));
                    break;
                case "3.1":
                    System.out.print("Введите число: \n");
                    int input31 = scanner.nextInt();

                    System.out.print("Итоговая строка: \n");
                    System.out.print(Lab1.listNums(input31));
                    break;
                case "3.3":
                    System.out.print("Введите число: \n");
                    int input43 = scanner.nextInt();

                    System.out.print("Итоговая строка с четными числами: \n");
                    System.out.print(Lab1.chet(input43));
                    break;
                case "3.5":
                    System.out.print("Введите число: \n");
                    int input45 = scanner.nextInt();

                    System.out.print("Количество знаков в числе: \n");
                    System.out.print(Lab1.numLen(input45));
                    break;
                case "3.7":
                    System.out.print("Введите длину стороны квадрата: \n");
                    int input47 = scanner.nextInt();

                    System.out.print("Квадрат: \n");
                    Lab1.square(input47);
                    break;
                case "3.9":
                    System.out.print("Введите длину катета треугольника: \n");
                    int input49 = scanner.nextInt();

                    System.out.print("Треугольник к правой стороне: \n");
                    Lab1.rightTriangle(input49);
                    break;
                case "4.1":
                    System.out.print("Введите длину массива: \n");
                    int length_arr41 = scanner.nextInt();
                    int[] arr41 = new int[length_arr41];
                    System.out.print("Вводите массив: \n");
                    for (int i = 0; i < length_arr41; i++) {
                        arr41[i] = scanner.nextInt();
                    }

                    System.out.print("Введите число для поиска: \n");
                    int num41 = scanner.nextInt();
                    System.out.print("Индекс первого вхождения числа в массив: \n");
                    System.out.print(Lab1.findFirst(arr41, num41));
                    break;
                case "4.3":
                    System.out.print("Введите длину массива: \n");
                    int length_arr43 = scanner.nextInt();
                    int[] arr43 = new int[length_arr43];
                    System.out.print("Вводите массив: \n");
                    for (int i = 0; i < length_arr43; i++) {
                        arr43[i] = scanner.nextInt();
                    }

                    System.out.print("Макимальное по модулю число в массиве:\n");
                    System.out.print(Lab1.maxAbs(arr43));
                    break;
                case "4.5":
                    System.out.print("Введите длину изначального массива: \n");
                    int length_arr45 = scanner.nextInt();
                    int[] arr45 = new int[length_arr45];
                    System.out.print("Вводите изначальный массив: \n");
                    for (int i = 0; i < length_arr45; i++) {
                        arr45[i] = scanner.nextInt();
                    }

                    System.out.print("Введите длину вставляемого массива: \n");
                    int length_arr_ins45 = scanner.nextInt();
                    int[] arr_ins45 = new int[length_arr_ins45];
                    System.out.print("Вводите вставляемый массив: \n");
                    for (int i = 0; i < length_arr_ins45; i++) {
                        arr_ins45[i] = scanner.nextInt();
                    }

                    System.out.print("Введите позицию, куда необходимо вставить массив: \n");
                    int ins_num45 = scanner.nextInt();
                    int[] arr_out45 = Lab1.add(arr45, arr_ins45, ins_num45);

                    System.out.print("Массив после вставки: \n");
                    for (int i : arr_out45) System.out.print(i + " ");
                    break;
                case "4.7":
                    System.out.print("Введите длину массива: \n");
                    int length_arr47 = scanner.nextInt();
                    int[] arr47 = new int[length_arr47];
                    System.out.print("Вводите массив: \n");
                    for (int i = 0; i < length_arr47; i++) {
                        arr47[i] = scanner.nextInt();
                    }

                    int[] arr_out47 = Lab1.reverseBack(arr47);
                    System.out.print("Массив нааоборот: \n");
                    for (int i : arr_out47) System.out.print(i + " ");
                    break;
                case "4.9":
                    System.out.print("Введите длину массива: \n");
                    int length_arr49 = scanner.nextInt();
                    int[] arr49 = new int[length_arr49];
                    System.out.print("Вводите массив: \n");
                    for (int i = 0; i < length_arr49; i++) {
                        arr49[i] = scanner.nextInt();
                    }

                    System.out.print("Введите число, позиции которого будем искать: \n");
                    int num49 = scanner.nextInt();

                    int[] arr_out49 = Lab1.findAll(arr49, num49);
                    System.out.print(
                            "массив, в котором записаны индексы вхождений числа " + num49 + " в массиве:\n");
                    for (int i : arr_out49) System.out.print(i + " ");
                    break;
                case "0":
                    go = false;
                    System.out.printf("Конец показа!");
                    break;
                default:
                    System.out.printf("Ошибка ввода :(");
                    break;
            }
        }
    }
}