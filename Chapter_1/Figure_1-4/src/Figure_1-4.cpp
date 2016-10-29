//============================================================================
// Name        : 1-4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : A program demonstrating the operation vector member functions
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>	// greater<T>

using namespace std;

//template<typname t>	// is almost the same thing
template<class T>
void printVector(char *s, const vector<T>& v)
{
	cout << s << " = (";
	if(0 == v.size())
	{
		cout << ")\n";
		return;
	}
	typename vector<T>::const_iterator i = v.begin();
	for( ; i != v.end()-1; i++)
		cout << *i << ' ';
	cout << *i << ")\n";
	return;
}

bool f1(int n)
{
	return n < 4;
}

int main()
{
	int a[] = {1,2,3,4,5};
	vector<int> v1;
	printVector((char *)"v1",v1);		// v1 is empty, size = 0, capacity = 0
	cout << "Size = " << v1.size() << ", Capacity = " << v1.capacity() << endl;
	for(int j = 1; j <=5 ; j++)
		v1.push_back(j);		// v1 = (1 2 3 4 5), size = 5, capacity = 8
	printVector("v1",v1);
	cout << "Size = " << v1.size() << ", Capacity = " << v1.capacity() << endl;
	vector<int> v2(3,7);
	printVector("v2",v2);		// v2 = (7 7 7)
	vector<int>::iterator i1 = v1.begin()+1;
	vector<int>v3(i1,i1+2);		// v3 = (2 3)
	printVector("v3",v3);
	cout << "Size = " << v3.size() << ", Capacity = " << v3.capacity() << endl;
	vector<int> v4(v1);
	printVector("v4",v4);		// v4 = (1 2 3 4 5)
	cout << "Size = " << v4.size() << ", Capacity = " << v4.capacity() << endl;
	vector<int> v5(5);
	printVector("v5",v5);		// v5 = (0 0 0 0 0)
	v5[1] = v5[3] = 9;			// v5 = (0 9 0 9 0)
	printVector("v5",v5);
	v3.reserve(6);
	printVector("v3",v3);		// v3 = (2 3), size =2, capacity = 6
	cout << "Size = " << v3.size() << ", Capacity = " << v3.capacity() << endl;
	v4.resize(7);
	printVector("v4",v4);		// v4 = (1 2 3 4 5 0 0), size = 7 , capacity = 10
	cout << "Size = " << v4.size() << ", Capacity = " << v4.capacity() << endl;
	v4.resize(3);
	printVector("v4",v4);		// v4 = (1 2 3) size = 3, capacity = 10
	cout << "Size = " << v4.size() << ", Capacity = " << v4.capacity() << endl;
	v4.clear();
	printVector("v4",v4);		// v4 is empty, size = 0, capacity = 10 (!)
	cout << "Size = " << v4.size() << ", Capacity = " << v4.capacity() << endl;
	v4.insert(v4.end(),v3[1]);	// v4 = (3)
	printVector("v4",v4);
	v4.insert(v4.end(),v3[1]);	// v4 = (3 3)
	printVector("v4",v4);
	v4.insert(v4.end(),2,4);	// v4 = (3 3 4 4)
	printVector("v4",v4);
	// append starting at v1.begin()+1 to v1.end()-1
	v4.insert(v4.end(),v1.begin()+1,v1.end()-1);	// v4 = (3 3 4 4 2 3 4)
	printVector("v4",v4);
	v4.erase(v4.end()-2);		// v = (3 3 4 4 2 4)
	printVector("v4",v4);
	v4.erase(v4.begin(), v4.begin()+4);	// v4 = (2 4)
	printVector("v4",v4);
	v4.assign(3,8);				// v4 = (8 8 8)
	printVector("v4",v4);
	v4.assign(a,a+3);			// v4 = (1 2 3)
	printVector("v4",v4);
	vector<int>::reverse_iterator i3 = v4.rbegin();
	for( ; i3 != v4.rend(); i3++)
		cout << *i3 << ' ';		// print 3 2 1
	cout << endl;
	cout << "Algorithms\n";

	v5[0] = 3;		// v5 = (3 9 0 9 0)
	printVector("v5",v5);
	replace_if(v5.begin(),v5.end(),f1,7);	// return 7 if < 4
	printVector("v5",v5);					// v5 = (7 9 7 9 7)
	v5[0] = 3; v5[2] = v5[4] = 0;
	printVector("v5",v5);					// v5 = (3 9 0 9 0)
	// from begin to end replace 0 with 7
	replace(v5.begin(),v5.end(),0,7);		// v5 = (3 9 7 9 7)
	printVector("v5",v5);
	sort(v5.begin(),v5.end());
	printVector("v5",v5);					// v5 = (3 7 7 9 9)
	sort(v5.begin(),v5.end(),greater<int>());
	printVector("v5",v5);					// v5 = (9 9 7 7 3)
	v5.front() = 3;
	printVector("v5",v5);					// v5 = (2 9 7 7 3)

	return 0;
}
