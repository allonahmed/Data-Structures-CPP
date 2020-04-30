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
#include "Map.h"
#include "HashTable.h"

//Question 1

ds::da::Vector<int> BoundMode(ds::da::Vector<int>& data,int upb)
{
	//range from 0-to upperbound ex. (0-10)
	ds::da::Vector<int> mode;
	ds::da::Map<int, int> map;
	int x = 1;
	for (int i  = 0; i < data.Size(); i+=1)
	{
		if(map.Contains(data[i])==false)
		{
			map.Put(data[i], 1);
		}
		else if(map.Contains(data[i]))
		{
			map.Put(data[i], map.Get(data[i])++);
		}
		if(x > map.Get(data[i]))
		{
			x = map.Get(data[i]);
		}
	}

	mode.Insert(data[x]);
	return ds::da::Vector<int>();
}  // not finished 

ds::da::Vector<int> generateList(int size, int max, int min)
{
	srand(time(NULL));
	ds::da::Vector<int> list;
	for(int i = 0; i < size; i+=1)
	{
		list.InsertLast((rand() % max) - min);
	}
	return list;
}

template <typename T>
void printVector(ds::da::Vector<T> vec)
{
	for (int  i = 0; i < vec.Size(); i+=1)
	{
		if(i==0)
		{
			std::cout << "[" << vec[i] << " ";
		}
		else if(i==vec.Size()-1)
		{
			std::cout << vec[i] << "]\n";
		}
		else
		{
			std::cout << vec[i] << ", ";
		}
	}
}

//Question 2

struct Point
{
	int x;
	int y;
};

int PointToIndex(Point& p)
{
	return (p.x - 1) * 8 + (p.y - 1);
}

bool RookMove(ds::da::Vector<int>& bd,Point& s,Point& e) // 64 elements(8X8) values only go up to 8
//keep track of positions visited...
{
	return false;
}

//Question 3

bool IsValidParentheses(std::string str) //cut string in half and count the parenthesis
{
	if(str.size()==0) 
	{
		return true;
	}
	ds::da::Stack<char> stack;
	
	for(const char prth : str)
	{
		if(!stack.IsEmpty() && ((prth == ')' && stack.Top() == '(')))
		{
			stack.Pop();
		}
		else
		{
			stack.Push(prth);
		}
	}
	return stack.IsEmpty()?(true):(false);
}



//Question 4

template <typename T>
void Swap(ds::dn::Node<T>* a,ds::dn::Node<T>* b)
{
	if(a != NULL && b != NULL)
	{
		T t = a->GetData();
		a->SetData(b->GetData());
		b->SetData(t);
	}
}

template<typename T>
void insert(ds::dn::Node<T>* head, ds::dn::Node<T>* newN)
{
	ds::dn::Node<T>* tmp;
	if(head == NULL) // empty ll
	{
		head = newN;
	}

	else if(head->GetData()>=newN->GetData())
	{
		newN->GetNext() = head;
		newN->GetNext()->SetPrev(newN);
		head = newN;
	}
	else
	{
		tmp = head;
		while(tmp->GetNext() != NULL && tmp->GetNext()->GetData() < newN->GetData())
		{
			tmp = tmp->GetNext();
		}

		if(tmp->GetNext()NULL)
		{
			newN->GetNext()->SetPrev(newN);
		}
		tmp->GetNext() = newN;
		newN->GetPrev= tmp;
	}
}


template <typename T>
void InsertionSort(ds::dn::Node<T>* root)
{
	ds::dn::Node<T>* tmp1, tmp2 = root;
	while( tmp2 != NULL)
	{
		ds::dn::Node<T>* next = tmp2->GetNext();
		tmp2->GetPrev() = tmp2->GetNext() = NULL;
		insert(&tmp1, tmp2);
		tmp2 = next;
	}
	root = tmp1;
} // no time to test, no idea if it works



//Question 5
/*Write the definition of the function IsProperSubSet() whose header is
bool IsProperSubSet(Set<T>& A,Set<T>& B)
template <typename T>
The function returns true if A is a proper subset of B; otherwise, it returns false. A set A is a
proper set of set B if every element of A belongs to B and there exists at least one element of
B that does not belong to A.*/

template <typename T>
bool IsProperSubSet(ds::da::Set<T>& A,ds::da::Set<T>& B)
{
	if (A.Size()==B.Size())
	{
		return false;
	}
	
	ds::sn::Iterator<T>* iter = A.ToIterator();
	while(iter->HasNext()){
		T item = iter->Next();
		if(B.Contains(item)==false)
		{
			return false;
		}
	}
	return true;
}


ds::sn::Set<int> GenerateSet(int n)
{
    int s = (n <= 0)?(10):(n);
    ds::sn::Set<int> S;

    while(S.Size() < s)
    {
        S.Insert((rand() % 10 + 1));
    }
    return S;
} 
int main()
{
	// int upb = 10;
	// ds::da::Vector<int> hello = generateList(15, upb, 1);

	// printVector(hello);

	// printVector(BoundMode(hello, upb));

	// std::cout << std::boolalpha << IsValidParentheses("()(())((()))");




}
