//============================================================================
// Name        : Figure-3-31_The-Library_Program.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <list>
#include <algorithm>
using namespace std;


class Patron;				// forward declaration: declaring a Patron class before
							// actually filling it out it so C++ is aware of it


/***************************************** BOOK *************************************/
class Book{
public:
	Book(){ patron = 0; }	// no one has checked out the book upon creation

	bool operator== (const Book& bk) const
	{
		return !strcmp(bk.title,title);		// checks if book titles are the same
	}
private:
	char *title;
	Patron *patron;

	/* print too the specified output stream, so you could use stdout,
	 * or open and print to a file */
	ostream& printBook(ostream&) const;

	// Now we can print the book using "<<" to the output stream specified above
	friend ostream& operator<< (ostream& out, const Book& bk)
	{
		return bk.printBook(out);
	}

	friend class CheckedOutBook;			// Book can be checked out by,
											// again the "class" keyword is forward declaring it
	friend Patron;							// a Patron

	/* The following functions can edit members of the Book class
	 * includeBook()	- include a book
	 * returnBook()		- return a book */
	friend void includeBook();
	friend void returnBook();
};


/*************************************** Author ***********************************/
class Author
{
public:
	Author(){;}

	bool operator== (const Author& ar) const
	{
		return !strcmp(ar.name,name);
	}
private:
	char *name;						// name of Author
	list<Book> books;				// list of Books written by that author

	ostream& printAuthor(ostream&) const;

	friend ostream& operator<< (ostream& out, const Author& ar)
	{
		return ar.printAuthor(out);
	}

	/* The following functions can edit members of the Author class
	 * includeBook()	- include a book written by the Author
	 * checkOutBook()	- check out a book written by the Author
	 * returnBook()		- return a book written by the Author */
	friend void includeBook();
	friend void checkOutBook();
	friend void returnBook();

	friend class CheckedOutBook;
	friend Patron;
};


class CheckedOutBook
{
public:

private:
	list<Author>::iterator author;
	list<Book>::iterator book;

	friend void checkOutBook();
	friend void returnBook();

	friend Patron;
};


/***************************************** MAIN *************************************/
int main()
{
	cout << "Welcome to the library" << endl; // prints !!!Hello World!!!


	return 0;
}
/************************************************************************************/
