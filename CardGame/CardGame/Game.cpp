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
using namespace std;

const vector<string> game_string = { "FiveCardDraw", "fivecarddraw" };

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
	ptr_vector.push_back(make_shared<Player>(player_name));
	cout << "Added: " << player << " to the game" << endl;
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
