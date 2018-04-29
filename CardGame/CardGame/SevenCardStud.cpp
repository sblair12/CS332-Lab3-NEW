// SevenCardStud.cpp
//
// Authors: 
// Shane Blair	sblair@wustl.edu
// Steven Lee	lee.steven@wustl.edu
//
// April 28, 2018
//
// Purpose- Declarations for the SevenCardStud class derived from "Game" publically

#include "stdafx.h"
#include "SevenCardStud.h"
#include "Parse.h"

#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

const unsigned int first_deal = 3;
const unsigned int middle_deal = 1;
vector<bool> faceup_cards = { false, false, true, true, true, true, false };

SevenCardStud::SevenCardStud()
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

void SevenCardStud::bet()
{
	size_t bet_index = (dealer_index + 1) % ptr_vector.size();
	unsigned int bet_round = 0;
	unsigned int current_bet = 0;

	while (bet_round < ptr_vector.size()) {
		string input;
		string substring = "invalid";
		unsigned int bet_amount = 0;
		unsigned int correct_length;
		
		for (int i = 0; i < ptr_vector.size(); ++i) {
			if (i != bet_index) {
				cout << ptr_vector[i]->name << "\t" << ptr_vector[i]->hand.as_string(faceup_cards) << endl;
			}
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

void SevenCardStud::print_rankings()
{
	for (int i = 0; i < ptr_vector.size(); ++i) {
		Hand pointer = ptr_vector[i]->hand;
		Hand ranked = pointer;
		Hand holder = ranked;
		Hand temp = ranked;
		int max_hash = 0;
		int max_poker = 0;

		do {
			next_permutation(ranked.hand.begin(), ranked.hand.end());
			vector<Card> to_rank(ranked.hand.begin(), ranked.hand.begin() + 5);
			sort(to_rank.begin(), to_rank.end());
			holder.hand = to_rank;
			rankHand(holder);
			if (holder.hash > max_hash) {
				max_hash = holder.get_ranking();
				max_poker = holder.get_poker();
			}
		} while (ranked != temp);
		ptr_vector[i]->hand.set_poker(max_poker);
		ptr_vector[i]->hand.set_ranking(max_hash);
		cout << ptr_vector[i]->name << " Max rank: " << max_hash << endl;
		rankHand(ptr_vector[i]->hand);
	}
	vector<shared_ptr<Player>> ptr_temp = ptr_vector;
	sort(ptr_temp.begin(), ptr_temp.end(), poker_rank_ptr);
	ptr_temp[0]->wins++;
	ptr_temp[0]->chips += pot;
	if (ptr_temp[0]->computer) {
		cout << ptr_temp[0]->name << "\t(Computer)";
		ptr_temp[0]->position = 2;
	}
	else {
		cout << ptr_temp[0]->name;
	}
	cout << "\t won " << pot << " chips!" << endl;
	cout << "Wins:\t" << ptr_temp[0]->wins << "\tLosses: " << ptr_temp[0]->losses << "\tChips: " << ptr_temp[0]->chips << endl;
	cout << ptr_temp[0]->hand << "\t" << poker_text[ptr_temp[0]->hand.get_poker()] << endl;

	for (int i = 1; i < ptr_temp.size(); ++i) {
		if (i == ptr_temp.size() - 1) {
			ptr_temp[i]->position = 0;
		}
		cout << endl;
		ptr_temp[i]->losses++;
		if (ptr_temp[i]->computer) {
			cout << ptr_temp[i]->name << "\t(Computer)" << endl;
		}
		else {
			cout << ptr_temp[i]->name << endl;
		}
		cout << "Wins:\t" << ptr_temp[i]->wins << "\tLosses: " << ptr_temp[i]->losses << "\tChips: " << ptr_temp[i]->chips << endl;
		if (ptr_temp[i]->fold == false) {
			cout << ptr_temp[i]->hand << "\t" << poker_text[ptr_temp[i]->hand.get_poker()] << endl;
		}
		else {
			cout << "FOLD" << endl;
		}
	}
	//Reset fold bools to false
	for (int i = 0; i < ptr_vector.size(); ++i) {
		ptr_vector[i]->fold = false;
	}
}

int SevenCardStud::before_round()
{
	ante();
	draw_deck.shuffle();
	return 0;
}

int SevenCardStud::round()
{
	int card_count = 0;
	size_t index = (dealer_index + 1) % ptr_vector.size();

	//First turn (deal 3 cards)
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

	cout << endl;
	bet();
	index = (dealer_index + 1) % ptr_vector.size();
	card_count = 0;

	//Second, third, fourth, and fifth turns (deal one card each)
	for (unsigned int turn = 2; turn <= 5; turn++) {
		int card_count = 0;
		while (card_count < middle_deal) {
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
	}
	return 0;
}

int SevenCardStud::after_round()
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

	//Take cards from discard deck and throw them into the draw deck
	draw_deck.deck.insert(draw_deck.deck.end(), discard_deck.deck.begin(), discard_deck.deck.end());
	discard_deck = Deck();

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
