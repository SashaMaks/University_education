#ifndef Header_h
#define Header_h

#include <iostream>
#include <fstream>

//FIX_ME: переименование Node в TNode
//class Node {
class TNode {
public:
  int data;
  TNode* next;

  TNode(int value);
};

class LinkedList {
private:
  TNode* head;

public:

  LinkedList();

  void insertSorted(int value);

  void print();

  void readFromFile(const std::string& filename);

  friend void readFromFile(LinkedList& list, const std::string& filename);
};

void readFromFile(LinkedList& list, const std::string& filename);

bool read_int_from_file(std::ifstream& file, int& value,
  const std::string& errorMsg);

#endif