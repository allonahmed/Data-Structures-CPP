#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"

void RandInts(ds::Array<int>& arr,int lo,int hi)
{
    int mx = (hi >= lo)?(hi):(lo);// if hi is greater or equal to low, max equals hi otherwise max equals low 
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
void targetArray(ds::Array<T>& arr, T target){
  int size = arr.Length();
  for (int i = 0; i<arr.Length(); i++){
    arr[i] = arr[target];
  }
}

int arrayMax(ds::Array<int>& arr){
  int max = 0;
  for(int i= 0; i<arr.Length(); i++){
    if(arr[i]>max){
      max = arr[i];
    }
  }
  return max;
}

template <typename S>
bool sumTarget(ds::Array<S>& arr, S target){
  for(int j = 0; j<arr.Length(); j++){
    for(int i = 0; i<arr.Length(); i++)
    {
        if(target == arr[i]+arr[j] && i!=j)
        {
            std::cout << j << " and " << i << " the indices of the elements, whose sum is " << target << std::endl;
            return true;
        }

    }
}

  return false;
} //1


int removeVal(ds::Array<int>& arr, int val)
{
  int count = 0;
  int size = arr.Length();
  for(int i = 0; i<arr.Length(); i++)
  {
      if(arr[i]==val)
      {
          for(int j=i; j<(arr.Length()-1); j++)
          {
            arr[j]=arr[j+1];
          }
          count++;
          break;
      }
  }
  size = arr.Length()-count;
  
  return size;
} // 2

int IndexFind(ds::Array<int>& arr, int target)
{
  int ndex=0;
  for(int i = 0; i<arr.Length(); i++)
  {
      if(arr[i]==target)
      {
          
      }
      else
      {
          if(arr[i]<target && arr[i+1]>target)
          {
            ndex = i+1;
          }
      }
  }
  
  return ndex;
} // 3


int main()
{
    ds::Array<int> a(10), b(20);

    srand(time(NULL));

    RandInts(a,1,50);
    SortedInts(b,8,false);
    std::cout << "Sorted Array: \n" << b << "\n\n";
   

    std::cout << (sumTarget(b, 60) ? "true" : "false") << std::endl << "\n";
    std::cout << "newstring length : " << removeVal(b, 23) << "\n\n";
    std::cout << "Index: " << IndexFind(b, 25) << std::endl;

    return 0; 
}
