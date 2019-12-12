#include <iostream>
#include <cstdlib>
#include "player.h"
using namespace std;

Player::Player() {

}

bool Player::checkForWin(int guess, int answer) {
    cout<< "You guessed " << guess << ".";
    if (answer == guess) {
        cout<< "You’re right! You win!" <<endl;
        return true;
    }
    else if (answer < guess) {
        cout<< "Your guess is too high." <<endl;
    }
    else {
        cout<< "Your guess is too low." <<endl;
    }
    return false;
}

void Player::play(Player &player1, Player &player2) {
    int answer = 0, guess = 0;
    answer = rand() % 100;
    bool win = false;
    while (!win) {
        cout << "Player 1's turn to guess." <<endl;
        guess = player1.get_guess();
        win = checkForWin(guess, answer);
        if (win) return;
        cout << "Player 2's turn to guess." <<endl;
        guess = player2.get_guess();
        win = checkForWin(guess, answer);
    }
}

int Player::get_guess() {
    return 0;
}

int HumanPlayer::get_guess() {
    bool valid = false;

    while (!(cin>>guess) || guess < 0 || guess > 99) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Please enter an integer between 0 and 99.\n";
    }
    return guess;

}

int ComputerPlayer::get_guess() {
    return rand() % 100;
}