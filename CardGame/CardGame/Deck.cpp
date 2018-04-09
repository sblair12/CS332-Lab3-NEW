// Deck.cpp
//
// Author- Shane Blair sblair@wustl.edu - March 17, 2018
//
// Purpose- Declarations for a "Deck" class

#include "stdafx.h"
#include "Deck.h"
#include "Parse.h"

#include <string>
#include <algorithm>
#include <random>
using namespace std;

Deck::Deck()
{
	deck = vector<Card>();
}

//Constructor
Deck::Deck(char * file_name)
{
	try {
		load(file_name);
	}
	catch (int i) {
		throw i;
	}
}

//Load file name strings into deck
void Deck::load(char * file_name)
{
	try {
		parseCards(deck, file_name);
	}
	catch (int i) {
		throw i;
	}
}

void Deck::add_card(Card c)
{
	deck.push_back(c);
}

//Shuffle deck
void Deck::shuffle()
{
	random_device rd;
	mt19937 g(rd());
	std::shuffle(deck.begin(), deck.end(), g);
}

int Deck::size() const
{
	return (int)deck.size();
}

ostream & operator<<(ostream & o, const Deck & d)
{
	int count = 1;

	for (Card card : d.deck) {
		int rank = card.rank;
		int suit = card.suit;

		o << rank_text[rank] << suit_text[suit] << " ";
		if (count % 13 == 0 && count != d.size()) {
			cout << endl;
		}
		++count;
	}
	cout << endl;
	return o;
}
