#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

int GetRandomNum();

void rollDice(int dice[3], int numberOfDice);

void updatePlayerDiceRolled(int dice[3], int numberOfDice, std::string PlayerName);

void calcPlayerScore(int &score, int dice[3], int numberOfDice, int target, std::string PlayerName);

void updatePlayerScore(std::string PlayerName, int score);

void updatePlayerScoreBustTarget(std::string PlayerName, int score);

int dice[3] = { 0 };