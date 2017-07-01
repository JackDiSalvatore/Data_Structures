/*
 * database.h
 *
 *  Created on: Nov 5, 2016
 *      Author: jack
 */

#ifndef DATABASE_H_
#define DATABASE_H_

using namespace std;

template<class T>
class Database
{
public:
	Database();
	void run();
private:
	fstream database;
	char fName[20];
	ostream& print(ostream&);
	void add(T&);
	bool find(const T&);
	void modify(const T&);
	friend ostream& operator<<(ostream& out, Database& db)
	{
		return db.print(out);
	}
};

#endif /* DATABASE_H_ */
