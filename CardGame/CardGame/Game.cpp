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
#include "SevenCardStud.h"
#include "Deck.h"
#include "Parse.h"

#include <fstream>
#include <sstream>
#include <algorithm>
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
				if (game_string[i] == "FiveCardDraw" || game_string[i] == "fivecarddraw") {
					game_ptr = make_shared<FiveCardDraw>();
				}
				if (game_string[i] == "SevenCardStud" || game_string[i] == "sevencardstud") {
					game_ptr = make_shared<SevenCardStud>();
				}
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
	if (player_ptr->chips == 0) {
		chips_empty();
	}
	if (player_ptr->chips > 0) {
		if (player_ptr->computer) {
			cout << "Added: " << player_name << "\t(Computer)" << endl;
		}
		else {
			cout << "Added: " << player << "\tChips: " << player_ptr->chips << endl;
		}
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
	all_fold = false;
	cout << "Ante:" << endl;
	for (int i = 0; i < ptr_vector.size(); ++i) {
		cout << ante_amount << " chip(s) from " << ptr_vector[i]->name << endl;
		ptr_vector[i]->chips -= ante_amount;
		pot += ante_amount;
	}
	cout << "Pot: " << pot << endl;
}


void Game::chips_empty()
{
	for (size_t i = ptr_vector.size() - 1; i >= 0; --i) {
		if (ptr_vector[i]->chips == 0) {
			cout << ptr_vector[i]->name << ", you are out of chips." << endl;

			string input;
			bool buy = false;
			bool correct = false;
			while (input.length() != 1 || !correct) {
				cout << "Would you like to buy back in (Y/n)?" << endl;
				getline(cin, input);
				if (input.length() == 1) {
					if (input[0] == 'Y' || input[0] == 'y') {
						buy = true;
						correct = true;
					}
					if (input[0] == 'N' || input[0] == 'n') {
						buy = false;
						correct = true;
					}
				}
			}

			if (buy) {
				ptr_vector[i]->chips = 20;
			}
			else {
				remove_player(ptr_vector[i]->name);
			}
		}
	}
}

bool poker_rank_ptr(const shared_ptr<Player>&p1, const shared_ptr<Player>&p2)
{
	if (!p1) {
		return false;
	}
	if (!p2) {
		return true;
	}
	if (p1->fold) {
		return false;
	}
	if (p2->fold) {
		return true;
	}
	return poker_rank(p1->hand, p2->hand);
}
