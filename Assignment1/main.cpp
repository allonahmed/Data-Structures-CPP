#include <iostream>

void fillArr(int arr[][10], int size)
{
    for(int i = 0; i < size; i+=1)
    {
        for(int j = 0; j < size; j+=1)
        {
            arr[i][j] = 0;
        }
    }
}




int main()
{
    const int size = 10;

    int twod[size][size];

    for(int i = 0; i < size; i+=1)
    {
        for(int j = 0; j < size; j+=1)
        {
            twod[i][j] = 0;
        }
    }

    for(int i = 0; i < size; i+=1)
    {
        for(int j = 0; j < size; j+=1)
        {
            std::cout << "[" << twod[i][j] << "]";
        }
        std:: cout << "\n";
    }



}