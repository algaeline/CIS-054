// Example program
#include <iostream>
using namespace std;

// Class: CIS 054
// Assignment: 4-1 Pull a Card
// Name: Angeline Lee
// Date: 9/29/19

int main()
{
  //Variables
  int value, suit;
  char repeat;
  
    do {
        //Randomly Generate Variable Values
        value = (rand() % 13) + 1;
        suit = (rand() % 4) + 1;

        //Initial Output
        cout << "Let's pull a card!\n";
        cout << "This time we got ";
  
        //13 Cases for A-K
        switch (value) {
            case 1: cout << "A";
            break;
            case 2: cout << "2";
            break;
            case 3: cout << "3";
            break;
            case 4: cout << "4";
            break;
            case 5: cout << "5";
            break;
            case 6: cout << "6";
            break;
            case 7: cout << "7";
            break;
            case 8: cout << "8";
            break;
            case 9: cout << "9";
            break;
            case 10: cout << "T";
            break;
            case 11: cout << "J";
            break;
            case 12: cout << "Q";
            break;
            default: cout << "K";
        }
        //4 Cases for Suits
        switch (suit) {
            case 1: cout << "H\n";
            break;
            case 2: cout << "S\n";
            break;
            case 3: cout << "C\n"; 
            break;
            default: cout << "D\n";
        }

        //Repeat Output
        cout << "Wanna pull a card again?\n";
        cout << "Type y to continue or any other key to terminate the program.";
        cin >> repeat;
      }
      while ( repeat == 'Y' || repeat == 'y');
    }

/*
==============================================================================
Problems I had working on this assignment (and how I overcame these problems)

1. Initially, my switch statements would not work. I realized this after going
through the lectures again and realized I forgot to include the "break"
statement following each case.

2. Another problem I had faced was that Iunsure of what to put in the default
case. Originally, I had 13 and 4 cases, respectively. I decided to solve my 
problem by removing the 13th and 4th case, and instead setting them as
default. Therefore, as the cards are randomly generated, any number greater 
than 13 or 4 would fall to the default case.

==============================================================================
*/
