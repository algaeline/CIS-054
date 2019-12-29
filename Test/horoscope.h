// File: horoscope.h
// Purpose: Interface file for ZodiacSign, Horoscope, and Person classes.
// Author & copyright:	Monza Lui
// Date:	Dec 2, 2019

#ifndef HORO_H
#define HORO_H

#include <iostream>
#include <string>
using namespace std;

class ZodiacSign {
private:
	string name;
	string element;
public:
	// Postcondition: return whether s1 and s2 are compatible signs
	//				  2 signs are compatible if they are of the same element
	//				  e.g. Water signs are compatible with each other 
	friend bool compatible(const ZodiacSign& s1, const ZodiacSign& s2);
	// == Constructors ==
	ZodiacSign(const string& sign_name, string sign_element);
	ZodiacSign();
	// == Getters ==
	string get_name() const;
	string get_element() const;
};

class Horoscope {
private:
	// List of zodiac signs in the order that matches the FirstDay
	static const string SignName[];
	// List of the first day_of_year for each sign, corresponds to what's in SignName
	// We count from day 1 to day 366 (to accommodate people who are born on a leap year)
	static const int FirstDay[];
	// List of sign elements
	static const string ElementName[];
	ZodiacSign signs[13];
	// Postcondition: returns the day of year calculated from the month and day
	int day_of_year(int month, int day) const;
public:
	// == Constructor ==
	Horoscope();
	// Postcondition: 
	//   	1. returns the zodiac sign with the birth day and month
	//		2. passes back the cusp sign if any (the adjacent sign which is only 1 or 2 days away)
	// Calls: day_of_year
	ZodiacSign get_sign_n_cusp(int month, int day, ZodiacSign& cusp_sign) const;
};

class Person {
private:
	string name;
	int birthday;
	int birthmonth;
	ZodiacSign sign;
	ZodiacSign cusp;
public:
	// Postcondition: prints p1.name is compatible or not with p2.name
	friend void print_compatible(const Person& p1, const Person& p2);
	// Postcondition: returns if p1 is compatible with p2 (based on their sign element)
	friend bool compatible(const Person& p1, const Person& p2);
	// == Constructor ==
	Person(string the_name, int bmonth, int bday, const Horoscope& the_orcale);
	// Postcondition: prints the person's name and sign
	void print_person();
};

#endif