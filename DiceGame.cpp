
// DiceGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DiceGame.h"
#include "DiceGameCore.h"
#include "Player.h"

int main()
{
    DiceGameCore diceGameCore;
   
    Player player1;
    Player player2;

    // Game Start:

    // Greeting:
    std::cout << "Hi and welcome to this awesome game!\n";
    std::cout << "\n";

    std::cout << "How many players are playing?\n";
    diceGameCore.setNumberOfPLayers(readInt(std::cin));

    std::cout << "How many rounds do you want to play?\n";
    diceGameCore.setRoundsOfPlay(readInt(std::cin));

    diceGameCore.calcTarget();

    // update each player with the targeet score:
    player1.setTargetScore(diceGameCore.getTarget());
    player2.setTargetScore(diceGameCore.getTarget());

    // tell the players the target score
    std::cout << "The target you are trying to get closest to is: " << diceGameCore.getTarget() << "\n";
    std::cout << "\n";

    // Enter names
    std::cout << "Player 1 enter your name: \n";
    player1.setName(readString(std::cin));
    std::cout << "\n";

    std::cout << "Player 2 enter your name: \n";
    player2.setName(readString(std::cin));
    std::cout << "\n";

    // Main Game loop
    for(int i=0; i< diceGameCore.getRoundsOfPlay(); i++)
    { 
        player1.LogQueryNumDice();
        player1.goPlay(readInt(std::cin));

        player2.LogQueryNumDice();
        player2.goPlay(readInt(std::cin));

    }

    // finish the game and calc and print the winner:

    if (diceGameCore.getTarget() - player1.getScore() == diceGameCore.getTarget() - player2.getScore())
    {
        std::cout << "Its a Draw! \n";
    }
    else if (diceGameCore.getTarget() - player1.getScore() < diceGameCore.getTarget() - player2.getScore())
    {
        std::cout << "The Winner is: " << player1.getName() << "\n";
    }
    else
    {
        std::cout << "The Winner is: " << player2.getName() << "\n";
    }
    

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