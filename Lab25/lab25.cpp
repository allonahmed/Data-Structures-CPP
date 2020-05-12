#include <iostream>
#include <string>
#include "BNode.h" 

int TreeSum(ds::dn::BNode<int>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return root->data +TreeSum(root->right) + TreeSum(root->left);
}

template <typename T>
bool EqualTrees(ds::dn::BNode<T>* tr1,ds::dn::BNode<T>* tr2)
{
	if (tr1 == NULL && tr2 == NULL)
	{
		return true;
	}
	if(tr1 != NULL && tr2 != NULL)
	{
		if(!(tr1->data == tr2->data && EqualTrees(tr1->left, tr2->left) && EqualTrees(tr1->right, tr2->right))){
			return false;
		}
		else
		{
			return true;
		}
		
	}
}

ds::dn::BNode<int>* TreeMerge(ds::dn::BNode<int>* x,ds::dn::BNode<int>* y)
{
	return NULL;
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
    template <typename T>
    int Size(ds::dn::BNode<T>* root)
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
ds::dn::BNode<T>* ShorterSubTree(ds::dn::BNode<T>* root) //lab23 if left and right have same height, return the left

{
	if (IsFull(root))
	{
		return root->left;
	}
	else
	{
		int sleft = 1+ Size(root->left);
		int sright = 1+ Size(root->right);
		if(sleft > sright)
		{
			return root->right;
		}
		else
		{
			return root->left;
		}
	}
}


int main()
{
	ds::dn::BNode<int>* tree = NULL;
	ds::dn::BNode<int>* tree1 = NULL;

	tree->BSTInsert(tree, 10);
	tree->BSTInsert(tree, 5);
	tree->BSTInsert(tree, 4);
	tree->BSTInsert(tree, 7);
	tree->PreOrderPrint(tree);

	tree1->BSTInsert(tree1, 10);
	tree1->BSTInsert(tree1, 5);
	tree1->BSTInsert(tree1, 4);
	tree1->BSTInsert(tree1, 7);
	tree->BSTInsert(tree1, 7);


	 std::cout << "tree 1: ";
	 tree->PreOrderPrint(tree);
	 std::cout << "tree 2: ";
	tree1->PreOrderPrint(tree1);

	std::cout << "\nsum of binary search tree: " << TreeSum(tree) << std::endl;

	std::cout << std::boolalpha << "it is " << EqualTrees(tree, tree1) << " that the two trees are equal\n";

	std::cout << "\nThe shorter subtree is: \n";
	ds::dn::BNode<int>* srt = ShorterSubTree(tree);

	srt->InOrderPrint(srt);






}
