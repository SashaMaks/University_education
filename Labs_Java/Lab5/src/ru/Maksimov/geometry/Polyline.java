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

    // Сеттеры
    public void setPoint(int index, Point point) {
        if (index < 0 || index >= points.length) {
            throw new IndexOutOfBoundsException("Индекс вне диапазона: " + index);
        }
        points[index] = point;
    }

    //Преобразование в сроку
    public String toString() {
        String sb = "Линия [";

        for (int i = 0; i < points.length; i++) {
            sb = sb + points[i];
            if (i < points.length - 1) {
                sb = sb + ",";
            }
        }
        sb = sb + "]";
        return sb;
    }
}
