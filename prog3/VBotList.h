//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Bot Wars Visual C++ Program
// Purpose: VBotList is a class that contains a dynamic array of
//          VBot pointers. VBots can be added and removed from the
//          list, as well as updated.
//-------------------------------------------------------------------
#pragma once
#include "VBot.h"

const int SIZE = 100;
const int GAP = 20;

class VBotList
{
private:
   int size;
   VBot** list;
public:
   //----------------------------------------------------------------
   // Default constructor for the VBotList class. Initializes the
   // size to zero and makes an array of VBot pointers.
   //----------------------------------------------------------------
   VBotList();

   //----------------------------------------------------------------
   // Destructor for the VBotList class. Deletes all of the pointers
   // in the array.
   //----------------------------------------------------------------
   ~VBotList();

   //----------------------------------------------------------------
   // Adds a given VBot to the array. Increments size by 1.
   //----------------------------------------------------------------
   void Add(VBot* bot){ list[size++] = bot; }

   //----------------------------------------------------------------
   // Finds and deletes a given VBot from the array. Decrements size
   // by 1. Returns false if the VBot wasn't in the array.
   //----------------------------------------------------------------
   bool Delete(VBot* bot);

   //----------------------------------------------------------------
   // Updates the position of the VBot at the given index in the
   // array and checks if the VBot has collided with another. Returns
   // false if the VBot gets deleted to avoid recalling it and
   // causing an error.
   //----------------------------------------------------------------
   bool Update(int index);

   //----------------------------------------------------------------
   // Shows all of the VBots on the main panel.
   //----------------------------------------------------------------
   void Show();

   //----------------------------------------------------------------
   // Getter for the size of the array.
   //----------------------------------------------------------------
   int GetNum() { return size; }
};