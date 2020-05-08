#include <iostream>


class Game{
    private:
        static const int size = 3;
        char arr[size][size];
    public:
        Game(){
            generateTTT();
            PrintTTT();
        }



        void PrintTTT(){
            int value  = 1;
            std::cout << "     1      2      3\n";
            std::cout << "   -------------------\n " << value;
            for(int i = 0; i < 3; i+=1)
            {
                for(int j = 0; j < 3; j+=1)
                {
                    std::cout << " | " << arr[i][j] << " | ";
                
                    if(j == 2 && value!=3)
                    {
                        std::cout << "\n   -------------------\n " << ++value;
                    }
                    if(j == 2 && i==2)
                    {
                        std::cout << "\n   -------------------\n";
                    }
                }
            }  
        }

        void generateTTT(){
            for(int x = 0; x< 3; x++)
            {
                for(int y = 0; y < 3; y++)
                {
                    arr[x][y] = ' ';
                }
            }
        }
};