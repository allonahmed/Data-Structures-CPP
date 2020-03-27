#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"

/**********************************
 * Question 1: Swap Counts
 * a. 4
 * b. 6
 * c. 7
 sorry for lateness, was struggling with, out of bound errors!
 **********************************/

void RandInts(ds::Array<int>& arr,int lo,int hi)
{
    int mx = (hi >= lo)?(hi):(lo);
    int mn = (lo <= hi)?(lo):(hi);
    ds::it::Iterator<int>* iter = arr.ToIterator();

    while(iter->HasNext())
    {
        iter->Next() = rand() % (mx - mn + 1) + mn;
    }
    delete iter;
} 

void SortedInts(ds::Array<int>& arr,int start,bool dup)
{
    int prev = start;
    int c = (dup)?(0):(1);
    ds::it::Iterator<int>* iter = arr.ToIterator();

    while(iter->HasNext())
    {
        prev = prev + rand() % 10 + c;
        iter->Next() = prev; 
    }

    delete iter;
}

template <typename T>
bool Monotonic(const ds::Array<T>& data)
{
  int size = data.Length();
  int i = 0;
  int fcount = 0;
  int bcount = 0;
  while(i<size-1 && data[i]<=data[i+1] ){
    i++;
    fcount++;
  } 
  i = 0;
  while(i<size-1 && data[i]>=data[i+1]  ){
    i++;
    bcount++;
  }
  if(bcount == (size-1) || fcount == (size-1)){
    return true;
  }
  else 
  {
    return false;
  }
}





int main()
{
    srand(time(NULL));
    ds::Array<int> arr1[1] = {ds::Array<int>(15)};
    std::cout << std::boolalpha;

    ds::Array<int> arr2[] = {9,7,5,3,1};
    
    RandInts(*arr1, 99, 10);

    std::cout << arr1[0];

    std::cout << std::endl << Monotonic(arr1[0]);

    SortedInts(arr1[0], 0, true);

    std::cout << "\nSorted Array: " << arr1[0];


   
    std::cout << std::endl << Monotonic(arr1[0]) << std::endl;

    return 0; 
}
