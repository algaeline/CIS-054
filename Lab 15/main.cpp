#include <iostream>
#include "player.h"
using namespace std;

// Class: CIS 054
// Assignment: 15-1 Number Guessing Game
// Name: Angeline Lee
// Date: 12/11/19

int main() {
    HumanPlayer human1, human2;
    ComputerPlayer cpu1, cpu2;

    cout << "Starting human v. human game: \n";
    human1.play(human1, human2); 

    cout << "\nStarting computer v. human game: \n";
    cpu1.play(cpu1, human1); 

    cout << "\nStarting computer v. computer game: \n";
    cpu1.play(cpu1, cpu2);
}

/* ==========================================================

Q1. Problems I had working on this assignment (and how I overcame these problems)

1. One of my biggest problems was implementing a valid input check for get_guess(). 
I struggled deciding between a while loop or do-while loop and how to check for
failure cases. I hadn't realized that while(!(cin >> guess)) would automatically
create another input stream, so I also included a cin >> guess within the loop. I
later discovered this was the reason why the user would be prompted multiple times
before the program registered the input.

2. Another issue I had with the program was using the play() function. I later discovered
that it has to be called by an existing Player object.
========================================================== */