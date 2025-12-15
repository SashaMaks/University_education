#include "module.h"
#include "module.cpp"

int main() {
  SetConsoleOutputCP(CP_UTF8);
  setlocale(LC_ALL, "ru_RU.UTF-8");

  std::string text;
  std::cout << "Введите текст для кодирования: ";
  std::getline(std::cin, text);

  HuffmanCoding huffman(text);
  huffman.BuildTree();

  huffman.PrintCodes();
  huffman.PrintTree();

  int originalSize = huffman.CalculateOriginalSize();
  int huffmanSize = huffman.CalculateHuffmanSize();

  std::cout << "Размер сообщения при равномерном кодировании (ASCII 8 бит/символ): "
            << originalSize << " бит\n";
  std::cout << "Размер сообщения при кодировании Хаффмана: "
            << huffmanSize << " бит\n";
}
