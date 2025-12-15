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
Node* sortedListToBST(Node** head_ref, int n) {
  if(n <= 0) return nullptr;

  Node* left = sortedListToBST(head_ref, n/2);

  Node* root = *head_ref;

  root->prev = left;

  *head_ref = (*head_ref)->next;

  root->next = sortedListToBST(head_ref, n - n/2 - 1);

  return root;
}

// Функция вывода исходного двусвязного списка
void printList(Node* head) {
  cout << "Исходный двусвязный список:\n";
  while(head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << "\n\n";
}

// Функция вывода бинарного дерева на боку.
void printTree(Node* root, int indent = 0) {
  if(root == nullptr)
    return;

  printTree(root->next, indent + 8);

  if(indent)
    cout << setw(indent) << " ";
  cout << root->data << "\n";

  printTree(root->prev, indent + 8);
}