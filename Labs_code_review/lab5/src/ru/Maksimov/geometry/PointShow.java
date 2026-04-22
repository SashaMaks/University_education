package ru.Maksimov.geometry;

import ru.Maksimov.utils.*;

public class PointShow {
    public static void main(String[] args) {
        System.out.println("Введите X: ");
        double point1X = Checks.readNumber();
        System.out.println("Введите Y: ");
        double point1Y = Checks.readNumber();

        Point p1 = new Point(point1X,point1Y);
        Point p2 = p1.clone();
        System.out.println(p2.toString());
    }
}
