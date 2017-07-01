/*
 * intSLLst.h
 *
 *  Created on: Dec 11, 2016
 *      Author: jack
 */

#ifndef INTSLLST_H_
#define INTSLLST_H_


class IntSLLNode
{
public:
	int info;
	IntSLLNode *next;

	IntSLLNode(int el = 0, IntSLLNode *ptr = 0)
	{
		info = el;
		next = ptr;
	}

};


class IntSLList
{
public:
	IntSLList()
	{
		head = tail = 0;
	}
	~IntSLList();

	int isEmpty()
	{
		return head == 0;
	}
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead();	// deletes the head and returns its info
	int deleteFromTail();	// deletes the tail and returns its info
	void deleteNode(int);
	bool isInList(int) const;
	void print();

private:
	IntSLLNode *head, *tail;
};


#endif /* INTSLLST_H_ */
