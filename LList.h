//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Maintain and Manipulate a Catalog of Fruit products
// Purpose: Linked list class that holds objects in nodes and 
//          pointers to link to the next node.
//-------------------------------------------------------------------

#ifndef _LLIST_H
#define _LLIST_H
//#define _TESTING_LLIST

#include "Fruit.h"
typedef Fruit InfoType;

class LList
{
public:
   //----------------------------------------------------------------
   // Default constructor for the linked list, sets the first node
   // to NULL (empty).
   //----------------------------------------------------------------
   LList() { list = NULL; }

   //----------------------------------------------------------------
   // Deconstructor for the linked list, deletes all the nodes in
   // the list.
   //----------------------------------------------------------------
   ~LList();    

   //----------------------------------------------------------------
   // Tells whether the list is empty. True if it is, false if not.
   //----------------------------------------------------------------
   bool IsEmpty() const;

   //----------------------------------------------------------------
   // Inserts an object into the list at the appropriate point by
   // comparing it to the elements already in the list with the "<"
   // operator. Returns true if the object was added, false if the
   // object was already in the list.
   //----------------------------------------------------------------
   bool Insert(InfoType * x_ptr);

   //----------------------------------------------------------------
   // Deletes a given object from the linked list. Returns true if
   // object is found and deleted, false if object wasn't in list.
   //----------------------------------------------------------------
   bool Delete(const InfoType & x);

   //----------------------------------------------------------------
   // Outputs the elements of the list to an output stream.
   //----------------------------------------------------------------
   void Display(ostream & out_stream) const;

private:
   struct Node
   {
      Node(InfoType * x, Node * p = NULL) { infoPtr = x;  next = p; }
      ~Node() { delete infoPtr; }
      InfoType * infoPtr;
      Node * next;
   };

   Node * list;

   //----------------------------------------------------------------
   // Overridden with no body so it cannot be accidentally accessed.
   //----------------------------------------------------------------
   LList(const LList & copyFrom);       

   //----------------------------------------------------------------
   // Overridden with no body so it cannot be accidentally accessed.
   //----------------------------------------------------------------
   LList & operator= (const LList & assignFrom);   
}; 
#endif