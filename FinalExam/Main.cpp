#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.h"
#include "Node.h"
#include "Pair.h"
#include "Iterator.h"
#include "List.h"
#include "Set.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "BNode.h"
using namespace ds;

//Question 1

template <typename T>
int Size(sn::BNode<T>* root)
{
	if(root == NULL)
	{
		return 0;
	}
	else 
	{
		return 1 + Size(root->left) + Size(root->right);
	}
}
template <typename T>
bool IsBST(sn::BNode<T>* root)
{
	int btsize = Size(root);
	if(btsize>=1)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

//Question 2

sn::Node<int>* MergeSortedLists(sn::Node<int>* a,sn::Node<int>* b)
{
	// MergeSortedLists();
}

//Question 3

bool IsValidWord(std::string wrd)
{
	return false;
}

//Question 4
/******************************************************************************************
InFix: 2 40 13 43 23 11 39 21 38 47 36 14 26 5 3

Postfix: 2 13 40 23 39 11 43 38 36 47 26 3 5 14 21
 
Prefix: 21 43 40 2 13 11 23  39 14 47 38 36 5 26 3

******************************************************************************************/

int main()
{
	return 0;
}
