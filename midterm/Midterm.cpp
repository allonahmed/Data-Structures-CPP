#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"
#include "Node.h"
#include "Iterator.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "Set.h"
#include "Deque.h"
#include "Helper.h" //Helper Functions for Testing Your Functions
#include <bits/stdc++.h> 

template <typename T>
int LastOccurrence(ds::da::Vector<T>& data,const T& value)
{
    //Rewrite Definition of LastOccurrence() Here
    int x = -1;
    for(int i = data.Size(); i > 0; i--){
        if(data[i-1]==value)
        {
         x = i-1;   
         break;
        }  
    }
    return x;
}

template<typename T>
void swap(ds::dn::Node<T>* node1, ds::dn::Node<T>* node2){
    ds::dn::Node<T>* tmp;
    tmp = node1->GetPrev();
    if(tmp){
        tmp->SetNext(node2);
    }

    node1->SetPrev(node2);
    node1->SetNext(node2->GetNext()); 
    node2->SetNext(node1);

}

template <typename T>
void BubbleSort(ds::dn::Node<T>* root)
{
    //Rewrite Definition of BubbleSort() Here
    ds::dn::Node<T>* node1, *node2;
    for(node1 = root; node1->GetNext() != NULL; node1 = node1->GetNext()){
        for( node2 = node1->GetNext(); node2 != NULL; node2 = node2->GetNext()){
            if(node2->GetData()>node1->GetData()){
                swap(node1, node2);
            }
        }
    }
    return;
}

template <typename T>
bool HasCycle(ds::sn::Node<T>* root)
{
    //Rewrite Definition of HasCycle() Here 
    ds::sn::Node<T>* node1 = root, *node2 = root;
    if(root==NULL){
        return false;
    }
    while(node1 && node2 && node2->GetLink()){
        node1 = node1->GetLink();
        node2 = node2->GetLink()->GetLink();
        if(node1 == node2){
            return true;
        }
    }

    return false;
}

std::string AdjacentDuplicatesRemoval(std::string str)
{
  ds::da::Stack<char> word;
        word.Push(str[0]);
        for(int i=1;i<str.size();i++)
        {
            if(!word.IsEmpty()&&word.Top()==str[i])
            {
                word.Pop();
            }
            else
            {
                word.Push(str[i]);
            }
        }

        std::string str2= "";
        while(!word.IsEmpty())
        {
            str2 += word.Top();
            word.Pop();
        }
        reverse(str2.begin(),str2.end());
        str = str2;
        return str;
}

int MaxKSum(ds::da::Vector<int>& data,int k)
{
    //Rewrite Definition of MaxKSum() Here
    int sum = 0;
    if(k<1 && k>data.Size()){
        for(int i = 0; i<data.Size(); i++){
            sum += data[i];
        }
        return sum;
    }
    else {
        int nsum = 0;
        for(int i = 0; i<k; i++){
            nsum += data[i]; 
        }
        int fsum = nsum;
        for(int i = k; i<data.Size(); i++){
            fsum += data[i] - data[i-k]; 
            nsum = (nsum>fsum)?(nsum):(fsum);
        }
        return nsum;
    }
}

int main()
{
    srand(time(NULL));
    //Test Your Functions Here
    std::cout << "\nquestion number one: " << std::endl;
    ds::da::Vector<int> data  = GenerateRepeatingList();
    std::cout << data << std::endl;
    std::cout << "last occurence: " << LastOccurrence(data, 2);



    //--------------questione 2-------------------------//

    // std::cout << "\n\nquestion number two: " << std::endl;
    // ds::dn::Node<int>* test = GenerateUnsortedList();
    // std::cout << "unsorted list: ";
    // PrintList(test);
    // BubbleSort(test);
    // std::cout << "sorted list: ";
    // PrintList(test);
    // // unfinished
     //--------------questione 3-------------------------//


    std::cout << "\n\nquestion number three: " << std::endl;
    ds::sn::Node<int>* infin = GenerateInfiniteList();  // infinite loop for testing
    std::cout << std::boolalpha;
    bool result = HasCycle(infin);
    std::cout << "the linked list" << ((result)?(" is "):(" is not ")) << "a cycle\n";

    ds::sn::Node<int>* nonin = GenerateList(10); //non infinite loop for testing
    bool result2 = HasCycle(nonin); 
    std::cout << "the linked list" << ((result2)?(" is "):(" is not ")) << "a cycle\n";

     //--------------questione 4-------------------------//

     std::cout << "\n\nquestion number four: " << std::endl;
    std::string rep = RepeatingValues();
    std::cout << rep << std::endl;
    std::cout << "no repeats: " << AdjacentDuplicatesRemoval(rep) << std::endl;


    //--------------questione 4-------------------------//
    std::cout << "\n\nquestion number five: " << std::endl;
    ds::da::Vector<int> newt = GenerateLengthyList();
    std::cout << newt << std::endl;
    std::cout << "max sum is : " << MaxKSum << std::endl;


    
    
    

    return 0;
}
