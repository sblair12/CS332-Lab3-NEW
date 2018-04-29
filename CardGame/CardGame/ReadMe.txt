// Shane Blair	- sblair@wustl.edu		-	448740
// Steven Lee	- lee.steven@wustl.edu	-	448180

// Lab 4: Multiple Card Games

For this lab, we implemented a program to:
	- play a game called Five Card Draw as instructed
	- play a game called Seven Card Stud as instructed
	- play a game called Texas Hold Em as instructed

For method functions see comments in source files

NOTE:	Selections require space separated items, without an extra space at the end, for input to be valid.
		If too many or too few items are given, the program will ask for the selections to be input again.
		This is the intended functionality.
		Computer from last lab is not functional for SevenCardStud.

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

"Cardgame fivecarddraw shane steven joel"
Produced:
	Playing: fivecarddraw
	Added: shane    Chips: 20
	Added: steven   Chips: 20
	Added: joel     Chips: 20

	Ante:
	1 chip(s) from shane
	1 chip(s) from steven
	1 chip(s) from joel
	Pot: 3

	steven  2D      4S      5H      6C      KH
	Chips: 19

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	bet 2

	joel    2S      4D      8C      QC      QD
	Chips: 19       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise 2

	shane   3C      5S      8S      10S     AS
	Chips: 19       Current Bet: 4

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise 2

	steven  2D      4S      5H      6C      KH
	Chips: 19       Current Bet: 6

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise 2

	joel    2S      4D      8C      QC      QD
	Chips: 19       Current Bet: 8

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise 2

	shane   3C      5S      8S      10S     AS
	Chips: 19       Current Bet: 10

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise 2

	steven  2D      4S      5H      6C      KH
	Chips: 19       Current Bet: 12

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise 2

	joel    2S      4D      8C      QC      QD
	Chips: 19       Current Bet: 14

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise 2

	shane   3C      5S      8S      10S     AS
	Chips: 19       Current Bet: 16

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise 2

	steven  2D      4S      5H      6C      KH
	Chips: 19       Current Bet: 18

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise 1

	joel    2S      4D      8C      QC      QD
	Chips: 19       Current Bet: 19

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	call

	shane   3C      5S      8S      10S     AS
	Chips: 19       Current Bet: 19

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	call

	Pot: 60


	steven  2D      4S      5H      6C      KH


	How many cards to discard?
	Please give a VALID number of cards to discard, from 0 to 5
	5

	Discarding all cards
	Discarding KH 6C 5H 4S 2D


	joel    2S      4D      8C      QC      QD


	How many cards to discard?
	Please give a VALID number of cards to discard, from 0 to 5
	5

	Discarding all cards
	Discarding QD QC 8C 4D 2S


	shane   3C      5S      8S      10S     AS


	How many cards to discard?
	Please give a VALID number of cards to discard, from 0 to 5
	5

	Discarding all cards
	Discarding AS 10S 8S 5S 3C


	steven  7D      9S      QH      QS      AC
	Chips: 0
	Already all in

	joel    3D      7S      9D      10C     AH
	Chips: 0
	Already all in

	shane   4H      7C      7H      8D      JH
	Chips: 0
	Already all in

	Pot: 60

	steven   won 60 chips!
	Wins:   1       Losses: 0       Chips: 60
	7D      9S      QH      QS      AC              One Pair

	shane
	Wins:   0       Losses: 1       Chips: 0
	4H      7C      7H      8D      JH              One Pair

	joel
	Wins:   0       Losses: 1       Chips: 0
	3D      7S      9D      10C     AH              High Card


	joel, you are out of chips.
	Would you like to buy back in (Y/n)?
	n
	Finding: joel
	Bye joel!
	shane, you are out of chips.
	Would you like to buy back in (Y/n)?
	n
	Finding: shane
	Bye shane!
	Does any Player want to leave? (Y/n)
	n
	Do any new Players want to join? (Y/n)
	n


	Not enough Players, ending game...
	Saving progress for last player
	Finding: steven
	Bye steven!
	Game ended!

	Would you like to play another game? (Y/n)
	n
	Bye bye

}

