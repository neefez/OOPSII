//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Reverse Polish Notation Expression Evaluator
// Purpose: RPNEval is the main class of this program. It contains 
//          the basic structure of the program and instantiates 
//          a stack and a queue, as well as calling their 
//          methods, in order to evaluate RPN expressions.
//-------------------------------------------------------------------

#ifndef _RPNEVAL_H
#define _RPNEVAL_H

#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <string>

typedef float OperandType;

class RPNEval
{
private:
   bool valid;                   // Is RPN expression valid?
   OperandType answer;           // Value of RPN expression if valid
   Stack stack;                  // Used to process RPN
   Queue queue;                  // Stores intermediate results

   //----------------------------------------------------------------
   // Pushes the inputted operand onto the stack.
   //----------------------------------------------------------------
   void ProcessOperand(OperandType op);

   //----------------------------------------------------------------
   // Does an operation relevant for the given operator and enqueues 
   // the result. Returns true if no error was met, else false.
   //----------------------------------------------------------------
   bool ProcessOperator(char ch);

public:
   static const int IGNORE = 256;

   //----------------------------------------------------------------
   // RPNEval constructor
   //----------------------------------------------------------------
   RPNEval();

   //----------------------------------------------------------------
   // Returns true if RPN expression is valid, false otherwise.
   //----------------------------------------------------------------
   bool IsValid() const;

   //----------------------------------------------------------------
   // Returns the value of the RPN expression if it is valid.
   // Returns garbage if RPN expression is not valid.
   //----------------------------------------------------------------
   OperandType Value() const;

   //----------------------------------------------------------------
   // Reads and processes the next RPN expression from the standard 
   // input.
   //----------------------------------------------------------------
   void ProcessExpression();

   //----------------------------------------------------------------
   // Print out the intermediate results to the standard
   // output, with one space after each result.
   // Does NOT print any header or any newlines.
   //----------------------------------------------------------------
   void PrintIntermediateResults();
};

#endif