//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Bot Wars Visual C++ Program
// Purpose: This filed contains the definitions of the methods for
//          the VBotList class.
//-------------------------------------------------------------------
#include "stdafx.h"
#include "VBotList.h"

VBotList::VBotList() 
{ 
   size = 0;
   list = new VBot*[size];
}

VBotList::~VBotList()
{
   for (int i = size - 1; i >= 0; i--)
   {
      delete list[i];
   }
}

bool VBotList::Delete(VBot* bot)
{
   for (int i = 0; i < size; i++)
   {
      if (list[i] == bot)
      {
         delete list[i];
         list[i] = list[--size];
         return true;
      }
   }
   delete bot;
   return false;
}

bool VBotList::Update(int index)
{
   bool deleted = true;
   list[index]->Move();
   for (int i = 0; i < size; i++)
   {
      if (i != index)
      {
         if (index >= size)
            return false;
         if (list[index]->CollidedWith(list[i]))
         {
            list[index]->DoBattleWith(list[i]);
            if (list[index]->IsDead())
            {
               Delete(list[index]);
               deleted = false;
            }
            else if (list[i]->IsDead())
            {
               Delete(list[i]);
               deleted = false;
            }
            else
            {
               if (index >= size)
                  return false;
               list[i]->Move();
            }
         }
      }
   }
   return deleted;
}

void VBotList::Show()
{
   for (int i = 0; i < size; i++)
   {
      list[i]->Show();
   }
}