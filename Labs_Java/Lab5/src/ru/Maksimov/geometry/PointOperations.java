package ru.Maksimov.geometry;

import java.util.*;

public class PointOperations {

    // Основной стрим для обработки точек
    public static Polyline processPointsWithStream(List<Point> points) {
        Point[] processedPoints = points.stream()
                .sorted(Comparator.comparingDouble(Point::getX)) // сортируем
                .map(Point::withPositiveY)
                .distinct()  // убираем одинаковые координаты
                .toArray(Point[]::new);
        return new Polyline(processedPoints);
    }
}
