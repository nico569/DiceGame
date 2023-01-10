
// DiceGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DiceGame.h"
#include "DiceGameCore.h"
#include "Player.h"


int main()
{
    DiceGameCore diceGameCore;

    std::vector<Player> players;

    // Game Start:

    // Greeting:
    std::cout << "Hi and welcome to this awesome game!\n";
    std::cout << "\n";

    std::cout << "How many players are playing?\n";
    diceGameCore.setNumberOfPLayers(readInt(std::cin));

    std::cout << "How many rounds do you want to play?\n";
    diceGameCore.setRoundsOfPlay(readInt(std::cin));   

    diceGameCore.calcTarget();

    // tell the players the target score
    std::cout << "The target you are trying to get closest to is: " << diceGameCore.getTarget() << "\n";
    std::cout << "\n";

    // Enter names
    for (int i = 0; i < diceGameCore.getNumberOfPlayers(); i++)
    {
        players.emplace_back();
        players[i].setTargetScore(diceGameCore.getTarget());
        std::cout << "Player " << (i+1) << " enter your name: \n";
        players[i].setName(readString(std::cin));
        std::cout << "\n";
    }

    // Main Game loop
    for(int i=0; i< diceGameCore.getRoundsOfPlay(); i++)
    { 
        for (int i = 0; i < diceGameCore.getNumberOfPlayers(); i++)
        {
            players[i].LogQueryNumDice();
            players[i].goPlay(readInt(std::cin));
        }

    }

    // finish the game and calc and print the winner:

    // TODO: remove the hard coded indices and move this function into the diceGameCore evaluating for n Players:
    if (diceGameCore.getTarget() - players[0].getScore() == diceGameCore.getTarget() - players[1].getScore())
    {
        std::cout << "Its a Draw! \n";
    }
    else if (diceGameCore.getTarget() - players[0].getScore() < diceGameCore.getTarget() - players[1].getScore())
    {
        std::cout << "The Winner is: " << players[0].getName() << "\n";
    }
    else
    {
        std::cout << "The Winner is: " << players[1].getName() << "\n";
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