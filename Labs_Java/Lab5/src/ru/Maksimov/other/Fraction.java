package ru.Maksimov.other;

import java.util.Objects;

public class Fraction{
    private int numerator;
    private int denominator;
    private Double cachedDoubleValue;

    // Конструкторы
    public Fraction() { this.numerator = 0; this.denominator = 1; this.cachedDoubleValue = null; }
    public Fraction(int numerator, int denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
        this.cachedDoubleValue = null;
        simplification();
    }

    // Геттеры
    public int getNumerator() { return numerator; }
    public int getDenominator() { return denominator; }
    public double getDouble() {
        if (cachedDoubleValue == null) {
            cachedDoubleValue = (double) numerator / denominator;
        }
        return cachedDoubleValue;
    }

    // Сеттер
    public void setFraction(int numerator, int denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
        this.cachedDoubleValue = null;
        simplification();
    }
    public void setNumerator(int numerator) {
        this.numerator = numerator;
    }
    public void setDenominator(int denominator) {
        this.denominator = denominator;
        this.cachedDoubleValue = null;
        simplification();
    }
    public void setFraction(Fraction fraction) {
        this.numerator = fraction.getNumerator();
        this.denominator = fraction.getDenominator();
        this.cachedDoubleValue = null;
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
        this.cachedDoubleValue = null;
    }

    // Преобразование в сроку
    public String toString() { return numerator + "/" + denominator; }
}