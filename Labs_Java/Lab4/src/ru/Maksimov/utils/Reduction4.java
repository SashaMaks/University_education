package ru.Maksimov.utils;

import java.util.*;

public class Reduction4 {
    public static <T> T reduce(List<T> list, T initialValue, Reduction<T> reducer) {
        if (list == null || list.isEmpty()) {
            return initialValue;
        }
        T result = initialValue;
        for (T item : list) {
            result = reducer.reduce(result, item);
        }
        return result;
    }
}