#include <iostream>
#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
public:
	int numerator, denominator;
	char symbol = '/';

	// ================================================
	// Constructors
	// ================================================
	// initializes the rational amount with the numerator and denominator given by the
	// arguments. 
	Rational(int num, int den);
	// initializes the object as a whole number, with the numerator equal to the argument
	// and the denominator equal to 1.
	Rational(int whole_number);
	// initializes the object so that its value represents 0.
	Rational();

	// ================================================
	// Other functions
	// ================================================

	// ================================================
	// Function: gcd(int a, int b)
	// Purpose: The function finds the greatest common denominator
	// of two integers. This is used for the numerator and 
	// denominator of a rational function so as to simplify it.
	// **It is a recursive function.
	// Parameters: 
	// int a and b are two declared integers
	// ================================================
	int gcd(int a, int b);

	// ================================================
	// Function: normalize()
	// Purpose: The function simplifies the rational fractions and
	// the negative signs, should the dnominator be negative.
	// Calls: gcd()
	// ================================================
	void normalize();

	// ================================================
	// Overload functions
	// ================================================
	friend istream& operator >>(istream& ins, Rational &amount);
	friend ostream& operator <<(ostream& outs, const Rational& amount);

	// Precondition for all: integer1 and integer2 have given values.
	// The operator functions are compared by using the individual
	// numerators and denominators to create the final result.
	friend bool operator ==(const Rational& integer1, const Rational& integer2);
	friend bool operator <(const Rational& integer1, const Rational& integer2);
	friend bool operator <=(const Rational& integer1, const Rational& integer2);
	friend bool operator >(const Rational& integer1, const Rational& integer2);
	friend bool operator >=(const Rational& integer1, const Rational& integer2);
	friend Rational operator +(const Rational& integer1, const Rational& integer2);
	friend Rational operator -(const Rational& integer1, const Rational& integer2);
	friend Rational operator *(const Rational& integer1, const Rational& integer2);
	friend Rational operator /(const Rational& integer1, const Rational& integer2);

private:
	// ================================================
	// Function: test_rational
	// Purpose:  test Rational class
	// Description: Please do not change the code
	// Author: Monza Lui
	// ================================================
	friend void test_rational(const Rational& base, const Rational& user_input);
	// normalize the integers that represent the rational number
};

#endif