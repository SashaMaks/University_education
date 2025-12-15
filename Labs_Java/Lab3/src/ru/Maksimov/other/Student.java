package ru.Maksimov.other;

public class Student {
    private String name;
    private int[] grades;

    // Конструкторы
    public Student(String name) {
        this.name = name;
        this.grades = new int[0];
    }
    public Student(String name, int[] grades) {
        this.name = name;
        this.grades = grades;
    }

    // Геттеры
    public String getName() {
        return name;
    }
    public int[] getGrades() {
        return grades;
    }

    // Сеттеры
    public void setName(String name) {
        this.name = name;
    }
    public void setGrades(int[] grades) {
        this.grades = grades;
    }

    // Преобразование в строку
    public String toString() {
        String out = name + ": [";

        for (int i = 0; i < grades.length; i++) {
            out = out + i;
            if (i < grades.length - 1) {
                out = out + ", ";
            }
        }
        out = out + "]";
        return out;
    }
}