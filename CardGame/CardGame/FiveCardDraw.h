// FiveCardDraw.h
//
// Authors: 
// Shane Blair	sblair@wustl.edu
// Steven Lee	lee.steven@wustl.edu
//
// April 6, 2018
//
// Purpose- Definitions for the FiveCardDraw class derived from "Game" publically
#pragma once

#include "Game.h"
#include "Deck.h"

class FiveCardDraw : public Game {
public:
	FiveCardDraw();
	void remove_cards(vector<size_t> &, Player &);
	virtual int before_turn(Player &);
	virtual int turn(Player &);
	virtual int after_turn(Player &);
	virtual int before_round();
	virtual int round();
	virtual int after_round();
protected:
	size_t dealer_index;
	Deck discard_deck;
	void print_rankings();
	void players_leave();
	void players_join();
};

bool poker_rank_ptr(const shared_ptr<Player>&, const shared_ptr<Player>&);