#include <iostream>
#include <iomanip>
using namespace std;

// Структура узла двусвязного списка / бинарного дерева
struct Node {
  int data;
  Node* prev; // в списке — предыдущий элемент; в дереве — левый сын
  Node* next; // в списке — следующий элемент; в дереве — правый сын
};

Node* createDLL(int arr[], int n) {
  Node* head = nullptr;
  Node* tail = nullptr;
  for (int i = 0; i < n; i++) {
    Node* newNode = new Node;
    newNode->data = arr[i];
    newNode->prev = nullptr;
    newNode->next = nullptr;
    if (head == nullptr) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
  }
  return head;
}

// Подсчёт количества узлов в двусвязном списке
int countNodes(Node* head) {
  int count = 0;
  while(head) {
    count++;
    head = head->next;
  }
  return count;
}

// Рекурсивная функция, которая преобразует отсортированный двусвязный список в
// сбалансированное бинарное дерево поиска.
// Параметры:
//    head_ref — указатель на указатель на текущий узел списка,
//    n        — число узлов для включения в поддерево.
Node* sortedListToBST(Node** head_ref, int n) {
  if(n <= 0)
    return nullptr;

  // Построение левого поддерева из первых n/2 элементов
  Node* left = sortedListToBST(head_ref, n/2);

  // Узел, на который сейчас указывает *head_ref, становится корнем
  Node* root = *head_ref;

  // Связываем левое поддерево с корнем (используем поле prev для левого ребенка)
  root->prev = left;

  // Перемещаем указатель списка к следующему элементу
  *head_ref = (*head_ref)->next;

  // Построение правого поддерева из оставшихся узлов
  root->next = sortedListToBST(head_ref, n - n/2 - 1);

  return root;
}

// Функция вывода исходного двусвязного списка
void printList(Node* head) {
  cout << "Исходный двусвязный список:" << endl;
  while(head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << "\n" << endl;
}

// Функция вывода бинарного дерева на боку.
// Для узла используется поле prev как левый ребенок и next как правый.
void printTree(Node* root, int indent = 0) {
  if(root == nullptr)
    return;

  // Сначала выводим правое поддерево с отступом
  printTree(root->next, indent + 8);

  // Выводим текущий узел
  if(indent)
    cout << setw(indent) << " ";
  cout << root->data << "\n";

  // Затем выводим левое поддерево
  printTree(root->prev, indent + 8);
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(arr)/sizeof(arr[0]);

  Node* head = createDLL(arr, n);

  printList(head);

  int count = countNodes(head);

  Node* head_ref = head;
  Node* root = sortedListToBST(&head_ref, count);

  cout << "Преобразованное дерево (бинарное дерево поиска, на боку):\n";
  printTree(root);
}
