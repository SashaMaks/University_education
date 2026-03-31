#ifndef Header_h
#define Header_h

#include <iostream>

struct TNode {
  // FIX_ME: некорректное название
  // int Znachenie;
  int data;

  // FIX_ME: некорректное название
  // TNode* Predydushiy;
  TNode* previous;

  // FIX_ME: некорректное название
  // TNode* Sleduyushiy;
  TNode* next;
};

// FIX_ME: некорректное название
//class Spisok {
class LinkedList {
private:
  // FIX_ME: некорректное название
  // TNode* PerviyElement;
  TNode* head;

public:
  // FIX_ME: некорректное название
  LinkedList();

  // FIX_ME: некорректное название
  //void Ochistka() {
  void clear();

  // FIX_ME: некорректное название 
  //void DobavitElement(int Znachenie) {
  void add(int value);

  // FIX_ME: некорректное название
  // void VivodSpiska() {
  void print();

  // FIX_ME: некорректное название
  // void PoiskMinMax(Uzel*& Min, Uzel*& Max) {
  void find_min_and_max(TNode*& min_node, TNode*& max_node);

  // FIX_ME: некорректное название
  // bool ProverkaPoryadka(TNode* A, TNode* B) {
  bool is_first_before_second(TNode* a, TNode* b);

  // FIX_ME: некорректное название
  // void VivodMezhduMinMax() {
  void print_between_min_max();

  // FIX_ME: нет деструктора
  ~LinkedList();
};

#endif
