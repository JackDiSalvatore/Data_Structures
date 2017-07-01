/*
 * genQueue.h
 *
 *  Created on: Mar 25, 2017
 *      Author: jack
 */

#ifndef GENQUEUE_H_
#define GENQUEUE_H_

using namespace std;

#include <list>

template<class T>
class Queue{
public:
	Queue() { };

	void clear() {
		lst.clear();
	}
	bool isEmpty() const {
		return lst.empty();
	}
	T& front() {
		return lst.front();
	}
	T dequeue() {
		T el = lst.front();
		lst.pop_front();
		return el;
	}
	void enqueue(const T& el) {
		lst.push_back(el);
	}
	void print() {
		typename list<T>::iterator i;

		for (i = lst.begin(); i != lst.end(); ++i)
			cout << *i << " ";
		cout << endl;
	}
private:
	list<T> lst;
};

#endif /* GENQUEUE_H_ */
