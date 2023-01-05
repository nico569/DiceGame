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
		initNumDice();
		targetScore = 1000;
	}
	// destructor:
	~Player()
	{
	}


private:
	std::string name;
	int score;
	int dice[3];
	int numberOfDice;
	int targetScore;

	void resetDice();
	void initNumDice();

public:

	void setName(std::string new_name);
	std::string getName();

	void setTargetScore(int new_targetScore);

	void goPlay(int numDice);

	void LogQueryNumDice();

	void setNumberDiceToRoll(int numDice);

	void rollDice();

	void LogDiceRolled();

	void calcPlayerScore();

	void setScore(int new_score);
	int getScore();

	void LogScore();
};

