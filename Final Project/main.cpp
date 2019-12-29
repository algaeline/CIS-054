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

// Class: CIS 054
// Assignment: Final Project
// Name: Angeline Lee
// Date: 12/19/19

#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include "horoscope.h"
using namespace std;

// Purpose: return whether or not the dates are valid
bool valid_date(int month, int date) {
	
	// check for month boundaries
	if(month > 12 || month < 1) {
		return false;
	}

	// copied from the horoscope class to ensure that maximum days matches respective month
	int month_length[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(date < 0 || date > month_length[month-1]) {
		return false;
	}
	return true;
}

// Purpose: call for user input for birthdays and only accept input if it meets all qualifications
// Postcondition: a valid input is accepted
// Calls: valid_input()
void birthday_reader(string who, string input, int &month, int &day) {
    bool firstIter = true;
	while(true) {
		cout << "Enter " << who << " birthday (month day): ";

		// fixes error - skips first input
		// ignore false cin
		if(firstIter) {
			cin.ignore(256, '\n');
			firstIter = false;
		}
		getline(cin, input);
		
		istringstream is(input);
		bool rejectInput = false, rejectDate = false, hasOneSpace = false;
		
		// for loop checks that the proper format is followed
		// e.g. digits and a space in between
		for(int i = 0; i < input.length() && !rejectInput; i++) {

			if(isdigit(input[i]))
				continue;

			if(input[i] == ' ' && hasOneSpace == false){
				hasOneSpace = true;
				continue;
			}
			rejectInput = true;
		}

		// if input is valid, use istringstream to re-input the entire line into separate variables
		if(!rejectInput)
			is >> month >> day;

		// check if the dates are valid
		// e.g. 1 <= month <= 12 and correct date per specified month
		if(!valid_date(month, day))
			rejectDate = true;
		
		//cout << month << " " << day;

		// if both qualifications are met, the program can proceed
		if(!rejectInput && !rejectDate)
			break;
	}

}

int main() {
	Horoscope oracle;
	ZodiacSign s, c;
	int month1, day1, month2, day2;
	string name1, name2, monthday1, monthday2;

	// USER INPUT
	cout << "Enter your name: ";
	cin >> name1;
	// cout << "Enter your birthday (month day): ";
	// cin >> month1 >> day1;
	birthday_reader("your", monthday1, month1, day1);

	cout << "Enter your friend's name: ";
	cin >> name2;
	//cout << "Enter his/her birthday (month day): ";
	//cin >> month2 >> day2;
	birthday_reader("his/her", monthday2, month2, day2);

	Person a(name1, month1, day1, oracle);
	Person b(name2, month2, day2, oracle);

	a.print_person();
	b.print_person();
	print_compatible(a, b);


	return 0;
}

/* ==========================================================

Q1. Problems I had working on this assignment (and how I overcame these problems)
1. I had difficulty reading the input validity of the user. I initially attempted
to use a simple while(cin.fail) loop like previous assignments, but the multiple
inputs made it difficult. I decided to break down the input character-by-character.

2. Alongside reading the input, after using getline(), I struggled separating the
input. After thorough research, I decided that the most efficient method would be
utilizing an istringstream.

Q2. Did you find any problems in the original program?
The cusp did not account for the overlap between the end of the year to the beginning.
Therefore, an inputted date of dates near the end of the year would lead to an incorrect
cusp or exception.
========================================================== */

