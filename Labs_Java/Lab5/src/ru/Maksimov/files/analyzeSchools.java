package ru.Maksimov.files;

import java.util.*;
import java.io.*;
import ru.Maksimov.utils.*;


public class analyzeSchools {

    // Вспомогательный класс Ученика
    public static class Student {
        private final String lastName;
        private final String firstName;
        private final int school;
        private final int score;

        // Конструктор
        public Student(String lastName, String firstName, int school, int score) {
            this.lastName = lastName;
            this.firstName = firstName;
            this.school = school;
            this.score = score;
        }

        // Геттеры
        public String getLastName() {
            return lastName;
        }
        public String getFirstName() {
            return firstName;
        }
        public int getSchool() {
            return school;
        }
        public int getScore() {
            return score;
        }

        // Вывод в строку
        public String toString() {
            return lastName + " " + firstName + " " + school + " " + score;
        }
    }

    // Вспомогательный класс по статистике школы
    private static class SchoolStats {
        private int totalScore = 0;
        private int studentCount = 0;

        public void addScore(int score) {
            totalScore += score;
            studentCount++;
        }

        // Геттеры
        public int getTotalScore() {
            return totalScore;
        }
        public int getStudentCount() {
            return studentCount;
        }

        // Среднее значение
        public double getAverage() {
            return studentCount > 0 ? (double) totalScore / studentCount : 0;
        }

        // Вывод в строку
        public String toString() {
            return "Всего баллов: "+ totalScore + "\nВсего учеников: "+ studentCount;
        }
    }

    // Читаем и проверяем данные из файлика
    public List<Student> loadDataFromFile(String fileName) throws IOException {
        List<Student> students = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            int lineNumber = 0;
            int expectedStudents = 0;

            // Читаем и проверяем первую строку - количество учеников
            line = reader.readLine();
            lineNumber++;
            if (line == null) {
                throw new IOException("Файл пуст");
            }
            line = line.trim();
            if (line.isEmpty()) {
                throw new IllegalArgumentException("Первая строка файла пуста");
            }
            try {
                expectedStudents = Integer.parseInt(line);
                if (expectedStudents < 5) {
                    throw new IllegalArgumentException("Количество учеников должно быть не менее 5");
                }
            } catch (NumberFormatException e) {
                throw new IllegalArgumentException("Первая строка должна содержать число - количество учеников");
            }
            System.out.println("Ожидается " + expectedStudents + " учеников");

            // Читаем данные учеников
            int studentsRead = 0;
            while ((line = reader.readLine()) != null && studentsRead < expectedStudents) {
                lineNumber++;
                line = line.trim();

                if (line.isEmpty()) {
                    continue;
                }

                Student student = parseStudent(line, lineNumber);
                if (student != null) {
                    students.add(student);
                    studentsRead++;
                } else {
                    // Если не смогли распарсить ученика, все равно считаем строку
                    studentsRead++;
                }
            }

            // Проверяем, что прочитали столько, сколько ожидали
            if (studentsRead < expectedStudents) {
                System.out.println("Внимание: прочитано " + studentsRead +
                        " учеников из " + expectedStudents + " ожидаемых");
            }

        } catch (FileNotFoundException e) {
            throw new IOException("Файл не найден!", e);
        }
        return students;
    }

    // Вспомогательный метод для деления строки из файлика на данные
    private Student parseStudent(String line, int lineNumber) {
        String[] parts = line.split("\\s+"); // Делим по всем пробелам строку

        if (parts.length != 4) {
            System.out.println("Ошибка в строке " + lineNumber +
                    ": неверный формат. Ожидается: Фамилия Имя Школа Балл");
            return null;
        }

        try {
            String lastName = Checks.checkStudentName(parts[0]);
            String firstName = Checks.checkStudentName(parts[1]);
            int school = Checks.checkSchoolNumber(parts[2]);
            int score = Checks.checkScore(parts[3]);

            return new Student(lastName, firstName, school, score);
        } catch (Exception e) {
            System.out.println("Ошибка в строке " + lineNumber + ": " + e.getMessage());
            return null;
        }
    }

    // Метод для обработки данных и подсчета данных требуемых в задании
    public List<Integer> analyze(List<Student> students) {
        if (students.isEmpty()) {
            System.out.println("Нет данных для анализа");
            return new ArrayList<>();
        }

        if (students.size() < 5) {
            System.out.println("Ошибка! Для точного анализа рекомендуется не менее 5 учеников");
        }

        // Вычисляем средний балл по всем ученикам (району)
        double districtAverage = calculateDistrictAverage(students);
        System.out.printf("Средний балл по району: "+ districtAverage+"\n");

        // Группируем учеников по школам и вычисляем средние баллы
        Map<Integer, Double> schoolAverages = calculateSchoolAverages(students);

        // Находим школы со средним баллом выше районного
        List<Integer> result = new ArrayList<>();

        for (Map.Entry<Integer, Double> entry : schoolAverages.entrySet()) {
            int school = entry.getKey();
            double schoolAverage = entry.getValue();

            if (schoolAverage > districtAverage) {
                result.add(school);
                System.out.printf("Школа " + school + ": средний балл " + schoolAverage + " (выше районного)\n");
            } else {
                System.out.printf("Школа " + school + ": средний балл " + schoolAverage + "\n");
            }
        }

        // Сортируем результат по номеру школы
        Collections.sort(result);

        return result;
    }

    // Вычисление среднего балла района
    private double calculateDistrictAverage(List<Student> students) {
        int totalScore = 0;
        for (Student student : students) {
            totalScore += student.getScore();
        }
        return (double) totalScore / students.size();
    }

    // Вычисление среднего балла школы
    private Map<Integer, Double> calculateSchoolAverages(List<Student> students) {
        Map<Integer, SchoolStats> statsMap = new HashMap<>();

        // Собираем статистику по школам
        for (Student student : students) {
            int school = student.getSchool();
            SchoolStats stats = statsMap.computeIfAbsent(school, k -> new SchoolStats());
            stats.addScore(student.getScore());
        }

        // Вычисляем средние значения
        Map<Integer, Double> averages = new HashMap<>();
        for (Map.Entry<Integer, SchoolStats> entry : statsMap.entrySet()) {
            averages.put(entry.getKey(), entry.getValue().getAverage());
        }

        return averages;
    }
}
