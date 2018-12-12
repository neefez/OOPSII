//-------------------------------------------------------------------
// Name:    Zack Neefe, Darius Fieschko
// Project: Data Structure Time Trials
// Purpose: Header file for the ListTrial class, which is the trial
//          class that manages the list datatype that can be chosen
//          by the user.
//-------------------------------------------------------------------

#pragma once

#include "Trial.h"
#include <list>

//----------------------------------------------------------------
// ListTrial class, which manages the trials for a list of
// strings.
//----------------------------------------------------------------
class ListTrial : public Trial
{
public:

	//----------------------------------------------------------------
	// Constructor. Takes in the StringList, number of runs, and
	// utilizes the parent constructor to store them.
	//----------------------------------------------------------------
	ListTrial(StringList & s, int num_runs, TrialType t)
		: Trial(s, num_runs, t) {}

protected:
	//----------------------------------------------------------------
	// Clears the data.
	//----------------------------------------------------------------
	void Clear() { data.clear(); }

	//----------------------------------------------------------------
	// Removes an element at the front or rear of the list,
	// depending on user input.
	//----------------------------------------------------------------
	void RemoveElement();

	//----------------------------------------------------------------
	// Adds an element from the specified position in StringList to 
	// the list at either the front or rear, depending on user
	// input.
	//----------------------------------------------------------------
	void AddElement(int i);

private:
	list<string> data;
};