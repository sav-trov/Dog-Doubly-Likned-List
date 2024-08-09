/********************************
Dog.cpp

*******************************/

#include "Dog.h"		
using namespace std;

 
// Default constructor.
// No return type for a constructor
Dog::Dog()
{
	setBreed("");
	setSize("");
	setLifeExpectancy(0);
}

// Another constructor.
Dog::Dog(string theBreed, string theSize, int theLifeEexpectancy)
{
	setBreed(theBreed);
	setSize(theSize);
	setLifeExpectancy(theLifeEexpectancy);
}

// Get and set methods.
string Dog::getBreed() const
{
	return Breed;
}


string Dog::getSize() const
{
	return Size;
}

int Dog::getLifeExpectancy() const
{
	return LifeExpectancy;
}

void Dog::setBreed(string theBreed)
{
	Breed = theBreed;
}

void Dog::setSize(string theSize)
{

	Size = theSize;
}

// Control data and flag bad data with default value.
void Dog::setLifeExpectancy(int theLifeEexpectancy)
{
	if (theLifeEexpectancy < 0)
	{
		LifeExpectancy = 0;
	}
	else
	{
		LifeExpectancy = theLifeEexpectancy;
	}
}

// Function to print out the dogs information
void Dog::print()
{
	cout << "The dog's breed is a " << Breed << " and will grow to a " << Size << " size and is expected to live for up to " << LifeExpectancy << " years."<< endl;
	
}


ostream& operator << (ostream& out, const Dog& theDog)
{
	out << "The dog's breed is a " << theDog.Breed << " and will grow to a " << theDog.Size << " size and is expected to live for up to " << theDog.LifeExpectancy << " years." << endl;

	return out;
}
