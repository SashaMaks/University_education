package ru.Maksimov.geometry;

import java.util.*;

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

    // Возвращаем точку с положительным X
    public Point withPositiveX() {
        return new Point(Math.abs(x), y);
    }

    // Возвращаем точку с положительным Y
    public Point withPositiveY() {
        return new Point(x, Math.abs(y));
    }

    // Сравнение точек
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Point point = (Point) o;
        return Double.compare(point.x, x) == 0 && Double.compare(point.y, y) == 0;
    }

    //Преобразование в сроку
    public String toString() {
        return "{" + x + ";" + y + "}";
    }
}
