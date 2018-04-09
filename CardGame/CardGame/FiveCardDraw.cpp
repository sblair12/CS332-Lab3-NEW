// FiveCardDraw.cpp
//
// Authors: 
// Shane Blair	sblair@wustl.edu
// Steven Lee	lee.steven@wustl.edu
//
// April 6, 2018
//
// Purpose- Declarations for the FiveCardDraw class derived from "Game" publically

#include "stdafx.h"
#include "FiveCardDraw.h"
#include "Card.h"
#include "Parse.h"
#include "Hand.h"

#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

const int max_discard = 5;
const int min_discard = 0;
const string invalid_string = "*STRINGINVALID*";

FiveCardDraw::FiveCardDraw()
{
	dealer_index = 0;
	draw_deck = Deck();
	discard_deck = Deck();
	for (int card_rank = TWO; card_rank <= ACE; ++card_rank) {
		for (int card_suit = CLUBS; card_suit <= SPADES; ++card_suit) {
			Card card;
			card.rank = (Rank)card_rank;
			card.suit = (Suit)card_suit;
			draw_deck.add_card(card);
		}
	}
}

void FiveCardDraw::remove_cards(vector<size_t> &to_remove, Player &player)
{
	sort(to_remove.begin(), to_remove.end());
	cout << "Discarding ";
	for (size_t i = to_remove.size() - 1; i >= 0 && i < to_remove.size(); --i) {
		Card card = player.hand.remove_card(to_remove[i]);
		cout << card << " ";
		discard_deck.add_card(card);
	}
	cout << endl;
}

int FiveCardDraw::before_turn(Player &player)
{
	cout << endl;
	cout << endl;
	cout << player.name << "\t" << player.hand << endl;
	cout << endl;
	cout << endl;
	cout << "How many cards to discard?" << endl;
	string input;
	int number_discarded;

	//Get number of cards to discard
	while (input.length() != 1 || number_discarded > max_discard || number_discarded < min_discard) {
		cout << "Please give a VALID number of cards to discard, from 0 to 5" << endl;
		getline(cin, input);
		if (input.length() == 1) {
			istringstream iss(input);
			iss >> number_discarded;
		}
	}

	cout << endl;
	const int valid_string_length = 2 * number_discarded - 1;
	size_t number;
	input = invalid_string;


	//Discard those cards from the Player hand
	if (number_discarded < max_discard && number_discarded > 0) {
		if (number_discarded == 1) {
			cout << "What card to discard? (indices 1-5)" << endl;
		}
		else {
			cout << "Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)" << endl;
		}
		while (input.length() != valid_string_length) {
			number = 1000;
			vector<size_t> to_remove;
			cout << "Please give valid card indices, from 1 to 5" << endl;
			getline(cin, input);
			if (input.length() == valid_string_length) {
				istringstream iss_2(input);
				int i;
				for (i = 0; iss_2 >> number; ++i) {
					if (number > max_discard || number < min_discard + 1) {
						cout << "Invalid index: " << number << endl;
						input = invalid_string;
						break;
					}
					else {
						for (int j = 0; j < to_remove.size(); ++j) {
							if (number - 1 == to_remove[j]) {
								cout << "Invalid index: " << number << endl;
								input = invalid_string;
								break;
							}
						}
						to_remove.push_back(number - 1);
					}
				}
				if (number == 1000 || i != number_discarded) {
					cout << "Invalid index value" << endl;
					input = invalid_string;
				}
				if (input.length() == valid_string_length && to_remove.size() > 0) {
					remove_cards(to_remove, player);
				}
			}
		}
	}

	//Discard ALL cards
	else if (number_discarded == max_discard) {
		cout << "Discarding all cards" << endl;
		vector<size_t> to_remove = { 0,1,2,3,4 };
		remove_cards(to_remove, player);
	}

	//Discard NO cards
	else {
		cout << "No cards will be discarded" << endl;
	}
	return 0;
}

int FiveCardDraw::turn(Player &player)
{
	for (int i = player.hand.size(); i < max_discard; ++i) {
		if (draw_deck.size() == 0) {
			if (discard_deck.size() == 0) {
				cout << "No more cards in the deck" << endl;
				int i = deck_out_of_cards;
				throw i;
			}
			discard_deck.shuffle();
			swap(draw_deck, discard_deck);
		}
		player.hand << draw_deck;
	}
	return 0;
}

