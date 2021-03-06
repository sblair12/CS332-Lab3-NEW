// CardGame.cpp : Defines the entry point for the console application.
//
// Authors:
// Shane Blair sblair@wustl.edu 
// Steven Lee lee.steven@wustl.edu
// 
// April 5, 2018
//
// TODO: Purpose- test

#include "stdafx.h"
#include "CardGame.h"
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
		while (game_ptr) {
			for (int i = player_name_index; i < argc; ++i) {
				game_ptr->add_player(argv[i]);
			}
			while (game_ptr->player_size() >= 2) {
				game_ptr->before_round();
				game_ptr->round();
				game_ptr->after_round();
			}
			cout << endl;
			cout << endl;
			cout << "Not enough Players, ending game..." << endl;
			if (game_ptr->player_size() != 0) {
				cout << "Saving progress for last player" << endl;
				game_ptr->remove_player(game_ptr->last_player()->name);
			}
			game_ptr->stop_game();
			game_ptr.reset();
			cout << "Game ended!" << endl;
			cout << endl;

			string input;
			bool another = false;
			bool correct = false;
			while (input.length() != 1 || !correct) {
				cout << "Would you like to play another game? (Y/n)" << endl;
				getline(cin, input);
				if (input.length() == 1) {
					if (input[0] == 'Y' || input[0] == 'y') {
						another = true;
						correct = true;
					}
					if (input[0] == 'N' || input[0] == 'n') {
						another = false;
						correct = true;
					}
				}
			}

			if (another) {
				correct = false;
				while (!correct) {
					cout << "What game would you like to play?" << endl;
					getline(cin, input);
					try {
						Game::start_game(input);
						correct = true;
					}
					catch (...) {
						cout << "Invalid game: " << input << endl;
					}
				}
				game_ptr = Game::instance();
			}
			else {
				cout << "Bye bye" << endl;
			}
		}
	}
	catch (int i) {
		cout << "Exception caught: " << i << endl;
		return i;
	}
	return 0;
}

//Helper function to print out program's usage method
void usage(char * program_name) {
	cout << "Usage: " << program_name << " <game_name> <player1> <player2> ..." << endl;
	cout << "\t\tRun this program with one argument for a game name and 2 or more arguments for player names" << endl;
	cout << "\t\t(ex: " << program_name << " fivecarddraw billybob Mao)" << endl;
}