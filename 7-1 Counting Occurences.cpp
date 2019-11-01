
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <assert.h> 
using namespace std;

// Class: CIS 054
// Assignment: 7-1 Counting Occurrences
// Name: Angeline Lee
// Date: 10/20/19

/* ===================================================================
Function: swap()
Purpose: swap any two given elements
Parameters: 
(1) a - passed as a reference integer to change a to b directly
(2) b - passed as a reference integer to change b to a directly
Precondition: a and b are two integers that need to be swapped
Postcondition: a becomes b and b becomes a
======================================================================*/
void swap(int& a, int& b)  
{  
    int temp = a;  
    a = b;  
    b = temp;  
}  
  
/* ===================================================================
Function: compare_n_swap()
Purpose: bubble sort a given array
Parameters: 
(1) a[] - an integer array to be sorted
(2) array_size - the size of the array so that it can loop through the exact number of elements
Precondition: given a sorted or unsorted array to be sorted
Postcondition: array a[] is sorted
======================================================================*/
void compare_n_swap(int a[], int array_size)  
{  
    int i, j;  

    //Nested for loop
    for (i = 0; i < array_size-1; i++)      
        for (j = 0; j < array_size-i-1; j++)  
            if (a[j] > a[j+1])  
                swap(a[j], a[j+1]);  
}  

/* ===================================================================
Function: removeAndCountDuplicates()
Purpose: given an integer list, remove all duplicates and change another
array that holds the counts of each integer in the first list
Parameters: 
(1) intList[] - takes in a list of integers and removes all duplicates
(2) countList[] - counts all duplicates when they are removed from intList[]
(3) n - the size of intList
Precondition: a list of integers exists with or without duplicates to be counted
Postcondition: intList has no duplicates and countList holds the counts
of every integer in intList in order
======================================================================*/
int removeAndCountDuplicates(int intList[], int countList[], int n) 
{ 
    int tempInt[n];
    int tempCount[n]; 
    int intCount = 0;
    int prevCount = -1;
  
    //Traverse elements
    int j = 0; 
    for (int i=0; i<n; i++) {
  
      if (intList[i] != intList[i+1]) {
        tempInt[j] = intList[i];
        intCount++;
        tempCount[j] = i - prevCount;
        prevCount = i;
        j++;
      }
    }
  
    //Move temp to the actual array
    for (int i=0; i<j; i++) {
        intList[i] = tempInt[i]; 
        countList[i] = tempCount[i];
    }
    
    return j;
} 

/* ===================================================================
Function: print_2d()
Purpose: to print out a 2D array
Parameters: 
(1) b[][2] - a 2d array that has only two columns
(2) array_size - an integer number that is the size of the rows in the array
Precondition: a predefined array exists to be printed
Postcondition: the 2d array is printed on the console in two rows
======================================================================*/
void print_2d(const int b[][2], int array_size) {
  for (int i=0; i < array_size; i++) {
    for (int j=0; j < 2; j++) {
      cout << b[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
    //assumes the test documents will only list 50 or less integers
    //start
    cout << "Welcome to Number Cruncher!\n";
    cout << "=======================\n";
    cout << "Which file do you want us to crunch?\n";

    //Variables
    int size = 0; 
    int intList[50];
    int countList[50];

    //User Input
    string fileName;
    cin >> fileName;
    ifstream inFile(fileName.c_str());

    //setup input file stream
    if (inFile.fail())
    {
        cout << "Input file cannot be opened.\n";
        exit(1);
    }  

    //test
    // ifstream inFile;
    // inFile.open("test1.dat");

    //Finds the size of the array
    //Inputs information from file into the array
    while(!inFile.eof())
    {
        inFile >> intList[size];
        size++;
    }

    inFile.close();

    compare_n_swap(intList, size);
    int newSize = removeAndCountDuplicates(intList, countList, size); 

    //Combine the arrays into a 2d array
    const int ARRAY_SIZE_0 = newSize;
    const int ARRAY_SIZE_1 = 2;
    int combinedArray[ARRAY_SIZE_0][ARRAY_SIZE_1];

    for (int i=0; i<ARRAY_SIZE_0; i++) {
      combinedArray[i][0] = intList[i];
      combinedArray[i][1] = countList[i];
    }

    //Output
    cout << "Here is the stats:\n";
    cout << "N Count\n";
    print_2d(combinedArray, newSize);

    return 0;
}

/*
==============================================================================
Problems I had working on this assignment (and how I overcame these problems)

1. My biggest problem was creating the removeAndCountDuplicates() function. 
Unfortunately, I deleted my progress several times, so I have little data to show.
I was unable to make it work. I ultimately realized I had an error by prematurely
 incrementing j, setting off unpredictable changes in my result.

2. Another problem I had faced was that I was unsure of where to open and close
the files. I initially put it in the function but later moved it to the main
function as the function only exists to make slight modifications.

==============================================================================
*/