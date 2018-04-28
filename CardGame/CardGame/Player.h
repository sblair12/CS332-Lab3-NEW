// Player.h
//
// Authors: 
// Shane Blair	sblair@wustl.edu
// Steven Lee	lee.steven@wustl.edu
//
// April 6, 2018
//
// Purpose- Definitions for a "Player" struct
#pragma once
#include "Hand.h"

#include <string>
using namespace std;

struct Player {
	string name;
	Hand hand;
	unsigned int wins;
	unsigned int losses;
	unsigned int chips;
	bool computer = false;
	bool fold;
	unsigned int position = 1;

	Player(char *);
	bool operator==(const Player&) const;
};

ostream & operator<<(ostream &, const Player &);