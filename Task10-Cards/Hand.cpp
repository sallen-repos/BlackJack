#include "pch.h"
#include "Hand.h"
#include <string>

int sum;
int count;
int lastCard;
std::string owner;

Hand::Hand(std::string name)
{
	setDefault();
	owner = name;
}

//defaults to zero and false so fresh for a new game
void Hand::setDefault() {
	sum = 0;	
	count = 0;
	lastCard = 0;
}
//adds deal card to the participants hand
//determins if ace aught be high or low (if high equals bust)
//counts cards added to hand, and adds total to sum
//in black jack cards of rank jack through king (10 - 13) score as 10 
int Hand::addToHand(int cardNum,int rank)
{	
	lastCard = cardNum;		           //last casrd used to re-display dealers first card
										//(which when called is their last card)
	//if face card face card equal to 10
	if (rank >= 10) 
		sum += 10;
	//else if ace
	else if (rank == 1) {

		if (sum >= 10) {		//ace 11 + sum equals more thab 21, set ace low
			sum += 1;			
		}
		else {				
			sum += 11;			//else ace = high			
		}
	}
	else {
		sum += rank;		//if not a face card or ace rank stays the same.
	}

	return sum;

}
// give sum of all cards in deck
int Hand::getHandSum()
{	
	return sum;
}
//gives the most recently dealt card
int Hand::getLastCard()
{
	return lastCard;
}
//dertermings whether or not a hand is blackJack (21 with 2 cards) and returns a bool
bool Hand::isBlackJack()
{
	if (sum == 21 && count == 2)
	{
		return true;
	}
	return false;
}
//returns the name of participant who owns the hand (most likely player or dealer);
std::string Hand::ownerStr() {
	return owner;
}

Hand::~Hand()
{
}

