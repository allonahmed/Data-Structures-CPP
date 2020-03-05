#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"
#include "Point.h"
#include "Vector.h"

bool IsLine(ds::Vector<Point>& coors)
{
    return false;
}

template<typename T>
int getCount(ds::Node<T>* head)  
{  
    int count = 0; // Initialize count  
    ds::Node<T>* current = head; // Initialize current  
    while (current->GetLink() != NULL)  
    {  
        count++;  
        current = current->GetLink();  
    }  
    return count;  
}  

template<typename T>
ds::Node<T>* MiddleNode(ds::Node<T>* head)
{
    int count = getCount(head);
    if(count%2!=0){
      count = count + 1;
    }
    ds::Node<T>* tmp = head;
    
    // for(int i = 0; i<count/2;i++){
    //     tmp= tmp->GetLink(); 
    // }
    ds::Node<T>* red;
    int i =0;
    while(i<count/2){
      tmp = tmp->GetLink();
      i++;
    }

    
    return tmp;
}



/********************************
 * Helper Functions : Begin
 *******************************/

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
    delete iter;
}

//Print() - prints elements of vector in a line
template <typename T>
void Print(ds::Vector<T> data)
{
    ds::da::Iterator<T>* iter = data.ToIterator();

    while(iter->HasNext())
    {
        std::cout << iter->Next() << " ";
    }
    std::cout << "\n"; 
    delete iter;
}

//GenerateList() - creates a linked list of random decimal numbers
ds::Node<int>* GenerateList(int n)
{
    int s = (n <= 0)?(10):(n);
    ds::Node<int>* root = new ds::Node<int>(0);

    for(int i = 1;i < s;i += 1)
    {
        ds::Node<int>* tmp = new ds::Node<int>(0,root);
        root = tmp;
    }

    ds::sn::Iterator<int>* iter = new ds::sn::Iterator<int>(root);
    
    while(iter->HasNext())
    {
        iter->Next() = (rand() % 100) + 1;
    }
    return root;
} 

/********************************
 * Helper Functions : End
 *******************************/

int main()
{
    return 0; 
}
