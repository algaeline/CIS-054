#include <iostream> 
#include <ctime>
#include "queue.h"

using namespace std;

int main()
{
  int iteration = 1, counter = 1;

  Queue q;    
  long timestamp;

  do {
    cout << "Enter '1' to simulate a customer's arrival, '2' to help the next customer, or '3' to quit." << endl;
    try {
      cin >> iteration;
      // Invalid input
      if(cin.fail()) { 
        throw 0;
      }
      
      //Customer enters the queue
      if(iteration == 1) {
        timestamp = time(nullptr);
        q.add(counter, timestamp);
        counter++;
        
      // Customer leaves the queue
      } else if (iteration == 2) {
        q.remove();
      }

    // Throw an exception if the user does not input an integer
    // If not, program will loop infinitely
    } catch (...) {
      cout << "Invalid input." << endl;
      break;
    }
  } while (iteration != 3);

  return 0;
}

/* ==========================================================

Q1. Problems I had working on this assignment (and how I overcame these problems)
1. For some reason, using the variable 'helped' was difficult because it automatically
set itself to -13236 despite being set equal to 0 at declaration. I tried to debug
the issue but was unable to resolve its origin. I fixed it by deleting all occurrences
of the variable and trying again.

2. One of my problems was implementing the try-throw-catch loop in the program. 
To create a new one aside from Queue, I spent a lot of extra time figuring out 
what uncommon  or problematic errors should throw an exception. While testing 
boundary cases, I then realized that invalid inputs would cause the do-while loop
to repeat infinitely.

Q2. My try-throw-catch block is at:
    main.cpp line 16
========================================================== */
