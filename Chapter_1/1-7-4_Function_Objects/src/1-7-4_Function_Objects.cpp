//============================================================================
// Name        : 1-7-4_Function_Objects.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class classf
{
public:
	classf() { }
	double operator() (double x)
	{
		return 2*x;
	}
};


double sum2(classf f, int n, int m)
{
	double result = 0;
	for(int i = n; i <= m; i++)
	{
		result += f(i);		// 0 + (2x2) + (3x2) + (4x2) + (5x2) = 28
	}
	return result;
}


int main()
{
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	cout << sum2(classf(),2,5) << endl;

	classf cf;
	cout << sum2(cf,2,5) << endl;

	return 0;
}
