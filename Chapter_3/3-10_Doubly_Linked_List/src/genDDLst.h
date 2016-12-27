/*
 * genDDLst.h
 *
 *  Created on: Dec 27, 2016
 *      Author: jack
 */

#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST


template<class T>
class DDLNode
{
public:
	DDLNode()
	{
		next = prev = 0;
	}
	DDLNode(const T& el, DDLNode *n = 0, DDLNode *p = 0)
	{
		info = el; next = n; prev = p;
	}
	T info;
	DDLNode *next, *prev;
};



#endif /* DOUBLY_LINKED_LIST */
