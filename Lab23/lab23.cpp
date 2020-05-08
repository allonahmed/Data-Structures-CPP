#include <iostream>
#include <string>
#include "BNode.h" 

bool HasPathSum(ds::sn::BNode<int>* root,int value)
{
	return false;
}



template <typename T>
int TreeDepth(ds::dn::BNode<T>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int left = TreeDepth(root->left);
		int right = TreeDepth(root->right);
		return (left>right)?(left+1):(right+1);
	}	
}


//either all nodes have two childs or no child
template <typename T>
bool IsFull(ds::dn::BNode<T>* root)
{
	if (root == NULL)
	{
		return true; // or false? idk
	}

	if((root->left == NULL) && (root->right==NULL))
	{
		return true;
	}

	if(root->right && root->right)
	{
		return (IsFull(root->left) && IsFull(root->right));
	}
	
	else{
		return false;
	}

}

int main()
{
	ds::dn::BNode<int>* tree = NULL;
	tree->BSTInsert(tree,13);
    tree->BSTInsert(tree,5);
    tree->BSTInsert(tree,20);
    tree->BSTInsert(tree,34);
    tree->BSTInsert(tree,12);
    // tree->BSTInsert(tree,9);
	// tree->BSTInsert(tree,8);
	// tree->BSTInsert(tree,17);
	// tree->BSTInsert(tree,20);
	// tree->BSTInsert(tree,2);
	// tree->BSTInsert(tree,11);

	tree->PreOrderPrint(tree);

	std::cout << "the tree depth is: " << TreeDepth(tree) << "\n";
	std::cout << std::boolalpha << IsFull(tree) << std::endl;
	
}
