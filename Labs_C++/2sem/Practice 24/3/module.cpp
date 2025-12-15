static int normalizeKey(int key) {
  key %= 26;
  if (key < 0) {
    key += 26;
  }
  return key;
}

//Шифровка
std::string CaesarCipher::encrypt(const std::string &text, int key) {
  std::string result;
  int shift = normalizeKey(key);

  for (char c : text) {
    if (c >= 'A' && c <= 'Z') {
      char shifted = ((c - 'A' + shift) % 26) + 'A';
      result.push_back(shifted);
    }
    else if (c >= 'a' && c <= 'z') {
      char shifted = ((c - 'a' + shift) % 26) + 'a';
      result.push_back(shifted);
    }
    else {
      result.push_back(c);
    }
  }
  return result;
}

// Для дешифрования достаточно зашифровать сдвигом, равным -key.
std::string CaesarCipher::decrypt(const std::string &text, int key) {
  return encrypt(text, -key);
}