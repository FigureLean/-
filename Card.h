#pragma once
#ifndef CARD_H
#define CARD_H
#include<iostream>
#include<string>
using namespace std;
class Card {
private:
	int face;
	int suit;
	string suits[4] = { "Hearts","Diamonds","Clubs","Spades" };
    string faces[14] = {"\0 ","Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};


public:
	Card(int f,int s);
	//Card(int f);
	void toString();

	string toString2();

	string getCardFace();

	string getCardSuit();
	void showStringSuit();

	int getFace();


};



#endif // !CARD_H

