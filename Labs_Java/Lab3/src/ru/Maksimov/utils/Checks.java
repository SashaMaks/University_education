package ru.Maksimov.utils;

import java.util.Scanner;

public class Checks {
    private static Scanner scanner = new Scanner(System.in);

    // Чтение инт
    public static int readInt() {
        while (true) {
            try {
                return Integer.parseInt(scanner.nextLine().trim());
            } catch (NumberFormatException e) {
                System.out.print("Ошибка! Введите целое число: ");
            }
        }
    }

    // Чтение дабл
    public static double readDouble() {
        while (true) {
            try {
                return Double.parseDouble(scanner.nextLine().trim());
            } catch (NumberFormatException e) {
                System.out.print("Ошибка! Введите дробное число: ");
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
    public static int readIntInRange(int a, int b) {
        int min, max;
        if (a < b) {
            min = a;
            max = b;
        } else {
            min = b;
            max = a;
        }
        while (true) {
            int value = Checks.readInt();
            if (value >= min && value <= max) {
                return value;
            }
            System.out.printf("Ошибка! Введите число от ", min, " до ", max);
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

    // Проверка на то что ввели оценку
    public static int readGrade() {
        return readIntInRange(2, 5);
    }

    // Проверка на то что ввели телефон
    public static String readValidPhone() {
        while (true) {
            String phone = scanner.nextLine().trim();
            if (phone.length() == 11 && phone.charAt(0) == '8') {
                for (int i = 0; i < phone.length(); i++) {
                    if (!Character.isDigit(phone.charAt(i))) {
                        System.out.print("Ошибка! Введите номер (шаблон: 8**********): ");
                        break;
                    }
                }
                return phone;
            }
            System.out.print("Ошибка! Введите номер (шаблон: 8**********): ");
        }
    }
}
