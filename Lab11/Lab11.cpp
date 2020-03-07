#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"
// #include "Point.h"
#include "Vector.h"

// bool IsLine(ds::Vector<Point>& coors)
// {

//     return false;
// }



template<typename T>
ds::Node<T>* MiddleNode(ds::Node<T>* head)
{
  
    ds::Node<T>* tmp1 = head;
    ds::Node<T>* tmp2 = head;
    if(tmp1->GetLink()==NULL){
      // std::cout << "NULL"; 
      return NULL;
    }
    while (tmp2 != NULL && tmp2->GetLink() != NULL)  
        {   
            tmp1 = tmp1->GetLink(); 
            tmp2 = tmp2->GetLink()->GetLink();  
            std::cout << "   ";
        } 
   
    return tmp1;
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
   ds::Node<int>* link = GenerateList(13);
   Print(link);
   std::cout << std::endl;
   Print(MiddleNode(link));
}
