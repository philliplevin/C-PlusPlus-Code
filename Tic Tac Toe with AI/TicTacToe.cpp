#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include "TicTacToe.h"

using namespace std;

// Implementation functions for classes.h

// Creates gameboad 
TicTacToe::TicTacToe()
{
   gameboard[0] = '1';
   gameboard[1] = '2';
   gameboard[2] = '3';
   gameboard[3] = '4';
   gameboard[4] = '5';
   gameboard[5] = '6';
   gameboard[6] = '7';
   gameboard[7] = '8';
   gameboard[8] = '9';
}

// Generates the gameboard when called
void TicTacToe::displayBoard()
{   
     cout << endl;
     cout << "     |   |    " << endl;
     cout << "   " << gameboard[0] << " | " << gameboard[1] << " | " << gameboard[2] << "   " << endl;
     cout << " ____|___|____" << endl;
     cout << "   " << gameboard[3] << " | " << gameboard[4]<< " | " << gameboard[5] << "   " << endl;
     cout << " ____|___|____" << endl;    
     cout << "   " << gameboard[6] << " | " << gameboard[7] << " | " << gameboard[8] << "   " << endl;
     cout << "     |   |    " << endl;
     cout << endl;  
}

// Checks to see if the board contains empty spaces. If not, the game is over and there is a tie
bool TicTacToe::boardFull()
{
   int counter = 0;
   for (int i = 0; i < 9; ++i)
   {
      if (gameboard[i] == 'X' || gameboard[i] == 'O')
         ++counter;
   }
   
   if (counter == 9) // meaning all 9 spots on the board are full
      return true;
   
   else
      return false;
}

// Places an X in the position specified by player
bool TicTacToe::playerMove(int x)
{
 
   if (gameboard[x] != 'X' && gameboard[x] != 'O')
   {
      gameboard[x] = 'X';
      return true;
   }
   
   return false;
}

