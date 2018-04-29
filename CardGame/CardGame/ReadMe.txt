// Shane Blair	- sblair@wustl.edu		-	448740
// Steven Lee	- lee.steven@wustl.edu	-	448180

// Lab 4: Multiple Card Games

For this lab, we implemented a program to:
	- play a game called Five Card Draw as instructed
	- play another game called Seven Card Stud as instructed

For method functions see comments in source files

NOTE:	Selections require space separated items, without an extra space at the end, for input to be valid.
		If too many or too few items are given, the program will ask for the selections to be input again.
		This is the intended functionality.

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

"Cardgame"
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
	Playing: fivecarddraw
	Added: shane    Chips: 20
	shane is already playing
	Exception caught: 13
}

6. {

"Cardgame fivecarddraw shane steven joel shane"
Produced:
	Playing: fivecarddraw
	Added: shane    Chips: 20
	Added: steven   Chips: 20
	Added: joel     Chips: 20
	shane is already playing
	Exception caught: 13
}

7. {

"Cardgame fivecarddraw steven joel shane dan billy bob mao trump obama michelle sasha"
Produced:
	Playing: fivecarddraw
	Added: steven   Chips: 20
	Added: joel     Chips: 20
	Added: shane    Chips: 20
	Added: dan      Chips: 20
	Added: billy    Chips: 20
	Added: bob      Chips: 20
	Added: mao      Chips: 20
	Added: trump    Chips: 20
	Added: obama    Chips: 20
	Added: michelle Chips: 20
	Added: sasha    Chips: 20

	Ante:
	1 chip(s) from steven
	1 chip(s) from joel
	1 chip(s) from shane
	1 chip(s) from dan
	1 chip(s) from billy
	1 chip(s) from bob
	1 chip(s) from mao
	1 chip(s) from trump
	1 chip(s) from obama
	1 chip(s) from michelle
	1 chip(s) from sasha
	Pot: 11
	No more cards in the deck
	Exception caught: 14
}

8. {

}

