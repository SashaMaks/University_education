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
}
