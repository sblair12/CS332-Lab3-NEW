// Card.cpp
//
// Author- Shane Blair sblair@wustl.edu - February 20, 2018
//
// Purpose- Declarations for for a "Card" struct, which holds a rank and a suit 
// from a typical 52 card Poker deck, and functions related to Card comparison

#include "stdafx.h"
#include "Card.h"
#include "Parse.h"

#include <string>
#include <iostream>
using namespace std;

ostream & operator<<(ostream &o, const Card &c)
{
	o << rank_text[c.rank] << suit_text[c.suit];
	return o;
}

//Overload "less than" operator for Card structs.
bool operator<(const Card & c1, const Card & c2) {
	if (c1.rank < c2.rank) {
		return true;
	}
	if (c1.rank == c2.rank && c1.suit < c2.suit) {
		return true;
	}
	return false;
}

bool operator>(const Card & c1, const Card & c2)
{
	if (c1.rank > c2.rank) {
		return true;
	}
	if (c1.rank == c2.rank && c1.suit > c2.suit) {
		return true;
	}
	return false;
}

bool Card::operator!=(const Card &c) const
{
	if (suit == c.suit && rank == c.rank) {
		return false;
	}
	else {
		return true;
	}
}

bool Card::operator==(const Card &c) const
{
	if (suit == c.suit && rank == c.rank) {
		return true;
	}
	else {
		return false;
	}
}
