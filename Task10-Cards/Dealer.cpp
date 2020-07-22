#include "pch.h"
#include "Dealer.h"
#include <string>
#include <iostream>

Dealer::Dealer()
{	

	
}

bool Dealer::hitOrStand()
{
	int sum = hand.getHandSum();
	if (sum < 17) {

		return true;
	}
	if (sum == 17)
		if (hand.getIsAceHigh())
			return true;
		else
			return false;

	return false;
}





Dealer::~Dealer()
{
}


