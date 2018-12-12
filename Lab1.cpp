#include <iostream>
using namespace std;

const int MAX_INTEGERS = 100;

int main()
{
   int input[MAX_INTEGERS];
   int less[MAX_INTEGERS];
   int numInput = 0;
   int numLess = 0;
   int total = 0;
   float average;

   cin >> input[numInput];
   numInput++;

   while (cin)
   {
      cin >> input[numInput];
	  numInput++;
   }

   numInput--;

   for (int i = 0; i < numInput; i++)
   {
      total = total + input[i];
   }

   average = float(total) / numInput;

   for (int j = 0; j < numInput; j++)
   {
      if(input[j] < average)
	  { 
         less[numLess] = input[j];
		 numLess++;
      }
   }

   cout << numLess << endl;

   return 0;
}