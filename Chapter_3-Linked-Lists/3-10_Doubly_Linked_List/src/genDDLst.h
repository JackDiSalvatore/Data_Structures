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
private:
    T info;
    DDLNode *next, *prev;
};


template<class T>
class DoublyLinkedList
{
public:
    DoublyLinkedList()
    {
        head = tail = 0;
    }
    void addToDLLTail(const T&);
    T deleteFromDLLTail();
    // Add more Doubly Linked List member functions here!
protected:
    DDLNode<T> *head, *tail;
};


/* Doubly Linked List Member Functions */
template<class T>
void DoublyLinkedList<T>::addToDLLTail(const T& el)
{
	if (tail !=0 )
	{
		tail = new DDLNode<T>(el, 0, tail);
		tail->prev->next = tail;
	}
	else
		head = tail = new DDLNode<T>(el);
}


template<class T>
T DoublyLinkedList<T>::deleteFromDLLTail()
{
	T el = tail->info;

	if (head == tail) // If only one node in the list
	{
		delete head;
		head = tail = 0;
	}
	else	// If more than one node in the list
	{
		tail = tail->prev;
		delete tail->next;
		tail->next = 0;
	}

	return el;
}
#endif
