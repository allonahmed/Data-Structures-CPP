#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Node.h"

namespace ds
{
	template <class T>
	class HashTable
	{
	private:
		dn::Node<T>** heads; 
		int (*hash)(const T& data);
		int capacity;

		HashTable();		
	public:
		HashTable(int value,int (*func)(const T& data)) : capacity(value), hash(func) 
		{
			heads = new dn::Node<T>*[capacity];

			for(int i = 0;i < capacity;i += 1)
			{
				heads[i] = NULL;
			}
		}
	
		HashTable(const HashTable<T>& obj)
		{
			capacity = obj.capacity;
			hash = obj.hash;
			heads = new dn::Node<T>*[capacity];

			for(int i = 0;i < capacity;i += 1)
			{
				heads[i] = dn::Copy(obj.heads[i]);
			}
		}

		HashTable<T>& operator=(const HashTable<T>& rhs)
		{
			if(this != &rhs)
			{
				for(int i = 0;i < capacity;i += 1)
				{
					dn::Clear(heads[i]);
				}
				delete[] heads;

				capacity = rhs.capacity;
				hash = rhs.hash;
				heads = new dn::Node<T>*[capacity];

				for(int i = 0;i < capacity;i += 1)
				{
					heads[i] = dn::Copy(rhs.heads[i]);
				}			
			}

			return *this;
		}

		~HashTable() 
		{
			for(int i = 0;i < capacity;i += 1)
			{
				dn::Clear(heads[i]);
			}
			delete[] heads;
		}

		bool Search(const T& data)
		{
			int idx = hash(data);
			dn::Node<T>* t = heads[idx];

			while(t != NULL && t->GetData() != data)
			{
				t = t->GetNext();
			}
			return (t != NULL);
		}

		void Insert(const T& data)
		{
			int idx = hash(data);

			if(heads[idx] == NULL)
			{
				heads[idx] = new dn::Node<T>(data);
			}
			else 
			{
				heads[idx]->SetPrev(new dn::Node<T>(data));
				heads[idx]->GetPrev()->SetNext(heads[idx]);
				heads[idx] = heads[idx]->GetPrev();
			}
		}

		void Remove(const T& data)
		{
			int idx = hash(data);

			if(heads[idx] != NULL)
			{
				if(heads[idx]->GetNext() == NULL && heads[idx]->GetData() == data)
				{
					delete heads[idx];
					heads[idx] = NULL;
				}
				else if(heads[idx]->GetData() == data)
				{
					dn::Node<T>* t = heads[idx];
					heads[idx] = heads[idx]->GetNext();
					delete t;
					t = NULL;

					if(heads[idx] != NULL)
					{
						heads[idx]->SetPrev(NULL);
					}
				}
				else 
				{
					dn::Node<T>* t = heads[idx]->GetNext();

					while(t != NULL && t->GetData() != data)
					{
						t = t->GetNext();
					}

					if(t != NULL)
					{
						t->GetPrev()->SetNext(t->GetNext());

						if(t->GetNext() != NULL)
						{
							t->GetNext()->SetPrev(t->GetPrev());
						}
						delete t;
						t = NULL;
					}
				}
			}
		}

		dn::Node<T>* GetSlot(const T& data)
		{
			return heads[hash(data)];
		}
	};
}
		
#endif
