//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Bot Wars Visual C++ Program
// Purpose: VBots are virtual robots that do battle with each other
//          when they touch. Each VBot has some energy and it uses
//          that energy when battling. VBots move around the screen
//          in some way.
//-------------------------------------------------------------------
#pragma once 
#include <vcclr.h>   

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
const int BORDER = 500;

class VBot
{
public:
   //----------------------------------------------------------------
   // Parameterized constructor for VBot. Takes in the position of
   // the bot and the panel to draw it on.
   //----------------------------------------------------------------
   VBot(int startX, int startY, Panel ^ drawingPanel) :
      x(startX), y(startY), panel(drawingPanel), energy(100), image(NULL) { }

   //----------------------------------------------------------------
   // Destructor for VBot to get overridden by its child classes.
   //----------------------------------------------------------------
   virtual ~VBot() { }

   //----------------------------------------------------------------
   // Move function for a generic VBot to get overridden by child
   // classes.
   //----------------------------------------------------------------
   virtual void Move() = 0;

   //----------------------------------------------------------------
   // Energy output function for a generic VBot to get overridden by
   // child classes.
   //----------------------------------------------------------------
   virtual int EnergyToFightWith() = 0;

   //----------------------------------------------------------------
   // Returns true if the energy of the bot is less than zero,
   // which indicates that the bot has died.
   //----------------------------------------------------------------
   bool IsDead() const { return energy <= 0; }

   //----------------------------------------------------------------
   // Shows the VBot on the panel.
   //----------------------------------------------------------------
   virtual void Show();

   //----------------------------------------------------------------
   // Checks to see if the VBot has collided with the VBot
   // parameter, returns true if it has.
   //----------------------------------------------------------------
   bool CollidedWith(VBot * b) const;

   //----------------------------------------------------------------
   // Executes a battle between the VBot and the VBot parameter. The
   // energies of the VBots are adjusted based on who wins or loses.
   //----------------------------------------------------------------
   void DoBattleWith(VBot * b);

protected:
   int x, y;                  
   gcroot<Drawing::Bitmap ^> image;   
   gcroot<Panel ^> panel;            
   int energy;                       
};