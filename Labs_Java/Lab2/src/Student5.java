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
    public int[] getGradesNoLinks() {
        int[] copy = new int[grades.length];
        System.arraycopy(grades, 0, copy, 0, grades.length);
        return copy;
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
            grades[index] = grade;
        }
    }

    // Метод для нахождения средней оценки студента
    public double AveregeGrade() {
            double sum = 0;
            for (int i = 0; i < this.grades.length; i++) {
                sum += this.grades[i];
            }
            sum = sum / this.grades.length;
            return sum;
    }

    // Метод для определения, отличник студент или нет
    public boolean isExcellent() {
        if (this.grades.length == 0) {
            return false;
        } else {
            if (this.AveregeGrade() != 5) {
                return false;
            }
            return true;
        }
    }

    // Преобразование в сроку
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