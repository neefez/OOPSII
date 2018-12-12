//-------------------------------------------------------------------
// Name:    Zack Neefe, Darius Fieschko; File created by instructor.
// Project: Data Structure Time Trials
// Purpose: Header file for the PrecisionTimer class, which measures 
//          the amount of time in microseconds that a trial takes to 
//          run.
//-------------------------------------------------------------------

#pragma once

//----------------------------------------------------------------
// PrecisionTimer class, which measures how long a trial takes to
// run with microsecond precision.
//----------------------------------------------------------------
class PrecisionTimer
{
public:

   //----------------------------------------------------------------
   // Constructor for PrecisionTimer. Sets the beginning time to the
   // current time.
   //----------------------------------------------------------------
   PrecisionTimer();

   //----------------------------------------------------------------
   // Restarts the timer, setting the beginning time to the current
   // time.
   //----------------------------------------------------------------
   void ReStart();

   //----------------------------------------------------------------
   // Returns the elapsed time measured by the PrecisionTimer since
   // the beginning time.
   //----------------------------------------------------------------
   unsigned int ElaspedTime() const;

private:
   __int64 start_count;
   double microseconds_per_count;
};