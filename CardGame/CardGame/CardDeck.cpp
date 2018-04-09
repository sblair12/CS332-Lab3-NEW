// CardDeck.cpp : Defines the entry point for the console application.
//
// Author- Shane Blair sblair@wustl.edu - March 6, 2018
//
// Purpose- Initialize a deck from a file input,
// deal a set number of cards to a set number of hands,
// and sort those cards based on lexical and Poker ranking order

#include "stdafx.h"
#include "CardDeck.h"
#include "Hand.h"
#include "Parse.h"

#include <iostream>		//For standard output stream
#include <vector>		//For standard vectors
#include <iterator>		//For standard iterators
#include <string>		//For standard C++ strings
#include <fstream>		//For standard input stream to operate on files
#include <sstream>		//For standard string streams 
#include <algorithm>	//For standard algorithms

//Symbols used from standard namespace
using namespace std;

//Constants to be used in program
const int min_arguments = 2;
const int max_arguments = 3;
const int hand_number = 9;
const int card_number = 5;
const int program_name_index = 0;

int main(int argc, char * argv[])
{
	if (argc > max_arguments || argc < min_arguments) {
		usage(argv[program_name_index]);
		return incorrect_arguments;
	}

	//One command line argument
	if (argc == min_arguments) {
		string argument = argv[1];
		if (argument == "--usage") {
			usage(argv[program_name_index]);
			return incorrect_arguments;
		}
		if (argument == "-shuffle") {
			cout << "ERROR: '-shuffle' parameter given without a location for a deck file" << endl;
			return shuffle_no_deck;
		}
		try {
			Deck deck(argv[1]);
			run(deck);
		}
		catch (int i) {
			return i;
		}
		catch (...) {
			cout << "Unknown exception caught" << endl;
		}

		//do stuff
	}

	//Two command line arguments
	if (argc == max_arguments) {
		string argument_1 = argv[1];
		string argument_2 = argv[2];

		if (argument_1 == "-shuffle" || argument_2 == "-shuffle") {

			//Both arguments are shuffle
			if (argument_1 == "-shuffle" && argument_2 == "-shuffle") {
				cout << "ERROR: Both parameters are the '-shuffle' parameter" << endl;
				return two_shuffle_parameters;
			}
			char * argument;
			//First argument is shuffle
			if (argument_1 == "-shuffle") {
				argument = argv[2];
			}
			//Second argument is shuffle
			else {
				argument = argv[1];
			}

			//Load the deck
			try {
				Deck deck(argument);
				deck.shuffle();
				run(deck);
			}
			catch (int i) {
				return i;
			}
			catch (...) {
				cout << "Unknown exception caught" << endl;
			}
		}
		else {
			cout << "ERROR: Two parameters given but none are the '-shuffle' parameter" << endl;
			return two_args_no_shuffle;
		}
	}
}

void run(Deck deck) {
	cout << endl;
	cout << "DECK before dealing:" << endl;
	cout << deck << endl;
	vector<Hand> hands;

	//Create hands
	for (int i = 0; i < hand_number; ++i) {
		hands.push_back(Hand());
	}

	//Deal to hands
	for (int round = 0; round < card_number; ++round) {
		for (int i = 0; i < hand_number; ++i) {
			if (deck.size() == 0) {
				cout << hand_number << " hands total" << endl;
				cout << "Not enough cards in the deck to deal " << card_number << " cards to all hands" << endl;
				int exception = out_of_cards;
				throw exception;
			}
			hands[i] << deck;
		}
	}
	cout << "DECK after dealing:" << endl;
	cout << deck << endl;
	cout << "HANDS:" << endl;
	
	for (int i = 0; i < hand_number; ++i) {
		rankHand(hands[i]);
		cout << hands[i] << endl;
	}

	sort(hands.begin(), hands.end());

	cout << endl;
	cout << "HANDS sorted by less than operator:" << endl;
	for (int i = 0; i < hand_number; ++i) {
		cout << hands[i] << endl;
	}

	sort(hands.begin(), hands.end(), poker_rank);

	cout << endl;
	cout << "HANDS sorted by Poker ranking:" << endl;
	for (int i = 0; i < hand_number; ++i) {
		rankHand(hands[i]);
		cout << hands[i] << poker_text[hands[i].get_poker()] << endl;
	}

}

//Helper function to print out program's usage method
void usage(char * program_name) {
	cout << "Usage: " << program_name << " <argument> [-shuffle]" << endl;
	cout << "\t\tRun this program with one argument for a deck file and an optional parameter" << endl;
	cout << "\t\t('-shuffle' to shuffle the deck before usage)" << endl;
}