// Hand.h
//
// Author- Shane Blair sblair@wustl.edu - March 19, 2018
//
// Purpose- Definitions for a "Hand" class
#pragma once

#include "Card.h"
#include "Deck.h"

#include <vector>
#include <memory>
using namespace std;

enum poker_rank { high_card, one_pair, two_pair, three_kind, straight, flush_rank, full_house, four_kind, straight_flush };
const vector<string> poker_text = { "High Card", "One Pair", "Two Pairs", "Three of a Kind", "Straight", "Flush", "Full House", "Four of a Kind", "Straight Flush" };

class Hand {
private:
	vector<Card> hand;
	int hash;
	int to_poker;
public:
	Hand();
	//Copy constructor
	Hand(const Hand &);
	//No destructor needed, as the vector member variable is a vector of objects, not of pointers to objects, so the default destructor suffices

	int	size() const;
	int	get_ranking() const;
	void set_ranking(int);
	int get_poker() const;
	void set_poker(int);
	Card remove_card(size_t);
	string as_string() const;

	Hand & operator=(const Hand&);
	int max_rank() const;

	Card operator[](size_t);
	bool operator==(const Hand&) const;
	bool operator<(const Hand&) const;
	bool operator>(const Hand&) const;
	friend ostream & operator<<(ostream &, const Hand &);
	friend Hand & operator<<(Hand &, Deck &);

	friend void rankHand(Hand &hand);
};

bool poker_rank(const Hand &, const Hand &);