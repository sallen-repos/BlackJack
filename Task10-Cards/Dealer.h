#pragma once
#include "Player.h"
#include "Hand.h"

class Dealer
{
public:

	//bool hitOrStand();
	bool hitOrStand();

	Dealer();
	~Dealer();


	Hand hand = Hand("Dealer");
};
