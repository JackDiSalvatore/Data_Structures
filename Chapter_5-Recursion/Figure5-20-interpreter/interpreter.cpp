/*
 * interpreter.cpp
 *
 *  Created on: May 7, 2017
 *      Author: jack
 */
#include <cctype>
#include <functional>
#include "interpreter.h"

std::string& stoupper( const std::string& s )
{
  std::string result( s );
  std::transform(
    s.begin(),
    s.end(),
    result.begin(),
    std::ptr_fun <int, int> (std::toupper));
  return result;
}

double Statement::findValue(char* id) {
	IdNode tmp(id);
	list<IdNode>::iterator i = find(idList.begin(), idList.end(), tmp);

	if(i != idList.end())
		return i->value;
	else issueError("Unknown variable");

	return 0;	// Should never reach here
}

void Statement::processNode(char* id, double e) {
	IdNode tmp(id,e);
	list<IdNode>::iterator i = find(idList.begin(), idList.end(), tmp);

	if(i != idList.end())
		i->value = e;
	else idList.push_front(tmp);
}

// readId() reads strings of letters and digits that start with
// a letter, and stores them in array passed to it as an actual
// parameter.
// Example of identifiers are: var1, x, pqr123xyz, aName, ect.

void Statement::readId(char *id) {
	int i = 0;

	if(isspace(ch))
		cin >> ch;		// skip whitespace
	if(isalpha(ch)) {
		while (isalnum(ch)) {
			id[i++] = ch;
			cin.get(ch);	// don't skip blanks
		}
		id[i] = '\0';
	}
	else issueError("Identifier expected");
}

double Statement::factor() {
	double var, minus = 1.0;
	static char id[200];

	cin >> ch;
	while(ch == '+' || ch == '-') {	// take all '+'s and '-'s
		if (ch == '-')
			minus *= -1.0;
		cin >> ch;
	}
	if(isdigit(ch) || ch == '.') {	// Factor can be a number
		cin.putback(ch);
		cin >> var >> ch;
	}
	else if(ch == '(') {	// or a parenthesized expression
		var = expression();

		if(ch == ')')
			cin >> ch;
		else issueError("Right parenthesize left out");
	}
	else {
		readId(id);		// or an identifier

		if(isspace(ch))
			cin >> ch;	// leave out whitespace

		var = findValue(id);
	}
	return minus * var;
}

double Statement::term() {
	double f = factor();

	while(true) {
		switch(ch) {
		case '*':
			f *= factor();
			break;
		case '/':
			f /= factor();
			break;
		default:
			return f;
		}
	}
}

double Statement::expression() {
	double t = term();

	while(true) {
		switch(ch) {
		case '+':
			t += term();
			break;
		case '-':
			t -= term();
			break;
		default:
			return t;
		}
	}
}

void Statement::getStatement() {
	char id[20], command[20];
	double e;

	cout << "Enter a statement: ";
	cin >> ch;
	readId(id);
	stoupper(strcpy(command, id));

	if(strcmp(command, "PRINT") == 0) {
		readId(id);
		cout << id << " = " << findValue(id) << endl;
	}
	else if(strcmp(command, "END") == 0)
		exit(0);
	else {
		if(isspace(ch))
			cin >> ch;
		if(ch == '=') {
			e = expression();
			if(ch != ';')
				issueError("There are some extras in the statement");
			else processNode(id,e);
		}
		else issueError("'=' is missing");
	}
}

ostream& operator<< (ostream& out, const Statement& s) {
	list<IdNode>::const_iterator i = s.idList.begin();

	for( ; i != s.idList.end(); i++)
		out << *i;

	out << endl;
	return out;
}

ostream& operator<< (ostream& out, const IdNode& r) {
	out << r.id << " = " << r.value << endl;

	return out;
}
