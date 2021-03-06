/*
 * main.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: jack
 */
#include <iostream>

using namespace std;

// const
//		- A compile time constraint that an object can not modified

/*
 * Why use const
 * 		a.) Guards against inadvertent write to the variable (use whenever a variable should not change)
 * 		b.) Self documenting, helps the reader understand how code works
 * 		c.) Enables compiler to do more optimization, make code tighter
 * 		d.) const means variable can be place into ROM, (Program memory? instead of data memory)
 * */

void exp1() {
	cout << "Example 1" << endl;
	const int i = 9;
	// i = 6;  can't do this

	const int *p1 = &i;	// The data that is pointed to is const, pointer is not
	++p1;	// this is allowed
	//*p1 = 6; this is not

	int k = 10;
	int *const p2 = &k;	// pointer is const, data is not
	*p2 = 20;
	//p2 = &i; cant do this

	const int *const p3 = &i;	// data is const int, pointer is also const

	// Both of these are the same, "i" can't be modified
	int const *p4 = &i;		// pointer to int that is const
	const int *p5 = &i;		// Same, pointer to const int

	// If const is on the left of *, data is const
	// If const is on the right of *, pointer is const

	int j = 9;
	// say I really want to change i
	const_cast<int&>(i) = 6;
	cout << i << endl;

	int z = 7;
	z = 10;
	// static_cast<const int&>(z) = 7;
	cout << z << endl;
	// Don't use the cast, its a hacky way to stuff
}



// example-2 const used with functions
class Dog {
	int age;
	string name;
public:
	Dog() { age = 3; name = "Roofus"; }

	// const parameter example
	void setAge(const int& a) {
		age = a;
		// a = 20; const fixes this
		cout << "Dog's age is " << age << endl;
	}

	// const return value example
	// you wanna return by reference so you don't have to make
	// a copy of the name as you would if you returned a value (it
	// would be a new value)
	// const makes sure you cant modify the returned name
	const string& getName() {return name;}

	// const function: this function will not change any member
	//                 variables of this class
	void printDogName() const {
		cout << name << " -const function"<< endl;
		// age++;  can't change member variables

		// cout << getName() <<  endl;
		// cant call other functions that are not const !
	}
	// you CAN overload this without the const
	// this will be invoked when the Dog object is not a const !
	void printDogName() {
		cout << getName() << " -non const function" << endl;
	}
};

void exp2() {
	cout << "Example 2" << endl;
	Dog d;

	int i = 9;
	d.setAge(i);
	cout << i << endl;

	const string& n = d.getName();
	cout << n << endl;

	d.printDogName();

	const Dog d2;
	d2.printDogName();
}

int main(int argc, char* argv[]) {

	exp1();
	exp2();


	return 1;
}


