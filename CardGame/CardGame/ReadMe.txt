// Shane Blair	- sblair@wustl.edu		-	448740
// Steven Lee	- lee.steven@wustl.edu	-	448180

// Lab 3: Five Card Draw

For this lab, we implemented a program to:
	- play a game called Five Card Draw as instructed

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
Error Code: 11

5. {

"CardGame fivecarddraw shane shane"
Produced:
		Added: shane to the game
		shane is already playing
		Exception caught: 13
}
Error Code: 13

6. {

"CardGame fivecarddraw shane steven joel shane"
Produced:
		Added: shane to the game
		Added: steven to the game
		Added: joel to the game
		shane is already playing
		Exception caught: 13
}
Error Code: 13

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
"CardGame fivecarddraw shane steven joel dan"
Produced:
		Added: shane to the game
		Added: steven to the game
		Added: joel to the game
		Added: dan to the game


		steven  2S      4H      5C      9S      KH


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding KH 9S 5C 4H 2S


		joel    4S      5H      8S      10H     KD


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding KD 10H 8S 5H 4S


		dan     3H      5D      8D      JS      AS


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding AS JS 8D 5D 3H


		shane   2C      2H      3C      KC      AC


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding AC KC 3C 2H 2C


		steven  4D      6D      9H      QD      AD

		joel    3S      4C      8C      JC      KS

		dan     3D      6C      8H      JH      QH

		shane   7C      7H      7S      JD      AH

		shane   Wins: 1 Losses: 0
		7C      7H      7S      JD      AH              Three of a Kind
		steven  Wins: 0 Losses: 1
		4D      6D      9H      QD      AD              High Card
		joel    Wins: 0 Losses: 1
		3S      4C      8C      JC      KS              High Card
		dan     Wins: 0 Losses: 1
		3D      6C      8H      JH      QH              High Card
		Does any Player want to leave? (Y/n)
		y
		Which Players would like to leave? (separate names with spaces, ex: joe bob bill
		ybob)
		dan
		Finding: dan
		Bye dan!
		Do any new Players want to join? (Y/n)
		y
		Which Players would like to join? (separate names with spaces, ex: mao dan steve
		bob)
		dani
		Adding: dani
		Added: dani to the game
		Hi dani!


		joel    3C      6D      6S      7D      8C


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding 8C 7D 6S 6D 3C


		dani    4C      4S      7H      AD      AH


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding AH AD 7H 4S 4C


		shane   3H      7S      10D     QH      AC


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding AC QH 10D 7S 3H


		steven  2C      4H      6H      8H      QC


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding QC 8H 6H 4H 2C


		joel    5H      9H      JH      QS      KC

		dani    2H      2S      5C      7C      10S

		shane   3S      9S      10C     JC      JS

		steven  5D      8S      10H     QD      KH

		shane   Wins: 2 Losses: 0
		3S      9S      10C     JC      JS              One Pair
		dani    Wins: 0 Losses: 1
		2H      2S      5C      7C      10S             One Pair
		steven  Wins: 0 Losses: 2
		5D      8S      10H     QD      KH              High Card
		joel    Wins: 0 Losses: 2
		5H      9H      JH      QS      KC              High Card
		Does any Player want to leave? (Y/n)
		y
		Which Players would like to leave? (separate names with spaces, ex: joe bob bill
		ybob)
		shane steven joel
		Finding: shane
		Bye shane!
		Finding: steven
		Bye steven!
		Finding: joel
		Bye joel!
		Do any new Players want to join? (Y/n)
		y
		Which Players would like to join? (separate names with spaces, ex: mao dan steve
		bob)
		shana
		Adding: shana
		Added: shana to the game
		Hi shana!


		shana   5S      7S      8D      8S      10H


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding 10H 8S 8D 7S 5S


		dani    2H      5D      7H      QD      KH


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding KH QD 7H 5D 2H


		shana   4C      8C      JH      JS      KD

		dani    3H      4S      7C      9H      JC

		shana   Wins: 1 Losses: 0
		4C      8C      JH      JS      KD              One Pair
		dani    Wins: 0 Losses: 2
		3H      4S      7C      9H      JC              High Card
		Does any Player want to leave? (Y/n)
		y
		Which Players would like to leave? (separate names with spaces, ex: joe bob bill
		ybob)
		shana
		Finding: shana
		Bye shana!
		Do any new Players want to join? (Y/n)
		n
}

