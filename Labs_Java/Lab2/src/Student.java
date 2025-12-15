class Student {
    private String name;
    private int[] grades;

    // Конструктор
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

    // Преобразование в строку
    public String toString() {
        String out = name + ": [";

        for (int i = 0; i < grades.length; i++) {
            out = out + this.grades[i];
            if (i < grades.length - 1) {
                out = out + ", ";
            }
        }
        out = out + "]";
        return out;
    }
}