#include <iostream>
#include <string>
#include "Node.h" 
#include "List.h" 
#include "Map.h"
#include "HashTable.h" 
using namespace std;



ds::da::Vector<int> TwoSum(ds::da::Vector<int>& data,int target)
{
	ds::da::Map<int, int> map;
	ds::da::Vector<int> vec(2);

	for(int i = 0; i < data.Size(); i+=1) //On)
	{
		map.Put(data[i], i);
	}
	for(int i = 0; i<data.Size(); i+=1 ){ //O(n)
		int dif = target - data[i];   // diference in target and current element
		if(map.Contains(dif) && map[dif] != 1){ 
			//if map contains the difference, we have both elements
			vec.InsertFirst(i);
			vec.InsertFirst(map[dif]);
			break;
		}
	}
	return vec;
}


int SingleNumber(ds::da::Vector<int>& data)
{
	return 0;
}

int main()
{

	ds::da::Vector<int> vec;
	vec.InsertLast(7);
	vec.InsertLast(9);
	vec.InsertLast(6);
	vec.InsertLast(1);
	vec.InsertLast(4);
	vec.InsertLast(13);
	int target = 17;

	ds::da::Vector<int> test = TwoSum(vec, target);
	std::cout << "[";
	for(int i = 0; i < test.Size(); i++)
	{
		if(i<test.Size()-1)
		{
			std::cout << test[i] << ", ";
		}
		else{
			std::cout << test[i];
		}
	}
	std:: cout << "]\n";
	return 0;
	
}