10. {
"CardGame fivecarddraw steven shane joel christian"
		Added: steven to the game
		Added: shane to the game
		Added: joel to the game
		Added: christian to the game


		shane   5S      7C      9D      10D     AS


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		2

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		3 4
		Discarding 10D 9D


		joel    2D      7H      8D      JC      QH


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		1

		What card to discard? (indices 1-5)
		Please give valid card indices, from 1 to 5
		3
		Discarding 8D


		christian       3H      5D      6S      8C      KH


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding KH 8C 6S 5D 3H


		steven  3C      4S      8H      10C     AC


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		0

		No cards will be discarded


		shane   2H      5S      7C      8S      AS

		joel    2D      6C      7H      JC      QH

		christian       2S      3D      4H      5C      QD

		steven  3C      4S      8H      10C     AC

		shane   Wins: 3 Losses: 0
		2H      5S      7C      8S      AS              High Card
		steven  Wins: 0 Losses: 3
		3C      4S      8H      10C     AC              High Card
		joel    Wins: 0 Losses: 3
		2D      6C      7H      JC      QH              High Card
		christian       Wins: 0 Losses: 1
		2S      3D      4H      5C      QD              High Card
		Does any Player want to leave? (Y/n)
		n^C
		C:\Users\lee.steven\Source\Repos\CS332-Lab3-NEW\CardGame\x64\Debug>cardgame five
		carddraw shane steven joel christian
		Added: shane to the game
		Added: steven to the game
		Added: joel to the game
		Added: christian to the game


		steven  3D      7H      8D      9D      QS


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding QS 9D 8D 7H 3D


		joel    3C      4H      7C      8C      JH


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		1

		What card to discard? (indices 1-5)
		Please give valid card indices, from 1 to 5
		3
		Discarding 7C


		christian       2C      4D      7D      10C     AH


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		2

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		5 2 3
		Please give valid card indices, from 1 to 5
		5 2 3
		Please give valid card indices, from 1 to 5
		5 2
		Discarding AH 4D


		shane   3H      JS      QH      KC      KD


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		4

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		1 3 4 5
		Discarding KD KC QH 3H


		steven  3S      4C      9C      9S      KH

		joel    3C      4H      8C      JH      AS

		christian       2C      7D      7S      10C     QD

		shane   2S      6H      6S      10S     JS

		steven  Wins: 1 Losses: 0
		3S      4C      9C      9S      KH              One Pair
		christian       Wins: 0 Losses: 1
		2C      7D      7S      10C     QD              One Pair
		shane   Wins: 0 Losses: 1
		2S      6H      6S      10S     JS              One Pair
		joel    Wins: 0 Losses: 1
		3C      4H      8C      JH      AS              High Card
		Does any Player want to leave? (Y/n)
		y
		Which Players would like to leave? (separate names with spaces, ex: joe bob bill
		ybob)
		christian shane steven
		Finding: christian
		Bye christian!
		Finding: shane
		Bye shane!
		Finding: steven
		Bye steven!
		Do any new Players want to join? (Y/n)
		y
		Which Players would like to join? (separate names with spaces, ex: mao dan steve
		bob)
		christina
		Adding: christina
		Added: christina to the game
		Hi christina!


		joel    2H      3S      4S      9S      AD


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		2

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		4 5
		Discarding AD 9S


		christina       5S      10D     JD      KD      KS


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding KS KD JD 10D 5S


		joel    2H      3S      4S      6D      6S

		christina       5C      5D      9C      10C     JC

		joel    Wins: 1 Losses: 1
		2H      3S      4S      6D      6S              One Pair
		christina       Wins: 0 Losses: 1
		5C      5D      9C      10C     JC              One Pair
		Does any Player want to leave? (Y/n)
		y
		Which Players would like to leave? (separate names with spaces, ex: joe bob bill
		ybob)
		joel
		Finding: joel
		Bye joel!
		Do any new Players want to join? (Y/n)
		n
}

