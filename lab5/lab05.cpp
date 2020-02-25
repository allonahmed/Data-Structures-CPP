#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"

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

void printArr(ds::Array<int>& arr, int size){
 for(int i = 0; i<size; i++){
   std::cout << arr[i] << ", ";
 } 
 std::cout << "\n";
}


void modeArr(ds::Array<int>& arr, int size)    // only if SortedInts
{
  int count = 1;
  int max = 1;
  int mode = arr[0]; 
  for (int i = 0; i<size-1; i++){
    if(arr[i]==arr[i+1])
    {
      count++;
    }
    else
    {
      count = 1;
      continue;
    }
    if(count>max)
    {
      max = count;
      mode = arr[i];
    }
    }
    
    std::cout<< "The mode is " << mode << ". And the count is " << max << std::endl;
}

int differenceElement(ds::Array<int>& arr, int target){
  int count = 0;
  for(int i = 0; i<arr.Length(); i++){
    for(int x = 0; x<arr.Length(); x++){
      if(target==arr[i]-arr[x]){
        count ++;
      }
    }
  }
  return count;
}


template <typename T>
T getCommon(ds::Array<T>& arr1, ds::Array<T>& arr2){
  
  int count = 0;
  for (int x = 0; x<arr1.Length(); x++){
    for (int y = 0; y<arr2.Length(); y++){
      if(arr1[x]==arr2[y]){
        count ++;
      }
    }
  }
  return count; 
}




int main()
{
    srand(time(NULL));
    int size  = 20;
    ds::Array<int> data[1] = {ds::Array<int>(size)};
    ds::Array<int> data2[1] = {ds::Array<int>(size)};
    
    // RandInts(*data,10,99);
    SortedInts(data[0], 0, true);
    SortedInts(data2[0], 0, true);

    
    std::cout << "Sorted array: " << data[0] << std::endl;
    // std::cout << "The mode of this array is " << modeArr(data[0], size) << std::endl;
    modeArr(data[0],size);
    std::cout << "Second sorted array: " << data2[0] << std::endl;
    // std::cout << "The mode of this array is " << modeArr(data2[0], size) << std::endl;
    SortedInts(data[0], 0, false);
    SortedInts(data2[0], 0, false);
    std::cout << "The ammount of common numbers are " << getCommon(data2[0], data2[0]) << std::endl;
    int target = 50;
    std::cout << "The number of pairs that is equal to the target " << target << " is " << differenceElement(data2[0], target) << std::endl;


    return 0; 
}