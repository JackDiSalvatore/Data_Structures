/*
 * database.cpp
 *
 *  Created on: Nov 5, 2016
 *      Author: jack
 */
#include <iostream>

#include "student.h"
#include "personal.h"
#include "database.h"

template<class T>
Database<T>::Database()
{
}

template<class T>
void Database<T>::add(T& d)
{
	database.open(fName,ios::in|ios::out|ios::binary);
	database.seekp(0,ios::end);
	d.writeToFile(database);
	database.close();
}

template<class T>
void Database<T>::modify(const T& d)
{
	T temp;
	database.open(fName,ios::in|ios::out|ios::binary);
	while(!database.eof())
	{
		temp.readFromFile(database);
		if(temp == d) 		// overloaded ==
		{
			cin >> temp;	// overloaded >>
			database.seekp(-d.size(),ios::cur);
			temp.writeToFile(database);
			database.close();
			return;
		}
	}
	database.close();
	cout << "This record to be modified is not in the database\n";
}

template<class T>
bool Database<T>::find(const T& d)
{
	T temp;
	database.open(fName,ios::in|ios::binary);
	while(!database.eof())
	{
		temp.readFromFile(database);
		if(temp == d )		// overloaded ==
		{
			database.close();
			return true;
		}
	}
	database.close();
	return false;
}

template<class T>
ostream& Database<T>::print(ostream& out)
{
	T temp;
	database.open(fName,ios::in|ios::binary);
	while(true)
	{
		temp.readFromFile(database);
		if(database.eof())
			break;
		out << temp << endl;	// overloaded <<
	}
	database.close();
	return out;
}

template<class T>
void Database<T>::run()
{
	cout << "File name: ";
	cin >> fName;
	char option[5];
	T rec;
	cout << "1. Add 2. Find 3. Modify a record; 4.Exit\n";
	cout << "Enter an option: ";
	cin.getline(option,4);		// get '\n';
	while (cin.getline(option,4))
	{
		if(*option == '1')
		{
			cin >> rec;		// overloaded >>
			add(rec);
		}
		else if(*option == '2')
		{
			rec.readKey();
			cout << "The record is ";
			if(find(rec) == false)
				cout << "not ";
			cout << "in the database\n";
		}
		else if(*option == '3')
		{
			rec.readKey();
			modify(rec);
		}
		else if(*option == '4')
		{
			cout << "Wrong option\n";
		}
		else return;
		cout << *this;		// overloaded <<
		cout << "Enter an option";
	}
}

int main()
{
	Database<Personal> ().run();
//	Database<Student> ().run();
	return 0;
}
