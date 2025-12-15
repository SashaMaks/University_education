package ru.Maksimov.other;

import java.util.*;

public class ListOperation {
    // Метод для того чтобы брать строки из L1 которых нет в L2
    public static <T> List<T> getDifferenceSimple(List<T> L1, List<T> L2) {
        List<T> result = new ArrayList<>();
        for (T element : L1) {
            if (!contains(L2, element) && !contains(result, element)) {
                result.add(element);
            }
        }
        return result;
    }

    private static <T> boolean contains(List<T> list, T element) {
        for (T item : list) {
            if (Objects.equals(item, element)) {
                return true;
            }
        }
        return false;
    }
}
