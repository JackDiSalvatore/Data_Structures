//============================================================================
// Name        : Figure-3-2_Singly_Linked_List.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "intSLLst.h"

using namespace std;

int main()
{
	cout << "!!!Hello World!!!" << endl;

	IntSLList list;

	list.addToHead(50);
	list.addToHead(8);
	list.addToHead(10);

	list.print();

	return 0;
}
