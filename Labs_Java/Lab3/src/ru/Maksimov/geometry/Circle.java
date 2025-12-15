package ru.Maksimov.geometry;

public class Circle extends Shape {
    private Point center;
    private double radius;

    // Конструкторы
    public Circle(Point center, double radius) {
        this.center = center;
        if (radius <= 0) {
            throw new IllegalArgumentException("Радиус должен быть положительным числом");
        }
        this.radius = radius;
    }
    public Circle(double centerX, double centerY, double radius) {
        this(new Point(centerX, centerY), radius);
    }

    // Геттер
    public Point getCenter() {
        return center;
    }
    public double getRadius() {
        return radius;
    }
    public String getShapeType() {
        return "Круг";
    }

    // Сеттер
    public void setCenter(Point center) {
        this.center = center;
    }
    public void setCenter(double centerX, double centerY) {
        this.center = new Point(centerX, centerY);
    }
    public void setRadius(double radius) {
        this.radius = radius;
    }

    // Площадь фигуры
    public double calculateArea() {
        return Math.PI * radius * radius;
    }

    // Преобразование в строку
    public String toString() {
        return "Круг с центром " + center + ", с радиусом " + radius + ", площадь " + calculateArea();
    }
}
