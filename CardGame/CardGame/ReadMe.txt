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


COMMAND LINE Trials


1. {

"CardDeck"
Produces:
	Usage: CardDeck <argument> [-shuffle]
                Run this program with one argument for a deck file and an optional parameter
                ('-shuffle' to shuffle the deck before usage)
Error Code: 1

This output is expected.

}

2. {

"CardDeck no_file.txt"
Produces:
	Cannot open the input file
Error Code: 2

This output is expected.

}

3. {

	Input file (deck_empty.txt): [
	]

"CardDeck deck_empty.txt"
Produces:
	No valid hands in input file
Error Code: 3

This output is expected.

}

4. {

"CardDeck -shuffle"
Produces:
	ERROR: '-shuffle' parameter given without a location for a deck file
Error Code: 4

This output is expected.

}

5. {

"CardDeck poker.txt full_deck.txt"
Produces:
	ERROR: Two parameters given but none are the '-shuffle' parameter
Error Code: 5

This output is expected.

}

6. {

"CardDeck -shuffle -shuffle"
Produces:
	ERROR: Both parameters are the '-shuffle' parameter
Error Code: 6

This output is expected.

}

7. {

	Input file (deck_invalid.txt): [
		7h QD 10F SG 9H
		Kc 3s 3D 2D 7c 5c
		6H
	]

"CardDeck deck_invalid.txt"
Produces:
	Invalid Card    at Line 1:      Card "10F"
	Invalid Card    at Line 1:      Card "SG"

	DECK before dealing:
	7H QD 9H KC 3S 3D 2D 7C 5C 6H

	9 hands total
	Not enough cards in the deck to deal 5 cards to all hands
Error Code: 7

This output is expected.

}

8. {

	Input file (full_deck.txt): [
		2C 3C 4C 5C 6C 7C 8C 9C 10C JC QC KC AC

		aD kD qD jD 10D 9D 8D 7D 6D 5D 4D 3D 2D

		2h 3h 4h 5h 6h 7h 8h 9h 10h Jh Qh Kh Ah

		as ks qs js 10s 9s 8s 7s 6s 5s 4s 3s 2s
	]

"CardDeck full_deck.txt"
Produces:
	DECK before dealing:
	2C 3C 4C 5C 6C 7C 8C 9C 10C JC QC KC AC
	AD KD QD JD 10D 9D 8D 7D 6D 5D 4D 3D 2D
	2H 3H 4H 5H 6H 7H 8H 9H 10H JH QH KH AH
	AS KS QS JS 10S 9S 8S 7S 6S 5S 4S 3S 2S

	DECK after dealing:
	2C 3C 4C 5C 6C 7C 8C

	HANDS:
	2S      3D      9H      JS      QD
	3S      4D      8H      QS      KD
	4S      5D      7H      KS      AD
	5S      6D      6H      AC      AS
	5H      6S      7D      KC      AH
	4H      7S      8D      QC      KH
	3H      8S      9D      JC      QH
	2H      9S      10C     10D     JH
	2D      9C      10H     10S     JD

	HANDS sorted by less than operator:
	2D      9C      10H     10S     JD
	2H      9S      10C     10D     JH
	2S      3D      9H      JS      QD
	3H      8S      9D      JC      QH
	3S      4D      8H      QS      KD
	4H      7S      8D      QC      KH
	4S      5D      7H      KS      AD
	5H      6S      7D      KC      AH
	5S      6D      6H      AC      AS

	HANDS sorted by Poker ranking:
	5S      6D      6H      AC      AS      Two Pairs
	2H      9S      10C     10D     JH      One Pair
	2D      9C      10H     10S     JD      One Pair
	5H      6S      7D      KC      AH      High Card
	4S      5D      7H      KS      AD      High Card
	4H      7S      8D      QC      KH      High Card
	3S      4D      8H      QS      KD      High Card
	3H      8S      9D      JC      QH      High Card
	2S      3D      9H      JS      QD      High Card
Error Code: 0

This output is expected.

}

