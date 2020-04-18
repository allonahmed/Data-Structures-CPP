#include <iostream>
#include <string>
#include "Array.h"
#include "Node.h"
#include "Iterator.h"
#include "List.h"
#include "Queue.h"
#include "Set.h"
#include "Stack.h"
#include "Deque.h"
#include <map>
#include <math.h> 

void LetterCount(std::string s)
{
    std::map < char, int > mymap; 
    char val;
    for ( int i = 0; i < s.size(); i++ ) 
    {
        val = s[i];
        mymap[val] ++;
    }
    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it){
        std::cout << it->first << " => " << it->second << '\n';
    }

}

std::string ABStringWithExceptions(int m,int n)
{
	std::string ab = "";
	double div = 3;
	double md = m, nd = n;
	if(((md/nd)>div||((nd/md)>div))) //have to type cast
	{
		return ab;
	}
	else 
	{
		char valm, valn;
		int max = (m>n)?(m):(n);
		int min = (m<n)?(m):(n);
		if(max==n){
			valm = 'a';
		}
		else{
			valm = 'b';
		}
		if(min==m){
			valn = 'b'; 
		}
		else{
			valn = 'a';
		}
		int size = n + m;

		for(int i = 0; i < size; i++)
		{
			if(i%3==0)
			{
				ab+= valm;
			}
			if(i%3==1){
				ab+= valm;
			}
			if(i%3==2){
				ab+= valn;
			}
		}
		return ab;
	}	
}

int ToInteger(std::string num)
{
	ds::da::Stack<int> ints;
	int size= num.size();
	int val = 0;
	int abs = 1;
	for(int  i = 0; i<num.size(); i+=1)
	{

		if(i==0 && num[i]=='-')
		{
			abs= abs*-1;
			--size;
		}
		else
		{
			if(num[i]-48>9){
				return -2147483648;
			}
			ints.Push(num[i]-48);
			// std::cout << ints.Top() << " ";
			val = val + (ints.Top()*std::pow(10,(size-1)));	
			--size;
		}	
	}
	if(val*abs>-2147483648 && val*abs<2147483647){
		return val*abs;
	}
	else{
		return -2147483648;
	}
}

int main()
{

	std::cout<< "ToInteger: " << ToInteger("2109845") << std::endl;



}