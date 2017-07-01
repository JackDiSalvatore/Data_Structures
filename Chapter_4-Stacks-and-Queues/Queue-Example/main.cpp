/*
 * main.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: jack
 */
#include <iostream>
#include <queue>
#include <list>

using namespace std;

int main() {
	queue<int> q1;
	queue<int, list<int> > q2;	// make sure to leave space between the angle brackets > >

	q1.push(1); q1.push(2); q1.push(3);
	q2.push(4); q2.push(5); q2.push(6);
	q1.push(q2.back());

	while(!q1.empty()) {
		cout << q1.front() << ' ';	// 1 2 3 6
		q1.pop();	// empty the list
	}

	cout << '\n';

	while(!q2.empty()) {
		cout << q2.front() << ' ';	// 4 5 6
		q2.pop();
	}

	return 0;
}



