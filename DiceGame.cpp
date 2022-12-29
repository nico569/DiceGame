
// DiceGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DiceGame.h"



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
    std::cout << "\n";
    std::cout << "Player 2 enter your name: \n";
    std::cin >> namePlayer2;
    std::cout << "\n";

    // Main Game loop
    for(int i=0; i< roundsOfPlay; i++)
    { 
        std::cout << namePlayer1 <<" press 1,2 or 3 to roll the number of dice you want: \n";
        std::cin >> numDice;

        rollDice(dice, numDice);
        updatePlayerDiceRolled(dice, numDice, namePlayer1);
        calcPlayerScore(player1Score, dice, numDice);
        updatePlayerScore(namePlayer1, player1Score);

        std::cout << namePlayer2 << " press 1,2 or 3 to roll the number of dice you want: \n";
        std::cin >> numDice;

        rollDice(dice, numDice);
        updatePlayerDiceRolled(dice, numDice, namePlayer2);
        calcPlayerScore(player2Score, dice, numDice);
        updatePlayerScore(namePlayer2, player2Score);


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

int GetRandomNum() // Generate a random number between 1 and 6
{
    // use namespace chrono
    using namespace std::chrono;
    // and include literals to be able to use 0.5s for seconds
    using namespace std::literals::chrono_literals;
    // get the current time in nanoseconds
    nanoseconds ns = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    // store the count in an int to be used as the seed for the random num gen
    int seed = ns.count();
    std::this_thread::sleep_for(1ms); // sleep the thread in order to get a new seed every time

    std::srand(seed); // use the seed in ms to get better random numbers

    int randomNumber = (std::rand() % 6 + 1); // clamp the number to only allow values between 1 and 6
    return randomNumber;
    // return std::rand(); // INFO: this also works and does not require a temporary int.
}

void rollDice(int dice[3], int numberOfDice)
{
    for (int i = 0; i < numberOfDice; i++)
    {
        dice[i] = GetRandomNum();
    }
}

void updatePlayerDiceRolled(int dice[3], int numberOfDice, std::string PlayerName)
{
    std::cout << PlayerName << " you've rolled: ";
    
    for (int i = 0; i < numberOfDice; i++)
    {
        std::cout << dice[i];
        if (i < (numberOfDice - 1) )
        {
            std::cout << ", ";
        }
        else
        {
            std::cout << "." << "\n";
        }
    }
    
    std::cout << "\n";
}

void calcPlayerScore(int& score, int dice[3], int numberOfDice)
{
    for (int i = 0; i < numberOfDice; i++)
    {
        score += dice[i];
    }

}

void updatePlayerScore(std::string PlayerName, int score)
{
    std::cout << PlayerName << " your current score is: " << score << "\n";
    std::cout << "\n";
}
