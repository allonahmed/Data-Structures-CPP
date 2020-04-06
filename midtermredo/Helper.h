#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.h"
#include "Node.h"
#include "Iterator.h"
#include "List.h"
#include "Stack.h"
#include "Set.h"
#include "Queue.h"
#include "Deque.h"

//Question 1 Helper
ds::da::Vector<int> GenerateRepeatingList()
{
    int n = rand() % 91 + 10;
    ds::da::Vector<int> data;

    for(int i = 0;i < n;i += 1)
    {
        data.Insert((rand() % (n / 2 + 1) + 1));
    }
    return data;
}

//Question 2 Helpers
ds::dn::Node<int>* GenerateUnsortedList()
{
    int n = rand() % 31 + 10;
    ds::dn::Node<int>* r = new ds::dn::Node<int>(rand() % 1000);
    ds::dn::Node<int>* t = r;

    for(int i = 1;i < n;i += 1)
    {
        t->SetNext(new ds::dn::Node<int>(rand() % 1000));
        t->GetNext()->SetPrev(t);
        t = t->GetNext();
    }
    return r;
}

template <typename T>
void PrintList(ds::dn::Node<T>* root)
{
    ds::dn::Node<T>* t = root;
    
    std::cout << "[";

    while(t != NULL)
    {
        std::cout << t->GetData();

        if(t->GetNext() != NULL)
        {
            std::cout << ",";
        }
        t = t->GetNext();
    }
    std::cout << "]\n";
}

//Question 3 Helper
ds::sn::Node<int>* GenerateInfiniteList()
{
    int n = rand() % 10 + 1;
    int l = rand() % n + 1;
    std::cout << "\n" << n << "," << l << "\n";
    ds::sn::Node<int>* r = new ds::sn::Node<int>(rand() % 1000);
    ds::sn::Node<int>* t = r;
    ds::sn::Node<int>* c = r;

    for(int i = 1;i < n;i += 1)
    {
        t->SetLink(new ds::sn::Node<int>(rand() % 1000));

        if(i == l)
        {
            c = t->GetLink();
        }
        t = t->GetLink();
    }
    t->SetLink(c);
    return r;
}

ds::sn::Node<int>* GenerateList(int n)
{
    int s = (n <= 0)?(10):(n);
    ds::sn::Node<int>* root = new ds::sn::Node<int>(0);

    for(int i = 1;i < s;i += 1)
    {
        ds::sn::Node<int>* tmp = new ds::sn::Node<int>(0,root);
        root = tmp;
    }

    ds::sn::Iterator<int>* iter = new ds::sn::Iterator<int>(root);
    
    while(iter->HasNext())
    {
        iter->Next() = (rand() % 100) + 1;
    }
    return root;
} 
//Question 4 Helper
std::string RepeatingValues()
{
    char chs[] = "abcde";
    int n = rand() % 11 + 10;
    int v;
    bool r;
    std::string result = "";

    for(int i = 0;i < n;i += 1)
    {
        v = rand() % 5;
        r = (rand() % 100) % 3 == 0;
        result = result + chs[v];

        if(r)
        {
            result = result + chs[v];
        }
    }
    return result;
}

//Question 5 Helper
ds::da::Vector<int> GenerateLengthyList()
{
    int n = rand() % 101 + 1;
    ds::da::Vector<int> data;

    for(int i = 0;i < n;i += 1)
    {
        data.Insert((rand() % 20 + 1));
    }
    return data;
}

#endif