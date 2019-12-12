// File:		queue.cpp
// Purpose:		Implementation of the queue class based on linked list
// Author & copyright:	Monza Lui
// Date:		Dec 1, 2019

#include <iostream>
#include <ctime>
#include "queue.h"
using namespace std;

Queue::Queue() : front(nullptr), end(nullptr) {
	// intentionally doing nothing
}

Queue::Queue(const Queue& the_Queue) {
	// similar to insert(after_me, data)
	cout << "Beginning of copy constructor\n";
	if (the_Queue.empty()) {
		front = nullptr;
		end = nullptr;
	} else {	// use else here because return doesn't look right
		NodePointer insert = new Node;
		front = insert;
		insert->symbol = the_Queue.front->symbol;
		for (NodePointer iter = the_Queue.front->next; iter != nullptr; iter = iter->next) {
				insert->next = new Node;
				insert = insert->next;
				insert->symbol = iter->symbol;
		}
    insert->getin_time = time(nullptr);
		insert->next = nullptr;
		end = insert;
	}
}

Queue::~Queue() {
	cout << "Beginning of Destructor\n";
	NodePointer discard = front;
	while (discard != nullptr) {
		front = discard->next;
		cout << discard->symbol << " is being destroyed\n";
		delete discard;
		discard = front;
	}
}

// Added parameter time to store getin_time
void Queue::add(int new_symbol, long time) {
	// add to the end
	NodePointer insert = new Node;
	insert->symbol = new_symbol;
  	insert->getin_time = time;
	insert->next = nullptr;

	if (front == nullptr) {
		front = insert;
	} else {
		end->next = insert;
	}
	end = insert;
  	cout << "Customer " << end->symbol << " entered the queue at time " << end->getin_time << endl;
}

char Queue::remove() {
	try {
		if (empty()) {
			throw 0;
		}
		// Establish current time in case runtime is extended and information is misaligned
		long current = time(nullptr), wait_time = current - front->getin_time, average = 0;		
		NodePointer next_front = front->next;    
		int curr_customer = front->symbol;
		delete front;
		front = next_front;
		helped++;

		// Shift all wait times to account for most recent customer helped
		time3 = time2;
		time2 = time1;
		time1 = wait_time;

		// In case of initial customers, take only the average of first or first two helped
		if(helped == 1) {
			average = time1;
		} else if(helped == 2) {
			average = (time1 + time2) / 2.0;
		} else {
			average = (time1 + time2 + time3) / 3.0;
		}

		cout << "Customer " << curr_customer << " is being helped at time " << current << ". Wait time = " << wait_time << endl;
		cout << "The estimated wait time for Customer " << curr_customer + 1 << " is " << average << endl;

		return '0';
	} catch (int e) {
		cout << e << " elements in Queue.\n";
	}
	return '\0';
}

bool Queue::empty() const {
	return (front == nullptr);
}

void print(const Queue& the_Queue) {
	NodePointer print = the_Queue.front;
	while (print != nullptr) {
		cout << print->symbol << " ";
		print = print->next;
	}
}