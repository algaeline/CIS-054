// Example program
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Class: CIS 054
// Assignment: 9-1 Sum and Average Program 2
// Name: Angeline Lee
// Date: 11/3/19

/* ===================================================================
Function: arraySizer()
Purpose: parse a given file and return element count to determine array size
Assumptions: 
(1) the file is valid
(2) arr_size is equal to zero
Parameters: 
(1) in_stream - a reference variable to the file to parse
(2) arr_size - a reference variable to the array_size of the array to be created
Precondition: arr_size is just an integer input
Postcondition: arr_size equals the number of elements in the array
======================================================================*/
void arraySizer(ifstream& in_stream, int& arr_size){
  int parse;
  
  while (in_stream >> parse){
    arr_size++;
  }
}

/* ===================================================================
Function: fileToArray()
Purpose: parse a given file and assign values to an array
Assumptions:
(1) arr[] is the same size as the number of elements in the array
Parameters: 
(1) in_stream - a reference variable to the file to parse
(2) arr[] - an array to be assigned each value in the file
Precondition: arr[] is an empty array
Postcondition: arr[] contains every element in the file
======================================================================*/
void fileToArray(ifstream& in_stream, int arr[]){
  int count = 0;

  in_stream.clear();
  in_stream.seekg(0, in_stream.beg);

  while (in_stream >> arr[count]){
    count++;
  }
}

int main()
{
  char repeat = 'f';

  char inFile[21];
  ifstream fin;

  typedef int* IntPointer;
  IntPointer values;

  do {
    //Starting Message
    cout << "Welcome to Sum and Average Program V2.0!\n";
    cout << "=======================\n";
    cout << "Which file do you want us to find the sums and averages for?\n";

    //Setup input file stream
    cin >> inFile;
    fin.open(inFile);
    if (fin.fail())
    {
        cout << "Input file cannot be opened.\n";
        exit(1);
    }
    
    int array_size = 0;
    arraySizer(fin, array_size);
    //Create pointer variable "values" to make a dynamic array of size array_size
    values = new int[array_size];
    fileToArray(fin, values);
    
    //=============================
    //2-1 Sum and Average Program modified to take arrays
    //=============================

    //Integer Variables for Sums
    int posSum = 0, negSum = 0, sum = 0;
    //Double Variables for Counts and Averages
    double count = 0, posCount = 0, negCount = 0, avg, posAvg, negAvg;

    for (int i = 0; i < array_size; i++) {
      sum += values[i];
      count += 1.0;
      
      //Positive Numbers
      if (values[i] >= 0) {
          posSum += values[i];
          posCount += 1.0;
      }
      //Negative Numbers
      if (values[i] < 0) {
          negSum += values[i];
          negCount += 1.0;
      }      
    } 
    
    //Calculations
    posAvg = posSum / posCount;
    negAvg = negSum / negCount;
    avg = sum / count;
      
      
    //Output
    cout << fixed;

    if (posCount == 0) {
        cout << "Positive Average: 0";
        cout << " Positive Sum: 0" << endl;
    } else {
        cout << "Positive Average: " << setprecision(2) << posAvg;
        cout << " Positive Sum: " << posSum << endl;
    }
    if (negCount == 0) {
        cout << "Negative Average: 0";
        cout << " Negative Sum: 0" << endl;
    } else {
        cout << "Negative Average: " << setprecision(2) << negAvg;
        cout << " Negative Sum: " << negSum << endl;
    }

    cout << "Total Average: " << setprecision(2) << avg;
    cout << " Total Sum: " << sum << endl;

    //clear variables
    delete []values;
    values = NULL;
    //close streams
    fin.close();

    //Prompt user to start over
    cout << "\nWant to read another file?\n";
    cout << "Type y to continue or any other key to terminate the program.\n";
    cin >> repeat;
  } while(repeat == 'y' || repeat == 'Y');

}

/*
==============================================================================
Problems I had working on this assignment (and how I overcame these problems)

1. I had trouble manipulating both reference and pointer variables throughout 
the assignment. I originally declared the pointer array within the function, 
which made it impossible to access the values of the created array outside of 
the function. I fixed this by moving it outside.

2. I kept receiving a "corrupted_size vs prev_size" error that would exit my
program, and I didn't know why. It would only occur when I had my starting cout
message implemented. I don't know why it would only happen with a cout message.
However, I later discovered that I would increment count twice at a time, causing
an incorrect allocation of memory size.

==============================================================================
*/