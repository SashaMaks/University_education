package ru.Maksimov.meowings;

public class MeowEverybody {
    public static void makeAllMeow(Meowing... meowables) {
        for (Meowing m : meowables) {
            m.meow();
            m.meow();
            m.meow();
        }
    }
}
