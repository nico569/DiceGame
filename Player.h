#pragma once

#include <string>

class Player
{
public:
	// constructor:
	Player()
	{
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

};

