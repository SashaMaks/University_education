package ru.Maksimov.geometry;

public class Line {
    private Point start;
    private Point end;

    //Конструкторы
    public Line(Point start, Point end) {
        if (start == null || end == null) {
            throw new IllegalArgumentException("Точки не могут быть null");
        }
        this.start = start;
        this.end = end;
    }
    public Line(double x1, double y1, double x2, double y2) {
        this(new Point(x1, y1), new Point(x2, y2));
    }

    // Геттеры
    public Point getStart() { return start; }
    public Point getEnd() { return end; }

    // Сеттеры
    public void setStart(Point start) { this.start = start; }
    public void setEnd(Point end) { this.end = end; }

    //Преобразование в сроку
    public String toString() {
        return "Линия от " + start + " до " + end;
    }
}
