//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Bot Wars Visual C++ Program
// Purpose: This file contains the definitions for the methods of
//          the PanBot class.
//-------------------------------------------------------------------
#include "stdafx.h"
#include "PanBot.h"

PanBot::PanBot(int startX, int startY, Panel ^ panelStart) : VBot(startX, startY, panelStart)
{
   this->x = startX;
   this->y = startY;
   this->panel = panelStart;
   this->image = gcnew Drawing::Bitmap("panbot.bmp");
   this->Show();
   this->energy = 50;
}

void PanBot::Move()
{
   this->x += MOVE_PAN;
   this->x += MOVE_PAN;
   this->y += 1;
   if (this->x > BORDER)
      this->x = 0;
   if (this->y > BORDER)
      this->y = 0;
   return;
}