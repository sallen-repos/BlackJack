#pragma once
#include "Hand.h"

class Player
{
private:
	int bet;
	int lastbet;
	int chips;

public:
	
	bool hitOrStand();
	
	void amountBet(int);
	void rebet();
	void placeBet();
	//bool firstTurn();
	void firstBet();
	int getTotalChips();
	void lostBet();
	void drewBet();
	int wonBet();
	int wonBlackJack();

	/*
	void split();	
	void doubleDown();
	void surrender();
	void insurance();
	void evenMoney();
	
	*/
	Player();
	~Player();
	
	Hand hand = Hand("Player");
};

