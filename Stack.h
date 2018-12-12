//---------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Reverse Polish Notation Expression Evaluator
// Purpose: The Stack class is used to hold various data. Stack is a
//          first in, first out system. The inputted data will be
//          pushed onto the stack and then popped back off in the
//          reverse order that they were pushed in.
//---------------------------------------------------------------------

#ifndef _STACK_H
#define _STACK_H
//#define _TESTING_STACK

typedef float StackInfoType;

class Stack
{
private:
   static const int MAXSTACK = 80;
   StackInfoType s[MAXSTACK];
   int numItems = 0;

public:
   //----------------------------------------------------------------
   // Default constructor for an instance of class Stack, sets the 
   // number of items in the stack to 0.
   //----------------------------------------------------------------
   Stack();

   //----------------------------------------------------------------
   // Tells whether the Stack is empty. Returns true if empty, false 
   // if not.
   //----------------------------------------------------------------
   bool IsEmpty();

   //----------------------------------------------------------------
   // Tells whether the Stack is full. Returns true if full, false 
   // if not.
   //----------------------------------------------------------------
   bool IsFull();

   //----------------------------------------------------------------
   // Removes an item from the end of the Stack and decrements the 
   // item count. Returns the object that is removed from the array.
   //----------------------------------------------------------------
   StackInfoType Pop();

   //----------------------------------------------------------------
   // Adds an item to the end of the stack and increments the number 
   // of items in the stack. The item parameter is the item to be 
   // added to the end of the array.
   //----------------------------------------------------------------
   void Push(StackInfoType item);

   //----------------------------------------------------------------
   // Looks at the item at the top of the Stack without removing it 
   // from the Stack. Returns the item at the end of the Stack.
   //----------------------------------------------------------------
   StackInfoType Top();

   //----------------------------------------------------------------
   // Gives the current number of items in the Stack. Return is an 
   // integer, the number of items in the array.
   //----------------------------------------------------------------
   int Size();
};

#endif