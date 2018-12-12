//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Maintain and Manipulate a Catalog of Fruit products
// Purpose: This file contains the method definitions for the
//          linked list class.
//-------------------------------------------------------------------

#include "LList.h"
#include "LeakWatcher.h"
typedef Fruit InfoType;

LList::~LList()
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

bool LList::IsEmpty() const
{
   if(list == NULL)
      return true;
   return false;
}

bool LList::Insert(InfoType * x_ptr)
{
   if (list == NULL)
   {
      list = new Node(x_ptr, NULL);
      return true;
   }

   Node * current = list;
   if (*x_ptr < *current->infoPtr)
   {
      list = new Node(x_ptr, current);
      return true;
   }

   while (current != NULL)
   {
      if (current->next == NULL)
      {
         Node * newNode = new Node(x_ptr, current->next);
         current->next = newNode;
         return true;
      }
      else if (*current->next->infoPtr < *x_ptr && 
          *x_ptr != *current->next->infoPtr)
      {
         current = current->next;
      }
      else if(*x_ptr == *current->next->infoPtr)
      {
         return false;
      }
      else
      {
         Node * newNode = new Node(x_ptr, current->next);
         current->next = newNode;
         return true;
      }
   }
   return false;
}

bool LList::Delete(const InfoType & x)
{
   if (list == NULL)
      return false;

   Node * current = list;
   
   if (*list->infoPtr == x)
   {
      current = list;    
      list = list->next;
      delete current;
      return true;
   }

   while (current->next != NULL)
   {
      if (*current->next->infoPtr == x)
      {
         Node * temp = current->next;
         current->next = current->next->next;
         delete temp;
         return true;
      }
      else
         current = current->next;
   }
   return false;
}

void LList::Display(ostream & out_stream) const
{
   Node * current = list;
   while (current != NULL)
   {
      out_stream << *current->infoPtr;
      current = current->next;
   }
   return;
}

//-------------------------------------------------------------------
// Testbed main
//-------------------------------------------------------------------
#ifdef _TESTING_LLIST

int main()
{
   LList stuff;
   if (stuff.IsEmpty())
      cout << "LList was properly initialized." << endl;
   else
      cout << "LList wasn't properly initialized." << endl;

   Fruit * f = new Fruit;

   cout << "Enter fruit information." << endl;
   cin >> *f;

   stuff.Insert(f);
   cout << "The following fruit was added to the list:" << endl;
   stuff.Display(cout);

   stuff.Delete(*f);

   if (stuff.IsEmpty())
      cout << "Fruit was properly deleted." << endl;
   else
      cout << "Fruit wasn't properly deleted." << endl;
}

#endif