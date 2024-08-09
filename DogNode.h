/*************
Node.h

*************/

#ifndef NODE_H
#define NODE_H
#include "Dog.h"
class Node // Node for Dog class.
{
private:
	Dog dog; // The dog element in this node.
	Node* next; // A pointer pointing to the next item in the list.


	Node* prev; // A pointer pointing to the previous item in the list.
	// The list needs access to this Node class.
	// Access is provided by friend declaration.
	friend class DoublyLinkedList; 
};
#endif
