#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"

template <typename T>
ds::Node<T>* ReverseCopy(ds::Node<T>* root)
{ 
    ds::Node<T>* tmp = root, *prev = NULL, *next = NULL;

    while(tmp!=NULL){
      next =tmp->GetLink();
      tmp->GetLink() = prev->GetLink();
      prev = tmp;
      tmp = next;
    }
    tmp = prev;

  
    return NULL;
}

void SelectionSort(ds::Node<double>* root)
{
    return;
}

/********************************
 * Helper Functions : Begin
 *******************************/
template <typename T>
void AppendToBack(ds::Node<T>*& root,const T& data)
{
	if(root == NULL)
	{
		root = new ds::Node<T>(data);
	}
	else
	{
		ds::Node<T>* tmp = root;

		while(tmp->GetLink() != NULL)
		{
			tmp = tmp->GetLink();
		}
		tmp->SetLink(new ds::Node<T>(data));
	}
}

template<typename T>
void Traverse(ds::Node<T>* root)
{
	//Never Traverse the actual root
	ds::Node<T>* tmp = root;
	std::cout << "[";

	while(tmp != NULL)
	{
		std::cout << tmp->GetData();

		if(tmp->GetLink() != NULL)
		{
			std::cout << ",";
		}
		tmp = tmp->GetLink();
	}
	std::cout << "]";
}

//Print() - prints elements of a linked list in a line
template <typename T>
void Print(ds::Node<T>* root)
{
    ds::sn::Iterator<T>* iter = new ds::sn::Iterator<T>(root);

    while(iter->HasNext())
    {
        std::cout << iter->Next() << " ";
    }
    std::cout << "\n"; 
}

//GenerateList() - creates a linked list of random decimal numbers
ds::Node<double>* GenerateList(int n)
{
    int s = (n <= 0)?(10):(n);
    ds::Node<double>* root = new ds::Node<double>(0);

    for(int i = 1;i < s;i += 1)
    {
        ds::Node<double>* tmp = new ds::Node<double>(0,root);
        root = tmp;
    }

    ds::sn::Iterator<double>* iter = new ds::sn::Iterator<double>(root);
    
    while(iter->HasNext())
    {
        iter->Next() = (rand() % 10000) / 100.0;
    }
    return root;
} 

//Swap() - swaps the data of two nodes of a linked list
template <typename T>
void Swap(ds::Node<T>* a,ds::Node<T>* b)
{
    T t = a->GetData();
    a->SetData(b->GetData()); //alternate: a->GetData() = b->GetData();
    b->SetData(t);
}

/********************************
 * Helper Functions : End
 *******************************/

int main()
{ 
  int n = 10;
  
  ds::Node<double>* value = new ds::Node<double>;
 for(double i = 0;i < 10;i += 1)
	{
		AppendToBack(value,i);
	}
  Traverse(value);

  std::cout << "reverse: \n";
  ReverseCopy(value);
    
}
