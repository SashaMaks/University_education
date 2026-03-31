#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>
#include <cctype>

//FIX_ME: переименование под вид lower_case_with_underscores
//bool IsNumber(const std::string& str);
bool is_number(const std::string& str);

class Queue {
private:
  //FIX_ME: переименование Node в TNode по условию задачи
  // struct Node {
  struct TNode {
    int data;
    TNode* next;
  };

  TNode* P1;
  TNode* P2;

public:
  Queue();

  void push(int num);

  void show();

  bool pop(int& num);

  //FIX_ME: переименование под вид lower_case_with_underscores
  //TNode* getP1() const;
  TNode* get_p1() const;

  //FIX_ME: переименование под вид lower_case_with_underscores
  //void getP1data() const;
  void get_p1_data() const;

  //FIX_ME: переименование под вид lower_case_with_underscores
  //void getP2data() const;
  void get_p2_data() const;

  //FIX_ME: переименование под вид lower_case_with_underscores
  //TNode* getP2() const;
  TNode* get_p2() const;

  //FIX_ME: переименование под вид lower_case_with_underscores
  //void EvenHead();
  void even_head();  // Извлечение элементов, пока не встретится четное значение

  ~Queue();

  // FIX_ME: очистка очереди
  void clear();
};

#endif