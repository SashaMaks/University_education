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
        //FIX_ME: добавлена проверка корректности ввода внутри конструктора, а не внешним методом
        for (int grade : grades) {
            if (2 > grade || grade > 5) {
                throw new IllegalArgumentException("Оценка студента должна находиться в пределах от 2 до 5");
            }
        }
        this.grades = grades;
    }
    //FIX_ME: требуется конструктор, который создаст студента с n количеством оценок, но которые будут пустые
    public Student(String name, int count) {
        this.name = name;
        if  (count < 0) {
            throw new IllegalArgumentException("Нельзя ввести <0 оценок");
        }
        this.grades = new int[count];
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
    public void setGrade(int index, int grade) {
        if (index >= 0 && index < grades.length) {
            if (2 > grade || grade > 5) {
                throw new IllegalArgumentException("Оценка студента должна находиться в пределах от 2 до 5");
            }
            grades[index] = grade;
        } else {
            throw new IllegalArgumentException("Номера такой оценки нет");
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