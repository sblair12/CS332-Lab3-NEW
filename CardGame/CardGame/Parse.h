// Parse.h
//
// Author:
// Shane Blair	sblair@wustl.edu
// Steven Lee	lee.steven@wustl.edu
//
// April 5, 2018
//
// Purpose- Definitions for "Card" file parsing functions, which can:
// parse valid card definition strings in a hand line into Card structs,
// identify valid hands and place them into a vector of Card structs,
// print the contents of a vector by converting from Card structs to card strings.
#pragma once

#include "Card.h"

#include <iostream>
#include <vector>
using namespace std;

enum result_codes {
	success, incorrect_arguments, cannot_open_input, no_valid_hands, 
	shuffle_no_deck, two_args_no_shuffle, two_shuffle_parameters, out_of_cards,
	out_of_bounds, instance_not_available, game_already_started, unknown_game,
	no_game_in_progress, already_playing, deck_out_of_cards,
	unexpected_error = -1, invalid_card = -2, end_of_line = -3
};

//Functions
int parseCards(vector<Card> & Deck, char * file_name);
Card toCard(string & holder);
