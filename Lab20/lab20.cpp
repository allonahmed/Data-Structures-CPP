#include <iostream>
#include <string>
#include "Node.h" //Node()
#include "Pair.h" //Pair()
#include "Iterator.h" //Iterator(), PairIterator()
#include "Set.h" //Set()
#include "List.h" //Vector(), LinkedList()
#include "Map.h" //Map()
#include<bits/stdc++.h> 


template <typename T>
void swap(T* a, T* b){
	T t = *a;
	*a = *b;
	*b = t;
}


void bubbleSort(ds::da::Vector<int>& data){
	for(int i = 0; i<data.Size()-1; i++){
		for(int j = 0; j<data.Size()-i-1; j++){
			if(data[j] > data[j+1]){
				swap(&data[j], &data[j+1]);
			}
		}
	}
}

int DuplicatesSum(ds::da::Vector<int>& data)
{
	ds::da::Map<int, int> map;
	ds::da::Vector<int> count;
	
	bubbleSort(data);
	int sum = 0;
	for(int i = 0; i < data.Size()-1; i++){
		if(data[i]==data[i+1] && count.Contains(data[i])!=true){
			count.InsertLast(data[i]);
		}
	}
	for(int i = 0; i<count.Size(); i++){
		sum += count[i];
	}
	return sum;
} //method 1

int DuplicatesSum1(ds::da::Vector<int>& data){
	ds::da::Map<int, int> map;
	int sum = 0;

	for(int i = 0; i<data.Size(); i+=1){
		if(map.Contains(data[i]))
		{
			if(map.Get(data[i])<=1)
			{
				map.Get(data[i])++;
				sum += data[i];
			}
			else
			{
				continue;
			}
		}
		else
		{
			map.Put(data[i], 1);
		}
	}
	return sum;
} //method 2

int main()
{
	ds::da::Vector<int> vec, vec1;
	vec.InsertFirst(1);
	vec.InsertFirst(2);
	vec.InsertFirst(2);
	vec.InsertFirst(3);
	vec.InsertFirst(2);
	vec.InsertFirst(4);
	vec.InsertFirst(1);
	vec1.InsertFirst(1);
	vec1.InsertFirst(1);
	vec1.InsertFirst(1);
	vec1.InsertFirst(3);
	vec1.InsertFirst(3);
	vec1.InsertFirst(4);
	vec1.InsertFirst(5);
	vec1.InsertFirst(5);
	vec1.InsertFirst(5);
	
	
	std::cout << "duplicate sum of vec: " << DuplicatesSum(vec) << std::endl;
	std::cout << "duplicate sum of vec1: " << DuplicatesSum(vec1) << std::endl;
	std::cout << "duplicate sum of vec: " << DuplicatesSum1(vec) << std::endl;
	std::cout << "duplicate sum of vec1: " << DuplicatesSum1(vec1) << std::endl;
}
