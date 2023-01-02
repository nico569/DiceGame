#include "Player.h"

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

void Player::calcPlayerScore(int dice[3], int numberOfDice, int target)
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