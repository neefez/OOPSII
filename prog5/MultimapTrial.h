//-------------------------------------------------------------------
// Name:    Zack Neefe, Darius Fieschko
// Project: Data Structure Time Trials
// Purpose: Header file for the MultimapTrial class, which is the 
//          trial class that manages the multimap datatype that can 
//          be chosen by the user.
//-------------------------------------------------------------------

#pragma once

#include "Trial.h"
#include <map>

//----------------------------------------------------------------
// ListTrial class, which manages the trials for a multimap of
// strings.
//----------------------------------------------------------------
class MultimapTrial : public Trial
{
public:

   //----------------------------------------------------------------
   // Constructor. Takes in the StringList, number of runs, and
   // utilizes the parent constructor to store them.
   //----------------------------------------------------------------
   MultimapTrial(StringList & s, int num_runs, TrialType t)
      : Trial(s, num_runs, t) {}

protected:
   //----------------------------------------------------------------
   // Clears the data.
   //----------------------------------------------------------------
   void Clear() { data.clear(); }

   //----------------------------------------------------------------
   // Removes an element at the location specified.
   //----------------------------------------------------------------
   void RemoveElement(int i);

   //----------------------------------------------------------------
   // Adds an element from the specified position in StringList to 
   // the multimap at either the front or rear, depending on user
   // input.
   //----------------------------------------------------------------
   void AddElement(int i);

private:
   multimap<int, string> data;
};