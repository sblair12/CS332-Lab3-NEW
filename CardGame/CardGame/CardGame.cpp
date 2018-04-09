// FiveCard.cpp : Defines the entry point for the console application.
//
// Authors:
// Shane Blair sblair@wustl.edu 
// Steven Lee lee.steven@wustl.edu
// 
// April 5, 2018
//
// TODO: Purpose- test

#include "stdafx.h"
#include "CardDeck.h"
#include "Game.h"
#include "FiveCardDraw.h"
#include "Hand.h"
#include "Parse.h"

#include <iostream>		//For standard output stream
#include <vector>		//For standard vectors
#include <iterator>		//For standard iterators
#include <string>		//For standard C++ strings
#include <fstream>		//For standard input stream to operate on files
#include <sstream>		//For standard string streams 
#include <algorithm>	//For standard algorithms
#include <memory>

//Symbols used from standard namespace
using namespace std;

//Constants to be used in program
const int min_arguments = 4;
const int hand_number = 9;
const int card_number = 5;
const int program_name_index = 0;
const int player_name_index = 2;

int main(int argc, char * argv[])
{
	if (argc < min_arguments) {
		usage(argv[program_name_index]);
		return incorrect_arguments;
	}

	string game_name = argv[1];

	try {
		Game::start_game(game_name);
		shared_ptr<Game> game_ptr = Game::instance();
		for (int i = player_name_index; i < argc; ++i) {
			game_ptr->add_player(argv[i]);
		}
		game_ptr->before_round();
		game_ptr->round();
		game_ptr->after_round();
	}
	catch (int i) {
		cout << "Exception caught: " << i << endl;
		return i;
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
	cout << "Usage: " << program_name << " <game_name> <player1> <player2> ..." << endl;
	cout << "\t\tRun this program with one argument for a game name and 2 or more arguments for player names" << endl;
	cout << "\t\t(ex: " << program_name << " fivecarddraw billybob Mao)" << endl;
}