package ru.Maksimov.utils;

import ru.Maksimov.other.Student;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Checks {
    private static Scanner scanner = new Scanner(System.in);

    // Чтение целого
    public static int readInt() {
        while (true) {
            try {
                return Integer.parseInt(scanner.nextLine().trim());
            } catch (NumberFormatException e) {
                System.out.print("Ошибка! Введите целое число: ");
            }
        }
    }

    // Чтение числа с плавающей точкой
    public static double readDouble() {
        while (true) {
            try {
                return Double.parseDouble(scanner.nextLine().trim());
            } catch (NumberFormatException e) {
                System.out.print("Ошибка! Введите целое число: ");
            }
        }
    }

    // Чтение числа
    public static double readNumber() {
        while (true) {
            String input = scanner.nextLine().trim();
            try {
                return Integer.parseInt(input);
            } catch (NumberFormatException e1) {
                try {
                    return Double.parseDouble(input);
                } catch (NumberFormatException e2) {
                    System.out.print("Ошибка! Введите число: ");
                }
            }
        }
    }

    // Чтение инт в рамках
    public static int readIntInRange(int min, int max) {
        while (true) {
            int value = Checks.readInt();
            if (value >= min && value <= max) {
                return value;
            }
            System.out.printf("Ошибка! Введите число от %d до %d: ", min, max);
        }
    }

    // Чтение, что строка не пустая
    public static String readNonEmptyString() {
        while (true) {
            String input = scanner.nextLine().trim();
            if (!input.isEmpty()) {
                return input;
            }
            System.out.print("Ошибка! Ввод не может быть пустым: ");
        }
    }

    //--------------------------------------------------------

    // Создание студента
    public static Student createStudent() {
        System.out.println("Введите имя студента: ");
        String name = Checks.readNonEmptyString();
        System.out.println("Введите количество оценок: ");
        int gradeCount = Checks.readInt();

        int[] grades = new int[gradeCount];
        for (int i = 0; i < gradeCount; i++) {
            System.out.println("Введите оценку " + (i + 1) + " (2-5): ");
            grades[i] = Checks.readGrade();
        }
        return new Student(name, grades);
    }

    // Проверка на то что ввели оценку
    public static int readGrade() {
        return readIntInRange(2, 5);
    }

    // Чтение списка строк
    public static List<String> inputStringList() {
        List<String> list = new ArrayList<>();

        System.out.print("Введите количество строк: ");
        int count = Checks.readInt();

        for (int i = 0; i < count; i++) {
            System.out.print("Введите строку " + (i + 1) + ": ");
            String input = scanner.nextLine();
            list.add(input);
        }
        return list;
    }

    // Чтение списка целых чисел
    public static List<Integer> inputIntegerList() {
        List<Integer> list = new ArrayList<>();

        System.out.print("Введите количество чисел: ");
        int count = Checks.readInt();

        for (int i = 0; i < count; i++) {
            System.out.print("Введите число " + (i + 1) + ": ");
            int input = Checks.readInt();
            list.add(input);
        }
        return list;
    }

    // Чтение списка массивов чисел
    public static List<int[]> inputArraysList() {
        List<int[]> list = new ArrayList<>();

        System.out.print("Введите количество массивов: ");
        int count = Checks.readInt();

        for (int i = 0; i < count; i++) {
            System.out.print("Введите длину массива " + (i + 1) + ": ");
            int length = Checks.readInt();
            int[] array = new int[length];
            for (int j = 0; j < length; j++) {
                System.out.print("Введите число " + (j + 1) + ": ");
                array[j] = Checks.readInt();
            }
            list.add(array);
        }
        return list;
    }

    // Чтение списка списков чисел
    public static List<List<Integer>> inputListsList() {
        List<List<Integer>> list = new ArrayList<>();

        System.out.print("Введите количество списков: ");
        int count = Checks.readInt();

        for (int i = 0; i < count; i++) {
            System.out.print("Введите длину списка " + (i + 1) + ": ");
            int length = Checks.readInt();
            List<Integer> subList = new ArrayList<>();
            for (int j = 0; j < length; j++) {
                System.out.print("Введите число " + (j + 1) + ": ");
                int number = Checks.readInt();
                subList.add(number);
            }
            list.add(subList);
        }
        return list;
    }
}