//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Bot Wars Visual C++ Program
// Purpose: PanBot is a VBot that moves in a horizontal line to the
//          right and occasionally moves slightly downwards. PanBot
//          uses its energy at an efficiency rate of 75%.
//-------------------------------------------------------------------
#pragma once
#include "VBot.h"
const float ENERGY_LOST = .75;
const int MOVE_PAN = 11;

class PanBot: public VBot
{
public:
   //----------------------------------------------------------------
   // Parameterized constructor for PanBot. Takes in the coordinates
   // for the bot and the panel to put it on.
   //----------------------------------------------------------------
   PanBot(int startX, int startY, Panel ^ panelStart);

   //----------------------------------------------------------------
   // Returns 75% of the bot's total energy.
   //----------------------------------------------------------------
   int EnergyToFightWith() { return int(energy * ENERGY_LOST); }

   //----------------------------------------------------------------
   // PanBot is moved 22 units to the right and 1 unit down. It it
   // moved to the opposite side of the screen if it hits a wall.
   //----------------------------------------------------------------
   void Move();
};