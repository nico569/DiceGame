#include "Player.h"

void Player::resetDice()
{
    for (int i = 0; i < 3; i++)
    {
        dice[i] = 0;
    }
}

void Player::initNumDice()
{
    numberOfDice = 1;
}

void Player::setName(std::string new_name)
{
	name = new_name;
}

std::string Player::getName()
{
	return name;
}

void Player::setTargetScore(int new_targetScore)
{
    targetScore = new_targetScore;
}

void Player::goPlay(int numDice)
{
    
    setNumberDiceToRoll(numDice);
    rollDice();
    LogDiceRolled();
    calcPlayerScore();
    LogScore();
}

void Player::LogQueryNumDice()
{
    std::cout << getName() << " press 1,2 or 3 to roll the number of dice you want: \n";
}

void Player::setNumberDiceToRoll(int numDice)
{
    numberOfDice = numDice;
}

void Player::rollDice()
{
    resetDice();

    for (int i = 0; i < numberOfDice; i++)
    {
        dice[i] = GetRandomNum();
    }
}

void Player::LogDiceRolled()
{
    std::cout << getName() << " you've rolled: ";

    for (int i = 0; i < numberOfDice; i++)
    {
        std::cout << dice[i];
        if (i < (numberOfDice - 1))
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

void Player::calcPlayerScore()
{
    for (int i = 0; i < numberOfDice; i++)
    {
        score += dice[i];
        // check if bust:
        if (score >= targetScore)
        {
            score = (score - targetScore);

        }
    }
}

void Player::setScore(int new_score)
{
	score = new_score;
}

int Player::getScore()
{
	return score;
}

void Player::LogScore()
{
    std::cout << getName() << " your current score is: " << getScore() << "\n";
    std::cout << "\n";
}