9. {

	Input file (full_deck.txt): [
		2C 3C 4C 5C 6C 7C 8C 9C 10C JC QC KC AC

		aD kD qD jD 10D 9D 8D 7D 6D 5D 4D 3D 2D

		2h 3h 4h 5h 6h 7h 8h 9h 10h Jh Qh Kh Ah

		as ks qs js 10s 9s 8s 7s 6s 5s 4s 3s 2s
	]

"CardDeck full_deck.txt -shuffle"
Produces:
	DECK before dealing:
	3D 10S 8H QC 7D 4S AC 5H 6C 9S AS 2D 10D
	9D 4H 6S 8S 2H QD JH 4C 6D 8D 5D 8C KS
	JS 7C 5C 3S AD 4D 7H 6H 9H 2S QS 3H KD
	10C 10H AH 5S KC 3C KH 7S JD QH JC 2C 9C

	DECK after dealing:
	3D 10S 8H QC 7D 4S AC

	HANDS:
	5S      6H      6S      8C      9C
	2C      4H      5D      7H      AH
	4D      8D      9D      10H     JC
	6D      10C     10D     QH      AD
	2D      3S      4C      JD      KD
	3H      5C      7S      JH      AS
	7C      9S      QD      QS      KH
	2H      2S      3C      6C      JS
	5H      8S      9H      KC      KS

	HANDS sorted by less than operator:
	2C      4H      5D      7H      AH
	2D      3S      4C      JD      KD
	2H      2S      3C      6C      JS
	3H      5C      7S      JH      AS
	4D      8D      9D      10H     JC
	5H      8S      9H      KC      KS
	5S      6H      6S      8C      9C
	6D      10C     10D     QH      AD
	7C      9S      QD      QS      KH

	HANDS sorted by Poker ranking:
	5H      8S      9H      KC      KS      One Pair
	7C      9S      QD      QS      KH      One Pair
	6D      10C     10D     QH      AD      One Pair
	5S      6H      6S      8C      9C      One Pair
	2H      2S      3C      6C      JS      One Pair
	3H      5C      7S      JH      AS      High Card
	2C      4H      5D      7H      AH      High Card
	2D      3S      4C      JD      KD      High Card
	4D      8D      9D      10H     JC      High Card
Error Code: 0

This output is expected.

}

10. {
Test comparisons between poker rankings (full house, straight, two pair, and one pair)

	Input file (comparison_1.txt): [
		8s 7s 6s 5h 4s 2h 7D

		2C 3C  qd  5C 7C kh 8C  9c AC 

		2s 5s  KC 10C aD kD 4C  9D as

		QC 6C  JC  6D 5D 4D 8D  3D jd 

		qs 4h 10h  6h 7h 8h 9h  3s Jh 

		Qh 2D  Ah 10D ks 3h 9s 10s js
	]

"CardDeck comparison_1.txt"
Produces:
	DECK before dealing:
	8S 7S 6S 5H 4S 2H 7D 2C 3C QD 5C 7C KH
	8C 9C AC 2S 5S KC 10C AD KD 4C 9D AS QC
	6C JC 6D 5D 4D 8D 3D JD QS 4H 10H 6H 7H
	8H 9H 3S JH QH 2D AH 10D KS 3H 9S 10S JS

	DECK after dealing:
	8S 7S 6S 5H 4S 2H 7D

	HANDS:
	JD      JH      JS      AC      AS
	3D      3S      9C      9D      10S
	4C      8C      8D      9H      9S
	3H      4D      8H      KD      KH
	5D      7C      7H      KS      AD
	5C      6D      6H      10C     10D
	10H     JC      QD      KC      AH
	2D      3C      4H      5S      6C
	2C      2S      QC      QH      QS

	HANDS sorted by less than operator:
	2C      2S      QC      QH      QS
	2D      3C      4H      5S      6C
	3D      3S      9C      9D      10S
	3H      4D      8H      KD      KH
	4C      8C      8D      9H      9S
	5C      6D      6H      10C     10D
	5D      7C      7H      KS      AD
	10H     JC      QD      KC      AH
	JD      JH      JS      AC      AS

	HANDS sorted by Poker ranking:
	2C      2S      QC      QH      QS      Full House
	JD      JH      JS      AC      AS      Full House
	10H     JC      QD      KC      AH      Straight
	2D      3C      4H      5S      6C      Straight
	5C      6D      6H      10C     10D     Two Pairs
	4C      8C      8D      9H      9S      Two Pairs
	3D      3S      9C      9D      10S     Two Pairs
	3H      4D      8H      KD      KH      One Pair
	5D      7C      7H      KS      AD      One Pair

Error Code: 0

This output is expected.

}

