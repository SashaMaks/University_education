package ru.Maksimov.meowings;

import ru.Maksimov.utils.Checks;

public class Cat implements Meowing {
    private String name;
    private int meowCount;

    // Конструкторы
    public Cat(String name) {
        this.name = name;
        this.meowCount = 0;
    }
    public Cat(String name, int meowCount) {
        this.name = name;
        this.meowCount = meowCount;
    }

    // Геттеры
    public String getName()  { return name; }
    public int getMeowCount() { return meowCount; }

    // Сеттеры
    public void setName(String name) {
        this.name = name;
    }
    public void setMeowCount(int meowCount) {
        this.meowCount = meowCount;
    }

    // Метод мяуканья
    public void meow() {
        meowCount++;
        System.out.println(name + ": мяу!");
    }

    //Преобразование в сроку
    public String toString() { return "кот: " + name; }
}
