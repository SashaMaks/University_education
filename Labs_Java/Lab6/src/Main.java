import java.util.Scanner;


public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        boolean go = true;
        while (go) {
            System.out.println("Выберете задание для показа задач (1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 2.1, 2.2| 0 - для выхода):");
            String choice = scanner.nextLine();
            switch (choice) {
                case "1.1":
                    Task11();
                    break;
                case "1.2":
                    Task12();
                    break;
                case "1.3":
                    Task13();
                    break;
                case "1.4":
                    Task14();
                    break;
                case "1.5":
                    Task15();
                    break;
                case "1.6":
                    Task16();
                    break;
                case "2.1":
                    Task21();
                    break;
                case "2.2":
                    Task22();
                    break;
                case "0":
                    go = false;
                    System.out.printf("Конец показа!");
                    scanner.close();
                    break;
                default:
                    System.out.printf("Ошибка ввода :(");
                    break;
            }
        }
    }

    // ------------------------- ЗАДАНИЯ ---------------------------------------

    // ----------------------------=1.1=------------------------------------------

    private static void Task11() {
        Class11 obj = new Class11();
        Processor.invokeAll(obj);
    }

    // ----------------------------=1.2=------------------------------------------

    private static void Task12() {
        Processor.processDefault(Class12.class);
    }

    // ----------------------------=1.3=------------------------------------------

    private static void Task13() {
        Class13 obj = new Class13();
        String str = Processor.ToString(obj);
        System.out.println(str);
    }

    // ----------------------------=1.4=------------------------------------------

    private static void Task14() {
        Processor.printValidationClasses(Class14.class);
    }

    // ----------------------------=1.5=------------------------------------------

    private static void Task15() {
        Processor.processDefault(Class12.class);
    }

    // ----------------------------=1.6=------------------------------------------

    private static void Task16() {
        Processor.processDefault(Class12.class);
    }

    // ----------------------------=2.1=------------------------------------------

    private static void Task21() {
        Processor.processDefault(Class12.class);
    }

    // ----------------------------=2.2=------------------------------------------

    private static void Task22() {
        Processor.processDefault(Class12.class);
    }
}

