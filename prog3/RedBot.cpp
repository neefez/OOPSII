//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Bot Wars Visual C++ Program
// Purpose: This file contains the definitions for the methods of
//          the RedBot class.
//-------------------------------------------------------------------
#include "stdafx.h"
#include "RedBot.h"

RedBot::RedBot(int startX, int startY, Panel ^ panelStart) : VBot(startX, startY, panelStart)
{
   this->x = startX;
   this->y = startY;
   this->panel = panelStart;
   this->image = gcnew Drawing::Bitmap("redbot.bmp");
   this->Show();
   this->energy = 100;
}

void RedBot::Move()
{
   if (this->movetype == 0)
      MoveZero();
   else if (this->movetype == 1)
      MoveOne();
   else if (this->movetype == TYPE2)
      MoveTwo();
   else
      MoveThree();
   OverloadCheck();
}

void RedBot::MoveZero()
{
   this->x += MOVE_RED;
   this->y += MOVE_RED_Y;
   if (this->x > BORDER && this->y > BORDER)
   {
      this->x = BORDER;
      this->y = BORDER;
      this->movetype = TYPE2;
   }
   else if (this->x > BORDER)
   {
      this->x = BORDER;
      this->movetype = TYPE3;
   }
   else if (this->y > BORDER)
   {
      this->y = BORDER;
      this->movetype = 1;
   }
}

void RedBot::MoveOne()
{
   this->x += MOVE_RED_Y;
   this->y -= MOVE_RED;
   if (this->x > BORDER && this->y < 0)
   {
      this->x = BORDER;
      this->y = 0;
      this->movetype = TYPE3;
   }
   else if (this->x > BORDER)
   {
      this->x = BORDER;
      this->movetype = TYPE2;
   }
   else if (this->y < 0)
   {
      this->y = 0;
      this->movetype = 0;
   }
}

void RedBot::MoveTwo()
{
   this->x -= MOVE_RED;
   this->y -= MOVE_RED_Y;
   if (this->x < 0 && this->y < 0)
   {
      this->x = 0;
      this->y = 0;
      this->movetype = 0;
   }
   else if (this->x < 0)
   {
      this->x = 0;
      this->movetype = 1;
   }
   else if (this->y < 0)
   {
      this->y = 0;
      this->movetype = TYPE3;
   }
}

void RedBot::MoveThree()
{
   this->x -= MOVE_RED_Y;
   this->y += MOVE_RED;
   if (this->x < 0 && this->y > BORDER)
   {
      this->x = 0;
      this->y = BORDER;
      this->movetype = 1;
   }
   else if (this->x < 0)
   {
      this->x = 0;
      this->movetype = 0;
   }
   else if (this->y > BORDER)
   {
      this->y = BORDER;
      this->movetype = TYPE2;
   }
}


int RedBot::EnergyToFightWith()
{
   if (overload == 0)
      return energy;
   else
      return (energy / OVERLOADED);
}

void RedBot::OverloadCheck()
{
   if (this->energy > FULLPOWER && !overload)
   {
      this->image = gcnew Drawing::Bitmap("redbotdead.bmp");
      overload = true;
      movetype = (movetype + 1) % NUM_TYPES;
   }
   return;
}