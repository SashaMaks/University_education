public class Point {
    private double x;
    private double y;

    // Конструкторы
    public Point() {
        this(0, 0);
    }
    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
    public Point(Point point) {
        this.x = point.x;
        this.y = point.y;
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