// The AI for the computerMove is based on executing one of three possible types of moves. First, it is determined if any moves can be made that will result in three-in-a-row for the computer and therefore a win. If such a move can be made, this is executed. Alternatively, the second type of move involves checking the gameboard for any cases where the player needs just one more X in a position to win the game. If such a case is found, the computer places its move in that position to block the player from a potentail win. The third and last possible type of move employs a randomly generated move. 
void TicTacToe::computerMove()
{
  while (true)
  {
      // Checks rows for moves that could win the game   
      for (int i = 0; i < 7; ++++++i)
      {
         if (
               gameboard[i] != 'O' &&
               gameboard[i] != 'X' && // AKA it is not taken
               gameboard[i + 1] == 'O' &&
               gameboard[i + 2] == 'O'
            )
                  {
                     gameboard[i] = 'O';
                     return;
                  }
         if (
               gameboard[i + 1] != 'O' &&
               gameboard[i + 1] != 'X' && 
               gameboard[i] == 'O' &&
               gameboard[i + 2] == 'O'
            )
                  {
                     gameboard[i + 1] = 'O';
                     return;
                  }
         if (
               gameboard[i + 2] != 'O' &&
               gameboard[i + 2] != 'X' && 
               gameboard[i] == 'O' &&
               gameboard[i + 1] == 'O'
            )
                  {
                     gameboard[i + 2] = 'O';
                     return;
                  }         
      }
    
      // Checks columns for moves that could win the game  
      for (int i = 0; i < 3; ++i)
      {
         if (
               gameboard[i] != 'O' &&
               gameboard[i] != 'X' && // AKA it is not taken
               gameboard[i + 3] == 'O' &&
               gameboard[i + 6] == 'O'
            )
                  {
                     gameboard[i] = 'O';
                     return;
                  }
         if (
               gameboard[i + 3] != 'O' &&
               gameboard[i + 3] != 'X' && 
               gameboard[i] == 'O' &&
               gameboard[i + 6] == 'O'
            )
                  {
                     gameboard[i + 3] = 'O';
                     return;
                  }
         if (
               gameboard[i + 6] != 'O' &&
               gameboard[i + 6] != 'X' && 
               gameboard[i] == 'O' &&
               gameboard[i + 3] == 'O'
            )
                  {
                     gameboard[i + 6] = 'O';
                     return;
                  }         
      }
      
      // Checks diagonals for moves that could win the game  
      if (
            gameboard[0] != 'O' &&
            gameboard[0] != 'X' && 
            gameboard[4] == 'O' &&
            gameboard[8] == 'O'
         )
            {
               gameboard[0] = 'O';
               return;
            }
         
      if (
            gameboard[4] != 'O' &&
            gameboard[4] != 'X' && 
            gameboard[0] == 'O' &&
            gameboard[8] == 'O'
         )
            {
               gameboard[4] = 'O';
               return;
            }
               
      if (
            gameboard[8] != 'O' &&
            gameboard[8] != 'X' && 
            gameboard[0] == 'O' &&
            gameboard[4] == 'O'
         )
            {
               gameboard[8] = 'O';
               return;
            }
            
      if (
            gameboard[2] != 'O' &&
            gameboard[2] != 'X' && 
            gameboard[4] == 'O' &&
            gameboard[6] == 'O'
         )
            {
               gameboard[2] = 'O';
               return;
            }
         
      if (
            gameboard[4] != 'O' &&
            gameboard[4] != 'X' && 
            gameboard[2] == 'O' &&
            gameboard[6] == 'O'
         )
            {
               gameboard[4] = 'O';
               return;
            }
               
      if (
            gameboard[6] != 'O' &&
            gameboard[6] != 'X' && 
            gameboard[2] == 'O' &&
            gameboard[4] == 'O'
         )
            {
               gameboard[6] = 'O';
               return;
            }
                     
// Checks rows for moves that block the player from winning the game   
      for (int i = 0; i < 7; ++++++i)
      {
         if (
               gameboard[i] != 'O' &&
               gameboard[i] != 'X' && // AKA it is not taken
               gameboard[i + 1] == 'X' &&
               gameboard[i + 2] == 'X'
            )
                  {
                     gameboard[i] = 'O';
                     return;
                  }
         if (
               gameboard[i + 1] != 'O' &&
               gameboard[i + 1] != 'X' && 
               gameboard[i] == 'X' &&
               gameboard[i + 2] == 'X'
            )
                  {
                     gameboard[i + 1] = 'O';
                     return;
                  }
         if (
               gameboard[i + 2] != 'O' &&
               gameboard[i + 2] != 'X' && 
               gameboard[i] == 'X' &&
               gameboard[i + 1] == 'X'
            )
                  {
                     gameboard[i + 2] = 'O';
                     return;
                  }         
      }
    
      // Checks columns for moves that block the player from  winnning the game  
      for (int i = 0; i < 3; ++i)
      {
         if (
               gameboard[i] != 'O' &&
               gameboard[i] != 'X' && // AKA it is not taken
               gameboard[i + 3] == 'X' &&
               gameboard[i + 6] == 'X'
            )
                  {
                     gameboard[i] = 'O';
                     return;
                  }
         if (
               gameboard[i + 3] != 'O' &&
               gameboard[i + 3] != 'X' && 
               gameboard[i] == 'X' &&
               gameboard[i + 6] == 'X'
            )
                  {
                     gameboard[i + 3] = 'O';
                     return;
                  }
         if (
               gameboard[i + 6] != 'O' &&
               gameboard[i + 6] != 'X' && 
               gameboard[i] == 'X' &&
               gameboard[i + 3] == 'X'
            )
                  {
                     gameboard[i + 6] = 'O';
                     return;
                  }         
      }
      
      // Checks diagonals for moves that  block the player from  winning the game  
      if (
            gameboard[0] != 'O' &&
            gameboard[0] != 'X' && 
            gameboard[4] == 'X' &&
            gameboard[8] == 'X'
         )
            {
               gameboard[0] = 'O';
               return;
            }
         
      if (
            gameboard[4] != 'O' &&
            gameboard[4] != 'X' && 
            gameboard[0] == 'X' &&
            gameboard[8] == 'X'
         )
            {
               gameboard[4] = 'O';
               return;
            }
               
      if (
            gameboard[8] != 'O' &&
            gameboard[8] != 'X' && 
            gameboard[0] == 'X' &&
            gameboard[4] == 'X'
         )
            {
               gameboard[8] = 'O';
               return;
            }
            
      if (
            gameboard[2] != 'O' &&
            gameboard[2] != 'X' && 
            gameboard[4] == 'X' &&
            gameboard[6] == 'X'
         )
            {
               gameboard[2] = 'O';
               return;
            }
         
      if (
            gameboard[4] != 'O' &&
            gameboard[4] != 'X' && 
            gameboard[2] == 'X' &&
            gameboard[6] == 'X'
         )
            {
               gameboard[4] = 'O';
               return;
            }
               
      if (
            gameboard[6] != 'O' &&
            gameboard[6] != 'X' && 
            gameboard[2] == 'X' &&
            gameboard[4] == 'X'
         )
            {
               gameboard[6] = 'O';
               return;
            }         
            

      // If none of the moves above apply the a random move is chosen
      int a = (rand() % 9);
   
      if (gameboard[a] != 'X' && gameboard[a] != 'O')
      {
         gameboard[a] = 'O';
         return;
      }
   
   }
}

// Checks to see if the player wins
bool TicTacToe::playerWins()
{
   // Checks each row for 3 Xs in a row
   for (int i = 0; i < 7; ++++++i)
   {
      if (gameboard[i] == 'X' && gameboard[i + 1] == 'X' && gameboard[i + 2] == 'X')
       return true;
   }
 
   // Checks each column for 3Xs in a row  
   for (int i = 0; i < 3; ++i)
   {
      if (gameboard[i] == 'X' && gameboard[i + 3] == 'X' && gameboard[i + 6] == 'X')
       return true;
   }
   
   // Checks diagonally for 3 Xs in a row
   if (gameboard[0] == 'X' && gameboard[4] == 'X' && gameboard[8] == 'X')
       return true;
   
   if (gameboard[2] == 'X' && gameboard[4] == 'X' && gameboard[6] == 'X')
       return true;

   return false;
}

// Checks to see if the computer wins
bool TicTacToe::computerWins()
{
   // Checks each row for 3 Os in a row
   for (int i = 0; i < 7; ++++++i)
   {
      if (gameboard[i] == 'O' && gameboard[i + 1] == 'O' && gameboard[i + 2] == 'O')
       return true;
   }
 
   // Checks each column for 3 Os in a row  
   for (int i = 0; i < 3; ++i)
   {
      if (gameboard[i] == 'O' && gameboard[i + 3] == 'O' && gameboard[i + 6] == 'O')
       return true;
   }
   
   // Checks diagonally for 3 Os in a row
   if (gameboard[0] == 'O' && gameboard[4] == 'O' && gameboard[8] == 'O')
       return true;
   
   if (gameboard[2] == 'O' && gameboard[4] == 'O' && gameboard[6] == 'O')
       return true;

   return false;
}
