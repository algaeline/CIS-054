#include <iostream>
#include "rational.h"
using namespace std;

// ================================================
// Function: test_rational
// Purpose:  test Rational class
// Description: Please do not change the code
// Author: Monza Lui
// ================================================
void test_rational(const Rational& base, const Rational& user_input) {
	cout << user_input << " + " << base << " = " << (user_input + base) << endl; 
	cout << user_input << " - " << base << " = " << (user_input - base) << endl; 
	cout << user_input << " * " << base << " = " << (user_input * base) << endl; 
	cout << user_input << " / " << base << " = " << (user_input / base) << endl;  
	cout << user_input << " == " << base << " : "; 
		(user_input == base) ? cout << "true\n" : cout << "false\n";
	cout << user_input << " < " << base << " : ";  
		(user_input < base) ? cout << "true\n" : cout << "false\n";
	cout << user_input << " <= " << base << " : "; 
		(user_input <= base) ? cout << "true\n" : cout << "false\n";
	cout << user_input << " > " << base << " : ";  
		(user_input > base) ? cout << "true\n" : cout << "false\n";
	cout << user_input << " >= " << base << " : "; 
		(user_input >= base) ? cout << "true\n" : cout << "false\n"; 

}

// ====================================
// CONSTRUCTORS
// ====================================
Rational::Rational(int num, int den) {
	numerator = num;
	denominator = den;
	normalize();
}

Rational::Rational(int whole_number) {
	numerator = whole_number;
	denominator = 1;
	normalize();
}

Rational::Rational() {
	numerator = 0;
	denominator = 1;
	normalize();
}

// ================================================
// Other functions:
// ================================================
int Rational::gcd(int a, int b) {
	if(b == 0)
		return a;
	return gcd(b, a % b);
}


void Rational::normalize() {
	int gcd_temp = gcd(numerator, denominator);
	numerator = numerator / gcd_temp;
	denominator = denominator / gcd_temp;

	// should denominator be negative, the negative sign is moved to the numerator
	if(denominator < 0) {
		denominator = -denominator;
		numerator = -numerator;
	}
}

// ================================================
// Overload operand functions:
// ================================================
istream& operator >>(istream& ins, Rational &amount) {
	return ins >> amount.numerator >> amount.symbol >> amount.denominator;
}
ostream& operator <<(ostream& outs, const Rational& amount) {
	if(amount.denominator == 1) {
		// takes into consideration if the rational number is a whole number
		return outs << amount.numerator;
	} else if (amount.denominator == 0) {
		// takes into consideration if the rational number is invalid
		return outs << "N/A";
	} else {
		return outs << amount.numerator << amount.symbol << amount.denominator;
	}
}

// ================================================
// Overload comparison functions:
// ================================================
bool operator ==(const Rational& integer1, const Rational& integer2) {
	if(integer1.denominator == 0 || integer2.denominator == 0)
		return false;
	return (integer1.numerator * integer2.denominator == integer1.denominator * integer2.numerator);
}
bool operator <(const Rational& integer1, const Rational& integer2) {
	if(integer1.denominator == 0 || integer2.denominator == 0)
		return false;
	return (integer1.numerator * integer2.denominator) < (integer1.denominator * integer2.numerator);
}
bool operator <=(const Rational& integer1, const Rational& integer2) {
	if(integer1.denominator == 0 || integer2.denominator == 0)
		return false;
	return (((integer1.numerator * integer2.denominator) < (integer1.denominator * integer2.numerator)) || ((integer1.numerator * integer2.denominator) == (integer1.denominator * integer2.numerator)));
}
bool operator >(const Rational& integer1, const Rational& integer2) {
	if(integer1.denominator == 0 || integer2.denominator == 0)
		return false;
	return (integer1.numerator * integer2.denominator) > (integer1.denominator * integer2.numerator);
}
bool operator >=(const Rational& integer1, const Rational& integer2) {
	if(integer1.denominator == 0 || integer2.denominator == 0)
		return false;
	return (((integer1.numerator * integer2.denominator) > (integer1.denominator * integer2.numerator)) || ((integer1.numerator * integer2.denominator) == (integer1.denominator * integer2.numerator)));
}
Rational operator +(const Rational& integer1, const Rational& integer2) {
	int tempNum = integer1.numerator * integer2.denominator + integer2.numerator * integer1.denominator;
	int tempDen = integer1.denominator * integer2.denominator;
	return Rational(tempNum, tempDen);
}
Rational operator -(const Rational& integer1, const Rational& integer2) {
	int tempNum = integer1.numerator * integer2.denominator - integer2.numerator * integer1.denominator;
	int tempDen = integer1.denominator * integer2.denominator;
	return Rational(tempNum, tempDen);
}
Rational operator *(const Rational& integer1, const Rational& integer2) {
	int tempNum = integer1.numerator * integer2.numerator;
	int tempDen = integer1.denominator * integer2.denominator;
	return Rational(tempNum, tempDen);
}
Rational operator /(const Rational& integer1, const Rational& integer2) {
	int tempNum = integer1.numerator * integer2.denominator;
	int tempDen = integer1.denominator * integer2.numerator;
	return Rational(tempNum, tempDen);
}