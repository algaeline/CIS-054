// File:	linkedlist.h
// Lab:		13-0 Bonuse lab 
// Purpose:	Definition of the reverse function as described below. 
//			You are to submit this file and linkedlist.cpp only. 
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

#ifndef LINKED_H
#define LINKED_H

#include "node.h"
using namespace std;

// Purpose: Inserts a new node onto the head of the list
// and is a class-based version of the same function defined
// in Display 15.4.
void head_insert(NodePtr &head, int the_number);

// Purpose: Reverse the order of the nodes, without destroying or changing value of data
// 			in any node
void reverse(NodePtr &head);

// Purpose: Print out the value of each node
void print_nodes(NodePtr head);

// Purpose: Delete all the nodes, clean up after ourselves
void delete_nodes(NodePtr& head);

#endif