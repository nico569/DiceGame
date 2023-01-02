
// DiceGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DiceGame.h"
#include "Player.h"



int main()
{
   
    Player player1;
    Player player2;

    int roundsOfPlay = 1; // fixed number of rounds to play
    int target = 30;

    int numDice = 1;
    
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
    player1.setName(readString(std::cin));
    std::cout << "\n";
    std::cout << "Player 2 enter your name: \n";
    player2.setName(readString(std::cin));
    std::cout << "\n";

    // Main Game loop
    for(int i=0; i< roundsOfPlay; i++)
    { 
        std::cout << player1.getName() <<" press 1,2 or 3 to roll the number of dice you want: \n";
        std::cin >> numDice;
        rollDice(dice, numDice);
        updatePlayerDiceRolled(dice, numDice, player1.getName());
        player1.calcPlayerScore(dice, numDice, target);
        updatePlayerScore(player1.getName(), player1.getScore());

        std::cout << player2.getName() << " press 1,2 or 3 to roll the number of dice you want: \n";
        std::cin >> numDice;
        rollDice(dice, numDice);
        updatePlayerDiceRolled(dice, numDice, player2.getName());
        player2.calcPlayerScore(dice, numDice, target);
        updatePlayerScore(player2.getName(), player2.getScore());


    }

    // finish the game and calc and print the winner:

    if (target - player1.getScore() == target - player2.getScore())
    {
        std::cout << "Its a Draw! \n";
    }
    else if (target - player1.getScore() < target - player2.getScore())
    {
        std::cout << "The Winner is: " << player1.getName() << "\n";
    }
    else
    {
        std::cout << "The Winner is: " << player2.getName() << "\n";
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

void updatePlayerScore(std::string PlayerName, int score)
{
    std::cout << PlayerName << " your current score is: " << score << "\n";
    std::cout << "\n";
}


int readInt(std::istream& stream)
{
    int i;
    stream >> i; // Cross your fingers this doesn't fail
    return i;
}

std::string readString(std::istream& stream)
{
    std::string i;
    stream >> i; // Cross your fingers this doesn't fail
    return i;
}