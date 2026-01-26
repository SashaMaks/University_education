package ru.Maksimov.other;

import java.util.*;

public class PhoneDirectory {
    private Map<String, String> contacts;

    // Конструкторы
    public PhoneDirectory() {
        this.contacts = new HashMap<>();
    }
    public PhoneDirectory(String name, String phone) {
        if (name == null || phone == null) {
            throw new IllegalArgumentException("Имя или телефон не могут быть пустыми");
        } else {
            this.contacts = new HashMap<>();
            this.contacts.put(name, phone);
        }
    }

    // Геттеры
    public String getPhone(String name) {
        return contacts.get(name);
    }
    public String[] getNamesStarting(String start) { // Массив всех имен, которые начинаются на данный в метод префикс
        if (start == null) return new String[0];

        List<String> matchingNames = new ArrayList<>();
        for (String name : contacts.keySet()) {
            if (name.startsWith(start)) {
                matchingNames.add(name);
            }
        }
        return matchingNames.toArray(new String[0]);
    }
    public int getContactsCount() {
        return contacts.size();
    }


    // Добавление новой пары “телефон – имя” || или замена номера у имени
    public String addContact(String name, String phone) {
        if (name == null || phone == null) {
            throw new IllegalArgumentException("Имя или телефон не могут быть пустыми");
        } else if (containPhone(phone)) {
            System.out.println("Телефон " + phone + " уже был!");
            return "";
        } else {

            if (containName(name)) {
                System.out.println("Имя " + name + " уже было в справочнике, переписываем его номер на новый");
            }
            String oldPhone = contacts.get(name);
            contacts.put(name, phone.trim());
            return "Старый телефон человека " + name + ": " + oldPhone;
        }
    }

    // Проверки на наличие имени и телефона в справочнике
    public boolean containName(String name) {
        return contacts.containsKey(name);
    }
    public boolean containPhone(String phone) {
        return contacts.containsValue(phone);
    }

    // Удалить пару “телефон – имя” по имени
    public void deletePair(String name) {
        contacts.remove(name);
    }

    // Запросы в виде массива
    public String[] AllPhones() {
        return contacts.values().toArray(new String[0]);
    }
    public String[] AllNames() {
        return contacts.keySet().toArray(new String[0]);
    }
    public String[][] AllPairs() {
        String[][] pairs = new String[contacts.size()][2];
        int i = 0;
        for (Map.Entry<String, String> entry : contacts.entrySet()) {
            pairs[i][0] = entry.getKey();
            pairs[i][1] = entry.getValue();
            i++;
        }
        return pairs;
    }

    // Преобразование в строку
    public String toString() {
        String sb = "";
        for (var entry : contacts.entrySet()) {
            sb = sb + (entry.getValue()) + (" - ") + (entry.getKey()) + ("\n");
        }
        return sb;
    }
}
