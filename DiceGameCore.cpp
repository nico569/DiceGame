#include "DiceGameCore.h"

void DiceGameCore::setNumberOfPLayers(int new_numPlayers)
{
	numberOfPlayers = new_numPlayers;
}

int DiceGameCore::getNumberOfPlayers()
{
	return numberOfPlayers;
}

void DiceGameCore::setRoundsOfPlay(int new_roundOfPlay)
{
	roundsOfPlay = new_roundOfPlay;
}

int DiceGameCore::getRoundsOfPlay()
{
	return roundsOfPlay;
}

void DiceGameCore::calcTarget()
{
	target = getRoundsOfPlay() * 3 * GetRandomNum();
}

int DiceGameCore::getTarget()
{
	return target;
}