//============================================================================
// Name        : prog1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Encapsulation, abstract data types, classes are blue prints
//				 for objects
//============================================================================
#include <iostream>
#include <string.h>

using namespace std;


class C
{
public:
	C (char *s = "", int i = 0, double d = 1)	// Initailize variables so that
	{											// they have a default value
		strcpy(dataMember1, s);
		dataMember2 = i;
		dataMember3 = d;
	}
	void memberFunction1()
	{
		cout << dataMember1 << ' ' << dataMember2 << ' ' << dataMember3 << endl;
	}
	void memberFunction2(int i, char *s = "unknown")
	{
		dataMember2 = i;
		cout << i << " received from " << s << endl;
	}
protected:
	char dataMember1[20];
	int dataMember2;
	double dataMember3;

};

int main()
{
	C object1("Obejct1", 1, 20.2), object2(" ",1 ,1 ), object3("Object 3", 3, 4.529);

	object3.memberFunction1();
	object2.memberFunction1();
	object1.memberFunction2(20,"Meeee");

	return 0;
}
