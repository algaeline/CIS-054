#ifndef TEMPLIST_H
#define TEMPLIST_H

#include <iostream>
#include <cstdlib>
using namespace std;

  class TemperatureList
  {
  public:
    //Constructors
    //Default: Initializes the object to an empty list.
    TemperatureList();
    //Initializes the object given a maximum size of array
    TemperatureList(int max);    

    // == BIG THREE ==
    //Copy Constructor
    TemperatureList(const TemperatureList &temp2);
    //Destructor
    ~TemperatureList();
    //Overload = operator
    void operator =(const TemperatureList& another_temp);

    // ================================================
	// Function: add_temperature()
	// Purpose: add a temperature element to the temperature list dynamic array
	// ================================================
    void add_temperature(double temperature);

    //**NO CHANGE**
    //Original implementations
    bool full( ) const;
    friend ostream& operator <<(ostream& outs, const TemperatureList& the_object);

  private:
    double *list; //pointer to dynamic array
    short max_size; //max number of elements allowed in array
    short size; //current number of elements in array
  };

  #endif