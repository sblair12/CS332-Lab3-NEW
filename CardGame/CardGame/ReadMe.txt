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

Computer leaving logic is done using an unsigned int member variable that is initialized at "1". If the computer player is the
lowest scorer, then this variable is set to "0". If they are the highest, it is set to "2". Then, when determining who leaves
the game, computer stay chances are assigned (90% for the highest scorer, 10% for the lowest scorer, 50% chance otherwise) and
this chance is evaluated against an unsigned int generated with rand() % 100 to give a range of 0-100. If the computer chance is
higher than the generated random, then it leaves. Once all computer players have been evaluated, the user-driven players can 
decide if they want to leave or not.

1. { 
"CardGame fivecarddraw shane joel* steve* hotep"
		Added: shane
		Added: joel     (Computer)
		Added: steve    (Computer)
		Added: hotep


		joel    4C      5D      7S      10C     KS


		How many cards to discard?
		3       *Computer*

		Discarding 7S 5D 4C


		steve   4D      8D      JD      QC      AH


		How many cards to discard?
		4       *Computer*

		Discarding QC JD 8D 4D


		hotep   5H      7H      10D     KC      AC


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		3

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		3 4 5
		Discarding AC KC 10D


		shane   3C      8S      9C      10S     JC


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		2

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		1 4
		Discarding 10S 3C


		joel    6S      7C      9D      10C     KS
		steve   5S      6C      JS      KD      AH
		hotep   2D      5C      5H      7H      KH
		shane   2S      8S      9C      9S      JC

		shane
		Wins:   1 Losses: 0
		2S      8S      9C      9S      JC              One Pair

		hotep
		Wins:   0 Losses: 1
		2D      5C      5H      7H      KH              One Pair

		steve   (Computer)
		Wins:   0 Losses: 1
		5S      6C      JS      KD      AH              High Card

		joel    (Computer)
		Wins:   0 Losses: 1
		6S      7C      9D      10C     KS              High Card


		Computer "joel" has decided to leave
		Finding: joel
		Bye joel!
		Does any Player want to leave? (Y/n)
		Y
		Which Players would like to leave? (separate names with spaces, ex: joe bob billybob)
		steve
		Finding: steve
		Bye steve!
		Do any new Players want to join? (Y/n)
		Y
		Which Players would like to join? (separate names with spaces, ex: mao dan stevebob)
		yaoming* rock*
		Adding: yaoming*
		Added: yaoming  (Computer)
		Hi yaoming*!
		Adding: rock*
		Added: rock     (Computer)
		Hi rock*!


		yaoming 2C      3S      6C      9H      QD


		How many cards to discard?
		3       *Computer*

		Discarding 6C 3S 2C


		rock    2D      3D      9C      9S      JH


		How many cards to discard?
		3       *Computer*

		Discarding JH 3D 2D


		shane   4D      6S      9D      JS      KC


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		4

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		1 2 4 5
		Discarding KC JS 6S 4D


		hotep   4H      4S      8C      8D      KS


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		1

		What card to discard? (indices 1-5)
		Please give valid card indices, from 1 to 5
		5
		Discarding KS


		yaoming 2S      6D      9H      QD      QS
		rock    4C      7S      9C      9S      QC
		shane   6H      7C      7H      9D      AD
		hotep   4H      4S      8C      8D      JC

		hotep
		Wins:   1 Losses: 1
		4H      4S      8C      8D      JC              Two Pairs

		yaoming (Computer)
		Wins:   0 Losses: 1
		2S      6D      9H      QD      QS              One Pair

		rock    (Computer)
		Wins:   0 Losses: 1
		4C      7S      9C      9S      QC              One Pair

		shane
		Wins:   1 Losses: 1
		6H      7C      7H      9D      AD              One Pair


		Computer "yaoming" has decided to leave
		Finding: yaoming
		Bye yaoming!
		Does any Player want to leave? (Y/n)
		n
		Do any new Players want to join? (Y/n)
		n


		shane   2D      5D      5H      6H      AH


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		5

		Discarding all cards
		Discarding AH 6H 5H 5D 2D


		hotep   5C      5S      JC      JS      AC


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		1

		What card to discard? (indices 1-5)
		Please give valid card indices, from 1 to 5
		5
		Discarding AC


		rock    3C      3D      4S      8S      QC


		How many cards to discard?
		3       *Computer*

		Discarding QC 8S 4S


		shane   4D      9D      9H      10S     KS
		hotep   5C      5S      6S      JC      JS
		rock    2S      3C      3D      10H     KH

		hotep
		Wins:   2 Losses: 1
		5C      5S      6S      JC      JS              Two Pairs

		shane
		Wins:   1 Losses: 2
		4D      9D      9H      10S     KS              One Pair

		rock    (Computer)
		Wins:   0 Losses: 2
		2S      3C      3D      10H     KH              One Pair


		Computer "rock" has decided to leave
		Finding: rock
		Bye rock!
		Does any Player want to leave? (Y/n)
		Y
		Which Players would like to leave? (separate names with spaces, ex: joe bob billybob)
		shane
		Finding: shane
		Bye shane!
		Do any new Players want to join? (Y/n)
		n


		Not enough Players, ending game...
		Saving progress for last player
		Finding: hotep
		Bye hotep!
		Game ended!
}

