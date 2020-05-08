#include <iostream>
#include <string>
#include "BNode.h" 
#include "Node.h"
#include <cstdlib>
#include <ctime>
#include "Stack.h"

namespace ds::da
{
    template <typename T>
    bool IsLeaf(BNode<T>& root,int idx)
    {
        if(idx >= 0 && idx < root.size && root.data[idx] != NULL && (2 * idx) < root.capacity)
        {
            return Left(root,idx) == NULL && Right(root,idx) == NULL;
        }
        return false;
    }

    template <typename T>
    void InOrderPrint(BNode<T>& root,int idx)
    {
        if(idx < root.capacity && root.data[idx] != NULL)
        {
            InOrderPrint(root,2 * idx + 1);
            std::cout << *(root.data[idx]);
            InOrderPrint(root,2 * idx + 2);
        }
    }

    template <typename T>
    void InOrderPrint(BNode<T>& root)
    {
        InOrderPrint(root,0);
    }

    template <typename T>
    void PreOrderPrint(BNode<T>& root,int idx)
    {
        if(idx < root.capacity && root.data[idx] != NULL)
        {                                    
            std::cout << *(root.data[idx]);
            PreOrderPrint(root,2 * idx + 1);
            PreOrderPrint(root,2 * idx + 2);
        }
    }

    template <typename T>
    void PreOrderPrint(BNode<T>& root)
    {
        PreOrderPrint(root,0);
    }

    template <typename T>
    void PostOrderPrint(BNode<T>& root,int idx)
    {
        if(idx < root.capacity && root.data[idx] != NULL)
        {                                    
            PostOrderPrint(root,2 * idx + 1);
            PostOrderPrint(root,2 * idx + 2);
            std::cout << *(root.data[idx]);
        }
    }

    template <typename T>
    void PostOrderPrint(BNode<T>& root)
    {
        PostOrderPrint(root,0);
    }

    template <typename T>
    void BTInsert(BNode<T>& root,const T& value)
    {
        if(root.size < root.capacity)
        {
            root.data[root.size] = new T(value);
            root.size += 1;
        }
    }

    template <typename T>
    void BSTInsert(BNode<T>& root,const T& value)
    {
        int x = 0;

        while(x < root.capacity)
        {
            if(root.data[x] == NULL)
            {
                root.data[x] = new T(value);
                root.size += 1;
                break;
            }
            else if(*(root.data[x]) > value)
            {
                x = 2 * x + 1;
            }
            else 
            {
                x = 2 * x + 2;
            }
        }
    }

    template <typename T>
    T* BTSearch(BNode<T>& root,const T& value)
    {
        for(int i = 0;i < root.size;i += 1)
        {
            if(*(root.data[i]) == value)
            {
                return root.data[i];
            }
        }
        return NULL;
    }

    template <typename T>
    T* BSTSearch(BNode<T>& root,const T& value)
    {
        int x = 0;
        while(x < root.capacity)
        {
            if(root.data[x] == NULL)
            {
                return NULL;
            }
            else if(root.data[x] == value)
            {
                return root.data[x];
            }
            else if(*(root.data[x]) > value)
            {
                x = 2 * x + 1;
            }
            else 
            {
                x = 2 * x + 2;
            }
        }
        return NULL;
    }
}

