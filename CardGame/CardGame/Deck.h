// Deck.h
//
// Authors:
// Shane Blair	sblair@wustl.edu
// Steven Lee	lee.steven@wustl.edu
//
// April 5, 2018
//
// Purpose- Definitions for a "Deck" class
#pragma once

#include "Card.h"

#include <iostream>
#include <vector>
using namespace std;

//Deck class
class Deck {
private:
	vector<Card> deck;
	friend class Hand;
	friend class FiveCardDraw;
public:
	Deck();
	Deck(char *);
	//No destructor needed, as the vector member variable is a vector of objects, not of pointers to objects, so the default destructor suffices

	void load(char *);
	void add_card(Card);
	void shuffle();
	int size() const;
	friend ostream & operator<<(ostream &, const Deck &);
	friend Hand & operator<<(Hand &, Deck &);
};