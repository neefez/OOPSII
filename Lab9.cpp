#include "Lab9.h"
#include <iostream>
using namespace std;

// Do 1: finish the Insert function
void BSTree::Insert(TreeNode * & t, InfoType x)
{
   if (t == NULL)
   {
      t = new TreeNode(x);
      return;
   }
   else if (x < t->info)
      return Insert(t->left, x);
   else if (x > t->info)
      return Insert(t->right, x);
   else
      return;
}

// Do 2: finish the Clean function used for the desctructor
void BSTree::Clean(TreeNode * t)
{
   if (t != NULL)
   {
      Clean(t->left);
      Clean(t->right);
      delete t;
   }
}

// Do 3: finish the depth function
int BSTree::Depth(const TreeNode * t) const
{
   if (t == NULL)
      return 0;
   int left = Depth(t->left);
   int right = Depth(t->right);
   if (left < right)
      return right + 1;
   return left + 1;
}

// Do 4: finish the RevOrderPrint function to 
// recursively print the tree in non-ascending order
void BSTree::RevOrderPrint(const TreeNode * t) const
{
   if (t != NULL)
   {
      RevOrderPrint(t->right);
      cout << t->info << endl;
      RevOrderPrint(t->left);
   }
}

// Do 5: finish the LevelPrint function to print the tree
// in a top-down, left-right manner
// hint: you may use a queue to do that
void BSTree::LevelPrint() const
{
   // If the tree is empty, what to do?
   if (tree == NULL)
      return;

   queue<TreeNode * > q;
   q.push(tree);
   while (!q.empty())
   {
      TreeNode * t = q.front();
      cout << t->info << endl;
      if(t->left != NULL)
         q.push(t->left);
      if(t->right != NULL)
         q.push(t->right);
      
      q.pop();
   }
}

//-----test main ---------
void main()
{
   BSTree bst;
   InfoType x;
   cin >> x;
   while (cin)
   {
      bst.Insert(x);
      cin >> x;
   }
   cout << "The depth of the tree is " << bst.Depth() << endl;
   cout << "Print in reverse order: " << endl;
   bst.RevOrderPrint();
   cout << "Print in level order: " << endl;
   bst.LevelPrint();
}