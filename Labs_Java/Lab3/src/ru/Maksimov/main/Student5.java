package ru.Maksimov.main;

class Student5 {
    private String name;
    private int[] grades;

    // Единственный конструктор который принимает и имя и оценки (ну или только имя)
    public Student5(String name, int... grades) {
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

    // Метод для нахождения средней оценки студента
    public double AveregeGrade() {
        if (this.grades.length == 0) {
            return 0;
        } else {
            double sum = 0;
            for (int i = 0; i < this.grades.length; i++) {
                sum += this.grades[i];
            }
            sum = sum / this.grades.length;
            return sum;
        }
    }

    // Метод для определения, отличник студент или нет
    public boolean isExcellent() {
        if (this.grades.length == 0) {
            return false;
        } else {
            for (int i = 0; i < this.grades.length; i++) {
                if (this.grades[i] != 5) {
                    return false;
                }
            }
            return true;
        }
    }

    // Вывод в строку
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