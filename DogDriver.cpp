// DogDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>   // Used for input and output.
#include <string>    // Used for string class
#include <conio.h>    // Used for getch().
#include <limits>     // numeric_limits
#include "Dog.h" 
#include "DoublyLinkedList.h"
using namespace std;
void pressAnyKey();
void getUserInput(string& Breed, string& Size, int& LifeExpectancy);

int main() {

	// Declare, construct, and display list object.
	DoublyLinkedList DogBreed;

	// add a few records to work with
	DogBreed.addFront(Dog("BullDog", "Large", 10));
	DogBreed.addFront(Dog("Chihuahua", "Small", 20));

	int choice = 0;
	bool keepGoing = true;

	// Display menu for user choice.
	while (keepGoing) {
		cout << endl
			<<
			"---------------------------------------------------------------------\n"
			<< " Select an option from the menu below\n"
			<< " by entering the number of the choice\n"
			"---------------------------------------------------------------------\n"
			<< "\t1\tAdd dog to the front of list\n"
			<< "\t2\tAdd dog to the back of list\n"
			<< "\t3\tSeach and display a specific breed of dog\n"
			<< "\t4\tEdit a specific breed of dog\n"
			<< "\t5\tDelete a specific breed of dog from the list\n"
			<< "\t6\tDisplay the entire list front to back\n"
			<< "\t7\tDisplay the first dog in the list\n"
			<< "\t8\tExit the Program\n"
			<<
			"---------------------------------------------------------------------\n\n"
			<< "Enter your choice : ";

		cin >> choice;   // Get user choice and process.
		 
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "\n\n\tOnly integer input please!. \n";
			pressAnyKey();
			continue;
		}

		std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		switch (choice) {

		case 1:   // Add dog to the front of list
		{
			string Breed, Size;
			int LifeExpectancy;
			getUserInput(Breed, Size, LifeExpectancy);
			DogBreed.addFront(Dog(Breed, Size, LifeExpectancy));
			pressAnyKey();
			break;
		}

		case 2: //Add dog to the back of list
		{
			string Breed, Size;
			int LifeExpectancy;
			getUserInput(Breed, Size, LifeExpectancy);
			DogBreed.addBack(Dog(Breed, Size, LifeExpectancy));
			pressAnyKey();
			break;
		}

		case 3: //Search and display a specific breed of dog 
		{
			string Breed,Size;
			int LifeExpectancy;
			getUserInput(Breed, Size, LifeExpectancy);
			DogBreed.searchAndDisplay(Breed);
			pressAnyKey();
			break;
		}

		case 4: //Edit a specific breed of dog
		{
			string Breed, Size;
			int LifeExpectancy;
			getUserInput(Breed, Size, LifeExpectancy);
			DogBreed.editDog(Breed);
		}

		case 5: // Delete a specific breed of dog in the list
		{
			string Breed, Size;
			int LifeExpectancy;
			getUserInput(Breed, Size, LifeExpectancy);
			DogBreed.deleteDog(Breed);
		}

		case 6: //Display the entire list front to back 
		{
			DogBreed.displayList();
			pressAnyKey();
			break;
		}


		case 7: //Display the first dog in the list
		{
			DogBreed.displayFirstDog();
			pressAnyKey();
			break;

		}
		case 8:   // exit program
		{
			keepGoing = false;
			cout << "The program is now ending.\n";
			pressAnyKey();
			break;
		}
		default:
		{
			cout << "That option is currently not available\n";
			pressAnyKey();
			break;
		}
		}
	}
	return 0;
}

void pressAnyKey() {
	char ch = '\0';
	cout << "Press any key to continue" << endl << endl;
	ch = _getch();
	system("cls");
	return;
}


void getUserInput(string& Breed, string& Size, int& LifeExpectancy) {
	cout << endl << endl;
	cout << "\nDog Breed: ";
	getline(std::cin, Breed);
	cout << "\nDog's Size: ";
	getline(std::cin, Size);
	cout << "\nLife Expectancy: ";
	cin >> LifeExpectancy;
	return;
}

