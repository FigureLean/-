#pragma once
#ifndef DECKOFCARD_H
#define DECKOFCARD_H
#include"Card.h"
#include<vector>
using namespace std;

class DeckOfCard {

private:
	vector<Card>deck;
	int currentCard;

public:
	DeckOfCard();
	void shuffle();
	void print(int k);
	Card dealCard();
	bool moreCards();
	void pair();//≈–∂œÕ¨∫≈≈∆
	void pair2();//≈–∂œÕ¨ª®≈∆
	void pair3();//≈–∂œÕ¨À≥
};

#endif // !DECKOFCARD_H
