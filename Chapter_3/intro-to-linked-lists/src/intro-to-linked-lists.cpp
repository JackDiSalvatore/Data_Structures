//============================================================================
// Name        : intro-to-linked-lists.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class IntSLLNode
{
public:
	IntSLLNode()
	{
		next = 0;
	}
	IntSLLNode(int i, IntSLLNode *in = 0)
	{
		info = i;
		next = in;
	}

	int info;
	IntSLLNode *next;
};

int main()
{
	cout << "Start...." << endl;

	IntSLLNode *p = new IntSLLNode(10);		// p points to a new linked list that holds the info 10
	cout << p->info << endl;

	p->next = new IntSLLNode(8);
	cout << p->next->info << endl;

	p->next->next = new IntSLLNode(50);
	cout << p->next->next->info << endl;

	return 0;
}
