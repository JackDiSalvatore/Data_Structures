/*
 * genBST.h
 *
 *  Created on: May 21, 2017
 *      Author: jack
 */

#include <queue>
#include <stack>

using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template<class T>
class Stack : public stack<T>
{
	// See Figure 4.21
};

template<class T>
class Queue : public queue<T>
{
public:
	T dequeue() {
		T tmp = queue<T>::front();
		queue<T>::pop();
		return tmp;
	}
	void enqueue(const T& el) {
		push(el);
	}
};

template<class T>
class BSTNode
{
public:
	BSTNode() {
		left = right = 0;
	}
	BSTNode(const T& e, BSTNode<T> *l = 0, BSTNode<T> *r = 0) {
		el = e; left = l; right = r;
	}

	T el;
	BSTNode<T> *left, *right;
};

template<class T>
class BST
{
public:
	BST() {
		root = 0;
	}
	~BST() {
		clear();
	}
	void clear() {
		clear(root); root = 0;
	}
	bool isEmpty() const {
		return root == 0;
	}
	void preorder() {				// Fig 6.11
		preorder(root);
	}
	void inorder() {				// Fig 6.11
		inorder(root);
	}
	void postorder() {				// Fig 6.11
		postorder(root);
	}
	T* search(const T& el) const {	// Fig 6.9
		return search(root, el);
	}

	void breadthFirst();			// Fig 6.10
	void iterativePreorder();		// Fig 6.15
	void iterativeInorder();		// Fig 6.17
	void iterativePostorder();		// Fig 6.16
	void MorrisInorder();			// Fig 6.20
	void insert(const T&);				// Fig 6.23
	void deleteByMerging(BSTNode<T>*&);		// Fig 6.29
	void findAndDeleteByMerging(const T&);		// Fig 6.29
	void deleteByCopying(BSTNode<T>*&);		// Fig 6.32
	void balance(T*,int,int);		// Fig 6.7

protected:
	BSTNode<T>* root;

	void clear(BSTNode<T>*);
	T* search(BSTNode<T>*, const T&) const; // Fig 6.9
	void preorder(BSTNode<T>*);				// Fig 6.11
	void inorder(BSTNode<T>*);				// Fig 6.11
	void postorder(BSTNode<T>*); 			// Fig 6.11
	virtual void visit(BSTNode<T>* p) {
	cout << p->el << ' ';
	}
};

#endif /* BINARY_SEARCH_TREE */
