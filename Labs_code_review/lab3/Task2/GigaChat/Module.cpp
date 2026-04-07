#include "Header.h"

//FIX_ME: функция для проверки, что это число 
bool is_number(const std::string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

//FIX_ME: Функция для проверки корректности постфиксного выражения
bool is_valid_prefix(const std::vector<int>& tokens) {
    if (tokens.empty()) return false;

    std::stack<int> st;

    // Идем с конца к началу (для префиксной записи)
    for (int i = tokens.size() - 1; i >= 0; i--) {
        int token = tokens[i];

        if (token >= 0 && token <= 9) {
            // Число - кладем в стек
            st.push(1); // 1 означает "один операнд"
        }
        else {
            // Оператор - требует 2 операнда
            if (st.size() < 2) {
                return false; // Недостаточно операндов
            }
            // Забираем 2 операнда, кладем 1 результат
            st.pop();
            st.pop();
            st.push(1);
        }
    }
    // В конце должен остаться ровно 1 результат
    return st.size() == 1;
}

//FIX_ME: переименование под вид lower_case_with_underscores
//std::vector<int> readExpression(const std::string& filename) {
std::vector<int> read_expression(const std::string& filename) {
    std::ifstream file(filename);
    //FIX_ME: отсутствует проверка на то что файл открылся
    if (!file.is_open()) {
        std::cerr << "Error: failed to open file '" << filename << "'\n";
        return {};
    }
    std::vector<int> tokens;
    std::string token;
    while (file >> token) {
        if (token == "+") tokens.push_back(-1);
        else if (token == "-") tokens.push_back(-2);
        else if (token == "*") tokens.push_back(-3);
        else if (token == "/") tokens.push_back(-4);
        else if (token == "%") tokens.push_back(-5);
        else if (token == "^") tokens.push_back(-6);
        //FIX_ME: если мы ввели не цифру, то будет ошибка
        //else tokens.push_back(stoi(token));
        else if (is_number(token)) {
            int num = stoi(token);
            if (num < 0 || num > 9) {
                std::cerr << "Error: number " << num << " out of range 0-9\n";
                return {};
            }
            tokens.push_back(num);
        }
        else {
            std::cerr << "Error: invalid token '" << token << "'\n";
            return {};
        }
    }
    //FIX_ME: перенесем из main в функцию
    if (tokens.empty()) {
        std::cerr << "Error: file is empty\n";
        return {};
    }

    // Проверка корректности постфиксного выражения
    if (!is_valid_prefix(tokens)) {
        std::cerr << "Error: invalid postfix expression (wrong number of operands)\n";
        return {};
    }

    return tokens;
}

//FIX_ME: переименование под вид lower_case_with_underscores
//Node* buildTree(std::vector<int>& tokens, int& pos) {
Node* build_tree(std::vector<int>& tokens, int& pos) {
    //FIX_ME: нет проверки на не полность подаваемого выражение
    if (pos >= tokens.size()) {
        std::cerr << "Error: unexpected end of expression (missing operands)\n";
        return nullptr;
    }

    int val = tokens[pos++];
    Node* node = new Node(val);
    if (val < 0) {
        node->left = build_tree(tokens, pos);
        node->right = build_tree(tokens, pos);
    }
    return node;
}

int compute(int op, int a, int b) {
    switch (op) {
    case -1: return a + b;
    case -2: return a - b;
    case -3: return a * b;
    case -4: return b != 0 ? a / b : 0;
    case -5: return b != 0 ? a % b : 0;
    case -6: return (int) pow(a, b);
    default: return 0;
    }
}

//FIX_ME: переименование под вид lower_case_with_underscores
//void printTree(Node* node) {
void print_tree(Node* node) {
    if (!node) {
        std::cout << "null";
        return;
    }

    // Если это лист (число), просто выводим значение
    if (node->value >= 0 && node->value <= 9) {
        std::cout << node->value;
        return;
    }

    // Если это операция, выводим скобки
    std::cout << "(";
    print_tree(node->left);

    // Выводим символ операции
    switch (node->value) {
    case -1: std::cout << " + "; break;
    case -2: std::cout << " - "; break;
    case -3: std::cout << " * "; break;
    case -4: std::cout << " / "; break;
    case -5: std::cout << " % "; break;
    case -6: std::cout << " ^ "; break;
    }

    print_tree(node->right);
    std::cout << ")";
}

Node* simplify(Node* node) {
    if (!node) return nullptr;
    node->left = simplify(node->left);
    node->right = simplify(node->right);

    // Если оба потомка — числа, вычисляем результат
    if (node->left && node->right &&
        node->left->value >= 0 && node->left->value <= 9 &&
        node->right->value >= 0 && node->right->value <= 9) {

        int result = compute(node->value, node->left->value, node->right->value);
        if (result >= 0 && result <= 9) {
            // Освобождаем память под потомков
            delete node->left;
            delete node->right;
            node->value = result;
            node->left = node->right = nullptr;
        }
    }
    return node;
}

// FIX_ME: бессмысленная функция для вывода и так имеющегося значения
/*void printRootPointer(Node* root) {
    std::cout << root << '\n';
}*/

//FIX_ME: переименование под вид lower_case_with_underscores
//void freeTree(Node* node) {
void free_tree(Node* node) {
    if (!node) return;
    free_tree(node->left);
    free_tree(node->right);
    delete node;
}

//FIX_ME: две бессмысленные функции с одинаковым функционалом
/*
void printTreeBefore(Node* root) {
    std::cout << "Дерево до упрощения:" << '\n';
    printTree(root);
    std::cout << "\n\n";
}

void printTreeAfter(Node* root) {
    std::cout << "Дерево после упрощения:\n";
    printTree(root);
    std::cout << "\n\n";
}*/