//============================================================================
// Name        : pointers1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	int i = 15, j, *p, *q;

	p = (int*) i;		// p = 15
	cout << p << endl;

	p = &i;				// p = address of i
	cout << p << endl;

	*p = 20;			// i = 20;
	cout << "p = " << p << " , i = " << i << endl;
	/* The (*) is an indirect operator that forces the system to first retrieve the
	 * CONTENTS of p, then access the LOCATION whose address has just been retrieved
	 * from p, and only afterwards, assign 20 to this location */

	j = 2 * *p;		// j = 2 * 20;
	cout << j << endl;

	i = 19;
	q = &i;

	*p = *q - 1;	// i = 18
	cout << i << endl;

	q = &j;
	*p = *q - 1;	// i = j -1 = 39
	cout << i << endl;

	/*********************************************************************************/

	p = new int;		// new allocates blank memory (only accessible by address) of size int

	p = 0;	// p is NULL
	delete p;			// get rid of mememory

	return 0;
}
