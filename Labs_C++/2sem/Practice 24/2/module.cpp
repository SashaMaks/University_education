// Рекурсивное освобождение памяти дерева
void HuffmanCoding::freeTree(HuffmanNode* node) {
  if (!node) return;
  freeTree(node->left);
  freeTree(node->right);
  delete node;
}

// Деструктор
HuffmanCoding::~HuffmanCoding() {
  freeTree(root);
}

// Конструктор
HuffmanCoding::HuffmanCoding(const std::string& text) : text(text), root(nullptr) {
  for (char ch : text) {
    frequencyMap[ch]++;
  }
}

// Построение дерева Хаффмана: создаем листья для каждого символа и объединяем их
void HuffmanCoding::BuildTree() {
  std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> pq;

  for (const auto& pair : frequencyMap) {
    pq.push(new HuffmanNode(pair.first, pair.second));
  }

  while (pq.size() > 1) {
    HuffmanNode* left = pq.top(); pq.pop();
    HuffmanNode* right = pq.top(); pq.pop();
    HuffmanNode* parent = new HuffmanNode('\0', left->freq + right->freq, left, right);
    pq.push(parent);
  }
  root = pq.top();

  GenerateCodes(root, "");
}

void HuffmanCoding::GenerateCodes(HuffmanNode* node, const std::string& code) {
  if (!node) return;

  if (node->ch != '\0') {
    huffmanCodes[node->ch] = code;
  }
  GenerateCodes(node->left, code + "0");
  GenerateCodes(node->right, code + "1");
}

// Вывод кодов для каждого символа
void HuffmanCoding::PrintCodes() const {
  std::cout << "Коды Хаффмана для символов:\n";
  for (const auto& pair : huffmanCodes) {
    std::cout << pair.first << ": " << pair.second << "\n";
  }
  std::cout << std::endl;
}

// Вычисление размера исходного сообщения (ASCII: 8 бит на символ)
int HuffmanCoding::CalculateOriginalSize() const {
  return text.size() * 8;
}

// Вычисление размера сообщения по коду Хаффмана
int HuffmanCoding::CalculateHuffmanSize() const {
  int size = 0;
  for (char ch : text) {
    size += huffmanCodes.at(ch).size();
  }
  return size;
}

// Вспомогательная функция для вывода дерева Хаффмана
// Если узел внутренний (ch == '\0'), выводим символ * и частоту.
void PrintHuffmanTree(HuffmanNode* node, int indent = 0) {
  if (!node) return;
  PrintHuffmanTree(node->right, indent + 4);
  std::cout << std::setw(indent) << "";
  if (node->ch == '\0')
    std::cout << "[*:" << node->freq << "]" << std::endl;
  else
    std::cout << "[" << node->ch << ":" << node->freq << "]" << std::endl;
  PrintHuffmanTree(node->left, indent + 4);
}

// Вывод дерева
void HuffmanCoding::PrintTree() const {
  std::cout << "Дерево кодирования Хаффмана:\n";
  PrintHuffmanTree(root);
  std::cout << std::endl;
}
