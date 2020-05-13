#include <iostream>
#include <string>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include "BNode.h"


template<typename T>
void findmx(ds::dn::BNode<T>* root, int level, int &deepLevel, int &val)
{
	if (root != NULL)
	{
		findmx(root->left, ++level, deepLevel, val);
		if( level > deepLevel)
		{
			val = root->data;
			deepLevel = level;
		}
		findmx(root->right, level, deepLevel, val);
	}
} // function to find the deepest level in the binary tree

template <typename T>
int deepestNode(ds::dn::BNode<T>* root)
{
	int val = -1;
	int deepLevel = -1;
	findmx(root, 0 , deepLevel, val);
	return val;
} // finds the value of the deepest node in binary tree
template <typename T>
void swap(T *a, T *b)
{
	T *tmp = a;
	a = b;
	b = tmp;
} // helper swap function

template <typename T>
void BTRemove(ds::dn::BNode<T>* root, int value)
{

	ds::dn::BNode<T>* tmp = root->BTSearch(root, value);
	if (tmp!=NULL)
	{
		ds::dn::BNode<T>* end = root->BTSearch(root, deepestNode(root));
		swap(&end->data, &tmp->data);
		tmp->data = end->data;
		delete end;
		end = NULL;
	}
}// swaps last node with the value to be removed
//sets node to zero instead of it being removed

template <typename T>
ds::dn::BNode<T>* deleteNode(ds::dn::BNode<T>* root,const T& value)
{
	ds::dn::BNode<T>* tmp;
	if(root == NULL) // if is empty, do nothing
	{
		return root;
	}
	if(value < root->data)
	{
		root->left = deleteNode(root->left, value);
	}
	else if(value > root->data)
	{
		root->right = deleteNode(root->right, value);
	}
	else
	{
		if (root->left == NULL)
		{
			tmp = root->right;
			free(root); //deallocates root so it can be reallocated
			return tmp;
		}
		else if(root->right == NULL)
		{
			tmp = root->left;
			free(root);
			return tmp;
		}
		tmp = root->TreeMinimum(root->right);
		root->data = tmp->data;
		root->right = deleteNode(root->right, tmp->data);
	}
	return root;
} // deletes the node with the value passed in parameter recursively

template <typename T>
void BSTRemove(ds::dn::BNode<T>* root,const T& value)
{
	root = deleteNode(root, value);
}

template <typename T>
ds::dn::BNode<T>* TreeMinimum(ds::dn::BNode<T>* root)
{
	ds::dn::BNode<double>* tmp = root;
	while(tmp->left != NULL)
	{
		tmp = tmp->left;
	}
	return tmp;
} // helper functiont that finds the minimum node in a bst


double Range(ds::dn::BNode<double>* root)
{
	ds::dn::BNode<double>* min = new ds::dn::BNode<double>();
	ds::dn::BNode<double>* max = new ds::dn::BNode<double>();

	min = root->TreeMinimum(root);
	max = root->TreeMaximum(root);

	double maximum = max->data;
	double minimum = min->data;

	return maximum - minimum;
} // maximum- minimum node values to find the range of the binary search tree




int main()
{
	ds::dn::BNode<double>* tree = NULL; // binary seach tree
	tree->BSTInsert(tree, 45);
	tree->BSTInsert(tree, 13);
    tree->BSTInsert(tree,5);
    tree->BSTInsert(tree,7);
    tree->BSTInsert(tree,34);
    tree->BSTInsert(tree,12);
    tree->BSTInsert(tree,9);
	tree->BSTInsert(tree,8);
	tree->BSTInsert(tree,17);
	tree->BSTInsert(tree,14);
	tree->BSTInsert(tree,2);
	tree->BSTInsert(tree,11);

	ds::dn::BNode<double>* test = NULL; // binary tree
	test->BTInsert(test, 20);
	test->BTInsert(test, 31);
	test->BTInsert(test, 12);
	test->BTInsert(test, 31);
	test->BTInsert(test, 19);
	test->BTInsert(test, 7);
	test->BTInsert(test, 45);
	test->BTInsert(test, 28);
	test->BTInsert(test, 15);	
	test->PreOrderPrint(test);
	double value = 7;

	std::cout << "the deepest node in the binary tree is:  " << deepestNode(test) << std::endl;
	std::cout << "after removal of " << value << ": " << std::endl; 

	BTRemove(test, value);
	test->PreOrderPrint(test);
	std::cout << "\n\n";

	tree->InOrderPrint(tree);
	std::cout << "\nThe range of the binary search tree is: " << Range(tree) << std::endl;

	std::cout << "The binary search tree after the removal of value " << value << "\n";

	BSTRemove(tree, value);
	tree->InOrderPrint(tree);

}
