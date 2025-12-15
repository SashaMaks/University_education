package ru.Maksimov.other;

import ru.Maksimov.utils.Comparable;

public class Number implements Comparable<Number> {
    private int number;

    // Конструктор
    public Number(int number) {
        this.number = number;
    }

    // Геттер
    public int getNumber() {
        return number;
    }

    // Сеттер
    public int setNumber() {
        return number;
    }

    // Обязательный метод из интерфейса для сравнения
    public int compare(Number other) {
        if (this.number > other.number) {
            return 1;
        } else if (this.number < other.number) {
            return -1;
        } else {
            return 0;
        }
    }

    // Преобразование в строку
    public String toString() {
        return "Число: " + number;
    }
}