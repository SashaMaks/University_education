import java.util.*;
import java.util.Scanner;

class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        boolean go = true;
        while (go) {
            scanner.nextLine();
            System.out.println("Выберете задание для показа задач (1.1 - 1.9, 2.1 - 2.9, 3.1 - 3.9, 4.1 - 4.9 (вторые номера нечетные) | 0 - для выхода):");
            String choice = scanner.nextLine();
            switch (choice) {
                case "1.1":
                    System.out.println("Введите число: ");
                    double input11 = scanner.nextDouble();

                    System.out.println("Дробная часть числа: ");
                    System.out.println(Lab1.fraction(input11));
                    break;
                case "1.3":
                    System.out.println("Введите один из символов (0 1 2 3 4 5 6 7 8 9): ");
                    char input13 = scanner.next().charAt(0);

                    System.out.println("Число преобразованное из char в int: ");
                    System.out.println(Lab1.charToNum(input13));
                    break;
                case "1.5":
                    System.out.println("Введите число: ");
                    int input15 = scanner.nextInt();

                    System.out.println("Двухзначное ли число?");
                    System.out.println(Lab1.is2Digits(input15));
                    break;
                case "1.7":
                    System.out.println("Введите первую грань:");
                    int a_Range17 = scanner.nextInt();
                    System.out.println("Введите вторую грань:");
                    int b_Range17 = scanner.nextInt();
                    System.out.println("Введите число:");
                    int num17 = scanner.nextInt();

                    System.out.println("Находится ли число в диапазоне?");
                    System.out.println(Lab1.isInRange(a_Range17, b_Range17, num17));
                    break;
                case "1.9":
                    System.out.println("Введите первое число: ");
                    int one19 = scanner.nextInt();
                    System.out.println("Введите второе число: ");
                    int two19 = scanner.nextInt();
                    System.out.println("Введите третье число: ");
                    int three19 = scanner.nextInt();

                    System.out.println("Равны ли все три числа? ");
                    System.out.println(Lab1.isEqual(one19, two19, three19));
                    break;
                case "2.1":
                    System.out.println("Введите число: ");
                    int input21 = scanner.nextInt();

                    System.out.println("Модуль числа " + input21 + ": ");
                    System.out.println(Lab1.abs(input21));
                    break;
                case "2.3":
                    System.out.println("Введите число: ");
                    int input23 = scanner.nextInt();

                    System.out.println(
                            "Делится ли число на 3 или на 5 (false так же если делится и на 3 и на 5)?");
                    System.out.println(Lab1.is35(input23));
                    break;
                case "2.5":
                    System.out.println("Введите первое число: ");
                    int one25 = scanner.nextInt();
                    System.out.println("Введите второе число: ");
                    int two25 = scanner.nextInt();
                    System.out.println("Введите третье число: ");
                    int three25 = scanner.nextInt();

                    System.out.println("Максимальное из этих трех чисел: ");
                    System.out.println(Lab1.max3(one25, two25, three25));
                    break;
                case "2.7":
                    System.out.println("Введите первое число: ");
                    int one27 = scanner.nextInt();
                    System.out.println("Введите второе число: ");
                    int two27 = scanner.nextInt();

                    System.out.println("Сумма чисел (если в диапазоне от 10 до 19, то вывести 20): ");
                    System.out.println(Lab1.sum2(one27, two27));
                    break;
                case "2.9":
                    System.out.println("Введите день недели: ");
                    int input29 = scanner.nextInt();

                    System.out.println(Lab1.day(input29));
                    break;
                case "3.1":
                    System.out.println("Введите число: ");
                    int input31 = scanner.nextInt();

                    System.out.println("Итоговая строка: ");
                    System.out.println(Lab1.listNums(input31));
                    break;
                case "3.3":
                    System.out.println("Введите число: ");
                    int input43 = scanner.nextInt();

                    System.out.println("Итоговая строка с четными числами: ");
                    System.out.println(Lab1.chet(input43));
                    break;
                case "3.5":
                    System.out.println("Введите число: ");
                    int input45 = scanner.nextInt();

                    System.out.println("Количество знаков в числе: ");
                    System.out.println(Lab1.numLen(input45));
                    break;
                case "3.7":
                    System.out.println("Введите длину стороны квадрата: ");
                    int input47 = scanner.nextInt();

                    System.out.println("Квадрат: ");
                    Lab1.square(input47);
                    break;
                case "3.9":
                    System.out.println("Введите длину катета треугольника: ");
                    int input49 = scanner.nextInt();

                    System.out.println("Треугольник к правой стороне: ");
                    Lab1.rightTriangle(input49);
                    break;
                case "4.1":
                    System.out.println("Введите длину массива: ");
                    int length_arr41 = scanner.nextInt();
                    int[] arr41 = new int[length_arr41];
                    System.out.println("Вводите массив: ");
                    for (int i = 0; i < length_arr41; i++) {
                        arr41[i] = scanner.nextInt();
                    }

                    System.out.println("Введите число для поиска: ");
                    int num41 = scanner.nextInt();
                    System.out.println("Индекс первого вхождения числа в массив: ");
                    System.out.println(Lab1.findFirst(arr41, num41));
                    break;
                case "4.3":
                    System.out.println("Введите длину массива: ");
                    int length_arr43 = scanner.nextInt();
                    int[] arr43 = new int[length_arr43];
                    System.out.println("Вводите массив: ");
                    for (int i = 0; i < length_arr43; i++) {
                        arr43[i] = scanner.nextInt();
                    }

                    System.out.println("Макимальное по модулю число в массиве:");
                    System.out.println(Lab1.maxAbs(arr43));
                    break;
                case "4.5":
                    System.out.println("Введите длину изначального массива: ");
                    int length_arr45 = scanner.nextInt();
                    int[] arr45 = new int[length_arr45];
                    System.out.println("Вводите изначальный массив: ");
                    for (int i = 0; i < length_arr45; i++) {
                        arr45[i] = scanner.nextInt();
                    }

                    System.out.println("Введите длину вставляемого массива: ");
                    int length_arr_ins45 = scanner.nextInt();
                    int[] arr_ins45 = new int[length_arr_ins45];
                    System.out.println("Вводите вставляемый массив: ");
                    for (int i = 0; i < length_arr_ins45; i++) {
                        arr_ins45[i] = scanner.nextInt();
                    }

                    System.out.println("Введите позицию, куда необходимо вставить массив: ");
                    int ins_num45 = scanner.nextInt();
                    int[] arr_out45 = Lab1.add(arr45, arr_ins45, ins_num45);

                    System.out.println("Массив после вставки: ");
                    for (int i : arr_out45) System.out.println(i + " ");
                    break;
                case "4.7":
                    System.out.println("Введите длину массива: ");
                    int length_arr47 = scanner.nextInt();
                    int[] arr47 = new int[length_arr47];
                    System.out.println("Вводите массив: ");
                    for (int i = 0; i < length_arr47; i++) {
                        arr47[i] = scanner.nextInt();
                    }

                    int[] arr_out47 = Lab1.reverseBack(arr47);
                    System.out.println("Массив нааоборот: ");
                    for (int i : arr_out47) System.out.println(i + " ");
                    break;
                case "4.9":
                    System.out.println("Введите длину массива: ");
                    int length_arr49 = scanner.nextInt();
                    int[] arr49 = new int[length_arr49];
                    System.out.println("Вводите массив: ");
                    for (int i = 0; i < length_arr49; i++) {
                        arr49[i] = scanner.nextInt();
                    }

                    System.out.println("Введите число, позиции которого будем искать: ");
                    int num49 = scanner.nextInt();

                    int[] arr_out49 = Lab1.findAll(arr49, num49);
                    System.out.println(
                            "массив, в котором записаны индексы вхождений числа " + num49 + " в массиве:");
                    for (int i : arr_out49) System.out.println(i + " ");
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