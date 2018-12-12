//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Maintain and Manipulate a Catalog of Fruit products
// Purpose: Catalog contains the linked list of products and handles
//          user input by calling various methods.
//-------------------------------------------------------------------

#ifndef _CATALOG_H
#define _CATALOG_H
#include <iostream>
#include "LList.h"
using namespace std;

class Catalog
{
private:
   int numInputs;      //inputted by user at outset of program
   LList FruitCatalog; //contains an updated list of fruit

   //----------------------------------------------------------------
   // Reads in a fruit from the user and inserts it into the linked
   // list if not already in it. Outputs wheter added or not.
   //----------------------------------------------------------------
   bool InsertItem();

   //----------------------------------------------------------------
   // Reads in a fruit from the user and deletes it from the list
   // if it is in the list. Outputs whether it was successfully
   // deleted or not.
   //----------------------------------------------------------------
   bool DeleteItem();

   //----------------------------------------------------------------
   // Prints out a header for the display followed by the display of
   // the linked list.
   //----------------------------------------------------------------
   void Print();
public:
   //----------------------------------------------------------------
   // Contains the main body for the program. Handles user input
   // and calls the other methods when necessary.
   //----------------------------------------------------------------
   void Run();
};
#endif