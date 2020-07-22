// Task10-Cards.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include "Deck.h"
#include "BlackJack.h"


const int NUM_CARDS = 52;
const int NUM_RANKS = 13;



int main()
{
	BlackJack blackjack;
	Deck deck;
	   
	//deck.initDeck();
	//deck.shuffleDeck();
	//deck.printAll();
	
	//cout << deck.dealCardNum() << '\n';
	//cout << deck.dealCardNum() << '\n';
	
	//cout << (47/ NUM_RANKS) << '\n';

	//cout << (7 / NUM_RANKS) << '\n';

	//int cardNum = 12;

	//int suit = cardNum / NUM_RANKS;

	//int rank = (cardNum % NUM_RANKS) + 2;
	// 0 1 2 3 4 5 6 7 8 9  10  11   12   13
	// ace 2 3 4 5 6 7 8 9  10 jack queen king

	

	




	// 0 1 2 3 4 5 6 7 8  9  10	  11    12   13
	// 1 2 3 4 5 6 7 8 9  10 jack queen king ace

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
