//-------------------------------------------------------------------
// Name:    Zack Neefe, Darius Fieschko
// Project: Data Structure Time Trials
// Purpose: Header file for the Trial class, which is the parent of
//          the trial classes for each data structure that can be
//          tested.
//-------------------------------------------------------------------

#pragma once

#include "PrecisionTimer.h"

#include <vector>
#include <string>
using namespace std;

typedef vector<string> StringList;

//----------------------------------------------------------------
// Trial class, the parent of all the other trial classes. Defines
// most of the functions and variables that the other trial 
// classes will use.
//----------------------------------------------------------------
class Trial
{
public:

   enum TrialType { FRONT_FRONT, FRONT_REAR, REAR_FRONT, REAR_REAR, SORTED };

   //----------------------------------------------------------------
   // Constructor. Takes in the StringList, number of runs, and
   // trial type.
   //----------------------------------------------------------------
   Trial(StringList & s, int num_runs, TrialType t)
      : strings(s), numRuns(num_runs), type(t) { }

   //----------------------------------------------------------------
   // Runs the trial and returns the number of microseconds elapsed.
   //----------------------------------------------------------------
   unsigned int Run();

   //----------------------------------------------------------------
   // Destructor.
   //----------------------------------------------------------------
   virtual ~Trial() {}

protected:

   StringList & strings;
   TrialType type;

   //----------------------------------------------------------------
   // Clears the data used in the trial.
   //----------------------------------------------------------------
   virtual void Clear() = 0;

   //----------------------------------------------------------------
   // Adds an element to the data structure used in the trial.
   //----------------------------------------------------------------
   virtual void AddElement(int i) = 0;

   //----------------------------------------------------------------
   // Struct used for error handling in try-catch blocks.
   //----------------------------------------------------------------
   struct WrongRemoveCalled { };

   //----------------------------------------------------------------
   // Removes an element from the front or rear of the data structure
   // being used.
   //----------------------------------------------------------------
   virtual void RemoveElement() { throw WrongRemoveCalled(); }

   //----------------------------------------------------------------
   // Removes an element at a specific spot in the data structure
   // being used.
   //----------------------------------------------------------------
   virtual void RemoveElement(int i) { throw WrongRemoveCalled(); }

private:
   PrecisionTimer timer;
   int numRuns;

};