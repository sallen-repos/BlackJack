#include "pch.h"
#include "BlackJack.h"
#include <iostream>
#include <string.h>
using namespace std;


int pot;
const int NUM_RANKS = 13;

Deck deck;
Player player;
Player* dealer;
Card card;

BlackJack::BlackJack() {

	//display chips
	cout << "Total Chips = $" << player.getTotalChips() << '\n';
	//deck initialised here, to avoid repetition between rounds
	//the deck is infact 8 decks as is mosr common in casinos
	deck.initDeck();
	game();
}

void BlackJack::game() {
	//shufle deack at start	   	
	deck.shuffleDeck();

	//show bet options and get user input
	player.placeBet();

	//first dealer is dealt one card
	dealer.hand = dealCard(dealer.hand);	

	//player is dealt two cards
	player.hand = dealCard(player.hand);
	player.hand = dealCard(player.hand);

	//totals of dealers and player hand printed
	printScores();

	//player round, do they hit or stand if players bust round will end early
	round(player);

	//dealers round dealer descions called here, dealer hits on values under 17 whatever the player cards
	//and stands on values 17 the dealer however hits on soft 17 (a total of 17, where an ace is high) 
	//soft 17 rules is common in casinos
	dealerRound(dealer);

	// games rules applied here
	determineWinner();

	//reset players and dealers hands
	player.hand.setDefault();
	dealer.hand.setDefault();
	
	system("pause");
	
	game();
}
//determine who won applying game rules
void BlackJack::determineWinner() {

	int playerFinalScore = player.hand.getHandSum();

	cout << '\n';
	if (playerFinalScore > 21)			//if player scored over 21 and is bust
	{
		cout << " Bust! You Lost!\n";
		player.lostBet();
	}
	else												//if 21 and under
	if (playerFinalScore > dealer.hand.getHandSum()) {		//if greater than dealers score				

		if (player.hand.isBlackJack()) {
			cout << "BLACK JACK!! You Won $" << player.wonBlackJack() << "!\n";		//if greater than dealers score and exactly 21
		}																			//player wins 2:3 as standard in 8 deck rules
		else {
			cout << " You Won $" << player.wonBet() << "!\n";

		}
	}
	else									
		if (playerFinalScore == dealer.hand.getHandSum()) {		//if dealer and players score are matched


			if (player.hand.isBlackJack() && !dealer.hand.isBlackJack()) {		//check if only the player has black jack
				cout << "BLACK JACK!! You Won $" << player.wonBlackJack() << "!\n";  
				player.wonBet();
			}
			else
			if (!player.hand.isBlackJack() && dealer.hand.isBlackJack()) {	//check if only the dealer has black jack 
					cout << " You Lost!\n";
					player.lostBet();
			}
			else
			{
					cout << " Draw!\n";	  //if nobody has black jack players draw, or both player have black jack
					player.drewBet();
			}
		}
	else
	if (dealer.hand.getHandSum() > 21) {	//if dealer is bust the player won
		cout << " You Won $" << player.wonBet() << "!\n";
	}
	else
	{
		cout << " You Lost!\n";
		player.lostBet();
	}

	cout << "Total Chips = $" << player.getTotalChips() << '\n';
}

//dealcards until player stands or is bust
void BlackJack::round(Player &participant) {
	
	while (participant.hand.getHandSum() < 21 && participant.hitOrStand())
	{
		dealCard(participant.hand);	
		printScores(); //print scores after each turn so player view them when deciding to hit or stand
	}
	
}
//deal cards until dealer stands or is bust 
void BlackJack::dealerRound(Dealer &participant) {

	while (participant.hand.getHandSum() < 21 && participant.hitOrStand())
	{
		dealCard(participant.hand);
	}
	printScores(); //print scores after round
}
//prints hand and the "owner" of the respective hand
void BlackJack::printScores() 
{
	cout << dealer.hand.ownerStr() << " Hand = " << dealer.hand.getHandSum() << " vs "
	<< player.hand.ownerStr() << " Hand = " << player.hand.getHandSum() << '\n';
}

Hand BlackJack::dealCard(Hand &hand) {
		 
	int cardNum = deck.dealCardNum();
	hand.addToHand(cardNum, card.getRank(cardNum)); 
	cout << hand.ownerStr() << "s ";
	card.printCard(cardNum);
	cout << "=================\n";
	return hand;
}

BlackJack::~BlackJack()
{
}

