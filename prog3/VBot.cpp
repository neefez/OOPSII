//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Bot Wars Visual C++ Program
// Purpose: This file contains the definitions for the methods of
//          the VBot class.
//-------------------------------------------------------------------
#include "stdafx.h"     
#include "Vbot.h"

void VBot::Show()
{
   Graphics ^ g = panel->CreateGraphics();
   g->DrawImageUnscaled(image, x, y);
   g->~Graphics();
}

bool VBot::CollidedWith(VBot * b) const
{
   if (b == NULL)
      return false;

   return   (x + image->Width) >= b->x
      && (b->x + b->image->Width) >= x
      && (y + image->Height) >= b->y
      && (b->y + b->image->Height) >= y;

}

void VBot::DoBattleWith(VBot * b)
{
   int mine = EnergyToFightWith();
   int yours = b->EnergyToFightWith();
   if (mine == yours)
   {
      energy = energy - mine / 2;
      b->energy = b->energy - yours / 2;
   }
   else if (mine > yours)
   {
      if (b->energy > 1)
      {
         b->energy = b->energy - yours;
         energy = energy + yours / 2;
      }
      else
      {
         b->energy = b->energy - 1;
         energy = energy + 1;
      }
   }
   else
   {
      if (energy > 1)
      {
         energy = energy - mine;
         b->energy = b->energy + mine / 2;
      }
      else
      {
         b->energy = b->energy + 1;
         energy = energy - 1;
      }
   }
}