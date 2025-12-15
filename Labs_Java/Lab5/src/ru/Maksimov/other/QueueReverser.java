package ru.Maksimov.other;

import java.util.*;

public class QueueReverser {
    public static <T> Queue<T> reverseQueue(Queue<T> L1) {
        Queue<T> L2 = new LinkedList<>();

        // Создаем стек для временного хранения элементов
        Stack<T> stack = new Stack<>();

        // Перемещаем все элементы из L1 в стек
        while (!L1.isEmpty()) {
            stack.push(L1.poll());
        }

        // Перемещаем все элементы из стека в L2
        while (!stack.isEmpty()) {
            L2.add(stack.pop());
        }

        return L2;
    }
}
