#include "pch.h"
#include "Deck.h"
#include <iostream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <time.h>
#include <iostream>


using namespace std;

//deck a vector of chars (-127 to +127)
vector<char> deck;

//number of decks set to 8 could be increased
const int NUM_DECKS = 8;
const int NUM_IN_DECK = 52; //num in deack could be changed for a game with jokers

bool shuffled = false;

Deck::Deck()
{

}

void Deck::initDeck() {

	//8 decks created in loop
	for (int i = 0; i < NUM_DECKS; i++) {
		for (int j = 0; j < NUM_IN_DECK; j++) {//values from 0-51 placed in vector of chars 8 times
			deck.push_back(j);
		}
	}
}
//deck(s) are shuffled
bool Deck::shuffleDeck() {
	srand(time(NULL));
	random_shuffle(deck.begin(), deck.end());	
	return shuffled = true;
}
//bool is shuffled
bool Deck::isShuffled() {
	return shuffled;	
}
//deal card if deck is not empty
int Deck::dealCardNum() {
	int result = -1;
	if (!deck.empty() )
	{
		result = deck.back();
		deck.erase(deck.end() -1);	//as card is taken from deck card is erased
	}
	return result; //if deck is empty -1 returned
}
//simply prints all cards in vector for length of vector (all 8 decks)
void Deck::printAll() {
	for (int i = 0; i < NUM_IN_DECK * NUM_DECKS; ++i)
		cout << deck[i] << '\n';
}


Deck::~Deck()
{
}
