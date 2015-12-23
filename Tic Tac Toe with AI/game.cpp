#include <iostream>
#include <cassert>
#include <string>
#include <ctime>
#include <cstdlib>
#include "TicTacToe.h"

using namespace std;

// Main function

int main()
{
   int p;
   TicTacToe game;
   bool rungame = true;
  
   srand(time(0));
   
   if (rand() % 2 == 0)
      game.computerMove();

   while (rungame == true)
   {
      game.displayBoard();
      
      cout << "Enter a number to place a X there, or enter 0 to quit." << endl;
      cin >> p;
      cout << endl;

      if (p == 0) // ends game
         {
            rungame = false;
            break;
         }
         
      if (p < 1 || p > 9)
      {
         while(p < 1 || p > 9)
         {
            cout << "Number must be between 1 and  9 inclusive." << endl;
            cin >> p;
         }  
      } 
      
      while (game.playerMove(p-1) == false)
      {
         cout << "Position " << p << " is already taken. Pick another!" << endl;
         cin >> p; 
      }
      
      if (game.playerWins())
      {
         game.displayBoard();
         cout << "You won!" << endl;
         break;  
      }
     
      if (game.boardFull())
      {
         game.displayBoard();
         cout << "There is a tie! GAME OVER!" << endl;
         rungame = false;
      }
       
      game.computerMove();
             
      if (game.computerWins())
      {
         game.displayBoard();
         cout << "You lost!" << endl;
         break;
      } 
      
     if (game.boardFull())
     {
         game.displayBoard();
         cout << "There is a tie! GAME OVER!" << endl;
         rungame = false;
     }
  }   
}


