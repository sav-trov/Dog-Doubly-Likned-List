/*************
DoublyLinkedList.cpp

*************/

#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

// Constructors. Only default constructor is needed for new empty list.
DoublyLinkedList::DoublyLinkedList()
    : head(nullptr),  tail(nullptr) { }

// list is empty
bool DoublyLinkedList::empty() const
{
    return (head == nullptr);
}

// code sourced from https://stackoverflow.com/questions/19009084/node-deletion-in-a-doubly-linked-list
// Remove node from front.
//need for deleting a specific item on list
void DoublyLinkedList::removeFront()
{
    if (!empty())
    {
        Node* temp = head; // temp saves the current head.
        head = temp->next; // Our new head is the old head's next.
        if (head != nullptr) // If list is not empty
            head->prev = nullptr; // Previous of new head is null.
        delete temp; // Delete the previous head.
    }
}


// Add node to front.
void DoublyLinkedList::addFront(const Dog& e)
{
    Node* temp = new Node; // Create new node.
    temp->dog = e; // Store data.
    temp->next = head; // head points to current first node
    temp->prev = nullptr; // first node always has prev == nullptr
    if (head != nullptr) // If list is not empty
        head->prev = temp; // point old nodes prev to our new node
    head = temp; // change head to point to new current first node
}

//Code sourced from the website https://stackoverflow.com/questions/76613130/linked-list-in-c-adding-node-at-the-end-of-the-list
//Add Node to the back of list
void DoublyLinkedList::addBack(const Dog& e)
{
    Node* newNode = new Node; // Create new node.
    newNode->dog = e; // Store data.
    newNode->next = nullptr; // Next of new node is null as it's the new tail.

    if (head == nullptr) // If the list is empty
    {
        newNode->prev = nullptr; // Previous of new node is null as it's the only node.
        head = newNode; // New node becomes the head.
    }
    else // If the list is not empty
    {
        Node* temp = head;
        while (temp->next != nullptr) // Traverse to the end of the list
        {
            temp = temp->next;
        }
        temp->next = newNode; // Link the last node to the new node.
        newNode->prev = temp; // Previous of new node is the previous last node.
    }
    tail = newNode; // Update the tail to the new node.
}

//Code sourced form https://www.alphacodingskills.com/cpp/ds/cpp-doubly-linked-list-search-an-element.php
// Search and display a specific breed of dog
void DoublyLinkedList::searchAndDisplay(const string& breed) const
{
    Node* temp = head;
    bool found = false;   // Initializes to see if the breed is found
    while (temp != nullptr)   // Goes through the list until reaching the end 
    {
        if (temp->dog.getBreed() == breed)  // Check if the breed of the current node matches the target breed
        {
            cout << "Dog found: " << temp->dog << endl;   // If the breed is found, output the dog's information
            found = true;
        }
        temp = temp->next;   // Move to the next node
    }
    if (!found)   // If the breed was not found in the list
        cout << "Dog breed '" << breed << "' not found in the list." << endl;
}

//Code Sourced from https://www.alphacodingskills.com/cpp/ds/cpp-doubly-linked-list-search-an-element.php
// and https://stackoverflow.com/questions/71643779/how-do-i-update-one-of-the-variables-in-an-existing-doubly-linked-list-in-c
// Edit a specific breed of dog
void DoublyLinkedList::editDog(const string& breed)
{
    Node* temp = head;   // Start from the head of the list
    bool found = false;   // Track if the breed is found
    while (temp != nullptr)   // Goes through the list until reaching the end 
    {
        if (temp->dog.getBreed() == breed)   // Check if the breed of the current node matches the target breed
        {
            // If the breed is found prompt to enter new details
            cout << "Enter new details for dog breed '" << breed << "':" << endl;
            string newBreed, newSize;
            int newLifeExpectancy;
            cout << "New Breed: " << endl;
            getline(cin, newBreed);
            cout << "New Size: "<< endl;
            getline(cin, newSize);
            cout << "New Life Expectancy: " << endl;
            cin >> newLifeExpectancy;
            cin.ignore(); // Ignore newline character

            // Update the dog's details with the new values
            temp->dog.setBreed(newBreed);
            temp->dog.setSize(newSize);
            temp->dog.setLifeExpectancy(newLifeExpectancy);
            cout << "Dog breed '" << breed << "' updated successfully." << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (!found)   // If the breed was not found in the list
        cout << "Dog breed '" << breed << "' not found in the list. No edits made." << endl;
}

// cde sourced from https://stackoverflow.com/questions/73749112/how-do-i-delete-a-specific-number-from-doubly-linked-list-in-c
// Delete a specific breed of dog from the list
void DoublyLinkedList::deleteDog(const string& breed)
{
    Node* temp = head;   // Start from the head of the list
    bool found = false;   //  track if the breed is found
    while (temp != nullptr)  // Goes through the list until reaching the end
    {
        if (temp->dog.getBreed() == breed)  // Check if the breed of the current node matches the target breed
        {
            if (temp == head)  // If the breed is found
                removeFront();  // If the node is the head, remove it using removeFront()
            else
            {
                temp->prev->next = temp->next;   // skip the node to be deleted
                if (temp->next != nullptr)
                    temp->next->prev = temp->prev;
                delete temp;
            }
            cout << "Dog breed '" << breed << "' deleted successfully." << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (!found)   // If the breed was not found in the list
        cout << "Dog breed '" << breed << "' not found in the list. No deletions made." << endl;
}


//Display list from front to back
void DoublyLinkedList::displayList() const
{
    if (!empty())
    {
        cout << "The following dogs are in this list:\n";
        Node* temp = head; // start at head of list
        while (temp != nullptr)
        {
            cout << temp->dog << endl;
            temp = temp->next; // will exit loop if null
        }
        cout << endl;
    }
    else
    {
        cout << "There are no dogs in this list.\n";
    }
}



//Display the first dog in the list
void DoublyLinkedList::displayFirstDog()
{
    if (!empty())   // Check if the list is not empty
    {
        cout << "The first dog in the list is:\n";   // output the first dog in the list
        cout << head->dog << endl;
    }
    else
    {
        cout << "There are no dogs in this list.\n";
    }
}




