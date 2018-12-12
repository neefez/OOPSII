//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Bot Wars Visual C++ Program
// Purpose: MadBot is a VBot that moves diagonally upwards and to
//          the left. MadBot moves more upwards the more energy it
//          has. MadBot loses some battle energy based on its x
//          position.
//-------------------------------------------------------------------
#pragma once
#include "VBot.h"
const int ENERGY_LOSS = 25;
const int MOVE_MAD = 5;
const int MOVE_MAD_Y = 15;
const int MAXSPEED = 35;

class MadBot: public VBot
{
public:
   //----------------------------------------------------------------
   // Parameterized constructor for MadBot. Takes in the coordinates
   // for the new bot and the panel to put it on.
   //----------------------------------------------------------------
   MadBot(int startX, int startY, Panel ^ panelStart);

   //----------------------------------------------------------------
   // Gives an amount of energy less than the total energy, based on
   // the x postion of the bot modulo 25.
   //----------------------------------------------------------------
   int EnergyToFightWith() { return (energy - (x % ENERGY_LOSS)); }

   //----------------------------------------------------------------
   // MadBot moves up and to the left, with a steeper angle the
   // higher its total energy is.
   //----------------------------------------------------------------
   void Move();
};