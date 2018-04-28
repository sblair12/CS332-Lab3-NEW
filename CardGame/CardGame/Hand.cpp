// Hand.cpp
//
// Authors:
// Shane Blair	sblair@wustl.edu
// Steven Lee	lee.steven@wustl.edu
//
// April 5, 2018
//
// Purpose- Declarations for a "Hand" class

#include "stdafx.h"
#include "Hand.h"
#include "CardGame.h"
#include "Parse.h"

#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//Constructor
Hand::Hand(){
	hand = vector<Card>();
}

//Copy constructor
Hand::Hand(const Hand &h)
{
	hand.clear();
	hand = h.hand;
	hash = h.hash;
	to_poker = h.to_poker;
}

//Size of vector
int Hand::size() const
{
	return (int)hand.size();
}

//Get raw ranking
int Hand::get_ranking() const
{
	return hash;
}

void Hand::set_ranking(int rank)
{
	hash = rank;
}

//Get gross poker ranking
int Hand::get_poker() const
{
	return to_poker;
}

void Hand::set_poker(int poker)
{
	to_poker = poker;
}

Card Hand::remove_card(size_t index)
{
	if (index >= hand.size() || index < 0) {
		int i = out_of_bounds;
		throw i;
	}
	Card card = hand[index];
	hand.erase(remove(hand.begin(), hand.end(), card), hand.end());
	return card;
}

string Hand::as_string(vector<bool> format) const
{
	string output = "";
	ostringstream oss;
	unsigned int count = 0;

	for (Card card : hand) {
		if (format[count]) {
			int rank = card.rank;
			int suit = card.suit;
			oss << rank_text[rank] << suit_text[suit] << "\t";
		}
		else {
			oss << "*" << "\t";
		}
		count++;
	}

	output += oss.str();
	return output;
}

Hand & Hand::operator=(const Hand &h)
{
	if (this != &h) {
		hand.clear();
		hand = h.hand;
		hash = h.hash;
		to_poker = h.to_poker;
	}

	return *this;
}

int Hand::max_rank() const
{
	return hand[hand.size() - 1].rank;
}

Card Hand::operator[](size_t index)
{
	if (index >= hand.size() || index < 0) {
		int i = out_of_bounds;
		throw i;
	}
	return hand[index];
}

bool Hand::operator==(const Hand &h) const
{
	if (size() != h.size()) {
		return false;
	}
	for (int i = 0; i < size(); ++i) {
		if (hand[i] != h.hand[i]) {
			return false;
		}
	}
	return true;
}

bool Hand::operator!=(const Hand &h) const
{
	return !(*this == h);
}

//Lexical less than
bool Hand::operator<(const Hand &h) const
{
	for (int i = 0; i < size(); ++i) {
		if (hand[i] < h.hand[i]) {
			return true;
		}
		if (hand[i] > h.hand[i]) {
			return false;
		}
	}
	return false;
}


bool Hand::operator>(const Hand &h) const
{
	for (int i = size() - 1; i > 0; --i) {
		if (hand[i] > h.hand[i]) {
			return true;
		}
		if (hand[i] < h.hand[i]) {
			return false;
		}
	}
	return false;
}

ostream & operator<<(ostream &o, const Hand &h)
{
	string output = "";
	ostringstream oss;

	for (Card card : h.hand) {
		int rank = card.rank;
		int suit = card.suit;
		oss << rank_text[rank] << suit_text[suit] << "\t";
	}

	output += oss.str();
	o << output;
	return o;
}

Hand & operator<<(Hand &h, Deck &d)
{
	h.hand.push_back(d.deck.back());
	d.deck.pop_back();
	sort(h.hand.begin(), h.hand.end());
	return h;
}

//Returns true if h1 rank is greater than h2 rank
bool poker_rank(const Hand &h1, const Hand &h2) {
	int rank_1 = h1.get_ranking();
	int rank_2 = h2.get_ranking();
	if (rank_1 > rank_2) {
		return true;
	}
	if (rank_1 == rank_2) {
		return h1 > h2;
	}
	return false;
}

//Rank cards in a hand
void rankHand(Hand &hand) {
	int rank;
	int ranks[13] = {};
	int suits[4] = {};
	int consecutive = 0;

	//Determine the number of all ranks and suits for easier comparison (hopefully)
	for (int j = 0; j < hand.size(); ++j) {
		//Check for consecutive cards first
		if ((j != 0) && hand.hand[j].rank == hand.hand[j - 1].rank + 1) {
			consecutive++;
		}
		ranks[hand.hand[j].rank]++;
		suits[hand.hand[j].suit]++;
	}

	//Find maximum frequency of...
	int max_rank_freq = 0;
	int max_suit_freq = 0;
	int num_pairs = 0;

	int significant_number = 0;
	int next_significant = 100;

	bool not_recorded = true;

	//...each rank...
	for (int j = 0; j < 13; ++j) {
		max_rank_freq = max(ranks[j], max_rank_freq);
		if (ranks[j] == 2) {
			num_pairs++;
			next_significant = min(j, next_significant);
			//Determine the pair with the highest rank (one pair and two pair)
			if (not_recorded) {
				significant_number = max(j, significant_number);
			}
		}
		//Determine three and four of a kind
		if (ranks[j] == 3 || ranks[j] == 4) {
			significant_number = j;
			not_recorded = false;
		}
	}
	//...and each suit
	for (int j = 0; j < 4; ++j) {
		max_suit_freq = max(suits[j], max_suit_freq);
	}

	//Determine Poker rankings
	if (consecutive == 4) {
		if (max_suit_freq == 5) {
			rank = straight_flush;
		}
		else {
			rank = straight;
		}
	}
	else if (max_suit_freq == 5) {
		rank = flush_rank;
	}
	else if (max_rank_freq == 4) {
		rank = four_kind;
	}
	else if (max_rank_freq == 3) {
		if (num_pairs == 1) {
			rank = full_house;
		}
		else {
			rank = three_kind;
		}
	}
	else if (max_rank_freq == 2) {
		if (num_pairs == 2) {
			rank = two_pair;
		}
		else if (num_pairs == 1) {
			rank = one_pair;
		}
	}
	else {
		rank = high_card;
	}

	hand.set_poker(rank);
	hand.set_ranking((int)((rank*pow(13, 2)) + (significant_number*pow(13, 1)) + (next_significant*pow(13, 0))));
}