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
	virtual void bet();
	virtual void print_rankings();
	virtual int before_round();
	virtual int round();
	virtual int after_round();
protected:
	int before_turn(Player &);
	int turn(Player &);
	int after_turn(Player &);
	Deck discard_deck;

	//Ask players if they want to leave
	int computer_number_discarded(Player);
	vector<size_t> computer_discard(Player);
};

