// Example program
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

// Class: CIS 054
// Assignment: 5-1 Giving Change
// Name: Angeline Lee
// Date: 10/06/19

//compute_coins() takes in the coin value, 
void compute_coins(int coin_value, int& num, int& amount_left) {
  //while loop checks if the current coin_value > amount_left
  //e.g. if remaining coin_value < 25 then end loop so that 
  //compute_coins() can be called for nickels
    while (amount_left >= coin_value) {
        num++;
        amount_left -= coin_value;
    }
}

//output_coins() assumes that num will never be negative
void output_coins(int coin_value, int num){
    //switch cases are based on the coin_value, meaning they can only be 1, 10, 25
    switch(coin_value) {
        case 1: {
          //if plural
          if(num > 1) {
            cout << num << " Pennies\n";
          } else if(num == 0) {
            return;
          } else {
            cout << num << " Penny\n";
          }
        break;
        case 10: 
          //if plural
          if(num > 1) {
            cout << num << " Dimes\n";
          } else if(num == 0) {
            return;
          } else {
            cout << num << " Dime\n";
          }
        break;
        //default case for quarters 
        default: 
          //if plural
          if(num > 1) {
            cout << num << " Quarters\n";
          } else if(num == 0) {
            return;
          } else {
            cout << num << " Quarter\n";
          }
        }
    }
}

int main()
{
  //Variable
  char repeat;

  //starter message
  cout << "Hello I am the coin machine! I will give you the least number of coins for your change.\n";

  do {
    //Variables
    int cents_remaining, quarters = 0, dimes = 0, pennies = 0;

    //User Input
    cout << "How many cents of change do you need? (Please enter from 1 to 99) \n";
    cin >> cents_remaining;

    //Failure Conditions
    if (cents_remaining < 0) {
        cout << "You are welcome to give me money! Otherwise please enter a number from 1 to 99.\n";
        repeat = 'y';
    } else if (cents_remaining > 99) {
        cout << "Sorry I can only give out less than 1 dollar of change.\n";
        repeat = 'y'; 
    } else if (cents_remaining == 0) {
        cout << "Sorry there is no change to give back.\n";
        cout << "Want to get change again?\n";
        cout << "Type y to continue or any other key to terminate the program.\n";
        cin >> repeat;
    } else {

        //Computations
        compute_coins(25, quarters, cents_remaining);
        compute_coins(10, dimes, cents_remaining);
        compute_coins(1, pennies, cents_remaining);

        //Result
        output_coins(25, quarters);
        output_coins(10, dimes);
        output_coins(1, pennies);

        //Output
        cout << "Want to get change again?\n";
        cout << "Type y to continue or any other key to terminate the program.\n";
        cin >> repeat;
    }
  } while ( repeat == 'Y' || repeat == 'y');
}

/*
==============================================================================
Problems I had working on this assignment (and how I overcame these problems)

1. One of the issues I had was that I initially used "printf()" instead of cout
in the output_coins function. I had trouble using the to_string function because
there were complications with "std::". Therefore, I switched to using cout as usual.

2. At first, I wasn't sure how I should implement the different results for the
various scenarios of input == 0, input > 99, and input < 0. I wanted to use a 
switch-statement but further research showed me that it wasn't practical to rely
on range-based switch-statements. I used if-statements instead.

==============================================================================
*/
