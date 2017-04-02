/*
 * priority-queue.cpp
 *
 *  Created on: Apr 2, 2017
 *      Author: jack
 */
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
	cout << "Figure 4.18" << endl;

	priority_queue<int> pq1;		// plus vector<int> and less<int>
	priority_queue<int,vector<int>,greater<int> > pq2;

	pq1.push(3); pq1.push(1); pq1.push(2);
	pq2.push(3); pq2.push(1); pq2.push(2);

	int a[] = {4, 6, 5};

	priority_queue<int> pq3(a,a+3);	// Compare = a; Container = a+3

	cout << "First: ";
	while (!pq1.empty()) {
		cout << pq1.top() << ' ';	// 3 2 1  - reorder by priority queue
									// high values come first
		pq1.pop();	// empty list one, by one
	}

	cout << "\nFirst: ";
	while (!pq2.empty()) {
		cout << pq2.top() << ' ';	//  1 2 3 - reorderd so small values come first
		pq2.pop();
	}

	cout << "\nFirst: ";
	while (!pq3.empty()) {
		cout << pq3.top() << ' ';	// 6 5 4 - high to small
		pq3.pop();
	}

	return 0;
}



