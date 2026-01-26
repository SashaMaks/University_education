package ru.Maksimov.utils;

import ru.Maksimov.geometry.Shape;

import java.util.Collection;

public class GeometryUtils {
    public static double calculateTotalArea(Collection<Shape> shapes) {
        if (shapes == null || shapes.isEmpty()) {
            return 0.0;
        }
        double totalArea = 0.0;
        for (Shape shape : shapes) {
            totalArea += shape.calculateArea();
        }
        return totalArea;
    }
}
