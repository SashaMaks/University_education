package ru.Maksimov.geometry;

public class Rectangle extends Shape {
    private Point topLeft;
    private double sideA;
    private double sideB;

    // Конструктор
    public Rectangle(Point topLeft, double sideA, double sideB) {
        this.topLeft = topLeft;
        if (sideA <= 0 && sideB <= 0) {
            throw new IllegalArgumentException("Сторона должна быть положительным числом");
        }
        this.sideA = sideA;
        this.sideB = sideB;
    }
    public Rectangle(double topLeftX, double topLeftY, double sideA, double sideB) {
        this(new Point(topLeftX, topLeftY), sideA, sideB);
    }

    // Геттеры
    public Point getTopLeft() {
        return topLeft;
    }
    public double getSideA() {
        return sideA;
    }
    public double getSideB() {
        return sideB;
    }
    public String getShapeType() {
        return "Прямоугольник";
    }

    // Сеттеры
    public void setTopLeft(Point topLeft) {
        this.topLeft = topLeft;
    }
    public void setTopLeft(double topLeftX, double topLeftY) {
        this.topLeft = new Point(topLeftX, topLeftY);
    }
    public void setSideA(double sideA) {
        this.sideA = sideA;
    }
    public void setSideB(double sideB) {
        this.sideB = sideB;
    }

    // Площадь фигуры
    public double calculateArea() {
        return sideA * sideB;
    }

    // Преобразование в строку
    public String toString() {
        return "Прямоугольник в точке " + topLeft.toString() + ", со сторонами " + sideA + " " + sideB + ", площадь=" + calculateArea();
    }
}
