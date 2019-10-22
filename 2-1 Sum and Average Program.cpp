// Example program
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

// Class: CIS 054
// Assignment: 2-1 Sum and Average Program
// Name: Angeline Lee
// Date: 9/15/19

int main()
{
  //Integer Variables for Sums
  int x, posSum = 0, negSum = 0, sum = 0;
  //Double Variables for Counts and Averages
  double count = 0, posCount = 0, negCount = 0, avg, posAvg, negAvg;
  
  //User Input
  cout << "Enter 10 integers separated by spaces.\n ";
  cout << "Press enter to calculate.\n ";
  while (count < 10) {
      std::cin >> x;
      sum = sum + x;
      count += 1.0;
      
      //Positive Numbers
      if (x >= 0) {
          posSum += x;
          posCount += 1.0;
      }
      //Negative Numbers
      if (x < 0) {
          negSum += x;
          negCount += 1.0;
      }
      
  } 
  
  //Calculations
  posAvg = posSum / posCount;
  negAvg = negSum / negCount;
  avg = sum / 10.0;
    
    
  //Output
  cout << fixed;

  if (posCount == 0) {
      cout << "Positive Average: N/A";
      cout << " Positive Sum: N/A";
  } else {
      cout << "Positive Average: " << setprecision(2) << posAvg;
      cout << " Positive Sum: " << posSum << std::endl;
  }
  if (negCount == 0) {
      cout << "Negative Average: N/A";
      cout << " Negative Sum: N/A" << endl;
  } else {
      cout << "Negative Average: " << setprecision(2) << negAvg;
      cout << " Negative Sum: " << negSum << endl;
  }

  cout << "Total Average: " << setprecision(2) << avg;
  cout << " Total Sum: " << sum << endl;
  
}

/*
==============================================================================
Problems I had working on this assignment (and how I overcame these problems)

1. One of the issues I had with this assignment were that averages were equal 
to 0 even when there were no positive or negative numbers. I fixed this issue
by including an if-else statement so that the averages are equal to "N/A" when
no such numbers exist.

2. A problem I forgot to address was that the program was giving me an error
if I forgot to use "std::" before each command. I overcame the issue by going 
online and finding that I could substitute the statement by including "using
namespace std;" at the beginning of the program.

==============================================================================
*/