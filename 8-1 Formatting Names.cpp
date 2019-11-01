// Example program
#include <iostream>
#include <string>
using namespace std;

// Class: CIS 054
// Assignment: 8-1 Formatting Names
// Name: Angeline Lee
// Date: 10/27/19

//Lab Observations
// 1) if-else
// 2) isspace()

/* ===================================================================
Function: properlyCapitalize()
Purpose: capitalize the first character of each name and set the rest to lowercase
Assumptions: 
(1) the name follows the correct format
(2) name does not have capitalized letters in the middle of parts (e.g. McDonald)
Parameters: 
(1) name - the full name (all parts included)
Precondition: name is a string input
Postcondition: all names are formatted with a leading capitalized character and lowercase characters following
======================================================================*/

void properlyCapitalize(string& name) {

  for(int i = 0; i < name.length(); i++) {
    
    //if name[i] is the very first character of the string (first name)
    //or if there is a space before name[i] (middle or last name)
    if(i == 0 || name[i-1] == ' ') {
      name[i] = toupper(name[i]);
    } else {
      name[i] = tolower(name[i]);
    }
  }

}

/* ===================================================================
Function: formatName()
Purpose: given input "First Middle Last" or "First Last" -> 
         produce output "Last, First M." or "Last, First"
Assumptions: 
(1) the name follows the correct format (only two or three name inputs)
(2) there are no outlier spaces (e.g. before the name)
Parameters: 
(1) name - the full name (all parts included)
(2) output result that will be printed
Precondition: name is a string input
Postcondition: the name is properly formatted and returned in predicted output style
Calls: properlyCapitalize()
======================================================================*/
void formatName(string name) {
  properlyCapitalize(name);

  string first, initial = "", last, result;
  int firstSpace = name.find(' ', 0);

  first = name.substr(0, firstSpace);
  int nextSpace = name.find(' ', firstSpace + 1);

  //function .find() returns -1 when no such substring is found
  //only occurs if one space exists in the string, therefore "first last" format
  if(nextSpace == -1) {
    last = name.substr(firstSpace + 1);
    result = last + ", " + first;
  } else {
    initial = name.at(firstSpace + 1);
    last = name.substr(nextSpace + 1, nextSpace + 2);
    result = last + ", " + first + " " + initial + ".";
  }
  cout << result << endl;
}

int main()
{
  ///Introductory Message
  cout << "Welcome to the name formatter!\n";
  cout << "=======================\n";

  //Variables
  string nameInput;
  //mark first time
  char repeat = 'f';
  
  do {
      cout << "Please enter a name in the format: first name, middle name or initial (OPTIONAL), and last name.\n";
      
      //ignores the '\n' for every following iteration of the loop
      if(repeat != 'f'){
        cin.ignore();
      }

      getline(cin, nameInput);
      formatName(nameInput);

      //ask user if they want to continue
      cout << "Enter y to format another name. Enter any other key to stop.\n";
      cin >> repeat;
  }   while ( repeat == 'Y' || repeat == 'y');
  
}

/*
==============================================================================
Problems I had working on this assignment (and how I overcame these problems)

1. One of the problems I had was dealing with efficiency. I had to decide which
functions would be most efficient. I originally had a hasMiddle() function but
removed it because there was no need for one. I implemented the recognition of
a middle name in the formatName() function by simply reading for how many spaces
appeared in the name string.

2. Another problem I had was using the getline() function. My do-while loop would
immediately take in an input without prompting the user. I discovered that cin
reads the new line character as an input, despite being a part of the prompt.
Therefore, I had to use the cin.ignore() function to fix the issue. However,
cin.ignore() does not work for the first iteration of the loop because cin
is never prompted until after the loop.

==============================================================================
*/