/*
 * student.cpp
 *
 *  Created on: Nov 5, 2016
 *      Author: jack
 */
#include "student.h"

Student::Student() : majorLen(10)
{
	Personal();
	major = new char[majorLen+1];
}

Student::Student(char *ssn,char *n,char *c,int y,long s, char *m) :
		majorLen(10)
{
	Personal(ssn,n,c,y,s);
	major = new char[majorLen+1];
	strcpy((char*)major,m);
}

void Student::writeToFile(fstream& out) const
{
	Personal::writeToFile(out);
	out.write(major,majorLen);
}

void Student::readFromFile(fstream& in)
{
	Personal::readFromFile(in);
	in.read(major,majorLen);
}

ostream& Student::writeLegibly(ostream& out)
{
	Personal::writeLegibly(out);
	major[majorLen] = '\0';
	out << ", major = " << major;
	return out;
}

istream& Student::readFromConsole(istream& in)
{
	Personal::readFromConsole(in);
	char s[80];
	cout << "Major: ";
	in.getline(s,80);
	strncpy(major,s,9);
	return in;
}
