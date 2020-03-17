#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "Node.h"
#include "Iterator.h"
#include "Point.h"
#include "Vector.h"
#include "Queue.h"


std::string intToString(int n){
    std::ostringstream val;
    val << n;
    return val.str();
}
template <typename T>
void swap(T *a, T *b){
    T tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
template <typename T>
ds::Vector<T> reverseVec(ds::Vector<T> vec){
    for(int i = 0; i<vec.Length()/2; i++){
        swap(&vec[i], &vec[vec.Length()-i-1]);
    }
    return vec;
}
std::string ToTernary(int n)
{
    std::string val;
    ds::Vector<int> vec;
    if(n<=0){
        return "0";
    }
    while(n!=0){
        vec.Insert(n%3);
        n = n/3;
    }
    vec = reverseVec(vec);
    for(int i =0; i<vec.Length(); i++){
        val += intToString(vec[i]); 
    }
    return val;
}

bool RookMove(ds::Vector<char>& bd,Point& s,Point& e)
{
    return false;
}

/********************************
 * Helper Functions : Begin
 *******************************/

//ToBoardIndex() - converts Point object to a one dimension chess board index
int ToBoardIndex(Point& p)
{
    if(p.x >= 0 && p.x < 8 && p.y >= 0 && p.y < 8)
    {
        return p.x * 8 + p.y;
    }
    return 0;
}

//PrintBoard() - prints chess board
void PrintBoard(ds::Vector<char>& bd)
{
    if(bd.Length() == 64)
    {
        for(int i = 0;i < 64;i += 1)
        {
            std::cout << bd[i];

            if((i + 1) % 8 == 0)
            {
                std::cout << "\n";
            } 
            else 
            {
                std::cout << " ";
            }
        }
    }
}

//GenerateBoard() - generate a chess board of spaces
ds::Vector<char> GenerateBoard()
{
    ds::Vector<char> bd(64);
    bd.Assign(64,'o');
    int n = rand() % 12 + 4;

    for(int i = 0;i < n;i += 1)
    {
        bd[rand() % 64] = 'x';
    }
    return bd;
} 

/********************************
 * Helper Functions : End
 *******************************/

int main()
{
    srand(time(NULL));
    std::string test = ToTernary(23);
    std::cout << test << std::endl;
   
    
    return 0; 
}
