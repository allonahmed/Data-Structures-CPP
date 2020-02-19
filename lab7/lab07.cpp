#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector.h"

/*********************************************************
 * Function A 
 * Description:  finding range 
 * Runtime: 3n + 3
 *********************************************************/
int A(ds::Vector<int>& data)
{
    if(data.Length() <= 1) // 1
    {
        return 0;
    }
    int mn = (data[0] <= data[1])?(data[0]):(data[1]); //1
    int mx = data[0] + data[1] - mn;
    int n = data.Length();
    int i = 0;

    while(i < n) // n+1
    {
        if(mx < data[i]) //n
        {
            mx = data[i];
        }
        else if(mn > data[i]) // n
        {
            mn = data[i];
        }
        i += 1;
    }
    return (mx - mn);
}

/*********************************************************
 * Function B 
 * Description:returns the day of week
 * Runtime: 1
 *********************************************************/
std::string B(int dy)
{
    int os = 5;
    std::string wkdy[7] = {"Sunday"};
    wkdy[1] = "Monday";
    wkdy[2] = "Tuesday";
    wkdy[3] = "Wednesday";
    wkdy[4] = "Thursday";
    wkdy[5] = "Friday";
    wkdy[6] = "Saturday";

    if(dy <= 0 || dy > 29) //1
    {
        return "Not a valid day";
    }
    return wkdy[(os + dy) % 7];
}

/*********************************************************
 * Function C 
 * Description:  bool function that returns true if it is positive
 * Runtime: n + (n-2)^1/2
 *********************************************************/
bool C(int n)
{
    int p = (n < 0)?(-1 * n):(n);

    for(int i = 2;i * i <= p;i += 1)
    {
        if(p % 1 != 0)
        {
            return false;
        }
    }
    return (p > 1);
}

/*********************************************************
 * Function D 
 * Description:  inserts an integer into an array
 * Runtime: 3n+1
 *********************************************************/
void D(ds::Vector<int>& data,int n)
{
    if(n >= 1) //1
    {
        for(int i = 1;i <= n;i += 1) //n+1
        {
            for(int j = 1;j <= n;j += 1) // n
            {
                data.Insert(i * j); // n-1
            }
        }
    }
}

/*********************************************************
 * Function E 
 * Description:  uh returns some math that looks like a sigma notation formula for i^2; if an integer is creater that 0
 * Runtime:0
 *********************************************************/
int E(int n)
{
    return (n > 0)?(n * (n + 1) * (2 * n + 1)/6):(0);
}

/*********************************************************
 * Function F
 * Description: no idea   
 * Runtime: n+2
 *********************************************************/
std::string F(int n)
{
    if(n <= 0) // 1
    {
        return "0";
    }
    std::string cur = "";
    char dc;
    int di;

    while(n > 0) // n+1
    {
        di = n % 10;
        dc = (char)('0' + di);
        cur = dc + cur;
        n /= 10;
    }
    return cur;
}

int main()
{
    std::cout << F(3320);
    return 0; 
}
