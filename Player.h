#pragma once

#include <iostream>
#include <string>
#include "RandomNumberGenerator.h"

class Player : public RandomNumberGenerator
{
public:
	// constructor:
	Player()
	{
		// initialise member variables
		setName("not set");
		setScore(0);
		resetDice();

	}
	// destructor:
	~Player()
	{
	}


private:
	std::string name;
	int score;
	int dice[3];

	void resetDice();

public:

	void setName(std::string new_name);
	std::string getName();

	void setNumberDiceToRoll(int numDice);

	void rollDice(int numberOfDice);

	void LogDiceRolled(int numberOfDice);

	void calcPlayerScore(int numberOfDice, int target);

	void setScore(int new_score);
	int getScore();

	void LogScore();
};

