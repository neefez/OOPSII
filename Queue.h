//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Reverse Polish Notation Expression Evaluator
// Purpose: Queue is a class that holds objects in an array using a 
//          first in, first out system. So, items are added to the 
//          end of the array and removed from the front of the array.
//-------------------------------------------------------------------

#ifndef _QUEUE_H
#define _QUEUE_H
//#define _TESTING_QUEUE

typedef float QueueInfoType;

class Queue
{
private:
   static const int MAXQ = 80;
   int front, rear, count;
   QueueInfoType q[MAXQ];

public:
   //----------------------------------------------------------------
   // Default constructor for an instance of class Queue, sets all 
   // indices to 0.
   //----------------------------------------------------------------
   Queue();

   //----------------------------------------------------------------
   // Enqueues an object into the item array by placing it at the end
   // of the queue, also increments rear and count. The item 
   // parameter is the item being added to the queue.
   //----------------------------------------------------------------
   void Enqueue(QueueInfoType item);

   //----------------------------------------------------------------
   // Removes an object from the queue, returns it, increments front, 
   // and decrements count. The return is the object that is removed 
   // from the queue.
   //----------------------------------------------------------------
   QueueInfoType Dequeue();

   //----------------------------------------------------------------
   // Removes the last object that was added to the queue, and 
   // decrements rear and count. Used for checking the type of object
   // at the end of the queue. The return is the object at the end of
   // the queue.
   //----------------------------------------------------------------
   QueueInfoType Last();

   //----------------------------------------------------------------
   // Tells whether the queue is empty or not. Returns true if empty, 
   // false if not.
   //----------------------------------------------------------------
   bool IsEmpty();

   //----------------------------------------------------------------
   // Tells whether the queue is full or not. Returns true if full, 
   // false if not.
   //----------------------------------------------------------------
   bool IsFull();

   //----------------------------------------------------------------
   // Empties the queue by setting all indices to 0.
   //----------------------------------------------------------------
   void Clear();

   //----------------------------------------------------------------
   // Gives the number of items currently in the queue. Returns an 
   // integer, the number of object in the item array.
   //----------------------------------------------------------------
   int Size();

   //----------------------------------------------------------------
   // Returns a string of all the items in the queue for future 
   // output. The string contains information for all of the items in
   // the queue.
   //----------------------------------------------------------------
   void Print();
};

#endif