2. {
"CardGame fivecarddraw shane joel* steve* hotep*""
		Added: shane
		Added: joel     (Computer)
		Added: steve    (Computer)
		Added: hotep    (Computer)


		joel    6H      8S      10S     JD      AC


		How many cards to discard?
		4       *Computer*

		Discarding JD 10S 8S 6H


		steve   3D      6D      7D      8C      QC


		How many cards to discard?
		3       *Computer*

		Discarding 7D 6D 3D


		hotep   3C      3H      4S      7H      JH


		How many cards to discard?
		3       *Computer*

		Discarding JH 7H 4S


		shane   2C      3S      4D      7C      JS


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		2

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		4 5
		Discarding JS 7C


		joel    2H      5S      8H      QD      AC
		steve   7S      8C      9H      9S      QC
		hotep   3C      3H      8D      KH      AD
		shane   2C      3S      4D      5C      5D

		steve   (Computer)
		Wins:   1 Losses: 1
		7S      8C      9H      9S      QC              One Pair

		shane
		Wins:   1 Losses: 3
		2C      3S      4D      5C      5D              One Pair

		hotep   (Computer)
		Wins:   2 Losses: 2
		3C      3H      8D      KH      AD              One Pair

		joel    (Computer)
		Wins:   0 Losses: 2
		2H      5S      8H      QD      AC              High Card


		Computer "joel" has decided to leave
		Finding: joel
		Bye joel!
		Computer "hotep" has decided to leave
		Finding: hotep
		Bye hotep!
		Does any Player want to leave? (Y/n)
		n
		Do any new Players want to join? (Y/n)
		n


		shane   4H      5D      JH      JS      QD


		How many cards to discard?
		Please give a VALID number of cards to discard, from 0 to 5
		2

		Which cards to discard? (indices 1-5, separate choices by spaces, ex: 1 2 4)
		Please give valid card indices, from 1 to 5
		1 2
		Discarding 5D 4H


		steve   4C      9S      JD      KS      AH


		How many cards to discard?
		4       *Computer*

		Discarding KS JD 9S 4C


		shane   3C      JH      JS      QD      AC
		steve   5C      6D      7S      9H      AH

		shane
		Wins:   2 Losses: 3
		3C      JH      JS      QD      AC              One Pair

		steve   (Computer)
		Wins:   1 Losses: 2
		5C      6D      7S      9H      AH              High Card


		Computer "steve" has decided to leave
		Finding: steve
		Bye steve!
		Does any Player want to leave? (Y/n)
		n
		Do any new Players want to join? (Y/n)
		n


		Not enough Players, ending game...
		Saving progress for last player
		Finding: shane
		Bye shane!
		Game ended!
}