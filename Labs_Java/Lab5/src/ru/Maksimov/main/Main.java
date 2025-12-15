package ru.Maksimov.main;

import ru.Maksimov.geometry.*;
import ru.Maksimov.utils.*;
import ru.Maksimov.meowings.*;
import ru.Maksimov.files.*;
import ru.Maksimov.other.*;

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.*;
import java.io.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        boolean go = true;
        while (go) {
            System.out.println("Выберете задание для показа задач (1, 2, 3, 4, 5, 6, 7.1, 7.2| 0 - для выхода):");
            String choice = scanner.nextLine();
            switch (choice) {
                case "1":
                    Task1();
                    break;
                case "2":
                    Task2();
                    break;
                case "3":
                    Task3();
                    break;
                case "4":
                    Task4();
                    break;
                case "5":
                    Task5();
                    break;
                case "6":
                    Task6();
                    break;
                case "7.1":
                    Task71();
                    break;
                case "7.2":
                    Task72();
                    break;
                case "0":
                    go = false;
                    System.out.println("Конец показа!");
                    scanner.close();
                    break;
                default:
                    System.out.println("Ошибка ввода :(");
                    break;
            }
        }
    }

    // ------------------------- ЗАДАНИЯ ---------------------------------------

    // ----------------------------=1=------------------------------------------

    private static void Task1() {
        Fraction fraction1 = Checks.inputFraction();
        Fraction fraction2 = Checks.inputFraction();

        System.out.println("Созданы дроби:");
        System.out.println("Дробь 1: " + fraction1.toString());
        System.out.println("Дробь 2: " + fraction2.toString());

        System.out.println("Сравнение дробей:");
        System.out.println("fraction1.equals(fraction3): " + fraction1.equals(fraction2));
    }

    // ----------------------------=2=------------------------------------------

    private static void Task2() {
        System.out.println("Введите имя кота: ");

        String name = Checks.readNonEmptyString();
        Cat cat = new Cat(name);

        System.out.println("Создана сущность: " + cat.toString());

        List<Meowing> meowing = new ArrayList<>();
        meowing.add(cat);

        System.out.println("Мяуканий в начале: " + cat.getMeowCount());
        MeowEverybody.makeAllMeow(meowing.toArray(new Meowing[0]));

        System.out.println("Мяуканий после вызова: " + cat.getMeowCount());
    }

    // ----------------------------=3=------------------------------------------

    private static void Task3() {
        System.out.println("Ввод списка L1: ");
        List<String> L1 = Checks.inputStringList();

        System.out.println("Ввод списка L2: ");
        List<String> L2 = Checks.inputStringList();

        List<String> L = ListOperation.getDifferenceSimple(L1, L2);

        System.out.println("Результаты:");
        System.out.println("L1: " + L1);
        System.out.println("L2: " + L2);
        System.out.println("L (элементы из L1, которых нет в L2, без дублей): " + L);
    }

    // ----------------------------=4=------------------------------------------

    private static void Task4() {
        try {
            analyzeSchools analyzer = new analyzeSchools();
            List<analyzeSchools.Student> students = analyzer.loadDataFromFile("C:\\Users\\HOOR\\IdeaProjects\\Lab5\\src\\ru\\Maksimov\\files\\students.txt");

            List<Integer> resultSchools = analyzer.analyze(students);

            System.out.println("Результат:");
            if (resultSchools.isEmpty()) {
                System.out.println("Нет школ со средним баллом выше районного");
            } else {
                for (int school : resultSchools) {
                    System.out.print(school + " ");
                }
                System.out.println();
            }

        } catch (Exception e) {
            System.out.println("Ошибка: " + e.getMessage());
        }
    }

    // ----------------------------=5=------------------------------------------

    private static void Task5() {
        String text = TextAnalyzer.readTextFromFile("C:\\Users\\HONOR\\IdeaProjects\\Lab5\\src\\ru\\Maksimov\\files\\text.txt");

        TextAnalyzer analyzer = new TextAnalyzer();

        System.out.println("Исходный текст:\n" + text);

        Set<Character> uniqueChars = analyzer.analyzeText(text);
        System.out.println("Символы, встречающиеся только в одном слове:");
        if (uniqueChars.isEmpty()) {
            System.out.println("Таких символов нет");
        } else {
            int count = 1;
            for (char c : uniqueChars) {
                System.out.println(count++ + ". '" + c + "'");
            }
        }
    }

    // ----------------------------=6=------------------------------------------

    private static void Task6() {
        Queue<String> L1 = new LinkedList<>();

        System.out.println("Введите количество элементов: ");
        int count = scanner.nextInt();
        scanner.nextLine();

        System.out.println("Введите " + count + " строк:");
        for (int i = 0; i < count; i++) {
            System.out.println("Элемент " + (i + 1) + ": ");
            L1.add(scanner.nextLine());
        }

        System.out.println("Исходная очередь L1:");
        Checks.printQueue(L1);

        Queue<String> L2 = QueueReverser.reverseQueue(L1);
        System.out.println("Очередь L2 (перевернутая L1):");
        Checks.printQueue(L2);
    }

    // ----------------------------=7.1=------------------------------------------

    private static void Task71() {
        List<Point> points = Checks.inputPoints();

        System.out.println("Исходные точки: ");
        for (Point point : points) {
            System.out.print(point.toString());
        }

        System.out.println("Количество исходных точек: " + points.size());

        System.out.println("Обработка стримом");
        Polyline polyline = PointOperations.processPointsWithStream(points);

        System.out.println("Результирующая ломаная: " + polyline.toString());
        System.out.println("Количество точек: " + polyline.getPointCount());
    }

    // ----------------------------=7.2=------------------------------------------

    private static void Task72() {
        String filename = "C:\\Users\\HONOR\\IdeaProjects\\Lab5\\src\\ru\\Maksimov\\files\\people.txt";
        try {
            Map<Integer, List<String>> result = PeoplesAndNumbers.processFile(filename);

            System.out.print("Результат: ");
            if (result.isEmpty()) {
                System.out.println("[]");
            } else {
                List<String> parts = new ArrayList<>();
                result.entrySet().stream()
                        .sorted(Map.Entry.<Integer, List<String>>comparingByKey().reversed())
                        .forEach(entry -> {
                            parts.add(entry.getKey() + ":[" + String.join(", ", entry.getValue()) + "]");
                        });
                System.out.println("[" + String.join(", ", parts) + "]");
            }

        } catch (FileNotFoundException e) {
            System.out.println("Файл не найден: " + filename);
        } catch (IOException e) {
            System.out.println("Ошибка чтения файла: " + e.getMessage());
        }
    }
}
