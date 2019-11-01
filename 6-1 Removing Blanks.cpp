#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Class: CIS 054
// Assignment: 6-1 Removing Blanks
// Name: Angeline Lee
// Date: 10/13/19

void remove_blanks(ifstream& in_stream, ofstream& out_stream){
  //notification message
  cout << "Begin editing files.\n";

  //character received from the file
  char c;

  //initial call
  in_stream.get(c);

  while (!in_stream.eof())
  {
    //if the next char is the eof() and a blank, break out of while
    if(c == ' ' && in_stream.peek(), in_stream.eof())
     break;
    //if c is not a space or the next input is not a space
    if(!isspace(c) || in_stream.peek() != ' ') {
      out_stream.put(c);
    }
    in_stream.get(c);
  }

  cout << "End of editing files. \nCheck translated.dat for result!\n";
}

int main()
{
    cout << "Welcome to Blank Eater!\n";
    cout << "=======================\n";
    cout << "Which file do you want us to clean up?\n";
    
    //test to ensure code works
    //ifstream inFile ("test.dat");

    char inFile[21];
    ifstream fin;

    //setup input file stream
    cin >> inFile;
    fin.open(inFile);
    if (fin.fail())
    {
        cout << "Input file cannot be opened.\n";
        //exit(1);
    }

    //setup output file stream
    ofstream fout ("translated.dat");
    if (fout.fail())
    {
        cout << "Output file can't be opened.\n";
        //exit(1);
    }

    remove_blanks(fin, fout);

    //close streams
    fin.close();
    fout.close();

    return 0;
}

/*
==============================================================================
Problems I had working on this assignment (and how I overcame these problems)

1. My biggest problem was testing this code. While I could get it to work with
an explicitly predetermined input file, I had issues using .c_str to convert
the user's input. However, this was ultimately solved by using .c_str().

2. Another problem I had faced was that I was unsure of where to open and close
the files. I initially put it in the function but later moved it to the main
function as the function only exists to make slight modifications.

==============================================================================
*/