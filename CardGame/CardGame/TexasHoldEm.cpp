// TexasHoldEm.cpp
//
// Authors: 
// Shane Blair	sblair@wustl.edu
// Steven Lee	lee.steven@wustl.edu
//
// April 28, 2018
//
// Purpose- Declarations for the TexasHoldEm class derived from "Game" publically

#include "stdafx.h"
#include "TexasHoldEm.h"
#include "Parse.h"

#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

const unsigned int first_deal = 2;
const unsigned int second_deal = 3;

TexasHoldEm::TexasHoldEm()
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

void TexasHoldEm::bet()
{
	size_t bet_index = (dealer_index + 1) % ptr_vector.size();
	unsigned int bet_round = 0;
	unsigned int current_bet = 0;

	while (bet_round < ptr_vector.size()) {
		string input;
		string substring = "invalid";
		unsigned int bet_amount = 0;
		unsigned int correct_length;

		for (int i = 0; i < shared_cards.size(); ++i) {
			cout << shared_cards[i] << "\t";
		}
		cout << endl;
		cout << ptr_vector[bet_index]->name << "\t" << ptr_vector[bet_index]->hand << endl;
		cout << "Chips: " << ptr_vector[bet_index]->chips << "\t";

		if (ptr_vector[bet_index]->fold == false && ptr_vector[bet_index]->chips > 0) {
			while (substring != "check" && substring != "bet" && substring != "fold" && substring != "raise" && substring != "call") {
				if (current_bet == 0) {
					cout << endl;
					cout << endl;
					cout << "Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)" << endl;
					getline(cin, input);
					if (input == "check") {
						substring = input;
					}
					if (input.substr(0, 3) == "bet") {
						correct_length = 5;
						substring = "bet";
						if (input.length() == 5) {
							istringstream bet_stream(input.substr(4, 5));
							bet_stream >> bet_amount;
							if (bet_amount <= 2 && bet_amount > 0 && bet_amount <= ptr_vector[bet_index]->chips) {
								current_bet = bet_amount;
								ptr_vector[bet_index]->bet = current_bet;
								bet_round = 0;
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
					cout << endl;
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
						if (input.length() == 7) {
							istringstream bet_stream(input.substr(6, 7));
							bet_stream >> bet_amount;
							if (bet_amount <= 2 && bet_amount > 0 && ((bet_amount + current_bet) <= ptr_vector[bet_index]->chips)) {
								current_bet += bet_amount;
								ptr_vector[bet_index]->bet = current_bet;
								bet_round = 0;
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
		}
		else if (ptr_vector[bet_index]->chips == 0) {
			cout << endl;
			cout << "Already all in" << endl;
		}
		else {
			cout << endl;
			cout << "Folded" << endl;
		}
		bet_index = (bet_index + 1) % ptr_vector.size();
		bet_round++;
		cout << endl;
	}

	//Take bets from players not folded
	for (int i = 0; i < ptr_vector.size(); ++i) {
		if (ptr_vector[i]->fold == false) {
			if (current_bet <= ptr_vector[i]->chips) {
				ptr_vector[i]->chips -= current_bet;
				pot += current_bet;
			}
			else {
				pot += ptr_vector[i]->chips;
				ptr_vector[i]->chips = 0;
			}
		}
		else {
			pot += ptr_vector[i]->bet;
			ptr_vector[i]->chips -= ptr_vector[i]->bet;
		}
		ptr_vector[i]->bet = 0;
	}
	cout << "Pot: " << pot << endl;
}

void TexasHoldEm::print_rankings()
{
}

int TexasHoldEm::before_round()
{
	ante();
	draw_deck.shuffle();
	return 0;
}

int TexasHoldEm::round()
{
	int card_count = 0;
	size_t index = (dealer_index + 1) % ptr_vector.size();

	//First turn (deal 2 cards to players)
	while (card_count < first_deal) {
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

	bet();
	card_count = 0;

	//Second turn (The "Flop", deal 3 cards to the middle)
	while (card_count < second_deal) {
		if (draw_deck.size() == 0) {
			cout << "No more cards in the deck" << endl;
			int i = deck_out_of_cards;
			throw i;
		}
		shared_cards.push_back(draw_deck.deck.back());
		draw_deck.deck.pop_back();
		++card_count;
	}

	bet();

	//Third and fourth turns (The "Turn" and the "River", one card each to the middle)
	for (int turn = 3; turn <= 4; turn++) {
		if (draw_deck.size() == 0) {
			cout << "No more cards in the deck" << endl;
			int i = deck_out_of_cards;
			throw i;
		}
		shared_cards.push_back(draw_deck.deck.back());
		draw_deck.deck.pop_back();
		++card_count;

		bet();
	}


	return 0;
}

int TexasHoldEm::after_round()
{
	cout << endl;
	print_rankings();

	//Take cards from hands and throw them into the draw deck
	for (int i = 0; i < ptr_vector.size(); ++i) {
		for (int index = ptr_vector[i]->hand.size() - 1; index >= 0 && index < ptr_vector[i]->hand.size(); --index) {
			Card card = ptr_vector[i]->hand.remove_card(index);
			draw_deck.add_card(card);
		}
	}

	//Take cards from the shared vector and throw them into the draw deck
	draw_deck.deck.insert(draw_deck.deck.end(), shared_cards.begin(), shared_cards.end());
	shared_cards.clear();

	cout << endl;
	cout << endl;

	chips_empty();

	try {
		players_leave();
		players_join();
	}
	catch (int i) {
		throw i;
	}

	if (ptr_vector.size() != 0) {
		dealer_index = (dealer_index + 1) % ptr_vector.size();
	}
	return 0;
}
