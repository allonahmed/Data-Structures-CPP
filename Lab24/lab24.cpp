#include <iostream>
#include <string>
#include "BNode.h" 
#include "Node.h"
#include <cstdlib>
#include <ctime>
#include "Stack.h"

namespace ds::dn
{
    template <typename T>
    bool IsLeaf(BNode<T>* root)
    {
        if(root != NULL)
        {
            return root->left == NULL && root->right == NULL;
        }
        return false;
    }

    template <typename T>
    void InOrderPrint(BNode<T>* root)
    {
        if(root != NULL)
        {
            InOrderPrint(root->left);
            std::cout << root->data << " ";
            InOrderPrint(root->right);
        }
    }

    template <typename T>
    void PreOrderPrint(BNode<T>* root)
    {
        if(root != NULL)
        {                                    
            std::cout << root->data << " ";
            PreOrderPrint(root->left);
            PreOrderPrint(root->right);
        }
    }

    template <typename T>
    void PostOrderPrint(BNode<T>* root)
    {
        if(root != NULL)
        {                                    
            PostOrderPrint(root->left);
            PostOrderPrint(root->right);
            std::cout << root->data << " ";
        }
    }

    template <typename T>
    int Size(BNode<T>* root)
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
    void BSTInsert(BNode<T>*& root,BNode<T>* p,const T& value)
    {
        if(root == NULL)
        {
            root = new BNode<T>(value,p);
        }
        else if(root->data > value)
        {
            BSTInsert(root->left,root,value);
        }
        else
        {
            BSTInsert(root->right,root,value);
        }
    }

    template <typename T>
    void BSTInsert(BNode<T>*& root,const T& value)
    {
        if(root == NULL)
        {
            root = new BNode<T>(value,NULL);
        }
        else 
        {
            BSTInsert<T>(root,NULL,value);
        }
    }

    template <typename T>
    BNode<T>* BSTSearch(BNode<T>* root,const T& value)
    {
        if(root == NULL || root->data == value)
        {
            return root;
        }
        else if(root->data > value)
        {
            return BSTSearch(root->left,value);
        }
        else
        {
            return BSTSearch(root->right,value);
        }
    }
 
}

template <typename T>
ds::dn::BNode<T>* TreeMinimum(ds::dn::BNode<T>* root)
{
    ds::dn::BNode<T>* tmp = root;
    while(tmp->left != NULL)
    {
        tmp = tmp->left;
    }
    return tmp;
}
            
template <typename T>
ds::dn::BNode<T>* TreeMaximum(ds::dn::BNode<T>* root)
{
    ds::dn::BNode<T>* tmp = root;

    while(tmp->right != NULL)
    {
        tmp = tmp->right;
    }
    return tmp;
}

template <typename T>
ds::dn::BNode<T>* TreeSuccessor(ds::dn::BNode<T>* x)
{
    ds::dn::BNode<T>* tmp = BSTSearch(x, x->data);
    ds::dn::BNode<T>* parent = tmp->p;
    if(tmp->right != NULL)
    {
        return TreeMinimum(x->right);
    }
    while(parent != NULL && tmp == parent->right)
    {
        tmp = parent;
        parent = parent->p;
    }

    return parent;
}

template<typename T>
ds::dn::BNode<T>* TreePredecessor (ds::dn::BNode<T>* x)
{
    ds::dn::BNode<T>* tmp = x;
    ds::dn::BNode<T>* parent = tmp->p;
    
    if(tmp->left != NULL)
    {
        return TreeMaximum(x->left);
    }
    while(parent != NULL && tmp == parent->left)
    {
        tmp = parent;
        parent = parent->p;
    }
    return parent;
}


int main()
{
	ds::dn::BNode<int>* tree = NULL;
	ds::dn::BSTInsert(tree,20);
    ds::dn::BSTInsert(tree,5);
    ds::dn::BSTInsert(tree,7);
    ds::dn::BSTInsert(tree,29);
    ds::dn::BSTInsert(tree,34);
    ds::dn::BSTInsert(tree,12);
    ds::dn::BSTInsert(tree,9);
	ds::dn::BSTInsert(tree,8);
	ds::dn::BSTInsert(tree,17);
	ds::dn::BSTInsert(tree,14);
	ds::dn::BSTInsert(tree,2);
	ds::dn::BSTInsert(tree,11);

	PreOrderPrint(tree);
    std::cout << "\n";
	ds::dn::BNode<int>* min = TreeMinimum(tree);
	std::cout << "min is: " << min->data << '\n';

	ds::dn::BNode<int>* max = TreeMaximum(tree);
	std::cout << "max is: " << max->data << "\n";

	ds::dn::BNode<int>* success = TreeSuccessor(tree); // dunno if this works
	std::cout << "successor is: " << success->data << "\n";

    ds::dn::BNode<int>* predec  = TreePredecessor(tree);
    std::cout << "predecessor is: " << predec->data << std::endl;

    return 0;
}