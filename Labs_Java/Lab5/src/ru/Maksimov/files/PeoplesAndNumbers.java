package ru.Maksimov.files;

import java.util.*;
import java.io.*;
import java.util.stream.Collectors;


public class PeoplesAndNumbers {
    // Дополнительный класс
    public static class Person {
        private String name;
        private Integer number;

        // Конструктор
        public Person(String name, Integer number) {
            this.name = name;
            this.number = number;
        }
        public Person(String name) {
            this.name = name;
            this.number = null;
        }

        // Геттеры
        public String getName() {
            return name;
        }
        public Integer getNumber() {
            return number;
        }
        public String getFormattedName() {
            if (name == null || name.isEmpty()) {
                return "";
            }
            return name.substring(0, 1).toUpperCase() +
                    name.substring(1).toLowerCase();
        }

        // Сеттеры
        public void setName(String name) {
            this.name = name;
        }
        public void setNumber(Integer number) {
            this.number = number;
        }

        //Преобразование в сроку
        public String toString() {
            return name + (number != null ? ":" + number : "");
        }

    }

    // Метод для обработки файла
    public static Map<Integer, List<String>> processFile(String filename) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            return reader.lines()
                    .map(String::trim)  // убираем лишние пробелы
                    .filter(line -> !line.isEmpty())  // убираем пустые строки
                    .map(PeoplesAndNumbers::parseLine)  // парсим строку
                    .filter(Objects::nonNull)  // убираем некорректные строки
                    .filter(person -> person.getNumber() != null)  // убираем без номеров
                    .collect(Collectors.groupingBy(
                            Person::getNumber,
                            Collectors.mapping(
                                    Person::getFormattedName,
                                    Collectors.toList()
                            )
                    ));
        }
    }

    // Метод для разбиения строки на имя и номер
    private static Person parseLine(String line) {
        try {
            String[] parts = line.split(":");
            if (parts.length == 0 || parts[0].trim().isEmpty()) {
                return null;
            }

            String name = parts[0].trim();
            Integer number = null;

            if (parts.length > 1 && !parts[1].trim().isEmpty()) {
                number = Integer.parseInt(parts[1].trim());
            }

            return new Person(name, number);
        } catch (Exception e) {
            return null;
        }
    }
}
