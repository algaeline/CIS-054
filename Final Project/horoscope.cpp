// File: horoscope.h
// Purpose: Implementation file for ZodiacSign, Horoscope, and Person classes.
// Author & copyright:	Monza Lui
// Date:	Dec 2, 2019
#include <iostream>
#include <string>
#include "horoscope.h"
using namespace std;

// ================= PERSON CLASS =================
Person::Person(string the_name, int bmonth, int bday, const Horoscope& the_orcale) {
	name = the_name;
	birthday = bday;
	birthmonth = bmonth;
	sign = the_orcale.get_sign_n_cusp(bmonth, bday, cusp);
}
bool compatible(const Person& p1, const Person& p2) {
	return compatible(p1.sign, p2.sign);
}
void Person::print_person() {
	cout << name << " is a " << sign.get_name() << ". ";
	if (!cusp.get_name().empty()) {
		cout << "He/she is also a cusp of " << cusp.get_name() << ". ";
	}
	cout << endl;
}
void print_compatible(const Person& p1, const Person& p2) {
	cout << p1.name << " is ";
	if (!compatible(p1,p2)) { cout << "not ";}
	cout << "compatible with ";
	cout << p2.name << ".\n";
}


// ================= ZODIACSIGN CLASS =================

ZodiacSign::ZodiacSign(const string& sign_name, string sign_element) {
	name = sign_name;
	element = sign_element;
	//cout << "creating " << name << ", " << element << endl;
}
ZodiacSign::ZodiacSign() {
	// do nothing
}
bool compatible(const ZodiacSign& s1, const ZodiacSign& s2) {
	//cout << s1.element << " and " << s2.element << endl;
	return (s1.element == s2.element);
}
string ZodiacSign::get_name() const {
	return name;
}
string ZodiacSign::get_element() const {
	return element;
}

// ================= HOROSCOPE CLASS =================
// Added Ophiuchus and changed first days
const string Horoscope::SignName[14] = {"SAGITTARIUS", "CAPRICORN", "AQUARIUS", "PISCES", "ARIES", "TAURUS", "GEMINI", "CANCER", "LEO", "VIRGO", "LIBRA", "SCORPIO", "OPHIUCHUS", "SAGITTARIUS"};
const int Horoscope::FirstDay[15] = {0, 21, 48, 72, 110, 135, 174, 203, 224, 261, 305, 329, 335, 353, 366};
const string Horoscope::ElementName[4] = { "Fire", "Earth", "Air", "Water" }; 

Horoscope::Horoscope() {
	for (int i=0; i < 12; i++) {
		signs[i] = ZodiacSign(SignName[i], ElementName[i%4]);
	}
	// Added special cases for Ophiuchus
	signs[12] = ZodiacSign(SignName[12], ElementName[3]);
	signs[13] = ZodiacSign(SignName[13], ElementName[0]);
}
int Horoscope::day_of_year(int month, int day) const{
	int month_length[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int day_of_year = 0;
	for (int i = 0; i < month - 1; i++) {
		day_of_year += month_length[i];
	}
	day_of_year += day;
	//cout << "day of year " << day_of_year << endl;
	return day_of_year;
}

ZodiacSign Horoscope::get_sign_n_cusp(int month, int day, ZodiacSign& cusp_sign) const {
	int day_of_year_born = day_of_year(month, day);
	int i;
	int cusp_index = -1;
	for (i=0; i < 14; i++) {
		//cout << "index is " << i << endl;
		if ((day_of_year_born < 363) && (FirstDay[i] <= day_of_year_born) && (day_of_year_born < FirstDay[i+1])) {
			if (day_of_year_born > 363 || day_of_year_born < 3)
				break;
			if (day_of_year_born - FirstDay[i] < 2) {
				//cout << "in cusp\n";
				cusp_index = (i == 0) ? 11 : i-1; 
				cusp_sign = signs[cusp_index];
			} else if (FirstDay[i+1] - day_of_year_born <= 2) {
				cusp_index = (i == 12) ? 0 : i+1;
				cusp_sign = signs[cusp_index];
			}
			break;
		}
	}
	//cout << " sign index is " << i << endl;
	//cout << " cusp index is " << cusp_index << endl;
	if(day_of_year_born > 363 || day_of_year_born < 3)
		i = 13;
	return signs[i];
}