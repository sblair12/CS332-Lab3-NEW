// SevenCardStud.h
//
// Authors: 
// Shane Blair	sblair@wustl.edu
// Steven Lee	lee.steven@wustl.edu
//
// April 27, 2018
//
// Purpose- Definitions for the SevenCardStud class derived from "Game" publically
#pragma once

#include "Game.h"

class SevenCardStud : public Game {
public:
	SevenCardStud();
	virtual void bet();
	virtual void print_rankings();
	virtual int before_round();
	virtual int round();
	virtual int after_round();
protected:
	Deck discard_deck;
};