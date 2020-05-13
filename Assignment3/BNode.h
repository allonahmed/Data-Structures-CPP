#ifndef BNODE_H
#define BNODE_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	namespace da
	{
		template <class T>
		class BNode
		{
		public:
			T** data;
			int capacity;
			int size;

			BNode() : capacity(128), size(0) 
			{
				data = new T*[this->capacity];

				for(int i = 0;i < this->capacity;i += 1)
				{
					data[i] = NULL;
				}
			}

			BNode(int capacity) : capacity(capacity), size(0) 
			{
				if(this->capacity < 0)
				{
					this->capacity = 128;
				}

				data = new T*[this->capacity];

				for(int i = 0;i < this->capacity;i += 1)
				{
					data[i] = NULL;
				}
			}

			~BNode() 
			{
				for(int i = 0;i < capacity;i += 1)
				{
					if(data[i] != NULL)
					{
						delete data[i];
					}
				}
				delete[] data;
			}
		};

		template <typename T>
		T* Parent(BNode<T>& t,int idx)
		{
			int pidx = (idx - 1) / 2;
			if(pidx < t.size)
			{
				return t.data[pidx];
			}
			return NULL;
		}

		template <typename T>
		T* Left(BNode<T>& t,int idx)
		{
			int lidx = idx * 2 + 1;
			if(lidx < t.size)
			{
				return t.data[lidx];
			}
			return NULL;
		}

		template <typename T>
		T* Right(BNode<T>& t,int idx)
		{
			int ridx = idx * 2 + 2;
			if(ridx < t.size)
			{
				return t.data[ridx];
			}
			return NULL;
		}
	}

	namespace sn
	{
		template <class T>
		class BNode
		{
		public:
			T data;
			BNode<T>* left;
			BNode<T>* right;

			BNode() : data(T()), left(NULL) , right(NULL) {}

			BNode(const T& data) : data(data), left(NULL) , right(NULL) {}

			~BNode() {}
		};

		template <class T>
		BNode<T>* Copy(const BNode<T>* root)
		{
			if(root == NULL)
			{
				return NULL;
			}

			BNode<T> *tmp = new BNode<T>(root->data);
			tmp->left = Copy(root->left);
			tmp->right = Copy(root->right);
			return tmp;
		}

		template <class T>
		void Clear(BNode<T>*& root)
		{
			if(root != NULL)
			{
				Clear(root->left);
				Clear(root->right);
				delete root;
				root = NULL;
			}
		}
	}

	namespace dn
	{
		template <class T>
		class BNode
		{
		public:
			T data;
			BNode<T>* p;
			BNode<T>* left;
			BNode<T>* right;

			BNode() : data(T()), p(NULL), left(NULL), right(NULL) {}

			BNode(const T& data) : data(data), p(NULL), left(NULL), right(NULL) {}

			BNode(const T& data,BNode<T>* p) : data(data), p(p), left(NULL), right(NULL) {}
			
			~BNode() {}
		
			bool IsLeaf(BNode<T>* root)
			{
				if(root != NULL)
				{
					return root->left == NULL && root->right == NULL;
				}
				return false;
			}

			void InOrderPrint(BNode<T>* root)
			{
				if(root != NULL)
				{
					InOrderPrint(root->left);
					std::cout << root->data << " ";
					InOrderPrint(root->right);
				}
			}

			void PreOrderPrint(BNode<T>* root)
			{
				if(root != NULL)
				{                                    
					std::cout << root->data << " ";
					PreOrderPrint(root->left);
					PreOrderPrint(root->right);
				}
			}

			void PostOrderPrint(BNode<T>* root)
			{
				if(root != NULL)
				{                                    
					PostOrderPrint(root->left);
					PostOrderPrint(root->right);
					std::cout << root->data << " ";
				}
			}

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
			
			BNode<T>* TreeMinimum(BNode<double>* root)
			{
				BNode<double>* tmp = root;
				while(tmp->left != NULL)
				{
					tmp = tmp->left;
				}
				return tmp;
			}
		
			BNode<T>* TreeMaximum(BNode<double>* root)
			{
				BNode<double>* tmp = root;
				while(tmp->right != NULL)
				{
					tmp = tmp->right;
				}
				return tmp;
			}

			void BTRemove(ds::dn::BNode<T>* root,const T& value)
			{
				return;
			}

		};


		template <typename T>
		BNode<T>* Copy(const BNode<T>* root,BNode<T>* p)
		{
			if(root == NULL)
			{
				return NULL;
			}

			BNode<T> *tmp = new BNode<T>(root->data);
			tmp->p = p;
			tmp->left = Copy(root->left,tmp);
			tmp->right = Copy(root->right,tmp);
			return tmp;
		}

		/*Call this version of Copy()*/
		template <typename T>
		BNode<T>* Copy(const BNode<T>* root)
		{
			if(root == NULL)
			{
				return NULL;
			}
			return Copy(root,NULL);
		}

		template <typename T>
		void Clear(BNode<T>*& root)
		{
			if(root != NULL)
			{
				Clear(root->left);
				Clear(root->right);
				delete root; 
				root = NULL;
			}
		}
	}
}
		
#endif
