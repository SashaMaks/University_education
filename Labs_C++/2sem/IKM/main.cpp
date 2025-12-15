#include "module.h"
#include "module.cpp"

int main() {
  SetConsoleOutputCP(CP_UTF8);
  setlocale(LC_ALL, "ru_RU.UTF-8");


  std::string inputFilename = "C:\\Users\\Public\\Documents\\2sem\\IKM\\IKM.txt";

  std::ifstream inFile(inputFilename);
  if (!inFile) {
    std::cerr << "Ошибка открытия файла для чтения!\n" << std::endl;
    return 1;
  }

  std::string polyStr;
  std::getline(inFile, polyStr);
  inFile.close();

  PNode* poly = nullptr;
  try {
    poly = parse(polyStr);
  }
  catch (const PolynomialParseException &e) {
    std::cerr << "Ошибка разбора многочлена: " << e.what() << std::endl;
    return 1;
  }

  poly = sort(poly);
  poly = combineLikePNodes(poly);
  
  std::string polyOut = polynomialToString(poly);
  
  std::ofstream outFile(inputFilename, std::ios::app);
  if (!outFile) {
    std::cerr << "Ошибка открытия файла для дозаписи!" << std::endl;
    freePolynomial(poly);
    return 1;
  }

  outFile << "\nРезультирующий многочлен: " << polyOut << "\n";
  outFile.close();

  freePolynomial(poly);

  std::cout << "Многочлен успешно обработан и записан в файл." << std::endl;
  return 0;
}
