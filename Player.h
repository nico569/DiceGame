#pragma once

#include <string>

class Player
{
public:
	// constructor:
	Player()
	{
		// initialise member variables
		setName("not set");
		setScore(0);

	}
	// destructor:
	~Player()
	{
	}


private:
	std::string name;
	int score;

public:

	std::string getName();
	void setName(std::string new_name);

	int getScore();
	void setScore(int new_score);

	void calcPlayerScore(int dice[3], int numberOfDice, int target);
	// roll the dice
};

