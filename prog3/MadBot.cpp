//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Bot Wars Visual C++ Program
// Purpose: This file contains the definitions for the methods of
//          the MadBot class.
//-------------------------------------------------------------------
#include "stdafx.h"
#include "MadBot.h"

MadBot::MadBot(int startX, int startY, Panel ^ panelStart) : VBot(startX, startY, panelStart)
{
   this->x = startX;
   this->y = startY;
   this->panel = panelStart;
   this->image = gcnew Drawing::Bitmap("madbot.bmp");
   this->Show();
   this->energy = 100;
}

void MadBot::Move()
{
   if ((MOVE_MAD + energy / MOVE_MAD_Y) > MAXSPEED)
      this->x -= MAXSPEED;
   else
      this->x -= (MOVE_MAD + energy / MOVE_MAD_Y);
   this->y -= MOVE_MAD_Y;
   if (this->x < 0)
      this->x = BORDER;
   if (this->y < 0)
      this->y = BORDER;
   return;
}