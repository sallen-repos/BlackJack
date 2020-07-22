#pragma once
#include "Hand.h"
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Dealer.h"
#include <string>

class BlackJack
{
public:

	
	void game();
	void printScores();
	void round(Player &);
	void determineWinner();
	void dealerRound(Dealer &);
	Hand dealCard(Hand &hand);

	BlackJack();
	~BlackJack();
	Player player;
	Dealer dealer;
	
};

