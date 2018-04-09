// Shane Blair	- sblair@wustl.edu		-	448740
// Steven Lee	- lee.steven@wustl.edu	-	448180
//	ID: 	  448740 
//	WUSTLKey: sblair
// Lab 2: Card Decks and Hands

For this lab, I implemented a program to:
	- Take in a deck of card strings
	- Deal valid cards from the deck to hands
	- Evaluate the hands lexically and by Poker ranking

For method functions see comments in source files

Error Codes:
	0 - No runtime errors
	1 - Incorrect number of arguments
	2 - Input file cannot be opened
	3 - No valid hands in input file
	4 - Shuffle parameter given without a deck
	5 - Two parameters but no shuffle parameter
	6 - Two shuffle parameters
	7 - The deck ran out of cards before dealing the desired number to each hand
	8 - The index was out of bounds
	9 - Instance has not been created yet so cannot be pulled
	10 - Game has already started
	11 - Game entered was not in set 
	12 - There is no game in progress
	13 - Player is already playing/in the game
	14 - No more Cards available in Deck
	   -1 - Unexpected error


Build is successful; no errors or warnings reported

COMMAND LINE Trials: 

1. {

"CardGame"
Produces: 
		Usage: cardgame <game_name> <player1> <player2> ...
				Run this program with one argument for a game name and 2 or more arguments for player names
				(ex: cardgame fivecarddraw billybob Mao)
}

2. {

"CardGame" fivecarddraw
Produces:
		Usage: cardgame <game_name> <player1> <player2> ...
				Run this program with one argument for a game name and 2 or more arguments for player names
                (ex: cardgame fivecarddraw billybob Mao)

}

3. {

"CardGame" fivecarddraw Shane
Produces:
		Usage: CardGame <game_name> <player1> <player2> ...
                Run this program with one argument for a game name and 2 or more arguments for player names
                (ex: CardGame fivecarddraw billybob Mao)
}