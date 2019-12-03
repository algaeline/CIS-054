// ===========================================================================
// Purpose:	Test program for lab12-2 TemperatureList Class with Dynamic Array
// Author: 	Monza Lui
// ===========================================================================

// Class: CIS 054
// Assignment: 12-1 TemperatureList Class with Dynamic Array
// Name: Angeline Lee
// Date: 11/26/19

#include <iostream>
#include "templist.h"
using namespace std;

int main() {
	TemperatureList temp_a(50);

	temp_a.add_temperature(23.5);
	temp_a.add_temperature(24.6);
	cout << temp_a;

	TemperatureList temp_b = temp_a;
	cout << temp_b;

	temp_a = TemperatureList();
	cout << "Now there's no temperatures in a.\n";
	cout << temp_a;
	cout << "How about temperatures in b?\n";
	cout << temp_b;

	return 0;
}

/* ==========================================================
Problems I had working on this assignment (and how I overcame these problems)

1. One of my greatest difficulties was compiling th efiles. When using
g++, I came across the issue of "multiple definitions" for my methods. 
However, running the templist.cpp implementations within templist.h was
successful, so I assumed my implementations were correct.

2. Another issue I had in the beginning was creating an int dynamic array. 
This severely complicated the results for temp_b, whose temperature elements
were jumbled in an attempt to copy it from temp_a.

========================================================== */