#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"

template <class T>
void ReverseTraverse(ds::dn::Node<T>* root)
{   
    ds::dn::Node<T>* tmp = root;
    while(tmp->GetNext()!=NULL)
    {
        tmp = tmp->GetNext();
    }
   while(tmp!=root->GetPrev())
   {
       std::cout<< tmp->GetData() << " ";
       tmp = tmp->GetPrev();
   }
}
template <typename T>
void insert(ds::dn::Node<T>* root, ds::dn::Node<T>* node)
{
    ds::dn::Node<T>* tmp;
    if(root == NULL)
    {
        root = node;
    }
    else if(root->GetData()>=node->GetData())
    {
        node->SetNext(root);
        node->SetPrev(NULL);
        root = node;
    }
    else{
        tmp = root;
        while(tmp->GetNext() != NULL && tmp->GetNext()->GetData()< node->GetData())
        {
            tmp = tmp->GetNext();
        }
        node->SetNext(tmp->GetNext());

        if(tmp->GetNext() != NULL){
            node->SetNext(tmp->GetNext());
        }
        tmp->SetNext(node);
        node->SetPrev(tmp);
    }

}

template <class T>
void InsertionSort(ds::dn::Node<T>* root) // still in progress of figuring solution out
{   
    ds::dn::Node<T>* sorted = NULL, *tmp = root;
    while(tmp != NULL)
    {
        ds::dn::Node<T>* next = tmp->GetNext();
        tmp->SetPrev(NULL);
        tmp->SetNext(NULL);

        insert(sorted, tmp);
        tmp = next;
    }

    root = sorted;
}


/********************************
 * Helper Functions : Begin
 *******************************/

//GenerateList() - converts Point object to a one dimension chess board index
ds::dn::Node<int>* GenerateList(int n)
{
    int nc = (n <= 0)?(10):(n);
    ds::dn::Node<int>* root = new ds::dn::Node<int>(rand() % 99 + 1);
    ds::dn::Node<int>* tmp = root;
    for(int i = 1;i < nc;i += 1)
    {
        tmp->SetNext(new ds::dn::Node<int>(rand() % 99 + 1));
        tmp->GetNext()->SetPrev(tmp);
        tmp = tmp->GetNext();
    }

    return root;
}

template <class T>
void Print(ds::dn::Node<T>* root)
{
    for(ds::dn::Node<T>* t = root;t != NULL;t = t->GetNext())
    {
        std::cout << t->GetData() << " ";
    }
}

/********************************
 * Helper Functions : End
 *******************************/

int main()
{
    srand(time(NULL));
    ds::dn::Node<int>* root = GenerateList(15);
    Print(root);
    std::cout << "\n";
    // ds::dn::Clear(root);
    // std::cout << "after clear: ";
    // Print(root);
    //  std::cout << "\n";
    ReverseTraverse(root);
    std::cout << "\n";
    InsertionSort(root);
    Print(root);
    std::cout << "\n";

        
    return 0; 
}
