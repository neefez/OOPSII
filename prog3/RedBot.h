//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Bot Wars Visual C++ Program
// Purpose: RedBot is a VBot that bounces off of the walls of the
//          panel. RedBot has a lot of starting energy, and it uses
//          its energy at maximum efficiency during battle. When
//          RedBot's energy exceeds 400, RedBot is overloaded and
//          only uses its energy at 33% efficiency from then on.
//-------------------------------------------------------------------
#pragma once
#include "VBot.h"
const int MOVE_RED = 10;
const int MOVE_RED_Y = 5;
const int TYPE2 = 2;
const int TYPE3 = 3;
const int FULLPOWER = 400;
const int OVERLOADED = 3;
const int NUM_TYPES = 4;

class RedBot: public VBot
{
private:
   int movetype = 0;
   bool overload = false;
public:
   //----------------------------------------------------------------
   // Parameterized constructor for the RedBot. Takes in the starting
   // position and the panel to put the bot on.
   //----------------------------------------------------------------
   RedBot(int startX, int startY, Panel ^ panelStart);

   //----------------------------------------------------------------
   // Moves the bot 10 units horizontally and 5 units vertically,
   // dependent on the last wall it bounced off. Calls another move 
   // function based on its movement state. Initial state is down 
   // and to the right.
   //----------------------------------------------------------------
   void Move();
   
   //----------------------------------------------------------------
   // Returns all of the bot's energy if it is in the normal state,
   // or a third of the bot's energy if it is overloaded.
   //----------------------------------------------------------------
   int EnergyToFightWith();

   //----------------------------------------------------------------
   // Checks if the bot has become overloaded. If it has, its
   // direction changes.
   //----------------------------------------------------------------
   void OverloadCheck();

   //----------------------------------------------------------------
   // Moves the bot down and to the right. Checks for a wall bounce
   // and executes it if necessary.
   //----------------------------------------------------------------
   void MoveZero();

   //----------------------------------------------------------------
   // Moves the bot up and to the right. Checks for a wall bounce
   // and executes it if necessary.
   //----------------------------------------------------------------
   void MoveOne();

   //----------------------------------------------------------------
   // Moves the bot up and to the left. Checks for a wall bounce
   // and executes it if necessary.
   //----------------------------------------------------------------
   void MoveTwo();

   //----------------------------------------------------------------
   // Moves the bot down and to the left. Checks for a wall bounce
   // and executes it if necessary.
   //----------------------------------------------------------------
   void MoveThree();
};