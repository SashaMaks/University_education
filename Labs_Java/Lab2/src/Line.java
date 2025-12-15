public class Line {
    private Point start;
    private Point end;

    // Конструкторы
    public Line() {
        this.start = new Point();
        this.end = new Point();
    }
    public Line(Point start, Point end) {
        this.start = start;
        this.end = end;
    }
    public Line(Line line) {
        this.start = line.start;
        this.end = line.end;
    }

    // Геттеры
    public Point getStart() {
        return start;
    }
    public Point getEnd() {
        return end;
    }

    // Сеттеры
    public void setStart(Point start) {
        this.start = start;
    }
    public void setStart(double x, double y) {
        this.start = new Point(x, y);
    }
    public void setEnd(Point end) {
        this.end = end;
    }
    public void setEnd(double x, double y) {
        this.end = new Point(x, y);
    }

    // Преобразование в сроку
    public String toString() {
        return "Линия от "+ start.toString() + " до " + end.toString();
    }
}
