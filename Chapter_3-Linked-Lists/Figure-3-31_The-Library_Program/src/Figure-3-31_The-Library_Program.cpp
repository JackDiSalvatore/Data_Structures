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
class Book
{
public:
	Book(){ patron = 0; }	// no one has checked out the book upon creation

	bool operator== (const Book& bk) const
	{
		return !strcmp(bk.title, title);		// checks if book titles are the same
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
	friend void checkOutBook();
	friend void returnBook();
};


/*************************************** Author ***********************************/
class Author
{
public:
	Author(){}

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
	CheckedOutBook(list<Author>::iterator ar = 0,
				   list<Book>::iterator bk = 0)
	{
		author = ar;
		book = bk;
	}

	bool operator== (const CheckedOutBook& bk) const
	{
		return !strcmp(author->name, bk.author->name) &&
			   !strcmp(book->title, bk.book->title);
	}
private:
	list<Author>::iterator author;
	list<Book>::iterator book;

	friend void checkOutBook();
	friend void returnBook();

	friend Patron;
};


/*************************************** PATRON *************************************/
class Patron
{
public:
	Patron(){}

	bool operator== (const Patron& pn) const
	{
		return !strcmp(pn.name,name);
	}

private:
	char *name;
	list<CheckedOutBook> books;			// books the patron current has checked out

	ostream& printPatron(ostream&) const;

	friend ostream& operator<< (ostream& out, const Patron& pn)
	{
		return pn.printPatron(out);
	}

	friend void checkOutBook();
	friend void returnBook();
	friend Book;
};


/************************************************************************************/
list<Author> catalog['Z'+1];
list<Patron> people['Z'+1];


/* Print the books by given author */
ostream& Author::printAuthor(ostream& out) const
{
	out << name << endl;
	list<Book>::const_iterator ref = books.begin();

	for( ; ref != books.end(); ref++)
		out << *ref;	// print the book

	return out;
}


/* Pint the who has checked out the book*/
ostream& Book::printBook(ostream& out) const
{
	out << "    * " << title;

	if(patron != 0)
		out << " - checked out to " << patron->name;
	out << endl;

	return out;
}


/* Print the books a Patron has checked out */
ostream& Patron::printPatron(ostream& out) const
{
	out << name;

	if(!books.empty())
	{
		out << " has the following books: \n";
		list<CheckedOutBook>::const_iterator bk = books.begin();

		for( ; bk != books.end(); bk++)
			out << "    *" << bk->author->name << ", " << bk->book->title << endl;
	}
	else out << " has no books\n";

	return out;
}

/************************************ Functions **************************************/

/* Overload output for printing lists */
template<class T>
ostream& operator<<(ostream& out, const list<T>& lst)
{
	for(typename list<T>::const_iterator ref = lst.begin(); ref != lst.end(); ref++)
		out << *ref;

	return out;
}


char *getString(char *msg)
{
	char s[82], i, *destin;

	cout << msg;
	cin.get (s,80);		// place user input in s

	while(cin.get(s[81]) && s[81] != '\n');		// discard overflowing characters
	destin = new char[strlen(s)+1];
	for(i = 0; destin[i] = toupper(s[i]); i++);

	return destin;
}


void status()
{
	register int i;

	cout << "The Library has the following books: \n\n";

	for(i = 'A'; i <= 'Z'; i++)
		if(!catalog[i].empty())
			cout << catalog[i];

	cout << "\nThe following people are using the library:\n\n";

	for(i = 'A'; i <= 'Z'; i++)
		if(!people[i].empty())
			cout << people[i];
}

void includeBook()
{
	Author newAuthor;
	Book newBook;

	newAuthor.name = getString("Enter the authors name: ");
	newBook.title = getString("Enter the title of the book: ");

	list<Author>::iterator oldAuthor = find(catalog[newAuthor.name[0]].begin(),
											catalog[newAuthor.name[0]].end(), newAuthor);

	if(oldAuthor == catalog[newAuthor.name[0]].end())
	{
		newAuthor.books.push_front(newBook);
		catalog[newAuthor.name[0]].push_front(newAuthor);
	}
	else (*oldAuthor).books.push_front(newBook);
}

void checkOutBook()
{
	Patron patron;
	Author author;
	Book book;

	list<Author>::iterator authorRef;
	list<Book>::iterator bookRef;

	patron.name = getString("Enter patron's name: ");

	while(true)
	{
		author.name = getString("Enter author's name: ");
		authorRef = find(catalog[author.name[0]].begin(),
		                 catalog[author.name[0]].end(), author);

		if(authorRef == catalog[author.name[0]].end())
			cout << "Misspelled author's name\n";
		else break;
	}

	while(true)
	{
		book.title = getString("Enter the title of the book: ");
		bookRef = find((*authorRef).books.begin(),
					   (*authorRef).books.end(), book);

		if(bookRef == (*authorRef).books.end())
			cout << "Misspelled authors name \n";
		else break;
	}

	list<Patron>::iterator patronRef;
	patronRef = find(people[patron.name[0]].begin(),
			         people[patron.name[0]].end(), patron);

	CheckedOutBook checkedOutBook(authorRef, bookRef);

	if(patronRef == people[patron.name[0]].end())		// a new patron in the library
	{
		patron.books.push_front(checkedOutBook);
		people[patron.name[0]].push_front(patron);
		(*bookRef).patron = &*people[patron.name[0]].begin();
	}
	else
	{
		(*patronRef).books.push_front(checkedOutBook);
		(*bookRef).patron = &*patronRef;
	}
}


void returnBook()
{
	Patron patron;
	Book book;
	Author author;

	list<Patron>::iterator patronRef;
	list<Book>::iterator bookRef;
	list<Author>::iterator authorRef;

	while(true)
	{
		patron.name = getString("Enter patron's name: ");
		patronRef = find(people[patron.name[0]].begin(),
						 people[patron.name[0]].end(), patron);

		if(patronRef == people[patron.name[0]].end())
			cout << "Patron's name misspelled\n";
		else break;
	}

	while(true)
	{
		author.name = getString("Enter author's name: ");
		authorRef = find(catalog[author.name[0]].begin(),
						 catalog[author.name[0]].end(), author);

		if(authorRef == catalog[author.name[0]].end())
			cout << "Misspelled author's name\n";
		else break;
	}

	while(true)
	{
		book.title = getString("Enter the title of the book: ");
		bookRef = find((*authorRef).books.begin(),
					   (*authorRef).books.end(), book);

		if(bookRef == (*authorRef).books.end())
			cout << "Misspelled title\n";
		else break;
	}

	CheckedOutBook checkedOutBook(authorRef, bookRef);
	(*bookRef).patron = 0;
	(*patronRef).books.remove(checkedOutBook);
}


int menu()
{
	int option;

	cout << "\nEnter one of the following options: \n"
		 << "1. Include a book in the catalog\n"
		 << "2. Check out a book\n"
		 << "3. Return a book\n"
		 << "4. Status\n"
		 << "5. Exit\n"
		 << "Your option? ";
	cin >> option;
	cin.get();			// discard '\n'

	return option;
}


/***************************************** MAIN *************************************/
int main()
{
	cout << "Welcome to the library" << endl; // prints !!!Hello World!!!

	while(true)
	{
		switch(menu())
		{
			case 1: includeBook();	break;
			case 2: checkOutBook();	break;
			case 3: returnBook();	break;
			case 4: status();		break;
			case 5: return 0;
			default: cout << "Wrong option try again: ";
		}
	}

	return 0;	// should never reach here
}
/************************************************************************************/
