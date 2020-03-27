#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"

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

template<typename T>
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

template <typename T>
void SwapNodes(ds::Node<T>* root,ds::Node<T>* nptr1,ds::Node<T>* nptr2)
{
  ds::Node<T>* tmp = root, *prev, *prev2, *tmp2 = root, *next, *next2;
  if (nptr1==nptr2){
    return;
  }
  while(tmp!=nptr1){
    prev = tmp;
    next = tmp->GetLink()->GetLink();
    tmp = tmp->GetLink();
    
  }
  while(tmp2!=nptr2){
    prev2 = tmp2;
    next2 = tmp2->GetLink()->GetLink();
    tmp2 = tmp2->GetLink();
  }

  prev->SetLink(tmp2);
  tmp2->SetLink(next);
  prev2->SetLink(tmp);
  tmp->SetLink(next2);

  nptr1 = tmp;
  nptr2 = tmp2;
  delete tmp;
  tmp =NULL;
  delete tmp2;
  tmp2 = NULL;   
}
template <typename T>
void RemoveAll(ds::Node<T>* root,const int target)
{
  ds::Node<T>* tmp = root, *prev;
  while(tmp!=NULL){
    if(tmp->GetData()==target){
      ds::Node<T>* del = tmp;
      tmp = tmp->GetLink();
      prev->SetLink(tmp);
      delete(del);
      del = NULL;
    }
    if(tmp->GetData()!=target){
      prev = tmp;
      tmp = tmp->GetLink();
    }
  }
}
template <typename C>
double  SecondLargest(ds::Node<C>* root)
{
  double max = root->GetData(); // assume root is largest
  double secondMax = root->GetData(); 
  root = root->GetLink(); // follow to the next element
  while (root != NULL)
  {
    // find maximum
    if(root->GetData() > max)
    {
      secondMax = max;
      max = root->GetData();
    }
    // update second max
    if( root->GetData() > secondMax && root->GetData() != max)
    {
      secondMax = root->GetData();
    }

    root = root->GetLink();
  }
  return secondMax;
}

int main()
{
  srand(time(NULL));
	ds::Node<int>* value = NULL;
	for(int i = 1;i < 10;i += 1)
	{
    int num = rand() %100 +1;
		AppendToBack(value,num);
	}
  Traverse(value);
}
