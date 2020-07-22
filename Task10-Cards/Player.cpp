#include "pch.h"
#include "Player.h"
#include <iostream>
#include <vector>

//initialise player chips and bet;
Player::Player()
{
	chips = 1000;			
	lastbet = -1;
}

//determine if player can re-bet their last amount  if lastbet isn't -1 (if there is a last amount)
void Player::placeBet() {

	if (lastbet < 0) {

		firstBet();
	}
	else
	{		
		rebet();
	}	   
}
//get input fot player to select a bet
void Player::firstBet()
{
	int input = -1;
	std::wcout << " Place your bet!\n 1. $10 \n 2. $20 \n 3. $50 \n 4. $70\n 5. $100\n"; // 6. Leave Table \n";
	std::cin >> input;

	amountBet(input);

}


//ask the player if they want to bet the same as last time
void Player::rebet()
{
	int input = -1;
	std::cout << " Place your bet!\n 1. Rebet\n 2. $10\n 3. $20\n 4. $50\n 5. $70\n 6. $100\n";// 7. Leave Table\n";
	std::cin >> input;

	if (input == 1) {
		bet = lastbet;
	}
	else {
		amountBet(input - 1);
	}
}
//set bet amount
void Player::amountBet(int input) {

	switch (input)
	{
	case 1:  bet = 10;
		break;
	case 2:	 bet = 20;
		break;
	case 3:  bet = 50;
		break;
	case 4:  bet = 70;
		break;
	case 5:  bet = 100;
		break;
	case 6:  bet = -1;
		break;
	default:
		std::cout << " Invalid Input!";
		placeBet();
		break;
	}
	lastbet = bet;			//set value of lastbet for the next round
	chips -= bet;		// subtract bet from players chips
}

//check which option the player selects if the player hits return true (to deal them a card)
bool Player::hitOrStand()
{
	int input = -1;
	std::cout << "\n 1. Hit\n 2. stand\n===================\n";
	std::cin >> input;

	switch (input)
	{
	case 1:  return true;  //return true if player hits
		break;
	case 2:	return false; //stand do nothing
		break;	
	default:
		std::cout << " Invalid Input!";
		hitOrStand();
		break;
	}
	return false; //return false if player doesn't hit
}


//get winnings or losses called at end of round
int Player::wonBlackJack() {

	int winnings = bet + (bet / 2);
	chips += winnings;
	return winnings;
}

int Player::wonBet() {
	
	chips += bet * 2;
	return bet;
}

void Player::drewBet() {
	
	chips += bet / 2;
}

void Player::lostBet() {

	chips -= bet;
}

//return value player has bet
int Player::getTotalChips() {
	
	return chips;
}

//unused functions potential to expand game
/*
void Player::split() {}
void Player::doubleDown() {}
void Player::surrender() {}
void Player::insurance() {}
void Player::evenMoney() {}
*/

Player::~Player()
{
}
