//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <stack>
//#include <cmath>
//#include <cassert>
//
//using namespace std;
//
//// Структура узла дерева
//struct Node {
//    int value;       // Значение: число (0-9) или код операции (-1..-6)
//    Node* left;
//    Node* right;
//    Node(int v) : value(v), left(nullptr), right(nullptr) {}
//};
//
//// Чтение выражения из файла в вектор токенов
//vector<int> readExpression(const string& filename) {
//    ifstream file(filename);
//    vector<int> tokens;
//    string token;
//    while (file >> token) {
//        if (token == "+") tokens.push_back(-1);
//        else if (token == "-") tokens.push_back(-2);
//        else if (token == "*") tokens.push_back(-3);
//        else if (token == "/") tokens.push_back(-4);
//        else if (token == "%") tokens.push_back(-5);
//        else if (token == "^") tokens.push_back(-6);
//        else tokens.push_back(stoi(token));
//    }
//    return tokens;
//}
//
//// Рекурсивное построение дерева по префиксной записи
//Node* buildTree(vector<int>& tokens, int& pos) {
//    int val = tokens[pos++];
//    Node* node = new Node(val);
//    if (val < 0) { // это операция
//        node->left = buildTree(tokens, pos);
//        node->right = buildTree(tokens, pos);
//    }
//    return node;
//}
//
//// Вычисление значения узла
//int compute(int op, int a, int b) {
//    switch (op) {
//    case -1: return a + b;
//    case -2: return a - b;
//    case -3: return a * b;
//    case -4: return b != 0 ? a / b : 0; // защита от деления на 0
//    case -5: return b != 0 ? a % b : 0;
//    case -6: return pow(a, b);
//    default: return 0;
//    }
//}
//
//// Рекурсивная функция для вывода дерева в инфиксной форме
//void printTree(Node* node) {
//    if (!node) {
//        cout << "null";
//        return;
//    }
//
//    // Если это лист (число), просто выводим значение
//    if (node->value >= 0 && node->value <= 9) {
//        cout << node->value;
//        return;
//    }
//
//    // Если это операция, выводим скобки
//    cout << "(";
//    printTree(node->left);
//
//    // Выводим символ операции
//    switch (node->value) {
//    case -1: cout << " + "; break;
//    case -2: cout << " - "; break;
//    case -3: cout << " * "; break;
//    case -4: cout << " / "; break;
//    case -5: cout << " % "; break;
//    case -6: cout << " ^ "; break;
//    }
//
//    printTree(node->right);
//    cout << ")";
//}
//
//// Пост-обход: вычисление поддеревьев и замена на числа, если возможно
//Node* simplify(Node* node) {
//    if (!node) return nullptr;
//
//    // Сначала упрощаем поддеревья
//    node->left = simplify(node->left);
//    node->right = simplify(node->right);
//
//    // Проверяем, можно ли вычислить текущий узел
//    if (node->left && node->right &&
//        node->left->value >= 0 && node->left->value <= 9 &&
//        node->right->value >= 0 && node->right->value <= 9) {
//
//        int result = compute(node->value, node->left->value, node->right->value);
//
//        // Освобождаем память под потомков
//        delete node->left;
//        delete node->right;
//
//        // Заменяем узел на результат вычисления
//        node->value = result;
//        node->left = nullptr;
//        node->right = nullptr;
//    }
//    return node;
//}
//
//// Вывод указателя на корень (адрес в памяти)
//void printRootPointer(Node* root) {
//    cout << root << endl;
//}
//
//// Освобождение памяти дерева
//void freeTree(Node* node) {
//    if (!node) return;
//    freeTree(node->left);
//    freeTree(node->right);
//    delete node;
//}
//
//// Обёртка для печати дерева до упрощения
//void printTreeBefore(Node* root) {
//    cout << "Дерево до упрощения:" << endl;
//    printTree(root);
//    cout << endl << endl;
//}
//
//// Обёртка для печати дерева после упрощения
//void printTreeAfter(Node* root) {
//    cout << "Дерево после упрощения:" << endl;
//    printTree(root);
//    cout << endl << endl;
//}
//
//int main() {
//    string filename;
//    cout << "Введите имя файла: ";
//    cin >> filename;
//
//    vector<int> tokens = readExpression(filename);
//    if (tokens.empty()) {
//        cerr << "Файл пуст или не удалось прочитать выражение." << endl;
//        return 1;
//    }
//
//    int pos = 0;
//    Node* root = buildTree(tokens, pos);
//
//    // Вывод исходного дерева
//    printTreeBefore(root);
//
//    // Упрощение дерева
//    root = simplify(root);
//
//    // Вывод упрощенного дерева
//    printTreeAfter(root);
//
//    // Вывод указателя на корень (как было в оригинале)
//    printRootPointer(root);
//
//    // Освобождение памяти
//    freeTree(root);
//
//    return 0;
//}