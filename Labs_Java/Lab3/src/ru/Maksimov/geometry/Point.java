package ru.Maksimov.geometry;

import java.util.Objects;

public class Point {
    private double x;
    private double y;

    // Конструкторы точки
    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
    public Point() {
        this(0, 0);
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

    // Вычисление расстояния до другой точки
    public double distanceTo(Point other) {
        double dx = this.x - other.x;
        double dy = this.y - other.y;
        return Math.sqrt(dx * dx + dy * dy);
    }

    // Сравнение точек
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Point point = (Point) o;
        return Double.compare(point.x, x) == 0 && Double.compare(point.y, y) == 0;
    }

    // Клонирование точки
    protected Point clone() {
        return new Point(this);
    }

    // Преобразование в сроку
    public String toString() {
        return "{" + x + ";" + y + "}";
    }
}
