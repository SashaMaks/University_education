package ru.Maksimov.other;

import ru.Maksimov.geometry.Point3D;
import ru.Maksimov.utils.Checks;

public class Box<T> {
    private T content;

    //Конструкторы
    public Box() {
        this.content = null;
    }
    public Box(T item) {
        this.content = item;
    }

    // Геттер
    public T getContent() {
        T item = content;
        content = null; // обнуляем ссылку после извлечения
        return item;
    }

    // Сеттер
    public void setContent(T item) {
        if (content != null) {
            throw new IllegalStateException("Коробка уже занята! Сначала извлеките текущий объект.");
        }
        this.content = item;
    }

    // Проверка, заполнена ли коробка
    public boolean isFull() {
        return content != null;
    }

    public static <T> void inputPointInBox(Box<T> box) {
        System.out.println("Введите координату X:");
        double X = Checks.readDouble();
        System.out.println("Введите координату Y:");
        double Y = Checks.readDouble();
        System.out.println("Введите координату Z:");
        double Z = Checks.readDouble();

        Point3D point = new Point3D(X, Y, Z);
        try {
            T value = (T) point;
            System.out.println("Содержимое: " + box.toString());
            box.setContent(value);
            System.out.println("Положим в коробку точку: " + point.toString());
            System.out.println("Содержимое: " + box.toString());
            Object a = box.getContent();
            System.out.println("Вынем точку из коробки");
            Student student = new Student("Вася",2,3);
            System.out.println("Положим в коробку студента: " + student.toString());
            box.setContent((T) student);
            System.out.println("Содержимое: " + box.toString());
        } catch (Exception e) {
            System.out.println("Ошибка!");
        }
    }

    // Преобразование в строку
    public String toString() {
        if (content == null) {
            return "Коробка[пусто]";
        } else {
            return "Коробка[" + content.toString() + "]";
        }
    }
}