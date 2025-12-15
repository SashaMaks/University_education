package ru.Maksimov.geometry;

public class Triangle extends Shape {
    private Point pointA;
    private Point pointB;
    private Point pointC;

    // Конструктор
    public Triangle(Point pointA, Point pointB, Point pointC) {
        this.pointA = pointA;
        this.pointB = pointB;
        this.pointC = pointC;

        if (isCollinear()) {
            throw new IllegalArgumentException("Точки треугольника не должны лежать на одной прямой");
        }
    }
    public Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        this(new Point(x1, y1), new Point(x2, y2), new Point(x3, y3));
    }

    // Геттер
    public Point getPointA() {
        return pointA;
    }
    public Point getPointB() {
        return pointB;
    }
    public Point getPointC() {
        return pointC;
    }
    public String getShapeType() {
        return "Треугольник";
    }

    // Сеттеры
    public void setPointA(Point pointA) {
        this.pointA = pointA;
    }
    public void setPointB(Point pointB) {
        this.pointB = pointB;
    }
    public void setPointC(Point pointC) {
        this.pointC = pointC;
    }

    // Нахождение площади
    public double calculateArea() {
        return Math.abs(
                (pointA.getX() * (pointB.getY() - pointC.getY()) +
                        pointB.getX() * (pointC.getY() - pointA.getY()) +
                        pointC.getX() * (pointA.getY() - pointB.getY())) / 2.0
        );
    }

    // Проверка, что точки не лежат на одной прямой
    private boolean isCollinear() {
        double area = Math.abs(
                (pointB.getX() - pointA.getX()) * (pointC.getY() - pointA.getY()) -
                        (pointC.getX() - pointA.getX()) * (pointB.getY() - pointA.getY())
        );
        return area < 1e-10;
    }

    // Преобразование в строку
    public String toString() {
        return "Треугольник с точками A=" + pointA + ", B=" + pointB + ", C=" + pointC + ", площадь=" + calculateArea();
    }
}
