/*
 * genListStack.h
 *
 *  Created on: Mar 11, 2017
 *      Author: jack
 */

#ifndef GENLISTSTACK_H_
#define GENLISTSTACK_H_


#include <list>

template<class T>
class LLStack
{
public:
	LLStack()
	{
	}


	void clear()
	{
		lst.clear();
	}

	bool isEmpty()
	{
		return lst.empty();
	}

	T& topEl()
	{
		return lst.back();
	}

	T pop()
	{
		T el = lst.back();
		lst.pop_back();

		return el;
	}

	void push(const T& el)
	{
		lst.push_back(el);
	}

private:
	list<T> lst;
};


#endif /* GENLISTSTACK_H_ */
