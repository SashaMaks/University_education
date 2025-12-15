public class Lab1 {
    // ------------------------- ЗАДАНИЯ ---------------------------------------

    // ----------------------------=1.1=------------------------------------------

    public static double fraction(double x) {
        return x - (int) x;
    }

    // ----------------------------=1.3=------------------------------------------
    public static int charToNum(char x) {
        return (int) x - 48;
    }

    // ----------------------------=1.5=------------------------------------------
    public static boolean is2Digits(int x) {
        if ((9 < x && x < 100) || (-9 > x && x > -100)) return true;
        else return false;
    }

    // ----------------------------=1.7=------------------------------------------
    public static boolean isInRange(int a, int b, int num) {
        if (b < a) {
            if (b <= num && num <= a) return true;
            else return false;
        } else if (a < b) {
            if (a <= num && num <= b) return true;
            else return false;
        } else {
            if (a == b && a == num) return true;
            else return false;
        }
    }

    // ----------------------------=1.9=------------------------------------------
    public static boolean isEqual(int a, int b, int c) {
        if (a == b && b == c) return true;
        else return false;
    }

    // ----------------------------=2.1=------------------------------------------
    public static int abs(int x) {
        if (x < 0) {
            x = x * (-1);
            return x;
        } else return x;
    }

    // ----------------------------=2.3=------------------------------------------
    public static boolean is35(int x) {
        if (x % 3 == 0 && x % 5 == 0) return false;
        else if (x % 3 == 0) return true;
        else if (x % 5 == 0) return true;
        else return false;
    }

    // ----------------------------=2.5=------------------------------------------
    public static int max3(int x, int y, int z) {
        if (y <= x && z <= x) return x;
        else if (x <= y && z <= y) return y;
        else return z;
    }

    // ----------------------------=2.7=------------------------------------------
    public static int sum2(int x, int y) {
        if (10 <= x + y && x + y <= 19) return 20;
        else return x + y;
    }

    // ----------------------------=2.9=------------------------------------------
    public static String day(int x) {
        switch (x) {
            case 1:
                return "Понедельник";
            case 2:
                return "Вторник";
            case 3:
                return "Среда";
            case 4:
                return "Четверг";
            case 5:
                return "Пятница";
            case 6:
                return "Суббота";
            case 7:
                return "Воскресенье";
            default:
                return "это не день недели";
        }
    }

    // ----------------------------=3.1=------------------------------------------
    public static String listNums(int x) {
        String s = "0";
        if (x > 0) {
            for (int i = 1; i <= x; i++) s = s + " " + Integer.toString(i);
        } else if (x < 0) {
            for (int i = -1; i >= x; i--) s = s + " " + Integer.toString(i);
        }
        return s;
    }

    // ----------------------------=3.3=------------------------------------------
    public static String chet(int x) {
        String s = "0";
        if (x > 0) {
            for (int i = 2; i <= x; i += 2) s = s + " " + Integer.toString(i);
        } else if (x < 0) {
            for (int i = -2; i >= x; i -= 2) s = s + " " + Integer.toString(i);
        }
        return s;
    }

    // ----------------------------=3.5=------------------------------------------
    public static int numLen(long x) {
        int i = 1;
        while (x / 10 != 0) {
            x = x / 10;
            i++;
        }
        return i;
    }

    // ----------------------------=3.7=------------------------------------------
    public static void square(int x) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) System.out.print("*");
            System.out.print("\n");
        }
    }

    // ----------------------------=3.9=------------------------------------------
    public static void rightTriangle(int x) {
        for (int i = x; i > 0; i--) {
            int spaces = i - 1;
            int stars = x - spaces;
            while (spaces != 0) {
                System.out.print(" ");
                spaces--;
            }
            while (stars != 0) {
                System.out.print("*");
                stars--;
            }
            System.out.print("\n");
        }
    }

    // ----------------------------=4.1=------------------------------------------
    public static int findFirst(int[] arr, int x) {
        for (int i = 0; i < arr.length; i++) if (arr[i] == x) return i;
        return -1;
    }

    // ----------------------------=4.3=------------------------------------------
    public static int maxAbs(int[] arr) {
        int max_abs_num = 0, max_abs = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < 0) {
                if (max_abs < arr[i] * (-1)) {
                    max_abs_num = i;
                    max_abs = arr[i] * (-1);
                }
            } else {
                if (max_abs < arr[i]) {
                    max_abs_num = i;
                    max_abs = arr[i];
                }
            }
        }
        return arr[max_abs_num];
    }

    // ----------------------------=4.5=------------------------------------------
    public static int[] add(int[] arr, int[] ins, int pos) {
        int[] arr_new = new int[arr.length + (int) ins.length];
        for (int i = 0; i < pos; i++) arr_new[i] = arr[i];
        for (int i = pos; i < pos + ins.length; i++) arr_new[i] = ins[i - pos];
        for (int i = pos + ins.length; i < ins.length + arr.length; i++)
            arr_new[i] = arr[i - ins.length];
        return arr_new;
    }

    // ----------------------------=4.7=------------------------------------------
    public static int[] reverseBack(int[] arr) {
        int[] arr_new = new int[arr.length];
        for (int i = 0; i < arr.length; i++) arr_new[i] = arr[arr.length - i - 1];
        return arr_new;
    }

    // ----------------------------=4.9=------------------------------------------
    public static int[] findAll(int[] arr, int x) {
        int counter = 0, j = 0;
        for (int i : arr) if (i == x) counter++;
        int[] arr_new = new int[counter];
        for (int i = 0; i < arr.length; i++)
            if (arr[i] == x) {
                arr_new[j] = i;
                j++;
            }
        return arr_new;
    }
}