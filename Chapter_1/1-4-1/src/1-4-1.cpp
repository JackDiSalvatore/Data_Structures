//============================================================================
// Name        : 1-4-1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void example1()
{
	int n;
	cin >> n;
	/* Arrays can be declared dynamically */
	int *p;
	p = new int[n];

	int sum;
	int i;
	for(sum = *p, i = 1; i < n; i++)
	{
		sum += *(p + i);
		cout << sum << endl;
	}

	delete [] p;	// free up array

}

int main()
{
	int i;
	int a[5];		// a is a pointer to memory to a block that can hold 5 integers
	int *p;

	cout << a[0] << " = " << *a << endl;
	cout << &a[0] << " = " << a << endl;

	for(i=0;i<5;i++)
	{
		cout << a[i] << "\tis at" << &a[i] << endl;
	}


	cout << "\nArray notation" << endl;
	for (int sum = a[0], i = 1; i < 5; i++)
	{
		sum += a[i];
		cout << sum << endl;
	}

	cout<<  "\nPointer notation" << endl;
	for (int sum2 = *a, i = 1; i < 5; i++)
	{
		sum2 = *(a + i);
		cout << sum2 << endl;
	}
	/* Or */
	cout << endl;
	/* a+1 == &a[1] */
/*	for(int sum3 = *a, p = a+1; p < a+5; p++)
	{
		sum3 += *p;
		cout << sum3 << endl;
	}*/

	example1();

	return 0;
}
