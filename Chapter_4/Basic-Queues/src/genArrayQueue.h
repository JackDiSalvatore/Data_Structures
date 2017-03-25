/*
 * genArrayQueue.h
 *
 *  Created on: Mar 25, 2017
 *      Author: jack
 */

#ifndef GENARRAYQUEUE_H_
#define GENARRAYQUEUE_H_

using namespace std;

template<class T, int size = 100>
class ArrayQueue {
public:
	ArrayQueue() {
		first = last = -1;
	}

	void enqueue(T);
	T dequeue();
	bool isFull() {
		return ((first == 0 && last == size-1) || first == last + 1);
	}
	void print() {
		cout << "First: ";
		for (int idx = first; idx < last; idx++) {
			cout << "\t" << storage[idx] << endl;
		}
		cout << "Last:\t" << storage[last] << endl;
	}
private:
	int first, last;
	T storage[size];
};


template<class T, int size>
void ArrayQueue<T,size>::enqueue(T el) {
	if (!isFull())
		if (last == size -1 || last == -1) {	// last is at end or not initialized yet
			storage[0] = el;	// store in element zero
			last = 0;
			if (first == -1)	// initialize first
				first = 0;
		}
		else storage[++last] = el;
	else cout << "Full queue.\n";
}

template<class T, int size>
T ArrayQueue<T,size>::dequeue() {
	T tmp = storage[first];

	if (first == last)
		last = first - 1;
	else if (first == size - 1)	// first is at the end of queue
		first = 0;
	else first++;

	return tmp;
}

#endif /* GENARRAYQUEUE_H_ */
