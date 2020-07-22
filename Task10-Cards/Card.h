#pragma once
#include <string>

class Card
{
public:

	void printCard(int);
	int getSuit(int);
	int getRank(int);
	std::string getCardStr(int);	
	Card();
	~Card();
};

