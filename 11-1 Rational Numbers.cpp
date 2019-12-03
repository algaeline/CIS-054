// ======================================================================
// Title: 	Rational Class Test program for lab 11
// Author: 	Monza Lui
// Date:	Nov 9, 2019
// ======================================================================

#include <iostream>
using namespace std;

// Class: CIS 054
// Assignment: 11-1 Rational Numbers
// Name: Angeline Lee
// Date: 11/17/19

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

// ================================================
// Function: main
// Purpose:  run test on Rational class
// Description: Please do not change the code
// Author: Monza Lui
// ================================================
int main() {

	Rational b(1,2);
	Rational a;
	cout << "Welcome to the Rational World of Wonders!\n";
	cout << "Please enter a rational number for this calculation:\n";
	cin >> a;

	test_rational(b, a);

	return 0;
}

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

/* ==========================================================

Problems I had working on this assignment (and how I overcame these problems)

1. One problem I had working on this assignment was that the
overriden ostream operator would not work. I discovered that
this was due to a difference in the function declarations at
the start and the end of the file.

2. Another problem I had was that the operators would not 
return proper results. I had been returning the Rational class
without calling the constructor. Therefore, the function was 
not receiving the proper output that it had expected.

========================================================== */