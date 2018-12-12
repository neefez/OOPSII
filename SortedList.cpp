#include "SortedList.h"

template<class ItemType>
bool SortedList<ItemType>::Insert(const ItemType& item)
{
   ItemType * x = new ItemType(item);
   Node * p = list;
   bool done = false;
   if (p == NULL)
   {
      list = new Node(x);
      return true;
   }
   else if (*p->data == *x)
   {
      done = true;
      delete x;
   }
   else if (*x < *p->data)
   {
      list = new Node(x, NULL, p);
      done = true;
   }
   while (p != NULL && !done)
   {
      if (p->next == NULL)
      {
         p->next = new Node(x);
         p->next->prev = p;
         done = true;
      }
      else if (*p->next->data < *x)
      {
         p = p->next;
      }
      else if (*p->next->data == *x)
      {
         delete x;
         done = true;
      }
      else
      {
         p->next->prev = new Node(x, p, p->next);
         p->next = p->next->prev;
         return true;
      }
   }
   return false;
}

template<class ItemType>
bool SortedList<ItemType>::Delete(const ItemType& item)
{
   if (list == NULL)
      return false;

   Node * current = list;

   if (*list->data == item)
   {
      current = list;
      list->next->prev = NULL;
      list = list->next;
      delete current;
      return true;
   }

   while (current->next != NULL)
   {
      if (*current->next->data == item)
      {
         Node * temp = current->next;
         if(temp->next != NULL)
            temp->next->prev = current;
         current->next = current->next->next;
         delete temp;
         return true;
      }
      else
         current = current->next;
   }
   return false;
}

template<class ItemType>
void SortedList<ItemType>::Print()
{
   int i = 1;
   Node * p = list;
   while (p != NULL)
   {
      cout << "Node " << i << ": " << *p->data << endl;
      p = p->next;
      i++;
   }
}

template<class ItemType>
SortedList<ItemType>::~SortedList()
{
   Node * p = list;
   while (list != NULL)
   {
      list = list->next;
      delete p;
      p = list;
   }
   list = NULL;
}

template<class ItemType>
SortedList<ItemType>::SortedList(const SortedList& sl)
{
   *list = *sl.list;
}

template<class ItemType>
SortedList<ItemType>& SortedList<ItemType>::operator=(const SortedList& rhs)
{
   if (this != &rhs)
   {
      *list = *rhs.list;
   }
   return *this;
}

void main()
{
   SortedList<char> list;
   char ch;
   cin.get(ch);
   while (ch != '\n')
   {
      list.Insert(ch);
      cin.get(ch);
   }
   list.Print();
   while (cin)
   {
      cout << "Which one do you want to delete?" << endl;
      cin.get(ch);
      cin.ignore(100, '\n');
      list.Delete(ch);
   }
   list.Print();

   SortedList<float> list2;
   list2.Insert(3.14);
   list2.Delete(2.17);
   list2.Print();
   return;
}