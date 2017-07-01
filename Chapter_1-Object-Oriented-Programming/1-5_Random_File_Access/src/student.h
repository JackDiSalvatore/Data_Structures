/*
 * student.h
 *
 *  Created on: Oct 31, 2016
 *      Author: jack
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "personal.h"

class Student : public Personal
{
public:
	Student();
	Student(char*,char*,char*,int,long,char*);
	void writeToFile(fstream&) const;
	void readFromFile(fstream&);
	int size() const
	{
		return Personal::size() + majorLen;
	}
protected:
	char *major;
	const int majorLen;
	ostream& writeLegibly(ostream&);
	friend ostream& operator<<(ostream& out, Student& sr)
	{
		return sr.writeLegibly(out);
	}
	istream& readFromConsole(istream&);
	friend istream& operator>>(istream& in, Student& sr)
	{
		return sr.readFromConsole(in);
	}
};

#endif /* STUDENT_H_ */