9. {

**checking for valid inputs 

"Cardgame fivecarddraw joel shane steven"
Produced:
	Playing: fivecarddraw
	Added: joel     Chips: 20
	Added: shane    Chips: 20
	Added: steven   Chips: 20

	Ante:
	1 chip(s) from joel
	1 chip(s) from shane
	1 chip(s) from steven
	Pot: 3

	shane   2H      3S      6C      QC      AD
	Chips: 19

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	1


	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	2


	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	3


	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	=


	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	bet 2

	steven  3C      4H      9D      JC      JH
	Chips: 19       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise -
	Invalid raise: The maximum raise is 2 chips
	Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise 0
	Invalid raise: The maximum raise is 2 chips
	Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise 10
	Invalid raise: Raise must be 1 or 2 chips
	Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise fakjfa;djksf
	Invalid raise: Raise must be 1 or 2 chips
	Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise `
	Invalid raise: The maximum raise is 2 chips
	Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	 
	 ...
}

10. {
"cardgame sevencardstud"
Produced:
	Usage: cardgame <game_name> <player1> <player2> ...
					Run this program with one argument for a game name and 2 or more arguments for player names
					(ex: cardgame fivecarddraw billybob Mao)
}

11. {

"cardgame sevencardstud joel shane steven daniel mao lee bear rasputin"
Produced:
(top was truncated b/c too many lines)
...
Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
check

joel    *       *       7S      10H     JD      AC
shane   *       *       6H      7H      9H      JS
daniel  *       *       6D      6S      8D      KD
mao     *       *       JC      QD      AD      AH
lee     *       *       9D      10C     10D     KC
bear    *       *       QH      QS      KS      AS
rasputin        *       *       4S      5S      8C      9C

steven  2D      5D      6C      7D      8S      9S
Chips: 17

Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
check

Pot: 24
No more cards in the deck
Exception caught: 14
}

12. {

"cardgame fivecarddraw shane steven joel"
Produced:
	Playing: fivecarddraw
	Added: shane    Chips: 20
	Added: steven   Chips: 20
	Added: joel     Chips: 20

	Ante:
	1 chip(s) from shane
	1 chip(s) from steven
	1 chip(s) from joel
	Pot: 3

	steven  5H      7S      8S      9D      JD
	Chips: 19

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	joel    4H      5S      9C      AD      AS
	Chips: 19

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	bet 2

	shane   3D      6S      QC      QS      AC
	Chips: 19       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	fold

	steven  5H      7S      8S      9D      JD
	Chips: 19       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	fold

	Pot: 5

	joel     won 5 chips!
	Wins:   1       Losses: 0       Chips: 22
	4H      5S      9C      AD      AS              One Pair

	shane
	Wins:   0       Losses: 1       Chips: 19
	FOLD

	steven
	Wins:   0       Losses: 1       Chips: 19
	FOLD


	Does any Player want to leave? (Y/n)
	n
	Do any new Players want to join? (Y/n)
	n

	Ante:
	1 chip(s) from shane
	1 chip(s) from steven
	1 chip(s) from joel
	Pot: 3

	joel    3D      9D      9H      JH      KC
	Chips: 21

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	bet 2

	shane   7D      9C      10S     QH      KS
	Chips: 18       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	fold

	steven  5H      7S      8S      JS      KD
	Chips: 18       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	fold

	Pot: 5

	joel     won 5 chips!
	Wins:   2       Losses: 0       Chips: 24
	3D      9D      9H      JH      KC              One Pair

	shane
	Wins:   0       Losses: 2       Chips: 18
	FOLD

	steven
	Wins:   0       Losses: 2       Chips: 18
	FOLD


	Does any Player want to leave? (Y/n)
	n
	Do any new Players want to join? (Y/n)
	n

	Ante:
	1 chip(s) from shane
	1 chip(s) from steven
	1 chip(s) from joel
	Pot: 3

	shane   2C      8C      8S      9C      KD
	Chips: 17

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	bet 2

	steven  2D      3S      6D      10C     10H
	Chips: 17       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	fold
	Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	fold

	joel    5H      6S      9H      JD      AC
	Chips: 23       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	fold

	Pot: 5

	shane    won 5 chips!
	Wins:   1       Losses: 2       Chips: 20
	2C      8C      8S      9C      KD              One Pair

	steven
	Wins:   0       Losses: 3       Chips: 17
	FOLD

	joel
	Wins:   2       Losses: 1       Chips: 23
	FOLD


	Does any Player want to leave? (Y/n)
	y
	Which Players would like to leave? (separate names with spaces, ex: joe bob bill
	ybob)
	shane joel steven
	Finding: shane
	Bye shane!
	Finding: joel
	Bye joel!
	Finding: steven
	Bye steven!
	Do any new Players want to join? (Y/n)
	n


	Not enough Players, ending game...
	Game ended!

	Would you like to play another game? (Y/n)
	n
	Bye bye

}

13. {

"cardgame sevencardstud joel steven shane"
Produced:
	Playing: sevencardstud
	Added: joel     Chips: 19
	Added: steven   Chips: 22
	Added: shane    Chips: 19
	Ante:
	1 chip(s) from joel
	1 chip(s) from steven
	1 chip(s) from shane
	Pot: 3

	joel    *       *       6S
	shane   *       *       8C

	steven  2H      JC      QS
	Chips: 21

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	bet 2

	joel    *       *       6S
	steven  *       *       QS

	shane   5H      7C      8C
	Chips: 18       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	fold

	steven  *       *       QS
	shane   *       *       8C

	joel    4H      6D      6S
	Chips: 18       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	fold

	Pot: 5

	steven   won 5 chips!
	Wins:   2       Losses: 0       Chips: 24
	2H      JC      QS

	joel
	Wins:   0       Losses: 2       Chips: 18
	FOLD

	shane
	Wins:   0       Losses: 2       Chips: 18
	FOLD


	Does any Player want to leave? (Y/n)
	yes
	Does any Player want to leave? (Y/n)
	y
	Which Players would like to leave? (separate names with spaces, ex: joe bob bill
	ybob)
	shane joel steven
	Finding: shane
	Bye shane!
	Finding: joel
	Bye joel!
	Finding: steven
	Bye steven!
	Do any new Players want to join? (Y/n)
	n


	Not enough Players, ending game...
	Game ended!

	Would you like to play another game? (Y/n)
	n
	Bye bye
}

14. {

"cardgame sevencardstud joel steven shane joel"
Produced:
	Playing: sevencardstud
	Added: joel     Chips: 18
	Added: steven   Chips: 24
	Added: shane    Chips: 18
	joel is already playing
	Exception caught: 13
}

15. { 

"cardgame sevencardstud joel steven shane"
Produced:
	Playing: sevencardstud
	Added: joel     Chips: 18
	Added: steven   Chips: 24
	Added: shane    Chips: 18
	Ante:
	1 chip(s) from joel
	1 chip(s) from steven
	1 chip(s) from shane
	Pot: 3

	joel    *       *       5C
	shane   *       *       JD

	steven  2D      3D      9H
	Chips: 23

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	joel    *       *       5C
	steven  *       *       9H

	shane   6C      7D      JD
	Chips: 17

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	steven  *       *       9H
	shane   *       *       JD

	joel    2S      4S      5C
	Chips: 17

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	Pot: 3
	joel    *       *       4S      5C
	shane   *       *       7D      JD

	steven  2D      3D      8H      9H
	Chips: 23

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	joel    *       *       4S      5C
	steven  *       *       8H      9H

	shane   2C      6C      7D      JD
	Chips: 17

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	steven  *       *       8H      9H
	shane   *       *       7D      JD

	joel    2S      4D      4S      5C
	Chips: 17

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	Pot: 3
	joel    *       *       4S      5C      QC
	shane   *       *       7D      JD      KD

	steven  2D      3D      8H      9H      9S
	Chips: 23

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	joel    *       *       4S      5C      QC
	steven  *       *       8H      9H      9S

	shane   2C      6C      7D      JD      KD
	Chips: 17

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	steven  *       *       8H      9H      9S
	shane   *       *       7D      JD      KD

	joel    2S      4D      4S      5C      QC
	Chips: 17

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	Pot: 3
	joel    *       *       4D      4S      5C      QC
	shane   *       *       7D      JD      KD      AD

	steven  2D      3D      8C      8H      9H      9S
	Chips: 23

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	joel    *       *       4D      4S      5C      QC
	steven  *       *       8C      8H      9H      9S

	shane   2C      6C      7D      JD      KD      AD
	Chips: 17

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	steven  *       *       8C      8H      9H      9S
	shane   *       *       7D      JD      KD      AD

	joel    2S      3S      4D      4S      5C      QC
	Chips: 17

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	Pot: 3
	joel    *       *       4D      4S      5C      10H     *
	shane   *       *       7D      JD      KD      AD      *

	steven  2D      3D      8C      8H      9H      9S      KH
	Chips: 23

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	joel    *       *       4D      4S      5C      10H     *
	steven  *       *       8C      8H      9H      9S      *

	shane   2C      6C      7D      JD      KD      AD      AS
	Chips: 17

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	steven  *       *       8C      8H      9H      9S      *
	shane   *       *       7D      JD      KD      AD      *

	joel    2S      3S      4D      4S      5C      10H     QC
	Chips: 17

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	Pot: 3

	steven   won 3 chips!
	Wins:   3       Losses: 0       Chips: 26
	2D      3D      8C      8H      9H      9S      KH
	8C      8H      9H      9S      KH              Two Pairs

	shane
	Wins:   0       Losses: 3       Chips: 17
	2C      6C      7D      JD      KD      AD      AS
	7D      JD      KD      AD      AS              One Pair

	joel
	Wins:   0       Losses: 3       Chips: 17
	2S      3S      4D      4S      5C      10H     QC
	2S      3S      4D      4S      5C              One Pair


	Does any Player want to leave? (Y/n)
	n
	Do any new Players want to join? (Y/n)
	y
	Which Players would like to join? (separate names with spaces, ex: mao dan steve
	bob)
	joel
	Adding: joel
	Invalid name: joel
}

16. {
**checking to see if another game can start
"cardgame sevencardstud shane steven"
Produced:
	Does any Player want to leave? (Y/n)
	y
	Which Players would like to leave? (separate names with spaces, ex: joe bob bill
	ybob)
	shane joel steven
	Finding: shane
	Bye shane!
	Finding: joel
	Bye joel!
	Finding: steven
	Bye steven!
	Do any new Players want to join? (Y/n)
	n


	Not enough Players, ending game...
	Game ended!

	Would you like to play another game? (Y/n)
	y
	What game would you like to play?
	texasholdem
	Playing: texasholdem
	Added: joel     Chips: 15
	Added: shane    Chips: 15
	Added: steven   Chips: 30
	Ante:
	1 chip(s) from joel
	1 chip(s) from shane
	1 chip(s) from steven
	Pot: 3


	shane   7D      AC
	Chips: 14

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)


	^C
	C:\Users\lee.steven\Source\Repos\CS332-Lab3-NEW\CardGame\x64\Debug>cardgame seve
	ncardstud shane steven
	Playing: sevencardstud
	Added: shane    Chips: 20
	Added: steven   Chips: 20
	Ante:
	1 chip(s) from shane
	1 chip(s) from steven
	Pot: 2

	shane   *       *       KS

	steven  8S      9C      10S
	Chips: 19

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	steven  *       *       10S

	shane   3C      10H     KS
	Chips: 19

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	bet 2

	shane   *       *       KS

	steven  8S      9C      10S
	Chips: 19       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	fold

	Pot: 4

	shane    won 4 chips!
	Wins:   1       Losses: 0       Chips: 21
	3C      10H     KS

	steven
	Wins:   0       Losses: 1       Chips: 19
	FOLD


	Does any Player want to leave? (Y/n)
	n
	Do any new Players want to join? (Y/n)
	n
	Ante:
	1 chip(s) from shane
	1 chip(s) from steven
	Pot: 2

	steven  *       *       AD

	shane   2D      QD      AC
	Chips: 20

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	shane   *       *       AC

	steven  10C     KD      AD
	Chips: 18

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	fold


	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	bet 2

	steven  *       *       AD

	shane   2D      QD      AC
	Chips: 20       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	fold

	Pot: 4

	steven   won 4 chips!
	Wins:   1       Losses: 1       Chips: 20
	10C     KD      AD

	shane
	Wins:   1       Losses: 1       Chips: 20
	FOLD


	Does any Player want to leave? (Y/n)
	y
	Which Players would like to leave? (separate names with spaces, ex: joe bob bill
	ybob)
	shane steven
	Finding: shane
	Bye shane!
	Finding: steven
	Bye steven!
	Do any new Players want to join? (Y/n)
	n


	Not enough Players, ending game...
	Game ended!

	Would you like to play another game? (Y/n)
	y
	What game would you like to play?
	fivecarddraw
	Playing: fivecarddraw
	Added: shane    Chips: 20
	Added: steven   Chips: 20

	Ante:
	1 chip(s) from shane
	1 chip(s) from steven
	Pot: 2

	steven  3H      4S      7D      10D     QH
	Chips: 19

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	bet 2

	shane   2S      4D      7H      10C     JS
	Chips: 19       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise 2

	steven  3H      4S      7D      10D     QH
	Chips: 19       Current Bet: 4

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	fold

	Pot: 8

	shane    won 8 chips!
	Wins:   2       Losses: 1       Chips: 23
	2S      4D      7H      10C     JS              High Card

	steven
	Wins:   1       Losses: 2       Chips: 17
	FOLD


	Does any Player want to leave? (Y/n)
	y
	Which Players would like to leave? (separate names with spaces, ex: joe bob bill
	ybob)
	steven shane
	Finding: steven
	Bye steven!
	Finding: shane
	Bye shane!
	Do any new Players want to join? (Y/n)
	y
	Which Players would like to join? (separate names with spaces, ex: mao dan steve
	bob)
	n
	Adding: n
	Added: n        Chips: 20
	Hi n!


	Not enough Players, ending game...
	Saving progress for last player
	Finding: n
	Bye n!
	Game ended!

	Would you like to play another game? (Y/n)
	y
	What game would you like to play?
	texasholdem
	Playing: texasholdem
	Added: shane    Chips: 23
	Added: steven   Chips: 17
	Ante:
	1 chip(s) from shane
	1 chip(s) from steven
	Pot: 2


	steven  10C     QD
	Chips: 16

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check



	shane   4C      9C
	Chips: 22

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	bet 2



	steven  10C     QD
	Chips: 16       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	fold

	Pot: 4


	shane    won 4 chips!
	Wins:   3       Losses: 1       Chips: 24
	4C      9C

	steven
	Wins:   1       Losses: 3       Chips: 16
	FOLD


	Does any Player want to leave? (Y/n)
	y
	Which Players would like to leave? (separate names with spaces, ex: joe bob bill
	ybob)
	shane steven
	Finding: shane
	Bye shane!
	Finding: steven
	Bye steven!
	Do any new Players want to join? (Y/n)
	n


	Not enough Players, ending game...
	Game ended!

	Would you like to play another game? (Y/n)
	n
	Bye bye

}


EXTRA CREDIT (Texas Hold 'EM):
1. {

"cardgame texasholdem steven shane"
Produced:
	Playing: texasholdem
	Added: steven   Chips: 20
	Added: shane    Chips: 20
	Ante:
	1 chip(s) from steven
	1 chip(s) from shane
	Pot: 2


	shane   3C      4C
	Chips: 19

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	bet 2



	steven  3H      JD
	Chips: 19       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	fold

	Pot: 4


	shane    won 4 chips!
	Wins:   1       Losses: 0       Chips: 21
	3C      4C

	steven
	Wins:   0       Losses: 1       Chips: 19
	FOLD

}

2.{
"cardgame texasholdem steven shane joel daniel santa obama michelle sasha caitlyn barry bomo flash jomo pickle rick morty jankens jarknes jukens ki lee blaire kurenok vladimir shook shidel"
Produced:
	Playing: texasholdem
	Added: steven   Chips: 20
	Added: shane    Chips: 20
	Added: joel     Chips: 20
	Added: daniel   Chips: 20
	Added: santa    Chips: 20
	Added: obama    Chips: 20
	Added: michelle Chips: 20
	Added: sasha    Chips: 20
	Added: caitlyn  Chips: 20
	Added: barry    Chips: 20
	Added: bomo     Chips: 20
	Added: flash    Chips: 20
	Added: jomo     Chips: 20
	Added: pickle   Chips: 20
	Added: rick     Chips: 20
	Added: morty    Chips: 20
	Added: jankens  Chips: 20
	Added: jarknes  Chips: 20
	Added: jukens   Chips: 20
	Added: ki       Chips: 20
	Added: lee      Chips: 20
	Added: blaire   Chips: 20
	Added: kurenok  Chips: 20
	Added: vladimir Chips: 20
	Added: shook    Chips: 20
	Added: shidel   Chips: 20
	Ante:
	1 chip(s) from steven
	1 chip(s) from shane
	1 chip(s) from joel
	1 chip(s) from daniel
	1 chip(s) from santa
	1 chip(s) from obama
	1 chip(s) from michelle
	1 chip(s) from sasha
	1 chip(s) from caitlyn
	1 chip(s) from barry
	1 chip(s) from bomo
	1 chip(s) from flash
	1 chip(s) from jomo
	1 chip(s) from pickle
	1 chip(s) from rick
	1 chip(s) from morty
	1 chip(s) from jankens
	1 chip(s) from jarknes
	1 chip(s) from jukens
	1 chip(s) from ki
	1 chip(s) from lee
	1 chip(s) from blaire
	1 chip(s) from kurenok
	1 chip(s) from vladimir
	1 chip(s) from shook
	1 chip(s) from shidel
	Pot: 26

	...


	The FLOP
	No more cards in the deck
	Exception caught: 14
}

3. {

"cardgame texasholdem steven shane joel"
Produced:
	Playing: texasholdem
	Added: steven   Chips: 20
	Added: shane    Chips: 20
	Added: joel     Chips: 20
	Ante:
	1 chip(s) from steven
	1 chip(s) from shane
	1 chip(s) from joel
	Pot: 3


	shane   3S      JD
	Chips: 19

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	bet 2



	joel    3D      KC
	Chips: 19       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise 2



	steven  9C      AS
	Chips: 19       Current Bet: 4

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	check
	Current Bet: 4

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	check
	Current Bet: 4

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	check
	Current Bet: 4

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	check
	Current Bet: 4

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	call



	shane   3S      JD
	Chips: 19       Current Bet: 4

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	call

	Pot: 15

	The FLOP
	2H      6S      8D

	shane   3S      JD
	Chips: 15

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	2H      6S      8D

	joel    3D      KC
	Chips: 15

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	2H      6S      8D

	steven  9C      AS
	Chips: 15

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	Pot: 15

	The TURN
	2H      6S      8D      JC

	shane   3S      JD
	Chips: 15

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	2H      6S      8D      JC

	joel    3D      KC
	Chips: 15

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	2H      6S      8D      JC

	steven  9C      AS
	Chips: 15

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	Pot: 15

	The RIVER
	2H      6S      8D      JC      9S

	shane   3S      JD
	Chips: 15

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	2H      6S      8D      JC      9S

	joel    3D      KC
	Chips: 15

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	2H      6S      8D      JC      9S

	steven  9C      AS
	Chips: 15

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	Pot: 15

	2H      6S      8D      JC      9S
	shane    won 15 chips!
	Wins:   1       Losses: 0       Chips: 30
	3S      JD
	2H      3S      6S      JC      JD              One Pair

	steven
	Wins:   0       Losses: 1       Chips: 15
	9C      AS
	2H      6S      8D      9C      9S              One Pair

	joel
	Wins:   0       Losses: 1       Chips: 15
	3D      KC
	2H      6S      8D      9S      JC              High Card


	Does any Player want to leave? (Y/n)
	b
	Does any Player want to leave? (Y/n)
	n
	Do any new Players want to join? (Y/n)
	n
}

3. {

"cardgame texasholdem joel shane steven"
Produced:
	Playing: texasholdem
	Added: joel     Chips: 20
	Added: shane    Chips: 20
	Added: steven   Chips: 20
	Ante:
	1 chip(s) from joel
	1 chip(s) from shane
	1 chip(s) from steven
	Pot: 3


	shane   5H      6C
	Chips: 19

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check



	steven  7C      9C
	Chips: 19

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check



	joel    3D      JC
	Chips: 19

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	bet 2



	shane   5H      6C
	Chips: 19       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	raise 2



	steven  7C      9C
	Chips: 19       Current Bet: 4

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	call



	joel    3D      JC
	Chips: 19       Current Bet: 4

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	call

	Pot: 15

	The FLOP
	JH      9H      AD

	shane   5H      6C
	Chips: 15

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	check

	JH      9H      AD

	steven  7C      9C
	Chips: 15

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
	bet 2

	JH      9H      AD

	joel    3D      JC
	Chips: 15       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	fold

	JH      9H      AD

	shane   5H      6C
	Chips: 15       Current Bet: 2

	Would you like to 'fold', 'raise', or 'call'? (ex: 'raise 2', the max raise is 2
	 chips)
	fold

	Pot: 17

	JH      9H      AD
	steven   won 17 chips!
	Wins:   1       Losses: 0       Chips: 30
	7C      9C

	joel
	Wins:   0       Losses: 1       Chips: 15
	FOLD

	shane
	Wins:   0       Losses: 1       Chips: 15
	FOLD


	Does any Player want to leave? (Y/n)
	y
	Which Players would like to leave? (separate names with spaces, ex: joe bob bill
	ybob)
	shane joel steven
	Finding: shane
	Bye shane!
	Finding: joel
	Bye joel!
	Finding: steven
	Bye steven!
	Do any new Players want to join? (Y/n)
	n


	Not enough Players, ending game...
	Game ended!

	Would you like to play another game? (Y/n)
	y
	What game would you like to play?
	texasholdem
	Playing: texasholdem
	Added: joel     Chips: 15
	Added: shane    Chips: 15
	Added: steven   Chips: 30
	Ante:
	1 chip(s) from joel
	1 chip(s) from shane
	1 chip(s) from steven
	Pot: 3


	shane   7D      AC
	Chips: 14

	Would you like to 'check' or 'bet'? (ex: 'bet 2', the max bet is 2 chips)
}