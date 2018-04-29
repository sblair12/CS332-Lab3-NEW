// TexasHoldEm.h
//
// Authors: 
// Shane Blair	sblair@wustl.edu
// Steven Lee	lee.steven@wustl.edu
//
// April 28, 2018
//
// Purpose- Definitions for the TexasHoldEm class derived from "Game" publically
#pragma once

#include "Game.h"

class TexasHoldEm : public Game {
public:
	TexasHoldEm();
	virtual void bet();
	virtual void print_rankings();
	virtual int before_round();
	virtual int round();
	virtual int after_round();
protected:
	Deck discard_deck;
	vector<Card> shared_cards;
};