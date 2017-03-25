//============================================================================
// Name        : Basic-Queues.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "genQueue.h"
#include "genArrayQueue.h"

using namespace std;

int main() {
	cout << "Basic Queues with arrays and linked lists" << endl; // prints !!!Hello World!!!

	ArrayQueue<int> arQueue;
	Queue<int> queue;

	arQueue.enqueue(10);
	arQueue.enqueue(5);
	arQueue.print();
	cout << "\n";
	arQueue.dequeue();
	arQueue.print();
	cout << "\n";
	arQueue.enqueue(15);
	arQueue.enqueue(7);
	arQueue.print();
	cout << "\n";
	arQueue.dequeue();
	arQueue.print();
	cout << "\n\n\n";

	queue.enqueue(10);
	queue.enqueue(5);

	queue.dequeue();

	queue.enqueue(15);
	queue.enqueue(7);

	queue.dequeue();

	cout << "\n\nEnd of Program\n\n" << endl;

	return 0;
}
