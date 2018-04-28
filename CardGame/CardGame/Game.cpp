// Game.cpp
//
// Authors: 
// Shane Blair	sblair@wustl.edu
// Steven Lee	lee.steven@wustl.edu
//
// April 6, 2018
//
// Purpose- Declarations for a Game abstract base class

#include "stdafx.h"
#include "Game.h"
#include "FiveCardDraw.h"
#include "Deck.h"
#include "Parse.h"

#include <fstream>
#include <sstream>
using namespace std;

const unsigned int ante_amount = 1;
const vector<string> game_string = { "FiveCardDraw", "fivecarddraw", "SevenCardStud", "sevencardstud" };

//Initialize game_ptr for use
shared_ptr<Game> Game::game_ptr;

shared_ptr<Game> Game::instance()
{
	//If the pointer points to nothing (singular)
	if (!game_ptr) {
		int i = instance_not_available;
		throw i;
	}
	else {
		return game_ptr;
	}
}

void Game::start_game(const string game)
{
	//If the pointer points to something (non-singular)
	if (game_ptr) {
		cout << "A game is already started" << endl;
		int i = game_already_started;
		throw i;
	}
	else {
		//Check if game is one that we have to play or not
		for (int i = 0; i < game_string.size(); ++i) {
			if (game == game_string[i]) {
				game_ptr = make_shared<FiveCardDraw>();
				cout << "Playing: " << game_string[i] << endl;
			}
		}
		if (!game_ptr) {
			//No known game type is found
			cout << "Unknown game type: " << game << endl;
			int i = unknown_game;
			throw i;
		}

	}
}

void Game::stop_game()
{
	if (game_ptr) {
		game_ptr.reset();
	}
	else {
		cout << "There is no game in progress" << endl;
		int i = no_game_in_progress;
		throw i;
	}
}

void Game::add_player(const string player)
{
	for (int i = 0; i < ptr_vector.size(); ++i) {
		Player existing = *ptr_vector[i].get();
		if (player == existing.name) {
			cout << player << " is already playing" << endl;
			int i = already_playing;
			throw i;
		}
	}
	char * player_name = new char [player.length() + 1];
	strcpy_s(player_name, player.length() + 1, player.c_str());
	shared_ptr<Player> player_ptr = make_shared<Player>(player_name);
	ptr_vector.push_back(player_ptr);
	if (player_ptr->computer) {
		cout << "Added: " << player_name << "\t(Computer)" << endl;
	}
	else {
		cout << "Added: " << player << endl;
	}
}

shared_ptr<Player> Game::find_player(const string player)
{
	shared_ptr<Player> ptr;
	for (int i = 0; i < ptr_vector.size(); ++i) {
		Player existing = *ptr_vector[i].get();
		if (player == existing.name) {
			ptr = make_shared<Player>(existing);
		}
	}
	return ptr;
}

void Game::remove_player(const string name)
{
	cout << "Finding: " << name << endl;
	shared_ptr<Player> player = find_player(name);
	if (player) {
		ofstream ofs(name);
		if (ofs.is_open()) {
			ofs << *player;
		}
		ofs.close();
		for (auto i = ptr_vector.begin(); i != ptr_vector.end(); ++i) {
			shared_ptr<Player> compare = *i;
			if (*player.get() == *compare.get()) {
				cout << "Bye " << name << "!" << endl;
				ptr_vector.erase(i);
				break;
			}
		}
	}
	else {
		cout << "Invalid name: " << name << endl;
	}
}

shared_ptr<Player> Game::last_player()
{
	return ptr_vector[0];
}

size_t Game::player_size()
{
	return ptr_vector.size();
}

void Game::players_leave()
{
	string input;
	bool leave = false;
	bool correct = false;

	//Determine if computers leave or not
	for (int i = 0; i < ptr_vector.size(); ++i) {
		if (ptr_vector[i]->computer) {
			unsigned int random_number = rand() % 100;
			unsigned int chance;
			if (ptr_vector[i]->position == 2) {
				chance = 90;
			}
			else if (ptr_vector[i]->position == 0) {
				chance = 10;
			}
			else {
				chance = 50;
			}
			if (random_number > chance) {
				cout << "Computer \"" << ptr_vector[i]->name << "\" has decided to leave" << endl;
				remove_player(ptr_vector[i]->name);
			}
		}
	}

	while (input.length() != 1 || !correct) {
		cout << "Does any Player want to leave? (Y/n)" << endl;
		getline(cin, input);
		if (input.length() == 1) {
			if (input[0] == 'Y' || input[0] == 'y') {
				leave = true;
				correct = true;
			}
			if (input[0] == 'N' || input[0] == 'n') {
				leave = false;
				correct = true;
			}
		}
	}

	if (leave) {
		//Get names of Players who are leaving
		cout << "Which Players would like to leave? (separate names with spaces, ex: joe bob billybob)" << endl;
		getline(cin, input);
		string name;
		istringstream iss(input);

		while (iss >> name) {
			remove_player(name);
		}
	}
}

