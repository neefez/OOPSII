// Lab 11
// heap sort a deque of Person pointers in descending order

#include <iostream>
#include <deque>
#include "Person.h"
using namespace std;


// Do1: write the heap sort in DESCENDING order. 
// Add additional functions if necessary
template <class T>
void HeapSortDescending(deque<T*> & nodes, int size)
{
   int index;
   for (index = size / 2 - 1; index >= 0; index--)
      ReheapDown(nodes, index, size);
   for (index = size - 1; index >= 1; index--)
   {
      swap(nodes[0], nodes[index]);
      ReheapDown(nodes, 0, index);
   }
}

void ReheapDown(deque<Person*> & nodes, int root, int num)
{
   if (2 * root + 1 <= (num - 1))
   {
      int maxKid = 2 * root + 1;
      if ((2 * root + 2) <= (num - 1) &&
         (*nodes[2 * root + 2] < *nodes[maxKid]))
         maxKid = 2 * root + 2;
      if (*nodes[maxKid] < *nodes[root])
      {
         swap(nodes[root], nodes[maxKid]);
         ReheapDown(nodes, maxKid, num);
      }
   }
}

void swap(Person *& p1, Person *& p2)
{
   Person * temp = p1;
   p1 = p2;
   p2 = temp;
}

void main()
{
   deque<Person *> people;
   Person p;

   // Do2: write end of file loop to read in multiple persons and store in people.
   cin >> p;
   while (cin)
   {
      Person * pp = new Person(p);
      people.push_back(pp);
      cin >> p;
   }

   // print out the entire people
   for (int i = 0; i < people.size(); i++)
      cout << *people[i];

   // Do3: Use HeapSortDescending to sort people in age descending order
   HeapSortDescending(people, people.size());


   // print out the sorted people
   cout << "The sorted array is: " << endl;
   for (int i = 0; i < people.size(); i++)
      cout << *people[i];

   for (int i = 0; i < people.size(); i++)
      delete people[i];
}