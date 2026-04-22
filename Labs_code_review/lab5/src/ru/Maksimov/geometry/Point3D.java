package ru.Maksimov.geometry;

public class Point3D extends Point {
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
    public double getZ() {
        return z;
    }

    // Сеттеры
    public void setZ(double z) {
        this.z = z;
    }
    public void setPoint(double x,double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    // Преобразование в сроку
    public String toString() {
        return "{" + x + ";" + y + ";" + z + "}";
    }
}
