#include <iostream>
#include<bits/stdc++.h>


class Game{
    private:
        static const int size = 3;
        char arr[size][size]; // 2d array that represents the tic tac toe board
    public:
        Game(){ // constructor
            generateTTT(arr);
            // PrintTTT();
        }
        char player = 'X';
        char computer = 'O';

        // coordinates for the 2d array board
        class BoardPosition
        {
          public:
            int row, column;
        };
        BoardPosition bp;
        // used to initialize and generate a default board
        void generateTTT(char arr[size][size]){
            for(int x = 0; x< 3; x++)
            {
                for(int y = 0; y < 3; y++)
                {
                    arr[x][y] = '_';
                }
            }
        }
        // prints the current state of the board
        void PrintTTT(char arr[size][size]){
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
        // tests to see if a player has won the game
        bool gameOver(char arr[size][size])
        {
          for (int row = 0; row < 3; row++) // test 3iar for row
          {
            if(arr[row][0] == arr[row][1] && arr[row][1] == arr[row][2])
            {

              if ( arr[row][0] == player)
              {
                std::cout << "Player has won!\n";
                return true;
              }
              else if ( arr[row][0] == computer)
              {
                std::cout << "Computer has won!\n";
                return true;
              }

            }
          }

          for (int column = 0; column < 3; column++) // test 3iar for columns
          {
            if(arr[0][column] == arr[1][column] && arr[1][column] == arr[2][column])
            {
              if(arr[0][column] == player)
              {
                std::cout << "Player has won!\n";
                return true;
              }
              else if ( arr[0][column] ==  computer)
              {
                std::cout << "Computer has won!\n";
                return true;
              }

            }
          }
           // tests for three in a row diagonally
          if( (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) ||
          (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) )
          {
            if(arr[1][1] == player)
            {
              std::cout << "Player has won!\n";
              return true;
            }
            else if (arr[1][1] == computer)
            {
              std::cout << "Computer has won!\n";
              return true;
            }

          }
          return false;
        }

        /* this function returns high value or low value depending
         * on if it is the maximizer or minimizer's turn */
        int EvaluateFunc(char arr[size][size])
        {
          //next three loops test to see if their is a three in a row victory

          for (int row = 0; row < 3; row++) // test 3iar for row
          {
            if(arr[row][0] == arr[row][1] && arr[row][1] == arr[row][2])
            {
              //gives +10 to player with 3iar and takes them if bot has 3iar
              if ( arr[row][0] == player)
              {
                return +10;
              }
              else if ( arr[row][0] == computer)
              {
                return -10; // means bot won
              }
            }
          }

          for (int column = 0; column < 3; column++) // test 3iar for columns
          {
            if(arr[0][column] == arr[1][column] && arr[1][column] == arr[2][column])
            {
              if(arr[0][column] == player)
              {
                return +10;
              }
              else if (arr[0][column] == computer)
              {
                return -10;
              }
            }
          }
           // tests for three in a row diagonally
          if( (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) ||
          (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) )
          {
            if(arr[1][1] == player)
            {
              return +10;
            }
            else if(arr[1][1] == computer)
            {
              return -10;
            }
          }
          return 0;
        }

        //minimax algorithm which returns the score of the board and considers
        //all possible moves
        int Minimax( char arr[size][size], int depth, bool max)
        {
          int score  = EvaluateFunc(arr);

          if (score == 10) // player has won
          {
            return score;
          }
          if (score == -10) // bot has won
          {
            return score;
          }

          if (!MovesLeft(arr)) // means there are no winners and their is a tie
          {
            return 0;
          }

          if (max == true)
          {
            int mv = -1;
            /* traverse through the board, checks all available open slots
             * and checks the highest possible scores and returns that value,
             * then resets the position back */
            for (int i = 0; i < 3; i++)
            {
              for (int j = 0; j < 3; j++)
              {
                if(arr[i][j] == '_') // position is empty
                {

                  arr[i][j] = player;
                  // takes max value
                  mv = std::max(mv, Minimax(arr, depth++, !max));

                  arr[i][j] = '_'; // resets the board position
                }
              }
            }
            return mv;
          }
          else
          {
            int mv  = 10000000;

            for (int i = 0; i < 3; i++)
            {
              for ( int j = 0; j < 3; j++)
              {
                if (arr[i][j] == '_')
                {
                  arr[i][j] == computer;
                  mv = std::min( mv, Minimax(arr, depth+1, !max)); // min value
                  arr[i][j] = '_';
                }
              }
            }
            return mv;
          }
        }

        //retursn the best move possible
        BoardPosition BMP (char arr[size][size])
        {
          int bv = -10000;
          BoardPosition bmp;
          bmp.row = -1;
          bmp.column = -1;
          for(int i = 0; i < size; i++)
          {
            for (int j = 0; j < size; j++)
            {
              if (arr[i][j] == '_')
              {
                arr[i][j] == player;
                int mv = Minimax(arr, 0 , false);
                arr[i][j] = '_';

                if(mv > bv) // finds the best possible value and saves the index
                {
                  bv = mv;
                  bmp.row = i;
                  bmp.column = j;
                }
              }
            }
          }
          return bmp;
        }

        // user input to place move;
        void HumanMove(char arr[size][size])
        {
            BoardPosition loc;
            int x, y;
            std::cout << "Enter the coordinates (X,Y), player: ";
            std::cin >> x >> y;
            while( ( y > 3 || x > 3 ) || (IsFull(x, y)) || (y < 1 || x < 1) ){ // need to add more bounds
              std::cout << "!invalid cooridinates!\n";
              std::cout << "Enter the coordinates (X,Y), player: ";
              std::cin >> x >> y;
            }
            loc.row = x - 1; // decrement so it can be placed in proper spot in array
            loc.column = y - 1;
            arr[loc.row][loc.column] = player;
            PrintTTT(arr);
        }

        //uses minimax to choose the points for computer
        void ComputerMove(char arr[size][size])
        {
            BoardPosition bm = BMP(arr);

            arr[bm.row][bm.column] = computer;

            std::cout << "the computer choose coordinates: " << bm.row+1 << " and "
            << bm.column+1 << std::endl;
            PrintTTT(arr);
        }

        /* checks if there are any moves remaining
         * if there is a char names '_', then there is still a spot avail */
        bool IsFull(int x, int y)
        {
            if (arr[x-1][y-1] == '_'){
              return false;
            }
            return true;
        }
        bool MovesLeft(char arr[3][3])
        {
          for (int i = 0; i < 3; i++)
          {
            for (int j = 0; j < 3; j++)
            {
              if (arr[i][j] == '_')
              {
                return true;
              }
            }
          }
          std::cout << "There are no more possible moves!\n";
          return false;
        }

        // plays the game while there are still possible moves and no winners
        void turn(char arr[size][size])
        {
          while(MovesLeft(arr) && !gameOver(arr))
          {
              int i = 1;
              while( i%2 == 1)
              {
                HumanMove(arr);
                i++;
              }
              while ( i % 2 == 0)
              {
                ComputerMove(arr);
                i++;
              }
          }
        }
};
