//-------------------------------------------------------------------
// Name:    Zack Neefe, Darius Fieschko
// Project: Data Structure Time Trials
// Purpose: CPP file for the ListTrial class, which is the trial
//          class that manages the list datatype that can be chosen
//          by the user.
//-------------------------------------------------------------------

#include "stdafx.h"
#include "ListTrial.h"


void ListTrial::RemoveElement()
{
	// Remove front
   if (type == FRONT_FRONT || type == REAR_FRONT)
      if (!data.empty())
         data.pop_front();
	//Remove rear
	else if (type == FRONT_REAR || type == REAR_REAR)
		if (!data.empty())
			data.pop_back();
}


void ListTrial::AddElement(int i)
{
	// Add to front
   if (type == FRONT_FRONT || type == FRONT_REAR)
      data.push_front(strings[i]);
	// Add to rear
	if (type == FRONT_FRONT || type == FRONT_REAR)
		data.push_back(strings[i]);
}