11. {
Test four of a kind, flush, three of a kind, and high card

	Input file (comparison_2.txt): [

		8s ad 6s 5h AC 6C Jh

		5s 2s  qd  5C 7C kh 8C  kD 4s 

		3C 2C  KC 10C 7s 9c 4C  8D as

		QC 2h  6D  JC 7D 4D 9D  3D ks 

		qs 2D 10h  6h 7h 8h 9h  5D 3s 

		Qh jd  Ah 4h 10S 3h 9s 10D js

	]

"CardDeck comparison_2.txt"
Produces:
	DECK before dealing:
	8S AD 6S 5H AC 6C JH 5S 2S QD 5C 7C KH
	8C KD 4S 3C 2C KC 10C 7S 9C 4C 8D AS QC
	2H 6D JC 7D 4D 9D 3D KS QS 2D 10H 6H 7H
	8H 9H 5D 3S QH JD AH 4H 10S 3H 9S 10D JS

	DECK after dealing:
	8S AD 6S 5H AC 6C JH

	HANDS:
	3S      4S      JS      KS      AS
	3D      5D      8D      10D     KD
	4C      8C      9D      9H      9S
	3H      4D      8H      9C      KH
	7C      7D      7H      7S      10S
	4H      5C      6H      10C     JC
	6D      10H     QD      KC      AH
	2C      2D      2H      2S      JD
	3C      5S      QC      QH      QS

	HANDS sorted by less than operator:
	2C      2D      2H      2S      JD
	3C      5S      QC      QH      QS
	3D      5D      8D      10D     KD
	3H      4D      8H      9C      KH
	3S      4S      JS      KS      AS
	4C      8C      9D      9H      9S
	4H      5C      6H      10C     JC
	6D      10H     QD      KC      AH
	7C      7D      7H      7S      10S

	HANDS sorted by Poker ranking:
	7C      7D      7H      7S      10S     Four of a Kind
	2C      2D      2H      2S      JD      Four of a Kind
	3S      4S      JS      KS      AS      Flush
	3D      5D      8D      10D     KD      Flush
	3C      5S      QC      QH      QS      Three of a Kind
	4C      8C      9D      9H      9S      Three of a Kind
	6D      10H     QD      KC      AH      High Card
	3H      4D      8H      9C      KH      High Card
	4H      5C      6H      10C     JC      High Card
Error Code: 0

This output is expected.

}

12. {
Test straight flush

	Input file (comparison_3.txt): [

		8s ad 6s 4h AC 6C Jh

		5s 2s  qd  7h 7C kh 8C  4D 10s 

		3C 2C  KC 8h 7s 9c 4C  6D as

		QC 2h  8D  9h 10D kD 9D 3D ks 

		3s 2D 10h  6h 5C 10C JC  5D qs 

		Qh jd  Ah  5h 4S 3h 9s 7D js

	]

"CardDeck comparison_3.txt"
Produces:
	DECK before dealing:
	8S AD 6S 4H AC 6C JH 5S 2S QD 7H 7C KH
	8C 4D 10S 3C 2C KC 8H 7S 9C 4C 6D AS QC
	2H 8D 9H 10D KD 9D 3D KS 3S 2D 10H 6H 5C
	10C JC 5D QS QH JD AH 5H 4S 3H 9S 7D JS

	DECK after dealing:
	8S AD 6S 4H AC 6C JH

	HANDS:
	10S     JS      QS      KS      AS
	3D      4D      5D      6D      7D
	4C      8C      9D      9S      JC
	3H      9C      10C     KD      KH
	4S      5C      7C      7S      10D
	5H      6H      7H      8H      9H
	8D      10H     QD      KC      AH
	2C      2D      2H      2S      JD
	3C      3S      5S      QC      QH

	HANDS sorted by less than operator:
	2C      2D      2H      2S      JD
	3C      3S      5S      QC      QH
	3D      4D      5D      6D      7D
	3H      9C      10C     KD      KH
	4C      8C      9D      9S      JC
	4S      5C      7C      7S      10D
	5H      6H      7H      8H      9H
	8D      10H     QD      KC      AH
	10S     JS      QS      KS      AS

	HANDS sorted by Poker ranking:
	10S     JS      QS      KS      AS      Straight Flush
	5H      6H      7H      8H      9H      Straight Flush
	3D      4D      5D      6D      7D      Straight Flush
	2C      2D      2H      2S      JD      Four of a Kind
	3C      3S      5S      QC      QH      Two Pairs
	3H      9C      10C     KD      KH      One Pair
	4C      8C      9D      9S      JC      One Pair
	4S      5C      7C      7S      10D     One Pair
	8D      10H     QD      KC      AH      High Card
Error Code: 0

This output is expected.

}

