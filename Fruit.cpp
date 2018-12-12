//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Maintain and Manipulate a Catalog of Fruit products
// Purpose: This file contains the definitions for the methods of
//          the Fruit class.
//-------------------------------------------------------------------

#include "Fruit.h"
#include "LeakWatcher.h"

Fruit::Fruit()
{
   name = NULL;
}

Fruit::~Fruit()
{
   if(name != NULL)
      delete[] name;  
   name = NULL;
}

Fruit::Fruit(const Fruit& f)
{
   char * str = new char[MAX_NAME_LEN + 1];
   strcpy_s(str, MAX_NAME_LEN, f.name);
   name = str;
   for (int i = 0; i < CODE_LEN; i++)
   {
      code[i] = f.code[i];
   }
}

Fruit& Fruit::operator=(const Fruit &rhs)
{
   if (this != &rhs)
   {
      delete[] name;
      char * str = new char[MAX_NAME_LEN + 1];
      strcpy_s(str, MAX_NAME_LEN, rhs.name);
      name = str;
      for (int i = 0; i < CODE_LEN; i++)
      {
         code[i] = rhs.code[i];
      }
   }
   return *this;
}

bool Fruit::operator<(const Fruit &rhs)
{
   return (strcmp(name, rhs.name) < 0);
}

bool Fruit::operator==(const Fruit &rhs)
{
   return (strcmp(name, rhs.name) == 0);
}

bool Fruit::operator!=(const Fruit &rhs)
{
   return !(strcmp(name, rhs.name) == 0);
}

ostream& operator<<(ostream& out, Fruit& f)
{
   out << setiosflags(ios::left) << setw(MAX_NAME_LEN + 1) << f.name;
   for (int i = 0; i < CODE_LEN; i++)
   {
      out << f.code[i]; 
   }
   out << endl;
   return out;
}

istream& operator>>(istream& in, Fruit& f)
{
   char* str = new char[MAX_NAME_LEN + 1];
   in >> str;
 
   for (int i = 0; i < CODE_LEN; i++)
   {
      in >> f.code[i];
   }
   
   f.name = str;
   return in;
}

//-------------------------------------------------------------------
// Testbed main
//-------------------------------------------------------------------
#ifdef _TESTING_FRUIT

int main()
{
   Fruit f;
   cout << "Enter fruit information:" << endl;
   cin >> f;
   Fruit * f2 = new Fruit;
   cout << "Enter another fruit:" << endl;
   cin >> *f2;

   Fruit f3(f);
   cout << "First fruit: " << f3;

   Fruit f4 = *f2;
   cout << "Second fruit: " << f4;

   Fruit f5;
   cout << "Enter another fruit:" << endl;
   cin >> f5;

   if (f3 == f4)
      cout << "First and second fruit are same." << endl;
   else
   {
      if (f3 < f4)
         cout << "First fruit is before second." << endl;
      else
         cout << "Second fruit is before first." << endl;
   }
   
   if (f5 != f3 && f5 != f4)
      cout << "Thrid fruit is different from the first two." << endl;
   else
      cout << "Third fruit has been inputted already." << endl;

   cout << "End of testbed." << endl;

   delete f2;
   return 0;
}
#endif