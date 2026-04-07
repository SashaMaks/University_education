import java.util.Scanner;

//FIX_ME: исправлена табуляция с tab на 2 пробела

public class Main {
  private static Scanner scanner = new Scanner(System.in);

  public static void main(String[] args) {
    boolean choose = true;
    while (choose) {
      System.out.println("Выберете задание для показа задач (1, 2, 3, 4.1, 4.7, 5 | 0 - для выхода):");
      String choice = scanner.nextLine();
      switch (choice) {
        case "1":
          task1();
          break;
        case "2":
          task2();
          break;
        case "3":
          task3();
          break;
        case "4.1":
          task41();
          break;
        case "4.7":
          task47();
          break;
        case "5":
          task5();
          break;
        case "0":
          choose = false;
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

  //FIX_ME: имена методов в виде lowerCamelCase
  //private static void Task1() {
  private static void task1() {
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

  //FIX_ME: имена методов в виде lowerCamelCase
  //private static void Task2() {
  private static void task2() {
    Line line1 = new Line(new Point(1, 3), new Point(23, 8));
    Line line2 = new Line(new Point(5, 10), new Point(25, 10));
    Line line3 = new Line(line1.getStart(), line2.getEnd());

    System.out.println("1. " + line1.toString());
    System.out.println("2. " + line2.toString());
    System.out.println("3. " + line3.toString());

    line1.getStart().setPoint(0, 0);
    line2.getEnd().setPoint(20, 20);
    System.out.println("\nПосле изменения:");
    System.out.println("Линия 1: " + line1);
    System.out.println("Линия 2: " + line2);
    System.out.println("Линия 3: " + line3);

    line1.setStart(new Point(1, 1));
    line2.setEnd(new Point(0, 0));
    System.out.println("\nПосле изменения:");
    System.out.println("Линия 1: " + line1);
    System.out.println("Линия 2: " + line2);
    System.out.println("Линия 3: " + line3);
  }

  // ----------------------------=3=------------------------------------------

  //FIX_ME: имена методов в виде lowerCamelCase
  //private static void Task3() {
  private static void task3() {
    //FIX_ME: имена переменных в вид lowerCamelCase
    /*Student Vasya = new Student("Вася",3,4,5);
    Student Petya = new Student("Петя", Vasya.getGrades());*/
    Student vasya = new Student("Вася", 3, 4, 5);
    Student petya = new Student("Петя", vasya.getGrades());

    System.out.println("Студенты Вася и Петя");
    System.out.println("1. " + vasya.toString());
    System.out.println("2. " + petya.toString());

    vasya.setGrade(0, 5);

    System.out.println("\nИзменили 1 оценку Васи на 5 ");
    System.out.println("1. " + vasya.toString());
    System.out.println("2. " + petya.toString());

    //FIX_ME: имена переменных в вид lowerCamelCase
    //Student Andrew = new Student("Андрей", vasya.getGradesNoLinks());
    Student andrew = new Student("Андрей", vasya.getGradesNoLinks());
    System.out.println("\nСтуденты Вася, Петя и Андрей");
    System.out.println("1. " + vasya.toString());
    System.out.println("2. " + petya.toString());
    System.out.println("3. " + andrew.toString());

    vasya.setGrade(1, 5);

    System.out.println("\nИзменили 1 оценку у Васи");
    System.out.println("1. " + vasya.toString());
    System.out.println("2. " + petya.toString());
    System.out.println("3. " + andrew.toString());
  }

  // ----------------------------=4.1=------------------------------------------

  //FIX_ME: имена методов в виде lowerCamelCase
  //private static void Task41() {
  private static void task41() {
    Point4 point1 = new Point4(3, 5);
    Point4 point2 = new Point4(25, 6);
    Point4 point3 = new Point4(7, 8);

    System.out.println("1. " + point1.toString());
    System.out.println("2. " + point2.toString());
    System.out.println("3. " + point3.toString());

    //Point4 point4 = new Point4();
  }

  // ----------------------------=4.7=------------------------------------------

  //FIX_ME: имена методов в виде lowerCamelCase
  //private static void Task47() {
  private static void task47() {
    //FIX_ME: имена переменных в вид lowerCamelCase
    /*Student4 Vasya = new Student4("Вася",3,4,5);
    Student4 Maksim = new Student4("Максим");*/
    Student4 vasya = new Student4("Вася", 3, 4, 5);
    Student4 maksim = new Student4("Максим");

    System.out.println("1. " + vasya.toString());
    System.out.println("2. " + maksim.toString());
  }

  // ----------------------------=5=------------------------------------------

  //FIX_ME: имена методов в виде lowerCamelCase
  //private static void Task5() {
  private static void task5() {
    //FIX_ME: имена переменных в вид lowerCamelCase
    /*Student5 Vasya = new Student5("Вася",3,4,5,4);
    Student5 Petya = new Student5("Петя",5,5,5,5);*/
    Student5 vasya = new Student5("Вася", 3, 4, 5, 4);
    Student5 petya = new Student5("Петя", 5, 5, 5, 5);

    System.out.println("1. " + vasya.toString());
    System.out.println("Средний балл Васи: " + vasya.averegeGrade());
    System.out.println("Отличник ли Вася: " + vasya.isExcellent());
    System.out.println("2. " + petya.toString());
    System.out.println("Средний балл Пети: " + petya.averegeGrade());
    System.out.println("Отличник ли Петя: " + petya.isExcellent());
  }
}