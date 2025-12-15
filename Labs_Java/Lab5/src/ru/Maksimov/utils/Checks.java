package ru.Maksimov.utils;

import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Scanner;

import ru.Maksimov.geometry.Point;
import ru.Maksimov.other.Fraction;

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

    // Вводы для списков
    public static List<String> inputStringList() {
        List<String> list = new ArrayList<>();

        System.out.print("Введите количество строк: ");
        int count = readInt();

        for (int i = 0; i < count; i++) {
            System.out.print("Введите строку " + (i + 1) + ": ");
            String input = scanner.nextLine();
            list.add(input);
        }

        return list;
    }

    public static List<Integer> inputIntegerList() {
        List<Integer> list = new ArrayList<>();

        System.out.print("Введите количество чисел: ");
        int count = readInt();

        for (int i = 0; i < count; i++) {
            System.out.print("Введите число " + (i + 1) + ": ");
            int input = readInt();
            list.add(input);
        }

        return list;
    }

    public static List<int[]> inputArraysList() {
        List<int[]> list = new ArrayList<>();

        System.out.print("Введите количество массивов: ");
        int count = readInt();

        for (int i = 0; i < count; i++) {
            System.out.print("Введите длину массива " + (i + 1) + ": ");
            int length = readInt();
            int[] array = new int[length];
            for (int j = 0; j < length; j++) {
                System.out.print("Введите число " + (j + 1) + ": ");
                array[j] = readInt();
            }
            list.add(array);
        }
        return list;
    }

    public static List<List<Integer>> inputListsList() {
        List<List<Integer>> list = new ArrayList<>();

        System.out.print("Введите количество массивов: ");
        int count = readInt();

        for (int i = 0; i < count; i++) {
            System.out.print("Введите длину массива " + (i + 1) + ": ");
            int length = readInt();
            List<Integer> subList = new ArrayList<>();
            for (int j = 0; j < length; j++) {
                System.out.print("Введите число " + (j + 1) + ": ");
                int number = readInt();
                subList.add(number);
            }
            list.add(subList);
        }
        return list;
    }

    // Метод для вывода очереди
    public static <T> void printQueue(Queue<T> queue) {
        if (queue.isEmpty()) {
            System.out.println("Очередь пуста");
            return;
        }
        Queue<T> copy = new LinkedList<>(queue);
        System.out.print("[");
        while (!copy.isEmpty()) {
            System.out.print(copy.poll());
            if (!copy.isEmpty()) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }

    //--------------------------------------------------------

    // Чтение знаменателя
    public static int readDenominator() {
        while (true) {
            try {
                int denominator = readInt();
                if (denominator == 0) {
                    throw new IllegalArgumentException("Знаменатель не может быть равен нулю");
                } else {
                    return Integer.parseInt(scanner.nextLine().trim());
                }
            } catch (NumberFormatException e) {
                System.out.print("Ошибка! Введите целое число: ");
            }
        }
    }

    // Проверки на деление
    public static void checkDiv(Fraction fraction) {
        if (fraction.getNumerator() == 0) {
            throw new IllegalArgumentException("Деление на нулевую дробь");
        }
    }
    public static void checkDiv(int number) {
        if (number == 0) {
            throw new IllegalArgumentException("Деление на ноль");
        }
    }

    // Метод для вставки в дробь
    public static Fraction inputFraction() {
        while (true) {
            try {
                System.out.println("Введите дробь:");
                System.out.println("Числитель: ");
                int numerator = Checks.readInt();

                System.out.println("Знаменатель: ");
                int denominator = Checks.readDenominator();

                return new Fraction(numerator, denominator);
            } catch (IllegalArgumentException e) {
                System.out.println("Ошибка: " + e.getMessage());
                System.out.println("Пожалуйста, введите дробь снова");
            }
        }
    }

    // Метод для проверки что правильно ввели имени фамилии
    public static String checkStudentName(String name) {
        if (name.length() >= 20) {
            throw new IllegalArgumentException("Имя/фамилия слишком длинное (макс 20 символов)");
        }
        if (name.contains(" ")) {
            throw new IllegalArgumentException("Имя/фамилия не должно содержать пробелов");
        }
        return name;
    }

    // Метод для проверки что правильно ввели номер школы
    public static int checkSchoolNumber(String schoolStr) {
        try {
            int school = Integer.parseInt(schoolStr);
            if (school <= 1 || school >= 99) {
                throw new IllegalArgumentException("Номер школы должен быть от 1 до 99");
            }
            return school;
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("Неверный формат номера школы");
        }
    }

    // Метод для проверки что правильно ввели балл
    public static int checkScore(String scoreStr) {
        try {
            int score = Integer.parseInt(scoreStr);
            if (score <= 1 || score >= 100) {
                throw new IllegalArgumentException("Балл должен быть от 1 до 100");
            }
            return score;
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("Неверный формат балла");
        }
    }

    // Метод для ввода списка точек
    public static List<Point> inputPoints() {
        List<Point> points = new ArrayList<>();

        System.out.print("Сколько точек вы хотите ввести: ");
        int count = Checks.readInt();

        for (int i = 0; i < count; i++) {
            System.out.println("Точка " + (i + 1));
            System.out.println("Введите координату X: ");
            double x = Checks.readDouble();

            System.out.println("Введите координату Y: ");
            double y = Checks.readDouble();

            Point point = new Point(x,y);
            points.add(point);
        }
        return points;
    }
}
