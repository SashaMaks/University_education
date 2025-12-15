package ru.Maksimov.other;

import ru.Maksimov.utils.Comparable;

public class Student implements Comparable<Student> {
    private String name;
    private int[] grades;

    // Конструкторы
    public Student(String name) {
        this.name = name;
        this.grades = new int[0];
    }
    public Student(String name, int... grades) {
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
    public double getAverageGrade() {
        if (grades.length == 0) return 0;

        int sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        return (double) sum / grades.length;
    }

    // Обязательный метод из интерфейса для сравнения
    public int compare(Student student) {
        double thisAverage = this.getAverageGrade();
        double otherAverage = student.getAverageGrade();

        if (thisAverage > otherAverage) {
            return 1;
        } else if (thisAverage < otherAverage) {
            return -1;
        } else {
            return 0;
        }
    }

    // Преобразование в строку
    public String toString() {
        String out = name + ": [";

        for (int i = 0; i < grades.length; i++) {
            out = out + grades[i];
            if (i < grades.length - 1) {
                out = out + ", ";
            }
        }
        out = out + "]";
        return out;
    }
}