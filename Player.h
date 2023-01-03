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

	std::string getName();
	void setName(std::string new_name);

	int getScore();
	void setScore(int new_score);

	void calcPlayerScore(int numberOfDice, int target);
	  
	void rollDice(int numberOfDice);

	void LogDiceRolled(int numberOfDice);

	void LogScore();
};

