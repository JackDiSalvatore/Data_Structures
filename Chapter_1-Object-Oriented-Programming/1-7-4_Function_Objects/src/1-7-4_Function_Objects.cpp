//============================================================================
// Name        : 1-7-4_Function_Objects.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <functional>	// ?
using namespace std;

/************* Overloading function call operator ***************/
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


/********* without overloading function call operator ***********/
class classf2
{
public:
	classf2() { }
	double run (double x)
	{
		return 2*x;
	}
};


double sum3(classf2 f, int n, int m)
{
	double result = 0;
	for(int i = n; i <= m; i ++)
	{
		result += f.run(i);
	}
	return result;
}


/************** Passing operators **************/
template<class T>
struct negate : public unary_function<T,T>
{
	T operator() (const T& x) const
	{
		return -x;
	}
};


template<class F>
double sum4(F f, int n, int m)
{
	double result = 0;
	for(int i = n; i <=m; i++)
	{
		result += f(i);
	}
	return result;
}


int main()
{
	cout << "First Example: " << endl; // prints !!!Hello World!!!

	cout << sum2(classf(),2,5) << endl;

	classf cf;
	cout << sum2(cf,2,5) << endl;

	cout << "Second Example: \n";

	cout << sum3(classf2(),2,5) << endl;

	cout << "Third Example: \n";

	//cout << sum4(negate<double>(),2,5);		// <functional ?


	return 0;
}
