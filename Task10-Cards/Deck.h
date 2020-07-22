#pragma once
#include "Card.h"
class Deck
{
private:
	int bet;
	int lastbet;

public:
	Deck();
	void initDeck();	
	int dealCardNum();	
	bool isShuffled();
	bool shuffleDeck();
	void printAll();
	~Deck();


};

