//============================================================================
// Name        : STL_vectors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : vectors
//
//					begin			  end
//					 |				   |
//					[ ][ ][ ][ ][ ][ ]
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	/* Container */
	vector<int> vec;
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(8);	// vec: {4,1,8}

	/* Iterator */
	vector<int>::iterator itr1 = vec.begin();	// [begin, end)
	vector<int>::iterator itr2 = vec.end();

	for(vector<int>::iterator itr = itr1; itr != itr2; itr++)
	{
		cout << *itr << " ";		// prints out 4, 1, 8
	}
	cout << "\n";

	/* Algorithm*/
	sort(itr1, itr2);	// vec: {1,4,8}

	for(vector<int>::iterator itr = itr1; itr != itr2; itr++)
	{
		cout << *itr << " ";		// prints out 4, 1, 8
	}
	cout << "\n";

	return 0;
}
