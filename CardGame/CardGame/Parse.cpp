// Parse.cpp
//
// Author- Shane Blair sblair@wustl.edu - February 1, 2018
//
// Purpose- Declarations for "Card" file parsing functions, which can:
// parse valid card definition strings in a hand line into Card structs,
// identify valid hands and place them into a vector of Card structs,
// print the contents of a vector by converting from Card structs to card strings.

#include "stdafx.h"
#include "Parse.h"
#include "Hand.h"

#include <iostream>		//For standard output stream
#include <vector>		//For standard vectors
#include <string>		//For standard C++ strings
#include <fstream>		//For standard input stream to operate on files
#include <sstream>		//For standard string streams
#include <algorithm>	//For vector sorting algorithm

//Symbols used from standard namespace
using namespace std;

//Helper function to parse a file of "Card" strings and push back a card struct instance to a vector
int parseCards(vector<Card> & Deck, char * file_name) {
	string in = file_name;
	ifstream ifs(in);

	if (ifs.is_open()) {
		string line_1, card_string;
		for (int j = 1; getline(ifs, line_1);) {
			if (!line_1.empty()) {
				istringstream iss(line_1);
				int k;
				for (k = 0; iss >> card_string;) {
					try {
						Card card = toCard(card_string);
						Deck.push_back(card);
						++k;
						if (card_string.length() == 4 && card_string[2] == '/' && card_string[3] == '/') {
							int e = end_of_line;
							throw e;
						}
						if (card_string.length() == 5 && card_string[3] == '/' && card_string[4] == '/') {
							int e = end_of_line;
							throw e;
						}
					}

					//If the Card string is valid, the push back to a vector. If not an exception is thrown
					catch (int i) {
						if (i == end_of_line) {
							break;
						}

						if (i == invalid_card) {
							cout << "Invalid Card\tat Line " << j << ":\tCard \"" << card_string << "\"" << endl;
						}
					}

				}
				++j;
			}

		}

		//If there are no valid hands in the file
		if (Deck.size() == 0) {
			int i = no_valid_hands;
			cout << endl;
			cout << "No valid hands in input file" << endl;
			throw i;
		}
		else {
			return success;
		}
	}
	else {
		int i = cannot_open_input;
		cout << "Cannot open the input file" << endl;
		throw i;
	}
}

//Helper function to convert a "Card" string to a card struct instance for printing use
Card toCard(string & holder) {

	//Force end of line when reaching a comment symbol
	if (holder[0] == '/' && holder[1] == '/') {
		int i = end_of_line;
		throw i;
	}

	//Valid "Card" strings are only of character length 2 or 3
	if (holder.length() < 2 || holder.length() > 4) {
		int i = invalid_card;
		throw i;
	}

	Card card;
	char card_rank;
	char card_suit;

	if (holder.length() == 2 || holder.length() == 4) {

		//The first character is the rank and the second is the suit
		card_rank = holder[0];
		card_suit = holder[1];

		switch (card_rank) {
		case '2': card.rank = TWO;
			break;
		case '3': card.rank = THREE;
			break;
		case '4': card.rank = FOUR;
			break;
		case '5': card.rank = FIVE;
			break;
		case '6': card.rank = SIX;
			break;
		case '7': card.rank = SEVEN;
			break;
		case '8': card.rank = EIGHT;
			break;
		case '9': card.rank = NINE;
			break;
		case 'J':
		case 'j': card.rank = JACK;
			break;
		case 'Q':
		case 'q': card.rank = QUEEN;
			break;
		case 'K':
		case 'k': card.rank = KING;
			break;
		case 'A':
		case 'a': card.rank = ACE;
			break;
		default: int i = invalid_card;
			throw i;
			break;
		}
	}

	if (holder.length() == 3 || holder.length() == 5) {
		//Cards of length 3 must be of rank 10 and the suit is the 3rd character
		card.rank = TEN;
		card_suit = holder[2];
	}

	switch (card_suit) {
	case 'C':
	case 'c': card.suit = CLUBS;
		break;
	case 'D':
	case 'd': card.suit = DIAMONDS;
		break;
	case 'H':
	case 'h': card.suit = HEARTS;
		break;
	case 'S':
	case 's': card.suit = SPADES;
		break;
	default: int i = invalid_card;
		throw i;
		break;
	}
	return card;
}
