
// DiceGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

int GetRandomNum();

int main()
{
   
    std::string namePlayer1;
    std::string namePlayer2;

    int roundsOfPlay = 5; // fixed number of rounds to play
    int target = 20;

    int player1Score = 0;
    int player2Score = 0;

    std::string in;


    // Game Start:
    //std::cout << "Player 1 enter your name: \n";
    //std::cin >> namePlayer1;
    //std::cout << "Player 2 enter your name: \n";
    //std::cin >> namePlayer2;

    for(int i=0; i< roundsOfPlay; i++)
    { 
        std::cout << "Player 1 press r to roll: \n";
        std::cin >> in;
        if (in == "r")
        {
            player1Score += GetRandomNum(); // is the same as: player1Score = player1Score + GetRandomNum();
        }

        std::cout << "Player 2 press r to roll: \n";
        std::cin >> in;
        if (in == "r")
        {
            player2Score += GetRandomNum();
        }

        // print result after each round
        std::cout << "Player 1 Score: " << player1Score << "\n";
        std::cout << "Player 2 Score: " << player2Score << "\n";
    }
    int b = 7;

}

int GetRandomNum()
{
    srand(time(0)); // set time for random number generator
    return (rand() % 6 + 1);
}

