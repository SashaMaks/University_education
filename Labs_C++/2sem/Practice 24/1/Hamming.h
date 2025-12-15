#ifndef HAMMING_H
#define HAMMING_H

#include <iostream>
#include <string>
#include <string>

int computeParityCount(int m);

int* buildHammingCode(const std::string &data, int &total, int &r);

void printHammingCode(const int* code, int total);

void setParityBits(int* code, int total, int r);

void insertError(int* code, int total);

int detectError(const int* code, int total, int r);

void correctError(int* code, int errorPos);

#endif