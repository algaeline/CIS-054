// Example program
#include <iostream>
#include <iomanip>
using namespace std;
#include <cmath>

// Class: CIS 054
// Assignment: 3-1 Pi
// Name: Angeline Lee
// Date: 9/22/19

int main()
{
  //Variables
  double n, pi = 0;
  char repeat;
  int i, j = 0, k = 1;
  
  do {
  pi = 0;
  
  //User Input
  cout << "How many terms do you wanna compute pi to? ";
  cin >> n;
  
  //Calculations
  for (i = 0; i < n; i++) {
      pi = pi + (pow((-1), i) * 4 / (2 * i + 1));
  }
  //Output
  cout << scientific;
  cout << "Our pi: " << setprecision(10) << pi << endl;
  cout << "Do you want to compute pi again?\n";
  cout << "Type y to continue or any other key to terminate the program.";
  cin >> repeat;
  }
  while ( repeat == 'Y' || repeat == 'y');
}

/*
==============================================================================
Problems I had working on this assignment (and how I overcame these problems)

1. cpp.sh was not working for quite a while, and one of the issues I faced was 
realizing that. My code failed to work for a while.

2. A problem I had was implementing the use of the "pow" function because I 
had mismatched the value of i. Instead, the value I was supposed to use 
was i + or - 1.

==============================================================================
*/
