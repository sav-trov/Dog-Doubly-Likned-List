//Dog.h

// 
// Preprocessing directives that prevents multiple definitions.
#ifndef Dog_H
#define Dog_H

#include<iostream>
#include<string>


using std::string;
using std::cout;
using std::endl;
using std::ostream;

// Class declaration for Dog class.
class Dog
{

	friend ostream& operator << (ostream& out, const Dog& theDog);

public:				

	Dog();					

	// Other constructors.
	Dog(string theBreed, string theSize, int theLifeExpectancy);

	// Get and set methods or member functions.
	string getBreed() const;
	string getSize() const;
	int getLifeExpectancy() const;
	void setBreed(string theBreed);
	void setSize(string theSize);
	void setLifeExpectancy(int LifeExpectancy);

	// Utility member functions.
	void print();




private:			
	string Breed;
	string Size;
	int LifeExpectancy;

};	

#endif

