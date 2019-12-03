// Example program
#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
using namespace std;

// Class: CIS 054
// Assignment: 10-1 Sum and Average Program
// Name: Angeline Lee
// Date: 11/12/19

// =========================================================
// Class: DayOfWeek
// Purpose: define a class to represent a day of the week
// =========================================================
class DayOfWeek {
        int day;
        string input;
        // constant string of first three letters per weekday to extract upon calling constructor
        const string weekdays[7] = {"mon", "tue", "wed", "thu", "fri", "sat", "sun"};

    public:
        // --- constructors ---
        DayOfWeek(string input);
        DayOfWeek(int input);
        //default
        DayOfWeek();

        // --- getters ---
        // returns the current day
        int get_day();

        // --- setters ---
        //sets the current day
        void set_day(int n);

        // --- other functions ---
        // directly takes cin to perform the input function and other functions, 
        // such as printing the input message
        void read_day(istream& ins);
        // directly takes cout so that it can output the default result
        void print_day(ostream& outs);

        // --- member functions ---
        // uses set day to set the current day to the next
        // if day is at the end of the week, it uses mod in order to reset the week following day 7
        void next_day(int prevDay);
        // bridges the constructor and read_day()
        // performs both of their required functionalities using the const weekdays array and compare()
        void set_day_by_string(string input);

        // --- helper functions ---
        // ensures that the current day is some day from 1 to 7
        bool validate_day();

};

int main() {
    DayOfWeek firstDay;
    firstDay.print_day(cout);

    return 0;
}

void DayOfWeek::read_day(istream& ins) {
    //welcome message
    cout << "Welcome to the Day of Week Program!\n";
    cout << "Please input the first three letters of the day that you would like to return.\n";
    // same performance as using "cin"
    ins >> input;  
    //calls set_day_by_string() to indirectly act as constructor(string)
    set_day_by_string(input);
}

void DayOfWeek::print_day(ostream& outs) {
    int count = 0;

    //ensure that the day lies somewhere in the week from days 1 to 7
    if(!validate_day()) {
      outs << "This is not a valid day of the week.";
    } else {
        //when count = 7, the week has finished printing
        while (count < 7) {
            //output message
            outs << "This is day " << get_day() << " of the week.\n";
            next_day(day);
            count++;
        }
    }
}

void DayOfWeek::next_day(int prevDay) {
    if (day % 7 == 0){
      set_day(1);
    } else {
      set_day(prevDay + 1);
    }
}

DayOfWeek::DayOfWeek(){
    set_day(0);
    read_day(cin);
}

DayOfWeek::DayOfWeek(string input) {
    set_day(0);    
    set_day_by_string(input);
}

DayOfWeek::DayOfWeek(int input) {
    //invalid input
    if (input < 1 || input > 7) {
        set_day(0);
    } else { 
        set_day(input);
    }
}

int DayOfWeek::get_day() {
    return day;
}

void DayOfWeek::set_day(int n) {
    day = n;
}

void DayOfWeek::set_day_by_string(string input) {   
    string temp = input;

    //make all inputs lowercase to maintain consistency and read both capital and lowercase
    for(int i = 0; i < temp.length(); i++) {
      temp[i] = tolower(temp[i]);
    }

    for(int i = 0; i < 7; i++) {
        // struggled here, cannot use "==" but compare() to compare two strings
        if(weekdays[i].compare(temp) == 0)
            set_day(i + 1);
    }
}

bool DayOfWeek::validate_day() {
  if (day < 1 || day > 7) {
      return false;
  } else {
    return true;
  }
}

/*
==============================================================================
Problems I had working on this assignment (and how I overcame these problems)

1. One of the issues I had was reading the user input and comparing it to the
elements of const string weekdays. I discovered the reason why was because
I failed ot use the string function compare(), instead using ==, which cannot
compare strings.

2. A problem I had was bridging the input function read_day() and constructor
so that it would prompt the user for the input. This was difficult because I 
could not re-call the constructor. Instead, I fixed this by creating a new member
function set_day_by_string() that could be called in the constructor as well as
the input function, thereby bridging the two functions together.

==============================================================================
*/