/*
 * useInterpreter.cpp
 *
 *  Created on: May 7, 2017
 *      Author: jack
 */
#include <iostream>

#include "interpreter.h"

using namespace std;

int main() {
	cout << "Figure 5.20: Interpreter" << endl;

	Statement statement;
	cout << "The program processes statements of the following format:\n"
		 << "\t<id> = <expr>;\n\tprint <id>\n\tstatus\ntend\n\n";

	while(true)		// This infinite loop is broken by exit(1)
		statement.getStatement();	// in getStatement() or upon
									// finding and error.

	return 0;
}
