// Game.h
//
// Authors: 
// Shane Blair	sblair@wustl.edu
// Steven Lee	lee.steven@wustl.edu
//
// April 6, 2018
//
// Purpose- Definitions for a "Game" abstract base class
#pragma once
#include "Deck.h"
#include "Player.h"

#include <vector>
#include <memory>
using namespace std;

class Game {
public:
	static shared_ptr<Game> instance();
	static void start_game(const string game);
	static void stop_game();
	void add_player(const string player);
	shared_ptr<Player> find_player(const string player);
	void remove_player(const string name);
	shared_ptr<Player> last_player();
	size_t player_size();
	void players_leave();
	//Ask players if they want to join
	void players_join();
	void ante();
	void bet();

	//Pure virtual methods
	virtual int before_turn(Player &) = 0;
	virtual int turn(Player &) = 0;
	virtual int after_turn(Player &) = 0;
	virtual int before_round() = 0;
	virtual int round() = 0;
	virtual int after_round() = 0;
protected:
	size_t dealer_index;
	static shared_ptr<Game> game_ptr;
	Deck draw_deck;
	vector<shared_ptr<Player>> ptr_vector;
	unsigned int pot = 0;
};