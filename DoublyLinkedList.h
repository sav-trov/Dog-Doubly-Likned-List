// DoublyLinkedList.h

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "DogNode.h"

class DoublyLinkedList
{
public:
    DoublyLinkedList(); // Empty list constructor.

    bool empty() const; // list is empty
   
    void removeFront(); // Remove front item list.

    void addFront(const Dog& e); // Add to front of list.

    void addBack(const Dog& e); // Add to back of list.

    void searchAndDisplay(const std::string& breed) const; // Search and display a specific breed of dog

    void editDog(const std::string& breed); // Edit a specific breed of dog

    void deleteDog(const std::string& breed); // Delete a specific breed of dog from the list

    void displayList() const; // Display list of dogs.
   
    void displayFirstDog(); // Display the first dog in the list

private:
    Node* head; // Pointer to the head of list
    Node* tail; // Pointer to the tail of the list
};

#endif