EXTRA CREDIT:

Note: A computer Player can become a normal, user-driven Player if the computer leaves and the user takes the computer's name.
This is intended behavior.

The computer is called by specifying a name with an '*' after it. A computer Player is separated from a normal Player only by
a bool member variable in the Player struct. If an '*' is detected in the name given, then this bool is set to true. The bool
determines whether user input is taken in during that Player's before and after turn. If it is true, then logic is used to 
determine the computer Player's choices. What choices this computer will take is based off of the functionality given
in the assignment instructions. 

Computer card discard logic is done in two separate methods, one to determine the number of cards to discard, and the other to
determine which cards to discard. The rank of the hand is used, followed by going through different cases of 
finding where the most significant card is in the hand that is held. Once this is determined, the number of cards and position
of the cards to be discarded is returned back to the main function to be processed in the same way that any user input would
also be processed. 

1. { 
"CardGame fivecarddraw shane joel* steve*"
		Added: shane
		Added: joel     (Computer)
		Added: steve    (Computer)


		joel    10C     JC      QS      KD      KS


		How many cards to discard?
		3       *Computer*

		Discarding QS JC 10C


		steve   10H     JD      JH      QD      AS


		How many cards to discard?
		3       *Computer*

		Discarding AS QD 10H


		shane   2S      6H      7S      8D      AD


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		4

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		1 2 3 4
		Discarding 8D 7S 6H 2S


		joel    4H      9H      QH      KD      KS
		steve   7C      8H      JD      JH      AC
		shane   4C      5C      8S      QC      AD

		joel    (Computer)
		Wins:   1 Losses: 0
		4H      9H      QH      KD      KS              One Pair

		steve   (Computer)
		Wins:   0 Losses: 1
		7C      8H      JD      JH      AC              One Pair

		shane
		Wins:   0 Losses: 1
		4C      5C      8S      QC      AD              High Card


		Does any Player want to leave? (Y/n)
		n
		Do any new Players want to join? (Y/n)
		n


		steve   3H      3S      6D      9D      9H


		How many cards to discard?
		1       *Computer*

		Discarding 6D


		shane   4C      5S      7D      7H      JC


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		2

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		1 2
		Discarding 5S 4C


		joel    2C      4S      8D      8H      QD


		How many cards to discard?
		3       *Computer*

		Discarding QD 4S 2C


		steve   3H      3S      9D      9H      JH
		shane   7C      7D      7H      JC      JD
		joel    2D      2H      8D      8H      AC

		shane
		Wins:   1 Losses: 1
		7C      7D      7H      JC      JD              Full House

		steve   (Computer)
		Wins:   0 Losses: 2
		3H      3S      9D      9H      JH              Two Pairs

		joel    (Computer)
		Wins:   1 Losses: 1
		2D      2H      8D      8H      AC              Two Pairs


		Does any Player want to leave? (Y/n)
		n
		Do any new Players want to join? (Y/n)
		n


		shane   2C      5H      9H      10D     AD


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		3

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		1 2 3
		Discarding 9H 5H 2C


		joel    4C      5C      6H      9D      QH


		How many cards to discard?
		3       *Computer*

		Discarding 6H 5C 4C


		steve   3C      6C      7S      JH      KH


		How many cards to discard?
		3       *Computer*

		Discarding 7S 6C 3C


		shane   2H      8S      10D     QS      AD
		joel    9D      9S      JC      QH      KC
		steve   7C      7D      10C     JH      KH

		joel    (Computer)
		Wins:   2 Losses: 1
		9D      9S      JC      QH      KC              One Pair

		steve   (Computer)
		Wins:   0 Losses: 3
		7C      7D      10C     JH      KH              One Pair

		shane
		Wins:   1 Losses: 2
		2H      8S      10D     QS      AD              High Card


		Does any Player want to leave? (Y/n)
		Y
		Which Players would like to leave? (separate names with spaces, ex: joe bob billybob)
		shane joel steve
		Finding: shane
		Bye shane!
		Finding: joel
		Bye joel!
		Finding: steve
		Bye steve!
		Do any new Players want to join? (Y/n)
		n


		Not enough Players, ending game...
		Game ended!
}