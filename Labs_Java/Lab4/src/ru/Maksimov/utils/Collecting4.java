package ru.Maksimov.utils;

import java.util.*;

public class Collecting4 {
    public static <T, P> P collect(List<T> list, P collection, Collecting<T, P> collector) {
        for (T item : list) {
            collector.collect(collection, item);
        }
        return collection;
    }
}