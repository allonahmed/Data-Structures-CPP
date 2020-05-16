#include <iostream>
#include "TTT.h"
#include<bits/stdc++.h>

int main()
{

    Game g;
    char arr[3][3];
    g.bp.row;
    std::cout << "HELLO WELCOME TO THE UNBEATABLE TIC TAC TOE GAME: \n";
    g.generateTTT(arr);
    g.PrintTTT(arr);
    g.turn(arr);

    return (0);
}