13. {

	Input file (comments.txt): [

		2d 3d 4d 5d 6d // straight flush
		7d 3d 4d 5d 6d// straight flush
		7d 8d 4d 5d 6d// straight flush


		2d 3d 4s 5s 6c// straight
		7d 3d 4s 5s 6c// straight
		7d 8d 4s 5s 6c// straight

		 

		2d 3d 4s 5s 7c // no rank (king high)
		2d 3d 4s 5s 8c// no rank (king high)
		2d 3d 4s 5s 9c // no rank (king high)

	]

"CardDeck comments.txt"
Produces:
	DECK before dealing:
	2D 3D 4D 5D 6D 7D 3D 4D 5D 6D 7D 8D 4D
	5D 6D 2D 3D 4S 5S 6C 7D 3D 4S 5S 6C 7D
	8D 4S 5S 6C 2D 3D 4S 5S 7C 2D 3D 4S 5S
	8C 2D 3D 4S 5S 9C

	DECK after dealing:


	HANDS:
	2D      4S      5D      8D      9C
	3D      4D      5S      7C      7D
	2D      3D      4S      5S      6C
	3D      4S      5S      6D      7D
	2D      3D      4S      5D      6D
	2D      3D      4D      5D      8C
	4D      5S      6C      7D      8D
	3D      4S      5S      6C      7D
	2D      3D      4S      5S      6D

	HANDS sorted by less than operator:
	2D      3D      4D      5D      8C
	2D      3D      4S      5D      6D
	2D      3D      4S      5S      6C
	2D      3D      4S      5S      6D
	2D      4S      5D      8D      9C
	3D      4D      5S      7C      7D
	3D      4S      5S      6C      7D
	3D      4S      5S      6D      7D
	4D      5S      6C      7D      8D

	HANDS sorted by Poker ranking:
	4D      5S      6C      7D      8D      Straight
	3D      4S      5S      6D      7D      Straight
	3D      4S      5S      6C      7D      Straight
	2D      3D      4S      5S      6D      Straight
	2D      3D      4S      5D      6D      Straight
	2D      3D      4S      5S      6C      Straight
	3D      4D      5S      7C      7D      One Pair
	2D      4S      5D      8D      9C      High Card
	2D      3D      4D      5D      8C      High Card
Error Code: 0

This output is expected.

}

EXTRA CREDIT:

A.8-A.9:
	In CardDeck.cpp, in my main function, I handle all run functions in a large try catch to ensure that all exceptions are caught. When a function is run it always catches those exceptions, and all unknown exceptions are also made to be caught as well, using catch(...).
A.12-A.15:
	All pointers in my code are used within the parameters available. Functions that require iterators for vectors use begin() and end(), ensuring that it can only iterate within the vector that it is given and not outside. Pointer arithmetic is also watched to ensure that it does not go out of bounds. 
	Variable length character sets are stored in strings, for example when used as arguments for my code. Other variable length items are held in vectors.
A.16:
	When debugging I put breakpoints where the code failed last. Then I look from there and move through code to find the point at which it fails. Sometimes this involves me looking through the Main Debugger, but sometimes I can just put print statements where I need them to see where the code went wrong.
B10.B12:
	Items appear in the order that they appear in the class. Initializations happen in the order that they are declared. Constructors are all called in the constructor body instead of in the constructor itself
B.18:
	No parts of my classes do not need to be protected from copy, so all parts of the class are put into the copy constructor. I do not need to protect from this because it does not matter in this case, I actually do need things like rank and poker rank to copy over.
B.31:
	Instead of using header guards, I use #pragma once to protect my headers. I felt like this was a cleaner way of handling my headers, although it is not standard.