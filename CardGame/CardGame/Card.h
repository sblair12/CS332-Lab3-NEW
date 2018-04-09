// Card.h
//
// Author- Shane Blair sblair@wustl.edu - February 20, 2018
//
// Purpose- Definitions for a "Card" struct, which holds a rank and a suit 
// from a typical 52 card Poker deck, and functions related to Card comparison
#pragma once


#include <vector>
using namespace std;

const vector<string> rank_text = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
const vector<string> suit_text = { "C", "D", "H", "S" };

enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

//Struct of type "Card"
struct Card {
	Rank rank;
	Suit suit;

	bool operator!=(const Card &) const;
	bool operator==(const Card &) const;

};

ostream & operator<<(ostream &, const Card &);

bool operator<(const Card &c1, const Card &c2);
bool operator>(const Card &c1, const Card &c2);
