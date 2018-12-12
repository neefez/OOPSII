//-------------------------------------------------------------------
// Name:    Zack Neefe, Darius Fieschko; File created by instructor.
// Project: Data Structure Time Trials
// Purpose: CPP file for the Trial class, which is the parent of
//          the trial classes for each data structure that can be
//          tested.
//-------------------------------------------------------------------
#include "stdafx.h"
#include "trial.h"


unsigned int Trial::Run()
{
   int num = strings.size();

   Clear();

   timer.ReStart();

   for (int r = 0; r < numRuns; r++)
   {
      for (int i = 0; i < num; i++)
         AddElement(i);

      for (int i = 0; i < num; i++)
      {
         if (type == SORTED)
            RemoveElement(i);
         else
            RemoveElement();
      }
   }

   return timer.ElaspedTime();
}