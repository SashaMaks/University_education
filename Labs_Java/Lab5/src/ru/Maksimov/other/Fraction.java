package ru.Maksimov.other;

import java.util.Objects;

public class Fraction{
    private int numerator;
    private int denominator;

    // Конструкторы
    public Fraction() { this.numerator = 0; this.denominator = 1; }
    public Fraction(int numerator, int denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
        simplification();
    }

    // Геттеры
    public int getNumerator() { return numerator; }
    public int getDenominator() { return denominator; }
    public double getDouble() { return numerator / denominator; }

    // Сеттер
    public void setFraction(int numerator, int denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
        simplification();
    }
    public void setNumerator(int numerator) {
        this.numerator = numerator;
    }
    public void setDenominator(int denominator) {this.denominator = denominator;}
    public void setFraction(Fraction fraction) {
        this.numerator = fraction.getNumerator();
        this.denominator = fraction.getDenominator();
        simplification();
    }

    // Сравнение дробей
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass() ) {
            return false;
        }
        Fraction fraction = (Fraction) obj;
        return this.numerator == fraction.numerator && this.denominator == fraction.denominator;
    }

    // Упрощение и сокращение дроби
    public void simplification(){
        if (denominator < 0){
            numerator = -numerator;
            denominator = -denominator;
        }

        int a = Math.abs(numerator);
        int b = Math.abs(denominator);
        while (b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        int shorten = a;
        numerator /= shorten;
        denominator /= shorten;

    }

    // Преобразование в сроку
    public String toString() { return numerator + "/" + denominator; }

    // Кэширование вещественного числа
    public int hashDouble() { return Objects.hash(this.getDouble()); }
}