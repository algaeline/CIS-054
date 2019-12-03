#include <iostream>
#include "templist.h"
using namespace std;

TemperatureList::TemperatureList( ) : size(0) {
    size = 0;
    max_size = 0;
    list = NULL;
}

TemperatureList::TemperatureList(int max) : max_size(max) {
    size = 0;
    list = new double[max];
}

//copy constructor - creates a copy of the given TemperatureList object
TemperatureList::TemperatureList(const TemperatureList &temp2) {
    size = temp2.size;
    max_size = temp2.max_size;

    if(size > 0) {
        list = new double[max_size];
        for(int i = 0; i < max_size; i++) {
            list[i] = temp2.list[i];
        }
    } else {
        list = NULL;
    }
}

//destructor
TemperatureList::~TemperatureList() {
    delete [] list;
}

void TemperatureList::add_temperature(double temperature) {
    if ( full( ) )
    {
        cout << "Error: adding to a full list.\n";
        exit(1);
    }
    else
    {
        list[size] = temperature;
        size = size + 1;
    }
}

bool TemperatureList::full( ) const
{
        return (size == max_size);
}

ostream& operator <<(ostream& outs, const TemperatureList& the_object)
{
    for (int i = 0; i < the_object.size; i++)
        outs << the_object.list[i] << " F\n";
    return outs;
}

void TemperatureList::operator =(const TemperatureList& another_temp) {
    size = another_temp.size;
    max_size = another_temp.max_size;
    if(size > 0) {
        list = new double[max_size];
        for(int i = 0; i < max_size; i++) {
            list[i] = another_temp.list[i];
        }
    } else {
        list = NULL;
    }
    
}