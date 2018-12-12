//---------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Reverse Polish Notation Expression Evaluator
// Purpose: This file contains the definitions of the functions and
//          methods for the Queue class.
//---------------------------------------------------------------------

#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
   front = rear = count = 0;
}

void Queue::Enqueue(QueueInfoType item)
{
   q[rear] = item;
   rear = (rear + 1) % MAXQ;
   ++count;
   return;
}

QueueInfoType Queue::Dequeue()
{
   QueueInfoType item = q[front];
   front = (front + 1) % MAXQ;
   --count;
   return item;
}

QueueInfoType Queue::Last()
{
   if (rear == 0)
      rear = MAXQ;
   QueueInfoType item = q[rear - 1];
   rear--;
   count--;
   return item;
}

bool Queue::IsEmpty()
{
   return count == 0;
}

bool Queue::IsFull()
{
   return count == MAXQ;
}

void Queue::Clear()
{
   front = 0;
   rear = 0;
   count = 0;
   return;
}

int Queue::Size()
{
   return count;
}

void Queue::Print()
{
   int j = front;
   for (int i = 0; i < count; i++)
   {
      if (j == MAXQ)
         j = 0;
      cout << q[j] << " ";
      j++;
   }
   return;
} 


#ifdef _TESTING_QUEUE
//-------------------------------------------------------------------
// Testbed main for Queue.
//-------------------------------------------------------------------
int main()
{
   Queue q;
   cout << "Enter 5 values" << endl;
   QueueInfoType i1, i2, i3, i4, i5;
   cin >> i1 >> i2 >> i3 >> i4 >> i5;
   q.Enqueue(i1);
   q.Enqueue(i2);
   q.Enqueue(i3);
   q.Enqueue(i4);
   q.Enqueue(i5);
   if (!q.IsFull())
      cout << "The queue is not full." << endl;
   else
      cout << "The queue is full" << endl;
   cout << "You entered " << q.Size() << " integers." << endl;
   cout << "The last integer added was " << q.Last() << endl;
   cout << "The first integer added was " << q.Dequeue() << endl;
   cout << "The remaining integers are: ";
   q.Print();
   cout << endl;

   q.Clear();
   if (q.IsEmpty())
      cout << "Queue successfully cleared." << endl;
   else
      cout << "ERROR: Queue not cleared." << endl;

   cout << "end of testbed" << endl;
}
#endif