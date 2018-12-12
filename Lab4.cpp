// Lab4 - Write the DoIt method as specified in the handout.  
// It has ???? by it.
// You are only allowed to change that method.
// You get 0 if you modify anything else.

#include <iostream>
using namespace std;

typedef int InfoType;

class LList
{
public:
   LList() { list = NULL; }
   ~LList();
   void AddRear( InfoType x );
   void RemoveFront();
   bool IsEmpty() const { return list == NULL; }
   bool DoIt ( InfoType & x ) const;
private:
   struct Node
   {
      InfoType info;
      Node * next;
      Node ( InfoType x, Node * p = NULL ) { info = x;  next = p; }
   };
   Node * list;
};


bool LList::DoIt ( InfoType & x ) const
{
   int numNodes = 0;
   if (list == NULL)
   {
      return false;
   }
   Node * current = list;
   if (current->next == NULL)
   {
      x = list->info;
      return true;
   }
   numNodes++;
   while (current->next != NULL)
   {
      numNodes++;
      current = current->next;
   }
   if (numNodes >= 2 && numNodes <= 4)
   {
      x = list->next->info;
      return true;
   }
   else
   {
      x = current->info;
      return true;
   }
}

LList::~LList()
{
   while ( list != NULL )
   {
      Node * p = list;
      list = list->next;
      delete p;
   }
}

void LList::RemoveFront()
{
   if ( list != NULL )
   {
      Node * p = list;
      list = list->next;
      delete p;
   }
}

void LList::AddRear( InfoType x ) 
{ 
   if( list == NULL )
      list = new Node(x);
   else
   {
      Node * p = list;
      while ( p->next != NULL  )
         p = p->next;
      p->next = new Node(x);
   }
}

void main()
{
   int x = 0;
   LList l;

   for ( int i = 0; i < 10; i++ )
   {
      if ( ! l.DoIt(x) )
         cout << "Not"  << endl;
      else
         cout << x << endl;
      l.AddRear( 2 * i + 1 );
   }
   while( ! l.IsEmpty() )
   {
      if ( ! l.DoIt(x) )
         cout << "Not"  << endl;
      else
         cout << x << endl;
      l.RemoveFront();
   }
   if ( ! l.DoIt(x) )
      cout << "Not"  << endl;
   else
      cout << x << endl;
}
