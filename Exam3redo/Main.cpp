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

// ds::da::Vector<int> BoundMode(ds::da::Vector<int>& data,int upb)
// {
// 	//range from 0-to upperbound ex. (0-10)
// 	ds::da::Vector<int> mode;
// 	ds::da::Map<int, int> map;
// 	int x = 1;
// 	for (int i  = 0; i < data.Size(); i+=1)
// 	{
// 		if(map.Contains(data[i])==false)
// 		{
// 			map.Put(data[i], 1);
// 		}
// 		else if(map.Contains(data[i]))
// 		{
// 			map.Put(data[i], map.Get(data[i])++);
// 		}
// 		if(x > map.Get(data[i]))
// 		{
// 			x = map.Get(data[i]);
// 		}
// 	}

// 	mode.Insert(data[x]);
// 	return ds::da::Vector<int>();
// }  // not finished 

ds::da::Vector<int> BoundMode(ds::da::Vector<int>& data,int upb)
{
	ds::da::Vector<int> results;
	if(upb < 1)
	{
		return results; // which is empty
	}
	int hash[upb+1] = {0};
	int count = 0;

	for (int i = 0; i <= data.Size();i ++)
	{
		hash[data[i]]++;
		if (count < hash[data[i]])
		{
			count  = hash[data[i]]; // to get max frequency
		}
	}

	if (count < 2) // means there is no mode
	{
		return results;
	}

	for (int i = 0; i <data.Size(); i++) 
	{
		if( hash[i] == count)
		{
			results.InsertFirst(i);
		}
	}
	return results;
}

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

/* hint use a queue*/
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
	Point loc = s;
	int startpoint = PointToIndex(s);
	int endpoint = PointToIndex(e);
	int locpoint = startpoint;

	while ( locpoint != endpoint)
	{
		if (s.x == e.x)
		{
			if (s.y < e.y)
			{
				loc.y++;
			}
			else
			{
				loc.y--;
			}
		}
		else
		{
			if(s.x < e.x)
			{
				loc.x++;
			}
			else
			{
				loc.x--;
			}
		}
		locpoint = PointToIndex(loc);
		if (locpoint != endpoint && bd[locpoint] == 'x');
		{
			return false;
		}
	}
	return true;
	

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

template <typename T>
void InsertionSort(ds::dn::Node<T>* root) //for the insertion sort we have to section off the elements and sort them from largest to smaleler
{
	ds::dn::Node<T>* tmp = root;
	for(tmp->GetData(); tmp->GetNext()!=NULL && tmp!=NULL; tmp = tmp->GetNext())
	{
		ds::dn::Node<T>* tmp2 = tmp->GetNext();
		while ( tmp2->GetPrev()!=NULL && tmp2->GetPrev()->GetData() > tmp2->GetData())
		{
			Swap(tmp2, tmp2->GetPrev());
			tmp2 = tmp2 ->GetPrev();
		}
	}
} // doesnt print the largest data

ds::dn::Node<int>* GenerateList(int n)
{
    int nc = (n <= 0)?(10):(n);
    ds::dn::Node<int>* root = new ds::dn::Node<int>(rand() % 99 + 1);
    ds::dn::Node<int>* tmp = root;
    for(int i = 0;i < nc;i += 1)
    {
        tmp->SetNext(new ds::dn::Node<int>(rand() % 99 + 1));
        tmp->GetNext()->SetPrev(tmp);
        tmp = tmp->GetNext();
    }

    return root;
}
template <typename T>
void TraverseList(ds::dn::Node<T>* root)
{
	ds::dn::Node<T>* tmp = root;
	while(tmp->GetNext() != NULL)
	{
		std::cout << tmp->GetData() << " ";
		tmp = tmp->GetNext();
	}
}


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
	while(iter->HasNext())
	{
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

	// ds::da::Vector<int> test = BoundMode(hello, upb);
	// printVector(test);

	// std::cout << std::boolalpha << IsValidParentheses("()(())((()))");

	ds::dn::Node<int>* test = GenerateList(10);
	// test->GetData() = 20;
	// test->GetNext()->GetData() = 25;
	std::cout << "\nRandomly generated link list: ";
	TraverseList(test);
	std::cout << "\nSorted linked list: ";
	InsertionSort(test);
	TraverseList(test);


}
