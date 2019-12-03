
#include <iostream>
#include "rational.h"
using namespace std;

// Class: CIS 054
// Assignment: 11-1 Rational Numbers
// Name: Angeline Lee
// Date: 11/26/19

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

/* ==========================================================

Problems I had working on this assignment (and how I overcame these problems)

**There were no problems in performing the extra credit assignment.
It was like repeating the process done in lab 12.

1. One problem I had working on this assignment was that the
overriden ostream operator would not work. I discovered that
this was due to a difference in the function declarations at
the start and the end of the file.

2. Another problem I had was that the operators would not 
return proper results. I had been returning the Rational class
without calling the constructor. Therefore, the function was 
not receiving the proper output that it had expected.

========================================================== */