int FiveCardDraw::after_turn(Player &player)
{
	cout << player.name << "\t" << player.hand << endl;
	cout << endl;
	return 0;
}

int FiveCardDraw::before_round()
{
	draw_deck.shuffle();
	int card_count = 0;
	size_t index = (dealer_index + 1) % ptr_vector.size();
	while (card_count < 5) {
		if (draw_deck.size() == 0) {
			cout << "No more cards in the deck" << endl;
			int i = deck_out_of_cards;
			throw i;
		}
		ptr_vector[index]->hand << draw_deck;
		index = (index + 1) % ptr_vector.size();
		if (index == (dealer_index + 1) % ptr_vector.size()) {
			++card_count;
		}
	}

	for (size_t i = 0; i < ptr_vector.size(); ++i) {
		try {
			before_turn(*ptr_vector[index].get());
			index = (index + 1) % ptr_vector.size();
		}
		catch (int i) {
			throw i;
		}
	}
	return 0;
}

int FiveCardDraw::round()
{
	size_t index = (dealer_index + 1) % ptr_vector.size();
	for (size_t i = 0; i < ptr_vector.size(); ++i) {
		try {
			turn(*ptr_vector[index].get());
			index = (index + 1) % ptr_vector.size();
		}
		catch (int i) {
			throw i;
		}
	}
	cout << endl;
	cout << endl;
	for (size_t i = 0; i < ptr_vector.size(); ++i) {
		try {
			after_turn(*ptr_vector[index].get());
			index = (index + 1) % ptr_vector.size();
		}
		catch (int i) {
			throw i;
		}
	}
	return 0;
}

int FiveCardDraw::after_round()
{
	print_rankings();

	//Take cards from hands and throw them into the draw deck
	for (int i = 0; i < ptr_vector.size(); ++i) {
		for (int index = ptr_vector[i]->hand.size() - 1; index >= 0 && index < ptr_vector[i]->hand.size(); --index) {
			Card card = ptr_vector[i]->hand.remove_card(index);
			draw_deck.add_card(card);
		}
	}

	//Take cards from discard deck and throw them into the draw deck
	draw_deck.deck.insert(draw_deck.deck.end(), discard_deck.deck.begin(), discard_deck.deck.end());
	discard_deck = Deck();

	try {
		players_leave();
		players_join();
	}
	catch (int i) {
		throw i;
	}

	dealer_index = (dealer_index + 1) % ptr_vector.size();
	return 0;
}

void FiveCardDraw::print_rankings()
{
	for (int i = 0; i < ptr_vector.size(); ++i) {
		rankHand(ptr_vector[i]->hand);
	}
	vector<shared_ptr<Player>> ptr_temp = ptr_vector;
	sort(ptr_temp.begin(), ptr_temp.end(), poker_rank_ptr);
	ptr_temp[0]->wins++;
	cout << ptr_temp[0]->name << "\t" << "Wins: " << ptr_temp[0]->wins << " Losses: " << ptr_temp[0]->losses << endl;
	cout << ptr_temp[0]->hand << "\t" << poker_text[ptr_temp[0]->hand.get_poker()] << endl;

	for (int i = 1; i < ptr_temp.size(); ++i) {
		ptr_temp[i]->losses++;
		cout << ptr_temp[i]->name << "\t" << "Wins: " << ptr_temp[i]->wins << " Losses: " << ptr_temp[i]->losses << endl;
		cout << ptr_temp[i]->hand << "\t" << poker_text[ptr_temp[i]->hand.get_poker()] << endl;
	}
}

void FiveCardDraw::players_leave()
{
	string input;
	bool leave = false;
	bool correct = false;
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
	}
}

void FiveCardDraw::players_join()
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
				try{
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

bool poker_rank_ptr(const shared_ptr<Player>&p1, const shared_ptr<Player>&p2)
{
	if (!p1) {
		return false;
	}
	if (!p2) {
		return true;
	}
	return poker_rank(p1->hand, p2->hand);
}