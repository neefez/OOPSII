//-------------------------------------------------------------------
// Name:    Zack Neefe, Darius Fieschko
// Project: Data Structure Time Trials
// Purpose: CPP file for the MultisetTrial class, which is the trial
//          class that manages the multiset datatype that can be 
//          chosen by the user.
//-------------------------------------------------------------------

#include "stdafx.h"
#include "MultisetTrial.h"

void MultisetTrial::RemoveElement(int i)
{
	if (!data.empty())
		data.erase(strings[i]);
}

void MultisetTrial::AddElement(int i)
{
   // Add element to multiset.
   data.insert(strings[i]);
}