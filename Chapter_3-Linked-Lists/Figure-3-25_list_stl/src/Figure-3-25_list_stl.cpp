//============================================================================
// Name        : Figure-3-25_list_stl.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : A program demonstrating the operation of list member functions
//============================================================================
#include <iostream>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	list<int> lst1;				// lst1 is empty
	list<int> lst2(3,7);		// lst2 = (7 7 7)
	for(int j = 1; j < 5; j++)
		lst1.push_back(j);		// lst1 = (1 2 3 4 5)
	list<int>::iterator i1 = lst1.begin(), i2 = i1, i3;	// i1 = 1, i2 = 1, i3 = null?
	i2++; i2++; i2++;			// i2 = 4
	list<int> lst3(++i1,i2);	// different constructor lst3 = (2 3)
	list<int> lst4(lst1);		// lst4 = lst1 = (1 2 3 4 5)

	i1 = lst4.begin();			// i1 = 1
	lst4.splice(++i1,lst2);		// lst2 is now empty
								// lst4 = ( 1 "7 7 7" 2 3 4 5)
								//   entry pt^, ^lst2

	lst2 = lst1;				// lst2 = (1 2 3 4 5)
	i2 = lst2.begin();			// i2 = 1
	// void splice (iterator position, list& x, iterator first, iterator last);
	lst4.splice(i1,lst2,++i2);	// lst2 = (1   3 4 5)
								//      take 2 (i1) out of lst2,
								// lst4 = ( 1 "7 7 7" 2 2 3 4 5)

	i2 = lst2.begin();			// i2 = 1
	i3 = i1;					// i3 = 1

	// void splice (iterator position,	= 1
	// 						  list& x,	= lst2 (1 3 4 5)
	//				   iterator first,	= 1
	// 					iterator last); = 2
	lst4.splice(i1, lst2, i2, i3++);// lst2 = (3 4 5),
									// lst4 = (1 7 7 7 2 1 2 "3 4 5")

	lst4.remove(1);					// lst4 (7 7 7 2 2 3 4 5)
	lst4.sort();					// lst4 (2 2 3 4 5 7 7 7)

	// removes all but the first element from every consecutive group of
	// equal elements in the container
	lst4.unique();					// lst4 (2 3 4 5 7)
	lst1.merge(lst2);				// lst1 (1 2 3 3 4 4 5 5),
									// lst2 is now empty
	lst3.reverse();					// lst3 (3 2)
	lst4.reverse();					// lst4(7 5 4 3 2)
	lst3.merge(lst4, greater<int>());	// lst3 (7 5 4 3 3 2 2),
										// lst4 is now empty
	lst3.remove_if(bind2nd(not_equal_to<int>(),3));	// lst3 (3 3)
	lst3.unique(not_equal_to<int>());	// lst3 (3 3)

	cout << "Done!!" << endl;
	return 0;
}
