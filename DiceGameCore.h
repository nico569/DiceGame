#pragma once

#include "RandomNumberGenerator.h"

class DiceGameCore : public RandomNumberGenerator
{
public:
	// constructor:
	DiceGameCore()
	{
		// initialise member variables
		numberOfPlayers = 1;
		roundsOfPlay = 1;
		target = 0;

	}
	// destructor:
	~DiceGameCore()
	{
	}
private:
	int numberOfPlayers;
	int roundsOfPlay;
	int target;


public:
	void setNumberOfPLayers(int new_numPlayers);
	int getNumberOfPlayers();

	void setRoundsOfPlay(int new_roundOfPlay);
	int getRoundsOfPlay();

	void calcTarget();
	int getTarget();
};

