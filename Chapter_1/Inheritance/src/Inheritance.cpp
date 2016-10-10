//============================================================================
// Name        : Inheritance.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>

using namespace std;


class BaseClass
{
public:
	BaseClass() { }
	void f(char *s = "unknown")
	{
		cout << "Function f() in BaseClass called from " << s << endl;
		h();
	}
protected:
	void g(char *s = "unknown")
	{
		cout << "Function g() in BaseCall called from " << s << endl;
	}
private:
	void h()
	{
		cout << "Function h() in BaseClass\n";
	}

};


class DerivedLevel1 : public virtual BaseClass
{
public:

};


int main()
{

	return 0;
}
