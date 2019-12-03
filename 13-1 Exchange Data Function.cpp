// File:	main.cpp
// Lab:		13-1 lab exchange data function. See lab description for more details
// Purpose:	Test whether the exchange data function described below works
// Your task:	Define and implement the following function
// Exchange data function:
// 		Write a void function that takes a linked list of integers and 
//		interchanges data in the first node with that in the last node. 
//		The function will take a pointer to the head of the list. After the 
//		function is called, it will retrieve data stored in it, then find and 
//		retrieve data stored in the last node. The function will then interchange 
//	 	the data of the first node with that of the last node. 
//		Note that your function will neither create nor destroy any nodes. It will 
//		simply interchange the data stored between the head and tail nodes. Place 
// 		your function in a suitable test program.
// Author:	Monza Lui
// Date:	Nov 26, 2019

// Class: CIS 054
// Assignment: 13-1 Exchange Data Function
// Name: Angeline Lee
// Date: 12/3/19

#include <iostream> 
using namespace std;

struct Node {
	// any type of data
	int data;		
	Node *next;
};
typedef Node* NodePointer;

// Purpose: insert a new node at the head of list, with data = data
// Precondition: head is pointing to an existing linked list 
void head_insert(NodePointer& head, int new_data);
// Purpose: remove all the nodes
void delete_nodes(NodePointer& head);
// Purpose: remove nodes with data = data, returns true if successful
void print_nodes(NodePointer head);

// CREATED METHODS
// Purpose: return the tail node and delete it from the linked list
NodePointer find_and_delete_tail(NodePointer& head);
// Purpose: switch the first and last node of the linked list without affecting the rest of the list
// Calls: head_insert, find_and_delete_tail()
void exchange_data(NodePointer& head);

int main() {

	NodePointer head = nullptr;
	head_insert(head, 9);
	head_insert(head, 8);
	head_insert(head, 4);
	head_insert(head, 5);
	head_insert(head, 7);

	cout << "Just finished adding nodes\n";
	print_nodes(head);
	exchange_data(head);
	cout << "Just finished exchanging data\n";
	print_nodes(head);


	delete_nodes(head);

	return 0;
}

void head_insert(NodePointer& head, int new_data) {
	// Create a new NodePointer temp_pointer
	// Create a new Node
	NodePointer temp_pointer = new Node;
	
	// Set the new Node’s data to 9
	temp_pointer->data = new_data;
	// Set the new Node’s pointer next to equal to head
	temp_pointer->next = head;
	// Set head to equal to temp_pointer
	head = temp_pointer;
	// Set temp_pointer to nullptr
	temp_pointer = nullptr;
}

void delete_nodes(NodePointer& head) {
	NodePointer iter = head, iter2;
	//for (iter = head; iter != nullptr; iter = iter->next) 
	while (iter != nullptr) {
		iter2 = iter->next;
		// iter pointing to the node that we are deleting
		// iter2 pointing to the node after the one iter is pointing to 
		cout << iter->data << " is being destroyed\n";
		delete iter;
		iter = iter2;
	}
	head = nullptr;
}

void print_nodes(NodePointer head) {
	cout << "Current linked list: ";
	for (NodePointer iter = head; iter != nullptr; iter = iter->next) {
		cout << " " << iter->data;
	}
	cout << endl;
}

NodePointer find_and_delete_tail(NodePointer& head) {
  NodePointer iter = head, iter2, tail;

  while (iter != nullptr) {
    //if before the tail, return the tail and remove it
    //follows the iteration method used in delete_nodes
    if(iter->next->next == nullptr) {
      tail = iter->next;
      //connects the second to last node to nullptr
      iter->next = nullptr;
      return tail;
    }

		iter = iter->next;
	}
  
  return 0;
}

void exchange_data(NodePointer& head) {
  NodePointer new_head = find_and_delete_tail(head), //call method so that head immediately loses tail
  new_tail = nullptr, //create empty node
  iter = head;

  head_insert(new_tail, head->data);

  //remove first node 
  head = head->next;
  head_insert(head, new_head->data);

  //find the current tail
  while(iter->next)
    iter = iter->next; 
  //attach the new tail
  iter->next = new_tail;

}

/* ==========================================================

Q1. Problems I had working on this assignment (and how I overcame these problems)
1. Initially, I was only going to create one function. However,
this became difficult as I lost track of variables. I would change
the linked list too quickly and would have difficulty reimplementing
lost information back into the function. Instead, I started over
and created a new function.
2. Originally, when I connected the end of the linked list with the
new tail, the console would print an infinitely looped list. I
discovered that I made an error in the order of nodes and their
deletion. The hardest part about dealing with nodes is that you
have to keep track of which nodes connect to which points.
Q2. When implementing exchange_data, I had passed in head as a parameter:
	I passed in head as a reference.
Q3. The reason being:
 	Like the previously implemented functions, exchange_data requires
the actual modification of the linked list as a whole (e.g. changing
the numbers of the first and last node). This would be impossible
to create without having access to the list itself.

========================================================== */