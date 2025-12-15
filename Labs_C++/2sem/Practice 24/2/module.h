#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <functional>
#include <windows.h>
#include <iomanip>

// Структура узла дерева Хаффмана
struct HuffmanNode {
  char ch;            // Cимвол
  int freq;           // Частота появления символа
  HuffmanNode* left;  // Левый ребенок
  HuffmanNode* right; // Правый ребенок

  HuffmanNode(char ch, int freq, HuffmanNode* left = nullptr, HuffmanNode* right = nullptr)
      : ch(ch), freq(freq), left(left), right(right) {}
};

// Компаратор для приоритетной очереди (узел с меньшей частотой имеет больший приоритет)
struct Compare {
  bool operator()(HuffmanNode* a, HuffmanNode* b) {
    return a->freq > b->freq;
  }
};

class HuffmanCoding {
 public:
  HuffmanCoding(const std::string& text);
  ~HuffmanCoding();

  void BuildTree();
  void GenerateCodes(HuffmanNode* root, const std::string& code);
  void PrintCodes() const;
  int CalculateOriginalSize() const;
  int CalculateHuffmanSize() const;
  void PrintTree() const;

 private:
  std::string text;
  HuffmanNode* root;
  std::unordered_map<char, int> frequencyMap;
  std::unordered_map<char, std::string> huffmanCodes;

  void freeTree(HuffmanNode* node);
};

#endif