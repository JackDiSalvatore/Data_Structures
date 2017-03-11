/*
 * genStack.h
 *
 *  Created on: Mar 11, 2017
 *      Author: jack
 */

#ifndef STACK_H
#define STACK_H


#include <vector>

using namespace std;

template<class T, int capacity = 30>
class Stack
{
public:
	Stack()
	{
		pool.reserve(capacity);
	}


	void clear()
	{
		pool.clear();
	}

	bool isEmpty()
	{
		return pool.empty();
	}

	T& topEl()
	{
		return pool.back();
	}

	T pop()
	{
		T el = pool.back();
		pool.pop_back();

		return el;
	}

	void push(const T& el)
	{
		pool.push_back(el);
	}

private:
	vector<T> pool;
};


#endif /* STACK_H_ */
