#include "module.h"
// Функция ручного заполнения
void my_lapki(PNode &p) {
  int N, k;
  std::cout << "Введите количество узлов в дереве:\n";
  std::cin >> N;

  std::cout << "Введите " << N << " узлов дерева:\n";
  for (int i = 1; i <= N; i++) {
    std::cin >> k;
    AddToTree(p, k);
  }
}
// Функция случайного заполнения
void my_rand(PNode &p) {
  srand(time(0));

  int n, k;
  std::cout << "Введите количество узлов в дереве:\n";
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    k = std::rand() % 100;
    AddToTree(p, k);
  }
}
// Функция заполнения из файла
void my_file(PNode &p) {
  int n,k;
  std::ifstream file("C:\\Users\\Public\\Documents\\2sem\\Practice 21\\2\\input.txt");

  file >> n;

  for (int i = 0; i < n; ++i) {
    file >> k;
    AddToTree(p, k);
  }
}

// Функция вставки элемента в бинарное дерево поиска
void AddToTree(PNode &Tree, int data) {
  if (!Tree) {
    Tree = new Node;
    Tree->key = data;
    Tree->left = nullptr;
    Tree->right = nullptr;
    return;
  }
  if (data < Tree->key)
    AddToTree(Tree->left, data);
  else
    AddToTree(Tree->right, data);
}

// Функция вывода дерева концевым (постфиксным) обходом
// (сначала левое поддерево, потом правое, затем текущий узел)
void Print(PNode Tree, int h)
{
  int i;
  if (Tree!=NULL)
  {
    Print(Tree->right, h + 1);
    for (i=1; i<=h; i++) std::cout<<"    ";
    std::cout<<Tree->key<<"\n\n";
    Print(Tree->left, h + 1);
  }
}