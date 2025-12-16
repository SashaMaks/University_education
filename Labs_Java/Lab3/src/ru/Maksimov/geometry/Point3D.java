package ru.Maksimov.geometry;

public class Point3D {
    private double x;
    private double y;
    private double z;

    // Конструкторы
    public Point3D(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
    public Point3D() {
        this(0, 0, 0);
    }
    public Point3D(Point3D point) {
        this.x = point.x;
        this.y = point.y;
        this.z = point.z;
    }


    // Геттеры
    public double getX() {
        return x;
    }
    public double getY() {
        return y;
    }
    public double getZ() {
        return z;
    }

    // Сеттеры
    public void setX(double x) {
        this.x = x;
    }
    public void setY(double y) {
        this.y = y;
    }
    public void setZ(double z) {
        this.z = z;
    }
    public void setPoint(double x,double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
    // Вычисление расстояния до другой точки
    public double distanceTo(Point3D other) {
        double dx = this.x - other.x;
        double dy = this.y - other.y;
        double dz = this.z - other.z;
        return Math.sqrt(dx * dx + dy * dy + dz * dz);
    }

    // Преобразование в сроку
    public String toString() {
        return "{" + x + ";" + y + ";" + z + "}";
    }
}
