package ru.Maksimov.main;

import ru.Maksimov.geometry.*;
import ru.Maksimov.utils.*;
import ru.Maksimov.other.*;

import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        boolean go = true;
        while (go) {
            System.out.println("Выберете задание для показа задач (1, 2, 3, 4, 5.3, 5.6, 6, 7.1, 7.2, 7.3, 8 | 0 - для выхода):");
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
                case "5.3":
                    Task53();
                    break;
                case "5.6":
                    Task56();
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
                case "7.3":
                    Task73(args);
                    break;
                case "8":
                    Task8(args);
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
        System.out.println("Введите 1 оценку для студента: ");
        int grade1 = Checks.readGrade();
        System.out.println("Введите 2 оценку для студента: ");
        int grade2 = Checks.readGrade();
        System.out.println("Введите 3 оценку для студента: ");
        int grade3 = Checks.readGrade();
        int[] grades = new int[3];
        grades[0] = grade1;
        grades[1] = grade2;
        grades[2] = grade3;

        Student Vova = new Student("Вова", grades);
        System.out.println(Vova.toString());
    }

    // ----------------------------=2=------------------------------------------

    private static void Task2() {
        System.out.println("Введите имя: ");
        String name = Checks.readNonEmptyString();
        System.out.println("Введите номер ");
        String number = Checks.readValidPhone();

        PhoneDirectory book = new PhoneDirectory();
        book.addContact(name,number);
        System.out.println(book.toString());

        book.addContact("Вася","88005553535");
        book.addContact("Вова","89999999999");
        book.addContact("Толик","80000000000");

        System.out.println(book.toString());

        System.out.println("Введите имя для удаления пары:");
        String nameToDel = Checks.readNonEmptyString();
        book.deletePair(nameToDel);
        System.out.println(book.toString());

        System.out.println("Поиск телефона по имени:");
        String nameForPhone = Checks.readNonEmptyString();
        System.out.println(book.getPhone(nameForPhone));

        System.out.println("Проверка на наличие имени в списке:");
        String nameToFind = Checks.readNonEmptyString();
        System.out.println(book.containName(nameToFind));

        System.out.println("Проверка на наличие телефона в списке:");
        String phoneToFind = Checks.readNonEmptyString();
        System.out.println(book.containPhone(phoneToFind));

        System.out.println("Все имена: ");
        String[] names = book.AllNames();
        for (int i = 0; i < names.length; i++) {
            System.out.println((i + 1) + ". " + names[i]);
        }

        System.out.println("Все телефоны: ");
        String[] phones = book.AllPhones();
        for (int i = 0; i < phones.length; i++) {
            System.out.println((i + 1) + ". " + phones[i]);
        }

        System.out.println("Все пары (имя-телефон): ");
        String[][] pairs = book.AllPairs();
        for (int i = 0; i < pairs.length; i++) {
            System.out.println((i + 1) + ". " + pairs[i][0] + " - " + pairs[i][1]);
        }

        System.out.println("Введите префикс имени по которому вести поиск: ");
        String prefix = Checks.readNonEmptyString();
        String[] prefixNames = book.getNamesStarting(prefix);
        for (int i = 0; i < prefixNames.length; i++) {
            System.out.println((i + 1) + ". " + prefixNames[i]);
        }
    }

    // ----------------------------=3=------------------------------------------

    private static void Task3() {
        System.out.println("Введите X: ");
        double point3DX = Checks.readNumber();
        System.out.println("Введите Y: ");
        double point3DY = Checks.readNumber();
        System.out.println("Введите Z: ");
        double point3DZ = Checks.readNumber();

        Point3D point3D = new Point3D(point3DX,point3DY,point3DZ);

        System.out.println(point3D.toString());
    }

    // ----------------------------=4=------------------------------------------

    private static void Task4() {
        System.out.println("\nКруг: \n");
        System.out.println("Введите X: ");
        double pointCircleX = Checks.readNumber();
        System.out.println("Введите Y: ");
        double pointCircleY = Checks.readNumber();
        System.out.println("Введите радиус: ");
        double radius = Checks.readNumber();
        Point pointCircle = new Point(pointCircleX,pointCircleY);
        Circle circle = new Circle(pointCircle,radius);
        System.out.println(circle.toString());

        System.out.println("\nКвадрат: \n");
        System.out.println("Введите X: ");
        double pointSquareX = Checks.readNumber();
        System.out.println("Введите Y: ");
        double pointSquareY = Checks.readNumber();
        System.out.println("Введите сторону: ");
        double sideSquare = Checks.readNumber();
        Point pointSquare = new Point(pointSquareX,pointSquareY);
        Square square = new Square(pointSquare,sideSquare);
        System.out.println(square.toString());

        System.out.println("\nПрямоугольник: \n");
        System.out.println("Введите X: ");
        double pointRectangleX = Checks.readNumber();
        System.out.println("Введите Y: ");
        double pointRectangleY = Checks.readNumber();
        System.out.println("Введите сторону a: ");
        double sideRectangleA = Checks.readNumber();
        System.out.println("Введите сторону b: ");
        double sideRectangleB = Checks.readNumber();
        Point pointRectangle = new Point(pointRectangleX,pointRectangleY);
        Rectangle rectangle = new Rectangle(pointRectangle,sideRectangleA,sideRectangleB);
        System.out.println(rectangle.toString());

        System.out.println("\nТреугольник: \n");
        System.out.println("Введите X1: ");
        double pointTriangle1X = Checks.readNumber();
        System.out.println("Введите Y1: ");
        double pointTriangle1Y = Checks.readNumber();
        System.out.println("Введите X2: ");
        double pointTriangle2X = Checks.readNumber();
        System.out.println("Введите Y2: ");
        double pointTriangle2Y = Checks.readNumber();
        System.out.println("Введите X3: ");
        double pointTriangle3X = Checks.readNumber();
        System.out.println("Введите Y3: ");
        double pointTriangle3Y = Checks.readNumber();
        Point pointTriangle1 = new Point(pointTriangle1X,pointTriangle1Y);
        Point pointTriangle2 = new Point(pointTriangle2X,pointTriangle2Y);
        Point pointTriangle3 = new Point(pointTriangle3X,pointTriangle3Y);
        Triangle triangle = new Triangle(pointTriangle1,pointTriangle2,pointTriangle3);
        System.out.println(triangle.toString());


    }

    // ----------------------------=5.3=------------------------------------------

    private static void Task53() {

        System.out.println("\nКруг1: \n");
        System.out.println("Введите X: ");
        double pointCircle1X = Checks.readNumber();
        System.out.println("Введите Y: ");
        double pointCircle1Y = Checks.readNumber();
        System.out.println("Введите радиус: ");
        double radius1 = Checks.readNumber();
        Point pointCircle1 = new Point(pointCircle1X,pointCircle1Y);
        Circle circle1 = new Circle(pointCircle1,radius1);
        System.out.println(circle1.toString());

        System.out.println("\nКруг2: \n");
        System.out.println("Введите X: ");
        double pointCircle2X = Checks.readNumber();
        System.out.println("Введите Y: ");
        double pointCircle2Y = Checks.readNumber();
        System.out.println("Введите радиус: ");
        double radius2 = Checks.readNumber();
        Point pointCircle2 = new Point(pointCircle2X,pointCircle2Y);
        Circle circle2 = new Circle(pointCircle2,radius2);
        System.out.println(circle2.toString());

        System.out.println("\nКвадрат1: \n");
        System.out.println("Введите X: ");
        double pointSquare1X = Checks.readNumber();
        System.out.println("Введите Y: ");
        double pointSquare1Y = Checks.readNumber();
        System.out.println("Введите сторону: ");
        double sideSquare1 = Checks.readNumber();
        Point pointSquare1 = new Point(pointSquare1X,pointSquare1Y);
        Square square1 = new Square(pointSquare1,sideSquare1);
        System.out.println(square1.toString());

        System.out.println("\nКвадрат2: \n");
        System.out.println("Введите X: ");
        double pointSquare2X = Checks.readNumber();
        System.out.println("Введите Y: ");
        double pointSquare2Y = Checks.readNumber();
        System.out.println("Введите сторону: ");
        double sideSquare2 = Checks.readNumber();
        Point pointSquare2 = new Point(pointSquare2X,pointSquare2Y);
        Square square2 = new Square(pointSquare2,sideSquare2);
        System.out.println(square2.toString());


        System.out.println("\nПлощади: \n");
        double totalArea = 0;
        Shape[] shapes = {circle1,circle2,square1,square2};
        for (Shape shape : shapes) {
            System.out.println(shape.getShapeType()+": площадь = "+ shape.calculateArea());
            totalArea += shape.calculateArea();
        }
        System.out.println("Общая площадь всех фигур: " + totalArea);
    }

    // ----------------------------=5.6=------------------------------------------

    private static void Task56() {
        System.out.println("\nКвадрат: \n");
        System.out.println("Введите X: ");
        double pointSquareX = Checks.readNumber();
        System.out.println("Введите Y: ");
        double pointSquareY = Checks.readNumber();
        System.out.println("Введите сторону: ");
        double sideSquare = Checks.readNumber();
        Point pointSquare = new Point(pointSquareX,pointSquareY);
        Square square = new Square(pointSquare,sideSquare);
        System.out.println(square.toString());

        System.out.println(square.getVerticesPolyline().toString());
    }

    // ----------------------------=6=------------------------------------------

    private static void Task6() {
        System.out.println("Введите X1: ");
        double point1X = Checks.readNumber();
        System.out.println("Введите Y1: ");
        double point1Y = Checks.readNumber();
        System.out.println("Введите X2: ");
        double point2X = Checks.readNumber();
        System.out.println("Введите Y2: ");
        double point2Y = Checks.readNumber();

        Point point1 = new Point(point1X,point1Y);
        Point point2 = new Point(point2X,point2Y);

        System.out.println("Равна ли точка 1 точке 2: " + point1.equals(point2));
    }

    // ----------------------------=7.1=------------------------------------------

    private static void Task71() {
        System.out.println("Сделано!");
    }

    // ----------------------------=7.2=------------------------------------------

    private static void Task72() {
        Student5 Vasia = new Student5("Вася",3,4,5,4);
        Student5 Petia = new Student5("Петя",5,5,5,5);

        System.out.println("Средний балл Васи: " + Vasia.AveregeGrade());
        System.out.println("Средний балл Пети: " + Petia.AveregeGrade());

        System.out.println("Отличник ли Вася: " + Vasia.isExcellent());
        System.out.println("Отличник ли Петя: " + Petia.isExcellent());

    }

    // ----------------------------=7.3=------------------------------------------

    private static void Task73(String[] args) {
        if (args.length != 2) {
            System.err.println("Нужно 2 числа: X и Y");
            return;
        }

        try {
            double result = Calculator.power(args[0], args[1]);
            System.out.println("Результат: " + result);
        } catch (Exception e) {
            System.out.println("Ошибка ввода");
        }

        //cd C:\Users\aleks\IdeaProjects\Lab3\src>
        //javac ru\Maksimov\main\Main.java
        //java ru.Maksimov.main.Main 5 3
    }

    // ----------------------------=8=------------------------------------------

    private static void Task8(String[] args) {
//        System.out.println("Введите X: ");
//        double point1X = Checks.readNumber();
//        System.out.println("Введите Y: ");
//        double point1Y = Checks.readNumber();
//
//        Point p1 = new Point(point1X,point1Y);
//        Point p2 = p1.clone();
//        System.out.println(p2.toString());

        PointShow.main(args);
    }
}
