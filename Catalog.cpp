//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Maintain and Manipulate a Catalog of Fruit products
// Purpose: This file implements the methods and functions for
//          the Catalog class.
//-------------------------------------------------------------------

#include "Catalog.h"
#include "LeakWatcher.h"

void Catalog::Run()
{  
   cin >> numInputs;
   cout << "There are " << numInputs << " types of fruits "
        << "initially in the list." << endl;
   cout << "They will be read in and inserted in the "
        << "list in order." << endl;
   
   Fruit * f = 0;
   for (int i = 0; i < numInputs; i++)
   {
      f = new Fruit;
      cin >> *f;
      FruitCatalog.Insert(f);
      cout << "Added to list:     " << *f;
      f = 0;
   }
   cout << endl;

   bool done = false;
   char command = 0;
   cin >> command;

   while (!done)
   {
      if (command == 'I')
         InsertItem();
      else if (command == 'D')
         DeleteItem();
      else if (command == 'P')
         Print();
      else if (command == 'S')
      {
         cout << "Normal Termination of program 2!" << endl;
         done = true;
      }
      else
         cout << "Invalid command!" << endl << endl;
      
      cin >> command;
   }
   return;
}

bool Catalog::InsertItem()
{
   Fruit * f = new Fruit;
   cin >> *f;
   bool inserted = FruitCatalog.Insert(f);
   if (inserted)
      cout << "Added to list:     " << *f << endl;
   else
   {
      cout << "Already in list:   " << *f << endl;
      delete f;
   }
   f = 0;
   return inserted;
}

bool Catalog::DeleteItem()
{
   Fruit f;
   cin >> f;
   Fruit f2 = f;
   bool deleted = FruitCatalog.Delete(f);
   if (deleted)
      cout << "Deleted from list: " << f2 << endl;
   else
      cout << "Wasn't in list:    " << f2 << endl;
   return deleted;
}

void Catalog::Print()
{
   cout << "Below are the fruits currently in the list" << endl;
   FruitCatalog.Display(cout);
   cout << endl;
}
