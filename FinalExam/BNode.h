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
