#include "pch.h"
#include "Card.h"
#include <string.h>
#include <iostream>

static const int NUM_RANKS = 13;
static const int SUITS_SIZE = 4;
static const int CARD_NAME_SIZE = 13;
static const std::string suits[SUITS_SIZE] = { "Clubs", "Diamonds", "Hearts", "Spades" };
static const std::string cardNames[CARD_NAME_SIZE] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };

Card::Card() 
{

}

//suit of card is dermined by the number of cards in the deck / by the  number of cards in a suit (NUM_RANKS) 
int Card::getSuit(int cardNum) {
	if (cardNum / NUM_RANKS > SUITS_SIZE) {
		std::cout << "ERROR 4 or over!: " << cardNum;
		return -1;
	}
	return cardNum / NUM_RANKS;
}
//rank of card is dermined by the number of cards in the deck % the number of cards in a suit (NUM_RANKS) 
int Card::getRank(int cardNum) {
	if (cardNum % NUM_RANKS > CARD_NAME_SIZE) {
		std::cout << "ERROR 13 or over!" << cardNum;
		return -1;
	}
	int rank = (cardNum % NUM_RANKS) + 1;	
	return rank;
}
//printes the rank and suit of a given card
void Card::printCard(int cardNum) {
	std::cout << "\n " << cardNames[getRank(cardNum) -1] << " of " << suits[getSuit(cardNum)] << '\n';
}

std::string Card::getCardStr(int cardNum) {

	return cardNames[cardNum % NUM_RANKS] + " of " + suits[cardNum / NUM_RANKS];
	
}

Card::~Card()
{
}
