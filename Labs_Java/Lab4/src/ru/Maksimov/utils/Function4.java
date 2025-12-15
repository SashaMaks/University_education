package ru.Maksimov.utils;

import java.util.*;

public class Function4 {
    public static <T, P> List<P> function(List<T> list, Function<T, P> function) {
        List<P> out = new ArrayList<>();
        for (T item : list) {
            out.add(function.apply(item));
        }
        return out;
    }
}