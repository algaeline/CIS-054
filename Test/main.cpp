/*
Purpose: Original astrology program for final project

Write an astrology program. The user types in a birthday, and the program
responds with the sign and horoscope for that birthday. The month may
be entered as a number from 1 to 12. Then enhance your program so
that if the birthday is only one or two days away from an adjacent sign,
the program announces that the birthday is on a “cusp” and also outputs
the horoscope for that nearest adjacent sign. This program will have a
long multiway branch. Make up a horoscope for each sign. Your program
should include a loop that lets the user repeat this calculation until the user
says she or he is done.
The horoscope signs and dates are:
Aries March 21–April 19 (day 81 - 110)
Taurus April 20–May 20 (day 111 - 141)
Gemini May 21–June 21 (day 142 - 173)
Cancer June 22–July 22 (day 174 - 204)
Leo July 23–August 22 (day 205 - 235)
Virgo August 23–September 22 (day 236 - 266)
Libra September 23–October 22 (day 267 - 296)
Scorpio October 23–November 21 (day 297 - 326)
Sagittarius November 22–December 21 (day 327 - 356)
Capricorn December 22–January 19 (day 357 - 19)
Aquarius January 20–February 18 (day 20 - 49)
Pisces February 19–March 20 (day 50 - 80)

Horoscope Signs of the same Element are most compatible. There are 4
Elements in astrology, and 3 Signs in each: FIRE (Aries, Leo, Sagittarius),
EARTH (Taurus, Virgo, Capricorn), AIR (Gemini, Libra, Aquarius) , WATER
(Cancer, Scorpio, Pisces).
According to some astrologers, you are most comfortable with your own sign
and the other two signs in your Element. For example, Aries would be most
comfortable with other Aries and the two other FIRE signs, Leo and Sagittarius.
Modify your program from Practice Program 3 to also display the name of
the signs that will be compatible for the birthday.

Author & copyright:	Monza Lui
Date:	Dec 2, 2019
*/


#include <iostream>
#include <string>
#include "horoscope.h"
using namespace std;

int main() {
	Horoscope oracle;
	ZodiacSign s, c;
	int month1, day1, month2, day2;
	string name1, name2;

	// USER INPUT
	cout << "Enter your name: ";
	cin >> name1;
	cout << "Enter your birthday (month day): ";
	cin >> month1 >> day1;

	cout << "Enter your friend's name: ";
	cin >> name2;
	cout << "Enter his/her birthday (month day): ";
	cin >> month2 >> day2;

	Person a(name1, month1, day1, oracle);
	Person b(name2, month2, day2, oracle);
	a.print_person();
	b.print_person();
	print_compatible(a, b);


	return 0;
}

