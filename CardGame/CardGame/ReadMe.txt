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

9. {
"CardGame fivecarddraw steven shane joel dan"
Produced:
		Added: steven to the game
		Added: shane to the game
		Added: joel to the game
		Added: dan to the game


		shane   7D      7H      JC      AC      AD


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		1

		What card to discard? (indices 1-5)
		Please give valid card indices, from 1 to 5
		3
		Discarding JC


		joel    4H      6S      7C      8D      KC


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding KC 8D 7C 6S 4H


		dan     4C      4D      4S      10H     QH


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		0

		No cards will be discarded


		steven  2H      3S      5S      9H      QC


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		2

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		4 5
		Discarding QC 9H


		shane   7D      7H      AC      AD      AH

		joel    3C      5C      8C      10D     KD

		dan     4C      4D      4S      10H     QH

		steven  2H      3S      5S      JS      QS

		shane   Wins: 1 Losses: 0
		7D      7H      AC      AD      AH              Full House
		dan     Wins: 0 Losses: 1
		4C      4D      4S      10H     QH              Three of a Kind
		joel    Wins: 0 Losses: 1
		3C      5C      8C      10D     KD              High Card
		steven  Wins: 0 Losses: 1
		2H      3S      5S      JS      QS              High Card
		Does any Player want to leave? (Y/n)
		y
		Which Players would like to leave? (separate names with spaces, ex: joe bob bill
		ybob)
		dan
		Finding: dan
		Bye dan!


		joel    2C      3S      5H      7D      10S


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		2

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		4 5
		Discarding 10S 7D


		steven  3H      7S      9D      JD      QD


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding QD JD 9D 7S 3H


		shane   6C      8C      QC      KC      KH


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		0

		No cards will be discarded


		joel    2C      3S      5H      6S      10H

		steven  2D      5D      5S      8D      10D

		shane   6C      8C      QC      KC      KH

		shane   Wins: 2 Losses: 0
		6C      8C      QC      KC      KH              One Pair
		steven  Wins: 0 Losses: 2
		2D      5D      5S      8D      10D             One Pair
		joel    Wins: 0 Losses: 2
		2C      3S      5H      6S      10H             High Card
		Does any Player want to leave? (Y/n)
		y
		Which Players would like to leave? (separate names with spaces, ex: joe bob bill
		ybob)
		joel
		Finding: joel
		Bye joel!


		shane   2D      3C      4D      8D      9S


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		3

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		3
		Please give valid card indices, from 1 to 5
		3 1 4
		Discarding 8D 4D 2D


		steven  4C      5S      8H      JC      QD


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		4

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		5 4 2 1
		Discarding QD JC 5S 4C


		shane   3C      4S      7S      9S      10C

		steven  6H      7H      8H      9C      KD

		steven  Wins: 1 Losses: 2
		6H      7H      8H      9C      KD              High Card
		shane   Wins: 2 Losses: 1
		3C      4S      7S      9S      10C             High Card
		Does any Player want to leave? (Y/n)
		y
		Which Players would like to leave? (separate names with spaces, ex: joe bob bill
		ybob)
		steven
		Finding: steven
		Bye steven!
}

10. {
"CardGame fivecarddraw shane steve joel dan"
Produced: 
		Added: shane to the game
		Added: steve to the game
		Added: joel to the game
		Added: dan to the game


		steve   4S      6D      9S      QH      AH


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding AH QH 9S 6D 4S


		joel    2H      3D      7S      10C     JS


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding JS 10C 7S 3D 2H


		dan     3S      9D      QC      QS      KH


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding KH QS QC 9D 3S


		shane   3H      5D      7D      9C      AD


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding AD 9C 7D 5D 3H


		steve   5S      6C      QD      KD      AS

		joel    2D      3C      4C      5C      10H

		dan     5H      6H      7C      7H      8H

		shane   4H      8S      10D     10S     JC

		shane   Wins: 1 Losses: 0
		4H      8S      10D     10S     JC              One Pair
		dan     Wins: 0 Losses: 1
		5H      6H      7C      7H      8H              One Pair
		steve   Wins: 0 Losses: 1
		5S      6C      QD      KD      AS              High Card
		joel    Wins: 0 Losses: 1
		2D      3C      4C      5C      10H             High Card
		Does any Player want to leave? (Y/n)
		y
		Which Players would like to leave? (separate names with spaces, ex: joe bob bill
		ybob)
		shane bob
		Finding: shane
		Bye shane!
		Finding: bob
		Invalid name: bob


		dan     4C      6D      9H      JH      KS


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding KS JH 9H 6D 4C


		steve   3H      6H      JC      JD      KC


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding KC JD JC 6H 3H


		joel    2S      4H      QC      KH      AH


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding AH KH QC 4H 2S


		dan     3C      4D      5H      10S     QS

		steve   6S      9D      10D     JS      AC

		joel    7C      8D      9C      10C     KD

		steve   Wins: 1 Losses: 1
		6S      9D      10D     JS      AC              High Card
		joel    Wins: 0 Losses: 2
		7C      8D      9C      10C     KD              High Card
		dan     Wins: 0 Losses: 2
		3C      4D      5H      10S     QS              High Card
		Does any Player want to leave? (Y/n)
		yes
		Does any Player want to leave? (Y/n)
		dan shane
		Does any Player want to leave? (Y/n)
		y
		Which Players would like to leave? (separate names with spaces, ex: joe bob bill
		ybob)
		dan shane
		Finding: dan
		Bye dan!
		Finding: shane
		Invalid name: shane


		joel    3H      10C     10S     QC      QS


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding QS QC 10S 10C 3H


		steve   3C      3S      5C      5D      7H


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding 7H 5D 5C 3S 3C


		joel    4H      6D      8S      10D     JS

		steve   2C      4D      7C      10H     KH

		steve   Wins: 2 Losses: 1
		2C      4D      7C      10H     KH              High Card
		joel    Wins: 0 Losses: 3
		4H      6D      8S      10D     JS              High Card
		Does any Player want to leave? (Y/n)
		y
		Which Players would like to leave? (separate names with spaces, ex: joe bob bill
		ybob)
		joel
		Finding: joel
		Bye joel!
}