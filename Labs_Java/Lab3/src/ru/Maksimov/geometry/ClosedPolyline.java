package ru.Maksimov.geometry;

import java.util.Arrays;

public class ClosedPolyline{
    private Point[] points;

    // Конструктор
    public ClosedPolyline(Point... points) {
        if (points == null || points.length < 2) {
            throw new IllegalArgumentException("Нужно минимум 2 точки");
        }

        // Если не замкнуто - замыкаем
        if (!points[0].equals(points[points.length - 1])) {
            this.points = new Point[points.length + 1];
            System.arraycopy(points, 0, this.points, 0, points.length);
            this.points[points.length] = new Point(points[0].getX(), points[0].getY());
        } else {
            this.points = Arrays.copyOf(points, points.length);
        }
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
    public double getLength() {
        double length = 0.0;
        for (int i = 0; i < points.length - 1; i++) {
            length += points[i].distanceTo(points[i + 1]);
        }
        return length;
    }

    //Преобразование в сроку
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
