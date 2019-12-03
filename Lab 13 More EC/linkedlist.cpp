// File:	linkedlist.cpp
// Lab:		13-0 Bonuse lab 
// Purpose:	Implementation of the reverse function as described below. 
//			You are to submit this file and linkedlist.h only. 
// Reverse function:
// 		Write a void function that takes a linked list of integers and reverses the order 
// 		of its nodes. The function will have one call-by-reference parameter that is a 
// 		pointer to the head of the list. After the function is called, this pointer will 
// 		point to the head of a linked list that has the same nodes as the original list, but 
// 		in the reverse of the order they had in the original list. 
// 		Note that your function will neither create nor destroy any nodes. It will simply 
// 		rearrange nodes. Place your function in a suitable test program.
// Author:	Monza Lui
// Date:	Nov 26, 2019

// Class: CIS 054
// Assignment: 13-0 Reversing Linked List
// Name: Angeline Lee
// Date: 12/3/19

#include <iostream>
#include "linkedlist.h"
#include "node.h"

using namespace std;

// This function inserts a new node onto the head of the list
// and is a class-based version of the same function defined
// in Display 15.4.
void head_insert(NodePtr &head, int the_number)
{
	NodePtr temp_ptr;
	temp_ptr = new Node(the_number, head);
	head = temp_ptr;
}

void reverse(NodePtr &head) {
	NodePtr temp = head, 
	//set to prev to nullptr to avoid segmentation fault
	//bc the entire linked list is reversed with each iteration
	//therefore, last must = nullptr
	prev = nullptr, remaining = nullptr; 

	while (temp != nullptr) { 
		remaining = temp->getLink(); 
		temp->setLink(prev); 

		//always make sure that the reversed linked list is separate
		//from the old linked list
		prev = temp; 
		temp = remaining; 
	} 
	head = prev; 
}

void print_nodes(NodePtr head) {
	cout << "Current linked list: ";
	for (NodePtr iter = head; iter != nullptr; iter = iter->getLink()) {
		cout << iter->getData() << " ";
	}
	cout << endl;
}

void delete_nodes(NodePtr& head) {
	while (head != NULL)
	{
		NodePtr discard = head;
		head = head->getLink();
		cout << "Deleting " << discard->getData() << endl;
		delete discard;
	}
}

/* ==========================================================
Problems I had working on this assignment (and how I overcame these problems)

1. Originally, I didn't set 'prev' to nullptr, and it 
continued to cause segmentation faults. The reason for this is 
because it becomes the tail of the list, but despite mapping it
out, I still forgot to declare assign the variable the value. I 
fixed this immediately by initializing it to nullptr.

2. I didn't have too many issues dealing with this assignment
because I have done the same program in Java before. However,
one of my greatest problems is just overcomplicating the
algorithm. Before I recalled how to solve it, I had much more work
attempting to move the data through more variables to ensure that
I didn't misplace it. For example, I also had a second iteration
loop to begin from the tail of the list and int variables.

========================================================== */