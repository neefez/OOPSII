#pragma once
#include <iostream>
using namespace std;

template<class ItemType>
class SortedList
{
private:
   struct Node
   {
      Node(ItemType * x, Node * p1 = NULL, Node * p2 = NULL) { data = x;  prev = p1; next = p2; }
      ~Node() { delete data; }
      ItemType * data;
      Node * next;
      Node * prev;
   };
   Node * list;

public:
   SortedList() { list = NULL; }
   ~SortedList();
   SortedList(const SortedList& sl);
   SortedList& operator=(const SortedList& rhs);
   bool Insert(const ItemType& item);
   bool Delete(const ItemType& item);
   void Print();
};