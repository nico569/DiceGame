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