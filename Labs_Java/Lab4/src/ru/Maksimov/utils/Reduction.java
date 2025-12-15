package ru.Maksimov.utils;

public interface Reduction <T> {
    T reduce(T accumulator, T element);
}
