package ru.Maksimov.main;

import java.util.Scanner;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

import ru.Maksimov.geometry.*;
import ru.Maksimov.other.*;
import ru.Maksimov.other.Number;
import ru.Maksimov.utils.*;


public class Main {
    private static Scanner scanner = new Scanner(System.in);

    static void main(String[] args) {
        boolean go = true;
        while (go) {
            System.out.println("Выберете задание для показа задач (1.3, 1.4, 2, 3.1, 3.2, 3.3, 3.4| 0 - для выхода):");
            String choice = scanner.nextLine();
            switch (choice) {
                case "1.3":
                    Task13();
                    break;
                case "1.4":
                    Task14();
                    break;
                case "2":
                    Task2();
                    break;
                case "3.1":
                    Task31();
                    break;
                case "3.2":
                    Task32();
                    break;
                case "3.4":
                    Task34();
                    break;
                case "3.3":
                    Task33();
                    break;
                case "0":
                    go = false;
                    System.out.println("Конец показа!");
                    break;
                default:
                    System.out.println("Ошибка ввода :(");
                    break;
            }
        }
    }

    // ------------------------- ЗАДАНИЯ ---------------------------------------

    // ----------------------------=1.3=------------------------------------------

    private static void Task13() {
        System.out.println("Введите первое число:");
        int num1 = Checks.readInt();
        System.out.println("Введите второе число:");
        int num2 = Checks.readInt();

        Number number1 = new Number(num1);
        Number number2 = new Number(num2);

        int result = number1.compare(number2);

        System.out.println("Результат сравнения:");
        System.out.println("Число 1: " + number1);
        System.out.println("Число 2: " + number2);
        System.out.println("Результат compare: " + result);

        if (result == 1) {
            System.out.println("Число " + number1 + " больше Числа " + number2);
        } else if (result == -1) {
            System.out.println("Число " + number1 + " меньше Числа " + number2);
        } else {
            System.out.println("Числа равны");
        }
    }

    // ----------------------------=1.4=------------------------------------------

    private static void Task14() {
        System.out.println("Создание первого студента:");
        Student student1 = Checks.createStudent();
        System.out.println("Создание второго студента:");
        Student student2 = Checks.createStudent();

        System.out.println("Студент 1: " + student1);
        System.out.println("Средний балл: " + student1.getAverageGrade());
        System.out.println("Студент 2: " + student2);
        System.out.println("Средний балл: " + student2.getAverageGrade());

        int result = student1.compare(student2);

        System.out.println("Результат сравнения: " + result);
        if (result > 0) {
            System.out.println(student1.getName() + " имеет средний балл выше, чем " + student2.getName());
        } else if (result < 0) {
            System.out.println(student1.getName() + " имеет средний балл ниже, чем " + student2.getName());
        } else {
            System.out.println("Средние баллы студентов равны");
        }
    }

    // ----------------------------=2=------------------------------------------

    private static void Task2() {
        Box<Point3D> boxpoint = new Box<>();
        Box.inputPointInBox(boxpoint);
    }

    // ----------------------------=3.1=------------------------------------------

    private static void Task31() {
        System.out.print("1. ");
        List<String> input1 = Checks.inputStringList();

        List<Integer> result1 = Function4.function(input1, String::length);

        System.out.println("Исходный список: " + input1);
        System.out.println("Результат: " + result1);



        System.out.print("2. ");
        List<Integer> input2 = Checks.inputIntegerList();

        List<Integer> result2 = Function4.function(input2, Math::abs);

        System.out.println("Исходный список: " + input2);
        System.out.println("Результат: " + result2);



        System.out.print("3. ");
        List<int[]> input3 = Checks.inputArraysList();

        List<Integer> result3 = Function4.function(input3, arr -> {
            if (arr == null || arr.length == 0) {
                return null;
            }
            int max = arr[0];
            for (int i = 1; i < arr.length; i++) {
                if (arr[i] > max) {
                    max = arr[i];
                }
            }
            return max;
        });

        System.out.println("Исходный список: " + Arrays.deepToString(input3.toArray()));
        System.out.println("Результат: " + result3);
    }

