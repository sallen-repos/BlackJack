#pragma once
#include <string>
class Hand
{
private: 

	int sum;
	int count;
	int lastCard;
	bool aceHigh;
	std::string owner;

public:

	int addToHand(int,int);
	bool isBlackJack();
	int getLastCard();
	int getHandSum();
	void setDefault();
	std::string ownerStr();
	
	Hand(std::string);
	~Hand();


};

