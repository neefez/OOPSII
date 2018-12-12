//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Maintain and Manipulate a Catalog of Fruit products
// Purpose: Fruit has a name and a PLU code associated with it. Fruit
//          can be compared to each other in various ways.
//-------------------------------------------------------------------

#ifndef _FRUIT_H
#define _FRUIT_H
//#define _TESTING_FRUIT

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
enum { CODE_LEN = 4 };
enum { MAX_NAME_LEN = 30 };

class Fruit
{
private:
   char *name;
   char code[CODE_LEN];
public:
   //----------------------------------------------------------------
   // Default constructor for Fruit, sets name to be empty.
   //----------------------------------------------------------------
   Fruit();

   //----------------------------------------------------------------
   // Deletes the name pointer in the fruit.
   //----------------------------------------------------------------
   ~Fruit();

   //----------------------------------------------------------------
   // Copy constructor; constructs a new fruit object from an 
   // existing one.
   //----------------------------------------------------------------
   Fruit(const Fruit& f);

   //----------------------------------------------------------------
   // Sets the called fruit to the same as the parameterized fruit.
   //----------------------------------------------------------------
   Fruit& operator=(const Fruit &rhs);

   //----------------------------------------------------------------
   // Returns true if the name of the called fruit comes before
   // the name of the parameterized fruit alphabetically, else false.
   //----------------------------------------------------------------
   bool operator<(const Fruit &rhs);

   //----------------------------------------------------------------
   // Returns true if the name of the called fruit is the same as
   // the name of the parameterized fruit, else false.
   //----------------------------------------------------------------
   bool operator==(const Fruit &rhs);

   //----------------------------------------------------------------
   // Returns false if the name of the called fruit is the same as
   // the name of the parameterized fruit, else true.
   //----------------------------------------------------------------
   bool operator!=(const Fruit &rhs);

   //----------------------------------------------------------------
   // Returns the fruit information properly formatted for output.
   //----------------------------------------------------------------
   friend ostream& operator<<(ostream& out, Fruit& f);

   //----------------------------------------------------------------
   // Properly parses inputted information to make a new fruit with.
   //----------------------------------------------------------------
   friend istream& operator>>(istream& in, Fruit& f);
};
#endif