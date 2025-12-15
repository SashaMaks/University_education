package ru.Maksimov.files;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class TextAnalyzer {
    // Метод для
    public Set<Character> analyzeText(String text) {
        String normalizedText = text.toLowerCase().trim();

        // Делим текст на слова по пробелам знакам препинания (цифры на всякий случай)
        List<String> words = new ArrayList<>();
        String[] wordArray = normalizedText.split("[\\s\\p{Punct}\\d]+");

        for (String word : wordArray) {
            if (!word.isEmpty()) {
                words.add(word);
            }
        }

        System.out.println("Найдено слов: " + words.size());
        System.out.println("Слова: " + words);

        // Мапы для хранения информации о символах
        Map<Character, Integer> charFrequency = new HashMap<>(); // символ и сколько слов
        Map<Character, String> charFirstWord = new HashMap<>(); // символ и первое слово

        for (String word : words) {
            Set<Character> uniqueChars = new HashSet<>();
            for (char c : word.toCharArray()) {
                uniqueChars.add(c);
            }

            for (char c : uniqueChars) {
                charFrequency.put(c, charFrequency.getOrDefault(c, 0) + 1);

                if (!charFirstWord.containsKey(c)) {
                    charFirstWord.put(c, word);
                }
            }
        }
        Set<Character> result = new TreeSet<>();
        for (Map.Entry<Character, Integer> entry : charFrequency.entrySet()) {
            if (entry.getValue() == 1) {
                result.add(entry.getKey());
            }
        }
        return result;
    }

    // Метод для чтения текста
    public static String readTextFromFile(String fileName) {
        String content = "";
        try {
            try (BufferedReader reader = new BufferedReader(
                    new InputStreamReader(new FileInputStream(fileName), "UTF-8"))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    content = content + line +"\n";
                }
            }
        } catch (IOException e) {
            System.out.println("Ошибка: " + e.getMessage());
            return "";
        }
        return content.trim();
    }
}
