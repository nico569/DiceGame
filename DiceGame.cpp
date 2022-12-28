
// DiceGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

int GetRandomNum();


int main()
{
   
    std::string namePlayer1;
    std::string namePlayer2;

    int roundsOfPlay = 1; // fixed number of rounds to play
    int target = 30;

    int player1Score = 0;
    int player2Score = 0;

    int numDice = 1;
    int dice1, dice2, dice3;

    // Game Start:

    // Greeting:
    std::cout << "Hi and welcome to this awesome game!\n";
    std::cout << "\n";
    std::cout << "How many rounds do you want to play?\n";
    std::cin >> roundsOfPlay;

    // work out the target based on the number of rounds 
    target = roundsOfPlay * 3 * GetRandomNum();
    std::cout << "The target you are trying to get closest to is: " << target << "\n";
    std::cout << "\n";

    // Enter names
    std::cout << "Player 1 enter your name: \n";
    std::cin >> namePlayer1;
    std::cout << "Player 2 enter your name: \n";
    std::cin >> namePlayer2;

    // Main Game loop
    for(int i=0; i< roundsOfPlay; i++)
    { 
        std::cout << namePlayer1 <<" press 1,2 or 3 to roll the number of dice you want: \n";
        std::cin >> numDice;
        if (numDice == 1)
        {
            dice1 = GetRandomNum();
            std::cout << namePlayer1 << " rolled: " << dice1 << "\n";
            player1Score += dice1;
        }
        if (numDice == 2)
        {
            dice1 = GetRandomNum();
            dice2 = GetRandomNum();
            std::cout << namePlayer1 << " rolled: " << dice1 << ", " << dice2 << "\n";
            player1Score += dice1 + dice2;
        }
        if (numDice == 3)
        {
            dice1 = GetRandomNum();
            dice2 = GetRandomNum();
            dice3 = GetRandomNum();
            std::cout << namePlayer1 << " rolled: " << dice1 << ", " << dice2 << ", " << dice3 << "\n";
            player1Score += dice1 + dice2 + dice3;
        }

        std::cout << namePlayer2 << " press 1,2 or 3 to roll the number of dice you want: \n";
        std::cin >> numDice;
        if (numDice == 1)
        {
            dice1 = GetRandomNum();
            std::cout << namePlayer2 << " rolled: " << dice1 << "\n";
            player2Score += dice1;
        }
        if (numDice == 2)
        {
            dice1 = GetRandomNum();
            dice2 = GetRandomNum();
            std::cout << namePlayer2 << " rolled: " << dice1 << ", " << dice2 << "\n";
            player2Score += dice1 + dice2;
        }
        if (numDice == 3)
        {
            dice1 = GetRandomNum();
            dice2 = GetRandomNum();
            dice3 = GetRandomNum();
            std::cout << namePlayer2 << " rolled: " << dice1 << ", " << dice2 << ", " << dice3 << "\n";
            player2Score += dice1 + dice2 + dice3;
        }

        // print result after each round
        std::cout << "Player 1 Score: " << player1Score << "\n";
        std::cout << "Player 2 Score: " << player2Score << "\n";
    }

    // finish the game and print the winner:

    if (target - player1Score == target - player2Score)
    {
        std::cout << "Its a Draw! \n";
    }
    else if (target - player1Score < target - player2Score)
    {
        std::cout << "The Winner is: " << namePlayer1 << "\n";
    }
    else
    {
        std::cout << "The Winner is: " << namePlayer2 << "\n";
    }
    

}

int GetRandomNum()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    srand(time(0)); // set time for random number generator
    //std::this_thread::sleep_for(std::chrono::seconds(2));
    return (rand() % 6 + 1);
}

