package ru.Maksimov.geometry;

import java.util.Arrays;

public class Polyline {
    private Point[] points;

    // Конструктор
    public Polyline(Point... points) {
        if (points == null) {
            throw new IllegalArgumentException("Массив точек не может быть null");
        }
        this.points = Arrays.copyOf(points, points.length);
    }

    // Геттеры
    public Point[] getPoints() { return Arrays.copyOf(points, points.length); }
    public int getPointCount() { return points.length; }
    public Point getPoint(int index) {
        if (index < 0 || index >= points.length) {
            throw new IndexOutOfBoundsException("Индекс вне диапазона: " + index);
        }
        return points[index];
    }

    // Нахождение длины ломаной
    public double getLength() {
        if (points.length < 2) {
            return 0.0;  // для одной точки длина 0
        }

        double length = 0.0;
        for (int i = 0; i < points.length - 1; i++) {
            length += points[i].distanceTo(points[i + 1]);
        }
        return length;
    }

    // Преобразование в сроку
    public String toString() {
        StringBuilder sb = new StringBuilder("Линия [");

        for (int i = 0; i < points.length; i++) {
            sb.append(points[i]);
            if (i < points.length - 1) {
                sb.append(",");
            }
        }

        sb.append("]");
        return sb.toString();
    }
}
