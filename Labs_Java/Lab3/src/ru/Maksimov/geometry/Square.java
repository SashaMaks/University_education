package ru.Maksimov.geometry;

public class Square extends Shape {
    private Point topLeft;
    private double side;

    // Конструкторы
    public Square(Point topLeft, double side) {
        this.topLeft = topLeft;
        if (side <= 0) {
            throw new IllegalArgumentException("Сторона должна быть положительным числом");
        }
        this.side = side;
    }
    public Square(double topLeftX, double topLeftY, double side) {
        this(new Point(topLeftX, topLeftY), side);
    }

    // Геттеры
    public Point getTopLeft() {
        return topLeft;
    }
    public double getSide() {
        return side;
    }
    public Polyline getVerticesPolyline() {
        Point[] vertices = getVertices();
        ClosedPolyline closedPolyline = new ClosedPolyline(
                vertices[0], vertices[1], vertices[2], vertices[3]
        );
        Point[] closedPoints = closedPolyline.getPoints();
        return new Polyline(closedPoints);
    }
    public Point[] getVertices() {
        double x = topLeft.getX();
        double y = topLeft.getY();

        return new Point[] {
                new Point(x, y),
                new Point(x + side, y),
                new Point(x + side, y - side),
                new Point(x, y - side)
        };
    }
    public String getShapeType() {
        return "Квадрат";
    }

    // Сеттеры
    public void setTopLeft(Point topLeft) {
        this.topLeft = topLeft;
    }
    public void setTopLeft(double topLeftX, double topLeftY) {
        this.topLeft = new Point(topLeftX, topLeftY);
    }
    public void setSide(double side) {
        this.side = side;
    }

    // Площадь фигуры
    public double calculateArea() {
        return side * side;
    }

    // Преобразование в строку
    public String toString() {
        return "Квадрат в точке " + topLeft.toString() + ", со стороной " + side + ", площадь=" + calculateArea();
    }
}
