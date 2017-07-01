//============================================================================
// Name        : Fig-4-13-Bank-One.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>

#include "genQueue.h"

using namespace std;

int option(int percents[]) {
	register int i = 0;
	register int choice = rand()%100 + 1;
	register int perc;

	for (perc = percents[0]; perc < choice; perc += percents[i+1], i++);

	return i;
}

int main() {
	cout << "Figure 4.13 - Bank One example\n" << endl;

	int arrivals[] = {15, 20, 25, 10, 30};
	int service[] = {0, 0, 0, 10, 5, 10, 10, 0, 15, 25, 10, 15};
	int clerks[] = {0, 0, 0, 0};
	int numOfClerks = sizeof(clerks)/sizeof(int);
	int customers, t, i;
	int numOfMinutes = 100;
	int x;
	double maxWait = 0.0;
	double currWait = 0.0;
	double thereIsLine = 0.0;
	Queue<int> simulQ;

	cout.precision(2);

	for (t = 1; t <= numOfMinutes; t++) {	// Time
		cout << " t = " << t;
		for (i = 0; i < numOfClerks; i++)	// After each minute subtract at most 60
			if (clerks[i] < 60)				// from time left to service the current
				clerks[i] = 0;				// customer by clerk i
			else clerks[i] -= 60;
		customers = option(arrivals);
		for (i = 0; i < customers; i++) {	// enqueue all new customers (or rather
			x = option(service) * 10;		// service time they require)
			simulQ.enqueue(x);
			currWait += x;		// time the customers have waited
		}
		// dequeue customers when clerks are available:
		for (i = 0; i < numOfClerks && !simulQ.isEmpty(); )
			if (clerks[i] < 60) {
				x = simulQ.dequeue();		// assign more than one customer to a
				clerks[i] += x;				// clerk if service time is still below
				currWait  -= x;				// 60 seconds
			}
			else i++;
		if (!simulQ.isEmpty()) {
			thereIsLine++;
			cout << " wait = " << currWait/60.0;
			if (maxWait < currWait)
				maxWait = currWait;
		}
		else cout << " wait = 0;";
	}

	cout << "\nFor " << numOfClerks << " clerks, there was a line "
		 << thereIsLine/numOfMinutes*100.0 << "% of the time;\n"
		 << "maximum wait time was " << maxWait/60.0 << " min.";
	return 0;
}