namespace ds::sn
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
            std::cout << root->data;
            InOrderPrint(root->right);
        }
    }

    template <typename T>
    void PreOrderPrint(BNode<T>* root)
    {
        if(root != NULL)
        {                                    
            std::cout << root->data;
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
            std::cout << root->data;
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
    void BTInsert(BNode<T>*& root,const T& value)
    {
        if(root == NULL)
        {
            root = new BNode<T>(value);
            return;
        }

        int sz = Size(root);
        int p = sz;
        Stack<int> anc;
        
        while(p > 0)
        {
            p = (p - 1) / 2;
            anc.Push(p);
        } 

        BNode<T>* t = root;
        int pp = 0;
        anc.Pop();

        while(!anc.IsEmpty())
        {
            p = anc.Top();
            anc.Pop();

            if(2 * pp + 1 == p)
            {
                t = t->left;
            }
            else 
            {
                t = t->right;
            }
            pp = p;
        }

        if(t->left == NULL)
        {
            t->left = new BNode<T>(value);
        }
        else
        {
            t->right = new BNode<T>(value);
        }
    }

    template <typename T>
    void BSTInsert(BNode<T>*& root,const T& value)
    {
        if(root == NULL)
        {
            root = new BNode<T>(value);
        }
        else if(root->data > value)
        {
            BSTInsert(root->left,value);            
        }
        else
        {
            BSTInsert(root->right,value);            
        }
    }

    template <typename T>
    BNode<T>* BTSearch(BNode<T>* root,const T& value)
    {
        if(root == NULL)
        {
            return NULL;
        }
        else if(root->data == value)
        {
            return root;
        }
        else
        {
            BNode<T>* ltNode = BTSearch(root->left,value);
            BNode<T>* rtNode = BTSearch(root->right,value);

            if(ltNode == NULL && rtNode == NULL)
            {
                return NULL;
            }
            else if(ltNode != NULL)
            {
                return ltNode;
            }
            else
            {
                return rtNode;
            }
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
    void BTInsert(BNode<T>*& root,const T& value)
    {
        if(root == NULL)
        {
            root = new BNode<T>(value,NULL);
            return;
        }

        int sz = Size(root);
        int p = sz;
        Stack<int> anc;
        
        while(p > 0)
        {
            p = (p - 1) / 2;
            anc.Push(p);
        } 

        BNode<T>* t = root;
        int pp = 0;
        anc.Pop();

        while(!anc.IsEmpty())
        {
            p = anc.Top();
            anc.Pop();

            if(2 * pp + 1 == p)
            {
                t = t->left;
            }
            else 
            {
                t = t->right;
            }
            pp = p;
        }

        if(t->left == NULL)
        {
            t->left = new BNode<T>(value,t);
        }
        else
        {
            t->right = new BNode<T>(value,t);
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
    BNode<T>* BTSearch(BNode<T>* root,const T& value)
    {
        if(root == NULL)
        {
            return NULL;
        }
        else if(root->data == value)
        {
            return root;
        }
        else
        {
            BNode<T>* ltNode = BTSearch(root->left,value);
            BNode<T>* rtNode = BTSearch(root->right,value);

            if(ltNode == NULL && rtNode == NULL)
            {
                return NULL;
            }
            else if(ltNode != NULL)
            {
                return ltNode;
            }
            else
            {
                return rtNode;
            }
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


// template <typename T>
// ds::dn::BNode<T>* TreePredecessor(ds::dn::BNode<int>* x)
// {
// 	return NULL;
// }


int main()
{
	ds::dn::BNode<int>* tree = NULL;
	ds::dn::BSTInsert(tree,13);
    ds::dn::BSTInsert(tree,5);
    ds::dn::BSTInsert(tree,7);
    ds::dn::BSTInsert(tree,34);
    ds::dn::BSTInsert(tree,12);
    ds::dn::BSTInsert(tree,9);
	ds::dn::BSTInsert(tree,8);
	ds::dn::BSTInsert(tree,17);
	ds::dn::BSTInsert(tree,14);
	ds::dn::BSTInsert(tree,2);
	ds::dn::BSTInsert(tree,11);

	tree->PreOrderPrint(tree);
    std::cout << "\n";
	ds::dn::BNode<int>* min = tree->TreeMinimum(tree);
	std::cout << "min is: " << min->data << '\n';

	ds::dn::BNode<int>* max = tree->TreeMaximum(tree);
	std::cout << "max is: " << max->data << "\n";

	ds::dn::BNode<int>* success = tree->TreeSuccessor(tree); // dunno if this works
	std::cout << "successor is: " << success->data << "\n";

	


}
