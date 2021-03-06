/*
 * interpreter.h
 *
 *  Created on: May 7, 2017
 *      Author: jack
 */

#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include <iostream>
#include <list>
#include <algorithm>	// find()
#include <string.h>

using namespace std;

class IdNode {
public:
	IdNode(char *s = "", double e = 0) {
		id = strdup(s);		// strdump: copies *s string into id
		value = e;
	}

	bool operator== (const IdNode& node) const {
		return strcmp(id, node.id) == 0;
	}
private:
	char *id;
	double value;
	friend class Statement;
	friend ostream& operator<< (ostream&, const IdNode&);
};

class Statement {
public:
	Statement() {
	}

	void getStatement();
private:
	list<IdNode> idList;
	char ch;

	double factor();
	double term();
	double expression();
	void readId(char*);
	void issueError(char *s) {
		cerr << s << endl;
		exit(1);
	}
	double findValue(char*);
	void processNode(char*, double);
	friend ostream& operator<< (ostream&, const Statement&);
};

#endif /* INTERPRETER_H_ */
