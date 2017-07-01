/*
 * personal.h
 *
 *  Created on: Oct 31, 2016
 *      Author: jack
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

#ifndef PERSONAL_H_
#define PERSONAL_H_

class Personal
{
public:
	Personal();
	Personal(char*, char*, char*, int, long);
	/* Takes a file stream as in input (and possibly changes it).  Because it's a
	 * reference input variable, it is probably changing the passes object, which
	 * is natural when are dealing with file-objects (because the file object
	 * cursor in file needs to move... thus the file object keeps changing.)
	 * const promises not to change the class*/
	void writeToFile(fstream&) const;
	void readFromFile(fstream&);
	void readKey();
	int size() const
	{
		return 9 + nameLen + cityLen + sizeof(year) + sizeof(salary);
	}
	bool operator==(const Personal& pr) const
	{
		return strncmp(pr.SSN,SSN,sizeof(SSN)) == 0;
	}
protected:
	const int nameLen, cityLen;
	char SSN[10], *name, *city;
	int year;
	long salary;
	ostream& writeLegibly(ostream&);
	friend ostream& operator<<(ostream& out, Personal& pr)
	{
		return pr.writeLegibly(out);
	}
	istream& readFromConsole(istream&);
	friend istream& operator>>(istream& in, Personal& pr)
	{
		return pr.readFromConsole(in);
	}
};

#endif /* PERSONAL_H_ */
