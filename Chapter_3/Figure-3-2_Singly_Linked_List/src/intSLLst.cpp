/*
 * intSLLst.cpp
 *
 *  Created on: Dec 11, 2016
 *      Author: jack
 *
 *      head		node	node	tail
 *      	info						info
 *      	next						next  -> 0
 */
#include <iostream>
#include "intSLLst.h"


IntSLList::~IntSLList()
{
	for (IntSLLNode *p; !isEmpty(); )
	{
		p = head->next;		// put head at end of list
		delete head;
		head = p;
	}
}

/* Figure 3.4 pg 82-83 */
void IntSLList::addToHead(int el)
{
	head = new IntSLLNode(el,head);		// new node in list

	if (tail == 0)
		tail = head;
}


void IntSLList::addToTail(int el)
{
	if (tail != 0) {	// if list not empty
		tail->next = new IntSLLNode(el);	// place new node at the end of list
		tail = tail->next;					// make the new node the end of the list
	}
	else head = tail = new IntSLLNode(el);	// list was empty, now there is only one element
}


int IntSLList::deleteFromHead()
{
	int el = head->info;
	IntSLLNode *tmp = head;

	if(head == tail)	// if only one node in the list
		head = tail = 0;	// delete it
	else head = head->next;	// make the next node in the list the new head

	delete tmp;
	return el;
}


int IntSLList::deleteFromTail()
{
	int el = tail->info;

	if (head == tail)	// if only one node in list
	{
		delete head;
		head = tail = 0;	// erase list
	}
	else
	{						// if more than one node in the list,
		IntSLLNode *tmp;	// find the predecessor of tail
		for (tmp = head; tmp->next != tail; tmp = tmp->next)	// go through the list untill you reach the tail
			delete tail;

		tail = tmp;			// the predecessor of tail becomes tail
		tail->next = 0;
	}

	return el;
}


void IntSLList::deleteNode(int el)
{
	if (head != 0 )				// if list is not empty
		if (head == tail && el == head->info)	// if only one node in the list
		{
			delete head;
			head = tail = 0;
		}
		else if (el == head->info)	// if more than one node in the list
		{
			IntSLLNode *tmp = head;
			head = head->next;		// make next node the head
			delete tmp;				// delete old head
		}
		else	// if more than one node in the list
		{
			IntSLLNode *pred, *tmp;
			for (pred = head, tmp = head->next;		// and a non-head node
				 tmp != 0 && !(tmp->info == el);	// is deleted
				 pred = pred->next, tmp = tmp->next);
			if( tmp != 0)
			{
				pred->next = tmp->next;
				if(tmp == tail)				// delete the tail and make the last
					tail = pred;			// preceding node the new tail

				delete tmp;
			}
		}
}


bool IntSLList::isInList(int el) const
{
	IntSLLNode *tmp;
	for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
	return tmp != 0;
}

void IntSLList::print()
{
	IntSLLNode *tmp;
	//for(tmp = head; tmp->next == tail; tmp = tmp->next)
	tmp = head;
	do
	{
		std::cout << tmp->info << std::endl;

		tmp = tmp->next;
	}
	while(tmp->next != tail);
}