    // ----------------------------=3.2=------------------------------------------

    private static void Task32() {
        System.out.print("1. ");
        List<String> input1 = Checks.inputStringList();

        List<String> result1 = Filter4.filter(input1, s -> s.length() <= 3);

        System.out.println("Исходный список: " + input1);
        System.out.println("Результат: " + result1);



        System.out.print("2. ");
        List<Integer> input2 = Checks.inputIntegerList();

        List<Integer> result2 = Filter4.filter(input2, x -> x > 0);

        System.out.println("Исходный список: " + input2);
        System.out.println("Результат: " + result2);



        System.out.print("3. ");
        List<int[]> input3 = Checks.inputArraysList();

        List<int[]> result3 = Filter4.filter(input3, arr -> {
            for (int num : arr) {
                if (num < 0) return false;
            }
            return true;
        });

        System.out.println("Исходный список: " + Arrays.deepToString(input3.toArray()));
        System.out.println("Результат: " + Arrays.deepToString(result3.toArray()));
    }

    // ----------------------------=3.3=------------------------------------------

    private static void Task33() {
        System.out.print("1. ");
        List<String> input1 = Checks.inputStringList();

        String result1 = Reduction4.reduce(input1, "", (acc, str) -> acc + str);

        System.out.println("Исходный список: " + input1);
        System.out.println("Результат: " + result1);



        System.out.print("2. ");
        List<Integer> input2 = Checks.inputIntegerList();

        Integer result2 = Reduction4.reduce(input2, 0 ,(s1, s2) -> s1 + s2);

        System.out.println("Исходный список: " + input2);
        System.out.println("Результат: " + result2);



        System.out.print("3. ");
        List<List<Integer>> input3 = Checks.inputListsList();

        List<Integer> allNumbers = Reduction4.reduce(input3, new ArrayList<>(),
                (acc, list) -> {
                    acc.addAll(list);
                    return acc;
                });
        int result3 = Reduction4.reduce(allNumbers, 0,
                (acc, size) -> acc + 1);

        System.out.println("Исходный список: " + input3);
        System.out.println("Результат: " + result3);
    }

    // ----------------------------=3.4=------------------------------------------

    private static void Task34() {
        System.out.print("1. ");
        List<Integer> input1 = Checks.inputIntegerList();
        List<List<Integer>> result1 = new ArrayList<>();
        result1.add(new ArrayList<>());
        result1.add(new ArrayList<>());

        Collecting4.collect(input1, result1,
                (list, num) -> {
                    if (num > 0) {
                        list.get(0).add(num);
                    } else {
                        list.get(1).add(num);
                    }
                }
        );

        System.out.println("Исходный список: " + input1);
        System.out.println("Результат: " + result1);



        System.out.print("2. ");
        List<String> input2 = Checks.inputStringList();
        List<List<String>> result2 = new ArrayList<>();

        Collecting4.collect(input2, result2,
                (list, str) -> {
                    boolean found = false;

                    for (List<String> group : list) {
                        if (!group.isEmpty() && group.get(0).length() == str.length()) {
                            group.add(str);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        List<String> newGroup = new ArrayList<>();
                        newGroup.add(str);
                        list.add(newGroup);
                    }
                }
        );

        System.out.println("Исходный список: " + input2);
        System.out.println("Результат: " + result2);



        System.out.print("3. ");
        List<String> input3 = Checks.inputStringList();
        List<String> result3 = new ArrayList<>();

        Collecting4.collect(input3, result3,
                (list, str) -> {
                    if (!list.contains(str)) {
                        list.add(str);
                    }
                }
        );

        System.out.println("Исходный список: " + input3);
        System.out.println("Результат: " + result3);
    }
}