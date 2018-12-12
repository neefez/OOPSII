//-------------------------------------------------------------------
// Name:    Zack Neefe, Darius Fieschko
// Project: Data Structure Time Trials
// Purpose: CPP file for the MultimapTrial class, which is the trial
//          class that manages the multimap datatype that can be 
//          chosen by the user.
//-------------------------------------------------------------------

#include "stdafx.h"
#include "MultimapTrial.h"


void MultimapTrial::RemoveElement(int i)
{
	if (!data.empty())
		data.erase(i);
}

void MultimapTrial::AddElement(int i)
{
	// Add element to multimap.
	data.insert(std::pair<int, string>(i, strings[i]));
}