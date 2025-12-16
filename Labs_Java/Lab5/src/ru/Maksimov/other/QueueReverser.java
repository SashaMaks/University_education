package ru.Maksimov.other;

import java.util.*;

public class QueueReverser {
    public static <T> void reverseQueue(Queue<T> L1,Queue<T> L2) {
        if (L1.isEmpty()) {
            return;
        }
        T element = L1.poll();
        reverseQueue(L1, L2);
        L2.offer(element);
    }
}
