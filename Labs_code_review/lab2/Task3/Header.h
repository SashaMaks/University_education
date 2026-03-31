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

  //FIX_ME: переименование под вид lower_case_with_underscores
  //void insertSorted(int value);
  void insert_sorted(int value);

  void print();

  //FIX_ME: переименование под вид lower_case_with_underscores
  //void readFromFile(const std::string& filename);
  void read_from_file(const std::string& filename);

  friend void read_from_file(LinkedList& list, const std::string& filename);
};
//FIX_ME: переименование под вид lower_case_with_underscores
//void readFromFile(LinkedList& list, const std::string& filename);
void read_from_file(LinkedList& list, const std::string& filename);

//FIX_ME: функция, для чтения из файла
bool read_int_from_file(std::ifstream& file, int& value,
  const std::string& errorMsg);

#endif
