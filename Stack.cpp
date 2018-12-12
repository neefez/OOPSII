//---------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Reverse Polish Notation Expression Evaluator
// Purpose: This file contains the definitions of the functions and
//          methods for the Stack class.
//---------------------------------------------------------------------

#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
   numItems = 0;
}

bool Stack::IsEmpty()
{
   return numItems == 0;
}

bool Stack::IsFull()
{
   return numItems == (MAXSTACK - 1);
}

StackInfoType Stack::Pop()
{
   if(Stack::IsEmpty())
      return NULL;
   else
   {
      numItems--;
      return s[numItems];
   }
}

void Stack::Push(StackInfoType item)
{
   if(Stack::IsFull())
      return;
   else
   {
      s[numItems] = item;
      numItems++;
   }
   return;
}

StackInfoType Stack::Top()
{
   if(Stack::IsEmpty())
      return NULL;
   else
      return s[numItems - 1];
}

int Stack::Size()
{
   return numItems;
}

//-------------------------------------------------------------------
// Testbed main
//-------------------------------------------------------------------
#ifdef _TESTING_STACK

int main()
{
   StackInfoType item;
   Stack s;

   cout << "Enter a list of numbers, ending with -1" << endl;

   cin >> item;

   while (item != -1)
   {
      s.Push(item);
      cin >> item;
   }

   if(s.IsFull())
      cout << "The stack is full." << endl;
   else
      cout << "The stack is not full." << endl;

   cout << "There are " << s.Size() << " items in the stack." 
        << endl;

   cout << "The last number you entered was " << s.Top() << endl;

   cout << "You entered, in reverse order:" << endl;
   while(!s.IsEmpty())
   {
      cout << s.Pop() << " ";
   }

   cout << endl;

   return 0;
}

#endif