void Game::players_join()
{
	string input;
	bool join = false;
	bool correct = false;
	while (input.length() != 1 || !correct) {
		cout << "Do any new Players want to join? (Y/n)" << endl;
		getline(cin, input);
		if (input.length() == 1) {
			if (input[0] == 'Y' || input[0] == 'y') {
				join = true;
				correct = true;
			}
			if (input[0] == 'N' || input[0] == 'n') {
				join = false;
				correct = true;
			}
		}
	}

	if (join) {
		//Get names of Players who want to join
		cout << "Which Players would like to join? (separate names with spaces, ex: mao dan stevebob)" << endl;
		getline(cin, input);
		string name;
		istringstream iss(input);

		while (iss >> name) {
			cout << "Adding: " << name << endl;
			shared_ptr<Player> player = find_player(name);
			if (!player) {
				try {
					add_player(name);
					cout << "Hi " << name << "!" << endl;
				}
				catch (int i) {
					if (i == 13) {
						cout << "Player: " << name << " is already in the game!" << endl;
					}
					else {
						throw i;
					}
				}
			}
			else {
				cout << "Invalid name: " << name << endl;
			}
		}
	}
}

void Game::ante()
{
	pot = 0;
	cout << "Ante:" << endl;
	for (int i = 0; i < ptr_vector.size(); ++i) {
		cout << ante_amount << " chip(s) from " << ptr_vector[i]->name << endl;
		ptr_vector[i]->chips = ptr_vector[i]->chips - ante_amount;
		pot = pot + ante_amount;
	}
	cout << "Pot: " << pot << endl;
}

void Game::bet()
{
	size_t bet_index = (dealer_index + 1) % ptr_vector.size();
	unsigned int bet_round = 0;
	unsigned int current_bet = 0;

	while (bet_round < ptr_vector.size()) {
		string input;
		string substring = "invalid";
		unsigned int bet_amount = 0;
		unsigned int correct_length;

		cout << ptr_vector[bet_index]->name << "\tChips: " << ptr_vector[bet_index]->chips << "\t";
		cout << endl;

		while (substring != "check" && substring != "bet" && substring != "fold" && substring != "raise" && substring != "call") {
			if (current_bet == 0) {
				cout << "Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)" << endl;
				getline(cin, input);
				if (input == "check") {
					substring = input;
				}
				if (input.substr(0, 3) == "bet") {
					correct_length = 5;
					substring = "bet";
					bet_round = 0;
					if (input.length() == 5) {
						istringstream bet_stream(input.substr(4, 5));
						bet_stream >> bet_amount;
						if (bet_amount <= 2 && bet_amount > 0 && bet_amount <= ptr_vector[bet_index]->chips) {
							current_bet = bet_amount;
						}
						else if (bet_amount > ptr_vector[bet_index]->chips) {
							cout << "Invalid bet: You only have " << ptr_vector[bet_index]->chips << " chip(s) to bet" << endl;
							substring = "invalid";
						}
						else {
							cout << "Invalid bet: The maximum bet is 2 chips" << endl;
							substring = "invalid";
						}
					}
					else {
						cout << "Invalid bet: Bet must be either 1 or 2 chips" << endl;
						substring = "invalid";
					}
				}
				if (input == "raise") {
					substring = "invalid";
				}
			}
			else {
				cout << "Current Bet: " << current_bet << endl;
				cout << "Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2 chips)" << endl;
				getline(cin, input);
				if (input == "fold") {
					ptr_vector[bet_index]->fold = true;
					substring = input;
				}
				if (input == "call") {
					substring = input;
				}
				if (input.substr(0, 5) == "raise") {
					correct_length = 7;
					substring = "raise";
					bet_round = 0;
					if (input.length() == 7) {
						istringstream bet_stream(input.substr(6, 7));
						bet_stream >> bet_amount;
						if (bet_amount <= 2 && bet_amount > 0 && ((bet_amount + current_bet) <= ptr_vector[bet_index]->chips)) {
							current_bet += bet_amount;
						}
						else if ((bet_amount + current_bet) > ptr_vector[bet_index]->chips) {
							cout << "Invalid raise: You only have " << ptr_vector[bet_index]->chips << " chip(s) to bet" << endl;
							substring = "invalid";
						}
						else {
							cout << "Invalid raise: The maximum raise is 2 chips" << endl;
							substring = "invalid";
						}
					}
					else {
						cout << "Invalid raise: Raise must be 1 or 2 chips" << endl;
						substring = "invalid";
					}
				}
			}
		}
		bet_index = (bet_index + 1) % ptr_vector.size();
		bet_round++;
		cout << endl;
	}

	//Take bets from players not folded
	for (int i = 0; i < ptr_vector.size(); ++i) {
		if (ptr_vector[i]->fold == false) {
			if (current_bet <= ptr_vector[i]->chips) {
				ptr_vector[i]->chips = ptr_vector[i]->chips - current_bet;
				pot = pot + current_bet;
			}
			else {
				pot = pot + ptr_vector[i]->chips;
				ptr_vector[i]->chips = 0;
			}
		}
	}

	//Reset fold bools to false
	for (int i = 0; i < ptr_vector.size(); ++i) {
		ptr_vector[i]->fold = false;
	}
}
