#include "Header.h"

int main() {
    //FIX_ME: надо для верного отображения пусского языка
    setlocale(LC_ALL, "ru");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::string filename = "a.txt";

    std::vector<int> tokens = read_expression(filename);
    
    //FIX_ME: огранечитель для остановки дальнейшего вывода
    if (tokens.empty()) {
        return 1;
    }

    //FIX_ME: перенесем из main в функцию
    /*if (tokens.empty()) {
        std::cerr << "Файл пуст или не удалось прочитать выражение.\n";
        return 1;
    }*/

    int pos = 0;
    Node* root = build_tree(tokens, pos);

    //FIX_ME: огранечитель для остановки дальнейшего вывода
    if (!root || pos != tokens.size()) {
        if (root) free_tree(root);
        std::cerr << "Error: invalid expression structure\n";
        return 1;
    }

    // Вывод исходного дерева
    std::cout << "Дерево до упрощения:" << '\n';
    print_tree(root);
    std::cout << "\n\n";

    // Упрощение дерева
    root = simplify(root);

    // Вывод упрощенного дерева
    std::cout << "Дерево после упрощения:\n";
    print_tree(root);
    std::cout << "\n\n";

    // FIX_ME: бессмысленная функция для вывода и так имеющегося значения
    // printRootPointer(root);
    std::cout << root << '\n';

    // Освобождение памяти
    free_tree(root);

    return 0;
}