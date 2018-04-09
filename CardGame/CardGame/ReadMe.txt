// Shane Blair	- sblair@wustl.edu		-	448740
// Steven Lee	- lee.steven@wustl.edu	-	448180
//	ID: 	  448740 
//	WUSTLKey: sblair
// Lab 2: Card Decks and Hands

For this lab, I implemented a program to:
	- play a game called Five Card Draw

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

"CardGame fivecarddraw"
Produces:
		Usage: cardgame <game_name> <player1> <player2> ...
				Run this program with one argument for a game name and 2 or more arguments for player names
                (ex: cardgame fivecarddraw billybob Mao)

}

3. {

"CardGame fivecarddraw Shane"
Produces:
		Usage: CardGame <game_name> <player1> <player2> ...
                Run this program with one argument for a game name and 2 or more arguments for player names
                (ex: CardGame fivecarddraw billybob Mao)
}

4. {

"CardGame poker shane steven"
Produces:
		Unknown game type: poker
		Exception caught: 11
}

5. {

"CardGame fivecarddraw shane shane"
Produced:
		Added: shane to the game
		shane is already playing
		Exception caught: 13
}

6. {

"CardGame fivecarddraw shane steven joel shane"
Produced:
		Added: shane to the game
		Added: steven to the game
		Added: joel to the game
		shane is already playing
		Exception caught: 13
}

7. {

"CardGame shane steven joel dan fr soel jao josh t dannn throww"
Produces:
		Added: shane to the game
		Added: steven to the game
		Added: joel to the game
		Added: dan to the game
		Added: fr to the game
		Added: soel to the game
		Added: jao to the game
		Added: josh to the game
		Added: t to the game
		Added: dannn to the game
		Added: throww to the game
		No more cards in the deck
		Exception caught: 14
}

8. {

"CardGame fivecarddraw steven shane"
Produced:
		Added: steven to the game
		Added: shane to the game


		shane   2H      5C      10C     JC      JH


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		2

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		1 1
		Invalid index: 1
		Please give valid card indices, from 1 to 5
		...
}
