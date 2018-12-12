//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Reverse Polish Notation Expression Evaluator
// Purpose: RPNEval is the main class of this program. This file
//          contains the definitions for the functions and methods
//          for the RPNEval class.
//-------------------------------------------------------------------

#include "RPNEVal.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;

void RPNEval::ProcessOperand(OperandType op)
{
   stack.Push(op);
}

bool RPNEval::ProcessOperator(char ch)
{
   OperandType operand2 = stack.Pop();
   OperandType operand1 = stack.Pop();
   OperandType result;
   if (operand1 == NULL || operand2 == NULL)
      return false;

   if (ch == '*')
   {
      result = operand1 * operand2;
      stack.Push(result);
      queue.Enqueue(result);
      return true;
   }
   else if (ch == '/')
   {
      if (operand2 == 0)
         return false;
      else
      {
         result = operand1 / operand2;
         stack.Push(result);
         queue.Enqueue(result);
         return true;
      }
   }
   else if (ch == '+')
   {
      result = operand1 + operand2;
      stack.Push(result);
      queue.Enqueue(result);
      return true;
   }
   else if (ch == '-')
   {
      result = operand1 - operand2;
      stack.Push(result);
      queue.Enqueue(result);
      return true;
   }
   return false;
}

RPNEval::RPNEval()
{
   valid = false;
}

bool RPNEval::IsValid() const
{ 
   return valid; 
}

OperandType RPNEval::Value() const
{ 
   return answer; 
}

void RPNEval::PrintIntermediateResults()
{
   cout << "The Intermediate Results are: ";
   queue.Print();
   cout << endl << endl;
   return;
}

void RPNEval::ProcessExpression()
{
   string inputString = "";
   bool done = false;
   char input;
   valid = true;

   while (valid && !done)
   {
      cin >> input;
      valid = true;
      bool calc = false;
      bool isOperator = false;
      OperandType operand;

      if (input >= '0' && input <= '9')
      {
         cin.putback(input);
         double operandDoub;
         cin >> operandDoub;

         string stringOperand = to_string(operandDoub);
         while (stringOperand.find(".") != string::npos &&
                stringOperand.substr(stringOperand.length() - 1, 1)
                == "0" ||
                stringOperand.substr(stringOperand.length() - 1, 1)
                == ".")
         {
            stringOperand.pop_back();
         }
         inputString = inputString + stringOperand + " ";

         operand = operandDoub;
         ProcessOperand(operand);
      }
      else if (input == '+' || input == '-' || input == '*' ||
               input == '/')
      { 
         inputString = inputString + input + " ";
         valid = ProcessOperator(input);
      }
      else if (input == '#')
         done = true;
      else
      {
         valid = false;
         inputString = inputString + input + " ";
      }
   }
   cin.ignore(IGNORE, '\n');

   if (stack.IsEmpty())
      valid = false;
   else if (valid)
   {
      answer = stack.Pop();
      if (!stack.IsEmpty())
         valid = false;
   }

   cout << inputString << endl;
   return;
}