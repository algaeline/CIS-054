// File:		queue.h
// Purpose:		Interface file of the queue class
// Author & copyright:	Monza Lui
// Date:		Dec 1, 2019

#ifndef QUEUE_H
#define QUEUE_H

struct Node {
	int symbol;
	// New variable to keep track of timestamps
	long getin_time;
	Node *next;
};
typedef Node* NodePointer;

class Queue {
private:
	NodePointer front;
	NodePointer end;

	// New variables to calculate average wait times
	int helped = 0;
	long time1 = 0, time2 = 0, time3 = 0;
public:
	// == Friends ==
	friend void print(const Queue& the_Queue);
	// == Constructors ==
	// Default constructor, initialize to an empty Queue
	Queue();
	// Copy constructor, make an exact copy of the_Queue
	Queue(const Queue& the_Queue);
	// Destructor, destroy the Queue and return memory allocated
	~Queue();

	// == Basic Operations ==
	// Purpose: Add new_symbol and time into the Queue
	// *EDIT* Added time in order to get current milliseconds for wait time calculations
	// *EDIT* Changed new_symbol to be an integer so that customer can be counted easier
	void add(int new_symbol, long time);
	// Purpose: Remove and return the front symbol from the Queue if not empty
	// Precondition: The Queue is not empty
	char remove();

	// == Others ==
	// Purpose: Returns if the Queue is empty
	bool empty() const;
};

#endif