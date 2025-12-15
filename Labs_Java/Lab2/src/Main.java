import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        boolean go = true;
        while (go) {
            System.out.println("Выберете задание для показа задач (1, 2, 3, 4.1, 4.7, 5 | 0 - для выхода):");
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
                case "4.1":
                    Task41();
                    break;
                case "4.7":
                    Task47();
                    break;
                case "5":
                    Task5();
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
        System.out.println("Введите 1X: ");
        double point1X = Checks.readNumber();
        System.out.println("Введите 1Y: ");
        double point1Y = Checks.readNumber();
        System.out.println("Введите 2X: ");
        double point2X = Checks.readNumber();
        System.out.println("Введите 2Y: ");
        double point2Y = Checks.readNumber();
        System.out.println("Введите 3X: ");
        double point3X = Checks.readNumber();
        System.out.println("Введите 3Y: ");
        double point3Y = Checks.readNumber();
        Point point1 = new Point(point1X,point1Y);
        Point point2 = new Point(point2X,point2Y);
        Point point3 = new Point(point3X,point3Y);

        System.out.println("1. " + point1.toString());
        System.out.println("2. " + point2.toString());
        System.out.println("3. " + point3.toString());
    }

    // ----------------------------=2=------------------------------------------

    private static void Task2() {
        Line line1 = new Line(new Point(1, 3), new Point(23,8));
        Line line2 = new Line(new Point(5,10), new Point(25, 10));
        Line line3 = new Line(line1.getStart(), line2.getEnd());

        System.out.println("1. " + line1.toString());
        System.out.println("2. " + line2.toString());
        System.out.println("3. " + line3.toString());

        line1.getStart().setPoint(0,0);
        line2.getEnd().setPoint(20,20);
        System.out.println("\nПосле изменения:");
        System.out.println("Линия 1: " + line1);
        System.out.println("Линия 2: " + line2);
        System.out.println("Линия 3: " + line3);

        line1.setStart(new Point(1,1));
        line2.setEnd(new Point(0,0));
        System.out.println("\nПосле изменения:");
        System.out.println("Линия 1: " + line1);
        System.out.println("Линия 2: " + line2);
        System.out.println("Линия 3: " + line3);
    }

    // ----------------------------=3=------------------------------------------

    private static void Task3() {
        Student Vasya = new Student("Вася",3,4,5);
        Student Petya = new Student("Петя", Vasya.getGrades());

        System.out.println("Студенты Вася и Петя");
        System.out.println("1. " + Vasya.toString());
        System.out.println("2. " + Petya.toString());

        Vasya.setGrade(0,5);

        System.out.println("\nИзменили 1 оценку Васи на 5 ");
        System.out.println("1. " + Vasya.toString());
        System.out.println("2. " + Petya.toString());

        Student Andrew = new Student("Андрей", Vasya.getGradesNoLinks());
        System.out.println("\nСтуденты Вася, Петя и Андрей");
        System.out.println("1. " + Vasya.toString());
        System.out.println("2. " + Petya.toString());
        System.out.println("3. " + Andrew.toString());

        Vasya.setGrade(1,5);

        System.out.println("\nИзменили 1 оценку у Васи");
        System.out.println("1. " + Vasya.toString());
        System.out.println("2. " + Petya.toString());
        System.out.println("3. " + Andrew.toString());
    }

    // ----------------------------=4.1=------------------------------------------

    private static void Task41() {
        Point4 point1 = new Point4(3,5);
        Point4 point2 = new Point4(25,6);
        Point4 point3 = new Point4(7,8);

        System.out.println("1. " + point1.toString());
        System.out.println("2. " + point2.toString());
        System.out.println("3. " + point3.toString());

        //Point4 point4 = new Point4();
    }

    // ----------------------------=4.7=------------------------------------------

    private static void Task47() {
        Student4 Vasya = new Student4("Вася",3,4,5);
        Student4 Maksim = new Student4("Максим");

        System.out.println("1. " + Vasya.toString());
        System.out.println("2. " + Maksim.toString());
    }

    // ----------------------------=5=------------------------------------------

    private static void Task5() {
        Student5 Vasya = new Student5("Вася",3,4,5,4);
        Student5 Petya = new Student5("Петя",5,5,5,5);

        System.out.println("1. " + Vasya.toString());
        System.out.println("Средний балл Васи: " + Vasya.AveregeGrade());
        System.out.println("Отличник ли Вася: " + Vasya.isExcellent());
        System.out.println("2. " + Petya.toString());
        System.out.println("Средний балл Пети: " + Petya.AveregeGrade());
        System.out.println("Отличник ли Петя: " + Petya.isExcellent());
    }
}
