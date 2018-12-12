//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Reverse Polish Notation Expression Evaluator
// Purpose: This file contains the main() function that starts the
//          program.
//-------------------------------------------------------------------

#include <iostream>
#include "RPNEval.h"
using namespace std;

int num_expressions = 0;

int main()
{
   cin >> num_expressions;

   for (int i = 0; i < num_expressions; i++)
   {
      RPNEval rpn;
      cout << "Expression " << i + 1 << ":" << endl;
      rpn.ProcessExpression();

      if (!rpn.IsValid())
         cout << "Invalid Expression" << endl;
      else
         cout << "The value is: " << rpn.Value() << endl;

      rpn.PrintIntermediateResults();
   }

   cout << "Normal Termination of Program 1!" << endl;
   return 0;
}