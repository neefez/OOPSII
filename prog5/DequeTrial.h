//-------------------------------------------------------------------
// Name:    Zack Neefe, Darius Fieschko
// Project: Data Structure Time Trials
// Purpose: Header file for the DequeTrial class, which is the trial
//          class that manages the deque datatype that can be chosen
//          by the user.
//-------------------------------------------------------------------

#pragma once

#include "Trial.h"
#include <deque>

//----------------------------------------------------------------
// DequeTrial class, which manages the trials for a deque of
// strings.
//----------------------------------------------------------------
class DequeTrial : public Trial
{
public:

	//----------------------------------------------------------------
	// Constructor. Takes in the StringList, number of runs, and
	// utilizes the parent constructor to store them.
	//----------------------------------------------------------------
	DequeTrial(StringList & s, int num_runs, TrialType t)
		: Trial(s, num_runs, t) {}

protected:
	//----------------------------------------------------------------
	// Clears the data.
	//----------------------------------------------------------------
	void Clear() { data.clear(); }

	//----------------------------------------------------------------
	// Removes an element at the front or rear of the deque,
	// depending on user input.
	//----------------------------------------------------------------
	void RemoveElement();

	//----------------------------------------------------------------
	// Adds an element from the specified position in StringList to 
	// the deque at either the front or rear, depending on user
	// input.
	//----------------------------------------------------------------
	void AddElement(int i);

private:
	deque<string> data;
};