#include "Player.h"

void Player::resetDice()
{
    for (int i = 0; i < 3; i++)
    {
        dice[i] = 0;
    }
}

std::string Player::getName()
{
	return name;
}

void Player::setName(std::string new_name)
{
	name = new_name;
}

int Player::getScore()
{
	return score;
}

void Player::setScore(int new_score)
{
	score = new_score;
}

void Player::calcPlayerScore(int numberOfDice, int target)
{
    for (int i = 0; i < numberOfDice; i++)
    {
        score += dice[i];
        // check if bust:
        if (score >= target)
        {
            score = (score - target);
           
        }
    }
}

void Player::rollDice(int numberOfDice)
{
    resetDice();

    for (int i = 0; i < numberOfDice; i++)
    {
        dice[i] = GetRandomNum();
    }
}

void Player::LogDiceRolled(int numberOfDice)
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

void Player::LogScore()
{
    std::cout << getName() << " your current score is: " << getScore() << "\n";
    std::cout << "\n";
}