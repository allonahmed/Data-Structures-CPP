#include <iostream>
#include <string>
#include "Node.h"
#include "Pair.h"
#include "Iterator.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "Map.h"
#include "Editor.h"
#include <cmath>

int countDigit(int n) 
{ 
    int count = 0; 
    while (n != 0) 
	{ 
        n = n / 10; 
        ++count; 
    } 
    return count; 
}

ds::sn::Node<int>* Sum(ds::sn::Node<int>* oper1,ds::sn::Node<int>* oper2)
{	
	// place the data in both linked list into a stack
	// top * 10^size-1 (size is the ammount of digits in the stack) to find the two values we need to add
	// put the sum of the two numbers reverse where each digit represents data in linked list
	// put new sum into stack and then put each value into a new linked list;
	ds::sn::Node<int>* current = NULL, *tmp1 = oper1, *tmp2 = oper2;
	ds::sn::Stack<int>* stack1, *stack2, *stack3;
	int size1 = 0, size2 = 0, sum1 = 0, sum2 = 0;
	while (tmp1->GetLink() != NULL)
	{
		stack1->Push(tmp1->GetData());
		tmp1 = tmp1->GetLink();
		size1++;
	}
	while (tmp2->GetLink() != NULL)
	{
		stack2->Push(tmp2->GetData());
		tmp2 = tmp2->GetLink();
		size2++;
	}	
	while(0 < size1)
	{
		sum1 += stack1->Top()*(pow(10,size1-1));
		size1--;
	}
	while(0 < size2)
	{
		sum2 += stack2->Top()*(pow(10,size2-1));
		size2--;
	}

	int sum3 = sum1 + sum2;
	int size3 = countDigit(sum3);
	int tmp = sum3;

	//next we want to push each digit into the stack so we can put it back into a linked list
	while(size3 > 0)
	{	
		int power = pow(10,size3-1);
		stack3->Push(sum3/(int)power);
		tmp = sum3 % power;
		size3--;
	}

	while(!stack3->IsEmpty()){
		current->GetData() = stack3->Top();
		current = current->GetLink();
		stack3->Pop();
	}
	return current;
}


ds::sn::Node<int>* GenerateList(int n)
{
    int s = (n <= 0)?(10):(n);
    ds::sn::Node<int>* root = new ds::sn::Node<int>(0);

    for(int i = 0;i < s;i += 1)
    {
        ds::sn::Node<int>* tmp = new ds::sn::Node<int>(0,root);
        root = tmp;
    }

    ds::sn::Iterator<int>* iter = new ds::sn::Iterator<int>(root);
    
    while(iter->HasNext())
    {
        iter->Next() = (rand() % 10) + 1;
    }
    return root;
} 

template <typename T>
void TraverseList(ds::sn::Node<T>* root)
{
	ds::sn::Node<T>* tmp = root;
	while(tmp->GetLink() != NULL)
	{
		std::cout << tmp->GetData() << " ";
		tmp = tmp->GetLink();
	}
}

// class Editor {};

template <class T>
class Editor
{
    private:
        ds::da::Deque<T>* deck;
    public:
        Editor()
		{
            std::cout << Write() << std::endl;
        }
        Editor(ds::da::Deque<T>* deck) : deck(deck){}

		Editor(const Editor &obj)
		{

		}

        ~Editor(){}

        void Read(char e)
        {
            if(e == '#' && !deck->IsEmpty())
            {
                deck->RemoveLast();
            }
            else
            {
                deck->InsertLast(e);
            }
        }
        std::string Write()
        {
            std::string edit;
            edit+=deck->First();
            return edit;
        }     
};



class DayPlanner {
	DayPlanner(){
		std::cout<< "hello world" << std::endl;
	}
};

std::string Decode(std::string str)
{
	return "";
}

int main()
{
	Editor<int> h;
	h.Read('e');


	

	// ds::sn::Node<int>* link1 = GenerateList(3);
	// ds::sn::Node<int>* link2 = GenerateList(3);
	// std::cout << "\nLinked List 1: ";
	// TraverseList(link1);
	// std::cout << "\nLinked List 2: ";
	// TraverseList(link2);

	// std::cout << "\nreverse sum = ";

	// ds::sn::Node<int>* test = Sum(link1, link2); // gives me segmentation error

	// TraverseList(test);


	return 0;
}
