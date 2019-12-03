// File:	main.cpp
// Lab:		13-0 Bonuse lab 
// Purpose:	Test whether the reverse function described below works
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
#include "node.h"
#include "linkedlist.h"

using namespace std;

int main()
{
	NodePtr head;

	// Create a list of nodes 4->3->2->1->0
	head = new Node(0, NULL);
	for (int i=1; i<5; i++)
	{
		head_insert(head, i);
	}
	cout << "Just finished adding nodes\n";
	print_nodes(head);
	reverse(head);
	cout << "Just finished reversing the linked list\n";
	print_nodes(head);

	delete_nodes(head);
	return 0;
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