public class Point4 {
    private double x;
    private double y;

    // Конструктор
    public Point4(double x, double y) {
        this.x = x;
        this.y = y;
    }

    // Геттеры
    public double getX() {
        return x;
    }
    public double getY() {
        return y;
    }

    // Сеттеры
    public void setX(double x) {
        this.x = x;
    }
    public void setY(double y) {
        this.y = y;
    }
    public void setPoint(double x,double y) {
        this.x = x;
        this.y = y;
    }

    // Преобразование в сроку
    public String toString() {
        return "{" + x + ";" + y + "}";
    }
}
