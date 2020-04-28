#include <iostream>
#include <string>
#include "Node.h" 

int Tribonacci(int n)
{
	if(n<=0){
		return 0;
	}
	else if(n==1){
		return 1;
	}
	else if(n==2){
		return 1;
	}
	else{
		return Tribonacci(n-1) +Tribonacci(n-2) + Tribonacci(n-3);
	}
}

int MissingSequentialMultiple(ds::dn::Node<int>* data,int n,int i)
{
	return 0;
}

int main()
{
	std::cout << Tribonacci(5);
}
